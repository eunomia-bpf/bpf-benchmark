# P89H Validate Report

Date: 2026-04-30

Validated tree: `1d619c17 fix(kinsn): validate tail-call-sensitive sites`

Corpus input: `corpus/results/x86_kvm_p89_kinsn_corpus_20260430_131403_981524`

Scope: host-only validation. No KVM run was started. No source code was edited by this validation task.

## Stage 1: cargo build + unit tests

The repository root has no `Cargo.toml`, so the literal root-level `cargo build ...` exits `101`. The same package set was rebuilt from the actual Rust workspace at `bpfopt/` and passed.

| Round | Passed | Failed | Exit |
|---:|---:|---:|---:|
| 1 | 418 | 0 | 0 |
| 2 | 418 | 0 | 0 |
| 3 | 418 | 0 | 0 |
| 4 | 418 | 0 | 0 |
| 5 | 418 | 0 | 0 |

Artifacts:

- `docs/tmp/p89h_validate_build.log`
- `docs/tmp/p89h_validate_cargo_round_1.log` through `docs/tmp/p89h_validate_cargo_round_5.log`

## Stage 2: host bpfopt replay

`docs/tmp/p89h_reproduce.sh` currently accepts one failure directory at a time; it does not implement the `--all` or `--output` interface shown in the task prompt. I used a wrapper loop around the current script and wrote normalized TSV output to the requested round files.

Coverage per round:

- `kinsn5`: 81/81 programs succeeded with `bulk_memory,rotate,cond_select,extract,endian_fusion`.
- `default11`: 11/81 programs succeeded.
- `default11`: 70/81 programs failed fast in `map_inline` because the saved failure workdirs do not contain concrete map-value snapshots. `map_fds.json` has map metadata, but not the map entries required by default-pipeline `map_inline`.

Round-to-round deterministic diff:

| Diff | Lines |
|---|---:|
| round 1 vs 2 | 0 |
| round 1 vs 3 | 0 |
| round 1 vs 4 | 0 |
| round 1 vs 5 | 0 |

Artifacts:

- `docs/tmp/p89h_validate_replay_round_1.tsv` through `docs/tmp/p89h_validate_replay_round_5.tsv`
- `docs/tmp/p89h_validate_replay_diff_round_1_vs_2.diff` through `docs/tmp/p89h_validate_replay_diff_round_1_vs_5.diff`
- `docs/tmp/p89h_validate_replay_default11_failures.tsv`
- `docs/tmp/p89h_validate_replay_round_1.log` through `docs/tmp/p89h_validate_replay_round_5.log`

## Stage 3: host bpfverify dry run

Host-verifiable subset: 0/81.

All 81 saved failure programs have non-empty `prog_info.json.map_ids`, so `bpfverify --map-fds` would need to reopen guest map IDs as host live map FDs. That is not host-verifiable from the saved corpus artifacts. The 5 bpfverify round files are therefore header-only and document the empty executable subset.

Accepted ratio: N/A (`0/0` host-verifiable programs).

KVM smoke fallback targets: all 81 programs listed in `docs/tmp/p89h_validate_bpfverify_candidates.tsv`.

Artifacts:

- `docs/tmp/p89h_validate_bpfverify_candidates.tsv`
- `docs/tmp/p89h_validate_bpfverify_round_1.tsv` through `docs/tmp/p89h_validate_bpfverify_round_5.tsv`

## Stage 4: micro baseline and kinsn coverage

Host micro baseline, direct driver, `simple`, 5 measured samples, `inner_repeat=10`:

| Runtime | Count | Min ns | Median ns | Max ns |
|---|---:|---:|---:|---:|
| llvmbpf | 5 | 16 | 35 | 85 |
| kernel | 5 | 24 | 27 | 55 |

No baseline regression was observed against the recent local result scale (`simple` medians in recent `micro/results/x86_kvm_micro_*` runs were llvmbpf 27-52 ns and kernel 35-112 ns). This host run emitted environment warnings for powersave governor, turbo enabled, `perf_event_paranoid=2`, and no CPU affinity, so it is a smoke/stability check, not an authoritative performance run.

Post-ReJIT micro performance was not host-runnable here: the current direct `micro/driver.py` exposes `llvmbpf` and `kernel` runtimes only, and this host is `6.15.11-061511-generic`, not the ReJIT fork kernel. No KVM fallback was used.

Offline bpfopt coverage on dumped host xlated micro bytecode:

| Pass | Sites applied | Micro programs with sites |
|---|---:|---|
| `bulk_memory` | 0 | none |
| `cond_select` | 0 | none |
| `endian_fusion` | 256 | `endian_swap_dense` |
| `extract` | 524 | `bounds_check_heavy`, `mixed_alu_mem`, `bitfield_extract`, `extract_dense` |
| `rotate` | 701 | 15 programs including `rotate_dense`, `rotate64_hash`, `mega_basic_block_2048` |

Artifacts:

- `docs/tmp/p89h_validate_micro_baseline.log`
- `docs/tmp/p89h_validate_micro_baseline_20260430_191348_749824/metadata.json`
- `docs/tmp/p89h_validate_micro_bench_specs.tsv`
- `docs/tmp/p89h_validate_micro_all_kinsns_target.json`
- `docs/tmp/p89h_validate_micro_kinsn_apply.tsv`
- `docs/tmp/p89h_validate_micro_kinsn_apply.log`

## Stage 5: skip-residue grep

Required grep returned matches only for the site-level helper `kinsn_replacement_subprog_skip_reason` and its call sites/tests:

- `bulk_memory.rs`, `cond_select.rs`, `endian.rs`, `extract.rs`, `rotate.rs`
- `utils.rs`

No `func_info_record_count > 1`, `num_subprogs > 1`, `nr_func_info > 1`, or equivalent program-wide multi-subprog pass skip was found by the required grep.

Artifact:

- `docs/tmp/p89h_validate_skip_grep.log`

## Findings

Bug count: 0 transform nondeterminism bugs found.

Validation gaps / follow-up defects:

1. Medium: default 11-pass host replay is blocked for 70/81 saved failure programs because the saved corpus failure workdirs lack concrete map-value snapshots needed by `map_inline`. Fix suggestion: preserve `map-values.json` and verifier-states side inputs in failure workdirs for default-pipeline host replay.
2. Medium: host-only `bpfverify` dry run has 0 executable programs because every saved failure requires guest map FD replay. Fix suggestion: preserve a host-replayable verifier fixture or run these 81 in KVM smoke.
3. Medium: current micro suite does not provide host xlated candidates for `bulk_memory` or `cond_select`, so it cannot prove wins for all five kinsn passes. Fix suggestion: add dedicated micro programs that compile to packed-compatible cond-select diamonds and scalarized bulk memory store/load sequences.
4. Medium: direct host micro driver cannot run post-ReJIT performance on this host kernel. Fix suggestion: use the ReJIT fork kernel/KVM for post-ReJIT micro performance, or add a host driver mode that explicitly reports unsupported ReJIT capability before benchmarking.

Overall result:

- Cargo/unit tests: pass, deterministic, 5/5 rounds.
- Host `kinsn5` bpfopt replay: pass, deterministic, 5/5 rounds.
- Host `default11` replay: deterministic, but incomplete due missing map snapshots.
- Host bpfverify: no host-verifiable subset in this corpus.
- Micro baseline: no smoke regression observed.
- Program-wide skip residue: none found by required grep.
