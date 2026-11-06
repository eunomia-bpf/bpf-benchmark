# Repaired235-form CPU replay

The identical235-form shape now has60160/60160 CPU/C agreements after the
D0 upper-half clear. No other simulated memory path changed. Exact command,
harness/production snapshot, native byte spans and per-form counts are retained.
The later ../arm64-memory-complete/ replay adds20 pair forms and independently
checks every output against the canonical reference.

```sh
taskset -c 16-23 prlimit --as=12884901888 -- make -C kprog/fidelity -f bank32.mk run-qemu BUILD=build-arm64-addressed-memory-fixed FAMILY=memory CASES=256 OUT=../results/kprog_fidelity_20261106/differential/arm64-memory-matrix-fixed
```

Rebuild archived generated C/assembly to retain235 forms; the current family
generator includes the later255-form matrix. This is QEMU functionality.
