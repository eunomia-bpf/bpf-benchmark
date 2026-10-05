# ARM64 Micro Eval Smoke - 2026-03-19

## Scope

Goal: get `micro_exec` smoke running on ARM64 in QEMU with the framework kernel, then verify both stock kernel execution and `BPF_PROG_JIT_RECOMPILE` from the micro path.

Constraints followed:

- no kernel code changes
- no commit
- no branch creation

## Summary

Status: ARM64 micro smoke now runs end-to-end in QEMU.

What works:

- ARM64 `micro_exec` cross-build with kernel runtime only
- existing `micro/programs/*.bpf.o` objects on ARM64
- stock kernel micro runs in ARM64 QEMU
- ARM64 live-program scan from `micro_exec`
- `BPF_PROG_JIT_RECOMPILE` from micro for at least `COND_SELECT` and `ROTATE`

Important finding:

- the userspace policy blob builder was hardcoded to `BPF_JIT_ARCH_X86_64`
- ARM64 kernel correctly rejected those blobs with `EINVAL`
- fixing the blob header arch id in userspace unblocked ARM64 micro recompile smoke

Current performance outcome:

- correctness looked good in smoke runs
- performance was strongly negative for the tested ARM64 recompile cases
- this report does not root-cause that regression; it only establishes working smoke

## Build Path

### 1. ARM64 cross-build image

Rebuilt the existing ARM64 cross-build image after adding missing packages needed by `micro_exec`:

- `cmake`
- `g++-aarch64-linux-gnu`
- `libyaml-cpp-dev:arm64`

### 2. ARM64 `micro_exec`

Built `micro_exec` in a separate tree with llvmbpf disabled:

```bash
docker run --rm --user "$(id -u):$(id -g)" \
  -e PKG_CONFIG_LIBDIR=/usr/lib/aarch64-linux-gnu/pkgconfig:/usr/share/pkgconfig \
  -e PKG_CONFIG_SYSROOT_DIR=/ \
  -e CMAKE_PREFIX_PATH=/usr/lib/aarch64-linux-gnu/cmake/yaml-cpp \
  -v "$PWD":/workspace \
  -w /workspace \
  bpf-benchmark-arm64-crossbuild:latest \
  bash -lc 'set -euxo pipefail;
    rm -rf /workspace/micro/build-arm64;
    make -C /workspace/micro \
      BUILD_DIR=/workspace/micro/build-arm64 \
      MICRO_EXEC_ENABLE_LLVMBPF=OFF \
      CC=aarch64-linux-gnu-gcc \
      CXX=aarch64-linux-gnu-g++ \
      AR=aarch64-linux-gnu-ar \
      micro_exec;
    mkdir -p /workspace/micro/build-arm64/lib;
    cp -L /usr/lib/aarch64-linux-gnu/libyaml-cpp.so.0.8 /workspace/micro/build-arm64/lib/;
    cp -L /usr/lib/aarch64-linux-gnu/libelf.so.1 /workspace/micro/build-arm64/lib/;
    cp -L /usr/lib/aarch64-linux-gnu/libz.so.1 /workspace/micro/build-arm64/lib/;
    cp -L /usr/lib/aarch64-linux-gnu/libzstd.so.1 /workspace/micro/build-arm64/lib/;
    cp -L /usr/lib/aarch64-linux-gnu/libstdc++.so.6 /workspace/micro/build-arm64/lib/;
    cp -L /usr/lib/aarch64-linux-gnu/libgcc_s.so.1 /workspace/micro/build-arm64/lib/;'
```

Result:

- `micro/build-arm64/runner/micro_exec` is an ARM64 PIE executable
- runtime libraries were staged under `micro/build-arm64/lib/`

### 3. BPF programs

The BPF programs are architecture-independent for this step and were already available under:

```text
micro/programs/*.bpf.o
```

These worked on ARM64 in the smoke runs below.

## QEMU Guest Setup

Booted the existing ARM64 QEMU environment using the existing smoke path:

- kernel image: `vendor/linux-framework/arch/arm64/boot/Image`
- BTF source used by micro: `vendor/linux-framework/build-arm64/vmlinux`
- host share mounted in guest at `/mnt`

Inside the guest:

```bash
mkdir -p /tmp/micro/lib
cp /mnt/micro/build-arm64/runner/micro_exec /tmp/micro/micro_exec
cp /mnt/micro/build-arm64/lib/* /tmp/micro/lib/
export LD_LIBRARY_PATH=/tmp/micro/lib
```

Important detail:

- the tested benchmarks here needed `--io-mode staged`
- without it, `simple` failed with `required result_map not found`

## ARM64 Recompile Bug Found

Root cause of initial ARM64 recompile failure:

- micro stock execution worked
- micro recompile path failed with `BPF_PROG_JIT_RECOMPILE -> EINVAL`
- the policy blob emitted by userspace used `BPF_JIT_ARCH_X86_64` unconditionally
- ARM64 kernel rejected the blob as intended

Userspace-side fix:

- add `BPF_JIT_ARCH_ARM64`
- emit ARM64 arch id from `build_policy_blob_v5()` when compiled on `__aarch64__`

No kernel code was modified.

## Smoke Commands

### Stock kernel run

```bash
LD_LIBRARY_PATH=/tmp/micro/lib /tmp/micro/micro_exec run-kernel \
  --io-mode staged \
  --btf-custom-path /mnt/vendor/linux-framework/build-arm64/vmlinux \
  --program /mnt/micro/programs/simple.bpf.o \
  --memory /mnt/micro/generated-inputs/simple.mem \
  --repeat 10 --warmup 0
```

### Recompile smoke

```bash
LD_LIBRARY_PATH=/tmp/micro/lib /tmp/micro/micro_exec run-kernel \
  --io-mode staged \
  --btf-custom-path /mnt/vendor/linux-framework/build-arm64/vmlinux \
  --program /mnt/micro/programs/cmov_dense.bpf.o \
  --memory /mnt/micro/generated-inputs/cmov_dense.mem \
  --repeat 10 --warmup 0 \
  --recompile-cmov
```

```bash
LD_LIBRARY_PATH=/tmp/micro/lib /tmp/micro/micro_exec run-kernel \
  --io-mode staged \
  --btf-custom-path /mnt/vendor/linux-framework/build-arm64/vmlinux \
  --program /mnt/micro/programs/rotate_dense.bpf.o \
  --memory /mnt/micro/generated-inputs/rotate_dense.mem \
  --repeat 10 --warmup 0 \
  --recompile-rotate
```

## Results

These are smoke numbers only. They are useful for "works / does not work" and correctness checks, not for performance claims.

| Benchmark | Mode | Recompile applied | Key scan result | Result value | Stock ns | Exec ns |
| --- | --- | --- | --- | --- | ---: | ---: |
| `simple` | stock | no | n/a | `12345678` | n/a | `352` |
| `simple` | `--recompile-all` | no | 0 eligible sites | `12345678` | `248` | `254` |
| `cmov_dense` | stock | no | n/a | `15544056576594566652` | n/a | `483` |
| `cmov_dense` | `--recompile-cmov` | yes | 32 cmov sites | `15544056576594566652` | `419` | `27435` |
| `rotate_dense` | stock | no | n/a | `14870098989209412331` | n/a | `601` |
| `rotate_dense` | `--recompile-rotate` | yes | 256 rotate sites | `14870098989209412331` | `553` | `76721` |

Additional policy-file checks also worked:

| Benchmark | Policy file | Recompile applied | Notes |
| --- | --- | --- | --- |
| `cmov_dense` | `micro/policies/cmov_dense.yaml` | yes | result matched stock; 26 rotate sites in that policy path |
| `rotate_dense` | `micro/policies/rotate_dense.yaml` | yes | result matched stock; 256 rotate sites |

## Interpretation

ARM64 micro smoke is operational in QEMU:

- ARM64 `micro_exec` runs
- ARM64 stock kernel path runs
- ARM64 micro scanner can find rewrite sites
- ARM64 `BPF_PROG_JIT_RECOMPILE` can be applied from micro
- tested results matched stock values in the smoke cases above

However, ARM64 BpfReJIT performance is currently much worse than stock on the tested examples:

- `cmov_dense`: about `419 ns -> 27.4 us`
- `rotate_dense`: about `553 ns -> 76.7 us`

That needs separate investigation before treating ARM64 recompile numbers as meaningful benchmark results.

## Outcome

The requested smoke milestone is complete:

- ARM64 micro benchmark smoke runs in QEMU
- stock kernel and kernel-recompile paths both execute
- representative benchmarks `simple`, `cmov_dense`, and `rotate_dense` were exercised
- one ARM64 userspace compatibility bug was fixed without touching kernel code
