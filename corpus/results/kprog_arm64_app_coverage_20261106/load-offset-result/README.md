# ARM load base plus immediate displacement

Fixes capable's actual verifier rejection of modified ctx+16. The canonical
width-preserving load macro accepts a separate displacement; signed16
constants remain in the BPF load instruction. Dynamic and out-of-range
addresses use the previous address arithmetic. Both paths read exactly the
selected native width, with unchanged memory/ISA value contracts.

Checks:1,052 independent host byte/value comparisons;32 actual BPF encodings
cover all four widths, signed16 boundaries, negative displacements, out-of-range
and dynamic offsets; existing20,024 load-byte oracle cases pass. Commands and
ELF instruction records are retained. Actual application admission is recorded
in ../bcc-runtime-v14/README.md; whole BCC application remains error.

Reproduce: make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile
load-offset-check PHASE=NEW_RESULT. No paper, kernel or workload change.
