# bpfopt Lifecycle-Aligned Facts Design

Date: 2026-05-14

## Problem

`map_inline`, `const_prop`, and other verifier-facing passes need facts about the
same BPF instruction stream:

- verifier-proven scalar exact values, pointer kinds, stack bytes, packet ranges;
- local bytecode-derived register/stack state such as `r10 + off`;
- use-def and liveness facts;
- branch/profile annotations;
- BTF/PC metadata used during lowering and reporting.

Today these facts live in several shapes:

- top-level `ProgramCFG` caches such as liveness and lifted register facts;
- raw `BTreeMap<InsnSite, ...>` maps for verifier states and metadata;
- pass-private scans in `map_inline`, `cond_select`, `wide_mem`, `bulk_memory`,
  `rotate`, and others.

That split makes it too easy for one pass to consume a stale or differently
interpreted fact. `map_inline` and `const_prop` should not each have their own
understanding of "constant", stack bytes, or verifier state. Analysis results
should live with the IR object that owns their lifecycle.

## Core Decision

Use one lifecycle-aligned facts structure, attached at the program, block,
instruction, and terminator positions where the facts are valid.

Do not create separate long-lived sidecar data structures for each domain
(`BlockVerifierProof`, `BlockAnalysis`, `BlockLiveness`, etc.). The domains can
be fields in one facts bundle, but ownership and invalidation should follow the
IR node.

The bpfopt IR remains BPF bytecode:

```text
BpfInsn       = instruction IR
BasicBlock   = lifecycle/index owner for a sequence of BpfInsn
ProgramCFG   = CFG view, mutation API, compute entry points
Facts        = one bundle of analysis/proof/profile/metadata facts
```

## Shape

First implementation should avoid wrapping every `BpfInsn` immediately. Keep
`Vec<BpfInsn>` and add parallel facts vectors owned by `BasicBlock`:

```rust
struct ProgramCFG {
    blocks: Vec<BasicBlock>,
    version: u64,

    // Only truly global derived indexes or epochs stay here.
    // The per-site facts themselves live on blocks/instructions.
}

struct BasicBlock {
    id: BlockId,
    version: u64,
    frame: FrameId,
    predecessors: Vec<BlockId>,

    insns: Vec<BpfInsn>,
    terminator: Terminator,

    block_facts: Facts,
    insn_facts: Vec<Facts>,      // same length and order as `insns`
    terminator_facts: Facts,
}

struct Facts {
    version: u64,

    // Verifier-like state. For an instruction this means before/after states.
    // For a block this means entry/exit-edge states.
    verifier: ...,

    // Local bytecode-derived state, e.g. fp offsets, packet ctx loads, packet
    // data/end provenance. This replaces ad hoc duplicate state shapes.
    local: ...,

    // Dataflow results. Computed at CFG/program scope, stored at the site.
    uses: RegSet,
    defs: RegSet,
    live_in: Option<RegSet>,
    live_out: Option<RegSet>,
    reaching_defs_in: ...,
    reaching_defs_out: ...,

    // Metadata and profile attached to this lifecycle point.
    branch_profile: Option<BranchProfile>,
    btf_pc: Option<usize>,
    ldimm64_second: Option<BpfInsn>,
}
```

The ellipses are intentional. The design requirement is not a large type tree.
It is one facts bundle with verifier/local/dataflow/profile/metadata fields.
The exact internal representation can be added only when an implementation needs
it.

Later, if the mechanical churn is acceptable, `BpfInsn` plus its `Facts` can be
wrapped:

```rust
struct InsnNode {
    insn: BpfInsn,
    facts: Facts,
}
```

That is an internal cleanup, not a prerequisite for the design.

## Lifecycle Rule

Facts live exactly where their owner lives:

- instruction facts live in `insn_facts[idx]`;
- terminator facts live in `terminator_facts`;
- block entry/exit facts live in `block_facts`;
- only program-wide derived indexes or epochs live in `ProgramCFG`.

Mutation must update facts atomically with the IR:

```text
delete insn       -> delete its facts
insert insn       -> insert empty facts
replace insn(s)   -> replace facts with empty facts unless explicitly preserved
split block       -> split insns and split/move corresponding facts
merge blocks      -> merge insns and merge/move corresponding facts
replace terminator -> clear terminator facts and affected edge facts
remove block      -> remove block and all its facts
```

This is the main reason to bind facts to `BasicBlock`: `BasicBlock` is already
the owner of instruction indices and mutation lifecycle.

## Mutation Boundary

The current code is close to the right shape:

- passes generally cannot directly mutate `BasicBlock.insns` because it is
  `pub(super)`;
- most rewrites already go through `ProgramCFG` APIs in `bbprogram_api.rs`;
- lift construction directly pushes instructions, which is construction rather
  than rewrite;
- `bbprogram_api.rs` still directly mutates `insns` and `terminator` internally.

The required cleanup is to make the `ProgramCFG` / `BasicBlock` mutation APIs
the only place that changes both IR and facts. Passes should never update facts
manually.

## Verifier Log Boundary

Verifier log remains only an input format:

```text
daemon ReJIT log_level=2
  -> verifier_log.rs parses raw lines
  -> ProgramCFG attaches normalized verifier fields into Facts
  -> passes query Facts through ProgramCFG APIs
```

Passes must not import or inspect raw verifier-log records such as
`VerifierInsn`, `VerifierInsnKind`, `RegState`, or `StackState`.

The verifier importer is responsible for:

- PC to block/insn/terminator mapping;
- before/after/edge classification;
- delta/full-state normalization;
- retaining all visits and frames;
- converting textual verifier states into the verifier fields inside `Facts`.

## Unified Queries

Passes should query facts through one API. The API can sit on `ProgramCFG`, but
the data comes from the lifecycle-owned `Facts`.

Examples:

```rust
prog.verifier_exact_scalar_after(site, reg)
prog.verifier_reg_kind_after(site, reg)
prog.verifier_stack_bytes_before(site, BPF_REG_2, width)
prog.local_reg_before(site, reg)
prog.live_out(site)
prog.reaching_defs(site, reg)
```

The query layer owns meet/consistency rules:

- no states means no fact;
- missing register means no verifier fact;
- disagreeing visits mean no exact fact;
- disagreeing frames mean no single-frame fact;
- edge-only evidence cannot be treated as site-wide evidence;
- verifier and local facts can be compared, but verifier-required queries must
  not silently fall back to local facts.

This allows cross-checking:

```text
local says r2 == fp-132
verifier says r2 == fp-132 and stack bytes are exact
  -> map_inline may use verifier stack bytes and report local agreement

local says r2 == fp-132
verifier has no r2 state or says r2 is scalar
  -> verifier-required query returns None; mismatch is visible
```

## What Goes Into Facts

All persistent analysis results should be stored where their lifecycle belongs:

- verifier state: instruction before/after, terminator before/after, block
  entry/exit;
- local register/stack state: instruction before/after;
- use/def sets: instruction and terminator facts;
- liveness: instruction and terminator facts;
- reaching defs: instruction and terminator facts;
- branch profile: branch terminator facts;
- BTF/PC metadata: instruction or terminator facts;
- LD_IMM64 second slot metadata: instruction facts.

The computation may still be program-level. For example, liveness and reaching
defs require CFG fixed-point propagation. The result should still be written
back to each instruction/terminator facts slot.

Top-level `ProgramCFG` may keep derived indexes when needed for efficient
queries, for example `DefSite -> Vec<UseSite>`. Those indexes are caches over
facts, not the primary lifetime owner.

## What Stays Pass-Local

Ephemeral matcher state can stay inside passes:

- candidate lists;
- temporary scan windows;
- `map_inline` rewrite plans;
- `cond_select` diamond candidates;
- `wide_mem` ladder windows;
- `bulk_memory` run candidates.

If a pass-local result becomes a reusable fact or affects correctness across
passes, it should move into `Facts` rather than becoming another sidecar map.

## Pass Responsibilities

`const_prop` should use verifier queries only:

```rust
prog.verifier_reg_kind_after(site, dst_reg)
prog.verifier_exact_scalar_after(site, dst_reg)
```

`map_inline` should use verifier stack-byte queries for key proof:

```rust
prog.verifier_stack_bytes_before(call_site, BPF_REG_2, key_size)
```

`map_inline` may use local facts and structural scans to find setup/delete sites,
but it must not treat local facts as verifier proof of key bytes.

Other passes should consume shared facts instead of adding new pass-private
dataflow where the result is not purely local to the matcher.

## Preservation

Default preservation is conservative:

```text
changed instruction body -> new/empty facts for changed instructions
changed block body       -> block entry/exit facts cleared unless preserved
changed terminator       -> terminator facts and affected edge facts cleared
changed CFG edge         -> dependent liveness/reaching-def facts stale
```

Runtime semantic equivalence does not automatically preserve verifier facts.
Any preservation must be explicit in the mutation API, not inferred by a pass
after the fact.

The first implementation can simply clear affected facts and mark fixed-point
analyses stale. More precise preservation can be added later if needed.

## Migration Plan

Phase 1: lifecycle storage without broad semantic changes.

1. Add `Facts` fields to `BasicBlock`: one block facts slot, one facts slot per
   instruction, and one terminator facts slot.
2. Update lift construction to initialize empty facts alongside instructions.
3. Update mutation APIs to insert/delete/clear facts together with instructions
   and terminators.
4. Move current verifier-state query payloads into facts.
5. Keep existing liveness/use-def computation, but write results to facts rather
   than only top-level maps.
6. Update `const_prop` and `map_inline` to use unified query APIs.

Phase 2: remove duplicate fact shapes.

1. Replace `LiftedRegFact` and verifier reg/stack query shapes with one
   verifier/local state vocabulary inside `Facts`.
2. Keep source strength explicit: verifier facts and local bytecode facts are
   comparable but not interchangeable.
3. Add consistency checks where local and verifier facts cover the same register
   or stack location.

Phase 3: tighten preservation.

1. Start with conservative invalidation.
2. Add explicit preservation only for edits whose fact transfer is proven.
3. Consider `InsnNode { insn, facts }` only after the parallel-vector approach is
   stable.

## Expected Code Impact

The design should avoid adding another large analysis layer.

Expected phase-1 movement:

- add one reusable `Facts` bundle;
- move current verifier queries and helpers into unified query code;
- move liveness/use-def results from maps into facts slots;
- keep pass-local candidate matching inside passes;
- avoid defining separate long-lived proof, liveness, local-state, and profile
  sidecar structures.

The first implementation may grow code modestly because mutation APIs must keep
facts synchronized with IR. The intended long-term reduction is fewer scattered
`BTreeMap<InsnSite, ...>` structures and fewer pass-private interpretations of
the same register/stack facts.

## Open Questions

- Exact before/after/edge mapping from kernel verifier logs still needs to be
  validated against real logs.
- `BranchDeltaState` should be normalized deliberately rather than dropped or
  treated as site-wide proof.
- How much of the current `UseDefGraph` should remain as a derived index after
  per-site facts own uses/defs/reaching-def facts?
- Whether block permutation can carry facts safely depends on current `BlockId`
  remapping guarantees.
