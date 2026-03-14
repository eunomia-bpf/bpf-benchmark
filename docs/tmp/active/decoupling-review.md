# 三组件解耦架构实现完成度 Review

Date: 2026-03-13

三组件架构：
- **(A)** 应用程序不修改，正常加载 BPF 程序到内核
- **(B)** BpfReJIT daemon/scanner 从内核枚举 live 程序，分析 + 可选 recompile（`BPF_PROG_GET_NEXT_ID` 路径）
- **(C)** 内核 `BPF_PROG_JIT_RECOMPILE` 验证并 re-JIT

---

## 1. Scanner `enumerate` 子命令

### 1.1 已完成的功能

**文件**: `scanner/src/cli.cpp`，`run_enumerate()` 函数（约 200 行，位于 L602–L851）

| 功能 | 状态 |
|------|------|
| `BPF_PROG_GET_NEXT_ID` 遍历所有 live 程序 | ✅ 已实现 |
| `BPF_PROG_GET_FD_BY_ID` 打开每个程序的 fd | ✅ 已实现 |
| `BPF_OBJ_GET_INFO_BY_FD` ×2 提取 xlated bytecode | ✅ 已实现 |
| `scan_v5_builtin()` 模式匹配（8个 family 全覆盖） | ✅ 已实现 |
| `--json` 输出 JSON 数组 | ✅ 已实现 |
| `--recompile` 模式：对有 site 的程序调用 `BPF_PROG_JIT_RECOMPILE` | ✅ 已实现 |
| `--policy-dir <dir>` 支持：按 `<dir>/<name>.policy.yaml` 过滤 | ✅ 已实现 |
| `--prog-id <id>` 过滤：只扫描指定程序 | ✅ 已实现 |
| 当 `--all` / 无显式 family 时启用全部 8 个 family | ✅ 已实现 |
| 不依赖 `.bpf.o` 文件（纯 live-program 路径） | ✅ 已实现 |

**实际运行验证**（host kernel 6.15.11）：
```
$ sudo scanner/build/bpf-jit-scanner enumerate --json 2>&1 | head -5
Enumerating live BPF programs...
[
  {"prog_id":54,"name":"s_cups_cupsd","type":"cgroup_device","total_sites":1,...},
  ...
]
# 总计：197 个程序，165 个有优化 site
```

`--prog-id` 过滤验证：
```
$ sudo scanner/build/bpf-jit-scanner enumerate --prog-id 84092 --json 2>/dev/null
[
  {"prog_id":84092,"name":"syncookie_xdp","type":"xdp","total_sites":36,"applied_sites":36,"recompile_ok":false}
]
```

### 1.2 Gap：enumerate JSON 输出缺少 per-family site 明细

**关键缺口**：`EnumerateResult` struct（L553–L561）只有：
```cpp
struct EnumerateResult {
    uint32_t prog_id;
    std::string name;
    uint32_t prog_type;
    uint32_t total_sites;      // 总 site 数（无 family 分类）
    uint32_t applied_sites;    // applied 数（无 family 分类）
    bool recompile_ok;
    std::string error;
};
```

JSON 输出（L812–L818）只输出 `total_sites` 和 `applied_sites`，没有 `cmov_sites`、`rotate_sites` 等 per-family 计数。

`scan` 子命令的 `--json` 输出（通过 `build_scan_manifest()`）包含完整的 per-family 明细，但 `enumerate` 不包含。

**影响**：`e2e/common/recompile.py` 中的 `_scan_counts_from_enumerate()` 函数（L406–L419）只能提取 `total_sites`，其余 8 个 family 字段全部置 0：
```python
def _scan_counts_from_enumerate(record):
    total = int(record.get("total_sites", 0) or 0)
    return {
        "total_sites": total,
        "cmov_sites": 0,       # 无法从 enumerate 获取
        "rotate_sites": 0,     # 无法从 enumerate 获取
        ...
    }
```

这导致 E2E 报告中 per-family 明细（`cmov_sites`、`rotate_sites` 等）在 enumerate 路径下始终为 0，需要额外调用 `scan --prog-fd` 才能获取。

### 1.3 Gap：无 daemon 模式

`enumerate` 是一次性扫描（run-to-completion），没有持续监控新加载程序的循环、inotify/BPF perf 触发、程序生命周期追踪等机制。这是已知的设计选择（参见 `docs/tmp/architecture-gap-analysis.md` §3.5），当前架构证明机制，但尚未打包为服务。

---

## 2. E2E Pipeline

### 2.1 已完成的功能

**文件**: `e2e/common/recompile.py`

| 功能 | 状态 |
|------|------|
| `_USE_ENUMERATE_PATH = True`（L21） | ✅ 已启用 |
| `scan_programs()` 优先走 enumerate 路径，失败 fallback 到 legacy | ✅ 已实现 |
| `apply_recompile()` 优先走 enumerate 路径，失败 fallback 到 legacy | ✅ 已实现 |
| `_enumerate_scan_one()` 调用 `scanner enumerate --prog-id --json` | ✅ 已实现 |
| `_enumerate_apply_one()` 调用 `scanner enumerate --prog-id --recompile [--policy-dir]` | ✅ 已实现 |
| `_apply_one_enumerate()` 做 scan→remap→write policy dir→recompile 完整流程 | ✅ 已实现 |
| fallback 到 legacy `scan --prog-fd` / `apply --prog-fd` 路径 | ✅ 已实现 |
| tracee / tetragon / bpftrace / xdp_forwarding case 都通过公共 `scan_programs`/`apply_recompile` API | ✅ 已验证 |

### 2.2 enumerate 路径的完整程度

enumerate 路径在 **scan** 操作上是完全解耦的（不需要调用方持有 fd）。

在 **apply** 操作（`_apply_one_enumerate()`，L570–L722）上有一个重要的混合：
- 对于 `blind_apply` 模式：完全使用 enumerate path，不需要 fd
- 对于 `policy-file` 模式（需要 remap）：需要 `_scan_live_manifest()` 获取 per-site 详情，而 `_scan_live_manifest()` 仍然调用 `scan --prog-fd`（需要调用方持有 fd）

**原因**：enumerate JSON 只输出 `total_sites`（无 per-site 坐标），而 `remap_policy_v3_to_live()` 需要完整的 per-site manifest（insn 偏移、family、pattern_kind）。因此 policy remap 仍需 `scan --prog-fd` 路径。

这是一个**设计层面的 gap**：如果 `enumerate` 提供 per-site 详情，policy-file 路径也可以完全解耦。

### 2.3 各 E2E case 的使用情况

| Case | 使用 scan_programs / apply_recompile | enumerate 路径激活 |
|------|--------------------------------------|-------------------|
| tracee | ✅（case.py L726, L824） | ✅（`_USE_ENUMERATE_PATH=True`） |
| tetragon | ✅（case.py L1038, L1039, L1108, L1109） | ✅ |
| bpftrace | ✅（case.py L474, L501） | ✅ |
| xdp_forwarding | ✅（case.py L1127, L1128） | ✅ |

---

## 3. Corpus Pipeline

### 3.1 corpus v5 framework（`_driver_impl_run_corpus_v5_framework.py`）

这个 driver 使用 `build_run_kernel_command()` → `micro_exec run-kernel --recompile-v5`，**内置式 inline recompile**（程序在 micro_exec 内部加载并 recompile），**不依赖 enumerate 路径**。

这不是解耦架构——micro_exec 对程序做 load + scan + apply 三合一，应用程序不是"自然加载"的独立进程。

### 3.2 macro corpus driver（`_driver_impl_run_macro_corpus.py`）

**attach_trigger + compile_only(bpftool_loadall) 路径**：通过 `apply_recompile_v5()` 函数（L688–L733）调用：
```python
command = [str(scanner_binary), "apply", "--prog-fd", str(fd), "--all", "--v5", ...]
```
这是 **legacy `apply --prog-fd` 路径**，不使用 enumerate。用 libbpf 获取 fd，传给 scanner。

**compile_only(micro_exec) + bpf_prog_test_run 路径**：通过 micro_exec 内联，同样不使用 enumerate。

### 3.3 generate_default_policies.py / directive_census.py

这些 corpus 工具对 `.bpf.o` 文件做 offline 扫描（`scanner scan <file.bpf.o>`），**完全是 object-file 路径**，与解耦架构无关（它们是 policy 生成工具，不是运行时路径）。

### 3.4 Corpus pipeline 是否是 gap？

**结论**：corpus pipeline 目前不用 enumerate 路径，属于预期的设计选择：

- corpus 用 `.bpf.o` 文件做 compile-only 或 test_run，属于受控的"框架加载"场景，不是真实应用程序场景
- 真实解耦场景（应用程序自己加载）的测试通过 E2E pipeline（tracee/tetragon 等）完成
- macro corpus 的 attach_trigger 路径确实实现了"应用先加载，然后 scanner 介入"的模式，但用的是 legacy `apply --prog-fd` 而非 `enumerate --prog-id`

**可选改进**（非必须）：macro corpus 的 `apply_recompile_v5()` 可以切到 `enumerate --prog-id --recompile` 路径，彻底不需要 libbpf 依赖，但当前 legacy 路径功能正确。

---

## 4. 仍依赖 .bpf.o 的地方

### 4.1 必要的 .bpf.o 依赖（合理存在）

| 位置 | 用途 | 是否合理 |
|------|------|---------|
| `corpus/generate_default_policies.py` | 离线生成 policy YAML | ✅ 合理（只做一次） |
| `corpus/directive_census.py` | 静态 census，不是运行时 | ✅ 合理 |
| `corpus/analyze_bytecode.py` | 静态分析 | ✅ 合理 |
| `corpus/run_code_size_comparison.py` | 代码大小对比 | ✅ 合理 |
| `e2e/run_e2e_tracee.py`（DEFAULT_OBJECT） | Tracee 没有 daemon 时 fallback | ✅ 合理（fallback） |
| `e2e/cases/tetragon/case.py`（DEFAULT_EXECVE_OBJECT 等） | Tetragon fallback | ✅ 合理（fallback） |
| `e2e/cases/xdp_forwarding/case.py`（DEFAULT_XDP_OBJECT） | 加载 XDP 程序 | ✅ 合理（XDP 需要 obj 才能 attach） |

### 4.2 非必要或可改进的依赖

| 位置 | 用途 | 建议 |
|------|------|------|
| `corpus/_driver_impl_run_macro_corpus.py` → `apply_recompile_v5()` | 用 `apply --prog-fd` 而非 `enumerate --prog-id` | 可选改进：切到 enumerate 路径 |
| `e2e/common/recompile.py` → `_scan_live_manifest()` | policy remap 时调用 `scan --prog-fd` | 受 enumerate 缺少 per-site 输出限制 |

---

## 5. 缺失的功能汇总

### 5.1 enumerate per-family site breakdown（中优先级）

**现状**：`enumerate --json` 输出只有 `total_sites`，无 per-family 计数。

**影响**：
- E2E scan 结果的 `cmov_sites`/`rotate_sites` 等字段在 enumerate 路径下全为 0
- 无法在 enumerate 模式下做 per-family 分析

**修复**：在 `EnumerateResult` struct 增加 8 个 family 字段，在 JSON 输出中包含它们（约 20 行 C++ 改动）。

### 5.2 enumerate 无 per-site 详情输出（中优先级）

**现状**：`enumerate --json` 只有 `total_sites`，没有逐 site 的 `{insn, family, pattern_kind}` 列表。

**影响**：`_apply_one_enumerate()` 中 policy-file 模式仍需 fallback 到 `scan --prog-fd` 获取 per-site manifest 做 remap。

**修复**：让 enumerate 在 `--json` 时可选输出 per-site 列表（`--per-site` flag，类似 `scan --json --per-site`）。这使 policy-file 路径完全不需要 `--prog-fd`。

### 5.3 daemon 模式（低优先级，超出当前 paper scope）

**现状**：enumerate 是一次性运行，没有持续循环、新程序发现、生命周期管理。

**缺失的 daemon 行为**（参见 `docs/tmp/architecture-gap-analysis.md §3.5`）：
- 持续轮询/事件驱动发现新加载程序
- 追踪已处理程序（避免重复 recompile）
- 程序卸载检测与 policy 撤销
- 中央化 metrics 与回滚

**当前设计**：paper 将 E2E pipeline（每次测量时调用 scanner）作为 "daemon prototype" 的实验替代，不要求真正的长驻进程。

### 5.4 enumerate 路径中 policy-file apply 仍需 fd（设计级 gap）

**现状**：`_apply_one_enumerate()` 的 policy-file 分支（L598–L657）中：
1. 调用 `_enumerate_scan_one()` 获取 live summary（无需 fd，✅）
2. 获取 fd，调用 `_scan_live_manifest()` 获取 per-site manifest（需要 fd，legacy scan 路径）
3. 调用 `_enumerate_apply_one()` 做 recompile（无需 fd，✅）

步骤 2 仍需要 caller-held fd，只有在 enumerate 支持 per-site 输出后才能去掉。

---

## 6. 总结

### 已完全完成

- Scanner `enumerate` 子命令：功能完整，实测 OK（197 progs，165 with sites）
- `--recompile` 模式：实现完整，包含 memfd+seals+`BPF_PROG_JIT_RECOMPILE` 完整流程
- `--policy-dir` 支持：实现完整（按 `<dir>/<name>.policy.yaml` 查找）
- `--prog-id` 过滤：实现完整
- 不依赖 `.bpf.o`：纯 live-program 路径（`BPF_PROG_GET_NEXT_ID` → `BPF_PROG_GET_FD_BY_ID` → `BPF_OBJ_GET_INFO_BY_FD` → scan → recompile）
- E2E pipeline `_USE_ENUMERATE_PATH = True`，所有 case（tracee/tetragon/bpftrace/xdp_forwarding）走公共 API
- `scan_programs()` 和 `apply_recompile()` 都优先用 enumerate 路径，有 fallback

### 仍有 gap 的地方

| Gap | 优先级 | 影响 |
|-----|--------|------|
| enumerate JSON 缺少 per-family site counts | 中 | E2E 报告中 per-family 字段全为 0 |
| enumerate JSON 缺少 per-site list | 中 | policy-file 路径仍需额外 `scan --prog-fd` 调用（fallback，非错误） |
| corpus macro driver 用 legacy `apply --prog-fd` | 低 | 功能正确，只是没走最新路径 |
| daemon 模式（持续监控） | 低/不适用 | 超出当前 paper 展示范围 |

### 建议的下一步

1. **在 `EnumerateResult` struct 中加入 8 个 per-family 计数字段**（`cmov_sites`、`rotate_sites` 等），并在 JSON 输出中包含它们。约 30 行 C++ 改动，使 `_scan_counts_from_enumerate()` 能直接提取完整 per-family 数据。

2. **评估是否需要 `--per-site` 输出**（即在 enumerate JSON 中包含每个 site 的 `{insn, family, pattern_kind}`）。这是使 policy-file 路径完全解耦的前提。当前 fallback 工作正常，优先级视 paper 需求而定。

3. **Corpus pending tasks（不阻塞解耦架构验证）**：corpus macro driver 和 corpus v5 framework 不走 enumerate 路径是已知设计，不是 bug。如果需要，可将 `apply_recompile_v5()` 切换到 `enumerate --prog-id --recompile` 路径，去掉 libbpf 依赖。
