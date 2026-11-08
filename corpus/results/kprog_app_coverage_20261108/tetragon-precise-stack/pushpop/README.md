# Native pointer representation through register and memory PUSH/POP

The current model preserves the architectural numeric stack bytes through PUSH/POP, but loses the separately saved pointer representation that MOV spill/reload already carries. This private candidate records a full-width register or stack-memory source representation on PUSH and restores it on POP. PUSH RSP captures the original SP before decrement. Memory PUSH reads at old SP; memory POP computes its destination after increment. Partial overwrites and opaque calls discard affected facts, and numeric bytes keep their original values. The candidate adds no native address, target, stack bound or admission check.

| Existing/control evidence | Result |
| --- | --- |
| Current model against pointer roundtrip regression | compile0, host1; raw value matches, first saved pointer tag is lost |
| Candidate register/RSP/memory/alias transfer, partial overwrite and helper effects | 240cases, ASan/UBSan0 |
| Original PUSH/POP generated handler contract | 463cases, ASan/UBSan0 |
| Original complete state PUSH/POP routing oracle | 347,152cases, ASan/UBSan0 |

The complete original Tetragon event_execve native P75318ea5 is compiling with this model separately. A compiler success or host equality does not establish stock-verifier acceptance or whole-application completion. Canonical source is still d963788c0. The raw native oracle, original failed control and complete unchanged routing domains are archived. Universal erasure/compiler/helper-frame obligations remain O2/O4 work for V; no per-program proof was created.
