# x86 live skb scalar fields and memory arithmetic

The canonical model maps native tc_index134/u16, priority144/u32 and mark168/u32 to their live BPF context fields. Each native byte/word/dword read selects its exact lane; partial writes preserve the other native field bits. MOV stores and the three arithmetic memory writers use the same native-address projection, retaining architectural flags. The existing stock context conversion supplies the kernel write. Every other native field keeps its actual kernel memory access.

| Observation | Actual result |
| --- | --- |
| Initial four-field context fixture | 229120full-state/width/alias observations,0differences,UBSan |
| Canonical three-field fixture | 217600observations,0differences,UBSan |
| Captured complete cil_from_netdev source, both candidates | compiles,exit0 |
| Existing micro compile target, canonical snapshot | 29positive+1negative-native,exit0; actual compiler logs retained |
| Complete Cilium, initial four-field snapshot | 2generated/compiled,1installed; tail_nodeport_nat_ingress_ipv4 packetoff18/size2 after415instructions |
| Canonical complete Cilium and BCC/Katran | detached sequential replay; terminal records follow |

The initial candidate also projects queue_mapping124/u16. Kernel filter.c shows its context setter skips65535, while a raw native16-bit store writes that value. The canonical snapshot therefore keeps queue_mapping on the actual kernel-memory route and maps the three fields whose context setters retain raw native writes. All initial source and measurements remain captured separately.

The initial private Makefiles have a micro target colliding with the repository micro directory. Their original logs retain `up to date` and make exit0. That receipt is a command outcome. The canonical private Makefile marks the existing micro target phony and executes the29positive plus1negative-native compiler sequence, whose original commands, object files and per-program outcomes appear in canonical-three-field.tar.gz. An initial private fixture edit omitted the array terminator; its compile error remains archived beside the corrected217600-observation execution.

The whole original Cilium startup with the initial snapshot reaches a native boundary comparison `data + (len - data_len)`. Both length fields retain real kernel values; the stock verifier treats the sum as an ordinary packet pointer and reports `invalid access to packet, off=18 size=2`. Its2terminal native hashes match their captured inputs. The source-generation epoch and the kernel/runtime identities remain in the request and runtime archives.

```sh
D=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps
make -f "$D/skb-scalar-write/Makefile" host cilium micro
make -f "$D/cilium-skb-write/Makefile" corpus STATE="$D/cilium-skb-write" CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=cilium/agent SAMPLES=1 WORKLOAD_DURATION=2
make -f "$D/bcc-katran-skb-write/Makefile" corpus STATE="$D/bcc-katran-skb-write" CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=bcc/set,katran SAMPLES=1 WORKLOAD_DURATION=2
```

The field and memory-operation relations apply generically to all native programs. V owns their universal ABI/token integration. Additional runtime admission predicates total0.
