# bounds_check_merge detector rewrite design (2026-05-13)

## Verdict
Recommend Relaxation C, but only with packet-fact support for end-before-data loads and stack-reloaded `PacketEnd`: it exposes 21 semantic guard sites versus 1 exact-current guard, but the committed testbin apply-count gain is still 0 consumed guards because no exposed guards form a merge-safe ladder; estimate ~100 LOC in `bounds_check_merge.rs`, ~150 LOC total with support API/fact work.

## Current detector limitation
`scan_guard_sites()` only passes `detect_guard_candidate()` the two immediately preceding sites in the same block:

```text
block_sites[idx - 2] = mov cursor, root
block_sites[idx - 1] = add cursor, K
block_sites[idx]     = jgt/jlt/jge/jle cursor, data_end, slow
```

That misses LLVM-emitted packet guards when anything appears between `add` and the compare. Katran has the expected examples:

```text
pc 42: r3 = r7
pc 43: r3 += 34
pc 44: *(u64)(r10-144) = r2
pc 45: if r3 > r2 goto 1531

pc 65: r1 = r7
pc 66: r1 += 42
pc 67: r2 = *(u64)(r10-144)
pc 68: if r1 > r2 goto 1531
```

The scan also found a second, independent fact-model issue: current `LiftedRegFact::PacketEnd { ptr_def }` pairs `data_end` with the previous `data` load in linear order. Many Cilium programs load `data_end` before `data`, so exact current `reg_fact_at()` proves only the first Katran singleton guard. A use-def detector needs either a packet-generation identity for ctx `data`/`data_end` loads or an equivalent ctx-load-chain check, plus stack preservation for spilled `PacketEnd`.

## Bytecode shape catalog
Method: decoded the 52 packet-layout testbin programs under `bpfopt/testbin/cilium_agent/*` and `bpfopt/testbin/katran/*` from raw little-endian `struct bpf_insn[]`. The semantic scan used the same register transfer rules as `compute_lifted_reg_facts`, plus two intended extensions: same packet-generation identity for ctx `data`/`data_end` regardless of load order, and stack spill/reload preservation for `PacketEnd` until a helper call or block reset. With exact current facts, only Katran pc 6 is visible.

34 of 52 packet programs have no use-def-confirmed guard under this model. The 18 programs below have would-be guards:

| program | guards | distance buckets | intervening classes | reusable same-key setup | accepted A/B/C |
| --- | ---: | --- | --- | ---: | --- |
| cilium/agent 159 `cil_xdp_entry` | 1 | 1:1 | none:1 | 0 | 1/1/1 |
| cilium/agent 195 `tail_handle_ipv4` | 1 | 1:1 | none:1 | 0 | 1/1/1 |
| cilium/agent 197 `tail_handle_arp` | 1 | 1:1 | none:1 | 0 | 1/1/1 |
| cilium/agent 198 `cil_from_container` | 1 | 3-5:1 | alu_other:1 | 0 | 0/0/1 |
| cilium/agent 199 `tail_handle_ipv4_cont` | 1 | 2:1 | alu_other:1 | 0 | 0/0/1 |
| cilium/agent 200 `tail_ipv4_to_endpoint` | 1 | 1:1 | none:1 | 0 | 1/1/1 |
| cilium/agent 201 `tail_nodeport_rev_dnat_ipv4` | 1 | 1:1 | none:1 | 0 | 1/1/1 |
| cilium/agent 202 `cil_lxc_policy` | 1 | 1:1 | none:1 | 0 | 1/1/1 |
| cilium/agent 207 `tail_no_service_ipv4` | 1 | 1:1 | none:1 | 0 | 1/1/1 |
| cilium/agent 211 `cil_lxc_policy` | 1 | 1:1 | none:1 | 0 | 1/1/1 |
| cilium/agent 212 `cil_from_container` | 1 | 3-5:1 | alu_other:1 | 0 | 0/0/1 |
| cilium/agent 213 `tail_handle_ipv4` | 1 | 1:1 | none:1 | 0 | 1/1/1 |
| cilium/agent 215 `tail_handle_arp` | 1 | 1:1 | none:1 | 0 | 1/1/1 |
| cilium/agent 216 `tail_nodeport_rev_dnat_ipv4` | 1 | 1:1 | none:1 | 0 | 1/1/1 |
| cilium/agent 218 `tail_handle_ipv4_cont` | 1 | 2:1 | alu_other:1 | 0 | 0/0/1 |
| cilium/agent 219 `tail_no_service_ipv4` | 1 | 1:1 | none:1 | 0 | 1/1/1 |
| cilium/agent 220 `tail_ipv4_to_endpoint` | 1 | 1:1 | none:1 | 0 | 1/1/1 |
| katran 530 `balancer_ingress` | 4 | 1:1, 2:3 | none:1, stack_store:1, stack_load_data_end:2 | 3 | 2/4/4 |

Aggregate distance histogram:

| distance compare-back-to-add | guards |
| --- | ---: |
| 1 strict | 14 |
| 2 | 5 |
| 3-5 | 2 |
| 6-10 | 0 |
| >10 | 0 |

Aggregate intervening classes:

| intervening class | guards |
| --- | ---: |
| none | 14 |
| ALU on other regs | 4 |
| stack store | 1 |
| stack load to `data_end_reg` | 2 |
| helper call | 0 |
| branch target inside setup window | 0 |

Top examples:

```text
cilium/agent 198 cil_from_container pc 11, window 14, distance 3, alu_other
  pc 7:  r4 = r2
  pc 8:  r4 += 14
  pc 9:  r9 = 0
  pc 10: r5 = 0
  pc 11: if r4 > r3 goto 19

cilium/agent 199 tail_handle_ipv4_cont pc 9, window 34, distance 2, alu_other
  pc 6: r3 = r4
  pc 7: r3 += 34
  pc 8: r9 = 0
  pc 9: if r3 > r2 goto 1274

katran 530 balancer_ingress pc 45, window 34, distance 2, stack_store
  pc 42: r3 = r7
  pc 43: r3 += 34
  pc 44: *(u64)(r10-144) = r2
  pc 45: if r3 > r2 goto 1531

katran 530 balancer_ingress pc 68, window 42, distance 2, stack_load_data_end
  pc 65: r1 = r7
  pc 66: r1 += 42
  pc 67: r2 = *(u64)(r10-144)
  pc 68: if r1 > r2 goto 1531

katran 530 balancer_ingress pc 78, window 62, distance 2, stack_load_data_end
  pc 75: r1 = r7
  pc 76: r1 += 62
  pc 77: r2 = *(u64)(r10-144)
  pc 78: if r1 > r2 goto 1531

cilium/agent 159 cil_xdp_entry pc 14, strict shape, end-before-data fact issue
  pc 8:  r2 = *(u32)(r6+4)
  pc 9:  r1 = *(u32)(r6+0)
  pc 12: r3 = r1
  pc 13: r3 += 14
  pc 14: if r3 > r2 goto 136

cilium/agent 195 tail_handle_ipv4 pc 9, strict shape, end-before-data fact issue
  pc 3: r2 = *(u32)(r8+80)
  pc 4: r1 = *(u32)(r8+76)
  pc 7: r3 = r1
  pc 8: r3 += 34
  pc 9: if r3 > r2 goto 1090

cilium/agent 197 tail_handle_arp pc 9, strict shape
  pc 7: r4 = r2
  pc 8: r4 += 42
  pc 9: if r4 > r3 goto 196

katran 530 balancer_ingress pc 6, exact-current singleton
  pc 4: r1 = r8
  pc 5: r1 += 14
  pc 6: if r1 > r9 goto 1560

cilium/agent 202 cil_lxc_policy pc 10, strict shape
  pc 8:  r4 = r2
  pc 9:  r4 += 14
  pc 10: if r4 > r3 goto 2321
```

## Apply-count by relaxation table
`guards detected` below uses the semantic packet-generation model described above, except the first row, which is exact current behavior. `ladders formed` applies the existing `can_extend_ladder()` policy, including same root/end regs, same slow target, monotonic window growth, `MAX_LADDER_WINDOW_GROWTH = 24`, and `interleaves_are_merge_safe()`.

| relaxation | guards detected | ladders formed >=2 | guards consumed | per-app contribution |
| --- | ---: | ---: | ---: | --- |
| Current exact detector | 1 | 0 | 0 | katran 1/0/0 |
| Strict shape + fixed packet facts | 14 | 0 | 0 | cilium 13/0/0; katran 1/0/0 |
| A: stack stores between add and compare | 15 | 0 | 0 | cilium 13/0/0; katran 2/0/0 |
| B: stack stores + `data_end` stack reloads | 17 | 0 | 0 | cilium 13/0/0; katran 4/0/0 |
| C: full use-def walk, non-clobbering interleaves | 21 | 0 | 0 | cilium 17/0/0; katran 4/0/0 |

Katran has a near-ladder at windows 34, 42, and 62 with the same root/end/slow-target key, but it is not merge-safe under current policy: branches and packet-dependent parsing sit between the guards. Widening the first check would reject packets on paths that may not require the later larger window.

## Use-def API audit
Available today:

- `RegUseDefSet` records per-instruction register `uses` and `defs`.
- `UseDefGraph` internally stores both `defs -> uses` and `uses -> defs`.
- `ProgramCFG::def_sites()` exposes defs.
- `ProgramCFG::uses_for_def(def)` exposes `defs -> uses`; `cursor_dead_after_compare()` already uses this.
- `ProgramCFG::prev_def_in_frame(start, reg)` finds the nearest prior linear-layout def in the same frame, but its own comment says callers needing CFG/dominance reasoning must not use it as the sole primitive.
- `ProgramCFG::reg_fact_at(site, reg)`, `live_in_site_checked()`, `live_out_site_checked()`, `branch_target_entry_sites()`, `sites_in_block_with_terminator()`, `site_frame()`, and `block_frame()` are sufficient support APIs for safety checks.

Missing for a clean detector:

- Expose `uses -> defs`, either as `ProgramCFG::defs_for_use(site, reg) -> &[DefSite]` or as `ProgramCFG::single_reaching_def(site, reg) -> Option<DefSite>`.
- The detector should require exactly one reaching def for the cursor use at the compare and exactly one reaching def for the cursor use at the `ADD64_IMM`.
- Existing use-def is register-only; it cannot explain `data_end` stack reloads. Either lifted facts must track stack slots containing packet facts, or a narrow stack-slot def-use helper is needed for this pass.
- Current lifted packet facts should be widened from order-sensitive `last_data_load` pairing to a same-packet ctx identity, otherwise strict Cilium guards where `data_end` is loaded before `data` remain invisible.

## Detector design (pseudocode)
```rust
fn detect_guard_candidate(compare_site, prog, target_sites) -> Result<Option<GuardSite>> {
    let cmp = prog.insn(compare_site)?;
    let Some((cursor_reg, data_end_reg, cmp_kind)) = normalize_slow_guard(cmp) else {
        return Ok(None);
    };
    if !prog.is_terminator_site(compare_site)? {
        return Ok(None);
    }

    // Semantic proof at the compare entry.
    let cursor_state = prog.reg_fact_at(compare_site, cursor_reg)?;
    let data_end_state = prog.reg_fact_at(compare_site, data_end_reg)?;
    let Some((cursor_ptr_def, window_end)) = cursor_state.as_packet_data() else {
        return Ok(None);
    };
    let Some(end_ptr_def) = data_end_state.as_packet_end() else {
        return Ok(None);
    };
    if cursor_ptr_def != end_ptr_def || window_end <= 0 {
        return Ok(None);
    }

    // CFG-backed use-def walk, not strict adjacency.
    let Some(add_def) = prog.single_reaching_def(compare_site, cursor_reg)? else {
        return Ok(None);
    };
    let add_site = add_def.site();
    let add = prog.insn(add_site)?;
    if add.code != (BPF_ALU64 | BPF_ADD | BPF_K)
        || add.dst_reg() != cursor_reg
        || add.imm != window_end
    {
        return Ok(None);
    }

    let Some(mov_def) = prog.single_reaching_def(add_site, cursor_reg)? else {
        return Ok(None);
    };
    let mov_site = mov_def.site();
    let mov = prog.insn(mov_site)?;
    if mov.code != (BPF_ALU64 | BPF_MOV | BPF_X) || mov.dst_reg() != cursor_reg {
        return Ok(None);
    }
    let root_reg = mov.src_reg();

    let root_state = prog.reg_fact_at(compare_site, root_reg)?;
    let Some((root_ptr_def, root_off)) = root_state.as_packet_data() else {
        return Ok(None);
    };
    if root_ptr_def != cursor_ptr_def || root_off != 0 {
        return Ok(None);
    }

    if !setup_window_is_safe(prog, mov_site, add_site, compare_site, cursor_reg, root_reg, data_end_reg, target_sites)? {
        return Ok(None);
    }

    let slow_target = match prog.terminator_at_site(compare_site)? {
        Terminator::CondBranch { taken, .. } => taken,
        _ => return Ok(None),
    };
    let cursor_dead = cursor_dead_after_compare(prog, add_site, compare_site, cursor_reg);

    Ok(Some(GuardSite {
        mov: mov_site,
        add: add_site,
        compare: compare_site,
        root_reg,
        data_end_reg,
        root_ptr_def: cursor_ptr_def,
        window_end,
        cmp_kind,
        slow_target,
        can_widen_in_place: !target_sites.contains(&mov_site)
            && !target_sites.contains(&add_site)
            && !target_sites.contains(&compare_site)
            && cursor_dead,
        can_remove_setup: !target_sites.contains(&mov_site)
            && !target_sites.contains(&add_site)
            && cursor_dead,
    }))
}
```

`setup_window_is_safe()` should require same frame, no branch target entry between setup and compare, no branch/call between setup and compare, no redefinition of `cursor_reg` or `root_reg`, and no redefinition of `data_end_reg` unless the redefining instruction is a proven same-packet `PacketEnd` rematerialization. The final `reg_fact_at(compare_site, data_end_reg)` remains the semantic authority.

`apply_rewrites()` does not need structural changes. It already accepts arbitrary `skip_sites`, replaces the dominant `add`, deletes body sites in reverse order, and deletes consumed branch terminators. If a non-adjacent consumed guard has `mov/add; reload data_end; compare`, deleting only `mov/add/compare` leaves the reload as dead code; that is safe and can be left for `dce`. If an intervening instruction uses the cursor, `cursor_dead_after_compare()` makes `can_remove_setup = false`, so the pass can remove only the redundant compare.

## Risk analysis
- Spill/reload can hide a changed `data_end` unless facts model the stack slot. Current `reg_fact_at()` marks `LDX DW rX, [r10-N]` as `Unknown`; B/C need stack packet facts or a narrow stack-slot def-use proof. A reload should be accepted only when the stored value was `PacketEnd` for the same packet generation and no helper/block reset invalidated it.
- End-before-data loads are common in Cilium. Current `PacketEnd { ptr_def } = last_data_load.unwrap_or(site)` makes those fail ptr equality. A same ctx packet identity is needed if the detector keeps requiring end/root identity.
- Branch target entry between setup and compare should reject the guard. Otherwise deleting `mov/add` can remove code reachable from another predecessor, and widening an earlier guard can change path-specific packet acceptance.
- Subprogram boundaries must not be crossed. Require `mov_site`, `add_site`, and `compare_site` in the same `FrameId`.
- Phi-like joins should reject automatically if the new API requires exactly one reaching def. Current lifted facts also reset at multi-predecessor and non-layout predecessor blocks, so many joins become `Unknown`; do not rely on `prev_def_in_frame()` alone.
- Helper calls between setup and compare should reject. The current lift clears packet facts across calls; stack packet facts should be cleared too unless a future helper-specific invalidation model is added.

## Implementation cost
- `bounds_check_merge.rs`: ~90-120 production LOC. Replace adjacency-driven setup discovery with use-def discovery, add `setup_window_is_safe()`, keep `cursor_dead_after_compare()` and existing ladder construction.
- Use-def API: ~20-35 LOC to expose `defs_for_use` or `single_reaching_def`.
- Lifted packet facts / stack support: ~35-60 LOC if implemented generally in `bbprogram.rs`; less if done as a pass-local helper, but the general version is cleaner.
- Tests: ~120-180 LOC. Add fixtures for stack-store interleave, stack-store plus `data_end` reload, unrelated ALU interleave, branch-target rejection, wrong stack slot or stale helper-invalidated reload rejection, multi-def join rejection, and one non-adjacent consumed guard that proves branch offsets still lower correctly.
- `apply_rewrites` changes: no.
- `interleaves_are_merge_safe` changes: no. Keep it as the consecutive-guard ladder safety gate; add a separate setup-to-compare safety check in the detector.

## Recommendation
Implement Relaxation C behind the existing pass policy, but do it in this order: first expose a CFG-backed single-reaching-def query and fix packet facts for same-ctx `data`/`data_end` plus stack-reloaded `PacketEnd`; then rewrite `detect_guard_candidate()` around use-def; then rerun the 52-program scan and real `bounds_check_merge` CLI. Do not relax `interleaves_are_merge_safe()` in the same change, because the current testbin gain is detector coverage only, not a proven safe ladder apply-count gain.
