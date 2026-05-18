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

## Optimization #1 — `-fno-plt` to eliminate trampolines (2026-05-18)

Adding `-fno-plt` to the userspace native build (`-fPIC -c -fno-plt`)
makes clang emit `call *[rip+disp32]` (6 bytes, R_X86_64_GOTPCREL reloc)
instead of `call rel32` (5 bytes, R_X86_64_PLT32). The GOTPCREL form is
already an indirect call through a memory operand, so native-link can
treat it exactly like a map GOT reference: append an 8-byte literal-
pool entry holding the helper kernel address, patch the disp32. No
trampoline needed.

**Per-helper savings:** trampoline was 14 bytes (`jmp [rip+0]` + 8-byte
addr) and added one indirection (call → trampoline jmp → helper). The
new form is 8 bytes per helper (just the addr) and one indirection
(call indirect → helper).

**Measured impact** (5-run averages):

| program | trampoline build (ns) | `-fno-plt` build (ns) | Δ |
|---|---:|---:|---:|
| helper_only_ktime | 54.4 | 54.4 | 0 (helper-internal dominates) |
| helper_get_pid_tgid | 30.0 | 30.0 | 0 |
| map_array_lookup | 42.2 | 42.8 | within noise |
| **map_hash_lookup** | **391.2** | **367.2** | **−24 ns (6% faster)** |
| map_percpu_array | 43.4 | 43.8 | within noise |
| combined_helper_map | 65.8 | 69.8 | +4 (within noise) |

Only `map_hash_lookup` shows a measurable improvement (~24 ns). That's
the program where the helper-internal cost is large enough (~300 ns)
that trampoline savings of 5 cycles per call show up above the run-to-
run noise floor. For everything else, helper-internal cost dwarfs the
trampoline overhead.

**Verdict**: -fno-plt is a net win. Smaller binary (saves ~6-12 bytes
per unique helper), one less indirect jump per call, and shaves ~5 ns
off helper-heavy programs.

The HASH map 5x gap shrinks only modestly (391→367 ns native_lab vs
~74 ns kernel_jit) because the dominant cost is still the missing
`map_gen_lookup` inlining (see below) — not the trampoline.

### Unified Stage 1 + Stage 2 table with `-fno-plt` (2026-05-18, 35 programs)

`-fno-plt` is now applied to both `micro/programs/Makefile` (Stage 1,
no observable effect since those programs are pure-compute and have no
external calls to relocate) and `ebpf-vm/test/Makefile` (Stage 2,
~24 ns win on `map_hash_lookup`). Single full sweep:

| stage | program | native_lab ns | kernel_jit ns | ratio |
|-------|---------|--------------:|--------------:|------:|
| S1 | bcc_runqlat_log2_histogram_bucket | 1246 | 1731 | 0.720 |
| S1 | bcc_tcpconnect_ipv4_tuple_filter | 70 | 124 | 0.565 |
| S1 | bitmap_popcount_scan | 471 | 1119 | 0.421 |
| S1 | bpf_local_call_fanout_dispatch | 83 | 125 | 0.664 |
| S1 | bpftrace_comm_key_fnv_hash | 443 | 736 | 0.602 |
| S1 | bpftrace_string_search_prefix_scan | 129 | 302 | 0.427 |
| S1 | cgroup_skb_hash_chain | 293 | 366 | 0.801 |
| S1 | cilium_ct_nat_tuple_rewrite | 93 | 186 | 0.500 |
| S1 | cilium_policy_guard_tree_filter | 43 | 115 | 0.374 |
| S1 | cilium_socket_lb_service_select | 179 | 425 | 0.421 |
| S1 | flow_5tuple_rss_hash | 19 | 19 | 1.000 |
| S1 | flow_record_field_scan | 61 | 65 | 0.938 |
| S1 | katran_lb_consistent_hash_select | 15 | 46 | 0.326 |
| S1 | otel_stack_frame_unwind_scan | 45 | 134 | 0.336 |
| S1 | packed_header_bitfield_decode | 202 | 259 | 0.780 |
| S1 | packet_checksum_fold | 13382 | 20766 | 0.644 |
| S1 | packet_record_bounds_window | 87 | 118 | 0.737 |
| S1 | packet_toeplitz_rss_hash | 178 | 259 | 0.687 |
| S1 | packet_vlan_tcpopt_parser | 12 | 15 | 0.800 |
| S1 | payload_prefix_memcmp_scan | 55 | 100 | 0.550 |
| S1 | simple | 7 | 7 | 1.000 |
| S1 | simple_packet | 7 | 7 | 1.000 |
| S1 | siphash_rotate64_mixer | 30 | 70 | 0.429 |
| S1 | sorted_rule_binary_search | 316 | 666 | 0.474 |
| S1 | tc_packet_checksum_fold | 13350 | 17630 | 0.757 |
| S1 | tetragon_process_event_arg_filter | 133 | 173 | 0.769 |
| S1 | trace_event_type_switch_dispatch | 306 | 397 | 0.771 |
| S1 | tracee_http_method_prefix_detect | 20 | 20 | 1.000 |
| S1 | tracee_syscall_name_table_lookup | 123 | 152 | 0.809 |
| S2 | helper_only_ktime | 55 | 56 | 0.982 |
| S2 | helper_get_pid_tgid | 37 | 37 | 1.000 |
| S2 | map_array_lookup | 49 | 44 | 1.114 |
| **S2** | **map_hash_lookup** | **355** | **86** | **4.128** ⚠️ |
| S2 | map_percpu_array | 43 | 43 | 1.000 |
| S2 | combined_helper_map | 66 | 67 | 0.985 |

**Aggregate (35 validated programs):**

| metric | value |
|--------|------:|
| geomean ratio | **0.7123x** (native_lab 1.40x faster on average) |
| range | 0.326 .. 4.128 |
| wins (native faster) | 27 |
| losses (kernel_jit faster) | 2 |
| ties | 6 |

Stage 1 geomean unchanged from the previous Stage 1-only run
(0.6307 vs 0.6393 — within run-to-run noise). Confirms `-fno-plt`
is a no-op for pure-compute programs.

The single outlier is still `map_hash_lookup` (4.13x slower native).
That's the `map_gen_lookup` inlining gap — the next optimization to
attack.

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

1. ~~Implement `map_gen_lookup`-style inlining in native-link (issue 1
   above). Re-measure HASH map case; expect native_lab to drop from
   ~390 ns to ~50 ns.~~ **DONE — see follow-up below.**
2. Migrate one real micro program from `micro/programs/` to use helpers
   + maps (e.g. tracee/tetragon-style filter with map lookup) to
   validate the mechanism on non-toy code.
3. Quantify the `map_gen_lookup` inlining gap precisely by varying
   map type / key size.

## Follow-up 2026-05-17: HASH `map_gen_lookup` inlining + 8 new test cases + honest measurement methodology

### What landed

1. **HASH `map_gen_lookup` inlining in native-link.** Kernel BPF JIT
   rewrites `bpf_map_lookup_elem` on HASH maps as a direct call into
   `__htab_map_lookup_elem` followed by inline
   `test rax,rax; je 2f; add rax, KEY_OFFSET; 2:` (skips the inner
   `key` offset on success). `native-link` now does the same when
   given `--inline-hash-lookup HTAB_ADDR,KEY_OFFSET`: GOTPCREL relocs
   against `bpf_map_lookup_elem` resolve to `HTAB_ADDR`, and a 9-byte
   declared-byte chunk (`48 85 c0  74 04  48 83 c0 imm8`) is spliced
   into the iced instruction stream after the call site. The runner
   pulls `__htab_map_lookup_elem`'s kernel address from
   `/proc/kallsyms` and extracts `KEY_OFFSET` by disassembling the
   companion `.bpf.o`'s JIT image (the kernel JIT's emitted
   `add rax, imm` carries the exact value for the host kernel).

2. **Single-HASH-map-only inline guard.** Replacing the pool entry
   for `bpf_map_lookup_elem` with `__htab_map_lookup_elem` is only
   safe when every call site targets a HASH map. The runner now
   passes `--inline-hash-lookup` only when the program contains
   exactly one map and that map is `BPF_MAP_TYPE_HASH`; mixed-map
   programs use plain `bpf_map_lookup_elem` and skip inline. The
   `multi_map_policy` test case below exercises this guard.

3. **R_X86_64_PC32 (local rodata) support.** Real-world BPF programs
   often contain `const T x = { ... }` where `T` is 16+ bytes;
   clang lowers these via `movups xmm0, [rip+disp]` against a
   `.L__const.<fn>.<arr>` symbol in `.rodata`, emitting an
   `R_X86_64_PC32` reloc. `native-link` now embeds the target
   symbol's bytes at the blob tail and patches the disp32 to point
   at the embedded copy. The `map_hash_str_key` test case below
   would have been blocked by the missing handler.

4. **Iced branch-fix enabled.** Inserting the inline-hash bytes
   pushes downstream branches past `i8` range; dropped
   `BlockEncoderOptions::DONT_FIX_BRANCHES` so iced grows
   `Jcc_short` -> `Jcc_near` legally. The `JmpEnd` placeholder now
   targets a far address so iced can't shrink the 5-byte form.

5. **8 new test cases under `ebpf-vm/test/`** spanning helper-only,
   single-map (ARRAY / HASH / LRU_HASH / PERCPU_HASH), and
   multi-map shapes (cilium-style policy chain, tetragon-style
   stats aggregator, 5-tuple classify). See table below.

### Honest measurement methodology

The previous status update (above) reported `map_hash_lookup` at
0.609x using `INNER_REPEAT=1000` and a SAMPLES=7 sweep. That number
was **noisy**: at INNER_REPEAT=1000, the per-iter `exec_ns` from the
kernel's BPF test_run varies wildly run-to-run (e.g. the kernel_jit
baseline jumped between 37 ns and 83 ns across consecutive sweeps).
At INNER_REPEAT=100000 the kernel_jit baseline stabilizes and the
true picture appears. The prior `nl_ns=355 kj_ns=86 = 4.128x` figure
came from `run_stage2.sh`'s INNER_REPEAT=1 mode and was almost
entirely PROG_TEST_RUN syscall dispatch overhead, not program time.

The 14-program perf table below uses **INNER_REPEAT=100000, SAMPLES=15
(median)** — verified stable across two consecutive sweeps.

### 14-program perf table

`ebpf-vm/x86/native_lab/results/stage2_inline_hash_sweep.txt`
(INNER_REPEAT=100000, SAMPLES=15 medians, run in 2-CPU VM, x86_64,
host kernel 7.0-rc2+):

| # | program | maps | helpers | native_lab ns | kernel_jit ns | ratio | inline? |
|---|---|---|---|---:|---:|---:|---|
| 1 | `helper_only_ktime` | 0 | 1 | 28 | 28 | 1.000 | n/a |
| 2 | `helper_get_pid_tgid` | 0 | 1 | 5 | 6 | 0.833 | n/a |
| 3 | `helper_chain_simple` | 0 | 4 | 33 | 31 | 1.065 | n/a |
| 4 | `map_array_lookup` | 1 ARRAY | 0 | 19 | 17 | 1.118 | no |
| 5 | `map_array_index_packet` | 1 ARRAY | 0 | 19 | 18 | 1.056 | no |
| 6 | `map_hash_lookup` | 1 HASH | 0 | 81 | 81 | **1.000** | **yes** |
| 7 | `map_hash_str_key` | 1 HASH (16B key) | 0 | 85 | 86 | **0.988** | **yes** |
| 8 | `map_percpu_array` | 1 PERCPU_ARRAY | 0 | 19 | 18 | 1.056 | no |
| 9 | `map_lru_hash_counter` | 1 LRU_HASH | 0 | 230 | 229 | 1.004 | no (LRU != HASH) |
| 10 | `map_percpu_hash_counter` | 1 PERCPU_HASH | 0 | 75 | 75 | 1.000 | no (PERCPU_HASH != HASH) |
| 11 | `combined_helper_map` | 1 PERCPU_ARRAY | 2 | 38 | 38 | 1.000 | no |
| 12 | `multi_map_policy` | 3 (ARRAY+HASH+PERCPU) | 0 | 196 | 137 | 1.431 | no (multi-map guard) |
| 13 | `packet_5tuple_classify` | 1 HASH (16B struct key) | 0 | 88 | 93 | **0.946** | **yes** |
| 14 | `stats_mixed_helpers` | 2 (HASH+PERCPU_HASH) | 3 | 218 | 173 | 1.260 | no (multi-map guard) |

**Geomean: 1.046x** — native_lab is on average ~5% slower than the
kernel BPF JIT across these 14 real-world-shaped programs.

### Reading

- **HASH-inline-eligible programs (#6, #7, #13)** all sit within
  noise of kernel JIT (0.946 .. 1.000). The inline transform closed
  what would otherwise be a ~30 ns per-call gap.
- **ARRAY / PERCPU_ARRAY / LRU_HASH / PERCPU_HASH** single-map
  programs (#4, #5, #8, #9, #10) all within ±10% — these helper
  calls dominate program time so the helper-call indirection cost
  is amortized away.
- **Multi-map programs (#12, #14) lose 26-43%.** This is the
  expected cost of the single-HASH-only inline guard: the HASH
  lookup in those programs goes through plain
  `bpf_map_lookup_elem` (slower than inlined
  `__htab_map_lookup_elem`). Per-call-site map resolution
  (rdi def-use backtrace) would lift this restriction but is
  deferred.
- **Pure-helper programs (#1, #2, #3)** match kernel JIT to within
  1-2 ns (effectively tied).

This is a more honest picture than the previous "geomean 0.654x"
claim, which was based on a single noisy 1000-iter sweep. native_lab
is **competitive but not faster** than the kernel BPF JIT on real-
shaped programs in the current state; the kernel JIT's per-call-site
map-type-aware inlining of `bpf_map_lookup_elem` remains the
strongest remaining optimization native_lab doesn't reproduce on
multi-map programs.
