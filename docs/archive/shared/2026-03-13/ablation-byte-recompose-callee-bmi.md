# Ablation #57: byte-recompose / callee-saved / BMI

## Bottom Line

- 当前 characterization gap 使用 `docs/tmp/characterization-gap-decomposition.md` 的 strict geomean: **1.641x**。
- gap surplus 定义为 `gap - 1 = 0.641`。
- **byte-recompose 仍是主导项**：point estimate **50.7%** of surplus，约 **0.325** ratio-points。
- **callee-saved 在当前 `7.0-rc2` stock 上未测到可分辨贡献**：point estimate **0.0%**；但 **18.5%** 仍可作为 pre-v7 historical upper bound。
- **BMI/BMI2-only 增量贡献接近 0**：direct `llvmbpf-nobmi` spot checks give a clipped point estimate of **0.0%** of surplus.

结论（中文）:

- 如果问题是“当前 1.641x gap 里哪一项最该优先补”，答案仍然是 **byte-recompose**。
- 如果问题是“历史上 18.5% 的 callee-saved 现在还剩多少”，答案是 **当前 stock 基本已经把这块吃掉了，剩余贡献接近 0**。
- 如果问题是“BMI2 / 高级 bit-manip 指令本身是不是大头”，答案是 **不是；更像 low-single-digit 以内，甚至接近 0 的增量项**。

## Method

- `byte-recompose`: use the repo's already-published surplus share (`50.7%`) as the point estimate. This is the strongest available number because it comes from the earlier full native-code surplus decomposition, not from a single proxy benchmark.
- `callee-saved`: treat `18.5%` only as a historical upper bound, then constrain the current contribution with direct current-vs-allsave spot checks on four proxies. The current-stock point estimate is fixed at `0%`, and the spot checks are used only to verify that the historical gap is already gone.
- `BMI/BMI2`: use direct `llvmbpf` vs `llvmbpf-nobmi` measurements on three strict-suite proxies (`rotate64_hash`, `bitfield_extract`, `bitcount`) to estimate the incremental value of BMI-specific instruction selection. Then down-weight by a conservative coverage prior (`12/56`) based on documented rotate/bit-twiddle prevalence.
- This report intentionally separates **BMI-only** from the broader **rotate-fusion / bit-twiddle family**. A rotate win can come from collapsing `shr/shl/or` into `ror`, even when the BMI2-only choice (`rorx`) adds little.

## Factor Estimates

| Factor | Share of Surplus | Absolute Contribution | Confidence | Method | Notes |
| --- | --- | --- | --- | --- | --- |
| byte-recompose | 50.7% | 0.325 | High | Directly use the repository's published native-code surplus decomposition. | This is the strongest number in the repo and already agrees with the causal-isolation narrative. |
| callee-saved (current stock) | 0.0% | 0.000 | Medium-Low | Current-vs-allsave proxy on `simple`, `simple_packet`, `load_native_u64`, and `fibonacci_iter`; report how much of the old allsave gap has already been removed by current stock. | Current stock already includes `detect_reg_usage()`, so the live contribution is modeled as zero. Treat `18.5%` only as a historical upper bound for pre-v7 kernels. |
| BMI/BMI2-specific delta | 0.0% | 0.000 | Low | Direct `llvmbpf` vs `llvmbpf-nobmi` proxy on `rotate64_hash`, `bitfield_extract`, and `bitcount`, then multiplied by a conservative coverage prior (`12/56`). | Signed proxy estimate is -0.5% of suite surplus, so the reported contribution is clipped to zero. This suggests the incremental BMI-only choice (`rorx`/`bextr`/`blsr`) is not a first-order driver of the current 1.641x gap. |

## Proxy Gaps From Strict Characterization

| Benchmark | llvmbpf | kernel stock | Char gap |
| --- | --- | --- | --- |
| load_byte_recompose | 80 ns | 224.5 ns | 2.806x |
| simple | 12 ns | 37 ns | 3.083x |
| simple_packet | 12 ns | 34.5 ns | 2.875x |
| load_native_u64 | 80 ns | 112 ns | 1.400x |
| rotate64_hash | 40 ns | 105 ns | 2.625x |
| bitcount | 2.8 us | 4.5 us | 1.637x |
| checksum | 13.3 us | 17.7 us | 1.333x |

## Callee-Saved Proxies

| Benchmark | llvmbpf | current stock | allsave stock | Current char gap | Historical gap already removed |
| --- | --- | --- | --- | --- | --- |
| simple | 23 ns | 6 ns | 6 ns | 0.261x | 0.0% |
| simple_packet | 24.5 ns | 6 ns | 6 ns | 0.245x | 0.0% |
| load_native_u64 | 94.5 ns | 92 ns | 93.5 ns | 0.974x | 0.0% |
| fibonacci_iter | 864 ns | 893.5 ns | 985.5 ns | 1.034x | 75.7% |

Callee reading: only `fibonacci_iter` still has a visible current gap among these proxies, but the `allsave` kernel is substantially slower than current stock. That means the old fixed-save overhead was real, yet it has already been removed from today's stock baseline rather than remaining inside today's 1.641x gap.

## BMI/BMI2 Proxies

| Benchmark | llvmbpf | llvmbpf-nobmi | Strict char gap | nobmi delta vs llvmbpf | Proxy-local share |
| --- | --- | --- | --- | --- | --- |
| rotate64_hash | 55.5 ns | 52.5 ns | 2.625x | -5.4% | -3.3% |
| bitfield_extract | 231 ns | 250.5 ns | 1.385x | +8.4% | 21.9% |
| bitcount | 4.7 us | 4.3 us | 1.637x | -9.4% | -14.8% |

BMI reading: `bitfield_extract` still benefits from BMI-style lowering, but `rotate64_hash` and `bitcount` do not show a positive BMI-only delta in the current spot checks. So the **incremental** benefit of BMI-specific instruction choice is not stable enough to claim a large suite-level share.

Auxiliary cross-check outside the original 56-benchmark strict suite:

- `rotate_dense`: `llvmbpf=163 ns`, `llvmbpf-nobmi=164 ns`. This newly added pure rotate-isolation benchmark is essentially invariant to BMI disablement, which matches the near-zero suite-level estimate.

## Broader Rotate-Fusion Note

- Do not over-read the near-zero BMI-only estimate as “rotate does not matter.” It only says `rorx` / `bextr` / `blsr` over non-BMI alternatives is not a dominant incremental source.
- The broader rotate-fusion family still matters locally. In the per-family ablation, `rotate64_hash` improves from `96 ns` to `69 ns` under `rotate`-only recompile, and `packet_rss_hash` improves from `30 ns` to `25 ns`. Those are real backend wins; they just should not all be attributed to BMI2-only forms.

## Post-Fix 62-Bench Sanity Check

| Benchmark | post-fix stock | post-fix recompile | stock/recompile |
| --- | --- | --- | --- |
| bitcount | 4.8 us | 4.5 us | 1.065x |
| checksum | 19.4 us | 17.7 us | 1.093x |
| load_byte_recompose | 184.5 ns | 222 ns | 0.831x |
| rotate64_hash | 56 ns | 69.5 ns | 0.806x |
| simple | 8 ns | 8 ns | 1.000x |
| simple_packet | 7.5 ns | 7.5 ns | 1.000x |

This sanity check matches the decomposition story:

- `load_byte_recompose` is still unrecovered in the latest post-fix run.
- `simple` / `simple_packet` remain ties, which is exactly what we expect if callee-saved overhead is no longer a major open gap in current stock.
- `bitcount` and `checksum` move only slightly, which is consistent with BMI/bit-twiddle being a second-order effect rather than a dominant suite-wide driver.

## Interpretation

- **High confidence**: byte-recompose is still the largest single contributor and should keep P1 priority.
- **Medium-low confidence, but directionally clear**: callee-saved was historically important, but current stock already upstreamed the relevant optimization, so it should no longer be modeled as an 18.5% live component of today's gap.
- **Low confidence, but consistent across mixed evidence**: BMI/BMI2 is best treated as a small incremental effect inside a larger rotate/bit-twiddle bucket, not as a primary explanation of the current characterization gap.