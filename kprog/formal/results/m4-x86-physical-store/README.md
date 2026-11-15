# x86 physical-store source checkpoint

Status: prepared during the dedicated Katran quiet window; validation pending.
The CompCert branch of the existing shared scalar store reuses Platform's
upstream alignment-one copy adapter for widths1/2/4/8. Native volatile and BPF
asm bodies stay unchanged. A single X86Memory root calls that actual helper.
No new platform import, width mask or unsupported-width fallback is added.

The existing memory oracle gains complete byte-frame checks across offsets,
wide/raw width capture, four guard windows, a permission fault and unsupported
width nonreturn. These are prepared tests, not measured results. The original
selector validator's queued `make clight` will run the combined suite after
Katran releases timing EX. A follow-up validator waits for that process to end
before reusing the same build outputs for historical comparison, three store
mutations, the restored adapter, targeted Lean and native-byte comparisons.
Its raw directory is `m4-x86-store-selectors/physical-store` under
`/workspaces/kprog-raw/formal`; no test success or new Lean AST is claimed yet.

The source change removes the C-chunk alignment obstruction without declaring
native volatile, permission, pointer-fragment or fault correspondence proved.
Those remain M5 obligations. M4/full handlers/default coverage, all2,065
refinements/recounts, M6 and whole-library acceptance remain open.
