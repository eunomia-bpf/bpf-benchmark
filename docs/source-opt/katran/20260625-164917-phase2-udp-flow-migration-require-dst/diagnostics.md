# Diagnostics

## Baseline Object

- Object: `vendor/build/x86/katran/bpf/balancer.bpf.o`
- `xdp` section size before patch: `0x4870` bytes, about 2318 BPF instructions.
- Main program: `balancer_ingress`.
- Hot helper/map sites in disassembly: `vip_map`, `stats`, `lru_mapping`, `quic_stats_map`, `server_id_map`, `reals`, `ctl_array`, `reals_stats`, and encapsulation helpers.

## Source Observation

`check_udp_flow_migration()` receives `struct real_definition **dst`; the call site passes `&dst`. Therefore the current `if (dst && ...)` checks the address of the local pointer, not whether a real has been selected. The function can do `is_under_flood()`, `vip_to_down_reals_map`, and down-real map work when `*dst == NULL`.

For UDP flow migration, only an already selected real can be migrated away from. On a no-destination path, later `get_packet_dst()` still performs CH selection. Requiring `*dst` preserves that behavior while skipping helper/map work that cannot affect routing.

## Candidate Patch

Change:

```c
if (dst && pckt->flow.proto == IPPROTO_UDP &&
```

to:

```c
if (*dst && pckt->flow.proto == IPPROTO_UDP &&
```

## Post-Patch Diagnostics

- Build command: `make -C vendor katran-x86`.
- Rebuilt file: `vendor/build/x86/katran/bpf/balancer.bpf.o`.
- `xdp` section size after patch: `0x4798` bytes, about 2291 BPF instructions.
- Delta vs clean object: `0x4870 -> 0x4798`, about 27 fewer BPF instructions.
- Disassembly shape: the patch adds a direct `*dst` guard before the UDP flow-migration block, allowing no-destination paths to skip the downstream flood/map-lookup sequence.
