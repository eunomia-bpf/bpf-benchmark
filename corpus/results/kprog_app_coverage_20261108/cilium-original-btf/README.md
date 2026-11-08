# Cilium whole-application original-BTF replay010928

The original upstream app uses the registered native-only service and captured coherent x86 runtime pair. Both observed native requests freshly generate and compile; cil_xdp_entry binds. The TC tail_handle_ipv4_from_host passes original-BTF/kfunc relocation and bound-proof transport, then reaches the kernel native-region call-identity guard before instruction exploration. The raw diagnostic is `kinsn proof call requires a resolved helper identity`.

| Baseline resident | Generated | Compiled | Bound | Specialization/loader errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 72 | 2 | 2 | 1 | 0 | 1 |

Both terminal native hashes and captured source pins reconcile. The complete original native/app/workload, common57e6module and paired original-BTF/mapless/src2-transport caller/worker retain their epochs. The run uses20-23/eightvCPU/12GiB and one2-second existing workload sample. The next generic change closes the canonical resolved-vmlinux call guard in kernel native-region validation.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/cilium-original-btf-replay/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/cilium-original-btf-replay APPS=cilium/agent CPUS=20-23 VM_MEM=12G VM_CPUS=8 SAMPLES=1 WORKLOAD_DURATION=2
```

`service.tar.gz` preserves original native/proof inputs and full generation/compiler/verifier/kernel logs. `result.tar.gz` preserves upstream startup/JIT workload/shim records; `launch.tar.gz` captures private/source/image/binary commands, including coherent transport adoption. `coverage.json` and `observations.json` preserve inventories and artifact hashes.
