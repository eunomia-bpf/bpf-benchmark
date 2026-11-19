# Cilium head-length bounds

`archive_validate.sh` tests the remaining historical acceptance question.
It reuses the41 emitted B objects and the production`relocate_trusted_proof`
function, creates fresh maps with captured shapes (including inner maps and
direct-value offsets), and stock-loads each object on the sole guest kernel.
Each request retains its command, verifier log and completion before the next.
These detached, empty maps test verifier acceptance; they do not reproduce
live map contents, native binding, application execution or performance.
No compiler, runtime image or benchmark configuration changes are required.

Worker487083 completed0 at2026-11-19T23:11:02Z. The boundary-equality
repair852c2bfe3 passes16 positive/eight exclusion selectors, five freshness
cases, six sole-kernel fixture loads and18 packet TEST_RUN cases. Fresh
Cilium run230826_548703 is appok with14/14 stock verification receipts
(phaseverify/status0) and14 checked-sim-c installs, versus8/14 previously.
This closes the six packet failures in that current population.

The historical41 and current-six replay sets all emit B, with367 and408
lowered predicates respectively. `replay.py` invokes the compiler/backend;
it does not stock-load these objects. Thus archived41 stock acceptance is
still unmeasured by this run, despite the peer class-closure record.
Historical store/emitter/arming defects and performance remain separate.
`edge-result.json` records these outcomes; full receipts are in raw
`edge-candidate-20261119T225223Z-487083`, including`coverage.json` and
`cilium/service.tar.gz`. The earlier queued/candidate status below is history.

PERF 2026-11-19T22:39Z: worker366677 completed0, fresh app status`ok`,
run `x86_kvm_corpus_20261119_223501_349942`. Its service journal contains
14requests: eight stock passes and six packet rejects, all successful native
installs. The shim records85 manifest misses plus14 replacements. This is
a different service population from the historical64; coverage of the
historical41packet/sixstore set remains a separate objective.
`fresh-coverage.json` reads each request's own capsule and records native
hashes, verifier receipts and error tails. The reader now derives identity
from the supplied archive; request ordinals from other runs carry separate
meaning. Its historical regression still yields14/41/6/3.

Allsix current rejects are `tail_no_service_ipv4`: requests4,5,8,9,11,14.
Their byte16 read at130 uses the same packet base that has range16, so the
SSA placement works there. The remaining path is a different branch:
the 18byte guard at125-128 can fall through via its pointer comparison,
then the scalar equality at129 leaves the byte16 access reachable with
range16. Bounds/equality branch correspondence is the next compiler defect
to reproduce. The full raw run and both replay sets remain preserved.

PERF 2026-11-19T22:35Z: validator366677 rebuilt the canonical compiler from
238c643fc at22:32:52Z and completed the focused compiler/stock checks.
All12 positive/eight exclusion controls and five data-freshness cases pass.
The five packet fixtures load on the sole guest kernel; all four packet
TEST_RUN cases return their expected values. The TC class fixture also loads,
with four TEST_RUN cases preserving the low16bits of marks0,65535,0x12345678
and0xffffffff. All41 packet captures and allsix store captures emit B,
each replay target exits0. `subset-result.json` records these separate outcomes.

The request7 replay now bounds the packet base in r1 at instructions24-26;
the retained data reload writes r2 at27, while the read at28 uses r1+20.
This shows the intended placement in an actual captured program. Fresh Cilium
started22:33:12Z on CPUs18-19 through the existing checked-corpus target;
its per-request stock acceptance and application result remain pending.

PERF 2026-11-19T22:34Z recovery: `ff8f0e4b3` shares the SSA value of
dominating public packet-data reads across intervals with preserved context.
Original reads retain their ordering effects; `8ec55e8b7` checks plain,
readonly, private-store, mutating and stale-identity cases. The same compiler
batch canonicalizes the six TC class stores through the frozen public accessor.
The minimal repair covers these two B compiler defects and their focused
regressions; native P, producer flags and workloads retain their definitions.

Validator366677 queued at22:28:23Z under imageEX, followed by imageSH for
the existing controls, stock fixtures, 41 packet replays, six store replays
and a fresh Cilium checked-corpus run. Raw:
`/workspaces/kprog-raw/perf/cilium-headlen-20261119/check-20261119T222823Z-366677`.
The canonical compiler rebuild precedes these tests. Its guest verdict is pending.

Two earlier runs are terminal. Worker303179 ended2 at fixture emission:
llc reported `symbol 'license' is already defined`; the fixture now uses
`fixture_license`. Worker351151 ended2 after all12 positive/eight exclusion
controls and normal B emission passed: stock rejected `head_ge` at instruction15,
packet byte23 through the reload at14. Its source predates the SSA repair.
Raw directories retain both command histories and the verifier log; see
`validation-history.json`. These outcomes supersede their queued status below.

PERF 2026-11-19T21:07:34Z. This is the phase-1 compiler repair for the 41 archived
Cilium `invalid access to packet` requests identified in
[the measured handoff](../cilium-packet-bounds-20261119/README.md).
The six trusted-sk_buff store failures and three live-table generation failures
remain separate. The established previous stock-verified count is 14.

Candidate `cdd26e9cd`, refined through `650994842` and `80dbcfc51`, recognizes
classifier sections, the simulator's exact asm u32 field reads and ALU32
identities, and the frozen kernel's i32 `len - data_len` head length.
It retains the scalar predicate and expresses its implied packet bound using
the public context data/data_end fields. Native P and its frontend IR stay
unchanged. Kernel `include/linux/filter.h`'s `bpf_compute_data_pointers` and
`include/linux/skbuff.h`'s `skb_headlen` establish the identity; `layout.c`
checks len112/data_len116 and their u32 widths against the actual target header.

The fresh public span must still describe the captured head length.
`80dbcfc51` walks predecessor paths back to each field read, including loops,
and leaves the original predicate unchanged across possible skb mutation.
Proven reads, register identities, kernel casts and private alloca stores
preserve this fact. This adds no runtime test or limit.

Current controls contain 12 positive forms and eight exclusions. They include
explicit LLVM predicates to avoid duplicate comparisons produced by Clang,
strict/inclusive 42/43-byte bounds, readonly loops, mutating loop backedges,
and intervening helper/asm writes. Against the installed old compiler,
only the two original spans match, the ten new forms miss, and all eight
exclusions remain unchanged. `freshness-before-result.json` records this
expected baseline. Final candidate syntax and target layout checks pass;
these are not candidate B or stock-verifier results.

The committed `validate.sh` runs under image EX only for the one canonical
compiler replacement, then image SH for controls, captured Katran replay,
five stock fixture loads/four TEST_RUN cases, all 41 captured frontend-to-B
replays, and the existing fresh Cilium checked-corpus entry. Functional guests
use CPUs18-19, without the timing lock. Host replays use CPUs8-11 with four
workers, each inheriting an 8GiB address-space limit. All LTO pieces and the
uniform app flags remain on. No archived frontend is recompiled from C.

Final worker303179 is parented to PID1 and queued at2026-11-19T21:06:31Z.
Raw: `/workspaces/kprog-raw/perf/cilium-headlen-20261119/check-20261119T210631Z-303179`.
Launch log: `/workspaces/kprog-raw/perf/cilium-headlen-final-launch-20261119.log`.
The active coordinator image reader is preserved. Earlier unstarted waiters
269752,296915,298900 ended143 and all their raw directories remain.

OMP independently reports 40/40 B emissions and235 pointer bounds from the
earlier candidate. That is useful compiler evidence, but it predates the
freshness correction and establishes neither stock acceptance nor bytewise
parity on other apps. PERF uses the canonical compiler, not the peer's
`/tmp/pbt/pb-new` diagnostic build. The fresh guest's per-request journals
will decide coverage; a successful fixture or B emission alone does not
close the 40-request acceptance objective. No runtime gain is claimed here.

Historical journal reconciliation, PERF 2026-11-19T21:12:20Z: `coverage.py` reads the
actual archived service journal and each stock-success verification receipt.
There are exactly14 `b_stock_passed=true` records, each with `phase=verify`,
`status=0`: requests1,2,4,5,8,13,30,34,39,46,51,52,54,62.
The remaining classes are40packet rejects,6store rejects,3generation failures
(22,40,58) and1terminal failure. Execution paths are14checked-sim-c,
49direct-native and1unreported. The handoff's17-class tally includes the
three generation failures, which have `b_generated=false`,
`b_stock_passed=false`, and `execution_path=direct-native`. Their successful
native installation does not establish stock acceptance. The original
handoff is retained; `historical-coverage.json` records the actual distinction.
Raw `/workspaces/kprog-raw/perf/cilium-headlen-20261119/journal-20261119T211300Z`. This is archive analysis, not a new run.

OMP's later independent replay, recorded in `f660709bb`, covers final
`80dbcfc51`:233predicates across all40requests, with two possible-write
predicates left unchanged. This supersedes235 as the reported final-source
lowering count; canonical worker303179 and actual stock acceptance remain
pending at 2026-11-19T21:27:36Z. The independent count is compiler evidence only.

PERF 2026-11-19T21:41:43Z: request64 extends the packet class to41. Its failure capsule
retains generated B and the rejected two-byte packet read at offset18.
`prepare.py` now reads the service journal's success **and failure** capsules;
selection comes from their inner verifier errors, not the outer completion
status. Retained index `/workspaces/kprog-raw/perf/cilium-headlen-20261119/inputs-41/inputs.json` has41requests,
reuses every original40frontend path, and adds request64 only. The original
40-input index and raw data remain unchanged. The queued `replay` make target
now takes this explicit index; validator303179 and its shell recipe remain
in place, with no cancellation, new compiler, or new guest.

`capsule-coverage.json` corrects the journal-only reading in the historical
receipt:14stock passes +41packet rejects +6store rejects +3generation
failures =64. Packet requests comprise40working direct-native fallbacks and
one hard failure (64); the49working direct-native paths also include the
six store and three generation failures. Outer journal fields remain as
recorded, including request64's missing B fields; the capsule proves its B
exists. This adds failure detail without inventing a stock pass.

The second request64 failure needs precise interpretation. Its log says
`arm kernel native image: No such file or directory`; this is the **arming
ioctl**, not a file-open error. `native_lab_store_chunk` calls
`native_lab_active_capsule` before allocating the image. That lookup returns
ENOENT when the active job is absent, abandoned, or has another request ID.
The archive does not distinguish those branches, so it does not establish a
missing image file. The binding failure remains open independently of packet
verification. `request64.json` records the original errors and source trace.
No loader/module/kernel change was made.

OMP reports2lowerings/3emitted bounds for request64 in addition to233lowerings
across the earlier40. Canonical41-request B/stock acceptance still awaits the
queued worker. The host7.3control is supporting evidence; it is not the
workspace7.0guest verdict. AllLTO/appflags/settings remain unchanged.

PERF 2026-11-19T22:53:57Z: canonicalization ff8f0e4b3 remains the selected
placement. Worker366677 completed the focused stock fixtures and41packet/six
store B emissions. Its fresh capture has14requests,8stock passes and6packet
rejects; `fresh-coverage.json` retains that separate population. The six
current inputs are retained in `current-six-inputs/inputs.json` under the raw
result root through the existing `make prepare` entry, extended by bc0a32641.

The focused head_edge baseline481274 reproduces the current rejection on the
sole kernel: `off=16 size=1, R2(id=0,off=16,r=16)`, verifier.log112. A16byte
range covers offsets0..15; byte16 needs17bytes. Actual request4 B pc129 skips
the read on EQ16, and pc130 reads byte16 on the other edge. Its original
frontend uses one i32 span%357 for ULT16/ULT18/EQ16, while len112/data_len116
read through kernelcast%27=bpf_cast_to_kern_ctx(%0). Those field reads and
packet reads have separate roots. `edge-baseline.json` preserves exact paths.

Candidate852c2bfe3 expresses boundary equality as an equivalent ordered
scalar predicate under its dominating interval, then applies the existing
packet-bound lowering. Under x>=K, EQK becomes ULEK and NEK becomes UGTK;
upper-bound cases are symmetric. Four new selectors detect that translation;
a bypass-edge case retains EQ. The installed compiler fails the lower-bound
selector as expected. Syntax passes. Worker487083 queues the sole compiler
rebuild under imageEX, followed by focused stock execution, historical41 and
current6 B replays, then fresh Cilium through checked-corpus. Actual candidate
stock acceptance, app coverage and performance remain pending.
