# Diagnostics

- Candidate diff matched the saved `source.diff` before restore (`cmp_status=0`).
- Tetragon repo modified files during the attempt:
  - `bpf/process/bpf_generic_tracepoint.c`
  - `bpf/process/generic_calls.h`
  - `bpf/process/pfilter.h`
- Diff size: 286 lines, inherited from the phase2 best plus the sparse active-clear change.
- Object inspection after `make -C vendor tetragon-x86`:
  - `vendor/build/.tetragon-bpf/x86/objs/bpf_generic_tracepoint_v61.o`
  - `tracepoint/generic_tracepoint` section size: `0x66b0`
  - `generic_tracepoint_event` symbol size: `0x66b0`
  - `generic_tracepoint_process_event` symbol size: `0x67c8`
  - `generic_tracepoint_filter` symbol size: `0x72d0`
- Disk after the run: `/` used 758G of 915G, 111G available.
- Docker after the run: images 58.95GB, containers 29.73GB, build cache 81.4GB; no cleanup needed.
