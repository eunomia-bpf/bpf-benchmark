# Stage2 correctness after production XDP context repair

Replay the same13 native/source objects and expected64-bit results from the
existing stage2 inputs on C18aef1f0c/86e0927e9 native-only trusted service.
The producer hash and all26 input hashes were checked before starting.
Only output-directory selection changes, preserving original request IDs and
raw archives. No workload/map contents, probe, kernel/module/loader or image
was rebuilt. This is correctness, not a timing or application result.

```sh
make -f kprog/results/kprog_fidelity_20261107/helper-map/x86-trusted-service/Makefile kvm RUN_OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/helper-map/x86-trusted-service/post-context
```

The run completed successfully: **13/13 cases pass**. Kernel and freshly bound
native executions match every exact64-bit expected result and retval2; each
load has1-3 nonzero generations. `results.csv` records every value/request ID,
`summary.json` pins sources and the original archive, and compressed outcomes
retain complete messages. All kernel/generated native objects match their
original input hashes; request source pins agree and host inputs are unchanged.
The prior14 tracked request/journal blobs remain byte-identical.

The command above is the actual completed command. A repeat requires a fresh
RUN_OUT and a byte-identical copy of the retained inputs.json.
This supplies functional correctness after the production context repair,
not a timing result; the existing R timing request remains separate.
