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

Reproduce via `make micro SUITE=micro/config/micro_stage2.yaml RUNTIMES="native_lab kernel" SAMPLES=3 INNER_REPEAT=10000 WARMUPS=2`.

| program | coverage |
|---|---|
| `helper_only_uid_gid` | one `bpf_get_current_uid_gid()` call (deterministic baseline) |
| `helper_chain_simple` | uid_gid + map_update + map_lookup + map_delete on 1-slot HASH |
| `map_array_lookup` | `BPF_MAP_TYPE_ARRAY` update + lookup |
| `map_array_index_packet` | ARRAY indexed by a packet byte |
| `map_hash_lookup` | `BPF_MAP_TYPE_HASH` update + lookup |
| `map_hash_str_key` | HASH with a 16-byte string-shaped key |
| `map_percpu_array` | `BPF_MAP_TYPE_PERCPU_ARRAY` |
| `map_lru_hash_counter` | `BPF_MAP_TYPE_LRU_HASH` per-key counter |
| `map_percpu_hash_counter` | `BPF_MAP_TYPE_PERCPU_HASH` per-key counter |
| `combined_helper_map` | smp_processor_id + uid_gid → PERCPU_ARRAY |
| `multi_map_policy` | ARRAY + HASH + PERCPU_ARRAY chain (cilium-style policy) |
| `packet_5tuple_classify` | HASH keyed by a 5-tuple struct parsed from packet |
| `stats_mixed_helpers` | HASH + PERCPU_HASH + 3 helpers (tetragon-style aggregator) |

All 13 produce bit-identical `result` words between native_lab and
kernel runtimes. The yaml suite deliberately excludes
`helper_only_ktime.bpf.c` and `helper_get_pid_tgid.bpf.c` (the .bpf.c
files still build) because `bpf_ktime_get_ns` and
`bpf_get_current_pid_tgid` return values that differ between the two
TEST_RUN invocations and therefore cannot be verified by exact-equality
comparison — keeping them out of the default suite is what lets the
suite double as a correctness check, not just a perf sweep.

## Baseline numbers — `make micro` 2026-05-18, SAMPLES=3 INNER_REPEAT=10000 WARMUPS=2

```
program                    native_lab    kernel    ratio (NL/K, <1 = NL faster)
                            min / med    min / med    min   med
─────────────────────────────────────────────────────────────────
helper_only_uid_gid           7 /  8 ns   9 /  9 ns   0.78  0.89
helper_chain_simple          72 / 74 ns  71 / 73 ns   1.01  1.01
map_array_lookup             15 / 16 ns  17 / 17 ns   0.88  0.94
map_array_index_packet       16 / 18 ns  17 / 17 ns   0.94  1.06
map_hash_lookup              31 / 32 ns  31 / 35 ns   1.00  0.91
map_hash_str_key             32 / 33 ns  35 / 36 ns   0.91  0.92
map_percpu_array             15 / 16 ns  17 / 17 ns   0.88  0.94
map_lru_hash_counter         86 / 86 ns  85 / 86 ns   1.01  1.00
map_percpu_hash_counter      27 / 28 ns  30 / 30 ns   0.90  0.93
combined_helper_map          17 / 17 ns  19 / 19 ns   0.89  0.89
multi_map_policy             46 / 49 ns  45 / 47 ns   1.02  1.04
packet_5tuple_classify       39 / 39 ns  41 / 41 ns   0.95  0.95
stats_mixed_helpers          64 / 67 ns  60 / 62 ns   1.07  1.08
─────────────────────────────────────────────────────────────────
geomean over 13 programs                              0.940 0.966
```

native_lab is comparable to (slightly faster than) kernel JIT on this
suite. The earlier 5x gap on `map_hash_lookup` is gone — per-call-site
inline routing (see commit `c43a7e43`) now lets HASH lookups use the
same in-kernel `__htab_map_lookup_elem` fast path the kernel JIT does
via its `map_gen_lookup` callback. Compile cost is 110–115 ms for
native_lab (clang -O2 + `native-link` relocation pipeline) vs 0.3–0.4
ms for the kernel JIT.

Environment caveats (visible as `[WARN]` lines in the run): KVM with
unknown CPU governor, turbo enabled, no CPU affinity. Numbers are
single-digit ns at the lower end and dominated by KVM scheduling
jitter rather than codegen quality.

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

### Per-call-site routing (2026-05-17 follow-up to the follow-up)

The single-HASH-only guard in (2) above was a band-aid: it forced
multi-map programs through plain `bpf_map_lookup_elem` for *every*
call site because every site shared one literal-pool entry. Now
removed.

**Mechanism** (~150 LOC across runner + native-link):
- Runner walks the entry program's BPF *source* bytecode, tracking
  which pseudo-map-fd is bound to r1 across `BPF_LD_IMM64` +
  `BPF_ALU64|MOV|X` chains. For each `BPF_CALL bpf_map_lookup_elem`,
  records the map fd in r1 (or -1 if the binding is ambiguous —
  matching the kernel verifier's "couldn't statically determine the
  map" condition, in which case kernel JIT also keeps a plain call).
- Runner extracts `offsetof(struct htab_elem, key)` once from the
  companion JIT image (any HASH lookup's post-call `add rax, imm`
  minus `roundup(that_map.key_size, 8)`).
- Per BPF-source call: HASH map → spec is
  `(__htab_map_lookup_elem, key_base + roundup(key_size, 8))`; any
  other map type (or unresolved) → spec is
  `(bpf_map_lookup_elem, 0)`.
- Runner passes the list to native-link as repeatable
  `--lookup-site INDEX=HEXADDR,OFFSET`.
- native-link in its decode loop maintains an ordinal counter for
  `bpf_map_lookup_elem` call sites (matching BPF-source order
  since clang preserves call order at -O2), allocates one
  *dedicated* literal-pool entry per call site holding the
  per-site target address, and emits the 9-byte
  `test rax,rax; je; add rax, OFFSET` chunk after the call when
  `OFFSET > 0`.

The "single-HASH-only" runner guard is gone. Multi-map programs now
get HASH inline on their HASH calls and plain helper on
ARRAY/PERCPU/LRU calls — exactly what kernel JIT does.

### 14-program perf table (with per-call-site routing)

`ebpf-vm/x86/native_lab/results/stage2_per_call_routing_sweep.txt`
(INNER_REPEAT=100000, SAMPLES=15 medians):

| # | program | maps | helpers | native_lab ns | kernel_jit ns | ratio | inline? | Δ vs guard |
|---|---|---|---|---:|---:|---:|---|---:|
| 1 | `helper_only_ktime` | 0 | 1 | 28 | 28 | 1.000 | n/a | — |
| 2 | `helper_get_pid_tgid` | 0 | 1 | 5 | 6 | 0.833 | n/a | — |
| 3 | `helper_chain_simple` | 0 | 4 | 33 | 31 | 1.065 | n/a | — |
| 4 | `map_array_lookup` | 1 ARRAY | 0 | 15 | 17 | **0.882** | no | -0.236 |
| 5 | `map_array_index_packet` | 1 ARRAY | 0 | 15 | 17 | **0.882** | no | -0.174 |
| 6 | `map_hash_lookup` | 1 HASH | 0 | 81 | 81 | 1.000 | yes | — |
| 7 | `map_hash_str_key` | 1 HASH (16B key) | 0 | 85 | 86 | 0.988 | yes | — |
| 8 | `map_percpu_array` | 1 PERCPU_ARRAY | 0 | 19 | 18 | 1.056 | no | — |
| 9 | `map_lru_hash_counter` | 1 LRU_HASH | 0 | 86 | 85 | 1.012 | no (LRU≠HASH) | — |
| 10 | `map_percpu_hash_counter` | 1 PERCPU_HASH | 0 | 27 | 28 | **0.964** | no | -0.036 |
| 11 | `combined_helper_map` | 1 PERCPU_ARRAY | 2 | 40 | 42 | **0.952** | no | -0.048 |
| 12 | **`multi_map_policy`** | 3 (ARRAY+HASH+PERCPU) | 0 | **56** | **55** | **1.018** | per-call | **-0.413** |
| 13 | `packet_5tuple_classify` | 1 HASH (16B struct key) | 0 | 47 | 49 | 0.959 | yes | — |
| 14 | **`stats_mixed_helpers`** | 2 (HASH+PERCPU_HASH) | 3 | 95 | 83 | **1.145** | per-call (HASH only) | **-0.115** |

**Stage 2 geomean: 0.979x** (was 1.046x under the single-HASH-only
guard). native_lab is now slightly *faster* than kernel JIT on this
14-program set.

### Reading

- **`multi_map_policy` 1.431 → 1.018**: the big win. The HASH lookup
  in this 3-map chain now inlines (its dedicated pool entry routes
  to `__htab_map_lookup_elem`), while the ARRAY and PERCPU_ARRAY
  lookups stay on plain `bpf_map_lookup_elem`. Correctness check
  still verifies bit-identical results vs kernel JIT.
- **`stats_mixed_helpers` 1.260 → 1.145**: improved but not closed.
  This program has HASH + PERCPU_HASH; the HASH lookup inlines, the
  PERCPU_HASH lookup doesn't (kernel JIT inlines PERCPU_HASH via
  `htab_lru_percpu_map_gen_lookup` on 5.7+; we don't yet replicate
  that). Closing this gap is a one-pass extension to the runner's
  spec computation: add a PERCPU_HASH branch that resolves
  `__htab_lru_percpu_map_lookup_elem` (or appropriate kernel func)
  and emits a similar inline expansion.
- **`map_array_lookup` 1.118 → 0.882**, **`map_array_index_packet`
  1.056 → 0.882**: the per-call routing's dedicated pool entries
  per call site (vs the previously-shared single entry) seem to
  shave a few ns per call. Some of this may be measurement noise
  (the runs across both routing variants share the same VM cold-
  start phases).
- **Pure-helper and HASH-only programs (#1-3, #6-7, #13)**:
  unchanged — they never relied on the guard.

The remaining gap is PERCPU_HASH inlining (~12 ns per lookup in
`stats_mixed_helpers`). Everything else is within noise of kernel
JIT.

### Unified 43-program table (Stage 1 + Stage 2)

Stage 1 = pure-compute micro suite from `micro/programs/` (29 progs,
`run_all_micro.sh`, INNER_REPEAT=100000, SAMPLES=5 medians).
Stage 2 = the 14 maps/helpers test programs from `ebpf-vm/test/`
(`run_stage2_sweep.sh`, INNER_REPEAT=100000, SAMPLES=15 medians).

Result files:
- `ebpf-vm/x86/native_lab/results/stage1_sweep_100k_s5_v2.jsonl`
- `ebpf-vm/x86/native_lab/results/stage2_per_call_routing_sweep.txt`

Sorted by ratio ascending (best native_lab wins first):

|   # | stage | program | native_lab ns | kernel_jit ns | ratio |
|---:|:---:|---|---:|---:|---:|
| 1 | S1 | `otel_stack_frame_unwind_scan` | 43 | 155 | 0.277 |
| 2 | S1 | `cilium_socket_lb_service_select` | 174 | 427 | 0.407 |
| 3 | S1 | `bitmap_popcount_scan` | 467 | 1113 | 0.420 |
| 4 | S1 | `cilium_ct_nat_tuple_rewrite` | 79 | 188 | 0.420 |
| 5 | S1 | `bpftrace_string_search_prefix_scan` | 115 | 247 | 0.466 |
| 6 | S1 | `bcc_tcpconnect_ipv4_tuple_filter` | 66 | 134 | 0.493 |
| 7 | S1 | `flow_5tuple_rss_hash` | 10 | 20 | 0.500 |
| 8 | S1 | `tetragon_process_event_arg_filter` | 111 | 204 | 0.544 |
| 9 | S1 | `payload_prefix_memcmp_scan` | 59 | 106 | 0.557 |
| 10 | S1 | `sorted_rule_binary_search` | 310 | 536 | 0.578 |
| 11 | S1 | `packet_record_bounds_window` | 84 | 144 | 0.583 |
| 12 | S1 | `bpf_local_call_fanout_dispatch` | 81 | 135 | 0.600 |
| 13 | S1 | `siphash_rotate64_mixer` | 43 | 68 | 0.632 |
| 14 | S1 | `tracee_syscall_name_table_lookup` | 103 | 156 | 0.660 |
| 15 | S1 | `cilium_policy_guard_tree_filter` | 72 | 107 | 0.673 |
| 16 | S1 | `packed_header_bitfield_decode` | 200 | 280 | 0.714 |
| 17 | S1 | `packet_checksum_fold` | 13347 | 17661 | 0.756 |
| 18 | S1 | `tc_packet_checksum_fold` | 13344 | 17637 | 0.757 |
| 19 | S1 | `tracee_http_method_prefix_detect` | 18 | 23 | 0.783 |
| 20 | S1 | `packet_vlan_tcpopt_parser` | 12 | 15 | 0.800 |
| 21 | S2 | `helper_get_pid_tgid` | 5 | 6 | 0.833 |
| 22 | S1 | `packet_toeplitz_rss_hash` | 215 | 257 | 0.837 |
| 23 | S1 | `katran_lb_consistent_hash_select` | 19 | 22 | 0.864 |
| 24 | S2 | `map_array_lookup` | 15 | 17 | 0.882 |
| 25 | S2 | `map_array_index_packet` | 15 | 17 | 0.882 |
| 26 | S1 | `flow_record_field_scan` | 68 | 73 | 0.932 |
| 27 | S1 | `bcc_runqlat_log2_histogram_bucket` | 1129 | 1208 | 0.935 |
| 28 | S2 | `combined_helper_map` | 40 | 42 | 0.952 |
| 29 | S2 | `packet_5tuple_classify` | 47 | 49 | 0.959 |
| 30 | S2 | `map_percpu_hash_counter` | 27 | 28 | 0.964 |
| 31 | S1 | `trace_event_type_switch_dispatch` | 277 | 281 | 0.986 |
| 32 | S2 | `map_hash_str_key` | 85 | 86 | 0.988 |
| 33 | S1 | `simple` | 6 | 6 | 1.000 |
| 34 | S2 | `helper_only_ktime` | 28 | 28 | 1.000 |
| 35 | S2 | `map_hash_lookup` | 81 | 81 | 1.000 |
| 36 | S1 | `bpftrace_comm_key_fnv_hash` | 439 | 438 | 1.002 |
| 37 | S2 | `map_lru_hash_counter` | 86 | 85 | 1.012 |
| 38 | S2 | `multi_map_policy` | 56 | 55 | 1.018 |
| 39 | S1 | `cgroup_skb_hash_chain` | 291 | 285 | 1.021 |
| 40 | S2 | `map_percpu_array` | 19 | 18 | 1.056 |
| 41 | S2 | `helper_chain_simple` | 33 | 31 | 1.065 |
| 42 | S2 | `stats_mixed_helpers` | 95 | 83 | 1.145 |
| 43 | S1 | `simple_packet` | 7 | 6 | 1.167 |

| metric | value |
|---|---:|
| **Combined geomean (N=43)** | **0.755x** (native_lab ~1.32x faster avg) |
| Stage 1 geomean (N=29) | 0.666x |
| Stage 2 geomean (N=14) | 0.980x |
| Wins (ratio < 0.98) | 30 |
| Losses (ratio > 1.02) | 5 |
| Ties (±2%) | 8 |
| Range | 0.277 .. 1.167 |

The biggest native_lab wins are pure-compute Stage 1 programs whose
BPF JIT has nothing to inline away (`otel_stack_frame_unwind_scan`,
`bitmap_popcount_scan`, `cilium_*`). The five losses cluster around
1.0-1.17x — programs where the kernel BPF JIT's per-call-site
optimizations (PERCPU_HASH inlining we haven't replicated, full
ARRAY/PERCPU_ARRAY LEA inlining, etc.) shave a few ns we don't yet
match. None of them is the previous 4.13x or 1.43x outlier.

### Methodology / measurement notes

- **VM**: 2 CPUs, 2 GB RAM, vng-launched host kernel 7.0-rc2+.
- **INNER_REPEAT=100000** amortizes PROG_TEST_RUN syscall dispatch
  to negligible per-iteration. Lower iter counts (<= 1000) are
  dominated by syscall overhead and produce misleading ratios.
- **SAMPLES median**: stage 1 uses 5, stage 2 uses 15. Stage 2
  numbers are stable across consecutive sweeps; Stage 1 has more
  per-sample timer noise (smaller absolute ns / iter for many
  programs) but the medians are reproducible to within a few ns.
- **Output format hardening** (Stage 1): the original
  `run_all_micro.sh` streamed JSON over the VM serial console which
  occasionally interleaved bytes between two consecutive writes
  (producing things like `}{"{"program":`). It now writes each
  `(program, runtime)` result to its own temp file under the VM's
  `/tmp/stage1-sweep-out/` and cats them at the end as a single
  uninterrupted stream. The `tc_packet_checksum_fold` row that
  previously showed `native_lab=None` was a casualty of that
  corruption; it now reports correctly (0.757 ratio).
