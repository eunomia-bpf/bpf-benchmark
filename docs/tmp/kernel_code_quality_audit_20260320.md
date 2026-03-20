# Kernel Code Quality Audit

Date: 2026-03-20

Scope read:
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `vendor/linux-framework/kernel/bpf/jit_validators.c`
- `vendor/linux-framework/kernel/bpf/jit_policy.c`
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
- `vendor/linux-framework/include/linux/bpf.h`
- `vendor/linux-framework/kernel/bpf/trampoline.c`
- `docs/tmp/kernel-module-design.md`
- `docs/tmp/precompute_inject_research_20260320.md`
- `docs/tmp/validator_emitter_boundary_audit_20260320.md`

Methodology note:
- The LOC table below counts form-specific validator code and form-dedicated emitter helpers.
- Shared helper blocks are excluded from the per-form table to avoid double-counting.
- This makes `ZERO_EXT_ELIDE` and `BRANCH_FLIP` look smaller than their true x86 maintenance cost, because both sit on top of shared x86 replay helpers at `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2311-2910`.

## 1. Executive summary: top 5 most impactful findings

1. `P0`, definitely wrong: x86 `BRANCH_FLIP` can overflow the per-site temp buffer. The validator allows up to 16 linear instructions per body (`vendor/linux-framework/kernel/bpf/jit_validators.c:1401-1514`) and treats 32-bit and 64-bit `DIV/MOD` as linearizable (`vendor/linux-framework/kernel/bpf/jit_validators.c:748-806`), but the x86 backend emits the entire flipped region into `temp[BPF_MAX_INSN_SIZE + BPF_INSN_SAFETY]` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3299-3301`) and only checks `ilen > BPF_MAX_INSN_SIZE` after emission (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3224-3235`). A sufficiently heavy branch body can exceed 192 bytes before that check runs.
2. `P1`, definitely wrong: `COND_SELECT` loses source-shape timing in the shared canonical contract. The validator collapses 2-insn, 3-insn, and 4-insn forms into the same `{cond,true,false}` parameter tuple (`vendor/linux-framework/kernel/bpf/jit_validators.c:291-380`), but x86 preloads the false value before the compare (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1356-1378`) while arm64 compares before materializing either side (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:836-895`). Alias cases where the selected destination also participates in the condition are therefore accepted by validation but miscompiled by one backend or the other.
3. `P1`, definitely wrong: `ADDR_CALC` accepts self-referential aliases that a single `LEA` cannot preserve. The validator records `base_reg = add_insn->src_reg` without rejecting `base_reg == dst_reg` (`vendor/linux-framework/kernel/bpf/jit_validators.c:1075-1119`), while the emitter assumes a pure `base + index * scale` address expression and emits one `LEA` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2287-2309`). A valid-looking site like `mov dst, idx; lsh dst, 2; add dst, dst` does not fit that contract.
4. `P2`, definitely wrong: the trampoline-regeneration warning path leaks old JIT images and private stacks. Shared orchestration intentionally keeps old text resident on regeneration failure (`vendor/linux-framework/kernel/bpf/jit_directives.c:492-503`), but the only free sites are gated by `!keep_old_images` (`vendor/linux-framework/kernel/bpf/jit_directives.c:528-532`), and later arch free paths only free the current live image (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5673-5704`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:3954-3984`).
5. Could be better: the implementation carries visible bloat in low-demand and duplicated areas. The design doc shows zero observed corpus demand for `ROTATE` and `ZERO_EXT_ELIDE`, and only 24 objects for `BRANCH_FLIP` (`docs/tmp/kernel-module-design.md:244-253`), yet x86 still keeps a 523-line replay subsystem for `ZERO_EXT_ELIDE` and `BRANCH_FLIP` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2311-2910`). `jit_policy.c` also retains an unused `policy->blob` field (`vendor/linux-framework/include/linux/bpf_jit_directives.h:138-149`, `vendor/linux-framework/kernel/bpf/jit_policy.c:30-40`, `vendor/linux-framework/kernel/bpf/jit_policy.c:99-110`, `vendor/linux-framework/kernel/bpf/jit_policy.c:216`).

## 2. Per-form LOC table

| Form | Validator LOC | x86 emitter LOC | arm64 emitter LOC | Total direct LOC | Flag |
| --- | ---: | ---: | ---: | ---: | --- |
| `COND_SELECT` | 271 | 123 | 322 | 716 | Large and bug-prone; high demand likely justifies some size, but the current shape contract is wrong |
| `WIDE_MEM` | 163 | 166 | 138 | 467 | Large but structurally similar on both arches; good factoring target |
| `ROTATE` | 276 | 64 | 25 | 365 | Disproportionate relative to zero observed corpus demand |
| `ADDR_CALC` | 57 | 23 | 0 | 80 | Small, but currently under-specified and buggy |
| `BITFIELD_EXTRACT` | 183 | 67 | 42 | 292 | Reasonable after normalization work, but still duplicated across arches |
| `ZERO_EXT_ELIDE` | 87 | 14 | 0 | 101 | Direct count is misleadingly low; x86 replay helper tax is not counted here |
| `ENDIAN_FUSION` | 110 | 58 | 0 | 168 | Moderate, x86-only |
| `BRANCH_FLIP` | 142 | 139 | 0 | 281 | Direct count is moderate, but the x86 replay-helper dependency is very large |

Shared helper tax not counted above:
- x86 compare/jump helpers shared by `COND_SELECT` and `BRANCH_FLIP`: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1079-1284` (206 lines).
- x86 replay helpers used by `ZERO_EXT_ELIDE` and `BRANCH_FLIP`: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2311-2910` (523 lines).

Forms that look disproportionately large versus observed complexity:
- `ROTATE`: 365 direct LOC, zero observed corpus sites (`docs/tmp/kernel-module-design.md:248`, `docs/tmp/kernel-module-design.md:251`).
- `ZERO_EXT_ELIDE`: only 101 direct LOC on paper, but it exists solely to replay an ALU32 instruction through x86-only helper machinery at `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2311-2501`.
- `BRANCH_FLIP`: 281 direct LOC plus the shared replay block; it is the only form that has to re-emit arbitrary BPF bodies, and it carries the highest correctness risk.

## 3. Bloat analysis with specific line ranges

- Could be better: the x86 replay subsystem is the biggest lines-to-value mismatch in the tree. `ZERO_EXT_ELIDE` and `BRANCH_FLIP` rely on `emit_bpf_alu32_insn()` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2311-2501`), `emit_bpf_end_insn()` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2577-2643`), `emit_bpf_alu64_insn()` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2645-2842`), and `emit_linear_bpf_insn()` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2844-2910`). The design doc shows zero observed demand for `ZERO_EXT_ELIDE` and only 24 objects for `BRANCH_FLIP` (`docs/tmp/kernel-module-design.md:251`, `docs/tmp/kernel-module-design.md:253`).
- Could be better: `COND_SELECT` and `WIDE_MEM` each keep their own architecture-local helper stacks instead of sharing the arch-independent parts of the algorithm. Compare x86 `COND_SELECT` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1286-1408`) with arm64 `COND_SELECT` (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:359-589`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:805-895`), and x86 `WIDE_MEM` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2057-2220`) with arm64 `WIDE_MEM` (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:593-771`).
- Could be better: tiny helper logic is duplicated verbatim. `pick_wide_chunk()` appears in x86 and arm64 (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2107-2113`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:593-599`), and the low-mask-width scanners for bitfield extraction are duplicated too (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3052-3061`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:677-686`).
- Could be better: rule lookup / dispatch / apply glue is duplicated across both backends. x86 carries `bpf_jit_rule_lookup_prog()` through `bpf_jit_apply_prog_rule()` at `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3120-3287`; arm64 carries the same pattern at `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:897-979`.
- Could be better: `jit_directives.c` repeats image selection and shadow-kallsyms selection boilerplate across multiple loops instead of centralizing it. The repeated `image_prog` choice shows up at `vendor/linux-framework/kernel/bpf/jit_directives.c:323-336`, `vendor/linux-framework/kernel/bpf/jit_directives.c:399-409`, `vendor/linux-framework/kernel/bpf/jit_directives.c:438-448`, `vendor/linux-framework/kernel/bpf/jit_directives.c:469-476`, `vendor/linux-framework/kernel/bpf/jit_directives.c:507-517`, `vendor/linux-framework/kernel/bpf/jit_directives.c:538-546`, and `vendor/linux-framework/kernel/bpf/jit_directives.c:554-565`.
- Definitely wrong, and also dead weight: `policy->blob` is retained, initialized, and freed (`vendor/linux-framework/kernel/bpf/jit_policy.c:39`, `vendor/linux-framework/kernel/bpf/jit_policy.c:110`, `vendor/linux-framework/kernel/bpf/jit_policy.c:216`) but never read anywhere in-tree.
- Could be better: `bpf_jit_recompile_snapshot()` appears to snapshot the main image twice for multi-function programs. It allocates `1 + real_func_cnt` state slots and saves `prog` first, then saves every `main_aux->func[i - 1]` (`vendor/linux-framework/kernel/bpf/jit_directives.c:155-185`), while the same file later treats `main_aux->func[0]` as the canonical main image (`vendor/linux-framework/kernel/bpf/jit_directives.c:478-487`).

## 4. Design boundary violations with specific line ranges

- Definitely wrong: `COND_SELECT` is not representable by the current canonical params alone. The validator stores only `{cond,true,false,width}` (`vendor/linux-framework/kernel/bpf/jit_validators.c:291-380`), but the original 3-insn compact form executes one move before the compare while the 4-insn diamond does not. x86 encodes the "preload false, then compare" model (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1356-1378`); arm64 encodes the "compare first, then select" model (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:836-895`). This directly contradicts the design doc’s safety claim that the validator is the only semantic gate (`docs/tmp/kernel-module-design.md:703-705`).
- Definitely wrong: `ADDR_CALC` likewise loses a necessary aliasing constraint at the validator/emitter boundary. The validator exports only `dst/base/index/scale` (`vendor/linux-framework/kernel/bpf/jit_validators.c:1111-1115`), but a single `LEA` is only correct when `base` is a true pre-site source, not the already-shifted destination (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2297-2306`).
- Could be better: `bpf_jit_rule_release()` lives in lifecycle/orchestration code but knows about form-specific heap ownership for `BRANCH_FLIP` (`vendor/linux-framework/kernel/bpf/jit_directives.c:263-276`). Allocation happens in the validator (`vendor/linux-framework/kernel/bpf/jit_validators.c:1479-1510`). A per-form release callback in `bpf_jit_form_meta` would keep ownership rules in the same layer as validation.
- Could be better: policy semantics are split between the parser and the syscall layer. `bpf_jit_parse_policy()` returns a policy object even when `active_cnt == 0`, and `bpf_prog_jit_recompile()` then turns that into `-EINVAL` (`vendor/linux-framework/kernel/bpf/jit_directives.c:653-669`). If "no active rules" is policy invalidity, it belongs in `jit_policy.c`, not `jit_directives.c`.
- Could be better: arch backends still own shared recompile accounting and fallback policy, not just byte emission. x86 and arm64 both update `jit_recompile_num_applied` and log "applied successfully" or fallback inside their arch-local `bpf_jit_apply_prog_rule()` helpers (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3253-3284`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:945-976`).
- Could be better: arm64 advertises two rotate native choices but ignores one of them. `bpf_jit_arch_form_supported()` accepts both `BPF_JIT_ROT_ROR` and `BPF_JIT_ROT_RORX` (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:3920-3929`), but `emit_canonical_rotate_arm64()` drops `native_choice` on the floor (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:689-708`).

## 5. Latent bug list (severity: P0/P1/P2)

- `P0`, definitely wrong: x86 `BRANCH_FLIP` can overrun the per-site temp buffer before any size guard runs. Validator-side body-length bounds are instruction-count bounds only (`vendor/linux-framework/kernel/bpf/jit_validators.c:1433-1448`). The emitter writes the whole replacement into `temp` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3299-3301`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2979-3050`) and only afterwards checks `ilen > BPF_MAX_INSN_SIZE` (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3224-3235`). This is a privileged-input kernel memory-safety bug.
- `P1`, definitely wrong: `COND_SELECT` accepts validated rules that x86 or arm64 cannot lower correctly when the selected destination aliases a condition operand. See validator normalization at `vendor/linux-framework/kernel/bpf/jit_validators.c:323-355`, x86 preload-before-compare at `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1356-1378`, and arm64 compare-before-materialize at `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:836-895`.
- `P1`, definitely wrong: `ADDR_CALC` accepts alias cases that the x86 `LEA` emitter cannot represent. The missing reject is in `vendor/linux-framework/kernel/bpf/jit_validators.c:1104-1115`; the incorrect lowering assumption is in `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2297-2306`.
- `P2`, definitely wrong: trampoline regeneration failure leaks old executable images and private stacks. The warning path preserves old allocations (`vendor/linux-framework/kernel/bpf/jit_directives.c:492-503`) but the only reclamation sites are skipped under `keep_old_images` (`vendor/linux-framework/kernel/bpf/jit_directives.c:528-532`), and the later arch free paths only know about the current live image (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:5673-5704`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:3954-3984`).

## 6. Dead code list

- Definitely dead today: `struct bpf_jit_policy::blob` is documented as retained backing storage (`vendor/linux-framework/include/linux/bpf_jit_directives.h:138-149`), initialized and freed (`vendor/linux-framework/kernel/bpf/jit_policy.c:30-40`, `vendor/linux-framework/kernel/bpf/jit_policy.c:99-110`, `vendor/linux-framework/kernel/bpf/jit_policy.c:216`), but never read anywhere in-tree.
- Definitely dead today: `BPF_JIT_BFX_PARAM_ORDER` is written once in the validator (`vendor/linux-framework/kernel/bpf/jit_validators.c:1041-1052`) and never read by either emitter (`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3076-3118`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:773-803`).
- Definitely dead today: `BPF_JIT_BFX_ORDER_MASK_SHIFT` is defined but never referenced (`vendor/linux-framework/include/linux/bpf_jit_directives.h:63-75`).
- Definitely dead today: the `rollback` parameter to `bpf_jit_recompile_prog_images()` is unused (`vendor/linux-framework/kernel/bpf/jit_directives.c:292-307`).
- Definitely dead today: the `native_choice` parameter to `emit_canonical_rotate_arm64()` is unused (`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:689-708`).
- Definitely dead today: the `insn_cnt` parameter to `bpf_jit_validate_rotate_rule()` is unused (`vendor/linux-framework/kernel/bpf/jit_validators.c:828-846`).

## 7. Simplification recommendations with estimated LOC savings

- Remove `policy->blob` retention until the policy format actually needs out-of-line rule payloads. Relevant code: `vendor/linux-framework/include/linux/bpf_jit_directives.h:138-149`, `vendor/linux-framework/kernel/bpf/jit_policy.c:30-40`, `vendor/linux-framework/kernel/bpf/jit_policy.c:99-110`, `vendor/linux-framework/kernel/bpf/jit_policy.c:216`. Estimated savings: 10-15 LOC and one unused pointer per live policy.
- Remove `BPF_JIT_BFX_PARAM_ORDER` and `BPF_JIT_BFX_ORDER_MASK_SHIFT`. The validator always normalizes to `SHIFT_MASK`, and neither backend reads the field. Relevant code: `vendor/linux-framework/include/linux/bpf_jit_directives.h:63-75`, `vendor/linux-framework/kernel/bpf/jit_validators.c:1041-1052`. Estimated savings: 8-12 LOC and one canonical-param slot.
- Factor `bpf_jit_rule_lookup_prog()`, fallback logging, and `jit_recompile_num_applied` accounting into shared recompile glue, leaving only the arch-specific `addrs[]` / `offset[]` collapse callback in each backend. Relevant code: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3120-3287`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:897-979`. Estimated savings: 45-60 LOC.
- Table-drive condition-code mapping and inversion instead of hand-written switches on both arches. Relevant code: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1079-1198`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:388-463`. Estimated savings: 60-80 LOC.
- Factor image selection and shadow-kallsyms selection helpers out of `jit_directives.c`. Relevant code: `vendor/linux-framework/kernel/bpf/jit_directives.c:323-336`, `vendor/linux-framework/kernel/bpf/jit_directives.c:438-448`, `vendor/linux-framework/kernel/bpf/jit_directives.c:507-517`, `vendor/linux-framework/kernel/bpf/jit_directives.c:554-565`. Estimated savings: 40-55 LOC.
- Merge tiny duplicated helper logic such as `pick_wide_chunk()` and bitfield-mask-width scanners. Relevant code: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2107-2113`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3052-3061`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:593-599`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:677-686`. Estimated savings: 10-15 LOC.
- Optional product-scope cut: if zero-demand forms are not strategic, retire `ZERO_EXT_ELIDE` and stop advertising arm64 `RORX` as a distinct native choice. Relevant code: `docs/tmp/kernel-module-design.md:248-253`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2311-2501`, `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:2503-2516`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:689-708`, `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:3920-3929`. Estimated savings: 25-200 LOC depending on how much shared replay scaffolding you remove.

## 8. Total estimated LOC savings if all recommendations applied

- Net savings without changing supported forms: about 120-180 LOC. The structural deletions above are partly offset by the correctness fixes this audit also recommends for `COND_SELECT`, `ADDR_CALC`, `BRANCH_FLIP`, and the trampoline-retention path.
- Net savings if you also prune the clearly low-value surface (`ZERO_EXT_ELIDE`, arm64's fake `RORX` choice, and any replay helpers that become unreachable): roughly 220-350 LOC.
