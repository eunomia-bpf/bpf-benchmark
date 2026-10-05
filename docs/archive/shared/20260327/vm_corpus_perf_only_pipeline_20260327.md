# VM Corpus Perf-Only Pipeline Run (2026-03-27)

## Requested sequence

1. `source /home/yunwei37/workspace/.venv/bin/activate`
2. `make daemon 2>&1 | tail -3`
3. `make runner 2>&1 | tail -3`
4. `rm -f /tmp/bpfrejit-vm-lock-* 2>/dev/null`
5. `make vm-corpus TARGET=x86 REPEAT=10 2>&1 | tee /tmp/vm_corpus_new.log`

## Build results

### `make daemon 2>&1 | tail -3`

```text

warning: `bpfrejit-daemon` (bin "bpfrejit-daemon") generated 91 warnings
    Finished `release` profile [optimized] target(s) in 0.01s
```

### `make runner 2>&1 | tail -3`

```text
gmake[3]: Leaving directory '/home/yunwei37/workspace/bpf-benchmark/runner/build'
gmake[2]: Leaving directory '/home/yunwei37/workspace/bpf-benchmark/runner/build'
make[1]: Leaving directory '/home/yunwei37/workspace/bpf-benchmark/runner'
```

## VM corpus run status

- Run start log: `/tmp/vm_corpus_new.log`
- Live wrapper log: `/tmp/vng-wrapper-log.HIETgT`
- Live incremental result dir: `runner/corpus/results/vm_corpus_20260327_033938`
- Local inspection time: `2026-03-26 21:07:07 -0700`
- Status: `running`

At inspection time, the live metadata in `runner/corpus/results/vm_corpus_20260327_033938/metadata.json` reported:

```text
progress:
  completed_objects: 27
  completed_programs: 177
  current_target_index: 27
  current_target: bcc:libbpf-tools/javagc.bpf.o
  total_objects: 477
  total_programs: 2019
```

```text
=== PARTIAL SUMMARY ===
targets_attempted: 177
compile_pairs: 49
measured_pairs: 49
applied_programs: 17
exec_ratio_geomean: 1.1205588896024707
pass_counts: {'cond_select': 2, 'const_prop': 36, 'dce': 36, 'endian_fusion': 4, 'extract': 4}
map_inline NOT in pass_counts
```

## Important observation

- This run is not hung; QEMU stayed busy and the guest progress advanced from object `1` to object `27`.
- The runtime is much longer than the requested "quick" expectation because guest batch mode is explicitly single-object sequential:
  - `corpus/modes.py:78` sets `GUEST_BATCH_TARGETS_PER_CHUNK = 1`
  - `corpus/modes.py:1194-1240` processes all `477` objects one chunk at a time
- No new completed `corpus/results/vm_corpus_2026032*/metadata.json` artifact existed yet during this session, so the requested final step:
  - `ls -lt corpus/results/vm_corpus_2026032*/metadata.json | head -1`
  could not be completed honestly at inspection time.
- After capturing the live state, the run was interrupted intentionally at `2026-03-26 21:07:59 -0700` to avoid leaving a multi-hour VM benchmark running silently.
- The final top-level error in `/tmp/vm_corpus_new.log` is therefore from that interruption:

```text
RuntimeError: vm guest batch failed: Script done on 2026-03-26 21:07:59-07:00 [COMMAND_EXIT_CODE="1"] (exit=1)
make[1]: *** [Makefile:267: vm-corpus] Error 1
make: *** [Makefile:314: vm-corpus] Error 2
```

## Current verification state

- The new daemon and runner both build successfully.
- The perf-only daemon pipeline is active in this run (`requested_passes` is `None` in the live runner metadata, so it is using daemon defaults).
- `map_inline` has not appeared yet in the partial live pass counts through object `27 / 477`.
- Because the run has not completed, this note is an in-progress status capture rather than a final completed corpus result.
