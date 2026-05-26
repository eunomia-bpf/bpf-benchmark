# ARM64 CSEL coverage/correctness gate

日期：2026-05-25。

## 结论

本 gate 已完成。

这次验证的是 ARM64 `CSEL` family 第一版 selector 的覆盖和正确性，不是性能实验。

结果：

- 原始 29 个 micro benchmark object 仍然没有命中第一版 CSEL selector。
- 新增 selected target `csel_select64` 后，CSEL treatment object 命中 1 个
  `bpf_arm64_tst` 和 1 个 `bpf_arm64_csel_ne`。
- same-LLC `all=disable` control 没有任何 ARM64 / x86 kfunc symbol。
- AWS ARM64 `native` 和 `kernel` runtime 都返回 expected result
  `15327322346016019187`。
- Kernel JIT code compare 中出现 `tst` / `csel` native instruction，说明 module lowering
  path 实际执行到了 ARM64 `CSEL`。

## 背景

ARM LLVM backend 不是新增 AArch64 object backend。LLVM 仍然输出 BPF object，只是在
LLVM BPF backend 中把特定 BPF MachineInstr pattern 换成 ARM64 kinsn request：

```text
BPF MachineInstr pattern
  -> ARM64 kinsn pseudo
  -> KINSN_SIDECAR + KINSN_CALL bpf_arm64_*
  -> verifier proof expansion
  -> ARM64 module native lowering
```

`CSEL` 第一版只支持这个 selected-safe pattern：

```text
dst = (cond_reg != 0) ? true_reg : false_reg
```

也就是 LLVM BPF `Select_Ri` 中 rhs immediate 是 `0`、condition 是 `SETNE` 或
`SETEQ`、selected value 是 64-bit register。

## 代码改动

代码仓库：

```text
/home/ruoji/github/bpf-opt/code
```

新增 selected coverage benchmark：

- `micro/programs/csel_select64.bpf.c`
- `micro/programs/csel_select64.md`
- `runner/libs/input_specs.yaml`
- `micro/config/micro_pure_jit.yaml`

Benchmark 语义：

```text
cond0 = read_u64(data, 0)
cond1 = read_u64(data, 8)
truev = read_u64(data, 16)
falsev = read_u64(data, 24)
first = cond0 ? truev : falsev
second = cond1 ? falsev : truev
out = first ^ rotl64(second, 13)
```

固定 input generator 是 `plain_bytes count=64`，expected result 是：

```text
15327322346016019187
```

## 结果

Object coverage：

```text
case                objects  arm64_tst  arm64_csel_ne  arm64_symbols  x86_symbols
arm64-all-disable   1        0          0               0              0
arm64-csel          1        1          1               2              0
```

Runtime correctness：

```text
benchmark       runtime  samples  result                retval  exec_ns  compile_ns  status
csel_select64   native   1        15327322346016019187  2       4        1484001     pass
csel_select64   kernel   1        15327322346016019187  2       28       16528868    pass
```

Kernel JIT ASM 证据：

```text
tst  x2, x2
csel x2, x3, x4, ne
tst  x1, x1
csel x1, x4, x3, ne
```

## AWS 成本

```text
instance_id          instance_type  region     state       wall_seconds  wall_hours  ec2_cost_usd  ebs_cost_usd  total_cost_usd
i-06d91d59006501c44 t4g.small      us-east-1 terminated  361           0.100278    0.00168467   0.00035654   0.00204121
```

价格口径是 EC2 `t4g.small` Linux on-demand `$0.0168/hour` 加 gp3 volume usage
`$0.08/GB-month`，不含折扣、税、data transfer、free tier、credits、Savings Plans 或
Reserved Instances。

## 数据

摘要数据在：

```text
code/docs/tmp/2026-05-25/arm64-llvm-backend/csel-coverage-correctness-gate/analysis
```

完整本地实验记录在：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-csel-coverage-correctness-gate
```

## 限制

- 这次只证明 selected coverage target 正确，不证明原始 29 个 micro 有 CSEL coverage。
- 这次没有做 performance attribution。
- `llvmbpf` userspace runtime 仍不支持 `bpf_arm64_*` extern，所以 AWS treatment 只跑
  `RUNTIMES="native kernel"`。

## 下一步

下一步是 CSEL same-LLC performance attribution 和 combined regression：

- same-LLC control：custom `llc` + `all=disable`
- CSEL-only treatment：custom `llc` + `all=disable` + `cmov=force`
- combined treatment：`REV+EXTR+UBFM+LDR_X+LDRH+LDR_W+CSEL`
