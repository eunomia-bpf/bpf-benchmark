// SPDX-License-Identifier: GPL-2.0
#define _GNU_SOURCE

#include <arpa/inet.h>
#include <errno.h>
#include <net/if.h>
#include <linux/bpf.h>
#include <linux/if_ether.h>
#include <linux/unistd.h>
#include <netpacket/packet.h>
#include <pthread.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/syscall.h>
#include <unistd.h>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#include "rejit_hotswap_common.h"

#define HOTSWAP_ROUNDS 10
#define SAMPLE_INTERVAL_US 50000
#define ROUND_DWELL_US 500000
#define RATIO_TIMEOUT_MS 2500
#define MIN_WINDOW_EVENTS 64
#define XDP_FLAGS_SKB_MODE (1U << 1)

static const char *g_progs_dir = "tests/unittest/build/progs";
static int g_pass;
static int g_fail;

struct hotswap_stats {
	__u64 total;
	__u64 events;
};

struct worker_ctx {
	volatile bool stop;
	volatile int err;
	int tx_ifindex;
	unsigned char src_mac[ETH_ALEN];
	unsigned char dst_mac[ETH_ALEN];
};

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", name); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s\n", name, reason); \
	g_fail++; \
} while (0)

static int read_stats(int map_fd, struct hotswap_stats *stats)
{
	__u32 key = 0;

	return bpf_map_lookup_elem(map_fd, &key, stats);
}

static bool ratio_matches(__u64 total_delta, __u64 event_delta, __u64 expected)
{
	__u64 target;
	__u64 diff;
	__u64 tolerance;

	if (!event_delta)
		return false;

	target = event_delta * expected;
	diff = total_delta > target ? total_delta - target : target - total_delta;
	tolerance = event_delta / 20 + 2;
	return diff <= tolerance;
}

static int wait_for_expected_delta(int map_fd, __u64 expected,
				   char *reason, size_t reason_sz)
{
	struct hotswap_stats prev;
	struct hotswap_stats cur;
	__u64 total_delta = 0;
	__u64 event_delta = 0;
	int elapsed_ms = 0;

	if (read_stats(map_fd, &prev) < 0) {
		snprintf(reason, reason_sz, "initial map lookup failed: %s",
			 strerror(errno));
		return -1;
	}

	while (elapsed_ms < RATIO_TIMEOUT_MS) {
		usleep(SAMPLE_INTERVAL_US);
		if (read_stats(map_fd, &cur) < 0) {
			snprintf(reason, reason_sz, "map lookup failed: %s",
				 strerror(errno));
			return -1;
		}

		total_delta = cur.total - prev.total;
		event_delta = cur.events - prev.events;
		if (event_delta >= MIN_WINDOW_EVENTS) {
			if (ratio_matches(total_delta, event_delta, expected))
				return 0;
			prev = cur;
		}

		elapsed_ms += SAMPLE_INTERVAL_US / 1000;
	}

	snprintf(reason, reason_sz,
		 "timed out waiting for delta=%llu (total_delta=%llu event_delta=%llu)",
		 (unsigned long long)expected,
		 (unsigned long long)total_delta,
		 (unsigned long long)event_delta);
	errno = ETIMEDOUT;
	return -1;
}

static int run_cmd(char *reason, size_t reason_sz, const char *fmt, ...)
{
	char cmd[512];
	va_list ap;
	int ret;

	va_start(ap, fmt);
	vsnprintf(cmd, sizeof(cmd), fmt, ap);
	va_end(ap);

	ret = system(cmd);
	if (ret != 0) {
		snprintf(reason, reason_sz, "command failed: %.200s", cmd);
		errno = EIO;
		return -1;
	}

	return 0;
}

static int get_if_hwaddr(const char *ifname, unsigned char mac[ETH_ALEN])
{
	struct ifreq ifr = {};
	int fd;

	fd = socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, 0);
	if (fd < 0)
		return -1;

	snprintf(ifr.ifr_name, sizeof(ifr.ifr_name), "%s", ifname);
	if (ioctl(fd, SIOCGIFHWADDR, &ifr) < 0) {
		close(fd);
		return -1;
	}

	memcpy(mac, ifr.ifr_hwaddr.sa_data, ETH_ALEN);
	close(fd);
	return 0;
}

static void *xdp_worker(void *arg)
{
	struct worker_ctx *ctx = arg;
	struct sockaddr_ll sll = {};
	unsigned char frame[64] = {};
	struct ethhdr *eth = (struct ethhdr *)frame;
	int sock;

	sock = socket(AF_PACKET, SOCK_RAW | SOCK_CLOEXEC, htons(ETH_P_IP));
	if (sock < 0) {
		ctx->err = errno ? errno : EIO;
		return NULL;
	}

	memcpy(eth->h_dest, ctx->dst_mac, ETH_ALEN);
	memcpy(eth->h_source, ctx->src_mac, ETH_ALEN);
	eth->h_proto = htons(ETH_P_IP);
	memset(frame + sizeof(*eth), 0xab, sizeof(frame) - sizeof(*eth));

	sll.sll_family = AF_PACKET;
	sll.sll_protocol = htons(ETH_P_IP);
	sll.sll_ifindex = ctx->tx_ifindex;
	sll.sll_halen = ETH_ALEN;
	memcpy(sll.sll_addr, ctx->dst_mac, ETH_ALEN);

	while (!ctx->stop) {
		if (sendto(sock, frame, sizeof(frame), 0,
			   (struct sockaddr *)&sll, sizeof(sll)) < 0) {
			if (errno == EINTR || errno == EAGAIN || errno == ENOBUFS)
				continue;
			ctx->err = errno ? errno : EIO;
			break;
		}
	}

	close(sock);
	return NULL;
}

static int test_rejit_hotswap_xdp(void)
{
	const char *name = "rejit_hotswap_xdp";
	char obj_path[512];
	char reason[256];
	char log_buf[65536];
	char if_ingress[IFNAMSIZ];
	char if_egress[IFNAMSIZ];
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	struct bpf_map *map;
	struct bpf_insn *orig_insns = NULL;
	struct bpf_insn *patched_insns = NULL;
	struct worker_ctx worker = {};
	pthread_t worker_thread;
	bool worker_started = false;
	bool xdp_attached = false;
	int fd_array[1];
	int ifindex = 0;
	int map_fd;
	int prog_fd;
	int orig_cnt;
	int i;
	int ret = 1;

	snprintf(obj_path, sizeof(obj_path), "%s/test_hotswap_xdp.bpf.o",
		 g_progs_dir);
	snprintf(if_ingress, sizeof(if_ingress), "rjx%05d0", getpid() % 100000);
	snprintf(if_egress, sizeof(if_egress), "rjx%05d1", getpid() % 100000);

	if (run_cmd(reason, sizeof(reason), "ip link add %s type veth peer name %s",
		    if_ingress, if_egress) < 0) {
		TEST_FAIL(name, reason);
		return 1;
	}

	if (run_cmd(reason, sizeof(reason), "ip link set dev %s up", if_ingress) < 0 ||
	    run_cmd(reason, sizeof(reason), "ip link set dev %s up", if_egress) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_FAIL(name, "cannot open test_hotswap_xdp.bpf.o");
		obj = NULL;
		goto out;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_FAIL(name, "failed to load BPF object");
		goto out;
	}

	prog = bpf_object__find_program_by_name(obj, "rejit_hotswap_xdp");
	if (!prog) {
		TEST_FAIL(name, "program rejit_hotswap_xdp not found");
		goto out;
	}

	map = bpf_object__find_map_by_name(obj, "stats_map");
	if (!map) {
		TEST_FAIL(name, "stats_map not found");
		goto out;
	}

	prog_fd = bpf_program__fd(prog);
	map_fd = bpf_map__fd(map);
	if (prog_fd < 0 || map_fd < 0) {
		TEST_FAIL(name, "invalid prog/map fd");
		goto out;
	}
	fd_array[0] = map_fd;

	ifindex = if_nametoindex(if_ingress);
	if (!ifindex) {
		TEST_FAIL(name, "if_nametoindex failed");
		goto out;
	}

	if (bpf_xdp_attach(ifindex, prog_fd, XDP_FLAGS_SKB_MODE, NULL) < 0) {
		TEST_FAIL(name, "bpf_xdp_attach failed");
		goto out;
	}
	xdp_attached = true;

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

	worker.tx_ifindex = if_nametoindex(if_egress);
	if (!worker.tx_ifindex) {
		TEST_FAIL(name, "if_nametoindex failed for worker");
		goto out;
	}

	if (get_if_hwaddr(if_egress, worker.src_mac) < 0 ||
	    get_if_hwaddr(if_ingress, worker.dst_mac) < 0) {
		TEST_FAIL(name, "failed to query veth MAC address");
		goto out;
	}

	if (pthread_create(&worker_thread, NULL, xdp_worker, &worker) != 0) {
		TEST_FAIL(name, "pthread_create failed");
		goto out;
	}
	worker_started = true;

	if (wait_for_expected_delta(map_fd, 1, reason, sizeof(reason)) < 0) {
		if (worker.err)
			snprintf(reason, sizeof(reason),
				 "packet worker failed: %s", strerror(worker.err));
		TEST_FAIL(name, reason);
		goto out;
	}

	for (i = 0; i < HOTSWAP_ROUNDS; i++) {
		int expected = (i % 2 == 0) ? 2 : 1;

		memcpy(patched_insns, orig_insns, orig_cnt * sizeof(*patched_insns));
		if (hotswap_patch_atomic_add_imm(patched_insns, orig_cnt,
						 offsetof(struct hotswap_stats, total),
						 expected) < 0) {
			TEST_FAIL(name, "failed to patch total delta immediate");
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

		if (wait_for_expected_delta(map_fd, expected,
					    reason, sizeof(reason)) < 0) {
			if (worker.err)
				snprintf(reason, sizeof(reason),
					 "packet worker failed: %s",
					 strerror(worker.err));
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
	if (xdp_attached)
		bpf_xdp_detach(ifindex, XDP_FLAGS_SKB_MODE, NULL);
	if (obj)
		bpf_object__close(obj);
	if (if_ingress[0]) {
		int ignored;

		snprintf(reason, sizeof(reason), "ip link del %s 2>/dev/null",
			 if_ingress);
		ignored = system(reason);
		(void)ignored;
	}
	return ret;
}

int main(int argc, char **argv)
{
	if (argc > 1)
		g_progs_dir = argv[1];

	if (test_rejit_hotswap_xdp())
		return 1;

	printf("\nSummary: pass=%d fail=%d\n", g_pass, g_fail);
	return g_fail ? 1 : 0;
}
