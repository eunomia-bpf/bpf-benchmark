Resident static census: actual stock-verifier outcomes

| Failure class / installed | Programs | Generated | Compiled | Verifier accepted | Verifier rejected | bcc/set | cilium/agent | katran | otelcol-ebpf-profiler/profiling | tetragon/observer | tracee/monitor |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| native_manifest_selection_gap | 275 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 275 | 0 |
| resource_failed | 238 | 0 | 0 | 0 | 0 | 2 | 72 | 0 | 13 | 0 | 151 |
| generation_failed | 23 | 0 | 0 | 0 | 0 | 14 | 0 | 0 | 0 | 9 | 0 |
| installed | 7 | 7 | 7 | 7 | 0 | 7 | 0 | 0 | 0 | 0 | 0 |
| verifier_rejected | 4 | 4 | 4 | 0 | 4 | 2 | 0 | 0 | 0 | 2 | 0 |
| compilation_failed | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 |
| context_lowering | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |

Every original instance retains its source ID and actual stage. Native execution requests:0. Source ELF maps/BTF are prepared with autoload=false; this static pass retains their declared initial resources. Application work and performance retain their separate runtime cohorts.

Generation, compilation, resource preparation and verifier diagnostics accompany each row in stock-results.json. The immutable model revision is 4f5b7ae6db02414f6ad69648677fc22ec8bf6795.
