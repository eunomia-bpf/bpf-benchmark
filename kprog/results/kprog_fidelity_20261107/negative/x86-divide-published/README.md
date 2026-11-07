# Final published x86 DIV bound acceptance checks

Proof artifacts were rebuilt from exact published production revision
`a689ff8d69cf3e640f2c14046a2336263a61b162`, using the producer archive in
[../../differential/x86-divide-published/](../../differential/x86-divide-published/).
Runtime kernel/module/loader/linker hashes are in `runtime-provenance.txt`.
No shared kernel, module or runtime image was rebuilt.

The permanent 25-program load-only suite gives:

| Outcome | Programs |
| --- | ---: |
| Verifier rejects | 17 |
| Specialization rejects | 6 |
| Loader rejects | 1 |
| Accepted safety finding | 1 |

All eight DIV fault fixtures (zero divisor and quotient overflow at
8/16/32/64 bits) are verifier-rejected. Their exact inputs and verifier
messages remain in `outcomes.json`, per-case manifests/logs and
`inputs-source.tar.gz`. The sole accepted finding is still
`stack_base_flags`; C owns the production SP repair. The suite's exit status
2 records that real remaining finding. No accepted unsafe program was run.
Earlier accepted DIV artifacts remain in the 20261106 result directory.

Eight valid controls pass both nonzero-generation bound admission and actual
native execution, each checking quotient and remainder before returning 2
with packet result 0. All four widths have a zero-high-dividend control;
the other controls use AX=512 at 8 bits, and high=1/low=6 at 16/32/64 bits.
The divisor is 7. `positive/outcomes.json` and its eight logs retain the
source-BPF/native return values, loader generation and execution checks.
These controls prevent a blanket rejection of all DIV from passing the test.

The first positive build mixed the test helper's live-root import with the
frozen producer root and failed before any guest run. Its log/exit are
retained under `first-build-error/`. The corrected helper imports the frozen
test dependencies consistently; final build=0, negative=2 (the SP finding),
positive=0. No production code was changed by this replay.

Commands through bws.sh from `/workspaces/repository`:

```sh
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261107/negative/x86-divide-published build positive-build
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261107/negative/x86-divide-published run
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261107/negative/x86-divide-published positive-kvm
```

The two guest invocations use the existing x86 KVM kernel/module, 2 vCPUs
and 2 GiB, and execute sequentially on the inherited CPU16-19 affinity.
