# Katran Map Inline Performance Results

日期：2026-03-27

## 结论

- Katran `balancer_ingress` 的 corpus/runtime 路径已经在修复后的 `runner` 上成功拿到真实运行时样本。
- 在只启用 `map_inline + const_prop + dce` 的请求级 pass 控制下，这个定向 case 实际只有 `map_inline` 命中；`const_prop` 和 `dce` 都没有 fire。
- 该定向 corpus 结果显示：
  - baseline `exec_ns = 14`
  - rejit `exec_ns = 7`
  - `speedup_ratio = 2.000x`
- 代码尺寸收益较小，但运行时样本显示明显改善：
  - JIT size `13645 -> 13632`（约 `-0.095%`）
  - xlated size `23872 -> 23872`（无变化）

## 运行方式

使用仓库标准入口：

```bash
make vm-corpus TARGET=x86 PROFILE=ablation_map_inline_full \
  FILTERS='katran:balancer.bpf.o:balancer_ingress'
```

关键配置：

- benchmark profile: `ablation_map_inline_full`
- active passes: `map_inline`, `const_prop`, `dce`
- filter: `katran:balancer.bpf.o:balancer_ingress`
- corpus input: `corpus/inputs/katran_vip_packet_64.bin`

结果目录：

- `runner/corpus/results/vm_corpus_20260327_152626/`

## 结果摘要

来自 `runner/corpus/results/vm_corpus_20260327_152626/details/result.json`：

- `compile_pairs = 1`
- `measured_pairs = 1`
- `applied = 1`
- `compile_passes_applied = ['map_inline']`
- `run_passes_applied = ['map_inline']`

单程序结果：

- program: `katran:balancer.bpf.o:balancer_ingress`
- baseline JIT bytes: `13645`
- rejit JIT bytes: `13632`
- code ratio: `1.0009536384976525x`
- baseline exec_ns: `14`
- rejit exec_ns: `7`
- exec ratio: `2.0x`
- baseline retval: `2`
- rejit retval: `2`

## Pass 细节

`map_inline`：

- `sites_found = 64`
- `sites_applied = 7`
- `sites_skipped = 57`

命中 site：

- `PC=1059`
- `PC=1248`
- `PC=1354`
- `PC=1636`
- `PC=1764`
- `PC=1952`
- `PC=2267`

主要 skip reason：

- `lookup key is not a constant stack or pseudo-map-value materialization`: 24
- `lookup result has non-load uses`: 20
- `lookup result is not consumed by fixed-offset scalar loads`: 9
- `map type 12 not inlineable in v1`: 2
- `map type 13 not inlineable in v1`: 2

`const_prop`：

- `sites_applied = 0`

`dce`：

- `sites_applied = 0`

## 与此前结果对比

相比之前 Katran live e2e 的两次真值：

- `e2e/results/katran_e2e_live_20260327_065733_20260327_135738/`
- `e2e/results/katran_live_20260327_070135_20260327_140143/`

这次定向 corpus 的关键变化是：

1. pass 控制已经完全收口到 request-level，只跑 `map_inline + const_prop + dce`。
2. 旧的 `prepared-run` 复用 compile-only `context` 输入导致的 `EINVAL` 已修掉，所以现在能正常拿到 runtime。
3. 这次没有混入 `wide_mem` / `endian_fusion`，因此 `2.0x` 提升可以直接归因于 `map_inline`。

## 当前判断

- Katran 至少在 corpus 的定向热路径上，`map_inline` 已经能产生明显运行时收益。
- 但这 7 个命中目前仍主要是“值为 0 的 inline 站点”，`const_prop`/`dce` 还没有接上，所以这还不是 Katran 的收益上限。
- 下一步最值得继续做的是：
  - 扩 `map_inline` 的 constant-key fallback，吃掉那 24 个 key-extraction miss
  - 放宽 use-classifier，减少 20 个 `non-load uses` skip
  - 继续打通 live e2e 的 request-level serve 路径，拿到和 corpus 一致的 live runtime
