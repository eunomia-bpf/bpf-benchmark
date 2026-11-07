# Immutable replay inputs for the central verification table

These files supply the hardware/QEMU replay column of V's central
kprog/results/kprog_verification_20261107/coverage.tsv. The central table
owns the operation and specialization-token taxonomy and the formal statuses.
This input set connects sampled replay observations to their actual source
epochs, binaries and canonical references.

| Numeric C token catalog | Tokens | Sampled three-way replay | Explicit-monitor observation | Replay pending |
| --- | ---: | ---: | ---: | ---: |
| x86 | 75 | 62 | 0 | 13 |
| AArch64 | 71 | 65 | 1 | 5 |

The numeric catalogs come directly from the committed x86_sim.h and
arm64_sim.h definitions. Five x86 width aliases point to existing tokens.
The requested 77/72 operation domain also needs V's semantic/control-family
alignment; numeric tokens, native instruction families and specialization
tokens each retain their own identities.

replay-observations.tsv contains 148 operation/source rows from ten published
snapshots. Each row records form counts, case counts, three comparison
counts, backend, compiled simulator header, binary and reference hashes,
and original per-form table paths. Both forms tables are joined by their
exact assembly names and checked for equal case counts and zero differences.
numeric-token-input.tsv lists all 146 numeric tokens, including the pending
replay entries, with their supporting source paths. inputs.json pins all
41 source artifacts used by the collector and records the aliases.

The main x86 snapshot covers 1,144 forms and 1,171,456 real-CPU/C/reference
states with header 4fe6817. The later focused RORX snapshot covers four
forms and 4,096 states with header 47fb5565. Each keeps its source epoch.
The ARM core snapshot covers 807 forms and 826,368 QEMU/C/reference states
with header c21833de. Full-register-bank FMOV, memory and bitfield snapshots
supply their own rows and source hashes.

The two finite-control cohorts retain their X86_CONTROL and ARM64_CONTROL
labels and composite scope: 35 real-x86 forms and 101 QEMU ARM forms.
The eight exclusive observations retain their explicit monitor-input
projection scope, including 4,096 store-exclusive observations for STLXR.
Their published premise checks and original monitor-state diagnostic remain
in the linked source reports. The LEAVE64 row records 33,792 real-CPU/
canonical architectural and fault-class comparisons, with the C comparison
case fields set to zero. These scopes guide the central table's integration.

All ARM rows describe QEMU user execution. The prepared static ARM artifacts
remain available for the coordinator's hardware replay. Samples and source
epochs support ISA fidelity; the formal lanes develop universal handler,
dispatcher, specialization, native-link and binding laws.

Recompute from the repository root:

~~~sh
python3 kprog/results/kprog_fidelity_20261107/differential/replay-inputs/collect.py
~~~

The collector verifies every consumed artifact against the captured Git HEAD,
reconciles table rows and compiled-header archives, and writes the replay
inputs. It reuses existing immutable observations. Warm CPU executables,
canonical binaries, original raw traces and other lanes' jobs remain available.
