# map_inline serve-mode debug (20260327)

## Scope

Goal: verify whether `map_inline` fires in VM corpus serve mode and inspect the per-program daemon optimize response.

I did not modify kernel code and did not commit anything.

## Commands run

- `source /home/yunwei37/workspace/.venv/bin/activate && make all`
- `make vm-corpus TARGET=x86 REPEAT=10 2>&1 | tail -50`
- Python one-offs to inspect:
  - `corpus/results/vm_corpus_20260327_025716/{metadata.json,details/result.json}`
  - `runner/corpus/results/vm_corpus_20260327_031209/details/result.json`
  - `docs/tmp/20260326/corpus-rejit-batch/corpus-rejit-vm-batch-result-18rnswzr.json`

## Build status

`make all` built `micro` and the release daemon successfully, then failed at `make kernel-tests` because `tests/kernel` is missing in this tree:

- `make[2]: *** /home/yunwei37/workspace/bpf-benchmark/tests/kernel: No such file or directory. Stop.`

That did not block inspection of existing serve-mode corpus artifacts.

## Benchmark status

I started `make vm-corpus TARGET=x86 REPEAT=10`, but this repo already had another active `vm-corpus` benchmark holding `with_vm_lock` from a different session. My duplicate quick run queued behind that lock, so I canceled it instead of leaving extra perf work pending.

Fresh serve-mode corpus artifacts were already present in the workspace and were enough to answer the question:

- `corpus/results/vm_corpus_20260327_025716/details/result.json`
- `runner/corpus/results/vm_corpus_20260327_031209/details/result.json`

Both showed the same applied-program evidence.

## Findings

### 1. The corpus serve-mode result does not retain the raw daemon optimize response

The runner captures and can serialize raw daemon JSON:

- `runner/src/kernel_runner.cpp` stores `rejit.daemon_response = sock_resp.raw_json`
- `runner/src/common.cpp` emits `daemon_response` into the JSON sample

But the corpus pipeline strips that field before writing guest batch results:

- `corpus/modes.py:_strip_daemon_response()` removes any `daemon_response` key

So the persisted corpus artifacts do **not** contain `daemon_response` or `pass_details`, even when the daemon was used successfully.

Observed result:

- searching the result JSONs found no persisted `daemon_response`
- the surviving per-program evidence is the summarized `sample.rejit` fields such as `passes_applied`, `total_sites_applied`, `insn_delta`, and `daemon_debug_stripped`

### 2. `map_inline` was not observed firing in the inspected serve-mode corpus run

At inspection time, `runner/corpus/results/vm_corpus_20260327_031209/details/result.json` reported:

- `requested_passes`: `["map_inline", "const_prop", "dce"]`
- `compile_pairs`: `23`
- `measured_pairs`: `23`
- `applied_programs`: `2`
- `compile_pass_counts`: `{"const_prop": 2, "dce": 2, "live_patch": 2}`
- `run_pass_counts`: `{"const_prop": 2, "dce": 2, "live_patch": 2}`
- `pass_counts`: `{"const_prop": 4, "dce": 4, "live_patch": 4}`

There were **zero** `map_inline` hits in:

- summary pass counts
- `applied_passes`
- `compile_passes_applied`
- `run_passes_applied`

Concrete applied programs:

1. `bcc:libbpf-tools/biopattern.bpf.o:handle__block_rq_complete`
   - `passes_applied`: `["const_prop", "dce", "live_patch"]`
   - `total_sites_applied`: `22`
   - `insn_delta`: `-15`
   - `daemon_debug_stripped`: `true`

2. `bcc:libbpf-tools/bitesize.bpf.o:block_rq_issue`
   - `passes_applied`: `["const_prop", "dce", "live_patch"]`
   - `total_sites_applied`: `9`
   - `insn_delta`: `0`
   - `daemon_debug_stripped`: `true`

`corpus/results/vm_corpus_20260327_025716/details/result.json` showed the same two applied programs with the same non-`map_inline` pass list.

### 3. Current serve-mode corpus evidence points to a pass-filter mismatch

The inspected run explicitly requested:

- `map_inline`
- `const_prop`
- `dce`

But the applied pass list includes `live_patch`, which was not requested, and does not include `map_inline`.

So the current serve-mode corpus evidence is:

- serve mode is active (`sample.rejit.mode == "daemon"` and `sample.rejit.requested == true`)
- the daemon is applying passes
- `map_inline` is **not** showing up in the persisted applied-pass data
- `live_patch` is showing up instead

## Conclusion

I could not verify that `map_inline` fires in corpus serve mode from the current VM corpus artifacts. The opposite is what the persisted evidence shows so far: serve mode is running, but the observed applied passes are `const_prop`, `dce`, and `live_patch`, with no `map_inline`.

Separately, the specific per-program daemon optimize response you wanted is not available in the saved corpus result because `corpus/modes.py` strips `daemon_response` before writing the JSON artifacts. The remaining summarized `sample.rejit` fields are enough to show which passes were applied, and those fields currently do not show `map_inline`.
