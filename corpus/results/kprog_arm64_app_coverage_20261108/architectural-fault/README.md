# ARM architectural fault operation bodies

Operator approval: 2026-11-08 09:36 UTC, four classes. The canonical C simulator models incoming SP alignment, pair-load destination overlap, integer transfer/writeback overlap and exclusive status overlap. Each uses the existing verifier-visible fault arm in generated B and applies to every native program.

The five-step QEMU replay uses the paired e2d3 runtime and all 34 existing native-only cases. Four positive cases execute. The other cases use the existing load-only path. Full-system QEMU operation-body replays and the executable Lean reference supply ISA-level evidence.

Rules follow the [Arm A64 instruction manual](https://documentation-service.arm.com/static/67e40f3398aa3c3b6eea6a85): CheckSPAlignment tests incoming SP before address offset/writeback; LDP constrains equal destination fields; LDR/STR and LDP/STP constrain writeback/data overlap for base fields 0..30; STXR/STLXR constrain status/data equality and status/base equality for base fields 0..30. The overlap classes have CONSTRAINED UNPREDICTABLE outcomes; the simulator routes their architecturally partial state to its fault arm. QEMU outcomes are recorded with that distinction.

Lean reference: `spAlignmentFault` at `kprog/formal/KProgFormal/Reference/AArch64.lean:526`, the addressed-memory and pair source witnesses, and the corresponding decode constraints around lines980?1038. V maintains the affected universal O1/O2 rows.

Existing29 micro programs generated and compiled with clang18/O2/BPFv4. The source dispatcher and generated direct dispatcher carry the same operation bodies. Application/compiler defaults retain their current profile.

## Closed outcomes

The complete34-case five-step run records4 matching valid executions,28 stock-verifier rejections and2 generation failures (unbounded indirect target and unsupported instruction). All8 earlier load-only architecture findings now reach stock-verifier rejection. The native risk-case execution count stays0. The source dispatcher/direct dispatcher were published in500abe542.

Full-system Linux QEMU operation replay:255 memory forms ?128 states =32640;8 exclusive forms ?128 =1024. CPU/C and CPU/Lean comparisons each have0 differences across these33664 states. The exclusive observer clears its monitor before each recorded instruction and the reference receives that explicit environment.

The143 targeted operation states contain17 defined states,109 SP-alignment states and17 overlap states. C and Lean agree across all143: defined results match; SP reaches the reference fault; overlap reaches its constrained-input decode classification and the C fault arm. The17 defined CPU outcomes match Lean. QEMU executes the17 constrained-overlap forms with its chosen outcomes.

QEMU8.2.2 executes the109 SP-alignment states with continued instruction execution. A second full-system bare-metal EL1 replay sets SCTLR_EL1=0x00c50838 (SA=1), runs all143 forms and records143 zero ESR values. Its [gen_check_sp_alignment implementation](https://github.com/qemu/qemu/blob/v8.2.2/target/arm/tcg/translate-a64.c#L1331-L1342) explains this performance-oriented emulation behavior. The Arm manual and Lean provide the architecture-fault comparison; QEMU provides an explicit measured emulator difference.

The broader101-form control replay records12928 states: CPU/Lean agrees throughout; C agrees on95 forms, with768 state differences across6 existing CODE/return-address forms. Those6 preserve the previously recorded logical-code-coordinate versus real-address O4 frontier. The current architectural-fault bodies have the33664 memory/exclusive comparisons and143 targeted comparisons above.

Manual locators (PDF page / printed page): CheckSPAlignment5477/5474; LDP507/504 and operation508/505; STP911/908; STLXR901/898; STXR985/982. Full manual URL/hash and the paired runtime/source identities are inoutcomes.json and the raw safety/operation archives.

Reproduction: operation-inputs.tar.gz contains source snapshots, native observers, build commands, ELF inputs and QEMU drivers. The safety-inputs.tar.gz and safety/trusted-arm64-service-result archive retain the original34 submission records. operation-body/trusted-arm64-service-result retains the first full-system observation, including the initial oracle-storage diagnostic; fault-body/trusted-arm64-service-result retains the corrected512-byte oracle replay. reference-outcomes.tar.gz carries every comparison log and mismatch stream; fault-reference.json.gz carries all143 canonical requests/responses. Oracle storage/profile changes belong to the observer. Canonical application defaults retain their current profile.
