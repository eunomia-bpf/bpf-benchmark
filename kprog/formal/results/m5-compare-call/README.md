# Actual original CMP call, frame release and caller resume

`Arm64Compare.Call.execute` follows the original sixth call: real nine-argument function entry1 + complete original body411 + actual freeList/return1 =413 silent steps. `execute_caller` includes the genuine original caller argument casts and restoration2+2:417 steps from afterMul to afterCompare, preserving original source locals and continuation.

The allocation frame transports actual flag-byte writability and typed scalar inputs. `Stores.Effect.storage` derives the reached header/register/SP/vector pointer storage from the same source allocations and actual four stores. Real live local permissions justify actual frame release; returned flag bytes survive the separate callee free frame. `Result` retains the actual source effect, released ranges/permissions, contents/nextblock, final flag bytes/current writability/storage, caller frame, bound and every differently named nonflag local load. `Result.gpr_load` derives preservation of every word/tag register observation for every chunk/offset. `Result.all_behaviors` establishes silent prefixes, the unique stuck terminal and no infinite relational run, without an observed-silence premise.

The real four before-cell write permissions remain an input contract. They must still be derived along the producer and earlier five calls for the original complete entry theorem. No native post-state, resulting flag, helper return or final-readback premise is introduced.

Component263jobs passed38.066s; five public type/axiom queries passed2.288s. CPU17/nice0/j1/32GiB/default200000heartbeats/depth512/asyncfalse. Effect.storage uses logical axioms only; other queries inherit only those plus CompCert external/assembly semantics. Exact source/dependency/query hashes, logs and timing are in validation.json. Intermediate413step source also passed39.546s; no failed attempts or increased limits.

Mature external SUBS-to-ZR NZCV, full source/native register representation and fetched original sixth/sixcall entry remain next. This is the actual source call, not a whole CMP/native/family result. M5/O1/O2/O4/M6 open; complete ISA families0. No runtime application or measurement.
