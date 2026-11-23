# Actual width-application helper

The complete original `x86_apply_width` call selects its real mask assignments
and returns the input word AND that mask. For every64-bit input and each
x86 operand size, its return equals the shared x86lean `Value.trunc` result.
Execution lengths are6/10/14/14 for byte/word/dword/qword. The caller memory
and continuation are retained exactly; the statement includes arbitrary
global environments and caller heaps.

Focused54 jobs and one public type/axiom query pass at200000/512 budgets,j1,
32GiB under shared timing. This helper supplies width setup in the original
logical flags branch. Its composition with flags and native writeback
continues next. Runtime and the shared specification retain their definitions.
Latest whole confirmation remains the DIV regression in `m5-xor-full-20261123`.
