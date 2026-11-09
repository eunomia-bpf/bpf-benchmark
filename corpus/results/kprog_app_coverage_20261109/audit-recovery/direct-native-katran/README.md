# Katran direct-native timing handoff

The three existing candidates are packaged as complete native/katran/ payloads.
Each contains the original manifest and all four native ELF objects. Member
bytes retain their original hashes; this step changes archive paths only.

| Candidate | Original result | Payload |
| --- | --- | --- |
| Inline/division | 32dadc6b6 | inline.tar.gz |
| Array lookup cleanup | 4b9805362 | array-cleanup.tar.gz |
| Per-CPU array lookup | 469a94426 | percpu-array.tar.gz |

R runs these first on its existing 2026-05-29 direct-native image and frozen
workload, changing native objects only. Each uses 3 samples of 180 seconds,
with BPF stats on and off. Per-row results retain actual replacements, fallbacks,
work counters and JIT/native code identities. The later optimization order is
Tetragon, Tracee, Cilium, OTel. Verified coverage follows its own model replay.

Example overlay command for the existing direct-native recipe:

    make -f kprog/perf/direct-native/Makefile image APP=katran PAYLOAD=/workspaces/repository/corpus/results/kprog_app_coverage_20261109/audit-recovery/direct-native-katran/inline.tar.gz
    make -f kprog/perf/direct-native/Makefile corpus CPUS=0-7 VM_CPUS=8 VM_MEM=64G APPS=katran SAMPLES=3 WORKLOAD_DURATION=180

R retains its existing May29 image and module selection for the object-only
cohort. The payload manifest records each member hash and undefined-symbol list.
