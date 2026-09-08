# Native-simulator formal model

This directory contains the first machine-checked refinement slice shared by
the x86-64 and AArch64 native simulators. Run it with:

```sh
make check
```

`KProgFormal.TagErasure` models four operations used by both simulators: a
64-bit move, a pointer-shaped 64-bit add-immediate, a scalarizing integer
multiply-immediate, and a 64-bit load of the packet or packet-end pointer from
the simulator entry ABI. It proves for any sequence of those operations that:

1. erasing verifier-facing provenance tags yields the same bits as a pure
   modulo-2^64 architectural execution; and
2. tag transitions follow a separately declared provenance policy.

This is a deliberately bounded proof. It does not establish equivalence
between the model and the current C macro implementations, cover memory,
branches, helpers, or the full workload-derived instruction subsets, or prove
the paper's complete O1--O4 obligations. The next mechanization step is to
derive the C and Lean transition descriptions from a shared declarative table
so that the model cannot silently drift from the implementation.
