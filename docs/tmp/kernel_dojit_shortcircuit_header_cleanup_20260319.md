# Kernel do_jit Short-Circuit + Header Cleanup

Date: 2026-03-19

## Summary

### Task 1: `do_jit` short-circuit restored

- Checked `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`.
- The `do_jit()` main loop was still calling `bpf_jit_apply_prog_rule()` on every insn.
- Restored the Phase B short-circuit by caching `has_active_rules` before the loop and skipping rule dispatch entirely when the active-rule count is zero.
- Change location: `arch/x86/net/bpf_jit_comp.c:3535-3539,3618-3629`.

### Task 2: DSL header residue cleanup

- Checked `vendor/linux-framework/include/linux/bpf_jit_directives.h` and whole-tree references under `vendor/linux-framework`.
- Removed unused `enum bpf_jit_var_type`.
- Removed unused `struct bpf_jit_var`.
- Removed write-only `present_mask` and `param_count` from `struct bpf_jit_canonical_params`.
- Removed unreferenced `reserved[7]` from `struct bpf_jit_binding_value`.
- Simplified parameter setter helpers to stop writing deleted fields.
- Change locations:
  - `include/linux/bpf_jit_directives.h:24-36`
  - `kernel/bpf/jit_directives.c:757-769`

## Reference Audit Notes

- `present_mask` and `param_count` only had write sites in `kernel/bpf/jit_directives.c` and no read sites.
- `enum bpf_jit_var_type` and `struct bpf_jit_var` had no references outside their definitions.
- Remaining JIT directive enums, structs, and rule/policy fields are still referenced.
- `reserved[7]` in `struct bpf_jit_binding_value` had no references. A local compile check confirmed removing it does not change the struct's size/alignment (`sizeof=16`, `alignof=8` before and after), so the cleanup is layout-safe in practice.

## Validation

1. `cd vendor/linux-framework && make -j$(nproc) bzImage`
   - PASS
   - Built `arch/x86/boot/bzImage` successfully.

2. `cd /home/yunwei37/workspace/bpf-benchmark && make vm-selftest`
   - PASS
   - `tests/kernel/build/test_recompile` passed 20/20 tests.
   - VM run printed `modules.order not found`, but execution completed successfully; kernel modules are simply disabled in this build.

3. `make vm-micro-smoke`
   - PASS
   - Smoke run completed and wrote `micro/results/dev/vm_micro_smoke.json`.
   - Representative results:
     - `simple`: `kernel` compile median `6.899 ms`, `kernel-recompile` compile median `4.864 ms`
     - `load_byte_recompose`: `kernel` compile median `4.917 ms`, `kernel-recompile` compile median `4.880 ms`
   - Environment warnings were informational only: CPU governor unknown, turbo enabled, `perf_event_paranoid=2`, no CPU affinity set.

## Files Modified

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
