# Tetragon's native arm dies on `event_wake_up_n`

Measured 2026-11-16 06:10-06:52Z on the one image (`bpf-benchmark/kprog:current`,
`d9e29630`), kernel `7.0.0-rc2+`, one 10 s sample per run on CPUs 16-23, the
rotate on 0-7 untouched. Every run below is a full `make -f
kprog/perf/one-image/Makefile corpus APPS=tetragon/observer`, varying only
`NATIVE_MANIFEST`; the payload is a hardlink copy of the stage under
`corpus/results/tet-manifest-ab-20261116/` (symlinks do not resolve inside the
guest, which invalidated an earlier attempt).

| manifest | entries | replacements | outcome |
|---|---|---:|---|
| `manifest.json` (canonical) | 94 | 6 | dies |
| `manifest-noentry.json` (drops `tg_kp_bprm_comm`) | 93 | 6 | dies |
| `manifest-six.json` | 6 | 6 | dies |
| `manifest-four.json` | 4 | 4 | dies |
| `manifest-three.json` | 3 | 3 | dies |
| `manifest-wake.json` (`event_wake_up_n` alone) | 1 | 1 | **dies** |
| `manifest-acctwake.json` (`event_exit_acct` + `event_wake_up_n`) | 2 | 2 | dies |
| `manifest-two.json` (`event_exit_acct` + `event_exit_disa`) | 2 | 2 | ok |
| `manifest-1entry.json` (`event_exit_disa`) | 1 | 1 | ok |
| `manifest-acct.json` (`event_exit_acct`) | 1 | 1 | ok |
| `manifest-empty.json` (no match) | 0 | 0 | error, EINVAL on `event_exit_acct_process` |

**`event_wake_up_n` is the trigger.** Across all twelve runs the separation is
perfect: every failing set contains it, no passing set does. An earlier reading
of this table as a *replacement-count* ceiling (3 and up die, 2 and below pass)
was a coincidence of how the sets were built — every set with three or more
entries contained `event_wake_up_n` because it sorts into the first three.

## The failure is in execution, not in load

`manifest-wake.json` replaces one program and then dies ~6 s later, on a
completely different program's load:

```
[126.586053 pid=1949 tid=1956] native-loader replaced prog=event_wake_up_n original_fd=71 native_fd=87 ...
[132.676577 pid=1949 tid=1964]   PROG_LOAD -> fd=476 errno=0 kernel_prog_id=416
[132.677990 pid=1949 tid=1964] BPF_PROG_LOAD type=2 (kprobe) name=generic_kprobe_ insn_cnt=2919 ...
```

Replacement and attachment both succeed; the native program then runs under
`stress_ng_tetragon_policy_hot` for about six seconds before the VM stops. So
the fault is in the replaced program's native code or in what the shim left
behind after swapping it — not in the loader's load path, which is where the
search was pointed by the earlier count reading.

The replacement itself looks successful by the shim's own report:

```
native-loader jit-info original fd=71 id=335 type=2 name=event_wake_up_n tag=edddb22551cf50f2 jited_len=7339 ...
native-loader jit-info native   fd=87 id=336 type=2 name=event_wake_up_n tag=59f4a931744dcdc6 jited_len=4900 ...
```

Its manifest entry is the one entry in the 94 that maps to
`bpf_fork_v511.native.o`:

```json
{"native_object": "bpf_fork_v511.native.o",
 "program": "event_wake_up_n",
 "source_lacks_helper": 174,
 "symbol": "event_wake_up_new_task"}
```

`source_lacks_helper: 174` is `get_attach_cookie`: the object's source does not
call that helper, so the linker had to prove a helper call away or leave one
unbound. The other seven entries carrying `source_lacks_helper: 174`
(`event_execve`, `event_exit_acct`, `event_exit_disa`, `execve_map_upda`,
`execve_rate`, `execve_send`, and the generic families) do not die, and
`event_exit_acct`/`event_exit_disa` were each verified alone. So the helper is
necessary context but not sufficient to explain it; what is unique to
`event_wake_up_n` is the `bpf_fork_v511` object and the `event_wake_up_new_task`
symbol.

## Silence

No `result.json`, no `details/apps/`, no kernel message. A guest `dmesg -c`
stream written into the repository captured the boot through `[34.4 s]` and
nothing at the crash; the host `dmesg` shows no fault at the crash times; and a
monitor-enabled run with `oops=panic` removed
(`/workspaces/kprog-raw/one-image-runs/tet-monitor.log`, 3 entries) died the
same way with no `Oops`, `panic`, `RIP:`, `BUG:` or trace in the captured
output. The vng invocation normally carries `oops=panic`, so a guest oops
would take the VM down whole — which is what the run looks like — but nothing
prints it, even with the monitor on.

## Next

The trigger is now one program with one native object, so the shortest path is
out of the guest: run the `bpf_fork_v511.native.o` build of
`event_wake_up_n` in the simulator against its intercepted BPF original
(`kprog/x86/`), and compare the two instruction streams at the
`get_attach_cookie`-shaped site. Anything that reproduces the death outside the
VM turns a silent VM crash into a comparable trace.