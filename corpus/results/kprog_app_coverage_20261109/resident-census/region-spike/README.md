Region compiler spike

The experiment outlines the ordinary generated B basic blocks into BPF noinline functions. One explicit state object carries the complete entry locals, native byte arena, forwarding cells, flags and return value between regions. Each original direct transfer returns its destination block number to an entry dispatcher; original C return expressions populate a distinct completion cell. Existing instruction and fault bodies remain expanded from the captured canonical header.

The production generation and native submission paths retain their current source. This experiment measures compiler time and per-function direct R10 offsets, with stock-verifier acceptance tracked separately.

Initial actions input: source05b80424b, 846 instruction labels, 150 basic blocks, 214 explicit CFG edges and two original value returns. Clang18 BPF C syntax analysis exits0. The archive retains original expanded C, outlined C and diagnostics. Native execution requests:0. The actions, process_filter and process_event B compile observations follow in the same result directory.

Command: python3 kprog/x86/micro-prog/region_spike.py expanded.c regions.c --report layout.json
