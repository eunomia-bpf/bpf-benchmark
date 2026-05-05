# Opaque bpfopt Passthrough, 2026-05-05

Per-file LoC delta: `bpfopt/src/main.rs +17/-2`, `pass.rs +1/-0`, `map_inline.rs +2/-0`, `map_inline_tests.rs +3/-0`, `cli_pipeline.rs +1/-0`, `corpus/driver.py +1/-9`, `daemon/src/commands.rs +67/-155`, `daemon/src/server.rs +0/-1`, `runner/libs/rejit.py +12/-263`, `docs/tmp/opaque-passthrough-20260505.md +18/-0`.
Totals: 122 added, 430 deleted, net -308 including this report; code-only net is -326.

bpfopt summary schema examples: noop `{"pass":"noop","sites_applied":0,"sites_matched":0,"sites_skipped":0,"skip_reasons":{},"diagnostics":[],"insn_count_before":N,"insn_count_after":N,"insn_delta":0}`; map_inline adds `map_inline_records:[{"map_id":7,"key_hex":"01000000","value_hex":"2a000000"}]`; cond_select uses the same common keys and pass-owned diagnostics/skips.
Implementation: bpfopt owns the report fields in `bpfopt/crates/bpfopt/src/main.rs:155` and map_inline emits value hex at `bpfopt/crates/bpfopt/src/main.rs:1178`.

Daemon per-pass response shape: `{"pass":name,"status":"ok|skipped_missing_states|failed_bpfopt|failed_rejit","error":string|null,"bpfopt_summary":opaque_json}` from `daemon/src/commands.rs:185`.
Daemon only peeks into `bpfopt_summary.map_inline_records` for `map_id/key_hex/value_hex` to preserve `inlined_map_entries`; see `daemon/src/commands.rs:300`.
Runner result.json per-pass shape is the daemon pass object copied unchanged; `runner/libs/rejit.py:225` now stores the daemon program record as a dict and only adds the app-level `error` alias.

Confirmations: `changed` is gone from the bpfopt report, daemon pass detail, and runner Python protocol path; `rg` only finds unrelated corpus wording at `corpus/driver.py:312`.
Noop hint preserved exactly at `daemon/src/commands.rs:553`: "pass {pass} requires verifier states from a previous per-pass ReJIT — insert a \`noop\` pass before {pass} in the pass chain to bootstrap them (e.g. BPFREJIT_BENCH_PASSES=\"noop,{pass},...\")".
KVM validator removed: the old `daemon response field 'changed' must be a boolean` path is gone; replacement copy path starts at `runner/libs/rejit.py:225`.

Validation: bpfopt cargo tests 406 passed; daemon cargo tests 26 passed; Python `tests/python/` 17 passed plus 1 subtest.
Commit hash: reported after commit creation; a commit cannot contain its own final Git object ID.
