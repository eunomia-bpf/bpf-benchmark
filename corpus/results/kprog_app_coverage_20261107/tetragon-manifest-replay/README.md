# Tetragon with complete source-function manifest selectors

Actual batch x86_kvm_corpus_20261107_223215_716961 uses the regenerated
manifest from db0228718. The common service receives execve_send and freshly
generates/compiles it, closing the earlier source-length selection failure.
The first4requests bind; the fifth reaches an actual verifier jump-sequence
limit:8193jumps,188982processed instructions,1926total/peak states and
max_states_per_insn4. This is a jump-depth rejection with the1M instruction
limit retained. The next generic CMP representation replay uses the same native
input, application startup and workload.

| Baseline attempts | Resident records | Generated | Compiled | Bound | Specialization errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: | --- |
|311|287|5|5|4|0|1: jump-sequence complexity|

All5terminal archives carry the kernel native bytes, fresh source/object,
metadata and request outcome; the collector verifies each native hash. The
first4bound IDs match their application replacements. Source drift records
the common trusted_service.py diagnostic wording update during this batch;
per-request source identities and launch snapshots retain their own epochs.
The common module is T697bea/c3842be1, kerneldf7a9293, and private warm-cache
readonly-label linker. The image adds that module/linker and the complete
source-closure manifest while native objects and workload retain their bytes.

```sh
sh /workspaces/.agent-state/kprog-lanes/C/tetragon-manifest-replay/run.sh
```

The existing recipe uses12GiB/eightvCPU on20-23,one sample and two-second
workload. Driver exit0 and app startup error have separate records; the
collector exits1 after preserving observations. coverage.json retains raw
per-program/workload counters. service.tar.gz retains the full verifier log
inside corpus/requests/5.failure.tar.gz at request/load.stderr; result.tar.gz
retains the original app and shim logs; launch.tar.gz retains inputs/commands.
Closed guest disk/export/private image are retired. Universal ISA/token/link/
binding laws supply the safety argument; this batch supplies execution evidence.
