# Third-party notices and vendored-dependency provenance

This repository's original material is licensed under the MIT license in
[`LICENSE`](LICENSE). The paths below are **third-party or vendored** and remain
under their own licenses, which are authoritative for those paths.

Exact revisions are pinned by git submodules (`.gitmodules`) and/or by the
recorded commits. To materialize them:

```bash
git submodule update --init --recursive
```

## Git submodules (exact pinned revisions)

Recorded with `git submodule status` at the artifact-definition commit.

| Path | Pinned revision | Upstream | License |
|---|---|---|---|
| `llvm-backend/llvm` | `01c8ff3766fcf8089c509ff58be535b1488dc7d9` | LLVM project (patched BPF backend) | Apache-2.0 with LLVM Exceptions (`LICENSE.TXT`) |
| `vendor/linux-framework` | `ddb3cbb286aed1fff579600794debe4927c76cc1` | Linux kernel build used for benchmarks | GPL-2.0 (`COPYING`) |
| `vendor/libbpf` | `caa25e0b72746fef7ea01497ece7db57187f132c` | libbpf | LGPL-2.1 OR BSD-2-Clause (`LICENSE`) |
| `vendor/llvmbpf` | `dd788ba56f1c16088f2541b56d9e5285466a8ae8` | eunomia-bpf/llvmbpf (project fork branch) | MIT (`LICENSE`) |
| `vendor/academic-writing-skills` | `867d61c2fd50c506b5727067186b5ee4ff120f0d` | writing skills | see submodule |
| `vendor/repos/bcc` | `07ca7ba9df379bf063b3b2afca6983b8d91bc2a2` | iovisor/bcc | Apache-2.0 |
| `vendor/repos/bpftrace` | `75aca47dd8e1d642ff31c9d3ce330e0c616e5b96` | bpftrace | Apache-2.0 |
| `vendor/repos/cilium` | `1b721c2964e7799cab3e18c38066905ea240fa34` | cilium/cilium | Apache-2.0 |
| `vendor/repos/cilium-ebpf` | `88256f7afc6f895e6396d0b85e6e9c4e2e1d2cf0` | cilium/ebpf | MIT |
| `vendor/repos/deepflow` | `1db10dd0d7c9381dd8ad3a4db03d7e1bcbe46c62` | deepflow | Apache-2.0 |
| `vendor/repos/katran` | `3f3a3daedfd136315c908cae94ed1fbcb789bf45` | facebookincubator/katran (project branch) | GPL-2.0 |
| `vendor/repos/opentelemetry-ebpf-profiler` | `2689a430a04318cb69f79f76adcba10dd40bb218` | OpenTelemetry eBPF profiler | Apache-2.0 |
| `vendor/repos/tetragon` | `8ca052908600a83c4fad7429a3023a921bc15851` | cilium/tetragon | Apache-2.0 |
| `vendor/repos/tracee` | `413ad7510f4aea23e0a6b33c9e0a996026580d39` | aquasecurity/tracee | Apache-2.0 |
| `docs/paper` | `70463745391cf3f33c1202f7beeb47aab4ebf674` | paper sources (Overleaf subtree) | author material |
| `docs/ebpf27-bpfoptbench` | `103d73c8ba750c7135fce12d0fa59aeef6359fa3` | bpf-bench paper draft | author material |
| `docs/kprog-simulator-in-ebpf` | `81dd58625e68fb322383fe4af56282cd41cff821` | simulator notes | author material |
| `docs/speculative-optimization` | `3e5f2483bddc7efa62a9ffb040b7a70bafb21fdb` | prior paper material | author material |

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
| Rust (`cargo`, via rustup) | `bpfopt/kopprober`, `native-sim/.../native_link` | MIT OR Apache-2.0 |
| Go | building benchmark applications | BSD-3-Clause |
| CMake, Ninja | builds | BSD-3-Clause / Apache-2.0 |
| Python 3 + PyYAML | harness, generators, plot scripts | PSF-2.0 / MIT |
| Docker | runtime images | Apache-2.0 |
| virtme-ng (`vng`), QEMU | local KVM/VM execution | GPL-2.0 |
| Lean 4 (`leanprover/lean4:v4.19.0`) | formal proofs | Apache-2.0 |

## Notes

- The `docs/paper` and sibling `docs/*` subtrees are author material included as
  supporting context; they are not part of the artifact's licensed software and
  are not required to run any documented command.
- Where a submodule directory is absent (e.g. optional writing skills), no
  documented artifact command depends on it.
