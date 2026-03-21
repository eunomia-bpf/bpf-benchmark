# BpfReJIT v1 任务追踪记录（#1 - #303）

> 这是 v1 架构（native-level JIT rewrite, ~6400 LOC kernel）的历史任务记录。
> v1 代码保存在 `v1-native-rewrite` 分支，内核代码在 `jit-directive-v5` 分支。
> v2 架构（Dynamic, Extensible Compilation Framework）从 #304 开始，见主 plan doc。
> 此文件仅供历史参考，不再更新。

| # | 任务 | 状态 | 关键数据 / 文档 |
|---|------|:---:|------|
| 1 | v3 JIT pass 框架设计 | ✅ | 8/10。`docs/tmp/2026-03-09/jit-pass-framework-v3-design.md`，`docs/tmp/2026-03-09/jit-pass-framework-v3-final-verdict.md` |
| 2 | v4 Post-load re-JIT 设计 | ✅ | `docs/tmp/2026-03-09/jit-pass-framework-v4-design.md` |
| 3 | v5 声明式 Pattern 设计 | ✅ | 7.5/10。`docs/tmp/2026-03-09/jit-pass-framework-v5-design.md`，`docs/tmp/2026-03-09/jit-pass-framework-v5-review.md` |
| 4 | v7 Hybrid 设计 | ✅ | `docs/tmp/2026-03-08/bpf-jit-advisor-v7.md`，`docs/tmp/2026-03-08/bpf-jit-advisor-v7-review.md` |
| 5 | Interface 设计 | ✅ | 6/10。`docs/tmp/2026-03-08/interface-design-detail.md`，`docs/tmp/2026-03-08/interface-design-review.md` |
| 6 | Verifier-rewrite 分析 | ✅ | JIT lowering 为主。`docs/tmp/2026-03-08/verifier-rewrite-approach.md` |
| 7 | Policy decision layer | ✅ | 3 级策略。`docs/tmp/2026-03-10/policy-decision-layer-design.md` |
| 8 | Directive 发现 | ✅ | 11 候选。`docs/tmp/2026-03-08/directive-discovery-analysis.md` |
| 9 | OSDI readiness | ✅ | 4/10。`docs/tmp/2026-03-08/osdi-readiness-review.md` |
| 10 | 跨文档交叉验证 | ✅ | `docs/tmp/2026-03-08/cross-document-review.md` |
| 11 | POC v1: wide_load verifier rewrite | ⚠️ 方向错误 | `docs/tmp/2026-03-09/poc-design-review.md` |
| 12 | POC v2: cmov_select JIT lowering | ✅ | jited 4168→4167。`docs/tmp/2026-03-09/poc-v2-design-conformance-review.md` |
| 13 | v4 POC（4 directives） | ✅ | ~850 LOC kernel。branch `jit-directive-v4` |
| 14 | v4 bug 修复 | ✅ | `docs/tmp/2026-03-09/v4-bug-diagnosis.md` |
| 15 | v4 review | ✅ | 6/10。`docs/tmp/2026-03-09/v4-implementation-review.md` |
| 16 | v4 Round 1 | ✅ | ADDR_CALC -12%，COND_SELECT log2_fold **+28%**（policy-sensitivity）。`docs/tmp/2026-03-09/v4-round1-test-results.md` |
| 17 | v4 Round 2: WIDE_MEM | ✅ | load_byte_recompose **-13%**。`docs/tmp/2026-03-09/v4-round2-test-results.md`，`docs/tmp/2026-03-09/v4-round2-implementation.md` |
| 18 | v4 Round 3: ROTATE | ✅ | rotate64_hash **-28.4%**。composability 验证。`docs/tmp/2026-03-09/v4-round3-test-results.md` |
| 19 | Fixed baselines 设计 | ✅ | `docs/tmp/2026-03-10/kernel-fixed-baselines-design.md` |
| 20 | Fixed baselines 测试 | ✅ | CMOV 必须 policy-controlled。`docs/tmp/2026-03-10/kernel-fixed-baselines-test-results.md` |
| 21 | Per-directive 隔离测试 | ✅ | `docs/tmp/2026-03-10/kernel-fixed-baselines-per-directive.md` |
| 22 | v5 POC | ✅ | v5=v4 功能等价。`docs/tmp/2026-03-10/v5-minimal-poc-results.md` |
| 23 | v5 迭代 | ✅ | `docs/tmp/2026-03-10/v5-iteration-results.md` |
| 24 | v5 canonical binding | ✅ | v4 1018 LOC vs v5 32 LOC (32x)。`docs/tmp/2026-03-10/v5-canonical-binding-results.md`，`docs/tmp/2026-03-10/extensibility-quantification.md` |
| 25 | Scanner 独立化 | ✅ | `docs/tmp/2026-03-10/scanner-cleanup-results.md` |
| 26 | v5 gap analysis | ✅ | 6.5/10。`docs/tmp/2026-03-10/v5-design-gap-analysis.md` |
| 27 | Framework review | ✅ | 4/10。`docs/tmp/2026-03-10/framework-architecture-review.md` |
| 28 | cmov subprog fix | ⚠️ | emitter bug 见 #47。`docs/tmp/2026-03-10/cmov-subprog-fix-results.md` |
| 29 | Pure-JIT audit | ✅ | `docs/tmp/2026-03-08/pure-jit-benchmark-audit.md` |
| 30 | Host 重跑 | ✅ | pure-jit L/K=**0.797x**。`micro/results/pure_jit_with_cmov.json` |
| 31 | VM 重跑 | ✅ | VM/host parity。`docs/tmp/2026-03-08/vm-rerun-analysis.md` |
| 32 | Directive census | ✅ | 67/98 有 sites，1029 总 sites。`docs/tmp/2026-03-11/real-program-directive-census.md` |
| 33 | Corpus v5 recompile | ✅ | 37/40 apply。`docs/tmp/2026-03-10/corpus-v5-recompile-results.md` |
| 34 | Production corpus | ✅ | Cilium/Katran/xdp-tools。`docs/tmp/2026-03-10/production-program-compilation.md` |
| 35 | Production recompile | ✅ | 15/15 成功。`docs/tmp/2026-03-10/production-corpus-v5-rerun-results.md` |
| 36 | Corpus 扩充 R2 | ✅ | 529 总 .bpf.o（22 项目）。`docs/tmp/2026-03-10/corpus-expansion-round2.md` |
| 37 | Scanner rotate fix | ✅ | `docs/tmp/2026-03-10/scanner-gap-fix.md` |
| 38 | 严格 benchmark | ✅ | CMOV **0.655x**, ROTATE **1.193x**。`docs/tmp/2026-03-10/rigorous-benchmark-results.md` |
| 39 | 微架构实验 | ✅ | PMU/频率/输入分布。`docs/tmp/2026-03-08/microarch_experiments.md` |
| 40 | ARM64 CI | ✅ | 3 轮修复。 |
| 41 | ARM64 分析 | ✅ | L/K=**0.656x**。`docs/tmp/2026-03-08/arm64-cross-arch-analysis.md`，`docs/tmp/2026-03-11/arm64-analysis-review.md` |
| 42 | EINVAL debug | ✅ | production EINVAL 修复。 |
| 43 | Benchmark 审计 | ✅ | `docs/tmp/2026-03-11/benchmark-infrastructure-audit.md` |
| 44 | Benchmark 分析 | ✅ | `docs/tmp/2026-03-10/benchmark-framework-analysis.md` |
| 45 | 论文 LaTeX | 🔄 | R3 6.5/10。`docs/paper/paper.tex`，`docs/tmp/2026-03-10/paper-review-r3-post-rewrite.md` |
| 46 | COND_SELECT v5 | ✅ | `docs/tmp/2026-03-10/cmov-v5-migration-report.md` |
| 47 | cmov emitter fix | ✅ | site index 修复。`docs/tmp/2026-03-10/cmov-emitter-fix-report.md` |
| 48 | Benchmark 重构 | 🔄 | P0 5/5 完成。`docs/tmp/2026-03-10/p0-bugfix-report.md` |
| 49 | 端到端部署 | 已取消 | |
| 50 | 论文更新 | 已取消 | |
| 51 | log_level/log_buf | ✅ | `docs/tmp/2026-03-11/v6-tier1-implementation.md` |
| 52 | Shape whitelist | ✅ | site_len≤64。`docs/tmp/2026-03-11/v6-tier1-implementation.md` |
| 53 | Overlap 语义 | ❌ | 未实现。 |
| 54 | Subprog 一致性 | ❌ | 未同步。 |
| 55 | K2/Merlin/EPSO 对比 | ✅ | **正交非替代**，backend gap 89.1%。`docs/tmp/2026-03-11/k2-merlin-epso-comparison.md` |
| 56 | RCU 安全分析 | ✅ | `docs/tmp/2026-03-11/rejit-rcu-safety-analysis.md` |
| 57 | 消融补全 | ❌ | |
| 58 | ZERO_EXTEND | ❌ | |
| 59 | ARM64 backend | ❌ | |
| 60 | 严格重跑 30×1000 | ✅ | 56/56 pass。`micro/results/pure_jit_authoritative_strict_20260312.json` |
| 61 | Benchmark 多样性 | 🟡 | 67 micro + 79 corpus paired。`docs/tmp/2026-03-11/benchmark-diversity-audit.md` |
| 62 | CMOV 信号增强 | ❌ | 仅 2.8% 改善。 |
| 63 | E2E throughput | 已取消 | 随 #49。 |
| 64 | Corpus 可运行性 | ✅ | 381 runnable / 3069 sites。`docs/tmp/2026-03-11/corpus-runnability-report.md` |
| 65 | Corpus 批量 recompile | ✅ | geomean **0.847x**。`docs/tmp/2026-03-11/corpus-batch-recompile-results.md`，`docs/tmp/2026-03-11/corpus-recompile-regression-analysis.md` |
| 66 | 非网络 E2E 研究 | ✅ | Tracee+Tetragon+bpftrace+scx。`docs/tmp/2026-03-11/non-networking-evaluation-plan.md` |
| 67 | Framework 重构 Step 1-3 | ✅ | 共享 Python 层。`docs/tmp/2026-03-11/framework-improvement-step1.md` |
| 68 | Corpus 扩展 R3 | ✅ | 560 objects（23 项目）。`docs/tmp/2026-03-11/corpus-expansion-round3.md` |
| 69 | Selective CMOV policy | ✅ | global skip-cmov 不足。`docs/tmp/2026-03-11/selective-policy-results.md` |
| 70 | bpftrace E2E driver | ✅ | 9 CMOV sites。`docs/tmp/2026-03-11/bpftrace-e2e-results.md` |
| 70a | Tetragon harness | ✅ | `docs/tmp/2026-03-11/tetragon-e2e-results.md` |
| 70b | BPF-side VM 测试 | ✅ | Tracee **2.71x**。`docs/tmp/2026-03-11/tracee-e2e-vm-summary.md`，`docs/tmp/2026-03-11/bpftrace-e2e-vm-summary.md`，`docs/tmp/2026-03-11/tetragon-e2e-vm-summary.md` |
| 70c | Framework 重构 Steps 2-7 | ✅ | `micro/driver.py` 统一入口。`docs/tmp/2026-03-11/framework-improvement-steps2-7.md` |
| 71 | 仓库三层重组 | ✅ | micro/corpus/e2e 分离。`docs/tmp/2026-03-11/repo-restructure-report.md` |
| 72 | Tracee E2E | ✅ | exec_storm **+21.65%**。`docs/tmp/2026-03-11/tracee-real-e2e-report.md`，`e2e/results/tracee-e2e-real.json` |
| 73 | Kernel 重编 | ✅ | FTRACE_SYSCALLS+SCHED_CLASS_EXT。`docs/tmp/2026-03-11/kernel-rebuild-report.md` |
| 74 | Tetragon E2E | ✅ | stress_exec **+6.7%**，BPF **-14.5%**。`e2e/results/tetragon-real-e2e.json` |
| 75 | bpftrace E2E | ✅ | geomean **0.992x**（policy-sensitivity）。`docs/tmp/2026-03-12/bpftrace-real-e2e-report.md`，`e2e/results/bpftrace-real-e2e.json` |
| 77 | Directive gap 分析 | ✅ | CMOV 应为 policy-sensitivity 证据。`docs/tmp/2026-03-11/directive-gap-analysis.md` |
| 78 | cmov 识别加宽 | ✅ | `docs/tmp/2026-03-11/cmov-broadening-report.md` |
| 79 | bitfield_extract | ✅ | **544 sites / 41 objects**。`docs/tmp/2026-03-11/bitfield-extract-implementation.md` |
| 80 | wide_load 扩展 | ✅ | **2835 sites**。`docs/tmp/2026-03-11/wide-load-extension-report.md` |
| 81 | branch_reorder | 归入 #89 | BRANCH_FLIP 简单版。 |
| 82 | bounds_window | ❌ | 未实现。 |
| 83 | Kernel JIT 清理 | ✅ | 零偏移+imm64 优化。`docs/tmp/2026-03-11/kernel-jit-cleanup-patches.md` |
| 84 | Interface v6 提案 | ✅ | `docs/tmp/2026-03-11/interface-design-audit.md`，`docs/tmp/2026-03-11/interface-improvement-proposals.md` |
| 85 | v4 删除 | ✅ | -778 LOC。 |
| 86 | v6 tier-1 | ✅ | `docs/tmp/2026-03-11/v6-tier1-implementation.md` |
| 87 | v6 接口研究 | ✅ | verifier log 足够 discovery。`docs/tmp/2026-03-11/v6-interface-design.md` |
| 88 | Framework audit v2 | ✅ | `docs/tmp/2026-03-11/benchmark-framework-audit-v2.md` |
| 89 | 新 forms (ZEXT/ENDIAN/BFLIP) | ✅ | 3 form 落地。`docs/tmp/2026-03-11/new-canonical-forms-implementation.md` |
| 90 | Corpus 全量 v6 | ✅ | geomean **0.868x**，92 applied。`docs/tmp/2026-03-11/corpus-full-recompile-v6.md` |
| 91 | 优化方向研究 | ✅ | Top 3 方向。`docs/tmp/2026-03-11/optimization-beyond-isel.md` |
| 92 | 8-family census | ✅ | 17637 total sites，zeroext=0。`docs/tmp/2026-03-11/corpus-8families-census-persection.md` |
| 93 | Micro 精简 | ✅ | 56-case pure-jit only。 |
| 94 | Micro input 去 map | ✅ | packet buffer 传入。 |
| 95 | Tracing corpus driver | ✅ | attach+trigger 测量。 |
| 96 | Corpus 整理 | ✅ | |
| 97 | Policy 配置设计 | ✅ | 统一 YAML schema + 5 阶段 auto-tuning。`docs/tmp/2026-03-11/policy-configuration-design.md` |
| 99 | Micro Python 整理 | ✅ | 归档+共享 helper。 |
| 99a | Micro cleanup follow-up | ✅ | |
| 98 | Policy v2 设计 | ✅ | 程序无关 auto-tuning。`docs/tmp/2026-03-12/policy-configuration-design-v2.md` |
| 98a | Policy P0+P1 | ✅ | 8-family surface + scanner compile-policy。 |
| 98b | P2 Micro policy | ✅ | manifest-driven policy plumbing。 |
| 98e | P3 Corpus policy | ✅ | per-program policy files。 |
| 98c | Tracing corpus VM | ✅ | 473 ready / 315 attached。`docs/tmp/2026-03-11/tracing-corpus-vm-full-results.md` |
| 98d | Code-size systematic | ✅ | `docs/tmp/2026-03-11/code-size-by-progtype.md` |
| 98f | P4 Auto-tuner | ✅ | prototype landed。`corpus/auto_tune.py` |
| 100 | Micro 回归修复 | ✅ | 56/56 pass。`micro/results/pure_jit_authoritative_20260312.json` |
| 101 | Corpus driver dedup | ✅ | -385 行。 |
| 102 | Inventory audit | ✅ | `docs/tmp/2026-03-11/benchmark-inventory-audit.md` |
| 103 | Policy pipeline | ✅ | `docs/tmp/2026-03-11/policy-pipeline-analysis.md` |
| 104 | Corpus tuned policy | ✅ | geomean 0.868x→**0.898x**。`docs/tmp/2026-03-11/corpus-tuned-policy-comparison.md` |
| 105 | E2E policy 接线 | ✅ | per-program policy lookup。 |
| 106 | 结果目录规范 | ✅ | authoritative naming + symlinks。 |
| 107 | Code-size VM | ✅ | geomean **1.003x**。`docs/tmp/2026-03-11/code-size-full-vm-results.md` |
| 108 | Tracing corpus VM | ✅ | applied-only **1.019x**。`docs/tmp/2026-03-11/tracing-corpus-vm-full-results.md` |
| 109 | scx EINVAL | ✅ | extable guard 修复。`docs/tmp/2026-03-11/struct-ops-recompile-investigation.md` |
| 110 | llvmbpf map inline POC | ✅ | **1.30x** speedup。`docs/tmp/2026-03-11/llvmbpf-array-map-inline-poc.md` |
| 111 | XDP forwarding PPS | ✅（已退役） | +0.27%，见 #203。 |
| 112 | Strict micro 30×1000 | ✅ | geomean **0.609x**，53/56 wins。`docs/tmp/2026-03-11/sub-ktime-and-strict-analysis.md` |
| 113 | Policy <1.0x 分析 | ✅ | non-CMOV families 回归。`docs/tmp/2026-03-11/policy-improvement-analysis.md` |
| 114 | Policy v2 格式 | ✅ | site > family > default 优先级。 |
| 115 | Strict 分析 | ✅ | 归入 #112。 |
| 116 | bflip/endian sweep | ✅ | bflip+endian:skip **0.857x**。`docs/tmp/2026-03-11/bflip-endian-skip-sweep.md` |
| 117 | scx EINVAL 调查 | ✅ | 归入 #109。`docs/tmp/2026-03-11/struct-ops-recompile-investigation.md` |
| 118 | Recompile micro strict | ✅ | overall **1.028x**，applied **1.024x**。`docs/tmp/2026-03-11/kernel-recompile-micro-strict.md` |
| 119 | XDP forwarding VM | ✅（已退役） | +0.27%，见 #203。`docs/tmp/2026-03-11/xdp-forwarding-live-vm-report.md` |
| 120 | Corpus v2 policy rerun | ✅ | **0.848x**（pre-fix baseline）。`docs/tmp/2026-03-11/corpus-v2-policy-rerun.md` |
| 121 | E2E v2 policy rerun | ✅ | wiring 验证，site 漂移导致 0 apply。`docs/tmp/2026-03-11/e2e-v2-policy-rerun.md` |
| 122 | v2 pipeline 迁移 | ✅ | scanner v2-only。`docs/tmp/2026-03-11/v2-pipeline-migration-report.md` |
| 123 | Per-family 消融 | ✅ | wide **1.010x**, rotate **1.021x**, cmov **0.974x**。`docs/tmp/2026-03-11/kernel-recompile-per-family-ablation.md` |
| 124 | 论文审计 | 已取消 | |
| 125 | Gap 分解 | ✅ | recovery **4.3%** of gap。`docs/tmp/2026-03-11/characterization-gap-decomposition.md` |
| 126 | Micro v2 tuned rerun | ✅ | applied-only **1.040x**。`docs/tmp/2026-03-11/kernel-recompile-micro-v2-tuned.md` |
| 128 | Corpus v2 policy fix | ✅ | site 漂移修复，0.758x→**1.055x**（13-target smoke）。`docs/tmp/2026-03-12/corpus-v2-policy-diagnosis.md` |
| 129 | Micro mismatch fix | ✅ | cmov site 触发 wrong-code。源级修复见 #138。`docs/tmp/2026-03-12/micro-mismatch-crash-diagnosis.md` |
| 127 | 阶段性 review | ✅ | 4 critical 不一致。`docs/tmp/2026-03-12/stage-review-report.md` |
| 130 | 默认语义修正 | ✅ | no-policy → stock。 |
| 131 | Inline policy v1→v2 | ✅ | policy_file 引用替换 inline。 |
| 132 | v2 spec 文档 | ✅ | `docs/tmp/2026-03-12/policy-v2-authoritative-spec.md` |
| 133 | Corpus v2 fixed rerun | ✅ | **0.875x**（91 applied）。`docs/tmp/2026-03-12/corpus-v2-fixed-rerun.md` |
| 134 | E2E v2 fixed rerun | ✅ | cmov skip 过滤生效。`docs/tmp/2026-03-12/e2e-v2-fixed-rerun.md` |
| 135 | Parser 一致性测试 | ✅ | golden tests。`docs/tmp/2026-03-12/parser-consistency-fix.md` |
| 136 | Plan doc 修正 | ✅ | 过时条目描述回写。 |
| 137 | bpftrace policy artifacts | ✅ | 12 cmov sites。`docs/tmp/2026-03-12/bpftrace-policy-artifacts.md` |
| 138 | CMOV/EXTRACT fix | ✅ | emitter fail-close + BEXTR ModRM 修正。`docs/tmp/2026-03-12/cmov-emitter-fix.md` |
| 139 | Micro authoritative | ✅ | 56/56 valid，applied-only **1.049x**。`docs/tmp/2026-03-12/kernel-recompile-micro-v2-fixed-authoritative.md` |
| 140 | Tetragon 回归调查 | ✅ | workload 噪声。`docs/tmp/2026-03-12/tetragon-connect-storm-investigation.md` |
| 141 | Per-family v1→v2 | ✅ | 8 policy 升级。 |
| 142 | v1 清理 | ✅ 被 #145 取代 | v2 纯化，后续切 v3。 |
| 143 | Post-fix micro rerun | ✅ | 11/56 applied，**1.007x**。`docs/tmp/2026-03-12/post-cmov-fix-micro-rerun.md` |
| 144 | CMOV 消融 | ✅ | CMOV 仍负面，保留 cmov:skip。`docs/tmp/2026-03-12/post-cmov-fix-corpus-ablation.md` |
| 145 | v3 policy | ✅ | per-site directive list，614 YAML 通过。 |
| 146 | Recompile 开销 | ✅ | scanner **4.32ms**，syscall **29.89μs**。`docs/tmp/2026-03-12/recompile-overhead-measurement.md` |
| 147 | bpftrace v3 validation | ✅ | `docs/tmp/2026-03-12/bpftrace-e2e-v3-validation.md` |
| 148 | 架构 Review + 图 | ✅ | `docs/tmp/2026-03-12/architecture-review-and-diagrams.md` |
| 149 | Canonical-site hardening | ✅ | 8 form 双重校验。 |
| 150 | Kernel cleanup | ✅ | RORX bug 等修复。`docs/tmp/2026-03-12/kernel-engineering-cleanup.md` |
| 151 | Kernel self-tests | ✅ | 18/18 PASS。`docs/tmp/2026-03-12/kernel-selftest-run.md` |
| 152 | Kernel safety fixes | ✅ | smp_store_release + RCU 等。`docs/tmp/2026-03-12/kernel-safety-fixes.md` |
| 153 | JIT image diff | ✅ | **re-JIT 改 non-site 字节**（code layout shift）。zero-site 短路已修。`docs/tmp/2026-03-12/jit-image-diff-analysis.md` |
| 154 | Per-form benchmark | ✅ | +6 纯隔离 benchmark。`docs/tmp/2026-03-12/per-form-benchmarks-implementation.md` |
| 155 | Corpus regressor root cause | ✅ | 3/10 真实回归（branch-flip）。`docs/tmp/2026-03-12/corpus-regressor-root-cause.md` |
| 156 | Measurement fix | ✅ | dual TSC + warmup。`docs/tmp/2026-03-12/kernel-runner-measurement-fixes.md` |
| 157 | Framework audit v3 | ✅ | corpus construct validity 问题。`docs/tmp/2026-03-12/benchmark-framework-audit-v3.md` |
| 158 | Post-cleanup 验证 | 🔄 | 62/62 micro valid。`docs/tmp/2026-03-12/post-cleanup-validation.md` |
| 159 | Root Makefile | ✅ | 一键 build+test。`docs/tmp/2026-03-12/root-makefile-report.md` |
| 160 | Post-fix micro 62 bench | ✅ | applied-only **0.877x**。`docs/tmp/2026-03-12/post-fix-micro-62bench-rerun.md` |
| 161 | Scanner pattern_kind fix | ✅ | `docs/tmp/2026-03-12/scanner-pattern-kind-investigation.md` |
| 162 | Corpus validity 分析 | ✅ | corpus exec **无效**（噪声主导），code size 有效。`docs/tmp/2026-03-12/corpus-construct-validity-analysis.md` |
| 163 | Scanner enumerate | ✅ | live program 分析，197 progs / 1920 sites。`docs/tmp/2026-03-12/scanner-enumerate-implementation.md` |
| 164 | E2E 切 enumerate | ✅ | `docs/tmp/2026-03-13/e2e-enumerate-pipeline-switch.md` |
| 165 | 消融补全 | ✅ | byte-recompose **50.7%**，callee-saved ~0%，BMI ~0%。`docs/tmp/2026-03-13/ablation-byte-recompose-callee-bmi.md` |
| 166 | Per-form 矛盾调查 | ✅ | emitter bug 导致零变化。`docs/tmp/2026-03-13/per-form-discrepancy-investigation.md` |
| 167 | Emitter 修复 | ✅ | BEXTR VEX 修正，extract_dense -6.8%。`docs/tmp/2026-03-13/emitter-fix-extract-endian-bflip.md` |
| 168 | endian/bflip 回归 | ✅ | same-size I-cache flush 开销 > 微架构收益。`docs/tmp/2026-03-13/endian-bflip-perf-investigation.md` |
| 170 | Enumerate manifest | ✅ | --json per-site 输出。 |
| 171 | Daemon 模式 | ❌ 暂不做 | 论文不需要。 |
| 172 | Native code 分析 | ❌ | jited_prog_insns 未用。 |
| 173 | Corpus 切 enumerate | ✅ | |
| 76 | scx E2E | 🔄 | 28 sites，struct_ops -EOPNOTSUPP。`docs/tmp/2026-03-11/scx-e2e-report.md`，`docs/tmp/2026-03-11/struct-ops-recompile-investigation.md` |
| 169 | Post-BEXTR rerun | ✅ | overall **1.003x**，applied **0.932x**。extract_dense **0.556x** 回归。`docs/tmp/active/micro-62bench-post-bextr-fix.md`，`micro/results/micro_62bench_post_bextr_fix_20260313.json` |
| 174 | Patch-site 架构 | ❌ | 消除 I-cache flush 开销。 |
| 175 | WIDE_MEM 扩展 | ❌ | byte-recompose 50.7%。 |
| 176 | Prologue 优化 | ❌ | 占 gap 18.5%。 |
| 177 | Cost model | ❌ | 跳过 same-size/dense 超阈值。 |
| 178 | 更多 E2E 数据 | ❌ | 目标 ≥3 workload 正向。 |
| 179 | Per-form ablation | ✅ | ROTATE **0.923x** win，CMOV **1.068x** loss。`docs/tmp/micro-per-form-ablation.md` |
| 180 | 框架重构 Makefile | ✅ | file-based deps + provenance + POLICY=。 |
| 181 | CI 修复 | ✅ | driver.py + requirements.txt。 |
| 182 | Opus review | ✅ | 架构✅，方法学有 gap。`docs/tmp/deep-review-*.md` |
| 183 | P0.1 更多 E2E | 🔄 已被 #304 搁置 | Tracee +6.28%/+7.00%。 |
| 184 | P0.2 Corpus >1.05x | 🔄 已被 #304 搁置 | 当前 1.046x。 |
| 185-188 | P1 优化方向 | ❌ 已被 #304 搁置 | prologue / patch-site / wide 扩展 / native 分析。 |
| 189 | Micro policy 优化 | ✅ | applied-only **1.110x**（7 applied）。`micro/results/vm_micro_authoritative_20260318.json` |
| 190 | 结果目录 + schema | ✅ | authoritative naming，policy 内嵌。 |
| 191 | Corpus+E2E 分析 | ✅ | stale policy 是主因。`docs/tmp/corpus_e2e_performance_analysis_20260318.md` |
| 192 | Katran E2E 可行性 | ✅ | 94 live sites。`docs/tmp/katran_e2e_feasibility_20260318.md` |
| 193 | Corpus policy refresh | ✅ | 582 个 v3 policy，skip cmov+extract。 |
| 194 | 项目卫生审计 | ✅ | `docs/tmp/project_hygiene_audit_20260318.md` |
| 195 | 内核修改文档 | ✅ | 1017 行。`docs/tmp/kernel_modifications_analysis.md` |
| 196 | Framework 设计文档 | ✅ | 800+ 行。`docs/tmp/benchmark_framework_analysis.md` |
| 197 | Micro 第三轮 | ✅ 归入 #189 | |
| 198 | prog_fd 残留清理 | ✅ | enumerate-only。 |
| 199 | Corpus refreshed rerun | ⚠️ | applied-only **1.077x**，overall 0.881x。 |
| 200 | **Tetragon rerun（2026-03-18）** | ⚠️ | connect_storm **-55.96%** 回归，见 #204 修复。 |
| 201 | **Kernel WARN_ON 排查（2026-03-18）** | ✅ | tailcall poke descriptor 冲突，暂不修。报告：`docs/tmp/kernel_warn_on_investigation_20260318.md`。 |
| 202 | **Katran E2E 完整设计（2026-03-18）** | ✅ | DSR 拓扑设计。报告：`docs/tmp/e2e_design_katran_20260318.md`。 |
| 203 | **XDP forwarding E2E 删除（2026-03-18）** | ✅ | 已删除 `e2e/cases/xdp_forwarding/` + 结果 + 文档引用。commit `431fdc5`。 |
| 204 | **Tetragon connect_storm 修复（2026-03-18）** | ✅ | stress_exec **+8.70%**，connect_storm **+22.29%**。3 applied / 49 bflip sites。报告：`docs/tmp/tetragon_connect_storm_investigation_20260318.md`。 |
| 205 | **Katran E2E MVP 实现（2026-03-18）** | 🔄 | 创建 e2e/cases/katran/，注册到 e2e/run.py，第一版用 standalone bpftool load 做 smoke。 |
| 206 | **Sequential rerun round 2（2026-03-18）** | ✅ | Tracee/Corpus rerun。trampoline guard 是 corpus 回归根因，已 revert。报告：`docs/tmp/sequential_rerun_round2_20260318.md`。 |
| 207 | **Tracee revert rerun（2026-03-19）** | ✅ | exec_storm +4.40%，file_io +4.69%。旧权威保持。报告：`docs/tmp/tracee_revert_rerun_20260319.md`。 |
| 208 | **Corpus revert rerun（2026-03-19）** | ✅ | applied-only **1.023x**。瓶颈是 non-applied ultra-short 噪声。报告：`docs/tmp/corpus_improvement_analysis_20260319.md`。 |
| 209 | **Trampoline regeneration 调研（2026-03-19）** | ✅ | ~100 LOC 方案。已在 #248 实施。报告：`docs/tmp/trampoline_regeneration_research_20260319.md`。 |
| 210 | **Kernel deep review（2026-03-19）** | ✅ | 9 个问题，3 轮修复见 #212-#214。报告：`docs/tmp/kernel_deep_review_20260319.md`。 |
| 211 | **GitHub ARM64 KVM 调研（2026-03-19）** | ✅ | 无 KVM，ARM64 recompile 需租机。报告：`docs/tmp/github_arm64_kvm_research_20260319.md`。 |
| 212-214 | **Kernel fix Phase A/B/C（2026-03-19）** | ✅ | 3 轮 kernel 修复。报告：`docs/tmp/kernel_fix_phase_{a,b,c1,c2}_20260319.md`。 |
| 215-216 | **Kernel cleanup + review（2026-03-19）** | ✅ | tracepoints 删除、stock choice 消除。9.2/10。selftest 20/20。 |
| 217-220 | **Kernel DSL 删除 + 简化（2026-03-19）** | ✅ | DSL ~900 行删除，blob 简化，do_jit 短路恢复。报告：`docs/tmp/kernel_dsl_removal_20260319.md`。 |
| 221 | **用户态 dead code 清理（2026-03-19）** | ✅ | -47 文件 / -21000 行。报告：`docs/tmp/userspace_cleanup_20260319.md`。 |
| 222-223 | **Kernel review + 接口精简（2026-03-19）** | ✅ | 8.4/10。selftest 19/19。报告：`docs/tmp/kernel_final_review_20260319.md`。 |
| 224-225 | **Build 依赖修复（2026-03-19）** | ✅ | Makefile blob 依赖修复。报告：`docs/tmp/micro_exec_blob_fix_20260319.md`。 |
| 226 | **UAPI 同步 + 验证（2026-03-19）** | ✅ | vm-micro 62/62，applied-only **1.078x**。报告：`docs/tmp/full_validation_final_20260319.md`。 |
| 227 | **ARM64 交叉编译 + QEMU（2026-03-19）** | ✅ | make kernel-arm64 + vm-arm64-smoke 通过。报告：`docs/tmp/arm64_cross_compile_qemu_20260319.md`。 |
| 228 | **Param match dead code 确认（2026-03-19）** | ✅ | 无需改动。 |
| 229-230 | **Kernel 5k review + P0/P1/P2 fix（2026-03-19）** | ✅ | trampoline gate、param-only emitter、overlap 检测。selftest 19/19。报告：`docs/tmp/kernel_review_fixes_20260319.md`。 |
| 231 | **Docker ARM64 交叉编译（2026-03-19）** | ✅ | Dockerfile + Makefile targets。ARM64 kernel 缺 recompile override。 |
| 232 | **用户态 cleanup round 3（2026-03-19）** | ✅ | dead imports/locals 清理。 |
| 233-235 | **Kernel LOC 分析 + 架构 review + 简化（2026-03-19）** | ✅ | 净减 **-447 LOC**。报告：`docs/tmp/kernel_simplification_20260319.md`。 |
| 236 | **Micro rerun post-P0/P1/P2（2026-03-19）** | ✅ | rotate_dense 回归为旧 bzImage 问题，非代码 bug。报告：`docs/tmp/rotate_dense_regression_debug_20260319.md`。 |
| 237 | **Scaleway RISC-V 调研（2026-03-19）** | ✅ | custom kernel 需特殊处理。报告：`docs/tmp/riscv_cloudv_scaleway_research_20260319.md`。 |
| 238 | **LLVM vs kernel JIT 指令级对比（2026-03-19）** | ✅ | WIDE_MEM+ROTATE 是主因。8-form 未覆盖：load-width narrowing、store coalescing、regalloc。报告：`docs/tmp/llvm_vs_kernel_jit_disasm_analysis_20260319.md`。 |
| 239 | **ARM64 JIT gap 分析（2026-03-19）** | ✅ | 4 form 值得移植（ROTATE/WIDE_MEM/EXTRACT/COND_SELECT）。报告：`docs/tmp/arm64_jit_gap_analysis_20260319.md`。 |
| 240 | **rotate_dense 回归 debug（2026-03-19）** | ✅ | 归入 #236。 |
| 241 | **Kernel 简化重启（2026-03-19）** | ✅ | 归入 #235。 |
| 242 | **Post-simplification review（2026-03-19）** | ✅ | 8/10。P1 masked ROTATE 见 #247。 |
| 243 | **ARM64 CI baseline（2026-03-19）** | ✅ | llvmbpf **0.590x**（54/62 wins）。报告：`docs/tmp/arm64_ci_first_run_20260319.md`。 |
| 244 | **权威 micro rerun（2026-03-19）** | ✅ | applied-only **1.152x**。报告：`docs/tmp/micro_authoritative_post_simplification_20260319.md`。 |
| 245 | **Corpus rerun（2026-03-19）** | ✅ | applied-only **1.062x**。报告：`docs/tmp/corpus_post_simplification_20260319.md`。 |
| 246 | **E2E rerun（待做）** | ⏳ 已被 #304 架构转向搁置 | |
| 247 | **ROTATE fix + cleanup（2026-03-19）** | ✅ | kernel-side 完成，scanner 待对齐（见 #268）。 |
| 248 | **Trampoline regeneration（2026-03-19）** | ✅ | selftest 25/25。报告：`docs/tmp/trampoline_regen_rotate_fix_20260319.md`。 |
| 249-251 | **ARM64 emitter 设计+实现（2026-03-19）** | ✅ | 4 form（ROTATE/WIDE_MEM/EXTRACT/COND_SELECT）+ arch callback 拆分。selftest 24/24（x86+ARM64）。报告：`docs/tmp/arm64_emitter_implementation_20260319.md`。 |
| 252 | **Selftest 扩展（2026-03-19）** | ✅ | +5 form，8/8 覆盖。selftest 24/24。 |
| 253 | **ARM64 CI corpus fix（2026-03-19）** | ✅ | io-mode 修复，覆盖率 52%。 |
| 254 | **Timing fix（2026-03-19）** | ✅ | llvmbpf 批量计时，ultra-short 修复。报告：`docs/tmp/timing_fix_20260319.md`。 |
| 255 | **Corpus llvmbpf 删除（2026-03-19）** | ✅ | 报告：`docs/tmp/corpus_llvmbpf_removal_20260319.md`。 |
| 256 | **权威 rerun（2026-03-20）** | ✅ | Micro **1.057x** / applied **1.193x**。Corpus applied **0.947x**。Tracee **+8.1%**。Tetragon **+20.3%/+32.2%**。Gap **0.581x**。报告：`docs/tmp/full_rerun_authoritative_20260320.md`。 |
| 257 | **Branch 合并（2026-03-19）** | ✅ | ARM64 CI 分支合并到 main。 |
| 258 | **Paired measurement（2026-03-19）** | ✅ | 归入 #262。 |
| 259 | **Framework review（2026-03-19）** | ✅ | micro applied-only 可靠；corpus overall 不可靠。报告：`docs/tmp/benchmark_framework_review_20260319.md`。 |
| 260 | **ARM64 micro eval（2026-03-19）** | ✅ | smoke 通过，性能负向（QEMU 噪声）。报告：`docs/tmp/arm64_micro_eval_20260319.md`。 |
| 261-262 | **Benchmark cleanup + same-image 改造（2026-03-19）** | ✅ | same-image paired measurement 落地。报告：`docs/tmp/same_image_measurement_20260319.md`。 |
| 263 | **Trampoline regen + ROTATE fix 合并（2026-03-19）** | ✅ | selftest 25/25。报告：`docs/tmp/trampoline_regen_rotate_fix_20260319.md`。 |
| 264-265 | **ARM64 emitter review + P0/P1 fix（2026-03-19）** | ✅ | subprog staging + EXTRACT width 校验。selftest 27/27。报告：`docs/tmp/arm64_p0p1_fix_20260319.md`。 |
| 266 | **AWS ARM64 benchmark（2026-03-19）** | ⚠️ 已被 #304 搁置 | t4g.micro smoke 通过。glibc ABI 残留。报告：`docs/tmp/aws_arm64_benchmark_run_20260320.md`。 |
| 267 | **Makefile 审计（2026-03-19）** | ✅ | defaults 统一 10/2/200。报告：`docs/tmp/makefile_benchmark_audit_20260319.md`。 |
| 268 | **Scanner ROTATE 对齐（2026-03-19）** | ✅ | scanner-tests 0 FAIL。报告：`docs/tmp/scanner_rotate_align_20260319.md`。 |
| 269 | **Validator/emitter boundary audit（2026-03-20）** | ✅ | “Validator=安全门，Emitter=信任”。selftest 27/27。报告：`docs/tmp/validator_emitter_boundary_audit_20260320.md`。 |
| 270 | **Katran harness fix（2026-03-20）** | ✅ | same-image paired，1.042x。报告：`docs/tmp/katran_harness_fix_20260320.md`。 |
| 271 | **Corpus 根因分析（2026-03-20）** | ✅ | applied-only 0.947x。报告：`docs/tmp/corpus_rootcause_20260320.md`。 |
| 272 | **Selftest 扩展（2026-03-20）** | ✅ | +9 tests，selftest **36/36**。报告：`docs/tmp/selftest_negative_boundary_20260320.md`。 |
| 273 | **Kernel quality audit（2026-03-20）** | ✅ | P0 buffer overflow + P1 alias bugs。见 #275 修复。报告：`docs/tmp/kernel_code_quality_audit_20260320.md`。 |
| 274 | **Benchmark framework refactor（2026-03-20）** | ✅ | runner/ 顶层提取，corpus 8→1 driver。报告：`docs/tmp/benchmark_framework_refactor_20260320.md`。 |
| 275 | **Kernel P0+P1 fix（2026-03-20）** | ✅ | BRANCH_FLIP/COND_SELECT/ADDR_CALC bugs。selftest 36/36。报告：`docs/tmp/kernel_p0p1_fix_20260320.md`。 |
| 276-278 | **ZERO_EXT_ELIDE 分析+删除（2026-03-20）** | ✅ | 内核 **-118 LOC**。selftest 35/35。报告：`docs/tmp/zero_ext_elide_deletion_20260320.md`。 |
| 277 | **Post-refactor cleanup（2026-03-20）** | ✅ | py_compile 无错误。 |
| 279 | **Cross-layer fix（2026-03-20）** | ✅ | 零跨层 import。报告：`docs/tmp/cross_layer_cleanup_20260320.md`。 |
| 280 | **Trampoline leak fix（2026-03-20）** | ✅ | Double synchronize_rcu。selftest 35/35。 |
| 281 | **ARM64 E2E smoke（2026-03-20）** | ✅ | Katran recompile 通过。Tetragon ❌。EC2 terminated。报告：`docs/tmp/arm64_e2e_smoke_20260320.md`。 |
| 282 | **Katran harness 升级（2026-03-20）** | ✅ | BPF **1.108-1.168x**。报告：`docs/tmp/katran_e2e_quality_analysis_20260320.md`。 |
| 283 | **ARM64 bpftool fix（2026-03-20）** | ✅ | kernel_btf fallback。Katran recompile 全通。报告：`docs/tmp/arm64_bpftool_fix_20260320.md`。 |
| 284 | **Kernel 精简（2026-03-20）** | ✅ | **-137 LOC**。selftest 35/35。报告：`docs/tmp/kernel_low_risk_simplification_20260320.md`。 |
| 285 | **用户态精简（2026-03-20）** | ✅ | **-32,329 行**。报告：`docs/tmp/userspace_consolidation_20260320.md`。 |
| 286 | **Framework 清理（2026-03-20）** | ✅ | 删除散乱目录/脚本。报告：`docs/tmp/framework_cleanup_audit_20260320.md`。 |
| 287-288 | **Kernel bloat review + emitter 成本（2026-03-20）** | ✅ | BRANCH_FLIP 反转不可行。per-form ~180-500 LOC。报告：`docs/tmp/kernel_bloat_review_20260320.md`。 |
| 289 | **表驱动 validator（2026-03-20）** | ✅ | 边际成本 ~500→~80-150 LOC。selftest 35/35。报告：`docs/tmp/form_cost_reduction_design_20260320.md`。 |
| 290 | **vm-micro 验证（2026-03-20）** | ✅ | 62/62 valid，applied-only **1.269x**。报告：`docs/tmp/vm_micro_validation_20260320.md`。 |
| 291 | **ROTATE/WIDE_MEM 表驱动（2026-03-20）** | ✅ | **-66 行**。selftest 35/35。报告：`docs/tmp/rotate_wide_table_driven_20260320.md`。 |
| 292 | **Katran endian bug（2026-03-20）** | ✅ | movbe store 副作用 bug。报告：`docs/tmp/katran_endian_store_bug_investigation_20260320.md`。 |
| 293 | **PGO policy 设计（2026-03-20）** | ✅ | live enumerate 是关键。报告：`docs/tmp/pgo_policy_design_20260320.md`。 |
| 294 | **Verifier 扩展调研（2026-03-20）** | ✅ | 方案 C 最划算（~50 行 liveness）。报告：`docs/tmp/verifier_extension_research_20260320.md`。 |
| 295-296 | **Katran site coverage（2026-03-20）** | ✅ | 74 sites（bflip=56, cmov=8, wide=4, endian=4, extract=2）。safe6 policy，BPF 1.042x。报告：`docs/tmp/katran_site_coverage_analysis_20260320.md`。 |
| 297/301 | **Tetragon 未 apply 调查（2026-03-20）** | ✅ | offline scan 看不到 live bflip sites。最多 5/7 可 apply。报告：`docs/tmp/tetragon_unapplied_investigation_20260320.md`。 |
| 298/300 | **ARM64 benchmark pipeline（2026-03-20）** | ⚠️ 已被 #304 搁置 | 改为 t4g.micro 交叉编译方案。 |
| 299 | **x86 新优化调研（2026-03-20）** | ✅ | Top-5 新机会。报告：`docs/tmp/x86_new_optimization_opportunities_20260320.md`。 |
| 302 | **E2E profiler（2026-03-20）** | 🔄 已被 #304 搁置 | PGO policy 设计。 |
| 303 | **目录整理（2026-03-20）** | ✅ | runner/docker, runner/scripts, docs/reference。报告：`docs/tmp/directory_reorganization_20260320.md`。 |
