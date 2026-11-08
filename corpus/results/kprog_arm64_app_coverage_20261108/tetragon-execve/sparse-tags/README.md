Private common ARM ghost-tag storage observations

The existing common CFG layout analysis has a private may-carry-tag domain prototype. Initial scalar cells outside the finite domain retain scalar tags; every possible tag-producing store/copy contributes a cell, and opaque domains retain full storage. The complete captured event_execve uses31potential tag cells within its480-byte raw native arena. Native raw memory accesses, payloads and operation bodies retain their expressions. The native access trace covers456bytes, giving24bytes of raw-hole scope.

| Complete captured P, Clang O2 | BPF instructions | Maximum FP displacement |
| --- | ---: | ---: |
| Production ordered tags | 38534 | 760 |
| Private packed finite tag domain,32storage bytes | 91299 | 928 |
| Private constant-index scalar-tag elision, original64storage bytes | 35548 | 736 |

Both private full-case compilers exit0. The packed prototype passes the existing6,885,971UBSan host scenes,9shared service cases and29+1micro/negative compiler cases; the constant-index follow-up also passes29+1existing compiler cases. Its compile-time constant choice preserves original ordered storage and addressing for every dynamic index. These are compiler storage observations; production remains the ordered5c7a source. The existing34ISA replay continues separately on its original packed source and privately pinned linker; terminal native/verifier/generation stages are collected when that cohort closes.

V owns the universal sparse-domain read/store/clear/copy contract. Derivation from the Python transfer/join/helper analysis and actual packed C/compiler representation retains its explicit producer interface. compiler-inputs.tar.gz contains exact before/candidate universal sources, original native request, both full C/B/disassemblies, all host/service/compiler streams and both existing micro output sets. Six shared generated C files received18candidate macro lines during the owning Make target; those exact inputs are retained, the shared files matchHEAD, and subsequent private invocations bind generated-C destinations into their own namespace. Runtime admission additions:0.
