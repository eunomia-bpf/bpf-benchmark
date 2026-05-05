# cond_select Immediate Operand Support - 2026-05-05

## Path

Path A: register materialization.

The current `bpf_select64` packed kinsn ABI is register-only. The x86 and
arm64 modules decode only `dst_reg`, `true_reg`, `false_reg`, and `cond_reg`,
and reject any non-zero payload mode field at bits 16+. No immediate operand
variant is available without kernel/module changes, which are forbidden for
this task.

## Implementation

- Matcher relaxation:
  - `bpfopt/crates/bpfopt/src/passes/cond_select.rs:312` accepts ALU64 and
    ALU32 MOVs in Pattern A via `is_select_mov`.
  - `bpfopt/crates/bpfopt/src/passes/cond_select.rs:349` does the same for
    Pattern C.
  - `bpfopt/crates/bpfopt/src/passes/cond_select.rs:398` records MOV64 reg,
    MOV64 imm, MOV32 reg, and MOV32 imm operands separately.
- Compare relaxation:
  - `bpfopt/crates/bpfopt/src/passes/cond_select.rs:459` builds a predicate
    register for non-simple compares while keeping direct packed operands for
    `JNE/JEQ reg, 0`.
- Register materialization:
  - `bpfopt/crates/bpfopt/src/passes/cond_select.rs:573` materializes immediate
    and ALU32 source operands into verifier-dead temp registers before the
    packed kinsn sidecar.
  - `bpfopt/crates/bpfopt/src/passes/cond_select.rs:610` chooses temps from the
    destination register or dead caller/callee BPF registers, excluding live
    values and predicate/source registers.

Unit coverage added in
`bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs:276` through `:478`:
immediate-true/reg-false, reg-true/immediate-false, both-immediate, ALU32
reg materialization, non-zero `JEQ reg, 5`, JMP32 zero predicate handling, and
non-JEQ/JNE predicate lowering.

## Delta

Implementation commit: `35ed1536fe00b11cf0507668a83a86df08256b1f`.

cond_select-only diff in that commit:

```text
2 files changed, 442 insertions(+), 113 deletions(-)
bpfopt/crates/bpfopt/src/passes/cond_select.rs        +284 / -85
bpfopt/crates/bpfopt/src/passes/cond_select_tests.rs  +158 / -28
```

Net delta: +329 lines. This exceeds the +120 target because the committed
change includes immediate materialization, ALU32 value support, and generic
predicate generation for relaxed compare shapes.

## Validation

Unit/workspace:

```text
cargo test -p bpfopt cond_select --manifest-path bpfopt/Cargo.toml
29 passed

cargo test --release --workspace --manifest-path bpfopt/Cargo.toml
415 passed
```

KVM corpus smoke command:

```text
SAMPLES=1 BPFREJIT_BENCH_PASSES="cond_select" \
  BPFREJIT_CORPUS_APPS="cilium/agent,bpftrace/runqlat,bcc/syscount" \
  make vm-corpus
```

Smoke artifact:
`corpus/results/x86_kvm_corpus_20260505_151215_014924`

Result:

```text
suite status: ok
app status: bcc/syscount ok, cilium/agent ok, bpftrace/runqlat ok
cond_select sites_applied before: 1
cond_select sites_applied after: 16
per-app after: bcc/syscount 0, cilium/agent 12, bpftrace/runqlat 4
error/reject records: 0
```

The requested smoke did not reach "several hundred" applied sites. The live
result JSONs show all 16 matched sites applied and no skip/reject records. This
matches the prior investigation's warning that static object candidate counts
do not directly reconcile with live loaded bytecode for the current artifacts.
