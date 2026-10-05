# ARM64 t4g.micro Benchmark Report

- Local task date: 2026-03-20 (America/Vancouver)
- Successful benchmark JSON `run_date`: 2026-03-21T04:48:45.625189+00:00
- AWS profile / region: `codex-ec2` / `us-east-1`
- Successful instance: `i-0f0e3e192f5545f8b`
- Instance type: `t4g.micro`
- Booted kernel: `7.0.0-rc2+`
- Result JSON: `micro/results/dev/arm64_t4g_micro_20260320.json`
- Raw cache bundle: `.cache/aws-arm64/results/benchmark_20260321_044520/results/`

## Run Flow

1. Confirmed no residual EC2 instances before launch.
2. Rebuilt local ARM64 userspace bundle with `make cross-arm64`.
3. Ran `runner/scripts/aws_arm64.sh full` with:
   - `AWS_ARM64_INSTANCE_TYPE=t4g.micro`
   - `AWS_ARM64_BENCH_ITERATIONS=10`
   - `AWS_ARM64_BENCH_WARMUPS=2`
   - `AWS_ARM64_BENCH_REPEAT=200`
4. `full` completed launch -> setup -> benchmark -> terminate successfully.
5. Confirmed no residual EC2 instances after termination.

## Key Results

### 1. llvmbpf vs kernel characterization

- Benchmarks completed: 62 / 62
- llvmbpf faster: 61
- kernel faster: 1
- Geometric-mean `llvmbpf/kernel` ratio: `0.5107`
- Median `llvmbpf/kernel` ratio: `0.5447`
- Strongest llvmbpf wins:
  - `multi_acc_8`: `0.2354`
  - `load_byte_recompose`: `0.2378`
  - `cmov_select`: `0.2411`
  - `rotate64_hash`: `0.3125`
  - `stride_load_16`: `0.3259`
- Only kernel win:
  - `branch_flip_dense`: `1.3617`

Note: the JSON summary helper currently names the top-ratio lists backwards; interpret them by the ratio value itself (`< 1.0` means llvmbpf faster).

### 2. kernel stock vs recompile

- Benchmarks completed: 62 / 62
- Benchmarks with scanner sites: 58
- Total sites enumerated: 2387
- Total sites applied: 1717
- Median absolute exec delta: `12.25 ns`
- Max absolute exec delta: `820.5 ns` on `nested_loop_3`
- Highest-site benchmarks:
  - `mega_basic_block_2048`: `520` sites, `520` applied
  - `extract_dense`: `512` sites, `512` applied
  - `rotate_dense`: `256` sites, `256` applied
  - `endian_swap_dense`: `256` sites, `0` applied
  - `branch_flip_dense`: `255` sites, `0` applied

### 3. Katran `balancer_ingress` recompile smoke

- `bpftool prog loadall ... kernel_btf ...` on AL2023 still fails with:
  - `Error: expected no more arguments, 'type', 'map' or 'dev', got: 'kernel_btf'?`
- Fallback load path without `kernel_btf` succeeded (`rc=0`)
- Scanner enumerate: `74` sites
- Scanner recompile: `6` applied
- `recompile_ok=true`
- No `0 sites` regression reproduced on `t4g.micro`

## Pipeline Fixes Used By This Run

- ARM64 cross-build now enables llvmbpf in `micro_exec`.
- ARM64 cross-build image now includes `git` and `llvm-devel`.
- `runner/CMakeLists.txt` now pre-creates global `LLVM`/`ZLIB`/`Terminfo` targets so llvmbpf links correctly on Amazon Linux 2023.
- `aws_arm64.sh benchmark` now uploads the full micro/scanner/Katran bundle and executes the remote full-suite runner.
- Remote benchmark execution now uses `python3.11` and `LD_LIBRARY_PATH=$root/lib` so Python helpers resolve the bundled `libbpf`.

## Final Status

- Result JSON written to `micro/results/dev/arm64_t4g_micro_20260320.json`
- Report written to `docs/tmp/arm64_t4g_benchmark_20260320.md`
- No EC2 instances left running/stopped under this workflow
