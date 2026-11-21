# Original scalar result selection

The actual four selection gates now have a checked52-step scalar path for width8, ALUop0, non-SP destination and scalar LHS tag0. It reaches the original scalar writer statement with the original continuation, same complete memory and exact comparison temporaries. The final t23 is0; t21/t22 remain1. The existing tagged-pointer select API/source is unchanged; the actual scalar source fragment is exported for caller-edge composition.

Component build passed232 jobs6.741s; new scalar and existing pointer public type/axiom queries passed with standard logic and inherited CompCert external/inline semantics only. Exact hashes/timings/logs in validation.json. No altered source AST, new axiom/admission/native oracle or proof-limit raise. Actual writer/store/return/body composition is the next checked step; whole-library confirmation and complete framefree/native/all-behavior/entry remain open. M5/O1/O2/O4/M6 open/families0. No apps/runtime tests/measurement.

Whole-library/root confirmation passed: full4,308 jobs369.523s; import KProgFormal and eight public type/axiom queries passed, inherited axioms only/source hashes stable. Raw full4/public-body-root1; exact details in validation.json. Complete source body467 still leaves the handler frame live; free/native/all-behavior/entry and M5/M6 remain open.
