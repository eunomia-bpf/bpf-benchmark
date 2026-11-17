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
| 3 | Constant tail slots use the indirect path (section 8) | Cilium, OTel; constant sites in Tracee/Tetragon | Installed Cilium JIT has patched direct jumps; native retains map bound and target loads. A constant-slot LTO subset can remove bound/index bookkeeping, while full direct patching needs the existing map-update/lifetime contract. |
| 4 | Unknown map path nests ARRAY, LPM and generic helper calls | OTel residual dynamic maps, Katran; potential BCC/Cilium/Tracee sites | Remove two extra call/return pairs and their stack adjustments on a non-ARRAY/non-LPM fallback; bind a concrete operation where type facts suffice. Retained Katran dispatcher costs are small, so this alone does not explain its entire gap. |
| 5 | Proven ARRAY accesses always cross a shared call boundary | OTel, BCC, Cilium, Katran where these sites execute | Selectively expose small constant-key accesses to LLVM, removing call/key materialization and enabling folding. Blanket inlining would undo demonstrated size savings. |
| 6 | Map identity is discarded at every basic-block boundary and memory reload | All five, site dependent | Recover additional direct lookup/update/delete bindings using actual provenance. Dynamic inner-map identity must remain distinct from its known type. Static source opportunity; no new hot-site count is established here. |
| 7 | Finite helper-ID joins become another runtime compare chain | Tetragon; other helper-selecting sources | Propagate/split a proven selection earlier where possible, avoiding repeated ID redispatch. Source-confirmed shape; production hot frequency and gain are unmeasured. |
| 8 | Exact hash key length stops before the LTO plan | Katran, BCC, OTel hash sites | Current JIT/native use the same runtime-length kernel lookup. Exact-shape specialization remains a distinct, unmeasured opportunity; the copied-hash comparison did not test a separately specialized function per proven key length. |

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
