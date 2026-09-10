# BPF development TODO — 2026-09-06 (updated 2026-09-09)

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

## 2026-09-08 continuation: shared pointer-add semantics and ARM64 guest path

### Implemented formal/implementation correspondence

- A source audit found that the original Lean `addImm64(dst, imm)` model did
  not match the implementations it named. The provenance-preserving x86 path
  is `LEA dst, [src + off]`, and the AArch64 path is `ADD dst, src, rhs`;
  x86 `ADD_IMM` instead goes through a scalarizing arithmetic write. The old
  theorem was internally consistent but could not substantiate C-handler
  correspondence.
- Replaced that operation with `ptrAdd64(dst, src, rhs)` and added
  `native-sim/formal/ptr_add_spec.json`. Its small generator emits both the
  Lean bits/tag transition and the C macros actually used by the x86
  non-stack LEA and AArch64 non-scalar ADD branches. `make -C
  native-sim/formal check` first rejects stale generated files, then builds the
  theorem. The check and Lake build exit 0.
- This is a real but narrow mechanical connection: source-plus-offset bits and
  copy-source-tag policy now share one declarative AST. The renderer,
  decoder-to-handler mapping, C compiler, multiply/ABI-load handlers, memory,
  control flow, helpers, specialization, and artifact binding remain outside
  this proof slice.
- `PATH=/opt/go1.26.8/bin:/usr/lib/llvm-18/bin:$PATH JOBS=16 make
  host-x86-sim-proofs` exits 0 after rebuilding the shared negative proof and
  all 29 x86 proof artifacts. This is compilation evidence only; it is not a
  new verifier or performance run.

### ARM64 public-Make bring-up failures retained

- The first QEMU preflight failed before VM launch because
  `$(ARM64_QEMU_ROOT_READY)` depended on an image-tar pathname with no Make
  rule. It now depends on the existing `arm64-runner-runtime-image-tar`
  producer; no runner or benchmark workload was added.
- The next attempt exposed OTel collector builder host/target conflation:
  `GOARCH=arm64 go run .../builder` built an AArch64 builder and tried to
  execute it on x86, yielding `exec format error`. The vendor build now
  installs the builder as a host tool, then applies `GOOS/GOARCH/CC` only when
  that tool builds the collector. A subsequent run compiled the AArch64
  collector successfully.
- The following attempt reached Tracee and failed because its AArch64 external
  link omitted the existing cross sysroot (`cannot find -lelf` and `-lz`).
  Passing the sysroot library/rpath flags through Tracee's upstream
  `CGO_EXT_LDFLAGS_EBPF` fixed the link; the next run produced an AArch64
  Tracee binary and passed its `file` check.
- That run then exposed the same omitted sysroot at the BCC libbpf-tools link.
  The AArch64 BCC target now receives the same flags through its existing
  `EXTRA_LDFLAGS` parameter. The raw failed-attempt logs are retained under
  `/workspaces/.agent-state/bpf-development/kprog-arm64-qemu-preflight-20260908*.log`.
  Validation of the BCC fix and the first fresh AArch64 guest result is still
  in progress at this checkpoint; no ARM verifier/runtime success is claimed
  by this paragraph.

## 2026-09-08 completion of the shared-ABI slice and ARM64 functional experiment

This section supersedes only the in-progress statement immediately above. It
preserves the failed attempts and their logs as part of the experiment record.

### Implementation and proof correspondence

- Added `native-sim/formal/abi_load_spec.json` and a checked generator for the
  entry-ABI provenance transition. The same source now emits the Lean policy
  and the C macro invoked by both simulator implementations. It distinguishes
  XDP from `__sk_buff`, grants packet provenance only to their concrete
  `data`/`data_end` offsets, and scalarizes all other 64-bit ABI loads.
- Compile-time assertions bind the four generated offsets to the concrete x86
  and ARM simulator ABI structs. The x86 chunked-program generator also stores
  the selected ABI kind in simulator state, so TC and cgroup-skb programs no
  longer inherit the XDP offset policy.
- Lean now models the ABI kind plus an arbitrary signed offset. Its generated
  implementation transition is checked against an independently stated tag
  policy for both known fields and all unknown offsets. Together with the
  earlier shared pointer-add source, this mechanically prevents two observed
  classes of C/model drift; it remains a bounded register/tag theorem rather
  than a proof of the complete simulator.
- The common unsafe fixture now returns only `data[64]`. Its AArch64 native
  body and generated proof each contain three instructions, with one unique
  unchecked byte access. The suite requires the exact verifier diagnostic
  `invalid access to packet, off=64 size=1`, rather than accepting any packet
  error. This repaired a real false-positive oracle: the prior fixture's
  result-write helper compiled into an unrelated out-of-bounds store that the
  ARM verifier encountered first.

### ARM64 public-Make acceptance

- Added the missing cross-execution prerequisites to the project devcontainer
  and startup hook: static AArch64 user-mode QEMU plus idempotent binfmt
  registration. A real `linux/arm64` container then reported `aarch64`; this
  was tooling validation, not an experiment result.
- Corrected `runner/scripts/qemu-arm64-init` to derive its working directory,
  `PYTHONPATH`, and `PATH` from `BPFREJIT_IMAGE_WORKSPACE`. The previous
  hard-coded developer-home path caused the first guest preflight to fail at
  PID 1; that failure remains in
  `/workspaces/.agent-state/bpf-development/kprog-arm64-qemu-preflight-20260908-rerun11.log`.
- The repaired public preflight exited zero and wrote completed metadata at
  `micro/results/arm64_qemu_micro_19700101_000014_909678/metadata.json`.
- A first full run completed all 29 positive cases but rejected the unsafe
  proof at the fixture's unrelated packet store. Its raw metadata is preserved
  at `tests/results/08063080/native_proof_micro_19700101_000023_397290/metadata.json`;
  it is recorded as a contradictory negative-control result, not relabeled as
  successful evidence.
- After the fixture and exact oracle repair, the public invocation
  `PLATFORM=qemu ARCH=arm64 JOBS=16 TIMEOUT=1800 make selftest` exited zero.
  Metadata at
  `tests/results/e4a8b96d/native_proof_micro_19700101_000021_547969/metadata.json`
  is `completed` with exactly 29 cases; an independent check confirms every
  sample's result and return value match its configured expectation. The
  target verifier reports the exact offset-64 one-byte rejection, the negative
  smoke passes, and the guest powers down normally. The full log is
  `/workspaces/.agent-state/bpf-development/kprog-arm64-qemu-selftest-final-20260908.log`.
- This is a fresh AArch64 verifier/load/test-run result under full-system QEMU,
  not an ARM hardware or throughput measurement. The guest reports KVM HYP
  unavailable because the Workspace host is x86.

### Final x86-64 regression and automatic repair

- `JOBS=16 make host-x86-sim-proofs` rebuilt the reduced negative artifact
  (16 eBPF instructions) and all 29 positive artifacts successfully.
- The first final-tree `make selftest` attempt then exposed a new native-build
  collision rather than a verifier failure: the freshly generated x86
  `vmlinux.h` declares the `bpf_copy_from_user_str` kfunc, while the
  force-included compatibility header supplied a same-named function macro.
  The macro expanded the later prototype and Tetragon failed with two syntax
  errors. The failure is retained at
  `/workspaces/.agent-state/bpf-development/kprog-x86-kvm-selftest-final-20260908.log`.
- Native translation now defines the generated header's supported
  `BPF_NO_KFUNC_PROTOTYPES` boundary before any `vmlinux.h` inclusion. The
  compatibility header remains the single owner of native helper/kfunc call
  shims, including the flags-zero string-copy mapping. A preprocessing check
  removed the conflicting declaration, and the full native Tetragon artifact
  build then passed.
- The repaired public `JOBS=16 TIMEOUT=1800 make selftest` run exited zero.
  Metadata at
  `tests/results/b5881f99/native_proof_micro_20260908_200540_851719/metadata.json`
  is `completed` with 29 cases, and an independent check confirms every result
  and return value. The x86 target verifier rejects the reduced proof at the
  exact `off=64 size=1` read, all verifier negative smokes pass, and the KVM
  guest powers down normally. The full log is
  `/workspaces/.agent-state/bpf-development/kprog-x86-kvm-selftest-final-rerun-20260908.log`.

### Current remaining kprog scope

The implemented 29-program subsets now have fresh target-kernel functional
smokes on x86-64 KVM and AArch64 full-system QEMU. The shared pointer-add and
entry-ABI provenance transitions have a narrow C/Lean mechanical connection.
Still open are general memory and control-flow refinement, helpers and the
remaining ISA handlers, specialization preservation, and semantic or
cryptographic binding between the verifier-accepted proof artifact and the
exact native bytes/entry ABI that execute. ARM hardware reproduction and
performance of the accepted-and-bound population are also outstanding. No
performance conclusion or complete-project claim is made from these smokes.


### Operator evidence audit 2026-09-08 19:07 UTC
Outer heartbeat independently verified the final ARM64 result: completed, 29 cases/29 samples with zero result or retval mismatches, exact off=64 size=1 verifier rejection and normal guest power-down in the final QEMU log. This is a real ARM64 QEMU guest functional run, not native ARM hardware or KVM acceleration. The raw metadata currently labels provenance.environment as bare-metal, repo_git_sha/kernel_commit as unknown and timestamps in 1970 (guest clock). Preserve the original raw bytes and prior false-positive evidence; reconcile those provenance gaps in the existing report/manifest and future collection as part of your ongoing evidence work. Do not promote these timings to a hardware performance result. This is an observation for your autonomous next useful boundary, not a new mandatory gate or a request to interrupt the current x86 regression.

## 2026-09-09 current-revision native performance opportunity

### Historical-number and path audit

- The May x86 six-app `1.349x` and ARM six-app `1.056x` values are
  higher-is-better native/eBPF *workload-throughput* ratios. They do not measure
  the current proof path.
- The historical pure-bytecode `1.478x` and helper/map `1.429x` values are the
  reciprocals of lower-is-better `native_kernel / kernel` execution-time ratios
  (`0.677` and `0.700`). They use the trusted native-lab preview, not accepted
  and bound NativeBPF execution.
- `native_proof`, used by the completed x86 and ARM functional smokes, loads and
  test-runs the generated verifier-visible eBPF proof. It does not execute the
  original native program. `native_kernel` installs and test-runs a direct
  native blob through the test-only native-lab module, but the module's trivial
  companion proof is not semantically or cryptographically bound to that blob.
  The paths therefore answer different questions and cannot be combined into a
  verified-native speedup claim.

### Public-Make performance experiment

The experiment plan, post-hoc analyzer, complete paired values, and review live
under
`docs/tmp/build-and-evaluate/step-0002-20260908T235430+0000/experiment-001/`.
The public preflight
`BENCH=simple RUNTIMES="kernel native_kernel" SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000 make micro`
exited zero and wrote
`micro/results/x86_kvm_micro_20260909_002321_849025/metadata.json`. Its
three-sample median was 6 ns for kernel and 7 ns for native, useful
contradictory evidence that the historical aggregate could not simply be
assumed.

The full public invocation
`RUNTIMES="kernel native_kernel" SAMPLES=15 WARMUPS=1 INNER_REPEAT=100000 make micro`
then exited zero and wrote
`micro/results/x86_kvm_micro_20260909_005014_965526/metadata.json`; the KVM guest
powered down normally. The complete log is retained at
`/workspaces/.agent-state/bpf-development/kprog-x86-performance-full-20260909.log`.
Strict post-hoc validation accepted all 29 benchmarks and all 870 measured
result/return-value pairs, with the native upload/load/run phases present.

The unweighted geometric mean of per-program median
`native_kernel.exec_ns / kernel.exec_ns` ratios is `0.6758480953`, or a
reciprocal direct-native speedup of `1.4796224283x`. A fixed-seed 50,000-draw
program-population bootstrap gives ratio interval
`[0.6080548053, 0.7524066802]`; 26 programs are faster, two tie, and one is
slower. Native code size is `0.5377131546x` the kernel-JIT size by the same
aggregation. The current load/compile path is instead `47.5423272677x` slower;
the median of per-program medians is 1.835 ms for kernel loading versus 115.906
ms for `native_kernel`.

This closely reproduces the old pure-bytecode upper-bound magnitude on the
current 29-program population, but it remains a trusted-component opportunity,
not C2 or verified native execution. The sole loss is the 6--7 ns
`simple_packet` case, where integer per-iteration `BPF_PROG_TEST_RUN` timing is
visibly quantized. The bootstrap describes variation across the 29 program
ratios; it does not eliminate timer quantization, CPU-frequency caveats, or the
need for a second machine.

### Evidence and manuscript updates

- The AArch64 functional result review now preserves and explicitly reconciles
  its raw provenance defects. `bare-metal`, 1970 guest timestamps, and unknown
  repository/kernel commits remain untouched in the raw JSON. The public
  `PLATFORM=qemu ARCH=arm64` command, QEMU-specific kernel command line, x86-host
  log, and `7.0.0-rc2+` guest version establish full-system emulation, but not
  the missing exact kernel commit or ARM hardware performance.
- The kprog evaluation section now reports the new repeated x86 opportunity,
  code-size result, and load/compile cost while keeping the artifact-binding
  limitation explicit. The speculative paper now states both ratio directions:
  execution time below one is faster, whereas workload throughput above one is
  faster. It does not import kprog measurements into its scientific story.
- Both manuscripts build successfully with `latexmk`; the existing layout
  warnings remain non-fatal.

### Remaining high-value scope

The current functional and performance evidence leaves the central NativeBPF
task unchanged: implement runtime binding between the exact verifier-accepted
proof and the exact native bytes/entry ABI that execute, extend the C/Lean
correspondence beyond pointer-add and entry ABI loads to memory, control flow,
helpers, and remaining handlers, and prove specialization preservation. Rerun
the same comparison through the accepted-and-bound path rather than treating
the 1.4796x upper bound as achieved system performance. ARM hardware functional
and performance reproduction and production-application accepted-and-bound
throughput also remain open. The speculative paper separately still needs its
profile-value and held-out profitability experiments; this kprog run supplies
no new speculative-optimization performance evidence.

## 2026-09-09 generation-bound native execution milestone

### Runtime implementation

- The native-lab slots on x86-64 and AArch64 now retain the uploaded verifier
  proof and a non-wrapping 32-bit mutation generation alongside native bytes
  and relocations. The KOP sidecar carries a 9-bit slot id and the generation;
  verifier instantiation and native emission both reject a stale generation.
  Every blob, relocation, or proof write advances the generation before
  mutation, and exhaustion returns `EOVERFLOW` rather than allowing an ABA
  match. Generation zero remains the explicitly unbound trusted lower-bound
  mode for historical comparisons.
- The loader separately opens and stock-verifier-loads the relocated proof,
  uploads that same instruction vector to the native slot, reads the resulting
  generation, and constructs a bound KOP stub. It rejects proof calls, nested
  KOPs, pseudo `ldimm64`, empty proofs, and proofs above the implemented bound.
  Every proof `EXIT` is redirected to its KOP-region boundary; for multi-chunk
  blobs the full CFG is placed on the final chunk and leading chunks use the
  verifier-safe `r0 = 0` continuation.
- Successful stub loads no longer request a full verifier trace. A failed
  silent load is retried only to collect a bounded diagnostic log while
  preserving the primary errno. This fixed real success-path `ENOSPC` on
  loop-heavy proofs without hiding actual load failures.
- The kernel verifier's two KOP proof scratch sites now allocate from the
  descriptor's `max_insn_cnt`, removing the unrelated fixed 256-instruction
  ceiling. ARM JIT KOP emission likewise allocates bounded scratch from
  `max_emit_bytes` instead of rejecting every descriptor above its former
  fixed 64-instruction/256-byte stack buffer; all return paths free it.

### Preserved failures

- The first x86 full attempt and focused reproducers remain at
  `micro/results/x86_kvm_micro_20260909_094215_341511/metadata.json`,
  `micro/results/x86_kvm_micro_20260909_101556_226850/metadata.json`,
  `micro/results/x86_kvm_micro_20260909_111713_283313/metadata.json`, and
  `micro/results/x86_kvm_micro_20260909_114315_763230/metadata.json`. They
  preserve the loop-final-EXIT assumption, proof placement, uninitialized-R0,
  and verifier-log `ENOSPC` failures; the partial corrected run remains under
  `micro/results/x86_kvm_micro_20260909_104608_695915/`.
- ARM attempts under
  `micro/results/arm64_qemu_micro_19700101_000021_338346/` and
  `micro/results/arm64_qemu_micro_19700101_000022_284039/` preserve the stale
  256-proof-buffer failure and the subsequent errno-524 ARM emit-scratch
  failure. Each was stopped only after multiple cases reproduced the same
  cause. A separate pre-guest Docker build failed when the host's AArch64
  binfmt registration disappeared; restoring the installed system registration
  made a real `docker run --platform linux/arm64 ... /bin/true` exit zero before
  the final public Make run.

### Repeated x86 performance result

- The public command
  `RUNTIMES="kernel native_kernel" SAMPLES=15 WARMUPS=1 INNER_REPEAT=100000 TIMEOUT=7200 make micro`
  exited zero and wrote
  `micro/results/x86_kvm_micro_20260909_121208_577260/metadata.json`. Strict
  post-hoc validation found 29 programs, 870 matching result/return-value
  pairs, and proof/load phases in all 435 native samples.
- The geometric mean across programs of median `native_kernel / kernel`
  execution-time ratios is `0.6824347261`, whose reciprocal is
  `1.4653416096x`; 26 programs win, two tie, and one loses. The 50,000-draw
  program-population bootstrap ratio interval is
  `[0.6135276985, 0.7592106567]`, and native/kernel code-size ratio is
  `0.5377131546`.
- Load cost is reported with non-interchangeable aggregations. The geometric
  mean of the 29 per-program load ratios is `54.5205457812x`. Separately, the
  medians across per-program median loads are 116.192 ms native and 1.869 ms
  kernel; the proof-open and proof-verifier-load medians are 31.490 us and
  2.529 ms. Dividing the two load medians does not reproduce the ratio
  aggregate.
- This is a real performance result for the generation-consistent test path,
  not proof of proof/native semantic equivalence, production workload
  throughput, or a multi-machine result. The previous generation-zero
  `1.4796224283x` result remains a distinct trusted-native opportunity run; the
  small difference is descriptive, not a causal binding-overhead estimate.

### ARM64 generation-bound functional acceptance

- After rebuilding the changed kernel and fixing the ARM JIT scratch defect,
  `PLATFORM=qemu ARCH=arm64 RUNTIMES=native_kernel SAMPLES=1 WARMUPS=0 INNER_REPEAT=1 TIMEOUT=7200 make micro`
  exited zero and wrote
  `micro/results/arm64_qemu_micro_19700101_000024_077043/metadata.json`.
  Independent JSON validation found status `completed`, exactly 29 programs
  and 29 samples, 29 matching results, 29 matching return values, and positive
  proof-open/proof-verifier-load phases for all 29 samples. The guest powered
  down normally.
- This is AArch64 full-system QEMU TCG functional evidence, not ARM hardware
  performance. Raw 1970 guest timestamps are preserved and are not used as
  provenance; the external command/result record supplies the environment
  interpretation. No ARM timing ratio is reported.
- `make -C native-sim/formal check` exits zero after these changes, and both
  manuscripts build with their existing non-fatal layout warnings.

### Remaining scope after this milestone

The module generation now binds proof and native bytes to one immutable load
snapshot on both implemented architectures, but it does not establish that the
trusted generator/native-link output semantically refines the verifier-visible
proof. General memory, control flow, helpers, remaining ISA handlers, and
specialization preservation remain the primary formal work. ARM hardware
reproduction, production-application bound execution, and repeated performance
on those paths remain open. The speculative paper still needs its own real
profile-value and held-out profitability experiments; neither kprog micro result
is speculative-optimization evidence.


## User priority 2026-09-09: semantic proofs, commit and push each step

用户最新明确指令：“能不能确保语义证明去做, 做一步去 commit push 一步”。

从当前已完成的绑定/跨架构验收继续，实际推进尚缺的语义证明，不再只列为remaining scope。你自主选取有价值且可验证的增量证明单元；每完成一个实质语义证明步骤，完成相应机器检查，说明已证明范围/假设/剩余缺口，就立即精确commit并push并确认远端提交，然后继续下一步。不要攒到整套证明、整个研究项目或无关长实验结束才提交；也不要用空提交、只有TODO或论文措辞代替证明代码。snapshot/version绑定不是语义等价证明，更多benchmark也不是语义证明。当前已经验证的独立实现先及时提交，随后优先推进证明；正在运行的有效实验保留。

内部技术路线、模型分工和合理步骤粒度由你决定。可以使用现有本地模型辅助，不可用就直接继续。保留并发改动和原始证据、按精确路径提交，不等待额外批准。读到这条后请在原会话明确确认并实际执行；外层六小时监督已同步此要求，会核验每步的证明代码、机器检查和远端提交。

### Semantic-refinement progress, 2026-09-09

- `894f0f0ea` binds all 15 supported AArch64 condition predicates to one
  generated JSON/Lean/C contract and proves, for arbitrary flags and targets,
  equality with an independently stated architectural next-PC decision.
- `5e7581be9` does the same for the 14 x86 conditions implemented by the
  simulator (codes 0--9 and 12--15). Parity conditions remain outside the
  accepted subset, matching prior C behavior.
- `6cade628a` connects the actual x86 logical-result flag handler to a shared
  generated contract and proves its composition through the condition table:
  after width narrowing, `CF=OF=0`, `ZF=zero`, and `SF=sign` select the same
  next PC as the independent specification.
- Each step passed `make -C native-sim/formal check`. Both C-changing x86
  steps also passed `make host-x86-sim-proofs`: the preserved negative proof
  artifact and all 29 workload-derived proof artifacts compiled successfully.
  Independent read-only review found no blocker in any step.

These are semantic increments, not a full simulator/native equivalence proof.
The immediate proof gap is x86 width narrowing and zero/sign observation;
ADD/SUB/shift flag production, AArch64 flag production, decoder-to-handler
correspondence, general control-flow traces, memory, helpers, and specialization
preservation remain open. Generation binding and verifier acceptance continue
to establish different properties from these refinement theorems.

### Width and subtraction refinement, 2026-09-10

- `1f0ac4509` moves x86 width codes, masks, bit counts, narrowing, and
  zero/sign observations into a shared generated JSON/Lean/C contract. Lean
  checks all four legal widths and arbitrary 64-bit values against an
  independent enumeration; C static assertions bind codes 1/2/4/8. The first
  generated C ternary had an excess closing parenthesis. The build-only proof
  path rejected it; after fixing the generator, the negative artifact and all
  29 workload-derived artifacts compiled.
- `fe993be9d` moves the central x86 SUB flag transition into a shared contract.
  For arbitrary already-narrowed operands, result, and sign mask, Lean checks
  borrow, zero, sign, and overflow flags against an independent specification
  and composes them through every supported condition to the next-PC decision.
  Formal checks and the negative plus 29/29 build-only artifacts pass.

These theorems do not verify C unsigned operations against Lean `BitVec`, the
C compiler, decoder/handler selection, native bytes, or that the supplied SUB
result equals architectural subtraction. Those remain premises, not proved
facts. The next x86 flag-production units are ADD, ADC/SBB, and shifts;
AArch64 flag production and broader memory/helper/control-flow refinement
remain open.

### ADD and SBB refinement, 2026-09-10

- `88a457063` binds the central x86 ADD flag transition to generated JSON,
  Lean, and C expressions. For arbitrary already-narrowed operands/result and
  sign mask, Lean checks carry, zero, sign, and signed overflow and composes
  them through all supported conditions to next-PC. The direct build-only x86
  Make target compiled the negative artifact and all 29 workload-derived
  artifacts without rebuilding the kernel. Independent review additionally
  compared 100,000 random 64-bit tuples against the old C formulas.
- `adb50c32a` binds all three imm/reg/mem SBB result paths, the narrowed
  subtrahend, and the true SBB flag transition. Lean composes raw modular
  `a-b-borrow`, per-width narrowing, `(narrow(b)+borrow)&mask`, SBB flags, and
  next-PC. C normalizes borrow with `!!`, matching the Lean `Bool` domain.
- Review rejected an intermediate composition that incorrectly reused ordinary
  SUB flags. For `a=0,b=0,borrow=1`, real SBB has an all-ones result with
  `CF=true,ZF=false`, while that incorrect model produced
  `CF=false,ZF=true`. The invalid theorem was removed and replaced with the
  dedicated SBB contract; a second review also required narrowed `b` in the
  subtrahend to mirror the actual C local data flow. Final formal checks and
  negative plus 29/29 build-only artifact compilation pass.

ADD still assumes its supplied result rather than proving `a+b`; ADC has not
yet been separated from ADD to prove carry-in/result formation. Decoder and
handler selection, sign-mask derivation, C/Lean language correspondence,
compiler/native bytes, shifts, and AArch64 flag production remain open.

### ADC, arithmetic-result, and compare refinement, 2026-09-10

- `86d81485c` gives all five encoder-reachable ADC operand forms one generated
  result/flag contract and proves `a+b+carry`, width narrowing, ADC flags, and
  next-PC refinement. This fixed an implementation bug rather than merely
  documenting a premise: folding `rhs+CF` into ordinary ADD flags loses carry
  at boundaries such as `a=0,b=UINT64_MAX,carry=1`, and can also lose signed
  overflow. The dedicated ADC formulas now preserve the original carry input.
- `0291b1cfa` specializes that generated modular-addition result to
  `carry=false` in the central plain-ADD helper. Lean composes the actual result
  expression with narrowing and ADD flags, closing ADD's earlier free-result
  premise for all five binary ADD operand forms.
- `bd6b34428` extends the existing legal-width contract with canonical sign
  masks, routes the C ADD/SUB/ADC/SBB flag wrappers through it, and removes the
  free `sign` input from the width-aware ADD, ADC, and SBB step theorems. Lean
  also proves for every legal width and arbitrary value that testing this mask
  equals the independently stated sign-bit observation. SUB did not yet have a
  width-aware step theorem at this commit.
- `db6fe2d40` specializes the generated SBB result to `borrow=false` in the
  central plain-SUB helper and composes result, narrowing, width-derived sign
  mask, and SUB flags. It covers five binary SUB operand forms; CMP, DEC, NEG,
  and SBB remain distinct paths.
- `fb5eeab17` binds all five CMP operand forms, in both direct-macro and generic
  dispatch execution, to the same zero-borrow result and SUB flag contracts.
  Lean composes that width-aware value transition through every supported
  condition to next PC. TEST retains its separate logical-flags path.

Every increment passed the full generated-artifact freshness and Lean checks.
Every C-changing state also passed the existing direct build-only x86 Make
path: the preserved negative artifact and all 29 workload-derived proof
artifacts compiled successfully. Independent read-only review found no blocker
and checked operand-form reachability and claim boundaries. These results do
not prove parsing/decoder selection, memory operand reads, C unsigned semantics
against Lean `BitVec`, compiler lowering, or native bytes. Shift and remaining
unary flags, broader traces, memory/helpers, specialization preservation, and
AArch64 flag production are still open; no new performance experiment was run.

### ALU decode binding and unary arithmetic refinement, 2026-09-10

- `feb4e0735` moves all 16 accepted ALU mnemonic/name/code mappings into one
  strict JSON contract. Its generated Python table is consumed by the actual
  proof-artifact encoder, its generated C constants are consumed by the
  simulator, and Lean checks mnemonic and numeric code against an independent
  enumeration. This binds an already parsed mnemonic to the C ALU code; it
  does not verify objdump, assembly parsing, operand selection, or handler
  semantics that lack separate proofs.
- `6f110f90c` fixes a real remaining SBB bug in the encoder-reachable
  `sbb [mem],imm` and `sbb [mem],reg` handlers. They previously fell through
  ordinary `lhs-rhs` and supplied `borrow=0` to flags. Both now snapshot CF and
  use the proved SBB result/flag contracts, completing value/flag binding for
  all five binary SBB operand forms. The current frozen corpus contains only a
  register SBB, so formal checks cover the value semantics and 29/29 builds
  cover integration/compilation; they are not a targeted dynamic regression
  of the two memory-destination forms.
- `4513b455f` specializes generated ADD/SBB result contracts for INC/DEC and
  proves their result, width, ZF/SF/OF, explicit incoming-CF preservation, and
  next-PC composition. Register and memory-unary handlers share that value
  path, while memory read/store remains outside the theorem. Current artifacts
  contain many register INCs but no DEC or memory-unary INC/DEC.
- `017a53ee2` similarly binds NEG to the generated `0-a` result. Its independent
  architectural flag specification states `CF=(a!=0)`, `ZF=(r==0)`, result
  sign, and `OF=(a==sign_mask)`; Lean proves it for the actual result at all
  four widths and composes it through next-PC. A weaker intermediate
  arbitrary-result formulation was removed before commit. Current artifacts
  contain no NEG, so the 29/29 result is compile integration rather than a
  targeted runtime regression.

All four states passed the full formal target and the direct x86 proof-artifact
build with the preserved negative plus 29 workload-derived rows. Independent
read-only review approved the final diffs. The next semantic targets include
shift result/flag transitions, NOT flag preservation, the remaining
decoder/operand-selection relation, memory and helper transitions, C-to-Lean
and compiler/native-byte correspondence, specialization preservation, and
AArch64 flag production. No new performance measurement was made.
