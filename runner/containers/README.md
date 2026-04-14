# Runner Container Image

This directory holds the repository-owned runner image definition.

Current policy:

1. `runner-runtime.Dockerfile` is the only first-class runner image.
2. The Dockerfile owns the user-space build graph.
3. The Dockerfile copies the repository into the host checkout path inside the
   image and calls `make image-userspace-artifacts BPFREJIT_IMAGE_BUILD=1`.
4. `runner/mk/build.mk` keeps the outer host entrypoints for `docker build`,
   `docker save`, and host-coupled kernel/module export.
5. The image-side Make rules in `runner/mk/build.mk` use normal local build
   commands. They must not call Docker or Podman.
6. Host-coupled kernel/module artifacts are exported through
   `docker build --target runner-host-artifacts --output`, not built by
   `docker run`.
7. Runtime containers use the image workspace directly. They must not
   bind-mount the host repository over that path.
8. Remote runners load and run this image directly; they do not rsync suite
   source trees as a container launcher.

The old split between a standalone build image and a runtime image is removed.
There is no separate `runner-build.Dockerfile`, and bpftrace no longer has a
separate first-class static build image in this pipeline.
