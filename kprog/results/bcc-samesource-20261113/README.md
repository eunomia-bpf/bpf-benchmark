# BCC from untouched upstream source (C3's same-source half)

Why BCC is not yet same-source, measured, and the one decision it needs.

## Only tcplife differs, and only in one number

The source audit lists two differing BCC files: `tcplife.bpf.c` (D18) and the generated
`x86/vmlinux.h`. Compiling all eight shipped tools **from the untouched upstream sources**
with the native rule's own flags gives `.rodata` sizes identical to the shipped objects for
seven of them:

| tool | upstream `.rodata` | shipped `.rodata` | |
|---|---:|---:|---|
| capable | 16 | 16 | same |
| biosnoop | 8 | 8 | same |
| vfsstat | — | — | same (no .rodata) |
| opensnoop | 13 | 13 | same |
| syscount | 48 | 48 | same |
| tcpconnect | 280 | 280 | same |
| runqlat | 12 | 12 | same |
| **tcplife** | **4118** | **4106** | **differs** |

(`rodata-layout.json` in this directory is the raw table.)

## What the tcplife difference is

`tcplife.bpf.c` in this tree adds, under `MICRO_NATIVE` only, an explicit small alignment to
four globals:

```c
const volatile __u16 target_sports[MAX_PORTS] NATIVE_RODATA_ALIGN(2) = {};
const volatile __u16 target_dports[MAX_PORTS] NATIVE_RODATA_ALIGN(2) = {};
const volatile pid_t target_pid               NATIVE_RODATA_ALIGN(4) = 0;
const volatile __u16 target_family            NATIVE_RODATA_ALIGN(2) = 0;
```

`NATIVE_RODATA_ALIGN` is empty when `MICRO_NATIVE` is not defined, so the eBPF arm is
unaffected. The four globals lay out as:

| | upstream + align(2/4) (shipped) | upstream, no attribute |
|---|---:|---:|
| `target_sports` | 2 | 16 |
| `target_dports` | 2050 | 2064 |
| `target_pid` | 4100 | 4112 |
| `target_family` | 4104 | 4116 |
| section size | **4106** | **4118** |

The `2` comes from the two `const volatile bool` flags that precede the arrays: with the
attribute the arrays pack right after them; without it `.rodata`'s 16-byte section
alignment pushes the first array to 16. I could not reproduce the packed layout with a
compiler flag — `-fno-common`, `-fdata-sections`, `-malign-data=compat`,
`-mprefer-vector-width=64`, `-mno-sse`, `-fno-tree-vectorize`, `-mllvm
-align-all-globals=N` (the last is not even a clang option) all leave `target_sports` at 16,
because the offset is set by the section's alignment, not by the globals' own.

## Why it matters: the loader rejects the load

`kprog/libnativeloader/src/native_loader.cpp:2840-2852` binds a native `.rodata` symbol to
`map value address + symbol offset`, and refuses the whole object when

    section_end = max(native .rodata size, off + sym.st_size)  >  map->value_size

The BPF object's `.rodata` — which is the map's `value_size` — is **4106**:

    shipped  native .rodata 4106  == value_size 4106   -> loads
    upstream native .rodata 4118  >  value_size 4106   -> fails to load

So building tcplife from untouched source would not merely differ in layout; the tool's
native object would not install at all, and the arm would silently fall back to eBPF.

## The decision

Three ways to get tcplife same-source, and they belong to different owners:

1. **Loader: allow a larger native section by remapping symbol offsets.** The offsets of the
   native symbols need not match the BPF ones as long as each symbol's *value* is placed at
   its BPF offset within the map. That means copying each symbol's bytes to `map + bpf_off`
   instead of requiring the section to be congruent. This is lane verified's file
   (`libnativeloader`), and it changes behaviour for every app, so it needs their agreement —
   and it would also remove the same constraint for Tracee/Tetragon/OTel, all of which are
   currently forced to keep one layout.
2. **Linker: pad/repack the native `.rodata` to the BPF layout.** The linker owns the
   relocation list; it could emit a section whose symbol offsets match the BPF object's. This
   is lane verified's `native_link` and lane perf's P0 area, and it needs the BPF offsets as
   an input the linker does not currently take.
3. **Leave tcplife's attribute in place and accept one tool as not-same-source.** Cheap, but
   it contradicts the goal written at the top of todo section 0, and it is the only tool
   affected — the other seven are already same-source by layout.

I have not touched either file. Request posted in COORDINATION.

## Reproduce

```sh
T=/var/tmp/kprog-tmp/C/bcc-samesource
CF="-O3 -g -fPIC -c -DMICRO_NATIVE -fomit-frame-pointer -march=native -mno-red-zone \
    -mgeneral-regs-only -fno-stack-protector -fno-asynchronous-unwind-tables \
    -fno-unwind-tables -fno-jump-tables -fno-optimize-sibling-calls -Wno-unknown-attributes \
    -mllvm -switch-to-lookup=false"
INC="-include vendor/bpf/native_compat.h -I vendor/bpf/bcc/libbpf-tools \
     -I vendor/bpf/bcc/libbpf-tools/x86 -I vendor/bpf/bcc/src/cc/libbpf/include/uapi \
     -I/usr/include -I/usr/include/x86_64-linux-gnu"
clang-18 $CF $INC -o $T/tcplife.upstream.native.o vendor/repos/bcc/libbpf-tools/tcplife.bpf.c
readelf -sW $T/tcplife.upstream.native.o | grep target_
```