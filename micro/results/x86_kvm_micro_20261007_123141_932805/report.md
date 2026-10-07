# Fixed kinsn lab: requested comparison, optimizer failed

The requested `make micro RUNTIMES="kernel kernel_rejit" BPFREJIT_BENCH_PASSES=kinsn SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000` finished with make exit 0 at checkout `022c1ef7b19a487b965475451134ab5d067e6780`, using the fixed-module image built from `f49c60b84`. All 29 benchmarks and 174 measured samples matched expected result/retval. However, all 519 recorded per-program pass attempts returned failed_bpfopt/exit 1. No kinsn sites were applied. The runtime name kernel_rejit in the raw data therefore measures unchanged programs after failed optimization attempts, not the effect of the fixed modules. The complete raw result is retained.

Error: `bpfopt: Unknown command line argument '-bpf-enable-kinsn-select'; suggested '--bpf-enable-kop-select'. Unknown '-bpf-kinsn-mode=all=force,movbe-load=disable'; suggested '--bpf-kop-mode=all=force,movbe-load=disable'.`

The reused native LLVM archive is dated 2026-09-16 and registers the old kop option names. The pinned LLVM source commit `7f56eafab493abea1ddbbffa785fb9231964454e` is dated 2026-10-06 and renames these options to kinsn. The source revision alone did not establish that this prebuilt archive had been rebuilt. LLVM was never rebuilt, per the task constraint, and the original checkout was not modified. A local search found only the supplied stale native archive, stock LLVM 22.1.8 (no selector), and a matching ARM64 archive (wrong host architecture). A matching prebuilt native LLVM directory is required before repeating the intended optimizing comparison.

No candidate kinsn program reached BPF_PROG_LOAD, so there are no kinsn verifier rejection logs from this attempt. The module installer loaded the fixed x86 modules successfully. Program failures are preserved for every captured program; no program exclusion was added. The existing micro lifecycle holds the runner, executes the shim plan, and sends SIGUSR1 to run it; no lifecycle or workload was changed.

The VM was 8 vCPUs/64G RAM, without explicit CPU pinning. Host governors remained performance and no_turbo=1; guest cpufreq/turbo fields were unknown. Lowest sampled free workspace space: 17.252 GiB.

Per-benchmark medians and installed-site counts are below. Zero sites is established by explicit failed_bpfopt status before candidate loading; optimizer summaries are null. Ratios are raw timing comparisons of the named runtimes.

| Benchmark | kernel median ns | kernel_rejit median ns | kernel/kernel_rejit | applied sites per measured sample |
| --- | ---: | ---: | ---: | --- |
| simple | 6 | 6 | 1.000000x | [0, 0, 0] |
| simple_packet | 6 | 6 | 1.000000x | [0, 0, 0] |
| bitmap_popcount_scan | 1115 | 1115 | 1.000000x | [0, 0, 0] |
| sorted_rule_binary_search | 526 | 528 | 0.996212x | [0, 0, 0] |
| bcc_runqlat_log2_histogram_bucket | 1173 | 1198 | 0.979132x | [0, 0, 0] |
| trace_event_type_switch_dispatch | 287 | 393 | 0.730280x | [0, 0, 0] |
| packet_checksum_fold | 17650 | 17652 | 0.999887x | [0, 0, 0] |
| payload_prefix_memcmp_scan | 91 | 88 | 1.034091x | [0, 0, 0] |
| packet_vlan_tcpopt_parser | 13 | 12 | 1.083333x | [0, 0, 0] |
| bpf_local_call_fanout_dispatch | 126 | 136 | 0.926471x | [0, 0, 0] |
| flow_5tuple_rss_hash | 20 | 20 | 1.000000x | [0, 0, 0] |
| katran_lb_consistent_hash_select | 25 | 24 | 1.041667x | [0, 0, 0] |
| cilium_policy_guard_tree_filter | 96 | 94 | 1.021277x | [0, 0, 0] |
| siphash_rotate64_mixer | 56 | 68 | 0.823529x | [0, 0, 0] |
| packet_record_bounds_window | 143 | 146 | 0.979452x | [0, 0, 0] |
| flow_record_field_scan | 80 | 77 | 1.038961x | [0, 0, 0] |
| packed_header_bitfield_decode | 279 | 277 | 1.007220x | [0, 0, 0] |
| bpftrace_string_search_prefix_scan | 243 | 244 | 0.995902x | [0, 0, 0] |
| tracee_syscall_name_table_lookup | 161 | 163 | 0.987730x | [0, 0, 0] |
| tracee_http_method_prefix_detect | 24 | 18 | 1.333333x | [0, 0, 0] |
| cilium_socket_lb_service_select | 373 | 437 | 0.853547x | [0, 0, 0] |
| bcc_tcpconnect_ipv4_tuple_filter | 107 | 107 | 1.000000x | [0, 0, 0] |
| tetragon_process_event_arg_filter | 201 | 212 | 0.948113x | [0, 0, 0] |
| otel_stack_frame_unwind_scan | 155 | 154 | 1.006494x | [0, 0, 0] |
| cilium_ct_nat_tuple_rewrite | 186 | 187 | 0.994652x | [0, 0, 0] |
| packet_toeplitz_rss_hash | 260 | 262 | 0.992366x | [0, 0, 0] |
| bpftrace_comm_key_fnv_hash | 438 | 436 | 1.004587x | [0, 0, 0] |
| tc_packet_checksum_fold | 17652 | 17655 | 0.999830x | [0, 0, 0] |
| cgroup_skb_hash_chain | 286 | 286 | 1.000000x | [0, 0, 0] |

The geomean over benchmarks with applied kinsn sites is undefined (zero such benchmarks). For transparency, the observed ratio geomean is 0.987924819x over all 29 and 0.987036184x over the 27 non-baseline cases; neither is a kinsn speedup. The historic paper 1.242x and September 1.214x use the 27 non-baseline set and successful optimization. Their compiler/protocol/host differences are discussed in the full requested report.

Exact command:

```bash
make micro 'RUNTIMES=kernel kernel_rejit' BPFREJIT_BENCH_PASSES=kinsn SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000 PLATFORM=kvm ARCH=x86 JOBS=8 IMAGE_BUILD_JOBS=8 HOST_KERNEL_BUILD_DIR_X86=/var/tmp/kinsn-runtime-test-20261007/linux X86_RUNTIME_KERNEL_IMAGE=/var/tmp/kinsn-runtime-test-20261007/linux/arch/x86/boot/bzImage NATIVE_KINSN_LLVM_BUILD_DIR=/workspaces/repository/llvm-backend/build-bpf-kinsn NATIVE_KINSN_LLVM_DIR=/workspaces/repository/llvm-backend/build-bpf-kinsn/lib/cmake/llvm NATIVE_KINSN_LLVM_TBLGEN=/workspaces/repository/llvm-backend/build-bpf-kinsn/bin/llvm-tblgen --old-file=/workspaces/repository/llvm-backend/build-bpf-kinsn/bin/llvm-tblgen --old-file=/workspaces/repository/llvm-backend/build-bpf-kinsn/lib/libLLVMBPFCodeGen.a --old-file=host-source-apps-x86 --old-file=host-native-bpf-x86 --old-file=x86-runner-runtime-image-tar RUN_TOKEN=kinsn-runtime-20261007-micro-kinsn
```
