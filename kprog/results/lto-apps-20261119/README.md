# LTO configuration timing on the apps with larger body share (2026-11-19)

Coordinator batch. BCC's program bodies are about 10 of 104 ns per call, so the LTO configuration (checked-sim-c,
C helpers compiled with the specialized sim C) stays at the JIT there (lto-freeze-20261119: 1.007x). Tracee's body
share is larger and its probe reads are the C helpers now inlined. In the LTO configuration each request whose B
fails a stage runs direct native (recorded fallback), so the app runs native as a whole; the run's coverage records
how many requests went through checked-sim-c. Recipe: Makefile here (native-cohort-timing-20261119 with the app as a
parameter), 3 x 180 s per arm, stats on. run.sh starts after perf's numeric repair and committed request-time inputs.
Raw: /workspaces/kprog-raw/coordinator/lto-apps-20261119.

## OMP arms (2026-11-20)

`otelcol-ebpf-profiler/`, and the bcc/tracee/tetragon arms queued by
`queue-omp.sh` (one lock-hold per arm, so the coordinator's runs interleave), use the same Makefile and recipe.
The service archive stays only in the raw directory; the committed directory holds README, coverage.json and
timing-summary.txt, as the coordinator's arms do.
