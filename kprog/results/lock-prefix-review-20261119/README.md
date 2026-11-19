# Locked x86 memory operations: phase-1 source trace

The coordinator's 2eb36bad9 receipt identifies a lost `lock incq` prefix in
the checked configuration. Source tracing confirms where it disappears:

- `kprog/x86/micro-prog/generate_micro_sim_proofs.py:182` removes `lock `
  before creating `NativeInsn`; its `raw` text is also the stripped string.
  `NativeInsn` at line 94 has no retained lock field.
- `encode()` at line 820 maps a memory `inc` to `X86_OP_ALU_MEM_UNARY`,
  carrying only width, memory-address auxiliary bits and the ALU operation.
  `append_step()` at line 1431 consumes that encoding for shared simulator C.
- `kprog/x86/x86_sim_local_bpf.h:2052` implements that unary memory arm as
  a read, arithmetic/flag calculation and a separate write. The original
  locked operation cannot be reconstructed from the lost encoding.

B and checked native are compiled from this same C, so correcting only the
native LLVM lowering would leave the verifier's representation inconsistent.
The class needs prefix preservation, a shared atomic RMW operation, and
retained width/flags/fault behavior. Audit the memory exchange forms too.
No new refusal, program exclusion, runtime check or mode switch is a fix.

Next: after the active batch, reproduce with real locked/plain assembly,
trace emitted B and native instructions, then implement the class in the
generator and shared operation with FORMAL. The shared interpreter header
is frozen; this source review changes neither it nor the active cohort.
The current results remain recorded with this correctness limitation;
this finding adds no benchmark admission gate or automatic rerun.

PERF 2026-11-19T09:05:51Z:8aa2dc378 adds four real locked/plain assembly pairs:
INC64,INC32,register-source ADD64,immediate-source ADD64. The local Make
entry builds one fixture object, GNU objdump feeds the actual production
parser, and evidence.json records native extents, decoded text and encoded
operations. The regression requires different locked/plain encodings; the
current defect is expected to fail that assertion after writing all cases.
An encoding-only pass will not close the shared atomic-memory obligation.

Detached worker314899 waits on timing SH behind the active BCC measurement;
raw reproduce-20261119T085937Z-314899, launcher
/workspaces/kprog-raw/perf/lock-prefix-review-launch-20261119.log. No test
result is claimed before it runs, and no active generator/interpreter or
benchmark input changed. Read commands.json/evidence.json/exit-code next;
distinguish a reproduced semantic assertion from a setup/compiler failure.

PERF 2026-11-19T09:23:54Z: Both queued workers ran after timing released at
09:23:20Z, source 6d6cb8b28. Worker 314899 exited Make 2 at the expected
semantic assertion after writing all four cases: locked/plain INC64, INC32,
ADD-reg64, ADD-imm64 have identical simulator encodings. reproduction-result.json
retains that evidence. This reproduces the defect, rather than a setup
failure, and leaves P-x86-lock-rmw open.

Atomic compiler worker 318982 finished 0 at 09:23:21Z. All eight native cases
compile; BPF-v4/O1 accepts 32/64-bit fetch-old ADD and compare-exchange and
rejects all four 8/16-bit cases with compiler exit 70 and "unsupported atomic
operation, please use 32/64 bit version". atomic-result.json contains the
actual commands and successful native/BPF assembly; each complete stderr
stays under atomic-20261119T091806Z-318982 in the persistent raw parent.
No atomic shared-I implementation, stock execution or concurrency claim is
made by this feasibility matrix. The next change must preserve the prefix
and implement the shared memory effect; replacing a narrow failed atomic
with separate reads/writes would reproduce the bug.

PERF 2026-11-19T09:46:49Z: The implementation retains `NativeInsn.locked`
and the original LOCK spelling. Unary, register-source and immediate-source
memory ALU encodings carry `X86_MEM_LOCK` separately from their width. Their
shared C handler resolves that bit before entering the existing plain body.
It performs seq_cst C atomic fetch operations, with a compare-exchange loop
for NEG, then derives flags from the successful old value. ADC/SBB capture
incoming carry once; INC/DEC and NOT retain their existing flag contracts.
There is no kernel/helper/benchmark/producer-flag change or added refusal.

Shared map memory receives one atomic write and ghost-tag invalidation.
Private RSP offsets resolve to the simulator arena; stack aliases retain
their overlapping tag erasure. Released private bytes retain the existing
read/materialization/release observations in that arena. Those private
representation stores are separate from shared memory and preserve the
ordinary private path's input visits. They do not follow a shared-map RMW.

Host results (timing SH, CPUs 18/19):

- All four real locked/plain encoding pairs now differ; plain encodings keep
  their width and operation fields. See fixed-encoding-result.json.
- 17,424 actual hardware memory/flag comparisons pass across 8/16/32/64-bit
  widths, all eleven legal ALU operations, carry and boundary values, and
  both binary operand forms. Four concurrent threads complete 80,000 shared
  increments. Live/released stack aliases, three negative displacements and
  the existing recovery branch pass. See shared-result.json.
- All 22 shared 32/64-bit operations compile through BPF-v4/O1 and the
  existing native compiler/O3. B has no unresolved symbol; every resulting
  native body retains LOCK. See shared-bpf-result.json. This is compilation
  and disassembly, not stock verifier acceptance.

Raw outputs remain under shared-20261119T0939Z,
fixed-encoding-20261119T0939Z, shared-bpf-20261119T0944Z and
shared-release-contract-20261119T0947Z in the persistent parent. The two
failed released-byte test attempts also remain (shared-released-20261119T0947Z
and shared-released-debug-20261119T0945Z). That test initially assumed a
fixed stack-alias load consumed the same released-byte input as RSP. Source
and the diagnostic show the existing no-index fixed-load path bypasses the
tagged-read observation. The regression now checks preservation of each
existing path's complete flags, arena state and input visits; it does not
claim hardware agreement for that separate released-alias model issue.

CompCert exposes the exact typed boundary
`kprog_c_x86_locked_rmw(void *, __u64 value, __u32 width, __u32 operation,
__u32 carry) -> __u64 old`. Width is bytes, operation is `X86_ALU_*`, carry is
the captured input, and ordering is fixed seq_cst. Its indivisibility,
faults, private representation and old/new correspondence remain FORMAL
obligations; the declaration is not a proof.

The coordinator's queued batch 327120 installs the HEAD compiler and times
this fix together with 2eb36bad9. No separate BCC timing is queued. Actual
app B/stock/native coverage and the combined runtime effect remain pending;
the previous 1.016x result precedes this implementation.

PERF 2026-11-19T10:36:35Z: Live batch 327120 completed the baseline arm
with status ok. Its request log has 25 completions from 25 distinct source
program IDs: all status 0, checked-sim-c, B generated and B stock accepted;
no fallback or failed request. The last request finished at 10:33:24Z.
The native arm's three samples have started. live-load-status.txt records
the point-in-time counts and exact raw log. This is actual guest stock and
native-install evidence for the combined freeze/LOCK cohort, while final
app status and runtime remain pending. The final archive reader will
replace this provisional accounting with complete run coverage.

PERF 2026-11-19T10:48:19Z: Coordinator batch 327120 finished at 10:45:48Z,
host 0, app ok. Run x86_kvm_corpus_20261119_101802_025374 completed three
180 s samples per arm, stats on. The final archive confirms programs/native/
B-generated/B-stock 25/25/25/25, all checked, no fallback or failed request.
The existing analysis reports 103.8→103.1 ns/inv, 1.007x; throughput 1.006x,
sample ratios 1.015/0.995/1.006, zero workload errors. Installed native is
8,628 B versus JIT 7,965 B across 25 programs. See combined/ for the original
reader outputs and complete coverage; small corpus raw files are committed.

The earlier cohort reported 107.7→106.0 ns and 1.018x throughput, installed
20,043 B. Both JIT and native times changed between runs. This run combines
2eb36bad9 with LOCK and provides no isolated speed effect for either piece.
It meets neither runtime target. Body/helper/map shares were not profiled.
The lost-LOCK implementation item now has host and real BCC stock/native/app
confirmation; full application stock coverage and FORMAL's atomic refinement
remain separate open obligations. No extra BCC timing is queued.
