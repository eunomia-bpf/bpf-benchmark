// SPDX-License-Identifier: GPL-2.0
#define _GNU_SOURCE

#include <arpa/inet.h>
#include <errno.h>
#include <linux/pkt_cls.h>
#include <net/if.h>
#include <poll.h>
#include <sched.h>
#include <signal.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#include "rejit_hotswap_common.h"

#define HOTSWAP_ROUNDS 10
#define SEND_INTERVAL_US 10000
#define ROUND_DWELL_US 800000
#define UDP_TIMEOUT_MS 30000
#define HOTSWAP_TC_PORT 41012
#define HOTSWAP_TC_ADDR_A "10.203.0.1"
#define HOTSWAP_TC_ADDR_B "10.203.0.2"

static const char *g_progs_dir = "tests/unittest/build/progs";
static int g_pass;
static int g_fail;

struct worker_ctx {
	pid_t pid;
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

static int run_cmd(const char *fmt, ...)
{
	char cmd[512];
	va_list ap;
	int ret;

	va_start(ap, fmt);
	vsnprintf(cmd, sizeof(cmd), fmt, ap);
	va_end(ap);

	ret = system(cmd);
	if (ret == -1)
		return -1;
	if (!WIFEXITED(ret) || WEXITSTATUS(ret) != 0) {
		errno = EIO;
		return -1;
	}

	return 0;
}

static int setup_veth_pair(const char *if_a, const char *if_b)
{
	if (run_cmd("PATH=/usr/sbin:/usr/bin:/sbin:/bin ip link add %s type veth peer name %s",
		    if_a, if_b) < 0)
		return -1;
	if (run_cmd("PATH=/usr/sbin:/usr/bin:/sbin:/bin ip addr add %s/24 dev %s",
		    HOTSWAP_TC_ADDR_A, if_a) < 0)
		return -1;
	if (run_cmd("PATH=/usr/sbin:/usr/bin:/sbin:/bin ip addr add %s/24 dev %s",
		    HOTSWAP_TC_ADDR_B, if_b) < 0)
		return -1;
	if (run_cmd("PATH=/usr/sbin:/usr/bin:/sbin:/bin ip link set dev %s up",
		    if_a) < 0)
		return -1;
	if (run_cmd("PATH=/usr/sbin:/usr/bin:/sbin:/bin ip link set dev %s up",
		    if_b) < 0)
		return -1;
	return 0;
}

static void cleanup_veth_pair(const char *if_a)
{
	run_cmd("PATH=/usr/sbin:/usr/bin:/sbin:/bin ip link del %s", if_a);
}

static int open_udp_receiver(const char *ip, int port)
{
	struct sockaddr_in addr = {};
	int fd;

	fd = socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, 0);
	if (fd < 0)
		return -1;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	if (inet_pton(AF_INET, ip, &addr.sin_addr) != 1) {
		close(fd);
		errno = EINVAL;
		return -1;
	}

	if (bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		close(fd);
		return -1;
	}

	return fd;
}

static void drain_udp_socket(int fd, uint64_t *last_seq)
{
	char buf[256];

	while (1) {
		ssize_t len;

		len = recv(fd, buf, sizeof(buf), MSG_DONTWAIT);
		if (len < 0)
			break;
		if ((size_t)len >= sizeof(*last_seq))
			memcpy(last_seq, buf, sizeof(*last_seq));
	}
}

static int wait_for_udp_packet(int fd, uint64_t *last_seq,
			       char *reason, size_t reason_sz)
{
	struct pollfd pfd = {
		.fd = fd,
		.events = POLLIN,
	};
	int elapsed_ms = 0;

	while (elapsed_ms < UDP_TIMEOUT_MS) {
		char buf[256];
		ssize_t len;
		int ret;

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
		if ((size_t)len >= sizeof(*last_seq)) {
			uint64_t seq;

			memcpy(&seq, buf, sizeof(seq));
			if (seq > *last_seq) {
				*last_seq = seq;
				return 0;
			}
		}
	}

	snprintf(reason, reason_sz, "timed out waiting for UDP packet");
	errno = ETIMEDOUT;
	return -1;
}

static int ensure_no_udp_packet(int fd, uint64_t *last_seq,
				char *reason, size_t reason_sz)
{
	struct pollfd pfd = {
		.fd = fd,
		.events = POLLIN,
	};
	int ret;

	ret = poll(&pfd, 1, UDP_TIMEOUT_MS / 2);
	if (ret < 0) {
		snprintf(reason, reason_sz, "poll failed: %s", strerror(errno));
		return -1;
	}
	if (ret == 0)
		return 0;

	drain_udp_socket(fd, last_seq);
	snprintf(reason, reason_sz, "packet still received after TC_ACT_SHOT");
	errno = EBUSY;
	return -1;
}

static void udp_send_child_loop(int port)
{
	struct sockaddr_in bind_addr = {};
	struct sockaddr_in dst_addr = {};
	uint64_t seq = 0;
	int fd;

	fd = socket(AF_INET, SOCK_DGRAM | SOCK_CLOEXEC, 0);
	if (fd < 0)
		_exit(120);

	bind_addr.sin_family = AF_INET;
	if (inet_pton(AF_INET, HOTSWAP_TC_ADDR_B, &bind_addr.sin_addr) != 1)
		_exit(121);
	if (bind(fd, (struct sockaddr *)&bind_addr, sizeof(bind_addr)) < 0)
		_exit(122);

	dst_addr.sin_family = AF_INET;
	dst_addr.sin_port = htons(port);
	if (inet_pton(AF_INET, HOTSWAP_TC_ADDR_A, &dst_addr.sin_addr) != 1)
		_exit(123);

	while (1) {
		if (sendto(fd, &seq, sizeof(seq), 0,
			   (struct sockaddr *)&dst_addr, sizeof(dst_addr)) < 0) {
			if (errno == EINTR || errno == EAGAIN || errno == ENOBUFS)
				continue;
			_exit(124);
		}
		seq++;
		usleep(SEND_INTERVAL_US);
	}
}

static int spawn_udp_sender(const char *ifname, struct worker_ctx *worker)
{
	int ready_pipe[2] = { -1, -1 };
	int start_pipe[2] = { -1, -1 };
	char ready = 0;
	pid_t pid;

	if (pipe(ready_pipe) < 0 || pipe(start_pipe) < 0)
		goto fail;

	pid = fork();
	if (pid < 0)
		goto fail;

	if (pid == 0) {
		close(ready_pipe[0]);
		close(start_pipe[1]);

		if (unshare(CLONE_NEWNET) < 0)
			_exit(110);
		if (write(ready_pipe[1], "R", 1) != 1)
			_exit(111);
		close(ready_pipe[1]);

		if (read(start_pipe[0], &ready, 1) != 1)
			_exit(112);
		close(start_pipe[0]);

		if (run_cmd("PATH=/usr/sbin:/usr/bin:/sbin:/bin ip link set dev lo up") < 0)
			_exit(113);
		if (run_cmd("PATH=/usr/sbin:/usr/bin:/sbin:/bin ip addr replace %s/24 dev %s",
			    HOTSWAP_TC_ADDR_B, ifname) < 0)
			_exit(114);
		if (run_cmd("PATH=/usr/sbin:/usr/bin:/sbin:/bin ip link set dev %s up",
			    ifname) < 0)
			_exit(115);

		udp_send_child_loop(worker->port);
		_exit(116);
	}

	close(ready_pipe[1]);
	close(start_pipe[0]);

	if (read(ready_pipe[0], &ready, 1) != 1) {
		close(ready_pipe[0]);
		goto fail_child;
	}
	close(ready_pipe[0]);

	if (run_cmd("PATH=/usr/sbin:/usr/bin:/sbin:/bin ip link set dev %s netns %d",
		    ifname, pid) < 0)
		goto fail_child;

	if (write(start_pipe[1], "G", 1) != 1)
		goto fail_child;
	close(start_pipe[1]);

	worker->pid = pid;
	return 0;

fail_child:
	close(start_pipe[1]);
	kill(pid, SIGTERM);
	waitpid(pid, NULL, 0);
fail:
	if (ready_pipe[0] >= 0)
		close(ready_pipe[0]);
	if (ready_pipe[1] >= 0)
		close(ready_pipe[1]);
	if (start_pipe[0] >= 0)
		close(start_pipe[0]);
	if (start_pipe[1] >= 0)
		close(start_pipe[1]);
	return -1;
}

static void stop_udp_sender(struct worker_ctx *worker)
{
	if (worker->pid <= 0)
		return;

	kill(worker->pid, SIGTERM);
	waitpid(worker->pid, NULL, 0);
	worker->pid = 0;
}

static void maybe_override_reason_with_worker_exit(struct worker_ctx *worker,
						   char *reason, size_t reason_sz)
{
	int status;
	pid_t ret;

	if (worker->pid <= 0)
		return;

	ret = waitpid(worker->pid, &status, WNOHANG);
	if (ret != worker->pid)
		return;

	worker->pid = 0;
	if (WIFEXITED(status))
		snprintf(reason, reason_sz, "packet worker exited with status %d",
			 WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		snprintf(reason, reason_sz, "packet worker killed by signal %d",
			 WTERMSIG(status));
}

static int test_rejit_hotswap_sched_cls(void)
{
	const char *name = "rejit_hotswap_sched_cls";
	char obj_path[512];
	char if_a[IFNAMSIZ];
	char if_b[IFNAMSIZ];
	char log_buf[65536];
	char reason[256];
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	struct bpf_insn *orig_insns = NULL;
	struct bpf_insn *patched_insns = NULL;
	struct worker_ctx worker = {
		.port = HOTSWAP_TC_PORT,
	};
	struct bpf_tc_hook hook = {};
	struct bpf_tc_opts attach_opts = {};
	struct bpf_tc_opts detach_opts = {};
	bool veth_created = false;
	bool tc_hook_created = false;
	uint64_t last_seq = 0;
	int recv_fd = -1;
	int prog_fd;
	int ifindex;
	int orig_cnt;
	int i;
	int err;
	int ret = 1;

	snprintf(if_a, sizeof(if_a), "rhta%05d", getpid() % 100000);
	snprintf(if_b, sizeof(if_b), "rhtb%05d", getpid() % 100000);

	if (setup_veth_pair(if_a, if_b) < 0) {
		TEST_FAIL(name, "failed to create veth pair");
		goto out;
	}
	veth_created = true;

	recv_fd = open_udp_receiver(HOTSWAP_TC_ADDR_A, HOTSWAP_TC_PORT);
	if (recv_fd < 0) {
		TEST_FAIL(name, "failed to open UDP receiver");
		goto out;
	}

	snprintf(obj_path, sizeof(obj_path), "%s/test_hotswap_sched_cls.bpf.o",
		 g_progs_dir);
	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_FAIL(name, "cannot open test_hotswap_sched_cls.bpf.o");
		obj = NULL;
		goto out;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_FAIL(name, "failed to load BPF object");
		goto out;
	}

	prog = bpf_object__find_program_by_name(obj, "rejit_hotswap_sched_cls");
	if (!prog) {
		TEST_FAIL(name, "program rejit_hotswap_sched_cls not found");
		goto out;
	}

	prog_fd = bpf_program__fd(prog);
	if (prog_fd < 0) {
		TEST_FAIL(name, "invalid program fd");
		goto out;
	}

	ifindex = if_nametoindex(if_a);
	if (!ifindex) {
		TEST_FAIL(name, "if_nametoindex failed for tc ingress device");
		goto out;
	}

	hook.sz = sizeof(hook);
	hook.ifindex = ifindex;
	hook.attach_point = BPF_TC_INGRESS;
	err = bpf_tc_hook_create(&hook);
	if (err < 0 && err != -EEXIST) {
		TEST_FAIL(name, "bpf_tc_hook_create failed");
		goto out;
	}
	tc_hook_created = true;

	attach_opts.sz = sizeof(attach_opts);
	attach_opts.prog_fd = prog_fd;
	attach_opts.handle = 1;
	attach_opts.priority = 1;
	err = bpf_tc_attach(&hook, &attach_opts);
	if (err < 0) {
		TEST_FAIL(name, "bpf_tc_attach failed");
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

	if (spawn_udp_sender(if_b, &worker) < 0) {
		TEST_FAIL(name, "failed to start packet worker");
		goto out;
	}

	drain_udp_socket(recv_fd, &last_seq);
	if (wait_for_udp_packet(recv_fd, &last_seq, reason, sizeof(reason)) < 0) {
		maybe_override_reason_with_worker_exit(&worker, reason,
						      sizeof(reason));
		TEST_FAIL(name, reason);
		goto out;
	}

	for (i = 0; i < HOTSWAP_ROUNDS; i++) {
		bool expect_drop = (i % 2) == 0;

		memcpy(patched_insns, orig_insns, orig_cnt * sizeof(*patched_insns));
		if (hotswap_patch_return_imm(patched_insns, orig_cnt,
					     expect_drop ? TC_ACT_SHOT : TC_ACT_OK) < 0) {
			TEST_FAIL(name, "failed to patch TC action");
			goto out;
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (hotswap_rejit_prog(prog_fd, patched_insns, orig_cnt,
				       log_buf, sizeof(log_buf)) < 0) {
			fprintf(stderr, "    verifier log:\n%s\n", log_buf);
			TEST_FAIL(name, "BPF_PROG_REJIT failed");
			goto out;
		}

		drain_udp_socket(recv_fd, &last_seq);
		if (expect_drop) {
			if (ensure_no_udp_packet(recv_fd, &last_seq,
						 reason, sizeof(reason)) < 0) {
				TEST_FAIL(name, reason);
				goto out;
			}
		} else {
			if (wait_for_udp_packet(recv_fd, &last_seq,
						reason, sizeof(reason)) < 0) {
				maybe_override_reason_with_worker_exit(&worker,
							      reason,
							      sizeof(reason));
				TEST_FAIL(name, reason);
				goto out;
			}
		}

		usleep(ROUND_DWELL_US);
	}

	TEST_PASS(name);
	ret = 0;

out:
	stop_udp_sender(&worker);
	free(patched_insns);
	free(orig_insns);
	if (tc_hook_created) {
		detach_opts.sz = sizeof(detach_opts);
		detach_opts.handle = attach_opts.handle;
		detach_opts.priority = attach_opts.priority;
		bpf_tc_detach(&hook, &detach_opts);
		bpf_tc_hook_destroy(&hook);
	}
	if (obj)
		bpf_object__close(obj);
	if (recv_fd >= 0)
		close(recv_fd);
	if (veth_created)
		cleanup_veth_pair(if_a);
	return ret;
}

int main(int argc, char **argv)
{
	if (argc > 1)
		g_progs_dir = argv[1];

	if (test_rejit_hotswap_sched_cls())
		return 1;

	printf("\nSummary: pass=%d fail=%d\n", g_pass, g_fail);
	return g_fail ? 1 : 0;
}
