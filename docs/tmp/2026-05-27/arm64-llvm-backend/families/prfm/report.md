# ARM64 PRFM family report

## 结论

`PRFM` family 已完成 design、pass-level coverage exploration、same-corpus control/treatment
和 native JIT evidence。2026-05-27 已补齐 forced LLVM object path，但不进入默认策略。

对应 kfunc：

```text
bpf_arm64_prfm_pldl1keep
```

原因：`PRFM` 是 prefetch hint，不是已有 BPF operation 的等价 replacement。module proof
expansion 是 no-op，所以 runtime correctness 只能证明程序仍正确，不能证明 prefetch 有效。
当前 expanded attribution 仍不是 performance win。

## 设计和证据

设计说明：

```text
/home/ruoji/github/bpf-opt/docs/arm-llvm-backend/families/prfm.md
```

关键 raw 记录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-prefetch-coverage-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-control-codegen-evidence
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-native-jit-dump-fix
/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-expanded-attribution
/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-existing-abi-completion
```

关键结果：

| metric | value |
|---|---|
| corpus workload | `katran/balancer_ingres` |
| prefetch sites | 44 |
| control | `noop`, `sites_applied=0`, `insn_delta=0` |
| treatment | `prefetch,noop`, `sites_applied=44`, `insn_delta=88` |
| BPF-level evidence | `live_xlated.disasm` has 44 aligned kfunc calls |
| native evidence | `live_jited.objdump` has 44 `prfm pldl1keep, [xN]` |
| expanded attribution | `katran` rerun still not performance win; `cilium/agent` aborted at `app_start` |
| forced LLVM object path | local FileCheck / object smoke passed; final combined object smoke has 105 `bpf_arm64_prfm_pldl1keep` relocations |

## 状态判断

`PRFM` 已经有足够证据证明 existing pass 能到达 native PRFM。forced LLVM selector 可用于 ABI
完整性和显式实验，但没有足够证据进入默认策略。

## 后续

保持 PRFM 默认策略 disabled，除非某个 workload 能稳定证明 prefetch benefit。
