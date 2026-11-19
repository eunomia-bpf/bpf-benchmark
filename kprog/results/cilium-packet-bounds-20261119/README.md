# Cilium's 41 verifier rejections are one missing packet-bounds predicate (omp 2026-11-19)

Run `x86_kvm_corpus_20261119_170933_095060`, raw
`/workspaces/kprog-raw/verified/20261119-checked-cilium/`. Of 64 requests, **41 are rejected for one and
the same reason** (`invalid access to packet`, counted request by request in the last section), 6 for a
second reason, 14 install, and 3 stop in the emitter. Requests and their measured shapes are in
`requests.json` (fields: `class`, `section`, `ctx_data_end_reads`, `ctx_data_reads`, `kern_len_reads`,
`kern_data_len_reads`, `ctx_loadinst`).

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

## Why the change needed the file's owner

`kprog/x86/packet_bounds_ir.cpp` is frozen and PERF owns it under two open lines (to 2026-11-21). The
change is not a one-liner: it must extend `field()`/`origin()` to recognize the asm-offset read form,
accept `__sk_buff.len`/`data_len` (112/116) as a packet-span source in addition to `data_end`/`data`
(80/76), and lower a 32-bit `len - data_len >= K` compare into the pointer form that `end - data >= K`
already emits. This was handed to PERF rather than edited here; it landed as `cdd26e9cd`, `650994842`
and `80dbcfc51` (checked below). Acceptance is measurable: the 40 requests' B must verify, and
Cilium's verified count must rise from 14.

The 6 requests 6, 14, 32, 44, 56, 61 are a separate class, analysed at the end of this file.

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

## What the freshness guard declines (omp 2026-11-19T21:24Z)

PERF's follow-ups `650994842` and `80dbcfc51` make the rewrite conditional on the captured `skb` fields
still being current: the matcher now walks every path from the comparison to each field read, backedges
included, and declines when a possible write to the `skb` intervenes (private alloca stores excepted).
That is the right direction — without it, a rewrite across an `skb` mutation would compare a *re-read*
`data_end` against a *stale* predicate.

Re-ran the rebuilt pass (`HEAD` = `80dbcfc51`) over the same archived inputs: **235 predicates across all
41 packet-class requests, every one with at least one** (233 on the 40 success-capsule requests plus
request 64's 2).

Why that guard is exactly the condition the rewrite needs, stated plainly: the emitted bound re-reads
`skb->data` and `skb->data_end` at the comparison site, which are *later* reads than the `len`/`data_len`
captures the original guard used. The two forms agree only while the `skb` is unchanged between them, so
the freshness walk is not extra caution — it is the proof that "no intervening write" makes
`len - data_len` and `data_end - data` the same value at both sites.

## The added bound is sufficient on a real kernel (omp 2026-11-19T21:56Z)

The host runs `7.3.0-070300rc3-generic` with `CAP_BPF`, so the verifier can be asked directly. Two
`classifier` programs, differing in exactly one thing — whether the pointer bound is present:

```
           # with bound                          # without bound (control)
 6: if w3 < 0x2a goto …                6: if w3 < 0x2a goto …
 7: r3 = r1                            7: r1 = *(s8 *)(r1 + 0x28)
 8: r3 += 0x2a                         8: r0 = *(s8 *)(r1 + 0x17)
 9: if r3 > r2 goto …                     → REJECT:
10: r2 = *(s8 *)(r1 + 0x28)                invalid access to packet, off=40 size=1,
11: r0 = *(s8 *)(r1 + 0x17)                R1(id=0,off=40,r=0)
    → ACCEPT                                R1 min value is outside of the allowed memory range
```

The control reproduces the exact failure the 40 Cilium requests hit (`off=<N> … r=0`, "outside of the
allowed memory range"), and the bound-only difference makes the same reads verify. That establishes the
emitted form is *sufficient*; the per-program case is still settled only by the guest, because each
program's paths decide whether the freshness guard lets a given predicate be lowered.

Caveat, stated because it bounds the claim: this is the host kernel
(`7.3.0-070300rc3-generic`), not the image's `7.0.0-rc2+`. The rule used
(`check_ptr_to_btf_access`/`check_mem_access` packet bounds) is stable across them, and the guest run is
the one that counts for the recorded numbers.

## Bytecode-level coverage of all forty-one (omp 2026-11-19T22:03Z)

Recompiled all 41 patched programs from `HEAD` (`80dbcfc51`, the freshness-guarded matcher) with the
pipeline's flags: **41 / 41 carry at least one emitted pointer bound in the `classifier` section**, so the
235 lowerings recorded above survive into bytecode for every request rather than being folded away.

## The forty-first program: request 64 (omp 2026-11-19T22:12Z)

The one hard failure in this run is not a separate defect — it is the same packet class with a second
mishap behind it. Request 64 (`tail_nodeport_nat_egress_ipv4`, `source_prog_id=622`) failed B's
verification with `invalid access to packet, off=18 size=2, R6(id=0,off=18,r=0)` / "R6 offset is outside
of the packet" — the identical shape as the 40 — and then its direct-native fallback could not find its
own arm image (`arm kernel native image: No such file or directory`), which is why it is a hard failure
rather than a fallback. Two independent problems, and only the first is this defect.

It was not counted in the 40 because its capsule is a `.failure.tar.gz`; its `bounds-input.bc` is there
all the same. Through `HEAD` the pass lowers **2** predicates and `clang` emits **3** pointer bounds, so
the fix covers this program too. The run's own README entry (`verified-hot-20261117/README.md:300`)
records it as a hard failure from the missing arm image; the packet rejection behind it is the same class
documented here, and the arm-image miss is still open and unrelated to this fix.

So the class is **41 programs**, not 40: 40 archived as successes with a verifier rejection, 1 archived as
the hard failure above.

## Complete accounting of the 64 requests (omp 2026-11-19T22:24Z)

Classified every request by its own capsule — `simulator-failure.json` present or absent, its `stage`, and
whether the direct-native fallback actually loaded:

| class | count | evidence |
|---|---|---|
| installs (`checked-sim-c`, no failure record) | **14** | no `simulator-failure.json` |
| **this defect** — `invalid access to packet` | **41** | 40 with a fallback, 1 hard (request 64) |
| `only read is supported` | 6 | `verify.stderr`, all with a working fallback |
| emitter refused a relative table | 3 | 22, 40, 58: `stage=generation`, fallback works |
| total | **64** | 14 + 41 + 6 + 3 |

So of the 49 requests that end on direct-native, **47 are stopped by a verifier rejection** — 41 by this
defect, 6 by the store class — and 3 by the emitter's relative-table refusal. Request 64 is the only hard
failure, and its hard part is the missing arm image, not the rejection.

This differs from the earlier reading in two ways, both corrected here: request 64 belongs to the packet
class (it is the 41st), and requests 22/40/58 are fallbacks of their own class, not installs.
