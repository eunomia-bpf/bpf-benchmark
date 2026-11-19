# Original integer identity barriers in checked native LTO

The B pass normalizes an empty asm with exact `=r,0` constraints and one
same-type integer operand to `freeze`. Native conversion currently preserves
all empty asm, preventing constant propagation through original simulator
register identities. Apply the existing B contract only to original calls:
pointer identities, memory clobbers and the register bases generated later
by `memoryAsm` retain their existing behavior.

The host fixture checks constant and live integer identities, preserved
pointer/clobber/barrier calls, and a translated BPF load whose generated
register base must survive. It executes the actual converted native output
under UBSan. Retained BCC and ARRAY/OTel compilation tests follow the focused
test. App runtime gains remain for the combined checked-sim-c batch.

PERF 2026-11-19T07:55:23Z: Native compiler rebuilt in place. The original-call snapshot now
normalizes only same-type integer identities with exact =r,0 constraints and
no stack-alignment or throwing attributes. Freeze models concrete register
bits, including undefined/poison LLVM inputs. Fresh address-base barriers
created by memoryAsm are outside that snapshot. No B or helper policy changed.

1024 identity/pointer/clobber/address execution cases pass, as do the prior
3072 verified-domain/ordinary-check cases and all25 retained BCC production
compile/proof links. Recoverable probe tests (96 cases plus lengths/compat)
and ARRAY (1008 cases plus2 generic calls)/retained OTel API also pass.
Against ba366fcb3, the same25 BCC proof .text sections total47,597 ->19,263B.
Every request gets smaller; sys_exit_open/openat each6,911 ->1,570B and
inet_sock_set_state7,911 ->3,899B. This shows more folding, not an app speedup
or complete interpreter elimination. All C helper pieces remain enabled.

Main raw /workspaces/kprog-raw/perf/native-integer-identities-20261119/candidate-20261119T075305Z-233661; helper raw /workspaces/kprog-raw/perf/native-integer-identities-20261119/helper-regression-20261119T075415Z. The first fixture used literal
dollar operands, which the converter correctly rejected; faead2799 fixes
C operand syntax. The candidate worker completed build, identity/verified
tests and25 BCC replays, then stopped because probe output directories were
missing.6083ebcea fixes that recipe; only unfinished helper tests were run
in the separate helper directory. All failures and outputs remain.
