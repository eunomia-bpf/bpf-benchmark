# Native array lookup cleanup

The array lookup lowering runs at LLVM optimizer-last. Run the standard SROA, instruction-combining and CFG simplification passes after it, so native P can simplify the new key loads, pointer arithmetic and branches before submission. This changes only the native producer; the original eBPF source, frozen benchmark, simulator, kernel and 38 safety inputs retain their bytes. No admission predicate, bound, gate or validation was added.

The paired balancer component uses identical source, inlining, allocator9 and kernel-layout macros. Both lower14array sites. Control emits9978executable bytes; cleanup emits9758, a220byte reduction. Both native stack frames remain216bytes. Raw objects, complete commands, plugin and diagnostics are in component-raw.tar.gz. Complete4object paired payload and actual timing follow; byte reduction alone is not a speedup or verifier-acceptance result.
