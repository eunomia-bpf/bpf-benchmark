# Runner Container Image

This directory holds the repository-owned runner image definition.

Current policy:

1. `runner-runtime.Dockerfile` is the runtime image. `katran-artifacts.Dockerfile`
   is a precompiled artifact image consumed by the runtime build.
2. The Dockerfiles own the user-space build graph.
3. The runtime Dockerfile copies only the source groups needed by each layer:
   stable app artifacts, kernel/kinsn artifacts, bpftool and native C++/BPF/test
   artifacts, Rust daemon artifacts, then runtime Python/config/corpus/e2e data.
   Build-only make rules, source trees, Go/Rust toolchain files, and common
   CMake/Cargo/test intermediates are removed after their artifacts are produced.
4. `runner/mk/build.mk` keeps the outer host entrypoints for `docker build`,
   `docker save`, and host-coupled kernel/module export.
5. The image-side Make rules in `runner/mk/build.mk` use normal local build
   commands. They must not call Docker or Podman.
6. Host-coupled kernel/module artifacts are exported through
   `docker build --target runner-host-artifacts --output`, not built by
   `docker run`; the exported target is a scratch stage containing only
   `/image-output` contents.
7. AWS host kernel installation streams the exported kernel image and
   `/lib/modules` archive over SSH, extracts it on the target root, then runs
   the host's `depmod`, `dracut`, and `grubby` directly. It must not use a
   privileged container with the full host root bind-mounted.
8. Runtime containers use the image workspace directly. They must not
   bind-mount the host repository over that path.
9. Kinsn modules are inside the runner image. Runtime containers must not
   bind-mount host `module/` over the image workspace.
10. Remote runners load and run this image directly; they do not mirror suite
   source trees or require a directory-sync tool for result collection.

The old split between a standalone build image and a runtime image is removed.
There is no separate `runner-build.Dockerfile`, and bpftrace no longer has a
separate first-class static build image in this pipeline.
