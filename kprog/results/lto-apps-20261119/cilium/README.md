# Cilium LTO-configuration timing (omp 2026-11-20)

The recipe is the batch's own (`kprog/results/lto-apps-20261119/Makefile`): `run_lto.sh` with
`verified_corpus.py cilium/agent 3 180 1`, stats on, CPUs 0-7, 8 vCPUs, 64 GiB, after `make kvm-host-cpu`.
Raw: `/workspaces/kprog-raw/timing/omp-cilium-20261119T233918Z`; run `x86_kvm_corpus_20261119_234045_456298`.

Run under `SKIP_REJIT=norejit`, so **both arms are eBPF** and this measures the workload, not the install:

| | eBPF arm | second arm |
|---|---|---|
| packets/s (pktgen, 3 x 180 s) | 616,593 | 633,105 |
| per-invocation BPF time | 637.8 ns (717.8 M calls) | 720.5 ns (676.7 M calls) |

Neither number separates the arms: across 78 Cilium runs in `corpus/results/` the per-invocation figure has
mean 829 ns and **sd 258 ns (31%)**, with a range of 558–2,323 ns, so a 13% gap in one run is inside the
noise. Throughput agrees (1.000x).

**Caveat on this particular run, found afterwards:** it held CPUs 0-7 from 23:40:45Z to 00:07:47Z and the
coordinator's rotate ran single-sample `cilium/agent` runs on the same CPUs inside that window (23:51:49–23:54:09,
`x86_kvm_corpus_20261119_235149_569391`). Both arms are therefore subject to the same interference, but the
numbers are not a clean measurement and should not be used as a ratio. The coverage result below is unaffected
(it is a count of how each request was served, not a rate).

**What this run does establish is coverage.** The guest service ran in `checked-sim-c`, and of its 28
requests (4 distinct programs, every one of them from the checked population) **28 installed through the
checked path, 0 fell back to direct-native, 0 failed**. Before the packet-bounds fix this app's captures were
routinely half direct-native; a 3 x 180 s production run now has no fallback at all (`coverage.json`).

Remaining, unchanged by this: the program `34af4b3a` still rejects when it appears (bound emitted on the
comparison's true edge, read on the fall-through) — it did not appear in this capture.
