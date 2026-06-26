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

Object diagnostics after build: TBD
