# vm-corpus results (2026-03-27)

## What I ran

1. Activated the repo venv:
   - `source /home/yunwei37/workspace/.venv/bin/activate`
2. Ran `make all`.
   - This built the daemon/runner artifacts needed for `vm-corpus`.
   - The root `make all` target still stops later at `make kernel-tests` because `tests/kernel` is missing in this checkout. That was not the runtime blocker for `vm-corpus`.
3. Checked whether `PASSES` is a supported make variable:
   - `grep -n PASSES runner/Makefile Makefile | head -10`
   - Result: no matches.

Conclusion: there is no top-level `PASSES=...` make variable wired through `make vm-corpus` in this checkout.

## Attempt 1: non-profile run with pass override

Command used:

```bash
make vm-corpus TARGET=x86 REPEAT=200 JOBS=1 PROFILE_FLAG='--passes "map_inline,const_prop,dce"'
```

Observed selection line:

```text
vm-corpus selection profile=default manifest_objects=477 manifest_programs=2019 selected_objects=477 selected_programs=2019 available_objects=568
```

This confirms the earlier profile-selection bug was avoided: the run selected the broad default corpus, not the broken 2-object profile slice.

Result directory:

- `runner/corpus/results/vm_corpus_20260327_031209`

Observed summary before failure:

- Total objects attempted: `14`
- Total programs attempted: `109`
- Compile pairs: `30`
- Measured pairs: `30`
- Applied programs: `2`
- Exec geomean: `1.0391091033439153`
- Applied passes: `const_prop=4`, `dce=4`, `live_patch=4`
- `map_inline` hits: `0`

Failure:

- `vm guest batch failed: Script done on 2026-03-26 20:34:20-07:00 [COMMAND_EXIT_CODE="255"] (exit=255)`

Interpretation:

- This run was broad enough, but its pass results were not trustworthy for `map_inline`.
- It reported `live_patch`, which was not requested, and did not report `map_inline` at all.
- That matches the earlier stale-daemon/serve-mode mismatch already visible in other `20260327` debug notes.

## Current clean default run in shared workspace

While trying to rerun with the now-clean performance-only daemon, the workspace already had another active `vm-corpus` benchmark session.

Per `AGENTS.md`:

- performance benchmarks must not run in parallel with other performance benchmarks.

Because of that, I did **not** start a conflicting isolated `REPEAT=200` run once the other session was active.

The currently active clean non-profile default run is:

```bash
make vm-corpus TARGET=x86 REPEAT=10
```

Its buffered top-level log shows the expected broad default selection:

```text
vm-corpus selection profile=default manifest_objects=477 manifest_programs=2019 selected_objects=477 selected_programs=2019 available_objects=568
```

I sampled its live guest result file directly:

- guest result file: `docs/tmp/20260326/corpus-rejit-batch/corpus-rejit-vm-batch-result-z0e59l13.json`

State at sample time:

- Object records completed: `18`
- Programs covered so far: `118`
- Compile pairs so far: `38`
- Measured pairs so far: `38`
- Applied programs so far: `15`
- Applied passes so far:
  - `cond_select=2`
  - `const_prop=30`
  - `dce=30`
  - `endian_fusion=4`
  - `extract=4`
- `map_inline` hits so far: `0`
- `live_patch` hits so far: `0`

Interpretation:

- The current clean daemon behavior is different from the stale run above: security passes are gone from the observed pass counts.
- Even with that cleaned performance-only behavior, the sampled corpus results still show **no `map_inline` hits so far**.
- At the time of this report, I do **not** have a completed isolated `REPEAT=200` non-profile run in this shared workspace.

## Answer to “any map_inline hits?”

- In the stale requested-pass run: `0`, because the persisted pass data shows the run was not cleanly honoring the intended `map_inline,const_prop,dce` pipeline and instead reported `live_patch`.
- In the current clean default run sampled so far: `0`, because none of the completed object records have emitted `map_inline` in either compile or run pass lists.

What I can say confidently:

- The profile-selection bug is avoided by running without the profile.
- There is no supported `PASSES=...` make variable at the top level.
- The stale serve-mode run that showed `live_patch` is not a valid `map_inline` measurement.
- The clean performance-only run sampled so far still shows zero `map_inline` hits.

What is still unresolved:

- A completed isolated `make vm-corpus TARGET=x86 REPEAT=200` run under the clean performance-only daemon was not obtained in this shared workspace because another active performance benchmark was already holding the VM queue, and `AGENTS.md` forbids running such benchmarks in parallel.
