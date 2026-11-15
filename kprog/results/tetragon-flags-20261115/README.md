# Tetragon native flags: they match upstream object for object

Task (lane C, 2026-11-15): audit `vendor/bpf/Makefile`'s `native-tetragon` compile flags against
Tetragon's own `bpf/Makefile`, now that the source guards are gone (`36357fe87`). The question is
whether the native objects are compiled the same way upstream compiles the eBPF objects they
replace — same `-D` set per object, same object inventory — so a native/eBPF comparison is equal
work rather than a different program.

Result: **the `-D` flags match upstream on all 76 compile targets**, and the object inventory
differs only by objects that a 7.0 kernel never loads.

## Variant and per-object defines

Upstream (`vendor/bpf/tetragon/bpf/Makefile:146-155`) defines five variants and four
per-object rules:

| upstream | flags |
|---|---|
| `CFLAGS_v310` | `-D__RHEL7_BPF_PROG` |
| `CFLAGS_v53` | `-D__LARGE_BPF_PROG` |
| `CFLAGS_v511` | `-D__LARGE_BPF_PROG -D__V511_BPF_PROG` |
| `CFLAGS_v61` | `-D__LARGE_BPF_PROG -D__V511_BPF_PROG -D__V61_BPF_PROG` |
| `CFLAGS_bpf_enforcer.o` | `-D__BPF_OVERRIDE_RETURN` |
| `CFLAGS_bpf_multi_enforcer.o` | `-D__BPF_OVERRIDE_RETURN -D__MULTI_KPROBE` |
| `CFLAGS_bpf_generic_lsm_core.o` | `-D__LARGE_BPF_PROG` |
| `CFLAGS_bpf_generic_lsm_output.o` | `-D__LARGE_BPF_PROG` |

Parsing `native-tetragon`'s `compile_native` calls and applying those two rules to each target
name gives 76 targets, and **every one matches** the flags in the rule. The four targets that
look like mismatches at first (`bpf_generic_lsm_{core,output}_v{511,61}`) are the duplicate
`-D__LARGE_BPF_PROG` that results from the object rule and the variant rule both supplying it;
duplicate `-D` is a no-op, so they are equivalent. `bpf_multi_*` targets carry `-D__MULTI_KPROBE`
as upstream's generated `CFLAGS_bpf_multi_<x>_$$(VAR).o` rules do (`Makefile:208-211`).

The whole build shares `NATIVE_CFLAGS` (operator 2026-11-15: "编译参数所有 app 统一") plus two
Tetragon-specific flags in `common_flags`: `-D__TARGET_ARCH_x86`, which upstream's
`Makefile.defs:35` sets, and `-fms-extensions`, which upstream does not set.

`-fms-extensions` is a correctness flag, not cosmetics. Tetragon's C declares a named member
anonymously (`struct outer { struct inner; … }`) and uses `inner`'s fields directly. Upstream
compiles it with `-target bpf`, where clang accepts that as an extension; on the default x86
target clang only emits `warning: declaration does not declare anything` and the member is
absent, so every `o->b` would fail. Measured on a two-struct fixture: without the flag the
declaration is dropped, with it the fields resolve.

`-D__TARGET_ARCH_x86` is upstream's (`Makefile.defs:35`). The `-I` set in `common_flags` is
upstream's `CLANG_FLAGS` include list (`-I $(LIBBPF) -I $(IDIR) -I $(LDIR)
-I $(ERRMETRICS_DIR)`) written out, plus the two system paths.

## Object inventory

88 native objects against upstream's 95. The seven absent:

| object | why absent |
|---|---|
| `bpf_alignchecker` | an alignment-checker program, loaded by the Go side outside the sensor set |
| `bpf_lseek`, `bpf_lseek_v511` | `BPFTEST`, upstream's own test program list (`Makefile:114-115`) |
| `bpf_map_test_p1..p3` | upstream's map API test programs (`Makefile:35`) |
| `object` | a parse artifact of the string "`object.o`" in the upstream comments |

So every *sensor* object upstream builds for this kernel's version line exists natively, and the
gap is test-only programs plus one checker. The eight program families that actually ran in
`x86_kvm_corpus_20261115_011551_351670` (`event_execve`, `event_exit_acct`, `event_wake_up_n`,
`generic_kprobe_`, `generic_rawtp_e`, `generic_retkpro`, `generic_tracepo`, `tg_kp_bprm_comm`)
are all covered: 288 of 577 loads took a native replacement.

## What is *not* claimed

This is a flags audit, not an equal-work proof. Two things it does not cover:

- **Load-time-generated programs.** Tetragon builds CEL filter bodies at load time; those have
  no source object at all and no native replacement. Earlier notes put Tetragon at 288 native of
  577 loads, and the difference is exactly this.
- **The guards that were removed.** `36357fe87` made `lib/bpf_d_path.h` and
  `lib/process.h` follow `lib/config.h`'s existing pattern, so the eBPF arm keeps upstream text
  and only the native arm substitutes. Flags matching does not by itself prove the substituted
  expressions are equivalent; that is what the object-level byte comparison covers
  (`../tetragon-samesource-20261114/README.md`: 88 native objects byte-identical to the image's,
  apart from two map-pointer immediates).

Reproduce the flag comparison: parse `compile_native` calls from `vendor/bpf/Makefile`'s
`native-tetragon` rule, expand `$${name}` suffixes, and apply `CFLAGS_<variant>` plus
`CFLAGS_<object>.o` from `vendor/bpf/tetragon/bpf/Makefile`.

## Build state at the time of this audit

The flag comparison is read off the Makefiles, which is exact regardless of whether the tree
builds. It does not: `native-tetragon` and `native-bcc` fail at HEAD because the CO-RE builtins
(`__builtin_preserve_field_info`, `…_type_info`, `…_enum_value`, `__builtin_preserve_access_index`)
exist only for clang's `bpf` target, and the native objects are x86-64. `native-katran`,
`native-otel`, `native-tracee` still build (0 errors). This is the state `kprog/docs/todo.md:14`
records — "编译暂时会失败，由 lane 在设计路线上重建" — and the rebuild is C-HDR, which replaces the
deleted `native_compat.h` with a compatibility header. The 88 objects and their byte comparison
above predate `2f83ebd4b`; they describe the flags that built them, not a currently reproducible
build.