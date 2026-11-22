# Mature CMP execution and fetched reference step

`Arm64Compare.Native.execute` evaluates the actual LNSym CMP X4,X1 alias: SUBS XZR,X4,X1,LSL0. Its resulting state uses the imported AddWithCarry/PState writers, advances PC by4 and discards the zero-register destination. This module supplies no local ISA arithmetic or replacement decoder.

`native_step` binds that operation to the same actual fetched encoding and its imported decoder certificate. `reference_step` retains complete native histories while deriving an empty new event list and no new fault. `registers` proves every GPR, SP, SIMD vector and extra flag bit outside NZCV remains unchanged. Current no-error and real fetch/decoded assumptions stay explicit.

Component76jobs passed2.137s; four public type/axiom queries passed1.812s. Existing low-priority CPU16-23/nice19/j1/32GiB/default200000heartbeats/depth512/asyncfalse; independent of the ongoing source Storage rebuild. Public queries use only inherited logical axioms, with no CompCert external semantic dependency, sorryAx or native proof oracle. Exact source/query hashes, failed source snapshots and logs are retained in validation.json; no limit increase.

Equality between the actual C flag-byte formulas and mature NZCV, full source/native register correspondence, W-width native bridge and original fetched six-call entry remain open. This is a mature-model execution proof, not a runtime application test or whole CMP/family result. M5/O1/O2/O4/M6 open; complete ISA families0.
