# Third-party notices and vendored-dependency provenance

This repository's original material is licensed under the MIT license in
[`LICENSE`](LICENSE). The paths below are **third-party or vendored** and remain
under their own licenses, which are authoritative for those paths.

## Scope of the MIT license

The MIT license in `LICENSE` applies to the original material of this
repository: the benchmark harness (`runner/`, `corpus/`, `micro/`, `tests/`),
the `bpfopt` optimizer and shim (`bpfopt/`), the Kinsn kernel modules
(`kinsn/module/`), the formalization and simulator code (`kprog/`), and this
repository's documentation.

Third-party and vendored material is covered by its own licenses, which are
authoritative for those paths. In particular:

- `vendor/linux-framework/` — Linux kernel, GPL-2.0 (`COPYING`).
- `llvm-backend/llvm/` — LLVM, Apache-2.0 with LLVM Exceptions (`LICENSE.TXT`).
- `vendor/libbpf/` — LGPL-2.1 or BSD-2-Clause (`LICENSE`).
- `vendor/llvmbpf/` — MIT (`LICENSE`).
- `vendor/bpf/{bcc,cilium,katran,otel,tetragon,tracee}/` — the respective
  upstream application projects, each under its own license.

Nothing in this file relicenses, supersedes, or alters the terms of any
third-party component.

## Getting the submodules

Exact revisions are pinned by git submodules (`.gitmodules`). Initialize only
the public submodules that the artifact uses:

```bash
git submodule update --init --recursive -- \
    vendor/linux-framework llvm-backend/llvm vendor/libbpf vendor/llvmbpf \
    vendor/repos/bcc vendor/repos/bpftrace vendor/repos/cilium \
    vendor/repos/cilium-ebpf vendor/repos/katran \
    vendor/repos/opentelemetry-ebpf-profiler vendor/repos/tetragon \
    vendor/repos/tracee
```

Do not run a bare `git submodule update --init --recursive`. Four submodules
(`docs/paper`, `docs/kprog-simulator-in-ebpf`, `docs/speculative-optimization`,
`vendor/academic-writing-skills`) are private author repositories: fetching them
fails without access, and no documented command needs them.
`vendor/repos/deepflow` and `docs/ebpf27-bpfoptbench` are public but not used by
the artifact (deepflow's own nested submodules do not resolve).

## Git submodules (pinned revisions)

Pins as of 2026-10-12; `git ls-tree HEAD <path>` prints the pin of any
checkout.

| Path | Pinned revision | Upstream | License | Access |
|---|---|---|---|---|
| `llvm-backend/llvm` | `7f56eafab493abea1ddbbffa785fb9231964454e` | LLVM project (patched BPF backend), `eunomia-bpf/bpf-kinsn-llvm` | Apache-2.0 with LLVM Exceptions (`LICENSE.TXT`) | public |
| `vendor/linux-framework` | `24cd6e63ce912a4e220ca1cae3137ab29706551b` | Linux kernel with the Kinsn prototype, `eunomia-bpf/linux` branch `kinsn-only` | GPL-2.0 (`COPYING`) | public |
| `vendor/libbpf` | `caa25e0b72746fef7ea01497ece7db57187f132c` | libbpf | LGPL-2.1 OR BSD-2-Clause (`LICENSE`) | public |
| `vendor/llvmbpf` | `dd788ba56f1c16088f2541b56d9e5285466a8ae8` | eunomia-bpf/llvmbpf (project fork branch) | MIT (`LICENSE`) | public |
| `vendor/academic-writing-skills` | `867d61c2fd50c506b5727067186b5ee4ff120f0d` | writing skills | see submodule | private |
| `vendor/repos/bcc` | `07ca7ba9df379bf063b3b2afca6983b8d91bc2a2` | iovisor/bcc | Apache-2.0 | public |
| `vendor/repos/bpftrace` | `75aca47dd8e1d642ff31c9d3ce330e0c616e5b96` | bpftrace | Apache-2.0 | public |
| `vendor/repos/cilium` | `1b721c2964e7799cab3e18c38066905ea240fa34` | cilium/cilium | Apache-2.0 | public |
| `vendor/repos/cilium-ebpf` | `88256f7afc6f895e6396d0b85e6e9c4e2e1d2cf0` | cilium/ebpf | MIT | public |
| `vendor/repos/deepflow` | `1db10dd0d7c9381dd8ad3a4db03d7e1bcbe46c62` | deepflow | Apache-2.0 | public, unused |
| `vendor/repos/katran` | `3f3a3daedfd136315c908cae94ed1fbcb789bf45` | facebookincubator/katran (project branch) | GPL-2.0 | public |
| `vendor/repos/opentelemetry-ebpf-profiler` | `2689a430a04318cb69f79f76adcba10dd40bb218` | OpenTelemetry eBPF profiler | Apache-2.0 | public |
| `vendor/repos/tetragon` | `8ca052908600a83c4fad7429a3023a921bc15851` | cilium/tetragon | Apache-2.0 | public |
| `vendor/repos/tracee` | `413ad7510f4aea23e0a6b33c9e0a996026580d39` | aquasecurity/tracee | Apache-2.0 | public |
| `docs/paper` | `3cfe369fcd2f15af6425578741bc616295aa786e` | paper sources (Overleaf subtree) | author material | private |
| `docs/ebpf27-bpfoptbench` | `17588bdd3dcad404541e9417934c0ee1eafbc6d1` | bpf-bench paper draft | author material | public, unused |
| `docs/kprog-simulator-in-ebpf` | `350aa2a2798a484197bb1f7462d01716591f6c74` | simulator notes | author material | private |
| `docs/speculative-optimization` | `604b807337c4a0ebb87a0ed2e4dae275410a01c1` | prior paper material | author material | private |

The `atc26-ae-1` release recorded `llvm-backend/llvm` at
`01c8ff3766fcf8089c509ff58be535b1488dc7d9` and `vendor/linux-framework` at
`ddb3cbb286aed1fff579600794debe4927c76cc1`.

## Vendored in-tree (not submodules)

- `vendor/bpf/{bcc,cilium,katran,otel,tetragon,tracee}/` — third-party
  application sources and generated BPF artifacts used as benchmark inputs. Each
  retains its upstream license; see the corresponding `vendor/repos/*` entries
  above for origin.
- `vendor/binary/`, `vendor/llvm/` — prebuilt helper binaries where present;
  upstream licenses apply.

## Host toolchain dependencies (not vendored)

| Dependency | Used for | License |
|---|---|---|
| clang / llc 18 | compiling benchmark BPF objects | Apache-2.0 with LLVM Exceptions |
| gcc / aarch64-linux-gnu-gcc 13 | host cross-checks, kernel modules | GPL-3.0 with GCC Runtime Library Exception |
| Rust (`cargo`, via rustup) | `bpfopt/kinsnprober`, `kprog/.../native_link` | MIT OR Apache-2.0 |
| Go | building benchmark applications | BSD-3-Clause |
| CMake, Ninja | builds | BSD-3-Clause / Apache-2.0 |
| Python 3 + PyYAML | harness, generators, plot scripts | PSF-2.0 / MIT |
| Docker | runtime images | Apache-2.0 |
| virtme-ng (`vng`), QEMU | local KVM/VM execution | GPL-2.0 |
| Lean 4 (`leanprover/lean4:v4.28.0`) and Mathlib | the paper's Kinsn proofs (`kinsn/lean/`) | Apache-2.0 |
| Lean 4 (`leanprover/lean4:v4.19.0`) | kprog formal proofs (`kprog/formal/`) | Apache-2.0 |

## Notes

- The `docs/paper` and sibling `docs/*` subtrees are author material included as
  supporting context; they are not part of the artifact's licensed software and
  are not required to run any documented command.
- Where a submodule directory is absent (e.g. the private ones above), no
  documented artifact command depends on it.
