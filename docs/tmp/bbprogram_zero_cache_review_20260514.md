# bbprogram zero-cache review 2026-05-14

## Re-review 2026-05-14

Verdict: FAIL under the exact requested greps. The old `UseDefGraph.uses` field is gone, but two broad literal checks still hit pass-local names.

1. `UseDefGraph` shape: PASS.
   - `rg -n "pub\\(crate\\) struct UseDefGraph|pub\\(super\\) defs: BTreeMap<DefSite, Vec<UseSite>>|uses: BTreeMap<UseSite" crates/bpfopt/src/analysis/bbprogram_use_def.rs`
   - Hits only `crates/bpfopt/src/analysis/bbprogram_use_def.rs:28-29`: `UseDefGraph` contains `defs: BTreeMap<DefSite, Vec<UseSite>>`.

2. No `use_def.uses`: FAIL literally, PASS for graph access.
   - `rg -n "use_def\\.uses\\b" crates/bpfopt/src` hits `crates/bpfopt/src/passes/map_inline.rs:2851`: local `RegUseDefSet` from `insn_use_def_set(insn)`.
   - `rg -n "self\\.use_def\\.uses\\b|prog\\.use_def\\.uses\\b" crates/bpfopt/src` produced no output.

3. `compute_site_liveness` and `use_def_site_facts`: PASS.
   - `crates/bpfopt/src/analysis/bbprogram.rs:543`, `552`, `561`: `use_def_site_facts()` reads `node.uses`/`node.defs` and `block.terminator_uses`/`block.terminator_defs`.
   - `crates/bpfopt/src/analysis/bbprogram.rs:1435`, `1446-1456`: `compute_site_liveness()` builds use/def sets from `InsnNode` and `BasicBlock` fields.

4. Zero-cache invariants: FAIL literally because `_cache:` still exists as a pass-local variable; otherwise the bbprogram storage invariants hold.
   - `rg -n "Mutex<" crates/bpfopt/src` produced no output.
   - `rg -n "_cache:" crates/bpfopt/src` hits `crates/bpfopt/src/passes/map_inline.rs:2166`: local `map_cache`, not `ProgramCFG` storage.
   - `ProgramCFG` fields remain `blocks`, `entry`, `use_def`, `kop_reg`, `map_bindings`, `func_info`, `line_info`, `prog_type`: `crates/bpfopt/src/analysis/bbprogram.rs:68-76`.
   - `rg -n "BTreeMap<InsnSite|HashMap<InsnSite" crates/bpfopt/src` hits type aliases, return values, locals, and pass-local maps; no `ProgramCFG` field.
   - Only persistent use-def index is `UseDefGraph.defs`: `crates/bpfopt/src/analysis/bbprogram_use_def.rs:28-29`; `ProgramCFG` stores it at `crates/bpfopt/src/analysis/bbprogram.rs:71`.
   - Per-instruction facts live on `InsnNode`: `crates/bpfopt/src/analysis/bbprogram.rs:104-119`.
   - Per-terminator facts live on `BasicBlock`: `crates/bpfopt/src/analysis/bbprogram.rs:172-184`.
   - `find crates/bpfopt/src -name verifier_facts.rs -print` produced no output.

Scope: `/home/yunwei37/workspace/bpf-benchmark/bpfopt/crates/bpfopt/src`.

Verdict: FAIL. One residual persistent map contradicts item 4: `ProgramCFG` stores `UseDefGraph`, and `UseDefGraph` still contains a persistent `BTreeMap<UseSite, Vec<DefSite>>` in addition to the allowed def-to-uses index.

## Residual contradiction

- `crates/bpfopt/src/analysis/bbprogram.rs:71`: `ProgramCFG` stores `use_def: UseDefGraph`.
- `crates/bpfopt/src/analysis/bbprogram_use_def.rs:29`: allowed persistent index: `defs: BTreeMap<DefSite, Vec<UseSite>>`.
- `crates/bpfopt/src/analysis/bbprogram_use_def.rs:30`: forbidden extra persistent index: `uses: BTreeMap<UseSite, Vec<DefSite>>`.
- `crates/bpfopt/src/analysis/bbprogram_use_def.rs:136`: `graph.uses.insert(use_site, defs);` populates the extra index.
- `crates/bpfopt/src/analysis/bbprogram.rs:550`: `use_def_site_facts()` reads `self.use_def.uses.keys()`.
- `crates/bpfopt/src/analysis/bbprogram.rs:1449`: liveness still reconstructs use sets from `prog.use_def.uses.keys()`.

## Checklist

1. No `Mutex<` anywhere in `analysis/`: TRUE.
   - Grep: `rg -n "Mutex<" crates/bpfopt/src/analysis` produced no output.

2. No `_cache:` fields on `ProgramCFG`: TRUE.
   - Grep: `rg -n "_cache:" crates/bpfopt/src/analysis` produced no output.
   - `ProgramCFG` fields at `crates/bpfopt/src/analysis/bbprogram.rs:68-77` are `blocks`, `entry`, `use_def`, `kop_reg`, `map_bindings`, `func_info`, `line_info`, and `prog_type`; no `_cache` fields.

3. No `BTreeMap<InsnSite,` or `HashMap<InsnSite,` as persistent `ProgramCFG` storage: TRUE.
   - `ProgramCFG` has no direct `InsnSite` map fields: `crates/bpfopt/src/analysis/bbprogram.rs:68-77`.
   - Grep hits are non-`ProgramCFG` persistent storage:
     - `crates/bpfopt/src/analysis/bbprogram.rs:16`: `BtfMetadataMap = BTreeMap<InsnSite, usize>`; lift/BTF boundary, not stored on `ProgramCFG`.
     - `crates/bpfopt/src/verifier_log.rs:708`: `VerifierStatesBySite = BTreeMap<InsnSite, Arc<[VerifierInsn]>>`; lift boundary, distributed into nodes at `crates/bpfopt/src/analysis/bbprogram_lift.rs:126-141`.
     - `crates/bpfopt/src/analysis/bbprogram.rs:499`, `543`, `575`, `578`, `695`, `1239`, `1346`, `1347`, `1438`: transient analysis return values/locals that are written back to inline fields.
     - `crates/bpfopt/src/passes/bulk_memory.rs:143`, `crates/bpfopt/src/passes/map_inline.rs:580`, `3669`: pass-local maps, not `ProgramCFG` storage.

4. The only allowed persistent map on `ProgramCFG` is `UseDefGraph`'s `BTreeMap<DefSite, Vec<UseSite>>`: FALSE.
   - Allowed: `crates/bpfopt/src/analysis/bbprogram_use_def.rs:29`.
   - Contradiction: `crates/bpfopt/src/analysis/bbprogram_use_def.rs:30` adds `BTreeMap<UseSite, Vec<DefSite>>`.
   - Persisted through `ProgramCFG.use_def` at `crates/bpfopt/src/analysis/bbprogram.rs:71`.

5. Per-instruction facts live on `InsnNode`: TRUE for field placement, with the item 4 caveat for duplicated use-site indexing.
   - `crates/bpfopt/src/analysis/bbprogram.rs:97-119` contains `insn`, `ldimm64_second`, `pc_relative_ldimm64_target`, `btf_pc`, `verifier_states`, `uses`, `defs`, `live_in`, `live_out`, and `local_reg_state`.
   - `crates/bpfopt/src/analysis/bbprogram_use_def.rs:151-176` populates `uses`/`defs` on `InsnNode` and terminator fields.
   - `crates/bpfopt/src/analysis/bbprogram.rs:954-969` writes `local_reg_state`; `crates/bpfopt/src/analysis/bbprogram.rs:973-1000` writes liveness.

6. Per-terminator facts live on `BasicBlock`: TRUE for field placement, with the item 4 caveat for duplicated use-site indexing.
   - `crates/bpfopt/src/analysis/bbprogram.rs:163-184` contains `terminator_branch_profile`, `terminator_btf_pc`, `terminator_verifier_states`, `terminator_uses`, `terminator_defs`, `terminator_live_in`, `terminator_live_out`, and `terminator_local_reg_state`.
   - `crates/bpfopt/src/analysis/bbprogram_lift.rs:56-70` initializes those fields.
   - `crates/bpfopt/src/analysis/bbprogram_lift.rs:136-141` writes terminator verifier states.
   - `crates/bpfopt/src/analysis/bbprogram.rs:629-653` writes terminator branch profiles.

7. `verifier_facts.rs` is deleted and helpers moved to `src/verifier_log.rs`: TRUE.
   - `find crates/bpfopt/src/analysis -maxdepth 1 -type f -name 'verifier_facts.rs' -print` produced no output.
   - `crates/bpfopt/src/analysis/mod.rs:4-9` has no `verifier_facts` module.
   - `crates/bpfopt/src/analysis/mod.rs:11` re-exports `VerifierStatesBySite` from `crate::verifier_log`.
   - `crates/bpfopt/src/verifier_log.rs:693-708` states the helpers formerly lived in `analysis/verifier_facts.rs`.
   - Helper functions are now in `crates/bpfopt/src/verifier_log.rs:710`, `725`, `736`, and `763`.
