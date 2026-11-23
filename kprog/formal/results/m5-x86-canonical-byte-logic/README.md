The same canonical Reference.X86.nativeStep and Reference.X86.step now
carry full-state equalities for XOR/OR/AND byte-register forms. Legal low/high
register slices, overlapping operands, either address mode and arbitrary
64-bit next PC share the imported checked execution. The result records
register and RFLAGS updates, exactly one AF oracle draw, PC advancement,
retained memory/XMM0/FS/GS/address mode and empty events/fault. Initial
modelError must be none.

CPU input and RFLAGS output are aliases of the existing canonical private
projection constants, accessed through Lean.mkPrivateNameCore. All16 input
GPR projections are checked against that original input. Native arithmetic
and flag meanings remain in the same imported ISA; reference source and
runtime bytes retain their definitions.

Focused174 jobs and five public type/axiom queries pass at original200000/512
budgets,j1,32GiB under shared timing. Retained diagnostics isolate a rewrite
matching issue using definitionally equal applications; an explicit local
projection closes the same full-state equation. Genuine source caller and
dispatcher composition remain next; complete instruction families remains0.
