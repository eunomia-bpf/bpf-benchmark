# Diagnostics

Patch shape:

- Adds `BITMASK_SIMPLE_VALUE_TYPES` for `INT`, `UINT`, `LONG`, `ULONG`, and
  `POINTER`.
- Adds `field_types_are_simple_values()` to recognize events whose six
  argument slots are all simple values or `NONE`.
- Adds `save_simple_value_args_to_submit_buf()` to save those arguments without
  the generic type table, type mask, and special pointer switch.
- Leaves the existing generic path unchanged for `STR`, `SOCKADDR`,
  `TIMESPEC`, byte arrays, integer arrays, credentials, and unknown types.

Diffstat:

```text
pkg/ebpf/c/common/buffer.h | 67 ++++++++++++++++++++++++++++++++++++++++++++--
1 file changed, 65 insertions(+), 2 deletions(-)
```

Expected performance mechanism:

- The hot syscall exit path continues to call `save_to_submit_buf()`, but avoids
  generic type classification for simple syscall events.
- This should apply to many `set`, `kill`, `eventfd`, `sigfd`, and `prctl`
  events in `stress_ng_tracee_syscall_hot`.

Object diagnostics after build:

| Object | Program section | Size |
| --- | --- | ---: |
| `tracee.bpf.o` | `raw_tracepoint/sys_enter_init` | `0x1218` |
| `tracee.bpf.o` | `raw_tracepoint/sys_enter_submit` | `0x7498` |
| `tracee.bpf.o` | `raw_tracepoint/sys_exit_init` | `0x0f10` |
| `tracee.bpf.o` | `raw_tracepoint/sys_exit_submit` | `0x5798` |

Artifacts checked:

- `vendor/build/.tracee-build/x86/dist/tracee.bpf.o` size `14968112` bytes.
- `vendor/build/x86/tracee/bin/tracee` size `83345376` bytes.

Observed verifier result:

- `sys_exit_submit` failed BPF load with `invalid access to map value`.
- The verifier could not prove the upper bound for the fallback
  `type_size_table[type]` lookup after the new simple-value check.
- This is a verifier-proof regression, so no performance samples were
  collected.

Conclusion: global `save_args_to_submit_buf()` restructuring is too risky for
Tracee phase2 without a verifier-focused rewrite. The next attempt should be
narrower and avoid adding a new helper-level prepass before the existing table
lookup.
