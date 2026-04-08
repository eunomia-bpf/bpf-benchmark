# Runner Config

- `upstream_selftests_selection.tsv`
  - explicit, tracked upstream selftests build-selection contract
  - lists canonical make targets, build-view exclusions, and generated
    `vmlinux.h` exclusions with reasons
  - drives the temporary build view materialized by the Python build helper; it
    is not an in-place patch or delete layer against the upstream checkout
  - the build helper also writes `selection.json` into the output dir so the
    exact exclusion contract used for a given build is preserved with artifacts
  - `runner/libs/build_upstream_selftests.py` is the canonical consumer
