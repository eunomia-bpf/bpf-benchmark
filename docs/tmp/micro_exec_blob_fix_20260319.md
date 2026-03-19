# micro_exec Blob Fix - 2026-03-19

## Summary

`micro_exec` 的当前源码并没有继续手搓旧 DSL `pattern/constraint/binding` blob。
真正的问题是：

1. `micro_exec` 二进制是旧的，内嵌了旧 scanner/blob-builder 实现。
2. 顶层 `Makefile` 的 `$(MICRO_RUNNER)` 增量依赖没有包含 `scanner/` 源文件。
3. 所以 `scanner` 源码已经切到新格式后，`make vm-micro` / `make vm-micro-smoke` 仍可能继续复用旧 `micro_exec`，导致 `BPF_PROG_JIT_RECOMPILE -> EINVAL`。

额外还发现：

4. 旧的 `vm-micro-smoke` bench 集合不包含一个会真实 `applied=true` 的 benchmark。
5. `load_byte_recompose` 的默认 policy 是空 `sites: []`，因此即使 recompile path 正常，smoke JSON 里也看不到 `applied=true`。

## What I Checked

按要求读了三处：

- `micro/runner/src/kernel_runner.cpp`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
- `scanner/src/pattern_v5.cpp`

结论：

- `kernel_runner.cpp` 当前源码在 `policy-file` / `auto-scan-v5` 路径上直接调用
  `bpf_jit_scanner::build_policy_blob_v5(...)`。
- `scanner/src/pattern_v5.cpp` 当前源码产出的 on-wire blob 是：
  - 32-byte policy header
  - 后跟 `V5RuleWire`，每条 12 byte:
    `{site_start, site_len, canonical_form, native_choice}`
- 当前 kernel parser 也接受这一路径；同一 guest 上 scanner live enumerate/recompile 可以成功。

所以这次故障不是“当前源码里的 `kernel_runner.cpp` 仍在构造旧 DSL blob”，而是“`micro_exec` 旧二进制没有被重新编出来”。

## Proof

### 1. 旧 `micro_exec` 在当前 guest 上失败

目标 benchmark：`cmov_dense`

重编前的单 benchmark probe：

- output: `micro/results/dev/tmp_cmov_dense_probe.json`
- `recompile.policy_bytes = 4504`
- `recompile.applied = false`
- `recompile.error = "BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22)"`

这说明当时跑进去的还是旧 blob 形态。

### 2. 同一 guest 上 scanner live recompile 成功

我把同一个 `cmov_dense.bpf.o` 直接 load 成 live XDP program，
然后用 `scanner/build/bpf-jit-scanner enumerate --prog-id ... --recompile --json` 做对照。

结果：

- `total_sites = 58`
- `applied_sites = 26`
- `recompile_ok = true`

这证明当前 kernel + 当前 scanner blob format 是兼容的。

### 3. 强制重编 `micro_exec` 后立即恢复

执行：

```bash
source /home/yunwei37/workspace/.venv/bin/activate
make -C micro micro_exec
```

然后再次跑同一个 `cmov_dense` probe：

- output: `micro/results/dev/tmp_cmov_dense_probe_after_rebuild.json`
- `recompile.policy_bytes = 344`
- `recompile.applied = true`
- `recompile.error = ""`

`344 = 32-byte header + 26 * 12-byte rules`

这正是当前简化 rule wire format。

## Fix Applied

### A. Fix stale `micro_exec` rebuilds

修改：

- `Makefile`

变更：

- 把 `scanner/src/*.cpp`
- `scanner/include/bpf_jit_scanner/*.hpp`
- `scanner/CMakeLists.txt`

加入 `MICRO_RUNNER_SOURCES`。

效果：

- 以后只要 scanner/blob-builder 源码变化，`$(MICRO_RUNNER)` 就会被视为过期。
- `make vm-micro`
- `make vm-micro-smoke`

都会自动先重编 `micro_exec`，不再复用内嵌旧 blob builder 的旧二进制。

### B. Make smoke actually cover an applied recompile

修改：

- `Makefile`

变更：

- `VM_SMOKE_ARGS` 从
  - `simple + load_byte_recompose`
- 改为
  - `simple + load_byte_recompose + cmov_dense`

原因：

- `load_byte_recompose` 的 policy 是空 `sites: []`
- 它只能验证“policy-file no-op path”
- 不能验证“non-empty policy blob actually applied”

加入 `cmov_dense` 后，`vm-micro-smoke` 会覆盖真实的 `applied=true` 路径。

## Other Blob Builders Checked

我额外检查了其他构造 blob 的地方：

- `scanner/src/pattern_v5.cpp`
  - 当前源码是正确的活跃实现。
- `tests/kernel/test_recompile.c`
  - 仍直接构造 policy blob。
  - 但它当前构造的是与当前 kernel/scanner 一致的 32-byte header + `bpf_jit_rewrite_rule_v2`。
  - 本次 micro smoke 修复不需要改它。
- `micro/tools/directive_hint.c`
  - 构造的是旧 directive blob，不是 `BPF_PROG_JIT_RECOMPILE` policy blob。
  - 与本问题无关。

## Validation

### Required builds

```bash
source /home/yunwei37/workspace/.venv/bin/activate
make -C micro micro_exec
make -C vendor/linux-framework -j"$(nproc)" bzImage
make vm-micro-smoke
```

结果：

- `micro_exec` 编译通过
- `bzImage` 增量构建通过
- `vm-micro-smoke` 通过

### Smoke result after fix

output:

- `micro/results/dev/vm_micro_smoke.json`

关键字段：

- `simple`
  - `applied = false`，预期如此
- `load_byte_recompose`
  - `policy_generated = false`
  - `applied = false`
  - 这是空 policy/no-op，预期如此
- `cmov_dense`
  - `policy_generated = true`
  - `policy_bytes = 344`
  - `syscall_attempted = true`
  - `applied = true`
  - `rotate_sites = 26`
  - `error = ""`

因此：

- `recompile` 不再因为旧 blob 形态返回 `EINVAL`
- smoke 结果中已经恢复可见的 `applied=true`

## Final Takeaway

这次 P0 的可执行修复不是再改一遍 `kernel_runner.cpp` 源码，
而是修正 `micro_exec` 的增量重编依赖，确保它永远跟着 scanner 的 blob-builder 一起更新，
并让 `vm-micro-smoke` 真正覆盖一个非空 policy 的 applied 路径。
