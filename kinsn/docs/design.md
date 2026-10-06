# kinsn upstream RFC design

This describes the seven-patch RFC posted on 2026-10-05, **[RFC PATCH bpf-next 0/7] bpf: Inline kfuncs that have a BPF body**. The implementation lives in a separate [kernel tree and draft PR](https://github.com/yunwei37/linux/pull/3), not in this repository's prototype kernel. Sources are the [cover letter](https://lore.kernel.org/bpf/20261005142219.33451-1-yunwei356@gmail.com/) and [Documentation/bpf/kfuncs.rst at RFC revision f9352783d5011](https://github.com/yunwei37/linux/blob/f9352783d501100ba95001da7dd06bb5e0aac27d/Documentation/bpf/kfuncs.rst). The [archived hub](archive/paper-prototype-design.md) describes the paper prototype.

## A kfunc carries its BPF semantics

A kfunc set can register a `struct bpf_kfunc_body` for a kfunc:

```c
struct bpf_kfunc_body {
        const u32 *id;
        const struct bpf_insn *insns;
        u32 len;
        int (*emit)(const u8 *reg, const s32 *imm, u8 *buf);
};
```

The body computes the result in R0 from arguments in R1–R5. The set supplies its body array through `btf_kfunc_id_set.bodies` and `body_cnt`. Programs use normal kfunc calls; there is no new BPF instruction encoding or UAPI. Arguments ending in `__k` must be constants.

Registration restricts bodies to supported ALU, memory operations and forward jumps within the body, using R0–R5 and falling through the end. Argument and return types must fit a register, and these kfuncs cannot carry kfunc flags. Registration also rejects constant arguments wider than the emitter's 32-bit immediate interface.

## The verifier checks every call through the body

Before program analysis, eligible calls become their BPF bodies. Ordinary verifier analysis therefore sees the computation and derives result bounds and memory effects at each call site. Program-type kfunc permissions still apply. Only arguments are readable on entry; R1–R5 become unreadable afterwards, as with a normal call.

After analysis, an eligible call is restored if native code is available. Its operands are bound to the registers supplying arguments and receiving the result, allowing surrounding moves to disappear. The verified body remains when constant blinding is enabled, later verifier rewrites such as speculation barriers prevent restoration, or memory kinds are unsupported. JIT KASAN also prevents native replacement of bodies accessing non-stack memory. Verification costs include analyzing each body, rather than treating the call as opaque.

## Native execution and body execution

The generic x86 JIT first asks the optional `emit` callback for machine code. `reg[i]` identifies the native register bound to Ri; `imm[i]` supplies constant arguments. An emitter may use non-argument registers among R1–R5 and must emit at most `BPF_KFUNC_INLINE_MAX` bytes, returning a length or an error.

Without an emitter, or when it cannot emit for the CPU, the x86 JIT tries copying the compiled C kfunc and renaming registers. The copy path accepts a restricted straight-line subset of moves, ALU and address computations; it excludes division and RIP-relative addressing and checks implicit-register constraints. If neither path applies, the verified BPF body executes. Native implementations are trusted kernel code and must match the body's result and memory accesses. The RFC has no arm64 native implementation; arm64 runs the bodies.

## Instruction kfunc module

`kernel/bpf/insn_kfuncs/` contains seven example kfuncs: `bpf_rol64`, `bpf_select64`, `bpf_extract64`, `bpf_load_be64`, `bpf_prefetch`, `bpf_copy16`, and `bpf_lea64`. `CONFIG_BPF_INSN_KFUNCS` is tristate: built in or `bpf_insn_kfuncs.ko`. The common C file owns the functions, bodies and registration; `x86/insn_kfuncs.h` supplies five static emitters under `CONFIG_BPF_INSN_KFUNCS_ARCH`. The verifier and JIT contain no dispatch table of these specific operations.

The separate [paper prototype](../README.md#paper-prototype) uses descriptors and sidecar payloads. Its selector, modules, Lean proofs and measurements are historical artifact components, not evidence that this RFC implementation has been measured by the repository's corpus runs.
