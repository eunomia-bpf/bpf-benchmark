# BPF development TODO — 2026-09-06 (updated 2026-09-07)

This is a current handoff for the stock-kernel userspace optimization line. It
does not replace older experiment logs, and it does not merge the KOperation
paper rebuttal backlog into this line of work.

## Current evidence

Experiment 093 is retained as ten completed x86 KVM Cilium runs from 2026-08-13:

- app: `cilium/agent`
- policy: `hot_region_version,map_inline`
- workload duration: 180 seconds per baseline and post-load-time phase
- artifacts: `corpus/results/x86_kvm_corpus_20260813_172108_373028` through
  `corpus/results/x86_kvm_corpus_20260813_201304_104628`
- raw sender-throughput post/baseline geomean: `1.0517214715`
- outcomes: 8 improvements, 2 regressions
- observed ratio range: `0.9477152911` to `1.1775151002`

These numbers were reproduced on 2026-09-06 from the two pktgen `pps` values in
each artifact's `details/apps/cilium__agent.json`. The two regressing artifacts
are `..._181919_954545` (`0.9733629766`) and `..._183805_997683`
(`0.9477152911`). They remain successful raw throughput results; no supplementary
check is being used to discard or relabel them.

There is already individual-pass evidence under the same two-start, 180-second
Cilium workload contract. The ten `hot_region_version` runs from
`x86_kvm_corpus_20260730_095500_065399` through `..._135809_421407` have a
post/baseline throughput geomean of `1.0504250464` (10 improvements, range
`1.0117898747`–`1.1075675098`). The ten `map_inline` runs from
`x86_kvm_corpus_20260730_143828_990498` through `..._183454_838901` have a
geomean of `1.0666709764` (10 improvements, range
`1.0133778469`–`1.1811505457`). These batches were collected on a different day
from experiment 093, so their ordering is useful prioritization evidence, not a
causal comparison of pass composition.

Static inspection adds one concrete lead: only six of the 45 retained Cilium
`hot_region_version` profiles contain sites, covering 22 branch roots, and every
recorded root is 100% one-sided. The pass clones the complete dominated tail at
each versionable merge; `map_inline` then performs another lift/optimization/
lower round trip over that output. The interaction can therefore change CFG and
code size substantially even though the profile confidence itself is not
borderline. This is a hypothesis to inspect against emitted bytecode, not an
explanation asserted from throughput alone.

## Completed artifact analysis — 2026-09-07

The retained per-program descriptors narrow that lead considerably. Comparing
the sorted multiset of `(name, type, bytes_xlated, bytes_jited)` values gives
three treatment fingerprints across experiment 093, corresponding to the 53,
56, and 62-program Cilium startup variants. For every program-count variant,
the difference from the matching retained `map_inline`-only fingerprint is
identical:

- two instances of `tail_handle_ipv`: `9272/5493` to `9480/5534` bytes
  (translated/JIT);
- two instances of another `tail_handle_ipv`: `9576/5507` to `10040/6001`;
- two instances of `tail_ipv4_ct_eg`: `8192/4406` to `8408/4657`; and
- two instances of `tail_ipv4_polic`: `8832/4969` to `9376/5395`.

The composed policy therefore retains a deterministic total increment of 2,864
translated bytes (358 BPF instructions) and 2,424 JIT bytes over `map_inline`
alone, localized to four tail-target signatures. It does not erase the
hot-region transformation. This comparison is based on descriptor sizes because
the successful-run bytecode and load-time JSONL reports were not retained.
Equal fingerprints do not prove byte-for-byte identity.

The size change also does not explain the two throughput regressions. Runs
`x86_kvm_corpus_20260813_174101_108576` and
`x86_kvm_corpus_20260813_183805_997683` have the same complete baseline and
treatment descriptor fingerprints, yet their throughput ratios are
`1.1133011040` and `0.9477152911`. The former improves in both directions
(`1.085674`, `1.140929`); the latter regresses in both (`0.966543`, `0.929607`).
Thus neither a different descriptor-size image nor a single-direction anomaly
accounts for the opposite outcomes. Runtime variance or byte-level differences
that preserve size remain possible; the artifacts cannot distinguish them.

Policy history shows that the absent layout flag is intentional, not an
oversight. Commits `2465d86a7` and `048bd66e4` successively enabled
`--layout-hot-roots` and `--layout-versioned-program-roots`; `e037c7a24` then
selected the current clone-only Cilium policy. Ten 5-second runs in each nearby
wall-clock interval have diagnostic geomeans of `1.0222359569` (7/3) and
`1.0395404731` (8/2), respectively, but their metadata does not record a source
revision. They are not causal or paper-grade comparisons and do not justify
re-enabling either flag.

Decision: keep the current pass policy. Do not add an arbitrary clone-size gate
or layout flag based on experiment 093. The next useful attribution needs the
actual per-step reports and bytecode for the four signatures above; changing
optimizer policy before that would outrun the retained evidence.

## Completed corrected-protocol cross-check — 2026-09-07

The newest retained 180-second, two-start `context_specialize` batches remove
two apparent leads from the immediate queue. Summing the raw stress-ng
`bogo ops` values across each app's configured stressors gives:

- Tracee, ten runs from
  `x86_kvm_corpus_20260813_101212_102293` through
  `x86_kvm_corpus_20260813_131003_298020`: post/baseline geomean
  `1.0003915611`, 5 improvements and 5 regressions, range
  `0.9791571678`–`1.0266156869`;
- BCC, ten runs from `x86_kvm_corpus_20260813_134141_183681` through
  `x86_kvm_corpus_20260813_164950_279285`: geomean `1.0043429528`,
  6 improvements and 4 regressions, range
  `0.9857216966`–`1.0638023681`.

Every Tracee run has the same 151-program baseline and treatment descriptor
fingerprints. Only `trace_sys_enter` (`13768/8190` to `12296/7260` translated/JIT
bytes) and `trace_sys_exit` (`13824/8223` to `12344/7280`) change, for a total
reduction of 2,952 translated bytes (369 BPF instructions) and 1,873 JIT bytes.
Every BCC run likewise has one deterministic descriptor change: `sys_exit`
grows from `656/402` to `872/567`, or 27 BPF instructions and 165 JIT bytes.

The earlier ten-run July batches remain raw evidence, but they are not the best
estimate of the current two-start result. Their apparent geomeans were
`1.3438044599` for Tracee and `1.1491782960` for BCC, while their optimized
descriptor fingerprints are identical to the corresponding corrected August
batches. Equal sizes are not proof of equal bytes, and the retained metadata
does not record a source revision or the missing load-time reports. The later
result commits explicitly identify their runs as corrected; the opposite
throughput outcomes therefore cannot be attributed to the optimizer from the
retained size data.

A separate corrected running-process Tracee batch provides attribution but is
not the accepted two-start measurement path. In all ten successful runs from
`x86_kvm_online_20260813_064118_412360` through
`x86_kvm_online_20260813_093359_017775`, the embedded per-step reports show one
site applied in each of `trace_sys_enter` (1,703 to 1,417 optimizer
instructions) and `trace_sys_exit` (1,710 to 1,423). That live-replacement
batch has a workload geomean of `0.9812740790`, with all ten runs regressing
(`0.9544709096`–`0.9972528802`). It is useful corroboration that the intended
sites were transformed, not a substitute for the two-start result.

Decision: keep `context_specialize` outside the default policy and do not spend
the next runtime window repeating its present single-value Tracee/BCC profiles.
The current Tracee profile directory has only 3 nonempty files out of 273, all
single-field deployment hints. A future multi-value profile is a new hypothesis
and needs its own measured provenance; the older unrecorded "two-context" and
"four-context" configurations cannot justify reconstructing one by guesswork.

The missing Cilium attribution can be captured without another runner. The
current normal corpus path writes its plan to `details/loadtime-plans/` and its
JSONL step reports to `details/loadtime-reports/`. With `KEEP_WORKDIRS=1`, the
load-time shim selects `details/loadtime-workdirs/` for each program's
`input.bin`, step outputs, and reports. These detail directories are ignored by
the repository, which is why the committed historical snapshots do not contain
them. On the next Make-backed run, preserve them outside the ignored-only
working copy and verify their presence before ending the runtime session; this
is artifact capture, not a new measurement-admission gate.

## Completed remaining single-pass breadth check — 2026-09-07

The other retained July 180-second batches give a secondary ordering after the
Cilium attribution work. These are post-hoc workload calculations, not new
benchmarks, and comparisons between their separate wall-clock batches are not
causal:

- Katran `map_inline`, ten runs from
  `x86_kvm_corpus_20260729_175727_128341` through
  `x86_kvm_corpus_20260730_084820_320412`: summed four-thread pktgen `pps`
  geomean `1.0911970593`, 10 improvements, range
  `1.0703673065`–`1.1051254691`. Every run has the same sole descriptor change,
  `balancer_ingres` from `23840/13629` to `20400/12306` translated/JIT bytes
  (430 fewer BPF instructions and 1,323 fewer JIT bytes).
- Katran `hot_region_version`, ten runs from
  `x86_kvm_corpus_20260730_190941_958365` through
  `x86_kvm_corpus_20260730_230621_961439`: geomean `1.0143077008`,
  8 improvements and 2 regressions, range
  `0.9923762829`–`1.0272763225`. Its sole descriptor change grows the same
  `balancer_ingres` program to `24416/14326` bytes (72 BPF instructions and
  697 JIT bytes).
- Tetragon `map_inline`, ten runs from
  `x86_kvm_corpus_20260729_182910_317337` through
  `x86_kvm_corpus_20260731_063637_522652`: summed stress-ng bogo-ops geomean
  `1.0076942898`, 7 improvements and 3 regressions, range
  `0.9843063624`–`1.0222094686`. The deterministic descriptor transition spans
  159 of 287 program instances and removes 173,808 translated bytes (21,726
  BPF instructions) and 91,323 JIT bytes; without the ignored per-step
  reports, that broad size change cannot identify the
  qualified-and-affected tail-call population.

Decision: if the Cilium bytecode inspection does not produce a stronger scoped
change, Katran `map_inline` is the next retained candidate worth confirming on
the current runtime. Katran hot-region versioning and broad Tetragon map-inline
work are lower priority on the available throughput evidence. No optimizer or
pass-policy change is justified from these separated batches alone.

## Prioritized work

1. Complete devcontainer acceptance after the infrastructure owner can publish
   and deploy the prepared rollout. The user explicitly approved
   `privileged=true` for this BPF Workspace and its rebuild. Automatic review
   rejected publication to the shared systems-dev template because that wider
   shared-template scope lacked explicit approval; publication, restart, and
   runtime privilege changes have not happened. The prepared infrastructure
   commits are `1b2998b3` and `2955d2a3` in `spark-manage`. Do not retry or route
   around that decision from this repository. After infrastructure deploys it,
   verify `docker info`, writable `/dev/kvm`, `vng --version`, the documented
   `gpt-5.6-sol` high/full-permission invocation, `make check`, and then one
   public Make-backed KVM smoke target. Record command, exit status, and artifact
   path; do not claim acceptance from process activity alone.
2. Preserve experiment 093 and recover the missing attribution only through the
   normal Make-backed path. Run it with `KEEP_WORKDIRS=1`, retain the ignored
   `details/loadtime-{plans,reports,workdirs}/` payloads, and confirm that the
   four affected signatures have input, per-step report, and output bytecode.
   Then compare `sites_applied`, control-flow layout, and instruction/JIT-size
   changes. Include the attached caller and tail-call descendants; tail
   targets' zero `run_cnt` is expected and is not non-execution.
3. Use that bytecode comparison to decide whether a smaller hot-region transform
   is justified. If it is not, retain `map_inline` alone as the stronger current
   Cilium candidate rather than adding an unevidenced optimizer heuristic.
4. Run a new Cilium comparison only if that inspection leaves a decision that
   existing artifacts cannot answer. Use `BPFREJIT_CORPUS_APPS="cilium/agent"`,
   `BPFREJIT_BENCH_PASSES`, `WORKLOAD_DURATION`, and `SAMPLES` on `make corpus`;
   do not invoke runner internals. A matched/no-op control is optional, not an
   admission gate, and `SAMPLES=3` remains the cap.
5. After resolving the Cilium interaction, continue the existing single-pass
   queue with one current-protocol Katran `map_inline` confirmation if runtime
   is available. The corrected Tracee/BCC `context_specialize` evidence is
   accounted for and does not need a repeat without a new, measured profile
   hypothesis; Katran hot-region versioning and Tetragon `map_inline` are lower
   priority. Keep all failures and raw results. Do not filter programs, alter
   workloads, or add new measurement-validity gates.

The older branch-layout and KOperation documents remain historical evidence for
their own paper lines. Revisit them only when those lines are explicitly chosen;
they are not prerequisites for the current stock-kernel speculative work.

## Current execution boundary — 2026-09-07 17:50 UTC

The independent retained-artifact work is exhausted. It has already accounted
for the Cilium interaction, the corrected Tracee/BCC neutral results, and the
Katran `map_inline` candidate; none supplies the missing per-step Cilium
bytecode or a current-protocol Katran confirmation. There is therefore no
evidence-supported optimizer or pass-policy change to make before collecting
new runtime evidence.

Both remaining application results require the public Make-backed KVM path:
the Cilium attribution run needs its actual load-time plan, JSONL step reports,
and input/output bytecode, while the Katran candidate needs a current
`make corpus` confirmation. The present Workspace has writable `/dev/kvm` but
still lacks Docker, dockerd, QEMU, and `vng`, so neither run can start here.
This is an execution blocker, not a failed benchmark; no new measurement has
been run or claimed.

The user approved `privileged=true` for this BPF Workspace and its rebuild, but
publication of the prepared shared systems-dev template was rejected because
that wider shared-template scope lacks explicit approval. No publication,
Workspace restart, or runtime privilege change has occurred, and no new
approval for the shared scope arrived. The infrastructure owner retains the
prepared `spark-manage` commits `1b2998b3` and `2955d2a3`; do not retry or
bypass that publication decision from this repository. Independent application
work resumes after that owner can publish and restart the Workspace, beginning
with the acceptance checks and normal Make-backed runs in the prioritized list
above.


## 最新用户目标：OSDI 级 kprog 迭代与统一 research skills（2026-09-08）

用户原话：“让里面的 codex 带着本地模型去快速推进, 确保迭代到符合 osdi 的程度. 然后我们的 research skills 也得作为 submdoule 安装到这两个 repo 里面”。本 Workspace 负责 BPF benchmark/kprog；eBPFOS 由它自己的 Workspace 负责。

请原会话 Codex 接收并确认此目标，沿用当前研究阶段持续推进 kprog/native-sim，实现、实验/证明、独立检查由你结合可用本地模型自主分工。模型不可用则你直接继续。不要重做 bootstrap、搬迁论文、新增控制器/调度器/停工门槛或固定预算，不中断当前真实长构建。OSDI 是系统研究和论证质量目标，不是录用保证；研究产物不能由安装、日志或报告替代。

统一 research skills 源为 https://github.com/yunwei37/academic-writing-skills.git，必须用真实 git submodule，核验远端 revision；外层另一任务观察到的 HEAD 为 867d61c2fd50c506b5727067186b5ee4ff120f0d，仅供定位。当前 Workspace 中的独立本地 OpenCode 辅助 Agent PID176326 已受托只安装此 submodule，创建 .agents/skills 与 .claude/skills 的相对链接、保留已有skills并提交/push接入，不碰你的构建和实现。它会把结果写到 /workspaces/.agent-state/bpf-development/research-skills-install-result.md。你可以自主协调它或后续本地模型的非重叠工作，不要重复接入。接入后阅读 auto-research-orchestrator 及引用、现有paper/用户意图/实验状态，从当前阶段继续；当前用户最少复杂度和持续推进要求优先，不因技能文字新增人为停工规则，不调用用户未点名的 iter-refine-ideas。

用户还问：“kprog 的 simluator 支持 x86 / arm 都支持了吗? 效果咋样? simulatoir 的形式化验证怎样了?” 请核验真实支持面，区分历史结果与本轮复现，说明机器检查证明和缺口，并据此推进研究。外层只读证据供你核实：native-sim/README.md 仍称 arm64 placeholder，但 arm64/README.md 和实现代码已有 subset；两架构 20260523-134121 结果表各29行ok是旧证据；论文 documents/5-formal-verification.tex 与 sections/5-koperation.tex 是 KOperation/双lowering Lean证明，不等于NativeBPF simulator整体fidelity。请结合当前源码与 active main.tex 澄清、修正文档并补足有效验证，保留核心研究方向及原始失败/结果。收到后在原会话回复中明确确认，并将当前研究阶段、架构支持/效果/证明边界及继续行动写入你现有研究记录。


### 用户后续明确补充：两篇论文与未完成形式化继续实现

用户原话：“你也要让里面的 codex 开始去吧 speculative 和 kprogs 的论文都得写一下”；“形式化还没做完的继续去做”。BPF现有子模块 docs/speculative-optimization -> https://github.com/yunwei37/speculative-optimization.git 属于本项目既有paper子模块，不创建新Workspace。请同一原Codex统筹并实际更新 docs/kprog-simulator-in-ebpf/main.tex 对应稿件和 speculative 稿件，允许本地模型并行负责非重叠写作/独立检查，分别保持两篇科学故事和数据，不把两路线或KOperation混成一篇。不能仅写TODO；缺失结果明确占位，已有结果核验后使用，不为写作打断实际长实验。

kprog仍优先实现和形式化。请实际推进尚缺的证明代码与可复现机器检查，按现有设计处理 ISA fidelity、specialization preservation、verifier-visible boundaries 和 artifact binding；工具、可信ISA语义及模型分工由你选。区分机器检查已覆盖、假设和尚未证明内容，x86/ARM支持面如实写清。当前kprog main.tex 引用4-safety条件refinement与5-evaluation-plan，未引用旧KOperation Lean章节；旧Lean文字不能充当simulator整体证明，native preview速度也不能冒充verified execution。论文、证明代码和实际实验需一起推进。OSDI为质量目标，不保证录用；保持用户核心方向，模型不可用则你直接继续。

[Operator resource update, not experiment evidence]
The existing spark-gateway/qwen3.8-27b-nvfp4-200k model is configured in this Workspace. Another owning QA task recently verified the same 27B backend with real Bash tools and continuation (OMP litellm provider; no fallback), and earlier shared-runner OpenCode tool execution passed on 27B. This is recent evidence, not a guarantee of the current request. The default Qwen Next helper request here had an actual API error. You may autonomously choose the existing 27B alias for useful non-overlapping paper/proof collaboration with existing credentials, or continue directly if unavailable. No global default or credential change is needed. The user specifically wants actual kprog and speculative manuscript updates alongside unfinished proof implementation; these need not wait for selftest to finish.
[End operator resource update]


### 2026-09-08 operator follow-up: continue automatic repair

User: “别的也是, 以后记住, 出问题了就去自动修好, 不要等我批准, 全部都去继续修, 要确保都是正常的, 有问题就去主动帮忙修复”。
Continue the existing kprog real VM/selftest, x86/ARM evidence, unfinished formal verification and both paper updates. Diagnose and repair actionable failures without waiting for another reminder; preserve this session and concurrent work. Infrastructure agent is repairing the shared systems-dev tool installation so existing vng no longer skips required BusyBox and matching bundled virtme executables. Do not wait for template adoption or restart this running experiment. Choose implementation and validation autonomously; unavailable local helpers are not a reason to stop. Keep actual authorization, data preservation and truthful acceptance boundaries.

## Kprog implementation and acceptance — 2026-09-08

This section supersedes the stale 2026-09-07 execution boundary above without
deleting its historical record. The Workspace now runs the
`systems-dev docker-cache-20260908` rollout: Docker uses its default storage
driver on an uncapped `/var/lib/docker` emptyDir, `/dev/kvm` is writable, and a
real default-driver `docker run` plus `KVM_CREATE_VM` probe passed. There is no
remaining shared-template publication dependency for the work below.

### Implemented

- Added the project-owned devcontainer build and startup hook. The image pins
  Docker, Go, Rust, AWS CLI, and virtme-ng versions; installs QEMU, the native
  and ARM64 cross-build dependencies, BusyBox, and udev; and starts dockerd
  idempotently with its ordinary defaults. The Rust install uses the corrected
  `--component rustfmt --component clippy` syntax.
- Corrected the x86 runner default to the LLVM 18 CMake package supplied by the
  devcontainer. ARM64 continues to use the in-tree cross-built LLVM package.
- Completed native application artifact compilation for all six corpus apps.
  Tetragon now compiles only its concrete kernel-version variants, rather than
  invalid unparameterized variants, and native compilation enables the source
  extensions those upstream headers require. Frozen applications, workloads,
  app runners, and benchmark launchers were not changed.
- Added a shared `unchecked_packet_read` stage-2 negative fixture. Both x86-64
  and AArch64 proof builds translate the same native source. The public test
  suite requires the resulting proof to fail with the verifier's
  `invalid access to packet` diagnostic; an arbitrary loader failure is not
  counted as success. The old x86-only skip is gone.
- Removed the stale `test_recompile` hook: it silently skipped a path under
  `tests/kernel/` even though that component no longer exists anywhere in the
  repository.
- Added `native-sim/formal`, a Lean 4.19 model that separates architectural
  bits from verifier-facing provenance tags. It machine-checks one-step and
  list-level refinement for two registers and the shared MOV, add-immediate,
  multiply-immediate, and packet/packet-end ABI-load fragment. A mutation that
  scalarized ADD provenance was rejected at `step_tags_sound`, demonstrating
  that the tag theorem is not tautological.
- Updated both paper submodules without mixing their scientific stories.
  Kprog commit `4dbf5d3` documents the NativeBPF proof boundary and current
  obligations; speculative-optimization commit `c7af054` narrows claims to the
  retained evidence. Both submodule commits and their PDFs were built and
  pushed before the parent update.

### Actual validation and retained failures

- A first public `make selftest` attempt with the host's Go 1.27.1 failed before
  VM launch in Cilium (`undefined: http2.TrailerPrefix`). Re-running with the
  project-pinned Go 1.26.8 built the complete image and executed the guest, but
  vng fell back to the serial console because the devcontainer lacked udev, so
  the guest result could not be returned and Make exited 255. Both failures are
  retained as diagnostics; neither is described as a benchmark result.
- Adding udev fixed vng's virtio-port discovery. The public invocation
  `PATH=/opt/go1.26.8/bin:/opt/virtme-ng/bin:/usr/lib/llvm-18/bin:$PATH JOBS=4 make selftest`
  then completed through QEMU/KVM and powered the guest down normally. All 29
  `native_proof` micro cases completed in the smoke configuration. The raw
  micro result is
  `tests/results/45870422/native_proof_micro_20260908_111306_925197/metadata.json`.
  The new x86 proof retained an unguarded byte read at packet offset 64 for a
  64-byte input and was rejected with `invalid access to packet, off=64 size=1`;
  the suite reported `PASS unchecked_packet_read rejected rc=1`. The four
  existing verifier-negative cases also passed. This is a functional KVM
  smoke, not a throughput benchmark or paper-grade performance result.
- After moving the negative policy to its shared `native-sim/test/` location,
  the same public command was run again against the final tree and exited 0.
  Its 29/29 raw result is
  `tests/results/827ac6f0/native_proof_micro_20260908_123347_809195/metadata.json`;
  the complete Make/vng/QEMU console log is retained at
  `/workspaces/.agent-state/bpf-development/kprog-selftest-20260908-final.log`.
  The guest again reported the exact offset-64 verifier rejection and powered
  down normally.
- `make host-x86-sim-proofs` rebuilt the shared negative proof and all 29 x86
  workload-derived proofs successfully. The negative proof contains 30 eBPF
  instructions and retains its offset-64 byte read.
- `JOBS=16 make host-arm64-sim-proofs` performed a fresh ARM64 kernel, EFI,
  module, micro-native, and proof build. All 29 workload-derived AArch64 proofs
  completed successfully. The shared negative proof contains 8 eBPF
  instructions and its disassembly contains `r2 = *(u8 *)(r1 + 0x40)`, so the
  unsafe access was not optimized away. This is current cross-build evidence;
  no new ARM64 guest verifier/runtime result is claimed.
- `make -C native-sim/formal check` and direct Python bytecode compilation of
  `runner/suites/test.py` pass. The root `make lint` still exits 2 because it
  descends into the unmodified vendored LLVM tree and invokes Python 3 on
  `polly/lib/External/isl/imath/tools/findthreshold.py`, a Python 2 script with
  a bare `print` statement. This failure is preserved and is unrelated to the
  changed runner module; the frozen root Makefile was not altered to hide it.
- A full devcontainer build succeeded as
  `bpf-benchmark-devcontainer:validation-kprog-20260908` (manifest-list digest
  `sha256:688b07c2a55c6dbd79446cab52411d710949de6e806cc15c375ae35fb001a971`).
  A container invocation confirmed Go 1.26.8, Rust 1.98.1, rustfmt, clippy,
  virtme-ng 1.41, udev, systemd-tmpfiles 255, pyelftools 0.30, and LLVM 18 CMake
  metadata.

### Supported surface and remaining proof boundary

The honest support statement is now: both x86-64 and AArch64 implement and
freshly build the instruction subsets emitted by the current 29 micro kernels;
x86 additionally has a fresh real KVM load/test-run smoke. Neither simulator
implements the full target ISA. Historical ARM64 runtime and performance
results remain useful retained evidence, but this work did not rerun or relabel
them as a new benchmark.

Verifier acceptance applies to the generated eBPF proof artifact. The loader
also records the native blob identity, but the current path does not yet bind
the accepted proof semantically or cryptographically to every native byte that
will execute. The Lean model checks a small shared transition fragment and is
not connected mechanically to the C macro definitions; it does not cover
memory, flags/branches, helpers, the complete workload-derived instruction
sets, or the paper's full O1--O4 argument. Therefore neither the 29-case smoke
nor the bounded theorem is described as verified direct-native execution.

The next high-value kprog work is to make the operation/tag policy a shared
declarative source for the C and Lean transitions, extend refinement over
memory and control flow, and bind the accepted proof artifact to the exact
native payload. A fresh ARM64 QEMU/AWS selftest can then exercise the new
negative proof on its target verifier. These are remaining research tasks, not
new mandatory gates for unrelated experiments, and no new optimization
throughput benchmark is claimed here.
