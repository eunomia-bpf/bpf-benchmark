# x86 XDP metadata projection, November8 UTC

The generic x86 XDP-context read projects the native64-bit field at offset16 to `xdp_md.data_meta`. Cilium's native compatibility routine reads exactly this field, and the current kernel `xdp_buff` layout records data0, data_end8 and data_meta16. The existing scalar constructor policy for offset16 stays in the shared ABI. The implementation adds three C-model lines; additional runtime admission predicates total0.

The original complete Cilium startup reaches three generated/compiled requests and installs `cil_xdp_entry` and `cil_host_policy`. `tail_handle_ipv4` reaches the stock verifier and reports `misaligned stack access off 0+-156+0 size 8` after352instructions. The original corpus records startup error and preserves its application stderr and work counters. Its baseline resident census is56. Earlier snapshots retain their own resident counts and native inputs.

| Entry | Generated | Compiled | Installed | Terminal outcome |
| --- | ---: | ---: | ---: | --- |
| cil_xdp_entry | 1 | 1 | 1 | installed |
| cil_host_policy | 1 | 1 | 1 | installed |
| tail_handle_ipv4 | 1 | 1 | 0 | stock-verifier stack alignment |

The previous helper189 snapshot reaches the offset16 projection during compile. The extended snapshot completes that compile and its XDP installation. All three terminal native hashes join their captured objects. The29micro positive compile controls and one negative-native compile control complete with exit0. The retained first invocation records its taskset command spelling error; the corrected invocation uses `taskset -c 8-11` and completes the existing target.

Commands through bws.sh:

```sh
M=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/xdp-metadata
make -f "$M/Makefile" micro
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/cilium-xdp-metadata/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/cilium-xdp-metadata CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=cilium/agent SAMPLES=1 WORKLOAD_DURATION=2
```

`runtime.tar.gz` preserves the model snapshot/patch, kernel layout, existing compile-control results and actual launch records. `service.tar.gz` carries native requests, generated C/BPF and stock-verifier logs. `result.tar.gz` preserves the whole original corpus result; `coverage.json` carries request-by-request joins. The kernel image is4eaf9f27, vmlinux1530dcc6, with842matching modules. BCC/Katran retain their completed workload receipts; Cilium's next generic frontier is native unaligned-stack access representation in B.
