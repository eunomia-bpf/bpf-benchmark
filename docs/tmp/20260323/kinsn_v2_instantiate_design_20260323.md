# kinsn v2 目标设计文档

日期：2026-03-24  
状态：target spec  
主题：first-class kinsn IR + proof lowering + pure transport

## 0. 文档定位

这份文档定义的是 `kinsn v2` 的长期目标架构。

它不是：

- `v1` 现状描述文档
- “当前最省改动实现路径”说明
- 论文前兼容迁移备忘

当前仓库里已经落地的 `v1`，继续以 `docs/kinsn-design.md` 和代码现状为准。  
本文档只定义终局目标：`kinsn` 长期应该是什么抽象，kernel、JIT、generic fallback、daemon 各自应围绕什么边界演进。

## 1. 目标

`kinsn v2` 的目标不是单纯把 `model_call()` 换成另一套 verifier helper，也不是只换一个 call 编码。

长期上，`kinsn` 应满足：

1. `kinsn` 是 first-class IR / first-class instruction，而不是 “is-a kfunc”
2. `instantiate_insn()` 定义它的 canonical BPF-visible semantics
3. verifier 通过临时 lowered proof object 证明它，而不是直接消费 module 提供的 `effect DSL`
4. 执行和 native JIT 仍以原始 `kinsn` 为主表示，而不是把最终 IR 永久降成普通 BPF
5. generic fallback 在需要时，按同一 `instantiate_insn()` 重建执行序列
6. transport 最终也应纯化，不再借 `kfunc` 身份、`kfunc` 名字和 `PSEUDO_KFUNC_CALL`
7. 纯 microarchitectural hints / non-BPF-visible semantics 也必须能被 `kinsn` 承载

一句话概括：

**`kinsn` 的本体是 first-class instruction；普通 BPF 是它的 proof object 和 fallback object，不是它的长期身份。**

## 2. 核心语义模型

## 2.1 first-class kinsn IR

原始程序中的 `kinsn` 不是“更聪明的 kfunc call”，也不是“等待被永久宏展开的语法糖”。

长期上，它应被视为独立 IR 节点：

- 有自己的 target 身份
- 有自己的 payload 约定
- 有自己的 native emit
- 有自己的 generic fallback
- 有自己的用户态发现与编码路径

这意味着：

- `kinsn` 不应再通过 `KF_KINSN` 绑在 `kfunc` 上
- daemon 不应再通过“已知 kfunc 名字 + 模块 BTF FUNC type id”来发现它
- JIT 不应再把它当 `kfunc call` 的特殊分支

## 2.2 `instantiate_insn()` 是 canonical 语义源

`instantiate_insn(payload, insn_buf)` 定义 `kinsn` 的 canonical BPF-visible semantics。

这里的关键点不是“把 payload 解码成几条 BPF”这么简单，而是：

- verifier 信它
- generic fallback 执行它
- native emit 对它做 refinement

因此：

- module 不再通过 `model_call()` 直接描述 `bpf_reg_state`
- verifier 不再以 `bpf_kinsn_effect` 作为主要语义源
- native emit 不是独立语义来源

可信边界也因此变得清楚：

- 用户只提供 payload 和 target
- kernel/module 负责产出 canonical semantics
- verifier 只信 kernel 生成的 proof object
- 不依赖用户“手工保证语义正确”

## 2.3 proof lowering

本文档把长期目标叫做 **proof lowering**。

它的抽象关系是：

```text
原始程序:
  P = 含 first-class kinsn 的程序

proof object:
  L(P) = 把每个 kinsn site 用 instantiate_insn(payload) 展开后的普通 BPF 程序
```

验证语义定义为：

- verifier 证明 `L(P)` 安全
- 证明结果回到原始程序 `P`
- 这个桥接成立，是因为每个原始 `kinsn` site 的 BPF-visible semantics 由 `instantiate_insn()` 定义

这里最重要的边界是：

- **普通 BPF 是证明对象，不是长期主 IR**
- **原始 `kinsn` 才是执行和优化的主表示**

## 2.4 执行模型

长期执行模型应区分两条路径：

1. **native path**
   - JIT 直接面对原始 `kinsn`
   - 调 `emit_x86()` / `emit_arm64()` 之类的 native emit callback
   - 这是优化路径

2. **generic fallback path**
   - 当 native emit 不存在、失败、或解释器/通用后端需要执行时
   - 重新调用同一个 `instantiate_insn()`
   - 生成普通 BPF 执行序列

因此长期契约是：

- 原始 `kinsn` 是主执行表示
- instantiated BPF 是 proof/fallback 表示
- 两者共享同一个 payload decode 和 canonical semantics

## 2.5 等价边界

本文档里的“等价”，默认都指：

- **BPF-visible semantics equivalence**

它不要求：

- native path 与 fallback path 具有完全一致的微架构效果

这个边界对纯 hint 类对象尤其重要。

## 3. 为什么终局应是 proof lowering，而不是 canonical final IR

`v2` 里有两种看起来都很“纯”的路线：

1. `kinsn` 永久 lower 成普通 BPF，native JIT 再对 lowered region 做 fusion
2. `kinsn` 保持 first-class IR，只在 verifier / fallback 中进行 proof lowering

本文档选择第 2 条，原因不是“代码量更少”，而是抽象更对。

## 3.1 保留 first-class instruction 身份

如果把最终执行 IR 永久降成普通 BPF，那么 `kinsn` 的长期身份会退化成：

- “一段宏展开”
- “一段带 provenance 的 lowered region”

这不符合本文档的目标。  
本文档要求 `kinsn` 本体长期存在，而不是只剩 metadata。

## 3.2 verifier 仍然通过普通 BPF 语义工作

选择 proof lowering，不等于让 verifier 重新理解一套 module 私有语言。

相反，verifier 仍然只需要理解：

- 普通 BPF
- 由 kernel 生成的 proof object

这比 `effect DSL` 更干净，因为 verifier 证明的仍是真实 BPF 语义，而不是人工摘要语言。

## 3.3 避免把 native emit 问题变成 fusion 证明问题

如果最终 IR 是 lowered BPF，那么 native path 需要做 region fusion，证明义务会多出一层：

- region 边界正确
- skip 长度正确
- pattern / metadata 对应正确
- fused native 序列等价于那段 lowered BPF

proof lowering 路线下，native emit 的论证更直接：

- `instantiate_insn(payload)` 定义 canonical BPF-visible semantics
- `emit_native(payload)` 只需要证明 refine 这份语义

不需要再额外证明“JIT 如何从最终 lowered IR 中识别并替换 region”。

## 3.4 避免 verifier 后续变换污染长期主 IR

如果 ordinary BPF 是最终 IR，那么 verifier/post-verifier rewrites 对 lowered BPF 做的所有变换，都可能反过来塑造 `kinsn` 的长期执行形态。

proof lowering 路线下：

- verifier 可以自由对 proof object 做它需要的分析和临时变换
- 这些变换不要求成为原始 `kinsn` 的长期身份

也就是说，verifier 使用普通 BPF 的优势可以保留，而 first-class `kinsn` 的长期抽象也不会被吞掉。

## 3.5 有利于缓解执行期寄存器压力

proof lowering 还有一个直接工程收益：

- verifier 使用的 proof object 可以为了证明方便而引入临时寄存器
- 但原始 `kinsn` 作为长期主 IR 时，这些临时寄存器不必出现在最终执行表示里

这意味着：

- 某些原本为了 ordinary BPF 展开而占用的 temp reg，可以在最终程序表示里释放出来
- native path 可以保持更紧凑的寄存器语义

这不是附带的小优化，而是 first-class `kinsn` 相对“永久展开成普通 BPF”很实际的一点优势。

## 4. verifier 模型

长期 verifier 模型应是：

1. 识别原始程序里的 `kinsn` site
2. 查找对应 target
3. 读取 payload
4. 调 `instantiate_insn(payload, insn_buf)`
5. 构造 proof object
6. 在 proof object 上做普通 BPF 验证
7. 验证成功后，把结果归属于原始 `kinsn` 程序

注意三点：

## 4.1 不是 effect DSL

不再走：

- `decode_call`
- `validate_call`
- `model_call`
- `bpf_kinsn_effect`
- `apply_clobber`
- `apply_result`

这些都属于 `v1` 的过渡机制，而不是 `v2` 的长期语义核心。

## 4.2 不是 pseudo BPF call

proof object 不是“把 kinsn 包装成一个伪 subprog call”。

原因很明确：

- subprog call 自带调用 ABI 语义
- 会把 `r0`、caller-saved、frame enter/exit 等语义再次绑回来
- 这与 `kinsn` 的任意寄存器语义目标冲突

因此 proof-lowered 序列应被视为：

- **inline 的普通 BPF 证明对象**

而不是：

- **某种伪装成 call 的对象**

## 4.3 proof lowering 的具体内核实现可留弹性

本文档定义抽象，不强行固定唯一实现手法。

在内核里，proof lowering 可以有两种常见实现：

1. 临时 in-place rewrite，再 restore
2. 单独构造 shadow proof program

这两者都只是实现技术。  
长期抽象上的硬要求只有一个：

- verifier 证明的是 lowered proof object
- 原始 `kinsn` 仍是主 IR

换句话说：

- “analysis-only lowering + restore” 是一种实现
- “shadow lowered proof object” 也是一种实现
- 但两者在本文档里的语义地位相同，都是 **proof lowering**

### 4.3.1 `验证前展开，验证后 replace` 是完全正当的实现

对当前内核代码形态，一个很自然的 proof-lowering 实现就是：

1. verifier 主分析前先把 `kinsn` site 展开成普通 BPF
2. verifier 在展开后的 proof object 上做分析
3. 分析完成后，再把对应 region replace 回原始 `kinsn`

这里的重点是：

- 这是实现技术
- 不是另一套语义模型
- 也不应被描述成一个复杂的独立子系统

### 4.3.2 不应把 replace 机制夸大成复杂框架

当前内核里，`bpf_patch_insn_data()` 和相关 rewrite 基础设施已经处理了大部分结构性细节。

因此，对 proof-lowering 路线里的 replace 机制，正确的理解应当是：

- 它主要复用现有 patch/rewrite 基础设施
- 可能需要少量附加细节
- 但它不构成新的主要设计难点

也就是说，本文档不把 “replace back” 当成一个需要额外发明完整 framework 的问题。  
它应被视为：

- 一个小而直接的 verifier 内部实现机制

而不是：

- 一个新的语义层
- 或一个需要专门复杂化设计叙事的对象

### 4.3.3 按当前 kernel 代码，replace 的正确做法

基于当前 `verifier.c` / `core.c` 的实现，一个正确且直接的方案可以写成：

#### A. proof lowering（验证前展开）

对每个原始 `sidecar + call` site，从后往前处理：

1. 先保存一条 region 记录：
   - 原始 sidecar 指令
   - 原始 call 指令
   - 当前 site 索引
   - proof-lowered 序列长度

2. 先删 sidecar：
   - `verifier_remove_insns(env, sidecar_idx, 1)`

3. 此时原始 call 已左移到 `sidecar_idx`

4. 再把这条 call patch 成 proof object：
   - `new_prog = bpf_patch_insn_data(env, sidecar_idx, insn_buf, proof_len)`
   - `env->prog = new_prog`

之所以建议“先 remove sidecar，再 patch call”，原因很简单：

- proof object 本来就不需要 sidecar
- `bpf_patch_insn_data()` 天然就是 `1 -> N`
- 这样 region 起点始终等于原始 sidecar 位置，记录和 restore 都更直观

#### B. restore（验证后 replace 回原始 kinsn）

在验证结束后，对 region 仍然从后往前处理：

1. 先把 proof region 的第一条普通 BPF patch 回两条原始编码：
   - `new_prog = bpf_patch_insn_data(env, region_start, orig_pair, 2)`
   - 其中 `orig_pair = { sidecar, call }`

2. 再删掉 proof region 剩余的尾部：
   - `verifier_remove_insns(env, region_start + 2, proof_len - 1)`

也就是把：

```text
[proof_0, proof_1, ..., proof_{N-1}]
```

恢复成：

```text
[sidecar, call]
```

这里不需要额外造一套 branch/linfo/subprog 框架。  
当前内核现成 helper 已覆盖了大部分结构性工作：

- `bpf_patch_insn_data()`
  - 调 `bpf_patch_insn_single()`
  - 调整 branch offset
  - 调整 line info
  - 调整 `subprog_info.start`
  - 调整 `insn_array`
  - 调整 `poke_desc`
  - 搬移 `insn_aux_data`

- `verifier_remove_insns()`
  - 清理被删区间的 aux 动态字段
  - 收缩指令流
  - 调整 branch offset
  - 调整 `subprog_info.start`
  - 调整 line info
  - 调整 `insn_array`
  - 搬移剩余 `insn_aux_data`

#### C. 为什么这条路不是“幻觉式复杂框架”

`adjust_insn_aux_data()` 现在已经会把：

- 原位置的 `seen`
- 插入范围的 aux 搬运

做掉。

因此，replace 这件事真正剩下的不是“region/aux 投影框架”，而只是：

- 保存 region 记录
- 逆序 patch/remove
- 对 restore 后那两个槽位做一个很小的 aux scrub

### 4.3.4 restore 后只需要一个很小的 aux scrub

虽然结构性工作基本都由现成 helper 覆盖了，但为了保证 post-analysis passes 不读到 proof object 残留，restore 后仍然建议做一个很小的 aux scrub。

原因是：

- `bpf_patch_insn_data()` 会把被替换位置原来的 aux 搬到“最后一条插入指令”
- 如果 proof region 的第一条普通 BPF 带有 `needs_zext`、`alu_state` 一类标记
- restore 回来的 `call` 槽位可能继承这些普通-BPF 专属 aux 位

而后面的 pass 还会继续读这些位，例如：

- `do_misc_fixups()` 会读 `needs_zext` / `alu_state`
- `opt_subreg_zext_lo32_rnd_hi32()` 会读 `zext_dst`
- `opt_remove_dead_code()` 会读 `seen`

因此 restore 后最稳的做法是：

- 保留 `seen`
- 视需要保留 `orig_idx`
- 其余 ordinary-BPF-specific aux 字段清零

这不是大工程。  
它就是一个小的 `scrub_restored_kinsn_aux()` helper。

### 4.3.5 restore 的时机

如果采用当前这条 `验证前展开，验证后 replace` 实现，最干净的插入窗口是：

- lowering：`add_subprog_and_kfunc()` 之后，`check_subprogs()` 之前
- restore：`do_check_main()/do_check_subprogs()` 之后，`remove_fastcall_spills_fills()` 之前

理由：

- 当前 transport 仍是 `kfunc` 形态时，需要先让 `add_subprog_and_kfunc()` 建好 `kfunc_tab`
- verifier 主分析、CFG、SCC、live-reg 都必须看到 proof object
- `remove_fastcall_spills_fills()`、`optimize_bpf_loop()`、`do_misc_fixups()` 等后续 rewrite 应该看到最终恢复后的原始 `kinsn`

### 4.3.6 关于 stack temp 的现实约束

按当前 kernel 代码，如果 proof object 里引入额外 stack temp，会有一个现实问题：

- `check_max_stack_depth()` 在主分析之后才跑
- 它检查的是主分析阶段算出来的 stack depth

所以如果 proof-lowered 序列使用了额外 stack，而 restore 发生在这之后，那么：

- 最终程序即使已经恢复成原始 `kinsn`
- verifier 仍可能按照 proof object 的更大 stack depth 记账

因此，当前代码形态下最简单、最稳的首版做法是：

- **proof-lowered 序列先保持 stack-free**

如果将来一定要在 proof object 中使用 stack temp，那么再决定：

- 是接受保守的更大 stack 记账
- 还是显式增加 stack-depth 重算/调整逻辑

## 5. generic fallback 模型

generic fallback 不应依赖 native emit。

长期上，generic fallback 的契约应是：

1. 接收原始 `kinsn` site 的 payload 和 target
2. 重新调用 `instantiate_insn()`
3. 生成普通 BPF 执行序列
4. 由解释器或通用后端执行

这意味着：

- verifier 证明的东西和 fallback 执行的东西来自同一个语义源
- native emit 缺失时，系统仍正确
- correctness 不依赖特定 arch 的 inline JIT callback
- 当 JIT 不支持某个 `kinsn` 时，系统退回的是 instantiated 指令序列，而不是退回 `kfunc` 语义

## 6. native JIT 模型

长期 native JIT 应直接面对原始 `kinsn`，而不是被迫从最终 ordinary BPF 里做 pattern fusion。

因此长期接口语义应是：

- JIT 识别一个 first-class `kinsn` site
- 读取 payload
- 调 `emit_x86()` / `emit_arm64()`

如果 emit 不可用，则：

- 走 generic fallback
- 而不是让 native JIT 必须自己从 lowered BPF 里重新识别 region

这样做的好处是：

- original IR 不丢失
- native emit 逻辑更直接
- correctness 叙事更短

## 7. 语义类别

## 7.1 BPF-visible kinsn

例如：

- `rotate`
- `select`
- `extract`
- `endian`
- `barrier`

这类对象的 canonical semantics 就是一小段普通 BPF。

它们最适合 proof lowering：

- verifier 直接理解
- fallback 直接执行
- native path 直接优化

## 7.2 microarchitectural hint / non-BPF-visible kinsn

例如未来可能的：

- `prefetch`
- `pause`
- cache hint
- pipeline hint

这类对象也必须允许进入 `kinsn` 范围。  
但它们的语义边界要写清楚：

- `instantiate_insn()` 只需要表达 **BPF-visible effect**
- native path 可以附加额外 microarchitectural effect

因此：

- 对 `prefetch`，canonical lowering 可能只是 no-op 或最小顺序约束表达
- 对 `barrier` 一类对象，canonical lowering 也可以是现有 BPF internal opcode，例如 `BPF_ST_NOSPEC`

正确性陈述必须是：

- verifier 证明程序的 BPF-visible 行为不变
- native path 允许有额外 hint 效果

## 8. `instantiate_insn()` 的长期约束

`instantiate_insn()` 不是任意代码生成器。  
它必须满足可验证、可执行、可 reasoning 的约束。

长期建议约束：

1. 不允许 helper/kfunc/kinsn/subprog/tailcall
2. 不允许 back-edge
3. region 必须局部封闭
4. 序列必须 deterministic
5. 不得依赖 verifier 内部隐藏状态
6. 同一 payload 必须生成同一 canonical lowering

这里不把 “禁止 stack temp” 写进长期规格。  
那只是某些具体实现策略的工程限制，不应当成为长期抽象的一部分。

## 9. API 方向

长期 API 应围绕 first-class `kinsn` 和 proof lowering，而不是围绕 `effect DSL`。

建议方向：

```c
struct bpf_kinsn {
	struct module *owner;
	u16 api_version;
	u16 max_insn_cnt;
	u16 max_emit_bytes;
	u16 flags;

	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);

	int (*emit_x86)(u8 *image, u32 *off, bool emit,
			u64 payload, struct bpf_prog *prog);
	int (*emit_arm64)(u32 *image, int *idx, bool emit,
			  u64 payload, struct bpf_prog *prog);
};
```

设计要点：

- `instantiate_insn()` 直接吃 raw payload
- `emit_*()` 也直接吃 raw payload
- verifier 与 fallback 共用 `instantiate_insn()`
- native path 与 fallback path 共用 payload decode 约定

长期上，`v1` 里这些东西应逐步退出主路径：

- `struct bpf_kinsn_ops`
- `struct bpf_kinsn_call`
- `struct bpf_kinsn_effect`
- `decode_call`
- `validate_call`
- `model_call`
- `apply_*` 类 verifier helper

## 10. transport 目标

本文档不把 transport 当作唯一核心，但长期 transport 也必须纯化。

长期 transport 要求：

1. `kinsn` 有 dedicated target 身份
2. userspace discovery 不再基于“已知 kfunc 名字 + BTF FUNC type id”
3. 字节码编码不再依赖 `PSEUDO_KFUNC_CALL`
4. `kinsn` 的用户态能力发现、编码和内核 lookup 都以 dedicated descriptor 为中心

这里有一个刻意保留的弹性：

- `CALL.off` 是否继续承担某种 module namespace handle，不是本文档的核心

如果目标对象仍处在 module-scoped namespace 里，`off` 继续承载 namespace handle 并不破坏纯度；  
真正破坏纯度的是：

- target 身份仍然被定义成 `kfunc`
- daemon 仍然通过 `kfunc` 发现与编码

## 11. daemon 影响边界

这部分必须说清楚：

## 11.1 仅做语义重构时，daemon 不必改

如果 kernel 只是把 `v1` 的 verifier/JIT 语义内核从 `effect DSL` 改成：

- `instantiate_insn()`
- proof lowering
- native emit / generic fallback 共用同一语义源

但 transport 仍保持：

- sidecar payload
- `PSEUDO_KFUNC_CALL`
- `CALL.off = fd slot`
- 当前按 kfunc/BTF 发现 target 的路径

那么 daemon 不需要做功能性改动。

原因是当前 daemon 根本不理解 verifier 语义。  
它只做：

- target discovery
- module fd slot 管理
- 字节码 emission

它并不参与：

- `effect DSL`
- `model_call()`
- verifier state 更新
- JIT emit correctness

因此：

- **语义重构本身不要求 daemon 变**

## 11.2 transport 纯化时，daemon 必须改

一旦 transport 也改纯，daemon 就必须改。

原因不是“语义变了”，而是当前 daemon 明确硬编码了 `kfunc` transport。

当前耦合点如下。

### 11.2.1 discovery

`daemon/src/kfunc_discovery.rs` 当前做的是：

- 扫描 `/sys/kernel/btf/<module>`
- 通过固定 `KNOWN_KFUNCS` 名字表查找 `BTF_KIND_FUNC`
- 记录每个 kfunc 的 BTF type id
- 打开 module BTF fd

具体耦合包括：

- `KNOWN_KFUNCS`
- `find_func_btf_id()`
- `DiscoveryResult`
- `registry.kfunc_module_fds`
- `registry.kfunc_supported_encodings`

这意味着 pure transport 下，daemon 必须把 “发现 kfunc” 改成 “发现 kinsn descriptor / target”。

### 11.2.2 registry 和 pass 映射

`daemon/src/pass.rs` 的 `KfuncRegistry` 当前按 kfunc 身份组织：

- `rotate64_btf_id`
- `select64_btf_id`
- `extract64_btf_id`
- `endian_load{16,32,64}_btf_id`
- `speculation_barrier_btf_id`
- `kfunc_module_fds`
- `kfunc_supported_encodings`

同时还把 pass 名字硬映射到 kfunc 名字：

- `kfunc_name_for_pass()`
- `btf_id_for_kfunc_name()`
- `module_fd_for_pass()`
- `supported_encodings_for_kfunc_name()`

如果 transport 纯化，这一层必须改成以 `kinsn target` 为中心，而不是以 `kfunc name` 为中心。

### 11.2.3 emission

`daemon/src/insn.rs` 和 `daemon/src/passes/utils.rs` 当前直接发：

- `BPF_PSEUDO_KFUNC_CALL`
- `call_kfunc_with_off()`
- `emit_packed_kfunc_call_with_off()`

其中：

- `BPF_PSEUDO_KFUNC_CALL` 定义在 `daemon/src/insn.rs`
- `call_kfunc_with_off()` 明确把 `src_reg` 设成 `BPF_PSEUDO_KFUNC_CALL`
- `emit_packed_kfunc_call_with_off()` 明确发 `sidecar + call_kfunc_with_off()`

如果 transport 纯化，这些 helper 必须换成 dedicated `kinsn` emission helper。

### 11.2.4 fd slot 管理

`daemon/src/passes/utils.rs` 的 `ensure_module_fd_slot()` 当前服务于：

- `CALL.off = module fd slot`

如果 pure transport 仍保留 module-scoped namespace handle，这部分可以继续存在。  
如果 pure transport 改成全局 target id / 不再需要 fd slot，这部分就可以删除或降级。

也就是说：

- daemon 是否还需要 fd slot，取决于 pure transport 的 namespace 设计
- daemon 必改的是 “按 kfunc 发现和编码”
- daemon 不一定必改的是 “是否还有 module fd slot”

### 11.2.5 依赖 call 形状的 pass/tests

当前还有一些 pass/test 直接假设“下一条是 `PSEUDO_KFUNC_CALL`”。

比如：

- `daemon/src/passes/spectre.rs`
- 各 pass 的单元测试中对 `is_kinsn_sidecar()` 和 `src_reg() == BPF_PSEUDO_KFUNC_CALL` 的断言

一旦 transport 纯化，这些地方也要同步改。

## 12. kernel 影响边界

这部分也要分成语义层和 transport 层看。

## 12.1 语义层改动点

即使 transport 暂时不变，只做 `v2` 语义重构，kernel 也必须动这些核心点：

### 12.1.1 `vendor/linux-framework/include/linux/bpf.h`

长期上需要：

- 引入 first-class `struct bpf_kinsn`
- 逐步退休 `struct bpf_kinsn_ops`
- 逐步退休 `struct bpf_kinsn_call`
- 逐步退休 `struct bpf_kinsn_effect`

当前这里的 `v1` 语义中心非常明确：

- `enum bpf_kinsn_encoding`
- `struct bpf_kinsn_call`
- `struct bpf_kinsn_effect`
- `struct bpf_kinsn_ops`
- `decode_call`
- `validate_call`
- `model_call`
- `emit_x86`
- `emit_arm64`

也就是说，`include/linux/bpf.h` 现在把 `kinsn` 定义成：

- “一个有 `decode/validate/model/emit` 回调的 kfunc 附件”

`v2` 需要把它改成：

- “一个 first-class target，提供 `instantiate_insn()` 和 native emit”

### 12.1.2 `vendor/linux-framework/kernel/bpf/verifier.c`

长期上需要：

- 移除 `model_call()` / `effect` 为核心的 kinsn verifier 路径
- 引入基于 `instantiate_insn()` 的 proof lowering 路径
- 明确 verifier 证明对象是 proof object，而不是 module 提供的效果摘要

当前 `v1` 在 verifier 里的具体耦合点，至少包括三块：

1. **注册与 lookup**
   - `struct bpf_kinsn_ops_desc`
   - `bpf_get_kinsn_ops_desc()`
   - `bpf_find_kinsn_ops()`
   - `register_bpf_kinsn_ops()`
   - `desc->kinsn_ops = ... (*kfunc.flags & KF_KINSN) ? ...`

2. **call 解析与 effect 主链**
   - `bpf_build_legacy_kinsn_call()`
   - `bpf_prepare_kinsn_call()`
   - `bpf_collect_kinsn_scalar_inputs()`
   - `bpf_validate_kinsn_effect()`
   - `bpf_kinsn_check_mem_accesses()`
   - `bpf_kinsn_apply_clobber_mask()`
   - `bpf_kinsn_apply_result()`
   - `bpf_kinsn_apply_subreg_def()`
   - `check_kinsn_call()`

3. **sidecar / kfunc 入口耦合**
   - `bpf_verifier_find_kinsn_sidecar()`
   - `check_kinsn_sidecar_insn()`
   - `check_kfunc_call()` 中 `(meta.kfunc_flags & KF_KINSN)` 分支

`v2` 语义重构的本质，就是把第 2 块整条链从 “decode -> model -> effect -> apply” 换成：

- `lookup target`
- `instantiate_insn(payload, buf)`
- `build proof object`
- `verify ordinary BPF`

同时把第 1 块里的 target 身份，从 `KF_KINSN` 绑到 `kfunc` 的模式拆出来。

### 12.1.3 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

长期上需要：

- 让 native path 直接面对 first-class `kinsn`
- 保留 generic fallback 的入口
- 不把最终方向写成“从 ordinary lowered BPF 做 pattern fusion”

当前 x86 路径的具体耦合非常直接：

- `emit_kinsn_call()`
- `bpf_jit_find_kinsn_ops()`
- `bpf_jit_get_kinsn_call()`
- `case BPF_JMP | BPF_CALL` 里：
  - `if (src_reg == BPF_PSEUDO_KFUNC_CALL && bpf_jit_find_kinsn_ops(...))`

这说明现在的 x86 native path 本质上还是：

- “在 kfunc call dispatch 里，顺手识别一个 KF_KINSN 目标”

`v2` 长期需要把这层关系反过来：

- `kinsn` 是主对象
- `kfunc` 不再是它的宿主入口

### 12.1.4 `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`

与 x86 同理。

当前 arm64 路径的具体点包括：

- `emit_kinsn_call_arm64()`
- `bpf_jit_find_kinsn_ops()`
- `bpf_jit_get_kinsn_call()`
- `build_insn()` 中对 `BPF_PSEUDO_KFUNC_CALL` 的专门分支

也就是说，arm64 当前同样是：

- 先走 `kfunc call`
- 再在里面特判 `kinsn`

### 12.1.5 `module/include/kinsn_common.h` 与 `module/{x86,arm64}/*.c`

长期上需要：

- 从 `decode/validate/model` 风格转向 `instantiate_insn()`
- 保留或重写 native `emit_*()`
- 把 module 的 verifier 语义贡献方式，统一成普通 BPF instantiation

当前 module 层的具体耦合也很重：

- `module/include/kinsn_common.h`
  - `kinsn_set_reg_operand()`
  - `kinsn_set_imm32_operand()`
  - `BTF_ID_FLAGS(..., KF_KINSN)`
  - `const struct bpf_kinsn_ops *ops`

- `module/x86/*.c` 和 `module/arm64/*.c`
  - 每个 target 都有 `decode_*_call()`
  - 每个 target 都有 `validate_*_call()`
  - 每个 target 都有 `model_*_call()`
  - 每个 target 都有 `static const struct bpf_kinsn_ops ...`

例如：

- `bpf_rotate.c`
- `bpf_select.c`
- `bpf_extract.c`
- `bpf_endian.c`
- `bpf_barrier.c`

都在重复维护：

- payload decode
- verifier 摘要建模
- native emit

`v2` 的目标是把中间那层 verifier 摘要建模删掉，只保留：

- payload decode / instantiation
- native emit

## 12.2 transport 纯化改动点

一旦 transport 也改纯，kernel 还必须继续动这些层：

### 12.2.1 `vendor/linux-framework/include/uapi/linux/bpf.h`

需要 dedicated `kinsn` transport 定义，例如：

- dedicated pseudo tag
- 或 dedicated target encoding

总之不能继续把 `kinsn` 定义成 `PSEUDO_KFUNC_CALL`。

### 12.2.2 `vendor/linux-framework/kernel/bpf/core.c`

如果 transport 变了：

- target lookup
- patch/fixup
- disasm 相关辅助逻辑

都要从 `kfunc` 视角拆出来。

这里不只是“改个常量”，而是要把：

- `kfunc` 目标解析
- `kinsn` 目标解析

拆成两套明确语义，而不是继续让 `kinsn` 通过 `kfunc` 通道搭车。

### 12.2.3 verifier 和 JIT 中所有 `PSEUDO_KFUNC_CALL` 触点

transport 纯化会影响：

- verifier 对 call 保留字段的检查
- kfunc/kinsn target lookup
- JIT dispatch
- 可能的 disassembler 展示

当前 verifier 里比较直接的触点包括：

- `bpf_pseudo_kfunc_call()`
- `add_kfunc_in_insns()`
- `add_subprog_and_kfunc()`
- `fetch_kfunc_arg_meta()`
- `check_kfunc_call()`
- `check_kinsn_sidecar_insn()`
- `do_check_insn()` 里 `BPF_CALL uses reserved fields` 的字段校验
- `fixup_kfunc_call()`
- `do_misc_fixups()` 中对 `BPF_PSEUDO_KFUNC_CALL` 的 fixup 分支

当前 JIT 里的直接触点包括：

- x86 `case BPF_JMP | BPF_CALL` 中 `src_reg == BPF_PSEUDO_KFUNC_CALL` 分支
- arm64 `build_insn()` 中 `insn->src_reg == BPF_PSEUDO_KFUNC_CALL` 分支

这说明 transport 纯化不是“单文件替换名字”，而是：

- verifier 主入口
- fixup 链路
- JIT dispatch
- daemon emission/discovery

一起改的系统工程。

因此 transport 改造本身是横跨 UAPI、verifier、core、JIT、daemon 的系统性改动。

## 13. 本文明确拒绝的长期路线

## 13.1 拒绝 effect DSL 作为主路径

原因：

- 它不是 canonical executable semantics
- verifier 和 JIT 不共享同一语义对象
- module 需要维护额外建模语言

## 13.2 拒绝 pseudo BPF call

原因：

- 会把 subprog call ABI 语义重新带回来
- 不适合 `kinsn` 的任意寄存器语义目标
- 会把 proof object 误建模成函数调用

## 13.3 拒绝“ordinary BPF 是最终 IR，native 只做 fusion”作为终局

原因：

- 会让 `kinsn` 长期退化成 lowered region
- 会把 native emit 正确性转化成 fusion 正确性
- 会让 verifier/post-verifier 对 ordinary BPF 的变换，反过来塑造 `kinsn` 的长期主表示

## 14. 对当前仓库文档的含义

建议文档分工固定为：

- `docs/kinsn-design.md`
  - 只描述 `v1 current`

- `docs/tmp/20260323/kinsn_v2_instantiate_design_20260323.md`
  - 描述 `v2 target`
  - 以 first-class `kinsn` + proof lowering + pure transport 为准

## 15. 最终结论

`kinsn v2` 的长期目标应定为：

- `kinsn` 是 first-class IR
- `instantiate_insn()` 定义 canonical BPF-visible semantics
- verifier 通过临时 lowered proof object 证明它
- 原始 `kinsn` 仍是执行与 native JIT 的主表示
- generic fallback 在需要时，按同一 `instantiate_insn()` 重建执行序列
- 纯 microarchitectural hints 也纳入 `kinsn` 范围，但其等价定义只覆盖 BPF-visible semantics
- transport 也要纯化，不再借 `kfunc` 身份、发现路径和 `PSEUDO_KFUNC_CALL`

同时要明确写死这一层边界：

- **语义重构本身不要求 daemon 变**
- **transport 纯化才要求 daemon 变**

而当前仓库里 daemon 需要动的具体位置，主要就是：

- `daemon/src/kfunc_discovery.rs`
- `daemon/src/pass.rs`
- `daemon/src/insn.rs`
- `daemon/src/passes/utils.rs`
- `daemon/src/passes/spectre.rs`
- 各 pass 中依赖 `sidecar + PSEUDO_KFUNC_CALL` 形状的测试

一句话总结：

**`kinsn v2` 的正确终局不是“更聪明的 kfunc”，也不是“最终只剩 ordinary BPF + fusion”；而是“first-class kinsn + proof lowering + pure transport”。**
