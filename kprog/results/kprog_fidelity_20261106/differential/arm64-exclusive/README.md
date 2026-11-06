# Exclusive-store CPU fidelity finding

The expanded production-encoder matrix executes8 actual forms ×1024 states
under QEMU:8192 cases, **4096 mismatches**. All four W/X STXR/STLXR rows differ
in every case: the CPU returns status1 and performs no write; C returns status0
and writes the source word. An explicit CLREX immediately before the observed
native PC establishes an empty local monitor. CLREX is observer setup, outside
the recorded STXR/STLXR byte span. Every mismatch retains all GPR/NZCV/vector
and memory inputs plus native/C outputs in `mismatches.jsonl.gz`.

| Form | Cases | Mismatches |
| --- | ---: | ---: |
| LDXR W | 1024 | 0 |
| LDAXR W | 1024 | 0 |
| STXR W | 1024 | 1024 |
| STLXR W | 1024 | 1024 |
| LDXR X | 1024 | 0 |
| LDAXR X | 1024 | 0 |
| STXR X | 1024 | 1024 |
| STLXR X | 1024 | 1024 |

The load rows compare GPR/flags/vector/memory only; zero differences there
does not establish monitor updates or acquire ordering, which the old observer
state does not encode. This is a newly exposed gap in the former567-form Arm
matrix: production already accepts these opcodes, but that matrix omitted them.
The audit is expanding every production family rather than treating that
denominator as complete ISA coverage.

Arm's primary STXR/STLXR pseudocode sets status1 initially, checks the exclusive
monitors, and writes only on success; LDXR/LDAXR establish monitor state.
CLREX clears the local monitor. See Arm DDI0602, STXR pages982–983 and shared
exclusive pseudocode pages5439–5440, in the already downloaded primary manual
`/workspaces/.agent-state/kprog-lanes/V/arm-a64.txt`. The
[Arm synchronization guide](https://documentation-service.arm.com/static/5efa1989dbdee951c1ccdea1)
also explains that store-exclusive status depends on monitor success.

The defect is safety-relevant: `../../negative/arm64-exclusive/README.md`
records four actual generation-bound accepted programs whose failure branch
dereferences NULL. Unsafe native programs are never executed. Those programs
cover both unpaired and paired exclusive sequences; a matching load does not
justify deleting the possible store-failure branch. The finding remains open
until production semantics, explicit monitor/environment state, ordering,
canonical refinement and the real bound negatives are repaired together.
Replacing constant0 with constant1, using a random helper, or excluding all
exclusive programs would not establish native fidelity.

```sh
taskset -c 16-23 prlimit --as=12884901888 -- make -C kprog/fidelity -f bank32.mk run-qemu BUILD=build-arm64-exclusive FAMILY=exclusive OUT=../results/kprog_fidelity_20261106/differential/arm64-exclusive
```

The command exits1 for the preserved mismatches. It initializes and compares
all31 GPRs, SP, NZCV, all32 independent vectors and memory. `forms.tsv` retains
every row. `harness-artifacts.tar.gz` restores exact production headers/imports,
generated C/native assembly and static binary under
`kprog/fidelity/build-arm64-exclusive/`. `coverage.json` in that archive records
the CLREX initial-monitor premise for each form. `native-code.json` records
the actual instruction byte spans. No production simulator file is changed
by this evidence increment. The static hardware handoff is
`../cpu-differential-arm64-exclusive.gz`, using `ARM64_HANDOFF` with the existing
`kprog/fidelity/run-arm64.sh`. Hardware execution is a separate required replay;
this result is functional QEMU evidence and makes no timing claim.
