# Native simulator verification

This directory executes the actual exported kprog C simulator bodies in
Clight and proves correspondence with external Lean ISA models. The goal is
refinement for every implemented operation and one composed dispatcher-step
theorem per ISA. That complete argument is still in progress; the
[worklist](../docs/todo.md) records the remaining work.

## Specification and layout

- [Reference/](KProgFormal/Reference/) contains the shared specification
  bindings used by proofs and executable differential tests.
  [X86.lean](KProgFormal/Reference/X86.lean) binds
  [x86lean](external/x86lean/); [AArch64.lean](KProgFormal/Reference/AArch64.lean)
  binds [LNSym](external/LNSym/). Git records the pinned submodule revisions.
  Numerical instruction semantics live in those external models.
- [ClightRefinement/](KProgFormal/ClightRefinement/) contains actual-source
  execution, memory, caller and native-state refinement proofs.
  [KProgFormal.lean](KProgFormal.lean) exposes the integrated library.
- [c/](c/) contains C export profiles. The existing Clight export target
  generates imports from them; [build/](build/) holds build products.
- [oracles/](oracles/) and [tools/](tools/) contain semantic comparisons and
  their drivers. [ReferenceMain.lean](ReferenceMain.lean) uses the same
  specification bindings as the proofs.
- [results/](results/) contains scoped receipts, commands, validation output
  and public type/axiom queries. [HISTORY.md](HISTORY.md) preserves the prior
  narrative. The coordinator-authorized [retirement inventory](results/legacy-retirement/README.md)
  records the obsolete JSON/generated-contract route; it is not an active
  reference ISA or a second verification entry point.

## What is proved

The library proves actual C helper/handler executions, typed memory effects,
allocation/freeing, caller frames and native register/scalar/cache views.
[Public type and axiom queries](results/m5-x86-producer-sub-all-flags-root/README.md)
expose every theorem's precise premises and retain prior interfaces.

The complete NOP handler and its actual generic dispatcher case refine the
checked ISA on arbitrary heaps. Scoped logical-register calls cover widths,
aliases and real RSP release/store/free paths within their stated domains.
AArch64 source/caller/native fixture prefixes are also integrated.

The complete original AArch64 source return retains both memory helpers,
provider traces, caller memory and its scalar result observer. Actual pointer
and MOV effects derive helper inputs, resources and source temporaries. The
original 98-provider/fourteen-call entry witness supplies those same reached
resources and the actual source-prefix trace to this complete continuation.
Its fourteen admitted native words derive the current PC, error and unchanged
program; CMP and B.GT fetch at original PC+56/+60 feed the four-step
CMP/B.GT/BL/RET suffix. Both real successor BL/RET/continuation certificates
bind once to that original program anchor and transport to the actual reached
machine. The same provider values select the correct site, retaining its real
BL offset and decoded instructions. One shared entry-result contract retains
all original prefix observations, and the previous entry interface keeps its
exact published type. Public theorem types expose the live source heap and
code domains; the worklist orders physical native memory/helper execution and
whole-program input/output correspondence next.

The original AArch64 memset byte-store route also pairs its real private tag
update and volatile byte write with a decoded, fetched checked STRB. Actual
producer resources derive source permissions and block separation. Stack
bias 96 maps its sixteen source offsets 64..79 to native origin-32..-17. The
byte relation preserves arbitrary uninitialized contents, defined source
loads, permissions, the complete native frame and the real ordered write.
The original memcpy body now composes its complete reader call, actual local
allocation/freeing and saved-caller resume with the real bias/index/mask/action
and tag/byte stores, each once. The same reached physical machine executes
fetched LDRB W3,[X1] and then STRB W3,[X0]; original program and PC+4 derive the
second fetch, and the loaded X3 supplies the write. Source indices 80..95 map
to native origin-16..-1. Actual source loop/caller/flag frames, initialized
bytes, all other native fields and bytes, PC+8 and ordered read/write history
remain. One shared checked STRB proof covers registers 0..30 and retains the
previous W1 interface. These per-byte statements expose their physical input,
register and two-word code premises. The original true guard and unsigned
increment/backedge now surround that same body, extending the actual copied
prefix to i+1 with its packet and caller frames.

The recorded sole-kernel memcpy object and vmlinux agree byte for byte at all
four inspected symbols. Its real generic 16-byte path uses two LDP and two STP
instructions, including the repeated tail accesses. Kernel-checked decoder
certificates bind its first fourteen words. The two actual source/destination
end additions execute on arbitrary physical addresses and count, retaining
the complete frame; their input PC is generic origin+4 after BTI. For count16,
all eight actual prefix steps compose under one Code certificate and derive
the first LDP fetch at origin+36. The original 16-byte readable range supplies
each real LDP's checked read states and exact events: either two ordered
8-byte reads or one 16-byte read, with actual initialization Booleans and
arbitrary underlying bytes. Both LDPs compose on the same reached state and
profile, repeating the source interval and retaining the complete frame.
The continuation consumes the original prefix witness and its reached-state
equality; final PC=origin+44 derives the first STP fetch. Imported bit-level
memory semantics identify both loaded register pairs with the original two
source words in either pair mode, including wrapping addresses. The same
loaded-state witness then feeds both real STPs from one original 16-byte
writable range. The first write derives the second initialized profile,
rights, address, code and error state. Both genuine write-event lists repeat
the same original source words; all registers and environment fields remain,
and final PC=origin+52 derives the actual RET fetch. Concrete imported output
memory states remain attached to these same execution witnesses. Both actual
STP modes now have identical physical memory and initialized profiles, with
exact 16-byte readback and outside-byte frames under wrapping addresses.
One original C caller/copy execution reaches its actual afterCopy statement;
its resources derive native write rights, and every final mapped native byte
has the same Mint8unsigned observation as that same source heap. The captured
RET then consumes the original LR and retains all copied bytes, initialized
profile, registers and environment. Public queries record the mature imported
MemoryProofs computation dependencies; kprog's local range proofs use kernel
arithmetic. The same source witness now continues through all tag transfers,
the actual clobber/provider trace, eight local frees and saved caller return.
One original physical Code, post-BTI PC and count16 derive all thirteen
actual native prefix/load/store/RET steps, preserving those same source and
native witnesses. Final byte observations, initialized profile, original LR
and caller frames remain. The native field frame retains every field outside
the real scratch/NZCV destinations, final flags are the actual CMP16 flags,
and outside physical bytes match the original input. The final source R0/tag4
agrees with returned X0 through the existing provenance map. The same complete
source call now binds its eighteen selected GPR words/tag0, four NZCV bits and
sixty-four vector halves to that actual native RET state. All eighty-six
provider outcomes use genuine kind6 external calls and supplied-heap cache
frames; these targeted environment premises remain explicit. The original
release stage, all 104 targeted stores, eight frees and caller return preserve
those exact maps. The existing single-step APIs retain their complete types.
The same returned call now derives the actual post-free entry pointer-table
readers for all 32 vectors, R1 through R18 with tag0, the complete NZCV tuple,
source R0=-16/tag4 and borrowed SP=-32. Its original stack-origin and physical
SP=-32+stackOrigin contracts bind both R0 and SP through the existing
provenance map. All reads use the exported C layout and real retained loads.
The same original program memcpy caller now retains its full initial
source/native binding through the actual eight-local entry, all sixteen
reader/tag/byte-store iterations, original tag transfers and release scans,
the same providers/stores, helper return, eight frees and saved caller
restoration. Real frames preserve R19–R30 values, tags and provenance;
the actual final packet derives the complete existing 31-GPR/SP/SIMD/NZCV
relation from that original caller binding. Fifteen complete original API
types retain kernel compatibility. One shared copy continuation consumes the
same actual source and native store witnesses. Actual generic Code, post-BTI
PC, count16, error and physical input derive all thirteen native steps;
source-derived read/write permissions and byte observations then yield both
the complete final register relation and all sixteen final source/native
destination-byte observations on that single execution. The actual exported
alias branch now decodes and executes mature B, reaching
the distinct generic symbol while preserving LR and the complete physical
frame and fetching generic BTI on the same program. The mature Hints body now
executes the four BTI landing encodings in its feature-absent plain projection.
Actual alias BTI, branch to the distinct generic symbol and generic BTI derive
their successive fetches and error states on that same Code. Those three
steps preserve the full input relation and feed the same thirteen native
prefix/load/store/RET steps and original C call. Both final sixteen-byte
observations and the complete register relation follow from these shared
witnesses. The captured Cortex-A57/QEMU invocation supplies configuration and
source evidence; live feature-register and patched-text bindings continue
alongside the actual generic-branch Code contract. Initial full binding,
targeted provider/cache inputs and the initialized count16 domain stay
explicit. The real emitter already writes LINK(next_addr) before a relocated
memcpy/memset BL's LIBC call. The next caller proof follows that actual LINK
source and native PC+4, then global provider/code evidence and the original
whole-program observer. [The platform receipt](results/m5-memcpy-bti-platform/README.md)
records the architectural source and projection; [the next route](results/m5-memcpy-kernel-bti-root/next-route.md)
names the actual C link and pointer-writer bodies.
The actual source-unit link also exposes the original LINK entry and renamed
ten-argument writer through their real symbol lookups. Its ABI theorem checks
the complete parameter types, signed bias, volatile-byte pointer, returns and
three writer locals. The complete LINK call will use this linked program.
Its actual two-argument LINK entry now executes both complete 31-row
pointer-table initializations: 373 true entry/body transitions retain both
typed pointer tables, every actual temporary update and the original caller
frame and access map. Original header reads and allocated ownership derive
each current read and store permission. The previous complete first-row API
delegates to that same generic row proof. Actual LR setup and seven header
reads now enter the genuinely linked ten-argument writer in 400 source
transitions from that original entry, with the real saved caller and casts.
The same execution now enters that writer's actual three-local allocator,
initializes both of its 31-pointer tables and writes its real stack descriptor:
590 source transitions preserve all four tables and the caller's raw frame.
The actual ordinary reg30 branch now reads the coordinate, writes the raw
address and tag9, and frees all three writer locals. Its saved caller then
breaks the original loop, frees both LINK locals and returns the same address:
638 actual source transitions, derived from original read/write resources.
Eight archived generated LINK/helper sites now bind local tokens, ELF
coordinates and fetched native BL return labels to that same complete LINK.
The canonical CODE9 numeric comparison holds exactly at zero function origin;
other placements retain an explicit fetched-code observation. These sites
call BPF helpers. The same original C execution and actual alias16/native
path now derive all31 GPR/SP/32-vector/NZCV observations with fetched code
labels, retaining trace, copied bytes, real free-lists and caller frames.
An original R30/CODE9 reader also derives the actual RET continuation fetch.
Old numeric APIs delegate once and retain their complete types. Actual loaded
text and the generated caller's initial resource/code binding still follow.
Original allocation rules out identifying the Addressing LINK's continuous
arrays with the producer's pointer-table locals in the same heap. At offset8,
the entry header contains the tag-table root; interpreting it as Addressing's
register root preserves the real register cells rather than writing X30.
A source-preserving inline LINK binding or a separate representation
transformation must connect these two interfaces before composition.
The five retained archives inspected here contain49 successful requests and
no generated/native memcpy callsite; this is a bounded inventory.

The original producer's first PUSH executes initialization, dispatch, real
stores/freeing and entry into the next source label. Its same final heap
represents GPRs, six flag bytes, XMM0 and initialized cache bytes of the exact
canonical PUSH step on its explicit successful-access domain. The proof binds
the actual kind-1 stack origin, original byte-fold memory effects, real cache
assignment observation and concrete byte53 decoding/one-byte fall-through.
Input native memory remains arbitrary. Migration continues with native
ELF/code-storage binding, general source/guest trace simulation,
platform/input-oracle correspondence, remaining operand/fault domains and
the 149 universal handler/dispatcher-step goals.

For the next original SUB RSP,32, the same source prefix includes actual
allocation, both operand helpers/saves, arithmetic/result save, unconditional
old-CF header/byte read, intermediate temporary, cast/save, real flag-arm
selection, width/mask/sign helper calls and returns, operand masking and the
all six actual flag stores. The saved number equals canonical
PUSH/SUB RSP under the initial register relation and native PUSH access domain.
Current scalar/header observations and per-object permissions derive actual
allocation/store/free frames; normalized temporary maps equal the original.
Concrete 48 83 ec 20 decoding is separate. All six flag pointer reads,
expressions, casts and byte stores derive from the same source execution and
current allocation rights. Their bytes equal external SUB CF/ZF/SF/OF/PF/AF
on the physical operands. Allocation proves separation, protecting each
preceding write; caller memory, other objects, permissions and allocation
frontier are preserved. RSP writeback/release/free/return and complete SUB
refinement remain unfinished.

## What is trusted

Lean's kernel checks terms against the pinned definitions, with standard
logical axioms. Imported Clight execution uses the existing
`CC.externalFunctionsSem` and `CC.inlineAssemblySem` assumptions; public
`#print axioms` output records their occurrence. The argument also trusts the
C front end/exporter, imported semantics, production-artifact binding and
platform memory assumptions.

Initial register/scalar/cache relations, operand/tag/provenance domains,
ownership, permissions and provider availability/frame guarantees remain
explicit premises. Growing-SP release requires stronger cache preservation
than the basic provider frame. External-call determinacy and trace-length
laws do not establish these memory ABIs. Protected typed loads across
providers do not imply raw byte equality. PUSH's private Clight cache write
is silent; its proved logical guest-write observation is a separate view,
not equality of the two external traces.

Hardware/oracle comparisons check sampled instruction values, registers,
flags, memory effects and faults. They complement universal statements within
their premises. Full specialization, linking/LTO and verifier correctness
also remain work in progress.

## Run

From this checkout, with the recorded toolchain and submodules:

```sh
make -C kprog/formal check
```

This builds the proof library and executable reference and runs semantic
oracles, including division faults and permissions. Focused commands and
validation output are retained in receipts. Benchmark settings stay frozen.
