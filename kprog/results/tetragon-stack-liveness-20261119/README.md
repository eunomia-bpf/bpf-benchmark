# Tetragon retained B stack pressure

Inspect request 6's retained O1 pre-PEI MIR after the existing scalar packing
pass. The earlier emission diagnostic found a 5,776-byte direct R10 depth;
production compilation failed at 4,096 bytes, before stock verification.
Neither limit nor the simulator source changes in this experiment.

`inspect.py` reads the MIR once, records declared objects and computes
conservative backward byte liveness over its actual CFG. Partial writes kill
only their written bytes. Address-taken and unfamiliar slot accesses are
excluded from the lifetime claim.
The analysis reports peaks, rather than assuming every declared spill is
live at once. It does not establish path feasibility, a safe coloring, stock
acceptance or any runtime gain. Its join/loop/partial-store regression passes,
including preservation of the upper four live bytes across a 32-bit store.
The launcher compares the same retained MIR before and after scalar packing.

Run through the local Makefile under timing SH on CPU 19 with an 8 GiB
address-space bound. Retain the source revision, commands, output and status
under `/workspaces/kprog-raw/perf/tetragon-stack-liveness-20261119/`.

PERF 2026-11-19T11:28:45Z: Worker 350737 completed with status 0, source
a170310b4, raw `inspect-20261119T112410Z-350737` under that directory.
Both versions contain 438,579 machine blocks. Before packing: 721 objects,
5,764 declared bytes, 614 eight-byte and 105 four-byte spills. After:
670 objects, 5,772 declared bytes, 667 eight-byte and one four-byte spill.
The two non-spill objects occupy 8 and 424 bytes. Declared size omits padding;
the earlier emitted 5,776-byte frame remains the actual emission diagnostic.

Both versions reach a conservative 3,996-byte live-spill frontier at
bb.176466 and bb.183521. These include 707 separate objects before packing
and 655 afterward. Only the address-taken 424-byte arena is excluded from
spill analysis. Packing adds one scratch object and merges 52 scalar pairs;
its whole-word operations do not reduce this byte frontier. These CFG unions
are not a proof that all paths are simultaneously feasible or that a physical
frame cannot shrink. Repeating the previous O3 experiment is unwarranted.

There is a concrete earlier folding opportunity at the first peak:
`trusted_x86.bpf.before.mir:533576` and `:533578` contain ALU32 self moves of
constant 8 and 4. LLVM retains comparisons against those outputs and a large
stack-tag update fanout after helper 4 (`peak-source.txt`). The shared macro
`x86_sim_local_bpf.h:664` intentionally materializes an ALU32 move to preserve
scalar bounds for live inputs. `packet_bounds_ir.cpp:139` only folds empty
`=r,0` identities, so it misses this constant-only case. A typed i32 self move
of a constant can fold without changing live-input ALU32 materialization.
This is the next targeted hypothesis; no production compiler fix, new B
acceptance, guest, image or runtime result is claimed here.

PERF 2026-11-19T14:15:12Z: The constant-ALU32 hypothesis above has already been
implemented and tested (0cb83f15d); its retained Tetragon replay worsened
allocation to1,804 spills and8,076 conservative live bytes. Current packing
cannot reduce its declared payload below7,648B including locals. The owned
packer was cancelled after that result, with no llc/stock rejection claimed.
See results/constant-alu32-20261119 for the exact negative result; repeating
that frontend or O3 experiment would not resolve the remaining class.

Source review identifies a narrower next inventory: render_program at
generate_micro_sim_proofs.py:1926-1928 emits one ghost-cache entry for every
eight-byte arena word. The retained tetragon6/trusted_x86.bpf.c preamble in
b-analysis-flags-20261119/production-20261119T063707Z-211523 declares424B
and M(0) through M(52):53 cache cells. Shared x86_sim_local_bpf.h:325-332
materializes each as a named tag and pointer, and :350-357 invalidates these
cells for helper-written byte ranges. That is the fanout seen after the
probe-read call in peak-source.txt. The ordinary byte arena already uses
indexed accesses; the separate ghost cache retains provenance.

Only STACK tags carry a pointer representative, but ABI, packet and map
value tags also affect restoration (:359-373). Consequently dropping
pointer cells by numeric address or by unused byte storage is not a valid
pruning argument. In x86_abi.py:48-51 the incoming context is represented by
alias False, and the same coarse alias class also represents scalar values;
False is not evidence of a SCALAR interpreter tag. Unknown aliases likewise
provide no dead-cache proof. Merely replacing the named cells by a variable
pointer array has no demonstrated stock-verifier or semantic benefit.

The useful next evidence is a conservative inventory of possible full-width
cache save/reload positions, including aliases, push/pop and call frames,
using the existing finite CFG information. The shared save sites at
x86_sim_local_bpf.h:1709 and :1722 distinguish register stores from scalar
byte writes, which only invalidate metadata. Such an inventory is diagnostic
first: this review does not establish that any of the53 cells can be removed.
Unknown positions retain their current representation rather than causing a
new generation refusal. No shared-I change, selector, check, limit, build,
profile or guest was introduced by this review. Any later transformation
uses the existing specialization interface and preserves pointer tags and
released-stack behavior; native byte trimming is not the objective here.

PERF 2026-11-19T18:06:06Z: Read-only cache inventory7ca5d9ee9 uses Python's call/return
profiling to observe the unchanged ABI analysis during generation from the
retained Tetragon6 proof and its original request metadata. It records
full-width store locations, unknown destinations, pointer-dictionary
offsets and unknown-RSP states. False aliases still combine scalar and
external pointer cases; push/pop/call frames and helper copies need
conservative treatment. No cache elimination or production change follows
from this inventory alone. No C frontend, backend or image is built.

Worker193484 is detached under timing SH, CPU20/4GiB AS, with persistent raw
/workspaces/kprog-raw/perf/tetragon-cache-inventory-20261119/inventory-20261119T180509Z-193484.
Only queued/run.log exist at18:05:34Z; no analysis pass is claimed. The
existing pointer-difference stock confirmation186985 remains separately
queued on batch EX behind the coordinator's six-app check.

PERF 2026-11-19T18:11:03Z: Inventory195833 completed0 frome9d43500b at18:09:17Z,
with2,538ABI states and18call contexts. Stack extent420 rounds to the
original424-byte arena/53cells. It observes91full-width store sites:
39have known stack offsets,52are external,0have unknown destinations.
There are17distinct direct-store offsets (one unaligned at-212),
45pointer-dictionary offsets including0 and-212, and43negative aligned
offsets in the arena. All observed RSP states are exact. This inventory
does not prove the other10cells dead: its dictionary also contains call
return facts and helper-copy effects, and False source aliases include
external pointers as well as scalars. Source-level cache save/copy/frame
coverage must establish any pruning argument; no production pruning,
B acceptance or runtime gain is claimed.

The focused run used CPU20/4GiBAS for18:09:13Z..18:09:17Z alongside the
coordinator BCC check. The non-verbatim all-host timingSH wait was relaxed
for this read-only diagnostic only (AGENTS.md allows relaxation when
blocked); old unstarted193484/193489 ends143, raw preserved. The stock
confirmation186985 remains queued on its original locks. Compact actual
counts: cache-inventory-result.json; full raw inventory/logs at
/workspaces/kprog-raw/perf/tetragon-cache-inventory-20261119/inventory-20261119T180913Z-195833.

PERF 2026-11-19T18:14:09Z: Follow-up source coverage narrows the next compiler item. In
the current shared header, only MOV_STORE_REG's direct-stack and tagged
stack arms call STACK_VALUES_SAVE (:1709/:1722), for full-width unshifted
register stores. PUSH/POP and native CALL use raw bytes through STACK_WRITE,
which erases facts (:824), while helper wrappers (:3937-3954) only
clear/erase/filter cache facts. They do not create copied pointer tags.
The inventory's17direct-store offsets therefore include16aligned arena
cells and one unaligned start(-212); its43dictionary offsets are a looser
ABI-analysis set, including return/copy bookkeeping. Sparse cache
enumeration from conservative destination aliases is the next compiler
item, with unknown aliases retaining the complete current enumeration.
No production pruning or preservation result is claimed. Source/destination
tag coverage, finite alias joins, loop widening, released-stack behavior
and the inline bindings must be covered before using a sparse list.
