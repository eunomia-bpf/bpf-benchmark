Paired ARM Tracee existing-clamp source

Both native and JIT frontends read the complete published Tracee C tree d920fbca5, keeping existing size bounds, guards, checked string offset and the four recorded register barriers. The upstream source-change ledger records the edits and patches. The ARM Go/libbpf output cache is reused, and an isolated embedded-dist holds the new JIT object for the original application binary. Canonical compiler flags are retained. Actual Make exit:2.

compile.json pins complete selected C inputs and actual output files; compile-inputs.tar.gz retains compiler commands, diagnostics and source. Same-copy P remains the simulator/JIT input. The full original workload follows the existing serial guest after this build. Runtime admission additions:0.
