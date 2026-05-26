#pragma once

struct SourceHelperCall {
    int helper_id;
    int map_fd;
    NativeMapShape dynamic_map_shape;
};

struct SourceMapBinding {
    int map_fd = -1;
    NativeMapShape map_shape;
    NativeMapShape lookup_return_shape;
    NativeMapShape dynamic_map_shape;
};

struct SourceBytecodeState {
    std::array<SourceMapBinding, 11> regs;
    std::array<SourceMapBinding, 64> stack_slots;
    bool reachable = false;
};

bool same_native_map_shape(const NativeMapShape &lhs,
                           const NativeMapShape &rhs)
{
    return lhs.type == rhs.type &&
           lhs.key_size == rhs.key_size &&
           lhs.value_size == rhs.value_size &&
           lhs.max_entries == rhs.max_entries;
}

bool same_source_map_binding(const SourceMapBinding &lhs,
                             const SourceMapBinding &rhs)
{
    return lhs.map_fd == rhs.map_fd &&
           same_native_map_shape(lhs.map_shape, rhs.map_shape) &&
           same_native_map_shape(lhs.lookup_return_shape, rhs.lookup_return_shape) &&
           same_native_map_shape(lhs.dynamic_map_shape, rhs.dynamic_map_shape);
}

SourceMapBinding merge_source_map_binding(const SourceMapBinding &lhs,
                                          const SourceMapBinding &rhs)
{
    if (same_source_map_binding(lhs, rhs)) {
        return lhs;
    }

    const bool lhs_direct = has_native_map_shape(lhs.map_shape);
    const bool rhs_direct = has_native_map_shape(rhs.map_shape);
    if (lhs_direct && rhs_direct &&
        same_native_map_shape(lhs.map_shape, rhs.map_shape)) {
        SourceMapBinding merged = lhs;
        if (!same_native_map_shape(lhs.lookup_return_shape,
                                   rhs.lookup_return_shape)) {
            merged.lookup_return_shape = NativeMapShape{};
        }
        return merged;
    }

    const bool lhs_dynamic = has_native_map_shape(lhs.dynamic_map_shape);
    const bool rhs_dynamic = has_native_map_shape(rhs.dynamic_map_shape);
    if (lhs_dynamic && rhs_dynamic &&
        same_native_map_shape(lhs.dynamic_map_shape, rhs.dynamic_map_shape)) {
        SourceMapBinding merged;
        merged.dynamic_map_shape = lhs.dynamic_map_shape;
        return merged;
    }

    return SourceMapBinding{};
}

bool merge_source_bytecode_state(SourceBytecodeState &dst,
                                 const SourceBytecodeState &src)
{
    if (!src.reachable) {
        return false;
    }
    if (!dst.reachable) {
        dst = src;
        return true;
    }

    bool changed = false;
    for (size_t i = 0; i < dst.regs.size(); i++) {
        const SourceMapBinding merged =
            merge_source_map_binding(dst.regs[i], src.regs[i]);
        if (!same_source_map_binding(dst.regs[i], merged)) {
            dst.regs[i] = merged;
            changed = true;
        }
    }
    for (size_t i = 0; i < dst.stack_slots.size(); i++) {
        const SourceMapBinding merged =
            merge_source_map_binding(dst.stack_slots[i], src.stack_slots[i]);
        if (!same_source_map_binding(dst.stack_slots[i], merged)) {
            dst.stack_slots[i] = merged;
            changed = true;
        }
    }
    return changed;
}

void clear_helper_clobbered_regs(SourceBytecodeState &state)
{
    for (int r = 0; r <= 5; r++) {
        state.regs[r] = SourceMapBinding{};
    }
}

int source_helper_map_arg_reg(int helper_id)
{
    if (helper_id == BPF_FUNC_tail_call ||
        helper_id == BPF_FUNC_perf_event_output) {
        return 2;
    }
    return 1;
}

NativeMapShape source_lookup_return_shape(
    int helper_id,
    const SourceMapBinding &map_binding,
    const std::unordered_map<int, MapMeta> *meta_by_fd)
{
    if (helper_id != BPF_FUNC_map_lookup_elem) {
        return NativeMapShape{};
    }
    if (has_native_map_shape(map_binding.lookup_return_shape)) {
        return map_binding.lookup_return_shape;
    }
    if (map_binding.map_fd < 0 || !meta_by_fd) {
        return NativeMapShape{};
    }
    auto meta_it = meta_by_fd->find(map_binding.map_fd);
    if (meta_it == meta_by_fd->end()) {
        return NativeMapShape{};
    }
    return inner_map_shape_for_outer_map(meta_it->second);
}

bool bpf_call_is_pseudo_subprog(const struct bpf_insn &in)
{
    return in.code == (BPF_JMP | BPF_CALL) &&
           in.src_reg == BPF_PSEUDO_CALL;
}

size_t checked_bpf_target(size_t pc, int16_t off, size_t cnt)
{
    const int64_t target = static_cast<int64_t>(pc) + 1 + off;
    if (target < 0 || static_cast<size_t>(target) >= cnt) {
        fail("native_kernel: source BPF branch target out of range at insn "
             + std::to_string(pc));
    }
    return static_cast<size_t>(target);
}

bool bpf_is_cond_jump(uint8_t code)
{
    const uint8_t cls = BPF_CLASS(code);
    return (cls == BPF_JMP || cls == BPF_JMP32) &&
           code != (BPF_JMP | BPF_CALL) &&
           code != (BPF_JMP | BPF_EXIT) &&
           BPF_OP(code) != BPF_JA;
}

int source_stack_slot_for_exact_dw(int16_t off)
{
    if (off >= 0 || (off % 8) != 0) {
        return -1;
    }
    const int byte = -static_cast<int>(off);
    if (byte < 8 || byte > 512) {
        return -1;
    }
    return byte / 8 - 1;
}

int source_stack_slot_containing(int16_t off)
{
    if (off >= 0) {
        return -1;
    }
    const int byte = -static_cast<int>(off);
    if (byte < 1 || byte > 512) {
        return -1;
    }
    return (byte - 1) / 8;
}

int bpf_mem_access_size(uint8_t code)
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

void clear_stack_slots_for_write(SourceBytecodeState &state,
                                 int16_t off,
                                 uint8_t code)
{
    const int size = bpf_mem_access_size(code);
    if (size <= 0) {
        return;
    }
    const int first = source_stack_slot_containing(off);
    const int last = source_stack_slot_containing(
        static_cast<int16_t>(off + size - 1));
    if (first < 0 || last < 0) {
        return;
    }
    for (int slot = first; slot <= last; slot++) {
        state.stack_slots[static_cast<size_t>(slot)] = SourceMapBinding{};
    }
}

void enqueue_source_state(std::deque<size_t> &work,
                          std::vector<SourceBytecodeState> &states,
                          size_t next,
                          const SourceBytecodeState &state)
{
    if (next >= states.size()) {
        return;
    }
    if (merge_source_bytecode_state(states[next], state)) {
        work.push_back(next);
    }
}

std::vector<SourceBytecodeState> analyze_source_bytecode_states(
    const struct bpf_insn *insns,
    size_t cnt,
    const std::unordered_map<int, MapMeta> *meta_by_fd)
{
    std::vector<SourceBytecodeState> states(cnt);
    if (cnt == 0) {
        return states;
    }

    std::deque<size_t> work;
    SourceBytecodeState entry;
    entry.reachable = true;
    enqueue_source_state(work, states, 0, entry);

    while (!work.empty()) {
        const size_t pc = work.front();
        work.pop_front();

        SourceBytecodeState state = states[pc];
        const struct bpf_insn &in = insns[pc];
        const uint8_t code = in.code;

        if (code == (BPF_LD | BPF_DW | BPF_IMM)) {
            if (pc + 1 >= cnt) {
                fail("native_kernel: truncated source BPF LDDW at insn "
                     + std::to_string(pc));
            }
            if (in.dst_reg < state.regs.size()) {
                state.regs[in.dst_reg] = SourceMapBinding{};
                if (in.src_reg == BPF_PSEUDO_MAP_FD) {
                    SourceMapBinding binding;
                    binding.map_fd = static_cast<int>(in.imm);
                    if (meta_by_fd) {
                        auto meta_it = meta_by_fd->find(binding.map_fd);
                        if (meta_it != meta_by_fd->end()) {
                            binding.map_shape =
                                map_shape_from_meta(meta_it->second);
                            binding.lookup_return_shape =
                                inner_map_shape_for_outer_map(meta_it->second);
                        }
                    }
                    state.regs[in.dst_reg] = binding;
                }
            }
            enqueue_source_state(work, states, pc + 2, state);
            continue;
        }

        if (code == (BPF_ALU64 | BPF_MOV | BPF_X)) {
            if (in.dst_reg < state.regs.size() &&
                in.src_reg < state.regs.size()) {
                state.regs[in.dst_reg] = state.regs[in.src_reg];
            } else if (in.dst_reg < state.regs.size()) {
                state.regs[in.dst_reg] = SourceMapBinding{};
            }
            enqueue_source_state(work, states, pc + 1, state);
            continue;
        }

        if (BPF_CLASS(code) == BPF_LDX &&
            BPF_MODE(code) == BPF_MEM &&
            in.src_reg == BPF_REG_10) {
            if (in.dst_reg < state.regs.size() &&
                BPF_SIZE(code) == BPF_DW) {
                const int slot = source_stack_slot_for_exact_dw(in.off);
                state.regs[in.dst_reg] = slot >= 0
                    ? state.stack_slots[static_cast<size_t>(slot)]
                    : SourceMapBinding{};
            } else if (in.dst_reg < state.regs.size()) {
                state.regs[in.dst_reg] = SourceMapBinding{};
            }
            enqueue_source_state(work, states, pc + 1, state);
            continue;
        }

        if ((BPF_CLASS(code) == BPF_STX || BPF_CLASS(code) == BPF_ST) &&
            BPF_MODE(code) == BPF_MEM &&
            in.dst_reg == BPF_REG_10) {
            clear_stack_slots_for_write(state, in.off, code);
            if (BPF_CLASS(code) == BPF_STX &&
                BPF_SIZE(code) == BPF_DW &&
                in.src_reg < state.regs.size()) {
                const int slot = source_stack_slot_for_exact_dw(in.off);
                if (slot >= 0) {
                    state.stack_slots[static_cast<size_t>(slot)] =
                        state.regs[in.src_reg];
                }
            }
            enqueue_source_state(work, states, pc + 1, state);
            continue;
        }

        if (code == (BPF_JMP | BPF_CALL)) {
            if (bpf_call_is_pseudo_subprog(in)) {
                SourceBytecodeState after_call = state;
                clear_helper_clobbered_regs(after_call);
                enqueue_source_state(work, states, pc + 1, after_call);
                enqueue_source_state(
                    work, states, checked_bpf_target(pc, in.off, cnt), state);
                continue;
            }
            if (in.src_reg == BPF_PSEUDO_KFUNC_CALL ||
                in.src_reg == BPF_PSEUDO_KINSN_CALL) {
                clear_helper_clobbered_regs(state);
                enqueue_source_state(work, states, pc + 1, state);
                continue;
            }
            if (in.src_reg == 0 && in.imm == kLibbpfCoreBadRelocPoison) {
                clear_helper_clobbered_regs(state);
                enqueue_source_state(work, states, pc + 1, state);
                continue;
            }
            if (in.src_reg != 0) {
                fail("native_kernel: unsupported non-helper BPF call src_reg="
                     + std::to_string(static_cast<unsigned>(in.src_reg)));
            }

            const int map_arg_reg = source_helper_map_arg_reg(in.imm);
            const SourceMapBinding map_binding = state.regs[map_arg_reg];
            const NativeMapShape return_shape =
                source_lookup_return_shape(in.imm, map_binding, meta_by_fd);

            clear_helper_clobbered_regs(state);
            if (has_native_map_shape(return_shape)) {
                state.regs[0].dynamic_map_shape = return_shape;
            }
            enqueue_source_state(work, states, pc + 1, state);
            continue;
        }

        if (code == (BPF_JMP | BPF_EXIT)) {
            continue;
        }

        if ((BPF_CLASS(code) == BPF_JMP || BPF_CLASS(code) == BPF_JMP32) &&
            BPF_OP(code) == BPF_JA) {
            enqueue_source_state(
                work, states, checked_bpf_target(pc, in.off, cnt), state);
            continue;
        }

        if (bpf_is_cond_jump(code)) {
            enqueue_source_state(work, states, pc + 1, state);
            enqueue_source_state(
                work, states, checked_bpf_target(pc, in.off, cnt), state);
            continue;
        }

        const uint8_t cls = BPF_CLASS(code);
        if (cls == BPF_ALU || cls == BPF_ALU64 || cls == BPF_LDX) {
            if (in.dst_reg < state.regs.size()) {
                state.regs[in.dst_reg] = SourceMapBinding{};
            }
        } else if (cls == BPF_LD) {
            state.regs[0] = SourceMapBinding{};
        }
        enqueue_source_state(work, states, pc + 1, state);
    }

    return states;
}

/* Walk a BPF program's original (pre-verifier) bytecode and identify every
 * reachable helper call in source order, plus the map fd currently bound to
 * that helper's map argument register when the call occurs. map_fd is -1 when
 * the binding is ambiguous. If a previous map-in-map lookup returned a
 * verifier-tracked inner map pointer, dynamic_map_shape records the inner map
 * shape so the next map_lookup_elem call can use the same map-specific
 * lowering as the kernel JIT.
 *
 * The analysis is intentionally small but control-flow aware: it tracks map
 * bindings through register moves, propagates branch targets, and merges
 * inconsistent register facts to "unknown". This preserves hot-path map-in-map
 * metadata without letting cold error paths clobber the success-path state. */
std::vector<SourceHelperCall> collect_source_helper_calls(
    const struct bpf_insn *insns,
    size_t cnt,
    const std::unordered_map<int, MapMeta> *meta_by_fd = nullptr)
{
    std::vector<SourceBytecodeState> states =
        analyze_source_bytecode_states(insns, cnt, meta_by_fd);
    std::vector<SourceHelperCall> sites;
    for (size_t i = 0; i < cnt; i++) {
        const struct bpf_insn &in = insns[i];
        if (in.code == (BPF_LD | BPF_DW | BPF_IMM)) {
            i++; /* skip second slot (high 32 bits of imm64) */
            continue;
        }
        if (in.code == (BPF_JMP | BPF_CALL)) {
            if (in.src_reg == BPF_PSEUDO_CALL ||
                in.src_reg == BPF_PSEUDO_KFUNC_CALL ||
                in.src_reg == BPF_PSEUDO_KINSN_CALL) {
                continue;
            }
            if (in.src_reg == 0 && in.imm == kLibbpfCoreBadRelocPoison) {
                continue;
            }
            if (in.src_reg != 0) {
                fail("native_kernel: unsupported non-helper BPF call src_reg="
                     + std::to_string(static_cast<unsigned>(in.src_reg)));
            }
            if (!states[i].reachable) {
                continue;
            }
            const int map_arg_reg = source_helper_map_arg_reg(in.imm);
            SourceMapBinding map_binding = states[i].regs[map_arg_reg];
            sites.push_back(SourceHelperCall{
                in.imm,
                map_binding.map_fd,
                map_binding.dynamic_map_shape,
            });
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
