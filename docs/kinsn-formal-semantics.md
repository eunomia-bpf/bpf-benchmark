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

where `Exec_BPF` means ordinary BPF execution of the instantiated proof
sequence, starting at the beginning of the sequence and finishing just past its
end.

This is the semantics the verifier actually reasons about after
`lower_kinsn_proof_regions()`.

### 1.3 Native refinement

For architecture `a` in `{x86, arm64}`, let `Emit_K^a(p)` be the machine code
emitted by `emit_x86` or `emit_arm64`, when that callback exists and succeeds.

Native emit is correct when it refines the proof semantics on the observable
architectural state of an admissible site:

```text
Proj_Obs(K, p, site)(Exec_a(Emit_K^a(p), s))
=
Proj_Obs(K, p, site)([[K, p]]_proof(s))
```

for every initial state `s` satisfying the instance validity predicate and the
site admissibility predicate.

So each in-tree instance has three pieces:

- `Valid_K(p)`: payload well-formedness checked by the module decoder
- `Proof_K(p)`: full proof-sequence semantics
- `Admissible_K^a(site, p)`: extra conditions needed by the rewrite/JIT path

The current tree does not encode all `Admissible_K^a` conditions in the kernel
verifier. Some are supplied by daemon passes.

### 1.4 Observability

For most instances below, the abstract result contract only cares about the
destination register and memory reads. But the proof sequence may still touch
other temporary registers.

This is the key reason to distinguish:

- the full proof semantics
- the abstract site contract used by the rewrite pipeline

The main example is `rotate64`: its proof sequence clobbers `tmp_reg`, while
the native emitters do not. Therefore the current rewrite pipeline requires
`tmp_reg` to be dead after the site.

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
kind  = bits(payload, 16..19)
```

Validity:

```text
dst, treg, freg, cond in {r0, ..., r10}
kind = 0            ; current implementation means "cond != 0"
```

Proof semantics:

```text
Proof_select(dst, treg, freg, cond)(R, M) =
  if R[cond] != 0 then
    (R[dst <- R[treg]], M)
  else
    (R[dst <- R[freg]], M)
```

There is no additional hidden temporary register in the proof object. The
native emitters are intended to refine this same state transformer directly.

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

Validity:

```text
dst in {r0, ..., r10}
0 <= start < 64
1 <= len <= 32
start + len <= 64
```

Helper:

```text
mask(len) = 2^len - 1
```

Proof semantics:

```text
Proof_extract(dst, start, len)(R, M) =
  (R[dst <- ((R[dst] >> start) AND mask(len))], M)
```

For `len = 32`, the implementation uses a 32-bit `AND -1`, which is equivalent
to masking with `0xffff_ffff` and zero-extending the result to 64 bits.

There is no additional site-side semantic precondition beyond ordinary rewrite
structural safety.

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

### 4.2 Not all correctness conditions live in the kernel today

The current in-tree design already relies on some site-level assumptions that
are enforced outside the kernel verifier:

- `rotate64`: `tmp_reg` must not be live after the site
- `endian_load*` on arm64: the rewritten site must use an offset that the
  native emitter can encode, or must first materialize an adjusted base

That does not make the model invalid. It just means the correct formal unit is
"descriptor semantics plus rewrite admissibility", not "descriptor semantics
alone".

### 4.3 Barrier is intentionally richer than its proof sequence

`speculation_barrier` shows why "formal semantics" has to separate:

- architectural BPF-state behavior
- extra non-functional execution guarantees

At the BPF-state level it is identity. At the execution-contract level it is a
real fence.
