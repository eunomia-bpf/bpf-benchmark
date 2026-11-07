Artifact census (all entries use the harness XDP ABI; no app execution is implied).

| App | Objects | generation_failed | compile_pending | compile_failed | verify_pending | verifier_accepted | verifier_rejected | load_failed | execution_failed |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| bcc | 34 | 3 | 0 | 0 | 0 | 4 | 27 | 0 | 0 |
| cilium | 82 | 17 | 0 | 0 | 0 | 2 | 63 | 0 | 0 |
| katran | 6 | 1 | 0 | 0 | 0 | 0 | 4 | 1 | 0 |
| otelcol-ebpf-profiler | 30 | 6 | 0 | 14 | 0 | 0 | 8 | 2 | 0 |
| tetragon | 809 | 559 | 0 | 43 | 0 | 16 | 170 | 21 | 0 |
| tracee | 175 | 120 | 0 | 4 | 0 | 21 | 28 | 2 | 0 |

| App | Stage | Error class | Artifacts |
| --- | --- | --- | ---: |
| bcc | generation_failed | undefined native ABI register | 1 |
| bcc | generation_failed | unresolved native ABI external call | 2 |
| bcc | verifier_rejected | cannot access ptr member | 2 |
| bcc | verifier_rejected | only read from bpf_array is supported | 8 |
| bcc | verifier_rejected | other (see raw log) | 17 |
| cilium | generation_failed | undefined native ABI register | 17 |
| cilium | verifier_rejected | invalid access to map value | 1 |
| cilium | verifier_rejected | invalid size of register fill | 6 |
| cilium | verifier_rejected | other (see raw log) | 56 |
| katran | generation_failed | undefined native ABI register | 1 |
| katran | load_failed | arm64_sim_unsupported_opcode | 1 |
| katran | verifier_rejected | invalid size of register fill | 1 |
| katran | verifier_rejected | other (see raw log) | 3 |
| otelcol-ebpf-profiler | compile_failed | other (see raw log) | 14 |
| otelcol-ebpf-profiler | generation_failed | undefined native ABI register | 2 |
| otelcol-ebpf-profiler | generation_failed | unresolved native ABI external call | 4 |
| otelcol-ebpf-profiler | load_failed | arm64_sim_unsupported_opcode | 2 |
| otelcol-ebpf-profiler | verifier_rejected | invalid access to map value | 3 |
| otelcol-ebpf-profiler | verifier_rejected | other (see raw log) | 5 |
| tetragon | compile_failed | compile timeout | 1 |
| tetragon | compile_failed | other (see raw log) | 42 |
| tetragon | generation_failed | undefined native ABI register | 522 |
| tetragon | generation_failed | unresolved native ABI external call | 37 |
| tetragon | load_failed | arm64_sim_unsupported_opcode | 21 |
| tetragon | verifier_rejected | invalid access to map value | 54 |
| tetragon | verifier_rejected | invalid size of register fill | 2 |
| tetragon | verifier_rejected | other (see raw log) | 102 |
| tetragon | verifier_rejected | program of this type cannot use helper | 12 |
| tracee | compile_failed | other (see raw log) | 4 |
| tracee | generation_failed | escapes private stack | 113 |
| tracee | generation_failed | undefined native ABI register | 7 |
| tracee | load_failed | arm64_sim_unsupported_opcode | 2 |
| tracee | verifier_rejected | invalid access to map value | 5 |
| tracee | verifier_rejected | invalid size of register fill | 2 |
| tracee | verifier_rejected | other (see raw log) | 21 |
