# Live integer register identities

2026-11-16T01:18:28Z

B-only normalization replaces exactly tied empty integer asm with freeze of its input. Defined bits stay equal; the register remains concrete for undef/poison inputs. Existing context provenance follows this identity. Pointer and memory-clobber asm retain their existing treatment. Shared I, native P, flags and published compiler are unchanged.

Host execution checks and IR boundary regressions pass; checks.json records the counts. Raw logs and commands remain at /workspaces/kprog-raw/perf/20261116-live-identities/check. Actual OTel frame, stock verifier and whole-app acceptance remain to be measured.
