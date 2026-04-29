# bpfopt / daemon pass design gap review (2026-04-29)

Scope: compared `docs/kernel-jit-optimization-plan.md` and `CLAUDE.md` with the current checkout. Current `main` already has the daemon-to-`bpfopt-core` migration; this review treats that migrated tree as the implementation.

I only reviewed bpfopt/daemon pass architecture and behavior. I did not run VM/corpus tests, and did not edit code or design docs.

## Design Requirements Extracted

From `docs/kernel-jit-optimization-plan.md`:

- Userspace daemon owns policy: discovery, static analysis, pass selection, profiling, bytecode rewrite, per-pass verify, final REJIT.
- Kernel remains the safety boundary: every rewritten program is verified by the normal verifier before swap.
- Daemon runtime CLI has converged to `bpfrejit-daemon serve --socket`; JSON commands are `optimize` and `optimize-all`.
- Daemon must use raw `bpf(2)` syscalls only, no libbpf runtime dependency.
- Per-pass verify must use `BPF_PROG_LOAD` dry-run after each changed pass; final apply is one `BPF_PROG_REJIT` atomic swap.
- Verifier-in-the-loop means `BPF_PROG_LOAD(log_level=2)` logs feed verifier constants/ranges into later passes.
- Structured per-pass records must include `pass`, `changed`, `sites_applied`, `insn_delta`, `verify_result`, `verify_error`, and `action`.
- `bpfopt/` architecture after #646: pass code is extracted to `bpfopt-core` and `bpfopt` CLI; `verify`, `rejit`, `profiler`, `syscall`, and `daemon` logic remain in `daemon/`; `bpfopt-core` must not carry per-pass verify/rollback or REJIT transport state.
- Security passes (`speculation_barrier`, `dangerous_helper_firewall`, `live_patch`) are not in the default pipeline.
- Current in-scope performance passes include `wide_mem`, `rotate`, `cond_select`, `extract`, `endian_fusion`, `map_inline`, `const_prop`, `dce`, `bounds_check_merge`, `bulk_memory`; `branch_flip` exists but is not a default benchmark pass; helper specialization is marked research-complete, not mainline complete.
- `128-bit LDP/STP` is documented as implemented at module level and described as adjacent load/store pair lowering to `bpf_ldp128` / `bpf_stp128`.
- Dynamic map inlining should not require frozen maps when direct value access is available; invalidation is driven by the persistent daemon tick, not a separate `watch` command.

From `CLAUDE.md`:

- Never filter, skip, or exclude BPF programs from ReJIT. Errors must be recorded and surfaced naturally.
- No per-prog_type pass exclusions in benchmark config and no exclusion lists.
- Benchmark apps must load BPF programs through real app startup; framework must not directly load `.bpf.o` for apps.
- Corpus metrics are per-program and should not add informational-only result fields that hide failure.

## Current Implementation Snapshot

- `daemon/Cargo.toml` now depends on `bpfopt-core` (`daemon/Cargo.toml:11-18`).
- `daemon/src/main.rs` reexports `bpfopt_core::{analysis, insn, pass, passes, verifier_log}` and keeps daemon-only modules for `bpf`, `commands`, `invalidation`, `kfunc_discovery`, `profiler`, and `server` (`daemon/src/main.rs:7-32`).
- `daemon/src/pass.rs`, `daemon/src/analysis/*`, `daemon/src/passes/*`, and related daemon pass tests no longer exist in the tracked daemon tree. Active pass code is under `bpfopt/crates/bpfopt-core/src`.
- `bpfopt-core` declares itself "Zero kernel dependency - pure bytecode in, bytecode out" (`bpfopt/crates/bpfopt-core/src/lib.rs:1-7`).
- `bpfopt-core` pass registry contains 12 passes: `map_inline`, `const_prop`, `dce`, `skb_load_bytes_spec`, `bounds_check_merge`, `wide_mem`, `bulk_memory`, `rotate`, `cond_select`, `extract`, `endian_fusion`, `branch_flip` (`bpfopt/crates/bpfopt-core/src/passes/mod.rs:52-118`).
- Benchmark config default includes 11 passes and excludes `branch_flip` (`corpus/config/benchmark_config.yaml:1-27`), matching the design's "non-default benchmark pass" statement.

## Pass Inventory

| Design pass | Current status | Gap |
| --- | --- | --- |
| `wide_mem` | Implemented in `bpfopt-core`. | Behavior is narrower than the high-level design: only widths 2/4/8 and likely packet pointers in XDP/TC are skipped (`wide_mem.rs:460-502`). |
| `rotate` | Implemented. | Skips every program containing BPF-to-BPF pseudo-calls (`rotate.rs:52-66`), so coverage is intraprocedural only. |
| `cond_select` | Implemented. | Requires CMOV, kfunc, packed ABI, and packed sites require register true/false operands (`cond_select.rs:130-178`, `cond_select.rs:220-225`). |
| `extract` / bitfield extract | Implemented. | Pattern is only `RSH64_IMM` followed by `AND64_IMM` with a low contiguous mask (`extract.rs:12-27`). |
| `branch_flip` | Implemented. | Benchmark config excludes it, as designed. Daemon/core default policy still includes it unless the client sends an explicit enabled list (`pass.rs:935-940`). Runtime behavior skips with no PMU data (`branch_flip.rs:85-97`) and uses heuristic fallback when per-site profiles are absent (`branch_flip.rs:153-173`). |
| `endian_fusion` | Implemented. | Potential transport bug: pass can emit 16/32/64-bit endian kfuncs, but `KinsnRegistry::target_name_for_pass("endian_fusion")` maps only to `bpf_endian_load32` (`pass.rs:703-711`), and the pass resolves a single call offset before emitting all site sizes (`endian.rs:326-350`). If static call offsets or fd-array slots differ per endian target, 16/64-bit sites can use the wrong transport metadata. |
| `map_inline` | Implemented with live map providers and invalidation. | Direct-value speculative inline no longer requires frozen maps (`map_info.rs:57-65`, `map_inline.rs:819-836`), but mutable map lookup sites are still skipped if the returned value has non-load uses (`map_inline.rs:901-914`), and pseudo-map-value constantization remains frozen-only (`map_inline.rs:1476-1510`). |
| `const_prop` | Implemented. | Uses verifier exact constants only, not the full documented tnum/range oracle. The core oracle keeps `exact64`/`exact32` facts (`const_prop.rs:120-173`), so range-driven branch simplification is not implemented. |
| `dce` | Implemented. | No major design gap observed. |
| `bounds_check_merge` | Implemented. | It is explicitly limited to packet program types (`bounds_check_merge.rs:94-95`, `bounds_check_merge.rs:237-248`), which is consistent with the packet guard-window design but narrower than a generic bounds pass. |
| `bulk_memory` | Implemented. | It handles memcpy/memset bulk kinsns with 32-byte minimum and 128-byte chunks (`bulk_memory.rs:14-17`); it is not the 128-bit adjacent load/store pass. |
| `128-bit LDP/STP` | Not implemented as a daemon/bpfopt-core pass. | No `ldp/stp` or `bpf_ldp128`/`bpf_stp128` pass exists in the active registry or source search. This is the clearest design-mentioned pass missing from the pass implementation. |
| Helper call specialization | Implemented as `skb_load_bytes_spec`. | Design marks this as research-complete, but code includes it in the main registry and benchmark default (`passes/mod.rs:68-72`, `benchmark_config.yaml:12`, `benchmark_config.yaml:26`). Behavior is narrow: only SCHED_CLS/SCHED_ACT, constant offset, stack destination, and `len <= 8` (`skb_load_bytes.rs:106-114`, `skb_load_bytes.rs:160-179`). |

## Architecture Gaps

1. `bpfopt-core` still carries daemon runtime state.

   The design explicitly says `bpfopt-core` must not carry per-pass verify/rollback or REJIT transport state. Current `BpfProgram` includes `required_btf_fds` with a comment tying it to the serve REJIT fd-array path (`pass.rs:54-56`). `PassResult` includes `verify` and `rollback` (`pass.rs:475-478`), and `PassVerifyResult` / `PassRollbackResult` live in `bpfopt-core` (`pass.rs:520-542`). `PassManager::run_with_verifier` performs per-pass verifier callbacks and rollback (`pass.rs:1063-1071`, `pass.rs:1213-1236`). This is daemon behavior embedded in the core pass library.

2. REJIT fd-array transport is in `bpfopt-core`.

   `PassContext` includes `KinsnCallResolver` (`pass.rs:666-670`), `KinsnRegistry` includes `target_btf_fds` and `target_call_offsets` (`pass.rs:681-700`), and `FdArrayKinsnCallResolver` mutates `program.required_btf_fds` (`pass.rs:811-827`). This is useful for the daemon, but it contradicts the design boundary that REJIT transport state belongs in `daemon/`, not `bpfopt-core`.

3. Docker/runtime build inputs were not updated for the new path dependency.

   `daemon/Cargo.toml` now depends on `../bpfopt/crates/bpfopt-core`, but the runtime Dockerfile still copies only `daemon` before building the daemon (`runner/containers/runner-runtime.Dockerfile:346-351`). `DAEMON_SOURCE_FILES` also tracks only `daemon/src`, `daemon/Cargo.toml`, `daemon/Cargo.lock`, and `daemon/Makefile` (`runner/mk/build.mk:70`), so bpfopt-core source changes are not part of daemon rebuild inputs (`runner/mk/build.mk:112-116`, `runner/mk/build.mk:269-271`). As written, image daemon builds can miss the path dependency or fail because `./bpfopt` is absent in the image build layer.

4. `bpfopt-core` has offline and live concerns mixed into one program object.

   `BpfProgram` contains offline map snapshots (`map_values`, `map_metadata`) and live provider traits used by the daemon (`map_info_provider`, `map_value_provider`) (`pass.rs:70-81`). The provider abstraction is a reasonable extraction seam, but it currently lives alongside REJIT fd-array and per-pass verification machinery. That makes the crate neither a pure bytecode library nor a clean daemon adapter boundary.

5. The migrated source-of-truth is not reflected everywhere outside Rust module imports.

   In the current checkout, `daemon/src/passes/` no longer exists, which is consistent with using `bpfopt-core` as the single pass implementation. The migration is still incomplete at the architecture level because Docker/Makefile inputs do not include `bpfopt/`, and because `bpfopt-core` still owns daemon runtime concerns.

## Functional Gaps

1. Missing daemon/bpfopt pass for 128-bit LDP/STP.

   The design describes adjacent load/store pair lowering to `bpf_ldp128` / `bpf_stp128`, but active pass registry has no such pass. `bulk_memory` is not a substitute: it targets large scalarized memcpy/memset runs (`bulk_memory.rs:14-17`, `bulk_memory.rs:122-188`), not adjacent 128-bit pair load/store.

2. Verifier const propagation does not use range/tnum facts.

   The design says `log_level=2 -> tnum/range constants -> MOV imm -> branch folding`. Current `ConstPropPass` derives only exact register facts (`exact64`, `exact32`) from verifier states (`const_prop.rs:120-173`). Verifier log parsing may retain richer state, but this pass does not use ranges/tnums for branch folding.

3. Helper specialization is ahead of the design status.

   `skb_load_bytes_spec` is in the active registry and benchmark default, while the design still labels helper call specialization as research complete. Either the design is stale or this pass is promoted without the design update.

4. `branch_flip` is default-enabled in core/daemon policy but disabled by benchmark config.

   The benchmark default matches the design, but daemon requests without an explicit enabled list use `default_enabled_passes()`, which includes every registry entry including `branch_flip` (`pass.rs:935-940`). The pass noops without PMU data, but the policy surface is still different from the design phrase "default benchmark profile not enabled." This is low risk for corpus runs that use `benchmark_config.yaml`, but it is a daemon default mismatch.

5. Map-inline invalidation is implemented, but only as polling re-optimization.

   `MapInvalidationTracker` stores `(prog_id, map_fd, key, expected_value)` and invalidates when a polled map value changes (`invalidation.rs:11-18`, `invalidation.rs:124-160`). `serve` checks every second and reoptimizes (`server.rs:227-255`). This matches the current "serve tick" design, but it is not event-driven deopt and failures in invalidation reoptimization terminate the serve loop via `?` (`server.rs:31-75`, `server.rs:227-255`). That surfaces failure, but it also makes one invalidation failure daemon-fatal.

## Behavior Gaps

1. Per-pass result schema uses `pass_name`, not the documented `pass` field.

   `PassDetail` serializes `pass_name` (`commands.rs:115-134`). The design requires `pass`/`changed`/`sites_applied`/`insn_delta`/`verify_result`/`verify_error`/`action`. The information is present, but the field name does not match the documented schema.

2. `optimize-all` can return top-level `"status": "ok"` while hiding individual errors behind a count.

   `collect_live_program_candidates()` fails the whole request if enumeration/original-bytecode collection fails (`server.rs:118-136`), which is good. But after candidates are collected, per-program `try_apply_one` errors only increment `errors`, and the response still returns `"status": "ok"` with no per-program error messages (`server.rs:622-658`). That weakens the zero-silent-failure rule because the specific failed program and reason are lost from the JSON response.

3. Original verifier-state seeding uses `BPF_PROG_REJIT(log_level=2)`, not `BPF_PROG_LOAD(log_level=2)`.

   Per-pass verify correctly calls `bpf_prog_load_verify()` (`commands.rs:621-626`, `bpf.rs:1558-1592`). However, initial verifier-state capture for the original program uses `bpf_prog_rejit_capture_verifier_log()` and explicitly labels the source as `BPF_PROG_REJIT(log_level=2)` (`commands.rs:458-467`, `bpf.rs:1709-1720`). If the design is read strictly, verifier-in-the-loop should be seeded by `BPF_PROG_LOAD(log_level=2)`.

4. Final REJIT failure has no pass-attribution retry after per-pass verification.

   The design's main safety mechanism is per-pass dry-run plus rollback, and that is implemented in `bpfopt-core`. If the final `BPF_PROG_REJIT` still fails, the daemon returns an error with a verifier log and leaves the kernel program unchanged (`commands.rs:854-914`). It does not attempt a second pass-attribution/disable loop at final apply time. This is probably acceptable under the current per-pass-verify design, but it is less than the older "auto-rollback / gradual rollout" wording if that is intended to include final-apply retries.

5. `endian_fusion` call-offset resolution is per-pass while the pass emits per-size targets.

   The pass checks availability per size (`endian.rs:267-310`) and emits the correct per-size BTF ID (`endian.rs:340-350`), but it resolves one call offset for the pass as a whole (`endian.rs:326`). Since `target_name_for_pass("endian_fusion")` resolves only `bpf_endian_load32` (`pass.rs:703-711`), 16-bit and 64-bit endian sites can use 32-bit target transport metadata in static/offline mode or when fd slots differ.

6. Several passes implement broad design names with narrower matchers.

   This is mostly coverage, not correctness:

   - `rotate` skips any program with BPF-to-BPF pseudo-calls (`rotate.rs:52-66`).
   - `cond_select` handles packed ABI register true/false operands, not all branch-over-mov shapes (`cond_select.rs:220-225`).
   - `extract` handles only a specific two-instruction `RSH64_IMM` + low-mask `AND64_IMM` shape (`extract.rs:12-27`).
   - `wide_mem` skips likely packet pointer sites in XDP/TC (`wide_mem.rs:470-502`).
   - `skb_load_bytes_spec` only handles short, constant, stack-destination `skb_load_bytes` calls (`skb_load_bytes.rs:160-179`).

## Extra / Design-Unmentioned Code

1. `skb_load_bytes_spec` is implemented and default-enabled even though the design still lists helper specialization as research complete.

2. Daemon JSON API includes `profile-start`, `profile-stop`, `profile-save`, `profile-load`, and `status` in addition to `optimize` and `optimize-all` (`server.rs:660-787`). These profiling commands may be useful for `branch_flip`, but they are not part of the minimized daemon API described in the core design.

3. Requests can override `enabled_passes`, `disabled_passes`, and `dry_run` (`server.rs:374-405`). That is useful for experiments, but the design only describes the daemon optimize/apply path and benchmark default pass set. It also creates a policy surface where pass exclusion is possible, even if benchmark config currently avoids per-prog_type exclusions.

4. `bpfopt` CLI has offline optimizer/developer commands and accepts target/profile/map snapshot inputs (`bpfopt/crates/bpfopt/src/main.rs:266-378`). The #646 design allows a `bpfopt` CLI, but this is outside the daemon serve runtime and must remain clearly developer/offline-only to avoid conflicting with the app-level loader rule.

5. Result records include extra diagnostic fields beyond the required per-pass schema: nested `verify`, `rollback`, `sites_skipped`, `skip_reasons`, `skipped_sites`, `insns_before`, `insns_after`, and `diagnostics` (`commands.rs:115-134`). These are useful for debugging, but the design only requires the smaller structured record and warns against informational-only payload fields in benchmark results.

## Non-Gaps Observed

- Active benchmark config does not contain per-prog_type pass exclusions; its default list simply omits `branch_flip` (`benchmark_config.yaml:1-27`).
- No default security pass appears in the active pass registry.
- Daemon uses raw `bpf(2)` wrappers in `daemon/src/bpf.rs`; no libbpf runtime dependency is visible in `daemon/Cargo.toml`.
- Per-pass verify and rollback are functionally present: changed passes are verified with `BPF_PROG_LOAD`, accepted verifier states update the program, and rejected passes restore the pre-pass snapshot (`commands.rs:621-626`, `pass.rs:1213-1236`).
- Final apply is one `BPF_PROG_REJIT` call after the pass pipeline (`commands.rs:771-786`).
- Dynamic map invalidation has real daemon wiring through `MapInvalidationTracker` and the `serve` tick.

## Highest-Priority Fixes

1. Decide the bpfopt-core boundary and enforce it.

   If `bpfopt-core` is meant to be pure, move per-pass verify/rollback and REJIT fd-array state back behind daemon-owned adapters. If the core is intentionally daemon-aware, update the design because it currently says the opposite.

2. Fix Docker/Makefile inputs for the daemon's `bpfopt-core` dependency.

   The image build must copy `bpfopt/` before building daemon, and daemon build inputs must include bpfopt-core source files so Python/config changes still layer correctly while Rust pass changes trigger daemon rebuilds.

3. Add or explicitly de-scope the 128-bit LDP/STP pass.

   The design currently says the module exists and describes a pass-level transform, but no active pass implements it.

4. Align design and implementation for helper specialization.

   Either promote `skb_load_bytes_spec` in the design and document its current limits, or remove it from default pass lists until it is no longer research-status.

5. Make result schemas and `optimize-all` errors match zero-silent-failure expectations.

   Rename/add `pass` in per-pass records, and include per-program error details when `optimize-all` reports nonzero errors.

6. Extend const_prop if the paper/design depends on verifier ranges.

   Exact constants are implemented; range/tnum-driven folding is not.
