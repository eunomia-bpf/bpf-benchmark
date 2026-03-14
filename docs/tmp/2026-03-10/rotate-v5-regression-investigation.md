# rotate64_hash v5 Regression Investigation

Date: 2026-03-10

## Summary

I could not reproduce a real `rotate64_hash` execution regression for v5 on the current framework kernel.

The `docs/tmp/v5-iteration-results.md` result (`298ns` baseline vs `578ns` v5 all at `--repeat 5`) looks like a noisy VM outlier. On the same `vendor/linux-framework/arch/x86/boot/bzImage`, five sequential reruns at `--repeat 100` show:

| mode | sites | jited_prog_len | exec_ns samples | median exec_ns |
| --- | --- | ---: | --- | ---: |
| baseline | none | 3559 | 103, 66, 98, 106, 93 | 98 |
| v4 `--recompile-rotate` | 115 rotate | 2409 | 89, 126, 77, 48, 53 | 77 |
| v5 `--recompile-v5 --recompile-rotate` | 115 rotate | 2409 | 85, 74, 49, 46, 73 | 73 |
| v4 `--recompile-all` | 115 rotate + 8 wide | 2313 | 50, 78, 72, 45, 74 | 72 |
| v5 `--recompile-v5 --recompile-all` | 115 rotate + 8 wide | 2313 | 57, 197, 73, 114, 44 | 73 |

So the current evidence says:

- no reproducible v5 slowdown
- no v4/v5 difference in matched sites for this workload
- no v4/v5 difference in generated native code shape for rotate-only or all

## Commands Run

- `vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec "cd /home/yunwei37/workspace/bpf-benchmark && sudo micro/build/runner/micro_exec run-kernel --program micro/programs/rotate64_hash.bpf.o --input micro/generated-inputs/rotate64_hash.mem --io-mode staged --input-size 8200 --repeat 100"`
- `vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec "cd /home/yunwei37/workspace/bpf-benchmark && sudo micro/build/runner/micro_exec run-kernel --program micro/programs/rotate64_hash.bpf.o --input micro/generated-inputs/rotate64_hash.mem --io-mode staged --input-size 8200 --repeat 100 --recompile-rotate"`
- `vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec "cd /home/yunwei37/workspace/bpf-benchmark && sudo micro/build/runner/micro_exec run-kernel --program micro/programs/rotate64_hash.bpf.o --input micro/generated-inputs/rotate64_hash.mem --io-mode staged --input-size 8200 --repeat 100 --recompile-v5 --recompile-rotate"`
- `vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec "cd /home/yunwei37/workspace/bpf-benchmark && sudo micro/build/runner/micro_exec run-kernel --program micro/programs/rotate64_hash.bpf.o --input micro/generated-inputs/rotate64_hash.mem --io-mode staged --input-size 8200 --repeat 100 --recompile-all"`
- `vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec "cd /home/yunwei37/workspace/bpf-benchmark && sudo micro/build/runner/micro_exec run-kernel --program micro/programs/rotate64_hash.bpf.o --input micro/generated-inputs/rotate64_hash.mem --io-mode staged --input-size 8200 --repeat 100 --recompile-v5 --recompile-all"`

I also ran wide-only spot checks:

- v4 `--recompile-wide`: samples `103, 270, 235, 104, 109`, median `109`, `3463B`
- v5 `--recompile-v5 --recompile-wide`: samples `104, 125, 103, 64, 103`, median `103`, `3463B`

All raw rerun logs are in `docs/tmp/rotate-v5-regression-runs/`.

## Findings By Hypothesis

### 1. VM 5-repeat noise

Supported.

The `578ns` number does not hold up once the inner repeat count is raised to `100` and we collect multiple outer samples. The median for `v5 all` is `73ns`, essentially identical to `v4 all` at `72ns`.

The main remaining signal is run-to-run VM variance, not a stable v5 penalty.

### 2. v5 matcher finds different sites than v4

Not supported for `rotate64_hash` on the current framework kernel.

Current reruns show:

- v4 rotate-only: `115` rotate sites
- v5 rotate-only: `115` rotate sites
- v4 all: `115 rotate + 8 wide = 123` total sites
- v5 all: `115 rotate + 8 wide = 123` total sites

The prompt's `126 vs 123` premise appears to mix unrelated numbers. The `126` figure elsewhere in the repo is the total rotate coverage across two programs (`115` in `rotate64_hash`, `11` in `packet_rss_hash`), not `115 rotate + 11 wide` inside `rotate64_hash`.

There is a real implementation difference:

- v4 `--recompile-all` scans each family independently and concatenates the rules
- v5 builtin scan does one greedy combined pass in descriptor order

But for this benchmark that difference does not change the effective result.

### 3. v5 blob format / native_choice issue

Not supported.

For rotate-only:

- v4 policy blob: `1872` bytes
- v5 policy blob: `17860` bytes
- both produce `2409B` of native code

For all:

- v4 policy blob: `2000` bytes
- v5 policy blob: `18724` bytes
- both produce `2313B` of native code

So the v5 blob is much larger, but it does not change the chosen lowering for this workload.

I also dumped the resulting JITed binaries and compared normalized disassembly:

- v4 rotate-only vs v5 rotate-only: `673` instruction lines, `0` normalized diff lines
- v4 all vs v5 all: `649` instruction lines, `0` normalized diff lines

The only raw byte differences were relocated absolute immediates such as the `movabs` map-value address in the prologue.

### 4. Emitter regression

Not supported.

The kernel-side rotate path is shared: v4 and v5 both end up in the same canonical rotate emitter. The normalized disassembly comparison above matches that expectation.

If v5 had introduced a rotate-emitter bug, we would expect at least one of:

- different `jited_prog_len`
- different rotate-only performance
- different normalized v4/v5 disassembly

None of those showed up.

### 5. I-cache / alignment regression from smaller code

Not supported.

If the smaller `2313B` image had introduced a real v5-specific layout problem, it should still appear when v4 all and v5 all emit the same native-code shape. It does not.

This hypothesis collapses together with the matcher/blob/emitter hypotheses once `v4 all` and `v5 all` converge to the same `2313B` code and the same normalized disassembly.

## Root Cause

The reported `rotate64_hash` v5 execution regression was a measurement artifact from a short `--repeat 5` VM run, not a real v5 codegen bug.

On the current framework kernel:

- rotate-only: v4 and v5 both find `115` sites and emit `2409B`
- all: v4 and v5 both find `123` sites (`115 rotate + 8 wide`) and emit `2313B`
- normalized v4/v5 disassembly is identical for both rotate-only and all
- `v5 all` median runtime (`73ns`) is effectively the same as `v4 all` (`72ns`)

## Suggested Fix

No kernel or scanner change is justified from this investigation.

The fix is in the benchmarking method and the documentation:

1. Treat the `298ns -> 578ns` entry in `docs/tmp/v5-iteration-results.md` as a non-reproducible outlier.
2. Use at least `--repeat 100` plus multiple outer samples for VM performance claims, and report the median.
3. Do not compare the `123` `rotate64_hash` all-family site count against the unrelated `126` total rotate-coverage number from another doc.
4. If an exact site-identity audit is needed later, add a temporary scanner dump mode that prints `site_start`, `site_len`, `family`, and `native_choice` for both v4 and v5.

## Extra Note On The Referenced v4 Doc

The prompt said `docs/tmp/v4-round3-test-results.md` showed a `-28.4%` `rotate64_hash` improvement. The file currently in this checkout does not show that.

For the run dated `2026-03-10 06:15:38 UTC`, it reports:

- baseline: `277ns`, `3559B`
- v4 rotate: `333ns`, `2409B`

So the `-28%` number must have come from a different artifact, likely one of the later fixed-baseline experiments, not from that specific `v4-round3` result file.
