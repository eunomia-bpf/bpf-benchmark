# Generic helper identity for pruned map calls

Cilium batch021801 reaches native resource binding after successful symbolic verification. A readonly map value prunes a map-lookup branch, whose native relocation names the kernel-generated internal hash lookup. The verifier marks the helper instruction as unreachable and its path-specific map-pointer state stays empty.

The generic binding callback now shares one map-operation resolver. Reachable calls retain their checked map-pointer state and poison handling. Unreachable helper calls resolve their static map-lookup/update operation against the proof program's retained kernel-owned maps. The resolver compares concrete operation pointers and actual map_gen_lookup call targets; allocation and generator failures retain their errors. Symbolic verification completes before this callback runs.

614400 source-extracted ASan/UBSan controls cover visited/pruned states, poison and empty pointer states, owned-map counts, helper IDs, direct/generated targets, signed call displacements, allocation failure and generator errors. The matching x86 native module builds successfully in the existing kernel namespace/cache. `component.tar.gz` captures source before/candidate/diff, exact extracted functions, controls, commands, outputs, module and image/BTF identities.

```sh
sh /workspaces/.agent-state/kprog-lanes/C/dead-map-helper-binding/check.sh
sh /workspaces/.agent-state/kprog-lanes/C/dead-map-helper-binding/build.sh
```

Whole-application Cilium and native-only runtime controls consume this module in fresh, separate guests after the current serial application queue. Their actual terminal results provide application acceptance.
