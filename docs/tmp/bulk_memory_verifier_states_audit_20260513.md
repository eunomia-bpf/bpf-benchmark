**Verdict**
Yes, `bulk_memory` has a yaml wiring bug: it declares `log_level: 1`, so the predecessor is only asked to emit a minimal verifier log even though the pass registry marks `bulk_memory` as verifier-state-consuming. The planner explicitly sets each step's outgoing log level from the successor config (`runner/libs/rejit_plan.py:108-126`). However, the observed katran record reports `sites_matched: 0`, not skipped candidates, so this artifact shows no bulk-memory candidate after prior transforms, not candidate rejection due to missing states (`corpus/results/x86_kvm_corpus_20260513_072625_341335/details/apps/katran.json:1405-1424`).

**Yaml log_level values**
- `map_inline`: `log_level: 2` in default yaml; katran override also `2` (`runner/config/passes/map_inline/default.yaml:4`, `runner/config/passes/map_inline/katran.yaml:40`).
- `const_prop`: `log_level: 2` (`runner/config/passes/const_prop/default.yaml:4`).
- `bulk_memory`: `log_level: 1`; command still passes `--verifier-states ${VERIFIER_STATES}` (`runner/config/passes/bulk_memory/default.yaml:4,12-13`).
- Registry consumers are `map_inline`, `const_prop`, and `bulk_memory` (`bpfopt/crates/bpfopt/src/passes/mod.rs:73-82`). Only `bulk_memory` declares `1`.

**bulk_memory empty/missing state behavior**
Missing `--verifier-states` is a hard CLI error for registry consumers (`bpfopt/crates/bpfopt/src/main.rs:143-145`). A missing file also errors on read (`main.rs:278-282`). But an empty or log_level=1 file is accepted: the verifier parser ignores non-state lines and returns an empty vector (`verifier_log.rs:110-128`), and `PassContext` explicitly treats empty state sets as legitimate (`pass.rs:642-647`). Since `has_verifier_states()` is then false, lifting proceeds without verifier states (`bbprogram_lift.rs:139-143`).

**bulk_memory pass behavior**
The pass ignores `_ctx`, scans the lifted CFG, and returns `PassResult::with_sites(0, skipped)` when no sites are found (`bulk_memory.rs:81-92`, `96-142`). It can apply without verifier states: tests build a context without states and expect one memcpy/memset rewrite (`bulk_memory_tests.rs:7-16,115-129`). States are mainly opportunity/safety proof for different-base memcpy alias classification through `reg_kind`; absent states make unknown bases conservative (`bulk_memory.rs:144-158`). Current katran evidence says no candidates: `sites_applied/matched/skipped = 0/0/0`.

**Historical evidence**
Searched `corpus/results/x86_kvm_corpus_2026051*/details/apps/katran.json` for non-zero `bulk_memory` applications. No non-zero rows were found. All bulk-memory records present in that glob were `applied=0, matched=0, skipped=0`; an earlier example is `x86_kvm_corpus_20260512_193039_342440` (`katran.json:176-198`).

**Recommended fix dimensions**
Set `runner/config/passes/bulk_memory/default.yaml` to `log_level: 2`. Add pass-side or CLI validation so registry consumers fail when parsed verifier states are empty unless explicitly optional. Add daemon/runner validation that a step using `--verifier-states` is preceded by outgoing `log_level >= 2`, or warn/fail when the successor is known to consume verifier states.
