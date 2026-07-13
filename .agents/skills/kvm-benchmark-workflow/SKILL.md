---
name: kvm-benchmark-workflow
description: Run or audit KVM/QEMU/virtme-ng benchmark workflows for systems research. Use when executing VM-backed benchmarks, interpreting KVM numbers for a paper, debugging local KVM benchmark setup, checking benchmark Makefile targets, or validating result provenance and baseline parity. Do not use for generic builds unrelated to VM execution, cloud-only benchmark runs, or prose-only paper review.
---

# KVM Benchmark Workflow

Use this skill when KVM or VM execution is part of the benchmark contract. The goal is to run the repository's benchmark workflow faithfully and decide whether the resulting numbers are paper-grade.

## Default Mode

Default to inline/report mode. Do not create result summaries, reports, or project-memory files unless the user explicitly asks for persistent output.

Use the argument directory if provided. If no argument is provided, use the current working directory.

## First Step

Read the repository's public benchmark contract before running commands:

- `README.md`, `CLAUDE.md`, or project docs that describe benchmark targets;
- the root `Makefile` or documented runner script;
- any benchmark-specific docs named by those files.

Project-local benchmark rules win over this skill. If the repository says all runs must go through `make <target>`, treat that as mandatory.

## Entrypoint Discipline

- Use the documented public target, usually `make <target>`, instead of directly invoking internal Python modules, Cargo binaries, Docker commands, QEMU commands, or runner components.
- Do not bypass the Makefile or runner when it owns build dependencies, VM image assembly, KVM dispatch, environment variables, or result paths.
- If no public target exists, report the missing benchmark contract and propose the smallest documented smoke command; do not invent a hidden direct runner path as the authoritative benchmark.
- Makefile edits must be minimal and local. Do not refactor target structure, add convenience aliases, or change output directories unless the user asks to fix the benchmark contract.

## KVM Environment Check

Before a run, verify only what matters for the documented target:

- `/dev/kvm` availability and permissions when local acceleration is required;
- required VM runner such as `vng`, `qemu-system-*`, or the repository's wrapper;
- host architecture, kernel/image path, CPU count, memory setting, and timeout knobs if the target exposes them;
- whether the target is local KVM, cross-arch QEMU, or a remote/cloud executor.

Do not require root blindly. Follow the repository's documented privilege model.

## Paper-Grade KVM Results

Treat KVM numbers as paper-grade when they come from the repository's authoritative benchmark target and include enough provenance:

- exact command and environment variables;
- git commit or source revision;
- benchmark target, workload, baseline/treatment policy, and sample/repetition policy;
- VM runner, kernel/image/config, CPU and memory settings, and host context;
- result path, raw logs or machine-readable result files, and post-processing command if any;
- baseline parity: baseline and treatment ran under the same VM contract unless the paper claim explicitly compares environments.

Do not dismiss results solely because they were collected under KVM. KVM is a valid paper benchmark environment when it is the controlled execution contract.

Downgrade results to smoke or diagnostic evidence when they come from one-off manual QEMU commands, direct internal binary execution, mismatched baseline/treatment environments, missing result paths, missing VM config, uncontrolled host load, or undocumented post-processing.

## Long-Run Protocol

For any batch run expected to exceed roughly 30 minutes or 20 cases, follow the Long-Run Protocol in `auto-research-orchestrator`'s `references/research-state-machine.md`: smoke one case first and verify the mechanism actually engaged, estimate total time before launching, write a progress heartbeat, stop-loss on systematic early failures, and checkpoint per-case results for resume.

## Running And Interpreting

- Prefer the repository's short validation or self-test target before a full benchmark when the state is unknown.
- If the user asks to run the benchmark, run the documented target and capture exact command, exit status, result path, and relevant log path.
- Do not delete caches, workdirs, VM images, or failure artifacts unless the user explicitly asks.
- Compare numbers only within the same benchmark contract. If KVM overhead matters, discuss it as part of scope, not as a reason to discard the result.
- No paper number should be written or strengthened without a result path and provenance.

## Output Shape

Return:

1. benchmark contract found,
2. KVM environment status,
3. command run or command to run,
4. result path and provenance,
5. paper-grade verdict: paper-grade / smoke / diagnostic / blocked,
6. next action if blocked or not paper-grade.
