# Katran E2E Benchmark 设计方案

日期：`2026-03-18`  
仓库：`/home/yunwei37/workspace/bpf-benchmark`

## 0. 结论先行

- **Katran 可以作为替换当前 `xdp_forwarding` 的 authoritative E2E case。**
- **authoritative 路径必须用 Katran 官方的 C++ server loader，而不是 `bpftool prog load/loadall`。**
- **authoritative 拓扑必须按 Katran README/EXAMPLE 的假设来做：DSR、L3 routed、single-interface load balancer on a stick；但 packet generator 必须放在 guest 外部，real 侧 IPIP decap 只保留在 guest 内。**
- **attach 模式建议用 Katran 官方文档更推荐的 shared mode**：先挂 `xdp_root`，再让 `katran_server_grpc` 通过 pinned `prog_array` 注册 `balancer_ingress`。
- **流量建议用“官方 gRPC client 做控制面 + host/独立 VM 做数据面生成”**。控制面仍然走 Katran 自己的 Go gRPC client；数据面主 workload 用 `wrk`，补充 workload 用 `nping`。
- **编译建议在 host 做，guest 只负责运行 Katran / real / scanner / recompile；应用层测量放在 host。** 这样既避免 guest 内 generator 争 CPU，也不影响 live datapath benchmark 的构造有效性。
- **当前 framework kernel 仍有一个硬 blocker：`CONFIG_NET_IPIP` 没开。** packet generator 挪到 host 之后，host-side IPIP 不再需要；但 guest 内 real 仍然必须创建 `ipip0` 做 decap，因此在真正实现 Katran authoritative case 前，仍必须先补 kernel config。

## 1. 设计依据和官方要求

### 1.1 已阅读的 Katran 官方材料

本地 corpus：

- `corpus/repos/katran/README.md`
- `corpus/repos/katran/USAGE.md`
- `corpus/repos/katran/DEVELOPING.md`
- `corpus/repos/katran/EXAMPLE.md`
- `corpus/repos/katran/build_katran.sh`
- `corpus/repos/katran/build_bpf_modules_opensource.sh`
- `corpus/repos/katran/install_xdproot.sh`
- `corpus/repos/katran/start_katran_grpc_server.sh`
- `corpus/repos/katran/start_katran_simple_server.sh`
- `corpus/repos/katran/os_run_tester.sh`
- `corpus/repos/katran/katran/lib/testing/...`

补读的上游官方源码和文档：

- `https://github.com/facebookincubator/katran`
- `https://raw.githubusercontent.com/facebookincubator/katran/main/example_grpc/katran_server.cpp`
- `https://raw.githubusercontent.com/facebookincubator/katran/main/example_grpc/KatranGrpcService.cpp`
- `https://raw.githubusercontent.com/facebookincubator/katran/main/example_grpc/CMakeLists.txt`
- `https://raw.githubusercontent.com/facebookincubator/katran/main/example_grpc/build_grpc_client.sh`
- `https://raw.githubusercontent.com/facebookincubator/katran/main/example_grpc/goclient/src/katranc/main/main.go`
- `https://raw.githubusercontent.com/facebookincubator/katran/main/example_grpc/goclient/src/katranc/katranc/katranc.go`

### 1.2 Katran 官方要求的部署模型

Katran 官方文档对真实部署有几条非常明确的约束：

- **只支持 DSR**。
- **网络拓扑必须是 L3 routed**，Katran 默认把发往 real 的包都交给默认网关。
- **默认假设是 single-interface load balancer on a stick**，也就是同一个接口既收 client->VIP 流量，也发 LB->real 的封装包。
- **不支持分片、不支持 IP options**。
- **推荐打开 BPF JIT**。
- **推荐 shared mode**，也就是先挂一个 root XDP program，再让 Katran 自己注册到 `prog_array`。

这意味着 authoritative benchmark 不能再沿用“简单两个 namespace + 一个 XDP object + devmap”那种最小 forwarding toy model，而是要把下面几个动作都做出来：

- router/default gateway 存在；
- Katran 知道 default gateway MAC；
- 外部 client 为 VIP 配静态路由，流量才能被送到 Katran；
- guest 内 real 仍要有 `ipip0` decap 和 `VIP/32 on lo`；
- 回包必须绕过 Katran，直接从 real 返回外部 client。

### 1.3 Katran server 的正确启动方式

Katran 不是只靠 `.bpf.o` 自己工作。官方 usage 明确要求控制面流程是：

1. 构造 `KatranConfig`
2. `loadBpfProgs()`
3. `attachBpfProgs()`
4. 配 VIP
5. 配 real

官方 example 给了两个 server 包装器：

- thrift 版 `simple_katran_server`
- gRPC 版 `katran_server_grpc`

`example_grpc/katran_server.cpp` 里可以确认 gRPC server 暴露了这些关键 flags：

- `-server`
- `-intf`
- `-balancer_prog`
- `-default_mac`
- `-map_path`
- `-prog_pos`
- `-hc_forwarding`
- `-lru_size`
- `-forwarding_cores`
- `-ipip_intf`
- `-ipip6_intf`

`KatranGrpcService.cpp` 里可以确认 server 构造时就会：

- `lb_.loadBpfProgs()`
- `lb_.attachBpfProgs()`

因此 authoritative E2E 应当把 **server 本身** 视作 agent 进程，而不是单独用 `bpftool` 替它做 load/attach。

### 1.4 VIP / real 的官方配置方式

Katran 官方文档和官方 Go gRPC client 都说明了正确姿势：

- 先通过 gRPC client `-A` 添加 VIP
- 再通过 gRPC client `-a` 给 VIP 加 real
- 再通过 gRPC client `-l` 列出当前 VIP / real
- 测量时可以用 gRPC client `-s`、`-sum`、`-lru` 拉 per-VIP 和 LRU stats

这比自己写 map initializer 更符合 Katran 的真实使用方式。

### 1.5 依赖要求

Katran 官方 build 脚本已经把依赖关系说得很清楚：

基础依赖：

- `folly`
- `fmt`
- `glog`
- `gflags`
- `libelf`
- `libmnl`
- `libzstd`
- `clang`
- `libbpf`

如果要构建 example server：

- gRPC 路线需要 `gRPC` 和 `protobuf`
- thrift 路线还需要 `fbthrift`

如果要构建官方 Go gRPC client：

- `go`
- `protoc`
- `protoc-gen-go`
- `protoc-gen-go-grpc`

### 1.6 Katran 自己提供了哪些测试方式

Katran 自带两类测试，但都不应当替代 authoritative E2E：

- `katran_tester --test_from_fixtures=true`
  - 基于 `bpf_prog_test_run`
  - 用固定 packet fixtures 做 correctness test
- `katran_tester --perf_testing`
  - 同样基于 fixture
  - 输出每 packet 平均 `ns` 和估算 `Mpps`

它们很适合作为：

- bring-up smoke
- object-level correctness check
- policy 变更前后的离线 sanity check

但它们**不等价于 live attach + live traffic + live scanner enumerate 的 E2E**。

### 1.7 Katran 是否有官方 Docker / 容器化部署

在 Katran 仓库里，没有像 Tracee/Tetragon 那样的官方 Docker 安装路径或容器编排文件。官方 README/EXAMPLE 走的是：

- Linux host / VM
- C++ server
- Go client
- 真实网络接口

因此 Katran authoritative case 应当优先按 **host-guest bridge + guest 内真实网络接口** 的方式做，而不是强行容器化。

## 2. Katran authoritative E2E 方案

### 2.1 方案目标

这个 case 的目标不是证明 Katran 能跑，而是替换当前只有 `3` 个 live optimization sites 的 `xdp_forwarding`，用一个：

- 真实 XDP production datapath
- live loaded
- live attached
- live configured
- live trafficked

的 E2E baseline 来测 BpfReJIT。

目标程序只锁定：

- `balancer_ingress`

不把下列程序作为 headline benchmark：

- `xdp_root`
- `healthcheck_*`
- `xdp_pktcntr`

### 2.2 编译方案

#### 结论

**建议在 host 编译 Katran，guest 只负责运行 Katran / real / scanner，并做 guest-side BPF runtime 测量。**

#### 原因

- Katran userspace 依赖比 Tracee/Tetragon 重很多，尤其是 `folly + gRPC/protobuf`。
- authoritative benchmark 的研究对象是 guest kernel 里的 live BPF datapath，不是 guest 内部 userspace 编译时间。
- 本项目当前 `e2e/common/vm.py` 已经支持把 workspace 挂进 guest，因此 host 产物可以直接在 guest 内运行。
- 这样可以把“依赖安装/构建不稳定”和“性能测量”解耦。

#### authoritative build 产物

建议由 host-side setup 生成并缓存下列产物：

- `katran/lib/xdproot`
- `example_grpc/katran_server_grpc`
- `deps/bpfprog/bpf/balancer.bpf.o`
- `deps/bpfprog/bpf/xdp_root.o`
- `example_grpc/goclient/src/katranc/main/main`

#### authoritative build 路线

不建议直接在 `corpus/repos/katran/` 上 build，原因是本地 corpus 是 sparse checkout，缺了 `example/` 和 `example_grpc/`。

正确做法应当是：

1. 在仓库里 vendor 或临时 clone 一份 **完整 upstream Katran source tree**
2. pin 到一个明确 commit
3. 在 host 上运行官方 `build_katran.sh`
4. 再运行官方 `example_grpc/build_grpc_client.sh`

建议的实现落点：

- `third_party/katran-src/` 或 `tmp/katran-src/`
- `e2e/cases/katran/setup.sh` 只负责“拉源码/校验产物/必要时构建”

#### 编译时的具体策略

- authoritative 路线只构建 **gRPC example**
- **thrift example 不必构建**
- `BUILD_EXAMPLE_GRPC=1`
- `BUILD_EXAMPLE_THRIFT=0`

这样可以避免引入 `fbthrift` 这一层额外复杂度，同时仍然完全符合官方 example 路线。

### 2.3 authoritative 网络拓扑

#### 设计原则

按 Katran README/EXAMPLE，topology 仍然需要同时满足：

- L3 routed
- DSR
- LB 单臂
- router/default gateway 在前
- real 侧 IPIP decap

但这次 authoritative benchmark 还要额外满足一个实验约束：

- packet generator 不能和 Katran/real 共用同一个 guest CPU 池

#### 推荐拓扑

推荐把外部 client 和 router/default gateway 都放在 host，guest 只跑 datapath 和测量组件：

```text
Host / external side
  wrk / nping
  Linux bridge/router: br0 或 virbr0
  bridge IP: 192.168.122.1/24
  VIP route: 10.200.200.1/32 via 192.168.122.10
            |
            | vng --network bridge=<br>
            |
VM1 / framework kernel guest
  katran0: 192.168.122.10/24   (Katran 主接口)
  real IP: 192.168.122.20/24   (同一接口上的 secondary address)
  ipip0: decap only
  lo: 10.200.200.1/32
  processes:
    - xdproot
    - katran_server_grpc
    - nginx real
    - scanner / recompile / bpftool
```

这个设计的好处是：

- packet generator 和被测 datapath 不再争同一个 guest vCPU；
- 仍然保留 Katran 官方要求的 single-interface、L3 routed、DSR 假设；
- 不依赖 `veth` 或 guest 内多 namespace lab；
- host 既是外部流量源，也是 Katran 的 default gateway / VIP router，拓扑更接近真实“外部 client + LB appliance”。

#### 推荐地址规划

建议先固定一组最小可运行地址（静态配置，或由 DHCP reservation 固定）：

- host bridge：`192.168.122.1/24`
- guest LB IP：`192.168.122.10/24`
- guest real IP：`192.168.122.20/24`
- VIP：`10.200.200.1/32`

host 侧关键路由：

```bash
sysctl -w net.ipv4.ip_forward=1
ip route replace 10.200.200.1/32 via 192.168.122.10 dev <bridge>
```

guest 侧关键路由：

- `default via 192.168.122.1 dev katran0`

这样 host 发往 VIP 的所有包都会被 L2 送到 guest 的 `katran0`，而 Katran 发往 real 的封装包会以 host bridge/router 为下一跳再回灌到 guest 的 real IP。

#### DSR / 回包路径说明

新设计下不再需要 host-side `ipip0` 或 host-side real namespace，但 DSR 路径仍然成立：

1. host 上的 `wrk`/`nping` 把 VIP 流量发给 `192.168.122.10` 这个下一跳；
2. `balancer_ingress` 收到 client->VIP 包后，按 Katran 逻辑把内层包封装成 outer dst=`192.168.122.20` 的 IPIP 包，并通过 `XDP_TX` 从同一接口打回 bridge；
3. host bridge/router 收到该封装包后，把 outer dst=`192.168.122.20` 再路由回同一个 guest；
4. guest 内的 `ipip0` 把包 decap，`nginx` 在 `VIP/32 on lo` 上处理请求；
5. `nginx` 直接从 `10.200.200.1` 回包到 host client，绕过 Katran，形成 DSR。

因此在新设计里：

- host 必须显式持有 VIP 静态路由；
- host 不需要做 IPIP decap；
- guest 内 real 仍然必须做 IPIP decap。

### 2.4 当前 framework-kernel 下的 VM 搭建方式

#### 关键现实约束

当前 `vendor/linux-framework/.config` 里明确有：

- `# CONFIG_NET_IPIP is not set`
- `# CONFIG_VETH is not set`
- `# CONFIG_IPV6_TUNNEL is not set`

这三条的影响分别是：

- `NET_IPIP` 没开：**guest 内 real-side decap 仍然直接被阻塞**
- `VETH` 没开：guest 内不能像普通 Linux 那样随手建 `veth pair`
- `IPV6_TUNNEL` 没开：如果以后要测 IPv6 VIP 或 v6 healthcheck，还会再被阻塞一次

#### authoritative 建议

**authoritative v1 先只做 IPv4 Katran datapath，并把 `CONFIG_NET_IPIP=y` 作为前置依赖。**

这样可以把必须的 kernel 变更压到最小：

- 必须补：`CONFIG_NET_IPIP`
- 可选补：`CONFIG_VETH`
- 暂时可不补：`CONFIG_IPV6_TUNNEL`

#### `vng --network` 的正确用法

这次不应再使用 `--network loop`。本机 `vng`/`virtme` 实现已经确认：

- `--network bridge=<br>`：把 guest NIC 接到一个**已有的** host Linux bridge；
- `--network bridge`：如果不显式给 bridge 名字，默认接到 `virbr0`；
- bridge 模式默认开启 DHCP；
- 如果想自己在 guest 里配静态地址，可额外加 `--no-dhcp`。

也就是说，authoritative Katran case 应直接把 `networks=["bridge=<br>"]` 传给 `e2e/common/vm.py::run_in_vm()`，而不是再拼 guest 内 `loop` 拓扑。

#### 推荐 VM bring-up

推荐的 host-side 启动形态是：

```bash
vng --run <kernel> \
  --network bridge=virbr0 \
  --cpus 4 \
  --memory 4096M \
  --ssh 2222
```

说明：

- `bridge=virbr0` 只是最小示例；更稳妥的方案是显式准备独立的 `katran-br0`；
- 若使用自定义 bridge，必须先在 host 上创建它并给 bridge 配地址；
- 需要 host/guest 并发 orchestration，所以 guest 最好以 long-lived 模式启动，再由 harness 通过 `ssh`/agent 进入 guest；
- `e2e/common/vm.py` 已经会把 `networks` 原样转成 `--network` 参数，设计上无需改 `vng` 语义。

#### authoritative preflight

在真正起 Katran 之前，guest 内还应显式做两件官方文档要求的事：

```bash
sysctl -w net.core.bpf_jit_enable=1
ethtool --offload katran0 gro off || true
ethtool --offload katran0 lro off || true
```

说明：

- `bpf_jit_enable=1` 是官方 example 明确要求的
- 在 virtio / generic-XDP 路径里，至少要关 `GRO`
- 如果设备支持 `LRO`，也应当关掉
- 为了让 `bpftool prog show` 稳定暴露 `run_cnt` / `run_time_ns`，benchmark bring-up 还应复用 `e2e/common/metrics.py::enable_bpf_stats()` 在 guest 内打开 BPF runtime stats。

#### 如果后续允许改 kernel config

建议一并打开：

- `CONFIG_VETH=y`
- `CONFIG_NET_IPIP=y`
- `CONFIG_IPV6_TUNNEL=y`

这样实现会明显简单，后续也更容易扩展到：

- real 共用一个 backend L2 segment
- IPv6 VIP
- healthcheck forwarding

### 2.5 Katran authoritative 服务配置

#### LB 侧

authoritative 路径建议：

- shared mode
- `hc_forwarding=false`
- 单 VIP
- 单个 guest-local real

shared mode bring-up 顺序：

1. mount bpffs
2. 启动 `xdproot`
3. 启动 `katran_server_grpc`
4. 用官方 Go gRPC client 配 VIP / real

推荐启动参数：

```bash
katran_server_grpc \
  -server=127.0.0.1:50051 \
  -intf=katran0 \
  -balancer_prog=/path/to/deps/bpfprog/bpf/balancer.bpf.o \
  -default_mac=<host_bridge_mac> \
  -forwarding_cores=0 \
  -hc_forwarding=false \
  -map_path=/sys/fs/bpf/jmp_katran0 \
  -prog_pos=2 \
  -lru_size=100000
```

说明：

- `katran0` 是 authoritative case 里给 LB 数据接口起的稳定名字
- `default_mac` 取 host bridge/router 的 MAC，而不是 real 的 MAC
- 单 queue guest 可以直接 `-forwarding_cores=0`
- 关闭 healthcheck 可以避免额外的 TC/qdisc/tunnel 配置
- 在 `-hc_forwarding=false` 下，`-ipip_intf` / `-ipip6_intf` / `-healthchecker_prog` 都不必作为 v1 authoritative 启动参数。

shared mode 根程序：

```bash
xdproot \
  -bpfprog /path/to/deps/bpfprog/bpf/xdp_root.o \
  -bpfpath /sys/fs/bpf/jmp_katran0 \
  -intf=katran0
```

#### VIP / real 配置

VIP 建议用：

- `10.200.200.1:80/TCP`

real 建议先只保留 1 个：

- real: `192.168.122.20`

用官方 gRPC client 配置：

```bash
katran_goclient -server 127.0.0.1:50051 -A -t 10.200.200.1:80
katran_goclient -server 127.0.0.1:50051 -a -t 10.200.200.1:80 -r 192.168.122.20 -w 1
katran_goclient -server 127.0.0.1:50051 -l
```

这里把 real 收敛成单个 guest-local backend 的原因是：

- 新设计的主要目标是修正 generator 位置并恢复可信 RPS/latency 测量；
- 在同一个 guest 里用多个 secondary IP 冒充多个 real，不会显著提高真实性；
- 如果后续确实要测多 real，更合理的扩展是上独立 VM2/VM3，而不是在一个 guest 里堆别名地址。

#### real 侧

guest 内 real 仍要按官方 DSR/IPIP 要求做，但无需再建 host-side real namespace：

```bash
ip addr add 192.168.122.20/24 dev katran0
ip link add name ipip0 type ipip external
ip link set dev ipip0 up
ip addr add 127.0.0.42/32 dev ipip0
ip addr add 10.200.200.1/32 dev lo
sysctl -w net.ipv4.conf.all.rp_filter=0
sysctl -w net.ipv4.conf.default.rp_filter=0
sysctl -w net.ipv4.conf.katran0.rp_filter=0
```

然后在 VIP 上起后端服务。

#### 后端服务建议

authoritative 路径建议用：

- `nginx` 或 `nginx-light`

原因：

- 比 Python HTTP server 更不容易成为瓶颈
- 静态响应简单
- `wrk`/`curl`/`ab` 都能直接打

如果只是 smoke，可退化到：

- `python3 -m http.server 80 --bind 10.200.200.1`

但不建议把 Python server 作为 publication-quality authoritative 配置。

### 2.6 流量生成方案

#### authoritative 主 workload

推荐主 workload 放在 host 上跑：

- `wrk -t2 -c64 -d30s --latency http://10.200.200.1/`

这会提供：

- `requests/sec`
- 平均延迟
- `p50/p75/p90/p99`
- 传输速率

host 侧 preflight 至少要先做：

```bash
ip route replace 10.200.200.1/32 via 192.168.122.10 dev <bridge>
```

#### 第二 workload：L4 packet / connection churn

Katran 的 datapath 里有：

- session lookup
- LRU hit / miss
- new-flow consistent hash

所以 authoritative case 最好再补一个外部 L4 generator。建议直接用 `nping`：

```bash
nping --tcp -c 100000 --rate 5000 10.200.200.1 -p 80
```

它可以提供：

- 发包/收包数
- 丢包
- L4 reachability / SYN path sanity

#### 控制面统计

同时后台起一个官方 `katran_goclient`：

- `-s -lru`

或者：

- `-s -sum`

作为 Katran 自己的 datapath counters 观测口。

这样 authoritative 报告里就同时有：

- 外部应用吞吐/延迟
- Katran 自己看到的 pkts/sec
- LRU hit/miss

#### CPU 隔离建议

即使 generator 已经搬到 host，只要 host 和 guest 仍跑在同一台物理机上，就仍然存在 socket / core 共享噪音。authoritative run 最好再做一层隔离：

- `vng --pin ...` 把 guest vCPU 固定到一组物理核；
- host 上的 `wrk` / `nping` 用 `taskset` 固定到另一组不重叠的物理核。

### 2.7 测量指标

建议 authoritative 报告至少固定输出下面几类指标。

host 应用层：

- `requests/sec`
- 平均 latency
- `p50/p95/p99`
- 失败请求数

host L4 packet 侧：

- `nping` send/recv/drop
- SYN/ACK reachability sanity

Katran 控制面（guest 内）：

- VIP packet rate
- VIP byte rate
- LRU hit ratio
- LRU miss ratio
- fallback LRU hit

guest BPF runtime：

- `run_cnt`
- `run_time_ns`
- `avg_ns_per_run`
- `bytes_jited`
- `bytes_xlated`

系统资源：

- Katran server 进程 CPU
- guest 总 busy CPU

BpfReJIT 相关：

- live scanner site 总数
- family 分布
- policy remap 命中数
- `BPF_PROG_JIT_RECOMPILE` 是否 applied

### 2.8 BpfReJIT 集成方案

这里可以直接复用现有 `tracee` / `tetragon` 的公共链路。

#### agent 管理

复用：

- `e2e/common/agent.py`

实现一个 `KatranAgentSession`：

- 配置 guest 内 `katran0` / `ipip0` / VIP / nginx
- 起 `xdproot`
- 起 `katran_server_grpc`
- 等 gRPC 端口 ready
- 等 `find_bpf_programs(server_pid)` 返回 `balancer_ingress`

除此之外还需要新增一个 **host-side workload runner**，专门在 host 上跑 `wrk` / `nping`。这是新设计相对旧文档最大的 orchestration 变化。

#### live program discovery

Katran authoritative case 不需要自己猜 prog id。直接用：

- `find_bpf_programs(server_pid)`

再按 program name 选：

- `balancer_ingress`

shared mode 下，`xdp_root` 由另一个 helper 进程加载，通常不会混进 server PID 的 owned programs，这一点正好符合我们只测 `balancer_ingress` 的目标。

#### scanner enumerate

复用：

- `e2e/common/recompile.py::scan_programs`

对 live `prog_id` 做：

```text
scanner enumerate --prog-id <id> --all --json
```

#### policy recompile

复用：

- `e2e/common/recompile.py::apply_recompile`

但 Katran authoritative case 不应依赖 object path 自动 resolve，因为 runtime build object path 和 corpus object path 未必一致。建议直接显式指定：

- `corpus/policies/katran/balancer/balancer_ingress.policy.yaml`

并强制做 live remap。

#### 测量顺序

推荐 authoritative phase 顺序：

1. host 准备 bridge 和 VIP 静态路由
2. 启 guest，并稳定 rename bridge NIC 为 `katran0`
3. 配 guest 内 `real IP + ipip0 + VIP/32 on lo + nginx`
4. 起 `xdproot`
5. 起 `katran_server_grpc`
6. 用官方 gRPC client 配 VIP/real
7. warmup host->VIP 路径
8. 在 guest 内启用 BPF stats，并记录 baseline 前的 `bpftool prog show` 快照
9. host 跑 baseline `wrk` / `nping`
10. `scan_programs`
11. `apply_recompile`
12. 记录 post-ReJIT workload 前的 `bpftool prog show` 快照
13. 如果 applied > 0，则 host 再跑 post-ReJIT workload
14. 输出 JSON/Markdown，报告 host 应用层结果与 guest BPF runtime delta

**不要在 baseline 和 post 之间重启 Katran server**。  
authoritative 目标是 live in-place recompile，而不是“重启后跑新程序”。

### 2.9 与现有 harness 的映射关系

可直接复用的公共基础设施：

- `e2e/common/vm.py`
- `e2e/common/agent.py`
- `e2e/common/metrics.py`
- `e2e/common/recompile.py`
- `e2e/common/workload.py`

特别可复用的思路：

- `tracee` / `tetragon` 的 agent + scanner + recompile phase 结构
- guest 内 BPF runtime 采样和 before/after delta 结构

建议新增文件：

- `e2e/cases/katran/case.py`
- `e2e/cases/katran/setup.sh`
- `e2e/cases/katran/config.yaml`
- `e2e/cases/katran/guest_smoke.sh`
- `e2e/cases/katran/host_workload.py`

可选拆分：

- `e2e/cases/katran/guest_net.py`
- `e2e/cases/katran/artifacts.py`

## 3. 工程量估算

### 3.1 authoritative 完整版本

以一个熟悉当前 `e2e/` harness 的工程师估算：

| 子任务 | 估算 |
| --- | ---: |
| vendor/拉取完整 Katran upstream，固定 commit，做 host-side build cache | `1.0-1.5` 天 |
| 跑通 `build_katran.sh` + gRPC client build，并稳定 guest 内 `LD_LIBRARY_PATH` | `1.0-1.5` 天 |
| 搭 host bridge + guest single-NIC real/IPIP/DSR 拓扑 | `1.0-1.5` 天 |
| 接 host-side `wrk` / `nping` workload runner 与 VIP 路由管理 | `1.0-1.5` 天 |
| 接 Katran server / goclient / stats collector | `1.0-1.5` 天 |
| 接 scanner enumerate / policy remap / guest-side `bpftool` before-after measurement | `1.0-1.5` 天 |
| 稳定化、CPU pinning、VM 重跑、结果格式化 | `1.0-1.5` 天 |
| **合计** | **`6-8.5` engineer-days** |

### 3.2 只做 smoke MVP

如果只做：

- standalone mode
- 单 real
- Python backend
- host 只跑 `curl` / `nping` smoke

那么 2-3 天可以出原型。  
但这**不满足**你这次要求的“按官方 README/EXAMPLE 来”的 authoritative 设计，所以不建议把 MVP 当最终方案。

## 4. 风险和依赖

### 4.1 当前 framework kernel 缺 `NET_IPIP`

这是最大 blocker。

如果不打开 `CONFIG_NET_IPIP`，guest 内 real 侧无法按官方方式创建：

```bash
ip link add name ipip0 type ipip external
```

新的 host-generator 设计虽然已经去掉了 host-side IPIP 依赖，但 Katran 的数据面封装没有变，guest 内 real 仍然要 decap，所以 authoritative Katran DSR/IPIP testbed 还是根本搭不起来。

### 4.2 当前 corpus 不是完整 Katran 源码

`corpus/repos/katran/` 里没有 `example_grpc/` 和 `example/` 的完整源码目录，不能直接 build 官方 server/client。

这意味着真正实现前必须先做一件仓库工程化工作：

- vendor 一份完整 upstream Katran source tree

### 4.3 gRPC client build 依赖额外工具链

除了 C++ side 的依赖，还要额外满足：

- `go`
- `protoc`
- `protoc-gen-go`
- `protoc-gen-go-grpc`

而且官方脚本还专门提到过 `protoc-gen-go_grpc` 命名兼容问题。这一块要在 `setup.sh` 里显式验证，不要把错误留到运行期。

### 4.4 host bridge / interface naming 需要显式校验

`vng --network bridge` 只负责把 guest NIC 接到 host bridge，并不保证：

- bridge 一定存在；
- guest 一定拿到 DHCP 地址；
- guest NIC 名字一定稳定。

因此 authoritative case 必须在 bring-up 里做：

- 校验 bridge 存在；如果只写 `bridge`，默认桥是 `virbr0`
- 记录 host bridge IP/MAC，作为 VIP route 和 `default_mac` 的来源
- guest 内 stable rename，把 bridge NIC 固定成 `katran0`
- 快照 guest 的最终 IP/MAC，避免 `-intf=<name>` 与实际接口漂移

### 4.5 backend service 可能成为瓶颈

如果直接用 Python HTTP server，当负载稍大时瓶颈很可能在 real，而不是 Katran。这样会把 ReJIT 效果淹没掉。

因此 authoritative 路径必须优先用：

- `nginx`

Python server 只能保留为 smoke fallback。

### 4.6 shared mode 会引入 root XDP 开销

shared mode 比 standalone 多一个 `xdp_root` dispatch 开销。  
这不是 correctness 风险，但会让 end-to-end 应用吞吐略低。

authoritative 路径仍然建议 shared mode，因为这是官方更推荐的部署方式；但要在报告里明确：

- 被 ReJIT 的目标程序是 `balancer_ingress`
- `xdp_root` 不参与 scanner/recompile
- root 开销在 baseline/post 两侧保持不变

### 4.7 Katran 现有 policy 明显 stale

仓库里现有 `balancer_ingress.policy.yaml` 和最新 live scan 已经漂移。  
如果不先修 policy，再好的 Katran E2E 也会退化成：

- scanner 能看到大量 sites
- recompile 实际 `0 applied`

因此 Katran authoritative case 上线前，应先完成：

- 基于 live enumerate 的 policy refresh

### 4.8 Tracee/Tetragon 的 `bpftool` 解析问题会连带影响公共统计链路

目前 `e2e/common/metrics.py` 和 `e2e/cases/tracee/case.py` 的部分路径还直接调用裸 `"bpftool"`。  
在 Ubuntu guest 上，这会踩到 `/usr/sbin/bpftool` wrapper，然后在 custom kernel 下失败。

这虽然不是 Katran 专属问题，但如果不先修通公共 `bpftool` 解析，Katran 后面的 runtime stats 同样会被拖住。

## 5. Tracee / Tetragon 现有设计的真实性审查

### 5.1 Tracee

### 当前设计里真实的部分

当前 `tracee` case 的 **daemon mode** 大体上是可信的：

- 它起的是官方 `tracee` binary
- 用的是 Tracee 官方支持的 `--events` 方式
- 事件输出走 JSON stdout
- live program discovery 是对 daemon 实际加载出来的 BPF 程序做的

这和 Tracee 官方文档是对得上的：

- 官方安装文档同时列了 binary release、Docker image、Helm chart
- 官方 events 文档明确支持 `tracee --events execve`
- 官方 prerequisites 文档明确要求 root / capabilities

所以：

- **Tracee daemon mode 是真实的 Linux 非 Kubernetes 部署路径**
- **manual fallback 不是**

### 当前设计里不真实的部分

不真实或不应进入 authoritative 结果的部分有：

- `manual_fallback`
  - 直接从 `tracee.bpf.o` 里手挑几个程序手动 attach
  - 这只能算调试/兜底路径，不能算官方部署
- setup 把二进制临时解到 `/tmp/tracee-bin`
  - 这对 smoke 可以接受
  - 但 authoritative run 更应该 pin 官方 release 版本，并固定安装路径

### 是否需要修正

建议修正，但不是推翻重做：

- authoritative Tracee 结果只接受 **real daemon mode**
- `manual_fallback` 保留给 smoke/debug，不写进 headline 结果
- 如需更贴近官方 policy 工作流，可以把当前 `--events` 方案升级为：
  - `tracee --policies <yaml>`

这不是 correctness blocker，因为 `--events` 本身也是官方支持的；只是 policy YAML 更接近现在 Tracee 文档的主工作流。

### Tracee 的 `bpftool` 问题怎么解决

根因不是 Tracee 本身，而是我们自己的 harness 对 `bpftool` 解析不一致。

当前明确有问题的地方：

- `e2e/cases/tracee/case.py::_current_prog_ids()` 直接调用 `"bpftool"`
- `e2e/common/metrics.py::sample_bpf_stats()` 直接调用 `"bpftool"`

应当统一修成：

1. 所有 `bpftool` 调用都走 `e2e/common/__init__.py::resolve_bpftool_binary()`
2. VM guest script 里统一：
   - `export PATH="/usr/local/sbin:$PATH"`
   - `export BPFTOOL_BIN=/usr/local/sbin/bpftool`
3. case preflight 里加一个强检查：
   - `bpftool version`
   - `bpftool -j -p prog show`
4. 如果解析到的是 Ubuntu wrapper，或者 `prog show` 失败，直接 fail fast，不要继续 benchmark

这样 Tracee 的 `bpftool` 问题就会一次性解决，而且 Katran/Tetragon 也能一起受益。

### 5.2 Tetragon

### 当前设计里真实的部分

从代码设计看，`tetragon` case 的 **daemon mode** 是基本符合官方支持路径的：

- 起的是官方 `tetragon` binary
- 用的是官方支持的 `--tracing-policy-dir`
- 读的是真实 daemon 加载出来的 live programs

Tetragon 官方文档明确写了：

- `TracingPolicy` 虽然是 Kubernetes CR，但也支持非 Kubernetes 环境
- 非 Kubernetes 下可以用 `--tracing-policy` / `--tracing-policy-dir` 在启动时静态加载 policy

所以从方法论上讲：

- **Tetragon daemon mode 是真实的**

### 当前设计里不真实的部分

但当前已经跑出来的报告里，真正成功的 VM run 是：

- `mode = manual_fallback`

也就是：

- 没有真的把官方 Tetragon daemon 跑起来
- 而是直接 load 了 `bpf_execve_event.bpf.o` 和 `bpf_generic_kprobe.bpf.o`

这就意味着：

- 代码里虽然有真实路径
- **当前有效结果本身还不够真实**

### 是否需要修正

需要。

authoritative Tetragon 结果应当满足：

- setup 能得到可运行的 `tetragon` binary
- health check 不只看 BPF program 可见，还要看 daemon 真正 ready
- benchmark 结果必须是 `tetragon_daemon` mode

比较接近官方 Linux package mode 的做法是：

- 用官方 release tarball
- 跑 `install.sh` 或至少复刻其目录布局
- 用 `tetra --server-address unix:///var/run/tetragon/tetragon.sock getevents` 验证 daemon 和 gRPC socket

`manual_fallback` 仍可保留，但应明确标成：

- debug only
- non-authoritative

### `bpftool` 部分

Tetragon 这边已经比 Tracee 好一些：

- 支持 `BPFTOOL_BIN`
- `guest_smoke.sh` 也显式导出 `/usr/local/sbin/bpftool`

所以这里的建议不是重写，而是：

- 把这套解析方式下沉到公共层
- 让 Tracee 和共享 metrics 也完全复用

## 6. 具体实现步骤

1. **补齐源码来源**
   - 在仓库内 vendor 或临时 clone 完整 upstream Katran 源码，不能继续依赖 sparse `corpus/repos/katran/` 作为 build source。

2. **先补 kernel 依赖**
   - 最少打开 `CONFIG_NET_IPIP=y`。
   - 如果允许顺手补，建议再打开 `CONFIG_VETH=y` 和 `CONFIG_IPV6_TUNNEL=y`。

3. **新增 Katran case 骨架**
   - 新建 `e2e/cases/katran/{case.py,setup.sh,config.yaml,guest_smoke.sh}`。

4. **做 host-side build cache**
   - `setup.sh` 检查完整源码、构建目录、Go client 产物。
   - 缺失时执行官方 `build_katran.sh` 和 `build_grpc_client.sh`。

5. **实现 host-guest bridge 启动**
   - authoritative VM run 改为 `vng --network bridge=<br>`。
   - 如果只写 `bridge`，明确接受其默认桥是 `virbr0`。
   - guest 以内长生命周期模式启动，便于 host workload 与 guest scanner 并发。

6. **实现 authoritative 网络 bring-up**
   - host 上准备 bridge IP / MAC
   - host 上打开 `net.ipv4.ip_forward=1`
   - host 上配 VIP 路由：`10.200.200.1/32 via <guest-lb-ip>`
   - guest 内 stable rename 成 `katran0`
   - guest 内配置 `default via <host-bridge-ip>`
   - guest 内配置 secondary real IP
   - guest 内配置 `ipip0` + `VIP/32 on lo` + `rp_filter=0`

7. **实现 Katran server lifecycle**
   - mount bpffs
   - 起 `xdproot`
   - 起 `katran_server_grpc`
   - 起官方 Go client 配 VIP/real
   - 做 health check：gRPC port、`katran_goclient -l`、`find_bpf_programs(server_pid)`

8. **接 host-side workload**
   - authoritative 主 workload 用 host 上的 `wrk`
   - L4 packet / churn workload 用 host 上的 `nping`
   - 同时后台起 guest 内 `katran_goclient -s -lru` 或 `-s -sum` 收控制面 counters
   - 可选加 `vng --pin` + host `taskset` 做 CPU 隔离

9. **接 BpfReJIT**
   - 用 `find_bpf_programs()` 取 live `balancer_ingress`
   - 用 `scan_programs()` 做 live enumerate
   - 用显式 Katran policy path 做 live remap + `apply_recompile()`
   - baseline/post 都围绕同一个 live server 进程测
   - workload 在 host 触发，`bpftool prog show` snapshot 在 guest 记录

10. **修公共 `bpftool` 解析并同步清理 Tracee/Tetragon**
   - Tracee case 和 `e2e/common/metrics.py` 全部改用 `resolve_bpftool_binary()`
   - authoritative Tracee 结果只接受 real daemon mode
   - authoritative Tetragon 结果只接受 `tetragon_daemon` mode

11. **最后再做 policy refresh**
   - Katran 现有 `balancer_ingress.policy.yaml` 先基于 live enumerate 重新生成或更新
   - 否则 authoritative Katran case 很可能还是 `0 applied`

## 7. 最终建议

如果目标是替换当前 `xdp_forwarding` 的弱 E2E，Katran 是对的方向，但必须接受下面两个现实：

- 这不是一个“直接把 `.bpf.o` 换掉”的小改动；
- authoritative 实现前必须先补 kernel config 和完整 upstream source。

在这些前置条件满足后，最稳妥的路线是：

- **host 编译完整 Katran gRPC server/client**
- **host/独立 VM2 跑 `wrk` / `nping`，VM1 只跑 Katran + real + scanner/recompile**
- **VM 内按 shared-mode + DSR + routed single-arm topology 运行**
- **用 `vng --network bridge=<br>` 建 host-guest 桥接；如果只写 `bridge`，默认桥是 `virbr0`**
- **只把 `balancer_ingress` 作为 BpfReJIT 目标**
- **用官方 gRPC client 做 VIP/real/stats 配置，real 保留在 guest 内做 `ipip0` decap**
- **应用层结果从 host 采，BPF runtime 从 guest 的 `bpftool prog show` 采**
- **复用现有 `e2e/common` 的 agent/scanner/recompile/metrics/vm 基础设施，并新增 host workload runner**

这条路线既满足 Katran 官方文档，也能给 BpfReJIT 一个明显比 `xdp_forwarding` 更强、更真实的 E2E benchmark。
