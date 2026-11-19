# Roots hidden by generated memory-base barriers

Read-only inspection of retained checked-native IR after ff02957cc, using
LLVM's existing getUnderlyingObjectsForCodeGen analysis on the pointer
before each generated register barrier. Counts distinguish provable private
arena roots from other or unknown roots. This diagnoses whether a narrower
barrier rule can expose stack aliases while preserving the absolute-address
contract; it changes no production source and supplies no runtime result.

PERF 2026-11-19T08:05:59Z: LLVM18 inspection passes on the retained BCC request17
(sys_exit_open) input. All42 generated base barriers have unknown roots;
folding only constant integer freeze nodes in the in-memory diagnostic
module leaves all42 unknown. A private-root rule using this analysis on
the present IR would therefore select no sites. No production fast path
or barrier removal was added from that unsupported premise.

The retained IR at
/workspaces/kprog-raw/perf/native-integer-identities-20261119/candidate-20261119T075305Z-233661/bcc-replay/17/root-inspection.ll
shows the first base explicitly: lines430-433 contain freeze40 and
ptrtoint(private arena)+8+freeze40; lines561-563 add freeze0 and inttoptr;
lines757-761 wrap the base in the generated tied asm and emit the volatile
store. This identifies an ordering/canonicalization problem in exposing
private memory. The absolute/null-base regression remains relevant.

Raw inspection /workspaces/kprog-raw/perf/native-base-roots-20261119/inspect-20261119T080429Z; roots.tsv records both phases. The first
inspection build lacked the Module definition include and failed;4e8cbe43a
fixes that include, and both later inspections pass. No source frontend,
image, guest, benchmark or native production code changed in this audit.

PERF 2026-11-19T08:41:44Z:9a8696938/246b13c19 add a read-only third phase using LLVM
simplifyInstruction on pure arithmetic/casts/GEP/freeze. The analysis also
handles integer base operands after pointer round trips simplify. Actual
results are pending because timing EX is held by the image-check/timing
batch. Detached recipe c1ded558b waits on timing SH; no production source,
compiler base or guest is changed. The initial foreground waiting flock
305980 was ended before work began and retained as exit143 at
arithmetic-20261119T083043Z; the detached worker uses a fresh raw directory.
