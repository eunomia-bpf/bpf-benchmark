# Live integer register identities

2026-11-16T01:18:28Z

B-only normalization replaces exactly tied empty integer asm with freeze of its input. Defined bits stay equal; the register remains concrete for undef/poison inputs. Existing context provenance follows this identity. Pointer and memory-clobber asm retain their existing treatment. Shared I, native P, flags and published compiler are unchanged.

Host execution checks and IR boundary regressions pass; checks.json records the counts. Raw logs and commands remain at /workspaces/kprog-raw/perf/20261116-live-identities/check. Actual OTel frame, stock verifier and whole-app acceptance remain to be measured.

2026-11-16T01:21:25Z: retained perf_unwind_native folds 2,225 constant identities and normalizes 280 live identities plus 18,581 private accesses. Code reduces 295,336 to 289,560 bytes (1.96%); spill slots increase 47 to 52 and frame increases 784 to 824 bytes. This does not solve phase 1. The sole published base compiler remains unchanged; source is a candidate. Actual input/compiler hashes and commands are in actual-main.json and the persistent raw directory.
