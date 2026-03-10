# Expanded Corpus Results

Date: 2026-03-10

Commands run:

- `source /home/yunwei37/workspace/.venv/bin/activate && python3 micro/directive_census.py`
- `source /home/yunwei37/workspace/.venv/bin/activate && sudo python3 micro/run_corpus_perf.py`
- `./micro/run_corpus_tracing.sh --filter biolatency.bpf.o --filter biopattern.bpf.o --filter biostacks.bpf.o --filter biotop.bpf.o --filter bitesize.bpf.o --filter filelife.bpf.o --filter filetop.bpf.o --filter fsdist.bpf.o --filter funclatency.bpf.o --filter ksnoop.bpf.o --filter readahead.bpf.o --filter runqlat.bpf.o --filter tcprtt.bpf.o --filter tcpsynbl.bpf.o --filter bpf_mod_race.bpf.o --filter lru_bug.bpf.o --filter mptcpify.bpf.o --filter test_overhead.bpf.o --filter test_varlen.bpf.o`

Existing script status before this run:

- `micro/run_corpus_perf.py` already existed as an untracked script.
- `micro/run_corpus_tracing.py` already existed as an untracked tracing harness.
- `micro/run_corpus_tracing.sh` was added in this session as a shell entrypoint to the Python tracing harness.

## 1. Corpus inventory

`corpus/build/` currently contains directories for:

- `bcc`
- `cilium`
- `katran`
- `libbpf-bootstrap`
- `linux-selftests`
- `manual-test`
- `real_world_code_size`
- `tetragon`
- `xdp-examples`
- `xdp-tools`
- `xdp-tutorial`

Filesystem inventory across all `corpus/**/*.bpf.o` files:

| Source | .bpf.o count |
| --- | ---: |
| bcc | 57 |
| bcf/bcc | 8 |
| bcf/collected | 9 |
| libbpf-bootstrap | 12 |
| linux-selftests | 361 |
| manual-test | 2 |
| real_world_code_size | 15 |
| repos/libbpf-bootstrap | 4 |
| Total | 468 |

Actual `.bpf.o` counts under `corpus/build/*`:

| corpus/build source | .bpf.o count |
| --- | ---: |
| bcc | 57 |
| cilium | 0 |
| katran | 0 |
| libbpf-bootstrap | 12 |
| linux-selftests | 361 |
| manual-test | 2 |
| real_world_code_size | 15 |
| tetragon | 0 |
| xdp-examples | 0 |
| xdp-tools | 0 |
| xdp-tutorial | 0 |
| Total | 447 |

Important discovery detail:

- `micro/directive_census.py`, `micro/run_corpus_perf.py`, and `micro/run_corpus_tracing.py` all defaulted to `corpus/results/expanded_corpus_build.json` when present.
- That build report currently points to 429 expanded-build objects from `bcc`, `libbpf-bootstrap`, and `linux-selftests`.
- The 39 remaining `.bpf.o` files on disk are legacy corpus artifacts outside the expanded-build report (`bcf/*`, `manual-test`, `real_world_code_size`, `repos/libbpf-bootstrap`).

Program inventory for the expanded-build corpus used by the perf and tracing harnesses:

| Source | Programs discovered |
| --- | ---: |
| bcc | 365 |
| libbpf-bootstrap | 20 |
| linux-selftests | 874 |
| Total | 1259 |

Program kinds in the expanded-build corpus:

| Program kind | Count |
| --- | ---: |
| tracing | 619 |
| tp_btf | 134 |
| tc | 126 |
| syscall | 74 |
| struct_ops | 49 |
| iter | 40 |
| cgroup | 28 |
| tp | 25 |
| perf_event | 20 |
| lsm.s | 18 |
| xdp | 13 |
| sockops | 12 |
| netfilter | 9 |
| socket | 9 |
| iter.s | 8 |
| lsm_cgroup | 8 |
| uprobe.multi | 8 |
| freplace | 7 |
| ksyscall | 6 |
| sk_skb | 5 |
| sk_msg | 5 |
| fentry.s | 4 |
| uprobe.s | 4 |
| uprobe.session | 4 |
| cgroup_skb | 3 |
| struct_ops.s | 2 |
| uprobe.multi.s | 2 |
| abc | 2 |
| custom | 2 |
| uretprobe.multi | 2 |
| xdp.frags | 2 |
| fmod_ret.s | 1 |
| tcx | 1 |
| kretsyscall | 1 |
| uretprobe.s | 1 |
| xyz | 1 |
| uretprobe.multi.s | 1 |
| flow_dissector | 1 |
| sk_lookup | 1 |
| sk_reuseport | 1 |
| Total | 1259 |

## 2. Directive census

`python3 micro/directive_census.py` wrote `docs/tmp/real-program-directive-census.md` and reported:

- 491 total objects scanned
- 3007 total candidate sites
- 0 non-BPF artifacts skipped

That 491-object total is:

- 62 micro benchmark objects
- 429 expanded-build corpus objects

Expanded-build corpus census summary:

- 57 / 429 corpus objects have at least one directive site
- 1999 total directive sites in the real-program corpus
- Family totals: `CMOV=182`, `WIDE=7`, `ROTATE=1810`, `LEA=0`

By source:

| Source in expanded build report | Objects | Objects with sites | Total sites |
| --- | ---: | ---: | ---: |
| bcc | 57 | 20 | 109 |
| libbpf-bootstrap | 11 | 0 | 0 |
| linux-selftests | 361 | 37 | 1890 |
| Total | 429 | 57 | 1999 |

Program-level directive-bearing coverage from the expanded-build runtime inventory:

- 80 program sections with directive sites
- 30 from `bcc`
- 50 from `linux-selftests`

Directive-bearing programs by kind:

- `tracing`: 35
- `tc`: 16
- `struct_ops`: 5
- `tp_btf`: 5
- `iter`: 4
- `lsm.s`: 3
- `sk_msg`: 3
- `uprobe.multi`: 3
- `xdp`: 1
- `tp`: 1
- `syscall`: 1
- `perf_event`: 1
- `sockops`: 1
- `lsm_cgroup`: 1

Highest-site new programs:

| Program | Section root | Total sites | CMOV | WIDE | ROTATE | LEA |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| test_verif_scale2.bpf.o:balancer_ingress | tc | 992 | 0 | 0 | 992 | 0 |
| core_kern.bpf.o:balancer_ingress | tc | 818 | 0 | 0 | 818 | 0 |
| biolatency.bpf.o:block_rq_complete | raw_tp | 6 | 6 | 0 | 0 | 0 |
| biolatency.bpf.o:block_rq_complete_btf | tp_btf | 6 | 6 | 0 | 0 | 0 |
| biostacks.bpf.o:block_io_done | tp_btf | 6 | 6 | 0 | 0 | 0 |
| fsdist.bpf.o:file_open_exit | kretprobe | 6 | 6 | 0 | 0 | 0 |
| runqlat.bpf.o:handle_sched_switch | raw_tp | 6 | 6 | 0 | 0 | 0 |
| runqlat.bpf.o:sched_switch | tp_btf | 6 | 6 | 0 | 0 | 0 |
| readahead.bpf.o:folio_mark_accessed | fentry | 5 | 5 | 0 | 0 | 0 |
| readahead.bpf.o:mark_page_accessed | fentry | 5 | 5 | 0 | 0 | 0 |
| xdp_synproxy_kern.bpf.o:syncookie_tc | tc | 5 | 2 | 3 | 0 | 0 |
| xdp_synproxy_kern.bpf.o:syncookie_xdp | xdp | 5 | 2 | 3 | 0 | 0 |

Takeaway:

- Real-program directive sites are dominated numerically by two huge Linux selftest TC programs (`test_verif_scale2` and `core_kern`), both driven entirely by `ROTATE`.
- Outside those two outliers, the new real-world directive-bearing programs are mostly CMOV-heavy tracing programs from BCC.

## 3. Corpus performance results

`sudo python3 micro/run_corpus_perf.py` completed successfully on the 429-object expanded-build corpus with the default `--repeat 200`.

Summary:

| Metric | Value |
| --- | ---: |
| Programs found | 1259 |
| Loadable programs | 856 |
| Baseline-runnable programs | 273 |
| Recompile-runnable programs | 273 |
| Paired measurements | 273 |
| Directive-bearing loadable programs | 80 |
| Directive-bearing paired programs | 29 |
| Correctness mismatches | 0 |
| Speedup geomean | 1.0023x |
| Speedup median | 1.0129x |
| Speedup min | 0.3449x |
| Speedup max | 3.0575x |

Notes on failures:

- 422 failures were `bpf_prog_test_run_opts failed: Unknown error 524`.
- 32 failures were `bpf_prog_test_run_opts failed: Operation not supported`.
- 116 failures were `bpf_prog_test_run_opts failed: Bad address`.
- 250 objects failed to load with `Invalid argument`.
- 81 objects failed to load with `Permission denied`.
- 67 objects failed to load with `No such process`.
- The `524` and `Operation not supported` buckets are consistent with the expected unsupported tracing/test-run cases.

Highest-site directive-bearing programs with paired runtime measurements:

| Program | Root | Sites | Baseline exec_ns | Recompile exec_ns | Speedup |
| --- | --- | ---: | ---: | ---: | ---: |
| test_verif_scale2.bpf.o:balancer_ingress | tc | 992 | 691 | 637 | 1.0848x |
| core_kern.bpf.o:balancer_ingress | tc | 818 | 593 | 502 | 1.1813x |
| runqlat.bpf.o:handle_sched_switch | raw_tp | 6 | 4514 | 3937 | 1.1466x |
| biolatency.bpf.o:block_rq_complete | raw_tp | 6 | 4411 | 5937 | 0.7430x |
| readahead.bpf.o:folio_mark_accessed | fentry | 5 | 3510 | 2057 | 1.7064x |
| readahead.bpf.o:mark_page_accessed | fentry | 5 | 2266 | 1687 | 1.3432x |
| xdp_synproxy_kern.bpf.o:syncookie_xdp | xdp | 5 | 14 | 14 | 1.0000x |
| xdp_synproxy_kern.bpf.o:syncookie_tc | tc | 5 | 14 | 15 | 0.9333x |
| tcprtt.bpf.o:tcp_rcv | fentry | 4 | 2744 | 1843 | 1.4889x |
| tcpsynbl.bpf.o:tcp_v6_syn_recv | fentry | 4 | 2587 | 1781 | 1.4526x |
| tcpsynbl.bpf.o:tcp_v4_syn_recv | fentry | 4 | 2131 | 1745 | 1.2212x |
| decap_sanity.bpf.o:decap_sanity | tc | 2 | 9 | 10 | 0.9000x |

Paired directive-bearing programs by kind:

- `tc`: 16
- `tracing`: 11
- `xdp`: 1
- `syscall`: 1

This is the first time the expanded corpus produces a non-trivial set of real programs with both directive sites and paired runtime data under the existing `bpf_prog_test_run_opts` path.

## 4. Tracing attach/trigger results

The tracing step used `micro/run_corpus_tracing.sh`, which is a shell entrypoint to the existing `micro/run_corpus_tracing.py` harness. I targeted the 19 object files that already showed directive-bearing tracing programs in the perf inventory.

Summary:

| Metric | Value |
| --- | ---: |
| Programs found in targeted objects | 87 |
| Supported programs | 43 |
| Measured programs | 39 |
| Programs with positive run_cnt delta | 35 |
| Zero-run programs | 4 |
| Attach failures | 4 |
| Skipped programs | 44 |
| Directive-bearing programs | 36 |
| Directive-bearing measured programs | 17 |
| New union additions beyond test_run | 11 |

Main skip and failure reasons:

- 24 programs had dynamic attach target placeholders and were skipped.
- 4 programs failed load/attach with `bpf_object__load failed: No such process`.
- `readahead.bpf.o` emitted libbpf BTF lookup failures for symbols such as `do_page_cache_ra`, `__page_cache_alloc`, and `filemap_alloc_folio`.
- Several remaining programs were skipped because the current trigger heuristic has no automatic workload for them yet, for example:
  - `fentry/blk_account_io_start`
  - `fentry/blk_account_io_done`
  - `kprobe/vfs_create`
  - `kprobe/security_inode_create`

New real-performance coverage that did not come from `bpf_prog_test_run_opts`:

| New tracing-only addition | Root | Sites | Trigger | run_cnt delta | run_time_ns delta | avg ns/run |
| --- | --- | ---: | --- | ---: | ---: | ---: |
| biolatency.bpf.o:block_rq_complete_btf | tp_btf | 6 | disk-io | 250 | 32002 | 128.008 |
| biostacks.bpf.o:block_io_done | tp_btf | 6 | disk-io | 200 | 21750 | 108.750 |
| runqlat.bpf.o:sched_switch | tp_btf | 6 | sched | 1131 | 227635 | 201.269 |
| tcprtt.bpf.o:tcp_rcv_kprobe | kprobe | 4 | tcp-loopback | 247 | 59384 | 240.421 |
| tcpsynbl.bpf.o:tcp_v4_syn_recv_kprobe | kprobe | 4 | tcp-loopback | 50 | 9419 | 188.380 |
| bitesize.bpf.o:block_rq_issue | tp_btf | 4 | disk-io | 202 | 37119 | 183.757 |
| filetop.bpf.o:vfs_write_entry | kprobe | 2 | write-devnull | 53 | 3642 | 68.717 |
| biostacks.bpf.o:blk_account_io_merge_bio | kprobe | 1 | disk-io | 366 | 258315 | 705.779 |
| test_varlen.bpf.o:handler_exit | tp | 1 | generic-syscalls | 164 | 37644 | 229.537 |
| biotop.bpf.o:block_io_done | tp_btf | 1 | disk-io | 200 | 48733 | 243.665 |
| biopattern.bpf.o:handle__block_rq_complete | tracepoint | 1 | disk-io | 250 | 82154 | 328.616 |

Important detail:

- The tracing harness also re-measured several programs that were already runnable under `bpf_prog_test_run_opts` (`raw_tp`, `fentry`, `fexit`, `fmod_ret`).
- The 11 rows above are only the new additions to the union set.

## 5. Key metric and summary

Key paper metric:

- 80 real expanded-corpus program sections have directive sites.
- 40 unique real programs now have both directive sites and real performance data.
- That 40-program union is:
  - 29 programs measurable through `bpf_prog_test_run_opts`
  - 11 additional programs measurable only through tracing attach/trigger

Source split for the 40-program union:

| Source | Programs with directive sites and real performance data |
| --- | ---: |
| bcc | 17 |
| linux-selftests | 23 |
| Total | 40 |

Kind split for the 40-program union:

| Kind | Programs with directive sites and real performance data |
| --- | ---: |
| tracing | 22 |
| tc | 16 |
| xdp | 1 |
| syscall | 1 |
| Total | 40 |

Root split for the 40-program union:

- `tc`: 16
- `fentry`: 6
- `tp_btf`: 5
- `kprobe`: 4
- `raw_tp`: 3
- `fexit`: 1
- `fmod_ret`: 1
- `tp`: 1
- `tracepoint`: 1
- `xdp`: 1
- `syscall`: 1

Bottom line:

- The expanded corpus materially changes the external-validity story. The previous small-corpus result had effectively no useful directive-bearing runnable programs; the expanded corpus now yields 40 unique real programs with directive sites and performance data.
- The highest raw site counts are still concentrated in two Linux selftest TC programs dominated by rotate patterns.
- The tracing attach/trigger pass is what makes the CMOV-heavy BCC tracing tools measurable in practice; most of the 11 new additions are `tp_btf`, `kprobe`, or `tracepoint` programs.
- The biggest remaining corpus gap is not discovery but build output: `cilium`, `katran`, `tetragon`, `xdp-tools`, `xdp-tutorial`, and `xdp-examples` currently have build directories but 0 emitted `.bpf.o` files under `corpus/build/`.

Primary artifacts:

- `docs/tmp/real-program-directive-census.md`
- `docs/tmp/corpus-perf-results.json`
- `docs/tmp/corpus-perf-results.md`
- `docs/tmp/corpus-tracing-results.json`
- `docs/tmp/corpus-tracing-results.md`
