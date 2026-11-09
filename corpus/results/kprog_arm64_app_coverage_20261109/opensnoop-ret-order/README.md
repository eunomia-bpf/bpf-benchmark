Paired ARM opensnoop local event liveness trial

The authorized original C edit moves event.ret=ret to the first event-data assignment before helper calls. The event stays private until the existing perf-output helper; its fields, field sizes, helper calls, branches, bounds and return value retain the same definitions. The store order shortens scalar ret liveness across helpers. The paired JIT BPF/skeleton/upstream application and reordered native profiles share the exact edited C/header tree; original profiles retain the original C. Same-source edited C SHA42b2a91cf3d27bd12c630e888c82a3335aae965d22d9c868ff863624afc09d8b.

Native O3 and common fixed22-25 allocation variants measure both original and reordered source against the same private generic scalar-cell model. Actual results:
- original: compiled, B frame576.
- reordered: compiled, B frame520.
- original-fixed: compiled, B frame544.
- reordered-fixed: compiled, B frame520.

Paired JIT build exit:0. Exact sources, source patch, compiler commands, native/BPF objects, skeleton, application binary, model overrides and logs accompany raw.tar.gz. Full QEMU application/verifier evidence belongs to the captured whole-app cohort. Runtime admission additions:0.
