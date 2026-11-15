# Constant identities in the B compiler

Retained OTel main IR has one408-byte private stack object and5642 inline-asm
calls. Many opaque identities carry already-known integer stack offsets. They
keep LLVM from folding the corresponding address and register expressions.

The common B IR compiler now folds an empty asm only when its constraint is
exactly tied `=r,0`, its operand/result types match and its argument is an
integer constant. Stack-aligning or throwing asm, live values, pointer values,
untied outputs, memory clobbers and real assembly retain their identity.
No C interpreter, producer, native P, flags, helper policy or LTO switch changes.

The existing subset passes:18 actual constant/negative host executions,
60 pointer-identity cases,30 equality-edge cases, four context load widths and
the normal service/backend path. In particular an untied constant input17
still returns the independently seeded R12 output; pointer and memory-clobber
forms remain in IR. The checked inputs and outcomes stay under the raw root.
This is a compiler candidate, with the active Katran image/base untouched.
Actual OTel main frame and stock/checked acceptance remain to be measured.
