# Experiment Review: current-revision native performance opportunity

## Decision

The supporting experiment is positive for a steady-state direct-native
opportunity on the current 29-program x86-64 micro population. Across the
per-program medians, `native_kernel / kernel` execution time has an unweighted
geometric mean of **0.675848**, or **1.4796x** reciprocal speedup. The
population-bootstrap 95% interval for the time ratio is **[0.608055,
0.752407]**. Direct native is faster for 26 programs, tied for two, and slower
for one.

This is not a result for accepted-and-bound NativeBPF execution. The
`native_kernel` runtime is the repository's test-only trusted upper-bound path:
it loads a companion BPF program and uses the native-lab module to install and
test-run a native blob. The module does not bind stock-verifier acceptance of
the generated proof to the exact native bytes that execute. The result updates
the current performance target for that missing binding mechanism; it does not
establish claim C2.

## Runs

The public preflight command was:

```text
BENCH=simple RUNTIMES="kernel native_kernel" SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000 make micro
```

It exited zero and wrote
`micro/results/x86_kvm_micro_20260909_002321_849025/metadata.json`. All six
samples matched the expected result and return value. Its three-sample median
was 6 ns for `kernel` and 7 ns for `native_kernel`; this deliberately
contradictory preflight prevented the old aggregate preview from being assumed
for the current tree.

The full public command was:

```text
RUNTIMES="kernel native_kernel" SAMPLES=15 WARMUPS=1 INNER_REPEAT=100000 make micro
```

It exited zero, the KVM guest powered down normally, and the raw result is
`micro/results/x86_kvm_micro_20260909_005014_965526/metadata.json`. The complete
console/build log is retained at
`/workspaces/.agent-state/bpf-development/kprog-x86-performance-full-20260909.log`.

## Independent checks and analysis

`analyze.py` is an external post-hoc script in this experiment directory. It
requires completed metadata, exactly 29 unique benchmarks, the two requested
runtimes, 15 samples with indexes 0--14 for each runtime, the configured
warmup/repeat counts, `ktime` execution measurements, valid compile/code-size
fields, and the native load/upload/run phases. It exits on any result or return
value mismatch. The generated `analysis.json` preserves every execution time
and paired-by-index ratio.

The final check accepted exactly **870/870** correct measured samples. It uses
the ratio of each runtime's 15-sample median, then the unweighted geometric mean
across the 29 programs. A fixed-seed 50,000-repetition population bootstrap
resamples those 29 median ratios. Values below one mean direct native is faster.

| Program | native/kernel time | reciprocal speedup |
| --- | ---: | ---: |
| `simple` | 1.0000 | 1.0000x |
| `simple_packet` | 1.1667 | 0.8571x |
| `bitmap_popcount_scan` | 0.4194 | 2.3841x |
| `sorted_rule_binary_search` | 0.5248 | 1.9055x |
| `bcc_runqlat_log2_histogram_bucket` | 0.9182 | 1.0890x |
| `trace_event_type_switch_dispatch` | 0.9754 | 1.0253x |
| `packet_checksum_fold` | 0.7527 | 1.3285x |
| `payload_prefix_memcmp_scan` | 0.5287 | 1.8913x |
| `packet_vlan_tcpopt_parser` | 0.9167 | 1.0909x |
| `bpf_local_call_fanout_dispatch` | 0.5610 | 1.7826x |
| `flow_5tuple_rss_hash` | 0.6250 | 1.6000x |
| `katran_lb_consistent_hash_select` | 0.6364 | 1.5714x |
| `cilium_policy_guard_tree_filter` | 0.5000 | 2.0000x |
| `siphash_rotate64_mixer` | 0.5185 | 1.9286x |
| `packet_record_bounds_window` | 0.5385 | 1.8571x |
| `flow_record_field_scan` | 0.7619 | 1.3125x |
| `packed_header_bitfield_decode` | 0.8520 | 1.1737x |
| `bpftrace_string_search_prefix_scan` | 0.5968 | 1.6757x |
| `tracee_syscall_name_table_lookup` | 0.6329 | 1.5800x |
| `tracee_http_method_prefix_detect` | 0.9474 | 1.0556x |
| `cilium_socket_lb_service_select` | 0.4632 | 2.1588x |
| `bcc_tcpconnect_ipv4_tuple_filter` | 0.5905 | 1.6935x |
| `tetragon_process_event_arg_filter` | 0.6842 | 1.4615x |
| `otel_stack_frame_unwind_scan` | 0.3784 | 2.6429x |
| `cilium_ct_nat_tuple_rewrite` | 0.5137 | 1.9467x |
| `packet_toeplitz_rss_hash` | 1.0000 | 1.0000x |
| `bpftrace_comm_key_fnv_hash` | 0.9885 | 1.0117x |
| `tc_packet_checksum_fold` | 0.7491 | 1.3349x |
| `cgroup_skb_hash_chain` | 0.7113 | 1.4059x |

The direct-native native-code-size ratio is 0.537713 by the same aggregation.
Its load/compile-time ratio is 47.5423x: the median of the 29 per-program
`kernel` compile medians is 1.835 ms, versus 115.906 ms for `native_kernel`.
The execution result is therefore steady-state headroom with a substantial
current load-time cost, not a latency win for short-lived programs.

## Historical comparison and provenance

The May 29 pure-bytecode preview reported a `native_kernel / kernel` time ratio
of 0.677 (1.478x reciprocal speedup). Its direction matches this analysis and
its magnitude is close to the new 0.675848 ratio. The agreement is useful
reproduction evidence, not identity: the old run predates the current proof
generator, ABI policy, runner, kernel build, and exact accepted population.
The historical six-app x86 1.349x and ARM 1.056x values are instead
native/eBPF *workload-throughput* ratios, and the historical 1.429x value is for
the separate 13-program helper/map micro set. None is relabeled as part of this
run.

The raw full-run metadata records an Intel Core Ultra 9 285K KVM guest,
`7.0.0-rc2+`, and the requested sample parameters, but it reports repository
and kernel commits as `unknown` because the image contains no Git metadata.
The public command entered at root revision
`e0b7d35e0ecb1127105410b2b5b637f65f9d8d1f`; the only experiment-time source
additions were this post-hoc research record and analyzer, which are not copied
into the measured runner executable. The retained build log supplies the
command-to-image-to-guest chain. This reconstructs the source boundary but
does not overwrite or pretend to fill the raw metadata fields.

## Measurement limits and next claim-facing step

`BPF_PROG_TEST_RUN` reports integer per-iteration nanoseconds. This visibly
quantizes the shortest programs: the sole regression, `simple_packet`, is a
6--7 ns comparison, and both ties include similarly coarse values. The
program-population bootstrap describes variation across these 29 program
ratios; it does not remove timer quantization or substitute for a second
machine.

The experiment establishes a current, reproducible x86 direct-native
performance opportunity and falsifies neither the opportunity nor the
functional proof-smoke result. It does not test ARM hardware, production
application throughput, general simulator fidelity, specialization
preservation, or verifier-to-native artifact binding. The decisive C2 result
still requires the same accepted proof and exact native payload to be bound by
the runtime and then measured through that bound path.
