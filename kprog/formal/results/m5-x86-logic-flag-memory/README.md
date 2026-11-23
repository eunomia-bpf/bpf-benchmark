# Flag byte readback and preservation

Five actual ordered byte-store equations yield the exact five represented
native flag bytes in the final heap. Every earlier byte is preserved through
all later stores. Separation requires distinct block/offset addresses,
permitting flags in the same allocation at different byte offsets.

The byte-frame proof uses injectivity of unsigned pointer offsets and the
actual one-byte load/store disjointness condition. Readback includes the
actual unsigned-byte normalization for both Boolean values. `FlagsRepresent`
states exactly the five bytes in the source binding ABI; the supplied native
`X86.Flags` is the single target representation. Coupling this memory result
to the real31-step logical execution and shared logical values follows next.

Focused73 jobs and two public type/axiom queries pass at200000/512 budgets,
j1,32GiB under shared timing. Runtime and the single external ISA specification
retain their definitions. Latest whole confirmation remains the DIV regression
in `m5-xor-full-20261123`.
