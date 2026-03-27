# Map Capture Tool Report

## Scope

Implemented an end-to-end map state capture path for BpfReJIT fixture generation:

- Added `runner/scripts/capture_map_state.py`.
- Added shared E2E helpers in `e2e/case_common.py` for object/program matching and script invocation.
- Added `--capture-maps` to the unified E2E entrypoint and to the direct Tracee/Tetragon/Katran case CLIs.
- Hooked capture into each case after the stock workload phase and before daemon REJIT.

## Design Notes

- The standalone script uses raw `bpf(2)` syscalls for enumeration and key/value reads.
- Program discovery uses `BPF_PROG_GET_NEXT_ID` plus `BPF_OBJ_GET_INFO_BY_FD` to fetch `map_ids`.
- Map enumeration uses program-owned `map_ids`, then `BPF_OBJ_GET_INFO_BY_FD` on each map FD for metadata.
- Array-like maps are dumped by iterating keys `0..max_entries-1`.
- Hash-like maps are dumped with `BPF_MAP_GET_NEXT_KEY` and `BPF_MAP_LOOKUP_ELEM`.
- Fixtures are written per program under `corpus/fixtures/<repo>/<object>/<program>.json`.

## E2E Integration

- `tracee`:
  Matches live program names against `corpus/build/tracee/*.bpf.o` via `micro_exec` object discovery.
- `tetragon`:
  Matches live program names against `corpus/build/tetragon/*.bpf.o` via `micro_exec` object discovery.
- `katran`:
  Uses an explicit mapping to `katran/balancer.bpf.o:balancer_ingress`.

Each capture result is attached to the case payload as `map_capture`.

## Verification

Ran:

```bash
python3 -m py_compile runner/scripts/capture_map_state.py e2e/case_common.py e2e/run.py e2e/cases/tracee/case.py e2e/cases/tetragon/case.py e2e/cases/katran/case.py
python3 runner/scripts/capture_map_state.py --help
```

Both completed successfully.

## Known Limitations

- Unsupported map types are recorded with `capture_error` and omitted from entry dumps.
- Tracee/Tetragon object matching can fall back to `unknown` if `micro_exec` object discovery is unavailable or ambiguous.
- The E2E hook captures after the stock workload phase has populated live state, not during the middle of a workload syscall burst.
