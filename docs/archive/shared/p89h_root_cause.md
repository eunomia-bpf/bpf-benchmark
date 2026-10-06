# P89H kinsn verifier root causes

## Scope

Latest saved failure corpus used for host-side replay:

`corpus/results/x86_kvm_p89_kinsn_corpus_20260430_131403_981524`

The run had 81 preserved failure workdirs under `details/failures/`. The saved
workdirs contained cilium and tetragon verifier/rejit failures; tracee did not
have a failure workdir in that run.

The replay helper is `docs/tmp/p89h_reproduce.sh`. It copies a saved failure
directory to a scratch output directory, runs `bpfopt optimize` with the saved
`prog.bin`, `prog_info.json`, func info, line info, and target metadata, and can
optionally run `bpfverify` on the optimized output.

## Host replay note

The host can replay `bpfopt` transformations directly from the saved failure
workdirs. Full host `bpfverify` dry runs are limited for programs whose saved
metadata references guest map IDs or FDs, because the host kernel cannot reopen
those guest objects and reports `BPF_MAP_GET_FD_BY_ID: Operation not permitted`.
For those cases, the iteration loop used host `bpfopt` output plus the saved
guest verifier/rejit logs to isolate the pass and bytecode shape. The final KVM
smoke run is the kernel-side validation.

## cilium: endian_fusion

Affected examples:

- `details/failures/219`
- `details/failures/235`

Root cause: the x86 lowering path for the endian-fusion kinsn call materialized
frame-pointer stack offsets into a temporary register before the kinsn sidecar
instruction. That made a two-instruction source pattern grow into four
instructions and obscured the original `r10 + off` operand shape that the kernel
ReJIT path needs to preserve for verifier-equivalent rewriting.

Fix: encode stack offsets directly in the kinsn sidecar payload when the operand
is already representable as `base + off`. For the cilium failures, the optimized
programs now keep the same instruction count (`1110 -> 1110` and `1194 -> 1194`)
while still applying the endian-fusion candidate.

Commit: `6708d2a1 fix(kinsn/endian): encode stack offsets directly`

## tetragon: extract

Root cause: tetragon failures that changed only in `extract` had multiple
subprograms in func-info metadata. The optimized bytecode could still pass
standalone verification, but the saved guest logs showed the ReJIT replacement
path rejecting the transformed program. The current kinsn ReJIT metadata
contract is not safe for these multi-subprogram extract candidates because the
candidate is emitted without enough proof that the rewritten instruction stream
preserves all subprogram metadata boundaries.

Fix: `extract` now requires single-subprogram func-info before emitting kinsn
candidates. Multi-subprogram programs remain unchanged by this pass, which keeps
the failure visible as an unsupported candidate shape instead of producing
invalid ReJIT input. This is a candidate safety guard, not app or program
filtering.

Commit: `858ddd97 fix(kinsn/extract): avoid multi-subprog rejit candidates`

## tetragon: bulk_memory

Root cause: the tetragon workdirs that changed in both `bulk_memory` and
`extract` had the same multi-subprogram metadata shape. `bulk_memory` could
emit kinsn candidates into programs whose func-info layout was not proven safe
for the current ReJIT replacement boundary.

Fix: `bulk_memory` now applies the same single-subprogram func-info proof guard
before emitting kinsn candidates. Multi-subprogram inputs are left byte-for-byte
unchanged by the pass.

Commit: `bad918ea fix(kinsn/bulk_memory): avoid multi-subprog rejit candidates`

## Verification

- `cargo fmt`
- `cargo test -p bpfopt test_endian_fusion_encodes_stack_offset_directly_on_x86`
- `cargo test -p bpfopt test_extract_pass_skips_multi_subprog_candidates`
- `cargo test -p bpfopt test_bulk_memory_skips_multi_subprog_candidates`
- `cargo test -p bpfopt`
- `cargo build --release -p bpfopt -p bpfverify`
- Host replay of all 81 saved failure workdirs with `docs/tmp/p89h_reproduce.sh`
  and `VERIFY=0`

Final KVM smoke result: pending.
