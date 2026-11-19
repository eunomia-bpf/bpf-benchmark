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

## Native code size of the BCC requests, rebuilt offline (2026-11-19 08:45)

The 25 BCC requests of the stats-on run (service archive) were disassembled: the specialized interpreter is fully
folded, and the size came from the simulator's private unknown inputs (`kprog_unspecified_input`), kept on the
native side as volatile map reads (25-833 per program; B drops the unused ones in packet_bounds_ir.cpp).
compile_sim_ir.cpp now gives each such read a frozen undefined value on the native side (any value, the same set the
verifier checks in B). Each request's native side was rebuilt with the request's own commands
(native-size-bcc.tsv, function bytes from nm):

| Native side | Total bytes | x P (5 447 B) | x JIT (7 965 B) |
|---|---|---|---|
| run of 05:21 | 53 616 | 9.84 | 6.73 |
| HEAD 8d89ede8c (perf's native LTO changes of 07:10-07:55) | 18 418 | 3.38 | 2.31 |
| HEAD + frozen unspecified inputs | 7 282 | 1.34 | 0.91 |

Open item found in the same disassembly: the x86 text parser (generate_micro_sim_proofs.py) drops the `lock` prefix,
so P's `lock incq` runs as a plain read-modify-write in B and on the native side.
