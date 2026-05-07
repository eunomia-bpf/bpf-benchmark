# Katran force-inline map lookup recipe

Date: 2026-05-06

Scope: investigation only. No `bpfopt` or daemon code was edited, and no corpus run was started. The shell date for the requested filename was `20260506`.

Primary current artifact: `corpus/results/x86_kvm_corpus_20260507_023000_475311/details/apps/katran.json`.

Bytecode artifact used for site decoding: `corpus/results/x86_kvm_corpus_20260430_193236_794969/details/workdirs/553/prog.bin`. This retained `balancer_ingres` workdir has the same 2542 instruction count as the R1 program: `prog_info.json` says `insn_cnt: 2542` and `orig_prog_len: 20336` (`20336 / 8 = 2542`) at `corpus/results/x86_kvm_corpus_20260430_193236_794969/details/workdirs/553/prog_info.json:8` and `:28`. R1 reports `balancer_ingres` `orig_insn_count: 2542` at `corpus/results/x86_kvm_corpus_20260507_023000_475311/details/apps/katran.json:243-247`.

## 1. Existing `map_inline` pass paths

### Path 1: verifier-guided helper lookup inline

Input:

- A direct `bpf_map_lookup_elem()` helper call found by `find_map_lookup_sites()`. The matcher requires helper call `imm == 1` and a previous `r1 = pseudo_map_fd` load; see `bpfopt/crates/bpfopt/src/passes/map_inline.rs:138-157` and `:2170-2184`.
- Live map metadata and map snapshots from `--map-values` plus `--map-ids`. The pass metadata declares `map_inline` needs verifier states and map values at `bpfopt/crates/bpfopt/src/passes/mod.rs:89` and registers the pass at `:102-104`. The CLI enforces `--verifier-states`, `--map-values`, and `--map-ids` for map-value passes at `bpfopt/crates/bpfopt/src/main.rs:451-457`.
- A verifier-state snapshot at the exact call PC. `extract_site_constant_key()` calls `try_extract_constant_key_verifier_guided()` on the first fixed-point round at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1243-1287`.

Verifier-state check:

- It first filters parsed verifier states by `state.pc == call_pc`; no occurrence gives `verifier log has no state snapshot at call pc ...` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:345-355`.
- For each occurrence it requires `r2` to be an `fp` pointer with a fixed stack offset at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:445-470`.
- It then requires constant stack bytes covering the map key width at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:410-418` and decodes per-byte verifier stack state at `:472-520`.
- If multiple verifier states exist for the call PC, all derived keys must agree at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:369-385`.

Output:

- A `ConstantKey` containing key bytes, stack offset, width, and optional materialization PCs (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:48-60`, `:425-442`).
- `build_site_rewrite()` looks up the snapshot value for `(map_id, key)` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1297-1345`.
- It replaces fixed-offset scalar loads from the map value pointer with immediate moves at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1393-1405`, records an inlined entry at `:1411-1422`, and applies replacements/removals through the common rewrite engine at `:1176-1225`.

What "force this constant key at this call_pc" looks like:

```rust
fn hint_constant_key(program: &BpfProgram, call_pc: usize, info: &MapInfo) -> Result<Option<ConstantKey>, String> {
    let Some(bytes) = program.map_inline_hints.get(&call_pc) else {
        return Ok(None);
    };
    if bytes.len() != info.key_size as usize {
        return Err(format!(
            "inline hint at pc {call_pc} has {} byte(s), expected {}",
            bytes.len(),
            info.key_size
        ));
    }
    let bounds = subprog_bounds(&program.insns, call_pc);
    let r2_setup = find_r2_stack_pointer_setup_simple(&program.insns, call_pc, bounds);
    Ok(Some(ConstantKey {
        stack_off: r2_setup.map(|(_, _, off)| off).unwrap_or(0),
        width: bytes.len(),
        value: constant_key_value(bytes),
        bytes: bytes.clone(),
        store_pc: call_pc,
        source_imm_pc: None,
        materialization_pcs: Vec::new(),
        r2_mov_pc: r2_setup.map(|(mov_pc, _, _)| mov_pc),
        r2_add_pc: r2_setup.map(|(_, add_pc, _)| add_pc),
    }))
}
```

Call it at the top of `extract_site_constant_key()` before the verifier-guided branch. That bypasses only key reconstruction; it still uses the existing map snapshot lookup, fixed-load classifier, branch fixup, BTF remap, and kernel ReJIT verification path.

### Path 2: `pseudo_map_value` direct load constantization

Input:

- A load whose source pointer resolves to `BPF_PSEUDO_MAP_VALUE` or `BPF_PSEUDO_MAP_IDX_VALUE`, not a helper call. `KeyPointerOrigin::MapValue` is defined at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:122-130`.
- `resolve_key_pointer_origin()` traces register pointer arithmetic back to a pseudo-map-value `LD_IMM64` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2506-2615`.
- The path uses key bytes of all zeroes for the target map at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2047`.

Output:

- `build_direct_map_value_load_rewrites()` replaces scalar loads with constants at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1918-2021`.
- It resolves the backing map snapshot through `resolve_snapshot_map_value()` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2023-2069`.

This path is why the R1 root-cause note says the only R1 applies were direct pseudo-map-value loads, not helper lookup rewrites (`docs/tmp/map_inline_hit_rate_root_cause_20260506.md:10-14`).

### Path 3: map-in-map helper chain

Input:

- An outer direct map lookup whose result flows into an inner helper lookup as `r1`. `MapInMapChain` is defined at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:38-46`; the chain finder tracks aliases and null checks at `:160-223`.
- A constant outer key, an `outer_map_id,key -> inner_map_id` snapshot entry, inner map metadata, and a constant inner key. The side-input reader stores `inner_map_ids` when bpftool dump entries include `inner_map_id` at `bpfopt/crates/bpfopt/src/main.rs:1141-1150`. `BpfProgram` carries `map_inner_map_ids` at `bpfopt/crates/bpfopt/src/pass.rs:115-119`.
- Current map-info code classifies `ARRAY_OF_MAPS` and `HASH_OF_MAPS` as map-in-map types at `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:63-69`.

Output:

- `build_map_in_map_chain_rewrite()` resolves outer key, inner map ID, inner metadata, inner key, and inner value at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1669-1791`.
- It then replaces fixed-offset loads from the inner value and optionally removes both lookup/null-check patterns at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1793-1901`.

### Path 4: runtime-key chain

Input:

- Constant-key extraction failed, but the map is not BPF-writable. The fallback branch is gated at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:970-997`.
- The lookup must have an immediate null check, fixed scalar loads, no escaping lookup pointer, and a key pointer that survives to those loads (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1425-1448`).
- All snapshot entries for the map are collected at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1513-1542`.

Output:

- A runtime key-membership chain at the helper call PC and either constant loads if all values are equal or a per-key value chain if values differ (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1458-1511`, `:1544-1616`).

This is not the right mechanism for the katran proof-of-concept because the target maps are BPF-writable or map-in-map, and the user wants explicit per-site keys rather than a generated membership chain.

## 2. Force-inline mechanism design

| Route | Engineering cost | Risk | Paper rigor | Verdict |
|---|---:|---|---|---|
| A. `bpfopt --inline-hint <prog_id>:<call_pc>:<hex_key_bytes>` | About 90-140 LOC in `bpfopt` for CLI parsing, `BpfProgram` storage, and `extract_site_constant_key()` hook; plus about 30-60 LOC later if the daemon should pass hints automatically. | Low. It reuses all existing snapshot lookup and bytecode rewrite logic. Bad hints should be fatal, not silent skips. | Good for a deliberately labeled operator contract. It demonstrates "the missed opportunity is key extraction" without pretending the verifier proved the key. | Recommended POC route. |
| B. `map_inline_hints.json` sidecar | About 130-220 LOC in `bpfopt`, plus schema docs/tests. More ergonomic for many sites. | Low to medium. More file format surface and more chance of stale sidecar confusion. | Good if the JSON is copied into artifacts and reported. | Better after POC, not the fastest first step. |
| C. Debug path that always uses bytecode-pattern key extraction | About 40-90 LOC if re-enabling the current test-only extractor. | Medium. It is a fallback from failed verifier reconstruction and would miss packet-derived keys anyway. It also risks reviving the exact hidden-fallback behavior the fail-fast rules discourage (`CLAUDE.md:76-80`). | Weak. It does not express an operator-supplied contract and will not explain runtime-key sites. | Not recommended. |
| D. Pre-rewrite input bytecode by hand and feed ReJIT | About 150-300 LOC for a one-off patcher, more if it needs BTF/line remap. | High. It bypasses `bpfopt` reports, map snapshot contracts, and normal pass accounting. It also conflicts with the v3 rule that transforms remain `bpfopt --pass <name>` CLI invocations (`CLAUDE.md:92-100`). | Weak. It proves the kernel can verify a hand patch, not that the framework pass can recover the opportunity. | Avoid. |

Recommended route: A. Add a repeated global CLI option and store hints in `BpfProgram`. For the POC, pass:

```text
--prog-id 537 --inline-hint 537:1105:00000000 --inline-hint 537:1807:00000000
```

`bpfopt` does not currently carry a program ID in its CLI; current global args include `--input`, `--output`, `--report`, `--platform`, `--prog-type`, `--verifier-states`, `--map-values`, and `--map-ids` at `bpfopt/crates/bpfopt/src/main.rs:94-128`. Adding `--prog-id` only for hint validation keeps the hint format honest without changing the runner boundary.

## 3. Concrete katran site list

R1 facts:

- `balancer_ingress` has baseline and post-ReJIT `run_cnt_delta = 0` in the shared-root result at `corpus/results/x86_kvm_corpus_20260507_023000_475311/details/apps/katran.json:14-21` and `:69-76`. The tail-call accounting caveat explains why a tail-called program can show zero runs (`CLAUDE.md:66-68`).
- R1 `map_inline` for prog 537 matched 14 sites, applied 0, and skipped 14 at `corpus/results/x86_kvm_corpus_20260507_023000_475311/details/apps/katran.json:218-230`.
- The per-site diagnostics are at `corpus/results/x86_kvm_corpus_20260507_023000_475311/details/apps/katran.json:191-216`.
- R1 map snapshot decisions for prog 537 are at `corpus/results/x86_kvm_corpus_20260507_023000_475311/details/daemon.stderr.log:4074-4087`.

Runtime fixed keys/values supplied by the runner:

- Constants: `CH_RING_SIZE = 65537`, `VIP_NUM = 0`, `REAL_NUM = 1`, `VIP_IP = 10.100.1.1`, `VIP_PORT = 8080`, `ROUTER_LB_MAC = 02:00:00:00:00:0b` at `runner/libs/app_runners/katran.py:32-58`.
- Packing: `pack_u32`, `pack_ctl_mac`, `pack_vip_definition`, `pack_vip_meta`, and `pack_real_definition` at `runner/libs/app_runners/katran.py:255-259`.
- Prepopulation: `ctl_array[0]`, `vip_map[VIP:8080/TCP]`, `reals[1]`, and all `ch_rings[ring_pos] = 1` at `runner/libs/app_runners/katran.py:609-628`.

Map identity from the retained matching bytecode workdir:

- `vip_map`: hash, key 20, value 8, max 512 at `corpus/results/x86_kvm_corpus_20260430_193236_794969/details/workdirs/553/map_fds.json:11-19`.
- `lru_mapping`: array-of-maps, key 4, value 4, max 128 at `corpus/results/x86_kvm_corpus_20260430_193236_794969/details/workdirs/553/map_fds.json:20-28`.
- `quic_stats_map`: percpu array, key 4, value 104, max 1 at `corpus/results/x86_kvm_corpus_20260430_193236_794969/details/workdirs/553/map_fds.json:38-46`.
- `vip_to_down_rea`: hash-of-maps, key 20, value 4, max 512 at `corpus/results/x86_kvm_corpus_20260430_193236_794969/details/workdirs/553/map_fds.json:65-73`.
- `ctl_array`: array, key 4, value 8, max 16 at `corpus/results/x86_kvm_corpus_20260430_193236_794969/details/workdirs/553/map_fds.json:74-82`.
- `vip_miss_stats`: array, key 4, value 20, max 1 at `corpus/results/x86_kvm_corpus_20260430_193236_794969/details/workdirs/553/map_fds.json:101-109`.

Site verdicts:

| call PC | map | Realistic key | Snapshot value usable? | Verdict |
|---:|---|---|---|---|
| 512 | `vip_map` | Packet-derived VIP key: `0a6401010000000000000000000000001f900600` for this workload. Source builds it from packet destination, port, and proto at `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:779-787`. | Yes. R1 dumped the only hash entry shape (`map_type=1`, size 340) at `daemon.stderr.log:4075`; runner prepopulates the exact key/value at `katran.py:617-618`. | Inline-able with manual hint, but workload-specific. |
| 520 | `vip_map` | Fallback VIP key with port zero after `vip.port = 0` at `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:788-790`: `0a64010100000000000000000000000000000600`. | No. The runner does not prepopulate port-zero VIP. | Key is computed at runtime so no useful constant fold for the current snapshot. |
| 562 | `lru_mapping` | `cpu_num = bpf_get_smp_processor_id()` at `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:837-840`. | Not enough. Outer key is CPU-runtime; inner LRU lookup key is packet flow. Map definition is array-of-maps at `runner/repos/katran/katran/lib/bpf/balancer_maps.h:49-64`. | Needs map-in-map support and still no useful global constant key. |
| 762 | `vip_map` | Same packet-derived VIP key as PC 512 on the duplicate path. Source construction is `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:779-787`. | Yes for the benchmark's fixed VIP. | Inline-able with manual hint, workload-specific. |
| 770 | `vip_map` | Same port-zero fallback shape as PC 520. | No configured entry. | Key is computed at runtime so no useful constant fold. |
| 814 | `lru_mapping` | Runtime CPU key. Source is `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:837-840`. | Not enough. | Needs map-in-map support and still no useful global constant key. |
| 863 | `quic_stats_map` | Constant `quic_packets_stats_key = 0` at `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:874-876`. | Yes if per-CPU slots are byte-identical; R1 dumped this percpu array (`map_type=6`, size 16336) at `daemon.stderr.log:4078`. It is not on the non-QUIC hot path because the configured VIP flags are only `F_LRU_BYPASS` (`katran.py:33`, `:618`). | Inline-able with manual hint, low workload value. |
| 895 | `quic_stats_map` | Constant key 0 on the duplicate path. | Same as PC 863. | Inline-able with manual hint, low workload value. |
| 1072 | `vip_to_down_rea` | Outer key is the VIP struct, packet-derived but fixed for this workload; source checks down reals with `vip_to_down_reals_map` at `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:661-664`. | No useful value in this run. R1 dumped the hash-of-maps as size 3 at `daemon.stderr.log:4081`, consistent with empty. | Needs map-in-map support and populated outer entry. |
| 1105 | `ctl_array` | Constant `mac_addr_pos = 0` at `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:696`; lookup at `:1033`. Key bytes `00000000`. | Yes. Runner writes `pack_ctl_mac(ROUTER_LB_MAC)` at `katran.py:617`; value bytes are `02000000000b0000` from `pack_ctl_mac` at `katran.py:256`. R1 dumped the matching small array (`map_type=2`, size 2950) at `daemon.stderr.log:4082`. | Inline-able with manual hint. Best POC. |
| 1351 | `vip_miss_stats` | Constant key 0 in `update_vip_lru_miss_stats()`; source initializes `vip_miss_stats_key = 0` at `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:586-588`. | Probably yes as an array snapshot, but it is a stats/config side map not part of the fixed prepopulation listed in `katran.py:609-628`. | Inline-able with manual hint, low paper value. |
| 1776 | `vip_to_down_rea` | Same map-in-map down-reals path as PC 1072. | No useful value in this run. | Needs map-in-map support and populated outer entry. |
| 1807 | `ctl_array` | Constant key 0 duplicate path. Source lookup is `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:1033`. | Yes, same value as PC 1105. | Inline-able with manual hint. |
| 2062 | `vip_miss_stats` | Constant key 0 duplicate path. | Probably yes, low paper value. | Inline-able with manual hint, low paper value. |

Map-in-map structure:

- PC 562 and PC 814 are `lru_mapping` outer lookups. R1 records them as `map-in-map chain is not inlineable` at `corpus/results/x86_kvm_corpus_20260507_023000_475311/details/apps/katran.json:197` and `:202`. The map is an `ARRAY_OF_MAPS` from CPU core to LRU map at `runner/repos/katran/katran/lib/bpf/balancer_maps.h:49-64`, and the outer key is `bpf_get_smp_processor_id()` at `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:837-840`.
- PC 1072 and PC 1776 are `vip_to_down_rea` outer lookups. R1 records missing verifier-state-derived outer keys at `corpus/results/x86_kvm_corpus_20260507_023000_475311/details/apps/katran.json:207` and `:212`. The map is a `HASH_OF_MAPS` keyed by `struct vip_definition` at `runner/repos/katran/katran/lib/bpf/balancer_maps.h:230-248`.
- The current pass expects map-in-map bpftool dump entries to carry `inner_map_id`; `read_map_values()` stores those at `bpfopt/crates/bpfopt/src/main.rs:1141-1150`, and `build_map_in_map_chain_rewrite()` consumes them at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1694-1717`. The R1 map-in-map failures are therefore not a missing bytecode emitter; they are missing outer/inner key evidence or empty/unusable map snapshots.

Important negative result: the prepopulated `reals[1]` and `ch_rings[*] = 1` are real optimization opportunities, but they are not among the 14 R1 counted skip sites because those large array snapshots were skipped by size. R1 shows `ch_rings`-shaped `map_type=2` with size `3847707452` skipped at `daemon.stderr.log:4084` and `reals`-shaped `map_type=2` with size `1080250` skipped at `daemon.stderr.log:4080`. A key-only hint will not overcome `MapLookupError::SkippedBySize`; `SnapshotMapProvider::lookup_elem()` returns `SkippedBySize` before checking entries at `bpfopt/crates/bpfopt/src/pass.rs:237-247`.

## 4. Recipe for one site: `ctl_array[0]` at PC 1105

Why this site:

- The key is an actual program invariant: `mac_addr_pos = 0` at `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:696`.
- The lookup is `bpf_map_lookup_elem(&ctl_array, &mac_addr_pos)` at `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:1033`.
- The runner writes exactly `ctl_array[0] = ROUTER_LB_MAC` at `runner/libs/app_runners/katran.py:617`.
- `pack_ctl_mac()` encodes six MAC bytes plus two zero bytes at `runner/libs/app_runners/katran.py:256`.

Original bytecode, decoded from `prog.bin` PCs:

```text
1101: r2 = r10
1102: r2 += -120
1103: r1 = map_fd old_fd:12 name:ctl_array type:array key_size:4 value_size:8
1105: call bpf_map_lookup_elem#1
1106: r8 = 1
1107: *(u64 *)(r10 -160) = r0
1108: if r0 == 0 goto 1531
...
1158: r6 = *(u64 *)(r10 -160)
1159: r2 = *(u8 *)(r6 +0)
1160: r3 = *(u8 *)(r6 +1)
1161: r4 = *(u8 *)(r6 +2)
1162: r5 = *(u8 *)(r6 +3)
1163: r0 = *(u8 *)(r6 +4)
1164: r6 = *(u8 *)(r6 +5)
```

The existing pass already knows how to turn fixed loads into immediate loads through `emit_constant_load()` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2156-2168`. With hint key `00000000`, the snapshot value is:

```text
ctl_array[0] = 02 00 00 00 00 0b 00 00
```

Expected rewritten load sequence:

```text
1159: r2 = 2
1160: r3 = 0
1161: r4 = 0
1162: r5 = 0
1163: r0 = 0
1164: r6 = 11
```

If lookup-pattern removal is allowed, the pass can also remove the map-load/call/null-check pattern using the existing `skipped_pcs` path at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1353-1391` and the common rewrite application at `:1176-1225`. If branch-target safety blocks removal, the fixed loads can still be constantized and the pass reports an applied site.

Minimum implementation route: A, `--inline-hint`.

Exact source diff shape to make `bpfopt` accept the hint and feed the existing rewrite builder:

```diff
diff --git a/bpfopt/crates/bpfopt/src/pass.rs b/bpfopt/crates/bpfopt/src/pass.rs
--- a/bpfopt/crates/bpfopt/src/pass.rs
+++ b/bpfopt/crates/bpfopt/src/pass.rs
@@
     pub map_snapshots_skipped_by_size: HashSet<u32>,
+    /// Explicit map_inline key hints: call_pc -> key bytes.
+    pub map_inline_hints: HashMap<usize, Vec<u8>>,
     /// Pre-loaded map metadata: map_id -> MapMetadata.
@@
             map_snapshots_skipped_by_size: HashSet::new(),
+            map_inline_hints: HashMap::new(),
             map_metadata: HashMap::new(),
diff --git a/bpfopt/crates/bpfopt/src/main.rs b/bpfopt/crates/bpfopt/src/main.rs
--- a/bpfopt/crates/bpfopt/src/main.rs
+++ b/bpfopt/crates/bpfopt/src/main.rs
@@
     /// BPF program type, such as xdp, sched_cls, tracing, or a numeric type.
     #[arg(long, global = true, value_name = "TYPE")]
     prog_type: Option<String>,
+    /// Live program id, used to validate --inline-hint records.
+    #[arg(long, global = true, value_name = "ID")]
+    prog_id: Option<u32>,
+    /// Force map_inline to use an explicit key: <prog_id>:<call_pc>:<hex_key_bytes>.
+    #[arg(long = "inline-hint", global = true, value_name = "PROG_ID:CALL_PC:HEX")]
+    inline_hints: Vec<String>,
@@
     if let Some(path) = common.map_values.as_deref() {
         let snapshot = read_map_values(path, &program.map_ids)?;
         program.map_metadata = snapshot.metadata;
@@
         program.map_snapshots_skipped_by_size = snapshot.maps_skipped_by_size;
     }
+    program.map_inline_hints = parse_inline_hints(common.prog_id, &common.inline_hints)?;
@@
     Ok(())
 }
+
+fn parse_inline_hints(prog_id: Option<u32>, raw: &[String]) -> Result<HashMap<usize, Vec<u8>>> {
+    let mut hints = HashMap::new();
+    for item in raw {
+        let mut parts = item.split(':');
+        let hint_prog_id: u32 = parts.next().ok_or_else(|| anyhow!("missing hint prog_id"))?.parse()
+            .with_context(|| format!("invalid inline hint prog_id in {item:?}"))?;
+        let call_pc: usize = parts.next().ok_or_else(|| anyhow!("missing hint call_pc"))?.parse()
+            .with_context(|| format!("invalid inline hint call_pc in {item:?}"))?;
+        let key_hex = parts.next().ok_or_else(|| anyhow!("missing hint key bytes"))?;
+        if parts.next().is_some() {
+            bail!("inline hint must be <prog_id>:<call_pc>:<hex_key_bytes>, got {item:?}");
+        }
+        let Some(current_prog_id) = prog_id else {
+            bail!("--inline-hint requires --prog-id for validation");
+        };
+        if hint_prog_id != current_prog_id {
+            bail!("inline hint for prog_id {hint_prog_id} does not match --prog-id {current_prog_id}");
+        }
+        let key = parse_even_hex(key_hex)?;
+        if hints.insert(call_pc, key).is_some() {
+            bail!("duplicate inline hint for call pc {call_pc}");
+        }
+    }
+    Ok(hints)
+}
+
+fn parse_even_hex(input: &str) -> Result<Vec<u8>> {
+    let hex = input.strip_prefix("0x").unwrap_or(input);
+    if hex.len() % 2 != 0 {
+        bail!("hex key must have an even number of digits");
+    }
+    (0..hex.len())
+        .step_by(2)
+        .map(|idx| u8::from_str_radix(&hex[idx..idx + 2], 16)
+            .with_context(|| format!("invalid hex byte {:?}", &hex[idx..idx + 2])))
+        .collect()
+}
diff --git a/bpfopt/crates/bpfopt/src/passes/map_inline.rs b/bpfopt/crates/bpfopt/src/passes/map_inline.rs
--- a/bpfopt/crates/bpfopt/src/passes/map_inline.rs
+++ b/bpfopt/crates/bpfopt/src/passes/map_inline.rs
@@
 fn extract_site_constant_key(
     program: &BpfProgram,
     call_pc: usize,
     info: &MapInfo,
     use_verifier_guided_keys: bool,
 ) -> Result<ConstantKey, String> {
+    if let Some(key) = hint_constant_key(program, call_pc, info)? {
+        log_map_inline_debug(&format!(
+            "site at PC={}: inline-hint key={} width={}",
+            call_pc,
+            format_constant_key(&key),
+            key.width
+        ));
+        return Ok(key);
+    }
     if use_verifier_guided_keys {
@@
     Err(detail)
 }
+
+fn hint_constant_key(
+    program: &BpfProgram,
+    call_pc: usize,
+    info: &MapInfo,
+) -> Result<Option<ConstantKey>, String> {
+    let Some(bytes) = program.map_inline_hints.get(&call_pc) else {
+        return Ok(None);
+    };
+    let expected = info.key_size as usize;
+    if bytes.len() != expected {
+        return Err(format!(
+            "inline hint at pc {call_pc} has {} byte(s), expected {expected}",
+            bytes.len()
+        ));
+    }
+    let bounds = subprog_bounds(&program.insns, call_pc);
+    let r2_setup = find_r2_stack_pointer_setup_simple(&program.insns, call_pc, bounds);
+    Ok(Some(ConstantKey {
+        stack_off: r2_setup.map(|(_, _, off)| off).unwrap_or(0),
+        width: bytes.len(),
+        value: constant_key_value(bytes),
+        bytes: bytes.clone(),
+        store_pc: call_pc,
+        source_imm_pc: None,
+        materialization_pcs: Vec::new(),
+        r2_mov_pc: r2_setup.map(|(mov_pc, _, _)| mov_pc),
+        r2_add_pc: r2_setup.map(|(_, add_pc, _)| add_pc),
+    }))
+}
```

Validation command shape after such a patch, without changing the benchmark runner:

```text
bpfopt --pass map_inline \
  --prog-id 537 \
  --inline-hint 537:1105:00000000 \
  --inline-hint 537:1807:00000000 \
  --input ${INPUT} --output ${OUTPUT} --report ${REPORT} \
  --prog-type ${PROG_TYPE} \
  --verifier-states ${VERIFIER_STATES} --map-values ${MAP_VALUES} --map-ids ${MAP_IDS}
```

For a real corpus validation through `make vm-corpus`, the daemon would also need to append `--prog-id` and selected `--inline-hint` flags to the `bpfopt` command. That is not part of this investigation.

## 5. Effort estimate

Proof of concept:

- `bpfopt` hint plumbing: 0.5 day, about 90-140 LOC.
- One focused test that proves a hinted key bypasses missing verifier state and still uses the snapshot provider: 0.25 day. This test has bug-detection value because it would fail on hint parsing, key-size validation, or failure to enter the existing rewrite path; this matches the unit-test quality rule in `CLAUDE.md:85-90`.
- Manual local validation against a retained workdir: 0.25 day.

Unlock as many of the 14 R1 sites as possible without map-in-map support:

- Easy and rigorous: PC 1105 and PC 1807 (`ctl_array[0]`).
- Useful but workload-specific: PC 512 and PC 762 (`vip_map` exact VIP key).
- Low paper value: PC 863, PC 895, PC 1351, PC 2062 (`quic_stats_map[0]` and `vip_miss_stats[0]`).
- Not useful with key-only hints: PC 520 and PC 770, because the port-zero fallback VIP key has no configured snapshot entry.
- Not unlockable without more machinery: PC 562, PC 814, PC 1072, PC 1776, because these are map-in-map or map-in-map-adjacent runtime paths.

Estimated total for all non-map-in-map viable sites:

- 1-2 days to implement route A, add tests, and produce a manual artifact showing `sites_applied > 0`.
- 2-3 days if adding daemon hint pass-through and artifact reporting.

Additional work beyond the POC:

- Sidecar JSON route B for many hints and reproducible artifact capture: +0.5-1 day, about 80-120 extra LOC over route A.
- Map-in-map practical support for katran's four map-in-map sites: 2-4 days if limited to better diagnostics and explicit outer/inner key hints; more if it needs daemon snapshot expansion and inner-map value hints.
- Reals/ch-rings opportunity: key-only hints are insufficient because R1 skipped those large array snapshots by size. Demonstrating `ch_rings[*] = 1` would need either a value hint (`call_pc:key:value`) or a map-wide uniform-value contract. That is a different optimization contract and should be estimated separately at 2-4 days for a clean, reportable implementation.

Bottom line: implement route A first and target `ctl_array[0]` at PC 1105/1807. It is the smallest honest demonstration that the current zero-apply result is blocked by key extraction, not by the replacement engine.
