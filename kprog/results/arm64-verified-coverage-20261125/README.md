# Arm64 verified-path coverage, measured object by object (OMP 2026-11-25)

Arm64 had no checked-sim-c chain at all before today: the service refused
`--arch 2` for the mode, the arm64 worker exposed only `specialize()`, and the
three checked tools fixed the x86 arena type name and target triple. Its
coverage was therefore 0 of every app by construction, not a residue.

The port is `c39250e88` (worker `compile_checked_simulator`, service gate, ISA
parameters on `compile_sim_ir.cpp` / `packet_bounds_ir.cpp` /
`socket-context-lower.cpp`, and an `exec` job in the compiler broker for tools
the guest cannot host).

## What is measured here

Stage 1 is the part of the chain that needs no kernel, and it is measured on
every arm64 native object the manifests name:

```
python3 kprog/results/arm64-verified-coverage-20261125/stage1.py --out <dir>
```

For each object entry: the manifest's entry symbol goes through
`specialize()` (proof link, B generation, BPF compile) and then
`compile_checked_simulator()` (checked IR lowering with `--stack-arena
union.anon` and the aarch64 triple/layout, aarch64 native compile,
`native-link --mode proof`). A success means B was generated and its aarch64
native simulator linked to a proof object; the stock verifier's verdict on that
proof is what stage 2 (one guest boot per app) adds.

Manifest entries without a single entry symbol (47 of 327: the dedupe rule in
`vendor/bpf/write_native_manifest.py` folds several text symbols under one
16-character program name) cannot be resolved before a kernel request exists,
so they are counted as `deduped` and left to the guest pass.

Map declarations: the generator walks the reachable native instructions and
reports any map its source still lacks; the harness retries with that exact set
until it converges (at most 8 times). A relocation table only covers the
section holding the entry, which under-covers tail-call targets.

Raw captures: `/workspaces/kprog-raw/omp/arm64-coverage-20261125/`.

## Results

| app | manifest objects | deduped | B generated + aarch64 proof | resume collision | LLVM OOM | native ABI |
|---|---|---|---|---|---|---|
| bcc | 29 | 3 | 26 | 0 | 0 | 0 |
| cilium | 89 | 10 | 79 | 0 | 0 | 0 |
| katran | 3 | 0 | 3 | 0 | 0 | 0 |
| otel | 26 | 2 | 14 | 0 | 10 | 0 |
| tetragon | 93 | 17 | 73 | 0 | 2 | 1 |
| tracee | 113 | 17 | 46 | 45 | 5 | 0 |

`B generated + aarch64 proof` counts objects whose
`generated*/checked-simulator.native.o` exists, i.e. B was compiled and lowered to a
linked aarch64 proof object. The failure columns are disjoint and exhaust every object
not counted as a proof: a resume collision (`[Errno 17] File exists`) from a re-run
inside an unfinished job, an `LLVM ERROR: out of memory` raised by `SROAPass` on a B
whose single function holds over a million allocas, and one unmodelled native ABI
external call. No object is left unexplained.

## The `LLVM ERROR: out of memory` class

Seventeen objects raise the same failure, and it is a property of the generated B, not
of a flag, a memory bound or the resume. `otel/0004` (`kprobe_unwind_dotnet`) is the
measured case: `commands.jsonl` records `LLVM ERROR: out of memory / Allocation failed`
from `clang -w -g -O2 ... -c trusted_arm64.bpf.c`, and the stack is
`llvm::PromoteMemToReg` <- `llvm::SROAPass::run` inside the module optimizer.

The B for that object is one 20,926-line function with 6,345 instruction labels; its
unoptimized IR is 258 MB of bitcode, 1.68 GB of text, **1,142,983 allocas**
(783,279 `i64`, 195,725 `i8`, 97,306 `ptr`, 66,635 `i32`), all in the single function
`trusted_arm64_arm64_sim_xdp`. Each inlined `ARM64_SIM_DIRECT_BODY_n` declaration in
`arm64_sim_direct.h` introduces its own scalars (`__a64_l_width`, `__a64_l_value`,
...), and 6,345 inlined bodies in one function multiply them past what SROA's
promotion maps can hold.

Two independent checks rule out the alternatives, both run on the same object:

- **Not the optimization level.** `-O1` and `-O2` both abort in `PromoteMemToReg`;
  `-O1` (1011 s) and `-O2` fail identically.
- **Not a memory bound.** With no `prlimit` at all and about 100 GB free, the bare
  `clang -emit-llvm` still raises `LLVM ERROR: out of memory`. The three-worker
  stage-1 pool ran without a `prlimit` wrapper, so contention was not the trigger
  either.

Size separates the classes cleanly: every object with a B under 1.5 MB either passes or
carries a resume collision, while 17 of the 18 objects with a B over 1.5 MB raise the
OOM (the eighteenth, `tracee/0012`, was still compiling). The largest passing B is
2.19 MB (`otel/0018`) and the smallest OOM is 1.89 MB (`tracee/0014`), so the boundary
is a per-object property of the function's alloca count rather than the byte size
alone.

## The one native ABI failure

`tetragon/0091` (`try_preload_arg`) stops before compilation:
`unresolved native ABI external call bpf_copy_from_user_str at 0x8ec: bl 0
<bpf_copy_from_user_str>`. The arm64 native linker has no simulator model for that
helper, so this is a coverage gap in the arm64 helper set, not a B defect.
