# x86 XDP context identity

The XDP entry GPR retains the actual verifier context. Ordinary stores and
memory intrinsics no longer target a private writable context copy. Native
64-bit data/data_end reads use the current typed BPF fields with the complete
base-relative alias offset. The old helper-side cached-field refresh is removed.
The entry selects XDP representation with a constant flag; no pointer-null
check, safety guard, count cap, or native instruction omission is added.
Unmapped XDP reads fail specialization. SKB projection remains separate work.

| Validation | Result |
| --- | --- |
| Existing route host, including actual context identity/live fields/offset alias |7057 cases pass|
| Existing memory-dispatch host |58 cases pass|
| Final five positive micro builds plus existing negative compile fixture |all compile|
| Actual kernel and fresh generation-bound helper/map controls |13/13 pass|

The13 controls reuse F's existing unchanged positive inputs, expected results
and producer; they do not overwrite F's evidence. Every control executes both
kernel BPF and newly bound native code through the native-only service. The
producer checks nonzero generation, absence of prebuilt proofs, the exact64bit
packet result and retval2. `summary.json` pins header/generator/oracle and
kernel/module bytes before/after; all match. Complete request archives and
per-case stdout/stderr are in its referenced archive, with the raw outcomes
also compressed separately. No unsafe native case was executed here.

Reproduce from the repository root:

```
make -f corpus/results/kprog_app_coverage_20261107/xdp-context-identity/Makefile kvm
make -C kprog/x86 micro-proofs-build MICRO_SIM_PROOF_ARGS="--only simple simple_packet packet_checksum_fold tc_packet_checksum_fold cgroup_skb_hash_chain"
```

The host commands are the existing `kprog/formal/Makefile` recipes for
`oracles/x86_route_host.c` and `oracles/test_x86_mem_dispatch_route_host.c`.
The positive wrapper pins the reused driver hash; its frozen source is retained
as `positive-driver.py.gz`. Existing kernels/modules were reused, not rebuilt.

The first full29 positive compilation passed on an intermediate header; it is
not counted as final-header verification. An address-equality selector then
failed to erase the XDP arm for SKB; a pointer-null selector compiled but made
all13 safe native loads fail with invalid scalar access. Both failures are
retained. `attempt-nullcheck-*` and its request archive record13/13 refused,
with no bound-native execution. Final entry-constant selection passes the
same13 unchanged cases. The initial wrapper syntax/setup error is retained
in `context-positive.log.gz` and is not counted as a program rejection.

This is a context repair and positive regression result. Independent unsafe
suite replay, SKB effect projection, opensnoop memory-intrinsic binding and
complete six-application coverage remain pending; no whole-simulator O1/O4,
full BCC coverage, same-work timing or application completion is claimed.
