# ARM actual-manifest control-flow audit

All 546 selectors across the six current ARM application manifests passed finite-target analysis, covering all 626 matching native ELF entry candidates. There were no linking or unbounded-target failures. The prior 30 missing-symbol records are closed by enumerating every nonempty STT_FUNC whose first 15 characters match the kernel program name. Explicit symbols remain exact. Live source BTF still chooses the actual entry at load time; this audit never guesses one candidate or discards ambiguous names.

| Application | Selectors | Native entry candidates | Analyzed indirect sites |
|---|---:|---:|---:|
| bcc | 32 | 32 | 0 |
| cilium | 98 | 112 | 3885 |
| katran | 12 | 12 | 91 |
| otelcol-ebpf-profiler | 36 | 38 | 4785 |
| tetragon | 245 | 248 | 57544 |
| tracee | 123 | 184 | 31825 |

The OTel stage now has 36 selectors after installation of the native-memory input, explaining the increase from the earlier 545 total. Counts include repeated candidates selected by different manifest records and do not represent unique loaded programs. Compressed records retain every selector, candidate, native/proof/manifest hash, linker command and finite target set. Each temporary proof is deleted immediately after analysis; canonical stage and incremental linker caches remain.

This is not verifier acceptance or application execution coverage. Reproduce with `make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile manifest-dispatch-audit`.
