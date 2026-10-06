# map_inline 在真实 VM run 中零命中的根因分析（2026-03-26）

## 结论摘要

先给结论：

1. **当前代码里已经没有 `frozen/immutable` gating。**
   - `daemon/src/analysis/map_info.rs:61-63` 的 `is_inlineable_v1()` 只看 `supports_direct_value_access()`。
   - `MapInfo.frozen` 仍会被采集（`daemon/src/analysis/map_info.rs:30-33`, `daemon/src/analysis/map_info.rs:183-192`），但 `map_inline` 已不再用它做 skip 条件。

2. **当前代码里也没有 “值全零就不 inline” 的逻辑。**
   - `daemon/src/passes/map_inline.rs:420-449` 读到 map value 后，直接把固定偏移 load 改写成常量 load。
   - `daemon/src/passes/map_inline.rs:510-516` 的 `emit_constant_load()` 对 `0` 也会正常发出 `mov64_imm(..., 0)`，没有零值特判。

3. **`map_info` 只负责读 live map metadata，不负责读 map value。**
   - metadata 读取：`daemon/src/analysis/map_info.rs:183-192`
   - 真正读 value 的地方在 pass 内：`daemon/src/passes/map_inline.rs:420-421`
   - syscall wrapper：`daemon/src/bpf.rs:576-597`

4. **`supports_direct_value_access()` 允许的 map type 不是只有 ARRAY，而是：ARRAY / HASH / LRU_HASH。**
   - 代码：`daemon/src/analysis/map_info.rs:48-53`
   - 明确排除了 `PERCPU_HASH / PERCPU_ARRAY / LRU_PERCPU_HASH`。

5. **真实 VM run 零命中的主因不是 zero value，也不是权限问题，而是 `extract_constant_key()` 对真实 clang 产出的 lookup pattern 识别错误。**
   - `MapInlinePass::run()` 对每个 site 都会调用 `extract_constant_key()`：`daemon/src/passes/map_inline.rs:182-188`
   - `extract_constant_key()` 继续调用 `find_r2_stack_pointer_setup()`：`daemon/src/passes/map_inline.rs:84-98`, `daemon/src/passes/map_inline.rs:562-576`
   - 这里假设 `r2 = fp; r2 += off` 是 helper call 前两个“紧邻”的 real insn。
   - 但真实 clang 产物通常是：
     - `stack store key`
     - `r2 = fp`
     - `r2 += -4`
     - `LD_IMM64 r1 = map`
     - `call bpf_map_lookup_elem`
   - 也就是说，**`LD_IMM64 map load` 插在了 `r2` key setup 和 helper call 之间**。
   - 结果：源码层面明明是“常量栈 key”，pass 仍误报 `"lookup key is not a constant stack materialization"`。

6. **已存在的真实 VM probe 直接支持这个判断。**
   - `docs/tmp/20260326/probe_outputs/pktcntr_zero.stderr`
   - `docs/tmp/20260326/probe_outputs/pktcntr_one.stderr`
   - 两次 probe 把 Katran `ctl_array[0]` 分别设成 `0` 和 `1`，`map_inline` 的 skip reasons 完全一样：
     - `"lookup key is not a constant stack materialization"`
     - `"map type 6 not inlineable in v1"`
   - 这说明它在**读 value 之前**就已经被模式匹配卡住了，map 是零还是非零不影响结果。

## 代码路径

真实 apply 路径是：

1. `try_apply_one()`
   - `daemon/src/commands.rs:682-919`
2. `PassManager::run_with_profiling()` / `run()`
   - `daemon/src/pass.rs:645-745`
3. `MapInlinePass::run()`
   - `daemon/src/passes/map_inline.rs:148-407`
4. 对每个候选 site：
   - 查 `MapInfoAnalysis`：`daemon/src/passes/map_inline.rs:159-180`
   - 提取常量 key：`daemon/src/passes/map_inline.rs:182-188`
   - 分类 `r0` uses：`daemon/src/passes/map_inline.rs:218-232`
   - 真正读 live map value：`daemon/src/passes/map_inline.rs:234-250`, `daemon/src/passes/map_inline.rs:420-421`

关键点：

- **只有通过前面的结构匹配后，才会走到 live map read。**
- 所以前面的 pattern bug 会让 pass 在真实程序里“完全读不到 value”，外面看起来就像“zero hit”。

## Step 1：`map_inline` 现在到底会因为什么 skip

### 1.1 显式 skip 条件

以下都是 `MapInlinePass::run()` 明确记录到 `sites_skipped` 的条件：

1. `map reference metadata unavailable`
   - `daemon/src/passes/map_inline.rs:160-166`
2. `map info unavailable`
   - `daemon/src/passes/map_inline.rs:167-173`
3. `map type {N} not inlineable in v1`
   - `daemon/src/passes/map_inline.rs:174-180`
4. `lookup key is not a constant stack materialization`
   - `daemon/src/passes/map_inline.rs:182-188`
5. `key width X does not match map key size Y`
   - `daemon/src/passes/map_inline.rs:189-198`
6. `constant key K out of range for max_entries M`
   - 仅 ARRAY 删除 lookup pattern 时检查
   - `daemon/src/passes/map_inline.rs:199-208`
7. `speculative map inline requires an immediate null check`
   - 仅 HASH / LRU_HASH
   - `daemon/src/passes/map_inline.rs:210-217`
8. `lookup result is not consumed by fixed-offset scalar loads`
   - `daemon/src/passes/map_inline.rs:218-225`
9. `lookup result has non-load uses`
   - `daemon/src/passes/map_inline.rs:226-232`
10. `failed to materialize replacement constants`
    - `build_site_rewrite()` 返回 `Ok(None)`
    - `daemon/src/passes/map_inline.rs:234-243`
11. `map lookup failed: ...`
    - `build_site_rewrite()` 返回 `Err(...)`
    - `daemon/src/passes/map_inline.rs:244-250`
12. `lookup pattern contains a branch target`
    - `daemon/src/passes/map_inline.rs:253-263`
13. `internal rewrite overlap`
    - `daemon/src/passes/map_inline.rs:265-275`
14. `overlapping map inline rewrite`
    - 多个 site merge 时冲突
    - `daemon/src/passes/map_inline.rs:298-315`

### 1.2 `build_site_rewrite()` 内部返回 `Ok(None)` 的隐藏原因

这些最后都会被上层统一变成：

- `failed to materialize replacement constants`

具体来源是：

1. `replacements.is_empty()`
   - `daemon/src/passes/map_inline.rs:452-454`
2. 要删除的 raw PC 不是连续区间
   - `daemon/src/passes/map_inline.rs:456-463`
3. 要删除的最大 PC 不是 `call` 或紧随其后的 null-check
   - `daemon/src/passes/map_inline.rs:465-469`
4. 删除区间越界
   - `daemon/src/passes/map_inline.rs:471-474`

### 1.3 “静默 no-op” 条件

这些不会进 `sites_skipped`，但会导致 pass 最终 `changed=false`：

1. 根本没找到任何 lookup site
   - `find_map_lookup_sites()` 只收集 `helper=1` 且能反向找到 `r1 = pseudo_map_fd` 的 site
   - `daemon/src/passes/map_inline.rs:62-81`
   - `find_map_load_for_call()`：`daemon/src/passes/map_inline.rs:547-560`
2. `find_map_lookup_sites()` 找到了 0 个 site，于是 `rewrites.is_empty()`
   - `daemon/src/passes/map_inline.rs:280-288`
3. 所有 rewrite 在 merge 阶段都冲突，导致 `applied == 0`
   - `daemon/src/passes/map_inline.rs:325-334`

## Step 2：`map_info` 分析到底做了什么

### 2.1 支持哪些 map type

`supports_direct_value_access()` 允许：

- `BPF_MAP_TYPE_HASH` = 1
- `BPF_MAP_TYPE_ARRAY` = 2
- `BPF_MAP_TYPE_LRU_HASH` = 9

代码：

- `daemon/src/analysis/map_info.rs:11-21`
- `daemon/src/analysis/map_info.rs:48-53`

明确排除：

- `BPF_MAP_TYPE_PERCPU_HASH` = 5
- `BPF_MAP_TYPE_PERCPU_ARRAY` = 6
- `BPF_MAP_TYPE_LRU_PERCPU_HASH` = 10

### 2.2 它会不会读 map value

**不会。**

`MapInfoAnalysis` 只调用：

- `collect_map_references(..., resolve_live_map_info)`：`daemon/src/analysis/map_info.rs:114-116`
- `resolve_live_map_info()`：`daemon/src/analysis/map_info.rs:183-192`

它只拿到：

- `map_type`
- `key_size`
- `value_size`
- `max_entries`
- `frozen`
- `map_id`

真正读 value 的是 pass 里的：

- `bpf::bpf_map_lookup_elem_by_id(info.map_id, &encoded_key, info.value_size as usize)`
- `daemon/src/passes/map_inline.rs:418-421`

### 2.3 VM 里是否存在读取 map 的权限问题

从当前证据看，**不是主要问题**。

原因：

1. 如果 `BPF_MAP_GET_FD_BY_ID` / `BPF_OBJ_GET_INFO_BY_FD` 失败，更可能出现：
   - `map reference metadata unavailable`
   - `map info unavailable`
2. 如果 `BPF_MAP_LOOKUP_ELEM` 失败，上层会记录：
   - `map lookup failed: ...`
3. 真实 VM probe 里看到的不是这些，而是结构匹配类 skip：
   - `"lookup key is not a constant stack materialization"`
   - `"map type 6 not inlineable in v1"`

也就是说，**当前 probe 根本没走到“权限/lookup syscall 失败”那一步。**

补充说明：

- 我准备了一个正向对照 probe：
  - `docs/tmp/20260326/map_inline_array_positive_probe.bpf.c`
  - `docs/tmp/20260326/map_inline_array_positive_probe.sh`
- 但本轮没有在 VM 里真正执行成功，因为 workspace 里已有一个运行中的 `vm-corpus` 占用了 repo 的 VM lock；按仓库规则我没有叠加新的 VM run 去和性能 run 排队/竞争。
- 所以“权限完全没问题”的最终正向实证，本轮还差一步；但现有负向 probe 已足够排除“这是当前 zero-hit 的主因”。

## Step 3：真实 VM 证据

### 3.1 已有 guest probe：Katran `xdp_pktcntr`

已存在的真实 guest probe 文件：

- `docs/tmp/20260326/probe_outputs/pktcntr_zero.stderr`
- `docs/tmp/20260326/probe_outputs/pktcntr_one.stderr`

对应源码：

- `runner/repos/katran/katran/lib/bpf/xdp_pktcntr.c:31-43`
- `runner/repos/katran/katran/lib/bpf/xdp_pktcntr.c:45-62`

这个程序有两个 lookup：

1. `ctl_array`
   - type = `BPF_MAP_TYPE_ARRAY`
   - key = `ctl_flag_pos = 0`
   - use = 读 `*flag`
2. `cntrs_array`
   - type = `BPF_MAP_TYPE_PERCPU_ARRAY`
   - key = `cntr_pos = 0`
   - use = `*cntr_val += 1`

两次真实 guest probe：

- 一次让 `ctl_array[0] = 0`
- 一次让 `ctl_array[0] = 1`

`map_inline` 的 skip reasons 完全相同：

- `lookup key is not a constant stack materialization`
- `map type 6 not inlineable in v1`

这说明：

1. 第二个 lookup 的 `PERCPU_ARRAY` 被过滤是**正确且预期的**；
2. 第一个 lookup 虽然源码上是 `ARRAY + key=0 + 读取 *flag`，但仍然被 `extract_constant_key()` 误判失败；
3. 因为失败发生在 value read 之前，所以把 map 值从 `0` 改成 `1` 完全不改变结果。

### 3.2 Katran object 的真实指令顺序

我在 host 上对真实构建产物做了反汇编：

- `llvm-objdump -S -d corpus/build/katran/xdp_pktcntr.bpf.o`

关键片段是：

```text
0:  r1 = 0
1:  *(u32 *)(r10 - 4) = r1
2:  *(u32 *)(r10 - 8) = r1
3:  r2 = r10
4:  r2 += -4
5:  r1 = map ll
7:  call bpf_map_lookup_elem
8:  if r0 == 0 goto ...
9:  r1 = *(u32 *)(r0 + 0)
10: if r1 == 0 goto ...
```

注意真实顺序：

- `r2 = fp`
- `r2 += -4`
- `LD_IMM64 r1 = map`
- `call`

而 `find_r2_stack_pointer_setup()` 当前写法是：

- `r2_add_pc = prev_real_pc(call_pc)?`
- `r2_mov_pc = prev_real_pc(r2_add_pc)?`
- 然后要求：
  - `mov` 必须是 `r2 = r10`
  - `add` 必须是 `r2 += negative_imm`

代码：

- `daemon/src/passes/map_inline.rs:562-576`

把 Katran 这个真实顺序代进去：

- `call_pc = 7`
- `prev_real_pc(7) = 5`
- 但 `pc=5` 是 `LD_IMM64 r1 = map`，不是 `r2 += -4`

所以这里直接失败，返回 `None`，上层就记录：

- `lookup key is not a constant stack materialization`

也就是说，**问题不是 key 不常量，也不是不在栈上，而是 pass 只认一种过窄的指令排列。**

## Step 4：为什么单元测试全过、真实程序却零命中

根因在测试样本不真实。

当前 `map_inline` 单元测试构造的指令顺序普遍是：

1. `LD_IMM64 r1 = map`
2. `stack store key`
3. `r2 = fp`
4. `r2 += off`
5. `call helper`

例如：

- `daemon/src/passes/map_inline.rs:993-1000`
- `daemon/src/passes/map_inline.rs:1034-1041`
- `daemon/src/passes/map_inline.rs:1071-1078`

也就是它们都把 `map load` 放在 `r2` key setup **之前**。

但真实 clang 产物更常见的是：

1. `stack store key`
2. `r2 = fp`
3. `r2 += off`
4. `LD_IMM64 r1 = map`
5. `call helper`

于是：

- 单元测试覆盖的是“手写理想顺序”
- 真实程序走的是“编译器正常顺序”
- pass 只支持前者，不支持后者

这就解释了为什么：

- 单元测试 23/23 通过
- 级联测试 5/5 通过
- 真实 VM run 里 `map_inline` 却几乎完全不触发

## Step 5：这是不是 zero-value 问题

**不是主因。**

### 5.1 代码上没有 zero skip

`build_site_rewrite()` 只要拿到 value bytes，就会对每个 fixed load 调：

- `read_scalar_from_value()`：`daemon/src/passes/map_inline.rs:495-508`
- `emit_constant_load()`：`daemon/src/passes/map_inline.rs:510-516`

没有任何：

- `if scalar == 0 { skip }`
- `if value is all zero { skip }`

### 5.2 ARRAY zero value 仍然可以 inline

对 ARRAY：

- key 在范围内即可 lookup 成功
- 即使用户没写，读到的也只是默认零值
- 当前 pass 仍会把它改写成常量 `0`

### 5.3 HASH/LRU_HASH 空 map 会 skip，但不是“inline zero”

对 HASH / LRU_HASH：

- key 不存在时，`bpf_map_lookup_elem_by_id()` 会失败
- 最后会记成：
  - `map lookup failed: ...`

这和“值为 0 所以跳过”是两回事。

### 5.4 已有 real VM probe 也证明 zero 不是当前主因

Katran probe 中：

- `ctl_array[0]=0`
- `ctl_array[0]=1`

skip reasons 不变。

说明当前真实 zero-hit 发生在**value read 之前**。

## Step 6：这是不是 map type filtering 问题

**部分是，但不是主因。**

### 6.1 正确的过滤

以下 map type 当前确实会被过滤：

- `PERCPU_HASH`
- `PERCPU_ARRAY`
- `LRU_PERCPU_HASH`

这是 `supports_direct_value_access()` 的设计意图，不是 bug。

Katran `xdp_pktcntr` 中第二个 lookup：

- `cntrs_array`
- type = 6 = `BPF_MAP_TYPE_PERCPU_ARRAY`

被 skip 成：

- `map type 6 not inlineable in v1`

这个 skip 是正确的。

### 6.2 没有错误过滤 HASH / LRU_HASH

当前代码允许：

- `HASH`
- `LRU_HASH`

所以“是不是 HASH/LRU 被误过滤了”这一点，按当前代码答案是**没有**。

但 HASH/LRU 还有额外结构约束：

- 必须有紧邻的 null-check：`daemon/src/passes/map_inline.rs:210-217`
- 结果用途只能是 fixed-offset scalar loads：`daemon/src/passes/map_inline.rs:218-232`

真实程序里大量 HASH lookup 会死在这些条件上。

## 最可能的根因排序

我对当前 “real VM zero-hit” 的排序是：

1. **P0：`extract_constant_key()` 对真实 clang 指令顺序识别错误**
   - 证据最强
   - 已被真实 Katran object 反汇编直接支持
   - 会把源码层面本来符合条件的 `ARRAY + const key + scalar load` site 误判掉

2. **P1：pass 的整体匹配条件本来就很窄**
   - 即使修了 P0，仍有很多 real lookup 会因：
     - `PERCPU_*`
     - 非 fixed-load use
     - pointer escape / write-back
     - HASH 无 immediate null-check
     - key 非常量
     而继续 miss

3. **P2：真实 benchmark orchestration 里的 map state 确实经常不理想**
   - 对 HASH/LRU 尤其如此
   - 但这更像“coverage 上限受限”，不是当前 zero-hit 的首要解释

## 建议修复

### 修复 1：放宽 `find_r2_stack_pointer_setup()`，不要要求 `r2` setup 紧邻 helper call

当前实现：

- `daemon/src/passes/map_inline.rs:562-576`

建议改成：

1. 从 `call_pc` 向前扫描，找到**最近一次对 `r2` 的定义**
2. 允许中间存在与 `r2` 无关的指令，尤其是：
   - `LD_IMM64 r1 = pseudo_map_fd`
3. 找到 `r2 += negative_imm` 后，再继续向前找与之配对的：
   - `r2 = r10`

最小可行实现：

- 把 `find_r2_stack_pointer_setup()` 改成类似 `find_map_load_for_call()` 的 backward def-use 搜索，而不是 `prev_real_pc(prev_real_pc(call_pc))` 这种固定模板。

### 修复 2：给真实 clang 顺序补单元测试

当前测试样本不真实。

至少新增一个 regression test，指令顺序应是：

1. `stack store key`
2. `mov64 r2, r10`
3. `add64 r2, -4`
4. `ldimm64 r1, pseudo_map_fd`
5. `call helper`
6. `ldx rX, [r0 + off]`

建议测试名：

- `extract_constant_key_accepts_real_clang_lookup_order`
- `map_inline_pass_rewrites_real_clang_lookup_order`

### 修复 3：保留/新增一个真实 guest probe

建议把这次准备好的正向对照 probe 真正跑掉：

- BPF 源：
  - `docs/tmp/20260326/map_inline_array_positive_probe.bpf.c`
- guest 脚本：
  - `docs/tmp/20260326/map_inline_array_positive_probe.sh`

期待结果：

1. 修复前：
   - 大概率仍会出现 `lookup key is not a constant stack materialization`
2. 修复后：
   - `map_inline.changed=true`
   - `map_inline.sites_applied=1`
   - 不再出现该 skip

### 修复 4：改善可观测性

目前 debug JSON 里只有 `PassDetail.skip_reasons`，没有 `MapInlineRecord.expected_value`。

建议至少做其一：

1. 在 `OptimizeOneResult` 暴露 `map_inline_records`
2. 或在 `map_inline.changed=true` 时把：
   - `map_id`
   - `key`
   - `expected_value`
   编进 `diagnostics`

这样后续就能直接回答：

- 这个 site 有没有真的读到 live value
- 读到的是 0 还是非 0

## 建议验证集

修复后建议按这个顺序验证：

1. **daemon unit test**
   - 新增 “真实 clang 顺序” regression test
   - 目标：当前代码 fail，修复后 pass

2. **guest 单程序 probe**
   - 跑 `docs/tmp/20260326/map_inline_array_positive_probe.sh`
   - 目标：证明 live `ARRAY` + non-zero value 能在 VM 中被成功 inline

3. **重跑已有 Katran probe**
   - `docs/tmp/20260326/map_inline_vm_probe.sh`
   - 目标：
     - `ctl_array` 那个 lookup 不再报 `lookup key is not a constant stack materialization`
     - `cntrs_array` 那个 `PERCPU_ARRAY` 仍继续被正确过滤

4. **再看 vm-static-test / vm-corpus / vm-e2e**
   - 目标不是立刻追求很高 hit rate，而是确认：
     - `map_inline` 不再长期固定为 0
     - `const_prop/dce` 开始出现由 `map_inline` 驱动的级联命中

## 最终判断

当前 `map_inline` 在真实 VM run 中零命中的**最核心根因**是：

> **pass 对 lookup key 的识别逻辑只匹配了手写测试里的指令顺序，没有匹配真实 clang 生成的顺序。**

所以今天看到的 “ZERO hits in real VM runs” 更准确地说不是：

- frozen gating 还没放开
- zero value 被特殊跳过
- HASH/LRU 被误过滤
- VM 没权限读 map

而是：

- **结构匹配器先把真实候选 site 误杀了，导致根本走不到 live map read。**

这也解释了为什么：

- unit tests 全过；
- real VM probe 把 map 从 0 改成 1 也没变化；
- corpus/e2e 里 `map_inline` 一直是 0。
