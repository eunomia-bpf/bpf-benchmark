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

## CO-RE resolved (lane perf's core-ir-resolve)

Running lane perf's `core-ir-resolve` on the frontend IR, before the idiom fold, resolves the
CO-RE queries against the sole kernel's BTF:

```
/var/tmp/kprog-tmp/perf/core-ir/core-ir-lower tracee.bc --local-bpf tracee.bpf.o \
  --target-btf /workspaces/.agent-state/kprog-ck/build-x86/vmlinux \
  --report tracee.core.json -o tracee.resolved.bc
```

370 CO-RE globals resolved, **201 of them to a different offset** (e.g. `llvm.task_struct:0:0`
0 -> 16), 0 pending scalar resize, 0 unresolved. After the fold and codegen the linked proofs
carry **zero** `llvm.*` relocations, against 135 before. The resolved offsets are visible in the
generated code as the shipped object's `add $0x10` shifts.

(The Makefile's `core-ir-resolve` target wraps the tool in `prlimit`, which fails with
"Permission denied" on this mount even though the binary is +x; calling the binary directly
works.)

## What remains: the helper call shape

The linked proof still differs from the shipped object in how helpers are called. The linker
inlines a helper as `mov $imm; call *reg` **only when the immediate is adjacent to the call**
(`x86_immediate_helper_load_before_call`, `x86.rs:928-945`). The shipped objects have that
form, and therefore **0 helper relocations**. This IR lets clang hoist the id (`mov $0x1,%ebx`
reused across a call that clobbers `rbx`), so the linker emits a name-bound
`HELPER_CALL_REL32` patch slot instead: 166 relocations where the shipped object has 25.

That form is valid — the loader patches an `e8 rel32` slot
(`NATIVE_LAB_RELOC_HELPER_CALL_REL32`) — but it is a different linked shape and costs one
relocation per helper call. Closing it needs either a linker that tracks the id through a
clobber, or IR that keeps the id adjacent per call site.

## Superseded: CO-RE placeholders

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

## Rebuilt 2026-11-14 (artifacts were in /var/tmp, wiped by a reboot)

172/172 programs build and link again from untouched upstream source. Three blockers
were found and fixed, all on this side of the linker boundary:

1. **`-fno-jump-tables` did not survive the saved IR.** `sys_enter_submit` linked in
   kernel mode failed with `instruction at IP 0x129b is an indirect branch; rebuild with
   -fno-jump-tables`. The flag is not a function attribute, so `clang -O3` over the
   lowered `.ll` regenerated the jump table (`movslq (%rcx,%rax,4); addq %rcx; jmpq *%rdx`).
   Fixed by writing the string attribute `"no-jump-tables"="true"` into every function
   attribute group. Indirect jumps: 0.
2. **Helper names came from the uapi, the linker binds from its own table.** Id 4 is
   `probe_read` in uapi and `bpf_probe_read_compat` in the kernel and in
   `native_link/src/x86.rs`. Naming from uapi produced `@bpf_probe_read`, which has no
   helper address: `x86 helper call bpf_probe_read has no helper address`. `name-helpers.py`
   now reads the linker's table (2,071 call sites affected).
3. The 45 s workload / image tar were simply missing after the reboot; re-exported
   (`docker save`), module present.

## Pipeline (current)

```sh
T=/var/tmp/kprog-tmp/C/tracee-samesource
SRC=vendor/repos/tracee/pkg/ebpf/c
clang-18 -target bpf -O2 -g -mcpu=v2 -emit-llvm -c -D__TARGET_ARCH_x86 -D__BPF_TRACING__ \
  -DCORE -DCOMMON_BUILD -I $SRC $SRC/tracee.bpf.c -o $T/tracee.bc
clang-18 -target bpf -O2 -g -mcpu=v2 -c <same flags> $SRC/tracee.bpf.c -o $T/tracee.bpf.o
/var/tmp/kprog-tmp/perf/core-ir/core-ir-lower $T/tracee.bc --local-bpf $T/tracee.bpf.o \
  --target-btf /workspaces/.agent-state/kprog-ck/build-x86/vmlinux \
  --report $T/tracee.core.json -o $T/tracee.resolved.bc        # resolved CO-RE globals=370
llvm-dis-18 $T/tracee.resolved.bc -o $T/tracee.resolved.ll
python3 kprog/results/tracee-samesource-20261113/name-helpers.py     $T/tracee.resolved.ll  $T/tracee.named.ll
python3 kprog/results/tracee-samesource-20261113/lower-tracee-asm.py $T/tracee.named.ll     $T/tracee.namedfinal.ll
sed -E 's/"target-features"="[^"]*"//; s/"target-cpu"="[^"]*"//' $T/tracee.namedfinal.ll > $T/tracee.notf.ll
sed -E 's/^(@[^ ]+ = )dso_local (global .*section "\.maps")/\1\2/' $T/tracee.notf.ll > $T/tracee.nodso.ll
# then the no-jump-tables string attribute on every function attribute group
clang-18 -target x86_64-linux-gnu -O3 -g -fPIC -fno-optimize-sibling-calls -fomit-frame-pointer \
  -mno-red-zone -mgeneral-regs-only -fno-stack-protector -fno-jump-tables \
  -c $T/tracee.nodso.ll -o $T/tracee.native.o
```

Manifest `corpus/results/tracee-samesource-20261114/manifest.json` is the image's file
verbatim (113 entries: 111 `tracee.native.o`, 1 `kprobe_check`, 1 `lsm_check`), with
174 proof objects generated from my objects.

## Guest state

169/169 programs replace with 0 load failures in the post arm — the previous
`failed to load BPF object: invalid argument` is gone. The guest then exits before the
arm reports, so there is no Tracee timing number yet.
