# SIMD ownership and indirect-branch integration

S11, 2026-11-09. These are implementation proposals for coordinator selection.
The cost figures below are instruction/storage accounting and engineering
estimates. Throughput and latency remain measurement tasks for the frozen R
recipe. The current change implements context dispatch, tail frames and flags.

## Item 7: SIMD state ownership

A benign x86 fixture containing `pxor xmm0,xmm0; mov eax,2; ret` survives both
trusted native-link stages with the PXOR bytes retained. The native emitters
copy those bytes into JIT text. The x86 and ARM emitters currently supply the
ordinary GPR wrapper; the kernel SIMD ownership protocol remains an integration
target. This fixture exercises emission and supplies evidence about that
boundary. Kernel task-state isolation requires its own execution evidence.

The recommended general-hook route lowers supported SIMD operations in the
trusted native linker to scalar operations on a private virtual register bank.
The generic transform preserves every supported operation and its protected-read
fault arm. The bank entry initialization and scalarized effects carry a universal B/native
correspondence proof. Storage costs
are 16 bytes for the modeled x86 XMM0, or 512 bytes for all 32 ARM V registers,
plus the transform's GPR spill slots. An ARM Q load needs two 64-bit load lanes
and two bank stores; a Q copy needs two lane loads and two lane stores. Register
liveness can reduce that storage after the initial implementation. Programs
using scalar instructions retain their present bytes. The compiler can also
emit scalar P directly with x86 SSE disabled or ARM `-mgeneral-regs-only` before
submission; the trusted generic transform supplies coverage for every submitted
supported SIMD operation. Engineering estimate: 2-4 days per ISA for the current
SIMD subset, plus 2-4 days for shared universal link-refinement and paired tests.

An alternative uses the kernel FPU protocol around vector regions, with a scalar
route for invocation contexts where the kernel API grants scalar execution.
The x86 route requires `irq_fpu_usable()` and
`kernel_fpu_begin_mask()`/`kernel_fpu_end()`; ARM requires `may_use_simd()` and the
actual tree's `kernel_neon_begin(struct user_fpsimd_state *)`/`kernel_neon_end()`.
Nested hooks, hard IRQ/NMI, helper calls, tail transfer, exceptions and sleepable
hooks all carry entry/exit ownership. This alternative adds two ownership calls
per region, ownership selection, and the kernel's dirty-state save work. SSE's
legacy image is 512 bytes; xstate features can enlarge it. ARM's 32x128-bit
register bank is 512 bytes plus FPSR/FPCR and struct alignment. A caller-owned ARM
save buffer is also required for the contexts described by the kernel API.
Engineering estimate: 3-5 days per ISA plus the scalar route. The coordinator's
decision covers any added runtime ownership selection; this lane adds the
proposal only.

Sources: repository `arch/x86/kernel/fpu/core.c:irq_fpu_usable`,
`arch/arm64/kernel/fpsimd.c:kernel_neon_begin`, and the
[Linux floating-point API](https://www.kernel.org/doc/html/v6.19-rc2/core-api/floating-point.html).
The local ARM source defines the current state-pointer API; the separate ARM32
NEON documentation describes a different architecture/API generation.

## Item 8: indirect-branch hardening

The emitted native tail fixture ends in `ff e1` (`jmp rcx`). Stock x86 emission
selects ITS, LFENCE, retpoline, call-depth and return-thunk paths in
`arch/x86/net/bpf_jit_comp.c:emit_indirect_jump/emit_return`. The stock helpers
provide the policy to reuse in native JIT relocation/expansion. The native
linker enumerates internal indirect transfers and return sites; the kernel
emitter resolves them using the active kernel policy. Entry and every reachable
indirect landing site receive ENDBR64 on x86 or the appropriate BTI class on
ARM. Universal link theorems cover target remapping, branch semantics, return
stack behavior and same-copy relocations for each expansion.

| Site | Concrete text/storage cost |
| --- | --- |
| x86 ENDBR64 landing | 4 bytes per landing |
| ARM BTI landing | 4 bytes per landing |
| x86 `ret` to rel32 return thunk | 1 to 5 bytes, growth 4 bytes per return |
| x86 two-byte register jump to rel32 thunk | 2 to 5 bytes, growth 3 bytes per site; REX forms differ by one byte |
| x86 LFENCE plus register jump | growth 3 bytes per site |
| x86 two-byte register call to rel32 call thunk | 2 to 5 bytes, growth 3 bytes per site |
| Far thunk target | a reachable island/literal and its existing relocation, with exact encoding selected by the kernel |

Kernel-policy feature selection and thunk symbols remain kernel-owned. The
linker's branch layout and readonly code-address tables are regenerated through
the existing generic relocation path. This keeps the landing sites and actual
branch targets paired across code growth. Engineering estimate: 2-4 days for
x86 policy integration, 1-3 days for ARM landing-pad/link integration, plus 2-4
days for universal transform proofs and paired IBT/BTI/retpoline guest tests.
Cycle cost depends on active mitigations, CPU and transfer frequency; R measures
that cost after coordinator selection using the existing workload definition.
