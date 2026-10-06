# P89-Fix69 Verifier Reject Report

Date: 2026-04-30

Base corpus: `corpus/results/x86_kvm_corpus_20260430_193236_794969`

Current HEAD during validation: `0e849a15`

## Summary

The actionable pass bug on current HEAD was in `wide_mem`, exposed by the old
`default11` reject for prog `763` (`bpftrace/tcplife`, kprobe
`tcp_set_state`). `wide_mem` collapsed byte loads from stack offsets `-95` and
`-94` into `LDXH [r10 -95]`, which the verifier rejects as an unaligned stack
halfword load.

Fix: add a site-level natural-alignment check in `wide_mem`; misaligned wide
load sites are skipped, while other valid sites in the same program remain
eligible. No program-wide or pass-wide skip was added.

## Stage 0

`cargo test --manifest-path bpfopt/Cargo.toml -p bpfopt` passed before the fix
and after the fix. The prior `utils.rs` / `pass_tests.rs` / `branch_flip.rs`
state is test-clean on this HEAD.

## Reject Pattern Attribution

I replayed the old 69 unique `kinsn5` rejected programs from
`docs/tmp/p89h_full_verify_results.tsv` with current release `bpfopt`:

Artifact: `/tmp/p89_fix69_after_kinsn5.tsv`

| Current kinsn5 outcome | Count |
|---|---:|
| optimize rc=0 | 69 |
| no current kinsn site applied | 60 |
| `extract:1` | 5 |
| `bulk_memory:1` | 1 |
| `bulk_memory:2` | 1 |
| `endian_fusion:1` | 2 |

The 60 no-site cases are not pass-induced rejects on current HEAD; there is no
site where a kinsn pass can add a validity guard.

For the 9 current transformed programs, host raw `bpfverify` cannot replay the
guest kinsn `fd_array`/BTF IDs directly, so I verifier-checked the
verifier-visible proof bytecode for the kinsn sites.

Artifact: `/tmp/p89_fix69_proof_after.tsv`

| Pattern | Programs | Host verifier result |
|---|---:|---|
| `extract:1` | 5 | 5 pass |
| `bulk_memory` | 2 | 2 pass |
| `endian_fusion:1` | 2 | original host fixture fails before attribution |

The two `endian_fusion` cases are progs `219` and `226` (`cilium/agent`,
`cil_to_host`). The original unoptimized program fails with the same host
fixture error before the optimized endian site is material:

`R1 invalid mem access 'scalar'` after a dummy `.rodata.config` path loads
`0xdeadc0de`.

Original replay artifact: `/tmp/p89_fix69_orig_verify/{219,226}/report.json`

## Fixed Pattern

### `default11` / `wide_mem` / misaligned stack wide load

Affected old reject:

| Prog ID | App | Program | Old failing pass |
|---:|---|---|---|
| 763 | `bpftrace/tcplife` | `tcp_set_state` | `wide_mem` |

Old verifier error:

`166: (69) r1 = *(u16 *)(r10 -95)`  
`misaligned stack access off 0+0+-95 size 2`

Root cause: `wide_mem` recognized a byte-load ladder and emitted a wider
natural-width load without checking that the base offset was naturally aligned.
The original byte loads were verifier-valid; the replacement halfword load from
`r10 -95` was not.

Fix:

- Added `wide_load_alignment_skip_reason()` in
  `bpfopt/crates/bpfopt/src/passes/wide_mem.rs`.
- The check is per rewrite site: for width `2`, `4`, or `8`, skip only if
  `base_off.rem_euclid(width) != 0`.
- Added `test_wide_mem_pass_skips_misaligned_halfword_site()` in
  `bpfopt/crates/bpfopt/src/passes/wide_mem_tests.rs`.

After the fix, prog `763` default pipeline result:

| Pass | Before | After |
|---|---:|---:|
| `const_prop` | 2 sites | 2 sites |
| `wide_mem` | 8 sites | 0 sites |
| host verifier | rejected | accepted |

Artifacts:

- Before-fix verifier report: `/tmp/p89_fix69_default/763/verify_opt_report.json`
- After-fix replay: `/tmp/p89_fix69_default_after_all/763/work/bpfopt_report.json`
- After-fix verifier report: `/tmp/p89_fix69_default_verify_after/763/report.json`

## Host Verification After Fix

Old 5 `default11` rejected programs were replayed after the fix.

Artifacts:

- Optimize replay: `/tmp/p89_fix69_default_after.tsv`
- Host verifier replay: `/tmp/p89_fix69_default_verify_after.tsv`

| Prog ID | Verify input | Result |
|---:|---|---|
| 6 | proof-lowered `extract` | pass |
| 14 | proof-lowered `extract` | pass |
| 15 | proof-lowered `extract` | pass |
| 702 | proof-lowered `extract` after `const_prop,dce` | pass |
| 763 | raw optimized bytecode | pass |

Result for the old `default11` reject set: `5 -> 0` verifier rejects.

For the old `kinsn5` reject set on current HEAD:

| Bucket | Count | Result |
|---|---:|---|
| no current kinsn site | 60 | no pass transform to fix |
| proof-lowered transformed site accepted | 7 | pass |
| original host fixture reject | 2 | same failure before/after optimization |

Result for current transform-induced `kinsn5` rejects: `0`.

## Test Commands

Passed:

```bash
cargo build --manifest-path bpfopt/Cargo.toml --release -p bpfopt -p bpfverify
cargo test --manifest-path bpfopt/Cargo.toml -p bpfopt
cargo test --manifest-path bpfopt/Cargo.toml --workspace
```

`vendor/linux-framework` remained at
`a1b8bade169fae6e174ef022fa96fb1c626d96df`.
