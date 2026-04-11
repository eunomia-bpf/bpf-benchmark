# Runner Container Images

This directory holds repository-owned container definitions for benchmark build
and run images.

Current policy:

1. Build containers are the canonical place for userspace compilation
   dependencies.
2. VM or AWS hosts own the kernel and host privileges.
3. Runtime containers own suite orchestration, daemon/app loaders, workload
   tools, eBPF object consumption, and userspace runtime dependencies.
4. Make remains the only build entrypoint; containers are implementation
   details used by Make targets.

Image families:

- `runner-build.Dockerfile`
  Canonical build image for runner, daemon, kernel/modules, workload tools, and
  native repo artifacts other than bpftrace. Make builds the same Dockerfile
  for `linux/amd64` and `linux/arm64`; ARM64 runs as a native ARM64 container
  rather than relying on a host-installed ARM64 sysroot.
- `runner/repos/bpftrace/docker/Dockerfile.static`
  Upstream bpftrace static build image. Make builds it per target architecture
  and runs bpftrace's own CMake install target to produce a fully static
  `.cache/repo-artifacts/<arch>/bpftrace/bin/bpftrace`, avoiding runtime
  `bcc`/`clang`/`libpcap` packages and hand-copied shared libraries.
- `runner-runtime.Dockerfile`
  Canonical runtime image for privileged host-kernel execution. The host entry
  point loads this image and runs `suite_entrypoint.py` inside it with host PID
  and network namespaces, so attach logic sees the real loader PIDs.

`runner/mk/build.mk` is intentionally thin: it dispatches into app-native build
commands inside these fixed images and installs the resulting artifacts into
the cache paths consumed by target/suite contracts.
