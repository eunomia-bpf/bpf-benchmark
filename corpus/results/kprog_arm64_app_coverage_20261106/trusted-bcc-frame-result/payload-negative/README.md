# Private compact-payload worker: native-only safety replay

This replay reuses the existing ARM safety harness's four safe controls and thirty unsafe native inputs, the same static bound-probe and mutable HASH negative context. Every native ELF SHA matches the original suite. Own manifests only relocate their filesystem paths; inputs.tar.gz preserves all 34 ELFs, the probe, context objects, manifests and hashes. Unsafe cases remain load-only; only the named safe controls execute.

The first no-stack return-2 control has completed on the real full-system QEMU kernel-backed service: the kernel and bound native execution both return result 0/retval 2, with one nonzero generation and service status 0. control.json and control.success.tar.gz retain the raw receipt, source pins, generated proof, compiled BPF, loader output and candidate-layout report. This control has no ghost stack slots, so it establishes the candidate bootstrap/compiler/binding path rather than stack-compaction correctness. The stack-spill control and all negative outcomes remain pending at this checkpoint.

Run through the existing result Makefile:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-payload-negative-run
```

The replay uses a separate 2 GiB, two-vCPU QEMU guest on host CPUs 20-23 and the retained runtime read-only. It reuses the matched kernel/module/loader without rebuilding them. The current Katran production run and its queued candidate replay are preserved. The private candidate remains unpromoted; this is not application coverage or performance evidence.


All four existing safe controls have now completed: return-2, direct SP copy/restore, a scalar load through a stack alias, and SP restoration through a spilled stack pointer. Each kernel and bound native execution returns result 0/retval 2 with one nonzero generation. The spill/restore proof has a 32-byte native stack and the single ghost offset `-32`, exercising the compact representation on the real kernel path. Candidate input hashes remain unchanged. `safe-controls.json` and `safe-controls.tar.gz` retain all four complete requests, layouts, generated/compiled artifacts and raw probe output. The thirty unsafe outcomes and actual Katran application replay are still pending; these four controls do not establish either result.

## Partial safety checkpoint

The current immutable snapshot contains 19 of 34 completed cases: 4 safe executions, 8 verifier rejections, 6 specialization rejections and 1 loader rejection. The loader refusal is the unbounded-loop input whose proof has no BPF exit. No completed unsafe input was accepted or executed. The guest and the remaining 15 cases are still running; zero accepted among this prefix is not a full-suite result.

`outcomes.json` retains every completed outcome, original native SHA, service receipt, rejection stage and pending case name. `completed-requests.tar.gz` contains exactly those closed success/failure request archives, with their raw generated C/BPF, compiler/load logs, kernel metadata and per-request source identities; each embedded kernel native ELF was checked against its original case SHA before publication. It contains no active request directory. The four safe controls have unchanged candidate-layout hashes and matching kernel/native retval 2.

This replay retains its original native-link executable. The independently published return-target repair `e18af21bb` and lane F's fresh replay are separate evidence; the current partial snapshot makes no claim about the pending return-target cases. Katran baseline and candidate application runs remain pending, and the compact worker remains unpromoted.


## Closed old-linker replay: accepted return-target finding

The guest stopped after 30 of 34 cases when `return_register_overwrite` (`mov x30, #0; mov w0, #2; ret`) was accepted for loading as bound program 265 with one nonzero generation. The unsafe native program was never executed. Completed outcomes are 4 safe executions, 14 verifier rejections, 10 specialization rejections, 1 loader rejection and 1 accepted unsafe finding. The harness stopped at the finding; `stack_base_flags`, `undefined_entry_register`, `undefined_entry_flags` and `helper_clobbered_register` did not run. This is a failed safety replay, not a 34-case pass or a zero-accepted result.

`trusted-arm64-service-result/summary.json` and `run-20261107T114812325090Z.tar.gz` preserve the complete closed guest, including all 30 request archives, exact native inputs, generated C/BPF, source pins, loader/compiler/verifier logs and outcomes. Archive SHA256 is `2dd1fe8c82866e841448035b242f306a0b2f84b9a433954a0442f76f7071af5d`. Every completed request's kernel-owned native ELF was rehashed against its original case; every available specializer input is byte-identical. All monitored inputs stayed unchanged; guest exit was 1 and QEMU exit was 0. The earlier 19-case checkpoint remains a historical prefix, superseded by this closed result.

This run uses native-link SHA256 `7d55f12233643c26968509e5c701743900ee1f1b5022178e69037f4a1cf9ab74`, before the published return-target repair `e18af21bb`. Lane F's corrected-linker 34-case replay is independent evidence. The existing A continuation waits for the current Katran candidate driver, then incrementally rebuilds native-link and the paired ARM ABI binaries and repeats these same 34 native inputs with the private compact worker. That replay remains pending; no candidate promotion or complete safety claim follows from the old-linker result.


## Closed corrected-linker compact replay

The retained continuation completed all 34 original native inputs after the incremental return-target repair rebuild. All four positive controls execute with matching kernel/native retval2 and nonzero bound generations; 16 unsafe cases are verifier-rejected, 13 are specialization-rejected, and one is loader-rejected. Accepted unsafe and unsafe executions are both zero. Guest and QEMU exits are zero, and the monitored host inputs and per-control candidate layouts are unchanged.

The current full archive is `trusted-arm64-service-result/run-20261107T134202577970Z.tar.gz` (SHA256 `bfa4ba2d4250ad34e88ec4bb3a1d3d3ddbac4b3ece82f501b054472bd6a38988`); its summary and `corrected-linker-audit.json` identify all 34 request archives and verify every original/kernel-captured/generated native identity. `outcomes.json` now holds the complete corrected replay; the old partial checkpoints and accepted finding remain historical evidence above and in their original archives.

This is the frozen private compact worker, whose header predates the production XDP context-identity repair. It validates these 34 cases and the corrected return target; it does not validate current context projection, promote the compact worker or close application acceptance. The distinct current-context+compact Katran compiler failure remains documented in ../context-composition/README.md.
