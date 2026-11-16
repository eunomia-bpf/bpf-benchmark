# Tetragon `cel_expr_N`: how upstream creates them, and the native form

Run that exposed it: `corpus/results/x86_kvm_corpus_20261116_082630_165122`,
arm `post_rejit`, program `generic_kprobe_` (3634 instructions).
Shim log line 1082: `Error: x86 helper tail branch cel_expr_0 has no helper address`.
Todo item: P1j-d19.

## What the eight symbols are

`vendor/bpf/tetragon/bpf/process/cel_expr.h:8` says it plainly: "The code for
the cel_expr_N functions will be generated and linked when the policy is
loaded". The header only declares `cel_expr_0` .. `cel_expr_7` (one
`int cel_expr_N(long *argsoff, char *args)` each, under `__LARGE_BPF_PROG` &&
(`GENERIC_KPROBE` || `GENERIC_UPROBE`)), and calls them from the switch in the
static `cel_expr(int id, long *argsoff, char *args)` at lines 23-45.

Confirmed in the app's own object,
`…/snapshots/3167/fs/artifacts/tetragon/bpf_generic_kprobe_v61.o`: all eight
are undefined `U`, with exactly one `R_BPF_64_32` relocation into `.text` per
case (41 `R_BPF_64_32` in the object overall). **No object in the image defines
any of them.**

## How upstream makes them

Both halves are userspace, at policy-load time.

1. **Emit BPF instructions from the CEL expression.** `pkg/celbpf/celbpf.go`
   parses with cel-go, type-checks, and `newCompiler(...).compile()` returns
   `asm.Instructions`. `CompileEmptyFunction` emits the two-instruction
   `r0 = 0; exit`; `CompileFn` pins the name with
   `btf.WithFuncMetadata(insns[0].WithSymbol(fnTy.Name), fnTy)` — a symbol name
   plus `btf.StaticFunc` metadata on the body's first instruction.
   `MaxCelExprFunctions = 8` and `CelExprFuncName(i) = fmt.Sprintf("cel_expr_%d", i)`
   (`pkg/selectors/celexpr.go:20-31`) match the header's eight exactly.

2. **Fill all eight slots and append them to the program spec.**
   `CelExprFunctions.functions()` (`celexpr.go`) puts the compiled body in each
   slot that has an expression and `CompileEmptyFunction` in every remaining
   one, with the upstream comment "this is needed, because otherwise loading
   will fail due to unresolved symbols". `RewriteProg` then appends all eight
   bodies to `prog.Instructions`. If `celbpf.Supported()` is false it instead
   runs `removeCelFunction`, deleting `cel_expr` from the bytecode and replacing
   each `call cel_expr` with `r0 = 0`. `Supported()` is
   `bpf.DetectMixBpfAndTailCalls()`.

3. **Hook it to the one program that calls them.** `pkg/sensors/tracing/generickprobe.go`,
   in both the single-kprobe and kprobe-multi loaders:

   ```go
   rewriteProg := make(map[string]func(prog *ebpf.ProgramSpec) error)
   if entry := gk.loadArgs.selectors.entry; entry != nil {
       if celbpf.EnabledInBPF() {
           rewriteProg["generic_kprobe_filter_arg"] = entry.CelExprFunctions().RewriteProg
       }
   }
   load.RewriteProg = rewriteProg
   ```

   Keyed on the program name `generic_kprobe_filter_arg` — the same entry our
   linker proves.

So the bytes the kernel verifies for `generic_kprobe_` are
`bpf_generic_kprobe_v61.o` **plus eight function bodies that exist only in the
Go process's memory**. Nothing on disk and nothing in the ELF contains them.

## Why the native path fails

The linker's input is the manifest's `*.native.o`
(`options.native_object_path` → `load_or_link_native_blob` → `--input`), i.e.
the compiled ELF. In `generic_kprobe_filter_arg`'s reachable set it sees
`cel_expr` (114 bytes, proven) branching to eight symbols the object declares
but does not define.

The linker already has the right rule for this. In
`x86_direct_tail_transfers` (`kprog/x86/native_lab/native_link/src/x86.rs:466`)
a tail branch's callee is resolved through the relocation:
`resolve_x86_plt32_defined_target_addr` returns `Some` only when the target
symbol has a section, i.e. is **defined in this object**. Only then is
`defined: Some(callee)` set, and only a defined callee gets the direct-branch
patch (`PatchKind::DirectBranch`). An undefined callee falls to
`runtime_call_target(...)` and is treated as a **kernel helper address** —
which is what the error reports:

    x86 helper tail branch cel_expr_0 has no helper address

That is the whole bug: eight application functions, defined at runtime, are
being classified as helper calls. Nothing about the IR embedding or the
producer is involved — the same eight undefined symbols and relocations are
present identically in the pre-IR object.

## The form that fits the design

The lane rule is that the native side is untouched upstream source and flags,
and after that only the linker changes things. The generated bodies are neither
source we may edit nor bytes in the ELF, so they must arrive as an input.

**The shim already captures exactly this program.** `dump_bytecode`
(`bpfopt/shim/shim_state.h:419`) writes the post-rewrite `struct bpf_insn[]`
that the kernel actually verifies — which contains `cel_expr` *and* all eight
generated bodies, because `RewriteProg` ran before `BPF_PROG_LOAD`. The shim
also retains the capture attr (`load_attr`) and `func_info_buf`, and func_info
is precisely the function-boundary table: one record per function giving its
instruction offset and BTF type id (with the name on the `btf.Func`).

So the minimal form is:

1. **Persist the function table beside the captured bytecode.** The shim already
   dumps `octets` per program; write the `func_info` records alongside (offset,
   btf id, rec size, count). The BTF is the program's own `prog_btf_fd`, already
   referenced by the capture.
2. **Let native-link accept a supplementary object.** When a reachable tail
   branch target has no definition in the primary object, look it up in the
   supplementary one and take `defined: Some(callee)` from there. The existing
   `defined` path then emits `PatchKind::DirectBranch` and proves it like any
   other symbol — no new patch kind, no new helper concept, no name heuristics.
   The residual "no helper address" error then means only what it says: a
   genuinely external callee.
3. **Report which symbols came from the supplement**, so a reader can tell a
   generated body from an object-defined one.

Why not the alternatives:

- **Empty stubs (`r0 = 0; exit`) for all eight** would satisfy the linker and is
  what upstream does for unused slots — but when a CEL expression *is* in use,
  the stub compiles in place of the real expression and silently changes filter
  behavior. It is correct only where the capture shows the slot is empty;
  taking the body from the capture is both simpler and always right.
- **Editing the app source or the header** is barred by the lane rule, and would
  also have to reproduce Go-generated code.
- **Treating `cel_expr_N` as helpers** is what happens today, and a helper
  address does not exist for them.

This is a narrower statement than "P1j-d19 generated-function provider gap": the
provider already exists in the shim's capture. What is missing is (a) the
function table on disk, and (b) the linker's fallback lookup. Both are additive
and touch no producer, flag, or app source.

## Separate observation

The same run shows `PROG_LOAD -> fd=-1 errno=28` for the 3634-instruction
program before the linker error. `errno=28` is ENOSPC, which for
`BPF_PROG_LOAD` is the verifier's instruction/complexity limit, not the linker
failing. Since the linker error leaves the original fd in place, the two are
independent and the ENOSPC should be read on its own once the provider exists.

## Evidence

- Header: `vendor/bpf/tetragon/bpf/process/cel_expr.h:8`, lines 17-45.
- App object: `/var/lib/docker/containerd/.../snapshots/3167/fs/artifacts/tetragon/bpf_generic_kprobe_v61.o`
  — eight `U` symbols, eight `R_BPF_64_32` relocations into `.text`.
- Failure: `corpus/results/x86_kvm_corpus_20261116_082630_165122/details/shim-logs/tetragon__observer.post_rejit.log:1082`
  and `:1109`; reachable-symbol list at lines 1067-1081.
- Linker rule: `kprog/x86/native_lab/native_link/src/x86.rs:466-527`
  (`x86_direct_tail_transfers`), `:311-333`
  (`resolve_x86_plt32_defined_target_addr`), `:1187-1199` (the error site).
- Capture: `bpfopt/shim/shim_state.h:419` (`dump_bytecode`), `:31`
  (`bytecode_path`), `:55-65` (`func_info` retention).
- Upstream at `main`, read 2026-11-16: `pkg/celbpf/celbpf.go`,
  `pkg/selectors/celexpr.go`, `pkg/sensors/tracing/generickprobe.go`.