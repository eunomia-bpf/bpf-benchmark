# Retained census body 104

2026-11-15. The running retained census adds body 104, Tracee
`trace_mmap_alert`, source program 555, request 50. Stock verification rejects
`*(u32 *)(r10 -1080) = r2` after 759 processed instructions and 38 total states.
No native program was installed by that request. The complete failure archive
and actual compiler command stream are retained and SHA-bound in receipt.json.

The recorded final compiler command directly compiles joined `.bpf.i` to BPF.
It does not run today's bounds/canonical-context/strict-identity/MIR path.
This is an old worker outcome; completion time does not establish a current
compiler failure. It joins the normal-pipeline replay work after the leading
linker fixes.

The journal now has 50 resumed rows. Relative to census-0430, the cumulative
record becomes 100 attempts across 95 bodies: 48 installed, 41 stock rejects,
five compile failures and one loader/linker invocation mismatch. This remains
submitted-native, load-only evidence from retained producer objects, without
execution, equal-work or application-performance claims.
