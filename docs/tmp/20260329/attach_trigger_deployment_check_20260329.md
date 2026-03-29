# Attach-Trigger Deployment Check (2026-03-29)

Artifact under review: `runner/corpus/results/vm_corpus_20260329_091745/metadata.json`

## Bottom line

I do not find evidence that `vm_corpus_20260329_091745` used a pre-#600 runner binary.

The strongest evidence points the other way:

- the source tree contains the full #600 attach-trigger broadening logic
- the `micro_exec` binary used by the run contains #600-only strings such as `attach: auto-trigger fallback...`, `raw_tp+`, `tp_btf+`, `fentry+`, `fmod_ret+`, `fexit+`, `ksyscall+`, `kretsyscall+`, and `kretprobe+`
- the run used the exact same `micro_exec` bytes as the current `runner/build/micro_exec`

So "fix not deployed, therefore rebuild runner and rerun" is not supported by the surviving artifacts alone.

What is true is narrower:

- the artifact does not record an exact runner git SHA
- the artifact's raw per-program result file is missing
- the `290` measured-to-comparable losses are not all "`exec_ns=0`"

## 1. Which runner binary did `091745` use?

`metadata.json` records:

- `started_at`: `2026-03-29T09:17:45.610943+00:00`
- `completed_at`: `2026-03-29T12:40:49.008540+00:00`
- `runner_binary`: `runner/build/micro_exec`
- guest command uses `runner/corpus/results/vm_corpus_20260329_091745/guest-inputs/micro_exec`

Relevant lines:

- `runner/corpus/results/vm_corpus_20260329_091745/metadata.json:7`
- `runner/corpus/results/vm_corpus_20260329_091745/metadata.json:1004`
- `runner/corpus/results/vm_corpus_20260329_091745/metadata.json:1043`
- `runner/corpus/results/vm_corpus_20260329_091745/metadata.json:1044`

Binary identity:

- `runner/build/micro_exec` mtime: `2026-03-28 17:11:31.660648682 -0700`
- `guest-inputs/micro_exec` mtime: same
- size: `109774552`
- SHA-256: `205bfc70890094405168b5f7d9b7d89f20b766123211607755ccc19184455b49`

The live build output and the archived guest copy are byte-identical.

## 2. What git commit was that binary built from?

Exact answer: not recoverable from the artifact.

What I could verify:

- the nearest committed `HEAD` before the binary mtime is `190861d5da9e6771d041201564c464a4dc93aac0` (`2026-03-28 16:52:05 -0700`)
- the #600 attach-trigger broadening commit is `bceb6157bee0eb75aac7219effde0e2385a7e600` (`2026-03-28 18:29:22 -0700`)
- current `HEAD` is later: `ad690ba237cdb4f8a7d39893a0c16831f538eabe`

However, mtime alone is misleading here.

I checked `runner/src/kernel_runner.cpp` at `190861d` and at `bceb615^`: neither contains any of the new auto-trigger code or strings. But the `micro_exec` binary used by `091745` does contain them. That means the binary was almost certainly built from a dirty tree that already included the #600 logic before it was committed as `bceb615`.

So:

- exact git SHA: not recorded
- strongest inference: the binary is newer in content than `190861d` and already contains the `bceb615` attach-trigger broadening logic

## 3. Does the source tree contain the attach-trigger enhancement?

Yes.

The current `runner/src/kernel_runner.cpp` contains all of the expected #600 pieces:

- broadened static eligibility in `section_supports_auto_attach_trigger()`:
  - `tracepoint`, `tp`, `raw_tp`, `raw_tracepoint`, `tp_btf`, `ksyscall`, `kretsyscall`
  - `kprobe*`, `kretprobe*`, `fentry*`, `fexit*`, `fmod_ret*`, `lsm*`
  - lines `1836-1853`
- section-based trigger planning in `build_auto_attach_trigger_plan()`:
  - exec/process/sched/file/memory/network sweep selection
  - lines `1871-1971`
- concrete auto-trigger suites:
  - exec/process/sched/file/memory/network
  - lines `1978-2249`
- fallback is only invoked when the primary workload did not bump `run_cnt`:
  - lines `3002-3012`
  - lines `4219-4228`

Relevant source references:

- `runner/src/kernel_runner.cpp:1836`
- `runner/src/kernel_runner.cpp:1871`
- `runner/src/kernel_runner.cpp:2211`
- `runner/src/kernel_runner.cpp:3002`
- `runner/src/kernel_runner.cpp:4219`

## 4. Does `metadata.json` record binary version info?

No useful version provenance is recorded.

What is present:

- `runner_binary` path
- `guest_input_snapshots.runner` path

What is not present:

- runner git SHA
- runner build id
- runner binary hash
- explicit `binary_version`

So the artifact tells us which file path was used, but not the exact source revision that produced it.

## 5. What are the "`290 exec_ns=0`" measured programs?

The surviving metadata shows that "`290 exec_ns=0`" is not the right description.

`summary.comparison_exclusion_reasons` sums exactly to `290`, but the split is:

| Bucket | Count |
| --- | ---: |
| `attach_trigger did not fire ...` | 214 |
| `attach_trigger measurement unsupported ...` | 27 |
| true `exec_ns=0` (`bpf_prog_test_run reported exec_ns=0 in baseline and REJIT`) | 49 |
| Total | 290 |

Relevant metadata lines:

- `runner/corpus/results/vm_corpus_20260329_091745/metadata.json:6833`
- `runner/corpus/results/vm_corpus_20260329_091745/metadata.json:6835`
- `runner/corpus/results/vm_corpus_20260329_091745/metadata.json:6848`

So only `49/290 = 16.9%` are actual both-sides-`exec_ns=0` cases.

The other `241/290 = 83.1%` are attach-trigger comparability losses:

- `214` no-fire attach-trigger cases
- `27` unsupported iterator sections

Unsupported iterator-section breakdown:

- `iter/task`: `8`
- `iter/tcp`: `4`
- `iter/bpf_map`: `3`
- `iter/task_file`: `2`
- `iter/task_vma`: `2`
- `iter/udp`: `2`
- `iter.s/task`: `1`
- `iter/bpf_link`: `1`
- `iter/bpf_prog`: `1`
- `iter/ksym`: `1`
- `iter/netlink`: `1`
- `iter/unix`: `1`

This means the big `290` bucket is not "mostly tracing/kprobe programs with `exec_ns=0`". The dominant loss is attach-trigger programs that still did not fire, plus a smaller iterator bucket that is explicitly outside the broadened auto-trigger roots.

## 6. Can I give the exact `prog_type` distribution for those 290 programs?

Not for `091745` itself.

Why not:

- the guest command recorded in `metadata.json` points at raw batch files `.../corpus-rejit-vm-batch-s7ih7dzs.json` and `.../result-wzjd5pr6.json`
- those exact files are not present anymore
- `runner/corpus/results/vm_corpus_20260329_091745/details/` is also gone
- `metadata.json` preserves only the exclusion histogram, not the per-program rows

So the exact per-program `prog_type_name` breakdown for the `290` exclusions is no longer reconstructible from the surviving `091745` artifact.

What can still be said safely:

- the `214` no-fire and `27` unsupported buckets are generated only on the `attach_trigger` path
- the `27` unsupported cases are iterator sections, not `kprobe/raw_tp/fentry/lsm/tp_btf`
- the `49` true zero-`exec_ns` cases are `bpf_prog_test_run`, not attach-trigger

## 7. Conclusion for deployment

Deployment verdict: #600 looks deployed in the binary used by `091745`, even though the artifact fails to record the exact commit.

Therefore:

- I cannot confirm "repair did not take effect because runner was stale"
- I can confirm "the binary likely already contained the broadened attach-trigger code"
- the remaining `290` loss is mostly a runtime measurement-coverage problem, not proof of missing deployment

## 8. What to do next

Do not use this artifact as evidence that a runner rebuild is required because #600 was absent.

If you want a clean, non-ambiguous answer on future runs:

1. rebuild `runner/build/micro_exec`
2. record the exact git SHA and SHA-256 in `metadata.json`
3. preserve `details/result.json` or the raw `corpus-rejit-vm-batch-result-*.json` for the completed run

That would eliminate both current ambiguities:

- dirty-tree build before commit
- lost per-program exclusion rows
