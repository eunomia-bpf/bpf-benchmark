# Katran-only `const_mod_reduce` plan

Date: 2026-05-13

Scope: Katran XDP `balancer_ingress` on x86_64. This is a feasibility and implementation plan for a narrow bytecode rewrite that handles the Katran CH-ring `hash % 65537` pattern only. It is not a general modulo-strength-reduction pass.

Final constraint: do not change daemon code and do not add a formal `bpfopt` pass for this probe. The current implementation is a host-prepared raw `bpf_insn[]` artifact selected by exact input hash in runner pass config; corpus execution stays behind `make corpus`.

## Conclusion

For feasibility testing, implement `const_mod_reduce` as a Katran-only host-prepared 32-bit `% 65537` BPF-to-BPF artifact. The runner pass config only verifies the incoming bytecode hash, copies the prebuilt optimized blob, verifies the output hash, and emits a report.

The live KVM x86 JIT currently emits hardware division for both Katran CH-ring modulo sites:

```text
mov $0x10001,%r11
xor %edx,%edx
div %r11
mov %rdx,%rax
```

The prepared artifact replaces the specific zero-extended `r0 %= 65537` sequence feeding `vip_num * 65537 + hash` with a branchless reduction based on:

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

### 8. Temporary same-length binary patch

Before implementing a real pass, a same-length patch was tested through a temporary corpus pass config:

```text
runner/config/passes/manual_mod32/default.yaml
```

The hook does not change daemon behavior. It rewrites only the exact observed Katran CH-ring bytecode window by changing the modulo opcode from `ALU64 MOD imm 65537` to `ALU32 MOD imm 65537`:

```text
(97) r0 %= 65537  ->  (94) w0 %= 65537
```

This is intentionally not the proposed `const_mod_reduce` pass. It only tests the lower bound from asking the kernel JIT to emit 32-bit divide instead of 64-bit divide, without instruction insertion or branch/call offset repair.

Smoke command:

```sh
BPFREJIT_CORPUS_APPS=katran \
BPFREJIT_BENCH_PASSES=noop,manual_mod32 \
SAMPLES=1 \
WORKLOAD_DURATION=1 \
TIMEOUT=1800 \
make corpus
```

Result:

```text
corpus/results/x86_kvm_corpus_20260513_231338_150658
```

The pass was verifier-accepted, applied both sites, and changed JIT size from 13,629 B to 13,627 B.

Temporary performance command:

```sh
BPFREJIT_CORPUS_APPS=katran \
BPFREJIT_BENCH_PASSES=noop,manual_mod32 \
SAMPLES=3 \
WORKLOAD_DURATION=10 \
TIMEOUT=1800 \
make corpus
```

Result:

```text
corpus/results/x86_kvm_corpus_20260513_231550_026145
```

Raw counter-derived analysis:

```text
baseline: run_cnt=1,175,327  run_time_ns=352,259,574  avg=299.711973 ns/run
post:     run_cnt=1,124,084  run_time_ns=342,884,465  avg=305.034557 ns/run
ratio:    1.017759
```

This same-length patch is not a clear win on the 3x10s temporary run. It does not invalidate the full branchless rewrite, because the JIT still emits a hardware divide.

Post-patch live JIT capture:

```sh
BPFREJIT_CORPUS_APPS=katran \
BPFREJIT_BENCH_PASSES=noop,manual_mod32,noop \
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
corpus/results/x86_kvm_corpus_20260513_231939_355874
```

Extracted artifact:

```text
docs/tmp/katran_kvm_live_jit_manual_mod32_20260513_231939/
```

Report:

```text
sites_applied=2
patched ALU64 MOD to ALU32 MOD at raw PC 1282
patched ALU64 MOD to ALU32 MOD at raw PC 1985
```

The post-ReJIT xlated dump confirms:

```text
1480: (94) w0 %= 65537
2346: (94) w0 %= 65537
```

The post-ReJIT x86 JIT confirms 32-bit divide:

```text
mov    $0x10001,%r11
div    %r11d
imul   $0x10001,%rdi,%rdi
```

So manual same-length patching is useful as a quick feasibility probe, but it is not the optimization we want. The real `const_mod_reduce` pass still needs insertion of the branchless reduction sequence and normal jump/call offset repair.

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

### P1: Prepare a host-side optimized raw bytecode artifact

Do not add `bpfopt/crates/bpfopt/src/passes/const_mod_reduce.rs`.

The manual probe uses the already captured canonical/noop Katran raw bytecode:

```text
docs/tmp/katran_kvm_live_jit_const_mod_reduce_20260513_235438/input_step0.bin
sha256=1d8367af26069a84fdef702a2feb8ce759d0be5a904686bb146b13eadb52525e
```

and the branchless optimized raw output:

```text
runner/config/passes/const_mod_reduce/katran_x86_kvm_balancer_ingress_branchless_mod65537.bin
sha256=1929357b97f00f4a8ed653fad7c7ed84a0ee810adcb9a325b8db6b06f9a985e5
```

The host-side generator is:

```text
runner/config/passes/const_mod_reduce/generate_katran_branchless_mod65537.py
```

Rebuild the artifact from the captured testbin with:

```sh
runner/config/passes/const_mod_reduce/generate_katran_branchless_mod65537.py \
  docs/tmp/katran_kvm_live_jit_const_mod_reduce_20260513_235438/input_step0.bin \
  runner/config/passes/const_mod_reduce/katran_x86_kvm_balancer_ingress_branchless_mod65537.bin
```

The rejected branchless candidate is also preserved under a stable pass name:

```text
runner/config/passes/const_mod_reduce_branchless_rejected/default.yaml
runner/config/passes/const_mod_reduce_branchless_rejected/katran_x86_kvm_balancer_ingress_branchless_mod65537.bin
```

Run it with:

```sh
BPFREJIT_BENCH_PASSES=noop,const_mod_reduce_branchless_rejected make corpus
```

A copy is also kept as a research artifact:

```text
docs/tmp/katran_const_mod_reduce_host_prepared_20260513/katran_x86_kvm_balancer_ingress_branchless_mod65537.bin
```

The artifact is valid only when the incoming program bytes match the exact input hash above.

### P2: Match the exact Katran CH-ring pattern during host preparation

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

For the manual artifact path, these guards were applied during host preparation. Runtime config does not scan or transform; it fails fast on input hash mismatch.

### P3: Rewrite the zero-extend plus modulo sequence in the prepared artifact

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

### P4: Add runner config, but not default policy yet

Add:

```text
runner/config/passes/const_mod_reduce/default.yaml
```

with a pure shell artifact loader:

```sh
set -eu
sha256sum "${INPUT}" must equal 1d8367af...
cp runner/config/passes/const_mod_reduce/katran_x86_kvm_balancer_ingress_branchless_mod65537.bin "${OUTPUT}"
sha256sum "${OUTPUT}" must equal 192935...
write report_step*.json with sites_applied=2 and insn_count 2542->2556
```

Do not put it into the default `full-x86` policy until the Katran isolated run proves verifier acceptance and positive performance.

### P5: Verify bytecode, JIT, and performance

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

Current host-artifact smoke:

```text
corpus/results/x86_kvm_corpus_20260514_001248_985725
```

Observed:

```text
rejit_result.status: ok
prog 9 balancer_ingress: ok
const_mod_reduce bpfopt_summary:
  diagnostics:
    host_prepared_artifact=katran_x86_kvm_balancer_ingress_branchless_mod65537.bin
    input_sha256=1d8367af26069a84fdef702a2feb8ce759d0be5a904686bb146b13eadb52525e
    output_sha256=1929357b97f00f4a8ed653fad7c7ed84a0ee810adcb9a325b8db6b06f9a985e5
  sites_applied: 2
  insn_count_before: 2542
  insn_count_after: 2556
post-ReJIT balancer_ingress:
  bytes_xlated: 23952
  bytes_jited: 13659
```

Katran SAMPLES=3 measurements:

```text
corpus/results/x86_kvm_corpus_20260514_001850_584276
baseline: 6013602 runs, 835452075 ns => 138.927 ns/run
post:     6004042 runs, 845628863 ns => 140.843 ns/run
post/base: 1.01379
delta: +1.916 ns/run

corpus/results/x86_kvm_corpus_20260514_002822_465245
baseline: 6017842 runs, 827751455 ns => 137.550 ns/run
post:     6011588 runs, 858306694 ns => 142.775 ns/run
post/base: 1.03799
delta: +5.226 ns/run
```

Both SAMPLES=3 runs put the branchless artifact on the slower side, so this candidate should remain rejected unless a different machine-code shape is proposed and verified.

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

The rewrite uses `r1` as scratch. The observed Katran pattern overwrites `r1` immediately after the modulo. A future maintained pass would need to verify this, or use liveness to prove `r1` is not live across the replacement.

For the current host-prepared artifact, this is guarded by exact input hash rather than by a runtime liveness analysis.

### Semantics risk

The formula is valid for 32-bit unsigned input. The host-prepared artifact was made from the existing `r0 <<= 32; r0 >>= 32` shape and replaces that shape together with modulo. Do not generalize this to 64-bit values.

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
- temporary same-length `manual_mod32` patch accepted by ReJIT
- post-patch live JIT confirmed `div %r11d`, not elimination of divide
- temporary 3x10s measurement found no clear win from `ALU32 MOD` alone
- formal `bpfopt` `const_mod_reduce` pass removed from source
- host-prepared branchless raw bytecode artifact created
- host-side generator script added for reproducing the branchless artifact from captured testbin
- rejected branchless candidate preserved as `const_mod_reduce_branchless_rejected`
- `runner/config/passes/const_mod_reduce/default.yaml` now only hash-checks and copies the artifact
- Katran-only smoke accepted the host-prepared artifact via ReJIT
- two Katran SAMPLES=3 runs measured the branchless artifact slower

Next:

1. Keep the rejected artifact only for reproducibility.
2. Capture post-ReJIT JIT only if investigating why the ALU sequence loses.
3. Do not productize this branchless shape into a maintained `bpfopt` pass.
