# Katran per call: where 05-29's and 8430daa81's native speed came from (2026-11-23)

Operator 2026-11-23: "性能是不是不够好? 为啥?".

Katran's single program balancer_ingress, per call with bpf stats on (corpus/results, baseline = eBPF,
post_rejit = native):

| Run | eBPF ns | native ns | native/eBPF | native bytes |
|---|---|---|---|---|
| 05-29 x86_kvm_corpus_20260529_061439_040837 | 178.3 | 142.4 | 1.25x | 10192 |
| 8430daa81 x86_kvm_corpus_20261122_002150_663253 | 180.7 | 145.9 | 1.24x | 10196 |
| 09613661f x86_kvm_corpus_20261122_171542_684932 | 176.8 | 175.6 | 1.01x | 9739 |
| dcf4a1aef x86_kvm_corpus_20261123_125701_042461 | 180.1 | 179.8 | 1.00x | 9739 |

The eBPF arm stays at 177–181 ns; the native arm moved by 34 ns between 8430daa81 and 09613661f, when
a04e31ae9 replaced the 05-29 linker's call-order lookup matching with binding by map name.

`replay.sh` links the 8430daa81 Katran object with the 8430daa81 linker offline (both exported from git
into /tmp; the plan is the Katran plan saved on 2026-11-16, whose lookup sites come from the frozen eBPF
object) and prints the site the linker gives each native lookup (`replay.out`). 58 of the 66 lookups
name their map in the argument register and take that map's site. Of the other eight, five take a
generic helper site; three take an inline PERCPU_ARRAY site of the map `stats`:

- calls 38, 43 and 44 (proof-object offsets 0x14b8, 0x166f, 0x16c7) pass the map pointer from stack
  slot 0x78(%rsp), which holds the result of `bpf_map_lookup_elem(&lru_mapping, &cpu)` or
  `&fallback_cache`: the per-CPU LRU connection table, an LRU hash map. The key is the packet's flow at
  0x40(%rsp).
- The PERCPU_ARRAY form bounds the first key word against stats' 1024 entries. The flow starts with the
  source address 10.0.0.2 (0x0200000a), so the inline form returns NULL on every packet, and the
  connection-table lookup of the LRU (hashing the 5-tuple, walking the bucket) never runs.

So 05-29's and 8430daa81's native Katran skipped the LRU lookups that the eBPF program performs; their
1.11x throughput and 1.24x per call come from that, the same defect that made OTel's 05-29 number void
(a04e31ae9's message: a site of another map gives the inline form and its map layout). On dcf4a1aef
those three lookups call the kernel helper, as the eBPF program's do (two different maps reach the same
call, so the verifier also leaves the helper call).

Where Katran's time goes on dcf4a1aef (in-guest cpu-clock profile, kprog/results/profile-20261123,
Katran run of 2026-11-23T07:57Z): native body 17486 samples, eBPF body 16964. The heaviest instructions
in both are the loads right after two lookups into large arrays: the consistent-hash ring (ch_rings,
0x2000200 entries; native 2781 samples, eBPF 3077) and the QUIC server-id table (server_id_map,
0xfffffe entries; native 2665, eBPF 621). The eBPF program also spends 1761 samples on the 64-bit
division for the ring index (`% 65537`), which native code does with a multiply. Both arms perform the
same table reads and the same kernel hash lookups (htab_map_hash 0.89% / 0.82%, lookup_nulls_elem_raw
0.60% / 0.57% of all samples), so per call they meet at 180 ns.

## Cilium on the same linker

`cilium-replay.sh` compiles bpf_lxc.c with the 8430daa81 headers and links each bpf_lxc program that has
a saved 2026-11-16 plan with the same 8430daa81 linker (`cilium-replay.out`): cil_from_container,
cil_to_container, cil_lxc_policy, tail_handle_ipv4, tail_ipv4_to_endpoint, tail_no_service_ipv4 (two
plans), tail_handle_arp. 64 lookups: 60 take their own map's site by name, four call the generic helper,
none takes another map's form. Cilium's gap to its 05-29 number has another source.

Cilium on dcf4a1aef: 1.205x per call, 1.169x throughput (stats off); the 05-29 run has 1.319x
throughput.
