AArch64 stack representation after the coordinator audit

The coordinator decision of 2026-11-09 21:50 closes the observation-kernel and region-split experiments and restores the original stack representation. This source step reverses the ARM scalar-forwarding additions from 729856581 and e2e6dc6c0. Stack data, pointer payloads and packed tags use their original volatile storage. The current implicit SP release, architectural fault predicates, effective-address recovery and context-load operations retain their definitions.

Six existing host fixtures drop their forwarding-cache declarations and resets; their semantic assertions remain intact. Python source compilation passes and the generated direct dispatcher is byte-identical. The matched existing host stage and the QEMU replay have separate receipts. The replay follows the shared reverts and compares each row with the best November 8 outcomes.

Earlier compiler and capacity experiments retain their published raw receipts. Native executions in this source step: 0.

The existing eight host groups cover stack reads, byte writes, provenance, arena boundaries, pair loads, implicit SP writeback and helper pointer selection. GCC passes all eight under UBSan. Clang passes five under UBSan; the three child-fault boundary oracles pass with their original Makefile compiler flags. Their added halt-on-error instrumentation exits the child before the oracle observes its expected signal, and those complete instrumented diagnostics accompany the original-flag passes. All 16 instrumented builds succeed. Every original semantic assertion stays current.

The November 8 reference catalog retains 203 observations from 36 coverage files, with native identities and artifact hashes. Highest observed stages by application/entry name: BCC23 installed; Katran1 installed; OTel2 installed/1 rejected; Tetragon4 installed/2 rejected; Tracee2 installed/1 rejected. Cilium has zero request rows in those files. These are a historical comparison catalog assembled across source epochs; the coordinated current replay supplies the next actual cohort.
