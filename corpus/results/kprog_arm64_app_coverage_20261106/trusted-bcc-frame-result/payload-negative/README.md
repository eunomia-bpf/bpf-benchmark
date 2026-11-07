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
