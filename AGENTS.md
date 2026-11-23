# BPF Benchmark Framework

## HIGHEST PRIORITY: one kernel, one worktree, one image, one base; raw data kept; benchmark settings fixed

This section overrides every other rule in this file, in lane prompts and in duty prompts.

Operator, 2026-11-11: "确保需要的功能 merge 到一起之后, 删掉所有别的内核版本. 任何时候只允许一个镜像和一个底座. 所有原始数据不允许删掉, 不允许建立任何新的 worktree. 明确记录." "一个 workspace 里面只能一个我顺便问一句, 内核版本只有一个吧? 也只有一个 worktree? ... 这个规则要记录在好几个地方, 最高优先级" "我们要确保在当前系统也达到这样的性能. benchmark 设置也不能改, 除非得到我同意" "得确保当前对象也是 05-29 系统的性能数据, 当前对象为啥会差? 是不是有回归? 代码为啥不是直接和 05-29 一致?"

- One worktree in this Workspace: /workspaces/repository on master, with the kernel submodule vendor/linux-framework checked out inside it. No other worktree, clone, export, copied tree or branch checkout of this repository or of a kernel exists here, and none is created.
- One kernel version: the vendor/linux-framework submodule at the commit master records. Functions a path needs are merged into that line as commits on top of it, made inside the submodule checkout (pushed to eunomia-bpf/linux kprog-no-kinsn, master's pointer updated in the same step). After the merge every other kernel version, kernel tree and kernel build is removed.
- One image (bpf-benchmark/kprog:current) and one base (/workspaces/.agent-state/kprog-ck: the kernel build build-x86, its modules, the loader, shim, native-link and the object sets) serve every lane at any time. A lane that changes the base rebuilds it in place and announces it in COORDINATION.md.
- kinsn keeps one of its own (operator 2026-11-23: "唯一内核、唯一镜像 可以保留一个 kinsn 的也保留一个 kprog 的"): one kinsn kernel build (the kinsn line 24cd6e63ce91 from the submodule history, its source exported once to /workspaces/.agent-state/kinsn-ck/src and built in kinsn-ck/build-x86), its kinsn modules and one kinsn runtime image, used only for the kinsn runs of the frozen benchmark. kprog keeps its one kernel, image and base above; each product still exists as one build per system.
- Raw data is kept: run directories, logs, archives, census and replay outputs stay on persistent storage under /workspaces, committed when they back a number. /var/tmp is cleared when the container restarts, so raw data written there moves to /workspaces. Removal applies to rebuildable build outputs (kernels, images, object builds) only, and every removal is listed in kprog/docs/cleanup-log.md.
- One build output: each product (kernel, image, linker, compiled apps, simulator C, B) exists as one build, and a new build replaces the previous one; no clone of any repository (operator, 2026-11-14: "不新建 worktree, 不能 clone, 不能有多个编译产物").
- Benchmark settings stay at the 2026-05-29 definition (9f3855f6f): the workload, its configuration and the runtime image definition. Any change needs the operator's explicit consent.
- History, 2026-11-11 to 11-12 (operator: "把需要的功能合进唯一内核线：在子模块检出里原地提交，推送后更新 master 指针；链接器和内核是不是应该在 05-29 上改? 内核应该从 stock 开始依次把需要的部分合并进来吧? kinsn RFC 那个也可以清理掉?" "停掉所有的, 然后确保重新开始" "你能自己来的整理可以自己来, omp 辅助 review; 先不用 claude subagent 了. 这些事情搞定, 性能确保回到 05-29 或者更好, 在开始考虑做别的"): the rebuild ran with every lane stopped, the coordinator rebuilding and omp reviewing. It is finished; lanes run again on the operator\'s later words, and the steps below are its record. (1) Kernel: start from the stock base c23719abc330 (bpf-next/master, shared by every kernel line) and add only the commits a path needs, one at a time in the submodule checkout, each built and checked. (2) Linker: start from the 2026-05-29 native-link source (9f3855f6f) and add only the changes a path needs, one at a time, with the six applications' native bytes compared against the 2026-05-29 output after each. (3) One image, one base. (4) One six-application sweep; every application at or above its 2026-05-29 number.
- Breadth first (operator 2026-11-11: "每小时监控提醒不能停" "自己推进, 直到性能这部分全部做完, 优化也搞定为止. 每个应用跑3次之后换下一个应用这样, 广度优先"): the coordinator keeps going until the performance work and the optimization are finished. Timing and optimization rotate across the applications: three runs of one application, then the next application, rather than many rounds on one.
  Refined by the operator on 2026-11-13 ("是不是过于慢了? 应该都弄好再?", spark-manage workspace-rules.md "Batch, then confirm once"): between fixes, time only the apps a fix touches, three samples each; the full six-app round runs once, before the freeze.
- Performance floor: the current system reaches, application by application, at least the 2026-05-29 system: OTel 1.849x, BCC 0.985x, Tracee 0.948x, Katran 1.113x, Tetragon 1.009x, Cilium 1.319x (stats off, reproduced 2026-11-10 on the frozen workload). The 2026-05-29 code is the reference. The 2026-05-29 numbers were measured without an equal-work check (kprog/docs/todo.md section 0); how they enter the paper is the operator's call.

The operator's words are recorded verbatim in kprog/docs/user-instruction.md (operator, 2026-11-14: "确保没有做错, 并且每一个原话都记录下来"). Standing words for every Workspace: "不新建 worktree, 不能 clone, 不能有多个编译产物", "结果一出来就提交, 有更改就提交 git, 但不能改论文", "不许 revert 提交". A rule that is his words keeps its wording; any rule is relaxed only when it blocks the work ("要不还是不要放宽, 除非 blovk 了").

## Freeze (operator 2026-11-16, recorded 2026-11-16T23:42:48Z)

Benchmark framework and settings unchanged (operator 2026-11-20: "整个 benchmark 框架不是说都不允许改动??? 还在动啥??? 明确记住, 记到很多地方"; 2026-11-09: "也要确保 benchmark framework 不能变化"; 2026-11-15: "不许改 bench 除非我同意"). The benchmark framework (runner/, corpus/, micro/, e2e/, and the frozen entry kprog/perf/one-image/Makefile) and its settings stay at the 2026-05-29 definition: no code change (the only difference from 9f3855f6f is the native-sim -> kprog and module/ -> kinsn/module/ path rename) and no setting override on the command line (SAMPLES, WORKLOAD_DURATION, STATS, BENCH_PASSES and the like). Timing runs use the frozen entry with its defaults only (rotate: 3 x 180 s per app, stats off then stats on). make check (1 x 10 s per app) is a functional check; its numbers are diagnostics. Needs of the verified path or the native side (waiting for loads, faster loading) are met in kprog's own code, outside the framework. Restored: runner/libs/rejit.py in 25b802208. (recorded 2026-11-20T08:26:09Z)

Operator: "需要有东西冻结并且明确禁止修改, 除了删除死代码. 是不是? 性能优化为啥没有做?"; "这些是不是应该你去看看回退到一个稳定版本并且禁止修改? 5/29?"; "我觉得内核是不是应该几乎不要修改, 整体 patch 也要少于 500 loc?"

- Frozen at the tree that built image 603cacfb442a (checked 2026-11-16): kprog/ (simulator, specializers, verify path, loader core, modules, perf, test, build, fidelity, stock-path), kinsn/, bpfopt/shim/, runner/, micro/, corpus/ configs, vendor/bpf/ upstream sources, the timing entry kprog/perf/one-image/Makefile, and the kernel vendor/linux-framework (stock c23719abc330 + 423 lines). In these paths a commit may delete dead code and nothing else.
- Open for performance work, the two places of the design (compiler flags when P is produced, and LTO): vendor/bpf/Makefile and vendor/bpf/*compat*.h, kprog/x86/native_lab/native_link/, and the loader headers native_loader_lto.hpp, native_loader_link_plan.hpp, native_loader_link_schema.hpp, native_loader_context_lto.hpp, and the load-time LTO compiler sources kprog/x86/perf_context_lto.cpp and kprog/x86/link_embedded_ir.cpp (added 2026-11-17T00:24:05Z: they are the LTO compiler).
- Open for the design's main configuration (LTO, checked-sim-c), since 2026-11-19 (coordinator, after audit 20261118T21Z: its code sat behind the exception process): kprog/trusted_generation.py, kprog/x86/trusted_specializer.py, kprog/x86/compile_sim_ir.cpp, kprog/x86/micro-prog/.
- Open for records and proofs: kprog/results, kprog/docs, corpus/results, micro/results, kprog/formal.
- A frozen path opens for a defect class through a line in kprog/docs/freeze-open.tsv: the path, an open-until UTC date, the evidence (run path and log line) and who opened it. tools/freeze-check lets that path take additions until the date; the hourly check reviews every line (coordinator 2026-11-18, after commits that skipped the hooks).
- Enforced by tools/freeze-check from .git/hooks/pre-commit and pre-push, and by a deletion-only pre-commit hook in the kernel repository. Hooks are never skipped.
- The 05-29 files stay a reference (kprog/results/compare-0529-20261115). Restoring them would bring back the unequal work (OTel context, Katran LRU) and the compile-time IR rewriting the operator removed on 2026-11-15.

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
another one. Commit and push every step ("做一步 commit push 一步"), committing only your
own paths; check `git status`/`git diff` first and never overwrite unrelated uncommitted work (may be another agent's WIP, not
recoverable via `reflog`). History-rewriting/destructive commands
(`commit --amend`, `checkout --`, `reset`, `restore`, `stash`, `branch -D`,
`push -f`, `rebase`, `cherry-pick`, `revert`) stay forbidden even if asked;
fix a wrong change forward in a new commit instead of `git revert`/"Restore
X".

## Measurement Integrity

Workload throughput and per-invocation BPF time are both reported; the 20%
target counts on per-invocation time, since throughput is bounded by BPF's CPU
share (kprog/docs/todo.md section 0). Don't invent
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

Benchmark workload freeze point: commit 9f3855f6f, 2026-05-29 02:22:18 UTC, the
definition that produced the May reference runs. Operator, 2026-11-09: "是不是 5
月份之后就应该冻结", "明确记录冻结时间, 以后也要想办法防止继续改动". Frozen paths:
`runner/libs/workload.py`, `runner/libs/app_runners/`, `corpus/driver.py`,
`corpus/config/`, `micro/driver.py`, `micro/config/`, `micro/programs/`, `Makefile`,
`micro/Makefile`, `runner/mk/`. Commit and push hooks in the Workspace checkout
refuse changes to them and their files carry the immutable attribute. A change
needs the operator's explicit words. Performance numbers come from this tree.

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
lives in `rejit/docs/evaluation.md` §5. Don't add `workload_miss`, `limitations`,
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
design in `rejit/docs/design.md`); historical
daemon/ReJIT designs under `docs/archive/` are not authoritative — no
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
`corpus/config/benchmark_config.yaml`: kinsn-class (kfunc lowering), bytecode
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
stable-to-frequent (base OS/apt → pre-built app artifacts → kernel/kinsn
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

## One tree, one branch

Operator, 2026-11-09: "以后禁止切换branch 和开不同的 tree". Every edit happens in this checkout on master. New git worktrees, clones, branches, branch switches and private edited source copies are banned. Builds, replays and guests also run from this checkout, with their recipes and scripts committed here, so exported source copies, copied benchmark trees (such as the former /paper-tree) and private harness directories go away as well (operator 2026-11-10: "/paper-tree 是什么???? 又违规开了 worktree 了?"). Commit and push every step at once ("做一步 commit push 一步").

## Oversized files on GitHub

Operator, 2026-11-09: "github 明确记录, 如果碰到这种大文件可以改写". A commit that has never been pushed and carries a file GitHub rejects for size may be rewritten to drop that file. This is the one exception to the history-rewriting ban above. Published history stays as it is. Tracked files stay under 50 MB.

## Direct native path

Operator, 2026-11-09: "直接 native 路径 要保留, 不允许删掉". The direct native (unbound) measurement path in `kprog/perf/direct-native/` stays.
