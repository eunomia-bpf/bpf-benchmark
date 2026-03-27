# Expanded Corpus Build Results

- Generated: `2026-03-27T17:04:23.413984+00:00`
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/runner/repos.yaml`
- Repo root: `/home/yunwei37/workspace/bpf-benchmark/runner/repos`
- Macro corpus: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_corpus.yaml`
- Build root: `/home/yunwei37/workspace/bpf-benchmark/corpus/build`
- Sources considered: 1213
- Built from source: 429
- Staged existing objects: 134
- Available objects: 563
- Failures: 650

## Per-Repo Summary

| Repo | ok | existing | error | timeout |
| --- | ---: | ---: | ---: | ---: |
| KubeArmor | 0 | 3 | 0 | 0 |
| bcc | 57 | 0 | 0 | 0 |
| bpftrace | 0 | 5 | 0 | 0 |
| calico | 0 | 8 | 0 | 0 |
| cilium | 0 | 3 | 9 | 0 |
| coroot-node-agent | 0 | 1 | 0 | 0 |
| datadog-agent | 0 | 1 | 0 | 0 |
| katran | 0 | 5 | 2 | 0 |
| libbpf-bootstrap | 11 | 1 | 4 | 0 |
| linux-selftests | 361 | 7 | 555 | 0 |
| loxilb | 0 | 3 | 0 | 0 |
| manual-test | 0 | 2 | 0 | 0 |
| netbird | 0 | 1 | 1 | 0 |
| opentelemetry-ebpf-profiler | 0 | 3 | 0 | 0 |
| real_world_code_size | 0 | 15 | 0 | 0 |
| scx | 0 | 4 | 0 | 0 |
| suricata | 0 | 2 | 0 | 0 |
| systemd | 0 | 8 | 6 | 0 |
| tetragon | 0 | 23 | 28 | 0 |
| tracee | 0 | 2 | 0 | 0 |
| tubular | 0 | 1 | 0 | 0 |
| xdp-examples | 0 | 0 | 13 | 0 |
| xdp-tools | 0 | 13 | 14 | 0 |
| xdp-tutorial | 0 | 23 | 18 | 0 |

## Failure Stages

| Stage | Count |
| --- | ---: |
| clang | 648 |
| missing_object | 2 |

## Top Errors

| Error | Count |
| --- | ---: |
| 1 error generated. | 355 |
| PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, and a... | 9 |
| 159912 | extern int bpf_path_d_path(struc... | 6 |
| 159912 | extern int bpf_path_d_path(struct... | 6 |
| PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, and ... | 6 |
| PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, a... | 6 |
| PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, and... | 6 |
| PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed sou... | 5 |
| PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source,... | 5 |
| 159863 | extern void *bpf_dynptr_slice(const struct bpf_... | 5 |
| PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed sourc... | 5 |
| 159912 | extern int bpf_path_d_path(struct ... | 4 |
| PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, and ass... | 4 |
| 159863 | extern void *bpf_dynptr_slice(const struct bpf... | 4 |
| 159912 | extern int bpf_path_d_path(struct pa... | 4 |
| /home/yunwei37/workspace/bpf-... | 4 |
| 159912 | extern int bpf_path_d_path(s... | 4 |
| ... | 4 |
| PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, and associated run scri... | 4 |
| PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, and asso... | 3 |

## Sample Failures

| Repo | Path | Stage | Error |
| --- | --- | --- | --- |
| cilium | bpf/bpf_alignchecker.c | clang | 13 | #incl... |
| cilium | bpf/bpf_host.c | clang | PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues... |
| cilium | bpf/bpf_lxc.c | clang | PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/... |
| cilium | bpf/bpf_overlay.c | clang | PLEASE submit a bug report to https://github.com/llvm/llvm-project/iss... |
| cilium | bpf/bpf_probes.c | clang | 13 | #include <a... |
| cilium | bpf/bpf_sock.c | clang | 13 | #include <asm... |
| cilium | bpf/bpf_sock_term.c | clang | 13 | #include... |
| cilium | bpf/bpf_wireguard.c | clang | PLEASE submit a bug report to https://github.com/llvm/llvm-project/i... |
| cilium | bpf/bpf_xdp.c | clang | In file included from /home/yunwei37/workspace/bp... |
| katran | katran/lib/bpf/balancer.bpf.c | clang | Stack du... |
| katran | katran/lib/bpf/healthchecking.bpf.c | clang | In file included ... |
| libbpf-bootstrap | examples/c/minimal.bpf.c | clang | 1 error generated. |
| libbpf-bootstrap | examples/c/minimal_legacy.bpf.c | clang | 1 error generated. |
| libbpf-bootstrap | examples/c/minimal_ns.bpf.c | clang | 1 error generated. |
| libbpf-bootstrap | examples/c/sockfilter.bpf.c | clang | PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, and associated run script.... |
| linux-selftests | tools/testing/selftests/bpf/progs/access_map_in_map.c | clang | 1 error generated. |
| linux-selftests | tools/testing/selftests/bpf/progs/arena_atomics.c | clang | PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, and a... |
| linux-selftests | tools/testing/selftests/bpf/progs/arena_spin_lock.c | clang | /home/yunwei37/workspace/bpf-benchmark/runner/repos/linux-selftests/tools/testing/selftests/bpf/bpf_experimental.h:222:12: error: conflicting types for 'bpf_path_d_path'... |
| linux-selftests | tools/testing/selftests/bpf/progs/arena_strsearch.c | clang | 159912 | extern int bpf_path_d_path(struc... |
| linux-selftests | tools/testing/selftests/bpf/progs/atomic_bounds.c | clang | 1 error generated. |
| linux-selftests | tools/testing/selftests/bpf/progs/atomics.c | clang | 1 error generated. |
| linux-selftests | tools/testing/selftests/bpf/progs/bad_struct_ops.c | clang | /usr/lib/llvm-18/lib/clang/18/include/__stddef_wchar_t.h:24:24: error: typedef redefinition with different typ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bad_struct_ops2.c | clang | 1 error generated. |
| linux-selftests | tools/testing/selftests/bpf/progs/bench_sockmap_prog.c | clang | 1 error generated. |
| linux-selftests | tools/testing/selftests/bpf/progs/bind4_prog.c | clang | PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, and asso... |
| linux-selftests | tools/testing/selftests/bpf/progs/bind6_prog.c | clang | PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed source, and asso... |
| linux-selftests | tools/testing/selftests/bpf/progs/bind_perm.c | clang | 1 error generated. |
| linux-selftests | tools/testing/selftests/bpf/progs/bloom_filter_bench.c | clang | 1 error generated. |
| linux-selftests | tools/testing/selftests/bpf/progs/bloom_filter_map.c | clang | 1 error generated. |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_flow.c | clang | /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/tools/include/linux/types.h:13:10: fatal error: 'as... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_setsockopt_unix.c | clang | In file included from /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/tools/include... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_tcp4.c | clang | |                  ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_tcp6.c | clang | |                  ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_udp4.c | clang | /home/yunwei37/workspace/bpf-benchmark/vend... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_udp6.c | clang | /home/yunwei37/workspace/bpf-benchmark/vend... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_qdisc_fail__incompl_ops.c | clang | 159912 | extern int bpf_path_... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_qdisc_fifo.c | clang | 159912 | extern int bpf_path_d_path(struct... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_qdisc_fq.c | clang | 159912 | extern int bpf_path_d_path(struct ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_smc.c | clang | /home/yunwei37/workspace/bpf-benchmark/runner/rep... |
| linux-selftests | tools/testing/selftests/bpf/progs/bprm_opts.c | clang | 1 error generated. |
| linux-selftests | tools/testing/selftests/bpf/progs/btf_type_tag_percpu.c | clang | |                         ~~... |
| linux-selftests | tools/testing/selftests/bpf/progs/cg_storage_multi_egress_only.c | clang | PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocesse... |
| linux-selftests | tools/testing/selftests/bpf/progs/cg_storage_multi_isolated.c | clang | PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed s... |
| linux-selftests | tools/testing/selftests/bpf/progs/cg_storage_multi_shared.c | clang | PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed sou... |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_getset_retval_getsockopt.c | clang | 1 error generated. |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_getset_retval_hooks.c | clang | 1 error generated. |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_getset_retval_setsockopt.c | clang | 1 error generated. |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_iter_memcg.c | clang | /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/... |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_read_xattr.c | clang | 159912 | extern int bpf_path_d_path(str... |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_skb_sk_lookup_kern.c | clang | PLEASE submit a bug report to https://github.com/llvm/llvm-project/issues/ and include the crash backtrace, preprocessed s... |

## Notes

- The builder scans repo sources directly from `runner/repos.yaml`.
- Global include paths are pinned to repo-managed libbpf and `vendor/linux-framework` headers; host `/usr/include` is not injected.
- Macro-corpus objects that are already present under `corpus/build/` are recorded as `existing` so `vm-corpus` can validate one strict availability report.
