# Tracee same-source native build: byte-identical to the image

Lane C, 2026-11-14.

## Result

`vendor/bpf` builds Tracee's native objects **byte-identically** to the ones the
image ships. Every one of the 179 files (175 proof objects, 3 native objects,
1 manifest) has the same sha256 as `/opt/bpf-benchmark/native-bpf/x86_64/tracee/`
in `bpf-benchmark/kprog:current`.

The build is reproducible: a `make -B` of `tracee.native.o` after touching the
source produces the same sha256 (`fb3f51b3...`).

## The one rule that matters

Tracee's native object comes from the **Makefile rule**, which compiles
`tracee.bpf.c` straight to native with `-include native_compat.h`:

    make native-tracee

The earlier hand pipeline in `tracee-samesource-20261113/` (BPF compile, core-ir
lowering, name-helpers, lower-tracee-asm, then native codegen) produces
**different** objects and must not be used for Tracee. Its divergence:

| property | Makefile rule (= image) | hand pipeline |
| --- | --- | --- |
| `.bss` size | `0x12` (18 bytes) | `0x13` (19 bytes) |
| `.bss` globals | 4 | 5 (`alerted_find_vma_unsupported` extra) |
| relocs against the `.bss` **section** symbol | 0 | 143 |

## Why the extra global crashed the guest

`vendor/repos/tracee/pkg/ebpf/c/common/memory.h:96` guards a warn-once flag on
`bpf_core_field_exists(mm->mm_rb)`. The target BTF has no `mm_rb` in
`mm_struct`, so a build that resolves the probe against real BTF keeps the
branch live and allocates `alerted_find_vma_unsupported` in `.bss`.

`native_compat.h:326` defines `bpf_core_field_exists(field...) (1)`, so the
Makefile rule folds the probe to true, the warn-once branch is dead, and the
flag never exists. That is the image's `.bss` = 18 bytes.

The hand pipeline's flag is `internal`, so clang references it through the
`.bss` **section** symbol. `native_link` embeds section-symbol data into
`.native_link_rodata` (`kprog/x86/native_lab/native_link/src/main.rs:790`) and
the module memcpy's it inside the JIT image
(`kinsn/module/x86/bpf_x86_native_lab.c:202`). A native `movb $1, off(%rip)`
into that flag then stores into the read-only page:

    BUG: unable to handle page fault for address: ffffffffc06720c6
    #PF: supervisor write access in kernel mode
    RIP: 0010:bpf_prog_59f4a931744dcdc6_tracepoint__sch+0x101f/0x38b4
    Code: ... <c6> 05 80 28 00 00 01 ...      # movb $1, 0x2880(%rip)

Using the Makefile rule removes the flag, hence the store.

## Acceptance check (no guest needed)

    F=vendor/build/native-bpf/x86/$(cat /workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release)/native/tracee/tracee.native.o
    llvm-readelf-18 -S -W $F | grep '\.bss '          # 000012
    llvm-readelf-18 -s -W $F | grep -c alerted_find_vma  # 0
    llvm-readelf-18 -r -W $F | grep -c ' \.bss '       # 0

## Reproduce

    cd vendor/bpf
    export KERNEL_RELEASE=$(cat /workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release)
    make native-tracee
    sha256sum vendor/build/native-bpf/x86/$KERNEL_RELEASE/native/tracee/tracee.native.o
    # fb3f51b32b0013c1258595a785e1053c0ec49a32e7d2fb80afafd2d29817bb82

`corpus/results/tracee-samesource-20261114/` holds the three native objects and
the manifest, all with the image's hashes; the 175 proof objects live in
`vendor/build/native-bpf/x86/stage/tracee/` and are rebuilt by the same target.

## Still open

The guest timing number. The 2026-11-14 08:01Z run crashed in the **baseline**
arm (`RIP: 0x0` in `loop_rootcg_workfn`) while another lane held the timing lock
and ran its own guest; it is a contention artifact, not a native defect. The
Tracee C3 timing needs the timing lock and a single guest.
