# Pure micro suite: canonical CMP repair, 12 GiB

Actual standard VM/container run `x86_kvm_micro_20261107_183244_961554` submits only the original native ELF P. The external registered service generates a fresh proof from the kernel-owned P, then the kernel verifies and binds it. No application proof, prebuilt proof lookup, changed native input, flags, workload, verifier limits or synthetic checks.

| Total programs | Generated | Compiled | Verifier accepted/bound | Specialization failed | Verifier rejected |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 29 | 29 | 28 | 27 | 1: Clang killed by guest OOM | 1: scalar access in division-fault path |

All 29 JIT samples and all 27 native samples match both the expected 64-bit result and return action (56 correct samples). All 29 service requests have complete terminal records and readable per-request archives. The driver exits 2 for the two recorded failures; the collector exits 1 because its all-29-pass assertion is not met, after writing the complete results. These failures remain open; this is not an all-pass or six-application result.

Compared with the earlier 8 GiB/26-pass run in `../micro-shared-elf`, this uses canonical CMP header `4fe6817022a81eaf529235979a9d0f0c237e972ae16ede5f5164b524ba5ac307` (b46de606c), terminal draining (63a9fea5b), and 12 GiB. The Trace switch now generates, binds, and returns result 16/action 2. SipHash still fails: the kernel explicitly reports `Out of memory: Killed process 1822 (clang)`, anon RSS 10,299,508 KiB. Socket LB compiles but rejects at instruction 116 (`R0 invalid mem access 'scalar'`), reached from the modeled native division-fault path because the verifier loses the divisor's nonzero identity. No fault guard has been removed.

## Command and inputs

C host CPUs 20-23, four vCPUs, 12 GiB, one sample, zero warmups, one repeat. Existing incremental kernel, 15 matching modules and cached image `bpf-benchmark/kprog-micro-trusted:c-20261107` are reused. Exact VM/overlay launch is `driver/run.sh` inside `runtime-raw.tar.gz`; guest command:

```sh
PATH=/usr/lib/llvm-18/bin:$PATH make __runtime-vm-micro PLATFORM=kvm ARCH=x86 \
  HOST_KINSN_DIR_X86=/workspaces/repository/kprog/tv/build-x86/corpus-modules \
  RUNTIME_CONTAINER_IMAGE=bpf-benchmark/kprog-micro-trusted:c-20261107 \
  RUNTIME_IMAGE_TAR=/workspaces/.agent-state/kprog-lanes/C/micro-cmp-12g/runtime.image.tar \
  RUN_TOKEN=c-cmp-pure12g-20261107 RUNTIMES="kernel native_proof" \
  SUITE=micro/config/micro_pure_jit.yaml SAMPLES=1 WARMUPS=0 INNER_REPEAT=1
```

`runtime.json` records all samples, per-request identities, failure tracebacks, exact image and source/binary pins. No launch pin drift. The root Makefile's normal-compiler-PATH fix was committed while this guest ran, but this run supplied its own LLVM PATH and does not validate that fix; the separately queued normal-PATH VM control does. `runtime-raw.tar.gz` contains original results, runner binary/image inputs, collector/launch, full guest kernel log and meminfo. `runtime-service.tar.gz` contains the original complete registered-service archive, including all generated sources/objects/load logs. `runtime-driver.log.gz` preserves the driver output. Closed guest disk and exported image tar are deleted, no active inputs/caches removed.

## Per-program coverage

| Program | Generated | Compiled | Accepted/bound + correct | Failure |
| --- | ---: | ---: | ---: | --- |
| simple | 1 | 1 | 1 |  |
| simple_packet | 1 | 1 | 1 |  |
| bitmap_popcount_scan | 1 | 1 | 1 |  |
| sorted_rule_binary_search | 1 | 1 | 1 |  |
| bcc_runqlat_log2_histogram_bucket | 1 | 1 | 1 |  |
| trace_event_type_switch_dispatch | 1 | 1 | 1 |  |
| packet_checksum_fold | 1 | 1 | 1 |  |
| payload_prefix_memcmp_scan | 1 | 1 | 1 |  |
| packet_vlan_tcpopt_parser | 1 | 1 | 1 |  |
| bpf_local_call_fanout_dispatch | 1 | 1 | 1 |  |
| flow_5tuple_rss_hash | 1 | 1 | 1 |  |
| katran_lb_consistent_hash_select | 1 | 1 | 1 |  |
| cilium_policy_guard_tree_filter | 1 | 1 | 1 |  |
| siphash_rotate64_mixer | 1 | 0 | 0 | Clang OOM (kernel log) |
| packet_record_bounds_window | 1 | 1 | 1 |  |
| flow_record_field_scan | 1 | 1 | 1 |  |
| packed_header_bitfield_decode | 1 | 1 | 1 |  |
| bpftrace_string_search_prefix_scan | 1 | 1 | 1 |  |
| tracee_syscall_name_table_lookup | 1 | 1 | 1 |  |
| tracee_http_method_prefix_detect | 1 | 1 | 1 |  |
| cilium_socket_lb_service_select | 1 | 1 | 0 | verifier: R0 invalid mem access scalar (division fault branch) |
| bcc_tcpconnect_ipv4_tuple_filter | 1 | 1 | 1 |  |
| tetragon_process_event_arg_filter | 1 | 1 | 1 |  |
| otel_stack_frame_unwind_scan | 1 | 1 | 1 |  |
| cilium_ct_nat_tuple_rewrite | 1 | 1 | 1 |  |
| packet_toeplitz_rss_hash | 1 | 1 | 1 |  |
| bpftrace_comm_key_fnv_hash | 1 | 1 | 1 |  |
| tc_packet_checksum_fold | 1 | 1 | 1 |  |
| cgroup_skb_hash_chain | 1 | 1 | 1 |  |
