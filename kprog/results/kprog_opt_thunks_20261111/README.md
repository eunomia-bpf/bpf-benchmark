# External thunks: why the current-ABI payloads are larger and do not link

Measured 2026-11-11 02:00 UTC by lane C (optimization track), after
`/var/tmp/kprog-tmp` was wiped at 01:19 UTC and the ART was rebuilt from
repo-side sources.

## Cilium: body size

Same program, `cil_from_host` in `bpf_host.native.o`:

| object | instructions | helper-call shape | undefined symbols |
| --- | ---: | --- | --- |
| archive, `vendor/build/native-bpf/x86/7.0.0-30-generic` | **734** | `callq *%rax`, one instruction | none |
| current-ABI payload, `current-abi-app-payloads/cilium` | **1,407** | `callq __x86_indirect_thunk_r11` | `__x86_indirect_thunk_r11`, `__x86_return_thunk` |

1.92x the instructions, 68 thunk relocations. This is the 1.299x
native/JIT body ratio against the archive objects' 1.049x, and at a ~4%
BPF share it accounts for the throughput drop from 1.319x to
1.006x-1.068x.

## Tracee: link failure on the 2026-05-29 image

The same objects fail the 2026-05-29 link boundary:

```
Error: x86 helper call __x86_indirect_thunk_r11 has no helper address
```

Reproduced by building the frozen linker from
`git show 9f3855f6f:native-sim/x86/native_lab/native_link` and linking
`current-abi-app-payloads/tracee`'s `tracee.native.o`.

Rebuilt with the canonical producer (`make -C vendor/bpf native-tracee`):
zero thunk symbols, the same 173 programs, and `sys_enter_submit` links
through both linkers — 13,756 bytes on the 2026-05-29 linker and 13,759 on
the current one, which inlines one tail call the older keeps as a call.

## Cause

The payloads were compiled with
`-mretpoline-external-thunk -mfunction-return=thunk-extern -fcf-protection=branch`.
These appear in the Tracee payload's `native-only.mk` and in the payload's
own stale copy of `cilium_native_build.py` line 279. The tree's canonical
producers, `vendor/bpf/Makefile` line 52 and
`runner/libs/cilium_native_build.py` line 279, carry none of them.

## Fix

Regenerate the Cilium and Tracee payloads with the canonical producers, as
`87a028418` did for Katran. That gives bodies near the archive size and
objects both linkers accept, so one image can carry all six best object
sets. Runtime checks added: 0.

## Tracee: recovering the size with the canonical producer

Summing the text bytes of all 173 programs in `tracee.native.o`:

| object | text bytes |
| --- | ---: |
| current-ABI payload | 1,823,858 |
| rebuilt with `vendor/bpf/Makefile` | **1,625,441** |

An 11% reduction from removing the thunk indirection alone, before any
linker-side inlining. `sys_enter_submit` then emits a 13,759-byte blob
through the current linker and 13,756 through the 2026-05-29 linker; the
thunked object emits nothing on either without a thunk stub.
