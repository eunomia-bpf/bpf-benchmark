# Private architectural flag-storage measurement

This component measurement keeps the original native inputs and generated instruction semantics, changes the six flat architectural flag locals into volatile byte cells, and compiles the same captured Cilium/Tetragon source with the same current header epoch and compiler flags. The canonical scalar-flag representation remains selected. The complete-state host observations total7347785 under UBSan and produce0differences.

| Captured source | Same-epoch scalar flags: maximum direct frame offset | Volatile flag bytes: maximum direct frame offset | Scalar / volatile direct accesses beyond512 |
| --- | ---: | ---: | ---: |
| Cilium tail_handle_ipv4_cont | 616 | 768 | 184 / 713 |
| Tetragon event_execve | 1280 | 1280 | 559 / 798 |

The snapshots from the earlier runtime cohorts separately measure608/1280bytes, with184/529direct accesses beyond512. Those objects retain their older header epochs. Fresh scalar baselines above isolate the six flag declarations from the current MOVX representation and include identity. The captured stock-verifier failures remain first observed accesses at544(Cilium) and944(Tetragon); disassembly maxima cover their whole compiled objects and have a different measurement domain.

The initial frame parser handled decimal disassembly and recorded0when LLVM printed hexadecimal offsets. Its receipt remains as `frame-observations.initial-parser.json`. The corrected parser reads both representations; all published frame values above come from `frame-observations.json` and the retained actual objects. These are compiler measurements. Complete-application acceptance remains in the original cohort logs.

```sh
N=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/flag-storage
make -f "$N/Makefile" host
make -f "$N/Makefile" cilium
make -f "$N/Makefile" tetragon
make -f "$N/Makefile" cilium-baseline
make -f "$N/Makefile" tetragon-baseline
python3 "$N/measure.py"
```

`component.tar.gz` preserves both headers, the exact sources and original/current scalar/volatile BPF objects, compiler commands/logs, existing flag-route oracle snapshots/outcomes, and the parser receipts. Additional runtime admission predicates total0. The resulting frame measurements direct the next model work to actual context representation: current x86 SKB entry allocates a216-byte proxy, while Cilium's native code reads the real skb len/data_len fields at112/116. The current private live-kernel-context port follows the existing AArch64 representation and compiles this Cilium source with direct frame416.
