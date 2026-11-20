# Source C LPM in load-time LTO

2026-11-20T01:34:15Z

The smallest change binds the existing known-map lookup pass to a shared C LPM body using loaded map shape and kernel BTF. The native linker continues relocation binding. The source lives in `vendor/bpf/native-lpm.h`, expands through `native-helpers.h`, and is embedded in the existing compiler so the runtime image definition stays fixed.

The host regression compares the imported machine code and source helper to an independent bitwise oracle. It covers empty roots, prefix limits, intermediate flags, parent retention, child branches, byte order, payload widths and guarded payload boundaries. Fixed, dynamic, mixed and unknown map facts exercise selection and retained generic calls. The previous ARRAY regression remains a separate compatibility check.

Build and execution receipts follow the committed `run.sh`/Makefile. Raw logs stay in `/workspaces/kprog-raw/perf/lpm-c-lto-20261120`. Application coverage and speed require the next combined image; current measurements come from image source `8f6ff5891`.
