# Cilium Prefetch Coverage Loss, 2026-05-12

## 1. Verify

Source rows:

- `docs/evaluation.md:313`: doc baseline says `cilium/agent` `prefetch` = `430 / 430`.
- `corpus/results/x86_kvm_corpus_20260512_185702_727232/details/apps/cilium__agent.json`: current prefetch-only run.
- `corpus/results/x86_kvm_corpus_20260512_190655_194595/details/apps/cilium__agent.json`: current kop-6 run.

Summing `rejit_result.per_program[].passes[].bpfopt_summary` where `pass == "prefetch"`:

| run | enabled passes | prefetch applied | prefetch matched | prefetch summaries |
|---|---:|---:|---:|---:|
| doc baseline | `prefetch` | 430 | 430 | n/a |
| current prefetch-only | `prefetch` | 411 | 416 | 53 |
| current kop-6 | `rotate,cond_select,extract,endian_fusion,bulk_memory,prefetch` | 50 | 50 | 16 |

The current isolated run is therefore `411 / 416`, not the documented `430 / 430`. The five missing applies inside the current isolated run are represented as prefetch `skip_reasons`. The extra matched delta versus the doc baseline (`430 -> 416`) is candidate census drift, not a matched-but-skipped apply.

## 2. Skip-Reason Breakdown

Prefetch-only `skip_reasons`, total `5`:

| reason | count | programs |
|---|---:|---|
| `r1 is redefined inside the prefetch window at InsnSite { block: BlockId(217), idx: 2 }` | 2 | `cil_lxc_policy`, `prog_type=3`, `orig_insn_count=2446` |
| `r2 is redefined inside the prefetch window at InsnSite { block: BlockId(1), idx: 1 }` | 2 | `cil_lxc_policy`, `prog_type=3`, `orig_insn_count=2446` |
| `r1 is redefined inside the prefetch window at InsnSite { block: BlockId(2), idx: 1 }` | 1 | `cil_xdp_entry`, `prog_type=6`, `orig_insn_count=276` |

KOperation-6 prefetch itself has no skip reasons (`50 / 50`). The only non-trivial non-prefetch skip bucket in kop-6 is:

| pass | reason | count |
|---|---|---:|
| `cond_select` | `no dead register available to materialize immediate operand` | 2 |

## 3. Why KOperation-6 Drops To 50

Program IDs are not stable between runs, so the comparison below keys by `(prog_name, prog_type, orig_insn_count)`.

Weighted by the isolated prefetch count for each kop-6 program:

| kop-6 outcome before/at prefetch | records | isolated applied | isolated matched | kop-6 matched | matched lost |
|---|---:|---:|---:|---:|---:|
| stopped at `cond_select failed_bpfopt` | 31 | 347 | 352 | 0 | 352 |
| prefetch reached, nonzero sites | 12 | 50 | 50 | 50 | 0 |
| stopped at `rotate failed_rejit` | 3 | 11 | 11 | 0 | 11 |
| stopped at `endian_fusion failed_rejit` | 2 | 2 | 2 | 0 | 2 |
| stopped at `extract failed_rejit` | 1 | 1 | 1 | 0 | 1 |

Largest identity-matched losses:

| program identity | records | isolated prefetch | kop-6 prefetch | kop-6 outcome |
|---|---:|---:|---:|---|
| `tail_handle_sna`, type `3`, `2617` insns | 3 | `54 / 54` | `0 / 0` | all stop at `cond_select failed_bpfopt` |
| `cil_lxc_policy`, type `3`, `2446` insns | 2 | `42 / 46` | `0 / 0` | all stop at `cond_select failed_bpfopt` |
| `tail_handle_ipv`, type `3`, `1720` insns | 3 | `36 / 36` | `0 / 0` | all stop at `cond_select failed_bpfopt` |
| `tail_nodeport_n`, type `3`, `1837` insns | 3 | `36 / 36` | `0 / 0` | all stop at `cond_select failed_bpfopt` |
| `tail_handle_ipv`, type `3`, `1377` insns | 2 | `30 / 30` | `0 / 0` | all stop at `cond_select failed_bpfopt` |
| `tail_ipv4_to_en`, type `3`, `1343` insns | 2 | `26 / 26` | `0 / 0` | all stop at `cond_select failed_bpfopt` |

Conclusion: the destructive earlier pass in this corpus is `cond_select`, but not because its applied bytecode rewrites hide prefetch candidates. Where prefetch actually runs, identity-matched coverage is preserved (`50 / 50` isolated subset -> `50 / 50` kop-6). The coverage collapse is mainly `cond_select` exiting 1 before later passes run.

## 4. Prefetch Pattern-Detector Audit

Map-value path:

- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:138`: candidate anchor must be a helper call with `src_reg == 0` and `imm == BPF_FUNC_map_lookup_elem`.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:151`: the map lookup return value starts as an alias in `r0`.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:153`: scan only instructions after the helper within `MAP_VALUE_LOOKAHEAD = 64` slots.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:166`: scan stops at calls, exits, pseudo-func `ldimm64`, or nonzero-offset `JA`.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:155`: first memory access whose base register aliases the map value becomes the target.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:197`: alias propagation only preserves `MOV X` and immediate `ADD/SUB` on an already aliased register.

Packet path:

- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:101`: packet scanning only runs for program types with `packet_ctx_layout(..., PacketAccess)`.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:214`: `r1` starts as the context register.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:275`: `LDX_MEM W [ctx + data_off]` produces `PacketData`; `data_end_off` produces `PacketEnd`.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:221`: memory access through a register tracked as `PacketData` becomes a packet prefetch target.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:243`: helper calls kill tracked packet pointer state; `xdp_adjust_head` kills all registers.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:287`: packet pointer propagation only preserves `MOV X` and immediate `ADD/SUB`.

Insertion window:

- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:318`: insertion window is limited to `MAX_PREFETCH_DISTANCE = 16` slots before the target.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:375`: pointer definition and target must be in the same frame.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:382`: window starts after the pointer definition and inside the target block.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:442`: any call, exit, jump, or pseudo-func in the window rejects the candidate.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:459`: any write to the pointer register in the window rejects the candidate.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:407`: insertion site is chosen nearest to `TARGET_PREFETCH_DISTANCE = 8` slots before the target.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:477`: candidates with the same insertion site and pointer register are deduplicated.

Optional profile filtering:

- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:113`: missing prefetch profile does not block emission.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:116`: profile with zero cache misses skips the site.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:128`: profile with zero execution count skips the site.

## 5. Host Reproduce

Chosen dropped identity: `tail_handle_sna`, `prog_type=3`, `orig_insn_count=2617`. In the result comparison it drops from `54 / 54` isolated across three instances to `0 / 0` in kop-6 because all three stop at `cond_select failed_bpfopt`.

Command run from `bpfopt/`:

```sh
cargo run --locked -q -p bpfopt -- \
  --pass prefetch \
  --input testbin/cilium_agent/175_tail_handle_snat_fwd_ipv4/input_step0.bin \
  --output /dev/null \
  --report /dev/stdout \
  --prog-type sched_cls \
  --koperation bpf_prefetch
```

Result:

```json
{
  "pass": "prefetch",
  "sites_applied": 18,
  "sites_matched": 18,
  "sites_skipped": 0,
  "skip_reasons": {},
  "insn_count_before": 2617,
  "insn_count_after": 2653,
  "insn_delta": 36
}
```

This confirms the preserved bytecode has the expected isolated per-instance prefetch sites.

Also checked `cil_lxc_policy` skip reproduction:

```sh
cargo run --locked -q -p bpfopt -- \
  --pass prefetch \
  --input testbin/cilium_agent/202_cil_lxc_policy/input_step0.bin \
  --output /dev/null \
  --report /dev/stdout \
  --prog-type sched_cls \
  --koperation bpf_prefetch
```

Result: `21 / 23`, with the two skip reasons `r1 is redefined ... BlockId(217)` and `r2 is redefined ... BlockId(1)`, matching the corpus bucket for each `cil_lxc_policy` instance.

## 6. Root Cause

Current isolated `411 / 416` missing applies:

- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:325`: `choose_prefetch_insert_site` rejects a site when `reject_reg_write_between` returns a reason.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:459`: `reject_reg_write_between` detects a definition of the pointer register inside the insertion window.
- `bpfopt/crates/bpfopt/src/passes/prefetch.rs:460`: emitted reason is `r{reg} is redefined inside the prefetch window at ...`.

KOperation-6 `50 / 50` collapse:

- The prefetch detector is not the main cause; prefetch has no skip reasons in kop-6.
- The main corpus failure text is `error: diamond join BlockId(...) has external predecessor BlockId(...)` from `cond_select`.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:795`: `replace_diamond_with_insns` iterates join predecessors.
- `bpfopt/crates/bpfopt/src/analysis/bbprogram_api.rs:797`: it `bail!`s if a join predecessor is outside the diamond-owned predecessor/true/false set.
- `bpfopt/crates/bpfopt/src/passes/cond_select.rs:126`: current `cond_select` clones the program and checks the diamond before replacement.
- `bpfopt/crates/bpfopt/src/passes/cond_select.rs:128`: current `cond_select` converts that external-join shape into a site skip before calling replacement.
- `bpfopt/crates/bpfopt/src/passes/cond_select.rs:153`: current `cond_select` repeats the external-join check before mutating the real program.
- `bpfopt/crates/bpfopt/src/passes/cond_select.rs:257`: the external-join reason is formatted as `diamond join ... has external predecessor ...`.

The result artifact was produced by a `bpfopt` path where the external-join condition escaped as process exit 1, so the daemon stopped the per-program pass sequence before `prefetch`.

## 7. Proposed Fix

Fix `cond_select` structurally, not in the daemon and not in `prefetch`: teach the diamond replacement path to handle shared joins by splitting/duplicating the join continuation so only the diamond-owned incoming edges are consumed by the branchless-select replacement, while external predecessors keep their original control-flow target. That turns non-isolated Cilium diamonds into either valid `cond_select` rewrites or ordinary site-level non-applications, without pass-chain fallback and without making `prefetch` compensate for earlier pass failures.

Verdict: the Cilium kop-6 prefetch collapse is a `cond_select` external-join abort that prevents `prefetch` from running on most affected programs, not a prefetch detector regression.
