# Original GPR tag reader in the linked world

The actual exported tag reader now has a layout-bound 28-step theorem for any world with the used original GPR layout. Its only memory premises are the real tag-table header pointer, indexed pointer slot and Mint8 load. It returns the zero-extended tag, preserves the complete memory, and retains the actual caller continuation. The standalone reader APIs are unchanged. This supplies the actual LHS tag call required by the fourth ADD-register tail; it reads SRC, not SRC2.

Component build passed143 jobs46.276s; public type/axiom queries for the new bound theorem and existing reader API passed with standard logic and inherited CompCert external/inline semantics only. Exact hashes, timings and raw logs are in validation.json. Original default proof limits, no admission/new axiom/native oracle. Whole-library confirmation follows the arithmetic/tag batch. Complete fourth handler/native and M5/O1/O2/O4/M6 remain open/families0. No apps, runtime tests or measurements.

Whole-library/root confirmation passed: full4,308 jobs369.523s; import KProgFormal and eight public type/axiom queries passed, inherited axioms only/source hashes stable. Raw full4/public-body-root1; exact details in validation.json. Complete source body467 still leaves the handler frame live; free/native/all-behavior/entry and M5/M6 remain open.
