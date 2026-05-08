# Per-pass YAML config adversarial review
Date: 2026-05-08. Scope: review only; no code fix, no commit, no benchmark.
Current tree note: `runner/libs/rejit_plan.py` is 128 lines in the checked tree,
not the 261-line schema-validating version described in the prompt.
## Top findings
1. **Wrong / P0:** `katran.yaml` likely fails at runtime. `--inline-hint` is a
   global bpfopt arg (`bpfopt/crates/bpfopt/src/main.rs:117-123`), but the YAML
   puts it after `--` (`runner/config/passes/map_inline/katran.yaml:15-21`).
   Then `MapInlineCliArgs` sees it and rejects it; that parser accepts only
   `--map-values`/`--map-ids` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:81-107`).
   Fix: move every `--inline-hint=...` before `--`, next to `--prog-id`.
2. **Wrong / policy conflict:** this is a runner-Python refactor during v3
   migration. `CLAUDE.md:96-101` and
   `docs/kernel-jit-optimization-plan.md:402-413` say `runner/libs/`, `corpus/`,
   and `micro/` stay stable except bug fixes/stale data. Actual edits touch
   `runner/libs/rejit_plan.py`, `runner/libs/rejit.py`, `runner/libs/case_common.py`,
   and `corpus/driver.py`. Fix: do not merge this as v3 migration work; make it
   an explicit experiment or move app/prog hint selection out of stable runner code.
3. **Wrong / shared lifecycle bug:** `runner/libs/case_common.py:257-258` assumes
   `sess.app.name`, but `run_case_lifecycle()` passes `CaseLifecycleState`
   objects (`runner/libs/case_common.py:299-306`) and that dataclass has no
   `app` field (`runner/libs/case_common.py:128-133`). Fix: use `getattr(sess,
   "app", None)` and fall back to pass defaults.
4. **Risk / dead surface:** `capture_workdir` is declared in YAML, e.g.
   `runner/config/passes/noop/default.yaml:4-7`, but `StepConfig` contains only
   `command/log_level/kinsns` (`runner/libs/rejit_plan.py:29-33`) and daemon
   tars only failed workdirs (`daemon/src/commands.rs:408-420`). Fix: delete it
   or plumb it through the protocol.
## A. Design correctness
### A1. log_level direction
Verdict: **correct for immediate successor semantics.** YAML documents
`log_level` as the input requirement (`runner/libs/rejit_plan.py:14-16`), and
runner sets step N's outgoing level from step N+1 (`runner/libs/rejit_plan.py:114-119`).
Daemon gives each command the previous `verifier_states_path`
(`daemon/src/commands.rs:513-524`) and updates it after ReJIT
(`daemon/src/commands.rs:716-717`). Therefore `noop -> const_prop` should make
`noop` ReJIT at L2 because `const_prop` declares L2
(`runner/config/passes/const_prop/default.yaml:4-7`). Fix: rename the field to
`input_log_level` or `needs_predecessor_log_level`.
### A2. const_prop step before dce/map_inline
Verdict: **correct today, but non-obvious.** `const_prop` should use `dce`'s
input requirement, not later `map_inline`'s, because `map_inline` must consume
states for the bytecode it receives after `dce`. bpfopt writes bytecode on
success (`bpfopt/crates/bpfopt/src/main.rs:280-289`), and daemon ReJITs
non-empty output before advancing verifier state (`daemon/src/commands.rs:621-649`,
`daemon/src/commands.rs:716-717`). Expected chain
`noop,const_prop,dce,map_inline`: `2,1,2,1`. Fix: add a payload-builder
regression test for exactly this chain.
### A3. Adjacent-only lookahead
Verdict: **safe for current bpfopt passes, risky for future non-bytecode steps.**
Current bpfopt always writes output (`bpfopt/crates/bpfopt/src/main.rs:289`),
so `dce` can become the L2 producer for a later `map_inline`. But daemon
explicitly allows successful no-output steps that leave input/states unchanged
(`daemon/src/commands.rs:640-649`). Fix: either restrict plans to
bytecode-producing steps or model `produces_bytecode` before adding bpfprof-like
steps between transforms.
### A4. Three-level lookup with no merge
Verdict: **risk point.** No merge is deterministic, but it duplicates the full
`map_inline` command in both `programs.balancer_ingres` and `programs.default`
(`runner/config/passes/map_inline/katran.yaml:7-30`). Worse, the documented
fallback to pass default is not implemented when app YAML exists but lacks
`programs.default`: `find_step_config()` raises `KeyError`
(`runner/libs/rejit_plan.py:63-66`) instead of reaching default
(`runner/libs/rejit_plan.py:73-77`). Fix: use small overrides such as
`append_args`/`inline_hints`, or explicitly require `programs.default` with a
friendly runtime error.
### A5. `${PASS_LOCAL_ARGS}`
Verdict: **dead / misleading.** Daemon declares it (`daemon/src/commands.rs:81`)
and always substitutes an empty string (`daemon/src/commands.rs:768-783`); no
runner code populates it. This hides that `branch_flip` needs pass-local
`--profile` (`bpfopt/crates/bpfopt/src/passes/branch_flip.rs:97-114`) while
`runner/config/passes/branch_flip/default.yaml:4-7` cannot supply one. Fix:
delete the placeholder, or make pass-local args a real validated config field.
## B. CLAUDE.md conflicts
### B1. v3 option B runner boundary
Verdict: **conflict.** The rules say runner Python remains the stable boundary
(`CLAUDE.md:96-101`; `docs/kernel-jit-optimization-plan.md:407-413`). This
change rewrites planning (`runner/libs/rejit_plan.py:1-128`), extends the daemon
apply API (`runner/libs/rejit.py:338-369`), and threads app/prog names through
corpus/shared lifecycle (`corpus/driver.py:637-654`,
`runner/libs/case_common.py:257-270`). Route A's report explicitly says it
changed no runner Python (`docs/tmp/route_a_inline_hint_round1.md:5-10`). Fix:
push back unless this is explicitly scoped outside v3 migration.
### B2. No CLI cross-dependencies
Verdict: **good direction with drift cost.** Removing runtime `bpfopt list-passes`
from runner reduces runner->bpfopt coupling (`runner/libs/rejit.py:364-369`);
daemon invoking bpfopt as a CLI remains allowed (`CLAUDE.md:103-108`;
`docs/kernel-jit-optimization-plan.md:421-423`). Risk: pass metadata now exists
both in Rust registry (`bpfopt/crates/bpfopt/src/passes/mod.rs:129-144`) and
YAML. Fix: wire `analysis/validate_pass_configs.py` into a non-benchmark make
check before image/corpus runs.
### B3. kernel-sys syscall boundary
Verdict: **correct.** YAML only passes file paths/scalars to bpfopt. Daemon still
does ReJIT through `kernel_sys::prog_rejit()` (`daemon/src/commands.rs:692-699`),
and `kernel-sys` owns the fork syscall wrapper
(`bpfopt/crates/kernel-sys/src/lib.rs:1330-1373`). This matches
`CLAUDE.md:118-123` and `docs/kernel-jit-optimization-plan.md:431-437`. Fix:
none, but reject future bpfopt live-BPF/syscall expansion.
### B4. Missing katran program override
Verdict: **fail-fast but poor.** If app YAML exists and neither the concrete
program nor `default` exists, runtime raises a raw `KeyError` at
`runner/libs/rejit_plan.py:63-66`. That surfaces the defect, but not with the
friendly error expected by `CLAUDE.md:70-74`, and it contradicts the documented
pass-default fallback (`runner/libs/rejit_plan.py:9-12`). Fix: explicit
`RuntimeError(pass, app, prog)` or real pass-default fallthrough.
## C. Edge cases
### C1. YAML-special BPF program names
Verdict: **mostly safe.** Kernel BPF names are max 16 bytes including NUL
(`vendor/linux-framework/include/uapi/linux/bpf.h:1513`) and allow only
alnum/underscore/dot (`vendor/linux-framework/kernel/bpf/syscall.c:1221-1225`),
so spaces, colons, and hyphens are impossible. Real gotcha: truncation. Route A
notes app JSON says `balancer_ingress` but metadata name is `balancer_ingres`
(`docs/tmp/route_a_inline_hint_round1.md:68-70`). Fix: document that YAML keys
use kernel `prog_info.name`.
### C2. Same prog name across apps / app_name extraction
Verdict: **works now, brittle later.** Current macro apps have unique first path
segments (`corpus/config/macro_apps.yaml:5-11`), so `katran.yaml` is isolated.
But `split("/")[0]` collapses future `bcc/set` and `bcc/opensnoop`
(`corpus/driver.py:637-641`, `runner/libs/case_common.py:257-258`). Fix: use
a safe full-name mapping such as `bcc__set.yaml`, or pass both app family and
full suite app name.
### C3. SAMPLES=3 behavior
Verdict: **correct.** `samples` only loops workloads
(`corpus/driver.py:187-192`). ReJIT is applied once per app between baseline
and post-ReJIT (`corpus/driver.py:618-654`), and `rejit_result` is stored once
per app result (`corpus/driver.py:419-428`). Fix: no change.
### C4. Different steps per program
Verdict: **supported.** Runner builds per-PID steps
(`runner/libs/rejit_plan.py:110-122`), server parses steps per program
(`daemon/src/server.rs:127-142`), and daemon dispatches by `prog_id`
(`daemon/src/commands.rs:373-382`). Fix: no protocol change; add a focused
unit test only if you want regression coverage for per-prog overrides.
### C5. Validator when bpfopt is missing
Verdict: **mixed.** Auto-discovery missing bpfopt is graceful and returns 2
(`analysis/validate_pass_configs.py:172-181`). Explicit bad `--bpfopt`, nonzero
`list-passes`, or invalid JSON are not graceful because `subprocess.run(check=True)`
and `json.loads()` are uncaught (`analysis/validate_pass_configs.py:38-46`,
`analysis/validate_pass_configs.py:183`). Fix: catch `OSError`,
`CalledProcessError`, and `JSONDecodeError`.
## D. Simplification check
### D1. Is this simpler?
Verdict: **no.** Current surface is 128 lines of loader
(`runner/libs/rejit_plan.py:1-128`), 223 lines of validator
(`analysis/validate_pass_configs.py:1-223`), plus the YAML tree
(`runner/config/passes/map_inline/katran.yaml:1-30` as the first override).
It removes runtime introspection, but adds duplicated pass metadata, offline
validation, app/prog naming rules, and command copy-paste. Fix: call it
configurability, not simplification.
### D2. Overdesign for paper needs
Verdict: **risk point.** The only concrete use case is katran `map_inline`.
Route A host-validated two ctl_array hints
(`docs/tmp/route_a_inline_hint_round1.md:94-102`), while YAML now carries four
(`runner/config/passes/map_inline/katran.yaml:18-21`). The full 15-pass config
directory is hard to justify before a second independent app override exists.
Fix: start with a narrow `map_inline_hints.yaml` or one `benchmark_config.yaml`
override; generalize later.
## E. Runtime risk before next corpus
### E1. Inline-hint placement
Verdict: **most dangerous.** `katran.yaml` sends hints after `--`
(`runner/config/passes/map_inline/katran.yaml:15-21`), but bpfopt global hints
must be parsed before `--` (`bpfopt/crates/bpfopt/src/main.rs:117-123`).
Mitigation: move hints before `--`; then run a non-benchmark command-construction
unit test.
### E2. Shared lifecycle AttributeError
Verdict: **high risk for test/micro/shared callers.** `case_common.py` assumes
`sess.app` (`runner/libs/case_common.py:257-258`) even though generic lifecycle
passes `CaseLifecycleState` (`runner/libs/case_common.py:299-306`). Mitigation:
use `getattr` and pass no app/prog override for generic callers.
### E3. Validator misses real command failures
Verdict: **high drift risk.** App override validation only checks `--pass`
string containment (`analysis/validate_pass_configs.py:137-160`). It misses
global-vs-pass-local placement, app override side-input parity, and
`branch_flip --profile`. Mitigation: reduce command freedom or add a parser-only
bpfopt validation mode for every YAML command shape.
### E4. KEEP_WORKDIRS=all / capture behavior
Verdict: **regression risk.** Makefile documents `KEEP_WORKDIRS=all` as
success-side tar capture (`Makefile:68-72`), but daemon only tars failures
(`daemon/src/commands.rs:408-420`) and no daemon code reads
`BPFREJIT_KEEP_ALL_WORKDIRS` (`runner/suites/_common.py:198-207` only forwards it).
Mitigation: restore real daemon support or delete the documented `all` behavior.
## Bottom line
Push back. The log-level chain is mostly sound and removing runtime
`list-passes` is directionally reasonable, but the current implementation is
not simpler, conflicts with the v3 runner boundary, contains a concrete katran
command bug, and adds dead/drift-prone config surface.
