# CI Monitoring Report

Generated at `2026-03-09T02:29:41Z` UTC.

## Scope

Monitored ARM64 benchmark workflow runs until one produced actual benchmark results on `main`.

## Final Status

ARM64 benchmark results were produced successfully by `ARM64 Benchmark` run `22835784942` on commit `d8edc80ff8690064ae99a7e38261b04f8f2a5817` at `2026-03-09T02:28:27Z` UTC.

## Run History

| Run ID | Head SHA | Created | Completed/Updated | Result | Notes |
| --- | --- | --- | --- | --- | --- |
| `22835367128` | `1c17332` | `2026-03-09T02:04:34Z` | `2026-03-09T02:13:47Z` | `success` | False green: workflow finished, but both benchmark suites failed with `llvmbpf packet buffer address exceeds 32-bit xdp_md range`; no result files were uploaded or committed. |
| `22835649757` | `d2bd851` | `2026-03-09T02:17:59Z` | `2026-03-09T02:20:59Z` | `failure` | `actions/checkout` was cancelled while cloning `vendor/linux`; benchmark code never ran. |
| `22835740878` | `d2bd851` | `2026-03-09T02:22:14Z` | `2026-03-09T02:24:53Z` | `cancelled` | Same transient checkout cancellation while cloning `vendor/linux`; benchmark code never ran. |
| `22835784942` | `d8edc80` | `2026-03-09T02:24:18Z` | `2026-03-09T02:28:28Z` | `success` | Produced benchmark output from both `llvmbpf` and `kernel`, uploaded 2 JSON result files, and skipped both kernel-only fallback steps because combined runs already wrote output. |
| `22835840553` | `d8edc80` | `2026-03-09T02:26:56Z` | `2026-03-09T02:29:41Z` | `cancelled` | Duplicate rerun cancelled after `22835784942` succeeded. |

## Actions Taken

- Confirmed that run `22835367128` was not sufficient despite its green conclusion, because logs showed no artifacts and no committed results.
- Fixed the ARM64 llvmbpf packet-buffer mapping issue in commit `d2bd851` (`Fix ARM64 llvmbpf low-address packet mapping`).
- Observed that `main` then advanced to `d8edc80` (`Fix ARM64 CI checkout and kernel fallback`), which removed recursive submodule checkout from `actions/checkout`, limited submodule sync/update to the required submodules, and switched fallback steps to kernel-only.
- Retried after two transient checkout cancellations on the older workflow revision.
- Verified in run `22835784942` logs that:
  - `Run pure JIT characterization with both runtimes` printed `llvmbpf` and `kernel` benchmark results and wrote `micro/results/arm64_pure_jit.json`.
  - `Run runtime suite with both runtimes` printed `llvmbpf` and `kernel` benchmark results and wrote `micro/results/arm64_runtime.json`.
  - `Upload benchmark artifacts` uploaded 2 files as artifact `arm64-benchmark-results` (artifact ID `5822238579`).
  - `Commit and push benchmark results` reported `nothing to commit, working tree clean` and `Everything up-to-date`, so no new result commit was pushed to `main`.

## Conclusion

ARM64 CI is now producing results on `main`. The critical fixes were:

- `d2bd851`: portable low-address packet mapping for llvmbpf on ARM64.
- `d8edc80`: more reliable ARM64 checkout/submodule handling and kernel-only fallback behavior.
