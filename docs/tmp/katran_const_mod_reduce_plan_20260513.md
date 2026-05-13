# Katran-only `const_mod_reduce` plan

Date: 2026-05-13

Scope: Katran XDP `balancer_ingress` on x86_64. This is a feasibility and implementation plan for a narrow bytecode rewrite pass that handles the Katran CH-ring `hash % 65537` pattern only. It is not a general modulo-strength-reduction pass.

No daemon change is needed. The pass belongs in `bpfopt`; corpus execution stays behind `make corpus`.

## Conclusion

Implement `const_mod_reduce` as a Katran-only 32-bit `% 65537` BPF-to-BPF rewrite.

The live KVM x86 JIT currently emits hardware division for both Katran CH-ring modulo sites:

```text
mov $0x10001,%r11
xor %edx,%edx
div %r11
mov %rdx,%rax
```

The pass should replace the specific zero-extended `r0 %= 65537` sequence feeding `vip_num * 65537 + hash` with a branchless reduction based on:

```text
2^16 == -1 (mod 65537)
```

For a 32-bit `x`:

```text
lo = x & 0xffff
hi = x >> 16
x % 65537 = lo - hi (mod 65537)
```

Since `lo` and `hi` are each at most 65535, one correction is enough.

Recommended replacement:

```text
r1 = r0
r1 >>= 16
r1 &= 65535
r0 &= 65535
r0 -= r1
r1 = r0
r1 >>= 63
r0 += r1
r1 <<= 16
r0 += r1
```

If `lo >= hi`, `r1 >> 63` is 0 and the result is `lo - hi`. If `lo < hi`, the 64-bit subtraction underflows, `r1 >> 63` is 1, and the final two operations add `1 + 65536 == 65537`.

This avoids a data-dependent branch on random hash bits and avoids both `div` and new `imul`.

## Research process

### 1. Start from the old limitation

The older Katran upper-bound note said real live JIT was missing:

- host `bpftool prog show` returned `Operation not permitted`
- `docs/tmp/katran_jited.disasm` was explicitly not a real live JIT dump
- conclusions about `%65537` were therefore still conditional

That meant `const_mod_reduce` first needed bytecode and KVM-kernel JIT evidence, not implementation.

### 2. Reject the host-only dump as authoritative

The host dump was useful but not authoritative for corpus results because host and KVM kernels differ:

- host kernel: `6.15.11-061511-generic`
- KVM corpus kernel: `7.0.0-rc2+`

So the decision point had to be a dump from inside the KVM corpus environment, not from a privileged host container.

### 3. Add a corpus-side live dump hook without touching daemon

The framework did not persist live JIT dumps. The safe path was to add an env-gated hook in `runner/config/passes/noop/default.yaml`:

```sh
if [ "x$BPFREJIT_DUMP_LIVE_JIT" = "x1" ]; then
  bpftool prog show id ${PROG_ID} > ${WORKDIR}/live_prog_show.txt
  bpftool -j prog show id ${PROG_ID} > ${WORKDIR}/live_prog_show.json
  bpftool prog dump xlated id ${PROG_ID} > ${WORKDIR}/live_xlated.disasm
  bpftool prog dump jited id ${PROG_ID} file ${WORKDIR}/live_jited.bin
  objdump -D -b binary -m i386:x86-64 ${WORKDIR}/live_jited.bin > ${WORKDIR}/live_jited.objdump
fi
```

Then force the pass to fail with `BPFREJIT_DUMP_LIVE_JIT_FAIL=1` so `KEEP_WORKDIRS=1` writes a failure tarball. This does not filter ReJIT programs and does not require daemon changes.

The first attempt proved that the runtime bpftool was built without JIT disassembly support:

```text
Error: No JIT disassembly support
```

The runtime Dockerfile had bpftool built with `feature-llvm=0` and all libbfd paths disabled. Rebuilding bpftool with `feature-llvm=1` fixed this; the rebuilt image reports:

```text
bpftool v7.7.0
using libbpf v1.7
features: llvm
```

### 4. Run the KVM Katran/noop dump

Command:

```sh
BPFREJIT_CORPUS_APPS=katran \
BPFREJIT_BENCH_PASSES=noop \
KEEP_WORKDIRS=1 \
BPFREJIT_DUMP_LIVE_JIT=1 \
BPFREJIT_DUMP_LIVE_JIT_FAIL=1 \
SAMPLES=1 \
WORKLOAD_DURATION=1 \
TIMEOUT=1800 \
make corpus
```

Result:

```text
corpus/results/x86_kvm_corpus_20260513_220629_417656
```

Failure artifact:

```text
corpus/results/x86_kvm_corpus_20260513_220629_417656/details/failure-artifacts/9.tar.gz
```

Extracted copy:

```text
docs/tmp/katran_kvm_live_jit_noop_20260513_220629/
```

Live program:

```text
9: xdp  name balancer_ingress  tag 90e1a12c30a4bce5
xlated 23840B  jited 13629B
run_cnt 144240
```

### 5. Confirm the two `%65537` bytecode sites

The xlated dump shows two static sites:

```text
live_xlated.disasm:2018:1480: (97) r0 %= 65537
live_xlated.disasm:2023:1483: (27) r1 *= 65537

live_xlated.disasm:3167:2346: (97) r0 %= 65537
live_xlated.disasm:3172:2349: (27) r1 *= 65537
```

Both are the same CH-ring shape:

```text
r0 = get_packet_hash(...)  // zero-extended to 32 bits
r0 %= 65537
r1 = vip_info->vip_num
r1 *= 65537
r1 += r0
key = r1
real_pos = bpf_map_lookup_elem(&ch_rings, &key)
```

### 6. Confirm the x86 JIT uses division

The corresponding JIT dump shows division at both sites:

```text
live_jited.objdump:1699: mov    $0x10001,%r11
live_jited.objdump:1701: div    %r11
live_jited.objdump:1706: imul   $0x10001,%rdi,%rdi

live_jited.objdump:2682: mov    $0x10001,%r11
live_jited.objdump:2684: div    %r11
live_jited.objdump:2689: imul   $0x10001,%rdi,%rdi
```

Therefore the kernel x86 BPF JIT does not already optimize this constant modulo. The opportunity is real.

### 7. Check the formula

The formula was checked on edge cases:

```text
0
1
65535
65536
65537
65538
0xffffffff
0x12345678
0x80000000
```

The branchless sequence matches `x % 65537` for 32-bit `x`.

## Implementation plan

### P0: Keep scope narrow

Do not implement a generic constant modulo optimizer.

The first version should only match:

- `ctx.arch == x86_64`
- destination register is `r0`
- divisor is immediate `65537`
- input is explicitly the low 32 bits of a hash value
- the modulo result is immediately consumed by the Katran CH-ring key pattern
- scratch register `r1` is safe because the matched suffix overwrites it before any read

This avoids broad verifier risk and avoids accidentally changing unrelated BPF programs.

### P1: Add a new bpfopt pass

Add:

```text
bpfopt/crates/bpfopt/src/passes/const_mod_reduce.rs
bpfopt/crates/bpfopt/src/passes/const_mod_reduce_tests.rs
```

Register it in:

```text
bpfopt/crates/bpfopt/src/passes/mod.rs
```

Add:

```rust
mod const_mod_reduce;
pass_entry!("const_mod_reduce", const_mod_reduce::ConstModReducePass, &[], false)
```

This pass is pure bytecode rewrite and needs no kinsn target and no verifier-state side input.

### P2: Match the exact Katran CH-ring pattern

Match a single-block window around this shape:

```text
r0 <<= 32
r0 >>= 32
r0 %= 65537
r1 = *(u64 *)(r10 -160)       // observed vip_info spill slot
r1 = *(u32 *)(r1 +4)          // vip_info->vip_num
r1 *= 65537
r1 += r0
```

The spill offset should not be hard-coded as the semantic guard. Use it only as part of the first conservative version if needed. The important guards are:

- `zext32(r0)` immediately before the modulo
- `BPF_MOD | BPF_K` with `imm == 65537`
- following key arithmetic is `some_reg *= 65537; some_reg += r0`
- `r1` is overwritten before the `r1 *= 65537` use

If any guard fails, skip and report a site skip reason.

### P3: Rewrite the zero-extend plus modulo sequence

Replace the three instructions:

```text
r0 <<= 32
r0 >>= 32
r0 %= 65537
```

with:

```text
r1 = r0
r1 >>= 16
r1 &= 65535
r0 &= 65535
r0 -= r1
r1 = r0
r1 >>= 63
r0 += r1
r1 <<= 16
r0 += r1
```

This is a net increase of 7 BPF instructions per site. The expected runtime win comes from removing a variable-latency 64-bit divide and the JIT's `rdx` save/restore sequence.

The emitted instructions are ordinary scalar ALU ops:

- `BPF_MOV | BPF_X`
- `BPF_RSH | BPF_K`
- `BPF_AND | BPF_K`
- `BPF_SUB | BPF_X`
- `BPF_ADD | BPF_X`
- `BPF_LSH | BPF_K`

No helper call, map access, pointer arithmetic, or verifier-state dependency is introduced.

### P4: Tests

Unit tests should catch real correctness bugs, not just existence:

- rewrites the exact Katran-like pattern
- applies to two independent sites in one program
- skips non-`r0` modulo
- skips divisor other than 65537
- skips missing zero-extension
- skips missing CH-ring `* 65537 + r0` suffix
- skips when scratch `r1` is read before being overwritten
- validates the arithmetic sequence for representative 32-bit values by simulating the emitted ALU operations

Suggested targeted unit command during development:

```sh
cargo test --workspace --manifest-path bpfopt/Cargo.toml const_mod_reduce
```

Repository-level validation remains through the Makefile:

```sh
make test
```

### P5: Add runner config, but not default policy yet

Add:

```text
runner/config/passes/const_mod_reduce/default.yaml
```

with the standard pure bpfopt CLI command:

```sh
timeout 6000 bpfopt --pass const_mod_reduce \
  --input ${INPUT} \
  --output ${OUTPUT} \
  --report ${REPORT} \
  --prog-type ${PROG_TYPE} \
  --target ${TARGET}
```

Do not put it into the default `full-x86` policy until the Katran isolated run proves verifier acceptance and positive performance.

### P6: Verify bytecode, JIT, and performance

First isolated functional run:

```sh
BPFREJIT_CORPUS_APPS=katran \
BPFREJIT_BENCH_PASSES=noop,const_mod_reduce \
SAMPLES=1 \
WORKLOAD_DURATION=1 \
TIMEOUT=1800 \
make corpus
```

Then capture post-ReJIT JIT with the same dump hook:

```sh
BPFREJIT_CORPUS_APPS=katran \
BPFREJIT_BENCH_PASSES=noop,const_mod_reduce \
KEEP_WORKDIRS=1 \
BPFREJIT_DUMP_LIVE_JIT=1 \
BPFREJIT_DUMP_LIVE_JIT_FAIL=1 \
SAMPLES=1 \
WORKLOAD_DURATION=1 \
TIMEOUT=1800 \
make corpus
```

Expected post-ReJIT checks:

- `report_step*.json`: `sites_applied == 2`
- xlated output no longer has `r0 %= 65537` at those two sites
- post JIT no longer has `div %r11` for CH modulo
- program remains verifier-accepted

Finally run paper-grade Katran isolated measurement:

```sh
BPFREJIT_CORPUS_APPS=katran \
BPFREJIT_BENCH_PASSES=noop,const_mod_reduce \
SAMPLES=3 \
WORKLOAD_DURATION=30 \
TIMEOUT=1800 \
make corpus
```

Interpretation remains analysis-side only; framework result JSON must stay raw.

## Risks and mitigations

### Code-size risk

The rewrite expands each site by 7 BPF instructions. Katran has two sites, so expected net growth is 14 instructions. The current program is large but still far from verifier instruction limits; nevertheless the isolated run must confirm ReJIT acceptance.

### Register clobber risk

The rewrite uses `r1` as scratch. The observed Katran pattern overwrites `r1` immediately after the modulo. The pass must verify this, or use liveness to prove `r1` is not live across the replacement.

### Semantics risk

The formula is valid for 32-bit unsigned input. The pass must require the existing `r0 <<= 32; r0 >>= 32` shape, then replace that shape together with modulo. Do not apply to 64-bit values.

### Benchmark-only creep

This optimization is production-safe only because it preserves the exact `%65537` semantics. Do not combine it with VIP or CH-ring value specialization in this pass.

## Current status

Done:

- KVM live xlated dump captured
- KVM live JIT dump captured
- bpftool rebuilt with LLVM support
- two Katran `%65537` sites identified
- both sites confirmed to JIT as `div`
- arithmetic rewrite formula checked on representative edge cases

Next:

1. Implement `bpfopt` pass and unit tests.
2. Add `runner/config/passes/const_mod_reduce/default.yaml`.
3. Run Katran isolated `noop,const_mod_reduce` smoke.
4. Capture post-ReJIT JIT and verify `div` is gone.
5. Run Katran SAMPLES=3 performance measurement through `make corpus`.
