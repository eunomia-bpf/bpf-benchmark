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
