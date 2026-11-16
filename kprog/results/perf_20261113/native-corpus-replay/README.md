2026-11-16T08:33:13Z

Host link replay of C's rebuilt payload (2036af0e9 / 7a1750367), using the
committed native-corpus-replay.mk and the unchanged canonical release linker.

| App | Candidate ELF entries | Proofs passing | Kernel emissions passing/attempted |
|---|---:|---:|---:|
| bcc | 34 | 34 | 25/25 |
| cilium | 80 | 80 | 39/54 |
| katran | 3 | 3 | 1/1 |
| otelcol-ebpf-profiler | 30 | 20 | 5/5 |
| tetragon | 154 | 154 | 2/2 |
| tracee | 174 | 174 | 0/6 |

These 475 candidates include full ELF symbols behind truncated manifest names;
they are not runtime installed-program counts. All candidates were attempted.
Kernel emission uses retained real requests; it is not kernel execution.

The ten genuine current-P failures are OTel perf_go_labels and perf_unwind_*
PERF_EVENT entries. They exist in the ELF and individual embedded unit modules,
but are absent from the aggregate embedded module. native_tracer_entry passes
conversion (10 loads) and proof. PERF requested C preserve the static entry
roots during LLVM aggregation. No image with this incomplete IR was published.

Fifteen initial Cilium kernel errors were test pairing errors: the replay matched
only the function name, but e.g. tail_handle_ipv4 occurs in bpf_lxc.c,
bpf_overlay.c and bpf_wireguard.c with different maps. A real captured request
has STT_FILE bpf_lxc.c; its plan cannot describe the other translation units.
The corrected replay records source-file identities, retains all same-symbol
captures and lists different-source captures separately. Its Cilium subset
passes all 80 proofs and 28 matching kernel emissions with zero failures;
26 differently sourced capture pairings remain listed. It does not skip any
candidate ELF entry or change production program selection.

Six remaining initial Tracee emissions lack the boot-kernel layout field in
the retained 11-14 plans. All 174 Tracee proofs pass. These old plans predate
the current plan schema; current layout or map addresses were not fabricated
or spliced into them. Current loader string-pool fix remains independently
covered by its own test, and actual Tracee application confirmation is open.

Raw inputs, full commands, plan data, object emissions and initial failures stay
at /workspaces/kprog-raw/perf/20261116-native-corpus-replay. This receipt does
not establish full current-P runtime correctness or measured performance.
