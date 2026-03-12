# CMOV Emitter Correctness Fix

## Summary

- `cmov` wrong-code / crash 的根因是：scanner 已把 `COND_SELECT` 扩展到 guarded-update、switch-chain、带 non-fallthrough join/backedge 的 widened patterns，但 x86 `emit_canonical_select()` 仍把所有 canonical `COND_SELECT` 都当成 simple `cmp + cmov + fallthrough`。
- 这会导致两类错误：
  - simple guarded-update site 上，条件真/假的语义被解释错；
  - broader site 上，site body 里的 ALU 和显式 join/backedge 分支被直接丢掉。
- 另外，`mixed_alu_mem extract@228` 是独立于 `cmov` 的问题：
  - 该 site 是 cross-register bitfield extract（`dst != src`）。
  - BMI1 `BEXTR` fast path 在这条路径上不稳定；保守回退到 `mov + shift + and` 后恢复正常。

## Root Cause By Site

- `binary_search cmov@152`
  - guarded-update with join，不是 simple compact/diamond。
  - 原 emitter 把 branch body 当成纯 select value，丢掉了 body 计算和 join control-flow。
- `switch_dispatch cmov@50`
  - site_len = 6，是 switch-chain fragment。
  - 原 emitter 只保留最后的 compare/select，不保留中间 dispatch CFG。
- `branch_dense cmov@152`
  - guarded-update + backward join。
  - 原 emitter 发出 plain `cmov` 后，loop latch edge 消失。
- `bpf_call_chain cmov@85`
  - 与 `branch_dense` 同类，也是 guarded-update + backward join。
- `bounds_ladder cmov@144`
  - body 含 `rsh/xor/mov`，不是纯 select。
- `bounds_ladder cmov@152`
  - body 含 `lsh/xor/mov`，且带 backward join；原 emitter 删除该 edge 后会直接把 VM 打死。
- `mixed_alu_mem extract@228`
  - exact `mov + rsh + and` shape，但为 cross-register extract。
  - 保守禁用这条路径上的 BMI1 fast path 后不再 crash。

## Code Changes

### 1. `COND_SELECT` fail-close 到 x86 真正支持的 shape

- [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c#L1471)
  - `emit_canonical_select()` 不再只依赖 canonical params。
  - 现在直接按原始 BPF site 判断，只接受两种旧 emitter 本来就支持的形式：
    - diamond: `jcc, mov_false, ja, mov_true`
    - compact: `mov_true, jcc, mov_false`
  - 其它 widened `COND_SELECT` site 返回 `-EOPNOTSUPP`，回退 stock emission。
- [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c#L3927)
  - `bpf_jit_try_emit_rule()` 现在把原始 insn window 和 local `site_len` 传给 `emit_canonical_select()`。

### 2. 重新启用 canonical-site validation

- [`vendor/linux-framework/kernel/bpf/jit_directives.c`](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/kernel/bpf/jit_directives.c#L2129)
  - `bpf_jit_validate_canonical_site()` 现在对：
    - `BPF_JIT_CF_COND_SELECT` 调用 `bpf_jit_validate_cond_select_rule()`
    - `BPF_JIT_CF_BITFIELD_EXTRACT` 调用 `bpf_jit_validate_bitfield_extract_rule()`
  - 这样 scanner 送入的 canonical rule 不仅参数合法，还必须与 kernel 当前 emitter 支持的原始 BPF shape 一致。

### 3. 收紧 cross-register extract 的 BMI1 fast path

- [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`](/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/net/bpf_jit_comp.c#L3771)
  - BMI1 `BEXTR` fast path 现在只用于 in-place extract（`src == dst`）。
  - `dst != src` 的 extract 统一退回 `mov + shift + and`。
  - 这修掉了 `mixed_alu_mem extract@228` 的 runtime crash，同时保留了 `extract@73` 的 fast path。

## Validation

### Build

```bash
make -C vendor/linux-framework -j$(nproc) bzImage
```

### VM run

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage --memory 4G --cpus 2 --exec '
  cd /home/yunwei37/workspace/bpf-benchmark &&
  python3 micro/run_micro.py --runtime kernel --runtime kernel-recompile \
    --bench binary_search --bench switch_dispatch --bench branch_dense \
    --bench bpf_call_chain --bench bounds_ladder --bench mixed_alu_mem \
    --iterations 1 --warmups 0 --repeat 5
'
```

Observed results:

| Benchmark | Kernel result | Kernel-recompile result | Status |
| --- | ---: | ---: | --- |
| `binary_search` | `126` | `126` | ok |
| `switch_dispatch` | `16` | `16` | ok |
| `branch_dense` | `15654347328787340782` | `15654347328787340782` | ok |
| `bpf_call_chain` | `17813494880153753973` | `17813494880153753973` | ok |
| `bounds_ladder` | `8686050057216939920` | `8686050057216939920` | ok |
| `mixed_alu_mem` | `5008154085265630854` | `5008154085265630854` | ok |

No result mismatches remained.
No VM crash remained.

## Policy Cleanup

Current micro policies are `default: apply` for:

- [`micro/policies/binary_search.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/binary_search.yaml)
- [`micro/policies/switch_dispatch.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/switch_dispatch.yaml)
- [`micro/policies/branch_dense.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/branch_dense.yaml)
- [`micro/policies/bpf_call_chain.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/bpf_call_chain.yaml)
- [`micro/policies/bounds_ladder.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/bounds_ladder.yaml)
- [`micro/policies/mixed_alu_mem.yaml`](/home/yunwei37/workspace/bpf-benchmark/micro/policies/mixed_alu_mem.yaml)

这移除了此前 `bounds_ladder` / `mixed_alu_mem` 的 per-site skip workaround，也让 `binary_search` / `switch_dispatch` / `branch_dense` / `bpf_call_chain` 不再需要 fail-close policy 掩盖 kernel 端 bug。
