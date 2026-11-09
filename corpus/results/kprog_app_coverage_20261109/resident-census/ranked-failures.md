Resident static census: actual initial stock-verifier outcomes

| Failure class / installed | Programs | Generated | Compiled | Verifier accepted | Verifier rejected | bcc/set | cilium/agent | katran | otelcol-ebpf-profiler/profiling | tetragon/observer | tracee/monitor |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| native_manifest_selection_gap | 275 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 275 | 0 |
| source_maps_btf_prepare | 153 | 0 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | 0 | 151 |
| source_elf_open | 85 | 0 | 0 | 0 | 0 | 0 | 72 | 0 | 13 | 0 | 0 |
| elf_symbol_name_grammar | 23 | 0 | 0 | 0 | 0 | 14 | 0 | 0 | 0 | 9 | 0 |
| installed | 7 | 7 | 7 | 7 | 0 | 7 | 0 | 0 | 0 | 0 | 0 |
| verifier_scalar_memory_access | 4 | 4 | 4 | 0 | 4 | 2 | 0 | 0 | 0 | 2 | 0 |
| compilation_failed | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 |
| context_lowering | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |

All 549 initial rows retain their measured stages: 12 generated, 11 compiled, 7 verifier accepted, 4 verifier rejected. This table refines failure labels from the same captured diagnostics. Source ELF open errors cover the 85 initial static-entry cases; maps/BTF prepare errors cover 151 Tracee and 2 BCC instances; the symbol grammar identifies 23 captured metadata failures. The four verifier errors are scalar-memory accesses in B.

Model revision: 4f5b7ae6db02414f6ad69648677fc22ec8bf6795. Source-zero submission, declared source ELF maps/BTF, autoload=false and native execution requests: 0. The completed original raw records remain in requests/ and stock-raw.tar.gz.

The generic manifest fix has 549 unique selections. Later resource/metadata fixes and the active linked-static continuation retain separate actual stage receipts.
