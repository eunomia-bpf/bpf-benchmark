2026-11-16T07:23:13Z

Actual retained OTel perf_unwind_native MIR fails LLVM MachineVerifier at three frame-address calculations in both its original packed MIR and the scalar-width candidate. BPF PEI expands unused dead MOV_rr frame-index definitions into a dead-marked MOV followed by an ADD that reads it. The standard LLVM dead-machine-instruction pass leaves those operations in place. This predates scalar narrowing.

The normal B storage pass now removes only unused pure frame-address definitions (MOV_rr frame index and FI_ri), using local physical-register effects and successor live-ins. Locally read, helper-argument and successor-live values remain. Existing block parsing and register-effect logic are shared with the packer; no I, P, native flags or LTO settings change. No verifier check was removed or downgraded.

The backend subset passes13 cases, including dead/live address counterexamples. The real-kernel matrix passes12720 value executions with0failures; the original544B frame still rejects. Actual OTel now passes MachineVerifier after three unused definitions are removed. Its direct B stack extent remains704B, so this does not close its existing stock stack rejection. No app acceptance or speed claim.

The MIR replay utility accepts a retained member stem and source/context inputs so the same regression can replay BCC or OTel. Defaults stay the BCC request. Failed original, narrowed and dead-machine-elimination diagnostics remain at /workspaces/kprog-raw/perf/20261116-otel-scalar-width; successful final host/kernel evidence stays at /workspaces/kprog-raw/perf/20261116-dead-frame-address. All subset jobs are terminal, CPU16 released, and original guests/pinned recovery/image d9e stay intact.
