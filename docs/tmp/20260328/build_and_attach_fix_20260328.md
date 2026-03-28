# Build And Attach Fix Report (2026-03-28)

## Scope

- Task 1: fix the `asm/types.h` build failure in corpus object compilation.
- Task 2: investigate attach failures in corpus runs without changing kernel code.

## 1. `asm/types.h` Build Fix

### What I read

- `runner/scripts/build_corpus_objects.py`
- `runner/repos.yaml`

### Root cause

`build_corpus_objects.py` was constructing the clang include path from:

- repo-specific include dirs from `runner/repos.yaml`
- a fixed global include list under `vendor/linux-framework`

That fixed global list was missing arch-specific UAPI/generated-UAPI directories.

For the failing `linux-selftests` path, the include chain was:

- `tools/include/uapi/linux/bpf.h`
- `tools/include/linux/types.h`
- `#include <asm/types.h>`

On this x86_64 host, `asm/types.h` should come from vendored kernel headers, not host headers:

- `vendor/linux-framework/arch/x86/include/generated/uapi/asm/types.h`

Related arch UAPI headers such as `asm/posix_types.h` come from:

- `vendor/linux-framework/arch/x86/include/uapi/asm/posix_types.h`

So the problem was not that `asm/types.h` was absent. The problem was that clang never searched the vendored arch-specific generated UAPI tree.

### Fix applied

I changed `runner/scripts/build_corpus_objects.py` to build the global include list dynamically from the target arch and include:

- `vendor/linux-framework/tools/arch/<arch>/include`
- `vendor/linux-framework/tools/arch/<arch>/include/uapi`
- `vendor/linux-framework/arch/<arch>/include/uapi`
- `vendor/linux-framework/arch/<arch>/include/generated/uapi`
- `vendor/linux-framework/include/generated/uapi`

The script still stays on repo-managed headers only; it does not inject host kernel headers.

### Verification

Command run:

```bash
python3 runner/scripts/build_corpus_objects.py --repo linux-selftests --max-sources 3
```

Observed result:

- `tools/testing/selftests/bpf/progs/access_map_in_map.c`: `ok`
- `tools/testing/selftests/bpf/progs/arena_htab.c`: `ok`
- `tools/testing/selftests/bpf/progs/arena_atomics.c`: `error`

The third failure is no longer `asm/types.h`. It is now a different issue involving `linux/time.h` / `time64_t` / `struct tm` collisions pulled in through `linux/filter.h`.

Conclusion:

- The `asm/types.h` blocker is fixed.
- The requested smoke verification no longer fails on `asm/types.h`.
- There is still a separate remaining compile failure in `arena_atomics.c`, but it is unrelated to the original missing-header problem.

## 2. Attach Failure Investigation

### What I read

- `runner/src/kernel_runner.cpp`
- `corpus/config/macro_corpus.yaml`
- `runner/corpus/results/vm_corpus_20260328_154829/details/result.json`

### Current attach logic

Both kernel attach paths in `runner/src/kernel_runner.cpp` do the same thing:

- pick the selected program
- call `bpf_program__attach(attach_prog)`
- fail immediately if libbpf returns an error

There is no attach-type-specific handling for:

- cgroup programs
- perf event programs
- iterator programs
- netfilter programs
- uprobes / USDT that need explicit binary/provider metadata

So any program type that needs extra attach parameters can load successfully but still fail at attach time.

### Data source and counts

The most useful detailed run artifact is:

- `runner/corpus/results/vm_corpus_20260328_154829/details/result.json`

This run is partial (`status: running`) but it contains per-program records for:

- 205 objects
- 901 program records

Inside that file there are 93 unique program records whose `baseline_run`/`rejit_run` failed with `bpf_program__attach failed: ...`.

Breakdown from that file:

| Recorded `prog_type_name` | Failures |
| --- | ---: |
| `kprobe` | 38 |
| `tracepoint` | 22 |
| `tracing` | 14 |
| `cgroup_sockopt` | 8 |
| `perf_event` | 5 |
| `raw_tracepoint` | 3 |
| `cgroup_sock_addr` | 2 |
| `netfilter` | 1 |

If I count only the categories you listed plus `raw_tracepoint` and `netfilter`, that gives 91. The extra 2 in this March 28, 2026 detailed run are the `cgroup_sock_addr` entries.

### Root causes by category

| Recorded type | Actual failing section families | Root cause |
| --- | --- | --- |
| `kprobe` (38) | `kprobe` 15, `kretprobe` 9, `usdt` 5, `uretprobe` 4, `uprobe` 4, `kprobe.multi` 1 | Mixed bucket. Many `ENOENT` failures are stale/missing kernel symbols or placeholders (`foo`, old block-layer symbols, unavailable kprobe targets). The `uprobe`/`uretprobe`/`usdt` entries need explicit user-space binary or USDT provider metadata, which generic attach does not provide. |
| `tracepoint` (22) | `uprobe` 19, `tracepoint` 2, `kprobe` 1 | This bucket is polluted by corpus metadata. `coroot-node-agent/ebpf.bpf.o` is declared as `prog_type: tracepoint`, but most failing entries are actually `uprobe/...`. Their `EINVAL` failures are caused by missing binary-path/symbol resolution, not tracepoint attach itself. The 2 real tracepoint failures are arch-specific syscall tracepoints absent on the x86 guest. |
| `tracing` (14) | `iter` 11, `iter.s` 2, `fentry` 1 | The iterator programs need iterator-specific target info (`link_info`, map fd, cgroup fd, sockmap fd, etc.). Generic attach returns `EBADF`/`EINVAL` because no iterator target is supplied. The one `fentry` failure (`biosnoop`) returned `EBUSY`. |
| `cgroup_sockopt` (8) | `cgroup/getsockopt` 8 | These need a cgroup fd and `bpf_program__attach_cgroup()`. Generic attach returns `EOPNOTSUPP`. |
| `perf_event` (5) | `perf_event` 5 | These need `perf_event_open()` fds and `bpf_program__attach_perf_event()`. Generic attach returns `EOPNOTSUPP`. |
| `raw_tracepoint` (3) | `raw_tracepoint` 2, `perf_event` 1 | Two failures are `raw_tracepoint/...` sections failing with `EINVAL`; they likely need explicit raw-tracepoint attach instead of relying on generic auto-attach. The remaining one (`find_vma:handle_pe`) is not actually raw-tracepoint at all; it is a `perf_event` program that inherits the wrong object-level type from YAML. |
| `cgroup_sock_addr` (2) | `cgroup/connect6` 1, `sockops` 1 | Same missing-cgroup-fd problem. Also, one failing entry is actually a `sockops` section but inherits `cgroup_sock_addr` from object-level YAML. |
| `netfilter` (1) | `netfilter` 1 | Needs `bpf_program__attach_netfilter()` plus `pf`/`hooknum`/`priority`. Generic attach has no such inputs. |

### Concrete corpus config issues found

These are real YAML metadata problems, but they do not by themselves make attach succeed under the current runner:

1. `coroot-node-agent/ebpf.bpf.o`

- Object-level `prog_type` is `tracepoint`.
- Many programs in that object are actually `uprobe/...` or `kprobe/...`.
- This is why the 22-program `tracepoint` bucket is mostly not tracepoints.

2. `linux-selftests/.../find_vma.bpf.o`

- Object-level `prog_type` is `raw_tracepoint`.
- Program `handle_pe` uses `section: perf_event`.
- So it is misclassified in reporting.

3. `linux-selftests/.../cgrp_ls_attach_cgroup.bpf.o`

- Object-level `prog_type` is `cgroup_sock_addr`.
- Companion programs use `section: sockops` and `section: fexit/...`.
- Those entries inherit the wrong program type in reporting.

### Why I did not patch attach config blindly

I did not make attach-side corpus YAML edits in this change for one reason:

- the dominant failures are not caused by a small typo like a wrong trigger string or wrong `attach_group`

They are caused by missing attach-time inputs or missing attach-mode support in the runner:

- user-space probe target binary / provider / symbol resolution
- cgroup fd selection
- iterator target selection
- perf event creation
- netfilter hook options

Changing only the YAML section text or tags would improve classification, but it would not make these programs attach successfully under the current `kernel_runner.cpp`.

## 3. Safe Conclusions

- Implemented now:
  - fixed corpus-build include path so clang can find vendored `asm/types.h`
- Not implemented now:
  - attach-side runner changes
  - kernel changes
  - corpus entry deletion / compile-only downgrades

The build fix is real and verified. The attach failures need runner-side attach specialization, not kernel patches.

## 4. Recommended Next Steps

1. Add attach-type-specific handling in `kernel_runner.cpp` before the generic fallback:
   - `bpf_program__attach_cgroup()` for `cgroup_sockopt`, `cgroup_sock_addr`, and `sockops`
   - `bpf_program__attach_perf_event()` for `perf_event`
   - `bpf_program__attach_raw_tracepoint()` for `raw_tracepoint`
   - `bpf_program__attach_netfilter()` for `netfilter`
   - iterator-specific `bpf_program__attach_iter()` with proper `link_info`

2. Add explicit corpus metadata for attach targets where generic section names are insufficient:
   - uprobe binary path
   - symbol/provider name
   - cgroup path
   - perf event spec
   - iterator target info
   - netfilter hook metadata

3. Clean up misclassified `prog_type` metadata in `macro_corpus.yaml` so failure summaries reflect the actual attach family.
