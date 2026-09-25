# BUILD_AND_EVALUATE Step 0008 Report

Date: 2026-09-25
Experiment: retain per-step before/after bytecode for the Cilium `map_inline` rewrite
Result: supported; the rewrite now reconciles against retained bytecode on a single startup

## Source ownership and experiment selection

Step 0007's next action was a clean Make-backed single-pass run with
`KEEP_WORKDIRS=1`, which its own step report deferred while the AE-owned
optimizer source and the other sessions held the tree.  That run was executed
this step:

```
env PLATFORM=kvm ARCH=x86 BPFREJIT_CORPUS_APPS=cilium/agent \
    BPFREJIT_BENCH_PASSES=map_inline SAMPLES=1 WORKLOAD_DURATION=30 \
    KEEP_WORKDIRS=1 make corpus -o runtime-kernel-image
```

with the standard `RUSTUP_HOME`/`CARGO_HOME`/`PATH`/`CLANG` and `VMLINUX_BTF`
exports, at source commit `680a9e9b88`.  It exited 0 after ~290 s inside the
guest.  Only `runner/config/passes/**` policy was exercised; no frozen workload,
app runner, `corpus/driver.py`, benchmark Makefile, or launch wiring changed.

The motivating gap is unchanged from step 0005/0007: the older RQ2 artifacts
retained no outputs and overwrote their before images, so the optimizer's
reported site count had no retained before/after bytecode behind it.  The
`KEEP_WORKDIRS=1` run supplies exactly that stream for every changed load
instance.

## Valid result

The retained report stream
(`details/loadtime-reports/cilium__agent.jsonl`) holds 169 rows: 122 changed
load instances and 47 unchanged, 3,787 applied sites, instruction counts
159,896 → 111,826 (−48,070).  The run's `metadata.status` is `completed`; the
Cilium app record is `status: ok` with an empty `error`.

For all 122 changed workdirs the retained per-step `input.step.0.bin` /
`output.next.0.bin` images are raw `struct bpf_insn[]` arrays whose lengths
equal `8 * insn_count_before` / `8 * insn_count_after`, and all 122 before/after
pairs differ byte-for-byte: zero length mismatches, zero identical images.  The
post-phase shim log is a third independent stream — exactly 122
`loadtime optimized prog=… insns=BEFORE->AFTER` lines, zero failure lines, whose
summed 154,340 → 106,270 matches the changed rows' summed reported counts (the
report stream's 159,896 → 111,826 covers all 169 rows including the 47
unchanged programs).

An independent auditor
(`analysis/audit_loadtime_evidence.py --app cilium/agent --expected-pass
map_inline ...`) reports `outcome: supported` with
`integrity_errors.total = 0`, the same 122/3,787/−48,070 values, and
`input_matches_reported_before = mutable_input_matches_reported_after =
output_matches_reported_after = retained_output_next_0 = 122`.

The evidence is shipped hash-bound at
`docs/artifacts/evidence/rq2-cilium-map-inline-retained-bytecode/`:
`receipt.json` binds the command, source commit, normalized `make-corpus.log`,
the report stream, and the per-step bytecode for the 122 changed workdirs by
SHA256 (376 files, all verified).  `docs/artifacts/render_claim_table.py` gained
a derived row (`RQ2 Cilium retained map_inline bytecode (3787 sites)`) that
recomputes the counts and both reconciliations at render time; it reads `PASS`,
and a mutation test on the derived instruction accumulation made the renderer's
`--self-test` fail, proving the derivation is load-bearing.

## Scientific boundary and next action

This is a rewrite-reconciliation result, not per-pass throughput causality: the
run applied a single pass at load time and compared one start pair
(`SAMPLES=1`, 30 s, one startup).  A successful whole-plan `BPF_PROG_LOAD` is
not per-pass causal proof, and the fresh 3,787-site count is reported beside —
never merged with — the paper's declared 4,086-site full-scale count, which
retained no per-step bytecode.  The run's `provenance/start.json` records the
command and source revision but is hand-authored, not Makefile-generated.

With retained before/after bytecode now available, the previously open
"does the rewrite actually change bytecode" question is answered for one
startup.  The remaining runnable RQ1 mechanism question is the applied-site
attribution already shipped (directly attached callers vs tail-call descendants)
and the proof line's next AArch64 items; both stay outside this step's scope.
