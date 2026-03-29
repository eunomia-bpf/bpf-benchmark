# Corpus Round 1

- Date: 2026-03-28
- Command: `make daemon && make runner && make vm-corpus TARGET=x86 REPEAT=50`
- Primary artifact: `runner/corpus/results/vm_corpus_20260329_061949/metadata.json`

## Outcome

- Build completed and VM batch started successfully after fixing earlier guest boot issues.
- The run crashed mid-batch at object 32/469 with:
  - `vm guest batch failed: {"index": 32, "kind": "program_progress", "total": 469} (exit=241)`
- Partial progress at failure:
  - `completed_objects=32`
  - `completed_programs=288`
  - `measured_pairs=110`
  - `comparable_pairs=58`
  - `applied_comparable_pairs=57`
  - `applied-only geomean=0.9633821721391223`

## Partial observations

- Early comparable data came entirely from `bcc`.
- Early `bcc` applied-comparable geomean was below 1.0.
- The crash was more urgent than the regression analysis because the corpus run did not complete.

## Reproduction notes

- `mountsnoop` alone in a fresh VM completed successfully.
- `memleak -> mountsnoop` also completed successfully in a fresh VM.
- A reduced `first33` guest-batch repro with `repeat=1` still crashed mid-run, but earlier, after object 27.
- The last successfully emitted object in that repro was `bcc:libbpf-tools/javagc.bpf.o`.
- This narrowed the issue to long-lived guest-batch state rather than a single isolated object.

## Fixes applied after Round 1

- `corpus/modes.py`
  - Stop reusing one daemon across the entire guest corpus batch.
  - Let each object-sized chunk start and stop its own daemon.
  - Snapshot guest-executed mutable inputs (`micro_exec`, `bpfrejit-daemon`, `vmlinux`) into the run artifact directory before starting the batch.

## Validation status

- Syntax check passed: `python3 -m py_compile corpus/modes.py`
- Clean rerun validation is pending because another concurrent `vm-e2e scx` task is rebuilding kernel/module artifacts in the same repository, which invalidates guest module compatibility during reproduction.
