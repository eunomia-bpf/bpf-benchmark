# Kinsn: A New OS Abstraction for Bringing eBPF Closer to Hardware

Status: research direction · paper-line hub for idea #2

> 本文档是 Kinsn 论文线索的单一 hub。详细机制设计见 `docs/kinsn-design.md`,
> 形式化语义见 `docs/kinsn-formal-semantics.md`,工程实现细节见各 pass 的
> `docs/tmp/*kinsn*` 调研报告。

## Project Context: Three Sister Ideas

This research project produces three distinct papers that share a single
evaluation setup (the `bpf-benchmark` corpus, micro suite, and measurement
infrastructure) but address different problems with different designs.

| # | Idea | Hub doc |
|---|---|---|
| 1 | Speculative eBPF optimization (pure userspace) | `docs/rejit-speculative-optimization-ebpf.md` |
| 2 | **Kinsn** (this doc) — new OS abstraction, bring eBPF close to hardware | `docs/kinsn-idea.md` |
| 3 | ReverseJIT / ReverseInterpreter (x86/arm interpreter in eBPF) | `docs/reverse-jit.md` |

The three ideas are not incremental versions of one design. Each picks a
different problem, a different point in the trust / kernel-surface / coverage
space, and a different design center.

## 1. Problem

The eBPF instruction set is intentionally minimal: load/store, ALU, compare,
branch, call, exit, plus a few packet-specific instructions. This minimalism
keeps the kernel verifier tractable and the JIT small, but it leaves several
classes of native-hardware-level optimization unreachable from inside eBPF
programs:

- **Rotate** (`RORX`/`ROR`): hash and crypto-style loops emit `(x << n) | (x >> (64-n))`
  which the kernel JIT cannot fuse into a single hardware rotate.
- **Conditional select** (`CMOV`/`CSEL`): branchless selection is unavailable;
  BPF emits a branch+mov sequence that costs more on predictable inputs and
  loses to a branch on unpredictable inputs.
- **Bitfield extract** (`BEXTR`/`UBFX`): bit-packed protocol parsing emits
  `shift+and` sequences instead of a single hardware extract.
- **Endian fusion** (`MOVBE`): load+byte-swap is two instructions instead of
  one.
- **Wide load/store pair** (`LDP`/`STP` on arm64): adjacent 64-bit loads or
  stores cannot be paired into a single 128-bit memory op.
- **Bulk memory** (`rep movsb` on x86, `LDP/STP` chain on arm64): inline
  memcpy/memset cannot use ISA-specific bulk paths.
- **Prefetch** (`PREFETCHT0`/`PRFM`): no way to hint the cache for a coming
  memory access.
- **Conditional compare chain** (`CCMP` on arm64): chained comparison cannot be
  collapsed into the arm64-specific compare-then-conditional-compare form.

Implementing each of these as a kernel-JIT peephole would require many small
patches, each going through upstream review, each adding kernel surface that
must be maintained for every supported architecture. The cumulative kernel
churn is high and the upstream cycle is slow.

## 2. Idea

**Kinsn** (kernel instruction) is a new OS abstraction that lets the kernel
expose hardware-specific instruction primitives to eBPF programs without
extending the core eBPF instruction set and without per-feature verifier or
JIT patches.

Each kinsn is a **dual-semantics primitive**:

- **Verifier semantics**: a declarative effect (`bpf_kinsn_effect`) describing
  the operation's clobber mask, result range, tnum, sub-register definition,
  and memory accesses. The kernel verifier applies this effect to the abstract
  state and checks the result with its existing rules.
- **Execution semantics**: a per-architecture `emit_x86()` / `emit_arm64()`
  callback that emits the native instruction sequence during JIT.

Kinsns are implemented as a specialization of the existing kfunc mechanism
with a new `KF_KINSN` flag and an attached `bpf_kinsn_ops` table. The verifier
reuses `check_kfunc_call()` with zero changes for the per-kinsn case; the JIT
checks `KF_KINSN` at CALL-emit time and dispatches to the module-provided emit
callback instead of generating a function call.

New optimization = new kinsn definition in a small kernel module + a userspace
pattern recognizer (in `bpfopt`) that rewrites matching BPF bytecode to call
the kinsn. **Zero changes to the core kernel verifier, JIT, or BPF ISA per new
optimization.**

## 3. Why This Is A New Abstraction, Not Another Peephole

Three properties separate kinsn from in-kernel peephole optimizations:

1. **Policy vs. mechanism separation**. The kernel module supplies the
   mechanism (what the instruction does, how the verifier should model it, how
   the JIT should emit it). Userspace `bpfopt` supplies the policy (which
   patterns to rewrite, what cost model to use, when a kinsn is worth
   inserting). Mechanism is small and fixed; policy is rich and iterable.

2. **No core kernel patch per optimization**. The core kernel JIT and verifier
   are untouched. Adding a new kinsn is a module change plus an external
   bytecode-rewrite pass. The upstream cycle is one-time (for the kinsn
   framework itself), not per-feature.

3. **Workload-adaptive insertion**. Whether a kinsn helps depends on workload
   characteristics (branch predictability for CMOV, hot/missy memory access
   for prefetch, register pressure for LDP/STP). A userspace optimizer with
   runtime profile data picks insertion sites better than any static kernel
   heuristic.

The combination produces a new OS abstraction: **a kernel-defined, verifier-
modeled, JIT-emitted, module-implemented instruction extension surface for
eBPF**.

## 4. Mechanism Sketch

Detailed mechanism design lives in `docs/kinsn-design.md`. Brief sketch:

- `struct bpf_kinsn_ops` holds the module callbacks:
  - `model_call(call, effect)`: produce a declarative `bpf_kinsn_effect` the
    verifier applies to abstract state.
  - `decode_call(call)` / `validate_call(call)`: decode encoded operands and
    check well-formedness.
  - `emit_x86(call, ctx)` / `emit_arm64(call, ctx)`: emit native code at JIT
    time.
- `KF_KINSN` is a new kfunc flag (mutually exclusive with KF_ACQUIRE /
  KF_RELEASE / KF_SLEEPABLE).
- Packed encoding: a sidecar pseudo-instruction (`BPF_PSEUDO_KINSN_SIDECAR`)
  immediately preceding the kinsn `BPF_CALL` carries operand bits. The verifier
  decodes the sidecar before applying the modeled effect. Zero-argument-setup,
  N→1 instruction replacement.
- Module lifetime: standard Linux module load/unload. When a kinsn module is
  not loaded, the verifier rejects programs that reference its kfuncs, and the
  JIT never sees them. When unloaded after programs are loaded, in-flight
  programs continue executing the already-emitted native code.

Formal semantics: `docs/kinsn-formal-semantics.md`.

## 5. Coverage And Decisions

The kinsn surface is intentionally bounded. Coverage decisions are driven by
corpus evidence: a candidate kinsn is added only when the supported runtime
corpus has enough sites to justify the kernel module surface and a measurable
performance win at the inserted sites.

**Implemented kinsns** (default policy on the corresponding architecture):

| Kinsn | Arch | Status | Headline site evidence |
|---|---|---|---|
| `bpf_rotate64` | x86 / arm64 | shipped | 701 sites |
| `bpf_select64` (CMOV/CSEL) | x86 / arm64 | shipped, policy-sensitive | corpus applied |
| `bpf_extract64` (BEXTR/UBFX) | x86 / arm64 | shipped | 524 sites |
| `bpf_endian` (MOVBE / rev16/32/64) | x86 / arm64 | shipped | 256 sites |
| `bpf_ldp128` / `bpf_stp128` | arm64 | shipped (arm64 only) | many adjacent-pair sites |
| `bpf_bulk_memory` | x86 / arm64 | shipped | corpus 40B/74B/360B/464B runs |
| `bpf_ccmp` | arm64 | designed (first wave) | 4957 sites, 6228 saved branches |
| `bpf_prefetch` | x86 / arm64 | shipped, default pass | 17391 map_lookup deref sites |
| `bpf_lea` | x86 only | experimental | adjacent MOV+ADD sites |

**Explicitly not pursued** (with rationale; details in respective research
reports under `docs/tmp/`):

| Candidate | Reason |
|---|---|
| POPCNT / CLZ / CTZ | Corpus has 0 supportable sites. |
| CRC32 | Broad coverage low; loxilb-only path. |
| PDEP / PEXT | 0 corpus sites. |
| SHRX / SHLX | No incremental win on OoO CPUs. |
| MADD / MSUB | MSUB 0 direct sites; MADD low priority. |
| RDTSC / RDTSCP | Semantics not portable for transparent rewrite. |
| ADC / SBB | 0 carry-chain sites in 917 .bpf.o. |
| SETcc / CSET | Designed but not yet implemented; 9417 sites; queue. |
| ANDN | 0 strict 3-insn sites; all real hits need liveness proof. |
| BLSI / BLSR / BLSMSK | 0 sites in supported apps. |
| PAUSE / YIELD | Kernel spinlock helper already PAUSE/WFE inside. |
| FPU SIMD | Per-call FPU context cost exceeds expected gain at corpus byte sizes. |
| NT store | No streaming-write pattern in corpus. |

Decision rule: a new kinsn must have non-trivial supported-corpus site count
(rough floor: hundreds), an isolable performance win at the inserted sites
larger than the I-cache and verifier-rerun cost of insertion, and a
verifier-friendly declarative effect. Without all three, the proposal stays
in the "not pursued" bucket.

## 6. Relation To The Other Two Ideas

### Idea #1 — Speculative eBPF optimization

Both ideas share `bpfopt` as the userspace rewrite tool and the
`bpfrejit-daemon` as the orchestrator. They differ in what passes the daemon
runs and what kernel facilities those passes require.

- Idea #1's default pipeline is BPF-to-BPF rewrites only (`map_inline`,
  `const_prop`, `dce`, `bounds_check_merge`, `branch_flip`, ...). It requires
  near-zero kernel changes.
- Idea #2's pipeline can include kinsn-introducing passes (`rotate`,
  `cond_select`, `extract`, `endian_fusion`, `prefetch`, ...). These require
  the kinsn framework patch in the kernel plus per-arch kinsn modules.

A kernel that ships idea #2 strictly contains a kernel that ships only idea
#1. The two pipelines compose: a deployment that wants both runs the union of
their passes. But the papers separate them because the contributions are
distinct (userspace mechanism vs. kernel abstraction).

### Idea #3 — ReverseJIT / ReverseInterpreter

Idea #2 and idea #3 attack the same underlying question — how to make
non-trivial native operations available inside the eBPF safety model — from
opposite ends:

- Kinsn extends the kernel-side instruction set with kernel-defined
  dual-semantics primitives. Each new primitive grows the kernel TCB by a
  small amount.
- ReverseInterpreter extends the userspace-side lowering with a verified
  interpreter or JIT. The kernel stays unchanged. The added TCB is a userspace
  artifact: one C file per target ISA.

Kinsn covers a handful of patterns ordinary eBPF cannot express well.
ReverseInterpreter covers anything the target ISA can express, subject to
verifier-tractable lowering. The two are not exclusive: a kinsn-aware kernel
combined with a ReverseInterpreter that emits kinsns where helpful is a
natural ablation point, but neither requires the other.

## 7. Paper Framing

Possible title:

```text
Kinsn: A Hardware-Aware Instruction Extension Surface for eBPF
```

Central systems claim:

```text
Kinsn introduces a new kernel abstraction that lets eBPF programs use
platform-specific hardware instructions safely. The verifier checks each
kinsn through a declarative effect supplied by a kernel module; the JIT
emits the native instruction sequence via the same module. New instructions
are added without modifying the core verifier, the core JIT, or the eBPF
ISA, and a userspace optimizer chooses insertion sites based on workload
profile data.
```

A strong evaluation needs to show:

- broad kinsn coverage (rotate / cond_select / extract / endian / prefetch /
  pair load-store / bulk memory at minimum), not a single primitive;
- real eBPF programs (Cilium / Katran / Tetragon / Tracee / BCC / bpftrace /
  loxilb), not only microbenchmarks;
- workload-adaptive insertion outperforming fixed kernel heuristics on at
  least one policy-sensitive kinsn (CMOV is the canonical example);
- small and understandable kernel surface (the framework patch);
- module-level isolation (loading or unloading a kinsn module does not
  affect unrelated programs);
- arm64 results, not only x86, to validate the per-arch abstraction.

## 8. Related Work Positioning

- **kfuncs (existing upstream)**: kinsn is implemented as a specialization
  of kfuncs (KF_KINSN). The contribution is the dual-semantics emit path,
  not the BTF or registration machinery.
- **JIT peepholes**: per-architecture peepholes in core JIT (e.g., upstream
  arm64 LDP fusion). Kinsn pushes the same capability behind a module
  boundary so additions do not touch the core JIT.
- **JVM intrinsics**: HotSpot intrinsics replace standard library calls with
  hand-coded native sequences chosen by the JIT. Kinsn is the same idea
  applied to eBPF, with the verifier modeling the intrinsic's effect
  declaratively.
- **K2 / Merlin / EPSO**: BPF bytecode optimizers operating pre-load on
  source `.bpf.o`. They do not extend the BPF ISA and cannot emit native
  instructions outside the standard JIT vocabulary. Kinsn complements them
  by widening the emit vocabulary.

## 9. Main Risks

- Each new kinsn adds a small piece of kernel surface (module callbacks,
  declarative effect, JIT emit). The total surface scales with the number of
  kinsns, and the audit cost compounds.
- A declarative effect that does not faithfully model the native emit
  silently violates verifier soundness for any program using that kinsn. The
  per-kinsn formal-semantics doc and translation-validation work
  (`docs/kinsn-formal-semantics.md`) is the mitigation.
- Workload-adaptive insertion requires reliable per-site profile data. Idea
  #1's `bpfprof --per-site` pipeline is the source; if PMU data is
  unreliable on a deployment, policy-sensitive kinsns must fall back to a
  conservative default rather than guess.
- Some natural-looking kinsns (FPU SIMD, RDTSC) cannot be added without
  either changing semantics (RDTSC not monotonic) or paying setup costs that
  exceed the gain (FPU context save). The decision rule in §5 keeps these
  out of the surface.

## 10. Cross-References

- Mechanism design: `docs/kinsn-design.md`
- Formal semantics and translation validation: `docs/kinsn-formal-semantics.md`
- `bpf_kinsn_ops` detailed design: `docs/tmp/20260323/kinsn_ops_design_20260323.md`
- Implementation audit: `docs/tmp/20260323/kinsn_implementation_review_20260323.md`
- Per-kinsn research and decisions: `docs/tmp/*kinsn*` (rotate, cond_select,
  extract, endian, prefetch, ccmp, lea, bls, andn, setcc_cset, simd_fpu,
  bulk_memory, ldp_stp, register_realloc, region_kinsn, ...)
- Speculative-optimization sibling paper: `docs/rejit-speculative-optimization-ebpf.md`
- ReverseJIT sibling paper: `docs/reverse-jit.md`
