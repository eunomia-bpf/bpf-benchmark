# Private compact-payload worker: native-only safety replay

This replay reuses the existing ARM safety harness's four safe controls and thirty unsafe native inputs, the same static bound-probe and mutable HASH negative context. Every native ELF SHA matches the original suite. Own manifests only relocate their filesystem paths; inputs.tar.gz preserves all 34 ELFs, the probe, context objects, manifests and hashes. Unsafe cases remain load-only; only the named safe controls execute.

The first no-stack return-2 control has completed on the real full-system QEMU kernel-backed service: the kernel and bound native execution both return result 0/retval 2, with one nonzero generation and service status 0. control.json and control.success.tar.gz retain the raw receipt, source pins, generated proof, compiled BPF, loader output and candidate-layout report. This control has no ghost stack slots, so it establishes the candidate bootstrap/compiler/binding path rather than stack-compaction correctness. The stack-spill control and all negative outcomes remain pending at this checkpoint.

Run through the existing result Makefile:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-payload-negative-run
```

The replay uses a separate 2 GiB, two-vCPU QEMU guest on host CPUs 20-23 and the retained runtime read-only. It reuses the matched kernel/module/loader without rebuilding them. The current Katran production run and its queued candidate replay are preserved. The private candidate remains unpromoted; this is not application coverage or performance evidence.
