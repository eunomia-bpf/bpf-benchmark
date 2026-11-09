# Native branch hardening, 2026-11-09

S15 implements the coordinator-selected native compiler and relocation route.
Source commits: 731a91ee6b87cbad5340976de90f146afa912a25, 1048afc134111aa6a68d46edaf8df345aa3576ad, 165ac41007f5857f46b5acaaa7b6e18c7c5e8d0e, 334996eb80cba1fed806c75783345cb94434663a.

## Behavior

x86 native compilation uses `-mretpoline-external-thunk`,
`-mfunction-return=thunk-extern` and `-fcf-protection=branch`. AArch64 uses
`-mbranch-protection=bti`. Existing scalar compiler flags remain present.
The B adapters interpret ENDBR64/BTI landing instructions and the architectural
transfer represented by compiler external thunks. The trusted path retains its
submitted P, single kernel copy, B generation, stock verification and JIT emission.

Relocation kind12 patches exactly four rel32 field bytes. Target low8 bits name
one of the15 ordinary compiler GPRs or16 for return; bit8 selects CALL. The kernel
resolves ITS, the stock retpoline/LFENCE alternatives, call-depth call/jump thunks
and the active return policy. The existing kernel patch helper applies the
additive `native-branch-thunks.patch` after the native-proof patch. RSP retains the
existing external-symbol generation path for its distinct transient-stack effect.

The generated native tail jump uses that same relocation. Tail programs declare
all four ordinary BPF callee saves through the existing sidecar ABI; the JIT and
tail pop sequence consequently share the same frame for every B register allocation.
The finite helper-table template also loads its target and calls its register thunk.
Runtime admission predicates added:0. Frozen workload and paper edits:0.

## Measured receipts

| Receipt | Actual outcome |
| --- | --- |
| Rust linker |91 passing tests |
| Trusted service |9 passing tests |
| Register/transfer ELF matrix |30 layouts,15 ordinary GPRs times CALL/JMP |
| Compiler/B adapters |x86 and ARM actual native ELF to compiled B pass |
| Kernel patch |Existing patch and additive thunk patch apply/idempotence pass |
| Private current-kprog kernel/module |Build exits0/0 |
| x86 retpoline+ITS guest |Stock/native retval2,34 invocations,33 tail transfers; stack24/pop24 |
| Pure retpoline guest |Finite indirect CALL/JMP, internal return and tail call pass; stock/native34/33 |
| Native ELF and all three JIT images |Plain x86 indirect branches0; selected pure-retpoline target differences match R11/RCX/return kernel symbols |
| Micro compile suite |29 positive plus1 unchecked-read compilation per ISA;60 total pass |
| x86 original safety45 |{'valid_executed': 9, 'verifier_rejected': 33, 'specialization_rejected': 1, 'accepted_finding': 2} |
| ARM original safety41 |{'valid_executed': 4, 'verifier_rejected': 28, 'specialization_rejected': 3, 'accepted_finding': 6} |
| ARM architectural BTI/ADR/BR control |valid_executed through actual B, stock verifier and native run |
| ARM compiled BTI/BLR control |positive_infrastructure_error; inherited saved-frame scalar equality verifier precision |

Safety negatives retain load-only execution. Negative native executions:0.
x86 original recovered-NULL labels: immediate_push_branch, stack_base_flags.
ARM original load-only labels: unpaired_stxr_failure, unpaired_stlxr_failure, paired_stxr_failure, paired_stlxr_failure, entry_return_address_flags, stack_base_flags.
The source-pinned receipts retain these actual stages and the full compiler,
service, verifier and kernel outputs. ARM used one2GiB QEMU guest, its four original
positive controls first under guest Clang, followed by the retained guest and the
existing host compiler broker; 33 host compiler jobs have individual receipts.
The guest process and P/source inputs retained ownership across that routing change.

## Recorded development diagnostics

The first private kernel cache predates the kprog API. Its source was advanced to
the current recorded kernel epoch and rebuilt incrementally. Assembler annotation
and symbol-table build diagnostics remain in the raw archive. The first hardened
tail replay exposed the B/native callee-save mismatch and measured2 invocations;
the complete-frame sidecar correction produced the34-invocation controls above.
Private-copy execute-mode and old static-producer activation diagnostics remain
alongside the successful current dynamic-loader replay. The host compiler PATH
uses private namespace copies and one wrapper; the shared directory retains its files.

## Universal interfaces and coverage

`coverage-proposal.tsv` supplies V's new THUNK_REL32 row. The existing universal
rel32 destination and immediate-field locality theorems apply to this field
placement. Its ledger status is `partial-universal-component`. V owns the complete
Rust/compiled-B/physical-thunk composition, including transient below-SP stack
accesses, dead-byte effects, landing-pad policy and the full callee-save relation.
The coordinator received the physical stack-validity case through Notices.

The ordinary ARM ADRP+ADD address-taken-function discovery frontier remains with A.
The compiled C control exercises the existing ADR route using the tiny code model and retains the saved-x29 scalar equality verifier diagnostic. A separate BTI c/j ADR/BR control with the ordinary unchanged frame executes successfully.
ARM landing-pad emission and the measured native control are recorded separately
from an enforcing-BTI kernel claim; embedded kernel-config extraction returned1.

Reproduce the focused compiler/linker check with:

```sh
TMPDIR=/var/tmp/kprog-tmp/S15 CARGO_TARGET_DIR=/var/tmp/kprog-tmp/S15/cargo \
  taskset -c 8-23 cargo build --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml
TMPDIR=/var/tmp/kprog-tmp/S15 PYTHONDONTWRITEBYTECODE=1 CLANG=clang-18 \
  taskset -c 8-23 python3 kprog/tv/test_native_branch_hardening.py \
  /var/tmp/kprog-tmp/S15/cargo/release/native-link /var/tmp/kprog-tmp/S15/replay
```

`raw-manifest.json` names every archived file and its SHA256. `source-identities.json`,
`kernel-source-epoch.json` and `runtime-identities.json` identify the actual source,
current private kernel epoch and runtime artifacts. Whole applications remain with C/A/R.
