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

The archives above preserve the old external-thunk profiles. Their undefined-symbol lists expose the original thunk requirements. The current Makefile payloads target recompiles each original command/plugin profile after removing the retpoline, return-thunk and ENDBR compiler flags. Rebuilt complete archives and commands go under /var/tmp/kprog-tmp/C/direct-native-katran-handoff/rebuilt. R receives that direct-instruction successor after compiler completion.

## Current direct-instruction payloads

All three profiles recompile at exit0 with their original optimization flags/plugin and original Katran C, after removing the three hardening flags. Every complete manifest has4 rows and all12 native objects have empty undefined-symbol lists. R uses direct-inline.tar.gz, direct-array-cleanup.tar.gz and direct-percpu-array.tar.gz for the original three candidates, in that order. The direct-payloads.json receipt records full commands, source/plugin/object hashes and the original profile path. The direct-build-raw archive retains each command, plugin binary, compiler/manifest output and complete payload. Existing May29 JIT objects and workload retain their bytes.
