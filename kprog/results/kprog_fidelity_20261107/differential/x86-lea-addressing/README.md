# Expanded LEA hardware addressing coverage: original failures

The existing CPU matrix adds 69 LEA forms: 16/32/64-bit destinations and
extended registers, all SIB scales, displacement boundaries, no-base
absolute displacement, address-size32, destination aliases and ignored FS/GS.
All source/native instructions and exact production dependencies are frozen
in `observer-source.tar.gz`; the static CPU binary is retained separately.

| Observation | Forms | Cases | Differences |
| --- | ---: | ---: | ---: |
| Entire CPU/C matrix | 885 | 906,240 | 20,480 |
| LEA CPU/reference | 73 | 74,752 | 0 |
| LEA C/reference | 73 | 74,752 | 11,264 |
| Newly added forms, CPU/C | 69 | 70,656 | 10,240 |

Ten newly exposed non-SP forms each differ on all 1,024 states:

- Absolute `[0x12345678]` into AX/EAX/RAX/R8W/R8D/R8: GNU objdump prints
  `ds:0x12345678` without brackets; `parse_mem_terms` returns displacement0.
- Address-size32 `[ebx+ecx*4-7]` or `[r8d+r9d*8+127]` into RAX/R8: the
  encoder discards address-register width and leaves the upper32 address
  bits instead of zero-extending the native 32-bit address.

The other59 new forms agree. The extra1,024 LEA C/reference differences are
the existing `lea rax,[rsp+16]` SP numeric bug. The full matrix's remaining
10,240 differences are its ten previously reported SP rows. No mismatch is
waived or turned into an unsupported-form rejection.

`forms.tsv` gives every CPU/C row; `reference-forms.tsv` gives all73 LEA rows.
Every mismatch's inputs, native/C/reference state and memory are retained in
the two compressed JSONL files. `cpu-states.bin` keeps all906,240 states in
the Workspace, with its hash in `trace-provenance.txt`.

Canonical revision8480a34f137fca66a4b9041a7e3978f22fe5ba90, executable and
source archive are published in the sibling `x86-lea-published/` result.
LEA reference replay passes no memory cells and requires no memory events,
matching all architectural registers, six flags, XMM0 and unchanged memory.
No second instruction semantics is implemented by the F harness.

Commands through bws.sh from `/workspaces/repository`:

```sh
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261107/differential/x86-lea-addressing build cpu
taskset -c 20-23 make -C kprog/results/kprog_fidelity_20261107/differential/x86-lea-addressing reference
```

This directory records the failing producer snapshot. Rebuilding against a
later fixed working tree is a different experiment; the original archived
binary/dependencies and raw observations remain immutable here.
