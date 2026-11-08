# Original BCC and Katran after undefined flag source adoption

The current paired image/kernel/ordinary/native modules, original upstream application/native objects and established two-second workload retain their definitions. The captured C simulator contains the adopted ANDN/BZHI PF/AF kind6 assignments; generated operation code and every included dependency carry hashes in [summary.json](summary.json). The existing native38 replay closes before this whole-app guest starts.

Actual generated/compiled/installed/failures: (26, 26, 26, 0). Work stages: [{'application': 'bcc/set', 'status': 'ok', 'error': ''}, {'application': 'katran', 'status': 'ok', 'error': ''}]. [coverage.json](coverage.json) and [work.json](work.json) retain the full native request rows, original counters and workload/lifecycle outcomes. The four other application rows retain their earlier published source epochs and actual frontiers.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/bcc-katran-undefined-flags/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/bcc-katran-undefined-flags CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=bcc/set,katran SAMPLES=1 WORKLOAD_DURATION=2
```

[runtime.tar.gz](runtime.tar.gz) retains the captured source/header/dependencies, commands and actual setup/terminal output. Every native P/generated B/compiler/verifier archive remains in the service receipt. Timing ownership stays with R; runtime admission additions0.

Current canonical-source work accounting is in [work-accounting.json](work-accounting.json), derived directly from [work.json](work.json). Each phase retains every program's run/time counters and the original workload return code. BCC exercises the original four stressors; both phases report all294system-call tests with220fast75tests exercised. The short syscall cohort records514bogo operations in each arm. Cap/set/socket duration-driven totals and actual elapsed time remain separate observations.

| Application work | JIT baseline | Verified native |
| --- | ---: | ---: |
| BCC syscall bogo ops | 514 | 514 |
| BCC cap bogo ops | 367873 | 392423 |
| BCC set bogo ops | 29345 | 29196 |
| BCC sockfd bogo ops | 158688 | 140420 |
| Katran LB RX / pktgen / BPF / TX action / VIP / LRU / real-map packets | 2465260 | 2486410 |
| Katran LRU misses | 0 | 0 |
| Katran receiver packets | 2465261 | 2486126 |
| Katran LB TX dropped | 0 | 0 |
| Katran receiver dropped | 0 | 284 |
| Katran receiver plus recorded drops minus input | 1 | 0 |

Katran has matching LB RX, pktgen, BPF, TX-action, VIP, LRU and real-map counts within each phase. Baseline interface TX and receiver deltas carry one additional packet at their sampling boundary; the baseline before/after counters remain available in work.json. Native receiver plus284recorded drops accounts for all2486410input packets. Duration-driven phase totals, the extra baseline interface packet and actual losses remain in the report. These functional observations support the current whole-app readiness; R owns counterbalanced timing, latency and CPU attribution. The latest simulator change affects B flag outputs; the native P used by the application retains its original bytes.
