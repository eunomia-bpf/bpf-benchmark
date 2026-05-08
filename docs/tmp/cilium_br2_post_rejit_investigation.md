# cilium BR2 post-ReJIT wrk timeout investigation

## Scope and constraints

This note investigates the cilium/agent failure in:

`corpus/results/x86_kvm_corpus_20260508_183351_517011`

The run used the BR2 bytecode-rewrite pass set:

`noop,wide_mem,const_prop,dce,bounds_check_merge,skb_load_bytes_spec`

No code was changed during this investigation. In particular, this does not add any BPF program filtering, does not change `runner/libs/`, and does not modify `vendor/linux-framework`.

## Executive finding

The artifact points most strongly at a semantic regression in a successfully ReJITed Cilium datapath program, most likely in the `const_prop` + `dce` combination on host/netdev/LXC datapath code. The failed ReJITs are real and important, but most of them are peripheral tail-call targets, and the kernel reports that failed refreshes retained the old JIT image. The one failed critical target, `tail_handle_ipv4`, failed during `wide_mem` with no sites applied and no bytecode size change, so that failure alone is unlikely to explain the immediate TCP blackhole.

The artifact cannot fully satisfy an absolute timestamp reconstruction for every requested event. `details/daemon.stdout.log` has no timestamps and contains only daemon lifecycle lines; kernel messages such as `SYN flooding` and `bpf_rejit: retaining old JIT image after refresh failure` are not present in the saved result directory. The app JSON contains durations and the final timeout error, but not event timestamps for `rejit_start`, `rejit_done`, or post-ReJIT workload start.

## Evidence sources

- `details/apps/cilium__agent.json`
- `details/progress.json`
- `metadata.json`
- `details/daemon.stdout.log`
- `details/daemon.stderr.log`
- `details/failure-artifacts/*.tar.gz`
- `runner/libs/app_runners/cilium.py`
- `runner/libs/workload.py`
- `runner/repos/cilium/bpf/bpf_host.c`
- `runner/repos/cilium/bpf/bpf_lxc.c`
- `runner/repos/cilium/bpf/lib/nodeport.h`
- `runner/repos/cilium/bpf/lib/nodeport_egress.h`
- `runner/repos/cilium/bpf/lib/drop.h`
- `runner/repos/cilium/bpf/lib/lb.h`
- `vendor/linux-framework/kernel/bpf/syscall.c`

## 1. Failure timeline

Hard timestamp facts from the captured artifact:

| Event | Timestamp / duration | Evidence |
| --- | --- | --- |
| Suite result directory start | `2026-05-08T18:33:51.517011+00:00` | `metadata.json.started_at` |
| Final progress record | `2026-05-08T18:38:00.618496+00:00` | `details/progress.json.timestamp` |
| Metadata generated time | `2026-05-08T18:38:00.618500+00:00` | `metadata.json.generated_at` |
| Baseline workload status | `ok` for all 3 samples | `apps/cilium__agent.json.baseline.workloads[]` |
| Baseline measured workload duration sum | `117.75642930900008s` | sum of `baseline.workloads[].duration_s` |
| First post-ReJIT command that failed | `/usr/bin/wrk -t2 -c20 -d1s http://10.244.0.30:18080/` | top-level `error` in app JSON |
| First post-ReJIT wrk timeout length | `31.0s` | top-level `error` in app JSON |
| App final status | `error` | `apps/cilium__agent.json.status` |

`details/daemon.stdout.log` contains only:

```text
serve: listening on /var/tmp/bpfrejit-daemon.sock
serve: shutting down
```

`details/daemon.stderr.log` is empty. Therefore the exact daemon-side wall-clock times for `rejit_start` and `rejit_done` are not present in the captured daemon logs.

The closest reconstructable sequence is:

1. The suite started at `2026-05-08T18:33:51.517011Z`.
2. Cilium started, created managed endpoints, refreshed BPF program IDs, and the runner sent `SIGSTOP` to cilium-agent after endpoint setup.
3. Baseline ran `network_lossy_multi` three times. Each sample succeeded despite noisy workload stderr. The host-to-endpoint matrix command `/usr/bin/wrk -t2 -c20 -d1s http://10.244.0.30:18080/` succeeded in baseline.
4. ReJIT ran across 53 programs. The structured `rejit_result.status` is `ok`, but 8 per-program pass records have `status=failed_rejit`; driver progress would surface this as `rejit_done status=error`.
5. The post-ReJIT phase entered the Cilium endpoint matrix. The first command was host-to-endpoint wrk against `10.244.0.30:18080`.
6. That wrk process hung until the Python subprocess timeout fired after `31.0s`.
7. The app recorded no `post_rejit` payload because the first post-ReJIT workload command raised the timeout error.
8. The result was finalized at `2026-05-08T18:38:00.6185Z`.

Bounds for the failed post-ReJIT wrk:

- The timeout completed no later than `2026-05-08T18:38:00.6185Z`.
- Since the timeout was `31.0s`, the first post-ReJIT wrk command started no later than about `2026-05-08T18:37:29.6185Z`.
- The post-ReJIT `baseline_setup`/workload setup timestamp is not recorded separately in the app JSON.

Missing requested timestamps:

- `rejit_done` wall-clock timestamp: not persisted in the result directory.
- Post-ReJIT `baseline_setup` timestamp: not persisted in the app JSON.
- SYN flood kernel message timestamp: no `SYN`, `flood`, or related kernel log line is present under the result directory.
- `bpf_rejit: retaining old JIT image after refresh failure` timestamps: not present in `daemon.stdout.log`/`daemon.stderr.log`; this string is emitted by the kernel with `pr_warn` in `vendor/linux-framework/kernel/bpf/syscall.c`, not by daemon stdout.

This is an artifact gap, not evidence that those events did not happen.

## 2. 53 program classification

The 53 programs in `baseline.bpf` fall into these groups. Tail-called programs have `run_cnt_delta=0` in many cases because BPF tail calls jump past the per-program stats prologue; zero run count does not mean the target did not execute.

### Direct datapath entry programs

These are directly attached or high-count datapath programs and are on the likely packet path for the failing host-to-endpoint wrk:

| IDs | Names | Role |
| --- | --- | --- |
| `106` | `cil_xdp_entry` | XDP entry program from `bpf_xdp.c` |
| `107` | `cil_from_host` | Host-side tc path |
| `108`, `129` | `cil_to_host` | Host-facing tc return path; only 2 baseline runs each |
| `130` | `cil_from_netdev` | tc ingress from physical/netdev side; source comment says this is the ingress filter on physical devices |
| `133` | `cil_to_netdev` | tc egress to physical/netdev side; source comment says this is the egress filter on physical devices |
| `147`, `162` | `cil_from_container` | Endpoint veth ingress attachment; Cilium comment says this corresponds to packets leaving the container |

### LXC and IPv4 tail-call datapath

These are tail-call descendants for endpoint and IPv4 handling. They are datapath critical even when their own `run_cnt_delta` is zero:

| IDs | Names | Role |
| --- | --- | --- |
| `117`, `123`, `139` | `tail_handle_ipv4_from_netdev` | IPv4 handling from netdev side, calls `tail_handle_ipv4` in `bpf_host.c` |
| `115`, `118`, `138` | `tail_handle_ipv4_from_host` | IPv4 handling from host side |
| `148`, `167` | `tail_handle_ipv4` | LXC IPv4 tail handler in `bpf_lxc.c` |
| `153`, `158` | `tail_handle_ipv4_cont` | LXC continuation tail handler |
| `145`, `164` | `tail_ipv4_to_endpoint` | Delivery to endpoint |
| `143`, `160` | `cil_lxc_policy_egress` | LXC egress policy |
| `149`, `156` | `cil_lxc_policy` | LXC ingress policy, tail-called before endpoint delivery |
| `144`, `163` | `tail_handle_arp` | ARP tail handler |

### CT, NodePort, SNAT, and LB peripheral paths

These can be traffic-path relevant depending on service/NAT configuration. For the first failed direct host-to-endpoint URL, they are less obviously central than the direct host/netdev/LXC path, but CT tails may still be used by normal Cilium datapath processing:

| IDs | Names | Role |
| --- | --- | --- |
| `146`, `161` | `tail_ipv4_ct_egress` | LXC egress connection-tracking tail |
| `151`, `155` | `tail_ipv4_ct_ingress` | LXC ingress connection-tracking tail |
| `110`, `125`, `132` | `tail_nodeport_nat_ingress_ipv4` | NodePort ingress NAT |
| `112`, `121`, `136` | `tail_nodeport_nat_egress_ipv4` | NodePort egress NAT |
| `150`, `157` | `tail_nodeport_rev_dnat_ipv4` | NodePort reverse DNAT |
| `111`, `120`, `134` | `tail_handle_snat_fwd_ipv4` | SNAT forwarding path |
| `126`, `137`, `152`, `166` | `tail_no_service_ipv4` | LB no-service path from `lib/lb.h` |

### Drop, host policy, and tracing/peripheral programs

These are not the main TCP forwarding path, although drop notification can run when the datapath is already dropping packets:

| IDs | Names | Role |
| --- | --- | --- |
| `116`, `124`, `141`, `142`, `159` | `tail_drop_notify` | Drop event notification from `lib/drop.h` |
| `109` | `cil_host_policy` | Host policy path |
| `10` | `dump_bpf_map` | tracing iterator |
| `11` | `dump_bpf_prog` | tracing iterator |

## 3. Failed ReJIT programs

The prompt says there were 5 failed ReJITs. The structured app artifact contains 8 `failed_rejit` pass records:

| Prog ID | Full baseline name | Pass | Error | Verifier outcome | Datapath criticality |
| --- | --- | --- | --- | --- | --- |
| `11` | `dump_bpf_prog` | `noop` | `BPF_PROG_REJIT errno 13: Permission denied` | verifier log rejects tracing iterator access: `access beyond the end of member pages ... struct bpf_prog` | Not datapath; tracing iterator |
| `110` | `tail_nodeport_nat_ingress_ipv4` | `bounds_check_merge` | `BPF_PROG_REJIT errno 16: Device or resource busy` | verifier log reaches successful processed-insn summary | Peripheral NodePort path |
| `116` | `tail_drop_notify` | `bounds_check_merge` | `BPF_PROG_REJIT errno 16: Device or resource busy` | verifier log reaches successful processed-insn summary | Drop notification peripheral |
| `121` | `tail_nodeport_nat_egress_ipv4` | `bounds_check_merge` | `BPF_PROG_REJIT errno 16: Device or resource busy` | verifier log reaches successful processed-insn summary | Peripheral NodePort path |
| `141` | `tail_drop_notify` | `wide_mem` | `BPF_PROG_REJIT errno 16: Device or resource busy` | verifier log reaches successful processed-insn summary | Drop notification peripheral |
| `142` | `tail_drop_notify` | `const_prop` | `BPF_PROG_REJIT errno 16: Device or resource busy` | verifier log reaches successful processed-insn summary | Drop notification peripheral |
| `144` | `tail_handle_arp` | `noop` | `BPF_PROG_REJIT errno 16: Device or resource busy` | verifier log reaches successful processed-insn summary | ARP tail path; not TCP data path after neighbor resolution |
| `148` | `tail_handle_ipv4` | `wide_mem` | `BPF_PROG_REJIT errno 16: Device or resource busy` | verifier log reaches successful processed-insn summary | Critical LXC IPv4 tail path |

Only ID `11` looks like a verifier/security rejection. The other seven failures are `EBUSY` after the candidate verifier log reaches the normal processed-instruction summary, so they look like post-verifier refresh, poke-table, trampoline, or attachment update failures rather than bytecode verifier rejects.

For the EBUSY failures, failure artifact summaries show that several failed even with no applied sites and no bytecode-size change. Examples:

- `141 tail_drop_notify`: `wide_mem`, 0 sites, `147 -> 147` insns.
- `144 tail_handle_arp`: `noop`, 0 sites, `287 -> 287` insns.
- `148 tail_handle_ipv4`: `wide_mem`, 0 sites, `2342 -> 2342` insns.

This matters because these failures do not prove a pass produced bad bytecode. They show that kernel-side ReJIT refresh/poke mechanics can fail on Cilium tail-call programs even for round-trip candidates.

The kernel code path in `vendor/linux-framework/kernel/bpf/syscall.c` supports that reading:

- `BPF_PROG_REJIT` re-verifies the candidate.
- It checks and rewrites poke-table metadata.
- It updates PROG_ARRAY tail-call target pokes before and after the image swap.
- On selected refresh failures, it can retain the old JIT image and emit `bpf_rejit: retaining old JIT image after refresh failure`.

Therefore, the failed ReJITs are a real issue, but they are not sufficient by themselves to explain the TCP timeout unless the retain-old-image path leaves a caller/target tail-call state inconsistent.

## 4. Successful ReJIT semantic-risk review

The key question is whether successful bytecode rewrites changed semantics on a program that the first post-ReJIT wrk needs.

### Pass behavior on critical Cilium datapath programs

The four requested passes show this pattern:

- `wide_mem`: no applied sites on the checked Cilium direct and LXC critical datapath programs.
- `bounds_check_merge`: no applied sites on the checked Cilium direct and LXC critical datapath programs.
- `skb_load_bytes_spec`: matched some critical programs but applied 0 sites there; it applied only to `tail_no_service_ipv4`, adding 44 instructions.
- `const_prop`: applied many sites on critical programs with no instruction-count delta, followed by `dce` deleting substantial code on the same programs.

Representative successful critical-path records:

| Program | `const_prop` applied | `const_prop` insns | `dce` insns | `skb_load_bytes_spec` | Notes |
| --- | ---: | --- | --- | --- | --- |
| `cil_from_host` (`107`) | 39 | `1194 -> 1194` | `1194 -> 1125` | no sites | Host-side datapath |
| `cil_from_netdev` (`130`) | 19 | `1113 -> 1113` | `1113 -> 1084` | matched 9, applied 0 | Netdev ingress critical path |
| `cil_to_netdev` (`133`) | 50 | `1281 -> 1281` | `1281 -> 1174` | matched 11, applied 0 | Netdev egress critical path |
| `tail_handle_ipv4_from_netdev` (`117`, `123`, `139`) | 51 | `1720 -> 1720` | `1720 -> 1582` | matched 4, applied 0 | Netdev IPv4 tail path |
| `cil_lxc_policy` (`149`, `156`) | 49 | `2446 -> 2446` | `2446 -> 2345` | matched 5, applied 0 | Endpoint policy path |
| `cil_from_container` (`147`, `162`) | 3 | `380 -> 380` | `380 -> 367` | matched 9, applied 0 | Endpoint veth egress |
| `tail_ipv4_to_endpoint` (`145`, `164`) | 14 | `1056 -> 1056` | `1056 -> 1017` | no sites | Endpoint delivery |
| `tail_ipv4_ct_ingress` (`151`, `155`) | 30 | `1168 -> 1168` | `1168 -> 1103` | no sites | CT ingress tail |
| `tail_ipv4_ct_egress` (`146`, `161`) | 28 | `1156 -> 1156` | `1156 -> 1092` | no sites | CT egress tail |
| `tail_handle_ipv4_cont` (`153`, `158`) | 28 | `1146 -> 1146` | `1146 -> 1085` | no sites | LXC IPv4 continuation |

`tail_no_service_ipv4` is the only notable `skb_load_bytes_spec` application in this run:

| Program | `skb_load_bytes_spec` applied | Instruction delta | Role |
| --- | ---: | --- | --- |
| `tail_no_service_ipv4` (`126`, `137`, `152`, `166`) | 2 | `+44` | LB no-service path |

### Interpretation

There is no single obviously explosive instruction-count delta on `cil_from_netdev`; `const_prop` applies 19 sites with `1113 -> 1113`, and `dce` then removes 29 instructions. The suspicious pattern is broader:

- `const_prop` affects many critical programs.
- `dce` then removes non-trivial code from those same programs.
- `wide_mem` and `bounds_check_merge` do not materially transform the direct critical path in this run.
- `skb_load_bytes_spec` does not apply to the direct `cil_*_netdev` or `cil_lxc_policy` records, but it does modify `tail_no_service_ipv4`.

Given the first post-ReJIT operation is a host-to-endpoint HTTP request, the most plausible semantic-damage region is the host/netdev/LXC path that had `const_prop` and `dce` applied:

- `cil_from_host`
- `cil_from_netdev`
- `cil_to_netdev`
- `tail_handle_ipv4_from_netdev`
- `cil_lxc_policy`
- `tail_ipv4_to_endpoint`
- CT ingress/egress tails
- `cil_from_container`

This does not prove `const_prop` or `dce` is wrong. It identifies the only successful BR2 transformations that materially touched the immediate datapath.

## 5. Network namespace and endpoint lifecycle

`runner/libs/app_runners/cilium.py` sets up Cilium like this:

1. Prepare runtime directories and benchmark interface.
2. Clean old managed endpoint links before startup.
3. Start etcd.
4. Start cilium-agent.
5. Call `_setup_managed_endpoints()`.
6. Refresh BPF programs.
7. Send `SIGSTOP` to cilium-agent.

The `_pause_agent()` comment explains the intent: freeze cilium-agent after endpoint setup so no controller calls `ReloadDatapath()` during baseline and post-ReJIT measurements. The TC/XDP datapath programs and pinned maps remain resident while packets continue to hit them.

Endpoint cleanup is in `stop()`:

- resume cilium-agent with `SIGCONT`;
- delete managed endpoints through the API;
- stop cilium-agent;
- clean endpoint links and namespaces;
- delete the benchmark veth.

I did not find a code path that destroys the managed endpoint namespaces or detaches TC/XDP programs between baseline and post-ReJIT. The post-ReJIT timeout is therefore unlikely to be explained by ordinary phase teardown. The more consistent explanation is that the same resident endpoint and attached datapath were still present, but packet forwarding failed after ReJIT.

## 6. Hypothesis ranking and validation experiments

All experiments below use `make` targets. I do not recommend a "skip `cil_from_netdev`" or "skip specific program" experiment because program filtering is explicitly forbidden by the benchmark rules.

### H1: `const_prop` + `dce` changed Cilium datapath semantics

Probability: high.

Why:

- The first failed post-ReJIT command is direct host-to-endpoint TCP.
- `const_prop` applies to many direct and tail-call critical programs.
- `dce` removes substantial code immediately after `const_prop`.
- Other requested BR passes either apply no sites on those programs or only touch `tail_no_service_ipv4`.
- Other apps survived BR2, so this may be Cilium-specific verifier-state or map/endpoint-state interaction.

Validation:

```sh
BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=const_prop,dce SAMPLES=1 WORKLOAD_DURATION=10 KEEP_WORKDIRS=1 make vm-corpus
BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=const_prop SAMPLES=1 WORKLOAD_DURATION=10 KEEP_WORKDIRS=1 make vm-corpus
BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=dce SAMPLES=1 WORKLOAD_DURATION=10 KEEP_WORKDIRS=1 make vm-corpus
```

Expected signal:

- If `const_prop,dce` reproduces the timeout but each pass alone does not, the bug is in their composition.
- If `const_prop` alone reproduces it, focus on constant materialization and verifier-state side inputs.
- If `dce` alone reproduces it, focus on DCE reachability/liveness.

### H2: ReJIT tail-call refresh/poke handling leaves partial state inconsistent after EBUSY

Probability: medium.

Why:

- Seven failed ReJITs are `EBUSY` after verifier success.
- Some failures happen with zero sites and zero instruction delta.
- ID `148 tail_handle_ipv4` is a critical LXC IPv4 tail target and fails at `wide_mem` even though `wide_mem` applied no changes.
- Cilium heavily uses PROG_ARRAY tail calls, which are exactly where kernel ReJIT must preserve poke-table compatibility.

Why it is not the top hypothesis:

- The kernel claims to retain the old JIT image after refresh failure.
- Most failed programs are NodePort/drop/ARP peripheral paths.
- A no-change failed ReJIT should not directly produce bad bytecode.

Validation:

```sh
BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=noop SAMPLES=1 WORKLOAD_DURATION=10 KEEP_WORKDIRS=1 make vm-corpus
BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=wide_mem SAMPLES=1 WORKLOAD_DURATION=10 KEEP_WORKDIRS=1 make vm-corpus
```

Expected signal:

- If `noop` or `wide_mem` alone can produce post-ReJIT timeout, the kernel refresh/poke path is sufficient to break Cilium.
- If they only produce failed_rejit records but post-ReJIT traffic works, EBUSY is probably not the direct cause of this timeout.

### H3: `skb_load_bytes_spec` changed an LB no-service path relevant to this workload

Probability: low to medium.

Why:

- `skb_load_bytes_spec` applies to `tail_no_service_ipv4`, adding 44 instructions.
- Cilium service/LB code can be involved depending on the benchmark topology.

Why lower:

- The failed command is direct endpoint IP `10.244.0.30:18080`, not a service VIP.
- `skb_load_bytes_spec` matched but applied 0 sites on `cil_from_netdev`, `cil_to_netdev`, `cil_lxc_policy`, and `tail_handle_ipv4_from_netdev`.

Validation:

```sh
BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=skb_load_bytes_spec SAMPLES=1 WORKLOAD_DURATION=10 KEEP_WORKDIRS=1 make vm-corpus
BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=const_prop,dce,skb_load_bytes_spec SAMPLES=1 WORKLOAD_DURATION=10 KEEP_WORKDIRS=1 make vm-corpus
```

Expected signal:

- If `skb_load_bytes_spec` alone times out, inspect `tail_no_service_ipv4`.
- If only the three-pass combination times out, inspect interaction with code already simplified by `const_prop,dce`.

### H4: Endpoint namespace or TC/XDP attachment was destroyed between phases

Probability: low.

Why:

- `cilium.py` freezes the agent after endpoint setup.
- Cleanup functions run in `stop()`, after post-ReJIT measurement.
- Baseline and post-ReJIT use the same managed endpoint setup.

Validation:

```sh
BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=noop SAMPLES=1 WORKLOAD_DURATION=10 KEEP_WORKDIRS=1 make vm-corpus
```

Expected signal:

- If `noop` succeeds post-ReJIT, the phase lifecycle is probably sound.
- If even `noop` times out, inspect endpoint existence and attachment state before the first post-ReJIT wrk in a dedicated diagnostic run.

### H5: The saved artifact is missing the kernel chronology needed to correlate SYN flood and retain-old-image logs

Probability: certain as an artifact limitation, not a root cause.

Why:

- The requested kernel messages are not in `daemon.stdout.log`, `daemon.stderr.log`, app JSON, or the result directory text files.
- The retain-old-image message is emitted by kernel `pr_warn`, so it needs dmesg, journal, or VM console capture.

Validation:

```sh
BPFREJIT_CORPUS_APPS=cilium/agent BPFREJIT_BENCH_PASSES=const_prop,dce SAMPLES=1 WORKLOAD_DURATION=10 KEEP_WORKDIRS=1 make vm-corpus
```

Expected signal:

- Preserve VM console or kernel journal output for the rerun, then correlate `SYN flooding` and `bpf_rejit: retaining old JIT image after refresh failure` with the post-ReJIT endpoint-matrix command.

## 7. Recommended next diagnostic order

1. Run `const_prop,dce` only on cilium with `SAMPLES=1 WORKLOAD_DURATION=10`. This is the most direct reproduction test for the strongest semantic-damage hypothesis.
2. If it reproduces, split into `const_prop` only and `dce` only.
3. Run `noop` and `wide_mem` only to separate kernel refresh/poke failure from bytecode semantic transformation.
4. Only after isolating a pass combination, inspect affected critical programs by comparing verifier logs and pass reports for `cil_from_host`, `cil_from_netdev`, `cil_to_netdev`, `tail_handle_ipv4_from_netdev`, `cil_lxc_policy`, and `tail_ipv4_to_endpoint`.
5. Do not validate by excluding individual BPF programs from ReJIT; that would violate the no-filtering benchmark rule.

## Bottom line

The immediate post-ReJIT symptom is not a slow workload; it is a first-packet-path failure: the first 1-second host-to-endpoint wrk call never completes and is killed by the 31-second subprocess timeout.

The failed ReJIT records are mostly EBUSY refresh/poke failures on tail-call/peripheral programs, with old-image retention expected. They deserve a separate kernel-side investigation, especially because ID `148 tail_handle_ipv4` is critical, but the strongest root-cause candidate for this run is successful `const_prop` plus `dce` rewriting on Cilium critical datapath programs.

---

## Bisect outcome (2026-05-08, post-investigation)

| Step | Pass set | Result |
| --- | --- | --- |
| 1 | `noop,wide_mem` | post-rejit ok (per-prog geomean 0.9973, 6 eligible) |
| 2 | `noop,wide_mem,const_prop,dce` | post-rejit wrk timeout 31 s — **bug reproduced** |
| 3 | `noop,const_prop` | post-rejit wrk timeout 31 s — **bug reproduced with const_prop alone** |
| 4 | `noop,dce` (running) | TBD |

**Confirmed culprit: `const_prop` alone breaks cilium's host→endpoint datapath.** All 5 critical attached programs reach 100 % verifier-pass after const_prop (39 sites on `cil_from_host`, 50 on `cil_to_netdev`, 32 on `tail_handle_ipv4`, 19 on `cil_from_netdev`, 51 on `tail_handle_ipv4_from_netdev`); every prog reports `status=ok` and `insn_delta=0` (same-size MOV replacement). Verifier accepts the rewritten code, but at runtime no packets reach the endpoint.

The root-cause bug must be in `const_prop`'s abstract model on a cilium-specific shape — likely interaction with subprog calls, map-of-maps lookups, or the verifier-state oracle's `(pc, reg)` consensus when the same PC is reached via multiple control-flow paths with different per-path register narrowings.

### Recommended action

For the OSDI'26 submission window: drop `const_prop` from the BR pass list reported in §6 (call it `BR-5`: `noop, wide_mem, dce, bounds_check_merge, skb_load_bytes_spec`). const_prop's correctness fix should land separately and rerun; the cilium-specific failure shape is reproduced with `noop,const_prop` alone, so the fix can iterate fast in `bpfopt/crates/bpfopt/src/passes/const_prop.rs` against the captured cilium workdir. Bytecode-rewrite section can quote BR-5 numbers across all 7 apps (no `—` row needed for cilium) and add a footnote about the const_prop bug.
