# Full pure micro suite: 29 native-only programs verified and correct

Actual standard VM/container run `x86_kvm_micro_20261107_191655_808444`, original 29 native ELFs and original inputs. Applications submit only P; the external registered service freshly generates and compiles each proof from the kernel-owned P, and the kernel verifies/binds the native program. This includes Trace, SipHash and Socket LB, which failed in earlier runs. No program is omitted.

| Programs | Generated | Compiled | Verifier accepted/bound | Specialization failed | Verifier rejected | Correct JIT/native samples |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 29 | 29 | 29 | 29 | 0 | 0 | 58 |

Every sample matches the full expected 64-bit result and return action. All 29 terminal request records have complete readable archives, matching kernel-owned native SHA and bound-program receipt; all 29 native program IDs are distinct. Driver and collector exit zero. All launch source/binary pins stay unchanged, including the generated narrow-load header, generator, worker, simulator, native linker, loader, kernel and module. Closed own guest disk/exported image tar are deleted.

The current source combines exact CMP flag expression b46de606c, shared RORX dispatch 2b1ab2c29, explicit narrow-load zero extension c0b8e9cfa, and terminal draining 63a9fea5b. The launch worktree has the byte-exact c0b8 source before its later commit; the recorded launch HEAD is retained without relabeling it. No native inputs, compiler flags, verifier limits, synthetic guards or workloads changed. Existing image, kernel and 15 modules are reused. Source snapshots in `runtime-raw.tar.gz` preserve the actually measured external-service inputs.

These are one-sample functional results, not a timing comparison or a complete simulator-wide ISA/artifact proof. TC checksum and cgroup_skb cases also pass their exact tested result/return action; no blanket skb ABI fidelity claim. The six real corpus applications remain a separate required coverage target; OTel's subsequent narrow-load application run and the other application queue are pending.

## Command and raw records

Host CPUs20-23, four vCPUs, 8 GiB, one sample, zero warmups, one repeat; exact VM/overlay launcher is `driver/run.sh` in the raw archive:

```sh
PATH=/usr/lib/llvm-18/bin:$PATH make __runtime-vm-micro PLATFORM=kvm ARCH=x86 \
  HOST_KINSN_DIR_X86=/workspaces/repository/kprog/tv/build-x86/corpus-modules \
  RUNTIME_CONTAINER_IMAGE=bpf-benchmark/kprog-micro-trusted:c-20261107 \
  RUNTIME_IMAGE_TAR=/workspaces/.agent-state/kprog-lanes/C/micro-load-width/runtime.image.tar \
  RUN_TOKEN=c-load-width-pure-20261107 RUNTIMES="kernel native_proof" \
  SUITE=micro/config/micro_pure_jit.yaml SAMPLES=1 WARMUPS=0 INNER_REPEAT=1
```

`runtime.json` contains all raw samples, all requests and exact launch pins. `runtime-service.tar.gz` wraps the original complete service archive with all generated sources/objects, native inputs and load logs. `runtime-raw.tar.gz` includes the original result tree, actual source snapshots, runner/image inputs, launch/collector, full guest kernel log and meminfo. `runtime-driver.log.gz` preserves driver output. `checks.json` records each original/bound program identity and exact-result audit. Earlier 26/29 and 27/29 failures remain unchanged in their original dated directories.

## Per-program table

| Program | Generated | Compiled | Accepted/bound | JIT + native correct |
| --- | ---: | ---: | ---: | ---: |
| simple | 1 | 1 | 1 | 2 |
| simple_packet | 1 | 1 | 1 | 2 |
| bitmap_popcount_scan | 1 | 1 | 1 | 2 |
| sorted_rule_binary_search | 1 | 1 | 1 | 2 |
| bcc_runqlat_log2_histogram_bucket | 1 | 1 | 1 | 2 |
| trace_event_type_switch_dispatch | 1 | 1 | 1 | 2 |
| packet_checksum_fold | 1 | 1 | 1 | 2 |
| payload_prefix_memcmp_scan | 1 | 1 | 1 | 2 |
| packet_vlan_tcpopt_parser | 1 | 1 | 1 | 2 |
| bpf_local_call_fanout_dispatch | 1 | 1 | 1 | 2 |
| flow_5tuple_rss_hash | 1 | 1 | 1 | 2 |
| katran_lb_consistent_hash_select | 1 | 1 | 1 | 2 |
| cilium_policy_guard_tree_filter | 1 | 1 | 1 | 2 |
| siphash_rotate64_mixer | 1 | 1 | 1 | 2 |
| packet_record_bounds_window | 1 | 1 | 1 | 2 |
| flow_record_field_scan | 1 | 1 | 1 | 2 |
| packed_header_bitfield_decode | 1 | 1 | 1 | 2 |
| bpftrace_string_search_prefix_scan | 1 | 1 | 1 | 2 |
| tracee_syscall_name_table_lookup | 1 | 1 | 1 | 2 |
| tracee_http_method_prefix_detect | 1 | 1 | 1 | 2 |
| cilium_socket_lb_service_select | 1 | 1 | 1 | 2 |
| bcc_tcpconnect_ipv4_tuple_filter | 1 | 1 | 1 | 2 |
| tetragon_process_event_arg_filter | 1 | 1 | 1 | 2 |
| otel_stack_frame_unwind_scan | 1 | 1 | 1 | 2 |
| cilium_ct_nat_tuple_rewrite | 1 | 1 | 1 | 2 |
| packet_toeplitz_rss_hash | 1 | 1 | 1 | 2 |
| bpftrace_comm_key_fnv_hash | 1 | 1 | 1 | 2 |
| tc_packet_checksum_fold | 1 | 1 | 1 | 2 |
| cgroup_skb_hash_chain | 1 | 1 | 1 | 2 |
