# Pending Tasks Summary (2026-03-13)

## Critical Blocker: /tmp/claude-1000 Permissions

**Problem**: `/tmp/claude-1000` has broken permissions → Claude's Bash tool CANNOT execute any command.

**Fix** (run from terminal):
```bash
sudo rm -rf /tmp/claude-1000
sudo mkdir -p /tmp/claude-1000
sudo chmod 1777 /tmp/claude-1000
# Verify: stat -c '%a %U:%G' /tmp/claude-1000
# Expected: 1777 root:root
```

After fix, Claude's Bash tool will work again in new sessions.

## Completed by Claude (File Operations Only)

### #171 Policy Optimization (Dense Benchmarks)

**Status**: Policy files updated, static analysis complete, VM verification pending.

**Changes made**:
- `micro/policies/cond_select_dense.yaml` → `sites: []` (was 104 cmov sites)
- `micro/policies/extract_dense.yaml` → `sites: []` (was 512 extract sites)
- `micro/policies/endian_swap_dense.yaml` → `sites: []` (was 256 endian sites)

**Analysis** (`docs/tmp/policy-iteration-rounds.md`):
- cond_select_dense 0.482x: predictable-branch CMOV regression → skip
- extract_dense 0.556x: without-copy BEXTR emitter bug (#170) → skip
- endian_swap_dense 0.695x: same-size MOVBE, I-cache flush cost → skip

**Expected results after VM verification**:
| Benchmark | Before | After |
|-----------|--------|-------|
| cond_select_dense | 0.482x | ~1.000x (skipped) |
| extract_dense | 0.556x | ~1.000x (skipped) |
| endian_swap_dense | 0.695x | ~1.000x (skipped) |
| rotate_dense | 1.167x | 1.167x (unchanged) |
| addr_calc_stride | 1.401x | 1.401x (unchanged) |
| branch_flip_dense | 1.052x | 1.052x (unchanged) |
| **Geomean (6 benches)** | **0.836x** | **~1.080x** |
| **Applied-only (3 benches)** | **1.198x** | **1.198x** |

This achieves the `applied-only geomean > 1.0x` target for dense benchmarks.

## Pending Execution (Requires Terminal)

### Run Everything

```bash
# Fix permissions first, then run all tasks:
bash /home/yunwei37/workspace/bpf-benchmark/docs/tmp/fix-and-run-all.sh
```

This script will:
1. Fix /tmp/claude-1000 permissions
2. Run policy iteration VM benchmark (verify dense policy results)
3. Run corpus post-fix rerun (fixed packet + use-policy mode)

### Policy Iteration Verification Only

```bash
source /home/yunwei37/workspace/.venv/bin/activate
bash /home/yunwei37/workspace/bpf-benchmark/docs/tmp/run-policy-iteration.sh
```

Expected: Rounds 1-4 comparison, full 62-bench authoritative run with optimal policy.

### Corpus Rerun Only

```bash
cd /home/yunwei37/workspace/bpf-benchmark
source /home/yunwei37/workspace/.venv/bin/activate
rm -f micro/generated-inputs/corpus_dummy_packet_64.bin
bash run_corpus_rerun.sh
```

Expected output: `corpus/results/corpus_post_fix_20260313.json`

## TODO After Execution

1. Update MEMORY.md with actual VM verification results
2. Update plan doc `docs/kernel-jit-optimization-plan.md` with actual geomean numbers
3. **#170**: Fix `emit_bitfield_extract_core` — add `src_reg != dst_reg` guard for without-copy path
   - After fix: restore extract_dense sites, expect ~0.7-0.9x improvement
4. Full 62-bench authoritative rerun after #170 fix

## Key Files

| File | Purpose |
|------|---------|
| `docs/tmp/fix-and-run-all.sh` | Master script: fix permissions + run all tasks |
| `docs/tmp/run-policy-iteration.sh` | Policy iteration VM benchmark (5 rounds) |
| `run_corpus_rerun.sh` | Corpus post-fix rerun |
| `docs/tmp/policy-iteration-rounds.md` | Policy analysis + expected results |
| `micro/policies/cond_select_dense.yaml` | CHANGED: sites: [] |
| `micro/policies/extract_dense.yaml` | CHANGED: sites: [] |
| `micro/policies/endian_swap_dense.yaml` | CHANGED: sites: [] |
