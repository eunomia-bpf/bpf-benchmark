# 2026-04-22 Program Discovery Review

## Scope

Required context read before this review:

- `docs/kernel-jit-optimization-plan.md` (`#663` / `#664` / `#665` / `#666`)
- `docs/tmp/no-changed-in-loader-investigation-20260421/summary.md`
- `docs/tmp/wave3-silent-failure-review-20260422/summary.md`

Current authoritative corpus baseline for the undercount discussion:

- `corpus/results/x86_kvm_corpus_20260421_232916_947372/result.json:44930` reports `discovered_programs=48`
- `corpus/results/x86_kvm_corpus_20260421_232916_947372/result.md:28` reports `tetragon/default | ... | Programs=1`
- `corpus/results/x86_kvm_corpus_20260421_232916_947372/result.md:30` reports `tracee/default | ... | Programs=3`

Historical object-centric / old-loader numbers are real but not directly comparable to the current app-centric macro suite:

- `docs/kernel-jit-optimization-plan.md:863`
- `docs/kernel-jit-optimization-plan.md:879`
- `docs/kernel-jit-optimization-plan.md:985`
- `docs/kernel-jit-optimization-plan.md:1014`

## Per-App Findings

| App | Current discovery mechanism | Best current signal for “true” attached set | Current gap / cause | Corpus vs E2E | FD-owned path on production scan/apply? | Recommended direction |
| --- | --- | --- | --- | --- | --- | --- |
| `tracee` | Pure FD-owned `find_bpf_programs(pid)` through `TraceeAgentSession` health check and final collection (`runner/libs/app_runners/tracee.py:313-345`, `runner/libs/agent.py:90-158`) | Historical live run already captured `44` programs for `tracee/default` in old corpus (`corpus/results/vm_corpus.md:30`); current macro corpus only sees `3` (`corpus/results/x86_kvm_corpus_20260421_232916_947372/result.md:30`) | Confirmed undercount. Attach completes, loader closes original FDs, and `find_bpf_programs()` stops seeing those programs | Mostly consistent today. Shared adapter only injects workload (`runner/libs/app_runners/__init__.py:57-63`), and current Tracee config has events but no explicit `target_programs/apply_programs` (`e2e/cases/tracee/config.yaml:1-33`) | Yes. Tracee duplicates loader-owned `prog_fds` in runner startup (`runner/libs/app_runners/tracee.py:332-341`), and `scan_programs()` explicitly requires them when provided (`runner/libs/rejit.py:592-604`). E2E passes them via `scan_kwargs` (`e2e/cases/tracee/case.py:1370-1378`) | Replace discovery truth source with global `bpftool prog show` before/after diff; keep FD ownership only as a hint / FD duplication source for scan/apply |
| `tetragon` | Hybrid: health gate still probes `find_bpf_programs(pid)`, but steady-state program set is global `bpftool prog show` diff against `before_ids` (`runner/libs/app_runners/tetragon.py:21-24`, `:38-67`) | Two authoritative signals exist: current E2E config explicitly scopes comparison/apply to `execve_rate` + `event_execve` (`e2e/cases/tetragon/config_execve_rate.yaml:11-17`), while older live corpus saw `8` Tetragon programs total (`corpus/results/vm_corpus.md:28`) | Current macro corpus fell to `1` because generic corpus selection re-pruned the app back to activity-only `event_execve`, ignoring the explicit E2E target/apply set (`docs/kernel-jit-optimization-plan.md:1041`) | Was inconsistent before this turn: E2E waited/selected by config (`e2e/cases/tetragon/case.py:135-165`, `:680-707`), corpus did not (`runner/libs/app_runners/__init__.py:63-69`, `corpus/config/macro_apps.yaml:86-90`) | No. FD-owned lookup is only used as a startup health hint (`runner/libs/app_runners/tetragon.py:44-45`); steady-state discovery and later apply work do not depend on loader-owned FDs | Use explicit config as the macro-suite truth source for target/apply selection; if we later want the full live Tetragon superset again, add a separate “global live census” mode instead of mixing it with the E2E-configured set |
| `bpftrace` | FD-owned `wait_for_attached_programs()` -> `find_bpf_programs(pid)` (`runner/libs/app_runners/bpftrace.py:151-198`, `runner/libs/app_runners/process_support.py:16-41`) | Real count is script-defined plus observable in authoritative runs. `tcplife=1`, `biosnoop=2`, `runqlat=3`, `tcpretrans=1`, `capable=1`, and `vfsstat` now exposes `4` active programs in E2E (`e2e/cases/bpftrace/scripts/*.bt`, `e2e/results/bpftrace_authoritative_20260331.json:4565-5383`) | No hard macro-suite undercount proven, but there is clear early-return risk from stale static thresholds. `vfsstat` still has `expected_programs=2` in `SCRIPTS`, while authoritative E2E reported `requested=4` / `active_programs=4` (`runner/libs/app_runners/bpftrace.py:62-68`, `e2e/results/bpftrace_authoritative_20260331.json:5383`) | Consistent. Corpus and E2E both reach `BpftraceRunner` through the same shared runner path (`runner/libs/app_runners/__init__.py:35-43`, `corpus/config/macro_apps.yaml:105-140`) | No current evidence of downstream `prog_fds` / scan-FD dependency. For bpftrace this is discovery plumbing, not the apply contract | Refresh static `expected_programs` using current authoritative runs; longer term replace PID-FD polling with global before/after diff filtered by script-expected names/types |
| `bcc` | Same FD-owned `wait_for_attached_programs()` path as bpftrace (`runner/libs/app_runners/bcc.py:436-506`, `runner/libs/app_runners/process_support.py:16-41`) | The checked-in config is already stale for several tools: `vfsstat` config says `5`, `tcpconnect` says `2`, `bindsnoop` says `3`, but authoritative E2E observed `requested=8/4/4` with `active_programs=6/4/4` (`e2e/cases/bcc/config.yaml:64-80`, `e2e/results/bcc_authoritative_20260403.json:16960`, `:19511`, `:21912`) | Likely latent undercount / early-return risk from stale static thresholds. Current corpus already reports fewer programs than the authoritative live tool view for some cases, but part of that is also corpus activity pruning after startup | Consistent. Corpus and E2E both instantiate `BCCRunner` from the same tool config (`runner/libs/app_runners/__init__.py:24-32`, `e2e/cases/bcc/case.py:447-486`) | No current evidence of downstream loader-FD scan/apply contract like Tracee/SCX | Refresh static tool counts from current authoritative runs; if we want attach-count semantics in corpus, stop letting generic activity selection collapse multi-probe tools into a smaller target set |
| `katran` | `ManagedProcessSession` discovers process-owned programs via `find_bpf_programs(pid)`, then `_select_program()` intentionally collapses to the single balancer XDP program (`runner/libs/app_runners/katran.py:424-489`, `:690-712`) | Current runtime truth is intentionally `1` program: `balancer_ingress` (`e2e/cases/katran/balancer_ingress.e2e.policy.yaml:5-8`, `e2e/results/katran_authoritative_20260403.json:1659`) | No undercount bug in the current story. The runner is explicitly single-program by design (`self.programs = [session.program]`) | Discovery is consistent; workload mode is not. Macro suite uses `corpus:test_run`, E2E hardcodes `network` (`corpus/config/macro_apps.yaml:92-96`, `runner/libs/app_runners/__init__.py:77-82`, `e2e/cases/katran/case.py:107-116`) | No. Katran’s apply path is already intentionally one-program | Keep single-program semantics unless the benchmark goal changes. Separate issue: align corpus/E2E workload mode once `e2e/cases/katran/case.py` is free to edit |
| `scx` | Hybrid and healthiest of the group: startup uses owner-FD discovery on `struct_ops`, refresh uses remembered scheduler program names + global `bpftool prog show` to recover the live set (`runner/libs/app_runners/scx.py:82-92`, `:129-185`, `:402-412`) | Real attached set is the scheduler callback set. Authoritative E2E reports `requested=13` and stores all `scheduler_programs`, while one E2E result only had `active_programs=11` because two callbacks were idle for that workload (`e2e/results/scx_authoritative_20260403.json:5257`, `:6091-6603`, `e2e/results/scx_20260422_041359_784456/result.json:195`) | Current corpus `Programs=11` is mainly an activity-selection artifact, not a discovery failure (`corpus/results/x86_kvm_corpus_20260421_232916_947372/result.md:26`) | Consistent for the only current macro-suite entry, `scx/rusty` (`corpus/config/macro_apps.yaml:79-84`); future non-`rusty` schedulers would diverge because E2E case currently defaults to `rusty` | Yes for current implementation. SCX duplicates loader-owned FDs for live scheduler programs (`runner/libs/app_runners/scx.py:100-126`, `:187-200`) and E2E consumes them | Keep the hybrid owner+global model; if we want attach-count semantics in corpus, override corpus selection to keep all scheduler callbacks instead of only active ones |
| `calico` | No shared app runner today | Only object/build-side evidence exists: `expanded_corpus_build.md` reports `existing=8` objects (`corpus/results/expanded_corpus_build.md:20`) | Not an undercount bug yet; there is no current runtime benchmark path to count | N/A. No macro-suite entry and no shared runner (`runner/libs/app_runners/__init__.py:85-92`, `corpus/config/macro_apps.yaml:7-140`) | N/A | Add an app-native runtime runner first; only then can discovery undercount be measured meaningfully |
| `suricata` | No shared app runner today | Only object/build-side evidence exists: `expanded_corpus_build.md` reports `existing=2` objects (`corpus/results/expanded_corpus_build.md:30`) | Not an undercount bug yet; there is no current runtime benchmark path to count | N/A. No macro-suite entry and no shared runner (`runner/libs/app_runners/__init__.py:85-92`, `corpus/config/macro_apps.yaml:7-140`) | N/A | Same as Calico: runtime integration first, discovery audit second |

## Main Conclusions

1. The only confirmed discovery undercount in the current macro-suite path is `tracee`, and it is caused by FD-owned discovery itself.
2. `tetragon` was not fundamentally a low-level discovery bug. The real issue was contract drift: E2E used explicit config-scoped `target_programs/apply_programs`, while corpus did not.
3. `bcc` and `bpftrace` are structurally at risk because they still use PID-FD polling with static `expected_programs` thresholds that are already stale for some tools/scripts.
4. `scx` already demonstrates the most robust pattern in-tree: owner-discovered startup plus global-name-based refresh.
5. `katran` is intentionally single-program today.
6. `calico` and `suricata` are not undercounting in the current shared-runner path because they are not in the current shared-runner path.

## Part B: Changes Completed This Turn

Implemented now:

- `runner/libs/app_runners/__init__.py:66-74`
  - The shared Tetragon adapter now always forwards a Tetragon config path into `TetragonRunner`.
- `runner/libs/app_runners/tetragon.py:224-316`
  - `TetragonRunner` now reads the config YAML directly and derives:
    - `tetragon_extra_args`
    - `target_programs`
    - `apply_programs`
- `runner/libs/app_runners/tetragon.py:393-409`
  - Corpus program selection now preserves the config-declared Tetragon target set instead of shrinking the app back to generic activity-only selection.

Net effect:

- Before this change, macro corpus could reduce `tetragon/default` to only `event_execve`.
- After this change, the shared runner inherits the same explicit Tetragon target/apply scope used by E2E: `execve_rate` + `event_execve`.

Static checks run for the change:

- `python -m py_compile runner/libs/app_runners/__init__.py runner/libs/app_runners/tetragon.py e2e/cases/tetragon/case.py`
- A local constructor sanity check confirmed `get_app_runner('tetragon', app_name='tetragon/default', workload='exec_storm')` now resolves:
  - `config_path = e2e/cases/tetragon/config_execve_rate.yaml`
  - `target_programs = ['execve_rate', 'event_execve']`
  - `apply_programs = ['execve_rate', 'event_execve']`

## Deferred / Blocked By Forbidden Files

These should wait until the Wave 3 / concurrent codex work on the forbidden files is finished:

- `tracee` global before/after diff discovery
  - Blocked by `runner/libs/agent.py` and `runner/libs/app_runners/tracee.py`
- Corpus-side reason taxonomy / `applied` vs `changed` cleanup
  - Blocked by `runner/libs/rejit.py`, `runner/libs/case_common.py`, `corpus/driver.py`, and related Wave 3 work
- `scx` / `katran` E2E-path cleanup
  - Blocked by `e2e/cases/scx/case.py` and `e2e/cases/katran/case.py`

## Recommended Next Fix Order

1. `tracee`: switch discovery truth source to global `bpftool prog show` before/after diff, then optionally annotate programs with surviving loader-owned FD hints.
2. `bcc` / `bpftrace`: refresh stale static `expected_programs` and decide whether corpus should report full attach count or only active subset.
3. `scx`: if attach-count semantics matter, stop pruning idle callbacks from the macro-suite `Programs` count.
4. `katran`: align E2E workload mode with macro-suite only if workload comparability matters more than the current “test_run” corpus choice.
5. `calico` / `suricata`: add app-native runners before doing any undercount audit.
