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
## Post-fix check against the same archive inputs (omp 2026-11-19T21:10Z)

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

The scalar guard is preserved and the pointer bound is added beside it. Compiled all **40** patched
programs with the pipeline's own command (`clang-18 -w -g -O1 -mcpu=v4 -target bpf`, the flags in
`trusted_specializer.py`); every one built, and the count of pointer-to-pointer compares in the emitted
`classifier` section is at least the lowering count in all 40 — no predicate is lost between IR and
bytecode. The bound itself reads the two public `__sk_buff` fields, `+0x4c` (data, offset 76) and
`+0x50` (data_end, offset 80), which the kernel's context conversion turns into `pkt` and `pkt_end`.

**The rewrite is an identity, not a strengthening.** The kernel itself defines the guard this way:
`bpf_convert_data_end_access` (`vendor/linux-framework/net/core/filter.c:10976-11015`) lowers a read of
`__sk_buff.data_end` to `skb->data + skb->len - skb->data_len`, and `skb_headlen()`
(`include/linux/skbuff.h:2531-2534`) is `skb->len - skb->data_len`. So `len - data_len >= K` and
`data + K <= data_end` accept exactly the same packets; no condition was added and P is unchanged — as
required for this pass.

**No regression on anything that already works.** The same binary lowers 0 predicates on all 14 OTel and
the one Katran archived inputs (`/workspaces/kprog-raw/verified/20261119-checked-otel2`, `-katran2`), and
on all 14 Cilium requests that already install and whose B input is archived (1, 2, 4, 5, 8, 13, 30, 34,
39, 46, 51, 52, 54, 62; the other three installing requests kept no `bounds-input.bc`). So the fix
changes bytecode only for the 40 that the verifier rejects, and the other five apps keep theirs.

Not yet proven here: that the 40 patched B programs are *accepted* by the stock verifier. Loading needs
a guest. The host BTF
lacks the apps' extern symbols (`__config_endpoint_ipv4` etc.), so the load must happen in the guest;
PERF's `kprog/results/cilium-headlen-20261119/validate.sh` does exactly that (stock fixtures, captured
40-request replay, then a full `checked-corpus` Cilium run) and is the run to read for the verdict.

## The six `only read is supported` requests are a different defect (omp 2026-11-19T21:14Z)

Requests 6, 14, 32, 44, 56, 61 fail at the same instruction shape, and it has nothing to do with packet
bounds. Request 6's trace:

```
13: (85) call bpf_cast_to_kern_ctx#70422   ; R0=trusted_ptr_sk_buff()
65: (bf) r2 = r0                            ; R2=trusted_ptr_sk_buff()
66: (07) r2 += 46                           ; R2=trusted_ptr_sk_buff(off=46)
67: (6b) *(u16 *)(r2 +0) = r1
only read is supported
```

The kernel rejects it in `check_ptr_to_btf_access` (`kernel/bpf/verifier.c:7424-7429`): when the program
type provides `btf_struct_access` — and `tc_cls_act_verifier_ops` does, `net/core/filter.c:11218-11224` —
a `BPF_WRITE` through `PTR_TO_BTF_ID` goes to that hook, but `bpf_cast_to_kern_ctx` hands back
`PTR_TO_BTF_ID | PTR_TRUSTED` with **no `MEM_ALLOC`** (`verifier.c:14018-14021`), so the else-branch's
`atype != BPF_READ && !type_is_ptr_alloc_obj(...)` fires. `tc_cls_act_btf_struct_access`
(`filter.c:9201-9212`) only consults `nfct_btf_struct_access`, which the conntrack module publishes for
the four conntrack fields, so an arbitrary `sk_buff` offset is refused either way.

Separately, offset 46 does not name a field: in the target `vmlinux.h`, 40 is `struct llist_node
ll_node` in `sk_buff`'s opening union, so 46 is six bytes into that member.

So this class needs a decision the packet-bounds pass cannot make: either lower the store to the public
`__sk_buff` accessor that `convert_ctx_access` knows (the way the ctx reads already work), or route the
write through a kernel-side `btf_struct_access` that admits it. It is **not** the same fix as the 40, and
should not be counted as part of it.

## The freshness guard costs 2 of 235 predicates (omp 2026-11-19T21:24Z)

PERF's follow-ups `650994842` and `80dbcfc51` make the rewrite conditional on the captured `skb` fields
still being current: the matcher now walks every path from the comparison to each field read, backedges
included, and declines when a possible write to the `skb` intervenes (private alloca stores excepted).
That is the right direction — without it, a rewrite across an `skb` mutation would compare a *re-read*
`data_end` against a *stale* predicate.

Re-ran the rebuilt pass (`HEAD` = `80dbcfc51`) over the same 40 archived inputs: **233 predicates, still
40 / 40 requests with at least one** (down from 235, so 2 predicates sit across a possible mutation and
are correctly declined).

Why that guard is exactly the condition the rewrite needs, stated plainly: the emitted bound re-reads
`skb->data` and `skb->data_end` at the comparison site, which are *later* reads than the `len`/`data_len`
captures the original guard used. The two forms agree only while the `skb` is unchanged between them, so
the freshness walk is not extra caution — it is the proof that "no intervening write" makes
`len - data_len` and `data_end - data` the same value at both sites.
