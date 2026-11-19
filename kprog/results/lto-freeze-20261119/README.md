# BCC in the LTO configuration with frozen private unknown inputs (2026-11-19)

Coordinator batch. 2eb36bad9 gives each private unknown input read of the simulator a frozen undefined value on the
native side; offline the 25 BCC requests go from 18 418 to 7 282 B of native code (lto-config-20261119/native-size-bcc.tsv).
run.sh waits until the request-time inputs (simulator headers, generator, service, loader) are committed, so the
lock-prefix work in progress by perf is measured as committed, then installs the checked-sim compiler tools from HEAD
(make -C kprog/libnativeloader checked-sim-stage) and times BCC with the recipe of native-cohort-timing-20261119
(run_lto.sh, 3 x 180 s per arm, stats on, CPUs 0-7, 8 vCPUs, 64 GiB). Raw: /workspaces/kprog-raw/coordinator/lto-freeze-20261119.
Previous measurement of the same recipe before 2eb36bad9: per call 1.016x, throughput 1.018x, installed 20 043 B vs JIT 7 965 B.

## Result (batch 09:50-10:45 UTC, source 3f80b472e)

The batch started at 09:50 at 3f80b472e, which includes 2eb36bad9 (frozen private unknown inputs) and perf's
3f80b472e (LOCK memory semantics kept in the shared x86 simulation); host exit 0, app ok, stats on, 3 x 180 s per arm.
Run x86_kvm_corpus_20261119_101802_025374. Registered-service coverage: 25 programs, 25 native installed, 25 B
generated, 25 B stock-accepted, 25 checked-sim-c, 0 direct fallback, 0 failed (coverage.json).

| Measure | Before 2eb36bad9 (native-cohort-timing-20261119) | This batch |
|---|---|---|
| per call (ns/inv, eBPF -> native) | 107.7 -> 106.0, 1.016x | 103.8 -> 103.1, 1.007x |
| throughput | 1.018x (1.013 / 1.020 / 1.022) | 1.006x (1.015 / 0.995 / 1.006) |
| installed native vs JIT | 20 043 B vs 7 965 B, 2.52x | 8 628 B vs 7 965 B, 1.08x |

Reading (coordinator): the native code of this configuration is now the size of P plus the link stubs; per call stays
at the JIT because the BCC program bodies are about 10 ns of each 104 ns call, the rest being the attach path and
helper calls. The per-call gain of this configuration shows on apps whose body share is larger (Tracee, Tetragon,
Cilium), which run through it once their B compiles (todo section 0).
