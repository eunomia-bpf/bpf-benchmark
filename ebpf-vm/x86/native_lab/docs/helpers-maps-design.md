# Native Lab Stage 2 — Helpers & Maps via the BPF JIT as Address Oracle

## Goal

Let `bpf_x86_native_lab` blobs call BPF helpers (`bpf_map_lookup_elem`,
`bpf_ktime_get_ns`, ...) and access BPF maps with the same datapath the
verified-and-JIT'd BPF programs use. After Stage 1 the native blob ran as
a pure-compute payload that only touched the packet via the ctx pointer.
Stage 2 lets it cooperate with the rest of the BPF ecosystem.

Two requirements drive the design:

1. **The native blob must obey the eBPF runtime ABI** when it executes
   inside the BPF JIT image — so calls to BPF helpers receive arguments
   in the registers the kernel expects, and accesses to BPF maps see the
   same `struct bpf_map *` the verifier hands every other caller.
2. **The native blob is clang-compiled from userspace**, so it cannot
   discover kernel symbol addresses on its own. We need an outside source
   to fill in helper-call targets and map pointers.

The proposed solution is the **JIT-as-address-oracle**: load a sibling
`.bpf.o` (same source compiled as BPF), let the kernel verify + JIT it
normally, then read the resolved x86 image back and harvest the helper
addresses and map pointers from it. Apply those to the userspace-compiled
`.native.so` via ELF relocations.

## What we get for free from SysV / BPF JIT convergence

The x86 BPF JIT register mapping:

| BPF reg | x86 reg     | SysV ABI role        |
|---------|-------------|----------------------|
| r0      | rax         | return               |
| r1      | rdi         | arg 1                |
| r2      | rsi         | arg 2                |
| r3      | rdx         | arg 3                |
| r4      | rcx         | arg 4                |
| r5      | r8          | arg 5                |
| r6      | rbx         | callee-saved         |
| r7      | r13         | callee-saved         |
| r8      | r14         | callee-saved         |
| r9      | r15         | callee-saved (+ tail-call counter slot in r9, see note) |
| r10     | rbp         | frame pointer        |

Critically: the registers BPF JIT uses to pass r1–r5 to a helper call are
**exactly the SysV ABI argument registers**. This is deliberate — BPF
helpers are ordinary kernel C functions, and `bpf_jit_emit_callee()` is
just a normal `call`. So clang `-target x86_64 -O2` emits exactly the
right register setup for `bpf_helper(a, b, c, d, e)` to invoke a BPF
helper — the only thing missing is the helper's kernel address.

The same alignment holds for map pointers: in BPF bytecode, an
`ld_imm64` with `src_reg = BPF_PSEUDO_MAP_FD` resolves at load time to
the kernel address of `struct bpf_map *`, and the JIT emits
`movabs reg, <kernel_map_ptr>`. A userspace-compiled native blob that
takes a `struct bpf_map *map` argument or holds a `&my_map` reference
naturally expects the same pointer.

## What's still missing

1. **Helper call targets**. `clang -target x86_64` emits an ELF
   `R_X86_64_PLT32` relocation against an external symbol like
   `bpf_map_lookup_elem`. The `.so` resolves it through the dynamic
   linker, which references userspace addresses unrelated to the kernel
   image. We need to rewrite those `call rel32` displacements to point at
   the helper's kernel address.

2. **Map pointers**. The `.bpf.c` source declares a map with a
   `SEC(".maps")` global structure. The `.native.so` build sees that
   global as a regular data symbol. Any reference to `&my_map` becomes a
   `R_X86_64_PC32` or `R_X86_64_GOTPCREL` relocation against the symbol.
   We need to rewrite those to point at the kernel's runtime
   `struct bpf_map *`.

3. **Tail-call counter (r9)**. The BPF JIT reserves r9 as a tail-call
   counter slot. If the surrounding BPF stub program ever participates in
   a tail-call chain, native code must not clobber r9. None of today's
   `ebpf-vm/test/*.bpf.c` use tail calls, so this is deferred; the fix
   when needed is to build native code with `-ffixed-r9` (clang x86
   supports this for general-purpose register reservation).

4. **Verifier safety**. BPF helpers assume their caller is verifier-
   approved code: pointers are bounds-checked, types match, etc. Native
   blobs bypass the verifier. Passing a bogus argument can crash the
   kernel. This is acceptable for the research path (and the existing
   `bpf_x86_native_lab` module already documents that it bypasses
   verifier guarantees), but is worth restating in the paper.

## Architecture

```
                            build time

      micro/test program source (e.g. helper_only_ktime.bpf.c)
              |                                |
              | clang -target bpf              | clang -target x86_64
              |                                |   -DMICRO_NATIVE
              v                                v
     helper_only_ktime.bpf.o          helper_only_ktime.native.so
       (BPF bytecode)                  (x86 ELF + relocations)


                            load time

   1. libbpf loads .bpf.o
       -> verifier accepts (real BPF program, helpers + maps OK)
       -> kernel BPF JIT emits x86 image with all addresses resolved
       -> maps created, fds returned

   2. native_lab_runner snapshots the JIT image + map fds
       BPF_OBJ_GET_INFO_BY_FD -> jited_prog_insns (x86 bytes)
       bpf_object__find_map_by_name -> bpf_map ptr

   3. address oracle
       Walk BPF bytecode + JIT bytes in parallel
         - each (BPF call HELPER_ID) corresponds to (x86 call rel32)
           -> capture (helper_id, kernel_addr) pair
         - each (BPF ld_imm64 PSEUDO_MAP_FD imm=fd_idx) corresponds to
           (x86 movabs reg, imm64)
           -> capture (map_name, kernel_map_ptr) pair

   4. native-link runs with the address table
       - parse .native.so ELF relocations
       - for each R_X86_64_PLT32 against a BPF helper name:
           rewrite disp32 to point at helper kernel addr
       - for each R_X86_64_PC32 / R_X86_64_GOTPCREL against a map symbol:
           rewrite disp32 to point at kernel bpf_map ptr
       - emit final position-independent native blob

   5. blob -> debugfs chunks -> kinsn -> JIT image splat
       Existing native_lab path takes over here.
```

## Build flow

`ebpf-vm/test/Makefile` produces, per source `<name>.bpf.c`:

```
<name>.bpf.o          # clang -target bpf, normal BPF object
<name>.native.so      # clang -target x86_64 -DMICRO_NATIVE -fPIC -shared,
                      # plus relocation records so native-link can patch
                      # helper calls and map references.
```

Required clang flags for `.native.so`:

- `-DMICRO_NATIVE` to select the userspace path of the source's macros
- `-fPIC -shared` so the linker emits dynamic relocations
- `-fomit-frame-pointer -mno-red-zone -fno-stack-protector` (existing
  micro flags carry over)
- `-fno-jump-tables -mllvm -switch-to-lookup=false` (no indirect jumps)
- `-fno-plt` — emit direct `R_X86_64_PC32` relocations rather than PLT
  trampolines, since we are not going through a userspace dynamic linker

Helper declarations live in a new `ebpf-vm/test/include/native_helpers.h`
header shared between BPF and native builds:

```c
#ifdef MICRO_NATIVE
/* Direct C-extern declarations; the .so build will emit a relocation
 * against each name. native-link rewrites those relocations to point at
 * the kernel helper. */
extern void *bpf_map_lookup_elem(void *map, const void *key);
extern long  bpf_map_update_elem(void *map, const void *key, const void *val, unsigned long flags);
extern unsigned long long bpf_ktime_get_ns(void);
extern unsigned long long bpf_get_current_pid_tgid(void);
/* ... */
#else
#include <bpf/bpf_helpers.h>
#endif
```

Map declarations stay identical between paths (modern libbpf-style):

```c
struct {
    __uint(type, BPF_MAP_TYPE_ARRAY);
    __uint(max_entries, 16);
    __type(key, __u32);
    __type(value, __u64);
} my_array_map SEC(".maps");
```

In `MICRO_NATIVE` mode, the SEC(".maps") section attribute is benign — it
just puts the struct in a named section the linker keeps. The struct
itself becomes a regular global symbol the .native.so exports; references
to `&my_array_map` become PC-relative relocations against that symbol.

## native-link extensions

Today's `native-link` (Rust, `ebpf-vm/x86/native_lab/native_link/`) only
handles `RET` rewriting and basic ELF symbol-byte extraction. Stage 2
extends it with:

1. **Symbol-name based relocation handling**. Read the ELF `.rela.text`
   (or `.rel.text`) section, walk each relocation:
   - Resolve the relocation's referenced symbol name
   - Match against (a) known BPF helper names from `native_helpers.h`,
     (b) map names registered by the runner
   - Patch the byte at the relocation offset accordingly

2. **`R_X86_64_PLT32` -> `call rel32` patch**. Compute
   `disp32 = helper_kernel_addr - (call_site_kernel_va + 5)`.
   At link time the actual `call_site_kernel_va` is unknown (the blob is
   PI; the kernel splats it into a BPF JIT image at some address). To
   handle this:
   - The blob is splatted into a known kernel address at JIT time. The
     `bpf_x86_native_lab` module's `emit_x86` callback already knows the
     final emit IP (it gets passed `image, off`).
   - **Easier approach** (recommended): native-link emits the blob with
     `disp32 = helper_addr - placeholder` and a separate side-band table
     of `(offset_in_blob, helper_kernel_addr)` pairs. The kernel module
     extends `emit_x86` to read this side-band and patch each disp32 at
     splat time using the actual emit address. This is a small (~30 LOC)
     module extension.
   - **Simpler still** (current Stage 1 ABI): native-link patches assume
     a known relative-offset structure if the helper is ALSO in the blob
     itself (call-into-blob). For real kernel helpers (out-of-blob), we
     **must** know the splat address. So the side-band approach above is
     the right one.

3. **`R_X86_64_PC32` / `R_X86_64_GOTPCRELX` -> map pointer load**. The
   compiled form for `mov rdi, &my_array_map` from clang -fPIC is
   usually `lea rdi, [rip + my_array_map@PC32]` (a single 7-byte LEA).
   The disp32 needs to be rewritten the same way as the helper call —
   `disp32 = kernel_map_ptr - (insn_kernel_va + 7)`. Same side-band
   table mechanism.

4. **Position-independence verification**. After patching, run a final
   pass to confirm no remaining unresolved relocations.

## Runtime side-band protocol

`bpf_x86_native_lab` module gets two new debugfs entries:

```
/sys/kernel/debug/bpf_x86_native_lab/blob<id>             (existing)
/sys/kernel/debug/bpf_x86_native_lab/blob<id>.relocs      (new)
```

`blob<id>.relocs` accepts a binary table:

```c
struct native_lab_reloc {
    u32 offset;       /* byte offset within blob */
    u32 reloc_type;   /* 0 = PC32_DISP_AT_OFFSET+0..3 (4 bytes) */
    u64 target;       /* absolute kernel address to point at */
};
```

The kernel module's `emit_x86` callback:

1. Splats the blob bytes via `memcpy` (as today).
2. For each registered reloc, computes
   `disp32 = target - (image_addr + offset + 4)` (where the +4 is because
   PC32 displacements are relative to the byte after the disp32 field)
   and writes the 4 bytes at `image + (off + reloc.offset)`.

This keeps the side-band data structured rather than embedding metadata
in the blob bytes. The relocs file is bound to the same blob id as the
blob file. The module already tracks blob registration; relocs is a
parallel side table.

## Runner integration

`native_lab_runner.cpp` extends its setup sequence:

1. Materialize input (as today).
2. **NEW**: Load the sibling `.bpf.o` via libbpf:
   - `bpf_object__open_file(<base>.bpf.o)`
   - `bpf_object__load(obj)` — kernel verifies + JITs
   - Walk all programs in the object, collect their `prog_fd` and via
     `BPF_OBJ_GET_INFO_BY_FD` collect the JIT bytes (`jited_prog_insns`)
   - Walk all maps in the object, collect `(name, kernel_map_ptr)`. To
     get `kernel_map_ptr` we either (a) ask libbpf via
     `bpf_map__addr()` if exposed, or (b) extract from the JIT image by
     looking for the `movabs imm64` patterns and cross-referencing
     against the bytecode's `ld_imm64` map FD references.
3. **NEW**: Walk the prog's BPF bytecode + JIT image in lockstep:
   - Each `call HELPER_ID` in bytecode is a 5-byte `e8 disp32` in JIT.
     Read disp32 -> `helper_kernel_addr = jit_addr + offset + 5 + disp32`.
   - Each `ld_imm64 (BPF_PSEUDO_MAP_FD, fd)` pair in bytecode is a
     `movabs reg, imm64` (10 bytes) in JIT. Read imm64 ->
     `kernel_map_ptr`.
   - Build `helper_id -> kernel_addr` and `map_name -> kernel_map_ptr`
     tables. Use libbpf to convert `helper_id` to symbol name (BPF helper
     proto registry).
4. Read the `.native.so` ELF + walk its `.rela.text` relocations.
5. For each relocation:
   - If symbol matches a BPF helper name from the table, build a
     side-band `(offset, target)` reloc.
   - If symbol matches a map name from the table, same.
   - Otherwise: bail — unresolved external reference is a build bug.
6. Upload blob bytes (existing path) + relocs side-band table (new).
7. Build BPF stub + run (existing path).

Most of the new logic lives in `native-link` (Rust); the runner just
threads through the address tables.

## Test program plan

Test programs live at `ebpf-vm/test/`:

| File | Coverage |
|------|----------|
| `helper_only_ktime.bpf.c` | One call to `bpf_ktime_get_ns()`. Pure smoke test — no maps, single helper. Lowest possible bar to validate the helper resolution path. |
| `helper_get_pid_tgid.bpf.c` | `bpf_get_current_pid_tgid()`. Tests a helper that reads kernel context, returning split tgid/pid. |
| `map_array_lookup.bpf.c` | `BPF_MAP_TYPE_ARRAY`, `bpf_map_lookup_elem` then read u64. The most-inlined map type in BPF JIT; native_lab will lose some perf vs BPF JIT here, which is interesting data. |
| `map_hash_lookup.bpf.c` | `BPF_MAP_TYPE_HASH`, `bpf_map_lookup_elem`. Helper call is not inlined for HASH; native_lab and BPF JIT should be equally fast. |
| `map_percpu_array.bpf.c` | `BPF_MAP_TYPE_PERCPU_ARRAY`. Tests per-CPU semantics — each CPU sees its own value. |
| `combined_helper_map.bpf.c` | Use `bpf_get_smp_processor_id()` to index a `BPF_MAP_TYPE_ARRAY`, then `bpf_ktime_get_ns()` to write a timestamp. Realistic mini program. |

All programs return a u64 result (via `data[0..8]` for XDP, via map for
map-only programs) that's deterministic given the input. Native vs BPF
JIT runs must produce the same value.

## Phased implementation

1. **Phase A — design + test sources** (this doc + `ebpf-vm/test/*.bpf.c`
   + Makefile that builds both `.bpf.o` and `.native.so`).
2. **Phase B — side-band relocs in kernel module** (~30 LOC in
   `module/x86/bpf_x86_native_lab.c`: new debugfs `.relocs` file,
   `emit_x86` applies relocs after `memcpy`).
3. **Phase C — native-link reloc extension** (~250 LOC in
   `ebpf-vm/x86/native_lab/native_link/src/main.rs`: parse ELF
   `.rela.text`, accept an address table from CLI args, emit side-band
   reloc file alongside the blob).
4. **Phase D — runner oracle wiring** (~150 LOC in
   `runner/src/native_lab_runner.cpp`: load sibling `.bpf.o`, extract
   JIT image, build helper/map address table, invoke `native-link` with
   it, upload reloc side-band).
5. **Phase E — VM verification** (run each test program through both
   `kernel_jit` and `native_lab` paths, assert result identity and
   sensible timing).

Phases B, C, D have no inter-dependency once the side-band protocol is
fixed; can be done in parallel.

## Open questions

- **Map pointer extraction without JIT inspection**. `bpf_map__addr()` is
  not in upstream libbpf. The alternative is to dump the JIT image and
  parse it. Another option: write a tiny BPF program that does
  `r0 = (u64)&my_map; exit;`, JIT it, read the imm. Decide which after
  the smoke test.
- **Map relocations after `-fno-plt`**. clang emits
  `lea rdi, [rip + sym@PC32]` for `-fPIC -fno-plt` references to globals.
  Need to confirm in practice that `.rela.text` records the relocation as
  `R_X86_64_PC32` (or `_REX_GOTPCRELX`) — affects native-link's offset
  arithmetic.
- **Inlined helpers**. Some helpers (`bpf_map_lookup_elem` on
  `ARRAY` / `PERCPU_ARRAY`) are inlined by the BPF JIT into direct
  pointer math; the JIT image contains NO call instruction for them.
  Native code will still emit a real `call`. Both paths will compute the
  same value, but native_lab will be slower than BPF JIT for those
  specific helpers. That's the interesting finding, not a bug.
- **Tail calls / bpf_tail_call**. Reserve r9 + emit the BPF JIT's
  tail-call counter slot if a program uses tail calls. Defer until a
  test program actually needs it.
- **Stub-program ctx access**. For programs that need ctx fields beyond
  data/data_end, the Stage 1 stub (`sidecar; call kinsn; exit`) is
  insufficient. We may need to add per-program prologue insns that
  pre-fetch ctx fields and stage them in caller-saved registers for the
  native body. Decide once a test program actually depends on a ctx
  field that's neither data nor data_end.
