# BCC native compilation with frozen read-only configuration

The frozen2026-05-29 recipe runs syscount with -L -i1. The CLI initializes measure_latency1 and filter_cg/count_by_process/filter_failed/filter_errno/filter_pid0 before loading its read-only data map. The private native compiler consumes those fixed input bindings, replaces only their scalar volatile IR loads with captured constants, and runs the existing O3 optimizer/code generator. Original C/JIT, workload and kernel same-copy emission retain their definitions. This is the authorized recompilation of P from stable configuration. The candidate stays tied to these captured bindings; arbitrary configuration changes require the corresponding P compile.

| Producer | Executable bytes | Instructions | Conditional branches | Calls | RIP memory operations |
| --- | ---: | ---: | ---: | ---: | ---: |
| control | 540 | 173 | 23 | 14 | 17 |
| candidate | 233 | 78 | 6 | 9 | 6 |

Both paired producers carry the same eight BCC native objects and complete manifest, with only syscount recompiled through the paired IR pipeline. summary.json records every replaced load, source hash and actual completed syscount service input. Full IR/commands/native/disassembly payloads accompany raw.tar.gz. These are native compiler observations. Generation-bound loading, original38 and actual matching-work/throughput remain application/R observations. Runtime admission additions0.
