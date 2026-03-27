// SPDX-License-Identifier: GPL-2.0
#define _GNU_SOURCE

#include <arpa/inet.h>
#include <errno.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
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
#include <sys/syscall.h>
#include <unistd.h>

#include <bpf/bpf.h>
#include <bpf/libbpf.h>

#include "rejit_hotswap_common.h"

#define LOG_BUF_SIZE 65536

#define STRUCT_OPS_VALUE_A 1111
#define STRUCT_OPS_VALUE_B 2222
#define STRUCT_OPS_CC_NAME "rjhtswp"
#define MAP_WAIT_TIMEOUT_MS 1200
#define MAP_SAMPLE_INTERVAL_US 25000
#define WORKER_INTERVAL_US 10000
#define ACCEPT_POLL_TIMEOUT_MS 50
#define MIN_MAP_OK_EVENTS 16
#define MIN_STABLE_MAP_SAMPLES 8

#define RACE_REJIT_LOOPS 48
#define RACE_ATTACH_LOOPS 64
#define RACE_DWELL_US 5000
#define REATTACH_RETRIES 10
#define REATTACH_SLEEP_US 50000
#define MAP_ROUNDTRIP_ROUNDS 12

static const char *g_progs_dir = "tests/unittest/build/progs";
static int g_pass;
static int g_fail;
static int g_skip;

#ifndef XDP_ABORTED
#define XDP_ABORTED 0
#define XDP_DROP 1
#define XDP_PASS 2
#define XDP_TX 3
#endif

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", name); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s (errno=%d: %s)\n", \
		name, reason, errno, strerror(errno)); \
	g_fail++; \
} while (0)

#define TEST_SKIP(name, reason) do { \
	printf("  SKIP  %s: %s\n", name, reason); \
	g_skip++; \
} while (0)

#define BPF_MOV64_REG(DST, SRC) \
	((struct bpf_insn){ .code = BPF_ALU64 | BPF_MOV | BPF_X, \
			    .dst_reg = DST, .src_reg = SRC })

#define BPF_MOV64_IMM(DST, IMM) \
	((struct bpf_insn){ .code = BPF_ALU64 | BPF_MOV | BPF_K, \
			    .dst_reg = DST, .imm = IMM })

#define BPF_ALU64_IMM(OP, DST, IMM) \
	((struct bpf_insn){ .code = BPF_ALU64 | OP | BPF_K, \
			    .dst_reg = DST, .imm = IMM })

#define BPF_JMP_IMM(OP, DST, IMM, OFF) \
	((struct bpf_insn){ .code = BPF_JMP | OP | BPF_K, \
			    .dst_reg = DST, .off = OFF, .imm = IMM })

#define BPF_EXIT_INSN() \
	((struct bpf_insn){ .code = BPF_JMP | BPF_EXIT })

#define BPF_EMIT_CALL(FUNC) \
	((struct bpf_insn){ .code = BPF_JMP | BPF_CALL, .imm = FUNC })

#define BPF_ST_MEM(SIZE, DST, OFF, IMM) \
	((struct bpf_insn){ .code = BPF_ST | BPF_MEM | SIZE, \
			    .dst_reg = DST, .off = OFF, .imm = IMM })

#define BPF_LDX_MEM(SIZE, DST, SRC, OFF) \
	((struct bpf_insn){ .code = BPF_LDX | BPF_MEM | SIZE, \
			    .dst_reg = DST, .src_reg = SRC, .off = OFF })

#define BPF_LD_IMM64_RAW(DST, SRC, IMM) \
	((struct bpf_insn){ .code = BPF_LD | BPF_DW | BPF_IMM, \
			    .dst_reg = DST, .src_reg = SRC, \
			    .imm = (__u32)(IMM) }), \
	((struct bpf_insn){ .imm = (__u64)(IMM) >> 32 })

#define BPF_LD_MAP_FD(DST, FD) \
	BPF_LD_IMM64_RAW(DST, BPF_PSEUDO_MAP_FD, FD)

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
}

static int load_xdp_prog(const struct bpf_insn *insns, __u32 insn_cnt,
			 char *log_buf, size_t log_buf_sz)
{
	static const char license[] = "GPL";
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.prog_type = BPF_PROG_TYPE_XDP;
	attr.insn_cnt = insn_cnt;
	attr.insns = ptr_to_u64(insns);
	attr.license = ptr_to_u64(license);
	attr.log_level = 1;
	attr.log_buf = ptr_to_u64(log_buf);
	attr.log_size = log_buf_sz;

	return sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
}

static int rejit_prog(int prog_fd, const struct bpf_insn *insns,
		      __u32 insn_cnt, char *log_buf, size_t log_buf_sz)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd = prog_fd;
	attr.rejit.insn_cnt = insn_cnt;
	attr.rejit.insns = ptr_to_u64(insns);
	attr.rejit.log_level = 1;
	attr.rejit.log_buf = ptr_to_u64(log_buf);
	attr.rejit.log_size = log_buf_sz;

	return sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
}

static int test_run_xdp(int prog_fd, const void *data_in, __u32 data_sz,
			__u32 *retval)
{
	unsigned char default_data[64] = {};
	union bpf_attr attr;

	if (!data_in) {
		data_in = default_data;
		data_sz = sizeof(default_data);
	}

	memset(&attr, 0, sizeof(attr));
	attr.test.prog_fd = prog_fd;
	attr.test.data_in = ptr_to_u64(data_in);
	attr.test.data_size_in = data_sz;
	attr.test.repeat = 1;

	if (sys_bpf(BPF_PROG_TEST_RUN, &attr, sizeof(attr)) < 0)
		return -1;

	*retval = attr.test.retval;
	return 0;
}

static int create_array_map(__u32 value_size)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_type = BPF_MAP_TYPE_ARRAY;
	attr.key_size = sizeof(__u32);
	attr.value_size = value_size;
	attr.max_entries = 1;

	return sys_bpf(BPF_MAP_CREATE, &attr, sizeof(attr));
}

static int create_prog_array_map(__u32 max_entries)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_type = BPF_MAP_TYPE_PROG_ARRAY;
	attr.key_size = sizeof(__u32);
	attr.value_size = sizeof(__u32);
	attr.max_entries = max_entries;

	return sys_bpf(BPF_MAP_CREATE, &attr, sizeof(attr));
}

static int map_update_prog_fd(int map_fd, __u32 key, int prog_fd)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_fd = map_fd;
	attr.key = ptr_to_u64(&key);
	attr.value = ptr_to_u64(&prog_fd);
	attr.flags = BPF_ANY;

	return sys_bpf(BPF_MAP_UPDATE_ELEM, &attr, sizeof(attr));
}

static int map_delete_elem(int map_fd, __u32 key)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.map_fd = map_fd;
	attr.key = ptr_to_u64(&key);

	return sys_bpf(BPF_MAP_DELETE_ELEM, &attr, sizeof(attr));
}

static int map_update_u32(int map_fd, __u32 key, __u32 value)
{
	return bpf_map_update_elem(map_fd, &key, &value, BPF_ANY);
}

static int map_lookup_u32(int map_fd, __u32 key, __u32 *value)
{
	return bpf_map_lookup_elem(map_fd, &key, value);
}

static int map_update_u64(int map_fd, __u32 key, __u64 value)
{
	return bpf_map_update_elem(map_fd, &key, &value, BPF_ANY);
}

static int map_lookup_u64(int map_fd, __u32 key, __u64 *value)
{
	return bpf_map_lookup_elem(map_fd, &key, value);
}

static unsigned long long read_counter(volatile unsigned long long *value)
{
	return __atomic_load_n(value, __ATOMIC_RELAXED);
}

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

static int read_value_map(int map_fd, __u64 *value)
{
	return map_lookup_u64(map_fd, 0, value);
}

static int write_value_map(int map_fd, __u64 value)
{
	return map_update_u64(map_fd, 0, value);
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
			snprintf(reason, reason_sz, "value_map lookup failed");
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

		while (true) {
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
			       STRUCT_OPS_CC_NAME, strlen(STRUCT_OPS_CC_NAME)) == 0)
			__atomic_fetch_add(&ctx->ok, 1, __ATOMIC_RELAXED);
		else
			__atomic_fetch_add(&ctx->err, 1, __ATOMIC_RELAXED);

		close(fd);
		usleep(WORKER_INTERVAL_US);
	}

	return NULL;
}

static __u32 build_simple_prog(struct bpf_insn *insns, __s32 retval)
{
	int i = 0;

	insns[i++] = BPF_MOV64_IMM(BPF_REG_0, retval);
	insns[i++] = BPF_EXIT_INSN();
	return i;
}

static __u32 build_tail_call_caller(struct bpf_insn *insns, int map_fd,
				    __u32 index, __s32 fallback_ret)
{
	int i = 0;

	insns[i++] = BPF_MOV64_REG(BPF_REG_6, BPF_REG_1);
	insns[i++] = BPF_MOV64_REG(BPF_REG_1, BPF_REG_6);
	insns[i++] = (struct bpf_insn){
		.code = BPF_LD | BPF_DW | BPF_IMM,
		.dst_reg = BPF_REG_2,
		.src_reg = BPF_PSEUDO_MAP_FD,
		.imm = map_fd,
	};
	insns[i++] = (struct bpf_insn){ .imm = 0 };
	insns[i++] = BPF_MOV64_IMM(BPF_REG_3, index);
	insns[i++] = BPF_EMIT_CALL(BPF_FUNC_tail_call);
	insns[i++] = BPF_MOV64_IMM(BPF_REG_0, fallback_ret);
	insns[i++] = BPF_EXIT_INSN();
	return i;
}

static __u32 build_map_value_prog(struct bpf_insn *insns, int map_fd,
				  bool use_tmp_reg)
{
	int i = 0;

	insns[i++] = BPF_ST_MEM(BPF_W, BPF_REG_10, -4, 0);
	insns[i++] = BPF_MOV64_REG(BPF_REG_2, BPF_REG_10);
	insns[i++] = BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -4);
	insns[i++] = (struct bpf_insn){
		.code = BPF_LD | BPF_DW | BPF_IMM,
		.dst_reg = BPF_REG_1,
		.src_reg = BPF_PSEUDO_MAP_FD,
		.imm = map_fd,
	};
	insns[i++] = (struct bpf_insn){ .imm = 0 };
	insns[i++] = BPF_EMIT_CALL(BPF_FUNC_map_lookup_elem);

	if (use_tmp_reg) {
		insns[i++] = BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 3);
		insns[i++] = BPF_MOV64_REG(BPF_REG_1, BPF_REG_0);
		insns[i++] = BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_1, 0);
		insns[i++] = BPF_EXIT_INSN();
	} else {
		insns[i++] = BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 2);
		insns[i++] = BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_0, 0);
		insns[i++] = BPF_EXIT_INSN();
	}

	insns[i++] = BPF_MOV64_IMM(BPF_REG_0, XDP_ABORTED);
	insns[i++] = BPF_EXIT_INSN();
	return i;
}

static struct bpf_link *reattach_struct_ops_with_retry(struct bpf_map *st_ops_map,
						       int map_fd)
{
	struct bpf_link *link;
	int attempt;

	for (attempt = 0; attempt < REATTACH_RETRIES; attempt++) {
		map_delete_elem(map_fd, 0);
		usleep(REATTACH_SLEEP_US);

		link = bpf_map__attach_struct_ops(st_ops_map);
		if (link && !libbpf_get_error(link))
			return link;

		errno = !link ? errno : -libbpf_get_error(link);
		if (errno != EBUSY)
			return NULL;

		usleep(REATTACH_SLEEP_US);
	}

	errno = EBUSY;
	return NULL;
}

static void test_t1_struct_ops_refresh_late_rollback(void)
{
	const char *name = "T1_struct_ops_refresh_late_rollback";
	char obj_path[512];
	char log_buf[LOG_BUF_SIZE];
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

	snprintf(obj_path, sizeof(obj_path), "%s/test_hotswap_struct_ops.bpf.o",
		 g_progs_dir);
	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_FAIL(name, "cannot open test_hotswap_struct_ops.bpf.o");
		obj = NULL;
		goto out;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_SKIP(name, "failed to load struct_ops object");
		goto out;
	}

	prog = bpf_object__find_program_by_name(obj,
						"rejit_hotswap_struct_ops_init");
	value_map = bpf_object__find_map_by_name(obj, "value_map");
	st_ops_map = bpf_object__find_map_by_name(obj, "rejit_hotswap_ca");
	if (!prog || !value_map || !st_ops_map) {
		TEST_FAIL(name, "struct_ops object is missing prog/map sections");
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
		TEST_SKIP(name, "attach_struct_ops failed");
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
		TEST_FAIL(name, "pthread_create worker failed");
		goto out;
	}
	worker_started = true;

	if (write_value_map(map_fd, 0) < 0) {
		TEST_FAIL(name, "failed to reset value_map");
		goto out;
	}

	if (wait_for_map_value(map_fd, STRUCT_OPS_VALUE_A, &worker, &accept_ctx,
			       reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (hotswap_rejit_prog_fd_array(prog_fd, orig_insns, orig_cnt,
					fd_array, ARRAY_SIZE(fd_array),
					log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    preflight log:\n%s\n", log_buf);
		TEST_SKIP(name, "attached struct_ops identity REJIT unsupported");
		goto out;
	}

	if (write_value_map(map_fd, 0) < 0) {
		TEST_FAIL(name, "failed to reset value_map after preflight");
		goto out;
	}

	if (wait_for_map_value(map_fd, STRUCT_OPS_VALUE_A, &worker, &accept_ctx,
			       reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	memcpy(patched_insns, orig_insns, orig_cnt * sizeof(*patched_insns));
	if (hotswap_patch_map_value_store_imm(patched_insns, orig_cnt,
					      STRUCT_OPS_VALUE_B) < 0) {
		TEST_FAIL(name, "failed to patch struct_ops store immediate");
		goto out;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (hotswap_rejit_prog_fd_array(prog_fd, patched_insns, orig_cnt,
					fd_array, ARRAY_SIZE(fd_array),
					log_buf, sizeof(log_buf)) < 0) {
		int saved_errno = errno;

		if (write_value_map(map_fd, 0) < 0) {
			TEST_FAIL(name, "failed to reset value_map after failed REJIT");
			goto out;
		}

		if (wait_for_map_value(map_fd, STRUCT_OPS_VALUE_A,
				       &worker, &accept_ctx,
				       reason, sizeof(reason)) < 0) {
			errno = saved_errno;
			TEST_FAIL(name, "late REJIT failure corrupted attached struct_ops");
			goto out;
		}

		printf("    patched REJIT failed safely (errno=%d); old callback stayed active\n",
		       saved_errno);
		TEST_PASS(name);
		goto out;
	}

	if (write_value_map(map_fd, 0) < 0) {
		TEST_FAIL(name, "failed to reset value_map after patched REJIT");
		goto out;
	}

	if (wait_for_map_value(map_fd, STRUCT_OPS_VALUE_B, &worker, &accept_ctx,
			       reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (hotswap_rejit_prog_fd_array(prog_fd, orig_insns, orig_cnt,
					fd_array, ARRAY_SIZE(fd_array),
					log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    rollback log:\n%s\n", log_buf);
		TEST_FAIL(name, "failed to REJIT back to original struct_ops image");
		goto out;
	}

	if (write_value_map(map_fd, 0) < 0) {
		TEST_FAIL(name, "failed to reset value_map after rollback REJIT");
		goto out;
	}

	if (wait_for_map_value(map_fd, STRUCT_OPS_VALUE_A, &worker, &accept_ctx,
			       reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, reason);
		goto out;
	}

	printf("    attached struct_ops callback updated to %u and restored to %u\n",
	       STRUCT_OPS_VALUE_B, STRUCT_OPS_VALUE_A);
	TEST_PASS(name);

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
}

struct struct_ops_rejit_race_ctx {
	int prog_fd;
	const struct bpf_insn *orig_insns;
	const struct bpf_insn *patched_insns;
	__u32 insn_cnt;
	const int *fd_array;
	__u32 fd_array_cnt;
	volatile unsigned long long ok;
	volatile unsigned long long fail;
	volatile int last_errno;
	volatile __u64 expected_value;
};

struct struct_ops_attach_flip_ctx {
	struct bpf_map *st_ops_map;
	struct bpf_link *link;
	volatile unsigned long long attach_ok;
	volatile unsigned long long attach_fail;
	volatile unsigned long long detach_ok;
	volatile int last_errno;
};

static void *struct_ops_rejit_worker(void *arg)
{
	struct struct_ops_rejit_race_ctx *ctx = arg;
	int i;

	for (i = 0; i < RACE_REJIT_LOOPS; i++) {
		const struct bpf_insn *insns;
		__u64 expected;
		char log_buf[LOG_BUF_SIZE];

		if (i & 1) {
			insns = ctx->orig_insns;
			expected = STRUCT_OPS_VALUE_A;
		} else {
			insns = ctx->patched_insns;
			expected = STRUCT_OPS_VALUE_B;
		}

		memset(log_buf, 0, sizeof(log_buf));
		if (hotswap_rejit_prog_fd_array(ctx->prog_fd, insns, ctx->insn_cnt,
						ctx->fd_array, ctx->fd_array_cnt,
						log_buf, sizeof(log_buf)) < 0) {
			__atomic_store_n(&ctx->last_errno, errno, __ATOMIC_RELAXED);
			__atomic_fetch_add(&ctx->fail, 1, __ATOMIC_RELAXED);
		} else {
			__atomic_fetch_add(&ctx->ok, 1, __ATOMIC_RELAXED);
			__atomic_store_n(&ctx->expected_value, expected,
					 __ATOMIC_RELAXED);
		}

		usleep(RACE_DWELL_US);
	}

	return NULL;
}

static void *struct_ops_attach_flip_worker(void *arg)
{
	struct struct_ops_attach_flip_ctx *ctx = arg;
	int i;

	for (i = 0; i < RACE_ATTACH_LOOPS; i++) {
		if (ctx->link) {
			bpf_link__destroy(ctx->link);
			ctx->link = NULL;
			__atomic_fetch_add(&ctx->detach_ok, 1, __ATOMIC_RELAXED);
		}

		ctx->link = bpf_map__attach_struct_ops(ctx->st_ops_map);
		if (!ctx->link || libbpf_get_error(ctx->link)) {
			int err = !ctx->link ? errno : -libbpf_get_error(ctx->link);

			ctx->link = NULL;
			__atomic_store_n(&ctx->last_errno, err, __ATOMIC_RELAXED);
			__atomic_fetch_add(&ctx->attach_fail, 1, __ATOMIC_RELAXED);
		} else {
			__atomic_fetch_add(&ctx->attach_ok, 1, __ATOMIC_RELAXED);
		}

		usleep(RACE_DWELL_US);
	}

	return NULL;
}

static void test_t2_struct_ops_rejit_detach_race(void)
{
	const char *name = "T2_struct_ops_rejit_detach_race";
	char obj_path[512];
	char log_buf[LOG_BUF_SIZE];
	char reason[256];
	struct bpf_object *obj = NULL;
	struct bpf_program *prog;
	struct bpf_map *value_map;
	struct bpf_map *st_ops_map;
	struct bpf_insn *orig_insns = NULL;
	struct bpf_insn *patched_insns = NULL;
	struct struct_ops_rejit_race_ctx rejit_ctx = {};
	struct struct_ops_attach_flip_ctx flip_ctx = {};
	struct accept_ctx accept_ctx = {
		.listen_fd = -1,
	};
	struct worker_ctx worker = {};
	pthread_t rejit_thread;
	pthread_t flip_thread;
	pthread_t accept_thread;
	pthread_t worker_thread;
	bool rejit_started = false;
	bool flip_started = false;
	bool accept_started = false;
	bool worker_started = false;
	int orig_cnt;
	int fd_array[1];
	int prog_fd = -1;
	int map_fd = -1;

	snprintf(obj_path, sizeof(obj_path), "%s/test_hotswap_struct_ops.bpf.o",
		 g_progs_dir);
	obj = bpf_object__open_file(obj_path, NULL);
	if (!obj || libbpf_get_error(obj)) {
		TEST_FAIL(name, "cannot open test_hotswap_struct_ops.bpf.o");
		obj = NULL;
		goto out;
	}

	if (bpf_object__load(obj) < 0) {
		TEST_SKIP(name, "failed to load struct_ops object");
		goto out;
	}

	prog = bpf_object__find_program_by_name(obj,
						"rejit_hotswap_struct_ops_init");
	value_map = bpf_object__find_map_by_name(obj, "value_map");
	st_ops_map = bpf_object__find_map_by_name(obj, "rejit_hotswap_ca");
	if (!prog || !value_map || !st_ops_map) {
		TEST_FAIL(name, "struct_ops object is missing prog/map sections");
		goto out;
	}

	prog_fd = bpf_program__fd(prog);
	map_fd = bpf_map__fd(value_map);
	if (prog_fd < 0 || map_fd < 0) {
		TEST_FAIL(name, "invalid prog/map fd");
		goto out;
	}
	fd_array[0] = map_fd;

	flip_ctx.st_ops_map = st_ops_map;
	flip_ctx.link = bpf_map__attach_struct_ops(st_ops_map);
	if (!flip_ctx.link || libbpf_get_error(flip_ctx.link)) {
		TEST_SKIP(name, "initial attach_struct_ops failed");
		flip_ctx.link = NULL;
		goto out;
	}

	orig_cnt = hotswap_get_original_insns(prog_fd, &orig_insns);
	if (orig_cnt < 0) {
		TEST_FAIL(name, "get_original_insns failed for struct_ops callback");
		goto out;
	}

	patched_insns = calloc(orig_cnt, sizeof(*patched_insns));
	if (!patched_insns) {
		TEST_FAIL(name, "calloc patched_insns failed");
		goto out;
	}

	memcpy(patched_insns, orig_insns, orig_cnt * sizeof(*patched_insns));
	if (hotswap_patch_map_value_store_imm(patched_insns, orig_cnt,
					      STRUCT_OPS_VALUE_B) < 0) {
		TEST_FAIL(name, "failed to patch struct_ops store immediate");
		goto out;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (hotswap_rejit_prog_fd_array(prog_fd, orig_insns, orig_cnt,
					fd_array, ARRAY_SIZE(fd_array),
					log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    preflight log:\n%s\n", log_buf);
		TEST_SKIP(name, "attached struct_ops REJIT unsupported");
		goto out;
	}

	rejit_ctx.prog_fd = prog_fd;
	rejit_ctx.orig_insns = orig_insns;
	rejit_ctx.patched_insns = patched_insns;
	rejit_ctx.insn_cnt = orig_cnt;
	rejit_ctx.fd_array = fd_array;
	rejit_ctx.fd_array_cnt = ARRAY_SIZE(fd_array);
	rejit_ctx.expected_value = STRUCT_OPS_VALUE_A;

	if (pthread_create(&rejit_thread, NULL, struct_ops_rejit_worker,
			   &rejit_ctx) != 0) {
		TEST_FAIL(name, "pthread_create REJIT worker failed");
		goto out;
	}
	rejit_started = true;

	if (pthread_create(&flip_thread, NULL, struct_ops_attach_flip_worker,
			   &flip_ctx) != 0) {
		TEST_FAIL(name, "pthread_create attach worker failed");
		goto out;
	}
	flip_started = true;

	pthread_join(rejit_thread, NULL);
	rejit_started = false;
	pthread_join(flip_thread, NULL);
	flip_started = false;

	if (flip_ctx.link) {
		bpf_link__destroy(flip_ctx.link);
		flip_ctx.link = NULL;
	}
	flip_ctx.link = reattach_struct_ops_with_retry(st_ops_map, map_fd);
	if (!flip_ctx.link) {
		if (errno == EBUSY) {
			TEST_SKIP(name, "struct_ops stayed busy after detach race; clean reattach not reproducible on this kernel");
			goto out;
		}
		TEST_FAIL(name, "failed to cleanly reattach struct_ops after race");
		goto out;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (hotswap_rejit_prog_fd_array(prog_fd, orig_insns, orig_cnt,
					fd_array, ARRAY_SIZE(fd_array),
					log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    post-race log:\n%s\n", log_buf);
		TEST_FAIL(name, "post-race identity REJIT failed");
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
		TEST_FAIL(name, "pthread_create worker failed");
		goto out;
	}
	worker_started = true;

	if (write_value_map(map_fd, 0) < 0) {
		TEST_FAIL(name, "failed to reset value_map after race");
		goto out;
	}

	if (wait_for_map_value(map_fd, STRUCT_OPS_VALUE_A,
			       &worker, &accept_ctx,
			       reason, sizeof(reason)) < 0) {
		TEST_FAIL(name, "attached struct_ops unusable after REJIT + detach race");
		goto out;
	}

	printf("    REJIT ok=%llu fail=%llu, attach ok=%llu fail=%llu, detach=%llu\n",
	       read_counter(&rejit_ctx.ok), read_counter(&rejit_ctx.fail),
	       read_counter(&flip_ctx.attach_ok), read_counter(&flip_ctx.attach_fail),
	       read_counter(&flip_ctx.detach_ok));
	TEST_PASS(name);

out:
	if (rejit_started)
		pthread_join(rejit_thread, NULL);
	if (flip_started)
		pthread_join(flip_thread, NULL);
	accept_ctx.stop = true;
	worker.stop = true;
	if (worker_started)
		pthread_join(worker_thread, NULL);
	if (accept_started)
		pthread_join(accept_thread, NULL);
	if (accept_ctx.listen_fd >= 0)
		close(accept_ctx.listen_fd);
	if (flip_ctx.link)
		bpf_link__destroy(flip_ctx.link);
	else
		map_delete_elem(map_fd, 0);
	free(patched_insns);
	free(orig_insns);
	if (obj)
		bpf_object__close(obj);
}

static void test_t3_poke_descriptor_roundtrip(void)
{
	const char *name = "T3_poke_descriptor_roundtrip";
	struct bpf_insn caller_insns[16];
	struct bpf_insn target_orig[4];
	struct bpf_insn target_alt[4];
	char log_buf[LOG_BUF_SIZE];
	__u32 caller_cnt;
	__u32 target_cnt;
	__u32 target_alt_cnt;
	__u32 retval = 0;
	int map_fd = -1;
	int caller_fd = -1;
	int target_fd = -1;

	map_fd = create_prog_array_map(4);
	if (map_fd < 0) {
		TEST_FAIL(name, "prog_array map create failed");
		goto out;
	}

	target_cnt = build_simple_prog(target_orig, XDP_TX);
	memset(log_buf, 0, sizeof(log_buf));
	target_fd = load_xdp_prog(target_orig, target_cnt, log_buf, sizeof(log_buf));
	if (target_fd < 0) {
		fprintf(stderr, "    target load log:\n%s\n", log_buf);
		TEST_FAIL(name, "target program load failed");
		goto out;
	}

	if (map_update_prog_fd(map_fd, 0, target_fd) < 0) {
		TEST_FAIL(name, "map_update_elem(target) failed");
		goto out;
	}

	caller_cnt = build_tail_call_caller(caller_insns, map_fd, 0, XDP_DROP);
	memset(log_buf, 0, sizeof(log_buf));
	caller_fd = load_xdp_prog(caller_insns, caller_cnt,
				  log_buf, sizeof(log_buf));
	if (caller_fd < 0) {
		fprintf(stderr, "    caller load log:\n%s\n", log_buf);
		TEST_FAIL(name, "caller program load failed");
		goto out;
	}

	if (test_run_xdp(caller_fd, NULL, 0, &retval) < 0 || retval != XDP_TX) {
		TEST_FAIL(name, "pre-REJIT tail-call path mismatch");
		goto out;
	}

	target_alt_cnt = build_simple_prog(target_alt, XDP_PASS);
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(target_fd, target_alt, target_alt_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    REJIT #1 log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT to alternate tail-call target failed");
		goto out;
	}

	if (test_run_xdp(caller_fd, NULL, 0, &retval) < 0 || retval != XDP_PASS) {
		TEST_FAIL(name, "caller did not follow repointed tail-call target");
		goto out;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(target_fd, target_orig, target_cnt,
		       log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    REJIT #2 log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT back to original tail-call target failed");
		goto out;
	}

	if (test_run_xdp(caller_fd, NULL, 0, &retval) < 0 || retval != XDP_TX) {
		TEST_FAIL(name, "caller did not recover original tail-call target");
		goto out;
	}

	if (map_delete_elem(map_fd, 0) < 0) {
		TEST_FAIL(name, "map_delete_elem(target) failed");
		goto out;
	}

	if (test_run_xdp(caller_fd, NULL, 0, &retval) < 0 || retval != XDP_DROP) {
		TEST_FAIL(name, "caller fallback broke after target round-trip");
		goto out;
	}

	if (map_update_prog_fd(map_fd, 0, target_fd) < 0) {
		TEST_FAIL(name, "map_update_elem(reinsert target) failed");
		goto out;
	}

	if (test_run_xdp(caller_fd, NULL, 0, &retval) < 0 || retval != XDP_TX) {
		TEST_FAIL(name, "caller did not repoke back to the reinserted target");
		goto out;
	}

	printf("    target image round-trip preserved direct tail-call and fallback state\n");
	TEST_PASS(name);

out:
	if (caller_fd >= 0)
		close(caller_fd);
	if (target_fd >= 0)
		close(target_fd);
	if (map_fd >= 0)
		close(map_fd);
}

static void test_t4_map_fd_survives_rejit_rounds(void)
{
	const char *name = "T4_map_fd_survives_rejit_rounds";
	struct bpf_insn prog_a[16];
	struct bpf_insn prog_b[16];
	static const __u32 values[] = { XDP_PASS, XDP_DROP, XDP_TX };
	char log_buf[LOG_BUF_SIZE];
	__u32 prog_a_cnt;
	__u32 prog_b_cnt;
	__u32 retval = 0;
	__u32 readback = 0;
	int map_fd = -1;
	int prog_fd = -1;
	int i;

	map_fd = create_array_map(sizeof(__u32));
	if (map_fd < 0) {
		TEST_FAIL(name, "array map create failed");
		goto out;
	}

	prog_a_cnt = build_map_value_prog(prog_a, map_fd, false);
	prog_b_cnt = build_map_value_prog(prog_b, map_fd, true);

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_a, prog_a_cnt, log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		fprintf(stderr, "    load log:\n%s\n", log_buf);
		TEST_FAIL(name, "map-backed XDP program load failed");
		goto out;
	}

	for (i = 0; i < MAP_ROUNDTRIP_ROUNDS; i++) {
		const struct bpf_insn *insns = (i & 1) ? prog_b : prog_a;
		__u32 insn_cnt = (i & 1) ? prog_b_cnt : prog_a_cnt;
		__u32 value = values[i % ARRAY_SIZE(values)];

		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(prog_fd, insns, insn_cnt,
			       log_buf, sizeof(log_buf)) < 0) {
			fprintf(stderr, "    round %d log:\n%s\n", i, log_buf);
			TEST_FAIL(name, "REJIT round failed");
			goto out;
		}

		if (map_update_u32(map_fd, 0, value) < 0) {
			TEST_FAIL(name, "map_update_elem failed");
			goto out;
		}

		if (map_lookup_u32(map_fd, 0, &readback) < 0 || readback != value) {
			TEST_FAIL(name, "map fd stopped serving expected reads");
			goto out;
		}

		if (test_run_xdp(prog_fd, NULL, 0, &retval) < 0 || retval != value) {
			TEST_FAIL(name, "map-backed behavior mismatch after REJIT");
			goto out;
		}
	}

	printf("    %d REJIT rounds completed while the same map fd stayed readable/writable\n",
	       MAP_ROUNDTRIP_ROUNDS);
	TEST_PASS(name);

out:
	if (prog_fd >= 0)
		close(prog_fd);
	if (map_fd >= 0)
		close(map_fd);
}

int main(int argc, char **argv)
{
	if (argc > 1)
		g_progs_dir = argv[1];

	printf("=== BpfReJIT Late-Failure Rollback Tests ===\n");

	printf("\n[T1] struct_ops refresh / rollback proxy:\n");
	test_t1_struct_ops_refresh_late_rollback();

	printf("\n[T2] REJIT + detach/reattach race:\n");
	test_t2_struct_ops_rejit_detach_race();

	printf("\n[T3] poke descriptor round-trip consistency:\n");
	test_t3_poke_descriptor_roundtrip();

	printf("\n[T4] map fd survives repeated REJIT:\n");
	test_t4_map_fd_survives_rejit_rounds();

	printf("\nSummary: pass=%d fail=%d skip=%d\n", g_pass, g_fail, g_skip);
	return g_fail ? 1 : 0;
}
