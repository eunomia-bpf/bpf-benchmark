# Stock-path receipt review, 2026-11-09

This continuation reviewed existing source identities and saved guest receipts.
The measured results below come from the preceding S17 guest runs.
The publication covers static per-case tables and this report.

| ISA | Cases | Executed controls | Verifier rejection | Generation rejection | Accepted load-only |
| --- | ---: | ---: | ---: | ---: | ---: |
| x86-64 | 48 | 10 | 34 | 1 | 3 |
| AArch64 | 48 | 4 | 33 | 4 | 7 |

Both tables record zero negative native executions. Accepted load-only cases
remain explicit in the tables. Finite suite observations support regression
coverage; universal O1/O2/O4 and compiler correspondence retain their separate
proof obligations.

The tables correspond by case, stage and return code to saved outcomes:
x86 uses `S17/run/x86-current/outcomes.json`; ARM uses
`S17/run/arm64-final/outcomes.json`. Private output root:
`/var/tmp/kprog-tmp/S17`. Saved outcome JSON SHA256 values:

- x86: f1ca403e43cb6bbcfc0ac52245e5ad9a72fa396459e0a0f0ed3427640e924580
- ARM: 4a5074a3eb51d39823618da1937d2777c983560e8b036bba661b5649c0634857

Kernel source identity: `35ea2cde39fc88b01f2f49b2a357e7cf7102e4c8`, present
in `origin/kprog-no-kinsn`. `kernel/bpf/verifier.c` blob is
`159b25f8269ddfd6f66edabbca06e3822e56a330` at both that commit and
`c23719abc330`. The kernel diff against that base totals eight files,
467 insertions and one deletion. Changes occupy the x86 and ARM JIT and fault
paths, shared native header, BTF include, core and syscall handoff.

Published stock receipts through `21ee8db8d` are ancestors of `origin/master`.
They retain credential outcomes (`678ca954e`), first-frame observations
(`ca3f85146`) and ARM controls (`21ee8db8d`). The single-attempt loader source
is published as `d140d92ab`.

Observed table differences against the paired kinsn receipts:

- Both ISAs: `uninitialized_stack` is accepted load-only with privileged
  stock `allow_uninit_stack` semantics; the paired kinsn receipt records
  verifier rejection. The credential receipt records acceptance with
  CAP_BPF plus CAP_PERFMON and stack-initialization rejection with CAP_BPF
  alone. Original privileged acceptance remains in history.
- x86: `valid_r12_preserved` executes; its comparison column identifies it
  as an additional positive control. All other paired stages agree.
- ARM: every other paired stage agrees.

Stock-path integration differs structurally through ordinary B admission,
shared armed-image ownership/subprogram error, architecture-native JIT emission
and the matching fault paths. The verifier source keeps the base identity.
The loader supplies the diagnostic buffer on its first load attempt.

The published ARM controls record small-program retval 2, live/NULL BTF values
4294967295/0, ordinary subprogram load success, and armed-subprogram EOPNOTSUPP
with one raw load. Saved ARM injected-relocation-error service output records
load failure after verifier processing, as described in the S17 10:01 notice.

The saved x86 tail control records stock/native retval 2, 34 invocations and
33 transfers on each route, with JIT stack depth 0 and pop 0. The separate
physical R12/RSP/RBP observation exits 1 with the diagnostic
`tail frame: physical R12/RSP/RBP observation`. Physical frame preservation
therefore remains an open result. Successful-transfer frame-predicate
composition remains the S11 O4 obligation.

The saved x86 JIT-error fixture exits 1 after its service records status 0
and a program ID; its client reports a TEST_RUN return mismatch. This receipt
establishes a fixture discrepancy. The x86 kernel-error result remains open.

The preceding final collector stopped on its expected-one-failure-archive
assertion. Existing raw artifacts, source/build outputs and shared-index state
are retained for review. End-to-end stock-path acceptance remains open for the
physical tail observation, x86 kernel-error receipt, complete raw collection
and universal proof composition. This continuation ends after defensive
receipt publication; native-image JIT implementation and execution remain
outside its safety scope.
