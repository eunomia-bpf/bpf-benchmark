# Scalar data objects in a shared read-only section

2026-11-15. Linker84b895d26 extends the existing anonymous code-table span
handling to a section-symbol PC32 reference into a defined immutable data
object. The copied extent is the same object extent used for a direct symbol
reference; interior pointers keep their offset, overlapping aliases retain
the union of their containing extents. Both proof and kernel relocation paths
use the common span logic. This avoids pulling another root's code entries
into an ordinary scalar-data reference. No new selector, P/source/flag change,
kernel version or runtime image; all LTO remains on together.

The new assembly regression d68283eaf reproduces the old missing-table-base
failure. Its scalar array shares `.rodata` with an independent root's relative
code table, and references its start and interior through section symbols.
An overlapping alias exercises the containing extent. After the fix, both
roots include only64 data bytes and zero unrelated code relocations;128
actual host executions of the proof→kernel-linked code match independent
values. The complete Rust suite passes42 tests, with one existing ignored.
Normal B compilation and64 full shared-simulator cases also pass.

The same actual Tracee ELF from `../tracee-proof-survey/report.md` now produces
**172/172** service-route function proofs (previously165/172). Its native SHA
stays `b0aafb3f523ad649c630f96e5bc12a1e45342dfb8c4d7950e09f4a7519e724ef`.
All165 previously successful proof files are byte-identical; seven newly
successful functions are listed in `tracee-after/before-after.json`. All
per-function commands, resources and hashes remain. Survey2.822s. This is
proof compatibility of those bytes, not source fidelity, B or Tracee app
acceptance. No raw native/proof binary is archived here.

The existing paired publisher updates the canonical linker/base in place,
under imageEX, with no guest using it. Published CLI SHA256 is
`c500c99e40e9f757870af7663cddf7097f4cd0fa227177122ede43e0a9d0e9d1`.
Main loader4e1a3af7, bounds5236d0ea and checked compiler907b671d retain
their previous hashes; full hashes and commands are in `publish`. The kernel
and Docker runtime image were not rebuilt. There is no second linker build.

The sole-kernel stock check initially used a plain libbpf diagnostic: reference
accepted, generated B failed to resolve the private unspecified-input symbol.
That failure remains in `stock`.5c59cb00c lets the existing scheduled-table
stock client select entry names and reuses its **production** ELF relocation/
private input-map binding. In `stock-bound`, both KPROBE programs are accepted:
reference ID3 (40 xlated/39 JIT bytes), generated ID4 (376 xlated/200 JIT
bytes), private map IDs1/2. Make0, kernel7.0.0-rc2+, CPU16–17/2vCPU/2GiB,
8GiBAS/imageSH, no timing lock. This is verifier acceptance, not KPROBE
execution or checked native installation. Host execution evidence is separate.

Raw `/workspaces/kprog-raw/perf/20261115-scalar-rodata` and
`/workspaces/kprog-raw/perf/20261115-tracee-proof-survey-after` remain complete.
Reproduction uses committed `check`, `scalar-rodata-b`, `scalar-rodata-reference`,
`publish-normal-pair`, `tracee-proof-survey`, and `scalar-rodata-stock` Make
targets. KVM workflow environment/entrypoint checks were followed. This is a
functional diagnostic; no throughput, per-call, body-speed, size-ratio or paper
performance claim. Whole apps, remaining object classes, equal work and
formal obligations remain open.
