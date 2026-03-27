# batch_runner diagnostics fix 2026-03-27

## 问题确认

我先读了：

- `daemon/src/server.rs`
- `daemon/src/commands.rs`
- `runner/src/batch_runner.cpp`
- `runner/src/kernel_runner.cpp`

daemon `optimize` 返回的是完整 `OptimizeOneResult`，其中 `passes[]` 已包含：

- `pass_name`
- `changed`
- `sites_applied`
- `sites_skipped`
- `skip_reasons`
- `insns_before`
- `insns_after`
- `insn_delta`
- `diagnostics`

但 runner 端原来只保留了：

- `summary.applied / program_changed / total_sites_applied`
- `program.insn_delta / final_insn_count / final_jited_size`
- `passes_applied`（仅 changed pass 名称）

因此 `skip_reasons` / `diagnostics` 会在 runner 解析阶段被丢掉。

## 实现

只改了 runner 端。

### 1. `runner/src/kernel_runner.cpp`

- 扩展 daemon socket response 解析，新增 `pass_details`
- 从 daemon `passes[]` 提取并保留每个 pass 的：
  - `pass_name`
  - `changed`
  - `sites_found`（runner 端由 `sites_applied + sites_skipped` 推导）
  - `sites_applied`
  - `sites_skipped`
  - `skip_reasons`
  - `diagnostics`
  - `insns_before / insns_after / insn_delta`
- 把这些字段写入 `rejit.pass_details`

结果：

- 即使 batch runner 后续裁掉 `rejit.daemon_response`
- `details/result.json` / `metadata.json` 里仍然能看到稳定的 `rejit.pass_details`

### 2. `runner/src/batch_runner.cpp`

- 扩展 batch daemon response 解析，新增 `pass_details`
- `static_verify_object` 的每个 program record 新增 `daemon_pass_details`
- `daemon_pass_details` 序列化进 payload records

结果：

- batch result JSON 的 static verify `program_records` 现在直接带有 per-pass skip reasons / diagnostics

### 3. `runner/include/micro_exec.hpp` 和 `runner/src/common.cpp`

- 新增共享 `daemon_pass_detail` 结构
- 在 sample JSON 的 `rejit` 对象里新增 `pass_details`

这让 corpus/e2e/micro 复用同一份稳定字段，而不是只能依赖可选的 `daemon_response` 原文。

## 验证

执行：

```bash
make runner
```

结果：

- 编译通过
- `micro_exec` 成功重新链接

## 结果

修复后，runner 输出不再只剩 `"map_inline": 0 hits` 这类摘要；可以在 runner 结果里继续看到该 pass 的：

- `sites_applied`
- `sites_skipped`
- `skip_reasons`
- `diagnostics`

从而直接判断为什么是 0 hits。
