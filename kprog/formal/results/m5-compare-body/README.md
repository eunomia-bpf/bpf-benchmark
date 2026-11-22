# Original CMP scalar branch and complete body

`Arm64Compare.Body.branch_execute` composes both actual operand calls218 with the original SUB flag loop73:291 silent steps from the original CMP branch to its actual continuation. `execute` includes actual linked width helper/all preceding source gates118 and the original outer-loop exit2:411 steps from the original generic handler body to Sskip with its caller frame still live.

The proof derives entry/DST/SRC/AUX/effective width/opcode through the exact dispatch temp map and captured operands through the exact real helper/caller temp map. Both real RHS width masks, all source casts/continuations and computed flag memory effects remain. Current four byte-cell permissions are the allocation-derived memory contract, transported through real caller frames; unrelated access-map entries may differ. No helper result, final native state, resulting flag or independent readback is assumed.

Component242jobs passed5.628s; two public type/axiom queries passed1.761s. CPU17/nice0/j1/32GiB/default200000heartbeats/depth512/asyncfalse. Only inherited logical and CompCert external/assembly semantics; no new axioms, native proof oracle or proof-limit change. First source attempt passed. Exact source/dependency hashes/logs/timing/axioms are in validation.json.

Complete generic entry/free/return, full register/provenance/cache/header/vector representation, mature external SUBS-to-ZR NZCV correspondence and fetched original sixth/sixcall composition remain next.411 is the body, with the generic function frame still allocated. M5/O1/O2/O4/M6 open; complete ISA families0. No runtime application or measurement.
