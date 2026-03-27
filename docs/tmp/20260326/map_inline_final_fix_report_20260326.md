# map_inline final fix report (2026-03-26)

## Summary

I read:

- `docs/tmp/20260326/map_inline_still_zero_investigation_20260326.md`
- `docs/tmp/20260326/map_inline_zero_hit_root_cause_20260326.md`

The core problem was real: `map_inline`'s constant-key matcher was still too narrow for real clang output. The pass was effectively assuming a very tight `r2 = fp; r2 += off` setup and a direct constant materialization path, so real programs with copy chains or constant registers feeding the stack store were rejected before the live map read.

After the fix, `map_inline` now works on a real VM-loaded Katran program:

- real object: `corpus/build/katran/xdp_pktcntr.bpf.o`
- direct VM `apply` result: `passes_applied=["map_inline","const_prop","dce"]`
- direct VM `map_inline` diagnostics:
  - `site at PC=7: inlined successfully, value=0x1`
  - `site at PC=15: map_type=6, skip reason: unsupported map type`

That proves the pass is no longer stuck at zero on real programs because of the old matcher.

## Code changes

Main code change:

- `daemon/src/passes/map_inline.rs`

What changed:

1. Added per-site diagnostics for every lookup site.
   - unsupported map type
   - key extraction failure with concrete reason
   - value-read failure with concrete reason
   - successful inline with the inlined value

2. Reworked constant-key extraction to resolve real instruction patterns.
   - bounded backward scan within the containing subprog
   - `r2` stack-pointer recovery now handles:
     - direct `r2 = r10; r2 += off`
     - copy chains such as `r6 = r10; r6 += off; r2 = r6`
     - add/sub through a constant-valued register
   - constant register recovery now handles:
     - `mov imm`
     - `mov reg`
     - `ldimm64`
     - constant ALU chains with constant K/X inputs

3. Relaxed key width handling.
   - old logic required exact width equality
   - new logic only rejects keys narrower than the map key size
   - this matches real clang output where a 4-byte key is often written via an 8-byte stack store

4. Kept lookup-pattern deletion conservative.
   - when the generalized matcher cannot prove the lookup setup is a tight removable block, the pass now keeps the original setup and only rewrites the value loads

5. Fixed success-path diagnostics.
   - single-load sites now print the actual scalar that was inlined
   - example: `value=0x1` instead of the misleading raw-byte preview `0x01000000`

Unit coverage added/updated in `daemon/src/passes/map_inline.rs`:

- `extract_constant_key_from_r2_copy_chain`
- `extract_constant_key_from_r2_add_reg_constant`
- `extract_constant_key_from_ldimm64_stack_store`
- diagnostics assertions updated to match the new per-site logging

## VM diagnosis

### 1. Katran `balancer.bpf.o`

I first ran a filtered VM static-verify on Katran `balancer.bpf.o`.

Result:

- `map_inline.sites_applied = 0`
- `map_inline.sites_skipped = 64`

The new diagnostics showed that the remaining misses there were mostly legitimate:

- many sites were unsupported map types (`map_type=6/12/13`)
- several "key extraction failed" sites were not true constant keys after inspection
- some sites had non-load uses or non-fixed-load consumers

This run was still useful because it confirmed the pass was no longer failing silently.

### 2. Katran `xdp_pktcntr.bpf.o`

I then switched to a smaller real Katran object that has one inlineable `ARRAY` lookup and one non-inlineable `PERCPU_ARRAY` lookup.

Artifacts:

- direct VM probe output:
  - `docs/tmp/20260326/probe_outputs/map_inline_xdp_pktcntr.apply.stderr`
  - `docs/tmp/20260326/probe_outputs/map_inline_xdp_pktcntr.apply.stdout`
  - `docs/tmp/20260326/probe_outputs/map_inline_xdp_pktcntr.map_lookup.txt`
- filtered VM static-verify output:
  - `docs/tmp/20260326/probe_outputs/static_verify_xdp_pktcntr_20260326.json`
  - `docs/tmp/20260326/probe_outputs/static_verify_xdp_pktcntr_20260326.daemon.log`

I explicitly set `ctl_array[0] = 1` before running `bpfrejit-daemon apply`.

Direct VM `apply` result:

- `passes_applied=["map_inline","const_prop","dce"]`
- `map_inline.changed=true`
- `map_inline.sites_applied=1`
- `map_inline.sites_skipped=1`
- `map_inline.skip_reasons={"map type 6 not inlineable in v1":1}`

Per-site diagnostics from that real VM run:

- `site at PC=7: inlined successfully, value=0x1`
- `site at PC=15: map_type=6, skip reason: unsupported map type`

This is the concrete proof that the matcher fix now handles a real program pattern end-to-end in the VM.

## Verification

Host tests:

- `cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml map_inline`
  - passed: `33` tests
- `cargo test --manifest-path /home/yunwei37/workspace/bpf-benchmark/daemon/Cargo.toml`
  - passed: `454` tests
  - failed: `0`

VM verification:

1. Filtered real-program static verify:
   - command:
     - `make vm-static-test TARGET=x86 STATIC_VERIFY_ARGS='--mode all --filter xdp_pktcntr.bpf.o --max-objects 1'`
   - result:
     - `programs_applied=1`
     - target `katran:xdp_pktcntr.bpf.o:pktcntr`
     - `passes_applied=["map_inline","const_prop","dce"]`

2. Broader micro static verify:
   - command:
     - `make vm-static-test TARGET=x86 STATIC_VERIFY_ARGS='--mode micro'`
   - saved artifact:
     - `docs/tmp/20260326/probe_outputs/static_verify_micro_20260326.json`
   - result:
     - `objects=62`
     - `programs=62`
     - `programs_applied=55`
     - programs with `map_inline` in `passes_applied`: `0`

Interpretation:

- the fix is verified on a real VM-loaded program and is no longer zero-hit there
- the `--mode micro` manifest slice still has zero `map_inline` hits
- that does **not** invalidate the fix, because the positive Katran target is a macro-corpus object and the micro slice is a different population

## Final assessment

Fixed:

- `map_inline` no longer rejects all real programs because of the old narrow constant-key matcher
- per-site diagnostics now make skip causes explicit
- a real Katran object in the VM now gets a successful `map_inline` rewrite

Still true after this patch:

- many real corpus lookups remain intentionally skipped because they are:
  - unsupported map types
  - genuinely non-constant keys
  - non-fixed-load or pointer-escaping consumers

So the main bug reported here is fixed, but broader corpus hit-rate still depends on future work beyond constant-key recovery alone.
