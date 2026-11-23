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

## 四、现在的状态（2026-11-22T11:4xZ）

- 路径 = 5/29（82ec89cb4）+ 必要修复 + 运营者要的改动，清单在第六节。
- x86 功能检查（09613661f 的代码，10:51–11:11Z）：六个应用 rc=0，在跑的程序全部原生（OTel 14、BCC 25、Cilium 135、Tetragon 288、Tracee 169、Katran 1）。
- arm64 功能检查 11:18Z 起在跑：结果写在 /workspaces/kprog-raw/coordinator/restore-529/chain18.done 和 /workspaces/kprog-raw/one-image-arm64-runs/check.log。
- x86 完整计时排在 arm64 检查之后自动开始（协调者 chain19，冻结入口的 rotate），进度在 /workspaces/kprog-raw/one-image-runs/progress.log，计时期间持有 locks/timing。

## 五、待办（按顺序；做完在行首写 [x] 和提交号）

0. **协调者：Cilium、Katran 退步**（x86 计时 11-22 12:22–17:40Z，kprog/results/x86-rotate-20261122）：Cilium 每次调用 0.461x（8430daa81 是 1.108x），Katran 1.007x（1.239x）。
   - 先查 map 查找走内核通用 helper 的位置：map 名字经寄存器拷贝、栈溢出就丢了。对照内核对同一程序的绑定。
   - 只修设计之内的必要问题，修好后只补测 Cilium、Katran。
1. [x] **omp：arm64 功能检查结果**（11-22 11:18–12:22Z，六个应用 rc=0，在跑的程序全部原生：OTel 13、BCC 23、Cilium 102、Tetragon 91、Tracee 73、Katran 1）。 六个应用 rc=0、在跑的程序全部原生，即完成。有失败时：
   - 找原因，只修让程序跑通、结果正确的必要 bug；
   - 提交；
   - 用 make -C kprog/perf/one-image-arm64 image 和 check 重查；
   - 用 make -C kprog/perf/one-image check 确认 x86 照旧通过（等计时结束再跑 x86 检查）。
2. **验证一侧。**
   - omp：B 剩下几类被库存 verifier 拒绝（kprog/results/pointer-launder-20261122/remaining-classes.txt；r3 栈帧 520 B 来自 3ffc87abc），做到主配置下在跑的程序全部原生。
   - V：每条指令的证明（kprog-lanes/V/prompt.md）。
   - formal：证明迁移 M5–M6。 CSEL 选中写回 120 步通过（260 项聚焦构建、2 项查询），EQ 条件至写回 186 步通过（261 项、1 项查询）；记录 formal/results/m5-select-write 和 m5-select-eq-write。原始 23 个 dispatch gate 及 handler 的完整 CSEL64/EQ body 已通过（262/263 项聚焦构建，2/1 项查询；formal/results/m5-select-dispatch、m5-select-body）；真实九参 CSEL 调用的分配、释放与返回已通过（264 项聚焦构建、1 项查询；formal/results/m5-select-generic-call）；原始第七调用点及 98 个 provider 输入到七调用/七原生步的完整前缀已通过（265/316 项聚焦构建、2/1 项查询；formal/results/m5-select-caller、m5-entry-select-prefix-native），第七取指由真实前六步传递（271 项、2 项查询）。CNEG/GE 的原始九参调用点、LNSym CSNEG/LT 别名、实际 GE helper（28 步）及原始 scalar-reader 调用入口（8 步）已通过（256 项聚焦构建、13 项接口查询；formal/results/m5-cneg-preparation）。读取及返回组合已通过：普通 scalar 路径 85 步、warm-stack 路径 103 步（251 项聚焦构建、3 项查询；formal/results/m5-cneg-scalar-read）。真实 GE 调用点（加载四个头部指针、原始 helper 及归一化）51 步已通过（253 项聚焦构建、5 项查询；formal/results/m5-cneg-condition-site）。上述组件已接入实际根模块（400 项定向构建、21 项接口查询；formal/results/m5-cneg-root）。CNEG 原始 scalar 写回调用、真实存储及返回 69 步已通过（254 项聚焦构建、1 项查询；formal/results/m5-cneg-writer）。CNEG 实际数值体、条件取负、结果复制及内层循环退出 38 步已通过（254 项聚焦构建、2 项查询；formal/results/m5-cneg-numeric）。数值体与写回已接入实际根模块（411 项定向构建、3 项接口查询；formal/results/m5-cneg-body-components-root）。原始 scalar/warm-stack 读取、GE、数值体与真实写回的整条 CNEG 分支组合已通过（256 项聚焦构建、1 项查询；formal/results/m5-cneg-path）。CNEG 原始宽度 helper 与前九个 dispatch gate 已通过（构造 79 步；257 项聚焦构建、2 项查询；formal/results/m5-cneg-dispatch）。完整 CNEG64/GE handler body（真实读取、条件、数值、存储及外层循环退出）已通过（258 项聚焦构建、1 项查询；formal/results/m5-cneg-body）。完整 CNEG body 与取指后的 LNSym CSNEG/LT 步、全部寄存器及 PC/事件/故障对应已通过（262 项聚焦构建、1 项查询；formal/results/m5-cneg-body-native）。原始九参数 CNEG 通用调用、真实帧分配与释放、返回及原生对应已通过（264 项聚焦构建、1 项查询；formal/results/m5-cneg-generic-call）。原始第八调用点、真实 afterCneg 返回及全部有限行为已通过（265 项聚焦构建、2 项查询；formal/results/m5-cneg-caller）。第八取指、PC+28 与无错状态已由真实前七步及输入 setup 传递（274 项聚焦构建、2 项查询；formal/results/m5-cneg-admission）。本批 handler、原始调用及取指证明已接入实际根模块（422 项定向构建、10 项接口查询；formal/results/m5-cneg-handler-root）。CSEL 实际存储到 CNEG source5 的 scalar/tag0 或 stack-relative/tag4 输入传递已通过（330 项聚焦构建、1 项查询；formal/results/m5-cneg-selected-source）。原始 98 个 provider 输入到八调用/八原生步的完整前缀已通过（332 项聚焦构建、1 项查询；formal/results/m5-entry-cneg-prefix-native），source5/tag/cache 由真实前序存储传递。完整八调用前缀已接入实际根模块（424 项定向构建、2 项查询；formal/results/m5-entry-cneg-root）。原始第九 ORN32 调用九参数、打包 AUX 及取指后的 LNSym ORN W7,W6,W3,LSL1 原生步已通过（256 项聚焦构建、7 项查询；formal/results/m5-orn-preparation）。实际宽度四 LSL1 modifier 的 41 步执行及原 LSL0 接口已通过（236 项聚焦构建、2 项查询；formal/results/m5-orn-modifier）。真实 LSL1 helper 五参数入口、scalar 读取、修饰及函数返回 119 步已通过（238 项聚焦构建、1 项查询；formal/results/m5-orn-modified-call）。ORN caller/native 与 LSL1 helper 本批已接入实际根模块（430 项定向构建、10 项查询；formal/results/m5-orn-components-root）。ORN 原始左读取调用点、scalar/warm-stack 读取及复制已通过（入口 8 步、完整 85/103 步；253 项聚焦构建、6 项查询；formal/results/m5-orn-read-entry）。ORN 实际 RHS 五参数解码、LSL1 helper 及返回复制 126 步已通过（264 项聚焦构建、5 项查询；formal/results/m5-orn-rhs-call）。ORN 实际宽度四掩码准备及 OR-NOT 数值、结果复制、内层退出 34 步已通过（264 项聚焦构建、2 项查询；formal/results/m5-orn-numeric）。ORN 原始 scalar writer 调用、实际存储及返回 69 步已通过（254 项聚焦构建、1 项查询；formal/results/m5-orn-writer）。ORN 原始 scalar/warm-stack 左读取、真实 LSL1 右读取、数值及实际写回的整分支已通过（266 项聚焦构建、2 项查询；formal/results/m5-orn-path），六项 RHS 加载由真实 storage 推出。ORN 原始宽度 helper 与前 21 个 dispatch gate 已通过（131 步；268 项聚焦构建、2 项查询；formal/results/m5-orn-dispatch）。ORN 完整 handler body（真实宽度、dispatch、两次读取、LSL1、OR-NOT、存储和外层循环退出）已通过（268 项聚焦构建、1 项查询；formal/results/m5-orn-body）。ORN 完整 body 与取指后 LNSym ORN32 步、全部寄存器及 PC/事件/故障对应已通过（273 项聚焦构建、2 项查询；formal/results/m5-orn-body-native），低 32 位写回等式单独证明。ORN 本批 source/native body 已接入实际根模块（442 项定向构建、21 项根接口查询；formal/results/m5-orn-handler-root）。ORN 原始九参数 generic 调用、真实帧分配与释放、返回及完整原生对应已通过（274 项聚焦构建、1 项查询；formal/results/m5-orn-generic-call）。ORN 原始第九调用点、实际 afterOrn 返回与全部有限行为已通过（275 项聚焦构建、2 项查询；formal/results/m5-orn-caller）。第九取指、PC+32 与无错状态已由真实前八步及输入 setup 传递（276 项聚焦构建、2 项查询；formal/results/m5-orn-admission）。原始 98 个 provider 输入到九调用／九原生步的完整前缀已通过（347 项聚焦构建、1 项查询；formal/results/m5-entry-orn-prefix-native），两个 ORN scalar/tag0 输入均由真实前序存储传递。完整九调用前缀已接入实际根模块（446 项定向构建、6 项根接口查询；formal/results/m5-entry-orn-root）。原始第十 FMOV D3,X7 调用九参数、实际 caller 入口返回及 LNSym 解码／原生步已通过（258 项聚焦构建、9 项查询；formal/results/m5-fmov-preparation），D3 高 64 位清零由导入语义推出。实际 FMOV destination helper 四种合法方向的完整调用均已通过（各 23 步；45 项聚焦构建、2 项查询；formal/results/m5-fmov-destination）。FMOV 原始 destination 调用点、真实 helper 返回及向量存储分支选择已通过（2+23+3 步；255 项聚焦构建、5 项查询；formal/results/m5-fmov-destination-site）。FMOV 本批 caller／native／destination 组件已接入实际根模块（452 项定向构建、16 项根接口查询；formal/results/m5-fmov-components-root）。实际 512 字节向量局部数组到全部 64 个半部的可写访问、真实 store／owned frame 权限传递已通过（177 项聚焦构建、5 项查询；formal/results/m5-vector-writable）。FMOV 实际向量／scalar 读取及返回完整前缀 99 步已通过（258 项聚焦构建、5 项查询；formal/results/m5-fmov-read-entry）。下一步 FMOV 真实读取、数值与向量写回组合。统一 make check 保留 V 报告的 DIV 故障路径回归。
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
