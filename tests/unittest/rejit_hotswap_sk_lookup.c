// SPDX-License-Identifier: GPL-2.0
#define _GNU_SOURCE

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <poll.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#include "rejit_hotswap_common.h"

#define HOTSWAP_ROUNDS 10
#define HOTSWAP_SK_LOOKUP_PORT 41021
#define CLIENT_INTERVAL_US 10000
#define ROUND_DWELL_US 200000
#define ACCEPT_TIMEOUT_MS 1200

static const char *g_progs_dir = "tests/unittest/build/progs";
static int g_pass;
static int g_fail;

struct accept_ctx {
	volatile bool stop;
	int listen_fds[2];
	volatile unsigned long long accepted[2];
	volatile unsigned long long err;
};

struct client_ctx {
	volatile bool stop;
	int port;
	volatile unsigned long long ok;
	volatile unsigned long long err;
};

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", name); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s\n", name, reason); \
	g_fail++; \
} while (0)

static unsigned long long read_counter(volatile unsigned long long *value)
{
	return __atomic_load_n(value, __ATOMIC_RELAXED);
}

static void dump_prog_insns(const struct bpf_insn *insns, int insn_cnt)
{
	int i;

	for (i = 0; i < insn_cnt; i++) {
		fprintf(stderr,
			"    insn[%d]: code=0x%02x dst=%u src=%u off=%d imm=%d\n",
			i, insns[i].code, insns[i].dst_reg, insns[i].src_reg,
			insns[i].off, insns[i].imm);
	}
}

static int open_reuseport_listener(int port)
{
	struct sockaddr_in addr = {};
	int one = 1;
	int fd;

	fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
	if (fd < 0)
		return -1;

	if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one)) < 0 ||
	    setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, &one, sizeof(one)) < 0) {
		close(fd);
		return -1;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		close(fd);
		return -1;
	}
	if (listen(fd, 128) < 0) {
		close(fd);
		return -1;
	}

	return fd;
}

static int wait_for_accept(struct accept_ctx *accept_ctx, int expected_idx,
			   char *reason, size_t reason_sz)
{
	unsigned long long start_err = read_counter(&accept_ctx->err);
	unsigned long long start_accepts = read_counter(&accept_ctx->accepted[expected_idx]);
	int elapsed_ms = 0;

	while (elapsed_ms < ACCEPT_TIMEOUT_MS) {
		if (read_counter(&accept_ctx->err) > start_err) {
			snprintf(reason, reason_sz, "accept worker saw unexpected errors");
			errno = EIO;
			return -1;
		}
		if (read_counter(&accept_ctx->accepted[expected_idx]) > start_accepts)
			return 0;

		usleep(10000);
		elapsed_ms += 10;
	}

	snprintf(reason, reason_sz, "timed out waiting for server %d accept",
		 expected_idx);
	errno = ETIMEDOUT;
	return -1;
}

static void *accept_worker(void *arg)
{
	struct accept_ctx *ctx = arg;
	struct pollfd pfds[2];

	pfds[0].fd = ctx->listen_fds[0];
	pfds[0].events = POLLIN;
	pfds[1].fd = ctx->listen_fds[1];
	pfds[1].events = POLLIN;

	while (!ctx->stop) {
		int ret;
		int i;

		pfds[0].revents = 0;
		pfds[1].revents = 0;
		ret = poll(pfds, ARRAY_SIZE(pfds), 50);
		if (ret < 0) {
			if (errno == EINTR)
				continue;
			__atomic_fetch_add(&ctx->err, 1, __ATOMIC_RELAXED);
			continue;
		}
		if (ret == 0)
			continue;

		for (i = 0; i < (int)ARRAY_SIZE(pfds); i++) {
			if (!(pfds[i].revents & POLLIN))
				continue;

			while (1) {
				int accepted_fd;

				accepted_fd = accept4(ctx->listen_fds[i], NULL, NULL,
						      SOCK_NONBLOCK | SOCK_CLOEXEC);
				if (accepted_fd < 0) {
					if (errno != EAGAIN && errno != EWOULDBLOCK &&
					    errno != EINTR)
						__atomic_fetch_add(&ctx->err, 1,
								   __ATOMIC_RELAXED);
					break;
				}

				close(accepted_fd);
				__atomic_fetch_add(&ctx->accepted[i], 1, __ATOMIC_RELAXED);
			}
		}
	}

	return NULL;
}

static void *client_worker(void *arg)
{
	struct client_ctx *ctx = arg;
	struct sockaddr_in addr = {};

	addr.sin_family = AF_INET;
	addr.sin_port = htons(ctx->port);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	while (!ctx->stop) {
		int fd;

		fd = socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC, 0);
		if (fd < 0) {
			__atomic_fetch_add(&ctx->err, 1, __ATOMIC_RELAXED);
			usleep(CLIENT_INTERVAL_US);
			continue;
		}

		if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) == 0)
			__atomic_fetch_add(&ctx->ok, 1, __ATOMIC_RELAXED);
		else
			__atomic_fetch_add(&ctx->err, 1, __ATOMIC_RELAXED);

		close(fd);
		usleep(CLIENT_INTERVAL_US);
	}

	return NULL;
}

static int test_rejit_hotswap_sk_lookup(void)
{
	const char *name = "rejit_hotswap_sk_lookup";
	char obj_path[512];
	char log_buf[65536];
	char reason[256];
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	struct bpf_map *sock_map;
	struct bpf_link *link = NULL;
	struct bpf_insn *orig_insns = NULL;
	struct bpf_insn *patched_insns = NULL;
	struct accept_ctx accept_ctx = {};
	struct client_ctx client_ctx = {
		.port = HOTSWAP_SK_LOOKUP_PORT,
	};
	pthread_t accept_thread;
	pthread_t client_thread;
	bool accept_started = false;
	bool client_started = false;
	int fd_array[1];
	int netns_fd = -1;
	int prog_fd;
	int map_fd;
	int orig_cnt;
	int i;
	int ret = 1;

	accept_ctx.listen_fds[0] = -1;
	accept_ctx.listen_fds[1] = -1;

	accept_ctx.listen_fds[0] = open_reuseport_listener(HOTSWAP_SK_LOOKUP_PORT);
	accept_ctx.listen_fds[1] = open_reuseport_listener(HOTSWAP_SK_LOOKUP_PORT);
	if (accept_ctx.listen_fds[0] < 0 || accept_ctx.listen_fds[1] < 0) {
		TEST_FAIL(name, "failed to create reuseport listeners");
		goto out;
	}

	snprintf(obj_path, sizeof(obj_path), "%s/test_hotswap_sk_lookup.bpf.o",
		 g_progs_dir);
	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_FAIL(name, "cannot open test_hotswap_sk_lookup.bpf.o");
		obj = NULL;
		goto out;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_FAIL(name, "failed to load BPF object");
		goto out;
	}

	prog = bpf_object__find_program_by_name(obj, "rejit_hotswap_sk_lookup");
	if (!prog) {
		TEST_FAIL(name, "program rejit_hotswap_sk_lookup not found");
		goto out;
	}

	sock_map = bpf_object__find_map_by_name(obj, "sock_map");
	if (!sock_map) {
		TEST_FAIL(name, "sock_map not found");
		goto out;
	}

	prog_fd = bpf_program__fd(prog);
	map_fd = bpf_map__fd(sock_map);
	if (prog_fd < 0 || map_fd < 0) {
		TEST_FAIL(name, "invalid prog/map fd");
		goto out;
	}
	fd_array[0] = map_fd;

	for (i = 0; i < 2; i++) {
		__u32 key = i;
		__u64 value = (__u64)accept_ctx.listen_fds[i];

		if (bpf_map_update_elem(map_fd, &key, &value, BPF_NOEXIST) < 0) {
			TEST_FAIL(name, "failed to populate sock_map");
			goto out;
		}
	}

	netns_fd = open("/proc/self/ns/net", O_RDONLY | O_CLOEXEC);
	if (netns_fd < 0) {
		TEST_FAIL(name, "failed to open current netns");
		goto out;
	}

	link = bpf_program__attach_netns(prog, netns_fd);
	if (!link || libbpf_get_error(link)) {
		TEST_FAIL(name, "failed to attach sk_lookup program");
		link = NULL;
		goto out;
	}

	orig_cnt = hotswap_get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed");
		goto out;
	}

	patched_insns = calloc(orig_cnt, sizeof(*patched_insns));
	if (!patched_insns) {
		TEST_FAIL(name, "calloc patched_insns failed");
		goto out;
	}

	if (pthread_create(&accept_thread, NULL, accept_worker, &accept_ctx) != 0) {
		TEST_FAIL(name, "pthread_create accept_worker failed");
		goto out;
	}
	accept_started = true;

	if (pthread_create(&client_thread, NULL, client_worker, &client_ctx) != 0) {
		TEST_FAIL(name, "pthread_create client_worker failed");
		goto out;
	}
	client_started = true;

	if (wait_for_accept(&accept_ctx, 0, reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	for (i = 0; i < HOTSWAP_ROUNDS; i++) {
		int expected_idx = (i % 2) == 0 ? 1 : 0;

		memcpy(patched_insns, orig_insns, orig_cnt * sizeof(*patched_insns));
		if (hotswap_patch_stack_map_key(patched_insns, orig_cnt,
						expected_idx) < 0) {
			dump_prog_insns(patched_insns, orig_cnt);
			TEST_FAIL(name, "failed to patch sk_lookup redirect key");
			goto out;
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (hotswap_rejit_prog_fd_array(prog_fd, patched_insns, orig_cnt,
						fd_array, ARRAY_SIZE(fd_array),
						log_buf, sizeof(log_buf)) < 0) {
			fprintf(stderr, "    verifier log:\n%s\n", log_buf);
			TEST_FAIL(name, "BPF_PROG_REJIT failed");
			goto out;
		}

		if (wait_for_accept(&accept_ctx, expected_idx,
				    reason, sizeof(reason)) < 0) {
			TEST_FAIL(name, reason);
			goto out;
		}

		usleep(ROUND_DWELL_US);
	}

	TEST_PASS(name);
	ret = 0;

out:
	client_ctx.stop = true;
	accept_ctx.stop = true;
	if (client_started)
		pthread_join(client_thread, NULL);
	if (accept_started)
		pthread_join(accept_thread, NULL);
	free(patched_insns);
	free(orig_insns);
	if (link)
		bpf_link__destroy(link);
	if (netns_fd >= 0)
		close(netns_fd);
	if (obj)
		bpf_object__close(obj);
	for (i = 0; i < 2; i++) {
		if (accept_ctx.listen_fds[i] >= 0)
			close(accept_ctx.listen_fds[i]);
	}
	return ret;
}

int main(int argc, char **argv)
{
	if (argc > 1)
		g_progs_dir = argv[1];

	if (test_rejit_hotswap_sk_lookup())
		return 1;

	printf("\nSummary: pass=%d fail=%d\n", g_pass, g_fail);
	return g_fail ? 1 : 0;
}
