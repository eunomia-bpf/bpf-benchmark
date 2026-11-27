# Actual caller vector input sites and allocated layout

The module extracts all 64 consecutive vector call/store sites from the
actual Flags.vectorStart. Kernel checks match each whole statement against
the mature vectorInitializerFor schema, including actual callee, types,
anonymous vector tag, lo/hi target, index, input temporary and successor.
The exact original final continuation is retained.

The actual caller global environment supplies anonymous tag __5189 with
16-byte records, lo/hi offsets zero/eight, and a 512-byte array of 32 vectors.
Storage derives its actual block binding, freshness and writable range from
the SAME original 795-local allocation. No old producer VectorLocal resource
or correspondence between old and actual allocations is assumed.

call_ready instantiates the existing generic three-step call prefix with
the actual caller function/environment/global callee at every original
source position. It assumes neither a successful provider return nor a
successful vector reader or store.

This is a source/layout/allocation and per-visit call-prefix result.
Actual vector writebacks, their local/caller frames, all-64 sequential
execution and whole function-entry composition remain subsequent work.
Native execution, loaded text, global/universal refinement and recount
remain open. Actual Cilium LINKs remain BPF-helper calls, separate from memcpy.
Query.lean checks nine public declarations and actual axioms; validation.json
records exact source hash, original caps, timing policy and full checks.
The promoted module retains the successful direct snapshot bytes.
