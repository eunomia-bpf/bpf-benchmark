Artifact census (all entries use the harness XDP ABI; no app execution is implied).

| App | Objects | generation_failed | compile_pending | compile_failed | verify_pending | verifier_accepted | verifier_rejected | load_failed | execution_failed |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| bcc | 34 | 3 | 0 | 0 | 31 | 0 | 0 | 0 | 0 |
| cilium | 82 | 17 | 0 | 0 | 65 | 0 | 0 | 0 | 0 |
| katran | 6 | 1 | 0 | 0 | 5 | 0 | 0 | 0 | 0 |
| otelcol-ebpf-profiler | 30 | 6 | 22 | 0 | 2 | 0 | 0 | 0 | 0 |
| tetragon | 809 | 559 | 250 | 0 | 0 | 0 | 0 | 0 | 0 |
| tracee | 175 | 120 | 55 | 0 | 0 | 0 | 0 | 0 | 0 |

| App | Stage | Error class | Artifacts |
| --- | --- | --- | ---: |
| bcc | generation_failed | undefined native ABI register | 1 |
| bcc | generation_failed | unresolved native ABI external call | 2 |
| cilium | generation_failed | undefined native ABI register | 17 |
| katran | generation_failed | undefined native ABI register | 1 |
| otelcol-ebpf-profiler | generation_failed | undefined native ABI register | 2 |
| otelcol-ebpf-profiler | generation_failed | unresolved native ABI external call | 4 |
| tetragon | generation_failed | undefined native ABI register | 522 |
| tetragon | generation_failed | unresolved native ABI external call | 37 |
| tracee | generation_failed | escapes private stack | 113 |
| tracee | generation_failed | undefined native ABI register | 7 |
