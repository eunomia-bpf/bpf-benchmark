# Speculative ReJIT

| Need | Start here |
| --- | --- |
| Current design and lifecycle | [design](../rejit-speculative-optimization-ebpf_idea.md) |
| Current evaluation and result paths | [evaluation](../evaluation.md) |
| Bytecode CLI and LLVM round trip | [`bpfopt/llvm/`](../../bpfopt/llvm/README.md) |
| In-process syscall shim | [`bpfopt/shim/`](../../bpfopt/shim/README.md) |
| Runner and pass policy | [`runner/`](../../runner/), [`runner/config/passes/`](../../runner/config/passes/) |
| Dated notes and step reports | [archive index](../archive/rejit/README.md) |

The corpus comparison uses two application starts: baseline, then startup
with `BPFREJIT_SHIM_LOADTIME_PLAN`. Build the CLI with
`make host-bpfopt-llvm-x86` and run the supported suites from the repository
root with `make test`, `make micro`, or `make corpus`. The default target is
local x86 KVM; `PLATFORM=aws ARCH=arm64 make corpus` selects AWS arm64.

Raw measurements remain under [`corpus/results/`](../../corpus/results/)
and [`micro/results/`](../../micro/results/). The evaluation document gives
the exact run directories for its current claims.
