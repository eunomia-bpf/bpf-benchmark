2026-11-16T07:08:58Z

The pre-publication replay recipe indexes every canonical manifest candidate and pairs it with actual retained same-symbol loader plans. Implicit kernel names are truncated to15 characters, so all matching full ELF function names are expanded; these are candidate-entry counts, not program-install counts. Every captured request retains its original context and plan, including variants and retries. Missing captures stay explicit; no helper address or map shape is synthesized. The catalog names retained BCC/OTel/Cilium service archives, two completed Tetragon requests, Tracee retained service evidence and the last captured Katran balancer plan.

The inventory has475 candidate entries across six apps and88 candidates with captured plans. The BCC subset passes all34 proof extractions and25 kernel-mode emissions with real retained plans, zero failures. That is host-only linkage, with no native execution or stock-verifier claim. It does not replace the separate25/25 checked whole-app result. The full six-app replay waits for C producer G/IR fixes so the final payload can be checked together. PERF_EVENT candidates will run trusted context LTO before proof extraction; conversion failures are recorded and dependent linking does not continue. Other entries retain their P.

Commands: make -r -f kprog/test/native-corpus-replay.mk inventory OUTPUT=/workspaces/kprog-raw/perf/20261116-native-corpus-replay/inventory; make -r -f kprog/test/native-corpus-replay.mk replay APPS=bcc OUTPUT=/workspaces/kprog-raw/perf/20261116-native-corpus-replay/bcc. Final full replay omits APPS. HostCPU16/16GiBAS/imageSH, no timing lock. report.json under each raw directory retains per-entry commands, captured source locations, output and errors. All subsets are terminal and the sole base/image and original guests are unchanged. No benchmark or runtime-image definition edit.

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

2026-11-16T09:05:57Z

Current CLI + rooted embedded P replay completes all475 candidate proofs and all11 OTel PERF_EVENT conversions. Matching retained plans emit70 kernel images; six Tracee old-plan omissions remain visible. C's later actual canonical Tetragon run reaches unresolved policy-generated CEL bodies, which the two retained Tetragon requests do not cover. This replay does not claim coverage of those absent current-load facts or app installation.

| App | Candidates | Proofs passing | Kernel passing/attempted |
|---|---:|---:|---:|
| bcc | 34 | 34 | 25/25 |
| cilium | 80 | 80 | 28/28 |
| katran | 3 | 3 | 1/1 |
| otelcol-ebpf-profiler | 30 | 30 | 14/14 |
| tetragon | 154 | 154 | 2/2 |
| tracee | 174 | 174 | 0/6 |

Raw rooted-current/report.json and the committed JSON retain every command/result. Coherent publication is running at /workspaces/kprog-raw/perf/20261116-rooted-image; no new timing result yet.
