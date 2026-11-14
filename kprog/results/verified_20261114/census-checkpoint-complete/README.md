Complete resident replay checkpoint
==================================

`receipt.json` records every input journal and retained request archive. The
base journal has 30 attempts; the three complete checkpoint journals add 9, 7
and 4 attempts. `outcomes.jsonl` contains all 50 rows, including retries and
their original diagnostics. Latest verdicts use service completion time and
the pair (application, body group), giving 45 distinct bodies.

| Application | Resident bodies replayed | Verified and installed | Native workload run |
| --- | ---: | ---: | ---: |
| BCC | 9 | 9 | 0 |
| Katran | 0 | 0 | 0 |
| Cilium | 0 | 0 | 0 |
| OTel | 0 | 0 | 0 |
| Tetragon | 6 | 2 | 0 |
| Tracee | 30 | 10 | 0 |

These are load-only resident replays, not whole-application startup coverage.
Latest results include 20 verifier refusals and 4 compilation failures. No
application workload execution is claimed.

All 20 new request archives are retained in full. One byte-identical archive
already published in the parent directory is referenced by path and SHA256.
For each other request, concatenate the `parts` in receipt order to recover
the original `.tar.gz`; verify its original `sha256` and `bytes`. Individual
parts are at most 40 MiB to fit GitHub's file-size constraint. The complete
original archives and checkpoint state remain under `/workspaces/kprog-raw/`.

Reproduction (fresh output and publication directories are required):

```
make -C kprog/libnativeloader resident-census-publish \
  CENSUS_PUBLISH_OUTPUT=/workspaces/kprog-raw/verified/NEW-publication \
  CENSUS_PUBLISH_DESTINATION=/workspaces/repository/kprog/results/NEW-publication
```

Executed from commit `dcfce1d50`: `resident-census-publish-test` passed the
retry/cross-application identity and byte-exact archive reuse/reconstruction
regression; `resident-census-publish` completed with exit 0. The collector
does not use or mutate the shared kernel, base, image or benchmark settings.
