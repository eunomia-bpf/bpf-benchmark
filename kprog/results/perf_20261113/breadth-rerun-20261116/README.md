2026-11-16T04:03:35Z

OTel stats0 on image d9e29630 completed run `x86_kvm_corpus_20261116_032555_782265`: app ok, zero workload errors; throughput median(native)/median(eBPF)=1.865747116x, against the05-29 floor1.849x. Samples parsed with the frozen May evaluation functions are retained in `otel-stats0.json`. Per-call timing is unavailable with stats off.

The shim records13 successful native loads, while framework tracking retains13 baseline and12 native program IDs at measurement. custom__generic still fails twice with native-stub EINVAL; this remains the original-ELF map-binding producer fix requested from C. These are different observations (load events versus tracked active IDs), so no14/14 or complete equal-work claim follows. Detailed raw shim/verifier logs remain in the run directory. No programs or errors were excluded.

Rotation continues to BCC with entry defaults3x180, CPUs0-7 and all LTO enabled. The checked functional batch remains independent on8-15. `analyze.py RUN_DIR OUTPUT` reproduces workload/counter analysis outside the benchmark framework, using exact metric function/constant ASTs from the archived parser and recording its SHA256. Its first whole-module import required unavailable matplotlib; this forward change executes only the metrics and leaves the archived source unchanged.
