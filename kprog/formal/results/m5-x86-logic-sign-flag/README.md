# Actual logical sign flag and shared native values

The original logical SF body executes its pointer read, unsigned shift,
mask, integer-to-byte conversion and store in4 steps for every64-bit word
and all four native widths. Its shift/AND payload equals the exact sign bit
in the shared x86lean `Value.msb`; the stored byte follows that same bit.
The actual original statement is retained by definitional equality.

Together with CF/OF/ZF/PF source-store proofs, `native_values` equates the
five produced bytes with one external x86lean logical-flags result for every
undefined-AF oracle choice. This is a value correspondence for the actual
width-truncated result; ordered heap/store composition and complete native
state/writeback remain the next steps.

Focused71 jobs and four public type/axiom queries pass at200000/512 budgets,
j1,32GiB under shared timing. Runtime, imported semantics and the single
external ISA specification retain their definitions. Latest whole confirmation
remains the DIV regression in `m5-xor-full-20261123`.
