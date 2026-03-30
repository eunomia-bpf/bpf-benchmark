# Prefetch kinsn 完整实现设计（2026-03-29）

日期：2026-03-29  
状态：design-only  
范围：只做设计，不改代码，不跑 VM

## 0. 结论摘要

`Prefetch` 适合作为 BpfReJIT 的 memory-hint showcase，但必须按 runtime-guided 方式收敛，而不能做静态 blanket insertion。

推荐方案如下：

- 新增一个单目标 kinsn：`bpf_prefetch(ptr)`。
- packed transport 继续沿用当前树的 `sidecar + BPF_PSEUDO_KINSN_CALL`。
- x86 JIT emit 为 `PREFETCHT0 [ptr]`；ARM64 JIT emit 为 `PRFM PLDL1KEEP, [ptr]`。
- verifier 语义定义为纯 hint：
  - 不修改任何寄存器状态。
  - 不暴露任何内存访问。
  - 不产生返回值。
- 在当前已实现的 kinsn v2 tree 上，推荐把 canonical proof sequence 实现成单条 `JA +0` no-op。这样无需先落地完整 `bpf_kinsn_ops::model_call()` 基础设施，也能满足“verifier 看起来什么都没发生”。
- daemon 侧新增 `PrefetchPass`，放在 pipeline 最后，做两类站点：
  - `lookup-prefetch`：对仍然存在的 `map_lookup_elem` helper call，在 call 前 `20-50` 条 BPF 指令处插入 `bpf_prefetch(R1)`。
  - `direct-load-prefetch`：对 direct map-value access / pseudo-map-value / future map-inline direct-load 路径，在第一条实际 load 前 `20-50` 条指令处插入 `bpf_prefetch(base)`。
- gate 必须是 profile-gated：
  - 没有 profile：默认不插。
  - 有 profile：只对 hot site 或 cache-miss 高的程序/站点插。
- 与 `map_inline` 的关系要明确区分：
  - 当前树的 `MapInlinePass` 主要是常量化，并不会稳定地产生“direct memory access + load”序列，因此“map_inline 后 prefetch”是 phase 2 设计点，不是当前实现的自动收益。
  - 当前树里更现实的 direct-address 入口是已有的 `BPF_PSEUDO_MAP_VALUE` 形式。

## 1. 设计目标与非目标

### 1.1 目标

1. 定义一个与现有 packed kinsn 风格一致的 `bpf_prefetch(ptr)`。
2. 给出 x86/ARM64 module skeleton。
3. 给出 daemon pass 的完整扫描、gate、distance 和重写策略。
4. 说明和 `map_inline` 的交互边界。
5. 给出预期收益、风险、实现优先级和时间估算。

### 1.2 非目标

1. 不在本轮设计里做 `NT store`。
2. 不在本轮设计里做“helper 内部真正 bucket/node/value 地址推导”的 specialized helper-lowering。
3. 不依赖 VM benchmark 或微架构手调来先证明 distance；v1 只给出可实现的 policy interface。
4. 不把 `PrefetchPass` 做成无 profile 也自动开启的固定 peephole。

## 2. kinsn 定义

### 2.1 用户可见语义

定义一个单操作数 kinsn：

```c
bpf_prefetch(ptr)
```

语义是：

- 这是一条纯 hint 指令。
- 它不改变任何 BPF 寄存器值。
- 它不在 verifier 语义里产生内存读取。
- 它不返回值。
- 它只影响 native JIT 代码中的 cache prefetch hint。

这正是 `Prefetch` 能体现 kinsn 价值的地方：固定内核 JIT 不知道哪些点值得 hint，daemon 可以按 runtime profile 选择性地插。

### 2.2 Packed bytecode 格式

继续沿用当前树已实现的 transport：

```text
pc:     sidecar pseudo-insn   ; payload
pc+1:   call kinsn            ; imm = BTF ID of bpf_prefetch
```

建议 payload 布局：

```text
bits [3:0]   = ptr_reg
bits [7:4]   = hint_kind   (v1 固定为 0，表示 temporal/L1 keep)
bits [63:8]  = reserved, must be zero
```

说明：

- v1 只支持一个 hint kind：
  - x86: `PREFETCHT0`
  - ARM64: `PLDL1KEEP`
- 预留 `hint_kind` 是为了后续扩展 `T1/T2/NTA` 或 `STRM/KEEP`，但 v1 不开放 policy 选择。
- `CALL.off` 继续放 module BTF 在 `fd_array` 里的 1-based slot，和现有 `rotate/extract/endian/bulk_memory` 完全一致。

示意：

```rust
let payload = ptr_reg as u64;
let insns = emit_packed_kinsn_call_with_off(payload, prefetch_btf_id, btf_slot);
```

### 2.3 verifier model

#### 2.3.1 目标语义

从设计上，`bpf_prefetch(ptr)` 的 verifier effect 应是：

- `input_mask = BIT(ptr_reg)`：消费一个输入寄存器。
- `clobber_mask = 0`。
- `result_type = VOID`。
- `nr_mem_accesses = 0`。

也就是说：

- verifier 看见的是“一条只读 hint”。
- 它不改变 range/tnum/subreg。
- 它不建立新的 pointer provenance。
- 它也不要求对某个 memory range 做 bounds proof。

这和 `docs/kernel-jit-optimization-plan.md §4.4`、`docs/tmp/20260323/kinsn_ops_design_20260323.md` 里定义的 `pure hint / no visible side effect` kinsn 是一致的。

#### 2.3.2 当前 tree 的落地方式

当前仓库里真实实现的 kinsn v2 还不是 `model_call()` 路径，而是：

- module 提供 `instantiate_insn(payload, insn_buf)`
- verifier 对 kinsn proof region 做 lowering

因此，`Prefetch` 在当前 tree 上最干净的落地方式不是伪造一个 load，而是：

- `instantiate_prefetch()` 返回一条 no-op proof sequence：

```c
insn_buf[0] = BPF_JMP_A(0);
return 1;
```

这样有几个好处：

1. verifier 看到的确实是不改寄存器、不访问内存的 no-op。
2. `max_insn_cnt = 1`，proof lowering 最小化。
3. 如果 native emit 缺失或 future fallback 触发，语义自动退化为 no-op，不会退化成真实函数调用。

所以推荐把本文档里的“verifier model = pure hint”具体实现成：

- 理想设计：`bpf_kinsn_ops::model_call()` 返回 empty effect。
- 当前 tree 实现：`instantiate_insn()` 产出 `JA +0`。

### 2.4 JIT emit

#### 2.4.1 x86

native emit：

```text
PREFETCHT0 [ptr]
```

module 侧建议新增：

- `module/x86/bpf_prefetch.c`
- stub kfunc：

```c
__bpf_kfunc void bpf_prefetch(void) {}
```

payload decode：

```c
static __always_inline int decode_prefetch_payload(u64 payload, u8 *ptr_reg)
{
	*ptr_reg = kinsn_payload_reg(payload, 0);
	if (payload >> 8)
		return -EINVAL;
	if (*ptr_reg > BPF_REG_10)
		return -EINVAL;
	if (!kinsn_x86_reg_valid(*ptr_reg))
		return -EINVAL;
	return 0;
}
```

emit 侧需要解决两个 x86 addressing 细节：

1. `rsp/r12` 作为 base 时需要 SIB byte。
2. `rbp/r13` 作为 base 时不能用 `mod=00`，必须编码成 `disp8 = 0`。

因此实现上最稳妥的做法是复用 `module/x86/bpf_bulk_memory.c` 已经存在的 memory-operand 编码思路，而不是手写一份只覆盖普通寄存器的简化版本。

建议 skeleton：

```c
static int instantiate_prefetch(u64 payload, struct bpf_insn *insn_buf)
{
	u8 ptr_reg;
	int err;

	err = decode_prefetch_payload(payload, &ptr_reg);
	if (err)
		return err;

	insn_buf[0] = BPF_JMP_A(0);
	return 1;
}

static int emit_prefetch_x86(u8 *image, u32 *off, bool emit,
			     u64 payload, const struct bpf_prog *prog)
{
	u8 ptr_reg;
	u8 buf[8];
	u32 len = 0;
	int err;

	(void)prog;
	err = decode_prefetch_payload(payload, &ptr_reg);
	if (err)
		return err;

	/* emit PREFETCHT0 [ptr_reg] */
	/* 0f 18 /1, plus REX/SIB/disp8=0 when needed */

	if (emit)
		memcpy(image + *off, buf, len);
	*off += len;
	return len;
}

const struct bpf_kinsn bpf_prefetch_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 6,
	.instantiate_insn = instantiate_prefetch,
	.emit_x86 = emit_prefetch_x86,
};
```

#### 2.4.2 ARM64

native emit：

```text
PRFM PLDL1KEEP, [ptr]
```

建议新增：

- `module/arm64/bpf_prefetch.c`

payload decode 与 x86 相同，寄存器映射复用 `kinsn_arm64_reg()`。

建议 skeleton：

```c
static int emit_prefetch_arm64(u32 *image, int *idx, bool emit,
			       u64 payload, const struct bpf_prog *prog)
{
	u8 ptr_reg;
	u32 insn;
	int err;

	(void)prog;
	err = decode_prefetch_payload(payload, &ptr_reg);
	if (err)
		return err;

	ptr_reg = kinsn_arm64_reg(ptr_reg);
	if (ptr_reg == 0xff)
		return -EINVAL;

	insn = a64_prfm_imm(A64_PRFM_PLDL1KEEP, ptr_reg, 0);
	if (emit)
		image[*idx] = cpu_to_le32(insn);
	*idx += 1;
	return 1;
}

const struct bpf_kinsn bpf_prefetch_desc = {
	.owner = THIS_MODULE,
	.max_insn_cnt = 1,
	.max_emit_bytes = 4,
	.instantiate_insn = instantiate_prefetch,
	.emit_arm64 = emit_prefetch_arm64,
};
```

#### 2.4.3 module 注册和 build 接线

需要的 file-level 变更应包括：

- `module/x86/bpf_prefetch.c`
- `module/arm64/bpf_prefetch.c`
- `module/x86/Makefile`: `obj-m += bpf_prefetch.o`
- `module/arm64/Makefile`: `obj-m += bpf_prefetch.o`
- `daemon/src/kfunc_discovery.rs`: 新增 `("bpf_prefetch", "bpf_prefetch", "bpf_prefetch")`
- `daemon/src/pass.rs`: `KinsnRegistry` 新增 `prefetch_btf_id`

## 3. Daemon pass 设计

### 3.1 Pass 放置位置

推荐把 `PrefetchPass` 放在默认 pipeline 最后：

```text
map_inline
-> const_prop
-> dce
-> skb_load_bytes_spec
-> bounds_check_merge
-> wide_mem
-> bulk_memory
-> rotate
-> cond_select
-> extract
-> endian_fusion
-> branch_flip
-> prefetch
```

原因：

1. `Prefetch` 只插 hint，不为后续 pass 提供结构性机会。
2. 它最依赖最终代码布局，尤其是 distance。
3. 放最后可以避免后续 `dce/const_prop/branch_flip` 把 distance 又打乱。
4. 当前 `MapInlinePass` 会删除一部分 lookup，`PrefetchPass` 放后面自然只看剩余 site。

### 3.2 Pass 输入与 profiling data

`PrefetchPass` 不应依赖当前 daemon 里的 `branch_miss_rate` PMU 路径，因为那条路径当前测到的是 daemon 线程，不是目标 BPF program。

因此推荐的数据模型是：

```rust
pub struct PrefetchSiteProfile {
    pub execution_count: u64,
    pub cache_miss_rate: Option<f64>,
}

pub struct ProfilingData {
    pub branch_profiles: HashMap<usize, BranchProfile>,
    pub branch_miss_rate: Option<f64>,
    pub cache_miss_rate: Option<f64>,
    pub prefetch_sites: HashMap<usize, PrefetchSiteProfile>,
}

pub struct InsnAnnotation {
    pub branch_profile: Option<BranchProfile>,
    pub prefetch_profile: Option<PrefetchSiteProfile>,
}
```

需要的 plumbing 设计：

1. `inject_profiling()` 支持把 `prefetch_sites[pc]` 注入到 `annotations[pc].prefetch_profile`。
2. `remap_annotations()` 必须像 remap `branch_profile` 一样 remap `prefetch_profile`。
3. `ProfileSnapshot` / `ProgramProfile` 需要新增 `cache_miss_rate` 字段。
4. 真正的 program-level cache-miss 数据源应是：
   - future `perf stat --bpf-prog <id> -e cache-references,cache-misses`
   - 或离线/runner 采集后 `profile-load` 进 daemon 的 snapshot

也就是说：

- program-level `cache_miss_rate` 是 coarse gate。
- site-level `execution_count` 是 site admission。

没有这两类 profile 之一时，`PrefetchPass` 默认不做任何 rewrite。

### 3.3 PGO gate 逻辑

推荐 gate：

```text
program_admit =
    profiling.cache_miss_rate >= program_cache_miss_threshold
    OR 存在任何 site execution_count >= site_hot_threshold

site_admit(site_pc) =
    site.execution_count >= site_hot_threshold
    OR site.cache_miss_rate >= site_cache_miss_threshold
    OR program.cache_miss_rate >= program_cache_miss_threshold
```

但为了避免“一个 missy program 把所有冷 site 都打开”，还要再叠一层 cap：

```text
per_program_budget = top N admitted sites by execution_count
```

v1 建议默认：

- `site_hot_threshold`: policy 可配，初值可从 profile window 内的 top percentile 派生，而不是硬编码到 pass。
- `program_cache_miss_threshold`: policy 可配，初值建议从 `5%-10%` 起调。
- `per_program_budget`: `4-8` 个 site。

关键点：

- `Prefetch` 是强 profile-gated pass，不应该像 `rotate` 那样“有 pattern 就尽量上”。
- cold start 时没有 profile，默认直接 skip，不能静默 fallback 成“全开”。

### 3.4 两类 rewrite family

#### 3.4.1 Family A: lookup-prefetch

目标：

- 对仍然存在的 `bpf_map_lookup_elem` call，在 helper 调用前较早位置插入：

```text
bpf_prefetch(R1)
...
call bpf_map_lookup_elem
```

这里必须明确它的真实语义：

- 这条 hint prefetch 的是 `R1` 指向的 map/base metadata line。
- 它不是“helper 内部最终会访问的 bucket/node/value line”。

因此：

- 这是一个可以现在实现的 v1 path。
- 但它不是 Prefetch 的最高 ROI 版本。
- gate 必须比 direct-load path 更严格。

推荐只对以下站点考虑：

1. `map_inline` 之后仍然保留的 `map_lookup_elem` site。
2. 站点属于 hot/candidate set。
3. 可在同一 basic block 里找到 `20-50` 条 BPF 指令的 prefetch window。
4. `R1` 在 prefetch 之后到 helper call 之前没有被改写。
5. prefetch window 中间没有其他 helper call / pseudo-call / exit。

#### 3.4.2 Family B: direct-load-prefetch

目标：

- 对 direct memory access 场景做：

```text
bpf_prefetch(base_or_exact_addr)
...
ldx *(base + off)
use
```

这是更有价值的路径，因为它更接近真实被 miss 的 data line。

但要把它拆成两个子阶段理解：

1. 当前树立即可做的 direct-address source：
   - 已有的 `BPF_PSEUDO_MAP_VALUE` / direct map value 访问。
2. future map-inline direct-load 模式：
   - 只有当 `MapInlinePass` 将来从“常量化”扩展到“保留 direct load”时，这条路才会成为主战场。

换句话说：

- 本文把 direct-load-prefetch 设计进 `PrefetchPass`。
- 但它的主收益依赖 future `map_inline` 形态，而不是当前 `MapInlinePass` 的常量化实现。

### 3.5 Prefetch distance 选择

#### 3.5.1 基本原则

distance 不是 kinsn payload 的一部分，而是 pass 放置位置策略。

推荐用 BPF 指令数作为 v1 proxy：

- `min_distance = 20`
- `max_distance = 50`
- `target_distance = 32`

这里的“指令数”应按 real BPF insn 计：

- `LD_IMM64` 作为一个逻辑点处理，不能把第二槽单独算一条。

#### 3.5.2 选择规则

给定目标指令 `target_pc` 和要 prefetch 的 `ptr_reg`：

1. 找到同一 basic block / subprog 的边界。
2. 反向找 `ptr_reg` 最后一次定义 `last_def_pc`。
3. 计算 valid insertion interval：

```text
valid_start = max(bb_start, last_def_end_pc, target_pc - max_distance)
valid_end   = target_pc - min_distance
```

4. 如果 `valid_start > valid_end`，则该 site skip，原因是：
   - 程序太短，或
   - `ptr_reg` 准备得太晚。
5. 否则选择最接近 `target_pc - target_distance` 的那个 insertion pc。

这条规则对两类 family 都适用。

#### 3.5.3 为什么不把 distance 编进 kinsn

因为真正起作用的是“prefetch 放在什么位置”，不是 native instruction 自己带一个距离参数。

`Prefetch` 的 runtime sensitivity 在 daemon pass 层，而不是 module/JIT 层。

### 3.6 去重和预算控制

需要额外的 anti-noise 规则：

1. 同一个 basic block 内，对同一个 target line 只发一个 prefetch。
2. 多个 candidate site 的 insertion pc 若相距过近，只保留最热那个。
3. 每个 program 只保留 top `N` 个 admitted site。

这三条对 bandwidth 和 code-size 都重要。

## 4. `PrefetchPass` 伪代码

```rust
struct PrefetchCandidate {
    anchor_pc: usize,      // profile 对应的目标站点 pc
    target_pc: usize,      // helper call 或 first load 的 pc
    insert_pc: usize,      // sidecar 插入位置
    ptr_reg: u8,
    kind: PrefetchKind,    // LookupBeforeHelper | DirectLoad
    score: u64,            // execution_count or derived hotness
}

fn run(program, analyses, ctx) -> PassResult {
    if ctx.kinsn_registry.prefetch_btf_id < 0 {
        return skip("bpf_prefetch kfunc not available");
    }
    if !ctx.kinsn_registry.packed_supported_for_target_name("bpf_prefetch") {
        return skip("bpf_prefetch packed ABI not available");
    }
    if no_prefetch_profile(program) {
        return skip("prefetch requires profile data");
    }

    let bt = analyses.get(BranchTargetAnalysis, program);
    let map_info = analyses.get(MapInfoAnalysis, program)?;

    let mut candidates = Vec::new();

    // Phase A: remaining lookup sites after map_inline.
    for site in find_map_lookup_sites(&program.insns) {
        if !lookup_site_passes_profile_gate(program, site.call_pc) {
            continue;
        }
        if let Some(insert_pc) = choose_insert_pc_for_lookup(program, &bt, site.call_pc, BPF_REG_1) {
            candidates.push(PrefetchCandidate {
                anchor_pc: site.call_pc,
                target_pc: site.call_pc,
                insert_pc,
                ptr_reg: BPF_REG_1,
                kind: PrefetchKind::LookupBeforeHelper,
                score: profile_score(program, site.call_pc),
            });
        }
    }

    // Phase B: direct-load sites (pseudo-map-value now, map_inline direct-load later).
    for site in find_direct_load_prefetch_sites(program, &map_info) {
        if !direct_load_site_passes_profile_gate(program, site.first_load_pc) {
            continue;
        }
        if let Some(insert_pc) = choose_insert_pc_for_load(program, &bt, site.first_load_pc, site.base_reg) {
            candidates.push(PrefetchCandidate {
                anchor_pc: site.first_load_pc,
                target_pc: site.first_load_pc,
                insert_pc,
                ptr_reg: site.base_reg,
                kind: PrefetchKind::DirectLoad,
                score: profile_score(program, site.first_load_pc),
            });
        }
    }

    candidates = dedup_and_budget(candidates);
    if candidates.is_empty() {
        return unchanged();
    }

    let btf_slot = ensure_btf_fd_slot(program, ctx.kinsn_registry.btf_fd_for_target_name("bpf_prefetch")?);

    let mut new_insns = Vec::new();
    let mut addr_map = vec![0; program.insns.len() + 1];
    let mut pc = 0;
    let mut by_insert_pc = group_by_insert_pc(candidates);

    while pc < program.insns.len() {
        addr_map[pc] = new_insns.len();

        if let Some(prefetches) = by_insert_pc.get(&pc) {
            for candidate in prefetches {
                let payload = candidate.ptr_reg as u64;
                new_insns.extend_from_slice(
                    &emit_packed_kinsn_call_with_off(payload, ctx.kinsn_registry.prefetch_btf_id, btf_slot)
                );
            }
        }

        copy_current_instruction(program, &mut new_insns, &mut pc);
    }
    addr_map[program.insns.len()] = new_insns.len();

    fixup_all_branches(&mut new_insns, &program.insns, &addr_map);
    program.insns = new_insns;
    program.remap_annotations(&addr_map);
    program.log_transform(...);
    return changed(...);
}
```

## 5. 和 `map_inline` 的关系

### 5.1 当前树的真实关系

当前 `MapInlinePass` 的主路径是：

- 直接把 map value 读回 userspace。
- 再把 fixed-offset load 改写成常量。

因此当前真实情况是：

- `map_inline` 之后，大量 site 根本不会留下内存 load。
- 对这些 site，`PrefetchPass` 不应该也不可能重新插内存 hint。

这意味着：

- “`map_inline` 后 prefetch”不是当前树自然而然就有的收益。
- 如果要拿到这个收益，需要一个新的 direct-load specialization 形态。

### 5.2 设计上的 phase 2 关系

长期更有价值的路径是：

1. `map_inline` 从“常量化”扩展到“direct value access specialization”。
2. 它留下：

```text
prefetch exact_addr
...
load exact_addr
use
```

3. `PrefetchPass` 再按 profile 只给 hot load sequences 插 hint。

这个场景比 helper-path 更有价值，因为：

- 它 prefetch 的是更接近真实 value line 的地址。
- 它和 `prefetch -> load -> use` 经典序列完全一致。
- 它不再受 helper 边界遮挡。

### 5.3 当前可直接复用的 direct-address 入口

在 `map_inline` 真正扩展到 direct-load 之前，`PrefetchPass` 可以先支持：

- `BPF_PSEUDO_MAP_VALUE`
- 其他已经 materialize 出 direct base pointer 的 site

这部分实现和未来 direct map-inline path 是兼容的，不会浪费工程。

## 6. 预期收益分析

## 6.1 单 site 收益模型

对一个 hot site：

```text
benefit_per_hit = hidden_latency
hidden_latency ∈ [10ns, 100ns]
```

更合理的平均收益应写成：

```text
expected_benefit_per_exec = prefetch_useful_probability * hidden_latency
```

举例：

- 若 `prefetch` 只有 `25%` 的时候真的把 miss 隐掉：
  - L2 miss 场景：`0.25 * 10ns = 2.5ns`
  - L3 miss 场景：`0.25 * 40ns = 10ns`
  - DRAM 场景：`0.25 * 100ns = 25ns`

因此 `Prefetch` 的合理预期不是“每个 site 固定赚 40ns”，而是：

- 对真正 hot 且 missy 的 site，平均 `2.5-25ns` / exec 是可想象的。
- 对冷 site 或 target 错的 site，可能是负收益。

## 6.2 Hot lookup path 的聚合收益

以 `katran` 的 `balancer_ingress` 为例，研究文档里提到它有 `66` 个 map 引用。

不应假设 66 个都值得 prefetch。更合理的估计是：

- 只有其中少数热点 site 会通过 gate。
- 假设最终只开 `6-10` 个站点。
- 若每个站点平均贡献 `10-20ns`：

```text
total hidden latency per packet ≈ 60ns - 200ns
```

这个量级已经足够在高包率路径上有意义。

对 tracing/security 程序同理：

- `tetragon`、`tracee`、`KubeArmor` 的 lookup site 数量很大。
- 真正需要的是“从 17391 个潜在点里挑出极少数真正值得开的点”。

这正是 fixed kernel JIT 做不到，而 daemon + profile 能做到的部分。

## 7. 风险与缓解

### 7.1 错误 prefetch 浪费带宽

风险：

- prefetch 错 line、错 site、错 workload，都可能只制造额外带宽压力。

缓解：

- 强制 profile gate。
- 每程序 site budget。
- helper-path 比 direct-load path 更严格。

### 7.2 helper-path 预取不到真正的 hash bucket/value

风险：

- `bpf_prefetch(R1)` 在 helper 前 prefetch 的通常只是 map/base metadata，不是 helper 内部真正 miss 的 node/value。

缓解：

- 在文档和实现里把它标成 v1 path，不夸大收益。
- 让 direct-load-prefetch 成为更高价值的 phase 2。
- 真要冲 hash/LRU_HASH 核心 miss，后续应走 helper-lowering 或 specialized lookup kinsn。

### 7.3 distance 强依赖程序形态

风险：

- `20-50` 条 BPF 指令只是 proxy，不同架构、不同 program native expansion 不同。

缓解：

- v1 用 BPF insn count 做稳定起点。
- distance 阈值做 policy-configurable。
- 后续再做 arch-aware/native-cost aware tuning。

### 7.4 当前 daemon 的 program PMU 路径不可信

风险：

- 当前 `profiler.rs` 的 `perf_event_open(pid=0)` 路径测到的是 daemon 线程，不是目标 BPF program。

缓解：

- `PrefetchPass` 不消费这条数据。
- 只接受 `profile-load` 的外部 snapshot，或 future 正确的 `--bpf-prog`-scoped collector。

### 7.5 冷启动无 profile

风险：

- cold start 阶段没有任何可靠 gate。

缓解：

- 默认不开。
- 让 `PrefetchPass` 成为“有 profile 才启”的显式 pass。

## 8. 实现优先级与时间估算

## 8.1 推荐优先级

### P0: kinsn + plumbing（2-3 天）

- `module/x86/bpf_prefetch.c`
- `module/arm64/bpf_prefetch.c`
- `module/*/Makefile`
- `daemon/src/kfunc_discovery.rs`
- `daemon/src/pass.rs` 的 `KinsnRegistry`

目标：

- `bpf_prefetch` 能被发现。
- packed ABI 能编码。
- native emit / no-op proof fallback 都明确。

### P1: `PrefetchPass` helper-path（2-3 天）

- 新增 `daemon/src/passes/prefetch.rs`
- 新增 pass registry entry
- 只做 `lookup-prefetch`
- 没有 profile 就完全 skip

这是当前树最容易直接落地的版本。

### P2: profiling schema 扩展（2-4 天）

- `ProfilingData` / `ProgramProfile` / `ProfileSnapshot`
- `InsnAnnotation` + remap
- program-level `cache_miss_rate`
- site-level `execution_count`

注意：

- 不应复用当前 daemon thread PMU 计数。
- 应以 `--bpf-prog`-scoped profile snapshot 为准。

### P3: direct-load-prefetch（2-4 天）

- 先支持现有 `BPF_PSEUDO_MAP_VALUE`
- 再支持 future map-inline direct-load form

这是更值得做的收益版本，但依赖更强。

## 8.2 总体工期

如果只做“当前树可落地、严格 gated 的 helper-path prefetch”：

- 约 `4-6` 工程日。

如果连同正确 profile plumbing 和 direct-load phase 一起做成论文可讲的版本：

- 约 `8-14` 工程日。

## 9. 推荐收敛结论

推荐把 `Prefetch` 定位成：

- 一个纯 hint kinsn。
- 一个强 runtime-gated pass。
- 一个分阶段推进的 memory optimization：
  - phase 1：helper-before-lookup，严格 gate，证明“runtime-guided memory hint”可行。
  - phase 2：direct-load / map-inline 场景，拿真正的高 ROI。

最重要的是不要把它做成“17391 个 lookup 点都插 hint”的固定策略。`Prefetch` 的价值不在于多插一条指令，而在于：

- fixed kernel JIT 不知道哪个 site 值得 prefetch；
- daemon 可以根据 workload profile 只打开少数真正 hot + missy 的 site。

这正是它最适合体现 BpfReJIT runtime-guided 优势的原因。
