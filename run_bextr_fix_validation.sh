#!/bin/bash
# BEXTR without-copy fix: build + validate
# Run this script from /home/yunwei37/workspace/bpf-benchmark

set -e

REPO=/home/yunwei37/workspace/bpf-benchmark
LINUX=$REPO/vendor/linux-framework

echo "=== Step 1: Build bzImage with BEXTR without-copy fix ==="
cd $LINUX
make -j$(nproc) bzImage 2>&1 | tail -20
echo "Build complete. bzImage: $LINUX/arch/x86/boot/bzImage"

echo ""
echo "=== Step 2: Run benchmarks in VM (stock, no recompile) ==="
cd $REPO
source /home/yunwei37/workspace/.venv/bin/activate

vng --run $LINUX/arch/x86/boot/bzImage --exec \
  "source /home/yunwei37/workspace/.venv/bin/activate && \
   cd $REPO && \
   python3 micro/run_micro.py \
     --runtime kernel \
     --bench extract_dense --bench bitfield_extract --bench rotate_dense \
     --iterations 2 --warmups 1 --repeat 200 \
     --output $REPO/micro/results/bextr_without_copy_fix_stock.json && \
   echo 'Stock run complete'"

echo ""
echo "=== Step 3: Run benchmarks in VM (with recompile policy) ==="

vng --run $LINUX/arch/x86/boot/bzImage --exec \
  "source /home/yunwei37/workspace/.venv/bin/activate && \
   cd $REPO && \
   python3 micro/run_micro.py \
     --runtime kernel \
     --bench extract_dense --bench bitfield_extract --bench rotate_dense \
     --iterations 2 --warmups 1 --repeat 200 \
     --recompile-policy $REPO/micro/policies/ \
     --output $REPO/micro/results/bextr_without_copy_fix_recompile.json && \
   echo 'Recompile run complete'"

echo ""
echo "=== Step 4: Compare results ==="
python3 - <<'PYEOF'
import json

def load_results(path):
    with open(path) as f:
        data = json.load(f)
    results = {}
    for entry in data.get('results', data if isinstance(data, list) else []):
        name = entry.get('bench') or entry.get('name', '')
        runtime = entry.get('runtime', '')
        median = entry.get('exec_ns_median') or entry.get('median_exec_ns', 0)
        results[(name, runtime)] = median
    return results

try:
    stock = load_results('micro/results/bextr_without_copy_fix_stock.json')
    recompile = load_results('micro/results/bextr_without_copy_fix_recompile.json')

    print("Benchmark comparison (recompile/stock ratio, >1 = improvement):")
    for key in sorted(set(stock.keys()) | set(recompile.keys())):
        s = stock.get(key, 0)
        r = recompile.get(key, 0)
        if s > 0 and r > 0:
            ratio = s / r
            print(f"  {key[0]:30s}: stock={s:.0f}ns, recompile={r:.0f}ns, ratio={ratio:.3f}x")
except Exception as e:
    print(f"Comparison failed: {e}")
    print("Check result files manually.")
PYEOF

echo ""
echo "=== Done. Results in micro/results/bextr_without_copy_fix_*.json ==="
