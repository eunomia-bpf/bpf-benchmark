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

## Distribution8.7 operational replay

The same576 inputs run against the unchanged8.7 core and machine books using
the retained SBCL runtime. The frozen canonical executable has SHA256
`3bc4ccd89914c82e5aa23eee626ea5ca0a0447a5965057a06c9b4b9b69ea0173`; all576 canonical results match the previous epoch.

| Outcome | Cases |
| --- | ---: |
| Complete observed state agreement | 288 |
| State difference | 120 |
| Model stopped | 168 |

BSWAP24, POPCNT register36/memory36, MOVBE load36/store36 and SHIFTX register72
now agree completely. The two SIMD labels retain their48 agreeing observations.
Combined with the existing Sail line, current evidence covers58 agreeing labels,
seven model-stopped labels and two state-difference labels among67 enumerated
canonical forms. Every model/ISA/compiler trust interface retains its stated scope.

Memory SHIFTX has72 observations with equal GPRs, flags, XMM0 and memory;
its PC advances one displacement byte less than the canonical instruction.
The upstream `x86-sarx/shlx/shrx` source430-541 discards the operand helper
returned RIP increment and finally writes `temp-rip`; this matches the observed
PC difference. Complete step equality stays open for this form. REP retains48
one-element versus whole-instruction PC/counter/memory differences. ANDN/BZHI
register/memory, MULX and RORX register/memory retain168 model-stopped cases.

[Original8.7 records](reference-x86-acl2-87.log.gz) retain each request, outcome,
Lisp chunk, command, failed setup attempt, exact key model source and package
identity. The loader uses official `init.lisp` plus the upstream local
`dispatch-creator` dependency. Every Uncertified/Compiled-file warning stays
in the raw logs; these are operational model comparisons and ACL2 certification
remains a separate trust item. The November source capability audit above
continues to describe its own source epoch.
