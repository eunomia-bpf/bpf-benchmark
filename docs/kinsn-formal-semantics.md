# Formal Model of Current kinsn Instances

Date: 2026-03-26  
Status: current in-tree formalization  
Scope: current in-tree kinsn descriptors and the site conditions required by the current rewrite pipeline

## 0. Why a separate formal model

[`docs/kinsn-design.md`](./kinsn-design.md) explains the implementation boundary.
This file makes the current semantics explicit enough to reason about:

- what a kinsn "is" in the current tree
- what the proof sequence means
- what each in-tree descriptor means
- which extra site conditions are required for native emit to be a valid refinement

The important distinction is:

- `instantiate_insn()` defines the verifier-visible proof object
- native emit defines an architecture-specific refinement of that proof object
- some refinements are valid only under additional site conditions supplied by
  the daemon rewrite passes

## 1. Core Model

### 1.1 State

We model the local architectural BPF state as:

```text
State = (R, M)
```

where:

- `R : {r0, ..., r10} -> u64` is the BPF register file
- `M` is the byte-addressable memory visible to the program

We write register update as:

```text
R[x <- v]
```

and functional composition on states as usual.

This model is intentionally architectural. It does not attempt to encode
microarchitectural speculation state. That matters for `speculation_barrier`
and is modeled separately below.

**Register encoding convention.** Payload fields that name registers use 4 bits,
encoding values 0–15. Only values 0–10 (corresponding to BPF `r0`–`r10`) are
valid; the remaining codes are reserved and rejected by module decoders.

### 1.2 Proof semantics

For a descriptor `K` and payload `p`, let:

```text
Inst_K(p) = instantiate_insn_K(p)
```

when decoding succeeds.

The verifier-visible denotation of a kinsn site is:

```text
[[K, p]]_proof = Exec_BPF(Inst_K(p))
```

where `Exec_BPF` is the standard BPF instruction-set semantics: a step function
over `(PC, R, M)` that starts at the beginning of the proof sequence and
terminates when `PC` advances past its end. We take this as given from the
kernel BPF specification and do not re-derive it here.

`Exec_BPF` is a partial function: memory-accessing instructions (e.g.,
`BPF_LDX_MEM` in `endian_load` proof sequences) are only defined when the
verifier's abstract state proves the access is safe (valid pointer kind,
in-bounds offset, correct alignment). We write `VerifierSafe(σ, site)` for the
predicate "the verifier abstract state `σ` at `site` proves all memory accesses
in the proof sequence are legal." This condition is established by the standard
verifier analysis on the lowered program and is a precondition for both the
proof semantics and the local refinement below.

This is the semantics the verifier actually reasons about after
`lower_kinsn_proof_regions()`.

### 1.3 Observable state projection

A kinsn site `s` in a BPF program occupies a contiguous, single-entry
single-exit region. Let `LiveOut(s)` be the set of registers live on exit from
the site (read by some reachable successor before being written).

The observable projection for site `s` is:

```text
π_s(R, M) = (R|_{LiveOut(s)}, M)
```

This projection is the formal reason some proof-sequence side effects are
invisible: if a proof sequence clobbers register `t` but `t ∉ LiveOut(s)`,
then the clobber does not affect the observable state.

### 1.4 Local refinement

For architecture `a ∈ {x86, arm64}`, let `Emit_K^a(p)` be the machine code
emitted by `emit_x86` or `emit_arm64`, when the callback exists and succeeds.

**Definition (Local Refinement).** Native emit for descriptor `K` at site `s`
with payload `p` is a correct local refinement when:

```text
π_s(Exec_a(Emit_K^a(p), (R, M))) = π_s(Exec_BPF(Inst_K(p), (R, M)))
```

for every initial state `(R, M)` satisfying:

1. `Valid_K(p)` — payload well-formedness (checked by the module decoder)
2. `Admissible_K^a(s, p)` — site conditions required for native emit
3. `VerifierSafe(σ, s)` — the verifier abstract state proves all proof-sequence
   memory accesses are safe (only relevant for memory-accessing instances like
   `endian_load`)

**Implementation assumptions.** The local refinement definition implicitly
requires:

- **Emit purity**: `emit_x86(p, prog)` and `emit_arm64(p, prog)` are
  deterministic pure functions of `(p, prog)`. All current in-tree callbacks
  ignore the `prog` argument and depend only on the payload. This ensures the
  sizing pass and emit pass produce identical code lengths.
- **Proof-sequence locality**: current proof sequences do not use stack writes,
  function calls, or global memory writes; they only compute on registers (and
  read memory for `endian_load`).

Each in-tree instance thus has three formal pieces:

- `Valid_K(p)`: payload structure and range checks
- `Proof_K(p)`: full proof-sequence state transformer
- `Admissible_K^a(s, p)`: extra conditions the daemon rewrite pipeline enforces
  before emitting a kinsn site (not checked by the kernel verifier)

### 1.5 Program phases and whole-program refinement

The verifier/JIT pipeline transforms a program through several phases. Using
the same names as the implementation:

```text
P_src       original program with sidecar + BPF_PSEUDO_KINSN_CALL pairs
    │  lower_kinsn_proof_regions()
    ▼
P_low       proof sequences substituted; this is what the verifier analyzes
    │  verifier analysis (CFG, liveness, abstract interpretation)
    ▼
P_low_ok    verified: all proof sequences are safe
    │  restore_kinsn_proof_regions()
    ▼
P_restored  original sidecar + kinsn_call pairs restored
    │  do_misc_fixups()
    ▼
P_fix       sites with native emit retained; sites without → lowered to BPF
    │  arch JIT
    ▼
P_jit       native machine code; kinsn sites compiled via emit callbacks
```

**Scope.** This formalization proves that `P_jit` refines `P_low` — that is,
native emit at each kinsn site produces the same observable result as the
proof sequence the verifier analyzed. It does **not** prove that the daemon's
rewrite from an original BPF idiom to a kinsn site is semantics-preserving;
that is a separate engineering argument in the daemon rewrite passes.

**Theorem (Whole-Program Refinement).** Let `P_low` be the lowered program
accepted by the verifier, containing `n` proof-sequence regions corresponding
to kinsn sites `s_1, …, s_n` in `P_src`. Let `P_jit` be the JIT-compiled
program where each retained site uses native emit. If for every site
`s_i = (K_i, p_i)`:

1. `Valid_{K_i}(p_i)` holds,
2. `Admissible_{K_i}^a(s_i, p_i)` holds,
3. `VerifierSafe(σ_i, s_i)` holds (for memory-accessing instances),
4. local refinement holds for `(K_i, p_i, s_i)`,

then for all initial states accepted by the verifier:

```text
Exec(P_jit, σ_0)|_{r0, M} = Exec(P_low, σ_0)|_{r0, M}
```

**Proof sketch.** We argue by trace simulation on execution steps, not by
structural induction on a topological order (BPF programs may contain bounded
loops, so kinsn sites can execute more than once).

Consider an execution trace `τ` of `P_low`. Each time the trace enters a
proof-sequence region for site `s_i`, it executes the instantiated BPF
instructions and exits with state `(R', M')`. In `P_jit`, the same trace
position instead executes `Emit_{K_i}^a(p_i)`. By local refinement (§1.4),
the two executions agree on `π_{s_i}(R', M')` — that is, on every register
in `LiveOut(s_i)` and on all of `M`.

Between kinsn sites, `P_jit` and `P_low` execute identical BPF instructions,
so their states remain synchronized. Since kinsn sites are non-overlapping and
single-entry single-exit (no backward jumps within a proof sequence, enforced
by `validate_kinsn_proof_seq()`), every inter-site segment sees identical
input state. By induction on the number of site entries in the trace, the
final program state agrees on `{r0} ∪ M`.

### 1.6 Failure modes

`instantiate_insn(p)` and native emit callbacks may fail (return negative).
The current tree handles failures as follows:

| Failure | Phase | Consequence |
|---------|-------|-------------|
| `instantiate_insn` returns error | `lower_kinsn_proof_regions()` | Verifier rejects the program |
| Native emit callback missing for arch | `do_misc_fixups()` | Transparent fallback: site rewritten to instantiated BPF |
| Native emit returns error at JIT time | JIT compilation | JIT compilation fails; program is rejected |

**Important:** the BPF interpreter does not understand `BPF_PSEUDO_KINSN_CALL`.
After `restore_kinsn_proof_regions()`, the program contains raw kinsn encodings
that only the arch JIT can execute. There is no late interpreter fallback for
kinsn programs. If JIT compilation fails for a program with retained kinsn
sites, the program cannot run — it is rejected at load time. This is enforced
by requiring `jit_requested` for programs containing kinsn sites.

The `do_misc_fixups()` path provides the only safe fallback: if no native emit
callback exists for the running architecture, the site is rewritten back to
instantiated BPF before JIT, so the resulting program contains only ordinary
BPF instructions.

**Two-pass consistency.** The arch JIT calls emit callbacks twice: once for
sizing (`emit = false`) and once for code generation (`emit = true`). The emit
purity assumption (§1.4) ensures both passes produce the same code length.
Current in-tree callbacks are deterministic functions of `payload` alone.

## 2. Instance Set

The current in-tree descriptor set is:

- `bpf_rotate64`
- `bpf_select64`
- `bpf_extract64`
- `bpf_endian_load16`
- `bpf_endian_load32`
- `bpf_endian_load64`
- `bpf_speculation_barrier`

These come from:

- [`module/x86/`](../module/x86)
- [`module/arm64/`](../module/arm64)

## 3. Per-instance Definitions

### 3.1 `rotate64`

Source files:

- [`module/x86/bpf_rotate.c`](../module/x86/bpf_rotate.c)
- [`module/arm64/bpf_rotate.c`](../module/arm64/bpf_rotate.c)

Decoded payload:

```text
dst   = bits(payload, 0..3)
src   = bits(payload, 4..7)
shift = bits(payload, 8..15) mod 64
tmp   = bits(payload, 16..19)
```

Validity:

```text
dst, src, tmp in {r0, ..., r10}
tmp != dst
tmp != src
```

Helper:

```text
rol64(x, s) =
  if s = 0 then x
  else ((x << s) OR (x >> (64 - s))) mod 2^64
```

Full proof semantics:

```text
Proof_rotate(dst, src, tmp, s)(R, M) =
  if s = 0 then
    (R[dst <- R[src]], M)
  else
    (R[dst <- rol64(R[src], s),
       tmp <- (R[src] >> (64 - s))],
     M)
```

Abstract site contract used by the rewrite pipeline:

```text
Abs_rotate(dst, src, s)(R, M) =
  (R[dst <- rol64(R[src], s)], M)
```

Admissibility required by the current rewrite path:

```text
shift = 0  OR  tmp notin LiveOut(site)
```

Reason:

- when `shift ≠ 0`, the proof sequence clobbers `tmp` with `R[src] >> (64 - shift)`,
  but the native emitters compute the rotate directly without writing `tmp`
- when `shift = 0`, neither the proof sequence nor the native emitters write `tmp`
  (both reduce to `MOV dst, src`), so the `LiveOut` condition is not needed
- the daemon `rotate` pass only matches `shift ≠ 0` idioms in practice, so it
  always checks `tmp ∉ LiveOut(site)` before rewriting

So `rotate64` is formalized as:

- proof object semantics over full BPF state
- plus an admissible-site abstraction that quotients away `tmp`

### 3.2 `select64`

Source files:

- [`module/x86/bpf_select.c`](../module/x86/bpf_select.c)
- [`module/arm64/bpf_select.c`](../module/arm64/bpf_select.c)

Decoded payload:

```text
dst   = bits(payload, 0..3)
treg  = bits(payload, 4..7)
freg  = bits(payload, 8..11)
cond  = bits(payload, 12..15)
cc    = bits(payload, 16..19)     ; condition-code discriminator
```

Validity:

```text
dst, treg, freg, cond in {r0, ..., r10}
cc = KINSN_SELECT_COND_NEZ (= 0) ; only "not-equal-to-zero" is currently implemented
```

The `cc` field is a condition-code discriminator, not a reserved constant. The
current implementation defines only `KINSN_SELECT_COND_NEZ = 0` (select on
`cond ≠ 0`). The encoding space permits future condition codes (e.g., signed
comparison) without changing the transport format, but this formalization covers
only the current `NEZ` semantics.

Proof semantics (for `cc = NEZ`):

```text
Proof_select(dst, treg, freg, cond)(R, M) =
  if R[cond] != 0 then
    (R[dst <- R[treg]], M)
  else
    (R[dst <- R[freg]], M)
```

There is no additional hidden temporary register in the proof object. The x86
native emitter uses `TEST + CMOV` to refine this state transformer directly
without branches.

**Register aliasing note.** When `dst == cond` and `dst ∉ {treg, freg}`, the
x86 emit sequence must execute `TEST cond` before any `MOV dst, ...` that would
overwrite the condition register. The proof sequence is naturally correct
because `JEQ cond` evaluates before any `MOV dst`, but the native emit must
respect this ordering. The arm64 path (`TST` + `CSEL`) is inherently safe
because `TST` always precedes the single `CSEL` instruction.

### 3.3 `extract64`

Source files:

- [`module/x86/bpf_extract.c`](../module/x86/bpf_extract.c)
- [`module/arm64/bpf_extract.c`](../module/arm64/bpf_extract.c)

Decoded payload:

```text
dst   = bits(payload, 0..3)
start = bits(payload, 8..15)
len   = bits(payload, 16..23)
```

Note: this is an **in-place** operation — `dst` serves as both source and
destination. There is no separate source register; the value to extract from is
read from `R[dst]` and the result is written back to `R[dst]`.

Validity:

```text
dst in {r0, ..., r10}
0 <= start < 64
1 <= len <= 32
start + len <= 64
```

The `len ≤ 32` bound is a **proof-sequence encoding constraint**, not a
hardware limit. The BPF proof sequence uses `BPF_ALU_IMM(AND, dst, mask)` with
a 32-bit immediate; `mask(len)` for `len > 32` exceeds `s32` range and cannot
be encoded in a single BPF ALU instruction. The x86 native emit (`SHR` + `AND`)
could handle wider extractions, but the proof sequence cannot verify them.

Helper:

```text
mask(len) = 2^len - 1
```

Proof semantics:

```text
Proof_extract(dst, start, len)(R, M) =
  (R[dst <- ((R[dst] >> start) AND mask(len))], M)
```

For `len = 32`, the proof sequence uses `BPF_ALU_IMM(AND, dst, -1)` (32-bit
ALU), which masks with `0xffff_ffff` and zero-extends the result to 64 bits.

No admissibility conditions beyond `Valid` are required; the native x86 emit
(`SHR` + `AND`) and the proof sequence agree on the full destination register.

### 3.4 `endian_load16`, `endian_load32`, `endian_load64`

Source files:

- [`module/x86/bpf_endian.c`](../module/x86/bpf_endian.c)
- [`module/arm64/bpf_endian.c`](../module/arm64/bpf_endian.c)

Decoded payload:

```text
dst    = bits(payload, 0..3)
base   = bits(payload, 4..7)
offset = sign_extend_16(bits(payload, 8..23))
```

Validity:

```text
dst, base in {r0, ..., r10}
```

Let `addr = R[base] + offset`.

**Memory safety precondition.** The proof sequence contains a `BPF_LDX_MEM`
instruction. `load_n(M, addr)` is only defined when the verifier abstract state
proves: `R[base]` is a valid pointer kind (stack, map value, packet, etc.),
`addr` is within bounds, and the access size and alignment are legal. This is
captured by `VerifierSafe(σ, site)` (§1.2) and is a precondition for both the
proof semantics and the local refinement.

Let `load_n(M, addr)` be the value produced by the corresponding BPF
`LDX_MEM(size, dst, base, offset)` instruction, and let `bswap_n` be the BPF
byte-swap on `n` bits, zero-extended to 64 bits.

Proof semantics:

```text
Proof_endian_n(dst, base, offset)(R, M) =
  (R[dst <- bswap_n(load_n(M, R[base] + offset))], M)
```

for `n` in `{16, 32, 64}`.

Architecture notes:

- x86 native emit can directly encode all current `s16` offsets used by the
  descriptor payload
- arm64 native emit has a stricter direct-encoding domain
- the daemon `endian_fusion` pass compensates by materializing `base + offset`
  into a register and then emitting a packed kinsn call with offset `0` when
  needed

So the proof semantics domain is wider than the arm64 native-emit direct
encoding domain, but the rewrite pipeline reshapes sites to stay inside the
native domain.

### 3.5 `speculation_barrier`

Source files:

- [`module/x86/bpf_barrier.c`](../module/x86/bpf_barrier.c)
- [`module/arm64/bpf_barrier.c`](../module/arm64/bpf_barrier.c)

Decoded payload:

```text
payload = 0
```

Validity:

```text
payload = 0
```

Architectural proof semantics:

```text
Proof_barrier(R, M) = (R, M)
```

because the instantiated proof sequence is `BPF_JMP_A(0)`.

Additional architecture-specific fence contract:

- x86 native emit inserts `LFENCE`
- arm64 native emit inserts `DSB SY; ISB`

So `speculation_barrier` has:

- identity semantics at the architectural BPF-state level
- an additional microarchitectural ordering contract not expressible in plain
  BPF proof instructions

That is why the proof object is a no-op while the native emit is still useful.

## 4. What This Formalization Says About the Current System

### 4.1 Three layers of correctness

The full correctness story has three distinct layers. This formalization only
addresses layer (c):

| Layer | Claim | Status |
|-------|-------|--------|
| (a) Rewrite soundness | Daemon rewrite from BPF idiom to kinsn site preserves program semantics | Engineering argument in daemon passes; not formally modeled here |
| (b) Proof-sequence safety | Verifier accepts the lowered proof sequence, proving memory safety and type safety | Inherited from the standard BPF verifier; not re-proved here |
| (c) Native refinement | JIT native emit refines the verified proof sequence on observable state | **This is what the Whole-Program Refinement theorem (§1.5) proves** |

If all three hold, the end-to-end guarantee is: the JIT'd program with native
kinsn emit behaves identically to the original BPF program on all observable
state. But the formal model only covers (c); (a) and (b) are trusted.

### 4.2 Trusted computing base

The system's TCB is not self-contained within the kernel verifier. The
Whole-Program Refinement theorem's preconditions are discharged by different
components:

| Obligation | Enforced by | In TCB? |
|------------|-------------|---------|
| Proof-sequence structural safety | Kernel (`validate_kinsn_proof_seq`) | Yes |
| Proof-sequence semantic safety | Kernel (standard verifier on lowered program) | Yes |
| Payload validity (`Valid_K`) | Kernel module decoder | Yes |
| Emit purity and determinism | Implementation convention (not dynamically checked) | Yes |
| Site admissibility (`Admissible_K^a`) | **Daemon rewrite passes** | **Yes** |
| Rewrite soundness (layer a) | **Daemon rewrite passes** | **Yes** |

The daemon is in the TCB. If a daemon rewrite pass emits a kinsn site where
`Admissible` does not hold (e.g., `rotate64` with `tmp ∈ LiveOut(site)`), the
native emit may produce a semantically incorrect result. The kernel verifier
does **not** re-check admissibility conditions after REJIT.

However, a daemon bug cannot cause a kernel crash through kinsn alone: native
emit callbacks can only write to the JIT image buffer, not to arbitrary kernel
memory. The worst case is a semantically incorrect BPF program, not a kernel
exploit. (This assumes the module emit callbacks themselves are correct kernel
code.)

Concrete admissibility conditions:

- `rotate64`: `shift = 0 ∨ tmp ∉ LiveOut(site)` — proof sequence clobbers
  `tmp` but native ROL does not
- `select64` on x86: `TEST cond` must execute before any `MOV dst` that could
  alias `cond` — enforced by emit ordering in `emit_select_x86`
- `endian_load*` on arm64: offset must be in the native emitter's direct
  encoding domain, or the daemon must first materialize an adjusted base with
  offset zero

### 4.3 Barrier: native emit is strictly stronger than proof

`speculation_barrier` demonstrates why the refinement relation is directional.
The proof sequence is a BPF no-op (`BPF_JMP_A(0)`), so:

```text
Proof_barrier(R, M) = (R, M)       ; identity on architectural state
```

The native emitters add a real fence (`LFENCE` on x86, `DSB SY; ISB` on
arm64). This is strictly stronger than the proof: it preserves the same
architectural state *and* provides an additional microarchitectural ordering
guarantee not expressible in BPF proof instructions.

Local refinement still holds because identity is trivially refined by any
state-preserving transformation. The extra fence guarantee is a bonus that the
formal model acknowledges but does not attempt to encode in the BPF state
model.

**Scope limitation.** The formal model only claims architectural state
preservation for `speculation_barrier`. Any Spectre-style security argument
requires a microarchitectural execution model that this formalization does
not provide.

### 4.4 What this formalization is and is not

This is a **semi-formal specification with a proof sketch** — not a
mechanically verified proof. It is closer to the style of Jitk (OSDI '14)
§3's pen-and-paper argument than to CertiKOS or seL4's Coq/Isabelle proofs.

What it provides:

- precise per-instance semantics cross-referenced against module source code
- a clear statement of what "native emit refines proof sequence" means
- an explicit enumeration of trusted assumptions and TCB components

What it does not provide:

- a machine-checked proof
- a formal model of the BPF verifier's abstract state
- a formal proof of daemon rewrite soundness (layer a)
