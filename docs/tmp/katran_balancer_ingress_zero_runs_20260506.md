# Katran `balancer_ingress` zero-run investigation

Investigation date: 2026-05-07 UTC, filename kept at `20260506` for the requested local-date report.

## Verdict

`balancer_ingress` is not being skipped by the traffic generator. The HTTP workload is already sending real client namespace traffic to the Katran VIP through the LB ingress veth. The zero `run_cnt_delta` is a measurement attribution artifact of Katran shared-root mode: `xdp_root` is the top-level XDP program attached to `katran0`, and it reaches `balancer_ingress` through `bpf_tail_call()` in `root_array[2]`. Kernel per-program `run_cnt`/`run_time_ns` accounting is visible at the top-level BPF entry, so the tail-call target row stays at zero.

If the paper needs a direct per-program row for the heavy LB program, run Katran in standalone mode for this benchmark so upstream `katran_server_grpc` attaches `balancer_ingress` directly to `katran0`. The current client/VIP/real traffic shape is the right one; the attach/composition mode is the problem.

## Topology

From `runner/libs/app_runners/katran.py`:

```text
root namespace
  katran0 192.0.2.2/24, MAC 02:00:00:00:00:0a
  XDP top-level today: xdp_root
        |
        | veth
        |
katran-router namespace
  rtlb0   192.0.2.1/24, MAC 02:00:00:00:00:0b
  rtcl0   10.0.0.1/24
  rtreal0 10.200.0.1/24
  route 10.100.1.1/32 via 192.0.2.2 dev rtlb0
  ip_forward=1
      |                           |
      | veth                      | veth
      |                           |
katran-client ns              katran-real ns
  client0 10.0.0.2/24          real0 10.200.0.2/24
  default via 10.0.0.1         lo 10.100.1.1/32
                                ipip0 external, up
                                HTTP server binds 10.100.1.1:8080
```

`run_parallel_http_load()` runs in `katran-client` and connects to `10.100.1.1:8080`, not loopback or the real namespace directly. The router route sends that VIP traffic to next-hop `192.0.2.2` on `rtlb0`, so it enters the root namespace through `katran0` XDP ingress.

## Attach And Dispatch Evidence

The latest saved artifacts contain `bpftool prog show`-derived counters but not a persisted `bpftool net show dev katran0` dump. I did not complete a fresh smoke run: even `make -n BPFREJIT_CORPUS_APPS=katran SAMPLES=1 corpus` expanded into recursive kernel/image build commands, so I stopped that path as not cheap.

Available evidence:

| Source | Evidence |
| --- | --- |
| `katran.py` lines 782-823 | Runner loads `xdp_root.bpf.o` with `bpftool prog load ... type xdp pinmaps ...` and attaches it with `bpftool net attach xdp pinned ... dev katran0 overwrite`. |
| `katran.py` lines 476-488 | Runner starts real `katran_server_grpc` with `-intf=katran0`, `-map_path=<bpffs>/maps/root_array`, and `-prog_pos=2`. |
| Upstream `KatranLb::attachBpfProgs()` lines 917-926 | In shared mode, Katran opens the pinned root map and updates `rootMapPos` with the `balancer_ingress` program fd. |
| Upstream `xdp_root.c` lines 29-36 | `xdp_root` loops root array slots 0..2 and calls `bpf_tail_call(ctx, &root_array, i)`, then returns `XDP_PASS` only if no slot tail-call succeeds. |
| `katran.py` lines 106-115 and 900-901 | After startup, runner reattaches the current attached program id to `xdpgeneric`; in current shared mode that id is still `xdp_root`, not `balancer_ingress`. |

Counter evidence from the two runs:

```text
x86_kvm_corpus_20260507_025319_683029
prog 531 xdp_root          xdp       bytes_jited 176   baseline runs 327649 post runs 323215
prog 537 balancer_ingress  xdp       bytes_jited 13629 baseline runs 0      post runs 0
prog 539 healthcheck_encap sched_cls bytes_jited 541   baseline runs 1      post runs 1

x86_kvm_corpus_20260507_023000_475311
prog 531 xdp_root          xdp       bytes_jited 176   baseline runs 327066 post runs 323274
prog 537 balancer_ingress  xdp       bytes_jited 13629 baseline runs 0      post runs 0
prog 539 healthcheck_encap sched_cls bytes_jited 541   baseline runs 1      post runs 1
```

The workload in both runs completed with all HTTP requests successful. If `xdp_root` only returned `XDP_PASS`, the packet would enter the root namespace IP stack with destination `10.100.1.1`; that VIP is assigned to loopback in `katran-real`, not root. There is no intended plain Linux forwarding path from root namespace stack to the real namespace VIP service.

## Packet Flow

Expected successful flow:

```text
client0 -> rtcl0 -> router route VIP/32 via LB_IP
        -> rtlb0 -> katran0 XDP
        -> xdp_root
        -> bpf_tail_call(root_array[2])
        -> balancer_ingress
        -> vip_map match 10.100.1.1:8080/TCP
        -> ch_rings selects real id 1
        -> reals[1] = 10.200.0.2
        -> IPIP encap, Ethernet dst ROUTER_LB_MAC
        -> XDP_TX out katran0 back to router
        -> router forwards outer packet to real0
        -> real namespace ipip0 decapsulates
        -> HTTP server on lo 10.100.1.1:8080 replies
```

The traffic does not diverge from `balancer_ingress`; the measurement does. `balancer_ingress` is entered by a tail call from `xdp_root`, and the runner reads raw `run_cnt`/`run_time_ns` from `bpftool prog show` via `runner/libs/bpf_stats.py`. The x86 JIT tail-call path jumps to the callee program's `bpf_func + X86_TAIL_CALL_OFFSET`, not through a fresh top-level BPF program entry wrapper. The kernel stats update path increments stats for the program passed to the top-level enter/exit path, so `xdp_root` is the visible accounting point.

## Failed Hypotheses

### Hypothesis 1: HTTP load uses the wrong namespace or bypasses Katran

Rejected. `run_parallel_http_load()` executes inside `katran-client` and targets `VIP_IP=10.100.1.1`, `VIP_PORT=8080`. The topology route in `katran-router` sends `10.100.1.1/32` via `LB_IP=192.0.2.2` on `rtlb0`, whose peer is root `katran0`. `xdp_root` has hundreds of thousands of runs in both latest artifacts, so packets are entering the XDP hook on the LB interface.

### Hypothesis 2: VIP/reals maps are missing, so balancer cannot match

Rejected. `configure_katran_maps()` writes:

- `ctl_array[0] = ROUTER_LB_MAC`
- `vip_map[10.100.1.1:8080/TCP] = { flags=F_LRU_BYPASS, vip_num=0 }`
- `reals[1] = 10.200.0.2`
- every `ch_rings[0 * 65537 + ring_pos] = 1`

If these were absent, `balancer_ingress` would return `XDP_PASS` on VIP miss or `XDP_DROP` on real/ring failure, and the all-success HTTP workload would not be plausible.

### Hypothesis 3: `xdp_root` is attached but `root_array[2]` is empty

Unlikely for the same reason. Upstream Katran exits the attach path with an exception if it cannot register in `root_array`, and the app result is `status: ok`. Successful VIP HTTP also strongly implies the tail call is installed. Still, the next smoke should explicitly verify this operationally:

```bash
bpftool -j net show dev katran0
bpftool -j map dump pinned /sys/fs/bpf/bpf-benchmark-katran-*/maps/root_array
bpftool -j prog show
```

Do this as a one-off debug capture, not as extra informational fields in `result.json`.

## Root Cause

The root cause is measurement attribution in shared-root XDP mode, not traffic generation:

- Attach interface is correct: ingress traffic arrives on `katran0`.
- `balancer_ingress` is configured by real Katran startup, not by a fake loader.
- VIP and real maps are configured enough for the HTTP workload to complete.
- `balancer_ingress` is not the top-level attached program; it is a tail-call target in `root_array[2]`.
- Current raw BPF stats expose runs for the top-level `xdp_root` entry. They do not expose a useful per-program run count for the tail-call target.

This answers the candidate causes as:

| Candidate | Verdict |
| --- | --- |
| Wrong attach iface | No. Current top-level XDP attach is on `katran0`, the interface that receives VIP traffic. |
| `xdp_root` chain not configured | Unlikely. Source path and successful HTTP traffic imply slot 2 is populated, but a debug smoke should dump the map. |
| `xdp_root` passes everything without invoking `balancer_ingress` | No. That would not explain all-success VIP HTTP through this topology. |
| Reals/VIP not added | No. Runner writes the relevant maps and traffic succeeds. |
| Tail-call target not counted by per-program stats | Yes. This is the blocker for paper-grade per-program `balancer_ingress` rows. |

## Recommended Fix

Use upstream Katran standalone attach mode for corpus Katran measurements that need `balancer_ingress` as the directly measured program.

Concrete edits to `runner/libs/app_runners/katran.py`:

1. Add a `use_xdp_root: bool = False` or `attach_mode: Literal["standalone", "shared_root"] = "standalone"` parameter to `KatranRunner` and `KatranServerSession`.
2. In standalone mode, do not call `_install_root_xdp_program()`.
3. In standalone mode, omit `-map_path=...` and `-prog_pos=...` from the `katran_server_grpc` command. With empty `rootMapPath`, upstream `KatranLb` takes the `standalone_` branch and attaches `balancer_ingress` directly to `mainInterface`.
4. Keep the same topology and `run_parallel_http_load()`; it already sends real TCP traffic through the VIP path.
5. Keep `session.reattach_xdpgeneric()`, but after standalone startup it should reattach the `balancer_ingress` program id rather than `xdp_root`.
6. Refactor the detach-all-XDP-modes part of `_cleanup_root_xdp_install()` into a helper and call it during standalone cleanup too. After reattaching to `xdpgeneric`, relying only on Katran's destructor flags may leave a mode mismatch.
7. Optional but cleaner for the LB-only benchmark: pass `-hc_forwarding=false`, matching upstream helper scripts, so the healthcheck `sched_cls` program is not loaded for this traffic-only measurement.

Expected result after this change:

- `bpftool net show dev katran0` should show `balancer_ingress` as the attached XDP program.
- `apps/katran.json` should have nonzero `run_cnt_delta` / `run_time_ns_delta` for `balancer_ingress`.
- `xdp_root` should disappear from the live Katran program set in standalone mode.

This fix does not require `katran_goclient` or `katran_tester`. It still uses the real upstream `katran_server_grpc` to load and attach the BPF program. The existing direct map programming in the runner can continue to configure the single VIP and real.

## Alternatives

### Alternative 1: Keep shared-root mode and treat `xdp_root` as the accounting proxy

This is the smallest operational change: no code edits to attach mode, just interpret `xdp_root` as the top-level accounting point for the whole shared XDP chain. It preserves the upstream-recommended shared-root deployment model.

Tradeoff: it does not produce a paper-grade per-program row for `balancer_ingress`. It also makes the row name misleading because the optimized heavy program is `balancer_ingress`, while the measured counter row is `xdp_root`.

### Alternative 2: Keep shared-root startup, then reattach the app-loaded `balancer_ingress` id directly

After `katran_server_grpc` loads programs and registers slot 2, the runner could find `balancer_ingress` and call `reattach_xdp_program(katran0, balancer_id, target_mode="generic")`. This would keep most startup code unchanged while making the heavy program the top-level XDP hook for measurement.

Tradeoff: this is less app-native than standalone mode because the framework overrides the app's intended shared-root attachment after startup. Cleanup also becomes trickier because the root map still contains a stale slot and the app believes it registered in shared mode.

### Alternative 3: Use upstream control-plane tooling for map setup

Use `katran_goclient` against `katran_server_grpc` to add the VIP and real instead of direct `bpftool map update` packing. This would better match upstream control-plane behavior and reduce ABI packing risk in `configure_katran_maps()`.

Tradeoff: it does not solve the zero `balancer_ingress` counter while shared-root tail-call mode remains. It also adds gRPC/client build and startup dependencies. This is useful for control-plane fidelity, not for the run-count attribution bug.

### Alternative 4: Use `katran_tester` or `BPF_PROG_TEST_RUN`

This can directly execute `balancer_ingress` and produce nonzero counters for that program.

Tradeoff: it is not real TCP traffic through the app topology and does not satisfy the stated benchmark goal. It is useful as a unit/e2e correctness or static datapath smoke, not as the corpus workload fix.

## Smoke Test To Run After The Fix

Use the Makefile entrypoint only:

```bash
BPFREJIT_CORPUS_APPS=katran SAMPLES=1 make corpus
```

During a debug-only run, capture:

```bash
bpftool -j net show dev katran0
bpftool -j prog show
```

For standalone mode, expected evidence is:

- `katran0` XDP attached program id equals the `balancer_ingress` id.
- `balancer_ingress` has nonzero runs.
- HTTP workload remains all-success.

