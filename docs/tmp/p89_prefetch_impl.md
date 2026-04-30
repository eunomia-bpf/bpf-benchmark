# P89 Prefetch Implementation

## Scope

Implemented the experimental `prefetch` kinsn pass for helper-before-lookup sites.
Phase 1 inserts a memory hint before `map_lookup_elem` when a hot PMU profile site
is present. Phase 2 map-inline direct-load prefetching is left as follow-up work.

The pass is registered for explicit use but is not part of
`DEFAULT_OPTIMIZE_PASS_ORDER`.

## Kernel kinsn modules

- Added `module/x86/bpf_prefetch.c`.
  - Encodes `PREFETCHT0 [ptr]`.
  - The kinsn is a pure hint and uses a no-op proof program, so verifier-visible
    state is unchanged.
  - Registers `bpf_prefetch` through the module BTF/kfunc registration path.
- Added `module/arm64/bpf_prefetch.c`.
  - Encodes `PRFM PLDL1KEEP, [ptr]`.
  - Uses the same pure-hint verifier proof contract.
  - Registers `bpf_prefetch` through module BTF/kfunc registration.
- Added Makefile entries for both architectures.

## Rust pass

- Added `bpfopt/crates/bpfopt/src/passes/prefetch.rs`.
- The pass looks for `map_lookup_elem(map, key)` helper calls and prefetches the
  key pointer register (`r2`) before the helper.
- The pass requires a site PMU profile. Missing profile data means the site is
  not emitted; no heuristic fallback is used.
- Site-level validity checks reject only invalid candidate sites:
  - no cross-subprogram insertion window;
  - insertion at real instruction boundaries, including `LD_IMM64` handling;
  - same basic-block insertion window;
  - explicit key pointer write before the helper;
  - no helper/control-flow/pseudo-function call in the prefetch window;
  - no `r2` rewrite between the insertion point and helper call.
- Added prefetch profile data plumbing to annotations and pass context.
- Added CLI/pass registry wiring so `bpfopt list-passes` includes `prefetch`,
  while the default optimize pipeline remains unchanged.

## Runtime integration

- Added `prefetch_sites` profile JSON parsing.
- Added `bpf_prefetch` kinsn discovery/required-kinsn mapping.
- Added runner result aggregation support for `prefetch_sites`.
- Updated daemon side-input generation so pass-specific side inputs are only
  captured for passes that need them. This keeps a prefetch-only run from
  failing on unrelated verifier-state or map-value side inputs.

## Verification

- `cargo fmt` for the touched Rust crates.
- `cargo test -p bpfopt prefetch`
- `cargo test -p bpfopt --test cli_pipeline`
- `cargo test -p bpfopt`, repeated 5 rounds.
- `cargo test -p bpfget --test cli`
- `cargo test` in `daemon`
- `cargo run -q -p bpfopt -- list-passes`
  - Output included `prefetch`.
  - `prefetch` was not in the default 11-pass optimize order.
- `BPFREJIT_BENCH_PASSES=prefetch make vm-corpus SAMPLES=1`
  - Result directory:
    `corpus/results/x86_kvm_corpus_20260430_204123_124983`
  - Status: `ok`
  - Apps: 22/22 ok
  - Loaded kinsn modules included `bpf_prefetch`
  - Requested programs: 519
  - Prefetch-applied programs: 0
  - Not-applied programs: 519
  - Verifier/ReJIT failures: 0
  - Acceptance rate for requested programs: 519/519 (100%)
  - Acceptance rate for mutated programs: not applicable because no PMU
    `prefetch_sites` profile was provided, so the runtime profile gate emitted
    no kinsn calls.
  - Corpus performance summary for the run:
    - `program_count`: 132
    - `wins`: 54
    - `losses`: 78
    - `per_program_geomean`: 0.9787464124683913

## Notes

- The direct host `make -C module/x86` check was blocked by the local
  `vendor/linux-framework` tree not having generated kernel build files.
  The VM/container module build used by `make vm-corpus` did build and load the
  new `bpf_prefetch` module successfully.
- `vendor/linux-framework` remained at `a1b8bade`.
