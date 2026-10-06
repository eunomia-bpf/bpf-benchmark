# kinsn: verified inline kfuncs

| Need | Start here |
| --- | --- |
| Current design | [design.md](design.md) |
| Current results and artifact paths | [evaluation.md](evaluation.md) |
| Userspace selector and pass implementation | [`bpfopt/llvm/`](../../bpfopt/llvm/README.md) and [pass policy](../../runner/config/passes/) |
| x86 and arm64 modules | [`kinsn/module/`](../module/) |
| Earlier mechanisms and experiments | [archive index](archive/README.md) |

The kernel RFC is maintained in a separate kernel tree. This repository holds
the userspace selector, module sources, policy, and benchmark integration.
From the repository root, `make host-kinsn-x86` builds the x86 modules after the
kernel build dependency; `make host-bpfopt-llvm-x86` builds the selector.
Use `make test`, `make micro`, or `make corpus` for supported checks and
measurements. AWS arm64 uses `PLATFORM=aws ARCH=arm64 make test` and the
corresponding `micro` or `corpus` target.

Raw results remain under [`micro/results/`](../../micro/results/) and
[`corpus/results/`](../../corpus/results/). The evaluation document identifies
the exact runs used in its tables and figures.
