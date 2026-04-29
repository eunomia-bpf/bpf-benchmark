# Docker Cleanup 2026-04-28

## Scope

- Changed Docker state only: image tags/images and BuildKit cache.
- Did not edit code, Dockerfiles, Makefiles, or cargo target directories.
- Did not stop or remove containers.
- Did not remove third-party or base images with unclear ownership.

## Commands Run

- `docker ps --format 'table {{.ID}}\t{{.Image}}\t{{.Names}}\t{{.Status}}'`
- `docker images --digests --no-trunc --format 'table {{.Repository}}\t{{.Tag}}\t{{.ID}}\t{{.Digest}}\t{{.CreatedAt}}\t{{.Size}}'`
- `docker system df --verbose`
- `docker buildx du`
- `docker builder du`
- `docker image prune -f`
- `docker image rm bpf-benchmark/platform-arg-smoke:latest bpf-benchmark/katran-context-smoke:latest bpf-benchmark/katran-local-syntax-smoke:latest bpf-benchmark/katran-local-smoke:latest bpf-benchmark/katran-artifacts:review localhost/bpf-benchmark/katran-artifacts:arm64`
- `docker builder prune --filter until=72h -f`
- `docker builder prune --all --filter until=72h -f`
- `docker buildx prune --max-used-space 30gb -f`
- `docker system df`
- `docker ps -a --format 'table {{.ID}}\t{{.Image}}\t{{.Names}}\t{{.Status}}'`

`docker buildx` on this host does not provide `--keep-storage`; the equivalent cap is `--max-used-space`. The 72h prune commands reclaimed 0B, so the final cache cleanup used the conservative 30GB cap strategy.

## Disk Usage

| State | Images | Containers | Volumes | Build cache |
| --- | ---: | ---: | ---: | ---: |
| Before | 17 images, 29.2GB | 1 created, 0B | 5 volumes, 97.77MB | 1183 entries, 151.4GB |
| After | 12 images, 28.07GB | 1 created, 0B | 5 volumes, 97.77MB | 326 entries, 32.2GB |

Approximate reclaim from Docker accounting:

- Images: 29.2GB -> 28.07GB, about 1.13GB lower.
- Build cache: 151.4GB -> 32.2GB, about 119.2GB lower.
- Combined images + build cache: about 120.3GB lower.
- `docker buildx prune --max-used-space 30gb -f` reported `Total: 120.3GB`.

Buildx/builder cache summary:

| State | Shared | Private | Reclaimable | Total |
| --- | ---: | ---: | ---: | ---: |
| Before | 18.86GB | 151.4GB | 170.3GB | 170.3GB |
| After | 17.72GB | 32.2GB | 49.92GB | 49.92GB |

## Images Removed

Removed requested temporary smoke/review/duplicate images:

| Image tag | Result |
| --- | --- |
| `bpf-benchmark/platform-arg-smoke:latest` | Untagged and image ID deleted |
| `bpf-benchmark/katran-context-smoke:latest` | Untagged |
| `bpf-benchmark/katran-local-syntax-smoke:latest` | Untagged; shared image ID deleted after both tags removed |
| `bpf-benchmark/katran-local-smoke:latest` | Untagged and image ID deleted |
| `bpf-benchmark/katran-artifacts:review` | Untagged and image ID deleted |
| `localhost/bpf-benchmark/katran-artifacts:arm64` | Untagged and image ID deleted |

`docker image prune -f` reclaimed 0B because the dangling image is referenced by a non-running `Created` container:

| Container | Image | Name | Status |
| --- | --- | --- | --- |
| `b01a98ed7aa0` | `ba65c8b9d13c` | `youthful_cori` | `Created` |

That dangling image remains:

| Repository | Tag | Image ID | Created | Size |
| --- | --- | --- | --- | ---: |
| `<none>` | `<none>` | `sha256:ba65c8b9d13c039a00e699dd575b5e6ca7f440978e2d299275cab2013834f801` | 2026-04-27 13:29:47 -0700 | 3.58GB |

Removing it would require removing the `Created` container first. I left it untouched because the task did not authorize container deletion.

## Images Retained

| Image | Reason |
| --- | --- |
| `bpf-benchmark/runner-runtime:x86_64` | Latest x86_64 runner runtime, needed by next `vm-corpus` / AWS runs |
| `bpf-benchmark/runner-runtime:arm64` | Latest arm64 runner runtime, needed by next `vm-corpus` / AWS runs |
| `bpf-benchmark/katran-artifacts:x86_64` | Runner dependency |
| `bpf-benchmark/katran-artifacts:arm64` | Runner dependency |
| `ghcr.io/openclaw/openclaw:latest` | Not clearly this project; left for user confirmation |
| `ghcr.io/nvidia/nemoclaw/sandbox-base:latest` | Not clearly this project; left for user confirmation |
| `alpine:latest` | Base image |
| `ubuntu:24.04` | Base image |
| `busybox:latest` | Base image |
| `quay.io/cilium/cilium:v1.19.3` | Supported app/base asset |
| `quay.io/calico/node:v3.31.3` | Supported app/base asset |

After cleanup, the full image list is:

| Repository | Tag | Size |
| --- | --- | ---: |
| `bpf-benchmark/runner-runtime` | `x86_64` | 9.67GB |
| `bpf-benchmark/katran-artifacts` | `x86_64` | 378MB |
| `bpf-benchmark/runner-runtime` | `arm64` | 7.47GB |
| `bpf-benchmark/katran-artifacts` | `arm64` | 379MB |
| `<none>` | `<none>` | 3.58GB |
| `ghcr.io/openclaw/openclaw` | `latest` | 3.22GB |
| `ghcr.io/nvidia/nemoclaw/sandbox-base` | `latest` | 2.27GB |
| `alpine` | `latest` | 8.45MB |
| `quay.io/cilium/cilium` | `v1.19.3` | 749MB |
| `ubuntu` | `24.04` | 78.1MB |
| `quay.io/calico/node` | `v3.31.3` | 410MB |
| `busybox` | `latest` | 4.42MB |

## Verification

- Confirmed no running containers before cleanup.
- Confirmed the current runner-runtime and katran-artifacts tags remain after cleanup.
- Confirmed third-party `ghcr.io/openclaw/openclaw` and `ghcr.io/nvidia/nemoclaw/sandbox-base` were not removed.
- Did not run `make image-runner-runtime`; that would repopulate cache and could take a long build. Cache cleanup verification uses the prune output and post-cleanup `docker system df`.
