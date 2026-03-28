# Expanded Corpus Build Results

- Generated: `2026-03-28T19:43:54.205762+00:00`
- Manifest: `/home/yunwei37/workspace/bpf-benchmark/runner/repos.yaml`
- Repo root: `/home/yunwei37/workspace/bpf-benchmark/runner/repos`
- Macro corpus: `/home/yunwei37/workspace/bpf-benchmark/corpus/config/macro_corpus.yaml`
- Build root: `/home/yunwei37/workspace/bpf-benchmark/corpus/build`
- Sources considered: 1192
- Built from source: 740
- Staged existing objects: 115
- Available objects: 855
- Failures: 337

## Per-Repo Summary

| Repo | ok | existing | error | timeout |
| --- | ---: | ---: | ---: | ---: |
| KubeArmor | 0 | 3 | 0 | 0 |
| bcc | 57 | 0 | 0 | 0 |
| calico | 0 | 8 | 0 | 0 |
| cilium | 0 | 3 | 9 | 0 |
| coroot-node-agent | 0 | 1 | 0 | 0 |
| datadog-agent | 0 | 1 | 0 | 0 |
| katran | 0 | 5 | 2 | 0 |
| libbpf-bootstrap | 13 | 0 | 2 | 0 |
| linux-selftests | 649 | 6 | 267 | 0 |
| loxilb | 0 | 3 | 0 | 0 |
| manual-test | 0 | 2 | 0 | 0 |
| netbird | 0 | 1 | 1 | 0 |
| opentelemetry-ebpf-profiler | 0 | 3 | 0 | 0 |
| real_world_code_size | 0 | 15 | 0 | 0 |
| scx | 0 | 4 | 0 | 0 |
| suricata | 0 | 2 | 0 | 0 |
| systemd | 4 | 6 | 2 | 0 |
| tetragon | 0 | 23 | 28 | 0 |
| tracee | 0 | 1 | 0 | 0 |
| tubular | 0 | 1 | 0 | 0 |
| xdp-examples | 5 | 0 | 8 | 0 |
| xdp-tools | 3 | 13 | 11 | 0 |
| xdp-tutorial | 9 | 14 | 7 | 0 |

## Failure Stages

| Stage | Count |
| --- | ---: |
| clang | 337 |

## Top Errors

| Error | Count |
| --- | ---: |
| 1 error generated. | 35 |
| ... | 7 |
| 159912 | extern int bpf_path_d_path(struc... | 6 |
| 159912 | extern int bpf_path_d_path(struct... | 6 |
| 159863 | extern void *bpf_dynptr_slice(const struct bpf_... | 5 |
| 159912 | extern int bpf_path_d_path(struct ... | 4 |
| 11 | int get_timespec64(str... | 4 |
| 159863 | extern void *bpf_dynptr_slice(const struct bpf... | 4 |
| 159912 | extern int bpf_path_d_path(struct pa... | 4 |
| /home/yunwei37/workspace/bpf-... | 4 |
| 159912 | extern int bpf_path_d_path(s... | 4 |
| 11 | int get_timespec64(struct t... | 4 |
| /home/yunw... | 3 |
| 11 | int get_timespec64(struc... | 3 |
| /home/y... | 3 |
| 159863 | extern void *bpf_dynptr_slice(const struct bpf_dynp... | 3 |
| /usr/lib/llvm-18/lib/clang/18/include/__stddef_wchar_t.h:24:24: error: typedef redefinition with different ... | 3 |
| 11 | int get_timespec64(struct ti... | 3 |
| 159863 | extern void *bpf_dynptr_slice(const struct ... | 3 |
| 159912 | extern int bpf_path_d_path(st... | 3 |

## Sample Failures

| Repo | Path | Stage | Error |
| --- | --- | --- | --- |
| cilium | bpf/bpf_alignchecker.c | clang | /home/yunwei37/workspace/bpf-bench... |
| cilium | bpf/bpf_host.c | clang | ... |
| cilium | bpf/bpf_lxc.c | clang | ... |
| cilium | bpf/bpf_overlay.c | clang | ... |
| cilium | bpf/bpf_probes.c | clang | /home/yunwei37/workspace/bpf-benchmark/r... |
| cilium | bpf/bpf_sock.c | clang | /home/yunwei37/workspace/bpf-benchmark/run... |
| cilium | bpf/bpf_sock_term.c | clang | /home/yunwei37/workspace/bpf-benchmar... |
| cilium | bpf/bpf_wireguard.c | clang | 13 |         false   = 0... |
| cilium | bpf/bpf_xdp.c | clang | In file included from /home/yunwei37/workspace/b... |
| katran | katran/lib/bpf/balancer.bpf.c | clang | /home/yunwei37/workspace/bpf-benchma... |
| katran | katran/lib/bpf/healthchecking.bpf.c | clang | | ... |
| libbpf-bootstrap | examples/c/minimal_ns.bpf.c | clang | 1 error generated. |
| libbpf-bootstrap | examples/c/sockfilter.bpf.c | clang | |... |
| linux-selftests | tools/testing/selftests/bpf/progs/arena_atomics.c | clang | In file included from /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/tools/i... |
| linux-selftests | tools/testing/selftests/bpf/progs/arena_spin_lock.c | clang | /home/yunwei37/workspace/bpf-benchmark/runner/repos/linux-selftests/tools/testing/selftests/bpf/bpf_experimental.h:222:12: error: conflicting types for 'bpf_path_d_path'... |
| linux-selftests | tools/testing/selftests/bpf/progs/arena_strsearch.c | clang | 159912 | extern int bpf_path_d_path(struc... |
| linux-selftests | tools/testing/selftests/bpf/progs/bad_struct_ops.c | clang | /usr/lib/llvm-18/lib/clang/18/include/__stddef_wchar_t.h:24:24: error: typedef redefinition with different typ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bind4_prog.c | clang | /home/yunw... |
| linux-selftests | tools/testing/selftests/bpf/progs/bind6_prog.c | clang | /home/yunw... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_flow.c | clang | /home/yunwei... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_setsockopt_unix.c | clang | In file included from /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/tools/include... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_tcp4.c | clang | |                  ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_tcp6.c | clang | |                  ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_udp4.c | clang | /home/yunwei37/workspace/bpf-benchmark/vend... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_iter_udp6.c | clang | /home/yunwei37/workspace/bpf-benchmark/vend... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_qdisc_fail__incompl_ops.c | clang | 159912 | extern int bpf_path_... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_qdisc_fifo.c | clang | 159912 | extern int bpf_path_d_path(struct... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_qdisc_fq.c | clang | 159912 | extern int bpf_path_d_path(struct ... |
| linux-selftests | tools/testing/selftests/bpf/progs/bpf_smc.c | clang | /home/yunwei37/workspace/bpf-benchmark/runner/rep... |
| linux-selftests | tools/testing/selftests/bpf/progs/btf_type_tag_percpu.c | clang | |                         ~~... |
| linux-selftests | tools/testing/selftests/bpf/progs/cg_storage_multi_egress_only.c | clang | 11 | int get_timespec64(... |
| linux-selftests | tools/testing/selftests/bpf/progs/cg_storage_multi_isolated.c | clang | 11 | int get_timespec64(str... |
| linux-selftests | tools/testing/selftests/bpf/progs/cg_storage_multi_shared.c | clang | 11 | int get_timespec64(struc... |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_iter_memcg.c | clang | /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/... |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_read_xattr.c | clang | 159912 | extern int bpf_path_d_path(str... |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_skb_sk_lookup_kern.c | clang | In file included from /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/tools/include/linu... |
| linux-selftests | tools/testing/selftests/bpf/progs/cgroup_tcp_skb.c | clang | In file included from /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/tools/include/linux/build_bug... |
| linux-selftests | tools/testing/selftests/bpf/progs/compute_live_registers.c | clang | In file included from /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framewor... |
| linux-selftests | tools/testing/selftests/bpf/progs/connect4_prog.c | clang | /home/y... |
| linux-selftests | tools/testing/selftests/bpf/progs/connect6_prog.c | clang | /home/y... |
| linux-selftests | tools/testing/selftests/bpf/progs/connect_force_port4.c | clang | /... |
| linux-selftests | tools/testing/selftests/bpf/progs/connect_force_port6.c | clang | /... |
| linux-selftests | tools/testing/selftests/bpf/progs/connect_unix_prog.c | clang | 159863 | extern void *bpf_dynptr_slice(const struct bpf_... |
| linux-selftests | tools/testing/selftests/bpf/progs/crypto_basic.c | clang | 159863 | extern void *bpf_dynptr_slice(const struct bpf_dynpt... |
| linux-selftests | tools/testing/selftests/bpf/progs/crypto_bench.c | clang | 159863 | extern void *bpf_dynptr_slice(const struct bpf_dynp... |
| linux-selftests | tools/testing/selftests/bpf/progs/crypto_sanity.c | clang | 159863 | extern void *bpf_dynptr_slice(const struct bpf_dyn... |
| linux-selftests | tools/testing/selftests/bpf/progs/dmabuf_iter.c | clang | |              ... |
| linux-selftests | tools/testing/selftests/bpf/progs/dynptr_fail.c | clang | In file included from /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/tools/include/linux/build_bug.h... |
| linux-selftests | tools/testing/selftests/bpf/progs/dynptr_success.c | clang | /home/yunwei37/workspace/bpf-benchmark/corpus/build/lin... |
| linux-selftests | tools/testing/selftests/bpf/progs/epilogue_exit.c | clang | /usr/lib/llvm-18/lib/clang/18/include/__stddef_wchar_t.h:24:24: error: typedef redefinition with different type... |

## Notes

- The builder scans repo sources directly from `runner/repos.yaml`.
- Global include paths are pinned to repo-managed libbpf and `vendor/linux-framework` headers; host `/usr/include` is not injected.
- Macro-corpus objects that are already present under `corpus/build/` are recorded as `existing` so `vm-corpus` can validate one strict availability report.
