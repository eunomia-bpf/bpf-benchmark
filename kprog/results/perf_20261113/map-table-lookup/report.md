# Map-table helper consumer through normal B

2026-11-15; source `3d834a0e4`. The same fixture C is compiled directly to
x86 with the unified native flags and to BPF as the reference. Its single
KPROBE context selects one of eight ARRAY maps; a real numeric helper-1
lookup returns a value, and the root returns a scalar. Native code contains
eight anonymous RELRO map-pointer slots. Production linker functions produce
the proof and kernel image; normal B compilation uses bounds/context/strict
identity lowering and whole-word MIR spills.

Normal B compilation **passes**. Actual native image and full shared simulator
agree in **128 host cases**: four sets of map values, all sixteen indices,
and present/missing values. The host model observes exactly one lookup for
indices 0–7 and none for the default arm. Native execution uses normal ARRAY
LTO with the boot layout; unused generic-helper slots bind to a trap so an
unexpected helper dispatch cannot silently pass. Missing-value host cases
set max_entries to zero; these are boundary fixtures, not the submitted
source maps, whose captured shape remains max_entries=1. No native generic
helper execution is claimed by this host subset.

The Rust subset passes **35 tests**, with one existing ignored test. The
first attempt expected a named ELF helper relocation; libbpf's actual
numeric ABI remains `mov eax,1; call rax`. The corrected test checks those
actual proof bytes. Both attempts and the final compile logs are retained.

Generated B SHA256:
`7a098f989b6b6f325f0fe538f411758bd7919fce3ee2d72bb969ff2193c612c0`.
Raw commands/results: `/workspaces/kprog-raw/perf/20261115-map-table-lookup`.
One canonical build: `/var/tmp/kprog-tmp/perf/map-table-lookup`.
`collect.py` retains the input hashes, native/proof disassembly, commands,
logs and host cases; no compiled copies are committed.

Registered kernel replay **818147 is queued**, after the normal paired-base
publisher 783752, then image SH, CPUs 16–17, 2 vCPUs/4 GiB and 16 GiB AS cap.
It uses the existing source-object resource setup and registered verify/load
path, including the actual eight map capabilities and captured context.
Read `kernel/replay/result.json` for stock_accepted and checked_installed;
this report does not claim either before those results exist. No new guest,
kernel/image/base publication, application run or performance measurement
occurred during the source/host step. Formal and actual application table
acceptance remain open.
