# `runner/containers/runner-runtime.Dockerfile` Build Analysis

Date: 2026-04-26

## Executive Summary

The Dockerfile is functionally correct, but it still carries several builder-era leftovers and a few cache-hostile mega-steps that are especially expensive for `linux/arm64` builds.

The biggest concrete findings are:

1. The Go toolchain is dead weight in the current Dockerfile.
   The current file never runs `go build`, never invokes a Go-based repo build, and no in-repo build rule references Go. `GO_VERSION`, the Go tarball download, `/usr/local/go`, and `/root/.cache/go-build` cleanup are all stale.

2. The apt `cargo` and `rustc` packages are redundant.
   The Dockerfile later installs Rust again through `rustup` and prepends `/opt/cargo/bin` to `PATH`, so the apt-provided `cargo`/`rustc` are not the toolchain that actually builds the daemon.

3. `ipset` and `iptables` are installed twice.
   They are installed in the base apt layer (`runner-runtime.Dockerfile:44-45`) and then installed again in the final runtime step (`runner-runtime.Dockerfile:458-460`) even though they were never purged.

4. Katran is the single most expensive avoidable userspace build.
   The repo needs real Katran runtime artifacts (`katran_server_grpc` plus three `.bpf.o` files), so some Katran build step is necessary unless those artifacts are prebuilt elsewhere. But there is no official upstream release channel to consume directly, so repeated source builds are paying the full folly/gflags/glog/grpc/CMake cost every time.

5. `bpftool` does not have to be built from source for basic runtime use, but building from the vendored kernel tree gives tighter version matching.
   Ubuntu Noble arm64 exposes a `bpftool` package path via the `linux-tools-common` family, so a system package is available. The tradeoff is determinism: the repo vendors Linux `7.0-rc2`, while Ubuntu package versions track distro kernel tooling.

6. The current `arm64` path is usually not true cross-compilation.
   `docker build --platform linux/arm64` plus `CROSS_COMPILE=` means most native code is compiled as arm64 _inside an arm64 container_. On an x86 builder that generally means QEMU emulation, which is why kernel, Katran, Rust, and C++ steps are slow.

## Important Context

- The repo currently documents a deliberate “single-lineage” design: build userspace artifacts inside the same runner image lineage instead of doing a classic builder-to-runtime handoff.
  See `docs/tmp/runner-image-hardcut-design.md` and `runner/containers/README.md`.
- This matters because the strongest optimization, a classic multi-stage builder/runtime split, is technically straightforward but partially reverses that current design choice.
- The analysis below therefore separates:
  - optimizations compatible with the current single-lineage design
  - optimizations that require relaxing that design

## Layer-by-Layer Analysis

| Dockerfile lines | Instruction | Purpose | Necessary now? | Notes / optimization |
| --- | --- | --- | --- | --- |
| 2-5 | `ARG TRACEE_IMAGE/TETRAGON_IMAGE/CILIUM_IMAGE/CALICO_NODE_IMAGE` | Pin upstream app images | Yes | Good. These are already the right pattern for prebuilt artifacts. |
| 6 | `FROM ubuntu:24.04 AS runner-runtime-build-base` | Shared base for userspace + kernel build stages | Partly | Works, but mixes runtime packages, build toolchains, and app packages into one heavy base. |
| 16-109 | Large `apt-get install` | Install build tools + runtime tools + app packages | Over-broad | Contains real runtime packages, real builder packages, and several likely-unused packages in one early layer. |
| 111-123 | Install Go tarball | Add Go toolchain | No | No current build step uses Go. This whole layer can be removed. |
| 125-126 | `ENV PATH=/usr/local/go/bin` | Expose Go | No | Dead once the Go layer is removed. |
| 128-140 | `rustup` install | Build Rust daemon | Yes for build, no for runtime | Needed only while building `daemon/`. Good candidate for an isolated daemon builder step or a Rust builder stage. |
| 142-143 | `mkdir` + `WORKDIR` | Workspace root | Yes | Fine. |
| 145-151 | `FROM --platform=$TARGETPLATFORM ... AS runner-runtime-*-upstream` | Pull prebuilt Tracee/Tetragon/Cilium/Calico images | Yes | This is already the right optimization. |
| 153-211 | `FROM runner-runtime-build-base AS runner-runtime-userspace` + big `RUN` | Copy partial sources, optionally clone Katran, build `bpftool`, build Katran | Partly | `bpftool` build is optional; Katran build is necessary unless artifacts are prebuilt elsewhere. The single huge `RUN` is bad for cache reuse. |
| 213-225 | `COPY` Tracee binaries/libs + musl fixup | Import Tracee runtime artifacts | Yes | Good use of upstream prebuilt artifacts. The apt `musl` package is not required for this. |
| 226-227 | `COPY` Tetragon binary + `/var/lib/tetragon` | Import Tetragon artifacts | Yes | Good. No local Tetragon build happens anymore. |
| 229-267 | `FROM runner-runtime-build-base AS runner-runtime-kernel-artifacts` + install `bsdextrautils` + build kernel/modules/kinsn | Build kernel-side artifacts | Yes | Kernel build is necessary in current design. `bsdextrautils` is build-only and isolated already. |
| 269-429 | `FROM runner-runtime-userspace AS runner-runtime` + big `RUN` | Copy repo sources, build runner/micro/tests/daemon, delete sources, purge build deps | Partly | All artifacts are needed, but the one-shot `RUN` makes cache invalidation much worse than necessary. |
| 431-450 | `COPY --from` kernel/Cilium/Calico artifacts | Import kernel outputs and upstream app assets | Yes | Good. Cilium and Calico are already consuming upstream prebuilt artifacts. |
| 451 | `COPY` installer script | Add `bpfrejit-install` | Yes | Fine. |
| 453-502 | Final runtime `RUN` | Install runtime networking packages, validate binaries, download `otelcol-ebpf-profiler`, symlink repo artifact roots | Mostly | `etcd-server`/`nftables` are justified; `auditd` looks unnecessary; `ipset`/`iptables` are duplicate installs. |
| 504-508 | Final `ENV` | Runtime environment | Yes | Fine. |
| 510 | `FROM runner-runtime AS runner-default` | Alias target | Yes | Fine. |

## APT Package Analysis

### 1. Packages that are clearly build-only

These are only needed to compile native artifacts and should not be in the final runtime environment:

`autoconf automake bc binutils-dev bison clang cmake dwarves flex g++ gcc git libaio-dev libboost-all-dev libbpf-dev libbpfcc-dev libbz2-dev libcap-dev libcereal-dev libclang-dev libcurl4-openssl-dev libdouble-conversion-dev libdw-dev libdwarf-dev libedit-dev libelf-dev libevent-dev libffi-dev libfl-dev libfmt-dev libgflags-dev libgoogle-glog-dev libiberty-dev liblz4-dev libmnl-dev libpcap-dev libre2-dev libsodium-dev libsnappy-dev libspdlog-dev libssl-dev libtool libtool-bin libltdl-dev libunwind-dev libyaml-cpp-dev libzstd-dev llvm llvm-dev make pkg-config rsync scons unzip xxd zlib1g-dev`

The Dockerfile already purges these at lines `369-428`, which is correct.

### 2. Packages that are build-only but currently redundant

These should not be installed at all:

- `cargo`
- `rustc`

Reason:

- apt installs them at lines `28` and `97`
- the image then installs Rust again via `rustup` at lines `134-140`
- `/opt/cargo/bin` is prepended to `PATH` at line `132`
- the actual daemon build uses the rustup-managed toolchain, not the apt toolchain

### 3. Packages that are runtime-needed by current repo code

These have explicit runtime call sites or obvious runtime binary dependencies:

- `bash`
  Needed by `runner/scripts/bpfrejit-install`.
- `bpfcc-tools`
  BCC runtime.
- `bpftrace`
  bpftrace runtime.
- `ca-certificates`
  Needed for external downloads and common TLS paths.
- `curl`
  Used by workload code and by `otelcol-ebpf-profiler` download.
- `fio`
  Used in `runner/libs/workload.py`.
- `iproute2`
  Provides `ip` and `tc`; used by Katran and tcp retransmit workloads.
- `kmod`
  Provides `modprobe`/`depmod`; used by workloads and installer.
- `procps`
  Provides `sysctl`; used by workload code.
- `python3`
  Main suite runtime.
- `python3-bpfcc`
  BCC Python runtime.
- `python3-yaml`
  Suite config parsing.
- `rt-tests`
  Provides `hackbench`.
- `stress-ng`
  Used by workloads.
- `tar`
  Used by Tetragon setup checks and `otelcol-ebpf-profiler` extraction.
- `util-linux`
  Provides `setpriv` and `unshare`; used by workloads.
- `wrk`
  Used by network workload.
- `etcd-server`
  Required by Cilium/Calico local runner paths.
- `nftables`
  Required by Calico/Cilium runtime paths.

### 4. Packages that look removable from the final runtime

I found no repo-local runtime call sites for these:

- `auditd`
  Current Dockerfile only uses it to make `ausyscall --dump` succeed at build time.
- `musl`
  Tracee’s musl loader and musl libc are copied from the upstream Tracee image; the apt `musl` package is not referenced.
- `sysbench`
  No current runner or workload path references it.
- `bzip2`
- `cpio`
- `debianutils`
- `diffutils`
- `elfutils`
- `file`
- `lz4`
- `openssl`
- `perl`
- `xz-utils`
- `zstd`

Some of these may still be indirectly useful for diagnostics, but they are not justified by the current benchmark runtime code.

### 5. Duplicate installation

`ipset` and `iptables` are installed twice:

- first install: lines `44-45`
- second install: lines `458-460`

They are not purged in between, so the final install is redundant.

## Toolchain Questions

### Rust toolchain

### Does runtime image need Rust compilation at runtime?

No.

The runtime image needs only the prebuilt daemon binary:

- `runner/mk/build.mk` builds `daemon/target/.../bpfrejit-daemon`
- the Dockerfile then deletes Rust sources and rustup directories at lines `333-356`

So the runtime image does **not** need Rust to execute benchmarks. Rust is only needed during image build.

### Is Rust toolchain still needed somewhere during image build?

Yes, for the daemon build at line `326`.

### Best optimization

- Keep Rust only in a daemon-specific builder step.
- At minimum, remove apt `cargo`/`rustc` and rely only on rustup.
- Better: split daemon build into its own `RUN`, or use a dedicated Rust builder stage if design policy allows it.

### Go toolchain

### Does runtime image need Go?

No.

### Does current Dockerfile build anything with Go?

No.

I found no active `go build`, no Go-based artifact target, and no current Dockerfile step that consumes `/usr/local/go`.

This is the clearest dead layer in the file.

### Conclusion

Remove:

- `ARG GO_VERSION`
- Go tarball download/install (`111-123`)
- Go `PATH`/`GOTOOLCHAIN` env (`125-126`)
- `/root/.cache/go-build` cleanup entries
- `/root/go` cleanup entries
- `/usr/local/go` cleanup entry

## Katran

### Is source build necessary today?

With the current artifact contract, yes.

The runtime expects:

- `katran/bin/katran_server_grpc`
- `katran/bpf/balancer.bpf.o`
- `katran/bpf/healthchecking_ipip.bpf.o`
- `katran/bpf/xdp_root.bpf.o`

That requirement is enforced in `runner/mk/build.mk` and suite validation code.

### Can this use official upstream prebuilt artifacts instead?

Not directly.

External verification:

- GitHub releases page currently shows **no releases**:
  <https://github.com/facebookincubator/katran/releases>
- Katran upstream README still tells users to build with `build_katran.sh`:
  <https://github.com/facebookincubator/katran>

So there is no obvious official per-arch binary or image channel comparable to Tracee/Tetragon/Cilium/Calico.

### Practical optimization

Yes, but it would be **your own prebuilt artifact**, not an official upstream one.

Recommended pattern:

1. Build Katran once per `{commit, arch}` in CI.
2. Publish an internal artifact image such as `ghcr.io/<org>/katran-artifacts:<commit>-<arch>`.
3. Replace the source build with `COPY --from=<that image> ...`.

This is the highest-impact arm64 optimization available without changing the benchmark contract.

## `bpftool`

### Is source build necessary?

Not strictly for current runtime usage.

Current runtime code mainly uses:

- `bpftool prog show`
- `bpftool prog run`
- `bpftool map show`
- `bpftool map update`
- `bpftool batch file`
- `bpftool net show/attach/detach`

These are mainstream capabilities.

### Can it use Ubuntu system packages?

Yes.

Ubuntu Noble arm64 exposes a `bpftool` package path via the `linux-tools-common` family (the `bpftool` package is a virtual package provided by `linux-tools-common`/related packages):

- <https://answers.launchpad.net/ubuntu/noble/arm64/bpftool>
- Noble package search snippets also show `bpftool` as a virtual package provider path under Ubuntu kernel tooling.

### Should it use system packages?

Only if you accept version skew.

Why skew matters:

- the repo vendors Linux `7.0-rc2` (`vendor/linux-framework/Makefile`)
- building `bpftool` from that tree guarantees behavior aligned with the vendored kernel tree
- distro `bpftool` will track Ubuntu kernel tooling instead

### Recommendation

- If the priority is deterministic compatibility with the vendored kernel tree, keep source build.
- If the priority is arm64 build speed and smaller builder complexity, switch to system `bpftool` and explicitly validate the runtime commands used by this repo.

My call: this is a reasonable optimization candidate, but it is less important than removing Go and externalizing Katran.

## Multi-Stage Build Isolation

### Can `cmake/clang/gcc` and other toolchains be isolated with multi-stage builds?

Yes, absolutely.

Technically, the cleanest layout would be:

1. `runtime-base`
   Only Python, workload tools, network tools, and app binaries.
2. `katran-builder`
   CMake/clang plus Katran dependency stack.
3. `runner-builder`
   CMake/gcc/llvm/libbpf for `micro_exec`, tests, and micro programs.
4. `daemon-builder`
   Rust-only.
5. `kernel-builder`
   Kernel build deps only.

Then `COPY --from=` the finished artifacts into `runtime-base`.

### Catch

This conflicts with the repo’s current documented “single-lineage” design, which intentionally removed classic builder-to-runtime handoff.

So:

- **Technically best**: use classic multi-stage builders.
- **Policy-compatible best**: keep one lineage, but split large `RUN`s and trim dead tooling.

## Things Already Correctly Using Prebuilt Artifacts

The Dockerfile already avoids unnecessary local builds for these components:

- Tracee
  `COPY --from=runner-runtime-tracee-upstream ...`
- Tetragon
  `COPY --from=runner-runtime-tetragon-upstream ...`
- Cilium
  `COPY --from=runner-runtime-cilium-upstream ...`
- Calico
  `COPY --from=runner-runtime-calico-upstream ...`
- `otelcol-ebpf-profiler`
  Downloaded as an official release tarball instead of local source build

So the main remaining “should this be prebuilt?” question is really Katran and, secondarily, `bpftool`.

## Cache and Layering Problems

### `runner-runtime-userspace` mega-step

Lines `159-211` combine:

- optional Katran source import / clone
- vendor copy
- `bpftool` build
- Katran build

This means a change in any of those inputs invalidates the whole step.

### `runner-runtime` mega-step

Lines `279-429` combine:

- runner build
- micro program build
- test build
- daemon build
- cleanup
- apt purge

This is the biggest incremental-build problem in the file.

Examples:

- changing a Python suite file can force rebuild of runner, tests, and daemon
- changing `daemon/src/**` can force rebuild of runner/test layers first
- changing `runner/src/**` can force daemon rebuild again

### Low-risk cache improvement within current design

Split line `279-429` into separate `RUN`s:

1. build runner
2. build micro programs
3. build tests
4. build daemon
5. cleanup + purge

Do the same for the Katran/`bpftool` step:

1. prepare vendored bpftool inputs and build `bpftool`
2. prepare Katran inputs and build Katran

This does not require a classic builder/runtime handoff, but it greatly improves layer reuse.

## Why Arm64 Builds Are Slow

The slowest steps for `docker build --platform linux/arm64` are:

1. Kernel build in `runner-runtime-kernel-artifacts`
   Current make rule uses `ARCH=arm64 CROSS_COMPILE=`; that is native-in-container, not host cross-compilation.
2. Katran build
   Folly/gflags/glog/grpc/CMake dependency stack is heavy even on native arm64, and much worse under QEMU.
3. Rust daemon build
   Cargo dependency compile on arm64 is non-trivial.
4. `micro_exec` / tests / libbpf / llvmbpf link steps
   LLVM and C++ linking are slower under emulation.
5. Early oversized apt/toolchain layer
   It installs both runtime packages and unused toolchains before any real build begins.

## Recommended Optimizations

### A. Low-risk, compatible with current single-lineage design

1. Remove Go entirely.
   Highest confidence, lowest risk.

2. Remove apt `cargo` and `rustc`.
   Keep only rustup-managed Rust.

3. Stop installing runtime-only packages in the early base if they are not needed before the final runtime step.
   Good candidates: `ipset`, `iptables`, `bpftrace`, `bpfcc-tools`, `python3-bpfcc`, `rt-tests`, `stress-ng`, `wrk`, `fio`, `etcd-server`, `nftables`.

4. Remove duplicate `ipset`/`iptables` install.

5. Remove likely-unused runtime packages after validation:
   `auditd musl sysbench bzip2 cpio debianutils diffutils elfutils file lz4 openssl perl xz-utils zstd`

6. Split the mega-`RUN` steps to improve cache reuse.

7. Add BuildKit cache mounts for Rust if keeping in-image build:
   `cargo registry`, `cargo git`, optionally daemon target cache.

### B. Medium-risk

1. Replace source-built `bpftool` with Ubuntu system package.
2. Keep a small validation test that exercises the exact runtime commands this repo uses.

### C. High-impact, highest-risk / architectural

1. Prebuild Katran artifacts externally and `COPY --from` them.
2. Reintroduce true builder stages for daemon / runner / Katran / kernel.
3. For arm64 on x86 builders, move from “emulated native arm64” toward real cross-compilation where possible:
   - kernel: `CROSS_COMPILE=aarch64-linux-gnu-`
   - Rust daemon: cross linker + `aarch64-unknown-linux-gnu`
   - runner/tests: arm64 cross toolchain + sysroot

Katran is the hardest piece to cross-compile cleanly because of its dependency stack.

## Estimated Arm64 Build-Time Savings

These are estimates, not measured timings.

### Conservative cleanup only

Changes:

- remove Go
- remove apt `cargo`/`rustc`
- remove duplicate `ipset`/`iptables`
- trim obvious unused packages

Expected arm64 clean-build reduction:

- roughly **5% to 12%**

This is mostly apt/download/tooling savings, not compile savings.

### Practical optimization set

Changes:

- conservative cleanup
- split mega-`RUN`s for cache reuse
- add Rust cache mounts
- optionally replace source-built `bpftool` with system package

Expected arm64 clean-build reduction:

- roughly **10% to 20%**

Expected arm64 incremental rebuild reduction after localized changes:

- roughly **40% to 75%**

The incremental gain is much larger than the clean-build gain because the current Dockerfile invalidates too much work at once.

### High-impact optimization set

Changes:

- externalize Katran artifacts
- optionally use classic builder/runtime stages

Expected arm64 clean-build reduction:

- roughly **25% to 45%**

If Katran currently dominates the userspace portion of the build, the real win will be closer to the top of that range.

### True x86 -> arm64 cross-compilation for kernel/userspace

If you replace emulated native arm64 compilation with real cross-compilation for the heavy native steps, the speedup can exceed the ranges above, but this is a larger engineering project and not a small Dockerfile cleanup.

## Recommended Priority Order

1. Delete Go now.
2. Delete apt `cargo`/`rustc` now.
3. Remove duplicate `ipset`/`iptables` now.
4. Split the big userspace build `RUN` into smaller cacheable steps.
5. Decide whether `bpftool` version matching is worth source-building.
6. If arm64 build time is still painful, prebuild Katran artifacts externally instead of rebuilding them in every runtime image.

## Bottom Line

The most important unnecessary steps today are not subtle:

- the Go toolchain is unused
- apt `cargo`/`rustc` are duplicated by rustup
- `ipset`/`iptables` are installed twice
- `auditd` appears to exist only to satisfy `ausyscall --dump`

The main arm64 pain is not package install time, though. It is that the Dockerfile still rebuilds heavy native components, especially Katran and the kernel, in target-arch containers. If you want materially faster arm64 builds, the real lever is to stop rebuilding Katran every time and to improve cache boundaries around native build steps.
