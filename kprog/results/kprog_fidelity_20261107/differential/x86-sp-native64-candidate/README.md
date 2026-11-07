# Native64 stack projection candidate: expanded CPU counterexamples and repair

PRIVATE candidate only. The production runtime header is not promoted by this
commit. Sources are based on1b114d3e plus F's SP projection/MOV/LEA/index/XCHG changes;
these results are not a claim about every intervening master change.

| Test | Cases | Differences/outcome |
|---|---:|---|
|v2e audit,40 sequences,CPU/C|40960|5120 across5 sequences|
|Same audit CPU/canonical X86Path|40960|0|
|v3 fixed,40 sequences,CPU/C/canonical|40960|0 on both comparisons|
|Native64 index host arithmetic|690|0|
|Arena host checks|71657|0; plus high32 slot/fit assertions|
|MOV route comparisons|23396|0|
|XCHG route comparisons|62725|0|
|ALU memory route comparisons|261137|0|
|Focused supporting Lean|19buildjobs plus2dependent modules|PASS|
|Original negative suite,KVM proof-load-only|25|18verifier,6specialization,1loader rejected;0accepted|
|Restored-SP high32 post-fix controls,KVM load-only|4|4verifier rejected;0accepted|
|Legitimate bound-native programs,KVM execution|6|all probe0, expected return2; captures retained|
|Paired old29micro inputs,v2e only|58compiles,29loads/phase|28/29admitted each; same Cilium null-store rejection|

The five new mismatching sequences are full64 XCHG alias forward/reverse/roundtrip,
SP XCHG restore, and scalar-SP-copy-restore. Full-width XCHG previously copied raw
arena addresses and erased origin tags. The private repair snapshots both operands'
values and origins before either write and permutes them, with native SP
normalization. Separately, adding capacity to a normalized64bit offset previously
truncated it to32bits: distinct addresses4GiB apart aliased the arena. Index and
word-index now retain64bits; scalar reads/spills expose native address bits;
partial writes merge native bits before scalarizing; MOV and LEA normalize SP once.
No runtime bound/fuel/zero-return was added. Canonical ISA semantics is unchanged.

All40sequences use actual encoded native instructions, random1024states each,
and the existing canonical X86Path reference, including register/flag/memory
comparisons. Every mismatch input is retained losslessly in audit/*.jsonl.gz.
The small host/model row counts are comparisons, not additional CPU executions.
Supporting Lean contracts are not whole-program correctness claims.

`v3` FULL fails at two dependent modules still using BV32 arena inputs.
`v3b` fixes the input widths but exposes3natural-modulo proof goals.
`v3c` proves the low-width restriction explicitly; its focused modules pass.
Its complete immutable FULL check was still running at this publication boundary.
Older v2/b/d/e FULL failures and the first focused filename error are retained.
The first high32 controls stop at unbalanced-RET specialization and are labelled
as such; the final controls restore SP and reach the actual verifier memory rejection.
No invalid native body was executed. All tests use CPUs16-23; guests2vCPU/2GiB.

Recipes are in recipes/. Primary commands: `x86_stack.py --source SOURCE --out BUILD`,
`cc -O1 -g -std=gnu11 -static ... driver.c generated.c native.S -o cpu-differential`,
`cpu-differential 1024 OUT OUT/cpu-states.bin`, and
`reference_check.py --reuse-trace --linear-paths --binary BINARY --reference REF
--arch x86 --cases1024 --out OUT` (actual argument spacing in scripts).
Sources, compiled harnesses, proof objects, source pins, native disassemblies,
compiler/verifier messages and six execution captures are retained here.
