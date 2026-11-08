# Whole OTel on canonical stack spill representation

Whole OTel: baseline13, generated3, compiled3, installed2, failed1, native hash joins3/3.

| Native entry | Generated | Compiled | Status | Verifier observation |
| --- | ---: | ---: | ---: | --- |
| read_task_struct | 1 | 1 | 0 |  |
| perf_unwind_stop | 1 | 1 | 0 |  |
| perf_unwind_native | 1 | 1 | -5 | invalid write to stack R10 off=-528 size=8; processed 3431 insns (limit 1000000) max_states_per_insn 0 total_states 87 peak_states 87 mark_read 0 |

Complete original application, existing two-second workload, captured runtime image and canonical d963788c0 generator/model. Baseline resident census and terminal native requests retain distinct measured domains. Complete input bytes, generated C/BPF, per-request stock-verifier logs, workload counters and app errors remain in the archives. Runtime admission checks, limits and per-program proofs added0. If the workload was not reached, this receipt records its setup error and zero observed requests; it does not establish whole-application coverage.
