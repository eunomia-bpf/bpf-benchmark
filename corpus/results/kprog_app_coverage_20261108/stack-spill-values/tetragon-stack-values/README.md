# Whole Tetragon on canonical stack spill representation

Whole Tetragon: baseline287, generated4, compiled4, installed3, failed1, native hash joins4/4.

| Native entry | Generated | Compiled | Status | Verifier observation |
| --- | ---: | ---: | ---: | --- |
| event_exit_acct_process | 1 | 1 | 0 |  |
| event_exit_disassociate_ctty | 1 | 1 | 0 |  |
| event_wake_up_new_task | 1 | 1 | 0 |  |
| execve_send | 1 | 1 | -5 | The sequence of8193jumps is too complex; processed246573 insns (limit 1000000) max_states_per_insn 4 total_states 2297 peak_states 2297 mark_read 0 |

Complete original application, existing two-second workload, captured runtime image and captured model 75d2c8813. Baseline resident census and terminal native requests retain distinct measured domains. Complete input bytes, generated C/BPF, per-request stock-verifier logs, workload counters and app errors remain in the archives. Runtime admission checks, limits and per-program proofs added0. If the workload was not reached, this receipt records its setup error and zero observed requests; it does not establish whole-application coverage.
