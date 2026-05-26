# ccmp_all_nonzero

## Purpose

This benchmark is a selected coverage target for ARM64 `CCMP/CMP/CSET`.

It intentionally contains the first-version selector shape:

```c
dst = (a != 0 && b != 0 [...]) ? 1 : 0;
```

The ARM64 kinsn backend should lower this shape to a contiguous kfunc sequence:

```text
bpf_arm64_cmp_x
bpf_arm64_ccmp_x
bpf_arm64_cset_x_cond
```

The benchmark uses a fixed 64-byte generated input. With bytes `0..63`,
`data[1]` through `data[4]` are all non-zero, so the expected result is:

```text
1
```

This target is not intended to represent a production workload by itself. It is
the correctness/coverage anchor for the `CCMP/CMP/CSET` ABI, selector, object
emission, verifier proof expansion, and ARM64 module lowering.
