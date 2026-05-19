# vendor/repos — corpus app sources

Submodules for the corpus apps (`bcc`, `bpftrace`, `cilium`, `katran`,
`opentelemetry-ebpf-profiler`, `tetragon`, `tracee`). Each is a fork
under `github.com/eunomia-bpf/*` so we can carry build patches without
maintaining out-of-tree diffs.

Default branch tracking:

| repo | branch | notes |
|---|---|---|
| `katran` | `bpf-benchmark` | 3 build patches on top of upstream commit `be1b2574` (see katran section below) |
| others | `main` | follow upstream HEAD at submodule pin |

`vendor/repos/repos.yaml` is the legacy corpus-collection manifest (lists
upstream URLs / sparse-paths used when the corpus directory was
populated from a fresh `git clone`). It is no longer consumed by any
active code; kept for reference.

---

## katran

Katran is the only fork-and-build app in this directory; everything else
is either pulled from upstream Docker image (tracee / tetragon /
cilium), apt (bpftrace / bcc), or GitHub release tarball (otelcol-ebpf-
profiler). Katran lacks a pre-built distribution, so the bench compiles
it from source.

### Outputs

Required deliverables, produced under
`vendor/build/{x86,arm64}/katran/install/`:

| path | size (rough) | role |
|---|---|---|
| `bin/katran_server_grpc` | ~37 MB (x86) / ~88 MB (arm64, with debug info) | The katran gRPC load-balancer daemon. The bench's `runner/libs/app_runners/katran.py` execs this binary. |
| `bpf/balancer.bpf.o` | ~131 KB | Main XDP load-balancer BPF program |
| `bpf/healthchecking_ipip.bpf.o` | ~15 KB | Health-check IP-in-IP encapsulation program |
| `bpf/xdp_root.bpf.o` | ~6 KB | Tail-call dispatcher attached at the XDP entry point |

### Build flow

`vendor/repos/katran/build_katran.sh` is the upstream-provided build
driver. We invoke it from `runner/mk/katran-artifacts.mk` (called via
`make image-katran-artifacts`). The script does:

1. **`get_*` deps stage** (`INSTALL_DEPS_ONLY=1` mode): clones + builds
   folly, fast_float, googletest, grpc (when `BUILD_EXAMPLE_GRPC=1`),
   libbpf, plus a clang stub marker. Each writes a `<name>_installed`
   sentinel under `build/deps/` so re-runs skip already-installed
   pieces.
2. **Main cmake configure + build**: assembles katran's own libs
   (`libkatranlb`, `libbpfadapter`, etc.) plus the `katran_server_grpc`
   binary.
3. **BPF .o build** via `build_bpf_modules_opensource.sh`: invokes
   clang `-target bpf` for the three programs above.

### Build patches (carried on the eunomia-bpf/katran `bpf-benchmark` branch)

Three changes from upstream `facebookincubator/katran@be1b2574`:

- **`build_bpf_modules_opensource.sh`**: add `-o BPF_OUT_DIR` flag so
  the bench can redirect `.bpf.o` output to a stable artifact path
  instead of katran's own build subdirectory; also fall back to system
  `/usr/bin/clang` when katran's pinned clang download is unavailable.
- **`build_katran.sh`**:
  - Forward `KATRAN_EXTRA_CMAKE_ARGS` env var into the folly and grpc
    cmake invocations (lets the caller pass cross-compile cache vars,
    toolchain files, etc. without editing the script).
  - `sed`-strip folly's `FOLLY_XLOG_STRIP_PREFIXES` compile definition
    after cloning folly. The upstream line
    `"FOLLY_XLOG_STRIP_PREFIXES=\"${CMAKE_SOURCE_DIR}:${CMAKE_BINARY_DIR}\""`
    in folly's `CMakeLists.txt` loses its outer quotes through the
    cmake → make → shell → compiler chain whenever the build path
    contains identifier-like tokens (e.g. `katran` appears in our
    `vendor/build/<arch>/katran/...` path). gcc/clang then read the
    bare path as raw C tokens — "stray `\`" / "use of undeclared
    identifier `katran`" / "missing terminating `"`" errors. The
    define's only effect is to shorten file paths in XLOG output
    lines, so dropping it is safe.
  - Add `-DOPENSSL_NO_ASM=ON` to grpc's cmake invocation so the
    bundled boringssl skips its x86-64 assembly files when building
    for arm64.
- **`example_grpc/CMakeLists.txt`**: cmake-version compatibility
  tweak so the grpc example builds against the newer cmake we use.

### x86 host build (current working procedure)

Run on an Ubuntu 24.04 host with the apt packages from the bench's
runtime-base + build-base lists installed (`clang`, `cmake`,
`build-essential`, the long list of `lib*-dev` packages — see
`runner/containers/runner-runtime.Dockerfile` `runner-runtime-build-
base` stage for the canonical set). Roughly 60 -dev packages; we
already had all but `elfutils`, `libbz2-dev`, `libtool-bin` on a fresh
24.04 install.

```bash
cd vendor/repos/katran
env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR \
  CC=clang CXX=clang++ AR=ar RANLIB=ranlib NCPUS=4 \
  KATRAN_SKIP_SYSTEM_PACKAGES=1 BUILD_EXAMPLE_GRPC=1 \
  BUILD_DIR=$PWD/../../build/x86/katran/build \
  INSTALL_DIR=$PWD/../../build/x86/katran/install \
  INSTALL_DEPS_ONLY=1 \
  ./build_katran.sh
# then the main cmake configure + install + bpf modules; the recipe in
# runner/mk/katran-artifacts.mk has the exact flags.
```

Total ~25 min cold (`folly` install dominates — about 6 min just for
folly's link step).

### ARM64 cross-build from x86 host (current working procedure)

This was the hardest piece. The same build runs end-to-end on an x86
host using `aarch64-linux-gnu-gcc-13` and an Ubuntu multiarch sysroot;
no Docker, no QEMU. The full set of fixes:

#### Required host packages

```bash
sudo dpkg --add-architecture arm64
sudo apt-get update
sudo apt-get install -y --no-install-recommends crossbuild-essential-arm64
```

Then the `:arm64` runtime/devel libraries that folly + katran link
against. The complete set we ended up needing:

```
libboost-context-dev:arm64       libboost-filesystem-dev:arm64
libboost-program-options-dev:arm64 libboost-regex-dev:arm64
libboost-system-dev:arm64        libboost-thread-dev:arm64
libboost-chrono-dev:arm64
libdouble-conversion-dev:arm64   libdouble-conversion3:arm64
libgflags-dev:arm64              libgoogle-glog-dev:arm64
libssl-dev:arm64                 libfmt-dev:arm64
liblz4-dev:arm64                 liblzma-dev:arm64
libsnappy-dev:arm64              libzstd-dev:arm64
libsodium-dev:arm64              libevent-dev:arm64
libre2-dev:arm64                 libbz2-dev:arm64
libdwarf-dev:arm64               libdw-dev:arm64
libiberty-dev:arm64              libaio-dev:arm64
libelf-dev:arm64                 libbpf-dev:arm64
libcereal-dev:arm64              libmnl-dev:arm64
libunwind-dev:arm64
libgrpc++-dev:arm64              libprotobuf-dev:arm64
# Plus the matching x86 host plugins for code generation:
protobuf-compiler-grpc           # provides /usr/bin/grpc_cpp_plugin
```

**Do NOT install `liburing-dev:arm64`.** Ubuntu 24.04 ships liburing
2.5; folly's master pulls a newer io_uring_zcrx API (kernel 6.10+
headers, e.g. `IORING_REGISTER_ZCRX_CTRL`, `io_uring_zcrx_rq`) that 2.5
doesn't expose. If liburing-dev is present, folly tries to use it and
fails. With liburing-dev absent, folly's `find_package(LIBURING)`
returns NOTFOUND and the affected features compile out cleanly.

#### Host PPA / multiarch version-alignment

Ubuntu's `Multi-Arch: same` policy requires `:amd64` and `:arm64`
shared-library packages to be at identical versions. If the host has a
3rd-party PPA whose builds are amd64-only (e.g. `savoury1/python` ships
`libzstd1:amd64=1.5.7` while ports.ubuntu.com only has
`libzstd1:arm64=1.5.5`), `apt install :arm64 -dev` packages will fail
with `Depends: libzstd1:arm64 (>= 1.5.5) but it is not going to be
installed`. Fix by downgrading the affected `:amd64` packages back to
the Ubuntu archive version (which has a matching `:arm64`):

```bash
sudo apt-get install -y --allow-downgrades \
  libzstd1:amd64=1.5.5+dfsg2-2build1.1   libzstd1:arm64=1.5.5+dfsg2-2build1.1 \
  libsnappy1v5:amd64=1.1.10-1build1      libsnappy1v5:arm64=1.1.10-1build1
```

This does not break host-side amd64 use of these libraries — they are
forward-compatible ABIs.

#### CMake toolchain file

`.cache/aarch64-toolchain.cmake` (already committed) declares the cross
compilers and `CMAKE_FIND_ROOT_PATH_MODE_*` so cmake's `find_package`
hunts the multiarch arm64 sysroot:

```cmake
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
set(CMAKE_C_COMPILER   /usr/bin/aarch64-linux-gnu-gcc-13)
set(CMAKE_CXX_COMPILER /usr/bin/aarch64-linux-gnu-g++-13)
set(CMAKE_AR           /usr/bin/aarch64-linux-gnu-ar)
set(CMAKE_RANLIB       /usr/bin/aarch64-linux-gnu-ranlib)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
set(ENV{PKG_CONFIG_PATH} "/usr/lib/aarch64-linux-gnu/pkgconfig")
set(ENV{PKG_CONFIG_LIBDIR} "/usr/lib/aarch64-linux-gnu/pkgconfig:/usr/share/pkgconfig")
```

#### CMake `try_run()` cross-compile cache vars

Folly's `FollyConfigChecks.cmake` calls `check_cxx_source_runs()`
several times to probe runtime behaviour (`vsnprintf` error returns,
unaligned access, weak-symbol semantics, Linux vDSO presence, wchar
support). Each one expands to `try_run()`, which can't execute the
arm64 binary on an x86 host. cmake errors out with `try_run() invoked
in cross-compiling mode, please set the following cache variables
appropriately`. The Linux/glibc arm64 outcome matches the x86 outcome
for all five, so we pre-set their exit codes to 0 (= run succeeded)
via `KATRAN_EXTRA_CMAKE_ARGS`. The exact vars to set:

```
-DFOLLY_HAVE_UNALIGNED_ACCESS_EXITCODE=0
-DFOLLY_HAVE_WEAK_SYMBOLS_EXITCODE=0
-DFOLLY_HAVE_LINUX_VDSO_EXITCODE=0
-DFOLLY_HAVE_WCHAR_SUPPORT_EXITCODE=0
-DHAVE_VSNPRINTF_ERRORS_EXITCODE=0
```

#### gRPC code-generation needs host-arch tools

When grpc cross-builds, its cmake compiles `grpc_cpp_plugin` and
`protoc` for the target. Those binaries are arm64 ELFs and cannot run
on the x86 build host, so the proto-stub generation step (which runs
during `make`) fails. Pass the system x86 plugins explicitly:

```
-D_PROTOBUF_PROTOC=/usr/bin/protoc
-D_gRPC_CPP_PLUGIN=/usr/bin/grpc_cpp_plugin
```

(`protobuf-compiler-grpc` provides both as host x86 binaries on Ubuntu.)

#### gRPC vs system version mismatch

Katran's `build_katran.sh` pins grpc to `v1.49.1`. Ubuntu 24.04 ships
grpc 1.51. The `grpc_cpp_plugin` we use is 1.51 and emits code that
expects the 1.51 header layout (e.g.
`<grpcpp/impl/channel_interface.h>` exists directly, whereas in 1.49
it lives under `<grpcpp/impl/codegen/channel_interface.h>`). If we
build grpc 1.49 from source and let katran link against it, the 1.51-
generated stubs fail to compile (`No such file or directory:
grpcpp/impl/channel_interface.h`).

Fix: drop the cross-built grpc 1.49 install entirely; link against the
**system grpc 1.51** (both `:amd64` and `:arm64` multiarch). After the
deps stage finishes, before running the katran main cmake, remove the
1.49 install bits:

```bash
rm -rf vendor/build/arm64/katran/install/include/grpc \
       vendor/build/arm64/katran/install/include/grpcpp \
       vendor/build/arm64/katran/install/lib/libgrpc* \
       vendor/build/arm64/katran/install/lib/libgpr* \
       vendor/build/arm64/katran/install/lib/libupb* \
       vendor/build/arm64/katran/install/lib/libaddress_sorting* \
       vendor/build/arm64/katran/install/lib/cmake/grpc \
       vendor/build/arm64/katran/install/lib/pkgconfig/grpc*
```

cmake's `find_package(gRPC)` then falls through to the system 1.51
copy, the generated stubs match, and the link succeeds.

#### Putting it all together

After the host setup above, the cross-build invocation is:

```bash
cd vendor/repos/katran
env -u VERBOSE -u BUILD_EXAMPLE_THRIFT -u BUILD_KATRAN_TPR \
  CC=aarch64-linux-gnu-gcc-13 CXX=aarch64-linux-gnu-g++-13 \
  AR=aarch64-linux-gnu-ar RANLIB=aarch64-linux-gnu-ranlib NCPUS=4 \
  KATRAN_SKIP_SYSTEM_PACKAGES=1 BUILD_EXAMPLE_GRPC=1 \
  KATRAN_EXTRA_CMAKE_ARGS="-DCMAKE_TOOLCHAIN_FILE=$PWD/../../../.cache/aarch64-toolchain.cmake -DFOLLY_HAVE_UNALIGNED_ACCESS_EXITCODE=0 -DFOLLY_HAVE_WEAK_SYMBOLS_EXITCODE=0 -DFOLLY_HAVE_LINUX_VDSO_EXITCODE=0 -DFOLLY_HAVE_WCHAR_SUPPORT_EXITCODE=0 -DHAVE_VSNPRINTF_ERRORS_EXITCODE=0 -D_PROTOBUF_PROTOC=/usr/bin/protoc -D_gRPC_CPP_PLUGIN=/usr/bin/grpc_cpp_plugin" \
  BUILD_DIR=$PWD/../../build/arm64/katran/build \
  INSTALL_DIR=$PWD/../../build/arm64/katran/install \
  INSTALL_DEPS_ONLY=1 \
  ./build_katran.sh

# Then nuke the cross-built grpc 1.49 (see previous section) and run
# the main cmake configure with the same toolchain file + system grpc
# + -DOPENSSL_NO_ASM=ON, build with -j4, and the BPF module step.
```

Total cold cross-build time: ~30 min (folly + grpc dominate).

### Why not skip grpc?

Katran's `example/CMakeLists.txt` defines a `simple_katran_server`
target that sounds lighter than `katran_server_grpc`, but it links
against fbthrift + wangle + fizz + sodium, which collectively are
heavier and harder to cross-compile than grpc. There is no truly
network-free example binary in the upstream tree.
