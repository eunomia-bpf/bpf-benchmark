# Complete staged-object x86 projection compile census

RUNNING. This is a generation/compile regression census of all1136 staged
proof objects from six applications after the XDP context repair18aef1f0c.
It is not the actual application-loaded program denominator, verifier
acceptance, native runtime coverage, matching work, or timing. None of those
unmeasured stages is counted as passing. Native-only runtime evidence is
separately recorded in ../trusted-service-bcc-set/ and ../xdp-context-identity/.

The existing app smoke runner visits every inventory entry with --keep-going;
failures and timeouts remain failures with raw commands in commands.jsonl.
The existing runner defaults are unchanged. No application is filtered.
Original staged inputs and source hashes are pinned in inventory.json and
source-pins.json. Generated files/build outputs live only in lane C state.

Command from repository root:

```
taskset -c 16-19 make -C kprog/x86 app-proofs-build APP_SIM_PROOF_ARGS="--report-dir /workspaces/repository/corpus/results/kprog_app_coverage_20261107/xdp-context-census --output-dir /workspaces/.agent-state/kprog-lanes/C/context-census --build-dir /workspaces/.agent-state/kprog-lanes/C/context-census-build"
```

A completion summary/table is generated after the runner exits. Do not stage
or commit active logs or generated directories while it is running.

## Closed generation/compile results

| App | Staged | Generated | Generation failed | Compiled | Compile failed |
|---|---:|---:|---:|---:|---:|
|bcc|34|33|1|19|14|
|cilium|82|66|16|4|62|
|katran|6|5|1|2|3|
|otelcol-ebpf-profiler|30|30|0|12|18|
|tetragon|809|130|679|102|28|
|tracee|175|119|56|59|60|

Source pins unchanged: True. Verifier/runtime acceptance remains unmeasured.

## Closed generation/compile results

| App | Staged | Generated | Generation failed | Compiled | Compile failed |
|---|---:|---:|---:|---:|---:|
|bcc|34|33|1|19|14|
|cilium|82|66|16|4|62|
|katran|6|5|1|2|3|
|otelcol-ebpf-profiler|30|30|0|12|18|
|tetragon|809|130|679|102|28|
|tracee|175|119|56|59|60|

Source pins unchanged: True. Verifier/runtime acceptance remains unmeasured.


Closure receipt: all1136 generation rows and all383 resulting compile rows
are complete. Source pins were checked at closure BEFORE the later canonical
header repair. commands.jsonl.gz preserves the full commands byte-for-byte;
raw-results.tar.gz preserves sources, staged native proof inputs,198 compiled
objects, the frozen repository include snapshot and driver log. System include
hashes were recorded at closure; a complete start-time include snapshot was
not available. The198 objects have no compiler .comment version section.
This forced-XDP staged-object scan measures generation/compilation only. It
is not the application-loaded program denominator, actual attach-ABI coverage,
verifier acceptance, bound execution or a completed six-application result.
