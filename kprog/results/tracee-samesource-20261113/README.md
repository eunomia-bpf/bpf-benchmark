# Tracee from untouched upstream source

All 172 of Tracee's programs now build and link from the unmodified `vendor/repos/tracee`
tree. One thing still stands between that and a runnable object: CO-RE placeholders.

## Pipeline

```sh
T=/var/tmp/kprog-tmp/C/tracee-samesource
SRC=vendor/repos/tracee/pkg/ebpf/c

# 1. the eBPF arm's own frontend, on untouched source
clang-18 -target bpf -O2 -g -mcpu=v2 -emit-llvm -c \
  -D__TARGET_ARCH_x86 -D__BPF_TRACING__ -DCORE -DCOMMON_BUILD -I $SRC \
  $SRC/tracee.bpf.c -o $T/tracee.bc
llvm-dis-18 $T/tracee.bc -o $T/tracee.ll
sed -E 's/"target-features"="[^"]*"//; s/"target-cpu"="[^"]*"//' $T/tracee.ll > $T/tracee.notf.ll

# 2. name the helpers, fold the four asm/intrinsic idioms
python3 name-helpers.py      $T/tracee.notf.ll    $T/tracee.named.ll
python3 lower-tracee-asm.py  $T/tracee.named.ll   $T/tracee.namedfinal.ll
#    3. clear dso_local on the .maps globals (see below)
sed -E 's/^(@[^ ]+ = )dso_local (global .*section "\.maps")/\1\2/' $T/tracee.namedfinal.ll > $T/tracee.nodso.ll

# 4. x86 codegen, then link
clang-18 -target x86_64-linux-gnu -O3 -g -fPIC -fno-optimize-sibling-calls \
  -fomit-frame-pointer -mno-red-zone -mgeneral-regs-only -fno-stack-protector \
  -fno-jump-tables -c $T/tracee.nodso.ll -o $T/tracee.nodso.native.o
for s in $(llvm-nm-18 --defined-only $T/tracee.nodso.native.o | awk '$2 ~ /^[Tt]$/ {print $3}'); do
  kprog/x86/native_lab/native_link/target/release/native-link \
    --input $T/tracee.nodso.native.o --symbol "$s" --output /tmp/p.o --mode proof
done
```

Result: 7,165,864-byte object, 172 defined text symbols, **0 SSE instructions**, and **172 of
172 programs link**, 0 failures. Lowering is 2.4 s, codegen 20 s, all 172 links 3 s.

## The four idioms, measured

The tree's three differing files (`common/buffer.h`, `common/common.h`,
`common/filesystem.h`) differ only by `MICRO_NATIVE` guards around these. Note
`vendor/bpf/tracee/pkg/ebpf/c/vmlinux.h` is **identical to upstream** — the trimmed
`task_struct` layout is a CO-RE question, not a tree modification.

| idiom | count | IR equivalent |
|---|---:|---|
| `llvm.bpf.passthrough(CODE, V)` | 36,574 | V itself |
| `asm sideeffect "", "~{memory}"()` | 810 | nothing (drop) |
| `asm "if $0 < $1 goto +1; $0 = $1"` (`r,i`) | 876 | `llvm.smin`, applied to later uses |
| `asm "if $0 <= $1 goto +1; $0 = $1"` (`=r,r,0`) | 268 | `llvm.smin` of its two inputs |

Two rules that are easy to get wrong, both learned the hard way here:

* **The fold must be function-scoped.** SSA names repeat across Tracee's 173 functions. A
  whole-file alias map produced a genuine type error where `%4` was an `i64` sext in one
  function and a `ptr` passthrough in another; a `pending` clamp list that crossed a
  `define`/`}` boundary produced a forward reference.
* **A renamed definition breaks `!DIAssignID`.** Rewriting an `alloca`'s name leaves the
  metadata pointing at the old one, so renaming is restricted to non-alloca lines.

## Two gaps that needed no linker change

Both looked like `native_link` bugs and were fixed from this side of the boundary:

1. **`x86 unresolved register-indirect call`.** The IR carries helpers as
   `inttoptr (i64 N to ptr)(...)`. The linker resolves helpers by *name*, and clang may hoist
   the constant into a register far from the call. `name-helpers.py` turns them into
   declarations of 27 named helpers (37,948 call sites), which the linker binds.
2. **`PC32 proof section-symbol target .maps is not rodata/bss`.** `.maps` globals were
   `dso_local`, so clang emitted a PC32 reference to the section symbol — the *address* of a
   copy — instead of a `GOTPCRELX` load whose slot the loader fills. Clearing `dso_local` on
   the 87 map globals gives the shipped object's form. This is the same fix `-fPIC` gives a C
   frontend (Katran's case); Tracee's frontend is the BPF target, which has no such flag.

## What remains: CO-RE placeholders

The linked proofs still carry **135 relocations against `llvm.<struct>:<idx>:<off>` externals**
(e.g. `llvm.task_struct:0:48$0:8`, `llvm.pid:0:0$0:0`) with `!llvm.preserve.access.index`
metadata. The shipped object has **0** and 25 relocations in total, against this object's 306.

The BPF frontend emits CO-RE as extern globals that libbpf resolves against the target BTF at
load time. A native object must have them resolved to the sole kernel's real offsets *before*
codegen, or the relocation survives into the blob and reads the wrong address — which is
exactly the defect C1 measured (13.5% of guest CPU inside the kernel's probe-read failure
path, because reads from the wrong offset failed and the helper zeroed the destination).

This is lane perf's P1h: at 2026-11-13T09:36 they announced an optional LLVM pass using the
BPF ELF's local BTF and the vendored libbpf resolver against the sole target BTF, offered for
reuse. That is the right tool; a second CO-RE resolver written here would be duplicate work.
