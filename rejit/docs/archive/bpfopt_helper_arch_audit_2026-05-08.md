# bpfopt helper architecture and file organization audit

Date: 2026-05-08

Scope: read-only audit of `bpfopt/crates/bpfopt/src/`, focused on helper consolidation, file organization, and module visibility. Algorithm-level pass duplication is intentionally out of scope; this complements `docs/tmp/bpfopt_pass_architecture_audit_2026-05-08.md`.

## 1. Executive summary

The current `bpfopt` layout is mostly workable, but the shared helper boundary is too weak: instruction encoding lives partly in `insn.rs`, partly in `src/test_helpers.rs`, partly in pass-local helper functions, and partly in `passes/utils.rs`. The largest architectural smell is not mere duplication; it is that identical domain concepts have multiple spellings, especially helper calls, `LD_IMM64` pairs, branch targets, verifier stack facts, and map references. `passes/utils.rs` is a real utility drawer and should be split by responsibility, while `map_inline.rs` and `pass.rs` both expose pass-local concepts more widely than they should. The right cleanup path is incremental: first align small instruction/helper APIs and visibility, then split `utils.rs`, then move read-only facts into `analysis/` without changing pass algorithms.

## 2. Helper consolidation candidates

| test helper | production helper | current locations | recommended consolidation location | same concept? | risk |
|---|---|---|---|---|---|
| `call_helper(imm)` | Raw `BpfInsn::new(BPF_CALL_OP, ..., imm)` call sites; `prefetch` uses `kernel_sys::BPF_FUNC_map_lookup_elem`; `map_inline` hard-codes helper IDs | `src/test_helpers.rs`, `src/insn.rs`, `passes/map_inline.rs`, `passes/prefetch.rs`, several `*_tests.rs` | `insn.rs` as `BpfInsn::helper_call(id)` plus a small `insn::helper` classifier/constants surface backed by `kernel_sys` | Yes. This is the same ABI instruction and should not have several spellings. | Low for constructor; medium for replacing magic helper IDs because behavior depends on exact helper classification. |
| `exit_insn()` | `BpfInsn::is_exit()` and raw `BPF_EXIT` construction | `src/test_helpers.rs`, `src/insn.rs` | `BpfInsn::exit()` | Yes. Constructor and predicate are the same instruction concept. | Low. |
| `pseudo_call_to(src, dst)` | Relative target math in branch target analysis, CFG, liveness, `ccmp`, `bounds_check_merge`, `map_inline`, `prefetch` | `src/test_helpers.rs`, `analysis/*.rs`, several passes | `insn::branch` or `analysis::branch_target` for target/offset math; constructor can be `BpfInsn::pseudo_call_to(src, dst)` | Yes for encoding and target math; analysis should own interpretation, `insn` should own construction. | Medium. Off-by-one bugs in branch offsets are easy to introduce. |
| `jeq_imm`, `jne_imm`, `jgt_reg` | Pass-local branch constructors such as `skb_load_bytes_tests::helper_call`, `skb_load_bytes.rs::jgt_reg`, and raw `BpfInsn::new` uses | `src/test_helpers.rs`, `passes/skb_load_bytes.rs`, pass tests | `BpfInsn::jump_imm(op, dst, imm, off)` and `BpfInsn::jump_reg(op, dst, src, off)`, with named thin aliases only where they improve readability | Yes. They are all conditional branch encoders. | Medium because jump class/opcode width must stay explicit for 32-bit vs 64-bit variants. |
| `ld_imm64(value)` | `emit_ldimm64`, `combine_ldimm64`, `decode_ldimm64`, `emit_map_ptr_load`, map pseudo load handling | `src/test_helpers.rs`, `passes/utils.rs`, `passes/map_inline.rs`, `passes/const_prop.rs`, `passes/bulk_memory.rs`, `passes/skb_load_bytes.rs` | `insn::ldimm64` helpers: encode/decode raw 64-bit immediate, plus typed constructors for pseudo map fd/index/value/function forms | Yes for two-instruction encoding; pseudo-source variants are related but need typed APIs instead of one loose helper. | Medium-high. `LD_IMM64` has two-slot width and pseudo-map semantics; this needs tests around encoded format. |
| `mov32_reg(dst, src)` | Local `cond_select.rs::mov32_reg`; `BpfInsn` only has `mov64_reg`, `mov64_imm`, `mov32_imm` | `src/test_helpers.rs`, `passes/cond_select.rs`, `src/insn.rs` | `BpfInsn::mov32_reg(dst, src)` | Yes. Same instruction encoding. | Low. |
| `add64_imm(dst, imm)` | `BpfInsn::alu64_imm(BPF_ADD, dst, imm)` | `src/test_helpers.rs`, `src/insn.rs` | Either keep test spelling as a thin wrapper around `BpfInsn::alu64_imm`, or add a small named constructor only if production call sites benefit | Mostly yes. This is an alias for a general ALU constructor, not a separate abstraction. | Low. API alignment matters more than extracting every alias. |
| `st_mem(size, dst, off, imm)` | `BpfInsn::stx_mem` and scattered raw stack/map stores | `src/test_helpers.rs`, `src/insn.rs`, pass code | `BpfInsn::st_mem(size, dst, off, imm)` beside `stx_mem` | Yes. Store-immediate and store-register are sibling instruction constructors. | Low. |
| `sidecar_payload(insn)` | `BpfInsn::kinsn_sidecar`, `BpfInsn::is_kinsn_sidecar`, private sidecar payload decode in `passes/utils.rs` | `src/test_helpers.rs`, `src/insn.rs`, `passes/utils.rs` | `insn::kinsn` or `BpfInsn::kinsn_sidecar_payload()` | Yes. Kinsn sidecar encoding/decoding is one binary ABI concept. | Low-medium. Keep encode/decode in one place to avoid hidden sidecar layout drift. |
| `scalar_reg`, `fp_reg`, `verifier_delta_state*` | Production verifier-state readers such as scalar value and stack-byte extraction in `map_inline`, plus CLI verifier-state parsing in `main.rs` | `src/test_helpers.rs`, `passes/map_inline.rs`, `src/main.rs` | `analysis::verifier_state` for read-only predicates/oracles; test fixture constructors can remain test-only but should target the same types | Partly. Fixtures are test-only, but the meaning of scalar/FP/stack state is production logic. | Medium. This must stay fail-fast and must not become heuristic fallback logic. |
| `stack_snapshot_from_key` | `constant_stack_bytes_for_range`, `constant_stack_byte`, `verifier_known_scalar_value`, and stack-slot layout assumptions around map lookup keys | `src/test_helpers.rs`, `passes/map_inline.rs` | `analysis::verifier_state` for stack snapshot querying; test-only builder next to it under `cfg(test)` | Yes for the verifier stack layout; no for the fixture convenience itself. | High. Stack-slot offsets and fixed-width assumptions directly affect correctness of `map_inline`. |
| `install_map`, `install_array_map` | `mock_maps` and `SnapshotMapProvider`-style map data used by production inputs | `src/test_helpers.rs`, `src/mock_maps.rs`, `src/pass.rs`, `passes/map_inline.rs` | Keep as test-only wrappers over `mock_maps`; do not move into production | No. The test helper installs fake state; production should consume explicit map snapshots/providers. | Low if kept test-only; high if promoted incorrectly. |
| `make_program(insns)` | `BpfProgram::new` plus repeated test fixtures in `pass_tests.rs` | `src/test_helpers.rs`, `src/pass.rs`, pass tests | Keep as test-only fixture, possibly move to `test_helpers::program` | Not really. It is a fixture policy, not a production concept. | Low. |

The important pattern is that instruction constructors and binary encoders are production-grade helpers, while fixtures that install fake map state or choose default pass context should remain test-only. The current issue is not that `test_helpers.rs` exists; it is that some of it is compensating for missing instruction and verifier-state APIs.

## 3. File organization recommendations

### Current layout issues

`src/insn.rs` is the right place for BPF instruction ABI helpers, but it is incomplete. It has the core wrapper, predicates, generic constructors, and some kinsn support, yet tests and passes still create common instructions by spelling raw opcodes directly. This makes tests read differently from production code even when they are expressing the same instruction.

`passes/utils.rs` has unrelated responsibilities in one module: branch fixups, BTF metadata remapping, kinsn proof/sidecar remapping, replacement address maps, unreachable/NOP/dead-def cleanup, `LD_IMM64` emission, and kinsn call offset resolution. The name `utils` is hiding several domain modules with different invariants and different expected callers.

`map_inline.rs` is doing too many kinds of work in one file: map-info analysis reexports, side-input parsing, hint handling, verifier-guided key extraction, R0 use classification, map reference resolution, direct map value rewrites, diagnostics, and tests. That is not a recommendation to split the pass algorithm now, but the generic read-only pieces should not stay pass-local forever.

`analysis/` currently contains CFG, branch targets, and liveness, but other read-only facts are still embedded inside passes: branch target math, register read/write effects, subprogram bounds, verifier scalar/stack queries, and map reference classification. The boundary should be: `analysis/` computes facts about bytecode/verifier/map references; `passes/` decides whether and how to transform.

`pass.rs` mixes core program/pass framework types with map-provider details and pass-local `map_inline` hint reexports. Some of that is historical convenience for `use crate::pass::*`, but it makes the framework layer know too much about one pass.

`mock_maps.rs` is correctly test-only. The problem is only naming/import surface: tests can currently reach both `crate::mock_maps::*` and `crate::bpf::*` aliases, so one preferred test import path would make ownership clearer.

### Recommended layout

This is the target direction, not a single refactor:

```text
src/
  insn.rs                         # BpfInsn wrapper and small common constructors
  insn/
    branch.rs                     # relative offset and target helpers
    helper.rs                     # helper IDs/classification, backed by kernel_sys constants
    ldimm64.rs                    # encode/decode and typed pseudo-source helpers
    kinsn.rs                      # kinsn sidecar encode/decode

  analysis/
    mod.rs
    branch_target.rs
    cfg.rs
    liveness.rs
    reg_effect.rs                 # read/write/def effects shared by liveness and passes
    verifier_state.rs             # exact verifier scalar/stack facts
    map_ref.rs                    # FD/IDX/VALUE/IDX_VALUE map reference resolution

  pass.rs                         # pass trait, program container, context, manager
  program_inputs.rs               # optional later split for map snapshots/providers/hints

  passes/
    mod.rs
    rewrite.rs                    # address maps, branch fixups, BTF annotation remap
    cleanup.rs                    # unreachable block/NOP/dead-def cleanup
    kinsn.rs                      # kinsn replacement emission and BTF/proof remap
    rotate.rs
    cond_select.rs
    ...
    map_inline/
      mod.rs                      # orchestration and pass implementation
      map_info.rs                 # MapInfoAnalysis and result types
      hints.rs                    # hint parsing/resolution if still pass-specific
      key_extraction.rs           # verifier-guided key extraction
      alias.rs                    # R0/key/map alias classification
      rewrite.rs                  # map-inline-specific rewrite emission
      side_inputs.rs              # JSON side-input loading

  test_helpers/
    mod.rs
    insn.rs                       # test aliases over production instruction constructors
    verifier.rs                   # verifier-state fixtures
    maps.rs                       # mock map installation fixtures
    kinsn.rs                      # kinsn fixture helpers
```

`utils.rs` should not be replaced by another broad `common.rs`. If an intermediate step is needed, split it first into `passes/rewrite.rs`, `passes/kinsn.rs`, and `passes/cleanup.rs`, then move instruction-width and `LD_IMM64` helpers into `insn`.

`analysis::verifier_state` should provide exact queries only: known scalar value, frame-pointer stack range, known stack bytes, and maybe verifier-state lookup by instruction index. It must not add fallback behavior for missing verifier data.

`analysis::map_ref` should be the one place that understands `BPF_PSEUDO_MAP_FD`, `BPF_PSEUDO_MAP_IDX`, `BPF_PSEUDO_MAP_VALUE`, and `BPF_PSEUDO_MAP_IDX_VALUE`. Today that knowledge is split between `pass.rs`, `map_info`, and `map_inline`.

## 4. Visibility and export audit

### Over-exported or too broadly visible

| item | why it looks over-exported | recommendation |
|---|---|---|
| `pub mod passes::map_inline` | Exposes pass internals outside the crate because the whole module is public. | Make the module private and reexport only `MapInlinePass`, `MapInfo`, `MapInfoAnalysis`, `MapInfoResult`, and any intentionally shared input types. |
| `MapLookupSite`, `MapInMapChain`, `ConstantKey`, `FixedLoadUse`, `R0UseClassification`, `find_map_lookup_sites`, `find_map_in_map_chains` | These are implementation details or test seams inside `map_inline`, but become public through `pub mod map_inline`. | Prefer private or `pub(crate)`. Use same-module tests or `cfg(test)` helper access rather than public API. |
| `pub use crate::passes::map_inline::{MapInlineHint, MapInlineHintAnchor, MapInlineHintMode}` from `pass.rs` | Framework core reexports a pass-local metadata type. | Move hint ownership to a neutral input module only if it is truly program input; otherwise keep it under `passes::map_inline`. |
| `build_map_fd_bindings` | Search shows only `BpfProgram::set_map_ids` calls it. | Make private, or move into a future `analysis::map_ref`/program input module if more callers appear. |
| `PlatformCapabilities::test_default` | Public method with no current caller found. | Delete, make `cfg(test)`, or replace with an actually used production-named constructor. |
| `PassContext::test_default` | Used by production CLI setup, so the name is misleading even though the function is not dead. | Rename/split into a production constructor such as `PassContext::baseline` or `PassContext::unavailable`, and keep `test_default` as a `cfg(test)` alias if tests want that spelling. |
| `eliminate_unreachable_blocks_with_cfg` | Public in `passes/utils.rs`, but only the wrapper in the same file appears to call it. | Make private unless a pass needs to inject a precomputed CFG. |
| `MapReference` reexport from `passes::mod` | This is an analysis detail; broad reexport invites pass/external code to depend on `map_inline` internals. | Keep it private or reexport from `analysis::map_ref` after that module exists. |

The `mock_maps` public items are acceptable because the whole module is `cfg(test)`. They should remain out of production exports.

### Under-exported or missing shared APIs

| missing/shared API | current symptom | recommended owner |
|---|---|---|
| Helper call constructor and helper ID classifier | `call_helper`, magic helper constants, and `kernel_sys::BPF_FUNC_*` imports coexist. | `insn::helper` plus `BpfInsn::helper_call`. |
| `LD_IMM64` encode/decode and pseudo-source model | `emit_ldimm64`, `combine_ldimm64`, `decode_ldimm64`, and map pseudo loads are implemented in several places. | `insn::ldimm64`. |
| Branch target/relative-offset helper | Target math is repeated in analysis and passes. | `insn::branch` for encoding math; `analysis::branch_target` for discovered targets. |
| Register read/write/def effect | Liveness has private `insn_use_def`; several passes have local `reads_reg`, `writes_reg`, or `reg_write_kind`. | `analysis::reg_effect`. |
| Verifier-state scalar/stack oracle | `test_helpers` constructs states, `main.rs` parses them, `map_inline` interprets them. | `analysis::verifier_state`. |
| Map reference resolution | `pass.rs`, `map_info`, and `map_inline` each know different pseudo-map cases. | `analysis::map_ref`. |
| Kinsn sidecar payload decoder | Tests decode sidecar payload separately from production sidecar emission/remap. | `insn::kinsn` or a kinsn ABI subsection of `insn`. |

## 5. Improvement path

### P0: small API and visibility alignment

| item | change | estimated LOC | risk | expected line savings |
|---|---|---:|---|---:|
| Instruction constructor alignment | Add `BpfInsn::exit`, `helper_call`, `mov32_reg`, `st_mem`, branch constructors, and central `LD_IMM64` encode/decode wrappers; rewrite test helpers as thin aliases. | +80 to +120 | Low-medium | 80 to 150 lines over time, mostly test/local helper deletion |
| Helper ID/classifier surface | Add a helper classification module using `kernel_sys::BPF_FUNC_*`; replace pass-local magic helper IDs where behavior is identical. | +60 to +90 | Medium | 40 to 80 lines and fewer inconsistent constants |
| Visibility narrowing | Make clearly internal functions private or `pub(crate)`: `build_map_fd_bindings`, `eliminate_unreachable_blocks_with_cfg`, unused `PlatformCapabilities::test_default`, and `map_inline` internals exposed only through `pub mod`. | 30 to 60 changed lines | Low | Small direct savings; large API clarity gain |
| Rename misleading production constructor | Split or rename `PassContext::test_default` so production code does not call a test-named API. | 10 to 25 | Low | None, but removes semantic confusion |

P0 is intentionally mechanical and should not change pass behavior.

### P1: split shared modules by responsibility

| item | change | estimated LOC | risk | expected line savings |
|---|---|---:|---|---:|
| Split `passes/utils.rs` | Move branch/BTF remap into `passes/rewrite.rs`, kinsn replacement/BTF/proof code into `passes/kinsn.rs`, cleanup routines into `passes/cleanup.rs`, and instruction-width/`LD_IMM64` helpers into `insn`. | 150 to 250 moved/edited lines | Medium | 0 to 80 direct lines; much better ownership |
| Add `analysis::verifier_state` | Centralize exact scalar and stack-byte queries used by `map_inline`; keep fixture builders under `cfg(test)`. | +200 to +300 | Medium-high | 150 to 250 lines once pass-local/test parsing helpers collapse |
| Add `analysis::map_ref` | Centralize pseudo-map reference resolution and fd/index/value binding interpretation. | +150 to +220 | Medium | 80 to 160 lines and fewer partial map-reference implementations |
| Add `analysis::reg_effect` | Extract instruction use/def/write effects from liveness and pass-local helpers. | +100 to +180 | Medium | 100 to 200 lines over several passes |

P1 should be done one module at a time with focused tests for encoded ABI, branch offsets, and verifier-stack interpretation.

### P2: larger organization cleanup after shared APIs exist

| item | change | estimated LOC | risk | expected line savings |
|---|---|---:|---|---:|
| Split `test_helpers.rs` | Move fixtures into `test_helpers::{insn, verifier, maps, kinsn}`. Production instruction aliases should already be gone or thin. | 100 to 250 moved lines | Low | 0 to 50 direct lines; better navigation |
| Split `map_inline.rs` mechanically | After `verifier_state`, `map_ref`, and instruction helpers exist, split into `map_info`, `hints`, `key_extraction`, `alias`, `rewrite`, and `side_inputs`. | 500+ moved lines | High for merge conflicts, medium for behavior | Little direct savings; major reviewability gain |
| Shrink `pass.rs` | Move map-provider/snapshot/input metadata into `program_inputs.rs` or `map_provider.rs` only after `map_ref` stabilizes. | 100 to 250 moved lines | Medium | Little direct savings; clearer core framework boundary |

P2 should not be started before P0/P1 because otherwise it becomes a file shuffle that preserves the current unclear concepts.

## 6. Changes not recommended

Do not promote all of `test_helpers.rs` into production. Map installation fixtures, default program fixtures, and convenience verifier builders are test policy, not production helpers.

Do not replace `passes/utils.rs` with `common.rs` or another broad utility module. The cleanup only helps if modules are named after the invariant they own.

Do not make APIs public just so tests can reach them. Prefer `pub(crate)`, sibling module tests, or `cfg(test)` fixture modules.

Do not combine this helper/file cleanup with algorithm rewrites from the pass architecture audit. The useful first step is to make concepts have one spelling; pass behavior should stay unchanged.

Do not add fallback verifier or map-reference interpretation while extracting helpers. Shared production helpers should expose missing data as explicit failure or `None` where the caller already handles absence; they should not silently downgrade.

Do not move `mock_maps` into production. The production boundary should remain explicit map snapshots/providers, while mock installation stays a test-only facility.
