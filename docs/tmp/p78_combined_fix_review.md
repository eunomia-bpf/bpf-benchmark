# P78 Combined Fix Self-Review
A. File decisions:
| File(s) | Decision + reason |
| --- | --- |
| `bpfget/src/main.rs` | Partial keep: BTF parser residue deleted; thin live metadata/target probing kept because it calls libbpf-sys/kernel-sys. |
| `kernel-sys/src/lib.rs` | Partial keep: syscall boundary and BTF record/prog-load plumbing kept; custom parsing removed. |
| `bpfverify/src/main.rs`, `bpfrejit/src/main.rs` | Partial keep: only BTF metadata flags/load replay were added; no CLI cross-dep introduced. |
| `bpfopt/src/passes/utils.rs` | Keep/add: central `remap_btf_metadata()` helper plus bug-detection test. |
| `map_inline.rs`, `wide_mem.rs`, `bulk_memory.rs`, `const_prop.rs`, `dce.rs` | Partial keep: length-changing passes now call metadata remap after bytecode rewrites. |
| `branch_flip.rs` | Partial keep: heuristic fallback deleted; per-site profile required for transformation. |
| `pass.rs`, `pass_tests.rs` | Partial delete: `disabled_passes`, dead public API, and const_prop+dce fixed-point special case removed. |
| `insn.rs` | Partial delete: unused helpers/constants removed; ABI/layout tests retained. |
| `passes/mod.rs`, `passes/mod_tests.rs` | Partial delete: dead public pipeline helpers removed; test-only builder scoped with `cfg(test)`. |
| `bpfopt/src/main.rs` | Partial delete: unused `analyze` command/handler/report helpers removed; transform/list/scan commands kept. |
| `bpfprof/src/main.rs` | Partial delete: unused `--show` mode/table code removed; JSON output path kept. |
| `daemon/src/{server,commands,bpf,invalidation}.rs` | Partial keep: fail-fast request/watch/status fixes, disabled_passes removal, legacy response field pruning, pub narrowing. |
| `daemon/README.md` | Partial rewrite: v3 socket-to-CLI behavior and explicit `enabled_passes` examples kept; stale bare optimize/per-pass text removed. |
| `docs/daemon-architecture.md` | Delete: stale v2/per-pass verify/rollback daemon design, now misleading. |
| `docs/kernel-jit-optimization-plan.md`, `docs/tmp/bpfopt_design_v3.md` | Partial update: implementation state aligned after deleting `analyze` and unused per-pass script. |
| `scripts/README.md`, `scripts/per-pass-verify.sh` | Delete: no real caller; script had dry-run/rollback behavior outside current fail-fast rule. |
| `docs/tmp/p81_strict_review.md` | Keep: parallel docs-only commit, counted in LOC table but not edited by P78. |
B. P74/P76 criticals:
| Critical | Status |
| --- | --- |
| daemon bare `optimize`/`optimize-all` missing `enabled_passes` | ✅ fixed: rejected before `bpfopt` fork with error JSON/tests. |
| `ProgramWatcher` swallowed enumeration errors | ✅ fixed: `from_live()`/`tick()` return `Result`; serve path propagates. |
| `status` hid `list-passes` failure | ✅ fixed: failure becomes error JSON, not `"status":"ok"`. |
| `disabled_passes` exclusion surface | ✅ fixed: request/result/policy/tests removed. |
| `branch_flip` heuristic fallback | ✅ fixed: missing per-site profile skips site, no fallback transform. |
C. line_info/func_info fix:
- `BpfProgram` carries raw func/line info bytes plus record sizes; bpfget extracts them, daemon forwards them, bpfverify/bpfrejit pass them into kernel `PROG_LOAD`.
- `remap_btf_metadata(prog, addr_map)` drops records whose `insn_off` maps to deleted instructions and shifts survivors to the new byte offset.
- All length-changing passes call it after remapping annotations/branches.
- Test covers 4-insn metadata `(0,1,2,3)` with delete+insert, expecting line records `(0,2_new,3_new)` and func record at `0`.
D. LOC delta:
| Scope | Insertions | Deletions | Net |
| --- | ---: | ---: | ---: |
| Before Stage 8 doc, `6ab0083a..HEAD` | 1051 | 2624 | -1573 |
| This review doc | 59 | 0 | +59 |
| Expected final, `6ab0083a..HEAD` | 1110 | 2624 | -1514 |
E. Checklist:
- ✅ line_info helper + unit test
- ✅ daemon bare optimize fail-fast
- ✅ ProgramWatcher Result propagation
- ✅ status failure -> error JSON
- ✅ disabled_passes full-chain deletion
- ✅ branch_flip heuristic deletion
- ✅ dead public API narrowed/deleted
- ✅ bpfopt analyze deleted because no runner/scripts/Makefile/*.py caller
- ✅ per-pass-verify.sh deleted because no caller
- ✅ removed-app residue grep clean in active runner/containers/repos/Makefile paths
- ✅ daemon legacy fields deleted
- ✅ bpfprof --show deleted because no caller
- ✅ net LOC remains <= -1500 after this doc
- ✅ cargo build/clippy/test passed for bpfopt workspace and daemon in Stage 8
- ✅ did not touch `vendor/linux-framework/` or `module/`
- ✅ did not touch `runner/libs/`, `corpus/`, `e2e/cases/`, or `micro/driver.py`
- ✅ `kernel-sys` remains the only direct BPF syscall boundary
- ✅ CLI crates still have no path-dependency on each other
