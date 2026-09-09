# Native-simulator formal model

This directory contains the first machine-checked refinement slice shared by
the x86-64 and AArch64 native simulators. Run it with:

```sh
make check
```

`KProgFormal.TagErasure` models a bounded fragment drawn from the simulators:
a 64-bit move, a pointer-shaped 64-bit add, an x86-shaped scalarizing integer
multiply-immediate, and a 64-bit load of the packet or packet-end pointer from
the simulator entry ABI. It proves for any sequence of those abstract
operations that:

1. erasing verifier-facing provenance tags yields the same bits as a pure
   modulo-2^64 architectural execution; and
2. tag transitions follow a separately declared provenance policy.

The pointer-add transition is generated from `ptr_add_spec.json` into both the
Lean model and the C macro used by the x86-64 non-stack LEA and AArch64
non-scalar ADD handler branches. The entry-ABI provenance policy is likewise
generated from `abi_load_spec.json`: it distinguishes XDP from `__sk_buff`,
maps only the architecture-independent `data` and `data_end` offsets to packet
tags, and scalarizes all other 64-bit ABI loads. Compile-time assertions bind
those offsets to both C ABI structs, while the Lean theorem compares the
generated transition against an independently written tag specification.
The complete AArch64 condition-code table is generated from
`arm64_cond_spec.json` into the Lean model and the C branch handler. Lean proves
that all 15 supported predicates select the same next program counter as an
independent architectural condition specification, for either branch
direction.
The supported x86 condition-code table is likewise generated from
`x86_cond_spec.json` into the C simulator predicate and Lean. Lean proves the
same next-PC refinement for arbitrary flags and branch targets; parity
conditions are outside the accepted simulator subset.
The x86 logical-result flag transition is also generated into C and Lean. Its
composition theorem covers `CF=OF=0`, `ZF=zero`, and `SF=sign` through the
condition-to-next-PC decision. Width narrowing and the zero/sign observations
remain explicit trusted premises of this bounded step.
`make check` rejects stale generated outputs before checking the theorem. This
mechanically binds the pointer-add bits/tag policy and ABI-load offset/tag
policy, both ISA flag-to-control-flow decisions, and x86 logical flag
production after narrowing; other flag production, the decoder-to-handler
mapping, renderer, C compiler, and all other
operations remain in the trusted computing base.

This is still a deliberately bounded proof. It does not establish full
equivalence between the model and the C macro implementations, cover memory,
branches, helpers, or the full workload-derived instruction subsets, or prove
the paper's complete O1--O4 obligations. In particular, the multiply model is
x86-shaped, and the ABI-load model still abstracts away base-register identity,
width checks, and memory-boundary checks.
