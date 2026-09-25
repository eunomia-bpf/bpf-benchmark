# Experiment 001 Plan: Retained per-step bytecode for the Cilium `map_inline` rewrite

Date: 2026-09-25T09:31:00+00:00
Phase: BUILD_AND_EVALUATE
Selected paper question: RQ2, "When Do Runtime Side Inputs Add Value?"
Source commit: 680a9e9b882e921bc8e42ed95c6babe2394180c0

## Motivation

Step 0007 established that all 3,787 optimizer-reported Cilium `map_inline`
sites in the fresh single-pass artifact referenced workdir-local metadata for a
frozen `.rodata.config` array, but it also restated the standing defect: the
older RQ2 artifacts retained no outputs and overwrote their before images, so
they could not show that any bytecode actually changed.  The quantity the
artifact lacked — retained per-step before/after bytecode — is now available.

## Paper-value admission

The paper's RQ2 rewrite claim needs at least one retained artifact in which the
optimizer's own report can be checked against the actual before/after
instruction stream, not merely against a site count.  A run started with
`KEEP_WORKDIRS=1` retains, per changed load instance, the per-step input and
output bytecode plus `report.0.json`.  That makes the rewrite's instruction
counts and applied-site totals *derived* quantities rather than declared ones.

This experiment does not re-measure throughput and does not claim per-pass
causality.  It answers exactly one question: for the changed load instances the
run reported, do the retained bytecode images agree with the reported
before/after instruction counts, and do the images actually differ?

## Input

The complete local single-pass Cilium run
`corpus/results/x86_kvm_corpus_20260925_081752_606800`, driven by

```
env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=cilium/agent \
    BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 \
    KEEP_WORKDIRS=1 make corpus -o runtime-kernel-image
```

which exited 0.  The retained, hash-bound copy is
`docs/artifacts/evidence/rq2-cilium-map-inline-retained-bytecode/`.

## Test

A read-only join: for every changed row of the retained
`details/loadtime-reports/cilium__agent.jsonl`, locate its workdir's
`input.step.0.bin` / `output.next.0.bin` / `report.0.json`.  Each bytecode file
is a raw `struct bpf_insn[]` (8 bytes per instruction), so its length must equal
`8 * insn_count_before` / `8 * insn_count_after`; and for a rewrite to have
happened the two images must differ.  The renderer recomputes these counts at
render time.

## Boundary

Single startup, `SAMPLES=1`.  A successful whole-plan `BPF_PROG_LOAD` is not
per-pass causal proof, and the run's one start pair is not a throughput
statement.  The paper's declared 4,086-site full-scale count is not merged with
the fresh 3,787.
