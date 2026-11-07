# Native-only trusted service: full BCC set

The existing frozen eight-tool BCC runner is being exercised with REQUIRE_BOUND_PROOF=1 and legacy REQUIRE_PREBUILT_PROOF=1. The latter must not select an application-provided proof on this path. Every request uses the kernel-owned native capsule and a fresh trusted-service proof. This is functional startup evidence, not corpus timing or same-work acceptance.

## Map metadata and ELF symbols

The first replay exposed sibling-entry map aliases outside the pinned source program resource set. The frontend now projects aliases onto `original_map_ids`; kernel resource membership and shape checks remain unchanged. Actual `sys_exit.zero` requires a legal C alias with an asm label retaining its exact ELF symbol. Shared validation and collision-free aliases are used by the x86 worker.

`make -C kprog/libnativeloader trusted-service-check trusted-worker-check` passes nine metadata/compiled-ABI checks and four actual ELF compilation cases. These include the renamed actual BCC ELF symbol and direct value offsets 0 and 8. Compact logs: `map-binding-check.json`, `map-binding-check.log.gz`.

Raw timestamped run archives retain all startup failures and subsequent retries. Full coverage and failure-class tables follow after the remaining simulator failures are closed; no full eight-tool pass is claimed here.
