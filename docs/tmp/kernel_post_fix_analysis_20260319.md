# Kernel Post-Fix Analysis (2026-03-19)

## 1. `micro/results/dev/vm_micro.json` 性能分析

统计口径固定为：

- ratio = `median(exec_ns, kernel-recompile) / median(exec_ns, kernel)`
- applied benchmark = `kernel-recompile` run 中任一 sample 满足 `recompile.applied = true`

### 1.1 当前结果

- benchmark 总数：`62`
- applied benchmark：`7`
- overall geomean：`0.9850x`
- applied-only geomean：`0.8174x`
- non-applied geomean：`1.0086x`

### 1.2 所有 applied benchmarks

| benchmark | sites | form | kernel median (ns) | kernel-recompile median (ns) | ratio (kr/k) | old authoritative (kr/k) |
| --- | ---: | --- | ---: | ---: | ---: | ---: |
| `bounds_ladder` | 4 | `cmov=2`, `wide=2` | 276.5 | 232.0 | `0.8391x` | `1.0290x` |
| `bpf_call_chain` | 2 | `wide=2` | 407.5 | 416.0 | `1.0209x` | `1.0357x` |
| `cmov_dense` | 26 | `rotate=26` | 74.0 | 59.0 | `0.7973x` | `0.8696x` |
| `large_mixed_1000` | 7 | `rotate=7` | 1017.0 | 1055.0 | `1.0374x` | `0.9861x` |
| `large_mixed_500` | 7 | `rotate=7` | 635.0 | 586.0 | `0.9228x` | `0.9848x` |
| `rotate64_hash` | 116 | `rotate=116` | 82.5 | 66.0 | `0.8000x` | `0.7456x` |
| `rotate_dense` | 256 | `rotate=256` | 288.5 | 134.5 | `0.4662x` | `0.7188x` |

当前 applied 集合与旧权威文件完全一致：没有新增 applied，也没有移除 applied。

### 1.3 对比旧权威 `micro/results/vm_micro_authoritative_20260318.json`

按同一口径 `kernel-recompile / kernel` 直接重算：

| metric | old authoritative (kr/k) | current dev (kr/k) | change |
| --- | ---: | ---: | ---: |
| overall geomean | `0.9866x` | `0.9850x` | `-0.0016x` |
| applied-only geomean | `0.9011x` | `0.8174x` | `-0.0837x` |
| non-applied geomean | `0.9981x` | `1.0086x` | `+0.0106x` |

解释：

- applied 子集明显更好，主因是 `rotate_dense`、`cmov_dense`、`bounds_ladder` 都比旧权威更快。
- non-applied 子集从 `0.9981x` 变成 `1.0086x`，说明当前 dev run 在未应用 policy 的 benchmark 上略偏慢/偏噪。
- 旧计划文档里写的 `overall 1.024x`、`applied-only 1.110x` 是反向口径 `kernel / kernel-recompile`。
- 如果强行按旧文档的反向口径对齐，当前 dev 分别是 `overall 1.0152x`、`applied-only 1.2234x`、`non-applied 0.9914x`。
- 其中 `applied-only 1.110x` 与 JSON 重算结果一致（精确值 `1.1098x`，取倒数即上表 `0.9011x`）。
- 但 `overall 1.024x` 与 JSON 直接重算不完全一致；该 JSON 的精确值是 `1.0136x` (`kernel / kernel-recompile`)，对应本报告口径 `0.9866x`。

### 1.4 2-insn CMOV site 检查

- 当前唯一带 `cmov_sites = 2` 且实际 applied 的 benchmark 仍然是 `bounds_ladder`。
- 旧权威文件里 `bounds_ladder` 已经是 applied，因此这次 **没有新的 2-insn CMOV applied**。
- 该 case 的 ratio 从旧权威 `1.0290x` 改善到当前 `0.8391x`（同为 `kernel-recompile / kernel` 口径）。
- `cmov_select` 仍然不是 applied，`cmov_sites = 0`。

## 2. 当前 kernel 代码量统计

命令：

```bash
cd vendor/linux-framework
git diff master..HEAD --stat
git diff master..HEAD --numstat
```

说明：

- 当前 `vendor/linux-framework` 分支是 `jit-directive-v5`
- `master...HEAD` 计数为 `0 20`，即相对 `master` ahead `20` commits
- 本节只统计 commit 级差异，不包含当前未提交工作树改动

### 2.1 `master..HEAD` 分文件 added/removed lines

| file | added | removed | net |
| --- | ---: | ---: | ---: |
| `arch/x86/net/bpf_jit_comp.c` | 2374 | 177 | +2197 |
| `include/linux/bpf.h` | 33 | 0 | +33 |
| `include/linux/bpf_jit_directives.h` | 184 | 0 | +184 |
| `include/trace/events/bpf.h` | 85 | 0 | +85 |
| `include/uapi/linux/bpf.h` | 258 | 0 | +258 |
| `kernel/bpf/Makefile` | 1 | 0 | +1 |
| `kernel/bpf/core.c` | 96 | 16 | +80 |
| `kernel/bpf/helpers.c` | 5 | 1 | +4 |
| `kernel/bpf/jit_directives.c` | 3708 | 0 | +3708 |
| `kernel/bpf/syscall.c` | 5 | 0 | +5 |
| `kernel/bpf/verifier.c` | 2 | 0 | +2 |
| `tools/bpf/bpftool/prog.c` | 4 | 0 | +4 |
| `tools/include/uapi/linux/bpf.h` | 4 | 0 | +4 |

### 2.2 总 LOC 变化

- `13` files changed
- `6759` insertions
- `194` deletions
- net LOC change: `+6565`

## 3. Phase A/B/C1/C2 改动前后 diff 大小

当前 Phase A/B/C1/C2 的 kernel 改动还没有单独 commit，因此按你的要求使用：

```bash
cd vendor/linux-framework
git diff --stat
git diff --numstat
```

### 3.1 当前未提交 patch 大小

- `6` files changed
- `692` insertions
- `292` deletions
- net change: `+400`

### 3.2 分文件统计

| file | added | removed | net |
| --- | ---: | ---: | ---: |
| `arch/x86/net/bpf_jit_comp.c` | 62 | 54 | +8 |
| `include/linux/bpf.h` | 26 | 0 | +26 |
| `include/linux/bpf_jit_directives.h` | 13 | 0 | +13 |
| `include/linux/filter.h` | 1 | 0 | +1 |
| `kernel/bpf/core.c` | 5 | 0 | +5 |
| `kernel/bpf/jit_directives.c` | 585 | 238 | +347 |

### 3.3 结论

- Phase A/B/C1/C2 当前工作树 patch 主要集中在 `kernel/bpf/jit_directives.c` 和 `arch/x86/net/bpf_jit_comp.c`。
- 如果之后把这些 phase squash 成一次 commit，那么这组数字就是最接近“改动前后 diff 大小”的当前 patch 规模。
