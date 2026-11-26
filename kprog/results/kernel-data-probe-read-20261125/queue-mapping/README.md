# queue_mapping canonicalization in the B bounds compiler

`packet_bounds_ir.cpp` now canonicalizes two public TC context stores through
`canonical_tc_class_stores()`, where it canonicalized one:

| physical store in B | public accessor written | kernel source of the conversion |
| --- | --- | --- |
| `*(u16 *)($0 + 46)` | `*(u32 *)($0 + 72)` — `__sk_buff.tc_classid` | `filter.c:9887-9899`, `BPF_EMIT_STORE(BPF_H, …)` into `sk_buff.cb + qdisc_skb_cb.tc_classid` (`sk_buff.cb` is 48, `tc_classid` 6) |
| `*(u16 *)($0 + 124)` | `*(u32 *)($0 + 12)` — `__sk_buff.queue_mapping` | `filter.c:9834-9849`, `BPF_EMIT_STORE(BPF_H, …)` into `bpf_target_off(sk_buff, queue_mapping, 2)` = physical 124 |

`net/core/filter.c:9147-9165` (`tc_cls_act_is_valid_access`) accepts a write at
both public ranges; `bpf_skb_is_valid_access` requires `size == sizeof(__u32)`
for a write, which is why B's 2-byte store at the physical field is refused and
the 4-byte public store is not. `filter.c:341` asserts
`sizeof_field(struct sk_buff, queue_mapping) == 2`, so 124 is the only physical
field the public 12 can be. A read of the same public offset converts to the
same physical field (`filter.c:9846-9850`), so one accessor names both.

The change is the one recorded as a patch in `12be07191`, applied under the
freeze line `kprog/docs/freeze-open.tsv` (`kprog/x86/packet_bounds_ir.cpp`,
open until 2026-11-30, coordinator 2026-11-26). A store now carries its public
offset in the work list (`SmallVector<std::pair<CallInst *, int64_t>, 4>`), so
the emitted offset comes from the matcher instead of being re-derived.

## Archived inputs: only the queue_mapping stores move

The rebuilt compiler was run against all 18 archived checked-corpus archives
(656 `trusted_x86.bpf.bounds-input.bc` inputs) beside the previously installed
one:

* 10 outputs differ, and each of them is a request whose source writes
  `sk_buff.queue_mapping`: `kdata2/cilium` 23 and 49, `kdata3/cilium` 3 and 31,
  `kdata4/cilium` 9 and 37, `recheck/cilium` 11 and 43,
  `omp-cilium-20261119/postfix-20261119T214810Z` 29 and 33.
* Every differing output reports `TC class stores canonicalized` 0 -> 1 with
  `packet length predicates lowered` unchanged; every other input is
  byte-identical.

Tool identity: `verified-compiler/packet-bounds` sha256
`fcc39e92c2a49e6df8c78c1ebd09dafc3033c83e82abb923459912cb003b841a` before,
`c8654962f42b2ce518a19386f574c61be651dc461a8db0277cc6a47e231a1cd6` after; the
previous build is kept at `/var/tmp/kprog-tmp/omp/queue-mapping/packet-bounds.prev`.

## Cilium checked rerun

`checked-corpus-20261126-qm` (guest, 8 vCPUs, host CPUs 20-23, 64 G, exit 0)
ran the same 64 Cilium requests as `checked-corpus-20261125-kdata4/cilium`.
Its archive pins the new tool (`bounds-inputs/packet-bounds` =
`c8654962f4…`) and the changed pass source in `source-identities.json`.
Per-program outcomes join the two runs (`kernel.entry` plus the program section
and map set; B's request order differs between runs):

| outcome | kdata4 | qm |
| --- | --- | --- |
| installed on checked-sim-c | 33 | 35 |
| fell back to direct-native on a verification refusal | 26 | 24 |
| failed in `context-lower` | 5 | 5 |

The only program that changes category is `cil_from_container`, the one whose
source writes `queue_mapping`: both of its requests installed, where in kdata4
both were refused with `only read is supported` at the physical store. All 24
other programs keep their exact outcome, request for request.

The residual 24 fallbacks are the two classes kdata4 already named:

* 22 packet-bounds refusals — `invalid access to packet, off=22 size=1` (13),
  `off=26 size=4` (5), `off=4 size=2` (4) — in the nodeport, netdev and policy
  tails;
* 2 `R0 invalid mem access 'scalar'` in `tail_handle_ipv4` (requests 5 and 45
  of kdata4, 27 and 47 of this run), the architectural fault arm from a real
  `div` whose divisor is the program's own map value.

The 5 `context-lower` failures are `tail_handle_snat_fwd_ipv4` (3 requests) and
`tail_ipv4_policy` (2), unchanged from `checked-corpus-20261125-kdata4`.