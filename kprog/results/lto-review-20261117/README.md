# LTO performance review

2026-11-17T00:18:07Z. Source reviewed at f821e1c77; kernel
83e0fabe355d. This is a source and retained-output review, with light host
reads on CPUs 16–19. No source was changed, tool built, image published or
guest started. The coordinator owns implementation. Recommendations below
introduce no new runtime check or admission gate.

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
| 1 | Probe reads retain generic size loops and repeated CPU feature selection | OTel; kernel-read sites in Tracee/Tetragon; BCC | Specialize common small reads; avoid 8/1-only copying and repeated SMAP capability selection. Large opportunity in OTel's retained read range; selective variants can grow code, so retain sharing. |
| 2 | Compat reads bypass that lowering entirely | Tracee, then Tetragon where present | Address-domain/size specialization can remove wrapper/copy overhead while preserving the helper's user/kernel choice. Actual Tracee blobs retain 2,375 read and 714 string call sites. This is an opportunity shared with the JIT helper, not evidence of a native-only regression. |
| 3 | Unknown map path nests ARRAY, LPM and generic helper calls | OTel residual dynamic maps, Katran; potential BCC/Cilium/Tracee sites | Remove two extra call/return pairs and their stack adjustments on a non-ARRAY/non-LPM fallback; bind a concrete operation where type facts suffice. Retained Katran dispatcher costs are small, so this alone does not explain its entire gap. |
| 4 | Proven ARRAY accesses always cross a shared call boundary | OTel, BCC, Cilium, Katran where these sites execute | Selectively expose small constant-key accesses to LLVM, removing call/key materialization and enabling folding. Blanket inlining would undo demonstrated size savings. |
| 5 | Map identity is discarded at every basic-block boundary and memory reload | All five, site dependent | Recover additional direct lookup/update/delete bindings using actual provenance. Dynamic inner-map identity must remain distinct from its known type. Static source opportunity; no new hot-site count is established here. |
| 6 | Finite helper-ID joins become another runtime compare chain | Tetragon; other helper-selecting sources | Propagate/split a proven selection earlier where possible, avoiding repeated ID redispatch. Source-confirmed shape; production hot frequency and gain are unmeasured. |

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

## 1. Read lowering keeps work that constant-size specialization can remove

Source: `kprog/x86/native_lab/native_link/src/x86_probe_read.rs:28–38,
59–108,118–146,150–173`.

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

## Existing work that should stay, and attribution limits

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
