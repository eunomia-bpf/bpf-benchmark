# AGENTS.md

Repository-level constraints for coding agents working in this tree.

## Build And Test Boundaries

- Use `make <target>` as the canonical build/test entry point.
- Keep the root `Makefile` thin; directory-specific logic belongs in that directory's own `Makefile`.
- Host-side compilation is allowed, but kernel/BPF runtime actions must happen in the VM.
- Do not run kernel-related tests, load modules, load BPF programs, or use `bpftool` against the host kernel.
- Debugging, static verification, and correctness-focused VM test runs may use multiple agents and multiple VMs in parallel when they do not share mutable build state.
- Performance benchmarks (`vm-micro`, `vm-corpus`, `vm-e2e`, or any timing/perf-counter run) must not run in parallel with other performance benchmarks.

## Test Ownership

- Repo-owned tests live under `tests/` and are built by `tests/*/Makefile`.
- Upstream kernel selftests and selftest kmods stay in `vendor/linux-framework/tools/testing/selftests/**`.
- Do not copy upstream kernel selftests into `tests/`.
- Do not patch upstream kernel testcase sources just to make this repo pass; fix kernel code, config, or repo-owned orchestration instead.

## Toolchain Consistency

- Prefer repo/source-tree headers over host kernel headers.
- Keep LLVM tool selection consistent inside one pipeline.
- Do not mix one `clang` version with a different default `llvm-config`/LLVM disassembler version for upstream selftests.

## Git Branch Safety

- Never change the checked-out branch in this repository.
- Do not use `git switch` or `git checkout` to move to another branch, even for inspection.
- If a branch ref must be updated, move the ref without switching branches.

## Code Change Scope

- Delete v1 and dead code when v2 replaces it.
- Avoid unrelated kernel churn when fixing test failures.
- Keep kernel diffs minimal and directly tied to REJIT/kinsn/v2 behavior.

## Error Handling (Zero Silent Failure Policy)

- **Every error must be visible.** No `unwrap_or_default()`, `.ok()`, `except: pass`, `let _ = result`, or any pattern that silently swallows errors.
- **No `compile_only` or skip-by-default.** Every corpus program must either run and produce a measurement, or fail with a clear error message explaining why. Do not annotate programs as "compile only" to hide runtime failures.
- **Errors must propagate, not degrade.** If a map FD lookup fails, the apply must abort — not continue with a broken program. If an E2E case fails, the suite must report failure — not mask it as "skipped".
- **No fallback behavior.** If a configuration or dependency is missing, fail loudly. Do not silently fall back to defaults that change the meaning of the benchmark.

## Security Passes (Out of Scope)

- Security-related passes (`speculation_barrier`, `dangerous_helper_firewall`, `live_patch`) are **not in the current OSDI evaluation scope**.
- Do not include them in `benchmark_config.yaml`, default pipeline, or any benchmark run.
- Code for these passes should be removed from the daemon default pipeline. Standalone pass implementations may be retained for future work but must not be registered or enabled by default.
