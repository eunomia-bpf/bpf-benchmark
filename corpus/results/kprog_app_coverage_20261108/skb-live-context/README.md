# x86 live kernel skb context and exact helper base

The x86 skb model now uses the actual kernel object through the existing `bpf_cast_to_kern_ctx` identity. Ordinary fields retain real values and widths, including skb.len112 and data_len116. Packet data/data_end and qdisc-cb accesses use the corresponding live typed BPF fields. Scratch writes reach the context before helpers and tail calls; architectural RAX supplies return. This port shares the canonical AArch64 mechanism.

The prior216-byte skb proxy initializes native offsets112/116 as padding, while the captured Cilium source reads both fields. The actual kernel layout gives len112,data_len116. The current context representation preserves those fields and retires the proxy storage from active access. Current captured Cilium compilation has maximum direct frame416bytes and0direct accesses beyond512, compared with616bytes in its same-epoch scalar-flag proxy baseline. This is a compiler observation; complete application acceptance is recorded separately.

The shared helper-context relation translates exactly VALUE==BASE to KERNEL. Its runtime KERNEL-nonnull conjunct is removed, following the design-only priority. The original universal Lean reference and arbitrary external-helper transition relation use the same exact-base rule. All other addresses keep their value. The prior whole Cilium source eliminates VALUE==BASE and reaches the remaining ctx-null branch, passing trusted_ptr_sk_buff into perf_event_output25 on its alternate. The stock verifier records expectedCTX after428instructions/9states. The current rule removes that extra branch and retains the existing actual address conversion.

| Component observation | Actual outcome |
| --- | --- |
| Existing cross-ISA cb/packet width and alias fixture | 142080cases,0differences |
| Same fixture including native112/116read/subtract/aliases | 144640cases,0differences,UBSan |
| Current captured whole Cilium source compile | exit0 |
| Existing micro compile controls | 29positive+1negative-native,exit0 |
| Existing helper typed-ABI route / ID cases | 18946 / 4100,0differences,UBSan |
| Existing universal X86MovLoadHandler / Arm64HelperArgPtrShape Lean modules | both build,exit0 |
| Complete original Cilium successor | 2generated/compiled,1installed; tc_index byteAND write |
| Complete original BCC/Katran successor | 26generated/compiled/installed; both applications ok |

The first two live-context Cilium cohorts each record2generated/compiled and1installed, reaching helper25context typing. Their BCC/Katran setup commands use the initial `bcc,katran` alias and retain the corpus unknown-app error with0native submissions. The current private recipe forwards the original concrete `bcc/set,katran` application ids. Both preceding source epochs and all actual counters/errors remain in `earlier-cohorts.tar.gz`.

The initial field-profile component has a private host-binary writer collision; its separate sequential host execution passes. The current successor uses one controller for host, captured compile, micro compile and whole applications. Its typed packet-context load emits the existing A-style u32 LDX into a64-bit compiler value, preserving the stock verifier's packet pointer. The initial Lean signature migration retains its failed reference-arity receipt; the corrected exact-base reference and both modules build successfully. Additional runtime admission predicates total0; one runtime guard is removed.

```sh
D=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps
make -f "$D/skb-live-context/Makefile" host
make -f "$D/skb-live-context/Makefile" cilium
make -f "$D/skb-live-context/Makefile" micro
make -f "$D/exact-helper-context/Makefile" proof host
make -f "$D/cilium-skb-live/Makefile" corpus STATE="$D/cilium-skb-live" CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=cilium/agent SAMPLES=1 WORKLOAD_DURATION=2
make -f "$D/bcc-katran-skb-live/Makefile" corpus STATE="$D/bcc-katran-skb-live" CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=bcc/set,katran SAMPLES=1 WORKLOAD_DURATION=2
```

`component.tar.gz` keeps the exact canonical candidate/base/patch, current source/BPF/compiler commands, all component outcomes, shared C/Lean files and whole-app launch recipes. The shared five-step kernel/module and native application inputs retain their earlier identities. V owns the universal ABI/token/link integration; the generic helper context relation applies to both ISAs.

The complete current live-context Cilium startup closes at `cil_from_netdev`: native byteAND at skb.tc_index134 reaches the stock BTF writer restriction `only read is supported`, after528instructions/7states. Live cb writes and helper25context conversion precede this frontier successfully. Its2terminal native hashes match their captured inputs. The following scalar-field source epoch retains a separate whole-application receipt.

The complete original BCC/Katran replay installs25BCC programs and1Katran program, and both workloads report `ok`. Its26native input hashes equal the earlier final five-step cohort. Katran native pktgen,BPF,total,VIP,LRU andTX each record2454567packets, with0LRUmisses. Receiver2454279 plus288RX-interface drops accounts for2454567; TX-interface drops0. JIT records2437119BPF runs,2437118VIP/LRU/TX and1PASS; received2395903 plus41047TX-interface and168RX-interface drops accounts for2437118TX. The original raw work, per-program counters and errors remain in each result archive. R keeps timing and same-work attribution ownership.

`cilium-skb-live/` and `bcc-katran-skb-live/` retain coverage, full request/result archives and closed launch/runtime receipts. `live-context-work.json` records native-input equality and terminal application status. The current context-model correction changes B while retaining P and the shared kernel/module/runtime identities.
