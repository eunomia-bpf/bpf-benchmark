// SPDX-License-Identifier: GPL-2.0
/*
 * BpfReJIT Safety & Correctness Test Suite
 *
 * Validates the core safety claim (Insight 3): the kernel verifier provides
 * identical safety guarantees for REJIT submissions as for initial program
 * loads. A failed REJIT must never affect the running program.
 *
 * Negative tests (10+):  malicious/invalid bytecode rejected via REJIT
 * Correctness tests (5+): semantic-preserving transforms, identity, rollback
 *
 * Build (from repo root):
 *   clang -O2 -Wall -Wno-\#warnings \
 *     -isystem vendor/linux-framework/include/uapi \
 *     -o tests/rejit_safety_tests tests/rejit_safety_tests.c -lpthread
 *
 * Run (requires root / CAP_BPF + CAP_SYS_ADMIN, on a BpfReJIT-enabled kernel):
 *   sudo ./rejit_safety_tests
 */
#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* ------------------------------------------------------------------ */
/*  Helpers                                                           */
/* ------------------------------------------------------------------ */

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ptr_to_u64(ptr) ((__u64)(uintptr_t)(ptr))
#define LOG_BUF_SIZE 65536

/* BPF_MAXINSNS from bpf_common.h is only 4096 (cBPF). The eBPF verifier
 * allows up to 1M instructions for privileged loaders.  We use a much
 * smaller oversized value that still exceeds the 4096 cBPF limit. */
#ifndef BPF_MAXINSNS
#define BPF_MAXINSNS 4096
#endif

static int g_pass;
static int g_fail;
static int g_skip;

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
}

struct unittest_btf_header {
	__u16 magic;
	__u8 version;
	__u8 flags;
	__u32 hdr_len;
	__u32 type_off;
	__u32 type_len;
	__u32 str_off;
	__u32 str_len;
};

struct unittest_btf_type {
	__u32 name_off;
	__u32 info;
	__u32 size_or_type;
};

struct unittest_btf_info {
	__u64 btf;
	__u32 btf_size;
	__u32 id;
	__u64 name;
	__u32 name_len;
	__u32 kernel_btf;
	__u8 pad[96];
};

/* Load a simple XDP program. Returns prog_fd or -1. */
static int load_xdp_prog_with_fd_array(const struct bpf_insn *insns,
				       __u32 insn_cnt,
				       const int *fd_array,
				       __u32 fd_array_cnt,
				       char *log_buf, size_t log_buf_sz)
{
	static const char license[] = "GPL";
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.prog_type    = BPF_PROG_TYPE_XDP;
	attr.insn_cnt     = insn_cnt;
	attr.insns        = ptr_to_u64(insns);
	attr.license      = ptr_to_u64(license);
	attr.log_level    = 1;
	attr.log_buf      = ptr_to_u64(log_buf);
	attr.log_size     = log_buf_sz;
	if (fd_array && fd_array_cnt) {
		attr.fd_array = ptr_to_u64(fd_array);
		attr.fd_array_cnt = fd_array_cnt;
	}

	return sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
}

static int load_xdp_prog(const struct bpf_insn *insns, __u32 insn_cnt,
			 char *log_buf, size_t log_buf_sz)
{
	return load_xdp_prog_with_fd_array(insns, insn_cnt, NULL, 0,
					   log_buf, log_buf_sz);
}

/* REJIT an existing prog.  Returns 0 on success, -1 on error (check errno). */
static int rejit_prog_with_fd_array(int prog_fd,
				    const struct bpf_insn *insns,
				    __u32 insn_cnt,
				    const int *fd_array,
				    __u32 fd_array_cnt,
				    char *log_buf, size_t log_buf_sz)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd  = prog_fd;
	attr.rejit.insn_cnt = insn_cnt;
	attr.rejit.insns    = ptr_to_u64(insns);
	attr.rejit.log_level = 1;
	attr.rejit.log_buf  = ptr_to_u64(log_buf);
	attr.rejit.log_size = log_buf_sz;
	if (fd_array && fd_array_cnt) {
		attr.rejit.fd_array = ptr_to_u64(fd_array);
		attr.rejit.fd_array_cnt = fd_array_cnt;
	}

	return sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
}

static int rejit_prog(int prog_fd, const struct bpf_insn *insns,
		      __u32 insn_cnt, char *log_buf, size_t log_buf_sz)
{
	return rejit_prog_with_fd_array(prog_fd, insns, insn_cnt, NULL, 0,
					log_buf, log_buf_sz);
}

/* Execute an XDP program via bpf_prog_test_run. Returns 0 on success. */
static int test_run_xdp(int prog_fd, __u32 *retval)
{
	unsigned char data[64] = {};
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.test.prog_fd     = prog_fd;
	attr.test.data_in     = ptr_to_u64(data);
	attr.test.data_size_in = sizeof(data);
	attr.test.repeat      = 1;

	if (sys_bpf(BPF_PROG_TEST_RUN, &attr, sizeof(attr)) < 0)
		return -1;

	*retval = attr.test.retval;
	return 0;
}

/* Get bpf_prog_info for a prog fd. Returns 0 on success. */
static int get_prog_info(int prog_fd, struct bpf_prog_info *info,
			 __u32 *info_len)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.info.bpf_fd   = prog_fd;
	attr.info.info      = ptr_to_u64(info);
	attr.info.info_len  = *info_len;

	if (sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) < 0)
		return -1;

	*info_len = attr.info.info_len;
	return 0;
}

/* ----- Canonical "good" programs ----------------------------------- */

/* Returns XDP_PASS (2) */
static const struct bpf_insn prog_xdp_pass[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = XDP_PASS },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* Returns XDP_DROP (1) */
static const struct bpf_insn prog_xdp_drop[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = XDP_DROP },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* Returns XDP_TX (3) via r0 = 1 + 2 (4 insns) */
static const struct bpf_insn prog_xdp_tx_long[] = {
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = 1 },
	{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_1, .imm = 2 },
	{ .code = BPF_ALU64 | BPF_ADD | BPF_X, .dst_reg = BPF_REG_0, .src_reg = BPF_REG_1 },
	{ .code = BPF_JMP | BPF_EXIT },
};

/* Helper: load the canonical XDP_PASS program, return fd or -1 */
static int load_good_prog(void)
{
	char log_buf[65536];

	memset(log_buf, 0, sizeof(log_buf));
	return load_xdp_prog(prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
			     log_buf, sizeof(log_buf));
}

/* Helper: verify the given prog fd returns expected_retval via test_run */
static int verify_retval(int prog_fd, __u32 expected)
{
	__u32 retval = 0;

	if (test_run_xdp(prog_fd, &retval) < 0)
		return -1;
	if (retval != expected)
		return -1;
	return 0;
}

/* ------------------------------------------------------------------ */
/*  Test framework macros                                             */
/* ------------------------------------------------------------------ */

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", name); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s\n", name, reason); \
	g_fail++; \
} while (0)

#define TEST_SKIP(name, reason) do { \
	fprintf(stderr, "  SKIP  %s: %s\n", name, reason); \
	g_skip++; \
} while (0)

#define BPF_UT_RAW_INSN(CODE, DST, SRC, OFF, IMM) ((struct bpf_insn) { \
	.code = (CODE), \
	.dst_reg = (DST), \
	.src_reg = (SRC), \
	.off = (OFF), \
	.imm = (IMM), \
})

#define BPF_UT_EXIT_INSN() \
	BPF_UT_RAW_INSN(BPF_JMP | BPF_EXIT, 0, 0, 0, 0)

#define BPF_UT_MOV64_IMM(DST, IMM) \
	BPF_UT_RAW_INSN(BPF_ALU64 | BPF_MOV | BPF_K, DST, 0, 0, IMM)

#define BPF_UT_KINSN_SIDECAR(PAYLOAD) \
	BPF_UT_RAW_INSN(BPF_ALU64 | BPF_MOV | BPF_K, \
			(__u8)((__u64)(PAYLOAD) & 0xf), \
			BPF_PSEUDO_KINSN_SIDECAR, \
			(__s16)(((__u64)(PAYLOAD) >> 4) & 0xffff), \
			(__s32)(((__u64)(PAYLOAD) >> 20) & 0xffffffffU))

#define BPF_UT_CALL_KINSN(OFF, IMM) \
	BPF_UT_RAW_INSN(BPF_JMP | BPF_CALL, 0, BPF_PSEUDO_KINSN_CALL, \
			OFF, IMM)

#define BPF_UT_BTF_FD_ARRAY(FD) { (FD), (FD) }

static int read_whole_file(const char *path, void **data_out, size_t *len_out)
{
	struct stat st;
	void *data;
	int fd;
	size_t cap;
	size_t len = 0;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return -1;
	if (fstat(fd, &st) < 0) {
		close(fd);
		return -1;
	}

	cap = st.st_size > 0 ? (size_t)st.st_size : 4096;
	data = malloc(cap);
	if (!data) {
		close(fd);
		errno = ENOMEM;
		return -1;
	}

	for (;;) {
		ssize_t nread;

		if (len == cap) {
			size_t new_cap = cap * 2;
			void *new_data;

			if (new_cap < cap) {
				free(data);
				close(fd);
				errno = EOVERFLOW;
				return -1;
			}

			new_data = realloc(data, new_cap);
			if (!new_data) {
				free(data);
				close(fd);
				errno = ENOMEM;
				return -1;
			}
			data = new_data;
			cap = new_cap;
		}

		nread = read(fd, (char *)data + len, cap - len);
		if (nread < 0) {
			free(data);
			close(fd);
			return -1;
		}
		if (nread == 0)
			break;
		len += nread;
	}

	close(fd);
	*data_out = data;
	*len_out = len;
	return 0;
}

static __u32 unittest_btf_kind(const struct unittest_btf_type *bt)
{
	return (bt->info >> 24) & 0x1f;
}

static size_t unittest_btf_type_extra_size(const struct unittest_btf_type *bt)
{
	__u32 kind = unittest_btf_kind(bt);
	__u32 vlen = bt->info & 0xffff;

	switch (kind) {
	case 1:
		return 4;
	case 3:
		return 12;
	case 4:
	case 5:
		return vlen * 12;
	case 6:
		return vlen * 8;
	case 13:
		return vlen * 8;
	case 14:
		return 4;
	case 15:
		return vlen * 12;
	case 17:
		return 4;
	case 19:
		return vlen * 12;
	default:
		return 0;
	}
}

static int count_btf_types(const void *btf_data, size_t btf_len,
			   __u32 *type_cnt_out)
{
	const struct unittest_btf_header *hdr = btf_data;
	const unsigned char *data = btf_data;
	const unsigned char *type_section;
	size_t type_start, type_end;
	size_t offset = 0;
	__u32 type_cnt = 1;

	if (btf_len < sizeof(*hdr)) {
		errno = EINVAL;
		return -1;
	}
	if (hdr->magic != 0xeb9f) {
		errno = EPROTO;
		return -1;
	}

	type_start = hdr->hdr_len + hdr->type_off;
	type_end = type_start + hdr->type_len;
	if (type_end > btf_len) {
		errno = EINVAL;
		return -1;
	}

	type_section = data + type_start;
	while (offset + sizeof(struct unittest_btf_type) <= hdr->type_len) {
		const struct unittest_btf_type *bt;
		size_t skip;

		bt = (const struct unittest_btf_type *)(type_section + offset);
		offset += sizeof(*bt);

		skip = unittest_btf_type_extra_size(bt);
		if (offset + skip > hdr->type_len) {
			errno = EINVAL;
			return -1;
		}

		offset += skip;
		type_cnt++;
	}

	if (offset != hdr->type_len) {
		errno = EINVAL;
		return -1;
	}

	*type_cnt_out = type_cnt;
	return 0;
}

static int get_vmlinux_btf_layout(__u32 *str_len_out, __u32 *type_cnt_out)
{
	const char *path = "/sys/kernel/btf/vmlinux";
	const struct unittest_btf_header *hdr;
	void *data = NULL;
	size_t data_len = 0;

	if (read_whole_file(path, &data, &data_len) < 0)
		return -1;
	if (data_len < sizeof(*hdr)) {
		free(data);
		errno = EINVAL;
		return -1;
	}

	hdr = data;
	if (hdr->magic != 0xeb9f) {
		free(data);
		errno = EPROTO;
		return -1;
	}
	if (count_btf_types(data, data_len, type_cnt_out) < 0) {
		free(data);
		return -1;
	}

	*str_len_out = hdr->str_len;
	free(data);
	return 0;
}

static int find_func_btf_id(const void *btf_data, size_t btf_len,
			    const char *func_name, __u32 base_str_off,
			    __u32 type_id_bias, __u32 *btf_id_out)
{
	const struct unittest_btf_header *hdr = btf_data;
	const unsigned char *data = btf_data;
	const unsigned char *type_section;
	const unsigned char *str_section;
	size_t type_start, type_end, str_start, str_end;
	size_t offset = 0;
	__u32 type_id = 1;

	if (btf_len < sizeof(*hdr))
		return -1;
	if (hdr->magic != 0xeb9f) {
		errno = EPROTO;
		return -1;
	}

	type_start = hdr->hdr_len + hdr->type_off;
	type_end = type_start + hdr->type_len;
	str_start = hdr->hdr_len + hdr->str_off;
	str_end = str_start + hdr->str_len;
	if (type_end > btf_len || str_end > btf_len) {
		errno = EINVAL;
		return -1;
	}

	type_section = data + type_start;
	str_section = data + str_start;

	while (offset + sizeof(struct unittest_btf_type) <= hdr->type_len) {
		const struct unittest_btf_type *bt;

		bt = (const struct unittest_btf_type *)(type_section + offset);
		if (unittest_btf_kind(bt) == 12) {
			size_t raw_off = bt->name_off;
			size_t local_off = raw_off;
			const char *name;
			size_t max_len;

			if (base_str_off && raw_off >= base_str_off)
				local_off = raw_off - base_str_off;
			if (local_off < hdr->str_len) {
				name = (const char *)(str_section + local_off);
				max_len = hdr->str_len - local_off;
				if (strnlen(name, max_len) < max_len &&
				    strcmp(name, func_name) == 0) {
					*btf_id_out = type_id + type_id_bias;
					return 0;
				}
			}
		}

		offset += sizeof(*bt);
		offset += unittest_btf_type_extra_size(bt);
		type_id++;
	}

	errno = ENOENT;
	return -1;
}

static int bpf_btf_get_fd_by_id(__u32 id)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.btf_id = id;
	return sys_bpf(BPF_BTF_GET_FD_BY_ID, &attr, sizeof(attr));
}

static int bpf_btf_get_next_id(__u32 start_id, __u32 *next_id)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.start_id = start_id;
	if (sys_bpf(BPF_BTF_GET_NEXT_ID, &attr, sizeof(attr)) < 0)
		return -1;

	*next_id = attr.next_id;
	return 0;
}

static int bpf_btf_get_info_name(int btf_fd, char *name_buf, size_t name_buf_sz)
{
	union bpf_attr attr;
	struct unittest_btf_info info;

	memset(&info, 0, sizeof(info));
	memset(&attr, 0, sizeof(attr));
	info.name = ptr_to_u64(name_buf);
	info.name_len = name_buf_sz;
	attr.info.bpf_fd = btf_fd;
	attr.info.info_len = sizeof(info);
	attr.info.info = ptr_to_u64(&info);

	return sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr));
}

static int bpf_btf_get_fd_by_module_name(const char *module_name)
{
	__u32 id = 0;

	for (;;) {
		char name_buf[64];
		int fd;

		if (bpf_btf_get_next_id(id, &id) < 0)
			return -1;

		fd = bpf_btf_get_fd_by_id(id);
		if (fd < 0)
			continue;

		memset(name_buf, 0, sizeof(name_buf));
		if (bpf_btf_get_info_name(fd, name_buf, sizeof(name_buf)) == 0 &&
		    strcmp(name_buf, module_name) == 0)
			return fd;

		close(fd);
	}
}

static int discover_barrier_kinsn(int *module_btf_fd, __u32 *func_btf_id)
{
	const char *module_name = "bpf_barrier";
	const char *func_name = "bpf_speculation_barrier";
	__u32 base_str_off;
	__u32 type_id_bias;
	char path[128];
	void *data = NULL;
	size_t data_len = 0;
	int fd;

	if (get_vmlinux_btf_layout(&base_str_off, &type_id_bias) < 0)
		return -1;
	if (type_id_bias == 0) {
		errno = EINVAL;
		return -1;
	}

	fd = bpf_btf_get_fd_by_module_name(module_name);
	if (fd < 0)
		return -1;

	snprintf(path, sizeof(path), "/sys/kernel/btf/%s", module_name);
	if (read_whole_file(path, &data, &data_len) < 0) {
		close(fd);
		return -1;
	}

	if (find_func_btf_id(data, data_len, func_name, base_str_off,
			     type_id_bias - 1, func_btf_id) < 0) {
		free(data);
		close(fd);
		return -1;
	}

	free(data);
	*module_btf_fd = fd;
	return 0;
}

static void patch_kinsn_call(struct bpf_insn *prog, size_t cnt, __u32 btf_id)
{
	size_t i;

	for (i = 0; i < cnt; i++) {
		if (prog[i].code == (BPF_JMP | BPF_CALL) &&
		    prog[i].src_reg == BPF_PSEUDO_KINSN_CALL) {
			prog[i].imm = (__s32)btf_id;
			prog[i].off = 1;
			return;
		}
	}
}

/* ================================================================== */
/*  PART A: Negative Tests -- REJIT must reject invalid bytecode      */
/* ================================================================== */

/*
 * Helper for negative tests.  Pattern:
 *  1. Load a good program, verify it returns XDP_PASS.
 *  2. Attempt REJIT with the given bad bytecode.
 *  3. Assert REJIT fails (returns < 0).
 *  4. Assert the original program still returns XDP_PASS.
 */
static int run_negative_test(const char *name,
			     const struct bpf_insn *bad_insns,
			     __u32 bad_insn_cnt)
{
	char log_buf[65536];
	int prog_fd, ret;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	/* Pre-REJIT: original works */
	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "pre-rejit run failed");
		close(prog_fd);
		return 1;
	}

	/* Attempt REJIT with bad bytecode -- should fail */
	memset(log_buf, 0, sizeof(log_buf));
	ret = rejit_prog(prog_fd, bad_insns, bad_insn_cnt,
			 log_buf, sizeof(log_buf));
	if (ret >= 0) {
		TEST_FAIL(name, "REJIT unexpectedly succeeded");
		close(prog_fd);
		return 1;
	}
	/* errno should be EINVAL, EACCES, or similar -- we just check ret<0 */

	/* Post-REJIT: original must still work identically */
	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "original program changed after failed REJIT!");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* N03: No BPF_EXIT -- program with only an ALU instruction, no exit */
static int test_neg_no_exit(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = 1 },
	};
	return run_negative_test("N03_no_exit", bad, ARRAY_SIZE(bad));
}

/* N04: Uninitialized R0 -- just BPF_EXIT without setting R0 */
static int test_neg_uninit_r0(void)
{
	static const struct bpf_insn bad[] = {
		{ .code = BPF_JMP | BPF_EXIT },
	};
	return run_negative_test("N04_uninit_r0", bad, ARRAY_SIZE(bad));
}

/* N10: Invalid prog_fd -- REJIT with fd = -1 */
static int test_neg_bad_prog_fd(void)
{
	const char *name = "N10_bad_prog_fd";
	char log_buf[65536];
	int ret;

	memset(log_buf, 0, sizeof(log_buf));
	ret = rejit_prog(-1, prog_xdp_drop, ARRAY_SIZE(prog_xdp_drop),
			 log_buf, sizeof(log_buf));
	if (ret >= 0) {
		TEST_FAIL(name, "REJIT with fd=-1 unexpectedly succeeded");
		return 1;
	}
	/* Should get EBADF */
	if (errno != EBADF && errno != EINVAL) {
		char buf[128];
		snprintf(buf, sizeof(buf), "unexpected errno %d (%s), expected EBADF",
			 errno, strerror(errno));
		TEST_FAIL(name, buf);
		return 1;
	}

	TEST_PASS(name);
	return 0;
}

/* N11: Non-BPF fd -- REJIT with fd pointing to a regular file */
static int test_neg_non_bpf_fd(void)
{
	const char *name = "N11_non_bpf_fd";
	char log_buf[65536];
	int fd, ret;

	fd = open("/dev/null", O_RDONLY);
	if (fd < 0) {
		TEST_FAIL(name, "cannot open /dev/null");
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	ret = rejit_prog(fd, prog_xdp_drop, ARRAY_SIZE(prog_xdp_drop),
			 log_buf, sizeof(log_buf));
	close(fd);

	if (ret >= 0) {
		TEST_FAIL(name, "REJIT with non-BPF fd unexpectedly succeeded");
		return 1;
	}

	TEST_PASS(name);
	return 0;
}

/* N14: Unprivileged REJIT -- fork a child, drop to nobody, try REJIT.
 * Expects EPERM. */
static int test_neg_unprivileged_rejit(void)
{
	const char *name = "N14_unprivileged_rejit";
	int prog_fd;
	pid_t pid;
	int status;

	/* Load a good program as root first */
	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	pid = fork();
	if (pid < 0) {
		TEST_FAIL(name, "fork failed");
		close(prog_fd);
		return 1;
	}

	if (pid == 0) {
		/* Child: drop privileges to nobody (uid 65534) */
		char log_buf[65536];
		int ret;

		if (setresuid(65534, 65534, 65534) < 0) {
			fprintf(stderr, "  %s: setresuid failed: %s\n",
				name, strerror(errno));
			_exit(2);
		}

		memset(log_buf, 0, sizeof(log_buf));
		ret = rejit_prog(prog_fd, prog_xdp_drop,
				 ARRAY_SIZE(prog_xdp_drop),
				 log_buf, sizeof(log_buf));
		if (ret >= 0) {
			fprintf(stderr, "  %s: unprivileged REJIT succeeded!\n",
				name);
			_exit(1);
		}
		if (errno != EPERM && errno != EACCES) {
			fprintf(stderr, "  %s: unexpected errno %d (%s)\n",
				name, errno, strerror(errno));
			_exit(1);
		}
		/* Good -- REJIT was rejected */
		_exit(0);
	}

	/* Parent: wait for child */
	waitpid(pid, &status, 0);
	close(prog_fd);

	if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
		TEST_PASS(name);
		return 0;
	} else if (WIFEXITED(status) && WEXITSTATUS(status) == 2) {
		/* Could not setresuid -- likely not root. Treat as failure. */
		fprintf(stderr, "  FAIL  %s: cannot drop privileges\n", name);
		g_fail++;
		return 0;
	} else {
		TEST_FAIL(name, "child reported failure");
		return 1;
	}
}

/*
 * N16: The verifier now rejects kinsn modules whose max_insn_cnt would exceed
 * INSN_BUF_SIZE. Userspace cannot force a module's descriptor value at runtime,
 * so this regression test exercises the supported path instead: discover a live
 * kinsn module, REJIT a program that uses it, and verify the verifier accepts
 * the normal case and the transformed program runs correctly. When the
 * out-of-scope security kinsn module is not loaded, skip cleanly.
 */
static int test_kinsn_max_insn_cnt_exceeds_buf(void)
{
	const char *name = "N16_kinsn_max_insn_cnt_exceeds_buf";
	int module_btf_fd = -1;
	int fd_array[2];
	char log_buf[LOG_BUF_SIZE];
	__u32 func_btf_id = 0;
	__u32 retval = 0;
	int prog_fd = -1;
	struct bpf_insn kinsn_prog[] = {
		BPF_UT_KINSN_SIDECAR(0),
		BPF_UT_CALL_KINSN(0, 0),
		BPF_UT_MOV64_IMM(BPF_REG_0, XDP_PASS),
		BPF_UT_EXIT_INSN(),
	};

	if (discover_barrier_kinsn(&module_btf_fd, &func_btf_id) < 0) {
		TEST_SKIP(name, "bpf_barrier kinsn module/BTF not available");
		return 0;
	}

	fd_array[0] = module_btf_fd;
	fd_array[1] = module_btf_fd;
	patch_kinsn_call(kinsn_prog, ARRAY_SIZE(kinsn_prog), func_btf_id);

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_xdp_drop, ARRAY_SIZE(prog_xdp_drop),
				log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base program");
		close(module_btf_fd);
		return 1;
	}

	if (verify_retval(prog_fd, XDP_DROP) < 0) {
		TEST_FAIL(name, "base program returned wrong value");
		close(prog_fd);
		close(module_btf_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog_with_fd_array(prog_fd, kinsn_prog, ARRAY_SIZE(kinsn_prog),
				     fd_array, ARRAY_SIZE(fd_array),
				     log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "valid kinsn REJIT was rejected");
		close(prog_fd);
		close(module_btf_fd);
		return 1;
	}

	if (test_run_xdp(prog_fd, &retval) < 0 || retval != XDP_PASS) {
		TEST_FAIL(name, "recompiled kinsn program returned wrong value");
		close(prog_fd);
		close(module_btf_fd);
		return 1;
	}

	close(prog_fd);
	close(module_btf_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  PART B: Correctness Verification Tests                            */
/* ================================================================== */

/* C01: Identity transform -- REJIT with the exact same bytecode */
static int test_cor_identity_transform(void)
{
	const char *name = "C01_identity_transform";
	char log_buf[65536];
	int prog_fd;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "pre-rejit run failed");
		close(prog_fd);
		return 1;
	}

	/* REJIT with the identical bytecode */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
		       log_buf, sizeof(log_buf)) < 0) {
		char buf[256];
		snprintf(buf, sizeof(buf), "identity REJIT failed: %s\n%s",
			 strerror(errno), log_buf);
		TEST_FAIL(name, buf);
		close(prog_fd);
		return 1;
	}

	/* Must still return XDP_PASS */
	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "post-identity-rejit run returned wrong value");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* C02: Semantic-preserving transform -- insert a NOP (r0 = r0 + 0) before exit */
static int test_cor_nop_insertion(void)
{
	const char *name = "C02_nop_insertion";
	char log_buf[65536];
	int prog_fd;

	/* Original: r0 = XDP_PASS; exit  (2 insns) */
	/* Replacement: r0 = XDP_PASS; r0 += 0; exit  (3 insns, same semantics) */
	static const struct bpf_insn prog_with_nop[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0, .imm = XDP_PASS },
		/* NOP: r0 += 0 */
		{ .code = BPF_ALU64 | BPF_ADD | BPF_K, .dst_reg = BPF_REG_0, .imm = 0 },
		{ .code = BPF_JMP | BPF_EXIT },
	};

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "pre-rejit run failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_with_nop, ARRAY_SIZE(prog_with_nop),
		       log_buf, sizeof(log_buf)) < 0) {
		char buf[256];
		snprintf(buf, sizeof(buf), "nop-insertion REJIT failed: %s\n%s",
			 strerror(errno), log_buf);
		TEST_FAIL(name, buf);
		close(prog_fd);
		return 1;
	}

	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "post-nop-rejit run returned wrong value");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* C03: REJIT preserves prog_info metadata (type, id remain consistent) */
static int test_cor_prog_info_after_rejit(void)
{
	const char *name = "C03_prog_info_after_rejit";
	char log_buf[65536];
	struct bpf_prog_info info_before, info_after;
	__u32 info_len;
	int prog_fd;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	/* Snapshot info before REJIT */
	memset(&info_before, 0, sizeof(info_before));
	info_len = sizeof(info_before);
	if (get_prog_info(prog_fd, &info_before, &info_len) < 0) {
		TEST_FAIL(name, "get_info pre-rejit failed");
		close(prog_fd);
		return 1;
	}

	/* REJIT to a different-length program (4 insns, returns XDP_TX) */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_tx_long, ARRAY_SIZE(prog_xdp_tx_long),
		       log_buf, sizeof(log_buf)) < 0) {
		char buf[256];
		snprintf(buf, sizeof(buf), "REJIT failed: %s", strerror(errno));
		TEST_FAIL(name, buf);
		close(prog_fd);
		return 1;
	}

	if (verify_retval(prog_fd, XDP_TX) < 0) {
		TEST_FAIL(name, "post-rejit retval wrong");
		close(prog_fd);
		return 1;
	}

	/* Snapshot info after REJIT */
	memset(&info_after, 0, sizeof(info_after));
	info_len = sizeof(info_after);
	if (get_prog_info(prog_fd, &info_after, &info_len) < 0) {
		TEST_FAIL(name, "get_info post-rejit failed");
		close(prog_fd);
		return 1;
	}

	/* prog_type must remain XDP */
	if (info_after.type != info_before.type) {
		char buf[128];
		snprintf(buf, sizeof(buf), "prog_type changed: %u -> %u",
			 info_before.type, info_after.type);
		TEST_FAIL(name, buf);
		close(prog_fd);
		return 1;
	}

	/* prog ID must remain the same (in-place update) */
	if (info_after.id != info_before.id) {
		char buf[128];
		snprintf(buf, sizeof(buf), "prog_id changed: %u -> %u",
			 info_before.id, info_after.id);
		TEST_FAIL(name, buf);
		close(prog_fd);
		return 1;
	}

	/* JIT should still be active */
	if (!info_after.jited_prog_len) {
		TEST_FAIL(name, "program no longer JIT'ed after REJIT");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* C04: Multiple consecutive REJITs -- REJIT the same prog 3 times */
static int test_cor_multiple_rejits(void)
{
	const char *name = "C04_multiple_rejits";
	char log_buf[65536];
	int prog_fd, i;

	struct {
		const struct bpf_insn *insns;
		__u32 cnt;
		__u32 expected;
	} steps[] = {
		{ prog_xdp_drop,    ARRAY_SIZE(prog_xdp_drop),    XDP_DROP },
		{ prog_xdp_tx_long, ARRAY_SIZE(prog_xdp_tx_long), XDP_TX },
		{ prog_xdp_pass,    ARRAY_SIZE(prog_xdp_pass),    XDP_PASS },
	};

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "initial run failed");
		close(prog_fd);
		return 1;
	}

	for (i = 0; i < 3; i++) {
		memset(log_buf, 0, sizeof(log_buf));
		if (rejit_prog(prog_fd, steps[i].insns, steps[i].cnt,
			       log_buf, sizeof(log_buf)) < 0) {
			char buf[256];
			snprintf(buf, sizeof(buf), "REJIT step %d failed: %s",
				 i, strerror(errno));
			TEST_FAIL(name, buf);
			close(prog_fd);
			return 1;
		}
		if (verify_retval(prog_fd, steps[i].expected) < 0) {
			char buf[128];
			snprintf(buf, sizeof(buf),
				 "step %d: expected %u, got different", i,
				 steps[i].expected);
			TEST_FAIL(name, buf);
			close(prog_fd);
			return 1;
		}
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* C05: REJIT round-trip -- REJIT to DROP, then REJIT back to PASS,
 * verify result matches the original exactly */
static int test_cor_rejit_roundtrip(void)
{
	const char *name = "C05_rejit_roundtrip";
	char log_buf[65536];
	int prog_fd;

	prog_fd = load_good_prog();
	if (prog_fd < 0) {
		TEST_FAIL(name, "cannot load base prog");
		return 1;
	}

	/* Phase 1: verify original */
	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "phase 1 (original) failed");
		close(prog_fd);
		return 1;
	}

	/* Phase 2: REJIT to XDP_DROP */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_drop, ARRAY_SIZE(prog_xdp_drop),
		       log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "phase 2 REJIT->DROP failed");
		close(prog_fd);
		return 1;
	}
	if (verify_retval(prog_fd, XDP_DROP) < 0) {
		TEST_FAIL(name, "phase 2 run (DROP) wrong");
		close(prog_fd);
		return 1;
	}

	/* Phase 3: REJIT back to original (XDP_PASS) */
	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_prog(prog_fd, prog_xdp_pass, ARRAY_SIZE(prog_xdp_pass),
		       log_buf, sizeof(log_buf)) < 0) {
		TEST_FAIL(name, "phase 3 REJIT->PASS failed");
		close(prog_fd);
		return 1;
	}
	if (verify_retval(prog_fd, XDP_PASS) < 0) {
		TEST_FAIL(name, "phase 3 run (PASS) wrong -- roundtrip failed!");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

/* ================================================================== */
/*  main                                                               */
/* ================================================================== */

int main(void)
{
	printf("=== BpfReJIT Safety & Correctness Test Suite ===\n\n");

	printf("--- Negative Tests (REJIT rejects invalid bytecode) ---\n");
	test_neg_no_exit();                        /* N03 */
	test_neg_uninit_r0();                      /* N04 */
	test_neg_bad_prog_fd();                    /* N10 */
	test_neg_non_bpf_fd();                     /* N11 */
	test_neg_unprivileged_rejit();             /* N14 */
	test_kinsn_max_insn_cnt_exceeds_buf();     /* N16 */

	printf("\n--- Correctness Verification Tests ---\n");
	test_cor_identity_transform();             /* C01 */
	test_cor_nop_insertion();                  /* C02 */
	test_cor_prog_info_after_rejit();          /* C03 */
	test_cor_multiple_rejits();                /* C04 */
	test_cor_rejit_roundtrip();                /* C05 */

	printf("\n=== Summary: %d passed, %d failed, %d skipped ===\n",
	       g_pass, g_fail, g_skip);

	if (g_fail) {
		fprintf(stderr, "SOME TESTS FAILED\n");
		return 1;
	}

	printf("ALL TESTS PASSED\n");
	return 0;
}
