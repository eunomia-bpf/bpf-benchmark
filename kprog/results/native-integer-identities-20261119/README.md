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
