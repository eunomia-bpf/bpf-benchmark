# Phase 2 HIGH Fix Review

Date: 2026-04-28
Commit reviewed: `44efcdb4` (`44efcdb4^..44efcdb4`)
Scope: `bpfverify --report`, `bpfprof` PMU/profile schema, and changed tests.

## Findings

### CRITICAL: `bpfprof` still aborts when PMU is unavailable instead of emitting nullable branch fields

Location: `bpfopt/crates/bpfprof/src/main.rs:113-117`, `bpfopt/crates/bpfprof/src/main.rs:202-224`

`ProfileJson` now models `branch_miss_rate`, `branch_misses`, and `branch_instructions` as nullable fields, and `build_profiles()` correctly emits `None` for each per-program branch field because the current PMU sample is window-level rather than program-attributed. However, `run()` still opens and drives `BranchCounters` before it builds profiles:

- `BranchCounters::open().context("open PMU branch counters")?`
- `pmu.reset_and_enable()?`
- `pmu.disable()?`
- `pmu.read_counts()?`

Any `perf_event_open`, ioctl, or read failure still makes `bpfprof` exit non-zero before it writes profile JSON. That violates the Phase 2 fix requirement that when PMU is unavailable or not per-program, the per-program branch fields surface as JSON `null`. It also keeps `bpfprof` unusable for otherwise valid `run_cnt_delta` / `run_time_ns_delta` profiling on hosts without PMU access, `perf_event_paranoid` permission, or virtualized PMU support.

The current tests do not catch this because `bpfopt/crates/bpfprof/tests/cli.rs:24-31` treats `perf_event_open` failure as a skip, while the new nullable checks exercise only `build_profiles()` and serde serialization.

Fix suggestion: make PMU collection optional in the CLI path, or remove it from the current path until real per-program attribution exists. `BPF_ENABLE_STATS` and program info failures can remain fatal, but PMU open/reset/enable/read failures should still produce profiles with `branch_miss_rate: null`, `branch_misses: null`, and `branch_instructions: null`. Add a targeted test using an injectable PMU source or a small helper seam so a PMU-open failure is verified to still write nullable profile JSON.

### HIGH: profile schema/documentation still says branch PMU fields are numeric program-level data

Location: `docs/tmp/bpfopt_design_v3.md:153-161`, `docs/tmp/bpfopt_design_v3.md:313-335`; changed-file absence in `git diff 44efcdb4^..44efcdb4`

The implementation changed the emitted profile schema to nullable branch metrics, but the authoritative v3 text still documents `perf_event_open -> branch_misses, branch_instructions`, shows numeric `branch_miss_rate`, `branch_misses`, and `branch_instructions`, and explicitly says `branch_miss_rate` is program-level PMU data. The commit also does not add a README or dated known-limitation note explaining that current `bpfprof` cannot attribute branch PMU counters per program and therefore emits `null`.

This leaves implementers and Phase 3 consumers with conflicting contracts: code emits nullable fields, while the design document still describes required numeric program-level PMU data.

Fix suggestion: update the user-facing docs/known-limitation material in the follow-up fix. If `docs/tmp/bpfopt_design_v3.md` is intentionally held unchanged for this review task, queue a separate design-doc alignment before Phase 3 depends on `profile.json`; otherwise keep the implementation and v3 §2.3/§3.4 schema synchronized.

## Checks

### H1: `bpfverify --report`

Status: passed.

`VerifyReport` now includes `verifier_states: VerifierStatesJson`, and report construction fills it from the same converted verifier-log states used by `--verifier-states-out` (`bpfopt/crates/bpfverify/src/main.rs:54-59`, `151-157`). The report JSON therefore has nested `verifier_states.insns`, matching the v3 §2.2 requirement to include parsed states and the v3 §3.5 DTO shape.

`effective_log_level()` forces `2` for both `--report` and `--verifier-states-out` (`bpfopt/crates/bpfverify/src/main.rs:138`, `192-198`). The integration test now asserts `json["log_level"] == 2` and that `json["verifier_states"]["insns"]` is an array (`bpfopt/crates/bpfverify/tests/cli.rs:106-107`).

### H2: `bpfprof` PMU nullable fields

Status: partial; blocked by the PMU-unavailable failure above.

The DTO types are now `Option<f64>` / `Option<u64>` (`bpfopt/crates/bpfprof/src/main.rs:61-70`), and `build_profiles()` no longer attributes shared window-level PMU counts to each program (`bpfopt/crates/bpfprof/src/main.rs:214-224`). No global window-level metadata field was added, so the commit appears to choose the nullable per-program scheme rather than scheme B.

Downstream compatibility is acceptable: `bpfopt` reads `branch_miss_rate` as `Option<f64>` with `#[serde(default)]` and ignores the raw branch count fields (`bpfopt/crates/bpfopt/src/main.rs:270-276`, `870-877`). `branch_flip` already treats `None` as unavailable PMU data and skips conservatively (`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:91-96`). No `bpfopt branch-flip` code fix is needed for JSON `null`.

### H3: `--log-level`

Status: passed.

The default is now `0` (`bpfopt/crates/bpfverify/src/main.rs:37-39`), and output modes force `2` through `effective_log_level()` (`bpfopt/crates/bpfverify/src/main.rs:192-198`). The unit test covers default `0`, `--report` forcing `2`, and `--verifier-states-out` forcing `2` even when the user passes `--log-level 0` (`bpfopt/crates/bpfverify/src/main.rs:630-649`).

### Tests

Status: passed.

- `cargo build` in `bpfopt/`: passed.
- `cargo test` in `bpfopt/`: passed, 450 tests.
- The 448 -> 450 increase is reasonable: one new `bpfverify` unit test for log-level behavior and one new `bpfprof` unit test for not attributing shared PMU counts.
- The changed tests have bug-detection purpose. They do not add size-only ABI tests or self-equality tautologies.

## Conclusion

Not ready for `#41` / Phase 3 yet.

H1 and H3 are fixed. H2 is only partially fixed: nullable branch fields are represented correctly once profiles are built, and downstream `branch_flip` can handle `null`, but `bpfprof` still fails before producing JSON when PMU is unavailable. The schema/documentation mismatch around nullable PMU fields also needs to be resolved before Phase 3 relies on `profile.json`.
