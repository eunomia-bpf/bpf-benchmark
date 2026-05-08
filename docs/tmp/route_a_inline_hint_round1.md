# Route A inline hint round 1

Date: 2026-05-08

Implemented katran map_inline Route A in `bpfopt`: a repeated global
`--inline-hint <prog_id>:<call_pc>:<hex_key_bytes>` flag. The hint bypasses
only verifier-guided key reconstruction; snapshot lookup, fixed-load
classification, rewrite assembly, branch fixup, BTF remap, and ReJIT
verification remain on the existing path. No daemon, runner Python, or kernel
files were changed.

## Code changes

- `bpfopt/crates/bpfopt/src/pass.rs:117,294`: added and initialized
  `BpfProgram::map_inline_hints: HashMap<usize, Vec<u8>>`.
- `bpfopt/crates/bpfopt/src/main.rs:114`: added `--prog-id`.
- `bpfopt/crates/bpfopt/src/main.rs:117`: added repeated `--inline-hint`.
- `bpfopt/crates/bpfopt/src/main.rs:513`: attaches parsed hint inputs to
  `BpfProgram`.
- `bpfopt/crates/bpfopt/src/main.rs:532`: parses hints into `Vec<InlineHint>`,
  validates `hint.prog_id == --prog-id`, rejects duplicates, and decodes even
  length hex.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:43,120,445`: `--map-ids` now
  accepts either CSV or a `prog_info.json` file with `map_ids`.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1209`: validates every hint PC
  points at a `bpf_map_lookup_elem` helper call.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1286`: emits
  `inline_hints_consumed=N` when hints are present.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1450,1742`: consumes hint key
  bytes before verifier-guided extraction and propagates fatal hint contract
  errors instead of downgrading them to normal key-unavailable skips.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2201`: threads hint accounting
  through map-in-map key extraction as well.

## Tests

- `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:383`
  `map_inline_consumes_hint_when_verifier_state_unavailable`
  - Bug caught: a valid operator hint was ignored when verifier stack state was
    absent.
- `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:412`
  `map_inline_rejects_hint_with_wrong_key_size`
  - Bug caught: stale or malformed hint bytes were downgraded to a normal
    key-extraction skip.
- `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:436`
  `map_inline_rejects_hint_pointing_at_non_lookup_call`
  - Bug caught: a typo in `call_pc` could silently leave an operator hint unused.
- `bpfopt/crates/bpfopt/tests/cli_pipeline.rs:435`
  `map_inline_accepts_prog_info_json_for_map_ids`: keeps the documented host
  command shape working with `--map-ids <prog_info.json>`.

Verification:

- `cargo test --manifest-path bpfopt/Cargo.toml -p bpfopt hint -- --nocapture`
  - 3 passed.
- `cargo test --manifest-path bpfopt/Cargo.toml -p bpfopt map_inline -- --nocapture`
  - 63 lib tests plus 2 CLI filtered tests passed.
- `cargo test --manifest-path bpfopt/Cargo.toml -p bpfopt`
  - 305 lib tests, 9 main tests, 11 CLI tests passed.
- `cargo build --manifest-path bpfopt/Cargo.toml -p bpfopt --release`
  - succeeded.

## Host Artifact

Fresh result dir inspected:
`corpus/results/x86_kvm_corpus_20260508_213022_786370`.

`details/progress.json` says the run completed. The katran program is prog id
`9`, app JSON name `balancer_ingress`, metadata name `balancer_ingres`.

The artifact did not contain expanded `details/workdirs/<id>/` or
`verifier_log_step1.log`; it retained `details/failure-artifacts/9.tar.gz`
with `input_step0.bin`, `output_step0.bin`, `captured-input-noop.bin`,
`report_step0.json`, and `map-values/`.

For host validation I extracted the tarball to `/tmp/route_a_inline_hint_workdir`,
used `output_step0.bin` as the map_inline input-equivalent after noop, used the
captured `map-values/`, and reconstructed `prog_info.json` with map ids in
daemon snapshot order:
`[3,5,7,6,13,18,9,20,4,10,8,12,11,16]`.

Because the fresh artifact had no verifier log, I used a minimal parseable
verifier-state JSON with no call-PC snapshots. This proves Route A because the
baseline verifier-guided path cannot reconstruct any key.

## Host Results

Baseline output: `/tmp/route_a_inline_hint_workdir/r-baseline-json.json`
- `sites_applied`: `0`
- `sites_matched`: `14`
- `sites_skipped`: `14`
- dominant skip: `lookup key is not available from verifier-guided state`

With hint output: `/tmp/route_a_inline_hint_workdir/r-hint-json.json`
- hints: `9:1105:00000000`, `9:1807:00000000`
- `sites_applied`: `2`
- diagnostics includes `inline_hints_consumed=2`
- successful entries: two `map_id=4`, `key_hex=00000000`,
  `value_hex=02000000000b0000`

The two applied sites are the expected katran `ctl_array[0]` lookups at PCs
`1105` and `1807`.

## Other Paths

In this host-side run, no verifier-state helper lookup path applied: the
minimal verifier-state file intentionally has no call-PC snapshots, and the
baseline report has `sites_applied=0`.

No direct pseudo-map-value path applied either: the baseline report has no
`inlined_map_entries`, and the hinted report records only the two `ctl_array`
entries from Route A.
