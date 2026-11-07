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
| 10:05:25 | 21 | 21 | 21 | 17 | 2 verifier rejects; 1 unlocalized native-load EINVAL; 1 activation refused during teardown |

Denominators are every observed request in that replay. Startup failures prevent completing the application inventory. The frozen runner starts capable, biosnoop, vfsstat, opensnoop, syscount, tcpconnect, tcplife and runqlat with its existing arguments. `coverage.csv` records every retained request, including incomplete archives. `python3 analyze.py` recreates both coverage files from the raw archives.

The 09:49 replay exposed a readiness defect: probe/transient program IDs looked stable while native loads awaited service proofs. The shim now reports in-flight outer loads and completed bound replacements; the existing runner waits while a load is active or no actual bound replacement has completed. JIT/unbound readiness and the program list remain unchanged. The later replays wait for real callbacks and expose verifier and native-load failures.

The 10:05 replay follows the private-stack byte-ladder fix: unaligned 64-bit accesses use volatile bytes, aligned 64-bit accesses retain typed words for pointer spills. The capable exit store formerly rejected at fp-36 is accepted. Remaining raw failures are opensnoop `tracepoint__syscalls__sys_exit_open` (EINVAL; retained diagnostic tail lacks the failing line), runqlat `sched_switch` (BPF stack write fp-672), and biosnoop `block_rq_issue` (unbounded scalar-minus-stack-pointer arithmetic at BPF pc256, native comparison at 0xd6). No extra assumptions, bounds, flags, fallback or program exclusions were added.

Reproduce: `make -C kprog/libnativeloader trusted-bcc-set-kvm`. It incrementally builds the canonical shim and uses the existing TV kernel/module with a 4-GiB guest on CPUs16-19. Fixed functional work is 10000 `/dev/null` open/write/close sequences, with BPF run-count snapshots before/after; it is not the frozen timing workload. Only the premature 09:49 run reached that work so far, so no same-work or timing acceptance follows.

## Diagnostic continuation and complete check

The 10:16:34 replay repeats the startup failures; all requests and logs remain in its archive and regenerated tables. Removing the 8192-byte tail limit exposed an embedded-NUL issue in the exception message: `what()` consumers stopped after the first segment. Failure logging now converts NUL separators to newlines so all captured segments survive. Another identical full-set diagnostic replay is running; no safety or compiler policy changed.

The canonical whole `make -C kprog/formal check` ran 10:12:52–10:19:07 UTC and exited 2 at the existing CMOV route host cross-check (30192 mismatches) with the shared in-progress SP/CMOV changes present. The two updated volatile-byte source linkage checks, Lean build and earlier reference/compiler checks completed before that failure. This is **not** a successful whole formal check. `formal-check.json` and the compressed complete log retain the invocation/result; its HEAD field is the start commit, not a claim that foreign uncommitted files matched it. F has the exact failure notice; those changes remain untouched.

The completed 10:21:03 replay accepted 17 of 21 observed requests: two explicit verifier rejections (runqlat stack limit and biosnoop scalar-minus-stack-pointer), one unlocalized opensnoop native-load EINVAL, and one teardown activation refusal. Its opensnoop log now retains 225103 bytes / 4517 nonblank lines. It reports 4502 processed instructions, 127 states and reaches EXIT, with no explicit instruction-rejection line. Therefore EINVAL alone is **not classified as verifier rejection**; the tables now distinguish it from the two demonstrated verifier errors. The next replay adds only an unmatched-relocation diagnostic to the kernel binding checker, preserving its rejection.

The diagnostic-only module now logs the exact unmatched relocation chunk/record/kind/offset/target/source ID before its existing EINVAL return. Canonical incremental `make -C kprog/tv module-check ARCH=x86 KDIR=/workspaces/repository/kprog/tv/build-kernel-x86` passed; no kernel or image rebuild. `module-diagnostic-build.json` pins the source/module/kernel hashes and compressed logs retain both the initial quoting build failure and corrected build. Actual same-eight-tool replay is pending; this is not a runtime or safety acceptance claim.

The completed 10:30:48 diagnostic replay accepted 17 of 19 observed requests. The exact new module hash matches the incremental build receipt. Opensnoop still returns native-load EINVAL, and no unmatched-relocation diagnostic appears in its captured kernel log or guest output. That diagnostic has therefore not located the failure; the load stage remains unlocalized. Biosnoop still reports scalar-minus-stack-pointer arithmetic. All requests remain in run-20261107T103048813742Z.tar.gz and the regenerated tables. No C guest remains running.

The 10:37:10 replay with rejection-stage diagnostics accepted 16 of 17 observed requests before biosnoop failed at the same scalar-minus-stack-pointer operation. Opensnoop exit and runqlat switch were not reached; their absent errors are not passes. The run archive retains every request. Stage diagnostics only add rejection messages in validate_program/validate_proof and native-emission binding failures; acceptance and rejection rules remain unchanged. Incremental module build passes.

## Native return-dispatch precision

The generator previously put every call fallthrough, including modeled helper calls, in the native RET dispatcher. The existing ABI analysis already follows actual saved `ReturnAddress` provenance and rejects overwritten return slots. It now optionally exposes its collected non-entry return destinations; the RET switch consumes that same union. No new acceptance condition, bound, branch assertion, native instruction omission or ABI assumption is added.

Fresh generation of the exact archived runqlat `sched_switch` payload (SHA256995e718c...) produces one return site, 0x11, matching its native call. Executable BPF instruction decoding shows the deepest direct R10 memory displacement changing from -672 to -104 and the instruction count from1143 to472. These are compiler/layout observations, not verifier acceptance. `return-site-frame-artifacts.tar.gz` retains both BPF objects and fresh worker inputs/outputs. The first text-regex metric missed hexadecimal offsets; `return-site-frame.json` corrects it using signed offsets decoded from BPF instructions, and retains that limitation explicitly.

The existing `make -C kprog/x86 micro-proofs-build` passes all30 rows. Existing `check_x86_flag_definedness.py` reports132 ABI/condition/undefined-result cases, CL/parity BPF compiles and19 rendered host/BPF programs plus5 invalid controls passing. Complete logs are compressed here. The same full eight-tool guest and one globally serialized whole formal check are running; neither is claimed successful yet.

The 10:46:37 full-set replay confirms runqlat `sched_switch` **accepted and bound** (request17). Its proof executable sections are byte-identical to the -104 frame candidate. The baseline and runtime whole ELFs differ (995e718c... versus03de8f33...); their defined function bytes, allocated data and allocated relocations compare equal. `return-site-frame.json` records every identity and differing section. All three observed runqlat entries pass. Overall18/21 observed requests pass: opensnoop exit native-load EINVAL remains unlocalized, biosnoop scalar-minus-stack-pointer remains, and vfsstat open is canceled during teardown. The next coverage replay collects all eight tools' startup outcomes before stopping, using the existing frozen spawn/readiness methods; official timing runner behavior is unchanged.

The complete canonical `make -C kprog/formal check` exits0 at10:54:03 UTC after the return-site change and F production integration. Its complete log and start-HEAD/live-tree scope are recorded in `formal-return-sites-check.*`; the earlier CMOV failure remains retained. This pass is not a full native fidelity or O4 certificate.

Core load-stage logging now distinguishes a native-proof verifier failure from runtime-selection failure. The canonical patch and existing idempotence/conflict test preserve production all-or-nothing application. The test normalizes its temporary fixture from kernel HEAD's preceding patch version; forced reverse avoids GNU patch --batch auto-applying an unapplied fragment. Incremental TV x86 kernel/module builds and the patch regression pass; the next complete-startup inventory is pending. No kernel/image/private cache rebuild from scratch.
