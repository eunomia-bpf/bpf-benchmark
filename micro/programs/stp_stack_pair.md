# stp_stack_pair

## Purpose

This benchmark is a selected coverage target for ARM64 `STP`.

It intentionally creates two adjacent 64-bit stack stores from independent
register values:

```c
pair.lo = lo;
pair.hi = hi;
```

The ARM64 kinsn backend should lower this shape to:

```text
bpf_arm64_stp_x
```

The benchmark uses a fixed 64-byte generated input. With bytes `0..63`,
`data[0] == 0`, `data[1] == 1`, and `len == 64`, so:

```text
lo = (64 << 32) ^ 0
hi = (1 << 48) | 64
result = lo ^ rotl64(hi, 17) = 274886295554
```

This target is not intended to represent a production workload by itself. It is
the correctness/coverage anchor that proves the STP ABI, selector, object
emission, verifier proof expansion, and ARM64 module lowering can execute under
the micro runner before pair-store selection is evaluated on broader workloads.
