## Per-program breakdown

Input: `/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260512_185218_803256/details/apps/cilium__agent.json`.

Current `map_inline` totals from `rejit_result.per_program`: `sites_applied=1452`, `sites_matched=1865`, `sites_skipped=413`, with 50 programs carrying a `map_inline` summary. There are 53 programs in `per_program`; three do not reach `map_inline` because `noop` fails first.

Doc baseline in `/home/yunwei37/workspace/bpf-benchmark/docs/evaluation-05-07-2026.md` section 6.1.1 is `cilium 1 454 / 1 824`. The exact matching run is `/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260507_195045_528717/details/apps/cilium__agent.json`: `sites_applied=1454`, `sites_matched=1824`, `sites_skipped=370`, with 51 programs carrying a `map_inline` summary.

| prog_id | prog_name | status | map_inline status | applied | matched | skipped | top skip reason |
|---:|---|---|---|---:|---:|---:|---|
| 10 | `dump_bpf_map` | ok | ok | 0 | 0 | 0 |  |
| 11 | `dump_bpf_prog` | error | not attempted | 0 | 0 | 0 | `noop` failed_rejit: EACCES |
| 106 | `cil_xdp_entry` | ok | ok | 1 | 6 | 5 | 4 x lookup key unavailable |
| 107 | `tail_nodeport_n` | ok | ok | 10 | 18 | 8 | 3 x kernel-mutable map_id=33 |
| 108 | `tail_handle_sna` | ok | ok | 50 | 72 | 22 | 8 x kernel-mutable map_id=9 |
| 109 | `tail_handle_ipv` | ok | ok | 4 | 8 | 4 | 2 x kernel-mutable map_id=9 |
| 111 | `tail_handle_ipv` | ok | ok | 76 | 96 | 20 | 10 x lookup key unavailable |
| 112 | `tail_nodeport_n` | ok | ok | 56 | 68 | 12 | 5 x kernel-mutable map_id=9 |
| 113 | `cil_host_policy` | ok | ok | 0 | 0 | 0 |  |
| 114 | `tail_drop_notif` | ok | ok | 4 | 4 | 0 |  |
| 116 | `cil_from_host` | ok | ok | 41 | 48 | 7 | 6 x kernel-mutable map_id=9 |
| 117 | `cil_to_host` | ok | ok | 5 | 6 | 1 | 1 x kernel-mutable map_id=9 |
| 118 | `tail_handle_ipv` | ok | ok | 4 | 8 | 4 | 2 x kernel-mutable map_id=9 |
| 121 | `tail_nodeport_n` | ok | ok | 10 | 18 | 8 | 3 x kernel-mutable map_id=33 |
| 122 | `tail_handle_sna` | ok | ok | 50 | 72 | 22 | 8 x kernel-mutable map_id=9 |
| 125 | `cil_to_host` | ok | ok | 5 | 6 | 1 | 1 x kernel-mutable map_id=9 |
| 126 | `tail_handle_ipv` | ok | ok | 76 | 96 | 20 | 10 x lookup key unavailable |
| 127 | `tail_drop_notif` | ok | ok | 4 | 4 | 0 |  |
| 128 | `tail_no_service` | ok | ok | 1 | 2 | 1 | 1 x kernel-mutable map_id=9 |
| 129 | `tail_nodeport_n` | ok | ok | 56 | 68 | 12 | 5 x kernel-mutable map_id=9 |
| 130 | `tail_handle_ipv` | ok | ok | 4 | 8 | 4 | 2 x kernel-mutable map_id=9 |
| 131 | `cil_from_netdev` | ok | ok | 26 | 34 | 8 | 7 x kernel-mutable map_id=9 |
| 132 | `tail_handle_ipv` | ok | ok | 76 | 96 | 20 | 10 x lookup key unavailable |
| 134 | `tail_drop_notif` | ok | ok | 4 | 4 | 0 |  |
| 135 | `tail_nodeport_n` | ok | ok | 56 | 68 | 12 | 5 x kernel-mutable map_id=9 |
| 137 | `tail_handle_sna` | ok | ok | 50 | 72 | 22 | 8 x kernel-mutable map_id=9 |
| 139 | `tail_nodeport_n` | ok | ok | 10 | 18 | 8 | 3 x kernel-mutable map_id=33 |
| 140 | `tail_no_service` | ok | ok | 1 | 2 | 1 | 1 x kernel-mutable map_id=9 |
| 141 | `cil_to_netdev` | ok | ok | 48 | 55 | 7 | 4 x kernel-mutable map_id=9 |
| 142 | `tail_drop_notif` | error | not attempted | 0 | 0 | 0 | `noop` failed_rejit: EBUSY |
| 143 | `tail_handle_arp` | ok | ok | 2 | 3 | 1 | 1 x kernel-mutable map_id=9 |
| 144 | `tail_nodeport_r` | ok | ok | 26 | 31 | 5 | 3 x kernel-mutable map_id=9 |
| 145 | `cil_lxc_policy_` | ok | ok | 0 | 0 | 0 |  |
| 146 | `tail_ipv4_ct_in` | ok | ok | 56 | 64 | 8 | 7 x kernel-mutable map_id=9 |
| 147 | `cil_lxc_policy` | ok | ok | 92 | 115 | 23 | 10 x kernel-mutable map_id=9 |
| 148 | `tail_handle_ipv` | ok | ok | 43 | 57 | 14 | 9 x lookup key unavailable |
| 149 | `tail_ipv4_ct_eg` | ok | ok | 52 | 60 | 8 | 7 x kernel-mutable map_id=9 |
| 150 | `tail_no_service` | ok | ok | 0 | 1 | 1 | 1 x kernel-mutable map_id=9 |
| 151 | `cil_from_contai` | ok | ok | 9 | 10 | 1 | 1 x kernel-mutable map_id=9 |
| 152 | `tail_handle_ipv` | ok | ok | 47 | 62 | 15 | 5 x lookup key unavailable |
| 153 | `tail_ipv4_to_en` | ok | ok | 35 | 51 | 16 | 5 x lookup key unavailable |
| 155 | `cil_lxc_policy_` | ok | ok | 0 | 0 | 0 |  |
| 156 | `tail_handle_ipv` | ok | ok | 47 | 62 | 15 | 5 x lookup key unavailable |
| 157 | `tail_ipv4_ct_in` | ok | ok | 56 | 64 | 8 | 7 x kernel-mutable map_id=9 |
| 158 | `tail_drop_notif` | error | not attempted | 0 | 0 | 0 | `noop` failed_rejit: EBUSY |
| 159 | `tail_ipv4_ct_eg` | ok | ok | 52 | 60 | 8 | 7 x kernel-mutable map_id=9 |
| 160 | `cil_from_contai` | ok | ok | 9 | 10 | 1 | 1 x kernel-mutable map_id=9 |
| 161 | `tail_ipv4_to_en` | ok | ok | 35 | 51 | 16 | 5 x lookup key unavailable |
| 162 | `tail_handle_ipv` | ok | ok | 43 | 57 | 14 | 9 x lookup key unavailable |
| 163 | `tail_handle_arp` | ok | ok | 2 | 3 | 1 | 1 x kernel-mutable map_id=9 |
| 164 | `tail_nodeport_r` | ok | ok | 26 | 31 | 5 | 3 x kernel-mutable map_id=9 |
| 166 | `cil_lxc_policy` | ok | ok | 92 | 115 | 23 | 10 x kernel-mutable map_id=9 |
| 167 | `tail_no_service` | ok | ok | 0 | 1 | 1 | 1 x kernel-mutable map_id=9 |

Aggregate diff by program name, current minus doc-baseline run:

| prog_name | applied | matched | skipped | explanation |
|---|---:|---:|---:|---|
| `tail_drop_notif` | -6 | -6 | 0 | two 88-insn instances fail `noop` before `map_inline` in current |
| `tail_handle_ipv` | +4 | +14 | +10 | baseline had one 227-insn instance fail `noop`; current reaches `map_inline` for all 10 instances |
| `tail_handle_sna` | 0 | +12 | +12 | more sites classified/skipped, no applied change |
| `tail_nodeport_n` | 0 | +21 | +21 | more sites classified/skipped, no applied change |

The net `1454 -> 1452` is therefore `-6 + 4 = -2`. If the `noop` `EBUSY` failures were ignored in both runs, both runs would have an inferred `1458` applied sites: baseline would regain one 4-site `tail_handle_ipv`, current would regain two 3-site `tail_drop_notif`.

## Skip reasons (top distribution)

Current `map_inline` skip reasons:

| count | reason |
|---:|---|
| 164 | map kernel-mutable: bytecode contains writer helper on `map_id=9` |
| 107 | lookup key is not available from verifier-guided state |
| 38 | map type 11 not inlineable |
| 32 | map kernel-mutable: writer helper on `map_id=36` |
| 30 | map kernel-mutable: writer helper on `map_id=33` |
| 16 | map kernel-mutable: writer helper on `map_id=35` |
| 12 | map kernel-mutable: writer helper on `map_id=18` |
| 5 | map kernel-mutable: writer helper on `map_id=29` |
| 4 | map kernel-mutable: LRU lookup mutates access order on `map_id=35` |
| 3 | map kernel-mutable: writer helper on `map_id=49` |
| 1 | map kernel-mutable: writer helper on `map_id=71` |
| 1 | map kernel-mutable: writer helper on `map_id=73` |

Baseline skip reasons were `map type 5 not inlineable` x162, `lookup key unavailable` x158, `map type 11` x37, `map type 10` x12, and `runtime_key_lookup_result_has_no_scalar_loads` x1. The current diagnostics are more explicit about kernel-mutability; this changes the text/distribution but does not identify the missing applied sites.

## Sites that should have applied (2 missing)

There are no two current `map_inline` diagnostics that say "this site should have applied but was skipped". The two-count regression is arithmetic, not site-local.

The missing current coverage is two whole `tail_drop_notif` programs that abort before `map_inline`:

| current prog_id | prog_name | insns | failure |
|---:|---|---:|---|
| 142 | `tail_drop_notif` | 88 | `noop` `failed_rejit`: `BPF_PROG_REJIT errno 16: Device or resource busy` |
| 158 | `tail_drop_notif` | 88 | `noop` `failed_rejit`: `BPF_PROG_REJIT errno 16: Device or resource busy` |

The doc-baseline run had the corresponding 88-insn `tail_drop_notif` programs reach `map_inline`:

| baseline prog_id | applied diagnostics |
|---:|---|
| 161 | PC 5 map_id 335 off 69 value 0x0; PC 26 off 56 value 0x80; PC 31 off 86 value 0x540 |
| 178 | PC 5 map_id 337 off 69 value 0x0; PC 26 off 56 value 0x80; PC 31 off 86 value 0x304 |

Those are six baseline-only applied sites. They are offset by four current-only `tail_handle_ipv` applied sites because the baseline run had `tail_handle_ipv` prog 129 fail `noop` before `map_inline`, while current reaches `map_inline` for the three 227-insn `tail_handle_ipv` instances. The current-only 4-site pattern is PC 6 off 4 value 0xe, PC 15 off 60 value 0x80, PC 29 off 4 value 0xe, PC 53 off 4 value 0xe.

## Code-change correlation

Recent `map_inline.rs` commits:

| commit | relevance |
|---|---|
| `a8c5b966` | transactional BBProgram mutation refactor; only 8 touched lines in `map_inline.rs`, no counter/snapshot logic found |
| `9a61ab1a` | removed `MakeReplacement`; includes `classify_r0_uses_with_options` bool collapse, but the removed two bool args were both `info.has_removable_lookup_pattern()`, so this is behavior-preserving for the observed path |
| `0dec9e22` | `MapInfoResult` flattened to private `type MapInfoBySite = HashMap<InsnSite, MapInfo>`; lookup now keys directly by `map_load_site` |
| `b42632e0` | cleanup/refactor including `lookup_value_size`; no evidence of changed map-inline eligibility |
| `496c82a0` | wrapper/side-input cleanup and kernel-mutable diagnostics plumbing; correlates with changed skip reason text, not with the two missing attempted programs |

Current code points checked:

| file location | observation |
|---|---|
| `crates/bpfopt/src/passes/map_inline.rs:502` | `collect_kernel_mutable_maps` classifies writer-helper and LRU maps; explains current kernel-mutable skip distribution |
| `crates/bpfopt/src/passes/map_inline.rs:854` | `lookup_site_map_info` directly uses `MapInfoBySite` by `site.map_load_site`; current diagnostics do not show `map reference metadata unavailable` |
| `crates/bpfopt/src/passes/map_inline.rs:2327` | `record_skip` directly pushes skip diagnostics; log wrapper removal is reporting-only |
| `crates/bpfopt/src/passes/map_inline.rs:2349` | `format_bytes_preview` uses shared `hex_bytes`; formatting-only |
| `crates/bpfopt/src/passes/map_inline.rs:2366` | `classify_r0_uses_with_options` has one helper-call bool; no evidence it caused the missing count |
| `crates/bpfopt/src/passes/map_inline.rs:3460` | `MapInfoBySite` is private; no behavior signal in result diagnostics |

The decisive evidence is outside `map_inline` eligibility: the current missing programs have no `map_inline` `bpfopt_summary` at all, because `noop` ReJIT fails first with `EBUSY`.

## Root cause hypothesis(代码 bug | 快照变异 | 其他)+ 置信度

Hypothesis: **其他: ReJIT/lifecycle `EBUSY` coverage variation before `map_inline`**, confidence **0.85**.

This is not a `map_inline` code bug based on the available evidence. The two current `tail_drop_notif` misses occur before `map_inline` is invoked. It is also not a pure map-snapshot-value change: the program pass coverage changed due to `noop` `BPF_PROG_REJIT errno 16`.

Why Cilium and not OTEL: Cilium has many tc tail programs and duplicate datapath/notification program instances, and the observed failures are Cilium `tail_drop_notif` lifecycle/ReJIT failures. OTEL's `map_inline` applied count is stable at 1192 across the inspected x86 KVM runs, even when its matched/skipped count changes between `1264/72` and `1593/401`; it does not show the same `tail_drop_notif`/`noop EBUSY` coverage shift.

## Recommended next step

For this result, treat `1452` as a pass-coverage artifact, not a `map_inline` site regression. Re-run cilium/agent and compare only runs where the same early-pass failures occur, or compute apply totals from programs that actually reached `map_inline`. If the goal is a stable doc number, record the `noop` `EBUSY` pre-pass failures alongside the applied/matched totals instead of interpreting `1452 vs 1454` as two missed `map_inline` applications.
