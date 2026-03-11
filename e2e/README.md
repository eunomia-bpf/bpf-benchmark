# End-to-End

`e2e/` is the end-to-end deployment layer.

Current transitional harnesses:

- `run_e2e_tracee.py`
- `run_e2e_tetragon.py`
- `run_e2e_bpftrace.py`

Planned layout:

- `common/`: shared case helpers and assets
- `cases/`: per-system deployment scenarios
- `results/`: end-to-end result snapshots

This layer will be expanded by follow-on tasks. For now, the moved probe harnesses are the first slice of the new structure.
