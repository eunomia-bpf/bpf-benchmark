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
## What the object shows

`bpf_fork_v511.native.o` (942 624 B, stage, built 2026-11-15 20:13Z) has one
code section, `kprobe/wake_up_new_task`, 0xc95 bytes, and no undefined helper
symbols: only `memcpy` and `memset` are undefined, and the 34 relocations are
`execve_map`/`execve_val`/`execve_map_stats`/`tg_conf_map`/`tg_cgtracker_map`/
`cgroup_rate*_map` GOTPCRELX plus the two libc calls. So the helper calls are
not ELF relocations; every one is an indirect call through a register that was
just loaded with the helper id as an immediate:

```
30: b8 04 00 00 00   movl $0x4, %eax
35: b9 71 00 00 00   movl $0x71, %ecx
3a: be 04 00 00 00   movl $0x4, %esi
3f: ff d1            callq *%rcx
```

`0x71` is helper 113, `bpf_probe_read_kernel`; the object uses it 20 times and
id 1 (`bpf_map_lookup_elem`) 20 times. Helper 174 (`bpf_get_attach_cookie`,
the `source_lacks_helper: 174` marker) never appears as an immediate — 174 is
0xae and no `movl $0xae` exists in the object.

All 94 manifest entries carry `"patches": []`, so no entry patches a call site;
the loader resolves helper ids to addresses itself through the kernel's
`helper_targets` debugfs query (all 212 canonical helpers, one query per
program) and the native-link plan binds them by name. Two consequences:

- The `source_lacks_helper: 174` marker is a *selection* filter, not a claim
  about this object's code: it only decides which tetragon program each entry
  may bind to.
- The helper id immediates are exactly what a BTF-typed `call` instruction
  compiles to, so an unresolved one would call a user-space address with a
  kernel calling convention. That is a silent tri-fault or a corrupted return,
  not an error return — consistent with the guest dying with no printed oops.

Worth noting for whoever picks this up: `0x71`-immediate call sites exist in
the object 20 times, and the `movl $0x4,%eax; movl $0x71,%ecx; callq *%rcx`
shape seen at offset 0x30 sets `%rax` (the helper id register for the call)
to 4 while the id is in `%rcx`, which is not the shape the kernel's JIT emits
for a direct helper call. That site is the first thing to compare against the
intercepted BPF original.

## Why the odd call shape is a lead and not yet the bug

`native-link` refuses to emit code with an unresolved register-indirect call:
`kprog/x86/native_lab/native_link/src/x86.rs:1585` bails with "x86 unresolved
register-indirect call in <sym> at local offset <n> through <reg>; helper calls
must be rewritten before kernel load". Since the load succeeded and the
replacement went in, every indirect call in this object *was* resolved — the
shim's `native-loader replaced` line would not exist otherwise.

So the shape difference is not an unresolved site. It narrows the question to
what the resolved target was:

- every other app's objects put the id in `%rax` (`movl $0x1,%eax; callq
  *%rax` in `balancer.native.o`, and `biosnoop.native.o` has no indirect calls
  at all), matching the helper-id-in-`%rax` convention;
- this object has the id in `%rcx` at 20 sites and `%rax` holding something
  else (`movl $0x4,%eax; movl $0x71,%ecx; movl $0x4,%esi; callq *%rcx`), where
  `0x71` is `bpf_probe_read_kernel` and the arguments read as
  `probe_read_kernel(dst, 4, src)`.

The provenance pass follows register families (`x86_gpr64_family`), so a
`%ecx`-held id should bind to the same helper as a `%eax`-held one — which is
exactly the thing to verify with `native-link`'s own output rather than by
reading the pass. `native-link` has a `show` path that prints
`native-link-helper-site {symbol, input_offset, helper, map, proof_mode}`, and
running the fork object through it is a single command outside the guest; it
answers whether the site bound to `bpf_probe_read_kernel` or to something else.
That is the next step, and it does not need a VM.
