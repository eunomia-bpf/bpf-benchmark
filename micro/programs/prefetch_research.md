# prefetch_research

## 目的

`prefetch_research.bpf.c` 是 Kinsn prefetch task 的 synthetic-control micro
benchmark。它把不同 packet memory access 形态拆开，用来判断某类访问是否可能从
Kinsn prefetch hint 受益。

这些 case 不是从真实 BPF 程序自动提取的 `real-derived` benchmark。它们是策略探针，
用来判断 `bpf_arm64_prfm_pldl1keep` / `bpf_x86_prefetcht0` 是否应该被用于特定访问形态。

## 输入和 IO 模式

- `io_mode`: staged XDP packet payload.
- `kernel_input_size`: 1400 bytes.
- `input_generator`: `prefetch_research`.
- `expected_result`: 每个 case 记录在
  `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`.

staged packet 模式让 verifier 约束接近普通 XDP packet access，也让 case 运行成本较低。
它不能模拟大 working set 的 cold memory 访问；这个问题由 `prefetch_map_research` 负责。

## Case

| case group | benchmarks | source type | 问题 |
|---|---|---|---|
| distance sweep | `prefetch_distance_0`, `prefetch_distance_2`, `prefetch_distance_4`, `prefetch_distance_8`, `prefetch_distance_16`, `prefetch_distance_32` | `synthetic-control` | later load 前的固定独立 work 是否能给 prefetch 足够 lead time。 |
| candidate filtering | `prefetch_hot_l1_load`, `prefetch_sequential_scan`, `prefetch_large_stride_scan`, `prefetch_permuted_index_scan`, `prefetch_packet_first_deref` | `synthetic-control` | 哪些 packet access shape 应该被 prefetch policy 考虑或跳过。 |
| selector v3 coverage | `prefetch_single_first_deref` | `synthetic-control` | 单个 data-dependent packet first deref 是否能被 v3 selector 命中 final deref。这个 case 用来验证 selector 行为，不作为真实 workload 收益证据。 |
| indirect / timeliness | `prefetch_indirect_lookup`, `prefetch_indirect_two_stage`, `prefetch_cacheline_dedup_scan`, `prefetch_packet_offset_guarded`, `prefetch_full_packet_ring_scan` | `synthetic-control` | indirect address、cacheline dedup、guarded offset 或较大 packet scan 是否能形成有用 prefetch window。 |

## 预期 Codegen 效果

使用 ARM64 forced LLVM path 编译时：

```text
-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=prefetch=force
```

treatment object 应该包含 `bpf_arm64_prfm_pldl1keep`，ARM64 kernel JIT dump
应该包含 native `prfm pldl1keep`。

对应 no-kinsn control 使用同一个 custom `llc`，参数是：

```text
-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable
```

## 当前证据

当前 ARM64 same-LLC attribution 的整体结果是负面的：

- distance sweep geomean treatment/control：`1.00492806`，约 0.49% slower。
- indirect / timeliness geomean treatment/control：`1.00367168`，约 0.37% slower。
- `prefetch_packet_first_deref` 旧实验显示弱 positive，但后续 raw-bytecode 检查发现旧 v1
  主要命中的是 address-source load，不足以证明 final deref prefetch 有收益。
- `prefetch_single_first_deref` 是为 selector v3 新增的 controlled coverage case，用来明确区分
  address-source load 和 final deref。v3 smoke 已确认 x86 和 ARM64 都能对 final deref 应用 1 个
  prefetch site。
- 这些 smoke 结果只证明 selector 行为和 runtime correctness，不证明性能收益。下一步需要对
  packet first-deref 做 multi-run same-LLC attribution。

这些 case 可以支持 research 和 selector v3 设计，但不能支持默认启用 prefetch。
