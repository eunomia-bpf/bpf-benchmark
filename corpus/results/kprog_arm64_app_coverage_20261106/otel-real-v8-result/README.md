# Completed direct-O2 ARM OTel compile census (frozen v8)

All14 original-ELF/BTF candidate entries generate. The complete direct clang
O2 compile queue has7compiled,5LLVM out-of-memory failures and2timeouts.
Single compiler,32GiB address-space limit,900second per-program timeout.
Per-program stage/cause, complete compiler commands/stdout/stderr and frozen
inputs are retained. Candidate count differs from12resident counters and13
observed truncated startup selectors; all14 full ELF identities are retained.

This is compiler-stage evidence, not verifier/app admission. The new preclean
compiler continues in v15 and corrected Native-only v19 (32GiB,16-iteration
instcombine). The existing v18 continuation adopts successful exact-source
objects and the tested stop fix, compiles remaining entries and links all14
before staging and actual QEMU. Failures remain open; no program is excluded
or treated as unsupported. The native preclean compile already published
elsewhere used the same v8 source but is separate from this direct-O2 queue.
