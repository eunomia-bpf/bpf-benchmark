#!/usr/bin/env bash
set -euo pipefail
REPO=/home/yunwei37/workspace/bpf-benchmark
RESULTS_DIR=$REPO/micro/results/per_form_ablation_20260313
BZIMAGE=$REPO/vendor/linux-framework/arch/x86/boot/bzImage

# Step 1: Generate ablation policy files
python3 - << 'PYEOF'
import os, yaml, copy

REPO = "/home/yunwei37/workspace/bpf-benchmark"
POLICIES_DIR = os.path.join(REPO, "micro/policies")
ABLATION_DIR = os.path.join(REPO, "micro/policies/ablation")
FAMILIES = ["rotate", "wide", "lea", "cmov", "extract", "endian", "branch-flip"]
FAMILY_SLUGS = {f: f.replace("-", "_") for f in FAMILIES}

# Read all original policies (including recovered dense ones from git)
import subprocess
bench_policies = {}

for fname in os.listdir(POLICIES_DIR):
    if not fname.endswith(".yaml"):
        continue
    if fname.startswith("ablation"):
        continue
    bench = fname[:-5]
    fpath = os.path.join(POLICIES_DIR, fname)
    with open(fpath) as f:
        data = yaml.safe_load(f)
    if data and 'sites' in data:
        bench_policies[bench] = data

# Recover the three dense policies with full sites from git
for bench, commit in [
    ("cond_select_dense", "c054510"),
    ("endian_swap_dense", "c054510"),
    ("extract_dense", "c054510"),
]:
    result = subprocess.run(
        ["git", "show", f"{commit}:micro/policies/{bench}.yaml"],
        capture_output=True, text=True, cwd=REPO
    )
    if result.returncode == 0:
        data = yaml.safe_load(result.stdout)
        if data and 'sites' in data:
            bench_policies[bench] = data
            print(f"  Recovered {bench}: {len(data.get('sites', []))} sites")

# Generate per-family policy files
for family in FAMILIES:
    slug = FAMILY_SLUGS[family]
    family_dir = os.path.join(ABLATION_DIR, slug)
    os.makedirs(family_dir, exist_ok=True)
    
    for bench, data in bench_policies.items():
        sites = data.get('sites', []) or []
        family_sites = [s for s in sites if s.get('family') == family]
        new_data = copy.deepcopy(data)
        new_data['sites'] = family_sites
        out_path = os.path.join(family_dir, f"{bench}.yaml")
        with open(out_path, 'w') as f:
            yaml.dump(new_data, f, default_flow_style=False, allow_unicode=True)
    
    count = len(os.listdir(family_dir))
    print(f"  {family}: {count} policy files in {family_dir}")

print("Policy generation complete")
PYEOF

echo "--- Policy files generated ---"
ls -la $REPO/micro/policies/ablation/

# Step 2: Run all targeted ablations in ONE VM session
# ROTATE: benchmarks with rotate sites
# WIDE: benchmarks with wide sites  
# LEA: benchmarks with lea sites
# CMOV: benchmarks with cmov sites
# EXTRACT: benchmarks with extract sites
# ENDIAN: benchmarks with endian sites
# BRANCH_FLIP: benchmarks with branch-flip sites

mkdir -p $RESULTS_DIR

echo "--- Launching single VM session for all targeted ablations ---"
vng --run $BZIMAGE --memory 4G --cpus 2 --rwdir $REPO -- bash -lc "
source /home/yunwei37/workspace/.venv/bin/activate
cd $REPO

echo '=== ROTATE: rotate_dense, cmov_dense (has rotate sites!), memcmp_prefix_64 ==='
taskset -c 0 python3 micro/run_micro.py \
  --suite config/ablation/ablation_rotate.yaml \
  --bench rotate_dense --bench cmov_dense --bench memcmp_prefix_64 \
  --runtime kernel --runtime kernel-recompile \
  --iterations 5 --warmups 3 --repeat 1000 \
  --output $RESULTS_DIR/ablation_rotate_targeted.json 2>&1 | tail -3
echo 'ROTATE done'

echo '=== WIDE: binary_search, log2_fold, bounds_ladder, bpf_call_chain, branch_dense, mixed_alu_mem, multi_acc_4, multi_acc_8, switch_dispatch ==='
taskset -c 0 python3 micro/run_micro.py \
  --suite config/ablation/ablation_wide.yaml \
  --bench binary_search --bench log2_fold --bench bounds_ladder --bench bpf_call_chain --bench branch_dense --bench mixed_alu_mem --bench multi_acc_4 --bench multi_acc_8 --bench switch_dispatch \
  --runtime kernel --runtime kernel-recompile \
  --iterations 5 --warmups 3 --repeat 1000 \
  --output $RESULTS_DIR/ablation_wide_targeted.json 2>&1 | tail -3
echo 'WIDE done'

echo '=== LEA: addr_calc_stride, multi_acc_4, multi_acc_8 ==='
taskset -c 0 python3 micro/run_micro.py \
  --suite config/ablation/ablation_lea.yaml \
  --bench addr_calc_stride --bench multi_acc_4 --bench multi_acc_8 \
  --runtime kernel --runtime kernel-recompile \
  --iterations 5 --warmups 3 --repeat 1000 \
  --output $RESULTS_DIR/ablation_lea_targeted.json 2>&1 | tail -3
echo 'LEA done'

echo '=== CMOV: binary_search, bounds_ladder, bpf_call_chain, branch_dense, cmov_select, cond_select_dense, switch_dispatch ==='
taskset -c 0 python3 micro/run_micro.py \
  --suite config/ablation/ablation_cmov.yaml \
  --bench binary_search --bench bounds_ladder --bench bpf_call_chain --bench branch_dense --bench cmov_select --bench cond_select_dense --bench switch_dispatch \
  --runtime kernel --runtime kernel-recompile \
  --iterations 5 --warmups 3 --repeat 1000 \
  --output $RESULTS_DIR/ablation_cmov_targeted.json 2>&1 | tail -3
echo 'CMOV done'

echo '=== EXTRACT: mixed_alu_mem, extract_dense (bitfield_extract) ==='
taskset -c 0 python3 micro/run_micro.py \
  --suite config/ablation/ablation_extract.yaml \
  --bench mixed_alu_mem --bench extract_dense \
  --runtime kernel --runtime kernel-recompile \
  --iterations 5 --warmups 3 --repeat 1000 \
  --output $RESULTS_DIR/ablation_extract_targeted.json 2>&1 | tail -3
echo 'EXTRACT done'

echo '=== ENDIAN: endian_swap_dense ==='
taskset -c 0 python3 micro/run_micro.py \
  --suite config/ablation/ablation_endian.yaml \
  --bench endian_swap_dense \
  --runtime kernel --runtime kernel-recompile \
  --iterations 5 --warmups 3 --repeat 1000 \
  --output $RESULTS_DIR/ablation_endian_targeted.json 2>&1 | tail -3
echo 'ENDIAN done'

echo '=== BRANCH_FLIP: branch_dense, branch_flip_dense, large_mixed_500 ==='
taskset -c 0 python3 micro/run_micro.py \
  --suite config/ablation/ablation_branch_flip.yaml \
  --bench branch_dense --bench branch_flip_dense --bench large_mixed_500 \
  --runtime kernel --runtime kernel-recompile \
  --iterations 5 --warmups 3 --repeat 1000 \
  --output $RESULTS_DIR/ablation_branch_flip_targeted.json 2>&1 | tail -3
echo 'BRANCH_FLIP done'

echo '=== ALL FILES ==='
ls -la $RESULTS_DIR/
echo '=== VM SESSION COMPLETE ==='
"

echo "--- VM session finished ---"
ls -la $RESULTS_DIR/
