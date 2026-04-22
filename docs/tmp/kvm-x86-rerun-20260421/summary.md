# KVM x86 Corpus Rerun Summary

## Failed rerun preserved for root-cause analysis

- Command: `make vm-corpus SAMPLES=30`
- Failed wall time: `2032.44s` (`33m52.44s`)
- Failed session: `corpus/results/x86_kvm_corpus_20260422_054946_580134/`
- Authority session: `corpus/results/x86_kvm_corpus_20260421_232916_947372/`
- Preserved runner debug artifact: `.state/runner-contracts/run.x86-kvm.corpus.dec10b07`

The failed rerun did **not** produce a valid benchmark result.

- Failed session status: `error`
- Authority session status: `ok`
- Failed all-comparable geomean: `n/a`
- Authority all-comparable geomean: `1.010x`
- Failed applied sample count: `0`
- Authority applied sample count: `12`
- Failed `no_programs_changed_in_loader`: `none`
- Authority `no_programs_changed_in_loader`: `36`

## Failure cause and fix

The original failure was a real caller/signature mismatch in [`corpus/driver.py`](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:838).

- `git blame -L 830,850 -L 1340,1360 corpus/driver.py` shows the mismatch was created after the authority run.
- The authority run captured its first lifecycle at `2026-04-21T23:29:21+00:00` (`2026-04-21 16:29 PDT`).
- The later cleanup commit `567df095` (`2026-04-21 18:56 PDT`) deleted the unreachable `measurement_mode=="app"` branch and removed the `measurement_mode` parameter from `_configure_program_selection(...)`, but the active-session caller still passed `measurement_mode=...`.
- Result: 19 apps failed with `_configure_program_selection() got an unexpected keyword argument 'measurement_mode'`.

Minimal fix:

- Keep `_configure_program_selection(...)` narrow.
- Remove the stray `measurement_mode=` kwarg from the active-session call in [`corpus/driver.py`](/home/yunwei37/workspace/bpf-benchmark/corpus/driver.py:1348).
- No extra kwargs, no refactor, no kernel or daemon changes.

## `bpftrace/tcpretrans` attach failure check

I inspected the current attach path in [`runner/libs/app_runners/bpftrace.py`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/bpftrace.py:178) and the shared attach wait loop in [`runner/libs/app_runners/process_support.py`](/home/yunwei37/workspace/bpf-benchmark/runner/libs/app_runners/process_support.py:16).

- `tcpretrans` still expects exactly one attached program and uses the shared `wait_for_attached_programs()` helper with a `20s` timeout.
- The failed session's `tcpretrans` stderr tail also contained many `tar: ... Cannot change ownership ... Operation not permitted` lines, so the one-off attach miss did not point at a clear attach-timeout bug.
- Targeted rerun `corpus/results/x86_kvm_corpus_20260422_063749_285833/` (`make vm-corpus FILTERS="bpftrace/tcpretrans" SAMPLES=1`) succeeded.
- Control rerun `corpus/results/x86_kvm_corpus_20260422_063229_887355/` (`make vm-corpus FILTERS="bcc/capable" SAMPLES=1`) also succeeded.

Conclusion: the `tcpretrans` attach failure was not reproducible, so no bpftrace/process-support code change was justified.

## Full rerun validation

After the one-line fix, two complete `make vm-corpus SAMPLES=30` reruns both finished successfully.

### First successful rerun

- Session: `corpus/results/x86_kvm_corpus_20260422_064321_184850/`
- Wall time: `2750s` (`45m50s`)
- Status: `ok`
- All-comparable geomean: `1.091x`
- Applied sample count: `16`
- `no_programs_changed_in_loader`: `37`
- `20/20` apps had `Programs > 0` and `Applied > 0`

### Confirmatory rerun

- Session: `corpus/results/x86_kvm_corpus_20260422_073105_905677/`
- Wall time: `2746s` (`45m46s`)
- Status: `ok`
- All-comparable geomean: `1.105x`
- Applied sample count: `16`
- `no_programs_changed_in_loader`: `37`
- `20/20` apps had `Programs > 0` and `Applied > 0`

## Comparison against the authority run

Authority run: `corpus/results/x86_kvm_corpus_20260421_232916_947372/`

- Authority all-comparable geomean: `1.010x`
- Confirmatory rerun all-comparable geomean: `1.105x`
- Authority applied sample count: `12`
- Confirmatory rerun applied sample count: `16`
- Authority `no_programs_changed_in_loader`: `36`
- Confirmatory rerun `no_programs_changed_in_loader`: `37`

Operationally, the TypeError is fixed and KVM x86 corpus reruns are stable again. However, the confirmatory rerun does **not** match the old authority run's `0.95x-1.05x` stability band.

- First successful rerun vs authority: `+8.0%` geomean drift (`1.010x -> 1.091x`)
- Confirmatory rerun vs authority: `+9.4%` geomean drift (`1.010x -> 1.105x`)

## Drift >5% in the confirmatory rerun

- `tetragon/default`: `Applied 1 -> 6`, `Comparable 0 -> 4`
- `bpftrace/runqlat`: `Applied-only 1.028x -> 0.967x` (`-5.9%`)
- `bpftrace/tcpretrans`: `Applied-only 1.021x -> 0.864x` (`-15.4%`)

The dominant structural change is `tetragon/default` moving from `1/0` to `6/4`, which matches the undercount suspicion already documented in plan item `#664`. That means the old authority run and the fixed reruns are likely not measuring identical Tetragon program coverage.

## Bottom line

- The regression was a real `measurement_mode` caller bug introduced by `567df095`.
- The minimal one-line caller fix restored successful KVM x86 corpus execution.
- `bpftrace/tcpretrans` did not show a reproducible code bug.
- Two back-to-back 30-sample reruns were operationally stable, but both landed materially above the old `1.010x` authority run because the fixed run now observes a different per-app mix, especially `tetragon/default`.
