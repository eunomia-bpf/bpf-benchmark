// SPDX-License-Identifier: GPL-2.0
#define _GNU_SOURCE

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
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
#define HOTSWAP_CC_NAME "rjhtswp"
#define STRUCT_OPS_VALUE_A 1111
#define STRUCT_OPS_VALUE_B 2222
#define MAP_WAIT_TIMEOUT_MS 1200
#define WORKER_INTERVAL_US 10000
#define ROUND_DWELL_US 200000
#define ACCEPT_POLL_TIMEOUT_MS 50
#define MAP_SAMPLE_INTERVAL_US 25000
#define MIN_MAP_OK_EVENTS 16
#define MIN_STABLE_MAP_SAMPLES 8

static const char *g_progs_dir = "tests/unittest/build/progs";
static int g_pass;
static int g_fail;

struct accept_ctx {
	volatile bool stop;
	int listen_fd;
	volatile unsigned long long err;
};

struct worker_ctx {
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

static int read_value_map(int map_fd, __u64 *value)
{
	__u32 key = 0;

	return bpf_map_lookup_elem(map_fd, &key, value);
}

static int write_value_map(int map_fd, __u64 value)
{
	__u32 key = 0;

	return bpf_map_update_elem(map_fd, &key, &value, BPF_ANY);
}

static int wait_for_map_value(int map_fd, __u64 expected,
			      struct worker_ctx *worker,
			      struct accept_ctx *accept_ctx,
			      char *reason, size_t reason_sz)
{
	unsigned long long start_ok = read_counter(&worker->ok);
	unsigned long long start_err = read_counter(&worker->err);
	unsigned long long start_accept_err = read_counter(&accept_ctx->err);
	__u64 last_value = 0;
	int stable_samples = 0;
	int elapsed_ms = 0;

	while (elapsed_ms < MAP_WAIT_TIMEOUT_MS) {
		__u64 current;

		if (read_counter(&accept_ctx->err) > start_accept_err) {
			snprintf(reason, reason_sz,
				 "accept worker saw unexpected socket errors");
			errno = EIO;
			return -1;
		}

		if (read_counter(&worker->err) > start_err) {
			snprintf(reason, reason_sz,
				 "worker saw unexpected TCP connect/setsockopt failures");
			errno = EIO;
			return -1;
		}

		if (read_value_map(map_fd, &current) < 0) {
			snprintf(reason, reason_sz, "value_map lookup failed: %s",
				 strerror(errno));
			return -1;
		}

		last_value = current;
		if (current == expected)
			stable_samples++;
		else
			stable_samples = 0;

		if (stable_samples >= MIN_STABLE_MAP_SAMPLES &&
		    read_counter(&worker->ok) - start_ok >= MIN_MAP_OK_EVENTS)
			return 0;

		usleep(MAP_SAMPLE_INTERVAL_US);
		elapsed_ms += MAP_SAMPLE_INTERVAL_US / 1000;
	}

	snprintf(reason, reason_sz,
		 "timed out waiting for stable map value %llu (last=%llu)",
		 (unsigned long long)expected,
		 (unsigned long long)last_value);
	errno = ETIMEDOUT;
	return -1;
}

static int open_listener(int *port)
{
	struct sockaddr_in addr = {};
	socklen_t addr_len = sizeof(addr);
	int one = 1;
	int fd;

	fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
	if (fd < 0)
		return -1;

	if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one)) < 0) {
		close(fd);
		return -1;
	}

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	addr.sin_port = 0;
	if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		close(fd);
		return -1;
	}

	if (listen(fd, 128) < 0) {
		close(fd);
		return -1;
	}

	if (getsockname(fd, (struct sockaddr *)&addr, &addr_len) < 0) {
		close(fd);
		return -1;
	}

	*port = ntohs(addr.sin_port);
	return fd;
}

static void *accept_worker(void *arg)
{
	struct accept_ctx *ctx = arg;
	struct pollfd pfd = {
		.fd = ctx->listen_fd,
		.events = POLLIN,
	};

	while (!ctx->stop) {
		int ret;

		pfd.revents = 0;
		ret = poll(&pfd, 1, ACCEPT_POLL_TIMEOUT_MS);
		if (ret < 0) {
			if (errno == EINTR)
				continue;
			__atomic_fetch_add(&ctx->err, 1, __ATOMIC_RELAXED);
			continue;
		}
		if (ret == 0 || !(pfd.revents & POLLIN))
			continue;

		while (1) {
			int accepted_fd;

			accepted_fd = accept4(ctx->listen_fd, NULL, NULL,
					      SOCK_NONBLOCK | SOCK_CLOEXEC);
			if (accepted_fd < 0) {
				if (errno != EAGAIN && errno != EWOULDBLOCK &&
				    errno != EINTR)
					__atomic_fetch_add(&ctx->err, 1,
							   __ATOMIC_RELAXED);
				break;
			}

			close(accepted_fd);
		}
	}

	return NULL;
}

static void *struct_ops_worker(void *arg)
{
	struct worker_ctx *ctx = arg;
	struct sockaddr_in addr = {};

	addr.sin_family = AF_INET;
	addr.sin_port = htons(ctx->port);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	while (!ctx->stop) {
		int fd;

		fd = socket(AF_INET, SOCK_STREAM | SOCK_CLOEXEC, 0);
		if (fd < 0) {
			__atomic_fetch_add(&ctx->err, 1, __ATOMIC_RELAXED);
			usleep(WORKER_INTERVAL_US);
			continue;
		}

		if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
			__atomic_fetch_add(&ctx->err, 1, __ATOMIC_RELAXED);
			close(fd);
			usleep(WORKER_INTERVAL_US);
			continue;
		}

		if (setsockopt(fd, IPPROTO_TCP, TCP_CONGESTION,
			       HOTSWAP_CC_NAME, strlen(HOTSWAP_CC_NAME)) == 0)
			__atomic_fetch_add(&ctx->ok, 1, __ATOMIC_RELAXED);
		else
			__atomic_fetch_add(&ctx->err, 1, __ATOMIC_RELAXED);

		close(fd);
		usleep(WORKER_INTERVAL_US);
	}

	return NULL;
}

static int test_rejit_hotswap_struct_ops(void)
{
	const char *name = "rejit_hotswap_struct_ops";
	char obj_path[512];
	char log_buf[65536];
	char reason[256];
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	struct bpf_map *value_map;
	struct bpf_map *st_ops_map;
	struct bpf_link *link = NULL;
	struct bpf_insn *orig_insns = NULL;
	struct bpf_insn *patched_insns = NULL;
	struct accept_ctx accept_ctx = {
		.listen_fd = -1,
	};
	struct worker_ctx worker = {};
	pthread_t accept_thread;
	pthread_t worker_thread;
	bool accept_started = false;
	bool worker_started = false;
	int fd_array[1];
	int map_fd;
	int prog_fd;
	int orig_cnt;
	int i;
	int ret = 1;

	snprintf(obj_path, sizeof(obj_path), "%s/test_hotswap_struct_ops.bpf.o",
		 g_progs_dir);
	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_FAIL(name, "cannot open test_hotswap_struct_ops.bpf.o");
		obj = NULL;
		goto out;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_FAIL(name, "failed to load BPF object");
		goto out;
	}

	prog = bpf_object__find_program_by_name(obj,
						"rejit_hotswap_struct_ops_init");
	if (!prog) {
		TEST_FAIL(name, "init callback program not found");
		goto out;
	}

	value_map = bpf_object__find_map_by_name(obj, "value_map");
	if (!value_map) {
		TEST_FAIL(name, "value_map not found");
		goto out;
	}

	st_ops_map = bpf_object__find_map_by_name(obj, "rejit_hotswap_ca");
	if (!st_ops_map) {
		TEST_FAIL(name, "struct_ops map not found");
		goto out;
	}

	prog_fd = bpf_program__fd(prog);
	map_fd = bpf_map__fd(value_map);
	if (prog_fd < 0 || map_fd < 0) {
		TEST_FAIL(name, "invalid prog/map fd");
		goto out;
	}
	fd_array[0] = map_fd;

	link = bpf_map__attach_struct_ops(st_ops_map);
	if (!link || libbpf_get_error(link)) {
		TEST_FAIL(name, "attach_struct_ops failed");
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

	accept_ctx.listen_fd = open_listener(&worker.port);
	if (accept_ctx.listen_fd < 0) {
		TEST_FAIL(name, "failed to create loopback listener");
		goto out;
	}

	if (pthread_create(&accept_thread, NULL, accept_worker, &accept_ctx) != 0) {
		TEST_FAIL(name, "pthread_create accept failed");
		goto out;
	}
	accept_started = true;

	if (pthread_create(&worker_thread, NULL, struct_ops_worker, &worker) != 0) {
		TEST_FAIL(name, "pthread_create failed");
		goto out;
	}
	worker_started = true;

	if (write_value_map(map_fd, 0) < 0) {
		TEST_FAIL(name, "failed to reset value_map");
		goto out;
	}

	if (wait_for_map_value(map_fd, STRUCT_OPS_VALUE_A,
			       &worker, &accept_ctx,
			       reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	for (i = 0; i < HOTSWAP_ROUNDS; i++) {
		__u64 expected = (i % 2) == 0 ? STRUCT_OPS_VALUE_B : STRUCT_OPS_VALUE_A;

		memcpy(patched_insns, orig_insns, orig_cnt * sizeof(*patched_insns));
		if (hotswap_patch_map_value_store_imm(patched_insns, orig_cnt,
						      (__s32)expected) < 0) {
			TEST_FAIL(name, "failed to patch struct_ops map store immediate");
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

		if (write_value_map(map_fd, 0) < 0) {
			TEST_FAIL(name, "failed to reset value_map after REJIT");
			goto out;
		}

		if (wait_for_map_value(map_fd, expected,
				       &worker, &accept_ctx,
				       reason, sizeof(reason)) < 0) {
			TEST_FAIL(name, reason);
			goto out;
		}

		usleep(ROUND_DWELL_US);
	}

	TEST_PASS(name);
	ret = 0;

out:
	accept_ctx.stop = true;
	worker.stop = true;
	if (worker_started)
		pthread_join(worker_thread, NULL);
	if (accept_started)
		pthread_join(accept_thread, NULL);
	if (accept_ctx.listen_fd >= 0)
		close(accept_ctx.listen_fd);
	free(patched_insns);
	free(orig_insns);
	if (link)
		bpf_link__destroy(link);
	if (obj)
		bpf_object__close(obj);
	return ret;
}

int main(int argc, char **argv)
{
	if (argc > 1)
		g_progs_dir = argv[1];

	if (test_rejit_hotswap_struct_ops())
		return 1;

	printf("\nSummary: pass=%d fail=%d\n", g_pass, g_fail);
	return g_fail ? 1 : 0;
}
