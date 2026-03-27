#ifndef REJIT_HOTSWAP_COMMON_H
#define REJIT_HOTSWAP_COMMON_H

#include <errno.h>
#include <linux/bpf.h>
#include <linux/unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ptr_to_u64(ptr) ((__u64)(uintptr_t)(ptr))

static inline int hotswap_sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr,
				  unsigned int size)
{
	return syscall(__NR_bpf, cmd, attr, size);
}

static inline int hotswap_rejit_prog(int prog_fd,
				     const struct bpf_insn *insns,
				     __u32 insn_cnt, char *log_buf,
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
	return hotswap_sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
}

static inline int hotswap_rejit_prog_fd_array(int prog_fd,
					      const struct bpf_insn *insns,
					      __u32 insn_cnt,
					      const int *fd_array,
					      __u32 fd_array_cnt,
					      char *log_buf,
					      size_t log_buf_sz)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.rejit.prog_fd = prog_fd;
	attr.rejit.insn_cnt = insn_cnt;
	attr.rejit.insns = ptr_to_u64(insns);
	attr.rejit.fd_array = ptr_to_u64(fd_array);
	attr.rejit.fd_array_cnt = fd_array_cnt;
	attr.rejit.log_level = 1;
	attr.rejit.log_buf = ptr_to_u64(log_buf);
	attr.rejit.log_size = log_buf_sz;
	return hotswap_sys_bpf(BPF_PROG_REJIT, &attr, sizeof(attr));
}

static inline int hotswap_get_prog_info(int prog_fd, struct bpf_prog_info *info,
					__u32 *info_len)
{
	union bpf_attr attr;

	memset(&attr, 0, sizeof(attr));
	attr.info.bpf_fd = prog_fd;
	attr.info.info = ptr_to_u64(info);
	attr.info.info_len = *info_len;
	if (hotswap_sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) < 0)
		return -1;

	*info_len = attr.info.info_len;
	return 0;
}

static inline int hotswap_get_original_insns(int prog_fd,
					     struct bpf_insn **out_insns)
{
	struct bpf_prog_info info = {};
	struct bpf_insn *insns;
	__u32 info_len = sizeof(info);
	__u32 insn_cnt;
	bool have_orig = false;

	if (hotswap_get_prog_info(prog_fd, &info, &info_len) < 0)
		return -1;

	if (info.orig_prog_len) {
		insn_cnt = info.orig_prog_len / sizeof(*insns);
		have_orig = true;
	} else if (info.xlated_prog_len) {
		insn_cnt = info.xlated_prog_len / sizeof(*insns);
	} else {
		errno = ENOENT;
		return -1;
	}

	insns = calloc(insn_cnt, sizeof(*insns));
	if (!insns)
		return -1;

	memset(&info, 0, sizeof(info));
	info_len = sizeof(info);
	if (have_orig) {
		info.orig_prog_len = insn_cnt * sizeof(*insns);
		info.orig_prog_insns = ptr_to_u64(insns);
	} else {
		info.xlated_prog_len = insn_cnt * sizeof(*insns);
		info.xlated_prog_insns = ptr_to_u64(insns);
	}

	if (hotswap_get_prog_info(prog_fd, &info, &info_len) < 0) {
		free(insns);
		return -1;
	}

	*out_insns = insns;
	return (int)insn_cnt;
}

static inline int hotswap_patch_return_imm(struct bpf_insn *insns, int insn_cnt,
					   __s32 imm)
{
	int i;

	for (i = 0; i + 1 < insn_cnt; i++) {
		if (insns[i + 1].code != (BPF_JMP | BPF_EXIT))
			continue;
		if (insns[i].dst_reg != BPF_REG_0)
			continue;
		if (insns[i].code != (BPF_ALU64 | BPF_MOV | BPF_K) &&
		    insns[i].code != (BPF_ALU | BPF_MOV | BPF_K))
			continue;

		insns[i].imm = imm;
		return 0;
	}

	errno = ENOENT;
	return -1;
}

static inline bool hotswap_is_mov_imm_insn(const struct bpf_insn *insn)
{
	return insn->code == (BPF_ALU64 | BPF_MOV | BPF_K) ||
	       insn->code == (BPF_ALU | BPF_MOV | BPF_K);
}

static inline bool hotswap_is_ldimm64_insn(const struct bpf_insn *insn)
{
	return insn->code == (BPF_LD | BPF_DW | BPF_IMM);
}

static inline bool hotswap_is_mov_reg_insn(const struct bpf_insn *insn)
{
	return insn->code == (BPF_ALU64 | BPF_MOV | BPF_X) ||
	       insn->code == (BPF_ALU | BPF_MOV | BPF_X);
}

static inline bool hotswap_is_add_imm_insn(const struct bpf_insn *insn)
{
	return insn->code == (BPF_ALU64 | BPF_ADD | BPF_K) ||
	       insn->code == (BPF_ALU | BPF_ADD | BPF_K);
}

static inline int hotswap_patch_scalar_imm(struct bpf_insn *insns, int insn_cnt,
					   int def_idx, __u8 reg, __s32 imm)
{
	int j;

	for (j = def_idx; j >= 0; j--) {
		if (hotswap_is_ldimm64_insn(&insns[j])) {
			__s64 imm64 = imm;

			if (insns[j].dst_reg != reg)
				continue;
			if (j + 1 >= insn_cnt)
				break;

			insns[j].imm = (__s32)imm64;
			insns[j + 1].imm = (__s32)((__u64)imm64 >> 32);
			return 0;
		}

		if (insns[j].dst_reg != reg)
			continue;

		if (hotswap_is_mov_imm_insn(&insns[j])) {
			insns[j].imm = imm;
			return 0;
		}

		if (hotswap_is_mov_reg_insn(&insns[j])) {
			reg = insns[j].src_reg;
			continue;
		}

		break;
	}

	errno = ENOENT;
	return -1;
}

static inline int hotswap_find_stack_slot_offset(const struct bpf_insn *insns,
						 int def_idx, __u8 reg,
						 __s16 *stack_off)
{
	__s32 offset = 0;
	int j;

	for (j = def_idx; j >= 0; j--) {
		if (insns[j].dst_reg != reg)
			continue;

		if (hotswap_is_add_imm_insn(&insns[j])) {
			offset += insns[j].imm;
			continue;
		}

		if (hotswap_is_mov_reg_insn(&insns[j])) {
			if (insns[j].src_reg == BPF_REG_10) {
				*stack_off = (__s16)offset;
				return 0;
			}

			reg = insns[j].src_reg;
			continue;
		}

		break;
	}

	errno = ENOENT;
	return -1;
}

static inline int hotswap_patch_atomic_add_imm(struct bpf_insn *insns,
					       int insn_cnt, __s16 off,
					       __s32 imm)
{
	int i;

	for (i = 0; i < insn_cnt; i++) {
		__u8 reg;
		int j;

		if (insns[i].code != (BPF_STX | BPF_ATOMIC | BPF_DW))
			continue;
		if (insns[i].off != off)
			continue;

		reg = insns[i].src_reg;
		j = hotswap_patch_scalar_imm(insns, insn_cnt, i - 1, reg, imm);
		if (!j)
			return 0;
	}

	errno = ENOENT;
	return -1;
}

static inline int hotswap_patch_stack_map_key(struct bpf_insn *insns,
					      int insn_cnt, __s32 key)
{
	int i;

	for (i = 0; i < insn_cnt; i++) {
		__s16 stack_off;
		int j;

		if (insns[i].code != (BPF_JMP | BPF_CALL) ||
		    insns[i].imm != BPF_FUNC_map_lookup_elem)
			continue;

		if (hotswap_find_stack_slot_offset(insns, i - 1, BPF_REG_2,
						   &stack_off) < 0)
			continue;

		for (j = i - 1; j >= 0; j--) {
			if (insns[j].dst_reg != BPF_REG_10 || insns[j].off != stack_off)
				continue;

			if (insns[j].code == (BPF_ST | BPF_MEM | BPF_W)) {
				insns[j].imm = key;
				return 0;
			}

			if (insns[j].code != (BPF_STX | BPF_MEM | BPF_W))
				continue;

			if (hotswap_patch_scalar_imm(insns, insn_cnt, j - 1,
						     insns[j].src_reg, key) == 0)
				return 0;
		}
	}

	errno = ENOENT;
	return -1;
}

static inline int hotswap_patch_map_value_store_imm(struct bpf_insn *insns,
						    int insn_cnt, __s32 value)
{
	int i, j;

	for (i = 0; i < insn_cnt; i++) {
		if (insns[i].code != (BPF_STX | BPF_MEM | BPF_DW))
			continue;
		if (insns[i].dst_reg == BPF_REG_10 || insns[i].off != 0)
			continue;

		for (j = i - 1; j >= 0 && j >= i - 4; j--) {
			if (insns[j].dst_reg != insns[i].src_reg)
				continue;
			if (insns[j].code != (BPF_ALU64 | BPF_MOV | BPF_K) &&
			    insns[j].code != (BPF_ALU | BPF_MOV | BPF_K))
				continue;

			insns[j].imm = value;
			return 0;
		}
	}

	errno = ENOENT;
	return -1;
}

#endif
