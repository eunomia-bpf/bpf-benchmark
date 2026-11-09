Linked cohort: eight completed static requests

Source model 4f5b7ae6db02414f6ad69648677fc22ec8bf6795. Snapshot 2026-11-09T14:34:13.618308+00:00. This partial observation covers8/275 requests;267 requests remain in the running batch. The original549-instance census remains the complete initial table.

| Cause | Programs | Generated | Compiled | Verifier rejected |
| --- | ---: | ---: | ---: | ---: |
| verifier_stack_access | 3 | 3 | 3 | 3 |
| verifier_scalar_memory_access | 3 | 3 | 3 | 3 |
| compiler_stack_storage | 2 | 2 | 0 | 0 |

The three verifier stack observations access R10 at-1024 twice and-520 once. The two compiler observations reach the existing4096-byte compiler stack diagnostic in the same generic_kprobe_process_event entry. The native source has a504-byte modeled stack and63 forwarding cells declared across its complete extent. These observations identify physical B storage as an investigation target; the remaining267 outcomes determine the final ranking.

The three scalar-memory observations reach the existing callee-return fault arm. Full diagnostics and original eight request archives accompany this snapshot. Native execution requests:0. Compiler and verifier stages retain their separate counts. The active guest retains its captured source and runtime.
