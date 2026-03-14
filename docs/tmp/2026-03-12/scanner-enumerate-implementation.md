# Scanner `enumerate` Subcommand Implementation Report

Date: 2026-03-12

## Summary

The `bpf-jit-scanner enumerate` subcommand was already present in `scanner/src/cli.cpp` but had a critical bug in the BPF syscall attribute struct layout that caused an infinite loop. This report documents the bug, the fix, and smoke-test results.

## Bug Found: `mini_bpf_attr_id` Wrong Field Layout

### Root Cause

`scanner/src/cli.cpp` defined:

```c
struct mini_bpf_attr_id {
    uint32_t start_id;   // offset 0: used by GET_NEXT_ID
    uint32_t prog_id;    // offset 4: (WRONG) intended to be same field as start_id
    uint32_t next_id;    // offset 8: (WRONG) kernel writes next_id to offset 4
    uint32_t open_flags; // offset 12
};
```

The actual Linux kernel `bpf_attr` layout for `BPF_PROG_GET_NEXT_ID` / `BPF_PROG_GET_FD_BY_ID`:

```
offset 0: start_id (input for GET_NEXT_ID) / prog_id (input for GET_FD_BY_ID)
offset 4: next_id (output written by kernel for GET_NEXT_ID)
offset 8: open_flags
```

The C struct had an extra field (`prog_id` at offset 4) between `start_id` and `next_id`, pushing `next_id` to offset 8. As a result:
- `BPF_PROG_GET_NEXT_ID` wrote the next prog ID to offset 4
- The code read `a->next_id` from offset 8, which remained 0 (part of the zeroed buffer)
- The loop re-queried from `start_id=0` infinitely, producing ~767k BPF syscalls in 8 seconds

Additionally, `bpf_prog_get_fd_by_id` wrote `prog_id` to offset 4 instead of offset 0, so it would query the wrong ID.

### Fix

```c
// Corrected struct:
struct mini_bpf_attr_id {
    uint32_t start_id;   // offset 0: input for GET_NEXT_ID; prog_id for GET_FD_BY_ID
    uint32_t next_id;    // offset 4: output for GET_NEXT_ID (kernel writes here)
    uint32_t open_flags; // offset 8
};
```

And `bpf_prog_get_fd_by_id` updated to use `a->start_id = prog_id`.

Additionally, a `break` was added after processing the matched program when `--prog-id` filter is set, avoiding unnecessary iteration through remaining IDs.

## Feature: `enumerate` Subcommand

The `enumerate` subcommand implements the decoupled daemon component (B) of the three-component architecture:

**Architecture:**
- (A) Applications load BPF programs normally (unmodified)
- **(B) BpfReJIT daemon** uses `enumerate` to scan live programs and optionally recompile
- (C) Kernel handles recompile via `BPF_PROG_JIT_RECOMPILE` (already implemented)

**Subcommand flags:**
```
bpf-jit-scanner enumerate [family flags] [--recompile] [--policy-dir <dir>] [--prog-id <id>] [--json]
```

- No flags: scan all live programs, all families, text output
- `--json`: JSON array output (one entry per program)
- `--prog-id <id>`: scan only a specific program (fast path)
- `--recompile`: after scanning, call `BPF_PROG_JIT_RECOMPILE` on programs with sites
- `--policy-dir <dir>`: per-program policy YAML files (`<dir>/<name>.policy.yaml`, v3 format)
- Family flags: `--cmov`, `--wide-mem`, `--rotate`, `--lea`, `--extract`, `--zero-ext`, `--endian`, `--branch-flip`

**Flow per program:**
1. `BPF_PROG_GET_NEXT_ID` — iterate all loaded program IDs
2. `BPF_PROG_GET_FD_BY_ID` — open fd for each program
3. `BPF_OBJ_GET_INFO_BY_FD` × 2 — probe xlated size, then fetch xlated bytecode
4. `scan_v5_builtin()` — pattern matching on xlated BPF instructions
5. (with `--recompile`) filter by policy, build blob, call `BPF_PROG_JIT_RECOMPILE`

## Build Verification

```
cmake --build scanner/build --target bpf-jit-scanner -j
# → [100%] Built target bpf-jit-scanner  (success)
```

## Smoke Test Results

### Full enumeration (host, sudo)

```
sudo bpf-jit-scanner enumerate
# Output: 197 programs × ~5.9s total
# Summary: scanned 197 programs, 165 with optimization sites
```

### JSON output

```json
[
  {"prog_id":54,"name":"s_cups_cupsd","type":"cgroup_device","total_sites":1,...},
  {"prog_id":84092,"name":"syncookie_xdp","type":"xdp","total_sites":36,...},
  ...
]
```

### Single-program filter (fast path)

```
time sudo bpf-jit-scanner enumerate --prog-id 111182
# → prog_id=111182  type=kprobe  name=lkm_seeker_kset  sites=26
# real 0m0.218s  (scan only, no full enumeration)
```

### Site census by program type (197 live programs, host kernel)

| Program type    | Programs | With sites | Total sites |
|----------------|----------|------------|-------------|
| kprobe          | 133      | 113        | 1278        |
| raw_tracepoint  | 33       | 31         | 282         |
| cgroup_skb      | 14       | 14         | 276         |
| xdp             | 1        | 1          | 36          |
| sched_cls       | 1        | 1          | 36          |
| lsm             | 1        | 1          | 8           |
| cgroup_device   | 14       | 4          | 4           |
| **Total**       | **197**  | **165**    | **1920**    |

83.8% of live BPF programs on this host have at least one optimization site.
1920 total optimization sites available for potential recompilation.

## Files Changed

- `/home/yunwei37/workspace/bpf-benchmark/scanner/src/cli.cpp`:
  - Fixed `mini_bpf_attr_id` struct layout (3 fields instead of 4)
  - Fixed `bpf_prog_get_fd_by_id` to use `a->start_id` at offset 0
  - Added early `break` when `--prog-id` filter matches
