# v4 Round 2 Test Results

**Run date (UTC):** 2026-03-10 06:15:05 UTC
**Kernel image:** `/home/yunwei37/workspace/bpf-benchmark/vendor/linux/arch/x86/boot/bzImage`
**Runner:** `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
**Raw outputs:** `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/v4-round2-raw`

## Success Criteria

| Criterion | Status | Evidence |
| --- | --- | --- |
| ROTATE sites found > 0 for `rotate64_hash` | PASS | Tests 2-4 each found `115` rotate sites |
| WIDE_MEM sites found > 0 for `load_byte_recompose` and `stride_load_4` | PASS | Test 10 found `1` site; test 11 found `2` sites |
| No LEA / CMOV regressions | PASS (functional) | Tests 13, 15, 17, 19 all exited `0`, preserved results, and kept the Round 1 site counts / code-size deltas |
| `xlated_prog_len` unchanged after recompile | PASS | Invariant held for all 19 tests |
| Results match expected values | PASS | Every test returned the same `result` as its program baseline |

## Summary Table

| Test | Program | Directive | IO | Sites found | exec_ns | result | xlated_prog_len | jited_prog_len | Exit |
| --- | --- | --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| 1 | `rotate64_hash` | baseline | staged / 64 | none | 250 | 2666935177028490406 | 7984 | 3559 | 0 |
| 2 | `rotate64_hash` | `--recompile-rotate` | staged / 64 | `rotate 115` | 415 | 2666935177028490406 | 7984 | 2409 | 0 |
| 3 | `rotate64_hash` | `--recompile-rotate-rorx` | staged / 64 | `rotate 115` | 249 | 2666935177028490406 | 7984 | 2477 | 0 |
| 4 | `rotate64_hash` | `--recompile-all` | staged / 64 | `wide 8; rotate 115` | 269 | 2666935177028490406 | 7984 | 2313 | 0 |
| 5 | `packet_rss_hash` | baseline | packet / 54 / raw | none | 80 | 2386930978469843216 | 2088 | 1021 | 0 |
| 6 | `packet_rss_hash` | `--recompile-rotate` | packet / 54 / raw | `rotate 11` | 322 | 2386930978469843216 | 2088 | 865 | 0 |
| 7 | `packet_rss_hash` | `--recompile-all` | packet / 54 / raw | `rotate 11` | 210 | 2386930978469843216 | 2088 | 865 | 0 |
| 8 | `packet_rss_hash` | `--recompile-wide` | packet / 54 / raw | none | 144 | 2386930978469843216 | 2088 | 1021 | 0 |
| 9 | `load_byte_recompose` | baseline | staged / 1032 | none | 547 | 1253018829653002637 | 744 | 422 | 0 |
| 10 | `load_byte_recompose` | `--recompile-wide` | staged / 1032 | `wide 1` | 471 | 1253018829653002637 | 744 | 410 | 0 |
| 11 | `stride_load_4` | `--recompile-wide` | staged / 1032 | `wide 2` | 735 | 1982929226459564480 | 920 | 493 | 0 |
| 12 | `stride_load_4` | baseline | staged / 1032 | none | 593 | 1982929226459564480 | 920 | 517 | 0 |
| 13 | `stride_load_4` | `--recompile-lea` | staged / 1032 | `lea 1` | 606 | 1982929226459564480 | 920 | 511 | 0 |
| 14 | `stride_load_16` | baseline | staged / 1032 | none | 383 | 17112594108265627168 | 920 | 517 | 0 |
| 15 | `stride_load_16` | `--recompile-lea` | staged / 1032 | `lea 1` | 586 | 17112594108265627168 | 920 | 511 | 0 |
| 16 | `multi_acc_4` | baseline | staged / 1032 | none | 605 | 1366287837132792961 | 1104 | 599 | 0 |
| 17 | `multi_acc_4` | `--recompile-lea` | staged / 1032 | `lea 1` | 306 | 1366287837132792961 | 1104 | 594 | 0 |
| 18 | `log2_fold` | baseline | staged / 1032 | none | 947 | 9 | 1112 | 648 | 0 |
| 19 | `log2_fold` | `--recompile-cmov` | staged / 1032 | `cmov 6` | 1115 | 9 | 1112 | 682 | 0 |

## Key Findings

### ROTATE (tests 1-7)

- **Primary success criterion met.** `rotate64_hash` now has real coverage: tests 2-4 each found `115` rotate sites.
- `rotate64_hash` code size improved sharply versus baseline `3559 B`:
  - `--recompile-rotate`: `2409 B` (`-1150 B`, `-32.3%`)
  - `--recompile-rotate-rorx`: `2477 B` (`-1082 B`, `-30.4%`)
  - `--recompile-all`: `2313 B` (`-1246 B`, `-35.0%`)
- `rotate64_hash` exec time versus baseline `250 ns`:
  - `--recompile-rotate`: `415 ns` (`+165 ns`, `+66.0%`)
  - `--recompile-rotate-rorx`: `249 ns` (`-1 ns`, `-0.4%`)
  - `--recompile-all`: `269 ns` (`+19 ns`, `+7.6%`)
- `packet_rss_hash` rotate coverage also moved off zero:
  - baseline `1021 B` -> `865 B` under both `--recompile-rotate` and `--recompile-all` (`-156 B`, `-15.3%`)
  - sites found: `11` in both tests 6 and 7
  - exec time in this run did **not** improve: baseline `80 ns` -> `322 ns` (`--recompile-rotate`) and `210 ns` (`--recompile-all`)
- `--recompile-all` on `rotate64_hash` also found `8` `wide_load` sites in addition to the `115` rotate sites, which explains why it produced the smallest native code of the rotate variants.

### WIDE_MEM (tests 8-11)

- `packet_rss_hash --recompile-wide` still found **no** `wide_load` sites and left native size unchanged at `1021 B`.
- `load_byte_recompose --recompile-wide` found `1` site:
  - `jited_prog_len`: `422 B` -> `410 B` (`-12 B`, `-2.8%`)
  - `exec_ns`: `547` -> `471` (`-76 ns`, `-13.9%`)
- `stride_load_4 --recompile-wide` found `2` sites:
  - `jited_prog_len`: `517 B` -> `493 B` (`-24 B`, `-4.6%`)
  - `exec_ns`: `593` -> `735` (`+142 ns`, `+23.9%`)
- Coverage-wise, WIDE_MEM is no longer stuck at zero on the staged byte-recompose workloads that motivated the Round 2 scanner changes.

### LEA / CMOV Regression Checks (tests 12-19)

- LEA remained functional on all three checked programs:
  - `stride_load_4`: `1` site, `517 B` -> `511 B`
  - `stride_load_16`: `1` site, `517 B` -> `511 B`
  - `multi_acc_4`: `1` site, `599 B` -> `594 B`
- CMOV remained functional on `log2_fold`:
  - `6` sites found
  - `jited_prog_len`: `648 B` -> `682 B` (`+34 B`)
  - `exec_ns`: `947` -> `1115` (`+168 ns`, `+17.7%`)
- The LEA / CMOV direction of code-size change matches Round 1 exactly; only the VM timing point moved around.

## `xlated_prog_len` Invariant Check

All recompiles preserved the xlated length of the original verifier output:

| Program | Tests | `xlated_prog_len` |
| --- | --- | ---: |
| `rotate64_hash` | 1-4 | 7984 |
| `packet_rss_hash` | 5-8 | 2088 |
| `load_byte_recompose` | 9-10 | 744 |
| `stride_load_4` | 11-13 | 920 |
| `stride_load_16` | 14-15 | 920 |
| `multi_acc_4` | 16-17 | 1104 |
| `log2_fold` | 18-19 | 1112 |

No test changed `xlated_prog_len`.

## Result Correctness Check

Every test exited `0`, no test timed out, and each directive run preserved the program result:

| Program | Tests | Expected / observed `result` |
| --- | --- | ---: |
| `rotate64_hash` | 1-4 | 2666935177028490406 |
| `packet_rss_hash` | 5-8 | 2386930978469843216 |
| `load_byte_recompose` | 9-10 | 1253018829653002637 |
| `stride_load_4` | 11-13 | 1982929226459564480 |
| `stride_load_16` | 14-15 | 17112594108265627168 |
| `multi_acc_4` | 16-17 | 1366287837132792961 |
| `log2_fold` | 18-19 | 9 |

## Comparison with Round 1

- **ROTATE:** Round 1 had zero rotate coverage on the checked programs. In this rerun:
  - `rotate64_hash` is a new benchmark and now exercises `115` rotate sites.
  - `packet_rss_hash` moved from `0` to `11` rotate sites.
  - `--recompile-rotate-rorx` is now exercised on real sites instead of the zero-coverage path seen in Round 1.
- **WIDE_MEM:** Round 1 coverage was `0` for `packet_rss_hash`, `load_byte_recompose`, and `stride_load_4`. In this rerun it is:
  - `packet_rss_hash`: still `0`
  - `load_byte_recompose`: `1`
  - `stride_load_4`: `2`
- **LEA:** The checked LEA programs keep the same site counts and the same native-size deltas as Round 1:
  - `stride_load_4`: `1` site, `517 -> 511`
  - `stride_load_16`: `1` site, `517 -> 511`
  - `multi_acc_4`: `1` site, `599 -> 594`
- **CMOV:** `log2_fold` still finds `6` sites and still expands native code by `+34 B` (`648 -> 682`), matching Round 1.

## Raw Artifacts

Each test directory under `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/v4-round2-raw` contains:

- `command.txt`
- `stdout.txt`
- `stderr.txt`
- `exit_code.txt`
- `timed_out.txt`

Exact stderr site messages extracted from those raw files:

| Test | stderr site messages |
| --- | --- |
| 1 | `none` |
| 2 | `recompile-rotate: found 115 rotate sites in xlated program (998 insns)` |
| 3 | `recompile-rotate: found 115 rotate sites in xlated program (998 insns)` |
| 4 | `recompile-cmov: no cmov-select sites found in xlated program (998 insns); recompile-wide: found 8 wide_load sites in xlated program (998 insns); recompile-rotate: found 115 rotate sites in xlated program (998 insns); recompile-lea: no addr_calc sites found in xlated program (998 insns)` |
| 5 | `none` |
| 6 | `recompile-rotate: found 11 rotate sites in xlated program (261 insns)` |
| 7 | `recompile-cmov: no cmov-select sites found in xlated program (261 insns); recompile-wide: no wide_load sites found in xlated program (261 insns); recompile-rotate: found 11 rotate sites in xlated program (261 insns); recompile-lea: no addr_calc sites found in xlated program (261 insns)` |
| 8 | `recompile-wide: no wide_load sites found in xlated program (261 insns)` |
| 9 | `none` |
| 10 | `recompile-wide: found 1 wide_load sites in xlated program (93 insns)` |
| 11 | `recompile-wide: found 2 wide_load sites in xlated program (115 insns)` |
| 12 | `none` |
| 13 | `recompile-lea: found 1 addr_calc sites in xlated program (115 insns)` |
| 14 | `none` |
| 15 | `recompile-lea: found 1 addr_calc sites in xlated program (115 insns)` |
| 16 | `none` |
| 17 | `recompile-lea: found 1 addr_calc sites in xlated program (138 insns)` |
| 18 | `none` |
| 19 | `recompile-cmov: found 6 cmov-select sites in xlated program (139 insns)` |
