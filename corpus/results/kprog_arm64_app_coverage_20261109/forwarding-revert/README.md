AArch64 stack representation after the coordinator audit

The coordinator decision of 2026-11-09 21:50 closes the observation-kernel and region-split experiments and restores the original stack representation. This source step reverses the ARM scalar-forwarding additions from 729856581 and e2e6dc6c0. Stack data, pointer payloads and packed tags use their original volatile storage. The current implicit SP release, architectural fault predicates, effective-address recovery and context-load operations retain their definitions.

Six existing host fixtures drop their forwarding-cache declarations and resets; their semantic assertions remain intact. Python source compilation passes and the generated direct dispatcher is byte-identical. The matched existing host stage and the QEMU replay have separate receipts. The replay follows the shared reverts and compares each row with the best November 8 outcomes.

Earlier compiler and capacity experiments retain their published raw receipts. Native executions in this source step: 0.
