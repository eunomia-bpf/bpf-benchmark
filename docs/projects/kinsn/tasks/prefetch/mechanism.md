# Kinsn Prefetch Mechanism

最后更新：2026-06-04。

## 结论

本文件只解释 Kinsn prefetch 的执行机制和基础设施。这里的内容不是 prefetch policy。

Prefetch policy 要回答的是：

```text
对哪个地址 prefetch、何时 prefetch、提前多远、一次发几个 hint、用哪种 hint、何时跳过。
```

本文件回答的是：

```text
如果 policy 已经决定要 prefetch，BPF bytecode、kfunc ABI、kernel JIT、runner 如何把它执行出来。
```

## Prefetch 和替换型 kinsn 的区别

多数 Kinsn family 是替换型优化。例如 rotate / EXTR 类优化：

```text
control BPF:
  shift
  shift
  or

treatment native:
  one rotate / extr instruction
```

替换型 kinsn 的性能逻辑通常是：

- native 指令更少；
- dependency 更短；
- 原始 BPF sequence 被更紧凑的 native 语义替代。

Prefetch 不是替换型优化，而是插入型优化：

```text
control BPF:
  load *(ptr)

treatment BPF:
  KINSN_SIDECAR(ptr_reg)
  KINSN_CALL(bpf_x86_prefetcht0 or bpf_arm64_prfm_pldl1keep)
  load *(ptr)
```

Treatment 保留原始 demand load，并额外增加一个 cache hint。因此 prefetch 只有在 hint 能隐藏
memory latency，且额外 frontend / bandwidth / cache pollution 成本可控时才可能变快。

## BPF 表达形式

Kinsn prefetch 在 BPF bytecode 里由两部分组成：

```text
KINSN_SIDECAR:
  payload = pointer register id

KINSN_CALL:
  target = bpf_x86_prefetch* or bpf_arm64_prfm_*
```

`KINSN_SIDECAR` 携带 payload，`KINSN_CALL` 指定目标 kfunc。Verifier 仍检查普通 BPF 程序；
目标架构 JIT 在 verifier 之后把 kfunc call 翻译成 native hint。

## Native hint ABI

当前支持的 target：

| arch | hint arg | kfunc target | native hint |
|---|---|---|---|
| x86 | `t0` / `l1keep` | `bpf_x86_prefetcht0` | `prefetcht0 [addr]` |
| x86 | `t1` / `l2keep` | `bpf_x86_prefetcht1` | `prefetcht1 [addr]` |
| x86 | `t2` / `l2strm` | `bpf_x86_prefetcht2` | `prefetcht2 [addr]` |
| x86 | `nta` | `bpf_x86_prefetchnta` | `prefetchnta [addr]` |
| ARM64 | `pldl1keep` / `l1keep` | `bpf_arm64_prfm_pldl1keep` | `prfm pldl1keep, [addr]` |
| ARM64 | `pldl1strm` / `l1strm` | `bpf_arm64_prfm_pldl1strm` | `prfm pldl1strm, [addr]` |
| ARM64 | `pldl2keep` / `l2keep` | `bpf_arm64_prfm_pldl2keep` | `prfm pldl2keep, [addr]` |
| ARM64 | `pldl2strm` / `l2strm` | `bpf_arm64_prfm_pldl2strm` | `prfm pldl2strm, [addr]` |

这些 target 只提供 “如何发 hint”。它们不决定 “何时发 hint”。

## 运行路径

主要实现文件：

```text
/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs
/home/ruoji/github/bpf-opt/code/module/x86/bpf_x86_prefetch.c
/home/ruoji/github/bpf-opt/code/module/arm64/bpf_arm64_prfm.c
```

Micro kernel runtime 路径：

```text
BPF object
  -> runner 读取 object
  -> 如果设置 BPFREJIT_BENCH_PASSES=prefetch，先调用 bpfopt
  -> bpfopt 输出 transformed raw BPF bytecode
  -> raw kinsn loader 加载 BPF
  -> kernel kinsn JIT emit native prefetch hint
  -> micro kernel runtime 测量 execution time
```

已经完成的基础设施：

| component | 作用 | 是否 policy |
|---|---|---|
| kfunc ABI | 提供 x86 / ARM64 prefetch target。 | 否 |
| `KINSN_SIDECAR + KINSN_CALL` | 在 BPF bytecode 中表达 prefetch。 | 否 |
| kernel JIT emit | 把 kfunc target 翻译成 native `prefetch*` / `prfm`。 | 否 |
| micro kernel pass path | 确保 benchmark 加载前真的运行 `bpfopt`。 | 否 |
| raw loader map relocation | 让 transformed raw BPF 支持 map relocation。 | 否 |
| PMU capability smoke | 检查当前环境能否采硬件 counters。 | 否 |

## 和 PF-LLM 的 scope 区别

PF-LLM 是 hardware prefetcher ensemble 的 offline hinting 方案。它为每个 load PC 生成 hint，
runtime 硬件用这些 hint 选择 sub-prefetcher、degree 和 demand filtering。

Kinsn prefetch 不做硬件 ensemble，也没有硬件 Prefetch Hint Table。Kinsn 的可控点是：

```text
BPF bytecode pass 决定是否插入一个显式 kinsn prefetch call。
```

因此 PF-LLM 对本 task 的价值是提供 policy 维度和评估方法，不是直接照搬硬件结构。

参考资料：

- PF-LLM paper PDF：`/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/sources/papers/pf-llm-2026-asplos.pdf`
- Online PDF：`https://fact-lab.hkust.edu.hk/publications/conference-paper/2025/xu-2025-pf-llm/3779212.3790202.pdf`
