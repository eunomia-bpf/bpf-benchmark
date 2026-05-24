# ARM64 LLVM Backend Notes

Date: 2026-05-23.

This directory contains repository-facing notes for the ARM64 LLVM backend
experiment cleanup before adding more kinsn families.

| Directory | Purpose |
|---|---|
| `experiment-matrix/` | Defines the validation matrix required for future ARM64 kinsn families and records current `REV` / `EXTR` coverage. |
| `per-family-attribution/` | Records the completed `REV-only` / `EXTR-only` performance attribution run. The first attempt hit an AWS session expiry before AMI resolution; after reauthentication, all four valid runs completed. |

The local experiment record is:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-23-arm64-rev-extr-performance-attribution
```
