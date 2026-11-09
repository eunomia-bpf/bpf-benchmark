All549 resident instances: ranked observed failure families

| Failure family | Instances | Generated B | Compiled B | Accepted | Rejected | bcc/set | cilium/agent | katran | otelcol-ebpf-profiler/profiling | tetragon/observer | tracee/monitor |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| bpf_stack_storage | 157 | 157 | 124 | 0 | 124 | 0 | 0 | 0 | 0 | 157 | 0 |
| source_maps_btf_prepare | 153 | 0 | 0 | 0 | 0 | 2 | 0 | 0 | 0 | 0 | 151 |
| callee_saved_equality_arm | 110 | 110 | 110 | 0 | 110 | 2 | 0 | 0 | 0 | 108 | 0 |
| source_elf_open | 85 | 0 | 0 | 0 | 0 | 0 | 72 | 0 | 13 | 0 | 0 |
| elf_symbol_name_grammar | 23 | 0 | 0 | 0 | 0 | 14 | 0 | 0 | 0 | 9 | 0 |
| native_kernel_link_relocation | 11 | 11 | 11 | 0 | 0 | 0 | 0 | 0 | 0 | 11 | 0 |
| installed | 7 | 7 | 7 | 7 | 0 | 7 | 0 | 0 | 0 | 0 | 0 |
| compilation_failed | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 1 | 0 | 0 | 0 |
| verifier_callback_argument | 1 | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 0 | 1 | 0 |
| context_lowering | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 | 0 |

Totals:549 instances, generated287, compiled253, accepted7, verifier rejected235. The275Tetragon continuation uses27 actual body representatives; the other274 rows retain their initial individual observations. Each compact row names its raw record and observation kind. All rows retain model4f5b7ae6d; native execution requests0.

The238 original resource failures have later successful maps/BTF preparation receipts, and23 symbol metadata cases have a later parser repair receipt. Their full native replay remains open and their initial stages remain in this table. The largest native failure family is BPF stack storage157: verifier124 and compiler33. The11kernel-link relocation failures follow successful B compilation.
