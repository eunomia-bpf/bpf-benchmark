# Tracee whole-application narrow-register-read replay

Actual batch: corpus/results/x86_kvm_corpus_20261107_214037_284090.
Upstream startup completes151programs in the JIT arm. The registered common
service observes6native requests, freshly generates and compiles all6, and
binds5. sys_exit_submit reaches actual verifier memory analysis: its readonly
object has80bytes, while the indexed4-byte read has maximum offset1036.
The full log records2154processed instructions and91states.

| JIT app loads | Native requests | Generated | Compiled | Bound | Specialization failures | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: | --- |
|151|6|6|6|5|0|1: readonly indexed extent|

The epoch uses d585cf1e5e2d private narrow-register-read include and
helper-preserving native input7479850e2345. Native/source copies, compiler
wrapper, guest script, image and module hashes appear in launch.tar.gz and
coverage.json. The retained driver uses12GiB/8vCPU/20-23,one sample and the
existing two-second workload:

```sh
sh /workspaces/.agent-state/kprog-lanes/C/representation-runtime-replay/tracee__monitor/run.sh
```

All6terminal kernel native hashes are verified. Complete service/result/launch
streams remain archived. The application reports startup error and the
collector exits1 after writing the failure observations. The shared guest.py
changes during this run and appears in source_drift; the private executed
guest.py remains captured separately in launch.tar.gz. coverage.json retains
raw JIT workload and per-program invocation counters. The full verifier log
lives in service.tar.gz, inside corpus/requests/6.failure.tar.gz at
request/load.stderr; its short tail in coverage.json contains later loader
diagnostics. The next generic CMP representation trial follows the existing
register-read finite observations. Universal instruction/token/link/binding
laws supply the safety argument; this batch supplies execution evidence.
