# Whole Tracee on canonical stack spill representation

Whole Tracee: baseline151, generated3, compiled3, installed2, failed1, native hash joins3/3.

| Native entry | Generated | Compiled | Status | Verifier observation |
| --- | ---: | ---: | ---: | --- |
| tracepoint__raw_syscalls__sys_enter | 1 | 1 | 0 |  |
| sys_enter_init | 1 | 1 | 0 |  |
| sys_enter_submit | 1 | 1 | -5 | 23953: (18) r2 = 0xffff89d485dd8000   ; R2=map_ptr(map=stack_addresses,ks=4,vs=160); 23956: (85) call bpf_get_stackid#27 |

Complete original application, existing two-second workload, captured runtime image and captured model d963788c0. Baseline resident census and terminal native requests retain distinct measured domains. Complete input bytes, generated C/BPF, per-request stock-verifier logs, workload counters and app errors remain in the archives. Runtime admission checks, limits and per-program proofs added0. If the workload was not reached, this receipt records its setup error and zero observed requests; it does not establish whole-application coverage.
