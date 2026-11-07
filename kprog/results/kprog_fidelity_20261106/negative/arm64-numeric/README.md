# Numeric entry-address safety repair

The final generation-bound AArch64 suite rejects30/30 unsafe fixtures:
16 verifier rejections,13 specialization rejections and1 loader rejection.
`final/outcomes.json` records all assemblies, stages and exact messages.
Both previously accepted `stack_base_flags` and
`entry_return_address_flags` now reach the unsafe native branch in the proof
and are rejected with `R1 invalid mem access 'scalar'`. No unsafe native
program is executed by this load-only harness.

The numeric prototype first exposed a distinct LLVM out-of-bounds erasure:
one stack negative was accepted after an invalid C array expression vanished.
`first/` retains it; `barrier/` and `final/` retain subsequent outcomes. The
identity index barrier changes no native arithmetic or access semantics and
allows the verifier to see the invalid access. All original11 negatives still
reject, along with the earlier exclusive-store/vector/ABI regressions.

Five legitimate controls remain accepted with nonzero generations:
outer-return spill/reload, stack-pointer spill/reload, paired SP/LR restore,
and byte observations of SP and LR. See
`../../differential/arm64-numeric/positive/outcomes.json`. Their first
prototype rejections are retained under `positive-first/`; successful results
establish bound admission, not native execution of these observer programs.

```sh
taskset -c 16-23 make -C kprog/fidelity negative-bound-qemu ARM_NEGATIVE_BOUND_BUILD=build-arm64/negative-numeric-final ARM_NEGATIVE_BOUND_OUT=../results/kprog_fidelity_20261106/negative/arm64-numeric/final
taskset -c 16-23 make -C kprog/results/kprog_fidelity_20261106/differential/arm64-numeric positive-build positive-run
```

`inputs-source.tar.gz` retains the final native/proof bytes, specialization
messages and frozen dependencies. Full guest consoles stay in the Workspace;
per-case messages are retained beside the JSON. The simulator repair and its
numeric/byte fidelity evidence are described in the linked differential item.
