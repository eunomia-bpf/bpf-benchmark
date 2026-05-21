# Kinsn: A New OS Abstraction for Bringing eBPF Closer to Hardware

Status: research direction · paper-line hub for idea #2

> 本文档是 Kinsn 论文线索的单一 hub。详细机制设计见 `docs/tmp/kinsn-design.md`,
> 形式化语义见 `docs/tmp/kinsn-formal-semantics.md`,工程实现细节见各 pass 的
> `docs/tmp/*kinsn*` 调研报告。

## Project Context: Three Sister Ideas

This research project produces three distinct papers that share a single
evaluation setup (the `bpf-benchmark` corpus, micro suite, and measurement
infrastructure) but address different problems with different designs.

| # | Idea | Hub doc |
|---|---|---|
| 1 | Speculative eBPF optimization (pure userspace) | `docs/rejit-speculative-optimization-ebpf_idea.md` |
| 2 | **Kinsn** (this doc) — new OS abstraction, bring eBPF close to hardware | `docs/kinsn_idea.md` |
| 3 | ReverseSim (x86/arm native simulator in eBPF) | `docs/reverse-sim_idea.md` |

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

Detailed mechanism design lives in `docs/tmp/kinsn-design.md`. Brief sketch:

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

Formal semantics: `docs/tmp/kinsn-formal-semantics.md`.

### 4.1 Kernel source touchpoints (rejit-v2 branch / kinsn subset)

The kinsn subset of the `vendor/linux-framework/rejit-v2` branch — i.e. the
kinsn-only kernel surface — touches the following files. (REJIT-specific
files belong to the orthogonal speculative-optimization line and are
intentionally excluded from this paper; see `docs/reverse-sim_idea.md` discussion
of the kernel-ABI variant and `docs/kinsn-only` branch in the kernel
worktree.)

| 文件 | 职责 |
|------|------|
| `include/linux/bpf.h` | `bpf_kinsn_ops` / `bpf_kinsn_effect` / `bpf_kinsn_call` structs, registration API |
| `include/linux/bpf_verifier.h` | kinsn verifier helper structs |
| `include/linux/btf.h` | `KF_KINSN` flag |
| `include/uapi/linux/bpf.h` + `tools/include/uapi/linux/bpf.h` | `BPF_PSEUDO_KINSN_SIDECAR` + `BPF_PSEUDO_KINSN_CALL` enum extensions |
| `kernel/bpf/btf.c` | kinsn BTF id resolution |
| `kernel/bpf/verifier.c` | kinsn registration / lookup, `model_call` verifier flow, sidecar decode |
| `kernel/bpf/disasm.c` | kinsn disasm support |
| `arch/x86/net/bpf_jit_comp.c` | x86 JIT CALL-case kinsn inline dispatch |
| `arch/arm64/net/bpf_jit_comp.c` | arm64 JIT kinsn inline dispatch |

Net diff size (kinsn-only branch on top of stock 7.0-rc baseline):
**+869 / -101 LOC across 10 files**(零 REJIT 引用,纯 kinsn surface)。

## 5. Coverage And Decisions

The kinsn surface is intentionally bounded. Coverage decisions are driven by
corpus evidence: a candidate kinsn is added only when the supported runtime
corpus has enough sites to justify the kernel module surface and a measurable
performance win at the inserted sites.

**Implemented kinsns** (default policy on the corresponding architecture):

| Kinsn | Arch | Status | Site evidence | Design / research refs |
|---|---|---|---|---|
| `bpf_rotate64` | x86 / arm64 | shipped | 701 sites, 15 applied (shift+or → RORX) | — |
| `bpf_select64` (CMOV/CSEL) | x86 / arm64 | shipped, **policy-sensitive** | 12 corpus applied (branch+mov → CMOV) | policy: predictable input → CMOV slower; unpredictable → faster |
| `bpf_extract64` (BEXTR/UBFX) | x86 / arm64 | shipped | 524 sites, 4 applied (shift+and → BEXTR) | — |
| `bpf_endian` (MOVBE / rev16/32/64) | x86 / arm64 | shipped | 256 sites, 17 corpus applied (load+bswap → MOVBE) | — |
| `bpf_ldp128` / `bpf_stp128` | **arm64 only** | shipped | ARM64 corpus store-pair density high; current JIT 0 LDP/STP | `arm64_ldp_stp_kinsn_design_20260326.md`, `arm64_bpf_ldp_module_report_20260326.md`; x86 dispatched to `rep movsb` (see `x86_128bit_wide_loadstore_design_20260326.md`) |
| `bpf_bulk_memory` | x86 / arm64 | shipped | corpus 40 / 74 / 360 / 464 B 连续 copy/zero runs | `simd_kinsn_design_20260324.md`; x86 用 `rep movsb/stosb`,ARM64 用 LDP/STP,均 no-FPU |
| `bpf_ccmp` | arm64 | designed (first wave) | **4957 sites, 6228 saved branches** | `arm64_kinsn_research_20260329.md`;restricted first wave,避免通用变长 compare-chain |
| `bpf_prefetch` (PrefetchV2) | x86 / arm64 | shipped, default pass | 17391 `map_lookup_elem` + 21 `map_lookup_percpu_elem` 潜在 site;hot+missy site 预期 2.5-25ns/exec | `docs/tmp/p89_prefetchv2_impl.md`, `memory_hints_kinsn_research_20260329.md`, `prefetch_kinsn_design_20260329.md` |
| `bpf_lea{32,64}` | **x86 only** | experimental | Katran `lea` 122 applied, bytes 13629→13277, BPF counter ratio 1.0487 | `docs/tmp/lea_kinsn_design_census_20260513.md`(详 §5.1 scoped-down decision) |

**Explicitly not pursued / deferred** (with rationale + research refs):

| Candidate | Site evidence | Reason / research ref |
|---|---|---|
| POPCNT / CLZ / CTZ | 0 site | clang 已展开 `__builtin_popcount` 为高效位操作序列。`bit_ops_kinsn_research_20260329.md` |
| CRC32 | loxilb SCTP CRC32C: 2 个 byte-update site | broad corpus 覆盖低;若做,第一版 CRC32C-only no-FPU scalar backend + loxilb-targeted `step8/step64` idiom pass。`crc32_kinsn_research_20260329.md` |
| PDEP / PEXT | 0 site | corpus 无 site。`bit_ops_kinsn_research_20260329.md` |
| SHRX / SHLX | 0 incremental gain | OoO CPU 上无增量收益。`bit_ops_kinsn_research_20260329.md` |
| MADD / MSUB | MADD 47 direct sites;MSUB 0 direct sites | MADD 仅二级优化;MSUB 宽松形式需 liveness/semantic work,不进 first wave。`arm64_kinsn_research_20260329.md` |
| UBFX / BFI | UBFX 321 total / 74 with-copy;BFI 0 | UBFX 应扩展现有 `extract` pass 覆盖 copy form;BFI 0 site 不做。`arm64_kinsn_research_20260329.md` |
| RDTSC / RDTSCP | 不适合默认 | cycles 不是 portable monotonic ns;不适合 `bpf_ktime_get_ns()` 透明 rewrite;若做应显式 opt-in。`rdtsc_adc_kinsn_research_20260329.md` |
| ADC / SBB | 917 个 `.bpf.o` 扫描:add carry-chain 0、sub borrow-chain 0 | 短期不进默认 pipeline。`rdtsc_adc_kinsn_research_20260329.md` |
| SETcc / CSET | **supported runtime corpus 9417 sites**(Tetragon 8832、Cilium 401、Calico 91、BCC 79);raw census 28653 sites | 比较结果直接存 0/1,不需要 branch+mov。standalone boolean-set 不被现 `COND_SELECT` 覆盖,应独立 kinsn。**调研完成待实现**:`docs/tmp/setcc_cset_kinsn_research_20260430.md` |
| ANDN | 957 个 `.bpf.o` 扫描:去重后 45 sites(Tracee 30 + Cilium 14) | 全部需 liveness proof;热路径上限 ~1.0M site/s × 2 cycles ≈ 0.07% 单核增量。不做第一波。`docs/tmp/andn_kinsn_research_20260430.md` |
| BLSI / BLSR / BLSMSK | 957 个 `.bpf.o` 扫描:BLSI 3 + BLSR 3 + BLSMSK 0(全部来自已移除 scx_lavd_main);supported app 为 0 | 当前 8-app corpus 无 exact site,后续 phase。`docs/tmp/bls_kinsn_research_20260430.md` |
| PAUSE / YIELD | corpus 几乎无 BPF-level busy-wait | 内核 BPF spinlock helper 内部已有 PAUSE/WFE,kinsn 无增量价值。`pause_yield_kinsn_research_20260329.md` |
| FPU SIMD (x86) | x86 corpus 绝大多数 copy/store ≤128B,break-even ≥数百字节 | `kernel_fpu_begin/end` XSAVE/XRSTOR ~200-800 cycles,pair load/store 远超收益。`simd_fpu_kinsn_deep_research_20260326.md` |
| NEON SIMD (arm64) | 仅 ≥1KiB + `may_use_simd()` 可考虑 | no-FPU LDP/STP 优先;Linux crypto 模式(per-op fpu_begin/end)不适用于 BPF 细粒度调用。同上 |
| NT store | corpus 无明确 streaming write 场景 | 不值得。`memory_hints_kinsn_research_20260329.md` |
| Region kinsn(寄存器扩展) | Cilium/Calico Jenkins/hash 信号,Tetragon byte-pack/decoder;上界 census 24/1/175 clusters | 高寄存器压力代码段包装为 region kinsn。首版限定 pure scalar N→1 无内存/stack/packet/map 写、无 helper/call,等 kinsn v3 / region ABI 收敛。`docs/tmp/region_kinsn_research_20260430.md` |
| 除法强度削减(常量除数 → shift+mul) | 957 .bpf.o:DIV/MOD 共 1269 sites,K 812 / X 457;Cilium `/1e9` 占 553 | 纯 bytecode 需 64×64→128 mulhi emulation,先等 per-site profile 或 native mulhi/kinsn。`docs/tmp/division_reduction_research_20260430.md` |

Decision rule: a new kinsn must have non-trivial supported-corpus site count
(rough floor: hundreds), an isolable performance win at the inserted sites
larger than the I-cache and verifier-rerun cost of insertion, and a
verifier-friendly declarative effect. Without all three, the proposal stays
in the "not pursued" bucket.

### 5.1 LEA / address-generation scoped-down decision (2026-05-13)

详细 design doc: `docs/tmp/lea_kinsn_design_census_20260513.md`.

**Status**: implemented as an x86-only kinsn experiment. **Do not pursue
the core kernel-JIT peephole path** under the project no-core-JIT-change
policy. ARM64 does not implement LEA and should not advertise
`bpf_lea{32,64}`.

Combined census:

- Runtime `testbin`: strict non-overlap sites are **13,321 total** (Tracee
  6,405, Tetragon 6,363, OTEL 470, Cilium 79, Katran 4). Static-scalar
  first wave would be 10,922 sites across 4 apps. All strict runtime sites
  are plain pattern `a` (`MOV+ADD`); scaled-index, scaled+disp, and
  add-imm-chain are 0.
- Generated `testobject`: strict BPF sites are 6,999 total across all
  7 apps (6,995 pattern `a`, 4 pattern `b`, 0 pattern `c`, 0 pattern `d`).
- Native `testccode/*.x86.s`: 42,153 `lea` instructions, but 36,991 are
  simple base+disp address materialization. **BPF-object strict/native
  ratio is 16.6%**.
- Katran contradiction resolved: actual native Katran count is 225, while
  Katran BPF strict count is 4. The native richness is x86 address-mode
  materialization, not bytecode-level arithmetic LEA.

Implication: the remaining BPF-level opportunity is adjacent `MOV+ADD`.
A core JIT peephole would lower it most directly, but that path is ruled
out by the no-core-JIT-change policy. The implemented kinsn-only route
preserves that boundary and lets userspace own replacement policy. It
reduces final x86 instruction count/code size for matched sites, but the
dominant pattern remains 2 BPF slots after packed-sidecar replacement and
does not recover the native address-mode LEAs that motivated the
investigation. Treat LEA as **experimental** until post-hoc performance
evidence shows a runtime win.

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

### Idea #3 — ReverseSim

Idea #2 and idea #3 attack the same underlying question — how to make
non-trivial native operations available inside the eBPF safety model — from
opposite ends:

- Kinsn extends the kernel-side instruction set with kernel-defined
  dual-semantics primitives. Each new primitive grows the kernel TCB by a
  small amount.
- ReverseSim extends the userspace-side lowering with a verified
  simulator or JIT. The kernel stays unchanged. The added TCB is a userspace
  artifact: one C file per target ISA.

Kinsn covers a handful of patterns ordinary eBPF cannot express well.
ReverseSim covers anything the target ISA can express, subject to
verifier-tractable lowering. The two are not exclusive: a kinsn-aware kernel
combined with a ReverseSim that emits kinsns where helpful is a
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
  (`docs/tmp/kinsn-formal-semantics.md`) is the mitigation.
- Workload-adaptive insertion requires reliable per-site profile data. Idea
  #1's `bpfprof --per-site` pipeline is the source; if PMU data is
  unreliable on a deployment, policy-sensitive kinsns must fall back to a
  conservative default rather than guess.
- Some natural-looking kinsns (FPU SIMD, RDTSC) cannot be added without
  either changing semantics (RDTSC not monotonic) or paying setup costs that
  exceed the gain (FPU context save). The decision rule in §5 keeps these
  out of the surface.

## 10. Cross-References

- Mechanism design: `docs/tmp/kinsn-design.md`
- Formal semantics and translation validation: `docs/tmp/kinsn-formal-semantics.md`
- `bpf_kinsn_ops` detailed design: `docs/tmp/20260323/kinsn_ops_design_20260323.md`
- Implementation audit: `docs/tmp/20260323/kinsn_implementation_review_20260323.md`
- Per-kinsn research and decisions: `docs/tmp/*kinsn*` (rotate, cond_select,
  extract, endian, prefetch, ccmp, lea, bls, andn, setcc_cset, simd_fpu,
  bulk_memory, ldp_stp, register_realloc, region_kinsn, ...)
- Speculative-optimization sibling paper: `docs/rejit-speculative-optimization-ebpf_idea.md`
- ReverseSim sibling paper: `docs/reverse-sim_idea.md`
