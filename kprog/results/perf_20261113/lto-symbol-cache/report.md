# Normal paired base: runtime-cache integration and installation

2026-11-15; fix `e1e96deff`.

The first paired publication completed after the coordinator-directed stop of
the old-route census and scale compiles. All five queued functional jobs then
failed during native loading: the boot layout writer requested
`nmi_uaccess_okay`, but the runtime's filtered kallsyms cache did not retain it.
The standalone layout resolver had read the full symbol file. Boot symbols
were present; this was a missing runtime-cache input, not a missing kernel
capability. Both registered table cases already passed stock verification and
checked compilation before their native load failed.

The loader now retains all seven boot-LTO symbol names, deduplicating names
already used by helpers. No LTO is disabled and no fallback is introduced.
Loader syntax passes. The same base was rebuilt under image EX, then all five
affected functional jobs were rerun under image SH on CPUs 16–19 with hard
memory caps. They all exit zero:

- Probe reads: 18 actual stock/native execution comparisons per submitted-native
  and checked-simulator mode.
- Maps: all 11 original kind/key cases pass in both modes; per-case execution
  rows and registered-service archives are retained.
- ARRAY: original-load resource substitution, subprogram references and mutable
  live values pass in both modes.
- Single-context code table: stock_accepted and checked_installed are true.
- Eight-map lookup-table consumer: stock_accepted and checked_installed are true;
  the kernel reply installs native program 12. This completes that fixture's
  registered acceptance, without claiming KPROBE execution or app acceptance.

Actual normal CLI SHA256:
`906f5b702febec12ccde874074f1b24718e0d3a7eaf0b8e8522ed60ab07a6393`.
Corrected trusted loader SHA256:
`4e1a3af777e8c60bc920cff4937212347224710946205a8b1de4e7064408d7a2`.
The same publication installs bounds compiler `5236d0ea...` and checked
compiler `907b671d...`; exact full hashes and source HEAD are in publication/.
The old runtime-linker symlink is gone. Kernel and image were unchanged.

Raw results: `/workspaces/kprog-raw/perf/20261115-lto-symbol-cache`.
First publication/failures remain in the preceding normal-layout-plan,
checked-codegen/kernel and map-table-lookup/kernel directories. Collection
keeps complete small execution rows, logs, reply JSON and archive hashes;
compiled products and service archives remain in their canonical/raw locations.

The coordinator's 06:06:55 notice also directed stopping census 524496/QEMU
524526 and scale 666038. Exact owned PIDs, parent/start identities and SIGTERM
records are retained. Census exits at 06:11:06 with Make status 2; scale's
worker/batch processes are stopped. These are requested cancellations. Raw
terminal rows, partial outputs and the old scale state are preserved; the old
jobs must not be restarted. New-route objects are needed for another census,
and helper-dispatch preprocessing growth is now the scale priority.

No application performance or code-size gain is inferred. Isolated Katran A/A
is running separately with the existing shim-disabled `SKIP_REJIT_MODE=all`,
two application starts, 3x180-second samples and stats on. Its output will be
reported after completion; it is not a native speedup measurement.
