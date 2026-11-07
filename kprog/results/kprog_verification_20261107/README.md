# Lane V verification checkpoint

Published source increments retain the previous theorems and semantic oracles.
This checkpoint archives the results before removing finished private exports,
scratch probes, raw output and private Git indexes. Shared Lean/Cargo caches are
retained; no clean rebuild is required.

| Published increment | Validation observed |
| --- | --- |
| `1b114d3e45c83fd8ac41814a4e0f3758df2342c7` classic ROR | Full `make check` exit 0 |
| `0f118e0e606e94240ede73a6ebec30f79e2cde99` MULX | Full `make check` exit 0 |
| `6d84c21c37ef24d824567cf7ee3cf612c1e35472` SHLD/SHRD | Full `make check` exit 0; undefined destination bits are relationally masked |
| `5e2dc9999fb2a3e4b163d8fe36da705875a460b1` XMM0 | Full `make check` exit 0; 2176 CPU cases, 32 actual faults, 128 GNU encodings and 8872 reference states |
| `590894d60723243b8363e420ef954c90c5c476b5` REP MOVS | Exact published full `make check` exit 0; 1120 CPU cases, 64 restart faults and 1774 reference states |
| `0fb9f53597ae49a1e36aca118afa6e30ac32e507` near CALL/RET | All Lean modules built; 440 CPU cases and 1279 reference states including four CALL/RET paths; existing REP, XMM, conditions, paths and ARM reference regressions passed |
| `d495572d3b9124d7b9ac9116f2145ef6e9a55883` named-map fixture | Focused exit 0; all 90 ARRAY/PERCPU_ARRAY full-state paths and four named direct-call targets retained; two opaque-map controls retain the generic helper target |
| `X86RegWrite.lean` projected byte-MOV lemmas in this commit | Incremental `lake build KProgFormal.X86RegWrite` exit 0 |

`call-cpu.jsonl.gz` retains the final 440 native CPU observations. The focused
CALL/RET run v7 explicitly built all Lean modules; v8 verified identical Lean
source hashes and strengthened page-fault read/write/fetch-bit and fault-address
checks. Both exited 0. Earlier failed proof scripts were proof elaboration
failures, not discarded native inputs. The semantic failure found during this
work is retained in `call-fault-priority.json.gz`: CALL to a noncanonical target
with an inaccessible stack faults on the stack access first. The corrected
canonical step and final CPU suite enforce this ordering.

The map fixture's first attempts exposed lost identity through a non-PIC LEA,
then the intentional raw-ELF proof-ABI rejection, and finally the loader's zero
MOVABS relocation placeholder. The published fixture uses legitimate proof-mode
normalization with PIC/GOT identity and applies the typed map-pointer patches;
it bypasses no production check and changes no production selector.

The two projected byte-MOV lemmas preserve prior useful proof work; they do not
enable a link-time optimization. Those optimizations are deferred by the current
operator priorities.

The combined post-cleanup full check at exact `aacc36597` exited 2: three
modules importing both X86RegWrite and X86ShiftResult encountered duplicate
`GeneratedX86Width.Width.enumToBitVec` definitions. The forward fix preserves
the MOV theorem statement and exposes its constant-width bit-vector goal before
`bv_decide`. All three affected import compositions then passed an incremental
81-job focused build. A new combined full check is required after publication.
None of the
focused results above establishes all 77/72 handler refinements or a complete
dispatcher-step theorem. XMM C lane projection still assumes successful aligned
access; REP C core assumes bounded matching count, forward/default addressing
and successful accesses. CALL/RET internal core lifts require materialized native
addresses and access/canonicality witnesses; helper and outer-invocation
certificates remain separate. The CPU profile is trusted environment data:
48/57-bit paging with CET disabled, not authority supplied by an application.

The subsequent ARM exclusive core increment composes generated LDAXR-width reads,
STLXR-width stores and W-status writes with the same canonical monitor semantics.
Load refinement includes native access faults after explicit SP/natural alignment
witnesses. Store refinement includes either externally supplied failure-bit
outcome, source/status aliases, and preservation of all other state. Its failure
preflight condition permits inaccessible memory when the architecture does not
check it. The success/failure bit must equal the canonical monitor/commit result;
monitor state and acquire/release/conditional-commit events are explicit ghost
annotations requiring a platform witness, not implemented C monitor guards or a
proof of hardware atomicity. The new proof and the three x86 import-composition
regressions passed; existing exclusive wire checks passed 82 complete-state,
effect and fault cases and 10 encoding/input rejections. One early proof attempt
failed on redundant record updates in the failure arm; restructuring that arm
removed the redundant update without weakening any theorem or filtering inputs.

## Published whole-check result

Exact `6e64f4a3e91b407c4ee5ce46c581080b9e667c27` completed
`make -C kprog/formal check` with exit **0**. The immutable export included the
CALL/RET, named-map fixture, import-composition fix and exclusive-core proofs;
all Lean modules, reference regressions, generated contracts, compiler/wire
checks and existing C semantic/route hosts passed. The final existing ARM stack
arena route host checked 2,814,832 cases and the decode host 1,410 cases.
The temporary source/cache export was deleted immediately. Its obsolete raw
outputs are removed after this summary is committed; shared incremental caches
are retained. The compressed CALL CPU observations now come from this successful
whole-check run rather than the earlier focused v8 run. Later source changes
require their own validation; this result does not include the subsequent D0
full-state proof work or other lanes' uncommitted runtime changes.

## D0 handler and native pointer-read increment

The concurrent V continuation published `b1cc1a232` (native pointer-read fix and
compiler regression) and `ce776d453` (D0 full-state/index and two singleton-arm
composition). The local continuation verified the same source bytes and keeps
those commits. This follow-up enables UBSan on the two existing real DQ/vector
route hosts and lets Clang's actual target definitions select the BPF path; no
synthetic `__BPF__` definition is needed. A duplicate pointer-check recipe added
by the overlapping continuations was removed before publication.

Validation: incremental Lean/reference build passed; 959 addressed/vector
complete-state cases and 18 precise rejects passed. Existing real DQ and vector
route hosts passed 62,418 and 62,445 cases with UBSan. The new primitive check
passed 512 native reads covering every alignment, and six actual compiled BPF
functions retained exactly one 8-byte read at the required address, including
literal context offset88, negative offsets, signed16 limits and the large-offset
path. Existing simple_packet and cilium_ct_nat_tuple_rewrite ARM micro programs
compiled successfully with the production BPF flags.

The original pointer macro had C alignment/effective-type UB on unaligned ABI
reads. Alignment1 alone was rejected: it fixed host UB but compiled into eight
reordered byte reads. The final primitive keeps an exact-width typed BPF read
and preserves literal context displacements; the host branch uses an aligned1,
may_alias pointer type. `arm64-pointer-counterexamples.json.gz` retains the
failing primitive and numeric byte-access counterexample. No inputs, sanitizer
checks or architectural effects were removed to obtain passing results.

D0 proofs currently cover V0 native8B loads/stores without writeback, including
immediate and extended/scaled register offsets, exact effects/faults and all
other state preservation under the explicit SP-alignment witness. The checked
memory branches introduce no new C runtime permission guards. Pre/post writeback
and Q16B versus two8B effect composition remain separate obligations; these two
singleton arms are not the complete72-operation dispatcher theorem.

The interrupted V continuation also left a validated base-update draft. Its
SP/GPR/zero-delta cases are now retained in Arm64VectorMemory. The universal
`bump_refines` theorem connects the actual numeric update branches to canonical
base writeback, and `writeback_base_refines` composes the generated pre/post
deltas for all three modes. Incremental Lean build passed (27 dependency jobs).
This preserves the draft's useful proof work; it proves base-update algebra,
not the outstanding intervening-memory/fault composition for a complete
pre/post-indexed D0 handler.

Exact `ef02edb2f7ced694a25efe0bc05f148d0e503f21` subsequently completed
`make -C kprog/formal check` with exit **0**, including the D0/index/singleton
proofs, writeback base algebra, native-pointer compiler regression and both
existing DQ/vector route suites under UBSan. All other Lean modules, generated
contracts, reference/wire/compiler checks and C semantic hosts also passed.
The immutable source/cache export was deleted immediately. The compressed CALL
CPU observations have been refreshed to this successful full run. This result
precedes the subsequent full D0 pre/access/post transfer composition work.
