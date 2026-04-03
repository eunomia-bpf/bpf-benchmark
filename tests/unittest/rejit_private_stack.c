// SPDX-License-Identifier: GPL-2.0
#define _GNU_SOURCE

#include <errno.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define LOG_BUF_SIZE 65536
#define ptr_to_u64(ptr) ((__u64)(uintptr_t)(ptr))

static int g_pass;
static int g_fail;
static int g_skip;

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
}

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", (name)); \
	g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s (errno=%d: %s)\n", \
		(name), (reason), errno, strerror(errno)); \
	g_fail++; \
} while (0)

#define TEST_SKIP(name, reason) do { \
	printf("  SKIP  %s: %s\n", (name), (reason)); \
	g_skip++; \
} while (0)

#define BPF_RAW_INSN(CODE, DST, SRC, OFF, IMM) ((struct bpf_insn) { \
	.code = (CODE), \
	.dst_reg = (DST), \
	.src_reg = (SRC), \
	.off = (OFF), \
	.imm = (IMM), \
})

#define BPF_EXIT_INSN() \
	BPF_RAW_INSN(BPF_JMP | BPF_EXIT, 0, 0, 0, 0)

#define BPF_MOV64_IMM(DST, IMM) \
	BPF_RAW_INSN(BPF_ALU64 | BPF_MOV | BPF_K, DST, 0, 0, IMM)

#define BPF_STX_MEM(SIZE, DST, SRC, OFF) \
	BPF_RAW_INSN(BPF_STX | BPF_SIZE(SIZE) | BPF_MEM, DST, SRC, OFF, 0)

static int load_prog(__u32 prog_type, const struct bpf_insn *insns,
		     __u32 insn_cnt, char *log_buf, size_t log_buf_sz)
{
	static const char license[] = "GPL";
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.prog_type = prog_type;
	attr.insn_cnt = insn_cnt;
	attr.insns = ptr_to_u64(insns);
	attr.license = ptr_to_u64(license);
	attr.log_level = 1;
	attr.log_buf = ptr_to_u64(log_buf);
	attr.log_size = log_buf_sz;

	return sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
}

static int get_prog_info(int prog_fd, struct bpf_prog_info *info,
			 __u32 *info_len)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.info.bpf_fd = prog_fd;
	attr.info.info = ptr_to_u64(info);
	attr.info.info_len = *info_len;
	if (sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) < 0)
		return -1;

	*info_len = attr.info.info_len;
	return 0;
}

static int get_jited_program(int prog_fd, __u8 **buf, __u32 *len)
{
	struct bpf_prog_info info;
	__u32 info_len;
	__u32 jited_len;

	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (get_prog_info(prog_fd, &info, &info_len) < 0)
		return -1;

	if (!info.jited_prog_len) {
		errno = ENODATA;
		return -1;
	}

	jited_len = info.jited_prog_len;
	*buf = calloc(jited_len, 1);
	if (!*buf)
		return -1;

	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	info.jited_prog_len = jited_len;
	info.jited_prog_insns = ptr_to_u64(*buf);
	if (get_prog_info(prog_fd, &info, &info_len) < 0) {
		free(*buf);
		*buf = NULL;
		return -1;
	}

	*len = info.jited_prog_len;
	return 0;
}

static bool find_bytes(const __u8 *haystack, __u32 haystack_len,
		       const __u8 *needle, __u32 needle_len)
{
	__u32 i;

	if (!needle_len || haystack_len < needle_len)
		return false;

	for (i = 0; i <= haystack_len - needle_len; i++) {
		if (!memcmp(haystack + i, needle, needle_len))
			return true;
	}

	return false;
}

static int test_kprobe_private_stack_store_uses_r9(void)
{
#if defined(__x86_64__)
	static const __u8 private_stack_store[] = {
		0x49, 0x89, 0xb9, 0x00, 0xff, 0xff, 0xff,
	};
	const char *name = "kprobe_private_stack_store_uses_r9";
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_1, 42),
		BPF_STX_MEM(BPF_DW, BPF_REG_10, BPF_REG_1, -256),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};
	char log_buf[LOG_BUF_SIZE];
	__u8 *jited = NULL;
	__u32 jited_len = 0;
	int prog_fd;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_prog(BPF_PROG_TYPE_KPROBE, prog, ARRAY_SIZE(prog),
			    log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_SKIP(name, "kprobe load failed");
		return 0;
	}

	if (get_jited_program(prog_fd, &jited, &jited_len) < 0) {
		TEST_FAIL(name, "failed to fetch JIT image");
		close(prog_fd);
		return 1;
	}

	if (!find_bytes(jited, jited_len, private_stack_store,
			sizeof(private_stack_store))) {
		fprintf(stderr, "    verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "private stack store via r9 not found");
		free(jited);
		close(prog_fd);
		return 1;
	}

	free(jited);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
#else
	TEST_SKIP("kprobe_private_stack_store_uses_r9", "x86_64 only");
	return 0;
#endif
}

int main(void)
{
	int ret = 0;

	ret |= test_kprobe_private_stack_store_uses_r9();

	printf("\nSummary: %d passed, %d failed, %d skipped\n",
	       g_pass, g_fail, g_skip);
	return ret ? 1 : 0;
}
