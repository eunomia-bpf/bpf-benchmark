# Diagnostics

- Base: phase2 best `20260625-182615-phase2-cache-vip-metadata`.
- Candidate: phase2 best plus unlikely hints on hot-path lookup failure checks.
- Base object: `base-object.txt`.
- Candidate object: `candidate-object.txt`.
- Base `xdp` section size: `0x47b8`.
- Candidate `xdp` section size: `0x4858`.
- Clean upstream `xdp` section size after restore target: `0x4870`.
- Candidate hash: `candidate-object.sha256`.
- Candidate objdump: `candidate-xdp.objdump.txt`.
- Restore object: `restore-object.txt`.
- Observation: branch hints increased static `xdp` size by `0xa0` bytes versus the
  phase2 best, so the expected win is not instruction-count reduction. The
  formal run tested whether the JIT/layout effect improves the valid packet hot
  path despite the larger bytecode.
- Risk reviewed: `__builtin_expect()` must not specialize behavior to the
  benchmark. It is acceptable here because every hinted branch keeps the same
  runtime condition and same cold-path action.
- Restore check: after reversing `source.diff` and rebuilding, katran source had
  no local diff and `xdp` returned to clean size `0x4870`.
