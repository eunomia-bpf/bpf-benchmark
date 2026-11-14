# Packet-field identity provenance

`KPROG_BPF_STRICT_IDENTITIES=1` enables the B IR compiler's
`--strict-identities` option. An empty asm output carries its input's packet
field provenance only when the constraint explicitly ties it to that input
(`=r,0`), with one argument and identical input/output types. The option is
off by default. The tracing-context matcher uses the same strict helper.

The previous packet matcher inferred identity for independently constrained
outputs. An actual native execution makes the error reproducible: with
`data=100`, `data_end=200`, and an untied output seeded to zero, unsigned
`(output-data)<64` returns zero before transformation and in strict mode,
but one with the legacy transformation. `execution.json` records all 60
executions across tied/untied functions, five context pairs and six output
seeds. Original and strict results match the independent unsigned-arithmetic
reference in every case. The native wrapper pins the independent output
register so this counterexample is deterministic.

A second fixture uses legal BPF constraints (`=r,r` for the untied output).
Strict mode recognizes only the tied predicate, and both legacy and strict
IR compile to BPF. This checks BPF-domain matching and code generation; the
60 execution cases run as native code. The service compiler forwarding path
also compiles a real BPF fixture with the option explicitly enabled.

Disabled output equals the prior base compiler byte for byte. Two retained
real Cilium frontend IR inputs also produce identical old/default/strict
bitcode. Neither retained input contains an eligible packet predicate (the
compiler reports zero lowered predicates), so these are compatibility
controls, not active transformation coverage. Full command output and the
source inputs are recorded in `commands.json`, `before.ll` and `bpf.ll`.

The tracing regression covers 8/16/32/64-bit reads at offset80, dynamic
addresses, other sections and untied outputs. Enabling both options produces
exactly the context-only bitcode. Its on/off ELF objects also equal the
previously kernel-tested objects byte for byte (`context-object-parity.json`):
the earlier actual kernel run rejected all four original modified-pointer
forms and loaded all four rewritten forms. No additional kernel run was
needed for the identical objects.

Sources: a267788ea, 3ed4d58e9, 977e9acef and 42959d7d7. Final runs:
`/workspaces/kprog-raw/perf/20261114-packet-identities-v3` and
`/workspaces/kprog-raw/perf/20261114-context-identity-regression`; Make targets
`identity-check` and `context-build` in `kprog/test/scalar-spill-precision.mk`.
Raw logs, observations and rebuild commands remain on persistent storage.

This is phase1 B generation correctness. The shared simulator C, runtime P
and pre-bounds IR used for checked-native compilation retain their definitions.
Whole-application checked execution and equal-work remain open; this result
makes no runtime performance claim.
