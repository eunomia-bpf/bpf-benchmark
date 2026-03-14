# Kernel `BPF_PROG_JIT_RECOMPILE` Self-Tests

Date: 2026-03-13

## What Was Added

- New root-level test suite under `tests/kernel/`
- Build glue in `tests/kernel/Makefile`
- Usage notes in `tests/kernel/README.md`
- Main libbpf-based runner in `tests/kernel/test_recompile.c`
- Four XDP BPF test objects in `tests/kernel/progs/`
  - `test_simple.bpf.c`
  - `test_diamond.bpf.c`
  - `test_rotate.bpf.c`
  - `test_wide.bpf.c`

## Test Coverage

The runner builds sealed policy memfds and invokes `BPF_PROG_JIT_RECOMPILE`
directly. It covers:

- Basic load/tag validation
- Valid recompile for `WIDE_MEM`
- Result preservation for `WIDE_MEM`, `COND_SELECT`, and `ROTATE`
- `recompile_count` increment checks
- Malformed policy rejection:
  - wrong magic
  - wrong `prog_tag`
  - wrong `insn_cnt`
  - wrong `arch_id`
  - non-sealed memfd
  - truncated header
  - out-of-bounds `site_start`
  - zero-length blob
- Repeated recompile
- Concurrent recompile (`EBUSY` expectation)
- Recompile while the program is attached to loopback XDP

The runner derives exact rule patterns from the live xlated program instead of
hard-coding register allocation, so the emitted policy blobs stay aligned with
what libbpf/kernel actually loaded.

## Build Result

Built successfully with:

```sh
make -C tests/kernel
```

## Runtime Notes

- The suite must run as root:

```sh
sudo tests/kernel/build/test_recompile
```

- It expects the framework kernel with `BPF_PROG_JIT_RECOMPILE` support.
- The current vendored kernel source still rejects `rule_cnt == 0` policy blobs
  with `EINVAL` in `kernel/bpf/jit_directives.c`; the runner reports that as the
  current implementation behavior so the rest of the suite remains runnable.
