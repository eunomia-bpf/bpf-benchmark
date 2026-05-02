# Round 14 Bug 修复报告

## 背景

Round 14 （commit `298211a0` "Refactor daemon to per-pass ReJIT"）删除了 `call_offset` 字段和 BTF 模块 fd 的加载逻辑，导致所有使用 kinsn 的程序 REJIT 失败。本报告记录根因分析和修复。

## Bug A：bpfopt extract pass 产生错误 BTF ID

### 症状

`bpfopt --pass extract` 输出的字节码中，kinsn CALL 指令的 `off=0`（vmlinux BTF），
但 `btf_func_id`（如 129876）属于内核模块 BTF 对象，不是 vmlinux。
内核 verifier 报错：`kernel btf_id 129876 is not a function`。

### 根因

`bpfget::TargetKinsnJson` 在 commit 298211a0 中被删除了 `call_offset` 字段。
`probe_kinsns_in_btf` 探测出 kinsn 函数后，不再记录该函数所在的 fd_array slot。
`bpfopt main.rs::kinsn_registry_from_target` 读取 `target.json` 时 `call_offset=None`，
于是 `KinsnRegistry::call_off_for_target_name` 返回 0，所有 kinsn CALL 的 `off` 都是 0（vmlinux）。
但 kinsn 实现位于内核模块 BTF 对象中，verifier 需要 `off=N`（fd_array[N-1] 是该模块 fd）才能找到函数类型。

### 修复（bpfget/src/lib.rs）

1. `TargetKinsnJson` 增加 `call_offset: u32` 字段（`#[serde(default, skip_serializing_if="is_zero_u32")]`，向后兼容）。
2. `probe_target_kinsns` 维护 `module_slot_map: BTreeMap<u32, u32>`，按 BTF 对象枚举顺序为每个新发现的模块 BTF ID 分配 1 起的 slot。
   - 能独立加载（`load_from_kernel_by_id` 成功）的 BTF 对象为 vmlinux，`call_offset=0`。
   - 只能 split-BTF 加载的 BTF 对象为内核模块，分配递增 slot。
3. `probe_kinsns_in_btf` 新增 `is_module: bool` 和 `module_slot_map` 参数，将 `call_offset` 写入返回的 `TargetKinsnJson`。

## Bug B：bpfopt prefetch pass 以 returncode 1 退出

### 症状

11 个 pass 成功提交后，prefetch pass 退出码 1，错误：
`extract payload has invalid range start=0 bit_len=0`

### 根因

同 Bug A：`call_offset` 被删除导致 `kinsn_call_matches` 无法区分来自不同模块但具有相同
`btf_func_id` 的不同 kinsn。具体来说，`bpf_extract64`（btf_id=4, call_offset=5）和
`bpf_rotate64`（btf_id=5, call_offset=3）在各自模块内的 type id 相同（均为 129876）。
在 `remap_kinsn_btf_metadata` → `collect_kinsn_proof_regions` → `kinsn_proof_len` 路径中，
`kinsn_call_matches` 看到 btf_id 匹配 extract64 于是调用 `extract_proof_len`，
但实际 payload 是 prefetch 格式（register number in bits[3:0]），`bit_len=0`，触发 bail。

### 修复

Bug B 与 Bug A 共享同一修复：恢复 `call_offset` 后，`kinsn_call_matches` 能通过
`target_call_offsets` 中的 `call_offset` 区分不同模块的同 btf_func_id 函数。

## Bug C：wide_mem pass REJIT 拒绝（多 subprog 程序）

### 状态

经代码审查和内核行为分析，Bug C 为误报：

- 非 EXT 程序的 REJIT 在 `bpf_prog_rejit()` 中设 `tmp->aux->func_info = NULL`，
  verifier 从字节码的 pseudo-call 指令重新探测 subprog 边界。
- `wide_mem` pass 的 `fixup_all_branches` 正确更新所有 pseudo-call 的 `imm` 偏移。
- 现有 round 13 corpus 所有失败均为 prefetch pass（Bug B），无 wide_mem REJIT 失败。

不需要修复。

## 守护进程 fd_array 布局修复（commands.rs）

除 `bpfget` 的探测修复外，`build_rejit_fd_array` 也需要重建：

### 修复内容

1. `TargetKinsnJson`（commands.rs 本地定义）增加 `call_offset: u32` 字段。
2. `try_apply_one_with_map_access` 将 probed kinsns 保存在内存中，传给 `build_rejit_fd_array`。
3. `build_rejit_fd_array` 新增 `kinsns: &HashMap<String, TargetKinsnJson>` 参数：
   - 按 `call_offset` 排序后，用 `kernel_sys::btf_get_fd_by_id` 打开各 BTF 模块 fd，
     置于 fd_array 前端（call_offset N → fd_array[N-1]）。
   - 验证 call_offset 连续无空洞（否则 bail）。
   - 然后追加 map fds。
4. `RejitFdArray` 新增 `btf_count: usize` 字段，提供 `map_fds_slice()` 方法。
5. `rejit_program` 签名改为接受 `&RejitFdArray`：
   - `relocate_map_fds_for_rejit` 使用 `fd_array.map_fds_slice()`（仅 map fds）。
   - `kernel_sys::prog_rejit` 使用 `fd_array.as_slice()`（完整数组，含 BTF 模块 fds）。
6. `KernelOps` trait 的 `rejit` 方法签名同步更新。

## 文件变更

| 文件 | 变更摘要 |
|---|---|
| `daemon/crates/bpfget/src/lib.rs` | +`call_offset` 字段；模块 BTF slot 分配 |
| `daemon/src/commands.rs` | +`call_offset` 字段；`build_rejit_fd_array` 含 BTF fds；`RejitFdArray` 双切片；trait 签名更新 |

## 验证

- `cargo build --manifest-path daemon/Cargo.toml --release` ✅
- `cargo test --manifest-path daemon/Cargo.toml --release` 28 passed ✅
- `cargo test --manifest-path bpfopt/Cargo.toml --release` 351+ passed ✅
- `make check` `RESULTS: 27 passed, 0 failed` ✅
