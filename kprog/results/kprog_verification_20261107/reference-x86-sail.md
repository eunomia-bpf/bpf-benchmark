# Canonical x86 reference and ACL2-derived Sail

The280-form memory/control cohort records3360 comparisons against a fixed
reference executable:3060 complete sampled states and data-byte access traces
agree,252 inputs stop at Sail instruction coverage, and48 REP MOVS inputs differ.
Together with the retained141-form register epoch, selected observations cover
50 agreeing numeric operations,14 model-stopped operations and one differing
operation. Their source epochs remain separate in the JSON. The existing coverage
ledger preserves hardware replay identities independently.

Observations include all16 GPRs, defined flags, PC and512 supplied memory bytes;
model byte-write logs reconstruct the resulting image. Every agreeing current
input also has the exact canonical data-byte read/write trace. Branches, stack
loads/stores, calls/returns, unaligned scalar memory and all16 memory CMOV/SETCC
conditions are represented. Inputs retain the mapped initialized application
profile, CR4=512 and CET-disabled assumptions. SIMD and missing Sail instruction
bodies remain explicit model interfaces.

The48 REP inputs retain their actual difference. Sail exposes one string element
per printed state; the canonical step executes the full instruction. For ZF-clear
inputs the raw Sail traces also continue past RCX=0 at the original RIP and wrap
the counter until its existing10000-step driver endpoint. The pinned
`model/string.sail` F3 branch supplies the counter/ZF/IP behavior. The canonical
REP implementation separately passes the existing1120-case CPU cohort,64 CPU
restart faults and1774 full-state transitions. Direct ACL2 execution is the next
model comparison; the Sail observations stay in the report.

The first collector stopped when a concurrent ARM build replaced its shared
reference executable. Original inputs and ENOENT diagnostics remain archived.
The entire domain was repeated against one immutable private executable, with
source/binary identities preserved. Its exact binary is retained once in the
Arm ASL archive; the JSON gives that entry and SHA256. This archive retains all
assembler/ELF inputs, model outputs, structured reference observations, scripts,
source pins and CPU-component records. Reproduce the existing register comparison
with `formal/tools/compare_sail_x86.py`; archived memory/control inputs use the
same upstream model and canonical JSON interface.
