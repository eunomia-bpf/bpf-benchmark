# P89 Division Strength Reduction Research

Date: 2026-04-30

Scope: decide whether constant-divisor `DIV`/`MOD` strength reduction should become a bpfopt pass.

## Recommendation

Status: `⏸ 后续 phase`.

Do not put this into the default Paper A / near-term bpfopt pass queue yet. The opportunity is real and the kernel does not already do it, but the current supported-app hits are almost entirely 64-bit constant division, especially Cilium `ktime_get_ns() / 1_000_000_000`. A pure bytecode lowering for 64-bit division needs 64x64-to-128 multiply-high semantics that eBPF does not expose directly, so the implementation is much more expensive than the usual native compiler shift/multiply trick.

Revisit when either:

- per-site profile shows the Cilium/BCC constant-divide sites execute at packet-rate or event-rate high enough to matter; or
- bpfopt gets an acceptable multiply-high primitive/kinsn/native lowering story, instead of emulating 128-bit multiply with many bytecode instructions and temporary registers.

## Stage 1: Corpus Census

Scanner: pyelftools over executable `SHT_PROGBITS | SHF_EXECINSTR` sections, decoding 8-byte eBPF instructions and counting:

- `BPF_ALU{,64} | BPF_DIV | BPF_K`
- `BPF_ALU{,64} | BPF_DIV | BPF_X`
- `BPF_ALU{,64} | BPF_MOD | BPF_K`
- `BPF_ALU{,64} | BPF_MOD | BPF_X`

Inputs found under `corpus/`, `runner/`, and `micro/`:

| Metric | Count |
|---|---:|
| Raw `.bpf.o` objects | 957 |
| Unique object SHA-256s | 865 |
| Executable sections | 3016 |
| Executable eBPF instructions | 2,000,277 |
| Objects with DIV/MOD | 100 |
| Parse errors | 0 |

Total raw sites:

| Opcode | K immediate | X register | Total |
|---|---:|---:|---:|
| `DIV` | 748 | 270 | 1018 |
| `MOD` | 64 | 187 | 251 |
| **Total** | **812** | **457** | **1269** |

Width/sign split:

| Class | Count |
|---|---:|
| `DIV K` 64-bit | 717 |
| `DIV K` 32-bit | 31 |
| `DIV X` 64-bit | 245 |
| `DIV X` 32-bit | 25 |
| `MOD K` 64-bit | 29 |
| `MOD K` 32-bit | 35 |
| `MOD X` 64-bit | 142 |
| `MOD X` 32-bit | 45 |
| Signed `DIV/MOD` sites | 120 |
| Unsigned `DIV/MOD` sites | 1149 |

Constant divisor distribution for K sites:

| Immediate | Count | Notes |
|---:|---:|---|
| 1,000,000,000 | 556 | Cilium/Calico time conversion dominates |
| 1000 | 66 | mostly BCC time/unit conversion |
| 100 | 30 | removed `scx` |
| 0 | 21 | linux-selftests verifier rejection cases |
| 1,000,000 | 20 | BCC/selftests/BCF |
| -1 | 20 | mostly signed-div verifier tests |
| 3 | 17 | linux-selftests |
| 2 | 17 | linux-selftests |
| -2 | 17 | linux-selftests |
| -3 | 12 | linux-selftests |
| 32749 | 8 | Cilium `MOD K` |
| 65537 | 4 | Katran |
| 1 | 4 | linux-selftests |
| 10000 | 4 | removed `scx` |

Power-of-two constants: 21 raw K sites, all in linux-selftests (`1` or `2`). Supported apps have zero power-of-two K divisors, so the easy shift-only case is not relevant for the benchmark apps.

Supported-app distribution:

| App | Total | `DIV K` | `DIV X` | `MOD K` | `MOD X` |
|---|---:|---:|---:|---:|---:|
| cilium | 589 | 553 | 2 | 8 | 26 |
| bcc | 128 | 80 | 16 | 0 | 32 |
| calico | 17 | 2 | 0 | 0 | 15 |
| katran | 4 | 2 | 0 | 2 | 0 |
| tracee | 2 | 0 | 0 | 2 | 0 |
| bpftrace | 0 | 0 | 0 | 0 | 0 |
| tetragon | 0 | 0 | 0 | 0 | 0 |
| otelcol-ebpf-profiler | 0 | 0 | 0 | 0 | 0 |
| **Supported total** | **740** | **637** | **18** | **12** | **73** |

Removed/unsupported buckets were still scanned, not filtered from the raw census: `scx` 253, linux-selftests 206, loxilb 52, `bcf-collected` 6, suricata 6, xdp-tools 6.

Supported K immediates:

| Immediate | Count |
|---:|---:|
| 1,000,000,000 | 555 |
| 1000 | 62 |
| 1,000,000 | 14 |
| 32749 | 8 |
| 65537 | 4 |
| 200 | 2 |
| 8000 | 2 |
| 10,000,000 | 2 |

The raw K count is a lower bound for constant-divisor opportunity. Some `X` sites may have verifier-known constant source registers, but the existing `ConstPropPass` only folds the whole ALU result when the destination is exact; it does not rewrite `dst /= src_const` to `dst /= imm` when `dst` is otherwise unknown.

## Stage 2: Kernel/Verifier Coverage

The kernel does not already perform general constant-divisor strength reduction for BPF programs.

Verifier findings:

- `vendor/linux-framework/kernel/bpf/verifier.c:16874` rejects `DIV/MOD K 0`.
- `vendor/linux-framework/kernel/bpf/verifier.c:23818` only patches signed `K -1` exception cases.
- `vendor/linux-framework/kernel/bpf/verifier.c:23847` only patches `X` forms to avoid divide-by-zero and signed minus-one exceptions, then leaves the original divide/mod instruction in the patched sequence.
- `vendor/linux-framework/kernel/bpf/verifier.c:24579` has a hand-written magic multiply for one verifier-generated branch-stack helper sequence (`size / 24`), but that is not a generic optimization of user BPF bytecode.

JIT findings:

- x86 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:1962` handles all `DIV/MOD` K/X forms in one case. For K it moves the immediate into `AUX_REG`, then emits hardware `div`/`idiv` at `:2002`/`:2011`.
- arm64 `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c:1335` emits `UDIV`/`SDIV` for X forms; `:1464` loads K into a temp and emits `UDIV`/`SDIV`; `MOD` uses divide plus `MSUB`.

Conclusion: implementing this in bpfopt would not be redundant with the current verifier or x86/arm64 JITs.

## Stage 3: Implementation Complexity

Existing bpfopt infra:

- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:516` and `:546` evaluate `DIV` when both operands are exact constants.
- `bpfopt/crates/bpfopt/src/passes/const_prop.rs:522` and `:552` do the same for `MOD`.
- `bpfopt/crates/bpfopt/src/passes/dce.rs` can clean up unreachable/dead definitions after const-prop, but has no division-specific behavior.

Pure bytecode lowering issues:

- `DIV K` sites already expose the immediate.
- `DIV X`/`MOD X` sites need shared const-prop/verifier exact-constant facts to prove the source register is constant and non-zero.
- 32-bit unsigned division by many constants can be lowered with a 64-bit product and shift, because a zero-extended 32-bit numerator times a 32-bit magic fits in 64 bits.
- Supported-app `DIV K` sites are all 64-bit, so the easy 32-bit path has almost no benchmark value.
- 64-bit unsigned division by arbitrary constants needs the high half of a 64x64 product. eBPF `MUL` only keeps the low 64 bits. Emulating multiply-high requires splitting into 32-bit limbs, multiple multiplications, shifts, adds, carry handling, and temporary registers or spills.
- K-form `MUL imm` is not enough for common magic constants that do not fit as a useful signed 32-bit immediate; loading a magic value often needs a temporary register and possibly `LD_IMM64`.
- `MOD K` needs the quotient plus `x - q * divisor`, so it inherits the same quotient complexity and needs to preserve the original numerator.

The practical first implementation would therefore need a real liveness/temporary-register allocator or a disciplined stack-spill strategy. That is a much larger pass than the one-line "DIV to MUL+SHR" description suggests.

## Stage 4: ROI Estimate

Per-site native hardware divide saving estimate: about 25 cycles per executed site.

Break-even intuition on a 3 GHz core:

- one replaced divide at 1 M executions/s saves about 25 M cycles/s, or roughly 0.8% of one core;
- one site needs about 1.2 M executions/s to save 1% of one 3 GHz core;
- ten hot sites at 100 k executions/s each also save about 25 M cycles/s.

The static corpus has many supported-app K sites, but hotness is uncertain:

- Cilium contributes 553 `DIV K` sites, almost all `/ 1_000_000_000`; objdump shows many are immediately after helper `call 0x5` (`bpf_ktime_get_ns`) and often feed seconds/nanoseconds formatting logic.
- BCC contributes 80 `DIV K` sites, mostly `/ 1000` and `/ 1_000_000`, in tracing/reporting tools.
- Calico, Katran, and Tracee have only small counts.

If Cilium executes these conversions on every packet, ROI could be visible. If they are trace/drop/debug/event paths, corpus geomean impact will likely be noise. Static `.bpf.o` census cannot distinguish those cases.

The implementation cost also reduces expected gain: a pure bytecode 64-bit multiply-high emulation may take enough native instructions that it no longer beats hardware `DIV` on arm64, and may only narrowly win on x86 while increasing code size and verifier/JIT work.

## Final Call

Do not mark this as `不做`: the corpus has real constant-divisor sites and neither verifier nor JIT handles them.

Do not mark this as `待实现` yet: the supported-app opportunity is dominated by the hard 64-bit case, not the simple 32-bit multiply/shift case.

Recommended status: `⏸ 后续 phase`, with the next decision gated on per-site profile for Cilium/BCC constant-divide sites or a native multiply-high/kInsn design.
