# Current x86 negative replay with a matched binding tuple

All17 cases reach a terminal result:9 verifier rejections,6 specialization
rejections,1 loader rejection and1 accepted stack-base-flags finding.
All11 original negatives reject. No unsafe native program is executed.
`outcomes.json` retains every assembly input, command, stage and exact message.
The accepted case records a nonzero generation and remains a safety bug.

The first attempt against the mutable shared module used the older12:08 static
F probe and failed binding with `Invalid argument` for ten generated cases.
Those were infrastructure failures, not safety rejections; their original
reports/logs remain under `../x86-post-ldp/` and in `raw-evidence.tar.gz`.
The corrected replay copies T's matched `shared-btf-fixed/x86` kernel/module,
uses T's e43eca549 loader library with its current public header, and freezes
C's readonly-capable native linker. The final probe uses that owning copy of
the linker and companion. No shared image, module or kernel is replaced.

```sh
taskset -c 16-23 make -C kprog/fidelity negative-build NEGATIVE_BUILD=build-x86/negative-post-ldp
taskset -c 16-19 make -C kprog/results/kprog_fidelity_20261106/negative/x86-post-ldp-matched build run
```

The Make run exits nonzero for the preserved unsafe acceptance. Its guest has
2vCPUs and2GiB, uses KVM and stays on host CPUs16–19. This is a safety replay,
not timing. `first-matched-results.tar.gz` preserves the first successful
matched-tuple replay before moving the same linker/companion into the owning
build directory; the final outcomes have the same rejection/acceptance counts.
`raw-evidence.tar.gz` preserves complete Make/guest/per-case logs and the
failed mixed-tuple attempt. `artifacts.tar.gz` contains the exact matched
kernel/module, static loader, probe, linker, companion, native/proof fixtures,
and include/import snapshots. Earlier negative results remain unchanged.
