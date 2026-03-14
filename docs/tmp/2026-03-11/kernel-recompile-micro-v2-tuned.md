# Kernel Recompile Micro v2 Tuned Policy Rerun

## Methodology

- Suite: `config/micro_pure_jit.yaml` 中 `56` 个 micro benchmarks
- Runtime: `kernel` vs `kernel-recompile`
- Warmups / iterations / repeat: `2 / 10 / 500`
- Guest: framework-kernel VM (`vendor/linux-framework/arch/x86/boot/bzImage`, `4G`, `2` vCPU)
- Authoritative rerun command:

```bash
python3 docs/tmp/kernel_recompile_micro_resume.py \
  --iterations 10 \
  --warmups 2 \
  --repeat 500 \
  --cpu 0 \
  --memory 4G \
  --cpus 2 \
  --output-json micro/results/kernel_recompile_v2_tuned_20260312.json \
  --output-md docs/tmp/kernel-recompile-micro-v2-tuned.md \
  --per-bench-dir docs/tmp/kernel_recompile_v2_tuned_per_bench
```

- 说明：这次 authoritative rerun 没有直接把整套 `micro/run_micro.py` 放进单个 guest 里跑；那个路径在长跑时不稳定，可能留下不完整 JSON。最终使用 host-controlled `kernel_recompile_micro_resume.py`，每个 benchmark 独立起 VM，结果更稳。

## Headline Numbers

| Metric | Blind all-apply (#118) | v2 tuned rerun | Delta / interpretation |
| --- | ---: | ---: | --- |
| Valid / invalid pairs | `50 / 6` | `54 / 2` | 恢复了 `4` 个 `result-mismatch`；剩余 invalid 仅 `bounds_ladder`、`mixed_alu_mem` 两个 VM crash |
| Applied pairs | `45` | `33` | tuned 故意把一批回归 case fail-close 成 no-op |
| Overall geomean (stock / recompile) | `1.028x` | `1.027x` | overall 基本持平；原因是 tuned 把 4 个原本 invalid 的 benchmark 重新计入统计 |
| Applied-only geomean | `1.024x` | `1.040x` | 已应用 policy 的质量明显变好 |
| Wins / losses / ties | `31 / 17 / 2` | `28 / 18 / 8` | tuned 的 no-op rows 更多，hard failure 更少 |

- 同一批 `50` 个 blind/tuned 都有效的 benchmark 上，geomean 从 `1.028x` 提到 `1.029x`。
- 在这 `50` 个共同有效 benchmark 上，直接比较 recompile 中位数，`blind_recompile / tuned_recompile` 的 geomean 是 `1.032x`。
- 在使用 tuned policy file 且 blind/tuned 都有效的 `16` 个 benchmark 上，`blind_recompile / tuned_recompile` 的 geomean 是 `1.070x`。

## Blind Regression Inventory

- CMOV-sensitive regressors / mismatches:
  - `cmov_dense`：blind 有 `32` 个 `cmov` sites，`0.612x`；tuned 改成 rotate-only。
  - `binary_search`：blind `result-mismatch`，sites 为 `cmov=1, wide=2`；tuned fail-close disable。
  - `switch_dispatch`：blind `result-mismatch`，sites 为 `cmov=1, wide=2`；tuned fail-close disable。
  - `branch_dense`：blind `result-mismatch`，sites 为 `cmov=1, wide=2, branch-flip=4`；tuned fail-close disable。
  - `bpf_call_chain`：blind `result-mismatch`，sites 为 `cmov=1, wide=2`；tuned 保留 wide-only。
- Blind 中由 WIDE 主导的 regressors，tuned 全部改为 `sites: []`：
  - `memory_pair_sum`
  - `bitcount`
  - `dep_chain_long`
  - `checksum`
  - `load_byte`
  - `load_byte_recompose`
  - `packet_parse`
  - `fibonacci_iter`
  - `nested_loop_2`
  - `nested_loop_3`
  - `smallmul_strength_reduce`
  - `tc_bitcount`
- Mixed-family regressors，按 probe 结果定向保留：
  - `large_mixed_500`：`wide=1, rotate=7, branch-flip=3`，最终只保留 `branch-flip`
  - `memcmp_prefix_64`：`wide=1, rotate=3`，最终只保留 `rotate`
  - `branch_fanout_32`：`wide=1, rotate=8`，probe 显示 rotate-only 甚至会 `EINVAL`，因此最终 disable
- 非 policy-actionable 的 blind 回归：
  - `struct_field_cluster`：blind 行本身就是 `0` sites / no-op regression，没有可调 family，所以没有新增 policy 文件。
- 仍未解决的非 policy 问题：
  - `bounds_ladder`
  - `mixed_alu_mem`

## Per-Benchmark Improvements

### Direct blind vs tuned wins on tuned-policy benchmarks

| Benchmark | Blind recompile median | Tuned recompile median | Blind/Tuned | Tuned stock/recompile | Action |
| --- | ---: | ---: | ---: | ---: | --- |
| `cmov_dense` | `73.5 ns` | `49.0 ns` | `1.500x` | `0.969x` | rotate-only |
| `packet_parse` | `151.5 ns` | `109.5 ns` | `1.384x` | `0.941x` | disable wide-only policy |
| `memcmp_prefix_64` | `148.0 ns` | `107.0 ns` | `1.383x` | `1.000x` | rotate-only |
| `memory_pair_sum` | `13.0 ns` | `9.5 ns` | `1.368x` | `1.000x` | disable wide-only policy |
| `load_byte_recompose` | `236.0 ns` | `216.0 ns` | `1.093x` | `1.123x` | disable wide-only policy |
| `large_mixed_500` | `704.0 ns` | `666.5 ns` | `1.056x` | `0.997x` | branch-flip-only |

### Recovered invalids

| Benchmark | Blind status | Tuned status | Tuned stock/recompile | Tuned action |
| --- | --- | --- | ---: | --- |
| `binary_search` | `result-mismatch` | `ok` | `1.068x` | disable |
| `switch_dispatch` | `result-mismatch` | `ok` | `0.980x` | disable |
| `branch_dense` | `result-mismatch` | `ok` | `0.988x` | disable |
| `bpf_call_chain` | `result-mismatch` | `ok` | `1.005x` | wide-only |

- 这四个 benchmark 的 tuned 价值首先是“恢复可测量性”；它们不全都变成 win，但至少从 blind 的 hard invalid 变成了可解释结果。
- `struct_field_cluster` 在 tuned run 里从 blind 的 `0.924x` 变成 `1.368x`，但它两边都是 `0` sites/no-op；这个变化不应当被当成 policy 效果，而更像 run-to-run 噪声。

## Policy-Sensitivity Evidence

- `cmov_dense`：`docs/tmp/kernel-recompile-per-family-ablation.md` 里，cmov-only 只有 `0.975x`，rotate-only 是 `1.200x`；blind all-apply 把 `32` 个 CMOV sites 一起打开后跌到 `0.612x`。这就是最直接的 per-site family sensitivity 证据。
- `binary_search`、`switch_dispatch`、`branch_dense`：per-family ablation 都复现了同一个现象，`cmov` 单独打开就会 `result-mismatch`。因此 tuned 先把 `cmov` 视为 culprit；对 `binary_search`/`branch_dense`，后续 strict 检查并没有给出足够强的“保留 wide 仍值得”的证据，所以最终 fail-close。
- `bpf_call_chain`：targeted family probe 显示 `cmov` 单独打开会 `result-mismatch`，但 `wide` 单独打开仍可跑完，约 `0.886x`。因此 tuned 保留 wide-only，full rerun 最终回到 `1.005x` 且不再 mismatch。
- `memcmp_prefix_64`：targeted probe 里，blind all-apply 是 `148 ns`，wide-only 是 `124 ns`，rotate-only 是 `112 ns`。最终 tuned 只保留 rotate，authoritative rerun 到了 `107 ns`。
- `large_mixed_500`：targeted probe 里，blind all-apply 是 `704 ns`，wide-only `732 ns`，rotate-only `625 ns`，branch-flip-only `596 ns`。因此 tuned 最终只保留 `branch-flip`，full rerun 改善到 `666.5 ns`。
- `branch_fanout_32`：targeted probe 里，rotate-only 直接报 `BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22)`，wide-only 也只有 `542 ns`，明显差于 blind 的 `398.5 ns`。这个 benchmark 没有可安全保留的 family，于是 tuned 直接 disable。

## Takeaways

- 如果只看整个 `56` benchmark aggregate，tuned 没有把 overall geomean 从 `1.028x` 继续抬高；根因不是 tuned 没起作用，而是它把 `4` 个 blind invalid 恢复成了可统计样本，其中有些只是“可测但不快”。
- 如果看更合适的口径，tuned 是明确有收益的：共同有效集合 `1.028x -> 1.029x`，applied-only `1.024x -> 1.040x`，invalid `6 -> 2`，tuned-policy benchmark 直接 blind/tuned 对比 `1.070x`。
- 当前剩余空间主要有两类：一类是 `bounds_ladder` / `mixed_alu_mem` 这种 VM-crash 级别问题；另一类是大批 wide-only regressors，目前最稳妥的做法仍然是 fail-close skip，而不是继续盲目应用。
