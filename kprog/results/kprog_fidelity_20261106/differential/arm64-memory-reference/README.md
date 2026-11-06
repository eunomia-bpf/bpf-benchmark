# Arm canonical memory and pair replay on identical CPU states

The saved567-form CPU trace now checks543 forms /556032 cases against V's
expanded canonical executable. **CPU versus reference: zero differences.**
Simulator versus reference:4096 differences, unchanged in the same four
SP/WSP transfers. This adds20 checked forms relative to the earlier523-form
replay, without regenerating or changing any native/simulator input state.

Newly checked forms are NOP; scaled/unscaled W/X loads/stores; byte/halfword
loads/stores; signed byte/halfword W/X loads; LDRSW; and signed-offset LDP/STP.
`reference-forms.tsv` reports every form and count. The four model rows are
`mov w0,wsp`, `mov wsp,w0`, `mov x0,sp`, `mov sp,x0`, each1024 differences.
Their actual SP anchors, full inputs, memory and reference/native/model states
remain in `reference-mismatches.jsonl.gz`.

The24 remaining encodings are still active reference work: ten bitfield-alias
forms and fourteen LDR/STR preindex/postindex/register-offset/vector forms.
Every exact encoding/request/rejection remains in
`reference-unavailable.jsonl.gz`; none is removed from the567-row denominator.
The replay exits1 for the preserved SP differences and missing decoding.

```sh
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/differential/arm64-memory-reference freeze replay
```

The replay reads `../arm64-sp-reference/cpu-states.bin` directly, without
copying the1GiB trace or rerunning QEMU. CPU/simulator data and metadata are
the frozen SP-observer run described in the parent README. The saved executable
is copied before replay, retaining its execute permissions; later shared
canonical rebuilds cannot change an in-flight comparison. The first launch
found missing execute permissions on the copied file before comparing any
case; preserving the original mode repaired that local packaging error.

`reference-snapshot.tar.gz` preserves the actual canonical executable,
executed replay adapter, CPU coverage/static binary and source archives.
The executable was frozen while the pair extension was checked but not yet
committed. `canonical-source.tar.gz` inside that snapshot is the then-committed
82b5cd46f source; `pair-source-471f5bc9e.tar.gz` additionally preserves the
subsequently published pair extension used by the executable. The freeze
recipe now captures the working canonical source closure and dirty-state
provenance as well, so future snapshots retain uncommitted extensions directly.
No clean-checkout gate is imposed. `provenance.txt` retains the original freeze
revision/time; `replay.log.gz` retains the completed command and exit status.

The replay adapter also supports an explicit frozen `--reference` executable
and a read-only `--trace` input. Its x86 flag comparison now includes PF/AF
under the reference's defined-flags mask, instead of silently projecting those
bits away. That x86 change does not alter this Arm comparison. The fresh
six-flag x86 CPU observer will use V's physical PF/AF state repair; the existing
native trace already records full CPU RFLAGS.
