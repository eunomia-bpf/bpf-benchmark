# ARM actual-manifest control-flow audit

All 545 selectors in the six current ARM manifests were recorded. Fresh native
linking and finite-target analysis completed for 515. Thirty selectors lack an
explicit symbol field and stopped at metadata selection; these are not unknown
indirect-target failures. Counts by application and the exact compressed
per-selector records remain. This audit does not count verifier acceptance or
application execution. Raw native/proof copies and duplicate manifests are
removed under the cleanup order; the canonical stage and incremental linker
cache remain.
