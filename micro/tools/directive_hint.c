// SPDX-License-Identifier: GPL-2.0-only
#include <bpf/libbpf.h>
#include <linux/bpf.h>

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BPF_JIT_DIRECTIVE_MAGIC 0x4a445243U
#define BPF_JIT_DIRECTIVE_VERSION 1

#define BPF_JIT_DIRECTIVE_WIDE_LOAD 1

#define BPF_JIT_WIDE_LOAD_MAX_WIDTH 8
#define BPF_JIT_WIDE_LOAD_PATTERN_LEN(width) ((width) * 3 - 2)

struct bpf_jit_directive_hdr {
	uint32_t magic;
	uint16_t version;
	uint16_t rec_size;
	uint32_t rec_cnt;
	uint32_t insn_cnt;
};

struct bpf_jit_directive_rec {
	uint16_t kind;
	uint16_t reserved;
	uint32_t site_idx;
	uint64_t payload;
};

struct bpf_jit_directive_wide_load {
	uint32_t width;
	uint32_t reserved;
};

struct wide_load_expr {
	uint8_t lane_mask;
	uint8_t base_reg;
	int16_t mem_off[BPF_JIT_WIDE_LOAD_MAX_WIDTH];
	bool valid;
};

_Static_assert(sizeof(struct bpf_jit_directive_hdr) == 16, "unexpected blob header size");
_Static_assert(sizeof(struct bpf_jit_directive_rec) == 16, "unexpected record size");
_Static_assert(sizeof(struct bpf_jit_directive_wide_load) == 8, "unexpected payload size");

static void die_errno(const char *what)
{
	fprintf(stderr, "%s: %s\n", what, strerror(errno));
	exit(1);
}

static void die(const char *what)
{
	fprintf(stderr, "%s\n", what);
	exit(1);
}

static bool is_direct_byte_load(const struct bpf_insn *insn)
{
	return insn->code == (BPF_LDX | BPF_MEM | BPF_B) &&
	       insn->dst_reg != insn->src_reg &&
	       insn->imm == 0;
}

static bool is_lsh_imm(const struct bpf_insn *insn)
{
	return insn->code == (BPF_ALU64 | BPF_LSH | BPF_K) &&
	       insn->src_reg == 0 &&
	       insn->off == 0;
}

static bool is_or_reg(const struct bpf_insn *insn)
{
	return insn->code == (BPF_ALU64 | BPF_OR | BPF_X) &&
	       insn->dst_reg != insn->src_reg &&
	       insn->off == 0 &&
	       insn->imm == 0;
}

static void expr_from_load(struct wide_load_expr *expr, const struct bpf_insn *insn)
{
	memset(expr, 0, sizeof(*expr));
	expr->valid = true;
	expr->lane_mask = 1U;
	expr->base_reg = insn->src_reg;
	expr->mem_off[0] = insn->off;
}

static bool expr_shift(struct wide_load_expr *expr, const struct bpf_insn *insn, uint32_t width)
{
	uint32_t shift_bytes;
	int16_t off;

	if (!expr->valid || expr->lane_mask != 1U || !is_lsh_imm(insn))
		return false;
	if (insn->imm <= 0 || insn->imm % 8 != 0)
		return false;

	shift_bytes = (uint32_t)insn->imm / 8U;
	if (shift_bytes >= width)
		return false;

	off = expr->mem_off[0];
	expr->lane_mask = (uint8_t)(1U << shift_bytes);
	expr->mem_off[shift_bytes] = off;
	return true;
}

static bool expr_merge(struct wide_load_expr *dst, const struct wide_load_expr *src, uint32_t width)
{
	uint32_t full_mask = width == 8 ? 0xffU : ((1U << width) - 1U);
	uint8_t merged = dst->lane_mask | src->lane_mask;
	uint32_t lane;

	if (!dst->valid || !src->valid || dst->base_reg != src->base_reg)
		return false;
	if (dst->lane_mask & src->lane_mask)
		return false;
	if (((uint32_t)merged & ~full_mask) != 0)
		return false;

	for (lane = 0; lane < width; lane++) {
		if ((src->lane_mask & (1U << lane)) == 0)
			continue;
		dst->mem_off[lane] = src->mem_off[lane];
	}
	dst->lane_mask = merged;
	return true;
}

static bool expr_complete(const struct wide_load_expr *expr, uint32_t width)
{
	uint32_t full_mask = width == 8 ? 0xffU : ((1U << width) - 1U);
	uint32_t lane;
	int16_t base_off;

	if (!expr->valid || expr->lane_mask != full_mask)
		return false;

	base_off = expr->mem_off[0];
	for (lane = 1; lane < width; lane++) {
		if (expr->mem_off[lane] != (int16_t)(base_off + (int16_t)lane))
			return false;
	}
	return true;
}

static size_t match_wide_load_pattern(const struct bpf_insn *insns, size_t insn_cnt,
				      size_t start_idx, uint32_t width)
{
	struct wide_load_expr exprs[MAX_BPF_REG] = {};
	size_t limit = start_idx + BPF_JIT_WIDE_LOAD_PATTERN_LEN(width);
	size_t pos;

	if (limit > insn_cnt)
		limit = insn_cnt;

	for (pos = start_idx; pos < limit; pos++) {
		const struct bpf_insn *insn = &insns[pos];

		if (is_direct_byte_load(insn)) {
			expr_from_load(&exprs[insn->dst_reg], insn);
			continue;
		}

		if (is_lsh_imm(insn)) {
			if (!expr_shift(&exprs[insn->dst_reg], insn, width))
				return 0;
			continue;
		}

		if (is_or_reg(insn)) {
			if (!expr_merge(&exprs[insn->dst_reg], &exprs[insn->src_reg], width))
				return 0;
			if (expr_complete(&exprs[insn->dst_reg], width))
				return pos - start_idx + 1;
			continue;
		}

		return 0;
	}

	return 0;
}

static struct bpf_program *find_program(struct bpf_object *obj, const char *program_name)
{
	struct bpf_program *prog = NULL;

	if (!program_name) {
		prog = bpf_object__next_program(obj, NULL);
		if (!prog)
			die("no BPF program found in object");
		return prog;
	}

	while ((prog = bpf_object__next_program(obj, prog)) != NULL) {
		const char *name = bpf_program__name(prog);

		if (name && strcmp(name, program_name) == 0)
			return prog;
	}

	die("requested BPF program not found in object");
	return NULL;
}

static const char *default_output_path(const char *object_path)
{
	static char path[4096];
	size_t len = strlen(object_path);

	if (len + strlen(".directive.bin") + 1 > sizeof(path))
		die("default output path is too long");

	snprintf(path, sizeof(path), "%s.directive.bin", object_path);
	return path;
}

static uint64_t pack_wide_load_payload(uint32_t width)
{
	struct bpf_jit_directive_wide_load payload = {
		.width = width,
		.reserved = 0,
	};
	uint64_t raw = 0;

	memcpy(&raw, &payload, sizeof(payload));
	return raw;
}

int main(int argc, char **argv)
{
	const char *object_path;
	const char *program_name = NULL;
	const char *output_path;
	struct bpf_object *obj;
	struct bpf_program *prog;
	const struct bpf_insn *insns;
	size_t insn_cnt, rec_cap, rec_cnt = 0, idx = 0;
	struct bpf_jit_directive_rec *recs;
	struct bpf_object_open_opts open_opts = {};
	struct bpf_jit_directive_hdr hdr;
	FILE *out;
	int err;

	if (argc < 2 || argc > 4) {
		fprintf(stderr, "usage: %s <program.bpf.o> [program_name] [output_blob]\n", argv[0]);
		return 1;
	}

	object_path = argv[1];
	if (argc >= 3)
		program_name = argv[2];
	output_path = argc >= 4 ? argv[3] : default_output_path(object_path);

	open_opts.sz = sizeof(open_opts);
	obj = bpf_object__open_file(object_path, &open_opts);
	err = libbpf_get_error(obj);
	if (err)
		die("bpf_object__open_file failed");

	prog = find_program(obj, program_name);
	insns = bpf_program__insns(prog);
	insn_cnt = bpf_program__insn_cnt(prog);
	if (!insns || insn_cnt == 0)
		die("selected program has no BPF instructions");

	rec_cap = insn_cnt;
	recs = calloc(rec_cap, sizeof(*recs));
	if (!recs)
		die_errno("calloc");

	while (idx < insn_cnt) {
		size_t pattern_len = 0;
		uint32_t width = 0;

		if (is_direct_byte_load(&insns[idx])) {
			pattern_len = match_wide_load_pattern(insns, insn_cnt, idx, 8);
			if (pattern_len)
				width = 8;
			else {
				pattern_len = match_wide_load_pattern(insns, insn_cnt, idx, 4);
				if (pattern_len)
					width = 4;
			}
		}

		if (pattern_len) {
			recs[rec_cnt].kind = BPF_JIT_DIRECTIVE_WIDE_LOAD;
			recs[rec_cnt].reserved = 0;
			recs[rec_cnt].site_idx = (uint32_t)idx;
			recs[rec_cnt].payload = pack_wide_load_payload(width);
			rec_cnt++;
			idx += pattern_len;
			continue;
		}

		idx++;
	}

	hdr.magic = BPF_JIT_DIRECTIVE_MAGIC;
	hdr.version = BPF_JIT_DIRECTIVE_VERSION;
	hdr.rec_size = (uint16_t)sizeof(struct bpf_jit_directive_rec);
	hdr.rec_cnt = (uint32_t)rec_cnt;
	hdr.insn_cnt = (uint32_t)insn_cnt;

	out = fopen(output_path, "wb");
	if (!out)
		die_errno("fopen");

	if (fwrite(&hdr, sizeof(hdr), 1, out) != 1)
		die_errno("fwrite header");
	if (rec_cnt != 0 && fwrite(recs, sizeof(*recs), rec_cnt, out) != rec_cnt)
		die_errno("fwrite records");
	if (fclose(out) != 0)
		die_errno("fclose");

	printf("%s %zu\n", output_path, rec_cnt);

	free(recs);
	bpf_object__close(obj);
	return 0;
}
