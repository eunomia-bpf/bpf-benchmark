# Kernel Validator Param-Match Removal Audit (2026-03-19)

## Summary

Target file: `vendor/linux-framework/kernel/bpf/jit_directives.c`

Current tree state already matches the requested post-cleanup design:

- Policy parse zeros `rule->params` before validation.
- Each canonical-form validator parses the site shape from insns.
- No validator matches user-supplied `rule->params` against that shape.
- On success, validators fill normalized canonical params back out.
- No `bpf_jit_param_matches_reg`, `bpf_jit_param_matches_imm`, or related match helpers exist in the current `vendor/linux-framework` tree.

No kernel code change was required in `jit_directives.c` for this task because the dead match layer is already absent in the checked-out source.

## Per-form Audit

### 1. `BPF_JIT_CF_COND_SELECT`

Validator: `bpf_jit_validate_cond_select_rule()` at `jit_directives.c:926`

- Step 1 retained: `bpf_jit_parse_cond_select_shape(...)`
- Step 2 status: no `rule->params` match logic present
- Step 3 retained: `bpf_jit_cond_select_fill_params(...)`

### 2. `BPF_JIT_CF_WIDE_MEM`

Validator: `bpf_jit_validate_wide_mem_rule()` at `jit_directives.c:1072`

- Step 1 retained: `bpf_jit_parse_wide_mem_shape(...)`
- Step 2 status: no `rule->params` match logic present
- Step 3 retained: fills `DST_REG`, `BASE_REG`, `BASE_OFF`, `WIDTH`

### 3. `BPF_JIT_CF_ROTATE`

Validator: `bpf_jit_validate_rotate_rule()` at `jit_directives.c:1594`

- Step 1 retained: `bpf_jit_parse_rotate_{4insn,5insn,5insn_masked,6insn}(...)`
- Step 2 status: no `rule->params` match logic present
- Step 3 retained: fills `DST_REG`, `SRC_REG`, `AMOUNT`, `WIDTH`

### 4. `BPF_JIT_CF_BITFIELD_EXTRACT`

Validator: `bpf_jit_validate_bitfield_extract_rule()` at `jit_directives.c:1743`

- Step 1 retained: `bpf_jit_parse_bitfield_extract_site(...)`
- Step 2 status: no `rule->params` match logic present
- Step 3 retained: fills `DST_REG`, `SRC_REG`, `SHIFT`, `MASK`, `WIDTH`, `ORDER`

### 5. `BPF_JIT_CF_ADDR_CALC`

Validator: `bpf_jit_validate_addr_calc_rule()` at `jit_directives.c:1841`

- Step 1 retained: `bpf_jit_parse_addr_calc_shape(...)`
- Step 2 status: no `rule->params` match logic present
- Step 3 retained: fills `DST_REG`, `BASE_REG`, `INDEX_REG`, `SCALE`

### 6. `BPF_JIT_CF_ZERO_EXT_ELIDE`

Validator: `bpf_jit_validate_zero_ext_elide_rule()` at `jit_directives.c:1927`

- Step 1 retained: `bpf_jit_parse_zero_ext_elide_shape(...)`
- Step 2 status: no `rule->params` match logic present
- Step 3 retained: fills `DST_REG` and internal `ALU32_PTR`

### 7. `BPF_JIT_CF_ENDIAN_FUSION`

Validator: `bpf_jit_validate_endian_fusion_rule()` at `jit_directives.c:2041`

- Step 1 retained: `bpf_jit_parse_endian_fusion_shape(...)`
- Step 2 status: no `rule->params` match logic present
- Step 3 retained: fills `DATA_REG`, `BASE_REG`, `OFFSET`, `WIDTH`, `DIRECTION`

### 8. `BPF_JIT_CF_BRANCH_FLIP`

Validator: `bpf_jit_validate_branch_flip_rule()` at `jit_directives.c:2172`

- Step 1 retained: `bpf_jit_parse_branch_flip_shape(...)`
- Step 2 status: no `rule->params` match logic present
- Step 3 retained: fills `COND_OP`, body ranges, `JOIN_TARGET`, and internal `SITE_PTR`

## Policy Parse / Fill Path

The parse path still behaves as expected for the DSL-removal model:

- `jit_directives.c:2475` zeros `rule->params` during policy parse.
- `jit_directives.c:2496` passes `&rule->params` into `bpf_jit_validate_rule(...)`.
- `bpf_jit_validate_rule(...)` and the per-form validators only synthesize normalized params from parsed shapes.

## Match-helper Audit

Workspace search under `vendor/linux-framework` found no remaining definitions or call sites for:

- `bpf_jit_param_matches_reg`
- `bpf_jit_param_matches_imm`
- any similarly named `param_matches_*` helper

So there was nothing additional to delete in the current checkout.

## Validation

Environment setup used:

- `source /home/yunwei37/workspace/.venv/bin/activate`

Commands run:

1. `cd vendor/linux-framework && make -j$(nproc) bzImage`
2. `cd /home/yunwei37/workspace/bpf-benchmark && make vm-selftest`
3. `cd /home/yunwei37/workspace/bpf-benchmark && make vm-micro-smoke`

Results:

- `bzImage`: passed
- `vm-selftest`: passed, `PASS all 19 test(s)`
- `vm-micro-smoke`: passed
- `micro/results/dev/vm_micro_smoke.json`: `cmov_dense` with `runtime=kernel-recompile` has `baseline_adjustment.applied = true`

