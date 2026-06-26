# Diagnostics

Patch shape:

- Stacks phase2 attempt 3: `capable` fexit rewrite plus raw-tracepoint
  `syscount`.
- Adds `sys_exit_latency`, another `raw_tracepoint/sys_exit` program that
  always performs latency accounting.
- Updates `syscount.c` to attach `sys_exit_latency` when `env.latency` is true,
  otherwise attach the existing `sys_exit`.

Build artifact checked:

- `vendor/build/.bcc-libbpf/x86/output/capable.bpf.o`
- `vendor/build/.bcc-libbpf/x86/output/syscount.bpf.o`
- `vendor/build/.bcc-libbpf/x86/output/syscount.skel.h`

Object diagnostics after build:

| Object | Program sections / symbols | Size or instruction lines |
| --- | --- | ---: |
| `capable.bpf.o` | phase2 attempt 3 base, `fexit/cap_capable` | unchanged from attempt 3 |
| `syscount.bpf.o` | `sys_enter` symbol size `0xf8` | 31 insns |
| `syscount.bpf.o` | non-latency `sys_exit` symbol size `0x308` | 97 insns |
| `syscount.bpf.o` | attached latency `sys_exit_latency` symbol size `0x388` | 113 insns |
| `syscount.bpf.o` | total object instruction lines | 214 |

Expected performance mechanism:

- Phase2 attempt 3 attached a generic raw `sys_exit` of size `0x3c8`.
- This attempt attaches `sys_exit_latency` of size `0x388` in `-L` mode,
  removing the runtime `measure_latency` checks on the bcc/set hot path.
- Total object size increases because the non-latency program is retained for
  correctness, but it is not attached during bcc/set.

Observed performance:

- Formal result:
  `corpus/results/x86_kvm_corpus_20260626_031853_909472/details/apps/bcc__set.json`
- `stress_ng_sum_bogo_ops_s` samples: `713487, 715830, 716731`
- Mean: `715349`
- Relative to clean baseline mean `710465`: `+0.69%`
- Relative to phase2 attempt 3 mean `724628`: `-1.28%`
- Interpretation: reducing the attached latency exit program by a small number
  of instructions was not enough to improve the measured workload. The next
  attempt should target a larger source-level change and should not use this
  patch as the stacked base.
