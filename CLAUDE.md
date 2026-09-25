# BPF Benchmark Framework

## Working Agreement

Inside this project's already-authorized goals, continue and deliver
automatically — don't stop to ask permission. Ask or wait only for a genuine
external/team constraint: the git rules below, publishing to an
external/public channel, spending money (AWS cap below), or credentials.
Nothing else is an approval gate — see "No invented experiment gates" for the
recurring failure mode of adding one anyway. Fail-fast strictness (Code
Quality) governs code correctness and missing capabilities; it is not license
to treat an absent optional check as grounds to block or discard an
otherwise-valid result. Report genuine blockers, keep working on unaffected
parts. Keep rules few and non-interfering: before adding one, delete or merge
an existing one; each rule lives in exactly one place here; skills and other
docs should link here instead of restating a rule.

**Branch and git**: `master` is the only development branch; don't create
task branches, and stop to align with the user if a session starts on
another one. State-mutating git commands (`pull`, `add`, `commit`, `push`)
need the user's explicit, scoped ask; check `git status`/`git diff` first and
never overwrite unrelated uncommitted work (may be another agent's WIP, not
recoverable via `reflog`). History-rewriting/destructive commands
(`commit --amend`, `checkout --`, `reset`, `restore`, `stash`, `branch -D`,
`push -f`, `rebase`, `cherry-pick`, `revert`) stay forbidden even if asked;
fix a wrong change forward in a new commit instead of `git revert`/"Restore
X". Tell Codex "DO NOT modify git state" on a dirty tree.

## Measurement Integrity

Workload throughput is the primary measurement. Don't invent
validity/admission/publication gates — matched no-op controls,
zero-drop/zero-error assertions, idle benchmark CPUs, a minimum `run_cnt`, a
clean checkout/commit/push — to stop the queue, discard a completed run, or
relabel a measured result invalid; contention, PMU noise, missing
supplementary checks, and delayed publication are caveats, not blockers. Use
the least-contended CPU set, keep the raw result, keep going. Changing an app
runner, workload, experiment backend, or common framework to add a new
validity gate needs explicit user authorization; app-specific changes that
implement the requested optimization are fine, changes that only add a proof
obligation are not.

Frozen workloads/launchers: don't modify benchmark workloads, upstream app
source, app runners, `corpus/driver.py`, benchmark Makefiles, or
runtime-image launch wiring without explicit authorization, and never to
amplify a reported speedup. Pass YAML under `runner/config/passes/` is policy,
not a frozen launcher — change it freely. The accepted protocol is the
existing two-start load-time comparison; don't add same-process PMU training,
`apply_app_rejit()`, or a live-swap lifecycle to `corpus/driver.py`.

Never filter, skip, or exclude a BPF program from ReJIT — a failure (e.g.
EINVAL) is recorded and surfaces naturally, never hidden behind
`live_rejit_programs()` overrides, `LifecycleAbort`, per-prog_type
exclusions, or exclusion lists. Apps load their own BPF programs via real
application startup; the framework never loads `.bpf.o` directly or ships a
custom loader binary instead of the upstream one (katran's `xdp_root`
bootstrapping the XDP chain is the one exception).

`result.json` holds only raw counters — per program/phase `run_cnt_delta`,
`run_time_ns_delta`, `id`, `name`, `type`, `bytes_jited`, `bytes_xlated`, plus
stdout/stderr, lifecycle log, and app `status`/`error`; raw app-side workload
metrics (`ops_per_sec`, `latency_ms`, `error_count`, ...) are fine to store,
and neither counts as a summary. Any aggregation, ratio, geomean, win/loss
tally, CI, or rollup is forbidden in framework code — delete on sight
`geometric_mean()`, `bootstrap_geometric_mean_ci()`, `win_counts()`,
`comparison_summary()`, or anything reducing ratios to a scalar. That
analysis (ratio, the `min_runs ≥ 100` filter, geomean, tail-call accounting)
lives in `docs/evaluation.md` §5. Don't add `workload_miss`, `limitations`,
or other informational-only result fields — a failure is an error, not a
metadata note.

`branch_flip` (Paper B profile-guided branch layout) stays out of the
default policy until Paper B results decide it, and must consume real
per-site PMU data (`branch_count`, `branch_misses`, `miss_rate`, `taken`,
`not_taken`) from the external `bpfperf` toolchain — no placeholder fields,
heuristic fallback, or missing-site success; missing PMU data exits 1.

## Code Quality

Fail-fast: no dead code (every fn/struct/field/constant has a real caller);
no fallback (unsupported capability or command failure exits 1 with a clear
message, never downgrades or returns partial results); no silenced errors
(propagate BPF syscall/IO/parse errors — no `.ok()`, `let _ = result`,
`unwrap_or_default`, warn-and-continue).

Unit tests need a clear bug-detection purpose — logic branches, state
changes, calculations, boundaries, error paths, ABI/layout/serialization
contracts (verify offsets/format, not just `size_of`), regressions — and
skip trivial getters/setters, stdlib/upstream behavior, tautologies,
mocks-only or duplicate coverage; name the bug a failing test would catch
before adding it.

Don't rewrite long-lived design notes, experiment logs, or status docs
wholesale without an explicit ask; prefer minimal additive edits that keep
existing data and rationale, and when simplifying stale prose, diff against
current state first and collapse only duplicated/obsolete narrative.

## Shim & Bytecode Architecture

Active architecture: stock-kernel userspace path in `bpfopt/shim/` (full
design in `docs/rejit-speculative-optimization-ebpf_idea.md`); historical
daemon/ReJIT designs under `docs/tmp/` are not authoritative — no
`bpfrejit-daemon`, `BPF_PROG_REJIT`, `BPF_PROG_GET_ORIGINAL`, or
project-fork syscall dependency. `libbpfrejit_shim.so` is injected into the
app process and intercepts its BPF syscalls, capturing the original
`BPF_PROG_LOAD` context, maps, attachment state, and bytecode; the runner
owns policy, building an ordered plan from
`runner/config/passes/<pass>/default.yaml` and delivering it via
`BPFREJIT_SHIM_LOADTIME_PLAN` or a shim-socket `execute_plan` request.

`bpfopt` is a pure bytecode CLI — no BPF syscalls, must never call
`libc::syscall(SYS_bpf, ...)` — one named pass per invocation over raw
`struct bpf_insn[]`, side inputs/reports as explicit files, no compile-time
dependency to/from the shim (the shim executes the `bpfopt` binary). Removed
binaries (`bpfget`, `bpfverify`, `bpfrejit`, `bpfprof`, `kernel-sys`,
`bpfrejit-daemon`) stay removed. The shim submits candidate bytecode through
the stock `BPF_PROG_LOAD` verifier/JIT path, then installs at load time or
reloads/reattaches via `shim_reload.h` (`BPF_LINK_UPDATE`, link recreation,
`BPF_PROG_ATTACH`, tracepoint reopen, perf-event replacement, program-array
updates); partial replacement is an explicit error, not success.

The evaluated corpus comparison is two-start load-time: stop the baseline
app, restart it with `BPFREJIT_SHIM_LOADTIME_PLAN`. The shim also implements
running-process `execute_plan`/reload-reattach — don't call a result
"live-swap" unless its recorded lifecycle used that path. Use
`libbpf-rs`/`libbpf-sys`, not hand-written wrappers, for BPF syscalls,
`struct bpf_insn`, opcode constants, and program-type enums, and preserve the
intercepted loader ABI exactly.

## Running Benchmarks

Every run goes through `make <target>` — never call
`python -m runner.libs.run_target_suite`, `cargo run`, `docker run`, or a
component binary directly. `make corpus`/`make test` and their AWS
equivalents must work with zero manual env vars beyond `PLATFORM`/`ARCH`
(defaults in `runner/targets/*.env`). Makefile edits stay minimal and local:
no target-structure refactors, alias targets, or convenience conditionals;
no `mkdir` (use `install -d`); arch-specific build outputs live under the
owning component's build dir (e.g. `bpfopt/shim/build-x86`), not `.cache`.

Targets (platform/arch are env vars, not part of the name): `selftest`,
`negative-test`, `test`, `micro`, `corpus`, `all`, `terminate`; `PLATFORM=kvm`
(default, x86 only) or `PLATFORM=aws`; `ARCH=x86` (default) or `ARCH=arm64`
(AWS only) — e.g. `make corpus`, `PLATFORM=aws ARCH=arm64 make test`. Common
knobs: `SAMPLES` (default 3), `WORKLOAD_DURATION` (seconds/sample, default
30), `TIMEOUT` (default 7200), `BPFREJIT_CORPUS_APPS` (app subset),
`BPFREJIT_BENCH_PASSES` (pass-list override), `KEEP_WORKDIRS=1` (retain
failure artifacts under `details/failure-artifacts/`), `BENCH`/`WARMUPS`/
`INNER_REPEAT` (micro-only), `FUZZ_ROUNDS` (test), `AWS_<ARM64|X86>_*` (AWS
deploy params) — compose on one invocation for isolated per-pass/per-app
runs; never bypass the Makefile. Current pass list is in
`corpus/config/benchmark_config.yaml`: kop-class (kfunc lowering), bytecode
rewriting (pure BPF→BPF), and profile-guided (`branch_flip`, not default).

**AWS cost cap**: bench suites use `t3.small`/`t4g.small`, the kernel test
suite uses `t3.micro`/`t4g.micro`; `medium` is the absolute upper cap, only
as documented OOM mitigation, never for variance/parallelism/SAMPLES=3 —
shrink the workload instead of upgrading the instance. `c5`/`c6g`, `xlarge`,
`2xlarge`, and larger are forbidden as defaults; spot instances are fine for
non-time-critical runs.

**Container**: no host bind mount of the workspace — everything ships via
image layers; only bind-mount system paths (`/sys`, `/sys/fs/bpf`,
`/lib/modules`, `/boot`) and result output dirs. Docker layers are ordered
stable-to-frequent (base OS/apt → pre-built app artifacts → kernel/kop
modules → C++ runner/micro .bpf.o/test artifacts → C shim/bpfopt CLI →
Python/configs/corpus data) so changing Python never triggers recompilation
(`RUNNER_RUNTIME_IMAGE_SOURCE_FILES` in `build.mk` lists only files that
participate in compilation).

## Supported Apps (6)
tracee, tetragon, bcc, katran, cilium, otelcol-ebpf-profiler

## Removed Apps
- **scx**: struct_ops ReJIT crashes the scheduler
- **suricata**: upstream eBPF assets incompatible with libbpf v1.0+
- **systemd**: Ubuntu default packages compiled without BPF framework
- **loxilb**: no arm64 support
- **calico**: BPF dataplane requires K8s pod model; bare-metal single-veth setup architecturally incompatible (Felix removes host IP from WEP iface)
