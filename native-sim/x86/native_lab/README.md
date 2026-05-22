# Native Kernel — running userspace-compiled x86 in kernel as eBPF replacement

A research escape hatch that lets userspace upload arbitrary x86-64 byte
sequences and execute them in kernel context as if they were the body of
a BPF program. The whole pipeline is end-to-end functional and gives us a
true "no verifier, no BPF JIT translation" performance baseline to compare
against bpfopt+kinsn passes — i.e. the A column of the OSDI paper's
three-archetype comparison.

## Goal

For each micro benchmark in `micro/programs/*.bpf.c`:

| column | what runs | what it tells us |
|--------|-----------|------------------|
| **A. native kernel** (`native_lab`) | clang -target x86_64 -O2 of the same `.bpf.c` source → linked through `native-link` → splatted into a BPF JIT image via the `bpf_x86_native_lab` kinsn | what the function would cost with no verifier inserts, no BPF→x86 translation |
| **B. kinsn** | the production bpfopt+kinsn pipeline (run via `make micro` etc.) | how close the production pipeline gets to A |
| **C. kernel BPF JIT** | stock `.bpf.o` → libbpf → BPF JIT | the BPF performance baseline B is trying to beat |

This directory ships A. B and C run through existing `make micro` infra;
the integration just exposes A as a new runtime mode (`run-native-lab`)
inside the same `micro_exec` binary.

## Architecture

```
                         userspace                                  kernel
   ┌──────────────┐  link   ┌─────────────┐  upload  ┌─────────────────────┐
   │ .native.so   │ ──────▶ │ .native.bin │ ────────▶│ /sys/kernel/debug/  │
   │ (clang x86)  │ native- │ (≤128 B per │ debugfs  │ bpf_x86_native_lab/ │
   └──────────────┘  link   │  chunk × N) │          │ blob{0..63}         │
                            └─────────────┘          └─────────────────────┘
                                                                │
   ┌──────────────────────────────────────┐                     │
   │ tiny BPF stub (built at runtime)     │  BPF_PROG_LOAD      ▼
   │   for each chunk:                    │ ───────────────▶ verifier sees
   │     sidecar(blob_id=i)               │                  `r0 = XDP_PASS`
   │     call bpf_x86_native_lab_emit     │                  (the kinsn's
   │   exit                               │                   instantiate_insn
   └──────────────────────────────────────┘                   proof; the actual
                                                              emit_x86 splats
                                                              raw bytes)
                                                                │
   BPF_PROG_TEST_RUN  ─────────────────────────────────────────▶ JIT image:
                                                                 [BPF prologue]
                                                                 [chunk 0 bytes]
                                                                 [chunk 1 bytes]
                                                                 ...
                                                                 [chunk N-1]
                                                                 [BPF epilogue]
```

## Layout

```
native-sim/x86/native_lab/
├── README.md                        — this file
├── native_link/                     — Rust ELF → native blob linker
│   ├── Cargo.toml
│   └── src/main.rs                  — uses `object` + `iced-x86`
├── tests/
│   ├── poc.c                        — bare-bones mechanism smoke test
│   │                                  (return 42 + multi-chunk wraparound)
│   ├── run_vm.sh                    — vng wrapper for poc.c
│   ├── run_micro_one.sh             — vng wrapper: link + run one program
│   │                                  through both runtimes
│   ├── run_all_micro.sh             — sweep every xdp micro benchmark
│   ├── analyze.py                   — per-program ratio + geomean
│   └── Makefile                     — builds poc.c
└── results/                         — JSONL output of run_all_micro.sh
                                      (gitignored)
```

The kernel-side kinsn module lives at `module/x86/bpf_x86_native_lab.c`
because the project's existing kinsn build pipeline auto-scans that
directory. Conceptually it's part of this research line; physically it
sits with the other kinsn modules so `make host-kinsn-x86` picks it up.

## The linker — what it actually does

`native-link` reads a userspace `.so` produced by
`micro/programs/Makefile`'s `MICRO_NATIVE` build path. It does the
absolute minimum work needed to bridge two ABIs:

1. **SysV AMD64** (what clang emits): `rdi` = first arg, `rax` = return,
   `rbx`/`rbp`/`r12`-`r15` callee-saved, control returns via `ret`.
2. **The native kernel kinsn contract** (what kernel will run): splatted in
   the middle of a BPF JIT image where the BPF JIT prologue already
   pushed the callee-saved registers and the BPF JIT epilogue expects to
   pop them. The blob must fall through to the epilogue, never `ret`.

The transformation:

1. `object` parses the ELF and finds the symbol's `.text` byte slice.
2. `iced_x86::Decoder` disassembles those bytes.
3. Compiler alignment NOPs are dropped (iced re-encodes multi-byte NOPs
   to shorter forms; dropping them sidesteps the size-arithmetic).
4. Every `RET` / `Retfq` / `Ret*_imm16` is replaced with a 5-byte
   `JMP rel32 -> end_label` placeholder.
5. `BlockEncoder::encode` lays out the block at IP=0 and reports each
   instruction's new offset.
6. We patch the `disp32` of each placeholder JMP so it lands at the
   blob's tail (where the BPF JIT's exit epilogue will be emitted).
7. Any PC-relative reference whose target sits outside the function (
   rodata, GOT, other functions) is rejected up front — the kernel splat
   location doesn't match the userspace ELF layout, so silently emitting
   the original `disp` would point at garbage.

We don't strip the prologue's push-callee-saved or the epilogue's pop-
callee-saved. Compilers emit balanced push/pop along every control-flow
path, so each `ret` site already sees a balanced stack. By the time the
rewritten `jmp end_label` fires, the function has popped whatever it
pushed, and the BPF JIT prologue's saved values are intact.

## Building

```sh
# 1. Rust linker
cargo build --release --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml

# 2. Kinsn module (uses the existing host-kinsn-x86 target)
make host-kinsn-x86

# 3. micro_exec (the `run-native-lab` mode is already wired into the
#    existing CMake target via runner/src/native_lab_runner.cpp)
cmake --build runner/build-llvmbpf --target micro_exec -j8

# 4. Micro programs' .native.so (already built by `make micro` or by hand)
make -C micro/programs
```

## Running

End-to-end: link one program, run native kernel and kernel BPF JIT under
the same input, print both samples:

```sh
vng --run vendor/build/x86/linux/arch/x86/boot/bzImage \
    --cwd "$(pwd)" --rwdir "$(pwd)" --overlay-rwdir /tmp \
    --cpus 2 --memory 2G \
    --append "loglevel=4 panic=30 oops=panic" \
    --exec "native-sim/x86/native_lab/tests/run_micro_one.sh bitmap_popcount_scan bitmap_popcount_scan_xdp 2056 1000"
```

Full sweep (all 26 xdp micros):

```sh
vng ... --exec native-sim/x86/native_lab/tests/run_all_micro.sh \
    > native-sim/x86/native_lab/results/all_micro.jsonl

python3 native-sim/x86/native_lab/tests/analyze.py
```

## Limitations (and why they're acceptable for the research goal)

- **No verifier protection at all.** Any blob with bad reg/state usage
  panics the kernel. This module is research-only; do not load it on
  production kernels.
- **Helper calls cannot be blindly lowered to `call rel32`.** On x86-64,
  `call rel32` can only reach +/-2GB from the JIT image. A 2026-05-21
  KVM validation run that rewrote helper calls to side-band direct
  `call rel32` relocs failed `BPF_PROG_LOAD` with `-ENOTSUPP` because
  the BPF JIT text and helper symbols were out of range. The native
  linker must either keep an indirect absolute call sequence or use a
  near thunk placed in the same JIT allocation; silently assuming direct
  helper reachability is not hardware-equivalent.
- **Entry save/restore cannot be stripped blindly after codegen.** A 2026-05-21
  KVM validation run removed x86 entry `push r15/r14/r12/rbx` and the
  matching pops in `native-link`; `helper_chain_simple` then panicked
  with an NX instruction fetch inside the native blob. The BPF JIT
  wrapper is not a normal SysV call frame, so post-link ABI surgery is
  unsafe unless it is proven against the concrete BPF JIT epilogue.
  A later 2026-05-21 run stripped `rbp` too and `multi_map_policy`
  panicked at the BPF epilogue `leave; ret`: the entry blob had used
  `rbp` as a normal temporary, corrupting the JIT frame pointer. The
  retained rule is therefore narrower: keep `rbp` save/restore, and only
  strip `rbx`/`r12`-`r15` when the prologue/epilogue shape matches.
- **Helper/map lowering should follow the BPF JIT's concrete ABI.** A
  2026-05-21 x86 KVM run added native lowering for the verifier/JIT's
  `bpf_get_smp_processor_id()` inline sequence (`cpu_number` plus
  `this_cpu_off`) and changed ARRAY/PERCPU_ARRAY lookup lowering to use
  the live SysV `rdi` map argument as the base pointer instead of
  materializing `map + value_offset` with `movabs`. The focused
  validation result `micro/results/x86_kvm_micro_20260521_090054_992787`
  kept all return values and packet result words identical to the kernel
  baseline; array blob sizes dropped by 9 bytes per lookup site.
- **Do not lower compiler-CSE'd helper pointer calls without a full ABI
  proof.** Clang can cache `bpf_map_lookup_elem@GOTPCREL` in a
  callee-saved register and emit `call r14` for multiple lookup sites.
  A 2026-05-21 x86 KVM experiment tried to recover per-call map metadata
  from that pattern and rewrite those calls, but `stats_mixed_helpers`
  faulted inside the native blob while dereferencing the first lookup
  result. That optimization was removed; the recovery run
  `micro/results/x86_kvm_micro_20260521_095307_768255` completed with
  matching return values and packet result words.
- **Do not trade indirect helper calls for PLT32 thunks without a size
  win.** A 2026-05-21 x86 KVM experiment removed `-fno-plt` and routed
  per-site `R_X86_64_PLT32` map-lookup relocations through the same
  inline metadata path. Correctness passed, but the focused runs
  `micro/results/x86_kvm_micro_20260521_094311_254827` and
  `micro/results/x86_kvm_micro_20260521_094813_982550` grew the blobs
  and showed no speed improvement. The build keeps `-fno-plt` plus the
  existing absolute helper trampoline.
- **Do not switch helper calls to side-band `call rel32` yet.** A
  2026-05-21 x86 KVM experiment replaced native-link's
  `movabs rax, helper; call rax` helper sequence with 5-byte
  `call rel32` placeholders plus native_lab relocation records. The
  focused run `micro/results/x86_kvm_micro_20260521_101550_546051`
  failed before workload execution: every tested helper/map benchmark hit
  `bpf_prog_load (native_lab stub): Unknown error 524` with a verifier
  log that had already processed the tiny stub. The experiment was
  removed; the recovery run
  `micro/results/x86_kvm_micro_20260521_101943_299336` completed with
  matching return values and packet result words. Keep the absolute
  helper-call path until the module/kernel JIT relocation failure is
  understood.
- **Direct helper calls must be opportunistic, not assumed.** A later
  2026-05-21 x86 KVM experiment kept a 13-byte
  `movabs r11, helper; call *r11` slot and let the kernel module patch it
  to `call rel32; nop8` only if the final helper address is in range.
  Correctness passed in
  `micro/results/x86_kvm_micro_20260521_131020_098407`, but the JIT dump
  still showed the absolute-indirect form, so the extra relocation kind
  was removed. The retained helper-call lowering is the range-independent
  absolute-register call sequence.
- **Instruction replacements must keep the replaced instruction's
  original IP.** A 2026-05-21 KVM JIT dump from
  `micro/results/x86_kvm_micro_20260521_132250_159715` showed
  `multi_map_policy` emitting a `je -1` after an inline ARRAY lookup.
  The branch target was the original GOT load, but native-link had
  replaced that one instruction with a synthetic `movabs` that no longer
  carried the original local IP. The fix records one-instruction
  replacements at the replaced local IP; the focused validation
  `micro/results/x86_kvm_micro_20260521_134806_999032` kept
  map/helper return values matching `kernel` and the dump now branches
  to real instruction boundaries.
- **RIP literal-pool helper calls were tested and not kept.** A
  2026-05-21 x86 KVM experiment used `call *disp32(%rip)` through a
  blob-local literal pool so the call instruction stayed shorter than
  `movabs r11; call *r11`. Correctness passed in
  `micro/results/x86_kvm_micro_20260521_134403_234702`, but the focused
  helper/map cases showed no speedup and larger blobs, so the linker was
  restored to the absolute-register helper-call sequence.
- **Use `rax` for absolute helper-call targets on x86.** A 2026-05-21
  focused KVM run changed the helper-call sequence from
  `movabs r11, helper; call *r11` to `movabs rax, helper; call *rax`.
  `rax` is caller-saved and not a SysV helper argument register, so this
  remains ABI-equivalent while saving one byte per helper call. The run
  `micro/results/x86_kvm_micro_20260521_135332_450788` kept all three
  focused map/helper cases correct and reduced native blob size from
  336/125/239 bytes to 335/123/237 bytes. A repeat single-case run
  `micro/results/x86_kvm_micro_20260521_135631_031982` confirmed
  `map_percpu_hash_counter` remained at 27 ns samples with matching
  result values.
- **Use the short x86 ARRAY bounds compare when possible.** A
  2026-05-21 focused KVM run changed inlined ARRAY/PERCPU_ARRAY lookup
  bounds checks from `cmp eax, imm32` to `cmp eax, imm8` when
  `max_entries <= 127`. The focused run
  `micro/results/x86_kvm_micro_20260521_140414_825532` kept all five
  affected benchmarks correct. Native blob sizes dropped by 2 bytes per
  affected array lookup site: `map_array_lookup` 132 -> 130,
  `map_array_index_packet` 140 -> 138, `map_percpu_array` 144 -> 142,
  `combined_helper_map` 165 -> 163, and `multi_map_policy` 335 -> 331.
- **Use sign-extended imm32 helper target loads when exact.** A
  2026-05-21 focused KVM run changed x86 helper target materialization
  from unconditional `movabs imm64` to `mov r64, sign_extend(imm32)`
  when the full helper address is exactly representable that way, falling
  back to `movabs` otherwise. Map pointers still use `movabs` because
  live map addresses such as `0xffff8...` are not generally sign-extended
  low-32-bit values. The focused run
  `micro/results/x86_kvm_micro_20260521_141224_348437` kept helper
  return values correct and reduced `helper_only_uid_gid`/`helper_chain`
  / `map_hash_lookup` native blob sizes to 32/153/126 bytes.
- **Inline simple ARRAY/PERCPU_ARRAY update helpers only at proven call
  sites.** A 2026-05-21 x86 KVM run added `--update-site` metadata from
  the companion BPF bytecode and lowered direct `bpf_map_update_elem`
  call sites for ARRAY/PERCPU_ARRAY maps with 1/2/4/8-byte values into
  the kernel arraymap bounds/flags/store sequence. Focused validation in
  `micro/results/x86_kvm_micro_20260521_142752_403207` kept return
  values and packet output equal to `kernel` while moving
  `map_array_lookup`, `map_array_index_packet`, and `map_percpu_array`
  down to 6-7 ns samples and `combined_helper_map` down to 13 ns. The
  full x86 stage2 run
  `micro/results/x86_kvm_micro_20260521_143430_287023` passed all 13
  native/kernel cases and the proof build. Do not apply this to
  compiler-CSE'd helper pointers (`call rbp`/`call r14`) without a
  separate ABI proof; `multi_map_policy` deliberately keeps those update
  calls on the real helper path.
- **The same ARRAY/PERCPU_ARRAY update inline is now wired for arm64.**
  The arm64 linker consumes the same `--update-site` metadata and lowers
  direct `bpf_map_update_elem` calls into the arraymap bounds/flags/store
  sequence, using `TPIDR_EL1` for PERCPU_ARRAY value selection like the
  arm64 lookup inline. A focused AWS run
  `micro/results/aws_arm64_micro_20260521_145305_707860` kept all five
  affected native/kernel cases correct and improved the old focused run:
  `map_array_lookup` 26-27 ns -> 17 ns, `map_percpu_array` 27-28 ns ->
  20-21 ns, and `multi_map_policy` 123-124 ns -> 110 ns. The full arm64
  stage2 run `micro/results/aws_arm64_micro_20260521_150209_297924`
  passed all 13 native/kernel cases with matching return values and
  packet/result words; the arm64 proof build was 29/29 ok.
- **x86 callee-saved pressure needs a real codegen strategy.** Raising
  LLVM's CSR first-use cost for x86 increased helper/map object sizes in
  the focused compile check, so that knob was not kept. Avoiding
  redundant save/restore should be solved before or during codegen, not
  by post-link deletion.
- **Terminal return deletion is safe only when all exits still run the
  BPF return bridge.** On x86, native-link now deletes a final
  `jmp +0` when the rewritten entry return is already at blob end; early
  returns still jump to the same end offset. The full 2026-05-21 KVM run
  `micro/results/x86_kvm_micro_20260521_132250_159715` passed all 13
  helper/map cases against `kernel`, with matching return values and
  packet result words. On arm64, the analogous optimization replaces the
  terminal return with `mov x7, x0` and redirects early returns to that
  word only when the entry tail contains padding NOPs and no literal pool
  or subprogram follows it; a local native-link sanity check reduced
  `simple_xdp` from 92 to 84 bytes. Helper/map arm64 blobs with a tail
  literal pool deliberately keep the shared return trampoline.
- **PERCPU_HASH inline was tested and not kept.** A 2026-05-21 x86 KVM
  focused run changed PERCPU_HASH lookup routing from
  `htab_percpu_map_lookup_elem` to `__htab_map_lookup_elem` plus the
  kernel-style per-cpu post-call sequence. Correctness passed in
  `micro/results/x86_kvm_micro_20260521_100128_134607`, but
  `map_percpu_hash_counter` grew from 147 to 168 native bytes with no
  runtime improvement. The restored run
  `micro/results/x86_kvm_micro_20260521_100511_996786` keeps the smaller
  helper-call path and matching results.
- **The runtime image needs GNU `objdump`.** The micro driver writes
  post-run code-compare markdown by disassembling native objects and JIT
  dumps. A 2026-05-21 KVM validation run completed both helper workloads
  but failed during artifact finalization with `FileNotFoundError:
  objdump`. This is a runtime-image dependency issue, not a native blob
  correctness failure.
- **Local-call symbol layout needs separate start/end maps.**
  `bpf_local_call_fanout_dispatch` exercises `__noinline`
  subprograms. A 2026-05-21 arm64 AWS run found that using one global
  original-address -> blob-offset map for both symbol starts and symbol
  ends can corrupt `BL` targets when discovery order differs from ELF
  address order. Keep subprogram calls keyed by symbol start, and keep
  intra-symbol branch-to-end targets keyed by the source symbol.
- **arm64 helper/map focused validation is passing.** The 2026-05-21 AWS
  arm64 focused run
  `micro/results/aws_arm64_micro_20260521_091309_937248` covered
  ARRAY/PERCPU_ARRAY, helper+map, multi-map, and mixed-helper cases with
  `native_kernel` and `kernel`; all return values and packet result
  words matched.
- **Proof generation now goes through native-link stage 1.** On
  2026-05-21, x86 and arm64 proof generators were changed to consume
  `native-link --mode proof` output for both the pure 29 and the
  helper/map stage2 13 programs. Python no longer parses ELF relocation
  records from the original native objects; native-link owns ELF
  relocation discovery and emits relocatable `.proof.o` files with
  helper/map/rodata relocations. The generator only disassembles those
  proof objects and emits labels plus simulator instruction macros.
  Local proof runs passed again after this split:
  x86 stage2 `native-sim/x86/results/README-20260521-proof-object-stage2.md`,
  x86 pure `native-sim/x86/results/README-20260521-proof-object-pure.md`,
  arm64 stage2 `native-sim/arm64/results/README-20260521-proof-object-stage2.md`,
  and arm64 pure `native-sim/arm64/results/README-20260521-proof-object-pure.md`.
- **Proof-object exits must survive kernel lowering.** A 2026-05-21 x86
  KVM stage2 run `micro/results/x86_kvm_micro_20260521_230627_333619`
  found two proof->kernel bugs before workload completion:
  `helper_only_uid_gid` had a branch target landing on a stripped
  epilogue pop, and `map_hash_str_key` fell through from the entry
  epilogue into appended rodata/literal bytes. The fix keeps the proof
  object's final `jmp end` marker, remaps branches that target stripped
  epilogue pops to the retained entry-exit marker, and makes kernel mode
  treat a proof-object entry `jmp` to symbol end as a `JmpEnd` site so
  late helper/map lowering can redirect it past appended pools. After
  that, x86 proof runs passed again for stage2 13/13 and pure 29/29, and
  KVM smoke runs passed with matching `native_kernel`/`kernel` results:
  stage2 `micro/results/x86_kvm_micro_20260521_231330_690264` and pure
  `micro/results/x86_kvm_micro_20260521_231746_727344`.
- **Make/runtime incrementality still has non-kernel repeat work.** The
  arm64 QEMU rootfs assembly was changed from a phony rebuild to the real
  file target `$(ARM64_QEMU_ROOT)/qemu-init`, so QEMU rootfs export is no
  longer forced by the target name. Separate from that, `make micro`
  still re-enters several vendor app recipes and rebuilds upper Docker
  runtime layers when runner/stage2 contexts change, and each AWS run
  starts a fresh instance that installs Docker again. These are build/run
  orchestration costs, not native blob correctness failures.
- **LRU_HASH lookup must preserve the kernel post-call sequence.** A
  2026-05-22 x86 KVM `map_lru_hash_counter` run oopsed in
  `htab_lru_map_delete_elem` after native-link routed lookup to
  `__htab_map_lookup_elem` but treated the returned `struct htab_elem *`
  as a map value pointer. That skipped the kernel JIT's LRU ref-byte
  update and value-offset add, so the workload wrote into the hash/LRU
  node. The linker now lowers LRU_HASH lookup as call-plus-postcall using
  kernel-derived `htab_elem.lru_node`, `bpf_lru_node.ref`, and
  `htab_elem.key` offsets. Validation after the fix: x86 KVM stage2
  native/kernel 13/13 passed in
  `micro/results/x86_kvm_micro_20260522_015723_998680`; x86 KVM pure
  native/kernel 29/29 passed in
  `micro/results/x86_kvm_micro_20260522_020005_773095`; x86 proof
  stage2 13/13 passed in
  `native-sim/x86/results/README-20260521-190151-991324.md`; x86 proof
  pure 29/29 passed in
  `native-sim/x86/results/README-20260521-190157-769852.md`.
- **Proof run targets now honor their object directory.**
  `micro-proofs-run` now passes `--build-dir "$(PROOF_BUILD_DIR)"` for
  both x86 and arm64, matching `micro-proofs-build`. The x86 stage2 proof
  run above populated `native-sim/test/build-x86/x86_sim_proofs` instead
  of the default x86 proof object directory.
- **arm64 proof->kernel lowering must keep verifier-visible map
  semantics.** A 2026-05-22 AWS arm64 `helper_chain_simple` run first
  exposed a kernel-mode crash/reboot: kernel lowering treated the
  proof-stage canonical `mov x7, x0` return marker as an ordinary
  instruction, then appended map literal bytes immediately after it. The
  normal return path could fall into that literal pool. Kernel mode now
  treats the final arm64 canonical return marker like a return site and
  branches over appended literals to the final native_lab return
  trampoline. The next run no longer rebooted, but returned result `1`
  instead of `0` because HASH lookup used the companion JIT target
  without the kernel JIT post-call value-offset add. arm64 now uses the
  same HASH/LRU_HASH/PERCPU_HASH call-plus-postcall lowering boundary as
  x86. Validation after the fix: arm64 AWS stage2 native/kernel 13/13
  passed in `micro/results/aws_arm64_micro_20260522_045503_769361`;
  x86 KVM stage2 native/kernel 13/13 passed in
  `micro/results/x86_kvm_micro_20260522_045841_826464`; stage2 proof
  13/13 passed for x86 in
  `native-sim/x86/results/README-20260521-215912-734470.md` and arm64 in
  `native-sim/arm64/results/README-20260521-215912-728238.md`.
- **arm64 proof-object return branches must remain return branches in
  kernel mode.** After switching kernel lowering to consume the proof
  `.o`, `helper_chain_simple` exposed a second version of the same
  class of bug: proof mode had already rewritten `ret` to
  `b __native_link_arm64_ret_trampoline`, and kernel mode treated that
  branch target as "entry symbol end". When map literals were appended,
  the entry symbol end became the literal pool, so both early and normal
  returns branched into data. Kernel mode now recognizes proof-object
  branches to the trampoline symbol and repatches them to the final
  kernel-stage return trampoline; conditional branches to the trampoline
  fail fast. Validation after the fix: arm64 AWS `helper_chain_simple`
  native-only passed in
  `micro/results/aws_arm64_micro_20260522_195730_326099`; current
  arm64 AWS stage2 native/kernel 13/13 passed in
  `micro/results/aws_arm64_micro_20260522_200701_786527`; current x86
  KVM pure/stage2 native/kernel passed in
  `micro/results/x86_kvm_micro_20260522_201404_601577` and
  `micro/results/x86_kvm_micro_20260522_201850_232073`.
- **arm64 native blobs must not keep their own entry callee-saved
  frame.** Later 2026-05-22 AWS arm64 mixed native/kernel runs showed
  intermittent reboot while repeatedly executing `helper_only_uid_gid`.
  The generated arm64 blob still contained compiler AAPCS entry
  save/restore such as `stp x30, x19, [sp, #-16]!` / `ldp x30, x19,
  [sp], #16`, unlike x86 where native-link trims the entry ABI frame and
  asks the BPF JIT to preserve raw-blob callee-saved registers via the
  kinsn sidecar. arm64 now uses the same model: proof mode replaces entry
  STP/LDP save/restore pairs for x19..x22/x30 with NOPs, records a
  generic `callee_saved_mask` in `.native_link_abi`, and the arm64
  native_lab proof marks BPF r6..r9 as used so the BPF JIT prologue owns
  saving x19..x22.
- **Non-xdp prog types** (`tc_packet_checksum_fold`,
  `cgroup_skb_hash_chain`) are skipped — the stub BPF program is
  currently hard-coded to `BPF_PROG_TYPE_XDP`. Extending to sched_cls /
  cgroup_skb is straightforward but unnecessary for the paper claim,
  which targets the xdp population.
- **No `.rodata` references.** The linker bails on any RIP-relative
  load whose target is outside the function's bytes. Today's micro
  programs are pure-compute so this never fires; if a future program
  needs a lookup table, the linker will need to splat the `.rodata`
  bytes adjacent to `.text` and fix up the `disp32`s.
- **`bpf_x86_native_lab` is loaded explicitly, never automatically.**
  It is *not* part of `expected_kinsn_modules()` and the production
  benchmark runner doesn't insmod it. Smoke scripts insmod it before
  use.

## Latest results (`results/all_micro.jsonl`)

See `tests/analyze.py` output. Headline numbers:

- 26 programs measured, 1 linker-rejected, 2 skipped (non-xdp).
- Per-program geomean of native kernel / kernel eBPF = **0.6438x**
  (native kernel is 1.55x faster on average).
- 23 wins, 2 losses, 1 tie.
- All 26 measured programs match the kernel JIT output bit-for-bit
  (`result` field identity check).
