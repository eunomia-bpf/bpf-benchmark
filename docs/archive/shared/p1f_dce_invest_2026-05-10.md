# p1f DCE over-elimination investigation

Date: 2026-05-10

## 1. Decisive root cause

The reject is not caused by a local scalarizing instruction immediately before
`r1 &= 1`. The first wrong deletion is earlier, at the `cond_select` kop
site:

```text
input 0046: r6 = 0 (64)                  raw [b7 06 00 00 00 00 00 00]
input 0047: r0 = 1 (64)                  raw [b7 00 00 00 01 00 00 00]
input 0048: kop sidecar payload 0x1066 raw [b7 36 06 01 00 00 00 00]
input 0049: call bpf_select64            raw [85 40 0b 00 bf f6 01 00]
```

For this `cond_select` payload, `dst=r6`, `true=r6`, `false=r0`,
`cond=r1` (`cond_select.rs:203-206`). DCE deleted PC46 and PC47 because
liveness did not see that the sidecar/call consumes `r6` and `r0`.

After deletion, the select proof uses stale `r0`, which is still
`map_value(map=php_procs)`. The verifier log confirms the resulting bad type
flow:

```text
47: (bf) r6 = r0      ; R0=map_value(map=php_procs) R6=map_value(map=php_procs)
55: (7b) *(u64 *)(r10 -136) = r6
97: (79) r1 = *(u64 *)(r10 -136)
98: (57) r1 &= 1
R1 bitwise operator &= on pointer prohibited
```

Relevant code:

- `bpfopt/crates/bpfopt/src/passes/dce.rs:196-204`: runs liveness and deletes
  instructions for which `is_removable_dead_def()` is true.
- `bpfopt/crates/bpfopt/src/passes/dce.rs:228-232`: treats any ALU/ALU64/LDX
  def, and non-pseudo-func `LD_IMM64`, as removable when `dst` is not live-out.
- `bpfopt/crates/bpfopt/src/analysis/liveness.rs:75-110`: context-free
  use/def model; it has no special case for kop sidecars or kop calls.

## 2. PC mapping and deleted instructions

Two PC coordinate systems are involved. In `/tmp/dce_output.bin`, `r1 &= 1`
is local bytecode PC96. In the kernel verifier log it is PC98 because the
earlier `bpf_select64` sidecar+call is encoded as 2 local instructions but
has a 4-instruction verifier proof region, shifting later verifier PCs by +2.

Byte-identical host repro was confirmed:

```text
cargo build --workspace --locked at repo root failed because this repo root has
no Cargo.toml; the actual workspace build was run under bpfopt/.
/tmp/dce_input.bin  = 6936 insns
/tmp/dce_output.bin = 6610 insns
dce report          = 326 deleted sites
diff /tmp/dce_output.bin /tmp/repro_output.bin: no diff
diff /tmp/dce_report.json /tmp/repro_report.json: no diff
```

Local input around the later failure:

```text
0097: r1 = 1
0098: *(u64 *)(r10 -128) = r1
0099: *(u64 *)(r10 -40) = r6
0100: if r6 == 0 goto +6697
0101: r1 = *(u64 *)(r10 -136)
0102: r1 &= 1
0103: r2 = 9          deleted
0104: r0 = 2          deleted
0105: kop sidecar   kept
0106: call bpf_select64
```

Failing local output around the same area:

```text
0091: r1 = 1
0092: *(u64 *)(r10 -128) = r1
0093: *(u64 *)(r10 -40) = r6
0094: if r6 == 0 goto +6381
0095: r1 = *(u64 *)(r10 -136)
0096: r1 &= 1         verifier PC98
0097: kop sidecar
0098: call bpf_select64
```

Near this later sidecar, DCE also deleted operand materialization:
input PC103 `r2 = 9` and PC104 `r0 = 2`. That is the same bug class, but the
program is rejected before that sidecar can execute.

## 3. Wrongly deleted key defs

The decisive deleted defs are:

```text
DELETE iter=0 curr_pc=0046 orig_pc=0046
  live_out=[1,2,3,4,5,7,8,9,10] uses=[] defs=[6]
  r6 = 0

DELETE iter=0 curr_pc=0047 orig_pc=0047
  live_out=[1,2,3,4,5,7,8,9,10] uses=[] defs=[0]
  r0 = 1
```

PC47 is the immediately decisive one: without it, `bpf_select64`'s false
operand `r0` is the stale `php_procs` map value pointer. The select proof then
writes that pointer into `r6`, and PC57 stores it to stack slot `fp-136`.
Later PC101/102 reloads that stack slot and applies `&= 1`.

## 4. Why liveness miscomputed it

`LivenessAnalysis` computes standard backward live-in/live-out sets from
`insn_use_def_set()` (`liveness.rs:34-65`).

The use/def table is wrong for kop pseudo instructions:

- `BPF_ALU64 | BPF_MOV | BPF_K` is treated as a normal immediate move that
  only defines `dst` (`liveness.rs:76-82`).
- `BPF_PSEUDO_KOP_SIDECAR` is encoded as exactly that kind of instruction
  (`insn.rs:608-612`, `insn.rs:670-671`).
- Generic calls are modeled as normal BPF helper ABI calls using `r1-r5` and
  defining `r0-r5` (`liveness.rs:101-110`), but a kop call consumes operands
  from the packed sidecar payload.

So the liveness result says PC46's `r6` and PC47's `r0` are dead, even though
the following `bpf_select64` sidecar/call needs them.

## 5. Reverse validation

Temporary guard tested: do not delete a def if its destination register appears
in any kop sidecar payload field (`dst`, `true`, `false`, `cond`). This is
intentionally broad and is not the proposed fix.

Result:

```text
original DCE: 6936 -> 6610, 326 sites deleted
guarded DCE:  6936 -> 6916, 20 sites deleted
```

The guarded output preserved input PC46, PC47, PC67, and the whole local
PC90..106 region. This structurally reverses the bad type flow: the select
operands are no longer stale, so `fp-136` is not populated from the old
`php_procs` pointer by the deleted-def path.

I could not produce a fresh kernel `accepted` verifier log on this host:

- `sudo -n bpftool prog show id 10` reports `No such file or directory`; the
  live program from the corpus run is gone.
- The failure tar does not include the old `prog_info.json`/`fd_array.json`
  needed for the stale host `bpfverify` path, and that path is outside the
  current v3 architecture anyway.

## 6. Recommended fix location

Do not fix in this investigation commit. Recommended follow-up:

- Fix the liveness model in `bpfopt/crates/bpfopt/src/analysis/liveness.rs`.
  It needs kop-sidecar-aware use/def information. For `bpf_select64`, mark
  sidecar payload regs `true`, `false`, and `cond` as uses and `dst` as the
  produced register.
- Also harden `bpfopt/crates/bpfopt/src/passes/dce.rs:is_removable_dead_def`
  so a `BPF_PSEUDO_KOP_SIDECAR` is never treated as an ordinary removable
  immediate move.
- The most direct regression should build a small `cond_select` sidecar/call
  program where the false operand is `r0` after a helper/map-value-producing
  call, then assert DCE preserves the operand materialization.
