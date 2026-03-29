# Corpus Round 2

- Date: 2026-03-29
- Command: `make vm-corpus TARGET=x86 REPEAT=50`
- Primary artifact: `runner/corpus/results/vm_corpus_20260329_073249/metadata.json`

## Code changes before rerun

- `corpus/modes.py`
  - Guest batch no longer reuses one daemon across the entire corpus run.
  - Each object-sized chunk starts and stops its own daemon.
  - Guest-executed mutable inputs are snapshotted into the run artifact:
    - `micro_exec`
    - `bpfrejit-daemon`
    - `vmlinux`

## Outcome

- The rerun progressed further without reproducing the original early guest-batch crash shape.
- Partial metrics at failure:
  - `completed_objects=25`
  - `completed_programs=169`
  - `measured_pairs=45`
  - `comparable_pairs=11`
  - `applied_comparable_pairs=11`
  - `applied-only geomean=1.0181130002773269`

## New failure mode

- Failure message:
  - `vm guest smoke failed: command failed (exit=-15)`
- `guest_smoke.payload` is `null`, which means the outer `run_vm_shell.py` process was terminated before the host-side collector saw a complete guest smoke handshake.
- The batch result JSON still contains 25 completed object records, so the guest had already done substantial work before the outer VM process died.
- No guest stdout/stderr diagnostic logs were preserved for this run; only the batch result JSON survived.

## Interpretation

- The original failure mode was:
  - guest batch dies mid-run with progress JSON still being emitted
- After the daemon lifecycle fix, the run made it through 25 objects and showed positive early applied-only geomean.
- The new `SIGTERM`-shaped stop is not explained by repo code paths in:
  - `runner/scripts/with_vm_lock.py`
  - `runner/scripts/run_vm_shell.py`
- That points to external interruption of the VM process rather than a normal corpus exception path.

## Environment notes

- There was a concurrent `vm-e2e scx` workflow in the same repository during this round.
- That workflow also rebuilt kernel-related artifacts in the shared workspace.
- To reduce this interference, repo modules were force-rebuilt directly via:
  - `make -C module/x86 clean KDIR="$(pwd)/vendor/linux-framework"`
  - `make -C module/x86 KDIR="$(pwd)/vendor/linux-framework"`

## Status

- Positive signal achieved on the partial prefix:
  - applied-only geomean `> 1.0`
- Full 469-object completion is still blocked by external VM-process termination.
