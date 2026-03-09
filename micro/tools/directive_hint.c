// SPDX-License-Identifier: GPL-2.0-only
#include "micro_exec.hpp"

#include <linux/bpf.h>

#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <optional>
#include <string>

#define BPF_JIT_DIRECTIVE_MAGIC 0x4a445243U
#define BPF_JIT_DIRECTIVE_VERSION 2

#define BPF_JIT_DIRECTIVE_CMOV_SELECT 1

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

struct bpf_jit_directive_cmov_select {
    uint32_t flags;
    uint32_t reserved;
};

static_assert(sizeof(struct bpf_jit_directive_hdr) == 16, "unexpected blob header size");
static_assert(sizeof(struct bpf_jit_directive_rec) == 16, "unexpected record size");
static_assert(sizeof(struct bpf_jit_directive_cmov_select) == 8, "unexpected payload size");

[[noreturn]] static void die_errno(const char *what)
{
    std::fprintf(stderr, "%s: %s\n", what, std::strerror(errno));
    std::exit(1);
}

[[noreturn]] static void die(const char *what)
{
    std::fprintf(stderr, "%s\n", what);
    std::exit(1);
}

static bool is_cmov_cond_jump(const struct bpf_insn *insn)
{
    uint8_t cls = BPF_CLASS(insn->code);

    if (cls != BPF_JMP && cls != BPF_JMP32) {
        return false;
    }
    if (BPF_SRC(insn->code) != BPF_X && BPF_SRC(insn->code) != BPF_K) {
        return false;
    }

    switch (BPF_OP(insn->code)) {
    case BPF_JEQ:
    case BPF_JNE:
    case BPF_JGT:
    case BPF_JLT:
    case BPF_JGE:
    case BPF_JLE:
    case BPF_JSGT:
    case BPF_JSLT:
    case BPF_JSGE:
    case BPF_JSLE:
        return true;
    default:
        return false;
    }
}

static bool is_simple_mov(const struct bpf_insn *insn)
{
    uint8_t cls = BPF_CLASS(insn->code);

    if ((cls != BPF_ALU && cls != BPF_ALU64) || BPF_OP(insn->code) != BPF_MOV) {
        return false;
    }
    if (insn->off != 0) {
        return false;
    }

    switch (BPF_SRC(insn->code)) {
    case BPF_X:
        return insn->imm == 0;
    case BPF_K:
        return insn->src_reg == 0;
    default:
        return false;
    }
}

static bool match_cmov_select_diamond(const struct bpf_insn *insns, size_t insn_cnt,
                                      size_t idx)
{
    const struct bpf_insn *jmp_insn, *fallthrough_insn, *ja_insn, *target_insn;
    uint8_t mov_cls;

    if (idx + 3 >= insn_cnt) {
        return false;
    }

    jmp_insn = &insns[idx];
    fallthrough_insn = &insns[idx + 1];
    ja_insn = &insns[idx + 2];
    target_insn = &insns[idx + 3];

    if (!is_cmov_cond_jump(jmp_insn) || jmp_insn->off != 2) {
        return false;
    }
    if (!is_simple_mov(fallthrough_insn) || !is_simple_mov(target_insn)) {
        return false;
    }
    if (ja_insn->code != (BPF_JMP | BPF_JA) || ja_insn->off != 1 ||
        ja_insn->imm != 0 || ja_insn->dst_reg != 0 || ja_insn->src_reg != 0) {
        return false;
    }
    if (fallthrough_insn->dst_reg != target_insn->dst_reg) {
        return false;
    }

    mov_cls = BPF_CLASS(fallthrough_insn->code);
    if (mov_cls != BPF_CLASS(target_insn->code)) {
        return false;
    }

    if (BPF_CLASS(jmp_insn->code) == BPF_JMP) {
        return mov_cls == BPF_ALU64;
    }

    return mov_cls == BPF_ALU;
}

static bool match_cmov_select_compact(const struct bpf_insn *insns, size_t insn_cnt,
                                      size_t idx)
{
    const struct bpf_insn *default_insn, *jmp_insn, *override_insn;
    uint8_t mov_cls;

    if (idx == 0 || idx + 1 >= insn_cnt) {
        return false;
    }

    default_insn = &insns[idx - 1];
    jmp_insn = &insns[idx];
    override_insn = &insns[idx + 1];

    if (!is_simple_mov(default_insn) || !is_simple_mov(override_insn)) {
        return false;
    }
    if (!is_cmov_cond_jump(jmp_insn) || jmp_insn->off != 1) {
        return false;
    }
    if (default_insn->dst_reg != override_insn->dst_reg) {
        return false;
    }

    mov_cls = BPF_CLASS(default_insn->code);
    if (mov_cls != BPF_CLASS(override_insn->code)) {
        return false;
    }

    if (BPF_CLASS(jmp_insn->code) == BPF_JMP) {
        return mov_cls == BPF_ALU64;
    }

    return mov_cls == BPF_ALU;
}

static std::string default_output_path(const char *object_path)
{
    const std::string path = std::string(object_path) + ".directive.bin";
    if (path.size() >= 4096) {
        die("default output path is too long");
    }
    return path;
}

static uint64_t pack_cmov_select_payload()
{
    struct bpf_jit_directive_cmov_select payload = {
        .flags = 0,
        .reserved = 0,
    };
    uint64_t raw = 0;

    std::memcpy(&raw, &payload, sizeof(payload));
    return raw;
}

int main(int argc, char **argv)
{
    const char *object_path;
    std::optional<std::string> program_name;
    std::string output_path;
    program_image image;
    const struct bpf_insn *insns;
    size_t insn_cnt, rec_cap, rec_cnt = 0, idx = 0;
    struct bpf_jit_directive_rec *recs;
    struct bpf_jit_directive_hdr hdr;
    FILE *out;

    if (argc < 2 || argc > 4) {
        std::fprintf(stderr, "usage: %s <program.bpf.o> [program_name] [output_blob]\n", argv[0]);
        return 1;
    }

    object_path = argv[1];
    if (argc >= 3) {
        program_name = std::string(argv[2]);
    }
    output_path = argc >= 4 ? argv[3] : default_output_path(object_path);

    image = load_program_image(std::filesystem::path(object_path), program_name);
    if (image.code.size() % sizeof(bpf_insn) != 0) {
        die("selected program has unaligned BPF instructions");
    }

    insns = reinterpret_cast<const struct bpf_insn *>(image.code.data());
    insn_cnt = image.code.size() / sizeof(struct bpf_insn);
    if (insn_cnt == 0) {
        die("selected program has no BPF instructions");
    }

    rec_cap = insn_cnt;
    recs = static_cast<struct bpf_jit_directive_rec *>(std::calloc(rec_cap, sizeof(*recs)));
    if (!recs) {
        die_errno("calloc");
    }

    while (idx < insn_cnt) {
        if (match_cmov_select_diamond(insns, insn_cnt, idx)) {
            recs[rec_cnt].kind = BPF_JIT_DIRECTIVE_CMOV_SELECT;
            recs[rec_cnt].reserved = 0;
            recs[rec_cnt].site_idx = static_cast<uint32_t>(idx);
            recs[rec_cnt].payload = pack_cmov_select_payload();
            rec_cnt++;
            idx += 4;
            continue;
        }

        if (match_cmov_select_compact(insns, insn_cnt, idx)) {
            recs[rec_cnt].kind = BPF_JIT_DIRECTIVE_CMOV_SELECT;
            recs[rec_cnt].reserved = 0;
            recs[rec_cnt].site_idx = static_cast<uint32_t>(idx);
            recs[rec_cnt].payload = pack_cmov_select_payload();
            rec_cnt++;
            idx += 2;
            continue;
        }

        idx++;
    }

    hdr.magic = BPF_JIT_DIRECTIVE_MAGIC;
    hdr.version = BPF_JIT_DIRECTIVE_VERSION;
    hdr.rec_size = static_cast<uint16_t>(sizeof(struct bpf_jit_directive_rec));
    hdr.rec_cnt = static_cast<uint32_t>(rec_cnt);
    hdr.insn_cnt = static_cast<uint32_t>(insn_cnt);

    out = std::fopen(output_path.c_str(), "wb");
    if (!out) {
        die_errno("fopen");
    }

    if (std::fwrite(&hdr, sizeof(hdr), 1, out) != 1) {
        die_errno("fwrite header");
    }
    if (rec_cnt != 0 && std::fwrite(recs, sizeof(*recs), rec_cnt, out) != rec_cnt) {
        die_errno("fwrite records");
    }
    if (std::fclose(out) != 0) {
        die_errno("fclose");
    }

    std::printf("%s %zu\n", output_path.c_str(), rec_cnt);

    std::free(recs);
    return 0;
}
