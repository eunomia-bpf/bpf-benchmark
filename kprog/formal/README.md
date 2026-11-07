# Native simulator verification

Run the complete local check on an x86-64 host:

```sh
make -C kprog/formal check
```

It requires Lean/Elan, Python3, Rust/Cargo, a C compiler with UBSan,
clang18/LLVM18 tools, GNU objdump, and the `vendor/libbpf` and
`vendor/linux-framework` submodules. The target builds every Lean theorem
module, checks generated contracts and routing, rejects proof placeholders,
and runs the C semantic oracles and executable-reference checks. Papers and
paper/count checkers are not inputs.

The specification is the single executable ISA model in
[`Reference/X86.lean`](KProgFormal/Reference/X86.lean) and
[`Reference/AArch64.lean`](KProgFormal/Reference/AArch64.lean), with the shared
memory, permissions, initialization, effects and faults in
[`Reference/Memory.lean`](KProgFormal/Reference/Memory.lean). Their headers
identify the Intel/Arm architectural sources; they import no simulator or
generated implementation contracts. Unwritten native memory has arbitrary
contents, not invented zeros. Undefined x86 flags and double-shift destination bits are masked by the
relational step instead of assigning them architectural guarantees. Single-step
responses include `defined_registers` when destination bits are undefined. ARM memory and
exclusive accesses carry their explicit architectural/environment inputs;
control uses the current Cortex-A72 base profile without GCS/BTI state. Logical
immediates decode native bitmask fields and reserved encodings, including
SP destinations for AND/ORR/EOR and ZR destinations for ANDS/TST. Their generated
value/width/flag lift preserves the same complete numeric state. Actual logical-immediate
ALU AUX selection and all six TST/ANDS/BICS numeric dispatch rows compose
with their generated operand/value/write/flag primitives. Test aliases retain
DST/SRC routing; register forms retain native shift bounds and SP/ZR rules. Generic ALU_REG
logical forms also compose the generated register RHS with AUX extraction,
including the stack-ORR path and bare NONE modifiers. Non-flag ADD/SUB
likewise retains the stack-SUB and pointer-ADD branches through immediate,
shifted and extended-register numeric dispatch. The actual register-byte codec binds GPR/ZR/SP/NONE reads and writes.
`Arm64Dispatcher.exec_observed_step_refines` composes the actual numeric
`L_EXEC` branch order through scalar operations, ordinary/signed/exclusive
memory, pairs, D0/Q0, FMOV and reductions. Its binding contains field identities;
original native permissions, alignment, pair profile and exclusive environment
witnesses remain separate. It retains actual GPR/ZR/SP32/NONE255 routing,
widths, aliases, modifiers and unused bytes. Q0 retains its two raw8-byte
events; the explicit architectural observation checks direction, adjacency
and lengths before concatenating bytes/init, preserving every ordered byte
address and value. Exclusive monitor/order events are explicit ghost
observations. Neither observation proves concurrent atomicity or platform
ordering. `emission_step_refines` additionally composes B/B.cond, W/X CBZ/CBNZ and
TBZ/TBNZ through the actual source-selected branch shapes. Source labels and
native PC words stay distinct under explicit current/next/target address
identities. A separate CODE-token state projection derives LINK/ADR and
finite CODE-tag BR/BLR/internal-RET primitive refinements, including LR
aliases. `source_emission_step_refines` joins those primitives with every
prior numeric/direct-branch case under the same code-state observation. Its
layout/ordinary-code-value transport is still explicit. RET_TO additionally
derives the raw-zero RETURN arm and finite CODE return arms against the same
canonical register branch, using the invocation outer-LR base. The separate
u32 result equation retains the unresolved ordinary CODE-value condition.
`invocation_emission_step_refines` composes these return routes and all prior
modeled source emissions under one RETURN/CODE frame and literal macro guards.
Faulting writeback, helper/entry/physical-return transport, SKB exit copies,
compiled bodies and full77/72 completion remain open. Focused
checks pass with the published ARM entry-selector repair; the latest complete
check fails in the x86 popcount host harness. Dated results preserve the
exact failure and separate it from focused validation.

The proofs establish arithmetic/flags, register and tag operations, memory
accesses, routing tables, and selected whole-state handler refinements.
[`Refinement/`](KProgFormal/Refinement/) connects generated implementation
slices to those same ISA steps, retaining registers, flags, vectors, memory,
PC and ordered effects/faults. This includes scalar/logical/unary operations,
width/sign extensions, signed and unsigned multiplication, conditional operations, shifts, bit operations,
stack transfers, LEA, DIV, register XCHG, classic ROR, REP MOVS iteration progress and XMM0 successful-access
lane projections, and the ARM arithmetic, vector, memory, exclusive and control
families represented there. Exclusive load/store core lifts additionally compose
the generated native-width memory primitives and W-status writeback, retaining
both outcomes. Monitor state and ordering events are ghost annotations whose
platform witnesses remain explicit; this does not certify ordinary stores as
atomic exclusive operations. D0 load/store lifts compose generated eight-byte
memory operations, upper-half clearing, indexed addressing and the two singleton
dispatch arms, retaining full state, ordered effects and faults under the explicit
SP-alignment witness. XMM0 MOVUPS/MOVAPS references include 16-byte
permission and alignment faults; the two-lane C projection currently requires
successful, suitably aligned access. REP MOVS includes direction, address32,
segments and restart faults; its C core lift requires a matching bounded count,
forward direction, default addressing and successful accesses. Near CALL/RET
uses explicit 48/57-bit paging canonicality (default 48, optional
`state.linear_address_bits`) with CET (IBT and shadow stacks) disabled. The same canonical decoder includes C9 LEAVE64. Under its flat long-mode,
LASS-disabled profile, the complete eight-byte incoming-RBP span is checked
for48/57-bit canonicality before reading; byte addresses wrap modulo64 bits.
Address faults and read faults retain the complete input state. Only success
commits RSP/RBP and PC. Public decode/success/fault/frame lemmas serve wrapper
certificates; read-result lemmas require the proved canonical span. Host
LASS user/supervisor policy, signal delivery RF and the initial ABI remain
platform inputs. The hardware boundary receipt exercises48-bit mode only.
Internal call/return
stack cores are distinct from helper and outer-invocation platform certificates. D0 pre/access/post success cores and their two dispatcher arms additionally
compose generated base updates with the transfer, under explicit accessible-memory
and original-SP alignment witnesses. Their numeric projection still needs Entry/O4
tag and address transport. Faulting pre/post accesses remain a separate obligation.
The scalar writeback lift in `Arm64WritebackMemory.lean` composes the actual
pre/access/post order for ordinary and signed loads/stores, all four widths,
and generated register-offset modifiers. It uses the canonical writeback-alias
restriction and explicit successful-access/original-SP witnesses; its LOAD and
STORE singleton compositions preserve the same complete numeric state and effects.
LDRSB/LDRSH/LDRSW additionally compose their generated opcode, memory width and
sign-operation selections with the same core and numeric family-dispatch gate,
including no-writeback register-offset forms.
LDP/STP also compose the two generated element transfers and pre/post updates,
retaining both ordered effects on the explicit two-access (non-LSE2) profile;
original-SP alignment, per-element access and canonical alias validity remain explicit.
The FMOV/CNT/UADDLV dispatcher tail composes numeric opcode/AUX selection,
all32 vector banks and legacy NONE→V0, generated direction/destination/width
selection and full-state steps; invalid fields retain rejection. Native decoding
and Entry/O4 must bind the typed operands, bank, direction and width flags.
BITFIELD, MOVK and SHIFT compose packed AUX extraction with generated value
operations, typed native bounds and dispatcher gates, independently of unused
AUX bytes. SHIFT also binds immediate/register count selection and the two
generated tables' numeric operation codes. MVN/NEG also compose AUX modifier/count
selection, including the identity modifier and its unused shift byte. MOV binds the two
operand-source tables and the full-width pointer/narrowing branch order;
immediate field31 remains ZR, while register operands distinguish SP and ZR. The eight-member
multiply dispatcher includes UDIV input narrowing, unused alias operands and
explicit X-width validity for long/high multiplies. EXTR/REV/REV16/SXT* bind
the six numeric labels, EXTR-only input narrowing and unused operand fields. A concrete
SHIFT→multiply→unary→CNEG→extract/reverse/extend segment composes the production
branch order and proves that preceding numeric gates cannot intercept later
family members. CSEL/CNEG also
compose whole-AUX condition decoding, NV normalization and the generated
CSEL/X pointer-preserving gate; alias condition validity remains explicit. CCMP also
binds both numeric operand rows and packed condition/fallback bytes: only
the fallback ignores its upper four bits. ADDS/SUBS/CMP/CMN compose their
eight numeric rows and packed modifiers with immediate, shifted and extended
arithmetic steps, preserving writeback versus compare-only behavior.
Individual module statements define their
exact scope. Dispatcher coverage/exclusivity is
**not yet a full simulator-step refinement theorem**; completing the remaining
handler lifts and their dispatcher composition is ongoing work.

The lifts consume materialized native register/address values.
[`EntryEnvironment.lean`](KProgFormal/Refinement/EntryEnvironment.lean)
states the same-invocation SP/code/return relation, with explicit frame biases
and argument/return witnesses. Kernel/JIT, ABI and artifact certificates must
establish those witnesses and code/provenance/profile bindings. A private
stack offset alone is not a native numeric address. The entry arithmetic and
partial-write theorems preserve this distinction. `X86NumericAddress` additionally
relates the actual register representation: RSP stores an offset, other STACK
cells store private arena pointers, numeric partial writes materialize before
merging, and RSP writeback normalizes once. Its MOV-immediate/register lifts
preserve complete native state for all widths, byte lanes and register aliases.
The register CMOV lift derives the same condition from native RFLAGS, retaining
false32 zero extension and the RSP-aware full-width pointer path. Register XCHG
additionally captures both raw pointers/tags/native values before either write;
its low-slice lift retains both ordered merges and every alias, including RSP/RSP.
The production encoder already rejects high-byte XCHG operands.
`X86Dispatcher.step_through_move_refines` composes the actual NOP/MOV prefix
from raw FLAGS/GPR/AUX fields and generated opcode identities under this frame;
its field binding retains native operand/layout facts and excludes no pending
operation from the remaining proof task.
The invocation stack origin and arena origin remain independent; initial ABI,
private-memory and compiled-body correspondence still require certificates.

Trust boundary: Lean checks Lean models, not arbitrary C source or compiled
BPF. The Lean kernel/toolchain are trusted; `native_decide` additionally trusts
compiled evaluation. JSON-to-C/Lean generators, C compilation and native
byte lowering remain cross-language boundaries: freshness checks, independent
semantic oracles, real CPU examples and BPF access checks test them. They do
not prove compiler correctness. Hardware fidelity, verifier acceptance,
platform helpers and artifact/invocation binding require their corresponding
evidence and proofs; a local passing check does not establish them by itself.

Actual linked ARRAY/PERCPU_ARRAY instruction paths are checked against the
canonical x86 model, including bounds, reads and first faults. Inline lookup
blocks emit no helper event; direct map-type calls retain their exact target
and relocation. Callee effects, arguments, map layout, CPU inputs and checked
helper expansion use the [TV platform contract](../tv/README.md#map-lookup-inlining-and-the-proof-boundary-2026-11-07).
These fixture paths are not application invocation certificates.

Layout:

- `KProgFormal/Reference/`: executable reference ISA and shared effects.
- `KProgFormal/Refinement/`: lifts against that reference; other modules in
  `KProgFormal/` retain the original bounded handler/table theorems.
- `contracts/`, `tools/generate_*`, `generated/`, `KProgFormal/Generated/`:
  implementation contracts, generators and emitted C/Lean expressions.
- `oracles/`: retained semantic C hosts, including the former build hosts.
- `tools/`: executable reference, encoding and semantic checks;
  `tools/mutations/` retains the tracked semantic mutation batteries.
- `build/`, `.lake/`: disposable generated/compiled outputs.

The same reference builds as `.lake/build/bin/reference`: JSON lines on stdin,
one complete transition per output line. Inputs provide native bytes, actual
registers/PC and explicit memory cells (value, permissions, initialization).
x86 also supplies XMM0/FS/GS and supports finite native paths whose byte extents
and actual successors are checked. Path outputs are executable representatives;
the producer's definedness evidence must justify observations of undefined state. AArch64 currently accepts one four-byte
instruction per request, with explicit SIMD/environment fields when needed.
The `tools/check_reference*` scripts are concrete examples. They execute these
Lean definitions, not a second Python/C ISA interpreter. F's hardware replay
and T's path/artifact checks consume this same canonical specification.

`conditional_move_word_frame_refines` additionally connects the whole32-bit
AUX condition word to all16 native CMOV conditions, including parity,
through the raw RSP/STACK frame. Both outcomes and false32 zero extension
are derived from generated condition evaluation; no condition-result premise
is required. This component still requires dispatcher/artifact/ABI composition.

`X86Dispatcher.register_dispatch_step_refines` composes the same raw-field
NOP/MOV prefix with register CMOV(all16 conditions), BSWAP, POPCNT and XCHG
through generated singleton opcode gates. Its binding contains only operand/
width/AUX/PC identities; BSWAP ignores SRC/AUX/immediate, POPCNT and XCHG
ignore AUX/immediate, and CMOV reads the entire AUX word. All widths retain
absent0-to64 resolution. Other opcodes remain outside this partial theorem.

The raw register-frame BSWAP and POPCNT lifts compose generated byte reversal/
population count with materialized native reads and scalarizing writeback,
including RSP and STACK aliases. POPCNT derives all flag outputs from the
captured input, while BSWAP preserves flags. Memory forms and compiled-body/
ABI transport remain separate.

The same-slice XOR specialization is also proved through the raw frame:
generated ALU/flag primitives on literal zero operands plus the actual lane
writer refine XOR of the same native register slice. Other byte lanes remain
unchanged. The raw producer predicate and compiled C/BPF body are separate.
