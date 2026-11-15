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

The retained actual main frontend now completes both compiler choices. Published
control emits2176496-byte object,52 spills and784-byte frame; candidate folds
2225 tied constants and emits1132336-byte object,47 spills and the same784-byte
frame. Observed child CPU totals16.592941→5.901504 seconds. A second candidate
observation records314528 executable bytes (prior actual replay991592),7739
CFG blocks and conservative maximum45 live spill slots, with zero proven
noninterfering pairs. Spill coloring has no demonstrated opportunity here.
The smaller B still exceeds512 bytes; stock/checked main and whole-app remain
open. Production base compiler remainsa7d9ab49; candidate publication is pending.

Constant closure cf084c84c also completes on this same frontend:305376 code
bytes,1123368 object bytes,47 spill slots,44 conservative live slots and the
same784-byte frame;2225 identities fold. Thus propagating pure constants
reduces code further but exposes no additional foldable identity in this
main. The frame remains the phase1 issue. No base/image publication or
stock acceptance follows from these compiler measurements.
