# csel_select64

## Purpose

This benchmark is a selected coverage target for ARM64 `CSEL`.

It intentionally contains the first-version LLVM selector shape:

```c
dst = (cond != 0) ? true64 : false64;
```

The ARM64 kinsn backend should lower this shape to:

```text
bpf_arm64_tst
bpf_arm64_csel_ne
```

The benchmark uses a fixed 64-byte generated input. With bytes `0..63`, both
conditions are non-zero, so the expected result is:

```text
15327322346016019187
```

This target is not intended to represent a production workload by itself. It is
the correctness/coverage anchor that proves the CSEL ABI, selector, object
emission, verifier proof expansion, and ARM64 module lowering can execute under
the micro runner before CSEL is evaluated on broader workloads.
