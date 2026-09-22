# Changelog / artifact version record

All notable changes to this artifact are recorded here. Versions are marked in
git; the archival release for artifact evaluation is tagged
`atc26-ae-<version>`.

## atc26-ae-1 (2026-09-22)

Artifact-evaluation release for the accepted ATC 2026 paper
**"BPF-Ext: Safely Extending the eBPF Compilation Pipeline with Native
Operations"** (accepted paper #1160).

Artifact entry point: [`docs/atc26-artifact-evaluation.md`](docs/atc26-artifact-evaluation.md).

Added for artifact evaluation:

- `LICENSE` — MIT for repository-original material, with the third-party scope
  stated explicitly.
- `THIRD_PARTY_NOTICES.md` — exact pinned revision and license of every
  submodule and vendored application.
- `docs/atc26-artifact-evaluation.md` — evaluator guide: environment, resources,
  safety warnings, no-VM fast path, KVM paths, per-claim command mapping,
  expected outputs, raw-result locations, idempotence and failure recovery,
  recommended badges, and the author/legal items that remain external.
- `CITATION.cff`, `.zenodo.json`, and `docs/artifacts/package-atc26.sh` --
  citation/deposit metadata and the single-ZIP archive/manifest/checksum procedure.
  The archive embeds every required direct and nested submodule at its exact pin.
- `docs/artifacts/render_claim_table.py` and
  `docs/artifacts/evidence/` -- JSON-derived claim checks plus retained,
  hash-bound formal and KVM evidence. An exit-zero, log-hash-bound receipt is
  required before a fresh KVM smoke can report PASS.

Optimizer fixes verified during artifact preparation (both with measured
evidence recorded in `docs/tmp/20260906-bpf-development-todo.md`):

- `bpfopt`: probe `bpf_x86_movw` so 2-byte memcpy stores lower, instead of
  failing the whole `kop` step with `target.json has no kop entry`.
- `vendor/llvmbpf`: compute kernel stack bytes from the deepest accessed byte.
  The previous `(-off) + width - 1` overcount rejected programs whose deepest
  access is exactly at `-512`.
- `runner/mk/build.mk`: link x86 `bpfopt` against the patched in-repo kop LLVM,
  bind x86 native BPF artifacts to the framework kernel BTF, avoid duplicate
  kernel builds in one runtime-image DAG, and stage serial `modules_install`
  output on the container-local filesystem before copying it to a FUSE-backed
  Workspace.

Measured on the preparation machine (raw counters only; not a claim that the
paper's Xeon/AWS numbers were re-measured):

- Full 6-app default corpus run `corpus/results/x86_kvm_corpus_20260921_211712_637406`:
  all six ReJIT results report `ok`, but the suite status is `error` because the
  Tracee workload failed to launch. This is KOperation coverage evidence only;
  it is not evidence of full workload success.
- Fresh Katran KVM smoke `corpus/results/x86_kvm_corpus_20260922_213414_889964`:
  exact documented command exited 0 in 5,946 seconds; suite `completed`, app
  `ok`, and ReJIT `ok`. The retained receipt binds commit, log and JSON files
  by SHA256.
- `make -C native-sim/formal check`: exit 0 (generated-contract drift checks,
  Lean modules, 25 C host cross-checks).
- `make -C native-sim/x86 micro-proofs-build`: 30/30 OK.
