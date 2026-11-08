# Whole Tracee with exact immutable-byte values

Whole Tracee: baseline151, generated6, compiled6, installed5, failed1. Native archive joins6/6.

| Entry | Generated | Compiled | Status | Final verifier observation |
| --- | ---: | ---: | ---: | --- |
| tracepoint__raw_syscalls__sys_enter | 1 | 1 | 0 |  |
| sys_enter_init | 1 | 1 | 0 |  |
| sys_enter_submit | 1 | 1 | 0 |  |
| tracepoint__raw_syscalls__sys_exit | 1 | 1 | 0 |  |
| sys_exit_init | 1 | 1 | 0 |  |
| sys_exit_submit | 1 | 1 | -5 | invalid access to map value, value_size=32536 off=65677 size=4096; processed 4951 insns (limit 1000000) max_states_per_insn 4 total_states 178 peak_states 172 mark_read 0 |

The complete original upstream Tracee startup and workload use the existing native7479850e epoch and the paired five-step runtime. `coverage.json` retains all terminal requests and application records. `service.tar.gz`, `result.tar.gz` and `runtime.tar.gz` hold the original service, framework, compiler and launch records. `work.json` retains the raw baseline and native work records, application status and errors. Generated and installed counts describe terminal native requests; the baseline census describes resident application programs.
