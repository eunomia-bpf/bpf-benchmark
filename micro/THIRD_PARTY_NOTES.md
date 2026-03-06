# Third-Party Notes

`micro/` 现在不是凭空设计，主要参考了仓库里已经 vendored 的三类方案。

## 1. `microsoft/bpf_performance`

来源：`third-party/bpf_performance`

它最值得借鉴的是三点：

- 测试是声明式的，而不是把实验矩阵写死在代码里
- 一个测试被拆成 `map_state_preparation` 和 `test` 两个阶段
- 内核执行靠受控的 iteration count 和 CPU assignment，而不是“跑一次看看”

我们在 `micro/` 里直接吸收了其中两点：

- 用 `suite.yaml` 明确 benchmark / runtime / build 元数据，而不是在 runner 里散落硬编码
- 把输入生成和执行解耦，后面加 F2/F3 map/helper 实验时可以自然扩展出 preparation phase

## 2. `pchaigno/tail-call-bench`

来源：`third-party/tail-call-bench`

它的核心方法很直接：利用 `BPF_PROG_TEST_RUN` 风格的受控内核执行，重复多次并取均值，而不是依赖真实流量路径的噪声。

我们在 `micro/` 里沿用这个思路：

- kernel runtime 不做 attach，不走真实网卡路径
- 直接用 `libbpf` 调 `BPF_PROG_TEST_RUN`
- 每次样本都重新 load 一次，显式记录 load/JIT/verifier 时间和执行时间

## 3. `aspsk/bpf-bench`

来源：`third-party/bpf-bench`

这个项目的启发不在执行框架，而在输出习惯：

- benchmark 范围小而尖
- 结果先机器可读，再画图

所以 `micro/` 也先把 JSON 结果固定下来，再谈 plotting 和论文图表。

## 结论

`micro/` 当前采用的是混合方案：

- 结构上借鉴 `bpf_performance`
- 内核执行路径借鉴 `tail-call-bench`
- 输出形式借鉴 `bpf-bench`
- 依赖收口上改成正式 submodule（`llvmbpf` / `libbpf` / `bpftool`）
- 程序产物上改成单一 `.bpf.o`，避免 runtime 之间维护两套 wrapper

这样能得到一个同时支持 `kernel eBPF` 和 `llvmbpf`、而且依赖来源可追踪的微基准层。
