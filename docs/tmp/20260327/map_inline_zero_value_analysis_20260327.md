# map_inline zero-value analysis (2026-03-27)

## 结论

- 当前 `map_inline` 没有 `value == 0` / `all_zero(value)` 之类的 skip 分支。
- zero-value inline 在现有 pass 设计里本来就是合法的：最终只会把定长标量 load 改写成 `MOV dst, 0` 一类常量装载。
- serve 模式下 `map_ids` 传递链是通的：socket 请求只传 `prog_id`，daemon 端自己取原始字节码和 `map_ids`，再传给 `MapInfoAnalysis` / `MapInlinePass`。
- 真正需要区分的是：
  - `ARRAY` / `PERCPU_ARRAY`：key 在 range 内时，zero-filled value 应该可 inline。
  - `HASH` / `LRU_HASH`：空 map 是 miss，不是 “zero value”；这类场景当前不会被当成 zero-value inline。

我这次做的修复是把 `bpf_map_lookup_elem_by_id()` 改成了更稳妥的语义：

- 先走 `bpf_map_lookup_elem_optional()`
- 只有在 miss 时，才对 `ARRAY` / `PERCPU_ARRAY` 做 in-range zero-filled fallback
- `HASH` miss 仍然报错，不会被错误地当成 zero value

同时补了 `map_inline` 的 zero-filled `ARRAY` / `PERCPU_ARRAY` 回归测试。

## 1. map_inline 完整 skip 路径

`MapInlinePass::run()` 的 skip 条件在 `daemon/src/passes/map_inline.rs:167-337`：

1. `map reference metadata unavailable`
2. `map info unavailable`
3. `map type X not inlineable in v1`
4. `lookup key is not a constant stack materialization`
5. `key width N is smaller than map key size M`
6. `constant key K out of range for max_entries E`
   只对能移除 lookup/null-check 模式的 map 生效，也就是 `ARRAY` / `PERCPU_ARRAY`
7. `speculative map inline requires an immediate null check`
   只对 `HASH` / `LRU_HASH` 生效
8. `lookup result is not consumed by fixed-offset scalar loads`
9. `lookup result has non-load uses`
10. `failed to materialize replacement constants`
11. `map lookup failed: ...`
12. `lookup pattern contains a branch target`
13. `internal rewrite overlap`
14. `overlapping map inline rewrite`

`build_site_rewrite()` 里还有 site-level veto（`daemon/src/passes/map_inline.rs:498-640`）：

- `PERCPU_ARRAY has zero value_size`
- `PERCPU_ARRAY lookup blob length ... is inconsistent ...`
- `PERCPU_ARRAY value differs across CPUs ...`

注意：这里也没有 “value is zero skip”。

## 2. zero-value inline 是否被正确支持

支持，且现在更稳了。

### 原本就成立的部分

`build_site_rewrite()` 读到 map value 之后，会直接按 fixed-offset load 的 width/offset 取出标量，再走 `emit_constant_load()`。如果标量是 `0`，就只是发出 `mov64_imm(dst, 0)`，不会 skip。

也就是说：

- `ARRAY` element 全 0：应该 inline 成常量 0
- `PERCPU_ARRAY` 每个 CPU slot 都全 0：应该 collapse 后 inline 成常量 0

### 这次加的防御性修复

位置：`daemon/src/bpf.rs:582-610`, `daemon/src/bpf.rs:686-703`

改动前：

- `bpf_map_lookup_elem_by_id()` 直接走 `bpf_map_lookup_elem()`
- 如果 lookup 返回 miss，就直接报错

改动后：

- 先走 `bpf_map_lookup_elem_optional()`
- 如果命中，直接返回原始 value
- 如果 miss，再取 map info
- 仅当 map type 是 `ARRAY` / `PERCPU_ARRAY` 且 key 在 `max_entries` 范围内时，返回 zero-filled value

这样即使 live lookup 路径对 zero-filled array-like map 返回 miss，也不会把本该合法的 zero-value inline 误判成错误。

### 新增回归测试

- `daemon/src/passes/map_inline.rs:2557`
  `map_inline_pass_inlines_zero_filled_array_maps`
- `daemon/src/passes/map_inline.rs:2594`
  `map_inline_pass_inlines_zero_filled_percpu_array_maps`

这两个测试都模拟了“map 存在，但没有显式 value entry；语义上应为全 0”的场景，并确认 pass 仍然成功改写成常量 0。

已有 mock 层测试也仍然覆盖了 zero-filled array-like 语义：

- `daemon/src/bpf.rs:2161`
  `test_mock_array_lookup_returns_zero_for_in_range_missing_key`
- `daemon/src/bpf.rs:2233`
  `test_mock_percpu_array_lookup_returns_zero_for_in_range_missing_key`

## 3. serve 模式下 map value 读取是否 work

work。

serve 请求入口在 `daemon/src/server.rs:147-153`，只接受 `prog_id`，然后调用 `try_apply_one()`。

`try_apply_one()` 在 `daemon/src/commands.rs:661-752` 做了两件关键事：

1. 用 `bpf_prog_get_info(fd, true)` 取原始字节码
2. 用 `bpf_prog_get_map_ids(fd)` 取 live `map_ids`

之后 `MapInlinePass` 在 `build_site_rewrite()` 里通过：

- `bpf_map_lookup_value_size_by_id(info.map_id)`
- `bpf_map_lookup_elem_by_id(info.map_id, key, lookup_value_size)`

读取 live map value。

`bpf_map_lookup_elem_by_id()` 自己会：

1. `BPF_MAP_GET_FD_BY_ID`
2. `BPF_MAP_LOOKUP_ELEM`（现在是 optional 版本）
3. 对 array-like miss 做 zero-filled fallback

daemon serve 跟 corpus runner 在同一 VM，且 daemon 以 root 运行，所以 “按 `map_id` 打开 map 并读 value” 这条路径在设计上是成立的。

## 4. map_ids 传递链是否正确

正确。

链路如下：

1. serve 请求只传 `prog_id`
   `daemon/src/server.rs:147-153`
2. `try_apply_one()` 打开 `prog_fd`
   `daemon/src/commands.rs:661`
3. `bpf_prog_get_map_ids(fd)` 取 live `map_ids`
   `daemon/src/commands.rs:741`
4. `program.set_map_ids(map_ids.clone())`
   `daemon/src/commands.rs:752`
5. `set_map_ids()` 同时构建 `old_fd -> map_id` 绑定
   `daemon/src/pass.rs:106-108`
6. `MapInfoAnalysis.run()` 读 `program.map_ids` 和 `program.map_fd_bindings`
   `daemon/src/analysis/map_info.rs:117-123`
7. `collect_map_references_with_bindings()` 把 `LD_IMM64 pseudo-map-fd` 解析成 `map_id`
   `daemon/src/analysis/map_info.rs:141-205`

所以 serve 模式不是 “请求里没带 `map_ids` 就没有 map info”，而是 daemon 端自行补齐。

补充说明：代码里并没有一个独立命名为 `GET_ORIGINAL` 的 syscall wrapper；实际用的是 `BPF_OBJ_GET_INFO_BY_FD` 扩展字段 `orig_prog_insns` / `orig_prog_len`，封装在 `bpf_prog_get_info(fd, true)` 中（`daemon/src/bpf.rs:802-815`）。

## 5. ARRAY / HASH / PERCPU_ARRAY 的区别

`MapInfo` 的分类逻辑在 `daemon/src/analysis/map_info.rs:35-78`：

- `ARRAY`
  - inlineable
  - 可移除 lookup/null-check 模式
  - 适合 zero-filled inline
- `PERCPU_ARRAY`
  - inlineable
  - 可移除 lookup/null-check 模式
  - 但必须先证明所有 CPU slot 的 value 完全一致
- `HASH` / `LRU_HASH`
  - inlineable，但属于 speculative inline
  - 要求 helper 后面立刻有 null check
  - 当前实现不会把 “miss” 当成 “zero value”
- `PERCPU_HASH` / `LRU_PERCPU_HASH`
  - 不 inline

## 6. bindsnoop 具体分析

对象：`corpus/build/bcc/libbpf-tools/bindsnoop.bpf.o`

### map

按 ELF 和源码 `runner/repos/bcc/libbpf-tools/bindsnoop.bpf.c`：

1. `cgroup_map`
   `BPF_MAP_TYPE_CGROUP_ARRAY`
2. `sockets`
   `BPF_MAP_TYPE_HASH`
3. `ports`
   `BPF_MAP_TYPE_HASH`
4. `events`
   `BPF_MAP_TYPE_PERF_EVENT_ARRAY`

### call site 数量

`kprobe/inet_bind` 入口段本身没有 `bpf_map_lookup_elem()`。

真正的两个 helper=1 站点都在 `.text/probe_exit` 子程序里（`llvm-objdump -dr --section=.text`）：

1. PC 19: `bpf_map_lookup_elem(&sockets, &tid)`
2. PC 53: `bpf_map_lookup_elem(&ports, &sport)`

对应源码位置大致是：

- `runner/repos/bcc/libbpf-tools/bindsnoop.bpf.c:73`
- `runner/repos/bcc/libbpf-tools/bindsnoop.bpf.c:86`

### MapInlinePass 会怎么处理

#### `sockets` site

- map type: `HASH`
- key: `tid`
- helper 后立刻有 `if (!socketp) return 0;`
- 如果 live map 命中，理论上是符合 `HASH` speculative inline 形状的
- 但 corpus / `BPF_PROG_TEST_RUN` 下，这个 map 通常是空的，因为没有先跑 entry 程序把 `tid -> socket` 写进去
- 所以 live lookup 是 miss，不是 zero-value
- 当前 pass 会保留为 skip；这次修复不会把这种 `HASH` miss 伪装成 zero-value inline

#### `ports` site

- map type: `HASH`
- key: `sport`
- 也是 `HASH` speculative inline 形状
- 但 corpus 下 map 也是空的，lookup 同样 miss
- 结论同上：这不是 zero-filled map case

#### `kprobe/inet_bind` 入口程序

- 自身只有 `bpf_current_task_under_cgroup()` 和 `bpf_map_update_elem(&sockets, ...)`
- 没有 helper=1 call site
- 因此对这个 section 跑 `map_inline`，预期就是 0 sites

### bindsnoop 的结论

`bindsnoop` 是一个很好的 trace 对象，但它说明的是另一件事：

- 它的 `lookup_elem` 站点主要是 `HASH` miss 问题
- 不是 “array/percpu-array 值全 0 还能不能 inline” 问题

所以如果 `bindsnoop` 在 corpus 里没有 `map_inline` hit，这本身并不能证明 zero-value inline 有 bug。

## 7. 这次代码修改了什么

### `daemon/src/bpf.rs`

- `bpf_map_lookup_elem_by_id()` 改为：
  - optional lookup
  - array-like miss 时 zero-filled fallback
- 抽出了 `zero_filled_lookup_value()`，mock/runtime 共用

### `daemon/src/passes/map_inline.rs`

- 新增 `install_empty_map()` 测试辅助函数
- 新增 zero-filled `ARRAY` / `PERCPU_ARRAY` 回归测试

## 8. 验证

已通过：

- `cargo test --manifest-path daemon/Cargo.toml map_inline -- --nocapture`

剩余验证见本次任务执行记录：

- `make daemon`
- 全量 daemon tests

