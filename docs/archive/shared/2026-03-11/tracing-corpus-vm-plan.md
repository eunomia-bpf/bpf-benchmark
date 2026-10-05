# Tracing Corpus VM Plan

- Date: 2026-03-11
- Kernel image: `vendor/linux-framework/arch/x86/boot/bzImage`
- Status: harness implemented, dry-run verified, full VM run not completed in this turn

## What Works

- `corpus/run_tracing_corpus_vm.py` now exists and defaults to `vendor/linux-framework/arch/x86/boot/bzImage`.
- The script reuses the tracing exec driver logic for attach target resolution, workload selection, attach, `scanner apply --all --v5`, and `run_cnt` / `run_time_ns` collection.
- `--dry-run` completes and writes:
  - `corpus/results/tracing_corpus_vm.json`
  - `docs/tmp/tracing-corpus-vm-report.md`
- Shared blockers uncovered while wiring this up were fixed:
  - `micro/benchmark_catalog.py` now tolerates missing `policy_file`
  - `corpus/_driver_impl_run_corpus_tracing_exec.py` no longer crashes on non-root `PermissionError` when probing tracepoint directories

## Dry-Run Inventory

- Programs considered: 724
- Ready programs: 473
- Skipped programs: 251
- Inventory failures: 88
- Ready by family:
  - `kprobe`: 108
  - `tracepoint`: 178
  - `raw_tracepoint`: 50
  - `lsm`: 33
  - `fentry`: 74
  - `fexit`: 30

These counts come from the current host-side preflight preview in `corpus/results/tracing_corpus_vm.json`.

## VM Attempts

### Smoke

Command:

```bash
python3 corpus/run_tracing_corpus_vm.py --filter biolatency.bpf.o --max-programs 6 \
  --output-json /tmp/tracing_corpus_vm_smoke.json \
  --output-md /tmp/tracing_corpus_vm_smoke.md
```

Observed result:

- Guest batch completed
- 6 programs attached
- 0 paired measurements with positive `run_cnt`
- All 6 landed in the zero-run bucket, so no stock-vs-recompile ratio was produced for that object slice

### Full Run Attempt 1

Command:

```bash
python3 corpus/run_tracing_corpus_vm.py
```

Observed result:

- The original one-process guest path eventually hit a guest-side Python segmentation fault after processing many failing objects/programs.
- To make the harness more robust, the implementation was changed to run one isolated subprocess per target inside a single guest boot.

### Full Run Attempt 2

Command:

```bash
python3 corpus/run_tracing_corpus_vm.py --repeat 10 --warmup-repeat 1 --timeout 30
```

Observed result:

- The isolated guest batch stayed alive and kept the VM stable, but it did not finish within a practical interactive window in this turn.
- The run was manually interrupted after roughly 10 minutes, so no final corpus-wide stock-vs-recompile JSON/markdown report was produced yet.

## Next Command

To continue from the current harness with a lighter per-target budget:

```bash
python3 corpus/run_tracing_corpus_vm.py --repeat 10 --warmup-repeat 1 --timeout 30
```

Expected final outputs:

- `corpus/results/tracing_corpus_vm.json`
- `docs/tmp/tracing-corpus-vm-report.md`

## Notes

- Current corpus objects live under `corpus/build/`; legacy `corpus/expanded_corpus/` and `corpus/objects/` do not exist in this repo snapshot.
- The isolated guest runner is the correct direction for full-corpus robustness, even though the full measurement still needs more wall-clock time than was available here.
