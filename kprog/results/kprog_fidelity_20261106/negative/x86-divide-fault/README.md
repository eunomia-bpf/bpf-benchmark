# x86 native division faults: load-only safety findings

The production generation-bound path accepts all eight native programs which
raise #DE: zero divisor and quotient overflow at each of8,16,32,64 bits.
Each accepted artifact has one nonzero-generation sidecar. The programs were
loaded only; no unsafe native instruction stream was executed.

`outcomes.json` records every assembly, exact rejection/load message and program
ID. All25 fixtures ran:9 accepted (the8 new DIV faults plus the prior stack-base
flags finding),9 verifier rejections,6 specialization rejections and1 loader
rejection. This is an open safety defect. The canonical arithmetic owner is
repairing native fault semantics; decoder rejection alone is not closure.

Commands from the repository root, host CPUs16-19:

```sh
make -C kprog/results/kprog_fidelity_20261106/negative/x86-divide-fault build
make -C kprog/fidelity bound-probe-build
make -C kprog/results/kprog_fidelity_20261106/negative/x86-divide-fault run
```

The final Make exits nonzero because it correctly surfaces accepted unsafe
programs. `inputs-source.tar.gz` freezes native/proof bytes, generated sources
and the exact simulator/generator dependency snapshot. `loader-rebuild.log.gz`
records the matching probe rebuild and guest result. The preceding stale-probe
binding seal errors are retained separately in `../x86-divide-fault-first/`;
they are infrastructure failures and do not count as safety rejections.
