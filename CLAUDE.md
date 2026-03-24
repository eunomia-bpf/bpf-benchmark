# AGENTS.md

Repository-level constraints for coding agents working in this tree.

## Build And Test Boundaries

- Use `make <target>` as the canonical build/test entry point.
- Keep the root `Makefile` thin; directory-specific logic belongs in that directory's own `Makefile`.
- Host-side compilation is allowed, but kernel/BPF runtime actions must happen in the VM.
- Do not run kernel-related tests, load modules, load BPF programs, or use `bpftool` against the host kernel.

## Test Ownership

- Repo-owned tests live under `tests/` and are built by `tests/*/Makefile`.
- Upstream kernel selftests and selftest kmods stay in `vendor/linux-framework/tools/testing/selftests/**`.
- Do not copy upstream kernel selftests into `tests/`.
- Do not patch upstream kernel testcase sources just to make this repo pass; fix kernel code, config, or repo-owned orchestration instead.

## Toolchain Consistency

- Prefer repo/source-tree headers over host kernel headers.
- Keep LLVM tool selection consistent inside one pipeline.
- Do not mix one `clang` version with a different default `llvm-config`/LLVM disassembler version for upstream selftests.

## Code Change Scope

- Delete v1 and dead code when v2 replaces it.
- Avoid unrelated kernel churn when fixing test failures.
- Keep kernel diffs minimal and directly tied to REJIT/kinsn/v2 behavior.
