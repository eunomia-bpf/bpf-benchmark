# All ordinary MOVZ/MOVN halfword columns

This extends the [returned-register contract](../m5-arm64-mov-view/README.md)
to MOVZ and MOVN, ordinary destinations 0–30, all 16-bit immediates, X64
columns 0/1/2/3 and W32 columns 0/1. Native register31/XZR and MOVK remain separate.

The live emitter is `kprog/arm64/micro-prog/generate_micro_sim_proofs.py`:
`normalize_alias` validates the halfword/column, shifts the immediate, optionally
complements it for MOVN, masks it to the W/X width and changes the mnemonic to
MOV. `encode` then emits `ARM64_OP_MOV_IMM`, the destination and width, and the
normalized u64 literal. Its other fields retain their defaults, including
SRC=NONE and AUX=0. The production `arm64/trusted_specializer.py` imports this
same module, as do `trusted_service.py` and the retained formal reference check.
The generic Clight handler consumes this IMM directly; it does not shift AUX.

`Wide.literal` binds exactly that width-limited operand computation, with no
machine input or native-step outcome. `literal_toNat` proves its modular integer
form: shift the native 16-bit value, reduce modulo 2^width, and for MOVN subtract
from 2^width−1. `fields` binds the mature decoded record; it defines no decoder.
The live Python parser/byte-disassembly admission is still outside this theorem.
`Emission.py` calls the real `normalize_alias`/`encode` functions and records 48
boundary operand cases in persistent raw data. Those are metadata observations,
not sampled ISA proofs or a formal verification of Python.

`native_step` proves the actual LNSym checked step from its real decoder
certificate, matching decoded fields, actual fetched encoding and no initial
error. W32 additionally requires column<2, matching the emitter's rejection
and native illegal-encoding guard. The generic `partInstall` identity and
source width-normalization law reuse imported bitvector operations. The native
body, public register/PC writes and checked dispatcher remain LNSym's.

`reference_step` proves the exact complete native wrapper state, PC+4 and empty
new event/fault delta, retaining input histories, memory/profile/program,
SP, vectors, NZCV/extra flags, exclusives and thread inputs. `call_corresponds`
composes this with the real 203-transition Clight procedure and final register
relation at the original pre-call frontier. It preserves the actual caller
execution and local free; it never inserts a standalone writer run there.

Source2/source3/aux may remain arbitrary unused Clight values in the handler
contract. Actual frontend/provider/producer/caller admission, native physical
memory/alias/origin binding and program control remain open. The new Numeric
world 203/frontier 204 remains distinct from the old Entry/Program 188/frontier 189.
M5/M6 and O1/O2/O4 recount remain open; complete ISA-handler/family count is zero.
C/runtime/benchmark sources and the 23 exported Clight modules are unchanged.

`Query.lean` and `validation.json` record final public types/axioms, builds,
export parity and retained failed attempts. Full emission records and logs
stay under `/workspaces/kprog-raw/formal/m5-arm64-mov-wide`.
