# P1-B pass-owned KinsnDescriptor review

Date: 2026-05-09

## Verdict

**pass-with-issues**

The pass-owned descriptor redesign is in place, the panic fix restores proof dispatch to `(btf_id, call_off)`, and the Rust test suite passes: `bpfopt` 332 lib + 15 main + 12 CLI tests, `daemon` 25 tests, total **384 passed**.

One P1 correctness edge remains in the new compound-key registry maintenance: a valid target set can be rejected when two targets share a `btf_id` and one target's final `call_offset` is `0`.

Scope note: current `git diff HEAD -- bpfopt/crates/bpfopt/src daemon/src` contains only `main.rs`, `pass.rs`, and `passes/utils.rs`; the pass-owned redo itself is already present in `HEAD`. I reviewed the current source for the redo design, and the current diff for the panic fix.

## Design Correctness

1. **Pass-owned descriptors: pass**
   - `KinsnDescriptor` lives in `bpfopt/crates/bpfopt/src/pass.rs:25`.
   - Each kinsn pass owns `KINSN_TARGETS`:
     - `rotate.rs:14`
     - `cond_select.rs:16`
     - `ccmp.rs:14`
     - `extract.rs:14`
     - `endian.rs:14`
     - `bulk_memory.rs:22`
     - `prefetch.rs:35`
   - `PassMetadata.kinsn_targets` is the aggregation field at `passes/mod.rs:88`, wired from pass-local constants at `passes/mod.rs:107-113`.
   - Adding a target to an existing pass is now localized to that pass file. Adding a brand-new pass still requires normal pass registration in `passes/mod.rs`.

2. **Registry discovers all targets from `PASS_REGISTRY`: pass**
   - `KinsnRegistry::new()` iterates `PASS_REGISTRY` and `metadata.kinsn_targets` at `pass.rs:794-804`.
   - Count check: `rg -o 'canonical_name: ("bpf_[^"]+"|MEMCPY_TARGET|MEMSET_TARGET|PREFETCH_TARGET_NAME)' ... | wc -l` returned `11`.
   - Targets present: `bpf_rotate64`, `bpf_rotate32`, `bpf_select64`, `bpf_ccmp64`, `bpf_extract64`, `bpf_endian_load16`, `bpf_endian_load32`, `bpf_endian_load64`, `bpf_bulk_memcpy`, `bpf_bulk_memset`, `bpf_prefetch`.

3. **Compound key maintenance: fail for one edge**
   - Normal synchronization is present: `set_btf_id_for_descriptor()` removes old `(btf_id, call_off)` and inserts the new key at `pass.rs:910-928`; `set_call_off_for_descriptor()` does the same at `pass.rs:931-949`; duplicate detection uses `KinsnCallKey { btf_id, call_off }` at `pass.rs:958-976`.
   - P1 edge: `kinsn_registry_from_target()` sets `btf_id` before `call_offset` for each entry at `main.rs:912-918`. Because new entries start with `call_off=0`, this falsely rejects a valid pair when another descriptor already owns `(same_btf_id, 0)`.
   - Reproduction:
     ```text
     target: bpf_endian_load16 { btf_func_id: 128703, call_offset: 0 }
             bpf_rotate64      { btf_func_id: 128703, call_offset: 2 }
     command: ./target/debug/bpfopt --pass noop --input min.bin --output out.bin --target target.json
     output:  error: kinsn btf_id 128703 call_off 0 is already registered for bpf_endian_load16
     ```
   - `call_offset=0` is a valid vmlinux-BTF encoding per `daemon/src/bpf.rs:61-64`, so this should be allowed when the final compound keys differ.

4. **CLI alias canonicalization and JSON output: pass**
   - Alias canonicalization covers all v3 aliases, including `rotate64`, `bulk_memcpy`, `bpf_memcpy_bulk`, and `memcpy_bulk`, in `main.rs:1233-1263`.
   - `list-passes --json` preserves the `kinsns_used` field via `#[serde(rename = "kinsns_used")]` at `main.rs:180` and emits pass metadata from `entry.metadata.kinsn_targets` at `main.rs:269-284`.
   - Observed output includes all kinsn passes. Example: `bulk-memory` emits `json_name: bpf_bulk_memcpy` with probe alias `bpf_memcpy_bulk`; rotate/endian/prefetch emit their expected `bpf_*` probe names.

5. **Descriptor proof decoder pointers: pass**
   - Each descriptor has a pass-local `decode_proof`:
     - rotate: `rotate.rs:18`, `rotate.rs:23`
     - cond_select: `cond_select.rs:19`
     - ccmp: `ccmp.rs:17`
     - extract: `extract.rs:17`
     - endian: `endian.rs:18`, `endian.rs:23`, `endian.rs:28`
     - bulk_memory: `bulk_memory.rs:26`, `bulk_memory.rs:31`
     - prefetch: `prefetch.rs:38`

6. **`remap_kinsn_btf_metadata` dispatch: pass**
   - `collect_kinsn_proof_regions()` reads both `imm` and `off` from the kinsn call at `passes/utils.rs:263-266`.
   - `kinsn_proof_len()` dispatches through `registry.lookup_by_kinsn_call(btf_id, call_off)` and then calls `desc.decode_proof` at `passes/utils.rs:289-302`.
   - Regression coverage exists for duplicate BTF ids with different call offsets at `passes/utils.rs:1142-1179`.

## CLAUDE.md Compliance

1. **No hardcoded runtime BTF IDs: pass**
   - Production path reads IDs from target JSON / CLI (`main.rs:912-939`). Numeric BTF IDs found by grep are test fixtures only.

2. **No forbidden silent-error patterns: pass**
   - `rg -n '#\[allow\(dead_code\)\]|unwrap_or_default|\.ok\(\)|let _ = ' bpfopt/crates/bpfopt/src daemon/src` returned zero matches.

3. **No fallback / silenced errors in reviewed change: pass-with-note**
   - Current panic-fix path propagates lookup and decoder errors through `anyhow::Result`.
   - Existing pass-level "kfunc unavailable" skips remain outside this change and are guarded by CLI required-kinsn validation for normal CLI use.

4. **No forbidden area changes in review scope: pass-with-note**
   - `git diff --name-only HEAD -- vendor/linux-framework runner corpus e2e micro daemon/src` returned no tracked diff.
   - Worktree note: `git status` currently shows unrelated untracked `corpus/results/...` and `docs/paper` changes outside the requested code review scope.

5. **No CLI path-dep cross dependency: pass**
   - `daemon/Cargo.toml` does not depend on `bpfopt`; the remaining path entries are the crate binary paths themselves.

6. **No revert/restore commit by this change: pass**
   - No commit was made for this review. Existing older history contains revert/restore commits, but none are introduced by the reviewed working-tree diff.

7. **No new `.sh` / `.py` scripts: pass**
   - `find bpfopt/crates/bpfopt/src daemon/src -maxdepth 5 \( -name '*.sh' -o -name '*.py' \) -print` returned zero files.

## Bytecode Identity

1. **Rust tests: pass**
   - `cd bpfopt && cargo test --workspace --locked`: 332 + 15 + 12 passed.
   - `cd daemon && cargo test --workspace --locked`: 25 passed.
   - Total observed: 384 passed.

2. **Emit paths: pass**
   - Current diff does not touch pass emit files for `rotate`, `cond_select`, `ccmp`, `extract`, `endian_fusion`, `bulk_memory`, or `prefetch`.
   - The shared emitter remains `emit_packed_kinsn_call_with_off()` at `passes/utils.rs:830-838`.
   - The pass files still feed target-name-derived `btf_id` and `call_off` into the same emitter, e.g. rotate `rotate.rs:174-185`, cond_select `cond_select.rs:234-248`, ccmp `ccmp.rs:261-274`, extract `extract.rs:189-200`, endian `endian.rs:514-525`, bulk_memory `bulk_memory.rs:284-300`, prefetch `prefetch.rs:320-330`.

3. **Panic-fix byte-identical evidence: pass**
   - The implementation change is in registry/proof lookup and tests only; it does not alter payload packing or instruction emission.
   - The panic-fix report's SHA comparison covers one rotate lowering case. Static diff evidence is stronger here: no kinsn pass emit path changed in the current diff.

## Repeated / Dead Code

1. **Forbidden grep: pass**
   - `#[allow(dead_code)]`, `unwrap_or_default`, `.ok()`, and `let _ = `: zero matches in `bpfopt/crates/bpfopt/src daemon/src`.

2. **`KinsnSlot`: pass**
   - `rg -n 'KinsnSlot' bpfopt/crates/bpfopt/src daemon/src` returned zero matches.

3. **`ProofLayout`: pass**
   - `rg -n 'ProofLayout' bpfopt/crates/bpfopt/src daemon/src` returned zero matches.

4. **Legacy target table names: pass**
   - `crate::kinsn`, `mod kinsn`, `pub mod kinsn`, `TargetSpec`, and `KinsnRef`: zero matches in `bpfopt/crates/bpfopt/src daemon/src`.
   - `find bpfopt/crates/bpfopt/src daemon/src -name 'kinsn.rs' -print` returned zero files.

5. **Dead helper / wrapper scan: pass-with-note**
   - New registry helpers have real callers: `lookup_by_kinsn_call` is used by proof remap and tests; `target_name_for_pass` is used by `resolve_kinsn_call_off_for_pass`; payload helpers are used by pass-local decoders.
   - No dead helper was found in the reviewed paths.

## Regression Coverage

1. **Full allowed Rust test coverage: pass**
   - 384 tests pass as above.

2. **Kinsn pass tests cover key paths: pass**
   - rotate tests cover 64/32-bit patterns, emit, unavailable kfunc, packed ABI, branch/subprog/liveness cases (`rotate_tests.rs:25-427`).
   - cond_select tests cover pattern matrices, capability matrix, emit variants, aliases/overlap (`cond_select_tests.rs:63-438`).
   - ccmp tests cover payload encoding/rejection, arch gate, emit, overlong and subprog-boundary cases (`ccmp_tests.rs:62-194`).
   - extract tests cover scan matrix, emit, branch/subprog/static call offset, edge widths and masks (`extract_tests.rs:18-492`).
   - endian tests cover all sizes, narrowing, unavailable/specific-size unavailable, packed ABI, branch fixup, per-size call offsets (`endian_tests.rs:28-514`).
   - bulk_memory tests cover memcpy/memset, segmentation, branch fixup, alias gate, overlap skip, proof tmp live-out (`bulk_memory_tests.rs:336-540`).
   - prefetch tests cover packet/map-value insertion, profile filtering, instruction-boundary insertion, payload validation (`prefetch_tests.rs:78-149`).

## Issues

### P0

None found.

### P1

1. **Valid duplicate `btf_id` with one final `call_offset=0` is falsely rejected**
   - Evidence: `pass.rs:923-945` updates the compound index in two separate field setters; `main.rs:912-918` calls the setters sequentially per target.
   - Reproduction above exits 1 even though final keys would be `(128703, 0)` and `(128703, 2)`.
   - Impact: the panic fix correctly models runtime identity as `(btf_id, call_off)`, but the mutation API can still reject a valid compound-key state before the final call offset is installed. This matters for vmlinux/module combinations because `call_offset=0` is valid.
   - Recommended fix: add an atomic setter such as `set_kinsn_call_for_target_name(target, btf_id, call_off)` and use it in target JSON parsing, or parse all target entries first and rebuild `by_call` from final `(btf_id, call_off)` pairs in one pass. Add a regression test for duplicate `btf_id` where one target has `call_offset=0` and the other has a non-zero offset.

### P2

1. **Coverage gap: existing duplicate-BTF regression omits `call_offset=0`**
   - Current tests cover duplicate BTF ids at call offsets `1/2` (`main.rs:1338-1378`) and `3/5` (`passes/utils.rs:1142-1179`), but not `0/N`.
   - This is the test gap that let the P1 edge survive.

2. **Worktree hygiene outside review scope**
   - `git status` shows unrelated untracked corpus result directories and a modified `docs/paper` submodule. They are not part of `git diff HEAD -- bpfopt/crates/bpfopt/src daemon/src`, but should be cleaned or intentionally tracked before final handoff.

## Recommended Next Step

Fix the P1 registry mutation edge before moving to P1-C. After the atomic/final-state registry update lands, rerun:

```sh
cd bpfopt && cargo test --workspace --locked
cd ../daemon && cargo test --workspace --locked
```

No `make`, corpus, e2e, or micro run is needed for this review gate.
