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

### Shift, register-lane, and handler refinement, 2026-09-10

- `338284376` binds bitwise NOT to one generated C/Lean contract and proves
  width-local result plus flag preservation. `0823cdd3e` proves the x86 count
  mask as modulo 32 for 8/16/32-bit operands and modulo 64 for 64-bit operands.
  `880ef1111` composes that count with SHL/SHR/SAR/ROL results and fixes the
  previous narrow-width SHR/SAR errors. `99d5443bf` adds their flag transition
  proofs and fixes 8/16-bit ROL carry when a nonzero masked count is an exact
  multiple of the operand width. Architecturally undefined carry/overflow
  cases remain explicitly outside the claim.
- The public `make selftest` validation for the shift/flag state first failed
  during image construction with the host Go 1.27.1 because vendored x/net no
  longer exposed `http2.TrailerPrefix`. The project-pinned Go 1.26.8 path then
  exited zero through real x86 KVM. Raw metadata is
  `tests/results/88f4cb2d/native_proof_micro_20260910_111110_837266/metadata.json`:
  status `completed`, 29 programs, 29 samples, and 29/29 matching result and
  return value. The offset-64 unsafe packet-read proof was rejected with
  `EACCES`, and all four other verifier-negative smokes passed. This is a
  functional smoke, not a new performance result or full native equivalence.
- `8fb69e6ec` proves 8/16-bit upper-bit preservation, 32-bit zero extension,
  64-bit replacement, and scalarized provenance for the actual 16-register C
  writeback switch. `651f26251` composes generated ADD/ADC/SUB/SBB results,
  narrowing, flags, and low-lane writeback. `51fc7ad82` extends the primitive
  to typed low/high byte lanes and preserves the concrete review
  counterexample: writing `0xaa` to AH of `0x1122334455667788` must produce
  `0x112233445566aa88`, not an AL write. `c1fd32b50` independently proves the
  matching register observations, including AH extraction.
- `fad5d3921` adds one strict generated AUX layout with separate payload,
  destination-lane, and source-lane bytes, proves field/lane round trips, and
  carries it through MOV-immediate, MOV-register, and register SETcc in both
  direct and monolithic C paths. The first compatibility build failed all 29
  existing generated sources after changing the MOV macro arity; retaining
  the old three-argument wrappers and adding `_AUX` variants restored the
  preserved negative plus 29/29 build-only artifacts. The existing
  `mov [mem], ah/bh/ch/dh` source encoding remains a separate supported memory
  layout.
- `42075b32a`, `de7d7e6d9`, `d5a7f55dc`, and `cd13d7fa1` incrementally bind
  register ADD, ADC, SUB, and SBB to lane-aware operand reads and destination
  writeback. Their Lean theorems generate the result rather than accepting it
  as a premise; ADC and SBB consume the same immutable pre-state CF in result
  and flags. The encoder rejects mixed-width register pairs and still rejects
  high-byte memory forms rather than corrupting the incompatible memory AUX
  layout. An initially over-broad width check rejected legal `rol r9,cl`; that
  build failure was fixed by limiting the same-width rule to these arithmetic
  instruction families.
- `b3b673cf9` binds lane-aware register CMP in the encoder and both C paths,
  proves the generated zero-borrow subtraction flags, and separately proves
  that the complete destination bits/tag are unchanged. `bc23832e3` does the
  same for register TEST through AND, width narrowing, and generated logic
  flags. Its first Lean check exposed a missing `X86LogicFlags` import; after
  fixing that dependency and the proof script, full checks passed. Enabling
  dynamic CMP/TEST AUX increased `payload_prefix_memcmp_scan` proof bytecode
  from 360 to 384 instructions in the 29-row build-only corpus. This is an
  observed code-size/verification cost, not runtime-performance evidence.
- `77921fd1a` binds register NOT to the same lane AUX and shared unary C
  handler. A new Lean handler theorem composes lane observation, the generated
  complement, width-limited selected-lane writeback, provenance scalarization,
  and preservation of CF/ZF/SF/OF. The concrete regression changes AH from
  `0xaa` to `0x55` while preserving every other bit and all flags. An initial
  direct `bv_decide` proof exposed private byte-read terms as opaque and
  reported only potentially spurious counterexamples; the final proof instead
  composes the existing read, NOT, narrowing-invariant write, and flag
  refinement theorems. High-byte INC/DEC/NEG remain fail-fast.

Every final state above passed generated-source freshness checks, the complete
Lean target, the preserved negative proof build, and all 29 workload-derived
x86 proof-artifact builds. Each diff received independent read-only review,
was committed separately, pushed to `origin/master`, and verified against the
remote hash. The current artifacts contain no high-byte arithmetic/compare
case, so those successful builds are integration evidence rather than targeted
guest execution of the new lane paths.

Remaining proof scope is still substantial: the decoder/parser and handler
selection relation, immediate sign-extension and operand legality, high-byte
lanes for other ALU/extend/shift/load and memory forms, general memory and
helper transitions, multi-step control-flow traces, C unsigned semantics
against Lean `BitVec`, compiler/native-byte correspondence, specialization
preservation, and AArch64 flag production. The accepted proof and generation
binding still do not establish semantic equivalence of every native byte.

### Unary-lane and arithmetic-immediate refinement, 2026-09-10

- `34f0e0c27`, `6acb11fd9`, and `675bc5d7a` compose selected-lane reads,
  generated INC/DEC/NEG results and flags, selected-lane writeback, and tag
  scalarization. INC/DEC preserve the immutable input CF; NEG replaces CF from
  the actual `0-a` borrow. Boundary theorems cover high-byte wraparound,
  signed-min overflow, preservation of all non-selected bits, and provenance
  scalarization. The artifact encoder now accepts high-byte register forms for
  all four implemented unary operations (INC/DEC/NOT/NEG).
- `753ba7c28` replaces the handwritten C arithmetic-immediate cast helper with
  one generated JSON/C/Lean contract. For every raw 64-bit artifact field and
  legal width, Lean proves that the generated mask/or implementation truncates
  to 32 bits and sign-extends bit 31 exactly for 64-bit operations, matching an
  independent `BitVec.setWidth`/`signExtend` specification. This is encoded-field
  decoding, not a proof of objdump text parsing or native instruction bytes.
- `6eb9514a7`, `67228f0f5`, `d8f70ae60`, and `69ad8f71f` compose that decoded
  immediate through register-destination ADD/ADC/SUB/SBB lane reads, generated
  results and flags, lane writeback, and tag scalarization. ADC and SBB capture
  one pre-state CF and use it consistently in both result and flags. The SBB
  boundary `0 - (-1) - 1` retains CF=true even though the effective
  subtrahend wraps to zero.
- `e30f088f9` and `5f937a7f2` compose the same immediate decode through CMP
  subtraction flags and TEST logic flags. Both prove preservation of the
  complete destination bits and tag; targeted theorems cover 64-bit signed
  immediate comparison and high-byte TEST.

Every proof state passed the full `make -C native-sim/formal check`, including
all generated-source freshness checks and the complete Lean build. The C
contract state additionally passed `make -C native-sim/x86 micro-proofs-build`:
the preserved negative artifact and all 29 workload-derived artifacts built.
Textual probes for `inc ah`, `dec ah`, and `neg ah` selected RAX, width 8,
destination shift 8, and the intended ALU opcode. Independent read-only review
found no blocking issue in the final form of each increment. Existing workload
artifacts contain no high-byte INC/DEC/NEG, so the 29/29 build is integration
evidence rather than dynamic execution of those newly enabled encoder cases.
No KVM run or performance experiment was repeated in this proof-only sequence.

The next highest-value boundary is still selection and language refinement:
prove the objdump/parser/operand/AUX path selects these typed handlers, then
relate generated C unsigned operations and compiler/native bytes to the Lean
model. Immediate AND/OR/XOR/shift/IMUL paths, other high-byte extend/shift/load
forms, memory lanes and stores, helpers, multi-step traces, specialization
preservation, and AArch64 flag production also remain open. These commits do
not establish complete native-byte semantic equivalence.

### Logical-immediate handler refinement (AND/OR/XOR + SHL/ROL examples), 2026-09-11

- New section in `KProgFormal/X86AluWriteback.lean` (file now ~892 lines):
  `generatedX86AndImmLaneHandler` / `x86AndImmLaneHandlerSpec` +
  `x86_and_imm_lane_handler_refines`, and the matching OR and XOR pairs.
  Each generated handler composes the generated register-lane read
  (`GeneratedX86RegRead.readAt`), the generated immediate decode
  (`GeneratedX86Immediate.value`, i.e. 32-bit truncation with 64-bit
  sign-extension), the bitwise result, the generated lane writeback
  (`generatedX86RegWriteAt`), the generated logic-flag transition
  (`generatedX86LogicFlags`), and the generated zero/sign observations
  (`GeneratedX86Width.zero`/`.sign`). Each refine theorem ties the
  generated composition to an independently written spec using only the
  shared per-piece refine lemmas
  (`x86_reg_read_at_refines`, `x86_immediate_value_refines`,
  `x86_zero_refines`, `x86_sign_refines`, `x86_logic_flags_refine`,
  `x86_reg_write_at_refines`).
- Five counterexample theorems (`native_decide` on the generated handler):
  high-byte AND `0xff & 0x0f` on `...ff00` → `...0f00`, all logic flags
  cleared; high-byte OR `0x00 | 0x80` on `...00ff` → `...80ff` with
  SF=true; 64-bit XOR of `0x55555555` with the sign-extended immediate
  `0xffffffff` → `0xffffffffaaaaaaaa`, SF=true; 64-bit SHL of `1` by the
  96-bit immediate (count masks to 32) → `0x100000000`; and high-byte ROL
  of `0x01` by 2 → `0x04` with the rotate flag transition preserving
  ZF/SF and keeping OF at its old value for masked count ≠ 1.
- Verification: full `make -C native-sim/formal check` passed (freshness +
  complete Lean build, ~33 s). The step is Lean-only (no C diff), but as
  integration insurance `make -C native-sim/x86 micro-proofs-build` was
  re-run with the host clang at `/usr/lib/llvm-18/bin` (not on default
  PATH): negative artifact + all 29 workload-derived artifacts built.
- `native-sim/formal/README.md` gains the matching paragraph after the
  arithmetic-immediate composition paragraph.
- These theorems do not establish objdump/text-parsing or
  native-byte-level equivalence; they close the immediate-form AND/OR/XOR
  handler-composition gap and pin the shift flag-preservation examples.

### Register-register logical handler refinement, 2026-09-11

- `KProgFormal/X86AluWriteback.lean` gains `generatedX86AndRegLaneHandler` /
  `x86AndRegLaneHandlerSpec` + `x86_and_reg_lane_handler_refines`, and the
  matching OR and XOR pairs. Each composes the two generated register-lane
  reads (destination lane and source register lane), the `BitVec`
  binary connective, the generated lane writeback, and the generated
  logic-flag transition (CF=OF=0, ZF/SF from the width-narrowed result);
  each refines the independent specification via the shared per-piece
  refine lemmas. This mirrors the C `X86_SIM_L_EXEC_ALU_REG` generic
  branch, which supplies the second operand from the source register lane
  rather than a raw immediate artifact field.
- Concrete counterexample theorems (`native_decide`): high-byte AND of
  `0xff` with `0x0f` → `0x0f`, high-byte OR of `0x00` with `0x80` →
  `0x80` setting the width sign bit, and 64-bit XOR of `0x123456` with
  `0x765432` → `0x646064`.
- Verification: full `make -C native-sim/formal check` passed
  (freshness + complete Lean build, ~34 s). Lean-only step (no C/JSON
  diff); as integration insurance `make -C native-sim/x86
  micro-proofs-build` was re-run with the host clang at
  `/usr/lib/llvm-18/bin`: negative artifact + all 29 workload-derived
  artifacts built.
- `native-sim/formal/README.md` gains the matching register-register
  paragraph after the logical-immediate one.
- Open x86 boundary after this increment: register-register shift
  handlers (second lane read feeding the count), IMUL immediate, memory
  lanes and stores, the objdump/parser-to-AUX selection relation, C-to-Lean
  unsigned-semantics correspondence, and AArch64 flag production. These
  theorems do not establish native-byte equivalence.

### Carry-sensitive handler classification (SBB/ADC), 2026-09-11

- `x86_alu_decode_spec.json` gains a per-opcode `handler` field: `.sbb` and
  `.adc` map to their own carry-sensitive handler classes; all other ALU
  ops are `.generic`. `generate_x86_alu_decode_spec.py` now validates the
  field, emits a generated `Handler` inductive (`generic | sbb | adc`) plus
  `handlerForCode : BitVec 32 -> Handler` in the Lean side and two C
  predicates `KPROG_X86_ALU_USES_{SBB,ADC}_HANDLER` in
  `generated/x86_alu_decode.h`, and the generator's `--check` target stays
  green.
- `KProgFormal/X86AluDecode.lean` composes the classification against the
  typed register-lane AUX: `x86_alu_handler_refines` proves the generated
  handler function refines the independent operation mapping, and
  `x86_alu_aux_handler_refines` proves packing a typed ALU code into the
  AUX and extracting its payload selects the same handler via the committed
  `x86_reg_lane_aux_payload_roundtrip`.
- `native-sim/x86/x86_sim_local_bpf.h` routes its four SBB/ADC sites
  (immediate, register, memory, and the ADD-flag shared paths) through the
  generated predicates instead of open-coded `== X86_ALU_SBB/ADC` compares;
  behaviour is unchanged, the C now derives handler selection from the
  same artifact as the Lean side.
- Verification: full `make -C native-sim/formal check` passed (freshness +
  complete Lean build, ~30 s) and `make -C native-sim/x86
  micro-proofs-build` passed with host clang at `/usr/lib/llvm-18/bin`
  (negative artifact + all 29 workload-derived artifacts).
- This increment is a carried-over WIP from an interrupted run of this
  session chain (stale 08:31 git lock); it was re-verified end-to-end and
  completed here. These theorems do not establish native-byte or
  C-to-Lean unsigned-semantics equivalence; they bind the typed AUX
  payload to handler class.

### Track negative-proof micro-prog fixtures, 2026-09-11

- `native-sim/x86/micro-prog/unchecked_packet_read.bpf.c` and
  `native-sim/arm64/micro-prog/unchecked_packet_read.bpf.c` were untracked
  while every one of the 29 workload-derived siblings in each `micro-prog/`
  is tracked. `run_micro_sim_batch.py` (`source_dir = <arch>/micro-prog`,
  `src = config.source_dir / f"{bench.name}.bpf.c"`) consumes these as
  hand-authored source for the `kprog_negative_stage2` suite, and both
  arch `Makefile`s set `NEGATIVE_PROGRAM := unchecked_packet_read`; the
  tracked home `native-sim/test/unchecked_packet_read.bpf.c` (added by
  `179119708`, which wired the micro-prog negative build) was committed
  without the two arch copies. A fresh clone would therefore break
  `kprog-negative-proof-build` (the target this chain uses as build
  insurance). These are hand-authored fixtures (not generator output, not
  build artifacts, not gitignored), so they are tracked here.
- Both copies carry the correct arch-local include
  (`../x86_sim_local_bpf.h` / `../arm64_sim_local_bpf.h`) and are distinct
  per-arch programs. They were already proven functional by this session's
  two `make -C native-sim/x86 micro-proofs-build` runs (each exercised
  `kprog-negative-proof-build` end-to-end, exit 0).

### Register-register shift handler refinement, 2026-09-11

- `KProgFormal/X86AluWriteback.lean` gains `generatedX86ShiftRegLaneHandler`
  / `x86ShiftRegLaneHandlerSpec` + one `x86_*_reg_lane_handler_refines`
  theorem for each of SHL, SHR, SAR, ROL. Each composes the two generated
  register-lane reads (destination lane and source register lane, the
  latter supplying the shift count), the `GeneratedX86ShiftResult`
  transition, the generated lane writeback with tag scalarization, and the
  generated shift-flag transition seeded with the pre-state flags; each
  refines the independent specification via the shared per-piece refine
  lemmas (`x86_reg_read_at_refines` applied to both lane reads, the
  matching `x86_shl|shr|sar|rol_result_refines`, and
  `x86_reg_write_at_refines`). The flag field is shared verbatim between
  generated handler and spec (`generatedX86ShiftFlags` on the spec values),
  mirroring the immediate form; the op-parametric
  `x86_shift_imm_flags_defined` already establishes the architectural
  shift-flag definedness contract for these operands. This mirrors the C
  `X86_SIM_L_EXEC_ALU_REG` generic branch, which routes shift ALUs through
  `x86_alu_result` -> `kprog_x86_shl|shr|sar|rol_result` and
  `X86_SIM_L_SET_SHIFT_FLAGS`; Lean-only increment, no C/JSON diff.
- Concrete counterexample theorems (`native_decide`): high-byte SHL of
  `0x01` by the high-byte count `0x03` -> `0x08` (all flags false), and
  high-byte SAR of `0x80` by the high-byte count `0x01` -> `0xC0`
  sign-fill (SF set, OF false).
- Verification: full `make -C native-sim/formal check` passed
  (freshness + complete Lean build, ~33 s). As integration insurance
  `make -C native-sim/x86 run` was re-run after installing host clang 18:
  the BPF object builds and the loader loads `x86_sim_hardcoded_xdp`
  (fd=4).
- `native-sim/formal/README.md` gains the matching register-register shift
  paragraph after the register-register logical one.
- Open x86 boundary after this increment: IMUL (register-register and
  immediate), memory lanes and stores, the objdump/parser-to-AUX
  selection relation, C-to-Lean unsigned-semantics correspondence, and
  AArch64 flag production. These theorems do not establish native-byte
  equivalence.

### x86 IMUL immediate and register-register handler refinement, 2026-09-13

- Shared contract: `native-sim/formal/x86_imul_flags_spec.json` (unchanged)
  generates `KProgFormal/GeneratedX86ImulFlags.lean` and
  `generated/x86_imul_flags.h` via `generate_x86_imul_flags_spec.py`.
  `GeneratedX86ImulFlags.signedAbs` expresses the width-narrowed signed
  magnitude; `mixedSign` expresses the operand sign mismatch; `apply` fixes
  `limit = signMask` for mixed signs else `signMask - 1` and
  `overflow = aAbs != 0 && bAbs > limit / aAbs` (64-bit guarded division),
  with `cf = of = overflow` and ZF/SF preserved.
- Fixes the three prior defects: the generated Lean called nonexistent
  `GeneratedX86Width.signedAbs`/`mixedSign` (now local to the generated
  module), `limit` used `BitVec.not sign` instead of `sign - 1`, and the
  generated C macro carried a spurious `a_abs < b_abs` conjunct. The Lean
  render now uses fully-qualified `BitVec.and`/`BitVec.not` (the `&`/`~`
  infix forms fail to parse) so the generated module compiles.
- `KProgFormal/X86ImulFlags.lean` (new bridge): `x86SignedAbsSpec`,
  `x86ImulOverflowSpec`, `x86ImulFlagsApplied`, `generatedX86ImulFlags`,
  theorem `x86_imul_flags_defined` (independent overflow spec equals the
  generated `apply`), theorem `x86_imul_flags_apply_refines`, and two
  `native_decide` boundary theorems (`0x7fff * 2` w16 overflows, `-128 * 1`
  w8 does not). No `sorry`.
- `KProgFormal/X86AluWriteback.lean` gains
  `generatedX86ImulImmLaneHandler` / `x86ImulImmLaneHandlerSpec` +
  `x86_imul_imm_lane_handler_refines`, and
  `generatedX86ImulRegLaneHandler` / `x86ImulRegLaneHandlerSpec` +
  `x86_imul_reg_lane_handler_refines`. Each composes the lane read(s), the
  decoded immediate (or the second register lane), the 64-bit product, the
  generated IMUL flags, and the lane writeback with tag scalarization; the
  refine proofs use `x86_reg_read_at_refines`, `x86_immediate_value_refines`,
  `x86_reg_write_at_refines`, and `x86_imul_flags_apply_refines`. Concrete
  `native_decide` examples pin the w16/w8 overflow and in-range cases.
- `native-sim/x86/x86_sim_local_bpf.h`: adds the generated-header include and
  rewrites `X86_SIM_L_SET_IMUL_FLAGS` to the house delegation pattern
  (compute the same locals, then call `KPROG_X86_SET_IMUL_FLAGS`), mirroring
  the SBB/shift macros above it. Behavior-preserving; all three call sites
  (register, immediate, memory-immediate) route through the generated macro.
- Host cross-check `native-sim/formal/test_imul_flags_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it
  against an independent `__int128` signed-product range oracle over 15
  explicit boundary vectors plus a fixed-seed (0x12345678) 20000-case sweep
  across all four widths. Result: `OK (15 vectors + 20000 sweep cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line + `lake build` + new `lake env lean KProgFormal/X86ImulFlags.lean`
  line; ~26 s). `make -C native-sim/x86 build` produces the BPF object from
  `x86_sim_hardcoded.bpf.c` (which includes the changed header); the same
  translation unit also compiles natively. `make -C native-sim/x86
  micro-proofs-build` rebuilds the negative artifact and all 29
  workload-derived artifacts, all `ok`.
- Open x86 boundary after this increment: memory lanes and stores, the
  objdump/parser-to-AUX selection relation, C-to-Lean unsigned-semantics
  correspondence, and AArch64 flag production. These theorems do not
  establish native-byte equivalence.

### x86 little-endian memory access refinement, 2026-09-13

- Gap: the central C memory primitives `X86_SIM_L_LOAD_ADDR` (hand-written
  byte ladder using `if (w >= X86_WIDTH_32)` fall-through) and
  `X86_SIM_L_STORE_ADDR` (typed `__u16`/`__u32`/`__u64` casts) had no shared
  source with a proof contract, and the earlier unary/ALU ledger listed
  "memory access/store" as an open boundary.
- Generator: `native-sim/formal/generate_x86_mem_access_spec.py` reads
  `x86_mem_access_spec.json` (widths 8/16/32/64 with per-width byte lists) and
  emits `native-sim/formal/generated/x86_mem_access.h`
  (`KPROG_X86_MEM_LOAD(ADDR, WIDTH)`, `KPROG_X86_MEM_STORE(ADDR, WIDTH, VALUE)`)
  and `native-sim/formal/KProgFormal/GeneratedX86MemAccess.lean`
  (`assemble`/`load`/`storeByte`/`store`/`byteCount` over
  `GeneratedX86Width.Width`). `--check` diffing plus a `make check` line keep
  the outputs fresh.
- C wiring: `native-sim/x86/x86_sim_local_bpf.h` includes the generated header
  and now defines `X86_SIM_L_LOAD_ADDR`/`X86_SIM_L_STORE_ADDR` as direct
  delegations to the generated macros, so sim C and the proof contract share
  one forwarded source. Semantics are unchanged for the four legal widths
  (byte-wise little-endian load; byte-wise store replacing the typed casts,
  bit-identical on little-endian and now endian-explicit).
- Lean bridge: `native-sim/formal/KProgFormal/X86MemAccess.lean` proves
  `x86_mem_assemble_refines` (generated `assemble` = independent little-endian
  byte-sum spec), `x86_mem_load_refines` (generated `load` = byte-sum narrowed
  by the mask, via the width-mask bridge), `x86_mem_store_byte_refines`
  (generated `storeByte` = independent width-masked extraction), and
  `x86_mem_byte_count`; concrete example theorems pin known encodings. No
  `sorry`/`admit`.
- Host cross-check `native-sim/formal/test_mem_access_host.c`: compiles the
  generated macros with zero warnings under `-Wall -Wextra` and compares them
  against an independent byte-level load/store oracle over 5 explicit boundary
  vectors x 4 widths plus a fixed-seed (0x12345678) 20000-case sweep over all
  widths (load and store each). Result: `OK (40020 cases)`; a deliberately
  broken oracle (`8*i+1`) fails, so the check is real.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line + new `lake env lean KProgFormal/X86MemAccess.lean` line + the
  host cross-check step; ~26 s). `make -C native-sim/x86 build` produces the
  BPF object from `x86_sim_hardcoded.bpf.c` (which includes the changed header)
  and the same translation unit compiles natively. `make -C native-sim/x86 run`
  loads the object (`load-only`, fd=4). `make -C native-sim/x86
  kprog-negative-proof-build` rebuilds the negative artifact, `ok`.
- Open x86 boundary after this increment: decoder selection of the access
  width, operand-form selection into the load/store handlers, the
  objdump/parser-to-AUX selection relation, C-to-Lean unsigned-semantics
  correspondence, and AArch64 flag production. These theorems do not
  establish native-byte equivalence.

### AArch64 width and NZCV flag refinement, 2026-09-13

- Gap: the central ARM64 flag setters `ARM64_SIM_L_SET_ADD_FLAGS`,
  `ARM64_SIM_L_SET_SUB_FLAGS`, and `ARM64_SIM_L_SET_LOGIC_FLAGS` were
  hand-written with no shared source or proof contract, and every recent
  increment ledger listed "AArch64 flag production" as an open boundary. The
  `arm64_width_mask`/`arm64_width_bits`/`arm64_sign_bit`/`arm64_apply_width`
  helpers were likewise hand-written.
- Generators: `native-sim/formal/generate_arm64_width_spec.py` reads
  `arm64_width_spec.json` and emits `generated/arm64_width.h`
  (`KPROG_ARM64_WIDTH_MASK`/`_SIGN_MASK`/`_BITS`, `KPROG_ARM64_APPLY_WIDTH`)
  plus `KProgFormal/GeneratedArm64Width.lean`;
  `native-sim/formal/generate_arm64_flags_spec.py` reads
  `arm64_flags_spec.json` and emits `generated/arm64_flags.h`
  (`KPROG_ARM64_SET_{ADD,SUB,LOGIC}_FLAGS`) plus
  `KProgFormal/GeneratedArm64Flags.lean` (`applyAdd`/`applySub`/`applyLogic`).
  Both have `--check` modes and `make check` lines.
- C wiring: `native-sim/arm64/arm64_sim.h` includes the generated width header
  and its four helpers now delegate to the generated macros;
  `native-sim/arm64/arm64_sim_local_bpf.h` includes the generated flags header
  and the three `ARM64_SIM_L_SET_*_FLAGS` macros now delegate to
  `KPROG_ARM64_SET_*_FLAGS`. Behavior is unchanged: ADD C is the unsigned
  carry-out, SUB C is not-borrow (`lhs >= rhs`), logical clears C/V, N/Z from
  the width-narrowed result, V from the sign-consistent overflow observation.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64Flags.lean` proves
  `arm64_add_flags_refines`, `arm64_sub_flags_refines`, and
  `arm64_logic_flags_refines` equal to an independently written `Arm64NzcSpec`
  statement over already width-narrowed operands, plus canonical example
  theorems: `0xffffffffffffffff + 1` w64 (C and Z set), `0 - 0` (C set),
  `0x7fffffff + 1` w32 (V and N set, no carry-out), `1 - 2` (borrow), and a
  logical result that clears C/V. No `sorry`/`admit`. The three generated
  modules plus the bridge are in the `KProgFormal.lean` root import list.
- Host cross-check `native-sim/formal/test_arm64_flags_host.c`: compiles the
  generated macros with zero warnings under `-Wall -Wextra` and compares them
  against an independent `__int128` carry/overflow oracle over 12 explicit
  boundary vectors x 4 widths x {add, sub, logic} plus a fixed-seed
  (0x12345678) 20000-case sweep. Result: `OK (60144 cases)`. An oracle
  regression (changing SUB C from `>=` to `>`) fails 8 vector cases, so the
  check is real. (Two oracle bugs were found and fixed during bring-up: a
  `__u64`-width shift before widening, and an incorrect sign extension; the
  generated macro was correct throughout.)
- Verification: full `make -C native-sim/formal check` green (two new generator
  `--check` lines, the `Arm64Flags.lean` lean line, and the arm64 host
  cross-check step; ~28 s). `make -C native-sim/arm64 build` produces the BPF
  object from `arm64_sim_hardcoded.bpf.c` (which includes the changed headers)
  and `make -C native-sim/arm64 run` loads it (`load-only`, fd=4).
  `make -C native-sim/arm64 micro-proofs-build` rebuilds all 30
  workload-derived artifacts, all `ok`.
- Open AArch64 boundary after this increment: instruction decode into the
  flag-setting handlers, `MADD`/`MSUB`/`UMULH` flag consequences if any,
  condition-to-next-PC beyond the earlier condition contract, and native bytes.
  These theorems do not establish native-byte equivalence.

### AArch64 instruction-decode table refinement, 2026-09-13

- Gap: the AArch64 ALU/shift/modifier/bitfield mnemonic-to-code mapping lived in
  three independent hand-written copies - the `ARM64_ALU_*`/`ARM64_SHIFT_*`/
  `ARM64_MOD_*`/`ARM64_BITFIELD_*` `#define`s in `native-sim/arm64/arm64_sim.h`
  and the `ALU`/`SHIFT`/`MOD`/`BITFIELD` dicts in the arm64 proof generator -
  with no shared source or proof contract. The previous increment's open
  AArch64 boundary named "instruction decode into the flag-setting handlers".
- Generator: `native-sim/formal/generate_arm64_decode_spec.py` reads
  `arm64_decode_spec.json` and emits the shared contract in four forms:
  `generated/arm64_decode.h` (`ARM64_ALU_*`/`ARM64_SHIFT_*`/`ARM64_MOD_*`/
  `ARM64_BITFIELD_*`), `KProgFormal/GeneratedArm64Decode.lean` (four
  `inductive`+`code`/`mnemonic` modules), and
  `native-sim/arm64/micro-prog/generated_arm64_decode.py` (the four dicts). It
  has a `--check` mode and a `make check` line.
- C wiring: `native-sim/arm64/arm64_sim.h` now `#include`s the generated header
  instead of the 29 hand-written `#define`s. Behavior is unchanged: the same
  numeric codes feed `ARM64_SIM_L_EXEC_ALU`, the shift handler, and the
  bitfield handler. Python: the generator imports the four dicts from the
  generated module at the top of the file rather than re-declaring them.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64Decode.lean` states four
  independent mnemonic/code enumerations and proves each generated table equal
  to it (`arm64_alu_decode_refines`, `arm64_shift_decode_refines`,
  `arm64_mod_decode_refines`, `arm64_bitfield_decode_refines`) plus
  `arm64_alu_codes_distinct`, all by `native_decide`. No `sorry`/`admit`. Both
  new modules are in the `KProgFormal.lean` root import list and the bridge has
  a `lean` line in the Makefile.
- Verification: full `make -C native-sim/formal check` green (generator
  `--check` line, generated module build, `Arm64Decode.lean` line; ~40 s).
  `make -C native-sim/arm64 micro-proofs-build` rebuilds all 30
  workload-derived artifacts against the changed header, all `ok`, no failures.
  Committed and pushed as `970b5ac04`.
- Open AArch64 boundary after this increment: the register-lane ALU handler
  composition (`ARM64_SIM_L_EXEC_ALU` value/flags/writeback plus its
  `ARM64_SIM_L_MOD_VALUE` source-modifier path), bitfield/extract/rev handler
  compositions, `MADD`/`MSUB`/`UMULH` flag consequences if any,
  condition-to-next-PC beyond the earlier condition contract, and native bytes.
  These theorems do not establish native-byte equivalence.

### AArch64 ALU op-step result refinement, 2026-09-13

- Gap: the six ALU result formulas (add/sub/and/bic/eor/orr) were hand-written
  in the value half of the flag-setting handlers and in `ARM64_SIM_L_EXEC_ALU`,
  with no shared source or proof contract, while the value half and the flag
  half of `SUBS`/`ADDS`/`ANDS`/`TST`/`BICS` were produced by two independent
  expression copies. The previous increment's open AArch64 boundary named "the
  register-lane ALU handler composition".
- Generator: `native-sim/formal/generate_arm64_alu_result_spec.py` reads
  `arm64_alu_result_spec.json` and emits the shared op-step result contract in
  two forms: `generated/arm64_alu_result.h` (`KPROG_ALU64_RESULT(OP, LHS, RHS,
  UNSUPPORTED)`, a statement expression switching on the numeric codes
  `0U..5U`, with `default: UNSUPPORTED`) and
  `KProgFormal/GeneratedArm64AluResult.lean` (`result : Alu -> BitVec 64 ->
  BitVec 64 -> BitVec 64`). `load()` re-reads `arm64_decode_spec.json` and
  exits 1 if the six mnemonic/code pairs drift from the ALU table, so the
  emitted numeric case labels cannot silently diverge from the generated
  `arm64_decode.h` `ARM64_ALU_*` constants. It has a `--check` mode and a
  `make check` line.
- C wiring: `native-sim/arm64/arm64_sim_local_bpf.h` includes the generated
  header. `ARM64_SIM_L_EXEC_ALU` computes `__a64_alu_result` through
  `KPROG_ALU64_RESULT`; the `SUBS`/`ADDS`/`TST`/`TST_BIC`/`BICS`/`ANDS`
  handlers compute their result through the same macro, so their value and
  flags now derive from one contract. Behavior is unchanged. The 64-bit ADD
  pointer-tag fast path in `ARM64_SIM_L_EXEC_ALU` is untouched (tagged ADD never
  uses the scalar result), and `ORN_REG` plus the flags-only `CMN`/`CMP` remain
  as before (`ORN` is not one of the six table operations).
- Lean bridge: `native-sim/formal/KProgFormal/Arm64AluResult.lean` proves
  `arm64_alu_result_refines` (the generated `result` equals an independently
  written `arm64AluResultSpec` whose SUB is stated as add-of-two's-complement
  and whose BIC uses an explicit complement mask), `arm64_alu_result_code_in_range`
  and `arm64_alu_result_code_dispatch` (the six codes are exactly the macro's
  case labels), `arm64_alu_result_narrow_refines` (64-bit result then narrowed is
  the operation on width-narrowed operands narrowed again - what the C writeback
  relies on), and the composition theorems `arm64_add_step_refines`,
  `arm64_sub_step_refines`, `arm64_logic_step_refines` that pair the result with
  the existing independent `arm64AddNzc`/`arm64SubNzc`/`arm64LogicNzc`
  statements. Canonical examples: `1 - 2` w64 borrow (value all-ones, C clear, N
  set), BIC `0xff & ~0x0f`, EOR self (zero, Z set), ORR (C/V clear), and
  `0xffffffffffffffff + 1` w64 (wrap to zero, C and Z set). No `sorry`/`admit`.
  Both new modules are in the `KProgFormal.lean` root import list and the bridge
  has a `lean` line in the Makefile.
- Host cross-check `native-sim/formal/test_arm64_alu_result_host.c`: compiles
  the generated macro with zero warnings under `-Wall -Wextra` and compares it
  against an independent oracle over 12 explicit boundary vectors x 6 ops plus a
  fixed-seed 20000-iteration sweep x 6 ops, and forks a child that evaluates the
  macro with an unsupported code and an `abort()` argument, requiring
  `WIFSIGNALED && WTERMSIG == SIGABRT` so the `default` branch cannot silently
  return zero. Result: `OK (120073 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, `Arm64AluResult.lean` lean line, and the arm64 alu-result host
  cross-check step; ~33 s), including the pre-existing `arm64 flag host
  cross-check: OK (60144 cases)` and `x86 memory-access host cross-check: OK
  (40020 cases)`. `make -C native-sim/arm64 build` produces the BPF object from
  `arm64_sim_hardcoded.bpf.c` (which includes the changed header) and `make -C
  native-sim/arm64 run` loads it (`load-only`, fd=4). `make -C
  native-sim/arm64 micro-proofs-build` rebuilds all 30 workload-derived
  artifacts, all `ok`.
- Open AArch64 boundary after this increment: the source-modifier composition
  (`ARM64_SIM_L_MOD_VALUE` feeding `EXEC_ALU`/`SUBS`/`ADDS`/`ANDS`), the
  bitfield/extract/rev handler compositions, `MADD`/`MSUB`/`UMULH` flag
  consequences if any, condition-to-next-PC beyond the earlier condition
  contract, and native bytes. These theorems do not establish native-byte
  equivalence, and the Lean result contract is stated over `BitVec 64` while the
  C macro operates on `__u64`; the host cross-check bridges that C/Lean
  semantics gap for the tested vectors only.

### AArch64 source-modifier value refinement, 2026-09-14

- Gap: the eleven source-modifier arms (no-op, LSL, LSR, ASR, ROR, UXTW, SXTW,
  UXTH, SXTH, UXTB, SXTB) were a hand-written if/else-if chain inside
  `ARM64_SIM_L_MOD_VALUE`, consumed by eleven call sites (the memory base-offset
  path, the `EXEC_ALU` rhs, and the `SUBS`/`ADDS`/`CMN`/`CMP`/`TST`/`TST_BIC`/
  `BICS`/`ANDS`/`ORN` register-operand paths). The chain had no shared source
  and no proof contract, and its shift-amount masking and rotate guards were
  restated separately in the `arm64_lsl`/`arm64_lsr`/`arm64_asr`/`arm64_ror`
  helpers. The previous increment's open AArch64 boundary named exactly this
  source-modifier composition.
- Generator: `native-sim/formal/generate_arm64_mod_spec.py` reads
  `arm64_mod_spec.json` and emits the shared modifier contract in two forms:
  `generated/arm64_mod.h` (`KPROG_ARM64_MOD_VALUE(MOD, VALUE, SHIFT, WIDTH)`, a
  statement expression switching on the numeric codes `0U..10U`, with no
  `default` and no unsupported arm) and
  `KProgFormal/GeneratedArm64Mod.lean` (`value : Mod -> BitVec 64 -> BitVec 64
  -> Width -> BitVec 64`). `load()` re-reads `arm64_decode_spec.json` and exits
  1 if the eleven mnemonic/code pairs drift from the modifier table, so the
  emitted numeric case labels cannot silently diverge from the generated
  `arm64_decode.h` `ARM64_MOD_*` constants (which the emitted `_Static_assert`s
  pin). The generated header also emits `KPROG_ARM64_MOD_HANDLED(MOD)` plus one
  coverage assert per code, so a modifier added to the table without an arm is a
  compile error rather than a runtime fallthrough. It has a `--check` mode and a
  `make check` line.
- C wiring: `native-sim/arm64/arm64_sim_local_bpf.h` includes the generated
  header and `ARM64_SIM_L_MOD_VALUE` now delegates to
  `KPROG_ARM64_MOD_VALUE((MOD), ARM64_SIM_L_READ_REG(REG), (SHIFT), (WIDTH))`,
  preserving the `({ … })` statement-expression shape and evaluating
  `ARM64_SIM_L_READ_REG` exactly once (as the old chain did). Behavior is
  unchanged: the same eleven arms, the same `(WIDTH) == ARM64_WIDTH_32 ? 31 : 63`
  amount mask, and the same `amount == 0` rotate guards. The helpers
  `arm64_lsl`/`arm64_lsr`/`arm64_asr`/`arm64_ror` stay live for the distinct
  `ARM64_SHIFT_*` `ARG` path and for other callers, so they were not rerouted.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64Mod.lean` proves
  `arm64_mod_refines` (the generated `value` equals an independently written
  `arm64ModValueSpec` that restates the shift arms through `narrow`, the
  sign-extending arms as a masked complement-and-subtract, the unsigned-extending
  arms as a shift pair, and the rotate on a narrowed operand in the rotation
  domain selected by the width code), `arm64_mod_code_in_range` (all eleven codes
  are inside the macro's case range, so no unsupported arm is needed),
  `arm64_mod_code_dispatch`, `arm64_mod_shift_magnitude` (the `__u8` shift field's
  zero extension is the 64-bit shift vector, with magnitude `shift.toNat`),
  `arm64_mod_shift_amount_masked` (the four shift arms depend on the shift only
  through its masked low bits, which is how the C macro computes the amount),
  `arm64_mod_extend_shift_refines` (the six extend arms truncate/sign-extend then
  apply the raw shift field), and `arm64_mod_fed_alu_refines` (the modifier result
  feeding the generated ALU op-step result equals the independent modifier
  statement feeding the independent ALU statement). Canonical examples: UXTB of
  `0x1ff` is `0xff`, SXTB of `0x80` is `0xffffffffffffff80`, zero-shift SXTW of
  `0xffffffff` is all ones, `w32` LSL of `1` by `32` is `1` while the `w64` form
  is `4294967296` (the amount mask), `w64` ROR of `0x0102030405060708` by 8 is
  `0x0801020304050607`, and the identity arm is untouched. No `sorry`/`admit`.
  Both new modules are in the `KProgFormal.lean` root import list and the bridge
  has a `lean` line in the Makefile.
- Lesson learned (two defects the earlier probe caught, both fixed here): the
  rotate arm must not mask its rotate distance. C's `arm64_ror32`/`arm64_ror64`
  guard `amount == 0` and then compute `32 - amount` / `64 - amount`, which lies
  in `[1,31]`/`[1,63]`; an `&&& 31`/`&&& 63` form of the rotate distance is wrong
  and produced a spurious counterexample (`value = shift = 0xffff...ff`). Second,
  the rotate domain is 32 bits exactly for `.w32` and 64 bits otherwise
  (`arm64_ror` dispatches on `ARM64_WIDTH_32` only), so modelling it with
  `bits width` is wrong for `.w8`/`.w16`; the spec keys the domain on
  `width = .w32`. A third modelling constraint: the shift amount is a `BitVec 64`
  (C's `__u8` field zero-extended), because `BitVec 8` amounts prevent the reifier
  from synthesizing the shift identities and it abstracts the operands instead.
- Host cross-check `native-sim/formal/test_arm64_mod_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it
  against an independent oracle (plain C shifts, the C rotate form with its
  `amount == 0` guard, and truncating/sign-extending casts) over 15 boundary
  values x 11 modifiers x 8 boundary shifts x 4 widths, plus a fixed-seed
  20000-iteration sweep, plus a check that `KPROG_ARM64_MOD_HANDLED` accepts
  exactly the eleven modifier codes and rejects code 11. Result: `OK (225292
  cases)`. The extend arms are swept only over the architectural shift domain
  (`shift < 64`) because C `<<` is undefined above that.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, `Arm64Mod.lean` lean line, and the arm64 mod host cross-check
  step; ~43 s), alongside the arm64 flags (`OK (60144 cases)`), arm64 ALU result
  (`OK (120073 cases)`), and x86 memory-access (`OK (40020 cases)`) cross-checks.
  Mutation checks: changing a modifier code in `arm64_mod_spec.json` makes
  `--check` exit 1; five independent semantic mutations of
  `generated/arm64_mod.h` (the 64-bit shift-amount mask, the LSL width mask, the
  SXTB sign-extension source, the 32-bit rotate domain, and the 64-bit rotate
  distance) each make the host cross-check exit 1 with a printed mismatch.
  `make -C native-sim/arm64 micro-proofs-build` rebuilds all 30 workload-derived
  artifacts, all `ok`; `make -C native-sim/arm64 build` produces the BPF object
  from `arm64_sim_hardcoded.bpf.c` (which includes the changed header) and `make
  -C native-sim/arm64 run` loads it (`load-only`, fd=4).
- Open AArch64 boundary after this increment: the bitfield/extract/rev handler
  compositions (`ARM64_SIM_L_BITFIELD_*`, the `UBFX`/`SBFX`/`UBFIZ`/`BFXIL`/`BFI`
  decode table already exists), `MADD`/`MSUB`/`UMULH` flag consequences if any,
  condition-to-next-PC beyond the earlier condition contract, and native bytes.
  These theorems do not establish native-byte equivalence, and the Lean modifier
  contract is stated over `BitVec 64` while the C macro operates on `__u64`; the
  host cross-check bridges that C/Lean semantics gap for the tested vectors only.

### AArch64 bitfield-composition refinement, 2026-09-15

- Gap: the five bitfield arms (UBFX, SBFX, UBFIZ, BFXIL, BFI) were a
  hand-written if/else-if chain inside the `ARM64_OP_BITFIELD` handler in
  `ARM64_SIM_L_EXEC_ALU`, computing `arm64_bits_mask`/`arm64_sign_extend`
  locally, reading `ARM64_SIM_L_READ_REG(DST)` twice, and carrying its own
  `lsb >= 64` guards. Those guards are unreachable under the architectural
  domain but were restated independently of the decode table's bitfield codes.
  The previous increment's open AArch64 boundary named exactly this bitfield
  composition.
- Generator: `native-sim/formal/generate_arm64_bitfield_spec.py` reads
  `arm64_bitfield_spec.json` and emits the shared contract in two forms:
  `generated/arm64_bitfield.h` (`KPROG_ARM64_BITFIELD_VALUE(KIND, SRC, DST, LSB,
  BITS, UNSUPPORTED)`, a statement expression switching on the numeric codes
  `0U..4U` with an explicit `default: UNSUPPORTED; break;`) and
  `KProgFormal/GeneratedArm64Bitfield.lean` (`value : Bitfield -> BitVec 64 ->
  BitVec 64 -> BitVec 8 -> BitVec 8 -> BitVec 64`, reusing the existing
  `GeneratedArm64BitfieldDecode.Bitfield` inductive rather than redeclaring it).
  `load()` re-reads `arm64_decode_spec.json` and exits 1 if the five
  mnemonic/macro/code triples drift from the decode table's `tables.bitfield`
  rows, so the emitted numeric case labels cannot silently diverge from the
  generated `arm64_decode.h` `ARM64_BITFIELD_*` constants (which the emitted
  `_Static_assert`s pin). It also emits `KPROG_ARM64_BITFIELD_HANDLED(KIND)` plus
  one coverage assert per code, so a kind added to the table without an arm is a
  compile error instead of a silent fallthrough. It has a `--check` mode and a
  `make check` line.
- C wiring: `native-sim/arm64/arm64_sim_local_bpf.h` includes the generated
  header and the 24-line handler chain is replaced by a delegation to
  `ARM64_SIM_L_BITFIELD_VALUE`, which passes `ARM64_SIM_L_UNSUPPORTED_OPCODE()`
  as the unsupported arm. Behavior is unchanged for the five in-table kinds
  (same mask, same sign extension, same field placement), and now
  `ARM64_SIM_L_READ_REG` is evaluated exactly once per operand: the old code
  read `DST` twice in the BFXIL/BFI arms, so a side-effecting read would have
  been double-evaluated. The macro takes an explicit unsupported argument
  (unlike the total `KPROG_ARM64_MOD_VALUE`) because a code outside the table
  must reach the caller's trap.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64Bitfield.lean` proves
  `arm64_bitfield_refines` (the generated `value` equals an independently
  written `arm64BitfieldValueSpec` over all five kinds and the architectural
  domain), `arm64_bitfield_mask_refines` (the generated `((1 << bits) - 1)` mask
  equals the complement-form `~~~(~0 <<< bits)` statement with a 64-bit
  saturation arm), `arm64_bitfield_lsb_below_width` (in-domain `lsb < 64`, so
  the C handler's guards never fire), `arm64_bitfield_code_in_range`,
  `arm64_bitfield_code_dispatch`, and `arm64_bitfield_field_magnitude` (the
  `__u8` field byte's zero extension carries its magnitude). Canonical examples:
  UBFX of `0x0000000000abcdef01` at `lsb=8, bits=16` is `0xcdef`, SBFX of a
  four-bit `1111` field is all ones, UBFIZ of `0xff` at `lsb=8, bits=8` is
  `0xff00`, BFXIL of `0xaa` into `0xffffffffffff0000` at `lsb=0, bits=8` is
  `0xffffffffffff00aa`, BFI of `0xb` at `lsb=4, bits=4` is `0xb0`, and a 64-bit
  UBFX consumes the whole source. No `sorry`/`admit`. Both new modules are in
  the `KProgFormal.lean` root import list and the bridge has a `lean` line in
  the Makefile.
- Lesson learned: the three non-wrapping `BitVec 8` bounds
  (`1 <= bits`, `bits <= 64`, `lsb <= 64 - bits`) are all mandatory hypotheses.
  Dropping the lower two makes `arm64_bitfield_refines` false, because without
  them the modular `64 - lsb - bits` field position no longer denotes the
  architectural field. A second lesson: `BitVec.signExtend (setWidth
  bits.toNat …)` is opaque to the reifier, so SBFX must be stated through the
  left-justified field's `.sshiftRight'` instead. A third: `(64 : BitVec 8)` to
  `Nat` reasoning needs `bv_omega`; `rw [BitVec.toNat_sub, …]` does not fire and
  bare `omega` cannot close the modular-subtraction goal. The five-arm theorem
  needs `set_option maxHeartbeats 4000000 in`, and that option must precede the
  docstring, not sit between docstring and `theorem`. A narrowing-commutation
  theorem for bitfield has no true naive form and was deliberately not added.
- Host cross-check `native-sim/formal/test_arm64_bitfield_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it
  against an independent oracle written as a pure bit-level model (per-bit
  extraction/insertion/sign-extension over architectural positions, no
  `arm64_sim.h` and no reuse of `arm64_bits_mask`/`arm64_sign_extend`). It sweeps
  16 sources x 8 destinations x 20 in-domain `(lsb, bits)` pairs x 5 kinds, then
  a 21-entry out-of-domain table that reaches the generated guards (zero width,
  widths past 64, field positions at or past 64) x 5 kinds, then a fixed-seed
  20000-iteration sweep over `(lsb, bits)` in `[0, 127]`, then checks that
  `KPROG_ARM64_BITFIELD_HANDLED` accepts exactly the five codes and rejects code
  5. Result: `OK (126246 cases)`. The oracle was wrong on its first draft: it
  modelled UBFIZ/BFI as the bare shifted mask instead of `(src & mask) << lsb`,
  which reported 41448 mismatches against a correct macro; the model now derives
  each result bit from the source bit at the corresponding field position.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, and the arm64 bitfield host cross-check step;
  ~51 s), alongside the arm64 mod (`OK (225292 cases)`), arm64 ALU result
  (`OK (120073 cases)`), arm64 flags (`OK (60144 cases)`), and x86 memory-access
  (`OK (40020 cases)`) cross-checks. Mutation checks: changing a bitfield code in
  `arm64_bitfield_spec.json` makes `--check` exit 1, and mutating a decode-table
  bitfield code makes the drift cross-check exit 1; fourteen independent
  semantic mutations of `generated/arm64_bitfield.h` each make the host
  cross-check exit 1 with a printed mismatch (mask width bound, SBFX sign bit,
  SBFX xor/subtract, mask shift width, field shift amount, the three `lsb >= 64`
  guard boundaries, both destination-complement masks, the UBFX mask, the
  subject shift guard, and the `HANDLED` chain), while the pristine header stays
  `OK`. `make -C native-sim/arm64 micro-proofs-build` rebuilds all 30
  workload-derived artifacts, all `ok`; `make -C native-sim/arm64 build`
  produces the BPF object from `arm64_sim_hardcoded.bpf.c` (which includes the
  changed header) and `make -C native-sim/arm64 run` loads it (`load-only`,
  fd=4).
- Open AArch64 boundary after this increment: the `MADD`/`MSUB`/`UMULH` flag
  consequences if any (the multiply block in
  `native-sim/arm64/arm64_sim_local_bpf.h`), condition-to-next-PC beyond the
  earlier condition contract, and native bytes. These theorems do not establish
  native-byte equivalence, and the Lean bitfield contract is stated over
  `BitVec 64` while the C macro operates on `__u64`; the host cross-check bridges
  that C/Lean semantics gap for the tested vectors only.

### AArch64 multiply-family refinement, 2026-09-15

- Gap: the eight multiply-family arms (MADD, MSUB, MUL, UMULL, UDIV, UMULH,
  UMADDL, SMADDL) were two hand-written if/else-if chains inside
  `ARM64_SIM_L_EXEC_ALU` in `native-sim/arm64/arm64_sim_local_bpf.h`. UMULH
  additionally called a private `arm64_umulh` helper in
  `native-sim/arm64/arm64_sim.h`, whose partial-product ladder existed nowhere
  else and had no independent statement. The two chains read
  `ARM64_SIM_L_READ_REG(SRC3)` once per condition test in the MADD/MSUB arm, so
  a side-effecting read could have been evaluated more than once. The previous
  increment's open AArch64 boundary named the multiply block and its
  `MADD`/`MSUB`/`UMULH` flag question; the flag question is answered here (see
  below) and the value contract is now generated and proved.
- Generator: `native-sim/formal/generate_arm64_mul_spec.py` reads
  `arm64_mul_spec.json` and emits the shared contract in two forms:
  `generated/arm64_mul.h` (`KPROG_ARM64_MUL_VALUE(OP, LHS, RHS, ADDEND,
  UNSUPPORTED)`, a statement expression switching on the eight raw numeric
  opcodes `10U, 11U, 12U, 13U, 14U, 46U, 59U, 64U` with an explicit
  `default: UNSUPPORTED; break;`) and `KProgFormal/GeneratedArm64Mul.lean`
  (a self-contained `namespace GeneratedArm64Mul` with `inductive Mul`, `code`
  and `value`, deliberately not reusing or extending the decode table's
  inductive). The family is **not contiguous** in the ARM64_OP_* space, so the C
  macro uses the raw architectural opcode values as case labels rather than an
  internal dense kind index; `load()` parses `native-sim/arm64/arm64_sim.h` for
  `ARM64_OP_*` and exits 1 if the spec's codes drift from the simulator's
  constants, so the numeric labels cannot silently diverge. The emitted
  `_Static_assert`s pin the same eight values at compile time and
  `KPROG_ARM64_MUL_HANDLED(OP)` has one arm and one coverage assert per code.
  It has a `--check` mode and a `make check` line.
- C wiring: `native-sim/arm64/arm64_sim_local_bpf.h` includes the generated
  header, gains the `ARM64_SIM_L_MUL_VALUE(OP, SRC, SRC2, SRC3)` wrapper (which
  hoists all three register reads exactly once each), and the 20-line two-chain
  handler is replaced by a single `else if (KPROG_ARM64_MUL_HANDLED(OP))` branch
  that delegates to the generated macro and hands the result to the unchanged
  `ARM64_SIM_L_WRITE_REG_WIDTH`. Behavior is unchanged for the eight in-table
  opcodes. The now-redundant `arm64_umulh` helper is deleted from
  `arm64_sim.h`; a `grep` over `native-sim/` confirmed it had exactly one caller
  (the replaced handler) and no doc or test reference, so removing it leaves no
  dangling caller and no duplicated implementation.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64Mul.lean` proves
  `arm64_mul_refines` (the generated `value` equals an independently written
  `arm64MulValueSpec` over all eight operations and all operand values),
  `arm64_mul_width_refines` (narrowing commutes with the refinement),
  `arm64_mul_flags_unchanged` (the multiply family's NZCV transition is the
  identity), `arm64_mul_code_in_range`, `arm64_mul_code_dispatch`, and a
  `native_decide` example per operation. The refinement is deliberately stated
  against structurally different forms: UMULH is compared against the exact
  128-bit product's high word (`BitVec.setWidth 64 (((lhs.setWidth 128) *
  (rhs.setWidth 128)) >>> 64)`) rather than the partial-product ladder, SMADDL
  goes through `arm64MulSignExt32Spec`, MSUB is stated as
  `addend + ~~~(lhs * rhs) + 1` (two's-complement form) rather than
  `addend - lhs * rhs`, and UMULL/UMADDL widen through
  `(lhs.setWidth 32).setWidth 64` rather than a mask. The bridge between the
  ladder and the 128-bit statement is the `Nat` identity
  `arm64MulUmulhLadderEqHighWord`, itself proved via
  `arm64MulUmulhNat`/`arm64MulUmulhHighWordToNat` from the radix-`2^32`
  decomposition. No `sorry`/`admit`. Both new modules are in the
  `KProgFormal.lean` root import list and both have `lean` lines in the
  Makefile.
- Lesson learned (the hard one): `bv_decide` cannot discharge the UMULH ladder.
  Unfolded, the SAT query needs 10.89 s; against the bare statement it fails
  with `It abstracted the following unsupported expressions as opaque
  variables: [umulhAlg lhs rhs]`; prior attempts ran 600 s, 601.94 s and
  902.63 s before failing. The working route is an explicit `Nat` chain: prove
  the operands' 32-bit halves multiply below `2^64`, eliminate the outer
  `% 2^64` layers with `Nat.mod_eq_of_lt` (`ma1`/`ma2` for the high partial and
  cross terms, `mb1`/`mb2` for the carry column), and close the last layer with
  `hbnd2`, whose bound transfers through the radix identity (`hid` =
  `arm64MulUmulhNat`) and `Nat.div_lt_iff_lt_mul` + `arm64MulProdBound`. Plain
  `omega` closes neither the division goal nor the normalized `Nat` goal; it is
  only used for the small side-condition bounds and the `ma1`/`ma2`/`mb1`/`mb2`
  subgoals. A second lesson: never plain-`rw` a div-mod decomposition lemma
  (`Nat.div_add_mod`) at a goal containing `a/2^32`/`a%2^32` — it rewrites
  inside them and recurses (`maximum recursion depth has been reached`, or a
  stack overflow, exit 134); `set_option maxRecDepth 100000` only makes the
  overflow worse. Use `congrArg` (as `arm64MulPq` does) or `conv => rhs;
  rw [...]`. A third: `conv_lhs`/`conv_rhs`/`nth_rewrite` do not exist in this
  Mathlib-free toolchain. A fourth: the sign-extension arm needs a `by_cases`
  split on the sign bit before `bv_decide`. A fifth: `BitVec.setWidth` is the
  truncation (`BitVec.setWidth_eq`); `BitVec.setWidth_self_le` and
  `BitVec.toNat_div` do not exist, but `BitVec.toNat_udiv` does. A sixth: an
  `@[simp]` helper (`arm64MulToNatMask32`) must be declared **before** the
  `simp only` that consumes it, and `simp only [<helper>]` on an already
  normalized goal errors with `simp made no progress`. A seventh:
  `arm64MulValueSpec` takes four operands (`op lhs rhs addend`), so every
  `native_decide` example must pass the `addend` slot explicitly even for
  operations that ignore it — passing three makes Lean read the literal as the
  `addend` slot's function type and the example fails with an
  `OfNat (BitVec 64 → BitVec 64)` synthesis error.
- Flag obligation: the multiply family writes **no** NZCV and no
  `ARM64_OP_MADDS`/`MSUBS` variant exists in the opcode table, so
  `arm64MulFlagsSpec` is the identity transition and
  `arm64_mul_flags_unchanged` proves the C macro's (absent) flag write matches
  it. The generated flag contract covers only the ADD/SUB/logical families, so
  this is a documentary obligation recorded here rather than a new spec family.
- Host cross-check `native-sim/formal/test_arm64_mul_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it
  against an independent oracle (no `arm64_sim.h`, no partial-product ladder).
  The UMULH oracle is architectural: it reads the high word of an
  `unsigned __int128` product. It sweeps a 20-vector boundary table (zero
  operands, all-ones, `0xffffffff`, `0x80000000`, `1<<31`, `1<<63`,
  `0x100000000`, accumulator-carry cases, `addend = ~0`) x all eight ops, then a
  fixed-seed 20000-iteration LCG sweep (seed `0x9e3779b97f4a7c15`, distinct
  from the alu-result `0x12345678` and bitfield `0x243f6a8885a308d3` seeds) x
  all eight ops, then a `fork`/`waitpid` check that an opcode outside the family
  (`9U`) aborts with `SIGABRT` through the generated `default:` arm. Result:
  `OK (160161 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, and the arm64 mul host cross-check step),
  alongside the arm64 bitfield (`OK (126246 cases)`), arm64 mod
  (`OK (225292 cases)`), arm64 ALU result (`OK (120073 cases)`), arm64 flags
  (`OK (60144 cases)`), and x86 memory-access (`OK (40020 cases)`)
  cross-checks. Mutation checks: changing a multiply code in
  `arm64_mul_spec.json` makes `--check` exit 1; changing `ARM64_OP_UMULH` in
  `arm64_sim.h` makes the generator report `arm64 multiply opcodes drift` and
  exit 1; seven independent semantic mutations of `generated/arm64_mul.h`
  (MADD `+`→`-`, MSUB `-`→`+`, UMULL rhs not narrowed, UDIV zero guard `0`→`1`,
  UMULH carry shift `32`→`31`, UMADDL accumulator dropped, SMADDL lhs
  sign→zero extension) each make the host cross-check exit 1 with a printed
  `MISMATCH`, while the pristine header stays `OK`.
  `make -C native-sim/arm64 micro-proofs-build` rebuilds all 30
  workload-derived artifacts, all `ok`; `make -C native-sim/arm64 build`
  produces the BPF object from `arm64_sim_hardcoded.bpf.c` (which includes the
  changed headers) and `make -C native-sim/arm64 run` loads it (`load-only`,
  fd=4).
- Open AArch64 boundary after this increment: the extract/reverse/extend
  (`EXTR`/`REV`/`SXT*`/`UXT*`-style) handler composition, condition-to-next-PC
  beyond the earlier condition contract, and native bytes. These theorems do
  not establish native-byte equivalence, and the Lean multiply contract is
  stated over `BitVec 64` while the C macro operates on `__u64`; the host
  cross-check bridges that C/Lean semantics gap for the tested vectors only.

### AArch64 extract/reverse/extend refinement, 2026-09-15

- Gap: the six AArch64 extract/reverse/extend arms were two hand-written
  if/else-if chains inside `ARM64_SIM_L_EXEC_ALU` in
  `native-sim/arm64/arm64_sim_local_bpf.h`. EXTR carried its own local
  `arm64_width_bits`/immediate-mask computation and read both source registers
  inline; REV/REV16/SXTB/SXTH/SXTW called the private `arm64_reverse_bytes`,
  `arm64_reverse_bytes16` and `arm64_sign_extend` helpers in
  `native-sim/arm64/arm64_sim.h`, whose byte ladders existed nowhere else and had
  no independent statement. The previous increment's open AArch64 boundary named
  exactly this extract/reverse/extend composition.
- Generator: `native-sim/formal/generate_arm64_extrev_spec.py` reads
  `arm64_extrev_spec.json` and emits the shared contract in two forms:
  `generated/arm64_extrev.h` (`KPROG_ARM64_EXTREV_VALUE(OP, SRC, SRC2, SHIFT,
  WIDTH, UNSUPPORTED)`, a statement expression switching on the six raw numeric
  opcodes `17U, 19U, 20U, 21U, 47U, 60U` with an explicit
  `default: UNSUPPORTED; break;`) and `KProgFormal/GeneratedArm64Extrev.lean`
  (a self-contained `namespace GeneratedArm64Extrev` with `inductive Extrev`,
  the `rev`/`rev16`/`signExtend` helper definitions, `code`, `mnemonic` and
  `value`). The family is not contiguous in the ARM64_OP_* space, so the C macro
  uses the raw architectural opcode values as case labels; `load()` parses
  `ARM64_OP_*` out of `native-sim/arm64/arm64_sim.h` and exits 1 on drift, and
  the emitted `_Static_assert`s pin the same six values at compile time.
  `KPROG_ARM64_EXTREV_HANDLED(OP)` has one arm and one coverage assert per code.
  It has a `--check` mode and a `make check` line.
- Emitted-subset evidence for the width domain: the 29 workload-derived micro
  kernels emit EXTR at width 32 (4 sites) and 64 (1 site), REV and REV16 at
  width 32 (12 sites each) and SXTH at width 32 (1 site); no REV/REV16/SXT site
  uses width 8 or 16, and no UXT* opcode exists in the simulator subset. The
  refinement therefore states EXTR at all four widths (the shared macro spans
  them) and states REV/REV16 at the word and doubleword arms the macro selects,
  which is the emitted domain.
- C wiring: `native-sim/arm64/arm64_sim_local_bpf.h` includes the generated
  header, gains the `ARM64_SIM_L_EXTREV_VALUE(OP, SRC, SRC2, SHIFT, WIDTH)`
  wrapper, and replaces the two chains with a single
  `else if (KPROG_ARM64_EXTREV_HANDLED(OP))` branch that delegates to the
  generated macro and hands the result to the unchanged
  `ARM64_SIM_L_WRITE_REG_WIDTH`. Behavior is unchanged for the six in-table
  opcodes, and `ARM64_SIM_L_READ_REG` is now evaluated exactly once per operand.
  The `arm64_reverse_bytes` and `arm64_reverse_bytes16` helpers are deleted; a
  `grep` over `native-sim/` confirmed their only callers were the replaced
  branches. `arm64_sign_extend` is retained because the LDRSB/LDRSW/LDRSH
  handlers still use it.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64Extrev.lean` proves
  `arm64_extrev_extr_w{8,16,32,64}_refines` (the generated EXTR arm narrowed to
  each width equals an independent statement over the 128-bit
  `src : src2` concatenation's rotation), `arm64_extrev_rev_w{32,64}_refines`
  and `arm64_extrev_rev16_w{32,64}_refines` (the generated byte ladders equal
  independent per-byte shift-and-or statements), `arm64_extrev_sxt{b,h,w}_refines`
  (the generated mask/xor/subtract equals the library sign extension),
  `arm64_extrev_family_refines` (all eleven conjuncts), `arm64_extrev_flags_unchanged`
  (the family's NZCV transition is the identity), `arm64_extrev_code_in_range`,
  `arm64_extrev_code_dispatch`, and a `native_decide` example per operation. The
  two operands of the EXTR conjuncts carry their `bits`-wide hypotheses, which is
  how the C handler's register write leaves them. No `sorry`/`admit`. Both new
  modules are in the `KProgFormal.lean` root import list and both have `lean`
  lines in the Makefile.
- Lesson learned (the hard one, and it cost most of this increment): `bv_decide`
  on a goal that still contains a `Width` value emits a shared auxiliary
  declaration `GeneratedArm64Width.Width.enumToBitVec`, so a second module using
  that tactic on a `Width`-typed goal collides in the combined `KProgFormal`
  import with the copy already emitted by `Arm64Mod`:
  `environment already contains 'KProgFormal.GeneratedArm64Width.Width.enumToBitVec'
  from KProgFormal.Arm64Mod`. Keeping `Width` out of the goal by `cases width`
  does NOT help — the per-branch goals still bit-blast the enum. The fix is to
  resolve the C `WIDTH == ARM64_WIDTH_32` test before the bit-blaster runs:
  `unfold rev arm64ExtrevRev32Spec; rw [if_pos rfl]` (word) or
  `rw [if_neg (by decide : ¬ (Width.w64 = Width.w32))]` (doubleword), and then
  `bv_decide` on the remaining pure-`BitVec` goal — or drop the `bv_decide`
  entirely where the rewrite already closes the goal. After the fix the module
  olean no longer carries the symbol and the root builds. A related lesson:
  `List.foldr`-shaped independent statements are opaque to `bv_decide`
  ("abstracted the following unsupported expressions as opaque variables:
  [List.foldr …]"), so the byte-reversal statements are written as explicit
  shift-and-or chains instead. A third: `bv_decide` can carry a
  `Width`-typed *hypothesis* without emitting the symbol, so the EXTR per-width
  conjuncts (whose goals are pure `BitVec` after `simp only [value, …spec,
  narrow, bits, mask]`) are safe as written.
- Flag obligation: all six arms write no NZCV and no MADD/MSUB-with-flags
  opcode exists, so `arm64ExtrevFlagsSpec` is the identity and
  `arm64_extrev_flags_unchanged` proves it. This is a documentary obligation, not
  a new spec family.
- Host cross-check `native-sim/formal/test_arm64_extrev_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it
  against an independent oracle built on architectural primitives only (no
  `arm64_sim.h`, no reuse of the header's ladders): EXTR against an
  `unsigned __int128` concatenation rotation, REV against a byte-array reversal,
  REV16 against a per-half byte swap, and SXTB/SXTH/SXTW against a
  mask/xor/subtract sign extension. Both operands are masked to the destination
  width before the macro runs and the result is masked afterwards — the
  composition of the generated value with the width-narrowing register write.
  It sweeps a 12-vector boundary table over the word and doubleword arms (zero
  operands, all-ones, `0x80`/`0x8000`/`0x80000000`, `1<<63`, `addend`-style
  all-ones shifts, a mid-register EXTR shift by 8), then a fixed-seed
  20000-iteration LCG sweep (seed `0x9e3779b97f4a7c15`, distinct from the
  multiply `0x1234abcd5678ef90`-family and earlier seeds), then a
  `fork`/`waitpid` check that opcode `9U` aborts with `SIGABRT` through the
  generated `default:` arm. Result: `OK (120145 cases)`. The oracle's first
  draft compared against an unmasked architectural value and reported 35058
  mismatches against a correct macro; masking both operands and the result to
  the architectural width is what makes it exact.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, and the arm64 extract/reverse/extend host
  cross-check step; the earlier steps stay green: arm64 mul `OK (160161 cases)`,
  arm64 bitfield `OK (126246 cases)`, arm64 mod `OK (225292 cases)`, arm64 ALU
  result `OK (120073 cases)`, arm64 flags `OK (60144 cases)`, x86 memory-access
  `OK (40020 cases)`). Mutation checks: changing an opcode in
  `arm64_extrev_spec.json` makes `--check` exit 1; changing `ARM64_OP_SXTB` in
  `arm64_sim.h` makes the generator report `arm64 extract opcodes drift` and
  exit 1; eight independent semantic mutations of `generated/arm64_extrev.h`
  (EXTR unmasked shift, EXTR swapped sources, REV32 byte shift, REV64 low-byte
  shift, REV16-32 mask, SXTB body width, SXTW sign position, `default` arm not
  aborting) each make the host cross-check exit 1 with a printed `MISMATCH`,
  while the pristine header stays `OK`. `make -C native-sim/arm64
  micro-proofs-build` rebuilds all 30 workload-derived artifacts, all `ok`;
  `make -C native-sim/arm64 build` produces the BPF object from
  `arm64_sim_hardcoded.bpf.c` (which includes the changed headers) and
  `make -C native-sim/arm64 run` loads it (`load-only`, fd=4).
- Real KVM evidence (the environment became available this session: `/dev/kvm`
  writable, `dockerd` running, `vng` 1.41, `qemu-system-*`, and both runner image
  tars present). `make micro BENCH="simple" SAMPLES=1 WARMUPS=0 INNER_REPEAT=10`
  completed exit 0 and wrote `micro/results/x86_kvm_micro_20260915_194201_705027/`
  (`details/result.json`): the `simple` program ran on the `native`, `kernel`
  and `llvmbpf` runtimes, each with result `12345678` and retval `2`, matching the
  expected result. This is a smoke, not a paper-grade throughput measurement.
  The run initially failed at `host-native-bpf-x86` because the framework kernel
  rebuild re-generated the two tracked vendored headers
  (`bcc/libbpf-tools/x86/vmlinux.h`,
  `tetragon/bpf/include/vmlinux_generated_x86.h`) from the *host* kernel BTF
  (`uname -r` = 7.3.0, whose `mm_struct` has no `user_ns`) instead of the
  framework runtime kernel target (7.0.0-30, whose `mm_struct` does have
  `user_ns`), breaking vendored tetragon. Restoring the committed headers made
  `make -C vendor/bpf native-artifacts` exit 0. Root cause: the x86 vendor
  header path keys off `uname -r`; a real framework run must use the committed
  7.0.0-30 headers. This is recorded as a caveat, not a measurement gate.
- Open AArch64 boundary after this increment: the remaining load/store handler
  compositions, condition-to-next-PC beyond the condition contract, and native
  bytes. These theorems do not establish native-byte equivalence, and the Lean
  extract/reverse/extend contract is stated over `BitVec 64` while the C macro
  operates on `__u64`; the host cross-check bridges that C/Lean semantics gap for
  the tested vectors only.

### Make-backed x86 KVM corpus attempt, 2026-09-15/16

- This session the runtime environment became fully available for the first time
  here: writable `/dev/kvm`, a running `dockerd`, `virtme-ng` 1.41,
  `qemu-system-{x86_64,aarch64}`, the framework x86 `bzImage`, and both runner
  image tars. Two public Make-backed runs were therefore attempted to establish
  real KVM evidence for the current tree (commit `9476539f0`, the AArch64
  extract/reverse/extend increment; its diff touches only `native-sim/arm64/**`
  and `native-sim/formal/**`, which the x86 corpus path does not consume).
- `make micro BENCH="simple" SAMPLES=1 WARMUPS=0 INNER_REPEAT=10` completed exit 0
  and wrote `micro/results/x86_kvm_micro_20260915_194201_705027/`
  (`details/result.json`). The `simple` program ran on the `native`, `kernel` and
  `llvmbpf` runtimes with result `12345678` and retval `2` (expected `12345678`).
  This is a functional smoke of the KVM path, not a throughput measurement.
- `make corpus BPFREJIT_CORPUS_APPS="bcc/set" SAMPLES=1 WORKLOAD_DURATION=10`
  ran end-to-end (`CORPUS_EXIT 0`; a full framework-kernel rebuild, then a VM
  workload) and wrote `corpus/results/x86_kvm_corpus_20260915_223707_648561/`.
  The run's own `metadata.json` records `status: "error"` and the app records
  `status: "error"` with `BCC tool capable exited before BPF programs were
  tracked by shim` / `failed to load BPF skeleton 'capable_bpf': -22`. The
  load-time step itself is `status: "ok"` and the baseline descriptor table is
  present, but the BCC `capable` tool died before the shim tracked a program, so
  no post-ReJIT workload or per-program delta exists. This is an app-side startup
  failure, not a throughput result.
- A second app was then run: `make corpus BPFREJIT_CORPUS_APPS="cilium/agent"
  SAMPLES=1 WORKLOAD_DURATION=10` (`CORPUS_CILIUM_EXIT 0`;
  `corpus/results/x86_kvm_corpus_20260915_230952_590418/`). It also records
  `status: "error"`: `native app exited before BPF programs were tracked by
  shim`, with the Cilium agent's stdout ending at
  `level=fatal msg="Failed to compile XDP program" ... error="attaching XDP
  program to interface bpfbench0: Failed to compile bpf_xdp.o: context
  canceled"`. Again the load-time step is `status: "ok"` and the baseline is
  captured, but the agent is canceled before shim tracking, so there is no
  post-ReJIT workload.
- A third attempt (`tetragon/observer`) failed during the runtime-image rebuild
  itself: `docker save ... image.tar.tmp` then `mv: cannot stat ... .tmp`, i.e.
  the `x86-runner-runtime-image-tar` rule's temp teardown raced with a
  concurrent run because the earlier corpus invocations had started builds that
  were still finishing. That is an operator sequencing mistake in this session,
  not a repository defect; the image tar rebuilt from `23:09` is intact
  (`tar -tf` succeeds) and `docker run --rm bpf-benchmark/runner-runtime:x86_64
  ls /usr/local/lib/bpfrejit/` shows `libbpfrejit_shim.so` present.
- Conclusion and caveats: the public Make-backed KVM path is functional
  end-to-end (kernel boot, VM workload, artifact write) and the micro smoke
  passes, but no paper-grade corpus throughput result was obtained this session
  because both corpus apps fail at application startup in the container (BCC
  skeleton load `-22`; Cilium XDP compile canceled). Those are x86-side runtime
  issues unrelated to the AArch64 proof line, and they are recorded as raw
  failures per the standing rule (keep all failures, no relabeling). The next
  useful step on the benchmark side is to diagnose the container-local BCC/
  Cilium startup failures; the next useful step on the proof side is the
  remaining AArch64 load/store handler compositions. Concurrency caveat: run one
  corpus invocation at a time, since parallel runs share
  `.cache/container-images/*.image.tar` and the runtime kernel build.

### AArch64 conditional-select refinement, 2026-09-16

- Gap: the eight AArch64 conditional-select arms (CSEL, CINC, CSET, CSETM,
  CINV, CSINV, CSINC, CSNEG) were three hand-written if/else-if chains inside
  `ARM64_SIM_L_EXEC_ALU` in `native-sim/arm64/arm64_sim_local_bpf.h`. They
  restated the condition evaluation (`ARM64_SIM_L_EVAL_COND`) at each site and
  read each source register inline, so a side-effecting operand read could be
  evaluated more than once, and the value selection had no independently stated
  contract. The previous increment's open AArch64 boundary named the remaining
  register-lane handler compositions; this is the largest emitted one after the
  already-shared families (30 CSEL sites, 35 CCMP_REG, 14 CCMP_IMM, 3 CSET,
  2 CINC in the 29 micro kernels).
- Generator: `native-sim/formal/generate_arm64_csel_spec.py` reads
  `arm64_csel_spec.json` and emits the shared contract in two forms:
  `generated/arm64_csel.h` (`KPROG_ARM64_CSEL_VALUE(OP, SRC, SRC2, TAKEN,
  UNSUPPORTED)`, a statement expression switching on the eight raw numeric
  opcodes `28U, 29U, 30U, 52U, 61U, 62U, 68U, 69U` with an explicit
  `default: UNSUPPORTED; break;`) and
  `KProgFormal/GeneratedArm64Csel.lean` (a self-contained
  `namespace GeneratedArm64Csel` with `inductive Csel`, `code`, `mnemonic` and
  `value`, whose arms are `if taken then <first> else <second>`). The family is
  not contiguous in the ARM64_OP_* space, so the C macro uses the raw
  architectural opcode values as case labels; `load()` parses `ARM64_OP_*` out
  of `native-sim/arm64/arm64_sim.h` and exits 1 on drift, and the emitted
  `_Static_assert`s pin the same eight values at compile time.
  `KPROG_ARM64_CSEL_HANDLED(OP)` has one arm and one coverage assert per code.
  It has a `--check` mode and a `make check` line.
- C wiring: `native-sim/arm64/arm64_sim_local_bpf.h` includes the generated
  header, gains the `ARM64_SIM_L_CSEL_VALUE(OP, SRC, SRC2, TAKEN)` wrapper, and
  replaces the three chains with a single `else if (KPROG_ARM64_CSEL_HANDLED(OP))`
  branch. The condition result is computed once into `__a64_l_taken`. **CSEL at
  width 64 keeps its pointer-tag-preserving path**: when the condition holds it
  writes `SRC`'s pointer and provenance tag, otherwise `SRC2`'s, exactly as
  before, because the value contract is stated over `__u64` and cannot express
  the tag lane. Every other arm — and CSEL at width 32 — delegates to the
  generated value macro and the width-narrowing register write.
  `ARM64_SIM_L_READ_REG` is now evaluated exactly once per source operand in the
  delegated arms.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64Csel.lean` proves
  `arm64_csel_refines` (the generated ternary `value` equals an independently
  stated bit-mask mux `arm64CselMux`, for all eight operations and both
  condition outcomes), `arm64_csel_cond_refines` (the same composition when the
  condition result comes from the generated `GeneratedArm64Cond.eval`, tying it
  to the already-proven condition contract rather than restating it),
  `arm64_csel_flags_unchanged` (the family reads flags but writes none),
  `arm64_csel_code_in_range`, `arm64_csel_code_dispatch`, and a `native_decide`
  example per operation. The two candidate values of each arm are named
  separately from the selection, so the refinement relates two genuinely
  different formulations (C ternary vs. architectural bit-mask mux). No
  `sorry`/`admit`. Both new modules are in the `KProgFormal.lean` root import
  list and both have `lean` lines in the Makefile.
- Lesson learned: a `Bool`-valued selector is the one place `bv_decide` is
  comfortable — `cases op <;> simp only [value, arm64CselValueSpec,
  arm64CselMux] <;> (cases taken <;> bv_decide)` closes every arm, because the
  goal stays inside `BitVec 64` and never bit-blasts a `Width` value (which is
  what emitted the colliding `Width.enumToBitVec` helper in the
  extract/reverse/extend increment). A second lesson: the pointer-tag lane at
  width 64 is outside the value contract's domain; the honest cutover keeps that
  one path hand-written and delegates the rest, instead of weakening the
  contract to a `(value, tag)` pair that no other arm needs.
- Flag obligation: all eight arms write no NZCV (the family only reads flags), so
  `arm64CselFlagsSpec` is the identity and `arm64_csel_flags_unchanged` proves
  it. This is a documentary obligation, not a new spec family.
- Host cross-check `native-sim/formal/test_arm64_csel_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it
  against an independent oracle that computes each arm's two candidate values
  with architectural arithmetic and selects with a bit mask (never the macro's
  ternary). It sweeps a 10-vector boundary table (`0`, all-ones, `1`,
  `0x7fff…`, `0x8000…`, `0x80000000`/`0xffffffff`, mid-range vectors) over both
  condition outcomes and all eight ops, then a fixed-seed 20000-iteration LCG
  sweep (seed `0x0123456789abcdef`, distinct from the other increments' seeds),
  then a `fork`/`waitpid` check that opcode `9U` aborts with `SIGABRT` through
  the generated `default:` arm. Result: `OK (160161 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, and the arm64 conditional-select host
  cross-check step; earlier steps stay green: arm64 extract/reverse/extend
  `OK (120145 cases)`, arm64 mul `OK (160161 cases)`, arm64 bitfield
  `OK (126246 cases)`, arm64 mod `OK (225292 cases)`, arm64 ALU result
  `OK (120073 cases)`, arm64 flags `OK (60144 cases)`, x86 memory-access
  `OK (40020 cases)`). Mutation checks: changing an opcode in
  `arm64_csel_spec.json` makes `--check` exit 1; changing `ARM64_OP_CSNEG` in
  `arm64_sim.h` makes the generator report `arm64 conditional-select opcodes
  drift` and exit 1; nine independent semantic mutations of
  `generated/arm64_csel.h` (CSEL swapped sources, CINC decrement, CSET constant,
  CSETM mask, CINV no complement, CSINV complement-first, CSINC wrong addend,
  CSNEG wrong source, `default` arm not aborting) each make the host cross-check
  exit 1 with a printed `MISMATCH`, while the pristine header stays `OK`.
  `make -C native-sim/arm64 micro-proofs-build` rebuilds all 30 workload-derived
  artifacts, all `ok`; `make -C native-sim/arm64 build` produces the BPF object
  from `arm64_sim_hardcoded.bpf.c` (which includes the changed headers) and
  `make -C native-sim/arm64 run` loads it (`load-only`, fd=4).
- Dead-code follow-up: the extract/reverse/extend cutover had left
  `arm64_width_mask`, `arm64_width_bits` and `arm64_sign_bit` with no caller
  (only their definitions remained). They were removed in a separate commit
  (`native-sim: drop dead AArch64 width helpers after extract cutover`) after
  the arm64 build, the 30 micro-proof artifacts, and the full formal check all
  stayed green.
- Open AArch64 boundary after this increment: the load/store handler
  compositions (including the LDRSB/LDRSW/LDRSH sign-extending loads, whose
  `arm64_sign_extend` helper is now the last private-helper caller) and
  condition-to-next-PC beyond the condition contract. These theorems do not
  establish native-byte equivalence, and the Lean conditional-select contract is
  stated over `BitVec 64` while the C macro operates on `__u64`; the host
  cross-check bridges that C/Lean semantics gap for the tested vectors only.

### AArch64 sign-extending-load composition, 2026-09-16

- Gap: the LDRSB/LDRSW/LDRSH handlers in
  `native-sim/arm64/arm64_sim_local_bpf.h` widened a byte/halfword/word memory
  read through the private `arm64_sign_extend` helper in
  `native-sim/arm64/arm64_sim.h`. That helper was the last caller of the private
  `arm64_bits_mask` helper, and the same sign-extension formula is already
  generated and proved in the extract/reverse/extend contract's SXTB/SXTH/SXTW
  arms.
- Composition: the handlers now delegate to
  `ARM64_SIM_L_EXTREV_SIGNEXT(OP, VALUE, WIDTH)`, a thin wrapper over the
  generated `KPROG_ARM64_EXTREV_VALUE` with the already loaded value as `SRC`.
  No new generator or spec was needed; the delegated arm is exactly the proved
  `((value & mask) ^ sign) - sign` form, so the change is a cutover onto an
  existing theorem rather than a new contract. This is the composition pattern
  the earlier increments set up: a new handler can reuse an already-proved
  generated arm instead of restating it.
- Dead code removed: with the last caller gone, `arm64_sign_extend` and its only
  dependent `arm64_bits_mask` were deleted from `arm64_sim.h`. A `grep` over
  `native-sim/` confirmed neither had another caller. This leaves
  `native-sim/arm64/arm64_sim.h` with no private sign-extension or byte-reversal
  helper; the remaining helpers (`arm64_apply_width`, `arm64_ror32/64`,
  `arm64_lsl/lsr/asr/ror`, the popcount/horizontal-add vector helpers, and
  `arm64_width_*` removal earlier) all still have callers.
- Verification: full `make -C native-sim/formal check` green with no new lines
  needed (the composition reuses the proved contract); `make -C
  native-sim/arm64 build` exit 0; `make -C native-sim/arm64 micro-proofs-build`
  rebuilds all 30 workload-derived artifacts, all `ok`; `make -C
  native-sim/arm64 run` loads the object (`load-only`, fd=4). No new mutation
  checks were added because no new generated artifact was introduced; the
  existing `test_arm64_extrev_host.c` mutation suite already covers the SXTB/
  SXTH/SXTW arms that the load handlers now use.
- Open AArch64 boundary after this increment: condition-to-next-PC beyond the
  condition contract (the value side of the conditional-select family is now
  covered; what remains is tying the generated condition predicate to an actual
  program-counter transition), and native bytes. These theorems do not establish
  native-byte equivalence.

### Completed two-start KVM corpus with the noop policy, 2026-09-16

- After the pass-specific failures recorded above, a completed two-start corpus
  run was obtained by narrowing the policy to the pass that is pure bytecode
  identity plus the map pass the tree already ships:
  `BPFREJIT_CORPUS_APPS="katran" BPFREJIT_BENCH_PASSES="noop"
  SAMPLES=1 WORKLOAD_DURATION=10 make corpus` (`EXIT 0`), artifact
  `corpus/results/x86_kvm_corpus_20260916_031856_977978/`.
- Result: `metadata.json` records `status: "completed"`; the app record is
  `status: "ok"` with `rejit_result.status: "ok"` and a populated
  `post_rejit`. Both phases ran the real upstream `katran_server_grpc` under
  `KVM`/`virtme-ng` with a 10-second `kernel_pktgen` L2/UDP workload.
- Raw per-phase descriptors for the sole tracked program `balancer_ingres`
  (xdp): baseline `bytes_xlated=23840`, `bytes_jited=13641`,
  `run_cnt_delta=25,919,459`, `run_time_ns_delta=4,390,702,012`; post-ReJIT
  `bytes_xlated=24080`, `bytes_jited=14260`, `run_cnt_delta=26,343,662`,
  `run_time_ns_delta=4,435,046,280`. The size **increase** is the expected
  `noop` verifier-state step, which adds bytecode deliberately; the run is
  evidence that the two-start load-time path completes, not that `noop`
  optimizes.
- Raw workload `pktgen` throughput lines (four 10-second threads per phase,
  thread 3 is the unused/drain thread and reports 0 pps in both phases):
  baseline `878541`, `858560`, `862303` pps; post-ReJIT `875900`, `886925`,
  `879385` pps. These are single-sample raw values from one run; they are
  recorded as provenance for the completed contract, not as a paper-grade
  speedup (SAMPLES=1, one app, one pass, ~2% spread across threads).
- Root cause of the earlier failures, now isolated: the default `full-x86`
  policy's `kop` step fails inside the load-time shim
  (`loadtime bpfopt step kop failed`, e.g. on the trivial `libbpf_nametest`
  2-instruction program), and with `noop,map_inline` the `map_inline` step fails
  on `balancer_ingres` (`loadtime bpfopt step map_inline failed`). In both cases
  the shim reports the failure and the app aborts, so the two-start comparison
  cannot complete. The `noop`-only policy exercises the same two-start
  load-time contract without the failing optimizer pass. The optimizer-pass
  failures are x86 pass-policy/backend issues on the current tree, unrelated to
  the AArch64 proof line, and are recorded here as raw failures.
- Concurrency caveat restated: run one corpus invocation at a time. Two of the
  earlier attempts overlapped and raced on
  `.cache/container-images/*.image.tar`.

### katran map_inline overlay-path fix, 2026-09-16

- Root cause of the `map_inline` load-time failure is now pinpointed and fixed.
  `runner/config/passes/map_inline/katran.yaml`'s `balancer_ingress` command
  built `OVERLAY_DIR=/home/yunwei37/workspace/bpf-benchmark/runner/config/passes/
  map_inline/overlays/katran`, an absolute path from a different machine layout.
  In this workspace (and in the runtime container) the overlays live at
  `/workspaces/repository/runner/config/passes/map_inline/overlays/katran`, so
  the step's `jq --slurpfile` calls failed with
  `Could not open …/ch_rings.json: No such file or directory` (exit 2), the
  overlay-construction `&&` short-circuited, `bpfopt` never ran, and the shim
  reported `loadtime bpfopt step map_inline failed`, aborting the app. This was
  reproduced exactly inside the runtime image: the hardcoded path fails, the
  workspace path produces a 163-byte `overlays.json`.
- Fix: the command now resolves the overlay directory from the injected
  workspace root, `OVERLAY_DIR="${BPFREJIT_REPO_ROOT:?BPFREJIT_REPO_ROOT is
  required}/runner/config/passes/map_inline/overlays/katran"`.
  `BPFREJIT_REPO_ROOT` is set by the corpus driver for every load-time step
  (`corpus/driver.py`), so the path is exact and the `:?` form fails loudly if
  the variable is ever missing. `runner/config/passes/**` is optimization policy
  under the repo rules (not a frozen workload, app runner, corpus driver, or
  benchmark Makefile), so this edit is in scope.
- The same hardcoded `/home/yunwei37/...` prefix still appears in two other pass
  policies, `runner/config/passes/const_mod_reduce/default.yaml` and
  `runner/config/passes/const_mod_reduce_branchless_rejected/default.yaml`.
  Neither pass is in the default `benchmark_config.yaml` policy, so they do not
  block the current corpus path, but they will fail the same way if they are ever
  enabled. They are left unchanged here and recorded as a known follow-up.
- The remaining default-policy blocker is the `kop` step. It fails because the
  host `bpfopt` (and the copy baked into the runtime image) is linked against
  the system LLVM-18, which does not carry the `-bpf-enable-kop-select` /
  `-bpf-kop-mode` options the kop pass needs; those live in the experimental
  `llvm-backend/llvm` fork under `llvm-backend/build-bpf-kop`, which is only
  partially built (no `libLLVM`). Building that fork and pointing
  `LLVM_DIR`/`RUN_LLVM_DIR` at it is the environment prerequisite for the
  default policy; it is a long build and was not completed in this session.

### Completed two-start KVM corpus with the katran map_inline policy, 2026-09-16

- With the overlay-path fix, the previously failing `noop,map_inline` policy now
  completes end to end:
  `BPFREJIT_CORPUS_APPS=katran BPFREJIT_BENCH_PASSES=noop,map_inline SAMPLES=1
  WORKLOAD_DURATION=10 JOBS=8 IMAGE_BUILD_JOBS=8 VMLINUX_BTF=<framework
  vmlinux> make corpus` exits 0 and writes
  `corpus/results/x86_kvm_corpus_20260916_131646_375109/` with suite
  `status: "completed"`, app `status: "ok"`, `rejit_result.status: "ok"`,
  passes `["noop","map_inline"]`, mode `loadtime`.
- The load-time report confirms `map_inline` actually ran and applied: of the 12
  step reports, one `map_inline` step reports `sites_applied: 16` /
  `sites_matched: 16` (the `balancer_ingres` XDP program) and five report
  `0/0` (programs with no inlinable map sites); the three `noop` steps report
  `1/1` and three `0/0`. This is the first run in this workspace where a real
  optimizer pass (not `noop`) applied sites under the load-time contract.
- Raw per-program counters (`balancer_ingres`, the 28.14M/26.26M-run XDP
  program): baseline `run_time_ns_delta = 4,437,801,179` over
  `run_cnt_delta = 26,261,979` (168.98 ns/run); post-ReJIT
  `run_time_ns_delta = 4,136,441,567` over `run_cnt_delta = 28,139,200`
  (147.00 ns/run). Ratio 0.870 (< 1: faster). `bytes_xlated` 19,616,
  `bytes_jited` 11,975, type `xdp`.
- Raw workload throughput (pktgen, four 10-second threads per phase; the
  `pps`-parsing thread that reports `860`/`1099` is the pktgen control thread,
  not a transmitter): baseline thread pps 883,074 + 870,014 + 879,703 =
  2,632,791; post-ReJIT 948,108 + 912,572 + 958,925 = 2,819,605. Sum ratio
  1.071. Single sample, one app, one pass: provenance plus a consistent
  direction, not a paper-grade speedup.
- The run needed `VMLINUX_BTF` pointed at the framework kernel's vmlinux
  (`vendor/build/x86/linux/vmlinux`). Without it the host-BTF path fails: the
  workspace host kernel changed to `7.3.0-070300rc3-generic` (BTF mtime
  11:22), whose `struct mm_struct` has no `user_ns`, so the regenerated
  `vendor/bpf/tetragon/bpf/include/vmlinux_generated_x86.h` (and the bcc
  `vmlinux.h`) break upstream tetragon's `_(&mm->user_ns)` at
  `native-tetragon`, and `host-native-bpf-x86` aborts. The framework kernel BTF
  (`7.0.0-rc2+`) has `user_ns`, and `make -C vendor/bpf native-tetragon
  VMLINUX_BTF=<framework vmlinux>` exits 0.
- Root cause of that environmental failure, which is also a repo asymmetry
  worth recording: `host-native-bpf-x86` (`runner/mk/build.mk`) invokes
  `make -C vendor/bpf native-artifacts` with no `VMLINUX_BTF`, so
  `vendor/bpf/Makefile` defaults it to `/sys/kernel/btf/vmlinux` — the *host*
  kernel — while the symmetric `host-native-bpf-arm64` rule explicitly passes
  `VMLINUX_BTF="$(HOST_KERNEL_VMLINUX_ARM64)"` (the framework kernel's
  vmlinux). The native objects are baked into the runtime image and run *under
  the framework kernel*, so x86 should derive field offsets from the same BTF
  as arm64. The one-line fix (add `$(HOST_KERNEL_VMLINUX_X86)` as a prerequisite
  and pass `VMLINUX_BTF="$(HOST_KERNEL_VMLINUX_X86)"`) was verified to make
  `native-tetragon` build, but `runner/mk/build.mk` is a frozen benchmark
  Makefile under the repo rules, so the change was **not** applied; the runs
  above pass `VMLINUX_BTF` on the `make` command line instead. Applying the
  Makefile fix needs explicit user authorization.
- Concurrency caveat repeated: run one corpus invocation at a time (runs share
  `.cache/container-images/*.image.tar` and the framework kernel build).

### AArch64 compare-and-branch predicate refinement, 2026-09-16

- Gap: the `CBZ`/`CBNZ`/`TBZ`/`TBNZ` control transfers in
  `native-sim/arm64/arm64_sim_local_bpf.h` each restated their taken/not-taken
  test inline (`(__a64_l_value == 0) == (ZERO)` and
  `((__a64_l_value >> (BIT)) & 1ULL)`), with the taken sense encoded in a
  `ZERO` selector argument rather than in a named predicate. These are the
  most-emitted control transfers in the corpus (35 `CBZ`, 8 `CBNZ`, 5 `TBZ`,
  3 `TBNZ` sites in the 29 micro kernels) and the remaining half of the
  condition-to-next-PC boundary the previous increments named.
- Generator: `native-sim/formal/generate_arm64_branch_spec.py` reads
  `arm64_branch_spec.json` and emits the shared contract in two forms:
  `generated/arm64_branch.h` (`KPROG_ARM64_BRANCH_TEST(KIND, VALUE, BIT)`, a
  statement expression switching on the four contiguous predicate kinds
  `0U..3U`, with named kind macros and a total `HANDLED` set) and
  `KProgFormal/GeneratedArm64Branch.lean` (a self-contained
  `namespace GeneratedArm64Branch` with `inductive Branch`, `code`, `mnemonic`
  and `value`). Unlike the opcode-family contracts, these kinds are a small
  contiguous predicate enum, not an architectural opcode table, so the case
  labels are `0U..3U` and there is no `arm64_sim.h` drift cross-check for them.
  The bit arms mask `BIT` with `& 63`, matching the 64-bit register domain.
  It has a `--check` mode and a `make check` line.
- C wiring: `native-sim/arm64/arm64_sim_local_bpf.h` includes the generated
  header and the four macros now delegate their predicate to
  `KPROG_ARM64_BRANCH_TEST` while keeping the exact `goto`/fall-through label
  structure the generator emits. `CBZ`/`CBNZ` pass `KPROG_ARM64_BRANCH_CBZ`/
  `CBNZ`; `TBZ`/`TBNZ` pass `TBZ`/`TBNZ` with the bit index. The `ZERO`
  selector is gone: the taken sense is now the kind. Behavior is unchanged for
  all four transfers (verified by the 30 recompiled workload artifacts), and the
  tested register is read exactly once.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64Branch.lean` proves
  `arm64_branch_refines` (the generated predicate equals an independent
  statement over the four kinds, stating the bit arms through `Nat` division and
  remainder rather than the generated shift/mask pair), `arm64_branch_next_pc_refines`
  (the predicate selects the same next program counter as the independent
  statement — the predicate half of the condition-to-next-PC relation, alongside
  the existing flag-based `arm64_conditional_branch_refines`),
  `arm64BranchBitMask` (C's `& 63` is the index modulo the register domain),
  `arm64BranchBitOf` (the generated bit extract reduces to the architectural
  bit's magnitude), `arm64_branch_code_in_range`, `arm64_branch_code_dispatch`,
  and four `native_decide` examples. No `sorry`/`admit`. Both new modules are in
  the `KProgFormal.lean` root import list and both have `lean` lines in the
  Makefile.
- Lesson learned: the generated bit arms must shift by a `Nat` index
  (`value >>> (bit &&& 63).toNat`), not by a `BitVec` index, because
  `BitVec.toNat_ushiftRight` only fires on the `Nat` form — with a `BitVec`
  shift amount `simp`/`rw` leaves an unfired goal and `omega` cannot close it.
  A second lesson: `decide P = decide Q` rewrites are ill-typed under `rw` when
  the two `Prop`s differ, so the bit-arm proofs go through
  `decide_eq_decide` (which yields a `Prop` iff) followed by a `BitVec.toNat_eq`
  bridge and the `arm64BranchBitOf` magnitude lemma. A third: `bv_decide`
  abstracts the symbolic bit extract (`BitVec.extractLsb' …`) as opaque, so it
  cannot prove these arms; the `Nat` reduction route is required.
- Host cross-check `native-sim/formal/test_arm64_branch_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it
  against an oracle that tests the register directly. It sweeps an 8-value ×
  8-bit-index table (zero, one, all-ones, `1<<63`, `1<<31`, single bits,
  out-of-domain indices 64 and 127) over all four kinds, then a fixed-seed
  20000-iteration LCG sweep (seed `0xfedcba9876543210`), and checks the macro is
  total over the four contiguous kinds. Result: `OK (80256 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, and the arm64 branch host cross-check step;
  the csel step stays `OK (160161 cases)`, extract/reverse/extend
  `OK (120145 cases)`, mul `OK (160161 cases)`, bitfield `OK (126246 cases)`,
  mod `OK (225292 cases)`, ALU result `OK (120073 cases)`, flags
  `OK (60144 cases)`, x86 memory-access `OK (40020 cases)`). Mutation checks:
  changing a kind code in `arm64_branch_spec.json` makes `--check` exit 1; five
  independent semantic mutations of `generated/arm64_branch.h` (CBZ inverted,
  CBNZ inverted, TBZ inverted, TBNZ inverted, bit mask narrowed to `& 31`) each
  make the host cross-check exit 1 with a printed `MISMATCH`, while the pristine
  header stays `OK`. `make -C native-sim/arm64 micro-proofs-build` rebuilds all
  30 workload-derived artifacts, all `ok` (the first attempt showed 14
  `compile-fail` because the new `arm64_branch.h` include had not yet been added
  to `arm64_sim_local_bpf.h`; adding it fixed all 14). `make -C
  native-sim/arm64 build` produces the BPF object and `make -C native-sim/arm64
  run` loads it (`load-only`, fd=4).
- Open AArch64 boundary after this increment: the load/store address and tag
  paths, the vector/`.D0`/`.Q0` paths, and native-byte equivalence. Both halves
  of the condition-to-next-PC relation (flag-based and compare-and-branch) are
  now proved against independent statements over the emitted domain; the
  remaining bridge is from this predicate level to the generator's actual
  `goto`/label emission, which the 30 recompiled artifacts exercise but do not
  formally relate.

### AArch64 move-wide insertion refinement, 2026-09-16

- Gap: the `MOVK` handler in `native-sim/arm64/arm64_sim_local_bpf.h` inlined a
  variable-shift mask/insert pair (`0xffffULL << shift`,
  `(dst & ~mask) | ((imm << shift) & mask)`) with no independent statement. MOVK
  is the largest remaining non-memory, non-control handler in the emitted
  subset: 184 sites at width 64 and 39 at width 32 across columns 16 (104
  sites), 32 (68) and 48 (51).
- Contract shape: the AArch64 `hw` field makes the insertion column one of the
  four architectural columns 0/16/32/48, so the contract is a four-element
  `MovkShift` enum rather than a free shift index. This is the same
  finite-domain pattern as the branch and conditional-select contracts, and it
  is what makes the refinement provable: `bv_decide` abstracts a symbolic
  barrel shift (`BitVec.extractLsb'`/`<<< s`) as opaque and cannot discharge a
  variable-shift MOVK (verified: it reports a spurious counterexample on both
  the pre-mask and post-mask forms), while the four-column case split closes
  every arm.
- Generator: `native-sim/formal/generate_arm64_movk_spec.py` reads
  `arm64_movk_spec.json` and emits `generated/arm64_movk.h`
  (`KPROG_ARM64_MOVK_INSERT(DST, IMM, SHIFT, UNSUPPORTED)`, a statement
  expression that resolves the column mask in a four-case switch with an
  explicit `default: UNSUPPORTED;`) and
  `KProgFormal/GeneratedArm64Movk.lean` (a self-contained
  `namespace GeneratedArm64Movk` with `inductive MovkShift`, `column` and
  `value`). `load()` re-reads `native-sim/arm64/arm64_sim.h` and exits 1 unless
  `ARM64_AUX_MOVK(S)` is still the `(((__u32)(S) & 0xffU) << 16)` form, so the
  contract's column set stays tied to the AUX encoding the shim reads back with
  `ARM64_SIM_L_SHIFT(AUX)`. It has a `--check` mode and a `make check` line.
- C wiring: `native-sim/arm64/arm64_sim_local_bpf.h` includes the generated
  header, gains `ARM64_SIM_L_MOVK_VALUE(DST, IMM, SHIFT)`, and the handler now
  delegates to it, keeping the width-narrowing register write. Behavior is
  unchanged for the four columns (the delegated expression is the same
  clear-then-insert), and `ARM64_SIM_L_READ_REG(DST)` is now evaluated exactly
  once.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64Movk.lean` proves
  `arm64_movk_refines` (the generated masked-shift insertion equals an
  independent statement that narrows the immediate with `&&& 0xffff` and shifts
  it into place, over all four columns), `arm64_movk_width_refines` (narrowing
  commutes), `arm64_movk_column_is_architectural` (the column is always one of
  0/16/32/48), `arm64_movk_column_dispatch`, and six `native_decide` examples
  (one per column, plus destination-preservation and immediate-narrowing). No
  `sorry`/`admit`. Both new modules are in the `KProgFormal.lean` root import
  list and both have `lean` lines in the Makefile.
- Lesson learned: a symbolic shift amount is the boundary of what `bv_decide`
  can do in this toolchain; the fix is to make the shift a finite architectural
  domain (here the four `hw` columns) and `cases` over it, exactly as the
  conditional-select and branch contracts do over their finite kind sets. A
  second lesson: an independent statement that keeps the immediate un-narrowed
  (`imm <<< s`) is not a valid architectural MOVK; the `&&& 0xffff` narrowing is
  what distinguishes the independent form from the generated one, so it is
  load-bearing rather than cosmetic.
- Host cross-check `native-sim/formal/test_arm64_movk_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it
  against an oracle that writes the destination into a byte array and overwrites
  the two bytes of the target halfword with the low two immediate bytes (never
  the macro's shift/mask pair). It sweeps a 6×6 destination/immediate table over
  all four columns, then a fixed-seed 20000-iteration LCG sweep (seed
  `0x0f1e2d3c4b5a6978`), then a `fork`/`waitpid` check that column `8` aborts
  with `SIGABRT` through the generated unsupported arm. Result:
  `OK (20145 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, and the arm64 movk host cross-check step;
  the csel step stays `OK (160161 cases)`, extrev `OK (120145 cases)`, branch
  `OK (80256 cases)`, mul `OK (160161 cases)`, bitfield `OK (126246 cases)`,
  mod `OK (225292 cases)`, ALU result `OK (120073 cases)`, flags
  `OK (60144 cases)`, x86 memory-access `OK (40020 cases)`). Mutation checks:
  changing a column in `arm64_movk_spec.json` makes `--check` exit 1; changing
  the `ARM64_AUX_MOVK` shift in `arm64_sim.h` makes `--check` report
  `ARM64_AUX_MOVK is not the expected … form` and exit 1; five independent
  semantic mutations of `generated/arm64_movk.h` (column-16 mask shift,
  column-32 mask shift, destination OR-ed instead of clear-then-set,
  destination complement dropped, unsupported column not aborting) each make the
  host cross-check exit 1 with a printed `MISMATCH`, while the pristine header
  stays `OK`. `make -C native-sim/arm64 micro-proofs-build` rebuilds all 30
  workload-derived artifacts, all `ok`; `make -C native-sim/arm64 build`
  produces the BPF object and `make -C native-sim/arm64 run` loads it
  (`load-only`, fd=4).
- Open AArch64 boundary after this increment: the load/store address and tag
  paths, the vector/`.D0`/`.Q0` paths, the ALU op-step register-lane
  compositions that remain hand-written, and native-byte equivalence.

### AArch64 shift-family refinement, 2026-09-16

- Gap: the `ARM64_OP_SHIFT_IMM`/`ARM64_OP_SHIFT_REG` handler in
  `native-sim/arm64/arm64_sim_local_bpf.h` dispatched to four hand-written
  helpers, `arm64_lsl`/`arm64_lsr`/`arm64_asr`/`arm64_ror` (plus
  `arm64_ror32`/`arm64_ror64`), with no independent statement. The shift table
  had only a decode contract (mnemonic -> `ARM64_SHIFT_*` code), which is the
  weakest remaining handler after MOVK.
- Contract shape: the shift family shares the `ARM64_SHIFT_*` codes with the
  decode table, so the shift contract is generated against that table rather
  than against raw opcodes. `generate_arm64_shift_spec.py` `load()` re-reads
  `arm64_decode_spec.json` and exits 1 unless the spec's `(mnemonic, macro,
  code)` rows still equal the decode table's `shift` rows, which keeps the Lean
  `Shift` codes and the C `case 0U..3U` tags pinned to one owner.
- Generator: `native-sim/formal/generate_arm64_shift_spec.py` reads
  `arm64_shift_spec.json` and emits `generated/arm64_shift.h`
  (`KPROG_ARM64_SHIFT_VALUE(SHIFT, VALUE, AMOUNT, WIDTH, UNSUPPORTED)`, a
  statement expression switching on the shift kind with an explicit
  `default: UNSUPPORTED;`) and `KProgFormal/GeneratedArm64Shift.lean` (a
  self-contained `namespace GeneratedArm64Shift` with `value`, `code`,
  `mnemonic`). It has a `--check` mode and a `make check` line. The C rotations
  are inlined exactly as the modifier contract inlines its rotate, so the
  translated header calls no hand-written helper; it includes `arm64_width.h`
  for `ARM64_WIDTH_32` and `KPROG_ARM64_WIDTH_MASK` so it is standalone.
- C wiring: `arm64_sim_local_bpf.h` includes the generated header, gains
  `ARM64_SIM_L_SHIFT_VALUE(KIND, VALUE, AMOUNT, WIDTH)`, and the handler now
  delegates to it, keeping the width-narrowing register write. The six
  hand-written helpers were then dead (each had exactly the one handler call
  site) and were deleted from `arm64_sim.h` (`arm64_apply_width` stays; it has
  other callers).
- Lean bridge: `native-sim/formal/KProgFormal/Arm64Shift.lean` proves
  `arm64_shift_refines` (the generated form equals an independent statement over
  all four kinds and both widths), `arm64_shift_amount_masked` (only the low
  amount bits matter), `arm64_shift_code_in_range`, `arm64_shift_code_dispatch`,
  and six `native_decide` examples. No `sorry`/`admit`.
- The independent statement is not a restatement of the generated one. LSL masks
  the operand before the shift (the mask commutes out); LSR masks the shifted
  operand by the shifted mask (`mask >>> k`) instead of masking first; ASR uses
  the sign-corrected `(v ^^^ sign) - sign` form then `sshiftRight'`; ROR is
  stated as the left-complement rotation `(v <<< (w - k)) ||| (v >>> k)` while
  the generated form writes the right rotation. Each is a structurally different
  expression that `bv_decide` closes against the generated arms.
- Lesson learned (extends the MOVK lesson): a symbolic shift *amount* is fine
  for `bv_decide` when it stays a `BitVec` and the mask is explicit, but
  Lean's `<<<`/`>>>` with a `BitVec` amount is **not** hardware-masked, and
  stating a rotate through `BitVec.rotateRight (k &&& 63).toNat` gets abstracted
  as an opaque variable (spurious counterexample). The provable form keeps the
  amount as a `BitVec` in both sides and writes rotation as a shift pair, which
  is why the independent ROR arm is also a shift pair (its distinctness comes
  from the left-complement ordering, not from `rotateRight`).
- Host cross-check `native-sim/formal/test_arm64_shift_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it
  against an oracle written against a byte/width model (masked amount, explicit
  width mask, arithmetic shift in the width's signed domain, right rotation of
  the `bits`-wide word). It sweeps an 8-value x 8-amount x 2-width x 4-kind
  boundary table, then a fixed-seed 20000-iteration LCG sweep (seed
  `0x51f3a7c2d9e40b68`), then a `fork`/`waitpid` check that kind `4` aborts with
  `SIGABRT`. **The oracle found two real bugs before commit**: the first ROR C
  draft left the result at 0 for a 64-bit rotate by amount 0 (missing `else`),
  and the oracle initially (wrongly) masked the ASR-32 result — the contract
  sign-extends into the high bits and the caller's width write narrows, so the
  oracle was corrected to match the architectural contract. Final result:
  `OK (20513 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, and the shift host cross-check step; the
  movk step stays `OK (20145 cases)`, branch `OK (80256 cases)`). Mutation
  checks: changing a code in `arm64_shift_spec.json` or in
  `arm64_decode_spec.json`'s `shift` table makes `--check` exit 1 with the
  expected drift message; six independent semantic mutations of
  `generated/arm64_shift.h` (wrong 32-bit amount mask, LSR shift direction,
  ASR as an unsigned shift, wrong 32-bit rotation width, short 64-bit rotation,
  unsupported kind not aborting) each make the host cross-check exit 1 with a
  printed `MISMATCH`, while the pristine header stays `OK`.
  `make -C native-sim/arm64 micro-proofs-build` rebuilds all 30 workload-derived
  artifacts, all `ok`; `make -C native-sim/arm64 build` produces the BPF object
  and `make -C native-sim/arm64 run` loads it.
- Open AArch64 boundary after this increment: the load/store address and tag
  paths, the vector/`.D0`/`.Q0` paths, the ALU op-step register-lane
  compositions that remain hand-written, and native-byte equivalence.

### AArch64 byte-lane reduction refinement, 2026-09-16

- Gap: the vector-register lane reductions `ARM64_OP_CNT` and `ARM64_OP_UADDLV`
  in `native-sim/arm64/arm64_sim_local_bpf.h` called two hand-written helpers,
  `arm64_replicate_byte_popcounts` and `arm64_horizontal_add_u8`, with no
  independent statement. These are the last two hand-written value helpers in
  the AArch64 emitted handler after the shift-family increment.
- Contract shape: both reductions are byte-lane folds over the eight bytes of
  the 64-bit value, so the contract is stated over the byte lanes and carries
  the `ARM64_OP_CNT`/`ARM64_OP_UADDLV` numbers, which `load()` re-checks against
  `native-sim/arm64/arm64_sim.h`.
- Generator: `native-sim/formal/generate_arm64_reduction_spec.py` reads
  `arm64_reduction_spec.json` and emits `generated/arm64_reduction.h`
  (`KPROG_ARM64_REDUCTION_VALUE(OP, VALUE, UNSUPPORTED)`, a statement
  expression switching on the opcode with an explicit `default: UNSUPPORTED;`)
  and `KProgFormal/GeneratedArm64Reduction.lean` (a self-contained namespace
  with `Reduction`, `popCountBits`, `code`, `mnemonic`, `value`). It has a
  `--check` mode and a `make check` line. The popcount is written out per byte
  (mask and `popcountll`) so the translated macro calls no hand-written helper.
- C wiring: `arm64_sim_local_bpf.h` includes the generated header, gains
  `ARM64_SIM_L_REDUCTION_VALUE(OP, VALUE)`, and the `CNT`/`UADDLV` handlers now
  delegate to `KPROG_ARM64_REDUCTION_HANDLED`/the macro. The two helpers were
  then dead and were deleted from `arm64_sim.h`.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64Reduction.lean` proves
  `arm64_reduction_refines` (the generated value equals an independent byte-lane
  statement for both reductions), `arm64_reduction_code_in_range`, the CNT lane
  bound (every replicated popcount is at most 8, so lanes never carry into each
  other), the UADDLV bound (< 2048), and four `native_decide` examples. No
  `sorry`/`admit`.
- Independence: the generated CNT uses `extractLsb'` on each byte and ORs the
  replicated popcounts; the independent CNT walks the eight bits of each byte
  with masks and shifts (`(v >>> (8b+j)) &&& 1`) and ORs them, a different
  extraction. The generated UADDLV is a left-associated sum; the independent
  form is a right-associated sum (the associativity is itself part of what the
  proof establishes).
- Lesson learned: this toolchain's Mathlib-free Lean has no `BitVec.popCount`,
  so a popcount contract must be built additively from bits; `bv_decide` closes
  those additive byte models (including the bit-trick SWAR form) without
  difficulty. Also, a single `switch` whose arms both declared the accumulator
  broke the host compile (`redefinition`), so the accumulator is declared once
  before the switch and reset per arm.
- Host cross-check `native-sim/formal/test_arm64_reduction_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it
  against an oracle that walks the eight bits of each byte lane directly. It
  sweeps an 8-value x 2-op boundary table, then a fixed-seed 20000-iteration LCG
  sweep (seed `0x7c3e9d15a2b8064f`), then a `fork`/`waitpid` check that an
  unsupported opcode (0) aborts with `SIGABRT`. Result: `OK (20017 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, and the reduction host cross-check step;
  shift `OK (20513 cases)`, movk `OK (20145 cases)`). Mutation checks: changing
  a code in `arm64_reduction_spec.json` makes `--check` exit 1; five independent
  semantic mutations of `generated/arm64_reduction.h` (CNT lane-3 source byte,
  CNT lane-6 result byte, UADDLV dropping the top byte, UADDLV wrong lane shift,
  unsupported opcode not aborting) each make the host cross-check exit 1 with a
  printed `MISMATCH`, while the pristine header stays `OK`.
  `make -C native-sim/arm64 micro-proofs-build` rebuilds all 30 workload-derived
  artifacts, all `ok`; `make -C native-sim/arm64 build`/`run` produce and load
  the BPF object.
- Open AArch64 boundary after this increment: the load/store address and tag
  paths, the vector/`.D0`/`.Q0` paths, and native-byte equivalence. All the
  hand-written scalar value helpers in the emitted AArch64 handler are now gone.

### Default-policy kop environment prerequisite resolved, 2026-09-16

- The `kop` step's load-time failure was an LLVM-backend prerequisite, and it is
  now built. `llvm-backend/build-bpf-kop` (the fork carrying
  `lib/Target/BPF/BPFKopSelect.cpp` and the `-bpf-enable-kop-select` /
  `-bpf-kop-mode` options) had only four static libraries; `ninja -C
  llvm-backend/build-bpf-kop -j12` completed the full build (2116/2116 targets,
  exit 0, 124 static libs including `libLLVMBPFCodeGen.a` and the
  `lib/cmake/llvm/LLVMConfig.cmake` package).
- Building `bpfopt` against it works: `cmake -S bpfopt/llvm -B <build>
  -DLLVM_DIR=/workspaces/repository/llvm-backend/build-bpf-kop/lib/cmake/llvm`
  configures and builds (exit 0), and the resulting `bpfopt` recognizes
  `-bpf-enable-kop-select` (previously the system LLVM-18 build reported
  `Unknown command line argument '-bpf-enable-kop-select'`). `runner/mk/build.mk`
  already points `BPFOPT_LLVM_BUILD_X86` at `bpfopt/llvm/build-kop` and takes
  `RUNNER_LLVM_DIR` from `LLVM_DIR`/`RUN_LLVM_DIR`, so the default policy can be
  enabled by building the fork and setting `LLVM_DIR` to its `lib/cmake/llvm`
  (no repository change required).
- Remaining work to exercise the default corpus policy: rebuild the runtime
  image with the fork-LLVM `bpfopt` and re-run
  `BPFREJIT_BENCH_PASSES="default" make corpus` (the separate `map_inline`
  overlay fix and the `VMLINUX_BTF` framework-kernel override already apply).
- The default corpus policy now runs the fork-LLVM `bpfopt` and reaches `kop`
  end to end. With the runtime image rebuilt from the fork-LLVM `bpfopt`,
  `BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=10` (framework-kernel
  `VMLINUX_BTF`, `LLVM_DIR=<fork>`) runs the `full-x86` group
  `[noop, map_inline, const_prop, dce, kop, wide_mem, bounds_check_merge,
  skb_load_bytes_spec, noop, const_prop, dce]` and `kop` now **applies 71 of 71
  matched sites** on `balancer_ingres` (xdp), shrinking it 2217 -> 2174
  instructions. Before this, `kop` aborted the app on the first program. The
  per-pass applied-site totals recorded in the run's load-time report are
  `noop: 3`, `map_inline: 16`, `const_prop: 1`, `dce: 1`, `kop: 71`.
- The `full-x86` policy then fails at `wide_mem`
  (`loadtime bpfopt step wide_mem failed` on `balancer_ingres`, after `kop`
  succeeded), so the two-start comparison still does not complete for the full
  group; the app exits before the workloads run. This is a new, more advanced
  failure point than the previous `kop` blocker and it is an optimizer-pass
  interaction (the `wide_mem` byte-ladder collapse on kop-modified bytecode),
  not a framework or measurement-validity issue. It is reproduced outside the VM
  on the balancer `.text`: `wide_mem` alone applies 1 site cleanly (224 -> 51
  insns), while `wide_mem` on `kop`-modified bytecode reports
  `Invalid offset 33 for movsx at pc 11` (the local reproduction uses a
  synthetic target map, so this is an indication, not the exact in-VM state).
  Running the same policy without `wide_mem` (i.e. through `kop`) is the next
  measurement to complete.
- **Completed two-start KVM corpus through `kop`, 2026-09-16.** Running the
  `full-x86` prefix without `wide_mem`,
  `BPFREJIT_BENCH_PASSES=noop,map_inline,const_prop,dce,kop`, exits 0 and writes
  `corpus/results/x86_kvm_corpus_20260916_172134_395628/` with suite
  `status: "completed"`, app `status: "ok"`, error empty, and
  `rejit_result.status: "ok"` over passes `[noop, map_inline, const_prop, dce,
  kop]`. Applied sites: `noop: 3`, `map_inline: 16`, `const_prop: 1`, `dce: 1`,
  `kop: 71`. This is the first completed two-start corpus in this workspace in
  which the `kop` koperation pass applies sites under the load-time contract.
- Raw `balancer_ingres` counters: baseline 169.00 ns/run
  (`run_cnt_delta = 26,174,496`), post-ReJIT 146.01 ns/run
  (`run_cnt_delta = 27,903,858`), ratio 0.864 (faster). Raw pktgen thread pps:
  baseline 894,064 + 869,262 + 857,649 = 2,620,975; post-ReJIT 929,288 +
  936,350 + 933,568 = 2,799,206; sum ratio 1.068. (The kvm host and container
  each contribute one non-transmitting pktgen control thread that sometimes
  reports 0 or a small count; those are excluded by dropping non-transmitter
  outliers, consistent with the earlier `map_inline` run's treatment.) Single
  sample, one app, one pass group: provenance plus a consistent direction, not a
  paper-grade speedup.
- Next: the `full-x86` group still fails at `wide_mem` on `kop`-modified
  bytecode. Diagnosing that interaction (the `wide_mem` byte-ladder collapse
  assuming pre-`kop` instruction shapes) would let the entire default group
  complete in one two-start comparison.
- Root cause of the `wide_mem` failure is now located precisely. Every
  non-kop-non-specialized pass (including `wide_mem`, `const_prop`, `dce`,
  `bounds_check_merge`, `skb_load_bytes_spec`) goes through
  `run_llvm_roundtrip` (`bpfopt/llvm/src/main.cpp` -> `run_llvm_roundtrip` in
  `bpfopt/llvm/src/llvm_mapinline.hpp`), which regenerates an LLVM module and
  re-extracts BPF text via the vendored `llvmbpf` compiler. That compiler
  handles BPF `MOV` with a nonzero `offset` as a sign-extending move and accepts
  only offsets 8/16/32; any other offset returns
  `"Invalid offset <n> for movsx at pc <pc>"` at
  `vendor/llvmbpf/src/compiler.cpp` (the `is_mov_sx` / `CreateSExt` chain). So
  the failure is the LLVM-roundtrip front end rejecting an instruction shape
  that the `kop` output (or the input the pass sees after `kop`) contains, not a
  measurement or framework problem. A faithful in-VM reproduction would need
  `KEEP_WORKDIRS=1` to retain `/tmp/loadtime_<pid>_5/step5.log`; the local
  reproduction is unreliable because it must supply a synthetic `--target` map.
- **Exact confirmation with retained workdirs.** Re-running the full `full-x86`
  group with `KEEP_WORKDIRS=1` retained
  `corpus/results/x86_kvm_corpus_20260916_180914_166297/details/loadtime-workdirs/loadtime_2792_5/`,
  whose `step5.log` reads exactly `error: Invalid offset -32623 for movsx at pc
  7`. `input.bin` in that workdir is the `kop` step's output (2174 instructions;
  `report.4.json` records `pass: kop, sites_applied: 71, insn_count_before:
  2217, insn_count_after: 2174`). Decoding it shows the failing word at pc 7 is
  `code=0xb7` (`BPF_MOV64_IMM`) with `off=-32623, imm=14`, immediately followed
  by `pc8 code=0x85` (`BPF_CALL`): this is a **kop koperation payload pair**
  (`MOV64_IMM` carrying the encoded payload + `CALL`), the wire form described
  by `read_kop_sidecar_payload`/`decode_kop_payload` in
  `bpfopt/llvm/src/main.cpp`. The `kop` pass itself knows this and bypasses the
  LLVM roundtrip when the input already carries kop calls
  (`if (kop_pass && count_kop_calls(input) > 0) output = input;`), but every
  other LLVM-roundtrip pass (`wide_mem`, `const_prop`, `dce`,
  `bounds_check_merge`, `skb_load_bytes_spec`) has no such guard, so running any
  of them on `kop` output feeds a kop payload word into `llvmbpf`'s `movsx`
  decoder and fails. This is a pass-ordering / kop-payload-awareness defect in
  the optimizer, not a measurement-validity issue: the `full-x86` group lists
  `kop` before `wide_mem`, which cannot work. The two viable fixes are (a) order
  `kop` after the pure-bytecode passes, or (b) make the pure-bytecode passes
  detect and preserve kop payload pairs. Verified alternative ordering
  (kop moved to the end of the group) is recorded with its own run.
- **Entire `full-x86` group completes with `kop` ordered last, 2026-09-16.**
  `BPFREJIT_BENCH_PASSES=noop,map_inline,const_prop,dce,wide_mem,
  bounds_check_merge,skb_load_bytes_spec,noop,const_prop,dce,kop` exits 0 and
  writes `corpus/results/x86_kvm_corpus_20260916_184607_120414/` with suite
  `status: "completed"`, app `status: "ok"`, error empty, and
  `rejit_result.status: "ok"` over all eleven passes. This confirms the
  ordering hypothesis: moving `kop` after the LLVM-roundtrip passes makes the
  whole group run, because the pure-bytecode passes then never see a kop payload
  word. Applied sites: `noop: 4`, `map_inline: 16`, `const_prop: 2`, `dce: 2`,
  `wide_mem: 1`, `bounds_check_merge: 1`, `skb_load_bytes_spec: 1`, `kop: 71`.
- Raw `balancer_ingres`: baseline 175.79 ns/run
  (`run_cnt_delta = 25,818,384`), post-ReJIT 146.95 ns/run
  (`run_cnt_delta = 28,317,888`), ratio 0.836 (faster); `bytes_xlated` 23,840 ->
  19,016 and `bytes_jited` 13,641 -> 11,545. Raw pktgen thread pps: baseline
  851,805 + 876,905 + 858,145 = 2,586,855; post-ReJIT 950,132 + 938,734 +
  949,317 = 2,838,183; sum ratio 1.097. Single sample, one app, eleven passes:
  provenance plus a consistent direction, not a paper-grade speedup.
- The ordering change was applied to the `full-x86` group in
  `corpus/config/benchmark_config.yaml` (`kop` moved to the end) and committed as
  `557a5af54`; the repository default now completes without a
  `BPFREJIT_BENCH_PASSES` override. The arm64 `full` group in the same file has
  the identical hazard (its `rotate`/`cond_select`/`extract`/`endian_fusion`/
  `ccmp`/`bulk_memory`/`prefetch` koperation passes precede `wide_mem`) and was
  deliberately left unchanged pending an arm64/KVM verification, since the
  reproduction here is x86. Reordering it the same way is the expected fix.
  The other alternative, making the pure-bytecode passes kop-payload-aware, is
  still open.

### AArch64 memory address-offset refinement, 2026-09-16

- Gap: `ARM64_SIM_L_MEM_BASE_OFF` in
  `native-sim/arm64/arm64_sim_local_bpf.h` computed the offset a load/store adds
  to its base register with an inline if/if-accumulate, the last hand-written
  value computation in the memory handler.
- Contract shape: the offset has two independent boolean inputs (pre/post-index,
  indexed or not) and is a 64-bit two's-complement accumulation, so the contract
  is a four-case table over `(prepost, hasIndex)` with `BitVec 64` addition.
- Generator: `native-sim/formal/generate_arm64_mem_offset_spec.py` reads
  `arm64_mem_offset_spec.json` and emits `generated/arm64_mem_offset.h`
  (`KPROG_ARM64_MEM_OFFSET(PREPOST, HAS_INDEX, IMM, INDEX)`) and
  `KProgFormal/GeneratedArm64MemOffset.lean` (`value` and an independent
  `valueSpec` case table). It has a `--check` mode and a `make check` line.
- C wiring: `arm64_sim_local_bpf.h` includes the generated header and
  `ARM64_SIM_L_MEM_BASE_OFF` now delegates, keeping the `(INDEX) !=
  ARM64_REG_NONE` guard for the source-modified index value. Behavior is
  unchanged for all four addressing forms.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64MemOffset.lean` proves
  `arm64_mem_offset_refines` (the generated form equals the independent case
  table over all four forms), `arm64_mem_offset_case_dispatch`, and
  `arm64_mem_offset_prepost_ignores_immediate`, plus three `native_decide`
  examples. No `sorry`/`admit`. A `signed-add == wrapping-add` theorem was
  drafted and removed: it is definitionally true for `BitVec` addition, so it
  added no information; the signed/wrapping equivalence is instead a property of
  the *host oracle*, which accumulates in `__int128` and truncates.
- Lesson learned: the C code adds `__s64` values, but signed two's-complement
  addition and 64-bit wrapping addition produce identical bits, so the contract
  is stated over `BitVec 64` and needs no sign model; `BitVec.ofInt`-based
  signed statements were not provable here (`bv_decide` abstracts
  `BitVec.ofInt 64 (a.toInt + b.toInt)`), confirming the wrapping formulation is
  the right one.
- Host cross-check `native-sim/formal/test_arm64_mem_offset_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it to an
  oracle that accumulates in `__int128` (a different expression tree). It sweeps
  a 2x2 x 7-imm x 6-index boundary table, then a fixed-seed 20000-iteration LCG
  sweep (seed `0x2b9d4c77e1a05f38`). Result: `OK (20168 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, mem-offset host cross-check step; reduction
  `OK (20017 cases)`). Mutation checks: changing a flag in
  `arm64_mem_offset_spec.json` makes `--check` exit 1; three independent semantic
  mutations of `generated/arm64_mem_offset.h` (pre/post keeps the immediate,
  index subtracted, index replaced by the immediate) each make the host
  cross-check exit 1 with a printed `MISMATCH`, while the pristine header stays
  `OK`. `make -C native-sim/arm64 micro-proofs-build` rebuilds all 30
  workload-derived artifacts, all `ok`; `make -C native-sim/arm64 build`/`run`
  produce and load the BPF object.
- Open AArch64 boundary after this increment: the remaining load/store tag paths
  (`ARM64_SIM_L_MEM_PRE`/`POST` writeback and the pointer-tag propagation), the
  vector/`.D0`/`.Q0` move paths (`ARM64_OP_FMOV`), and native-byte equivalence.

### AArch64 FMOV direction refinement, 2026-09-16

- Gap: the `ARM64_OP_FMOV` handler in
  `native-sim/arm64/arm64_sim_local_bpf.h` selected between the vector register
  `v0` and the general-purpose register with an inline two-branch if/else over
  the four `ARM64_FMOV_*` direction codes, with no independent statement.
- Contract shape: the direction is the only free choice, so the contract is a
  four-arm selection over the `ARM64_FMOV_D_FROM_X`/`X_FROM_D`/`S_FROM_W`/
  `W_FROM_S` codes, which `load()` re-checks against
  `native-sim/arm64/arm64_sim.h`.
- Generator: `native-sim/formal/generate_arm64_fmov_spec.py` reads
  `arm64_fmov_spec.json` and emits `generated/arm64_fmov.h`
  (`KPROG_ARM64_FMOV_VALUE(DIR, V0, SRC, UNSUPPORTED)`, a statement expression
  switching on the direction with an explicit `default: UNSUPPORTED;`) and
  `KProgFormal/GeneratedArm64Fmov.lean` (a self-contained namespace with
  `Fmov`, `code`, `mnemonic`, `writesReg`, `value`). It has a `--check` mode and
  a `make check` line.
- C wiring: `arm64_sim_local_bpf.h` includes the generated header, and the
  `ARM64_OP_FMOV` handler now computes the moved value through the macro and
  keeps the architectural split: the two vector-destination directions assign
  `v0`, the two register-destination directions write the destination register
  at the destination width.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64Fmov.lean` proves
  `arm64_fmov_refines` (the generated selection composed with the caller's width
  write equals an independent statement that narrows the selected value to the
  destination width), `arm64_fmov_code_in_range`,
  `arm64_fmov_direction_dispatch`, `arm64_fmov_vector_destination`,
  `arm64_fmov_register_destination`, and two `native_decide` examples (a
  D_FROM_X -> X_FROM_D round trip and a 32-bit W_FROM_S narrowing). No
  `sorry`/`admit`.
- Independence: the generated contract answers both questions from one arm (it
  returns the raw `v0`/`src` and defers width), while the independent statement
  is stated *after* the width write and is driven by a predicate (`dir =
  .x_from_d ∨ dir = .w_from_s`) rather than by enumeration. The refinement
  therefore has to relate the generated per-arm selection to a width-applied
  predicate form, not restate it.
- Host cross-check `native-sim/formal/test_arm64_fmov_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it to an
  oracle keyed off a separate `vector_destination[4]` table (never the macro's
  switch). It sweeps the 4 directions x 6 x 6 value pairs, then a fixed-seed
  20000-iteration LCG sweep (seed `0x4e8b1d63f2079ac5`), then a `fork`/`waitpid`
  check that direction `4` aborts with `SIGABRT`. Result: `OK (20145 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, fmov host cross-check step; mem offset
  `OK (20168 cases)`). Mutation checks: changing a code in
  `arm64_fmov_spec.json` makes `--check` exit 1; five independent semantic
  mutations of `generated/arm64_fmov.h` (each of the four direction arms
  selecting the wrong register, and the unsupported direction not aborting) each
  make the host cross-check exit 1 with a printed `MISMATCH`, while the pristine
  header stays `OK`. `make -C native-sim/arm64 micro-proofs-build` rebuilds all
  30 workload-derived artifacts, all `ok`; `make -C native-sim/arm64
  build`/`run` produce and load the BPF object.
- Open AArch64 boundary after this increment: the load/store pre/post-index
  writeback (`ARM64_SIM_L_MEM_PRE`/`POST`) and pointer-tag propagation, the
  `ARM64_SIM_L_MEM_READ`/`WRITE` tag-dispatch bodies, and native-byte
  equivalence. Every finite-selection handler in the emitted AArch64 dispatch is
  now generated.

### Default `make corpus` completes end to end, 2026-09-16

- With the `full-x86` ordering fix committed (`557a5af54`, `kop` moved after the
  LLVM-roundtrip passes), the repository default policy now completes with **no
  `BPFREJIT_BENCH_PASSES` override**:
  `BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=10 JOBS=8
  IMAGE_BUILD_JOBS=8 VMLINUX_BTF=<framework vmlinux> LLVM_DIR=<fork LLVM>
  make corpus` exits 0 and writes
  `corpus/results/x86_kvm_corpus_20260916_192529_199370/` with suite
  `status: "completed"` and app `status: "ok"`. The run reports all eleven
  passes `[noop, map_inline, const_prop, dce, wide_mem, bounds_check_merge,
  skb_load_bytes_spec, noop, const_prop, dce, kop]` with
  `rejit_result.status: "ok"`.
- Applied sites: `noop: 4`, `map_inline: 16`, `const_prop: 2`, `dce: 2`,
  `wide_mem: 1`, `bounds_check_merge: 1`, `skb_load_bytes_spec: 1`, `kop: 71`.
  Raw `balancer_ingres`: 170.86 ns/run (`run_cnt_delta = 26,219,225`) ->
  148.00 ns/run (`run_cnt_delta = 27,925,025`), ratio 0.866; `bytes_xlated`
  23,840 -> 19,016 and `bytes_jited` 13,641 -> 11,545. pktgen throughput
  2,626,908 -> 2,798,385 pps (ratio 1.065). Single sample, one app, eleven
  passes: provenance plus a consistent direction, not a paper-grade speedup.
- This closes the "default config must work" thread for the corpus suite on
  x86/KVM in this workspace: the remaining environment inputs are the fork-LLVM
  `bpfopt` (now built) and the framework-kernel `VMLINUX_BTF` (a documented host
  workaround for the `mm_struct::user_ns` drift).

### AArch64 byte-ladder load refinement, 2026-09-16

- Gap: `ARM64_SIM_L_LOAD_ADDR` in `native-sim/arm64/arm64_sim_local_bpf.h`
  assembled a little-endian byte/halfword/word/doubleword from memory with a
  hand-written width-gated ladder and no independent statement, the last
  hand-written value computation in the AArch64 memory path.
- Contract shape: the load width is one of the four `ARM64_WIDTH_*` codes, so
  the ladder has a closed byte-count set (1, 2, 4, 8) and no unsupported arm.
- Generator: `native-sim/formal/generate_arm64_load_bytes_spec.py` reads
  `arm64_load_bytes_spec.json` and emits `generated/arm64_load_bytes.h`
  (`KPROG_ARM64_LOAD_BYTES(ADDR, WIDTH)`, the unrolled width-gated ladder) and
  `KProgFormal/GeneratedArm64LoadBytes.lean` (a self-contained namespace with
  `LoadWidth`, `widthCode`, `byteCount`, `value`). It has a `--check` mode and a
  `make check` line.
- C wiring: `arm64_sim_local_bpf.h` includes the generated header and
  `ARM64_SIM_L_LOAD_ADDR` now delegates to the macro. The emitted ladder is the
  same unrolled byte-OR sequence as before, so the compiled shape is unchanged.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64LoadBytes.lean` proves
  `arm64_load_bytes_refines` (the generated lane assembly equals an independent
  *masked truncation* of the whole word, not a lane restatement),
  `arm64_load_bytes_width_dispatch`, `arm64_load_bytes_upper_cleared`, and three
  `native_decide` examples. No `sorry`/`admit`.
- Lesson learned: the independent statement for a byte ladder is `value &&&
  mask width`; the lane-by-lane OR and the mask truncation agree exactly because
  the lanes are disjoint, and `bv_decide` closes all four widths in one `cases`
  chain. Generating the C as an unrolled ladder (not a runtime loop) keeps the
  emitted BPF instruction shape identical to the hand-written form, which matters
  for the load path's verifier behavior.
- Host cross-check `native-sim/formal/test_arm64_load_bytes_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it to an
  oracle that assembles the in-range bytes through a byte pointer, plus a
  high-bytes-cleared invariant. It sweeps six byte patterns over all four widths,
  then a fixed-seed 20000-iteration LCG sweep on a heap buffer (seed
  `0x9a2f5c81e4b70d36`). Result: `OK (20024 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, load-bytes host cross-check step; fmov
  `OK (20145 cases)`). Mutation checks: changing a byte count in
  `arm64_load_bytes_spec.json` makes `--check` exit 1; four independent semantic
  mutations of `generated/arm64_load_bytes.h` (byte-2 lane shift, W64 gate
  widened, W16 gate widened, top byte dropped) each make the host cross-check
  exit 1 with a printed `MISMATCH`, while the pristine header stays `OK`.
  `make -C native-sim/arm64 micro-proofs-build` rebuilds all 30
  workload-derived artifacts, all `ok`; `make -C native-sim/arm64 build`/`run`
  produce and load the BPF object.
- Open AArch64 boundary after this increment: the remaining memory tag-dispatch
  bodies (`ARM64_SIM_L_MEM_READ`/`WRITE` tag selection, the pre/post-index
  writeback and pointer-tag propagation), the stack load/store
  (`ARM64_SIM_L_STACK_READ`/`WRITE*`), and native-byte equivalence.

- Follow-on de-duplication (same increment, 2026-09-16):
  `ARM64_SIM_L_STACK_READ`'s non-qword branch repeated the byte ladder
  byte-for-byte over `__a64_stack.b[]`. It now calls
  `KPROG_ARM64_LOAD_BYTES(&__a64_stack.b[__a64_str_index], width)`, so the stack
  ladder is covered by the same refined contract as the memory ladder and the
  duplicated code is gone (14 lines removed, 4 added). `make -C
  native-sim/arm64 micro-proofs-build` rebuilds all 30 artifacts, all `ok`;
  `build`/`run` produce and load the BPF object.

### Default policy across all six apps, 2026-09-16

- With the default `full-x86` policy
  (`SAMPLES=1 WORKLOAD_DURATION=10`, framework-kernel `VMLINUX_BTF`,
  fork-LLVM `LLVM_DIR`) the full six-app sweep
  (`corpus/results/x86_kvm_corpus_20260916_214505_768159/`, `CORPUS_EXIT 0`)
  completes with **two apps `status: "ok"`** under the all-passes policy:
  - `katran`: `status: ok`; applied sites `noop: 4`, `map_inline: 16`,
    `const_prop: 2`, `dce: 2`, `wide_mem: 1`, `bounds_check_merge: 1`,
    `skb_load_bytes_spec: 1`, `kop: 71`; `balancer_ingres` 169.58 -> 146.87
    ns/run (ratio 0.866).
  - `bcc/set`: `status: ok`; the multi-program BCC bundle applies
    `noop: 55`, `map_inline: 60`, `const_prop: 28`, `dce: 26`, `wide_mem: 13`,
    `bounds_check_merge: 13`, `skb_load_bytes_spec: 13`, `kop: 72` across its
    thirteen BPF programs (`sys_enter`/`sys_exit` tracepoints,
    `sched_switch`/`sched_wakeup` tracepoints, `kprobe__cap_cap`,
    `fentry_vfs_*`, `block_rq_*`). Per-program raw `run_time_ns_delta /
    run_cnt_delta` for the high-run programs: `sys_enter` 78.11 -> 77.91,
    `sys_exit` 85.04 -> 84.71, `sched_switch` 111.73 -> 112.70,
    `sched_wakeup` 92.23 -> 89.38, `kprobe__cap_cap` (first) 62.54 -> 60.89.
    This is the broadest completed all-passes run so far: one app is XDP and one
    is a thirteen-program tracing bundle.
- The other four apps fail at their own application startup, before the shim
  tracks their programs, and are raw failures unrelated to the optimizer
  ordering: `cilium/agent` (`Cilium API PUT /v1/endpoint/0 returned HTTP 500:
  "timeout while waiting for initial endpoint generation to complete"`),
  `otelcol-ebpf-profiler/profiling` (`native app exited before BPF programs were
  tracked by shim`), `tetragon/observer` (`Tetragon exited before BPF programs
  were tracked by shim`), `tracee/monitor` (`failed to launch Tracee`). These
  match the pre-existing app-startup failures recorded earlier and are not
  measurement-validity gates.

### AArch64 byte-lane scatter refinement, 2026-09-16

- Gap: the stack byte scatter in `ARM64_SIM_L_STACK_WRITE_TAG`
  (`native-sim/arm64/arm64_sim_local_bpf.h`) extracted each byte lane with an
  inline `(__u8)(value >> 8*i)` expression, the mirror of the load ladder and
  the last hand-written per-byte extraction in the AArch64 memory path.
- Contract shape: the eight lanes are the closed set the scatter uses, so the
  contract is an eight-way lane enumeration with the shift `8*lane`.
- Generator: `native-sim/formal/generate_arm64_byte_lane_spec.py` reads
  `arm64_byte_lane_spec.json` and emits `generated/arm64_byte_lane.h`
  (`KPROG_ARM64_BYTE_AT(LANE, VALUE, UNSUPPORTED)`, an eight-case switch
  resolving the lane shift, `default: UNSUPPORTED;`) and
  `KProgFormal/GeneratedArm64ByteLane.lean` (a self-contained namespace with
  `ByteLane`, `index`, `shift`, `byteAt`). It has a `--check` mode and a
  `make check` line. A `KPROG_ARM64_BYTE_AT_HANDLED` predicate was drafted and
  removed before commit because nothing called it (no dead code).
- C wiring: `arm64_sim_local_bpf.h` includes the generated header and the stack
  scatter now calls `KPROG_ARM64_BYTE_AT(i, value, ...)` for each lane. Every
  call site passes a constant lane, so clang folds each switch to a single
  shift; the emitted `arm64_sim_hardcoded.bpf.o` is **byte-identical** to the
  pre-change object (same 11,168-byte size, `.text` disassembly diff shows only
  the filename header), and `make -C native-sim/arm64 run` still loads it.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64ByteLane.lean` proves
  `arm64_byte_lane_refines` (the generated shift-then-narrow equals an
  independent mask-shift form), `arm64_byte_lane_shift_dispatch`,
  `arm64_byte_lane_load_inverse`, and two `native_decide` examples. No
  `sorry`/`admit`.
- Strongest content — `arm64_byte_lane_load_inverse`: it proves the eight-lane
  byte-lane scatter reassembles exactly the **generated load contract's** value
  for all four load widths, i.e. the extraction side and the assembly side of
  the little-endian ladder are formally inverse on the emitted domain. This ties
  two separately generated contracts together rather than proving each in
  isolation.
- Lesson learned: `native_decide` caught a wrong canonical example during
  development (lane 2 of `0x0123456789abcdef` is `0xab`, not the `0xcd` typed by
  hand); the tactic verified the corrected statement. Also, an inverse theorem
  between two generated contracts is provable in one `cases width` chain with
  `bv_decide`, so cross-contract composition does not need a shared
  intermediate definition.
- Host cross-check `native-sim/formal/test_arm64_byte_lane_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra` and compares it to an
  oracle that reads the lane through the value's byte view (never the macro's
  shift). It sweeps seven boundary words over all eight lanes, then a fixed-seed
  20000-iteration LCG sweep (seed `0xc4a1f70e95d3826b`), then a `fork`/`waitpid`
  check that lane `8` aborts with `SIGABRT`. Result: `OK (20057 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, byte-lane host cross-check step; load bytes
  `OK (20024 cases)`). Mutation checks: changing a lane index in
  `arm64_byte_lane_spec.json` makes `--check` exit 1; four independent semantic
  mutations of `generated/arm64_byte_lane.h` (lane-0/3/5 shift and unsupported
  lane not aborting) each make the host cross-check exit 1 with a printed
  `MISMATCH`, while the pristine header stays `OK`. `make -C native-sim/arm64
  micro-proofs-build` rebuilds all 30 workload-derived artifacts, all `ok`.
- Open AArch64 boundary after this increment: the memory tag-dispatch bodies
  (`ARM64_SIM_L_MEM_READ`/`WRITE` tag selection, pre/post-index writeback and
  pointer-tag propagation), the stack pointer helper, and native-byte
  equivalence.

### AArch64 memory tag-dispatch refinement, 2026-09-16

- Gap: `ARM64_SIM_L_MEM_READ_TAG` in `native-sim/arm64/arm64_sim_local_bpf.h`
  classified a load by the base register's memory space (stack / ABI /
  reloc-address / ordinary) and the access width with an inline `if/else` chain
  that had no independent statement, and `ARM64_SIM_L_MEM_READ`'s value-source
  selection had the same shape without its own contract.
- Contract shape: the classification is a closed table over the four memory
  spaces and the two width cases (32/64), so each predicate is total and has no
  unsupported arm. The ABI packet tag itself stays in the already-generated
  `KPROG_ABI_LOAD_TAG`; this contract selects *which* tag source applies.
- Generator: `native-sim/formal/generate_arm64_mem_dispatch_spec.py` reads
  `arm64_mem_dispatch_spec.json` and emits `generated/arm64_mem_dispatch.h`
  (`KPROG_ARM64_MEM_READ_SRC` / `KPROG_ARM64_MEM_READ_TAG`, each a total
  predicate returning a `KPROG_ARM64_MEM_SRC_*` / `KPROG_ARM64_MEM_TAG_*`
  selector, plus the selector constants) and
  `KProgFormal/GeneratedArm64MemDispatch.lean` (a namespace with `Space`,
  `ValueSrc`, `ResultTag` and the two exhaustive tables). It has a `--check`
  mode and a `make check` line. The tag macro names come from the spec
  (`tag_macro`, e.g. `ARM64_SIM_TAG_RELOC_ADDR`), so the generator does not
  guess the C constant names.
- C wiring: `arm64_sim_local_bpf.h` includes the generated header and
  `ARM64_SIM_L_MEM_READ_TAG` now switches on
  `KPROG_ARM64_MEM_READ_TAG(sp, tag, width)`, with the four cases performing
  exactly the operations the chain did (stack helper, `KPROG_ABI_LOAD_TAG`,
  reloc map-pointer with the zero-offset check, scalar default). The emitted
  `xdp` program section is byte-identical to the pre-change object (both
  16 bytes), and `make -C native-sim/arm64 run` still loads it. The value-source
  predicate is generated and available for the `MEM_READ` body; its
  field-projection refinement is proved even though the read body still uses its
  own chain (recorded as the remaining wiring).
- Lean bridge: `native-sim/formal/KProgFormal/Arm64MemDispatch.lean` proves
  `arm64_mem_dispatch_src_refines` and `arm64_mem_dispatch_tag_refines` (each
  generated table equals an independent **predicate-nesting** statement, not a
  table restatement), `arm64_mem_dispatch_no_widening` (off width 64 only the
  stack space changes the selection — the property the C chain's later
  width-64 gates rely on), `arm64_mem_dispatch_stack_width_independent`, and
  `arm64_mem_dispatch_reloc`. No `sorry`/`admit`.
- Host cross-check `native-sim/formal/test_arm64_mem_dispatch_host.c`: compiles
  the generated predicates with zero warnings under `-Wall -Wextra` and compares
  them to an independent predicate-nesting oracle over **every** (is_sp, tag,
  width) combination (2 x 9 x 4 = 72), also asserting the two classifications
  select the same space family. Result: `OK (72 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, mem-dispatch host cross-check step; byte
  lane `OK (20057 cases)`). Mutation checks: changing a space's `w64_only` flag
  in `arm64_mem_dispatch_spec.json` makes `--check` exit 1; four independent
  semantic mutations of `generated/arm64_mem_dispatch.h` (source ABI width gate
  dropped, tag stack space mapped to scalar, reloc tag mapped to the ABI family,
  source normal fallback mapped to reloc) each make the host cross-check exit 1
  with a printed `MISMATCH`, while the pristine header stays `OK`.
  `make -C native-sim/arm64 micro-proofs-build` rebuilds all 30
  workload-derived artifacts, all `ok`; `build`/`run` produce and load the BPF
  object.
- Follow-on wiring (same increment, 2026-09-16, committed `695c946e5`):
  `ARM64_SIM_L_MEM_READ`'s value-source body now also switches on
  `KPROG_ARM64_MEM_READ_SRC`, so both halves of the dispatch (value source and
  result tag) are driven by the generated, refined classification and neither
  predicate is dead. The emitted `xdp` program section stays byte-identical to
  the pre-change object, `build`/`run` load the object, and the full formal
  check and the 30 micro proofs remain green.
- Open AArch64 boundary after this increment: the pre/post-index writeback and
  pointer-tag propagation, the stack pointer helper, `ARM64_SIM_L_STACK_READ_TAG`
  and `ARM64_SIM_L_STACK_WRITE`'s selection (byte-ladder part is already the
  generated load contract), and native-byte equivalence.

### AArch64 stack slot-tag refinement, 2026-09-16

- Gap: `ARM64_SIM_L_STACK_READ_TAG` and the tag-slot gate in
  `ARM64_SIM_L_STACK_WRITE_TAG` (`native-sim/arm64/arm64_sim_local_bpf.h`)
  decided with an inline `width == 64 && (index & 7) == 0` conjunction whether a
  stack slot carries its stored tag, with no independent statement.
- Contract shape: the two conditions (access is 64-bit, slot is qword-aligned)
  are a closed pair, so the contract is a four-case classification plus the
  selection predicate; the predicate is total.
- Generator: `native-sim/formal/generate_arm64_stack_tag_spec.py` reads
  `arm64_stack_tag_spec.json` and emits `generated/arm64_stack_tag.h`
  (`KPROG_ARM64_STACK_TAG(IS_W64, IS_ALIGNED)`) and
  `KProgFormal/GeneratedArm64StackTag.lean` (a namespace with `Case`,
  `classify`, `tagged`, and an independent `taggedSpec` conjunction). It has a
  `--check` mode and a `make check` line.
- C wiring: `arm64_sim_local_bpf.h` includes the generated header; the stack
  read tag now selects on the predicate, and the stack write's slot-tag gate
  uses it too. The emitted `xdp` program section stays byte-identical to the
  pre-change object and `build`/`run` load the object.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64StackTag.lean` proves
  `arm64_stack_tag_classify_total`, `arm64_stack_tag_refines` (classify-then-
  table equals the independent `isW64 && isAligned` conjunction),
  `arm64_stack_tag_dispatch`, and `arm64_stack_tag_unaligned_never`. No
  `sorry`/`admit`.
- Lesson learned: Lean's equation-style `def f (a b : Bool) : C | p, q => ...`
  does **not** elaborate for a two-binder non-recursive definition here
  (`expected type Case` error); the working form is `def f (a b : Bool) : C :=
  match a, b with | ...`. Also, a constructor named `of` collides with Lean core
  notation — `classify` is used instead. Arm order is right-to-left (last binder
  varies fastest), which matters for naming the cases correctly.
- Host cross-check `native-sim/formal/test_arm64_stack_tag_host.c`: compiles the
  generated predicate with zero warnings under `-Wall -Wextra` and compares it
  to a plain-conjunction oracle over four widths x eight offsets plus the four
  explicit combinations. Result: `OK (36 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, stack-tag host cross-check step; mem dispatch
  `OK (72 cases)`). Mutation checks: changing the tagged flag in
  `arm64_stack_tag_spec.json` makes `--check` exit 1; four independent mutations
  of `generated/arm64_stack_tag.h` (OR instead of AND, alignment dropped, width
  dropped, result inverted) each make the host cross-check exit 1 with a printed
  `MISMATCH`, while the pristine header stays `OK`. `make -C native-sim/arm64
  micro-proofs-build` rebuilds all 30 workload-derived artifacts, all `ok`.
- `make micro BENCH=simple` note: the suite currently stops in
  `host-native-bpf-x86` (upstream tetragon `_(&mm->user_ns)` against the host
  7.3.0-rc3 BTF), the same pre-existing host-BTF drift the corpus runs work
  around with `VMLINUX_BTF=<framework vmlinux>`. The override was passed and the
  failure is unchanged, so it is a build-graph prerequisite (the x86 native rule
  does not take the override through to `vendor/bpf`) rather than a measurement
  gate; the micro-proofs step itself passes.
- Open AArch64 boundary after this increment: the pre/post-index writeback and
  pointer-tag propagation, the stack pointer helper, and native-byte
  equivalence.

### x86 ROR result refinement, 2026-09-17

- Gap: `x86_ror` in `native-sim/x86/x86_sim.h` implemented the right-rotate used
  by the `RORX`/`RORX_MEM` handlers (and `x86_alu_result` has no ROR arm, so it
  is the only x86 right-rotate path) with an inline shift pair and no
  independent statement. The generated x86 shift-result contract covered
  SHL/SHR/SAR/ROL but not ROR.
- Contract: `generate_x86_shift_result_spec.py` now emits
  `GeneratedX86ShiftResult.ror` (the mirror of the generated `rol`) and
  `kprog_x86_ror_result` in `generated/x86_shift_result.h`, and
  `x86_shift_result_spec.json` lists `ror` in `operations`.
- C wiring: `x86_ror` is now a one-line delegation to
  `kprog_x86_ror_result`, matching how `x86_alu_result` already delegates
  SHL/SHR/SAR/ROL to the generated functions.
- Lean bridge: `native-sim/formal/KProgFormal/X86ShiftResult.lean` proves
  `x86_ror_result_refines` and two `native_decide` examples. No `sorry`/`admit`.
- Independence: the spec is `x86RorResultSpec`, which states x86 ROR as **the
  generated `rol` applied at the complementary count `bits - k`** — the defining
  identity of a right rotate — rather than mirroring the generated shift pair.
  That makes the theorem a cross-operation statement (`ror` vs the already
  generated `rol`) and, in the host cross-check, doubles as an executable
  invariant (`ror(v,k) == rol(v, w-k)`) checked on every one of the 20,320
  cases, not just asserted once.
- Host cross-check `native-sim/formal/test_x86_ror_result_host.c`: this is the
  first host test that compiles `generated/x86_shift_result.h` (the only
  generated header that defines `__always_inline` functions), so it supplies the
  attribute for the host build. It compares the generated function to an oracle
  that rebuilds each destination bit from source bit `(i + k) mod w` (never the
  macro's shift pair). It sweeps 8 operands x 10 shifts x 4 widths, then a
  fixed-seed 20000-iteration LCG sweep (seed `0x3f8c2ea97164b0d5`). Result:
  `OK (20320 cases)`.
- Verification: full `make -C native-sim/formal check` green (new host-test step
  in the `check` target; arm64 steps unchanged). Mutation checks: dropping `ror`
  from `x86_shift_result_spec.json` makes `--check` exit 1; four independent
  mutations of the generated ROR function (shift direction flipped, complementary
  count off by one, count mask widened, operand not narrowed) each make the host
  cross-check exit 1 with a printed `MISMATCH`, while the pristine header stays
  `OK`. `make -C native-sim/x86 micro-proofs-build` rebuilds all 30
  workload-derived artifacts, all `ok`; `make -C native-sim/x86 build`/`run`
  produce and load the object.
- Open x86 proof surface after this increment: `x86_bswap`, `x86_popcount64`,
  `x86_shld`/`x86_shrd`, `x86_sign_extend`, `x86_signed_abs_width`, the
  objdump/parser-to-AUX relation, and native-byte correspondence.

### x86 BSWAP byte-reversal refinement, 2026-09-17

- Gap: `x86_bswap` in `native-sim/x86/x86_sim.h` implemented the byte reversal
  used by the `BSWAP`, `MOVBE_LOAD`, and `MOVBE_STORE` handlers (three call
  sites) with an inline mask/shift ladder and no independent statement.
- Contract: `native-sim/formal/generate_x86_bswap_spec.py` reads
  `x86_bswap_spec.json` and emits `generated/x86_bswap.h`
  (`kprog_x86_bswap_value`) and `KProgFormal/GeneratedX86Bswap.lean`. It has a
  `--check` mode and a `make check` line.
- C wiring: `x86_sim.h` includes the generated header and `x86_bswap` is now a
  one-line delegation. (The edit initially merged the helper's closing brace
  into `x86_popcount64`; the region was repaired and `x86_popcount64` restored
  verbatim before the build.)
- Lean bridge: `native-sim/formal/KProgFormal/X86Bswap.lean` proves
  `x86_bswap_refines` (the generated ladder equals an independent per-byte
  **lane-extraction** assembly), `x86_bswap_involutive` (applying the reversal
  twice restores the width-masked value), `x86_bswap_w32_clears_high`, and three
  `native_decide` examples. No `sorry`/`admit`.
- Independence: the generated form is a mask-and-shift ladder over the raw word;
  the spec extracts each source byte as an `extractLsb'` lane and re-places it in
  reverse lane order, sharing no mask constants with the generated form. The
  involution theorem is a property the ladder form does not state and is checked
  executably in the host cross-check on every case.
- Host cross-check `native-sim/formal/test_x86_bswap_host.c`: compiles the
  generated function with zero warnings under `-Wall -Wextra`, compares it to an
  oracle that reverses the width's bytes through a byte array, and asserts both
  the width invariant (no byte above the width survives) and involution. It
  sweeps seven boundary words over all four widths, then a fixed-seed
  20000-iteration LCG sweep (seed `0x1a6f83c2d50947be`). Result:
  `OK (20028 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, bswap host cross-check step; the x86 ROR step
  still `OK (20320 cases)`). Mutation checks: changing a width's byte count in
  `x86_bswap_spec.json` makes `--check` exit 1; four independent mutations of
  `generated/x86_bswap.h` (64-bit lane-0 not moved, 64-bit lane-1 to the wrong
  lane, 32-bit case not shifted down, 16-bit case wrong shift) each make the host
  cross-check exit 1 with a printed `MISMATCH`, while the pristine header stays
  `OK`. A fifth candidate mutation (`& 0xff00` widened to `& 0xffff` in the
  16-bit arm) was confirmed semantically equivalent and rejected as a mutation,
  not a coverage gap. `make -C native-sim/x86 micro-proofs-build` rebuilds all 30
  workload-derived artifacts, all `ok`; `build`/`run` produce and load the
  object.
- Open x86 proof surface after this increment: `x86_popcount64`,
  `x86_shld`/`x86_shrd`, `x86_sign_extend`, `x86_signed_abs_width`, the
  objdump/parser-to-AUX relation, and native-byte correspondence.

### x86 signed-value refinement (sign extension and magnitude), 2026-09-17

- Gap: `x86_sign_extend` (six call sites) and `x86_signed_abs_width` (the two
  IMUL-magnitude operands, `native-sim/x86/x86_sim.h`) implemented the width
  sign extension and the width-domain magnitude with inline width `if` chains
  and no independent statements.
- Contract: `native-sim/formal/generate_x86_signed_spec.py` reads
  `x86_signed_spec.json` and emits `generated/x86_signed.h`
  (`kprog_x86_sign_extend_value`, `kprog_x86_abs_width_value`) and
  `KProgFormal/GeneratedX86Signed.lean`. It has a `--check` mode and a
  `make check` line.
- C wiring: `x86_sim.h` includes the generated header and both helpers are
  one-line delegations.
- Lean bridge: `native-sim/formal/KProgFormal/X86Signed.lean` proves
  `x86_sign_extend_refines` and `x86_abs_width_refines` (each generated form
  equals an independent statement: `BitVec.signExtend` of the narrowed low lane,
  and a negate-then-narrow magnitude, neither sharing the generated
  complement-and-subtract form), `x86_abs_width_idempotent`,
  `x86_abs_width_bounded` (the magnitude never exceeds the width's sign mask,
  via `BitVec.ule`), and three `native_decide` examples. No `sorry`/`admit`.
- Lesson learned: `BitVec.toNat` upper-bound goals are **outside**
  `bv_decide`'s supported fragment ("None of the hypotheses are in the supported
  BitVec fragment"); stating the same bound with `BitVec.ule` against a literal
  discharges it immediately. A drafted `toNat`-bounded version was replaced for
  this reason, and a `sign_clear` theorem whose `.w64` arm was a reflexive
  `if p then x else x` was deleted as a tautology and replaced by the real bound.
- Host cross-check `native-sim/formal/test_x86_signed_host.c`: compiles the
  generated functions with zero warnings under `-Wall -Wextra` and compares them
  to oracles that widen through the width's explicit `__s*` C type and take the
  magnitude through a signed reinterpretation, asserting both are idempotent. It
  sweeps nine boundary operands over all four widths, then a fixed-seed
  20000-iteration LCG sweep (seed `0x6d41b0e793f28ac5`). Result:
  `OK (20036 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, signed host cross-check step; the x86 BSWAP
  step still `OK (20028 cases)`). Mutation checks: changing a width's bit count
  in `x86_signed_spec.json` makes `--check` exit 1; five independent mutations of
  `generated/x86_signed.h` (8-bit sign extension as unsigned, 32-bit extension
  from the wrong type, 64-bit extension narrowing, magnitude dropping the sign
  test, magnitude forgetting to re-narrow) each make the host cross-check exit 1
  with a printed `MISMATCH`, while the pristine header stays `OK`.
  `make -C native-sim/x86 micro-proofs-build` rebuilds all 30 workload-derived
  artifacts, all `ok`; `build`/`run` produce and load the object.
- Open x86 proof surface after this increment: `x86_popcount64`,
  `x86_shld`/`x86_shrd`, the objdump/parser-to-AUX relation, and
  native-byte correspondence.
- `x86_shld`/`x86_shrd` analysis (corrected 2026-09-17): an initial note here
  claimed the helper's `amount >= bits` branch is dead because the count is
  width-masked. That is **wrong** and was disproved by evaluation:
  `KPROG_X86_SHIFT_COUNT` masks the shift to 31 for *every* width except 64
  (`(RHS) & (WIDTH == 64 ? 63 : 31)`), so for an 8- or 16-bit SHLD the count can
  exceed the width and the `amount >= bits` branch is **live** (`count 0xf…f .w8
  = 0x1f`). The x86 ROR/ROL results avoid this because they re-mask with
  `bits - 1` before rotating; SHLD/SHRD deliberately keep the 31-mask and take
  the "shift by more than the width, keep low bits of `src`" branch. The
  remaining obstacle to a contract is that `bv_decide` abstracts the
  `BitVec.toNat`/`BitVec.ult` amount comparison, so both a `toNat`-based and an
  `ult`-based statement yield spurious counterexamples; a future increment should
  state the amount as a bounded `Nat` derived from the masked `BitVec` and prove
  the equivalence as a separate counting lemma. The helpers are unchanged.

### x86 POPCNT refinement, 2026-09-17

- Gap: `x86_popcount64` in `native-sim/x86/x86_sim.h` implemented the 64-bit
  population count used by the POPCNT handler with the standard SWAR reduction
  and no independent statement.
- Contract: `native-sim/formal/generate_x86_popcount_spec.py` reads
  `x86_popcount_spec.json` and emits `generated/x86_popcount.h`
  (`kprog_x86_popcount_value`) and `KProgFormal/GeneratedX86Popcount.lean`. It
  has a `--check` mode and a `make check` line.
- C wiring: `x86_sim.h` includes the generated header and `x86_popcount64` is a
  one-line delegation.
- Lean bridge: `native-sim/formal/KProgFormal/X86Popcount.lean` proves
  `x86_popcount_refines` (the SWAR reduction equals an independent
  **lane-grouped bit walk**: eight byte lanes, each counted bit by bit and
  summed), `x86_popcount_bounded` (`BitVec.ule` against 64), and four
  `native_decide` examples. No `sorry`/`admit`.
- Independence and the proof-engineering result: the two obvious independent
  statements both fail in this toolchain — a flat 64-term bit walk times the SAT
  solver out (`The SAT solver timed out while solving the problem` at ~11 s), and
  a per-byte statement driven by `>>> (8*i)` with a symbolic `i` yields a
  spurious counterexample. Grouping the walk **by the eight concrete byte lanes**
  (each lane's popcount sums at most 8, so lanes cannot interfere) is both
  provable and a genuinely different expression from the SWAR constants; it
  closes in one `bv_decide`.
- A per-nibble intermediate statement was also tried and rejected: `v1 = x -
  ((x >> 1) & 0x55)` borrows across nibble boundaries at `b = 0xff`, so
  "stage-2 lane value == lane popcount" is false; only the completed reduction is
  the true statement. Recorded so the stage-2 shortcut is not retried.
- Host cross-check `native-sim/formal/test_x86_popcount_host.c`: compiles the
  generated function with zero warnings under `-Wall -Wextra` and compares it to
  a one-bit-at-a-time oracle, checking the `<= 64` bound and, on every random
  iteration, additive consistency `popcount(x & ~y) + popcount(x & y) ==
  popcount(x)`. It sweeps nine boundary words, then a fixed-seed
  20000-iteration LCG sweep (seed `0x8e27c4a1f60d3b95`). Result:
  `OK (40009 cases)`.
- Verification: full `make -C native-sim/formal check` green (new generator
  `--check` line, two `lean` lines, popcount host cross-check step; the x86
  signed step still `OK (20036 cases)`). Mutation checks: changing a field in
  `x86_popcount_spec.json` makes `--check` exit 1; four independent mutations of
  `generated/x86_popcount.h` (stage-1 mask, stage-2 shift, stage-3 nibble mask,
  byte-gather multiply constant) each make the host cross-check exit 1 with a
  printed `MISMATCH`, while the pristine header stays `OK`.
  `make -C native-sim/x86 micro-proofs-build` rebuilds all 30 workload-derived
  artifacts, all `ok`; `build`/`run` produce and load the object.
- Open x86 proof surface after this increment: `x86_shld`/`x86_shrd` (see the
  corrected analysis in the signed-value section: the `amount >= bits` branch is
  live for sub-64 widths because the count masks to 31, and `bv_decide`
  abstracts the amount comparison), the objdump/parser-to-AUX selection
  relation, compiler/native-byte correspondence, and multi-step control-flow
  traces. All other x86 value helpers are now generated with proven contracts.

### x86 signed-abs cross-contract agreement, 2026-09-17

- Follow-on to the signed-value increment, committed `79a34f502`. The IMUL flag
  contract (`GeneratedX86ImulFlags.signedAbs`) and the new signed-value contract
  (`GeneratedX86Signed.absWidth`) were generated independently, each with a local
  signed-abs definition. `x86_abs_width_agrees_imul` proves them equal for all
  four widths, so the two generated contracts cannot drift apart on the magnitude
  they both depend on.
- This is the second cross-contract tie in the x86 chain (the first is the
  AArch64 `arm64_byte_lane_load_inverse` between the load ladder and the byte-lane
  scatter). Both are cheap to state and catch a class of drift single-contract
  refinements miss.
- Proof note: the goal needs `GeneratedX86Width.sign` and
  `GeneratedX86Width.bits` in the `simp only` set in addition to `narrow`/`mask`,
  because the IMUL contract's `signedAbs` tests the sign through `sign` while the
  signed contract tests the literal sign mask; `bv_decide` abstracts `sign` when
  it is not unfolded.

### AArch64 pre/post writeback: contract attempted and rejected, 2026-09-17

- Attempted a generated contract for `ARM64_SIM_L_MEM_PRE`/`ARM64_SIM_L_MEM_POST`
  (the load/store base-register writeback), the last AArch64 memory macro without
  one. Built a full JSON->Lean+C pipeline (`GeneratedArm64Writeback` with a
  three-way `Mode`, `classify`, `applies`, `value`, plus a refinement against an
  independent flag-disjunction statement and a `KPROG_ARM64_WRITEBACK` macro).
- **Rejected and fully removed** before commit, for two reasons, both structural
  rather than toolchain difficulty:
  1. The emitted C has *two independent single-bit macros*, not one combined
     classification. `ARM64_SIM_L_MEM_PRE` tests `AUX & ARM64_MEM_PRE` and
     `ARM64_SIM_L_MEM_POST` tests `AUX & ARM64_MEM_POST`, and a call site always
     invokes exactly one of them. A three-way `Mode`/`classify` contract therefore
     models structure the emitted code does not have, and the only C call site that
     could consume a combined macro (applying `PRE || POST`) would double-apply the
     delta if both bits were ever set.
  2. The macro body is a bare `base + imm` with a pointer-tag writeback that
     differs between the SP and general-register arms; there is no non-trivial
     value computation to state independently, and the flag gate is the tautology
     `bit ? 1 : 0`. The genuinely load-bearing part — "a pre/post access
     contributes no separate immediate to the address" — is **already** generated
     and proven by `GeneratedArm64MemOffset` (`valueSpec true _ => 0` /
     `... => index`, with `arm64_mem_offset_prepost_ignores_immediate`).
- Lesson learned: a contract needs an honest call site and a statement that is not
  a restatement or a tautology. Both "PRESENT in the emitted code" and "the
  independent form says something the generated form does not" are necessary
  conditions; the writeback delta fails the first, and its only non-trivial
  property is already owned by the mem-offset contract. Recorded so the same
  contract is not rebuilt. All generated files, the spec, the generator, the two
  Lean modules, and the `arm64_sim_local_bpf.h` include were removed; `make -C
  native-sim/arm64 build` is green and `git status` shows no residual change.

### x86 BT/BZHI refinement, 2026-09-17

- Gap: the `X86_SIM_L_EXEC_BT*` (three macros) and `X86_SIM_L_EXEC_BZHI*` (two
  macros) handlers in `native-sim/x86/x86_sim_local_bpf.h` computed the indexed
  bit and the zero-high-bits result with inline expressions and no independent
  statements.
- Contract: `native-sim/formal/generate_x86_bitops_spec.py` reads
  `x86_bitops_spec.json` and emits `generated/x86_bitops.h`
  (`kprog_x86_bt_value`, `kprog_x86_bzhi_value`) and
  `KProgFormal/GeneratedX86Bitops.lean`. It has a `--check` mode and a
  `make check` line.
- C wiring: `x86_sim.h` includes the generated header and all five macros now
  delegate their value computation to the generated helpers.
- Lean bridge: `native-sim/formal/KProgFormal/X86Bitops.lean` proves
  `x86_bt_refines`, `x86_bzhi_refines` (each against an independent
  exponent-built mask rather than the generated match table),
  `x86_bzhi_within_width`, `x86_bzhi_max_index_keeps`, and three `native_decide`
  examples. No `sorry`/`admit`.
- **A real precedence bug was caught by the host cross-check, not by Lean.** Lean's
  `&&&` (infix priority 70) binds *tighter* than `>>>` (65), so the generated
  `x >>> bit &&& 1` parsed as `x >>> (bit &&& 1)` — the opposite of the C reading
  — and `x & (1 <<< c) - 1` parsed as `(x & (1 <<< c)) - 1`. Both were fixed with
  explicit parentheses. The Lean-only `native_decide`/`bv_decide` checks passed on
  the buggy form because they compared the generated def against itself; only the
  independent host oracle, evaluating the *semantics*, exposed it.
- **The BT index mask is the simulator's `63 : 31` pair, not the width's bit
  count.** An 8-bit `bt` with offset 8 tests a bit the narrowed byte does not have
  and yields false; the contract and the host oracle both encode this, and the
  host oracle deliberately builds the mask from the C expression while the Lean
  spec builds it from a predicate, so the two remain independent.
- **Build-graph finding (pre-existing, important).** Adding a module that imports
  `GeneratedX86Width` (an `inductive` with a `deriving` clause) alongside the
  existing `X86ShiftResult` produced an intermittent
  `environment already contains '…Width.enumToBitVec'` error through `lake
  build`, even though every module compiled standalone. The robust fix was to
  make the generated bitops module depend on the **numeric width code** rather
  than the `Width` inductive, removing the diamond. A second, independent failure
  surfaced during the clean rebuild: the committed `X86Popcount.lean:29`
  `bv_decide` proof needs ~7 s CPU, which exceeds the default solver budget on a
  loaded machine and failed a from-scratch build; it now passes
  `bv_decide (config := { timeout := 120 })`. Both are recorded because they make
  `make check` non-deterministic on a cold cache.
- Host cross-check `native-sim/formal/test_x86_bitops_host.c`: compiles the
  generated helpers with zero warnings under `-Wall -Wextra` and compares them to
  an oracle that tests the indexed bit through a shifted one-bit mask and builds
  the `bzhi` kept mask from the index. It sweeps eight operands x four widths x
  all 64 indices, then a fixed-seed 20000-iteration LCG sweep (seed
  `0x5b13f8a2e64c07d9`), plus the within-width and max-index invariants. Result:
  `OK (22048 cases)`.
- Verification: full `make -C native-sim/formal check` green **from a clean
  `.lake`** (`MAKE 0`, popcount `OK (40009 cases)`, bitops `OK (22048 cases)`).
  Mutation checks: changing a width's index mask in `x86_bitops_spec.json` makes
  `--check` exit 1; five independent mutations of `generated/x86_bitops.h` (BT
  index mask widened, BT base not narrowed, BZHI count mask dropped, BZHI result
  not narrowed, BZHI clearing the low bits) each make the host cross-check exit 1
  with a printed `MISMATCH`, while the pristine header stays `OK`.
  `make -C native-sim/x86 micro-proofs-build` rebuilds all 30 workload-derived
  artifacts, all `ok`; `build`/`run` produce and load the object.
- Open x86 proof surface after this increment: `x86_shld`/`x86_shrd`, the
  objdump/parser-to-AUX relation, compiler/native-byte correspondence, and
  multi-step control-flow traces.

### x86 SHLD/SHRD double-shift refinement, 2026-09-17

- Gap: `x86_shld` and `x86_shrd` in `native-sim/x86/x86_sim.h` implemented the
  double-precision shifts used by the `X86_OP_SHLD_IMM`/`SHRD_IMM` handlers with
  inline shift pairs and no independent statements. This closes the last
  documented open x86 helper.
- Contract: `native-sim/formal/generate_x86_doubleshift_spec.py` reads
  `x86_doubleshift_spec.json` and emits `generated/x86_doubleshift.h`
  (`kprog_x86_shld_value`, `kprog_x86_shrd_value`) and
  `KProgFormal/GeneratedX86DoubleShift.lean`. It has a `--check` mode and a
  `make check` line.
- C wiring: `x86_sim.h` includes the generated header and both helpers are
  one-line delegations.
- Lean bridge: `native-sim/formal/KProgFormal/X86DoubleShift.lean` proves
  `x86_shld_refines` and `x86_shrd_refines` (each against the independent
  doubled-word statement: shift the `(dst:src)` / `(src:dst)` 2b-bit word and take
  its high / low half), `x86_doubleshift_zero_count`, and two `native_decide`
  examples. No `sorry`/`admit`.
- **The `count >= bits` arm is live, not dead.** The count is
  `KPROG_X86_SHIFT_COUNT` (63 for 64-bit, 31 otherwise), so for an 8- or 16-bit
  SHLD the count can exceed the width and the result is taken wholly from `src`
  shifted by `count - bits`. This is what the earlier SHLD investigation had
  mis-analysed twice; both the generated arms and the refinement now encode it,
  and `GeneratedX86DoubleShift.countMask` documents the mask explicitly.
- **A real UB bug was caught by the host cross-check.** The first generated C
  draft omitted the `count == 0` guard, so it evaluated `s >> (bits - 0)`, a
  shift by 64 (`width`) or 32 — undefined behaviour in C. The oracle flagged it;
  the guard is now emitted, and one of the mutation cases deletes it again to keep
  it pinned.
- **Build-graph (recurrence).** As with BT/BZHI, a module that both imported
  `GeneratedX86Width` (a `deriving` inductive) and sat alongside `X86ShiftResult`
  produced the intermittent `environment already contains '…Width.enumToBitVec'`
  diamond through `lake build`. The generated double-shift module was again
  rewritten to take the **numeric width code** and define its own
  `widthMask`/`countMask`, which removes the diamond; the refinement module then
  builds its independent mask from `2 ^ (8 * code)`. With both shifts
  code-parameterised the full `make check` is green from a clean `.lake`.
- Host cross-check `native-sim/formal/test_x86_doubleshift_host.c`: compiles the
  generated helpers with zero warnings under `-Wall -Wextra` and compares them to
  oracles that build the doubled words in `unsigned __int128` and shift them
  there (never the macro's OR-of-two-shifts). It sweeps seven operands x four
  widths x all 64 counts x seven sources, then a fixed-seed 20000-iteration LCG
  sweep (seed `0x2c95e1b734af680d`), plus the within-width invariant. Result:
  `OK (32544 cases)`.
- Verification: full `make -C native-sim/formal check` green **from a clean
  `.lake`** (`MAKE 0`; popcount `OK (40009 cases)`, bitops `OK (22048 cases)`,
  doubleshift `OK (32544 cases)`). Mutation checks: flipping an operation's
  direction in `x86_doubleshift_spec.json` makes `--check` exit 1; five
  independent mutations of `generated/x86_doubleshift.h` (SHLD direction, SHLD
  fill amount, SHRD direction, SHRD wide-count arm, zero-count guard) each make
  the host cross-check exit 1 with a printed `MISMATCH`, while the pristine header
  stays `OK`. `make -C native-sim/x86 micro-proofs-build` rebuilds all 30
  workload-derived artifacts, all `ok`; `build`/`run` produce and load the object.
- Open x86 proof surface after this increment: the objdump/parser-to-AUX
  selection relation, compiler/native-byte correspondence, and multi-step
  control-flow traces. All x86 value helpers are now generated with proven
  contracts.

### Default corpus completes on the current tree; kop output rejected by the verifier, 2026-09-18

- The repository default policy now completes end to end on the current working
  tree with **no command-line overrides at all**:
  `BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=10 JOBS=8
  IMAGE_BUILD_JOBS=8 make corpus` exits 0 and writes
  `corpus/results/x86_kvm_corpus_20260918_063928_597786/` with suite
  `status: "completed"`, app `status: "ok"`, and `rejit_result.status: "ok"` over
  all eleven `full-x86` passes. The working tree at this point carries a
  concurrent uncommitted change to `runner/mk/build.mk` that adds the
  `VMLINUX_BTF`/`KERNEL_RELEASE` pin to `host-native-bpf-x86` (the exact fix this
  log previously recorded as needing authorization), so the framework-kernel BTF
  is now used by default and no override is needed.
- **The `kop` step's optimized bytecode is rejected by the stock verifier.** The
  shim log for that run records `loadtime verifier probe rejected candidate after
  step kop errno=13`, after which it correctly passes the original
  `BPF_PROG_LOAD` through (`PROG_LOAD -> fd=19 errno=0 kernel_prog_id=86`). So
  although the plan contains all eleven steps including `kop` at index 10, no kop
  site is installed: the xdp `balancer_ingres` step list ends at step 9 (`dce`),
  and the applied-site totals for the run are `noop: 4`, `map_inline: 4`,
  `const_prop: 2`, `dce: 2`, `wide_mem: 1`, `bounds_check_merge: 1`,
  `skb_load_bytes_spec: 1`, `kop: 0`. This is a **correctness signal about the kop
  pass output**, not a framework or measurement-validity problem: the shim did
  exactly the right thing (reject the candidate, keep the original), and the
  verifier error is the ground truth to act on.
- Contrast with the earlier committed `kop`-through run
  (`corpus/results/x86_kvm_corpus_20260916_172134_395628/`, 71 kop sites
  installed, `balancer_ingres` 169.00 -> 146.01 ns/run). The two runs differ in
  the concurrent `bpfopt/llvm/src/*` and `bpfopt/shim/*` WIP now in the tree, so
  the kop backend changed between them. The current tree's kop output does not
  survive the verifier; the earlier one did.
- Raw counters for the completed (kop-not-installed) run: `balancer_ingres`
  170.63 ns/run baseline -> 169.48 ns/run post, pktgen throughput 2,575,546 ->
  2,621,341 pps. Consistent with kop contributing nothing on this tree.
- Note on follow-up evidence capture: a second `KEEP_WORKDIRS=1` run
  (`corpus/results/x86_kvm_corpus_20260918_074332_118383/`) failed before the BPF
  work for an unrelated environmental reason (`modprobe tunnel4 failed: Module
  tunnel4 not found in directory /artifacts/lib/modules/7.0.0-rc2+`), so the
  in-VM `verifier_log_step10.log` from the first run was not retained. The
  rejection line above is from the retained shim log, which is the authoritative
  record of the outcome.

### AArch64 branch-emission bridge, 2026-09-18

- Gap (explicitly named as open in `docs/implementation.md`): the proved
  condition and compare-and-branch predicates were stated over an abstract
  `branchPc`, with no link to the `goto`/label code the generator actually emits
  for control transfers.
- Contract: `native-sim/formal/generate_arm64_branch_emit_spec.py` reads
  `arm64_branch_emit_spec.json` and emits `generated/arm64_branch_emit.h`
  (`KPROG_ARM64_BRANCH_BACKWARD(CURRENT, TARGET)`) and
  `KProgFormal/GeneratedArm64BranchEmit.lean` (`Shape`, `backward`, `shape`,
  `nextPc`). It has a `--check` mode and a `make check` line.
- C wiring: the three identical direction tests in
  `arm64_sim_local_bpf.h` (`ARM64_SIM_A64_JCC_IMPL`, `ARM64_SIM_A64_CBZ_IMPL`,
  `ARM64_SIM_A64_TBZ_IMPL` — the `if ((TARGET) <= (CURRENT))` shape selector)
  now call the generated macro. Behaviour is unchanged; `build`/`run` stay green.
- Lean bridge: `native-sim/formal/KProgFormal/Arm64BranchEmit.lean` proves
  `arm64_branch_emit_shape_refines` (the generated shape equals the independent
  address-ordering predicate), **`arm64_branch_emit_refines`** (for both emitted
  shapes the selected next PC equals `branchPc`), plus
  `arm64_branch_emit_shape_irrelevant`, `arm64_branch_emit_taken` and
  `arm64_branch_emit_not_taken`. Together with the existing
  `arm64_condition_sound`/`arm64_branch_next_pc_refines`, this closes the chain
  predicate -> emitted code -> architectural next PC. No `sorry`/`admit`.
- Host cross-check `native-sim/formal/test_arm64_branch_emit_host.c`: compiles the
  generated macro with zero warnings under `-Wall -Wextra`, compares the direction
  test to a plain address-comparison oracle, and — for every ordered pair of eight
  addresses and both predicate values — checks the emitted shape selects the same
  next PC as the architectural model. Result: `OK (64 cases)`.
- Verification: full `make -C native-sim/formal check` green (`MAKE 0`; branch
  emit `OK (64 cases)`). Mutation checks: flipping a shape flag in
  `arm64_branch_emit_spec.json` makes `--check` exit 1; three independent
  mutations of `generated/arm64_branch_emit.h` (strict-less direction test,
  reversed direction test, inverted result) each make the host cross-check exit 1
  with a printed `MISMATCH`, while the pristine header stays `OK`.
  `make -C native-sim/arm64 micro-proofs-build` rebuilds all 30 workload-derived
  artifacts, all `ok`.
- Open AArch64 boundary after this increment: the ALU op-step and register-lane
  handler compositions that remain hand-written, the vector/`.D0`/`.Q0` paths, and
  native-byte equivalence.

### Default corpus run series on the 2026-09-18 tree, 2026-09-18

- Ran the default policy (`BPFREJIT_CORPUS_APPS=katran SAMPLES=1
  WORKLOAD_DURATION=10 JOBS=6 IMAGE_BUILD_JOBS=6 make corpus`) four times to get
  authoritative two-start KVM evidence on the current tree. Results, in order:
  1. `CORPUS_EXIT 0` (`x86_kvm_corpus_20260918_063928_597786/`): suite
     `completed`, app `ok`; `kop` output **verifier-rejected**
     (`verifier probe rejected candidate after step kop errno=13`), so no kop site
     installed. Full numbers in the section above.
  2. `CORPUS_EXIT 2`: `cp: cannot create .../modules-install/lib/modules/
     7.0.0-rc2+/kernel/drivers/iommu/virtio-iommu.ko: No such file or directory`
     during `host-kernel-x86`'s `modules_install`.
  3. `CORPUS_EXIT 2`: the same `cp` failure one driver later
     (`xen/xen-pciback/xen-pciback.ko`), with no competing build process.
  4. `CORPUS_EXIT 0` (`x86_kvm_corpus_20260918_203721_967160/`): kernel and image
     built cleanly, but the **post-ReJIT restart failed at application startup**
     (`native app exited before BPF programs were tracked by shim`, katran
     `Starting Katran` then exit), so suite `status: "error"` and app
     `status: "error"`. The baseline phase did complete a full measurement
     (`measure_start` -> `measure_finish`) with `balancer_ingres` 172.83 ns/run
     and pktgen ~2,536,629 pps, but there is no post-ReJIT counterpart.
- **New kop failure mode in run 4**: the post-ReJIT shim log records
  `loadtime optimization failed: loadtime bpfopt step kop failed;
  log=/tmp/loadtime_2819_2/step10.log` on the trivial 2-instruction
  `socket_filter` and `tracepoint` programs. This differs from run 1's
  verifier-rejection of the optimized candidate: here the `bpfopt --pass kop`
  subprocess itself fails. Both are failures of the current tree's kop backend
  and both leave the original bytecode in place (the framework behaves
  correctly); they are recorded as raw failures, not measurement-validity gates.
- **Two environment-level blockers, both outside the optimizer:**
  - `modules_install` `cp` failures (runs 2 and 3) are a **SeaweedFS FUSE
    flakiness** at deep pre-existing destination paths. Direct `mkdir`/`touch`
    under the same tree succeeds, and a 200-iteration create sweep in a fresh
    path under the same mount had 0 failures, so the mount is not broadly broken;
    the large stale `modules-install` tree is the trigger. `vendor/build/**` is
    gitignored, so removing that tree is a safe build-artifact cleanup.
  - Run 4's katran startup failure is application/environment, not the load-time
    shim. Run 1 on the same tree started katran fine, so it is intermittent.
- The authoritative **completed** evidence on the current tree remains run 1
  (`x86_kvm_corpus_20260918_063928_597786/`): default policy, no overrides, all
  eleven passes, suite `completed`, `kop` rejected by the verifier.

### Root cause of the x86 `kop` step failure, fixed 2026-09-18

- Scope correction: run 1's kop steps actually **ran** (the loadtime report has
  all `kop_*` fields, `sites_applied: 0`, `elapsed_ms` ~6-7 per program); its
  "verifier rejection" is a separate, later-stage effect on an optimized
  candidate, not an argument-parsing failure. The `bpfopt step kop failed`
  mode (run 4) is the argument-parsing failure described here, and it appeared
  with the x86 `bpfopt` rebuilt at 2026-09-18 07:33, which was linked against
  the devcontainer's unpatched LLVM 18.
- The kop backend's options `-bpf-enable-kop-select` and `-bpf-kop-mode` are
  registered only by the patched BPF backend in `llvm-backend/llvm/llvm/`
  (`BPFKopSelect.cpp`). `runner/mk/build.mk` built the x86 binary with
  `-DLLVM_DIR="$(RUNNER_LLVM_DIR)"`, which defaults to
  `/usr/lib/llvm-18/lib/cmake/llvm`. The arm64 rule already used the in-repo
  cross-built `llvm-backend/build-bpf-kop-arm64`, so **kop worked on arm64 and
  failed on x86**.
- Evidence: `strings` finds `enable-kop-select` in
  `llvm-backend/build-bpf-kop/lib/libLLVMBPFCodeGen.a` but not in
  `/usr/lib/llvm-18/lib/libLLVMBPFCodeGen.a`; the old binary printed
  `Unknown command line argument '-bpf-enable-kop-select'` and
  `'-bpf-kop-mode=all=force,movbe-load=disable'` and exited 1, exactly the
  `kop` failures the shim logged (that string is `main.cpp`'s default kop-mode
  for the `kop` pass). Nothing was wrong with the pass logic or the framework.
- Fix (commit `677aef815`): `host-bpfopt-llvm-x86` now depends on
  `host-llvm-x86`, a new target that builds `llvm-libraries` in
  `llvm-backend/build-bpf-kop`, and the x86 bpfopt rule passes
  `-DLLVM_DIR="$(NATIVE_KOP_LLVM_DIR)"` — the same pattern as arm64.
  `RUNNER_LLVM_DIR` is untouched because the runner's llvmbpf build still uses
  system LLVM 18.
- Verification: on a 2-instruction `socket_filter` and `tracepoint` program the
  pass went `EXIT 1` -> `EXIT 0` with a well-formed report; the previously
  failing `--pass kop` command now runs.

### Root cause of the `modules_install` cp failures, 2026-09-19

- The `cp: cannot create ... <mod>.ko: No such file or directory` failures in
  `host-kernel-x86` (runs 2, 3, 5, 6 above; a different driver each time) are a
  **SeaweedFS FUSE `mkdir`-drop**, not a kernel or Makefile bug.
- Exact mechanism: `vendor/linux-framework/scripts/Makefile.modinst` line 17
  runs `$(shell rm -fr $(MODLIB)/kernel $(MODLIB)/build)` at **parse time** and
  then recreates every destination directory in one
  `$(foreach dir, ..., $(shell mkdir -p $(dir)))` sweep (line 121). The
  `/workspaces` SeaweedFS FUSE mount
  (`fuse.seaweedfs ... on /workspaces`) silently fails some of those rapid
  `mkdir` calls, so a later `cp` into that directory finds no parent. Because
  `modinst` deletes the tree first, pre-creating it only helps for the run that
  does not re-delete it, which is why the failure is intermittent rather than
  deterministic.
- Evidence: every failing destination directory is missing while its source
  `.ko` exists; a direct `mkdir -p <dir>` + `cp` into the same path succeeds
  immediately afterward; a `find`-driven loop with a 5-attempt `mkdir` retry
  creates every directory (`434` source dirs, `0` hard failures); a 200-iteration
  `mkdir`+`touch` sweep in a fresh path had 0 failures.
- Confirmed good measurement: rerunning `modules_install` directly once the tree
  is present completes with `EXIT 0`, `0` `cp` errors, `842` `.ko` installed.
- This is vendored upstream kernel source plus an environment-level FUSE
  deficiency; `vendor/build/x86/linux/**` is a gitignored build artifact. The
  retry loop over `make corpus` is the practical mitigation, not a source change.
- **Reproduced `modules_install` success inside a corpus run**: corpus attempt 1
  of the v10 series cleared `host-kernel-x86` and advanced to
  `host-native-bpf-x86`, proving the kernel stage can pass end to end.
- **Blocking failure `host-native-bpf-x86`/tetragon: real build bug, fixed
  2026-09-19 (commit `1a66f51b3`).** Initial attribution to the concurrent
  agent's dirty `vmlinux_generated_x86.h` was wrong. Root cause:
  `host-native-bpf-x86` ran `make -C vendor/bpf native-artifacts` with **no**
  `VMLINUX_BTF`, so `vendor/bpf/Makefile:19` defaulted it to
  `/sys/kernel/btf/vmlinux` — the **host** kernel BTF — and `KERNEL_RELEASE`
  defaulted to `uname -r`. The runtime kernel is the in-repo
  `vendor/linux-framework` build, whose BTF differs: `pahole -C mm_struct` on
  the host BTF has no `user_ns`, while
  `vendor/build/x86/linux/vmlinux` does. So `vmlinux.h` was generated without
  `mm_struct.user_ns` and tetragon's
  `bpf_core_field_exists(mm->user_ns)` could not compile. The arm64 sibling rule
  already passed the built kernel's vmlinux, so **arm64 was fine and x86 broke**.
- Fix: `host-native-bpf-x86` now depends on `$(HOST_KERNEL_VMLINUX_X86)` and
  passes `VMLINUX_BTF="$(HOST_KERNEL_VMLINUX_X86)"` plus
  `KERNEL_RELEASE=<built kernel release>` (`7.0.0-rc2+`), mirroring arm64. This
  is also the semantically correct CO-RE binding: the VM runs the framework
  kernel, so native BPF must bind against that kernel's BTF, keyed under its own
  release dir (`vendor/bpf/targets/x86/7.0.0-rc2+/`).
- Verification: `make -C vendor/bpf KERNEL_RELEASE=7.0.0-rc2+
  VMLINUX_BTF=<built vmlinux> native-artifacts` -> `EXIT 0`, all six apps staged
  (`bcc cilium katran otelcol-ebpf-profiler tetragon tracee`), and all three
  generated x86 headers (`targets/x86/7.0.0-rc2+/vmlinux.h`,
  `tetragon/.../vmlinux_generated_x86.h`, `bcc/libbpf-tools/x86/vmlinux.h`) now
  define `mm_struct.user_ns`.

### First completed default corpus run with `kop` installed, 2026-09-19

- Run `corpus/results/x86_kvm_corpus_20260919_225748_512435/`, default policy
  (`BPFREJIT_CORPUS_APPS=katran SAMPLES=1 WORKLOAD_DURATION=10 JOBS=6
  IMAGE_BUILD_JOBS=6 make corpus`), on the tree with both fixes above
  (`1a66f51b3` x86 VMLINUX_BTF, `677aef815` x86 kop LLVM). Suite `completed`,
  app `katran` `status: ok`, `error: ""`.
- **`kop` finally applied sites**: on the real katran `xdp` program,
  `sites_matched: 71`, `sites_applied: 71`, `insn_count 2216 -> 2175`, with
  `kop_calls_by_name = {bpf_x86_bextrq: 1, bpf_x86_bswapl: 4, bpf_x86_leaq: 41,
  bpf_x86_roll: 20, bpf_x86_rolw: 5}`. The six trivial programs
  (`socket_filter` x3, `kprobe`, `cgroup_sock`) correctly applied `0` (no
  matching sites). This is the first corpus run on this tree in which `kop`
  installs optimized bytecode end to end through the stock verifier.
- **No kop failure signatures**: `0` occurrences of
  `Unknown command line argument`, `bpfopt step kop failed`, or
  `verifier probe rejected` in `details/shim-logs/katran.post_rejit.log`;
  `rejit_result.status: ok`.
- Two-start measurement (both phases present): `balancer_ingres` (xdp)
  baseline `run_cnt_delta 21,487,673`, `169.56 ns/run`; post-ReJIT
  `run_cnt_delta 28,232,777`, `147.85 ns/run`. Raw counters only; no framework
  aggregation.
- Other passes applied on the same program: `noop: 4`, `map_inline: 16`,
  `const_prop: 2`, `dce: 2`, `wide_mem: 1`, `bounds_check_merge: 1`,
  `skb_load_bytes_spec: 1`, `kop: 71` sites.
- Run series context: `corpus_v11` attempt 1 still hit the SeaweedFS FUSE
  `modules_install` `cp` drop (`acpi_ipmi.ko`); attempt 2 cleared it (kernel
  `#6` built clean) and completed. The FUSE drop remains the only recurring
  environment failure, and the `make corpus` retry loop is the mitigation.

### Full six-app default corpus run, 2026-09-20

- Run `corpus/results/x86_kvm_corpus_20260920_045430_754822/`, default policy on
  the fixed tree (`SAMPLES=1 WORKLOAD_DURATION=10 JOBS=6 IMAGE_BUILD_JOBS=6 make
  corpus`, no `BPFREJIT_CORPUS_APPS` filter). `corpus_v12` attempt 2 `EXIT 0`,
  all six app result files written. Attempt 1 hit the FUSE `modules_install`
  drop (`zstd_compress.ko`).
- App statuses: `bcc__set` ok, `katran` ok, `tetragon__observer` ok;
  `cilium__agent` error (Cilium API `PUT /v1/endpoint/0` HTTP 500),
  `otelcol-ebpf-profiler__profiling` error (native app exited before programs
  were tracked), `tracee__monitor` error (Tracee launch failure). All six report
  `rejit_result.status: ok`.
- **`kop` applied sites in all six apps** (programs already carrying kop calls
  are preserved; counts are newly applied sites):
  `tracee/monitor 3089` (`leaq 2841`, `leal 191`, `shlxq 52`, `cmp_cmovb 4`,
  `rolw 1`), `tetragon/observer 2824` (`leaq 2367`, `movq 234`, `movl 142`,
  `movzwl 49`, `movb 16`, `movzbl 16`), `cilium/agent 1980` (`leaq 1142`,
  `rolw 390`, `leal 246`, `cmp_cmovb 126`, `rorxl 28`, `bextrq 20`, `shlxl 19`,
  `movbe16 9`), `otelcol 463` (`leaq 212`, `leal 121`, `cmp_cmovb 115`,
  `bswapl 5`, `bswapq 5`, `shrxq 4`, `shlxq 1`), `katran 71`, `bcc/set 72`.
  Total ~8,499 applied kop sites across the six apps.
- Remaining observed failures, recorded raw (framework leaves the original
  bytecode in place and reports them; not measurement gates):
  - `cilium/agent`: `40` `bpfopt step kop failed` on `cil_to_netdev` and
    `tail_nodeport_n` (kop runs after `noop/map_inline/const_prop/dce/...`), plus
    `verifier probe rejected candidate after step kop errno=13` on a few
    programs. `19` kop reports carry the diagnostic
    `bytecode_kop_recovery_applied=1` (a partial-recovery path that still yields
    applied sites, e.g. `sched_cls` 17 sites on 565->570 insns).
  - `otelcol`: `2` `step kop failed`.
  - `tetragon/observer`, `tracee/monitor`: `2` optimization failures each, on
    `map_inline`/`const_prop` rather than kop.
  - These are real remaining defects in the kop pass for specific
    already-optimized bytecode, distinct from the argument-parsing bug fixed in
    `677aef815`; they need the failing input bytecode captured (the framework's
    `/tmp/loadtime_*` workdirs are removed) to reproduce offline.
- Two-start raw counters for the three completing apps: `katran`
  `balancer_ingres` 171.80 -> 148.34 ns/run; `bcc/set` `sys_enter` 82.29 ->
  80.42, `sys_exit` 88.61 -> 86.50 ns/run; `tetragon/observer`
  `generic_tracepoint` 426.65 ns/run baseline. Raw counters only.

### Remaining kop step failures: root-caused, 2026-09-20

I reproduced the failing `kop` steps offline from the checked-in canonicalized
fixtures (`bpfopt/testbin/<app>/<n>/canonicalize_output.bin`) by running the
configured pass chain (`noop, const_prop, dce, wide_mem, bounds_check_merge,
skb_load_bytes_spec`) and then `kop`. Two independent defects, neither of which
is the argument-parsing bug fixed in `677aef815`:

1. **`bpf_x86_movw` was not probed — FIXED (`ccf9d3852`).**
   `mov_store_target_for_width(2)` in `bpfopt/llvm/src/bpf_kop_bytecode.hpp`
   emits `bpf_x86_movw` for a 2-byte memcpy store, and
   `module/x86/bpf_x86_mov.c` registers it as a kfunc, but the name was missing
   from `kopprober`'s `DEFAULT_KOP_NAMES` and from every runner pass yaml.
   `kopprober` writes only the kfuncs it finds, so `target.json` had no entry and
   `append_kop_pair` threw `target.json has no kop entry for bpf_x86_movw`,
   failing the whole step. Fix: add the name to both lists.
   Evidence: sweeping all 500 canonicalized program fixtures from
   `bpfopt/testbin` through the chain, the old name list failed 4 kop steps and
   2 were this bug; with `movw` probed only the 2 unrelated stack failures
   remain. Two concrete programs were repaired:
   `bpfopt/testbin/bcc_set/569_sys_dup_exit_tail` and
   `bpfopt/testbin/bcc_set/582_syscall__accept4` both threw
   `target.json has no kop entry for bpf_x86_movw` with the old name list; with
   `movw` probed they apply `108` sites (`movw: 16`) and `73` sites
   (`movw: 8`) respectively. Since all nine kop-family passes share
   `apply_bytecode_kop_recovery`, the eight sibling yamls were updated too
   (commit `da730ae39`).

2. **LLVM roundtrip leaks stack-frame bytes — OPEN, in the llvmbpf submodule.**
   The shared LLVM roundtrip grows the r10 frame on every invocation. Running
   the same trivial pass repeatedly on `cilium_agent/202_cil_lxc_policy`
   (`noop`, `const_prop`, `dce`, and `wide_mem` all behave identically — it is
   the roundtrip, not the pass) gives max r10 depth
   `257 -> 337 -> 369 -> 417 -> 449 -> 489 -> 513` with the 7th invocation
   failing. Distinct r10 slots grow `16 -> 24 -> 26 -> 28 -> 29`, i.e. each
   roundtrip allocates new slots and extends the frame downward.
   - The pipeline runs six passes before `kop`, so a program whose raw frame is
     `257` bytes reaches `257 + ~256 = 513` and `kop` (step 11, last) then fails.
     The raw bytecode alone is fine: `kop` on the un-passed fixture succeeds
     (`EXIT 0`).
   - Failure surfaces from `vendor/llvmbpf/src/compiler.cpp:389`
     (`Kernel-compatible lift requires N bytes of stack, exceeding the kernel
     limit`), where `N = compute_kernel_stack_bytes(...)`.
   - `compute_kernel_stack_bytes` also **overcounts by `access_size - 1`**
     (`compiler.cpp:105-107`: `(-off) + access_size - 1`), e.g. an 8-byte access
     at `-504` reports `511` instead of `504`, and a 2-byte access at `-512`
     reports `513` instead of `512`. The true requirement is `-off`.
   - `vendor/llvmbpf` is a **git submodule** (`eunomia-bpf/llvmbpf`, pinned at
     `1fdc7b16`) and is not covered by the authorized edit scope, so this is
     recorded for upstream rather than patched here.
   - `bpfopt/llvm/src/main.cpp` already has `remap_out_of_range_stack_spills`,
     but it only repairs *out-of-range* spills (`ref->off < -512`); a frame that
     grows to exactly fill `512` bytes is considered valid and is not reclaimed.

Effect on the six-app run: `cilium/agent` `40` kop failures and `otelcol` `2`
are consistent with these two causes. Both are recorded as raw failures; the
framework leaves the original bytecode in place and continues.

### movw fix: static verification complete; KVM re-run blocked, 2026-09-20

- Static verification of the `bpf_x86_movw` fix:
  - All 46 string literals of `bpf_{x86,arm64}_*` across
    `bpfopt/llvm/src/bpf_kop_bytecode.hpp` and `bpf_bytecode.hpp` are now present
    in `kopprober`'s `DEFAULT_KOP_NAMES` (only `bpf_x86_movw` was missing).
  - Every `const char *name` passed to `append_kop_pair` resolves to a literal or
    to `bmi2_shift_name`/`bzhi_name_for_opcode`/`mov_store_target_for_width`,
    each of which returns only literals; no name is built dynamically, so the
    literal scan is exhaustive.
  - `kopprober` rebuilds clean and its binary now contains `bpf_x86_movw`;
    `bpfopt` CLI suite still `42/42 OK`.
  - Two concrete repaired programs: `bcc_set/569_sys_dup_exit_tail` (108 sites,
    `movw: 16`) and `bcc_set/582_syscall__accept4` (73 sites, `movw: 8`).
  - `make -C native-sim/x86 micro-proofs-build` 30/30 OK;
    `make -C native-sim/formal check` 25 host cross-checks OK, no errors.
- **KVM re-run to confirm the fix in a measured corpus run did not complete**:
  `corpus_v13` ran four attempts, and every one failed in `host-kernel-x86`
  `modules_install` with the SeaweedFS FUSE `mkdir`-drop (`acpi_ipmi.ko`,
  `ipmi_msghandler.ko`, `zstd_compress.ko`). Two follow-up `make
  host-kernel-x86` retries were cut short by a 1500 s timeout while the kernel
  was still rebuilding, and a concurrent agent re-started a `-j24` kernel build
  on the same output tree, so the shared `vendor/build/x86/linux/**` tree was
  contended. The measured confirmation of the `movw` fix therefore remains
  outstanding; the offline 500-fixture sweep and the two named programs are the
  current evidence.
- Operational note for the next attempt: run the corpus retry loop with a
  per-attempt timeout above the full kernel+image build time (roughly 1.5-2 h),
  or pre-build `host-kernel-x86` to completion before starting, and do not
  overlap with another agent's kernel build on the shared output tree.

### movw fix confirmed in a measured KVM corpus run, 2026-09-21

- Run `corpus/results/x86_kvm_corpus_20260921_105241_827794/`, default policy
  (`SAMPLES=1 WORKLOAD_DURATION=10 JOBS=6 IMAGE_BUILD_JOBS=6 make corpus`),
  `corpus_v14` attempt 2 `EXIT 0`, all six app result files written. Attempt 1
  hit the FUSE `modules_install` drop once; the pre-create + retry loop cleared
  it (`modules_install` `EXIT 0`, 842 `.ko`).
- **`kop` applied sites rose in `cilium/agent` from `1980` to `2494` (`+514`)**
  versus the pre-fix run `x86_kvm_corpus_20260920_045430_754822`. All other apps
  are unchanged (`bcc/set 72`, `katran 71`, `otelcol 463`, `tetragon 2824`,
  `tracee 3089`), which is the expected signature: only the programs whose
  lowering emitted `bpf_x86_movw` changed, and cilium has by far the most such
  programs.
- Remaining `cilium/agent` kop step failures (`42`) are on `cil_to_netdev`,
  `tail_nodeport_n`, `cilium_nodeport`, `cilium_calls_*`, `cil_bpf_policy`,
  i.e. the large-frame programs, consistent with the open llvmbpf roundtrip
  stack-growth defect rather than the fixed name gap. The checked-in
  `193_cil_to_netdev` fixture (1307 insns, 313-byte frame) succeeds offline; the
  live program is 1897 insns and its frame exceeds 512 after the pass chain.
- `bytecode_kop_recovery_applied` diagnostics: 39 (was 36); still a
  partial-recovery path, not a failure.
- App statuses identical to the pre-fix run: `bcc/set`, `katran`,
  `tetragon/observer` `ok`; `cilium/agent`, `otelcol`, `tracee/monitor` `error`
  (Cilium API 500, native app exited, Tracee launch). All six
  `rejit_result.status: ok`.
- Raw two-start counters reproduce across the two completed runs (post-fix
  `20260921_105241_827794` vs pre-fix `20260920_045430_754822`): katran
  `balancer_ingres` `148.02` vs `148.34` ns/run (baseline `171.94` vs `171.80`);
  bcc/set `sys_enter` `79.35` vs `80.42`, `sys_exit` `83.54` vs `86.50` ns/run;
  tetragon baseline `generic_tracepoint` `449.61` vs `426.65` ns/run. Raw
  counters only, no framework aggregation.
- The `movw` fix is therefore confirmed by measurement as well as the offline
  sweep: previously failing lowerings now install sites, and the residual
  failures are the separate, upstream, still-open stack-growth defect.

### Residual kop failures: kernel-stack off-by-one in llvmbpf, fixed 2026-09-21

- The remaining `kop` step failures (`cilium/agent` `42`, `otelcol` `2`) all
  carried the same error from `vendor/llvmbpf/src/compiler.cpp`:
  `Kernel-compatible lift requires N bytes of stack, exceeding the kernel limit`.
- Root cause is a **one-off in `compute_kernel_stack_bytes`** (line 105-107):
  it computed `(-inst.offset) + access_size - 1`. The deepest byte touched by an
  access at `r10+off` of width `w` (`off + w <= 0`) is at depth `-off`, so the
  `+ access_size - 1` overcounts by `w - 1`. An access whose deepest byte is
  exactly `r10-512` therefore reported `513`, which `align_up_to_8` rounds to
  `520` and the `> EBPF_STACK_SIZE` check rejects, although the frame fits the
  512-byte limit exactly.
- Measured across **every** canonicalized program fixture in `bpfopt/testbin`
  (500-541 programs depending on which pass chain completes): the two kop
  failures (`202_cil_lxc_policy`, `211_cil_lxc_policy`) have a **true** frame
  requirement of exactly `512` but an overcounted `513`; the largest true frame
  among passing programs is `496`. There is no fixture whose true requirement
  exceeds 512, i.e. every failure was purely this off-by-one.
- **Fix** (submodule `dd788ba`, parent gitlink bump `d4c4f4773`): compute the
  requirement as `-inst.offset`. `vendor/llvmbpf` is a git submodule pinned to a
  project-owned branch (`origin/codex/bpfopt-llvm-roundtrip-20260515`, all recent
  commits project-authored), so landing a fix there follows existing practice;
  the parent records the new pin.
- Verification with the fix: sweeping all fixtures, kop step failures `2 -> 0`
  with no previously passing program changed; the two repaired programs each
  apply `49` sites; `bpfopt` CLI suite `42/42 OK`; `native-sim/x86`
  `micro-proofs-build` `30/30`.
- Supersedes the earlier "stack-growth" reading: the frame does grow a little
  per roundtrip (`256 -> 336 -> 368 -> 416 -> 448 -> 488 -> 512` true bytes) but
  only ever reached exactly `512`, never above; the rejections were the
  off-by-one, not unbounded growth.

### Off-by-one fix validated in a measured KVM corpus run, 2026-09-21

- Run `corpus/results/x86_kvm_corpus_20260921_211712_637406/`, default policy,
  `corpus_v15` attempt 2 `EXIT 0` (attempt 1 hit the FUSE `modules_install`
  drop once). All six app result files written.
- **`kop` step failures are now `0` in all six apps** (previously
  `cilium/agent 42`, `otelcol 2`). `kop` applied sites across the fix series:

  | run | bcc | cilium | katran | otel | tetragon | tracee | total |
  |---|---|---|---|---|---|---|---|
  | pre-fix `20260920_045430` | 72 | 1980 | 71 | 463 | 2824 | 3089 | 8499 |
  | +movw `20260921_105241` | 72 | 2494 | 71 | 463 | 2824 | 3089 | 9013 |
  | +off-by-one `20260921_211712` | 72 | 2231 | 71 | 916 | 2824 | 4727 | 10841 |

- App statuses: `bcc/set`, `cilium/agent`, `katran`, `otelcol`, `tetragon` all
  `ok`; `tracee/monitor` `error` (Tracee launch). This is `5/6 ok`, up from
  `3/6` in the pre-fix runs; all six `rejit_result.status: ok`. The cilium and
  otel app-level errors that appeared in earlier runs did not recur.
- Raw two-start counters: katran `balancer_ingres` `168.95 -> 148.15` ns/run;
  bcc/set `sys_enter` `77.28`, `sys_exit` `82.59` ns/run post-ReJIT; tetragon
  baseline `generic_tracepoint` `494.80`, `generic_kprobe` `607.61` ns/run. Raw
  counters only.
- With this run both kop defects found this session are fixed and confirmed by
  measurement: the missing `bpf_x86_movw` probe and the llvmbpf kernel-stack
  off-by-one.

### Tracee app-level failure is pre-existing, not caused by this session

- After the two kop fixes, the only remaining app error in the six-app run
  `x86_kvm_corpus_20260921_211712_637406` is `tracee/monitor`:
  `failed to launch Tracee: ... ebpf.(*Tracee).initBPF: failed to load BPF
  object: invalid argument`, with libbpf reporting
  `prog 'trace_security_file_mprotect': BPF program load failed: Invalid
  argument` (`-22`).
- **Not a regression**: the same failure appears in
  `x86_kvm_corpus_20260916_214505_768159` (commit `38476c24f`, before any change
  in this session) with the identical
  `failed to load BPF object: invalid argument` error, and again in every
  six-app run since (`20260920_045430`, `20260921_105241`, `20260921_211712`).
  The only `ok` tracee result is the two-app run
  `x86_kvm_corpus_20260919_035700_452954`, which does not exercise the same
  program set.
- The failing program name varies between runs (`trace_security_file_open`,
  `trace_security_file_mprotect`), and it **never reaches the shim** — the
  `BPF_PROG_LOAD` fails before interception, so no optimization step is
  involved. The tracee `vmlinux.h` used by its BPF build is an unmodified copy
  of `vendor/repos/tracee/pkg/ebpf/c/vmlinux.h` (unchanged since 2026-09-02), so
  the x86 `VMLINUX_BTF` fix (`1a66f51b3`) does not affect it.
- Recorded as an observed app-level failure outside the optimizer; it does not
  gate the kop results, which are counted from the shim's own per-program
  reports and are now zero-failure.

### Investigated and rejected: raising `-bpf-stack-size` for generic passes

- Symptom: `const_prop` (and `noop`) fail on
  `tracee_monitor/639_trace_security_file_mprotect` with the BPF backend's
  `Looks like the BPF stack limit is exceeded ... -mllvm -bpf-stack-size`
  diagnostic from `llvm-backend/llvm/llvm/lib/Target/BPF/BPFRegisterInfo.cpp:62`
  (`WarnSize`), where `BPFStackSizeOption` defaults to `512`.
- Hypothesis: the asymmetry is real — `configure_llvm_kop_select` passes
  `-bpf-stack-size=4096`, while generic passes never call
  `ParseCommandLineOptions`, so they run with the 512 default even though the
  lifted register machine needs backend spill space. Confirming evidence: the
  same fixture **succeeds** under `kop` (which sets 4096) and fails under
  `const_prop`/`noop` (512).
- Change tried: add a `configure_llvm_roundtrip_args()` that parses
  `-bpf-stack-size=4096` once for the non-kop passes (placed after the existing
  dispatch so the kop path keeps its single parse, since
  `ParseCommandLineOptions` resets prior occurrences). It compiles and the
  fixture's `const_prop` then gets past the backend check.
- **Rejected on measurement.** A/B on all `542` canonicalized fixtures with a
  HEAD-build binary and a patched-build binary gave *identical* results:
  `541 OK / 1 FAIL` both ways, no improved and no regressed fixture. The single
  failure simply moved from the backend's `WarnSize` to bpfopt's own
  `remap_out_of_range_stack_spills` ("LLVM output has inconsistent
  out-of-range stack slot width"), which fires for slots below `-512`.
- Interpretation: the backend's 512 rejection was **correct** — the lift
  genuinely exceeds the frame. Raising the limit only defers a correct
  rejection to a later correct one, so it is not an improvement and was not
  committed. `bpfopt/llvm/src/main.cpp` was reverted and rebuilt; the binary is
  byte-identical to the HEAD build.
- Conclusion: `tracee`'s `639_trace_security_file_mprotect` (and the live
  7346-instruction variant seen in the KVM run) cannot be lifted within the
  512-byte frame. It is a **real capacity limit of the lift**, not a
  misconfigured option; a fix would have to reduce the lift's stack demand
  (e.g. prompt `remap_out_of_range_stack_spills` to reclaim slots, or avoid
  re-materializing the frame per roundtrip), not raise the limit.

### Shim semantics: a failed optimizer step returns EINVAL to the application

- Traced `tracee`'s `failed to load BPF object: invalid argument` to the shim,
  not to the tracee program: in `bpfopt/shim/libbpfrejit_shim.c` the
  intercepted `BPF_PROG_LOAD` is rewritten through
  `loadtime_optimize_prog_load`, and when that returns `< 0` the shim sets
  `errno = EINVAL` and returns `-1` **for the application's own load**:

  ```
  if (opt_rc < 0) {
      in_shim = 0;
      log_line("loadtime optimization failed: %s", opt_err);
      prog_free(pending_prog);
      errno = EINVAL;
      return -1;
  }
  ```

- The failure originates in `shim_loadtime.h`: a bpfopt step that exits
  non-zero makes `loadtime_optimize_prog_load` `return -1`
  (`loadtime bpfopt step <name> failed; log=...`).
- This is a **different policy from candidate-verifier rejection**, which logs
  `passing original BPF_PROG_LOAD through` and `return 0`, so the application
  still loads its original bytecode.
- Measured consequence in `20260921_211712_637406`: `tracee/monitor` had
  `2` `const_prop` step failures and its app died fatally; `tetragon/observer`
  had `2` `map_inline` step failures yet reports `ok`. So the EINVAL is real but
  whether it is fatal depends on the application's own load handling.
- The single failing tracee program is a `7346`-instruction
  `trace_security_*` kprobe whose lift exceeds the 512-byte frame (see the
  rejected-change entry above). Most `trace_security_*` programs optimize fine
  in the same run (e.g. `6704 -> 5718`).
- **Not changed.** AGENTS.md mandates fail-fast ("unsupported capability or
  command failure must exit 1 with friendly stderr, never downgrade to other
  logic, return partial results"), so the `return -1` is deliberate policy, not
  an oversight. Aligning it with the verifier-rejection pass-through would be a
  behaviour/policy change to the shim and needs explicit user authorization.
  Recorded here so the decision is visible and reversible.
- Scope note: this is an **application-survival** effect of a step failure, not
  a measurement-validity gate. It does not affect the kop site counts, which the
  shim records per program from its own reports (now zero-failure).

### Systematic finding: the LLVM roundtrip inflates the r10 frame by ~45 bytes

- Measured over all `542` canonicalized fixtures, running exactly one `noop`
  roundtrip (a pure LLVM re-emit, no optimization) and comparing the deepest
  `r10` access (`true frame = -min_off`; the fixture's own offsets):
  - `405 / 542` fixtures **grow**, `137` are unchanged, `0` shrink.
  - growth: min `+8` B, max `+104` B, mean `+45.1` B.
  - worst cases: `bpftrace_set/731_cap_capable` `24 -> 128` (also `156 -> 166`
    instructions), `otelcol/45_perf_unwind_hotspot` `400 -> 496`,
    `bcc_set/40_trace_req_completion_tp` `8 -> 96`.
- The inflation is bounded, not a leak: repeating `noop` on
  `cilium_agent/166_tail_handle_snat_fwd_ipv4` gives
  `264 -> 352 -> 384 -> 392 -> 392 ...` (converges after ~3 roundtrips).
- Cumulative effect along the configured chain (`noop, const_prop, dce,
  wide_mem, bounds_check_merge, skb_load_bytes_spec`): the true frame reaches
  **exactly `512`** for `43` fixtures, and `0` exceed it, so the chain still
  completes for `541 / 542`. But a program that starts near the limit crosses it
  mid-pipeline.
- This is exactly `tracee_monitor/639_trace_security_file_mprotect`: one `noop`
  takes it `440 -> 512` and the *next* pass can no longer lift it. The live KVM
  variant is `7346` instructions with the same shape.
- Mechanism sketch (not yet pinned to a line): `vendor/llvmbpf/src/compiler.cpp`
  allocates one `kernel_stack_bytes`-sized `stackBegin` for the whole module
  (line ~475) and shifts `r10` by a fixed `STACK_SIZE = 64` per BPF-to-BPF call
  (lines ~632, ~1527), so the lifted frame is a re-layout of the original with
  per-call reservation rather than a byte-faithful copy — consistent with both
  the instruction-count drop (`7490 -> 6122`) and the deeper offsets
  (`-2, -16, -24` becoming `-120, -128, -16, -24`).
- Consequence for the goal: `kop` runs **last** (step 11), after ~9 roundtrips,
  so any program whose frame lands near 512 loses all optimization. It is
  therefore worth reducing the lift's stack demand rather than raising the
  kernel limit (which was measured to have no effect — see the rejected-change
  entry above). Two candidate directions, both in scope:
  (a) make the roundtrip preserve the original frame depth instead of
  re-laying it out; (b) let `remap_out_of_range_stack_spills` reclaim the
  over-allocated slots it already detects, which currently throws
  `inconsistent out-of-range stack slot width` before it can try.
- Not attempted: (a) is a behavioural rewrite of the submodule's frame layout,
  and (b) alone is inert because at the `512` default no out-of-range slot is
  ever emitted. Both need a design decision, not an inference.

### Measured and rejected: raising the limit AND relaxing the remapper guard

- Tested the combination suggested above: (1) `configure_llvm_roundtrip_args()`
  parsing `-bpf-stack-size=4096` for non-kop passes, and (2) replacing the
  remapper's strict per-offset width guard (`inconsistent out-of-range stack
  slot width`) with "keep the widest width seen at that offset" so it can
  attempt a remap instead of throwing.
- **Rejected on measurement.** A/B on all `542` fixtures, patched binary vs the
  committed baseline binary, again gave identical totals: `541 OK / 1 FAIL`
  both ways; no improved fixture, no regressed fixture. The single failure just
  moved from `const_prop` to `kop`, i.e. from one correct rejection to another.
- Reason: the failing program's lift genuinely needs more than the 512-byte
  frame at every stage; no amount of tolerance in the *reclaim* step creates
  space for it. `bpfopt/llvm/src/main.cpp` was reverted again and the rebuilt
  binary is byte-identical to the committed baseline.
- Net: two independent attempts to get `tracee`'s `639_trace_security_file_mprotect`
  through the chain both failed to improve any measurable outcome, which
  strengthens the conclusion that the real fix must **reduce the lift's stack
  demand** (the +45 B mean inflation documented above), not relax any limit.
- Nothing is left uncommitted: `bpfopt/llvm/src/main.cpp` matches HEAD and the
  binary matches the HEAD build.

### AArch64 generic ALU handler refinement, 2026-09-24

- Gap: the generated AArch64 ALU result, width, and pointer-add primitives had
  local refinement theorems, but the real `ARM64_SIM_L_EXEC_ALU` decision
  between provenance-preserving pointer ADD and scalarizing arithmetic
  writeback was still hand-written and not covered by a handler-state theorem.
- Contract and C binding: `arm64_alu_handler_spec.json` now generates
  `KPROG_ARM64_ALU_USE_POINTER` and
  `GeneratedArm64AluHandler.usePointer`. The real C handler calls that predicate
  for its unchanged condition: width 64, ADD, destination not SP, and source tag
  non-scalar. The generator's `--check` mode is part of the formal gate.
- Lean bridge: `KProgFormal/Arm64AluHandler.lean` independently enumerates the
  path condition and models GPR, SP, XZR, and absent destinations.
  `arm64_alu_handler_refines` composes path selection, all six generated ALU
  results, pointer-add bits/tag preservation, width narrowing, discarded
  XZR/NONE writes, SP writes, and scalarized GPR writes for every modeled width
  and provenance tag. Concrete theorems pin tagged pointer ADD, tagged SUB
  scalarization, SP ADD, and 32-bit zero extension. There is no `sorry` or
  `admit`.
- Machine checks: `make -C native-sim/formal check` exits 0, including the new
  168-case independent C path oracle and the complete pre-existing Lean/C
  suite. With the workspace's installed toolchains made explicit through
  `RUSTUP_HOME=/usr/local/rustup`, `CARGO_HOME=/usr/local/cargo`, and
  `PATH=/usr/lib/llvm-18/bin:$PATH`, `make -C native-sim/arm64
  micro-proofs-build` exits 0: the negative proof artifact and all 29
  workload-derived artifacts compile `ok`.
- Preserved boundary: the theorem begins after instruction decoding,
  register-number selection, and source-modifier evaluation. It does not prove
  the C register switch, C/Lean language correspondence, compiler output,
  native instruction bytes, multi-step traces, helpers, specialization
  preservation, or full O1--O4. The artifact rebuild is regression evidence,
  not whole-simulator semantic equivalence.

### AArch64 arithmetic flag-handler composition, 2026-09-24

- Gap: ADD/SUB result and NZCV primitives were separately generated and proved,
  but the actual ADDS/SUBS branches still composed them by hand, and the proof
  did not state the crucial difference between result-writing ADDS/SUBS and
  flag-only CMN/CMP.
- Contract and C binding: `arm64_flag_handler_spec.json` defines ADD and SUB
  families plus writeback and compare modes. Its generator emits the C
  `KPROG_ARM64_EXEC_ARITH_WRITEBACK` / `...COMPARE` macros called by the real
  ADDS/SUBS/CMN/CMP branches and a typed Lean family/step. The C branches first
  capture both operands, so result and NZCV use the same immutable values.
- Lean bridge: `KProgFormal/Arm64FlagHandler.lean` independently reconstructs
  ADD/SUB result and NZCV statements. `arm64_flag_step_refines` proves the
  generated family step; `arm64_flag_handler_refines` then proves both modes
  over every ADD/SUB family, width, destination class, state, and operand.
  ADDS/SUBS perform width-aware scalarizing writeback and replace NZCV; CMN/CMP
  preserve the complete modeled GPR/SP state and replace only NZCV. Concrete
  theorems pin 32-bit signed overflow, discarded XZR result with live flags,
  CMP state preservation, and CMN carry/zero. There is no `sorry` or `admit`.
- Machine checks: the full `make -C native-sim/formal check` exits 0. The new
  independent host oracle checks 64 ADD/SUB family, width, and boundary-vector
  combinations in both writeback and compare modes. With the installed
  Rust/Clang paths made explicit, `make -C native-sim/arm64
  micro-proofs-build` exits 0 for the negative artifact and all 29
  workload-derived artifacts.
- Preserved boundary: the theorem begins after typed operands, width,
  destination class, and source-modifier evaluation are supplied. It does not
  cover instruction parsing, register-number selection, the C register switch,
  logical flag handlers, conditional compare, compiler/native bytes,
  multi-step traces, helpers, specialization preservation, or full O1--O4.

### AArch64 logical flag-handler composition, 2026-09-24

- Gap: the AND/BIC result and logical-NZCV primitives were separately generated
  and proved, but the real ANDS/BICS/TST/TST-BIC branches still composed them
  by hand. There was also no handler-state theorem distinguishing the
  result-writing instructions from flag-only tests.
- Contract and C binding: `arm64_logic_flag_handler_spec.json` defines the AND
  and BIC families plus writeback and test modes, with family codes validated
  against the shared ALU decode table. Its generator emits one C
  `KPROG_ARM64_EXEC_LOGIC_FLAGS` step and the matching typed Lean step. The real
  ANDS/BICS/TST/TST-BIC branches now capture both operands and call that step,
  so result and NZCV observe the same immutable operands and operation family.
- Lean bridge: `KProgFormal/Arm64LogicFlagHandler.lean` independently restates
  AND/BIC results and logical NZCV. `arm64_logic_flag_step_refines` proves the
  generated step; `arm64_logic_flag_handler_refines` proves both state modes
  for every family, width, destination class, operand, and incoming state.
  ANDS/BICS perform width-aware scalarizing writeback and replace NZCV;
  TST/TST-BIC preserve the complete modeled GPR/SP state and replace only NZCV.
  Concrete theorems pin 32-bit negative writeback, discarded XZR results with
  live flags, TST state preservation, and TST-BIC flags. There is no `sorry` or
  `admit`.
- Machine checks: `make -C native-sim/formal check` exits 0, including a new
  independent 64-case AND/BIC, four-width boundary-vector C oracle. With the
  installed Rust/Clang paths made explicit, `make -C native-sim/arm64
  micro-proofs-build` exits 0 for the negative artifact and all 29
  workload-derived artifacts.
- Preserved boundary: the theorem begins after typed operands, width,
  destination class, and source-modifier evaluation are supplied. It does not
  cover instruction parsing, register-number selection, the C register switch,
  conditional compare, compiler/native bytes, multi-step traces, helpers,
  specialization preservation, or full O1--O4. The architecture rebuild is
  regression evidence, not whole-simulator semantic equivalence.

### AArch64 conditional-compare handler composition, 2026-09-24

- Gap and value: CCMP appears throughout the 29 workload-derived AArch64
  programs, but its real handler still hand-composed the incoming-NZCV
  condition, SUB flag transition, and immediate fallback NZCV. The earlier
  condition and SUB theorems did not prove this two-path state transition.
- Contract and C binding: `arm64_ccmp_handler_spec.json` states that the
  incoming flags select between SUB-NZCV and fallback bits NZCV[3:0], with no
  register write. Its generator validates the canonical 15-condition table and
  emits `KPROG_ARM64_EXEC_CCMP` plus a typed Lean step. The real CCMP immediate
  and register branch now captures operands, condition, and fallback before
  calling this shared macro.
- Lean bridge: `KProgFormal/Arm64CcmpHandler.lean` independently restates the
  condition through `arm64CondSpec`, the true path through `arm64SubNzc`, and
  fallback extraction through `BitVec.getLsbD`. The corresponding lemmas prove
  each bridge, and `arm64_ccmp_handler_refines` proves that both paths preserve
  the complete modeled GPR/SP state for every incoming flag state, all 15
  supported conditions, every width, all operands, and every 8-bit fallback
  (whose high nibble is ignored). Concrete theorems pin true SUB flags, false
  fallback flags, 32-bit SUB overflow, and high-nibble irrelevance. There is no
  `sorry` or `admit`.
- Machine checks: `make -C native-sim/formal check` exits 0, including an
  independent 122880-case C oracle that exhausts all incoming flag states,
  conditions, widths, boundary operands, and 4-bit fallbacks. With the installed
  Rust/Clang paths explicit, `make -C native-sim/arm64 micro-proofs-build` exits
  0 for the negative artifact and all 29 workload-derived artifacts.
- Preserved boundary: the theorem begins after operand/register selection and
  AUX condition/fallback decoding are supplied. It does not prove those parser
  and selector steps, the C register switch, C/Lean language correspondence,
  compiler/native bytes, multi-step traces, helpers, specialization
  preservation, or full O1--O4. The architecture rebuild is regression
  evidence, not whole-simulator semantic equivalence.

### AArch64 ALU operand-to-handler composition, 2026-09-24

- Gap: `arm64_alu_handler_refines` proved the generic handler only after an
  externally supplied RHS, while `arm64_mod_refines` separately proved the
  eleven source modifiers. The actual immediate/register choice connecting
  those layers remained outside the handler theorem.
- Contract and C binding: `arm64_alu_operand_spec.json` defines immediate and
  register forms, with the register form tied to the canonical eleven-entry
  modifier table. Its generator emits `KPROG_ARM64_ALU_RHS` and the matching
  Lean selector. The real `ARM64_SIM_L_EXEC_ALU` now uses that selector:
  immediate form bypasses modifier evaluation and register form applies the
  generated modifier to the selected register value.
- Lean bridge: `arm64_alu_rhs_refines` proves the selector against an
  independently stated immediate-or-`arm64ModValueSpec` RHS.
  `arm64_alu_operand_handler_refines` composes it with the complete prior
  handler theorem for both operand forms, all six ALU operations, eleven
  modifiers, four widths and destination classes, every modeled source tag,
  arbitrary state/operands, and arbitrary shift vectors. Concrete theorems pin
  immediate bypass, signed-byte extension feeding pointer ADD, 32-bit shifted
  register scalarization, and immediate SP writeback. There is no `sorry` or
  `admit`.
- Machine checks: `make -C native-sim/formal check` exits 0, including a new
  independent 5632-case C oracle over both forms, all modifiers/widths, and
  boundary values/shifts. With the installed Rust/Clang paths explicit,
  `make -C native-sim/arm64 micro-proofs-build` exits 0 for the negative
  artifact and all 29 workload-derived artifacts.
- Preserved boundary: the theorem begins after the parser has supplied typed
  opcode, width, selected register value/tag, destination class, and packed-AUX
  modifier/shift. It does not prove register-number lookup, AUX extraction, the
  C register switch, C/Lean language correspondence, compiler/native bytes,
  multi-step traces, helpers, specialization preservation, or full O1--O4.
  The architecture rebuild is regression evidence, not whole-simulator
  semantic equivalence.

### x86 memory-source arithmetic handler composition and SBB overflow fix, 2026-09-25

- Gap and boundary: the generated x86 little-endian memory primitive and the
  ADD/ADC/SUB/SBB result, flag, and register-writeback contracts were proved
  separately, but `X86_SIM_L_EXEC_ALU_MEM` still had no handler-state theorem.
  `x86_mem_arith_handler_refines` now composes those contracts for arbitrary
  memory bytes, destination bits/tag, incoming flags, and all four legal widths.
  It begins after a valid effective address and address-space path have supplied
  the source bytes and after a typed arithmetic operation/width is selected; it
  does not cover address derivation, bounds/provenance checks, stack/ABI dispatch,
  parsing/AUX selection, memory-destination stores, compiler output, or native
  bytes.
- The independent host oracle exposed a real pre-existing SBB flag defect. The
  generated C/Lean contract used the width-wrapped `(b + borrow)` as the second
  operand of the subtraction-overflow test. For 8-bit `0 - 127 - 1`, that turns
  `127` into `-128` and falsely sets OF even though the exact result is `-128`;
  the dual `-1 - 127 - 1 = -129` case was falsely cleared. The contract and real
  C flag path now use the architectural original-operand formula
  `((a ^ b) & (a ^ result) & sign) != 0`. The now-unused generated subtrahend
  expression was removed rather than retained as dead code.
- Machine checks: the Lean theorem covers full modeled destination/flag state;
  concrete theorems pin 16-bit little-endian ADC carry/partial writeback and
  32-bit SUB borrow/zero-extension. `test_x86_mem_alu_handler_host.c` composes
  the same generated C primitives and compares them with a byte-loop plus
  independent 128-bit carry/borrow and signed-range oracle over 22,048 boundary
  and fixed-seed cases. This is a bounded handler refinement and bug fix, not a
  whole-simulator or native-byte equivalence claim.

### x86 memory-destination arithmetic handler composition, 2026-09-25

- Gap: `X86_SIM_L_EXEC_ALU_MEM_IMM` and `...MEM_REG` read the old memory value,
  run ADD/ADC/SUB/SBB, update flags, and store the width-local result, but only
  the load/store primitives and register-destination arithmetic composition had
  theorems. The new `x86_mem_dest_arith_handler_refines` theorem covers this
  complementary state transition after a valid effective address, typed width
  and RHS have been supplied.
- Machine-checked statement: for arbitrary old memory bytes, RHS, incoming
  flags, operation, and legal width, the composed generated step agrees with an
  independent arithmetic statement on every modeled flag and every memory byte.
  Exactly `width/8` little-endian bytes receive the width-local result; every
  byte outside the access remains unchanged. A concrete theorem pins a 16-bit
  ADC carry/wrap store and preservation of the following byte. There is no
  `sorry` or `admit`.
- Independent C oracle: `test_x86_mem_store_alu_handler_host.c` executes the
  generated load, result, flag, and store macros and compares the full 16-byte
  buffer plus flags against a byte-loop and exact 128-bit signed/unsigned model
  over 22,048 boundary and fixed-seed cases. This proof does not cover address
  calculation or bounds, stack/ABI dispatch, immediate/register RHS decoding,
  AUX/opcode selection, compiler/native bytes, multi-step traces, helpers,
  specialization preservation, or full O1--O4.

### x86 memory-unary handler composition, 2026-09-25

- Gap: the real `X86_OP_ALU_MEM_UNARY` handler loads a width-local memory
  value, executes `INC`, `DEC`, `NEG`, or `NOT` with their distinct flag
  policies, and stores the result, but the existing theorem stopped at the
  corresponding register-lane handlers and standalone memory primitives.
- Machine-checked statement: `x86_mem_unary_handler_refines` composes those
  pieces after a valid effective address, unary operation, and legal width have
  been supplied. For arbitrary old bytes and incoming flags, it proves equality
  with an independent load/unary/store statement on every modeled flag and
  every memory byte. The selected width receives the little-endian result and
  all bytes outside it are preserved; `INC`/`DEC` preserve carry, `NOT`
  preserves all flags, and `NEG` replaces arithmetic flags. A concrete theorem
  pins 8-bit signed-minimum `NEG` overflow and preservation of the following
  byte. There is no `sorry` or `admit`.
- Independent C oracle: `test_x86_mem_unary_handler_host.c` executes the actual
  generated load/result/flag/store macros and compares them with a byte-loop
  and exact signed-range model over 22,048 cases. Its boundary portion covers
  every operation, width, selected value, and all 16 incoming flag
  combinations. The theorem does not cover address calculation/bounds,
  stack/ABI dispatch, packed-AUX operation selection, other memory handlers,
  compiler/native bytes, multi-step traces, helpers, specialization
  preservation, or full O1--O4.

### x86 memory-destination logic handler composition, 2026-09-25

- Gap: the memory-destination `AND`, `OR`, and `XOR` paths shared the proved
  memory primitives and register logical transitions, but lacked a theorem for
  their real load/result/flag/store composition.
- Machine-checked statement: `x86_mem_logic_handler_refines` proves, after a
  valid address, RHS, operation, and width have been supplied, equality with an
  independent statement on every modeled flag and memory byte. The selected
  width receives the little-endian logical result, all other bytes remain
  unchanged, CF/OF are cleared, and ZF/SF are derived from the width-local
  result. A concrete theorem pins a 16-bit XOR-to-zero store and following-byte
  preservation. There is no `sorry` or `admit`.
- Independent C oracle: `test_x86_mem_logic_handler_host.c` exercises actual
  generated load, logic-flag, and store macros against an independent byte-loop
  model for 21,536 boundary and fixed-seed cases. The boundary portion covers
  all 16 incoming flag combinations. Address calculation/bounds, stack/ABI
  dispatch, RHS and packed-AUX selection, other memory handlers,
  compiler/native bytes, multi-step traces, helpers, specialization
  preservation, and full O1--O4 remain outside the theorem.

### x86 memory-source shift/rotate handler composition, 2026-09-26

- Gap: the flagless BMI2 memory-source shifts `SHLX/SHRX/SARX dst, [mem],
  count` and `RORX dst, [mem], imm8` shared the proved memory, shift-result,
  and register-writeback primitives but lacked a theorem for their real
  load/shift/writeback composition.
- Machine-checked statement: `x86_mem_shift_step_refines` and
  `x86_mem_rorx_step_refines` prove, for arbitrary bytes, register state,
  incoming flags, count, and legal width, equality with an independent
  statement. `x86_mem_shift_preserves_flags`/`x86_mem_rorx_preserves_flags`
  prove every modeled flag is preserved, the architectural property that
  separates the flagless BMI2 forms from their flag-writing legacy
  counterparts. Three concrete theorems pin a 32-bit SHLX, an 8-bit SARX
  sign-fill, and an 8-bit RORX. No `sorry` or `admit`.
- Independent C oracle: `test_x86_mem_shift_handler_host.c` exercises the
  actual generated load, shift-result, and writeback macros against a
  byte-loop model for 21,024 boundary and fixed-seed cases, including the
  architectural 32-bit zero-extension into the 64-bit destination. Full
  `make -C native-sim/formal check` passes with 0 errors. Effective-address
  derivation, count register selection, bit/compare/multiply memory handlers,
  compiler/native bytes, multi-step traces, and specialization preservation
  remain outside the theorem.

### x86 memory-source bit-test/zero-high-bits handler composition, 2026-09-27

- Gap: the memory-source bit handlers `BT [mem], imm8` and `BZHI dst, [mem],
  count` shared the proved memory, bit-helper, and register-writeback
  primitives but lacked a theorem for their real load/bit-test/writeback
  composition.
- Machine-checked statement: `x86_mem_bit_step_refines` proves, for arbitrary
  bytes, register state, incoming flags, decoded second operand, and legal
  width, equality with an independent statement that loads through the byte-sum
  memory specification and applies the independently stated `bt`/`bzhi`
  contract. `x86_mem_bt_preserves_dst`/`x86_mem_bt_only_cf` prove `BT` writes no
  register and only CF; `x86_mem_bzhi_clears_sf_of` proves `BZHI` defines SF/OF
  as zero. Three concrete theorems pin an 8-bit BT, a 32-bit BZHI, and an 8-bit
  BZHI whose count reaches the width. No `sorry` or `admit`.
- Supporting bridges: `x86_width_bits_refines` in `X86Width.lean` (BZHI's
  `CF := count >= bits`), and `x86_width_code_spec_cases`/
  `x86_bt_refines_width`/`x86_bzhi_refines_width` in `X86Bitops.lean` to join
  the generated width code to the independent width code.
- Independent C oracle: `test_x86_mem_bit_handler_host.c` exercises the actual
  generated load, bit-helper, and writeback macros against a byte-loop model for
  20,512 boundary and fixed-seed cases, including the masked-to-63/31 bit index,
  the byte-masked count, and the architectural 32-bit zero-extension. Full
  `make -C native-sim/formal check` passes with 0 errors. Effective-address
  derivation, decoded second-operand selection (immediate vs register),
  compare/multiply memory handlers, compiler/native bytes, multi-step traces,
  and specialization preservation remain outside the theorem.

### x86 memory-source multiply handler composition, 2026-09-27

- Gap: the memory-source multiply handler `IMUL reg, [mem], imm` shared the
  proved memory, immediate, sign-extend, IMUL-flag, and register-writeback
  primitives but lacked a theorem for their real composition.
- Machine-checked statement: `x86_mem_imul_step_refines` proves, for arbitrary
  bytes, register state, incoming flags, raw immediate, destination width, and
  memory width, equality with an independent statement that loads through the
  byte-sum memory specification, applies the independently stated
  immediate/sign-extend/multiply-flag contracts, and writes the width-confined
  destination. `x86_mem_imul_preserves_zf_sf` and `x86_mem_imul_cf_eq_of` pin
  the IMUL flag convention (ZF/SF untouched, CF equal to OF),
  `x86_mem_imul_tag_scalar` pins destination tag scalarization,
  `x86_mem_imul_bytes_congruent` confines the load to the memory operand's byte
  count, and `x86_mem_imul_rhs_narrow_reads_low_bits` shows the immediate
  extension depends only on the raw value's low bits. Four concrete theorems pin
  a 16-bit overflow, an 8-bit memory read sign-extended into a 64-bit multiply,
  an 8-bit mixed-sign overflow, and an 8-bit in-range product. No `sorry` or
  `admit`.
- Independent C oracle: `test_x86_mem_imul_handler_host.c` exercises the actual
  generated load, immediate, sign-extend, IMUL-flag, and writeback macros against
  a byte-loop model for 43,136 boundary and fixed-seed cases across all
  destination/memory width pairings. Its CF/OF model is independently stated as
  "the 128-bit mathematical signed product fits the destination's signed width",
  and expressing a sign-filled operand in the 128-bit domain needed a 64-bit
  signed cast in between; the first run failed on that alone (11,198 flag
  mismatches with every destination equal), confirming the generated side and
  the oracle differ on exactly one axis. Full `make -C native-sim/formal check`
  passes with 0 errors and 37 host cross-checks. Register-source multiply
  handlers, effective-address derivation, packed-AUX/effective-width decoding,
  compare memory handlers, compiler/native bytes, multi-step traces, and
  specialization preservation remain outside the theorem.

### x86 memory-source compare/test handler composition, 2026-09-27

- Gap: the four `CMP/TEST [mem], rhs` handlers and `CMP reg, [mem]` shared the
  proved memory load, subtraction-flag, and logical-flag primitives but lacked a
  theorem for their real composition.
- Machine-checked statement: `x86_mem_compare_step_refines` proves, for arbitrary
  bytes, register state, incoming flags, decoded right-hand side, operation, and
  width, equality with an independent statement that loads through the byte-sum
  memory specification and applies either the independently stated zero-borrow
  subtraction contract or the two-operand logical-flag contract.
  `x86_mem_compare_preserves_dst` pins that no register is written, and
  `x86_mem_compare_cmp_flags`/`x86_mem_compare_test_flags` pin the flag half per
  family. `x86_cmp_reg_mem_step_refines` composes the register-left, memory-right
  form, which always takes the subtraction path, and
  `x86_mem_compare_handler_refines` conjoins both. Four concrete theorems pin an
  equal 32-bit compare, an 8-bit borrow, a 16-bit zero test, and the 64-bit
  register/memory borrow. No `sorry` or `admit`.
- Independent C oracle: `test_x86_mem_compare_handler_host.c` exercises the
  actual generated load, immediate, SBB-result, subtraction-flag, and logical-flag
  macros against a byte-loop model for 40,784 boundary and fixed-seed cases
  across all four widths. The generated contract must be evaluated with
  simulator-level masking: `KPROG_X86_SET_SUB_FLAGS` compares raw operands and
  takes the width's sign *mask* as its last argument, while the `X86_SIM_L_*`
  wrapper masks both operands and the result first; the first oracle run used
  unmasked operands and passed the width where the mask belongs, failing with
  39,262 mismatches exactly on mask boundaries. The generated side was correct
  throughout — the oracle was fixed, never the macro. Full
  `make -C native-sim/formal check` passes with 0 errors and 38 host
  cross-checks. Register-source multiply handlers, effective-address derivation,
  packed-AUX/effective-width decoding, compiler/native bytes, multi-step traces,
  and specialization preservation remain outside the theorem.


### x86 two-destination MULX handler composition, 2026-09-27

- Gap: `X86_SIM_L_EXEC_MULX` writes two registers — the low half of the product
  into the destination and the high half into the auxiliary operand — computes a
  128-bit high half, and produces no flags. None of that was covered by the
  single-destination arithmetic handlers.
- Machine-checked statement: `x86_mulx_step_refines` proves, for arbitrary
  register state, operands, operand width, and auxiliary-destination presence,
  that the generated composition equals an independent statement in which the
  low half is the exact product and the high half is the upper word of the exact
  128-bit product. `x86_mulx_preserves_flags` pins that the flag word is
  untouched, `x86_mulx_aux_absent_preserves_aux` pins the
  `if ((AUX) != X86_REG_NONE)` guard, and `x86_mulx_dst_tag_scalar`/
  `x86_mulx_aux_tag_scalar` pin both writebacks' tag scalarization. Four
  `native_decide` examples pin 64-bit max×max, 32-bit max×max, an aux-absent
  case, and a 16-bit limb-branch case. No `sorry` or `admit`.
- The high half is proved by reuse, not re-derivation: `x86MulxHighLadderEqUmulhAlg`
  shows the C four-limb ladder equals `arm64MulUmulhAlg` up to cross-term order
  (`simp only` then `ac_rfl`), and `arm64MulUmulhLadderEqHighWord` from
  `Arm64Mul.lean` then yields the 128-bit high-word equality. This avoids the
  infeasible `bv_decide` on the 64×64→128 identity and the product-blind `omega`
  entirely; `bv_decide` is used only on the small `w32` mask-vs-`setWidth`
  bridge.
- Independent C oracle: `test_x86_mulx_handler_host.c` derives both halves from
  a plain-C exact 128-bit product (`__int128`) — sharing no arithmetic with the
  limb ladder — and checks them against the real `KPROG_X86_WRITE_REG8/16/32/64`
  macros for 41,296 boundary and fixed-seed cases across all four widths, each
  swept with and without the auxiliary destination. Zero warnings. Full
  `make -C native-sim/formal check` passes with 0 errors and 39 host
  cross-checks. Register-source multiply handlers, effective-address derivation,
  packed-AUX/effective-width decoding, compiler/native bytes, multi-step traces,
  and specialization preservation remain outside the theorem.
- Commit `bd518d708`, pushed to `origin/master`.


### x86 register-source IMUL-immediate handler composition, 2026-09-27

- Gap: `X86_SIM_L_EXEC_IMUL_IMM` multiplies the source register by an
  immediate. Unlike `IMUL reg, [mem], imm` there is no memory load and no
  memory-operand width: the left operand is the register's *raw* 64-bit value,
  never sign-extended, while only the immediate is sign-extended and at the
  destination width. A source holding `0xffff...ffff` therefore multiplies as
  `2^64 - 1`, not as a width-narrowed `-1`.
- Machine-checked statement: `x86_imul_reg_imm_step_refines` proves, for
  arbitrary register state, source value, decoded immediate and destination
  width, that the generated composition equals an independent
  sign-extend/multiply/flags/writeback statement. A single `simp only` over the
  four generated `*_refines` lemmas (`x86_immediate_value_refines`,
  `x86_sign_extend_refines`, `x86_reg_write_refines`,
  `x86_imul_flags_apply_refines`) closes it — no `cases width`, because the
  composition is uniform at every width (unlike MULX's `w32` limb branch).
  `x86_imul_reg_imm_preserves_zf_sf`, `x86_imul_reg_imm_cf_eq_of` and
  `x86_imul_reg_imm_tag_scalar` pin the flag-survival, CF-equals-OF and
  scalarization contracts; `x86_imul_reg_imm_source_not_extended` pins the
  register-source rule the memory form does not have. Four `native_decide`
  examples pin a 16-bit overflow, a 64-bit sign-extending immediate that still
  fits, an 8-bit mixed-sign overflow, and an in-range 8-bit product. No `sorry`
  or `admit`.
- Independent C oracle: `test_x86_imul_reg_imm_handler_host.c` sign-extends the
  narrowed source and computes an exact `__int128` product, checking it against
  the real generated immediate/sign-extend/abs/flags/writeback macros for
  41,296 boundary and fixed-seed cases across all four widths. The first draft
  computed its overflow comparison from `lhs & width_mask(width)` — masking
  rather than sign-extending — and disagreed with the generated side on CF/OF
  whenever the narrowed lhs had its sign bit set: 294 mismatches, all CF/OF-only,
  `dst` always matching. The oracle was fixed; the generated macro was never
  touched. Zero warnings. Full `make -C native-sim/formal check` passes with 0
  errors and 40 host cross-checks. The AUX-payload `X86_SIM_L_EXEC_ALU_REG` IMUL
  path, effective-address derivation, packed-AUX/effective-width decoding,
  compiler/native bytes, multi-step traces, and specialization preservation
  remain outside the theorem.
- Commit `011e3a80e`, pushed to `origin/master`.

## Step 0032 — x86 effective-address offset + LEA handler composition

- Scope: `X86_SIM_L_EXEC_LEA`. Chosen because `X86_SIM_L_MEM_OFFSET` is shared
  by every remaining memory-source handler (`_MOV_LOAD`, `_STORE`,
  `_CMOV_MEM`, …), so proving the offset once removes it from the boundary for
  the whole family.
- Generated contract: `x86_mem_offset_spec.json` +
  `generate_x86_mem_offset_spec.py` → `GeneratedX86MemOffset.lean`
  (`value`/`valueSpec`) and `generated/x86_mem_offset.h`
  (`KPROG_X86_MEM_OFFSET(AUX, DISP, INDEX_VALUE, HAS_INDEX)`).
  `x86_mem_offset_refines` (`cases hasIndex <;> bv_decide`) proves the generated
  transition equal to an independent sum; `x86_mem_offset_plain_ignores_index`
  and the `x86_mem_offset_scale_is_power_of_two` components pin the two
  contracts. Three `native_decide` examples (12, `0x8000000000000000`,
  `0xfffffffffffffff8`) were each re-derived with an independent Python
  simulation before the commit.
- Machine-checked statement: `x86_lea_step_refines` proves, for arbitrary
  destination state, source operand (bits/tag/isNone/isRsp), decoded immediate,
  rodata flag, destination width and effective-address terms, that the
  generated handler equals an independent statement — the RODATA fast path
  writes the raw immediate and scalarizes, the 64-bit stack path resolves
  through an abstract frame base and tags `.stack`, the 64-bit general path sums
  the source pointer and carries its tag, and the narrow exits truncate the
  summed pointer through the partial-register writeback. Four further theorems
  pin each path (`x86_lea_rodata_fast_path`, `x86_lea_rodata_needs_no_source`,
  `x86_lea_rsp_uses_stack_base`, `x86_lea_narrow_ignores_rsp`) plus four
  `native_decide` examples (`0x4000`, `0x1030`, `0x7020`, `0x1010`), each
  re-derived in Python. No `sorry` or `admit`.
- Design decisions: the offset contract takes the raw scale byte — C `<<` and
  Lean `<<<` both reduce the amount modulo the word width, so no `& 3` mask is
  needed and the `--check` grid confirms bit-identity for every scale. The
  macro takes the already-read `INDEX_VALUE`, so no `X86_SIM_L_READ_REG`
  dependency leaks into `generated/`. The abstract `stackBase` exists because
  RSP is never initialized in this build (BSS zero ⇒ `__x86_rsp.ptr = NULL`)
  while `X86_SIM_L_STACK_PTR(0) = &stack_mem.b[0] ≠ NULL`.
- Independent C oracle: `test_x86_lea_handler_host.c` checks
  `KPROG_X86_MEM_OFFSET` against an `__int128` power-of-two multiply and the
  composed step against an explicit `stack_base + src_ptr + off` and
  partial-writeback model, for 61,440 boundary and fixed-seed cases. The first
  draft's stack arm omitted `src_ptr` from the base, producing 5,048 mismatches,
  all on the 64-bit RSP arm and all short by exactly `src_ptr`; the sim adds the
  raw RSP value to the offset before `X86_SIM_L_STACK_PTR` indexes. The oracle
  was fixed; the generated macro and the Lean module were never touched. Zero
  warnings. Full `make -C native-sim/formal check` passes with 0 errors, 53
  generators and 41 host cross-checks. The index register decode and packed-AUX
  layout, the mapping from the simulator's stack region to the abstract frame
  base, the `MOV`/`CMOV`/`SETCC`/`STORE`/`XMM`/`CALL`/`PUSH`/`REP_MOVS` matrix,
  compiler/native bytes, multi-step traces, and specialization preservation
  remain outside the theorem.
- Commit `601c76544`, pushed to `origin/master`.
- Step 0033 (2026-09-27): proved the register-writing `MOV` handlers
  `X86_SIM_L_EXEC_MOV_IMM{,_AUX}` and `X86_SIM_L_EXEC_MOV_REG{,_AUX}` in the
  new `native-sim/formal/KProgFormal/X86MovHandler.lean` (236 lines, local
  `X86MovState {dst}` and `X86MovSrc {bits, tag, isRsp}`). `x86_mov_imm_step_refines`
  composes the immediate form over the generated `GeneratedX86RegWrite.writeAt`
  partial-register writeback (destination width + explicit byte lane), with
  `x86_mov_imm_low_lane_is_plain` for the zero-aux degenerate lane.
  `x86_mov_reg_step_refines` composes the register source: the w64 stack-pointer
  arm resolves through an abstract frame base and tags `.stack`, the w64 general
  arm copies the source bits and provenance (`x86_mov_reg_copies_provenance`),
  and the narrow arm reads the source through its decoded lane, writes through
  the destination lane, and scalarizes (`x86_mov_reg_narrow_scalarizes`,
  `x86_mov_reg_narrow_ignores_rsp`). Five `native_decide` examples (`0x4000`,
  `0x112233445566aa88`, `0x7000`, `0x1234`, `0xffffffffffffffaa`), each
  re-derived in Python. No `sorry` or `admit`.
- No new generated contract: `MOV_IMM`/`MOV_REG` are fully expressible over the
  existing `writeAt`/`readAt`/`GeneratedPtrAdd` contracts, so step 0033 adds only
  the Lean handler module and its oracle; the `_AUX` forms reuse
  `GeneratedX86RegLaneAux.pack`/`dstShift`/`srcShift` at the oracle level.
- Independent C oracle: `test_x86_mov_handler_host.c` checks the immediate
  composition against an explicit lane-selecting partial-writeback model and the
  register-source composition (RSP arm, general pointer arm, narrow arm with both
  decoded lanes) against an independent lane-read and writeback model, for
  100,448 boundary and fixed-seed cases. First draft warned on an unused
  `old_tag` parameter in `oracle_mov_imm`; fixed with the same `(void)old_tag;`
  precedent as `test_x86_lea_handler_host.c`. Zero warnings. Full
  `make -C native-sim/formal check` passes with 0 errors, 53 generators, 94 Lean
  module checks and 42 host cross-checks over 1,975,148 cases. The memory-touching
  `MOV` forms, `CMOV`/`SETCC`/`STORE`/`XMM`/`CALL`/`PUSH`/`REP_MOVS`/`ANDN`/`BZHI`/
  `MOVBE`/`CMP_*_OP`, the index register decode and packed-AUX layout, the
  simulator-stack-to-abstract-frame-base mapping, compiler/native bytes,
  multi-step traces, and specialization preservation remain outside the theorem.
- Commit `21f6aae0f` (code increment, 6 files). Step report and research log:
  `650e28d1e`. Evidence refresh: `03b685164`. All pushed to `origin/master`.
- Step 0034 (2026-09-27): proved the width-converting register-source `MOV`
  handlers `X86_OP_MOVZX_REG` and `X86_OP_MOVSX_REG` — the shared body
  `X86_SIM_L_EXEC_MOVX_REG`, which also carries bare `cdqe` and `movsxd` — in
  the new `native-sim/formal/KProgFormal/X86MovxRegHandler.lean` (local
  `X86MovxState {dst}`, `inductive X86MovxOp | movzx | movsx`).
  `x86_movx_reg_step_refines` composes the source register's raw 64-bit value
  through the already-proved `GeneratedX86Width.narrow` (MOVZX) or
  `GeneratedX86Signed.signExtend` (MOVSX) at the decoded *source* width, then
  through `generatedX86RegWrite` at the decoded *destination* width.
  `x86_movzx_is_narrow`/`x86_movsx_is_sign_extend` pin the two arms,
  `x86_cdqe_is_movsx_w32_w64` identifies the `cdqe`/`movsxd` decoding,
  `x86_movzx_same_width_idempotent` rules out double truncation,
  `x86_movzx_ignores_upper_source_bits` shows the source's upper bits never
  reach the destination, `x86_movx_reg_tag_scalar` shows every writeback
  scalarizes, and `x86_movx_reg_narrow_preserves_upper` shows a sub-64-bit
  destination keeps its upper bytes. Six `native_decide` examples, each
  re-derived in Python. No `sorry` or `admit`.
- No new generated contract: MOVX is fully expressible over the existing
  `GeneratedX86Width.narrow` and `GeneratedX86Signed.signExtend` value contracts
  plus the shared writeback, so the generator count stays 53. This is the first
  proof to compose both value contracts in one handler and the first to carry a
  source width distinct from the destination width.
- Unlike the register-source `MOV`, the MOVX body reads the raw 64-bit register
  with no byte lane and writes with lane shift 0; `AUX` is a width code, not a
  lane aux. A corpus-wide grep finds no high-byte (`%ah`) MOVX source.
- Independent C oracle: `test_x86_movx_reg_host.c` drives the actual generated
  `KPROG_X86_APPLY_WIDTH`/`kprog_x86_sign_extend_value` and `KPROG_X86_WRITE_REG*`
  macros against an independent sign-bit model over a 25-pair width-code grid,
  a `cdqe` decoding block, an LCG sweep, and a `movsxd`-identity block: 62,409
  cases, zero warnings. Full `make -C native-sim/formal check` passes with 0
  errors, 53 generators, 95 Lean module checks and 43 host cross-checks over
  2,037,557 cases. The memory-touching `MOV` forms, `CMOV`/`SETCC`/`STORE`/`XMM`/
  `CALL`/`PUSH`/`REP_MOVS`/`ANDN`/`BZHI`/`MOVBE`/`CMP_*_OP`, the index register
  decode and packed-AUX layout, the simulator-stack-to-abstract-frame-base
  mapping, compiler/native bytes, multi-step traces, and specialization
  preservation remain outside the theorem.
- Commit `e861cf838` (code increment, 6 files). Step report and research log:
  `29495e78a`. Evidence refresh: `7359f4cb7`. All pushed to `origin/master`.

- Step 0035 (2026-09-28): proved the shared x86 memory read-dispatch
  classification of `X86_SIM_L_READ_MEM_VALUE`, the one read body behind the
  plain load and store families, in the new
  `native-sim/formal/KProgFormal/X86MemDispatch.lean`. A new generator
  `generate_x86_mem_dispatch_spec.py` (54th) emits a closed eight-row table
  `GeneratedX86MemDispatch.valueSrc : Bool -> Bool -> Bool -> ValueSrc` over
  the three facts the body consults — stack-pointer register identity, ABI
  memory tag, effective width 64 — and the C predicate
  `KPROG_X86_MEM_READ_SRC`. `x86_mem_dispatch_src_refines` equates the
  generated table with an independent predicate *nesting*
  (`if isRsp then .stackRead else if isAbi && w64 then .abiPtrLoad else
  .normalLoad`), not a copy of the generated table. Further theorems pin the
  x86 asymmetry — `x86_mem_dispatch_stack_overrides_tag` (register identity is
  tested first, so an ABI-tagged stack pointer still reads through the stack
  helper at either width; contrast AArch64, whose first test is a memory tag),
  `x86_mem_dispatch_abi_requires_width64` (the ABI arm holds only at width 64;
  off width 64 an ABI base falls through to the ordinary load) — plus
  `x86_mem_dispatch_no_tag_widening` and
  `x86_mem_dispatch_all_arms_reachable`. No `sorry` or `admit`.
- `READ_MEM_VALUE` carries no reloc arm and no per-arm result tag, unlike the
  AArch64 dispatch: the contract is a value-source table only, because the ABI
  packet tag refinement (`KPROG_ABI_LOAD_TAG`) lives in `X86_SIM_L_EXEC_MOV_LOAD`
  (690-700) rather than in the read body. `X86_REG_NONE` (0xff) is not
  `X86_RSP` (4) and `X86_SIM_L_REG_TAG`'s `switch` default leaves the tag
  scalar, so a `NONE` base falls through to the ordinary load without needing
  a separate row. The generated contract is not wired into the live sim, the
  same proof-only decision as the MOVX increment.
- Independent C oracle: `test_x86_mem_read_dispatch_host.c` sweeps the
  generated dispatch over (2 stack-pointer identities × 5 tags × 4 widths)
  plus override/non-widening/reachability blocks, then drives the generated
  `KPROG_X86_MEM_OFFSET` and `KPROG_X86_MEM_LOAD` contracts with the dispatch
  over a deterministic memory/register/stack model — 16 base registers × 4 tags
  × 4 widths × 7 displacements × 2 `STORE_DISP` plus an indexed block — against
  an explicit read-body model: 3,650 cases, zero warnings. Full
  `make -C native-sim/formal check` passes with 0 errors, 54 generators, 97 Lean
  module checks and 44 host cross-checks over 2,041,207 cases. The concrete
  memory-load forms that compose on top of this dispatch (`MOV_LOAD`/
  `MOVSX_LOAD`/`MOV_LOAD_SCALAR`/`MOVBE_LOAD`/`MOVBE_STORE`/`MOV_STORE_*`) and
  `MOV_LOAD_MAP_PTR` (a pointer-immediate write, not a memory read), the
  remaining `CMOV`/`SETCC`/`XMM`/`CALL`/`PUSH`/`REP_MOVS`/`ANDN`/`BZHI`/
  `CMP_*_OP` forms, the index register decode and packed-AUX layout, the
  simulator-stack-to-abstract-frame-base mapping, compiler/native bytes,
  multi-step traces, and specialization preservation remain outside the theorem.
- Commit `7a43a5b27` (code increment, 9 files).

- Step 0036 (2026-09-28): proved the shared x86 `MOV_LOAD` handler
  composition `X86_SIM_L_EXEC_MOV_LOAD`, the single body behind
  `X86_OP_MOV_LOAD`, `X86_OP_MOV_LOAD_SCALAR` and `X86_OP_MOVSX_LOAD`, in the
  new `native-sim/formal/KProgFormal/X86MovLoadHandler.lean`. A new generator
  `generate_x86_mov_load_spec.py` (55th) emits a closed width-resolution table
  `GeneratedX86MovLoad.resolveWidth` over the five `X86_WIDTH_*` codes
  (including the 0 "absent" code) and a closed 32-row arm table
  `GeneratedX86MovLoad.arm : Bool -> Bool -> Bool -> Bool -> Bool -> Arm`, with
  the C predicates `KPROG_X86_MOV_LOAD_WRITE_WIDTH`,
  `KPROG_X86_MOV_LOAD_MEM_WIDTH` and `KPROG_X86_MOV_LOAD_ARM`.
  `x86_mov_load_resolve_width_refines` and `x86_mov_load_arm_refines` equate
  each generated table with an independent statement — a two-fallback width
  resolver and a predicate *nesting* over the five selector facts — and
  `x86_mov_load_resolved_not_absent` shows both resolved widths are total, so
  the handler has no unsupported width. `x86_mov_load_step_refines` composes
  the resolution, the arm, the byte-ladder load, the sign extension, the ABI
  provenance tag and the partial-register writeback in one step relation.
  Further theorems pin the x86 asymmetries:
  `x86_mov_load_arm_stack_ignores_op_and_tag` and
  `x86_mov_load_stack_arm_ignores_sign_extension` (the first arm test is
  register identity, so the stack arm precedes the ABI arm and a stack-based
  `_MOVSX_LOAD` is not sign-extended), `x86_mov_load_arm_abi_iff` (the ABI arm
  needs the plain `_MOV_LOAD` opcode and both resolved widths at 64 bits),
  `x86_mov_load_ordinary_scalarizes`, `x86_mov_load_ordinary_w64_masks_mem`,
  `x86_mov_load_abi_arm_tag`/`_at_end`, and
  `generated_abi_load_tag_refines`, which bridges the generated
  `GeneratedAbiLoad.tag` to the declarative `abiTagSpec` provenance policy.
  No `sorry` or `admit`.
- The generated contract is closed over an explicit `Code` inductive rather
  than `Nat`, because a partial `Nat` table would let `resolveWidth` be
  partial; `x86WidthIs64` is a local matcher rather than `==` because Lean has
  no usable `BEq X86Width` for `native_decide` evaluation. The contract is not
  wired into the live sim — the same proof-only decision as the MOVX and
  read-dispatch increments.
- Independent C oracle: `test_x86_mov_load_host.c` checks the generated
  width-resolution table over the 25 code pairs, the arm table over its 32
  selector combinations, and the full handler over a deterministic
  memory/register/stack model — 16 base registers × 4 base tags × 3 opcodes ×
  5 AUX codes × 5 FLAGS codes × 3 displacement classes × 2 ABI kinds × 3
  destination values, plus an ABI-arm provenance pin — against an explicit
  handler model that restates the arms from the raw fields: 86,461 cases, zero
  warnings. Full `make -C native-sim/formal check` passes with 0 errors, 55
  generators, 99 Lean module checks and 45 host cross-checks over 2,127,668
  cases. Commit `5d7b435c2` (code increment, 10 files).

- Step 0037 (2026-09-28): proved the shared x86 `MOV_STORE` handler
  composition `X86_SIM_L_EXEC_STORE`, the single body behind
  `X86_OP_MOV_STORE_IMM` (`0x07`) and `X86_OP_MOV_STORE_REG` (`0x08`), in the
  new `native-sim/formal/KProgFormal/X86StoreHandler.lean`. A new generator
  `generate_x86_store_spec.py` (56th) emits a closed width-resolution table
  `GeneratedX86Store.resolveWidth` over the five `X86_WIDTH_*` codes
  (including the 0 "absent" code, which defaults to 64 bits) plus three
  separate selector tables — `dispForm` (`immHighHalf`/`signedImm`),
  `valueSource` (`immediateWidth`/`registerRead`) and `shiftSource`
  (`auxSrcShift`/`zero`) — so the two displacement arms out of the same
  artifact field cannot be conflated, and an arm table `arm`
  (`stackWrite`/`memoryStore`). `x86_store_step_refines` composes the width
  resolution, the displacement form, the value source, the AUX shift source,
  the arm, the generated effective-address offset and the little-endian byte
  update into a five-conjunct step relation (four field equalities plus a
  `∀ i` byte statement), with `x86_store_step_fields_refines` and
  `x86_store_step_bytes_refines` exported as reusable pieces.
- Step 0037 design notes: the store's observable state is memory only (no
  flags, no register, no ABI tag), so `X86StoreEffect` carries only
  `arm`/`width`/`value`/`addr`/`bytes` and `X86MovLoadState` is not reused;
  one resolved width feeds both the immediate value and the write, and the
  stack arm re-derives the same `FLAGS ? FLAGS : 64` expression (stated as
  `x86_store_both_arms_use_one_width` — there is no second, AUX-sourced memory
  width as in the read body); `x86_store_imm_disp(IMM) = (s32)(IMM >> 32)`
  while `x86_simm(IMM) = (s64)IMM`; only the register form consults the AUX
  source-shift byte, and modulo 64 because the C `>>=` on a `__u64` truncates
  while Lean's `BitVec` `>>>` saturates, routed through
  `GeneratedX86ShiftCount.count srcShift .w64`; the register source is read at
  the full 64 bits even at a narrow store width. The explicit
  `generatedX86StoreDisp`/`Value`/`Shift` selector-helper defs are the shape
  that made the proof tractable — the same pattern as step 0036.
- Independent C oracle: `test_x86_store_host.c` sweeps the generated width
  resolution over the five codes, the generated arm contract, and the full
  handler over a deterministic memory/register/stack model — 16 base registers
  × 2 opcodes × 5 index codes × 5 shift codes × 5 FLAGS codes × 4 displacement
  classes × 3 index values, plus six asymmetry pins — against an explicit
  store-body model, snapshotting and restoring the pristine buffers around
  every pair and comparing every resulting memory and stack byte: 48,013
  cases, zero warnings. Five independent model mutations each make the oracle
  exit 1, so the sweep is non-vacuous. Full `make -C native-sim/formal check`
  passes with 0 errors, 56 generators, 101 Lean module checks and 46 host
  cross-checks over 2,175,681 cases. Commit `ff267c8b5` (code increment, 10
  files).

## Step 0038 — x86 `SETCC` handler composition

- Scope: `X86_SIM_L_EXEC_SETCC` (`X86_OP_SETCC`, `0x16`). Chosen over the
  alternate `MOVBE_LOAD` because its whole dependency chain was already
  proved — `x86_condition_sound`, `x86_reg_write_at_refines`,
  `x86_reg_lane_aux_*_roundtrip` — and it has real corpus callers
  (`bcc_tcpconnect_ipv4_tuple_filter.bpf.c:187`,
  `cilium_socket_lb_service_select.bpf.c:121,127`). The body reads the
  condition from the AUX *payload* byte and the byte lane from the
  *destination-shift* byte, fixes the width at `X86_WIDTH_8`, and scalarizes
  the destination tag unconditionally.
- New generator `generate_x86_setcc_spec.py` (57th) emits
  `GeneratedX86Setcc.lean`, `generated/x86_setcc.h` and `x86_setcc_spec.json`.
  The generated proof obligation is split: `condOf : BitVec 8 -> Option Cond`
  maps the 14 raw `X86_CC_*` codes, `evalCond` is total over the 14
  constructors, and `evalRaw` composes them with a defined `false` for the
  unsupported codes. Two earlier revisions were rejected — one typed a
  selector as `Option Nat` while returning a constructor, one built `evalRaw`
  from the boolean expressions and thereby required an unprovable 256-way
  `BitVec 8` exhaustion for the default arm.
- New `KProgFormal/X86SetccHandler.lean`: `x86_setcc_eval_cond_sound` (14
  constructor cases, so a transposition of any two arms fails),
  `x86_setcc_raw_cond_sound`, `x86_setcc_raw_unsupported`,
  `x86_setcc_lane_not_eight` / `x86_setcc_lane_high_iff` (the lane decode is an
  *equality*, so a destination shift of 9 selects the low byte),
  `x86_setcc_aux_fields`, `x86_setcc_step_at_refines` /
  `x86_setcc_step_refines`, and the asymmetry theorems
  `x86_setcc_step_preserves_upper_bytes` (the strong
  `0xffffffffffffff00` mask is false — the high lane writes the *second*
  byte), `x86_setcc_step_scalarizes` (unlike `CMOV`, which preserves the source
  pointer tag at `w64`), and the two lane-specific writeback lemmas. No
  `sorry`. `BitVec.ofBool : Bool -> BitVec 1` here, so the 64-bit boolean
  widening is the local `x86BoolValue`.
- Independent C oracle `test_x86_setcc_host.c`: part 1 sweeps the whole
  256-value raw condition byte space against the generated fold; part 2 the
  whole 256-value destination-shift space; part 3 the full handler over a
  deterministic 16-register model (16 × 256 × 8 × 16 = 524,288 cases),
  comparing every byte and the tag; part 4 a second destination-shift sweep;
  part 5 seven asymmetry pins including every accepted code reproducing the
  raw `KPROG_X86_EVAL_CC` expression over all 16 flag combinations; part 6 the
  generated `KPROG_X86_WRITE_REG8` helper over every byte shift. 590,726
  cases, zero warnings. Eight model mutations plus two mutations of the *real
  generated headers* each make the oracle exit 1.
- Full `make -C native-sim/formal check` passes with 0 errors, 57 generators,
  103 Lean module checks and 47 host cross-checks over 2,766,407 cases.

## Next after step 0038

`X86_OP_SETCC_MEM` (`0x3e`) and `X86_OP_CMOV`/`X86_OP_CMOV_MEM` (`0x15`/`0x40`)
have their full bodies read and share the pieces step 0038 composed:
`SETCC_MEM` takes the condition from the AUX *source-shift* byte (not the
payload) and writes memory, and `CMOV` reads the whole AUX word and preserves
the pointer tag at `w64`.

## Step 0039 — x86 `SETCC_MEM` handler composition

- Scope: `X86_SIM_L_EXEC_SETCC_MEM` (`X86_OP_SETCC_MEM`, `0x3e`). Chosen over
  `CMOV`/`CMOV_MEM` because it reuses both halves of the chain the previous two
  steps composed — step 0038's condition decode and step 0037's memory-write arm
  (`x86_mem_offset_refines`, `x86_mem_store_byte_refines`,
  `x86_store_byte_update_refines`, `x86_store_bytes_above_width_unchanged`) — so
  the *new* obligation is exactly the asymmetry the register form could not
  have: a condition decoded from a different AUX byte composed onto the register
  form's condition table.
- Three asymmetries modeled and pinned: (1) the condition byte is the AUX
  **source-shift** byte at bits 24..31 (`X86_REG_AUX_GET_SRC_SHIFT`), not the
  payload byte at bits 0..7 that `SETCC` reads, so the same AUX word names
  different conditions for the two opcodes; (2) the displacement is the **whole
  artifact** (`x86_simm(IMM) = (__s64)IMM`), unlike `_MOV_STORE_IMM`'s
  high-half slice; (3) `(DST) == X86_REG_NONE` forms a **null base pointer**
  *before* the `X86_RSP` arm test, so the null base always takes the memory arm
  with process null as the base. The width is the opcode's constant
  `X86_WIDTH_8` — neither a FLAGS code nor the AUX `X86_MEM_AUX_MEM_WIDTH` byte
  can move it.
- New `generate_x86_setcc_mem_spec.py` (58th generator). `GeneratedX86SetccMem`
  deliberately does **not** re-emit the `condOf`/`evalCond` two-table split: it
  imports `KProgFormal.GeneratedX86Setcc` and defines
  `conditionCode (aux : BitVec 32) := (aux >>> 24).setWidth 8` composed onto it,
  so the counterexample pin (`x86_setcc_mem_condition_source_differs`) is real
  content. The generated `base`/`arm` selectors are stated over decoded `Bool`
  predicates, with three `rfl` refinements in the handler bridging the raw
  register-number tests.
- New `KProgFormal/X86SetccMemHandler.lean`: `abbrev X86SetccMemEffect :=
  X86StoreEffect` (same five fields, so the store's byte-update lemmas apply
  unchanged and the 5-conjunction needs `X86StoreEffect.mk.injEq`);
  `x86_setcc_mem_raw_cond_sound` / `…_raw_unsupported` /
  `…_value_refines`; `…_step_fields_refines` / `…_bytes_refines` /
  `…_step_refines` (13-argument independent spec) / `…_step_aux_refines` (the
  packed-AUX form the dispatch has); the asymmetry theorems
  `x86_setcc_mem_width_ignores_inputs` (a nonzero `X86_MEM_AUX_MEM_WIDTH` byte
  *and* a nonzero FLAGS code both leave the width at `.w8`),
  `x86_setcc_mem_both_arms_use_one_width`,
  `x86_setcc_mem_null_base_ignores_dst`, `x86_setcc_mem_arm_stack_iff`,
  `x86_setcc_mem_step_writes_one_byte`; seven `native_decide` examples. No
  `sorry`.
- Independent C oracle `test_x86_setcc_mem_host.c`: part 1 sweeps the whole
  256-value source-shift byte space through the generated decoder into the real
  `KPROG_X86_EVAL_CC` over all 16 raw flag nibbles against a restated 14-arm
  table, pinning every unsupported code to 0; parts 2/3 sweep all 256 register
  numbers through the base table and both truth values through the arm table;
  part 4 drives the whole handler over a deterministic register/memory/stack
  model (16 dst × 256 conditions × 16 flag nibbles × 2 address modes × 2
  memory-width bytes × 4 immediates plus the smaller sweeps), comparing arm,
  width, value, address and every byte of both buffers; part 5 pins the
  source-shift decode, the whole-artifact displacement, the constant width, the
  null-base memory arm, the unsupported parity codes 10/11, and the scaled-index
  offset on both arms. **1,053,191 cases**, zero non-macro `-Wall -Wextra`
  warnings. Nine mutations of the real generated header each make the oracle
  exit 1 (the `>> 24` decode, the base/arm code swaps, the inverted selectors,
  and each of `WIDTH_CODE`, `NONE_REG`, `RSP_REG` tripping the generated
  `_Static_assert` drift checks); mutating the JSON opcode `0x3e` → `0x3f`
  makes `--check` exit 1.
- Full `make -C native-sim/formal check` passes with 0 errors, 58 generators,
  105 Lean module checks and 48 host cross-checks over 3,819,598 cases.

## Next after step 0039

`X86_OP_CMOV`/`X86_OP_CMOV_MEM` (`0x15`/`0x40`) have their full bodies read:
`CMOV` reads the **whole AUX word** as the condition (`X86_SIM_L_EVAL_CC(AUX)`,
not a byte field) and at `w64` preserves the **source's pointer tag** through
`X86_SIM_L_WRITE_REG_PTR_TAG`, the asymmetry against `SETCC`'s unconditional
scalarization; `CMOV_MEM` reads the source-shift byte *and* has a two-level
width fallback (`X86_MEM_AUX_MEM_WIDTH(AUX) ?: effective(FLAGS)`) with
`STORE_DISP = 1`, so it takes the high-half displacement slice. Then
`_MOVBE_LOAD`/`_MOVBE_STORE`, `_MOV_LOAD_MAP_PTR`, and the rest of the x86
surface.

## Step 0040 — x86 `CMOV` / `CMOV_MEM` handler composition

- Scope: `X86_SIM_L_EXEC_CMOV` (`X86_OP_CMOV`, `0x15`) and
  `X86_SIM_L_EXEC_CMOV_MEM` (`X86_OP_CMOV_MEM`, `0x40`), composed in one module
  because they share the chain the previous four steps composed — step 0038's
  condition decode, step 0037's width/mem-offset pieces and the register-write
  contract. The two forms differ only in where the condition byte comes from
  and whether the value crosses memory.
- Two asymmetries modeled and pinned: (1) `CMOV`'s condition is the **whole
  AUX word** (`X86_SIM_L_EVAL_CC(AUX)`), not a byte field — the low-byte table
  is a *truncating* model, and
  `x86_cmov_whole_word_not_low_byte_equality` (the `0x00000105` witness:
  whole word unsupported, low byte `0x05` supported) pins the distinction,
  while `x86_cmov_condition_sources_differ` (`0x05000000` vs. `0x00000005`)
  pins that the register form's whole word and the memory form's source-shift
  byte name two different conditions from one AUX word; (2) the writeback is
  keyed by the 64-bit test, not by opcode — the register form's `w64` arm
  preserves the source's pointer tag via
  `X86_SIM_L_WRITE_REG_PTR_TAG` (`x86_cmov_w64_arm_preserves_source_tag`),
  every narrower arm scalarizes (`x86_cmov_narrow_arm_scalarizes`), and
  `x86_cmov_writeback_only_w64` pins that the `pointerTag` arm fires only at the
  64-bit width; the memory form, by contrast, scalarizes at **every** width
  including 64-bit (its `WRITE_REG_WIDTH` writeback), so the `pointerTag` arm
  is register-form-only — pinned by the oracle part 4 model, not a dedicated
  theorem.
- New `generate_x86_cmov_spec.py` (59th generator) emitting
  `KProgFormal/GeneratedX86Cmov.lean` + `generated/x86_cmov.h` +
  `x86_cmov_spec.json`: the `X86CmovOp`/`ConditionSource` op tables, the
  whole-word `condOf` / low-byte `condOfByte` / source-shift `condOfSrcShift`
  condition tables composed onto `GeneratedX86Setcc`'s expression table, the
  width tables `resolveWidth`/`resolveMemWidth` over `Code`, and the
  is-64-keyed `writeBack : Bool -> WriteBack` table.
- New `KProgFormal/X86CmovHandler.lean` (515 lines, 31 theorems): 12
  refinement lemmas bridging the generated contracts to the C bodies
  (condition byte/word, mem condition, width/mem-width/mem-disp, writeback,
  evalRaw) plus the top-level `x86_cmov_step_refines` (9-argument); the
  asymmetry theorems `x86_cmov_false_condition_no_write`,
  `x86_cmov_w64_arm_preserves_source_tag`,
  `x86_cmov_narrow_arm_scalarizes`, `x86_cmov_condition_sources_differ`,
  `x86_cmov_whole_word_not_low_byte_equality`,
  `x86_cmov_mem_width_two_level_fallback`,
  `x86_cmov_mem_disp_differs_from_setcc_mem` (the `0xdeadbeef00000008`
  witness), `x86_cmov_writeback_only_w64`, `x86_cmov_unsupported_example`;
  and four `native_decide` examples. No `sorry`.
- Independent C oracle `test_x86_cmov_host.c`: part 1 sweeps the 14 × 16
  condition expression table, the whole-word (256 × 256) and truncating byte
  (256 × 16) condition spaces through the generated macros into the real
  `KPROG_X86_EVAL_CC`, plus the 256-case mem source-shift byte extraction
  (70,112 cases); part 2 sweeps all 6 FLAGS codes through the width and
  writeback contracts; part 3 drives the register form over a deterministic
  register model (30,240 cases); part 4 drives the memory form (384,000
  cases) with the model deliberately scalarizing at **every** width,
  including 64-bit; part 5 pins the eight asymmetry pins (4+7 cases).
  **484,369 cases**, zero non-macro `-Wall -Wextra` warnings. Six mutations
  of the real generated header/spec each make the oracle or the drift check
  exit 1 (the `(AUX)` → `(__u8)(AUX)` low-byte condition, the `>> 24`
  decode → low-byte mem condition, the inverted `if (IS_64)` writeback
  branch, the high-half → whole-artifact displacement, the `>> 16` → `>> 8`
  mem-width shift, and the JSON opcode `0x15` → `0x25` drift check);
  relabeling the numeric `POINTER_TAG`/`SCALARIZE` codes alone does **not**
  trip the oracle — the codes are a shared label both sides derive.
- Full `make -C native-sim/formal check` passes with 0 errors, 59
  generators, 107 Lean module checks and 49 host cross-checks over
  4,303,967 cases.

## Step 0041 — x86 `MOVBE_LOAD` / `MOVBE_STORE` handler composition

- Scope: `X86_SIM_L_EXEC_MOVBE_LOAD` (`X86_OP_MOVBE_LOAD`, `0x28`) and
  `X86_SIM_L_EXEC_MOVBE_STORE` (`X86_OP_MOVBE_STORE`, `0x29`), composed in one
  module because they share one width resolution and the chain the previous
  steps composed — step 0037's mem-offset/mem-access pieces, step 0036's
  register-write contract, the read dispatch of step 0039, the `x86_bswap`
  value contract, and (for the store) step 0035's arm selection and store
  addressing. The two forms share only the width; their arms are different —
  the load classifies through the shared read dispatch
  (`GeneratedX86MemDispatch.valueSrc`), the store through the local
  register-identity arm.
- One asymmetry dominates, plus three contrasts, all modeled and pinned:
  (1) both forms resolve **one** width `FLAGS ? FLAGS : 64`, used for the byte
  reversal, the memory access, and the written size alike — the store's stack
  arm passes the same resolved width, so it does **not** re-derive an effective
  width (`x86_movbe_store_both_arms_use_one_width`,
  `x86_movbe_one_width_rides_all`) the way the shared `MOV_LOAD` does, and the
  load has no second, AUX-sourced width; (2) both forms take the **whole**
  instruction-immediate artifact `(s64)IMM` — the load passes `STORE_DISP = 0`
  to `X86_SIM_L_READ_MEM_VALUE`, selecting `x86_simm` over the store slice —
  pinned by `x86_movbe_disp_differs_from_imm_store` (the `0x8000001000000008`
  witness) against step 0035's `(s32)(IMM >> 32)`; (3) the load writes through
  `X86_SIM_L_WRITE_REG_WIDTH`, always scalarizing, so it has no
  pointer-preserving arm (`x86_movbe_load_scalarizes`) and, unlike the shared
  `MOVSX` load, no sign-extension arm (`x86_movbe_load_no_sign_extension`: an
  8-bit reversal of `0x80` stays `0x80`); (4) the store reads a **separate**
  64-bit source register `SRC` (no shift) while `DST` is the base, reverses
  before the arm split, and writes no register and no flags.
- New `generate_x86_movbe_spec.py` (60th generator) emitting
  `KProgFormal/GeneratedX86Movbe.lean` + `generated/x86_movbe.h` +
  `x86_movbe_spec.json`: the `Op` table (`movbeLoad`/`movbeStore` with their
  opcode codes `0x28`/`0x29` and their consumed arm family), the
  `resolveWidth` table over `Code` with the absent row
  (`KPROG_X86_MOVBE_WIDTH_ABSENT`), the `DispForm`/`dispForm` table (both rows
  `signedImm`), and the `Arm`/`arm` table (`stackWrite` iff the register is the
  stack pointer). The generator's width-define validation keys on
  `flags_width`, not on the resolved `width` — the absent row's `flags_width`
  is 0 while its `width` is 8, so keying on `width` rejects the spec.
- New `KProgFormal/X86MovbeHandler.lean` (519 lines, 26 theorems): the
  width/arm-family/disp/arm refinement lemmas plus the two top-level step
  refinements `x86_movbe_load_step_refines` and
  `x86_movbe_store_step_refines`; the asymmetry theorems
  `x86_movbe_resolved_not_absent`, `x86_movbe_width_absent_defaults`,
  `x86_movbe_disp_forms_whole`, `x86_movbe_arm_stack_iff`,
  `x86_movbe_arm_all_reachable`, `x86_movbe_load_scalarizes`,
  `x86_movbe_load_no_sign_extension`, `x86_movbe_store_step_value_eq`,
  `x86_movbe_store_both_arms_use_one_width`, `x86_movbe_one_width_rides_all`,
  `x86_movbe_store_load_round_trip`; and seven `native_decide` examples. No
  `sorry`. `KProgFormal.lean` gains the two module imports.
- Independent C oracle `test_x86_movbe_host.c` (878 lines): part 1 sweeps the
  width code space (6 codes) through the generated width contract and rejects
  the absent code; part 2 sweeps the shared read dispatch over all eight
  selector combinations against an independent predicate nesting; part 3
  sweeps the store arm over the register-identity fact; part 4 drives the load
  body (1,920 cases) and part 5 the store body (2,700 cases) over a
  deterministic register/memory/stack model against a hand-written C model,
  comparing every byte and the tag of the destination (load) or every byte of
  both buffers (store); part 6 pins the six asymmetries. Its
  `oracle_bswap` is a byte-reverse loop independent of
  `kprog_x86_bswap_value`. **4,675 cases**, zero non-macro `-Wall -Wextra`
  warnings.
- Full `make -C native-sim/formal check` passes with 0 errors, 60 generators,
  108 Lean module checks and 50 host cross-checks.


## Step 0042 — x86 `MOV_LOAD_MAP_PTR` / `MOV_LOAD_HELPER_ID` pointer-write composition

- Scope: the two `X86_SIM_L_EXEC` arms for `X86_OP_MOV_LOAD_MAP_PTR`
  (`0x2c`) and `X86_OP_MOV_LOAD_HELPER_ID` (`0x2d`) — the opcodes whose
  register write installs pointer bits together with a provenance tag.
  One generated contract covers both, the CMOV/MOVBE two-opcode
  one-module precedent: the arms differ only in which fact they set, and
  the tag is what distinguishes them.
- This is the **first handler whose sim C actually calls the generated
  contract** rather than restating it. The generator emits both the Lean
  selector and the C macro; `x86_sim_local_bpf.h` now routes through
  `KPROG_X86_PTR_WRITE_TAG` (opcode-to-tag) and
  `KPROG_X86_PTR_WRITE_IS_HELPER_ID` (gates the helper-id arm's
  preliminary width-64 scalar lane write), then performs the pointer
  write through `X86_SIM_L_WRITE_REG_PTR_TAG`. The two former
  `X86_SIM_L_EXEC` arms were merged into one so the tag is selected once;
  the now-dead `X86_SIM_L_WRITE_REG_MAP_PTR` and
  `X86_SIM_L_WRITE_REG_HELPER_ID` leaf macros were deleted after
  re-grepping for other callers.
- Two opcode facts modeled and pinned. (1) **The map-pointer arm writes
  no width at all** — `x86_ptr_write_map_ptr_writes_no_width`, and
  `x86_ptr_write_map_ptr_no_scalar_write` /
  `x86_ptr_write_never_scalarizes`. (2) **The helper-id arm's width-64
  scalar lane write is replaced bit for bit by the pointer write**, so
  the two writes are observationally one pointer+tag write —
  `x86_ptr_write_helper_id_absorbs_scalar`. Neither arm writes flags;
  `X86_REG_NONE` writes nothing.
- The tag table is **total, not partial**: three rows mirroring
  `X86_SIM_TAG_*` (scalar 0 / mapPtr 5 / helperId 7), with the
  out-of-range C fallthrough `KPROG_X86_PTR_WRITE_TAG_ANY 0xffU` modeled
  by Lean's `none`, so the selector is total without inventing a fourth
  tag. `x86_ptr_write_tag_all_reachable` pins that every tag the C chain
  can select has a Lean counterpart and that the all-false fallthrough
  maps to `none`; `x86_ptr_write_none_fallthrough` pins that no real
  opcode can reach it.
- New `generate_x86_ptr_write_spec.py` (61st generator, 282 lines)
  emitting `KProgFormal/GeneratedX86PtrWrite.lean` +
  `generated/x86_ptr_write.h` + `x86_ptr_write_spec.json`: the `Op` table
  (`mapPtr`/`helperId` with opcode codes `0x2c`/`0x2d` and their two
  opcode facts), the tag table, the selector chain (map-pointer first,
  then helper-id, then the out-of-range code), the
  `width64`/`writes_width64` table, and the C statement-expression
  selector with each input evaluated once. The generator's `load()`
  compares the whole JSON against an `EXPECTED` dict. The generated C
  header must be included **after** the `X86_SIM_TAG_*` defines because
  its tag `_Static_assert`s reference them, so it sits at
  `x86_sim_local_bpf.h:92-95`, not with the other generated includes.
- New `KProgFormal/X86PtrWriteHandler.lean` (310 lines, 19
  theorems/examples): the tag/width-64/selector refinement lemmas plus
  the top-level step refinement `x86_ptr_write_step_refines`, composing
  the arms over the generated tag table, the width-64 fact, and the
  reused `generatedX86MovPointerWrite`/`generatedX86RegWrite`
  primitives; the asymmetry theorems
  `x86_ptr_write_tag_all_reachable`,
  `x86_ptr_write_map_ptr_writes_no_width`,
  `x86_ptr_write_helper_id_absorbs_scalar`,
  `x86_ptr_write_map_ptr_no_scalar_write`,
  `x86_ptr_write_never_scalarizes`,
  `x86_ptr_write_none_fallthrough`, `x86_ptr_write_step_fields`,
  `x86_ptr_write_bits_spec_is_id`; and five `native_decide` canonical
  examples. No `sorry`, no warnings; `KProgFormal.lean` gains the two
  module imports.
- Independent C oracle `test_x86_mov_load_map_ptr_host.c` (559 lines): it
  drives the generated macros exactly as the arms do and compares against
  a hand-written model of the arms — part 1 pins the generated tag table
  against an independent restatement of the raw codes plus the
  fallthrough's distinctness; part 2 exercises the selector over all four
  fact pairs against an independent map-pointer-first nesting; part 3
  exercises the helper-id test over all 256 tag bytes; part 4 drives the
  whole arm over four opcodes × three destinations (incl. `X86_REG_NONE`)
  × four immediates, comparing the whole register file, the lane-write
  count and the flags; part 5 pins the six asymmetries (map-pointer
  absent lane, helper-id single erased lane, flag-free, `X86_REG_NONE`
  no-write, identical bits/different tags, all-false fallthrough).
  **318 cases**, zero `-Wall -Wextra` warnings.
- Full `make -C native-sim/formal check` passes with 0 errors, 61
  generators, 109 Lean module checks and 51 host cross-checks.


## Step 0043 — x86 `LOAD_XMM0` / `STORE_XMM0` pair-move composition

- Scope: the two `X86_SIM_L_EXEC` arms for `X86_OP_LOAD_XMM0` (`0x30`) and
  `X86_OP_STORE_XMM0` (`0x31`) — the 128-bit XMM0 pair moved as two 8-byte
  lanes. One generated contract covers both, the two-opcode one-module
  precedent: `opcode_rows` gives each opcode its direction and base form,
  `arm_rows` the single stack-pointer arm test, and `lane_rows` the two
  consecutive lane offsets.
- Base-form asymmetry is the headline: the load's `X86_REG_NONE` operand
  *is* the whole `x86_simm(IMM)` artifact with the addressing offset
  *discarded*; the store's is the *null pointer* with the offset *always
  added*; every register operand agrees between the two opcodes. The
  displacement is the whole artifact, never the immediate store's high-half
  slice.
- Files: `native-sim/formal/generate_x86_xmm0_spec.py` +
  `x86_xmm0_spec.json` (schema_version 1, literal `EXPECTED`, `--check`
  rejects stale text) → `KProgFormal/GeneratedX86Xmm0.lean`,
  `generated/x86_xmm0.h`; `KProgFormal/X86Xmm0Handler.lean`; oracle
  `test_x86_xmm0_host.c`. Wired into `KProgFormal.lean` and the Makefile
  `check` target. `x86_sim_local_bpf.h` is unchanged.
- Generated C `KPROG_X86_XMM0_BASE_PTR` **takes four arguments** and gates on
  `BASE_IS_NONE`; the three-argument form the first oracle draft assumed
  could not distinguish the two `X86_REG_NONE` readings, and the oracle
  caught exactly that divergence (`load handler mismatch … got=(1,2468…)`
  instead of the raw `0x1234001000000008` artifact).
- Lean: `x86Xmm0Pair` `lo`/`hi : BitVec 64`; direction/arm/lane/base-form
  generated refinements; `generated_x86_xmm0_load_step_refines` /
  `_store_step_refines`; `x86_xmm0_ordinary_addr_load_ignores_offset`,
  `_store_uses_offset`, `_reg_base_agrees`; `x86_xmm0_disp_forms_whole`;
  `x86_xmm0_pair_layout`, `x86_xmm0_lane_width_is_64`,
  `x86_xmm0_store_bytes_above_pair_unchanged`;
  `x86_xmm0_load_store_round_trip`.
- Independent C oracle `test_x86_xmm0_host.c` (882 lines): generated tables
  vs. hand restatements; the whole load and store compositions over a
  deterministic register/memory model (2 opcodes × 4 bases × 3 index regs ×
  2 scales × 4/3 imms) comparing whole buffers; eight pins (whole-artifact
  displacement, base-form asymmetry, register-operand agreement, lane order,
  `X86_REG_NONE` store placement, untouched GPRs/tags, non-vacuous access,
  stack round trip). **283 cases**, zero `-Wall -Wextra` warnings. Mutation-
  tested: inverting the load's base form, reusing lane 0 for lane 1, and
  zeroing `ADDS_DISP` each make it exit non-zero.
- Full `make -C native-sim/formal check` passes with 0 errors, 62
  generators, 113 Lean module checks and 52 host cross-checks.


## Step 0044 — x86 `CALL_MEMCPY` / `CALL_MEMSET` block-copy/fill composition

- Scope: the four `X86_SIM_L_EXEC` arms for `X86_OP_CALL_MEMCPY` (`0x3f`),
  `X86_OP_CALL_MEMCPY_REG` (`0x46`), `X86_OP_CALL_MEMSET` (`0x3c`), and
  `X86_OP_CALL_MEMSET_REG` (`0x45`) — one composition under three per-opcode
  facts. The two `*_REG` bodies are *not* aliases of the immediate forms:
  they take the length from `RDX` and the array bound from the immediate.
- The headline fact is that the bound form and the count source are
  *independent*: the two immediate-count bodies iterate to the hardcoded
  literal `1024` and move `min(count, 1024)` bytes, whereas the two
  register-count bodies are bounded by the immediate artifact and move
  `min(RDX, immediate)` bytes — the *opposite* of their length source. In
  codes the two selections even coincide (fixed/immediate are both `0`), so
  only the *reading* keeps them apart; a table that collapsed the bound form
  into the count source would still pass a raw-code equality check.
- Files: `native-sim/formal/generate_x86_callmem_spec.py` +
  `x86_callmem_spec.json` (schema_version 1, literal `EXPECTED`, `--check`
  rejects stale text) → `KProgFormal/GeneratedX86CallMem.lean`,
  `generated/x86_callmem.h`; `KProgFormal/X86CallMemHandler.lean`; oracle
  `test_x86_callmem_host.c`. Wired into `KProgFormal.lean` and the Makefile
  `check` target. `x86_sim_local_bpf.h` is unchanged.
- Generated C: four `_Static_assert` opcode-drift asserts, the
  `KPROG_X86_CALLMEM_{COPY,FILL}`, `_COUNT_{IMM,REG}`,
  `_BOUND_{FIXED,IMM}` code defines, `KPROG_X86_CALLMEM_FIXED_BOUND 1024U`,
  and the three single-input selector macros `KPROG_X86_CALLMEM_KIND`,
  `_COUNT_SOURCE`, `_BOUND_FORM`. The generator additionally validates the
  count-source/bound-form independence invariant.
- Lean: `X86CallMemOp` (four constructors) and `x86CallMemToOp`; independent
  `x86CallMemKindSpec`/`CountSourceSpec`/`BoundFormSpec` + `*_refines`
  (each closing by `cases op <;> rfl`); `x86_call_mem_kind_shapes`;
  `x86_call_mem_bound_and_count_are_independent` (the headline reading
  separation); the fixed-bound, bound-form, count-source, and fill-byte
  generated refinements; `X86CallMemEffect` (a function-typed field, so no
  `deriving`); the function-level `x86CallMemByteSpec` +
  `x86_call_mem_byte_refines` (`funext i; cases k <;> simp only [...]`);
  `generatedX86CallMemStep`/`x86CallMemStepSpec` + `x86_call_mem_step_refines`;
  and `x86_call_mem_beyond_bound_unchanged`.
- The destination-pointer-with-destination-tag `RAX` write is carried as an
  explicit `Tag` parameter through both the generated and spec steps
  (`KProgFormal.Tag`, `TagErasure.lean:15`).
- Independent C oracle `test_x86_callmem_host.c`: generated tables vs. hand
  restatements; the whole composition over a deterministic register/memory
  model (4 opcode shapes × 6 immediates × 3 dst regs × 3 src regs × 4 `RDX`
  lengths) comparing whole buffers, the whole register file, and the flags;
  six pins (literal-vs-artifact bound, register-count bounded by the
  artifact, copy-vs-fill byte behavior, bound/count canaries, the
  destination-pointer `RAX` write with untouched GPRs, the flag-free body).
  **875 cases**, zero `-Wall -Wextra` warnings. Mutation-tested: changing the
  fixed-bound literal, dropping the copy's source read, skipping the `RAX`
  write, swapping the model's bound arm, and collapsing the generated
  `BOUND_FORM` each make it exit non-zero.
- Full `make -C native-sim/formal check` passes with 0 errors, 63
  generators, 115 Lean module checks and 53 host cross-checks.


## Step 0045 — x86 `PUSH` / `POP` stack-step composition

- Scope: the two `X86_SIM_L_EXEC` arms for `X86_OP_PUSH` (`0x12`) and
  `X86_OP_POP` (`0x13`) — one composition under two per-opcode facts. Both
  bodies step the stack pointer by exactly `8` bytes; the asymmetry is
  *when* and *at what width*.
- The headline fact is the step-direction / width-source pairing: PUSH
  pre-decrements RSP by 8 before its store, hardcodes width 64, ignores the
  FLAGS code, and writes no register; POP resolves `FLAGS ? FLAGS : 64`, uses
  that one width for both its stack read and its destination write, then
  post-increments RSP by 8. In codes the two selections coincide
  (pre-decrement and hardcoded-64 are both `0`), so only the *reading* keeps
  them apart; a table that collapsed the width source into the step direction
  would still pass a raw-code equality check.
- Files: `native-sim/formal/generate_x86_pushpop_spec.py` +
  `x86_pushpop_spec.json` (schema_version 1, literal `EXPECTED`, `--check`
  rejects stale text) → `KProgFormal/GeneratedX86PushPop.lean`,
  `generated/x86_pushpop.h`; `KProgFormal/X86PushPopHandler.lean`; oracle
  `test_x86_pushpop_host.c`. Wired into `KProgFormal.lean` and the Makefile
  `check` target. `x86_sim_local_bpf.h` is unchanged.
- Generated C: two `_Static_assert` opcode-drift asserts, the
  `KPROG_X86_PUSH_{STEP_PRE_DECREMENT,STEP_POST_INCREMENT}`,
  `_WIDTH_{HARDCODED_64,FLAGS_OR_64}`, `_FLAGS_{RESOLVED,ABSENT}` code
  defines, `KPROG_X86_PUSH_WIDTH_ABSENT 0U`, `KPROG_X86_PUSH_STACK_STEP 8U`,
  and the three single-input selector macros `KPROG_X86_PUSH_STEP_DIRECTION`,
  `_WIDTH_SOURCE`, `_FLAGS_WIDTH`.
- Lean: `X86PushPopOp` (`push`/`pop`) and `x86PushPopToOp`; independent
  `x86PushPopStepDirectionSpec`/`WidthSourceSpec` + `*_refines`; the headline
  `x86_push_pop_facts` (direction/width-source independence, closed by
  `StepDirection.noConfusion` / `WidthSource.noConfusion` — a `fun h => cases h`
  does not discharge `≠` between two constructors of a generated inductive);
  `x86_push_pop_flags_width_absent_iff`; `x86PushPopStepAmountSpec` +
  `x86_push_pop_step_amount_refines` + `x86_push_pop_step_amount_is_eight`;
  the shared-width `x86PushPopWidthCodeSpec`/`WidthSpec` +
  `generatedX86PushPopWidth` + `x86_push_pop_width_refines` +
  `x86_push_pop_push_ignores_flags`/`pop_absent_defaults`/`push_byte_count`
  (the last closes with `cases flags <;> decide`);
  `generatedX86PushPopAccessAddr`/`RspAfter` + `*_refines` +
  `x86_push_pop_{rsp_round_trip,push_addr_is_new_rsp,pop_addr_is_old_rsp,step_independent_of_width}`;
  the byte-level `x86PushPopByteSpec`/`x86_push_pop_byte_refines` (delegating
  to `x86StoreByteUpdate`); `X86PushPopEffect` (a function-typed field, so no
  `deriving`); `generatedX86PushPopStep`/`x86PushPopStepSpec` +
  `x86_push_pop_step_refines`; `x86_push_pop_{push_has_no_dst,pop_writes_dst,pop_frame_unchanged,push_frame_updates_eight}`;
  and the `native_decide` examples, whose POP form needs
  `simp only [...]` then `decide` (`native_decide` cannot evaluate a
  `BitVec`-valued proposition here).
- The generated module imports `KProgFormal.GeneratedX86Store` and shares its
  `Code` inductive and `resolveWidth` table (precedent
  `GeneratedX86Cmov.lean:3-7`) rather than declaring its own; the POP
  destination write goes through `generatedX86RegWrite`.
- Independent C oracle `test_x86_pushpop_host.c`: generated tables vs. hand
  restatements; the whole composition over a deterministic register,
  stack-frame and flags model (2 opcodes × 5 FLAGS codes × 5 RSP values ×
  3 src regs × 3 dst regs) comparing the whole register file, the whole
  stack frame, and the flags; seven pins (PUSH ignores a narrow FLAGS code
  and stores the whole eight bytes, POP at an absent FLAGS defaults to 64 and
  still steps by eight, the push/pop round trip, both directions stepping the
  same amount, PUSH touching no register but RSP, the narrow-pop partial
  writeback, and the flag-free bodies). **463 cases**, zero `-Wall -Wextra`
  warnings. Mutation-tested: `STACK_STEP` 8→4 and swapping the
  `STEP_DIRECTION` arms each make it exit non-zero (a plain renumbering of
  the two direction codes does *not* — the oracle reads the codes, so the
  arm swap is the binding mutation).
- Full `make -C native-sim/formal check` passes with 0 errors, 64
  generators, 117 Lean module checks and 54 host cross-checks.

## Step 0046 — x86 `REP MOVS` block-copy composition

- Scope: the single `X86_SIM_L_EXEC_REP_MOVS` arm for `X86_OP_REP_MOVS`
  (`0x3a`), the bounded block copy that moves `RSI`-addressed bytes to `RDI`.
- Facts: the copy width is the FLAGS-resolved width `FLAGS ? FLAGS : 64`; the
  loop bound is the literal `64`; the count copied is the raw instruction
  immediate (`IMM`), *not* `RCX`; the body copies `min 64 count` elements while
  each pointer advances by the full raw count times the copy stride; and the
  trailing `RCX` writeback zeroes `RCX` at the fixed 64-bit width, independent
  of the FLAGS code. The two pointers keep the provenance tags they were read
  with. `X86_SIM_L_LOAD_ADDR`/`_STORE_ADDR` are plain `KPROG_X86_MEM_LOAD`/
  `_MEM_STORE` here (no ABI tag path), so no `BASE_IS_RSP`/`BASE_TAG`
  classification is needed.
- Files: `native-sim/formal/generate_x86_rep_movs_spec.py` +
  `x86_rep_movs_spec.json` (schema_version 1, literal `EXPECTED`, `--check`
  rejects stale text) → `KProgFormal/GeneratedX86RepMovs.lean`,
  `generated/x86_rep_movs.h`; `KProgFormal/X86RepMovsHandler.lean`; oracle
  `test_x86_rep_movs_host.c`. Wired into `KProgFormal.lean` and the Makefile
  `check` target. `x86_sim_local_bpf.h` is unchanged.
- Generated C: the opcode-drift `_Static_assert`, a local width-code block with
  a 64-bit drift assert, `KPROG_X86_REP_MOVS_BOUND 64U`,
  `KPROG_X86_REP_MOVS_COPY_WIDTH_DEFAULT X86_WIDTH_64`,
  `KPROG_X86_REP_MOVS_COUNT_WIDTH X86_WIDTH_64`, and the FLAGS-resolving
  `KPROG_X86_REP_MOVS_WIDTH(FLAGS)` arm macro. The width macro is *not*
  degenerate: the absent arm falls back to the 64-bit default while a narrow
  arm stays narrow.
- Lean: `x86RepMovsBoundSpec` + `*_refines`/`*_is_sixty_four`;
  `x86RepMovsWidthSpec` + `generatedX86RepMovsWidth` + `*_refines`/
  `*_is_flags_resolved`/`*_absent_defaults`;
  `x86RepMovsElementCountSpec`/`generatedX86RepMovsElementCount` +
  `*_refines`/`*_bounded`; `x86RepMovsStrideSpec` + `*_is_width_bytes`;
  `generatedX86RepMovsAdvance`/`x86RepMovsAdvanceSpec` + `*_refines` +
  `x86_rep_movs_overshoot_beyond_bound`/`*_count_is_immediate`;
  `x86RepMovsCountWidthSpec`/`generatedX86RepMovsCountWidth` + `*_refines`;
  `x86RepMovsRcxSpec`/`generatedX86RepMovsRcx` + `*_refines`/`*_zeroed`;
  `X86RepMovsEffect` (data-only, so it carries `deriving DecidableEq, Repr`);
  `generatedX86RepMovsStep`/`x86RepMovsStepSpec` + `x86_rep_movs_step_refines`;
  the reads-apart lemmas `*_copy_width_is_flags_resolved`,
  `*_count_is_raw_immediate`, `*_copies_at_most_bound`,
  `*_advance_uses_flags_width`, `*_step_rcx_zeroed`, `*_tags_preserved`; and
  the `simp only [...]` then `decide` examples (BitVec-valued props, so
  `native_decide` fails). The generated module imports `GeneratedX86Store` and
  shares its `Code`/`resolveWidth` (precedent `GeneratedX86Cmov.lean:3-7`);
  the `RCX` writeback goes through `generatedX86RegWrite`.
- Independent C oracle `test_x86_rep_movs_host.c`: generated tables vs. hand
  restatements; the whole composition over a deterministic register and
  copy-buffer model (5 FLAGS codes × 10 counts) comparing the whole register
  file, the copied region, and the flags; seven pins (the narrow-width advance,
  the bound-vs-raw-count saturation asymmetry, the zero-count no-op, the fixed
  64-bit `RCX` zeroing under a narrow copy width, the preserved provenance
  tags, the byte-for-byte copy, and the flag-free body). **67 cases**, zero
  `-Wall -Wextra` warnings. Mutation-tested with arm swaps / literal changes:
  swapping the two `KPROG_X86_REP_MOVS_WIDTH` arms, `BOUND` 64→8, and
  `COUNT_WIDTH` 64→32 each make it exit non-zero (a plain renumbering of the
  width codes is vacuous — the oracle reads the codes).
- Full `make -C native-sim/formal check` passes with 0 errors, 65
  generators, 119 Lean module checks and 55 host cross-checks.

## Step 0047 — x86 `ANDN` / `ANDN_MEM` source-split composition

- Scope: the two `X86_SIM_L_EXEC_ANDN` / `X86_SIM_L_EXEC_ANDN_MEM` arms for
  `X86_OP_ANDN` (`0x3d`) and `X86_OP_ANDN_MEM` (`0x44`), the bitwise
  `(~src1) & src2` pair. `ANDN` reads `src2` from a register (`AUX`); the
  memory form reads it from memory.
- Facts: the destination write width is the FLAGS-resolved `FLAGS ? FLAGS : 64`
  for both bodies; the second-operand source is a per-opcode table entry, and
  only the memory form consults a memory width at all. The headline fact is
  the memory-read width: it is *independently selected* and is not the
  destination write width — the memory form reads at `X86_MEM_AUX_MEM_WIDTH(AUX)`
  when the AUX field names a width and falls back to the resolved FLAGS write
  width when that field is absent or zero. CF and OF are set to 0 by the shared
  logic-flag production; ZF/SF track the result narrowed at the *write* width.
- Files: `native-sim/formal/generate_x86_andn_spec.py` + `x86_andn_spec.json`
  (schema_version 1, two-opcode `EXPECTED` table, `--check` rejects stale text)
  → `KProgFormal/GeneratedX86Andn.lean`, `generated/x86_andn.h`;
  `KProgFormal/X86AndnHandler.lean`; oracle `test_x86_andn_host.c`. Wired into
  `KProgFormal.lean` and the Makefile `check` target. `x86_sim_local_bpf.h` is
  unchanged.
- Generated C: the two opcode-drift `_Static_assert`s, a local width-code block
  with a 64-bit drift assert, `KPROG_X86_ANDN_WRITE_WIDTH_DEFAULT X86_WIDTH_64`,
  the two source codes + per-opcode source defines +
  `KPROG_X86_ANDN_SOURCE(OP_IS_MEMORY)`, the two memory-width arm codes +
  `KPROG_X86_ANDN_MEM_WIDTH_ARM(AUX_WIDTH_IS_ABSENT)`, the FLAGS-resolving
  `KPROG_X86_ANDN_WRITE_WIDTH(FLAGS)`, and the two-input
  `KPROG_X86_ANDN_MEM_WIDTH(AUX_WIDTH_CODE, FLAGS)`.
- Lean: `x86AndnWriteWidthSpec`/`generatedX86AndnWriteWidth` + `*_refines`/
  `*_absent_defaults`; `Source`/`source` + `x86_andn_source_refines`;
  `memWidthArm` (keyed on the raw AUX `Code`, the `absent` code is 0) +
  `x86_andn_mem_width_arm_refines`; `x86AndnMemWidthSpec`/
  `generatedX86AndnMemWidth` + `x86_andn_mem_width_refines`;
  `X86AndnEffect` (data-only, carries `deriving DecidableEq, Repr`);
  `generatedX86AndnStep`/`x86AndnStepSpec` + `x86_andn_step_refines`; and the
  narrowing pins. The `memWidthArm` takes a `Code` rather than a `Bool`, so the
  arm theorem carries no `resolveWidth` cycle; the `auxField` arm resolves the
  AUX code through the shared width table, the `flagsFallback` arm resolves the
  FLAGS code to the resolved write width. The generated module declares its own
  `resolveWidth` (precedent `GeneratedX86Cmov.lean`).
- The final `x86_andn_step_refines` proof is `cases op <;> cases flagsCode <;>
  cases auxCode <;> simp only [...]` — the `cases` must come *before* `simp
  only`, or `simp` rewrites into a mangled `if true = true then …` form that no
  longer reduces.
- Independent C oracle `test_x86_andn_host.c`: generated tables vs. hand
  restatements; the whole composition over a deterministic register and
  source-memory model (2 source forms × 5 FLAGS codes × 5 AUX widths × 4
  displacements × 3 src1 regs × 3 dst regs) comparing the whole register file,
  the whole memory array, and the flags; seven pins. **1849 cases**, zero
  `-Wall -Wextra` warnings. Mutation-tested with arm swaps / literal changes:
  swapping the two `KPROG_X86_ANDN_MEM_WIDTH` result arms, changing
  `KPROG_X86_ANDN_WRITE_WIDTH_DEFAULT` 64→32, and swapping the two per-opcode
  source values each make it exit non-zero (a plain renumbering of the codes is
  vacuous — the oracle reads the codes).
- Full `make -C native-sim/formal check` passes with 0 errors, 66 generators,
  121 Lean module checks and 56 host cross-checks.


## Step 0048 — x86 `BZHI` / `BZHI_MEM` single-width value/count composition

- Scope: the two `X86_SIM_L_EXEC_BZHI` / `X86_SIM_L_EXEC_BZHI_MEM` arms for
  `X86_OP_BZHI` (`0x34`) and `X86_OP_BZHI_MEM` (`0x35`), the BMI2 opcodes that
  clear the bits at or above a byte-masked bit count.
- Facts: both bodies resolve *one* width `FLAGS ? FLAGS : 64` and use it for the
  value read, the count comparison, and the destination write — there is no
  second AUX-selected memory width here, unlike `ANDN_MEM`. The value and count
  sources are per-opcode table entries: `BZHI` reads its value from `SRC` and
  its count from `COUNT`, `BZHI_MEM` reads its value from memory at the
  resolved width and its count from the register the AUX shift byte names. The
  headline fact is the hand-defined flag set: `OF = SF = 0` outright while `ZF`
  is the real zero test of the result, so SF is not the result's sign as the
  shared logic-flag production would make it; and `CF` is the byte-masked count
  reaching the *width's* bit count, not any property of the result. The count
  is byte-masked, so a register holding `0x1ff` behaves as `0xff`.
- Files: `native-sim/formal/generate_x86_bzhi_spec.py` + `x86_bzhi_spec.json`
  (schema_version 1, two-opcode `EXPECTED` table, `--check` rejects stale text)
  → `KProgFormal/GeneratedX86Bzhi.lean`, `generated/x86_bzhi.h`;
  `KProgFormal/X86BzhiHandler.lean`; oracle `test_x86_bzhi_host.c`. Wired into
  `KProgFormal.lean` and the Makefile `check` target. `x86_sim_local_bpf.h` is
  unchanged.
- Generated C: the two opcode-drift `_Static_assert`s, a local width-code block
  with a 64-bit drift assert, `KPROG_X86_BZHI_WRITE_WIDTH_DEFAULT X86_WIDTH_64`,
  the two value-source and two count-source codes + per-opcode source defines +
  `KPROG_X86_BZHI_VALUE_SOURCE(OP_IS_MEMORY)` /
  `KPROG_X86_BZHI_COUNT_SOURCE(OP_IS_MEMORY)`, the FLAGS-resolving
  `KPROG_X86_BZHI_WRITE_WIDTH(FLAGS)`, and `KPROG_X86_BZHI_COUNT_MASK 0xffULL`.
- Lean: `x86BzhiWidthSpec`/`generatedX86BzhiWidth` + `x86_bzhi_width_refines`/
  `x86_bzhi_width_default_refines`; `ValueSource`/`CountSource` tables +
  `x86_bzhi_value_source_refines`/`x86_bzhi_count_source_refines`;
  `x86BzhiValueSpec`/`generatedX86BzhiValue` + `x86_bzhi_value_refines` (memory
  arm bridged through `x86_mem_load_refines`); `x86BzhiCountSpec`/
  `generatedX86BzhiCount` + `x86_bzhi_count_read_refines` + the byte-truncation
  pin `x86_bzhi_count_masks_to_byte`; `x86BzhiResultSpec`/
  `generatedX86BzhiResult` + `x86_bzhi_result_refines` (bridged through
  `x86_bzhi_refines_width`); `x86BzhiFlagsSpec`/`generatedX86BzhiFlags` +
  `x86_bzhi_flags_refines` (bridged through `x86_width_bits_refines`);
  `X86BzhiEffect` (data-only, `deriving DecidableEq, Repr`);
  `generatedX86BzhiStep`/`x86BzhiStepSpec` + `x86_bzhi_step_refines`; and the
  narrowing pins (`x86_bzhi_clears_sf_of`, `x86_bzhi_cf_is_count_versus_width`,
  `x86_bzhi_zf_real_sf_cleared`). The generated module declares its own
  `resolveWidth` (precedent `GeneratedX86Cmov.lean`); the handler imports
  `KProgFormal.X86LogicFlags` for the `X86Flags` structure and
  `KProgFormal.X86Bitops` for the `bzhi` refinement lemmas (reused, no new
  generator for the helper).
- The final `x86_bzhi_step_refines` proof is `cases op <;> cases flagsCode <;>
  simp only [...]` — the `cases` must come *before* `simp only`, as in 0047.
  Concrete flag pins use `simp only [x86BzhiFlagsSpec, x86WidthBitsSpec] <;>
  decide`; a `simp only` that has already rewritten the goal cleanly benefits
  from a plain `decide` rather than a further `simp only` list.
- Independent C oracle `test_x86_bzhi_host.c`: generated tables vs. hand
  restatements; the whole composition over a deterministic register and
  source-memory model (2 opcode forms × 5 FLAGS codes × 4 displacements × 3 src
  regs × 3 count regs × 3 AUX count regs × 3 dst regs) comparing the whole
  register file, the whole memory array, and the flags; eight pins. **3264
  cases**, zero `-Wall -Wextra` warnings. Mutation-tested with arm swaps /
  literal changes: swapping the arms inside `KPROG_X86_BZHI_VALUE_SOURCE` or
  `KPROG_X86_BZHI_COUNT_SOURCE`, swapping the per-opcode value/count source
  names, and changing `KPROG_X86_BZHI_WRITE_WIDTH_DEFAULT` 64→32 each make it
  exit non-zero (a plain renumbering of the codes is vacuous — the oracle reads
  the codes).
- Full `make -C native-sim/formal check` passes with 0 errors, 67 generators,
  123 Lean module checks and 57 host cross-checks.

## Step 0049 — x86 `BT` / `BT_IMM` / `BT_MEM_IMM` base/index-source composition

- Scope: the three `X86_SIM_L_EXEC_BT` / `X86_SIM_L_EXEC_BT_IMM` /
  `X86_SIM_L_EXEC_BT_MEM_IMM` arms for `X86_OP_BT` (`0x37`), `X86_OP_BT_IMM`
  (`0x42`) and `X86_OP_BT_MEM_IMM` (`0x43`), the opcodes that test one bit and
  assign it to `CF`.
- Facts: all three resolve *one* width `FLAGS ? FLAGS : 64` and narrow the
  tested base to it before the bit test; there is no second memory width. The
  base and index sources are per-opcode table entries: `BT` reads its base from
  a register and its index from `SRC`, `BT_IMM` reads its base from a register
  and its index from the literal immediate, and `BT_MEM_IMM` reads its base
  from memory at the resolved width and its index from the immediate widened to
  32 bits. The headline fact is that index-width asymmetry: an immediate with a
  high bit set selects a different bit through the memory form than through the
  immediate form, because `BT_MEM_IMM` drops the high bits while `BT`/`BT_IMM`
  keep them. All three bodies write no register and touch only `CF`.
- Files: `native-sim/formal/generate_x86_bt_spec.py` + `x86_bt_spec.json`
  (schema_version 1, three-opcode `EXPECTED` table, `--check` rejects stale
  text) → `KProgFormal/GeneratedX86Bt.lean`, `generated/x86_bt.h`;
  `KProgFormal/X86BtHandler.lean`; oracle `test_x86_bt_host.c`. Wired into
  `KProgFormal.lean` and the Makefile `check` target. `x86_sim_local_bpf.h` is
  unchanged.
- Generated C: the three opcode-drift `_Static_assert`s, a local width-code
  block with a 64-bit drift assert, `KPROG_X86_BT_WRITE_WIDTH_DEFAULT
  X86_WIDTH_64`, the base-source codes + per-opcode base-source defines +
  `KPROG_X86_BT_BASE_SOURCE(OP_IS_MEMORY)`, the three index-source codes +
  per-opcode index-source defines + the nested
  `KPROG_X86_BT_INDEX_SOURCE(INDEX_IS_MEMORY, INDEX_IS_REGISTER)`
  (`MEMORY ? IMM32 : (REGISTER ? REGISTER : IMMEDIATE)`, a two-boolean
  selector — the split cannot be a single boolean), and the FLAGS-resolving
  `KPROG_X86_BT_WRITE_WIDTH(FLAGS)`. There is no count/mask macro: `BT` has no
  count.
- Lean: `BaseSource`/`IndexSource` tables +
  `x86_bt_base_source_refines`/`x86_bt_index_source_refines`;
  `x86BtCodeWidthSpec`/`generatedX86BtWriteWidth` + `x86_bt_write_width_refines`
  / `x86_bt_write_width_default_refines`; `x86BtBaseSpec`/`generatedX86BtBase` +
  `x86_bt_base_refines` (memory arm bridged through `x86_mem_load_refines`);
  `x86BtIndexSpec`/`generatedX86BtIndex` + `x86_bt_index_refines` (imm32 arm
  bridged through `x86_immediate_value_refines`) plus the index-width pin
  `x86_bt_imm32_drops_high_bits`; `x86BtCfSpec`/`generatedX86BtCf` +
  `x86_bt_cf_refines` (bridged through `x86_bt_refines_width`); `X86BtEffect`
  (data-only, `deriving DecidableEq, Repr`; carries `dst`/`zf`/`sf`/`of`
  through unchanged); `generatedX86BtStep`/`x86BtStepSpec` +
  `x86_bt_step_refines`; and the write shape pins (`x86_bt_preserves_dst`,
  `x86_bt_only_cf`, `x86_bt_base_sources`, `x86_bt_index_sources_differ`). The
  generated module declares its own `resolveWidth` (precedent
  `GeneratedX86Cmov.lean`); the handler does *not* import
  `KProgFormal.X86LogicFlags` (BT touches no logic-flag production) and does
  *not* import `KProgFormal.TagErasure`; it imports `KProgFormal.X86Bitops` for
  the `bt` refinement lemma (reused, no new generator for the helper).
- The final `x86_bt_step_refines` proof is `cases op <;> cases flagsCode <;>
  simp only [...]` — the `cases` must come *before* `simp only`, as in
  0047/0048. Concrete pins use `native_decide` after the defs are in scope.
- Independent C oracle `test_x86_bt_host.c`: generated tables vs. hand
  restatements; the whole composition over a deterministic register and
  source-memory model (3 opcode forms × 5 FLAGS codes × 4 raw imms × 3
  displacements × 3 base regs × 3 index regs × 3 dst regs) comparing the whole
  register file, the whole memory array, and the flags; eight pins. **4883
  cases**, zero `-Wall -Wextra` warnings. Mutation-tested with arm swaps /
  literal changes: swapping the arms inside `KPROG_X86_BT_BASE_SOURCE`,
  swapping the nested arms of `KPROG_X86_BT_INDEX_SOURCE`, swapping the
  per-opcode `..._BT_MEM_IMM_INDEX_SOURCE` name, and changing
  `KPROG_X86_BT_WRITE_WIDTH_DEFAULT` 64→32 each make it exit non-zero with a
  distinct message.
- Full `make -C native-sim/formal check` passes with 0 errors, 68 generators,
  125 Lean module checks and 58 host cross-checks.

## Step 0050 — x86 `CMP_IMM` / `CMP_REG` / `TEST_IMM` / `TEST_REG` source/flag-kind composition

- Scope: the two `X86_SIM_L_EXEC_CMP_IMM_OP` / `X86_SIM_L_EXEC_CMP_REG_OP`
  (and `_AUX`) arms serving `X86_OP_CMP_IMM` (`0x0c`), `X86_OP_CMP_REG`
  (`0x0d`), `X86_OP_TEST_IMM` (`0x0e`) and `X86_OP_TEST_REG` (`0x0f`), the four
  opcodes that compare or test without writing a register. The memory-source
  `X86_SIM_L_EXEC_CMP_MEM` family (`0x1c`–`0x1f`) is a different body and out of
  scope.
- Facts: all four resolve *one* width `FLAGS ? FLAGS : 64` and read their
  destination lane through the width/lane register read. Two per-opcode facts
  separate them, both provably independent table entries: the right-hand side is
  the decoded immediate for the `_IMM` forms and the width/lane register read of
  `SRC` for the `_REG` forms, and the flag kind is the zero-borrow subtraction
  flags for the `CMP` opcodes and the logical flags of the width-narrowed
  conjunction for the `TEST` opcodes. No register is written.
- Files: `native-sim/formal/generate_x86_cmpop_spec.py` + `x86_cmpop_spec.json`
  (schema_version 1, four-opcode `EXPECTED` table, `--check` rejects stale text)
  → `KProgFormal/GeneratedX86CmpOp.lean`, `generated/x86_cmpop.h`;
  `KProgFormal/X86CmpOpHandler.lean`; oracle `test_x86_cmpop_host.c`. Wired into
  `KProgFormal.lean` and the Makefile `check` target. `x86_sim_local_bpf.h` is
  unchanged.
- Generated C: the four opcode-drift `_Static_assert`s, a local width-code block
  with a 64-bit drift assert, `KPROG_X86_CMPOP_WRITE_WIDTH_DEFAULT X86_WIDTH_64`,
  the rhs-source codes (`RHS_IMMEDIATE`/`RHS_REGISTER`) with a per-opcode
  `..._RHS_SOURCE` define per opcode, the flag-kind codes
  (`FLAGS_SUB`/`FLAGS_LOGIC`) with a per-opcode `..._FLAG_KIND` define, the
  boolean `KPROG_X86_CMPOP_RHS_SOURCE(OP_IS_REG)` and
  `KPROG_X86_CMPOP_FLAG_KIND(OP_IS_TEST)` selectors, and the FLAGS-resolving
  `KPROG_X86_CMPOP_WRITE_WIDTH(FLAGS)`.
- Lean: `GeneratedX86CmpOp.Op`/`RhsSource`/`FlagKind` with `rhsSource`/
  `flagKind`/`resolveWidth` tables; the handler's `X86CmpOp` mirror + `x86CmpOpToOp`
  and independent `x86CmpOpRhsSourceSpec`/`x86CmpOpFlagKindSpec` (+
  `x86_cmpop_rhs_source_refines`/`x86_cmpop_flag_kind_refines`/
  `x86_cmpop_tables_independent`); `generatedX86CmpOpWriteWidth`/
  `x86CmpOpCodeWidthSpec` (+ `x86_cmpop_write_width_refines`/
  `_default_refines`); `generatedX86CmpOpRhs`/`x86CmpOpRhsSpec` (+
  `x86_cmpop_rhs_refines`, `_IMM` arm bridged through
  `x86_immediate_value_refines`, `_REG` arm through `x86_reg_read_at_refines`);
  `X86CmpOpEffect` (data-only, `deriving DecidableEq, Repr`);
  `generatedX86CmpOpStep`/`x86CmpOpStepSpec` + `x86_cmpop_step_refines` (the
  `CMP` arm bridged through `x86_sub_step_refines`, the `TEST` arm through
  `x86_zero_refines`/`x86_sign_refines`/`x86_logic_flags_refine`); and the shape
  pins `x86_cmpop_preserves_dst`/`x86_cmpop_flag_production`. The handler imports
  `GeneratedX86CmpOp`, `X86AluWriteback`, `X86Immediate`, `X86LogicFlags`,
  `X86RegRead`, `X86SubResult`, `X86Width`, and (`Std.Tactic.BVDecide`) for
  `native_decide`; it does *not* import `X86MemAccess` (register/immediate
  sources only) nor `TagErasure`. No new generator for the operands or flags —
  every read/flag bridge reuses an existing contract.
- The final `x86_cmpop_step_refines` proof is `cases op <;> cases flagsCode <;>
  simp only [...] <;> first | rw [x86_sub_step_refines] | rw [...]` — the
  `cases` must come *before* `simp only`, as in 0047/0048/0049. Concrete pins use
  `native_decide` after the defs are in scope.
- Independent C oracle `test_x86_cmpop_host.c`: generated tables vs. hand
  restatements; the whole composition over a deterministic register model (4
  opcodes × 5 FLAGS codes × 4 raw imms × 3 dst regs × 3 src regs × 2 dst lanes ×
  2 src lanes) comparing the resolved width, both operands, all four flags, the
  whole register file, and the whole memory array; nine pins. **2904 cases**,
  zero `-Wall -Wextra` warnings. Mutation-tested with arm swaps / literal
  changes: swapping the arms inside `KPROG_X86_CMPOP_FLAG_KIND`, swapping the
  arms inside `KPROG_X86_CMPOP_RHS_SOURCE`, swapping the per-opcode
  `..._CMP_IMM_FLAG_KIND` name, and changing
  `KPROG_X86_CMPOP_WRITE_WIDTH_DEFAULT` 64→32 each make it exit non-zero with a
  distinct message.
- Full `make -C native-sim/formal check` passes with 0 errors, 69 generators,
  127 Lean module checks and 59 host cross-checks.


## Next after 0050

The memory-source compare/test family (`X86_SIM_L_EXEC_CMP_MEM` for
`CMP`/`TEST [mem], rhs` and `X86_SIM_L_EXEC_CMP_REG_MEM` for `CMP reg, [mem]`)
was already composed in step 0029 (`X86MemCompareHandler.lean`, 40784-case
oracle), so with 0050 the register/immediate and memory compare/test surfaces
both have refinement theorems. The x86 ALU dispatch (`x86_alu_handler_refines` /
`x86_alu_aux_handler_refines`) and per-operation lane handlers
(`X86AluWriteback.lean`), the memory-source and memory-destination ALU handlers,
`IMUL`/`MULX`, `MOV`/`MOVX`/`LEA`/`STORE`, `SETCC`/`CMOV`/`MOVBE`, and the
XMM0/push-pop/rep-movs/call-mem families are likewise already proved.
Remaining open work is the index register decode and packed-AUX layout, the
simulator-stack-to-abstract-frame-base mapping, the register and immediate/RHS
objdump/parser-to-AUX selection relation, C-to-Lean unsigned-semantics
correspondence, compiler/native bytes, multi-step control-flow traces, and
specialization preservation.

## Step 0051 — AArch64 `.D0` / `.Q0` vector memory-transfer contract

- Scope: the four `ARM64_SIM_L_{LOAD,STORE}_{D0,Q0}_MEM` bodies
  (`native-sim/arm64/arm64_sim_local_bpf.h:675-713`), the opcodes that move a
  SIMD register's low 64-bit lane (`.D0`) or both 64-bit lanes (`.Q0`) to or
  from memory (`ARM64_OP_LOAD_D0` `0x28`, `ARM64_OP_STORE_D0` `0x29`,
  `ARM64_OP_LOAD_Q0` `0x2a`, `ARM64_OP_STORE_Q0` `0x2b`). Their dispatch is at
  `1008-1015`; the bodies share `ARM64_SIM_L_MEM_READ`/`_MEM_WRITE` and the
  pre/post base adjustment, but the *lane plan* is per-opcode.
- Shared JSON spec `arm64_dq_mem_spec.json` → generated
  `KProgFormal/GeneratedArm64DqMem.lean` + `generated/arm64_dq_mem.h` via
  `generate_arm64_dq_mem_spec.py` (`--check` rejects stale outputs). The contract
  fixes two independent per-opcode axes — the access direction
  (load/store) and the ordered 64-bit lane plan (`.D0` = `[0]`, `.Q0` =
  `[0, 8]`) — plus the lane stride (`ARM64_WIDTH_64` = 8) and the arm index of
  the four-way `OP == LOAD_D0 / LOAD_Q0 / STORE_D0 / STORE_Q0` chain. The
  address offset (`MEM_BASE_OFF`) and the pre/post base adjustment are
  deliberately *not* in scope: they already have the proved
  `arm64_mem_offset_refines` contract.
- `KProgFormal/Arm64DqMemHandler.lean`: independent lane plan
  `arm64DqMemPlanSpec` written as literals (`[0]` / `[0, 8]`), never the
  generated `n * 8` formula. `arm64_dq_mem_refines` pins the generated ordered
  lane offsets to the plan; `arm64_dq_mem_lane_count_refines` pins the generated
  lane count to the plan length; `arm64_dq_mem_access_dispatch` and
  `arm64_dq_mem_lane_plan` state the two per-opcode axes as conjunctions;
  `arm64_dq_mem_q0_moves_distinct_lanes` pins the two `.Q0` lanes differ;
  `arm64_dq_mem_arm_index_dispatch` pins the chain order; `arm64_dq_mem_lane_stride`,
  `arm64_dq_mem_low_lane_example`, `arm64_dq_mem_high_lane_example` give the
  concrete geometry.
- Host oracle `test_arm64_dq_mem_host.c`: Part 1 checks the generated constants
  and drives the `KPROG_ARM64_DQ_MEM_INDEX` selector against an independent
  opcode-code → arm-index map; Part 2 drives both the contract step (selectors +
  generated lane stride) and a model step restated from the raw opcode over a
  deterministic 32-register file, memory and stack for all 4 opcodes × 32 base
  registers × 3 flag sets × 4 index forms × 6 immediates = 9,216 cases, comparing
  the SIMD lanes, every GPR value/tag, memory and the stack. Prints
  `arm64 D0/Q0 mem host cross-check: OK (9216 cases)`.
- Mutation-tested: access-direction swap, lane-count swap, lane-stride change
  (caught by the generated C `_Static_assert`), and selector-arm swap each exit
  non-zero.
- No C body was edited (`arm64_sim_local_bpf.h` unchanged), so
  `make -C native-sim/arm64 micro-proofs-build` is not required for this step.
- Full `make -C native-sim/formal check` passes with 0 errors, 70 generators,
  129 Lean module checks, 60 host cross-checks.

## Next after 0051

With 0051 the AArch64 memory transfer surface has per-opcode contracts: the
generic read/write dispatch (`arm64_mem_dispatch_refines`), the address offset
(`arm64_mem_offset_refines`), the byte-lane scatter (`arm64_byte_lane`), the
stack slot-tag selection (`arm64_stack_tag`), and now the vector `.D0`/`.Q0`
lane plan. The remaining AArch64 open surfaces are the SIMD register file
mapping (the `__a64_v0`/`__a64_v0_hi` state fields to an abstract register
pair), the address-decoding of pre/post against the raw `AUX`/`IMM` fields, the
remaining SIMD element widths (`.S0`/`.H0`/`.B0` and the `.Q0` element
variants), and the C-to-Lean unsigned-semantics correspondence. On x86 the
remaining open work is unchanged from 0050: the index register decode and
packed-AUX layout, the simulator-stack-to-abstract-frame-base mapping, the
register and immediate/RHS objdump/parser-to-AUX selection relation, compiler/
native bytes, multi-step control-flow traces, and specialization preservation.

## Step 0052 — AArch64 `LDP` / `STP` pair-move contract

- Scope: the two `ARM64_SIM_L_LDP` / `ARM64_SIM_L_STP` bodies for
  `ARM64_OP_LDP` (`0x21`) / `ARM64_OP_STP` (`0x22`). One contract, two
  opcodes; the distinctive composition is the register-pair mapping (load:
  low slot→`DST`, high slot→`SRC`; store: low from `SRC`, high from `SRC2`).
- Out of scope (already proved): the address offset (`MEM_BASE_OFF`,
  `arm64_mem_offset_refines`), pre/post (`MEM_PRE`/`MEM_POST`), and the
  LDP tag-pair probe (`ARM64_SIM_L_MEM_READ_TAG`).
- Generated from `arm64_pair_mem_spec.json`:
  `KProgFormal/GeneratedArm64PairMem.lean` + `generated/arm64_pair_mem.h`
  (2 opcodes, `slot_stride` = `ARM64_WIDTH_64`, `slot_count` = 2,
  `high_slot_stride` = 8). Generator bug fixed: the two-opcode case makes the
  middle of the `OP == LDP / STP` chain empty, so the emitted
  `KPROG_ARM64_PAIR_MEM_INDEX` macro lost its line continuation and terminated
  early; `index_branches` now carries its own leading newlines.
- `KProgFormal/Arm64PairMemHandler.lean`: `arm64PairMemSlotPlanSpec` (literal
  `[0, 8]` for both), `arm64_pair_mem_refines`, `_slot_count_refines`,
  `_access_dispatch`, `_slot_plan`, `_slot_count`, `_moves_distinct_slots`,
  `_slot_stride`, `_arm_index_dispatch`, `_low_slot_example`,
  `_high_slot_example`.
- `test_arm64_pair_mem_host.c`: independent 465,696-case oracle. Part 1 checks
  the generated constants/selector against an independent table incl. an
  off-set opcode; Part 2 drives the full composition (pre/post writeback,
  read-before-write load gather so a target that is also the base reads the
  original base, register-pair mapping, tag clearing on GPR writes) as a
  contract step over the generated constants against a model step restated
  from the raw opcode with the literal stride 8, comparing GPR file, tags,
  memory and stack.
- Mutation test: 4/4 detected — access-direction swap, slot-count swap,
  slot-stride literal change, selector-arm swap (Lean mutation requires a
  `lake build` rebuild).
- Full `make -C native-sim/formal check` passes with 0 errors, 71 generators,
  131 Lean module checks, 61 host cross-checks.

## Next after 0052

With 0052 the AArch64 memory transfer surface has per-opcode contracts: the
generic read/write dispatch (`arm64_mem_dispatch_refines`), the address offset
(`arm64_mem_offset_refines`), the byte-lane scatter (`arm64_byte_lane`), the
stack slot-tag selection (`arm64_stack_tag`), the vector `.D0`/`.Q0` lane plan,
and now the `LDP`/`STP` pair plan. The remaining AArch64 open surfaces are the
SIMD register file mapping (the `__a64_v0`/`__a64_v0_hi` state fields to an
abstract register pair), the address-decoding of pre/post against the raw
`AUX`/`IMM` fields, the remaining SIMD element widths (`.S0`/`.H0`/`.B0` and the
`.Q0` element variants), `MADD`/`MSUB`/`UMULH` flag consequences, and the
C-to-Lean unsigned-semantics correspondence. On x86 the remaining open work is
unchanged from 0051: the index register decode and packed-AUX layout, the
simulator-stack-to-abstract-frame-base mapping, the register and immediate/RHS
objdump/parser-to-AUX selection relation, compiler/native bytes, multi-step
control-flow traces, and specialization preservation.

## Step 0053 — AArch64 pre/post-indexed address-writeback contract

- Scope: the decode of the packed memory-flag byte of an `ARM64_AUX_MEM` operand
  into the address-writeback form used by `ARM64_SIM_L_MEM_PRE` and
  `ARM64_SIM_L_MEM_POST`. The byte is the top byte of the packed `AUX` word
  (`aux >>> 24 & 0xff`, matching `ARM64_SIM_L_MEM_FLAGS`); `MEM_PRE` (`1`) and
  `MEM_POST` (`2`) are independent bits; each body's gate is the matching bit;
  the offset macro `MEM_BASE_OFF` suppresses its immediate exactly when either
  bit is set. This is distinct from the already-proved `arm64_mem_offset_refines`,
  which is stated over an already-decoded `prepost : Bool`.
- Semantics: both bits independent, so a byte with both set applies the same
  immediate twice (once before, once after) — a `writebackFormSpec` ordinal in
  `{0,1,2}`.
- Generated from `arm64_mem_prepost_spec.json`:
  `KProgFormal/GeneratedArm64MemPrepost.lean` + `generated/arm64_mem_prepost.h`
  (`pre_bit` = 1, `post_bit` = 2, `flags_shift` = 24, `flags_mask` = 255); the
  generator's `load()` re-checks `ARM64_MEM_PRE`/`ARM64_MEM_POST` in
  `native-sim/arm64/arm64_sim.h`.
- `KProgFormal/Arm64MemPrepost.lean`: `arm64_mem_prepost_flags_refines`,
  `_pre_writeback`, `_post_writeback`, `_suppress_offset`, `_delta_refines`,
  `_form_is_sum`, `_form_bounded`, plus `_offset_example`, `_post_example`,
  `_both_example`.
- `test_arm64_mem_prepost_host.c`: independent 4,608-case oracle. Part 1 checks
  the generated bit/shift/mask constants against independent literals and
  `native-sim/arm64/arm64_sim.h`'s `ARM64_MEM_PRE`/`ARM64_MEM_POST`; Part 2
  drives the generated decode/select macros over every flag byte crossed with
  low-byte noise (which must not leak into the flag byte) and a spread of
  immediates, restating the top-byte decode, the suppression gate and the two
  gated deltas from the raw `AUX` word.
- Mutation test: 5/5 detected — C pre-bit change (C static assertion),
  flag-shift 24→16 (oracle mismatch), C pre-delta gate bit swap (oracle
  mismatch), Lean `postWriteback` bit change and Lean `writebackFormSpec` bit
  change (refinement theorem, requires a `lake build` rebuild).
- Full `make -C native-sim/formal check` passes with 0 errors, 72 generators,
  133 Lean module checks, 62 host cross-checks.

## Next after 0053

With 0053 the AArch64 memory-flag decode surface now has contracts: the generic
read/write dispatch (`arm64_mem_dispatch_refines`), the address offset
(`arm64_mem_offset_refines`), the byte-lane scatter (`arm64_byte_lane`), the
stack slot-tag selection (`arm64_stack_tag`), the vector `.D0`/`.Q0` lane plan,
the `LDP`/`STP` pair plan, and now the pre/post writeback decode
(`arm64_mem_prepost_*`). The remaining AArch64 open surfaces are the SIMD
register file mapping (the `__a64_v0`/`__a64_v0_hi` state fields to an abstract
register pair), the remaining SIMD element widths (`.S0`/`.H0`/`.B0` and the
`.Q0` element variants), `MADD`/`MSUB`/`UMULH` flag consequences, and the
C-to-Lean unsigned-semantics correspondence. On x86 the remaining open work is
unchanged from 0052: the index register decode and packed-AUX layout, the
simulator-stack-to-abstract-frame-base mapping, the register and immediate/RHS
objdump/parser-to-AUX selection relation, compiler/native bytes, multi-step
control-flow traces, and specialization preservation.


## Step 0054 — AArch64 vector-register-file half-mapping contract

- Scope: the mapping from the four vector memory-transfer bodies
  (`ARM64_SIM_L_LOAD_{D0,Q0}_MEM`, `ARM64_SIM_L_STORE_{D0,Q0}_MEM`) onto the two
  independent 64-bit vector-register state fields `__a64_v0` (low half, slot
  offset 0) and `__a64_v0_hi` (high half, slot offset 8). A `.D0` transfer
  touches the low half only; a `.Q0` transfer touches the low half and then the
  high half. This is distinct from the already-proved `arm64_dq_mem_refines`,
  which fixes the *memory* lanes a transfer touches, not which vector-register
  state field each lane maps into.
- Semantics: two distinct half slots (low at 0, high at 8); the `.Q0` plan
  touches the low half before the high half, and a `.Q0` plan that aliased the
  two halves would not satisfy the plan.
- Generated from `arm64_vreg_spec.json`: `KProgFormal/GeneratedArm64Vreg.lean` +
  `generated/arm64_vreg.h` (`low_offset` = 0, `high_offset` = 8, four opcodes
  `LOAD_D0`/`LOAD_Q0`/`STORE_D0`/`STORE_Q0` with access, half count and arm
  index); the generator's `load()` re-checks the `__a64_v0`/`__a64_v0_hi`
  declarations in `native-sim/arm64/arm64_sim_local_bpf.h`.
- `KProgFormal/Arm64Vreg.lean`: `arm64_vreg_refines`,
  `arm64_vreg_half_count_refines`, `arm64_vreg_access_dispatch`,
  `arm64_vreg_half_plan`, `arm64_vreg_halves_distinct`,
  `arm64_vreg_q0_touches_distinct_halves`, `arm64_vreg_arm_index_dispatch`, plus
  `arm64_vreg_low_half_example`, `arm64_vreg_high_half_example`.
- `test_arm64_vreg_host.c`: independent 9,216-case oracle. Part 1 checks the
  generated offset/half/access/plan/index constants against independent literals
  including an off-set opcode; Part 2 drives the generated
  `KPROG_ARM64_VREG_HALF_OFFSET` / per-opcode `SELECT` / `HALVES` / `ACCESS`
  macros over every opcode crossed with all 32 base registers, the pre/post flag
  set and a spread of immediates and seeded vector-register state pairs,
  restating the same bodies from the raw opcode and confirming `.D0` leaves the
  high half untouched while `.Q0` writes low-then-high.
- Mutation test: 8/8 detected — C half-offset swap, D0 selector swap, half-count
  swap and Q0 order reversal (oracle mismatch or C static assertion), spec
  state-field-name swap and offset alias (generator `--check`), Lean
  plan-literal change and generated-`halfOffset` change (`lake build`
  refinement).
- Full `make -C native-sim/formal check` passes with 0 errors, 73 generators,
  135 Lean module checks, 63 host cross-checks.

## Next after 0054

With 0054 the AArch64 memory-transfer surface now has contracts for the generic
dispatch (`arm64_mem_dispatch_refines`), the address offset
(`arm64_mem_offset_refines`), the byte-lane scatter (`arm64_byte_lane`), the
stack slot-tag selection (`arm64_stack_tag`), the vector `.D0`/`.Q0` lane plan
(`arm64_dq_mem_refines`), the `LDP`/`STP` pair plan (`arm64_pair_mem_refines`),
the pre/post writeback decode (`arm64_mem_prepost_*`), and now the
vector-register-file half mapping (`arm64_vreg_*`). The remaining AArch64 open
surfaces are the remaining SIMD element widths (`.S0`/`.H0`/`.B0` and the `.Q0`
element variants), `MADD`/`MSUB`/`UMULH` flag consequences, and the C-to-Lean
unsigned-semantics correspondence. On x86 the remaining open work is unchanged
from 0053: the index register decode and packed-AUX layout, the
simulator-stack-to-abstract-frame-base mapping, the register and immediate/RHS
objdump/parser-to-AUX selection relation, compiler/native bytes, multi-step
control-flow traces, and specialization preservation.

## Step 0055 — AArch64 MVN/NEG unary-value contract

- Scope: the two unary value arms `ARM64_OP_MVN` (0x0f) and `ARM64_OP_NEG`
  (0x10) formerly inlined in the local dispatch, writing the
  destination-width-narrowed bitwise complement or two's-complement negation of
  a source register. The generated arm folds the destination-width mask
  (`narrow (~src) width`, `narrow (0 - src) width`) exactly as the caller's
  register write does, and is deliberately distinct from the family-level
  width-narrowing theorem `arm64_alu_result`.
- Semantics: MVN is an exclusive-or with the all-ones word; NEG is the
  invert-and-add-one two's-complement identity; both narrow to the destination
  width; neither writes NZCV.
- Generated from `arm64_unary_spec.json`: `KProgFormal/GeneratedArm64Unary.lean`
  + `generated/arm64_unary.h` (`mvn` = 15, `neg` = 16; `HANDLED`/`VALUE`
  macros).
- `KProgFormal/Arm64Unary.lean`: `arm64_unary_refines` (generated arm equals an
  independent spec — MVN as `src ^^^ 0xffffffffffffffff`, NEG as `~~~src + 1` —
  over both ops and all four widths), `arm64_unary_code_in_range`,
  `arm64_unary_code_dispatch`, `arm64_unary_flags_unchanged`,
  `arm64_unary_mvn_self_inverse`, `arm64_unary_neg_add_cancel`, the `w32`/`w8`
  bounds, plus five `native_decide` examples.
- `test_arm64_unary_host.c`: independent 40,081-case oracle deriving the width
  mask from a shift of one (not the macro's ladder), sweeping both ops over
  boundary vectors and all four widths plus 40,000 fixed-seed random cases, and
  confirming an unsupported opcode aborts.
- Sim wiring: `arm64_sim_local_bpf.h` now includes
  `../formal/generated/arm64_unary.h`, adds the `ARM64_SIM_L_UNARY_VALUE`
  wrapper, and replaces the two former inline arms with the
  `KPROG_ARM64_UNARY_HANDLED` branch — lifting the unary value out of the TCB.
- Mutation test: 5/5 detected — C case-body swap and dropped NEG width mask
  (oracle), spec code swap (generator `--check`), Lean NEG-identity and
  MVN-narrowing change (`lake build` refinement).
- Full `make -C native-sim/formal check` passes with 0 errors, 74 generators,
  137 Lean module checks, 64 host cross-checks; `make -C native-sim/arm64
  micro-proofs-build` rc=0.

## Next after 0055

The AArch64 unary surface is now proved and, unlike the preceding memory
contracts, its value arm is lifted out of the TCB. Remaining AArch64 candidates,
one contract per increment: `CNEG` (0x1a, condition-gated negation),
`ORN_REG`/`EON_REG` (complemented logical), the `ADRP` pair, `STLXR`, the
`MOV_IMM`/`MOV_REG` pair, and the sign-extending loads `LDRSB`/`LDRSW`/`LDRSH`
with writeback. The other open AArch64 surfaces are unchanged from 0054: the
remaining SIMD element widths (`.S0`/`.H0`/`.B0` and the `.Q0` element
variants), `MADD`/`MSUB`/`UMULH` flag consequences, and the C-to-Lean
unsigned-semantics correspondence. On x86 the remaining open work is unchanged
from 0054.

## Step 0056 — AArch64 CNEG condition-gated negation contract

- Scope: the condition-gated negation arm `ARM64_OP_CNEG` (0x41, 65) formerly
  inlined in the local dispatch, writing the source negated on a taken
  condition or passed through unchanged otherwise. The generated arm folds the
  destination-width mask (`narrow (if taken then 0 - src else src) width`)
  exactly as the caller's register write does.
- Semantics: on a taken condition the source is negated; otherwise it is
  unchanged; both narrow to the destination width; no NZCV is written. The
  independent statement uses the invert-and-add-one identity (`~~~src + 1`),
  deliberately not the subtraction operator the generated arm uses.
- Generated from `arm64_cneg_spec.json`: `KProgFormal/GeneratedArm64Cneg.lean`
  + `generated/arm64_cneg.h` (`cneg` = 65; `HANDLED`/`VALUE` macros).
- `KProgFormal/Arm64Cneg.lean`: `arm64_cneg_refines` (generated arm equals the
  independent spec over both condition outcomes and all four widths),
  `arm64_cneg_code_in_range`, `arm64_cneg_code_dispatch`,
  `arm64_cneg_flags_unchanged`, `arm64_cneg_taken_cancel`,
  `arm64_cneg_untaken_identity`, the `w32` bound, plus four `native_decide`
  examples.
- `test_arm64_cneg_host.c`: independent 40,097-case oracle deriving the width
  mask from a shift of one (not the macro's ladder), checking the negation
  against both the subtraction operator and the invert-and-add-one identity,
  sweeping both condition outcomes over boundary vectors and all four widths
  plus 40,000 fixed-seed random cases, and confirming an unsupported opcode
  aborts.
- Sim wiring: `arm64_sim_local_bpf.h` now includes
  `../formal/generated/arm64_cneg.h`, adds the `ARM64_SIM_L_CNEG_VALUE`
  wrapper, and replaces the former inline arm with the
  `KPROG_ARM64_CNEG_HANDLED` branch — lifting the condition-gated negation
  value out of the TCB.
- Mutation test: 7/7 detected — dropped/inverted condition gate and dropped
  width mask in the generated C (oracle), spec code move (generator `--check`),
  Lean branch swap and narrowing drop, and an independent-spec narrowing drop
  (`lake build` refinement).
- Full `make -C native-sim/formal check` passes with 0 errors, 75 generators,
  139 Lean module checks, 65 host cross-checks; `make -C native-sim/arm64
  micro-proofs-build` rc=0.

## Next after 0056

The AArch64 condition-gated value surface now has contracts for the CSEL family
(`arm64_csel_refines`/`arm64_csel_cond_refines`) and the single-op CNEG
(`arm64_cneg_refines`), both lifting their value arm out of the TCB. Remaining
AArch64 candidates, one contract per increment: `ORN_REG` (0x35, complemented
logical — note there is no `EON_REG` in `arm64_sim.h`), the `ADRP` pair,
`STLXR`, the `MOV_IMM`/`MOV_REG` pair, and the sign-extending loads
`LDRSB`/`LDRSW`/`LDRSH` with writeback. The other open AArch64 surfaces are
unchanged from 0055: the remaining SIMD element widths (`.S0`/`.H0`/`.B0` and
the `.Q0` element variants), `MADD`/`MSUB`/`UMULH` flag consequences, and the
C-to-Lean unsigned-semantics correspondence. On x86 the remaining open work is
unchanged from 0055.


## Step 0057 — AArch64 ORN complemented-logical-OR contract

- Scope: the complemented logical OR arm `ARM64_OP_ORN_REG` (0x35, 53)
  formerly inlined in the local dispatch, writing the OR of the first source
  with the bitwise complement of the already source-modified second source. The
  generated arm folds the destination-width mask (`narrow (lhs ||| ~~~rhs)
  width`) exactly as the caller's register write does.
- Semantics: `lhs | ~rhs`; the independent statement is the De Morgan form
  `~~~((~~~lhs) &&& rhs)`, deliberately not the OR-with-complement; both narrow
  to the destination width; no NZCV is written.
- Generated from `arm64_orn_spec.json`: `KProgFormal/GeneratedArm64Orn.lean` +
  `generated/arm64_orn.h` (`orn_reg` = 53; `HANDLED`/`VALUE` macros).
- `KProgFormal/Arm64Orn.lean`: `arm64_orn_refines` (generated arm equals the
  independent De Morgan statement over all four widths),
  `arm64_orn_de_morgan`, `arm64_orn_code_in_range`,
  `arm64_orn_code_dispatch`, `arm64_orn_flags_unchanged`,
  `arm64_orn_zero_rhs_all_ones`, `arm64_orn_zero_lhs_complement`, the `w32`
  bound, plus two `native_decide` examples.
- `test_arm64_orn_host.c`: independent 40,401-case oracle deriving the width
  mask from a shift of one (not the macro's ladder), applying both the De Morgan
  and direct OR-with-complement forms and requiring them equal, composing the
  existing `KPROG_ARM64_MOD_VALUE` contract for the right-hand source
  modification, sweeping both operands over boundary vectors and every modifier
  code across all four widths plus 40,000 fixed-seed random cases, and
  confirming an unsupported opcode aborts.
- Sim wiring: `arm64_sim_local_bpf.h` now includes
  `../formal/generated/arm64_orn.h`, adds the `ARM64_SIM_L_ORN_VALUE` wrapper,
  and replaces the former inline arm with the `KPROG_ARM64_ORN_HANDLED` branch —
  lifting the complemented-OR value out of the TCB.
- Mutation test: 7/7 detected — dropped complement, swapped OR, and dropped
  width mask in the generated C (oracle), spec code move (generator `--check`),
  a Lean complemented-lhs swap, and an independent-spec complement drop and
  narrowing drop (`lake build` refinement).
- Full `make -C native-sim/formal check` passes with 0 errors, 76 generators,
  141 Lean module checks, 66 host cross-checks; `make -C native-sim/arm64
  micro-proofs-build` rc=0.

## Next after 0057

The AArch64 complemented-logical surface now has a contract for the single
`ORN_REG` arm (`arm64_orn_refines`; note there is no `EON_REG` in
`arm64_sim.h`), lifting its value out of the TCB. Remaining AArch64 candidates,
one contract per increment: the `ADRP` pair, `STLXR`, the `MOV_IMM`/`MOV_REG`
pair, and the sign-extending loads `LDRSB`/`LDRSW`/`LDRSH` with writeback. The
other open AArch64 surfaces are unchanged from 0056: the remaining SIMD element
widths (`.S0`/`.H0`/`.B0` and the `.Q0` element variants),
`MADD`/`MSUB`/`UMULH` flag consequences, and the C-to-Lean unsigned-semantics
correspondence. On x86 the remaining open work is unchanged from 0056.


## Step 0058 — AArch64 ADRP relocation-tag selection contract

- Scope: the two page-address opcodes `ARM64_OP_ADRP_GOT` (0x26, 38) and
  `ARM64_OP_ADRP_RODATA` (0x27, 39). Both wrote through
  `ARM64_SIM_L_WRITE_REG_PTR_TAG` with an inline `?:` choosing the provenance
  tag; the selected tag is now the generated contract and the write stays in the
  TCB.
- Semantics: GOT tags the page-address write as a relocation address
  (`ARM64_SIM_TAG_RELOC_ADDR`, 7) and RODATA as a read-only-data address
  (`ARM64_SIM_TAG_RODATA_ADDR`, 8); no NZCV is written.
- Generated from `arm64_adrp_spec.json`: `KProgFormal/GeneratedArm64Adrp.lean` +
  `generated/arm64_adrp.h` (`got`=38, `rodata`=39; `HANDLED`/`TAG` macros). The
  generator re-checks both the opcodes against `arm64_sim.h` and the tag values
  against `arm64_sim_local_bpf.h`.
- `KProgFormal/Arm64Adrp.lean`: `arm64_adrp_tag_refines` (the generated table
  equals an independent Boolean-indexed base-plus-offset selection),
  `arm64_adrp_isgot_refines` (the GOT/RODATA classification matches the opcode),
  `arm64_adrp_code_dispatch`, `arm64_adrp_tags_distinct`,
  `arm64_adrp_tag_in_range`.
- `test_arm64_adrp_host.c`: independent oracle classifying the opcode itself
  (not the macro ladder), requiring the two tags distinct and in range, and
  exhaustively driving all 256 opcode bytes in forked children (known kinds
  return the oracle tag; unknown bytes abort through the generated unsupported
  arm): 257 cases.
- Sim wiring: `arm64_sim_local_bpf.h` includes `../formal/generated/arm64_adrp.h`
  (placed *after* the `ARM64_SIM_TAG_*` definitions, because the generated
  header's `_Static_assert`s reference them), adds the `ARM64_SIM_L_ADRP_TAG`
  wrapper, and replaces the inline `?:` arm with the `KPROG_ARM64_ADRP_HANDLED`
  branch calling the generated macro.
- Mutation test: 7/7 detected — swapped relocation tag, moved case label, spec
  code move, spec tag change (generator `--check`), and a generated-table value
  change, an independent-spec base change, and a flipped GOT classification
  (`lake build` refinement).
- Full `make -C native-sim/formal check` passes with 0 errors, 77 generators,
  143 Lean module checks, 67 host cross-checks; `make -C native-sim/arm64
  micro-proofs-build` rc=0.

## Next after 0058

The AArch64 ADRP page-address surface now has a relocation-tag contract
(`arm64_adrp_tag_refines`), lifting the tag selection out of the TCB; the
immediate page address and the tagged-pointer write remain outside. Remaining
AArch64 candidates, one contract per increment: `STLXR`, the `MOV_IMM`/`MOV_REG`
pair, and the sign-extending loads `LDRSB`/`LDRSW`/`LDRSH` with writeback. The
other open AArch64 surfaces are unchanged from 0057: the remaining SIMD element
widths (`.S0`/`.H0`/`.B0` and the `.Q0` element variants),
`MADD`/`MSUB`/`UMULH` flag consequences, and the C-to-Lean unsigned-semantics
correspondence. On x86 the remaining open work is unchanged from 0056.


## Step 0059 — AArch64 STLXR exclusive-store status contract

- Scope: the single store-release-exclusive opcode `ARM64_OP_STLXR` (0x38, 56).
  The handler wrote an inline success code `0` at word width; the status value is
  now the generated contract.
- Semantics: the store-exclusive succeeds unconditionally in this simulator, so
  the status written back to the destination register is the success code `0`
  narrowed to `ARM64_WIDTH_32` (the width the handler writes); no NZCV is
  written. The memory write, the source-register value and tag reads, and the
  status-register write stay in the TCB.
- Generated from `arm64_stlxr_spec.json`:
  `KProgFormal/GeneratedArm64Stlxr.lean` + `generated/arm64_stlxr.h`
  (`stlxr`=56; `HANDLED`/`VALUE` macros). The generator re-checks the opcode
  against `arm64_sim.h`.
- `KProgFormal/Arm64Stlxr.lean`: `arm64_stlxr_refines` (the generated arm equals
  an independent statement forming the status as the width mask minus itself),
  `arm64_stlxr_success_zero`, `arm64_stlxr_code_dispatch`,
  `arm64_stlxr_code_in_range`, `arm64_stlxr_flags_unchanged`,
  `arm64_stlxr_w32_bound`, plus two worked examples.
- `test_arm64_stlxr_host.c`: independent oracle deriving the width mask from a
  shift of one (not the macro ladder), forming the success code as that mask
  minus itself, requiring it zero at every width, then sweeping all 256 opcode
  bytes across all four destination widths in forked children (known opcodes
  return the zero status; unknown bytes abort through the generated unsupported
  arm): 1028 cases.
- Sim wiring: `arm64_sim_local_bpf.h` includes
  `../formal/generated/arm64_stlxr.h` (after the `ARM64_SIM_TAG_*` block, beside
  the adrp include), adds the `ARM64_SIM_L_STLXR_VALUE` wrapper, and replaces the
  inline status write with the `KPROG_ARM64_STLXR_HANDLED` branch calling the
  generated macro.
- Mutation test: 6/6 detected — a nonzero success status, a dropped width
  narrowing, and a moved case label in the generated C, a spec code move, and a
  nonzero generated status and a nonzero independent-spec code in Lean.
- Full `make -C native-sim/formal check` passes with 0 errors, 78 generators,
  145 Lean module checks, 68 host cross-checks; `make -C native-sim/arm64
  micro-proofs-build` rc=0.

## Next after 0059

The AArch64 exclusive-store surface now has a success-status contract
(`arm64_stlxr_refines`), lifting the status encoding out of the TCB. Remaining
AArch64 candidates, one contract per increment: the `MOV_IMM`/`MOV_REG` pair
(provenance-tag propagation) and the sign-extending loads
`LDRSB`/`LDRSW`/`LDRSH` with writeback. The other open AArch64 surfaces are
unchanged from 0058: the remaining SIMD element widths (`.S0`/`.H0`/`.B0` and the
`.Q0` element variants), `MADD`/`MSUB`/`UMULH` flag consequences, and the
C-to-Lean unsigned-semantics correspondence. On x86 the remaining open work is
unchanged from 0056.


## Step 0060 — AArch64 MOV provenance-path contract

- Scope: the two move opcodes `ARM64_OP_MOV_IMM` (0x01, 1) and
  `ARM64_OP_MOV_REG` (0x02, 2). The handler chose between the tag-copy register
  write and a width-narrowed scalar write with an inline `if (width == 64)`;
  which path runs is now the generated contract.
- Semantics: the routing decision is fixed by the mnemonic plus the access width.
  `MOV_IMM` always writes a width-narrowed value (its source is an immediate, so
  it drops any provenance tag); `MOV_REG` copies the source register's tag only
  at `ARM64_WIDTH_64` and otherwise writes a scalar, dropping the tag. The
  surrounding reads, the tag value, and both register writes stay in the TCB.
- Generated from `arm64_mov_spec.json`: `KProgFormal/GeneratedArm64Mov.lean` +
  `generated/arm64_mov.h` (`movImm`=1, `movReg`=2;
  `HANDLED`/`PTR_TAG_PATH` macros). The generator re-checks both opcodes against
  `arm64_sim.h`.
- `KProgFormal/Arm64Mov.lean`: `arm64_mov_path_refines` (the generated table
  equals an independent "register-source move and doubleword width" predicate),
  `arm64_mov_imm_never_ptr`, `arm64_mov_reg_ptr_iff_w64`,
  `arm64_mov_reg_sub_word_drops`, `arm64_mov_width_matters`,
  `arm64_mov_code_dispatch`, the two code-range pins, plus two worked examples.
- `test_arm64_mov_host.c`: independent oracle deciding tag preservation from the
  mnemonic class and the width (not the macro switch), sweeping all 256 opcode
  bytes across all four widths in forked children (known moves return the oracle
  path; unknown opcodes abort through the generated unsupported arm): 1024 cases.
- Sim wiring: `arm64_sim_local_bpf.h` includes `../formal/generated/arm64_mov.h`,
  adds the `ARM64_SIM_L_MOV_PTR_TAG_PATH` wrapper, and replaces the two inline
  `MOV_IMM`/`MOV_REG` arms with one `KPROG_ARM64_MOV_HANDLED` branch that
  dispatches on the generated macro.
- Mutation test: 7/7 detected — a MOV_IMM wrongly taking the tag-copy path, a
  MOV_REG tag-copy ignoring the width, a moved case label, and a dropped coverage
  disjunct in the generated C, a spec code swap, and a generated sub-word
  register-move tagging and an independent-width-condition drop in Lean.
- Full `make -C native-sim/formal check` passes with 0 errors, 79 generators,
  147 Lean module checks, 69 host cross-checks; `make -C native-sim/arm64
  micro-proofs-build` rc=0.

## Next after 0060

The AArch64 move surface now has a provenance-path contract
(`arm64_mov_path_refines`), lifting the tag-copy-versus-narrow routing out of the
TCB. Remaining AArch64 candidates, one contract per increment: the
sign-extending loads `LDRSB`/`LDRSW`/`LDRSH` with writeback. The other open
AArch64 surfaces are unchanged from 0059: the remaining SIMD element widths
(`.S0`/`.H0`/`.B0` and the `.Q0` element variants), `MADD`/`MSUB`/`UMULH` flag
consequences, and the C-to-Lean unsigned-semantics correspondence. On x86 the
remaining open work is unchanged from 0056.

## Step 0061 — AArch64 sign-extending-load width contract

- Scope: the three load-sign-extend opcodes `ARM64_OP_LDRSB` (0x36, 54),
  `ARM64_OP_LDRSW` (0x39, 57), and `ARM64_OP_LDRSH` (0x3f, 63). The handlers read
  a hardcoded memory width before sign-extending the loaded value into the
  destination; which load width each opcode reads is now the generated contract.
- Semantics: the load width is fixed by the opcode's numeric code alone — a byte
  load reads a byte, a halfword load a halfword, a word load a word, independent
  of the destination access width. The three widths are pairwise distinct, and
  every one is below 64 so the shared sign-extension step is always load-bearing.
- Generated from `arm64_ldrsx_spec.json`: `KProgFormal/GeneratedArm64LdrSx.lean`
  + `generated/arm64_ldrsx.h` (`ldrSb`=54, `ldrSw`=57, `ldrSh`=63;
  `HANDLED`/`LOAD_WIDTH` macros). The generator re-checks all three opcodes
  against `arm64_sim.h`.
- `KProgFormal/Arm64LdrSx.lean`: `arm64_ldrsx_width_refines` (the generated table
  equals an independent numeric-code-keyed statement),
  `arm64_ldrsx_width_code_determined`, `arm64_ldrsx_widths_distinct`,
  `arm64_ldrsx_bytes_match`, `arm64_ldrsx_width_lt_64`, `arm64_ldrsx_code_dispatch`,
  the three code-range pins, `arm64_ldrsx_flags_unchanged`, plus two examples.
- `test_arm64_ldrsx_host.c`: independent oracle deciding the load width from the
  numeric opcode code (not the macro switch), sweeping all 256 opcode bytes in
  forked children (known loads return the oracle width; unknown opcodes abort
  through the generated unsupported arm): 256 cases.
- Sim wiring: `arm64_sim_local_bpf.h` includes `../formal/generated/arm64_ldrsx.h`,
  adds the `ARM64_SIM_L_LDRSX_LOAD_WIDTH` wrapper, and replaces the three inline
  `LDRSB`/`LDRSW`/`LDRSH` arms with one `KPROG_ARM64_LDRSX_HANDLED` branch whose
  memory read is keyed on the generated `KPROG_ARM64_LDRSX_LOAD_WIDTH` and whose
  sign-extension operand is selected from the opcode.
- Mutation test: 7/7 detected — a byte load that reads a word, a word load that
  reads a halfword, a moved case label, and a dropped coverage disjunct in the
  generated C, a spec load-width swap, and a generated halfword-load that reads a
  byte and an independent code-to-word mislabel in Lean.
- Full `make -C native-sim/formal check` passes with 0 errors, 80 generators,
  149 Lean module checks, 70 host cross-checks; `make -C native-sim/arm64
  micro-proofs-build` rc=0.

## Next after 0061

The AArch64 sign-extending-load surface now has a load-width contract
(`arm64_ldrsx_width_refines`), lifting the load-width decision out of the TCB.
Remaining AArch64 candidates, one contract per increment: the remaining SIMD
element widths (`.S0`/`.H0`/`.B0` and the `.Q0` element variants), the
`MADD`/`MSUB`/`UMULH` flag consequences, and the C-to-Lean unsigned-semantics
correspondence. On x86 the remaining open work is unchanged from 0056.

## Step 0062 — AArch64 plain-load provenance-preservation contract

- Scope: the ordinary `LDR` (`ARM64_OP_LOAD`, 0x1f, 31). The handler chose
  between the tag-copy register write and the tag-dropping width-narrowed scalar
  write with an inline `width == 64 && tag != SCALAR`; whether a load preserves
  the memory-read provenance tag is now the generated contract.
- Semantics: the tag survives a load only at doubleword width and only when it is
  not the bare scalar tag. A sub-word load is a scalar narrowing (dropping the
  tag) and a doubleword load of a scalar value has nothing to preserve, so only
  the doubleword non-scalar load carries provenance.
- Generated from `arm64_load_tag_spec.json`: `KProgFormal/GeneratedArm64LoadTag.lean`
  + `generated/arm64_load_tag.h` (`KPROG_ARM64_LOAD_TAG_PRESERVE`). The generator
  re-checks the opcode against `arm64_sim.h`.
- `KProgFormal/Arm64LoadTag.lean`: `arm64_load_tag_refines` (the generated table
  equals an independent bit-count-and-scalar-class statement),
  `arm64_load_tag_sub_word_drops`, `arm64_load_tag_scalar_drops`,
  `arm64_load_tag_w64_non_scalar_preserves`, `arm64_load_tag_preserve_iff`,
  `arm64_load_tag_preserving_width_is_w64`, `arm64_load_tag_code_dispatch`,
  `arm64_load_tag_code_in_range`, plus two examples.
- `test_arm64_load_tag_host.c`: independent oracle deciding preservation from the
  width and tag class (not the macro switch), sweeping all 256 opcode bytes
  crossed with the four widths and the two tag classes in forked children: 2048
  cases.
- Sim wiring: `arm64_sim_local_bpf.h` includes
  `../formal/generated/arm64_load_tag.h`, adds the
  `ARM64_SIM_L_LOAD_TAG_PRESERVE` wrapper, and replaces the inline LOAD `if`
  with the generated macro.
- Mutation test: 7/7 detected — a preservation that ignores the width, one that
  ignores the scalar class, a moved case label, a wrongly inverted scalar guard,
  a spec preserve-rule change, a generated guard drop, and an independent
  scalar-class inversion in Lean.
- Full `make -C native-sim/formal check` passes with 0 errors, 81 generators,
  151 Lean module checks, 71 host cross-checks; `make -C native-sim/arm64
  micro-proofs-build` rc=0.

## Next after 0062

The AArch64 ordinary-load surface now has a provenance-preservation contract
(`arm64_load_tag_refines`), lifting the tag-copy-versus-narrow routing out of the
TCB. Remaining AArch64 candidates, one contract per increment: the remaining SIMD
element widths (`.S0`/`.H0`/`.B0` and the `.Q0` element variants), the
`MADD`/`MSUB`/`UMULH` flag consequences, and the C-to-Lean unsigned-semantics
correspondence. On x86 the remaining open work is unchanged from 0056.

## Step 0063 — AArch64 pair-load provenance-preservation contract

- Scope: the pair load `LDP` (`ARM64_OP_LDP`, 0x21, 33). The handler reads two
  64-bit slots, each with its own tag, and decided per slot between the tag-copy
  register write and the tag-dropping width-narrowed scalar write, under an outer
  pair gate `width == 64 && (tagLo != SCALAR || tagHi != SCALAR)`; whether each
  slot preserves its tag is now the generated contract.
- Semantics: the mask has bit 0 set exactly when the low slot preserves its tag
  and bit 1 exactly when the high slot does; a slot preserves exactly at
  doubleword width and when its tag is not the bare scalar tag. The gate is
  redundant with the per-slot rule and the theorem proves that.
- Generated from `arm64_pair_load_tag_spec.json`:
  `KProgFormal/GeneratedArm64PairLoadTag.lean` + `generated/arm64_pair_load_tag.h`
  (`KPROG_ARM64_PAIR_LOAD_TAG_ROUTE` and its ROUTE_LOW/ROUTE_HIGH accessors). The
  generator re-checks the opcode against `arm64_sim.h`.
- `KProgFormal/Arm64PairLoadTag.lean`: `arm64_pair_load_tag_refines`,
  `arm64_pair_load_tag_gate_iff`, `arm64_pair_load_tag_both_scalar`,
  `arm64_pair_load_tag_sub_word_drops`, the three per-slot-case lemmas,
  `arm64_pair_load_tag_routing_width_is_w64`, `arm64_pair_load_tag_slot_count`,
  the opcode lemmas, plus two examples.
- `test_arm64_pair_load_tag_host.c`: independent oracle deciding each slot's bit
  from the width and that slot's tag class (not the macro gate), sweeping all 256
  opcode bytes crossed with the four widths and the four tag-class pairs in forked
  children: 4096 cases.
- Sim wiring: `arm64_sim_local_bpf.h` includes
  `../formal/generated/arm64_pair_load_tag.h`, adds the
  `ARM64_SIM_L_PAIR_LOAD_TAG_ROUTE` wrapper, and replaces the inline LDP gate and
  per-slot branches with the generated routing mask and its two slot accessors.
- Mutation test: 7/7 detected — a gate that drops the width conjunct, a high slot
  routed by the low slot's tag, a moved case label, swapped slot route bits, a
  spec preserve-rule change, a generated gate width-drop, and an independent
  slot-weight swap in Lean.
- Full `make -C native-sim/formal check` passes with 0 errors, 82 generators,
  153 Lean module checks, 72 host cross-checks; `make -C native-sim/arm64
  micro-proofs-build` rc=0.

## Next after 0063

The AArch64 pair-load surface now has a routing contract
(`arm64_pair_load_tag_refines`). Remaining AArch64 candidates, one contract per
increment: the remaining SIMD element widths (`.S0`/`.H0`/`.B0` and the `.Q0`
element variants), the `MADD`/`MSUB`/`UMULH` flag consequences, and the C-to-Lean
unsigned-semantics correspondence. On x86 the remaining open work is unchanged
from 0056.

## Step 0064 — AArch64 FMOV destination-routing contract

- Scope: the vector/register move `FMOV` (`ARM64_OP_FMOV`, 0x23, 35). The handler
  applies the generated `KPROG_ARM64_FMOV_VALUE` selection and then decided which
  register file receives the result with the inline disjunction
  `AUX == D_FROM_X || AUX == S_FROM_W`; that destination routing is now the
  generated contract.
- Semantics: a direction routes to the vector register `v0` exactly when it is one
  of the four in-range codes with an even parity; the two register-half
  directions route to the general-purpose destination through the width-narrowed
  register write.
- Generated from `arm64_fmov_dest_spec.json`:
  `KProgFormal/GeneratedArm64FmovDest.lean` + `generated/arm64_fmov_dest.h`
  (`KPROG_ARM64_FMOV_DEST_VECTOR`). The generator re-checks the FMOV opcode and
  the four direction codes against `arm64_sim.h`.
- `KProgFormal/Arm64FmovDest.lean`: `arm64_fmov_dest_refines` (the generated
  routing equals an independent parity-and-range statement),
  `arm64_fmov_dest_parity`, `arm64_fmov_dest_out_of_range`,
  `arm64_fmov_dest_complement`, the opcode lemmas, and two examples.
- `test_arm64_fmov_dest_host.c`: independent oracle deciding the routing bit from
  the direction code's parity and range (not the macro switch), sweeping the
  direction over all 256 byte values in forked children: 256 cases.
- Sim wiring: `arm64_sim_local_bpf.h` includes
  `../formal/generated/arm64_fmov_dest.h` and replaces the inline FMOV routing
  disjunction with the generated predicate.
- Mutation test: 7/7 detected — two direction arms flipped onto the wrong
  register file, a moved case label, an opcode static-assert drift, a spec
  routing-rule change, a generated routing arm parity drop, and an independent
  parity flip in Lean.
- Full `make -C native-sim/formal check` passes with 0 errors, 83 generators,
  155 Lean module checks, 73 host cross-checks; `make -C native-sim/arm64
  micro-proofs-build` rc=0.

## Next after 0064

The AArch64 FMOV surface now has both a value contract (`arm64_fmov_refines`) and
a destination-routing contract (`arm64_fmov_dest_refines`). Remaining AArch64
candidates, one contract per increment: the remaining SIMD element widths
(`.S0`/`.H0`/`.B0` and the `.Q0` element variants), the `MADD`/`MSUB`/`UMULH` flag
consequences, and the C-to-Lean unsigned-semantics correspondence. On x86 the
remaining open work is unchanged from 0056.

## Step 0065 — AArch64 conditional-select pointer-path contract

- Scope: the eight-member conditional-select family
  (`KPROG_ARM64_CSEL_HANDLED`: `CSEL` 0x1c=28, `CINC` 0x1d=29, `CSET` 0x1e=30,
  `CINV` 0x34=52, `CSINV` 0x3d=61, `CSINC` 0x3e=62, `CSETM` 0x44=68,
  `CSNEG` 0x45=69). The handler inlined
  `(OP) == ARM64_OP_CSEL && width == ARM64_WIDTH_64` to select between the
  tag-copy register write (`ARM64_SIM_L_WRITE_REG_PTR_TAG`, carrying the selected
  source register's provenance tag) and the tag-dropping width-narrowed scalar
  write; that pointer-path routing is now the generated contract. The value
  contract `arm64_csel_refines` does not cover the pointer path.
- Semantics: the destination takes the pointer path exactly when the operation is
  the plain `CSEL` and the access is doubleword width; every other family member
  and every sub-word width drops the tag.
- Generated from `arm64_csel_ptr_spec.json`:
  `KProgFormal/GeneratedArm64CselPtr.lean` + `generated/arm64_csel_ptr.h`
  (`KPROG_ARM64_CSEL_PTR_TAG_PATH`). The generator reuses the eight-opcode family
  table in `arm64_csel_spec.json` and re-checks the opcode numbers against
  `arm64_sim.h`.
- `KProgFormal/Arm64CselPtr.lean`: `arm64_csel_ptr_refines` (the generated
  `ptrTagPath` equals an independent operation-and-width statement),
  `arm64_csel_ptr_only_csel`, `arm64_csel_ptr_csel_iff_w64`,
  `arm64_csel_ptr_csel_sub_word_drops`, `arm64_csel_ptr_family_drops`, the opcode
  lemmas, and three examples.
- `test_arm64_csel_ptr_host.c`: independent oracle deciding the pointer path from
  the opcode class and the access width (not the macro switch), sweeping the
  opcode over all 256 byte values and all four widths in forked children: 1024
  cases.
- Sim wiring: `arm64_sim_local_bpf.h` includes
  `../formal/generated/arm64_csel_ptr.h` (after the csel header) and replaces the
  inline pointer-path test with the generated predicate.
- Mutation test: 7/7 detected — the pointer family arm inverted, a sub-word width
  accepted on the pointer arm, a family arm flipped onto the width test, a moved
  case label, an opcode static-assert drift, a spec pointer-op change, and a
  generated/independent pointer-rule divergence in Lean.
- Full `make -C native-sim/formal check` passes with 0 errors, 84 generators,
  157 Lean module checks, 74 host cross-checks; `make -C native-sim/arm64
  micro-proofs-build` rc=0.

## Next after 0065

The AArch64 conditional-select family now has both a value contract
(`arm64_csel_refines`) and a pointer-path routing contract
(`arm64_csel_ptr_refines`). Remaining AArch64 candidates, one contract per
increment: the wide immediate-vs-register RHS selection shared by the
ADDS/SUBS/CMP/CMN/TST/ANDS/CCMP flag arms (generalizing the single-opcode
`arm64_alu_operand` precedent to the family), and the C-to-Lean
unsigned-semantics correspondence. `SHIFT_IMM`/`SHIFT_REG` amount selection is
also inline but is subsumed by the shift value contract. On x86 the remaining
open work is unchanged from 0056.

## Step 0066 — AArch64 flag-family operand-source contract

- Scope: the six NZCV-producing arm pairs
  `SUBS`/`ADDS`/`CMP`/`TST`/`ANDS`/`CCMP` (`SUBS_IMM`/`SUBS_REG` and the five
  other pairs) in `arm64_sim_local_bpf.h`. Each arm inlined
  `(__u64)(IMM)` vs a register expression behind
  `(OP) == ARM64_OP_<F>_IMM`; the register expression is modifier-rewritten for
  SUBS/ADDS/CMP/TST/ANDS and a bare `ARM64_SIM_L_READ_REG(SRC)` for CCMP.
- Contract: `arm64_flag_operand_spec.json` -> `GeneratedArm64FlagOperand.lean`
  (a twelve-member `FlagOp` inductive, `code`, and `immediate : FlagOp -> Bool`)
  + `generated/arm64_flag_operand.h` (`KPROG_ARM64_FLAG_RHS(OP, IMM, REG)`). The
  macro yields `IMM` exactly on the six immediate case labels and `REG`
  otherwise, evaluating `OP`/`IMM`/`REG` once each. The twelve opcode numbers
  are re-checked against `native-sim/arm64/arm64_sim.h` both in the generator
  and by `_Static_assert`s.
- Proof: `arm64_flag_operand_refines` proves the generated table agrees with an
  independent membership test over a named immediate-opcode list; the
  `immediate_iff_mem`, `reg_never_immediate`, `lists_disjoint`,
  `pairs_exclusive`, `code_dispatch` and `code_in_range` theorems pin the
  binding cases. Host oracle
  (`test_arm64_flag_operand_host.c`) sweeps all 256 opcodes against an
  independent opcode-class oracle; 5120 cases OK.
- Wiring: dispatcher includes `../formal/generated/arm64_flag_operand.h` after
  the `arm64_alu_operand.h` include; six inline ternaries replaced by
  `KPROG_ARM64_FLAG_RHS`. `micro-proofs-build` rc=0; nine binding mutations all
  DETECTED (`/tmp/mut_flag_operand.py`); post-restore `--check` OK.
- Full `make -C native-sim/formal check` passes with 0 errors, 85 generators,
  159 Lean modules, 75 host cross-checks.

## Next after 0066

The AArch64 flag-arm operand source now joins the conditional-select family
under a generated contract. The remaining genuine AArch64 item is the C-to-Lean
unsigned-semantics correspondence. On x86 the remaining open work is unchanged
from 0056.

## Step 0067 — AArch64 width/narrowing independent-spec contract

- Scope: the AArch64 width contract (`GeneratedArm64Width` from
  `arm64_width_spec.json`: `Width`, `code`, `mask`, `signMask`, `bits`,
  `narrow`, `zero`, `sign`) had no standalone independent Lean module and no
  host oracle; the arm64 mask/narrowing was restated inline in
  `Arm64AluResult.lean`. The x86 side already carried the analogous
  independent module (`X86Width.lean`). This closes that arm64 gap — the
  concrete instance of the open "C-to-Lean unsigned-semantics correspondence"
  item.
- `KProgFormal/Arm64Width.lean`: independent `arm64WidthCodeSpec`,
  `arm64WidthMaskSpec`, `arm64WidthSignMaskSpec`, `arm64WidthBitsSpec`,
  `arm64NarrowSpec`, `arm64ZeroSpec`, `arm64SignSpec` plus
  `arm64_width_code_refines`, `arm64_width_mask_refines`,
  `arm64_width_sign_mask_refines`, `arm64_width_bits_refines`,
  `arm64_narrow_refines`, `arm64_zero_refines`, `arm64_sign_refines`, and
  `arm64_sign_mask_observes` (the sign-mask test equals the shift-based sign
  observation, so the C `KPROG_ARM64_WIDTH_SIGN_MASK` test and the generated
  `sign` pick the same bit).
- Clean cutover: `Arm64AluResult.lean` now imports `Arm64Width` and drops the
  duplicate inline `arm64WidthMaskSpec`/`arm64NarrowSpec`/`arm64_narrow_refines`
  definitions (reused from the new module).
- `test_arm64_width_host.c`: independent oracle built only from the width bit
  count, verifying `KPROG_ARM64_WIDTH_MASK`/`_SIGN_MASK`/`_BITS` and
  `KPROG_ARM64_APPLY_WIDTH` over boundary vectors and a fixed-seed random
  stream across all four widths: 40080 cases OK.
- Mutation test: 9/9 detected — a width mask, a sign mask, a bit count, an
  APPLY_WIDTH mask drop, a width-code static-assert drift, a spec mask change,
  a generated mask flip, an independent sign-mask flip, and an independent
  bit-count change.

## Next after 0067

The AArch64 width/narrowing contract now has the same standalone independent
spec module and host oracle as x86 width. On x86 the remaining open work is
unchanged from 0056.

## Step 0068 — AArch64 condition-code independent-spec contract

- Scope: the AArch64 condition contract (`GeneratedArm64Cond` from
  `arm64_cond_spec.json`), previously only a fragment of `Arm64ControlFlow.lean`
  with no dedicated host oracle.
- Generator: extended `generate_arm64_cond_spec.py::render_lean` to also emit
  `code : Cond -> Nat` from each condition's `code` field. `generated/arm64_cond.h`
  stays byte-identical (only the Lean output gained the table); no new
  `--check` line, so the generator count is unchanged.
- New `KProgFormal/Arm64Cond.lean` (standalone): the independent `Arm64Flags`
  record, `arm64CondSpec`, `generatedArm64Cond`, `arm64_condition_sound`,
  `arm64_cond_code_in_range` (0..14), `arm64_cond_code_dispatch` (all fifteen
  codes pinned), `arm64_cond_codes_distinct`, `arm64_cond_al_always`, and
  `arm64_cond_complements`.
- Clean cutover: `Arm64ControlFlow.lean` now imports `Arm64Cond` and keeps only
  `branchPc` + `arm64_conditional_branch_refines`; `Arm64CcmpHandler.lean`
  imports `Arm64Cond` directly. `Arm64BranchEmit.lean` still imports
  `Arm64ControlFlow` (it needs only `branchPc`).
- `test_arm64_cond_host.c`: independent switch oracle over all fifteen
  conditions × all sixteen NZCV combinations (240 cases OK), plus a sweep of
  every byte value outside 0..14 in forked children confirming the generated
  unsupported arm aborts.
- Mutation test: 10/10 detected — a HI guard drop, GE and LE polarity flips, a
  code static-assert drift, a spec predicate change, a generated arm flip, a
  generated code shift, an independent predicate flip, an independent
  dispatch-value shift, and an independent range-bound change.
- Gate: 85 generators / 161 Lean / 77 oracles / 0 errors. No C-header change,
  so no `micro-proofs-build`.

## Next after 0068

The AArch64 condition contract now has the same standalone independent spec
module and host oracle as the other contracts. `arm64_decode` remains the one
AArch64 contract with neither a standalone module (only enum-level
`Arm64Decode.lean` theorems) nor a host oracle; on x86 the remaining open work
is unchanged from 0056.


## Step 0069 — AArch64 mnemonic-to-code decode host oracle

- Scope: the AArch64 decode contract (`generated/arm64_decode.h` from
  `generate_arm64_decode_spec.py`, Lean `KProgFormal/Arm64Decode.lean`). It was
  the last AArch64 generated contract with a standalone Lean module but no host
  oracle (confirmed by a scout audit: `arm64_decode` and `x86_alu_decode` are
  the only generated headers included by *no* host file).
- New `test_arm64_decode_host.c`: includes `../arm64/arm64_sim.h` so the
  generated `ARM64_{ALU,SHIFT,MOD,BITFIELD}_*` constants are checked against
  the macros the simulator actually uses. Independently restates the four
  mnemonic tables locally (`{mnemonic, code}` arrays, no header values),
  asserts each macro equals its table code and every code within a table is
  distinct, then drives the generated constants through the real shared
  `ARM64_AUX_ALU/_SHIFT/_MOVK/_MEM/_BITFIELD/_CCMP` packing macros and reads
  each packed field back with an independent extractor, sweeping each generated
  code through each AUX field it belongs to plus the 0/255 field boundaries.
  Exits non-zero on mismatch; success line `arm64 decode host cross-check: OK
  (1410 cases)`.
- `Arm64Decode.lean` reworked: the four `arm64*Spec` independent lists were
  previously dead (the refinement theorems hardcoded values and never compared).
  Each `arm64_{alu,shift,mod,bitfield}_decode_refines` now projects the
  generated table to `(mnemonic, code)` pairs and proves it *equal* to the
  independent list, so a drift on either side breaks the proof. Per-table
  `arm64_{alu,shift,mod,bitfield}_codes_distinct` theorems added.
- Makefile: only the CC/run oracle line appended after the existing
  `Arm64Decode.lean` line; no new Lean line (405 already builds it), no new
  generator `--check`, no C-header change.
- Gate: 85 generators / 161 Lean / 78 oracles / 0 errors. Mutation harness
  `/tmp/mut_arm64_decode.py` 12/12 DETECTED (generated code/mnemonic shifts, a
  duplicate bitfield code, three AUX-field packing distortions in
  `arm64_sim.h`, a spec mnemonic rename, and an independent-list change).

## Next after 0069

Every AArch64 generated contract now has both a standalone independent-spec Lean
module and a host oracle. On the x86 side `x86_alu_decode` is the remaining
generated header included by no host file; on x86 the broader open work is
unchanged from 0056.

## Step 0070 — x86 ALU-decode host oracle

- Scope: the x86 ALU decode contract (`generated/x86_alu_decode.h` from
  `generate_x86_alu_decode_spec.py`, Lean `KProgFormal/X86AluDecode.lean`). It
  was the last generated header included by *no* host file (per the 0069 scout
  audit), and unlike the arm64 decode header the x86 header is consumed by a
  real dispatcher (`x86_alu_result` in `x86_sim.h`).
- New `test_x86_alu_decode_host.c`: includes `../x86/x86_sim.h` (after the
  eight integer typedefs and `#define __always_inline inline`) so the generated
  `X86_ALU_*` constants are checked against the macros the simulator actually
  uses. Independently restates the 16-entry `{mnemonic, code}` table locally,
  asserts each macro equals its table code and all codes are distinct, then
  drives every generated code through the **real** `x86_alu_result` over a
  6×8×4 operand/width grid and compares against an independently recomputed
  identity (add/sub/xor/or/and/imul/inc/dec/neg/not/sbb/adc, plus shl/shr/sar/
  rol). Pins the dispatcher contract in the oracle: the arithmetic/logical/
  negate family is computed at full 64-bit width and `width` is consumed only
  by the shift family (narrowing is the caller's register write), so only the
  shift cases mask. Drives both generated handler-selector macros
  (`KPROG_X86_ALU_USES_SBB_HANDLER`/`_ADC_HANDLER`) and checks they agree with
  the dispatcher's own identity checks and are mutually exclusive. Exits
  non-zero on mismatch; success line `x86 alu decode host cross-check: OK
  (3256 cases)`.
- Makefile: only the CC/run oracle line appended after the existing
  `X86AluDecode.lean` line (107 already builds the Lean module); no new Lean
  line, no new generator `--check`, no C-header change.
- Gate: 85 generators / 161 Lean / 79 oracles / 0 errors. Mutation harness
  `/tmp/mut_x86_alu_decode.py` 10/10 DETECTED (two generated-code duplicates
  for SBB/ADC, the SBB handler selector rebound to ADC, four dispatcher
  distortions in `x86_sim.h` — IMUL add-for-mul, SBB add-for-sub, NOT
  identity, SHR→SHL result, NEG self-subtract, a spec code change caught by
  the generator `--check`, and an independent Lean code-spec shift).

## Next after 0070

Every generated contract — AArch64 and x86 — now has both a standalone
independent-spec Lean module and a host oracle. The x86 open work is unchanged
from 0056: index-register decode + packed-AUX layout; simulator-stack-to-
abstract-frame-base mapping; register/immediate/RHS objdump→AUX selection;
compiler/native bytes; multi-step control-flow traces; specialization
preservation.

## Step 0071 — x86 shift-flag host oracle

- Scope: the x86 shift-flag contract (`generated/x86_shift_flags.h` from
  `generate_x86_shift_flags_spec.py`, Lean `KProgFormal/X86ShiftFlags.lean`).
  It was the last generated header with a Lean module but *no* host oracle, and
  unlike the decode tables it is consumed by the simulated shift path: the
  simulator wrapper `X86_SIM_L_SET_SHIFT_FLAGS` (`x86_sim_local_bpf.h:585`)
  calls the generated `KPROG_X86_SET_SHIFT_FLAGS` for `SHL`/`SHR`/`SAR`/`ROL`.
- New `test_x86_shift_flags_host.c`: includes `../x86/x86_sim.h` and
  `generated/x86_shift_flags.h` (after the eight typedefs and `#define
  __always_inline inline`) so the generated macro is checked as the simulator
  uses it. Reproduces the wrapper's input derivation independently (width
  narrowing via `x86_width_mask`, `x86_width_bits` bit count, sign bit,
  `x86_shift_count` masked amount), drives the **real** generated macro, and
  compares each of CF/ZF/SF/OF against an independent restatement of the x86
  shift-flag semantics for shl/shr/sar/rol — including the masked-count-zero
  preservation, the rotate ZF/SF preservation, and the defined-when-count-1 OF
  cases. The shift *result* comes from the real `x86_alu_result`, so the
  oracle drives the same `(value, rhs, result, width)` tuple the sim would.
  Exits non-zero on mismatch; success line `x86 shift flags host cross-check:
  OK (90112 cases)` (22528 tuples × 4 flag fields).
- Makefile: only the CC/run oracle pair appended after the existing
  `X86ShiftFlags.lean` line (136 already builds the Lean module); no new Lean
  line, no new generator `--check`, no C-header change.
- Gate: 85 generators / 161 Lean / 80 oracles / 0 errors. Mutation harness
  `/tmp/mut_x86_shift_flags.py` 10/10 DETECTED (six `x86_shift_flags.h`
  distortions — ROL CF bit, ZF forced true, SAR saturating CF inverted,
  masked-count-zero preservation dropped, ROL OF bit, SHR CF off-by-one — a
  generated `x86_shift_count.h` mask change, a spec policy change caught by the
  generator `--check`, and two independent Lean shift-flag spec changes).

## Next after 0071

Every generated contract — AArch64 and x86 — now has both a standalone
independent-spec Lean module and a host oracle. The remaining x86 open work is
unchanged from 0056 and is now all *compositional/handwritten*, not a missing
generated-header oracle: index-register decode + packed-AUX layout;
simulator-stack-to-abstract-frame-base mapping; register/immediate/RHS
objdump→AUX selection; compiler/native bytes; multi-step control-flow traces;
specialization preservation. The next increment must be one of these deeper
contracts.

## Step 0072 — x86 packed-AUX layout contract

- Scope: the packed x86-64 AUX word — the four-byte layout (index register
  bits 0-7, scale exponent bits 8-15, memory-width / register-source-lane bits
  16-23, ALU-opcode / source-shift / condition byte bits 24-31) that every
  micro-prog instruction carries. It was hand-written as plain unnamed macros
  in `x86/x86_sim.h` with no JSON spec, no generated Lean, and no refinement,
  yet it is a real artifact-level producer: all 43 micro-prog `*.bpf.c`
  `#include "../x86_sim_local_bpf.h"`, and the simulator reads it back through
  `X86_SIM_L_MEM_OFFSET` (index @0, scale @8), the memory-width paths (@16),
  and the source-shift / ALU-opcode paths (@24).
- New `x86_mem_aux_spec.json` + `generate_x86_mem_aux_spec.py`: emit
  `KProgFormal/GeneratedX86MemAux.lean` (C-shaped masked-or `pack`, four byte
  decoders, `indexNone`) and `generated/x86_mem_aux.h` (`KPROG_X86_MEM_AUX`
  packer, `KPROG_X86_MEM_AUX_{INDEX,SCALE_LOG2,MEM_WIDTH,OP}` decoders,
  `KPROG_X86_MEM_AUX_INDEX_NONE`). `x86_sim.h` now `#include`s the generated
  header and aliases its `X86_MEM_AUX*` / `X86_REG_AUX_*` macros to it, so the
  hand-written duplicate is gone and every consumer keeps its name. The
  aliases are live because the micro-progs call the `X86_*` names, which now
  expand to the generated packer.
- New `KProgFormal/X86MemAux.lean`: independent spec is an explicit
  little-endian byte concatenation (`opTag ++ memWidth ++ scaleExp ++ index`),
  not the generated masked-or. Theorems: packer-refines-spec, four field
  roundtrips, sentinel roundtrip, four-fields-pairwise-non-interfering, the
  `indexNone = 0xff` pin, and two concrete byte-order / source-lane examples.
- New `test_x86_mem_aux_host.c`: includes `../x86/x86_sim.h`, drives the
  *real* sim-path `X86_MEM_AUX`/`X86_MEM_AUX_FULL`/`X86_MEM_AUX_ALU_OP`/
  `X86_REG_AUX_*` macros and the decoders, and compares every field against an
  independent `(aux >> 8k) & 0xff` restatement over a byte grid, the sentinel,
  and all 256 values of each single field. Success line `x86 memory aux host
  cross-check: OK (7904 cases)`; exit 1 on mismatch.
- Makefile: generator `--check` after the x86 `--check` block; the
  `X86MemAux.lean` line + oracle CC/run pair after `X86RegLaneAux.lean`. The C
  header + `x86_sim.h` change rebuilt both sims (`make -C native-sim/x86
  micro-proofs-build` and `make -C native-sim/arm64 micro-proofs-build`, both
  rc=0).
- Gate: 86 generators / 162 Lean / 81 oracles / 0 errors. Mutation harness
  `/tmp/mut_x86_mem_aux.py` 9/9 DETECTED (generated packer/decoder shifts and
  masks, a spec code change caught by `--check`, two independent Lean spec
  changes, two live sim-alias flips, and a sentinel-define change).

## Next after 0072

The packed-AUX layout is now bound. Remaining x86 open work is unchanged and
still all *compositional/handwritten*: index-register decode into the AUX index
byte; simulator-stack-to-abstract-frame-base mapping; register/immediate/RHS
objdump→AUX selection; compiler/native bytes; multi-step control-flow traces;
specialization preservation. The next increment must be one of these deeper
contracts. The cheap option (a) left open by 0072 is a host oracle for
`x86_reg_lane_aux` (its Lean module exists but it has no oracle).

## Step 0073 — x86 register-lane AUX contract

- Scope: the packed x86 register-lane AUX word
  (`generated/x86_reg_lane_aux.h` from `generate_x86_reg_lane_aux_spec.py`,
  Lean `KProgFormal/X86RegLaneAux.lean`). It was the last generated packer
  contract with only field-roundtrip theorems and *no* refinement against an
  independent spec and *no* host oracle, yet it is live: the simulator's
  register/immediate ALU bodies (`x86_sim_local_bpf.h:863-915`) read the ALU
  code and the two byte lanes through `KPROG_X86_REG_LANE_AUX_PAYLOAD` /
  `_DST_SHIFT` / `_SRC_SHIFT` on every `X86_SIM_L_EXEC_ALU_{IMM,REG}` step, and
  the width/lane read-write macros read `_DST_SHIFT`/`_SRC_SHIFT` at
  `1398-1467`.
- `X86RegLaneAux.lean`: added `x86RegLaneAuxSpec` (independent little-endian
  byte concatenation: unused top byte, source lane, destination lane, payload)
  and `x86_reg_lane_aux_pack_refines` proving the generated masked-or packer
  equal to it, plus `x86_reg_lane_aux_fields_non_interfering`, a concrete
  byte-order example (`pack 2 8 0 = 0x0802`), and docstrings on the existing
  roundtrips. The module was rewritten off the ambiguous `open` (a binder named
  `payload` shadowed the generated `payload` decoder) to fully qualified
  `GeneratedX86RegLaneAux.*` names.
- New `test_x86_reg_lane_aux_host.c`: includes `../x86/x86_sim.h`, drives the
  *real* generated packer and decoders, and compares every field against an
  independent `(aux >> 8k) & 0xff` restatement over a byte grid, the concrete
  dst-lane-only and both-lane shapes, and all 256 values of each single field,
  including that the unused top byte stays zero. Success line `x86 register lane
  aux host cross-check: OK (7629 cases)`; exit 1 on mismatch.
- Makefile: only the CC/run oracle pair appended after the existing
  `X86RegLaneAux.lean` line (144 already builds the Lean module); no new Lean
  line, no new generator `--check`, no C-header change (so no sim rebuild).
- Gate: 86 generators / 162 Lean / 82 oracles / 0 errors. Mutation harness
  `/tmp/mut_x86_reg_lane_aux.py` 9/9 DETECTED (a generated C packer/decoder/mask
  distortion, a generated Lean shift, a generated Python valid-shift change, a
  spec JSON shift caught by `--check`, and three independent-spec/example
  changes in Lean).

## Next after 0073

Every generated packer contract now has a refinement theorem against an
independent spec, roundtrips, and a host oracle. STEP 0074 took the top
remaining *compositional* item.

## Step 0074 — x86 stack-index frame-offset contract

- Scope: the affine map from an abstract frame offset to a byte index in the
  simulator's fixed `X86_SIM_STACK_BYTES` arena. `X86_SIM_L_STACK_INDEX(OFF)` in
  `x86_sim_local_bpf.h` computed `(__u32)((__s64)(OFF) + X86_SIM_STACK_BYTES)`
  inline with no shared spec, no refinement theorem, and no oracle, yet it is the
  one mapping `X86_SIM_L_STACK_PTR` (`x86_sim_local_bpf.h:494`) — the abstract
  frame base the LEA/MOV stack arms resolve through — and every
  `X86_SIM_L_STACK_READ`/`_WRITE` share. This closes the
  simulator-stack-to-abstract-frame-base mapping gap.
- New shared spec `x86_stack_index_spec.json` +
  `generate_x86_stack_index_spec.py` → `KProgFormal/GeneratedX86StackIndex.lean`
  (`index capacity off = (capacity + off).truncate 32`) and
  `generated/x86_stack_index.h` (`KPROG_X86_STACK_INDEX(OFF, CAPACITY)`).
  `x86/x86_sim.h` now includes the generated header, and
  `X86_SIM_L_STACK_INDEX` is a thin alias `KPROG_X86_STACK_INDEX(OFF,
  X86_SIM_STACK_BYTES)` — one machine-checked map, no inline duplicate.
- `X86StackIndex.lean`: independent low-32-bits spec `BitVec.setWidth 32 (off +
  capacity)`, `x86_stack_index_refines`, plus the laws the mapping must satisfy:
  the frame base (`-capacity`) lands at index 0, the arena top (offset 0) lands
  at the capacity, offsets differing by a multiple of `2^32` alias, and a
  concrete 64-byte-frame example.
- New `test_x86_stack_index_host.c`: drives the *real* generated macro over a
  grid of the frame base, the arena top, offsets below the base, and offsets with
  the high 32 bits set, comparing against an independent unsigned-64-bit
  low-32-bits restatement and checking `2^32` aliasing. Success line `x86 stack
  index host cross-check: OK (690 cases)`; exit 1 on mismatch.
- Because `x86_sim.h` / `x86_sim_local_bpf.h` changed, the sim was rebuilt:
  `make -C native-sim/x86 micro-proofs-build` rc=0 (43 micro-progs; the 30
  runnable arms include the stack `PUSH`/`POP` paths that now go through the
  generated map).
- Gate: 87 generators / 164 Lean / 83 oracles / 0 errors. Mutation harness
  `/tmp/mut_x86_stack_index.py` 10/10 DETECTED (generated C base/width/sign, a
  generated Lean truncation/width/sign, a spec JSON base and mask-bits change
  caught by `--check`, two independent-spec changes, and a Lean example).

## Next after 0074

Remaining x86 open work is unchanged and still *compositional/handwritten*:
index-register decode into the AUX index byte; register/immediate/RHS
objdump→AUX selection; compiler/native bytes; multi-step control-flow traces;
specialization preservation.

## Step 0075 — x86 stack-arena storage-model contract

- Scope: the arithmetic the simulator's stack helpers use to reach the arena
  storage. The arena is a union of two overlapping views
  (`x86_sim_local_bpf.h`): `__u8 b[X86_SIM_STACK_BYTES]` and
  `__u64 q[(X86_SIM_STACK_BYTES + 7U) / 8U]`. `X86_SIM_L_STACK_READ`/`_WRITE`
  index `q[INDEX >> 3]` on the 64-bit path only when `(INDEX & 7U) == 0`, and
  otherwise split/reassemble a 64-bit value byte by byte through `b[]`. Each of
  those steps was inline with no shared spec, no refinement theorem, and no
  oracle. This closes the storage-model gap under the STEP 0074 frame-offset map.
- New shared spec `x86_stack_arena_spec.json` +
  `generate_x86_stack_arena_spec.py` → `KProgFormal/GeneratedX86StackArena.lean`
  (`wordIndex`, `wordAligned`, `byteAt`, `assembleByte`, `words`) and
  `generated/x86_stack_arena.h` (`KPROG_X86_STACK_WORD_INDEX`,
  `_WORD_ALIGNED`, `_BYTE`, `_ASSEMBLE`, `_WORDS`). `x86/x86_sim.h` now
  includes the generated header; the `union … q[]` bound, the read/write word
  fast-path guard, word index, byte extractor/assembler, and word count are thin
  aliases to the generated macros — one machine-checked storage model, no inline
  duplicate.
- `X86StackArena.lean`: independent `BitVec`-native specs
  (`x86StackArenaWordIndexSpec`, `_WordsSpec`, `_WordAlignedSpec`,
  `_SplitSpec`, `_ReadSpec`) with refinement theorems, the cover/tightness
  lemmas for the rounded-up word count, the 8-aligned roundtrip, the
  word≅byte reassembly identity, the read/split equivalence, the slot-in-range
  bound, and concrete capacity/word examples.
- New `test_x86_stack_arena_host.c`: drives the *real* generated macros over a
  capacity/index/value grid plus an exhaustive two-page sweep, comparing each
  against independent shift/mask restatements and checking a value stored
  through the word view reloads byte-for-byte through the byte view. Success line
  `x86 stack arena host cross-check: OK (70571 cases)`; exit 1 on mismatch.
- Because `x86_sim.h` / `x86_sim_local_bpf.h` changed, the sim was rebuilt:
  `make -C native-sim/x86 micro-proofs-build` rc=0 (43 micro-progs).
- Gate: 88 generators / 166 Lean / 84 oracles / 0 errors. Mutation harness
  `/tmp/mut_x86_stack_arena.py` 12/12 DETECTED (five generated-C corruptions, three
  generated-Lean corruptions, two spec-JSON changes caught by `--check`, and two
  independent-spec/example changes in Lean).

## Next after 0075

Remaining x86 open work is unchanged and still *compositional/handwritten*:
index-register decode into the AUX index byte; register/immediate/RHS
objdump→AUX selection; compiler/native bytes; multi-step control-flow traces;

## Step 0076 — x86 simulator routes effective-address offsets through the checked contract

- Scope: the x86 simulator's `X86_SIM_L_MEM_OFFSET(AUX, DISP)` helper. The
  effective-address offset was already machine-checked (`KPROG_X86_MEM_OFFSET`
  + `X86MemOffset.lean`), but the simulator **restated the arithmetic inline**:
  it decoded the AUX index, read the register, and did the shift-and-add itself,
  so the theorem bounded a macro the running simulator did not use. This closes
  the "curated contract vs. shipped helper" gap for the offset (the arm64
  simulator already routed through `KPROG_ARM64_MEM_OFFSET`).
- `x86/x86_sim.h` now includes `../formal/generated/x86_mem_offset.h`.
  `X86_SIM_L_MEM_OFFSET(AUX, DISP)` resolves the index through
  `X86_SIM_L_READ_REG` and delegates to KPROG_X86_MEM_OFFSET via a new
  `X86_SIM_L_MEM_OFFSET_INDEXED(AUX, DISP, INDEX_VALUE, HAS_INDEX)` — the
  public helper is the only restatement-free caller; LEA/MOV/CMP/STORE/test and
  the base-offset macros are unchanged and now inherit it.
- New `test_x86_mem_offset_route_host.c`: includes the *simulator* header
  (`x86_sim_local_bpf.h`), drives the real `X86_SIM_L_MEM_OFFSET` over
  register-AUX forms (RAX/RSP/RBP/RDI/R15/NONE × four scales × eight register
  values × six displacements), compares against an independent signed
  accumulator built from the same source register value, checks the no-index
  form ignores a poisoned register file, and checks the routed helper agrees
  with the explicit-value helper. Success line `x86 mem offset route host
  cross-check: OK (2305 cases)`; exit 1 on mismatch.
- Because `x86_sim.h` / `x86_sim_local_bpf.h` changed, the sim was rebuilt:
  `make -C native-sim/x86 micro-proofs-build` rc=0 (43 micro-progs).
- Gate: 88 generators / 166 Lean / 85 oracles / 0 errors.
- Mutation harness `mut_x86_mem_offset_route.py`: 9/9 DETECTED — four sim-side
  routing mutations (index-register swap to RAX, disp/index operand swap,
  forced no-index, off-by-one on the selected AUX index) caught by the route
  oracle alone; two spec-JSON mutations (invalid `indexed` tag, widened
  accumulation) caught by the generator `--check`; the Lean independent-spec
  shift mutation caught by the refinement module; and two generated-C
  mutations (shift→multiply, scale off-by-one) caught by both the generator
  `--check` and the route oracle.

## Step 0077 — x86 simulator routes the memory read dispatch through the checked contract

- Scope: the x86 simulator's memory read path. The read-source classification
  (stack read vs. ABI pointer load vs. ordinary load) was already
  machine-checked (`KPROG_X86_MEM_READ_SRC` + `X86MemDispatch.lean`) and the
  **arm64** simulator already routed through its peer
  (`KPROG_ARM64_MEM_SRC_*`), but the x86 simulator restated the predicate
  ladder inline in two helpers, so the theorem bounded a contract the running
  simulator did not call. This closes the same "curated contract vs. shipped
  helper" gap that 0076 closed for the offset.
- `x86/x86_sim.h` now includes `../formal/generated/x86_mem_dispatch.h`. New
  `X86_SIM_L_MEM_READ_SRC(BASE_REG, MEM_WIDTH)` resolves the base tag through
  `X86_SIM_L_REG_TAG` and delegates to the generated `KPROG_X86_MEM_READ_SRC`
  with `((BASE_REG) == X86_RSP)`. Both routed helpers now `switch` on it:
  `X86_SIM_L_READ_MEM_VALUE` (stack read / pointer load / ordinary load) and
  `X86_SIM_L_EXEC_MOV_LOAD` (its ABI arm keeps the opcode-plus-width-64
  refinement that falls back to an ordinary load and write, exactly as the
  contract comment states; the MOVSX sign-extend stays in the ordinary arm).
  The now-dead `__x86_l_base_tag` local in the MOV_LOAD macro was removed.
- New `test_x86_mem_dispatch_route_host.c`: includes the *simulator* header and
  drives the real `X86_SIM_L_READ_MEM_VALUE` over stack/ABI/ordinary bases
  (four widths × the scale/offset grid) against an independent byte reader and
  the contract's classification; drives the real `X86_SIM_L_EXEC_MOV_LOAD`
  over ordinary, MOVSX, ABI-at-width-64, ABI-off-width-64, and stack bases,
  checking both the written value and the destination register tag; plus an
  ABI-width-gate probe and a no-index-ignores-registers check. Success line
  `x86 mem dispatch route host cross-check: OK (62 cases)`; exit 1 on
  mismatch. This is distinct from the pre-existing
  `test_x86_mem_read_dispatch_host.c`, which tests the contract plus an
  independent model but never includes the sim header.
- Because `x86_sim.h` / `x86_sim_local_bpf.h` changed, the sim was rebuilt:
  `make -C native-sim/x86 micro-proofs-build` rc=0 (43 micro-progs).
- Gate: 88 generators / 166 Lean / 86 oracles / 0 errors.
- Mutation harness `mut_x86_mem_dispatch_route.py`: 12/12 DETECTED — six
  simulator-header routing distortions caught by the route oracle alone (the
  `== X86_RSP` identity swapped for a non-stack register, the register-tag
  argument dropped to a scalar tag, the RSP identity forced true, the read
  helper's stack arm replaced by an ordinary load, the MOV_LOAD opcode/width-64
  refinement inverted, and the MOV_LOAD stack displacement shifted by one);
  two generated-C defects caught by the generator `--check`, the pre-existing
  dispatch oracle, and the route oracle (the width-64 gate inverted, the ABI
  source define colliding with the ordinary one); two shared-spec mutations
  caught by the generator `--check` (an ABI row's source define flipped to the
  ordinary load, and an RSP row's source tag changed to the ABI pointer load);
  and two Lean independent-spec mutations caught by the refinement module (the
  ABI/width predicate conjoined instead of gated, and the RSP-first branch
  disabled).

## Step 0078 — x86 simulator routes the shared MOV_STORE body through the checked contract

- Scope: the x86 simulator's one live store helper, `X86_SIM_L_EXEC_STORE`
  (shared by `X86_OP_MOV_STORE_IMM` / `X86_OP_MOV_STORE_REG`, one call site).
  Its contract (`KPROG_X86_STORE_*` + `X86StoreHandler.lean`, spec
  `x86_store_spec.json`, oracle `test_x86_store_host.c`) was already generated
  and proven, but the helper restated all five clauses inline — the width
  fallback, the two displacement slices, the two value sources, the AUX
  source-shift gate, and the stack-pointer arm selection. This closes the same
  "curated contract vs. shipped helper" gap 0076 (offset) and 0077 (read
  dispatch) closed.
- `x86/x86_sim.h` now includes `../formal/generated/x86_store.h`. New
  `X86_SIM_L_MEM_STORE_SRC(DST)` = `KPROG_X86_STORE_ARM((DST) == X86_RSP)`
  (a plain two-way arm, unlike the read path's three-way source; the store has
  no ABI arm and no sign extension). `X86_SIM_L_EXEC_STORE` now resolves every
  clause through the generated macros — `KPROG_X86_STORE_WIDTH(FLAGS)`,
  `KPROG_X86_STORE_DISP((OP) == X86_OP_MOV_STORE_IMM, IMM)`,
  `KPROG_X86_STORE_VALUE(...)` fed by `X86_SIM_L_READ_REG(SRC)`,
  `KPROG_X86_STORE_SHIFTED_VALUE(value, KPROG_X86_STORE_SRC_SHIFT(...))`, and
  an `X86_SIM_L_MEM_STORE_SRC`-driven `switch` whose `STACK` arm calls
  `X86_SIM_L_STACK_WRITE` and whose `default` arm calls `X86_SIM_L_STORE_ADDR`.
  The old inline `if (OP == MOV_STORE_REG && shift != 0) value >>= shift` and
  the `if ((DST) == X86_RSP) ... else ...` ladder are gone.
- The two arms keep their distinct width *expressions* deliberately: the memory
  arm writes at `KPROG_X86_STORE_WIDTH(FLAGS)` while the stack arm passes
  `X86_SIM_L_EFFECTIVE_WIDTH(FLAGS)`; both are `FLAGS ? FLAGS : 64`, and the
  contract comment itself calls the stack arm a re-derivation of the same
  resolution — they are semantically identical and were not "unified" without
  evidence.
- New `test_x86_store_route_host.c`: includes the *simulator* header and drives
  the real `X86_SIM_L_EXEC_STORE` over the immediate and register forms, all
  four widths (plus an absent-FLAGS case), flat and indexed addressing modes,
  the register-form AUX source shift, and both the stack and memory arms, then
  compares the *entire* modeled heap and modeled stack against an independent
  byte model (`put_le` + a restated width-aware immediate rule + the
  `immHighHalf`/`signedImm` displacement split) built from the raw inputs; it
  also checks the routed `X86_SIM_L_MEM_STORE_SRC` against
  `KPROG_X86_STORE_ARM` for a register sweep and the width default over the
  FLAGS codes. Success line `x86 store route host cross-check: OK (77 cases)`;
  exit 1 on mismatch. Distinct from the pre-existing `test_x86_store_host.c`,
  which tests the contract plus an independent model but never includes the sim
  header.
- Because `x86_sim.h` / `x86_sim_local_bpf.h` changed, the sim was rebuilt:
  `make -C native-sim/x86 micro-proofs-build` rc=0 (43 micro-progs).
- Gate: 88 generators / 166 Lean / 87 oracles / 0 errors.
- Mutation harness `mut_x86_store_route.py`: 12/12 DETECTED — six
  simulator-header distortions caught by the route oracle alone (the `== X86_RSP`
  arm identity swapped for RDI, the disp-form opcode argument flipped, the
  value-source opcode argument flipped, the AUX shift gate inverted, the stack
  arm's effective width shifted by one, and the memory arm's width forced to
  64); three generated-C defects caught by the generator `--check` and the
  route oracle (the displacement slice moved from `>> 32` to `>> 16`, the two
  arm defines colliding, the width default changed to 32 bits); one shared-spec
  mutation caught by the generator `--check` (a `disp_row`'s `is_store_imm`
  flipped); and two Lean independent-spec mutations caught by the refinement
  module (the arm predicate forced true, and the displacement slice shifted to
  16 bits).

## Step 0079 — x86 simulator routes the MOVBE pair through the checked contract

- Scope: the x86 simulator's `X86_SIM_L_EXEC_MOVBE_LOAD` and
  `X86_SIM_L_EXEC_MOVBE_STORE` bodies. Their contract (`KPROG_X86_MOVBE_*` +
  `X86MovbeHandler.lean`, spec `x86_movbe_spec.json`, oracle
  `test_x86_movbe_host.c`) was already generated and proven, but both bodies
  restated clauses inline — the width fallback in both, and the stack-pointer
  arm selection in the store — the same "curated contract vs. shipped helper"
  gap 0076 (offset), 0077 (read dispatch), and 0078 (shared `MOV_STORE`) closed.
- `x86/x86_sim.h` now includes `../formal/generated/x86_movbe.h`. New
  `X86_SIM_L_MEM_MOVBE_SRC(DST)` = `KPROG_X86_MOVBE_ARM((DST) == X86_RSP)`,
  the same plain two-way arm as the store path (no ABI arm, no sign extension).
  `X86_SIM_L_EXEC_MOVBE_LOAD` now resolves its width through
  `KPROG_X86_MOVBE_WIDTH(FLAGS)` and hands it to the shared read body.
  `X86_SIM_L_EXEC_MOVBE_STORE` resolves the width through
  `KPROG_X86_MOVBE_WIDTH(FLAGS)`, the displacement through
  `KPROG_X86_MOVBE_DISP(IMM)` (via `X86_SIM_L_MEM_OFFSET`), and selects the arm
  through an `X86_SIM_L_MEM_MOVBE_SRC`-driven `switch` whose `STACK` arm calls
  `X86_SIM_L_STACK_WRITE` and whose `default` arm calls `X86_SIM_L_STORE_ADDR`.
  The old inline `(FLAGS) ? (FLAGS) : X86_WIDTH_64` and the
  `if ((DST) == X86_RSP) ... else ...` ladder are gone.
- One resolved width drives the byte reversal, the memory access, and the
  written size in both forms; the contract calls the stack arm's width a
  re-derivation of the same `FLAGS ? FLAGS : 64` (`x86_movbe_resolve_width_refines`
  / `x86_movbe_resolved_not_absent`), so the two arms deliberately share one
  width expression rather than being "unified" further.
- New `test_x86_movbe_route_host.c`: includes the *simulator* header and drives
  the real `X86_SIM_L_EXEC_MOVBE_STORE` over all four widths, flat and indexed
  addressing modes, and both the stack and memory arms, comparing the *entire*
  modeled heap and modeled stack against an independent byte model
  (`put_le` + `bswap_model`); the load half plants source bytes at the
  effective address (displacement plus scaled index) and compares the written
  destination register value — including the 32-bit zero-extension and the
  narrower-width lane merge — and tag against the byte-reversed model; it also
  checks the routed `X86_SIM_L_MEM_MOVBE_SRC` against `KPROG_X86_MOVBE_ARM` for
  a register sweep and the width default over the FLAGS codes. Success line
  `x86 movbe route host cross-check: OK (71 cases)`; exit 1 on mismatch.
  Distinct from the pre-existing `test_x86_movbe_host.c`, which tests the
  contract plus an independent model but never includes the sim header.
- Because `x86_sim.h` / `x86_sim_local_bpf.h` changed, the sim was rebuilt:
  `make -C native-sim/x86 micro-proofs-build` rc=0 (43 micro-progs).
- Gate: 88 generators / 166 Lean / 88 oracles / 0 errors.
- Mutation harness `mut_x86_movbe_route.py`: 10/10 DETECTED — four
  simulator-header distortions caught by the route oracle alone (both bodies'
  width forced to 32, the store arm identity swapped from RSP to RDI, the
  store displacement moved to the high-half slice); three generated-C defects
  caught by the generator `--check` and the route oracle (the width default
  changed to 32 bits, the displacement slice moved to `>> 32`, the two arm
  defines colliding); one shared-spec mutation caught by the generator
  `--check` (a `disp_row`'s `form` switched to `immHighHalf`); and two Lean
  independent-spec mutations caught by the refinement module (the width
  fallback forced to 32 bits, the displacement restated as the high-half
  slice).

## Step 0080 — x86 simulator routes the XMM0 pair through the checked contract

- Scope: the x86 simulator's `X86_SIM_L_EXEC_LOAD_XMM0` and
  `X86_SIM_L_EXEC_STORE_XMM0` bodies. Their contract (`KPROG_X86_XMM0_*` +
  `X86Xmm0Handler.lean`, spec `x86_xmm0_spec.json`, oracle
  `test_x86_xmm0_host.c`) was already generated and proven, but both bodies
  restated clauses inline — the stack-pointer arm selection, the two lane
  offsets, and (for the load) the `X86_REG_NONE` absolute base form with its
  discarded offset — the same "curated contract vs. shipped helper" gap 0076
  (offset), 0077 (read dispatch), 0078 (shared `MOV_STORE`), and 0079 (MOVBE)
  closed.
- `x86/x86_sim.h` now includes `../formal/generated/x86_xmm0.h`. New
  `X86_SIM_L_MEM_XMM0_ARM(BASE_REG)` = `KPROG_X86_XMM0_ARM((BASE_REG) ==
  X86_RSP)`, the one fact either body's branch chain consults. Both bodies now
  select the arm through an `X86_SIM_L_MEM_XMM0_ARM`-driven `switch` over
  `KPROG_X86_XMM0_ARM_STACK` / default, place the high lane at
  `KPROG_X86_XMM0_LANE_OFFSET(1)`, and — in the ordinary arm — resolve the base
  form through `KPROG_X86_XMM0_BASE_FORM` (load: `1U` = `absImmPtr`; store:
  `0U` = `nullBasePlusDisp`), the base pointer through
  `KPROG_X86_XMM0_BASE_PTR`, and the offset-adding test through
  `KPROG_X86_XMM0_ADDS_DISP`. The old inline `if ((SRC/DST) == X86_RSP) ...
  else ...` ladder and the literal `+ 8` lane step are gone.
- The two bodies keep the literal `X86_WIDTH_64` lane width: the generated
  header deliberately has no lane-width macro (`_Static_assert(
  KPROG_X86_XMM0_LANE_BYTES == X86_WIDTH_64)`), since the pair move is always
  64-bit and neither body resolves a width. The header's own doc comment was
  stale ("the sim bodies do not call it") and was corrected in
  `generate_x86_xmm0_spec.py`; `GeneratedX86Xmm0.lean` is byte-for-byte
  unchanged, so the generator `--check` gate rejects only a stale header.
- New `test_x86_xmm0_route_host.c`: includes the *simulator* header and drives
  the real bodies. The load half plants two known lanes at the effective
  address and compares the written XMM0 pair against an independent byte model
  (`put_lane` / `get_lane`); the store half drives the real body and compares
  the *entire* modeled heap and modeled stack against the byte model. Both
  halves cover the stack arm, an ordinary register base, the `X86_REG_NONE`
  base form of each opcode (load: raw absolute immediate with the addressing
  offset *discarded*; store: null base with the offset *added*), and indexed
  addressing. It also checks the routed `X86_SIM_L_MEM_XMM0_ARM` against
  `KPROG_X86_XMM0_ARM` over a register sweep, the lane offsets, and the two
  routed base forms. Success line `x86 xmm0 route host cross-check: OK (59
  cases)`; exit 1 on mismatch. Distinct from the pre-existing
  `test_x86_xmm0_host.c`, which tests the contract plus an independent model
  but never includes the sim header.
- Because `x86_sim.h` / `x86_sim_local_bpf.h` changed, the sim was rebuilt:
  `make -C native-sim/x86 micro-proofs-build` rc=0 (43 micro-progs).
- Gate: 88 generators / 166 Lean / 89 oracles / 0 errors.
- Mutation harness `mut_x86_xmm0_route.py`: 10/10 DETECTED — the
  simulator-header distortions caught by the route oracle alone (the shared arm
  identity swapped from RSP to RDI, the load's high-lane offset moved to lane
  0, the load's base form swapped, the offset-adding test forced on); the
  generated-C defects caught by the generator `--check` and the route oracle
  (the arm define colliding, the high-lane offset moved to 0, the
  absolute-immediate base form renamed); one shared-spec mutation caught by the
  generator `--check` (the high lane's `byte_offset` moved to 0); and the Lean
  independent-spec mutations caught by the refinement module (the arm spec
  swapped, the lane offset moved to 0).

## Step 0081 — x86 simulator routes the CALL_MEMCPY/CALL_MEMSET quartet through the checked contract

- Scope: the x86 simulator's four block-copy/block-fill bodies
  `X86_SIM_L_EXEC_CALL_MEMCPY` (`0x3f`), `X86_SIM_L_EXEC_CALL_MEMCPY_REG`
  (`0x46`), `X86_SIM_L_EXEC_CALL_MEMSET` (`0x3c`), and
  `X86_SIM_L_EXEC_CALL_MEMSET_REG` (`0x45`) previously restated the array loop
  four times and called no generated macro. They now share one
  `X86_SIM_L_EXEC_CALL_MEM_STEP(IMM, OP_IS_COPY, OP_IS_REG)` composition that
  selects the array shape through `KPROG_X86_CALLMEM_KIND`, the copied/filled
  length's source through `KPROG_X86_CALLMEM_COUNT_SOURCE`, and the array bound
  through `KPROG_X86_CALLMEM_BOUND_FORM` / `KPROG_X86_CALLMEM_FIXED_BOUND`; each
  opcode macro is now a one-line instantiation of the shared step. The element
  width (`X86_WIDTH_8`), the byte addressing, and the RAX/RDI-tag write stay in
  the composed body by contract design (the header selects three facts, no
  width macro and no body macro).
- `native-sim/x86/x86_sim.h`: added
  `#include "../formal/generated/x86_callmem.h"` after the XMM0 include.
- `native-sim/x86/x86_sim_local_bpf.h`: the four bodies replaced by the shared
  routed step macro (block comment above it) plus four one-line opcode macros.
- New `test_x86_callmem_route_host.c`: includes the *simulator* header and
  drives the four real bodies. Per opcode it plants a case where each routed
  fact is numerically distinguishable from the wrong selection — an
  artifact-exceeds-`1024` immediate case (a bound-form swap to the artifact
  would run past the literal) and an `RDX`-exceeds-artifact register case
  (both a bound-form swap to the literal and a count-source swap to the
  artifact would move a different region) — plus flat, small, and zero counts,
  the source-register low-byte truncation on the fill path, and the
  destination-pointer-with-RDI-tag result write. Compares the whole modeled
  heap and the result-register write against an independent byte model. Success
  line `x86 callmem route host cross-check: OK (52 cases)`; exit 1 on mismatch.
  Distinct from the pre-existing `test_x86_callmem_host.c`, which tests the
  contract plus an independent model but never includes the sim header.
- Because `x86_sim.h` / `x86_sim_local_bpf.h` changed, the sim was rebuilt:
  `make -C native-sim/x86 micro-proofs-build` rc=0 (43 micro-progs).
- `native-sim/formal/Makefile`: added the `test_x86_callmem_route_host` build +
  run pair after the `test_x86_callmem_host` pair.
- `native-sim/formal/README.md`: routing paragraph added after the CALL_MEM
  theorem paragraph; the stale TCB paragraph ("The four
  `X86_SIM_L_EXEC_CALL_{MEMCPY,MEMSET}{,_REG}` handler bodies do not call the
  generated `x86_callmem.h` macros…") deleted; the binding-list clause updated
  to record the simulator's routing of all four call-memory bodies through the
  `KPROG_X86_CALLMEM_*` contract.
- Mutation harness `mut_x86_callmem_route.py`: 11/11 DETECTED — the
  simulator-header distortions caught by the route oracle alone (the shared
  kind test inverted, the count-source test inverted, the bound-form test
  inverted, the `MEMSET` macro retagged as a register opcode); the generated-C
  defects caught by the generator `--check` and the route oracle (the copy
  define colliding, the register-count define colliding, the fixed-bound define
  colliding, the literal `1024` moved to `0`); one shared-spec mutation caught
  by the generator `--check` (`fixed_bound` moved to `0`); and the Lean
  independent-spec mutations caught by the refinement module (`MEMSET`'s kind
  moved from `fill` to `copy`, `MEMCPY_REG`'s bound form moved from `imm` to
  `fixedBound`).

## Step 0082 — x86 simulator routes the PUSH/POP pair through the checked contract

- Scope: the x86 simulator's two stack-transfer bodies
  `X86_SIM_L_EXEC_PUSH` (`0x12`) and `X86_SIM_L_EXEC_POP` (`0x13`) previously
  restated the stack-pointer step twice and called no generated macro. They now
  share one `X86_SIM_L_EXEC_PUSH_POP_STEP(IS_POP, DST, SRC, FLAGS)` composition
  that selects the step direction through `KPROG_X86_PUSH_STEP_DIRECTION`, which
  body honours the opcode's FLAGS code through `KPROG_X86_PUSH_WIDTH_SOURCE`,
  the absent-FLAGS default through `KPROG_X86_PUSH_FLAGS_WIDTH`, and the byte
  amount through `KPROG_X86_PUSH_STACK_STEP`; `X86_SIM_L_EXEC_PUSH` and
  `X86_SIM_L_EXEC_POP` are now one-line instantiations of the shared step. The
  stack-pointer arithmetic, the stack helper's byte framing, the destination
  writeback, and the flags-free property stay in the composed body by contract
  design (the header selects four facts, no body macro).
- `native-sim/formal/generate_x86_pushpop_spec.py`: module docstring and the
  emitted-header prose updated to name the two handlers and the shared routed
  composition; regenerated without `--check` then verified with `--check`
  (`REGEN-OK`; only `generated/x86_pushpop.h` changed — the Lean output is
  byte-identical).
- `native-sim/x86/x86_sim.h`: added
  `#include "../formal/generated/x86_pushpop.h"` after the CALL_MEM include.
- `native-sim/x86/x86_sim_local_bpf.h`: the two bodies replaced by the shared
  routed step macro (block comment above it) plus two one-line opcode macros;
  the `X86_SIM_L_EXEC` `X86_OP_PUSH` / `X86_OP_POP` arms now call the wrappers.
- New `test_x86_pushpop_route_host.c`: includes the *simulator* header and
  drives both real bodies directly and through the `X86_SIM_L_EXEC` dispatcher
  arms, over both directions, every FLAGS code (`0`, 8, 16, 32, 64) and a range
  of stack pointers, planting per opcode a case where each routed fact is
  numerically distinguishable from the wrong selection (a narrow-FLAGS `PUSH`
  that must still step by eight and store eight bytes, an absent-FLAGS `POP`
  that must still read and write eight bytes, and a direction swap). Compares
  the whole register file, the whole stack frame, the stack pointer, and the
  flags against an independent model. Success line
  `x86 pushpop route host cross-check: OK (31504 cases)`; exit 1 on mismatch.
  Distinct from the pre-existing `test_x86_pushpop_host.c`, which tests the
  contract plus an independent model but never includes the sim header.
- Because `x86_sim.h` / `x86_sim_local_bpf.h` changed, the sim was rebuilt:
  `make -C native-sim/x86 micro-proofs-build` rc=0 (43 micro-progs).
- `native-sim/formal/Makefile`: added the `test_x86_pushpop_route_host` build +
  run pair after the `test_x86_pushpop_host` pair.
- `native-sim/formal/README.md`: routing paragraph added after the PUSH/POP
  theorem paragraph; the stale TCB paragraph ("The two
  `X86_SIM_L_EXEC_{PUSH,POP}` handler bodies do not call the generated
  `x86_pushpop.h` macros…") deleted; the binding-list clause updated to record
  the simulator's routing of both bodies through the `KPROG_X86_PUSH_*`
  contract.
- Mutation harness `mut_x86_pushpop_route.py`: 17/17 DETECTED — the
  simulator-header distortions caught by the route oracle alone (the direction
  test inverted, the width-source test inverted, the absent-FLAGS test
  inverted, the stack-step literal hardcoded to `16`, `PUSH` tagged as the POP
  body, `POP` tagged as the PUSH body, the dispatcher `POP` arm routed to the
  PUSH body); the generated-C defects caught by the generator `--check` and the
  route oracle (the pre-decrement define colliding, the post-increment define
  colliding, the hardcoded-width define colliding, the absent-FLAGS define
  colliding, the absent-width define colliding, the stack-step literal moved to
  `16`); one shared-spec mutation caught by the generator `--check`
  (`stack_step` moved to `16`); and the Lean independent-spec mutations caught
  by the refinement module (`PUSH`'s direction moved to `postIncrement`,
  `POP`'s width source moved to `hardcoded64`, the step amount moved to `16`).

## Step 0083 — x86 simulator routes the ANDN/ANDN_MEM pair through the checked contract

- Scope: the x86 simulator's two complement-and bodies
  `X86_SIM_L_EXEC_ANDN` (`0x3d`) and `X86_SIM_L_EXEC_ANDN_MEM` (`0x44`)
  previously restated the source split and the two width selections twice and
  called no generated macro. They now share one
  `X86_SIM_L_EXEC_ANDN_STEP(OP_IS_MEM, DST, SRC, AUX, FLAGS, IMM)` composition
  that selects the second-operand source through `KPROG_X86_ANDN_SOURCE`, the
  destination write width through `KPROG_X86_ANDN_WRITE_WIDTH`, and the
  independently selected memory-read width through `KPROG_X86_ANDN_MEM_WIDTH`;
  `X86_SIM_L_EXEC_ANDN` and `X86_SIM_L_EXEC_ANDN_MEM` are now one-line
  instantiations of the shared step. The complement/and, the flag production,
  and the writeback stay in the composed body by contract design (the header
  selects three facts, no body macro).
- `native-sim/formal/generate_x86_andn_spec.py`: module docstring and the
  emitted-header prose updated to name the two handlers and the shared routed
  composition; regenerated without `--check` then verified with `--check`
  (only `generated/x86_andn.h` changed — the Lean output is byte-identical).
- `native-sim/x86/x86_sim.h`: added
  `#include "../formal/generated/x86_andn.h"` after the PUSH/POP include.
- `native-sim/x86/x86_sim_local_bpf.h`: the two bodies replaced by the shared
  routed step macro (block comment above it) plus two one-line opcode macros;
  the `X86_SIM_L_EXEC` arms already called the wrapper names, so the dispatcher
  is unchanged. **The memory-form local width variable is named
  `__x86_l_andn_mem_width`, not `__x86_l_mem_width`:** `X86_SIM_L_READ_MEM_VALUE`
  declares its own `__x86_l_mem_width` as its first statement, so passing the
  outer width under that name made the inner declaration shadow it and
  initialise from an uninitialised variable (`-Wuninitialized`), reading the
  memory at a garbage width. The rename removes the shadow.
- New `test_x86_andn_route_host.c`: includes the *simulator* header and drives
  both real bodies directly and through the `X86_SIM_L_EXEC` dispatcher arms,
  over both opcodes, every FLAGS code (`0`, 8, 16, 32, 64), every AUX
  memory-width code, four displacements, and several source/destination
  registers, planting per opcode a case where each routed fact is numerically
  distinguishable from the wrong selection (a memory form carrying a named AUX
  width that differs from the FLAGS write width, an absent AUX width that must
  fall back to the resolved FLAGS width, and a register-versus-memory source
  pair). Compares the whole register file with its tags and all four flags
  against an independent model. Success line
  `x86 andn route host cross-check: OK (356404 cases)`; exit 1 on mismatch.
  Distinct from the pre-existing `test_x86_andn_host.c`, which tests the
  contract plus an independent model but never includes the sim header.
- Because `x86_sim.h` / `x86_sim_local_bpf.h` changed, the sim was rebuilt:
  `make -C native-sim/x86 micro-proofs-build` rc=0 (every micro-prog `ok`).
- `native-sim/formal/Makefile`: added the `test_x86_andn_route_host` build +
  run pair after the `test_x86_andn_host` pair.
- `native-sim/formal/README.md`: routing paragraph added after the ANDN
  theorem paragraph; the stale TCB paragraph ("The `X86_SIM_L_EXEC_ANDN` and
  `X86_SIM_L_EXEC_ANDN_MEM` handler bodies do not call the generated
  `x86_andn.h` macros…") deleted; the binding-list clause updated to record
  the simulator's routing of both bodies through the `KPROG_X86_ANDN_*`
  contract.
- `docs/kprog-simulator-in-ebpf/sections/4-safety.tex`: routing sentence pair
  inserted after the ANDN oracle paragraph; structural balance re-verified
  (0 tabs; the introduced `(`/`)` and `{`/`}` deltas are equal; `$` count
  unchanged).
- Mutation harness `mut_x86_andn_route.py`: 19/19 DETECTED — the
  simulator-header distortions caught by the route oracle alone (the source
  test inverted, the memory width hardcoded to `8`, the write width hardcoded
  to `8`, `ANDN` tagged as the memory body, `ANDN_MEM` tagged as the register
  body, the dispatcher ANDN_MEM arm routed to the register body, the dispatcher
  ANDN arm routed to the memory body); the generated-C defects caught by the
  generator `--check` and the route oracle (the source-register define
  colliding, the source-memory define colliding, the AUX memory-width arm
  colliding, the FLAGS memory-width arm colliding, the write-width default
  colliding, the 64-bit width code moved to `4`, both opcode static-assert
  codes drifted); one shared-spec mutation caught by the generator `--check`
  (`write_width_default` moved to `b8`); and the Lean independent-spec
  mutations caught by the refinement module (`ANDN`'s source moved to
  `memoryRead`, the 64-bit code mapping moved to `w32`, the memory-width arm
  body swapped).
- Full gate `make -C native-sim/formal check` rc=0.

## Step 0084 — x86 simulator routes the BZHI/BZHI_MEM pair through the checked contract

- Scope: the x86 simulator's two single-width bit-clear bodies
  `X86_SIM_L_EXEC_BZHI` (`0x34`) and `X86_SIM_L_EXEC_BZHI_MEM` (`0x35`)
  previously restated the value/count split and the one width twice and called
  no generated macro. They now share one
  `X86_SIM_L_EXEC_BZHI_STEP(OP_IS_MEM, DST, SRC, COUNT, AUX, FLAGS, IMM)`
  composition that selects the value source through
  `KPROG_X86_BZHI_VALUE_SOURCE`, the count source through
  `KPROG_X86_BZHI_COUNT_SOURCE`, the count byte mask through
  `KPROG_X86_BZHI_COUNT_MASK`, and the one width both the memory read and the
  destination write use through `KPROG_X86_BZHI_WRITE_WIDTH` (unlike
  `ANDN_MEM`, `BZHI_MEM` has no independent read width);
  `X86_SIM_L_EXEC_BZHI` and `X86_SIM_L_EXEC_BZHI_MEM` are now one-line
  instantiations of the shared step, preserving their old signatures/order so
  the `X86_SIM_L_EXEC` arms are unchanged. The reads, the masked bit-clear, the
  flag production, and the writeback stay in the composed body by contract
  design (the header selects facts, no body macro).
- `native-sim/formal/generate_x86_bzhi_spec.py`: module docstring and the
  emitted-header prose updated to name the two handlers and the shared routed
  composition; regenerated without `--check` then verified with `--check`
  (only `generated/x86_bzhi.h` changed — the Lean output is byte-identical,
  `-Wcomment` count 0).
- `native-sim/x86/x86_sim.h`: added
  `#include "../formal/generated/x86_bzhi.h"` after the ANDN include.
- `native-sim/x86/x86_sim_local_bpf.h`: the two bodies replaced by the shared
  routed step macro (block comment above it) plus two one-line opcode macros;
  the `X86_SIM_L_EXEC` arms already called the wrapper names, so the dispatcher
  is unchanged.
- New `test_x86_bzhi_route_host.c`: includes the *simulator* header and drives
  both real bodies directly and through the `X86_SIM_L_EXEC` dispatcher arms,
  over both opcodes, every FLAGS code, every AUX width code, four
  displacements, and several value/count/destination registers, planting per
  opcode a count whose low byte differs per register and whose high bit is set
  (its upper bytes carry `0x5a`), so a body that reads its value or count from
  the wrong place lands on a different byte-masked count, a body that skips the
  mask clears different bits, and a mask wider than `0xff` is caught by the
  count-versus-width CF. Compares the whole register file with its tags and all
  four flags against an independent model. Success line
  `x86 bzhi route host cross-check: OK (356405 cases)`; exit 1 on mismatch.
  Distinct from the pre-existing `test_x86_bzhi_host.c`, which tests the
  contract plus an independent model but never includes the sim header.
- Because `x86_sim.h` / `x86_sim_local_bpf.h` changed, the sim was rebuilt:
  `make -C native-sim/x86 micro-proofs-build` rc=0 (every micro-prog `ok`).
- `native-sim/formal/Makefile`: added the `test_x86_bzhi_route_host` build +
  run pair after the `test_x86_bzhi_host` pair.
- `native-sim/formal/README.md`: routing paragraph added after the BZHI
  theorem paragraph; the stale TCB paragraph ("The `X86_SIM_L_EXEC_BZHI` and
  `X86_SIM_L_EXEC_BZHI_MEM` handler bodies do not call the generated
  `x86_bzhi.h` macros…") deleted; the binding-list clause updated to record
  the simulator's routing of both bodies through the `KPROG_X86_BZHI_*`
  contract.
- `docs/kprog-simulator-in-ebpf/sections/4-safety.tex`: routing sentence pair
  inserted after the BZHI oracle paragraph; structural balance re-verified
  (0 tabs; the introduced `(`/`)` and `{`/`}` deltas are equal; `$` count
  unchanged).
- Mutation harness `mut_x86_bzhi_route.py`: 26/26 DETECTED — the
  simulator-header distortions caught by the route oracle alone (the
  value-source test inverted, the count-source test inverted, the write width
  hardcoded to `8`, the count mask hardcoded to `0x7f` in *each* of the two
  count-source branches, `BZHI` tagged as the memory body, `BZHI_MEM` tagged as
  the register body, the dispatcher BZHI_MEM arm routed to the register body,
  the dispatcher BZHI arm routed to the memory body); the generated-C defects
  caught by the generator `--check` and the route oracle (the value-source
  register/memory defines colliding, the count-source register/AUX-shift defines
  colliding, the per-opcode value/count-source defines colliding, the
  write-width default colliding, the 64-bit width code moved, the count mask
  colliding, both opcode static-assert codes drifted); one shared-spec mutation
  caught by the generator `--check` (the count mask moved to `7f`); and the Lean
  independent-spec mutations caught by the refinement module (`BZHI`'s value
  source moved to `memoryRead`, `BZHI_MEM`'s count source moved to `register`,
  the 64-bit code mapping moved to `w32`, the count mask moved to `7f`).
- Full gate `make -C native-sim/formal check` rc=0.

## Next after 0076


Remaining x86 open work is unchanged and *compositional/handwritten*: the
index-register decode into the AUX index byte itself; register/immediate/RHS
objdump→AUX selection; compiler/native bytes; multi-step control-flow traces;
specialization preservation.

### KVM selftest smoke at `5aa795837`, 2026-09-29

- `make selftest` (default `PLATFORM=kvm ARCH=x86`, zero extra env vars),
  launched 22:56:40Z, completed 23:06:13Z (~49.5 min; host-build prefix of
  the log rotated out, retained 504-line in-VM tail), make PID 230578, host
  kernel `7.3.0-070300rc3-generic`, virtme-ng 1.41, `sudo -n` OK.
- All four sections PASS in the host log: kop modules load
  (`bpf_x86_alu: loading out-of-tree module`); native_proof micro smoke
  29/29 benchmarks (`[bench] (1/29) simple` → `result 12345678`,
  `compile last 444787 ns | exec last 163 ns`); `PASS unchecked_packet_read
  rejected rc=1`; BPF verifier negative smoke `PASS valid_xdp_pass`,
  `PASS invalid_opcode errno=22`, `PASS stack_oob_write errno=13`,
  `PASS uninitialized_register errno=13`. VM powered down cleanly
  (`kvm: exiting hardware virtualization`, `reboot: Power down`); no make
  error markers in the log.
- Driver artifact: `tests/results/62ce5f12/native_proof_micro_20260929_230257_731320/`
  (random `RUN_TOKEN`, untracked): `metadata.json` `status: completed`,
  `details/progress.json` `29/29 completed`, `details/result.json` 29
  benchmarks with `simple` → `expected_result: 12345678`,
  `expected_retval: 2`, `exec_cycles: 5686`, `details/code_compare/` 29
  files. Suite-level `selftest.log`/`native_proof_micro.json` were not in
  the host token dir at power-down; PASS rests on the host make log plus
  the driver run dir.
- Source state: the tree carried an uncommitted, supervisor-owned
  `bpfopt/llvm/src/llvm_mapinline.hpp` (+3: `Aggressive` target machine +
  `promote_register_allocas`); the rebuilt x86 runtime image was built from
  that dirty source. Paper-B speculative evidence stays blocked pending a
  clean-source image rebuild; ordinary provenance proceeded.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0041-20260929T234020Z/make-selftest.log`
  and `run-marker.txt`; full report in `step-report.md`.

### KVM micro sanity (`simple`) at `5b4730556`, 2026-09-30

- `make micro BENCH="simple" SAMPLES=1 WARMUPS=0 INNER_REPEAT=10` (default
  `PLATFORM=kvm ARCH=x86`, zero extra env vars), launched 00:12:40Z,
  completed 00:17:13Z (~4.5 min; x86 image cached from step 0041), make
  PID 302214, host kernel `7.3.0-070300rc3-generic`.
- Run `micro/results/x86_kvm_micro_20260930_001655_090124/`
  `status: completed` (1/1 benchmark), VM powered down cleanly, no make
  error markers. `simple` matches on all three runtimes (raw):
  `native` `compile_ns: 52456` / `exec_ns: 13` / `native_code_bytes: 61`;
  `kernel` `compile_ns: 387392` / `exec_ns: 44` / `jited_prog_len: 111`;
  `llvmbpf` `compile_ns: 4471088` / `exec_ns: 21` / `native_code_bytes: 59`;
  all `result: 12345678` = `expected_result`, `retval: 2` =
  `expected_retval`. Raw counters only, no ratio vs the 09-26 anchor
  (`x86_kvm_micro_20260926_105108_035832`); the check is exact-result
  match, not a performance delta.
- Tracked summary files added to git: `metadata.json`,
  `details/result.json`, `details/progress.json` (same set as the 09-26
  run); `code_compare/` and `jit_dumps/` stay ignored.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0042-20260930T001631Z/make-micro.log`
  and `run-marker.txt`; full report in `step-report.md`.

### KVM katran corpus run at `1207dbb06`, 2026-09-30

- `BPFREJIT_CORPUS_APPS=katran make corpus` (default `PLATFORM=kvm ARCH=x86`,
  default policy `SAMPLES=3 WORKLOAD_DURATION=30`, zero extra env vars),
  launched 00:41Z, make PID 317784, `RUN_TOKEN=06e78ce0`, x86 image cached
  from the step 0041 build; host kernel `7.3.0-070300rc3-generic`.
- Run `corpus/results/x86_kvm_corpus_20260930_004629_965759/`
  `status: completed` (`suite_name: macro_apps`, `samples: 3`,
  `workload_only: False`), VM powered down cleanly, no make error markers.
- katran `status: ok`, rejit `mode: loadtime`,
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce, kop]`,
  selected workload `xdp_pktgen`. Raw two-start counters
  (`details/apps/katran.json`, raw only): `balancer_ingres` baseline
  (id 9) `run_cnt_delta: 219,971,021` / `run_time_ns_delta: 38,647,805,320`
  / `bytes_jited: 13,641` / `bytes_xlated: 23,840`; post_rejit (id 87)
  `run_cnt_delta: 236,092,608` / `run_time_ns_delta: 36,630,391,333` /
  `bytes_jited: 11,778` / `bytes_xlated: 19,392`. Raw pktgen
  `pkts-sofar`/`errors` per workload: baseline
  `23,985,728/25,997,023`, `24,776,575/27,529,992`,
  `5,606,892/5,997,366`; post_rejit `25,892,525/27,086,961`,
  `15,686,193/13,641,759`, `25,472,272/24,123,226`. No ratio or rollup —
  analysis per `docs/evaluation.md` §5.
- Tracked summary files added to git (same set as the 09-24 KVM runs):
  `metadata.json`, `details/result.json`, `details/progress.json`,
  `details/apps/katran.json`, `details/loadtime-reports/katran.jsonl`;
  `shim-logs/` and `loadtime-plans/` stay ignored.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0043-20260930T005037Z/make-corpus.log`
  and `run-marker.txt`; full report in `step-report.md`.

### KVM bcc/set corpus run at `897291237`, 2026-09-30

- `BPFREJIT_CORPUS_APPS="bcc/set" make corpus` (default `PLATFORM=kvm
  ARCH=x86`, default policy `SAMPLES=3 WORKLOAD_DURATION=30`, zero extra
  env vars), launched 01:35Z, make PID 348425, `RUN_TOKEN=94f9b166`,
  x86 image cached from the step 0041 build; host kernel
  `7.3.0-070300rc3-generic`.
- Attempt 1 (`BPFREJIT_CORPUS_APPS="bcc,set"`, make PID 334899,
  01:26Z) **failed fast** at the driver's fail-fast check:
  `references unknown apps: ['bcc', 'set']; available: ['bcc/set',
  'cilium/agent', 'katran', 'otelcol-ebpf-profiler/profiling',
  'tetragon/observer', 'tracee/monitor']` — the app key is the single
  `app/tool` entry `bcc/set`, and the comma split it into two unknown
  names. No run dir created, VM powered down cleanly, `make: ***
  [Makefile:276: corpus-kvm-x86] Error 2`. Mechanical typo, not a suite
  failure; failure preserved in
  `step-0044-20260930T012822Z/make-corpus-failed-attempt1.log` and
  noted in the run marker.
- Run `corpus/results/x86_kvm_corpus_20260930_013937_924928/`
  `status: completed` (`suite_name: macro_apps`, `samples: 3`,
  `workload_only: False`), VM powered down cleanly, no make error
  markers.
- `bcc/set` `status: ok`, rejit `mode: loadtime`,
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce, kop]`,
  selected workload `stress_ng_bcc_hook_hot` (3 samples, all
  `returncode: 0`). Raw two-start counters
  (`details/apps/bcc__set.json`, raw only): `sys_enter` baseline
  (id 75) `run_cnt_delta: 541,768,543` / `run_time_ns_delta:
  44,316,208,484` / `bytes_jited: 108` / `bytes_xlated: 168`;
  `sys_exit` (id 77) `541,768,554` / `47,526,478,291` / `406` / `656`;
  post_rejit `sys_enter` (id 718) `546,561,845` / `44,314,841,636` /
  `69` / `112`; `sys_exit` (id 908) `546,561,851` / `47,147,870,673` /
  `262` / `408`. No ratio or rollup — analysis per
  `docs/evaluation.md` §5.
- Tracked summary files added to git: `metadata.json`,
  `details/result.json`, `details/progress.json`,
  `details/apps/bcc__set.json`, `details/loadtime-reports/bcc__set.jsonl`;
  `shim-logs/` and `loadtime-plans/` stay ignored.
- Retained log copies + run marker:
  `docs/tmp/build-and-evaluate/step-0044-20260930T012822Z/make-corpus.log`
  (attempt 2), `make-corpus-failed-attempt1.log` (attempt 1), and
  `run-marker.txt`; full report in `step-report.md`.

### KVM micro bench `bcc_runqlat_log2_histogram_bucket` at `944ff6fb7`, 2026-09-30

- `make micro BENCH="bcc_runqlat_log2_histogram_bucket" SAMPLES=1
  WARMUPS=0 INNER_REPEAT=10` (default `PLATFORM=kvm ARCH=x86`, same
  sanity knobs as the step 0042 `simple` run; zero extra env vars beyond
  the bench knob), launched 02:23Z, x86 image cached from the step 0041
  build; host kernel `7.3.0-070300rc3-generic`.
- Run `micro/results/x86_kvm_micro_20260930_022413_595750/`
  `status: completed` (`progress.json`: 1/1 benchmark completed), VM
  powered down cleanly, no make error markers.
- All three runtimes matched `expected_result 17790125373615940312` /
  `retval 2`. Raw per-runtime sample-0 counters
  (`details/result.json`, raw only):
  `native` `compile_ns 33,855` / `exec_ns 1,952` /
  `bpf_bytecode_bytes 1416` / `native_code_bytes 340`; `kernel`
  `compile_ns 79,885,857` / `exec_ns 2,023` / `1368` / `720`
  (+ `jited_prog_len 720`, `xlated_prog_len 1368`, `exec_cycles
  14,822,490`, `tsc_freq_hz 3,686,168,041`); `llvmbpf`
  `compile_ns 12,549,987` / `exec_ns 1,213` / `1416` / `434`
  (+ `exec_cycles 4,470`, `tsc_freq_hz 3,686,226,999`). No ratio or
  rollup — analysis per `docs/evaluation.md` §5.
- Tracked summary files added to git (same set as the step 0042 `simple`
  run): `metadata.json`, `details/result.json`,
  `details/progress.json`; `code_compare/` and `jit_dumps/` stay ignored.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0045-20260930T022311Z/make-micro.log`
  and `run-marker.txt`; full report in `step-report.md`.
- `PLATFORM=aws ARCH=arm64` micro/corpus within caps is **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials land.

### KVM micro bench `cgroup_skb_hash_chain` at `42553ea42`, 2026-09-30

- `make micro BENCH="cgroup_skb_hash_chain" SAMPLES=1 WARMUPS=0
  INNER_REPEAT=10` (default `PLATFORM=kvm ARCH=x86`, same sanity knobs
  as steps 0042/0045; zero extra env vars), launched 02:46:55Z
  (attempt 1) / 02:50Z (attempt 2, make PID 392574), x86 image cached
  from the step 0041 build; host kernel `7.3.0-070300rc3-generic`.
- Attempt 1 (02:46:55Z) was killed by `SIGTERM from pid 361074 (omp)`
  during VM boot (`qemu-system-x86_64: terminating on signal 15`),
  before any suite work — an external session-teardown interrupt, not a
  suite failure. No run dir created; preserved in
  `make-micro-interrupted-attempt1.log`, noted in the run marker.
- Run `micro/results/x86_kvm_micro_20260930_025441_553888/`
  `status: completed` (`progress.json`: 1/1 benchmark completed), VM
  powered down cleanly, no make error markers.
- First micro bench with a non-XDP program type and
  `expected_retval != 2` (prior two — `simple`,
  `bcc_runqlat_log2_histogram_bucket` — were both staged XDP, retval
  2). All three runtimes matched `expected_result
  12027228624407116210` / `retval 1`. Raw per-runtime sample-0 counters
  (`details/result.json`, raw only): `native` `compile_ns 34,931` /
  `exec_ns 209` / `bpf_bytecode_bytes 936` / `native_code_bytes 561`;
  `kernel` `compile_ns 1,187,083` / `exec_ns 294` / `936` / `520`
  (+ `jited_prog_len 520`, `xlated_prog_len 936`, `exec_cycles 1,329`,
  `tsc_freq_hz 3,686,055,316`); `llvmbpf` `compile_ns 9,658,372` /
  `exec_ns 455` / `936` / `275` (+ `exec_cycles 1,676`, `tsc_freq_hz
  3,686,108,108`). No ratio or rollup — analysis per
  `docs/evaluation.md` §5.
- Tracked summary files added to git (same set as the step 0042/0045
  micro runs): `metadata.json`, `details/result.json`,
  `details/progress.json`; `code_compare/` and `jit_dumps/` stay
  ignored.
- Retained log copies + run marker:
  `docs/tmp/build-and-evaluate/step-0046-20260930T024655Z/make-micro.log`
  (attempt 2), `make-micro-interrupted-attempt1.log` (attempt 1), and
  `run-marker.txt`; full report in `step-report.md`.

### KVM cilium/agent corpus run at `9738ca00f`, 2026-09-30

- `BPFREJIT_CORPUS_APPS="cilium/agent" make corpus` (default
  `PLATFORM=kvm ARCH=x86`; default policy `SAMPLES=3`,
  `WORKLOAD_DURATION` 30 s, `FUZZ_ROUNDS=1000`; zero extra env vars),
  launched 03:14:42Z, make PID 407106, x86 image cached from the step
  0041 build; host kernel `7.3.0-070300rc3-generic`.
- Run `corpus/results/x86_kvm_corpus_20260930_031929_336215/`
  `status: completed` (`progress.json` status `completed`); suite
  `details/result.json` `status: ok`, `suite_name: macro_apps`,
  `samples: 3`; app `details/apps/cilium__agent.json` `status: ok`,
  `error: ''`. `rejit_result`: `mode: loadtime`,
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce,
  kop]`, `selected_workload: cilium_endpoint_pktgen`, `runner:
  cilium`.
- **53 BPF programs** recorded per start (baseline and post_rejit),
  keyed by in-VM program id. Hot pair is `cil_from_container` (LXC
  endpoint forward program); the two-start raw two-start BPF counters
  (raw only, no ratios):
  - baseline `cil_from_container` id 147 `run_cnt_delta
    57,263,642` / `run_time_ns_delta 40,673,150,028` / `bytes_jited
    1,093` / `bytes_xlated 1,720`; id 163 `run_cnt_delta 57,273,769` /
    `run_time_ns_delta 40,567,185,435` / `1,093` / `1,720`.
  - post_rejit `cil_from_container` id 2058 `run_cnt_delta
    60,692,033` / `run_time_ns_delta 38,285,958,028` / `bytes_jited
    952` / `bytes_xlated 1,416`; id 2214 `run_cnt_delta 60,631,769` /
    `run_time_ns_delta 37,389,204,336` / `952` / `1,416`.
  - The full 53-program table is preserved verbatim in
    `details/apps/cilium__agent.json` (tracked into git this step).
- Raw app-side workload counters (two `kernel_pktgen` components per
  sample, both `rc=0`, `errors: 0` across all six runs; `pkts-sofar`
  per netns `bpfbench-cepa` / `bpfbench-cepb`):
  - baseline: sample 0 `19,001,255`/`19,007,707`; sample 1
    `19,254,010`/`19,253,530`; sample 2 `19,008,281`/`19,012,437`.
  - post_rejit: sample 0 `20,853,949`/`20,853,437`; sample 1
    `20,037,542`/`19,972,009`; sample 2 `19,800,446`/`19,806,227`.
  - No ratio, geomean, or win/loss tally computed here — any
    cross-start comparison is analysis per `docs/evaluation.md` §5.
- In-VM BPF program ids differ between the two starts (147/163 →
  2058/2214 for the same named program), so the hot pair is matched by
  `name`, not id.
- Tracked summary files added to git (same set as the step 0043/0044
  corpus runs): `metadata.json`, `details/result.json`,
  `details/progress.json`, `details/apps/cilium__agent.json`,
  `details/loadtime-reports/cilium__agent.jsonl`; `details/shim-logs/`
  and `details/loadtime-plans/` stay ignored.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0047-20260930T031442Z/make-corpus.log`
  and `run-marker.txt`; full report in `step-report.md`.
- `PLATFORM=aws ARCH=arm64` corpus within caps is **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.

### KVM tracee/monitor corpus run at `65a34c7cd`, 2026-09-30

- `BPFREJIT_CORPUS_APPS="tracee/monitor" make corpus` (default
  `PLATFORM=kvm ARCH=x86`; default policy `SAMPLES=3`,
  `WORKLOAD_DURATION` 30 s, `FUZZ_ROUNDS=1000`; zero extra env vars),
  launched 03:48:34Z, make PID 422716, x86 image cached from the step
  0041 build; host kernel `7.3.0-070300rc3-generic`.
- Run `corpus/results/x86_kvm_corpus_20260930_035320_255208/`
  `status: completed` (`progress.json` status `completed`); suite
  `details/result.json` `status: ok`, `suite_name: macro_apps`,
  `samples: 3`; app `details/apps/tracee__monitor.json` `status: ok`,
  `error: ''`. `rejit_result`: `mode: loadtime`,
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce,
  kop]`, `selected_workload: stress_ng_tracee_syscall_hot`,
  `runner: tracee`.
- **151 BPF programs** recorded per start (baseline and post_rejit) —
  the largest program count of the session (vs. 53 for cilium). 56
  programs had a nonzero `run_cnt_delta` per start. Full 151-program
  table preserved in `details/apps/tracee__monitor.json` (tracked into
  git this step). Top hot progs by `run_cnt_delta` (raw two-start BPF
  counters, raw only; in-VM ids differ between starts so pairs matched
  by `name`; `name` strings truncated to 16 chars by the kernel):
  - baseline `tracepoint__raw_sys_enter` id 19 `run_cnt_delta
    248,150,238` / `run_time_ns_delta 98,946,033,709` / `bytes_jited
    8,194` / `bytes_xlated 13,768`; `tracepoint__raw_sys_exit` id 20
    `248,150,245` / `100,255,357,349` / `8,227` / `13,824`.
  - post_rejit `tracepoint__raw_sys_enter` id 373 `245,748,172` /
    `97,468,963,109` / `bytes_jited 7,593` / `bytes_xlated 11,976`;
    `tracepoint__raw_sys_exit` id 386 `245,748,176` / `96,695,526,877`
    / `7,618` / `12,016`.
  - `trace_ret_vfs_read` id 99 (baseline) / 1263 (post_rejit)
    `26,831,607` / `27,000,454` runs; `trace_ret_vfs_write` id 85 /
    1111 `6,636,561` / `6,688,343` runs. `bytes_jited` dropped for the
    two hottest sys_enter/sys_exit tracepoint progs after the ReJIT
    pass chain (8,194/8,227 → 7,593/7,618).
- Raw app-side workload counters (`stress_ng_tracee_syscall_hot`,
  7-stressor `stress-ng` run, all six runs `rc=0`, `failed: 0`,
  `metrics untrustworthy: 0`; per-stressor raw bogo-ops, raw only):
  - baseline: cap `1,846,802`/`1,797,365`/`1,923,882`; set
    `151,535`/`154,866`/`152,477`; sigfd `4,568,349`/`4,517,945`/
    `4,672,999`; eventfd `1,091,014`/`1,085,741`/`1,090,194`; kill
    `823,490`/`836,935`/`812,020`; futex `4,328,636`/`4,394,750`/
    `4,483,028`; prctl `11,786`/`8,708`/`8,099`.
  - post_rejit: cap `1,875,575`/`1,863,837`/`1,808,564`; set
    `151,571`/`150,084`/`151,152`; sigfd `4,566,239`/`4,743,076`/
    `4,516,371`; eventfd `1,103,945`/`1,093,747`/`1,094,724`; kill
    `820,893`/`765,786`/`794,342`; futex `4,406,154`/`4,525,774`/
    `4,478,158`; prctl `8,150`/`9,724`/`9,980`.
  - No ratio, geomean, or win/loss tally computed here — any
    cross-start comparison is analysis per `docs/evaluation.md` §5.
- Tracked summary files added to git (same set as the step 0043/0044/
  0047 corpus runs): `metadata.json`, `details/result.json`,
  `details/progress.json`, `details/apps/tracee__monitor.json`,
  `details/loadtime-reports/tracee__monitor.jsonl`;
  `details/shim-logs/` and `details/loadtime-plans/` stay ignored.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0048-20260930T034834Z/
  make-corpus.log` (455 lines, clean power-down) and `run-marker.txt`;
  full report in `step-report.md`.
- `PLATFORM=aws ARCH=arm64` corpus within caps is **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.

### KVM tetragon/observer corpus run at `7c01f1340`, 2026-09-30

- `BPFREJIT_CORPUS_APPS="tetragon/observer" make corpus` (default
  `PLATFORM=kvm ARCH=x86`; default policy `SAMPLES=3`,
  `WORKLOAD_DURATION` 30 s, `FUZZ_ROUNDS=1000`; zero extra env vars),
  launched 04:30:26Z, make PID 439128, x86 image cached from the step
  0041 build; host kernel `7.3.0-070300rc3-generic`.
- Run `corpus/results/x86_kvm_corpus_20260930_043516_570740/`
  `status: completed` (`progress.json` status `completed`); suite
  `details/result.json` `status: ok`, `suite_name: macro_apps`,
  `samples: 3`; app `details/apps/tetragon__observer.json` `status:
  ok`, `error: ''`. `rejit_result`: `mode: loadtime`,
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce,
  kop]`, `selected_workload: stress_ng_tetragon_policy_hot`,
  `runner: tetragon`.
- **287 BPF programs** recorded per start (baseline and post_rejit) —
  the largest program count of the session (vs. 151 for tracee, 53 for
  cilium). 32 programs had a nonzero `run_cnt_delta` at baseline, 35
  at post_rejit. Full 287-program table preserved in
  `details/apps/tetragon__observer.json` (tracked into git this
  step). Top hot progs by `run_cnt_delta` (raw two-start BPF counters,
  raw only; in-VM ids differ between starts so pairs matched by
  `name`; `name` strings truncated to 16 chars by the kernel):
  - baseline `generic_tracepoint` id 214 `run_cnt_delta 224,546,563` /
    `run_time_ns_delta 163,445,837,000` / `bytes_jited 14,942` /
    `bytes_xlated 26,568`; `generic_retkprobe` id 142 `40,927,410` /
    `1,976,902,600` / `15,275` / `26,384`; `generic_kprobe_*` id 136
    `40,927,410` / `24,859,691,600` / `1,879` / `3,304`.
  - post_rejit `generic_tracepoint` id 2152 `236,028,705` /
    `122,954,311,472` / `bytes_jited 11,895` / `bytes_xlated 21,888`;
    `generic_retkprobe` id 1569 `50,892,497` / `2,392,676,083` /
    `15,275` / `26,384`; `generic_kprobe_*` id 1564 `50,892,497` /
    `30,508,232,057` / `1,371` / `2,336`.
  - `bytes_jited` dropped for the hottest tracepoint/kprobe progs
    after the ReJIT pass chain (e.g. 14,942 → 11,895; 1,879 → 1,371);
    full per-program detail in the tracked JSON.
- Raw app-side workload counters (`stress_ng_tetragon_policy_hot`,
  6-stressor `stress-ng` run, all six runs `rc=0`, `failed: 0`;
  per-stressor raw bogo-ops, raw only):
  - baseline: eventfd `1,935,185`/`1,787,637`/`1,858,339`; mmap
    `805`/`796`/`769`; udp `3,306,826`/`3,193,481`/`3,230,045`;
    sock `9,344`/`8,770`/`9,776`; sockfd `3,481,844`/`3,418,449`/
    `3,414,332`; sockpair `1,212,312`/`1,230,939`/`1,273,602`.
  - post_rejit: eventfd `2,696,439`/`2,236,132`/`1,842,316`; mmap
    `963`/`898`/`816`; udp `5,543,632`/`4,992,934`/`3,388,677`;
    sock `43,216`/`21,924`/`9,688`; sockfd `7,394,907`/`4,764,568`/
    `3,409,259`; sockpair `2,167,331`/`1,584,325`/`1,127,976`.
  - No ratio, geomean, or win/loss tally computed here — any
    cross-start comparison is analysis per `docs/evaluation.md` §5.
- In-VM BPF program ids differ between the two starts (e.g. 214 →
  2152 for `generic_tracepoint`), so hot progs are matched by `name`,
  not id; the generic `generic_kprobe_*` names collide across distinct
  programs, distinguished by id in the full JSON.
- Tracked summary files added to git (same set as the step 0043/0044/
  0047/0048 corpus runs): `metadata.json`, `details/result.json`,
  `details/progress.json`, `details/apps/tetragon__observer.json`,
  `details/loadtime-reports/tetragon__observer.jsonl`;
  `details/shim-logs/` and `details/loadtime-plans/` stay ignored.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0049-20260930T043026Z/
  make-corpus.log` (449 lines, clean power-down) and `run-marker.txt`;
  full report in `step-report.md`.
- `PLATFORM=aws ARCH=arm64` corpus within caps is **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.

### KVM otelcol-ebpf-profiler/profiling corpus run at `2d0a0995a`, 2026-09-30

- `BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" make corpus`
  (default `PLATFORM=kvm ARCH=x86`; default policy `SAMPLES=3`,
  `WORKLOAD_DURATION` 30 s, `FUZZ_ROUNDS=1000`; zero extra env vars),
  launched 04:59:24Z, make PID 454478, x86 image cached from the step
  0041 build; host kernel `7.3.0-070300rc3-generic`.
- Run `corpus/results/x86_kvm_corpus_20260930_050405_991692/`
  `status: completed` (`progress.json` status `completed`); suite
  `details/result.json` `status: ok`, `suite_name: macro_apps`,
  `samples: 3`; app `details/apps/otelcol-ebpf-profiler__profiling.json`
  `status: ok`, `error: ''`. `rejit_result`: `mode: loadtime`,
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce,
  kop]`, `selected_workload: otel_mixed_workload`,
  `runner: otelcol-ebpf-profiler`.
- **13 BPF programs** recorded per start (baseline and post_rejit) —
  the smallest program count of the session. 2 hot progs per start
  (nonzero `run_cnt_delta`); the other 11 (per-language
  `perf_unwind_*` + `perf_go_labels` + `custom__generic`) zero-run for
  this workload, recorded as raw zero counters, not excluded. Full
  13-program table in `details/apps/otelcol-ebpf-profiler__profiling.json`
  (tracked into git this step). Hot progs by `run_cnt_delta` (raw
  two-start BPF counters, raw only; in-VM ids differ between starts so
  pairs matched by `name`; `name` strings truncated to 16 chars by the
  kernel):
  - baseline `native_tracer_e` id 17 `run_cnt_delta 723,698` /
    `run_time_ns_delta 3,230,143,971` / `bytes_jited 3,815` /
    `bytes_xlated 5,904`; `tracepoint__sch` id 16 `103` / `177,377` /
    `792` / `1,320`.
  - post_rejit `native_tracer_e` id 192 `723,217` /
    `3,540,538,933` / `bytes_jited 3,688` / `bytes_xlated 5,584`;
    `tracepoint__sch` id 179 `99` / `168,671` / `698` / `1,224`.
  - Zero-run progs (both starts, `bytes_jited`/`bytes_xlated`):
    `perf_unwind_php` 14,983/24,736 → 14,451/22,520;
    `perf_unwind_pyt` 19,605/33,208 → 14,539/24,584;
    `perf_unwind_rub` 17,840/30,280 → 19,610/30,632;
    `perf_unwind_v8` 20,215/33,448 → 20,117/31,504;
    `perf_unwind_dot` 22,797/37,440; `perf_go_labels` 1,572/2,504 →
    1,405/2,184; `custom__generic` 3,679/5,712 → 3,549/5,400;
    `perf_unwind_sto` 3,650/6,144 → 3,432/5,616;
    `perf_unwind_nat` 21,868/37,024 → 20,614/33,296;
    `perf_unwind_hot` 18,424/28,080; `perf_unwind_per` 18,264/29,640 →
    17,686/26,752.
- Raw app-side workload counters (`otel_mixed_workload`, 3 samples ×
  11 components, all `rc=0`; per-language raw `int_loop ops=`
  counters from stderr, 2 workers per sample, raw only):
  - python3: `136,732,043`/`142,841,193` | `119,095,556`/`161,105,052`
    | `172,740,653`/`158,097,665` (baseline s0/s1/s2);
    `129,962,456`/`157,633,531` | `142,851,384`/`173,417,323` |
    `119,438,991`/`162,475,486` (post_rejit s0/s1/s2).
  - ruby: `358,220,751`/`427,129,736` | `381,323,499`/`396,586,544` |
    `284,929,481`/`366,698,446`; post `379,956,660`/`327,097,648` |
    `327,539,260`/`309,377,022` | `362,363,039`/`339,476,110`.
  - nodejs: `371,542,141`/`326,937,393` | `360,851,851`/`354,774,918`
    | `338,538,363`/`384,881,116`; post `382,425,809`/`355,494,800` |
    `362,055,085`/`364,167,603` | `341,915,438`/`325,222,523`.
  - perl: `148,781,768`/`145,156,042` | `162,934,308`/`193,509,254` |
    `179,163,377`/`142,303,898`; post `146,652,385`/`184,680,612` |
    `161,120,153`/`180,777,379` | `128,496,521`/`179,997,159`.
  - php: `674,924,279`/`626,775,779` | `572,562,162`/`504,417,485` |
    `572,620,368`/`571,359,687`; post `631,166,935`/`507,325,964` |
    `599,540,707`/`525,054,643` | `696,122,711`/`610,816,875`.
  - stress-ng cpu bogo-ops: baseline `40,256`/`41,006`/`43,036`;
    post_rejit `40,477`/`38,962`/`48,372`.
  - No ratio, geomean, or win/loss tally computed here — any
    cross-start comparison is analysis per `docs/evaluation.md` §5.
- **Completes evidence for all 6 supported corpus apps**
  (`bcc/set`, `cilium/agent`, `katran`, `otelcol-ebpf-profiler/
  profiling`, `tetragon/observer`, `tracee/monitor`) on the KVM x86
  line.
- Tracked summary files added to git (same set as the step 0043/0044/
  0047/0048/0049 corpus runs): `metadata.json`, `details/result.json`,
  `details/progress.json`,
  `details/apps/otelcol-ebpf-profiler__profiling.json`,
  `details/loadtime-reports/otelcol-ebpf-profiler__profiling.jsonl`;
  `details/shim-logs/` and `details/loadtime-plans/` stay ignored.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0050-20260930T045924Z/
  make-corpus.log` (439 lines, clean power-down) and `run-marker.txt`;
  full report in `step-report.md`.
- `PLATFORM=aws ARCH=arm64` corpus within caps is **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.

### KVM corpus full default suite (all 6 apps) at `6a6304a91`, 2026-09-30

- Plain `make corpus` (no `BPFREJIT_CORPUS_APPS`, no
  `SAMPLES`/`WORKLOAD_DURATION`/`FUZZ_ROUNDS` overrides; all defaults
  from `runner/targets/*.env`: `PLATFORM=kvm`, `ARCH=x86`,
  `SAMPLES=3`, `WORKLOAD_DURATION` 30 s, `FUZZ_ROUNDS=1000`) — the
  canonical full-suite invocation running the entire supported corpus
  (`corpus/config/macro_apps.yaml`: `bcc/set`,
  `otelcol-ebpf-profiler/profiling`, `cilium/agent`,
  `tetragon/observer`, `katran`, `tracee/monitor`) in a single suite
  run; launched 05:34:48Z, make PID 470360, x86 image cached from the
  step 0041 build; host kernel `7.3.0-070300rc3-generic`.
- Run `corpus/results/x86_kvm_corpus_20260930_053929_108492/`
  `status: completed` (`progress.json` status `completed`); suite
  `details/result.json` `status: ok`, `suite_name: macro_apps`,
  `samples: 3` (in-VM suite 05:39:29 → 06:13:38Z, ~34 min; VM
  power-down ~06:14Z).
- **All 6 apps `status: ok`, `error: ''`**; `rejit_result` per app
  `mode: loadtime`, default x86 pass chain `[noop, map_inline,
  const_prop, dce, wide_mem, bounds_check_merge,
  skb_load_bytes_spec, noop, const_prop, dce, kop]`. Per-app BPF
  program counts recorded per start (baseline / post_rejit) + hot
  counts: bcc/set 25/25 (17/17 hot); cilium/agent 53/56 (8/4 hot);
  katran 1/1 (1/1 hot); otelcol-ebpf-profiler/profiling 13/13 (2/2
  hot); tetragon/observer 287/287 (33/35 hot); tracee/monitor
  151/151 (57/54 hot). Full per-program tables in the tracked
  `details/apps/*.json` (all six tracked into git this step).
- Top hot programs by `run_cnt_delta` (raw two-start BPF counters,
  raw only; in-VM ids differ between starts so pairs matched by
  `name`, not id; `name` strings truncated to 16 chars by the
  kernel):
  - bcc/set `sys_exit` id 50 → 892: `553,579,529` → `553,357,976`
    runs; `bytes_jited` 406 → 262.
  - cilium/agent `cil_from_container` id 1467 → 3533:
    `60,278,495` → `61,297,916` runs; `bytes_jited` 1,093 → 952.
  - katran `balancer_ingress` id 6691 → 6769: `222,299,508` →
    `231,888,637` runs; `bytes_jited` 13,641 → 11,778.
  - otelcol `native_tracer_event` id 1095 → 1270: `723,341` →
    `722,703` runs; `bytes_jited` 3,815 → 3,688.
  - tetragon `generic_tracepoint` id 3868 → 5843: `221,794,542` →
    `237,073,117` runs; `bytes_jited` 14,942 → 11,895.
  - tracee `trace_sys_enter` id 6785 → 7139: `238,682,419` →
    `243,075,052` runs; `bytes_jited` 8,194 → 7,593.
  - `bytes_jited` dropped after the ReJIT pass chain on every app's
    hot programs; full per-program detail in the tracked JSON.
- Raw app-side workload counters (`samples: 3` per app, raw only, no
  ratios; katran's `errors=` is a raw pktgen counter, not a
  validity gate):
  - bcc/set `stress_ng_bcc_hook_hot`: raw bogo-ops per sample
    (syscall/cap/set/sockfd); e.g. baseline s0 `514`/`8,673,910`/
    `655,412`/`6,476,303`; post_rejit s0 `514`/`8,484,606`/
    `663,286`/`6,455,066`; all `failed: 0`.
  - cilium/agent `cilium_endpoint_pktgen`: raw `pkts-sofar` per
    endpoint, `errors=0`; baseline `19.74M`/`19.74M`/`20.00M`/
    `20.06M`/`20.39M`/`20.48M`; post_rejit `20.53M`/`20.53M`/
    `20.38M`/`20.39M`/`20.38M`/`20.38M`.
  - katran `xdp_pktgen`: raw `pkts-sofar` + raw `errors` per
    endpoint; baseline s0 `22.69M`/`1.95M`/`24.66M`/`24.73M`
    (errors `27.08M`/`2.17M`/`29.27M`/`29.01M`); post_rejit s0
    `20.56M`/`25.91M`/`25.09M`/`5.39M` (errors `19.43M`/`23.87M`/
    `23.91M`/`4.40M`).
  - otelcol `otel_mixed_workload`: raw per-language `int_loop ops=`
    (python3/ruby/nodejs/perl/php, 2 workers each) + raw stress-ng
    cpu bogo-ops; e.g. baseline s0 php `529,307,125`/`529,624,103`,
    cpu `39,926`; post_rejit s0 php `563,051,693`/`657,638,370`,
    cpu `39,142`.
  - tetragon `stress_ng_tetragon_policy_hot`: raw bogo-ops per
    stressor (eventfd/mmap/udp/sock/sockfd/sockpair); e.g. baseline
    s0 eventfd `1,898,361`, udp `3,227,082`, sockfd `3,491,941`;
    post_rejit s0 eventfd `2,642,769`, udp `5,286,053`, sockfd
    `6,483,858`; all `failed: 0`.
  - tracee `stress_ng_tracee_syscall_hot`: raw bogo-ops per
    stressor (cap/set/sigfd/eventfd/kill/futex/prctl); e.g. baseline
    s0 cap `1,777,597`, futex `4,537,498`; post_rejit s0 cap
    `1,823,916`, futex `4,590,194`; all `failed: 0`.
  - No ratio, geomean, or win/loss tally computed here — any
    cross-start comparison is analysis per `docs/evaluation.md` §5.
- cilium/agent recorded 56 progs post_rejit vs. 53 baseline (a few
  extra progs appeared in the second start) — recorded as-is, not
  excluded.
- Tracked summary files added to git: `metadata.json`,
  `details/result.json`, `details/progress.json`, all six
  `details/apps/*.json`, all six `details/loadtime-reports/*.jsonl`;
  `details/shim-logs/` and `details/loadtime-plans/` stay ignored.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0051-20260930T053448Z/
  make-corpus.log` (390 lines, clean power-down) and `run-marker.txt`;
  full report in `step-report.md`.
- This is the canonical **full-default** suite: the whole supported
  6-app corpus in one invocation, zero knobs — the most
  comprehensive single Make-backed KVM artifact of the session.
- `PLATFORM=aws ARCH=arm64` corpus within caps is **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.

### KVM micro bench `packet_toeplitz_rss_hash` at `42e1c4e37`, 2026-09-30

- `make micro BENCH=packet_toeplitz_rss_hash SAMPLES=1 WARMUPS=0
  INNER_REPEAT=10` (default `PLATFORM=kvm`, `ARCH=x86`; only the BENCH
  selection + the documented micro knobs, consistent with the
  session's prior micro increments); launched 06:49:36Z, make PID
  490235, x86 image cached; host kernel `7.3.0-070300rc3-generic`.
- `packet_toeplitz_rss_hash` is a packet-io XDP-class hash bench
  (`io_mode: packet`, 54-byte packet input, Toeplitz/5-tuple RSS
  hash codegen) — a distinct codegen class from the three micro
  benches already evidenced (`simple`,
  `bcc_runqlat_log2_histogram_bucket`, `cgroup_skb_hash_chain`).
- Run `micro/results/x86_kvm_micro_20260930_065534_021869/`
  `status: completed`; `progress.json` `completed_benchmarks: 1 /
  total_benchmarks: 1` (in-VM suite 06:55:34Z, ~42 s; VM power-down
  ~06:56Z).
- **All 3 runtimes (native / kernel / llvmbpf) matched**
  `expected_result: 13526464303109995596` / `expected_retval: 2`
  (`INNER_REPEAT=10`); raw sample counters:
  - `native`: `exec_ns=511`, `code_size` bpf 1,808 / native 799
    bytes.
  - `kernel`: `exec_cycles=14,861,068` (`tsc_freq_hz` ~3.686e9);
    `jited_prog_len=1,090`, `xlated_prog_len=1,808`;
    `object_load_ns` ~2.72 ms.
  - `llvmbpf`: `exec_cycles=3,557`, native 846 bytes;
    `jit_compile_ns` ~17.4 ms.
  - No ratio / geomean / rollup computed here (raw sample counters
    only; cross-start comparison is analysis per
    `docs/evaluation.md` §5).
- Kernel JIT `exec_cycles` (14.86M) far exceeds llvmbpf's (3,557) —
  expected for this kernel-only XDP-class bench under the in-VM
  harness; recorded as-is.
- Tracked summary files added to git: `metadata.json`,
  `details/result.json`, `details/progress.json`;
  `details/code_compare/` and `details/jit_dumps/` stay ignored.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0052-20260930T064936Z/
  make-micro.log` (473 lines, clean power-down) and `run-marker.txt`;
  full report in `step-report.md`.
- `PLATFORM=aws ARCH=arm64` micro/corpus within caps is **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.

### KVM micro bench `bpf_local_call_fanout_dispatch` at `cb1f966a3`, 2026-09-30

- `make micro BENCH=bpf_local_call_fanout_dispatch SAMPLES=1 WARMUPS=0
  INNER_REPEAT=10` (default `PLATFORM=kvm`, `ARCH=x86`; only the
  BENCH selection + the documented micro knobs, consistent with the
  session's prior micro increments); launched 07:12:51Z, make PID
  504973, x86 image cached; host kernel `7.3.0-070300rc3-generic`.
- `bpf_local_call_fanout_dispatch` is a BPF-to-BPF local-call
  codegen bench (`io_mode: staged`, 392-byte input, tags `[call,
  bpf-to-bpf, local-call, reg-pressure, pure-jit]`) — a distinct
  codegen class from the four micro benches already evidenced
  (`simple`, `bcc_runqlat_log2_histogram_bucket`,
  `cgroup_skb_hash_chain`, `packet_toeplitz_rss_hash`).
- Run `micro/results/x86_kvm_micro_20260930_071732_207339/`
  `status: completed`; `progress.json` `completed_benchmarks: 1 /
  total_benchmarks: 1` (in-VM suite 07:17:32Z, ~42 s; VM power-down
  ~07:17:33Z).
- **All 3 runtimes (native / kernel / llvmbpf) matched**
  `expected_result: 1171593469689687806` / `expected_retval: 2`
  (`INNER_REPEAT=10`); raw sample counters:
  - `native`: `exec_ns=105`, `code_size` bpf 4,240 / native 291
    bytes.
  - `kernel`: `exec_cycles=14,784,621`; `exec_ns=249`; `code_size`
    bpf 4,240 / native 2,193 bytes.
  - `llvmbpf`: `exec_cycles=802`; `exec_ns=217`; `code_size`
    bpf 4,240 / native 869 bytes.
  - No ratio / geomean / rollup computed here (raw sample counters
    only; cross-start comparison is analysis per
    `docs/evaluation.md` §5).
- Kernel JIT `exec_cycles` (14.78M) vs llvmbpf (802) — expected
  spread for a kernel-local-call codegen bench under the in-VM
  harness; recorded as-is.
- BPF bytecode 4,240 bytes — largest of the five micro benches
  evidenced this session (the local-call fanout expands to multiple
  sub-programs); recorded as-is.
- Tracked summary files added to git: `metadata.json`,
  `details/result.json`, `details/progress.json`;
  `details/code_compare/` and `details/jit_dumps/` stay ignored.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0053-20260930T071251Z/
  make-micro.log` (473 lines, clean power-down) and `run-marker.txt`;
  full report in `step-report.md`.
- `PLATFORM=aws ARCH=arm64` micro/corpus within caps is **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.

### KVM `make test` suite (TEST_MODE=test) at `e4471dcd2`, 2026-09-30

- Plain `make test` (default `PLATFORM=kvm`, `ARCH=x86`;
  `TEST_MODE=test` per the Makefile target, `FUZZ_ROUNDS=1000`
  default but a no-op on the non-fuzz `test` path; zero knobs) —
  runs `runner.suites.test` in-VM (`__runtime-vm-test`), the last
  uncovered Make target on the KVM line alongside selftest/micro/
  corpus; launched 07:33:35Z, make PID 519630, x86 image cached;
  host kernel `7.3.0-070300rc3-generic`.
- Run token `tests/results/d83499ef/`; artifact
  `tests/results/d83499ef/native_proof_micro_20260930_073817_193862/`
  `status: completed`, `run_type: native_proof_micro` (in-VM
  07:38:17 → 07:38:21Z, ~46 s; VM power-down ~07:38:22Z).
- `progress.json` `completed_benchmarks: 29 / total_benchmarks: 29`.
- **All 29 `native_proof` benchmarks matched** their
  `expected_result`/`expected_retval` (`runtime=native_proof`,
  `--samples 1 --warmups 0 --inner-repeat 1`); the set spans the
  full `micro_pure_jit.yaml` catalog, re-confirming under
  `native_proof` the four benches already evidenced standalone this
  session (`simple`, `bcc_runqlat_log2_histogram_bucket`,
  `cgroup_skb_hash_chain`, `packet_toeplitz_rss_hash`).
- Section 2 `native_proof verifier rejection smoke`:
  **PASS `unchecked_packet_read rejected rc=1`** (the unsafe
  `off=64` read rejected as required).
- Section 3 `BPF verifier negative smoke`: **PASS**
  `valid_xdp_pass`; `invalid_opcode` (errno=22/EINVAL);
  `stack_oob_write` (errno=13/EACCES); `uninitialized_register`
  (errno=13/EACCES).
- Log: **0 error markers** (no `make ***`, `FAILED`, `fatal`,
  `Aborted`, `Terminated`, `did not match`, `unexpectedly
  succeeded`); clean VM power-down.
- All 32 files under `tests/results/d83499ef/` are trackable
  (`git check-ignore` reports 0 ignored; `tests/results/` is a
  tracked tree, 485 files precedent); tracked into git this step:
  `metadata.json`, `details/result.json`, `details/progress.json`,
  all 30 `details/code_compare/*.md`.
- No ratio / geomean / rollup computed here (raw sample counters
  only; cross-start comparison is analysis per
  `docs/evaluation.md` §5).
- This completes Make-target coverage on the KVM line:
  `selftest` (step 0041), `micro` (5 benches: `simple`,
  `bcc_runqlat_log2_histogram_bucket`, `cgroup_skb_hash_chain`,
  `packet_toeplitz_rss_hash`, `bpf_local_call_fanout_dispatch`),
  `corpus` (all 6 apps individually + full default suite), and now
  `test`.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0054-20260930T073335Z/
  make-test.log` (clean power-down) and `run-marker.txt`; full
  report in `step-report.md`.
- `PLATFORM=aws ARCH=arm64` test within caps is **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.

### KVM `make negative-test` at `7a0da65f0`, 2026-09-30 (observed
 test-mode shape; TEST_MODE in-VM propagation gap recorded)

- Plain `make negative-test` (default `PLATFORM=kvm`, `ARCH=x86`, zero
  knobs); launched 08:00:27Z, make PID 534924, x86 image cached; host
  kernel `7.3.0-070300rc3-generic`. Target intent is the dedicated
  negative-only suite (`TEST_MODE ?= negative`, Makefile:227;
  `_run_negative_mode`, `fuzz=False`, writes `negative.log`, no micro
  smoke).
- **Observed shape = test-mode, not negative-mode**: the run executed
  the three-section test-mode suite (`native_proof micro smoke` +
  `native_proof verifier rejection smoke` + `BPF verifier negative
  smoke`) and wrote a `native_proof_micro_<ts>/` dir, **not** a
  `negative.log`. Root cause confirmed via `make -n` dry runs of
  `negative-test`/`test`/`selftest`: the KVM `vng --exec "make -C …
  __runtime-vm-test $(RUN_MAKE_VARS)"` line carries **no `TEST_MODE`**
  (only `SAMPLES='3' FUZZ_ROUNDS='1000'
  MERLIN_COMPILETIME_MODE='none'`), so the in-VM suite fell back to
  `env_str("TEST_MODE","test")` (`runner/suites/test.py:48`). All three
  test-family targets run the default test-mode suite on the KVM path.
  Frozen benchmark Makefile — recorded as a wiring gap, not patched,
  not a gate.
- Run token `tests/results/4dca07ca/`; artifact
  `tests/results/4dca07ca/native_proof_micro_20260930_080511_037492/`
  `status: completed`, `run_type: native_proof_micro` (in-VM
  08:05:11 → 08:05:15Z, ~4 s; VM power-down ~08:05:16Z).
- `progress.json` `completed_benchmarks: 29 / total_benchmarks: 29`;
  **all 29 `native_proof` benchmarks matched** their
  `expected_result`/`expected_retval` (`runtime=native_proof`,
  `--samples 1 --warmups 0 --inner-repeat 1`).
- `BPF verifier negative smoke` (the "negative" substance, run as part
  of the test-mode suite): **PASS** `valid_xdp_pass`;
  `invalid_opcode` (errno=22/EINVAL); `stack_oob_write`
  (errno=13/EACCES); `uninitialized_register` (errno=13/EACCES) —
  invalid BPF programs rejected as required. Plus **PASS
  `unchecked_packet_read rejected rc=1`** from the verifier-rejection
  smoke.
- Log: **0 error markers** (no `make ***`, `FAILED`, `fatal`,
  `Aborted`, `Terminated`, `did not match`, `unexpectedly
  succeeded`); clean VM power-down.
- All 32 files under `tests/results/4dca07ca/` are trackable
  (`git check-ignore` reports 0 ignored); tracked into git this step:
  `metadata.json`, `details/result.json`, `details/progress.json`, all
  30 `details/code_compare/*.md`.
- No ratio / geomean / rollup computed (raw sample counters only;
  cross-start comparison is analysis per `docs/evaluation.md` §5).
- **Open item (recorded, not gated)**: TEST_MODE does not propagate
  in-VM on the KVM path (frozen Makefile), so the dedicated negative-
  only suite (`negative.log`, no micro smoke) is not produced by a
  zero-knob `make negative-test`. Forcing it needs `TEST_MODE=negative`
  reaching in-VM (outside the zero-knob rule) or a frozen-Makefile fix.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0055-20260930T080027Z/
  make-negative-test.log` (clean power-down) and `run-marker.txt`;
  full report in `step-report.md`.
- `PLATFORM=aws ARCH=arm64` within caps is **blocked on credentials**:
  no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.

### KVM `make corpus` variance re-run (zero knobs) at `674d32748`,
 2026-09-30

- Plain `make corpus` (default `PLATFORM=kvm`, `ARCH=x86`, zero knobs;
  `SAMPLES=3`, `WORKLOAD_DURATION=30` defaults); launched 08:37:24Z,
  make PID 721250, prev HEAD `674d32748`; run token `46529a8b`,
  result dir
  `corpus/results/x86_kvm_corpus_20260930_084230_227783/` (in-VM
  08:42:30 → 09:16:38Z, ~34 min; VM power-down at in-VM ~2090 s).
- **Purpose: paired variance data point against the canonical
  step-0051 full-corpus run (`42e1c4e37`)** — the paper's primary
  measurement is workload throughput, and `docs/evaluation.md` §5
  analysis (ratios, `min_runs ≥ 100` filter, geomean, tail-call
  accounting) needs ≥2 raw runs of the primary metric. This is the
  second whole-corpus run on the same host kernel
  (`7.3.0-070300rc3-generic`).
- Top `metadata.json` `status: completed`, `run_type:
  x86_kvm_corpus`, `samples: 3`, `workload_seconds: 30.0`;
  `enabled_passes: [noop, map_inline, const_prop, dce, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce,
  kop]` (same pass list as step 0051); `details/progress.json`
  `status: completed`, `completed_at 2026-09-30T09:16:38Z`.
- **All 6 apps `status: ok`, 0 `error`**, raw two-start BPF counters
  (sum `run_cnt_delta` baseline → post_rejit; sum `run_time_ns_delta`
  baseline → post_rejit):
  - `bcc/set` (25 progs/start): 1,264,807,680 → 1,261,697,834;
    131,799,998,389 → 130,103,656,097 ns.
  - `cilium/agent` (60 progs/start): 119,792,066 → 120,840,657;
    77,865,616,730 → 76,816,178,280 ns.
  - `katran` (1 hot xdp prog): 219,133,665 → 233,004,895;
    37,265,401,864 → 34,422,786,269 ns.
  - `otelcol-ebpf-profiler/profiling` (13 progs/start): 723,235 →
    723,477; 3,233,580,399 → 3,468,636,568 ns.
  - `tetragon/observer` (287 progs/start): 485,755,566 →
    552,086,889; 352,597,966,080 → 320,901,728,419 ns.
  - `tracee/monitor` (151 progs/start): 1,164,270,875 →
    1,163,045,466; 418,519,538,380 → 418,432,584,943 ns.
- Raw workload counters (per-sample, 3 samples/segment; raw values
  only, no aggregation):
  - `bcc/set` (stress-ng `--metrics-brief`): baseline cap ≈ 8.63M /
    8.67M / 8.62M, sockfd ≈ 6.48M / 6.50M / 6.48M; post_rejit cap
    ≈ 8.51M / 8.40M / 8.49M, sockfd ≈ 6.50M / 6.54M / 6.53M.
  - `cilium/agent` (kernel pktgen): pkts-sofar ≈ 20.12M / 19.77M /
    20.07M vs 20.21M / 19.94M / 20.17M; errors=0 all samples.
  - `katran` (kernel pktgen): pkts-sofar ≈ 23.96M / 24.20M / 24.15M
    vs 26.44M / 25.66M / 16.10M; errors ≈ 26.42M / 27.54M / 26.84M
    vs 26.30M / 24.91M / 15.24M (raw as reported; recorded as-is,
    not gated on — contention/noise caveat).
  - `otelcol-ebpf-profiler/profiling` (`int_loop ops=`): 493,393,552
    / 543,141,293 / 639,538,573 vs 548,755,969 / 521,043,509 /
    603,085,450.
  - `tetragon/observer` (stress-ng): baseline udp ≈ 3.18M / 3.18M /
    3.14M, sockfd ≈ 3.52M / 3.31M / 3.46M; post_rejit udp ≈ 4.71M /
    4.07M / 3.17M, sockfd ≈ 6.74M / 4.76M / 3.53M.
  - `tracee/monitor` (stress-ng): cap ≈ 1.85M / 1.85M / 1.85M vs
    1.89M / 1.79M / 1.83M; futex ≈ 4.42M / 4.64M / 4.45M vs 4.53M /
    4.46M / 4.50M.
- Host log: **0 error markers**; clean VM power-down
  (`reboot: Power down`).
- 15 trackable files under the result dir committed (`git
  check-ignore` confirms `details/shim-logs/` +
  `details/loadtime-plans/` stay gitignored via `corpus/.gitignore`
  `results/*/details/*` + negation rules): top `metadata.json`,
  `details/progress.json`, `details/result.json`, 6×
  `details/apps/*.json`, 6× `details/loadtime-reports/*.jsonl`.
- No ratio / geomean / rollup computed here (raw two-start BPF
  counters + raw per-sample workload counters only; the
  step-0051 ↔ step-0056 paired delta is analysis per
  `docs/evaluation.md` §5).
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0056-20260930T083724Z/
  make-corpus.log` (clean power-down) and `run-marker.txt`; full
  report in `step-report.md`.
- `PLATFORM=aws ARCH=arm64` within caps is **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate); resume when credentials
  land.

### KVM `make micro` full default suite (zero knobs) at `c37b6b539`,
 2026-09-30

- Plain `make micro` (default `PLATFORM=kvm`, `ARCH=x86`, zero knobs;
  `SAMPLES=3`, `WARMUPS=0`, `INNER_REPEAT=100000` defaults; no
  `BENCH` selector → full default suite
  `micro/config/micro_pure_jit.yaml`, all 29 workload-derived
  benchmarks, all 3 runtimes `native`/`llvmbpf`/`kernel`); launched
  09:29:04Z, make PID 770720, prev HEAD `c37b6b539`.
- **Purpose: canonical whole-micro-suite timing artifact** — the
  29-bench counterpart to the whole-corpus runs (0051 canonical
  `42e1c4e37` + 0056 variance `c37b6b539`). Prior micro runs in this
  session (increments 2–4, 12, 13: `BENCH=simple`,
  `bcc_runqlat_log2_histogram_bucket`, `cgroup_skb_hash_chain`,
  `packet_toeplitz_rss_hash`, `bpf_local_call_fanout_dispatch`)
  were single-bench matched-value smokes; the zero-knob full-suite
  run records raw `compile_ns`/`exec_ns`/`code_size` across all 29
  benchmarks × 3 runtimes × 3 samples.
- Run dir `micro/results/x86_kvm_micro_20260930_093345_919079/`
  (the micro suite records no run token; the dir name
  `<target>_micro_<UTC ts>_<pid-suffix>` is the run identifier);
  `details/progress.json` `status: completed`,
  `completed_benchmarks: 29 / total_benchmarks: 29`,
  `current_benchmark: null`.
- **All 29 × 3 runtimes × 3 samples = 261 samples matched** their
  `expected_result`/`expected_retval` (`result`/`retval` per
  sample); 0 mismatches; runtimes covered `native`, `llvmbpf`,
  `kernel`.
- Raw per-sample timing recorded for every bench × runtime ×
  sample: `compile_ns`, `exec_ns`, `wall_exec_ns`,
  `code_size.bpf_bytecode_bytes`/`native_code_bytes`, `phases_ns
  (memory_prepare_ns, native_load_ns)`, `timing_source:
  clock_monotonic`, `sample_index`. `details/code_compare/`: 29
  per-bench JIT-dump comparison `.md` files.
- Host log: **0 error markers**; clean VM power-down
  (`reboot: Power down`).
- 3 trackable files under the run dir committed (`git check-ignore`
  confirms `details/jit_dumps/` + `details/code_compare/` stay
  gitignored via `.gitignore` `micro/results/*/details/jit_dumps/` +
  `micro/results/*/details/code_compare/` rules,
  `!micro/results/**/*.json` negation for the .json files):
  `metadata.json`, `details/result.json`, `details/progress.json`.
- No ratio / geomean / rollup computed here (raw per-sample
  `result`/`retval`/`compile_ns`/`exec_ns`/`code_size` only;
  cross-runtime / cross-bench comparison is analysis per
  `docs/evaluation.md` §5).
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0057-20260930T092904Z/
  make-micro.log` (clean power-down) and `run-marker.txt`; full
  report in `step-report.md`.
- `PLATFORM=aws ARCH=arm64` within caps is **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate; re-checked 2026-09-30:
  no `~/.aws`, no aws-cli profiles, no matching `.pem`); resume when
  credentials land.

### QEMU arm64 `make micro` full default suite (zero knobs) at
 `840c2ed47`, 2026-09-30 (first arm64 cross-arch run on the host; local
 QEMU path — no AWS credentials needed)

- `PLATFORM=qemu ARCH=arm64 make micro` (zero knobs; `SAMPLES=3`,
  `WARMUPS=0`, `INNER_REPEAT=100000` defaults; no `BENCH` selector →
  full default suite `micro/config/micro_pure_jit.yaml`, all 29
  workload-derived benchmarks, all 3 runtimes `native`/`llvmbpf`/
  `kernel`); launched 10:05:32Z, make PID 786540, prev HEAD
  `840c2ed47`. This is the **arm64 cross-arch counterpart of the
  step-0057 KVM full-suite micro run** (`840c2ed47`).
- **Key finding: the arm64 line is NOT actually blocked on AWS
  credentials.** The local QEMU arm64 path (`micro-qemu-arm64`,
  Makefile:278–293) is a public Makefile target needing no external
  credentials; only `PLATFORM=aws ARCH=arm64` is the
  credential-blocked line. All prerequisites were present on the host
  (`qemu-system-aarch64`, arm64 kernel `Image` 42 MB, prepared
  `qemu-arm64-root/qemu-init`, 680 MB arm64 runner-runtime image tar);
  the arm64 build chain (kernel check, cilium daemon Go cross-build,
  BPF artifacts, runtime image build, Docker stage #30+) still ran as
  part of the target.
- Run dir `micro/results/arm64_qemu_micro_19700101_000008_942047/`
  (QEMU in-VM clock is 1970 — no RTC set in the VM; the dir name and
  `metadata.json` `completed_at` reflect that, not a real timestamp;
  recorded as a QEMU clock quirk, not a gate); `details/progress.json`
  `status: completed`, `completed_benchmarks: 29 /
  total_benchmarks: 29`, `current_benchmark: null`.
- **All 29 × 3 runtimes × 3 samples = 261 samples matched** their
  `expected_result`/`expected_retval` (`result`/`retval` per
  sample); 0 mismatches; runtimes covered `native`, `llvmbpf`,
  `kernel`.
- Raw per-sample timing recorded for every bench × runtime × sample:
  `compile_ns`, `exec_ns`, `wall_exec_ns`,
  `code_size.bpf_bytecode_bytes`/`native_code_bytes`, `phases_ns
  (memory_prepare_ns, native_load_ns)`, `timing_source:
  clock_monotonic`, `sample_index`. `details/code_compare/`: 29
  per-bench JIT-dump comparison `.md` files.
- Cross-arch observation (raw, no ratio computed): arm64 sample values
  differ from the x86 KVM full-suite run (0057) as expected — e.g.
  `simple` `exec last` 21/39/103 ns (x86 native/llvmbpf/kernel) vs
  arm64 `compile last` native ~6.3–8.9 ms, llvmbpf ~2.3–2.5 s, kernel
  ~65–888 µs across the 29 benches; the deterministic per-bench
  `result` values are the same expected values on both arches (the
  matched-value check is arch-independent). No ratio / geomean /
  rollup computed here — cross-arch comparison is analysis per
  `docs/evaluation.md` §5.
- QEMU exit clean: `qemu-status` = `0`; in-VM `sysrq: Power Off` +
  `reboot: Power down`; 0 real error markers (the only two `panic`
  hits in the host log are the kernel cmdline string
  `panic=30 oops=panic`, not a fault).
- 3 trackable files under the run dir committed (`git check-ignore`
  confirms `details/jit_dumps/` + `details/code_compare/` stay
  gitignored via `.gitignore` `micro/results/*/details/jit_dumps/` +
  `micro/results/*/details/code_compare/` rules,
  `!micro/results/**/*.json` negation for the .json files):
  `metadata.json`, `details/result.json`, `details/progress.json`.
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0058-20260930T100532Z/
  make-micro-arm64.log` (clean QEMU power-down, `qemu-status=0`) and
  `run-marker.txt`; full report in `step-report.md`.
- `PLATFORM=aws ARCH=arm64` (the AWS line, not the local QEMU line)
  remains **blocked on credentials**: no `codex-ec2` AWS profile and
  no `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate; re-checked 2026-09-30: no
  `~/.aws`, no aws-cli profiles, no matching `.pem`); resume when
  credentials land.

### QEMU arm64 `make corpus` full default suite (zero knobs) at
 `2201b2375`, 2026-09-30 (arm64 whole-corpus counterpart of the KVM x86
 full-corpus runs 0051/0056; local QEMU path — no AWS credentials needed)

- `PLATFORM=qemu ARCH=arm64 make corpus` (zero knobs; `SAMPLES=3`,
  `WORKLOAD_DURATION=30s`, `WARMUPS=1`, `skip_rejit=false`; full default
  suite `corpus/config/macro_apps.yaml`, all 6 apps
  `tracee`/`tetragon`/`bcc`/`katran`/`cilium`/`otelcol-ebpf-profiler`,
  arm64 pass group `full` per `corpus/config/benchmark_config.yaml
  platforms.arm64`); launched 10:56:14Z, make PID 863149, prev HEAD
  `2201b2375`. The arm64 whole-corpus counterpart of the KVM x86
  full-corpus runs 0051/0056 (`42e1c4e37`/`c37b6b539`), exercising the
  local QEMU arm64 path (`corpus-qemu-arm64`, Makefile:278–293) — no
  external credentials.
- Run dir `corpus/results/arm64_qemu_corpus_19700101_000006_146493/`
  (QEMU in-VM clock is 1970 — no RTC; `metadata.json` `completed_at:
  None`, `generated_at` 1970, `run_type: arm64_qemu_corpus` — recorded
  as a QEMU clock quirk, not a gate).
- **Suite `status: error`**; `details/progress.json` `status: error`,
  `error_message: "corpus suite reported errors"`.
- **All 6 apps `status: error`**, each with a distinct recorded error
  (none hidden/gated). Cross-arch signature: the **baseline** start of
  the two-start protocol works (shim tracks BPF programs; raw
  `run_cnt_delta`/`run_time_ns_delta` captured) for 5/6 apps, but the
  **`post_rejit_start` phase (`BPFREJIT_SHIM_LOADTIME_PLAN`) fails for
  all 6**; `details/apps/<app>.json` `post_rejit` is `null` for every
  app. This contrasts with KVM x86 0051/0056, where all 6 apps
  completed and `post_rejit` carried `run_cnt_delta`/
  `run_time_ns_delta`.
- Per-app recorded error + representative raw baseline counters (no
  ratio / geomean computed):
  - `bcc/set` → `no tracked BPF programs`. Baseline hot progs
    `sys_enter` `run_cnt_delta=2037428`, `sys_exit` `2037321`,
    `sched_switch` `869618`, `sched_wakeup` `510175`,
    `fentry_vfs_open` `86484`; 3 stress-ng `--syscall` samples rc=0,
    dur ~31–38 s.
  - `otelcol-ebpf-profiler/profiling` → `no tracked BPF programs`.
    Baseline hot `native_tracer_engine` `run_cnt_delta=259770`.
  - `cilium/agent` → `Remote end closed connection without response;
    cilium-agent output tail: …Start hook executed…`. Baseline hot
    `cil_from_container` `run_cnt_delta=4216666`/`4215728`,
    `cil_xdp_entry` `1`.
  - `katran` → `Katran server did not expose an attached XDP program on
    katran0`. Baseline hot `balancer_ingress`
    `run_cnt_delta=17595617`; 3 xdp_pktgen samples rc=0, dur ~32 s.
  - `tetragon/observer` → `Tetragon exited before BPF programs were
    tracked by shim` (`rejit_result: null`; **failed at baseline**, no
    baseline BPF data, no `loadtime-reports/tetragon__observer.jsonl`).
  - `tracee/monitor` → `failed to launch Tracee: /artifacts/tracee/bin/
    tracee --events '*' …`. Baseline hot `trace_sys_enter`
    `run_cnt_delta=1067318`, `trace_sys_exit` `1066348`,
    `tracepoint_raw_sys_enter/exit` `1067308`/`1066359`,
    `tracepoint_sched_wakeup` `226228`; 3 stress-ng `--cap` samples
    rc=0, dur ~31 s. `post_rejit: null` (post-rejit tracee launch
    failed).
- 14 trackable files under the run dir committed (`git check-ignore`
  confirms `details/shim-logs/` + `details/loadtime-plans/` stay
  gitignored): `metadata.json`, `details/progress.json`,
  `details/result.json`, 6× `details/apps/*.json`, 5×
  `details/loadtime-reports/*.jsonl` (tetragon's `.jsonl` absent —
  failed before the shim tracked programs).
- Retained log copy + run marker:
  `docs/tmp/build-and-evaluate/step-0059-20260930T105614Z/
  make-corpus-arm64.log` (clean QEMU power-down, `qemu-status=0`) and
  `run-marker.txt`; full report in `step-report.md`.
- **The all-6-app post-rejit failure on arm64 is a recorded capability
  gap** (surfaces naturally in each app's `error` field and the suite
  `status: error`; recorded additively, not hidden/gated/dropped).
  Cross-arch / cross-runtime comparison is analysis per
  `docs/evaluation.md` §5 — no ratio / geomean / rollup computed here.
- `PLATFORM=aws ARCH=arm64` (the AWS line, not the local QEMU line)
  remains **blocked on credentials**: no `codex-ec2` AWS profile and
  no `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate; re-checked 2026-09-30: no
  `~/.aws`, no aws-cli profiles, no matching `.pem`); resume when
  credentials land.

### QEMU arm64 `make corpus` determinism re-run (paired against 0059) at
 `ef51b1a98`, 2026-09-30 (arm64 whole-corpus counterpart of the KVM x86
 variance re-run 0056; answers whether 0059's all-6-apps post-rejit
 failure is deterministic or a flake)

- `PLATFORM=qemu ARCH=arm64 make corpus` (zero knobs; same default suite,
  `SAMPLES=3`, `WORKLOAD_DURATION=30s`), launched 12:01:11Z, make PID
  881657, qemu PID 894443 (up 12:06–12:47), prev HEAD `ef51b1a98`.
- Run dir `corpus/results/arm64_qemu_corpus_19700101_000006_022292/`
  (QEMU in-VM clock 1970; suite `status: error`, `error_message: "corpus
  suite reported errors"`).
- **Verdict: deterministic.** All 6 apps `status: error` with the
  **identical per-app error strings as 0059** (1:1 in
  `step-report.md`): `bcc/set` + `otelcol-ebpf-profiler/profiling`
  `no tracked BPF programs`; `cilium/agent` `Remote end closed
  connection without response`; `katran` `did not expose an attached XDP
  program on katran0`; `tetragon/observer` `exited before BPF programs
  were tracked by shim` (fails at **baseline** again — 0 workload
  samples, 0 tracked progs); `tracee/monitor` `failed to launch Tracee`.
  `post_rejit: null` for all 6 in both runs.
- Raw baseline counters re-captured this run (raw only, no
  ratio/geomean/rollup; values differ numerically from 0059 — they are
  timing-dependent — without affecting the failure-signature verdict):
  `bcc/set` `sys_enter=1934466`/`sys_exit=1934356`/`sched_switch=882145`;
  `cilium/agent` `cil_from_container=4375226`/`4370154`; `katran`
  `balancer_ingress=17192751`; `otelcol` `native_tracer_engine=322503`;
  `tracee` `tracepoint_raw_sys_enter=1055357`/`trace_sys_enter=1055289`/
  `trace_sys_exit=1054367`; `tetragon` none.
- Clean QEMU power-down, `qemu-status=0`; the make target exits 0 even
  with the suite `status: error` (0059 established this pattern — a
  recorded suite error is not a make failure). 14 trackable files
  committed; `details/shim-logs/` + `details/loadtime-plans/` stay
  gitignored (`git check-ignore` verified).
- **The arm64 post-rejit gap is now confirmed deterministic**: two full
  arm64 QEMU corpus runs (0059 + 0060), 6/6 apps, same per-app error
  strings, `post_rejit` null everywhere; KVM x86 0051/0056 all-6
  completed with `post_rejit` counters. Recorded as a cross-arch
  capability gap (record-not-patch: no framework/app/runner change, no
  exclusion lists, no re-gating); analysis per `docs/evaluation.md` §5.
- `PLATFORM=aws ARCH=arm64` (the AWS line) remains **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate; re-checked 2026-09-30: no
  `~/.aws`, no aws-cli profiles, no matching `.pem`); resume when
  credentials land.

### QEMU arm64 `make test` gate (zero knobs) at `76f47306f`, 2026-09-30
 (arm64 verification-gate counterpart of the KVM x86 `make test` suite
 0054; distinguishes a load-time-plan-specific arm64 gap from a broader one)

- `PLATFORM=qemu ARCH=arm64 make test` (zero knobs; `TEST_MODE=test`,
  `runner.suites.test` via `RUNTIME_SUITE_MODULE`, Makefile:228/233),
  launched 12:55:39Z, make PID 899323, prev HEAD `76f47306f`. The test
  gate loads the kop modules, runs the BPF-verifier negative suite
  (non-fuzz), and runs the native-proof micro staged-codegen smoke.
  `test.py:351` skips the native-loader-shim smoke on non-`x86_64`
  (aarch64 auto-skip, recorded not patched).
- Result dir `tests/results/44d305d7/` (token-based; nested run dir
  `native_proof_micro_19700101_000013_259265/`; QEMU in-VM clock 1970).
- **Gate result: PASS (5 PASS / 0 FAIL)**: BPF verifier negative smoke
  `valid_xdp_pass`, `invalid_opcode errno=22`, `stack_oob_write
  errno=13`, `uninitialized_register errno=13`; native_proof verifier
  rejection `unchecked_packet_read rejected rc=1`. 5 PASS / 0 FAIL in
  `make-test-arm64.log`.
- **Bonus: native-proof micro staged-codegen 29/29 completed**
  (`suite=micro_staged_codegen`, `manifest micro/config/micro_pure_jit.yaml`;
  `progress.json status: completed` 29/29; `result.json` `benchmarks[]`
  with `result`/`retval`/`compile_ns`/`exec_ns`, `timing_source: ktime`,
  `cpu_model: aarch64`). No ratio/geomean/rollup computed.
- **Cross-arch readout (analysis per `docs/evaluation.md` §5, not a
  gate)**: the arm64 `make test` gate passes on QEMU (aarch64) — verifier,
  kop-module load, and native-proof micro staged-codegen all work on
  aarch64. The 0059/0060 arm64 corpus failure (all 6 apps `post_rejit:
  null`, `BPFREJIT_SHIM_LOADTIME_PLAN` start fails) is therefore
  **localized to the load-time-plan / post-rejit path**, not the verifier,
  kop modules, or general test infrastructure — a sharp cross-arch
  capability-gap readout, no framework/app change.
- Clean QEMU power-down, `qemu-status=0`, make target exits 0. 32
  trackable files under the run dir committed (token + nested run dir:
  `metadata.json`, `details/progress.json`, `details/result.json`, 29×
  `details/code_compare/*.md`).
- `PLATFORM=aws ARCH=arm64` (the AWS line) remains **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate; re-checked 2026-09-30: no
  `~/.aws`, no aws-cli profiles, no matching `.pem`); resume when
  credentials land.

### QEMU arm64 `make selftest` gate (zero knobs) at `d098e6530`,
 2026-09-30 (completes the arm64 target-parity matrix; selftest mode =
 kop modules + native-proof smokes + BPF-negative suite + bpf_stats)

- `PLATFORM=qemu ARCH=arm64 make selftest` (zero knobs; `TEST_MODE=
  selftest`, `runner.suites.test`, Makefile:226/233), launched
  13:29:22Z, make PID 914605, exited 13:36:03Z, prev HEAD `d098e6530`.
  Selftest is the fullest gate mode — kop modules + native-proof micro
  smoke + native-proof negative smoke + BPF-verifier negative suite
  (non-fuzz) + `ensure_bpf_stats_enabled` (`_mode_needs_bpf_stats`,
  `test.py:487`), which `test` mode also needs but `negative` mode does
  not. The arm64 counterpart of KVM x86 selftest (increment 2 / step 0052
  lineage).
- Result dir `tests/results/3736936a/` (token-based; nested run dir
  `native_proof_micro_19700101_000013_422919/`; QEMU in-VM clock 1970).
- **Gate result: PASS (5 PASS / 0 FAIL)**: BPF verifier negative smoke
  `valid_xdp_pass`, `invalid_opcode errno=22`, `stack_oob_write
  errno=13`, `uninitialized_register errno=13`; native_proof verifier
  rejection `unchecked_packet_read rejected rc=1`. 5 PASS / 0 FAIL in
  `make-selftest-arm64.log`.
- **Bonus: native-proof micro staged-codegen 29/29 completed**
  (`suite=micro_staged_codegen`, `progress.json status: completed`
  29/29; `metadata.json status: completed`, `run_type=native_proof_micro`).
  No ratio/geomean/rollup computed.
- **Cross-arch readout (analysis per `docs/evaluation.md` §5, not a
  gate)**: the selftest mode (which re-enables bpf_stats on top of 0061's
  gate set) **passes on aarch64 QEMU**. The target-parity matrix now
  covers every KVM target on the arm64 line: micro (0058 clean), corpus
  ×2 (0059/0060 recorded failure, deterministic), test (0061 pass),
  selftest (0062 pass); only `negative-test` remains. This reaffirms the
  0061 localization that the arm64 corpus post-rejit failure is specific
  to the load-time-plan/post-rejit path — not the verifier, kop modules,
  bpf_stats, or test infrastructure. No framework/app/runner changes.
- Clean QEMU power-down, `qemu-status=0`, make target exits 0. 32
  trackable files under the run dir committed (token + nested run dir:
  `metadata.json`, `details/progress.json`, `details/result.json`, 29×
  `details/code_compare/*.md`).
- `PLATFORM=aws ARCH=arm64` (the AWS line) remains **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate; re-checked 2026-09-30: no
  `~/.aws`, no aws-cli profiles, no matching `.pem`); resume when
  credentials land.

### QEMU arm64 `make negative-test` gate (zero knobs) at `6739525f3`,
 2026-09-30 (completes the arm64 target-parity matrix; target name is
 nominal `negative` mode but the launch path actually ran the default
 `test`-mode full gate — see TEST_MODE finding below)

- `PLATFORM=qemu ARCH=arm64 make negative-test` (zero knobs; nominal
  `TEST_MODE=negative`, `runner.suites.test`, Makefile:227/233), launched
  13:43:35Z, make PID 928270, exited 13:50:23Z, prev HEAD `6739525f3`.
- Result dir `tests/results/30da2a6e/` (token-based; nested run dir
  `native_proof_micro_19700101_000013_504093/`; QEMU in-VM clock 1970).
- **Gate result: PASS (5 PASS / 0 FAIL)**: BPF verifier negative smoke
  `valid_xdp_pass`, `invalid_opcode errno=22`, `stack_oob_write
  errno=13`, `uninitialized_register errno=13`; native_proof verifier
  rejection `unchecked_packet_read rejected rc=1`. 5 PASS / 0 FAIL in
  `make-negative-test-arm64.log` (lines 17026–17034).
- **Bonus: native-proof micro staged-codegen 29/29 completed**
  (`suite=micro_staged_codegen`, `progress.json status: completed`
  29/29; `metadata.json status: completed`, `run_type=native_proof_micro`).
  No ratio/geomean/rollup computed.
- **FINDING (record-only, not patched)**: `TEST_MODE` does **not** reach
  the QEMU arm64 in-VM run. The printf-baked `/qemu-run.sh` export line
  (Makefile:235) contains `…SAMPLES='3'/FUZZ_ROUNDS='1000'/
  MERLIN_COMPILETIME_MODE='none'` but **no `TEST_MODE`** — the
  simply-expanded `RUN_MAKE_VARS` (Makefile:192–193) drops the
  target-specific `TEST_MODE ?=` (Makefile:226–228) at expansion time
  because it is still empty. In-VM `runner/suites/test.py:48`
  (`env_str("TEST_MODE","test")`) therefore falls back to the default
  `test` mode. Consequence: **0061/0062/0063 on QEMU arm64 ALL actually
  executed the same default `test`-mode full gate** (the 5-PASS shape +
  32 files + nested run dir), and the `negative`/`selftest` target names
  were nominal-only on this launch path. This corrects 0063's pre-run
  "thinnest gate (~4 PASS / ~2 files / no nested run dir)" prediction —
  actuals are 5 PASS / 32 files / nested run dir. Because the full
  `test`-mode gate is the **superset** of what `negative`/`selftest`
  modes would run, the 0061–0063 gate evidence remains valid (uniformly
  the full gate). Cross-arch check: the KVM x86 host sub-make
  (Makefile:230, `__runtime-vm-test`) **also** omits `TEST_MODE` (0
  mentions in `make -n` for all three gate targets); the in-VM
  `__runtime-vm-test` env-inheritance path (`export $(SUITE_ENV_NAMES)`,
  Makefile:183) is unconfirmed — left as a read-only open question, and
  no past KVM result is re-run or re-labeled. Launch wiring is frozen, so
  no patch is applied here; surfaced as a finding.
- **Cross-arch readout (analysis per `docs/evaluation.md` §5, not a
  gate)**: the arm64 **target-parity matrix is now 5/5 complete** on
  QEMU arm64: micro (0058 clean), corpus ×2 (0059/0060 recorded failure,
  byte-identical/deterministic), test (0061 pass), selftest (0062 pass),
  negative-test (0063 pass) — mirroring the 5 KVM x86 targets. This
  reaffirms the 0061 localization that the arm64 corpus post-rejit /
  load-time-plan failure is specific to the load-time-plan/post-rejit
  path — not the verifier, kop modules, bpf_stats, or test
  infrastructure. No framework/app/runner changes.
- Clean QEMU power-down, `qemu-status=0`, make target exits 0. 32
  trackable files under the run dir committed (token + nested run dir:
  `metadata.json`, `details/progress.json`, `details/result.json`, 29×
  `details/code_compare/*.md`).
- `PLATFORM=aws ARCH=arm64` (the AWS line) remains **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate; re-checked 2026-09-30: no
  `~/.aws`, no aws-cli profiles, no matching `.pem`); resume when
  credentials land.

### KVM x86 make selftest gate (zero knobs) at d70317d34, 2026-09-30

- Launch: `PLATFORM=kvm ARCH=x86 make selftest` (zero knobs),
  14:51:47Z, prev HEAD `d70317d34` (increment 23). Nominal
  `TEST_MODE=selftest` (Makefile:226); KVM in-VM propagation gap
  recorded in 0055 → in-VM suite ran the default `test`-mode full
  gate (superset; evidence still valid).
- Result: token `tests/results/fc73bdc4/native_proof_micro_20260930_145653_760978/`
  (32 trackable files). `metadata.json`: `status: completed`,
  progress 29/29, `run_type: native_proof_micro`. All 29
  `native_proof` benches matched
  `expected_result`/`expected_retval` (runtime `native_proof`,
  `--samples 1 --warmups 0 --inner-repeat 1` gate defaults).
- Gate PASS lines: `unchecked_packet_read rejected rc=1`,
  `valid_xdp_pass`, `invalid_opcode errno=22`,
  `stack_oob_write errno=13`, `uninitialized_register errno=13`.
  Clean `reboot: Power down`, `qemu-status=0`, 0 error markers in
  the final log.
- Provenance: in-VM `kernel_version 7.0.0-rc2+`, hostname
  `virtme-ng`, CPU "Intel(R) Core(TM) Ultra 9 285K",
  `repo_dirty: false`; host kernel `7.3.0-070300rc3-generic` —
  first KVM x86 gate evidence since the 09-30 host-kernel change.
  Decoded `virtme.exec=` confirms `TEST_MODE` absent from the
  in-VM sub-make.
- Caveats: (1) log line-count oscillation across reads (2439 →
  9949 → 504 lines, `make: Leaving directory` interleaved mid-line
  at line 35) = stderr interleaving from a concurrent make
  instance, not a result defect; (2) `tests/results/d6b6575f/negative.log`
  (14:29Z, before this launch) = a parallel/supervisor instance's
  KVM in-VM `TEST_MODE=negative` run — external WIP, not committed
  or claimed here; this step commits only its own token
  `fc73bdc4`.
- KVM x86 target-coverage now: micro/corpus/test/negative-test
  (09-30 entries) + this selftest. The arm64 5/5 target-parity
  matrix (0058–0063) is complete; KVM evidence continues under the
  user's 2026-09-30 authorization.
- `PLATFORM=aws ARCH=arm64` (the AWS line) remains **blocked on
  credentials**: no `codex-ec2` AWS profile and no
  `codex-arm64-test-20260319121631.pem` key on this host (genuine
  external blocker, not an invented gate; re-checked 2026-09-30: no
  `~/.aws`, no aws-cli profiles, no matching `.pem`); resume when
  credentials land.

### TEST_MODE propagation mechanism correction, 2026-09-30

The 0063 step report
(`docs/tmp/build-and-evaluate/step-0063-20260930T134335Z/step-report.md`,
line 42) explains the KVM in-VM `TEST_MODE` gap by saying `RUN_MAKE_VARS`
"is simply expanded at definition time with `$(foreach …)`" and that at
that point `TEST_MODE` is still empty, so the `$(if …)` guard drops it.
The *expansion type* it attributes is wrong; the *observed symptom* is
correct.

- `Makefile:193` is `RUN_MAKE_VARS = $(foreach v,$(RUN_MAKE_BASE_VAR_NAMES),…) \`
  — a **recursive `=`** (line 193 ends with `\`, continuing onto a
  tab-prefixed line 194 holding the `SUITE_ENV_NAMES` guarded half),
  **not** a `:=`. A recursive variable expands at *use* time, so the
  phrase "simply expanded at definition time" is inaccurate about the
  type of expansion. `Makefile:167` lists `TEST_MODE` in
  `SUITE_ENV_NAMES`; `Makefile:183` `export $(SUITE_ENV_NAMES)`; the
  guarded `$(if $($(v)),…)` half sits on line 194.
- The target-specific `?=` value (Makefile:226–228) is nonetheless
  empirically dropped from the in-VM sub-make, reproduced read-only
  against the **frozen** Makefile:
  - P1 `make -n PLATFORM=kvm ARCH=x86 selftest` (no command-line
    `TEST_MODE`): the captured `vng --exec … __runtime-vm-test
    $(RUN_MAKE_VARS)` arg line carries **zero** `TEST_MODE` tokens
    (`grep -c TEST_MODE` → 0; the `-e …=` token list shows
    `SAMPLES`, `FUZZ_ROUNDS`, `MERLIN_COMPILETIME_MODE` but no
    `TEST_MODE`).
  - P2 `make -n … selftest TEST_MODE=cli`: the printed sub-make line
    carries `-e TEST_MODE="cli"` (`grep -c TEST_MODE` → 1). A
    separate real (non-dry-run) launch of that target booted the KVM
    VM (`7.0.0-rc2+`) and the in-VM suite fail-fast rejected the
    value, `[test-suite][ERROR] unsupported test mode: cli` —
    confirming a command-line `TEST_MODE` reaches the in-VM suite
    end-to-end. That real run's result dir `tests/results/b29a899c/…`
    is kept untracked.
  - `runner/suites/test.py:48` reads `args.test_mode =
    env_str("TEST_MODE","test")`, so with the target-specific value
    dropped the in-VM suite falls back to the `test`-mode default.
    This is why the 0064 gate (`fc73bdc4`) ran the `test`-mode full
    gate rather than the nominal `selftest`; its `metadata.json`
    independently confirms `TEST_MODE` absent from the sub-make args.
- The asymmetry (target-specific `?=` value dropped, command-line
  value propagated) is the recorded launch-wiring behavior. With a
  recursive `=`, target-specific variables are normally in scope at
  recipe-expansion time, so the drop is *not* explained by
  expansion-type; this correction records the observed fact and does
  not assert an unverified internal mechanism.
- Disposition: **record-only**. The launch wiring and benchmark
  Makefile are frozen, so no Makefile patch. The 0063 wording is
  corrected forward by this note, not by rewriting the 0063
  entry/report.
- AWS line: `PLATFORM=aws ARCH=arm64` remains **blocked on
  credentials** (re-checked 2026-09-30: no `~/.aws`, no aws-cli
  profiles, no matching `.pem`); resume when credentials land.

### const_mod_reduce* policy-YAML stale-prefix follow-up closed, 2026-09-30
- **Change (increment 26):** `runner/config/passes/const_mod_reduce/default.yaml:10`
  and `..._branchless_rejected/default.yaml:10` — replaced the stale
  `/home/yunwei37/workspace/bpf-benchmark/` prefix on the host-prepared
  artifact path with `${BPFREJIT_REPO_ROOT:?BPFREJIT_REPO_ROOT is required}`
  (parity with the already-committed `map_inline/katran.yaml:51`). `BPFREJIT_REPO_ROOT`
  is a runner-injected env var, not a shim constant (no shim reference).
- **Host-sim proof (pre-VM):** ran the fixed command block against the 09-25
  captured input blob (`loadtime_3078_5/input.step.0.bin`, sha256=`1d8367af…`)
  with `BPFREJIT_REPO_ROOT="$PWD"` → rc=0, output sha256=`1929357b…`, valid JSON
  report (`sites_applied=2`, `insn_delta=14`). Negative case: `BPFREJIT_REPO_ROOT`
  unset → rc=1 fail-fast. The `.bin` artifacts (`..._branchless_mod65537.bin` and
  `..._branchless_rejected/...`) are byte-identical 20448 B, sha256=`1929357b`=expected_output_sha.
- **In-VM proof (step 0065):** isolated `make corpus BPFREJIT_CORPUS_APPS=katran
  BPFREJIT_BENCH_PASSES=const_mod_reduce SAMPLES=1 WORKLOAD_DURATION=10` (RUN_TOKEN
  `corpus/results/x86_kvm_corpus_20260930_171858_652950`). The built plan
  `details/loadtime-plans/katran.json` step[0].command carries the
  `${BPFREJIT_REPO_ROOT:?...}` prefix (stale `/home/yunwei37` gone) and
  `loadtime_plan_done status: "ok"` — the path fix is validated in-VM.
- **Isolated-run outcome (record-only, not clean evidence):** baseline completed
  (`balancer_ingres` type=xdp id=9, `bytes_jited=13641`/`bytes_xlated=23840`);
  `post_rejit: null`, app `status: "error"` — katran SIGABRTs during startup.
  Root cause is **structural, not build-stale**: the loadtime plan builder emits a
  single *global* step with no program targeting, and the `const_mod_reduce` step is
  a hard input-hash gate (`set -eu; … !=1d8367af…; exit 1`). It therefore fires on
  libbpf's trivial `insn_cnt=2` probe loads → shim `BPF_PROG_LOAD` returns `EINVAL`
  → `bpf_object__probe_loading(): -EINVAL` → katran `can't load main bpf program`
  → SIGABRT **before** `balancer_ingres` loads. NOT build-stale: 09-30 baseline
  `balancer_ingres` bytecode `0325eddd…/13641/23840` is byte-identical to 09-25, and
  the gate's `expected_input_sha=1d8367af` still matches the 09-25 captured target.
  05-14 worked because that mode was **per-program** rejit (`enabled_passes:
  ['noop','const_mod_reduce']`, `rejit_result.mode: None`, only prog 9 gated) so the
  probes were not gated; the loadtime global path is a loadtime-mode-specific finding.
  09-25 `map_inline` handled the same probes gracefully (`produced no bytecode
  changes; passing original BPF_PROG_LOAD through`) → clean two-start.
- **Disposition:** **record-only.** No re-run (deterministically reproduces the same
  abort); no new gate/skip-on-mismatch logic (would invent a validity gate + change
  the pass's fail-fast contract). No framework/app/runner change; no
  ratio/geomean/rollup. Run dir kept untracked (raw abort, not clean evidence).

### KVM x86 `make corpus` default policy (zero knobs) completed 6/6 at 8d4626452, 2026-09-30
- **Command**: `make corpus` zero-knob (`PLATFORM=kvm ARCH=x86` defaults; `SAMPLES=3`, `WORKLOAD_DURATION=30`; full x86 pass chain `noop,map_inline,const_prop,dce,wide_mem,bounds_check_merge,skb_load_bytes_spec,noop,const_prop,dce,kop`; 6 apps), at `8d4626452`.
- **Result**: `corpus/results/x86_kvm_corpus_20260930_193317_347907/` — **completed, 6/6 apps `ok` with `post_rejit` present, all `rejit_result: ok` (loadtime mode)**; `metadata.json`/`result.json`/`progress.json` = `completed`/`ok`/`completed` (`completed_at 20:07:27Z`); clean `reboot: Power down` (in-VM t≈2091.9s ≈ 35 min; `7.0.0-rc2+`, `virtme-ng`, 8 cpus / 64 GiB).
- **Per-app raw counters (post `run_cnt_delta`; no ratios here — analysis per `docs/evaluation.md` §5)**: bcc/set `sys_exit` 552,276,514; cilium/agent `cil_from_contai` 60,003,594; katran `balancer_ingres` 234,540,480 (jit 11778 / xlat 19392 B); otelcol `native_tracer_e` 722,726; tetragon `generic_tracepo` 239,664,899; tracee `trace_sys_exit` 244,714,905.
- **Determinism pairing** vs 0051 (`x86_kvm_corpus_20260930_053929_108492`) and 0056 (`x86_kvm_corpus_20260930_084230_227783`), same-prog post `run_cnt_delta`: bcc 552.3M/553.4M/552.1M; cilium 60.0M/61.3M/60.5M; katran 234.5M/231.9M/233.0M; otelcol 722.7K/722.7K/723.4K; tetragon 239.7M/237.1M/240.2M; tracee 244.7M/243.1M/243.0M — same order of magnitude, sub-percent to low-single-percent spread across the three same-tree runs (raw triplets only; tracee prog named `trace_sys_exit` in 0066 vs `tracepoint__raw` in 0051/0056, same magnitude — recorded caveat).
- **Launch-lifecycle finding (recorded, not patched)**: attempts 1–3 (18:20:30/18:30:14/19:14:10Z, session-owned async jobs) were all SIGTERMed at session disposal by OMP's `cancelAndReapOwnerJobs` (`qemu-system-x86_64: terminating on signal 15 from pid …(omp)`; attempt 2 reached 5/6 apps before reaping; attempt 3 was 0 apps). Attempt 4 launched **detached** (`setsid nohup make corpus … & < /dev/null`; new session/pgid, reparents to init) so the reaper can't reach it → survived three duty-poll session restarts and completed. The frozen `make` target path / launch wiring was **not** modified; only the process lifecycle was detached. No new validity gate added.
- **Disposition**: clean 6/6 completed KVM x86 default-policy two-start benchmark at `8d4626452` (valid evidence, not record-only). Committed the trackable JSON subset (6 `details/apps/*.json` + 6 `loadtime-reports/*.jsonl` + `result.json` + `progress.json` + `metadata.json` + step report + this entry) per the 0051 precedent (`42e1c4e37`); `shim-logs/`/`loadtime-plans/` stay gitignored.
- **AWS arm64 re-check (read-only, 2026-09-30)**: still blocked — no `~/.aws`, no `codex-arm64-test-20260319121631.pem` (or any arm64 key) on host, no `AWS_*` creds; Makefile knobs wired (`AWS_ARM64_*` → `t4g.micro`/`t4g.small`, us-east-1, profile `codex-ec2`). Launching = spending money + missing key → external blocker, resume when credentials land.

### Duty close-out: local Make-backed KVM/QEMU evidence chain saturated; AWS blocked on credentials; Paper-B blocked on clean-source image rebuild, 2026-09-30
- **Local KVM x86 + QEMU arm64 Make target matrix is saturated** at this tree (`e9b1f735f`), default policy / zero knobs: all five targets — `make selftest`, `make test`, `make negative-test`, `make micro`, `make corpus` — have completed on both local platforms (`PLATFORM=kvm` x86 and QEMU full-system arm64). KVM x86 default-policy `make corpus` is now a clean 6/6 (step 0066, `corpus/results/x86_kvm_corpus_20260930_193317_347907/`). **No local `make <target>` remains unrun at default policy in this duty chain.**
- **AWS platform (both arches) is externally blocked on credentials** (read-only re-check 2026-09-30): no `~/.aws`, no `AWS_*` credential env, and the key file both `AWS_X86_KEY_PATH` (Makefile:110) and `AWS_ARM64_KEY_PATH` (Makefile:124) resolve to `/home/yunwei37/.ssh/codex-arm64-test-20260319121631.pem` is absent on this host. The Makefile knobs are wired correctly (`AWS_X86_*` → `t3.micro`/`t3.small`, `AWS_ARM64_*` → `t4g.micro`/`t4g.small`, region `us-east-1`, profile `codex-ec2`); launching = spending money + missing key → **blocked on credentials**, report-only, resume when credentials land. (Recorded, not a blocker to the local line: `AWS_X86_KEY_PATH` reuses the arm64 key filename — minor wiring inconsistency, not a blocker.)
- **Paper-B speculative-optimization KVM evidence (a `KEEP_WORKDIRS=1` artifact-capture run) remains blocked** on a clean-source runtime-image rebuild: the current x86 runtime image (built in the 09-30 ~19:32 chain, `.cache/container-images/x86_64-runner-runtime.image.tar`) was built from the **uncommitted, AE-supervisor-owned** generic LLVM-roundtrip change in `bpfopt/llvm/src/llvm_mapinline.hpp` (+3 lines: `create_bpf_target_machine(Aggressive)` + `promote_register_allocas` in `run_llvm_roundtrip`). That is not an authorized change in this duty chain, so speculative paper evidence stays pending until it is superseded by a clean-source image rebuild (external / separate ownership; not actioned here).
- **Disposition**: no further authorized local `make` step remains. The KVM x86 + QEMU arm64 Make-backed two-start benchmark evidence chain is complete and committed. The only outstanding items are external (AWS credentials) and the Paper-B clean-source image rebuild (separate ownership). Nothing further is locally runnable.

### Disk sweep: untracked evidence-tree provenance resolved; no orphan (record-only, 2026-09-30)

A full untracked-file sweep surfaced two families of completed result
trees that are **untracked but not orphans** — each is deliberately
untracked, so no evidence from this duty chain is missing from git.
Every gate token this chain claims was re-verified tracked on disk.

- **`corpus/results/arm64_qemu_corpus_19700101_000012_467359/`**
  (step 0012, arm64 QEMU katran single-app `map_inline`,
  `KEEP_WORKDIRS=1`) is **not an orphan**. Step 0012's shipped
  commit `66261fe12` registered the evidence under the canonical
  package `docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode/`
  (14 files tracked in HEAD; its `receipt.json` binds the raw run
  dir). The raw `corpus/results/…/467359/` dir stays untracked as
  `KEEP_WORKDIRS=1` scratch (raw `loadtime-workdirs/`, `shim-logs/`,
  `make-corpus.log`); the canonical package is the tracked evidence.
  Deliberate, not a gap.
- **8 untracked `tests/results/<8hex>/native_proof_micro_20260930_*/`
  trees** (32-file shape each; `metadata.status: completed`,
  progress 29/29, `host: virtme-ng`, kernel `7.0.0-rc2+`):
  - `b29a899c` (`native_proof_micro_20260930_155936_606137`) —
    **explicitly kept untracked** by step 0064: the `TEST_MODE=cli`
    real-run mechanism probe whose in-VM suite fail-fast rejected
    the value (`[test-suite][ERROR] unsupported test mode: cli`).
    A mechanism finding, not gate evidence.
  - The other 7 — `bf2d759f`, `c51b46d7`, `cfd08584`, `d1f2d8be`,
    `d7a7a31b`, `ddda2554`, `ee13e166` — have **zero references** in
    the research log, any `docs/tmp/build-and-evaluate/step-*/`
    receipt, or the `docs/` tree. They are external / supervisor-
    parallel KVM runs, in the same category as
    `tests/results/d6b6575f/negative.log` (0063 caveat: a
    parallel/supervisor instance's KVM in-VM run — external WIP, not
    committed or claimed here). **Left untracked; not claimed by
    this chain.** No commit.
- **Claimed-evidence audit (the load-bearing check that no claimed
  result was missed):** every gate token this duty chain claims is
  tracked on disk —
  - KVM x86 test-family × 3: `tests/results/d83499ef/` (0054 test),
    `4dca07ca/` (0055 negative-test), `fc73bdc4/` (0064 selftest) —
    32 tracked files each.
  - QEMU arm64 test-family × 3: `tests/results/44d305d7/` (0061
    test), `3736936a/` (0062 selftest), `30da2a6e/` (0063
    negative-test) — 32 tracked files each.
  - KVM x86 default-policy corpus (0066):
    `corpus/results/x86_kvm_corpus_20260930_193317_347907/` — 15
    tracked JSON.
  - QEMU arm64 micro (0058):
    `micro/results/arm64_qemu_micro_19700101_000008_942047/` — 3
    tracked files.
  - QEMU arm64 corpus (0059/0060, recorded deterministic failure):
    `corpus/results/arm64_qemu_corpus_19700101_000006_146493/` +
    `_022292/` — 14 tracked files each.
  - arm64 katran `map_inline` evidence package (step 0012,
    `66261fe12`):
    `docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode/`
    — 14 tracked files.
  **No orphan: every claimed result is committed.**
- **Live-state re-check (read-only, 2026-09-30):** HEAD =
  `origin/master` = `c3dc5007f` (0/0); the same 13 WIP ` M` files
  remain unstaged; `bpfopt/llvm/src/llvm_mapinline.hpp` still ` M`
  (Paper-B clean-source image rebuild still blocked); no new step dir
  past `step-0066`; AWS still blocked on credentials (no `~/.aws`,
  no `AWS_*` env, no `codex-arm64-test-…pem`); KVM operational
  (`/dev/kvm`, `qemu-system-*`, `/opt/virtme-ng/bin/vng`).
- **Disposition: record-only.** No evidence tree is committed — the
  arm64 `467359` dir is intentional `KEEP_WORKDIRS` scratch; the 7
  unclaimed 0930 test trees are external WIP; `b29a899c` is a
  recorded mechanism probe. No new `make <target>` run, no new
  validity gate. The chain remains at the fixed point recorded in the
  0066 close-out entry above: only the external items (AWS
  credentials, Paper-B clean-source image rebuild) remain.

### Disk sweep correction: complete untracked-tree inventory; prior sweep was truncated (record-only, 2026-09-30)

The "no orphan" entry above was based on a sweep cut by `head -40`,
which missed three families of untracked result trees. This is the
forward-only correction. **No external condition flipped this cycle**
(read-only re-check): HEAD = `origin/master` = `b2a29ab82` (0/0); the
same 13 WIP ` M` files remain unstaged; `bpfopt/llvm/src/llvm_mapinline.hpp`
still ` M` (Paper-B clean-source image rebuild still blocked); AWS still
blocked (no `~/.aws`, no `AWS_*` env, no `codex-arm64-test-…pem`); no new
step dir past `step-0066`; KVM operational (`/dev/kvm` writable,
`/opt/virtme-ng/bin/vng` present). Nothing is running
(`pgrep -c -f run_target_suite` = 0). No new `make <target>` run, no new
validity gate.

- **Method correction (the load-bearing fix):** the ground-truth
  check is **per-top-token `git ls-files -- <token-dir>/ | wc -l`
  (count > 0 = tracked)**, *not* a per-file classifier. The earlier
  classifier mis-labeled the six 09-30 KVM single-app trees as
  "untracked" when `git ls-files` shows them **5/5 tracked**:
  `corpus/results/x86_kvm_corpus_20260930_{004629_965759(katran),
  013937_924928(bcc/set),031929_336215,035320_255208,043516_570740,
  050405_991692}/` each track `metadata.json`, `details/result.json`,
  `details/progress.json`, `details/apps/<app>.json`,
  `details/loadtime-reports/<app>.jsonl`; only gitignored
  `shim-logs/` + `loadtime-plans/` scratch stays untracked. The
  research-log sections that say "Tracked summary files added to git"
  for these six are **correct**. Not open.

- **`corpus/results/x86_kvm_corpus_20260930_{171858_652950(status=error),
  183425_011210(status=running,5/6,reaped~19:03Z),
  192224_050834(status=running,0 apps,reaped~19:23Z)}/`** are
  **deliberately kept-untracked**, documented in the `step-0065` /
  `step-0066` receipts (a raw SIGABRT abort plus two
  OMP-supervisor-reaped partial attempts — the reaping-hazard
  failure mode). Nothing running now; trees are ~3h stale.
  **Not open** (resolved by receipt; record-only).

- **The 09-16→09-26 x86 KVM corpus tail (68 fully-untracked trees;
  day counts 0916=8, 0918=4, 0919=4, 0920=1, 0921=2, 0922=1, 0923=1,
  0924=1, 0925=10, 0926=36, plus the 3× 0930 above = 71 total) is
  legitimate untracked scratch, not a claimed-vs-disk bug.** Decisive
  checks: `git log --all --oneline -- <token>/` = **0 commits** for
  every full token (never tracked on any branch). The research log and
  `docs/implementation.md` cite these as **execution provenance**
  ("exits 0 and writes `corpus/results/…/` with suite
  `status: completed`"), *not* as "committed to git" — the 60-line
  "tracked"-in-window hits were prose false-positives ("tracked by
  shim", "gitignored build artifact"). The asymmetry with the tracked
  `corpus/results/x86_kvm_corpus_20260916_031856_977978/` (4 tracked
  files, also cited in `implementation.md`) is simply that that one
  was separately committed; both are provenance citations. **Left
  untracked; not claimed as committed; no commit.**

- **NEW (the 8 families the truncated sweep never inventoried) — all
  external/supervisor-parallel KVM WIP, record-only, no commit:**
  - **7× `tests/results/{04653888,1b786105,27701e23,45ef4b1a,
    7af33003,8487eb21,91832227}/native_proof_micro_20260930_*/`** —
    32-file shape each; `metadata.status: completed`, progress 29/29,
    `host: virtme-ng`. **Zero references** in the research log, any
    `docs/tmp/build-and-evaluate/step-*/` receipt, or the `docs/`
    tree. Same category as the "other 7" above (`bf2d759f` …
    `ee13e166`) — external/supervisor-parallel KVM runs; not
    committed or claimed here.
  - **`micro/results/x86_kvm_micro_20260924_223349_704509/`** —
    **100% untracked** (0 tracked files; 7 on disk: `metadata.json`,
    `details/result.json`, `details/progress.json`,
    `details/code_compare/simple.md`, 3×
    `details/jit_dumps/simple__*__sample00.{jitted,xlated}.bin`),
    `status: completed` progress 1/1, `host: virtme-ng`, zero
    research-log refs. The ATC26-claimed sibling
    `micro/results/x86_kvm_micro_20260924_231824_136293/` is
    tracked; this one is not. Left untracked; not claimed; no commit.

- **Re-confirmed (no change):** `tests/results/62ce5f12/` (09-29,
  `step-0041` "kept untracked"), `tests/results/b29a899c/` (0064
  `TEST_MODE=cli` mechanism probe), `tests/results/d6b6575f/` + the 7
  above — external/supervisor KVM WIP.

- **Corrected full untracked inventory (per-top-token `git ls-files`):**
  `corpus/results` = 72 fully-untracked top dirs = 1× arm64 QEMU
  `467359` (intentional `KEEP_WORKDIRS` scratch, canonical package
  committed under `docs/artifacts/evidence/rq2-katran-arm64-map-inline-retained-bytecode/`)
  + 68× 09-16→09-26 x86 KVM scratch + 3× 09-30 reaped/aborted;
  `micro/results` = 1 (the 09-24 KVM micro above); `tests/results` =
  17 (`62ce5f12`, `b29a899c`, `d6b6575f` + the 7 handoff-listed
  `bf2d759f…ee13e166` + the 7 new zero-ref KVM trees). **No claimed
  result is missing from git; the "no orphan" conclusion still holds —
  the correction is that the prior sweep undercounted untracked
  *scratch/external* families, not that it missed a committed result.**

- **Disposition: record-only.** The two external blockers (AWS
  credentials; Paper-B clean-source image rebuild) remain the sole
  outstanding *run* items. This entry only corrects the truncated
  inventory; it commits nothing new. The chain stays at the fixed
  point recorded in the 0066 close-out entry above.

### Untracked build/packaging artifact families: no claimed evidence; record-only (2026-09-30)

The untracked sweep this cycle re-listed the `corpus/`, `micro/`,
`tests/` result roots: every family is already inventoried (no new
result tree). The three families the log's "corrected full untracked
inventory" (entry above, scoped to the three result roots) did not
list are **build/packaging artifacts, not evidence trees**:

- **`vendor/bpf/targets/x86/7.0.0-rc2+/` (untracked, `vmlinux.h`)** —
  the framework-kernel CO-RE binding key under `host-native-bpf-x86`
  (`make -C vendor/bpf … native-artifacts` regenerates it; the 09-30
  mtime 17:16:08 matches the KVM chain's build step). Documented in
  this log (~line 3666) and `docs/implementation.md` §273–281 as an
  intended build output; kept untracked, consistent with all other
  build outputs. No commit.
- **`vendor/bpf/targets/x86/7.3.0-070300rc3-generic/` (untracked,
  `vmlinux.h`, mtime 09-19)** — host-kernel BTF leftover from the
  host-native-BPF experiment; the host 7.3.0 BTF lacks
  `struct mm_struct::user_ns`, which is why tetragon breaks against
  it (`implementation.md` §273–281). Not used by any Make target.
  Left untracked; not claimed.
- **`vendor/bpf/targets/arm64/7.3.0-070300rc3-generic/` (untracked,
  `vmlinux.h`)** — same host-kernel-release key generated on this
  host while building arm64 native BPF; a build byproduct, never a
  claimed result. Left untracked; not claimed.
- **`docs/artifacts/dist/atc26-ae-2.zip` + `.sha256` (untracked,
  mtime 09-26)** — the ATC26 artifact-2 package; the *packaging
  receipts* are tracked and documented (`docs/artifacts/package-atc26.sh`,
  `docs/atc26-artifact-evaluation.md`, step-0011/0020–0034 step
  reports). The dist zip is a binary packaging artifact, not
  benchmark evidence; kept untracked. No commit.

- **Re-verification (read-only):** corrected gate-token inventory —
  clean-pathspec `git ls-files` confirms **252 tracked evidence files
  across the 11 gate tokens, 0 mismatches** (the prior cycle's
  `0/32` was a script bug, not a signal); all 6 KVM single-app trees
  `5/5`; the untracked result-root families match the documented
  inventory exactly. **No orphan; no claimed evidence missing from
  git.**
- **Live-state re-check:** HEAD = `origin/master` = `0d25bbdc5`;
  the same 13 WIP ` M` files remain unstaged;
  `bpfopt/llvm/src/llvm_mapinline.hpp` still ` M` (Paper-B
  clean-source image rebuild still blocked); AWS still blocked (no
  `~/.aws`, no `AWS_*` env, no key file); no step dir past
  `step-0066`; KVM operational; nothing running.
- **Disposition: record-only.** This entry only closes the
  build/packaging-artifact inventory gap; it commits nothing new and
  invents no run or gate. The two external blockers (AWS credentials;
  Paper-B clean-source image rebuild) remain the sole outstanding
  *run* items. The chain stays at the fixed point recorded in the
  0066 close-out entry above.

### Filled the BR suite-geomean cell: cross-run pool of 148 retained programs (2026-10-01)

Prior cycles anchored the chain's "fixed point" to the two external *run*
blockers (AWS credentials; Paper-B clean-source image rebuild) and never
audited the doc's own open cells. This cycle found a genuine local
analysis-layer increment: `docs/evaluation.md` §6.2.1 had the
All-bytecode-rewriting row's `suite` cell as `*pending*` while all seven
per-app cells + `retained=148` were filled. That cell is sanctioned
post-hoc analysis over on-disk raw `result.json` counters — no new run,
validity gate, framework change, or AWS/Paper-B.

- **Cell filled:** `docs/evaluation.md` line 452 `*pending*` → `0.8917`.
  One provenance line added below the table: the row pools two on-disk
  runs because no single 7-app run exercised this exact 6-pass set.
- **Source trees (both S=3, status=completed, strict-BR pass set
  `{noop, wide_mem, const_prop, dce, bounds_check_merge,
  skb_load_bytes_spec}`):**
  `corpus/results/x86_kvm_corpus_20260508_202653_157003` (6 apps,
  retained=67: bcc 20, bpftrace 8, cilium 6, katran 1, otel 2,
  tetragon 30) +
  `corpus/results/x86_kvm_corpus_20260508_210422_770525` (tracee only,
  retained=81). 67 + 81 = 148 = the doc's `retained` column.
- **Method:** the sanctioned `analysis/corpus_analyze.py` (per-program
  ratio `p_avg/b_avg`, retain `min(b_runs,p_runs) ≥ 100`, `pair_by=id`,
  `applied_only=False`); the suite cell is the per-program geomean over
  the union of all 148 retained programs. Every per-app cell matches the
  doc exactly (bcc 1.0659, bpftrace 1.0155, cilium 0.9813, katran
  0.9807, otel 0.4713, tetragon 1.0064, tracee 0.8115). The pooled 0.8917
  sits beside the sibling suite cells (noop 0.9019, 6-pass kop 0.9009)
  and is < 1.0, consistent with the §6.2.1 Findings; no Findings edit
  was needed.
- **Live-state re-check:** HEAD = `origin/master` = `44728a93c`; the
  same 13 WIP ` M` files remain unstaged (none touched);
  `bpfopt/llvm/src/llvm_mapinline.hpp` still ` M` (Paper-B
  clean-source image rebuild still blocked); AWS still blocked (no
  `~/.aws`, no `AWS_*` env, no key file); no step dir past
  `step-0066`; KVM operational; nothing running.
- **Disposition:** scoped doc edit committed to `docs/evaluation.md`
  only, plus this forward-only log entry. This broke the "fixed point"
  framing by surfacing a local analysis cell, not by inventing a run or
  gate. The two external blockers (AWS credentials; Paper-B
  clean-source image rebuild) remain the sole outstanding *run* items.

### Named `br` pass-group KVM x86 `make corpus` 6/6 completed at 6aa33210e (2026-10-01)

- **Run:** `make corpus BPFREJIT_BENCH_PASSES="br"` (S=3, 30 s, all 6
  apps; `br` = `[noop, wide_mem, const_prop, dce, bounds_check_merge,
  skb_load_bytes_spec]`), detached via `setsid nohup` from the start.
  Result token `corpus/results/x86_kvm_corpus_20261001_011124_022384/`,
  prev HEAD `6aa33210e`, `CORPUS_EXIT=0`, clean power-down, zero
  reaping lines.
- **Why this step:** steps 0042–0066 were all zero-knob default
  `full-x86`; no KVM step had ever selected a named group. This is the
  first KVM run exercising a group token, re-deriving the §6.2.1
  `br` conclusion at the current tree.
- **Raw outcome:** 6/6 `ok` with `post_rejit`, including tetragon
  without a `VMLINUX_BTF` override (KVM in-VM build uses framework
  kernel BTF, not the host `7.3.0-070300rc3` BTF). `metadata.json`
  `config.enabled_passes` confirms the exact `br` expansion.
- **Sanctioned analysis:** `corpus_analyze.py --pair-by id` (default)
  retains 0 on current two-start in-VM trees (kernel reassigns
  `bpf_prog` ids per start; the 0066 tree behaves identically — a
  property of this tree generation, not of the pass group).
  `--pair-by name-type` retains 72, per-program geomean **0.9669**
  (41W/31L; tetragon 0.8782, cilium 0.9205 best). Same <1.0 direction
  as the §6.2.1 pooled `0.8917` (148-retained historical 2026-05-08
  pool), on a different retained population (no bpftrace in the
  current 6-app corpus). No doc cell overwritten; the historical row
  remains the paper record.
- **Provenance:** gate tokens re-verified 252 across 11 (0
  mismatch); untracked sweep 93 result dirs in documented families;
  `6aa33210e` confirmed in HEAD. Step report:
  `docs/tmp/build-and-evaluate/step-0067-20261001T010526Z/step-report.md`.
- **Disposition:** scoped commit = 15 structured result-tree files +
  step report + this entry. No framework/app/runner/Makefile change,
  no new gate. Remaining *run* blockers unchanged: AWS credentials;
  Paper-B clean-source image rebuild (`llvm_mapinline.hpp` still ` M`).

### Named `kop-6` KOP-class pass-group KVM x86 `make corpus` 6/6 completed at 830195d59 (2026-10-01)

- **Run:** `make corpus BPFREJIT_BENCH_PASSES="kop-6"` (S=3, 30 s, all 6
  apps; `kop-6` = `[cond_select, bulk_memory, rotate, extract,
  endian_fusion, prefetch]`), detached via `setsid nohup`. Result token
  `corpus/results/x86_kvm_corpus_20261001_025602_885812/`, prev HEAD
  `830195d59` (the step-0067 `br` commit), `CORPUS_EXIT=0`, clean
  power-down, zero reaping lines.
- **Why this step:** 0067 closed the `br` bytecode-rewriting group at the
  current tree. The KOP-class named groups (`kop`, `kop-5`, `kop-6`)
  were noted out of scope in 0067, but that over-read
  `docs/evaluation.md` §1: KOP is a KOperation-*paper* deliverable,
  while AGENTS.md's "Current pass list" explicitly includes the kop-class
  as a measured pass in this framework. The KOP groups are therefore
  in-scope framework pass space, and re-deriving the §6.2.1 KOP rows
  (`5-pass kop` 0.9074, `6-pass kop + prefetch` 0.9009, both historical
  2026-05-08) at the current tree is a genuine useful step. This is the
  first KVM step exercising a KOP-class named group.
- **Raw outcome:** 6/6 `ok` with `post_rejit`; KOP module load `status:
  ok` with all 15 expected in-VM KOP modules loaded. KOP-site
  application (from `details/loadtime-reports/*.jsonl`) is non-zero on
  every app: tracee 7320, tetragon 2416, cilium 1455, otelcol 519,
  katran 50, bcc 14 sites matched/applied.
- **Sanctioned analysis:** `corpus_analyze.py --pair-by id` retains 0
  (tree-generation property, as in 0066/0067). `--pair-by name-type`
  retains 72, per-program geomean **0.9802** (39W/33L; per-app cilium
  0.9026, tetragon 0.9269, katran 0.9676, tracee 0.9920, bcc 1.0334,
  otelcol 1.0880). The analyzer's `applied` column is structurally 0 in
  this tree generation (its source
  `result.json→results[].rejit_result.per_program` is empty; the current
  driver writes per-app payloads to `details/apps/*.json` with an empty
  `rejit_result.per_program`), but KOP-site application is genuinely
  non-zero via loadtime-reports — so 0.9802 measures real KOP
  kfunc-lowering + phase variance, unlike 0067 `br`'s pure relift.
  No doc cell overwritten; the §6.2.1 KOP rows remain the paper record.
- **Determinism:** rep-prog baseline-side `run_cnt_delta` within sub-
  percent across the kop-6 / br-0067 / 0066 three trees (e.g.
  katran `balancer_ingres` 221,552,336 / 220,263,922 / 222,602,879) —
  baseline counters remain pass-independent.
- **Provenance:** step report:
  `docs/tmp/build-and-evaluate/step-0068-20261001T025112Z/step-report.md`.
- **Disposition:** scoped commit = 15 structured result-tree files +
  step report + this entry. No framework/app/runner/Makefile change,
  no new gate. Remaining *run* blockers unchanged: AWS credentials;
  Paper-B clean-source image rebuild (`llvm_mapinline.hpp` still ` M`).

### Named `kop-5` KOP-class pass-group KVM x86 `make corpus` 6/6 completed at c0da1d785 (2026-10-01)

- **Run:** `make corpus BPFREJIT_BENCH_PASSES="kop-5"` (S=3, 30 s, all 6
  apps; `kop-5` = `[cond_select, bulk_memory, rotate, extract,
  endian_fusion]` = `kop-6` minus `prefetch`), detached via `setsid nohup`.
  Result token `corpus/results/x86_kvm_corpus_20261001_040643_284761/`,
  prev HEAD `c0da1d785` (the step-0068 `kop-6` commit), `CORPUS_EXIT=0`,
  clean power-down, zero reaping lines.
- **Why this step:** the KOP-group ablation follow-on. 0068 exercised
  `kop-6` (KOP family **with** `prefetch`); dropping `prefetch` isolates its
  effect on the KOP-group geomean and completes the §6.2.1 KOP-group
  ablation pair (`kop-5` / `kop-6`) at the current tree.
- **Raw outcome:** 6/6 `ok` with `post_rejit` (progs b/p: bcc 25/25,
  cilium 53/53, katran 1/1, otelcol 13/13, tetragon 287/287, tracee
  151/151). KOP module load `status: ok` with all 15 expected in-VM KOP
  modules. KOP-site application (loadtime-reports JSONL) non-zero on every
  app: tracee 6172, tetragon 1989, cilium 800, otelcol 200, katran 44,
  bcc 11 — all ≤ the `kop-6` per-app values, delta = `prefetch`.
- **Sanctioned analysis:** `corpus_analyze.py --pair-by id` retains 0
  (tree-generation property, as in 0066–0068). `--pair-by name-type`
  retains 72, with the retained (app, name, type) multiset **identical** to
  0068 `kop-6` (all 72 keys present in both), per-program geomean
  **0.9855** (39W/33L; per-app cilium 0.9061, tetragon 0.9212, katran
  0.9749, tracee 1.0056, bcc 1.0352, otelcol 1.1155). Ablation delta
  `kop-6` − `kop-5` = `0.9802 − 0.9855 = −0.0053`: removing `prefetch`
  slightly **worsens** the geomean, so `prefetch` is a small net-positive
  contributor to the KOP pass-group on this corpus. The analyzer's
  `applied` column is structurally 0 in this tree generation (empty
  `result.json → results[].rejit_result.per_program`), so KOP-site
  application is read from loadtime-reports only — same condition as
  0067/0068. No doc cell overwritten; the §6.2.1 KOP rows remain the paper
  record.
- **Determinism:** rep-prog baseline-side `run_cnt_delta` within sub-
  percent across the kop-5 / kop-6 / 0066 three trees (e.g. katran
  `balancer_ingres` 222,443,576 / 221,552,336 / 222,602,879; tracee
  `trace_sys_exit` 240,945,205 / 241,631,272 / 242,894,771) — baseline
  counters remain pass-independent.
- **Provenance:** step report:
  `docs/tmp/build-and-evaluate/step-0069-20261001T040152Z/step-report.md`.
- **Disposition:** scoped commit = 15 structured result-tree files +
  step report + this entry. No framework/app/runner/Makefile change,
  no new gate. Remaining *run* blockers unchanged: AWS credentials;
  Paper-B clean-source image rebuild (`llvm_mapinline.hpp` still ` M`).

### Single `kop` KOP-class pass KVM x86 `make corpus` 6/6 completed at d8483f22e (2026-10-01)

- **Run:** `make corpus BPFREJIT_BENCH_PASSES="kop"` (S=3, 30 s, all 6
  apps; `kop` = `[kop]`, the single KOP-kfunc-lowering pass with the full
  KOP-op lowering list), detached via `setsid nohup`. Result token
  `corpus/results/x86_kvm_corpus_20261001_050956_828597/`, prev HEAD
  `d8483f22e` (the step-0069 `kop-5` commit), `CORPUS_EXIT=0`, clean
  power-down, zero reaping lines.
- **Why this step:** the KOP-family anchor. 0068/0069 exercised the
  KOP-*family* sub-pass groups (`kop-6` with `prefetch`, `kop-5`
  without). This exercises the canonical single `kop` pass. Together the
  three form the §6.2.1 "KOP-class" ablation at the current tree:
  single `kop` → `kop-5` → `kop-6`.
- **Raw outcome:** 6/6 `ok` with `post_rejit` (progs b/p: bcc 25/25,
  cilium 62/53, katran 1/1, otelcol 13/13, tetragon 287/287, tracee
  151/151). KOP module load `status: ok` with all 15 expected in-VM KOP
  modules. KOP-site application (loadtime-reports JSONL;
  `sites_matched == sites_applied`) — the single `kop` pass is the
  **broadest** KOP lowering: tracee 7507, tetragon 2988, cilium 2988,
  otelcol 1532, bcc 84, katran 70 (Σ ≈ 15,169), vs `kop-6` family Σ
  ≈ 11,774 and `kop-5` family Σ ≈ 9,216. The single pass lowers the full
  KOP-op list; the family sub-passes lower a transform-category subset.
- **Sanctioned analysis:** `corpus_analyze.py --pair-by id` retains 0
  (tree-generation property, as in 0066–0069). `--pair-by name-type`
  retains 72, with the same retained (app, name, type) multiset as
  0068/0069 (all 72 keys in all three KOP trees), per-program geomean
  **0.9932** (36W/36L; CV 50.4%). KOP-family geomean ladder: `kop`
  0.9932 → `kop-5` 0.9855 → `kop-6` 0.9802; the single `kop` pass is the
  strongest KOP group on this corpus and has the lowest per-program ratio
  CV, because it lowers more KOP op kinds. The analyzer's `applied`
  column is structurally 0 in this tree generation (empty
  `result.json → results[].rejit_result.per_program`), so KOP-site
  application is read from loadtime-reports only — same condition as
  0067–0069. No doc cell overwritten; the §6.2.1 KOP rows remain the
  paper record.
- **Determinism:** rep-prog baseline-side `run_cnt_delta` within sub-
  percent across the kop / kop-5 / 0066 three trees (e.g. katran
  `balancer_ingres` 223,534,877 / 222,443,576 / 222,602,879; tracee
  `trace_sys_exit` 240,100,882 / 240,945,205 / 242,894,771) — baseline
  counters remain pass-independent.
- **Provenance:** step report:
  `docs/tmp/build-and-evaluate/step-0070-20261001T050506Z/step-report.md`.
- **Disposition:** scoped commit = 15 structured result-tree files +
  step report + this entry. No framework/app/runner/Makefile change,
  no new gate. Remaining in-scope KVM Make-backed runs: refresh the
  stale KVM `make micro` layer (last KVM micro tree = 09-30 09:33,
  older than the KVM corpus trees); individual KOP-family named passes
  if per-pass resolution is wanted. Remaining *run* blockers unchanged:
  AWS credentials; Paper-B clean-source image rebuild
  (`llvm_mapinline.hpp` still ` M`).

### KVM x86 `make micro` full-suite refresh (29 benches, 3 runtimes) at b3d899262 (2026-10-01)

- **Run:** `make micro SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000`
  (default `micro/config/micro_pure_jit.yaml` suite; empty `BENCH` = all 29
  benches; runtimes `native/llvmbpf/kernel`; default `RUNTIMES` = those
  three, no KOP-module load), detached via `setsid nohup`. Result token
  `micro/results/x86_kvm_micro_20261001_061549_699286/`, prev HEAD
  `b3d899262` (the step-0070 `kop` commit), `MICRO_EXIT=0`, clean S5
  power-down, zero reaping lines.
- **Why this step:** the KVM micro measurement layer had not been
  refreshed since the 09-30 09:33 tree (`x86_kvm_micro_20260930_093345_919079`)
  while the KVM corpus layer advanced through 0066–0070. This step brings
  the KVM micro layer to the current tree generation so both KVM layers
  share a tree generation.
- **Raw outcome:** 29/29 benchmarks completed, runtimes `native`/`llvmbpf`/
  `kernel` (29 each), all 261 samples (29 × 3 × 3) match the suite's
  declared `expected_result`/`expected_retval` (261 ok, 0 bad).
- **Cross-check vs the 09-30 tree:** the pure-jit layer is structurally
  unchanged. `bpf_bytecode_bytes` median-per-bench sum is identical
  (55,872 in both trees, delta +0) — the JIT input did not change between
  the two tree generations. Per-bench median `exec_ns` new/old geomeans:
  kernel ×1.0014, llvmbpf ×1.0330, native ×0.9369 — all within
  host-JIT run-to-run variance for a pure-jit suite (no codegen
  regression). JIT codegen medians: llvmbpf 13.19 ms ≫ kernel 2.29 ms ≫
  native 0.048 ms (expected ordering).
- **Provenance:** host `virtme-ng`, `repo_dirty: False`,
  `cpu_model Intel(R) Core(TM) Ultra 9 285K`; in-VM VM records
  `repo_git_sha`/`kernel_commit` as `unknown` by design; tree tied to
  launch's prev HEAD `b3d899262`.
- **Provenance (step dir):**
  `docs/tmp/build-and-evaluate/step-0071-20261001T061059Z/step-report.md`.
- **Disposition:** scoped commit = 3 structured result-tree files
  (`metadata.json` + `details/result.json` + `details/progress.json`) +
  step report + this entry (5 files, per the step-0057 KVM make-micro
  precedent). The `details/code_compare/*.md` (29) and
  `details/jit_dumps/*.bin` are not committed. No framework/app/runner/
  Makefile change, no new gate. Remaining *run* blockers unchanged: AWS
  credentials; Paper-B clean-source image rebuild
  (`llvm_mapinline.hpp` still ` M`). Remaining in-scope KVM Make-backed
  runs: individual KOP-family named passes if per-pass resolution is
  wanted; QEMU arm64 `make micro`/`corpus` for non-KVM evidence.
