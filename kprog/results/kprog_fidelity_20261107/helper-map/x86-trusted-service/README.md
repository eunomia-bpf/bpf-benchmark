# Stage2 correctness on the native-only trusted service

All13 configured workloads in `micro/config/micro_stage2.yaml` pass the real
x86KVM native-only COMMONservice path. Both the original kernel BPF execution
and the newly generated, bound native execution match each exact64-bit expected
result and retval2. Every native load has a nonzero-generation sidecar.

| Workload | Expected/kernel/native result | Retval | Nonzero generations |
| --- | ---: | ---: | ---: |
| helper_only_uid_gid | 0 | 2 | 1 |
| helper_chain_simple | 0 | 2 | 2 |
| map_array_lookup | 16045690984503050241 | 2 | 2 |
| map_array_index_packet | 16045690984503098046 | 2 | 2 |
| map_hash_lookup | 1234605616436508552 | 2 | 2 |
| map_hash_str_key | 18369614221520256751 | 2 | 2 |
| map_percpu_array | 18369614221190019774 | 2 | 2 |
| map_lru_hash_counter | 1 | 2 | 2 |
| map_percpu_hash_counter | 1 | 2 | 2 |
| combined_helper_map | 0 | 2 | 2 |
| multi_map_policy | 1311768465173141112 | 2 | 3 |
| packet_5tuple_classify | 3405691582 | 2 | 2 |
| stats_mixed_helpers | 1 | 2 | 3 |

`results.csv` records per-case IDs, values, generations and native hashes.
`outcomes.json.gz` preserves all commands, stdout/stderr and service receipts;
all13 success archives under `requests/` retain the kernel-owned native input,
worker source identities and freshly generated proof/native artifacts.
`inputs.json` records both original BPF and native ELF SHA256 values. These
unchanged objects come from the existing kprog/test build; workloads and map
contents were not rewritten to obtain the result. The producer manifest has
only native object/entry, never simulator_object or simulator_program. The
probe refuses prebuilt proofs; only the registered service generates proof.
Original BPF bytes are used locally for manifest/map selection, not supplied
as a proof. Kernel/module/loader/simulator hashes before and after are equal.

Commands from the repository root:

```sh
make -f kprog/results/kprog_fidelity_20261107/helper-map/x86-trusted-service/Makefile build
make -f kprog/results/kprog_fidelity_20261107/helper-map/x86-trusted-service/Makefile kvm
```

The existing static application probe, canonical TV kernel/module, native-link
and trusted loader were reused, with2 guest CPUs/2GiB on host16-19. No image,
kernel, loader or workload rebuild is part of this replay. This is functional
correctness evidence, not timing; R's existing stage2 timing request stays in
COORDINATION.md. Earlier13-case bound/prebuilt results remain separate.
The report does not assert a full O1/O2/O4 proof or six-application completion.
