# Exclusive status-register overlap source validation

Four constrained-unpredictable native encodings loaded through the real
generation-bound path before this repair, with one chunk and generation1:

| Native instruction | Before program ID | After |
| --- | ---: | --- |
| `stxr w1,x1,[x2]` | 8 | specialization rejects |
| `stlxr w1,w1,[x2]` | 16 | specialization rejects |
| `stxr w2,x1,[x2]` | 24 | specialization rejects |
| `stlxr w2,w1,[x2]` | 32 | specialization rejects |
| `stxr wzr,x1,[x2]` | 40 | accepted control, ID8/generation1 |
| `stlxr w0,xzr,[sp]` | 48 | accepted control, ID16/generation1 |

The fixtures allocate/initialize stack memory, define every consumed register,
and return safely after the exclusive instruction. They are load-only; none
was executed natively. Arm DDI0602 STXR/STLXR shared decode permits undefined
instruction and NOP outcomes when status aliases data, or status aliases a
non-SP base. A discarded result cannot eliminate the possible instruction fault.

The production ABI checker now rejects exactly those architectural register
aliases. W/X views share identity; SP/ZR do not. For example:

```text
constrained-unpredictable native exclusive status register overlap at 0x10: stxr w1, x1, [x2]
```

Every exact before/after native input and message is retained in the respective
`outcomes.json`. No runtime guard, arbitrary status value, instruction semantics
change or exclusion of valid exclusives is introduced. The separate four unsafe
failure-branch findings remain open; this increment repairs invalid encodings.

The permanent29-case Arm suite now has9 verifier rejections,13 specialization
rejections,1 loader rejection and6 accepted safety findings. Those six remain
the four exclusive-store failure branches and two numeric SP/LR observations.
All11 original negatives reject. The suite exits1 for findings, with zero
infrastructure errors. All40 existing ABI regressions pass, and the negative
proof plus all29 workload-derived positive proofs rebuild.

The first full-suite attempt exposed a stale test adapter: A's current generator
requires the actual original map declaration, while the old F adapter expected
an auto-generated `neg_map_0` then renamed it. The adapter now supplies the
unchanged `negative_companion.bpf.c` prelude through the existing API. Both map
negatives again reach their real verifier errors. No synthetic map, original
workload, launcher or loader was changed. The stale attempt remains in
`original-prelude-adapter-attempt.tar.gz`, separately from the final safety run.

```sh
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-exclusive-overlap build run
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-exclusive-overlap PHASE=after build run
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-exclusive-overlap full-build full-run
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/negative/arm64-sp-alignment check BUILD=/workspaces/repository/kprog/fidelity/build-arm64/exclusive-overlap-bound/after
taskset -c 16-19 make -C kprog/arm64 micro-proofs-build PROOF_BUILD_DIR=build/fidelity-exclusive-overlap/micro-proofs NEGATIVE_NATIVE_BUILD_DIR=build/fidelity-exclusive-overlap/negative-native MICRO_SIM_PROOF_ARGS='--jobs 1'
```

The before command describes the saved old source closure; do not remove the
production fix to reproduce it. Both guests use cortex-a57,2vCPUs/2GiB and
the matched assets deduplicated in `../arm64-sp-alignment/artifacts.tar.gz`.
`artifacts.tar.gz` restores exact before/after source closures, native/proof
inputs,29-case permanent suite and40 ABI checks under
`kprog/fidelity/build-arm64/exclusive-overlap-bound/`. `raw-logs.tar.gz` retains
every guest/per-case log; compressed Make logs retain commands and outcomes.
No shared kernel/module/image was rebuilt.
