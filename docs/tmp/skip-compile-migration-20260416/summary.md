# Skip-Compile Migration Summary

Date: 2026-04-16

## Inputs Verified

- Required plan read: `docs/kernel-jit-optimization-plan.md`.
- Ubuntu 24.04 apt policy was checked with:
  `docker run --rm ubuntu:24.04 bash -c "apt-get update >/dev/null && apt-cache policy sysbench wrk rt-tests bpfcc-tools python3-bpfcc bpftrace scx scx-tools"`.
- `apt-cache policy` returned candidates for `sysbench`, `wrk`, `rt-tests`, `bpfcc-tools`, `python3-bpfcc`, and `bpftrace`; it returned no candidate block for `scx` or `scx-tools`.
- `apt-cache search scx` on the host Ubuntu 24.04 package database returned Qt SCXML packages, not sched_ext `scx` scheduler packages. A Docker retry for that search timed out during `apt-get update`; the policy check above is the authoritative container result for this migration.
- Latest stable upstream releases were checked via GitHub release API:
  - Tracee: https://github.com/aquasecurity/tracee/releases/tag/v0.24.1
  - Tetragon: https://github.com/cilium/tetragon/releases/tag/v1.6.1

## Component Decisions

| Component | Final source | Version / tag | Runtime path decision |
|---|---|---:|---|
| sysbench | Ubuntu 24.04 apt | `1.0.20+ds-6build2` | Use `/usr/bin/sysbench`; no repo build. |
| wrk | Ubuntu 24.04 apt | `4.1.0-4build2` | Use `/usr/bin/wrk`; no repo build. |
| hackbench | Ubuntu 24.04 apt package `rt-tests` | `2.5-1` | Use `/usr/bin/hackbench`; no repo build. |
| BCC tools | Ubuntu 24.04 apt packages `bpfcc-tools python3-bpfcc` | `0.29.1+ds-1ubuntu7` | Runner resolves `<tool>-bpfcc` from PATH, e.g. `execsnoop-bpfcc`; no `runner/repos/bcc/libbpf-tools` build. |
| bpftrace | Ubuntu 24.04 apt | `0.20.2-1ubuntu4.3` | Runner already resolves `bpftrace` from PATH; artifact PATH entries removed from workspace layout. |
| SCX | No Ubuntu 24.04 `scx` / `scx-tools` candidate found | N/A | Runner resolves `scx_<scheduler>` from PATH and fails loudly if absent. No source fallback is retained. |
| Tracee | Upstream container image | `docker.io/aquasec/tracee:0.24.1` | Dockerfile patch copies `/tracee/tracee` and `/tracee/tracee-ebpf` into runtime artifacts. |
| Tetragon | Upstream container image | `quay.io/cilium/tetragon:v1.6.1` | Dockerfile patch copies `/usr/bin/tetragon` and `/var/lib/tetragon/*.o` into runtime artifacts. |
| Katran | Source build retained | current `runner/repos/katran` checkout | Required because no suitable FB release artifact is available. |

## Container Image Pins

Tracee:

- Tag: `docker.io/aquasec/tracee:0.24.1`
- Manifest-list digest: `sha256:cfbbfee972e64a644f6b1bac74ee26998e6e12442697be4c797ae563553a2a5b`
- `linux/amd64` digest: `sha256:9e9dd6024cdd9f792d5efeb6f0cfb2208b3102164f37712d4d55040e9e151206`
- `linux/arm64/v8` digest: `sha256:65df39d3ea1695d27c11a0c12f3e37a18944c54f9847765d89c4255b94ced4dd`

Tetragon:

- Tag: `quay.io/cilium/tetragon:v1.6.1`
- Manifest-list digest: `sha256:ff96ace3e6a0166ba04ff3eecfaeee19b7e6deee2b7cdbe3245feda57df5015f`
- `linux/amd64` digest: `sha256:7522b25373b5c2344a068bac3871457ab03cd51aebdde2d1b1b6d84b6d9f88ea`
- `linux/arm64` digest: `sha256:06e7d64ddd8e3ff17e21c6c55852eec483e8c17a6c413e0bd26f3803cd422158`

## Source Checkout Cleanup

The target `runner/repos/*` trees are ignored local checkouts, not tracked gitlinks in this repository, and there are no matching `.gitmodules` entries. `git submodule deinit` therefore reported pathspec misses for those paths, and `git rm --ignore-unmatch` had no index entries to remove. The ignored local checkout directories for BCC, bpftrace, SCX, Tracee, Tetragon, sysbench, wrk, and rt-tests were removed from the workspace.

## Paper Reproducibility Warnings

- BCC changes from repo-built libbpf-tools to distro `bpfcc-tools`. These are Python/BCC tools and may attach different program shapes or names than the previous libbpf-tools builds.
- Tracee and Tetragon now follow upstream release artifacts, not the historical source checkout at benchmark time. Their embedded BPF object sets may change relative to previous corpus/e2e measurements.
- Tracee `0.24.1` ships `/tracee/tracee` and `/tracee/tracee-ebpf`; no separate `tracee.bpf.o` files were found in the container image during inspection.
- Tetragon `v1.6.1` ships BPF objects under `/var/lib/tetragon/`; those are copied as runtime artifacts.
- SCX is the only unresolved apt packaging gap: Ubuntu 24.04 does not provide `scx` or `scx-tools` in the checked package set. The runner no longer builds SCX from source, so SCX benchmarks require an externally installed distro/upstream `scx_rusty` binary before they can run.
