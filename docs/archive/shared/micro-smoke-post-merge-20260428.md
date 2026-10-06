# KVM x86 Micro Smoke After bpfopt-core Merge

- Timestamp: 2026-04-28 20:29:34 -0700
- Host commit at run: `de64cde33d74b430f5349bc464073e7b2db45566`
- Relevant merge/review commits in history: `7d34960e`, `d973a4fd`
- Command: `source /home/yunwei37/workspace/.venv/bin/activate && make vm-micro SAMPLES=3`
- Target: `x86-kvm micro`
- Log: `/tmp/bpf-benchmark-vm-micro-smoke-20260428-200734.log`

## Environment

- `vm-micro` target was present in `/home/yunwei37/workspace/bpf-benchmark`.
- CPU: x86_64, Intel Core Ultra 9 285K, 24 CPUs, VT-x available.
- Memory after run: 125 GiB total, 117 GiB available.
- KVM guest configuration from the run: 4 vCPUs, 32 GiB memory.

## Result

- Overall status: failed.
- Build status: passed far enough to build/export the x86_64 runner runtime image and extract the runtime kernel.
- VM status: guest started and invoked the micro suite.
- Microbenchmarks completed: 0.
- Result directory created: `micro/results/x86_kvm_micro_20260429_032844_862721`.
- Result payload: not written; the result directory is empty and `micro/results/x86-kvm_micro.json` was not produced.
- Baseline phase: did not complete.
- ReJIT phase: not reached.
- Post-ReJIT phase: not reached.
- Applied programs: unavailable because the run failed before ReJIT results were emitted.
- Failed programs: unavailable; there is one run-level failure.
- Per-bench ratios: unavailable because no benchmark result payload was emitted.

## Failure

The guest-side driver failed while writing the running artifact metadata:

```text
RuntimeError: baseline benchmark not found in results: simple
```

The failing command inside the guest was:

```text
/usr/bin/python3 /home/yunwei37/workspace/bpf-benchmark/micro/driver.py --runtime llvmbpf --runtime kernel --samples 3 --warmups 0 --inner-repeat 10 --output /home/yunwei37/workspace/bpf-benchmark/micro/results/x86-kvm_micro.json --perf-scope full_repeat_raw
```

The preserved runner debug artifact path was:

```text
/home/yunwei37/workspace/bpf-benchmark/.state/runner-contracts/run.x86-kvm.micro.d885446e
```

No daemon panic or Rust panic signature was found in the run log. The only fatal error found was the Python `RuntimeError` above.

## Conclusion

This smoke run did not validate the Phase 1.1 merge on real KVM micro benchmarks. It is a regression/blocker for the default `make vm-micro SAMPLES=3` entrypoint because the suite exits before baseline, ReJIT, post-ReJIT, applied-count, or ratio data are produced.
