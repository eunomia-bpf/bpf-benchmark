# Corpus Coverage Fix And Rerun 2026-03-28

## Scope

- Goal: fix the corpus coverage bottlenecks that left only 170 / 2009 programs in the old headline geomean, rerun the full corpus, and restate the headline metric so it matches the true comparable set.
- Constraints followed:
  - no changes under `docs/paper/`
  - no changes under `vendor/linux-framework`
  - build and test only through `make <target>`

## Baseline Before Fixes

- Source of truth for the pre-fix partial run:
  - [`runner/corpus/results/vm_corpus_20260328_194356/metadata.json`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_194356/metadata.json)
  - [`docs/tmp/20260328/corpus_data_statistics_review_20260328.md`](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260328/corpus_data_statistics_review_20260328.md)
- Old funnel:
  - selected objects/programs: 469 / 2009
  - completed before crash: 288 objects / 1149 programs
  - compile pairs: 648
  - measured pairs: 483
  - numeric comparable pairs in old headline: 255
  - applied-only comparable pairs in old headline: 170
- Main losses in the old run:
  - crash truncation after 288 / 469 objects: 860 programs never ran
  - object prepare/load failures: 100 objects, blocking 501 programs
  - `exec_ns=0` / non-comparable measured pairs: 228

## Review Findings

### 1. Crash Truncation

- The previous guest `exit 139` aligns with the old REJIT retry-loop failure mode described in the earlier audit.
- Current code path now uses per-pass verify instead of the old retry loop, so the rerun must only validate that the crash no longer reproduces.

### 2. Prepared-State Coverage Bug

- Root cause: `runner/libs/corpus.py` built one prepared kernel state per whole object, and `runner/src/kernel_runner.cpp` loaded the full object when creating that state.
- That made one unsupported sibling program poison every other program in the object.
- Concrete example: `bcc:libbpf-tools/cachestat.bpf.o`
  - `fentry_account_page_dirtied` still fails `bpf_object__load` with kernel-side target lookup failure.
  - Other programs in the same object load and run when the prepared state only autoloads the selected program/group.
- This was a real framework bug, not a kernel capability limit.

### 3. `exec_ns=0` / Silent Geomean Drop

- `runner/src/kernel_runner.cpp` reports attach-trigger runs with `exec_ns=0` when `run_cnt_delta == 0`.
- `runner/libs/corpus.py` previously converted those to `speedup_ratio=None`, and `runner/libs/results.py` silently excluded them from geomean.
- The dominant zero-duration cases are:
  - unsupported attach-trigger program kinds such as `fentry/*` and `kprobe/*`
  - tracepoints whose synthetic trigger path did not actually fire the target program
- This is mostly a reporting/classification problem. The framework must label these cases explicitly instead of dropping them without explanation.

### 4. Headline Geomean Semantics

- The old top-line `exec_ratio_geomean` mixed:
  - programs where passes actually rewrote the code
  - programs with no applied passes but numeric ratios
- That headline did not match the intended “applied-only comparable” story.

### 5. Additional Bug Found During Validation

- Targeted reruns exposed a daemon/runner schema mismatch:
  - REJIT path failed with `invalid daemon JSON: missing JSON key: final_disabled_passes`
- Root cause: `runner/src/daemon_client.cpp` still treated `final_disabled_passes` as mandatory, while the current daemon summary can omit it.
- This would have invalidated any rerun even after the prepared-state fix, so it had to be fixed before the full corpus rerun.

## Fixes

### 1. Group-Scoped Prepared Loads

- Added `load_program_names` to the runner CLI/job spec and propagated it through:
  - [`runner/include/micro_exec.hpp`](/home/yunwei37/workspace/bpf-benchmark/runner/include/micro_exec.hpp)
  - [`runner/src/batch_runner.cpp`](/home/yunwei37/workspace/bpf-benchmark/runner/src/batch_runner.cpp)
  - [`runner/src/kernel_runner.cpp`](/home/yunwei37/workspace/bpf-benchmark/runner/src/kernel_runner.cpp)
- Reworked corpus batch planning in:
  - [`runner/libs/corpus.py`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py)
- New behavior:
  - attach-trigger programs are prepared by `attach_group`
  - other programs are prepared per-program
  - prepared-state loads only the program names needed for that group
  - object results become `partial` when only some groups fail
- Result: unsupported siblings no longer suppress unrelated programs in the same object.

### 2. Explicit Comparison Exclusion Reasons

- Added explicit `comparison_exclusion_reason` labeling in:
  - [`runner/libs/corpus.py`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/corpus.py)
  - [`corpus/modes.py`](/home/yunwei37/workspace/bpf-benchmark/corpus/modes.py)
- Newly surfaced cases include:
  - unsupported attach-trigger section kind
  - attach-trigger did not fire the target program
  - other measured-but-not-comparable cases
- This removes the old silent drop from the benchmark report.

### 3. Applied-Only Headline Geomean

- Updated [`runner/libs/results.py`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/results.py) so the headline `exec_ratio_geomean` uses applied-only comparable pairs.
- Kept all-comparable metrics as secondary outputs:
  - `all_exec_ratio_geomean`
  - `all_exec_ratio_median/min/max`
  - comparable-pair counters split into all-comparable vs applied-comparable

### 4. Daemon JSON Parser Compatibility

- Made `final_disabled_passes` optional in:
  - [`runner/include/json_parser.hpp`](/home/yunwei37/workspace/bpf-benchmark/runner/include/json_parser.hpp)
  - [`runner/src/json_parser.cpp`](/home/yunwei37/workspace/bpf-benchmark/runner/src/json_parser.cpp)
  - [`runner/src/daemon_client.cpp`](/home/yunwei37/workspace/bpf-benchmark/runner/src/daemon_client.cpp)

## Validation Before Full Rerun

- `make runner`: pass
- `make daemon`: pass
- `make python-tests`: pass
- Targeted VM check:
  - `make vm-corpus TARGET=x86 REPEAT=5 FILTERS=cachestat`
  - `make vm-corpus TARGET=x86 REPEAT=1 FILTERS=cachestat`
- Observed behavior on `cachestat`:
  - object no longer fails as all-or-nothing
  - result becomes `partial`
  - 10 / 11 compile pairs succeed
  - unsupported or non-fired attach-trigger programs are explicitly labeled
  - the daemon JSON parse failure is gone

## Full Rerun Attempt

- Command sequence launched as requested:
  - `make daemon`
  - `make runner`
  - `make vm-corpus TARGET=x86 REPEAT=50`
- Artifact:
  - [`runner/corpus/results/vm_corpus_20260328_224017/metadata.json`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_224017/metadata.json)
  - guest raw batch JSON: `docs/tmp/20260328/corpus-rejit-batch/corpus-rejit-vm-batch-result-edw5hqn9.json`
- Observed status:
  - the run no longer hit the old daemon JSON parse failure
  - the run no longer showed the old REJIT retry-loop crash signature in the early prefix
  - but it did not finish the full 469-object corpus; it stopped making forward progress after 62 completed object records and had to be interrupted for diagnosis

### Partial Full-Run Numbers

- Selected objects/programs: 469 / 2009
- Persisted object/program records before interruption: 62 / 445
- Compile pairs: 308
- Measured pairs: 247
- Comparable pairs: 124
- Applied-only comparable pairs: 109
- Headline applied-only exec geomean: `1.0242x`
- Secondary all-comparable exec geomean: `1.0190x`
- Last persisted object in guest raw JSON:
  - `calico:from_nat_debug.bpf.o`

## Additional Validation

The full rerun exposed a new long-tail / stall condition, so I reduced the problem to smaller authoritative slices to separate “object-local bug” from “prefix interaction”.

### Targeted Object Checks

- [`runner/corpus/results/vm_corpus_20260328_223332/metadata.json`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_223332/metadata.json)
  - `FILTERS=cachestat`, pre-daemon-parser fix validation
  - `1 object / 11 programs`, `10` compile pairs, `7` measured pairs
  - confirms group-scoped prepared loads recover `cachestat` from all-or-nothing failure to `partial`
- [`runner/corpus/results/vm_corpus_20260328_223706/metadata.json`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_223706/metadata.json)
  - `FILTERS=cachestat`, post-daemon-parser fix validation
  - same coverage as above, and the `invalid daemon JSON: missing JSON key: final_disabled_passes` failure is gone
- [`runner/corpus/results/vm_corpus_20260328_233641/metadata.json`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_233641/metadata.json)
  - `FILTERS=from_wep_debug`, `REPEAT=1`
  - `1 object / 8 programs`, `8` comparable pairs, applied-only exec geomean `0.9500x`
- [`runner/corpus/results/vm_corpus_20260328_233801/metadata.json`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_233801/metadata.json)
  - `FILTERS=from_wep_debug`, `REPEAT=50`
  - `1 object / 8 programs`, `8` comparable pairs, applied-only exec geomean `0.9640x`
- [`runner/corpus/results/vm_corpus_20260329_003725/metadata.json`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260329_003725/metadata.json)
  - `FILTERS=xdp_no_log`, `REPEAT=1`
  - `1 object / 4 programs`, `4` comparable pairs
- [`runner/corpus/results/vm_corpus_20260329_003849/metadata.json`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260329_003849/metadata.json)
  - `FILTERS=xdp_no_log`, `REPEAT=50`
  - `1 object / 4 programs`, `4` comparable pairs, applied-only exec geomean `0.8529x`
- Conclusion:
  - the calico debug objects and `xdp_no_log` itself are not intrinsically hanging under the new batching logic

### Small-Slice Prefix Checks

- [`runner/corpus/results/vm_corpus_20260328_233940/metadata.json`](/home/yunwei37/workspace/bpf-benchmark/runner/corpus/results/vm_corpus_20260328_233940/metadata.json)
  - `FILTERS=from_`
  - `5 objects / 30 programs`, `27` measured pairs, `25` comparable pairs
  - applied-only exec geomean `1.0534x`
- A larger near-prefix slice with `bcc + KubeArmor + calico debug` advanced past the calico debug range and reached at least:
  - `67` completed objects
  - `483` completed programs
  - `346` compile pairs
  - `285` measured pairs
  - `175` comparable pairs
  - `152` applied-only comparable pairs
- Conclusion:
  - I could not reproduce the full-run stall with the obvious calico-only or bcc-plus-calico slices
  - the remaining blocker is prefix-dependent and likely involves a broader guest-state interaction than a single bad object

## Current Interpretation

### Bleed Point 1: Crash Truncation

- The original retry-loop crash is no longer the dominant blocker.
- I did not observe the old `exit 139` crash in the targeted runs or in the early prefix of the full rerun attempt.
- However, because the authoritative `REPEAT=50` full corpus rerun did not complete, this fix is only partially validated, not fully closed.

### Bleed Point 2: Object Load Failures

- Confirmed real framework bug:
  - whole-object prepared-state loading wrongly dropped good sibling programs
  - fixed by group-scoped `load_program_names`
- Confirmed on `cachestat`:
  - old behavior: full object effectively lost
  - new behavior: `10 / 11` compile pairs survive, only the incompatible group remains failed
- Remaining object load failures are now more likely to reflect actual kernel/object incompatibility than prepared-state blast radius.

### Bleed Point 3: `exec_ns=0`

- Confirmed main issue was reporting, not just attachment:
  - unsupported attach-trigger section kinds were silently excluded before
  - trigger misses (`run_cnt_delta=0`) were also silently excluded before
- The result pipeline now surfaces those cases explicitly in `comparison_exclusion_reason` and summary counters.

## Coverage Comparison

### Before Fixes

- Full selected corpus: `469 objects / 2009 programs`
- Old partial run persisted: `288 objects / 1149 programs`
- Compile pairs: `648`
- Measured pairs: `483`
- Numeric comparable pairs used in the old headline: `255`
- Applied-only comparable pairs: `170`

### After Fixes So Far

- `cachestat` object-level recovery:
  - from `0 / 11` compile pairs effectively usable in the old run
  - to `10 / 11` compile pairs in the fixed targeted rerun
- Early-prefix full-run recovery:
  - `62` objects / `445` programs persisted cleanly before the new long-tail investigation interruption
  - applied-only comparable pairs already reached `109` in that partial full rerun
- Important limitation:
  - there is still no completed authoritative full-corpus `REPEAT=50` rerun after these fixes, so a final before/after corpus-wide coverage delta is not yet available

## Per-Repo Breakdown

No final full-corpus per-repo breakdown is available yet because the authoritative rerun did not complete.

The partial full rerun already showed meaningful coverage in early repos, for example:

- `bcc:libbpf-tools/klockstat.bpf.o`
  - `73` compile pairs
  - `59` measured pairs
  - `41` comparable pairs
  - `40` applied-only comparable pairs
- `calico:from_hep_debug.bpf.o`
  - `9` comparable pairs
  - `9` applied-only comparable pairs
- `calico:from_nat_debug.bpf.o`
  - `8` comparable pairs
  - `8` applied-only comparable pairs

## Conclusions

- Fixed and validated:
  - applied-only headline geomean
  - explicit comparison exclusion reasons for `exec_ns=0` / unsupported attach-trigger cases
  - prepared-state group-scoped loading
  - daemon JSON parser compatibility
- Strongly supported:
  - the old object-load coverage collapse was a real framework bug and is fixed
  - the old silent geomean drop for attach-trigger zero-duration cases is fixed
- Still open:
  - the authoritative `make vm-corpus TARGET=x86 REPEAT=50` rerun did not complete, because a new or nondeterministic long-tail stall appeared after the early prefix
  - I was able to rule out the obvious single-object and calico-debug-sequence explanations, but I did not reduce this stall to one minimal deterministic reproducer within this pass

This report therefore closes Phase 1 and Phase 2, and only partially closes Phase 3. A final full-corpus before/after table still requires one more pass focused on the new full-run stall.
