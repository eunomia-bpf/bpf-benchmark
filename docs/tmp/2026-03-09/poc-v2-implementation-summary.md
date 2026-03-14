# Kernel JIT Directive POC v2: `cmov_select`

## Why v1 was wrong

POC v1 implemented the visible optimization as a verifier-stage BPF bytecode rewrite. It replaced a byte-load/shift/OR ladder with a different BPF instruction sequence before JIT lowering. That is not a backend optimization:

- the transformed BPF program was different from the original program;
- userspace bytecode optimizers could have done the same rewrite;
- the x86 JIT itself was not making a meaningful target-specific code generation choice.

That breaks the intended thesis of the directive framework. A correct directive must preserve BPF semantics and BPF bytecode shape, while changing only native lowering inside the kernel JIT.

## What v2 changes

POC v2 keeps transport and policy input in userspace, but moves the optimization itself into the x86 backend:

- userspace emits a sealed-memfd directive blob attached to `BPF_PROG_LOAD`;
- the kernel parses that blob into `prog->aux->jit_directives` and fails closed on malformed input;
- the verifier only validates that a requested site is a legal narrow `cmov_select` region and records the validated site;
- the x86 JIT consumes that validated site in `do_jit()` and emits `cmp/test + mov + cmovcc` instead of the branch-based native sequence.

The BPF instruction stream is not rewritten for this directive. The optimization is now a true JIT emission choice.

## Invariant

The key v2 invariant is:

- `xlated_prog_len` should remain unchanged with and without directives;
- `jited_prog_len` may change because only native code generation changes.

If `xlated_prog_len` changes, the implementation has fallen back into verifier-level rewriting and is no longer a valid JIT-level POC.

## Current positive case

The current positive case is `micro/programs/cmov_select.bpf.c`. To force a genuinely narrow select region in the loaded BPF program, the benchmark now uses a dedicated helper subprog:

- `cmov_select_pick(lhs, rhs, on_true, on_false)`

On current clang/BPF codegen this helper lowers to a compact narrow select shape:

```text
mov dst, default
jcc +1
mov dst, override
```

The kernel-side validator and the x86 JIT still support the canonical four-insn diamond form, but they also accept this compact local select shape because that is what the current benchmark actually emits. The important property is unchanged: the kernel does not rewrite BPF; it only changes x86 lowering at the validated site.

At the moment, `directive_hint` finds:

- `cmov_select.bpf.o`: 1 directive site
- `binary_search.bpf.o`: 0 directive sites
- `switch_dispatch.bpf.o`: 0 directive sites

That is expected for the current narrow matcher. `binary_search` and `switch_dispatch` still serve as control/real-world cases, but they may not contain a legal narrow pure-assignment select region under current clang lowering.

## Build

Kernel:

```bash
cd vendor/linux
make -j"$(nproc)"
```

Userspace:

```bash
cd /home/yunwei37/workspace/bpf-benchmark
make -C micro
make -C micro directive_hint
```

## Validation flow

Use the validation script:

```bash
python3 docs/tmp/run_poc_v2_validation.py
```

The script is expected to:

- generate directive blobs with `micro/build/tools/directive_hint`;
- run `micro/build/runner/micro_exec` in three modes:
  - normal libbpf loader baseline;
  - manual loader without directives;
  - manual loader with directives;
- record `xlated_prog_len`, `jited_prog_len`, `compile_ns`, `exec_ns`, and directive counts.

The same-loader manual no-directive run matters because it isolates directive impact from loader-path differences.

Run that script inside a booted `jit-directive-poc-v2` kernel or an equivalent VM using the built
`vendor/linux/arch/x86/boot/bzImage`. Running it on an unrelated host kernel is still useful for
smoke-testing blob generation and loader-path plumbing, but it will not validate the kernel-side
directive behavior.

## Current local status

On the current development host:

- `vendor/linux` built successfully through `arch/x86/boot/bzImage`;
- `make -C micro programs micro_exec directive_hint` succeeded;
- `directive_hint` currently reports `1` directive for `cmov_select` and `0` for
  `binary_search` / `switch_dispatch`;
- host-side `run_poc_v2_validation.py` completed structurally, but the running host kernel rejected
  BPF load/map creation with `EPERM`, so no final runtime numbers were collected yet.

## Expected results

For `cmov_select`:

- directive count should be non-zero;
- `xlated_prog_len` should match baseline exactly;
- `jited_prog_len` should shrink or at least differ only in native code;
- execution time may improve if the host CPU benefits from `cmovcc`.

For `binary_search` and `switch_dispatch`:

- directive count may be zero with the current narrow matcher;
- if zero, `xlated_prog_len`, `jited_prog_len`, and timing should match the no-directive controls;
- this is still a valid result, because it shows the framework is fail-closed and does not rewrite BPF to manufacture opportunities.
