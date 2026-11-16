# Byte-precise spill liveness

2026-11-16T02:02:34Z

The previous diagnostic incorrectly treated every partial store as a read of the entire old slot. Each store now defines exactly the bytes it writes. Loads use their actual bytes; upper bytes remain live when a later wide load observes them. Whole-slot interference still includes all simultaneously live parts and every store clobber, including dead stores. This changes the observation, not the B compiler or MIR.

Four focused regressions cover the false read, required upper-byte preservation, dead-store clobbers and upper bytes across a CFG join. On real OTel main, maximum live slots is50, maximum live bytes328, and there are still zero noninterfering whole-slot pairs. Code288400B/frame824B stay unchanged. No slot overlay or speculative coalescing is justified by these data. The lane's earlier no-pairs conclusion remains, with more precise reasoning.

Raw checks and actual retained-frontend replay: /workspaces/kprog-raw/perf/20261116-byte-spill-liveness. Explicit slot-byte offsets support sparse IDs and mixed slot sizes. No benchmark/image/base changes.
