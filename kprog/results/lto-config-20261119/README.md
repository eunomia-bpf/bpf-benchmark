# The design's main configuration, LTO (checked-sim-c), timed (2026-11-19)

kprog/docs/design.md names the LTO configuration (checked-sim-c) as the main one and direct native as the control.
run.sh starts the registered service in checked-sim-c mode (run_lto.sh, the command of kprog/test/run_checked_otel.sh)
and the frozen corpus driver through kprog/test/verified_corpus.py, in a guest on CPUs 0-7 with 8 vCPUs and 64 GiB,
holding the timing lock. Stats off 3 x 180 s, then stats on 3 x 60 s.

## BCC (bcc/set), base loader and image of bpf-benchmark-dev at 1fd06a9a5

| Run | Result | Function |
|---|---|---|
| stats off, x86_kvm_corpus_20261119_045219_454072 | throughput 1.023x (1.020 / 1.071 / 1.023) | 25 replaced, 0 failed |
| stats on, x86_kvm_corpus_20261119_052151_233344 | per call 1.004x (106.9 -> 106.5 ns), throughput 1.004x | ok |

Installed native code is 54 511 B against 7 965 B JIT (6.84x); direct native is 0.77-1.46x.
Reading: in this configuration every helper is still a call and the specialized simulator code is large, so BCC
runs even with the JIT. The design's gains in this configuration come from helpers written in C and compiled with the
specialized sim C (todo section 0, coordinator blocks of 2026-11-19); code size of this configuration is the other item.
run.sh first missed the run directory (the guest console breaks the JSON line); both runs were read from their
directories and run.sh now takes the corpus run name from the log.
