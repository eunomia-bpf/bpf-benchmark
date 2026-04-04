// SPDX-License-Identifier: GPL-2.0
#define _GNU_SOURCE

#include <arpa/inet.h>
#include <errno.h>
#include <limits.h>
#include <net/ethernet.h>
#include <net/if.h>
#include <netpacket/packet.h>
#include <poll.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <unistd.h>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#include "rejit_hotswap_common.h"

#define PACKET_TIMEOUT_MS 1500
#define SEND_INTERVAL_US 10000
#define SOCKET_FILTER_TRUNC_LEN 64
#define SOCKET_FILTER_SINK_PORT 41011
#define SOCKET_FILTER_PAYLOAD_LEN 256

static char g_progs_dir[PATH_MAX] = "tests/unittest/build/progs";
static char g_daemon_path[PATH_MAX] = "daemon/target/release/bpfrejit-daemon";
static int g_pass;
static int g_fail;
static int g_skip;

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

#define TEST_SKIP(name, reason) do { \
	printf("  SKIP  %s: %s\n", name, reason); \
	g_skip++; \
} while (0)

static int trim_last_component(char *path)
{
	char *slash;

	slash = strrchr(path, '/');
	if (!slash)
		return -1;
	if (slash == path) {
		path[1] = '\0';
		return 0;
	}

	*slash = '\0';
	return 0;
}

static int get_repo_root(char *buf, size_t buf_sz)
{
	char exe_path[PATH_MAX];
	ssize_t len;
	int i;

	len = readlink("/proc/self/exe", exe_path, sizeof(exe_path) - 1);
	if (len < 0 || len >= (ssize_t)sizeof(exe_path) - 1)
		return -1;
	exe_path[len] = '\0';

	for (i = 0; i < 4; i++) {
		if (trim_last_component(exe_path) < 0)
			return -1;
	}

	if (snprintf(buf, buf_sz, "%s", exe_path) >= (int)buf_sz)
		return -1;
	return 0;
}

static int join_path(char *dst, size_t dst_sz, const char *prefix,
		     const char *suffix)
{
	size_t prefix_len = strlen(prefix);
	size_t suffix_len = strlen(suffix);

	if (prefix_len + suffix_len + 1 > dst_sz)
		return -1;

	memcpy(dst, prefix, prefix_len);
	memcpy(dst + prefix_len, suffix, suffix_len + 1);
	return 0;
}

static void init_default_paths(void)
{
	char repo_root[PATH_MAX];
	const char *override;

	if (get_repo_root(repo_root, sizeof(repo_root)) < 0)
		return;

	override = getenv("BPFREJIT_PROGS_DIR");
	if (override && override[0]) {
		snprintf(g_progs_dir, sizeof(g_progs_dir), "%s", override);
	} else {
		join_path(g_progs_dir, sizeof(g_progs_dir), repo_root,
			  "/tests/unittest/build/progs");
	}

	override = getenv("BPFREJIT_DAEMON_PATH");
	if (override && override[0]) {
		snprintf(g_daemon_path, sizeof(g_daemon_path), "%s", override);
		return;
	}

	join_path(g_daemon_path, sizeof(g_daemon_path), repo_root,
		  "/daemon/target/release/bpfrejit-daemon");
}

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

static int wait_for_truncated_packet(int fd, char *reason, size_t reason_sz)
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

		if (len == SOCKET_FILTER_TRUNC_LEN)
			return 0;
	}

	snprintf(reason, reason_sz,
		 "timed out waiting for packet length %d",
		 SOCKET_FILTER_TRUNC_LEN);
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

static int get_prog_info_snapshot(int prog_fd, struct bpf_prog_info *info)
{
	__u32 info_len = sizeof(*info);

	memset(info, 0, sizeof(*info));
	return hotswap_get_prog_info(prog_fd, info, &info_len);
}

static int run_daemon_optimize_all_request(char *reason, size_t reason_sz)
{
	char socket_dir_template[] = "/tmp/rejit-daemon-e2e.XXXXXX";
	char socket_path[PATH_MAX];
	char response[65536];
	struct sockaddr_un addr = {};
	pid_t pid;
	int fd = -1;
	ssize_t nread;
	int status;
	size_t used = 0;

	if (!mkdtemp(socket_dir_template)) {
		snprintf(reason, reason_sz, "mkdtemp failed: %s", strerror(errno));
		return -1;
	}
	if (join_path(socket_path, sizeof(socket_path), socket_dir_template,
		      "/daemon.sock") < 0) {
		snprintf(reason, reason_sz, "socket path is too long");
		rmdir(socket_dir_template);
		return -1;
	}

	pid = fork();
	if (pid < 0) {
		snprintf(reason, reason_sz, "fork failed: %s", strerror(errno));
		rmdir(socket_dir_template);
		return -1;
	}

	if (pid == 0) {
		char *const argv[] = {
			g_daemon_path,
			"serve",
			"--socket",
			socket_path,
			NULL,
		};
		execv(g_daemon_path, argv);
		fprintf(stderr, "execv(%s) failed: %s\n", g_daemon_path,
			strerror(errno));
		_exit(127);
	}

	for (int attempt = 0; attempt < 50; attempt++) {
		if (access(socket_path, F_OK) == 0)
			break;
		if (waitpid(pid, &status, WNOHANG) == pid) {
			snprintf(reason, reason_sz,
				 "daemon serve exited early: status=0x%x", status);
			rmdir(socket_dir_template);
			return -1;
		}
		usleep(100000);
	}

	fd = socket(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0);
	if (fd < 0) {
		snprintf(reason, reason_sz, "socket failed: %s", strerror(errno));
		goto fail;
	}

	addr.sun_family = AF_UNIX;
	snprintf(addr.sun_path, sizeof(addr.sun_path), "%s", socket_path);
	if (connect(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		snprintf(reason, reason_sz, "connect failed: %s", strerror(errno));
		goto fail;
	}

	if (write(fd, "{\"cmd\":\"optimize-all\"}\n",
		  strlen("{\"cmd\":\"optimize-all\"}\n")) < 0) {
		snprintf(reason, reason_sz, "write failed: %s", strerror(errno));
		goto fail;
	}

	memset(response, 0, sizeof(response));
	while (used + 1 < sizeof(response)) {
		nread = read(fd, response + used, sizeof(response) - used - 1);
		if (nread < 0 && errno == EINTR)
			continue;
		if (nread <= 0)
			break;
		used += (size_t)nread;
		response[used] = '\0';
		if (strchr(response, '\n'))
			break;
	}
	if (used == 0) {
		snprintf(reason, reason_sz, "read failed: %s",
			 nread < 0 ? strerror(errno) : "empty response");
		goto fail;
	}
	if (!strstr(response, "\"status\":\"ok\"")) {
		snprintf(reason, reason_sz,
			 "daemon optimize-all request failed (%s)", response);
		goto fail;
	}

	close(fd);
	kill(pid, SIGTERM);
	waitpid(pid, &status, 0);
	unlink(socket_path);
	rmdir(socket_dir_template);
	return 0;

fail:
	if (fd >= 0)
		close(fd);
	kill(pid, SIGTERM);
	waitpid(pid, &status, 0);
	unlink(socket_path);
	rmdir(socket_dir_template);
	return -1;
}

static int test_rejit_daemon_optimize_all_request(void)
{
	const char *name = "rejit_daemon_optimize_all_request";
	char obj_path[PATH_MAX];
	char reason[256];
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	struct bpf_map *cfg_map;
	struct worker_ctx worker = {
		.port = SOCKET_FILTER_SINK_PORT,
	};
	pthread_t worker_thread;
	struct bpf_prog_info pre_info;
	struct bpf_prog_info post_info;
	bool worker_started = false;
	__u32 key = 0;
	__u32 cfg_value = SOCKET_FILTER_TRUNC_LEN;
	int capture_fd = -1;
	int sink_fd = -1;
	int cfg_fd;
	int prog_fd;
	int ret = 1;

	if (access(g_daemon_path, X_OK) < 0) {
		TEST_SKIP(name, "daemon binary not found; build daemon/target/release/bpfrejit-daemon first");
		return 0;
	}

	if (join_path(obj_path, sizeof(obj_path), g_progs_dir,
		      "/test_daemon_e2e_socket_filter.bpf.o") < 0) {
		TEST_FAIL(name, "object path is too long");
		goto out;
	}

	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_SKIP(name, "cannot open test_daemon_e2e_socket_filter.bpf.o");
		obj = NULL;
		ret = 0;
		goto out;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_SKIP(name, "failed to load BPF object (kernel mismatch?)");
		ret = 0;
		goto out;
	}

	prog = bpf_object__find_program_by_name(obj,
						"rejit_daemon_e2e_socket_filter");
	cfg_map = bpf_object__find_map_by_name(obj, "cfg_map");
	if (!prog || !cfg_map) {
		TEST_FAIL(name, "required program or map not found");
		goto out;
	}

	prog_fd = bpf_program__fd(prog);
	cfg_fd = bpf_map__fd(cfg_map);
	if (prog_fd < 0 || cfg_fd < 0) {
		TEST_FAIL(name, "invalid prog/map fd");
		goto out;
	}

	if (bpf_map_update_elem(cfg_fd, &key, &cfg_value, BPF_ANY) < 0) {
		TEST_FAIL(name, "cfg_map update failed");
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
		TEST_SKIP(name, "SO_ATTACH_BPF failed");
		ret = 0;
		goto out;
	}

	if (get_prog_info_snapshot(prog_fd, &pre_info) < 0) {
		TEST_FAIL(name, "failed to read pre-daemon prog_info");
		goto out;
	}

	if (pthread_create(&worker_thread, NULL, socket_filter_worker, &worker) != 0) {
		TEST_FAIL(name, "pthread_create failed");
		goto out;
	}
	worker_started = true;

	drain_socket(capture_fd);
	if (wait_for_truncated_packet(capture_fd, reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	if (run_daemon_optimize_all_request(reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	if (get_prog_info_snapshot(prog_fd, &post_info) < 0) {
		TEST_FAIL(name, "failed to read post-daemon prog_info");
		goto out;
	}

	if (post_info.orig_prog_len == 0) {
		snprintf(reason, sizeof(reason),
			 "orig_prog_len is still 0 after daemon optimize-all request (pre_xlated=%u post_xlated=%u)",
			 pre_info.xlated_prog_len, post_info.xlated_prog_len);
		TEST_FAIL(name, reason);
		goto out;
	}

	if (post_info.xlated_prog_len >= pre_info.xlated_prog_len) {
		snprintf(reason, sizeof(reason),
			 "xlated_prog_len did not shrink after daemon optimize-all request (pre=%u post=%u)",
			 pre_info.xlated_prog_len, post_info.xlated_prog_len);
		TEST_FAIL(name, reason);
		goto out;
	}

	drain_socket(capture_fd);
	if (wait_for_truncated_packet(capture_fd, reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	printf("    prog_id=%u pre_xlated=%u post_xlated=%u post_orig=%u\n",
	       pre_info.id, pre_info.xlated_prog_len, post_info.xlated_prog_len,
	       post_info.orig_prog_len);
	TEST_PASS(name);
	ret = 0;

out:
	worker.stop = true;
	if (worker_started)
		pthread_join(worker_thread, NULL);
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
	init_default_paths();
	if (argc > 1)
		snprintf(g_progs_dir, sizeof(g_progs_dir), "%s", argv[1]);

	if (test_rejit_daemon_optimize_all_request())
		return 1;

	printf("\nSummary: pass=%d fail=%d skip=%d\n", g_pass, g_fail, g_skip);
	return g_fail ? 1 : 0;
}
