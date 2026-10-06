# VM Corpus map_inline Run Notes (2026-03-27)

## Attempted commands

1. `source /home/yunwei37/workspace/.venv/bin/activate && make all`
2. `source /home/yunwei37/workspace/.venv/bin/activate && make vm-corpus TARGET=x86 REPEAT=200 PROFILE=ablation_map_inline`

## Outcome

- `make all` did not complete in this checkout. The root target currently calls `make kernel-tests`, which fails because `tests/kernel` is missing.
- The requested `vm-corpus` run did not start a fresh results directory during this session.
- The VM lock was already held by an older `vm-corpus` job:
  - lock holder: `PID 522484`
  - command lineage: `corpus/driver.py --profile ablation_map_inline_full --repeat 500`
- I cancelled only the queued `REPEAT=200` run I started after confirming it was blocked behind the older VM job.

## Active map_inline run observed in tree

- Latest result dir: `corpus/results/vm_corpus_20260327_025716`
- Profile: `ablation_map_inline_full`
- Requested passes: `map_inline,const_prop,dce`
- Repeat: `500`
- Status in metadata: `running`
- Last metadata update: `2026-03-27T03:00:38.336376+00:00`
- Progress at inspection time:
  - objects: `2 / 477`
  - programs: `8 / 2019`
  - current target: `KubeArmor:protectproc.bpf.o`

## Partial metrics from the active run

- Total programs: `2019`
- Measured: `0`
- Applied: `0`
- Pass counts: none recorded yet
- Exec geomean ratio: not available yet
- map_inline hits: none recorded yet
- Current failure reasons include `bpf_object__load failed: Invalid argument` with count `32`

## Timestamp

- Local inspection time: `2026-03-26 20:08:26 PDT`
- UTC inspection time: `2026-03-27 03:08:26 UTC`

## Next step needed

To produce the requested final analysis, the older queued/running VM benchmark jobs need to be cleared or allowed to finish, then rerun:

`make vm-corpus TARGET=x86 REPEAT=200 PROFILE=ablation_map_inline`
