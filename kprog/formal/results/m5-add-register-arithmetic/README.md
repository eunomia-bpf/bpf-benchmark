# Actual scalar LHS tag and AUX256 ADD candidate

The original tail now has a checked56-step run through operation masking, the actual LHS GPR tag reader, and the eager inline ADD candidate to original selection. Full AUX256 retains low ALUop0; the actual LHS scalar tag0 is read from the same storage heap. The source SRC2 STACK tag does not drive this choice. All candidate zero-initialization/sum/result assignments, casts and continuations remain. The existing SP/STACK evaluate contract is unchanged; the private tag call now accepts its actual source argument.

Component arithmetic2 passed231 jobs5.344s; public queries for new scalar and original SP evaluate passed with inherited axioms only. Exact hashes/timings/logs in validation.json. Earlier arithmetic1 rebuilt dependencies879.054s then failed a header conditional normalization; adding ite_true fixed that proof syntax only. No new premise on the existing interface, instruction model, axiom/admission/native oracle or proof-limit raise.

Scalar selection, actual writer, full register relation, free/return/native/all-behavior/entry composition and whole-library confirmation remain open. M5/O1/O2/O4/M6 open/families0. No apps, runtime tests or measurements.
