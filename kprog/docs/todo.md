# kprog TODO

唯一的待办清单。运营者原话：2026-11-08 “这个也要记录 todo”“要有 todo”；2026-11-09 “都有 todo list 了吗? 确保都有”。

规则：每完成一项，负责的 lane 在同一个提交里把这一行改成 `[x]` 并写上提交号，然后 push。新发现的事项直接加到这里。证明数字以 `kprog/results/kprog_verification_20261107/coverage.tsv` 为准。

状态基于 2026-11-09 13:05 UTC。

## 1. 性能（目标：六应用几何平均 native/JIT 1.20x–1.40x，来自原生代码）

- [x] 框架恢复为 05-29 定义，只保留 `native-sim`→`kprog` 和 `module/`→`kinsn/module/` 两处目录改名（191f9dc1d、96d09c17b）。
- [ ] **R** 用 05-29 完整版本（内核、loader、原生对象）跑 Katran 和 OTel，两边工作量相等时才算数字回来（参考值 1.102x、1.824x）。
- [ ] **R** 解释 05-29 完整版本上 Katran native 0.859x（JIT 843,755 pps，native 725,112 pps，947a8896b）：native 三个样本单调下降，5 月记录 1.102x。
- [x] **C** 恢复后的框架上 verified 一侧 0 个 native 请求（b288ec52f）。 Fixed by external recipe b0b0824c2: matching May rejit support + norejit; post switch already works. Replay 809c71b76: 1 request/generated/compiled, 0 installed; verifier stack R10 -624. Both workload phases complete on eBPF fallback; native installation stays open.
- [ ] **R** 在恢复后的框架上重测六个应用，3 个样本、每个 180 秒、stats 开关各一组。11-09 之前“恢复后”的数字全部作废。
- [ ] **R** 解释 Cilium JIT 一侧的差异（改动框架上 1,293 ns，05-29 为 488.7 ns），重测后确认是否消失。
- [ ] **R** 实测每个应用的 BPF 占比（BPF 秒数 /（时长 × 忙 CPU 数）），得出算术上限。**协调者**据此确定目标按哪些应用计算。
- [ ] **R** 在 unbound 路径计时 C 已发布的候选：BCC control 和 candidate、Katran 内联（32dadc6b6）、Katran array 查找（99d79e4c9）。
- [ ] **R** 可信模块基线、时延、CPU 利用率。
- [ ] **C** 在原生编译阶段下沉 map 查找、改写 probe-read，先做 Katran 和 Tracee，再做 Tetragon、Cilium、OTel。
- [ ] **C** 当前 master 的 Katran 恢复原生安装：XDP 编译已修（044d32e09）；内联 P 的返回寄存器一致性拒绝见 13c38586e；分配候选 98650c853 的恢复框架回放为 0 次原生请求（247af4cc8），须先在冻结路径外补齐启动传递。
- [x] **C** 完整 Katran P 在提交前下沉 array 查找，21 个调用点、4 个对象、manifest/plugin/原始日志齐全，R unbound 请求已发（99d79e4c9，TODO 启用时补记）。
- [ ] **C** 继续在 P 中下沉 per-CPU array、hash、LRU 查找，保留现有重定位和验证后的同一副本发射。
- [ ] **C** 完成 Tracee probe-read 有效值/零值/故障重放与 R 计时：9738f6a5a 初版已撤回，保留原 helper ERANGE/EFAULT 的完整替代 payload 已发布（88e623a6a）; actual bfa5ae6de:4generated/4compiled/4verifier rejections/0native executions, from trusted-pointer masking before the load. R unbound timing and verified fault semantics remain open.
- [x] **C** 原生替换失败后保留 eBPF，完整 Katran 两个工作阶段继续运行，recipe 位于冻结路径之外（7734afc52、725e45398；248ebacee、13c38586e，TODO 启用时补记）。
- [ ] **C** 05-29 driver 缺少的运行需求放进 shim、loader 或冻结路径之外的 recipe，让 verified 一侧在恢复后的框架上跑通。
- [ ] **R** AArch64 硬件性能（DGX Spark，单次测试后立刻恢复 deepseek41-flash 部署）。
- [ ] **协调者** 用重测结果更新论文 §6。

## 2. 应用覆盖

两条路径分开计数。直接 native（跳过 verifier）：六个应用都跑通过（05-29，11-07 复现）。verified 路径（verifier 检查 B）：BCC 25/25、Katran 1/1 跑通过，其余应用只有少量程序，历史最高约 50/549。

549 个常驻程序的静态普查（`corpus/results/kprog_app_coverage_20261109/resident-census/`）第一轮：选择缺口 275、资源准备 238、ELF 名称语法 23、context 下沉 1；实际生成 12、编译 11、verifier 接受 7、拒绝 4。后续 stock guest 资源回放完成 238/238（bc3104df7），资源阶段与 native 生成、编译和 verifier 结果分别计数。

- [x] Tetragon 275 个选择缺口（271ddeee9、5dbd5d481、8922e4bde）。
- [ ] **A** 这 275 个程序的静态结果，按失败类排序后修最大的一类。现有 guest 保持运行；已记录 6/275（verifier 拒绝 5、编译失败 1），模型快照 4f5b7ae6d，完整结果与原始日志由现有批次发布。
- [x] **A/C** 资源准备 238/238 完成：Tracee 151、OTel 13（3daeea9b2），Cilium 72（aba3e9d46），BCC 2（7b4876f7a）；汇总 bc3104df7，本提交补记统一 TODO。通用路径适配局部入口符号、资源专用重定位视图、临时 pinning 生命周期和原应用运行时 map 参数。Cilium 的 CILIUM_PIN_REPLACE=16 与 BCC stackmap 的空模板字段均按实际 loader 语义处理。
- [x] **A** 23 条数字开头 ELF 名称的元数据语法修复：原始 kernel metadata/facts 全部规范化，23 份 map 声明编译与 ELF 名称保留通过，现有 6 项元数据测试通过（eeec0f52a，本提交补记统一 TODO）。
- [x] **A** 静态普查合并发布保留 previous-results 路径与 worker PID 各自语义；已完成的 guest 记录可独立发布，运行中的 275 行批次沿用原 guest 和模型。本提交修复 harness 的变量覆盖，代码位于冻结路径之外。 每行携带模型提交号，合并表保留各版本的实际行数。
- [ ] **A** 用已发布资源和名称修复回放其余 274 行的完整 native 生成、编译及 stock verifier 阶段；逐行记录模型/源码版本，并与上面的 275 行批次分别保留原始记录；回放 harness 位于冻结路径之外。
- [ ] **C** verifier 拒绝 4（scalar memory access）、编译失败 1、context 下沉 1；23 条名称问题的后续 native 阶段由上述 274 行回放记录。
- [ ] **C** x86-64 六个应用全部走通 verified 路径。
- [ ] **A** AArch64 QEMU 上六个应用全部走通（Tracee 启动窗口按 05-29 框架处理）。
- [ ] **C** 100–100K 规模扫描，verifier 时间和内存。

## 3. 安全：运行时缺口（有限用例和 guest 已验证）

- [x] 退出契约 RBP/R12/RSP、below-SP 栈生命周期（S7，cdeb9804d）；ARM 隐式 SP 回写（55504ff90）。
- [x] context 布局、尾调用帧、verifier 派生标志（S11，901194c0c）。
- [x] 部分宽度读的异常表恢复（S1、S2、S9、S10）；SMAP 分发（4ececd2cb）。
- [x] SIMD-free 原生代码（S14，0ead331cd）。
- [x] 间接分支加固 retpoline/ITS 和 BTI（S15，165ac4100）。
- [x] 安全用例 x86 47、ARM 48，接受的 8 例为良性恢复读，配对的写入变体被 verifier 拒绝（S16，ec468f0f7）。
- [x] 每个 armed 镜像只加载一次（fb23a234d、d140d92ab）。
- [ ] **C** RSP 位移候选：clang inbounds GEP 对区域外访问的影响（compiled-B 义务）。

## 4. 安全：证明（对所有程序，一次证完；禁止逐程序）

| 项 | x86-64 | AArch64 | 负责 |
|---|---|---|---|
| O1 参考语义定义 | 67/75 | 74/74 | V |
| O1 raw 寄存器 handler 精化 | 32/75 | 条件式 74/74，raw 0/74 | V |
| O1 地址内存组合步骤 | 29/75 | 0/74 | V |
| O2 C-model token 体等价 | 71/75 | 73/74 | V |
| 编译字节级证明 | 13/75 个操作，141 单元组合对象（含 2 个部分 helper 单元） | 0/74 | V、C |
| O4 链接步骤（22 行，两个 ISA 合计） | 7 条件式、14 部分、1 待证 | 同左 | V |

- [ ] **V** 上表每一行做到满额。
- [ ] **V** O1：官方模型对照补上 ANDN、BZHI 这 4 个 x86-64 形式（现为 63/67）。
- [ ] **V** O1/O2：x86-64 的 helper 调用、寄存器调用、外层返回；REP MOVS 全计数的 C 和编译证明。
- [x] **V** DIV：逐轮 64 位恢复除法、独立进位、余数与商不变式、bit63→bit0 顺序、零高位快路径与有符号故障结果组合（f243ef693，`X86Divide.RestoringLoop`）。
- [x] **V** DIV：四种宽度的实际 word 算术、窄宽度打包、word 范围比较、符号恢复、完整状态/fresh flags 与 raw/tag frame 组合（ce913a9c7，`X86Divide.SourceWords`）。
- [ ] **V** DIV word/当前 raw handler 与 RET exit 契约模型批次的全量检查（f243ef693、ce913a9c7、315c2f660 与本提交；当前 full 源 099a096fb，结束后沿用增量缓存继续）。
- [x] **V** DIV：AUX bit0 的 signed/unsigned 分流、任意 fresh flags、寄存器/捕获操作数、token/dispatcher 与通用块组合（099a096fb）。
- [x] **V** DIV：signed/unsigned 当前具体 C-model 全分支，word 算术直接执行于 raw/tag handler，并接入字段、dispatcher 和 O2 token 定理（本提交；71/75）。
- [ ] **V** 全 simulator 的 C 源解释与 Lean C-model 对应关系（包括 DIV、ROR、ANDN/BZHI 等当前 C-model）；编译 B 与物理内存/入口/ABI 对应关系继续按各项收尾。
- [x] **V** RET：现有 x86/ARM callee 标签/值/SP 退出判定、正常返回的完整 frame、x86 RET token guard，以及 native-return/JIT-result 的 callee/SP 前提组合（本提交，15 条组件定理）。
- [x] **V** RET：内部 STACK_RELEASE 的区间 fresh 字节、已声明 below-SP word 的 tag/valid 清除、payload/live cell 保留、saved-word 捕获与 selected/default token 组合（本提交，17 条组件定理）。
- [x] **V** RET：owned64read 的 scalar forwarding/非对齐字节路径、字节/scalar coherence 推导 saved-read 前提、live-read 保留与重新分配读取当前字节（本提交，9 条定理；前序 17 条 lifetime 重新审计）。
- [ ] **V** RET：实际 source index/union/signed 域与 live-stack/native-memory coherence，两个 ISA 的 return-mode 及 x86 saved-return/ARM LR 映射、实际 C/B/编译/物理入口出口对应关系。
- [ ] **V** RET 栈生命周期/owned-read 组件批次全量检查（本提交；沿用共享增量缓存，当前唯一 full 源 d39918760）。
- [ ] **V** O4：物理异常表一步、thunk 与物理栈有效性的组合、真实 JIT 对应关系、成功尾调用组合，并解除条件定理的 O1/O2 前提。
- [ ] **V、C** 编译后的 B 与 C 模型的差距：按 token 单元验证，或走经过验证的编译路径。
- [ ] **C/A** O3：两个 ISA 的有界间接跳转。
- [ ] **C/A** selftests：停在 specialization 的部分（x86-64 151/315，AArch64 268/380）；`__failure` x86-64 99/101、AArch64 84/87 的差异项。ARM 同源头文件批次 5102f3ca7 记录安装 18、verifier 拒绝 94；3 条安装的 failure 为 test_dynptr_reg_type、misaligned_access_read、global_func14，按原始规则、P/B 访问和异常恢复语义继续说明。
- [x] **V** 全量检查通过（本提交归档的源版本 099a096fb，实际 make check exit0）；后续模型批次按第5节继续全量检查。
- [ ] **V** TCB 统计，在提交论文的版本上重新计数。
- [ ] **协调者** 全量检查通过后重核论文的 O1、O2、O4 数字。

## 5. 架构整理

- [x] kinsn-free 内核路径，`verifier.c` 与 bpf-next 字节相同（35ea2cde39fc，970e4b205、fc443b4d4）。
- [ ] **C/A** 在 kinsn-free 路径上跑应用和 selftests。
- [ ] **协调者** 把四种形式的内核收成一条线：`kprog-no-kinsn` 成为主线，C/A/V/R 切换，主线 `verifier.c` 的 +527/−72 随之消失。
- [ ] **C/A/V** 模型改动按批发布，V 每批跑一次全量检查。
- [ ] **C、V** 工作树积压的约 100 条路径（S19 交接）。
- [ ] **协调者** lane 状态目录搬出 %TEMP%。

## 6. 开源整理（仓库名、许可证、结果位置保持现状）

- [ ] `THIRD_PARTY_NOTICES.md` 对 `kinsn/module` 的说明和文件自身的 GPL-2.0 标注保持一致。
- [ ] 确认 `kprog/formal` 中 ASL、Sail 生成物的许可。
- [ ] 代码里的 `/workspaces` 硬编码路径改成相对路径。
- [ ] 逐路径的发布清单：进超级仓库、进 kinsn、进 kprog、进存档。
- [ ] 公开文档（README、CONTRIBUTING、SECURITY，英文）和新 CI。
- [ ] 安静窗口：内核合并，kinsn 和 kprog 拆成两个 submodule，全新环境构建验证。
