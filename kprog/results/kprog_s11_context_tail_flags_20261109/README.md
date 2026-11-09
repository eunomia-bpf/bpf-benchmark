# Context layouts, tail frames and verifier flags

S11, 2026-11-09. Context generation, actual x86 tail frames and stock rewrite
flags are implemented through the existing trusted service and same-copy JIT
relocation path. The stock verifier checks B. Universal B/P correspondence
remains the shared proof contract.

Context dispatch (901194c0c) retains 3 typed handlers and 12 identity-layout RAW
types. The other 17 context families report a typed generation-handler
requirement. `context-layouts.json` records all 32 kernel context declarations
and converter tables for x86-64 and ARM64. The 32-type test also checks both
specializer call sites.

Flag retention (b1be661ee) visits seen B instructions before restore. It retains
route-destination use, prandom initialization, kprobe override, tail-call cb and
packet extent, and the stock context converter's effects. Narrow loads receive
the stock normalization in the temporary callback input. The executable helper/
callback regression, complete patch application/reapplication/conflict test,
private kernel and paired module build all pass. The final physical ARM kernel
flag integration follows the same shared C patch through the kernel owner.

The x86 tail linker emits two frame relocations: counter displacement
`-16 - round_up(stack_depth,8)` and the matching successful-transfer stack pop.
The kernel emitter uses depth zero with the actual JIT private stack, matching
the stock JIT. The native cleanup and callee-save pops retain their order.
The fixed text adds one seven-byte ADD on successful transfer and two 16-byte
relocation records per lowered tail site.

The Rust producer tests pass 91 cases. Actual emitted code passes 195 userspace
frame executions across 13 stack depths and the populated/empty/index routes;
relocation tests cover all 513 depths from 0 through 512 and both RBP forms.
The real tc test uses an allocated native stack and measures a JIT stack of
24 bytes. Stock and native each return 2 after 34 invocations,
which is 33 tail transfers. The C-produced test's original RET/RBX verifier
diagnostic is retained alongside the caller-register-only assembly test.
S7 owns the general saved-register precision interface exposed by that input.

Final micro compilation: x86 30/30 and ARM64 30/30 (29 positive objects and the
unchecked-read object on each ISA). The captured-source repeat preserves the
initial two x86 Clang SIGBUS diagnostics. Service component tests pass 9/9.
The guest runtime uses one 2 GiB guest at a time and CPU set 8-23. ARM's initial
transport records retain the historical static-library activation diagnosis;
its successor uses the paired loader. Its remaining B compilation uses the
existing host compiler protocol in the private guest namespace.

Safety suites complete: x86 42 cases, {'valid_executed': 8, 'positive_infrastructure_error': 1, 'verifier_rejected': 30, 'specialization_rejected': 1, 'accepted_finding': 2}; ARM64
38 cases, {'valid_executed': 4, 'verifier_rejected': 25, 'specialization_rejected': 2, 'accepted_finding': 7}. Every negative case stays load-only.
`summary.json` names each finding and preserves the actual outcomes. S7/S10/C own the named
model, stack/ABI and context-spill findings. The current tail-frame and flag
results retain those suite findings as separate evidence. Shared model owners
continue their stack/ABI edits during the suite; every service request records
its actual source identities. The archive preserves the frozen micro source
snapshot and the observed service/compiler/runtime transitions.

The SIMD and branch-hardening proposal, benign emitted-code fixtures, storage/
text costs and engineering estimates are published in `proposals.md`.
V/S13 own the universal source/compiler/physical entry and successful transfer
composition. The coordinator decides reuse of the existing exit predicate at
the successful tail-helper boundary and selects SIMD and branch integration.
The benchmark workload and paper sources retain their frozen ownership.

`raw.tar.gz` contains the commands, source identities, compiler results, host
results, guest service archives and initial diagnostics. `raw-manifest.json`
records each exported file's size and SHA256. Large private outputs retire after
publication and independent archive readback.
