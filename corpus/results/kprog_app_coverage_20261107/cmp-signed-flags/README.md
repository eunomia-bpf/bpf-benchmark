# Exact CMP flags retain signed comparisons through verification

Original native-only trace_event_type_switch_dispatch fails the verifier at
1000001 instructions. Its frontier repeatedly reconstructs signed branches
from separately expanded SF/OF bit operations. The generic CMP body now
expresses OF as SF xor signedLT(width-narrowed operands), after its exact
subtraction. This is the same flag bit for every input at8/16/32/64bits.
It lets signed hardware conditions compile as signed comparisons and retain
range information. No branch outcome is assumed and no loop bound, fuel,
packet/input condition, native instruction or compiler flag changes.

Only CMP's equivalent OF assignment changes. CF/ZF/SF/PF/AF, operand reads,
all memory/register effects, TEST and the generated general SUB primitive
remain unchanged. Existing47529 register-CMP and2244 memory-CMP route cases
pass UBSan against their original expected-state models. Four universally
quantified Lean bitvector identities prove the arithmetic law; their printed
axioms include Lean.ofReduceBool along with propext/Classical.choice/Quot.sound.
These are word laws, not an additional ISA reference or a proof of compiled C,
ABI reconstruction, full translation validation or all applications.

The same actual native ELF (bcc2fbd...) and original deterministic input now
generate/compile fresh through the registered kernel-owned service and pass
bound native execution with result16/retval2. One terminal success record and
complete nested archive are verified. It uses the same kernel/module/linker/
native ABI,4GiB/C20-23 and no application-supplied proof. Capture used a private
mount namespace for the candidate header; canonical source outside remained
d30 before/after. The exact captured header bytes are subsequently promoted
as canonical4fe6817..., as checks.json records. This is not a recapture under
a later source or an all29 pass claim. The separate26/29 baseline remains.

raw.tar.gz holds exact before/candidate headers, patch, pure-word Lean proofs
and axiom outputs, unchanged route tests with private include resolution,
compiler logs, original rejection, namespace scripts and full successful
service request/native/proof artifacts. The initial include-path setup error
and the initial undrained terminal archive are retained explicitly; neither
is counted as a semantic counterexample. The supervisor drain fix is recorded
separately in service-terminal-drain. No kernel/module/image rebuild occurred.
