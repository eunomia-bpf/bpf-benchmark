# Expanded Corpus Build Results

- Generated: `2026-03-10T20:17:25.522718+00:00`
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/repos.yaml`
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/corpus/inventory.json`
- Build root: `/home/yunwei37/workspace/bpf-benchmark/corpus/build`
- Sources considered: 20
- Compiled successfully: 6
- Compile failures: 14

## Per-Repo Summary

| Repo | ok | error | timeout |
| --- | ---: | ---: | ---: |
| linux-selftests | 6 | 14 | 0 |

## Failure Stages

| Stage | Count |
| --- | ---: |
| clang | 14 |

## Top Errors

| Error | Count |
| --- | ---: |
| |                                                                             ... | 2 |
| |                                                                        ... | 2 |
| In file included from /home/yunwei37/workspace/bpf-benchmark/corpus/repos/linux-selftests/include/linux/... | 2 |
| |                                                                         ... | 1 |
| /home/yunwei37/workspace/bpf-benchmark/corpus/repos/linux-selftests/tools/testing/selftests/bpf/bpf_experimental.h:222:12: error: conflicting types for 'bpf_path_d_path'... | 1 |
| 159912 | extern int bpf_path_d_path(struc... | 1 |
| |                                                                                   ... | 1 |
| /usr/lib/llvm-18/lib/clang/18/include/__stddef_wchar_t.h:24:24: error: typedef redefinition with different types ('int' vs 'u... | 1 |
| |                                                                           ... | 1 |
| |                                                                                 ... | 1 |
| |                                                                          ... | 1 |

## Sample Failures

| Repo | Source | Stage | Error |
| --- | --- | --- | --- |
| linux-selftests | tools/testing/selftests/bpf/progs/access_map_in_map.c | clang | |                                                                         ... |
| linux-selftests | tools/testing/selftests/bpf/progs/arena_atomics.c | clang | |                                                                             ... |
| linux-selftests | tools/testing/selftests/bpf/progs/arena_spin_lock.c | clang | /home/yunwei37/workspace/bpf-benchmark/corpus/repos/linux-selftests/tools/testing/selftests/bpf/bpf_experimental.h:222:12: error: conflicting types for 'bpf_path_d_path'... |
| linux-selftests | tools/testing/selftests/bpf/progs/arena_strsearch.c | clang | 159912 | extern int bpf_path_d_path(struc... |
| linux-selftests | tools/testing/selftests/bpf/progs/atomic_bounds.c | clang | |                                                                             ... |
| linux-selftests | tools/testing/selftests/bpf/progs/atomics.c | clang | |                                                                                   ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bad_struct_ops.c | clang | /usr/lib/llvm-18/lib/clang/18/include/__stddef_wchar_t.h:24:24: error: typedef redefinition with different types ('int' vs 'u... |
| linux-selftests | tools/testing/selftests/bpf/progs/bad_struct_ops2.c | clang | |                                                                           ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bench_sockmap_prog.c | clang | |                                                                        ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bind4_prog.c | clang | In file included from /home/yunwei37/workspace/bpf-benchmark/corpus/repos/linux-selftests/include/linux/... |
| linux-selftests | tools/testing/selftests/bpf/progs/bind6_prog.c | clang | In file included from /home/yunwei37/workspace/bpf-benchmark/corpus/repos/linux-selftests/include/linux/... |
| linux-selftests | tools/testing/selftests/bpf/progs/bind_perm.c | clang | |                                                                                 ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bloom_filter_bench.c | clang | |                                                                        ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bloom_filter_map.c | clang | |                                                                          ... |

## Notes

- The builder keeps going across compile failures and records both `clang` and `bpftool gen object` errors.
- Output objects are written under `corpus/build/<repo>/...` and keep the source-relative path to avoid filename collisions.
- Include paths are intentionally broad; many upstream programs still fail due to repo-specific build systems, generated headers, or kernel feature assumptions.
