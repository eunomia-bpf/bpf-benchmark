# Tracee on initialized inactive ghost pointer storage

Whole Tracee: baseline151, generated6, compiled6, installed5, failed1, native joins6/6.

Private generic representation initializes named and array ghost pointer cells to0 while their existing initial tags remain scalar. Raw native stack bytes, architectural GPRs, memory operations, flags and control flow retain their existing expressions. Existing pointer-overlap/lifetime native-host comparisons,30micro compiler controls and the captured full Tracee compilation retain their actual logs. Canonical source adoption0; runtime admission additions0.

| Native entry | Generated | Compiled | Status | Verifier observation |
| --- | ---: | ---: | ---: | --- |
| tracepoint__raw_syscalls__sys_enter | 1 | 1 | 0 |  |
| sys_enter_init | 1 | 1 | 0 |  |
| sys_enter_submit | 1 | 1 | 0 |  |
| tracepoint__raw_syscalls__sys_exit | 1 | 1 | 0 |  |
| sys_exit_init | 1 | 1 | 0 |  |
| sys_exit_submit | 1 | 1 | -5 | 12222: (18) r2 = 0xffff88fe5acf8000   ; R2=map_ptr(map=stack_addresses,ks=4,vs=160); 12225: (85) call bpf_get_stackid#27   ; R0=scalar() |

The whole original Tracee application retains the existing image/native inputs and two-second workload. Baseline resident census and submitted terminal requests have distinct domains. Runtime compilation uses the fresh registered service and host compiler broker. [runtime.tar.gz](runtime.tar.gz), [service.tar.gz](service.tar.gz) and [result.tar.gz](result.tar.gz) retain complete captured inputs, generated C/BPF, compiler, verifier and raw work evidence. Universal inactive-ghost/compiler erasure remains with V.
