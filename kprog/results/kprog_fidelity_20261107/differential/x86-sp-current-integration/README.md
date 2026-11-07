# Current-source x86 stack representation integration

The production simulator now keeps full native-width stack offsets, projects
stack aliases to native numeric bits for scalar operations, preserves origins
through full MOV/CMOV/XCHG, and performs address formation with unsigned64
modular arithmetic. The latter removes the UBSan-reported null-relative pointer
addition without inserting bounds checks, traps, fuel or fallback. Existing C
byte-ladder changes and other lanes' runtime edits were preserved.

| Replay | Forms | Cases | CPU/C differences | CPU/canonical differences |
| --- | ---: | ---: | ---: | ---: |
| Before CMOV writeback correction | 47 | 48,128 | 3,072 | 0 |
| Corrected current source | 47 | 48,128 | 0 | 0 |
| Corrected source with UBSan | 47 | 48,128 | 0 | not separately replayed |

The original40 sequences remain; seven CMOV stack-alias/source/destination/self
controls were added. Each form has1,024 deterministic random inputs, all GPRs,
flags and modeled memory compared. Per-form counts, original counterexamples,
native byte lists and reference outcomes are in the three replay subdirectories.
`cmov-before/inputs.tar.gz` retains the pre-correction source; source hashes pin
the current runtime and the existing routing checks. Zero-case lists are empty,
not omitted failures. Source generation and replay commands are in
`cmov_fixed.sh` and `check_sanitized.sh`.

The first focused50 existing route programs all passed after their fixture
models were converted from raw private pointer cells to independent native
geometry. The selected dependent Lean build passed. The full canonical
`make -C kprog/formal check` then failed at a separately named
`cmov_step_route_host.c`:30,192 comparisons still used the old raw-cell model.
Its original full log is retained in `full-before-cmov-model.log.gz`. The same
unfiltered grid now passes9,585,138 checks after the representation bridge was
applied there, including the existing untaken-memory-fault controls. This is an
oracle representation correction, not a change to the canonical ISA reference.

Commands (repository root, CPUs16-23):

```sh
bash kprog/results/kprog_fidelity_20261107/differential/x86-sp-current-integration/cmov_fixed.sh
bash kprog/results/kprog_fidelity_20261107/differential/x86-sp-current-integration/check_sanitized.sh
python3 kprog/results/kprog_fidelity_20261107/differential/x86-sp-current-integration/check_full.py
```

A replacement51-route check and whole formal check are detached, reusing the
shared incremental build and Lake caches, and waiting for an existing FULL
check to finish. `full.exit` and source-pins are their completion receipts; a
whole-check pass is not claimed here. The native-only trusted-service negative
suite is separate under `negative/x86-trusted-sp`; it has not yet established
zero accepted on the new service path. Earlier private-path negative results
remain historical evidence. BIOSNOOP's scalar/private-stack pointer projection
verifier rejection reported by C remains an integration issue, not hidden by
these CPU successes. No whole-program fidelity or safety closure is claimed.
