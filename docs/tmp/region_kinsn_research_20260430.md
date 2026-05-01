# Region kinsn research: high-register-pressure regions

Status: ⏸ 后续 phase（等 kinsn v3 / region ABI 收敛）

Scope: research-only. No code, vendor, or module edits. No tests were run.

## 1. 当前 kinsn ABI 局限

当前 kinsn 已经不是普通 helper call，而是 `sidecar + BPF_PSEUDO_KINSN_CALL`
的 packed kfunc transport。内核 descriptor 仍然很小：

```c
struct bpf_kinsn {
	struct module *owner;
	u16 max_insn_cnt;
	u16 max_emit_bytes;
	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);
	int (*emit_x86)(u8 *image, u32 *off, bool emit, u64 payload, const struct bpf_prog *prog);
	int (*emit_arm64)(u32 *image, int *idx, bool emit, u64 payload, const struct bpf_prog *prog);
};
```

Verifier path is proof lowering:

1. userspace pass emits `kinsn_sidecar(payload)` + `call_kinsn_with_off()`
2. `lower_kinsn_proof_regions()` replaces that pair with `instantiate_insn(payload)`
3. verifier analyzes the proof sequence
4. `restore_kinsn_proof_regions()` restores the sidecar/call pair
5. arch JIT calls `emit_x86` / `emit_arm64`

This is enough for current single-operation kinsns:

- `cond_select`: one packed call, proof is branch/mov semantics, native is CMOV/CSEL.
- `extract`: one packed call, proof is shift+mask, native is BEXTR/UBFM-like lowering.
- `prefetch`: proof is nop, native is `PREFETCHT0` / `PRFM`.
- `ccmp`: proof is a short compare chain, native is ARM64 `CMP/CCMP/CSET`.
- `bulk_memory`: proof is byte load/store loop, native uses `rep movsb/stosb` or A64 load/store sequences.

What region kinsn needs but current ABI does not define explicitly:

- N original BPF instructions replaced by one sidecar/call site, with a declared region length and region kind.
- A live-in/live-out ABI, not just a compact operand payload for a single operation.
- A native scratch-register contract, because the point is to use native registers not modeled as BPF registers.
- A proof relation between the original N-instruction region, `instantiate_insn()` proof object, and native emit.
- Userspace proof metadata handling. `bpfopt` currently hard-codes proof lengths in
  `passes/utils.rs` per known target; there is no generic region descriptor discovery.

The important limitation is not that N-to-1 replacement is impossible. Existing passes already replace
multi-insn BPF idioms with a 2-insn kinsn call form. The missing part is a general, reviewable contract
for a multi-instruction region whose native implementation intentionally uses extra native-only registers.

## 2. Proof model options

### Option A: pure scalar region

First viable model:

- Region is single-entry/single-exit and has no internal call, helper, kfunc, tail call, exit, or back-edge.
- Inputs are a fixed set of BPF scalar registers.
- Output is one BPF scalar register.
- No stack, packet, map, ctx, or global memory writes.
- No native memory access inside `emit_*`.
- Any original memory loads required by the computation must happen before the region and enter through input registers.
- Any original stack spill/fill removed by the region must be proven to be compiler scratch, not caller-visible stack state.

Proof object:

- `instantiate_insn(payload)` emits a canonical ordinary-BPF scalar sequence for the region kind.
- The proof sequence may write only `dst` and declared temporary BPF registers.
- Temporary BPF registers are allowed only when they are not live-out, matching the existing formal projection
  model in `docs/kinsn-formal-semantics.md`.
- Keep the first implementation stack-free. `kinsn_v2_instantiate_design` already identifies stack-free proof
  lowering as the simplest current-kernel constraint because stack-depth accounting happens after main analysis.

This keeps verifier safety simple: the verifier sees ordinary BPF scalar code and no memory side effects.
Native emit then only needs to refine that proof sequence on `LiveOut`.

### Option B: effect-signature region

Broader model:

- Region can write multiple BPF registers.
- Region can read packet/map/ctx/stack memory.
- Region can write caller-visible stack or packet memory.
- Descriptor carries an effect signature: live-ins, live-outs, clobbers, memory reads, memory writes, bounds assumptions.

This is not a first version. It moves the design from "proof object is ordinary BPF" toward "verifier trusts a
region-specific effect summary." That would require either a trusted effect DSL or a stronger proof checker.
It also makes native emit correctness harder because memory aliasing and verifier pointer-state precision become part
of the contract.

## 3. Native register ABI

The region goal is to escape BPF's 10 visible registers, but the available native registers are narrower than
"all high registers."

### x86-64

Current x86 BPF JIT mapping:

- BPF `r0..r5`: `RAX, RDI, RSI, RDX, RCX, R8`
- BPF `r6..r9`: `RBX, R13, R14, R15`
- BPF `r10`: `RBP`
- JIT temps: `BPF_REG_AX` maps to `R10`, `AUX_REG` maps to `R11`
- `R9` is reserved for trampoline use in the JIT table
- `R12` is unused by BPF programs but is callee-saved and has worse memory encoding

First scalar region should use:

- native registers backing declared BPF inputs/outputs
- `R10` and `R11` as volatile scratch when the region does not cross helper/call boundaries
- optionally `R12` only if the emitter saves/restores it or the JIT ABI explicitly reserves it for kinsn

Do not use `R13-R15` as scratch: they are BPF `r7-r9`. Do not use XMM registers in phase 1; the SIMD/FPU research
already found x86 FPU context cost too high for these fine-grained paths.

### ARM64

Current arm64 BPF JIT mapping:

- BPF `r0..r5`: `x7, x0, x1, x2, x3, x4`
- BPF `r6..r9`: `x19..x22`
- BPF `r10`: `x25`
- JIT temps: `BPF_REG_AX = x9`, `TMP_REG_1..3 = x10..x12`
- `x23/x24` are saved in the JIT prologue but not mapped to BPF registers
- `x26..x28` are used by tail-call/private-stack/arena machinery

First scalar region should use:

- native registers backing declared BPF inputs/outputs
- `x9..x12` as volatile scratch
- optionally `x13..x17` if the arch JIT contract reserves them for kinsn emit
- avoid `x18`
- consider `x23/x24` only as an explicit later extension, because they are callee-saved and part of the JIT prologue policy

Do not use NEON/SIMD in phase 1.

## 4. Corpus census

This is a read-only census, not profile data. It estimates where a pure scalar region could matter.

Source scan:

- Cilium has direct Jenkins hash users:
  - `runner/repos/cilium/bpf/lib/hash.h`: `hash_from_tuple_v4()` calls `jhash_3words()`.
  - `runner/repos/cilium/bpf/lib/hash.h`: `hash_from_tuple_v6()` does two `__jhash_mix()` rounds and one `__jhash_final()`.
  - `runner/repos/cilium/bpf/lib/jhash.h`: `__jhash_mix()` and `__jhash_final()` are rotate/xor/add/sub chains.
  - `runner/repos/cilium/bpf/lib/ghash.h`: `hash_32()` is a small multiply/shift hash and does not need region kinsn.
  - Cilium checksum paths mostly use helpers or small scalar folds; they are not first-wave region candidates.
- Calico has Maglev/Jenkins:
  - `runner/repos/calico/felix/bpf-gpl/maglev.h`: IPv4 `hashword(ip_arr, 5, 0xCA71C0)`.
  - `runner/repos/calico/felix/bpf-gpl/maglev.h`: IPv6 `hashword(ip_arr, 11, 0xCA71C0)`.
  - `runner/repos/calico/felix/bpf-gpl/jenkins_hash.h`: `mix()` and `final()` are the same rotate/xor/add/sub shape.
  - Most checksum work is delegated to `bpf_csum_diff()` / `bpf_l3_csum_replace()` / `bpf_l4_csum_replace()`.
- Tetragon source is absent from `runner/repos` in this workspace, but built objects exist under `corpus/build/tetragon`.
  Its candidate-looking regions are mostly byte packing, argument decoding, and event-buffer field assembly, not obvious
  SipHash/xxhash/CRC/Jenkins hot loops.

Object heuristic:

Command shape used:

```bash
llvm-objdump -d --no-show-raw-insn <object> |
  sliding 32-insn window:
    alu/bit ops >= 16
    stack spill/fill ops >= 4
    calls == 0
    non-stack memory ops <= 2
```

Raw overlapping windows were clustered into contiguous regions:

| App | Objects scanned | Files with candidate clusters | Candidate clusters |
| --- | ---: | ---: | ---: |
| Cilium | 7 | 5 | 24 |
| Calico | 8 | 1 | 1 |
| Tetragon | 93 | 43 | 175 |

Interpretation:

- Cilium's 24 clusters are a real signal, but many are packet/address byte assembly or checksum-adjacent blocks. Pure scalar
  region candidates after manual review are closer to the jhash tuple paths and a few byte-pack/comparison blocks:
  approximately 10-20 candidate regions across the runtime objects, with fewer unique shapes.
- Calico's raw runtime signal is small in the checked debug corpus: one strong Jenkins/Maglev-looking cluster in
  `from_hep_debug.bpf.o` around the `hashword()` mix/final sequence. Source shows two logical hashword variants
  (IPv4 length 5, IPv6 length 11), so first-wave scope is about 1-4 region shapes.
- Tetragon has many raw clusters because generic tracing templates are duplicated across kernel-version variants.
  Deduplicated, this looks like a small set of byte-pack/argument-decoder shapes rather than hash/checksum loops.
  It is not a strong first-wave region-kinsn driver unless profiling proves those decoders dominate runtime.

## 5. First implementation scope

Do not build a generic arbitrary-N region kinsn first.

A safe first version would be fixed-shape, pure scalar regions:

- `jhash_mix32(a, b, c) -> packed/new state` is awkward because it has three outputs; avoid as first target unless
  the ABI supports multiple outputs.
- `jhash_final32(a, b, c) -> c` is a better first target if the original region only needs the final `c`.
- `pack_u32_bytes` / `pack_u64_bytes` can be useful for byte assembly, but only if all bytes are already in BPF regs.
- No stack-visible effects, no packet/map/ctx access, no helper calls, no branch inside the region.
- Payload encodes a small enum region kind, dst, up to 5 input regs, width, and immediate mode bits.
- `instantiate_insn()` emits canonical BPF proof code for the selected region kind.
- `emit_*()` uses only the approved arch scratch set and never emits calls.

Required bpfopt side conditions:

- contiguous region with no interior branch target
- no helper/kfunc/tailcall/exit/back-edge
- no memory writes
- no memory reads inside the region for v1
- all live-ins are scalar registers
- exactly one live-out BPF register
- any original stack spill/fill removed by the region is dead outside the region
- replacement must not cross subprogram boundaries and must reuse existing branch fixup checks

## 6. Recommendation

Classification: ⏸ 后续 phase（等 kinsn v3 / region ABI 收敛）

Region kinsn is not "do not do"; Cilium and Calico show legitimate hash/mix targets, and the object census shows many
high-pressure scalar-ish blocks. But the mechanism is bigger than a normal single-operation kinsn. It needs a region ABI,
native scratch-register policy, proof-lowering shape, and bpfopt live-in/live-out validation before it is safe to put in
the benchmark pipeline.

Recommended next phase:

1. Define a first-class region descriptor rather than a generic "arbitrary BPF snippet" payload.
2. Implement one pure scalar target, preferably `jhash_final32` or a byte-pack region with one output.
3. Add a corpus/profiler gate so only hot regions are considered.
4. Keep effect-signature and memory-writing regions out of the first version.
