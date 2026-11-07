# Immutable replay inputs for the central verification table

These files supply the hardware/QEMU replay column of V's central
kprog/results/kprog_verification_20261107/coverage.tsv. The central table
owns the operation and specialization-token taxonomy and the formal statuses.
This input set connects sampled replay observations to their actual source
epochs, binaries and canonical references.

| Numeric C token catalog | Tokens | Sampled three-way replay | Explicit-monitor observation | Replay pending |
| --- | ---: | ---: | ---: | ---: |
| x86 | 75 | 66 | 0 | 9 |
| AArch64 | 71 | 65 | 1 | 5 |

The numeric catalogs come directly from the committed x86_sim.h and
arm64_sim.h definitions. Five x86 width aliases point to existing tokens.
The requested 77/72 operation domain also needs V's semantic/control-family
alignment; numeric tokens, native instruction families and specialization
tokens each retain their own identities.

replay-observations.tsv contains 219 operation/source rows from fifteen published
snapshots. Each row records form counts, case counts, three comparison
counts, backend, compiled simulator header, binary and reference hashes,
and original per-form table paths. Both forms tables are joined by their
exact assembly names and checked for equal case counts and zero differences.
numeric-token-input.tsv lists all 146 numeric tokens, including the pending
replay entries, with their supporting source paths. inputs.json pins all
72 source artifacts used by the collector and records the aliases.

The main x86 snapshot covers 1,144 forms and 1,171,456 real-CPU/C/reference
states with header 4fe6817. The later focused RORX snapshot covers four
forms and 4,096 states with header 47fb5565. Four additional numeric-token
bindings contribute 32 raw/direct route/form groups and 32,768 real-CPU/
C/reference states with that header and memory header 3ba4bc78. Each source
keeps its own epoch, binding scope and counts.
The later production source epoch adds1,144 forms and292,864 real-CPU/
C/reference observations with main header6b3f3173 and tagged-write headercf27e323.
Its compiled90-file archive contains82 source snapshots matching launch commit
be2bbfbb exactly. The executable is5188ecdedc827345a010d08d837a2aabf92870f9ddf5660d9d9f7130131fe1f7;
the canonical executable remainsc110b03a. The published result01ce447e records
zero differences in all three comparisons.

That production epoch preserves its initial283,136 canonical cases and38 pending
branch/CALL forms, followed by the existing --control-paths saved-state replay
of9,728 cases. The initial command's exit2 and the control completion's exit0
remain explicit. The collector verifies the initial archive, exact38-row
replacement,1106 retained rows, table/binary/trace hashes and the original
reference-reader source. Eleven additional artifact pins record this complete
source and interface history. All157 preceding operation/source rows and61
artifact pins retain their values; the existing numeric-token totals remain66
x86 and65 ARM plus one explicit-monitor observation. The added62 operation/source
rows describe the adopted production epoch and preserve each token's domain.

Two CL double-shift snapshots add 96 raw/direct groups and 98,304 real-CPU/
C/reference observations. The 32/64-bit snapshot covers all effective counts;
the 16-bit snapshot samples its defined count domain 0–16. Both retain RCX/RSP
source and destination alias cases, production encoding and header 47fb5565.
Their scope labels and original per-form tables preserve those input domains.
The LEA matrix adds 768 raw/direct groups, 384 native forms and 196,608
real-CPU/C/reference observations. Its original compiler epoch retains main
header 47fb5565, 80 production snapshot sources and two exact V-corrected
producer/offset sources. The collector verifies the archived 72 C headers
against production afc178f46, paired encoded fields and the published
384-field/384-direct-statement correspondence report. This finite production
interface bridge has its own scope and all eight source/observation artifact
pins; later header 6b3f3173 retains its separate source epoch. The LEA token
already has replay evidence, so the catalog totals retain their values.

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

Closed raw state streams use lossless cpu-states.bin.zst storage. Restore a
selected trace with zstd -d before an existing command that reads cpu-states.bin.
The collector consumes the published summaries, tables and source archives
directly. The private ARM numeric/contract and x86 partial-register storage candidates
retain their owner integration boundaries and separately published observations.
