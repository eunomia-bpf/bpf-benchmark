# Tetragon's native arm dies once the replacement count reaches 3

Measured 2026-11-16 06:10-06:38Z on the one image (`bpf-benchmark/kprog:current`,
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
| `manifest-three.json` | 3 | 3 | **dies** |
| `manifest-two.json` | 2 | 2 | **ok** |
| `manifest-1entry.json` (`event_exit_disa`) | 1 | 1 | ok |
| `manifest-acct.json` (`event_exit_acct`) | 1 | 1 | ok |
| `manifest-empty.json` (no match) | 0 | 0 | error, EINVAL on `event_exit_acct_process` |

The crash depends on **how many programs were replaced**, not on which programs
they are: the canonical entry set dies at 6, an arbitrary 4 die, an arbitrary 3
die, two arbitrary entries are fine, and either of two single entries alone is
fine. The first suspect — the `tg_kp_bprm_comm` entry, whose manifest entry
carries `source_lacks_helper: 174`, helper 174 being `get_attach_cookie` — is
not the cause: dropping that entry still dies at 6.

The death is silent. No `result.json`, no `details/apps/`, no kernel message: a
guest `dmesg -c` stream written into the repository captured the boot through
`[34.4 s]` and nothing at the crash, and the host `dmesg` shows no fault at the
crash times. The shim log ends on a complete line, mid-load sequence:

```
native-loader no manifest match for prog=generic_kprobe_ ...
  PROG_LOAD -> fd=477 errno=0 kernel_prog_id=417
BPF_PROG_LOAD type=2 (kprobe) name=generic_kprobe_ insn_cnt=3634 ...
```

with no `PROG_LOAD ->` for that load. In every failing run the last completed
action is the Nth replacement and the next `BPF_PROG_LOAD` is the one that
never returns; the program in flight differs between runs (`tg_kp_bprm_comm`
with the canonical manifest, `execve_map_upda` with the no-entry one,
`generic_kprobe_` with three), which is what rules out a single program.

The vng invocation carries `--append '... oops=panic'`, so a guest kernel oops
would terminate the VM — consistent with the whole run vanishing rather than the
app exiting. That the app's own stderr never appears, and that the `make` level
reports only `Error 255` with no driver traceback, point the same way.

Checked with the monitor on and `oops=panic` removed
(`/workspaces/kprog-raw/one-image-runs/tet-monitor.log`, run
`corpus/results/x86_kvm_corpus_20261116_064048_412955`, three entries): the run
still died at the fourth load, 3 replacements, and no `Oops`, `panic`, `RIP:`,
`BUG:` or trace appears in the captured output. So the VM-level silence is not
an artifact of `--disable-monitor` and not a suppressed-oops print; the console
simply carries nothing.

Not explained yet: why the count matters, and what the shim or loader does on
the (N+1)-th load that it does not do earlier. Two next steps: the console is a
dead end, so the next signal has to come from the process itself — a wrapper
that catches the death and reports the last shim entry point entered, or the
loader run under a debugger in the guest; and tetragon's baseline arm exercises
the same 94-load sequence without dying, which bounds the fault to the
replacement path rather than tetragon's load sequence.