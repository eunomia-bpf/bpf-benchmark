# Whole Tracee with the generic C-copy readonly model

WholeTracee baseline151, generated6, compiled6, installed5, failures1; nativehashjoins6/6.

| Native entry | Generated | Compiled | Status | Final verifier observation |
| --- | ---: | ---: | ---: | --- |
| tracepoint__raw_syscalls__sys_enter | 1 | 1 | 0 |  |
| sys_enter_init | 1 | 1 | 0 |  |
| sys_enter_submit | 1 | 1 | 0 |  |
| tracepoint__raw_syscalls__sys_exit | 1 | 1 | 0 |  |
| sys_exit_init | 1 | 1 | 0 |  |
| sys_exit_submit | 1 | 1 | -5 | invalid access to map value, value_size=32536 off=65677 size=4096; processed 4951 insns (limit 1000000) max_states_per_insn 4 total_states 178 peak_states 172 mark_read 0 |

The complete original upstream application uses its existing native7479850e input and workload with the captured generic generator,70-row header and015a3096release linker. Service, result and runtime archives retain the actual terminal inputs and outputs; work.json carries the raw phase counters and errors. The baseline census and terminal native requests describe their own measured domains.
