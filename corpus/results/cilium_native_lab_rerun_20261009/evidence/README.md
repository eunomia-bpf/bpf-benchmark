# Archived evidence

All evidence comes from the interrupted October 9 execution. No archived
launcher or analysis script was executed while recording it. Scripts and
image recipes are preserved verbatim with `.txt` suffixes as historical
evidence; they include superseded proposals as well as the primary tooling.
Copied raw text and CSV files retain their original whitespace/line endings.
`verification.json` records the offline counter, inventory, ratio, pinning
and documentation checks; its checker is archived as `scripts/verify-record.py.txt`.

- `analysis.json`, the CSV files and `supervisor/independent-*` retain the
  final saved analysis and independent arithmetic. Raw counters remain in
  `cases/<series>/<case>/raw/<run>/details/apps/cilium__agent.json`.
- `completion.json`, per-case commands/exits and guest-host snapshots record
  what actually ran. `unfinished-control/` preserves the original running
  metadata/progress rather than fabricating a final result.
- Per-case `observations.json` packages the original JSON snapshots as a
  mapping from relative source filename to parsed content, plus original
  text/stderr. `incomplete_json_files` preserves malformed/empty files as
  text. No partial snapshot is represented as a complete inventory.
- `host-load-boundaries.json` retains first/last host samples within each
  completed measurement snapshot window, including QEMU thread affinities
  and pod CPU counters. `host-load-by-pod.csv` retains the original analysis
  of all windows. Full two-second archives remain at their source locations.
- `supervisor/start.json` has an early, superseded pinning proposal.
  `original/metadata.json` and actual thread snapshots describe the mapping
  used in the completed measurements. Historical digests already present
  in copied evidence are preserved; none were recomputed for this record.
- `original/tables.md` is an unfinished, stale table rendering: it omits the
  current pair and predates the last stats-off control. Use `analysis.json`,
  the CSV files and `../findings.md` for completed counts and ratios. The
  original README also describes the planned five current pairs; they did
  not complete. Both files are retained as evidence, not final conclusions.
- `run-log-excerpts.txt` quotes selected lines after removing log NUL bytes;
  it is not the full execution log. Other `.log.txt` files retain the small
  series completion records.

[../retained-artifacts.csv](../retained-artifacts.csv) lists omitted logs,
archives and binary images by byte size and original location. This includes
the full execution log, native artifact tarballs, kernel build outputs and
per-program JIT/translated images. Empty size means that a reported build
path no longer existed at recording time. No source artifact was moved.
Sizes are observations at recording time; reusable build paths may have
changed since the measurement, and are not certified historical binaries.
Locations under `/tmp` may have been lost on reboot; paths are provenance,
not a guarantee of continued availability. The historical source checkout
remains `.../cilium-lab-20261009/paper-tree`; its ordinary repository content
is not duplicated here.
