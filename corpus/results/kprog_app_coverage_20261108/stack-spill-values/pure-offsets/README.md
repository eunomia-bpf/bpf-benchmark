# Pure ghost offsets with unchanged raw architectural accesses

This private successor keeps the stack metadata index before the existing empty-assembly address-opacity expression. The architectural load/store retains its original address and barrier. The per-slot metadata uses the same overlap, tag and helper-lifetime semantics as the named candidate. This changes the compiler representation; no runtime admission check, bound, assertion or per-program proof was added. Production sources retain the committed implementation.

Actual terminal results: exits {"component": 0, "host": 0, "micro": 2, "safety": 0}; component [{"instructions": 8849, "maximum_fp_minus_offset": 376, "section": "tc"}]; safety {"specialization_rejected": 2, "valid_executed": 9, "verifier_rejected": 27}.

The host log records52,992 CPU pointer-byte/partial-store comparisons and552 deallocated-frame helper comparisons with ASan and UBSan. The actual log/exit files retain any failure. `outcomes.json` carries every original native safety input hash and terminal stage. `compiler-and-replays.tar.gz` contains all commands, complete sources, the actual complete Cilium object, the existing38-case service replay and existing29+1micro compiler artifacts. A captured component compilation or verifier acceptance does not establish whole-application completion. O2/O4 universal model/compiler obligations retain V ownership.

```sh
N=/workspaces/.agent-state/kprog-lanes/C/design-only/stack-spill-values
make -f "$N/Makefile" component host host-liveness
make -f "$N/pure-safety/Makefile" replay
make -f "$N/micro.mk" micro
```
