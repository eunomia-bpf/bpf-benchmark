# Round 4 Investigate Further 2026-04-22

Status:
- Investigate B: completed, deleted duplicate production response struct
- Investigate A: researched only, deferred to Round 5 due live file conflicts

Scope:
- code changes only in `daemon/src/commands.rs` and `daemon/src/server.rs`
- no VM runs

## Investigate B: `OptimizeOneResult` vs `ServeOptimizeResponse`

### Field comparison

| Field | `OptimizeOneResult` | `ServeOptimizeResponse` | Difference |
| --- | --- | --- | --- |
| `status` | `String` | `String` | same |
| `prog_id` | `u32` | `u32` | same |
| `changed` | `bool` | `bool` | same |
| `passes_applied` | `Vec<String>` | `Vec<String>` | same |
| `program` | `ProgramInfo` | `ProgramInfo` | same |
| `summary` | `OptimizeSummary` | `OptimizeSummary` | same |
| `passes` | `Vec<PassDetail>` | `Vec<PassDetail>` | same |
| `attempts` | `Vec<AttemptRecord>` | `Vec<AttemptRecord>` | same type; `ServeOptimizeResponse` alone added `skip_serializing_if = "Vec::is_empty"` |
| `timings_ns` | `TimingsNs` | `TimingsNs` | same |
| `inlined_map_entries` | `Vec<InlinedMapEntry>` | `Vec<InlinedMapEntry>` | same |
| `error_message` | `Option<String>` | `Option<String>` | same |

Conclusion from the struct diff:
- there were no unique business fields on either side
- the only production delta lived in serialization behavior for `attempts`

### Converter behavior

Source:
- `daemon/src/commands.rs` before cleanup had `impl From<OptimizeOneResult> for ServeOptimizeResponse`

Behavior:
- copied every top-level field 1:1
- rebuilt every `AttemptRecord` as `AttemptRecord { debug: None, ..attempt }`
- therefore the only mutation was dropping `attempts[*].debug`

No other business logic existed in the converter.

### Active serialization path

Production socket path:
- `daemon/src/server.rs:481-493` is the active `"optimize"` serialization site
- before cleanup it serialized `ServeOptimizeResponse::from(result)`
- internal non-socket call sites already used `OptimizeOneResult` directly:
  - invalidation reoptimize path: `daemon/src/server.rs:233-247`
  - `optimize-all` accounting path: `daemon/src/server.rs:625-636`

Runner expectation:
- `runner/libs/rejit.py:583-624` validates and stores `status`, `summary`, `changed`, `program`, `inlined_map_entries`, and `error_message`
- `runner/libs/rejit.py:460-475` validates `passes[*].pass_name`
- no live runner/corpus/e2e source reader consumes `attempts` or `attempts[*].debug`

### Decision

Keep `OptimizeOneResult`, delete the production `ServeOptimizeResponse` struct and the explicit converter.

Reason:
- `OptimizeOneResult` is the canonical internal result type returned by `try_apply_one(...)`
- `ServeOptimizeResponse` existed only as a one-hop socket wrapper
- the wrapper had no schema value beyond omitting attempt debug payloads
- that omission is now expressed directly on `OptimizeOneResult` JSON serialization, so the wire contract stays compact without carrying a second struct

Implementation chosen:
- `daemon/src/commands.rs:24-77`
  - deleted the production `ServeOptimizeResponse` struct
  - deleted `impl From<OptimizeOneResult> for ServeOptimizeResponse`
  - moved the serve-only `attempts[*].debug` omission into `OptimizeOneResult` serialization via `serialize_attempts_without_debug(...)`
  - kept a `#[cfg(test)]` type alias `ServeOptimizeResponse = OptimizeOneResult` so existing in-tree tests still compile without widening the edit scope
- `daemon/src/server.rs:481-498`
  - serialize `OptimizeOneResult` directly with `serde_json::to_value(result)`

### Deleted / changed locations

- `daemon/src/commands.rs:24-77`
  - duplicate response layer removed; single-struct wire serialization now lives here
- `daemon/src/server.rs:481-498`
  - direct serialization of `OptimizeOneResult`

## Investigate A: `target_prog_ids` / `apply_prog_ids`

Research result:
- the duplication still exists and is still a real cleanup candidate
- `runner/libs/case_common.py:104-111` keeps both `target_prog_ids` and `apply_prog_ids`, and `prog_ids()` merges them with `apply_prog_ids or target_prog_ids`
- both builders still seed both fields with the same list:
  - `runner/libs/case_common.py:470-472`
  - `corpus/driver.py:780-782`
- corpus code still splits reads across the two names:
  - `corpus/driver.py:1045-1046` session helper reads `apply_prog_ids`
  - `corpus/driver.py:1138-1140` baseline measurement reads `target_prog_ids`
  - `corpus/driver.py:1249-1250` rejit measurement reads `target_prog_ids`

Why deferred to Round 5:
- the required edit surface is exactly `runner/libs/case_common.py` and `corpus/driver.py`
- your prompt marked those files as concurrently modified by Codex D this round
- doing the merge now would create direct overlap and likely conflict for a cleanup that is not blocking Investigate B

Round 5 outline:
- replace `CaseLifecycleState.target_prog_ids` + `apply_prog_ids` with one canonical `prog_ids: list[int]`
- update `CaseLifecycleState.prog_ids()` callers to read the field directly or collapse the helper away
- update `_default_runner_lifecycle_state(...)` and `_build_runner_state(...)` to initialize only the canonical field
- update `CorpusSession.prog_ids()` to read the canonical field
- switch baseline/rejit measurement call sites from `state.target_prog_ids` to the canonical field
- then delete the fallback merge logic (`apply_prog_ids or target_prog_ids`)

## Validation

- `cargo test --manifest-path daemon/Cargo.toml`
  - PASS
  - `494 passed; 0 failed`
- `make -C daemon release`
  - PASS
- `make check`
  - PASS
- not run:
  - `vm-e2e`
  - `vm-corpus`

## `git diff --shortstat`

Command output:
- `39 files changed, 577 insertions(+), 1156 deletions(-)`

Note:
- this is workspace-wide and includes concurrent in-flight edits from other rounds, not just this investigate-B change set
