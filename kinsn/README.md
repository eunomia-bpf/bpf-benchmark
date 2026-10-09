# kinsn: verified inline kfuncs

kinsn has two parts: the current upstream RFC in a separate kernel tree, and the paper prototype preserved in this repository.

## Upstream RFC

The draft [kernel PR](https://github.com/yunwei37/linux/pull/3) implements kfuncs with a verified BPF body and optional native emit callback. It was posted to `bpf@vger.kernel.org` on 2026-10-05 as **[RFC PATCH bpf-next 0/7] bpf: Inline kfuncs that have a BPF body** ([cover letter](https://lore.kernel.org/bpf/20261005142219.33451-1-yunwei356@gmail.com/)). See the [current design](docs/design.md) for the interface, verifier and JIT behavior. The RFC is not the kernel implementation vendored by this artifact.

## Paper prototype

The prototype backs the paper *BPF-Ext: Safely Extending the eBPF Compilation Pipeline with Native Operations* and its earlier naming. Its components are:

- [Kernel modules](module/) for x86 and arm64 and [Lean proofs](lean/README.md).
- [Target prober](kinsnprober/) and [LLVM/bytecode selector](../bpfopt/llvm/README.md), with policies in [runner/config/passes/](../runner/config/passes/).
- [ATC'26 paper data, plots, and provenance](paper/atc26/README.md): `make -C kinsn/paper/atc26` regenerates the local paper bundle and its discrepancy report.
- [Evaluation](docs/evaluation.md), [project notes](docs/README.md), and indexed raw [corpus](../corpus/results/README.md), [micro](../micro/results/README.md), and [test](../tests/results/README.md) results.
- [Archived paper-prototype design](docs/archive/paper-prototype-design.md) and [historical notes](docs/archive/).

Builds and runs use the repository [Make entrypoints](../README.md#running-benchmarks); module build targets are `make host-kinsn-x86` and `make host-kinsn-arm64`. The shared optimizer remains a pure bytecode CLI. Historical prototype measurements do not evaluate the October RFC.

## Renames

`Kops`, `KOperation`, and `kop` → `kinsn` (with `KINSN`/`Kinsn` casing in identifiers); `kopprober` → `kinsnprober`; `nokop` → `nokinsn`. [docs/MOVED.md](../docs/MOVED.md) records the old and new paths, including result directories. Earlier paper names and immutable external references remain recognizable there.

The LLVM fork is now [`eunomia-bpf/bpf-kinsn-llvm`](https://github.com/eunomia-bpf/bpf-kinsn-llvm); GitHub redirects its earlier `bpf-kop-llvm` URL.
