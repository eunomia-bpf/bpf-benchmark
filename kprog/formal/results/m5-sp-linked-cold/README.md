# Actual linked cold STACK reader

`Arm64ProgramEntryColdRead.setup_read_cold` feeds the real post-setup SP=-32 readback into the actual linked reader. `cold_cache_reads` proves that both STACK and RETURN caches remain at base 0 / valid 0 through the SP/NZCV writes, using the reached initializer's typed bindings, local-load frame and retained header pointers. No warm-cache premise substitutes for that cold state.

The shared STACK proof now takes only the used header layouts (SP 40, cache-valid 48, cache-base 16), the actual input block and its complete external-function binding. The actual world supplies input 59; the existing original reader body at 66 is checked in the public queries. The former standalone APIs remain instances at input 64. An unused private wrapper is removed; execution proofs are shared, with no second ISA or C body.

The reader executes 35 internal transitions to materialization and 22 to the external request `[1]`. Its actual provider outcome retains the exact trace, returned base and supplied memory. The 28-transition suffix derives the Mint64 base store and Mint8 valid store from writable borrowed storage, returns the pre-provider SP offset plus base, and establishes the warm cache, access map and frontier. The provider may change memory and cache addresses; no purity or successful-store premise is introduced.

Post-provider borrowed storage and native-origin/ABI admission remain explicit. Complete native register/caller preservation through those stores and the real first MOV_IMM callsite remain the next composition step. This reader result does not close a native instruction family or discharge unrestricted mark/priority, all-outcome or final-return obligations.

Shared 143 jobs, linked 219 jobs and 15 public type/axiom queries pass at the original proof limits on CPU17, one worker and 32 GiB address space. Imported execution axioms are listed in validation.json. Raw logs retain the closed-index normalization retries; explicitly rewriting the reader frontier and using the original typed field mapping avoids a larger proof cap. Whole KProgFormal proof-library/root confirmation passes 271 jobs on CPUs 16–23, nice 19, one worker and 32 GiB address space. Executable/tool native builds are excluded.

M5/M6 and O1/O2/O4 recount remain open; completed ISA-family count is 0.
