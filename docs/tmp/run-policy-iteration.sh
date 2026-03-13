#!/usr/bin/env bash
# Policy iteration script — runs 4+ rounds in VM, finds best policy combo for dense benchmarks
# Usage: bash docs/tmp/run-policy-iteration.sh

set -euo pipefail
ROOT=/home/yunwei37/workspace/bpf-benchmark
VENV=/home/yunwei37/workspace/.venv
BZIMAGE="$ROOT/vendor/linux-framework/arch/x86/boot/bzImage"
POLICY_DIR="$ROOT/micro/policies"
RESULTS_DIR="$ROOT/micro/results"
TMP_DIR="$ROOT/docs/tmp"
LOGFILE="$TMP_DIR/policy-iteration-rounds.md"

cd "$ROOT"

# ── backup original policy files ──────────────────────────────────────────────
backup_policy() {
  local name=$1
  local src="$POLICY_DIR/${name}.yaml"
  local bak="$POLICY_DIR/${name}.yaml.orig"
  if [[ ! -f "$bak" ]]; then
    cp "$src" "$bak"
    echo "  Backed up $name → ${name}.yaml.orig"
  fi
}

restore_policy() {
  local name=$1
  local bak="$POLICY_DIR/${name}.yaml.orig"
  if [[ -f "$bak" ]]; then
    cp "$bak" "$POLICY_DIR/${name}.yaml"
  fi
}

write_empty_policy() {
  local name=$1
  local prog=$2
  cat > "$POLICY_DIR/${name}.yaml" <<EOF
version: 3
program: '${prog}'
sites: []
EOF
}

# ── keep first N sites ─────────────────────────────────────────────────────────
keep_first_n_sites() {
  local name=$1
  local n=$2
  local orig="$POLICY_DIR/${name}.yaml.orig"
  python3 - "$orig" "$POLICY_DIR/${name}.yaml" "$n" <<'PYEOF'
import sys, yaml
src, dst, n_str = sys.argv[1], sys.argv[2], sys.argv[3]
n = int(n_str)
with open(src) as f:
    d = yaml.safe_load(f)
d['sites'] = d['sites'][:n]
with open(dst, 'w') as f:
    yaml.dump(d, f, default_flow_style=False, allow_unicode=True)
print(f"  Kept first {n} sites in {dst}")
PYEOF
}

# ── run VM benchmark for 6 dense benches ─────────────────────────────────────
run_dense_benches() {
  local out_json=$1
  echo "  Running VM benchmark → $out_json ..."
  vng --run "$BZIMAGE" --rwdir "$ROOT" -- bash -lc "
    cd '$ROOT'
    source '$VENV/bin/activate'
    python3 micro/run_micro.py \
      --runtime kernel --runtime kernel-recompile \
      --bench cond_select_dense \
      --bench extract_dense \
      --bench endian_swap_dense \
      --bench rotate_dense \
      --bench addr_calc_stride \
      --bench branch_flip_dense \
      --iterations 2 --warmups 2 --repeat 500 \
      --output '$out_json'
  " 2>&1 | tail -30
}

# ── compute ratios from JSON ──────────────────────────────────────────────────
compute_ratios() {
  local json=$1
  python3 - "$json" <<'PYEOF'
import json, math, sys
with open(sys.argv[1]) as f:
    d = json.load(f)
benchmarks = d['benchmarks']
by_name = {}
for b in benchmarks:
    by_name.setdefault(b['name'], {})[b['runtime']] = b
ratios = {}
for name, rts in by_name.items():
    if 'kernel' in rts and 'kernel-recompile' in rts:
        base_ns = rts['kernel']['exec_ns']['median']
        recomp_ns = rts['kernel-recompile']['exec_ns']['median']
        ratios[name] = base_ns / recomp_ns
print("| Benchmark | ratio |")
print("|-----------|-------|")
geomean_all = 1.0
geomean_applied = 1.0
count_all = 0
count_applied = 0
for name in sorted(ratios):
    r = ratios[name]
    tag = ""
    geomean_all *= r
    count_all += 1
    print(f"| {name} | {r:.3f}x |")
if count_all:
    gm_all = geomean_all ** (1/count_all)
    print(f"\nGeomean (all 6): {gm_all:.3f}x")
PYEOF
}

# ── init log file ─────────────────────────────────────────────────────────────
mkdir -p "$TMP_DIR"
cat > "$LOGFILE" <<'EOF'
# Policy Iteration Rounds — Dense Benchmark Optimization

Goal: find policy combo with applied-only geomean > 1.0x for dense benchmarks.

Baselines (from micro_62bench_post_bextr_fix_20260313.json):
- cond_select_dense: 0.482x (104 cmov sites → heavy regression)
- extract_dense: 0.556x (512 bextr sites → heavy regression)
- endian_swap_dense: 0.695x (256 endian sites → regression)
- rotate_dense: 1.167x (positive)
- addr_calc_stride: 1.401x (positive)
- branch_flip_dense: 1.052x (positive)

EOF

# ── backup all 3 problematic policies ─────────────────────────────────────────
echo "=== Backing up original policies ==="
backup_policy cond_select_dense
backup_policy extract_dense
backup_policy endian_swap_dense

# ══════════════════════════════════════════════════════════════════════════════
echo ""
echo "=== ROUND 1: Skip all 3 regressors (empty sites) ==="
echo "" >> "$LOGFILE"
echo "## Round 1: Skip all 3 regressors (sites: [])" >> "$LOGFILE"
echo "" >> "$LOGFILE"
echo "Policy: cond_select_dense=[], extract_dense=[], endian_swap_dense=[]" >> "$LOGFILE"
echo "" >> "$LOGFILE"

write_empty_policy cond_select_dense "cond_select_dense_xdp"
write_empty_policy extract_dense "extract_dense_xdp"
write_empty_policy endian_swap_dense "endian_swap_dense_xdp"

OUT1="$TMP_DIR/policy_round1.json"
run_dense_benches "$OUT1"

echo "" >> "$LOGFILE"
compute_ratios "$OUT1" >> "$LOGFILE"
echo "" >> "$LOGFILE"
echo "Round 1 results saved to: $OUT1" >> "$LOGFILE"
echo "Round 1 complete. Results:"
compute_ratios "$OUT1"

# ══════════════════════════════════════════════════════════════════════════════
echo ""
echo "=== ROUND 2: Restore extract_dense only (keep cmov+endian empty) ==="
echo "" >> "$LOGFILE"
echo "## Round 2: Restore extract_dense, keep cmov+endian empty" >> "$LOGFILE"
echo "" >> "$LOGFILE"
echo "Policy: cond_select_dense=[], extract_dense=FULL(512), endian_swap_dense=[]" >> "$LOGFILE"
echo "" >> "$LOGFILE"

# restore extract_dense to original
restore_policy extract_dense

OUT2="$TMP_DIR/policy_round2.json"
run_dense_benches "$OUT2"

echo "" >> "$LOGFILE"
compute_ratios "$OUT2" >> "$LOGFILE"
echo "" >> "$LOGFILE"
echo "Round 2 results saved to: $OUT2" >> "$LOGFILE"
echo "Round 2 complete. Results:"
compute_ratios "$OUT2"

# ══════════════════════════════════════════════════════════════════════════════
echo ""
echo "=== ROUND 3: extract_dense with 50 sites only ==="
echo "" >> "$LOGFILE"
echo "## Round 3: extract_dense = first 50 sites, cmov+endian empty" >> "$LOGFILE"
echo "" >> "$LOGFILE"
echo "Policy: cond_select_dense=[], extract_dense=first50, endian_swap_dense=[]" >> "$LOGFILE"
echo "" >> "$LOGFILE"

# set extract to first 50 sites
source "$VENV/bin/activate"
keep_first_n_sites extract_dense 50

OUT3="$TMP_DIR/policy_round3.json"
run_dense_benches "$OUT3"

echo "" >> "$LOGFILE"
compute_ratios "$OUT3" >> "$LOGFILE"
echo "" >> "$LOGFILE"
echo "Round 3 results saved to: $OUT3" >> "$LOGFILE"
echo "Round 3 complete. Results:"
compute_ratios "$OUT3"

# ══════════════════════════════════════════════════════════════════════════════
echo ""
echo "=== ROUND 4: extract_dense with 100 sites ==="
echo "" >> "$LOGFILE"
echo "## Round 4: extract_dense = first 100 sites, cmov+endian empty" >> "$LOGFILE"
echo "" >> "$LOGFILE"
echo "Policy: cond_select_dense=[], extract_dense=first100, endian_swap_dense=[]" >> "$LOGFILE"
echo "" >> "$LOGFILE"

keep_first_n_sites extract_dense 100

OUT4="$TMP_DIR/policy_round4.json"
run_dense_benches "$OUT4"

echo "" >> "$LOGFILE"
compute_ratios "$OUT4" >> "$LOGFILE"
echo "" >> "$LOGFILE"
echo "Round 4 results saved to: $OUT4" >> "$LOGFILE"
echo "Round 4 complete. Results:"
compute_ratios "$OUT4"

# ══════════════════════════════════════════════════════════════════════════════
# Determine best extract_dense policy based on rounds 1-4
echo ""
echo "=== Determining best extract_dense sites count ==="

# Parse geomean from round outputs
R1_GM=$(compute_ratios "$OUT1" | grep "Geomean" | awk '{print $NF}' | tr -d 'x')
R2_GM=$(compute_ratios "$OUT2" | grep "Geomean" | awk '{print $NF}' | tr -d 'x')
R3_GM=$(compute_ratios "$OUT3" | grep "Geomean" | awk '{print $NF}' | tr -d 'x')
R4_GM=$(compute_ratios "$OUT4" | grep "Geomean" | awk '{print $NF}' | tr -d 'x')

echo "  Round 1 (all empty):       $R1_GM"
echo "  Round 2 (extract full):    $R2_GM"
echo "  Round 3 (extract 50):      $R3_GM"
echo "  Round 4 (extract 100):     $R4_GM"

echo "" >> "$LOGFILE"
echo "## Geomean Summary" >> "$LOGFILE"
echo "" >> "$LOGFILE"
echo "| Round | Config | Geomean |" >> "$LOGFILE"
echo "|-------|--------|---------|" >> "$LOGFILE"
echo "| R1 | all empty | ${R1_GM}x |" >> "$LOGFILE"
echo "| R2 | extract full | ${R2_GM}x |" >> "$LOGFILE"
echo "| R3 | extract 50 | ${R3_GM}x |" >> "$LOGFILE"
echo "| R4 | extract 100 | ${R4_GM}x |" >> "$LOGFILE"

# Pick best config: whichever has highest geomean
# Use python to compare floats
BEST_ROUND=$(python3 - "$R1_GM" "$R2_GM" "$R3_GM" "$R4_GM" <<'PYEOF'
import sys
vals = [float(x) for x in sys.argv[1:]]
best_idx = vals.index(max(vals)) + 1
print(best_idx)
PYEOF
)
echo ""
echo "Best round: R$BEST_ROUND"

# Apply best policy
case "$BEST_ROUND" in
  1)
    echo "Best: all empty — keeping extract empty"
    write_empty_policy extract_dense "extract_dense_xdp"
    BEST_DESC="all 3 dense regressors empty (sites: [])"
    ;;
  2)
    echo "Best: extract full 512"
    restore_policy extract_dense
    BEST_DESC="cond_select+endian empty, extract full 512 sites"
    ;;
  3)
    echo "Best: extract first 50 sites"
    keep_first_n_sites extract_dense 50
    BEST_DESC="cond_select+endian empty, extract first 50 sites"
    ;;
  4)
    echo "Best: extract first 100 sites"
    keep_first_n_sites extract_dense 100
    BEST_DESC="cond_select+endian empty, extract first 100 sites"
    ;;
esac

echo "" >> "$LOGFILE"
echo "## Best Policy Selected: $BEST_DESC" >> "$LOGFILE"

# ══════════════════════════════════════════════════════════════════════════════
echo ""
echo "=== ROUND 5: Full 62-bench authoritative run with optimal policy ==="
echo "" >> "$LOGFILE"
echo "## Round 5: Full 62-bench Authoritative Run" >> "$LOGFILE"
echo "" >> "$LOGFILE"
echo "Policy: $BEST_DESC" >> "$LOGFILE"
echo "" >> "$LOGFILE"

TIMESTAMP=$(date +%Y%m%d)
OUT5="$RESULTS_DIR/micro_62bench_policy_optimized_${TIMESTAMP}.json"

echo "Running full 62-bench (this will take ~15-30 min) → $OUT5"
vng --run "$BZIMAGE" --rwdir "$ROOT" -- bash -lc "
  cd '$ROOT'
  source '$VENV/bin/activate'
  python3 micro/run_micro.py \
    --runtime kernel --runtime kernel-recompile \
    --iterations 10 --warmups 2 --repeat 1000 \
    --output '$OUT5'
" 2>&1 | tail -50

echo "" >> "$LOGFILE"
echo "Full 62-bench results: $OUT5" >> "$LOGFILE"
echo "" >> "$LOGFILE"

# Compute overall + applied-only geomean
python3 - "$OUT5" >> "$LOGFILE" <<'PYEOF'
import json, math, sys
with open(sys.argv[1]) as f:
    d = json.load(f)
benchmarks = d['benchmarks']
by_name = {}
for b in benchmarks:
    by_name.setdefault(b['name'], {})[b['runtime']] = b

ratios = {}
for name, rts in by_name.items():
    if 'kernel' in rts and 'kernel-recompile' in rts:
        base_ns = rts['kernel']['exec_ns']['median']
        recomp_ns = rts['kernel-recompile']['exec_ns']['median']
        ratios[name] = base_ns / recomp_ns

print("### Per-benchmark ratios (kernel-recompile / kernel):\n")
print("| Benchmark | ratio |")
print("|-----------|-------|")
gm_all = 1.0
gm_applied = 1.0
cnt_all = 0
cnt_applied = 0
for name in sorted(ratios):
    r = ratios[name]
    gm_all *= r
    cnt_all += 1
    print(f"| {name} | {r:.3f}x |")

if cnt_all:
    print(f"\n**Overall geomean ({cnt_all} benches): {gm_all**(1/cnt_all):.3f}x**")
PYEOF

echo ""
echo "=== DONE. Results in $LOGFILE and $OUT5 ==="
echo "=== Optimal policy: $BEST_DESC ==="

# Also append to plan doc a summary note
cat >> "$ROOT/docs/kernel-jit-optimization-plan.md" <<PLANEOF

## §Policy Iteration Results ($(date +%Y-%m-%d))

- **Optimal dense policy**: $BEST_DESC
- Full 62-bench results: $OUT5
- Iteration log: $LOGFILE
- See docs/tmp/policy-iteration-rounds.md for per-round details.

PLANEOF

echo "Updated docs/kernel-jit-optimization-plan.md with summary."
