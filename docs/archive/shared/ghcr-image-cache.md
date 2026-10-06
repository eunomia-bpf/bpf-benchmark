# GHCR Image Cache

The Docker build keeps local tags under `bpf-benchmark/*` and mirrors the slow,
stable artifact images to GHCR:

| Image | Local tag | GHCR tag |
| --- | --- | --- |
| Kernel fork artifacts | `bpf-benchmark/kernel-fork:<arch>-<kernel_commit>` | `ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:<arch>-<kernel_commit>` |
| Katran artifacts | `bpf-benchmark/katran-artifacts:<arch>` | `ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:<arch>` |

`bpf-benchmark/runner-runtime:<arch>` is intentionally not pushed to GHCR
because it changes whenever daemon, BPF optimizer, runner, Python, or benchmark
data changes.

## Login

Use a token with `write:packages` for pushes and `read:packages` for private
pulls.

```bash
gh auth token | docker login ghcr.io -u yunwei37 --password-stdin
```

With a GitHub Actions token:

```bash
printf '%s' "$GITHUB_TOKEN" | docker login ghcr.io -u "$GITHUB_ACTOR" --password-stdin
```

## Push

Push the current architecture artifacts after they have been built or pulled
locally:

```bash
make image-push-kernel-fork RUN_TARGET_ARCH=x86_64
make image-push-katran-artifacts RUN_TARGET_ARCH=x86_64

make image-push-kernel-fork RUN_TARGET_ARCH=arm64
make image-push-katran-artifacts RUN_TARGET_ARCH=arm64
```

The push targets preserve the local `bpf-benchmark/*` tags and add the matching
`ghcr.io/eunomia-bpf/*` tags before pushing.

## Pull-First Builds

`make image-kernel-fork-image-tar`, `make image-katran-artifacts-image-tar`, and
the higher-level `make image-runner-runtime-image-tar` targets try GHCR before
building:

1. `docker pull ghcr.io/eunomia-bpf/...:<tag>`
2. On success, tag the image back to the local `bpf-benchmark/*` name and save
   the tar artifact.
3. On pull failure, build locally, add the GHCR tag locally, and save the tar
   artifact.

ARM64 Katran pulls use `--platform linux/arm64`, so an x86_64 build host can
pull the ARM64 artifact tag without asking Docker for the host platform.

## Visibility

GHCR packages are private by default. Private packages require Docker login on
every machine that should pull them. Public packages can be pulled by cold AWS
builders without extra credentials.

After the first push, make the organization packages public when the cache
should be shared without login:

```bash
gh api -X PATCH /orgs/eunomia-bpf/packages/container/bpf-benchmark-kernel-fork/visibility -f visibility=public
gh api -X PATCH /orgs/eunomia-bpf/packages/container/bpf-benchmark-katran-artifacts/visibility -f visibility=public
```

Keep them private if access should stay limited to authenticated organization
users or CI jobs.
