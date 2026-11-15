# Indexed GPR cells reduce simulator preprocessing

The one simulator path now accesses sixteen indexed value/tag cells. An overlapping named view keeps the extraction ABI: value offsets are register*16, tag offsets register*16+8, and the next state field remains at offset 256. Unknown entry words are still drawn independently in the same order; SP begins at zero. The complete selector is checked before narrowing, so a wide invalid selector cannot alias R8. Width writes, pointer tags and stack-release behavior are unchanged. No application producer or P source changes.

| Case | Before CPP bytes | After CPP bytes | Reduction |
|---|---:|---:|---:|
| n100_scalar_direct | 3,965,651 | 2,930,876 | 26.09% |
| n100_scalar_indirect | 4,026,273 | 2,974,229 | 26.13% |
| n100_ptr_direct | 9,859,911 | 6,889,886 | 30.12% |
| n100_ptr_indirect | 9,925,749 | 6,938,455 | 30.10% |
| n1000_scalar_direct | 30,517,198 | 22,012,423 | 27.87% |
| n1000_scalar_indirect | 30,599,504 | 22,077,460 | 27.85% |
| n1000_ptr_direct | 89,515,778 | 61,658,503 | 31.12% |
| n1000_ptr_indirect | 89,650,200 | 61,775,656 | 31.09% |

Four 100-instruction variants were freshly compiled through the normal production B path before and after the change, using the same canonical products. Every allocated section is byte-identical, including 248/256-byte scalar and 2232/2248-byte pointer XDP sections. Inputs/CPP were then regenerated for all eight size/shape combinations. Commands and resource records are under `/workspaces/kprog-raw/perf/20261115-preprocess-growth`; each host job had an 8 GiB AS cap on CPUs 8–11. These are compiler measurements, not B kernel submissions.

Validation: UBSan register dispatch/ABI/independent entry draw ordering 6423 cases; existing route semantics 7057 cases; canonical capacity-64 scalar storage versus extraction binding 102816 full state/stream comparisons; actual generated MUL versus x86 hardware and independent 128-bit products 50605 vectors; actual CompCert Clight generation of the full X86Pointer.c binding succeeds. This does not complete M4–M6 proofs or regenerate their tracked ASTs.

Failures retained: the first broad route compile found its pre-existing missing __x86_entry_rbp test variable; the oracle now explicitly snapshots/restores the incoming pointer and tag. The first CompCert run rejected a new GNU statement expression in REG_VALUE; the final implementation uses an ordinary conditional expression and passes. The wider CPU suite stopped at its existing unsupported movups encoder case, before any hardware comparisons, and is not marked passing. Its generator had already copied source headers into build-x86/snapshot; those rebuildable copies were removed with per-file SHA receipts. Do not rerun that target until it uses this checkout directly.

This is a 26–31% preprocessing reduction, not a repaired scale limit. The 1K pointer input is still about 61.7 MB; repeated ALU/load logic remains. No 10K/100K job was resumed, no native performance gain or stack acceptance is claimed, and no base/kernel/image was changed. All LTO remains on together.

Follow-up: 511f1ff0d removes source snapshots from both CPU generators, using
this checkout and recording source SHA identities. The finite-control CPU
observer executes 35 forms / 8960 cases: 4864 failures, all exclusively in
released private stack bytes (registers, defined flags, vectors and external
memory match). The historical pre-cell header at d4a6e8fed reproduces exactly
the same per-form failure counts; e9ea021fa streams that header in compiler
stdin and replaces the sole executable, with no historical source tree or
second retained binary. Both raw traces and mismatches are retained here.

The model's STACK_RELEASE writes explicit unspecified environment words;
this legacy host observer binds them to zero, while hardware retains return
addresses below SP. This explains the observed byte class, but the observer
still fails and is not relabeled passing. A matched free-input observer is an
open task; it does not invalidate or enlarge the focused passing subsets.
