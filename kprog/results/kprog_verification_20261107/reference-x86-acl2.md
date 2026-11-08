# Direct ACL2 x86 model comparison

The unmodified Ubuntu ACL2/x86isa8.5 model processes576 instruction inputs.
All48 MOVUPS/MOVAPS XMM0 load/store observations agree with the canonical Lean
reference, including all GPRs, defined flags, PC, XMM0 and supplied memory.
The480 inputs for fourteen Sail-stopped operations also reach ACL2's
unimplemented-opcode or illegal-instruction boundary. The48 REP inputs retain
a clear-state difference between the model's first element and the complete
canonical instruction. Raw equality classifications remain in the JSON; separate
diagnostic labels distinguish model stops from the REP state difference.

The REP probe uses the model's own EFER/CS accessors to establish64-bit mode.
After three element steps, RCX is zero, source/destination advance by three and
the three bytes have copied; RIP remains at the original instruction. The
archived8.5 F3 definition contains the same counter/ZF/IP control observed in
Sail. The canonical implementation's1120normal CPU scenes,64 restart faults and
1774full-state transitions remain separate evidence in the Sail report.

The supplied certificates report an original length/write-date mismatch for
`paging-structures.lisp`, inherited by dependent books. Those warnings and the
program-mode wrapper invariant-risk warnings remain in full model output.
This comparison records executable model definitions; ACL2 certification stays
a separate evidence boundary. Input values, loaded source/compiled-object and
package hashes identify the exact toolchain. The wrappers leave model sources
unchanged and use Lisp batches below28KB.

Initial setup epochs are retained alongside the completed batch. All actual
MOVUPS/MOVAPS forms, fourteen stopped operation domains and REP inputs remain
represented. The coverage ledger now has52 sampled-agreeing native operation
labels across its explicitly identified source epochs,14 model-stopped labels
and one REP difference. Physical/compiler/link and environment-token interfaces
retain their existing obligations.

## Current official source capability

The executed8.5 instruction listing binds NIL semantics for the stopped
BSWAP, POPCNT, MOVBE and BMI instruction families. Its default CPUID attachment
is documented as enabling features, which cannot supply missing semantics.
A separate [official source snapshot](https://raw.githubusercontent.com/acl2/acl2/37292996d867d74c30192bc09472e135d70a3595/books/projects/x86isa/machine/inst-listing.lisp) at
`37292996d867d74c30192bc09472e135d70a3595` declares semantic handlers for10 previously stopped
operation labels: BSWAP, POPCNT register/memory, MOVBE load/store, MULX,
RORX register/memory and SHIFTX register/memory. ANDN/BZHI register/memory
retain NIL bindings for4 labels. This is a source audit; no new model execution
agreement is claimed and the original14 model-stop rows remain unchanged.

The [source audit archive](reference-x86-capabilities.log.gz) retains both
listings, CPUID definition, exact line records, upstream commit metadata and
original distribution lookup outputs. Debian lists8.7 source/cert/runtime
packages; the optional direct source HTTP probe ended with IncompleteRead,
whose original traceback is retained. Running a newer executable model is the
next comparison step. Existing8.5/Sail model sources and binaries stay intact.
