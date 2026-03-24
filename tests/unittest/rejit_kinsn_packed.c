// SPDX-License-Identifier: GPL-2.0
/*
 * REJIT kinsn packed-ABI test suite.
 *
 * Covers:
 *   - sidecar + CALL pair verifier acceptance
 *   - packed operand decode/JIT consumption for rotate/select/endian/barrier
 *   - packed extract range narrowing for bounded dynamic stack access
 */
#define _GNU_SOURCE

#include <errno.h>
#include <fcntl.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <unistd.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define LOG_BUF_SIZE 65536
#define ptr_to_u64(ptr) ((__u64)(uintptr_t)(ptr))

enum kinsn_module_id {
	MOD_ROTATE,
	MOD_SELECT,
	MOD_EXTRACT,
	MOD_ENDIAN,
	MOD_BARRIER,
	MOD_CNT,
};

enum kinsn_func_id {
	FUNC_ROTATE,
	FUNC_SELECT,
	FUNC_EXTRACT,
	FUNC_ENDIAN16,
	FUNC_BARRIER,
	FUNC_CNT,
};

struct kinsn_module_ref {
	const char *module_name;
	int btf_fd;
};

struct kinsn_func_ref {
	const char *desc_name;
	enum kinsn_module_id module_id;
	__u32 btf_id;
};

struct btf_header {
	__u16 magic;
	__u8 version;
	__u8 flags;
	__u32 hdr_len;
	__u32 type_off;
	__u32 type_len;
	__u32 str_off;
	__u32 str_len;
};

struct btf_type {
	__u32 name_off;
	__u32 info;
	__u32 size_or_type;
};

struct btf_info {
	__u64 btf;
	__u32 btf_size;
	__u32 id;
	__u64 name;
	__u32 name_len;
	__u32 kernel_btf;
	__u8 pad[96];
};

static int g_pass;
static int g_fail;
static int g_skip;
static bool g_discovered;

static struct kinsn_module_ref g_modules[MOD_CNT] = {
	[MOD_ROTATE] = { .module_name = "bpf_rotate", .btf_fd = -1 },
	[MOD_SELECT] = { .module_name = "bpf_select", .btf_fd = -1 },
	[MOD_EXTRACT] = { .module_name = "bpf_extract", .btf_fd = -1 },
	[MOD_ENDIAN] = { .module_name = "bpf_endian", .btf_fd = -1 },
	[MOD_BARRIER] = { .module_name = "bpf_barrier", .btf_fd = -1 },
};

static struct kinsn_func_ref g_funcs[FUNC_CNT] = {
	[FUNC_ROTATE] = {
		.desc_name = "bpf_rotate64_desc",
		.module_id = MOD_ROTATE,
	},
	[FUNC_SELECT] = {
		.desc_name = "bpf_select64_desc",
		.module_id = MOD_SELECT,
	},
	[FUNC_EXTRACT] = {
		.desc_name = "bpf_extract64_desc",
		.module_id = MOD_EXTRACT,
	},
	[FUNC_ENDIAN16] = {
		.desc_name = "bpf_endian_load16_desc",
		.module_id = MOD_ENDIAN,
	},
	[FUNC_BARRIER] = {
		.desc_name = "bpf_speculation_barrier_desc",
		.module_id = MOD_BARRIER,
	},
};

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

#define BPF_MOV64_REG(DST, SRC) \
	BPF_RAW_INSN(BPF_ALU64 | BPF_MOV | BPF_X, DST, SRC, 0, 0)

#define BPF_ALU64_IMM(OP, DST, IMM) \
	BPF_RAW_INSN(BPF_ALU64 | BPF_OP(OP) | BPF_K, DST, 0, 0, IMM)

#define BPF_ALU64_REG(OP, DST, SRC) \
	BPF_RAW_INSN(BPF_ALU64 | BPF_OP(OP) | BPF_X, DST, SRC, 0, 0)

#define BPF_ST_MEM(SIZE, DST, OFF, IMM) \
	BPF_RAW_INSN(BPF_ST | BPF_SIZE(SIZE) | BPF_MEM, DST, 0, OFF, IMM)

#define BPF_CALL_KINSN(OFF, IMM) \
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, BPF_PSEUDO_KINSN_CALL, OFF, IMM)

#define BPF_KINSN_SIDECAR(PAYLOAD) \
	BPF_RAW_INSN(BPF_ALU64 | BPF_MOV | BPF_K, \
		     (__u8)((__u64)(PAYLOAD) & 0xf), \
		     BPF_PSEUDO_KINSN_SIDECAR, \
		     (__s16)(((__u64)(PAYLOAD) >> 4) & 0xffff), \
		     (__s32)(((__u64)(PAYLOAD) >> 20) & 0xffffffffU))

#define MODULE_FD_ARRAY(FD) { (FD), (FD) }

#define KINSN_ROTATE_PAYLOAD(DST, SRC, SHIFT, TMP) \
	((__u64)(DST) | ((__u64)(SRC) << 4) | ((__u64)(SHIFT) << 8) | \
	 ((__u64)(TMP) << 16))

#define KINSN_SELECT_PAYLOAD(DST, TRUE_REG, FALSE_REG, COND_REG) \
	((__u64)(DST) | ((__u64)(TRUE_REG) << 4) | ((__u64)(FALSE_REG) << 8) | \
	 ((__u64)(COND_REG) << 12))

#define KINSN_EXTRACT_PAYLOAD(DST, START, LEN) \
	((__u64)(DST) | ((__u64)(START) << 8) | ((__u64)(LEN) << 16))

#define KINSN_ENDIAN_PAYLOAD(DST, BASE) \
	((__u64)(DST) | ((__u64)(BASE) << 4))

static const struct bpf_insn prog_ret_0[] = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
};

static int load_xdp_prog(const struct bpf_insn *insns, __u32 insn_cnt,
			 const int *fd_array, __u32 fd_array_cnt,
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
	if (fd_array && fd_array_cnt) {
		attr.fd_array = ptr_to_u64(fd_array);
		attr.fd_array_cnt = fd_array_cnt;
	}

	return sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
}

static int rejit_xdp_prog(int prog_fd, const struct bpf_insn *insns,
			  __u32 insn_cnt, const int *fd_array,
			  __u32 fd_array_cnt, char *log_buf,
			  size_t log_buf_sz)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd = prog_fd;
	attr.rejit.insn_cnt = insn_cnt;
	attr.rejit.insns = ptr_to_u64(insns);
	attr.rejit.log_level = 1;
	attr.rejit.log_buf = ptr_to_u64(log_buf);
	attr.rejit.log_size = log_buf_sz;
	if (fd_array && fd_array_cnt) {
		attr.rejit.fd_array = ptr_to_u64(fd_array);
		attr.rejit.fd_array_cnt = fd_array_cnt;
	}

	return sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
}

static int test_run_xdp(int prog_fd, __u32 *retval)
{
	unsigned char data[64] = {};
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.test.prog_fd = prog_fd;
	attr.test.data_in = ptr_to_u64(data);
	attr.test.data_size_in = sizeof(data);
	attr.test.repeat = 1;

	if (sys_bpf(BPF_PROG_TEST_RUN, &attr, sizeof(attr)) < 0)
		return -1;

	*retval = attr.test.retval;
	return 0;
}

static int read_file(const char *path, void **data_out, size_t *len_out)
{
	struct stat st;
	void *data;
	int fd;
	size_t cap, len = 0;

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
			void *new_data = realloc(data, new_cap);

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

static __u32 btf_kind(const struct btf_type *bt)
{
	return (bt->info >> 24) & 0x1f;
}

static size_t btf_type_extra_size(const struct btf_type *bt)
{
	__u32 kind = btf_kind(bt);
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
	const struct btf_header *hdr = btf_data;
	const unsigned char *data = btf_data;
	const unsigned char *type_section;
	size_t hdr_len, type_start, type_end;
	size_t offset = 0;
	__u32 type_cnt = 1;

	if (btf_len < sizeof(*hdr) || hdr->magic != 0xeb9f) {
		errno = EINVAL;
		return -1;
	}

	hdr_len = hdr->hdr_len;
	type_start = hdr_len + hdr->type_off;
	type_end = type_start + hdr->type_len;
	if (type_end > btf_len) {
		errno = EINVAL;
		return -1;
	}

	type_section = data + type_start;
	while (offset + sizeof(struct btf_type) <= hdr->type_len) {
		const struct btf_type *bt;
		size_t skip;

		bt = (const struct btf_type *)(type_section + offset);
		offset += sizeof(struct btf_type);
		skip = btf_type_extra_size(bt);
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
	void *data = NULL;
	size_t data_len = 0;
	const struct btf_header *hdr;

	if (read_file("/sys/kernel/btf/vmlinux", &data, &data_len) < 0)
		return -1;
	if (data_len < sizeof(*hdr)) {
		free(data);
		errno = EINVAL;
		return -1;
	}

	hdr = data;
	if (hdr->magic != 0xeb9f) {
		free(data);
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

static int find_var_btf_id(const void *btf_data, size_t btf_len,
			   const char *desc_name, __u32 base_str_off,
			   __u32 type_id_bias, __u32 *btf_id_out)
{
	const struct btf_header *hdr = btf_data;
	const unsigned char *data = btf_data;
	const unsigned char *type_section;
	const unsigned char *str_section;
	size_t hdr_len, type_start, type_end, str_start, str_end;
	size_t offset = 0;
	__u32 type_id = 1;

	if (btf_len < sizeof(*hdr) || hdr->magic != 0xeb9f)
		return -1;

	hdr_len = hdr->hdr_len;
	type_start = hdr_len + hdr->type_off;
	type_end = type_start + hdr->type_len;
	str_start = hdr_len + hdr->str_off;
	str_end = str_start + hdr->str_len;
	if (type_end > btf_len || str_end > btf_len) {
		errno = EINVAL;
		return -1;
	}

	type_section = data + type_start;
	str_section = data + str_start;

	while (offset + sizeof(struct btf_type) <= hdr->type_len) {
		const struct btf_type *bt = (const struct btf_type *)(type_section + offset);

		if (btf_kind(bt) == 14) {
			size_t raw_off = bt->name_off;
			size_t local_off = raw_off;

			if (base_str_off && raw_off >= base_str_off)
				local_off = raw_off - base_str_off;
			if (local_off < hdr->str_len) {
				const char *name = (const char *)(str_section + local_off);
				size_t max_len = hdr->str_len - local_off;

				if (strnlen(name, max_len) < max_len &&
				    strcmp(name, desc_name) == 0) {
					*btf_id_out = type_id + type_id_bias;
					return 0;
				}
			}
		}

		offset += sizeof(struct btf_type);
		offset += btf_type_extra_size(bt);
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
	struct btf_info info;

	memset(&info, 0, sizeof(info));
	memset(&attr, 0, sizeof(attr));

	info.name = ptr_to_u64(name_buf);
	info.name_len = name_buf_sz;
	attr.info.bpf_fd = btf_fd;
	attr.info.info_len = sizeof(info);
	attr.info.info = ptr_to_u64(&info);

	if (sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) < 0)
		return -1;

	return 0;
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

static int discover_kinsns(void)
{
	__u32 base_str_off;
	__u32 type_id_bias;
	size_t i;

	if (g_discovered)
		return 0;
	if (get_vmlinux_btf_layout(&base_str_off, &type_id_bias) < 0)
		return -1;
	if (type_id_bias == 0) {
		errno = EINVAL;
		return -1;
	}
	type_id_bias--;

	for (i = 0; i < ARRAY_SIZE(g_modules); i++) {
		g_modules[i].btf_fd =
			bpf_btf_get_fd_by_module_name(g_modules[i].module_name);
		if (g_modules[i].btf_fd < 0)
			return -1;
	}

	for (i = 0; i < ARRAY_SIZE(g_funcs); i++) {
		char path[128];
		void *data = NULL;
		size_t data_len = 0;

		snprintf(path, sizeof(path), "/sys/kernel/btf/%s",
			 g_modules[g_funcs[i].module_id].module_name);
		if (read_file(path, &data, &data_len) < 0)
			return -1;
		if (find_var_btf_id(data, data_len, g_funcs[i].desc_name,
				    base_str_off, type_id_bias,
				    &g_funcs[i].btf_id) < 0) {
			free(data);
			return -1;
		}
		free(data);
	}

	g_discovered = true;
	return 0;
}

static void cleanup_discovery(void)
{
	size_t i;

	for (i = 0; i < ARRAY_SIZE(g_modules); i++) {
		if (g_modules[i].btf_fd >= 0) {
			close(g_modules[i].btf_fd);
			g_modules[i].btf_fd = -1;
		}
	}
}

static void patch_single_kinsn(struct bpf_insn *prog, size_t cnt, __u32 btf_id)
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

static int run_rejit_expect_success(const char *name,
				    const struct bpf_insn *replacement,
				    __u32 replacement_cnt,
				    const int *fd_array, __u32 fd_array_cnt,
				    __u32 expected_retval)
{
	char log_buf[LOG_BUF_SIZE];
	__u32 retval = 0;
	int prog_fd;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_ret_0, ARRAY_SIZE(prog_ret_0),
				NULL, 0, log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "base load failed");
		return 1;
	}

	if (test_run_xdp(prog_fd, &retval) < 0 || retval != 0) {
		TEST_FAIL(name, "base program run failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_xdp_prog(prog_fd, replacement, replacement_cnt, fd_array,
			   fd_array_cnt, log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT failed");
		close(prog_fd);
		return 1;
	}

	if (test_run_xdp(prog_fd, &retval) < 0 || retval != expected_retval) {
		char msg[128];

		snprintf(msg, sizeof(msg), "retval=%u expected=%u",
			 retval, expected_retval);
		TEST_FAIL(name, msg);
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

static int test_kinsn_discovery(void)
{
	const char *name = "packed_kinsn_discovery";
	size_t i;

	if (discover_kinsns() < 0) {
		TEST_FAIL(name, "failed to discover packed kinsn modules");
		return 1;
	}

	for (i = 0; i < ARRAY_SIZE(g_funcs); i++) {
		if (g_funcs[i].btf_id == 0 ||
		    g_modules[g_funcs[i].module_id].btf_fd < 0) {
			TEST_FAIL(name, "missing packed kinsn BTF ID or module BTF FD");
			return 1;
		}
	}

	TEST_PASS(name);
	return 0;
}

static int test_packed_rotate_apply(void)
{
	int fd_array[2] = MODULE_FD_ARRAY(g_modules[MOD_ROTATE].btf_fd);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_6, 1),
		BPF_KINSN_SIDECAR(KINSN_ROTATE_PAYLOAD(BPF_REG_7, BPF_REG_6, 1, BPF_REG_8)),
		BPF_CALL_KINSN(0, 0),
		BPF_MOV64_REG(BPF_REG_0, BPF_REG_7),
		BPF_EXIT_INSN(),
	};

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_ROTATE].btf_id);
	return run_rejit_expect_success("packed_rotate_apply",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array), 2);
}

static int test_packed_select_apply(void)
{
	int fd_array[2] = MODULE_FD_ARRAY(g_modules[MOD_SELECT].btf_fd);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_1, 11),
		BPF_MOV64_IMM(BPF_REG_2, 29),
		BPF_MOV64_IMM(BPF_REG_3, 1),
		BPF_KINSN_SIDECAR(KINSN_SELECT_PAYLOAD(BPF_REG_5, BPF_REG_1,
						       BPF_REG_2, BPF_REG_3)),
		BPF_CALL_KINSN(0, 0),
		BPF_MOV64_REG(BPF_REG_0, BPF_REG_5),
		BPF_EXIT_INSN(),
	};

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_SELECT].btf_id);
	return run_rejit_expect_success("packed_select_apply",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array), 11);
}

static int test_packed_endian_apply(void)
{
	int fd_array[2] = MODULE_FD_ARRAY(g_modules[MOD_ENDIAN].btf_fd);
	struct bpf_insn prog[] = {
		BPF_ST_MEM(BPF_H, BPF_REG_10, -2, 0x1234),
		BPF_MOV64_REG(BPF_REG_6, BPF_REG_10),
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_6, -2),
		BPF_KINSN_SIDECAR(KINSN_ENDIAN_PAYLOAD(BPF_REG_7, BPF_REG_6)),
		BPF_CALL_KINSN(0, 0),
		BPF_MOV64_REG(BPF_REG_0, BPF_REG_7),
		BPF_EXIT_INSN(),
	};

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_ENDIAN16].btf_id);
	return run_rejit_expect_success("packed_endian_apply",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array), 0x3412);
}

static int test_packed_barrier_preserves_r5(void)
{
	int fd_array[2] = MODULE_FD_ARRAY(g_modules[MOD_BARRIER].btf_fd);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_5, 7),
		BPF_KINSN_SIDECAR(0),
		BPF_CALL_KINSN(0, 0),
		BPF_MOV64_REG(BPF_REG_0, BPF_REG_5),
		BPF_EXIT_INSN(),
	};

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_BARRIER].btf_id);
	return run_rejit_expect_success("packed_barrier_preserves_r5",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array), 7);
}

static int test_packed_extract_range_narrowing(void)
{
	int fd_array[2] = MODULE_FD_ARRAY(g_modules[MOD_EXTRACT].btf_fd);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_2, 0xabcd),
		BPF_KINSN_SIDECAR(KINSN_EXTRACT_PAYLOAD(BPF_REG_2, 0, 8)),
		BPF_CALL_KINSN(0, 0),
		BPF_MOV64_REG(BPF_REG_1, BPF_REG_10),
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_1, -256),
		BPF_ALU64_REG(BPF_ADD, BPF_REG_1, BPF_REG_2),
		BPF_ST_MEM(BPF_B, BPF_REG_1, 0, 1),
		BPF_MOV64_IMM(BPF_REG_0, XDP_PASS),
		BPF_EXIT_INSN(),
	};

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_EXTRACT].btf_id);
	return run_rejit_expect_success("packed_extract_range_narrowing",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array),
					XDP_PASS);
}

static bool should_run_test(const char *filter, const char *name)
{
	return !filter || strcmp(filter, name) == 0;
}

int main(int argc, char **argv)
{
	const char *filter = NULL;
	int ret = 0;

	if (argc > 1 && !strchr(argv[1], '/'))
		filter = argv[1];

	printf("[kinsn-packed] sidecar and packed operand ABI tests\n");

	if (should_run_test(filter, "packed_kinsn_discovery"))
		ret |= test_kinsn_discovery();
	if (should_run_test(filter, "packed_rotate_apply"))
		ret |= test_packed_rotate_apply();
	if (should_run_test(filter, "packed_select_apply"))
		ret |= test_packed_select_apply();
	if (should_run_test(filter, "packed_endian_apply"))
		ret |= test_packed_endian_apply();
	if (should_run_test(filter, "packed_barrier_preserves_r5"))
		ret |= test_packed_barrier_preserves_r5();
	if (should_run_test(filter, "packed_extract_range_narrowing"))
		ret |= test_packed_extract_range_narrowing();

	printf("\nSummary: %d passed, %d failed, %d skipped\n",
	       g_pass, g_fail, g_skip);
	cleanup_discovery();
	return ret || g_fail ? 1 : 0;
}
