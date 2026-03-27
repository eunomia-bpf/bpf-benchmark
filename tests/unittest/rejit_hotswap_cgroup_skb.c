// SPDX-License-Identifier: GPL-2.0
#define _GNU_SOURCE

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#include "rejit_hotswap_common.h"

#define HOTSWAP_ROUNDS 10
#define SEND_INTERVAL_US 10000
#define ROUND_DWELL_US 200000
#define SEND_TIMEOUT_MS 1200
#define HOTSWAP_CGROUP_PORT 41013

static const char *g_progs_dir = "tests/unittest/build/progs";
static int g_pass;
static int g_fail;

struct worker_ctx {
	volatile bool stop;
	int port;
	volatile unsigned long long ok;
	volatile unsigned long long eperm;
	volatile unsigned long long other_err;
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

static int read_self_cgroup_relpath(char *buf, size_t buf_sz)
{
	FILE *fp;
	char line[PATH_MAX + 32];

	fp = fopen("/proc/self/cgroup", "re");
	if (!fp)
		return -1;

	while (fgets(line, sizeof(line), fp)) {
		char *path;
		size_t path_len;

		if (strncmp(line, "0::", 3) != 0)
			continue;

		path = line + 3;
		path[strcspn(path, "\n")] = '\0';
		if (!*path)
			path = "/";
		path_len = strlen(path);
		if (path_len >= buf_sz) {
			fclose(fp);
			errno = ENAMETOOLONG;
			return -1;
		}

		memcpy(buf, path, path_len + 1);
		fclose(fp);
		return 0;
	}

	fclose(fp);
	errno = ENOENT;
	return -1;
}

static int write_pid_to_cgroup(const char *cg_dir, pid_t pid)
{
	char path[PATH_MAX];
	char buf[32];
	ssize_t len;
	int fd;

	snprintf(path, sizeof(path), "%s/cgroup.procs", cg_dir);
	fd = open(path, O_WRONLY | O_CLOEXEC);
	if (fd < 0)
		return -1;

	len = snprintf(buf, sizeof(buf), "%d\n", pid);
	if (write(fd, buf, (size_t)len) != len) {
		close(fd);
		return -1;
	}

	close(fd);
	return 0;
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

static int wait_for_send_mode(struct worker_ctx *worker, bool expect_allow,
			      char *reason, size_t reason_sz)
{
	unsigned long long start_ok = read_counter(&worker->ok);
	unsigned long long start_eperm = read_counter(&worker->eperm);
	unsigned long long start_other = read_counter(&worker->other_err);
	int elapsed_ms = 0;

	while (elapsed_ms < SEND_TIMEOUT_MS) {
		unsigned long long ok_now = read_counter(&worker->ok);
		unsigned long long eperm_now = read_counter(&worker->eperm);
		unsigned long long other_now = read_counter(&worker->other_err);

		if (other_now > start_other) {
			snprintf(reason, reason_sz, "worker saw unexpected send errors");
			errno = EIO;
			return -1;
		}
		if (expect_allow && ok_now > start_ok)
			return 0;
		if (!expect_allow && eperm_now > start_eperm)
			return 0;

		usleep(10000);
		elapsed_ms += 10;
	}

	snprintf(reason, reason_sz, "timed out waiting for send %s",
		 expect_allow ? "success" : "EPERM");
	errno = ETIMEDOUT;
	return -1;
}

static void *cgroup_send_worker(void *arg)
{
	struct worker_ctx *ctx = arg;
	struct sockaddr_in addr = {};
	uint64_t seq = 0;
	int fd;

	fd = socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, 0);
	if (fd < 0)
		return NULL;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(ctx->port);
	addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

	while (!ctx->stop) {
		ssize_t ret;

		ret = sendto(fd, &seq, sizeof(seq), 0,
			     (struct sockaddr *)&addr, sizeof(addr));
		if (ret >= 0) {
			__atomic_fetch_add(&ctx->ok, 1, __ATOMIC_RELAXED);
			seq++;
		} else if (errno == EPERM) {
			__atomic_fetch_add(&ctx->eperm, 1, __ATOMIC_RELAXED);
		} else {
			__atomic_fetch_add(&ctx->other_err, 1, __ATOMIC_RELAXED);
		}

		usleep(SEND_INTERVAL_US);
	}

	close(fd);
	return NULL;
}

static int test_rejit_hotswap_cgroup_skb(void)
{
	const char *name = "rejit_hotswap_cgroup_skb";
	char obj_path[512];
	char log_buf[65536];
	char reason[256];
	char parent_rel[PATH_MAX] = {};
	char parent_path[PATH_MAX] = {};
	char child_path[PATH_MAX] = {};
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	struct bpf_link *link = NULL;
	struct bpf_insn *orig_insns = NULL;
	struct bpf_insn *patched_insns = NULL;
	struct worker_ctx worker = {
		.port = HOTSWAP_CGROUP_PORT,
	};
	pthread_t worker_thread;
	bool worker_started = false;
	bool moved_to_child = false;
	int sink_fd = -1;
	int child_cgroup_fd = -1;
	int prog_fd;
	int orig_cnt;
	int i;
	int ret = 1;

	if (read_self_cgroup_relpath(parent_rel, sizeof(parent_rel)) < 0) {
		TEST_FAIL(name, "failed to read current cgroup");
		goto out;
	}

	if (strcmp(parent_rel, "/") == 0)
		snprintf(parent_path, sizeof(parent_path), "/sys/fs/cgroup");
	else
		snprintf(parent_path, sizeof(parent_path), "/sys/fs/cgroup%s",
			 parent_rel);

	snprintf(child_path, sizeof(child_path), "%s/rejit_hotswap_cgroup_skb_%d",
		 parent_path, getpid());
	if (mkdir(child_path, 0755) < 0) {
		TEST_FAIL(name, "failed to create child cgroup");
		goto out;
	}

	child_cgroup_fd = open(child_path, O_RDONLY | O_DIRECTORY | O_CLOEXEC);
	if (child_cgroup_fd < 0) {
		TEST_FAIL(name, "failed to open child cgroup");
		goto out;
	}

	sink_fd = open_udp_sink(HOTSWAP_CGROUP_PORT);
	if (sink_fd < 0) {
		TEST_FAIL(name, "failed to open UDP sink");
		goto out;
	}

	snprintf(obj_path, sizeof(obj_path), "%s/test_hotswap_cgroup_skb.bpf.o",
		 g_progs_dir);
	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_FAIL(name, "cannot open test_hotswap_cgroup_skb.bpf.o");
		obj = NULL;
		goto out;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_FAIL(name, "failed to load BPF object");
		goto out;
	}

	prog = bpf_object__find_program_by_name(obj, "rejit_hotswap_cgroup_skb");
	if (!prog) {
		TEST_FAIL(name, "program rejit_hotswap_cgroup_skb not found");
		goto out;
	}

	prog_fd = bpf_program__fd(prog);
	if (prog_fd < 0) {
		TEST_FAIL(name, "invalid program fd");
		goto out;
	}

	link = bpf_program__attach_cgroup(prog, child_cgroup_fd);
	if (!link || libbpf_get_error(link)) {
		TEST_FAIL(name, "failed to attach cgroup_skb program");
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

	if (write_pid_to_cgroup(child_path, getpid()) < 0) {
		TEST_FAIL(name, "failed to move process into child cgroup");
		goto out;
	}
	moved_to_child = true;

	if (pthread_create(&worker_thread, NULL, cgroup_send_worker, &worker) != 0) {
		TEST_FAIL(name, "pthread_create failed");
		goto out;
	}
	worker_started = true;

	if (wait_for_send_mode(&worker, true, reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	for (i = 0; i < HOTSWAP_ROUNDS; i++) {
		bool expect_allow = (i % 2) != 0;

		memcpy(patched_insns, orig_insns, orig_cnt * sizeof(*patched_insns));
		if (hotswap_patch_return_imm(patched_insns, orig_cnt,
					     expect_allow ? 1 : 0) < 0) {
			TEST_FAIL(name, "failed to patch cgroup_skb return value");
			goto out;
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (hotswap_rejit_prog(prog_fd, patched_insns, orig_cnt,
				       log_buf, sizeof(log_buf)) < 0) {
			fprintf(stderr, "    verifier log:\n%s\n", log_buf);
			TEST_FAIL(name, "BPF_PROG_REJIT failed");
			goto out;
		}

		if (wait_for_send_mode(&worker, expect_allow,
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
	if (moved_to_child)
		write_pid_to_cgroup(parent_path, getpid());
	free(patched_insns);
	free(orig_insns);
	if (link)
		bpf_link__destroy(link);
	if (obj)
		bpf_object__close(obj);
	if (sink_fd >= 0)
		close(sink_fd);
	if (child_cgroup_fd >= 0)
		close(child_cgroup_fd);
	if (child_path[0])
		rmdir(child_path);
	return ret;
}

int main(int argc, char **argv)
{
	if (argc > 1)
		g_progs_dir = argv[1];

	if (test_rejit_hotswap_cgroup_skb())
		return 1;

	printf("\nSummary: pass=%d fail=%d\n", g_pass, g_fail);
	return g_fail ? 1 : 0;
}
