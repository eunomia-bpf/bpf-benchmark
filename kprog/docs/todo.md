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
- [x] 直接 native 的 blob 端点放回 R 专用测量模块（`kprog/perf/direct-native/`，1734f582f、3bd83fb13），Katran 2 秒功能运行替换 1 个程序。
- [ ] **C/R** 这条测量路径没有异常表项，带 probe read 内联的 Tetragon、Tracee 载荷要先补上恢复路径再计时。
- [ ] **R** 统一 pps 口径：843,755 接近单 worker，四 worker 合计约 250 万。
- [ ] **C** 优化顺序改为 Tetragon、Cilium、OTel、Tracee，Katran 放最后。
- [ ] **协调者** 用重测结果更新论文 §6。

## 2. 应用覆盖

两条路径分开计数。直接 native（跳过 verifier）：六个应用都跑通过（05-29，11-07 复现）。verified 路径（verifier 检查 B）：BCC 25/25、Katran 1/1 跑通过，其余应用只有少量程序，历史最高约 50/549。

549 个常驻程序的静态普查（`corpus/results/kprog_app_coverage_20261109/resident-census/`）第一轮：选择缺口 275、资源准备 238、ELF 名称语法 23、context 下沉 1；实际生成 12、编译 11、verifier 接受 7、拒绝 4。后续 stock guest 资源回放完成 238/238（bc3104df7），资源阶段与 native 生成、编译和 verifier 结果分别计数。

- [x] Tetragon 275 个选择缺口（271ddeee9、5dbd5d481、8922e4bde）。
- [x] **A** body分组的实际resource preparation metadata（本提交）：36个重复body组/338resident涵盖58个不同profile输入，实际libbpf构造均成功、组内完整map定义/program context各自一致；其余211组各一resident。证据resource-profiles.json及gzip原始记录；maps创建0/program loads0/native executions0，549/247实际kernel阶段继续。
- [x] **A** 匿名runtime map metadata处理（本提交）：OTel inventory的23条匿名map按optional name参与原有profile join；原始13对象均KeyError(name)，修复后13/13实际libbpf metadata打开成功，完整source-map定义与program/attach context均与named reference相同。全部原始metadata保留，maps创建0/program loads0/native executions0；完整native阶段走观察内核。
- [x] **A** stage-end发布harness（本提交）：所有代表收集完成后一次发布；原始gzip流超过48MB时按顺序分片，每tracked文件小于50MB；相同字节结果沿用现有commit。三代表fixture仅触发一次stage publication，gzip JSON完整还原，48,000,001B分片完整还原。test-kernel image路径沿现有provenance传递，跨app资源按(application,id)匹配。
- [x] **A** 按协调者16:00原始结果审计把active class verifier_scalar_memory_access命名为callee_saved_equality_arm（本提交），Tetragon106/十体、merged549共110。原始diagnostic与阶段计数保留，入口桩修复由C继续。
- [x] **A** 275实例的分组静态普查完成：27/27实际代表、275/275加权实例；B生成275、编译242、verifier接受0/拒绝231，native kernel link PLT32失败11。与其余274原始行的549总表见 grouped-static/ranked-all-549.md；完整原始结果无损gzip保存。本提交本地完成，GitHub发布按限定历史修复case处理；最大storage类157继续按下方通用修复项收尾。
- [x] **A/C** 资源准备 238/238 完成：Tracee 151、OTel 13（3daeea9b2），Cilium 72（aba3e9d46），BCC 2（7b4876f7a）；汇总 bc3104df7，本提交补记统一 TODO。通用路径适配局部入口符号、资源专用重定位视图、临时 pinning 生命周期和原应用运行时 map 参数。Cilium 的 CILIUM_PIN_REPLACE=16 与 BCC stackmap 的空模板字段均按实际 loader 语义处理。
- [x] **A** 23 条数字开头 ELF 名称的元数据语法修复：原始 kernel metadata/facts 全部规范化，23 份 map 声明编译与 ELF 名称保留通过，现有 6 项元数据测试通过（eeec0f52a，本提交补记统一 TODO）。
- [x] **A** 静态普查合并发布保留 previous-results 路径与 worker PID 各自语义；已完成的 guest 记录可独立发布，运行中的 275 行批次沿用原 guest 和模型。本提交修复 harness 的变量覆盖，代码位于冻结路径之外。 每行携带模型提交号，合并表保留各版本的实际行数。
- [ ] **A/协调者** grouped census 完整诊断改为无损gzip与compact索引，继承现有guest/clang继续收集；GitHub GH001拒绝两个超100MB的本地census提交，后续peer提交一并保留，发布链按 Notices 的限定修复方案处理。
- [x] **A** 相同 native body 分组与 CPU8–19 并行提交 harness（本提交）：275 实例按完整 proof ELF 的代码、数据和重定位身份归为27组；13条串行记录覆盖7组、231加权实例，后续每组各一条实际提交，并在组完成时发布分类。
- [x] **A** 普查按原始 commands.jsonl 保留失败编译器的命令、退出码和 stderr，并将 BPF stack-size 编译错误单列；现有两条编译失败均属此类，本提交纳入统一分类路径。 八行实际分类和原始档案见 resident-census/linked-progress-8。
- [x] **A** 普查 B 的 forwarding cells 按现有整字读取布局收缩（本提交）：捕获的 8 行全部生成，6 行减少声明，其余生成行逐字相等；4 项布局用例保持旧 extent。结果见 resident-census/stack-forwarding-layout。
- [x] **A** forwarding tag8 与 valid1 合并为16位状态（本提交），保留所有256tag值与两个valid状态；GCC/Clang18、array/named两种布局的完整512状态与原栈生命周期用例共8组构建/运行通过，host UBSan 启用。编译B的stack占用与stock verifier继续按下一行收尾。
- [x] **A** Packing670b的5个distinct body完成B编译，5/5成功；直接R10最深值-120/-248/-248/-568/-1632，process_filter相对sparse的-2176收缩544字节。源/对象/命令/日志见 forwarding-state-pack/compile，本提交本地保存，stock verifier继续按下一行。 完整5体编译原始收据在本提交归档。
- [x] **A** canonical scoped05b的五体B编译完成（本提交）：5/5成功，直接R10为-120/-248/-248/-568/-1632，与packing670b相同。实际barrier保留；原始source/object/command/log见resident-census/scoped-coordinates-compile，后续按region spike继续。
- [ ] **A/C** 最大native storage类157（verifier124、compiler33）的通用修复及stock回放。Packing670b五体全部编译；process_filter直接R10从-2176降至-1632，仍需继续。宽constant-barrier1760/d3f的编译记录保留为撤回trial；C原38例中的entry_return_slot_overwrite要求保留原访问barrier，后续使用f202/05b等canonical source。
- [ ] **A/C** native kernel link的PLT32编码11实例（3体）及bpf_loop callback参数1实例（1体），分别保留B已生成/已编译与实际verifier阶段，使用通用链接/回调下沉处理。
- [ ] **A** 用已发布资源和名称修复回放其余 274 行的完整 native 生成、编译及 stock verifier 阶段；逐行记录模型/源码版本，harness 位于冻结路径之外。协调者 14:35 优先275行分组普查，旧等待队列已结束；源abf7ddc0b及274行输入保留于 repaired-static/launch 对应 scratch。
- [ ] **C** verifier 拒绝 4（scalar memory access）、编译失败 1、context 下沉 1；23 条名称问题的后续 native 阶段由上述 274 行回放记录。
- [ ] **C** x86-64 六个应用全部走通 verified 路径。
- [ ] **A** AArch64 QEMU 上六个应用全部走通（Tracee 启动窗口按 05-29 框架处理）。
- [ ] **A** 放大 MAX_BPF_STACK 的观察内核，覆盖549个B的512B墙后分类。输入549resident/247linked bodies已齐（47859e6dc），8192compiler fixture完成。完整容量patch把precision/liveness/scratch改为1024slot bitmap，六个14bit linked records用128bit，slot字段16bit；GCC/Clang18各1,218,560项UBSan观察及verifier/liveness/log真实TU syntax均0（本提交）。原old_must_write的u32临时字段也采用完整slot-set。kernel source位置按C/协调者one-tree处置，配对six-save内核的完整object/link/guest阶段继续。 实际kernel object阶段verifier/liveness/log三者GCC codegen0，最大function frame1424B，原始对象/命令/stack-usage已归档（本提交）；linked kernel与549 guest阶段继续。 collector实际写regno alias，补齐spi/regno双16bit：原256→0回归两编译器复现，修复后各1,226,840项UBSan通过、完整verifier object重建0（本提交）；source位置批准后进行paired kernel/link/549guest。
- [x] **A** 按 `design.md` 的 region 切分做 spike：B 按基本块拆成 noinline 子函数，量 actions、process_filter、generic_kprobe_ 的栈深和 clang 时间。 本提交提供独立region_spike编译实验：actions为150基本块/214显式边/2原返回，完整状态跨block保留，Clang18 BPF syntax exit0；三体编译结果继续收集。 三体stage完成：actions150块/45.98s/state1264B、process_filter438块/179.42s/state1672B、process_event631块/436.82s/state2616B，全部compile0；原始输入/对象/log gzip归档，root state容量继续按storage157项处理。
- [ ] **R/C** 应用级 B 生成时间（clang 单个 body 12–2,819 秒，最高 15.1 GB），论文的 54.52x 只来自 micro。
- [ ] **C** 100–100K 规模扫描，verifier 时间和内存。

## 3. 安全：运行时缺口（有限用例和 guest 已验证）

- [x] 退出契约 RBP/R12/RSP、below-SP 栈生命周期（S7，cdeb9804d）；ARM 隐式 SP 回写（55504ff90）。
- [x] context 布局、尾调用帧、verifier 派生标志（S11，901194c0c）。
- [x] 部分宽度读的异常表恢复（S1、S2、S9、S10）；SMAP 分发（4ececd2cb）。
- [x] SIMD-free 原生代码（S14，0ead331cd）。
- [x] 间接分支加固 retpoline/ITS 和 BTI（S15，165ac4100）。
- [x] 安全用例 x86 47、ARM 48，接受的 8 例为良性恢复读，配对的写入变体被 verifier 拒绝（S16，ec468f0f7）。
- [x] 每个 armed 镜像只加载一次（fb23a234d、d140d92ab）。
- [ ] **C** 入口桩保存恢复六个 callee-saved 寄存器，B 删掉对应比较；这个相等分支是最大的单一拒绝原因（105 个 Tetragon 实例及 Katran、OTel、Cilium、BCC）。
- [ ] **C** RSP 位移候选：clang inbounds GEP 对区域外访问的影响（compiled-B 义务）。

## 4. 安全：证明（对所有程序，一次证完；禁止逐程序）

| 项 | x86-64 | AArch64 | 负责 |
|---|---|---|---|
| O1 参考语义定义 | 67/75 | 74/74 | V |
| O1 raw 寄存器 handler 精化 | 32/75 | 条件式 74/74，raw 51/74 | V |
| O1 地址内存组合步骤 | 29/75 | 0/74 | V |
| O2 C-model token 体等价 | 71/75 | 73/74 | V |
| 编译字节级证明 | 16/75 个操作，158 单元组合对象（含 2 个部分 helper 单元） | 0/74 | V、C |
| O4 链接步骤（22 行，两个 ISA 合计） | 7 条件式、14 部分、1 待证 | 同左 | V |

- [x] **V** ARM raw NOP/MOV_IMM/MOVK：全部32目的字段、64位raw值/256标签、STACK4/RETURN10数值还原、实际cell/width/tag写回、XZR丢弃和opcode/field绑定的统一step定理；13条审计及模块/root编译通过（本提交，raw3/74），与B栈转发表示分离。
- [x] **V** ARM raw乘除法8操作：MADD/MSUB/MUL/UMULL/UDIV/UMULH/UMADDL/SMADDL，raw/tag数值还原、UDIV输入截断、width/tag写回、全部别名/XZR、unused SRC3任意字节含255，以及production multiply dispatcher与11操作统一step；新增10条及前13条审计/模块/root通过（本提交，raw11/74）。
- [x] **V** ARM raw SHIFT_IMM/SHIFT_REG/MVN/NEG：整字AUX移位种类、byte1/byte2 unary修改和计数、任意raw值/256标签/别名/XZR、width/tag写回、unused字段含255，以及production dispatcher与15操作统一step；新增17条及前23条审计/模块/root通过（本提交，raw15/74）。
- [x] **V** ARM数值SHIFT接口与实际C整字AUX统一：handler、dispatcher、specialized token和native binding使用整字0..3，原bad-kind定理覆盖全部AUX>3；11个受影响模块/root及50条公理审计通过，既有公开定理名和15操作raw step保留（本提交）。
- [x] **V** ARM raw EXTR/REV/REV16/SXTB/SXTH/SXTW/CNEG：实际raw/tag来源、EXTR输入截断、输入NZCV条件、width/tag写回、别名/XZR、unused SRC2/SRC3/IMM含255，以及production dispatcher和22操作统一step；新增14条及前40条审计/模块/root通过（本提交，raw22/74），入口/C抽取/物理compiler接口保持显式。
- [x] **V** ARM raw CSEL/CSINC/CSINV/CSNEG/CINC/CINV/CSET/CSETM：CSEL/X复制选中的raw值与完整标签，scalar分支按width写回；输入NZCV/别名/XZR、alias条件反转和ZR、NV归一化、unused字段含255，以及production dispatcher和30操作统一step；新增15条及前54条审计/模块/root通过（本提交，raw30/74）。
- [x] **V** ARM raw BITFIELD：UBFX/SBFX/UBFIZ/BFXIL/BFI五种native形式；输入SRC/旧DST的raw/tag还原、实际AUX字段、width/tag写回、全部别名/XZR、任意unused高字节/SRC2/SRC3/IMM，以及production dispatcher和31操作统一step；新增8条及前69条审计/模块/root通过（本提交，raw31/74），native字段边界与C/物理compiler接口显式。
- [x] **V** ARM raw源分支B/B.cond/CBZ/CBNZ/TBZ/TBNZ六族：原始tag/GPR/NZCV、W/X zero和low6 bit测试、前/后向源标签选择、current/next/target native地址绑定、NV归一化和完整data/tag frame，production emission等式与前31数值raw操作统一step；新增14条及前77条审计/模块/root通过（本提交），数值31/74与源分支6/6分列。
- [ ] **V** ARM六族source-control的selected硬件/official-model回放与native标签提取/数据和代码地址对应接口；通用label-map定理已在raw源分支批次给出，数值catalogue保持独立。
- [x] **V** ARM raw ORN_REG：物化SRC/SRC2、实际modifier/amount、四类native shift与omitted modifier任意amount、width/tag写回、全部别名/XZR和unused字节含255；production ORN dispatcher、32操作raw step以及保留六类源分支的统一emission step；新增12条及前91条审计/模块/root通过（本提交，raw32/74）。
- [x] **V** ARM raw CCMP_IMM/CCMP_REG：DST/SRC物化、输入NZCV、实际条件/比较/fallback low4、完整rawGPR/tag/data frame与NZCV外flag位、native IMM5/WX/NV归一化、unused字段含255和任意IMM；production dispatcher、34数值操作step与六类源分支统一emission step，新增19条及前103条审计/模块/root通过（本提交，raw34/74）。
- [x] **V** ARM raw ANDS_IMM/ANDS_REG/BICS_REG/TST_IMM/TST_REG/TST_BIC_REG：实际操作数角色/物化、immediate/modifier、AND/BIC result/NZCV、scalar写回或完整TST raw/tag frame、native WX/shift与omitted amount、unused字段含255/任意IMM；production dispatcher、40数值step与六类源分支emission step，新增14条及前122条审计/模块/root通过（本提交，raw40/74）。
- [x] **V** 完整检查99b的ROR字节码观察器修复：实际r3=3;r3+=r1交换加数顺序，增加既有ADD64仿射传播的常数DST/指针SRC形式；全部原有断言保留，504 handler/17640结果/40 BPF artifact及内存宽度/MOVX/坏偏移原套件通过；原full exit2与1289 Git源SHA和CPU/log归档（本提交）。
- [ ] **V** raw CCMP/logical flags（40数值操作+6源分支）与交换ADD64观察器合并后的完整make check；保留既有增量cache与精确源/实际exit。
- [x] **V** ARM raw ADDS/SUBS/CMP/CMN八操作：SP32/ZR31与全部tag物化、实际SRC/SRC2或DST/SRC角色、immediate/shift/extend、arithmetic result/NZCV、width/tag写回或完整compare raw/tag frame；production dispatcher与48数值+六源分支normalized emission step，新增12条及前136条审计/模块/root通过（本提交，raw48/74）。
- [ ] **V** raw arithmetic flags（48数值操作+6源分支）批次的完整make check，接续当前固定40操作源的sole full，复用增量cache并保留各自源/actual exit。
- [x] **V** ARM raw MOV_REG/ADRP_GOT/ADRP_RODATA：捕获raw/tag、W64复制/W32 scalar化、SP32/ZR31和SP相对坐标往返、MOV_IMM bitmask SP alias、GOT7/RODATA8及resolved IMM/native PC绑定；完整architecture/tag frame、production prefix和51数值+六源分支emission step，新增16条及前148条审计/模块/root通过（本提交，raw51/74）。
- [ ] **V** raw move/address（51数值操作+6源分支）批次完整make check，接续当前sole full并复用共享增量cache；保留各自固定源/actual exit。
- [ ] **V** 上表每一行做到满额。
- [ ] **V** O1：官方模型对照补上 ANDN、BZHI 这 4 个 x86-64 形式（现为 63/67）。
- [ ] **V** O1/O2：x86-64 的 helper 调用、寄存器调用、外层返回；REP MOVS 全计数的 C 和编译证明。
- [x] **V** DIV：逐轮 64 位恢复除法、独立进位、余数与商不变式、bit63→bit0 顺序、零高位快路径与有符号故障结果组合（f243ef693，`X86Divide.RestoringLoop`）。
- [x] **V** DIV：四种宽度的实际 word 算术、窄宽度打包、word 范围比较、符号恢复、完整状态/fresh flags 与 raw/tag frame 组合（ce913a9c7，`X86Divide.SourceWords`）。
- [x] **V** DIV word/当前 raw handler 与 RET exit 契约模型批次的全量检查（源 d39918760，本提交归档实际 make check exit0；包含 f243ef693、ce913a9c7 、当前 raw handler 与 RET exit 契约）。
- [x] **V** DIV：AUX bit0 的 signed/unsigned 分流、任意 fresh flags、寄存器/捕获操作数、token/dispatcher 与通用块组合（099a096fb）。
- [x] **V** DIV：signed/unsigned 当前具体 C-model 全分支，word 算术直接执行于 raw/tag handler，并接入字段、dispatcher 和 O2 token 定理（本提交；71/75）。
- [ ] **V** 全 simulator 的 C 源解释与 Lean C-model 对应关系（包括 DIV、ROR、ANDN/BZHI 等当前 C-model）；编译 B 与物理内存/入口/ABI 对应关系继续按各项收尾。
- [ ] **C/V** 原始ABI ISA48的三个load-only accepted_finding：uninitialized_stack、immediate_push_branch、stack_base_flags（C完整before收据7cc7c2106，原字节/前S17阶段保留，negative native执行0）；C对齐六保存寄存器kernel/header回放，V跟踪通用模型与入口/stack/flag/物理compiler对应，保留明确版本前提。
- [x] **V** RET：现有 x86/ARM callee 标签/值/SP 退出判定、正常返回的完整 frame、x86 RET token guard，以及 native-return/JIT-result 的 callee/SP 前提组合（本提交，15 条组件定理）。
- [x] **V** RET：内部 STACK_RELEASE 的区间 fresh 字节、已声明 below-SP word 的 tag/valid 清除、payload/live cell 保留、saved-word 捕获与 selected/default token 组合（本提交，17 条组件定理）。
- [x] **V** RET：owned64read 的 scalar forwarding/非对齐字节路径、字节/scalar coherence 推导 saved-read 前提、live-read 保留与重新分配读取当前字节（本提交，9 条定理；前序 17 条 lifetime 重新审计）。
- [x] **V** RET：实际 wrapping source index/有符号坐标/native byte 地址，已分配 8 字节域的 signed SP 推进、Coherent 推导 saved-read 并在 release 后保持，接入 native Step 与 selected/default token（本提交，12 条定理）。
- [x] **V** ARM RET：当前 raw target/RETURN10/CODE9 的 invocation/有限 case/default 分流、完整 scratch frame、X0 物化与外层 callee/SP 契约、内部 reference branch 与 native ABI 前提（本提交，12 条组件定理）。
- [ ] **V** RET：实际 C/union/编译器建立 live-stack/native-memory Coherent 关系，x86 producer return-mode、ARM producer operand/case 表及两 ISA saved-return/LR/code-PC 映射、实际 C/B/编译/物理入口出口对应关系。
- [x] **V** RET source-coordinate/coherence 与 ARM RET source 批次全量检查（源 2adbd4abd，本提交归档实际 make check exit0；含源坐标/live-memory12条及ARMtarget/tag/numeric-exit12条定理）。
- [x] **V** RET 栈生命周期/owned-read 组件批次全量检查（源 2adbd4abd，本提交归档实际 make check exit0；包含 85d7ff891 的17条 lifetime、5e9636767 的9条 owned-read，以及后续源坐标与ARM RET模型）。
- [ ] **V** O4：物理异常表一步、thunk 与物理栈有效性的组合、真实 JIT 对应关系、成功尾调用组合，并解除条件定理的 O1/O2 前提。
- [x] **V** compiled ROR：五个真实 BPF 单元覆盖 8 位低/高字节及 16/32/64 位，任意 value/count/fresh 输入、reference scalar 写回和完整 memory/visit/halt/fault/events 观察；组合对象 146 个函数，原 141 字节保持（本提交，compiled14/75）。
- [x] **V** compiled ROR 与前序 RET source 模型合并批次全量检查（源 2adbd4abd，本提交归档实际 make check exit0；包含151组合单元及50条RET组件定理）。
- [x] **V** compiled ADD_IMM：五个真实 BPF 单元覆盖8位低/高字节及16/32/64位，任意操作数/编码立即数及64位imm32符号扩展，reference scalar写回、完整memory/visit/halt/fault/events；151组合函数保留原146字节（本提交，compiled15/75）。
- [x] **V** compiled ADD_IMM 后继全量检查（源 2adbd4abd，本提交归档实际 make check exit0；包含151组合单元及50条RET组件定理）。
- [x] **V/C** ROR_MEM 绝对地址写回采用现有64位整数地址运算（源9208b579d）；原有26,547,217-case oracle 在 Clang18/GCC UBSan 各通过，原始line892诊断和精确源码/编译输入归档于本提交。
- [x] **V** compiled ADD_REG：七个真实BPF单元覆盖四种8位源/目的低高字节组合及16/32/64位，任意操作数/fresh/visit、canonical arithmetic与scalar写回、完整memory/exclusive/23输入/halt/fault/events；158组合函数保留原151字节（本提交，compiled16/75）。
- [ ] **V** compiled ADD_REG 后继全量检查（协调者16:00暂停；已提交源码/归档保留，等待B表示调整）。
- [ ] **V、C** 编译后的 B 与 C 模型的差距：按 token 单元验证，或走经过验证的编译路径。 协调者16:00暂停编译单元，等待B表示调整。
- [ ] **C/A** O3：两个 ISA 的有界间接跳转。
- [ ] **C/A** selftests：停在 specialization 的部分（x86-64 151/315，AArch64 268/380）；`__failure` x86-64 99/101、AArch64 84/87 的差异项。ARM 同源头文件批次 5102f3ca7 记录安装 18、verifier 拒绝 94；3 条安装的 failure 为 test_dynptr_reg_type、misaligned_access_read、global_func14，按原始规则、P/B 访问和异常恢复语义继续说明。
- [x] **V** 全量检查通过（本提交归档的源版本 2adbd4abd，实际 make check exit0）；后续模型批次按第5节继续全量检查。
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
