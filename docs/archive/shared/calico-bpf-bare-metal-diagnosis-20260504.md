# Calico BPF Bare-Metal wrk Timeout — 完整诊断 + 所有尝试 (2026-05-04)

## TL;DR

历史 corpus calico/felix 始终 wrk timeout / measurable=0。本 doc 完整记录 5 轮诊断 + 多次错误判断 + 最终架构层 root cause + 推荐修复路径。

**最终结论**：Felix BPF dataplane attach 完全 OK（HEP + GNP + main programs 全装）。问题在 K8s pod 模型假设 vs 我们 bare-metal veth 单对 setup 的架构 mismatch。**改 setup 加 host-side workload veth 可让 A 方案工作**。

## 错误诊断 1: LPM_TRIE EINVAL = kernel-level bug (推翻)

felix process stderr_tail 显示:
```
libbpf: Error in bpf_create_map_xattr(cali_v4_nat_fe3):Invalid argument(-22). Retrying without BTF.
libbpf: Error in bpf_create_map_xattr(cali_v4_routes):Invalid argument(-22).
libbpf: failed to pin map: File exists
```

3 个 map 都 LPM_TRIE，初步以为 fork kernel 7.0-rc2 破坏了 BPF_MAP_CREATE 路径。

**反证**：`git log v7.0-rc2..HEAD -- kernel/bpf/lpm_trie.c kernel/bpf/syscall.c` 显示 fork 没动 lpm_trie.c 也没动 BPF_MAP_CREATE 主路径。fork commits 全是 REJIT/kop related：
- bpf: minimal prog rejit syscall
- bpf: expose original prog insns
- bpf: kop_ops with verifier modeling
- bpf: convert poke desc update BUG_ON to error return
- ... 全部 REJIT/kop，不动 map create

bcc/bpftrace/tracee/tetragon 用 hash/array map 全部正常 attach BPF program → BPF_MAP_CREATE 整体路径正常。

**真相**：这些 EINVAL 是 Felix 自己 fallback 路径噪音。Felix maps.go:738 用 stub object（`ipv4_map_stub.o`）通过 libbpf 试 create，失败后转 `GetMapFDByPin` 路径成功：

```
felix/maps.go 738: Trying to create map from obj file b.VersionedName()="cali_v4_nat_fe3" objName="ipv4_map_stub.o"
felix/syscall.go 34: GetMapFDByPin(/sys/fs/bpf/tc/globals/cali_v4_nat_fe3)
felix/maps.go 833: Loaded map file descriptor. fd=0x31 name="/sys/fs/bpf/tc/globals/cali_v4_nat_fe3"
```

Map 实际**创建成功**。stderr_tail 200 lines 全被 retry noise 占满，掩盖真因。

## 错误诊断 2: HEP mapping 失败 (推翻)

源码读完 felix `bpf_ep_mgr.go:2884-2965 attachDataIfaceProgram` + `endpoint_mgr.go:1170 resolveHostEndpoints` + `hostendpointprocessor.go:86`，发现 HEP 通过：

```
v3.HostEndpoint.Spec.InterfaceName → proto.HostEndpoint.Name
endpoint_mgr.resolveHostEndpoints: hostEp.Name == ifaceName → match
→ hostIfaceToEpMap[bpfbench0] = HEP
→ bpf_ep_mgr.attachDataIfaceProgram(ep != nil) → updatePolicyProgram → jumpmap[PolicyIdxV4]
```

任何一步断 → `ep == nil` → `removePolicyProgram` → preamble tail call 找不到 policy → drop。

**反证**：felix Debug log（启用 `FELIX_LOGFILEPATH=corpus/results/calico-felix-debug.log` + `FELIX_LOGSEVERITYFILE=Debug`，host-shared 路径捕获 244K log）证明 HEP mapping 完全成功：

```
felix/int_dataplane.go 2357: Received *proto.HostEndpointUpdate update
  endpoint:{name:"bpfbench0" expected_ipv4_addrs:"198.18.0.1"}

felix/pol_prog_builder.go 553: End of policy "default.bpfbench-allow-all" 0
felix/bpf_ep_mgr.go 4280: Putting sub-program 0 at position 2 in map cali_jump_ing2

felix/attach.go 164: Program attached to tcx.
  Iface:"bpfbench0" Hook:0 PolicyIdxV4:2
  HookLayoutV4:hook.Layout{0:12, 2:13, 3:14, 4:15, 6:16, 7:17, 8:18}
  HostIPv4:198.18.0.1 Type:"l3dev" ToOrFrom:"from"

felix/bpf_ep_mgr.go 2086: Applied program to host interface id="bpfbench0"
```

- HEP `proto.HostEndpoint{name="bpfbench0", expected_ipv4_addrs="198.18.0.1"}` 正确接到
- Policy program (allow-all) 编译 + load 成功
- TCX preamble + main programs 全部 attach 到 bpfbench0 ingress + egress
- HookLayoutV4 包含完整 main programs jumpmap indices
- HostIPv4 = 198.18.0.1 正确
- PolicyIdxV4 = 2 指向 jumpmap allow-all policy program

**完整 BPF dataplane attach 完全成功**。

## 错误诊断 3: cali_v4_routes 空 = drop (部分对，但根因不在 routes 本身)

发现 felix attach 完整后还是 wrk timeout。怀疑 `cali_v4_routes` LPM_TRIE 空 → `cali_tc_main` forward 时找不到 route → drop。

依据：Felix BPF dataplane 设计假设 K8s + WorkloadEndpoint + IPPool 提供 routes，bare-metal 没这些 → routes 空。docs 也明确说 BPF dataplane 只 K8s 支持。

实施 A 方案 (IPPool + WEP) 验证。

## A 方案：IPPool + WEP 实施 (失败但揭示真因)

### Round 1: IPPool CIDR 不 strict-mask
错误: `IPPool.Spec.CIDR = '198.18.0.1/30' (IPPool CIDR is not strictly masked)`
修: `pool_cidr = ipaddress.ip_network(BENCHMARK_IFACE_CIDR, strict=False)` → `198.18.0.0/30`

### Round 2: WEP name 必须用 `--` escape `-`
错误: `WorkloadEndpoint name 'virtme-ng-bpfbench-bpfbench-bpfbench1' does not match expected 'virtme--ng-bpfbench-bpfbench-bpfbench1'`
修: `_esc(s) = s.replace("-", "--")` 应用到所有 component

### Round 3: 两个 resource 都 apply 成功，但 wrk 仍 timeout

felix log 显示：
```
felix/conversion.go: Key is valid and converted to model-etcdKey 
  model-etcdKey=WorkloadEndpoint(default/virtme--ng-bpfbench-bpfbench-bpfbench1)
felix/conversion.go: Key is valid and converted to model-etcdKey 
  model-etcdKey=IPPool(bpfbench-pool)
felix/int_dataplane.go 2357: Received *proto.WorkloadEndpointUpdate
  endpoint:{name:"bpfbench1" ipv4_nets:"198.18.0.2/32" 
            tiers:{ingress_policies:"default.bpfbench-allow-all" ...}}
```

calc graph 收到 ✓。但 dataplane 应用阶段全部失败：

```
felix/bpf_ep_mgr.go 1966: Ignoring interface that doesn't match the host data/l3 interface regex iface="bpfbench1"
felix/bpf_ep_mgr.go 1969: Removing interface that doesn't match... and is not workload interface iface="bpfbench1"
felix/route_table.go 458: SetRoutes called. ifaceName="bpfbench1" CIDR=198.18.0.2/32
felix/route_table.go 652: Skipping route for missing interface. ifaceName="bpfbench1"
felix/endpoint_mgr.go 851: Failed to get link bpfbench1: Link not found
felix/endpoint_mgr.go 1521: Skipping configuration of interface because it is oper down. ifaceName="bpfbench1"
felix/endpoint_mgr.go 636: Re-evaluated workload endpoint status 
  adminUp=true failed=false known=true operUp=false status="down"
```

## 真正的架构层 Root Cause

**Felix 跑在 root ns，看不到 bpfbench1（在 bpfbenchns netns 内）**。

Calico K8s pod 模型 (canonical):
```
[root ns]                                  [pod netns]
  caliXXXX (host-side veth, no IP) ──────  pod-eth0 (pod IP)
       │                                       │
   Felix attaches BPF here                  workload runs here
   Felix manages routes
```

我们 bare-metal setup:
```
[root ns]                                  [bpfbenchns]
  bpfbench0 (host iface, 198.18.0.1) ─── bpfbench1 (peer, 198.18.0.2)
       │                                       │
   Felix attaches HEP BPF here              nginx runs here
                                            (Felix 看不到这个)
```

WEP 模型要求 host-side workload veth 在 root ns（caliXXXX 类）。我们没有这个 — 直接把 198.18.0.2 放在 netns 里的 peer 上。Felix calc graph 收 WEP 但 dataplane 应用阶段：
- `bpf_ep_mgr` 在 `wlIfacesRegexp` 找 bpfbench1 — 不匹配 `^cali.*` → 被 discard
- `route_table` 找 link bpfbench1 — root ns 里没有 → `Skipping route for missing interface`
- `endpoint_mgr` 试 attach — `Failed to get link` → `oper down` → status `down`

routes 没 push 到 BPF map → wrk 流量经过 bpfbench0 BPF egress → 找 cali_v4_routes 没 198.18.0.2 → drop or pass-through 无法确认（需要 BPFLogLevel=Debug）。

## 真正的修复方向：改 setup 加 host-side workload veth

用户指出此点。Calico K8s 模型要求：
- host-side workload veth 在 root ns（Felix 管）
- pod-side veth 在 netns（workload 跑）

我们要 mimic 这个，可以采用：

### 方案 α: 重命名现有 veth + 加 cali prefix

最小改动：
1. `bpfbench0` 仍在 root ns，但去掉 BPFDATAIFACEPATTERN（不当 host iface）
2. `FELIX_INTERFACEPREFIX="cali,bpfbench"` 让 bpfbench* 匹配 workload 正则
3. 不 apply HEP；改 apply WEP 给 `bpfbench0`（!!! 这是 host-side workload veth），ipNetworks=`198.18.0.2/32`
4. apply IPPool 198.18.0.0/30
5. nginx 在 bpfbench1 (netns) 监听 198.18.0.2

Felix workflow:
- bpfbench0 在 root ns ✓ — Felix 能 attach BPF
- WEP for bpfbench0 — Felix 装 workload BPF (cali_tc_main "from-workload" / "to-workload")
- `cali_v4_routes` push 198.18.0.2 → via bpfbench0
- wrk → kernel route 198.18.0.0/30 dev bpfbench0 → BPF egress 处理 → 流到 bpfbench1 → nginx
- BPF program triggers, **measurable_count > 0**

代码改动：~20 行 calico.py（replace HEP with WEP，加 IPPool，改 env vars）

⚠️ 注意 bpfbench0 IP 198.18.0.1：K8s host-side veth 不带 IP，但 Felix 不 enforce 这个 — bpfbench0 带 IP 应该不影响 Felix 把它当 workload-side。

### 方案 β: 加第二对 veth 专给 calico

calico 用独立 calibench0/calibench1 veth pair：
- calibench0 (root ns, no IP, host-side)
- calibench1 (calibenchns, 198.18.0.6) — 不同子网
- HEP 仍可用 bpfbench0（保持现状）or 不用 HEP
- WEP for calibench0 + ipNetworks 198.18.0.6/32

更干净，对其他 app（cilium, katran）零影响，但 calico 需要自己 setup veth + netns + nginx。代码改动：~50 行。

### 方案 γ: 共用现有 setup，不改 iface 名字

只设 `FELIX_INTERFACEPREFIX="cali,bpfbench"`，Felix 把 bpfbench0 同时当 host iface (BPFDATAIFACEPATTERN 匹配) AND workload iface (prefix 匹配)。Felix 内部如何处理冲突未明，可能 felix 直接 ignore 或者 panic。

**未推荐 γ** — 双重身份 corner case 风险高。

### 推荐：方案 α

最小改动，符合 K8s 模型语义。代码改动 ~20 行：
1. 去掉 `FELIX_BPFDATAIFACEPATTERN` env 设置（让默认 regex 不匹配 bpfbench0）
2. 加 `FELIX_INTERFACEPREFIX=cali,bpfbench`
3. 删 `_register_host_endpoint()` 调用
4. 加 `_apply_ip_pool()` apply 198.18.0.0/30
5. 加 `_apply_workload_endpoint()` apply WEP 引用 `bpfbench0` (注意是 host-side 不是 peer！) ipNetworks=198.18.0.2/32
6. cleanup 加 IPPool + WEP 删除

## 当前状态 (commit pending)

- calico.py 撤回到 BACKEND=bird + HEP + GNP + nft cleanup（A 方案 IPPool + WEP 已撤回因为 peer 在 netns）
- felix tail capture 在 `_run_workload` 保留（debug 用）
- felix log 文件输出已移除（恢复默认 LOGSEVERITYSCREEN=Info）

下一步：实施方案 α，验证 measurable_count > 0。

## 方案 α 第 4 轮失败：Felix link_addrs.go 删 host IP

实施方案 α (WEP 指 `bpfbench0` host-side + `FELIX_INTERFACEPREFIX=cali,bpfbench`) 后跑 vm-corpus，wrk **仍然 timeout**。

但这次 felix Debug log 显示**所有预期工作完成**：
- WEP 应用 ✓
- BPF program attach `Iface:"bpfbench0" Type:"workload"` ✓ (line 977, 987)
- jump map 装填 ingress + egress workload programs ✓

唯一一个 fatal 行 — `felix/link_addrs.go:371` (line 1056)：
```
Removed host side address on workload interface address=198.18.0.1/30 bpfbench0 ipVersion=4
```

**Felix 把 bpfbench0 当 WEP 后会主动 remove host 端 IP**（K8s 模型：host-side veth 不带 IP）。

后果：
- `bpfbench0` 不再有 198.18.0.1
- wrk 在 root ns 想 connect 198.18.0.2:18080
- 但 198.18.0.0/30 网络的 root-ns 端口已无 IP → wrk 没源 IP 路由出 → connection timeout

确认架构层 incompatibility：
- **WEP 模型要求 host-side veth 不带 IP**
- 但我们的 setup 在 `bpfbench0` 上用 198.18.0.1 作为 wrk 出口
- 同一个 iface 不能既是 wrk 出口（带 host IP）又是 WEP 端（被 felix 强删 IP）

## 真正可行的修复：方案 β（双 veth pair）

唯一正确的拓扑（mimic K8s pod model）：

```
[root ns]                        [pod-like netns]
  caliproxy0 (host-side, no IP, WEP) ─── wlpeer0 (198.18.0.2)
       ↑                                       ↑
    Felix attaches workload BPF             nginx serves
    Felix manages cali_v4_routes
       ↑
       │  routes 198.18.0.2 dev caliproxy0
       │
   wrk (root ns) ──────────► nginx
       (route via 198.18.0.0/30 dev caliproxy0)
```

要 setup:
- 第一对 veth: `caliproxy0` (root ns, no IP, host-side workload) ↔ `wlpeer0` (netns, 198.18.0.2)
- WEP 引用 `caliproxy0`, ipNetworks=`198.18.0.2/32`
- 现有 `bpfbench0/bpfbench1` 保留给 cilium/katran/etc 用，calico 完全用独立 veth pair
- nginx 在 wlpeer0 ns 监听 198.18.0.2:18080

代码改动：~80 行 calico.py（独立 veth setup + WEP + nginx 移到 ns 内）+ runner/libs/setup_workspace.sh 加 second veth。

**方案 β 是唯一不与 Felix WEP 语义冲突的路径**。

## 当前状态 (再次撤回)

- 方案 α 失败 → calico.py 回滚到 status=ok / measurable_count=0 stable state
- felix log 文件输出 + tail capture 保留（diagnostic value）
- 方案 β 需独立 PR：~80 行 setup 改动 + 独立 ns + nginx 重定向

文档化 limitation：**without K8s/IPAM, Calico bare-metal 测不到 measurable BPF traffic**。这与 plan doc workload_miss 已知 limitation 一致。programs 仍 ReJIT，但 wrk 不通过 BPF dataplane。

## 关键源码引用

| 行 | 内容 |
|---|---|
| `runner/repos/calico/felix/dataplane/linux/bpf_ep_mgr.go:1966-1969` | 拒绝 non-data/non-workload iface |
| `runner/repos/calico/felix/dataplane/linux/bpf_ep_mgr.go:2884-2965` | `attachDataIfaceProgram` HEP 路径 |
| `runner/repos/calico/felix/dataplane/linux/bpf_ep_mgr.go:2952-2964` | `ep != nil → updatePolicyProgram` 关键分支 |
| `runner/repos/calico/felix/dataplane/linux/endpoint_mgr.go:1170` | `resolveHostEndpoints` HEP iface match |
| `runner/repos/calico/felix/dataplane/linux/endpoint_mgr.go:307` | `wlIfacesPattern = "^(<prefix>).*"` |
| `runner/repos/calico/felix/dataplane/linux/route_table.go:652` | `Skipping route for missing interface` |
| `runner/repos/calico/felix/bpf-gpl/tc_preamble.c:50-53` | preamble drops if `jumps[PROG_INDEX_MAIN] == -1` |
| `runner/repos/calico/felix/bpf-gpl/routes.h:44-48` | `cali_v4_routes` LPM_TRIE 256K |
| `runner/repos/calico/libcalico-go/lib/backend/syncersv1/updateprocessors/hostendpointprocessor.go:86` | `proto.HostEndpoint.Name = v3.Spec.InterfaceName` |

## Diagnostic Tooling 改进 (保留 in calico.py)

加入 `_run_workload` exception handler 抓 felix snapshot stderr/stdout tail 到 error message，确认 felix-side 错误信息能 surface 到 corpus result。这次诊断的关键工具。

## 时间线 (本日)

| 时间 | 事件 |
|---|---|
| 13:30 | Mode A (BACKEND=bird) 派 sonnet 实施 — 7 轮 wrk timeout 全失败 |
| 14:30 | 用户介入，要我自己读 calico/cilium docs |
| 15:00 | 完整读 6 个 Calico 官方 doc — 发现 BPF dataplane K8s only |
| 15:30 | 用户要求源码层验证 — 读 ~600 行 felix BPF dataplane 源码 |
| 16:00 | 错误诊断 LPM_TRIE EINVAL — 推翻 |
| 16:30 | 加 felix Debug log to host-shared file — 拿到完整 244K log |
| 17:00 | 错误诊断 HEP mapping — 推翻（felix log 证明 HEP 完全 OK） |
| 17:30 | A 方案 IPPool + WEP 实施 — 揭示真因（架构层 mismatch）|
| 18:00 | 用户提示改 setup — 重新规划方案 α |

## Lessons Learned

1. **`stderr_tail` 200 lines 不够** — Felix retry noise 占满，第一手 error 被截断。需要 file-based log capture
2. **felix log 必须 host-shared** — KVM 内 docker container 的 log 默认丢失，需要 LOGFILEPATH 写到 corpus/results/（host bind-mount）
3. **fork kernel commits ≠ kernel-level bug** — 必须 git log 验证才能下 kernel-level 结论
4. **过早结论是反复失败的根本原因** — 应该先把 evidence 收齐再判断
5. **架构层 mismatch 难一眼看出** — 需要 dataplane 应用阶段 log（route_table.go / endpoint_mgr.go）才能定位
