# Combined checked-native BCC functional check

Run the canonical `make -C kprog/libnativeloader checked-corpus` entry for
BCC with the current C ARRAY/probe helpers and native private-arena,
verified-path and integer-identity changes enabled together. The entry
defines its existing one-sample, ten-second functional workload. This is
stock/native coverage validation, not timing evidence.

The committed worker holds batch EX and timing SH; the entry acquires
image SH and starts its two-vCPU guest on CPUs 20–21. It uses the sole
base/compiler/loader and changes no image, kernel or benchmark setting.
All outputs and the registered-service request archive remain under
`/workspaces/kprog-raw/perf/native-cohort-check-20261119/`.
