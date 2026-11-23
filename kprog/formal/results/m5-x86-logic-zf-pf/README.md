# Actual logical zero and parity flag stores

The original logical ZF and PF bodies each execute in4 steps for every64-bit
input. ZF evaluates the actual equality-to-zero expression; PF executes the
actual nibble-fold and38505 lookup, including both shift bounds and integer
conversions. Each body reads its original binding-header pointer and performs
the real byte store, returning the exact current heap and temporary update.

Both use the shared actual pointer-read/assignment execution proof. ZF uses
the existing checked zero predicate; PF uses the existing parity value whose
equality to x86lean low-byte parity is already proved. Their actual source
expressions are retained by definitional equality. Runtime and the single
external ISA specification retain their definitions.

Focused71 jobs and four public type/axiom queries pass at200000/512 budgets,
j1,32GiB and shared timing. SF, ordered flag composition, writeback and native
whole-state/dispatcher correspondence continue next. Latest whole confirmation
remains the DIV regression in `m5-xor-full-20261123`.
