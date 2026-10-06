# GHCR Push Result

Date: 2026-04-30 23:11 PDT.

## Outcome

No image was pushed successfully.

The first push attempt failed immediately:

```text
docker push ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:x86_64
denied: permission_denied: The token provided does not match expected scopes.
```

Per the task instruction, the push flow stopped after the GHCR permission
failure. I did not try to work around the token problem.

## Tags From `build.mk`

Expanded values:

- `GHCR_IMAGE_PREFIX`: `ghcr.io/eunomia-bpf`
- `X86_KATRAN_ARTIFACTS_GHCR_IMAGE`: `ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:x86_64`
- `ARM64_KATRAN_ARTIFACTS_GHCR_IMAGE`: `ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:arm64`
- `X86_KERNEL_FORK_GHCR_IMAGE`: `ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:x86_64-ff4e136`
- `ARM64_KERNEL_FORK_GHCR_IMAGE`: `ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:arm64-ff4e136`

## Local Images Found

Push candidates present on the host:

| Local image | GHCR target | Arch | Size | Local image ID |
| --- | --- | --- | ---: | --- |
| `bpf-benchmark/katran-artifacts:x86_64` | `ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:x86_64` | `amd64/linux` | 378,264,061 bytes | `sha256:33b8f30d5942af1dbf8bad1bcbf873bce984094ba64bff2a97c688d59a345fe1` |
| `bpf-benchmark/katran-artifacts:arm64` | `ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:arm64` | `arm64/linux` | 889,911,118 bytes | `sha256:c844eec7e334cf86393e165de0c63c580977afd050f5a5d89473e1e7f8fbd4b7` |
| `bpf-benchmark/kernel-fork:x86_64-ff4e136` | `ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:x86_64-ff4e136` | `amd64/linux` | 2,058,296,869 bytes | `sha256:e33c7ac88b7b70670ea1e54887607cb86705baaa87bc90cc99c8589b60bb8dcd` |

Other related local tags:

- `bpf-benchmark/kernel-fork:x86_64-a1b8bad`
- `ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:x86_64-a1b8bad`
- `ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:x86_64-ff4e136`
- `ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:x86_64`
- `ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:arm64`

No local `bpf-benchmark/kernel-fork:arm64-ff4e136` image was present, so no
arm64 kernel-fork push was attempted.

Registry digests are unavailable because GHCR rejected the push before any
remote manifest was published.

## Auth State

Docker config contains a `ghcr.io` auth entry, so the failed push used the
existing Docker credential.

`gh auth status -h github.com` reports account `yunwei37`, but the active token
scopes are only:

```text
gist, read:org, repo, workflow
```

The token is missing `read:packages` and `write:packages`, matching the GHCR
push failure.

## Required User Action

Refresh the GitHub CLI token with package scopes, then log Docker into GHCR
with that token:

```bash
gh auth refresh -h github.com -s 'read:packages,write:packages,delete:packages'
gh auth token | docker login ghcr.io -u yunwei37 --password-stdin
```

After that, rerun the push commands:

```bash
docker push ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:x86_64
docker push ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:arm64
docker push ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:x86_64-ff4e136
```

If `bpf-benchmark/kernel-fork:arm64-ff4e136` later exists locally, also run:

```bash
docker tag bpf-benchmark/kernel-fork:arm64-ff4e136 ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:arm64-ff4e136
docker push ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:arm64-ff4e136
```

## Verification Status

Pull verification was not run because no image was pushed successfully.

I also did not run `docker rmi`: the task notes say not to remove any images
while the host `vm-corpus` round is running. After auth is fixed and push
succeeds, verification can be done without deleting local tags:

```bash
docker manifest inspect ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:x86_64 >/dev/null
docker manifest inspect ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:arm64 >/dev/null
docker manifest inspect ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:x86_64-ff4e136 >/dev/null
```

Or, to exercise the exact pull path used by `build.mk`:

```bash
docker pull --platform linux/amd64 ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:x86_64
docker pull --platform linux/arm64 ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:arm64
docker pull --platform linux/amd64 ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:x86_64-ff4e136
```

## Commands Intentionally Not Run

- `make vm-corpus`
- `make vm-e2e`
- `make vm-micro`
- `docker prune`
- `docker rmi`

## Maintenance Suggestions

- Add a manual GitHub Actions workflow that builds or loads these image tags and
  pushes them to GHCR using `GITHUB_TOKEN` with `packages: write`.
- Keep kernel-fork tags commit-addressed, as `build.mk` already does.
- Keep katran-artifacts tags architecture-addressed unless Katran source inputs
  become frequent enough to require source-hash tags.
- Add a lightweight CI check that runs `docker manifest inspect` for the four
  `build.mk` GHCR tags before authoritative benchmark runs.
