// SPDX-License-Identifier: GPL-2.0
/*
 * REJIT kinsn test suite.
 *
 * Covers:
 *   - kinsn function discovery via BTF transport
 *   - REJIT correctness for rotate/select/endian/bulk-memory/LDP
 *   - packed sidecar semantics on arbitrary architectural registers
 *   - x86 native emit byte-pattern coverage for rotate and bulk memory
 *   - x86 rotate clobber behavior (r5 preserved, r4 rejected)
 *   - endian memory-effect validation
 *   - bulk memcpy/memset behavior, length, and stack-boundary coverage
 *   - arm64 LDP/STP pair-load/store behavior and payload validation
 *   - extract range narrowing enabling bounded dynamic stack access
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

#if defined(__aarch64__)
#define ARM64_KINSN_MODULE_REQUIRED true
#else
#define ARM64_KINSN_MODULE_REQUIRED false
#endif

enum kinsn_module_id {
	MOD_ROTATE,
	MOD_SELECT,
	MOD_EXTRACT,
	MOD_ENDIAN,
	MOD_BULK_MEMORY,
	MOD_LDP,
	MOD_CNT,
};

enum kinsn_func_id {
	FUNC_ROTATE,
	FUNC_SELECT,
	FUNC_EXTRACT,
	FUNC_ENDIAN16,
	FUNC_ENDIAN32,
	FUNC_ENDIAN64,
	FUNC_MEMCPY_BULK,
	FUNC_MEMSET_BULK,
	FUNC_LDP128,
	FUNC_STP128,
	FUNC_CNT,
};

struct kinsn_module_ref {
	const char *module_name;
	int btf_fd;
	bool required;
	bool available;
};

struct kinsn_func_ref {
	const char *func_name;
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
	[MOD_ROTATE] = {
		.module_name = "bpf_rotate",
		.btf_fd = -1,
		.required = true,
	},
	[MOD_SELECT] = {
		.module_name = "bpf_select",
		.btf_fd = -1,
		.required = true,
	},
	[MOD_EXTRACT] = {
		.module_name = "bpf_extract",
		.btf_fd = -1,
		.required = true,
	},
	[MOD_ENDIAN] = {
		.module_name = "bpf_endian",
		.btf_fd = -1,
		.required = true,
	},
	[MOD_BULK_MEMORY] = {
		.module_name = "bpf_bulk_memory",
		.btf_fd = -1,
		.required = true,
	},
	[MOD_LDP] = {
		.module_name = "bpf_ldp",
		.btf_fd = -1,
		.required = ARM64_KINSN_MODULE_REQUIRED,
	},
};

static struct kinsn_func_ref g_funcs[FUNC_CNT] = {
	[FUNC_ROTATE] = {
		.func_name = "bpf_rotate64",
		.module_id = MOD_ROTATE,
	},
	[FUNC_SELECT] = {
		.func_name = "bpf_select64",
		.module_id = MOD_SELECT,
	},
	[FUNC_EXTRACT] = {
		.func_name = "bpf_extract64",
		.module_id = MOD_EXTRACT,
	},
	[FUNC_ENDIAN16] = {
		.func_name = "bpf_endian_load16",
		.module_id = MOD_ENDIAN,
	},
	[FUNC_ENDIAN32] = {
		.func_name = "bpf_endian_load32",
		.module_id = MOD_ENDIAN,
	},
	[FUNC_ENDIAN64] = {
		.func_name = "bpf_endian_load64",
		.module_id = MOD_ENDIAN,
	},
	[FUNC_MEMCPY_BULK] = {
		.func_name = "bpf_memcpy_bulk",
		.module_id = MOD_BULK_MEMORY,
	},
	[FUNC_MEMSET_BULK] = {
		.func_name = "bpf_memset_bulk",
		.module_id = MOD_BULK_MEMORY,
	},
	[FUNC_LDP128] = {
		.func_name = "bpf_ldp128",
		.module_id = MOD_LDP,
	},
	[FUNC_STP128] = {
		.func_name = "bpf_stp128",
		.module_id = MOD_LDP,
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

#define BPF_LD_IMM64_RAW(DST, IMM) \
	BPF_RAW_INSN(BPF_LD | BPF_DW | BPF_IMM, DST, 0, 0, \
		     (__s32)((__u64)(IMM) & 0xffffffffULL)), \
	BPF_RAW_INSN(0, 0, 0, 0, \
		     (__s32)(((__u64)(IMM) >> 32) & 0xffffffffULL))

#define BPF_ALU64_IMM(OP, DST, IMM) \
	BPF_RAW_INSN(BPF_ALU64 | BPF_OP(OP) | BPF_K, DST, 0, 0, IMM)

#define BPF_ALU64_REG(OP, DST, SRC) \
	BPF_RAW_INSN(BPF_ALU64 | BPF_OP(OP) | BPF_X, DST, SRC, 0, 0)

#define BPF_LDX_MEM(SIZE, DST, SRC, OFF) \
	BPF_RAW_INSN(BPF_LDX | BPF_SIZE(SIZE) | BPF_MEM, DST, SRC, OFF, 0)

#define BPF_ST_MEM(SIZE, DST, OFF, IMM) \
	BPF_RAW_INSN(BPF_ST | BPF_SIZE(SIZE) | BPF_MEM, DST, 0, OFF, IMM)

#define BPF_STX_MEM(SIZE, DST, SRC, OFF) \
	BPF_RAW_INSN(BPF_STX | BPF_SIZE(SIZE) | BPF_MEM, DST, SRC, OFF, 0)

#define BPF_JMP_IMM(OP, DST, IMM, OFF) \
	BPF_RAW_INSN(BPF_JMP | BPF_OP(OP) | BPF_K, DST, 0, OFF, IMM)

#define BPF_JMP_REG(OP, DST, SRC, OFF) \
	BPF_RAW_INSN(BPF_JMP | BPF_OP(OP) | BPF_X, DST, SRC, OFF, 0)

#define BPF_CALL_KINSN(OFF, IMM) \
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, BPF_PSEUDO_KINSN_CALL, OFF, IMM)

#define BPF_KINSN_SIDECAR(PAYLOAD) \
	BPF_RAW_INSN(BPF_ALU64 | BPF_MOV | BPF_K, \
		     (__u8)((__u64)(PAYLOAD) & 0xf), \
		     BPF_PSEUDO_KINSN_SIDECAR, \
		     (__s16)(((__u64)(PAYLOAD) >> 4) & 0xffff), \
		     (__s32)(((__u64)(PAYLOAD) >> 20) & 0xffffffffU))

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

#define BPF_EXPECT_EQ_IMM(REG, IMM, RETVAL) \
	BPF_JMP_IMM(BPF_JEQ, REG, IMM, 2), \
	BPF_MOV64_IMM(BPF_REG_0, RETVAL), \
	BPF_EXIT_INSN()

#define BPF_EXPECT_EQ_REG(REG, SRC, RETVAL) \
	BPF_JMP_REG(BPF_JEQ, REG, SRC, 2), \
	BPF_MOV64_IMM(BPF_REG_0, RETVAL), \
	BPF_EXIT_INSN()

#define BTF_FD_ARRAY(FD) { (FD), (FD) }

static const struct bpf_insn prog_ret_0[] = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
};

static const struct bpf_insn prog_ret_1[] = {
	BPF_MOV64_IMM(BPF_REG_0, 1),
	BPF_EXIT_INSN(),
};

static __u64 bulk_width_class(__u8 width)
{
	switch (width) {
	case BPF_B:
		return 0;
	case BPF_H:
		return 1;
	case BPF_W:
		return 2;
	case BPF_DW:
		return 3;
	default:
		return 0xf;
	}
}

static __u64 pack_bulk_memcpy_payload_len_field(__u8 dst_base, __u8 src_base,
						__s16 dst_off, __s16 src_off,
						__u8 len_field, __u8 tmp_reg)
{
	return (__u64)dst_base |
	       ((__u64)src_base << 4) |
	       ((__u64)(__u16)dst_off << 8) |
	       ((__u64)(__u16)src_off << 24) |
	       ((__u64)len_field << 40) |
	       ((__u64)tmp_reg << 48);
}

static __u64 pack_bulk_memcpy_payload(__u8 dst_base, __u8 src_base,
				      __s16 dst_off, __s16 src_off,
				      __u8 len, __u8 tmp_reg)
{
	return pack_bulk_memcpy_payload_len_field(dst_base, src_base, dst_off,
						  src_off, len - 1, tmp_reg);
}

static __u64 pack_bulk_memset_payload_len_field(__u8 dst_base, __u8 val_reg,
						__s16 dst_off, __u8 len_field,
						__u8 width, bool value_from_reg,
						bool zero_fill, __u8 fill_imm8)
{
	return (__u64)dst_base |
	       ((__u64)val_reg << 4) |
	       ((__u64)(__u16)dst_off << 8) |
	       ((__u64)len_field << 24) |
	       (bulk_width_class(width) << 32) |
	       ((__u64)value_from_reg << 34) |
	       ((__u64)zero_fill << 35) |
	       ((__u64)fill_imm8 << 36);
}

static __u64 pack_bulk_memset_imm_payload(__u8 dst_base, __s16 dst_off,
					  __u8 len, __u8 width,
					  __u8 fill_imm8)
{
	return pack_bulk_memset_payload_len_field(dst_base, 0, dst_off, len - 1,
						  width, false, false,
						  fill_imm8);
}

static __u64 pack_bulk_memset_reg_payload(__u8 dst_base, __u8 val_reg,
					  __s16 dst_off, __u8 len,
					  __u8 width)
{
	return pack_bulk_memset_payload_len_field(dst_base, val_reg, dst_off,
						  len - 1, width, true, false,
						  0);
}

static __u64 pack_bulk_memset_zero_payload(__u8 dst_base, __s16 dst_off,
					   __u8 len, __u8 width)
{
	return pack_bulk_memset_payload_len_field(dst_base, 0, dst_off, len - 1,
						  width, false, true, 0);
}

static __u64 pack_ldp_pair_payload(__u8 lane0_reg, __u8 lane1_reg,
				   __u8 base_reg, __s16 offset, __u8 flags)
{
	return (__u64)lane0_reg |
	       ((__u64)lane1_reg << 4) |
	       ((__u64)base_reg << 8) |
	       ((__u64)(__u16)offset << 12) |
	       ((__u64)(flags & 0xf) << 28);
}

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

static int get_jited_program(int prog_fd, __u8 **buf, __u32 *len)
{
	struct bpf_prog_info info = {};
	union bpf_attr attr = {};
	__u32 info_len = sizeof(info);
	__u32 jited_len;

	attr.info.bpf_fd = prog_fd;
	attr.info.info_len = info_len;
	attr.info.info = ptr_to_u64(&info);
	if (sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) < 0)
		return -1;
	if (!info.jited_prog_len) {
		errno = ENOENT;
		return -1;
	}
	jited_len = info.jited_prog_len;

	*buf = calloc(jited_len, 1);
	if (!*buf) {
		errno = ENOMEM;
		return -1;
	}

	memset(&info, 0, sizeof(info));
	memset(&attr, 0, sizeof(attr));
	attr.info.bpf_fd = prog_fd;
	info.jited_prog_len = jited_len;
	info.jited_prog_insns = ptr_to_u64(*buf);
	*len = jited_len;
	attr.info.info_len = sizeof(info);
	attr.info.info = ptr_to_u64(&info);
	if (sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) < 0) {
		free(*buf);
		*buf = NULL;
		*len = 0;
		return -1;
	}

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

static int read_file(const char *path, void **data_out, size_t *len_out)
{
	struct stat st;
	void *data;
	int fd;
	size_t cap = 0;
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

	if (btf_len < sizeof(*hdr)) {
		errno = EINVAL;
		return -1;
	}
	if (hdr->magic != 0xeb9f) {
		errno = EPROTO;
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
	const char *path = "/sys/kernel/btf/vmlinux";
	void *data = NULL;
	size_t data_len = 0;
	const struct btf_header *hdr;

	if (read_file(path, &data, &data_len) < 0)
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
	const struct btf_header *hdr = btf_data;
	const unsigned char *data = btf_data;
	const unsigned char *type_section;
	const unsigned char *str_section;
	size_t hdr_len, type_start, type_end, str_start, str_end;
	size_t offset = 0;
	__u32 type_id = 1;

	if (btf_len < sizeof(*hdr))
		return -1;
	if (hdr->magic != 0xeb9f) {
		errno = EPROTO;
		return -1;
	}

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
		const struct btf_type *bt;
		__u32 kind;
		__u32 vlen;
		size_t skip = 0;

		bt = (const struct btf_type *)(type_section + offset);
		kind = btf_kind(bt);

		if (kind == 12) {
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

		offset += sizeof(struct btf_type);
		vlen = bt->info & 0xffff;
		(void)vlen;
		skip = btf_type_extra_size(bt);
		offset += skip;
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
		g_modules[i].btf_fd = bpf_btf_get_fd_by_module_name(
			g_modules[i].module_name);
		if (g_modules[i].btf_fd < 0) {
			if (g_modules[i].required)
				return -1;
			continue;
		}
		g_modules[i].available = true;
	}

	for (i = 0; i < ARRAY_SIZE(g_funcs); i++) {
		const struct kinsn_module_ref *module;
		char path[128];
		void *data = NULL;
		size_t data_len = 0;

		module = &g_modules[g_funcs[i].module_id];
		if (!module->available)
			continue;

		snprintf(path, sizeof(path), "/sys/kernel/btf/%s",
			 module->module_name);
		if (read_file(path, &data, &data_len) < 0)
			return -1;
		if (find_func_btf_id(data, data_len, g_funcs[i].func_name,
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
		g_modules[i].available = false;
	}
	g_discovered = false;
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

static void patch_all_kinsns(struct bpf_insn *prog, size_t cnt, __u32 btf_id)
{
	size_t i;

	for (i = 0; i < cnt; i++) {
		if (prog[i].code == (BPF_JMP | BPF_CALL) &&
		    prog[i].src_reg == BPF_PSEUDO_KINSN_CALL) {
			prog[i].imm = (__s32)btf_id;
			prog[i].off = 1;
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

static int run_rejit_expect_failure_preserves_original(
	const char *name, const struct bpf_insn *replacement,
	__u32 replacement_cnt, const int *fd_array, __u32 fd_array_cnt)
{
	char log_buf[LOG_BUF_SIZE];
	__u32 retval = 0;
	int prog_fd;

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_ret_1, ARRAY_SIZE(prog_ret_1),
				NULL, 0, log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "base load failed");
		return 1;
	}

	if (test_run_xdp(prog_fd, &retval) < 0 || retval != 1) {
		TEST_FAIL(name, "base program run failed");
		close(prog_fd);
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_xdp_prog(prog_fd, replacement, replacement_cnt, fd_array,
			   fd_array_cnt, log_buf, sizeof(log_buf)) >= 0) {
		TEST_FAIL(name, "REJIT unexpectedly succeeded");
		close(prog_fd);
		return 1;
	}

	if (test_run_xdp(prog_fd, &retval) < 0 || retval != 1) {
		TEST_FAIL(name, "failed REJIT changed original program");
		close(prog_fd);
		return 1;
	}

	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

static bool skip_if_module_unavailable(const char *name,
				       enum kinsn_module_id module_id)
{
	if (g_modules[module_id].available)
		return false;

	TEST_SKIP(name, "module not available on this kernel/architecture");
	return true;
}

static bool should_skip_bulk_for_insn_buf_limit(enum kinsn_module_id module_id,
						const char *log_buf)
{
	return module_id == MOD_BULK_MEMORY &&
	       strstr(log_buf, "exceeds insn_buf size 32") != NULL;
}

static int run_single_kinsn_expect_success(const char *name,
					   enum kinsn_module_id module_id,
					   enum kinsn_func_id func_id,
					   struct bpf_insn *prog,
					   __u32 prog_cnt,
					   __u32 expected_retval)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[module_id].btf_fd);
	char log_buf[LOG_BUF_SIZE];
	__u32 retval = 0;
	int prog_fd;

	if (skip_if_module_unavailable(name, module_id))
		return 0;

	patch_single_kinsn(prog, prog_cnt, g_funcs[func_id].btf_id);

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
	if (rejit_xdp_prog(prog_fd, prog, prog_cnt, fd_array,
			   ARRAY_SIZE(fd_array), log_buf,
			   sizeof(log_buf)) < 0) {
		if (should_skip_bulk_for_insn_buf_limit(module_id, log_buf)) {
			close(prog_fd);
			TEST_SKIP(name, "kernel kinsn proof buffer is limited to 32 insns");
			return 0;
		}

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

static int run_single_kinsn_expect_failure(const char *name,
					   enum kinsn_module_id module_id,
					   enum kinsn_func_id func_id,
					   struct bpf_insn *prog,
					   __u32 prog_cnt)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[module_id].btf_fd);

	if (skip_if_module_unavailable(name, module_id))
		return 0;

	patch_single_kinsn(prog, prog_cnt, g_funcs[func_id].btf_id);
	return run_rejit_expect_failure_preserves_original(
		name, prog, prog_cnt, fd_array, ARRAY_SIZE(fd_array));
}

static int run_single_kinsn_expect_jit_bytes(const char *name,
					     enum kinsn_module_id module_id,
					     enum kinsn_func_id func_id,
					     struct bpf_insn *prog,
					     __u32 prog_cnt,
					     __u32 expected_retval,
					     const __u8 *needle,
					     __u32 needle_len,
					     const char *missing_reason)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[module_id].btf_fd);
	char log_buf[LOG_BUF_SIZE];
	__u32 retval = 0;
	__u8 *jited = NULL;
	__u32 jited_len = 0;
	int prog_fd;

	if (skip_if_module_unavailable(name, module_id))
		return 0;

	patch_single_kinsn(prog, prog_cnt, g_funcs[func_id].btf_id);

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_ret_0, ARRAY_SIZE(prog_ret_0),
				NULL, 0, log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "base load failed");
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_xdp_prog(prog_fd, prog, prog_cnt, fd_array,
			   ARRAY_SIZE(fd_array), log_buf,
			   sizeof(log_buf)) < 0) {
		if (should_skip_bulk_for_insn_buf_limit(module_id, log_buf)) {
			close(prog_fd);
			TEST_SKIP(name, "kernel kinsn proof buffer is limited to 32 insns");
			return 0;
		}

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

	if (get_jited_program(prog_fd, &jited, &jited_len) < 0) {
		TEST_FAIL(name, "failed to fetch JIT image");
		close(prog_fd);
		return 1;
	}

	if (!find_bytes(jited, jited_len, needle, needle_len)) {
		TEST_FAIL(name, missing_reason);
		free(jited);
		close(prog_fd);
		return 1;
	}

	free(jited);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
}

static int test_kinsn_discovery(void)
{
	const char *name = "kinsn_discovery";
	size_t i;

	if (discover_kinsns() < 0) {
		TEST_FAIL(name, "failed to discover kinsn function BTF and IDs");
		return 1;
	}

	for (i = 0; i < ARRAY_SIZE(g_funcs); i++) {
		const struct kinsn_module_ref *module;

		module = &g_modules[g_funcs[i].module_id];
		if (!module->available)
			continue;
		if (g_funcs[i].btf_id == 0 || module->btf_fd < 0) {
			TEST_FAIL(name, "missing kinsn BTF ID or module BTF FD");
			return 1;
		}
	}

	TEST_PASS(name);
	for (i = 0; i < ARRAY_SIZE(g_modules); i++) {
		if (!g_modules[i].available && !g_modules[i].required)
			printf("    %s: unavailable (optional)\n",
			       g_modules[i].module_name);
	}
	for (i = 0; i < ARRAY_SIZE(g_funcs); i++) {
		if (!g_modules[g_funcs[i].module_id].available)
			continue;
		printf("    %s/%s: btf_fd=%d btf_id=%u\n",
		       g_modules[g_funcs[i].module_id].module_name,
		       g_funcs[i].func_name,
		       g_modules[g_funcs[i].module_id].btf_fd,
		       g_funcs[i].btf_id);
	}
	return 0;
}

static int test_rejit_rotate_apply(void)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_ROTATE].btf_fd);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_1, 1),
		BPF_KINSN_SIDECAR(KINSN_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_1, 1,
							      BPF_REG_6)),
		BPF_CALL_KINSN(0, 0),
		BPF_EXIT_INSN(),
	};

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_ROTATE].btf_id);
	return run_rejit_expect_success("rotate_apply",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array), 2);
}

static int test_rejit_rotate_jit_emits_rol(void)
{
#if defined(__x86_64__)
	static const __u8 rotate_seq[] = {
		0x48, 0x89, 0xf8,
		0x48, 0xc1, 0xc0, 0x01,
	};
	const char *name = "rotate_jit_emits_rol";
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_ROTATE].btf_fd);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_1, 1),
		BPF_KINSN_SIDECAR(KINSN_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_1, 1,
							      BPF_REG_6)),
		BPF_CALL_KINSN(0, 0),
		BPF_EXIT_INSN(),
	};
	char log_buf[LOG_BUF_SIZE];
	__u32 retval = 0;
	__u8 *jited = NULL;
	__u32 jited_len = 0;
	int prog_fd;

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_ROTATE].btf_id);

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_ret_0, ARRAY_SIZE(prog_ret_0),
				NULL, 0, log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "base load failed");
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_xdp_prog(prog_fd, prog, ARRAY_SIZE(prog), fd_array,
			   ARRAY_SIZE(fd_array), log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT failed");
		close(prog_fd);
		return 1;
	}

	if (test_run_xdp(prog_fd, &retval) < 0 || retval != 2) {
		TEST_FAIL(name, "recompiled program returned wrong value");
		close(prog_fd);
		return 1;
	}

	if (get_jited_program(prog_fd, &jited, &jited_len) < 0) {
		TEST_FAIL(name, "failed to fetch JIT image");
		close(prog_fd);
		return 1;
	}

	if (!find_bytes(jited, jited_len, rotate_seq, sizeof(rotate_seq))) {
		TEST_FAIL(name, "ROL sequence not found in JIT image");
		free(jited);
		close(prog_fd);
		return 1;
	}

	free(jited);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
#else
	TEST_SKIP("rotate_jit_emits_rol", "x86_64 only");
	return 0;
#endif
}

static int test_rejit_rotate_arbitrary_regs(void)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_ROTATE].btf_fd);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_6, 1),
		BPF_KINSN_SIDECAR(KINSN_ROTATE_PAYLOAD(BPF_REG_7, BPF_REG_6, 1,
							      BPF_REG_8)),
		BPF_CALL_KINSN(0, 0),
		BPF_MOV64_REG(BPF_REG_0, BPF_REG_7),
		BPF_EXIT_INSN(),
	};

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_ROTATE].btf_id);
	return run_rejit_expect_success("rotate_arbitrary_regs",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array), 2);
}

static int test_rejit_rotate_r5_preserved(void)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_ROTATE].btf_fd);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_5, 7),
		BPF_MOV64_IMM(BPF_REG_1, 1),
		BPF_KINSN_SIDECAR(KINSN_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_1, 1,
							      BPF_REG_6)),
		BPF_CALL_KINSN(0, 0),
		BPF_MOV64_REG(BPF_REG_0, BPF_REG_5),
		BPF_EXIT_INSN(),
	};

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_ROTATE].btf_id);
	return run_rejit_expect_success("rotate_r5_preserved",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array), 7);
}

static int test_rejit_rotate_restore_preserves_ldimm64_layout(void)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_ROTATE].btf_fd);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_1, 1),
		BPF_KINSN_SIDECAR(KINSN_ROTATE_PAYLOAD(BPF_REG_5, BPF_REG_1, 1,
							      BPF_REG_6)),
		BPF_CALL_KINSN(0, 0),
		BPF_LD_IMM64_RAW(BPF_REG_7, 0x1122334455667788ULL),
		BPF_MOV64_IMM(BPF_REG_1, 1),
		BPF_KINSN_SIDECAR(KINSN_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_1, 1,
							      BPF_REG_6)),
		BPF_CALL_KINSN(0, 0),
		BPF_EXIT_INSN(),
	};

	patch_all_kinsns(prog, ARRAY_SIZE(prog), g_funcs[FUNC_ROTATE].btf_id);
	return run_rejit_expect_success("rotate_restore_preserves_ldimm64_layout",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array), 2);
}

static int test_rejit_rotate_invalid_tmp_rejected(void)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_ROTATE].btf_fd);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_1, 1),
		BPF_KINSN_SIDECAR(KINSN_ROTATE_PAYLOAD(BPF_REG_0, BPF_REG_1, 1,
							      BPF_REG_1)),
		BPF_CALL_KINSN(0, 0),
		BPF_EXIT_INSN(),
	};

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_ROTATE].btf_id);
	return run_rejit_expect_failure_preserves_original(
		"rotate_invalid_tmp_rejected", prog, ARRAY_SIZE(prog),
		fd_array, ARRAY_SIZE(fd_array));
}

static int test_rejit_select_apply(void)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_SELECT].btf_fd);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_1, 11),
		BPF_MOV64_IMM(BPF_REG_2, 29),
		BPF_MOV64_IMM(BPF_REG_3, 1),
		BPF_KINSN_SIDECAR(KINSN_SELECT_PAYLOAD(BPF_REG_0, BPF_REG_1,
							       BPF_REG_2, BPF_REG_3)),
		BPF_CALL_KINSN(0, 0),
		BPF_EXIT_INSN(),
	};

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_SELECT].btf_id);
	return run_rejit_expect_success("select_apply",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array), 11);
}

static int test_rejit_select_arbitrary_dst_reg(void)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_SELECT].btf_fd);
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
	return run_rejit_expect_success("select_arbitrary_dst_reg",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array), 11);
}

static int test_rejit_endian_apply(void)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_ENDIAN].btf_fd);
	struct bpf_insn prog[] = {
		BPF_ST_MEM(BPF_H, BPF_REG_10, -2, 0x1234),
		BPF_MOV64_REG(BPF_REG_1, BPF_REG_10),
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_1, -2),
		BPF_KINSN_SIDECAR(KINSN_ENDIAN_PAYLOAD(BPF_REG_0, BPF_REG_1)),
		BPF_CALL_KINSN(0, 0),
		BPF_EXIT_INSN(),
	};

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_ENDIAN16].btf_id);
	return run_rejit_expect_success("endian_apply",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array), 0x3412);
}

static int test_rejit_endian32_apply(void)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_ENDIAN].btf_fd);
	struct bpf_insn prog[] = {
		BPF_ST_MEM(BPF_W, BPF_REG_10, -4, 0x12345678),
		BPF_MOV64_REG(BPF_REG_1, BPF_REG_10),
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_1, -4),
		BPF_KINSN_SIDECAR(KINSN_ENDIAN_PAYLOAD(BPF_REG_0, BPF_REG_1)),
		BPF_CALL_KINSN(0, 0),
		BPF_EXIT_INSN(),
	};

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_ENDIAN32].btf_id);
	return run_rejit_expect_success("endian32_apply",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array), 0x78563412);
}

static int test_rejit_endian_arbitrary_regs(void)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_ENDIAN].btf_fd);
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
	return run_rejit_expect_success("endian_arbitrary_regs",
					prog, ARRAY_SIZE(prog),
					fd_array, ARRAY_SIZE(fd_array), 0x3412);
}

static int test_rejit_endian_invalid_access_rejected(void)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_ENDIAN].btf_fd);
	struct bpf_insn prog[] = {
		BPF_MOV64_REG(BPF_REG_1, BPF_REG_10),
		BPF_ALU64_IMM(BPF_ADD, BPF_REG_1, -513),
		BPF_KINSN_SIDECAR(KINSN_ENDIAN_PAYLOAD(BPF_REG_0, BPF_REG_1)),
		BPF_CALL_KINSN(0, 0),
		BPF_EXIT_INSN(),
	};

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_ENDIAN16].btf_id);
	return run_rejit_expect_failure_preserves_original(
		"endian_invalid_access_rejected", prog, ARRAY_SIZE(prog),
		fd_array, ARRAY_SIZE(fd_array));
}

static int test_rejit_bulk_memcpy_apply(void)
{
	const __u64 payload = pack_bulk_memcpy_payload(BPF_REG_10, BPF_REG_10,
						       -128, -96, 32,
						       BPF_REG_6);
	struct bpf_insn prog[] = {
		BPF_ST_MEM(BPF_W, BPF_REG_10, -96, 0x04030201),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -92, 0x08070605),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -88, 0x0c0b0a09),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -84, 0x100f0e0d),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -80, 0x14131211),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -76, 0x18171615),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -72, 0x1c1b1a19),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -68, 0x201f1e1d),
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_10, -128),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0x04030201, 1),
		BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_10, -116),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0x100f0e0d, 2),
		BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_10, -100),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0x201f1e1d, 3),
		BPF_EXPECT_EQ_IMM(BPF_REG_6, 0x20, 4),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};

	return run_single_kinsn_expect_success("bulk_memcpy_apply",
					       MOD_BULK_MEMORY,
					       FUNC_MEMCPY_BULK,
					       prog, ARRAY_SIZE(prog), 0);
}

static int test_rejit_bulk_memset_reg_apply(void)
{
	const __u64 payload = pack_bulk_memset_reg_payload(BPF_REG_10, BPF_REG_1,
							   -128, 32, BPF_W);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_1, 0x7c),
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_LDX_MEM(BPF_W, BPF_REG_2, BPF_REG_10, -128),
		BPF_EXPECT_EQ_IMM(BPF_REG_2, 0x7c7c7c7c, 1),
		BPF_LDX_MEM(BPF_W, BPF_REG_2, BPF_REG_10, -116),
		BPF_EXPECT_EQ_IMM(BPF_REG_2, 0x7c7c7c7c, 2),
		BPF_LDX_MEM(BPF_W, BPF_REG_2, BPF_REG_10, -100),
		BPF_EXPECT_EQ_IMM(BPF_REG_2, 0x7c7c7c7c, 3),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};

	return run_single_kinsn_expect_success("bulk_memset_reg_apply",
					       MOD_BULK_MEMORY,
					       FUNC_MEMSET_BULK,
					       prog, ARRAY_SIZE(prog), 0);
}

static int test_rejit_bulk_memcpy_offset_lower_boundary(void)
{
	const __u64 payload = pack_bulk_memcpy_payload(BPF_REG_10, BPF_REG_10,
						       -512, -480, 32,
						       BPF_REG_6);
	struct bpf_insn prog[] = {
		BPF_ST_MEM(BPF_W, BPF_REG_10, -480, 0x24232221),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -476, 0x28272625),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -472, 0x2c2b2a29),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -468, 0x302f2e2d),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -464, 0x34333231),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -460, 0x38373635),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -456, 0x3c3b3a39),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -452, 0x403f3e3d),
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_10, -512),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0x24232221, 1),
		BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_10, -500),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0x302f2e2d, 2),
		BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_10, -484),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0x403f3e3d, 3),
		BPF_EXPECT_EQ_IMM(BPF_REG_6, 0x40, 4),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};

	return run_single_kinsn_expect_success(
		"bulk_memcpy_offset_lower_boundary", MOD_BULK_MEMORY,
		FUNC_MEMCPY_BULK, prog, ARRAY_SIZE(prog), 0);
}

static int test_rejit_bulk_memset_max_len_zero_fill(void)
{
	const __u64 payload = pack_bulk_memset_zero_payload(BPF_REG_10, -128,
							    128, BPF_DW);
	struct bpf_insn prog[] = {
		BPF_ST_MEM(BPF_W, BPF_REG_10, -128, 0x01020304),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -64, 0x11121314),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -4, 0x21222324),
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_10, -128),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0, 1),
		BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_10, -64),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0, 2),
		BPF_LDX_MEM(BPF_B, BPF_REG_1, BPF_REG_10, -1),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0, 3),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};

	return run_single_kinsn_expect_success("bulk_memset_max_len_zero_fill",
					       MOD_BULK_MEMORY,
					       FUNC_MEMSET_BULK,
					       prog, ARRAY_SIZE(prog), 0);
}

static int test_rejit_bulk_memcpy_zero_length_rejected(void)
{
	const __u64 payload = pack_bulk_memcpy_payload_len_field(BPF_REG_10,
								 BPF_REG_10,
								 -128, -96,
								 0xff,
								 BPF_REG_6);
	struct bpf_insn prog[] = {
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};

	return run_single_kinsn_expect_failure(
		"bulk_memcpy_zero_length_rejected", MOD_BULK_MEMORY,
		FUNC_MEMCPY_BULK, prog, ARRAY_SIZE(prog));
}

static int test_rejit_bulk_memcpy_invalid_tmp_rejected(void)
{
	const __u64 payload = pack_bulk_memcpy_payload(BPF_REG_10, BPF_REG_10,
						       -128, -96, 32,
						       BPF_REG_10);
	struct bpf_insn prog[] = {
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};

	return run_single_kinsn_expect_failure(
		"bulk_memcpy_invalid_tmp_rejected", MOD_BULK_MEMORY,
		FUNC_MEMCPY_BULK, prog, ARRAY_SIZE(prog));
}

static int test_rejit_bulk_memset_invalid_width_rejected(void)
{
	const __u64 payload = pack_bulk_memset_imm_payload(BPF_REG_10, -128, 34,
							   BPF_DW, 0x5a);
	struct bpf_insn prog[] = {
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};

	return run_single_kinsn_expect_failure(
		"bulk_memset_invalid_width_rejected", MOD_BULK_MEMORY,
		FUNC_MEMSET_BULK, prog, ARRAY_SIZE(prog));
}

static int test_rejit_bulk_memcpy_jit_emits_rep_movsb(void)
{
#if defined(__x86_64__)
	static const __u8 rep_movsb[] = { 0xf3, 0xa4 };
	const __u64 payload = pack_bulk_memcpy_payload(BPF_REG_10, BPF_REG_10,
						       -128, -96, 32,
						       BPF_REG_6);
	struct bpf_insn prog[] = {
		BPF_ST_MEM(BPF_W, BPF_REG_10, -96, 0x04030201),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -92, 0x08070605),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -88, 0x0c0b0a09),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -84, 0x100f0e0d),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -80, 0x14131211),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -76, 0x18171615),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -72, 0x1c1b1a19),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -68, 0x201f1e1d),
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_10, -100),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0x201f1e1d, 1),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};

	return run_single_kinsn_expect_jit_bytes(
		"bulk_memcpy_jit_emits_rep_movsb", MOD_BULK_MEMORY,
		FUNC_MEMCPY_BULK, prog, ARRAY_SIZE(prog), 0,
		rep_movsb, ARRAY_SIZE(rep_movsb),
		"REP MOVSB sequence not found in JIT image");
#else
	TEST_SKIP("bulk_memcpy_jit_emits_rep_movsb", "x86_64 only");
	return 0;
#endif
}

static int test_rejit_bulk_memcpy_kinsn_tmp_r7_saves_r13(void)
{
#if defined(__x86_64__)
	static const __u8 push_r13[] = { 0x41, 0x55 };
	static const __u8 pop_r13[] = { 0x41, 0x5d };
	const __u64 payload = pack_bulk_memcpy_payload(BPF_REG_10, BPF_REG_10,
						       -128, -96, 32,
						       BPF_REG_7);
	const char *name = "bulk_memcpy_kinsn_tmp_r7_saves_r13";
	struct bpf_insn prog[] = {
		BPF_ST_MEM(BPF_W, BPF_REG_10, -96, 0x04030201),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -92, 0x08070605),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -88, 0x0c0b0a09),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -84, 0x100f0e0d),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -80, 0x14131211),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -76, 0x18171615),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -72, 0x1c1b1a19),
		BPF_ST_MEM(BPF_W, BPF_REG_10, -68, 0x201f1e1d),
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_10, -100),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0x201f1e1d, 1),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_BULK_MEMORY].btf_fd);
	char log_buf[LOG_BUF_SIZE];
	__u32 retval = 0;
	__u8 *jited = NULL;
	__u32 jited_len = 0;
	int prog_fd;

	if (skip_if_module_unavailable(name, MOD_BULK_MEMORY))
		return 0;

	patch_single_kinsn(prog, ARRAY_SIZE(prog), g_funcs[FUNC_MEMCPY_BULK].btf_id);

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_ret_0, ARRAY_SIZE(prog_ret_0),
				NULL, 0, log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		TEST_FAIL(name, "base load failed");
		return 1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_xdp_prog(prog_fd, prog, ARRAY_SIZE(prog), fd_array,
			   ARRAY_SIZE(fd_array), log_buf, sizeof(log_buf)) < 0) {
		if (should_skip_bulk_for_insn_buf_limit(MOD_BULK_MEMORY, log_buf)) {
			close(prog_fd);
			TEST_SKIP(name, "kernel kinsn proof buffer is limited to 32 insns");
			return 0;
		}
		fprintf(stderr, "    verifier log:\n%s\n", log_buf);
		TEST_FAIL(name, "REJIT failed");
		close(prog_fd);
		return 1;
	}

	if (test_run_xdp(prog_fd, &retval) < 0 || retval != 0) {
		TEST_FAIL(name, "recompiled program returned wrong value");
		close(prog_fd);
		return 1;
	}

	if (get_jited_program(prog_fd, &jited, &jited_len) < 0) {
		TEST_FAIL(name, "failed to fetch JIT image");
		close(prog_fd);
		return 1;
	}

	if (!find_bytes(jited, jited_len, push_r13, sizeof(push_r13))) {
		TEST_FAIL(name, "push r13 not found in JIT image");
		free(jited);
		close(prog_fd);
		return 1;
	}

	if (!find_bytes(jited, jited_len, pop_r13, sizeof(pop_r13))) {
		TEST_FAIL(name, "pop r13 not found in JIT image");
		free(jited);
		close(prog_fd);
		return 1;
	}

	free(jited);
	close(prog_fd);
	TEST_PASS(name);
	return 0;
#else
	TEST_SKIP("bulk_memcpy_kinsn_tmp_r7_saves_r13", "x86_64 only");
	return 0;
#endif
}

static int test_rejit_bulk_memset_jit_emits_rep_stosb(void)
{
#if defined(__x86_64__)
	static const __u8 rep_stosb[] = { 0xf3, 0xaa };
	const __u64 payload = pack_bulk_memset_imm_payload(BPF_REG_10, -128, 32,
							   BPF_W, 0x5a);
	struct bpf_insn prog[] = {
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_10, -100),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0x5a5a5a5a, 1),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};

	return run_single_kinsn_expect_jit_bytes(
		"bulk_memset_jit_emits_rep_stosb", MOD_BULK_MEMORY,
		FUNC_MEMSET_BULK, prog, ARRAY_SIZE(prog), 0,
		rep_stosb, ARRAY_SIZE(rep_stosb),
		"REP STOSB sequence not found in JIT image");
#else
	TEST_SKIP("bulk_memset_jit_emits_rep_stosb", "x86_64 only");
	return 0;
#endif
}

static int test_rejit_ldp128_apply(void)
{
	const __u64 payload = pack_ldp_pair_payload(BPF_REG_6, BPF_REG_7,
						    BPF_REG_10, -32, 0);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_1, 0x01020304),
		BPF_STX_MEM(BPF_DW, BPF_REG_10, BPF_REG_1, -32),
		BPF_MOV64_IMM(BPF_REG_2, 0x05060708),
		BPF_STX_MEM(BPF_DW, BPF_REG_10, BPF_REG_2, -24),
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_EXPECT_EQ_IMM(BPF_REG_6, 0x01020304, 1),
		BPF_EXPECT_EQ_IMM(BPF_REG_7, 0x05060708, 2),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};

	return run_single_kinsn_expect_success("ldp128_apply", MOD_LDP,
					       FUNC_LDP128, prog,
					       ARRAY_SIZE(prog), 0);
}

static int test_rejit_stp128_apply(void)
{
	const __u64 payload = pack_ldp_pair_payload(BPF_REG_6, BPF_REG_7,
						    BPF_REG_10, -32, 0);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_6, 0x11121314),
		BPF_MOV64_IMM(BPF_REG_7, 0x21222324),
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_LDX_MEM(BPF_DW, BPF_REG_1, BPF_REG_10, -32),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0x11121314, 1),
		BPF_LDX_MEM(BPF_DW, BPF_REG_1, BPF_REG_10, -24),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0x21222324, 2),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};

	return run_single_kinsn_expect_success("stp128_apply", MOD_LDP,
					       FUNC_STP128, prog,
					       ARRAY_SIZE(prog), 0);
}

static int test_rejit_stp128_offset_lower_boundary(void)
{
	const __u64 payload = pack_ldp_pair_payload(BPF_REG_6, BPF_REG_7,
						    BPF_REG_10, -512, 0);
	struct bpf_insn prog[] = {
		BPF_MOV64_IMM(BPF_REG_6, 0x31323334),
		BPF_MOV64_IMM(BPF_REG_7, 0x41424344),
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_LDX_MEM(BPF_DW, BPF_REG_1, BPF_REG_10, -512),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0x31323334, 1),
		BPF_LDX_MEM(BPF_DW, BPF_REG_1, BPF_REG_10, -504),
		BPF_EXPECT_EQ_IMM(BPF_REG_1, 0x41424344, 2),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};

	return run_single_kinsn_expect_success(
		"stp128_offset_lower_boundary", MOD_LDP, FUNC_STP128,
		prog, ARRAY_SIZE(prog), 0);
}

static int test_rejit_ldp128_invalid_flags_rejected(void)
{
	const __u64 payload = pack_ldp_pair_payload(BPF_REG_6, BPF_REG_7,
						    BPF_REG_10, -32, 1);
	struct bpf_insn prog[] = {
		BPF_KINSN_SIDECAR(payload),
		BPF_CALL_KINSN(0, 0),
		BPF_MOV64_IMM(BPF_REG_0, 0),
		BPF_EXIT_INSN(),
	};

	return run_single_kinsn_expect_failure(
		"ldp128_invalid_flags_rejected", MOD_LDP, FUNC_LDP128,
		prog, ARRAY_SIZE(prog));
}

static int test_rejit_extract_range_narrowing(void)
{
	int fd_array[2] = BTF_FD_ARRAY(g_modules[MOD_EXTRACT].btf_fd);
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
	return run_rejit_expect_success("extract_range_narrowing",
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

	printf("[kinsn] discovery and verifier/JIT modeling tests\n");

	if (!filter || strcmp(filter, "kinsn_discovery") != 0)
		ret |= test_kinsn_discovery();
	else if (should_run_test(filter, "kinsn_discovery"))
		ret |= test_kinsn_discovery();
	if (should_run_test(filter, "rotate_apply"))
		ret |= test_rejit_rotate_apply();
	if (should_run_test(filter, "rotate_jit_emits_rol"))
		ret |= test_rejit_rotate_jit_emits_rol();
	if (should_run_test(filter, "rotate_arbitrary_regs"))
		ret |= test_rejit_rotate_arbitrary_regs();
	if (should_run_test(filter, "rotate_r5_preserved"))
		ret |= test_rejit_rotate_r5_preserved();
	if (should_run_test(filter, "rotate_restore_preserves_ldimm64_layout"))
		ret |= test_rejit_rotate_restore_preserves_ldimm64_layout();
#if defined(__x86_64__)
	if (should_run_test(filter, "rotate_invalid_tmp_rejected"))
		ret |= test_rejit_rotate_invalid_tmp_rejected();
#endif
	if (should_run_test(filter, "select_apply"))
		ret |= test_rejit_select_apply();
	if (should_run_test(filter, "select_arbitrary_dst_reg"))
		ret |= test_rejit_select_arbitrary_dst_reg();
	if (should_run_test(filter, "endian_apply"))
		ret |= test_rejit_endian_apply();
	if (should_run_test(filter, "endian32_apply"))
		ret |= test_rejit_endian32_apply();
	if (should_run_test(filter, "endian_arbitrary_regs"))
		ret |= test_rejit_endian_arbitrary_regs();
	if (should_run_test(filter, "endian_invalid_access_rejected"))
		ret |= test_rejit_endian_invalid_access_rejected();
	if (should_run_test(filter, "bulk_memcpy_apply"))
		ret |= test_rejit_bulk_memcpy_apply();
	if (should_run_test(filter, "bulk_memset_reg_apply"))
		ret |= test_rejit_bulk_memset_reg_apply();
	if (should_run_test(filter, "bulk_memcpy_offset_lower_boundary"))
		ret |= test_rejit_bulk_memcpy_offset_lower_boundary();
	if (should_run_test(filter, "bulk_memset_max_len_zero_fill"))
		ret |= test_rejit_bulk_memset_max_len_zero_fill();
	if (should_run_test(filter, "bulk_memcpy_zero_length_rejected"))
		ret |= test_rejit_bulk_memcpy_zero_length_rejected();
	if (should_run_test(filter, "bulk_memcpy_invalid_tmp_rejected"))
		ret |= test_rejit_bulk_memcpy_invalid_tmp_rejected();
	if (should_run_test(filter, "bulk_memset_invalid_width_rejected"))
		ret |= test_rejit_bulk_memset_invalid_width_rejected();
	if (should_run_test(filter, "bulk_memcpy_jit_emits_rep_movsb"))
		ret |= test_rejit_bulk_memcpy_jit_emits_rep_movsb();
	if (should_run_test(filter, "bulk_memcpy_kinsn_tmp_r7_saves_r13"))
		ret |= test_rejit_bulk_memcpy_kinsn_tmp_r7_saves_r13();
	if (should_run_test(filter, "bulk_memset_jit_emits_rep_stosb"))
		ret |= test_rejit_bulk_memset_jit_emits_rep_stosb();
	if (should_run_test(filter, "ldp128_apply"))
		ret |= test_rejit_ldp128_apply();
	if (should_run_test(filter, "stp128_apply"))
		ret |= test_rejit_stp128_apply();
	if (should_run_test(filter, "stp128_offset_lower_boundary"))
		ret |= test_rejit_stp128_offset_lower_boundary();
	if (should_run_test(filter, "ldp128_invalid_flags_rejected"))
		ret |= test_rejit_ldp128_invalid_flags_rejected();
	if (should_run_test(filter, "extract_range_narrowing"))
		ret |= test_rejit_extract_range_narrowing();

	printf("\nSummary: %d passed, %d failed, %d skipped\n",
	       g_pass, g_fail, g_skip);
	cleanup_discovery();
	return ret || g_fail ? 1 : 0;
}
