# Katran endian-swap-store-16 correctness bug 调查

日期: 2026-03-20

## 结论摘要

Katran `balancer_ingress` 中两个 `endian-swap-store-16` site 确实会在一起启用时导致请求超时。根因不是 Katran 的特殊语义，也不是 16-bit store 的对齐问题，而是：

1. `ENDIAN_FUSION` emitter 对 `swap-store` 的 lowering 不保留原始 BPF 指令对寄存器的副作用。
2. `ENDIAN_FUSION` validator 只校验了 pattern shape 和宽度匹配，没有校验 store 后数据寄存器是否仍然 live。

这两个 site 在 Katran 里都是对外层 IPv4 头 `tot_len` 的写入。原始 BPF 语义是：

- 先把寄存器变成 big-endian 值；
- 再把该值写到包头；
- 随后继续复用这个“已经 swap 过”的寄存器参与 IPv4 checksum 累加。

而 fused JIT 只做了 `movbe store`，内存里的字节序是对的，但寄存器仍保持 host-order。随后 checksum 累加使用了错误值，导致外层 IP header checksum 错误，测试请求超时。

因此，这是：

- 直接原因: emitter correctness bug
- 漏防原因: validator bug

最安全的修复方案是先禁止 `ENDIAN_SWAP_STORE` fusion；更精细的方案是 validator 只允许 store 后数据寄存器 dead 的 site 通过。

## 1. Site 定位

### 1.1 object-level scanner 结果

对 `corpus/build/katran/balancer.bpf.o` 运行 scanner：

```bash
scanner/build/bpf-jit-scanner scan corpus/build/katran/balancer.bpf.o \
  --program-name balancer_ingress --endian --json
```

得到 4 个 endian site：

| object insn offset | kind |
| --- | --- |
| 371 | `endian-load-swap-32` |
| 662 | `endian-load-swap-32` |
| 1462 | `endian-swap-store-16` |
| 2161 | `endian-swap-store-16` |

本次问题只涉及后两个 `endian-swap-store-16`。

### 1.2 live program 中的 remap 结果

在 VM 中加载 Katran，并只应用这两个 store site 的 policy 后，live remap 结果为：

| live insn offset | kind |
| --- | --- |
| 1702 | `endian-swap-store-16` |
| 2564 | `endian-swap-store-16` |

相关工件：

- `docs/tmp/katran_balancer_storepair_20260320.policy.yaml`
- `docs/tmp/katran_storepair_guest_probe_20260320.json`

### 1.3 对应的 Katran 源码位置

`llvm-objdump -Sl --section=xdp corpus/build/katran/balancer.bpf.o` 显示这两个 site 都落在：

- `corpus/repos/katran/katran/lib/bpf/encap_helpers.h:67`

对应语句：

```c
iph->tot_len = bpf_htons(pkt_bytes + sizeof(struct iphdr));
```

调用链来自 `encap_v4()` 的两个 inline clone，调用点可见于：

- `corpus/repos/katran/katran/lib/bpf/pckt_encap.h:117`

这说明两个 site 都是在写 packet header，不是写 map，也不是写 stack。具体是在构造外层 IPv4 header 时写 `iph->tot_len`。

### 1.4 xlated dump 中的语义

stock xlated dump 中，这两个 site 都呈现出相同结构：

```text
rX = be16 rX
*(u16 *)(r1 + 16) = rX
r2 += rX
```

第一处 live site 附近：

```text
1702: r4 = be16 r4
1703: *(u16 *)(r1 +16) = r4
1705: r2 += r4
```

第二处 live site 附近：

```text
2564: r9 = be16 r9
2565: *(u16 *)(r1 +16) = r9
2567: r2 += r9
```

这里的关键点是：store 后寄存器值还会继续用于 checksum 累加。

## 2. ENDIAN_FUSION emitter 分析

目标文件：

- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

关键逻辑：

- `emit_movbe_load()` 会在 16-bit load 后做 zero-extension。
- `emit_movbe_store()` 只发出一个 `movbe` store。
- `emit_canonical_endian_fusion()` 对 `ENDIAN_SWAP_STORE` 直接走 `emit_movbe_store()`。

也就是说，swap-store 被 canonicalize 为“只对 memory store 做 byte-reverse”，而不是“先更新寄存器，再执行 store”。

### 2.1 stock JIT 与 recompiled JIT 的关键差异

第一处 site 的 stock JIT：

```text
addq $20, %rcx
rorw $8, %cx
movzwl %cx, %ecx
movw %cx, 16(%rdi)
addq %rcx, %rsi
```

第一处 site 的 recompiled JIT：

```text
addq $20, %rcx
movbew %cx, 16(%rdi)
addq %rcx, %rsi
```

第二处 site 也是同样差异：

```text
stock:
addq $20, %r15
rorw $8, %r15w
movzwl %r15w, %r15d
movw %r15w, 16(%rdi)
addq %r15, %rsi

recompiled:
addq $20, %r15
movbew %r15w, 16(%rdi)
addq %r15, %rsi
```

### 2.2 correctness 判断

`movbe` store 只保证“写到内存里的两个字节是翻转后的顺序”，但不会把翻转后的值写回寄存器。

因此 fused code 的语义变成：

```text
host-order reg
  -> movbe store to memory  (memory 正确)
  -> later arithmetic still uses host-order reg  (寄存器错误)
```

这和原始 BPF 语义不等价。Katran 正好在 store 后马上把该寄存器加入 IPv4 checksum，所以 checksum 被算错。

结论：emitter 生成了错误的 native code。

## 3. ENDIAN_FUSION validator 分析

目标文件：

- `vendor/linux-framework/kernel/bpf/jit_validators.c`

validator 已经做对的部分：

- 识别 `swap + stx` 的 store pattern；
- 检查 store 宽度和 swap 宽度匹配；
- `swap-store-16` 对应的是 16-bit store，不存在 “32-bit swap 配 16-bit store” 这种明显宽度错配。

所以本问题不是宽度检查漏掉了，至少不是这个方向。

### 3.1 validator 实际漏检的条件

validator 没有检查：

- store 之后，参与 swap 的数据寄存器是否仍然 live；
- 后续是否继续依赖“swap 后的寄存器值”。

Katran 这两个 site 恰好就是 live-out 的：

```text
rX = be16 rX
*(u16 *)(r1 + 16) = rX
r2 += rX
```

如果 validator 只看前两条，会误以为这是可以安全变成 `movbe store` 的 canonical pattern；但第三条证明该寄存器的副作用仍然被程序观察到。

结论：validator 错误地放行了不满足语义等价条件的 site。

## 4. VM 中的复现与隔离

### 4.1 只启用两个 store site 仍可稳定复现

使用只包含 object offsets `1462` 和 `2161` 的 policy：

- `docs/tmp/katran_balancer_storepair_20260320.policy.yaml`

运行 Katran e2e smoke，warmup 直接失败并报 timeout。

随后在 VM 内做了定制 probe，结果如下：

- stock JIT: 3/3 HTTP 请求 `200 OK`
- recompiled JIT，仅启用这两个 `swap-store-16` site: 3/3 请求全部 `timed out`

相关工件：

- `docs/tmp/katran_storepair_guest_probe_20260320.json`
- `docs/tmp/katran_storepair_stock_xlated_20260320.txt`
- `docs/tmp/katran_storepair_stock_jited_20260320.txt`
- `docs/tmp/katran_storepair_recompiled_xlated_20260320.txt`
- `docs/tmp/katran_storepair_recompiled_jited_20260320.txt`

### 4.2 复现结论

这说明：

1. 只要启用这两个 `swap-store-16` site，就足以触发故障。
2. 问题不依赖其他两个 `endian-load-swap-32` site。
3. 故障和这两个 site 的 native lowering 直接相关。

## 5. 根因归类

### 5.1 不是 Katran 特殊语义

Katran 的代码本身没有异常。它只是写了一个很常见的模式：

```c
tmp = htons(x);
store(tmp);
checksum += tmp;
```

这是合法且常见的网络栈写法。

真正的问题是 `ENDIAN_SWAP_STORE` 假设“swap 只对 memory store 有意义”，忽略了“swap 也会改变寄存器值”这一 BPF 语义。

### 5.2 不是 16-bit 对齐或 store 字节序错误

从 JIT dump 看，`movbew` 写出的内存字节序是正确的。真正错的是 store 之后继续使用寄存器时，寄存器仍保持未翻转值。

### 5.3 最终判定

- emitter bug: 是，且这是直接导致请求超时的 correctness failure。
- validator bug: 是，validator 不该让这类 live-out swap-store site 通过。
- Katran 程序特殊语义: 否，Katran 只是暴露了一个通用的语义等价漏洞。

## 6. 修复建议

### 6.1 短期安全修复

最安全的方案是暂时禁用 `BPF_JIT_ENDIAN_SWAP_STORE` / `ENDIAN_SWAP_STORE` fusion。

原因：

- 现有 canonical emitter 无法保留寄存器副作用；
- 当前 validator 也没有足够的数据流检查保证 site 安全。

### 6.2 中期可接受修复

保留 load-side fusion，只让 validator 拒绝所有 store-side fusion，直到有完整的 liveness 证明。

这比修改 emitter 更现实，也更不容易引入新的 corner case。

### 6.3 如果必须保留 swap-store fusion

validator 至少要新增一条硬条件：

- 只有当 swap 的目标寄存器在 store 之后 dead，才允许 `swap-store` fusion。

否则必须拒绝该 site。

理论上也可以改 emitter，让 fused lowering 同时保留寄存器更新后的值；但那样通常需要额外指令，收益会明显下降，而且当前 canonical interface 并没有表达这类约束。

### 6.4 建议补测试

建议新增一类最小化 JIT regression test，覆盖：

```text
rX = be16 rX
*(u16 *)(base + off) = rX
use(rX)
```

验证 stock JIT、recompiled JIT 和 interpreter 结果一致。这个测试能直接防止同类 bug 再次出现。

## 7. 最终结论

Katran `balancer_ingress` 的两个 `endian-swap-store-16` site 都是写外层 IPv4 `tot_len`。`ENDIAN_FUSION` 把它们错误地降成了只影响 memory 的 `movbe store`，没有保留原始 `be16` 指令对寄存器的副作用；Katran 后续又复用了该寄存器去计算 checksum，最终生成错误的 outer IP checksum，导致请求超时。

所以这不是 Katran 特有问题，而是 `ENDIAN_SWAP_STORE` 优化本身不满足语义等价。修复方向应优先落在 validator gating，必要时直接禁用 swap-store fusion。
