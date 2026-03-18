# Expanded Corpus Build Results

- Generated: `2026-03-10T20:18:07.122802+00:00`
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/corpus/repos.yaml`
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/corpus/inventory.json`
- Build root: `/home/yunwei37/workspace/bpf-benchmark/corpus/build`
- Sources considered: 1070
- Compiled successfully: 429
- Compile failures: 641

## Per-Repo Summary

| Repo | ok | error | timeout |
| --- | ---: | ---: | ---: |
| bcc | 57 | 0 | 0 |
| cilium | 0 | 9 | 0 |
| katran | 0 | 2 | 0 |
| libbpf-bootstrap | 11 | 4 | 0 |
| linux-selftests | 361 | 555 | 0 |
| tetragon | 0 | 28 | 0 |
| xdp-examples | 0 | 13 | 0 |
| xdp-tools | 0 | 14 | 0 |
| xdp-tutorial | 0 | 16 | 0 |

## Failure Stages

| Stage | Count |
| --- | ---: |
| clang | 641 |

## Top Errors

| Error | Count |
| --- | ---: |
| |                                                                        ... | 35 |
| 1 error generated. | 34 |
| |                                                                         ... | 32 |
| |                                                                             ... | 25 |
| |                                                                      ... | 22 |
| |                                                                            ... | 18 |
| |                                                                              ... | 18 |
| |                                                                   ... | 17 |
| |                                                                          ... | 16 |
| |                                                                       ... | 15 |
| |                                                                                 ... | 14 |
| |                                                                           ... | 13 |
| |                                                                    ... | 13 |
| |                                                                     ... | 13 |
| ... | 9 |
| |                                                                ... | 8 |
| |                                                                  ... | 8 |
| |                                                                 ... | 7 |
| |                                                                               ... | 7 |
| |                                                               ... | 7 |

## Sample Failures

| Repo | Source | Stage | Error |
| --- | --- | --- | --- |
| cilium | bpf/bpf_alignchecker.c | clang | /home/yunwei37/workspace/bpf-bench... |
| cilium | bpf/bpf_host.c | clang | ... |
| cilium | bpf/bpf_lxc.c | clang | ... |
| cilium | bpf/bpf_overlay.c | clang | ... |
| cilium | bpf/bpf_probes.c | clang | /home/yunwei37/workspace/bpf-benchmark/c... |
| cilium | bpf/bpf_sock.c | clang | /home/yunwei37/workspace/bpf-benchmark/cor... |
| cilium | bpf/bpf_sock_term.c | clang | /home/yunwei37/workspace/bpf-benchmar... |
| cilium | bpf/bpf_wireguard.c | clang | 13 |         false   = 0... |
| cilium | bpf/bpf_xdp.c | clang | ... |
| katran | katran/lib/bpf/balancer.bpf.c | clang | /usr/include/linux/... |
| katran | katran/lib/bpf/healthchecking.bpf.c | clang | In f... |
| libbpf-bootstrap | examples/c/minimal.bpf.c | clang | 1063 | static __s64 (*bpf_csum_update)(stru... |
| libbpf-bootstrap | examples/c/minimal_legacy.bpf.c | clang | 1063 | static __s64 (*bpf_csum_updat... |
| libbpf-bootstrap | examples/c/minimal_ns.bpf.c | clang | 1063 | static __s64 (*bpf_csum_update)(s... |
| libbpf-bootstrap | examples/c/sockfilter.bpf.c | clang | 796 | static __s64 (*bpf_csum_diff)(__be32 *from, __u32 from_size, __be32 *to, __u32 to_size, __wsum s... |
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
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_flow.c | clang | In file included from /home/yunwei37/workspace/bpf-benchmark/corpus/repos/linux-selftests/include/linux/mm... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_setsockopt_unix.c | clang | In file included from /home/yunwei37/workspace/bpf-benchmark/vendor/libbpf/include/linux/ty... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_tcp4.c | clang | |                  ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_tcp6.c | clang | |                  ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_udp4.c | clang | /home/yunwei37/workspace/bpf-benchmar... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_udp6.c | clang | /home/yunwei37/workspace/bpf-benchmar... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_qdisc_fail__incompl_ops.c | clang | 159912 | extern int bpf_path_... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_qdisc_fifo.c | clang | 159912 | extern int bpf_path_d_path(struct... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_qdisc_fq.c | clang | 159912 | extern int bpf_path_d_path(struct ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_smc.c | clang | /home/yunwei37/workspace/bpf-benchmark/corpus/rep... |
| linux-selftests | tools/testing/selftests/bpf/progs/bprm_opts.c | clang | |                                                                                 ... |
| linux-selftests | tools/testing/selftests/bpf/progs/btf_type_tag_percpu.c | clang | |                         ~~... |
| linux-selftests | tools/testing/selftests/bpf/progs/cg_storage_multi_egress_only.c | clang | 11 | i... |
| linux-selftests | tools/testing/selftests/bpf/progs/cg_storage_multi_isolated.c | clang | 11 | int ... |
| linux-selftests | tools/testing/selftests/bpf/progs/cg_storage_multi_shared.c | clang | 11 | int ge... |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_getset_retval_getsockopt.c | clang | |                                                           ... |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_getset_retval_hooks.c | clang | |                                                                ... |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_getset_retval_setsockopt.c | clang | |                                                           ... |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_iter_memcg.c | clang | /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/... |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_read_xattr.c | clang | 159912 | extern int bpf_path_d_path(str... |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_skb_sk_lookup_kern.c | clang | |                                                                 ... |

## Notes

- The builder keeps going across compile failures and records both `clang` and `bpftool gen object` errors.
- Output objects are written under `corpus/build/<repo>/...` and keep the source-relative path to avoid filename collisions.
- Include paths are intentionally broad; many upstream programs still fail due to repo-specific build systems, generated headers, or kernel feature assumptions.
