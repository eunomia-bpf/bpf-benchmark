# kprog 待办

协调者 2026-11-22T11:4xZ 按运营者原话整理：“arm64 不急, 你去写好 todo, 让 omp 或者 codex 在 workspace 里面继续实现, 也需要 lane 把它拉起来? 这样电脑关机还是可以产出. todo 要整理好. 不允许改动的不让改, 也不要调优, 只要确保实现正确加上功能一致.”
运营者原话全文在 kprog/docs/user-instruction.md，以原话为准。上一版待办在 git 历史。

## 一、目标（运营者原话）

- “只要确保实现正确加上功能一致.”（11-22）
- “接下来只允许修必要的 bug, 或者通过 profile 找大的性能问题, 框架不改动.”（11-22）
- “可以 profile 但是不允许做任何设计之外的事情或者细节调优, 必须跑几次确保数据全部都在.”（11-22）
- “库的特性探测程序无所谓, 但是在运行的必须是原生.”（11-22）

## 二、设计（kprog/docs/design.md）

1. P 从应用源码直接编成原生代码：O3，所有应用一组编译参数，兼容靠头文件。
2. 验证：可信服务把解释器 I 特化到 P，编成 eBPF B，交库存 verifier；接受即确证 P 内存安全。
3. 链接时优化：绑定 map 和 helper，就地内联 map 查找和 helper，内核直接执行原生代码。
4. 两种配置分别报告：主配置（验证加链接时优化）和直接原生（对照）。

## 三、不允许改动的（运营者原话）

- benchmark 框架和设置（runner/、corpus/、micro/、e2e/、kprog/perf/one-image/Makefile）：“整个 benchmark 框架不是说都不允许改动???”（11-20），“不许改 bench 除非我同意”（11-15）。
- 论文、故事、设计：保持原样（11-09、11-15）。
- 检查和守卫：“但不能任何额外的 check/guard?”（11-22），“不允许增加新的 check”（11-09）。
- 调优：“也不要调优”（11-22），“也不需要调参”（11-22）。
- 上游应用源码：“尽可能禁止改源代码”（11-13），“必要的话改一点是可以接受的”（11-15）。
- 冻结路径只经 kprog/docs/freeze-open.tsv 开放，钩子始终运行。
- 一个工作树、一个内核、一个镜像、一个底座；不开 worktree、clone、分支、stash；原始数据保留；用前向提交，不 revert；提交不带 AI 署名。

## 四、现在的状态（2026-11-23T14:1xZ）

- 路径 = 5/29（82ec89cb4）+ 必要修复 + 运营者要的改动，清单在第六节；在跑的代码是 dcf4a1aef（jiffies_64 地址保留，冻结 .rodata 读成常量）。
- 两边功能检查（dcf4a1aef）：六个应用 rc=0，在跑的程序全部原生（x86 OTel 14、BCC 25、Cilium 135、Tetragon 288、Tracee 169、Katran 1；arm64 13/23/102/91/73/1）。
- 两边完整计时：x86 kprog/results/x86-rotate-20261123（几何平均吞吐 1.206x、每次调用 1.292x），arm64 kprog/results/arm64-spark-run5-20261123（1.116x、1.126x）。
- kinsn x86：内核、14 个模块、镜像已建好；冻结框架下用 kinsn-5，只有 Cilium 能启动，其余五个应用的程序经 kinsn 改写后被 verifier 拒绝（kprog/results/kinsn-x86-20261123/README.md）。计时已停。

## 五、待办（按顺序；做完在行首写 [x] 和提交号）

0. **协调者：性能排查**（运营者 11-23：“性能是不是不够好? 为啥?”）。
   - [x] Cilium 11-22 的 0.461x：x86 链接器丢了 jiffies_64 的 GOT 读，时钟读到旧寄存器（dcf4a1aef 修好，11-23 每次调用 1.205x）。
   - [x] Katran：05-29 和 8430daa81 的原生 142–146 ns 来自旧链接器按调用顺序配查找点，三处 LRU 连接表查找拿到 stats 的 PERCPU_ARRAY 内联形式，每个包都返回 NULL，LRU 查找没做（kprog/results/katran-callorder-20261123，5c8423561）。Katran 的 05-29 底线和 OTel 的一样作废；现在原生和 eBPF 都是 180 ns。
   - Cilium：stats 关吞吐 1.169x，低于 05-29 的 1.319x。热点程序 cil_from_container 的 eBPF 臂本身 05-29 是 486 ns、11-21 是 619 ns、11-23 是 726 ns，基线阶段的程序数 11-21 是 53、11-22 起是 90–92。先查这两个变化从哪里来，再判断 05-29 的 Cilium 底线能否对比。
   - OTel：每次调用 0.930x。宿主 PMU 采样（kprog/results/profile-20261123/profile-host.sh）显示：72 处多 map 查找 eBPF 也走通用 helper（kprog/results/lookup-binding-20261123）；差别在 LPM trie 查找，原生走通用 helper，eBPF 直调 trie_lookup_elem，通用 helper 里那一个间接调用的目标来回换（array_map_lookup_elem+0x7 原生 15204 样本、eBPF 1128）。77908203a 让已知的 LPM trie 直调 trie_lookup_elem；镜像、检查、OTel profile、四个有 LPM trie 的应用（OTel、Cilium、Tetragon、Tracee）重测由 kprog/results/trie-direct-20261123/chain.sh 进行。
   - map-in-map 的内层表：verifier 按外层表的内层模板内联，原生原来调通用 helper（Tracee 直线代码上 1404 处，Cilium、Katran 各 2 处；kprog/results/lookup-binding-20261123）。30e401e37：shim 在 BPF_MAP_CREATE 时记下 inner_map_fd 的模板，加载器给出“<map>#inner”形式，x86、arm64 链接器把外层查找的结果记成“<map>#inner”。
   - 重测：trie 那一轮在 OTel stats 关之后停（STOP），inner-20261123/chain.sh 用 30e401e37 重建 x86 镜像、检查，再对 OTel、Cilium、Tetragon、Tracee、Katran 完整计时；arm64 镜像和检查由 trie-direct-20261123/arm64-chain.sh 进行，之后在 Spark 上补测受影响的应用。
   - 只修设计之内的必要问题，修好后只补测受影响的应用。
1. [x] **omp：arm64 功能检查结果**（11-22 11:18–12:22Z，六个应用 rc=0，在跑的程序全部原生：OTel 13、BCC 23、Cilium 102、Tetragon 91、Tracee 73、Katran 1）。 六个应用 rc=0、在跑的程序全部原生，即完成。有失败时：
   - 找原因，只修让程序跑通、结果正确的必要 bug；
   - 提交；
   - 用 make -C kprog/perf/one-image-arm64 image 和 check 重查；
   - 用 make -C kprog/perf/one-image check 确认 x86 照旧通过（等计时结束再跑 x86 检查）。
2. **验证一侧。**
   - omp：B 剩下几类被库存 verifier 拒绝（kprog/results/pointer-launder-20261122/remaining-classes.txt；r3 栈帧 520 B 来自 3ffc87abc），做到主配置下在跑的程序全部原生。
   - V：每条指令的证明（kprog-lanes/V/prompt.md）。
   - formal：证明迁移 M5–M6。 CSEL 选中写回 120 步通过（260 项聚焦构建、2 项查询），EQ 条件至写回 186 步通过（261 项、1 项查询）；记录 formal/results/m5-select-write 和 m5-select-eq-write。原始 23 个 dispatch gate 及 handler 的完整 CSEL64/EQ body 已通过（262/263 项聚焦构建，2/1 项查询；formal/results/m5-select-dispatch、m5-select-body）；真实九参 CSEL 调用的分配、释放与返回已通过（264 项聚焦构建、1 项查询；formal/results/m5-select-generic-call）；原始第七调用点及 98 个 provider 输入到七调用/七原生步的完整前缀已通过（265/316 项聚焦构建、2/1 项查询；formal/results/m5-select-caller、m5-entry-select-prefix-native），第七取指由真实前六步传递（271 项、2 项查询）。CNEG/GE 的原始九参调用点、LNSym CSNEG/LT 别名、实际 GE helper（28 步）及原始 scalar-reader 调用入口（8 步）已通过（256 项聚焦构建、13 项接口查询；formal/results/m5-cneg-preparation）。读取及返回组合已通过：普通 scalar 路径 85 步、warm-stack 路径 103 步（251 项聚焦构建、3 项查询；formal/results/m5-cneg-scalar-read）。真实 GE 调用点（加载四个头部指针、原始 helper 及归一化）51 步已通过（253 项聚焦构建、5 项查询；formal/results/m5-cneg-condition-site）。上述组件已接入实际根模块（400 项定向构建、21 项接口查询；formal/results/m5-cneg-root）。CNEG 原始 scalar 写回调用、真实存储及返回 69 步已通过（254 项聚焦构建、1 项查询；formal/results/m5-cneg-writer）。CNEG 实际数值体、条件取负、结果复制及内层循环退出 38 步已通过（254 项聚焦构建、2 项查询；formal/results/m5-cneg-numeric）。数值体与写回已接入实际根模块（411 项定向构建、3 项接口查询；formal/results/m5-cneg-body-components-root）。原始 scalar/warm-stack 读取、GE、数值体与真实写回的整条 CNEG 分支组合已通过（256 项聚焦构建、1 项查询；formal/results/m5-cneg-path）。CNEG 原始宽度 helper 与前九个 dispatch gate 已通过（构造 79 步；257 项聚焦构建、2 项查询；formal/results/m5-cneg-dispatch）。完整 CNEG64/GE handler body（真实读取、条件、数值、存储及外层循环退出）已通过（258 项聚焦构建、1 项查询；formal/results/m5-cneg-body）。完整 CNEG body 与取指后的 LNSym CSNEG/LT 步、全部寄存器及 PC/事件/故障对应已通过（262 项聚焦构建、1 项查询；formal/results/m5-cneg-body-native）。原始九参数 CNEG 通用调用、真实帧分配与释放、返回及原生对应已通过（264 项聚焦构建、1 项查询；formal/results/m5-cneg-generic-call）。原始第八调用点、真实 afterCneg 返回及全部有限行为已通过（265 项聚焦构建、2 项查询；formal/results/m5-cneg-caller）。第八取指、PC+28 与无错状态已由真实前七步及输入 setup 传递（274 项聚焦构建、2 项查询；formal/results/m5-cneg-admission）。本批 handler、原始调用及取指证明已接入实际根模块（422 项定向构建、10 项接口查询；formal/results/m5-cneg-handler-root）。CSEL 实际存储到 CNEG source5 的 scalar/tag0 或 stack-relative/tag4 输入传递已通过（330 项聚焦构建、1 项查询；formal/results/m5-cneg-selected-source）。原始 98 个 provider 输入到八调用/八原生步的完整前缀已通过（332 项聚焦构建、1 项查询；formal/results/m5-entry-cneg-prefix-native），source5/tag/cache 由真实前序存储传递。完整八调用前缀已接入实际根模块（424 项定向构建、2 项查询；formal/results/m5-entry-cneg-root）。原始第九 ORN32 调用九参数、打包 AUX 及取指后的 LNSym ORN W7,W6,W3,LSL1 原生步已通过（256 项聚焦构建、7 项查询；formal/results/m5-orn-preparation）。实际宽度四 LSL1 modifier 的 41 步执行及原 LSL0 接口已通过（236 项聚焦构建、2 项查询；formal/results/m5-orn-modifier）。真实 LSL1 helper 五参数入口、scalar 读取、修饰及函数返回 119 步已通过（238 项聚焦构建、1 项查询；formal/results/m5-orn-modified-call）。ORN caller/native 与 LSL1 helper 本批已接入实际根模块（430 项定向构建、10 项查询；formal/results/m5-orn-components-root）。ORN 原始左读取调用点、scalar/warm-stack 读取及复制已通过（入口 8 步、完整 85/103 步；253 项聚焦构建、6 项查询；formal/results/m5-orn-read-entry）。ORN 实际 RHS 五参数解码、LSL1 helper 及返回复制 126 步已通过（264 项聚焦构建、5 项查询；formal/results/m5-orn-rhs-call）。ORN 实际宽度四掩码准备及 OR-NOT 数值、结果复制、内层退出 34 步已通过（264 项聚焦构建、2 项查询；formal/results/m5-orn-numeric）。ORN 原始 scalar writer 调用、实际存储及返回 69 步已通过（254 项聚焦构建、1 项查询；formal/results/m5-orn-writer）。ORN 原始 scalar/warm-stack 左读取、真实 LSL1 右读取、数值及实际写回的整分支已通过（266 项聚焦构建、2 项查询；formal/results/m5-orn-path），六项 RHS 加载由真实 storage 推出。ORN 原始宽度 helper 与前 21 个 dispatch gate 已通过（131 步；268 项聚焦构建、2 项查询；formal/results/m5-orn-dispatch）。ORN 完整 handler body（真实宽度、dispatch、两次读取、LSL1、OR-NOT、存储和外层循环退出）已通过（268 项聚焦构建、1 项查询；formal/results/m5-orn-body）。ORN 完整 body 与取指后 LNSym ORN32 步、全部寄存器及 PC/事件/故障对应已通过（273 项聚焦构建、2 项查询；formal/results/m5-orn-body-native），低 32 位写回等式单独证明。ORN 本批 source/native body 已接入实际根模块（442 项定向构建、21 项根接口查询；formal/results/m5-orn-handler-root）。ORN 原始九参数 generic 调用、真实帧分配与释放、返回及完整原生对应已通过（274 项聚焦构建、1 项查询；formal/results/m5-orn-generic-call）。ORN 原始第九调用点、实际 afterOrn 返回与全部有限行为已通过（275 项聚焦构建、2 项查询；formal/results/m5-orn-caller）。第九取指、PC+32 与无错状态已由真实前八步及输入 setup 传递（276 项聚焦构建、2 项查询；formal/results/m5-orn-admission）。原始 98 个 provider 输入到九调用／九原生步的完整前缀已通过（347 项聚焦构建、1 项查询；formal/results/m5-entry-orn-prefix-native），两个 ORN scalar/tag0 输入均由真实前序存储传递。完整九调用前缀已接入实际根模块（446 项定向构建、6 项根接口查询；formal/results/m5-entry-orn-root）。原始第十 FMOV D3,X7 调用九参数、实际 caller 入口返回及 LNSym 解码／原生步已通过（258 项聚焦构建、9 项查询；formal/results/m5-fmov-preparation），D3 高 64 位清零由导入语义推出。实际 FMOV destination helper 四种合法方向的完整调用均已通过（各 23 步；45 项聚焦构建、2 项查询；formal/results/m5-fmov-destination）。FMOV 原始 destination 调用点、真实 helper 返回及向量存储分支选择已通过（2+23+3 步；255 项聚焦构建、5 项查询；formal/results/m5-fmov-destination-site）。FMOV 本批 caller／native／destination 组件已接入实际根模块（452 项定向构建、16 项根接口查询；formal/results/m5-fmov-components-root）。实际 512 字节向量局部数组到全部 64 个半部的可写访问、真实 store／owned frame 权限传递已通过（177 项聚焦构建、5 项查询；formal/results/m5-vector-writable）。FMOV 实际向量／scalar 读取及返回完整前缀 99 步已通过（258 项聚焦构建、5 项查询；formal/results/m5-fmov-read-entry）。FMOV 真实 producer 向量指针、scalar 输入及十个 ABI／宽度参数保持已通过（258 项聚焦构建、2 项查询；formal/results/m5-fmov-read-operands）。FMOV 原始 mode0 数值体、结果复制及内层循环退出 16 步已通过（258 项聚焦构建、2 项查询；formal/results/m5-fmov-numeric）。FMOV 读取 99 步、数值 16 步及原始 destination 28 步到真实向量存储点的组合已通过（259 项聚焦构建、1 项查询；formal/results/m5-fmov-store-entry）。本批可写权限及 FMOV 读取／数值／destination 组合已接入实际根模块（460 项定向构建、15 项根接口查询；formal/results/m5-fmov-read-store-root）。FMOV 两个真实向量存储的成功性、最终低／高读取、其余 31 个向量及所有其他块保持已通过（178 项聚焦构建、7 项查询；formal/results/m5-fmov-vector-memory）。FMOV 两个真实写回后的 producer storage、全部 GPR／tag 单元、SP／标志／向量指针保持已通过（179 项聚焦构建、5 项查询；formal/results/m5-fmov-vector-storage）。FMOV 原始选择、两个实际指针加载和低／高赋值共 14 步执行已通过（264 项聚焦构建、3 项查询；formal/results/m5-fmov-vector-write）。FMOV 原始读取、数值、真实 destination helper 及双向量写回的完整分支 157 步已通过（264 项聚焦构建、1 项查询；formal/results/m5-fmov-path）。FMOV 完整分支及真实写回／storage 组件已接入实际根模块（466 项定向构建、16 项根接口查询；formal/results/m5-fmov-vector-root）。FMOV 原始宽度 helper、全部 37 个实际 dispatch gate 及九参数保持共 187 步已通过（266 项聚焦构建、2 项查询；formal/results/m5-fmov-dispatch）。FMOV 原始宽度、dispatch、完整分支及真实外层循环退出共 346 步已通过（266 项聚焦构建、1 项查询；formal/results/m5-fmov-body）。FMOV 真实 GPR／SP／NZCV／向量读取视图已通过（180 项聚焦构建、5 项查询；formal/results/m5-fmov-vector-view）。FMOV 真实 source7／tag0 到 LNSym X7、D3 清高位及完整寄存器对应已通过（274 项聚焦构建、6 项查询；formal/results/m5-fmov-native-view）。FMOV 完整原始 handler 与取指后的 LNSym 步、全部寄存器及 PC／事件／故障对应已通过（274 项聚焦构建、1 项查询；formal/results/m5-fmov-body-native）。FMOV 原始九参数通用调用、真实分配／释放／返回及完整原生对应已通过（275 项聚焦构建、1 项查询；formal/results/m5-fmov-generic-call）。FMOV 原始第十调用点、真实 afterFmov 返回与全部有限行为已通过（276 项聚焦构建、2 项查询；formal/results/m5-fmov-caller）。第十 FMOV 取指、PC+36 与无错状态已由真实前九步及原始输入 setup 传递（278 项聚焦构建、2 项查询；formal/results/m5-fmov-admission）。本批 FMOV 完整 handler／真实调用／第十取指证明已接入实际根模块（474 项定向构建、20 项根接口查询；formal/results/m5-fmov-handler-root）。原始 512 字节向量分配的可写权限已贯穿全部实际 storage 构造、存储与分配／释放帧；真实向量指针和原生对应推出旧低半部读取（聚焦构建及 5 项查询；formal/results/m5-fmov-inputs）。FMOV 实际双向量存储后的 12 个头部指针、真实 borrowed 读取与 warm-cache 谓词传递已通过（3 项查询；formal/results/m5-fmov-cache-frame）。原始 98 个 provider 输入到十调用／十原生步的完整前缀已通过（1 项查询；formal/results/m5-entry-fmov-prefix-native），向量权限、旧低半部和 source7/tag0 均由实际分配与前序执行推出，保留全部既有契约。原始第十一 CNT 调用九参数、实际 caller 入口／返回及导入 LNSym CNT V0.16B,V0.16B 步已通过（9 项查询；formal/results/m5-cnt-native）；继续实际 reduction helper 与完整 body 对应。完整十调用前缀、原始向量权限／缓存传递及第十一 CNT caller／原生绑定已接入实际根模块（484 项定向构建、18 项根接口查询；formal/results/m5-entry-fmov-root）。CNT 实际共享 popcount C 完整调用 11 步、全部字节值的导入语义对应及八个真实移位／掩码参数已通过（179 项聚焦构建、3 项查询；formal/results/m5-cnt-popcount）。CNT 向量0双半部真实存储、最终读取及其余31向量保持已由原始分配权限推出（7 项查询；formal/results/m5-cnt-vector-memory）。CNT 双半部写回后的真实 producer storage、全部 GPR／tag／SP／标志／向量指针及权限保持已通过（181 项聚焦构建、3 项查询；formal/results/m5-cnt-vector-storage）。CNT 导入完整字循环、八个字节写入及拼接对应已通过（2 项查询；formal/results/m5-cnt-lanes）。CNT 双写回后的真实 GPR／SP／NZCV／向量读取视图已通过（5 项查询；formal/results/m5-cnt-vector-view）。CNT 原始 reduction 八次真实 helper 调用、累积、循环退出和完整返回已通过（176 步、1 项查询；formal/results/m5-cnt-reduction）。本批 CNT 实际 popcount／八次调用 reduction 已接入根模块（486 项定向构建、4 项根接口查询；formal/results/m5-cnt-reduction-root）。CNT 原始高／低调用点、真实链接 reduction 和 caller 返回已通过（183 项聚焦构建、3 项查询；formal/results/m5-cnt-reduction-site）。下一步将实际 packed 字节结果对应到导入的完整字计数，再完成 CNT 真实向量读取、双半部写回、完整 handler 与第十一调用／原生步组合。统一 make check 保留 V 报告的 DIV 故障路径回归。
3. [x] **协调者：x86 完整计时**（11-22 12:22–17:40Z，数据齐全，结果在 kprog/results/x86-rotate-20261122）。
   - 结果出来后核对每个应用的样本和时长都齐全，缺的补跑。
   - 和 5/29 对比，写进 kprog/results。
   - 计时期间，lane 耗 CPU 的工作都放在 flock -s /workspaces/.agent-state/kprog-lanes/locks/timing 里。
4. **协调者：arm64 完整计时**（不急）：在 Spark 上跑，暂停 DeepSeek，测完立即恢复。
5. **协调者：数字写进论文**（agent 不改论文）。

## 六、路径上保留的内容（5/29 之外只有这些）

1. **今天内核的接口**：
   - 内核模块接收原生代码，装载器先装最小的 eBPF 占位程序，再挂原生代码；
   - Tetragon 在今天内核上的编译选项和函数声明。
2. **修 bug**：
   - helper 绑到这个程序类型对应的内核函数；
   - Cilium 配置值按程序自己的类型信息定位；装载器拿住找到的数据 map，直到原生程序接手；
   - Tracee 的字符串常量留在原生代码里；
   - OTel 经内核性能事件上下文读采样寄存器；
   - map 查找按 map 名字配到它自己的 map，名字确定不了时调内核通用 helper；
   - 尾调用跳走前恢复寄存器；
   - 测量拦截库在原生替换完成之后开始计数；
   - arm64：编译配置、程序内调用、尾调用、数据地址、代码段合并；按位条件跳转在重新排布后改目标；读内存的位置登记到内核异常表。
3. **运营者要的**：
   - helper 按名字调用，删掉 arm64 按编号的运行时挑选；
   - 时钟和 jiffies 用 C 写在头文件里；
   - 读内核内存是普通内存读；
   - map 更新、删除在 map 已知时直接调用该类型的函数（“这个是我要的啊”）。

## 七、lane 和怎么拉起（电脑关机时照常运行）

- **omp**：集群值守 agent-duties/bpf-benchmark-supervisor，每 10 分钟续跑同一会话，prompt 在 /workspaces/.agent-state/bpf-benchmark-supervisor/prompt.md。
- **V、formal**：集群 Codex，kprog-lanes/<lane>/runner 加 lane-loop.sh；集群守护 kprog-lane-keeper 每 10 分钟拉起停掉的 loop。
- **纠偏**：写 kprog-lanes/<lane>/resume-msg.md，并在 kprog-lanes/COORDINATION.md 记一行。
