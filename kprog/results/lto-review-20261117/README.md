# LTO performance review

2026-11-17T00:18:07Z. Source reviewed at f821e1c77; kernel
83e0fabe355d. This is a source and retained-output review, with light host
reads on CPUs 16–19. No source was changed, tool built, image published or
guest started. The coordinator owns implementation. Recommendations below
introduce no new runtime check or admission gate.

Scope update, 2026-11-17T03:18:29Z: operator decision 31aadd99c requires
O3 for every P and load-time LTO. Os/O2 investigation records below are
historical; their follow-up fixes and flag candidates are closed by that
decision. The active review concerns the O3 pipeline and its LTO work.

The strongest remaining opportunities are the read-helper family and map
calls whose type is known but whose emitted path still redispatches. Making
ordinary native arithmetic faster cannot remove those costs. The shared
kernel hash is already the smaller implementation and the retained paired
diagnostics do not support replacing it with a per-program copy.

## Priority and app coverage

Ranking is expected opportunity, informed by the retained profiles, not a
claim that a proposed change has achieved a measured speedup. Static sites
are not execution frequencies. All changes still need their isolated app
measurement through the frozen entry, with installed bytes and per-call
time. The 00:19:11Z audit withdraws the coordinator's earlier interpretation
that every app's installed native/JIT ratio must be <= 0.5: the flag study
measures stage executable bytes against the operator's code-halving request,
and reports installed bytes separately. Both sizes matter when evaluating
whether LTO work earns its footprint.

| Rank | Finding | Most affected apps | Expected per-call effect and size direction |
|---|---|---|---|
| 1 | Probe reads retain runtime-size loops, feature selection and a nested policy call | OTel; kernel-read sites in Tracee/Tetragon; BCC | Specialize common small reads/SMAP; inline the live target policy to allow a leaf routine (section 14). The 8/1-only remainder is addressed in c03737bf4; its historical costs below are not current measurements. Selective variants can grow code, so retain sharing. |
| 2 | Compat reads bypass that lowering entirely | Tracee, then Tetragon where present | Address-domain/size specialization can remove wrapper/copy overhead while preserving the helper's user/kernel choice. Actual Tracee blobs retain 2,375 read and 714 string call sites. This is an opportunity shared with the JIT helper, not evidence of a native-only regression. |
| 3 | Constant tail slots use the indirect path (section 8) | Cilium, OTel; constant sites in Tracee/Tetragon | Installed Cilium JIT has patched direct jumps; native retains map bound and target loads. A constant-slot LTO subset can remove bound/index bookkeeping, while full direct patching needs the existing map-update/lifetime contract. |
| 4 | Unknown map path nests ARRAY, LPM and generic helper calls | OTel residual dynamic maps, Katran; potential BCC/Cilium/Tracee sites | Remove two extra call/return pairs and their stack adjustments on a non-ARRAY/non-LPM fallback; bind a concrete operation where type facts suffice. Retained Katran dispatcher costs are small, so this alone does not explain its entire gap. |
| 5 | Proven ARRAY accesses always cross a shared call boundary | OTel, BCC, Cilium, Katran where these sites execute | Selectively expose small constant-key accesses to LLVM, removing call/key materialization and enabling folding. Blanket inlining would undo demonstrated size savings. |
| 6 | Map identity is discarded at every basic-block boundary and memory reload | All five, site dependent | Recover additional direct lookup/update/delete bindings using actual provenance. Dynamic inner-map identity must remain distinct from its known type. Static source opportunity; no new hot-site count is established here. |
| 7 | Finite helper-ID joins become another runtime compare chain | Tetragon; other helper-selecting sources | Propagate/split a proven selection earlier where possible, avoiding repeated ID redispatch. Source-confirmed shape; production hot frequency and gain are unmeasured. |
| 8 | Exact hash key length stops before the LTO plan | Katran, BCC, OTel hash sites | Current JIT/native use the same runtime-length kernel lookup. Exact-shape specialization remains a distinct, unmeasured opportunity; the copied-hash comparison did not test a separately specialized function per proven key length. |
| 9 | Current-task BTF and jiffies helpers retain calls the JIT removes | Tracee, Cilium | Remove a call/return per executed covered site. Historical outputs have 121/91 static calls; dynamic importance is unknown, and inline loads can grow installed text. |
| 10 | Memory emission conflates a known count with full unrolling | OTel dynamic 668-byte zero fill; Tracee/BCC unrolled zero fills | Keep count facts independently of the loop/unroll decision. Tracee's retained entry proofs repeat 200/368-byte fills with 133/280-byte bodies; compactness competes with the unrolled path's lower branch count. No measured per-call gain. |
| 11 | ARRAY routines jump to shared return instructions | All apps using these ARRAY routines; OTel retained bytes demonstrated | Separate returns remove one jump on each successful covered lookup, also on runtime ARRAY misses. Static size falls 1 B per known routine and 3 B per runtime routine; per-call effect unmeasured. |
| 12 | Generated read/LPM branches keep near encodings within short range | OTel demonstrated; other apps with these routines | Static local opportunities are 70 B in the captured user-read routine and 41 B in historical LPM. Instruction/branch counts stay the same; fetch/cache benefit and app installed-size effect remain unmeasured. |

Tetragon's prior native load failure is **fixed in the retained corrected-image
check**; it is discussed separately below. It should not be ranked as a
current failure on the basis of the earlier round.

## Flag-study issue: installed code has a second optimization policy

`kprog/x86/perf_context_lto.cpp:313–327` creates an aggressive-codegen target
machine and runs LLVM's O3 default module pipeline.
`perf_context_lto.cpp:381` runs O3 again after context/map lowering.
`kprog/libnativeloader/src/native_loader_context_lto.hpp:13–14` determines
which entries take that compiler path: PERF_EVENT entries always do; other
entries do when function bodies, immutable-global facts or map types exist.

Thus a P flag candidate such as O2 or Os is followed by a fixed O3 load-time
pipeline for those entries. P's frontend choices and function attributes
such as optsize/minsize can still matter; the candidate is not wholly
ignored. But its installed result is a combination of both policies, and
different entries need not undergo the same second pipeline. This matters
to interpreting the coordinator's current flag study and code-size results.
Choose/report the final LTO optimization policy together with P flags rather
than attributing the installed difference to P flags alone. The optimizer's
own runtime is load-time cost, not BPF per-call overhead.

`kprog/x86/link_embedded_ir.cpp:23–37` preserves sectioned entry roots and
links/writes their modules; it does not itself run an optimization pipeline.
Marking those roots external is not evidence that every root executes or
that all module functions are installed in each selected native image.

Source update, 2026-11-17T00:28:02Z: coordinator commit **a541c006d**
addresses the fixed-O3 issue. `vendor/bpf/Makefile:299–309` selects the
compiler's optimization-level macro from NATIVE_CFLAGS and tracks it in a
level dependency. `perf_context_lto.cpp:37–53,331–345,399` now uses that
level for both module pipelines and backend optimization. The study's
single-O-level O3/Os/O2 candidates are covered by this change. This review
confirms the source wiring; it does not claim a new compiler/image has
passed a run or assign this change a speedup.

One residual policy issue matters to the later candidates in
`../flag-tuning-20261117/tune.sh:18–19`: O3-branch adds
`-mllvm -x86-cmov-converter-force-all=true`, and O3-nounroll adds
`-fno-unroll-loops`. Only the O level is transferred by a541c006d.
`native_loader_context_lto.hpp:43–59` does not pass those options to the
compiler subprocess; `perf_context_lto.cpp:285–299` reads `.llvmbc`, not
embedded compiler command-line data, and line 340 constructs PassBuilder
with its default tuning options. LLVM18's local
`include/llvm/Passes/PassBuilder.h:59–60,124–127` documents default
LoopUnrolling as true.

Consequently the branch-converter process option does not reach this
re-emission path through the current option wiring. For no-unroll, explicit
loop metadata already present in P could still survive, so loss of the
requested effect cannot be concluded solely from the command line; inspect
that candidate's embedded IR/installed loop shape. Either way, changing the
O level alone does not establish that these later candidates control the
same final policies in recompiled entries. This is an interpretation and
implementation follow-up, not a reason to discard any completed sample.

Active-study correction, 2026-11-17T00:36:04Z: the retained live
`/workspaces/kprog-raw/flag-tuning-20261117/progress.log` records at
23:59:02Z that CMOV-branch and no-unroll were dropped on the operator's
instruction and the controller restarted with **ORDER=O3 Os O2**. The
script still lists other candidates, which led the previous note to call
them later study candidates. They are not in the active sweep. The residual
option-transfer concern above does **not** affect that sweep; it is relevant
only if those other policies are investigated later. a541c006d covers the
active sweep's optimization levels. No new build or option-transfer work is
needed for the dropped candidates.

## 1. Read lowering keeps work that constant-size specialization can remove

Source: `kprog/x86/native_lab/native_link/src/x86_probe_read.rs:28–38,
59–108,118–146,150–173`.

Update after c03737bf4 (2026-11-17): the coordinator has replaced the
byte-only remainder with 4/2/1-byte steps. Source inspection confirms the
new load-site lengths are 2/3/3 bytes and recovery still clears/tests R11.
The older retained disassembly and path counts below describe the
pre-change output. Constant-size specialization, the five-save frame and
per-read SMAP selection remain separate opportunities; no current-image
gain is inferred from those historical counts.

Each lowered read enters one shared routine for its helper kind. It saves
RBX and R12–R15, copies its three arguments, checks the address policy,
calls `nmi_uaccess_okay` or `copy_from_kernel_nofault_allowed`, and changes
pagefault nesting. User reads additionally load `boot_cpu_data`, test its
SMAP bit and retain the result in R15b; cleanup tests that result again.
The ordinary copy uses an 8-byte loop followed by a byte loop, with a fault
status test/branch after each source load. Size is a live argument to this
routine; `share` only groups relocation targets and never uses a proven
constant size from the call site.

Concrete output: the successful 68-inner-ARRAY-site OTel replay's
`/workspaces/kprog-raw/perf/20261116-inner-array-lto/libbpf/otel-typed.blob`
has the 326-byte user-read routine at [0x743a,0x7580). The committed
[disassembly](typed-unwinder.disassembly.txt) shows five pushes at 0x743a,
the capability load/test at 0x7487/0x7491, and the 8-byte loop at 0x74c1.
This is a host-linked payload; its external E8 slots still need kernel
relocation. It is not a new timed run.

Kernel comparison:

- `vendor/linux-framework/mm/maccess.c:29–51` handles kernel reads with
  8-, 4-, 2- and 1-byte pieces. A four-byte read need not execute four byte
  load/status/store iterations as the native routine does.
- `mm/maccess.c:120–136` performs the user range/NMI/pagefault checks too.
  These checks are part of the reference semantics, not native-only waste.
- `arch/x86/include/asm/uaccess_64.h:119–135` selects rep-movsb versus its
  alternative and uses STAC/CLAC. `arch/x86/include/asm/smap.h:18–22,40–47`
  selects those instructions through boot alternatives; it does not load
  and test `boot_cpu_data` on every copy.
- `kernel/trace/bpf_trace.c:173–180` zeros the entire destination after a
  failed read. The native fault path must continue to do so.

Expected change: specialize the frequent small constant lengths using real
call-site facts, add 4/2-byte tails, and select feature-dependent instruction
forms from trustworthy facts about the booted kernel. Host CPUID alone is
not that fact. Keep generic shared routines for other sizes and preserve
range/NMI policy, pagefault nesting, exception recovery and failure zeroing.
Do not assume that all five saves can disappear: policy calls still clobber
caller-saved registers. Any leaf/smaller-save version needs its actual ABI.

Why first: the retained OTel shared-hash diagnostic reports 2,393.348
user-probe text cycles per app call, versus only 9.365 kernel-probe text
cycles. Its counter times are 4,156.394 ns JIT and 5,286.145 ns native.
These are the old 6641a7e1 diagnostic, before the later lookup fixes, not
the current image's cost split. See
`../shared-hash-regression-20261116/otel-shared.costs.json` and raw
`/workspaces/kprog-raw/perf/20261116-shared-hash-regression/otel-shared/`.
Cycles are not nanoseconds; external roots lack exclusive caller ownership,
and the remaining program-text bucket is not pure arithmetic body. The
profile locates an opportunity, not a promised percentage reduction.

Follow-up, 2026-11-17T00:23:40Z: the same retained blob contains 24 direct
calls to this user-read routine. In the two preceding decoded instructions,
all 24 have a visible `mov esi,constant`: 16 use 8 bytes, four use 16 bytes
and four use 144 bytes. The intervening instruction, when present, is a
move that does not write RSI. Exact windows and offsets are in
[read-call-sites.disassembly.txt](read-call-sites.disassembly.txt), with
counts in evidence.json. These are local instruction patterns, not a full
CFG proof or dynamic read-size distribution. They make an 8-byte shared
specialization a concrete first candidate; unrolling the 144-byte case
would have a different code-size tradeoff. The missing 4/2-byte tail is a
general weakness but does not apply to these 24 literal sizes.

There is a second implementation constraint: the existing constant analysis
cannot simply be reused unchanged for this unwinder.
`x86.rs:1119,1469` computes `memory::constants` and consults it for memory
routines. `x86_memory.rs:155–162` returns an empty result for the entire
function if **any** indirect branch exists, without accepting the resolved
jump-table destinations already used by helper/map provenance. The retained
typed-kernel log shows `jmp rax` at 0x09f9 and `jmp r9` at 0x0ca3, among
others. A resolved switch therefore erases constants even at an adjacent
literal-size read in the same function. Expose the specialization while its
IR facts are available, or use the resolved CFG for the existing analysis;
do not infer safety from this local-window extraction. This is another
reason why merely adding a read case to `memory::Routine::at_call` would
not deliver the expected OTel benefit.

Read-path detail, 2026-11-17T00:36:04Z: the decoded successful-copy region
0x74b8–0x74eb has two prefix instructions, nine instructions per 8-byte
iteration, then two suffix instructions when no byte tail remains. For
the three observed literal sizes this gives:

| Literal bytes | Word iterations | Copy-region instructions | Conditional branches |
|---:|---:|---:|---:|
| 8 | 1 | 13 | 4 |
| 16 | 2 | 22 | 6 |
| 144 | 18 | 166 | 38 |

This is a static path count from the retained disassembly, **not** measured
retired instructions, cycles, branch misses or dynamic size frequency. It
excludes entry/policy calls, pagefault/SMAP work, return/error handling and
their callees. evidence.json derives it from those exact decoded windows.
For constant 8/16-byte copies, indexed fixed-offset loads/stores can avoid
pointer increments, size decrement/comparison and loop selection. For the
144-byte copy, kernel `copy_user_generic` already selects a boot-patched
bulk-copy path; retaining that implementation may beat growing a long
unrolled native body. This tradeoff needs its actual app measurement.

The fault-status tests are a different category from loop overhead. The
retained ABI has `load_site 29889,3,11` and `load_site 29932,3,11`, matching
the word/byte source loads at 0x74c1/0x74ec. Their x86 instruction destination
is RAX, but the sideband **recovery** register is deliberately R11.
`x86_probe_read.rs:75,92–105` initializes R11 to one and tests it after
each load. `kprog/perf/direct-native/bpf_x86_native_lab.c:345–352,387–392`
maps that register number into pt_regs; the unchanged kernel's
`arch/x86/net/bpf_jit_comp.c:1481–1503,3825–3828` clears the selected
register and skips the faulting instruction. The test then reaches the
error path before a stale RAX can be stored, and that path zeros the whole
destination and returns -EFAULT.

Therefore do not delete the R11 test on the premise that the kernel already
zeroes RAX or that a zero loaded value signals a fault. Neither premise
matches this ABI. A constant-size specialization still needs the established
fault/error behavior, unless a source is actually proven nonfaulting under
the existing semantics. No kernel/module change or extra runtime check is
proposed here.

Constant-size implementation detail, 2026-11-17T02:02:53Z: the current read
routine uses R12 for the destination, R14 for the source, RBX for current
task/pagefault nesting, R13 for size and R15b for the user SMAP choice.
With a proven constant size, R13 need not retain a live size across the
policy callback. A kernel-read variant also has no SMAP flag to preserve.
Those two roles can disappear together, leaving three saved registers
instead of five. This is an opportunity in a specialized routine, not a
claim that the existing variable-size routine can drop its live operands.

Keep nested-call alignment explicit: SysV routine entry has RSP mod16=8;
five pushes or three pushes align the policy call, but four pushes do not.
Removing only one save needs another alignment adjustment and can lose the
expected size/instruction benefit. A user-read variant with dynamic SMAP
still needs its flag or equivalent lifetime; do not fold it from host CPU
identity. This is why blindly deleting an apparently unused push is not a
per-call optimization by itself.

Unrolled loads also need their own existing ABI metadata. The retained
`mov rax,[rsi]` is three bytes; `mov rax,[rsi+8]` has a displacement and a
different instruction length. Each LoadSite must retain its actual load
offset/length and R11 recovery register, rather than copying the loop's
three-byte record onto every unrolled word. Otherwise the unchanged kernel
would resume at the wrong byte after a fault. Preserve full-destination
zeroing and the original error return. No new runtime validation, metadata
format or fault handler is needed for these constraints. No specialized
routine was built or timed in this review.

## 2. Tracee's legacy read helpers get none of the read lowering

`x86_probe_read.rs:155` recognizes only `bpf_probe_read_user`,
`bpf_probe_read_kernel` and `bpf_probe_read_kernel_str`. It does not recognize
`bpf_probe_read_compat`, `bpf_probe_read_compat_str` or user-string reads.
Helper-name resolution is already corrected: the old public read aliases
resolve to the kernel compat functions rather than failing to link.

Evidence: [evidence.json](evidence.json) counts the **remaining** helper-call
relocations in the 169 Tracee captures listed in
`../host-link-replay-20261116/tracee-inputs.json`. There are 2,375
`bpf_probe_read`/`bpf_probe_read_compat` sites and 714
`bpf_probe_read_str`/`bpf_probe_read_compat_str` sites. Each slash separates
aliases of one target, not two calls. Retained per-entry copies of a common
callee may contribute multiple static sites; these counts do not measure
dynamic traffic. One example is
`corpus/results/shared-hash-regression-20261116/captures/link-04mya4zp/shared.relocs`,
offsets 0x300 and 0x16f respectively.

The JIT reaches the same compat helpers.
`kernel/trace/bpf_trace.c:286–293,305–312` chooses user versus kernel access
from the source address. Keeping the correct name fixed loading but did
not specialize this work. Extend the read optimization to this helper
family, or specialize a proven address domain and size at the call site.
Replacing all compat reads with kernel-only reads would change semantics.
Do not assume a byte-loop native string helper wins: the kernel's
`mm/maccess.c:86–104` kernel-string implementation is itself byte based,
while user-string copying has word-at-a-time handling in
`lib/strncpy_from_user.c:31–72`. Measure the particular matched helper.

This has broader Tracee coverage than improving only already-lowered kernel
reads. It remains an unmeasured optimization opportunity; static counts
cannot establish how much of Tracee's per-call time those sites consume.

Source/capture follow-up, 2026-11-17T00:28:02Z: compat-domain selection is
task dependent. `arch/x86/include/asm/page_64_types.h:59–67` defines TASK_SIZE
using the current task's TIF_ADDR32 flag and personality (IA32 limit versus
TASK_SIZE_MAX). A single boot-time USER_PTR_MAX comparison is not a
substitute for the compat helper's TASK_SIZE branch. An unknown source
pointer must keep that choice; a source proven to be current kernel-frame
storage gives a more specific case to optimize.

There are concrete small local-copy cases in upstream Tracee:
`vendor/bpf/tracee/pkg/ebpf/c/common/buffer.h:192` reads four bytes from the
local `rsize`, and lines 411/431 read a local four-byte `sz`; line 330 reads
eight-byte pointer elements. The retained `lkm_seeker_new_mod_only_tail`
blob also has a compat read at 0x300 preceded by `lea rdx,[rsp+0x50]` and
`mov esi,8`. Its compat-string call at 0x16f likewise uses that stack
source with size 64. The plan/relocation establishes helper identity; the
unpatched E8 displacement itself does not. See
[compat-read-sites.disassembly.txt](compat-read-sites.disassembly.txt).

These source and machine cases suggest specializing proven local-frame
copies before attempting to replace arbitrary user reads. Constant size,
source lifetime/bounds and fault/error behavior still need the compiler's
actual facts; this review does not prove that all local-looking reads may
skip their policy/fault handling, nor count their runtime frequency. The
call-site evidence supports the small-read direction without asserting
that every one of the 2,375 compat sites has the same shape.

## 3. A generic lookup pays for two failed specializers before its helper

`x86.rs:1802–1806` first rewrites generic lookup relocations to the runtime
ARRAY routine. `x86.rs:1816–1819` then rewrites the remaining generic lookup
relocation, which is the ARRAY fallback, to the runtime LPM routine.
`x86_runtime_array.rs:33–41` and `x86_lpm_lookup.rs:73–75` each use
`sub rsp,8; call; add rsp,8; ret` on their fallback.

The retained successful typed-unwinder blob proves the composition, not
just the source possibility: ARRAY starts at 0x73f7, its fallback CALL at
0x7430 targets LPM at 0x7580. LPM's final fallback calls the generic helper.
The range log and decoding are in [evidence.json](evidence.json) and the
disassembly. This persists even after the successful lowering of 68 inner
ARRAY sites; do not confuse this output with the initial zero-site attempt
at the parent raw directory.

A non-ARRAY/non-LPM lookup therefore pays two failed type selections, two
extra call/return pairs and four stack adjustments before reaching the same
generic helper. A known LPM shape whose name was recovered already bypasses
this chain; that fix is not a new opportunity here.

The verifier at `kernel/bpf/verifier.c:23878–23912` uses the actual map's
`map_gen_lookup`; at 23939–23948 it binds the concrete map operation when
inlining is unavailable. `arch/x86/net/bpf_jit_comp.c:2444–2460` emits the
resolved call. It does not add this ARRAY-then-LPM wrapper chain. Some
genuinely dynamic JIT sites still use the generic helper: the retained
Katran installed-call audit finds that on both arms, so not every lookup
has the stronger verifier specialization.

First choose the appropriate operation once when actual map/inner-type
facts prove it. Where they do not, avoid composing callable dispatchers as
a chain; preserve the real runtime choice in one path. The E8 fallback
shape is explicitly justified by the current loader ABI in
`x86_runtime_array.rs:38–39`, so changing it to an unconditional tail jump
without checking that contract is not a ready fix.

Expected gain is bounded by the executing sites. In the retained Katran
shared diagnostic, ARRAY and LPM ranges cost 3.360 and 2.500 cycles per app
call, respectively (`../shared-hash-regression-20261116/katran-shared.costs.json`).
These include useful dispatch work as well as fallback; neither whole
bucket is automatically removable. This is a concrete inefficiency, not
an explanation for a large Katran regression by itself.

## 4. ARRAY sharing prevents constant-key folding across the call

`x86.rs:1541–1546,3963–3998` emits a CALL to a selected ARRAY/PERCPU_ARRAY
routine with bounds and layout constants. `x86.rs:4001–4018` shares equal
machine bodies within a program. For dynamic proven-inner-ARRAY sites,
`perf_context_lto.cpp:190–193` explicitly marks the IR routine NoInline;
204–218 loads the key, bounds and mask. Lines 182–184 merge all selected
sites into one stride choice, so differing value sizes force that shared
routine to load the live stride even where individual sites have a size.

The kernel's `kernel/bpf/arraymap.c:219–249` emits ordinary ARRAY lookup
instructions directly into the caller: no ARRAY helper CALL/RET boundary.
It still emits bounds handling; it does not establish that every constant
key loses its check. Inner maps with `BPF_F_INNER_MAP` deliberately decline
this generator at 229–230 and retain the callable operation with live
capacity. Preserve those live bounds when optimizing inner maps.

The successful OTel host result is 30,410 payload bytes, including a
27-byte typed-inner routine; it selected 68 sites
(`../inner-array-lto-20261116/report.json` and README). For a proven small
constant key/stride, selective IR exposure could remove CALL/RET, stack-key
materialization and arithmetic. Grouping by proven stride can also retain
constant multiplication when other sites have a different stride.

Size tradeoff is real: sharing selected machine ARRAY bodies already saved
573 B in this unwinder, 1,088 B in V8 and 1,104 B in Katran host replays
(`../known-lookup-targets-20261116/README.md`). Do not inline all 68 sites.
Prefer cases that shrink after folding; compare final installed bytes and
per-call time rather than assuming more inlining is faster.

## 5. Provenance is much weaker than the verifier's across blocks

`x86_known_maps.rs:20–24` discards all facts for an unresolved indirect
branch; 26–40 clears register identities at every block boundary. Lines
49–75 track named absolute/GOT loads and full-width register copies, but
not stack spills/reloads, cross-block meets or callee map parameters.
`x86.rs:114–134` selects generic lookup when no exact identity survives.
`x86.rs:34–41,1581–1586` likewise binds update/delete only when RDI has a
proven name.

The loader already serializes actual named lookup shapes and update/delete
operation addresses at
`kprog/libnativeloader/src/native_loader_link_schema.hpp:145–167` and
`native_loader_link_plan.hpp:98–105`. Better propagation can use these facts
without adding a per-call check or changing module replies. The verifier's
map pointer state is available at the actual call (`verifier.c:23888–23903`),
rather than being erased just because it crossed a branch.

Retained unwinder analysis found 38 named and 72 dynamic sites among 110
static lookups. Later typed IR correctly handles 68 inner ARRAY sites;
that work is already done. Katran's six dynamic sites include a joined
cache choice and returned inner maps, not merely a lost single named map.
Their actual map identity must not be invented from call order, a truncated
name or one branch. Propagate a common **type** where identity is mixed;
carry identity only when every incoming value proves it. This finding
identifies a source limitation, not 72 still-unoptimized hot calls.

## 6. Finite helper selection is resolved late

`x86_helper_provenance.rs:40–59` retains finite numeric helper joins;
`x86.rs:3706–3737` emits a compare/JNE chain, a concrete helper call and
an exit jump for nonfinal alternatives. With N alternatives it may execute
up to N-1 comparisons. `verifier.c`/`bpf_jit_comp.c:2444–2460` resolve each
ordinary immediate BPF helper call directly; the frontend can leave the
original branch beside the individual calls instead of materializing IDs
and redispatching them.

The actual two-helper compiler fixture and Tetragon plan are retained under
`/workspaces/kprog-raw/perf/20261116-tetragon-helper-abi/joins/`, with the
correctness receipt in `../perf_20261113/numeric-helper-tail/README.md`.
Earlier IR propagation or branch threading may remove a repeated selection
and some materialization. This must preserve observed helper IDs and ABI;
an unresolved function pointer cannot be guessed. There is no production
frequency measurement here, so this ranks below the measured read/map
opportunities and is not a reason to replace the functioning finite-call
support.

## 7. Hash binding removes wrappers, but stops before key-length specialization

2026-11-17T00:46:15Z. `x86.rs:1550–1576,1799–1801` binds known hash
lookups to the shared raw kernel routine, with return adjustment and LRU/
per-CPU handling still in native text. This matches the verifier's
`kernel/bpf/hashtab.c:773–784` generated call. It saves duplicated code
and dispatch wrappers, but does not specialize the hash or key comparison
using the particular map's key length.

The exact length exists in the loader's `MapMeta.key_size`
(`kprog/libnativeloader/src/native_loader.cpp:1597–1604`). The lookup shape
builder at 2715–2734 instead carries the **rounded return offset**.
`native_loader_link_schema.hpp:40–49` and the linker's
`main.rs:141–150` have no exact key-size field. The IR-side
`perf_context_lto.cpp:55–60` likewise has type/inner-type and value sizes,
not key sizes. Thus changing P's optimization flags cannot constant-fold
the length inside the external kernel function it calls.

In that function, `hashtab.c:741–747` reloads `map->key_size`, hashes the
key, selects a bucket and compares candidate keys with that runtime length.
`hashtab.c:674–678` selects jhash2 for word-sized lengths, otherwise jhash;
`include/linux/jhash.h:117–140` loops and selects the remaining words from
that length. Both arms currently pay for this kernel algorithm. This is
one concrete reason why a smaller/faster P body can leave app per-call
time near 1.0x. It is not evidence of a native-only map regression.

Retained Katran plan shapes in evidence.json give vip_map return offset
72 and fallback_cache offset 88. Upstream `balancer_structs.h:26–40,62–69`
declares the usual x86 C flow/VIP layouts of 40/20 bytes, and
`balancer_maps.h:31–64` uses those types for the hash/LRU maps and inner
LRU template. The rounded offsets agree with those source shapes, but
**must not be inverted into exact key lengths**: several lengths have the
same rounded offset. Use the existing actual map/template fact when
implementing a specialization, not a guessed length from this plan.

The old copied routine is also not a separately compiled function for one
proven key length. Its first instruction loads the live key size, followed
by comparisons for 4, 8, 12, 16 and 20, then a generic word path and a raw
fallback. [hash-dispatch.disassembly.txt](hash-dispatch.disassembly.txt)
extracts that prefix from the retained 2,444-byte routine. It already has
special cases for those short lengths; the paired result therefore cannot
be described as testing only a byte-for-byte copy of stock kernel code.
Equally, its no-gain result is not a measurement of a 40-byte constant
specialization without runtime length dispatch. The original shared/copy
measurements remain unchanged and support keeping the current smaller
shared implementation until an alternative earns its size.

Expected opportunity is elimination of length selection/loop bounds and
unrolling exact-length key comparisons. Bucket memory latency, collision walking,
nulls-list retry on concurrent movement, hash seed and LRU marking remain.
No 20% or 50% gain follows from the source alone. The retained external hash
PMU roots have no exclusive caller ownership and cannot be treated as a
fully removable per-call budget. Any future variant must be shared where
the existing image/lifetime contract permits, with its installed bytes
counted; duplicating all 2,444 bytes per program would repeat the earlier
size problem. No new map query, runtime check, module or kernel change is
proposed by this review.

## 8. Constant tail slots retain the indirect tail-call path

2026-11-17T00:57:03Z. `x86.rs:1486–1522` sends every recognized tail call
to `build_x86_tail_call_inline`; it passes frame/cleanup facts, not the
map identity or a proven index. `x86.rs:3841–3874` zero-extends EDX,
loads/checks the live map bound, checks the tail count, loads the program
array slot, checks for null, loads `prog->bpf_func`, adds its tail-entry
offset and jumps through RCX. Even a constant slot uses all of this work.

The kernel verifier has a different path for a proven map/constant slot:
`kernel/bpf/verifier.c:23748–23768` records a tail-call poke descriptor.
`arch/x86/net/bpf_jit_comp.c:816–870,2466–2478` emits the direct form;
873–907 patches its target/bypass from the current program-array entry.
It retains the tail-count limit but avoids a live bound check and the
program/function-pointer loads on each populated direct tail transition.

This difference is present in actual installed code, not only in the
source. The retained 603cacfb442a packet-diagnostic capture pairs original
ID275 with native ID279, both named cil_from_contai, in one app load.
Original installed size is 1,093 B; native is 677 B. The original's tail
blocks at 0x2a7,0x316,0x413 retain the limit test then use a patched NOP
bypass and direct jump. Native blocks at 0x14e,0x257 retain the live map
bound, slot load, null test, function load and indirect jump. See
[cilium-tail.disassembly.txt](cilium-tail.disassembly.txt) and evidence.json.

The differing number of static blocks does not establish a path mismatch:
native IR can fold config branches. This capture's packet test timed out
before executing, and the original is a retained shadow FD whose shared
program-array entries may already target native callees. These dumps prove
the caller's code shape; they are not a completed paired-packet test or an
independent all-eBPF tail chain.

The earlier host emission also exposes actual constants: Cilium
`/workspaces/kprog-raw/perf/20261116-host-link-replay/emission-current/34-0/image.blob`
has literal slots 7,6,1 immediately before the native stubs at
0x217,0x2b9,0x3d7. Its image.maps binds their RSI immediates to cilium_calls.
The OTel sampling-entry capture
`corpus/results/shared-hash-regression-20261116/captures/link-6tuf3oq8/`
has a constant-zero slot before stub 0x8ed, bound to perf_progs. Its other
stub and the typed native unwinder's 0x5a17 stub use runtime index operands
in the retained windows; no full constant proof is provided for them. Do
not treat all tail calls as constant from these examples.

A bounded LTO-only improvement is to use a proven map and u32 index to
remove redundant bound/index work for an index known in range, while still
loading the **live** slot and keeping null handling, count and frame cleanup.
The loader already has MapMeta.max_entries (`native_loader.cpp:1604`), but
the retained cilium_calls lookup shape has max_entries=0. Existing machine
map provenance also returns RDI identities (`x86_known_maps.rs:43–46`),
whereas a tail call carries its map in RSI. Those facts must reach the
tail-site transformation; a call ordinal or the context's RDI is not a map
identity. The constant-analysis switch limitation described in section 1
also applies where the caller has resolved indirect branches.

Full direct-jump parity is a separate contract. Cilium/Tetragon/OTel can
populate or replace program-array slots after program load. The stock JIT
maintains its direct targets through poke descriptors and map-update
tracking; a one-time target address substituted by LTO would go stale and
could also outlive its target. Current native emission does not register
such descriptors. Do not cache the initial target, drop the count/null
semantics or change the frozen kernel to claim this optimization. The
source-supported constant-slot subset should reduce caller instructions
and bytes; its app per-call effect remains unmeasured. No new check, hook
or guest is proposed here.

## Tetragon: distinguish the fixed failure from the inventory question

The older `generic_kprobe_filter_arg` emission jumped outside its included
callee set: a conditional cross-function tail was omitted by a closure
that followed only calls and unconditional jumps. The actual failing proof
and fixture evidence are in `../conditional-tail-20261116/` and raw
`/workspaces/kprog-raw/perf/20261116-conditional-tail/`. Current
`x86.rs:481–534` discovers Jcc and JMP targets; the emission path handles
the conditional transfer. Commit 3940c4bee fixed this class.

The corrected 603cacfb442a functional check completed Tetragon with **288
native replacement events and zero native-load failures**, in its real
policy/CEL load context. See `../native-load-corrections-20261116/summary.json`
and `tetragon-inventory.json`. Thus the earlier load failure is not evidence
that another CEL or tail-call rewrite is currently needed.

Its measurement-window inventories are still 287 JIT versus 225 native;
35 versus 25 records have positive calls. The 63 loaded native IDs absent
from the window comprise 56 generic kprobes, six return probes and one
event_exit_disa. Successful loading does not prove equal work or zero
activity for the absent records. The read-only follow-up is FD/program-array
lifetime and counter-window identity; it is not a license to change the
frozen framework or filter programs. No new guest was run in this review.

Timeline follow-up, 2026-11-17T01:17:26Z: retained logs narrow this gap
substantially. Of the 63 absent IDs, **62 form a strict final load suffix**.
The latest native load represented in the window is ID788 at guest
monotonic 195.717379 s. Missing ID790 loads at 195.772010 s, and the suffix
continues through ID912 at 200.996473 s. The remaining absent ID336
(event_exit_disa) loaded much earlier at 160.155894 s and is a separate
lifetime/selection question. The repeated seven-size/eight-copy pattern
therefore need not imply a special failure of those function bodies.

Ten suffix programs have successful `BPF_TASK_FD_QUERY` attachment evidence:
sk_alloc return, __sk_free, tcp_set_state, two tcp_close instances,
tcp_create_openreq_child entry/return, tcp_connect, tcp_sendmsg and tty_write.
For example, native ID890 attached to tcp_sendmsg at 200.276279 s but is
absent from the window; baseline ID302 at that hook has 1,174,423 calls.
Hook matches can be nonunique across policies and are not a one-to-one
program equivalence proof. Exact load times, IDs, attachment types and
baseline hook records are in [tetragon-timeline.json](tetragon-timeline.json).
These are not ten failed native installations or ten proven-zero programs.

The frozen startup path explains why startup timing is a strong lead:
`runner/libs/app_runners/tetragon.py:35–42` explicitly requests zero stable
time and a minimum of 100 tracked programs. `runner/libs/rejit.py:369–373`
returns on that count; it does not wait for the remaining policies.
`rejit.py:459–470` then runs the configured warmup, starts measurement,
runs the samples and finishes measurement. This check used one ten-second
warmup and one ten-second sample, while the native first-to-last load span
alone is about 40.85 seconds. Baseline and native can consequently have
different policy exposure in a short functional window.

This is **not** a fixed-start-list explanation: the current shim at
`bpfopt/shim/shim_measure.h:99–108` already includes programs registered
after measure_start, using zero initial counters. Its start/finish queries
also synchronize with native loading (48–74,94–104). A program still alive
and tracked before finish is not intentionally excluded merely for loading
after start. The ordered suffix and late attachment evidence are consistent
with measurement ending while sensor loading continues; the exact
measure_start/finish request timestamps are not retained, so the ordering
alone does not prove that timing explains every missing record. ID336
remains separate. This narrows the next investigation without claiming a
completed equal-work check.

Keep this run's raw counters and functional result. It is not an official
default-duration timing round, and no new delay, count threshold, exclusion
or benchmark change follows from this review. The planned full confirmation
retains its existing entry and settings. In particular, do not turn a short
check's 287/225 aggregate into a steady-state Tetragon speedup.

One source-side load-cost lead stays inside LTO: `link_embedded_ir.cpp:23–30`
makes every sectioned program entry external. The load-time compiler
selects F but runs both module pipelines and code generation on the entire
module (`perf_context_lto.cpp:318–345,399–404`), without first internalizing
unselected roots. Selected-program native linking trims reachable machine
code later. Thus the source pipeline can repeatedly optimize/emit other
public entries while preparing one program. Internalizing unselected roots
and retaining the selected reachable/address-taken closure is a possible
way to reduce that load work; callback tables and injected functions must
remain reachable. No compiler timing or gain for that change is established
here. It would target setup CPU and completion time, not directly improve
per-call execution after startup, and it avoids inventing another readiness
gate in the frozen launcher.

Existing-module evidence, 2026-11-17T01:32:49Z: the staged Os OTel P,
mtime 01:03:02Z, is 2,948,472 bytes and has 30 executable function sections
totalling 413,855 stage bytes. Its embedded frontend IR contains **347
function definitions and 30 sectioned program roots**, including both
perf_event and kprobe unwinder variants. Those root definitions have
external linkage in the IR even where the ELF machine symbol is local.
`otel-os-module.json` records section/function names, sizes, root IR headers,
ABI/size attributes and file metadata; no file digest was generated.

This makes the multi-entry load-cost lead concrete: selecting one symbol
does not first restrict either module optimization pipeline to that symbol's
closure. Unselected external roots remain live. It does not mean all 347
definitions become machine functions: LLVM can inline/delete internal
helpers. The later native-link extraction selects the reachable machine
closure; the retained older O3 unwinder replay reports only two reachable
symbols. That older replay and this Os stage are different artifacts, not
a before/after size or compiler-time comparison. No 30x speedup or measured
load-time saving is inferred from the root count.

The reader `module_inventory.py` uses readelf and LLVM disassembly of the
existing in-memory bitcode section; it builds and executes no program. Its
first attempt incorrectly used an objcopy dump path of /dev/stdout, which
replaced the device link with a regular bitcode file and gave llvm-dis an
empty pipe. The device link was restored to /proc/self/fd/1 before the
successful retry. The failed metadata is `otel-os-module.failed.json`;
the extracted output and recovery record remain under
`/workspaces/kprog-raw/perf/20261117-lto-module-review/`. Already-open stdout
FDs were unchanged, while an explicit pathname open during that interval
could have reached the file. The corrected script neither uses objcopy nor
writes a source/object/bitcode copy. It finished successfully in about
0.05 seconds. No benchmark/build was started or coordinator process
signalled by this review.

ABI inheritance was also checked rather than presumed missing:
`kprog/x86/runtime_bpf_callee.hpp:43–50` copies target CPU/features,
tuning/frame attributes and NoRedZone from the selected entry into imported
callee definitions. The Os P's program-root attribute groups retain
NoRedZone and optsize. The generated typed ARRAY helper sets only NoInline/
NoUnwind (`perf_context_lto.cpp:208–211`), but its retained 27-byte body is
register-only. These observations do not establish a current SIMD or
red-zone failure; no new ABI check or compiler flag is proposed here.

## Existing work that should stay, and attribution limits

Entry-wrapper coverage, 2026-11-17T02:02:53Z: another reviewed candidate was
the 18-byte SysV wrapper at `x86.rs:1080–1102`, used to preserve entry tail
transfers. In the 239 retained host-emission outputs, its exact opcode
prefix occurs in zero entries: BCC 0/25, Cilium 0/28, Katran 0/1, OTel 0/14,
Tracee 0/169 and Tetragon 0/2. The existing conditional-tail `choose.blob`
fixture does contain that prefix, so the shape being counted is present
in a real emitted output. Counts and fixture prefix are in evidence.json.
This does not cover differently encoded wrappers or the later Tetragon CEL
loads; it is not evidence that tail support is dead. It is a reason to put
speculative wrapper removal below the read/map/tail-slot findings with
actual app-code evidence. A wrapper CALL followed by a helper tail jump
also must not automatically be counted as two helper CALL/RET pairs.

- Shared kernel hash: `x86.rs:1799–1801` uses the shared raw kernel routine;
  `x86.rs:4034–4073` retains null/value/per-CPU/inner-map/LRU postprocessing.
  The LRU reference-bit store remains at 4045–4050, matching the kernel's
  LRU JIT generator (`kernel/bpf/hashtab.c:788–838`). The retained shared/
  copied diagnostic is 204.532/205.781 ns per Katran call, with
  10,546/12,995 installed B. OTel's time-control-adjusted copy advantage
  was only 1.0096x for 26,939 extra B. Those observations support keeping
  sharing, not removing reference work or duplicating the hash again.
- Known LPM lookup binding and the loader's wanted-name cache are fixed
  already (25ee76410/e8960af11/a53922beb). The old OTel LPM bucket of
  4,333.540 cycles/app call cannot be presented as a current-image cost
  after that binding change.
- Cilium cb/frame and duplicate saves already changed in ed85c9c02 and the
  sole kernel. The 603 check no longer has the per-packet native host path:
  native cil_to_host/from_host recorded zero, while the JIT's two calls
  were one-off. This is diagnostic path evidence, not the still-unfinished
  paired packet comparison or proof that every packet matches.
- Loader BTF parsing, plan construction/serialization, hashing/caching,
  symbol resolution, `main.rs` orchestration and the two LLVM pipelines
  themselves run at load time. They do not explain ongoing per-call cost.
  The relevant review boundary is what they leave in the installed image.
- `x86_memory.rs` already folds supported constant lengths and shares
  generated routines. The claim that all native memcpy calls remain
  generic is false. Similarly, immutable scalar globals are already folded
  at `perf_context_lto.cpp:223–255`; no aggregate-layout relaxation is
  justified by this review.

Reproduce the lightweight extraction with
`taskset -c 16-19 python3 kprog/results/lto-review-20261117/evidence.py`.
It reads retained plans, relocations and blobs, then writes only derived
evidence in this directory. It neither executes native code nor establishes
a performance result. Full raw captures remain under /workspaces.

## Os load failures: private string pools cross the wrong layout boundary

2026-11-17T02:26:35Z source review at fbbe797ef. This finding concerns
pipeline correctness before any per-call optimization. The coordinator's
Os run `x86_kvm_corpus_20261117_013735_779007` ends during Tracee startup.
Its `details/shim-logs/tracee__monitor.post_rejit.log:519` records an ARRAY
map named `.rodata.str1.1` with a 246-byte value. Lines 929–933 record two
loads of kernel name `trace_ret_vfs_w`, 6,288 instructions, each failing
with `native data symbol .L.str.6 exceeds BPF data map value_size for
.rodata.str1.1`. There are 79 preceding native replacement events in this
log, rather than a successful whole-app native phase. The 15-byte kernel
name does not distinguish the four upstream `trace_ret_vfs_write*`
symbols; the full failing ELF symbol is not established by this receipt.

The source explains the class. At
`kprog/libnativeloader/src/native_loader.cpp:2934–2955`, the native data
section name selects the original loaded map. Ordinary globals bind by
BTF variable name, but `SHF_STRINGS` sections keep the **native** symbol's
section offset. Lines 2957–2968 compare that offset and native symbol size
with the **eBPF** map's extent and bind its address. Those two compiler
literal pools have no shared offset contract. By comparison, the sole
kernel tree's `tools/lib/bpf/libbpf.c:1983,2009–2010` builds the original
map from the original section's size and bytes; its data relocation at
6380–6382 uses that object's symbol offset. No native pool layout enters
the JIT arm. The observed exception proves an extent mismatch, without
retaining the exact Os symbol offset in this log. In-bounds offsets can
also name different bytes; removing the existing bounds refusal would
leave that correctness problem unresolved.

The ordering matters for remediation. `native_loader.cpp:4154–4160`
extracts the P entry and binds these symbols **before** calling the
context LTO compiler at 4190. It binds them again at 4197–4204 if LTO
returns a new object. A private-pool rename introduced only by the
load-time compiler would arrive after the first failure. Also,
`native_loader_entry_data.hpp:24–27` collects every named proof symbol;
being defined in the proof does not by itself exempt a private literal
from the original-map binder. The existing native readonly-data machinery
(`native_link/src/x86_readonly_relocs.rs:5–6,287–306`) is relevant, but its
presence alone does not prevent this earlier binding.

The forward correction needs to distinguish compiler-owned immutable
literals from source globals whose identity and actual loaded map values
must be preserved, at both binding stages. Private literal bytes can stay
with their native image; program-visible configuration/global data still
needs canonical source-map binding. This is a coordinator implementation
finding, not authorization to edit the frozen loader core. It adds no
check and makes no speedup claim: its immediate effect would be allowing
the Os Tracee native phase to load correctly. Installed bytes and per-call
time for that successful phase are not available from this failed run.

BCC Os is a separate unresolved failure. Run
`x86_kvm_corpus_20261117_012030_406547` retains baseline completion and
outer Make exit 255, with no result or app JSON. Its native shim log has
22 replacement events, zero `native-loader failed` events, and ends at
line 506 with a successful `LINK_CREATE`. This bounds the observed
progress; it does not identify a panic, OOM or LTO/helper defect. Neither
the BCC log interval ending 01:25:30 nor Tracee's run starting 01:37:35
falls inside the separately documented 01:29–01:31 stdout-path incident.

The committed reader `flag_failure_inventory.py` reproduces these counts
and selected events in `flag-failures.json` from retained logs, on CPUs
16–19. It executes no guest or compiled native code. The stage objects
have since been replaced by the coordinator's O2 build, so this review
does not attribute the current stage object's offsets to the Os run.

### Literal ownership can be separated in the initial proof

2026-11-17T02:35:29Z follow-up at 5a8ab9942. An open-path implementation
direction exists before the frozen binder: the selected-entry proof.
`native_link/src/x86.rs:2206–2216,2245–2250` copies a named PC32 data
target into `ProofReloc.data` while retaining `target_name` as its symbol.
`main.rs:687–705` puts those bytes in `.native_link_rodata` and emits a
defined symbol with that same name. The loader's entry inventory collects
defined and undefined names together (`native_loader_entry_data.hpp:24–27`);
its membership test at `native_loader.cpp:2901` therefore lets the P's
private `.L.str.*` symbol reach map binding even though the proof already
owns a copy of the bytes.

For compiler-owned literals, a proof-local identity would separate these
two roles without a loader-core edit. The proof emitter already uses a
synthetic `section:...` identity for anonymous data (`x86.rs:2202–2204`).
Extending that existing ownership convention to named private literals,
with their proof relocations using the same identity, would leave the
original `.L.str.*` name absent from the binder's selected-name set. This
would apply to both the initial and post-LTO proof. Source-global and map
identities must stay intact: renaming every defined data symbol, or using
`ProofReloc.data.is_some()` alone to decide ownership, would also affect
logical globals. This is a source-derived implementation direction for
the coordinator, not a linked or guest-tested patch.

Clarification to the preceding concern about in-bounds binding: that
address can select the wrong original-map bytes, but this review has
**not** established a runtime literal misread. For ordinary named PC32
literals, `x86.rs:2641–2658` already copies the P's own symbol bytes into
the installed blob. `x86_writable_data.rs:25–30` selects mutable/undefined
resources, excluding these defined readonly strings from its map-address
rewrite. Thus the observed load refusal does not by itself prove that the
native program would read the wrong bytes on this path. Keeping literal
ownership coherent removes unnecessary binding work at load time; it
does not establish a per-call speedup or installed-size reduction.

One related coverage edge should not be mistaken for the observed Os
failure: object 0.36 classifies allocated `SHF_STRINGS` sections as
`ReadOnlyString` (`src/read/elf/section.rs:630–631`), whereas
`x86_readonly_relocs.rs:5–6` accepts `ReadOnlyData` and `.data.rel.ro`.
Named positive-size literals take the copy path above regardless of this
predicate. The anonymous zero-size section-symbol branch at
`x86.rs:2624–2635` uses the predicate; supporting named strings alone
does not establish coverage of that separate relocation form.

Provenance receipt `literal-identities.json`, generated by
`literal_identity_inventory.py`, also prevents a misleading comparison.
The current O2 P was written at 01:55:50 on November 17. Its staged
`trace_ret_vfs_write_tail` and `trace_ret_vfs_writev_tail` proofs were
written on November 11 and name `.L.str.5`; the current P instead names
the 72-byte literal `.L.str.6`. These files are not a current input/output
pair. The stage retains 175 proof files totaling 2,032,296 B, while the
traced loader generates its own cached entry proof at 4154. The staging
recipe (`vendor/bpf/Makefile:484–497`) replaces native objects without
refreshing those proof files. They are stale build-output cleanup
candidates, not evidence of current literal identity or of a failed
load-time proof. No build output or raw data was removed by this review.

## 9. Two small helpers retain calls that the JIT removes

2026-11-17T02:44:47Z review at 93d17d3c5. This is below the demonstrated
read/map opportunities in priority: it removes call overhead at covered
sites, rather than a large helper body. The retained 239-entry host
emission inventory contains 121 external `bpf_get_current_task_btf` CALL
relocations across 109 distinct Tracee entry symbols, and 91 external
`bpf_jiffies64` CALL relocations across 13 Cilium entry symbols.
`helper_parity_inventory.py` reproduces these counts and bounded decoded
call windows in `helper-parity.json`. Shared source callees can recur in
different per-entry payloads. These are historical static sites, not
dynamic counts, unique source sites or a current-image performance result.

- **Current task, BTF variant:** `x86_probe_read.rs:180` recognizes only
  `bpf_get_current_task` for its wide GS-relative load. The BTF variant
  therefore falls through the selection at `x86.rs:1524` to an external
  helper call. Example: retained Tracee `cgroup_bpf_run_filter_skb` has
  a CALL at 0x22b whose relocation targets `bpf_get_current_task_btf`.
  Both kernel helper bodies return the current task pointer
  (`kernel/trace/bpf_trace.c:755–768`); their verifier return types differ,
  but the runtime pointer value agrees. The verifier explicitly inlines
  both (`kernel/bpf/verifier.c:24026–24041`), using the same current-task
  per-CPU address. Its eligibility condition is JIT plus per-CPU instruction
  support (18293–18302); the sole x86 JIT implements that support at
  `arch/x86/net/bpf_jit_comp.c:4087`. Reusing the existing same-boot current
  task lowering for the BTF helper closes this runtime-code gap without a
  new module reply or per-call check.
- **Jiffies:** the native helper name table recognizes ID 118
  (`x86.rs:205`), but there is no matching inline load. Cilium's retained
  `cil_lxc_policy` has the external CALL at 0x75a, followed by `shr rax,8`.
  The verifier replaces this helper with an address and 64-bit load
  (`kernel/bpf/verifier.c:23973–23995`). The helper itself just returns
  `get_jiffies_64()` (`kernel/bpf/helpers.c:394–397`), which is a read of
  volatile `jiffies` on this 64-bit kernel (`include/linux/jiffies.h:86,
  99–102`). Equivalent native lowering needs that variable's actual
  same-boot address; neither the helper's code address nor a cached tick
  value can substitute. Preserve a fresh volatile read at each call site.

No external `bpf_get_current_task` or `bpf_get_smp_processor_id` CALL
relocations remain in this inventory; the source already lowers those
two names. This finding extends that implemented coverage, rather than
proposing a second helper dispatcher. The likely per-call effect is one
less external CALL/return per executed covered site. It is not evidence
for a 20% app gain. Size also needs measurement: the current GS-load form
is 9 B versus a 5 B direct CALL, a local increase of 4 B per replacement
before other layout changes. A machine-only replacement also leaves any
caller spills that LLVM chose around the original call; removing those
would require exposing the load to the existing IR optimization. Neither
variant has been built or timed here. No source or optimization record
was changed, and the coordinator retains implementation ownership.

### Lookup chain: remove the internal boundary while preserving E8 ABI

2026-11-17T02:54:36Z follow-up to section 3, at 6353b4cad. The
loader-format constraint and the internal dispatcher composition are
separable. In the retained successful typed OTel blob, ARRAY's fallback
at 0x742c is exactly 14 B: `sub rsp,8; call 0x7580; add rsp,8; ret`.
LPM's fallback at 0x76bc has the same 14 B form, but its CALL at 0x76c0
still has the unpatched external helper slot. The first CALL's destination
is an image-local routine; the second needs loader relocation. The reader
`dispatch_inventory.py` records both spans in `dispatch-fallbacks.json`.
Its decoded destination for the unpatched external slot is only the
placeholder's next instruction, not the installed helper address.

The final external E8 requirement is real:
`kprog/perf/direct-native/bpf_x86_native_lab.c:250–255` accepts the exact
E8 slot for relocation kind 1. Changing that slot to E9 would fail this
existing ABI. In contrast, `runtime_array::share` has already resolved
the callers into the image before `lpm_lookup::share` resolves ARRAY's
fallback (`x86.rs:1802–1818`). The internal ARRAY→LPM edge does not need a
helper relocation in the final image. It need not retain an E8 boundary
merely because the final external edge requires one.

A combined dispatcher can retain ARRAY's success/NULL return and put the
LPM body directly at its other-type destination. That deletes the first
14-byte fallback wrapper rather than leaving unreachable instructions.
An internal E9 instead of adjacency replaces those 14 B with 5 B. These
are local emitted-byte differences, not a measured installed-image size
change; branch layout, routine placement and all affected relocation and
fault-site offsets still have to be emitted consistently. The final LPM
fallback keeps its existing aligned E8 call and return. ARRAY and LPM
prefixes use caller-saved registers without allocating a stack frame;
entering LPM at ARRAY's original RSP preserves its call-entry alignment
and lets its success return directly to the original lookup caller.
This is an internal function handoff, not a BPF program tail call: no
tail counter or program-frame transition is involved.

This narrower change removes one call/return pair and two stack
adjustments when ARRAY falls through to LPM, including a non-ARRAY,
non-LPM lookup. It retains the actual map-type selection, live bounds,
index mask, LPM semantics and final generic helper. It introduces no
pointer cache, new check, loader format or module change. It also leaves
one extra wrapper boundary relative to a direct generic helper call;
the broader link-time type/operation selection remains preferable when
actual facts prove the map shape. The retained 3.360/2.500-cycle Katran
ARRAY/LPM buckets already cited in section 3 bound the opportunity in
that diagnostic; they are not two wholly removable costs. This is a
source-derived implementation direction, with no generated candidate,
guest run, per-call gain or installed-size result claimed here.

## OTel O2: the large time change still needs an unwind-path explanation

2026-11-17T03:07:52Z review at 20786f06d. The newly committed O2 study
row (d2a96a706) reports 1.849x throughput and 11.565x per-call speedup.
The raw entry counters below retain that observation rather than
interpreting it as an established equal-work improvement. The comparator
Os row is from the same study, not a paired isolated LTO change.
The coordinator's 02:59 decision attributes the O2 result to missed
context conversion/unequal work and keeps uniform O3. This receipt records
the observed counters; it does not independently establish the missing
load or unwind-attempt values behind that diagnosis.

| Candidate and arm | Entry calls | Entry time, ns | ns/call | Installed entry bytes |
|---|---:|---:|---:|---:|
| Os eBPF | 129,570,118 | 440,658,774,440 | 3,400.9 | 3,815 |
| Os native | 123,498,235 | 393,095,963,329 | 3,183.0 | 3,362 |
| O2 eBPF | 138,518,973 | 445,085,206,992 | 3,213.2 | 3,815 |
| O2 native | 144,264,207 | 40,081,168,617 | 277.8 | 3,427 |

`otel_flag_inventory.py` reads these from runs
`x86_kvm_corpus_20261117_010914_990572` and
`x86_kvm_corpus_20261117_020132_158734`, preserving exact fields in
`otel-flag-paths.json`. Each native shim log has 14 replacement events and
zero loader failures. Entry invocation counts and the small code-size
change do not identify what work happens inside those invocations.
Neither retained details directory contains the collector-8888/6060
scrapes used by the earlier equal-work investigation. No unwind-attempt
value is inferred from their absence. Tail-program `run_cnt_delta` is
also not a substitute for the application's unwind counters.

There is a concrete context-pass coverage question to investigate,
without claiming it caused this run. `perf_context_lto.cpp:345` optimizes
first, then 363–366 selects only entry-function `LoadInst`s whose
`getUnderlyingObject` equals the entry argument. LLVM 18's
`Analysis/ValueTracking.h:674–690` documents that the single-object utility
strips GEPs/casts, whereas the plural utility additionally traverses PHI
and select nodes. A load through a mixed context/local-buffer pointer
can therefore be omitted from this selection. Memory-intrinsic sources
and surviving callee accesses are outside this direct-load loop too.
The later dynamic-offset exception at 372 only sees loads already
selected; it does not cover the omitted uses. Adding a refusal for them
is not the remedy requested by the operator.

OTel has both context and local register views in its actual source:
`tracemgmt.h:683–701` either copies kernel-stack registers into a local
buffer or reads the context registers. It then reaches state-copy code
at 584–605. A complete lowering must preserve that distinction under
optimization. It must also preserve the original physical context for
`bpf_get_stackid` and BPF tail-call operands (`tracemgmt.h:747,774`), as
the pass already intends at 386. Replacing every context argument with
the dereferenced register pointer would break those helper uses.

One tempting diagnosis was ruled out by inspection: the current O2 P's
frontend IR gives `collect_trace.100` and `get_usermode_regs.109` the
`alwaysinline` attribute, and the P's machine entry already contains their
inlined work. Merely observing frontend calls to those functions does not
establish a missed-inlining defect. The optimized post-context object
and OTel's own unwind/error counters from this run are not retained here,
so neither an omitted PHI load nor a broken tail transition is asserted
as its cause. The coordinator owns that implementation/diagnostic work.
No guest, optimizer/code-generation invocation, source change, new check
or benchmark change was introduced by this review.

### New remainder path: short-read gains and the zero-remainder cost

2026-11-17T03:18:29Z, source c03737bf4/31aadd99c. The new 4/2/1 remainder
is useful for short reads, but the general multiple-of-eight path now
also visits the `cmp ecx,4` and `cmp ecx,2` selections before reaching the
existing zero test (`x86_probe_read.rs:100–117`). The successful copy paths
below compare the previous real OTel user-read emission with the
coordinator's already-emitted 03:03 host user-read fixture. No code was
built or executed for this comparison.

| Size, B | Previous copy instructions | New copy instructions | Previous conditional branches | New conditional branches |
|---:|---:|---:|---:|---:|
| 2 | 20 | 15 | 6 | 5 |
| 4 | 36 | 15 | 10 | 5 |
| 8 | 13 | 17 | 4 | 6 |
| 16 | 22 | 26 | 6 | 8 |
| 144 | 166 | 170 | 38 | 40 |

These counts stop before the success XOR and exclude saves, address
policy, SMAP, pagefault nesting and cleanup. They assume every source
load succeeds; they are neither cycle counts nor evidence of a measured
app regression. At a zero remainder, two extra comparisons and branches
account for the four-instruction difference. The old user routine is
326 B; the captured new fixture is 380 B, a local 54-byte increase.
This is not an installed-image comparison.

The earlier retained OTel emission has 24 nearby literal-size sites:
16 of 8 B, four of 16 B and four of 144 B. Those observed sizes all take
the zero-remainder path. Their dynamic frequencies, and whether every
current O3 P has the same sites, remain unmeasured here. Conversely,
BCC's current `runqlat` P includes 4-byte kernel-read sites, for which the
new remainder removes the old byte-loop work. This supports retaining
the short-read improvement and prioritizing proven constant-size paths,
especially multiples of eight, rather than undoing it. Compile-time
specialization can omit a proven empty remainder without adding a
runtime check. It remains subject to the existing fault recovery and
code-sharing constraints in section 1.

`remainder_path_inventory.py` records decoded instruction fragments and
the path arithmetic in `remainder-paths.json`. An explicit `--capture`
read preserved the existing fixture's instruction bytes, load-site data
and decoded instructions under
`/workspaces/kprog-raw/perf/20261117-remainder-review/user-fixture.json`.
Default replay reads that persistent capture, so the evidence does not
depend on the fixture remaining under /var/tmp. No second executable
build, guest, source modification or deletion was made.

## Pipeline inputs: included headers are missing from build prerequisites

2026-11-17T03:35:56Z source review, including the coordinator's O3 cleanup
now published as 5a6941d73. This is a build-correctness
finding, separate from per-call code. It can leave the measured binary
unchanged after a relevant source change; it does not add work on each
invocation.

`vendor/bpf/Makefile:292` lists only `perf_context_lto.cpp` as the staged
context compiler's prerequisite. That C++ file directly includes
`native_loader_lto.hpp`, `bpf_function_bodies.hpp` and
`runtime_bpf_callee.hpp` at 21–23. The published pre-cleanup rule at
1036df3ad:307 also omitted these headers, while additionally depending on
the optimization-level file. If the compiler output is newer than its
`.cpp`, editing an included header alone does not make this target out of
date. In particular, `native_loader_lto.hpp` is one of the open LTO
performance paths: its changes must reach the compiler that emits the
installed code, as well as the loader. No currently stale compiler output
is asserted here; this is a source-derived dependency counterexample.

There are two more direct omissions in P production. The Cilium object
rule at `vendor/bpf/Makefile:259` lists only its `.c`, but its command at
262 uses `core_flags`: that expands to `-include core-compat.h` and the
generated Cilium CO-RE answer header (160). Neither input is a prerequisite
of that rule. The OTel unit rule at 273 names its answer header and
`errors.h`, but omits the same included `core-compat.h`. BCC's rule at
242–243 already lists both inputs. A `core-answers` goal existing elsewhere
does not give the Cilium object a dependency on its generated header:
`native-cilium` at 358 depends on the objects alone. An outer recipe may
generate the header first, but a later header change still does not
invalidate this object's rule.

The just-observed stale-P incident is related but distinct. The study's
`tune.sh:29–31` deletes native build outputs before each command-line flag
candidate. The first probe-tail `run.sh` did not do so when returning to
default O3. The coordinator recorded at 03:26:28 that five apps retained
the O2 group's stage executable sizes and stopped that series. Commit
1036df3ad's `run2.sh` removes those rebuildable outputs before the new O3
image. Its old runs remain raw evidence; they are not an O3 per-call
comparison. There is no reason to reopen alternative flag levels: the
operator has fixed O3.

The lean correction is to express the actual included project headers
and generated inputs in the existing producer/compiler build dependencies,
including the transitive inputs they use. No binary-admission validator,
new refusal, flag-study framework or runtime check is needed. The current
forced O3 rebuild repairs the retained flag outputs, but does not by
itself supply the missing header edges for later LTO/compat changes.
This review changed no source, touched no input timestamp, invoked no
Make/compiler target and interrupted no coordinator job. Per-call effects
and installed bytes belong to the source change once its actual rebuilt
binary is measured.

### User reads: SMAP selection and constant size share a register-save benefit

2026-11-17T03:46:21Z follow-up to section 1 at c55f8cdf6. The persistent
380-byte user-read fixture also exposes the cost of choosing the same boot
feature on every read. Its selection instructions are:

```text
0x04d movabs r11,boot_cpu_data
0x057 test   [r11+x86_capability_word],SMAP_bit
0x062 setne  r15b
0x066 je     after_stac
 ... copy ...
0x112 test   r15b,r15b
0x115 je     after_clac
```

The decoded fixture addresses are offsets, not installed helper addresses.
The six decision instructions occupy 40 B and include two conditional
branches. STAC and CLAC themselves are excluded: if the target kernel
requires them, they remain required. The new `smap_selection` receipt in
`remainder-paths.json` derives this count from the existing captured
instructions; no new instruction stream was generated or executed.
The real emitter's matching source is `x86_probe_read.rs:62–70,129–133`.

This reinforces an interaction between two existing opportunities, rather
than another standalone dispatcher. R15b's only role here is preserving
the feature choice; R13 preserves the dynamic size. A version with both a
proven constant size and a bound feature choice needs neither role. R12
and R14 preserve destination/source across the policy call; this emitter
uses RBX for task/pagefault state after that call. Keeping these three
registers gives a valid save frame, not a claim of minimum register use.
Three saves align the nested SysV call. Removing just R15 leaves four
saves and requires alignment work, so its isolated benefit cannot be
estimated by deleting a push/pop alone. The source must continue to
preserve every callee-saved register it writes, including on failures.
The 40 B is local decision code, not a net installed-image saving for a
completed specialization.

The fact belongs to the booted target. The sole kernel uses alternatives
for STAC/CLAC (`arch/x86/include/asm/smap.h:18–22,40–47`) and enables CR4
SMAP from its CPU capability decision (`arch/x86/kernel/cpu/common.c:377–385`).
That decision can include forced capability clearing (952–957); raw host
CPUID and the P compiler's `-march=native` cannot establish it. The guest
kernel's `/proc/cpuinfo` flags are themselves emitted from kernel CPU
capability data (`arch/x86/kernel/cpu/proc.c:104–107`), rather than being a
dump of the build host's compiler features. This identifies a relevant
target-side source of information; it does not establish an actual guest
SMAP value here or prescribe an unchecked substitute for boot_cpu_data.
Any specialization must bind its feature fact to the same target boot as
its helper/layout facts and retain it with the emitted-code inputs.

Range/NMI policy, pagefault nesting and load-fault zeroing remain required.
In particular, policy-denial paths currently bypass the STAC/CLAC and
pagefault-enable cleanup because they never entered that protected copy
region. Feature folding must preserve that control flow, while successful
and faulted copies still close the access region. This review supplies
instruction and ABI evidence for the already-ranked read work, not a
measured per-call gain or a proposed extra runtime check.

## 10. A known 668-byte zero-fill is emitted as a dynamic-length routine

2026-11-17T03:59:34Z review at 9a3a369f8. The memory emitter has a
specific information-loss point: `x86_memory.rs:31–35` takes the proven
RDX length, discards it when greater than 512, and then stores the
remaining value as `Option<u16>`. The 512 bound selects full unrolling,
but also decides whether the routine remembers any count. The separate
zero-byte fact survives at 36–39. This is an emission-policy cutoff, not
a program-load refusal or a proposed new limit.

The retained OTel entry host emission has two calls, at 0x12d and 0x2ce,
with `mov edx,0x29c; xor esi,esi` immediately before each. Both target
the same zero-fill routine at 0x1ad5. Its 98-byte body first selects a
32-byte loop, then an 8-byte loop, then tests the 4/2/1-byte remainder.
At 668 bytes, its successful path executes 20 iterations of 32 bytes,
three of 8 bytes and one 4-byte store: 190 helper instructions and 28
conditional branches including loop exits. The count includes helper
setup and RET, but excludes caller argument setup/CALL, surrounding
program work and cycles. The zero-fill stores themselves still do useful
work. These are static decoded path counts, not a measured cost.

`large_memset_inventory.py` preserves call windows, the helper decode and
path arithmetic in `large-memset.json`. It also records that the current
O3 producer P still calls `memset` with the same literal 668 in
`native_tracer_entry`. That P is not the post-context installed object,
so the historical 98 B and 190 instructions are not asserted as current
installed costs. In the source, trace reset and the custom-label clearing
loop are at `otel/support/ebpf/tracemgmt.h:220–265`. The corresponding
eBPF path executes the BPF memory operations emitted by its compiler;
the x86 JIT's ordinary stores are handled at
`arch/x86/net/bpf_jit_comp.c:2133–2150`. This native-link unroll threshold
does not govern that JIT path. No retained JIT instruction-count comparison
for this exact zero-fill range is claimed.

Keep a proven count independently of choosing full unrolling. A compact
counted loop can retain 20 bulk iterations and a known 28-byte tail,
avoiding the dynamic tail selection and preserving the actual zero-fill.
Simply raising the unroll cutoff would expose a code-size tradeoff;
arbitrarily large known lengths should not require fully unrolled output.
The two demonstrated calls currently share one body, so any replacement
should retain that sharing. If a program has mixed unknown/known lengths,
an additional specialized body has to earn its installed bytes. Preserve
the original destination return value and every required write; a zero
label count alone does not authorize deleting observable clearing.

This is below read/map work in priority. It adds a concrete large-count
example to the already documented memory-emitter coverage, rather than
claiming all native memcpy/memset calls are generic. No source change,
emitted candidate, executable run, input check or performance gain was
introduced here.

### Below the cutoff: repeated unrolled fills in Tracee and BCC

2026-11-17T04:41:13Z source/retained-output follow-up at dccc430b0.
The other side of the same policy is visible in real inputs:
`x86_memory.rs:96–103` emits every known size up to 512 as a straight
sequence of 8/4/2/1-byte operations. Above offset 127, `operand` at 13–23
uses a four-byte displacement for each store. `Routine` identity includes
the exact length, so the 200- and 368-byte zero fills remain separate
functions even within one linked program.

The existing 239-entry host replay logs list these input-function
definitions, after entry-proof construction but before the final link:

| App | Constant zero length | Distinct entry symbols containing it | Input function bytes each | Summed input-function bytes |
|---|---:|---:|---:|---:|
| BCC | 312 | 2 | 231 | 462 |
| Tracee | 200 | 115 | 133 | 15,295 |
| Tracee | 256 | 6 | 182 | 1,092 |
| Tracee | 368 | 108 | 280 | 30,240 |

The Tracee sum is 46,627 B across per-entry definitions. This is neither
the P stage's executable size nor an app installed-size total: the same
source helper can recur in multiple entry proofs, and the log sizes precede
final encoding. It is also not a count of runtime calls. The new reader
reports this provenance explicitly, rather than presenting the sum as
already removable native code.

One final emitted Tracee blob demonstrates that the large definitions
survive into output. `emission-current/301-0/image.blob`, entry
`cgroup_bpf_run_filter_skb`, has a 280-byte routine at 0xe7a with 46 qword
stores (368 bytes), and a 133-byte routine at 0xf92 with 25 qword stores
(200 bytes). They execute 49 and 28 instructions including their own RET
on a call, respectively. Each has one direct call site in this particular
blob. Both start with MOV RAX,RDI and XOR R8D,R8D; their stores use R8 and
the RET preserves the original destination result. Together they occupy
413 of the payload's 4,701 bytes. This is an actual historical output
range, not a current-image measurement or a claim that both calls execute
on every invocation.

`zero_unroll_inventory.py` retains the definition inventory, exact log
locations and this representative final disassembly in `zero-unroll.json`.
It reads existing files and decodes one blob; it does not emit or run a
candidate. The report's selection of lengths >=128 merely bounds the
inventory, and introduces no production threshold or load check.

The useful optimization class is to separate known length from code-layout
policy on both sides of 512. A compact bulk loop with a fixed tail can
retain exact counts for 200/368 as well as 668. Within a program, sharing a
bulk operation between different sizes is another size opportunity, but
requires preserving each call's count, destination result and all required
writes. Per-program sharing of an identical size already works and should
stay. No kernel routine, global cross-program code cache or new helper ABI
is proposed here.

There is an explicit speed tradeoff: these unrolled bodies have no loop
branches, so a compact counted loop adds instructions that the present
straight-line path does not execute. Smaller displacement/store code may
help the instruction cache, but that is not an established per-call win.
Do not lower the cutoff blindly, fully unroll arbitrarily large lengths,
or delete stores because a higher-level count happens to be zero. Keep
this behind the higher-priority read/map work and measure the affected
Tracee/BCC sites before claiming either speed or app code-size progress.

## 11. Cilium leaf programs retain eBPF despite existing native functions

2026-11-17T04:14:42Z review at e833763a2. The corrected O3 check finished
successfully for all six apps. Its load logs distinguish native replacements,
native-loader failures and no-manifest-match retention:

| App | Check run suffix | Native replacement events | Native-loader failed events | No-match retention events |
|---|---|---:|---:|---:|
| OTel | 033743_984421 | 14 | 0 | 0 |
| BCC | 034122_540932 | 25 | 0 | 0 |
| Cilium | 034447_636111 | 113 | 0 | 22 |
| Tetragon | 034829_591728 | 288 | 0 | 4 |
| Tracee | 035153_064790 | 169 | 0 | 0 |
| Katran | 035600_460257 | 1 | 0 | 0 |

These are load events, including repeated loads, rather than unique
program counts. They do not establish B generation/stock acceptance or
execution frequencies. The check's app status and absence of loader-failed
events do not mean that every application program was replaced.
`native_coverage_inventory.py` reads the existing logs and app results;
`native-coverage.json` retains each unmatched load, its returned program ID
and later program-array publications. No guest or build is involved.

The Cilium cases are eleven `tail_drop_notif`, nine `cil_host_policy`, and
two `cil_lxc_policy_` loads. The current stage manifest contains all three
names and its ELF files contain their native functions. Host
`tail_drop_notify` is 943 B; the LXC version is 699 B. The corresponding
policy stubs are 3 B. These are current P function sizes, not newly installed
native bytes or a byte-identity comparison of the check image's manifest.

The selector's object discriminator is the problem class:

- `vendor/bpf/Makefile:364–376` supplies `source_map_prefix=cilium_calls_*`
  for each host/LXC/overlay/wireguard object. The manifest writer applies
  this object attribute to program entries (`write_native_manifest.py:305–307,
  337–347`).
- `native_loader_manifest.hpp:626–630` rejects an entry unless the original
  program itself references that prefix. `source_has_map_prefix` at 514–539
  scans only that program's LD_IMM64 map-FD/map-value operands. It does not
  identify the object from a map which merely holds that program as a tail
  target.
- A two-instruction return-only policy stub cannot carry a map LD_IMM64
  plus its terminating EXIT. The source policy entries exist at
  `bpf_host.c:1855–1858` and `bpf_lxc.c:2560–2563`; their substantive bodies
  are conditional on HOST_FIREWALL/L7_LB. A stub's lack of map references
  does not make it a capability probe.
- `lib/drop.h:69–119` declares drop notification as a tail destination and
  writes its event through `cilium_events`; being called through a
  `cilium_calls_*` map does not require this leaf to reference that map.
  The named extension hook defaults to an empty macro at line 30.

The log proves these leaves are deployed as real tail targets. For example,
`034447_636111/details/shim-logs/cilium__agent.post_rejit.log:837–839`
loads `tail_drop_notif` (185 instructions), retains original program 214,
and returns FD 75. Line 895 installs exactly program 214 into
`cilium_calls_ho`, key 1, successfully. All eleven unmatched drop-notify
loads have successful key-1 publications: nine host/netdev instances and
two LXC instances (`cilium_calls_00` and `cilium_calls_02`). The receipt
preserves their IDs and line numbers. This is stronger evidence than
inferring purpose from program length. It establishes installation, not a
nonzero dynamic drop frequency or the cause of the separate Cilium host-path
difference.

`bpfopt/shim/shim_native_loader.h:316–319` explicitly keeps the original
BPF FD on a manifest miss. The needed correction is object selection for
leaf/stub programs using their actual load/object provenance or caller's
program-array relationship. Selecting the first same-name entry or deleting
all object scoping would be wrong: the host and LXC notification functions
are different. This finding requests no new refusal, probe exclusion or
runtime performance check. Implementation remains with the coordinator;
the selector and shim are in frozen paths.

Tetragon's four unmatched loads are unnamed LSM/3-insn, raw-tracepoint/11,
tracing/3 and socket-filter/18 programs (log lines 63, 85, 88, 816).
Their purposes remain unclassified in this receipt. The vendored feature
library does emit a three-instruction LD_IMM64-zero/EXIT probe
(`features/prog.go:24–35`), with LSM and tracing specifications at 159–168
and 92–101. That is a source lead, not proof of the exact logged callers;
the two other unnamed loads also need their own attribution. The shim's
sixteen explicit feature-probe skip events are counted separately and are
not silently combined with these four misses.

This is a phase-1 coverage finding ahead of further LTO attribution. No
per-call gain, installed-size saving or equal-work conclusion follows from
the load counts. Preserve the completed timing results and report their
actual replacement coverage alongside them.

### Tetragon unnamed loads: source attribution, 2026-11-17T04:20:30Z

The next source pass narrows the four unclassified misses above. Two of
the unnamed Go-generated programs have particularly specific source matches:

| Logged native-arm load | Best source match | Evidence and purpose |
|---|---|---|
| raw_tracepoint, 11 slots, Dual BSD/GPL; log 84–86 | `pkg/bpf/detect_linux.go:657–712`, `detectMixBpfAndTailCalls` | Creates a one-entry program array, loads a two-slot return program into key 0, then loads a program combining a local BPF call and helper tail call. Ten Go instruction constructors encode eleven BPF slots because LoadMapPtr occupies two. The source closes both programs and the map without attaching or running them. |
| socket_filter, 18 slots, GPL; log 815–817 | `pkg/sensors/map_update.go:13–73`, `UpdateStatsMap` | Looks up key 0 in a per-CPU ARRAY and atomically adds the caller's value. Thirteen constructors encode eighteen slots: five LD_IMM64 constructors occupy two slots each. It calls `prog.Run` with 20 bytes of input and then closes the program. This changes application state; it is not a capability probe. |

The first match also fits the exact preceding log sequence: unnamed
one-entry program array at 77–78, two-slot raw-tracepoint return program
at 79–81, successful key-0 publication at 82, then the eleven-slot load
at 84. `pkg/celbpf/celbpf.go:34–39` invokes this capability test through
`Supported`. It tests whether CEL's combination of BPF subprogram calls
and tail calls is supported; it does not establish a failure in installed
CEL functions.

The stats updater has a real application caller.
`pkg/sensors/exec/procevents/proc_reader_linux.go:138` invokes
`updateExecveMapStats(len(procs))` after populating the process map.
Lines 83–95 open the pinned `execve_map_stats` map and pass it to
`sensors.UpdateStatsMap`. The generated program's value is the number of
processes discovered during initialization. Its map lookup, atomic add,
return code and per-CPU selection must be preserved. Omitting it as a
probe would lose that update. This is separate from the named
`execve_map_upda` program loaded immediately beforehand; that named program
is successfully replaced by native program 350, while the unnamed 18-slot
program stays as original BPF program 351.

The LSM/3-slot and tracing/3-slot loads fit the program-type probes in the
vendored `features/prog.go`: 24–35 supplies LD_IMM64 R0=0 and EXIT; 159–168
sets GPL/LSM/AttachLSMMac/file_mprotect; 92–101 sets
tracing/AttachTraceFEntry/bpf_init with an empty license. Those metadata
match the log's GPL/attach-27 and empty-license/attach-24 cases. This review
has not independently mapped logged BTF IDs 71220/70809 to those target
functions. Both the eleven-slot and eighteen-slot metadata shapes also
occur once in the baseline arm, as do the two three-slot type probes.

`tetragon_unnamed_inventory.py` retains the source operation/slot arithmetic,
caller locations and both arms' load metadata in `tetragon-unnamed.json`.
No captured original instruction bytes or caller stacks are present in
this run directory. The metadata, ordering and source matches provide
attribution evidence; they are not exact-byte binding of the logged load
to its source. Current Tetragon manifest has zero empty-program entries.
These runtime Go instruction sequences have no selected native manifest
counterpart in this run.

The coverage correction is therefore more specific than “four failed
application programs” or “four feature probes”: three source matches are
capability tests and one is an application-state initializer. None is
shown here to be an event-frequency hot path. Filling native coverage for
the generated stats updater matters to the native-first requirement; no
measured per-call improvement is predicted from its setup-only source use.
Do not broaden name/length exclusions or count its B as generated/passing
without actual artifacts. The completed app and timing results stay as
recorded, with this coverage qualification and no added run gate.

## 12. Generated helper branches retain avoidable rel32 width

2026-11-17T04:26:36Z review at 011950744. The original native function
encoder already has branch sizing (`x86.rs:804–806`). This finding concerns
the separately constructed helper byte vectors, rather than all native
branches. `append_x86_jcc_rel32` at 3775–3779 always reserves six bytes;
`patch_x86_rel32` only fills its displacement. Probe reads use it for
copy, cleanup and fault branches, with unconditional five-byte E9 branches
from `x86_probe_read.rs:11–15`. LPM uses the same conditional emitter and
its own E9 builder. These routines are appended after ordinary function
encoding (`x86.rs:1627,1809–1819`); the later load-site decoder at 1905–1912
does not resize them.

The retained bytes contain internal branches which fit signed rel8 even
if only that one instruction shrinks. No candidate has been emitted:

| Existing routine | Bytes | Near conditional/unconditional branches | Independently shortenable conditional/unconditional branches | Local branch bytes removable before alignment/layout effects |
|---|---:|---:|---:|---:|
| Captured 4/2/1 user-read fixture | 380 | 19 / 2 | 16 / 2 | 70 |
| Historical OTel user-read routine | 326 | 16 / 2 | 13 / 2 | 58 |
| Historical OTel LPM routine | 330 | 12 / 4 | 8 / 3 | 41 |

For example, in the 380-byte fixture, JE at 0x66 targets 0x6f and carries
a three-byte displacement in a six-byte instruction. JAE at 0xa4 targets
0x87 with displacement -35; replacing only that branch with its two-byte
form leaves displacement -31. The conditions and destinations do not
change. Sixteen such conditional branches account for 64 B, and two
internal E9 branches account for another 6 B. This is static encoding
arithmetic, not a 70-byte installed-image measurement or a cycle saving.
Further compaction could bring other branches into range; it is not
included in the table.

`branch_width_inventory.py` reads the existing fixture capture and one
retained OTel blob, decodes that blob once, and records exact candidate
offsets/destinations in `branch-widths.json`. It changes no instruction
bytes. The historical 67-byte runtime ARRAY routine and three known ARRAY
ranges have no near-branch candidates under this count; ARRAY already uses
short local branches. Thus this is not a reason to rework all map routines.
CALL rel32 sites are counted separately and preserved.

The kernel JIT already chooses short conditional/unconditional encodings
when distance fits (`arch/x86/net/bpf_jit_comp.c:2608–2635,2693–2720`).
Its final-pass jump padding can retain bytes for convergence, so these
source rules alone do not prove that a matched JIT program has smaller
installed bytes. The native linker also already has rel8 emit/patch helpers
at `x86.rs:4094–4108`; missing instruction support is not the obstacle.

One routine-local sizing step can use existing encoding machinery before
publishing offsets. It must remap internal branch labels, external helper
relocation offsets, returned code ranges and probe-recovery load-site
offsets together. Preserve the existing E8 helper slot contract; changing
an external transfer's encoding to save bytes is a different ABI issue.
Probe source instruction lengths and R11 recovery destinations must still
describe the actual faulting loads. Applying a blind byte splice to a
finished blob would leave those offsets wrong. No new runtime test or
refusal is proposed.

This ranks below eliminating read/map instructions. Dynamic branch count,
helper work and call depth remain unchanged; the possible per-call effect
is from a smaller fetch/cache footprint and needs measurement. The local
70 B and 41 B opportunities recur only where these generated routines are
actually present. They are not multiplied by static call sites: calls in
one program already share each routine. App installed bytes and per-call
effect remain unmeasured. Implementation stays with the coordinator.

## 13. ARRAY return sharing adds a jump to successful lookups

2026-11-17T04:33:56Z review at 5ee83174d. This is distinct from shortening
an existing branch: the following unconditional transfers can disappear
without increasing code size or inlining every lookup call.

`x86.rs:3987–3997` builds each known ARRAY/PERCPU_ARRAY routine with a
two-byte jump over the null result to a shared return:

```text
success: ... produce RAX
         JMP return          # EB 02
missing: XOR EAX,EAX
return:  RET
```

Ending the successful path with its own RET uses one byte instead of
two. The missing path keeps its existing XOR/RET. Each successful lookup
loses one executed jump; a missing known-map lookup already branches
straight to XOR/RET and gains no instruction reduction. Current source
contains the same tail as all three retained known ARRAY ranges in the
OTel host blob: 32, 32 and 27 B respectively. The local size opportunity
is one byte per routine, with sharing between callers preserved.

The dynamic ARRAY dispatcher uses a more elaborate shared return
(`x86_runtime_array.rs:24–35`):

```text
success: ... produce RAX
         JMP return          # EB 04
missing: XOR EAX,EAX
         JMP return          # EB 00, next instruction is already RET
return:  RET
generic: ... external helper fallback
```

Two separate RETs replace both jumps and the old shared RET: four bytes
of jumps plus one RET become two RETs, saving three bytes. Successful and
missing ARRAY paths each lose one executed jump. The non-ARRAY branch
already goes to the generic fallback before this tail, so that path has
no instruction-count gain. In the retained 67-byte dispatcher the exact
seven-byte marker `EB 04 31 C0 EB 00 C3` starts at 0x7425. The zero-distance
jump at 0x7429 is still a real emitted instruction; this receipt does not
assign it a cycle cost or assume how the host predicts it.

`array_return_inventory.py` records these four actual ranges, marker
offsets and disassembly in `array-returns.json`. The total local byte
opportunity in this one payload is only six bytes. Dynamic instruction
savings recur at executed lookups, but their frequency and per-call effect
have not been measured. No candidate code was emitted or run. Ordinary
LLVM-generated typed-inner routines are not counted by these byte-pattern
matches.

The JIT's ARRAY generator emits address/bounds/index operations directly
into its caller (`kernel/bpf/arraymap.c:232–249`), with no leaf-helper RET
to share. Its existing success jump over the null result is a separate
control-flow shape. This native-only function-tail overhead is below the
larger call/key-materialization issue in section 4. A routine-local return
layout can remove it without broad inlining, a runtime switch or a new
check. Local null/generic branch targets, code ranges and helper-relocation
offsets still have to describe the new layout; the external E8 call slot
stays unchanged. Implementation remains coordinator-owned.

### ARRAY mask attribution: policy conditions remain necessary

The same source pass checked whether removing the live mask would be
another straightforward win. `perf_context_lto.cpp:215–219` retains
`index & mask` for typed inner arrays; the runtime dispatcher emits the
memory-form AND at `x86_runtime_array.rs:18–19`. Retained runtime code
at 0x740d is `and eax,[rdi+0x124]`: one instruction with a memory operand,
not a separately decoded load and register AND. The known-map routine
above has no AND in its emitted lookup body already. There is no universal
extra mask cost across all native ARRAY paths.

The kernel callable `array_map_lookup_elem` always masks at
`arraymap.c:167–175`. Its JIT generator omits that operation only when
`map->bypass_spec_v1` is true (234–239); maps flagged BPF_F_INNER_MAP decline
the generator at 229–230 and retain the callable path. Allocation records
the map's policy at 89 and 146–147, using `bpf_bypass_spec_v1` from
`include/linux/bpf.h:2741–2745`, which considers kernel policy and capability
facts. Root in the build container is not a captured per-map policy fact.
The native map-type facts carry type/value sizes, not this policy bit
(`native_loader.cpp:4181–4183`, `perf_context_lto.cpp:42–46`). No actual
policy value for these timed maps is established here.

Likewise, inner ARRAY capacity is fixed by the kernel's template match
only when BPF_F_INNER_MAP is absent (`arraymap.c:594–600` and
`map_in_map.c:83–91,105–109`). Treating every inner-map template capacity
as a constant would be wrong. Keep existing live bounds/masks where facts
do not justify specialization; this review proposes no blanket mask
deletion, frozen module/core change or new per-call policy check. The
separate-return opportunity above does not depend on either policy fact.

## 14. Inline read policy to make the copying routine a leaf

2026-11-17T04:49:19Z review at 778ee0ae7. This extends the first-ranked
read item beyond constant size and SMAP selection. Those changes still
leave a nested policy CALL, which is why the earlier register-layout
discussion retained three callee-saved registers across it. Inlining the
actual predicate can remove that call boundary while retaining the policy.

The sole kernel's `nmi_uaccess_okay` is small:
`arch/x86/mm/tlb.c:1767–1789` compares the live per-CPU
`cpu_tlbstate.loaded_mm` with `current->mm`. The current build has
CONFIG_DEBUG_VM disabled, so its VM_WARN_ON_ONCE diagnostics and CR3
comparison do not execute. The on-disk function body confirms the
effective predicate:

```text
CALL __fentry__
MOV RDX, GS:[current_task]
MOV RAX, GS:[cpu_tlbstate.loaded_mm]
CMP [RDX + task_struct.mm], RAX
SETE AL
JMP __x86_return_thunk
```

`policy_leaf_inventory.py` reads this exact function and the kernel-address
policy from the one vmlinux, records the relevant config lines, and counts
the existing captured read fixture's frame/CALL instructions in
`policy-leaf.json`. The objdump outputs are on-disk code. Ftrace and return
sites can be patched at boot; neither the __fentry__ CALL nor the particular
return thunk is claimed as executed guest overhead. The definite boundary
is the read routine's external policy CALL and its corresponding return
transfer, in addition to live policy work that must remain.

At present `x86_probe_read.rs:37–38` saves five registers and copies its
arguments into R12/R13/R14; 54–58 calls the policy and tests its bool result.
Line 59 then loads current_task again for pagefault nesting. The NMI policy
itself has already read that pointer. Keeping it in a caller-saved register
through an inline predicate avoids that duplicate GS read as well as the
CALL/return boundary and materialized bool/test sequence.

A feasible leaf-state assignment is:

| Register | State |
|---|---|
| RAX | Policy temporary, then copy load/result |
| RDI / RSI | Advancing destination / source |
| RCX | Remaining copy or zero count |
| R8 / R9D | Original destination / original u32 size |
| R10 | Current task for mm comparison and pagefault nesting |
| R11 | Policy/feature temporary before copy, then source-load fault status |
| RDX | SMAP decision after moving the source, if not boot-folded; zero scratch after cleanup |

These are all SysV caller-saved registers. The source pointer moves out of
RDX before its feature role, and feature cleanup finishes before zeroing
uses RDX. R11 remains reserved for fault status during every protected
source load. This is a design witness rather than emitted/tested code or
a minimum-register proof. It shows why eliminating the nested call can
eliminate the need for the current ten PUSH/POP instructions, rather than
merely reducing five saves to three. A leaf has no nested CALL alignment
requirement; the program frame and tail-call frame contract need not change.
Net instruction count, local bytes and app installed size remain unmeasured.

Bind `cpu_tlbstate` and the two structure offsets from the same boot/layout
facts as the current task binding. Do not embed the displayed System.map
addresses or the on-disk task offset as a portable ABI. Read loaded_mm and
current->mm on every policy evaluation, preserve their comparison before
pagefault_disable, and branch to the existing denied/error/zero path when
they differ. The function does not short-circuit on `!in_nmi()`; adding
that shortcut, caching the comparison across calls, or treating it as a
boot constant would change the check. No extra NULL test, CR3 read or
debug-only check is needed for this kernel configuration.

Kernel-read policy is the next case, not a function to assume true.
`arch/x86/mm/maccess.c:9–36` rejects the user/guard range and vsyscall page,
then checks canonicality using boot_cpu_data.x86_virt_bits, with an
early-boot zero-width case. Its compiled body does not consume the size
argument. Folding actual boot address-width facts can simplify it while
retaining those predicates and the existing -ERANGE denial. This does not
authorize replacing compat reads' task-dependent user/kernel selection.

The first target is OTel's lowered user reads. Other apps benefit at
actually lowered read sites; Tracee's still-external compat family is not
counted as already covered. Expected savings come from the call/frame and
duplicate task-pointer work on each executed read, while policy/fault
semantics remain. This ranks above the return-layout/branch-width items.
No guest, optimizer/codegen invocation, source change or candidate execution
was performed. Coordinator owns implementation and its isolated app timing;
no new runtime switch, check, refusal or kernel/module change is proposed.

## 15. Installed-size summaries overwrite same-name programs

2026-11-17T04:58:06Z review at 9521a9cf2. The per-call audit found no
name-key overwrite in its aggregate: `native_eval_20260529.py:194–204`
iterates the phase's full record list and sums time/count for the existing
min-runs population. OTel's second retained baseline program contributes
only 100 calls beside roughly 139 million entry calls in the new run.
This does not explain the observed OTel per-call improvement; its work
attribution remains a separate question. No per-call formula was changed.

The installed-byte summary has a different implementation.
`kprog/results/flag-tuning-20261117/inst.py:8–14` parses kernel IDs and
types out of its regex match, then discards them and assigns each size to
`o[name]` or `n[name]`. Later loads with the same kernel name replace
earlier ones, including loads of different source functions with truncated
names. Intersecting those dictionaries produces a last-load-per-name
population rather than all installed programs. Adding type to this key
would still lose multiple same-name programs of the same type.

Five completed corrected-O3 timing runs show the difference. The first
byte column below preserves the already published name-based result. The
next two columns use unique program IDs from the same load log, and keep
cumulative loads separate from the measurement-window snapshot:

| App/run suffix | Reported name population, original/native B | Successful replacement IDs, cumulative original/native B | Snapshot native IDs matched to those loads, companion-original/native B |
|---|---|---|---|
| OTel / 035907_339709 | 14; 167,706 / 135,468 | 14; 167,706 / 135,468 | 13; 167,504 / 134,949 |
| BCC / 041017_749964 | 21; 6,938 / 7,480 | 25; 7,965 / 8,286 | 25; 7,965 / 8,286 |
| Cilium / 042102_276469 | 18; 80,282 / 66,314 | 113; 581,577 / 484,353 | 47; 236,653 / 204,484 |
| Tetragon / 043157_792401 | 17; 105,568 / 79,549 | 288; 2,472,912 / 1,913,889 | 287; 2,471,824 / 1,912,832 |
| Tracee / 044227_741393 | 110; 1,237,382 / 1,068,760 | 169; 2,068,918 / 1,699,564 | 167; 2,068,774 / 1,699,430 |

Here “original” means the eBPF companion loaded immediately before its
replacement in the native arm, not a name-based match into the other
arm's fresh kernel IDs. The snapshot-matched population's native/original
ratios are BCC 1.0403, Tetragon 0.77385 and Tracee 0.82147. These describe
that explicit population; they do not replace stage P executable sizes,
which the flag study measures independently.

For example, Tetragon's 287-program snapshot contains 1,912,832 native
bytes, while the name-based report says 79,549 B across seventeen names.
BCC's 25 records include four `tracepoint__sys` programs and two
`kprobe__cap_cap` programs. Tracee has 31 `trace_security_` records of the
same type among other collisions. These are separate kernel programs,
not duplicate text lines that should be discarded because their names
match. The last selected name's size also depends on load order.

Cumulative load bytes are not the measurement-window footprint either:
Cilium replaced 113 program IDs during startup/reconfiguration, but only
47 of them occur in the final 56-record native-arm snapshot. Its other
nine records have no native replacement pair and total 2,079 B: five
drop-notify programs, two host-policy programs and two LXC-policy programs.
They fit the earlier manifest-miss class. All have zero recorded run count;
that does not establish that a tail target never ran. The whole snapshot
contains 206,563 B, including this retained eBPF code. This is a size and
coverage receipt, not resolution of Cilium's separate packet-path question.

`installed_population_inventory.py` pairs original/native jit-info records
with their replacement event on the same PID/TID, retains kernel IDs and
source log lines, then joins native IDs to that run's measurement snapshot.
`installed-populations.json` contains the ledger and each population. IDs
are compared only within one run/boot. The reader also reproduces the
legacy name-based sums so the correction can be checked directly against
the published row. No raw result, benchmark or coordinator script was
modified; `inst.py` lies outside this lane's review-write directory.

Use a stated snapshot or load-event population when recording an LTO
piece's installed bytes, with per-instance IDs/provenance instead of
names as identity. Keep startup-only and retained-eBPF programs visible
in their own explicit counts. This is an analysis correction, not a new
measurement gate or a reason to discard any completed run. Throughput,
per-call counters and the uniform-O3 P stage sizes remain as recorded.
No guest, image build or source optimization was started. Implementation
of the summary correction remains coordinator-owned.

Follow-up 2026-11-17T05:23:06Z at 7f458722f: the coordinator fixed name overwrites by pairing
same-thread original/native log records and keying pairs by native program
ID. A light replay of that corrected script reproduces this receipt's
cumulative totals: BCC 25 / 7,965 / 8,286 B; Cilium 113 / 581,577 /
484,353 B; Tetragon 288 / 2,472,912 / 1,913,889 B; Tracee 169 / 2,068,918 /
1,699,564 B. The name-overwrite defect is therefore corrected in the
current summary helper. Its output remains cumulative paired loads, not
the measurement snapshot: it never joins to the snapshot inventory.
The Cilium 113-versus-47 distinction and nine retained-eBPF records still
matter when describing a live footprint. Also, its “original” log record
is the same-load eBPF companion in the native arm, rather than the first
timing arm's program. These are population/label qualifications, not
reasons to change or reject the completed timing results.

## 16. User-read range arithmetic can drop the carry branch

2026-11-17T05:06:00Z review at 4e63113e7; refinement of the first-ranked
read item.

The range predicate in `x86_probe_read.rs:45–50` currently computes an
unsigned source-plus-size, rejects carry, then compares that sum with the
live USER_PTR_MAX. The retained 4/2/1 fixture has exactly six instructions,
31 bytes and two conditional branches for that portion. This is separate
from NMI policy, SMAP selection, copy faults and full-destination zeroing.

For unsigned source `s`, zero-extended u32 size `n` and user limit `L`,
the target's invariant `0 <= n <= L < 2^64` gives:

```text
no carry in (s + n) AND (s + n <= L)
                  iff s <= L - n
```

If the left side holds, ordinary integer addition gives `s <= L - n`.
Conversely, that inequality gives `s + n <= L < 2^64`, which establishes
both no carry and the existing upper bound. This preserves the original
end-of-range predicate, including overflow rejection. It does not relax
the helper to a start-address-only test or rely on a later fault to repair
an access that the old range test rejected.

The side condition comes from actual target source, not container
privilege or host CPUID. `x86_probe_read.rs:38` retains size via R13D,
zero-extending its u32 value. `arch/x86/kernel/cpu/common.c:2615–2623`
initializes USER_PTR_MAX from TASK_SIZE_MAX before userspace loads these
programs. `arch/x86/include/asm/page_64.h:138–146` selects either
`2^47 - PAGE_SIZE` or `2^56 - PAGE_SIZE`; this kernel has 4 KiB pages.
Even the smaller limit exceeds UINT32_MAX. No exact guest address-width
value needs to be inferred, and the rewrite can still load the live limit
on each helper invocation. No runtime `L >= n` check is proposed.

Using the present argument/register layout, the shape is:

```text
MOVABS R11, &USER_PTR_MAX
MOV    RAX, [R11]
SUB    RAX, R13               # n was zero-extended through R13D
CMP    RDX, RAX               # original source, not the wrapped sum
JA     existing_denied
```

This is five instructions and one conditional branch, with 25 bytes if
the existing rel32 branch form is retained, compared with six/two/31 in
the capture. The memory read of USER_PTR_MAX remains once per check.
These are encoding arithmetic and a proposed sequence, not assembled
candidate bytes, a timed instruction path or an installed-size saving.
The existing frame-size/leaf-policy and branch-compaction changes would
alter the surrounding layout independently.

`user_range_inventory.py` reads the captured instructions and records
340 agreeing arithmetic boundary vectors in `user-range.json`: zero/max
u32 sizes, ordinary small sizes, limit-minus-size and neighboring source
addresses, high kernel addresses and wraparound cases for both target
limit alternatives. It also preserves a counterexample outside the
hypothesis (`L=0,n=1,s=0`), where subtracting underflows and would wrongly
accept. The script is an offline arithmetic reader; it introduces no
production check or candidate execution. The algebra, rather than these
finite vectors, establishes the equivalence under the stated invariant.

Keep the size truncation explicit. Subtracting an unproven 64-bit RSI
value or truncating the 64-bit limit to 32 bits would invalidate the
argument. Likewise, this is not permission to use another architecture's
or an uninitialized user limit. The sole-kernel/userspace-load contract
already supplies the needed bound; no kernel/module change or new fact
query is required. Denial still follows the same -EFAULT/zeroing path,
and the NMI/pagefault/fault-recovery work still runs after an accepted
range. Expected per-call benefit is one fewer conditional branch on a
successful lowered user read; actual effect remains unmeasured and
implementation remains coordinator-owned.

## 17. A counted block keeps long constant reads compact

2026-11-17T05:14:44Z review at 22de1e918.

This refines the first-ranked size-specialization item. The existing
144-byte example should not force a choice between the generic eight-byte
loop and eighteen fully unrolled protected word operations. A counted
four-word block with a fixed two-word tail offers a third source shape.
This section is a static schedule/encoding model, not emitted candidate
code, a tested lowering or a measured speedup.

The current normal-copy loop in `x86_probe_read.rs:89–100` executes nine
instructions per qword: source load, R11 status test, fault branch, store,
two pointer increments, size subtraction/comparison and the loop branch.
With 0dcf97880, a zero remainder now skips the 4/2/1 tail using TEST/JE.
For successful copies of positive constant multiples of eight, the source model is
two initial instructions plus nine per word plus two empty-tail
instructions. `constant_copy_model.py` reads the retained pre-0dcf
instruction inventory and models that explicit eight-byte source addition.
It does not rerun the old decoder against a new binary or present the
old 380-byte fixture as current installed code.

| Known size | 0dcf generic source-model copy instructions / conditional branches | Fully unrolled copy instructions / conditional branches | Fully unrolled copy-only bytes with near fault branches |
|---|---:|---:|---:|
| 8 B | 13 / 4 | 4 / 1 | 15 |
| 16 B | 22 / 6 | 8 / 2 | 32 |
| 144 B | 166 / 38 | 72 / 18 | 316 |

Every unrolled word still has MOV-load, TEST R11D, JE-fault and MOV-store.
The 144-byte byte count includes the longer displacement encodings for
the final two accesses at offsets 128/136. It is not eighteen copies of
the zero-offset instruction width.

For 144 bytes, use four iterations copying 32 bytes each, then 16 fixed
tail bytes. The four-word block has sixteen load/status/branch/store
instructions, followed by two pointer increments, DEC of a four-iteration
counter and JNE. Counting the initial counter MOV and two protected tail
words gives 89 executed copy instructions and 22 conditional branches,
versus 166/38 in the generic source model. The static copy-only schedule
is 119 bytes with the existing near fault/loop branch widths, versus 316
for full unrolling. The existing generic copy region is modeled as 142 B
after the empty-tail addition. These are local encoding counts; they
exclude policy, frame, SMAP, copy setup, success result, cleanup, zeroing,
exception metadata and the rest of the program.

This is appropriate only after the call site's actual size is proven.
The four historical 144-byte nearby literals remain static leads, not
full CFG proofs or dynamic frequencies. Keep the already identified 8/16
cases simpler: a counted block is not an improvement over their one/two
fixed words. The 144-byte schedule needs no runtime size discriminator;
the existing original-size value or a literal still supplies full-buffer
zeroing on a fault, while ECX is free to be the bulk iteration counter.
No SIMD, REP, kernel routine, extra helper CALL or new runtime check is
required by this layout.

Preserve load order and first-fault behavior. Each word must test R11
before its store and before any later source load; a single status test
after four speculative loads is not this model. The eighteen loads remain
at source offsets 0,8,...,136, with no read beyond the requested 144 bytes.
Fault handling still produces the same error and zeros the entire original
destination. Pair loads/stores in their original order rather than loading
all four words before storing them; that also preserves the existing
behavior for overlapping source and destination. There are six static protected load sites in the counted
shape (four in the reused block, two in the tail), each needing its actual
instruction length. Those lengths are 3/4/4/4 and 3/4 bytes, not all the
old zero-offset loop's three bytes. Keep R11 as the recovery destination.

`constant-copy-model.json` retains the arithmetic, assumed instruction
widths, source-order offsets and stated exclusions. No assembler/compiler
or native candidate was invoked. The original generic routine is shared
across callers: adding separate constant variants can grow total installed
code even when each copy region is smaller. In particular, duplicating
policy/frame/cleanup for every length can erase this local benefit. Keep
variant sharing deliberate and measure the whole reachable image, including
exception metadata, along with per-call time. Expected benefit is reduced
loop/pointer bookkeeping at executed proven-size reads; actual gain and
app installed bytes remain unmeasured. Coordinator owns implementation.

## 18. LPM prefix arithmetic can replace NEG/ADD with XOR

2026-11-17T05:21:21Z review at b80b2dad0. This is a small simplification of
the generated 12-data-byte LPM path, below the read and generic-dispatch
items. It requires no new CPU instruction feature, runtime policy branch
or map fact.

`x86_lpm_lookup.rs:38` computes the first differing bit using BSR RCX,RAX,
NEG ECX, ADD ECX,63. Its existing nonzero branch guarantees the BSR result
`k` lies in 0..63. In that domain, `63-k == k XOR 63`: complementing the
six low bits gives the same count. Retain BSR and replace the two following
instructions with XOR ECX,63. The second chunk at line 47 has a nonzero
32-bit BSR result in 0..31; `95-k == k XOR 95`, since the low five bits
are complemented and bit 6 contributes 64. It likewise needs only XOR
after BSR.

Actual retained code contains both sequences at 0x7627–0x762d and
0x7655–0x765a in `otel-typed.blob`. Each NEG/ADD pair occupies five bytes;
XOR ECX,imm8 occupies three. The two replacements remove four local bytes
and one executed instruction on whichever BSR case a node comparison
takes. This is arithmetic/encoding analysis, not a rebuilt 326-byte LPM
routine or a measured per-call reduction.

Flags differ between ADD and XOR, but are dead here. Both paths jump
directly to the limit-clamp CMP ECX,R9D at 0x7671, which supplies the flags
for the following CMOVA. Source line 55 has that same overwrite. Preserve
the existing TEST/JE zero handling: when the 64-bit XOR is zero, the code
can inspect the remaining 32 bits or use the short-prefix case, and a
fully equal key produces 96 directly. This simplification does not remove
those branches or apply BSR to a newly reachable zero operand.

`lpm_prefix_inventory.py` records all 64 and 32 possible nonzero-BSR
results, retained native instructions and the sole kernel's compiled
`trie_lookup_elem` in `lpm-prefix.json`. Every value agrees over the full
stated domains. No candidate code was emitted, assembled or executed.
Local labels and external helper-relocation offsets still need to follow
the shorter emitted vector, as they do for any emitter layout change.

The JIT's known-LPM path calls the kernel's trie operation. Kernel source
`kernel/bpf/lpm_trie.c:183–204` expresses the same counts as `64-fls64`
and accumulated `32-fls`; its compiled general routine uses BSR with
MOV/SUB for the first chunk and SUB/ADD for later chunks, not the proposed
XOR sequence. That body also supports other key sizes and an accumulator,
so this receipt does not extrapolate the replacement into kernel code.
The native fixed 12-byte shape exposes the smaller finite domains.

Only generated-LPM node comparisons taking a nonzero-BSR case save an
instruction. An all-equal or short-prefix bypass gains no instruction;
a non-LPM generic fallback does not execute this code. Known LPM sites
already bound directly to the kernel trie function are unaffected too.
The retained Katran LPM bucket was only 2.5 cycles per app call, so this
is not an explanation for a large Katran gap. Dynamic case frequencies
and current per-call gain remain unknown. No new check, default switch,
flag set, kernel/module change or source implementation was introduced;
coordinator owns the small forward change and its measurement.

## Leaf-read fact wiring already has a plan/cache boundary

2026-11-17T05:30:47Z source review at 97212ec1c.

The next implementation is the coordinator's leaf-read item, so this
source pass checks how its facts reach emitted code. The existing path
supports the change inside the open LTO headers/linker; a new module
query, loader-core cache or per-program boot validation layer is not
needed by the proposed NMI-predicate lowering.

| Fact or boundary | Existing source | Consequence for the leaf work |
|---|---|---|
| Filtered kernel-symbol collection | `native_loader.cpp:1445–1448` iterates `native_lto::kernel_symbols`, declared in `native_loader_lto.hpp:14–18` | Add the needed `cpu_tlbstate` name in the open list when introducing its use. Merely requesting it later from the resolver does not make it a collected symbol. |
| Structure-field positions | `native_loader_lto.hpp:39–81` resolves named/anonymous BTF members; `write_layout` at 107 onward emits facts | Use task_struct.mm and tlb_state.loaded_mm offsets from the running BTF, beside the current pagefault_disabled offset. Do not borrow a numeric displacement from the on-disk disassembly. |
| Running target and one layout string | `native_loader_link_plan.hpp:124–138` loads running-vmlinux BTF and resolves symbols through the existing resolver | The provider executes in the loader's running kernel environment, rather than the P build host. Its string is initialized once in that process. |
| Link-plan input | `native_loader_link_plan.hpp:163` writes that same string as kernel_layout | New emitted-code facts belong here, with Rust RuntimeProbeReadLayout at `main.rs:188–199` consuming their meaning. |
| Final emission cache | `native_loader.cpp:3131–3132` incorporates the whole layout string | A changed serialized fact automatically participates in this cache identity; it need not be added to another frozen core field list or a new cache generation mechanism. |
| Kernel-only lowering | `main.rs:432–436,481–483` requires/passes the layout for x86 kernel emission, while proof mode does not use it | Keep boot-policy specialization at this boundary. It does not require a new host-CPU dependency in frontend P or a new boot-fact requirement in entry-proof generation. |

The first row matters because the earlier trie_lookup_elem regression
was exactly a wanted-symbol omission, corrected by a53922beb. The existing
symbol-list hook already avoids that need for another frozen core edit.
The plan and cache rows also use the same value, rather than two similar
serializations. This is a positive source check of the current design,
not discovery of a present stale-cache defect or a request for new checks.

There is one fact-type distinction to retain. Current probe_read JSON
(`native_loader_lto.hpp:136–144`) contains addresses and field offsets,
including boot_cpu_data and x86_capability. Those locate the capability
bit; BTF and a symbol address do not supply its enabled value. The planned
SMAP link-time selection needs an actual target-boot capability fact in
the same serialized layout. It must not come from the build host's CPUID
or be inferred as false from an absent value. This audit did not read or
establish a new guest SMAP value, and introduces no provider implementation
or missing-fact rejection.

By contrast, inlined NMI policy must keep loaded_mm and current->mm as
live kernel reads on every invocation. Their addresses/offsets may be
link facts; the equality result is not one. The existing final-emission
cache is the relevant boundary for this machine-code specialization.
The earlier embedded-IR compiler cache need not acquire CPU facts that
its LLVM transformations do not consume.

The 0dcf97880 build-input change already makes the staged LTO compiler
depend on native_loader_lto.hpp and its other included headers
(`vendor/bpf/Makefile:292`); that prior missing dependency is fixed. No
new source change, guest, build, candidate or cache output was produced
in this pass. The existing runtime checks/ABI and all other LTO pieces
stay as they are. Per-call effect and installed bytes belong to the
forthcoming implementation, not this wiring review.

## User-read cost already omitted: destination object checking

2026-11-17T05:37:24Z review at 9d9ffdd6f. The read performance comparison
must distinguish work the native emitter still executes from work it
already omits. The compiled kernel's `copy_from_user_nofault` contains a
CALL to `__check_object_size` before its raw copy. The native scalar read
routine has no corresponding call; its one external CALL in the retained
fixture is the source/NMI policy call identified in the source, not this
destination-object operation. Its removal cannot be counted again as a
benefit of the forthcoming leaf-read change.

The kernel call chain and conditions are concrete:

- `kernel/trace/bpf_trace.c:177–186` calls copy_from_user_nofault and clears
  the whole destination on a negative result.
- `mm/maccess.c:124–131` checks the source range and NMI access, disables
  pagefaults and calls __copy_from_user_inatomic.
- `include/linux/uaccess.h:99–106` performs destination-object checking
  before raw_copy_from_user.
- `include/linux/ucopysize.h:16–23` calls __check_object_size only when
  size is not a C compile-time constant and the usercopy jump label is
  enabled. This target enables HARDENED_USERCOPY and DEFAULT_ON. A boot
  parameter can change the jump-label choice (`mm/usercopy.c:265–284`).
- `mm/usercopy.c:223–261` returns immediately for zero length, otherwise
  examines bogus addresses, stack extent, heap objects and kernel-text
  overlap. A valid stack object returns after its stack classification;
  every call does not necessarily execute every heap/text operation.

Source-range/NMI checks and destination object extent are different
questions. The helper prototype describes the destination as
ARG_PTR_TO_UNINIT_MEM with ARG_CONST_SIZE_OR_ZERO
(`bpf_trace.c:189–195`), placing destination extent/provenance in the
existing caller/verifier contract. Kernel code itself permits this
particular hardening wrapper to disappear for a known C constant size.
This source comparison does not independently prove every generated
native destination's extent, and proposes no new runtime object checker,
admission gate or kernel hardening change. It does not justify deleting
the live source/NMI policy or the existing error/full-zeroing behavior.

`usercopy_path_inventory.py` retains the sole kernel's on-disk copy
function and relevant config, the captured native fixture's CALL count,
and selected historical profile data in `usercopy-path.json`. The retained
OTel shared-hash diagnostic has 6,196,886,309 baseline PMU periods rooted
at __check_object_size and 12,870,151 in the native phase. These are the
existing profile's external roots without caller ownership, not BPF-owned
cycles, nanoseconds or a saved-time estimate. Other guest code can call
the same function; residual native-phase samples do not establish that
this native read routine calls it. The config/default and on-disk CALL
also do not by themselves establish a timed guest's jump-label state.

The next source gain remains removal of the current nested policy call,
its saved-register lifetimes and copy-loop bookkeeping. This receipt
adds an already-removed-cost boundary to that work, rather than a new
optimization result. No source, runtime check, benchmark, guest, build,
candidate or cache output was changed; per-call effects remain with the
coordinator's actual implementation and measurements.

## Kernel-read leaf policy: CPU width and paging mode are distinct facts

Source audit, 2026-11-17. This refines the kernel-policy part of section 14;
it identifies a simplification to avoid, not another measured optimization.
The user-read leaf remains first in the coordinator's order.

`arch/x86/mm/maccess.c:17–36` accepts a source only after the user/guard
threshold and the **whole vsyscall page** have been excluded. It then
accepts zero `boot_cpu_data.x86_virt_bits` during early boot, or checks
canonicality at that width. The size argument is unused. Two distinct
inputs feed this policy:

- `arch/x86/kernel/cpu/common.c:1085–1107` obtains `x86_virt_bits` from
  CPUID leaf 0x80000008, with a 48-bit fallback on x86-64.
- `arch/x86/include/asm/page_64.h:138–146` selects `TASK_SIZE_MAX` through
  the LA57 alternative: `(1 << 47) - PAGE_SIZE` or
  `(1 << 56) - PAGE_SIZE`. `common.c:1835–1842` explicitly clears the LA57
  capability when five-level paging is inactive; it does not rewrite the
  separately obtained `x86_virt_bits` there. Thus the CPUID width cannot be
  inferred from the active user-address limit, or vice versa.

For a nonzero canonical width `w`, the policy's canonical set is
`[0, 2^(w-1)-1]` together with `[2^64-2^(w-1), 2^64-1]`.
Intersect it with `src >= TASK_SIZE_MAX + PAGE_SIZE` and exclude
`[0xffffffffff600000, 0xffffffffff600fff]`, as
`asm/vsyscall.h:32–34` does. Some illustrative source-policy results are:

| User/guard threshold | CPU virtual width | Source | Allowed by this policy |
| --- | --- | --- | --- |
| `2^47` | 48 | `0x0000800000000000` | No: not canonical at width 48 |
| `2^47` | 57 | `0x0000800000000000` | Yes: above the threshold and canonical at width 57 |
| `2^56` | 57 | `0x0000800000000000` | No: below the threshold |
| `2^47` | 48 or 57 | `0xffffffffff600fff` | No: last byte of the excluded vsyscall page |

These are conditional cases, **not claims about the running guest's CPU
width**. In the second case an unmapped/noncanonical-for-active-paging
source reaches the protected copy and can return `-EFAULT`; rejecting all
nonnegative addresses in the replacement instead returns `-ERANGE`.
`include/linux/bpf.h:3381–3389` forwards a negative kernel-read result
after zeroing the destination, so matching zeroed bytes alone would miss
this return-value change. A single address equality would also fail to
exclude the remaining 4,095 bytes of the vsyscall page.

The sole on-disk kernel's `copy_from_kernel_nofault_allowed` disassembly is
already retained in [policy-leaf.json](policy-leaf.json): threshold ADD/CMP,
page-mask/CMP, byte load of the CPU width, zero-width branch, then variable
SHL/SAR/CMP. Its initial threshold MOV is an alternative site, not a proof
of the running guest's active paging. Boot facts may select constants for
these operations; the existing predicates and error behavior remain the
reference. No new predicate or runtime check is proposed.

[kernel_policy_model.py](kernel_policy_model.py) records boundary arithmetic
in [kernel-policy-boundaries.json](kernel-policy-boundaries.json): 108 cases,
including the early-boot branch and both address widths. It compares the source's
sign-extension definition with the equivalent two-interval description;
the negative-only restriction is deliberately recorded as a counterexample.
This is source review only: no code emission, candidate execution, guest,
build, per-call saving or installed-byte reduction is claimed.

## Zero-remainder measurement receipt: baseline movement and installed cost

Review of coordinator change `0dcf97880`, 2026-11-17. This is a result
interpretation for an implemented item, not another source change. The
`x86_probe_read.rs` diff adds `TEST ECX,ECX; JE success` ahead of the 4/2/1
remainder path. Its current near-branch form is eight added bytes per
scalar-read routine. An empty remainder formerly executes three tests and
three conditional branches; it now executes one test and one conditional
branch. Thus this region saves **four instructions and two conditional
branches** when the remainder is zero, including a size-zero request after
its policy work. Nonempty remainders execute the new test/branch as extra
work. String routines do not use this scalar remainder path.

The following compares completed O3 run2 and first zero-remainder runs.
All times are the existing aggregate ns per BPF invocation, with its
existing >=100-call reporting convention. These are **cross-run observed
changes**, not isolated causal estimates or a body/helpers/maps split.

| App | Before → after eBPF ns/call | Before → after native ns/call | Reported eBPF/native time ratio | Cumulative installed native bytes | Same-load companion JIT bytes |
| --- | --- | --- | --- | --- | --- |
| OTel | 3212.8 → 3375.0 | 2926.5 → 2873.8 | 1.098x → 1.174x | 135,468 → 135,604 (+136) | 167,706 both |
| BCC | 104.1 → 107.7 | 102.8 → 106.0 | 1.013x → 1.016x | 8,286 → 8,334 (+48) | 7,965 both |
| Tracee, first attempt | 365.9 → 367.7 | 319.6 → 376.4 | 1.145x → 0.977x | 1,699,564 → 1,700,836 (+1,272) | 2,068,918 both |

OTel's native time falls **1.80%**, while its eBPF baseline rises **5.05%**.
The larger increase in the eBPF/native ratio therefore cannot all be
credited to the new branch. BCC's native time rises **3.09%**, alongside
a **3.45%** eBPF increase; the small ratio change does not establish a
native-time improvement. Its baseline aggregation also changes from 16
to 15 selected records, while the native aggregation stays at 15. Keep
the invocation mixture in view when using these aggregate figures.

Tracee's first post-change native throughput series is
366,127 / 204,491 / 319,601 against eBPF
326,173 / 340,675 / 342,630. Native/eBPF per-sample ratios are
1.122 / 0.600 / 0.933. The coordinator started a second run on the same
image (`b4c325eba`, `zero-remainder-20261117/tracee2.sh`); its result was
not complete at this receipt. The first result stays recorded beside
that follow-up. Neither the spread nor the absence of fresh PMU attribution
is a reason to discard it or manufacture a body/helper/map time split.

[zero_remainder_effect_inventory.py](zero_remainder_effect_inventory.py)
reads the six retained app JSON files and replacement logs, writing
[zero-remainder-effects.json](zero-remainder-effects.json). Installed
populations are cumulative unique successful native replacement IDs:
14/25/169 for OTel/BCC/Tracee in both runs. Within each boot, original and
native are paired by the replacement's process/thread and native ID.
Across boots, `(original type, name, JIT size)` **multisets**, including
duplicate counts, agree in these pairs; no kernel ID is joined across
boots and a multiset is not proof of source identity. The additions are
17/6/159 eight-byte units, consistent with the scalar-routine source
change, not independently measured routine counts. They are installed
code costs, separate from unchanged P executable totals. They are not
measurement-window snapshot sizes.

The source diff also fixes build prerequisites. That part has no intended
per-call code effect, but these observations alone do not prove the build
had no other effective-input differences. Current-stage code, fresh PMU
ownership and the coordinator's next runs remain the evidence for more
specific attribution. No benchmark, source or runtime check was changed
by this review, and no extra measurement was started.

## User-leaf work in progress: savings attribution and live-register audit

Read-only inspection at 2026-11-17T05:57:44Z of the coordinator's **uncommitted**
`x86_probe_read.rs` change. The references below describe that working
state, not an installed image, a finished build or an execution test.
No copy of the working source or candidate code was made. Fact-provider
and schema edits are still being written; their absence in this partial
tree is not reported as a landed regression.

The new `user_leaf` at lines 98–152 contains no nested helper CALL and no
RBX/R12–R15 saves. It uses only SysV caller-saved registers:

| Register | Lifetime in this source |
| --- | --- |
| R8 | Original destination through full-buffer failure zeroing |
| R9 | Zero-extended original u32 size, through the range subtraction and zeroing |
| R10 | Current task through the mm predicate and pagefault nesting decrement |
| RDX / DL | Source until copied into RSI; then SMAP decision until cleanup; only then zeroing scratch |
| R11 | Address scratch before copying; fixed success/fault status throughout protected source loads |
| RAX, RDI, RSI, RCX | Policy temporary, advancing copy pointers/count and return value |

This establishes a useful attribution boundary in the source: **the leaf
change removes all ten push/pop instructions without first specializing
the size or the SMAP bit**. Those saves occupied 18 bytes in the old
routine. Earlier sections describe their potential removal from the
pre-leaf five-save body; later SMAP/constant-size results must not claim
their removal again. Kernel scalar and kernel-string bodies at lines
155–212 still retain their callback and saved registers in this working
state, so this observation is specifically about user reads.

The remaining SMAP decision is explicit at lines 120–127 and 136–139:
MOVABS (10 bytes), memory TEST (11), SETNE DL (3), near JZ (6), TEST DL,DL
(2), near JZ (6). That is **six decision instructions, two branches and
38 bytes**, excluding the 3-byte STAC and 3-byte CLAC themselves. The old
R15b choice used 40 bytes, as retained in `remainder-paths.json`; DL avoids
two REX bytes without removing feature selection. A future boot-fact
choice can remove this decision sequence and retain or omit STAC/CLAC
as appropriate. It buys no further push/pop removal from this user body.
These are source encoding counts, not emitted final-byte or cycle results.

The source ordering also preserves the intended register lifetimes:
RSI receives the source before SETNE overwrites DL; SETNE leaves the TEST
flags intact for the following JZ; the shared copy body at lines 38–74
does not overwrite R8/R9/R10/RDX. Each protected 8/4/2/1-byte source load
has a 3/2/3/3-byte recovery site, a TEST R11D and a fault branch before
its destination store. Success sets EAX to zero. Faults set sign-extended
`-EFAULT`, join CLAC/pagefault cleanup, then zero the original full
destination. Policy denial skips that cleanup because nesting was not
incremented, and also zeros the original destination. `zero_fill` uses
EDX only after SMAP cleanup and leaves the RAX error intact. These are
source control-flow observations; emitted offsets, exception recovery
and runtime behavior remain for the coordinator's completed change.

The live GS task/mm comparison and single range comparison match the
planned direction. SMAP selection remains per invocation here, and
kernel-read policy and constant-size specialization remain later work.
The existing plan/cache facts boundary described above is still the
integration point. No new check, guard, source edit, execution, measured
per-call gain or installed-size result is introduced by this receipt.

### Tracee same-image repeat now complete

Coordinator receipt `a66b7f436` completes the follow-up that was pending
above. Run `corpus/results/x86_kvm_corpus_20261117_054943_357840` gives
365.699 ns/call eBPF and 316.975 native, or **1.154x**. Throughput is
**1.098x**, with per-sample native/eBPF ratios
1.095 / 1.079 / 1.101 (eBPF 338,109 / 336,676 / 336,951;
native 370,122 / 363,433 / 370,991). Both coordinator scripts use stats
on and three 60-second samples through the corpus entry.

Against pre-change run2, native time is **0.82% lower** (319.590 →
316.975), while baseline time is **0.06% lower** (365.923 → 365.699).
The same post-change image also produced the first attempt's
376.436 native ns/call. That **59.461 ns** same-image difference is far
larger than the **2.616 ns** before/change/repeat difference. It supports
keeping the repeat beside the first attempt; it does not identify the
cause as host scheduling, instruction changes, map state or workload mix.

The repeated load has the same 169 successful replacement IDs counted
within its own boot, 2,068,918 companion JIT bytes and 1,700,836 installed
native bytes. Every `(original type, name, JIT size)` group's count and
native-byte sum agrees with the first attempt. Their measurement-window
records also both number 167, with 41 selected by the existing per-call
analysis. These population observations do not turn code-size equality
into proof of identical dynamic work. The +1,272 installed-byte cost
against run2 remains; body/helper/map attribution remains unavailable.

The existing [reader](zero_remainder_effect_inventory.py) now records this
repeat in [zero-remainder-effects.json](zero-remainder-effects.json) without
replacing the first attempt or changing its raw counters. No additional
guest or measurement was started for this review.

### User-leaf integration landed while this review was running

`6beae45cc` (2026-11-17T06:01:31Z) completes the fact/schema integration
that was still in progress in the earlier receipt. Source review confirms
`native_loader_lto.hpp:14–18` collects `cpu_tlbstate`; its layout output
obtains `tlb_state.loaded_mm` and `task_struct.mm` from running-kernel BTF,
and the matching `RuntimeProbeReadLayout` fields are present in `main.rs`.
The old `nmi_uaccess_okay` symbol and serialized field are removed. The
existing complete-layout cache input therefore includes the added facts;
no separate cache epoch or validation layer is needed.

The coordinator's [leaf-read receipt](../leaf-read-20261117/README.md)
reports 40 linker tests, 1,149 user-read host vectors, a user payload
reduction **388 → 370 bytes**, and byte-identical kernel scalar/string
bodies. These are reported host results, not tests rerun by this review
or installed application-size totals. The fixture diff uses a live
GS-backed task/mm pair and a mismatch case rather than patching a user
policy CALL. Runtime SMAP selection still remains in this implementation.
`d08e60c83` starts the coordinator's image/check/three-app timing batch,
whose raw directory is `/workspaces/kprog-raw/leaf-read-20261117`.
No measured per-call effect is available yet. The partial-tree status
above is retained as a dated observation and is now closed by this commit.

## SMAP boot fact: `/proc/cpuinfo` rows are not the global capability set

Source review for the next scheduled SMAP specialization, 2026-11-17.
The landed user leaf still reads
`boot_cpu_data.x86_capability[9] & (1 << 20)` on every invocation. The
kernel's `stac()`/`clac()` alternatives use `X86_FEATURE_SMAP`
(`arch/x86/include/asm/smap.h:40–47`), and alternatives choose using
`boot_cpu_has(alt->cpuid)` (`arch/x86/kernel/alternative.c:621`).
`boot_cpu_has` itself reads `boot_cpu_data` (`asm/cpufeature.h:74`).
This gives the precise global capability value the link-time choice is
trying to preserve, rather than a raw host CPUID result.

A possible userspace shortcut needs qualification: guest `/proc/cpuinfo`
does expose kernel-filtered feature flags, but its **first CPU row is not
defined as that global structure**. `cpu/proc.c:159–164` iterates online
CPUs and supplies `&cpu_data(cpu)` to `show_cpuinfo`; lines 104–107 print
that CPU's `cpu_has(c, bit)` flags. In contrast,
`cpu/common.c:2086–2101` first applies forced capability options and then
ANDs each initialized CPU's capability words into `boot_cpu_data`.
The source explicitly calls the latter the common feature set.

For example, if one CPU has SMAP and another does not, the first row can
say `smap` while the global AND is false. Reading only currently online
rows also does not by itself reproduce an accumulated set that included
a CPU now offline. These are conditional source examples, **not findings
of heterogeneous or offline CPUs in the benchmark guest**. A uniform guest
with matching kernel feature filtering can have equal values; this
inspection does not establish that equivalence from the first row alone.

Use the target kernel's capability meaning when supplying the once-per-load
fact to the existing serialized-layout/cache boundary. A BTF offset or
symbol address still does not supply its value, and substituting host
flags supplies a different machine's facts. This review neither chooses
a new kernel-memory interface nor proposes an all-CPU validation loop,
new refusal, hotplug gate, module change or benchmark change. The current
dynamic test remains the semantic reference while the coordinator develops
the provider. No additional per-call saving beyond the previously counted
six instructions/two branches is claimed.

### An existing target-kernel data interface can supply the SMAP value

Follow-up source review, 2026-11-17: the sole kernel build has
`CONFIG_PROC_KCORE=y` and `CONFIG_ARCH_PROC_KCORE_TEXT=y`. An exact
load-time provider can use the running guest's existing `/proc/kcore`
ELF view, rather than add a module query or approximate the value from
the first CPU flags row. This is a concrete interface candidate, not an
implemented provider or a successful guest-read claim.

`fs/proc/kcore.c:395–408` emits PT_LOAD records with each range's kernel
virtual address, file offset and size. For the load segment containing
the already resolved `boot_cpu_data` field address, the corresponding
file position is `p_offset + (address - p_vaddr)`. The exact four-byte
target is `boot_cpu_data + BTF(cpuinfo_x86.x86_capability) + 9*4`;
bit 20 is `X86_FEATURE_SMAP` (`asm/cpufeatures.h:253`). Source lines
695–697 register `_text` through `_end`, including the kernel data
image, in this build's KCORE_TEXT range. Symbol and offset sources are
already available to the open loader LTO header.

Only the ELF header/program table and the selected four data bytes need
reading. The enormous sparse core file does not need copying, hashing,
mapping in full or passing through a whole-file object reader. Using the
PT_LOAD mapping also avoids guessing the architecture's core-file offset
bias. Source lines 514–519 can return zeros for holes, so a read from an
unmapped guessed position must not be interpreted as a disabled feature.
This is about translating the existing ELF address map correctly, not
about adding an admission check to native programs.

The existing access conditions remain relevant:
`open_kcore` at lines 635–643 uses CAP_SYS_RAWIO and LOCKDOWN_KCORE.
The frozen runtime already launches with `docker run --privileged`
(`runner/libs/suite_commands.py:104`), and the sole config has
`CONFIG_LOCK_DOWN_KERNEL_FORCE_NONE=y`. Those source facts make this
route worth inspecting in the existing guest; they do not prove file
visibility, privileges or read success in its running container.
No host `/proc/kcore` read or new guest was attempted by this review.

The result belongs in the existing process-local serialized layout,
which already feeds the final emission cache. It adds no per-call kernel
read. This route needs no kernel/module, container-launcher or benchmark
edit, and no new dependency in P production. No permission changes,
all-CPU validation loop, provider implementation, runtime refusal,
extra gate or measured performance claim is proposed here.

### First leaf-image application checks confirm the new layout loads

The coordinator's existing check log now records OTel and BCC completion
with rc=0 on the leaf image. Reading their replacement logs with the
already committed ID-pairing `flag-tuning-20261117/inst.py` gives:

| Check run | Cumulative successful native replacements | Same-load companion JIT bytes | Installed native bytes | Change from zero-remainder image |
| --- | --- | --- | --- | --- |
| OTel `060939_178921` | 14 | 167,706 | 135,424 | −180 bytes |
| BCC `061308_930333` | 25 | 7,965 | 8,334 | 0 bytes |

Both run directories have prefix
`corpus/results/x86_kvm_corpus_20261117_`; the completion records are
06:11:22Z and 06:14:38Z in
`/workspaces/kprog-raw/one-image-runs/check.log`. These are the coordinator's
one-sample, ten-second functional checks, not the pending three-sample
per-call timing result. Counts and bytes here include all successful
replacements in each startup, not only programs alive in the measurement
snapshot. OTel's −180-byte installed sum is distinct from the reported
−18-byte host helper payload; neither is a per-call speed measurement.
BCC's unchanged sums do not independently prove byte identity or equal
dynamic work. The remaining checks and timing continue in the existing
coordinator batch; no guest or extra confirmation was run by PERF.

## Constant-read integration can reuse the existing resolved branch targets

Source refinement for the scheduled constant-size step, 2026-11-17. Section
1 already identifies the retained OTel unwinder's jump tables as the reason
`memory::constants` loses its size facts. The current source provides a
small integration route; it does not need another ELF table resolver or a
new general CFG framework:

- `x86_helper_provenance.rs:24–38` already calls
  `readonly_relocs::control_targets` and returns the result in
  `Calls.branch_targets`. The resolver at
  `x86_readonly_relocs.rs:238–266` handles code-table relocation bases and
  neighbouring-table limits.
- `x86.rs:1119–1121` currently computes memory constants **before** those
  helper facts. Reordering these existing computations makes the resolved
  destinations available to the existing constant worklist.
- `x86.rs:1159–1161` already passes the same destinations to
  `known_maps::arguments`. Its source at `x86_known_maps.rs:20–24` even
  distinguishes resolved from unresolved indirect branches. Memory
  analysis currently makes no such distinction at
  `x86_memory.rs:155–162`, so it abandons facts for both.

The target map uses **absolute input-symbol IPs**: its branch keys match
the decoder's `Instruction::ip()`, and its target values belong in the
same input address space. Constant-analysis results instead use
`instruction.ip() - symbol.address` for call-site keys, which the helper
rewriter consumes as `local_ip`. Passing the targets after instruction
rewriting, confusing those two key spaces, or adding the symbol base a
second time would invalidate the reasoning.

Reuse the branch destinations, **not the helper-ID value domain**.
`x86_helper_provenance.rs:83–88` seeds immediate IDs only up to 255 and
copies their sets; its joins at lines 122–127 union alternatives so that
one indirect call can legitimately denote several helpers. That domain
does not assert that a size register has one constant value. The memory
worklist already handles general MOV constants, XOR-zero, partial writes,
call clobbers and same-value predecessor intersection
(`x86_memory.rs:178–224,250–257`). Its intersection semantics are the
appropriate ones for selecting one specialized size: paths assigning
8 and 16 must not become a single-size 8 or 16 read. The existing handling
of unresolved branches and internal calls can stay; no new refusal or
runtime predicate is needed.

This narrows the earlier source suggestion to data already being computed.
It does not yet prove the 24 historical nearby literals through that
worklist or give their dynamic frequencies. It introduces no analyzer,
production source edit, emitted candidate, build, guest, additional check
or new measured gain. Final specialized read sharing and installed bytes
remain part of the coordinator's implementation and timing work.

## Kernel-leaf canonicality can use the masked negative width

Refinement for the next item in the coordinator's 06:23 todo update,
2026-11-17. Keep both source-policy inputs live and distinct: the
`USER_PTR_MAX + PAGE_SIZE` threshold and the byte
`boot_cpu_data.x86_virt_bits`. The threshold and whole-vsyscall-page
exclusions remain ahead of canonicality. This does not specialize the
width to 48, infer it from the paging threshold, or add a capability check.

`asm/page.h:71–78` canonicalizes by shifting left and arithmetically right
by `64 - width`. Legacy x86 shifts of a 64-bit operand mask their count
with 63; the local reference encodes this at
`kprog/formal/KProgFormal/Reference/X86.lean:200–201` and the host oracle
at `formal/oracles/test_x86_shift_flags_host.c:64`. Therefore
`(64 - width) & 63 == (-width) & 63`.
With the live byte loaded directly into ECX, the count setup can be
`NEG ECX` before `SHL RAX,CL; SAR RAX,CL`, then compare RAX with the
unchanged source. This is one instruction/two bytes for count preparation
instead of the on-disk kernel's `MOV ECX,64; SUB ECX,EAX` pair
(two instructions/seven bytes), excluding the width load and all other
policy code. Flags from count preparation are overwritten by the final
address CMP before its result is used.

The same shift pair also preserves the **width-zero allowance without
a separate zero-width branch**: with CL zero both shifts leave the source
unchanged, so the final comparison is equal. The earlier threshold and
vsyscall tests still apply, as in the source's explicit early-boot return.
No C expression that shifts by 64 is introduced: this suggestion is for
the linker-owned x86 instruction sequence, whose masked count is zero.
The zero-width path would execute the register sequence instead of taking
its old shortcut; no current guest is asserted to use that boot state.

The existing [policy model](kernel_policy_model.py) now records count
congruence for all 256 byte values and the branch-free predicate on its
108 boundary cases at widths 0/48/57 and both user-limit scenarios.
Both comparisons have zero disagreements in
[kernel-policy-boundaries.json](kernel-policy-boundaries.json). The broad
count congruence is an instruction-arithmetic statement, not a claim about
C canonicality expressions at arbitrary unsupported CPUID widths. This
is a local simplification within the planned policy inlining; removing
the callback/frame remains the larger source opportunity. No emitted
candidate, test execution of native code, per-call saving or final
installed-byte reduction is claimed.

One entry-order detail matters when the kernel-string body becomes a leaf:
`mm/maccess.c:86–95` returns zero for a nonpositive string count **before**
evaluating the policy or changing pagefault nesting. The BPF helper takes
a u32 size, so this early case is size zero. Kernel scalar reads instead
evaluate the policy even at size zero (`mm/maccess.c:29–46`). Thus an
invalid/denied source with size zero returns 0 for the kernel-string
helper but can return `-ERANGE` for the scalar helper. Preserve that
existing distinction when sharing the policy body. Positive string
errors are still forwarded and the full destination zeroed by
`kernel/trace/bpf_trace.c:264–267`; error values must not be collapsed
merely because the destination bytes match. This introduces no new
runtime predicate or required verification gate.

## Kernel-leaf source in progress: preserved semantics and payload growth

Read-only review of the coordinator's uncommitted kernel-leaf change,
2026-11-17. References describe the working source at 06:33, not a finished
build or installed image. The callback's removal is consistent with the
planned direction, with one size tradeoff to measure alongside per-call
time and throughput.

`kernel_routine` at `x86_probe_read.rs:160–224` now saves original dst/size
in R8/R9, uses RDX as source and R10 for the task, and has no nested policy
CALL or RBX/R12–R15 frame. Its policy loads the live user limit, adds 4096,
compares unsigned source/threshold, excludes the masked whole vsyscall
page, and loads the live CPU width through its BTF offset. It uses
NEG ECX for the canonical shift count. The separate width-zero branch is
still present; removing it as in the preceding arithmetic receipt remains
an optional local refinement, not a correctness issue.

The source preserves string size-zero return **ahead of** policy/nesting,
scalar size-zero policy evaluation, sign-extended `-ERANGE` on denial,
`-EFAULT` on a source fault, one nesting decrement after an entered copy,
and full original-buffer zeroing on negative results. String successful
length is still narrowed/sign-extended as the helper's int return, so its
negative-result handling is preserved too. The loader/schema changes add
only the BTF offset for `cpuinfo_x86.x86_virt_bits` and remove the obsolete
policy callback symbol/field. They keep the width **value** live rather
than recording it as a boot constant. No defect is established by these
source observations; final emitted metadata and execution are untested
by PERF.

The current fixed near-branch encodings give this local byte accounting
against committed `6beae45cc`:

| Changed region, once per kernel scalar or kernel-string routine | Before | Working source | Delta |
| --- | --- | --- | --- |
| Policy arguments + CALL + bool test/branch, replaced by inline threshold/vsyscall/canonicality | 19 B | 95 B (28 + 21 + 46) | +76 B |
| Five saves and five restores | 18 B | 0 B | −18 B |
| Original argument preservation | 9 B | 6 B | −3 B |
| Task nesting INC/DEC encodings, RBX → R10 | 12 B | 14 B | +2 B |
| Other copy/zero/string/result regions | Same encoding lengths | Same encoding lengths | 0 B |
| **Routine payload arithmetic** | | | **+57 B** |

This is source-literal arithmetic, not emitted code or final installed
bytes. Removing the policy CALL can also affect external relocation
veneers and installation layout, which this table does not count. A
program using both scalar and string forms contains two policy copies in
this design; static routines are not dynamic call counts. The removal of
call/frame overhead can still improve invocation time while this local
payload grows. Record both measured effects instead of inferring either
speed or installed size from the table. The larger compat-read family is
still outside this lowering, as section 2 explains. No rejection gate,
new sharing framework or extra benchmark is proposed by this review.

## User-leaf OTel timing: installed size falls, invocation gain unestablished

Coordinator receipt `1160dc4f6`, run
`corpus/results/x86_kvm_corpus_20261117_063024_376511`, completes the first
user-leaf timing subset. Against the preceding zero-remainder run:

| Observation | Zero remainder | User leaf |
| --- | --- | --- |
| eBPF ns/call | 3374.986 | 3203.124 |
| Native ns/call | 2873.846 | 2899.163 |
| eBPF/native per-call ratio | 1.174x | 1.105x |
| Native/eBPF throughput ratio | 1.202x | 1.076x |
| Cumulative installed native bytes / companion JIT bytes | 135,604 / 167,706 | 135,424 / 167,706 |
| Successful cumulative native replacements | 14 | 14 |

Native invocation time is **0.88% higher**, while eBPF time is **5.09%
lower**. This run therefore does not establish an invocation-time gain
from removing the user callback/frame. It also does not isolate a source
regression from cross-run variation. Native code is 180 bytes smaller in
the paired cumulative load population, independently of the time result.
Neither improvement nor regression is inferred from instruction counts.

The native aggregate now selects two records instead of one under the
existing >=100-call convention. The added `tracepoint__sch` record has
101 invocations and **0.0000551%** of selected native elapsed time;
`native_tracer_e` accounts for the other 99.9999449% and 140,925,219
invocations. Thus that small record's inclusion does not explain the
aggregate change. The baseline remains similarly dominated by the root.
[leaf_read_effect_inventory.py](leaf_read_effect_inventory.py) records
the raw counts/times and exact aggregate arithmetic in
[leaf-read-effects.json](leaf-read-effects.json), preserving IDs within
their own boots and using the existing installed-byte reader.

The new throughput sample ratios are 1.076 / 1.095 / 1.035, from eBPF
40,971,684 / 40,464,510 / 41,926,081 and native
44,080,840 / 44,305,466 / 43,378,243. The coordinator reports zero errors
and a root count ratio of 1.009. These are three 60-second stats-on
samples; no counter scrape or new equal-work proof was added by PERF.
BCC/Tracee timing continues. Keep these observed series and population
labels rather than treating the source's removed operations as a promised
application gain.

### Kernel-leaf implementation and host footprint now landed

`ac7116e0d` lands the kernel-leaf source reviewed above. The coordinator's
[receipt](../kernel-leaf-20261117/README.md) reports kernel payload
**317 → 374 bytes**, agreeing with the review's +57-byte local accounting;
it is still a host payload size, not a final application installed total.
It also reports 40 linker tests, 1,152 kernel-read host vectors including
122 exact-site faults, 193 string vectors and byte-identical user code.
PERF did not rerun those tests. `adc3fc72e` queues the existing image/check/
BCC-Tetragon-Tracee batch after the user-leaf batch. Kernel-leaf app
effects are pending; no concurrent image or competing job was started.

## Closed lead: string-only objects still receive the scalar helper anchor

The extra scalar-helper lookup in `probe_read::share` initially looked
like a possible missed optimization for string-only programs. Source
inspection closes that production lead: `native_loader.cpp:1504–1508`
queries **all canonical helper IDs**, not just helpers called by the
program. It emits each available prototype address and its historical
alias at lines 1536–1543; `native_loader_link_schema.hpp:95–97` puts that
set in the link plan. The non-context construction also includes both
scalar/string names through `kSupportedHelpers`.

In the sole kernel, `kernel/bpf/helpers.c:2191–2198` exposes scalar and
string kernel reads under the same LOCKDOWN_BPF_READ_KERNEL condition.
The scalar anchor therefore does not disappear merely because an object
calls only the string helper. This is not a production string-only LTO
miss, and no extra resolver/fallback/check is needed to fix it. Future
attempts to prune the helper table to observed bytecode calls would have
to preserve existing internal anchor users. No production change,
manual link-plan experiment, guest or build was made for this review.

### User-leaf BCC result: both arms become faster, ratio stays near one

Coordinator run `corpus/results/x86_kvm_corpus_20261117_064150_558773`
completes BCC on the user-leaf image. It reports **1.001x per call** and
**1.005x throughput**, with throughput sample ratios
0.996 / 1.011 / 1.005 (eBPF 525,386 / 521,644 / 523,713;
native 523,417 / 527,223 / 526,543; zero reported errors).

The raw-derived aggregate is 102.710 ns/call eBPF and 102.626 native.
Against the zero-remainder run, eBPF falls **4.65%**
(107.716 → 102.710) and native falls **3.17%**
(105.984 → 102.626). The eBPF/native ratio consequently changes from
1.016x to 1.001x despite the lower observed native time. This is another
reason to keep both arm times alongside the speedup ratio. The baseline
selection contains 16 records rather than the prior run's 15; native
selection stays at 15, so the raw per-program counters remain relevant
to changes in the weighted mixture.

Cumulative installed totals are unchanged at 25 successful replacements,
7,965 companion JIT bytes and 8,334 native bytes. Unchanged sums alone do
not prove byte identity, identical dynamic work or a causal control.
The coordinator's count analysis reports a median native/eBPF count ratio
of 1.001 among 11 active programs, while the two block-I/O records retain
lower native counts (0.262x / 0.248x). Keep that context without excluding
programs or rejecting the run. These are the existing three 60-second
stats-on samples, and they remain separate from the later kernel-leaf
batch aimed at BCC's kernel reads.

The [reader](leaf_read_effect_inventory.py) and
[leaf-read-effects.json](leaf-read-effects.json) now contain both complete
OTel/BCC before/after pairs, including every record selected by the existing
reporting convention. PERF started no guest or extra measurement. No gain
from a particular source operation is inferred from this cross-run pair.

## Compact field displacements in linker-owned map routines

Source/retained-byte review, 2026-11-17. Several field accesses keep a
four-byte displacement even when the bound BTF offset fits the ordinary
x86 disp8 form or is zero. This is a **size** opportunity, with no
instruction-count or measured per-call gain claimed. It follows the
scheduled read work rather than replacing that priority.

`x86_lpm_lookup.rs:4–5` appends an i32 displacement for every `mem` call.
The retained OTel 330-byte LPM body in `otel-typed.blob` contains **11
eligible accesses**, whose displacement fields alone can lose **35
bytes** with the same addressing registers and immediate widths. That
would make this local region 295 bytes before any separate branch-width
change. [displacement_inventory.py](displacement_inventory.py) records
the original instructions/bytes and byte arithmetic in
[displacements.json](displacements.json); it emits no replacement bytes.
The known-LPM direct kernel binding means these historical routine bytes
must not be multiplied across all current programs as an installed saving.

`x86.rs:4022–4031` also forces disp32 for both the LRU reference-byte CMP
and MOV. The retained Katran plan gives `fallback_cache` reference offset
35, so each seven-byte instruction can use four bytes: **six local bytes
per emitted LRU postprocess**. That plan's presence is a field-value fact,
not a count of emitted or executed LRU sites; the inspected historical
Katran payload did not independently establish such a site count.
The current native code at lines 4045–4050 already tests the reference
byte and stores 1 only when it is zero, matching
`kernel/bpf/hashtab.c:823–830`. Keep that work and the null-result check.
An unconditional-store discrepancy was investigated and is **not** present.

These raw bodies are inserted through declared-byte instructions
(`x86.rs:3671–3677`), so later branch encoding does not automatically
compress their ModRM displacement fields. By contrast,
`append_x86_add_rax_imm` at 4076–4083 already chooses the short immediate
form when appropriate; there is no missing short-ADD fix to make.
`x86_memory::Routine::operand` already demonstrates offset-size selection
for its non-indexed operands and should retain it.

For the LPM indexed loads, the final byte of the opcode prefix can be a
**SIB**, not the ModRM. A compact emitter must select the ModRM addressing
mode while preserving the SIB's scale/index/base; copying the memory
helper's `last_mut()` adjustment blindly would change the address.
RBP/R13 zero offsets still require an encoded displacement, and RIP/GS
absolute disp32 forms are different addressing modes. This is normal
instruction encoding, not a new runtime test or BTF-offset restriction.
Recompute branches and later load-site positions from final layout as
usual; no extra validation gate or encoding framework is needed. There
is no production edit, candidate assembly/execution, image build, guest,
whole-image saving or app speed claim in this receipt.

### User-leaf batch complete: Tracee row and current target gaps

Coordinator `8a822b41f` completes Tracee in
`corpus/results/x86_kvm_corpus_20261117_065240_468797`. It reports
**1.118x per call** and **1.068x throughput**: eBPF 367.523 ns/call,
native 328.817 ns/call. Throughput sample ratios are
1.068 / 1.032 / 1.096 (eBPF 339,304 / 345,228 / 335,348;
native 362,333 / 356,251 / 367,484), with zero reported errors.

Against the coordinator's preceding same-image zero-remainder repeat,
native time is **3.74% higher** (316.975 → 328.817), while baseline time
is **0.50% higher** (365.699 → 367.523). Its cumulative installed native
total falls **144 bytes**, from 1,700,836 to 1,700,692, against unchanged
companion JIT 2,068,918 bytes and 169 successful replacements. Both
measurement-window inventories contain 167 records and 41 selected
records per arm. The coordinator's active median count ratio is 1.042;
the `trace_ret_file_`/`trace_file_upda` pair still has a lower native ratio
(0.209x). No program is excluded from reporting here.

The first zero-remainder attempt at 376.436 native ns/call remains beside
its 316.975 repeat in `zero-remainder-effects.json`; the new row is added
to `leaf-read-effects.json`. These differing observations do not isolate
a user-leaf regression, a gain, or a specific noise/work-state cause.
There is no new guest or repeated confirmation from PERF.

The completed three-app subset currently reads:

| App | Per-call eBPF/native ratio | Native/eBPF throughput | Cumulative native / companion JIT bytes |
| --- | --- | --- | --- |
| OTel | 1.105x | 1.076x | 135,424 / 167,706 |
| BCC | 1.001x | 1.005x | 8,334 / 7,965 |
| Tracee | 1.118x | 1.068x | 1,700,692 / 2,068,918 |

These stats-on three-by-60-second diagnostic subsets have not reached
the requested 1.20x per-call or 1.30x throughput targets, and the paired
native/JIT installed ratios are still above 0.5. That records the remaining
work; it does not discard a run or stop the next queued optimization.
The kernel-leaf batch follows, then constant-size reads in the ordered
source work. Final stats-off breadth/floor comparison remains with the
coordinator after this read group, as the 06:20 todo update specifies.

## Kernel globals can avoid MOVABS with an absolute signed-disp32 operand

Source/retained-plan review, 2026-11-17. The leaf routines currently load
`USER_PTR_MAX` and fields of `boot_cpu_data` by materializing the global
address in R11, then reading through R11. For an effective target address
equal to the sign extension of its low 32 bits, x86's **default 64-bit
address-size absolute SIB form** can read that global directly. It needs
neither the eventual native image PC nor another relocation kind. It
still reads the live value on every invocation.

The retained guest plan resolves `USER_PTR_MAX` to `0xffffffffae2e4660`
and the SMAP capability word to `0xffffffffad968ab4`. Both are encodable
in that form, including the captured guest's KASLR displacement.
[absolute_global_inventory.py](absolute_global_inventory.py) records these
actual captured values and boundary cases in
[absolute-globals.json](absolute-globals.json). They are examples, not
assumptions about a future guest: use the actual resolved/rebased address
**including the field offset** to choose the form. Other addresses retain
the existing MOVABS form rather than cause a new refusal. Heap/map pointers
need not fit this range, and per-CPU GS accesses retain their segment
semantics.

| Global access | Current address setup + memory operation | Absolute operand | Local saving |
| --- | --- | --- | --- |
| Load live USER_PTR_MAX into RAX | 13 B / 2 instructions | 8 B / 1 instruction | 5 B / 1 instruction |
| TEST live SMAP word with imm32 | 21 B / 2 instructions | 11 B / 1 instruction | 10 B / 1 instruction |
| MOVZX live width byte into ECX | 18 B / 2 instructions | 8 B / 1 instruction | 10 B / 1 instruction |

The width row is a source encoding case, not a captured width address in
that older plan. For two eligible globals, a user or kernel leaf can lose
**15 local bytes and two executed address-setup instructions** without
changing its memory reads or policy. These are encoding counts only,
not emitted code or a measured application gain. Do not add the capability
row's saving again if boot-time SMAP selection removes that entire read,
or combine it with savings for shortening the displacement of the same
old R11-based access.

The address-size detail is essential: adding `67h` would instead select
32-bit address arithmetic and zero-extend a high-bit disp32 into the low
address space. Use the normal address size and SIB base/index-none form.
The installed iced-x86 decoder sign-extends its 32-bit displacement in
64-bit addressing; its encoder likewise requires the signed-i32 range
and selects SIB for a 64-bit operand with no base/index. The existing
GS-absolute helper forms also use the corresponding absolute-disp32
addressing shape. No assembler or candidate was run for this review.

A RIP-relative global load was considered separately. The frozen direct
module's kind-1 relocation validates a five-byte E8 call slot and patches
only that slot (`kprog/perf/direct-native/bpf_x86_native_lab.c:250–274`);
it is not a generic RIP-relative data relocation. Do not repurpose that
call relocation or add a module ABI change for this encoding opportunity.
The absolute form above works with link-time target addresses and existing
raw literal emission. No pool, extra field, runtime check, cache service,
kernel/module change or benchmark change is proposed.
