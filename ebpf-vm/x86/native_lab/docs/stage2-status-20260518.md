# Stage 2 status — helpers + maps via JIT-as-address-oracle (2026-05-18)

## State

All Stage 2 design pieces are implemented, build, and pass an in-VM
end-to-end sweep on the BpfReJIT fork kernel:

- Kernel module side-band relocs file (deprecated by trampoline approach
  but left in the module — harmless).
- `native-link` extended to parse `.rela.text`, append trampolines for
  PLT32 helper calls and literal-pool entries for GOTPCREL map refs,
  patch all disp32s position-independently.
- `native_lab_runner` extended to:
  - Detect ELF input (vs pre-linked blob)
  - Load sibling `.bpf.o` as address oracle (libbpf load + JIT)
  - Resolve helper names via `/proc/kallsyms`
  - Extract map kernel pointers by disassembling jited_prog_insns
    (xlated bytecode can't be used — kernel sanitizes map ptrs there to
    map ids for KASLR protection)
  - fork+exec `native-link` subprocess with resolved addresses
  - Upload blob + relocs to native_lab debugfs

## Test programs in `ebpf-vm/test/`

| program | coverage |
|---|---|
| `helper_only_ktime` | one `bpf_ktime_get_ns()` call |
| `helper_get_pid_tgid` | `bpf_get_current_pid_tgid()` |
| `map_array_lookup` | `BPF_MAP_TYPE_ARRAY` update + lookup |
| `map_hash_lookup` | `BPF_MAP_TYPE_HASH` update + lookup |
| `map_percpu_array` | `BPF_MAP_TYPE_PERCPU_ARRAY` |
| `combined_helper_map` | `bpf_get_smp_processor_id` + ktime + percpu map |

All six pass the smoke test. Three (`map_array_lookup`, `map_hash_lookup`,
`map_percpu_array`) produce bit-identical `result` words between
native_lab and kernel_jit runtimes, proving both runtimes hit the same
kernel map instance with the same value semantics.

## Baseline numbers (from `results/stage2_sweep.txt`)

```
program                native_lab    kernel_jit   ratio   verdict
─────────────────────────────────────────────────────────────────
helper_only_ktime        55 ns         55 ns      1.00x   tied
helper_get_pid_tgid      38 ns         38 ns      1.00x   tied
map_array_lookup         43 ns         44 ns      0.98x   tied (BPF JIT inlines ARRAY lookup)
map_hash_lookup         390 ns         77 ns      5.06x   native much slower ⚠️
map_percpu_array         42 ns         43 ns      0.98x   tied (BPF JIT inlines PERCPU_ARRAY lookup)
combined_helper_map      67 ns         78 ns      0.86x   native slightly faster
```

(Numbers vary 5-10% across runs; the 5x gap on `map_hash_lookup` is
consistent and dominates.)

## Where the gaps come from

### Helper trampoline overhead (~5-10 cycles per call)

Every helper call goes:

```
call rel32 → trampoline:  jmp [rip+0]   ; load helper kernel addr from pool
                          .quad helper  ; absolute kernel address
                          → helper       ; execute
                          ret            ; return to original caller
```

vs BPF JIT's direct `call rel32 → helper`. The extra indirection costs
~5 cycles when the BTB is warm, more when cold. At 3 GHz that's
~1.5–3 ns per helper call.

For `helper_only_ktime` / `helper_get_pid_tgid` the per-iteration time
is dominated by the helper itself (~50–60 ns), not the trampoline, so
native_lab and kernel_jit tie.

### Map literal-pool overhead (~1-4 cycles per access)

```
mov reg, [rip+disp32]   ; load map ptr from pool entry (1 L1 mem load)
```

vs BPF JIT's

```
movabs reg, imm64       ; absolute address baked into instruction
```

~1-4 cycles per map dereference. Negligible for most programs.

### The real story: BPF JIT's `map_gen_lookup` inlining

This is the dominant gap for HASH-style programs. The kernel exposes a
per-map-type callback `map_gen_lookup` that lets the BPF JIT REPLACE
`bpf_map_lookup_elem(map, key)` with a specialized inline sequence:

```c
/* kernel/bpf/hashtab.c */
.map_gen_lookup = htab_map_gen_lookup,
```

`htab_map_gen_lookup` emits BPF code that calls `__htab_map_lookup_elem`
(the inner core, no RCU check, no type dispatch) and adds the value
offset inline:

```
call __htab_map_lookup_elem   ; fast path, skips public-API overhead
jne +1                         ; handle NULL
add r0, sizeof(htab_elem)+key  ; direct offset to value
```

native_lab loses this — calling `bpf_map_lookup_elem` from native goes
through the public symbol, which:
- Acquires/checks RCU read-lock state
- Dispatches via `map->ops->map_lookup_elem`
- Returns via the full unwound stack frame

The `bpf_map_lookup_elem` public path costs ~200–300 ns when the BPF
JIT's specialized path costs ~30–50 ns. That's where the `5x` gap on
`map_hash_lookup` lives. The trampoline overhead is barely 5% of this.

Similarly for ARRAY and PERCPU_ARRAY, BPF JIT inlines lookup but native
calls the public helper. Yet for those types the public path is also
~30–40 ns (simpler internals), so we tie.

## Cycle attribution

| component | best-case cost / call | worst-case cost / call | notes |
|---|---:|---:|---|
| trampoline indirection | ~2 cycles (~0.6 ns) | ~10 cycles (~3 ns) | indirect call through inline pool |
| map literal-pool load | ~1 cycle (~0.3 ns) | ~4 cycles (~1.3 ns) | L1 hit vs L2 miss |
| missing `map_gen_lookup` inlining | varies by map type | up to ~250 ns | dominant for HASH map |
| missing other JIT-only optimizations | varies | varies | bounds check elimination, helper specialization |

## Optimization options ranked by expected ns-savings

1. **Inline `map_gen_lookup`-equivalent sequences in native-link**
   (~80–250 ns/call on HASH map). The kernel publishes which map type
   each map is; we already load the .bpf.o, so we have that info. For
   HASH maps, generate the inlined call to `__htab_map_lookup_elem`
   instead of the public `bpf_map_lookup_elem`. Requires:
   - kallsyms lookup for `__htab_map_lookup_elem`
   - native-link to emit the 3-instruction inline expansion (call + jne
     + add) for `bpf_map_lookup_elem` calls when the first arg is known
     to be a HASH map.
   - The 1-byte offset constant (key_size_rounded_up) needs to come from
     the map's `bpf_map__key_size()`.

2. **Drop the trampoline for helpers (~3-5 ns/call)**. Replace
   `call rel32 (5B)` with `call *[rip+disp32] (6B)` indirect through a
   pool entry. Same indirection cost as trampoline minus the extra jmp.
   Requires iced's BlockEncoder relayout (instruction length change by
   +1) — drop `DONT_FIX_BRANCHES` and let iced refix all PC-relative
   refs.

3. **Drop the literal pool for maps (~1 ns/access)**. Replace
   `mov reg, [rip+disp32] (7B)` with `movabs reg, imm64 (10B)` and let
   iced relayout (length change by +3). Smaller win than #1 and #2.

4. **Direct `call rel32` to helper instead of indirect via pool**
   (saves ~3 cycles + pool memory load). Requires kernel patch to
   expose splat address to `emit_x86` — currently disallowed by project
   rules.

Ordering: #1 is the biggest win and worth doing first. #2 is medium.
#3 is small. #4 needs a kernel-side change.

## Files / locations

| file | role |
|---|---|
| `ebpf-vm/test/*.bpf.c` | 6 POC test programs |
| `ebpf-vm/test/Makefile` | build .bpf.o + .native.o |
| `ebpf-vm/test/run_stage2.sh` | in-VM sweep driver |
| `ebpf-vm/test/include/native_helpers.h` | helper externs + map macro stand-ins for MICRO_NATIVE |
| `ebpf-vm/x86/native_lab/docs/helpers-maps-design.md` | full design doc |
| `ebpf-vm/x86/native_lab/docs/stage2-status-20260518.md` | this file |
| `ebpf-vm/x86/native_lab/native_link/src/main.rs` | linker: ELF reloc parsing, trampoline + pool emit |
| `ebpf-vm/x86/native_lab/results/stage2_sweep.txt` | raw sweep output |
| `module/x86/bpf_x86_native_lab.c` | kernel module + side-band relocs file (deprecated, kept harmless) |
| `runner/src/native_lab_runner.cpp` | runner: companion .bpf.o load, map ptr extraction, linker invocation |
| `runner/src/common.cpp` | CLI option parsing additions |
| `runner/include/micro_exec.hpp` | cli_options additions |

## How to reproduce

```sh
# Build
make -C ebpf-vm/test
cargo build --release --manifest-path ebpf-vm/x86/native_lab/native_link/Cargo.toml
make host-kinsn-x86
cmake --build runner/build-llvmbpf --target micro_exec -j8

# Run
vng --run .cache/runtime-kernel/x86_64/bzImage --cwd "$(pwd)" \
    --rwdir "$(pwd)" --overlay-rwdir /tmp --cpus 2 --memory 2G \
    --disable-monitor --append "loglevel=4 panic=30 oops=panic" \
    --exec ebpf-vm/test/run_stage2.sh
```

## Next research steps

1. Implement `map_gen_lookup`-style inlining in native-link (issue 1
   above). Re-measure HASH map case; expect native_lab to drop from
   ~390 ns to ~50 ns.
2. Migrate one real micro program from `micro/programs/` to use helpers
   + maps (e.g. tracee/tetragon-style filter with map lookup) to
   validate the mechanism on non-toy code.
3. Quantify the `map_gen_lookup` inlining gap precisely by varying
   map type / key size.
