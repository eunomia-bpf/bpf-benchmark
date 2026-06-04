# Kinsn Prefetch Safety and Admission Rules

最后更新：2026-06-03。

## 结论

本文件记录 prefetch selector 的 safety / admission rules。它们不是 prefetch policy。

Policy 决定：

```text
这个 load 值不值得 prefetch？
```

Safety / admission rules 决定：

```text
如果 policy 想 prefetch，这个位置能不能安全插？会不会破坏 verifier/JIT/runtime correctness？
```

## 必须区分 policy 和 safety

错误分类：

```text
verifier-safe insertion window 是 policy
pointer register stability 是 policy
load-only filtering 是 policy
```

正确分类：

```text
这些都是 safety / admission rules。
```

它们不会告诉我们 prefetch 是否有性能收益，只能阻止错误或明显低质量的插入。

## 当前 safety / admission rules

| rule | 作用 | 当前状态 |
|---|---|---|
| same basic block | 插入点、payload pointer 和 target load 必须在可追踪的局部控制流内。 | 已实现。 |
| no call / jump / exit crossing | 插入窗口不能跨 `call`、`jump`、`exit`、pseudo func。 | 已实现。 |
| pointer register stability | prefetch 使用的 register 在插入点到 target load 之间不能被重定义。 | 已实现。 |
| verifier-safe placement | hint 必须位于 bounds/null check 之后，不能在 pointer 被证明安全前插入。 | 已由局部窗口和 case 设计覆盖，仍需要更强 dominance 规则。 |
| load-only target | 当前只对 read load 插入，不对 store 插入。 | 已实现。 |
| same-cacheline dedup | 同一 pointer / cacheline 的多个 loads 只保留一个 prefetch candidate。 | 已实现。 |
| site budget | 限制每个 program 的 prefetch site 数，避免代码膨胀。 | 已实现 `--max-sites`；这不是 true degree。 |
| map-value profile gate | map-value candidate 默认 skip，只有 profile allow-list 通过才插入。 | 已实现。 |
| dependent-depth gate | packet first-deref 只允许 depth 1 final deref；depth 0 和 depth > 1 默认 skip。 | 已实现 selector v3。 |

## 当前不足

当前 rules 仍是 BPF bytecode-level 局部规则，不是完整编译器 dominance / alias analysis。

仍需补的内容：

| missing rule | 为什么需要 |
|---|---|
| dominance-aware bounds proof | 现在主要依赖同 basic block / local window；复杂 CFG 下需要证明 bounds/null check dominate insertion point。 |
| automatic future-pointer validity | horizon policy 现在靠 hand-profiled PC/register；自动 selector 需要证明 future pointer 已物化且 live。 |
| per-site profitability guard | safety rules 只保证安全，不保证有收益；仍需要 policy / profile 判断。 |
| profile schema validation | profile 文件指定 PC/register 时，需要更严格检查 PC 是否仍对应同一 program shape。 |

## 和 true degree 的区别

`--max-sites N` 只是 site budget：

```text
最多允许插 N 个 prefetch candidates。
```

True degree 是 policy：

```text
对同一 logical access stream，一次预取几个未来地址，例如 i+1、i+2、i+4。
```

因此：

- site budget 属于 safety / admission。
- true degree 属于 policy。

## 和 PF-LLM 的 demand filtering 区别

PF-LLM 的 demand request filtering 是硬件 prefetcher ensemble 的 policy hint：某个 load 的 demand
request 是否应该喂给某个 sub-prefetcher，目的是避免污染该 sub-prefetcher 的内部状态。

Kinsn 当前没有硬件 sub-prefetcher state，因此不能直接照搬 demand filtering。

Kinsn 可以借鉴的是：

```text
对某些 load site，即使结构上可 prefetch，也要明确标记为 no-prefetch / skip。
```

这应该表现为 policy 层的 skip decision，而不是 safety 层的 verifier rule。
