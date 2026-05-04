# App Cleanup Status Audit (2026-05-04)

## TL;DR

- **Overall**: cleanup quality is uneven but progressively better for network-facing apps. Tracing apps (tracee, tetragon, bpftrace, bcc, otelcol) rely entirely on process death for BPF auto-detach. Network apps (calico, cilium) explicitly delete the benchmark veth to drop orphaned TC attachments. Katran is the most thorough: it runs a teardown wait loop and explicitly detaches XDP + unpins bpffs objects.
- **Inter-app interference main risks**: (1) Calico or Cilium stop() leaving TC programs attached to `bpfbench0` before deleting the veth — both now handle this by deleting the veth, but only if `is_benchmark_interface(self.device)` is true. (2) Katran's network namespaces (katran-router/client/real) not cleaned up on abnormal exit. (3) `bpfbenchns` netns surviving between app runs when calico/cilium fail mid-start. (4) Calico etcd data surviving in memory-only but etcd process properly killed; Node/HEP/GNP resources are explicitly deleted before etcd shutdown.
- **Minimum cleanup** (no design change): two P0 items and three P1 items detailed below.

---

## Per-App Status

### tracee

- **start()**: Launches upstream `tracee` binary with `--events '*'` and a healthz HTTP server. Discovers BPF programs via `bpftool prog show` (program ID set stable after start).
- **stop()** (line 318–326 in `tracee.py`): Calls `stop_agent(process, timeout=30)` → sends SIGINT, escalates to SIGTERM then SIGKILL. No explicit BPF cleanup.
- **BPF cleanup**: Tracee uses kprobe/tracepoint/raw_tracepoint attach types. All are process-fd-scoped: when the tracee process dies and closes all fds, the kernel auto-detaches. No pinned objects in `/sys/fs/bpf/`. **No explicit BPF detach needed.**
- **Network cleanup**: Does not use any network namespace or custom interface. No network cleanup needed.
- **Kernel state leak**: None. Tracee writes event output to `--output none`, uses a tmpdir under `$TMPDIR/tracee`. The tmpdir is NOT removed in `stop()`. The runtime dir is preserved across runs (created with `mkdir -p`, not `mkdtemp`), which is benign but wastes disk space.
- **Risk**: **低**. Process death is sufficient for all BPF program cleanup.

---

### tetragon

- **start()** (line 168–189 in `tetragon.py`): Launches `tetragon` binary with `--tracing-policy-dir`, `--bpf-lib`, health+gRPC server addresses. Discovers BPF programs via ID set stable.
- **stop()** (line 206–210): Calls `session.close()` which calls `stop_agent(process, timeout=8)` → SIGINT/SIGTERM/SIGKILL. No explicit BPF cleanup.
- **BPF cleanup**: Tetragon uses kprobe/tracepoint/raw_tracepoint. All are fd-scoped. **Auto-detach on process death.** No pinned objects observed.
- **Network cleanup**: No network namespace, no custom interface. N/A.
- **Kernel state leak**: Tetragon has 287+ BPF programs (observed in prior investigations). With `timeout=8` in `stop_agent`, there is a risk that SIGINT takes longer than 8s to flush its ring buffers. If the process gets killed before graceful shutdown, ring buffer contents may be lost but BPF programs detach regardless (kernel refcount drops to zero).
- **Risk**: **低** for inter-app interference. Internally, fast kill may leave Tetragon's map state uncleared, but maps die with the process too.

---

### bpftrace

- **start()** (line 97–139 in `bpftrace.py`): Runs `bpftrace -q <script>` as a subprocess. Discovers BPF programs via ID set stable.
- **stop()** (line 169–200): Calls `stop_agent(process, timeout=8)` → SIGINT → SIGTERM → SIGKILL. Joins IO threads (2s each). No explicit BPF cleanup.
- **BPF cleanup**: bpftrace attaches kprobes, uprobes, and raw_tracepoints. All are fd-scoped. bpftrace also manages its own perf event fds. **Auto-detach on process death.** bpftrace does not pin objects to bpffs.
- **Network cleanup**: No network namespace. Scripts: tcplife, tcpretrans (network), biosnoop (disk), runqlat (scheduler), capable (OS), vfsstat (filesystem). None create interfaces.
- **Kernel state leak**: None.
- **Risk**: **低**.

---

### bcc

- **start()** (line 357–425 in `bcc.py`): Spawns distro BCC tool (e.g., `tcptracer-bpfcc`) as subprocess. Prepares a tmpdir for Python compat shim via `mkdtemp`. Discovers BPF programs via ID set stable.
- **stop()** (line 448–478): Calls `stop_agent(session.process, timeout=8)`. Joins IO threads (2s each). **Explicitly removes `_compat_dir`** via `shutil.rmtree` (line 469–471).
- **BPF cleanup**: BCC tools use kprobe/tracepoint/socket filter. All fd-scoped. **Auto-detach on process death.** BCC does not pin objects.
- **Network cleanup**: No network namespace.
- **Kernel state leak**: The `bcc-kheaders` tmpdir under `$TMPDIR/bcc-kheaders/<release>/` (extracted from `/sys/kernel/kheaders.tar.xz`) is NOT cleaned up in `stop()`. It is created once per kernel release and reused across runs (protected by flock). Intentional: this is a build artifact that should persist for performance.
- **Risk**: **低** for inter-app interference.

---

### katran

- **start()** (line 883–930 in `katran.py`): Creates three network namespaces (katran-router, katran-client, katran-real) via `KatranDsrTopology.__enter__()`. Creates veth pairs (katran0/rtlb0, rtcl0/client0, rtreal0/real0). Loads `xdp_root.bpf.o` via `bpftool prog load` + pins to `/sys/fs/bpf/bpf-benchmark-katran-<pid>-<ns>/`. Attaches XDP via `bpftool net attach`. Launches `katran_server_grpc`. Launches namespace HTTP server. Rewrites to xdpgeneric mode.
- **stop()** (line 953–974): Stops server session → calls `KatranServerSession.close()` → calls `_cleanup_root_xdp_install()` which detaches all XDP modes (xdpgeneric, xdpdrv, xdp) with `check=False` and removes the bpffs pin dir. Then closes HTTP server. Then closes topology → `KatranDsrTopology.cleanup()` which deletes katran0 interface (or moves router peer back) and deletes all three namespaces. Then calls `wait_for_katran_teardown()` which polls until katran prog IDs disappear AND all three namespaces are gone (10s timeout).
- **BPF cleanup**: **Explicit and thorough.** XDP prog is detached (all modes tried), bpffs pin dir is removed. katran_server holds fds for the XDP prog; when process dies, kernel drops refcount. The explicit detach + unpin ensures maps are also freed.
- **Network cleanup**: **Explicit.** All three namespaces deleted in `cleanup()`. katran0 veth deleted (veth deletion cascades to move peer out of namespace). Healthcheck tunnel interfaces (ipip0, ipip60) deleted if created.
- **Kernel state leak**: Kernel modules (veth, ipip, ip6tnl) are loaded but NOT unloaded in `stop()`. This is safe: modules are ref-counted and shared. The `wait_for_katran_teardown` timeout (10s) is the only window where a subsequent app could race.
- **Risk**: **低–中**. Teardown is thorough but `wait_for_katran_teardown` can raise if kernel doesn't quiesce within 10s. On abnormal exit (exception before `wait_for_katran_teardown`), error is propagated; corpus driver then calls `wait_for_suite_quiescence()` as a fallback. **Exception path**: if `session.close()` raises, `http_server.close()` and `topology.close()` may not run (they're in a sequential `for attr in ("http_server", "topology")` loop that continues regardless of prior exceptions — actually errors are accumulated, not short-circuited — see line 965–970). So topology IS cleaned up even if session errors.

---

### calico

- **start()** (line 485–506 in `calico.py`): Creates `LocalEtcdSession` (tmpdir under /tmp/var/tmp). Calls `calico-node -startup` to initialize datastore. Patches Node BGP IPv4. Applies GlobalNetworkPolicy (allow-all). Registers HostEndpoint. Calls `super().start()` which launches `calico-node -felix`. Uses benchmark interface `bpfbench0` (veth pair with `bpfbenchns`). Felix attaches TC BPF programs (from_hep/to_hep) to the interface.
- **stop()** (line 508–522): Calls `super().stop()` (which kills felix process via `stop_agent` timeout=8). Then `_delete_host_endpoint()` which calls `calicoctl delete hostendpoint` and `calicoctl delete globalnetworkpolicy` (check=False). Then `etcd_session.close()` (kills etcd, removes work_dir). Then `shutil.rmtree(runtime_dir)`. Then **deletes `bpfbench0`** via `_delete_link_if_exists(BENCHMARK_IFACE)` with comment: "TC attachments survive process death because they are scoped to the network interface, not the process."
- **BPF cleanup**: Felix attaches TC programs to `bpfbench0`. TC attachments are **not** process-fd-scoped — they survive process death. The fix is explicitly deleting the interface, which the code does (line 521–522). This removes TC attachments as a side effect of interface deletion.
- **Network cleanup**: `bpfbench0` veth is deleted in `stop()` (line 521). The `bpfbenchns` netns is **NOT** deleted in stop(). It persists and is reused by `_ensure_benchmark_interface()` in the next start (it checks if netns exists and creates only if not). The peer veth `bpfbench1` disappears when `bpfbench0` is deleted (veth pair auto-deletion).
- **Kernel state leak**: Etcd data is ephemeral (tmpdir). Felix creates NFTables rules; on process death these are left. Felix BPF maps are unlinked when interface is deleted. Node/HEP/GNP data is deleted from etcd before etcd shutdown. **NFTables rules leak** on process death: Felix installs NFT rules for MASQUERADE etc. These persist after felix dies and the interface is deleted. However, since bpfbench0 is deleted, the NFT rules are orphaned and functionally inert (no matching interface). Still cosmetically leaky.
- **Risk**: **中** without the veth deletion, **低** with it. The veth deletion at line 521 is the critical cleanup that prevents TC-program interference with Cilium.

---

### cilium

- **start()** (line 194–214 in `cilium.py`): Creates tmpdir with subdirs `bpffs/` and `state/`. Creates `LocalEtcdSession`. Runs `_ensure_benchmark_interface()` to set up bpfbench0 veth pair. Launches `cilium-agent` with `--bpf-root=<tmpdir>/bpffs`, `--state-dir=<tmpdir>/state`, `--devices=bpfbench0`. Cilium attaches TC programs (from-container/to-container direction) to bpfbench0.
- **stop()** (line 216–231): Calls `super().stop()` (kills cilium-agent, timeout=8). Then `etcd_session.close()`. Then `shutil.rmtree(runtime_dir)` (removes bpffs mount subdir and state). Then **deletes `bpfbench0`** via `_delete_link_if_exists(BENCHMARK_IFACE)` (line 231), same rationale as calico.
- **BPF cleanup**: Cilium pins many programs and maps to `--bpf-root` (the tmpdir bpffs subdir). `shutil.rmtree(runtime_dir)` removes the bpffs subdir (the local filesystem path). If cilium-agent's `--bpf-root` is a bind mount of the real bpffs, this only removes the directory but not the kernel objects. However here bpf_root is a tmpdir path — Cilium may or may not mount bpf there. If it does mount, `shutil.rmtree` will fail or not unmount. Cilium's TC attachments to bpfbench0 are cleaned by interface deletion. Programs pinned under a separate bpffs mount may leak if the mount is not unmounted.
- **Network cleanup**: `bpfbench0` deleted in stop() line 231. `bpfbenchns` netns NOT deleted (same as calico — shared pattern).
- **Kernel state leak**: If Cilium mounts bpffs at `--bpf-root`, that mount may survive `shutil.rmtree`. Pinned programs/maps under that mount survive until the mount is unmounted. However, once cilium-agent dies and bpfbench0 is deleted, the remaining pinned objects are stranded (no live process holds refs through attachment). They will be freed when the filesystem is unmounted or when the pinned paths are explicitly removed. The `shutil.rmtree` on a mount point typically fails silently (`ignore_errors=True` not used here — wait, line 222: `shutil.rmtree(self.runtime_dir, ignore_errors=True)` — yes, ignore_errors=True). So if bpffs is mounted there, the tree removal silently fails and leaves pinned objects. This is a **potential medium risk**.
- **Risk**: **中**. If Cilium mounts bpffs under its bpf-root, pinned programs survive. Interface deletion prevents TC interference. Etcd cleanup is complete.

---

### otelcol-ebpf-profiler

- **start()** (line 120–128 in `otel_profiler.py`): Creates tmpdir via `mkdtemp`. Writes minimal config.yaml. Calls `super().start()` which launches `otelcol-ebpf-profiler` binary.
- **stop()** (line 130–134): Calls `super().stop()` (kills process, timeout=8). Then **in `finally`** calls `_cleanup_runtime_dir()` which removes the tmpdir via `shutil.rmtree(ignore_errors=True)`.
- **BPF cleanup**: otelcol-ebpf-profiler uses perf events and uprobe/kprobe. All fd-scoped. **Auto-detach on process death.**
- **Network cleanup**: No network namespace, no custom interface.
- **Kernel state leak**: None significant. tmpdir cleanup is guaranteed in `finally`.
- **Risk**: **低**.

---

## Inter-app Interference Matrix

| app1 stop() leak | impact on app2 start() |
|---|---|
| Calico TC programs on bpfbench0 (pre-fix: no veth deletion) | Cilium's `cilium-agent` sees pre-existing TC programs on bpfbench0; may fail to attach its own or produce unexpected policy behavior |
| Cilium TC programs on bpfbench0 (pre-fix: no veth deletion) | Calico's Felix sees TC programs on bpfbench0 from prior run; Felix detects "unexpected" state, may reset or fail |
| **Both now fixed**: calico.py line 521 and cilium.py line 231 delete bpfbench0 in stop() | Next app gets fresh interface via `_ensure_benchmark_interface()` |
| Katran namespaces (katran-router/client/real) surviving abnormal exit | Katran next run: `KatranDsrTopology.__enter__()` calls `self.cleanup()` first (line 260), so it self-heals. Other apps: no impact. |
| Katran XDP program on katran0 surviving (if stop() errors before _cleanup_root_xdp_install) | Next Katran start calls topology.cleanup() → deletes katran0 → XDP detaches. Self-healing. |
| `bpfbenchns` netns persisting between runs | None: `_ensure_benchmark_interface()` checks existence and reuses it. No conflict. |
| Cilium pinned programs under bpffs mount (if mount not unmounted) | Subsequent apps won't see them (different iface/ns). Programs consume kernel memory but don't interfere functionally. |
| Calico NFTables rules surviving felix death | Orphaned rules (no interface, no nat target) — no functional impact on next app. |
| Tracee/tetragon kprobes surviving process death | Impossible: kprobe/tracepoint attachments are fd-scoped; when tracee/tetragon process closes all fds, kernel detaches. |

---

## 最小清理建议（不改设计）

### P0 (必须修复 — 当前有实际干扰风险)

1. **Cilium bpffs mount cleanup**: `cilium.py stop()` 在 `shutil.rmtree(self.runtime_dir, ignore_errors=True)` 之前，先检查并 `umount self._bpf_root`。如果 cilium-agent 在 `--bpf-root` 下 mount 了 bpffs，那么 shutil.rmtree 会静默失败，pinned programs/maps 残留。需在 `stop()` 里加：
   ```python
   if self._bpf_root is not None and self._bpf_root.is_mount():
       run_command(["umount", str(self._bpf_root)], check=False, timeout=10)
   ```
   这样 pinned 对象随 umount 被清理（如果没有其他 ref）。

2. **corpus driver: `wait_for_suite_quiescence()` 保证在每个 app stop 后调用**: 检查 `driver.py` 第 827–842 行的异常路径——`wait_for_suite_quiescence()` 确实在 exception 路径里调用了（第 836 行）。但在 `_run_suite_lifecycle_sessions()` 正常 stop 路径（`stop_session`）里没有调用 quiescence。正常路径里所有 session 在 `finally` 块（第 713–715 行）停止，之后 `run_suite` 继续下一个 app 的 `runner.start()`，没有间隔的 quiescence 等待。需在 `run_suite()` 里每个 app 完成后加 `wait_for_suite_quiescence()` 调用，确保 BPF IDR 稳定再启动下一个 app。

### P1 (中优先 — 有残留但当前无已知 app 间冲突)

3. **Calico NFTables 规则清理**: Felix 安装 NFTables 规则（MASQUERADE 等），进程死后规则残留。虽然 bpfbench0 删除后规则功能性失效，但 `nft list ruleset` 会留有垃圾。在 `CalicoRunner.stop()` 里 super().stop() 之后加 `run_command(["nft", "flush", "ruleset"], check=False, timeout=10)` 可清除，但这过于激进（会清所有 NFT 规则）。更保守：`run_command(["nft", "delete", "table", "ip", "calico"], check=False, timeout=10)` 只清 calico table。

4. **Tracee/Tetragon tmpdir cleanup**: Tracee 的 runtime dir (`$TMPDIR/tracee/`) 在 stop() 里不清除（signatures dir 等 persist）。Tetragon 使用 `--bpf-lib` 指向 artifact dir（不是 tmpdir），无问题。只有 Tracee 的 tmpdir 可能积累。在 `TraceeRunner.stop()` 之后加 tmpdir 清理（但需要注意 tracee 会复用同一个 tmpdir 跨运行，如果同一个 TraceeRunner 实例多次 start/stop）。

5. **Katran `wait_for_katran_teardown` 超时改进**: 当前 10s，如果内核 namespace 回收慢（虚拟机中常见），可能 raise。应在 corpus driver 的 `wait_for_suite_quiescence()` 里也等 katran ns 消失，或将超时适当提高（如 20s）。

### P2 (低优先 — 噪音/磁盘)

6. **BCC kheaders dir**: 不需要清理——这是有意设计的缓存（提取一次复用）。

---

## 设计相关分析

### framework 层（case_common.py）应该负责的
- `wait_for_suite_quiescence()` 在每个 app 之间的调用：**corpus driver 目前只在异常路径调用，正常路径里缺失。** 这是 framework 级别的保障，应该在 `run_suite()` 每个 app 完成后（不管成功失败）统一调用。

### app-specific stop() 必须负责的
- TC / XDP 显式 detach（calico.py 和 cilium.py 通过删 veth 处理）
- bpffs pin 目录清理（katran.py 显式 unpin + katran 的 bpffs install dir cleanup）
- namespace 删除（katran.py 的 KatranDsrTopology.cleanup()；calico/cilium 的 bpfbenchns 未删但无问题）
- etcd 进程 + 数据（calico/cilium 各自的 LocalEtcdSession.close()）

### corpus driver 现状
- `driver.py` 的 `run_suite()` 每个 app 循环：在 exception 路径调用 `wait_for_suite_quiescence()`（第 836 行），在正常 lifecycle 路径通过 `_run_suite_lifecycle_sessions()` 内部的 `finally` 停止所有 session，但**正常路径没有 quiescence 等待**。
- `_run_suite_lifecycle_sessions()` 是 sequential per-app（不是并发多 app），corpus 设计上是一次一个 app，理论上 quiescence 问题较小，但 BPF IDR 稳定还是需要时间。
- 已有 `wait_for_suite_quiescence()` 函数（case_common.py 第 100–126 行），等待 BPF prog IDR 20s 内稳定 2s。这应该被 corpus driver 正常路径调用。

---

## 结论

**8 个 app 的 cleanup 现状**：

| App | BPF auto-detach | 显式 net cleanup | etcd cleanup | 风险 |
|---|---|---|---|---|
| tracee | ✅ (fd-scoped) | N/A | N/A | 低 |
| tetragon | ✅ (fd-scoped) | N/A | N/A | 低 |
| bpftrace | ✅ (fd-scoped) | N/A | N/A | 低 |
| bcc | ✅ (fd-scoped) | N/A | N/A | 低 |
| katran | ✅ + 显式 detach+unpin | ✅ (ns + veth) | N/A | 低–中 |
| calico | TC 靠删 veth ✅ | bpfbench0 deleted ✅, bpfbenchns 保留(ok) | ✅ etcd killed+dir removed | 中→低 |
| cilium | TC 靠删 veth ✅, bpffs mount 未 umount ⚠️ | bpfbench0 deleted ✅, bpfbenchns 保留(ok) | ✅ etcd killed+dir removed | 中 |
| otelcol | ✅ (fd-scoped) | N/A | N/A | 低 |

**最严重的 inter-app interference (top 3)**:
1. Calico TC programs surviving on bpfbench0 into Cilium start — **已通过 bpfbench0 veth deletion 修复**（calico.py line 521）
2. Cilium bpffs mount surviving if `shutil.rmtree` fails silently on a mount point — **P0 pending fix**
3. corpus driver 正常路径缺少 `wait_for_suite_quiescence()` — 下一个 app 可能在 BPF IDR 还不稳定时 start — **P0 pending fix**

**P0 list（不改设计，只补强 stop() 必要清理）**:
1. `cilium.py stop()`: 在 shutil.rmtree 之前加 umount `self._bpf_root`（check=False）
2. `corpus/driver.py run_suite()`: 在每个 app 的 `_run_suite_lifecycle_sessions()` 返回后、下一个 app start 之前，调用 `wait_for_suite_quiescence()`（现在异常路径有，正常路径缺失）
