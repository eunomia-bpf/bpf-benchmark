# P89 ARM64 GHCR Push

## Stage 1: ARM64 image wait

- Start: 2026-04-30T16:05:34-07:00
- End: 2026-04-30T17:35:39-07:00
- Elapsed: 5405 seconds (90m05s)
- Result: timed out before all required ARM64 images appeared.

Final local image state:

- Present: `bpf-benchmark/katran-artifacts:arm64`
  - Image ID: `c844eec7e334`
  - Full digest ID: `sha256:c844eec7e334cf86393e165de0c63c580977afd050f5a5d89473e1e7f8fbd4b7`
  - Size: 889911118 bytes
- Missing: `bpf-benchmark/runner-runtime:arm64`
- Missing: `bpf-benchmark/kernel-fork:arm64-a1b8bad`

No ARM64 image tar files were present under `.cache/container-images/`:

- Missing: `.cache/container-images/arm64-runner-runtime.image.tar`
- Missing: `.cache/container-images/arm64-katran-artifacts.image.tar`
- Missing: `.cache/container-images/arm64-kernel-fork-a1b8bad.image.tar`

The AWSARM64 codex process `1175356` had exited by the post-timeout check.

## Stage 2: GHCR push

GHCR login:

- Command: `gh auth token | docker login ghcr.io -u yunwei37 --password-stdin`
- Result: succeeded.

Kernel-fork push:

- Expected local image: `bpf-benchmark/kernel-fork:arm64-a1b8bad`
- Expected GHCR image: `ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:arm64-a1b8bad`
- Result: not executed.
- Reason: both the local image and tar were missing. Running `make image-push-kernel-fork RUN_TARGET_ARCH=arm64` in that state would fall through to `make image-kernel-fork-image-tar`, which can trigger an ARM64 rebuild.

Katran artifacts push:

- Local image: `bpf-benchmark/katran-artifacts:arm64`
- GHCR image: `ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:arm64`
- Command: `make image-push-katran-artifacts RUN_TARGET_ARCH=arm64`
- Result: failed.
- Error: `denied: permission_denied: The token provided does not match expected scopes.`

The active GitHub CLI token scopes were `gist`, `read:org`, `repo`, and `workflow`; `write:packages` was not present. No alternate GHCR token environment variable was available.

## Outcome

Completion criteria were not met:

- `ghcr.io/eunomia-bpf/bpf-benchmark-kernel-fork:arm64-a1b8bad` was not pushed.
- `ghcr.io/eunomia-bpf/bpf-benchmark-katran-artifacts:arm64` was not pushed.

No Dockerfile, runner Python, kinsn pass, or `vendor/linux-framework` files were modified by this task.
