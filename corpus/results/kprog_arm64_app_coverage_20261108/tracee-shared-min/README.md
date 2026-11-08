Paired ARM Tracee shared clamp register operand

Published shared source20096bb3c puts the existing empty register barrier inside update_min and covers every original clamp, including string-array ellipsis offset. It replaces the earlier four local barriers and retains all values, numeric limits, existing conditions, buffer fields and helper calls. Both native/JIT frontends read the same complete C tree. Canonical O3/JIT flags, ARM cross-library paths and warm Go/libbpf outputs are retained. Actual Makeexit:0.

Prior original whole ARM source d920fbca5 reaches the JIT ellipsis maxoffset65672/4096 on32536map. This build adopts C common repair as the single selected source. The earlier private A local-offset variant is retained as a compiler diagnostic. Runtime admission additions:0.
