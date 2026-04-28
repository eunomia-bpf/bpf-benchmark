# BpfReJIT v2 Task Archive (#304 - #673)

> Archived from  Section 7.
> For current tasks, see git history.

| # | 任务 | 状态 | 关键数据 / 文档 |
|---|------|:---:|------|
| ~~1-303~~ | v1 历史任务 | 见旧档 | `docs/kernel-jit-optimization-plan-record-old.md` |
| 304 | **v2 架构探索+收敛（2026-03-21）** | ✅ | v1 native-level rewrite → v2 bytecode-layer transformation + kernel verifier 验证。**收敛方案**：(A) GET_ORIGINAL+REJIT 程序变换；(B) kinsn ISA 扩展（KF_INLINE_EMIT）。REJIT 接受完整新 bytecode（非 patch）。**+200 行 kernel**。10 份调研报告在 `docs/tmp/20260320-21/`。POC 三 Phase 完成（`rejit-v2` 分支）。主仓库 commits: `e50365a`/`ba3c76e`/`f5eb9f1`。关键发现：xlated 不可逆需保存原始 bytecode；kinsn 优于新增独立 opcode；re-verify ~ms 级。 |
| 305 | 内核 POC 修复（2026-03-21） | ✅ | **444 行 kernel**（含 selftest 974 行）。fd_array/等长约束/rejit_mutex/sleepable 等 7 项修复。VM 通过。 |
| 306 | Runner v1→v2 替换 | ✅ | 净删 1121 行，删全部 v1 scanner/policy/directive 代码。 |
| 307 | module/x86/ 真实 kinsn 模块 | ✅ | `bpf_rotate.c`(ROL)、`bpf_select.c`(CMOV)、`bpf_extract.c`(BEXTR)。 |
| 308 | Bytecode rewriter 架构设计 | ✅ | 6 阶段 pipeline。报告：`docs/tmp/20260321/rewriter_architecture_design_20260321.md`。 |
| 309 | scanner→daemon 重命名 | ✅ | `git mv scanner daemon`，编译通过。 |
| 310 | Runner v1 死代码清理 | ✅ | 删 32 行 v1 残留。 |
| 311 | Daemon Rust POC 实现 | ✅ | **1834 行 Rust，21 tests**。C++→Rust 重写。6 模块，零 libbpf 依赖。 |
| 312 | VM 冒烟 + 3 bug fix | ✅ | **20/20 PASS**。REJIT cmd=39、ksym INIT_LIST_HEAD_RCU、len bytes÷8。 |
| 313 | Matcher Variant B 修复 | ✅ | 添加 high-first variant。27 tests。 |
| 314 | daemon-apply 集成 | ✅ | micro_exec `--daemon-path`。 |
| 315 | v2 WIDE_MEM 性能结果 | ✅ | 10/14 有 site。bounds_ladder **2.78x**、load_byte **2.59x**。Commit `27cbc1b`。 |
| 316 | Paper tex v2 更新 | ✅ | Abstract/Intro/Background 全部重写。+463/-866 行。 |
| 317 | corpus/ 死代码清理 | ✅ | 净删 ~329 行 v1 路径。 |
| 318 | driver.py --daemon-path 适配 | ✅ | Makefile `vm-micro` 自动传 DAEMON_PATH。 |
| 319 | Makefile cmake→cargo | ✅ | daemon target 改 cargo build。 |
| 320 | Commit push（2026-03-21） | ✅ | `698334f`/`56d6d19`/`c48cb43`。kernel submodule `4bcbc8e21`。 |
| 321 | Daemon pass 框架设计 | ✅ | PassManager 框架。报告：`docs/tmp/20260321/daemon_pass_framework_design_20260321.md`。 |
| 322 | Kernel code review | ✅ | 3 Critical + 4 Major。报告：`docs/tmp/20260321/kernel_v2_review_20260321.md`。 |
| 323 | ARM64 kinsn 模块 | ✅ | `module/arm64/` 3 模块。+613 行。交叉编译通过。 |
| 324 | e2e v2 daemon 集成 | ✅ | 5 case 接入 baseline→apply-all→post_rejit。 |
| 325 | Attachment sync 调研+修复（2026-03-22） | ✅ | Trampoline/freplace UAF 是真问题。Phase 0-2 修复实现：+260 行 kernel。**VM 12/12 PASS**。报告：`docs/tmp/20260321/rejit_attachment_sync_research_20260321.md`。 |
| 326 | Verifier log parser | ✅ | `verifier_log.rs` 433 行，33 tests。 |
| 327 | Daemon profiling | ✅ | `profiler.rs` 249 行。bpf_stats polling。 |
| 328 | Daemon pass 框架实现 | ✅ | WideMemPass + RotatePass + SpectreMitigation。**104 tests**。 |
| 333 | 安全测试套件设计 | ✅ | 5 类测试。报告：`docs/tmp/20260321/safety_eval_design_20260321.md`。 |
| 334 | func_cnt 限制调研 | ✅ | swap 路径不完整。报告：`docs/tmp/20260322/func_cnt_and_e2e_compat_20260322.md`。 |
| 335 | perf/LBR 调研 | ✅ | VM 无硬件 PMU（Arrow Lake）。bpf_stats 够用。 |
| 336 | func_cnt 修复实现 | ✅ | **+55 行 syscall.c**。multi-subprog layout match + swap。**VM 6/6 PASS**。Kernel `21c1b1f89`。 |
| 337 | 安全 negative test suite | ✅ | **919 行，20 tests，VM 20/20 PASS**。主仓库 `31c1433`。 |
| 338 | VM micro 冒烟（2026-03-22） | ✅ | **62/62, 47 applied, 0 mismatch**。geomean 0.887x。 |
| 339 | Kernel cleanup + gate 放宽 + st_ops | ✅ | 净减 101 行，st_ops text_poke +85 行。**~608 LOC kernel**。报告：`docs/tmp/20260322/kernel_cleanup_arch_review_20260322.md`。 |
| 340 | Daemon 升级 | ✅ | 被 #344 取代。 |
| 341 | Benchmark 框架升级 | ✅ | driver.py 正确性验证，corpus v2 对齐。 |
| 342 | prog_type 覆盖测试 | ✅ | **VM 21/21**。覆盖 13 种 prog_type。 |
| 343 | tail_call REJIT | ✅ | **VM 2/2**。deadlock fix `f4be5f31b`。**BpfReJIT 零 prog_type 限制。** |
| 344 | Daemon 完整重构 | ✅ | 删旧代码 -1622 行，PassManager 架构。**6425 行 / 111 tests**。 |
| 345 | kfunc 发现 + VM module loading | ✅ | `kfunc_discovery.rs`。Commits: `1c281ea`/`7f5d70a`。 |
| 346 | 全量测试 + 4 kernel bug fixes | ✅ | **62/62, 47 applied, 0 mismatch**。修 4 个 kernel bug。Kernel `b4bd737`。 |
| 347 | upstream BPF selftest | ✅ | test_verifier **526/527**（1 FAIL 非 REJIT）。test_progs 109 PASS。 |
| 348 | kernel bug fix 回归测试 | ✅ | 5 回归 PASS。并发 40/40，latency 27μs，78779 REJITs 压力。 |
| 349 | kernel 全面审计+修复 | ✅ | 3 HIGH + 6 MED 全修。Kernel `8a6923893`。报告：`docs/tmp/20260322/kernel_full_audit_20260322.md`。 |
| 350 | kinsn module 重编 | ✅ | 3/3 modules 加载成功。 |
| 351 | micro v2 with kinsn | ✅ | RotatePass **412 sites**。rotate64_hash **20.4% 加速**。报告：`docs/tmp/20260322/micro_analysis_v2_20260322.md`。 |
| 352 | corpus attach_trigger | ✅ | 新增 `runner/libs/attach.py`。 |
| 353 | applied 数下降修复 | ✅ | WideMemPass width=3/5/6/7 skip。121 tests。 |
| 354 | e2e 准备 | ✅ | 5/5 case 可跑。dev: Katran 1.108x, Tracee +8.1%。 |
| 355 | 全部 5 pass apply | ✅ | CondSelectPass/BranchFlipPass/SpectreMitigation。后续 #362 修正算法。 |
| 356 | SpectreMitigation 测试 | ✅ | 18+7 tests。JA+0 是 placeholder（真 barrier 在 #382）。 |
| 357 | bpftrace 复杂 tools | ✅ | 6 个 upstream tools 替换简单脚本。Commit `6933ee3`。 |
| 358 | v2 全量评估 | 🔄 → #637 | micro 1.153x（62/62, 49 applied）。corpus/e2e 需在新架构下重跑（#637）。 |
| 359 | Recompile overhead | ✅ 见 #491 | daemon ~2ms + REJIT ~13ms。 |
| 360 | Policy sensitivity 输入变体 | 待做 | predictable/random 变体，支撑 Insight 2。 |
| 361 | VM bias 调查 | 待做 | control 有 7.8% phantom speedup。 |
| 362 | Daemon P0 算法修复 | ✅ | branch_flip/cond_select/rotate/liveness 4 项修复。**147 tests**。Commit `ae76f1b`。 |
| 363 | Daemon P1 集成修复 | ✅ | BTF kind/fd_array/PGO/dead code。Commit `0c650f0`。 |
| 364 | Daemon serve 子命令 | ✅ | Unix socket server，JSON 协议。Commit `4df4922`。 |
| 365 | Tests 目录重组 | ✅ | 删 40+ debug scripts。4 层结构。Commit `a68a79a`。 |
| 366 | Kernel bug 回归测试 | ✅ | **VM 9/9**。含 struct_ops multi-slot。Commit `ca5aa66`。 |
| 367 | docs/tmp 按日期归档 | ✅ | ~250 文件归到 6 个日期目录。Commits `94c3ce2`/`3373251`。 |
| 368 | Corpus measured_pairs 修复 | ✅ | vng --rwdir + kinsn auto-load。0→94 measured。Commit `7a5009e`。 |
| 369 | Daemon code review | ✅ | 3 CRITICAL + 8 HIGH，全在 #362-363 修复。报告：`docs/tmp/20260322/daemon_code_review_20260322.md`。 |
| 370 | vm-micro-smoke 全覆盖 | ✅ | 62 bench smoke（ITER=1, WARM=0, REP=50）。 |
| 371 | Corpus 54 unmeasured | ✅ | 8 新 attach 类型。measured 91→152。 |
| 372 | Makefile vm-selftest 接入 unittest | ✅ | unittest/ 6 个测试文件接入。 |
| 373 | kinsn module 重编 | ✅ | 3/3 x86 modules。Commit `9e6eb3d`。 |
| 374 | Daemon post-fix review | ✅ | 5/11 完整、3/11 部分、3/11 未修。报告：`docs/tmp/20260322/daemon_postfix_review_20260322.md`。 |
| 375 | Daemon 7 issues 全修复 | ✅ | cond_select/rotate/fd_array/PGO/annotation remap 等。**187 tests**。 |
| 376 | 缺失 pass 覆盖分析 | ✅ | ENDIAN_FUSION **1386 sites**（最高）、EXTRACT 542。 |
| 377 | ExtractPass 增强 | ✅ | +9 edge case tests。**196 tests**。 |
| 379 | 全项目架构审查 | ✅ | 报告：`docs/tmp/20260322/full_project_review_20260322.md`。 |
| 380 | ENDIAN_FUSION 实现 | ✅ | x86 MOVBE + arm64 LDR+REV + daemon EndianFusionPass。+22 tests。 |
| 381 | Module UB + cross-arch 修复 | ✅ | extract/rotate UB fix。ARM64 ROL 统一。全部 UNSPEC。 |
| 382 | 真实 Spectre barrier | ✅ | x86 LFENCE + arm64 DSB+ISB kinsn。**224 tests**。 |
| 383 | kinsn common header | ✅ | `DEFINE_KINSN_MODULE` 宏，10 modules 简化 ~300 行。 |
| 384 | PGO 闭环实现 | ✅ | profiler→ProfilingData→BranchFlipPass 完整数据流。**224 tests**。 |
| 385 | e2e case_common 提取 | ✅ | `e2e/case_common.py`，5 case 去重。 |
| 386 | scanner→daemon 全量清理 | ✅ | 25 文件命名统一。 |
| 387 | 5 infra 架构修复 | ✅ | module/load_all.sh、VM_INIT 宏、daemon path 统一。 |
| 388 | Daemon serve 接入 pipeline | ✅ | kernel_runner.cpp Unix socket client。 |
| 389 | Makefile 全自动 pipeline | ✅ | kernel defconfig + kinsn-modules 依赖链。 |
| 390 | Makefile 大重构 | ✅ | 759→335 行（-56%）。 |
| 391 | 5 dead code 接线 | ✅ | verifier_log/HotnessRanking/PlatformCapabilities/module_fds/AnalysisCache。**229 tests**。 |
| 392 | kernel 改动总结 | ✅ | 22 文件，净增 ~1300 行。5 组件。 |
| 393 | sudo 全量清理 | ✅ | 29 文件删 sudo。VM 内已是 root。 |
| 394 | deprecated CLI 清理 | ✅ | 删 --daemon-path、recompile_v5→blind_apply 等。 |
| 395 | Corpus 54 unmeasured 实现 | ✅ | 8 新 attach 类型。measured 91→152。 |
| 396 | Fuzz + adversarial tests | ✅ | fuzz 10000 轮 + adversarial 23 tests。 |
| 397 | Verifier-guided rollback | ✅ | TransformAttribution + failure PC 提取。**240 tests**。 |
| 398 | Verifier differential verification 调研 | 📝 | **方案 B（per-pass LOAD+log_level=2 对比）最佳**。报告：`docs/tmp/20260322/verifier_differential_verification_research_20260322.md`。 |
| 399 | v1 policy 文件系统清理 | ✅ | 删 policy.py(553行) + corpus/policies/(582文件)。 |
| 400 | Verifier log ENOSPC 修复 | ✅ | 快速路径 log_level=0，失败时 16MB。 |
| 401 | Split BTF name_off 修复 | ✅ | 7/7 kfuncs 发现成功。 |
| 402 | CPU freq scaling bias 修复 | ✅ | daemon idle 降频。修复后 geomean 0.654→1.059x。 |
| 403 | Corpus applied=2 调查 | ✅ | 根因：pattern matcher 不匹配真实 bytecode。已在 #416 修复。 |
| 404 | E2E 3 bug 修复 | ✅ | persist_results + scx bpftool + katran CONFIG_NET_IPIP。 |
| 407 | Transform trace observability | ✅ | 结构化 `OptimizeOneResult`。runner JSON 嵌入。**246 tests**。 |
| 408 | kinsn BTF 常量修复 | ✅ | `BPF_BTF_GET_NEXT_ID` 22→23。`CONFIG_DEBUG_INFO_BTF_MODULES=y`。 |
| 409 | Map fd bit extraction 修复 | ✅ | `regs & 0x0f` → `(regs >> 4) & 0x0f`。修复 60/152 REJIT 失败。**256 tests**。 |
| 410 | PMU counters 接入 profiler | ✅ | `perf_event_open` 采集 branch_misses。**251 tests**。 |
| 411 | BranchFlip fallback + PGO warmup | ✅ | no PMU data → skip。`--pgo-warmup-repeat`。**265 tests**。 |
| 412 | 死代码/过时脚本清理 | ✅ | 删 v1 policy tests。**256 tests**。 |
| 413 | Daemon 测试缺口补充 | ✅ | +19 tests。含 kernel header BPF cmd 常量验证。**265 tests**。 |
| 414 | Mock test 审计 | ✅ | 6 HIGH + 8 MEDIUM。报告：`docs/tmp/20260323/daemon_mock_test_audit_20260323.md`。 |
| 415 | 修复全部 14 个测试问题 | ✅ | 发现 rotate/cond_select/extract 真实 bytecode 不匹配。 |
| 416 | Pass pattern matcher 修复 | ✅ | RotatePass 反向 OR、CondSelectPass Jcc+1、caller-saved save/restore。**303 tests**。 |
| **417** | **⚠️ kinsn operand-encoded ALU 设计（2026-03-23）** | ✅ 设计完成 | **核心 novelty**：kinsn 不是函数调用，是自定义 ALU 指令。dst_reg 编码操作数，off 编码常量，verifier 只 mark dst_reg modified + narrow_result 回调恢复精度。每个 kinsn 替换都是 N→1 指令，零开销。**关键**: 这是论文 kinsn 机制的核心贡献 — 如何让 verifier 正确建模平台特定内联指令。设计报告：`docs/tmp/20260323/kinsn_register_design_20260323.md`。 |
| 418 | kfunc verifier 机制调研 | ✅ | 无现成 clobber 控制。报告：`docs/tmp/20260323/kfunc_verifier_mechanisms_20260323.md`。 |
| **419** | **⚠️ bpf_kinsn_ops 完整设计（2026-03-23）** | ✅ | codex 调研。独立 sidecar `struct bpf_kinsn_ops`（不扩展 btf_kfunc_id_set）。`model_call()` 返回声明式 `bpf_kinsn_effect`（input_mask + clobber_mask + result range/tnum + mem_accesses），不暴露 bpf_reg_state。packed ABI 用 sidecar pseudo-insn（不复用 off 字段）。endian_load 改 const void*。KF_KINSN 替代 KF_INLINE_EMIT。设计报告：`docs/tmp/20260323/kinsn_ops_design_20260323.md`。 |
| **420** | **kinsn_ops 完整实现** | ✅ | **53/62 applied, 1612 sites**（rotate 701, extract 524, endian 256）。vm-selftest **70/70 PASS**。Commit `8c1dd22`。Review：`docs/tmp/20260323/kinsn_implementation_review_20260323.md`。 |
| 421 | SIMD kinsn module | ❌ 不做 | x86 SIMD 不做（FPU 开销），ARM64 NEON 条件性 Phase 2。见 #505。 |
| 422 | Frozen map inlining | ❌ 不做 | 真实 workload 无显式 freeze。报告：`map_inlining_opportunity_analysis_20260323.md`。 |
| 423 | **Dynamic map inlining + invalidation** | ✅ | ARRAY 全消除 + HASH speculative inline + invalidation tracker。**设计报告见 #472a**。 |
| 424 | Verifier-assisted const prop | ✅ 见 #624 | v1 落地 + verifier-in-the-loop 已实现（#624）。534 tests。 |
| 425 | vm-micro 正确性验证 | ✅ | **53/62 applied, 0 mismatch**。kinsn pass 生效。 |
| 426 | vm-corpus 正确性验证 | ✅ | 152 measured, **56 applied**（14x 提升）。0 mismatch。 |
| 427 | vm-e2e 正确性验证 | ✅ | 4/5 PASS（katran timeout）。 |
| 428 | Kernel code review | ✅ | 2 CRITICAL + 3 HIGH。报告：`docs/tmp/20260323/kernel_code_review_20260323.md`。 |
| 429 | Packed ABI 验证 | ✅ | rotate/extract ✅。endian offset 需修（#430）。 |
| 430 | endian packed + 删 legacy ABI | ✅ | 全部走 packed。删 legacy emit。**296 tests**。Commit `5e10be2`。 |
| 431 | Kernel CRITICAL/HIGH 修复 | ✅ | uapi 头同步、fd_array_cnt 上限、module 引用。 |
| 432 | katran HTTP server 修复 | ✅ | 归入 #435。Commit `a57e41f`。 |
| 433 | LFENCE/BPF_NOSPEC 消除 | ⏸ 暂不评估 | corpus 实测 BPF_ST_NOSPEC = 0。见 §3.2。 |
| 434 | 全面优化调研 | ✅ | 3 份报告：`docs/tmp/20260323/comprehensive_optimization_survey_20260323.md` 等。 |
| 435 | E2E 真实应用模式 | ✅ | katran xdpgeneric + retry。**5/5 PASS**。 |
| 436 | 删除 E2E manual fallback | ✅ | 删 `manual.py`（-244 行）。Commit `174bfe5`。 |
| 437 | Katran post-REJIT correctness bug | ✅ | HTTP server 行为问题（非 REJIT bug）。Commit `a57e41f`。 |
| 438-440 | endian packed / legacy ABI / packed tests | ✅ | 归入 #430。 |
| 441 | Kernel CRITICAL/HIGH 修复 | ✅ | 同 #431（重复条目）。 |
| 442 | 冗余 bounds check 消除 | ✅ 见 #498 | BoundsCheckMergePass 实现。14/14 tests。 |
| 443 | DCE pass | ✅ | `dce.rs`：unreachable block + NOP cleanup。设计：`docs/tmp/20260324/verifier_constprop_dce_design_20260324.md`。 |
| 444 | skb_load_bytes 特化 | ✅ | `SkbLoadBytesSpecPass`。TC only, len≤8。Commit `bf0742d9540f`。报告：`docs/tmp/20260324/helper_call_inlining_research_20260324.md`。 |
| 445 | Spill/fill 消除 | ❌ | 内核已有 KF_FASTCALL。 |
| 446 | kinsn 设计文档 | ✅ | `docs/kinsn-design.md`（1097 行）。Commit `5e10be2`。 |
| 447 | Daemon debug logging | ✅ | `--debug` per-pass dump。299 tests。 |
| 448 | Corpus 测量 bug 修复 | ✅ | daemon-socket 模式下 stock sample 缺失。 |
| 449 | bpftrace 脚本修复 | ✅ | 语法适配 v0.20.2。 |
| 450 | Tetragon e2e 修复 | ✅ | kprobe→tcp_connect。 |
| 451 | Tracee e2e 修复 | ✅ | setup.sh 重写。 |
| 452 | Kernel 完整审计 v2 | ✅ | **1437 LOC**。2 HIGH + 5 MED 新发现。报告：`docs/tmp/20260323/kernel_full_review_20260323.md`。 |
| 453 | Kernel HIGH 修复 | ⏸ | refresh 吞错误 + dead code。低影响，不阻塞 eval。 |
| 454 | 干净环境性能重跑 | superseded by #637 | 新架构全量跑取代旧架构重跑。 |
| 455 | Recompile overhead | ✅ | daemon ~2-5ms + REJIT ~3-7ms。见 #491 详细。 |
| 456 | ARM64 QEMU 测试 | ✅ 见 #593 | ARM64 kinsn 6/6 + rejit_poc 6/6。 |
| 457 | WideMemPass packet pointer fix | ✅ | XDP/TC skip 非 R10 base。+7 tests，**350 tests**。 |
| 458 | Corpus single-VM batch | ✅ | 单 VM + daemon serve 全程常驻。删 per-target VM 路径。 |
| 459 | micro_exec keep-alive | ✅ | stdin JSON-line 模式。BTF 只加载一次。micro 13.5min→3-4min。 |
| 460 | Daemon 静态验证 pipeline | ✅ | 342 程序→48 applied→340 accepted。`make vm-static-test`。 |
| 461 | BCC corpus 扩展 | ✅ | +34 条目（16→50）。 |
| 462 | BCC e2e case | ✅ | 8 个 tool，真实 binary。 |
| 463 | kinsn v2 instantiate 设计 | ✅ | 报告：`docs/tmp/20260323/kinsn_v2_instantiate_design_20260323.md`。 |
| 464 | Paper submodule + 清理 | ✅ | Commits `91a2be3`/`329ef17`。 |
| 465 | VM 管理设计 | ✅ | 报告：`docs/tmp/20260323/vm_management_design_20260323.md`。 |
| 466 | Benchmark 框架 review | ✅ | 五大瓶颈。#458/#459 解决前两个。 |
| 467 | **Runner 统一第三方 repo 控制面** | ✅ | `runner/repos.yaml` + fetch/build + Make 薄封装均已落地。新架构（§5.6 app_runners）取代旧消费层。 |
| 468 | Corpus 补全 | ✅ | +61 条目。~60→~155。 |
| 469 | Runner infra 全量验证+提速 | ✅ | debug artifact 默认关闭。micro 154→119s，corpus 703→514s。 |
| 470 | Runner VM/机器调度控制面 | ✅（后续继续收口） | 早期实现是 `machines.yaml` + `with_vm_lock.py`；当前 active 控制面已迁移到 `runner/targets/*.env`、`runner/suites/*.env` 和显式 KVM/AWS executors。 |
| 471 | benchmark 死代码清理 | ✅ | 删 v1 helpers。Commits `d3879ba`/`3b98b53`/`eeef9f4`。 |
| 472 | **未实现优化深度调研** | ✅ | 8 份设计/调研报告全部完成，均在 `docs/tmp/20260324/`：(a) `dynamic_map_inlining_design`、(b) `verifier_constprop_dce_design`、(c) `lfence_nospec_elimination_design`、(d) `bounds_check_elimination_research`、(e) `128bit_wide_loadstore_research`、(f) `addr_calc_lea_research`（**14 sites，ROI 低**）、(g) `simd_kinsn_design`、(h) `helper_call_inlining_research`（`skb_load_bytes` 最可行）。 |
| 473 | Related Work survey | ✅ | → `docs/tmp/20260324/related_work_comprehensive_analysis_20260324.md` |
| 474 | **Map Inlining + Const Prop + DCE（论文核心）** | ✅ | 全部落地。Pipeline: `map_inline → const_prop → dce`。**11556 lookup sites；Katran -91%；Tetragon -99.6%**。corpus 72 applied, exec geomean **0.854x**（+17%）。设计：`dynamic_map_inlining_design_20260324.md` + `verifier_constprop_dce_design_20260324.md`。verifier-in-the-loop 已接入（#624）。 |
| **475** | **kinsn 统一到 kfunc 路径** | 📝 设计完成 | 消除平行子系统，统一到 `KF_KINSN` + `PSEUDO_KFUNC_CALL`。净减 ~150-260 行 kernel。报告：`docs/tmp/20260325/kinsn_kfunc_unification_research_20260325.md`、`docs/tmp/20260325/kinsn_kfunc_unification_codex_research_20260325.md`。**待做**：(1) 10 module 补 kfunc stub + daemon 切 FUNC discovery；(2) verifier/JIT `KF_KINSN` 旁路 + normalize shim；(3) 删旧 `kinsn_tab`/`register_bpf_kinsn_set()`/独立 JIT dispatch。 |
| **476** | **测试基础设施 + bug 修复（2026-03-25/26）** | ✅ | **测试**：rejit_swap(5) + rejit_verifier_negative(4) + rejit_pass_correctness(16) + retval check + fuzz(1000) + ARM64 53 pass。**Bug 修复**：daemon const_prop/map_inline/DCE 3 个 + 内核 metadata 竞态/null deref/swap 遗漏/smp_wmb 4 个。**验证**：vm-selftest x86 **13 suites ALL PASSED**；vm-micro **62/62 0 mismatch 1591 sites**。**残留 P1**：swap one-way copy + find_call_site 单匹配。报告：`docs/tmp/20260325/kernel_remaining_bugs_20260325.md`、`kernel_patch_strict_final_review_20260325.md`、`arm64_test_results_20260325.md`。 |
| 477 | **框架死代码清理 + kallsyms panic 修复** | ✅ | (1) 删除 ~1314 行死代码（mode 概念/attach.py/--rejit flag）。验证：vm-micro 62/62 0 mismatch，corpus 764/471/292/113。报告：`corpus_modes_audit_20260326.md`、`benchmark_framework_dead_code_audit_20260326.md`。(2) REJIT subprog kallsyms kernel panic：swap 后 `INIT_LIST_HEAD_RCU()`（+10 行）。217 applied / 576 accepted / 0 crash。报告：`rejit_kallsyms_crash_report_20260325.md`。 |
| 478 | WideMemPass provenance filter | ✅ | `is_likely_packet_ptr()` 回扫。只跳真正 packet pointer。351 tests。 |
| 479 | 测试基础设施统一 | ✅ | wildcard 自动发现 `rejit_*.c`。vm-all 加 vm-static-test。 |
| 480 | Corpus 全 prog type 覆盖 | ✅ | YAML **131→764 条目**，覆盖 **2019/2019 程序 100%**。**764 targets / 471 compile / 292 measured / 113 applied**。 |
| 481 | QEMU 8.2.2 TCG crash + 9.2.2 升级 | ✅ | QEMU bug（非内核）。源码编译 9.2.2。200 轮零 segfault。报告：`docs/tmp/20260325/tcg_min_repro_and_e2e_investigation_20260325.md`。 |
| 482 | const_prop typed LD_IMM64 修复 | ✅ | 不再折叠 `src_reg != 0` 的 LD_IMM64。340 tests。 |
| 484 | 内核代码 4 轮审阅 | ✅ | **2935 行 patch**，7 必修 HIGH + 4 误报 + 1 新发现。报告：`docs/tmp/20260325/kernel_review_opus_final_20260325.md`、`docs/tmp/20260326/kernel_final_verdict_opus_20260326.md`。 |
| 490 | 未调研 pass 补全 | ✅ | 6 份报告（`docs/tmp/20260326/`）：subprog inline(**834** 调用点)、tail-call(**537** sites)、helper firewall(**91034** 调用)、corpus 统计(**568** obj/**2019** prog)、live patching(**31**/45 CVE)、权限收紧。 |
| 498 | **批量 pass + module 实现（2026-03-26）** | ✅ | 8 项一次性实现：(1) BoundsCheckMergePass 14/14 tests `639926cb`，设计：`bounds_check_merge_design_20260326.md`；(2) SkbLoadBytesSpecPass 14/14 tests `bf0742d9`，设计：`skb_load_bytes_spec_design_20260326.md`；(3) BulkMemoryPass 16/16 tests `958bab45`，设计：`bulk_memory_pass_design_20260326.md`；(4) MapInvalidationTracker 12/12 tests `eb9b5fe`，设计：`dynamic_map_invalidation_design_20260326.md`；(5) DangerousHelperFirewallPass 13/13 tests `ca020c4`，设计：`dangerous_helper_firewall_design_20260326.md`；(6) LivePatchPass 14/14 tests `750adfa`，设计：`live_patch_pass_design_20260326.md`；(7) ARM64 `bpf_ldp.c` + x86/ARM64 `bpf_bulk_memory.c` modules `d29d9b6427ab`，报告：`arm64_bpf_ldp_module_report_20260326.md`、`x86_bpf_bulk_memory_module_report_20260326.md`、`arm64_bpf_bulk_memory_module_report_20260326.md`、`kinsn_modules_review_20260326.md`。均在 `docs/tmp/20260326/`。 |
| 499 | Serve per-request pass selection + profiles | ✅ | 请求级 `passes` 覆盖 + `benchmark_config.yaml` + 5 个 cascade 集成测试。**448 tests**。Commit `2872554`。报告：`docs/tmp/20260326/serve_per_request_passes_report_20260326.md`、`benchmark_config_report_20260326.md`、`cascade_integration_test_report_20260326.md`。 |
| 491 | Recompile overhead 分解 + hotswap 压力测试 | ✅ | overhead：daemon ~2ms + REJIT ~13ms + PGO ~500ms，摊销门槛 646x-226140x。报告：`recompile_overhead_analysis_20260326.md`。hotswap：11/12 PASS（ext FAIL=kernel bug #506），12 prog_type。Commit `24f480d`。报告：`hotswap_test_review_20260326.md`。 |
| 492 | Scalability 测量 | ✅ | O(N) **~15ms/prog**。62 progs 579ms。报告：`scalability_memory_overhead_analysis_20260326.md`。 |
| 493 | Memory overhead | ✅ | kernel orig_prog_insns **10.21 MiB**/2019 progs。daemon RSS **9.97 MiB**。报告同 #492。 |
| 500 | map_inline 真实 VM 零命中修复 | ✅ | 真实 clang bytecode pattern 更复杂。Katran `xdp_pktcntr` 命中。**454 tests**。Commit `e658335`。报告：`map_inline_final_fix_report_20260326.md`。E2E capture Tracee+Tetragon **20 fixtures**。 |
| 501 | Corpus 结果分析 | ✅ | `764/442/315/130`。security pass 混入导致 1.239x 回归→已配 `active: performance`。报告：`corpus_results_analysis_20260326.md`。 |
| 502 | Corpus 覆盖 + map 初始化调研 | ✅ | **568 obj / 2073 prog，覆盖 97.7%**。推荐 E2E capture fixture 方案。报告：`corpus_coverage_and_map_init_investigation_20260326.md`。 |
| 503 | Daemon runtime 数据架构分析 | ✅ | 3 个缺陷（invalidation 未接入/PGO 缺 per-PC/非 JVM deopt）。报告：`daemon_runtime_data_architecture_20260326.md`。 |
| 504 | map_inline→const_prop→DCE 级联测试 | ✅ | 5 个集成测试。Commit `2872554`。 |
| 505 | SIMD/FPU kinsn 深度调研 | ✅ | x86 SIMD 不做（FPU ~200-800 cycles）。ARM64 NEON 条件性 Phase 2。报告：`simd_fpu_kinsn_deep_research_20260326.md`。 |
| 506 | Corpus YAML v2 重构 + EXT REJIT known limitation | ✅/📝 | (1) YAML 重构：object-centric schema **477 obj / 2019 prog**，Commit `d9a5e94`，设计：`corpus_yaml_restructure_design_20260326.md`。(2) EXT REJIT：`bpf_tracing_link_release()` 清 `dst_prog`，eval 无影响。修复方案 `ext_rejit_fix_proposal_20260326.md`（~70-100 行）。 |
| 507 | E2E map state capture | ✅ | v2：从 daemon response 提取 `inlined_map_entries`。Tracee 13 + Tetragon 7 = **20 fixtures**。Commit `bdc11ca`。 |
| 508 | map_inline 性能验证 | ✅ | **3 真实命中**。Katran insns **-45%**, JIT **-47%**; Tracee insns **-11%**。exec_ns 在 timing floor。报告：`map_inline_performance_validation_20260326.md`。 |
| 509 | Daemon testcase review | ✅ | 276/283 手写 BpfInsn。报告：`daemon_testcase_review_real_bpfo_20260326.md`。 |
| 510 | Corpus naming 统一 | ✅ | 764 条目加 `name`。Commit `ed9588f`。 |
| 511 | Daemon testcase 迁移真实 .bpf.o | ✅ | 全 15 pass，44 个真实 .bpf.o 测试。**513 tests**。Commit `79586a2`。 |
| 512 | Map fixture replay | ✅ | C++ runner `--fixture-path`。支持 PROG_ARRAY/map-in-map FD 翻译。Commit `9876557`。 |
| 513 | map_inline emit + const_prop fixed point | ✅ | MOV_IMM 替代 LD_IMM64。fixed point 最多 5 轮。Commit `c8b18f3`。 |
| 514 | map_inline inline 统计 | ⏸ | katran fixture 2 sites 命中。 |
| 515 | Daemon 简化 + E2E pass plumbing | ✅ | 删 --pgo/-passes（**-335 行**）。E2E 统一 `benchmark_performance_passes()`。报告：`map_inline_debug_status_20260327.md`。 |
| **494** | **Fixed kernel peephole baseline 对比** | ✅ 见 #611 | 分析已完成（#611）：ceiling 14049 sites，BpfReJIT 14833 sites（8.5x applied），CMOV 有负例。A/B benchmark run 如需更新数据，在新架构全量跑后补充。 |
| 483 | 宿主频繁重启 | 📝 | Intel 285K 过热（`-j24` + QEMU TCG）。降并行度。 |
| 495 | BPF 程序生命周期分析 | ⏸ 低优先级 | 论文用 transparency + zero overhead 论点已足够，不需要专门的 lifecycle 分析。 |
| 496 | K2/Merlin/EPSO 量化对比 | ✅ 见 #612 | K2 **0.736x** vs BpfReJIT **0.629x**。K2 只 XDP/TC。报告：`k2_comparison_setup_20260328.md`。如需更新数据，在新架构全量跑后补充。 |
| 497 | ARM64 性能数据 | ✅ 见 #609/#627 | AWS t4g.micro：llvmbpf gap **0.616x**，BpfReJIT **49/62 applied, 123 sites**。Katran 16/16 sites。 |
| 516 | map_inline PERCPU_ARRAY 等值槽 | ✅ | 归入 #526 map_inline 全面增强。 |
| 517 | Katran 热路径静态分析 | ✅ | `balancer_ingress`（**23872 xlated / 13654 jited / ~218.7ns**）。**66 map 引用**。先攻 `ctl_array/ch_rings/reals`。 |
| 518 | Tracee fixture replay 修复 | ✅ 归入 #526 | stale map_id→live fd 重映射。inner-map fixture 仍缺。 |
| 519 | map_inline corpus 0-hits 根因 | ✅ | BCC 全 HASH+动态 key。报告：`map_inline_root_cause_analysis_20260327.md`。 |
| 520 | Katran live e2e 真值 | ✅ | BPF **229→225ns (1.016x)**。wide_mem+endian 6 sites。map_inline 0 hit。 |
| 521 | Katran `inlined_map_entries` null fix | ✅ 归入 #526 | rejit.py null→空数组。后续 #526 全面增强。 |
| 522 | Katran corpus EINVAL 修复 | ✅ | prepared-run 复用 compile-only 输入→改重新 materialize_memory()。 |
| 523 | E2E/Corpus request-level pass 收口 | ✅ | daemon serve request-level `enabled_passes`。6 E2E case 统一。**540 tests**。归入 #541。 |
| 526 | map_inline 全面增强 + .rodata | ✅ | PERCPU fallback + PSEUDO_MAP_VALUE + verifier-guided key + .rodata（BCC **169** sites）。**540 tests**。 |
| 527 | Katran REPEAT=50 可信度审查 | ✅ | **<100ns ktime 不可信**。REPEAT=500+。报告：`katran_perf_credibility_analysis_20260327.md`。 |
| 528 | Corpus 构建方式调研 | ✅ | **429/1213 成功 (35%)**。531 include path 失败。报告：`corpus_build_analysis_20260327.md`。 |
| 524 | Katran 定向 corpus 真值 | ✅ | map_inline only: **exec_ns 14→7 (2.000x)**。sites_found=64, applied=7。报告：`katran_map_inline_perf_results_20260327.md`。 |
| 529 | map_inline fixpoint + Katran 40-site | ✅ | fixed-point 迭代。Katran `sites_applied 40`，`const_prop 29`。wall_exec **-17%**。 |
| 530 | Katran 20-byte key + stack-slot tracking | ✅ | 任意长度 key + stack-slot 常量追踪。Katran **41/105** sites，wall_exec **-23.6%**。 |
| 531 | 任意长度 constant-key | ✅ | wall_exec_ns **-23.6%**，exec_cycles **-23.6%**。JIT `13645→13573`。 |
| 532 | lookup-result spill/fill 跟踪 | ✅ 回退 | **1.714x**→correctness 回归→回退。结论：不可行。 |
| 533 | Katran spill/fill correctness 复核 | ✅ | **1.714x 是假阳性**（mutable writeback + spill alias 过长）。安全版本 2 sites，无 runtime 收益。 |
| 534 | Corpus warmups 配置接线修复 | ✅ | `warmup_repeat` 透传修复。之前默认 5 warmups 扭曲数据。 |
| 535 | Tracee inner-map fixture + Katran warmup-fixed | ✅ | Tracee inner-map capture+replay 落代码。Katran `total_sites_applied=2`，runtime 0.671x（无收益）。 |
| 536 | Tetragon func_info blocker 清除 | ✅ | 内核修正 btf+func_info 预填充。收敛为 attach EINVAL（非 REJIT 问题）。 |
| 537 | Tetragon tail-call guard | ✅ | 含 `bpf_tail_call` 程序保守 `no_change`。收敛为 attach blocker。 |
| 538 | Tetragon corpus 单-pass matrix | ✅ | 主阻塞是 generic attach EINVAL，不是 pass-specific rewrite。 |
| 539 | 安全 pass 从评估范围移除 | ✅ | `benchmark_config.yaml` 删 security 组。§3.2 标「⏸ 暂不评估」。 |
| 540 | Tetragon const_prop JA offset bug | ✅ | `fixup_folded_jumps()` 修 stale offset。报告：`tetragon_permission_denied_fix_20260328.md`。 |
| 541 | E2E pass 控制面统一 | ✅ | `rejit.py` 从 YAML 读 active passes，所有 case 统一。 |
| 542 | Daemon 质量修复 | ✅ | 静默吞错→传播、rollback 归因→per-pass diff、pass 别名→报错。**503 tests**。报告：`daemon_quality_fixes_20260328.md`。 |
| 543 | E2E 首次全量结果 | ✅ | **6/6 PASS**。Katran BPF **-4.5%**/throughput **+1.8%**。BCC **0.983x**。Tracee **+11.5%**。报告：`e2e_full_run_results_20260328.md`。 |
| 544 | Corpus 分析 | ✅ | 最后全量 run `764/442/315/130`，exec geomean 0.807x（不可信——security pass 污染）。报告：`corpus_results_analysis_20260328.md`。 |
| 545 | map_inline 零命中调查 | ✅ | mutable writeback guard 是程序级 veto（同 map 有写回→全禁）。报告：`map_inline_corpus_zero_hit_investigation_20260328.md`。 |
| 546 | 仓库一致性审查 | ✅ | 3 HIGH + 5 MEDIUM。报告：`repo_consistency_review_20260328.md`。 |
| 547 | Daemon 代码质量审查 | ✅ | 3 HIGH + 5 MEDIUM。God files：map_inline.rs 5134 行。报告：`daemon_code_quality_review_20260328.md`。 |
| 548 | E2E post-fix 重跑 | ✅ | **6/6 ok**。Tetragon 不再 Permission denied。 |
| 549 | Corpus 覆盖率瓶颈 | ✅ | build 失败 76% 是 asm/types.h。prepared-state 失败 308 个。报告：`corpus_coverage_bottleneck_analysis_20260328.md`。 |
| 550 | Daemon 架构文档 | ✅ | 1476 行 `docs/daemon-architecture.md`。 |
| 551 | Daemon post-fix review | ✅ | rollback attribution 不稳定、空白绕过、invalidation 错误丢弃。报告：`daemon_post_fix_review_20260328.md`。 |
| 552 | E2E + corpus 代码 review | ✅ | CRITICAL: 失败伪装 skipped。HIGH: enabled_passes=[] 语义。报告：`e2e_corpus_code_review_20260328.md`。 |
| 553 | 测试重组 + unwrap_or_default 修复 | ✅ | 4 个空测试填充。unwrap_or_default 收紧。**510 tests**。 |
| 554 | compile_only 清理 | ✅ | 66→17。报告：`compile_only_and_prepared_state_fix_20260328.md`。 |
| 555 | asm/types.h build 修复 | ✅ | 注入 vendor UAPI include。报告：`build_and_attach_fix_20260328.md`。 |
| 556 | K2 + fixed-baseline 对比方案 | ✅ | K2 开源可用。报告：`k2_and_baseline_comparison_plan_20260328.md`。 |
| 557 | Ablation 设计 | ✅ | 7 个 profile。报告：`ablation_and_bpftrace_investigation_20260328.md`。 |
| 558 | Static verify post-build | ✅ | **531 obj / 1241 prog / 345 applied / 345 accepted**。报告：`post_build_fix_static_verify_20260328.md`。 |
| 559 | Corpus dev run | ✅ partial | **288/469 obj**（segfault 截断）。exec geomean **0.980x**。map_inline=465, const_prop=635。报告：`corpus_dev_full_results_20260328.md`。 |
| 560 | 死代码清理 | ✅ | cargo 0 warnings, **507 tests**。pyflakes 干净。 |
| 561 | 静默失败 + 安全 pass 清理 | ✅ | 安全 pass .rs 删。enabled_passes=[] 统一。E2E skip→error。 |
| 562 | Daemon CLI serve-only | ✅ | 删 5 个旧子命令。**净删 -1418 行**。 |
| 563 | corpus/modes.py 重构 | ✅ | **3085→689 行（-78%）**。pytest 34 pass。 |
| 564 | Runner C++ 去重 | ✅ | 新建 3 共享模块。**合计 -1038 行**。 |
| 565 | json_parser fail-close | ✅ | 缺 key→fail()。socket 30s timeout。 |
| 566 | 5 个 SOSP red flags 修复 | ✅ | micro passes 传递、daemon docs、module 失败退出、README 清理、profiler 统一。 |
| 567 | SOSP 架构 readiness | ✅ | 302 files / 120644 LOC。5 red flags（已修 #566）。报告：`architecture_sosp_readiness_20260328.md`。 |
| 568 | Mutable writeback guard site-local | ✅ | 程序级 veto→per-site。只读 site 仍可 inline。**507 tests**。 |
| 569 | bpftrace 0 applied 修复 | ✅ | benchmark_config 加回全部 11 个 performance passes。 |
| 570 | Corpus 深入分析 + crash | ✅ | Top speedup security_bpf_map **4.19x**。88/255 加速。Calico 是 layout perturbation（非 bloat）。报告：`corpus_deep_analysis_and_crash_20260328.md`。 |
| 571 | E2E + Katran 验证（旧 binary） | ✅ | Katran map_inline=**6**。BCC **1.023x**。报告：`e2e_and_katran_post_all_fixes_20260328.md`。 |
| 572 | Per-pass verify 重构 | ✅ | 每 pass 后 verify callback，失败回退+继续。最终 REJIT 一次。**506 tests**。 |
| 573 | PGO socket protocol | ✅ | profile-start/stop/save/load。**513 tests**。 |
| 574 | E2E case scaffold 去重 | ✅ | `run_case_lifecycle()` 统一 6 case。 |
| 575 | 术语统一 recompile→rejit | ✅ | C++ + Python 全改。 |
| 576 | daemon-architecture.md 更新 | ✅ | 1371 行。反映 serve-only + PGO + per-pass verify。 |
| 577 | Calico 回归分析 | ✅ | **不是真实回归**：中位数 1.005，geomean 正负号翻转。repeat=50 不够。 |
| 578 | verifier_retries JSON 修复 | ✅ | optional 解析，缺失置 0。 |
| 579 | Python test 修复 | ✅ | 断言更新到 11 pass。38 tests。 |
| 580 | KVM PMU 调查 | ✅ | Arrow Lake Hybrid CPU 禁用 vPMU。替代：host-side `perf stat -e ...:Gk`。报告：`perf_kvm_guest_profiling_20260328.md`。 |
| 581 | SOSP paper review | ✅ | **Strong Reject**。eval placeholder、story 不收敛。报告：`sosp_paper_review_20260328.md`。 |
| 582 | 回归根因分析 | ✅ | Calico：layout perturbation。BCC：emit 32-bit 用 LD_IMM64。报告：`regression_root_cause_analysis_20260328.md`。 |
| 583 | E2E 最终重跑 | ✅ | **5/6 PASS**。Katran veth symbol 不兼容（#591 修）。 |
| 584 | emit_constant_load fix | ✅ | `MOV32_IMM` 替代 `MOV64_IMM`。R4 !read_ok 是 subprog 参数问题（已解决）。 |
| 585 | perf kvm stat 调研 | ✅ | `perf stat -e cycles:Gk` host 侧采样可用。报告：`perf_kvm_guest_profiling_20260328.md`。 |
| 586 | 重构 post-review | ✅ | 7 个正确。12 cargo warnings 消除。**510 tests**。报告：`post_refactor_review_20260328.md`。 |
| 587 | Corpus 数据统计审计 | ✅ | **0.980x 是 crash-truncated**。applied-only 0.995x / 170 samples。真实漏斗 2009→170。报告：`corpus_data_statistics_review_20260328.md`。 |
| 588 | Profiler 接线 + warnings 消除 | ✅ | hotness ranking 接入 optimize-all。**0 warnings**，509 tests。 |
| 589 | Corpus 覆盖率修复 | ✅ partial | results.py applied-only geomean 已 commit。完整 run 见 #608。 |
| 590 | kinsn vs kfunc novelty 文档 | ✅ | 当前真实 novelty：proof-visible instruction form + packed sidecar + native emit + graceful degradation。5/11 pass 依赖 kinsn。报告：`kinsn_vs_kfunc_novelty_20260328.md`。 |
| 591 | Katran veth module 修复 | ✅ | Makefile kernel-build 增量判断 + .ko 存在校验。 |
| 592 | Tetragon event_execve verifier bugs 修复 | ✅ | const_prop branch fold + dce BPF_PSEUDO_FUNC 两个 bug 修复。4 个回归测试。513 tests。报告：`tetragon_verifier_bugs_20260328.md`。 |
| 593 | ARM64 交叉编译 + QEMU test | ✅ | ARM64 kinsn **6/6**，`rejit_poc` **6/6**。报告：`arm64_test_20260328.md`。 |
| 594 | map_inline correctness 形式化 | ✅ | ARRAY/PERCPU_ARRAY/HASH/LRU_HASH。Invalidation 1s polling。报告：`map_inline_correctness_contract_20260328.md`。 |
| 595 | Pass-regression 关联分析 | ✅ | const_prop only **1.031**，triple **0.977**。Policy：const_prop 默认开，map_inline+dce profiling-gated。报告：`pass_regression_analysis_20260328.md`。 |
| 596 | ARM64 bulk_memset bug fix | ✅ | 3 修复（BPF_W 校验/stale insn_aux_data/INSN_BUF_SIZE 扩容）。ARM64 QEMU **3/3 PASS**。报告：`arm64_bulk_memset_fix_20260328.md`。 |
| 597 | Per-program pass selection YAML policy | ✅ | YAML policy 格式 + rejit.py 解析。pytest **45 passed**。报告：`per_program_policy_design_20260328.md`。 |
| 598 | 级联分析 | ✅ | 级联发生但效果小。报告：`cascade_analysis_20260328.md`。 |
| 599 | HASH map aggressive inline | ✅ | 全消除 lookup+null check。真实效果有限。 |
| 600 | attach-trigger + auto-trigger | ✅ | 静态可测集合 **111→1060/1536**。报告：`attach_trigger_fix_20260328.md`。 |
| 601 | map_inline 放宽 review | ✅ | 3 放宽但 E2E 效果有限。报告：`map_inline_relaxation_20260328.md`。 |
| 602 | Pass 覆盖率调查 | ✅ | **595/1241 = 47.9%**。报告：`pass_coverage_investigation_20260328.md`。 |
| 603 | E2E 6/6 正面数据 | ✅ | Tracee **+3.09%**，Katran **+1.78%/p99 -1.57%**，BCC **1.015x**，bpftrace **1.140x**，scx **+54.6%**。 |
| 604 | BCC 0.883x 回归修复 | ✅ | DCE fixed-point 死寄存器删除。**520 tests**。 |
| 605 | Build toolchain 并发安全 | ✅ | 旧串行化方案已废弃；当前走 per-arch build roots + Make 真实文件 target。 |
| 606 | Tracee 回归 + Tetragon 超时 | ✅ | branch-target fallback + 错误传播修复。**517 tests**。 |
| 607 | OSDI benchmark review | ✅ | **Reject**。P0：paired trials、K2 对比、完整 run。报告：`benchmark_framework_osdi_review_20260328.md`。 |
| 608 | Corpus 469 objects 跑 | ✅ 旧架构 | Round 1：431/469，applied-only geomean **1.0156**。旧架构数据，新架构需重跑（#637）。 |
| 609 | AWS ARM64（t4g.micro） | ✅ | llvmbpf gap **0.616x**，BpfReJIT **49/62 applied, 123 sites**。Katran 16/16 sites。 |
| 610 | AWS x86（t3.micro） | ✅ | **62/62** benchmark。ENA/VIRTIO builtin。Commits `5eed9d6`/`dc6c436`。 |
| 611 | Fixed peephole baseline 分析 | ✅ | ceiling **14049** sites。BpfReJIT **14833** sites（8.5x applied）。CMOV 有负例。报告：`fixed_peephole_baseline_analysis_20260328.md`。 |
| 612 | K2 对比框架 | ✅ | K2 **0.736x** vs BpfReJIT **0.629x**。K2 只 XDP/TC。报告：`k2_comparison_setup_20260328.md`。 |
| 613 | Tracee 方法学增强 | ✅ | same-image paired，5 轮，Bootstrap CI + significance test。 |
| 614 | Daemon 生命周期优化 | ✅ | session 级 daemon。E2E scan+apply 复用。 |
| 615 | Pass-regression 分析 | ✅ | 选择偏差确认。const_prop **1.031**（最佳候选）。triple **0.977**（风险组合）。 |
| 616 | lkm_seeker EINVAL fix | ✅ | 完整 metadata（prog_btf_fd/func_info/line_info 等）。**527 tests**。 |
| 617 | kinsn module 证据 | ✅ | `metadata.kinsn_modules` 写入 E2E artifact。 |
| 618 | Corpus exit 1 根因 | ✅ | `RLIMIT_NOFILE` 65536。 |
| 619 | Smart trigger 设计 | ✅ | 8 类 category。报告：`smart_trigger_design_20260329.md`。 |
| 620 | Map inline 覆盖差距 | ✅ | **17321→1629（9.4%）**。blocker：动态 key 35.9%、不支持 map type 27%、非标量 load 19.6%。报告：`map_inline_coverage_gap_20260329.md`。 |
| 621 | Corpus measured=0 gap | ✅ | loader 模型错。应用 app-native loader。报告：`corpus_measured_gap_analysis_20260329.md`。 |
| **622** | E2E 性能瓶颈分析 | ✅ | lkm_seeker EINVAL 是最大阻塞（已修 #616）。Katran 19 insns 是上限不是 bug。kinsn modules 缺观测证据（已修 #617）。报告：`e2e_performance_blockers_20260329.md`。 |
| 623 | Per-repo app-native loader | ✅ 见 #635 | 6 个 app runner 已实现（bcc/tracee/katran/tetragon/bpftrace/scx）。Commit `86bc953`。 |
| **624** | Verifier-in-the-loop 实现 + review | ✅ | **实现完成**（+713/-147 行，7 文件）：bpf.rs accept 时 log_level=2 抓 success log + 自适应扩容；verifier_log.rs 升级解析 exact scalar/tnum/32-64 bit/spill/speculative；const_prop.rs 优先用 verifier exact constants，fallback 本地传播；pass.rs accept 后刷新 verifier_states。**Review 修 2 个问题**：seed capture 扩到所有程序（不只 map_lookup）；超大 log 退化改 visible warning。**534 tests pass**。报告：`docs/tmp/20260329/verifier_in_the_loop_review_20260329.md`。 |
| **625** | **LLVM IR map_inline 可行性调研** | ✅ | **结论：可行，推荐 hybrid 方案**。保留 kinsn pass 在 BPF 层，map_inline+const_prop+DCE 走 LLVM IR 子路径。`llvmbpf` lifter 覆盖大部分 BPF 指令，已有 array-map inline 实现可证明路线正确。**最大风险**：verifier 兼容性（lifted IR 缺 PTR_TO_CTX/loop-bound/pointer provenance）。不需要改 LLVM BPF backend（第一阶段）。**时间线**：1 周窄 POC，2 周接入 daemon，1 个月工程化。827 行报告：`docs/tmp/20260329/llvm_ir_map_inline_feasibility_20260329.md`。 |
| **626** | Corpus pipeline bug fix + verifier log bloat | ✅ | (1) 单 object 失败不 kill 整个 batch；(2) 部分失败数据聚合；(3) daemon response 不输出 verifier log 原文。**corpus 189/189 objects 完成，15 applied, geomean 0.913x**。但 baseline_run 全 None（prepared_group bug），结果不可靠。 |
| **627** | ARM64 native cross-build + AWS rerun | ✅ | cross-arm64-build.sh 改 native cross-compile（不再 QEMU 模拟）。t4g.micro **62 micro, 50 applied, 126 sites**。Katran smoke **23 sites applied**。结果：`.cache/aws-arm64/results/benchmark_20260329_200533/`。 |
| **628** | E2E/corpus 质量 review + 清理 | ✅ | 11 个问题修复（skip→error、daemon crash fail-fast、silent fallback 等）。**78 pytest pass**。报告：`e2e_corpus_quality_review_20260329.md`。 |
| **629** | bpftool 替代 C++ 调研 | ✅ | **大体可行**：loadall/pin/run/show/map update 均支持。6 个硬缺口：无 bpf_enable_stats CLI、37.7ms/次 overhead（repeat N 可摊薄）、短命进程模型。**结论**：corpus 用 Python+bpftool+ctypes，micro 保留 C++。报告：`bpftool_replacement_feasibility_20260329.md`。 |
| **630** | **llvmbpf round-trip POC** | ✅ | **BPF → llvmbpf lift → opt -O2 → llc -march=bpf → BPF_PROG_LOAD 通过 kernel verifier ✅**。identity（-O0）不 work（`indirectbr` crash），必须 -O2 才能 canonicalize IR。测试程序：simple XDP（无 map）。下一步：有 map_lookup 的程序 + 常量注入。报告+脚本：`docs/tmp/20260329/llvmbpf_roundtrip_poc/`。 |
| **631** | 大规模代码清理（2026-03-29） | ✅ | **C++ -4033 行**（删 batch_runner/daemon_client/json_parser/attach_trigger/prepared state，保留 test-run+llvmbpf）。**Python -5994 行**（删 batch plan/guest-host 双路径/trigger 命令/compile_only）。**Daemon -11 行**（已干净）。E2E 清理（旧 schema/兼容路径）。macro_corpus.yaml 统一 measurement: app_native/test_run。报告：`cpp_cleanup_report`/`python_cleanup_report`/`python_cleanup_review`/`e2e_review_and_cleanup`/`daemon_rust_cleanup`（均在 `docs/tmp/20260329/`）。 |
| **632** | 新 benchmark 架构实现 | ✅ | `corpus/driver.py` + `runner/libs/app_runners/bcc.py` + `runner/libs/bpf_stats.py` + `make vm-corpus-new`。**VM 验证通过**：BCC app_native exec_ns **3347ns**（baseline）→ **3564ns**（rejit）；test_run（bpftool）exec_ns **81→57ns（1.42x）**。65 pytest pass。报告：`new_orchestrator_implementation_20260329.md`。 |
| **633** | llvmbpf bulk round-trip 170 objects | ✅ | **962 programs**：lift **556（57.8%）**→ lower **309（55.6%）**→ verifier **7（2.3%）**。4292 map_lookup sites。主失败：`last insn is not an exit or jmp`（subprog boundary）。报告：`llvmbpf_bulk_roundtrip_report_20260329.md`。 |
| **634** | llvmbpf round-trip 四轮修复 | ✅ | **Round 1**：`last insn` 清零，lift 556→779，verifier 7→16（3.9%）。**Round 2**（.bpf.o 路径）：map relocation repair，verifier **157/413（38.0%）**。**Round 3**：GET_ORIGINAL+REJIT 正确路径打通，blocker 是 llvmbpf userspace 栈模型。**Round 4**：kernel_compatible_mode（512B stack + align 8 + implicit extern helper）。**BCC 17/17 全过**。**Tracee 9/33**（iter4）：kernel poke_tab 校验放宽（允许 insn_idx 变化）解决 tail-call EINVAL。剩余 24 fail：15 E2BIG + 8 ENOSPC + 1 verifier EPERM。-O1/Os/Oz 对 E2BIG 无帮助，需要 code-size 降低。报告：`llvmbpf_roundtrip_fix_report`、`llvmbpf_map_relocation_fix_report`、`llvmbpf_map_relocation_vm_results`、`llvmbpf_rejit_roundtrip_poc`、`llvmbpf_kernel_stack_fix_report`（均在 `docs/tmp/20260329/`）。 |
| 635 | 更多 app runner 实现 | ✅ | 6 个 runner（bcc/tracee/katran/tetragon/bpftrace/scx）。Commit `86bc953`。 |
| **636** | 全面 benchmark 架构 review | ✅ | 5 CRITICAL + 14 HIGH + 10 MEDIUM + 2 LOW。核心：bpftool loadall 残留、corpus repeat 没跑、rejit.py prog_fds 丢弃、大量 object-centric 死代码、silent fallback。报告：`strict_final_review_20260329.md`。 |
| **637** | **新架构 corpus + E2E 端到端验证** | ✅ | corpus suite driver 重写完成（loader-instance lifecycle）。大规模清理 **-21462 行**（`579c081`）。import cycle 修复 5/5（`2dd43c8`）。新增 9 个 app runner。残留清理+Tracee重构（`3101592`）。**2026-04-02 本地 VM 重跑完成**：`make vm-corpus` **20/20 app ok**、applied-only / all-comparable geomean **1.033x**、applied sample **61**；`make vm-e2e` **6/6 ok**。新 YAML schema 已落到 `macro_apps.yaml`，object-centric 规划不再是主线。报告：`corpus_app_native_coverage_and_e2e_dedup`、`benchmark_framework_redesign`、`benchmark_yaml_redesign`、`corpus_e2e_deep_review`（均在 `docs/tmp/20260329/`）。 |
| 638 | 新 kinsn 调研（6 组） | ✅ | 全部完成。结论：(1) POPCNT/CLZ/PDEP/PEXT/SHRX — **❌ 不做**（corpus 无 site）；(2) ARM64 CCMP — **✅ 值得做**（74 site），MADD/UBFX 低优先级；(3) Prefetch — **✅ 值得做**（17391 map_lookup site，需 PGO），NT store — ❌ 不做；(4) CRC32 — ⏸ 不做默认 pass（loxilb 2 site）；(5) RDTSC + ADC — 待评估；(6) PAUSE/YIELD — ❌ 不做（kernel 已有）。报告均在 `docs/tmp/20260329/`：`bit_ops_kinsn_research`、`arm64_kinsn_research`、`memory_hints_kinsn_research`、`crc32_kinsn_research`、`rdtsc_adc_kinsn_research`、`pause_yield_kinsn_research`。 |
| **639** | **PGO 方案设计 + LBR 验证** | ✅ | **Host-side LBR 对 guest BPF 尚未验证可用**（5s 窗口 IP/branch 命中数=0）。推荐 **Hybrid PGO**：(1) profiler.rs 保留为 hotness collector；(2) sampling 零侵入发现（IP ~+1.37%, LBR ~+1.83%）；(3) selective instrumentation 给 hot subset 补精确 per-branch 数据。优先 BranchFlipPass，PrefetchPass 等 SPE/precise memory。**AWS**: t4g 有 SPE 硬件但 Nitro 是否暴露需实测，t3 有 LBR 但 guest 是否可用需实测，bare metal 才无限制。报告：`bpf_pgo_design_20260329.md`。 |
| **640** | **Strict review 修复（删除为主）** | ✅ | **-2865 行**。删除：x86/arm64 远端 benchmark 脚本（bpftool loadall）、catalog.py/object_discovery.py/commands.py（object-centric 死代码）、results.py object-centric 函数、过时测试（test_micro_driver/test_runner_results）。修复：corpus repeat 真跑、rejit.py prog_fds 保留、tracee_support fallback→fail-fast、scx_support ulimit fail-fast。二次 review 确认全部落地，无误删。pytest **71 passed**，daemon-tests **535 passed**。报告：`strict_review_fixes_20260329.md`、`strict_review_second_pass_20260329.md`。 |
| **641** | **llvmbpf E2BIG root cause 分析** | ✅ | **E2BIG 根因**：LLVM BPF backend lowering 不紧凑，净增 **9352 insns**（1.192x）。67.3% stack spill/reload（+6291）、38% helper marshaling（+3550）、22% scalarization（+2053）。opt -O2 反而比不优化小 ~2x，-Oz 无增量。真实 limit 是 `prog->pages` page-budget（非 1M insn limit）。**ENOSPC 根因**：verifier log buffer exhaustion（log_level=2 的 16MiB 不够），不是 code-size。报告：`llvmbpf_e2big_root_cause_20260329.md`。 |
| **642** | **llvmbpf Tracee 修复** | ✅ | **ENOSPC 8→0**（log_level=0 修复）。ok **9→10/33**（lkm_seeker_proc_tail 新通过）。Full set 37 程序：**13 ok / 23 E2BIG / 1 EPERM**。Phase 2 尝试 -regalloc=greedy/-Oz/--disable-loop-unrolling/noalias 全部无效（通过率不变）。**结论**：flag 调节收益为零，剩余 E2BIG 需要 backend lowering 定向减胀或 size-aware skip gate。报告：`llvmbpf_tracee_fix_20260329.md`。 |
| **643** | **Pass split + kinsn 开关实测** | ✅ | 修复 `--no-kinsn` 假关闭（现已真实生效），完整跑三组：`full+kinsn`、`map_inline,const_prop,dce+kinsn`、`map_inline,const_prop,dce+no-kinsn`。**结论**：`kinsn` 不是通用默认项，关掉后多数 live E2E 变好，但 corpus 从 **0.984x → 0.949x** 变差；`map_inline` 也不是无效，只是尚未做 isolated ablation，不能单独归因。artifact 元数据同步补齐 launcher identity / stale recovery / per-tool pass provenance。报告：`docs/tmp/20260331/pass_split_analysis.md`。 |
| **644** | **Apply-only 口径收敛 + full-pass 重跑** | ✅ | benchmark 默认 pass 集恢复为当前全部 in-scope performance passes（不含 `branch_flip` / 安全 pass）；BCC `execsnoop` 的单独 `rejit_passes` 缩窄配置已删除。E2E / corpus 报告统一改为 **“apply 多少报告多少”**：site totals 只来自 daemon 实际 apply 结果，不再把 scan candidate counts 当最终数字。**重跑结果**：bpftrace **5** 个脚本有 applied sites、总计 **33**；BCC **9** 个工具、总计 **961**；SCX **13** 个程序、总计 **359**；Tetragon `execve_rate=7`、`event_execve=8`。验证：`make check`、`make vm-selftest`、`make vm-test`、`make vm-negative-test`、`make vm-corpus`、`make vm-e2e`、`make vm-micro-smoke`、`make vm-micro` 全通过。**备注**：本轮 `vm-micro` guest 仍提示 governor unknown / turbo on / no CPU affinity，适合回归确认，不应当作为最终噪声受控绝对性能数字。 |
| **645** | **Private-stack 覆盖迁移 + 2026-04-03 全量验证** | ✅ | 将 brittle 的 upstream `verifier_private_stack` 覆盖保留在默认 deny-list 外，同时把关键行为迁移到 repo-owned tests：新增 `tests/unittest/rejit_private_stack.c`，并在 `tests/unittest/rejit_kinsn.c` 增加 kinsn 临时寄存器保存回归；`upstream-selftests-build` 固定 LLVM 20 工具链，避免 host 默认 LLVM 版本漂移。内核侧仅保留必要的 x86 JIT 修复（`vendor/linux-framework` commit `a1b8bade1`），主仓库提交 `e3a9de1`。**2026-04-03 验证**：`make all`、`make check`、`make vm-test` 全通过。 |
| **647** | **工程化 review + 清理（2026-04-07）** | ✅ | **两轮清理合计 -2435 行**。第一轮（测试）：删除 BCC per-tool `rejit_passes`、重复 BPF stats（合并到 `bpf_stats.py`）、死 integration 脚本（`vm_comprehensive.sh`/`vm_daemon_live.sh`/`hold_bpf_prog`）、重复 SCX repro、`rejit_daemon_e2e.c`、纯 contract 测试；恢复并改写 `scx_bad_rejit_replay.c` 为自包含 negative test（自建 map + good prog → 提交 bad bytecode → 验证 verifier 拒绝）；简化重复 mock 测试和 verifier rejection 覆盖；对齐 Makefile 与 §6.4（`vm-selftest`/`vm-negative-test`/`vm-micro-smoke`）。第二轮（生产代码）：删 11 个未使用 app runner（calico/coroot/datadog/kubearmor/loxilb/suricata/tubular/xdp-tools/xdp-tutorial/libbpf-bootstrap/systemd）+ adapter 函数、去重 `geometric_mean`、删死 Makefile corpus-build targets。**验证**：python 104 pass / daemon 535 pass / negative 编译通过。**VM 重构设计**：`docs/tmp/vm_management_refactor_design_20260407.md`（4 phase：合并重复 → manifest 迁 Python → Executor 抽象 → 统一 Python 编排；当前不动，论文提交后执行）。Commits：`d253445d`、`a849f182`。 |
| **646** | **bpfopt 独立优化工具链（2026-04-07, 2026-04-26 收敛）** | ✅ | 2026-04-07：从 daemon 提取 pass 代码到独立 workspace。2026-04-26：workspace 收缩并重命名为 `bpfopt/`，只保留 `bpfopt-core`（pass library）和 `bpfopt`（CLI）；删除 `kernel-sys`、`bpfget`、`bpfverify`、`bpfprof`、`bpfrejit`、`bpfrejit-daemon` stub crate。**边界收敛**：`bpfopt-core` 继续保留 verifier-state parser 供 `const_prop` / `map_inline` 使用，但移除了 per-pass verify/rollback 和 REJIT transport 状态，kernel-facing verify/rejit/profiler/syscall/daemon 逻辑继续留在 `daemon/`。设计文档：`docs/tmp/bpfopt_design_v3.md`。Benchmark review：`docs/tmp/benchmark_status_review_20260403.md`。Commits：`ea92e14`、`8b66471`。 |
| **648** | **Runner micro suite 独立入口（2026-04-11）** | ✅ | Phase 1 完成：新增 `runner.suites.micro` CLI，KVM micro 分支直接生成 `python3 -m runner.suites.micro ...`，不再经旧统一入口调用 micro driver；旧入口临时保留给 test/corpus/e2e。复用现有 `micro/driver.py` 与 `runner/libs` artifact/path helper。验证：`python3 -m runner.suites.micro --help`、`python3 -m runner.suites.micro --arch x86 --samples 1 --warmups 0 --inner-repeat 1 --list`、`make check`。 |
| **649** | **Runner corpus suite 独立入口（2026-04-11）** | ✅ | Phase 2 完成：新增 `runner.suites.corpus` CLI，封装旧 corpus 分支的 runtime env、container、bpf_stats、SCX/Katran artifact 校验和 `corpus/driver.py` 调用逻辑；KVM corpus 分支直接生成 `python3 -m runner.suites.corpus ...`，不再经旧统一入口。验证：`python3 -m py_compile runner/suites/corpus.py runner/libs/kvm_executor.py`、`python3 -m runner.suites.corpus --help`、`make check`。 |
| **650** | **Runner e2e/test suite 独立入口（2026-04-11）** | ✅ | Phase 3+4 完成：新增 `runner.suites.e2e` 与 `runner.suites.test` CLI，封装旧 e2e/test 分支的 runtime env、container、bpf_stats、SCX/Katran artifact 校验、kinsn module 加载、unittest/negative/full/fuzz 模式和 `e2e/driver.py` 调用逻辑；KVM micro/corpus/e2e/test 四个 suite 均直接生成 `python3 -m runner.suites.* ...`，不再经旧统一入口。验证：`python3 -m py_compile runner/suites/e2e.py runner/suites/test.py runner/suites/micro.py runner/suites/corpus.py runner/libs/kvm_executor.py runner/libs/run_contract.py runner/libs/workspace_layout.py`、`python3 -m runner.suites.e2e --help`、`python3 -m runner.suites.test --help`、`make check`。 |
| **651** | **Runner 旧 suite 框架删除（2026-04-11）** | ✅ | Phase 5 完成：AWS 远端 `run-workspace` 改为直接分发到 `runner.suites.micro/corpus/e2e/test`；删除旧统一入口、guest prereq 层和 prereq contract 层；KVM 删除旧 fallback；`runtime_path_value` 收敛到 `workspace_layout.py`；清理 `case_common.py` 未使用 helper 和残留文档引用。验证：见本轮 `py_compile` 与 `make check`。 |
| **652** | **Runner Makefile 参数传递简化（2026-04-11）** | ✅ | Phase 6 完成：`RunConfig` 删除 benchmark/test suite 参数字段，保留 executor/prep 所需字段；新增独立 `suite-args.json` 旁路，KVM/AWS executor 直接把 Make/env suite 参数传给 `runner.suites.*`；`Makefile` VM 入口改为 `-- suite-args` 显式传参；删除 run_contract 里的 suite 参数映射、远端 command contract 逻辑和 app runner `required_remote_commands` 残留。验证：`python3 -m py_compile ...`、`make check`。 |
| **653** | **AWS x86 runtime image e2e + corpus 验证（2026-04-18）** | ✅ | 复用 `.cache/container-images/x86_64-runner-runtime.image.tar`，未重建 image。`make aws-e2e RUN_TARGET_ARCH=x86_64` **6/6 PASS**；`make aws-corpus RUN_TARGET_ARCH=x86_64` **20/20 app ok**，corpus status `ok`。AWS `t3.large` / `us-east-1`，kernel `7.0.0-rc2`。报告：`docs/tmp/aws-x86-e2e-20260418/summary.md`。 |
| **654** | **Wave 1 silent fallback removal（2026-04-21）** | ✅ | 删除 `rejit.py` / daemon / AWS executor / corpus+e2e driver 中的 silent fallback，改为 strict schema/error propagation；KVM 复验：`make vm-e2e` **ALL PASSED**，`make vm-corpus` status `ok`。KVM x86 corpus `applied_sample_count` **10→12**，`sample_count` **10→12**，`no_programs_changed_in_loader` **38→36**。报告：`docs/tmp/wave1-fallbacks-20260421/summary.md`。 |
| **655** | **Wave 1.5 AWS x86 复验（2026-04-21）** | ✅ | 基于 `0df38b7f` 复跑 AWS x86：`make aws-e2e RUN_TARGET_ARCH=x86_64` **ALL PASSED**；`make aws-corpus RUN_TARGET_ARCH=x86_64` status `ok`。无代码修复；复用 `.cache/container-images/x86_64-runner-runtime.image.tar`。AWS x86 corpus 相对 pre-wave1 baseline `aws_x86_corpus_20260421_200048_542429`：`applied_sample_count` **8→10**，`sample_count` **8→10**，`no_programs_changed_in_loader` **39→36**，方向与 KVM Wave 1 复验一致（applied ↑，excluded ↓）。报告：`docs/tmp/wave1.5-aws-x86-verify-20260421/summary.md`。 |
| **656** | **Unused contract surface verification（2026-04-21）** | ✅ | 复核 review §5 后，删除 corpus wrapper 的死 `--warmups` surface（`runner.suites.corpus` parser、`runner.libs.suite_args` emission、root `VM_CORPUS_SUITE_ARGS`），删除 root `Makefile` 中未使用的 `PROFILE` / `KALLSYMS_EXTRA_PASS`，并确认 `aws-e2e` / `aws-corpus` 仍是 live AWS 单 suite 入口，**保留**。验证：`make -n vm-e2e`、`make -n aws-e2e RUN_TARGET_ARCH=x86_64`、`python3 -m py_compile runner/suites/corpus.py runner/suites/e2e.py runner/libs/suite_args.py`。报告：`docs/tmp/unused-surface-20260421/summary.md`。 |
| **657** | **AWS x86 runtime image 打包修复（2026-04-18）** | ✅ | `668ddae9` 补 Makefile `aws-e2e` / `aws-corpus` targets 与 `aws_executor.py` 命令实现；`6099e04e` / `1c8da845` 把 tracee musl runtime 库（loader path）打进 runtime image；`94da7880` bcc kheaders cache 跨 run 共享、per-run scratch 干净；`b3cc3bd8` 记录 AWS x86 runtime 验证补遗。配合 #653，AWS x86 image 不再缺 musl / kheaders。 |
| **658** | **arm64 kinsn "Invalid module format" 修复（2026-04-18）** | ✅ | `0133184c` 每次都从当前 image tar 重新提取 arm64 host kernel artifact，避免 host 侧残留与 image 内 kernel 不匹配导致 insmod EINVAL。配套 5 份 docs/tmp summary 一并入 git。 |
| **659** | **Dead code cleanup：corpus/e2e driver 不可达路径（2026-04-21）** | ✅ | 删 `--rejit-passes` CLI flag（`c6e9815c`）、`e2e/driver.py` 不可达 empty-rejit-passes fallback（`a1f2fbc2`），保留 reachable `requested_rejit_passes` fallback 分支（`bf29e010`，codex 自我 review 防止误删）。总结：`3519116f`。 |
| **660** | **Wave 2 silent fallback sweep（2026-04-21）** | ✅ | 删 redundant `effective_enabled_passes_by_program` 重建（`04d5b2bd`，daemon 不需要传该字段，runner 直接从 `config.enabled_passes - policy.exclusions` 推导）；清理 `katran.py` request-as-truth 模式（`17512ed5`）。总结：`cb6b5809`。 |
| **661** | **AWS/KVM image rebuild 统一到 make dep tracking（2026-04-21）** | ✅ | `52f2ab8c` 把 `local_prep_targets()` 的 AWS short-circuit（`is_file() → skip`）删掉，让 AWS 和 KVM 共享同一条 runtime image tar target，`make` 自动按依赖重建，不必要的重复构建被 Make 文件时间戳拦住。`10c1a392` runtime image 外路径也按 target_arch 分离 `kinsn_module_dir` / `kernel_modules_root`。`b2ea5e03` 补 `vendor/linux-framework` submodule 条目。总结：`ade26353`。 |
| **662** | **Wave 1.5 AWS arm64 复验（2026-04-21）** | ✅ | `make aws-e2e RUN_TARGET_ARCH=arm64` **ALL PASSED**（tracee/tetragon/bpftrace/scx/bcc/katran 6/6）；`make aws-corpus RUN_TARGET_ARCH=arm64` status `ok`，`aws_arm64_corpus_20260422_044304_037607` **20/20 app ok**，applied-only geomean **0.986x**，applied sample 10。相对 pre-wave1 baseline `aws_arm64_corpus_20260421_213547_871838`：`applied_sample_count` **16→10**、`no_programs_changed_in_loader` **37→36**；applied 回落全部来自 `tracee/default` — 后 wave1 只报告两个 raw-syscall tracee program（与 AWS x86 post-wave1 一致），不是 rejit 问题。报告：`docs/tmp/wave1.5-aws-arm64-verify-20260421/summary.md`。commit `b9c807f0`。 |
| **663** | **2026-04-21/22 三目标 corpus authoritative 重跑** | ✅ | 单会话跑完 KVM x86 / AWS x86 / AWS arm64 三套 corpus，全部 20/20 app ok：`x86_kvm_corpus_20260421_232916_947372`（30 samples，all-comparable geomean **1.010x**，applied sample 12）；`aws_x86_corpus_20260422_012001_472335`（1 sample，**0.983x**，applied sample 10）；`aws_arm64_corpus_20260422_044304_037607`（1 sample，**0.986x**，applied sample 10）。三目标 `no_programs_changed_in_loader` 统一 **36**。该 reason 的真实语义见 #664 调研（不是 bytes same-size gap）。 |
| **664** | **`no_programs_changed_in_loader` 语义 + program count 调研（2026-04-21）** | ✅ | 代码级结论：(a) reason 判定代码 `corpus/driver.py:471-540` 只看 daemon semantic signal（`summary.program_changed` / `total_sites_applied` / `passes_applied`），**根本没比较 bytes_jited/xlated/JIT image hash**。反例：`scx/rusty:rusty_exit_task` baseline/rejit 都 `bytes_jited=232` 但 `changed=true, comparable=true`。(b) 真实含义是混了三类的 observability bucket：0 site 命中 + pass 命中但 verifier 全 rollback（`tetragon/default:event_execve`：map_inline 7 sites rolled_back + const_prop 1 site rolled_back → `program_changed=false`）+ apply 成功但最终 program_changed=false。**非 apply bug，是 taxonomy 过粗**。(c) ~48 program 总量符合 app-centric 设计（旧口径 469 obj / 2019 prog 是 object-centric，非同一量级）：`katran=1` 按设计（`KatranRunner.start()` 只返回 balancer ingress）；`tracee=2/3` 是 FD-owned discovery undercount（`runner/libs/agent.py:90-141` attach 完关 fd 就不见了，历史 VM 曾测 44 个）；`tetragon=1` 是 corpus runner adapter 没传 e2e 的 `target_programs/apply_programs` config（`runner/libs/app_runners/__init__.py:63-69` vs `e2e/cases/tetragon/config_execve_rate.yaml:11-17`）。**建议动作**（未实施）：拆 exclusion reason 为 4 子类；Tracee runner 加 global `bpftool prog show` before/after diff 模式；Tetragon corpus 路径复用 e2e config。报告：`docs/tmp/no-changed-in-loader-investigation-20260421/summary.md`。 |
| **665** | **KVM x86 corpus rerun after `_configure_program_selection` TypeError fix（2026-04-22）** | ⚠️ | 失败 rerun `x86_kvm_corpus_20260422_054946_580134` 的根因是 `567df095` 删除 `_configure_program_selection()` 的 `measurement_mode` 形参时漏改 `run_suite()` active-session 调用；最小修复是在 `corpus/driver.py` 删掉 stray `measurement_mode=` kwarg。单 app 复验：`bcc/capable` `x86_kvm_corpus_20260422_063229_887355` ok，`bpftrace/tcpretrans` `x86_kvm_corpus_20260422_063749_285833` ok，attach failure 未复现。两次完整 `make vm-corpus SAMPLES=30` rerun 均 `20/20 app ok`：`x86_kvm_corpus_20260422_064321_184850`（all-comparable geomean **1.091x**，applied sample 16，`no_programs_changed_in_loader` 37）和 confirmatory `x86_kvm_corpus_20260422_073105_905677`（**1.105x**，16，37）。相对 authority run #663 的 `1.010x / 12 / 36` 仍偏高；主要漂动为 `tetragon/default` `1/0 -> 6/4`、`bpftrace/runqlat` `-5.9%`、`bpftrace/tcpretrans` `-15.4%`。报告：`docs/tmp/kvm-x86-rerun-20260421/summary.md`。 |
| **666** | **Wave 3 silent-failure review（2026-04-22）** | ✅ | 1 CRITICAL（runner 把 `applied` 当 `changed` 用）+ 4 HIGH + 2 MEDIUM + 1 LOW。报告：`docs/tmp/wave3-silent-failure-review-20260422/summary.md`。已在 Round 3/4/5/6 全部修完。 |
| **667** | **Round 2-6 系统性删除 + Wave 3 修复（2026-04-22）** | ✅ | 六轮清理累计净删 ~600 行源码（38 files / +705 / -1303）：Wave 3 修 silent-failure 8 项；Round 2 删 program selection / threshold / applied_any 家族 / legacy_total_sites / workload_kind / loader-FD dup；Round 3A schema 扁平化（`changed`/`counts`/`pass` alias/`requested_prog_ids` rename/pending kinsn metadata overlay）；Round 3B 删 tracee strict parser accommodation/9 个 dead e2e override/tetragon 双 setup/katran `_select_program`/`find_bpf_programs`/Makefile 死变量；Round 4D 9 项（`_run_app`死函数/write-only artifact 字段/`get_app_runner` alias/tetragon workload wrapper 死壳/`scan_kwargs`+`setup_state`+`metadata` 死字段/`prepare_daemon_session` 冗余）；Round 4E daemon 12 个 pass 文件 31 个 PassResult scaffold 去重；Round 4F 合并 `OptimizeOneResult`/`ServeOptimizeResponse`；Round 5 R1-R9（`app_name` plumbing/`sites`+`counts` 双 shape/3 个 setup_result skeleton/dead import/`BCCWorkloadSpec.name`/katran args.workload/CorpusAppSession.prog_ids/target+apply_prog_ids 合并 + SCX live-id 内部化）；Round 6 修 B1 tracee event file minimal structured contract (parse error counting + inode/size reopen + partial-line buffer + verify_phase delta check)/M1 suite cleanup warn/tetragon adapter 显式传 setup_result/删 SCX+tracee 死字段。VM 验证：vm-e2e smoke 6/6 PASS；vm-corpus SAMPLES=1 20/20 ok，applied=23，`no_programs_changed_in_loader`=38。B1 首轮 VM 捕获 4 个 silent-skipped parse errors，证明 Round 3B 纯 silent-skip 确实在丢事件。报告：`docs/tmp/{wave3-fixes,delete-program-selection,round2-cleanup,round3-core,round3-cases,round4-python,round4-daemon,round4-investigate,round5-cleanup,round6-fixes,round5-vm-verify,round6-vm-verify,round34-verification,behavioral-review,broader-deletion-review,complexity-review,delete-verification,program-discovery-review,bpftrace-bcc-threshold-refresh}-20260422/summary.md`。 |
| **668** | **Round 7 taxonomy split + prod coverage expansion（2026-04-23）** | ✅ | 主要工作：X taxonomy split（`zero_sites_found` / `all_sites_rolled_back` / `applied_but_identical` / `no_passes_requested`）、map_inline fp-alias 放宽、Katran healthcheck + `xdp_root` 接线、6 个 workload variant + `macro_apps.yaml` 切换、fail-loud/timeouts cleanup。最终 KVM authority：total programs **122→124**，`applied_sample_count` **23→26**，X exclusion reason 的 4 个子类 distribution 可见。VM 验证：`vm-e2e` run `133dad38` **6/6 PASS**；`vm-corpus` run `56c38295` **20/20 ok**。报告：`docs/tmp/{taxonomy-split-20260423,impl-daemon-passes-20260423,impl-product-config-20260423,workload-coverage-20260423,app-attach-undercount-20260423,impl-fix-20260423,impl-review-20260423,pass-trigger-20260423,recovery-vm-20260423,final-vm-verify-20260423}/summary.md`。 |
| **669** | **Round 8 彻底删除 filter/select/gate，强制两阶段测量（2026-04-23）** | ✅ | 删除 Tracee event 子集、Tetragon synthetic/static policy pack、`--tracing-policy-dir`、BCC/bpftrace/SCX case 子集、corpus `--filter` / `_matches_filter`、e2e `--e2e-cases` / `SUITE_DEFAULT_E2E_CASES` 与 post-ReJIT gate；所有 app 现在都无条件执行 baseline + post-ReJIT 两阶段测量，Round 7 taxonomy 只保留为 apply 结果分类；corpus lifecycle 同步修成“启动前记录 `before_prog_ids`、共享 baseline/apply 前各 refresh 一次 live prog_ids、stabilization 从 exact-set 改为 count-stable”；Tetragon 改成纯 native default CLI，预期只暴露 ~8 个 native programs，而不是此前 synthetic ~35；源码层面净删 **24 files / +266 / -994 = -728 LOC**（10 份 summary 文档单独在 docs commit）；主 codex 在 VM poll 过程中曾短暂回写 tetragon policy pack，已重新删除；commit 时未跑 VM 实测，仅确认 `make check`、`make -n vm-corpus`、`make -n vm-e2e` 通过（VM smoke 验证见 #670）。报告：`docs/tmp/{delete-filters-all-programs,delete-cli-args,review-delete-filters,round2-delete-subset-selection,program-coverage-gaps,fix-corpus-lifecycle,delete-post-gate,final-review,rename-vs-delete-audit,tetragon-revert,commit-round8}-20260423/summary.md`。 |
| **670** | **Round 8 后续审计 + VM smoke 验证（2026-04-23，已完成）** | ✅ | Round 8 commit 后并行派出 4 个 codex 做独立验证与后续审计，现已收口：(a) `b71j00s3d` **VM smoke verify** —— 仍在进行中，持续跑 `make vm-e2e` + `make vm-corpus SAMPLES=1`，当前已观测到 SCX `scx_20260423_233939_252543` 13 programs / applied sites=2 (extract) / baseline+post 两阶段完成；(b) `bl7qdjynz` **daemon Rust 审计** —— 已完成，确认 `daemon/src/commands.rs:533-547` 的 `orig_insns.is_empty()` short-circuit 应改为 loud-fail，并已落地 `358da2d5` / `f0692904` / `a95c6466`；(c) `b6cjwaqlz` **设计整洁性审计** —— 已完成，评分 **3/5**，3 个 BLOCKER 均已在后续 #672 修掉：BLOCKER 1 `f545534b`、BLOCKER 2 `ff14c7a1`、BLOCKER 3 `67a851b9`；(d) `bvhfeigla` **功能清单 + 冗余诊断** —— 已完成，盘点出的 🔴 冗余 5 条已在后续 #672 删除。报告目录：`docs/tmp/{round8-vm-smoke,daemon-rust-audit,design-cleanliness-audit,feature-inventory}-20260423/`。 |
| **671** | **Lazy-rename Round 2 深度清理（2026-04-23）** | ✅ | 依据 `rename-vs-delete-audit`/`final-review`/`daemon-rust-audit` 再扫一轮 live code，先修两条已知问题：`1b81f3c3` 把 `e2e/cases/tetragon/config_execve_rate.yaml` 改回 `config.yaml` 并更新 `DEFAULT_CONFIG`；`6d62a537` 删除 `measurement_mode` / `corpus_measurement_mode` 全链路死抽象。随后 `3d739442` 继续删新发现的 lazy shells：`selected_apps -> app_count`、`get_app_runner(workload=None)` 与 runner `workload_spec` 死 fallback、bpftrace `script_name|script_path` 双入口和单用 `suite_scripts()`、Tracee/Tetragon 假 `exec_storm` 默认值、以及 5 个 e2e case 顶部不再读取的 output 常量。验证仅跑 `python3 -m py_compile`、`make check`、live-code grep（`measurement_mode` / `config_execve_rate` 均 0 命中），未跑 `make vm-*`。当前 `git diff --shortstat`：`20 files changed, 73 insertions(+), 407 deletions(-)`。报告：`docs/tmp/lazy-rename-round2-20260423/summary.md`。 |
| **672** | **Round 8 post-cleanup：daemon orig_insns + BLOCKER 2/3 + 功能冗余 + 终点小杂项 + corpus lifecycle 合并（2026-04-23）** | ✅ | 承接 #670 的 daemon `orig_insns` 审计/修复后，Round 8 commit 之后除 #671 外的 post-cleanup 继续收口：**BLOCKER 2+3** 由 `67a851b9` / `ff14c7a1` 落地，`make check` 改为 `find`-based 自动覆盖全 live `.py`，`SAMPLES` / `WARMUPS` / `INNER_REPEAT` 的单一权威收敛到 `runner/libs/suite_args.py` 的 `MICRO_BENCHMARK_DEFAULT_*`；**功能冗余 5 删** 由 `e2cb3ed6` / `2cc827bb` / `2a2e77d1` / `babcb9b1` / `75c9eba4` 落地，删除 `full` test mode alias、wrapper-hidden `--rejit-passes`、workload 3 alias（`minimal_syscall` / `mixed_system` / `system_telemetry_mix`）、`--output-md` 残留、`micro/compare_results.py` 整文件和 `micro/README` 里 stale `PROFILE=...` 引用；**终点小杂项** 由 `18f36cc6` / `8d462379` / `6f475773` / `3bee4426` 收口，删 `_normalize_test_mode` / `SuiteSelection` 薄 wrapper、`AppRunner.program_fds` 空接口、`ROOT_DIR` 重复定义、Makefile 装饰性 comment 分隔符和 help 里的 stale `--rejit-passes` advertise，`43c6e581` 另把 `daemon-rust-audit` / `design-cleanliness-audit` / `feature-inventory` 3 份未跟踪审计报告追进 git；**BLOCKER 1 corpus lifecycle 合并** 由 `f545534b` 完成，`runner/libs/case_common.py` 提供共享 multi-session lifecycle，`run_case_lifecycle()` 改走单-session 包装，`corpus/driver.py` 删除第二套手写 state machine，仅保留 corpus grouped apply / slice 回填，提交集 shortstat `+345 / -395 = -50 LOC`；累计本组 commit 约 **13** 笔，源码净删约 **-130 LOC**，所有变更均过 `make check`，未跑 VM 实测。报告：`docs/tmp/{blocker23-fix,redundancy-cleanup,final-cleanup,corpus-lifecycle-merge}-20260423/summary.md`。 |
| **673** | **Round 8 post-cleanup 第二大组：activity gate 删除 + smoke 删除 + tetragon upstream policies + result/cmd 精简 + fallback purge（2026-04-23/24）** | ✅ | 紧接 #672 之后的第二大组清理继续把 Round 8 后处理收口：`e252866d` 删除 Tracee `require_program_activity` config key 与 gate 参数链（`+6/-29`）；Tetragon 由 `7c81db17` / `553e38b8` / `f4c404da` 从 `cilium/tetragon@38a65437a875246d31e13347ebf6a3c0184d4b6b` 下载并 pin 住 18 份真实 `TracingPolicy` YAML 到 `e2e/cases/tetragon/policies/`，`sync_upstream_policies.sh` 负责同步，runner 恢复 `--tracing-policy-dir`，runtime Dockerfile 也将其 `COPY` 进 image，因此 AWS/KVM 共走同一路径，预期 tetragon program 量由约 `7` 升到约 `292`；`34b0597a` / `4cd2c4c9` / `cdfae346` 彻底删除 `E2E_SMOKE` / `--e2e-smoke` / `--smoke` / `vm-micro-smoke` / `VM_MICRO_SMOKE_SUITE_ARGS` 与 case YAML 的 `smoke_*` 字段，默认即最小参数路径（`vm-corpus SAMPLES=1`，e2e 默认 `10s/5s` 量级），大样本改为显式 `SAMPLES=30` 覆盖，提交集 `+44/-127`；`24294456` / `270689c4` / `ca4c88ef` 删除 tracee/tetragon/scx 整条 activity-gate 链，含 preflight phase、`program_activity` 数据链、`total_run_cnt <= 0` loud-fail 与 `_zero_drops` / `active_count` / `application_overhead` 派生字段，`bd35d164` 记录文档，合计 `+130/-353 = -223 LOC`，而 bcc/bpftrace/katran 本来就没有该 gate；repo-wide review round 2 由 `f86d8b97` / `0f0eadeb` / `be74a91b` / `2d555d5f` / `b604878b` 删掉 suite summary plumbing、bpftrace fallback、BCC `policy_context` 空壳和 SCX `command_used` 单值 mode（`+99/-135`）；结果与命令字段继续精简于 `d3988906` / `68d837a9` / `7e5ff83d` / `8ef8a196`，分别 prune write-only result payload fields、去掉 bpftool pretty-json flags、canonicalize suite artifact args、缩 runtime container env/mounts；fallback/compat shim purge 由 `ccd8debe` / `f8bd2575` / `16ecb21d` / `7862b308` 删除 Python compat shim 与 silent fallback、daemon Rust defensive fallback、补 audit 文档并移除 corpus `prog_type_name` 最后 consumer；全组合计约 **25** 笔 commit、源码净删约 **-600 LOC**，验证上 `make check` 全过、`cargo test` **499 passed**，且 live code `grep 'preflight|program_activity|_zero_drops|active_count|application_overhead|smoke|require_program_activity'` 为 **0** 命中（仅 Round 8 首轮已判定的 BCC Python UAPI compat shim 属 load-bearing 例外）；本组**未跑 VM 实测**，因为 `b71j00s3d` 仍在独立迭代 Tracee collector bug。报告：`docs/tmp/{tracee-activity-gate-delete,tetragon-upstream-policies,delete-smoke-config,delete-all-activity-gates,repo-wide-review-round2,activity-review-fallback-purge}-20260424/summary.md`，另 `bst3pkgya` 未单独写 summary，以 commit message 记录。 |
