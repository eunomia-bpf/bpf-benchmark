#pragma once

struct SourceHelperCall {
    int helper_id;
    int map_fd;
    NativeMapShape dynamic_map_shape;
    bool key_known;
    uint32_t key;
};

struct SourceMapBinding {
    int map_fd = -1;
    NativeMapShape dynamic_map_shape;
};

bool source_map_binding_has_value(const SourceMapBinding &binding)
{
    return binding.map_fd >= 0 || has_native_map_shape(binding.dynamic_map_shape);
}

size_t bpf_mem_access_size(uint8_t code)
{
    switch (BPF_SIZE(code)) {
    case BPF_B:
        return 1;
    case BPF_H:
        return 2;
    case BPF_W:
        return 4;
    case BPF_DW:
        return 8;
    default:
        return 0;
    }
}

void clear_overlapping_stack_bindings(
    std::unordered_map<int16_t, SourceMapBinding> &stack_map,
    int16_t off,
    size_t size)
{
    if (size == 0) {
        stack_map.clear();
        return;
    }

    const int start = off;
    const int end = start + static_cast<int>(size);
    for (auto it = stack_map.begin(); it != stack_map.end();) {
        const int slot_start = it->first;
        const int slot_end = slot_start + 8;
        if (slot_start < end && start < slot_end) {
            it = stack_map.erase(it);
        } else {
            ++it;
        }
    }
}

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
 *   - 64-bit stack spill/reload through r10 preserves bindings; any
 *     overlapping stack write clears the affected binding.
 *   - map-in-map lookup return in R0 carries a known inner-map shape when the
 *     outer map shape is recognized.
 *   - Any other write to a register clears that register's binding.
 *   - CALL clobbers r0..r5.
 * This matches the common "load map fd into r1 just before the call" pattern
 * and the map-in-map pointer spill/reload shape clang emits in larger
 * programs. Anything fancier (conditional map selection, non-stack memory
 * transport) falls through to fd=-1 -> no inline. */
std::vector<SourceHelperCall> collect_source_helper_calls(
    const struct bpf_insn *insns,
    size_t cnt,
    const std::unordered_map<int, MapMeta> *meta_by_fd = nullptr,
    const std::vector<NativeMapRule> *map_rules = nullptr)
{
    std::vector<SourceHelperCall> sites;
    SourceMapBinding reg_map[11];
    bool reg_imm_known[11] = {};
    uint64_t reg_imm[11] = {};
    std::unordered_map<int16_t, SourceMapBinding> stack_map;
    auto clear_reg = [&](uint8_t reg) {
        if (reg < 11) {
            reg_map[reg] = SourceMapBinding{};
            reg_imm_known[reg] = false;
            reg_imm[reg] = 0;
        }
    };
    auto clear_call_clobbered = [&]() {
        for (int r = 0; r <= 5; r++) clear_reg(r);
    };
    for (size_t i = 0; i < cnt; i++) {
        const struct bpf_insn &in = insns[i];
        uint8_t code = in.code;
        if (code == (BPF_LD | BPF_DW | BPF_IMM)) {
            if (in.dst_reg < 11) {
                clear_reg(in.dst_reg);
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
                reg_imm_known[in.dst_reg] = reg_imm_known[in.src_reg];
                reg_imm[in.dst_reg] = reg_imm[in.src_reg];
            } else {
                clear_reg(in.dst_reg);
            }
            continue;
        }
        if (code == (BPF_ALU64 | BPF_MOV | BPF_K) ||
            code == (BPF_ALU | BPF_MOV | BPF_K)) {
            if (in.dst_reg < 11) {
                reg_map[in.dst_reg] = SourceMapBinding{};
                reg_imm_known[in.dst_reg] = true;
                reg_imm[in.dst_reg] = static_cast<uint32_t>(in.imm);
            }
            continue;
        }
        if (BPF_CLASS(code) == BPF_STX && BPF_MODE(code) == BPF_MEM) {
            const size_t size = bpf_mem_access_size(code);
            if (in.dst_reg == BPF_REG_10) {
                clear_overlapping_stack_bindings(stack_map, in.off, size);
                if (size == 8 && in.src_reg < 11 &&
                    source_map_binding_has_value(reg_map[in.src_reg])) {
                    stack_map[in.off] = reg_map[in.src_reg];
                }
            }
            continue;
        }
        if (BPF_CLASS(code) == BPF_ST && BPF_MODE(code) == BPF_MEM) {
            if (in.dst_reg == BPF_REG_10) {
                clear_overlapping_stack_bindings(
                    stack_map, in.off, bpf_mem_access_size(code));
            }
            continue;
        }
        if (BPF_CLASS(code) == BPF_LDX && BPF_MODE(code) == BPF_MEM) {
            if (in.dst_reg < 11) {
                if (BPF_SIZE(code) == BPF_DW && in.src_reg == BPF_REG_10) {
                    auto it = stack_map.find(in.off);
                    reg_map[in.dst_reg] =
                        it == stack_map.end() ? SourceMapBinding{} : it->second;
                    reg_imm_known[in.dst_reg] = false;
                    reg_imm[in.dst_reg] = 0;
                } else {
                    clear_reg(in.dst_reg);
                }
            }
            continue;
        }
        if (code == (BPF_JMP | BPF_CALL)) {
            if (in.src_reg == BPF_PSEUDO_CALL ||
                in.src_reg == BPF_PSEUDO_KFUNC_CALL ||
                in.src_reg == BPF_PSEUDO_KINSN_CALL) {
                clear_call_clobbered();
                continue;
            }
            if (in.src_reg == 0 && in.imm == kLibbpfCoreBadRelocPoison) {
                clear_call_clobbered();
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
                reg_imm_known[BPF_REG_3],
                static_cast<uint32_t>(reg_imm[BPF_REG_3]),
            });

            NativeMapShape return_shape;
            if (in.imm == BPF_FUNC_map_lookup_elem &&
                map_binding.map_fd >= 0 &&
                meta_by_fd) {
                auto meta_it = meta_by_fd->find(map_binding.map_fd);
                if (meta_it != meta_by_fd->end()) {
                    return_shape = inner_map_shape_for_outer_map(
                        meta_it->second,
                        map_rules ? *map_rules : std::vector<NativeMapRule>{});
                }
            }

            clear_call_clobbered();
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
            clear_reg(in.dst_reg);
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
