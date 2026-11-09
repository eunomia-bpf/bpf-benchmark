Region compiler spike

The experiment outlines the ordinary generated B basic blocks into BPF noinline functions. One explicit state object carries the complete entry locals, native byte arena, forwarding cells, flags and return value between regions. Each original direct transfer returns its destination block number to an entry dispatcher; original C return expressions populate a distinct completion cell. Existing instruction and fault bodies remain expanded from the captured canonical header.

The production generation and native submission paths retain their current source. This experiment measures compiler time and per-function direct R10 offsets, with stock-verifier acceptance tracked separately.

Initial actions input: source05b80424b, 846 instruction labels, 150 basic blocks, 214 explicit CFG edges and two original value returns. Clang18 BPF C syntax analysis exits0. The archive retains original expanded C, outlined C and diagnostics. Native execution requests:0. The actions, process_filter and process_event B compile observations follow in the same result directory.

Command: python3 kprog/x86/micro-prog/region_spike.py expanded.c regions.c --report layout.json

Completed stage: all three outlined bodies compile successfully with the existing O3/4096-byte compiler profile.

| Body | Basic blocks | Clang seconds | Shared state bytes | Entry direct R10 | Deepest outlined direct R10 |
| --- | ---: | ---: | ---: | ---: | ---: |
| 104 | 150 | 45.98 | 1264 | -1264 | -128 |
| 100 | 438 | 179.42 | 1672 | -1672 | -296 |
| 102 | 631 | 436.82 | 2616 | -2616 | -536 |

Bodies104/100/102 are generic_kprobe_actions/process_filter/process_event. The whole-function scoped05b actions and process_filter compiles took106.27s/480.97s with direct R10-568/-1632. Outlining takes45.98s/179.42s, with complete shared state1264B/1672B. Process_event now compiles in436.82s with shared state2616B and one outlined frame reaching direct R10-536. Baseline process_event failed its compiler stack profile. These observations identify the remaining shared-state and per-region stack requirements; stock-verifier outcomes remain a separate stage.

The entry state exceeds the production512B capacity for all three bodies. A smaller complete boundary representation remains part of the generic storage work. State bytes come from DWARF and direct R10 offsets come from actual BPF load/store instructions; actual JIT/combined-frame depth remains a separate measurement. Native execution requests:0.

Each numeric raw archive retains commands, expanded/outlined C, compiler output and the BPF object. Actions expanded/outlined C are retained by initial-syntax.tar.gz; its numeric archive carries the completed compiler result. Ordered part manifests preserve compressed streams above48MB. Every archive entry was read back against the original byte hash. Stage publication occurs once after all three results.
