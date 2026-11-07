# Native-only trusted service: full BCC set

The existing frozen eight-tool BCC runner is being exercised with REQUIRE_BOUND_PROOF=1 and legacy REQUIRE_PREBUILT_PROOF=1. The latter must not select an application-provided proof on this path. Every request uses the kernel-owned native capsule and a fresh trusted-service proof. This is functional startup evidence, not corpus timing or same-work acceptance.

## Map metadata and ELF symbols

The first replay exposed sibling-entry map aliases outside the pinned source program resource set. The frontend now projects aliases onto `original_map_ids`; kernel resource membership and shape checks remain unchanged. Actual `sys_exit.zero` requires a legal C alias with an asm label retaining its exact ELF symbol. Shared validation and collision-free aliases are used by the x86 worker.

`make -C kprog/libnativeloader trusted-service-check trusted-worker-check` passes nine metadata/compiled-ABI checks and four actual ELF compilation cases. These include the renamed actual BCC ELF symbol and direct value offsets 0 and 8. Compact logs: `map-binding-check.json`, `map-binding-check.log.gz`.

Raw timestamped run archives retain all startup failures and subsequent retries. Full coverage and failure-class tables follow after the remaining simulator failures are closed; no full eight-tool pass is claimed here.

## Full-set checkpoints

| Run UTC | Requests observed | Proof C generated | BPF compiled | Accepted | Remaining outcomes |
|---|---:|---:|---:|---:|---|
| 09:30:56 | 5 | 1 | 1 | 1 | 3 map queries fail; 1 archive interrupted during teardown |
| 09:49:36 | 3 | 3 | 3 | 3 | Premature readiness; not full-set success despite outer `ok=true` |
| 09:56:02 | 12 | 11 | 11 | 10 | 1 misaligned stack store; 1 teardown failure |
| 10:05:25 | 21 | 21 | 21 | 17 | 3 verifier rejects; 1 activation refused during teardown |

Denominators are every observed request in that replay. Startup failures prevent completing the application inventory. The frozen runner starts capable, biosnoop, vfsstat, opensnoop, syscount, tcpconnect, tcplife and runqlat with its existing arguments. `coverage.csv` records every retained request, including incomplete archives. `python3 analyze.py` recreates both coverage files from the raw archives.

The 09:49 replay exposed a readiness defect: probe/transient program IDs looked stable while native loads awaited service proofs. The shim now reports in-flight outer loads and completed bound replacements; the existing runner waits while a load is active or no actual bound replacement has completed. JIT/unbound readiness and the program list remain unchanged. The later replays wait for real callbacks and expose verifier failures.

The 10:05 replay follows the private-stack byte-ladder fix: unaligned 64-bit accesses use volatile bytes, aligned 64-bit accesses retain typed words for pointer spills. The capable exit store formerly rejected at fp-36 is accepted. Remaining raw failures are opensnoop `tracepoint__syscalls__sys_exit_open` (EINVAL; retained diagnostic tail lacks the failing line), runqlat `sched_switch` (BPF stack write fp-672), and biosnoop `block_rq_issue` (unbounded scalar-minus-stack-pointer arithmetic at BPF pc256, native comparison at 0xd6). No extra assumptions, bounds, flags, fallback or program exclusions were added.

Reproduce: `make -C kprog/libnativeloader trusted-bcc-set-kvm`. It incrementally builds the canonical shim and uses the existing TV kernel/module with a 4-GiB guest on CPUs16-19. Fixed functional work is 10000 `/dev/null` open/write/close sequences, with BPF run-count snapshots before/after; it is not the frozen timing workload. Only the premature 09:49 run reached that work so far, so no same-work or timing acceptance follows.

## Diagnostic continuation and complete check

The 10:16:34 replay repeats the startup failures; all requests and logs remain in its archive and regenerated tables. Removing the 8192-byte tail limit exposed an embedded-NUL issue in the exception message: `what()` consumers stopped after the first segment. Failure logging now converts NUL separators to newlines so all captured segments survive. Another identical full-set diagnostic replay is running; no safety or compiler policy changed.

The canonical whole `make -C kprog/formal check` ran 10:12:52–10:19:07 UTC and exited 2 at the existing CMOV route host cross-check (30192 mismatches) with the shared in-progress SP/CMOV changes present. The two updated volatile-byte source linkage checks, Lean build and earlier reference/compiler checks completed before that failure. This is **not** a successful whole formal check. `formal-check.json` and the compressed complete log retain the invocation/result; its HEAD field is the start commit, not a claim that foreign uncommitted files matched it. F has the exact failure notice; those changes remain untouched.
