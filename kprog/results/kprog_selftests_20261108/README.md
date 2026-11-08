# Kernel BPF selftests on the five-step path, 2026-11-08

The kernel selftests are the upstream corpus of verifier programs. Each
program carries a BTF decl_tag in `progs/bpf_misc.h` saying whether the
verifier must accept or reject it:

```c
#define __failure  __attribute__((btf_decl_tag("comment:test_expect_failure")))
#define __success  __attribute__((btf_decl_tag("comment:test_expect_success")))
```

Those annotations are the ground truth this harness checks the native path
against, in place of programs built for the purpose.

Harness: `kprog/selftests/selftests.py`. Compile: `kprog/selftests/include/
vmlinux.h`, dumped from the same kernel with
`bpftool btf dump file vendor/build/x86/linux/vmlinux format c` (136,896
lines) because the vendored bcc header predates `bpf_rb_root`,
`bpf_res_spin_lock` and the arena helpers.

## Counts on the 2026-11-08 tree

| quantity | count |
| --- | ---: |
| `SEC(...)` declarations in `progs/*.c` | 5,000+ scanned, **1,917** annotated |
| annotated programs whose body is BPF inline asm | **1,248** |
| annotated programs whose body is ordinary C | **669** |
| of which `__failure` | 916 (all bodies) |
| of which `__success` | 1,001 (all bodies) |

Counted per program, not per file: a program is a `SEC("...")` declaration
followed by its own run of `__annotation(...)` attributes, so one program's
annotations cannot bleed into the next. The markers are matched exactly —
`__failure` must not match `__failure_unpriv`, and **77 upstream programs
carry `__success __failure_unpriv`**: they load privileged and fail
unprivileged, so reading the prefix would file them under failure.

## What compiles to native x86-64

| quantity | count |
| --- | ---: |
| files with no BPF-asm program | 180 total, **42 compile** |
| C programs inside compiling files | **200** |
| of those, a GLOBAL FUNC entry found | **128** |
| `__failure` / `__success` among them | 114 / 86 |

A file that contains any inline-asm program is excluded as a unit, because
one `asm volatile("r1 = 0; ...")` body makes the whole translation unit
uncompilable by the native compiler; in-clause the file's C programs share
that obstacle.

## The residue, and why it is inherent

291 C programs still fail to compile, in four causes:

| cause | count | nature |
| --- | ---: | --- |
| `use of unknown builtin '__builtin_preserve_field_info'` | 41 | BPF-target CO-RE builtin, not expressible in x86-64 C |
| `call to undeclared function 'bpf_res_spin_lock_irqsave'` | 31 | BPF kfunc, no x86-64 declaration |
| `redefinition of 'arena' with a different type` | 24 | BPF arena map type |
| `expected ')'` and other parse errors | 81+ | selftest-specific macros |

These are BPF-only constructs, so a native x86-64 compile cannot express
them however the includes are arranged. They are a coverage boundary of
*compiling* selftests natively, and the kernel's own `test_progs` remains
the runner for them.

## Per-program table

`kprog/selftests/build/programs.json` holds one row per annotated
program — file, program name, section, body kind, expectation, whether it
compiled, whether its entry symbol is present, and the compile error when
not.

## Status

Programs are enumerated and compiled; the submission half is pending the
five-step runtime that lane C is rewriting (`TRUSTED_CHUNK` immutable
chunks), since the corpus guest harness is being changed underneath it.
When that settles, each of the 128 compiled entries is submitted and its
outcome compared with the annotation: a `__failure` program that runs is a
faithfulness defect and goes to C with its source and B; a `__success`
program the verifier rejects is triaged between the native compile and the
simulator; a generation failure is coverage and goes to C.

AArch64 follows lane A's five-step port.