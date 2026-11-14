# Code reorganization, 2026-11-14 — `kprog/perf/native-context` -> `kprog/build`

Coordinator 2026-11-14T10:02:41Z (todo.md section 0): the lanes are split by code;
lane C owns the side that produces P. First item: one reorganization commit.

## What moved

| From | To | Files |
| --- | --- | --- |
| `kprog/perf/native-context/` | `kprog/build/` | 92 tracked (`git mv`, 0 under `build-x86/`) |
| `kprog/results/tracee-samesource-20261113/native-ir-prep.py` | `kprog/build/native-ir-prep.py` | 1 |
| `kprog/results/tracee-samesource-20261113/name-helpers.py` | `kprog/build/name-helpers.py` | 1 |
| `kprog/results/tracee-samesource-20261113/lower-tracee-asm.py` | `kprog/build/lower-tracee-asm.py` | 1 |
| `kprog/perf/katran-same-source.sh` | `kprog/build/katran-same-source.sh` | 1 |

96 renames total. `build-x86/` (60 of the 61 MB) is untracked build output and moved
with the tree; `kprog/build/build-*/` stays ignored by `.gitignore`.

Historical result directories (`kprog/results/perf_20261113/`,
`kprog/results/katran-samesource-20261113/`, `kprog/results/kprog_design_only_20261108/`,
`corpus/results/**`) are the record of the runs that produced them and are untouched;
their references to the old path are historical text.

## References updated

- `kprog/build/Makefile:4` (`HERE`), and the three `--exec 'make -f ...'` strings at
  lines 817/884/955.
- `kprog/build/{core-ir,packet-context,socket-context,tetragon-source}.md` (the
  documented invocations) and `socket-retain.py:53` (the compiler-commit lookup).
- `kprog/libnativeloader/Makefile` lines 202, 203, 249, 264, 269, 270.
- `kprog/x86/native_lab/native_link/src/{x86_probe_read,x86_lpm_lookup,x86_hash_lookup}.rs`
  (`kprog/build/test-{probe-read,lpm-lookup,hash-lookup}.c`).
- `kprog/trusted_service.py:233`.
- `vendor/bpf/Makefile:241` — `NATIVE_IR_PREP ?= $(CURDIR)/../../kprog/build/native-ir-prep.py`.
- `kprog/docs/todo.md` ownership table; `kprog/results/tracee-samesource-20261113/README.md`
  command lines.

## `.gitignore` defect found and fixed

`.gitignore:41` is a bare `build/`, which matched `kprog/build` and silently made the
whole new tree invisible to git (`git status` empty, `git ls-files` 0, the `git mv`
renames dropped from the index). Fixed by an exception plus an explicit output rule:

```gitignore
build/
# kprog/build is the same-source build pipeline (tracked source); only its
# own output directories are ignored.
!kprog/build/
kprog/build/build-*/
```

`git check-ignore -v kprog/build` no longer matches; `kprog/build/build-x86` still does
(`.gitignore:331 /kprog/**/build-*/`).

## Byte-identical check

Frozen benchmark paths are untouched (no file under `runner/libs/`, `corpus/`,
`micro/`, `Makefile`, `runner/mk/` was modified). Default native objects were hashed
before the move and rebuilt after it, then compared **against the image's own objects**
(the image is the authority; a `vendor/bpf` rebuild from the host BTF had perturbed one
pre-move reading — see below).

| app | compared to image | note |
| --- | --- | --- |
| bcc | 8/8 identical | |
| tracee | 3/3 identical | `tracee.native.o` = `fb3f51b3...` |
| cilium | 7/7 identical | |
| tetragon | 88/88 identical | |
| otel | 14/16 identical | `native_stack_trace`, `ruby_tracer` differ; both unchanged since 11-11 13:31 |
| katran | 1/4 identical | 3 differ; unchanged since 11-13 22:58 |
| **total** | **121/126** | the 5 remaining predate this reorg and were not touched by it |

Both arms of the same-source switches were exercised after the move:

- default (`BCC_SAME_SOURCE=0`): `opensnoop.native.o` = `d19552e4...` = image.
- same-source (`BCC_SAME_SOURCE=1`): `opensnoop.native.o` = `631fd4f0...` = the object
  this lane recorded before the move.

`make -f kprog/build/Makefile socket-context-check` runs from the new path: 29 context
accesses lowered, fixture PASS.

## Why a pre-move baseline reading moved (not caused by the reorg)

`vendor/bpf` defaults `VMLINUX_BTF ?= /sys/kernel/btf/vmlinux` (host 7.3.0-070300rc3)
while the sole kernel is 7.0.0-rc2+. A rebuild with that default regenerates
`targets/x86/7.0.0-rc2+/vmlinux.h`, `bcc/libbpf-tools/x86/vmlinux.h` and
`tetragon/bpf/include/vmlinux_generated_x86.h` from the **host** BTF, which changes the
BCC objects. Attribution, run deliberately on `opensnoop`:

| header source | header sha256 | resulting object |
| --- | --- | --- |
| host BTF | `762812f9...` | `5564ba28...` |
| sole kernel BTF | `39c424a6...` | `d19552e4...` = image |

`-B` rebuilds must therefore pass
`VMLINUX_BTF=/workspaces/.agent-state/kprog-ck/build-x86/vmlinux` (and
`KERNEL_RELEASE=$(cat .../include/config/kernel.release)`), or they silently swap the
tracked headers. After regeneration from the sole kernel's BTF both tracked headers are
byte-identical to `HEAD` again.