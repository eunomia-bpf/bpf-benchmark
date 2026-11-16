Current six-app host link replay, 2026-11-16

The next publication needs current-P proof extraction and kernel emission from
the six apps' last captured load facts. The old replay entry was removed by
cleanup; experiments live here rather than recreating a shared test target.

Fresh Tracee capture is needed: all six retained Tracee kernel plans in the
08:xx inventory predate kernel_layout. Missing layout or boot addresses will
not be guessed. The completed C runs demonstrate application loading but do
not retain the loader's temporary native-link cache in their result bundle.

`make -f kprog/results/host-link-replay-20261116/Makefile capture-tracee`
reuses the committed shared-link capture adapter and profile workflow. The
adapter delegates every proof/kernel invocation to the existing image linker
and archives actual input proof, plan, blob, relocations, map patches and ABI.
There is no code substitution. Captures are under the existing corpus result
mount at corpus/results/shared-hash-regression-20261116/captures; commands,
workload logs, counters and live JIT bytes stay under the raw root above.

This is a functional load-fact capture with the existing diagnostic contract:
image 6641a7e1, four vCPUs/32 GiB on 20-23, image SH, one 60-second sample per
arm, cycles:G at 199 Hz. It is not official default timing. C's frozen round
on 0-7 continues. The controller uses a 48 GiB address-space cap. No image,
base, source tool, kernel or benchmark setting is changed. Raw data stays.

Current tools for later replay are the existing release native-link and
vendor/build/native-bpf/x86/stage/kprog-perf-context-lto. The latter is the
P-stage compiler, not a verified-compiler binary or the retired /var/tmp tool.
Entry proof extraction follows native_loader_entry_data.hpp:33-43, without
the old host-only --preserve-entry-abi argument. Missing runtime function,
immutable-data or map-template facts remain explicit coverage limits.

`dry-run` lists the 475 retained candidate entries and tools. `proofs` extracts
all current-P entries with two workers, including the eleven recorded OTel
PERF_EVENT conversions with the current P-stage compiler. It uses the runtime
entry ABI contract. Every command, output and failure is retained separately.
No guest/image/base rebuild is part of that target. Its controller inherits a
16 GiB address-space cap and runs on 16,19. Runtime immutable/map-template and
generated-function facts are not supplied when absent from the retained input;
those limits remain distinct from entry extraction and later kernel emission.

Completed subset results

| App | Current-P entry extractions | Captured kernel emissions |
|---|---:|---:|
| BCC | 34/34 | 25/25 |
| Cilium | 80/80 | 28/28 |
| Katran | 3/3 | 1/1 |
| OTel | 30/30 | 14/14 |
| Tetragon | 154/154 | 2/2 |
| Tracee | 174/174 | 169/169 |
| Total | 475/475 | 239/239 |

All eleven recorded PERF_EVENT conversions pass. Entry extraction controller
1955248 finished zero. Kernel replay controller 1958588 finished zero after
the harness fix below. Fresh shared-link captures replace the six old Tracee
plans that lacked kernel_layout; no layout or boot address was synthesized.
Kernel emissions use newly extracted current-P proofs with the runtime entry
ABI. Other apps retain their explicitly paired source-file requests; OTel and
Katran use the latest shared-case capture plans. No LTO piece is disabled.

The initial kernel replay had one harness error: tail_no_service_ipv4 retained
only its originally numbered 1.link-plan.json after source pairing, while the
new replay assumed 0.link-plan.json. a8c271183 reads the exact plan path from
each recorded command. All initial results remain in raw emission-initial;
the corrected full host confirmation remains in emission-current. This was
a replay-path error rather than a native-link rejection.

The Tracee functional capture 215747_562449 completes with app status ok and
native measurement completed. Its shim records 169 native replacements and
the adapter archives 169 unique entry requests. The measurement window holds
167 programs in each arm; shorter-lived programs are separate from that
window inventory. Measured installed totals are 2068774 B JIT and 1693847 B
native. These are diagnostic inventory/size observations, not a new timing
headline. Controller 1953931 is terminal; CPUs 20-23 and image SH are released.

Candidate symbols are not runtime program counts. Many static entries have
no captured load context, and the two Tetragon requests do not cover generated
policy/CEL callees. Runtime immutable-data/map-template/function-body facts
missing from a retained request remain outside that request's coverage.
Entry extraction and kernel emission do not establish stock B acceptance,
native execution of every candidate or Cilium packet-path equality. These
remain required application checks after coherent publication. No image or
base was published during C's current round.

Reports and commands are in proofs-report.json, emission-report.json and
tracee-inputs.json. Large ELF/blob/profile captures stay under the persistent
raw root and the existing corpus result mount. Reproduce emission using the
result Makefile; use a new EMISSION_OUTPUT directory to retain prior output.
