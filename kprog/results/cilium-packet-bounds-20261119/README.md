# Cilium's 40 verifier rejections are one missing packet-bounds predicate (omp 2026-11-19)

Run `x86_kvm_corpus_20261119_170933_095060`, raw
`/workspaces/kprog-raw/verified/20261119-checked-cilium/`. Of 64 requests, 17 reach the stock verifier
and install, 40 are rejected for one and the same reason, 6 for a second reason, and one has no
generated B. Requests and their measured shapes are in `requests.json` (fields: `class`, `section`,
`ctx_data_end_reads`, `ctx_data_reads`, `kern_len_reads`, `kern_data_len_reads`, `ctx_loadinst`).

```
124: (71) r1 = *(u8 *)(r5 +23)
invalid access to packet, off=23 size=1, R5(id=0,off=23,r=0)
R5 offset is outside of the packet
```

The verifier sees `skb->data` loaded as a packet pointer with no packet bound on the path, and rejects
the first byte read through it. `packet length predicates lowered=0` in every one of the 14 archive
`commands.jsonl` files of this run — and in every verified request of OTel (3/3), Katran (1/1) and BCC
(25/25), so the pass has not fired for any app in the current configuration.

## Why it does not fire: three shape gaps, measured

`kprog/x86/packet_bounds_ir.cpp:356-372` matches exactly one shape: an `ICmpInst` whose operand 0 is an
i64 `Sub` of two **`LoadInst`s** whose base is `function.getArg(0)` and whose constant offsets are
`offsetof(__sk_buff,data_end)` (80) and `offsetof(__sk_buff,data)` (76). Cilium's B differs on all three
points, and each difference is sufficient on its own:

| gate | matcher requires | Cilium B actually has | count |
|---|---|---|---|
| function section | `xdp`, `xdp/*`, `tc`, `tc/*`, `cgroup_skb/*` | `classifier` | 59 of 63 |
| operand shape | `LoadInst` from `%arg0` | `inline asm` `"=r,r,i,~{memory}"` calls | 40 of 40 packet-class |
| value compared | `data_end - data`, i64 | `len - data_len`, i32 (`kern` offsets 112/116) | 40 of 40 |

Measurements, from each request's `trusted_x86.bpf.bounds-input.bc`:

- **`ctx_loadinst` = 0 for all 40 packet-class requests** — not one packet-context field is a `LoadInst`;
  the simulator reads them through `asm sideeffect "$0 = *(u32 *)($1 + $2)"` with the offset as an asm
  operand, so `field()` (`packet_bounds_ir.cpp:230-237`) can never match.
- **`ctx_data_end_reads` = 0 in 33 of 40** (and 0 overall in request 3's B) — the guard Cilium writes is
  `skb->len - skb->data_len` (headlen), which is exactly `kern_len_reads`/`kern_data_len_reads` = 112/116
  in **40 of 40**. The offsets agree with the header: `__builtin_offsetof(struct sk_buff, len) == 112`,
  `data_len == 116`, `data == 208` against `vendor/bpf/bcc/libbpf-tools/x86/vmlinux.h`.
- **The comparison is 32-bit**: request 3's IR is `%124 = sub i32 %121, %123` on the `u32` fields, then
  `%129 = icmp ugt i32 %125, 41`. The pass only accepts an i64 constant.

Request 7 shows the same in the emitted B: `(61) r1 = *(u32 *)(r0 +112)`, `(61) r2 = *(u32 *)(r0 +116)`,
`(1c) w1 -= w2`, `(a6) if w1 < 0x2a` — then `(61) r1 = *(u32 *)(r1 +76)` yields `R1=pkt(r=0)` and the
byte read at +23 fails. The predicate is present and correct; the verifier just cannot connect it to the
packet pointer, because Cilium never compares against `data_end` at all.

## What an instrumented probe showed

A copy of the pass with `classifier` added to the section gate, run over all 63 requests' real
`bounds-input.bc`, still reports `lowered=0` everywhere (`/tmp/pbt/pb2`, this turn). So the section name
is the *first* rejection but not the block: adding it alone changes nothing. The `asm`-operand and
i32/`len-data_len` gaps both have to be handled.

## Why this needs the file's owner, not a drive-by edit

`kprog/x86/packet_bounds_ir.cpp` is frozen; PERF owns it under two open lines (to 2026-11-21) and has a
queued rebuild (`rawfix-20261119T193239Z`, worker 269752 waiting on the image lock). The change is not a
one-liner: it must extend `field()`/`origin()` to recognize the asm-offset read form, accept
`__sk_buff.len`/`data_len` (112/116) as a packet-span source in addition to `data_end`/`data` (80/76),
and lower a 32-bit `len - data_len >= K` compare into the pointer form that `end - data >= K` already
emits. Acceptance is measurable: the 40 requests' `bounds.bc` must verify, and Cilium's verified count
must rise from 14.

## Second class, for the same hand-off

6 requests (6, 14, 32, 44, 56, 61) are rejected with `only read is supported` — a write through a packet
pointer the verifier has not proved writable. Same file, different matcher question; counted here so the
two are not confused.
## Post-fix check against the same archive inputs (omp 2026-11-19T20:55Z)

PERF's `cdd26e9cd` ("Recognize classifier head-length predicates through simulator memory
templates") closes all three gaps above. Rebuilt the pass from that commit
(`clang++-18 … ../x86/packet_bounds_ir.cpp -o /tmp/pbt/pb-new`) and ran it over the same 40 archived
`trusted_x86.bpf.bounds-input.bc` files:

| | before | after |
|---|---|---|
| requests with `predicates lowered > 0` | 0 / 40 | **40 / 40** |
| predicates lowered, total | 0 | **235** |
| per-request range | — | 1 (req 3, 7) … 35 (req 15) |

Request 7's emitted B, `classifier` section, before → after:

```
before  (61) r1 = *(u32 *)(r1 + 76)          ; R1=pkt(r=0) — no bound, byte read rejected
after   (23) if w3 < 0x2a goto …              ; the original scalar guard, preserved
        (24) r1 += 0x2a
        (25) if r1 > r2 goto …                ; data + 42 <= data_end
        (26) r1 = *(u32 *)(r6 + 0x4c)          ; then the byte read is in bounds
```

The scalar guard is preserved and the pointer bound is added beside it; `clang-18 -O1 -target bpf`
compiles all four sampled requests (3, 7, 9, 15, 21) to objects without error.

**The rewrite is an identity, not a strengthening.** The kernel itself defines the guard this way:
`bpf_convert_data_end_access` (`vendor/linux-framework/net/core/filter.c:10976-11015`) lowers a read of
`__sk_buff.data_end` to `skb->data + skb->len - skb->data_len`, and `skb_headlen()`
(`include/linux/skbuff.h:2531-2534`) is `skb->len - skb->data_len`. So `len - data_len >= K` and
`data + K <= data_end` accept exactly the same packets; no condition was added and P is unchanged — as
required for this pass.

**No regression on the other apps.** The same binary lowers 0 predicates on all 14 OTel and the one
Katran archived inputs (`/workspaces/kprog-raw/verified/20261119-checked-otel2`,
`-katran2`), so the 17 currently installing Cilium requests and the other five apps keep their bytecode.

Not yet proven here: that the 40 patched B programs are *accepted* by the stock verifier. The host BTF
lacks the apps' extern symbols (`__config_endpoint_ipv4` etc.), so the load must happen in the guest;
PERF's `kprog/results/cilium-headlen-20261119/validate.sh` does exactly that (stock fixtures, captured
40-request replay, then a full `checked-corpus` Cilium run) and is the run to read for the verdict.
