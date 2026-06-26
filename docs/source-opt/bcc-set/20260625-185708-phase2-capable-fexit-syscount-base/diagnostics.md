# Diagnostics

Patch shape:

- `capable`: removes `struct args_t` and `start` hash map, replacing
  `SEC("kprobe/cap_capable")` plus `SEC("kretprobe/cap_capable")` with one
  `SEC("fexit/cap_capable")`.
- `syscount`: stacks the first-round accepted early return for
  `args->id == -1` before `bpf_get_current_pid_tgid()` in `sys_exit`.

Build artifact checked:

- `vendor/build/.bcc-libbpf/x86/output/capable.bpf.o`
- `vendor/build/.bcc-libbpf/x86/output/syscount.bpf.o`

Object diagnostics after build:

| Object | Program sections | Instruction lines |
| --- | --- | ---: |
| `capable.bpf.o` | `fexit/cap_capable` size `0x4c0`; `.maps` size `0x88` | 133 |
| `syscount.bpf.o` | `sys_enter` size `0xf8`; `sys_exit` size `0x3a0`; `.maps` size `0x60` | 129 |

Expected performance mechanism:

- The previous `capable` version had two attached programs and a temporary
  hash-map handoff keyed by `pid_tgid`. This patch keeps one exit-side program
  and removes one map update, one map lookup, and one map delete from each
  successfully matched capability check.
- This is a larger semantic-preserving source rewrite than the first-round BCC
  attempts, but still uses the real libbpf-tools loader and does not change the
  benchmark workload, runner, or ReJIT path.
