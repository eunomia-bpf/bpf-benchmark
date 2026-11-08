# Design-only trusted native path, 2026-11-08

The five steps are (a) submit P as native bytes, relocations and metadata; (b) retain one kernel copy; (c) the registered service generates and compiles B from that copy; (d) the stock verifier analyzes B; (e) the JIT emits the copy through ordinary link resolution.

Safety has two facts: the stock verifier accepts B, and B faithfully simulates P through universal O1/O2 and O4 link preservation. Steps b?e use one kernel copy, so the installed program is the program B simulates.

## Shared implementation

The registered service creates immutable request-owned chunks through `TRUSTED_CHUNK`. Each handle names one allocation throughout its lifetime. The request retains its ELF/metadata and resources; installed programs retain their request and linked chunks. Copy/allocation failures, service registration capability, request/reply matching, ordinary map/helper/kfunc/relocation resolution, stock verification and JIT emission remain.

Remove decisions cover public blob/relocs/proof/binding/generation writers; binding envelopes and generation vectors; B/P, group, program and context comparisons; worker TGID and boot-lifetime registration pinning; transport versions/flags/reserved refusals and map-count policy caps; exact-key schemas and compiler identity guards; specialization ABI admission refusals; readonly/exclusive matching metadata and their audit fixtures. ABI unspecified entry state and helper caller-clobbers are represented in B as unconstrained architectural values. Stack extent and finite return-site collection continue to supply the representation.

## Refusal inventory

The baseline snapshots and SHA256 ledger identify each source epoch. The appendix assigns each explicit refusal expression a decision and the design step served by each keep. Rewritten functions relocate copy/allocation and lifecycle handling into immutable storage. The native branch of the kernel sequence expander passes B to stock verification; ordinary helper/kfunc resolution supplies the required link information.

The inventory contains 826 sites: 563 keep and 263 remove decisions. C owns the shared and x86 implementation, A owns the arm64 module port, and V owns theorem-row cleanup.

## Validation

| Application | Native requests | Generated | Compiled | Verifier accepted and installed | Workload |
| --- | ---: | ---: | ---: | ---: | --- |
| BCC | 25 | 25 | 25 | 25 | both arms complete |
| Katran | 1 | 1 | 1 | 1 | both arms complete |

Actual corpus result: `corpus/results/x86_kvm_corpus_20261108_053635_529825`, metadata completed, both application statuses ok. BCC syscall work is 514 operations in each arm; the duration-driven cap/set/sockfd work and per-program counters are retained. Katran records JIT2375305 packets and native2453813 packets, with one TX action per packet and LRU miss0 in both arms. Native receiver records2453813 packets. The two-second protocol supplies functional evidence; raw durations and contention remain in the logs.

The existing38 native-only safety cases execute9 valid controls and record27 stock-verifier refusals plus2 generation failures (missing instruction handler and unbounded indirect jump), with0 accepted dangerous cases. ABI entry-register/flags and helper-clobber cases reach the verifier. The final-source replay includes the collector cleanup and common caller-clobber model for BPF helpers and external memcpy/memset calls. Kernel patch application/idempotence/conflict checks and eight retained service checks pass.

The app runtime receipt uses eight vCPUs,8GiB and host CPUs20?23. The initial controller launch file retains its earlier four-vCPU queue epoch; the successful retry wrapper and guest logs record the actual eight-vCPU invocation. The whole-app epoch precedes the final retirement of inert ABI-analysis calls and remaining metadata-key/version refusals. Final compiler and safety receipts identify the resulting source epoch.

## Commands and artifacts

Project commands use the Workspace wrapper. Cached kernel/module and loader commands run from `/workspaces/.agent-state/kprog-lanes/C/design-only`:

```sh
unshare --mount --propagation private sh /workspaces/.agent-state/kprog-lanes/C/design-only/inside-build.sh
make -C kprog/libnativeloader trusted-service BUILD_DIR=/workspaces/.agent-state/kprog-lanes/C/design-only/loader
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/apps/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/apps CPUS=20-23 VM_CPUS=8 VM_MEM=8G APPS=bcc/set,katran SAMPLES=1 WORKLOAD_DURATION=2
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/Makefile safety-complete
```

`observations.json` retains request entries, source/native/binary hashes, per-app counters and source epochs. `application-service.tar.gz` retains every actual P/B request and its generation/compile/load logs. `application-results.tar.gz` holds the original corpus output. `safety-results.tar.gz` retains all safety trials. `implementation-epochs.tar.gz` holds baseline snapshots, the refusal ledger, commands and build logs; `kernel-loader-artifacts.tar.gz` holds the kernel, loader and module binaries. The initial setup trial preserves its client-linker resource-mode and four-vCPU NAPI diagnostics.

The coordinator has a design-scope review case for direct global-kinsn ingress alongside native_submit. The operator decides its scope; extra runtime admission checks await approval. A owns the arm64 module port after this shared publication; V owns the retired O4 rows and updated ABI relations.

## Baseline refusal appendix

| Baseline source line | Function | Decision | Design step | Purpose |
| --- | --- | --- | --- | --- |
| `bpfopt/shim/shim_native_loader.h:91` | `shim_native_loader_fatal_reason` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:97` | `shim_native_loader_fatal` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:98` | `shim_native_loader_fatal` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:111` | `shim_native_loader_check_bound_abi` | remove | outside a?e | policy or comparison removed |
| `bpfopt/shim/shim_native_loader.h:124` | `shim_native_loader_resolve_load_fn` | remove | outside a?e | policy or comparison removed |
| `bpfopt/shim/shim_native_loader.h:136` | `shim_native_loader_resolve_load_fn` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:149` | `shim_native_loader_resolve_load_fn` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:158` | `shim_native_loader_resolve_load_fn` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:444` | `shim_maybe_replace_with_native_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:461` | `shim_maybe_replace_with_native_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:468` | `shim_maybe_replace_with_native_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:476` | `shim_maybe_replace_with_native_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:524` | `shim_maybe_replace_with_native_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:555` | `shim_maybe_replace_with_native_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:569` | `shim_maybe_replace_with_native_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:616` | `shim_maybe_replace_with_native_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `bpfopt/shim/shim_native_loader.h:630` | `shim_maybe_replace_with_native_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_binding.h:33` | `native_lab_reloc_patch_size` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_binding.h:83` | `native_lab_binding_validate` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_binding.h:94` | `native_lab_binding_validate` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_binding.h:97` | `native_lab_binding_validate` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_binding.h:100` | `native_lab_binding_validate` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_binding.h:118` | `native_lab_binding_use` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_binding.h:120` | `native_lab_binding_use` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_binding.h:136` | `native_lab_binding_snapshot` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_binding.h:138` | `native_lab_binding_snapshot` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_binding.h:141` | `native_lab_binding_snapshot` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_binding.h:144` | `native_lab_binding_snapshot` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_checked.h:58` | `native_lab_capture_proof` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_checked.h:77` | `native_lab_capture_proof` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_checked.h:91` | `native_lab_capture_proof` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_checked.h:111` | `native_lab_checked_open` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_checked.h:114` | `native_lab_checked_open` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_checked.h:117` | `native_lab_checked_open` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_checked.h:121` | `native_lab_checked_open` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_checked.h:161` | `native_lab_capture_emit` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_checked.h:179` | `native_lab_emitted_open` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_checked.h:182` | `native_lab_emitted_open` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_checked.h:186` | `native_lab_emitted_open` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_checked.h:196` | `native_lab_emitted_open` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_checked.h:203` | `native_lab_emitted_open` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:57` | `native_lab_context_matches` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:63` | `native_lab_context_matches` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:70` | `native_lab_context_matches` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:118` | `native_lab_pin_maps` | keep | b | copy, allocation and lifetime |
| `kinsn/module/include/native_lab_group.h:133` | `native_lab_pin_maps` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_group.h:141` | `native_lab_pin_maps` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_group.h:176` | `native_lab_readonly_data` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:179` | `native_lab_readonly_data` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:196` | `native_lab_readonly_data` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:199` | `native_lab_readonly_data` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:204` | `native_lab_readonly_data` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:222` | `native_lab_group_metadata` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:240` | `native_lab_group_prepare` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:259` | `native_lab_group_prepare` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:289` | `native_lab_exclusive_environment` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:310` | `native_lab_exclusive_environment` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:329` | `native_lab_group_use` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:334` | `native_lab_group_use` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:336` | `native_lab_group_use` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:349` | `native_lab_group_use` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:372` | `native_lab_group_program` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:384` | `native_lab_group_program` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:390` | `native_lab_group_program` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:430` | `native_lab_map_target` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_group.h:435` | `native_lab_map_target` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_group.h:441` | `native_lab_map_target` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_group.h:451` | `native_lab_emit_literal` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_group.h:453` | `native_lab_emit_literal` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_group.h:485` | `native_lab_map_operation_target` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:497` | `native_lab_map_operation_target` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_group.h:638` | `native_lab_validate_proof` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_input.h:58` | `bpf_native_input_candidate` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_trusted.h:112` | `native_lab_trusted_seal` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:118` | `native_lab_trusted_seal` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:135` | `native_lab_trusted_bind_program` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_trusted.h:139` | `native_lab_trusted_bind_program` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_trusted.h:164` | `native_lab_snapshot_resources` | keep | b | copy, allocation and lifetime |
| `kinsn/module/include/native_lab_trusted.h:176` | `native_lab_snapshot_resources` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_trusted.h:202` | `native_lab_trusted_submit` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:204` | `native_lab_trusted_submit` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:206` | `native_lab_trusted_submit` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:209` | `native_lab_trusted_submit` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:216` | `native_lab_trusted_submit` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:219` | `native_lab_trusted_submit` | keep | b, c | request matching and queue lifecycle |
| `kinsn/module/include/native_lab_trusted.h:239` | `native_lab_trusted_submit` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:249` | `native_lab_trusted_submit` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:268` | `native_lab_trusted_submit` | keep | b | copy, allocation and lifetime |
| `kinsn/module/include/native_lab_trusted.h:278` | `native_lab_trusted_submit` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_trusted.h:280` | `native_lab_trusted_submit` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_trusted.h:282` | `native_lab_trusted_submit` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_trusted.h:287` | `native_lab_trusted_submit` | keep | b, c | request matching and queue lifecycle |
| `kinsn/module/include/native_lab_trusted.h:314` | `native_lab_trusted_next` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:316` | `native_lab_trusted_next` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:327` | `native_lab_trusted_next` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_trusted.h:331` | `native_lab_trusted_next` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_trusted.h:347` | `native_lab_trusted_next` | keep | b, c | request matching and queue lifecycle |
| `kinsn/module/include/native_lab_trusted.h:352` | `native_lab_trusted_next` | keep | b | copy, allocation and lifetime |
| `kinsn/module/include/native_lab_trusted.h:359` | `native_lab_trusted_next` | keep | b | copy, allocation and lifetime |
| `kinsn/module/include/native_lab_trusted.h:377` | `native_lab_trusted_activate` | keep | b, c | request matching and queue lifecycle |
| `kinsn/module/include/native_lab_trusted.h:381` | `native_lab_trusted_activate` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:383` | `native_lab_trusted_activate` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:397` | `native_lab_trusted_complete` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:400` | `native_lab_trusted_complete` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:404` | `native_lab_trusted_complete` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:416` | `native_lab_trusted_complete` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:458` | `native_lab_trusted_context` | keep | b, c | request matching and queue lifecycle |
| `kinsn/module/include/native_lab_trusted.h:478` | `native_lab_trusted_context` | keep | b | copy, allocation and lifetime |
| `kinsn/module/include/native_lab_trusted.h:490` | `native_lab_trusted_map` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:492` | `native_lab_trusted_map` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/include/native_lab_trusted.h:510` | `native_lab_trusted_map` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_trusted.h:516` | `native_lab_trusted_map` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_trusted.h:530` | `native_lab_trusted_map` | keep | b | copy, allocation and lifetime |
| `kinsn/module/include/native_lab_trusted.h:541` | `native_lab_trusted_ioctl` | keep | c | registered service capability |
| `kinsn/module/include/native_lab_trusted.h:549` | `native_lab_trusted_ioctl` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_trusted.h:566` | `native_lab_trusted_ioctl` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/include/native_lab_trusted.h:573` | `native_lab_trusted_ioctl` | keep | b, c | request matching and queue lifecycle |
| `kinsn/module/include/native_lab_trusted.h:578` | `native_lab_trusted_ioctl` | keep | b | copy, allocation and lifetime |
| `kinsn/module/include/native_lab_trusted.h:586` | `native_lab_trusted_open` | keep | b | copy, allocation and lifetime |
| `kinsn/module/include/native_lab_trusted.h:589` | `native_lab_trusted_open` | keep | b | copy, allocation and lifetime |
| `kinsn/module/include/native_lab_trusted.h:594` | `native_lab_trusted_open` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:144` | `decode_native_lab_payload` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:146` | `decode_native_lab_payload` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:148` | `decode_native_lab_payload` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:152` | `decode_native_lab_payload` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:166` | `native_lab_advance_generation` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:210` | `instantiate_native_lab` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:214` | `instantiate_native_lab` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:224` | `instantiate_native_lab` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:278` | `emit_native_lab_x86` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:301` | `emit_native_lab_x86` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:338` | `emit_native_lab_x86` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:349` | `emit_native_lab_x86` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:360` | `emit_native_lab_x86` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:375` | `emit_native_lab_x86` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:389` | `emit_native_lab_x86` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:419` | `emit_native_lab_x86` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:465` | `blob_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:468` | `blob_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:471` | `blob_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:476` | `blob_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:479` | `blob_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:519` | `relocs_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:521` | `relocs_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:523` | `relocs_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:526` | `relocs_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:531` | `relocs_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:534` | `relocs_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:563` | `proof_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:565` | `proof_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:567` | `proof_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:570` | `proof_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:608` | `binding_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:610` | `binding_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:614` | `binding_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:628` | `binding_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:715` | `blob_read` | keep | b | copy, allocation and lifetime |
| `kinsn/module/x86/bpf_x86_native_lab.c:727` | `blob_open` | keep | b | copy, allocation and lifetime |
| `kinsn/module/x86/bpf_x86_native_lab.c:786` | `map_ptr_open` | keep | b | copy, allocation and lifetime |
| `kinsn/module/x86/bpf_x86_native_lab.c:809` | `map_ptr_query_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:811` | `map_ptr_query_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:813` | `map_ptr_query_write` | remove | outside a?e | policy or comparison removed |
| `kinsn/module/x86/bpf_x86_native_lab.c:815` | `map_ptr_query_write` | keep | b | copy, allocation and lifetime |
| `kinsn/module/x86/bpf_x86_native_lab.c:831` | `map_ptr_query_write` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kinsn/module/x86/bpf_x86_native_lab.c:840` | `map_ptr_query_write` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_environment_binding.hpp:17` | `parse_native_environment_layout` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_environment_binding.hpp:33` | `parse_native_environment_layout` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_environment_binding.hpp:39` | `parse_native_environment_layout` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_environment_binding.hpp:62` | `bind_exclusive_environment` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_environment_binding.hpp:67` | `bind_exclusive_environment` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_environment_binding.hpp:69` | `bind_exclusive_environment` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:198` | `load_prog_info` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:220` | `load_xlated_program` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:233` | `load_xlated_program` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:244` | `read_binary_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:249` | `read_binary_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:256` | `read_binary_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:266` | `read_bpf_insn_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:269` | `read_bpf_insn_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:281` | `write_binary_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:288` | `write_binary_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:359` | `NativeLabUploadLock` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:368` | `NativeLabUploadLock` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:610` | `lookup_native_lab_ptr_by_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:617` | `lookup_native_lab_ptr_by_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:628` | `lookup_native_lab_ptr_by_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:634` | `lookup_native_lab_ptr_by_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:642` | `lookup_native_lab_ptr_by_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:650` | `lookup_native_lab_ptr_by_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:766` | `native_lab_reloc_slot_bytes` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:894` | `parse_native_lab_relocs` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:904` | `parse_native_lab_relocs` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:908` | `parse_native_lab_relocs` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:923` | `plan_blob_chunks` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:939` | `plan_blob_chunks` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:946` | `plan_blob_chunks` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:958` | `upload_reloc_chunk` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:964` | `upload_reloc_chunk` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:991` | `upload_relocs` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1009` | `upload_relocs` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1024` | `upload_blob` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1030` | `upload_blob` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1036` | `upload_blob` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1042` | `upload_blob` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1050` | `bound_proof_sequence` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1053` | `bound_proof_sequence` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1065` | `bound_proof_sequence` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1073` | `bound_proof_sequence` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1097` | `bound_proof_sequence` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1108` | `upload_proof_chunk` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1115` | `upload_proof_chunk` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1127` | `read_blob_generation` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1196` | `seal_bound_chunk` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1202` | `seal_bound_chunk` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1253` | `open_module_btf_fd_by_id` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1258` | `open_module_btf_fd_by_id` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1287` | `find_module_btf_id` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1300` | `find_module_btf_id` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1309` | `find_kfunc_btf_id` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1315` | `find_kfunc_btf_id` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1322` | `find_kfunc_btf_id` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1357` | `load_native_stub_btf_cache` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1373` | `load_native_stub_btf_cache` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1408` | `store_native_stub_btf_cache` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1415` | `store_native_stub_btf_cache` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1426` | `store_native_stub_btf_cache` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1432` | `store_native_stub_btf_cache` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1455` | `open_btf_fd_by_id_required` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1459` | `open_btf_fd_by_id_required` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1468` | `open_prog_fd_by_id_required` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1472` | `open_prog_fd_by_id_required` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1587` | `bpf_prog_load_native_stub_raw` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1589` | `bpf_prog_load_native_stub_raw` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1602` | `load_stub_prog` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1605` | `load_stub_prog` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1608` | `load_stub_prog` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1614` | `load_stub_prog` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1627` | `load_stub_prog` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1639` | `load_stub_prog` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1717` | `load_stub_prog` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1722` | `load_stub_prog` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1814` | `load_stub_prog` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1885` | `hash_file_identity` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1889` | `hash_file_identity` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1908` | `parse_decimal_u64` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1917` | `read_map_patch_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1929` | `read_map_patch_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1935` | `read_map_patch_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1940` | `read_map_patch_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1952` | `read_link_abi_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1966` | `read_link_abi_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1973` | `read_link_abi_file` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1980` | `read_link_abi_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:1984` | `read_link_abi_file` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:1988` | `read_link_abi_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2016` | `read_first_line_required` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2022` | `read_first_line_required` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2067` | `read_first_line_required` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2076` | `read_first_line_required` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2088` | `read_first_line_required` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2096` | `read_first_line_required` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2126` | `required_kernel_symbol_addr` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2210` | `roundup_pow2_mask` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2369` | `btf_symbol_name_from_func_info` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2374` | `btf_symbol_name_from_func_info` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2380` | `btf_symbol_name_from_func_info` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2417` | `btf_symbol_name_from_func_info` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2426` | `btf_symbol_name_from_func_info` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2434` | `btf_symbol_name_from_func_info` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2440` | `btf_symbol_name_from_func_info` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2459` | `load_prog_btf_symbol_name` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2468` | `load_prog_btf_symbol_name` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2479` | `load_prog_btf_symbol_name` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2484` | `load_prog_btf_symbol_name` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2507` | `load_prog_map_ids` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2510` | `load_prog_map_ids` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2553` | `verify_loaded_prog_uses_maps` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2562` | `load_map_info` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2600` | `collect_open_process_maps` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2620` | `collect_open_process_maps` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2632` | `collect_open_process_maps` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2835` | `run_subprocess` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2845` | `run_subprocess` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2862` | `run_subprocess` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2863` | `run_subprocess` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:2887` | `native_link_binary` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3156` | `add_map_symbol_alias_meta` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3174` | `bind_source_map_symbols` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3176` | `bind_source_map_symbols` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3254` | `find_loaded_manifest_native_symbol_map` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3297` | `find_open_process_manifest_native_symbol_map` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3333` | `find_open_process_manifest_native_symbol_map` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3375` | `find_open_process_manifest_native_symbol_map` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3390` | `find_open_process_manifest_native_symbol_map` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3405` | `add_known_kconfig_symbol_addrs` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3435` | `source_data_symbol_offset` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3447` | `source_data_symbol_offset` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3454` | `source_data_symbol_offset` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3459` | `source_data_symbol_offset` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3517` | `add_native_map_symbol_alias` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3524` | `add_native_map_symbol_alias` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3548` | `add_native_map_symbol_alias` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3638` | `inner_map_shape_for_outer_map` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3671` | `configure_lookup_site_for_shape` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3704` | `configure_lookup_site_for_shape` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3764` | `configure_update_site_for_shape` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3816` | `add_native_data_symbol_addrs` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3820` | `add_native_data_symbol_addrs` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3825` | `add_native_data_symbol_addrs` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3831` | `add_native_data_symbol_addrs` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3840` | `add_native_data_symbol_addrs` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3855` | `add_native_data_symbol_addrs` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3882` | `add_native_data_symbol_addrs` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3898` | `add_native_data_symbol_addrs` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3922` | `add_native_data_symbol_addrs` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3959` | `load_from_loaded_program_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:3980` | `load_from_loaded_program_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4379` | `publish_cache_file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4414` | `invoke_native_link` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4419` | `invoke_native_link` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4445` | `invoke_native_link` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4488` | `invoke_native_link` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4502` | `bind_native_map_relocations` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4506` | `bind_native_map_relocations` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4513` | `bind_native_map_relocations` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4517` | `bind_native_map_relocations` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4519` | `bind_native_map_relocations` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4545` | `bind_native_map_relocations` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4669` | `upload_and_load_stub` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:4838` | `upload_and_load_stub` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4868` | `reopen_relocated_map_fds` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4886` | `open_map_btf` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4899` | `validate_data_map_layout` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4909` | `validate_data_map_layout` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4922` | `validate_data_map_layout` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4926` | `validate_data_map_layout` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4938` | `read_proof_metadata` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4941` | `read_proof_metadata` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4943` | `read_proof_metadata` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4948` | `read_proof_metadata` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4950` | `read_proof_metadata` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4952` | `read_proof_metadata` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4955` | `read_proof_metadata` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:4974` | `bind_readonly_data_map` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:4978` | `bind_readonly_data_map` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:4980` | `bind_readonly_data_map` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:4984` | `bind_readonly_data_map` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:4988` | `bind_readonly_data_map` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:4993` | `bind_readonly_data_map` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:4995` | `bind_readonly_data_map` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:4997` | `bind_readonly_data_map` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:5013` | `bind_raw_proof_maps` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5022` | `bind_raw_proof_maps` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5029` | `bind_raw_proof_maps` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5034` | `bind_raw_proof_maps` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:5040` | `bind_raw_proof_maps` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5052` | `bind_raw_proof_maps` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:5065` | `bind_raw_proof_maps` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5083` | `open_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5089` | `open_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5092` | `open_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5098` | `open_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5112` | `open_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5125` | `open_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5131` | `open_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5139` | `open_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5143` | `open_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5149` | `open_simulator_proof` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:5157` | `open_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5162` | `open_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5172` | `decltype` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5177` | `decltype` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5183` | `decltype` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5185` | `decltype` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5188` | `decltype` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5201` | `relocate_vmlinux_proof_call` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5205` | `relocate_vmlinux_proof_call` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5210` | `relocate_vmlinux_proof_call` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5224` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5231` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5236` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5239` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5242` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5244` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5248` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5252` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5257` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5263` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5271` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5278` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5280` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5284` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5287` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5293` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5295` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5301` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5311` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5318` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5320` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5324` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5330` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5337` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5342` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5345` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5353` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5356` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5363` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5370` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5377` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5385` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5393` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5396` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5402` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5410` | `relocate_source_map_proof` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:5415` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5425` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5428` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5432` | `relocate_source_map_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5456` | `finish_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5459` | `finish_simulator_proof` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:5466` | `finish_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5473` | `finish_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5475` | `finish_simulator_proof` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5480` | `finish_simulator_proof` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:5506` | `submit_trusted_native` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:5509` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5525` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5530` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5533` | `submit_trusted_native` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:5543` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5546` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5550` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5567` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5574` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5577` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5594` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5597` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5603` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5610` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5613` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5615` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5618` | `submit_trusted_native` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5640` | `load_from_fd` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:5642` | `load_from_fd` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:5644` | `load_from_fd` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:5648` | `load_from_fd` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader.cpp:5651` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5654` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5660` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5677` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5699` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5706` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5740` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5775` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5778` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5781` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5786` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5796` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5827` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5864` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5878` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5881` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:5953` | `load_from_fd` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:6116` | `native_loader_load_from_fd_with_manifest_path_btf_and_context` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:6123` | `native_loader_load_from_fd_with_manifest_path_btf_and_context` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:6137` | `native_loader_load_from_fd_with_manifest_path_btf_and_context` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:6147` | `native_loader_load_from_fd_with_manifest_path_btf_and_context` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:6154` | `native_loader_load_from_fd_with_manifest_path_btf_and_context` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:6175` | `native_loader_load_from_fd_with_manifest_path_btf_and_context` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader.cpp:6181` | `native_loader_load_from_fd_with_manifest_path_btf_and_context` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_bytecode.hpp:151` | `collect_source_helper_calls` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_link_plan.hpp:142` | `write_native_link_plan` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_link_plan.hpp:162` | `write_native_link_plan` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_link_schema.hpp:34` | `add_name_addr` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_link_schema.hpp:63` | `make_link_lookup_site` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_link_schema.hpp:199` | `build_native_link_args` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:164` | `json_append_scalar` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:179` | `json_parse_string_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:190` | `json_parse_string_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:218` | `json_parse_string_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:224` | `json_parse_string_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:232` | `json_parse_string_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:235` | `json_parse_string_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:242` | `json_parse_string_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:246` | `json_parse_string_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:251` | `json_parse_string_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:255` | `json_parse_string_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:259` | `json_parse_string_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:264` | `json_parse_string_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:272` | `json_skip_array` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:278` | `json_skip_array` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:292` | `json_skip_array` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:299` | `json_skip_object` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:305` | `json_skip_object` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:313` | `json_skip_object` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:324` | `json_skip_object` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:332` | `json_skip_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:363` | `json_skip_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:371` | `json_find_key_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:378` | `json_find_key_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:386` | `json_find_key_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:390` | `json_find_key_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:402` | `json_find_key_value` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:431` | `json_object_string_list` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:438` | `json_object_string_list` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:452` | `json_object_string_list` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:461` | `json_required_string` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:475` | `json_object_u64` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:482` | `json_object_u64` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:490` | `json_object_u64` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:499` | `json_required_u32` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:518` | `json_object_bool` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:531` | `json_array_objects` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:538` | `json_array_objects` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:544` | `json_array_objects` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:552` | `json_array_objects` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:558` | `json_array_objects` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:566` | `json_require_object_fields` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:569` | `json_require_object_fields` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:571` | `json_require_object_fields` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:572` | `json_require_object_fields` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:576` | `json_require_object_fields` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:578` | `json_require_object_fields` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:581` | `json_require_object_fields` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:583` | `json_require_object_fields` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:597` | `parse_source_map_bindings` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:607` | `parse_proof_source_maps` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:614` | `parse_proof_source_maps` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:625` | `parse_source_map_fd_sites` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:635` | `parse_source_map_fd_sites` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:637` | `parse_source_map_fd_sites` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:638` | `parse_source_map_fd_sites` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:642` | `parse_source_map_fd_sites` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:710` | `manifest_source_bytecode_matches` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:716` | `manifest_source_bytecode_matches` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:735` | `manifest_bound_source_matches` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:794` | `parse_native_map_rule` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:868` | `parse_manifest_data_objects` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_loader_manifest.hpp:876` | `parse_manifest_data_objects` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:31` | `readonly_json_integer` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:40` | `readonly_json_integer` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:47` | `readonly_json_objects` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:49` | `readonly_json_objects` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:53` | `readonly_json_objects` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:60` | `readonly_json_objects` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:62` | `readonly_json_objects` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:70` | `parse_native_readonly_layout` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:77` | `parse_native_readonly_layout` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:79` | `parse_native_readonly_layout` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:89` | `parse_proof_readonly_bindings` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:99` | `parse_proof_readonly_bindings` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:108` | `parse_proof_readonly_bindings` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:111` | `parse_proof_readonly_bindings` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_rodata_binding.hpp:114` | `parse_proof_readonly_bindings` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:13` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:16` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:45` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:49` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:61` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:64` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:67` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:73` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:77` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:81` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:87` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:96` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:101` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/libnativeloader/src/native_tv_capture.hpp:107` | `capture_bound_artifact` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_compile.py:45` | `validate_job` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_compile.py:47` | `validate_job` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_compile.py:51` | `validate_job` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_compile.py:58` | `validate_job` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_compile.py:60` | `validate_job` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_compile.py:62` | `validate_job` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_compile.py:64` | `validate_job` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_compile.py:66` | `validate_job` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_compile.py:89` | `execute` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_compile.py:106` | `serve` | keep | c | generation, compiler or IO completion |
| `kprog/trusted_compile.py:142` | `submit` | keep | c | generation, compiler or IO completion |
| `kprog/trusted_compile.py:146` | `submit` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_compile.py:175` | `file` | keep | c | generation, compiler or IO completion |
| `kprog/trusted_generation.py:13` | `elf_symbol` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/trusted_generation.py:21` | `c_symbol_aliases` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/trusted_generation.py:34` | `u32` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/trusted_generation.py:40` | `declarations` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_generation.py:42` | `declarations` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_generation.py:45` | `declarations` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_generation.py:48` | `declarations` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_generation.py:50` | `declarations` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_generation.py:61` | `emit` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_generation.py:65` | `emit` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_generation.py:68` | `emit` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_generation.py:71` | `emit` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_generation.py:91` | `declarations` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_generation.py:94` | `declarations` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/trusted_generation.py:103` | `validate_native` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/trusted_generation.py:105` | `validate_native` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/trusted_generation.py:108` | `validate_native` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/trusted_generation.py:112` | `validate_native` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/trusted_generation.py:117` | `validate_native` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/trusted_service.py:58` | `next_request` | keep | b, c | request matching and queue lifecycle |
| `kprog/trusted_service.py:61` | `next_request` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:71` | `pairs` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:95` | `kernel_facts` | keep | b, c | request matching and queue lifecycle |
| `kprog/trusted_service.py:99` | `kernel_facts` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:102` | `kernel_facts` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:109` | `kernel_facts` | keep | b, c | request matching and queue lifecycle |
| `kprog/trusted_service.py:135` | `normalize` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:137` | `normalize` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:140` | `normalize` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:145` | `normalize` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:147` | `normalize` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:152` | `normalize` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:155` | `normalize` | keep | c | generation, compiler or IO completion |
| `kprog/trusted_service.py:159` | `normalize` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:163` | `normalize` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:166` | `normalize` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:196` | `serve` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:214` | `serve` | remove | outside a?e | policy or comparison removed |
| `kprog/trusted_service.py:244` | `serve` | keep | b, c | request matching and queue lifecycle |
| `kprog/trusted_service.py:277` | `run_application` | keep | c | generation, compiler or IO completion |
| `kprog/trusted_service.py:300` | `run_application` | keep | c | generation, compiler or IO completion |
| `kprog/trusted_service.py:313` | `run_application` | keep | c | generation, compiler or IO completion |
| `kprog/trusted_service.py:360` | `main` | keep | c | generation, compiler or IO completion |
| `kprog/tv/native-proof-regions.patch:32` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:41` | `file` | keep | b | copy, allocation and lifetime |
| `kprog/tv/native-proof-regions.patch:82` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:112` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:121` | `file` | keep | b | copy, allocation and lifetime |
| `kprog/tv/native-proof-regions.patch:168` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:367` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:376` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:385` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:396` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:405` | `file` | keep | b | copy, allocation and lifetime |
| `kprog/tv/native-proof-regions.patch:419` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:429` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:440` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:461` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:486` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:492` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:504` | `file` | keep | b | copy, allocation and lifetime |
| `kprog/tv/native-proof-regions.patch:535` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:559` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:564` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:568` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:586` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:595` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/native-proof-regions.patch:651` | `file` | keep | b | copy, allocation and lifetime |
| `kprog/tv/native-proof-regions.patch:734` | `file` | keep | a, e | input decoding, symbol/relocation resolution or IO |
| `kprog/tv/test_binding_kernel.c:50` | `use_context` | remove | outside a?e | policy or comparison removed |
| `kprog/tv/test_binding_kernel.c:66` | `create_context` | remove | outside a?e | policy or comparison removed |
| `kprog/tv/test_binding_kernel.c:75` | `fatal` | remove | outside a?e | policy or comparison removed |
| `kprog/tv/test_binding_kernel.c:91` | `upload` | remove | outside a?e | policy or comparison removed |
| `kprog/tv/test_binding_kernel.c:224` | `load_group` | remove | outside a?e | policy or comparison removed |
| `kprog/tv/test_binding_kernel.c:270` | `reject_surrounding_stack` | remove | outside a?e | policy or comparison removed |
| `kprog/tv/test_binding_kernel.c:597` | `helper_address` | remove | outside a?e | policy or comparison removed |
| `kprog/tv/test_x86_abi_kernel.py:29` | `file` | remove | outside a?e | policy or comparison removed |
| `kprog/tv/test_x86_abi_kernel.py:32` | `file` | remove | outside a?e | policy or comparison removed |
| `kprog/tv/test_x86_abi_kernel.py:48` | `file` | remove | outside a?e | policy or comparison removed |
| `kprog/tv/test_x86_abi_kernel.py:51` | `file` | remove | outside a?e | policy or comparison removed |
| `kprog/tv/test_x86_abi_kernel.py:55` | `file` | remove | outside a?e | policy or comparison removed |
| `kprog/tv/test_x86_abi_kernel.py:59` | `file` | remove | outside a?e | policy or comparison removed |
| `kprog/tv/test_x86_abi_kernel.py:79` | `file` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:142` | `parse_asm_text` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:168` | `parse_asm_text` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:199` | `parse_asm_text` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:210` | `section_size` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:230` | `load_rodata_blobs` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:238` | `load_rodata_blobs` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:260` | `parse_native_link_blob` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:357` | `parse_int` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:465` | `enc` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:482` | `relocated_data_address` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:496` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:503` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:505` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:531` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:541` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:564` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:568` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:578` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:581` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:585` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:592` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:600` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:614` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:620` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:637` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:640` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:655` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:674` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:678` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:683` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:691` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:695` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:698` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:703` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:707` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:717` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:721` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:728` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:735` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:738` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:765` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:776` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:807` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:808` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:813` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:823` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:840` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:844` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:854` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:880` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:881` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:885` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:899` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:905` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:910` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:916` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:927` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:933` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:935` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:937` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:943` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:948` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:958` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:963` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:969` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:977` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:982` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:986` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:999` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1002` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1007` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1018` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1021` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1031` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1037` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1040` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1044` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1053` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1056` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1066` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1069` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1073` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1076` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1080` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1086` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1090` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1095` | `encode` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1122` | `file` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1126` | `file` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1211` | `push` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1314` | `indirect_targets` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1320` | `indirect_targets` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1391` | `append_indirect` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1407` | `append_indirect` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1457` | `append_branch_or_ret` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1461` | `append_branch_or_ret` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1477` | `append_branch_or_ret` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1498` | `append_branch_or_ret` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1504` | `append_branch_or_ret` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1583` | `render_program` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1592` | `render_program` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1595` | `render_program` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1597` | `render_program` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1617` | `render_program` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1620` | `render_program` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1622` | `render_program` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1624` | `render_program` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1627` | `render_program` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1636` | `render_program` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1652` | `render_program` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1669` | `render_program` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1744` | `render_program` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1796` | `write_one` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/generate_micro_sim_proofs.py:1834` | `file` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/x86_abi.py:113` | `push` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:115` | `push` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:119` | `push` | keep | c | instruction, ELF or finite-target decoding |
| `kprog/x86/micro-prog/x86_abi.py:137` | `need` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:143` | `flags_needed` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:227` | `store` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:240` | `store` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:257` | `check_definedness` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:309` | `check_definedness` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:465` | `check_definedness` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:471` | `check_definedness` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:566` | `check_definedness` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:603` | `check_definedness` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:607` | `check_definedness` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:610` | `check_definedness` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:614` | `check_definedness` | remove | outside a?e | policy or comparison removed |
| `kprog/x86/micro-prog/x86_abi.py:628` | `check_definedness` | remove | outside a?e | policy or comparison removed |
| `kernel/bpf/verifier.c (applied baseline):3679` | `validate_kinsn_proof_seq` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3687` | `validate_kinsn_proof_seq` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3700` | `validate_kinsn_proof_seq` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3706` | `validate_kinsn_proof_seq` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3710` | `validate_kinsn_proof_seq` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3719` | `validate_kinsn_proof_seq` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3743` | `lower_kinsn_proof_regions` | keep | d, e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3747` | `lower_kinsn_proof_regions` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3750` | `lower_kinsn_proof_regions` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3761` | `lower_kinsn_proof_regions` | keep | d, e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3791` | `lower_kinsn_proof_regions` | keep | d, e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3796` | `lower_kinsn_proof_regions` | keep | d, e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3800` | `lower_kinsn_proof_regions` | keep | d, e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3806` | `lower_kinsn_proof_regions` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3817` | `lower_kinsn_proof_regions` | keep | d, e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3850` | `lower_kinsn_proof_regions` | keep | d, e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3875` | `lower_kinsn_proof_regions` | keep | d, e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3890` | `restore_kinsn_proof_regions` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3893` | `restore_kinsn_proof_regions` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3904` | `restore_kinsn_proof_regions` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3912` | `restore_kinsn_proof_regions` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3954` | `restore_kinsn_proof_regions` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3958` | `restore_kinsn_proof_regions` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):3961` | `restore_kinsn_proof_regions` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):21443` | `check_native_input` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):21448` | `check_native_input` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):21452` | `check_native_input` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):21470` | `check_native_input` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):21475` | `check_native_input` | keep | d, e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):21479` | `check_native_input` | remove | outside a?e | native B uses stock verifier; slice descriptors retain their decoder |
| `kernel/bpf/verifier.c (applied baseline):21483` | `check_native_input` | keep | d, e | native B uses stock verifier; slice descriptors retain their decoder |

## AArch64 migration

Shared publication `82f8e9e77` supplies the immutable chunk/capsule interface. The ARM candidate uses that interface with BL26/far-helper, perCPU, readonly and map/helper resolution. Its657-line module replaces the1269-line baseline. The inventory records127 baseline refusal expressions: 72 removal and55 functional keep decisions. [Exact source sites and decisions](arm64/refusal-inventory.json) accompany the candidate source and command archive.

The private simulator represents entry GPR/NZCV/vector values and helper caller-clobbers through kind6. The layout collector retains stack/payload geometry, and metadata decoding consumes the request fields. Existing byte-arm and skb CB representations join this source epoch. The existing142080 UBSan observations and TC BPF compile pass. The sole warm ARM kernel cache supplies the incremental Image and11-module build on16-19; the existing ARM loader cache supplies the paired caller/service binaries. BCC, Katran and the existing34 native-only cases follow the coherent build. Source/receipts are in [ARM preparation](arm64/preparation.json).

Safety has two facts: the stock verifier accepts B, and B faithfully simulates P. The five steps construct the kernel-copy relationship. Additional runtime admission checks follow the operator approval path through Notices.

### ARM ABI admission battery retirement

The executable `abi_check.py` battery and its `abi-effect-check`/`abi-positive-identity` launchers retire with the ABI-definedness refusal branches. The associated `abi-artifacts` launcher retires with that executable. Existing native-only and stage2 build/run targets continue to exercise instruction semantics and the stock verifier. The exact retired source and launcher epoch are retained in [ARM retirement inputs](arm64/retired-abi-admission.tar.gz); historical result archives retain their bytes. ARM safety replays use the original34 native fixtures through the five-step runtime.

### Lane V verification retirement

V follows the shared five-step implementation82f8e9e77. Safety uses stock
verifier acceptance of B and faithful simulation of P; the constructor uses
one kernel copy through generation and native emission.

| Verification artifact | Decision | Design step | Result |
| --- | --- | --- | --- |
| FULL_ARTIFACT_BINDING active coverage row | retire | b through e construction |20 functional transformation/composition rows remain |
| Runtime generation/snapshot, proof-sequence and resource admission claims | retire from active coverage | operator five-step scope | historical receipts keep their original source epochs |
| Encoder ABI-definedness/refusal battery | retire | c models unspecified state in B; d verifies B |176 admission assertions leave the entry point |
| Compiled CL/parity and MOVX semantic functions | keep | c faithful instruction handlers | same C/LLVM cases move together to check_x86_encoded_handlers.py |
| Deleted environment-binding fixture prerequisite | retire | current request-owned construction | native-link-arm-exclusive-check retains its semantic Lean target |
| Chunk bounds, partition and record rebase laws | keep | e functional layout | producer construction supplies their mathematical span premises |
| Relocation, map, spill, helper/kfunc/tail and final-image laws | keep | e functional resolution | existing theorem statements and bodies retained |
| One-copy generic checked-effects composition | keep and instantiate | b through e construction; d acceptance | one Artifact parameter, identity by reflexivity |

Composition.native_effects_from_kernel_copy and
Composition.generic_program_effects_from_kernel_copy, plus
SimulatorComposition.actual_program_effects_from_kernel_copy, expose the
single-copy interface. Existing general identity-transport theorems remain
available as mathematical lemmas. NativeLinkChunkLayout documents its span
and partition predicates as construction facts. Exclusive coverage references
canonical decode, marker execution and block preservation; old metadata scanner
claims leave its active theorem list while their pure lemmas remain.

V preserves all existing semantic Lean theorems and C/LLVM oracle functions.
The caller-clobber/unspecified entry model in82f8e9e77 supplies the current
step(c) state; its per-token ABI/native-link relations continue in O1/O2.
C's BCC/Katran and38-case safety receipts above are the published runtime
evidence. A owns the corresponding ARM module/application/safety port.

### AArch64 replay outcomes and operator case

The paired ARM build and module port are published as `e2d3a5ee8`. The x30 return-coordinate correction is captured in `5d27b2a9b`. Its native-only replay `996430e44` closes16 of the existing34 cases:4 native positive executions,9 stock-verifier refusals,2 generation coverage failures and1 accepted SP-alignment finding. Risk-case native executions total0; the accepted case used the existing load-only harness. The suite exits2 at that finding. [Exact replay status](arm64/replay-status.json) and [original raw trial](arm64/safety-x30-replay.json) retain every completed outcome.

The canonical ARM reference already represents `spAlignmentFault` at `Reference/AArch64.lean:526`. A generic B-level fault representation for incoming-SP alignment and architectural register-overlap faults is posted under Notices for operator approval, following the operator rule for added predicates. The proposed operation bodies carry architectural fault effects through B and retain the five-step constructor. [The approval case](arm64/architectural-fault-approval-case.json) records the concrete finding and scope. Whole BCC/Katran collection continues through captured source epochs.

The first five-step BCC epoch `043482cfd` records23 baseline resident programs and5 native requests, each generated and compiled. Four requests reach the stock-verifier return-dispatch default; one records a kernel chunk lookup errno2. The x30-corrected whole BCC/Katran queue follows the retained original epoch and the safety trial. Raw workload and per-program counters remain in the dated corpus result archive.

### Lane V DIV admission assertion retirement

The historical DIV tool still expected the removed ABI-definedness pass to
refuse two undefined-result observations. Those two generation-admission
assertions retire under step(c), where B models unspecified state, and
step(d), where the stock verifier decides B. The18,432 CPU comparisons,
nine primary BPF variants, nine fault-marker objects and two narrow-result
controls remain and pass. Original e12 full Make exit2 and all1263 source
hashes remain in the verification ledger alongside the retained tool's exit0.
