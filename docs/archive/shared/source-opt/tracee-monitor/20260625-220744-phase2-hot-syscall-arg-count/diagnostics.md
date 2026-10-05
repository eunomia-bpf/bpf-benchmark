# Diagnostics

Patch shape:

- Adds an x86-only `tracee_hot_syscall_arg_count()` helper for stress-ng hot
  syscall IDs.
- Moves the existing compat syscall ID translation before argument reads, so
  the arg-count helper sees canonical 64-bit syscall IDs.
- Gates each register argument read in `sys_enter_init()` with `arg_count > N`.
- Leaves arm64 and unlisted x86 syscall IDs on the original six-argument path.

Diffstat:

```text
pkg/ebpf/c/tracee.bpf.c | 90 ++++++++++++++++++++++++++++++++++++++-----------
1 file changed, 70 insertions(+), 20 deletions(-)
```

Expected performance mechanism:

- `eventfd`, `setuid`, `setgid`, `setfsuid`, and `setfsgid` read one argument
  instead of six.
- `kill`, `tkill`, `capget`, `capset`, `setreuid`, `setregid`, and `eventfd2`
  read two arguments instead of six.
- `tgkill`, `setresuid`, `setresgid`, and `signalfd` read three arguments
  instead of six; `signalfd4` reads four; `prctl` reads five.

Object diagnostics after build:

| Object | Program section | Size |
| --- | --- | ---: |
| `tracee.bpf.o` | `raw_tracepoint/sys_enter_init` | `0x1568` |
| `tracee.bpf.o` | `raw_tracepoint/sys_enter_submit` | `0x7498` |
| `tracee.bpf.o` | `raw_tracepoint/sys_exit_init` | `0x0f10` |
| `tracee.bpf.o` | `raw_tracepoint/sys_exit_submit` | `0x4fc8` |

Artifacts checked:

- `vendor/build/.tracee-build/x86/dist/tracee.bpf.o` size `14896456` bytes.
- `vendor/build/x86/tracee/bin/tracee` size `83271648` bytes.

Observed result:

- Formal result: `corpus/results/x86_kvm_corpus_20260626_051548_824007`
- Correctness passed: app `status=ok`, `error=""`, 3 workload samples,
  `post_rejit=null`, `rejit_result.mode="skip_rejit_all"`.
- Performance samples: `453757.34`, `460873.01`, `456240.77`
  `stress_ng_sum_bogo_ops_s`; mean `456957.04`.
- Compared with the clean-source baseline mean `460865.35`, this is -0.85%.

Interpretation:

- The reduced register reads were not enough to offset the added syscall-id
  branch structure in `sys_enter_init()`.
- This patch is rejected as no-signal and should not be used as a stacked base.
