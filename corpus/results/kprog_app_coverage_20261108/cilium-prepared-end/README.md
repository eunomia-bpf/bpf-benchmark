# Cilium native prepared packet end

The native-only ctx_data_end ABI shim reads the same kernel-prepared pointer as the stock BPF context converter. Kernel bpf_compute_data_pointers writes data+skb_headlen to skb.cb.data_end, and filter.c loads that slot for __sk_buff.data_end. The native Cilium layout exposes it as cb[8], at48+32=80. The original BPF ctx function and application algorithm/workload retain their source. This replaces the native shim's separate data+(len-data_len) computation and forms a new native input epoch.

| Complete original application outcome | Actual value |
| --- | --- |
| Baseline resident BPF census | 72 |
| Native terminal requests | 5 |
| Generated and compiled | 5 / 5 |
| Stock accepted and installed | 4 |
| Specialization/compiler/loader failures | 0 |
| Stock verifier rejection | tail_ipv4_policy, helper9 R3scalar,2899instructions/73states |
| Terminal native object hash joins | 5 / 5 |

cil_xdp_entry, tail_nodeport_nat_egress_ipv4, tail_drop_notify and tail_handle_snat_fwd_ipv4 install through the complete five-step startup. The later tail_ipv4_policy request reaches bpf_skb_store_bytes with a scalar argument3. Its native pointer reaches that helper through a stack spill: lea rax,[rsp+48]; mov [rsp+120],rax; ...; mov rdx,[rsp+120]. The current numeric stack-address representation loses the verifier pointer during that spill. The original native bytes and full verifier trace retain this next generic memory/ABI frontier. The whole application reports its original startup error; complete application work/timing remains pending.

```sh
D=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps
make -f "$D/cilium-live-data-end/Makefile" image
make -f "$D/cilium-prepared-end/Makefile" corpus STATE="$D/cilium-prepared-end" CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=cilium/agent SAMPLES=1 WORKLOAD_DURATION=2
```

runtime.tar.gz retains the one-file image layer, image identity/build receipts, exact source/ABI change, frozen model/compiler wrapper and complete launch/exit receipts. Full request/native objects and application metrics remain in service.tar.gz and result.tar.gz. R keeps previous native timing inputs; this native ABI epoch has its own request hashes. The canonical native shim now uses the measured prepared-slot representation. V owns its universal entry/link relation. Additional admission predicates total0.
