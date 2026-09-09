# Result Review: proof-bound native execution

## Outcome

The public command

```text
RUNTIMES="kernel native_kernel" SAMPLES=15 WARMUPS=1 INNER_REPEAT=100000 TIMEOUT=7200 make micro
```

exited zero on x86-64 KVM. Raw metadata is preserved at
`micro/results/x86_kvm_micro_20260909_121208_577260/metadata.json`. The guest
completed all 29 configured programs and powered down normally.

`analyze.py` accepted all 870 measured result/return-value pairs and all 435
native samples. Every native sample contains positive proof-open, independent
proof-verifier-load, and final program-load phase timings. The resulting
machine-readable summary is `analysis.json`.

## Execution benefit

The geometric mean across the 29 per-program median
`native_kernel / kernel` execution-time ratios is `0.6824347261`; below one is
faster. Its reciprocal is a `1.4653416096x` speedup. Native is faster for 26
programs, tied for two, and slower for one. A fixed-seed 50,000-draw bootstrap
over the program population gives a ratio interval of
`[0.6135276985, 0.7592106567]`.

This is close to, but distinct from, the preceding generation-zero trusted
native opportunity run (`0.6758480953`, reciprocal `1.4796224283x`). The
descriptive difference between separate runs is not a causal estimate of the
binding overhead. Both runs have the same 29 programs and sampling protocol;
only the new run verifies and generation-binds the simulator proof during the
load that installs the native payload.

Native code size is `0.5377131546x` the kernel-JIT code size by the same
per-program-ratio geometric mean. Code size is unchanged from the preceding
run because binding changes loading and authorization, not the emitted native
payload.

## Load cost

The geometric mean of per-program median `native_kernel / kernel` load ratios
is `54.5205457812x`. This is a ratio aggregate. Separately, the median across
the 29 per-program median load times is 116.192 ms for `native_kernel` and
1.869 ms for the kernel path; these two medians must not be divided and
presented as the ratio aggregate.

Within the native path, the median across per-program median proof-open times
is 31.490 us and the corresponding proof-verifier-load value is 2.529 ms. The
reported `native_kernel` load time also includes companion handling, native
linking/cache lookup, upload, relocation, and the KOP-expanded verifier/JIT
load, so the 2.529 ms value is not the complete binding cost.

## Failures that changed the implementation

The first full attempt retained at
`micro/results/x86_kvm_micro_20260909_094215_341511/metadata.json` found two
defects: successful loop-heavy proofs exhausted a forced 16-MiB verifier log,
and Katran's valid loop CFG contradicted the loader's final-EXIT assumption.
Focused failed results at
`micro/results/x86_kvm_micro_20260909_101556_226850/metadata.json`,
`micro/results/x86_kvm_micro_20260909_111713_283313/metadata.json`, and
`micro/results/x86_kvm_micro_20260909_114315_763230/metadata.json` preserve the
success-path `ENOSPC` and uninitialized-continuation evidence. The final loader
redirects every proof EXIT to the proof boundary, places the complete CFG on
the final native chunk, initializes preceding proof regions with `r0 = 0`, and
loads without verifier tracing unless a real failure requires a diagnostic
retry.

## Claim boundary

This run establishes a verifier-accepted proof and direct-native payload held
in one immutable, non-wrapping module-slot generation for the implemented
test-only path. Both proof instantiation and native JIT emission reject a stale
generation. It also separately loads the proof object through the stock
verifier before uploading the same relocated instruction vector.

It does not prove that the generator, native linker, and ISA simulator make
the native bytes semantically refine that proof. Those components remain
trusted, and general memory, control-flow, helper, and specialization
refinement remains open. This is therefore proof/native snapshot binding and
a real performance result for that test path, not a complete verified compiler
result, production-application throughput result, or ARM hardware result.

The run used one Intel Core Ultra 9 285K host. The suite recorded unknown guest
governor, turbo enabled, and no CPU affinity; the bootstrap measures variation
across program ratios, not machine-to-machine reproducibility or frequency
noise. These are analysis caveats, not retrospective validity gates.

## ARM64 functional reproduction

The generation-bound implementation also completed the unchanged public ARM
command:

```text
PLATFORM=qemu ARCH=arm64 RUNTIMES=native_kernel SAMPLES=1 WARMUPS=0 INNER_REPEAT=1 TIMEOUT=7200 make micro
```

Raw metadata is preserved at
`micro/results/arm64_qemu_micro_19700101_000024_077043/metadata.json`.
Independent validation found `completed`, 29 programs, 29 samples, 29 matching
results, 29 matching return values, and proof-open plus proof-verifier-load
phases in every sample. The guest powered down normally.

This run required two implementation fixes that are preserved by failed raw
attempts. A stale incremental kernel at
`micro/results/arm64_qemu_micro_19700101_000021_338346/` retained the old
256-instruction KOP proof buffer. After a normal incremental kernel rebuild,
`micro/results/arm64_qemu_micro_19700101_000022_284039/` reached ARM native JIT
emission and returned errno 524 because the JIT used a fixed 64-instruction
scratch while the native-lab descriptor declares a bounded 16-KiB chunk. The
JIT now allocates that scratch from `max_emit_bytes` and frees it on every
path. A transient loss of the host `qemu-aarch64` binfmt registration also
caused a pre-guest Docker `exec format error`; the existing system registration
was restored and an ARM64 Docker smoke exited zero before the final Make run.

The raw guest timestamps remain in 1970 and the host is x86-64, so this is
full-system QEMU functional evidence only. Its nanosecond fields are not
reported as ARM performance or hardware reproduction.
