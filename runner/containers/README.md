# Runner Container Images

This directory holds repository-owned container definitions for benchmark build
and run images.

Current policy:

1. Build containers are the canonical place for userspace compilation
   dependencies.
2. VM or AWS hosts own the kernel and host privileges.
3. Runtime containers should own userspace runtime dependencies whenever an app
   can run that way.
4. Make remains the only build entrypoint; containers are implementation
   details used by Make targets.

Image families:

- `runner-build.Dockerfile`
  Canonical build image for runner, daemon, kernel/modules, workload tools, and
  native repo artifacts. Make builds the same Dockerfile for `linux/amd64` and
  `linux/arm64`; ARM64 runs as a native ARM64 container rather than relying on
  a host-installed ARM64 sysroot.
- future `*-runtime.Dockerfile`
  Will carry app userspace dependencies for privileged host-kernel execution.

The long-term goal is to shrink `runner/mk/build.mk` until it mostly dispatches
into app-native build commands inside these fixed images.
