# Katran Server Build Report

Date: `2026-03-18`
Repo: `/home/yunwei37/workspace/bpf-benchmark`
Source commit: `45926bf4f0dece1fe5d29784718ecdceac8d9f88`

## Outcome

Built a working `katran_server_grpc` bundle for x86_64 Linux and staged it under:

- `e2e/cases/katran/bin/katran_server_grpc`
- `e2e/cases/katran/bin/balancer.bpf.o`
- `e2e/cases/katran/lib/`

`e2e/cases/katran/setup.sh` now discovers the repo-local bundle automatically.

## Discovery

- `corpus/repos/katran/` does not contain any `Dockerfile*`, `docker*`, or `.docker*` file.
- `corpus/repos/katran/` is still a sparse checkout; the usable full clone is `tmp/katran-src/`.
- `apt-cache search folly` on the host did not expose a usable `libfolly-dev` package.
- `docker` is available on this machine and the daemon is healthy.

## What Worked

I built in Docker on `ubuntu:22.04` instead of on the host.

Local builder assets:

- `tmp/katran-docker/Dockerfile`
- `tmp/katran-docker/run-build.sh`

Build strategy:

1. Use a full Katran clone from `tmp/katran-src/`.
2. Copy sources into `/work/src` inside the container so the build path is short and has no `bpf-benchmark` segment.
3. Reuse previously built deps from `/work/build/deps` when possible.
4. Force `CC=/usr/bin/clang` and `CXX=/usr/bin/clang++`.
5. Bundle the final binary with the required shared libraries on the host.

## Key Fixes Needed

The Docker build did not work on the first try. These were the concrete blockers and fixes:

1. `build_katran.sh` assumes `BUILD_DIR` lives under the source tree because it runs `cmake ../..` from `build/...`.
   Fix: copy the source tree to `/work/src` and build under `/work/src/_build`.

2. Reusing compiled `folly`/`grpc` without also providing the system development packages caused CMake failures for `Boost` and `libzstd`.
   Fix: bake the required Ubuntu development packages into `tmp/katran-docker/Dockerfile`.

3. `example_grpc/CMakeLists.txt` forced `C++17`, but the built `folly` headers now require `constinit`.
   Fix: change `tmp/katran-src/example_grpc/CMakeLists.txt` to `CMAKE_CXX_STANDARD 20`.

## Artifacts

Primary bundle:

- `e2e/cases/katran/bin/katran_server_grpc`
- `e2e/cases/katran/bin/balancer.bpf.o`
- `e2e/cases/katran/lib/`

Checksums:

- `katran_server_grpc`: `f5cc6db8f20fd68be7676e663cd1a9c37c270e2865c09d8805d9f2cf5c15b1ce`
- `balancer.bpf.o`: `087c2be666ec016f1986824f87bdc47dc8e6e3458b65d701a63da81754caa934`

Raw build outputs are preserved under:

- `tmp/katran-docker-work/src/_build/`

## Verification

Binary checks:

- `file e2e/cases/katran/bin/katran_server_grpc`
  - `ELF 64-bit LSB pie executable, x86-64`
- `readelf -d e2e/cases/katran/bin/katran_server_grpc`
  - `RUNPATH` is `$ORIGIN/../lib`
- `ldd e2e/cases/katran/bin/katran_server_grpc`
  - resolves bundled `libglog.so.0`, `libfmt.so.8`, `libboost_program_options.so.1.74.0`, plus other needed shared libraries
- `e2e/cases/katran/bin/katran_server_grpc --help`
  - starts successfully and exposes the expected flags:
    `-balancer_prog`, `-intf`, `-map_path`, `-prog_pos`, `-server`, `-default_mac`, `-forwarding_cores`

BPF object checks:

- `file e2e/cases/katran/bin/balancer.bpf.o`
  - `ELF 64-bit LSB relocatable, eBPF`
- `llvm-objdump -t e2e/cases/katran/bin/balancer.bpf.o`
  - contains symbol `balancer_ingress` in section `xdp`

Setup-path check:

- `bash e2e/cases/katran/setup.sh`
  - resolves `KATRAN_SERVER_BINARY=/home/yunwei37/workspace/bpf-benchmark/e2e/cases/katran/bin/katran_server_grpc`

## Notes

- I did **not** do a live host attach/XDP smoke test in this pass. That still needs root, a chosen interface, and a safe test setup.
- The server binary is the gRPC variant, not the thrift/simple variant.
- The official server expects the BPF object file path `balancer.bpf.o`; the program symbol inside it is `balancer_ingress`.
