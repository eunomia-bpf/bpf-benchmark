# benchmark framework app 候选调研（2026-04-25）

## TL;DR

- 当前框架的 shared app runner 只剩 5 个家族：`bcc`、`bpftrace`、`katran`、`tetragon`、`tracee`。`scx` 已在 `2026-04-25` 因 `struct_ops` ReJIT 后会把 scheduler 打坏而被整体移除。
- 历史上 shared runner 明确支持过但现在被删掉的 app 有 11 个：`calico`、`coroot-node-agent`、`datadog-agent`、`kubearmor`、`libbpf-bootstrap`、`loxilb`、`suricata`、`systemd`、`tubular`、`xdp-tools`、`xdp-tutorial`。
- 现有 checked-in `corpus/results/` 里，能明确看到历史跑过或至少进入过 source-level corpus 的还有 `calico`、`suricata`、`cilium`、`netbird`、`opentelemetry-ebpf-profiler`。其中 `calico/suricata/cilium` 都有比较强的证据链。
- 当前 5 个 app 家族基于最近一批仍保留 `programs` 明细的成功结果，共覆盖 111 个已加载 BPF program、8 个 program type：`kprobe`、`tracepoint`、`raw_tracepoint`、`tracing`、`perf_event`、`socket_filter`、`sched_cls`、`xdp`。
- `socket_filter` 其实已经被 `tetragon/default` 覆盖，真正明显缺的是 `cgroup_*` 家族、`lsm`、`sockops`、`sk_msg`、`sk_skb`、`flow_dissector`、`fentry/fexit`，以及 `scx` 删除后留下的 `struct_ops` 空洞。
- 如果只看“真实生产 BPF app + 能在 KVM VM 里跑 + 程序数量尽量多 + 尽量补 type 空白”，我的优先级建议是：
  - P0: `systemd`、`cilium`
  - P1: `calico`、`suricata`、`loxilb`、`merbridge`
  - P2: `KubeArmor`

## 1. 历史 app 调研

### 1.1 当前 shared runner 只剩 5 个家族

`runner/libs/app_runners/__init__.py` 当前只注册：

- `bcc`
- `bpftrace`
- `katran`
- `tetragon`
- `tracee`

`corpus/config/macro_apps.yaml` 当前对应 19 个 workload：

- 10 个 `bcc/*`
- 6 个 `bpftrace/*`
- `katran`
- `tetragon/default`
- `tracee/default`

### 1.2 明确被删除的 shared runner / e2e case

1. `a849f182e5615f4a1279b33de9efa4670465cabd`（2026-04-07）

- commit message 明确写的是 “remove 11 unused app runners”
- 被删文件：
  - `runner/libs/app_runners/calico.py`
  - `runner/libs/app_runners/coroot_node_agent.py`
  - `runner/libs/app_runners/datadog_agent.py`
  - `runner/libs/app_runners/kubearmor.py`
  - `runner/libs/app_runners/libbpf_bootstrap.py`
  - `runner/libs/app_runners/loxilb.py`
  - `runner/libs/app_runners/suricata.py`
  - `runner/libs/app_runners/systemd.py`
  - `runner/libs/app_runners/tubular.py`
  - `runner/libs/app_runners/xdp_tools.py`
  - `runner/libs/app_runners/xdp_tutorial.py`

2. `764043c500fe508fc86fa1111dda79600ff05bc9`（2026-04-25）

- commit message 明确写的是 “Remove scx from the benchmark framework”
- 删除了：
  - `e2e/cases/scx/__init__.py`
  - `e2e/cases/scx/case.py`
  - `runner/libs/app_runners/scx.py`
- 同时还删掉了 corpus macro app、suite 注册和 runtime artifact plumbing。

3. `579c0811e75755e1b60abaf7d8b3419df88bacd0`（2026-03-29）

- 删除了旧对象级 corpus 路线的关键文件：
  - `corpus/config/macro_corpus.yaml`
  - `corpus/config/macro_corpus_linux_selftests.yaml`
  - 旧版 `corpus/driver.py`
  - `runner/libs/app_runners/real_world_code_size.py`

### 1.3 旧 runner 的形态：很多 app 其实只是薄封装

从删除前版本看，很多 app runner 只是 `NativeProcessRunner` 的薄封装：

- `CalicoRunner` 只是在 `corpus/build/calico/bin/calico-node`、`runner/repos/calico/bin/calico-node`、`/usr/bin/calico-node` 之间选 binary。
- `SuricataRunner` 只是在 `corpus/build/suricata/bin/suricata`、`runner/repos/suricata/bin/suricata`、`/usr/bin/suricata` 之间选 binary。
- `SystemdRunner` 也是按 app 名映射到不同 `systemd` binary。

这意味着：

- 恢复历史 app 不一定要重写复杂 runner。
- 对于“用户态守护进程启动后自动挂 BPF 程序”的 app，重新引入 shared runner 的成本并不高。

### 1.4 `e2e/cases/` 的历史结论

- 真正在 `e2e/cases/` 里有过独立 case 的，当前这条线主要是：`bcc`、`bpftrace`、`katran`、`tetragon`、`tracee`，以及已经删除的 `scx`。
- `a574a0892dc9edfca34db39ebe9e33fe73a15684`（2026-04-24）删掉了老的 case config：
  - `e2e/cases/bcc/config.yaml`
  - `e2e/cases/tetragon/config.yaml`
  - `e2e/cases/tracee/config.yaml`
- 2026-04-07 被删的那 11 个 app 更多是 shared runner / corpus 路线里的 app，不是 `e2e/cases/*` 下长期存在的独立 case。

## 2. `corpus/results/` 调研

### 2.1 当前 checked-in 结果里有两条 lineage

1. `macro_apps` 新路线

- 代表文件：`corpus/results/vm_corpus.json`、`corpus/results/vm_corpus_rerun.json`
- 这里能看到 20 个 workload 名字：
  - `bcc/*` 10 个
  - `bpftrace/*` 6 个
  - `katran`
  - `tetragon/default`
  - `tracee/default`
  - 历史上的 `scx/rusty`

2. `macro_corpus` / source-level 旧路线

- 代表文件：
  - `corpus/results/expanded_corpus_build_authoritative_20260310.json`
  - `corpus/results/expanded_corpus_build.md`
  - `corpus/results/vm_corpus_20260326_*/metadata.json`
- 这里出现过的 source 比 shared runner 名单更广，包括：
  - `calico`
  - `cilium`
  - `suricata`
  - `netbird`
  - `opentelemetry-ebpf-profiler`
  - 以及 build-only 视角里的 `linux-selftests`、`xdp-tools`、`xdp-tutorial` 等

### 2.2 重点 app 结果核对

| app/source | 当前 working tree 下 `corpus/results/` 证据 | 历史更强证据 | 结论 |
| --- | --- | --- | --- |
| `calico` | `vm_corpus_20260326_035158/metadata.json` 等文件里有 `source_name=calico`，`programs=2`、`compile_pairs=2`、`measured_pairs=0` | `git show 4bc303ce:corpus/results/corpus_post_fix_20260313.json` 里 `calico` 为 `programs=59`、`measured_pairs=59`、`exec_ratio_geomean=1.070079...`；`git show 245c18ac:corpus/results/corpus_authoritative_20260320.json` 里 `exec_ratio_geomean=1.017423...` | Calico 明确跑过，而且曾经是大型 production corpus 主力；但 `1.097x` 这个数我没有在当前 checked-in `corpus/results/*.json` 里找到，只在 `docs/tmp/20260319/corpus_post_simplification_20260319.md`、`docs/tmp/active/corpus-post-fix-build39.md` 这种分析文档里看到。也就是说，`1.097x` 现在更像“文档侧 authority”，不是 working-tree 里还留着的结果 JSON。 |
| `suricata` | `vm_corpus_20260326_035158/metadata.json` 等文件里有 `source_name=suricata`，`programs=1`、`compile_pairs=1`、`measured_pairs=0` | `git show 4bc303ce:corpus/results/corpus_post_fix_20260313.json` 里 `suricata` 为 `programs=2`、`compile_pairs=1`、`measured_pairs=1`、`exec_ratio_geomean=1.538461...`；同文件 `top_speedups` 里有 `corpus/build/suricata/xdp_filter.bpf.o:xdp_hashfilter`，`speedup_ratio=1.538461...` | Suricata 的 `1.538x` 可以直接落到历史结果 JSON，不只是文档里提过。 |
| `cilium` | `expanded_corpus_build.md` 里 `cilium | 0 | 0 | 9 | 0`，说明当时有 9 个 build failure；`vm_corpus_20260326_035158/metadata.json` 等文件里 `source_name=cilium` 为 `programs=3`、`compile_pairs=0` | 本地 `corpus/build/cilium/` 现在已经有 `bpf_xdp.bpf.o`、`bpf_lxc.bpf.o`、`bpf_overlay.bpf.o`、`bpf_sock.bpf.o` 等对象；`runner/repos/cilium/bpf/bpf_sock.c` 本地源码里可以看到大量 `cgroup/*` section | Cilium 明显被尝试过，价值很高，但当时卡在 object-open / loader 路径，没有进入稳定 runtime corpus。 |

### 2.3 其他在 `corpus/results/` 中出现过的 source

下面这些 source 也在当前结果目录中留下了痕迹，但大多停在 build 或 compile-only 阶段：

| source | 证据 | 备注 |
| --- | --- | --- |
| `netbird` | `vm_corpus_20260326_*/metadata.json` 里 `programs=1`、`compile_pairs=0`；`expanded_corpus_build.md` 也出现过 | 只有 1 个 XDP 程序，coverage 增量太小。 |
| `opentelemetry-ebpf-profiler` | `vm_corpus_20260326_*/metadata.json` 里 `programs=3`、`compile_pairs=0`；本地 `corpus/build/opentelemetry-ebpf-profiler/` 有 3 个对象 | 编译 corpus 价值不低，但 runtime corpus 目前不成熟。 |

## 3. 当前 5 个 app 的 BPF program type 覆盖

### 3.1 统计口径

- 最新一次 `2026-04-25` 的 `details/result.json` 已经把每个 app 的 `programs` 明细裁掉了，不能直接拿来做 coverage。
- 因此这里回退到最近一批仍保留 `programs` 明细、且 20 个 workload 都有非空 program 列表的结果：
  - `corpus/results/x86_kvm_corpus_20260423_124338_026179/details/result.json`
- 统计规则：
  - 每个 workload 取最近一次 `programs` 非空的结果。
  - “当前 5 个 app”按 shared runner 家族聚合，不再把已删除的 `scx` 计入当前覆盖。

### 3.2 覆盖结果

| 家族 | workload 数 | 已加载 program 数 | 覆盖 type |
| --- | --- | ---: | --- |
| `bcc` | 10 | 26 | `kprobe`, `raw_tracepoint`, `tracepoint`, `tracing` |
| `bpftrace` | 6 | 10 | `kprobe`, `perf_event`, `tracepoint` |
| `katran` | 1 | 3 | `sched_cls`, `xdp` |
| `tetragon` | 1 | 35 | `kprobe`, `raw_tracepoint`, `socket_filter`, `tracepoint` |
| `tracee` | 1 | 37 | `kprobe`, `raw_tracepoint` |
| 合计 | 19 | 111 | `kprobe`, `perf_event`, `raw_tracepoint`, `sched_cls`, `socket_filter`, `tracepoint`, `tracing`, `xdp` |

补充说明：

- 同一批 `2026-04-23` 结果里如果把历史上的 `scx/rusty` 也算上，还会再多出 `13` 个 `struct_ops` program。
- 但 `scx` 已在 `2026-04-25` 被正式移除，因此这里不把它计入“当前 5 个 app”的覆盖。

### 3.3 当前已覆盖 / 未覆盖

已覆盖：

- `kprobe`
- `tracepoint`
- `raw_tracepoint`
- `tracing`
- `perf_event`
- `socket_filter`
- `sched_cls`
- `xdp`

当前明显未覆盖或已丢失的 type：

- `cgroup_*` 家族
  - 例如 `cgroup/sock_create`
  - `cgroup/bind4` / `bind6`
  - `cgroup/connect4` / `connect6`
  - `cgroup/post_bind4` / `post_bind6`
  - `cgroup/sendmsg4` / `sendmsg6`
  - `cgroup/recvmsg4` / `recvmsg6`
  - `cgroup/getpeername4` / `getpeername6`
  - `cgroup/sock_release`
  - `cgroup/sysctl`
- `lsm`
- `sockops`
- `sk_msg`
- `sk_skb`
- `flow_dissector`
- `fentry` / `fexit`
- `struct_ops`
  - 这个原本由 `scx` 提供，但 `scx` 已在 `2026-04-25` 被删掉。

需要特别纠正的一点：

- `socket_filter` 不是空白。
- 当前 `tetragon/default` 结果里已经能看到 `execve_map_update | socket_filter`。

## 4. 可加的新 app 建议

### 4.1 总体排序

| 优先级 | app | 性质 | 为什么值得做 |
| --- | --- | --- | --- |
| P0 | `systemd` | 恢复历史 app | 补最多的 type 空白，尤其是 `cgroup_*` 和 `lsm`。 |
| P0 | `cilium` | 新 app（但 source-level corpus 里已经出现过） | 真实使用最广、程序数量潜力最大、还能补 `cgroup_*`。 |
| P1 | `calico` | 恢复历史 app | 虽然不补新 type，但 TC/XDP 程序多、历史上已经证明能跑。 |
| P1 | `suricata` | 恢复历史 app | 稳定、真实、有历史跑通证据，而且 `1.538x` 是现成基线。 |
| P1 | `loxilb` | 恢复历史 app | 真实 eBPF LB，仍然是高价值网络 datapath。 |
| P1 | `merbridge` | 真正新的 app | 明确补 `sockops` 和 `sk_msg`，这是当前最缺、也最难从别的主流 app 拿到的 type。 |
| P2 | `KubeArmor` | 恢复历史 app | 安全域真实产品，能补 `lsm`，但和现有 `tracee/tetragon` 的重叠也比较大。 |

### 4.2 各候选的具体判断

#### `systemd`：我认为是最该优先恢复的 app

理由：

- 这是最能补 type 空白的历史 app。
- upstream `src/bpf/meson.build` 直接列出了 6 个内置 BPF 程序：
  - `bind-iface.bpf.c`
  - `restrict-fs.bpf.c`
  - `restrict-ifaces.bpf.c`
  - `socket-bind.bpf.c`
  - `sysctl-monitor.bpf.c`
  - `userns-restrict.bpf.c`
- upstream 源文件可以直接看到：
  - `bind-iface.bpf.c` 用的是 `SEC("cgroup/sock_create")`
  - `socket-bind.bpf.c` 用的是 `SEC("cgroup/bind4")` 和 `SEC("cgroup/bind6")`
  - `sysctl-monitor.bpf.c` 用的是 `SEC("cgroup/sysctl")`
  - `userns-restrict.bpf.c` 用的是多组 `SEC("lsm/path_*")`，还有 `SEC("kprobe/retire_userns_sysctls")`
- 这正好补掉当前 5 个 app 完全没有覆盖到的 `cgroup_*` 与 `lsm`。
- 历史上已经有 `runner/libs/app_runners/systemd.py`，说明接入过一次。

判断：

- 真实度：非常高
- KVM VM 可行性：高
- 程序数量：中等，但 type 增量最大
- 接入成本：低到中等

#### `cilium`：如果要追求“程序数量最多 + cgroup 类型补全”，它是最高价值的新 app

理由：

- 官方文档明确写出 Cilium datapath 使用：
  - `XDP`
  - `tc ingress/egress`
  - `socket operations`
  - `socket send/recv`
- 本地 `runner/repos/cilium/bpf/bpf_sock.c` 又能直接看到大量 cgroup section：
  - `cgroup/connect4` / `connect6`
  - `cgroup/post_bind4` / `post_bind6`
  - `cgroup/bind4` / `bind6`
  - `cgroup/sendmsg4` / `sendmsg6`
  - `cgroup/recvmsg4` / `recvmsg6`
  - `cgroup/getpeername4` / `getpeername6`
  - `cgroup/sock_release`
- 这意味着它不只是“再来一份 XDP/TC”，而是能真正把 `cgroup_sock_addr` / `cgroup_sock` 家族补进来。
- 本地 `corpus/build/cilium/` 已经有 7 个对象，说明构建工作不是从零开始。

问题：

- 当前 repo 的历史结果表明 Cilium 卡在 object-open / loader 路径。
- `vm_corpus_20260326_*` 里 `cilium` 一直是 `programs=3` 但 `compile_pairs=0`。
- `expanded_corpus_build.md` 里也能看到早期大面积 compile failure。

判断：

- 真实度：非常高
- KVM VM 可行性：高
- 程序数量：非常高
- type 增量：非常高
- 接入成本：高

#### `calico`：不是“新 type”优先项，但一定是“高产出恢复项”

理由：

- 历史 runner 已经存在过，恢复成本低。
- 历史 corpus 里它是最大的 production networking source 之一。
- `corpus_post_fix_20260313.json` 里 `calico` 是 `59` 个 program、`59` 个 measured pair。
- 程序类型主要是 `sched_cls` + `xdp`，单纯从 type 角度没有新增，但从“applied 数量”和“真实生产 datapath 规模”角度仍然很强。

判断：

- 真实度：非常高
- KVM VM 可行性：高
- 程序数量：高
- type 增量：低
- 接入成本：低

#### `suricata`：程序数不多，但它是最稳定、最好恢复的历史 XDP app 之一

理由：

- 历史 runner 已经有。
- 历史结果 JSON 里可以直接拿到 `1.538x`。
- `xdp_hashfilter` 的基线和历史 story 已经很完整。

判断：

- 真实度：高
- KVM VM 可行性：高
- 程序数量：低
- type 增量：低
- 接入成本：低

#### `loxilb`：如果想扩充 networking datapath，而不想立刻碰 Cilium 的 loader 难题，它是个好中间项

理由：

- 历史 runner 存在过。
- 官方文档明确说：
  - TC eBPF 承担主要 L4+ 处理
  - XDP 负责某些特殊 fast-path / mirror 工作
- 它本质上是另一个真实的 eBPF LB datapath，和 Katran 同域，但 shape 不一样。

判断：

- 真实度：高
- KVM VM 可行性：高
- 程序数量：中等到较高
- type 增量：主要还是 `sched_cls` + `xdp`
- 接入成本：中等

#### `merbridge`：如果目标明确要补 `sockops` / `sk_msg`，它是当前最有针对性的候选

理由：

- README 直接写它是 “Use eBPF to speed up your Service Mesh”，支持 Istio / Linkerd / Kuma / OSM，要求 Linux kernel `>= 5.7`。
- GitHub 仓库当前公开可见，且不是 toy repo。
- 代码里可以直接看到：
  - `bpf/mb_sockops.c` 使用 `__section("sockops")`
  - `bpf/mb_redir.c` 使用 `__section("sk_msg")`
- 这两个 type 在当前框架里完全空白。

不足：

- 它的生态主流程度明显不如 Cilium / systemd / Calico。
- 为了在 benchmark 里稳定跑起来，可能要补一个最小 service-mesh harness。

判断：

- 真实度：中等到较高
- KVM VM 可行性：中等到较高
- 程序数量：中等
- type 增量：非常高
- 接入成本：中等到较高

#### `KubeArmor`：安全域候选，主要价值在 `lsm`

理由：

- 历史 runner 已经存在过。
- 官方文档明确说 KubeArmor 的 system monitor 使用：
  - `Tracepoints`
  - `Kprobes`
  - `BPF-LSM`
- 如果已经通过 `systemd` 把 `lsm` 补进来了，KubeArmor 的新增 type 价值会下降，但它仍然是安全域真实产品。

判断：

- 真实度：高
- KVM VM 可行性：高
- 程序数量：中等
- type 增量：`lsm` 为主
- 接入成本：中等到较高

### 4.3 明确不建议优先投入的项

- `netbird`
  - 当前 corpus 痕迹里只有 1 个 XDP 程序，type 增量太小。
- `opentelemetry-ebpf-profiler`
  - 编译 corpus 很有意思，但 runtime/app-native corpus 现在不成熟，暂时更像“对象级 corpus”而不是“app benchmark”。
- `xdp-tools` / `xdp-tutorial`
  - 这些更像示例/工具集，不满足“真实、广泛使用的 BPF 应用”这一条。

### 4.4 `flow_dissector` 的现实结论

- 这次调研里我没有找到一个足够强、足够主流、又明显使用 `flow_dissector` 的生产级 app。
- 如果“覆盖更多 BPF type”比“只纳入真实产品 app”更重要，那么 `flow_dissector` 很可能只能回退到 `linux-selftests` 或内核 samples 这类非产品 corpus。
- 如果坚持“必须是广泛使用的真实 app”，那我建议先把 `systemd`、`cilium`、`merbridge` 这三类明显能补空白的候选做掉，再看 `flow_dissector` 是否值得为覆盖率单独破例。

## 5. 建议的落地顺序

1. 先恢复历史上最容易回来的 app：`systemd`、`calico`、`suricata`、`loxilb`

- 好处是 runner 形态已经验证过，回报最快。

2. 再单独攻 `cilium`

- 它是最值得投入工程时间解决 loader/object-open 问题的 app。

3. 如果 coverage 目标明确包含 `sockops` / `sk_msg`，再引入 `merbridge`

- 这一步的意义不是“再加一个网络 app”，而是把当前最缺的 socket-path type 补上。

4. `KubeArmor` 放在 `systemd` 之后做

- 因为它对安全域更真实，但如果只是为了尽快补 `lsm`，`systemd` 的性价比更高。

## 6. 上游参考

- Cilium docs: https://docs.cilium.io/en/stable/network/ebpf/intro/
- Cilium program types: https://docs.cilium.io/en/stable/reference-guides/bpf/progtypes/
- systemd resource control / cgroup-bpf: https://www.freedesktop.org/software/systemd/man/252/systemd.resource-control.html
- systemd `socket-bind.bpf.c`: https://github.com/systemd/systemd/blob/main/src/bpf/socket-bind.bpf.c
- systemd `bind-iface.bpf.c`: https://github.com/systemd/systemd/blob/main/src/bpf/bind-iface.bpf.c
- systemd `sysctl-monitor.bpf.c`: https://github.com/systemd/systemd/blob/main/src/bpf/sysctl-monitor.bpf.c
- systemd `userns-restrict.bpf.c`: https://github.com/systemd/systemd/blob/main/src/bpf/userns-restrict.bpf.c
- LoxiLB eBPF internals: https://docs.loxilb.io/main/loxilbebpf/
- KubeArmor eBPF overview: https://docs.kubearmor.io/kubearmor/quick-links/kubearmor_overview/bpf
- Merbridge README: https://github.com/merbridge/merbridge
