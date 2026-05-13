# x86 native C instruction gap vs current kInsn passes

Date: 2026-05-13

This note answers one question: when benchmark-set BPF C sources are compiled
directly to native x86, which x86 instructions does clang actually choose, and
what still differs from the current BPF bytecode -> kInsn -> x86 path?

The important split is:

- `bpfopt/testccode/*.x86.s`: direct C -> x86 evidence. This is the strongest
  evidence for "clang really emits this instruction from the app source".
- `bpfopt/testobject/*.bpf.o`: one BPF object per copied source file. These are
  useful for object-level source/object comparison, but they are not yet split
  into the exact live program bytecode that the optimizer sees.
- `bpfopt/testbin/*/*/canonicalize_output.bin`: live per-program BPF bytecode
  after canonicalize-map-refs. This is the strongest evidence for whether a
  current bpfopt pass can recover a semantic site from production bytecode.

Generated native assembly is an instruction-shape check, not a replacement for
the real app loader path or a benchmark result. The copied sources are kept close
to upstream benchmark app sources and use local shims only for BPF-only headers,
helpers, maps, and compiler builtins.

## Executive conclusion

The real-app direct native census changed the priority order:

1. Katran jhash is a `rotate32` problem, not a `jhash` kInsn problem. Native
   x86 emits 20 independent 32-bit `rorx` sites in `katran_balancer`, and
   current testbin bytecode has exactly 20 Katran rotate sites. Keep this as
   `bpf_rotate32`.
2. The cleanest remaining x86-emitter parity gap is endian load: direct native
   emits 91 `movbe` instructions across Cilium/Katran/OTel/Tetragon/Tracee, and
   current `endian_fusion` finds 260 testbin sites, but the x86 emitter still
   emits load+`bswap`/`rol`.
3. `cmov`/`setcc` are very real in direct native output: 661 `cmov*` and 475
   `setcc`. Current `cond_select` already applies many bytecode sites, but its
   boolean-condition ABI cannot match native `cmp/test + cmovcc` as tightly as a
   compare-select kInsn could.
4. `lea` is massive in native output, but the count alone does not justify a
   `bpf_lea` kInsn. Much of it is x86 address-mode selection or flagless add
   selection after native register allocation. That needs the separate LEA
   native-vs-BPF census, and may be a kernel-JIT/address-mode problem rather
   than a bpfopt kInsn problem.
5. `bextr`, `lzcnt`, `tzcnt`, and `prefetch*` are not emitted by direct native
   clang for these 37 real-app sources. Do not prioritize them as native-parity
   kInsns. `popcnt` exists, but only 7 sites in Tracee, so it needs a bytecode
   loop census before code.

## Corpus used

`bpfopt/testccode` currently has 37 copied real-app C files, with generated
`.x86.s` and `.arm64.s` for each. `bpfopt/testobject` has the corresponding 37
BPF objects. App coverage:

| App prefix | C files | x86 asm | arm64 asm | BPF objects |
|---|---:|---:|---:|---:|
| `bcc` | 8 | 8 | 8 | 8 |
| `bpftrace` | 9 | 9 | 9 | 9 |
| `cilium` | 7 | 7 | 7 | 7 |
| `katran` | 5 | 5 | 5 | 5 |
| `otel` | 3 | 3 | 3 | 3 |
| `tetragon` | 2 | 2 | 2 | 2 |
| `tracee` | 3 | 3 | 3 | 3 |
| Total | 37 | 37 | 37 | 37 |

The native build entrypoint is `bpfopt/testccode/Makefile`. It compiles x86 with
`-O3 --target=x86_64-linux-gnu -march=x86-64-v3 -masm=intel` and arm64 with
`-O3 --target=aarch64-linux-gnu -march=armv8.2-a`. `make -q -C
bpfopt/testccode x86` and `make -q -C bpfopt/testccode arm64` both returned
status 0, so the generated asm was up to date during this check.

Source files:

```text
bcc_biosnoop.bpf.c
bcc_capable.bpf.c
bcc_opensnoop.bpf.c
bcc_runqlat.bpf.c
bcc_syscount.bpf.c
bcc_tcpconnect.bpf.c
bcc_tcplife.bpf.c
bcc_vfsstat.bpf.c
bpftrace_base.bpf.c
bpftrace_map_map.bpf.c
bpftrace_process_process.bpf.c
bpftrace_strings_strings.bpf.c
bpftrace_system_system.bpf.c
bpftrace_task_task.bpf.c
bpftrace_task_vma.bpf.c
bpftrace_test_test.bpf.c
bpftrace_usdt_usdt.bpf.c
cilium_bpf_alignchecker.bpf.c
cilium_bpf_host.bpf.c
cilium_bpf_lxc.bpf.c
cilium_bpf_overlay.bpf.c
cilium_bpf_sock.bpf.c
cilium_bpf_wireguard.bpf.c
cilium_bpf_xdp.bpf.c
katran_balancer.bpf.c
katran_healthchecking.bpf.c
katran_healthchecking_ipip.bpf.c
katran_xdp_pktcntr.bpf.c
katran_xdp_root.bpf.c
otel_generic_probe.bpf.c
otel_native_stack_trace.bpf.c
otel_sched_monitor.bpf.c
tetragon_bpf_generic_kprobe.c
tetragon_bpf_generic_tracepoint.c
tracee_lsm_support_kprobe_check.bpf.c
tracee_lsm_support_lsm_check.bpf.c
tracee_tracee.bpf.c
```

## Direct C -> x86 census

Counts below are mnemonic counts in `bpfopt/testccode/*.x86.s`, skipping labels,
directives, and comments.

| App | Objects | Insns | `rorx` | `cmov` | `setcc` | `movbe` | `bswap` | `rol` | `lea` | `shrx` | `shlx` | `sarx` | `bextr` | `popcnt` | `lzcnt` | `tzcnt` | `prefetch` | vector `v*` | `imul` | `adc/sbb` | `rep` |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| bcc | 8 | 2493 | 0 | 2 | 9 | 0 | 0 | 0 | 285 | 8 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 51 | 0 | 0 | 0 |
| bpftrace | 9 | 453 | 0 | 2 | 0 | 0 | 0 | 0 | 20 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 35 | 0 | 1 | 0 |
| cilium | 7 | 10040 | 0 | 47 | 6 | 57 | 0 | 0 | 1796 | 7 | 13 | 0 | 0 | 0 | 0 | 0 | 0 | 88 | 10 | 0 | 0 |
| katran | 5 | 2400 | 20 | 22 | 3 | 8 | 0 | 6 | 225 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 81 | 2 | 0 | 0 |
| otel | 3 | 4419 | 0 | 64 | 8 | 12 | 0 | 0 | 359 | 0 | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 625 | 0 | 2 | 0 |
| tetragon | 2 | 25558 | 2 | 180 | 184 | 6 | 0 | 0 | 2841 | 0 | 2 | 2 | 0 | 0 | 0 | 0 | 0 | 130 | 12 | 0 | 0 |
| tracee | 3 | 330852 | 11 | 344 | 265 | 8 | 4 | 0 | 36627 | 0 | 44 | 0 | 0 | 7 | 0 | 0 | 0 | 8070 | 89 | 18 | 0 |
| Total | 37 | 376215 | 33 | 661 | 475 | 91 | 4 | 6 | 42153 | 16 | 62 | 3 | 0 | 7 | 0 | 0 | 0 | 9080 | 113 | 21 | 0 |

Largest per-file sites:

| Family | Files |
|---|---|
| `rorx` | `katran_balancer.bpf.x86.s` 20, `tracee_tracee.bpf.x86.s` 11, `tetragon_bpf_generic_kprobe.x86.s` 2 |
| `cmov` | `tracee_tracee.bpf.x86.s` 344, `tetragon_bpf_generic_kprobe.x86.s` 122, `otel_native_stack_trace.bpf.x86.s` 64, `tetragon_bpf_generic_tracepoint.x86.s` 58 |
| `setcc` | `tracee_tracee.bpf.x86.s` 265, `tetragon_bpf_generic_kprobe.x86.s` 108, `tetragon_bpf_generic_tracepoint.x86.s` 76 |
| `movbe` | Cilium files 57 total, `otel_native_stack_trace.bpf.x86.s` 7, `katran_balancer.bpf.x86.s` 6, Tracee 8, Tetragon 6 |
| `popcnt` | `tracee_tracee.bpf.x86.s` 7 |
| `lea` | `tracee_tracee.bpf.x86.s` 36621, Tetragon 2841, Cilium 1796, OTel 359, Katran 225 |

Tracee is huge because `tracee_tracee.bpf.c` compiles a large real source file;
use its counts as instruction-shape evidence, not as a statement that every
static function is equally hot in the benchmark workload.

## Current testbin pass census

This was run over all 542 committed `bpfopt/testbin/*/*/canonicalize_output.bin`
programs with `target/release/bpfopt`, using a target containing
`bpf_rotate64`, `bpf_rotate32`, `bpf_select64`,
`bpf_endian_load16/32/64`, and `bpf_extract64`. Two `cond_select` invocations
hit the 10 second offline-analysis timeout; other pass invocations completed.

| App | Pass | Programs | Matched | Applied | Skipped | BPF insn delta |
|---|---|---:|---:|---:|---:|---:|
| bcc_set | rotate | 21 | 0 | 0 | 0 | 0 |
| bcc_set | cond_select | 21 | 8 | 8 | 0 | 39 |
| bcc_set | endian_fusion | 21 | 1 | 1 | 0 | 0 |
| bcc_set | extract | 21 | 1 | 1 | 0 | 0 |
| bpftrace_set | rotate | 9 | 0 | 0 | 0 | 0 |
| bpftrace_set | cond_select | 9 | 4 | 4 | 0 | 20 |
| bpftrace_set | endian_fusion | 9 | 1 | 1 | 0 | 0 |
| bpftrace_set | extract | 9 | 0 | 0 | 0 | 0 |
| cilium_agent | rotate | 53 | 0 | 0 | 0 | 0 |
| cilium_agent | cond_select | 53 | 244 | 234 | 10 | 1011 |
| cilium_agent | endian_fusion | 53 | 24 | 24 | 0 | 0 |
| cilium_agent | extract | 53 | 0 | 0 | 0 | 0 |
| katran | rotate | 1 | 20 | 20 | 0 | -80 |
| katran | cond_select | 1 | 7 | 7 | 0 | 14 |
| katran | endian_fusion | 1 | 6 | 6 | 0 | 0 |
| katran | extract | 1 | 0 | 0 | 0 | 0 |
| otelcol-ebpf-profiler_profiling | rotate | 13 | 0 | 0 | 0 | 0 |
| otelcol-ebpf-profiler_profiling | cond_select | 12 | 34 | 34 | 0 | 103 |
| otelcol-ebpf-profiler_profiling | endian_fusion | 13 | 4 | 4 | 0 | 0 |
| otelcol-ebpf-profiler_profiling | extract | 13 | 36 | 36 | 0 | 0 |
| tetragon_observer | rotate | 287 | 44 | 44 | 0 | 0 |
| tetragon_observer | cond_select | 287 | 2003 | 1695 | 308 | 6537 |
| tetragon_observer | endian_fusion | 287 | 220 | 220 | 0 | 0 |
| tetragon_observer | extract | 287 | 114 | 114 | 0 | 0 |
| tracee_monitor | rotate | 158 | 0 | 0 | 0 | 0 |
| tracee_monitor | cond_select | 157 | 397 | 387 | 10 | 1195 |
| tracee_monitor | endian_fusion | 158 | 4 | 4 | 0 | 0 |
| tracee_monitor | extract | 158 | 47 | 37 | 10 | 0 |

Totals from completed invocations:

| Pass | Matched | Applied | Skipped | Interpretation |
|---|---:|---:|---:|---|
| rotate | 64 | 64 | 0 | All current production rotate recovery is Katran 20 + Tetragon 44. |
| cond_select | 2697 | 2369 | 328 | Broadly applicable, but not native-like enough because it consumes a boolean register rather than original compare flags. |
| endian_fusion | 260 | 260 | 0 | Good bytecode coverage; x86 emitter is the remaining MOVBE gap. |
| extract | 198 | 188 | 10 | Useful bytecode compaction, but not a native `bextr` parity argument. |

The positive BPF instruction delta for many `cond_select` sites is expected:
the replacement has to set up kfunc arguments and a boolean condition. The point
is not BPF instruction count; the point is whether the final JITed x86 can avoid
branches. This is also why compare-select is the better next ABI for native
parity.

## Why BPF -> x86 is not as optimized as direct C -> x86

Direct native clang still has source-level expression trees, x86 flags, x86
addressing modes, and vector registers available during instruction selection.
BPF bytecode has already lowered those into scalar registers, explicit jumps,
helper calls, verifier-visible pointer state, and simple memory operands.

Concrete losses visible here:

- Rotate: source/native can become `rorx`; BPF often becomes masked
  shift/shift/or with zero-extension artifacts. The current rotate matcher
  recovers the Katran and Tetragon shapes that are visible in bytecode.
- Select: source/native can use the flags from the original `cmp/test` and emit
  `cmovcc` or `setcc`. Current `bpf_select64` gets only a boolean condition
  register, so it must re-test the bool and often needs predicate setup.
- Endian: source/native can fuse a memory load and byte swap into `movbe`. The
  current kInsn recovers "endian load" semantics but emits load+`bswap`/`rol`.
- LEA/addressing: native x86 can fold arithmetic into memory operands or
  flagless `lea`. BPF cannot encode x86 SIB addressing, so many native `lea`
  sites may not correspond to any bytecode-level kInsn opportunity.
- SIMD: native x86 can use vector registers for fixed copies/reductions. BPF
  verifier state has no vector register model, so a general SIMD kInsn is not a
  production-safe first step.

The practical improvement strategy is therefore not "make a big source-level
kInsn". It is:

1. Recover narrow semantics that survive in BPF bytecode.
2. Emit the exact native instruction family when the kInsn target guarantees it.
3. Leave pure x86 instruction-selection problems to the kernel JIT where the BPF
   operation is already explicit.

## Family analysis

### `rorx` / rotate

Direct native real-app evidence:

- 33 total `rorx` sites.
- `katran_balancer.bpf.x86.s`: 20, all 32-bit operands from jhash.
- `tracee_tracee.bpf.x86.s`: 11, all 32-bit operands.
- `tetragon_bpf_generic_kprobe.x86.s`: 2, all 32-bit operands.
- No real-app `rorxq` was found in the 37-source direct native set. The older
  rotate64 evidence is still valid for micro programs, but not for this real-app
  source corpus.

Current BPF/kInsn state:

- `rotate` declares both `bpf_rotate64` and `bpf_rotate32`.
- `runner/config/passes/rotate/default.yaml` requests both target probes.
- The x86 module defines both kfuncs.
- `bpf_rotate32` x86 emitter always emits BMI2 `rorx r32, r/m32, imm`; there is
  no fallback path in the current emitter.
- `bpf_rotate64` still emits the older `mov + rol` path.
- Current testbin apply count is 64: Katran 20 and Tetragon 44.

Katran-specific conclusion:

Katran is a 32-bit rotate problem. The jhash native shape is not one opaque hash
operation; it is ordinary 32-bit add/sub/xor plus 20 independent `rorx` sites.
The closest native-like kInsn plan is:

```text
masked/zero-extended BPF shift/or rotate
  -> bpf_rotate32 payload(dst, src, shift, tmp)
  -> x86 rorx r32, r/m32, imm
```

Do not build a `jhash` kInsn. It would be less reusable, would couple the pass
to a whole hash dataflow and constants, and would not help the Tetragon/Tracee
rotate-shaped cases. The remaining differences around jhash are register
allocation, surrounding ALU scheduling, and dead mask/zero-extension code; those
belong to DCE and ordinary JIT lowering, not to a hash mega-instruction.

Tetragon note:

The 44 Tetragon rotate sites are bytecode rotate semantics recovered by the
in-place masked matcher. Rotate alone has delta 0 because the replacement cannot
blindly delete the masked temporary branch when that temp is live out on the
CFG. This is the right safety behavior. To see final cleanup, validate
`rotate,dce`, not rotate alone.

Remaining gap:

- For real apps: Tracee has 11 direct-native `rorx` sites, but current testbin
  rotate finds 0 Tracee sites. That means either those native sites do not
  survive into the live Tracee bytecode shape, or the current matcher still
  misses that BPF form. Tracee should be the next rotate census target if we
  want more rotate coverage.
- For micro rotate64: change `bpf_rotate64` x86 emitter to `rorxq` if rotate64
  remains a benchmark target. It is not the Katran fix.

### `cmov` / `setcc` / branchless conditions

Direct native real-app evidence:

- 661 `cmov*` sites across all apps.
- 475 `setcc` sites across all apps.
- Largest `cmov` files: Tracee 344, Tetragon generic kprobe 122, OTel native
  stack trace 64, Tetragon generic tracepoint 58.
- Largest `setcc` files: Tracee 265, Tetragon generic kprobe 108, Tetragon
  generic tracepoint 76.

Current BPF/kInsn state:

- `cond_select` emits `bpf_select64`.
- x86 emitter does `test cond_reg, cond_reg` plus optional `mov` and `cmov`.
- Testbin census: 2697 matched, 2369 applied, 328 skipped.

Gap:

Native clang commonly keeps the original flags:

```text
cmp/test original operands
cmovcc dst, src
```

Current `bpf_select64` gets this instead:

```text
materialize bool condition in a BPF register
CALL bpf_select64
x86: test bool,bool; cmov...
```

That can still remove branches, but it is not as tight as native C output. It
also explains why `cond_select` can increase BPF instruction count while still
being potentially useful at final x86 runtime.

Recommendation:

Add a separate compare-select kInsn rather than stretching `bpf_select64`:

```text
bpf_select_cmp64(dst, true_reg, false_reg, lhs_reg, rhs_reg_or_imm, cmp_op)
```

The x86 emitter can then generate `cmp/test + cmovcc` directly. Keep
`bpf_select64` for already-boolean conditions. A standalone `cond_bool`/`setcc`
kInsn should come later, after proving boolean values are consumed as booleans
rather than immediately feeding a select.

### `movbe` / endian fused loads

Direct native real-app evidence:

- 91 total `movbe` sites.
- Cilium contributes 57 across host/lxc/overlay/wireguard/xdp/alignchecker.
- Katran contributes 8, mainly packet/endian field loads and stores.
- OTel contributes 12, Tetragon 6, Tracee 8.
- Direct native also has 4 `bswap` and 6 `rol` sites, but `movbe` is the bigger
  real-app signal.
- This census counts all `movbe` mnemonics, including stores. The current kInsn
  is load-only, so store parity would require a separate store-side bytecode
  census and matcher.

Current BPF/kInsn state:

- `endian_fusion` emits `bpf_endian_load16/32/64`.
- Testbin census: 260 matched, 260 applied, 0 skipped.
- Current x86 emitter emits:
  - load16 + `rol16 8`;
  - load32 + `bswap32`;
  - load64 + `bswap64`.
- It does not emit `movbe`.

Gap:

The pass already recovers the right semantic operation, but the emitter does not
match direct native x86. This is a clean emitter-side/native-parity opportunity.

Recommendation:

Change the x86 emitter for `bpf_endian_load16/32/64` to emit `movbe` when the
kInsn target is exposed for a MOVBE-capable x86 target. If the module cannot
legally assume MOVBE for all deployments, make capability exposure strict rather
than silently falling back. The benchmark target already reports MOVBE in older
discovery logs, but old artifacts predate some current kInsn target shape, so a
fresh live run should still verify target probing.

### `extract` / `bextr`

Direct native real-app evidence:

- `bextr`: 0.
- `lzcnt`: 0.
- `tzcnt`: 0.

Current BPF/kInsn state:

- `extract` emits `bpf_extract64`.
- Testbin census: 198 matched, 188 applied, 10 skipped.
- Current x86 emitter emits `shr` + `and`.

Gap:

There is no direct-native `bextr` parity gap in this real-app source corpus.
`extract` can still be useful as BPF bytecode compaction or as a target for
future emitter experiments, but "clang native already emits BEXTR" is false for
these sources.

Recommendation:

Do not prioritize a BEXTR emitter change from this evidence. If wanted, treat it
as a separate microarchitecture experiment and benchmark it against `shr+and`.

### `lea`

Direct native real-app evidence:

- 42153 total `lea` sites.
- Tracee dominates with 36627.
- Tetragon has 2841, Cilium 1796, OTel 359, Katran 225, BCC 285.

Gap:

This is not enough to justify `bpf_lea`. Native `lea` has at least three
different meanings:

- x86 addressing-mode materialization;
- flagless scalar add/add-constant;
- scaled-index arithmetic after native register allocation.

BPF bytecode cannot encode x86 SIB memory operands, and many native `lea` sites
may never exist as a recoverable multi-insn scalar pattern in live bytecode.

Recommendation:

Use the separate LEA native-asm-vs-BPF-object/testbin census before adding any
code. If the evidence is mostly address-mode folding, this should be scoped as a
kernel-JIT peephole/addressing improvement, not a bpfopt kInsn. If there are many
scalar-only `mov/add/lsh/add` chains with verifier-safe register state, a narrow
scalar `bpf_lea64` could be reconsidered.

### `shrx` / `shlx` / `sarx`

Direct native real-app evidence:

- `shrx`: 16.
- `shlx`: 62.
- `sarx`: 3.
- Most `shlx` sites are Tracee/Cilium.

Gap:

These are real native x86 instructions, but they are not automatically kInsn
gaps. BPF already has variable shifts, and the kernel JIT can lower explicit BPF
variable shifts to BMI2 where supported. Add a kInsn only if JIT dumps show the
current kernel path is failing to select BMI2 for an existing BPF variable-shift
operation.

Recommendation:

No kInsn work now. Verify with JIT dumps before spending code here.

### `popcnt`

Direct native real-app evidence:

- 7 total sites, all in `tracee_tracee.bpf.x86.s`.

Gap:

BPF has no scalar popcount instruction. A kInsn could only help if the BPF
bytecode contains recognizable bitcount loops or table-free popcount idioms in
live programs. The current evidence only says native clang can emit `popcnt` in
Tracee source compilation.

Recommendation:

Do a Tracee bytecode census for popcount loops before implementing anything.
This is lower priority than MOVBE and compare-select.

### Vector `v*`, fixed copies, and bulk memory

Direct native real-app evidence:

- 9080 vector-mnemonic sites, dominated by Tracee and OTel.
- Katran has 81 vector sites in direct native output.

Gap:

This is real native output but not a good general kInsn target. BPF verifier
state has scalar registers, not vector registers. A generic vector kInsn would
require vector-state ABI decisions and save/restore rules that are much larger
than the current kInsn model.

Recommendation:

Do not build generic SIMD kInsns. For copy-like cases, continue with scalar
`wide_mem` and narrowly scoped fixed-size memory patterns. `bulk_memory` remains
for large runs; it is not the answer for Katran-style 6/16-byte copies.

### `imul`, `adc/sbb`, and plain ALU lowering

Direct native real-app evidence:

- `imul`: 113.
- `adc/sbb`: 21.

Gap:

`imul` is usually just the native lowering of existing BPF multiply; this is a
kernel JIT instruction-selection issue only if JIT dumps show a worse sequence.
`adc/sbb` is low-count and mostly multiword arithmetic/compiler lowering.

Recommendation:

No kInsn priority from this evidence.

## Current target-probing status for rotate32

The old artifact problem was real: some older discovery logs showed
`bpf_rotate64` but not `bpf_rotate32`. Current source state is different:

- `module/x86/bpf_rotate.c` defines `bpf_rotate32`.
- `bpfopt/crates/bpfopt/src/passes/rotate.rs` declares `bpf_rotate32` in
  `KINSN_TARGETS`.
- `runner/config/passes/rotate/default.yaml` requests `bpf_rotate32`.
- The local offline target used for this census included `bpf_rotate32`.

That proves the current code path expects the target, but it is still worth
checking the next live run's per-program `target.json` because target probing is
runtime BTF discovery, not just source registration.

## Priority order

1. Keep `bpf_rotate32` as the Katran jhash solution. Do not add a `jhash`
   kInsn. Use `rotate,dce` for final bytecode cleanup validation.
2. Add MOVBE x86 emission for `bpf_endian_load16/32/64`. This has both direct
   native evidence (91 `movbe`) and bytecode pass coverage (260 applied sites).
3. Design compare-select (`cmp/test + cmovcc`) as a new kInsn ABI. Current
   `cond_select` has wide coverage but cannot preserve native compare flags.
4. Investigate Tracee's 11 native `rorx` sites against Tracee live BPF bytecode.
   Current rotate pass finds 0 Tracee sites, so this is the next rotate matcher
   census, not Katran.
5. Decide LEA only from the separate native-vs-BPF LEA census. Do not infer
   `bpf_lea` ROI from native `lea` counts alone.
6. Defer BEXTR/LZCNT/TZCNT/PREFETCH. They have zero real-app direct-native
   evidence here.
7. Treat POPCNT as Tracee-only exploratory work after a bytecode-loop census.
