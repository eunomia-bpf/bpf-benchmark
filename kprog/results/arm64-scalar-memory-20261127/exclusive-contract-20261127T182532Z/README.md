# ARM exclusive retry lowering boundary

{
  "requests": 70,
  "sites": 216,
  "widths": {
    "64": 171,
    "32": 45
  },
  "operation_orders": {
    "('ldxr', 'add', 'stxr')": 7,
    "('ldaxr', 'add', 'stlxr')": 163,
    "('ldaxr', 'orr', 'stlxr')": 44,
    "('ldaxr', 'and', 'stlxr')": 2
  },
  "operands": {
    "immediate": 132,
    "register": 84
  },
  "alias_counts": {
    "base_overwritten": 0,
    "status_aliases_value": 0,
    "status_aliases_base": 0,
    "operand_overwritten": 0
  },
  "sites_with_external_direct_entries": 0,
  "requests_with_indirect_control": 70
}

Preserve explicit EXCLUSIVE_FAILURE per dynamic store visit, with both0/1 outcomes. Failed store must skip source/memory observation and write zero-extended Wstatus1; success performs the ordinary memory-write semantics and Wstatus0.

Every failed visit still executes its exclusive load and arithmetic; keep load faults, SP alignment, pointer tags, width and external read effects. No fairness, fixed retry count or constant-success substitution is licensed.

A native atomic fetch intrinsic is not a drop-in proof: reconcile memory-order labels, external interference/reservation model, per-visit choices, fault paths, local value/status live-outs and traces. The existing local simulator does not itself establish an atomic linearization relation.

Any stock-B loop/callback form needs its safety-preservation relation to arbitrary native failure prefixes and successful continuation. A finite bpf_loop/iterator bound alone does not cover an unbounded native retry.

Native direct-branch closure is checked here; indirect entry targets and specialization dispatch closure remain unproved. Structural operand stability is not sufficient for selecting a production rewrite.

The70 archived C sources match their captured hashes. The original145-stock acceptance and active Tetragon guest are unchanged. contract.json retains all216 sites and every native indirect control instruction for follow-up; direct entry checks cover parsed immediate branch targets only. No proposed lowering is established by these counts.
