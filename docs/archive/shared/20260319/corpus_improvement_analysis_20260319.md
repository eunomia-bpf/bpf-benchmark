# Corpus Improvement Analysis (2026-03-19)

输入：

- Full rerun: `corpus/results/dev/vm_corpus.json`
- Old authority: `corpus/results/corpus_recompile_authoritative_20260313.json`
- Prior refreshed-policy rerun context: `docs/tmp/corpus_rerun_20260318.md`, `docs/tmp/sequential_rerun_round2_20260318.md`
- Targeted validation:
  - `docs/tmp/corpus_tunnel_subset_current_20260319.json`
  - `docs/tmp/corpus_tunnel_subset_skip_cmov_only_20260319.json`
  - `docs/tmp/corpus_calico_regressor_subset_current_20260319.json`
  - `docs/tmp/corpus_calico_regressor_subset_stock_20260319.json`

## 1. Full rerun result

Kernel:

- guest kernel release: `7.0.0-rc2-g8c70a729d22e`
- top commit: `8c70a729d Revert "bpf: reject recompile for trampoline-attached programs"`

Command:

```bash
source /home/yunwei37/workspace/.venv/bin/activate
make vm-corpus REPEAT=200
```

Topline:

- measured pairs: `152`
- recompiled programs: `61`
- applied programs: `61`
- overall exec geomean: `0.899971x`
- old authoritative: `1.046336x`
- vs old authoritative: `-14.0%` multiplicative (`0.8601x` of the old topline)
- applied-only geomean: `1.022548x`
- non-applied geomean: `0.826143x`

Interpretation:

- The recompile-sensitive subset is still net positive.
- The overall loss is dominated by the non-applied/no-op population, not by the applied population.

## 2. By source

| Source | Pairs | Recompiled | Applied | Exec geomean |
| --- | ---: | ---: | ---: | ---: |
| `calico` | 59 | 46 | 46 | `1.02337x` |
| `katran` | 5 | 2 | 2 | `0.75876x` |
| `libbpf-bootstrap` | 1 | 1 | 1 | `0.96825x` |
| `linux-selftests` | 59 | 4 | 4 | `0.70757x` |
| `real_world_code_size` | 1 | 1 | 1 | `0.96124x` |
| `suricata` | 1 | 0 | 0 | `0.97143x` |
| `tracee` | 2 | 2 | 2 | `1.05981x` |
| `xdp-tools` | 4 | 1 | 1 | `1.00475x` |
| `xdp-tutorial` | 20 | 4 | 4 | `1.24438x` |

重点：

- `linux-selftests` 仍然是主要拖后腿 source。
- `katran` 本轮再次回归，不是稳定的正向 source。
- `calico` 仍是正向 source，且 applied rows 比较多。

## 3. Applied / non-applied split

当前 full rerun 最重要的分裂不是 source，而是 applied vs non-applied：

- applied geomean: `1.02255x`
- non-applied geomean: `0.82614x`

再看时间尺度：

- baseline `<=20ns` 的 rows: `79/152`
- baseline `<=20ns` 且 non-applied: `70/152`
- baseline `<=20ns` 且 regressor: `41`

这些 worst rows 大量呈现整数比：

- `3ns -> 9ns`
- `4ns -> 12ns`
- `5ns -> 13ns`
- `9ns -> 23ns`
- `13ns -> 34ns`

这更像极短 steady-state path 上的 `ktime` 量化噪声，而不是 policy 把程序真实变慢了 `2-3x`。

定量看这个现象的影响：

- full suite 原始 geomean: `0.89997x`
- 如果只排除 non-applied 且 baseline `<=10ns` 的 rows，geomean 变成 `1.02927x`
- 如果排除 non-applied 且 baseline `<=20ns` 的 rows，geomean 变成 `1.01110x`

结论：

- 当前 topline 已经被 ultra-short non-applied rows 主导。
- 在这个状态下继续做小 policy sweep，不足以稳定拉回旧 authoritative `1.046x`。

## 4. Winners / losers

Top losers：

| Ratio | Source | Program | Notes |
| ---: | --- | --- | --- |
| `0.09375x` | `calico` | `calico_xdp_norm_pol_tail` | no policy, `3ns -> 32ns` |
| `0.23077x` | `linux-selftests` | `prepare/program` | no policy, `3ns -> 13ns` |
| `0.33333x` | `katran` | `healthchecking_ipip/healthcheck_encap` | no policy, branch-flip-only, `4ns -> 12ns` |
| `0.33333x` | `linux-selftests` | `pkt_ptr` | empty CMOV-only policy, `3ns -> 9ns` |
| `0.33333x` | `linux-selftests` | `get_netns_cookie_tcx` | no policy, `4ns -> 12ns` |
| `0.33333x` | `linux-selftests` | `main_does_not_change` | no policy, `3ns -> 9ns` |
| `0.33333x` | `linux-selftests` | `tcx5` | no policy, `4ns -> 12ns` |

Top winners：

| Ratio | Source | Program | Notes |
| ---: | --- | --- | --- |
| `3.66667x` | `xdp-tutorial` | `tracing01/xdp_drop_func` | no policy |
| `3.50000x` | `xdp-tutorial` | `packet02/xdp_port_rewrite_func` | no policy |
| `3.25000x` | `linux-selftests` | `xdp_redirect_to_222` | no policy |
| `3.09000x` | `calico` | `xdp_debug/calico_xdp_accepted_entrypoint` | no policy |
| `3.00000x` | `calico` | `xdp_no_log/calico_xdp_accepted_entrypoint` | no policy |

结论：

- 两端尾部都被 no-op / no-policy 的短程序强烈污染。
- 这进一步支持“整体问题主要不是 policy family 选错了，而是测量在 short no-op rows 上不稳”。

## 5. Family view

`summary.by_family`：

| Family | Programs | Applied | Exec geomean | Notes |
| --- | ---: | ---: | ---: | --- |
| `wide` | 35 | 32 | `1.01499x` | 净正向 |
| `endian` | 64 | 58 | `1.00548x` | 基本中性略正 |
| `rotate` | 4 | 1 | `0.96098x` | 样本少，不稳定 |
| `cmov` | 75 | 0 | `0.95478x` | 当前全部 skip |
| `extract` | 33 | 0 | `0.96374x` | 当前全部 skip |
| `branch-flip` | 76 | 0 | `1.05291x` | 当前全部 skip，结果主要是 no-op 噪声 |

结论：

- 现有 positive families 仍然是 `wide` 和 `endian`。
- `cmov` 没有证据值得全局放开。
- `extract` 没有证据值得全局放开。

## 6. Trampoline coverage

这套 corpus rerun 里根本没有 trampoline 类型程序：

- `prog_type_name` 只有 `sched_cls=106`, `xdp=41`, `cgroup_skb=5`
- `trampoline_candidates = 0`
- 没有 `fentry/fexit/lsm/tracing/kprobe/tracepoint` rows

所以针对“reverted kernel 现在能不能 recompile trampoline programs”这个问题，本次 corpus benchmark **不能回答**。

能回答的只有：

- reverted kernel 成功跑完整套 corpus
- 但 corpus 本身没有覆盖 trampoline attach 类型

## 7. Stale policy status

本轮不是早先那种“大量 stale policy 完全 miss”状态，但也不是完全干净：

- `policy selected 0 of N`: `36` rows
- `policy_path` 存在但 `v5_run_applied=false`: `36` rows
- `was not found in the live program`: `13` rows

这 36 个 no-apply rows 的主体不是 stale miss，而是“当前 policy 本来就是空 allowlist”：

- `pkt_ptr` 等 CMOV-only rows
- `__encap_*` extract-only rows
- 一些 current policy 明确 skip 掉的 rows

但 `13` 条 stale-miss warning 说明 live-xlated refresh 仍不完全稳定。它们主要出现在：

- `calico`
- `tracee`

这些 warning 大多没有直接造成强回归，但说明当前 `remap_policy_v3_to_live()` 的 family+pattern_kind 顺序 remap 仍然会漂。

## 8. Katran and linux-selftests

### 8.1 Katran

`katran = 0.75876x`

明细：

- `healthchecking_ipip/healthcheck_encap`: `0.33333x`, no policy, branch-flip-only, `4ns -> 12ns`
- `pktcntr`: `0.75000x`, no policy, branch-flip-only, `30ns -> 40ns`
- `balancer_ingress`: `0.88525x`, applied `wide+endian`, `54ns -> 61ns`
- `xdp_root`: `0.90909x`, no policy, `10ns -> 11ns`
- `healthchecking/healthcheck_encap`: `1.25000x`, applied `endian`, `5ns -> 4ns`

判断：

- `katran` 本轮回归不是 stale `balancer_ingress` 那种老问题。
- 它主要被两条 no-policy short rows 拖下去，尤其是 `healthchecking_ipip`.
- 这类 row 当前没有足够证据支持“加 branch-flip policy 就会稳定改善”。

### 8.2 Linux-selftests

`linux-selftests = 0.70757x`

只有 `4` 个 program 被 recompile/applied；source collapse 主要来自大量 short no-op rows：

- `prepare/program`: `3ns -> 13ns`
- `pkt_ptr`: `3ns -> 9ns`
- `get_netns_cookie_tcx`: `4ns -> 12ns`
- `main_does_not_change`: `3ns -> 9ns`
- `tcx5`: `4ns -> 12ns`
- `tcx3`: `13ns -> 34ns`
- `test_pkt_access`: `9ns -> 23ns`, `13ns -> 33ns`, `22ns -> 56ns`

判断：

- `linux-selftests` 继续是整体最主要瓶颈。
- 根因不是“apply 之后明显变差”，而是“绝大部分根本没 apply，但 paired measurement 自己在漂”。

## 9. Targeted validation

### 9.1 `extract` 回补实验

目的：

- 验证当前 `--skip-families cmov,extract` 是否过头
- 对象：`test_tc_tunnel.bpf.o` 中最相关的 `6` 条

Current policy subset:

- file: `docs/tmp/corpus_tunnel_subset_current_20260319.json`
- overall: `0.69193x`
- applied: `0`

Candidate subset:

- generated temp policies under `/tmp/corpus-policy-skip-cmov-only-20260319`
- 只 skip `cmov`，允许 `extract`
- file: `docs/tmp/corpus_tunnel_subset_skip_cmov_only_20260319.json`
- overall: `0.74828x`
- applied: `5`

逐条：

| Program | Current | Skip-cmov-only |
| --- | ---: | ---: |
| `__encap_ip6gre_none` | `0.333x` | `0.800x` |
| `__encap_ip6tnl_none` | `0.444x` | `0.600x` |
| `__encap_ip6udp_none` | `1.000x` | `0.800x` |
| `__encap_ip6vxlan_eth` | `1.667x` | `0.800x` |
| `__encap_sit_none` | `0.444x` | `0.800x` |
| `decap_f` | `1.000x` | `0.714x` |

关键结论：

- extract 回补后，subset geomean 从 `0.692x` 到 `0.748x`，只是把极端 no-op 噪声拉近了一点。
- 但绝对性能上，`extract` applied rows 是 `5/5 regressions`，extract family geomean 只有 `0.755x`。
- `decap_f` 没有出现可支持的正向证据。

结论：

- **不建议取消全局 `extract` skip。**
- 如果未来要动 extract，只能做更高 repeat 的 per-program case study，不能直接放回 checked-in default policy。

### 9.2 `calico` negative-looking rows stock 对照

对象：

- `from_nat_debug/calico_tc_main`
- `to_hep_debug/calico_tc_host_ct_conflict`
- `xdp_debug/calico_xdp_main`

Current policy subset:

- file: `docs/tmp/corpus_calico_regressor_subset_current_20260319.json`
- overall: `1.01070x`
- applied: `3`

Forced-stock subset:

- file: `docs/tmp/corpus_calico_regressor_subset_stock_20260319.json`
- overall: `0.86023x`
- applied: `0`

逐条：

| Program | Current policy | Forced stock |
| --- | ---: | ---: |
| `from_nat_debug/calico_tc_main` | `0.952x` | `0.995x` |
| `to_hep_debug/calico_tc_host_ct_conflict` | `1.038x` | `0.748x` |
| `xdp_debug/calico_xdp_main` | `1.045x` | `0.855x` |

结论：

- 这批 current live-remapped `wide+endian` policy 总体优于 stock。
- `from_nat_debug/calico_tc_main` 单条接近中性，确实略偏负，但不是足以支持直接清 policy 的程度。
- **不建议清掉这些 checked-in calico policies。**

## 10. What should change

### 10.1 不建议现在就改的东西

- 不建议把 global skip 从 `cmov,extract` 改成只 skip `cmov`
- 不建议清掉本轮验证过的 `calico` live-remapped policies
- 不建议为了 `katran` 的 short branch-flip-only rows 盲加 branch-flip policy

### 10.2 应该优先做的改进

1. benchmark-side stabilization for ultra-short non-applied rows
   - 当前最大瓶颈不是 applied policy，而是 baseline `<=20ns` 的 no-op rows
   - 建议对这类 rows 做 adaptive repeat，至少把 total measured steady-state time 拉到更高量级
   - 或者对这类 rows 做多次 rerun 取中位数，而不是单次 pair

2. separate topline reporting
   - 保留 full suite geomean
   - 但新增一个“non-applied and baseline<=20ns filtered” topline
   - 当前这个 filtered topline 已经在 `1.01x-1.03x` 区间，信息量比原始 `0.90x` 更高

3. stabilize live policy remap
   - 当前 `13` 条 stale-miss warning 说明 family+pattern_kind 顺序 remap 仍会漂
   - 建议后续 user-space fix 用更稳定的 site identity，而不是继续靠 family-order remap
   - 这是中期方向，不是当前这轮 rerun 的 immediate unblocker

### 10.3 低优先级 policy candidates

当前只把这些列为低优先级后续候选，不建议直接改 checked-in default：

- `linux-selftests/cls_ingress`
- `katran/healthchecking_ipip/healthcheck_encap`
- `katran/pktcntr`

理由：

- 它们要么太短、噪声太大
- 要么是 branch-flip-only
- 要么当前没有任何稳定的正向验证

## 11. Final recommendation

这轮不修改 `corpus/policies/` checked-in YAML。

原因：

- extract 回补没有给出足够强的正向证据
- 已验证的 calico negative-looking rows 在 isolated rerun 中反而是 current policy 优于 stock
- 当前 overall loss 的主因不是少数可修 policy regressors，而是大量 ultra-short non-applied rows 的测量不稳定

如果下一轮要继续投入，最值得做的是：

1. 在 user-space benchmark driver 中给 non-applied short rows 加 repeat stabilization
2. 再用同一 kernel / 同一 policy 做至少一轮 full rerun
3. 只有在 short-row 噪声收敛之后，再重新评估是否值得动 corpus default policy
