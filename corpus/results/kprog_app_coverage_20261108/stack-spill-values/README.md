# Native stack pointer spill representation candidate

The captured complete Cilium `tail_ipv4_policy` body spills an architectural stack pointer as a numeric native address. Reloading that value currently loses the verifier-shaped stack address before helper9. This private candidate keeps the original native bytes and a separate pointer representative. Ordinary loads/stores still execute; overlapping writes and opaque calls discard the affected ghost facts. Readonly helper1 and helper9 retain facts in the allocated caller frame and discard facts below the current SP. No runtime admission check or per-program proof was added. Production sources retain their committed implementation.

| Measurement | Result |
| --- | --- |
| Native CPU pointer-byte and partial-store comparison, ASan and UBSan | 52,992 observations, 0 differences |
| Deallocated-frame helper lifetime comparison, ASan and UBSan | 552 observations, 0 differences |
| Existing native positive controls through stock verifier and native execution | 9/9 |
| Existing native negative controls | 27 stock-verifier rejections, 2 generation rejections, 0 accepted loads |
| Captured complete Cilium body | compiled, 10,475 BPF instructions, maximum FP offset736 |

The 736-byte frame still exceeds the existing stock-verifier 512-byte stack extent. This candidate therefore has not been adopted or submitted as an application success. The next private variant keeps ghost offsets before the existing architectural address opacity barriers so the compiler can remove unused metadata cells; the original raw memory address path remains intact.

```sh
N=/workspaces/.agent-state/kprog-lanes/C/design-only/stack-spill-values
make -f "$N/Makefile" component host host-liveness
make -f "$N/safety/Makefile" replay
```

`named-candidate.tar.gz` preserves the named-header epoch, complete captured program, component object, commands and host sources/logs. The test source include paths resolve to the archived `source/` tree; the Makefile component output name is `captured.bpf.o`, whose captured bytes are retained as `named-captured.bpf.o`. `native-safety.tar.gz` retains all38 actual service outcomes, generated request archives and raw verifier/kernel logs. `outcomes.json` keeps each native input hash and actual terminal stage. These measured domains do not discharge the universal O2/O4 simulator/compiler obligations, which retain V ownership.
