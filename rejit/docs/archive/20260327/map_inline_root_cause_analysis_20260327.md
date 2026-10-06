# map_inline root cause analysis (2026-03-27)

## 结论摘要

- `map_inline` 在 `vm-corpus` 的 serve 模式里是会被调用的，不是“根本没跑到”。
- `prog_id`、`map_ids`、`MapInfoAnalysis`、`PassManager` 这条 serve-mode 链路是通的；`map_ids` 来自 live kernel `BPF_OBJ_GET_INFO_BY_FD`，不是 ELF，也不是 `GET_ORIGINAL` 返回值。
- 当前 `vm-corpus` 成功加载并送进 daemon 的程序，几乎都不是 `katran` 那种“常量 key + 只读固定偏移 scalar load”的 map-lookup 形态。它们大多是：
  - 动态 key 的 hash lookup，例如 `pid`/`tid`/`rq`/`req`/`sport`/`hkey`
  - `lookup_or_try_init` / `lookup + update`
  - 取回 map value 指针后继续写字段、做 pointer-style state mutation，而不是只做固定偏移标量 load
- 因此 `map_inline` 的主导失败点是 `try_extract_constant_key()`，对应 `daemon/src/passes/map_inline.rs:214-242`，skip reason 为 `lookup key is not a constant stack materialization`。
- `bpf_map_lookup_elem_by_id()` 在当前 corpus 的主路径里并不是根因，因为大部分 site 在到达这一步之前就已经因为“key 不是常量”而被跳过了。
- zero-value map 不是问题本身：全零 value 不会被 pass 主动 veto。对 array/percpu-array，只要 kernel lookup 成功返回 value bytes，就可以 inline 成常量 0；对 hash miss，则 `bpf_map_lookup_elem_by_id()` 会直接报错并 skip。
- 目前 corpus 结果里看不到 `pass_details` / `skip_reasons`，不是因为 daemon 没产出，而是因为 batch/guest 路径把这些信息丢掉了。

## 1. 根因分析

### 1.1 `map_inline` 确实会在 serve 模式下执行

1. daemon 默认 pipeline 包含 `map_inline`
   - `daemon/src/passes/mod.rs:64-70` 把 `map_inline` 放进 `PASS_REGISTRY`
   - `daemon/src/passes/mod.rs:239-247` 的 `build_full_pipeline()` 会把所有默认 pass 加进 `PassManager`
   - `daemon/src/commands.rs:152-155` 的 `build_pipeline()` 直接调用 `passes::build_full_pipeline()`

2. serve handler 会把请求里的 `prog_id` 原样传到 `try_apply_one()`
   - `daemon/src/server.rs:147-165`

3. `try_apply_one()` 每次 optimize 都会构造 `BpfProgram` 并运行 pipeline
   - `daemon/src/commands.rs:661-662` 通过 `prog_id` 打开 live program fd
   - `daemon/src/commands.rs:662` 读取 `GET_ORIGINAL` bytecode
   - `daemon/src/commands.rs:741` 读取 live `map_ids`
   - `daemon/src/commands.rs:751-753` 构造 `BpfProgram`，`set_map_ids(map_ids)`，然后 `pm.run(&mut program, &local_ctx)?`

4. `MapInlinePass::run()` 本身无条件取 `MapInfoAnalysis`
   - `daemon/src/passes/map_inline.rs:153-154`
   - `daemon/src/pass.rs:242-250` 中 `AnalysisCache::get()` 会在 cache miss 时真实执行 analysis

结论：在成功走到 daemon optimize 的程序上，`map_inline` 是执行的；0 hits 不是“pass 未注册”或“server 没传 `prog_id`”。

### 1.2 serve 模式的 map metadata 链路是正确的

1. `GET_ORIGINAL` 只负责拿 original insns，不负责 map IDs
   - `daemon/src/bpf.rs:792-805`

2. `map_ids` 单独来自 live kernel `BPF_OBJ_GET_INFO_BY_FD`
   - `daemon/src/bpf.rs:819-871`

3. `BpfProgram::set_map_ids()` 会把 `map_ids` 挂到程序对象上，并建立 `old_fd -> map_id` 绑定表
   - `daemon/src/pass.rs:105-108`
   - `daemon/src/pass.rs:178-203`

4. `MapInfoAnalysis` 使用的正是 `program.insns + program.map_ids + program.map_fd_bindings`
   - `daemon/src/analysis/map_info.rs:117-123`
   - `daemon/src/analysis/map_info.rs:141-205`

5. live map info 解析来自 `bpf_map_get_info_by_id()`
   - `daemon/src/analysis/map_info.rs:208-218`
   - `daemon/src/bpf.rs:512-523`

结论：`MapInfoAnalysis` 在 serve 模式里不是从 ELF 猜 map，也不是从 `GET_ORIGINAL` 拿 map IDs；它依赖 live kernel 的 `map_ids`，这条实现链本身没有问题。

### 1.3 当前 corpus 的真实 root cause：没有符合 `map_inline` 约束的 site

`map_inline` 当前只优化很窄的一类 site：

- helper 必须是 `bpf_map_lookup_elem()`，见 `daemon/src/passes/map_inline.rs:76-96`
- key 必须能被逆推出“常量栈物化”，见 `daemon/src/passes/map_inline.rs:214-242`
- lookup result 的使用必须是“固定偏移 scalar loads”，见 `daemon/src/passes/map_inline.rs:261-290`

而 2026-03-27 最新 corpus 结果 `runner/corpus/results/vm_corpus_20260327_040944/details/result.json` 中：

- 一共 117 个 `program_records`
- 其中只有 37 个 `rejit_compile.ok == true`
- compile/run pass 统计只有 `const_prop` / `dce` / `extract` / `endian_fusion` / `cond_select`
- `map_inline` 命中数为 0

我进一步对这 37 个成功程序对应的 11 个对象源码做了静态扫描：

1. 直接 `bpf_map_lookup_elem()` 的 key 全是 runtime 变量，不是常量
   - `runner/repos/bcc/libbpf-tools/bindsnoop.bpf.c:73`，key=`tid`
   - `runner/repos/bcc/libbpf-tools/bindsnoop.bpf.c:86`，key=`sport`
   - `runner/repos/bcc/libbpf-tools/biolatency.bpf.c:109`，key=`rq`
   - `runner/repos/bcc/libbpf-tools/biolatency.bpf.c:126`，key=`hkey`
   - `runner/repos/bcc/libbpf-tools/biosnoop.bpf.c:103`，key=`rq`
   - `runner/repos/bcc/libbpf-tools/biosnoop.bpf.c:175`，key=`rq`
   - `runner/repos/bcc/libbpf-tools/biosnoop.bpf.c:181`，key=`rq`
   - `runner/repos/bcc/libbpf-tools/biostacks.bpf.c:52`，key=`rq`
   - `runner/repos/bcc/libbpf-tools/biostacks.bpf.c:78`，key=`rq`
   - `runner/repos/bcc/libbpf-tools/biotop.bpf.c:86`，key=`req`
   - `runner/repos/bcc/libbpf-tools/biotop.bpf.c:100`，key=`req`
   - `runner/repos/bcc/libbpf-tools/bitesize.bpf.c:56`，key=`hkey`
   - `runner/repos/bcc/libbpf-tools/bitesize.bpf.c:59`，key=`hkey`
   - `runner/repos/bcc/libbpf-tools/drsnoop.bpf.c:69`，key=`pid`
   - `runner/repos/bcc/libbpf-tools/execsnoop.bpf.c:64`，key=`pid`
   - `runner/repos/bcc/libbpf-tools/execsnoop.bpf.c:131`，key=`pid`

2. 另外一些成功对象根本没有 direct `bpf_map_lookup_elem()`，或者只有 `bpf_map_lookup_or_try_init()`，且 key 仍然是 runtime 值
   - `runner/repos/bcc/libbpf-tools/biopattern.bpf.c:43`，`lookup_or_try_init(&counters, &dev, &zero)`
   - `runner/repos/bcc/libbpf-tools/cpufreq.bpf.c:78`，`lookup_or_try_init(&hists, &hkey, &zero)`
   - `runner/repos/bcc/libbpf-tools/cachestat.bpf.c:11-90`，没有 `bpf_map_lookup_elem()`

3. 很多 site 即便“假设 key 是常量”，也仍不符合“只做固定偏移 scalar load”的 use-shape
   - `execsnoop` 在 `runner/repos/bcc/libbpf-tools/execsnoop.bpf.c:64-111` 中拿到 `event*` 后持续写字段
   - `biosnoop` 在 `runner/repos/bcc/libbpf-tools/biosnoop.bpf.c:103-119` 中拿到 `stage*` 后更新字段再写回 map
   - `biolatency` 在 `runner/repos/bcc/libbpf-tools/biolatency.bpf.c:126-141` 中拿到 `hist*` 后做计数更新

因此当前 corpus 的真实问题不是“serve mode 读不到 map value”，而是“benchmark 中几乎没有 `map_inline` 设计目标那种 site”。dominant skip 会落在：

- `daemon/src/passes/map_inline.rs:214-242`
- skip reason: `lookup key is not a constant stack materialization`

### 1.4 `bpf_map_lookup_elem_by_id()` 不是当前 0-hit 的主因

`bpf_map_lookup_elem_by_id()` 只有在以下条件都满足后才会被调用：

- 找到了 helper lookup site
- `MapInfoAnalysis` 能解析出 map info
- `try_extract_constant_key()` 成功
- use-shape 至少包含 fixed scalar loads

真正调用发生在：

- `daemon/src/passes/map_inline.rs:498-531`

但当前 corpus 里的大多数成功 site 在 `daemon/src/passes/map_inline.rs:214-242` 就已经因为 dynamic key 被 skip，所以根本不会走到 `bpf_map_lookup_elem_by_id()`。

### 1.5 zero-value maps 能不能 inline？

可以，但要区分 map 类型。

1. pass 本身没有“全零 value 禁止 inline”的逻辑
   - `daemon/src/passes/map_inline.rs:532-580` 只是把读出来的 bytes 切成标量并替换 load
   - `daemon/src/passes/map_inline.rs:662-672` 中 `emit_constant_load()` 可以正常发出 `mov64_imm(..., 0)`

2. serve 模式下没有 offline/test fallback；生产代码只做 live syscall
   - `daemon/src/bpf.rs:582-603`
   - 非 test build 下，`bpf_map_lookup_elem_by_id()` 直接做 `BPF_MAP_GET_FD_BY_ID + BPF_MAP_LOOKUP_ELEM`

3. 对 miss 的行为是“报错”，不是 optional
   - `daemon/src/bpf.rs:525-547` 的 `bpf_map_lookup_elem()` 出错直接 `bail!`
   - 虽然有 `bpf_map_lookup_elem_optional()`（`daemon/src/bpf.rs:549-579`），但 `map_inline` 并没有用它

4. test-only mock 会为 ARRAY / PERCPU_ARRAY 合成缺省零值
   - `daemon/src/bpf.rs:661-683`
   - 这是 `#[cfg(test)]` 行为，不是 serve mode fallback

结论：

- zero-valued `ARRAY` / `PERCPU_ARRAY`：如果 live lookup 成功返回全零 bytes，可以 inline
- “map 建了但没数据”的 `HASH`：lookup miss 会变成 error，最终在 `map_inline` 里被记成 `map lookup failed: ...`

但这不是当前 corpus 0 hits 的主因，因为当前 corpus 主要卡在“key 不是常量”之前。

## 2. `map_inline` 在 corpus serve 模式下的完整执行路径

1. guest 模式启动常驻 daemon
   - `corpus/modes.py:548-558`
   - 实际命令只有 `bpfrejit-daemon serve --socket <path>`，stdout/stderr 都被重定向到 `DEVNULL`

2. guest batch 为所有 `kernel-rejit` job 注入 `daemon_socket`
   - `corpus/modes.py:739-740`
   - `corpus/modes.py:921-950`
   - `corpus/modes.py:953-993`
   - `corpus/modes.py:1818-1829`

3. C++ batch runner 加载 live program，读取 `prog_id`，并通过 socket 发 optimize 请求
   - `runner/src/batch_runner.cpp:1341-1367`
   - 请求体是 `{\"cmd\":\"optimize\",\"prog_id\":<id>}`，见 `runner/src/batch_runner.cpp:612-613`

4. daemon serve handler 收到请求后调用 `try_apply_one(prog_id, ...)`
   - `daemon/src/server.rs:147-165`

5. `try_apply_one()` 从 live kernel 取 original insns 与 map IDs
   - `daemon/src/commands.rs:661-662`
   - `daemon/src/bpf.rs:792-805`：`GET_ORIGINAL`
   - `daemon/src/commands.rs:741`
   - `daemon/src/bpf.rs:819-871`：`nr_map_ids/map_ids`

6. `BpfProgram::set_map_ids()` 建立 `map_fd_bindings`
   - `daemon/src/commands.rs:751-753`
   - `daemon/src/pass.rs:105-108`
   - `daemon/src/pass.rs:178-203`

7. pipeline 执行 `MapInlinePass`
   - `daemon/src/commands.rs:760-772`
   - `daemon/src/passes/mod.rs:239-247`
   - `daemon/src/passes/map_inline.rs:147-154`

8. `MapInfoAnalysis` 被 `AnalysisCache::get()` 触发执行
   - `daemon/src/pass.rs:242-250`
   - `daemon/src/analysis/map_info.rs:117-123`
   - `daemon/src/analysis/map_info.rs:169-177`
   - `daemon/src/analysis/map_info.rs:208-218`

9. 对每个 lookup site，`map_inline` 执行：
   - 识别 helper site：`daemon/src/passes/map_inline.rs:76-96`
   - 提取常量 key：`daemon/src/passes/map_inline.rs:214-242`
   - 分析 `r0` uses：`daemon/src/passes/map_inline.rs:261-290`
   - 读取 live map value：`daemon/src/passes/map_inline.rs:498-531`
   - 生成替换常量 load：`daemon/src/passes/map_inline.rs:570-580`

10. 结果通过 JSON 返回给 runner
    - `daemon/src/server.rs:152-158`

## 3. 每个 skip 条件的分析

以下按 `MapInlinePass::run()` / `build_site_rewrite()` 的真实代码路径列出。

| skip 条件 | 代码位置 | 含义 | 对当前 corpus 的相关性 |
| --- | --- | --- | --- |
| `map reference metadata unavailable` | `daemon/src/passes/map_inline.rs:167-175` | helper site 识别到了，但 `MapInfoAnalysis` 没能在 `map_load_pc` 找到对应 map ref | 不是当前主因；serve-mode `map_ids` 链路正常 |
| `map info unavailable` | `daemon/src/passes/map_inline.rs:180-184` | 找到了 map ref，但 live `map_id -> map_info` 解析失败 | 不是当前主因；当前 0-hit 更早卡在 key 常量性 |
| `map type X not inlineable in v1` | `daemon/src/passes/map_inline.rs:195-212` | 只允许 direct-value-access map；`PERCPU_HASH` / `LRU_PERCPU_HASH` / `PERF_EVENT_ARRAY` 等不支持 | 可能会发生，但不是当前主因；成功对象里更常见的是 dynamic-key hash |
| `lookup key is not a constant stack materialization` | `daemon/src/passes/map_inline.rs:214-242` | `try_extract_constant_key()` 失败 | **当前 corpus 的主导根因** |
| `key width < map key size` | `daemon/src/passes/map_inline.rs:244-251` | 栈上常量宽度不足以覆盖 map key | 当前未见证据 |
| `constant key out of range for max_entries` | `daemon/src/passes/map_inline.rs:252-259` | array/percpu-array 的常量下标越界 | 当前未见证据 |
| `speculative map inline requires an immediate null check` | `daemon/src/passes/map_inline.rs:267-271` | 对 hash/lru-hash 这种 speculative inline，要求 helper 后立刻有 null-check | 只有“key 已经是常量”才会走到这里；当前 corpus 先卡在 key |
| `lookup result is not consumed by fixed-offset scalar loads` | `daemon/src/passes/map_inline.rs:280-285` | `r0` 没有被当作固定偏移标量 load 来源 | corpus 中很多 state-map site 也不匹配这个 use-shape |
| `lookup result has non-load uses` | `daemon/src/passes/map_inline.rs:286-290` | `r0` 逃逸到 helper、写回、间接指针操作等 | corpus 中也很常见，例如 `execsnoop` / `biosnoop` / `biolatency` 这类 mutable pointer/value 模式 |
| `failed to materialize replacement constants` | `daemon/src/passes/map_inline.rs:292-299` + `583-585` | 找到了 fixed loads，但没生成出 replacement | 当前未见证据 |
| site-level veto，例如 `PERCPU_ARRAY value differs across CPUs` | `daemon/src/passes/map_inline.rs:301-304` + `606-640` | `prepare_inline_value()` 拒绝 inline，例如 per-cpu slot 不一致 | 不是当前主因 |
| `map lookup failed: ...` | `daemon/src/passes/map_inline.rs:305-317` + `508-530` + `572-580` | live map read 失败、lookup size 失败、hash miss、load 越界等 | 当前主路径通常到不了这里，因为 key 常量性已先失败 |
| `lookup pattern contains a branch target` | `daemon/src/passes/map_inline.rs:320-328` | 安全检查，防止删掉 branch target 指令 | 不是当前主因 |
| `internal rewrite overlap` | `daemon/src/passes/map_inline.rs:330-338` | 单个 site 自身 rewrite 冲突 | 不是当前主因 |
| `overlapping map inline rewrite` | `daemon/src/passes/map_inline.rs:369-389` | 多个 site 的 rewrite 互相冲突 | 不是当前主因 |

补充两点：

1. `find_map_lookup_sites()` 只会抓 helper id=1 且前面能回溯到 `BPF_PSEUDO_MAP_FD` load 的 site
   - `daemon/src/passes/map_inline.rs:76-96`
   - 这不是 skip reason，而是候选集预过滤

2. `record_skip()` 会把 skip 写进 `PassResult.sites_skipped` 和 `diagnostics`
   - `daemon/src/passes/map_inline.rs:1161-1175`
   - 但 corpus batch 结果当前没有把这份数据保留下来

## 4. 结果产物里的 `daemon_response` / `skip_reasons` 为什么看不到

### 4.1 batch runner 只保留 changed-pass summary，不保留完整 daemon JSON

- `runner/src/batch_runner.cpp:406-421` 的 `daemon_socket_response_batch` 没有 `raw_json`、`passes`、`skip_reasons`
- `runner/src/batch_runner.cpp:635-699` 只抽取：
  - `status`
  - `summary.applied/program_changed/total_sites_applied/verifier_retries/final_disabled_passes`
  - `program.insn_delta/final_insn_count/final_jited_size`
  - `passes_applied`（仅 changed passes）

所以就算 daemon 返回了 `passes[].skip_reasons`，batch runner 也直接丢掉了。

### 4.2 guest 模式又递归删除了 `daemon_response`

- `corpus/modes.py:1162-1176`
- `corpus/modes.py:1243-1246`

也就是说，`metadata.json` 和 `details/result.json` 都只剩“最后 changed 了哪些 pass”，看不到：

- `passes[]`
- `skip_reasons`
- `diagnostics`
- `inlined_map_entries`

### 4.3 daemon 自己的 `map_inline` debug log 也被吞掉了

- `daemon/src/passes/map_inline.rs:1152-1154` 用 `eprintln!("map_inline: ...")`
- 但 `corpus/modes.py:551-556` 启 daemon 时把 stdout/stderr 都重定向到了 `DEVNULL`

因此当前 corpus 结果无法直接回答“每个 site 到底为什么 skip”；只能通过代码链路和 workload 形态反推。

## 5. 修复方案

### 5.1 首先修可观测性，否则之后每次都只能靠源码逆推

#### 建议 A：batch runner 保留完整 daemon optimize 响应

改动建议：

- 在 `runner/src/batch_runner.cpp:406-421` 的 `daemon_socket_response_batch` 增加：
  - `std::string raw_json;`
  - 或者至少增加 `std::vector<daemon_pass_detail>`，保留 `passes[].pass_name/changed/sites_skipped/skip_reasons/diagnostics`
- 在 `runner/src/batch_runner.cpp:620-699` 读完响应后保存整行 `line`
- 在 batch result record 里输出：
  - `daemon_response`
  - 或 `daemon_passes`
  - 或 `daemon_skip_reasons`

效果：

- 可以直接从 corpus 结果看到 `map_inline` 是“没 candidate”还是“candidate 全 skip”

#### 建议 B：guest sanitize 不要无条件删掉 `daemon_response`

改动建议：

- 修改 `corpus/modes.py:1162-1176`
- 不要递归删掉整个 `daemon_response`
- 至少保留一个裁剪版字段，例如：
  - `daemon_passes`
  - `daemon_skip_reasons`
  - `daemon_inlined_map_entries`

效果：

- `metadata.json` / `details/result.json` 里能直接看到 `map_inline` 的 pass details

#### 建议 C：把 daemon stderr 打到文件，而不是 `DEVNULL`

改动建议：

- 修改 `corpus/modes.py:551-556`
- 把 daemon stderr 重定向到 `details/daemon.log` 或 batch-specific log file

效果：

- `map_inline: ...` 的 per-site debug 文本可直接回溯

### 5.2 修 benchmark 控制面，避免“metadata 写了 requested_passes，但 serve daemon 根本没收到”

当前 serve 启动命令只有：

- `corpus/modes.py:552`

同时 batch job 里只有 `daemon_socket`，没有任何 requested-pass 字段：

- `corpus/modes.py:739-740`
- `corpus/modes.py:939`
- `corpus/modes.py:972`
- `corpus/modes.py:991`

这意味着：

- 结果目录里记录的 `requested_passes`，并不能证明 serve daemon 真按这些 pass 运行
- 在你删除 `--passes` 之后，这个 metadata 对 serve 模式已经带有误导性

改动建议（二选一）：

1. 恢复/新增 serve-mode pass selection
   - daemon 启动时支持 `--passes`
   - 或 optimize request JSON 里加 `passes`

2. 如果不打算支持 serve-mode custom passes
   - 删掉或重命名 corpus 结果里的 `requested_passes`
   - 明确写成 `benchmark_requested_passes_not_applied_in_serve_mode`

### 5.3 如果目标是“让 vm-corpus 真的出现 map_inline hits”，需要改 benchmark 覆盖面，不是修 serve plumbing

当前 root cause 是 workload 形态不匹配。

改动建议：

1. 为 corpus 增加一组明确的 `map_inline` 候选对象
   - 常量 key 的 `ARRAY` / `PERCPU_ARRAY` lookup
   - helper 返回值只做固定偏移 scalar load
   - 最好同时覆盖：
     - 全零 value
     - 非零 value
     - frozen / mutable array

2. 单独做一个 `vm-corpus-map-inline-candidates` profile
   - 不要指望当前 bcc tracing corpus 自然出现 `katran` 型 site

3. 如果你想覆盖 libbpf global-data / pseudo-map-value 的常量配置读取
   - 这不是修 `map_inline` 的小改动
   - 需要在 `daemon/src/passes/map_inline.rs` 之外新增对 `BPF_PSEUDO_MAP_VALUE` / 直接 global-data load 的优化

### 5.4 如果目标是扩展 `map_inline` 本身的适用范围

当前 pass 的约束非常窄，最关键的两个门槛是：

- 常量 key：`daemon/src/passes/map_inline.rs:214-242`
- fixed scalar loads only：`daemon/src/passes/map_inline.rs:261-290`

可考虑的代码方向：

1. 支持更多“常量 key”识别来源
   - 例如更复杂的栈物化/寄存器传播
   - 这只能扩大一小部分 coverage；对 `pid/tid/rq/req` 这类 runtime key 仍然无能为力

2. 支持更宽的 use-shape
   - 例如只读 struct field bundle
   - 但一旦返回值被当可变 pointer 用，风险会明显上升

3. 不要把“dynamic-key state maps”作为 `map_inline` 的目标
   - 这类场景从语义上就不适合当前 pass

## 最终判断

`vm-corpus` 里 `map_inline` 0 hits 的根本原因，不是 serve 模式没有调用 pass，也不是 `prog_id` / `map_ids` 没传对，更不是 zero-value array 天然不能 inline。

根因是：

1. 当前真实 corpus 成功加载的程序，不存在 `katran` 那种“常量 key + 固定偏移只读 scalar load”的 lookup site
2. 因此 `map_inline` 虽然被调用，但在 `daemon/src/passes/map_inline.rs:214-242` 的 constant-key gate 就已经把大多数 site 全部 skip 掉了
3. batch/guest 结果路径又把 `daemon_response`、`skip_reasons`、`diagnostics` 全部裁掉，导致外部只看到“0 hits”，看不到“为什么 0 hits”

