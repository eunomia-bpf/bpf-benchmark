#pragma once

struct SourceHelperCall {
    int helper_id;
    int map_fd;
    NativeMapShape dynamic_map_shape;
};

struct SourceMapBinding {
    int map_fd = -1;
    NativeMapShape dynamic_map_shape;
};

/* Walk a BPF program's original (pre-verifier) bytecode and identify every
 * helper call in source order, plus the map fd currently bound to that
 * helper's map argument register when the call occurs. map_fd is -1 when the
 * binding is ambiguous. If a previous map-in-map lookup returned a verifier
 * tracked inner map pointer, dynamic_map_shape records the inner map shape so
 * the next map_lookup_elem call can use the same map-specific lowering as the
 * kernel JIT.
 *
 * Tracking is intentionally minimal:
 *   - LD_IMM64 with src_reg=BPF_PSEUDO_MAP_FD binds dst_reg -> imm (map fd).
 *   - ALU64|MOV|X copies the binding from src_reg to dst_reg.
 *   - map-in-map lookup return in R0 carries a known inner-map shape when the
 *     outer map shape is recognized.
 *   - Any other write to a register clears that register's binding.
 *   - CALL clobbers r0..r5.
 * This matches the simple "load map fd into r1 just before the call"
 * pattern clang emits at -O2 for the test programs and most real
 * BPF code. Anything fancier (spill/reload via stack, conditional
 * map selection) falls through to fd=-1 -> no inline. */
std::vector<SourceHelperCall> collect_source_helper_calls(
    const struct bpf_insn *insns,
    size_t cnt,
    const std::unordered_map<int, MapMeta> *meta_by_fd = nullptr)
{
    std::vector<SourceHelperCall> sites;
    SourceMapBinding reg_map[11];
    for (size_t i = 0; i < cnt; i++) {
        const struct bpf_insn &in = insns[i];
        uint8_t code = in.code;
        if (code == (BPF_LD | BPF_DW | BPF_IMM)) {
            if (in.dst_reg < 11) {
                reg_map[in.dst_reg] = SourceMapBinding{};
                if (in.src_reg == BPF_PSEUDO_MAP_FD) {
                    reg_map[in.dst_reg].map_fd = (int)in.imm;
                }
            }
            i++; /* skip second slot (high 32 bits of imm64) */
            continue;
        }
        if (code == (BPF_ALU64 | BPF_MOV | BPF_X)) {
            if (in.dst_reg < 11 && in.src_reg < 11) {
                reg_map[in.dst_reg] = reg_map[in.src_reg];
            } else if (in.dst_reg < 11) {
                reg_map[in.dst_reg] = SourceMapBinding{};
            }
            continue;
        }
        if (code == (BPF_JMP | BPF_CALL)) {
            if (in.src_reg == BPF_PSEUDO_CALL ||
                in.src_reg == BPF_PSEUDO_KFUNC_CALL ||
                in.src_reg == BPF_PSEUDO_KINSN_CALL) {
                for (int r = 0; r <= 5; r++) reg_map[r] = SourceMapBinding{};
                continue;
            }
            if (in.src_reg == 0 && in.imm == kLibbpfCoreBadRelocPoison) {
                for (int r = 0; r <= 5; r++) reg_map[r] = SourceMapBinding{};
                continue;
            }
            if (in.src_reg != 0) {
                fail("native_kernel: unsupported non-helper BPF call src_reg="
                     + std::to_string(static_cast<unsigned>(in.src_reg)));
            }
            int map_arg_reg = 1;
            if (in.imm == BPF_FUNC_tail_call ||
                in.imm == BPF_FUNC_perf_event_output) {
                map_arg_reg = 2;
            }
            SourceMapBinding map_binding = reg_map[map_arg_reg];
            sites.push_back(SourceHelperCall{
                in.imm,
                map_binding.map_fd,
                map_binding.dynamic_map_shape,
            });

            NativeMapShape return_shape;
            if (in.imm == BPF_FUNC_map_lookup_elem &&
                map_binding.map_fd >= 0 &&
                meta_by_fd) {
                auto meta_it = meta_by_fd->find(map_binding.map_fd);
                if (meta_it != meta_by_fd->end()) {
                    return_shape = inner_map_shape_for_outer_map(meta_it->second);
                }
            }

            for (int r = 0; r <= 5; r++) reg_map[r] = SourceMapBinding{};
            if (has_native_map_shape(return_shape)) {
                reg_map[0].dynamic_map_shape = return_shape;
            }
            continue;
        }
        /* Conservative: invalidate dst_reg for any other ALU/LDX/JMP-class
         * insn that writes a reg. Stores (BPF_STX/BPF_ST) don't write
         * dst_reg, conditional jumps don't either. */
        uint8_t cls = BPF_CLASS(code);
        if (cls == BPF_ALU || cls == BPF_ALU64 || cls == BPF_LDX) {
            if (in.dst_reg < 11) reg_map[in.dst_reg] = SourceMapBinding{};
        }
    }
    return sites;
}

std::vector<int> collect_source_map_fds(const struct bpf_insn *insns, size_t cnt)
{
    std::vector<int> fds;
    std::unordered_set<int> seen;
    for (size_t i = 0; i < cnt; i++) {
        const struct bpf_insn &in = insns[i];
        if (in.code == (BPF_LD | BPF_DW | BPF_IMM)) {
            if (in.src_reg == BPF_PSEUDO_MAP_FD ||
                in.src_reg == BPF_PSEUDO_MAP_VALUE) {
                int fd = static_cast<int>(in.imm);
                if (fd >= 0 && seen.insert(fd).second) {
                    fds.push_back(fd);
                }
            }
            i++; /* skip second slot (high 32 bits of imm64) */
        }
    }
    return fds;
}
