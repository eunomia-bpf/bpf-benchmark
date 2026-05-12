# 1. Verify The Loss

Current run inspected:

`corpus/results/x86_kvm_corpus_20260512_202209_159676/details/apps/tetragon__observer.json`

`cond_select` summaries:

| summaries | sites_matched | sites_applied | sites_skipped |
| ---: | ---: | ---: | ---: |
| 286 | 1972 | 1170 | 802 |

The documented baseline is `docs/evaluation.md:305-310`, where `tetragon` has `cond_select` `1 331 / 1 753` applied/matched. Current matched grew by `1972 - 1753 = 219`; current applied dropped by `1331 - 1170 = 161`.

Current skip-reason totals:

| count | skip reason |
| ---: | --- |
| 301 | `no dead register available to materialize immediate operand` |
| 43 | `diamond join BlockId(213) has external predecessor BlockId(189)` |
| 43 | `diamond join BlockId(220) has external predecessor BlockId(137)` |
| 43 | `diamond join BlockId(231) has external predecessor BlockId(222)` |
| 43 | `diamond join BlockId(409) has external predecessor BlockId(307)` |
| 43 | `diamond join BlockId(417) has external predecessor BlockId(412)` |
| 43 | `diamond join BlockId(593) has external predecessor BlockId(491)` |
| 43 | `diamond join BlockId(606) has external predecessor BlockId(600)` |
| 43 | `diamond join BlockId(659) has external predecessor BlockId(594)` |
| 43 | `diamond join BlockId(670) has external predecessor BlockId(659)` |
| 43 | `diamond join BlockId(678) has external predecessor BlockId(670)` |
| 35 | `diamond join BlockId(256) has external predecessor BlockId(223)` |
| 34 | `diamond join BlockId(66) has external predecessor BlockId(24)` |
| 1 | `diamond join BlockId(56) has external predecessor BlockId(50)` |
| 1 | `diamond join BlockId(71) has external predecessor BlockId(29)` |

Gap breakdown:

| bucket | skipped sites | share of 802 gap |
| --- | ---: | ---: |
| external join predecessor | 501 | 62.5% |
| no dead temp register for immediate materialization | 301 | 37.5% |
| other | 0 | 0.0% |

Representative corpus-program reference: program `249`, `generic_kprobe_`, `prog_type=2`, has `31` matched, `14` applied, `17` skipped at `tetragon__observer.json:26578-26600`, with skipped site PCs at `tetragon__observer.json:26601-26669`.

# 2. Per-Program Guard Distribution

Top 5 individual contributors by skipped-site count:

| prog_id | name | prog_type | matched | applied | skipped | dominant bucket | bucket count | dominant exact reason | exact count |
| ---: | --- | ---: | ---: | ---: | ---: | --- | ---: | --- | ---: |
| 28 | `generic_kprobe_` | 2 | 31 | 14 | 17 | external predecessor | 10 | `no dead register available to materialize immediate operand` | 7 |
| 37 | `generic_kprobe_` | 2 | 31 | 14 | 17 | external predecessor | 10 | `no dead register available to materialize immediate operand` | 7 |
| 44 | `generic_kprobe_` | 2 | 31 | 14 | 17 | external predecessor | 10 | `no dead register available to materialize immediate operand` | 7 |
| 53 | `generic_kprobe_` | 2 | 31 | 14 | 17 | external predecessor | 10 | `no dead register available to materialize immediate operand` | 7 |
| 57 | `generic_retkpro` | 2 | 31 | 14 | 17 | external predecessor | 10 | `no dead register available to materialize immediate operand` | 7 |

All skipful programs, grouped by identical distribution:

| prog_ids | name | type | matched | applied | skipped | external | no-temp | dominant bucket |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| 28,37,44,53,61,71,78,88,92,100,109,114,121,128,151,166,177,188,191,199,222,224,234,239,249,256,264,274,282,293,299,306 | `generic_kprobe_` | 2 | 31 | 14 | 17 | 10 | 7 | external predecessor |
| 57,81,137,145,159,167,178,244,278 | `generic_retkpro` | 2 | 31 | 14 | 17 | 10 | 7 | external predecessor |
| 205 | `generic_tracepo` | 5 | 31 | 14 | 17 | 10 | 7 | external predecessor |
| 215 | `generic_rawtp_f` | 17 | 31 | 14 | 17 | 10 | 7 | external predecessor |
| 23 | `event_execve` | 5 | 9 | 8 | 1 | 1 | 0 | external predecessor |
| 31,32,36,40,45,47,51,52,63,66,68,73,75,76,87,90,93,96,102,103,110,111,113,117,122,126,127,133,141,143,152,154,160,165,171,174,183,187,192,194,196,202,217,218,226,229,230,232,242,243,248,254,255,259,263,266,269,272,281,286,288,292,295,298,301,304 | `generic_kprobe_` | 2 | 7 | 6 | 1 | 1 | 0 | external predecessor |
| 212,213 | `generic_rawtp_p` | 17 | 7 | 6 | 1 | 1 | 0 | external predecessor |
| 203 | `generic_tracepo` | 5 | 6 | 5 | 1 | 1 | 0 | external predecessor |
| 207 | `generic_tracepo` | 5 | 7 | 6 | 1 | 1 | 0 | external predecessor |

There are `114` programs with at least one `cond_select` skip. Every skipful program has an external-predecessor skip. The high-skip programs have `10` external-predecessor skips plus `7` immediate-materialization skips.

# 3. Skip-Reason Classification

| category | count | source |
| --- | ---: | --- |
| external predecessor | 501 | `external_join_predecessor_skip()` emits `diamond join ... has external predecessor ...` at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:257-273`; it mirrors `validate_diamond()` at `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:790-803`. |
| immediate materialization register pressure | 301 | `materialize_value()` returns `no dead register available to materialize immediate operand` at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:545-561`; temp selection is at `cond_select.rs:573-585`. |
| target lacks `bpf_select64` | 0 | Pass-level skip exists at `cond_select.rs:95-103`; not hit in this run. |
| mismatched alias regs | 0 | No current `cond_select` skip reason matched this bucket. |
| frame mismatch | 0 | No current `cond_select` skip reason matched this bucket. |
| wide ALU missing kinsn | 0 | Not a `cond_select` skip class in this result. |

Baseline comparison from the documented-baseline run artifact:

`corpus/results/x86_kvm_corpus_20260507_200821_664435/details/apps/tetragon__observer.json`

That run has the doc count `1753` matched, `1331` applied, `422` skipped. Its skip reasons were:

| baseline category | baseline count |
| --- | ---: |
| no dead register available to materialize immediate operand | 301 |
| interior branch target | 121 |

The `301` no-temp sites are unchanged between the baseline and current run. The regression is not caused by an increase in this category.

# 4. Is The Loss All From `external_join_predecessor_skip()`?

Yes for the applied-site regression.

Current external-predecessor skips are `501`, which is `501 / 161 = 311%` of the missing-applied count. More usefully, compared to the baseline skip mix:

| term | count |
| --- | ---: |
| current external-predecessor skips | 501 |
| baseline `interior branch target` skips that disappeared | -121 |
| net new skip pressure | 380 |
| newly matched sites | -219 |
| resulting applied drop | 161 |

So the accounting is exact: `380` extra skip pressure from the external-predecessor bucket minus `219` newly matched candidates equals the `161` applied-site loss.

Non-external skips did not increase. The `no dead register available to materialize immediate operand` bucket is `301` in both the baseline artifact and the current artifact. It is not the current 161-site loss.

The guard is implemented twice in the pass: once during trial validation at `cond_select.rs:126-132`, and again before the real replacement at `cond_select.rs:152-157`. The helper itself is `external_join_predecessor_skip()` at `cond_select.rs:257-273`.

Important algorithm note: `replace_diamond_with_insns()` currently removes the join block when `pattern.join` is present. It appends the join body to the predecessor at `bbprogram_api.rs:494-521`, inserts `join` into the remove set at `bbprogram_api.rs:488-492`, and removes the blocks at `bbprogram_api.rs:546`. Therefore the external-predecessor guard is load-bearing for the current implementation, but only because the implementation cannot yet rewrite a shared-join diamond. The correct fix is not to keep the guard; it is to add a shared-join rewrite mode that deletes only the two private branch blocks and leaves the externally reachable join block in place.

# 5. Non-External Skip Category

Only one non-external category remains: `no dead register available to materialize immediate operand`, count `301`.

Code path:

- `build_lowering()` builds the predicate and then materializes the selected true/false operands at `cond_select.rs:416-453`.
- `materialize_value()` accepts register operands directly but must allocate a temp for `Imm`, `Imm32`, and `Reg32` values at `cond_select.rs:545-570`.
- Temp allocation uses `choose_temp_reg()` at `cond_select.rs:573-585`; it avoids protected registers, already allocated temps, and registers live after the diamond unless the register is the destination.
- If no such temp exists, `materialize_value()` returns the skip reason at `cond_select.rs:560-561`.

Classification: correctness-load-bearing for the current lowering. `bpf_select64` takes register operands encoded in the kinsn payload (`cond_select.rs:9-16`, `cond_select.rs:144-148`). If an immediate or 32-bit source must be passed to the kfunc and all legal temps are live or protected, reusing one would clobber a live value before the join. This is not a prophylactic guard.

Minimal coverage fix if this bucket becomes a target: add a real spill/restore lowering for a chosen live temp around the emitted `bpf_select64` call, with verifier-state handling for the stack slot. That is an algorithm extension, not a guard removal. No text diff is proposed here because this category is correctness-load-bearing and did not contribute to the 161-site regression.

# 6. Host-Side Reproduction

Chosen host testbin program:

`bpfopt/testbin/tetragon_observer/245_generic_kprobe_filter_arg/canonicalize_output.bin`

This testbin input reproduces the high-skip tetragon shape. The equivalent command was run with `--manifest-path` because the repository root has no `Cargo.toml`:

```sh
cargo run -q --manifest-path bpfopt/Cargo.toml -p bpfopt -- \
  --pass cond_select \
  --input bpfopt/testbin/tetragon_observer/245_generic_kprobe_filter_arg/canonicalize_output.bin \
  --output /tmp/cond_select_scan_245_generic_kprobe_filter_arg.bin \
  --kinsns bpf_select64:5555 \
  --report /tmp/cond_select_scan_245_generic_kprobe_filter_arg.json
```

Host report:

| pass | matched | applied | skipped |
| --- | ---: | ---: | ---: |
| `cond_select` | 31 | 14 | 17 |

Host skip reasons:

| count | reason |
| ---: | --- |
| 1 | `diamond join BlockId(213) has external predecessor BlockId(189)` |
| 1 | `diamond join BlockId(220) has external predecessor BlockId(137)` |
| 1 | `diamond join BlockId(231) has external predecessor BlockId(222)` |
| 1 | `diamond join BlockId(409) has external predecessor BlockId(307)` |
| 1 | `diamond join BlockId(417) has external predecessor BlockId(412)` |
| 1 | `diamond join BlockId(593) has external predecessor BlockId(491)` |
| 1 | `diamond join BlockId(606) has external predecessor BlockId(600)` |
| 1 | `diamond join BlockId(659) has external predecessor BlockId(594)` |
| 1 | `diamond join BlockId(670) has external predecessor BlockId(659)` |
| 1 | `diamond join BlockId(678) has external predecessor BlockId(670)` |
| 7 | `no dead register available to materialize immediate operand` |

This matches the current corpus high-skip pattern exactly. Example corpus program `249` has the same `31 / 14 / 17` split and the same `10 + 7` skip distribution at `tetragon__observer.json:26578-26600`.

Note: a broader scan was stopped after unrelated concurrent edits made the crate stop compiling. The successful `/tmp/cond_select_scan_245_generic_kprobe_filter_arg.json` report above was produced before that compile break and is the reproduction used here.

# 7. Cross-Reference With Cilium Investigation

Sibling report: `docs/tmp/cond_select_external_predecessor_root_cause_20260512.md`.

The cilium report identifies the same structural root cause: `cond_select` detects a diamond whose join has an incoming edge from outside `{predecessor, true_branch, false_branch}`, then `external_join_predecessor_skip()` rejects it before `replace_diamond_with_insns()`. It also confirms the important implementation detail: the current generic rewrite does not leave the join untouched; it moves the join body into the predecessor and deletes the join block (`cond_select_external_predecessor_root_cause_20260512.md:23-33`, `:83-99`).

The proposed fix should be the same class of fix as cilium's:

- remove the prophylactic `external_join_predecessor_skip()` prefilter from `cond_select.rs`;
- change `replace_diamond_with_insns()` or add a dedicated API variant so shared-join diamonds preserve the join block and only remove the private true/false branch blocks;
- keep the existing branch-block predecessor checks in `validate_diamond()` (`bbprogram_api.rs:777-788`), because true/false branch blocks being private is load-bearing;
- replace `cond_select_skips_diamond_join_with_external_predecessor` at `cond_select_tests.rs:148-164` with a test that asserts successful rewrite of a shared-join diamond.

The cilium worked example uses `bpfopt/testbin/cilium_agent/164_cil_from_host/canonicalize_output.bin`, where the external path enters the shared join with `r0 = -1`, while the diamond paths select `r0 = -100` or `r0 = -3`; preserving the join keeps the external path's live-ins unchanged (`cond_select_external_predecessor_root_cause_20260512.md:101-233`, `:413-421`). Tetragon's external-predecessor skip strings are the same `diamond join ... has external predecessor ...` predicate and reproduce host-side in `245_generic_kprobe_filter_arg`, so there is no tetragon-only guard class. Tetragon adds a large, pre-existing immediate-materialization pressure bucket, but that bucket is unchanged from the baseline and is not the 161-site applied regression.

Tetragon loss root cause: the 161-site applied regression is fully explained by `external_join_predecessor_skip()` rejecting 501 shared-join diamonds while the pre-existing 301 immediate-materialization skips stayed constant. Distinct from cilium? no.
