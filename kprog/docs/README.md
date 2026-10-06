# kprog

kprog studies native whole-program execution with an eBPF program that models
the native instruction stream for verifier analysis. The current simulator and
proof artifacts cover the workload-derived x86-64 and AArch64 subsets; they do
not establish fidelity for either complete ISA.

| Need | Start here |
| --- | --- |
| Design and trust boundary | [design.md](design.md) |
| Evaluation, results, and raw artifact manifest | [evaluation.md](evaluation.md) |
| Simulator and native loader code | [`kprog/`](../README.md), including `x86/`, `arm64/`, `formal/`, `loader/`, and `libnativeloader/` |
| Current paper | `docs/kprog-simulator-in-ebpf/` (submodule; initialize it to read the paper) |
| Older plans and experiment notes | [archive index](archive/README.md) |

From the repository root, build the x86 proof object with
`make -C kprog/x86 build` and the AArch64 proof object with
`make -C kprog/arm64 build`. Check the Lean contracts and host cross-checks
with `make -C kprog/formal check`. Run the repository's VM-backed smoke
and benchmark entrypoints with `make selftest`, `make micro`, and `make corpus`
(set `PLATFORM=aws ARCH=arm64` for AWS AArch64). The architecture-specific
READMEs under `kprog/` describe their direct smoke targets.

The result summary and exact dataset paths are in [evaluation.md](evaluation.md).
Raw run artifacts remain under `micro/results/` and `corpus/results/`; local
simulator proof records remain under `kprog/x86/results/` and
`kprog/arm64/results/`.
