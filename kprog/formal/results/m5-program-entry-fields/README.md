# Actual entry field transport

Imported Clight field offsets and field evaluation agree across the actual
producer and production composite environments. The proof uses member sizes
and alignments and complete record equality for five local layouts: entry
header, vector lane, volatile stack union, GPR union and RAW ABI. It assumes
no equality of the whole composite environments.

The generic offset laws retain every field name, including unknown-field
errors, and every starting bit position. Field address/read transport retains
exact offsets, bitfields and failures. Its base-expression premise admits
separate temporary environments. allocated_header derives that premise from
the real allocator and existing local-expression law for the actual header,
with arbitrary subsequent memory and both arbitrary temporary environments.
It assumes neither a readable field nor a successful lookup.

Focused validation passes 166 jobs. One full Lake build passes 341 jobs.
Seven new field type/axiom queries and eleven prior source/local queries pass,
18 total, with standard logical axioms only. All ten Arm64 exports retain the
9c617740f byte baseline; 12 historical x86 differences and exact sizes
are recorded in validation.json. Full confirmation also closes the pending
whole-build check of focused source commit 3f7578a54.

Failed focused attempts remain raw. They exposed proof-construction issues:
an unsolved True conjunction, premature unification of large different worlds,
and a match/fieldOffset alias needing explicit reduction. Unfolding only the
imported operations being compared fixes these at unchanged proof limits.
The proofs reuse imported semantics; C sources and runtime behavior are unchanged.

This is expression/field transport. Actual assignment/cast/arithmetic steps,
complete prefix execution and global callback/provider/native/context binding
remain open. The continuation still needs its genuine one-pointer/uint32 ABI.
Completed ISA-family count stays zero; M5 precedes M6 and final fresh checks.

Raw logs: /workspaces/kprog-raw/formal/m5-program-entry-fields
Public queries: Query.lean. Actual results: validation.json.
