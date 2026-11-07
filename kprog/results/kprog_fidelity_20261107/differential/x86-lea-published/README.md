# Published LEA reference against saved real CPU states

Canonical reference revision: `8480a34f137fca66a4b9041a7e3978f22fe5ba90`.
All four previously undecoded LEA forms now execute in the reference on the
same immutable 1,024 CPU states per form (4,096 cases).

| Actual instruction | CPU/reference differences | Production C/reference differences |
| --- | ---: | ---: |
| lea rax, [rsp+16] | 0 | 1,024 |
| lea rsp, [rsp+16] | 0 | 0 |
| lea eax, [rdi+rbx*4-7] | 0 | 0 |
| lea rax, [rdi+rbx*4-7] | 0 | 0 |

No selected form remains undecoded. The first row is the already reported
SP numeric-materialization bug, now independently checked by the executable
reference. Every mismatch retains inputs, native/C/reference full modeled
state and memory in `reference-mismatches.jsonl.gz`. The reference agrees
with hardware; F made no production simulator change or SP waiver.

This reuses the original binary trace from the 816-form expanded CPU run:
`kprog/results/kprog_fidelity_20261106/differential/x86-high-load-cpu/cpu-states.bin`.
Its hash and the archived/static CPU binary hash are in `cpu-provenance.txt`.
The existing binary was verified byte-identical to the published gzip, and
no trace record was rewritten. The new opcode selector in the existing F
serializer seeks over other families, validates the complete source trace
layout and original record identities, and compares exactly the four LEA
rows. LEA is classified as address computation, so the reference receives no
memory cells and must return no memory events, in addition to matching every
observed memory byte. It adds no instruction execution model. `forms.tsv` retains the full
source CPU summary; `reference-forms.tsv` describes only this replay.

Together with the earlier 571-form replay, these four newly covered forms
leave 241 of the original 816 forms awaiting a reference (240 decode gaps
and the CALL composite). The combined evidence covers 575 forms/588,800
states, with zero CPU/reference differences and 10,240 C/reference SP
differences across ten rows. This is a union of the explicitly pinned fb7
and 8480 reference runs, not a claim that all forms were rerun at one revision.
The raw CPU/C sweep and its 10,240 SP differences are unchanged.

Command through bws.sh from `/workspaces/repository`:

```sh
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261107/differential/x86-lea-published reference
```

The Makefile restores the existing archived CPU binary and form metadata;
the 1.5 GB raw trace remains in its original retained result directory.
The canonical executable and full formal sources are archived here. The
reference was built with `lake build reference` from that exact revision;
temporary source/cache export was removed immediately. Exit2 records the
1,024 real SP mismatches, not an infrastructure or decoder failure. The
other x86 SP rows remain C's production work.
