// SPDX-License-Identifier: GPL-2.0
/*
 * Test: select64 register alias correctness (dst == cond)
 *
 * Loads real BPF programs into the kernel and compares:
 *   (a) plain BPF proof sequence (ordinary JMP/MOV instructions)
 *   (b) kinsn sidecar+call (triggers native x86 CMOV emit via bpf_select module)
 *
 * The two must produce identical results for all test vectors,
 * especially when dst_reg == cond_reg.
 *
 * Regression test for: x86 emit_select_x86 MOV-before-TEST alias bug.
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

/* ------------------------------------------------------------------ */
/* Helpers                                                             */
/* ------------------------------------------------------------------ */

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define LOG_BUF_SIZE  65536
#define ptr_to_u64(p) ((__u64)(uintptr_t)(p))

static int g_pass, g_fail;

#define TEST_PASS(name) do { \
	printf("  PASS  %s\n", (name)); g_pass++; \
} while (0)

#define TEST_FAIL(name, reason) do { \
	fprintf(stderr, "  FAIL  %s: %s (errno=%d: %s)\n", \
		(name), (reason), errno, strerror(errno)); \
	g_fail++; \
} while (0)

/* ------------------------------------------------------------------ */
/* BPF instruction macros                                              */
/* ------------------------------------------------------------------ */

#define BPF_RAW_INSN(CODE, DST, SRC, OFF, IMM) ((struct bpf_insn) { \
	.code = (CODE), .dst_reg = (DST), .src_reg = (SRC), \
	.off = (OFF), .imm = (IMM), })

#define BPF_EXIT_INSN() \
	BPF_RAW_INSN(BPF_JMP | BPF_EXIT, 0, 0, 0, 0)

#define BPF_MOV64_IMM(DST, IMM) \
	BPF_RAW_INSN(BPF_ALU64 | BPF_MOV | BPF_K, DST, 0, 0, IMM)

#define BPF_MOV64_REG(DST, SRC) \
	BPF_RAW_INSN(BPF_ALU64 | BPF_MOV | BPF_X, DST, SRC, 0, 0)

#define BPF_JMP_IMM(OP, DST, IMM, OFF) \
	BPF_RAW_INSN(BPF_JMP | (OP) | BPF_K, DST, 0, OFF, IMM)

#define BPF_JMP_A(OFF) \
	BPF_RAW_INSN(BPF_JMP | BPF_JA, 0, 0, OFF, 0)

#define BPF_CALL_KINSN(OFF, IMM) \
	BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, BPF_PSEUDO_KINSN_CALL, OFF, IMM)

#define BPF_KINSN_SIDECAR(PAYLOAD) \
	BPF_RAW_INSN(BPF_ALU64 | BPF_MOV | BPF_K, \
		     (__u8)((__u64)(PAYLOAD) & 0xf), \
		     BPF_PSEUDO_KINSN_SIDECAR, \
		     (__s16)(((__u64)(PAYLOAD) >> 4) & 0xffff), \
		     (__s32)(((__u64)(PAYLOAD) >> 20) & 0xffffffffU))

#define KINSN_SELECT_PAYLOAD(DST, TRUE_REG, FALSE_REG, COND_REG) \
	((__u64)(DST) | ((__u64)(TRUE_REG) << 4) | \
	 ((__u64)(FALSE_REG) << 8) | ((__u64)(COND_REG) << 12))

#define BTF_FD_ARRAY(FD) { (FD), (FD) }

/* ------------------------------------------------------------------ */
/* BPF syscall wrappers                                                */
/* ------------------------------------------------------------------ */

static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
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

/* ------------------------------------------------------------------ */
/* Minimal BTF discovery for bpf_select module                         */
/* ------------------------------------------------------------------ */

struct btf_header {
	__u16 magic;
	__u8  version;
	__u8  flags;
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

struct btf_info_q {
	__u64 btf;
	__u32 btf_size;
	__u32 id;
	__u64 name;
	__u32 name_len;
	__u32 kernel_btf;
	__u8  pad[96];
};

static int read_file(const char *path, __u8 **data, size_t *len)
{
	struct stat st;
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return -1;
	if (fstat(fd, &st) < 0 || st.st_size < 1) {
		close(fd);
		return -1;
	}
	*len = st.st_size;
	*data = malloc(*len);
	if (!*data) {
		close(fd);
		return -1;
	}
	if (read(fd, *data, *len) != (ssize_t)*len) {
		free(*data);
		close(fd);
		return -1;
	}
	close(fd);
	return 0;
}

static int get_vmlinux_type_count(__u32 *type_id_bias)
{
	struct btf_header *hdr;
	__u8 *data;
	size_t len;
	__u32 cnt;

	if (read_file("/sys/kernel/btf/vmlinux", &data, &len) < 0)
		return -1;
	hdr = (struct btf_header *)data;
	if (hdr->magic != 0xeb9f) {
		free(data);
		return -1;
	}
	cnt = hdr->type_len / sizeof(struct btf_type);
	*type_id_bias = cnt - 1;
	free(data);
	return 0;
}

static int bpf_btf_get_fd_by_module_name(const char *module_name)
{
	union bpf_attr attr;
	__u32 id = 0;

	for (;;) {
		int fd;
		char name[64] = {};

		memset(&attr, 0, sizeof(attr));
		attr.start_id = id + 1;
		if (sys_bpf(BPF_BTF_GET_NEXT_ID, &attr, sizeof(attr)) < 0)
			return -1;
		id = attr.next_id;

		memset(&attr, 0, sizeof(attr));
		attr.btf_id = id;
		fd = sys_bpf(BPF_BTF_GET_FD_BY_ID, &attr, sizeof(attr));
		if (fd < 0)
			continue;

		struct btf_info_q info;

		memset(&info, 0, sizeof(info));
		info.name_len = sizeof(name);
		info.name = ptr_to_u64(name);

		memset(&attr, 0, sizeof(attr));
		attr.info.bpf_fd = fd;
		attr.info.info_len = sizeof(info);
		attr.info.info = ptr_to_u64(&info);
		if (sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) < 0) {
			close(fd);
			continue;
		}
		if (strcmp(name, module_name) == 0)
			return fd;
		close(fd);
	}
}

static int find_func_btf_id(const __u8 *data, size_t data_len,
			     const char *func_name,
			     __u32 base_str_off, __u32 type_id_bias,
			     __u32 *out_id)
{
	const struct btf_header *hdr = (const struct btf_header *)data;
	const __u8 *type_sec = data + hdr->hdr_len + hdr->type_off;
	const __u8 *str_sec = data + hdr->hdr_len + hdr->str_off;
	__u32 off = 0;
	__u32 type_id = 1;

	(void)data_len;

	while (off < hdr->type_len) {
		const struct btf_type *t =
			(const struct btf_type *)(type_sec + off);
		__u32 kind = (t->info >> 24) & 0x1f;
		__u32 vlen = t->info & 0xffff;

		off += sizeof(*t);
		if (kind == 12 /* BTF_KIND_FUNC */) {
			__u32 name_off = t->name_off - base_str_off;

			if (name_off < hdr->str_len &&
			    strcmp((const char *)str_sec + name_off,
				   func_name) == 0) {
				*out_id = type_id + type_id_bias;
				return 0;
			}
		}
		/* skip variable-length data for other kinds */
		switch (kind) {
		case 1: /* INT */
			off += 4;
			break;
		case 2: /* PTR */
		case 3: /* ARRAY */
			break;
		case 4: /* STRUCT */
		case 5: /* UNION */
			off += vlen * 12;
			break;
		case 6: /* ENUM */
			off += vlen * 8;
			break;
		case 8: /* FWD */
		case 10: /* VOLATILE */
		case 11: /* CONST */
		case 12: /* FUNC */
		case 14: /* FUNC_PROTO */
			break;
		case 13: /* RESTRICT */
			break;
		case 15: /* VAR */
			off += 4;
			break;
		case 16: /* DATASEC */
			off += vlen * 12;
			break;
		case 17: /* FLOAT */
			break;
		case 18: /* DECL_TAG */
			off += 4;
			break;
		case 19: /* TYPE_TAG */
		case 20: /* ENUM64 */
			off += vlen * 12;
			break;
		default:
			break;
		}
		type_id++;
	}
	return -1;
}

static int g_select_btf_fd = -1;
static __u32 g_select_btf_id;

static int discover_select_kinsn(void)
{
	__u32 type_id_bias, base_str_off;
	__u8 *data;
	size_t len;
	struct btf_header *hdr;

	if (get_vmlinux_type_count(&type_id_bias) < 0) {
		fprintf(stderr, "failed to read vmlinux BTF\n");
		return -1;
	}

	g_select_btf_fd = bpf_btf_get_fd_by_module_name("bpf_select");
	if (g_select_btf_fd < 0) {
		fprintf(stderr, "bpf_select module not loaded\n");
		return -1;
	}

	if (read_file("/sys/kernel/btf/bpf_select", &data, &len) < 0) {
		fprintf(stderr, "cannot read /sys/kernel/btf/bpf_select\n");
		return -1;
	}

	hdr = (struct btf_header *)data;
	base_str_off = hdr->str_off;

	if (find_func_btf_id(data, len, "bpf_select64",
			      base_str_off, type_id_bias,
			      &g_select_btf_id) < 0) {
		fprintf(stderr, "cannot find bpf_select64 BTF ID\n");
		free(data);
		return -1;
	}
	free(data);

	printf("  discovered: bpf_select64 btf_fd=%d btf_id=%u\n",
	       g_select_btf_fd, g_select_btf_id);
	return 0;
}

/* ------------------------------------------------------------------ */
/* Kinsn helpers                                                       */
/* ------------------------------------------------------------------ */

static const struct bpf_insn prog_ret_0[] = {
	BPF_MOV64_IMM(BPF_REG_0, 0),
	BPF_EXIT_INSN(),
};

static void patch_kinsn(struct bpf_insn *prog, size_t cnt, __u32 btf_id)
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

/* ------------------------------------------------------------------ */
/* Run plain BPF program and return result                             */
/* ------------------------------------------------------------------ */
static int run_bpf_prog(const struct bpf_insn *insns, __u32 cnt, __u32 *retval)
{
	char log_buf[LOG_BUF_SIZE];
	int fd;

	memset(log_buf, 0, sizeof(log_buf));
	fd = load_xdp_prog(insns, cnt, NULL, 0, log_buf, sizeof(log_buf));
	if (fd < 0) {
		fprintf(stderr, "    load failed: %s\n", log_buf);
		return -1;
	}
	if (test_run_xdp(fd, retval) < 0) {
		close(fd);
		return -1;
	}
	close(fd);
	return 0;
}

/* ------------------------------------------------------------------ */
/* Run kinsn program via REJIT and return result                       */
/* ------------------------------------------------------------------ */
static int run_kinsn_prog(struct bpf_insn *insns, __u32 cnt, __u32 *retval)
{
	char log_buf[LOG_BUF_SIZE];
	int fd_array[2] = BTF_FD_ARRAY(g_select_btf_fd);
	int prog_fd;

	patch_kinsn(insns, cnt, g_select_btf_id);

	memset(log_buf, 0, sizeof(log_buf));
	prog_fd = load_xdp_prog(prog_ret_0, ARRAY_SIZE(prog_ret_0),
				 NULL, 0, log_buf, sizeof(log_buf));
	if (prog_fd < 0) {
		fprintf(stderr, "    base load failed: %s\n", log_buf);
		return -1;
	}

	memset(log_buf, 0, sizeof(log_buf));
	if (rejit_xdp_prog(prog_fd, insns, cnt,
			    fd_array, ARRAY_SIZE(fd_array),
			    log_buf, sizeof(log_buf)) < 0) {
		fprintf(stderr, "    REJIT failed: %s\n", log_buf);
		close(prog_fd);
		return -1;
	}

	if (test_run_xdp(prog_fd, retval) < 0) {
		close(prog_fd);
		return -1;
	}
	close(prog_fd);
	return 0;
}

/* ------------------------------------------------------------------ */
/* Test: compare BPF proof sequence vs kinsn native for a given vector */
/* ------------------------------------------------------------------ */

struct select_test_vec {
	const char *name;
	__u8  dst;       /* BPF_REG_* for dst */
	__u8  treg;      /* BPF_REG_* for true_reg */
	__u8  freg;      /* BPF_REG_* for false_reg */
	__u8  cond;      /* BPF_REG_* for cond_reg */
	__s32 dst_val;   /* initial value of dst */
	__s32 treg_val;  /* initial value of true_reg */
	__s32 freg_val;  /* initial value of false_reg */
	__s32 cond_val;  /* initial value of cond_reg (only used if cond != dst) */
};

static int run_select_test(const struct select_test_vec *v)
{
	__u32 bpf_result, kinsn_result;

	/*
	 * Build BPF proof sequence:
	 *   MOV dst, dst_val
	 *   MOV treg, treg_val
	 *   MOV freg, freg_val
	 *   [MOV cond, cond_val]    -- only if cond != dst
	 *   JEQ cond, 0, +2
	 *   MOV dst, treg
	 *   JA +1
	 *   MOV dst, freg
	 *   MOV r0, dst             -- only if dst != r0
	 *   EXIT
	 */
	struct bpf_insn bpf_prog[12];
	int n = 0;

	bpf_prog[n++] = BPF_MOV64_IMM(v->dst, v->dst_val);
	if (v->treg != v->dst)
		bpf_prog[n++] = BPF_MOV64_IMM(v->treg, v->treg_val);
	if (v->freg != v->dst && v->freg != v->treg)
		bpf_prog[n++] = BPF_MOV64_IMM(v->freg, v->freg_val);
	if (v->cond != v->dst && v->cond != v->treg && v->cond != v->freg)
		bpf_prog[n++] = BPF_MOV64_IMM(v->cond, v->cond_val);

	/* proof sequence: JEQ cond,0,+2; MOV dst,treg; JA +1; MOV dst,freg */
	bpf_prog[n++] = BPF_JMP_IMM(BPF_JEQ, v->cond, 0, 2);
	bpf_prog[n++] = BPF_MOV64_REG(v->dst, v->treg);
	bpf_prog[n++] = BPF_JMP_A(1);
	bpf_prog[n++] = BPF_MOV64_REG(v->dst, v->freg);

	if (v->dst != BPF_REG_0)
		bpf_prog[n++] = BPF_MOV64_REG(BPF_REG_0, v->dst);
	bpf_prog[n++] = BPF_EXIT_INSN();

	if (run_bpf_prog(bpf_prog, n, &bpf_result) < 0) {
		TEST_FAIL(v->name, "BPF proof sequence load/run failed");
		return 1;
	}

	/*
	 * Build kinsn program:
	 *   MOV dst, dst_val
	 *   MOV treg, treg_val
	 *   MOV freg, freg_val
	 *   [MOV cond, cond_val]
	 *   SIDECAR(SELECT_PAYLOAD(dst, treg, freg, cond))
	 *   CALL_KINSN
	 *   MOV r0, dst
	 *   EXIT
	 */
	struct bpf_insn kinsn_prog[12];
	int k = 0;

	kinsn_prog[k++] = BPF_MOV64_IMM(v->dst, v->dst_val);
	if (v->treg != v->dst)
		kinsn_prog[k++] = BPF_MOV64_IMM(v->treg, v->treg_val);
	if (v->freg != v->dst && v->freg != v->treg)
		kinsn_prog[k++] = BPF_MOV64_IMM(v->freg, v->freg_val);
	if (v->cond != v->dst && v->cond != v->treg && v->cond != v->freg)
		kinsn_prog[k++] = BPF_MOV64_IMM(v->cond, v->cond_val);

	kinsn_prog[k++] = BPF_KINSN_SIDECAR(
		KINSN_SELECT_PAYLOAD(v->dst, v->treg, v->freg, v->cond));
	kinsn_prog[k++] = BPF_CALL_KINSN(0, 0);

	if (v->dst != BPF_REG_0)
		kinsn_prog[k++] = BPF_MOV64_REG(BPF_REG_0, v->dst);
	kinsn_prog[k++] = BPF_EXIT_INSN();

	if (run_kinsn_prog(kinsn_prog, k, &kinsn_result) < 0) {
		TEST_FAIL(v->name, "kinsn REJIT load/run failed");
		return 1;
	}

	if (bpf_result != kinsn_result) {
		char msg[256];

		snprintf(msg, sizeof(msg),
			 "MISMATCH: bpf=%u kinsn=%u "
			 "(dst=r%u treg=r%u freg=r%u cond=r%u "
			 "vals=%d/%d/%d/%d)",
			 bpf_result, kinsn_result,
			 v->dst, v->treg, v->freg, v->cond,
			 v->dst_val, v->treg_val, v->freg_val, v->cond_val);
		TEST_FAIL(v->name, msg);
		return 1;
	}

	TEST_PASS(v->name);
	return 0;
}

/* ------------------------------------------------------------------ */
/* Test vectors                                                        */
/* ------------------------------------------------------------------ */

static const struct select_test_vec vectors[] = {
	/*
	 * Core alias bug cases: dst == cond, dst != treg, dst != freg
	 */
	{
		.name = "dst_eq_cond__cond_nz_freg_zero",
		.dst = BPF_REG_0, .treg = BPF_REG_1,
		.freg = BPF_REG_2, .cond = BPF_REG_0,
		.dst_val = 42, .treg_val = 11, .freg_val = 0,
		/* cond=42!=0 → expect true_reg=11 */
	},
	{
		.name = "dst_eq_cond__cond_zero_freg_nz",
		.dst = BPF_REG_0, .treg = BPF_REG_1,
		.freg = BPF_REG_2, .cond = BPF_REG_0,
		.dst_val = 0, .treg_val = 11, .freg_val = 29,
		/* cond=0 → expect false_reg=29 */
	},
	{
		.name = "dst_eq_cond__both_nz",
		.dst = BPF_REG_0, .treg = BPF_REG_1,
		.freg = BPF_REG_2, .cond = BPF_REG_0,
		.dst_val = 42, .treg_val = 11, .freg_val = 29,
		/* cond=42!=0 → expect true_reg=11 */
	},
	/*
	 * Alias cases that should work even without the fix
	 */
	{
		.name = "dst_eq_cond_eq_treg",
		.dst = BPF_REG_1, .treg = BPF_REG_1,
		.freg = BPF_REG_2, .cond = BPF_REG_1,
		.dst_val = 42, .treg_val = 42, .freg_val = 0,
		/* cond=42!=0, dst==treg → expect dst stays 42 */
	},
	{
		.name = "dst_eq_cond_eq_freg",
		.dst = BPF_REG_2, .treg = BPF_REG_1,
		.freg = BPF_REG_2, .cond = BPF_REG_2,
		.dst_val = 0, .treg_val = 11, .freg_val = 0,
		/* cond=0, dst==freg → expect dst stays 0 */
	},
	/*
	 * Normal cases: dst != cond (should always work)
	 */
	{
		.name = "normal__cond_nz",
		.dst = BPF_REG_0, .treg = BPF_REG_1,
		.freg = BPF_REG_2, .cond = BPF_REG_3,
		.dst_val = 0, .treg_val = 11, .freg_val = 29, .cond_val = 1,
		/* cond=1!=0 → expect true_reg=11 */
	},
	{
		.name = "normal__cond_zero",
		.dst = BPF_REG_0, .treg = BPF_REG_1,
		.freg = BPF_REG_2, .cond = BPF_REG_3,
		.dst_val = 0, .treg_val = 11, .freg_val = 29, .cond_val = 0,
		/* cond=0 → expect false_reg=29 */
	},
	/*
	 * Higher register numbers with alias
	 */
	{
		.name = "dst_eq_cond_r6__cond_nz_freg_zero",
		.dst = BPF_REG_6, .treg = BPF_REG_7,
		.freg = BPF_REG_8, .cond = BPF_REG_6,
		.dst_val = 99, .treg_val = 55, .freg_val = 0,
		/* cond=99!=0 → expect 55 */
	},
	{
		.name = "dst_eq_cond_r6__cond_zero_freg_nz",
		.dst = BPF_REG_6, .treg = BPF_REG_7,
		.freg = BPF_REG_8, .cond = BPF_REG_6,
		.dst_val = 0, .treg_val = 55, .freg_val = 77,
		/* cond=0 → expect 77 */
	},
};

/* ------------------------------------------------------------------ */
/* Main                                                                */
/* ------------------------------------------------------------------ */

int main(void)
{
	size_t i;
	int ret = 0;

	printf("[select_alias] BPF proof vs kinsn native comparison tests\n");

	if (discover_select_kinsn() < 0) {
		fprintf(stderr, "FATAL: cannot discover bpf_select kinsn\n");
		return 1;
	}

	for (i = 0; i < ARRAY_SIZE(vectors); i++)
		ret |= run_select_test(&vectors[i]);

	printf("\nSummary: %d passed, %d failed\n", g_pass, g_fail);

	if (g_select_btf_fd >= 0)
		close(g_select_btf_fd);

	return ret || g_fail ? 1 : 0;
}
