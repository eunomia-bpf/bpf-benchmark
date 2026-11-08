Private pointer payload layout for external copies

The layout collector now distinguishes a proved external memcpy destination from private and unknown destinations. SP-derived dynamic destinations preserve their existing complete payload geometry. Memory instructions and simulator C bodies retain their semantics. The original external-copy regression and the first proposal dynamic-destination regression retain their failing outputs; the final four-scene test and shared service suite carry the current outcomes in summary.json.

The captured Tetragon event_wake_up_new_task native P, proof object and baseline B are retained. Baseline recompilation has identical allocated sections to the original B and maxFP872. The precise layout uses native368bytes, one pointer payload slot at-64, and compiled maxFP488. Exact commands, source, objects and disassembly accompany these compiler measurements. Stock verification and complete application outcomes follow the corrected queued Tetragon cohort.
