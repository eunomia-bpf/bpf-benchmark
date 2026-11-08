# Kernel BPF selftests through the five-step path, 2026-11-08

The kernel's own `__success` and `__failure` annotations are the expected
outcome for each program.  This run compiles every C-written annotated
program to native x86-64 with the corpus toolchain, submits it through the
five-step path in the guest that boots the vendored kernel, and compares the
outcome with the annotation.

Reproduce with `kprog/selftests/run.sh` (one guest boot, host CPUs 0-7).

## Program population

The scan reads `vendor/linux-framework/tools/testing/selftests/bpf/progs` and
counts every `SEC("...")` program carrying `__success` or `__failure`:

| | count |
| --- | --- |
| annotated programs | 1,917 |
| written in C | 657 |
| BPF inline assembly (`__naked` or an `asm` body) | 1,260 |
| `__failure` | 916 |
| `__success` | 1,001 |

The inline-assembly programs stay with the kernel's `test_progs`, as the task
says.  Of the 657 C programs, 128 are in a file that compiles and whose entry
symbol the native compiler emits; those 128 are the sweep.

Each program is compiled into its own BPF object, because the kernel groups
several programs into one section and libbpf reads a program's type off that
section.  `selftests.py` comments the sibling programs out of the translation
unit, so all 126 generated objects hold exactly one program.

## Totals

| outcome | count |
| --- | --- |
| submitted | 33 |
| ran (native path executed) | 1 |
| refused by the specializer | 10 |
| native path not reached | 22 |
| skipped before submission | 95 |

Of the programs whose native path ran, `success` agrees **1**; `failure`
agrees **0** and disagrees **0**, because no `__failure` program reached the
specializer in this run.

The 10 refusals are all `__success` programs, so they are the case the task
calls a rejection to triage between the native compile and the simulator.  No
`__failure` program ran, so this run reports no faithfulness defect.

## Why 95 programs were skipped

Every one of the 95 carries a program type the five-step stub does not
create.  The runner's stub supports three types
(`runner/src/native_lab_runner.cpp:47-52`): `xdp`, `sched_cls` and
`cgroup_skb`.  The rest are `sock_addr`, `sk_msg`, `iter`, `kprobe`,
`crypto`, `struct_ops` and others.  This is a bound of the stub, so
widening it is `runner` work for lane C.

The 13 objects that a previous run could not build now build: a program
was being removed together with a following sibling's global declarations,
and the removal now ends at the program's own closing brace.

## Why 22 programs did not reach the native path

The loader decides these before submitting:

| cause | count |
| --- | --- |
| companion BPF object failed to load (`EPERM`) | 8 |
| companion BPF object failed to load (`EINVAL`) | 8 |
| companion BPF object failed to load (`E2BIG`) | 1 |
| section has no type libbpf can infer (`?tc`, `?xdp`) | 4 |
| companion object loaded, its own run failed | 1 |

A `?`-prefixed section marks a section libbpf may see repeated; the companion
object opened from a single re-emitted `?tc` section has no type, so it fails
to load.  Each of these settles the outcome before the native path runs.

## The 10 refusals the specializer made

The specializer's rejection is a native-path verdict, so it is real evidence.
The named mechanism is the kernel's 512-byte stack: the native stub's frame
and the program's own stack share those bytes.  `global_func2` uses 248 bytes,
and the verifier reports `invalid write to stack R10 off=-528`.

## The one agreement

`global_func8` (`test_global_func8.c`) is a `__success` program: the whole
object holds one program, the companion BPF object loads, the specializer
accepts the native program, and it runs.  This is the first program that
exercises the complete five-step path end to end and agrees with the kernel's
annotation.

## Harness defects found by running it

Each of these was found by executing the path, and each is fixed:

- The BPF compile drove the host linker without `-c`, which cannot relink a
  BPF object (`Relocations in generic ELF (EM: 247)`).
- libbpf refuses an object with no `license` section, which several selftests
  omit; the harness supplies one.
- The native compile omitted `-mno-red-zone` and `-mgeneral-regs-only`, so
  the frame landed outside the stack the verifier models (`R10-1312`).
- The agreement count included programs whose companion BPF object failed to
  load.  Those settle before the native path runs, so their apparent
  agreement was vacuous; only a program the specializer accepted or rejected
  counts, and `ran` for the rest.

## Environment

The lab module is built for `kprog/tv/build-kernel-x86`, so it only loads in a
guest booted from that tree's image; the host kernel differs and rejects the
module on vermagic.  The module must be built with
`KDIR=kprog/tv/build-kernel-x86`, because the default points at a different
output directory and yields a symbol-version mismatch.

`trusted-native-loader` must be rebuilt from `kprog/trusted_loader.cpp` when
`native_loader.cpp` changes; a stale binary looks for a `blob%u` interface the
current module does not create.