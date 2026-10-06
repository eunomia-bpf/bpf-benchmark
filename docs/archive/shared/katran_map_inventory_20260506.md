# Katran Map Inventory for `map_inline`

Date: 2026-05-06  
Primary artifact: `corpus/results/x86_kvm_corpus_20260507_023000_475311/details/apps/katran.json`  
Scope: `balancer_ingress`, `healthcheck_encap`, and `xdp_root`.

## Inputs

Read first, per request:

- `docs/kernel-jit-optimization-plan.md`
- `CLAUDE.md`
- `docs/tmp/map_inline_hit_rate_root_cause_20260506.md`

Source/audit inputs:

- BPF sources: `runner/repos/katran/katran/lib/bpf/balancer.bpf.c`, `healthchecking_ipip.c`, `xdp_root.c`, `balancer_maps.h`, `control_data_maps.h`, `balancer_consts.h`, `balancer_structs.h`, `balancer_helpers.h`
- Userspace population: `runner/repos/katran/katran/lib/KatranLb.cpp`, `KatranLb.h`, `KatranLbStructs.h`, `Vip.cpp`
- Benchmark population: `runner/libs/app_runners/katran.py`
- Compiled map order/sizes: `corpus/build/katran/balancer.bpf.o`, `healthchecking_ipip.bpf.o`, `xdp_root.bpf.o`
- R1 diagnostics: `corpus/results/x86_kvm_corpus_20260507_023000_475311/details/daemon.stderr.log` and `details/apps/katran.json`

## Important Context

The BPF source defaults are `MAX_VIPS=512`, `MAX_REALS=4096`, `RING_SIZE=65537`, and `CH_RINGS_SIZE = MAX_VIPS * RING_SIZE` (`balancer_consts.h:48-60`, `balancer_consts.h:95`). `KatranConfig` has the same default `maxVips=512`, `maxReals=4096`, and `chRingSize=65537` (`KatranLbStructs.h:31-35`, `KatranLbStructs.h:187-203`). The user's production premise is larger than this default: 1000+ VIPs and many reals. That implies production either raises the compile-time/default caps or shards across instances; the conclusions below scale linearly with VIP count.

The benchmark runner explicitly configures one VIP, one real, and one full VIP ring: it writes `vip_map`, `reals`, every `ch_rings` position for `VIP_NUM=0`, and `ctl_array[0]` (`katran.py:32-36`, `katran.py:609-628`). It sets `F_LRU_BYPASS`, so the LRU datapath is mostly avoided for the benchmark VIP (`katran.py:32-36`, `katran.py:617-623`).

Array maps are important: even when semantic population is small, `bpftool map dump` emits all array slots. That is why maps like `ch_rings`, `server_id_map`, and `reals` trip the JSON snapshot cap in R1.

## Map Inventory

`est size` is the requested `(key_size + value_size) * max_entries` declaration estimate, not bpftool JSON size and not per-CPU-expanded storage. For per-CPU maps, R1 JSON dump size is much larger than this estimate.

| map name | declared in | type | key_size | value_size | max_entries | est size | exceeds 64KB? 256KB? 1MB? | typical entry count in our benchmark | typical entry count in production | mutability | used by program(s) | how `map_inline` could help |
|---|---|---:|---:|---:|---:|---:|---|---|---|---|---|---|
| `root_array` | `xdp_root.c:22` | `PROG_ARRAY` | 4 | 4 | 3 | 24 B | no / no / no | 1 Katran tail-call slot in the root chain | 1 Katran slot, possibly other root programs up to 3 | M-in-M/control-plane program dispatch | `xdp_root` tail-calls it at `xdp_root.c:30-35` | Not a data map; not a `map_inline` candidate. |
| `stats` | `balancer_maps.h:110` | `PERCPU_ARRAY` | 4 | 16 | 1024 | 20,480 B | no / no / no | array dump emits 1024 slots; packet counters are mutated during workload | per-VIP plus generic counters, hot on every packet | M, per-cpu | many `balancer_ingress` counter paths, e.g. `balancer.bpf.c:41-42`, `balancer.bpf.c:1100-1129` | Should not inline. Values are counters updated by BPF. R1 skipped by size because per-CPU JSON was 2,818,916 B. |
| `ctl_array` | `control_data_maps.h:35` | `ARRAY` | 4 | 8 | 16 | 192 B | no / no / no | key 0 default-router MAC written by runner/server | read-mostly config; MAC/introspection keys can change via control plane | R2 | `balancer_ingress` at `balancer.bpf.c:1033`; introspection helper at `balancer_helpers.h:54-57` if enabled | Good candidate for constant-key reads. Stale MAC after `changeMac()` is a correctness risk (`KatranLb.cpp:962-977`). |
| `vip_map` | `balancer_maps.h:31` | `HASH` | 20 | 8 | 512 | 14,336 B | no / no / no | 1 VIP entry | 1000+ VIPs by user premise; default build cap is 512 unless raised | R2 | `balancer_ingress` at `balancer.bpf.c:787` and `balancer.bpf.c:790`; inline-decap stats path at `balancer.bpf.c:420` when enabled | Semantically attractive but current verifier-only `map_inline` cannot prove packet-derived VIP keys. Staleness risk on add/del/modify (`KatranLb.cpp:1019-1044`, `KatranLb.cpp:1087-1106`, `KatranLb.cpp:1153-1173`). |
| `fallback_cache` | `balancer_maps.h:40` | `LRU_HASH` | 40 | 16 | 1000 | 56,000 B | no / no / no | typically 0 due `F_LRU_BYPASS`; fallback only if no per-core LRU | runtime connection table fallback; should be rare if `lru_mapping` is populated | M | fallback pointer used after `lru_mapping` miss at `balancer.bpf.c:839-843` | Not a candidate. Hot runtime flow state, updated by BPF (`balancer.bpf.c:172`, `balancer.bpf.c:185-198`). |
| `lru_mapping` | `balancer_maps.h:49` | `ARRAY_OF_MAPS` | 4 | 4 | 128 | 1,024 B outer | no / no / no | 0 outer entries in current runner config; dump was empty | one outer entry per forwarding core; inner LRUs total default `LruSize=8,000,000` across cores (`KatranLb.cpp:473-537`) | M-in-M | `balancer_ingress` at `balancer.bpf.c:839`; R1 PCs 562 and 814 | Blocked by map-in-map and runtime CPU key (`bpf_get_smp_processor_id`). Also points to hot mutable flow LRUs. |
| `ch_rings` | `balancer_maps.h:66` | `ARRAY` | 4 | 4 | 33,554,944 | 268,439,552 B | yes / yes / yes | semantic: 65,537 entries for one VIP; bpftool array dump emits all 33,554,944 slots | about VIPs * 65,537 ring slots; 1000 VIPs implies about 65.5M slots if cap raised/sharded | R2 | hot CH lookup at `balancer.bpf.c:143-147`; repeated in another path in disassembly | A hot lookup, but key is `RING_SIZE * vip_num + hash(packet)`. Cap is severe, key is runtime-derived, and real changes rewrite ring deltas (`KatranLb.cpp:1286-1310`, `Vip.cpp:43-59`). Not unlocked by Prong A+B alone. |
| `reals` | `balancer_maps.h:75` | `ARRAY` | 4 | 20 | 4096 | 98,304 B | yes / no / no | semantic: 1 real at key 1; bpftool array dump emits all 4096 slots | many real IDs, up to default 4096 | R2 | hot real lookup at `balancer.bpf.c:159`, LRU path at `balancer.bpf.c:198`, QUIC/server-id paths at `balancer.bpf.c:540`, `balancer.bpf.c:898` | Good only if real ID is proven constant. In the hot CH path, the key comes from `ch_rings` or LRU/server_id state, so Prong A+B alone is insufficient. |
| `reals_stats` | `balancer_maps.h:84` | `PERCPU_ARRAY` | 4 | 16 | 4096 | 81,920 B | yes / no / no | array dump emits 4096 per-CPU slots; benchmark mutates real 1 stats | one counter slot per real; hot per-packet | M, per-cpu | `balancer_ingress` at `balancer.bpf.c:1047` | Not a candidate; hot BPF counter writes. R1 skipped by size with 11,275,330 B JSON. |
| `lru_miss_stats` | `balancer_maps.h:93` | `PERCPU_ARRAY` | 4 | 4 | 4096 | 32,768 B | no / no / no | normally mostly zero; reset across all keys by `logVipLruMissStats()` | diagnostic map; updated on LRU miss for selected VIP | M, per-cpu | `balancer_ingress` at `balancer.bpf.c:603`; compiled also has PCs after `vip_miss_stats` | Not a candidate; BPF increments it and userspace resets all keys (`KatranLb.cpp:1884-1923`). R1 skipped by size with 4,852,652 B JSON. |
| `vip_miss_stats` | `balancer_maps.h:102` | `ARRAY` | 4 | 20 | 1 | 24 B | no / no / no | one entry initialized to zero at load (`KatranLb.cpp:848-858`) | one selected VIP for LRU-miss diagnostics | M/R2 | `balancer_ingress` at `balancer.bpf.c:587-588`; R1 PCs 1351 and 2062 | Key is constant 0, but value is diagnostic state and BPF writes into the map value on the miss path (`balancer.bpf.c:599-607`). Do not inline. |
| `quic_stats_map` | `balancer_maps.h:119` | `PERCPU_ARRAY` | 4 | 104 | 1 | 108 B | no / no / no | one per-CPU entry, usually not exercised by TCP benchmark | one hot QUIC stats slot | M, per-cpu | `balancer_ingress` at `balancer.bpf.c:874-876`; R1 PCs 863 and 895 | Key is constant 0 but value is hot counter state. Do not inline. R1 dumped it under cap. |
| `server_id_map` | `balancer_maps.h:157` | `ARRAY` | 4 | 4 | 16,777,214 | 134,217,712 B | yes / yes / yes | 0 semantic entries in TCP benchmark, but array dump emits all slots | many QUIC/TCP server IDs; up to 24-bit default array space | R2 | QUIC/TCP server-id lookup at `balancer.bpf.c:534`, `balancer.bpf.c:886` | Potentially useful for known server IDs, but keys come from packet connection IDs/options and the map is huge. R1 skipped by size with 1,918,268,502 B JSON. Updates/invalidation occur at `KatranLb.cpp:1727-1803`, `KatranLb.cpp:3269-3312`. |
| `server_id_stats` | `balancer_maps.h:222` | `PERCPU_ARRAY` | 4 | 16 | 512 | 10,240 B | no / no / no | per-CPU array emitted; likely not hot in TCP benchmark | per-VIP server-id routing counters | M, per-cpu | `balancer_ingress` server-id stats at `balancer.bpf.c:640-641` | Not a candidate; BPF counter writes. R1 skipped by size with 1,408,916 B JSON. |
| `vip_to_down_reals_map` | `balancer_maps.h:230` | `HASH_OF_MAPS` | 20 | 4 | 512 | 12,288 B outer | no / no / no | empty in benchmark | one outer entry per VIP with down reals; inner entries are down real IDs | M-in-M/R2 | UDP flow migration path at `balancer.bpf.c:661-664`; R1 PCs 1072 and 1776 | Blocked by map-in-map chain. Also runtime health/control-plane state (`KatranLb.cpp:3315-3399`, `KatranLb.cpp:3461-3543`). |
| `hc_stats_map` | `healthchecking_ipip.c:80` | `PERCPU_ARRAY` | 4 | 40 | 1 | 44 B | no / no / no | one per-CPU stats entry | hot healthcheck counters | M, per-cpu | `healthcheck_encap` at `healthchecking_ipip.c:99-103`; R1 PC 17 | Key is constant 0 but value is hot counter state. Do not inline. |
| `hc_reals_map` | `healthchecking_ipip.c:73` | `HASH` | 4 | 20 | 4096 | 98,304 B | yes / no / no | likely 0 entries in this runner; R1 dump was tiny | healthcheck marks to real destinations, many possible marks up to maxReals | R2 | `healthcheck_encap` at `healthchecking_ipip.c:94`, `healthchecking_ipip.c:112`; R1 PC 32 | Key is `skb->mark`, runtime packet metadata. Not verifier-constant; add/delete via `KatranLb.cpp:2321-2387`. |
| `hc_ctrl_map` | `healthchecking_ipip.c:66` | `ARRAY` | 4 | 4 | 4 | 32 B | no / no / no | array dump emits 4 slots; server may write tunnel/main ifindexes | read-mostly interface config | R2 | `healthcheck_encap` at `healthchecking_ipip.c:126` and `healthchecking_ipip.c:134`; R1 PCs 56 and 68 | Good candidate for constant-key ifindex reads. Stale ifindex after reconfiguration is a correctness risk. |

## R1 `skip_size` Maps

R1 did not persist Katran `bpftool map show` JSON. The name mapping below is inferred from the compiled `.maps` BTF order in `balancer.bpf.o`, the R1 map type, and the dump sizes. The seven `skip_size` decisions are in `daemon.stderr.log:4074-4087`.

| R1 map id | inferred map | type | R1 JSON dump size | why it exceeded the 64KB cap |
|---:|---|---|---:|---|
| 3559 | `stats` | `PERCPU_ARRAY` | 2,818,916 B | per-CPU JSON expansion of 1024 counter slots |
| 3564 | `ch_rings` | `ARRAY` | 3,847,707,452 B | `bpftool` dumps all 33,554,944 array slots |
| 3565 | `reals` | `ARRAY` | 1,080,250 B | `bpftool` dumps all 4096 array slots, not only the one benchmark real |
| 3566 | `reals_stats` | `PERCPU_ARRAY` | 11,275,330 B | per-CPU JSON expansion of 4096 real counter slots |
| 3567 | `lru_miss_stats` | `PERCPU_ARRAY` | 4,852,652 B | per-CPU JSON expansion of 4096 slots |
| 3572 | `server_id_map` | `ARRAY` | 1,918,268,502 B | `bpftool` dumps the full 16,777,214-entry array |
| 3574 | `server_id_stats` | `PERCPU_ARRAY` | 1,408,916 B | per-CPU JSON expansion of 512 VIP stat slots |

Raising the cap alone is not enough for Katran: `ch_rings`, `server_id_map`, and all large per-CPU counter maps remain far above 1 MiB in R1 JSON form. `reals` is also just above 1 MiB as JSON even though its declared binary estimate is only 98,304 B.

## Hot-Path Triple

### 1. `vip_map[vip_key] -> vip_meta`

Source: `balancer.bpf.c:787` and fallback zero-port lookup at `balancer.bpf.c:790`.

Key value: packet-derived VIP tuple: destination IP, destination port, and protocol. In the benchmark traffic this is always `10.100.1.1:8080/TCP`, but the verifier does not know packet bytes. In production it is traffic-dependent and spans 1000+ VIPs by the user's premise.

Entry count: benchmark 1 semantic entry; production 1000+ semantic VIPs if caps are raised or sharded.

Could `map_inline` help after Prong A+B? It would be a meaningful lookup to specialize if a separate runtime/profile specialization proved a dominant VIP key. Prong B verifier-state reconstruction alone does not make packet bytes constant, and Prong A is irrelevant because `vip_map` is under the cap. So this is not unlocked by Prong A+B alone under the current verifier-constant model.

### 2. `ch_rings[(vip_num * RING_SIZE) + (hash % RING_SIZE)] -> real_id`

Source: hash/key construction and lookup at `balancer.bpf.c:143-147`; userspace programs ring deltas at `KatranLb.cpp:1286-1310`; `Vip.cpp:43-59` computes the ring.

Key value: `vip_num` is config-derived from `vip_map`, but `hash` is packet-derived. In the benchmark, all 65,537 positions for VIP 0 point to real 1 (`katran.py:620-623`). In production, each VIP has a full 65,537-position ring, generally with many distinct real IDs.

Entry count: benchmark 65,537 semantic entries for one VIP, but array dump emits 33,554,944 default slots. Production is roughly `VIPs * 65,537`; 1000 VIPs implies about 65.5M ring positions.

Could `map_inline` help after Prong A+B? Not realistically. This is a hot lookup, but it is both cap-blocked and runtime-keyed. The benchmark's "all positions map to 1" fact is a map-content invariant, not a verifier-known key. A future segment-uniform/range specialization could exploit it for the benchmark, but that is beyond Prong A+B.

### 3. `reals[real_id] -> real_definition`

Source: CH result lookup at `balancer.bpf.c:159`; LRU result lookup at `balancer.bpf.c:198`; server-id result lookups at `balancer.bpf.c:540` and `balancer.bpf.c:898`.

Key value: from `ch_rings`, LRU flow state, or `server_id_map`. In the benchmark CH path it is semantically always real 1, but the verifier cannot know that unless the prior CH lookup is itself specialized. In production it is one of many real IDs and changes as reals are added/deleted or flags change.

Entry count: benchmark 1 semantic real; production many, up to default 4096 unless raised.

Could `map_inline` help after Prong A+B? It can be a good second-stage candidate only if the real ID is already proven constant. Prong A could make `reals` dumpable if snapshot handling avoids the 1 MiB JSON problem, and Prong B can recover constant stack keys, but neither proves the CH/LRU/server-id result constant.

## Lookup-Site Verdict

### `balancer_ingress` R1 matched sites

R1 summary for `balancer_ingress`: `matched=14`, `applied=0`, `skipped=14`, `maps_skipped_by_size=7`; diagnostics are in `apps/katran.json` under program id 537. PCs below come from that R1 report and map names from `llvm-objdump -dr` relocations of `balancer.bpf.o`.

| PC | map | source | key at lookup time | R1 reason | Prong B alone? | Prong A+B? | verdict |
|---:|---|---|---|---|---|---|---|
| 512 | `vip_map` | `balancer.bpf.c:787` | packet-derived VIP tuple | no verifier-guided key | no: reconstructed state still has packet-derived bytes | no: cap is not the blocker | Not realistically inlineable under verifier-constant `map_inline`. |
| 520 | `vip_map` | `balancer.bpf.c:790` | packet-derived VIP tuple with port zero fallback | no verifier-guided key | no | no | Same as PC 512. |
| 562 | `lru_mapping` | `balancer.bpf.c:839` | CPU id from helper | map-in-map chain not inlineable | no | no | M-in-M plus runtime CPU key and hot LRU state. |
| 762 | `vip_map` | `balancer.bpf.c:787` | packet-derived VIP tuple | no verifier-guided key | no | no | Same as PC 512 on another parse path. |
| 770 | `vip_map` | `balancer.bpf.c:790` | packet-derived fallback key | no verifier-guided key | no | no | Same as PC 520 on another parse path. |
| 814 | `lru_mapping` | `balancer.bpf.c:839` | CPU id from helper | map-in-map chain not inlineable | no | no | Same as PC 562. |
| 863 | `quic_stats_map` | `balancer.bpf.c:874-876` | constant 0 | no verifier-guided key | mechanically yes after state reconstruction, but should be vetoed | no | Mutable per-CPU counters; do not inline. |
| 895 | `quic_stats_map` | `balancer.bpf.c:874-876` | constant 0 | no verifier-guided key | mechanically yes, but should be vetoed | no | Same as PC 863. |
| 1072 | `vip_to_down_reals_map` | `balancer.bpf.c:661-664` | packet-derived VIP tuple, then real ID | map-in-map outer key unavailable | no | no | M-in-M plus runtime key and mutable health/control state. |
| 1105 | `ctl_array` | `balancer.bpf.c:1033` | constant key 0, default-router MAC | no verifier-guided key | yes | yes | Realistic R2 candidate. Needs stale-config discipline. |
| 1351 | `vip_miss_stats` | `balancer.bpf.c:587-603` | constant key 0 | no verifier-guided key | mechanically yes, but should be vetoed | no | Diagnostic map mutated by BPF/userspace; do not inline. |
| 1776 | `vip_to_down_reals_map` | `balancer.bpf.c:661-664` | packet-derived VIP tuple, then real ID | map-in-map outer key unavailable | no | no | Same as PC 1072 on another path. |
| 1807 | `ctl_array` | `balancer.bpf.c:1033` | constant key 0, default-router MAC | no verifier-guided key | yes | yes | Realistic R2 candidate. |
| 2062 | `vip_miss_stats` | `balancer.bpf.c:587-603` | constant key 0 | no verifier-guided key | mechanically yes, but should be vetoed | no | Same as PC 1351. |

Rough rank after both fixes: 2 of 14 are high-confidence realistic candidates (`ctl_array` at PCs 1105 and 1807). Four `vip_map` sites are semantically interesting for a fixed benchmark VIP but not unlockable by Prong A+B alone. The rest remain blocked by map-in-map, mutability, or runtime keys.

### `healthcheck_encap` R1 matched sites

R1 summary for `healthcheck_encap`: `matched=4`, `applied=0`, `skipped=4`; all were "lookup key is not available from verifier-guided state".

| PC | map | source | key at lookup time | Prong B alone? | Prong A+B? | verdict |
|---:|---|---|---|---|---|---|
| 17 | `hc_stats_map` | `healthchecking_ipip.c:99-103` | constant 0 | mechanically yes, but should be vetoed | no | Mutable per-CPU counters; do not inline. |
| 32 | `hc_reals_map` | `healthchecking_ipip.c:94`, `healthchecking_ipip.c:112` | runtime `skb->mark` | no | no | Runtime packet metadata and R2 config map. |
| 56 | `hc_ctrl_map` | `healthchecking_ipip.c:126` | constant key 1, IPv4 tunnel ifindex | yes | yes | Realistic R2 candidate. |
| 68 | `hc_ctrl_map` | `healthchecking_ipip.c:134` | constant key 2, IPv6 tunnel ifindex | yes | yes | Realistic R2 candidate. |

Healthcheck does not need Prong A for these four sites: the three health maps were dumped under cap in R1 (`daemon.stderr.log:4075-4077`).

### `xdp_root`

`xdp_root` has no `bpf_map_lookup_elem` sites. It tail-calls `root_array` entries in a fixed three-iteration loop (`xdp_root.c:30-35`). `root_array` is a `PROG_ARRAY`, skipped by type in R1 (`daemon.stderr.log:4073`), and is not a data `map_inline` target.

## Final Verdict

Prong B is necessary for constant-key helper lookups, but Katran is not a case where Prong B alone turns all skipped helper lookups into valid constants. Many keys are packet-derived (`vip_map`, `hc_reals_map`), helper-derived (`lru_mapping` CPU key), or value-derived from another map (`reals` after `ch_rings`/LRU/server_id). Those remain non-constant after verifier-state reconstruction.

Prong A is necessary for the seven R1 size-skipped maps, but the biggest Katran maps are bad snapshot targets in JSON form. `ch_rings` and `server_id_map` are full-array dumps measured in gigabytes, and per-CPU counter maps are mutable anyway. A smarter binary/sparse snapshot would reduce cap pain for `reals`, but it still would not prove the hot-path key constant.

Realistic `map_inline` candidates today are small, constant-key, read-mostly config maps:

- `ctl_array[0]` in `balancer_ingress`: 2 matched sites.
- `hc_ctrl_map[1]` and `hc_ctrl_map[2]` in `healthcheck_encap`: 2 matched sites.

The hot-path triple is attractive for performance, but not realistically unlocked by Prong A+B alone:

- `vip_map[vip_key]`: key is packet-derived.
- `ch_rings[hash%N]`: key is packet-derived and the map is huge.
- `reals[real_id]`: key depends on prior map/runtime state.

For the 14 R1 `balancer_ingress` matched sites, the rough realistic inlineable count after both fixes is 2/14. With an additional runtime/profile specialization beyond Prong A+B, the four `vip_map` sites become plausible benchmark-specialization targets, but that would need an explicit stale-config and traffic-key validity story.
