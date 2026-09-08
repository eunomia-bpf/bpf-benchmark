# bpf-benchmark devcontainer

This directory defines the project-owned development image and startup hook for
the BPF benchmark framework. The repository contract still applies: benchmark
runs use the root `make` targets, workloads and launch wiring stay frozen, and
git state is changed only with explicit authorization.

## Contents

- `Dockerfile` installs the host build toolchain, Docker CE, QEMU, static
  BusyBox for vng initramfs generation, `vng` and its bundled `virtme-run`
  runtime in one Python environment, udev for vng's virtio-serial I/O links,
  a tmpfiles implementation and rule for the root runtime directory exported into vng guests, Go,
  Rust, Lean's `elan` toolchain manager, and the AWS CLI. The base image is digest-pinned; direct tool downloads
  and Docker packages use explicit versions. GNU awk and the libbpf headers are
  included for the native-simulator proof build, `file` supports vendored
  application architecture checks, `pyelftools` binds native proof entries to
  their source BPF objects, and LLVM 18's tools plus CMake package metadata are
  available to the runner build. LLVM 18's bin directory is on `PATH` so the
  repository's unversioned tool names resolve. Ubuntu's native
  archive stanzas are restricted to `amd64`, while the separate ports stanza
  supplies the foreign `arm64` packages needed by `make aarch64-sysroot`.
- `devcontainer.json` uses the envbuilder-supported build, user, and lifecycle
  keys.
- `scripts/ensure-dockerd.sh` starts dockerd idempotently with ordinary Docker defaults, and
  reports Docker/KVM readiness without failing workspace startup.

Coder installs Codex and OpenCode outside this image and mounts their persistent
configuration and credentials. The image does not install another agent runner,
local-model server, or any credentials.

## Runtime requirements

The Coder template, rather than `devcontainer.json`, owns pod security, devices,
and Docker storage. A working workspace needs:

1. a privileged workspace pod so dockerd-in-Docker can start;
2. writable `/dev/kvm` passthrough for the local x86 KVM targets; and
3. workspace-local Docker storage with no size limit imposed by the template.

The `systems-dev docker-cache-20260908` rollout provides those requirements
without a host Docker-socket mount or a `devices.kubevirt.io/kvm` resource
request. `/var/lib/docker` is an uncapped `emptyDir`; the daemon uses its normal
storage-driver selection and other defaults.

After rebuild, check the environment with:

```console
docker info
test -w /dev/kvm
vng --version
```

If dockerd is unavailable, inspect `/var/log/dockerd.log` and rerun
`/usr/local/bin/ensure-dockerd.sh`. The hook intentionally exits successfully so
workspace creation remains usable while an infrastructure fault is diagnosed.

## Codex and OpenCode

The verified Codex backend model ID is `gpt-5.6-sol` (`gpt-5.6` is not accepted
by this CLI backend). Start the requested model, reasoning level, and full Agent
permission mode together from the repository:

```console
codex -C /workspaces/repository -m gpt-5.6-sol \
  -c model_reasoning_effort=high \
  --dangerously-bypass-approvals-and-sandbox
```

The existing OpenCode configuration already exposes the `spark-gateway` models;
no Ollama or LM Studio service is needed. Discover the configured names with
`opencode models spark-gateway`, then use one as an optional assistant, for
example:

```console
opencode run -m spark-gateway/glm-5.3-flash-nvfp4-dflash2-200k \
  "Review the scoped optimizer change; do not modify git state."
```

## Acceptance

Use the public project entrypoints and retain their result paths:

```console
make check
make selftest
make micro SAMPLES=1 WARMUPS=0 INNER_REPEAT=10
```

On 2026-09-08, the rebuilt Workspace passed a default-driver `docker run` and a
`KVM_CREATE_VM` probe. Project build and KVM-suite results should still be
recorded per invocation; infrastructure readiness alone is not a benchmark
result. The current research priorities and retained experiment evidence are in
[`docs/tmp/20260906-bpf-development-todo.md`](../docs/tmp/20260906-bpf-development-todo.md).
