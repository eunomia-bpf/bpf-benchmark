# RAW setup to the native register relation

`Arm64EntryAdmissibility.raw_registers_initialized` composes the real
90-transition stack-tag/SP/context setup with the 638-transition header and
vector-pointer loop. Its 728-transition witness establishes the existing
register relation in one reached memory, with caller contents, both permission
maps, access and nextblock preserved.

The actual RAW context stores supply x0's context value and ABI tag 1, and
change x30's tag to RETURN 10. The preceding SP assignment supplies offset 0.
Those final loads are derived, rather than premises of this theorem. The x30
payload remains the source's zero word, so existing provenance materialization
recovers the explicit invocation return origin. Other GPR inputs retain scalar
words and tags; vector and flag data survive setup. The cell map is the actual
source register index: all 31 exported declaration indices and the context
store/table-cell identities are kernel checked.

The theorem starts after vector inputs. Earlier table contents, scalar words,
ordinary tags, flag/vector data and the source x30 zero word are still precise
allocation-bound premises. Native context bits, other initial GPR bits, return
origin and stack origin are same-invocation bindings to discharge. Source
indexing alone does not certify hardware ABI bindings or aliasing. There is no
claim of complete native input admissibility, memory/events/fault/control
correspondence or a bound program continuation. M5/M6 and O1/O2/O4 recount
remain open; complete ISA-handler refinement count is 0.

The source routes are distinct:

- `c/Arm64Entry.c` includes `c/Arm64Entry.h`, then the production
  `arm64_sim_local_bpf.h` and canonical `kinsn/module/include/native_lab_input.h`.
  The host/Clight branch declares `native_lab_entry_input(unsigned int kind)`;
  the linked export retains that one-argument external at block 64. Clight
  export does not include the host fixture definition.
- `oracles/arm64_entry_environment_host.h` deliberately returns zero for kinds
  1/3/6 in host fixtures. These are selected test outcomes, not native values.
- The canonical `__bpf__` branch emits a private input instruction. The stock
  compiler wrapper instead force-includes `stock_native_input.h`, whose shared
  include guard replaces the macros with volatile `kprog_unspecified_input[0]`
  reads. `native_loader.cpp` creates an ARRAY map named `kprog_unspec` and binds
  that symbol in `load_trusted_worker`. This verifier input route supplies no
  proof here that a read equals each hardware register or origin.

Focused Lake passes 167 jobs and full Lake passes 294 jobs. The public theorem
query and two source/ABI inspections pass. The axiom list contains only ordinary
propext/Classical.choice/Quot.sound and the previously imported external/assembly
semantics through InternalRun; no external or assembly call executes in this
728-transition segment. All 23 exports (243488732 bytes) remain byte-identical
to 9c617740f. An initial query attempted decidability of expression equality;
it now uses definitional equality for those source ASTs. Two build invocations
ran from the repository root and failed before checking a module; corrected
formal-directory builds pass. All attempts and errors remain in raw data.

From kprog/formal, under timing SH, CPU17 or18, `ulimit -v 33554432`,
LEAN_NUM_THREADS=1 and default 200000 heartbeats/512 recursion depth:

```
lake build KProgFormal.ClightRefinement.Arm64EntryAdmissibility
lake env lean -j1 results/m5-entry-admissibility/Query.lean
lake env lean -j1 results/m5-entry-admissibility/Next.lean
lake build
python3 results/clight-build/compare.py 9c617740f
```

Raw: /workspaces/kprog-raw/formal/m5-entry-admissibility. C, exports and frozen
benchmark paths are unchanged. Last complete native make check passed at
5236c0e9677f635526fdd515cde5195b2ba0810c; it was not repeated for this Lean-only
step. Actual M5/M6 completion still requires fresh full Lake and make check.
