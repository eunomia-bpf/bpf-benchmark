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

for every initial state `(R, M)` satisfying both:

- `Valid_K(p)` — payload well-formedness (checked by the module decoder)
- `Admissible_K^a(s, p)` — site conditions required for native emit

Each in-tree instance thus has three formal pieces:

- `Valid_K(p)`: payload structure and range checks
- `Proof_K(p)`: full proof-sequence state transformer
- `Admissible_K^a(s, p)`: extra conditions the daemon rewrite pipeline enforces
  before emitting a kinsn site (not checked by the kernel verifier)

### 1.5 Whole-program refinement

**Theorem (Whole-Program Refinement).** Let `P` be a BPF program accepted by
the verifier after proof lowering, containing kinsn sites `s_1, …, s_n`. If
for every site `s_i = (K_i, p_i)`:

1. `Valid_{K_i}(p_i)` holds (payload well-formed),
2. `Admissible_{K_i}^a(s_i, p_i)` holds (site conditions enforced by daemon),
3. local refinement holds for `(K_i, p_i, s_i)`,

then the JIT-compiled program `P_jit` and the verified lowered program `P_low`
produce the same observable result:

```text
P_jit(s_0)|_{r0, M} = P_low(s_0)|_{r0, M}
```

for all initial states `s_0` in the verifier-accepted domain.

**Proof sketch.** kinsn sites are non-overlapping, single-entry single-exit
regions in a program whose proof sequences contain no backward jumps (enforced
by `validate_kinsn_proof_seq()`). Each site's replacement preserves state on
`LiveOut(s_i)`, which is exactly what downstream code depends on. By structural
induction on the program's topological order, local refinement at each site
lifts to whole-program observational equivalence at program exit.

### 1.6 Failure modes

`instantiate_insn(p)` and native emit callbacks may fail (return negative).
The current tree handles failures as follows:

| Failure | Phase | Consequence |
|---------|-------|-------------|
| `instantiate_insn` returns error | `lower_kinsn_proof_regions()` | Verifier rejects the program |
| Native emit callback missing for arch | `do_misc_fixups()` | Transparent fallback: site rewritten to instantiated BPF |
| Native emit returns error at JIT time | JIT compilation | JIT fails; kernel falls back to BPF interpreter on the lowered program |

In all failure cases the system either rejects the program or falls back to the
verified proof sequence. No unverified native code is ever executed.

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
tmp notin LiveOut(site)
```

Reason:

- the proof sequence clobbers `tmp`
- current x86 and arm64 native emitters compute the rotate directly and do not
  write `tmp`
- the daemon `rotate` pass explicitly checks this liveness condition before
  rewriting

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
without branches. No admissibility conditions beyond `Valid` are required.

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
be encoded in a single BPF ALU instruction. The x86 `BEXTR` instruction itself
can handle wider extractions, but the proof sequence cannot verify them.

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

No admissibility conditions beyond `Valid` are required; the native x86 `BEXTR`
and the proof sequence agree on the full destination register.

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

### 4.1 kinsn is best modeled as a tuple

For the current tree, the clean formal object is:

```text
K = (Valid, Proof, Emit_x86, Emit_arm64, Admissible_x86, Admissible_arm64)
```

not just a single pure state transformer.

This is because the current system combines:

- a proof object used by the verifier
- an architecture-specific implementation object
- site-side rewrite obligations supplied by the daemon

The Whole-Program Refinement theorem (§1.5) ties these pieces together: given
payload validity, site admissibility, and per-site local refinement, the
JIT-compiled program is observationally equivalent to the verified lowered
program.

### 4.2 Split responsibility: kernel verifier + daemon

The correctness argument is not self-contained within the kernel. The current
system distributes obligations across two trust boundaries:

| Obligation | Enforced by |
|------------|-------------|
| Proof-sequence structural safety | Kernel (`validate_kinsn_proof_seq`) |
| Proof-sequence semantic safety | Kernel (standard verifier analysis on lowered program) |
| Payload validity (`Valid_K`) | Kernel module decoder |
| Site admissibility (`Admissible_K^a`) | Daemon rewrite passes |

Concrete admissibility conditions enforced by the daemon today:

- `rotate64`: `tmp ∉ LiveOut(site)` — the proof sequence clobbers `tmp` but
  native ROL does not
- `endian_load*` on arm64: offset must be in the native emitter's direct
  encoding domain, or the daemon must first materialize an adjusted base with
  offset zero

This split does not weaken the correctness guarantee: the Whole-Program
Refinement theorem holds regardless of *where* each predicate is checked, as
long as all predicates hold at JIT time.

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
