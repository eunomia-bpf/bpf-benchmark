# tracee/monitor cond_select and bulk_memory drift investigation

Read-only investigation except for this findings file. No benchmark target was run.

## 1. Pinpoint which programs lost matches

Compared runs:

- Old/doc-matching run: `corpus/results/x86_kvm_corpus_20260507_025319_683029/details/apps/tracee__monitor.json`
- Current run: `corpus/results/x86_kvm_corpus_20260512_224334_908950/details/apps/tracee__monitor.json`
- Documentation baseline: `docs/evaluation.md:309` has `tracee/monitor` `cond_select` 391/400 and `bulk_memory` 117/214.

The May 7 run is an exact match for the doc baseline:

| run | cond_select applied/matched | bulk_memory applied/matched |
| --- | ---: | ---: |
| 20260507_025319 | 391/400 | 117/214 |
| 20260512_224334 | 372/381 | 112/204 |

Per-program deltas by full BPF program name:

| program | type | old id | new id | cond old -> new matched/applied | bulk old -> new matched/applied | current status |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| `sys_dup_exit_tail` | kprobe | 578 | 42 | 0/0 -> 3/2 | 0/0 -> 2/2 | gains; later `bulk_memory` ReJIT failed with EBUSY |
| `trace_execute_finished` | kprobe | 689 | 153 | 5/5 -> failed before report | 2/1 -> not run | `cond_select` `failed_bpfopt` |
| `trace_security_file_open` | kprobe | 605 | 69 | 4/4 -> 6/6 | 2/1 -> 2/1 | gains; ok |
| `trace_security_socket_accept` | kprobe | 618 | 82 | 6/6 -> failed before report | 3/2 -> not run | `cond_select` `failed_bpfopt` |
| `trace_security_socket_bind` | kprobe | 619 | 83 | 4/4 -> failed before report | 2/1 -> not run | `cond_select` `failed_bpfopt` |
| `trace_security_socket_connect` | kprobe | 617 | 81 | 4/3 -> failed before report | 2/1 -> not run | `cond_select` `failed_bpfopt` |
| `trace_security_socket_setsockopt` | kprobe | 620 | 84 | 5/5 -> failed before report | 3/2 -> not run | `cond_select` `failed_bpfopt` |

Accounting:

- Old matches lost to current `cond_select` `failed_bpfopt`: 24 matched, 23 applied.
- Current gains from `sys_dup_exit_tail` and `trace_security_file_open`: +5 matched, +4 applied.
- Net `cond_select` drift: -19 matched, -19 applied.
- Old `bulk_memory` matches lost because `cond_select` aborted the pass chain first: 12 matched, 7 applied.
- Current `bulk_memory` gain from `sys_dup_exit_tail`: +2 matched, +2 applied.
- Net `bulk_memory` drift: -10 matched, -5 applied.

The current app-level status is `ok`, but the current run has six per-program errors. Five are `cond_select failed_bpfopt`; the remaining one is `sys_dup_exit_tail` failing later at `bulk_memory` ReJIT.

## 2. Bisect pattern detector

I used the canonical tracee testbins as fixed bytecode inputs and varied only the bpfopt source snapshot. The local working tree is dirty in BBProgram/ProgramCFG files, so I used temporary `git archive` snapshots under `/tmp`:

- Old code snapshot: `e321ec98`, parent of the doc-matching result commit `5a79c754`.
- Current-run code snapshot: `4236d2d0`, parent of result commit `4e5fad8c`.

Command shape used for `trace_security_socket_accept`:

```sh
cargo run -q --manifest-path <snapshot>/bpfopt/Cargo.toml -p bpfopt -- \
  --pass cond_select \
  --input bpfopt/testbin/tracee_monitor/609_trace_security_socket_accept/canonicalize_output.bin \
  --output /tmp/x.bin \
  --report /tmp/x.json \
  --koperation bpf_select64:5555 \
  --prog-type kprobe
```

And for `bulk_memory`:

```sh
cargo run -q --manifest-path <snapshot>/bpfopt/Cargo.toml -p bpfopt -- \
  --pass bulk_memory \
  --input bpfopt/testbin/tracee_monitor/609_trace_security_socket_accept/canonicalize_output.bin \
  --output /tmp/x.bin \
  --report /tmp/x.json \
  --koperation bpf_bulk_memcpy:10,bpf_bulk_memset:11 \
  --prog-type kprobe
```

Host-side results on the five programs that lost old matches:

| testbin | old `e321ec98` cond_select | current-run `4236d2d0` cond_select | old `e321ec98` bulk_memory | current-run `4236d2d0` bulk_memory |
| --- | ---: | --- | ---: | ---: |
| `680_trace_execute_finished` | 5/5/0 | failed: `fallthrough to BlockId(168) is not physically adjacent: current pc 1334, target pc 1364` | 2/1/1 | 2/1/1 |
| `608_trace_security_socket_connect` | 4/3/1 | failed: `conditional fallthrough to BlockId(178) is not adjacent: branch pc 1371, fallthrough pc 1397` | 2/1/1 | 2/1/1 |
| `609_trace_security_socket_accept` | 6/6/0 | failed: `conditional fallthrough to BlockId(178) is not adjacent: branch pc 1419, fallthrough pc 1443` | 3/2/1 | 3/2/1 |
| `610_trace_security_socket_bind` | 4/4/0 | failed: `conditional fallthrough to BlockId(172) is not adjacent: branch pc 1349, fallthrough pc 1372` | 2/1/1 | 2/1/1 |
| `611_trace_security_socket_setsockopt` | 5/5/0 | failed: `conditional fallthrough to BlockId(169) is not adjacent: branch pc 1337, fallthrough pc 1360` | 3/2/1 | 3/2/1 |

The direct `bulk_memory` detector output is identical between the old and current-run code snapshots for every affected program. The current corpus `bulk_memory` shortfall is therefore downstream of the earlier `cond_select` abort, not a `bulk_memory` detector regression.

## 3. Git blame the detector

Relevant history from:

```sh
git log --oneline -n 30 -- \
  bpfopt/crates/bpfopt/src/passes/cond_select.rs \
  bpfopt/crates/bpfopt/src/passes/bulk_memory.rs \
  bpfopt/crates/bpfopt/src/analysis/bbprogram*.rs
```

Key commits:

- `57cac8a0` still succeeds on `609_trace_security_socket_accept` and reports `cond_select` 6/6/0.
- `965a259e` is the first compileable bad snapshot I found; it fails with the same non-adjacent fallthrough error.
- `18ff261a` is still bad; it is not the introducing commit.
- `4236d2d0` is the parent of the current result commit and reproduces the current corpus failures.
- `37e8c7b0` is later than the current result and not the run-producing code.

The structural change is in `cond_select`, not `bulk_memory`:

- Good snapshot `57cac8a0:bpfopt/crates/bpfopt/src/passes/cond_select.rs:365` required Pattern A fallthrough to start at `branch_pc + 1`.
- Good snapshot `57cac8a0:bpfopt/crates/bpfopt/src/passes/cond_select.rs:375` required the taken block to start immediately after the false-move block.
- Current-run snapshot `4236d2d0:bpfopt/crates/bpfopt/src/passes/cond_select.rs:277` now matches Pattern A using only logical CFG shape: single-instruction false block, single-instruction true block, common successor, equal destination register.
- Current-run snapshot `4236d2d0:bpfopt/crates/bpfopt/src/passes/cond_select.rs:307` returns a Pattern A site without reconstructing the physical 4-instruction layout that the rewrite requires.
- Current-run snapshot `4236d2d0:bpfopt/crates/bpfopt/src/passes/cond_select.rs:323` does the same kind of CFG-only Pattern C matching.

The lowerer is correctly enforcing BPF physical fallthrough constraints:

- `4236d2d0:bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:128` reads the fallthrough block start PC.
- `4236d2d0:bpfopt/crates/bpfopt/src/analysis/bbprogram_lower.rs:129` rejects conditional branches whose fallthrough block is not at `current_pc + 1`.
- This is the exact error seen in current corpus per-program failures and in host-side testbin runs.

The `bulk_memory` same-base/different-base admission rule is not the source of this drift:

- Current-run direct `bulk_memory` reports match old direct `bulk_memory` reports for the affected programs.
- The alias skip rule is at `4236d2d0:bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:158`, and it reports the same skip counts in direct old/current comparisons.

## 4. Classify each missing match

Classification by affected program:

| program | missing old cond_select matches | missing old bulk_memory matches | classification |
| --- | ---: | ---: | --- |
| `trace_execute_finished` | 5 | 2 | real `cond_select` structural regression; `bulk_memory` not run after abort |
| `trace_security_socket_accept` | 6 | 3 | real `cond_select` structural regression; `bulk_memory` not run after abort |
| `trace_security_socket_bind` | 4 | 2 | real `cond_select` structural regression; `bulk_memory` not run after abort |
| `trace_security_socket_connect` | 4 | 2 | real `cond_select` structural regression; `bulk_memory` not run after abort |
| `trace_security_socket_setsockopt` | 5 | 3 | real `cond_select` structural regression; `bulk_memory` not run after abort |

No missing match is explained by "now correctly rejected because the detector got more precise." The current code does the opposite: it admits a CFG diamond that is not a physically contiguous cond-select bytecode pattern, then the rewrite leaves a conditional fallthrough pointing at a non-adjacent block and lowering fails.

No missing match is explained by `bulk_memory` detector drift. Direct `bulk_memory` on original canonical bytecode still reports the old counts. The corpus loss happens because the pass pipeline stops at `cond_select failed_bpfopt`.

This also is not a tracee bytecode drift: affected programs have identical old/current `orig_insn_count` and `bytes_xlated` in the corpus JSON. Examples:

- `trace_security_socket_accept`: old/new `orig_insn_count` 2188, old/new `bytes_xlated` 17368.
- `trace_security_socket_bind`: old/new `orig_insn_count` 2045, old/new `bytes_xlated` 16152.
- `trace_execute_finished`: old/new `orig_insn_count` 4798, old/new `bytes_xlated` 38400.

The two gains in the net table are not evidence for doc baseline drift:

- `sys_dup_exit_tail` was zero in the May 7 run because that old run had `wide_mem` before `cond_select` and failed at `wide_mem`; the May 12 run's enabled pass list starts at `rotate`, so it reaches `cond_select` and `bulk_memory`.
- `trace_security_file_open` gained two `cond_select` matches under the current detector, offsetting part of the failed-program loss.

## 5. Verdict and fix

This is a real regression in `cond_select` pattern/rewrite structure, introduced by `965a259e` and still present in the current-run snapshot `4236d2d0`.

The doc baseline should not be updated downward. The old baseline is reproducible on canonical bytecode with old code, and current direct `bulk_memory` still matches old `bulk_memory`.

Minimal structural fix:

- Make `cond_select` construct a physical-layout-aware diamond pattern, not a CFG-only pattern.
- The matcher should derive the candidate from current linear PCs/sites and carry that physical layout into the replacement object.
- Pattern A must only represent the contiguous bytecode shape the rewrite can lower: conditional branch at `pc`, false move at `pc + 1`, false-branch jump at `pc + 2`, true move at `pc + 3`, with the common join after that layout.
- Pattern C should likewise derive its replacement range from a contiguous current-PC window, not merely from logical predecessor/fallthrough/successor relationships.
- `replace_diamond_with_insns` should receive a pattern whose physical block order is already proven; it should not be asked to repair arbitrary CFG diamonds.
- Add targeted regression coverage using the five tracee canonical bins above: `cond_select` must not abort lowering, and direct `bulk_memory` counts should remain unchanged.

Verdict:

**Real regression: `cond_select` in `bpfopt/crates/bpfopt/src/passes/cond_select.rs:277` and `:323` at run-producing commit `4236d2d0`, introduced by `965a259e`; fix: restore physical-layout-aware diamond construction so CFG-only non-contiguous diamonds cannot become cond_select rewrite sites.**
