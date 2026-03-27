// SPDX-License-Identifier: GPL-2.0
#define _GNU_SOURCE

#include <arpa/inet.h>
#include <errno.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <netpacket/packet.h>
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
#define SEND_INTERVAL_US 10000
#define ROUND_DWELL_US 200000
#define PACKET_TIMEOUT_MS 1500
#define SOCKET_FILTER_TRUNC_LEN 64
#define SOCKET_FILTER_FULL_LEN_MIN 200
#define SOCKET_FILTER_SINK_PORT 41011
#define SOCKET_FILTER_PAYLOAD_LEN 256

static const char *g_progs_dir = "tests/unittest/build/progs";
static int g_pass;
static int g_fail;

struct worker_ctx {
	volatile bool stop;
	int port;
};

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", name); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s\n", name, reason); \
	g_fail++; \
} while (0)

static int open_loopback_packet_socket(void)
{
	struct sockaddr_ll sll = {};
	int ifindex;
	int fd;

	ifindex = if_nametoindex("lo");
	if (!ifindex) {
		errno = ENODEV;
		return -1;
	}

	fd = socket(AF_PACKET, SOCK_DGRAM | SOCK_CLOEXEC, htons(ETH_P_IP));
	if (fd < 0)
		return -1;

	sll.sll_family = AF_PACKET;
	sll.sll_protocol = htons(ETH_P_IP);
	sll.sll_ifindex = ifindex;
	if (bind(fd, (struct sockaddr *)&sll, sizeof(sll)) < 0) {
		close(fd);
		return -1;
	}

	return fd;
}

static int open_udp_sink(int port)
{
	struct sockaddr_in addr = {};
	int fd;

	fd = socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, 0);
	if (fd < 0)
		return -1;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		close(fd);
		return -1;
	}

	return fd;
}

static void drain_socket(int fd)
{
	char buf[2048];

	while (recv(fd, buf, sizeof(buf), MSG_DONTWAIT) > 0)
		;
}

static int wait_for_packet_shape(int fd, bool expect_trunc,
				 char *reason, size_t reason_sz)
{
	struct pollfd pfd = {
		.fd = fd,
		.events = POLLIN,
	};
	char buf[2048];
	int elapsed_ms = 0;

	while (elapsed_ms < PACKET_TIMEOUT_MS) {
		int ret;
		int len;

		ret = poll(&pfd, 1, 100);
		if (ret < 0) {
			snprintf(reason, reason_sz, "poll failed: %s",
				 strerror(errno));
			return -1;
		}
		if (ret == 0) {
			elapsed_ms += 100;
			continue;
		}

		len = recv(fd, buf, sizeof(buf), 0);
		if (len < 0) {
			if (errno == EINTR)
				continue;
			snprintf(reason, reason_sz, "recv failed: %s",
				 strerror(errno));
			return -1;
		}

		if (!expect_trunc && len >= SOCKET_FILTER_FULL_LEN_MIN)
			return 0;
		if (expect_trunc && len == SOCKET_FILTER_TRUNC_LEN)
			return 0;
	}

	snprintf(reason, reason_sz, "timed out waiting for %s packet shape",
		 expect_trunc ? "truncated" : "full");
	errno = ETIMEDOUT;
	return -1;
}

static void *socket_filter_worker(void *arg)
{
	struct worker_ctx *ctx = arg;
	struct sockaddr_in addr = {};
	char payload[SOCKET_FILTER_PAYLOAD_LEN];
	uint64_t seq = 0;
	int fd;

	fd = socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, 0);
	if (fd < 0)
		return NULL;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(ctx->port);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	while (!ctx->stop) {
		memset(payload, 0, sizeof(payload));
		memcpy(payload, &seq, sizeof(seq));
		sendto(fd, payload, sizeof(payload), 0,
		       (struct sockaddr *)&addr, sizeof(addr));
		seq++;
		usleep(SEND_INTERVAL_US);
	}

	close(fd);
	return NULL;
}

static int test_rejit_hotswap_socket_filter(void)
{
	const char *name = "rejit_hotswap_socket_filter";
	char obj_path[512];
	char log_buf[65536];
	char reason[256];
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	struct bpf_insn *orig_insns = NULL;
	struct bpf_insn *patched_insns = NULL;
	struct worker_ctx worker = {
		.port = SOCKET_FILTER_SINK_PORT,
	};
	pthread_t worker_thread;
	bool worker_started = false;
	int capture_fd = -1;
	int sink_fd = -1;
	int prog_fd;
	int orig_cnt;
	int i;
	int ret = 1;

	snprintf(obj_path, sizeof(obj_path), "%s/test_hotswap_socket_filter.bpf.o",
		 g_progs_dir);
	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_FAIL(name, "cannot open test_hotswap_socket_filter.bpf.o");
		obj = NULL;
		goto out;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_FAIL(name, "failed to load BPF object");
		goto out;
	}

	prog = bpf_object__find_program_by_name(obj,
						"rejit_hotswap_socket_filter");
	if (!prog) {
		TEST_FAIL(name, "program rejit_hotswap_socket_filter not found");
		goto out;
	}

	prog_fd = bpf_program__fd(prog);
	if (prog_fd < 0) {
		TEST_FAIL(name, "invalid program fd");
		goto out;
	}

	capture_fd = open_loopback_packet_socket();
	if (capture_fd < 0) {
		TEST_FAIL(name, "failed to open AF_PACKET socket on loopback");
		goto out;
	}

	sink_fd = open_udp_sink(SOCKET_FILTER_SINK_PORT);
	if (sink_fd < 0) {
		TEST_FAIL(name, "failed to open UDP sink socket");
		goto out;
	}

	if (setsockopt(capture_fd, SOL_SOCKET, SO_ATTACH_BPF,
		       &prog_fd, sizeof(prog_fd)) < 0) {
		TEST_FAIL(name, "SO_ATTACH_BPF failed");
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

	if (pthread_create(&worker_thread, NULL, socket_filter_worker, &worker) != 0) {
		TEST_FAIL(name, "pthread_create failed");
		goto out;
	}
	worker_started = true;

	drain_socket(capture_fd);
	if (wait_for_packet_shape(capture_fd, false, reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	for (i = 0; i < HOTSWAP_ROUNDS; i++) {
		bool expect_trunc = (i % 2) == 0;

		memcpy(patched_insns, orig_insns, orig_cnt * sizeof(*patched_insns));
		if (hotswap_patch_return_imm(patched_insns, orig_cnt,
					     expect_trunc ? SOCKET_FILTER_TRUNC_LEN : 0xffff) < 0) {
			TEST_FAIL(name, "failed to patch socket filter return value");
			goto out;
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (hotswap_rejit_prog(prog_fd, patched_insns, orig_cnt,
				       log_buf, sizeof(log_buf)) < 0) {
			fprintf(stderr, "    verifier log:\n%s\n", log_buf);
			TEST_FAIL(name, "BPF_PROG_REJIT failed");
			goto out;
		}

		drain_socket(capture_fd);
		if (wait_for_packet_shape(capture_fd, expect_trunc,
					  reason, sizeof(reason)) < 0) {
			TEST_FAIL(name, reason);
			goto out;
		}

		usleep(ROUND_DWELL_US);
	}

	TEST_PASS(name);
	ret = 0;

out:
	worker.stop = true;
	if (worker_started)
		pthread_join(worker_thread, NULL);
	free(patched_insns);
	free(orig_insns);
	if (sink_fd >= 0)
		close(sink_fd);
	if (capture_fd >= 0)
		close(capture_fd);
	if (obj)
		bpf_object__close(obj);
	return ret;
}

int main(int argc, char **argv)
{
	if (argc > 1)
		g_progs_dir = argv[1];

	if (test_rejit_hotswap_socket_filter())
		return 1;

	printf("\nSummary: pass=%d fail=%d\n", g_pass, g_fail);
	return g_fail ? 1 : 0;
}
