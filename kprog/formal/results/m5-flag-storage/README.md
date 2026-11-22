# Allocation-derived flag permissions through the original call path

`Storage.flagWritable` retains current writable bytes for the four actual N/Z/C/V source locals. `of_header` derives them from the same typed producer allocation using scalar_local and the reached access map. Current successful flag reads are not used to infer write permission.

Every actual storage constructor preserves the fact: generic allocation frames use actual permission-derived block liveness; bounded free frames use producer ownership; GPR word/tag, pointer, cache, body and flag stores use their real access equalities. No new C computation, native arithmetic, runtime rule, gate or input configuration is introduced. The original complete five-call source/native entry theorem was rechecked with this stronger storage, so its actual returned Storage carries the four permissions through the same existing allocation/store/free history.

`Stores.writable_of_storage` derives the existing CMP predicate. `Call.execute_from_storage`413 and `execute_caller_from_storage`417 eliminate the separate caller permission argument while retaining the earlier APIs. No extra hypothesis is added to the original entry theorem and no final permission/native-state/readback assumption substitutes for the derivation.

All three focused ARM targets passed292jobs in1318.199s; twelve public constructor/type/axiom queries passed1.659s. CPU17/nice0/j1/32GiB/default200000heartbeats/depth512/asyncfalse. Only inherited logical and CompCert external/assembly semantic axioms; no sorryAx/new axiom/native proof oracle or increased limits. First source attempt passed. Exact nine current/baseline hashes, baseline snapshots, raw build/public logs and timing are retained in validation.json.

This confirms the affected ARM closure, including the original five-call entry, rather than a new whole-library/root pass. Native N/V equality to the C masks, complete C-byte/native-NZCV and register correspondence, fetched original sixth/sixcall entry remain open. M5/O1/O2/O4/M6 open; complete ISA families0. No runtime application or measurement.
