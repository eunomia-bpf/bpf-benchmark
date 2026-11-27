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
arithmetic. Next comes the same source witness's tag transfer, clobbers,
free/caller return and native caller/landing-pad/alternative feature binding,
then the complete helper/environment and whole-program observer.

The original producer's first PUSH executes initialization, dispatch, real
stores/freeing and entry into the next source label. Its same final heap
represents GPRs, six flag bytes, XMM0 and initialized cache bytes of the exact
canonical PUSH step on its explicit successful-access domain. The proof binds
the actual kind-1 stack origin, original byte-fold memory effects, real cache
assignment observation and concrete byte53 decoding/one-byte fall-through.
Input native memory remains arbitrary. Native ELF/code-storage binding,
general source/guest trace simulation, platform/input-oracle correspondence,
remaining operand/fault domains and all149 universal handler/dispatcher-step
goals remain unfinished.

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
