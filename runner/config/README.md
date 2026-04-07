# Runner Config

- `upstream_selftests_selection.tsv`
  - explicit, tracked upstream selftests build-selection contract
  - lists canonical make targets and source-level exclusions with reasons
  - drives the selected source view materialized by the build helper; it is not
    an in-place patch or delete layer against the upstream checkout
  - `runner/scripts/build_upstream_selftests.sh` consumes this file directly
