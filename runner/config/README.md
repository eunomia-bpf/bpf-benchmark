# Runner Config

- `upstream_selftests_selection.tsv`
  - explicit, tracked upstream selftests build-selection contract
  - lists canonical make targets and source-level exclusions with reasons
  - `runner/scripts/build_upstream_selftests.sh` consumes this file directly
