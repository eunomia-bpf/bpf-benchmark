# BCC and Katran on the final five-step runtime

The original two-start corpus protocol completes both applications. BCC generates, compiles and installs25/25 programs; Katran completes1/1. All26 actual native object hashes match the terminal records, and their multiset matches the earlier five-step application cohort. Corpus metadata is `completed`; both app statuses and verified-native-loader statuses are `ok`.

The guest uses the final kernel's842 matching standard modules and captured a04786538 simulator/header inputs. Eight vCPUs,12GiB, host CPUs20-23 and the original two-second workload supply functional measurements. R retains ownership of timing on CPUs0-7. The helper189 extension has its separate source epoch and complete Cilium successor.

| BCC stressor | JIT bogo operations | Native bogo operations |
| --- | ---: | ---: |
| syscall |514|514|
| cap |356269|379425|
| set |28845|26748|
| sockfd |176528|170543|

All four stressors complete in each arm. Duration-driven counts and all25 per-program run/time counters remain in the raw output.

| Katran measured work | JIT | Native |
| --- | ---: | ---: |
| pktgen packets / BPF runs / total / VIP / LRU / TX |2523084|2455449|
| LRU misses / BPF drops |0|0|
| receiver packets |2523084|2452337|
| load-balancer TX interface drops |0|2550|
| receiver RX interface drops |0|562|

Within each arm, pktgen, BPF and application processing counts agree. In the native arm,2452337 received packets plus2550 TX-interface drops plus562 RX-interface drops account for all2455449 processed packets. All interface and application counters retain their original before/after values in the cohort. These are short functional results with their measured delivery losses and duration-driven workload sizes.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/bcc-katran-final/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/bcc-katran-final CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=bcc/set,katran SAMPLES=1 WORKLOAD_DURATION=2
```

`applications.tar.gz` retains the complete26 native/generated/verifier/service archives, corpus output, per-program counters and application work. `runtime.tar.gz` retains the captured launch/header/Python inputs and actual compiler receipts. `observations.json` records the measured counters, source hash and native-object identity comparison. The detached cohort controller owns its host compiler lifetime; the command above uses that controller's broker while it is active.
