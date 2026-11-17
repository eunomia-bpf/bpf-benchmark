# Actual consumer boundary and local lifetime

`Arm64ProducerLifetime.lean` binds the exported continuation call, its typed
`&entry` argument, saved producer frame and uint32 return statement. One
sequence step reaches Scall; two steps reach Callstate with explicit callee
lookup and signature premises. Header construction composes to 640 internal
transitions, with both borrowed caches on the same entry argument, preserved
continuation binding and the actual Freeable local ranges.

Once a continuation returns a uint32 value, its real Kcall/Sskip/Sreturn path
takes three internal transitions and frees the producer frame. The ownership
premise covers only the actual declared local ranges. It allows changed data,
other blocks and additional allocations. No successful free is assumed:
`deallocate_live_locals` constructs one from those ranges and actual allocation
freshness/distinctness. The original `deallocate_locals` interface is retained
as a corollary, sharing the proof rather than duplicating it.

Every enumerated local range loses both Cur and Max permissions. Later frees
cannot restore denied permission. Contents and nextblock remain unchanged;
all prior caller bytes and permission maps are preserved relative to memory
at the return boundary. Old bytes do not constitute a live borrowed entry.

The callee body is neither chosen nor executed here. Its real binding and
resource preservation remain obligations. The next query proves that the
exported raw borrowed handler has a different C signature: (entry, reg) to
ulong versus the producer continuation's (entry) to uint. Entry and Program
environments cannot be silently composed. Source/provider ABI, native origins,
memory/control, full handler migration and O1/O2/O4 recount remain M5. Complete
ISA-handler count is zero; remaining M6 follows M5.

Focused generic Lake passes 33 jobs and the lifetime source check passes.
Full Lake passes 286 jobs with zero failures; thirteen public type/axiom queries
and the actual ABI inspection pass. All 23 exports remain byte-identical to
9c617740f, 243488732 bytes. Shape uses propext, revocation also Quot.sound, and
general resources use at most the three standard axioms. Internal runs also
mention the imported external and assembly relations. Builds/queries use timing SH,
CPU 17, one worker and 32 GiB address space, with default 200000 heartbeats and
512 recursion depth. No external, callback or assembly body executes; no new
semantic/native-reflection axiom or proof-budget increase is introduced.

Reproduce from kprog/formal with those bounds and the shared timing lock:

```
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerLifetime
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-lifetime/Query.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-lifetime/Next.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build
```

Raw attempts: /workspaces/kprog-raw/formal/m5-producer-lifetime. Production C,
pinned semantics, exports and frozen benchmark paths are unchanged. Last full
native make check remains PASS at 5236c0e96 and was not repeated for Lean-only
proof additions.
