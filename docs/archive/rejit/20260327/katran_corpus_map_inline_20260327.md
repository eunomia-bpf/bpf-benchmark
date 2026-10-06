# Katran Corpus Map Inline Report

日期：2026-03-27

## 结论

- `katran:balancer.bpf.o:balancer_ingress` 现在已经能在 live corpus 路径上真正触发 `map_inline`。
- `vm-corpus` 结果里能看到 `map_inline` 的命中统计：`sites_found=64`、`sites_applied=7`、`sites_skipped=57`。
- 这次 Katran 的剩余阻塞点不是 constant-key extraction，而是 `map_inline` 对一个非平凡 null-check 窗口过度删除了 lookup/null-check，导致 verifier 在 REJIT 后拒绝程序。
- 修复后，REJIT compile 成功，`balancer_ingress` 在 corpus 结果里记为 `applied=1`。

## 1. Katran 在 Corpus 中的状态

`corpus/build/katran/` 当前有以下 `.bpf.o`：

- `balancer.bpf.o`
- `healthchecking.bpf.o`
- `healthchecking_ipip.bpf.o`
- `xdp_pktcntr.bpf.o`
- `xdp_root.bpf.o`

`corpus/config/macro_corpus.yaml` 中，Katran balancer 的 corpus 条目是：

- `source: corpus/build/katran/balancer.bpf.o`
- `repo: katran`
- `prog_type: xdp`
- `section: xdp`
- `programs: [balancer_ingress]`
- `test_input: corpus/inputs/katran_vip_packet_64.bin`

所以 `balancer_ingress` 一直都在 corpus manifest 里，不是“未纳入 corpus”的问题。

## 2. Balancer Bytecode 与 Constant-Key Pattern

这次没有改 key extraction。Katran balancer 的 constant-key pattern 已经能被现有 `try_extract_constant_key()` 识别。

代表性 xlated 片段（来自 `docs/tmp/20260327/katran_original_xlated_1700_1785_20260327.txt`）：

```text
1756: (63) *(u32 *)(r10 -28) = r9
1757: (bf) r2 = r10
1758: (07) r2 += -28
1759: (18) r1 = map[id:15]
1761: (07) r1 += 304
1762: (61) r0 = *(u32 *)(r2 +0)
1763: (35) if r0 >= 0xfffffe goto pc+3
1764: (67) r0 <<= 3
1765: (0f) r0 += r1
1766: (05) goto pc+1
1767: (b7) r0 = 0
1768: (15) if r0 == 0x0 goto pc+58
1769: (61) r1 = *(u32 *)(r0 +0)
```

这个形状说明：

- key 先被物化到栈上：`*(u32 *)(r10 -28) = r9`
- `r2` 指向该栈 key：`r2 = r10; r2 += -28`
- map lookup 被 lowering 成 direct-value array access
- 随后存在显式 null-check：`if r0 == 0x0 goto ...`
- 非 null 路径里不仅有一个 fixed-offset load，还包含后续真实逻辑

Katran balancer 里这类站点很多。live 结果里，能确认被 `map_inline` 命中的 PC 有：

- `1059`
- `1248`
- `1354`
- `1636`
- `1764`
- `1952`
- `2267`

## 3. 为什么之前没有稳定 Fire

这轮调查确认了两个阶段性结论：

1. Katran 并不是“提取不出 constant key”。
2. 真正导致 live REJIT 失败的是 null-check 删除过头。

之前的 live log 已经表明 `map_inline` 实际在 Katran 上准备了 rewrite，但 REJIT 后 verifier 报：

- `BPF_CALL uses reserved fields`
- 以及随后定位出的 `R9 invalid mem access 'scalar'`

`BPF_CALL uses reserved fields` 是分支修复污染 helper-call `off` 字段造成的，之前已经在 `utils` 侧修掉。

剩余 Katran 特有失败来自 `PC=1764` 一类站点：

- `map_inline` 已经能识别 constant key
- 也能识别 fixed-offset load
- 但它把 lookup/null-check 连同一个并不“平凡”的非 null 窗口一起删除了
- 删除后 verifier 丢失了原来的 non-null 约束，后续路径中的寄存器状态退化成 scalar，最终被拒绝

所以 Katran 的最终 blocker 不是 key extraction，而是 null-check removal policy 太激进。

## 4. 本次代码修改

修改文件：

- `daemon/src/passes/map_inline.rs`

改动点：

1. 新增 `null_check_removal_window_is_trivial()`。
2. 新增 `is_trivially_safe_null_check_guarded_insn()`。
3. `build_site_rewrite()` 在决定是否删除 lookup/null-check 前，会检查 null-check 非 null 窗口是否只包含：
   - 即将被 `map_inline` 替换/删除的 PC
   - 或非常平凡的指令：`ja`、`exit`、普通 `ldimm64`、`mov imm`
4. 如果窗口里存在真实逻辑或副作用，则：
   - 仍然 inline fixed loads
   - 但保留原 lookup/null-check
   - 不再尝试整段删掉 lookup pattern

新增回归测试：

- `map_inline_pass_keeps_null_check_when_non_null_window_has_side_effects`

这条测试专门覆盖“可以 inline load，但不能删 null-check”的情况。

## 5. Katran Live Corpus 验证结果

运行命令：

```bash
python3 corpus/driver.py --profile ablation_map_inline --filter 'katran:balancer.bpf.o:balancer_ingress' --max-programs 1
```

结果目录：

- `corpus/results/corpus_vm_batch_20260327_141413/`

顶层结果：

- `mode=vm`
- `objects=1`
- `targets=1`
- `compile_pairs=1`
- `measured_pairs=0`
- `applied=1`

`details/result.json` 中 `map_inline` 的 pass 统计：

- `sites_found: 64`
- `sites_applied: 7`
- `sites_skipped: 57`

skip reason 分布：

- `lookup key is not a constant stack or pseudo-map-value materialization`: 24
- `lookup result has non-load uses`: 20
- `lookup result is not consumed by fixed-offset scalar loads`: 9
- `map type 12 not inlineable in v1`: 2
- `map type 13 not inlineable in v1`: 2

命中的诊断行：

- `site at PC=1059: inlined successfully, value=0x0`
- `site at PC=1248: inlined successfully, value=0x0`
- `site at PC=1354: inlined successfully, value=0x0`
- `site at PC=1636: inlined successfully, value=0x0`
- `site at PC=1764: inlined successfully, value=0x0`
- `site at PC=1952: inlined successfully, value=0x0`
- `site at PC=2267: inlined successfully, value=0x0`

compile 结果也说明 REJIT 这次确实成功应用：

- baseline JIT code size: `13645`
- REJIT JIT code size: `13584`
- code-size ratio: `1.004x`（baseline / rejit）
- `compile_passes_applied: map_inline, wide_mem, endian_fusion`

注意：

- 这次 `measured_pairs=0` 不是 REJIT 失败，而是 baseline/rejit run 阶段都遇到了 `bpf_prog_test_run_opts failed: Invalid argument`
- 也就是说 Katran balancer 的“运行测量”这次没拿到，但“REJIT compile + pass hit 统计”已经成功

## 6. 测试与构建验证

本次实际跑过：

- `cargo test --manifest-path daemon/Cargo.toml test_map_inline_real_katran_balancer_ingress -- --nocapture`
- `cargo test --manifest-path daemon/Cargo.toml map_inline`
- `make daemon-tests`
- `make daemon`

结果：

- `test_map_inline_real_katran_balancer_ingress` 通过，并显示 `applied 7 map_inline rewrite(s), skipped 57 site(s)`
- `cargo test ... map_inline` 通过：`64 passed`
- `make daemon-tests` 通过：`536 passed, 0 failed, 12 ignored`
- `make daemon` 通过

## 7. Corpus 中其他已确认命中的程序

这次没有新增一个“全 corpus 离线枚举器”；当前 `bpfrejit-daemon rewrite` CLI 也只接受 live `prog_id`，不再直接对 `.bpf.o` 做 `rewrite --debug`。因此这里列的是本次通过现有真实 fixture / smoke 验证到的、已经确认能命中的程序。

已确认命中：

| Program | 结果 |
| --- | --- |
| `katran/xdp_pktcntr.bpf.o:xdp` | `applied 1 map_inline rewrite(s), skipped 1 site(s)` |
| `katran/balancer.bpf.o:balancer_ingress` | `sites_found=64, sites_applied=7` |
| `tetragon/bpf_execve_event.bpf.o:execve_rate` | `applied 2 map_inline rewrite(s), skipped 11 site(s)` |
| `tetragon/bpf_execve_event.bpf.o:event_execve` | `applied 2 map_inline rewrite(s), skipped 19 site(s)` |
| `tetragon/bpf_fork.bpf.o:event_wake_up_new_task` | `applied 1 map_inline rewrite(s), skipped 15 site(s)` |

captured-fixture smoke 中也能看到对应真实程序发生变化：

- `bpf_execve_event.bpf.o:tracepoint/sys_execve changed=true applied=2`
- `bpf_execve_event.bpf.o:tracepoint changed=true applied=2`
- `bpf_fork.bpf.o:kprobe/wake_up_new_task changed=true applied=1`

对 `linux-selftests` 和 `libbpf-bootstrap`，这轮没有拿到同样粒度的离线命中列表；如果要补成 repo-wide 名单，建议下一步加一个直接读取 `.bpf.o` 并离线跑 `map_inline` 的小工具，而不是继续依赖当前只接受 live `prog_id` 的 `rewrite` CLI。

## 8. 最终判断

目标已完成：

- `map_inline` 在 Katran `balancer_ingress` 上真正 fire
- corpus 结果中能看到 hits
- verifier 不再因为这个 Katran site 回滚整个 REJIT

这次 Katran 验证给出的直接结论是：

- constant-key extraction 已经足够覆盖 balancer 的关键 array/direct-value pattern
- 真正需要收紧的是 null-check removal，而不是继续扩大 key-extraction pattern 集
