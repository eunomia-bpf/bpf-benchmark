# Native DIV fault rejection after arithmetic repair

All8 previously accepted DIV8/16/32/64 zero-divisor and quotient-overflow
fixtures now reject in the actual generation-bound x86 KVM verifier path.
The native programs are loaded only; no unsafe kernel-native program runs.
Exact messages include the invalid scalar memory access on the #DE branch.

All25 permanent fixtures remain in the denominator:17 verifier rejections,
6 specialization rejections,1 loader rejection and1 accepted safety finding
(`stack_base_flags`). The nonzero suite exit preserves that remaining finding.
`outcomes.json` retains every native assembly and exact outcome. Compare
`../x86-divide-fault/` for the original8 bound accepts.

This run captures V's current production arithmetic candidate: the full
simulator/generator dependency bytes, native/proof objects and generated C are
in `inputs-source.tar.gz`. It does not imply that unpublished source was
already in HEAD. The canonical reference was published separately at
fb7c2b362; actual CPU fault/full128-bit/alias observations are a separate
supporting result under `../../differential/x86-divide-cpu/`.

```sh
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/negative/x86-divide-fault-fixed build
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/negative/x86-divide-fault-fixed run
```

`run.log.gz` retains the Make-backed build and KVM run. No rejection by a
missing canonical decoder was counted as verifier rejection.
