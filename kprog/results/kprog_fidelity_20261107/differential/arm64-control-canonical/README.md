# AArch64 control composites versus the canonical native step

All 99,328 fresh QEMU CPU states agree with both the saved production C
simulator and V's canonical native-byte decoder/step. The matrix contains
97 run rows and 95 distinct assembly forms: the original generator repeats
the full-width `sp` and `x30` spill at offset 0. Each row has 1,024 cases;
those two forms therefore have 2,048 cases each. `unique-forms.tsv` gives
counts by distinct assembly, while `forms.tsv` and `reference-forms.tsv`
preserve every original matrix row.

| Comparison | Matrix rows | Distinct forms | Cases | Differences |
| --- | ---: | ---: | ---: | ---: |
| QEMU CPU versus C simulator | 97 | 95 | 99,328 | 0 |
| Same CPU states versus canonical reference | 97 | 95 | 99,328 | 0 |
| C simulator versus canonical reference | 97 | 95 | 99,328 | 0 |

This covers conditional branches in both directions, compare/bit branches,
finite indirect BR, BL/BLR, RET X30/RET X17, nested calls with stack-saved LR,
scalar/pair stack accesses, SP round trips, SP/LR flag observations, narrow
SP numeric reads and every tested spill byte width/offset. Comparisons
include X0..X30, actual SP normalized to the saved wrapper base, NZCV, V0,
all 64 observed stack bytes and 256 external-memory bytes. Other SIMD
registers are outside this observer's measured state. All memory writes
within the observed byte windows are compared through resulting bytes.

`arm64_reference_path.py` adds only serialization/sequencing. The existing
ReferenceMain wire accepts four native bytes per AArch64 request. The adapter
fetches that word from the observed program using the PC returned by the
canonical step, passes the returned architectural state into the next
request, and stops at the actual outer observation boundary. It does not
interpret branch conditions, instructions, addresses or register effects.
Out-of-range or repeated PCs fail this finite acyclic fixture runner; no
native instruction, production simulator or verifier program gets a fuel
guard. Faults, wrong final PC/state, changed cell identities/permissions or
initialization fail comparison. Canonical memory events are accumulated and
retained with every mismatch. There are no mismatches in this run.

Canonical source revision is e80346047, whose existing ReferenceMain and
AArch64 decoder/step are unchanged. Its frozen source and executable are
archived here; the temporary reference source/cache export was deleted.
This is an executable differential check, not a new whole-program theorem
or a claim that the existing x86 native_path wire accepts ARM paths.

The static CPU observer is byte-identical to the 1998ee4fc numeric-control
handoff. Its original combined source/header provenance is retained in
`../..`'s older date directory, specifically:
`kprog/results/kprog_fidelity_20261106/differential/arm64-numeric/source-inputs.tar.gz`.
The source and executable hashes are in `source-pins.json`. It includes the
then-unused A helper-context changes described by that older result; this
run is not presented as a freshly rebuilt current production simulator.
All inputs here were newly generated under QEMU user mode, Cortex-A72;
no deleted old raw trace was reused. QEMU evidence is distinct from actual
ARM hardware evidence, which remains a coordinator/A handoff.

Commands through bws.sh from `/workspaces/repository`:

```sh
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261107/differential/arm64-control-canonical cpu reference
```

The recipe uses a new `fresh-run/` output directory. On ARM hardware,
`OUT=/absolute/new-directory sh run-hardware.sh` executes the archived static
observer and saves a full trace/metadata. Copy that output to the x86
Workspace to run `make frozen reference OUT=/copied/output`; the archived
canonical executable is an x86 host executable. No ARM compiler is needed
for the static handoff.

Source/build/CPU/reference stages exit 0. `run.log.gz` retains all per-row
progress, and `SHA256SUMS` covers retained artifacts. Per coordinator disk
instruction the completed raw trace is deleted after summary publication
and a no-reader check; its hash/size remain in `trace-retention.json`.
A future invocation produces a new run, whose native addresses can differ.
