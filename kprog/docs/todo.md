# kprog TODO

唯一的待办清单。运营者原话：2026-11-08 “这个也要记录 todo”“要有 todo”；2026-11-09 “都有 todo list 了吗? 确保都有”。

规则：每完成一项，负责的 lane 在同一个提交里把这一行改成 `[x]` 并写上提交号，然后 push。新发现的事项直接加到这里。证明数字以 `kprog/results/kprog_verification_20261107/coverage.tsv` 为准。

状态基于 2026-11-12 04:30 UTC。六应用几何平均（stats 关）：第 c 轮 1.217x；用第 d 轮的 Cilium 1.401x、Katran 1.112x 为 1.240x；05-29 下限表 1.169x；运营者 11-09 目标"平均之后 20%-40% 进步"。

## 1. 性能（目标：六应用几何平均 native/JIT 1.20x–1.40x，来自原生代码）
- [ ] **重新开始（运营者 2026-11-11 “停掉所有的, 然后确保重新开始”，“你能自己来的整理可以自己来, omp 辅助 review; 先不用 claude subagent 了”）**：所有 lane 停止，协调者自己做，omp 逐步 review。顺序：① 内核从 stock 基点 c23719abc330 开始，按需要逐个加入提交，每步构建并检查；② 链接器从 05-29 的源码（9f3855f6f）开始，按需要逐个加入改动，每步比对六个应用的原生字节；③ 唯一镜像、唯一底座；④ 一轮六应用计时，每个应用达到或超过 05-29。之后才做其他事。运营者 2026-11-11 22:55 UTC "6 小时审核 可以是 claude. 开发让 omp 做" "每一个 workspace 一个 omp 在里面跑, 持续推进. local large"：lane C 以新会话重启，作为 Workspace 里唯一的 omp 开发 lane（fleet/local-large），按本节的加载时特化条目开发；6 小时审核在 Workspace 里由全新的 claude -p 进程自己跑（AUDIT 循环）。2026-11-12 运营者（经 ModelOS 会话转达）"每一个 workspace 里面都可以加一个 codex lane 一直干, 用 gpt 6.1 sol"：加 Codex lane "verified"（gpt-6.1-sol）做 verified 线：先在唯一内核和镜像上跑通 BCC、Katran，再按失败类别从大到小做其余四个应用；CPU 0-7 归 lane C 计时，8-19 归 verified，20-23 归 lane C 构建。运营者 "每小时监控提醒不能停" "自己推进, 直到性能这部分全部做完, 优化也搞定为止. 每个应用跑3次之后换下一个应用这样, 广度优先"：计时和优化按应用广度优先，每个应用跑 3 次再换下一个。
- [ ] **最高优先级（运营者 2026-11-11）**：每个应用在当前系统上至少达到 05-29 系统的数字（11-10 复现，stats 关：OTel 1.849x、BCC 0.985x、Tracee 0.948x、Katran 1.113x、Tetragon 1.009x、Cilium 1.319x）。以 05-29 代码为参照，逐个应用比对原生代码字节，差异要么是实测的改进，要么改回 05-29 的形式。
- [ ] **C** 内核合并：9c50491de2a5 和 a3cb8790e 里当前路径需要的功能，以提交的形式合进 7d6b7d663680 这条线（在子模块检出里原地提交，推送 eunomia-bpf/linux kprog-no-kinsn，同步 master 指针），在 `/workspaces/.agent-state/kprog-ck/build-x86` 原地重建；之后删掉其他内核版本和构建，删除清单写进 `kprog/docs/cleanup-log.md`。
- [x] **协调者** 唯一镜像 `bpf-benchmark/kprog:current`：05-29 的 build.mk 与 Dockerfile（d0b902050），内核在唯一底座按 05-29 defconfig 构建，配方 `kprog/perf/one-image`（0373ac0eb、7d31c972b、2fa61eee7）。
- [x] **协调者** 原生用户态链路与框架回到 05-29：shim、loader、链接器（e6808c073，链接器与 05-29 二进制逐字节相同）、`vendor/bpf`（5a47ae87b）、`runner/`（c9b58a26f、24a2d15aa）。之后的改动按六应用在唯一内核上的需要逐个加回。
- [ ] **协调者** 六应用在唯一系统上装入原生代码：Katran、BCC 已装上（16a1391d8、ee1ba70fc）；OTel、Cilium、Tetragon、Tracee 在 tail call 上让 guest 崩溃，修复 5f6e694bfd4d、6a3152eb7 待验证。
- [x] **协调者** Tetragon 的比较基准（运营者 11-11 "请你定? 解释一下? 不是说你自己决定吗, 干嘛找我" "记住"）：按等量工作比较，即唯一系统第 c 轮（原生对象按唯一内核结构体布局编译）对照 AGENTS.md 里的下限表（11-10 复现：stats 关 1.009x、开 1.140x）。存档 1.323x 与复现中 generic_kprobe 每次调用 5.8x 来自按另一内核 task_struct 布局编译的原生对象，记为工作量不同的数字，附证据，不作目标。
- [ ] **协调者** 广度优先计时（每个应用 3×180 秒）：BCC stats 关 1.005x（101011_549780）、Katran stats 关 1.128x（103657_155576），均达到或超过 05-29；其余四个应用待装上后计时。
- [ ] **C** Katran：链接器去掉多余的 helper id 加载（cd8996e64，blob 与 05-29 字节相同）后计时；jited_len 剩下的差（10,102 对 10,196）查内核一侧的包装。
- [ ] **C** Cilium：用去掉 thunk 的配方对象（`cil_from_host` 734 条指令）计时，对照 05-29 的 1.319x。
- [ ] **C** OTel、Tracee：唯一内核线支持 tail call 计数重定位（第 10、11 种），`native_tracer_e` 走 native。
- [ ] **全部 lane** 原始数据从 /var/tmp 移到 /workspaces 的持久存储，一律保留。

- [x] 框架恢复为 05-29 定义，只保留 `native-sim`→`kprog` 和 `module/`→`kinsn/module/` 两处目录改名（191f9dc1d、96d09c17b）。
- [ ] **R** 用 05-29 完整版本（内核、loader、原生对象）跑 Katran 和 OTel，两边工作量相等时才算数字回来（参考值 1.102x、1.824x）。
- [ ] **R** 解释 05-29 完整版本上 Katran native 0.859x（JIT 843,755 pps，native 725,112 pps，947a8896b）：native 三个样本单调下降，5 月记录 1.102x。
- [x] **C** 恢复后的框架上 verified 一侧 0 个 native 请求（b288ec52f）。 Fixed by external recipe b0b0824c2: matching May rejit support + norejit; post switch already works. Replay 809c71b76: 1 request/generated/compiled, 0 installed; verifier stack R10 -624. Both workload phases complete on eBPF fallback; native installation stays open.
- [ ] **R** 在恢复后的框架上重测六个应用，3 个样本、每个 180 秒、stats 开关各一组。11-09 之前“恢复后”的数字全部作废。
- [ ] **R** 解释 Cilium JIT 一侧的差异（改动框架上 1,293 ns，05-29 为 488.7 ns），重测后确认是否消失。
- [ ] **R** 实测每个应用的 BPF 占比（BPF 秒数 /（时长 × 忙 CPU 数）），得出算术上限。**协调者**据此确定目标按哪些应用计算。
- [ ] **R** 在 unbound 路径计时 C 已发布的候选：BCC control 和 candidate、Katran 内联（32dadc6b6）、Katran array 查找（99d79e4c9）。
- [ ] **R** 可信模块基线、时延、CPU 利用率。
- [ ] **C** 在原生编译阶段下沉 map 查找、改写 probe-read；按协调者22:20顺序处理 Katran、Tetragon、Tracee、Cilium、OTel。完整 direct Katran 三候选已交给R（87a028418）。
- [ ] **C** 当前 master 的 Katran 恢复原生安装：XDP 编译已修（044d32e09）；内联 P 的返回寄存器一致性拒绝见 13c38586e；分配候选 98650c853 的恢复框架回放为 0 次原生请求（247af4cc8），须先在冻结路径外补齐启动传递。
- [x] **C** 完整 Katran P 在提交前下沉 array 查找，21 个调用点、4 个对象、manifest/plugin/原始日志齐全，R unbound 请求已发（99d79e4c9，TODO 启用时补记）。
- [ ] **C** 继续在 P 中下沉 per-CPU array、hash、LRU 查找，保留现有重定位和验证后的同一副本发射。
- [ ] **C** 完成 Tracee probe-read 有效值/零值/故障重放与 R 计时：9738f6a5a 初版已撤回，保留原 helper ERANGE/EFAULT 的完整替代 payload 已发布（88e623a6a）; actual bfa5ae6de:4generated/4compiled/4verifier rejections/0native executions, from trusted-pointer masking before the load. R unbound timing and verified fault semantics remain open.
- [x] **C** 原生替换失败后保留 eBPF，完整 Katran 两个工作阶段继续运行，recipe 位于冻结路径之外（7734afc52、725e45398；248ebacee、13c38586e，TODO 启用时补记）。
- [ ] **C** 在冻结路径之外接通05-29 verified native阶段：原snapshot RPC9220b9b44、原norejit模式e9b15dbfb、完整成功/失败请求档案759f31d85已发布；六应用baseline共384个观测程序，同af422c391模型的生命周期锁ea4625f42后，BCC25/25完整运行710fdaa60，OTel两条旧安装入口恢复42ba10978；其余native阶段回放继续。
- [ ] **R** AArch64 硬件性能（DGX Spark，单次测试后立刻恢复 deepseek41-flash 部署）。
- [x] 直接 native 的 blob 端点放回 R 专用测量模块（`kprog/perf/direct-native/`，1734f582f、3bd83fb13），Katran 2 秒功能运行替换 1 个程序。
- [ ] **C/R** 这条测量路径没有异常表项，带 probe read 内联的 Tetragon、Tracee 载荷要先补上恢复路径再计时。
- [ ] **R** 统一 pps 口径：843,755 接近单 worker，四 worker 合计约 250 万。
- [x] **C** 按协调者22:20更新优化顺序：Katran、Tetragon、Tracee、Cilium、OTel；Katran完整direct payload87a028418交给R，verified审计回退按主线继续。
- [ ] **协调者** 用重测结果更新论文 §6。
- [ ] **BCC、Tracee 每次调用持平（2026-11-11 分析，运营者 "workload 如果能优化的话也行? 但是要分析处理 workload 哪里不好再说,我需要批准."）**：按程序拆分（`kprog/perf/may29-image/perprog.py`）显示 BCC 69% 的 BPF 时间在 syscount 的 sys_enter/sys_exit（每次约 80 ns，原生 1.002x/1.015x），Tracee 86% 在 raw_syscalls sys_enter 与 trace_sys_enter/exit（原生 1.091x/0.984x/0.944x）。两者都由 helper 与 map 访问主导；eBPF 一侧验证器按冻结的 .rodata 删掉配置分支（sys_enter 31→21 条，sys_exit 116→82 条），原生代码保留全部分支并在运行时读 6 个配置值，代码更长（153 对 108 字节，561 对 406 字节）。workload 本身让时间集中在这些热点上，符合它的设计目的；比值持平的原因在原生代码一侧，workload 保持不变。优化（运营者 "这个是不是我们加载时的特化也要保持, 并且做的更过分? 比如说相当于 helper map 也可以这样内联之后常量消除. 在 llvm 层面做? 你看看?" "或者在 verifier 特化那一步做也可以?"）：（运营者 "不是 在 LLVM 层? 是在 simulator 那一层, 那不是用 c 做产量传播吗? 还可以进一步优化?" "不需要 构建时多保留一份 LLVM bitcode?"）simulator 层的 C 常量传播产出的是供 verifier 分析的 eBPF，运行的是 P（design.md §按程序特化 第 4 点）；把 .rodata 和 map 布局也当常量交给它，分析对象随之变小。运营者 "干嘛要改机器码? ... 为啥不直接把.rodata 值放进 C 里面? 干嘛还需要 bitcode?"：采用。冻结的 .rodata 值直接放进 C：P 由 clang 从应用的 C 源码编译，每个 .rodata 全局变成带加载值的普通常量（按 ELF 符号表里的名字去掉 const volatile 的 volatile，六个应用同一条规则）；helper 和 map 查找在 native compat 头文件里按加载时的 map 布局给出 C 内联实现，clang 一次编译里完成常量折叠和内联。simulator 用同样的值在它的 C 里对这份 P 特化。不需要 bitcode，也不改机器码；按（程序、.rodata 字节、map 布局）编译一次并缓存。顺序 Tracee（BPF 占 8 个 vCPU 的 57.9%）、Tetragon（49.3%）、BCC（18.2%）。design.md 第 119 行"每个程序一次特化,而非每次 load 跑一遍 LLVM"的改写等运营者同意；原型先做。2026-11-12 审核 detour-20261112T03Z 之后：先做构建时实验（用一次运行抓到的 .rodata 值在构建时编出原生对象，运行时镜像不变），Tracee、BCC 各计时一次；Tracee 热点程序每次调用快 10% 以上，再把加载时形式（镜像里带源码和编译，属于运行时镜像定义的改变，AGENTS.md:13）交运营者同意；否则记录结果，lane C 转 verified 线。下限判定：下限落在该应用自身样本范围内或低于其中位数即算达到。运营者 "我们可以保留两种版本, isolate 出来性能差异,一个是有内联特化的版本一个是没有内联特化的版本?"：同一个镜像里两种原生配置，由加载器的一个开关选择——"原生（无加载时特化）"即现在的 05-29 路径，原样保留；"原生（加载时特化）"。每个应用在同一轮广度优先计时里两种都跑，各 3 个样本，stats 关和开各一次，各自对照同一次运行里的 eBPF 基线；stats 开的逐程序每次调用时间把特化带来的差异单独分出来。

## 2. 应用覆盖

**当前唯一镜像 verified 覆盖快照（2026-11-12 09:55 UTC）**：kernel `5f6e694bfd4d`、model `8f1a1a8b4`、current image（built from `d70d2e03e`）、installed worker `fba19ea94`。样本为 1×10s 功能覆盖。source submissions 计实际装入后提交 service 的候选原程序（保留应用重试）；verified 计 stock verifier 接受并安装的 native programs；run 计 workload 内 `run_cnt_delta > 0` 的 native programs。启动阶段退出的 run counters 标为待测。原始目录统一位于 `/workspaces/kprog-raw/verified/`；完整 corpus run IDs、逐 ID counters 与 stdout/stderr 见各 receipt/archive。worker map-dependency fix `812aee2ec` 的运行结果在协调 rebuild 后单列。

| 应用 | Source loaded/submitted | Verified installed | Workload run | App status | Raw run directory / receipt |
| --- | ---: | ---: | ---: | --- | --- |
| BCC | 25 | 25 | 17 | ok | `20261112-image-bcc/` · [receipt](../results/verified_20261112/image-bcc-receipt.json) |
| Katran | 1 | 1 | 1 | ok | `20261112-image-katran/` · [receipt](../results/verified_20261112/image-katran-receipt.json) |
| Tetragon | 4 | 2 | 待测 | error | `20261112-image-tetragon/` · [receipt](../results/verified_20261112/image-tetragon-first-receipt.json) |
| Tracee | 4 | 2 | 待测 | error | `20261112-image-tracee/` · [receipt](../results/verified_20261112/image-tracee-first-receipt.json) |
| OTel | 待测 | 待测 | 待测 | running（PID671605） | `20261112-image-otel-initial/` |
| Cilium | 待测 | 待测 | 待测 | pending | 本轮 verified startup 接续 |

- [ ] **VERIFIED（2026-11-12）** 唯一内核 5f6e694bfd4d 上重新跑 BCC、Katran，再按最大失败类推进其余四应用。第一步：现有 stock-path module 在唯一底座 `build-x86` 编译成功，产物 `/workspaces/.agent-state/kprog-ck/verified-module/bpf_kprog_stock.ko`，构建收据 `/workspaces/kprog-raw/verified/20261112-module-build/receipt.json`。当前镜像仅带 timing-only module，没有 specializer；May reset e6808c073 删除了 trusted-service loader API，待在原检出中恢复所需部分，并协调唯一镜像重建。六应用在当前内核的 loaded/verified/run 数量均未测量，不能沿用下方历史计数。 生产者提交端已恢复（2a32f739a、ee9d3117d）：要求 verified 时通过 kernel queue 提交 P 和 map capabilities，service 拒绝直接返回；首轮 kernel-queue regression rc2（`/workspaces/kprog-raw/verified/20261112-producer-queue/`）：P/entry/source snapshot 收到，但测试 map 名称缺少 `.bss` 后缀，metadata 断言失败；修正 fixture 后重跑 rc0（705aa20a4，`/workspaces/kprog-raw/verified/20261112-producer-queue-2/`）：kernel 收到逐字相同的 P、entry/source identity 与实际 stats map capability/offset，service 的 EACCES 正确返回；本项仅测 transport，native 执行 0；service-worker load API 已恢复并通过下述 control，镜像集成仍待协调。 现有 specializer 依赖的 `--preserve-entry-abi` 已按历史逻辑恢复，测试将先保存六应用全部 manifest entries 的默认 proof-stage native `.text`/ABI，再原地重建唯一 linker、跑 Rust tests 并逐字比较；首轮 `/workspaces/kprog-raw/verified/20261112-entry-abi/` 已完成 baseline 捕获与 release build，3 个现有 Rust tests 通过；新增 test 的 expected bytes 漏了原有 proof exit jump，c3f3d8599 修正后重跑 rc0（`/workspaces/kprog-raw/verified/20261112-entry-abi-2/`），Rust 4/4 通过；对首轮重建前 baseline 的 349 条命令状态一致，302 份成功输出的 `.text`/ABI 逐字相同，47 条原有失败保留。本项仅为 linker proof-stage bytes，非最终 kernel-linked runtime bytes 或应用覆盖。 本次恢复现有 bridge 的 worker API、trusted-only B 重定位、单 native extent 的 stock load/COMPLETE，并恢复 x86 load-site sideband（默认不输出）；source-current 构建、Rust tests、六应用默认 proof-stage bytes 回归与原有 return-2 control 全部 rc0（fba19ea94，`/workspaces/kprog-raw/verified/20261112-service-recovery/`）：P 由 kernel queue 进入 service，B 经 stock verifier 接受，native prog ID6 实际 TEST_RUN 返回2；原始 service archive 与 receipt 见 `kprog/results/verified_20261112/`。这是 1 个 control，尚非应用覆盖；已准备交协调者安排唯一镜像集成。

- **VERIFIED diagnostic（2026-11-12，非镜像 corpus）** 上游 BCC `vfsstat -v 1 1` 在唯一内核启动 rc0：实际应用 loaded 5、verified/native attached 5，native IDs 8/12/16/20/24；read/write/open 的 app counters 非零，执行至少 3 个程序，未采集全部程序 run_cnt，fsync/create 是否执行未确认。目录 `/workspaces/kprog-raw/verified/20261112-bcc-startup/`；完整 service/shim/startup 日志与 receipt 已归档 `kprog/results/verified_20261112/bcc-vfsstat-*`。source-current producer regression 同轮 rc0。完整 BCC set 与唯一镜像 corpus 仍待跑。

- **VERIFIED BCC set diagnostic（2026-11-12）** 首轮 harness rc0，但只观测到 8 个仍在 native load 中的原始程序，verified native 0、native run 0；首个实际 service request 的 B 已生成/编译，caller 在完成前被 harness SIGINT，worker arm 返回 ENOENT，不能记作 verifier rejection。原始目录 `/workspaces/kprog-raw/verified/20261112-bcc-set/`，归档 `kprog/results/verified_20261112/bcc-set-interrupted*`。通用原因是 snapshot 可发布正在替换的 original FD；恢复历史 ea4625f42 的 load/snapshot lifetime 同步，不改 frozen runner、不新增 readiness 条件。 同步修复与真实 kernel queue/snapshot regression 已恢复到当前 shim；将先用旧 artifact 复现，再原地重建同一 shim 并重跑 regression/BCC set，目录 `/workspaces/kprog-raw/verified/20261112-load-lifecycle/`。旧 shim 的真实 kernel request/snapshot regression 复现提前发布（snapshot_before_load_completed=true，rc2）；原地重建同一 artifact 后 snapshot 等待完成（false，rc0）。两轮 service 均按测试要求返回 EACCES，app rc1；此测试测 load/snapshot lifetime，应用计数另列。修复 1af32bdae，完整前后日志、P、metadata、observation 已归档 `kprog/results/verified_20261112/load-lifecycle*`；同轮完整 BCC set diagnostic 正在运行。


- **VERIFIED BCC completed diagnostic（2026-11-12，唯一内核）** load/snapshot 修复 1af32bdae 后，原八工具启动 rc0，25 个实际 source submissions 全部经 service 生成 B、stock verifier 接受、native 安装完成（25 loaded / 25 verified）；结束时 14 个 native program 的 run_cnt 为正，其中 12 个在原 10K 次 open/write/close 功能操作阶段增加。其余程序继续保留原始计数。目录 `/workspaces/kprog-raw/verified/20261112-load-lifecycle/bcc/control/`；每个 source/native ID、run_cnt 前后值和完整 service/app/shim 档案见 `kprog/results/verified_20261112/bcc-set-completed*`。opensnoop 报 CPU0 丢失 3295 个事件，原始 stderr 已保存。此项为镜像外 diagnostic；冻结 workload 的唯一镜像 BCC、Katran 重跑仍交协调者集成。
- **VERIFIED final linker regression（2026-11-12）** 在最终 linker source fba19ea94 重跑六 manifest 默认 proof-stage bytes 对照，rc0，349 个 command identity/status 一致，302 份成功 `.text`/ABI 逐字相同，47 条历史失败状态保留；原始目录 `/workspaces/kprog-raw/verified/20261112-final-linker-bytes/`，原 baseline 和本轮输出一起归档 `kprog/results/verified_20261112/final-linker-bytes*`。最终 runtime bytes 与应用运行数据按各自 run 记录。


- **VERIFIED image integration（2026-11-12）** READY FOR IMAGE 已于 07:26 交协调者（loader/linker fba19ea94、shim 1af32bdae，证据 bfe589764/2a01f79e6）。冻结 root Makefile 的 `SUITE_ENV_NAMES` 和 `runner/libs/suite_commands.py` 环境列表保持 05-29 版本；verified invocation 需要通过现有 Make 变量 `RUNTIME_ENV_BASE_NAMES` 显式包含 `BPFREJIT_NATIVE_LOADER_REQUIRE_BOUND_PROOF`，才能将 service supervisor 的值传入 app container。module selection 由协调者在同一镜像的每个 guest 单独安排。原 Katran artifact preparation helper 改为读取唯一镜像 `bpf-benchmark/kprog:current`，用已有 `unbound-katran-inputs` target 将上游可执行文件与依赖放入唯一底座的 `verified-katran-inputs`；之后真实服务诊断复用该二进制，冻结 workload/image 重跑继续按协调安排。


- **VERIFIED Katran diagnostic（2026-11-12）** 原 `unbound-katran-inputs` preparation 在唯一镜像 current 上 rc0；上游 server 与运行库位于唯一底座 `verified-katran-inputs`，原始日志 `/workspaces/kprog-raw/verified/20261112-katran-inputs/`。下一步在当前 registered service 下复用 `KatranServerSession` 启动上游应用，保存完整 program snapshots，对实际加载的程序使用既有 `katran_vip_packet_64.bin` 执行 TEST_RUN，原始 stdout/stderr/packet 保留；新脚本 `kprog/test/katran_startup.py` 仅组织该 diagnostic。应用 loaded/verified/run 计数由运行后 service receipts 与 raw counters 交叉记录。


- **VERIFIED module selection integration（2026-11-12）** stock module 的内部名和文件名按已有架构 endpoint 对齐为 `bpf_$(SRCARCH)_native_lab`，仍由同一 `kprog_stock.o` 组成；x86 service/queue/lifecycle Make callers 与 stock guest 默认文件名同步。verified guest 先载入对应 variant 后，冻结 installer 的递归扫描和 corpus 的顶层扫描均能按既有 resident 判定复用该模块。源代码已准备，唯一底座 module 替换、旧 `bpf_kprog_stock` wrapper build 输出清理和 kernel regression 交协调者安排共享 rebuild slot；当前 Katran guest 使用其启动时已载入的模块继续运行。08:34 在协调者 image rebuild slot 内完成外部 verified module 原地构建 rc0；实际模块 name 为 `bpf_x86_native_lab`，vermagic `7.0.0-rc2+`，原 bpf_kprog_stock wrapper 的 9 份 build 输出删除逐条记入 cleanup-log。目录 `/workspaces/kprog-raw/verified/20261112-module-identity/`，metadata/build receipt 在 `kprog/results/verified_20261112/module-identity*`；现有 queue/lifetime/return2 与实际 Katran regression 接续运行。


- **VERIFIED Katran first result（2026-11-12）** upstream 实际 source loaded/submitted 1（ID6），B generated 1/compiled 1，stock verifier 拒绝，verified native 0、native run 0，make rc2。末端 BPF 指令 7127 在 stack alias lifetime 路径重建 frame pointer 时得到过宽负数范围：`value -9223372036854775568 makes fp pointer be out of bounds`。原始目录 `/workspaces/kprog-raw/verified/20261112-katran-startup/`，完整 worker/generated-C/compiler/verifier/app/shim 档案 `kprog/results/verified_20261112/katran-stack-alias-failure*`。继续处理通用 tagged stack alias store 的 typed address 保持；此前 broad constant-barrier 方案的安全 replay 有变化，当前保留 canonical barrier。


- **VERIFIED typed stack alias store（2026-11-12）** 通用 tagged store 保留原 typed address 完成原宽度写入，随后沿该地址对现有 below-SP 字节逐个写入 environment input；原 alias offset barrier、metadata erase、SP predicate 保持。扩展原 invocation-stack host oracle，覆盖 3861 个 width/alignment/SP 组合，GCC 与 Clang18 的 UBSan 均 rc0（Clang 编译 object，使用已安装的 GCC UBSan runtime 链接）。原始 `/workspaces/kprog-raw/verified/20261112-stack-alias-host/` 和 `kprog/results/verified_20261112/stack-alias-host*`。当前 Katran 首轮 verifier 拒绝原样保留；对原 P/entry/generation metadata 的再编译和实际 kernel regression 继续分阶段记录，module identity 替换走协调 rebuild slot。


- **VERIFIED corpus invocation prepared（2026-11-12）** `kprog/test/verified_corpus.py <app> <samples> <duration> <stats>` 从已有 service supervisor 的 guest 调用冻结 `make __runtime-vm-corpus`，通过原有 `RUNTIME_ENV_BASE_NAMES` 接口显式转发 bound flag 和原始 artifact 保留开关。固定选择唯一镜像 current 和当前唯一 image tar，`post`/`norejit` 沿用原两次启动比较；app/workload/框架文件保持冻结定义。已有 `trusted-service-kvm` 的 guest CPU 与额外 vng 参数现可按调用设置（默认仍为 2 CPU、原 flag 集合），corpus 调用使用 8 CPU、64G 和原 `/run`、`/usr/local` overlays，加可写 `/var/tmp` 映射供冻结 Docker target 写临时 disk。此入口已准备交协调者用于 module/image rebuild 后的 BCC、Katran；实际 corpus 结果继续按 raw run 记录。


- **VERIFIED captured Katran compile（2026-11-12）** 8f1a1a8b4 的原 P/entry/generation metadata 再生成和编译全部 rc0（proof link、两段预处理、完整 B 编译），B ELF 为 1485544 bytes。目录 `/workspaces/kprog-raw/verified/20261112-stack-alias-compile/`，完整输出（含预处理 source）归档 `kprog/results/verified_20261112/stack-alias-compile*`。本项记录编译阶段，实际 stock verifier/native execution 继续按重跑 receipt 记录。


- **VERIFIED safety replay preparation（2026-11-12）** 既有 stock-path `run_safety.py` 增加对原 suite `build()` 的原地入口，默认工具/fixture 目录统一为唯一底座的 `verified-loader`、`verified-safety` 与 canonical linker。历史 cases/assembly/build/check 逻辑继续由原脚本执行，生成的 fixture/native/context/probe 位于该底座；raw replay `--out` 单独保留。`make -C kprog/libnativeloader trusted-safety-inputs BUILD_DIR=/workspaces/.agent-state/kprog-ck/verified-loader` 准备现有 38-case suite，后续在唯一 kernel/module 上 replay；历史 source-export/kernel-copy launcher 留作原始记录。第一轮 probe 构建因旧 native_chunk_count 日志字段失败；修正后发现 current fixture generator 为 47 cases，完整中间 build 已归档、9 份额外 fixture 的移动逐条记录 cleanup-log。build 改用原始 recorded cases 后 rc0，38 个 name/assembly/negative 标记与原记录完全一致（positive9/negative29）；原始 build/probe/contexts 见 `kprog/results/verified_20261112/safety-inputs*`。现有 classifier 同时识别 stock worker 的 verifier failure prefix，真实 Katran 拒绝档案分类为 verifier_rejected。


- **VERIFIED module runtime controls（2026-11-12）** 0ecc10f51 的同名 stock module 在唯一内核上通过现有三项 control，group rc0：原始 P/map capability capture 与 service EACCES；pending native load 的 snapshot 等待完成（false）；registered service 生成 B 经 stock verifier/JIT，原 source3 → native6 TEST_RUN retval2。raw `/workspaces/kprog-raw/verified/20261112-module-regressions/controls/`，完整 archive/receipt `kprog/results/verified_20261112/module-controls*`。actual Katran 同轮继续运行。协调者 08:39 已公布 IMAGE REBUILT，冻结镜像 corpus 可接续运行。


- **VERIFIED Katran completed diagnostic（2026-11-12）** typed stack alias store 8f1a1a8b4 在唯一 kernel 5f6e694bfd4d / 同名 stock module 0ecc10f51 上通过实际 upstream startup：loaded 1 / verified 1 / run 1，source6 → native9，service 四条生成/编译命令及 stock load 均 rc0，native9 attached XDP。source/native 各 TEST_RUN 一次，retval 均 2、64-byte output packet 相同，run_cnt 各为 1。raw `/workspaces/kprog-raw/verified/20261112-module-regressions/katran/`；完整 generated B/compiler/verifier/app/shim 与逐 ID counters 已归档 `kprog/results/verified_20261112/katran-completed*`。冻结镜像 corpus BCC/Katran 接续运行。

- **VERIFIED safety VM entry（2026-11-12）** 已有 38-case inputs 接入 `make -C kprog/libnativeloader trusted-safety-kvm BUILD_DIR=/workspaces/.agent-state/kprog-ck/verified-loader OUTPUT=<fresh raw dir>`：同一 kernel/base/module，fixture build 与 worker 复用已有 recipe；guest 仅载入 stock module，由原 check() 自己注册 service 并保持 negative load-only 协议。与 app supervisor 的 service 生命周期独立，kernel replay 将在当前 Katran compiler 完成后串行执行；guest recipe dry-run 通过，实际结果按 run 单列。

- **VERIFIED BCC current-image corpus（2026-11-12）** 唯一 kernel 5f6e694bfd4d / stock module 0ecc10f51 / current image（协调者 08:39 rebuilt）上的冻结两次启动 workload，1 sample × 10s、stats on、CPU8–19，make/app rc0。实际 source loaded 25 / stock verified + native installed 25 / workload run 17；25 份 worker archive 的生成/编译 returncode 全部为 0，stock load status 全部为 0，原始 native counters 的 ID 集与 service 安装 ID 集相同。逐 ID run_cnt_delta（包括 0）与完整 app stdout/stderr 保留。corpus `corpus/results/x86_kvm_corpus_20261112_085658_299095/`，service/raw `/workspaces/kprog-raw/verified/20261112-image-bcc/`；完整 archive/receipt `kprog/results/verified_20261112/image-bcc*`。本项为短样本功能覆盖，image Katran 和 original38 replay 接续。

- **VERIFIED Katran current-image corpus（2026-11-12）** sole kernel 5f6e694bfd4d / model 8f1a1a8b4 / current image 的冻结两次启动 workload，1×10s、stats on、CPU8–19，make/app rc0；loaded 1 / verified 1 / run 1，实际 source15 → native18，四条生成/编译命令与 stock load 全部 status0。workload native run_cnt_delta 19,865,512，raw run_time_ns_delta 3,932,891,086。corpus `corpus/results/x86_kvm_corpus_20261112_091130_181587/`，service/raw `/workspaces/kprog-raw/verified/20261112-image-katran/`；完整 archive/receipt `kprog/results/verified_20261112/image-katran*`。BCC 和 Katran 的唯一镜像 verified 功能覆盖均有本轮数据，其余四应用按实际失败类接续。

- **VERIFIED original38 safety replay（2026-11-12）** 唯一 kernel/model 8f1a1a8b4 的原地 replay 完成，suite make rc2，38 outcomes 全部保留：positive executed 9、verifier rejected 25、specializer rejected 1、load-only accepted_finding 3（uninitialized_stack、immediate_push_branch、stack_base_flags）。三个名字与 §3 原始 ABI open item / historical receipt 7cc7c2106 相同；各 negative command argc3，negative native execution 0。stack_oob、entry_return_slot_overwrite 继续 verifier rejected。原始目录 `/workspaces/kprog-raw/verified/20261112-safety-replay/`；完整 38 份 service request/generated B/compiler/load diagnostics、probe stdout/stderr 与 outcomes 在 `kprog/results/verified_20261112/safety-replay*`。通用模型调查继续，四应用实际 startup 按覆盖工作顺序接续。

- **VERIFIED safety artifact inspection（2026-11-12）** 原 replay 三份已编译 B 的 llvm-objdump-18 输出与 ELF 保存为 `kprog/results/verified_20261112/safety-inspection.tar.gz`，分析补入 safety-replay receipt：uninitialized_stack 的原 stack read 在 B 指令 33/41–48 保留；sole kernel 的 allow_uninit_stack 来自 CAP_PERFMON，按 MAX_BPF_STACK 接受该范围。另两条原 scalar-NULL load 的 B 返回 0，沿已有 READ_RECOVERY_AT；历史 exit-stack / branch-hardening receipts 同样记录这两个 recovered-NULL labels，current stock module 继续传递 load-site/stock register fixup。原 labels、stage 与 negative load-only 结果保留；§3 universal/physical correspondence 继续按原项跟踪。

- **VERIFIED Tetragon current-image first result（2026-11-12）** baseline workload 完成，280 个原程序有 raw counters；candidate 实际 source submissions 4 / stock verified + native installed 2 / run counters 待测（startup 先退出）。make rc0、app status error 分别保留；event_wake_up_new_task 两次重试均 B generated/compiled 后在 BPF2676 以 `R2 invalid mem access scalar` 拒绝。native R14 在 PC0x11 来自 pt_regs+112（DI 槽），BPF33 的 context read 为 scalar；PC0x3c7 的 R14+3328 load 在 recovery 的成功分支继续 ordinary scalar read。属于历史最大 scalar class。raw `/workspaces/kprog-raw/verified/20261112-image-tetragon/`，corpus `corpus/results/x86_kvm_corpus_20261112_092733_716003/`，四份完整 service/generated/compiler/verifier 与 native/B disassembly 归档 `kprog/results/verified_20261112/image-tetragon-first*`。通用 producer/helper-read 表达需求交 lane C，当前 canonical verifier-visible read 保持。

- **VERIFIED producer candidate integration（2026-11-12）** 已有 verified corpus wrapper 现在保留调用者的 `BPFREJIT_SHIM_NATIVE_MANIFEST`，默认继续 image 内 app manifest；整类 producer candidate 可放入 runtime 已可见的结果目录，再通过同一个 frozen corpus/service 路径提交。选择接口复用既有环境变量；kernel/image/框架文件继续沿用当前定义。Python syntax check 通过，actual candidate app 结果按运行单列。

- **VERIFIED Tetragon producer origin（2026-11-12）** native 原对象 DWARF 将 PC0x3c7 对应到 `vendor/bpf/tetragon/bpf/process/bpf_process_event.h:159` 的 `cred = task ? task->cred : 0`：MICRO_NATIVE_TETRAGON 的 direct metadata-read 分支。`__get_caps`、`get_current_subj_caps`、`get_namespaces` 三段 native guard 的 upstream else 已使用 probe-read helpers。该定位将此前 CORE_READ 调查收窄到 native-only credentials/namespaces lowering；producer 全类 selector 需求交 lane C，timing default bytes 保持当前参考。原对象 disassembly 为 `kprog/results/verified_20261112/tetragon-native-origin.tar.gz`，细节补入 image-tetragon-first receipt。

- **VERIFIED Tracee current-image first result（2026-11-12）** baseline 167 programs/workload 完成；candidate 4 source submissions / 2 verified native installs（security_bpf_kprobe194、lsm_bpf_check201）/ run 待测，主 raw_syscalls entry 两次因 stock used-map limit64 在 processed0 拒绝，后续 shim socket refused；make0/app error 分开保留。78 个 binding symbols 对应75个 kernel map IDs，但 native proof 仅引用2个，B 仅引用同2个加 unspecified map；worker 当前将所有 pins 填入 fd_array，导致 object-wide map dependencies 进入选中程序。raw `/workspaces/kprog-raw/verified/20261112-image-tracee/`，corpus `corpus/results/x86_kvm_corpus_20261112_093955_323073/`；完整 generated/compiler/loader/relocations 与 stdout/stderr 归档 `kprog/results/verified_20261112/image-tracee-first*`。下一步通用 worker 修复按 linked native relocations 填入 fd_array，完整 binding/pin 生命周期保持；外部 worker 原地 rebuild 交协调 slot。

- **VERIFIED worker map dependency fix（2026-11-12）** trusted worker 的 fd_array 现在由既有 linked.relocated_map_ids 生成，并继续将这些 FDs 放入原 pins 生命周期；完整 map binding metadata 与临时 pins 保留，B 的 LDDW maps 由 stock verifier 原机制跟踪。该通用修复消除把整份对象的所有 binding maps 附加到每个 entry 的行为，stock map limit 与所有程序继续按原路径运行。C++20 syntax-only 在现有 canonical build include/flags 下 rc0，raw `/workspaces/kprog-raw/verified/20261112-worker-map-dependencies/`；源码已准备，sole-base worker 原地 rebuild / 完整 Tracee regression 交协调 slot，runtime acceptance 按后续实际 run 记录。 后续主机启动使用 committed `kprog/test/run_verified_corpus.sh OUTPUT APP [extra make arguments...]`（setsid nohup）；复用 installed worker 时传既有 `-o trusted-service`，默认配置为 1×10s/stats on，沿用现有 SAMPLES/WORKLOAD_DURATION/BPFREJIT_CORPUS_BPF_STATS 覆盖。

- **VERIFIED follow-on order（2026-11-12）** BCC、Katran 的唯一镜像 corpus 完成后，以最新历史 `resident-census/master-grouped/README.md` / `result.json` 的分类作为下一轮定位起点：scalar memory access 230 instances / 116 bodies（Tetragon 123、Tracee 104、Cilium 3），随后 stack write 81 / 9 bodies、Clang source locations 23 / 23 bodies。该表的模型为 46659115e，记录的是 load-only stock verifier 阶段；当前 sole-kernel/model 8f1a1a8b4 的实际 app startup 继续分别收集并按实际诊断更新分类。下方 157 storage 排序保留为早期 grouped-static 记录。通用修复优先覆盖整个失败类别。

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
- [x] **A/协调者** grouped census 完整诊断已无损gzip与compact索引发布；协调者946562856完成限定超大文件历史修复，A普通push成功，所有peer提交保留。
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
- [x] **A** 观察内核预构建阶段按协调者21:50决策收尾：549resident/247body输入齐全，1024slot容量表示完成，GCC/Clang各1,226,840项UBSan与真实verifier/liveness/log对象编译通过（223e06735、e6388cf3e）。Linked kernel/guest观察实验停止，原始证据保留；verified回放使用统一kinsn-free内核。
- [x] **A** 按 `design.md` 的 region 切分做 spike：B 按基本块拆成 noinline 子函数，量 actions、process_filter、generic_kprobe_ 的栈深和 clang 时间。 本提交提供独立region_spike编译实验：actions为150基本块/214显式边/2原返回，完整状态跨block保留，Clang18 BPF syntax exit0；三体编译结果继续收集。 三体stage完成：actions150块/45.98s/state1264B、process_filter438块/179.42s/state1672B、process_event631块/436.82s/state2616B，全部compile0；原始输入/对象/log gzip归档，root state容量继续按storage157项处理。 协调者21:50决策后，此编译实验收尾，原始三体收据保留。
- [ ] **R/C** 应用级 B 生成时间（clang 单个 body 12–2,819 秒，最高 15.1 GB），论文的 54.52x 只来自 micro。
- [ ] **C** 100–100K 规模扫描，verifier 时间和内存。

- [x] **A** 按协调者21:50决策恢复ARM原始volatile栈表示（本提交）：撤回729/e2e scalar forwarding及六个host fixture中的cache声明/reset，保留全部原有语义assertions、隐式SP release与异常恢复；Python语法通过，direct dispatcher逐字相同。现有host回放单独收据。 host stage完成：GCC8/8 UBSan通过；Clang5/8 UBSan通过，三个child-fault boundary oracle按原Makefile flags全部通过，完整instrumentation诊断保留。11-08参考目录36覆盖文件/203原始观察/36entry名及native身份齐全。
- [ ] **A/C** 共享reverts完成后，用统一kinsn-free路径进行一次verified回放，与11-08最佳行逐行比较；A负责ARM，C负责x86。
- [x] **C** 相同af422c391运行文件完成原始ISA48和upstream315逐行回放/归档（114749e2b）：ISA10执行/29拒绝/1生成拒绝/8仅加载接受，315为58安装/91拒绝/137生成/29资源；315阶段与5afa逐行相同，风险native执行0；原注释与两条失败注释接受记录保留，安全发现按协调待办继续。
- [x] **C** x86审计回退和单内核切换：aee6栈布局39c529032、普通helper/copy参数1c85d1097、context/extent421c97bb8、原生branch指令a2a3c62ab、原上游BPF前端配对范围51711ed07、kernel pin47579c053、canonical stock loader70a4af5a8。统一回放模型5afa9bf29。
- [ ] **C/协调者/V** 原始ISA48回放的below-SP helper/memset/memcpy输出三例load-only接受结果进入协调决策；原字节与注释保留，风险native执行0，新增生产判定按批准规则处理。

- [x] **A** 协调者21:50要求的ARM helper检查撤回（本提交）：31个output-wrapper使用恢复原helper参数投影，移除below-SP output fault、libc额外prefetch及memcpy scalar-source fault；原有invocation-stack host在GCC/Clang18+UBSan均通过。实际guest回放沿共享revert项继续。

- [x] **A** ARM X19-X29 stock entry frame, SP-only RET, original ARM branch flags and matching tail cleanup published (fdc68ecea); Image/module/release builds0 and existing tail tests19/19 for each feature selection.
- [x] **A** Requested aee6/4f5 census comparison published (7d1d0d41d):549 identities, installed7->10, resources238, ELF names14, ENDBR11 and service-OOM transport276; exact2GiB/8GiB evidence and per-instance outcomes retained.
- [x] **A** Exact OOM-input parser attribution published (f3f1e6b9c):210call-to-following thunk edges and7return thunks normalize in4f5; input/module identities retained, parser-only generation/verifier submissions0.
- [x] **A** Existing ARM ISA48 fixed-frame replay collected: 48/48 cases, {"accepted_finding": 11, "specialization_rejected": 4, "valid_executed": 4, "verifier_rejected": 29}; original case bytes/annotations and suite exit 1 retained. Receipt entry-frame/isa48/replay; ARM applications remain deferred.

## 3. 安全：运行时缺口（有限用例和 guest 已验证）

- [x] 退出契约 RBP/R12/RSP、below-SP 栈生命周期（S7，cdeb9804d）；ARM 隐式 SP 回写（55504ff90）。
- [x] context 布局、尾调用帧、verifier 派生标志（S11，901194c0c）。
- [x] 部分宽度读的异常表恢复（S1、S2、S9、S10）；SMAP 分发（4ececd2cb）。
- [x] SIMD-free 原生代码（S14，0ead331cd）。
- [x] 间接分支加固 retpoline/ITS 和 BTI（S15，165ac4100）在 2026-11-09 按变更必要性审计撤回，native 代码回到原来的间接分支形式。
- [x] 安全用例 x86 47、ARM 48，接受的 8 例为良性恢复读，配对的写入变体被 verifier 拒绝（S16，ec468f0f7）。
- [x] 每个 armed 镜像只加载一次（fb23a234d、d140d92ab）。
- [x] **C** 入口桩保存恢复六个 callee-saved 寄存器，B的外层RET保持RSP判定（96c6946cf、kernel390ef9011c7d、canonical pin47579c053）；同模型ISA48/315与六应用回放属于上方统一回放项。
- [ ] **C** RSP 位移候选：clang inbounds GEP 对区域外访问的影响（compiled-B 义务）。

## 4. 安全：证明（对所有程序，一次证完；禁止逐程序）

| 项 | x86-64 | AArch64 | 负责 |
|---|---|---|---|
| O1 参考语义定义 | 67/75 | 74/74 | V |
| O1 raw 寄存器 handler 精化 | 34/75 | 条件式 74/74，raw 58/74 | V |
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
- [x] **V** raw CCMP/logical flags（40数值操作+6源分支）与交换ADD64观察器合并完整make check（源 37f561242，本提交归档实际exit0；136条raw公理审计及全部既有语义套件）。
- [x] **V** ARM raw ADDS/SUBS/CMP/CMN八操作：SP32/ZR31与全部tag物化、实际SRC/SRC2或DST/SRC角色、immediate/shift/extend、arithmetic result/NZCV、width/tag写回或完整compare raw/tag frame；production dispatcher与48数值+六源分支normalized emission step，新增12条及前136条审计/模块/root通过（本提交，raw48/74）。
- [x] **V** raw arithmetic flags（48数值操作+6源分支）批次完整make check（源 9c112535f，本提交归档actual exit0；包括后续MOV/address和全部既有语义套件）。
- [x] **V** ARM raw MOV_REG/ADRP_GOT/ADRP_RODATA：捕获raw/tag、W64复制/W32 scalar化、SP32/ZR31和SP相对坐标往返、MOV_IMM bitmask SP alias、GOT7/RODATA8及resolved IMM/native PC绑定；完整architecture/tag frame、production prefix和51数值+六源分支emission step，新增16条及前148条审计/模块/root通过（本提交，raw51/74）。
- [x] **V** raw move/address（51数值操作+6源分支）批次完整make check（源 9c112535f，本提交归档actual exit0；164条raw审计及全部既有语义套件）。
- [x] **V** ARM raw CNT/UADDLV：低/高64位primitive、AUX16/其余AUX分流、完整raw GPR/tag/SP/flags/memory/exclusive/其他vector frame、任意unused operand/FLAGS/IMM；production dispatcher与53数值+六源分支emission，新增6条及前164条审计/模块/root通过（本提交，raw53/74）。当前scalar producer策略沿用其域。
- [ ] **V** raw reduction（53数值操作+6源分支）批次完整make check，接续sole full队列并复用增量cache，保留固定源/actual exit。
- [x] **V** ARM raw ADD/SUB：捕获raw/tag与scalar/STACK条件绑定、任意entry origin的加减物化交换、实际SP32/STACK坐标写回、STACK SUB/tagged ADD/scalar分支、immediate aliases3/4与shift/extend；55数值+六源分支emission，新增9条及前170条审计/模块/root通过（本提交，raw55/74）。ALU_IMM/REG arithmetic AUX域同步精化，logical域继续。
- [ ] **V** raw arithmetic（55数值操作+6源分支）批次完整make check，接续sole full队列并复用增量cache，保留固定源/actual exit。
- [x] **V** ARM raw ALU_IMM/REG logical AUX：AND/BIC/EOR/ORR与已证ADD/SUB组合；实际STACK ORR raw坐标和小RHS在entrySP origin16对齐前提下物化，四种native shift/omitted amount、immediate unused SRC2/SP与ZR/alias；57数值+六源分支emission，新增8条及前179条审计/模块/root通过（本提交，raw57/74）。先前55操作保留原origin域，BIC-immediate沿用normalized complement形式。
- [ ] **V** raw logical ALU（57数值操作+6源分支）批次完整make check，接续sole full队列并复用增量cache，保留固定源/actual exit。
- [x] **V** ARM raw FMOV：四方向/32vector banks、raw/tag物化、vector high64清零/S_FROM_W low32截断、GPR width/scalar tag写回与完整architecture/tag frame；production支持legacy NONE255→V0、任意unused integer/SRC3/IMM及vector FLAGS或integer native-width绑定；58数值+六源分支emission，新增7条及前187条审计/模块/root通过（本提交，raw58/74）。当前scalar producer策略保持既有域。
- [ ] **V** raw FMOV（58数值操作+6源分支）批次完整make check，接续sole full队列并复用增量cache，保留固定源/actual exit。
- [x] **V** x86 raw JCC/JMP：完整raw GPR/byte-tag/flags/XMM/memory frame、PF-aware generated CC和实际前后向source goto、任意source→native label map且顺序独立；current specialized dispatcher保留unused FLAGS/DST/SRC/fresh与任意JMP AUX；10条新定理及6条原module审计/root编译通过，sorryAx0（本提交，x86 raw34/75）。Native label/entry image/C flag packing/physical/compiler接口显式。
- [ ] **V** x86 raw control（34数值操作，ARM58保留）批次完整make check，接续sole full队列并复用增量cache，保留固定源/actual exit。
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
- [x] **V** 全量检查通过（本提交归档的源版本 9c112535f，实际 make check exit0）；后续模型批次按第5节继续全量检查。
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
- [ ] 主树的 `corpus/driver.py`（冻结版）从 `runner/libs/rejit.py` 导入 `snapshot_app_maps`，主树的 `rejit.py` 已经改掉了这个函数，主树上 `make corpus` 在导入这一步就停下。计时目前用 `kprog/perf/may29-image` 从 9f3855f6f 读框架；主树框架要和冻结的 driver 重新对齐（运营者 2026-11-09："也要确保 benchmark framework 不能变化"）。
