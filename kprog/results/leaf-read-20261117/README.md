# User probe read as a leaf (2026-11-17)

run.sh rebuilds the one image with 6beae45cc, runs the one-image check and times OTel, BCC and Tracee; summary.txt holds the table, compared with ../zero-remainder-20261117. Host tests: 40 linker tests pass; the user routine passes 1149 host vectors and shrinks from 388 to 370 bytes; the kernel and kernel-string routines stay byte-identical. Raw: /workspaces/kprog-raw/leaf-read-20261117.
