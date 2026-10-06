# Round 18: PSEUDO_MAP_IDX canonicalization

## 结论

本轮把 daemon 内部 bytecode ABI 从 loader raw fd 形式切到 canonical `PSEUDO_MAP_IDX(_VALUE)` 形式：snapshot 后只做一次 map reference canonicalize，后续每个 pass 的 ReJIT 直接提交 bpfopt 输出，不再做 per-pass first-seen / fd imm rewrite。

## 设计

新路径：

1. `bpfget::snapshot_program()` 仍读取 `BPF_PROG_GET_ORIGINAL` 原始 bytecode 和 `prog_info.map_ids`。
2. `commands.rs` 在写 `prog.bin` 前调用 `bpf::canonicalize_map_refs_to_idx()`。
3. canonicalize 规则：
   - `PSEUDO_MAP_FD imm=loader_fd` -> `PSEUDO_MAP_IDX imm=map_ids index`
   - `PSEUDO_MAP_VALUE imm=loader_fd` -> `PSEUDO_MAP_IDX_VALUE imm=map_ids index`，第二个 LD_IMM64 word 的 value offset 原样保留
   - `PSEUDO_MAP_IDX(_VALUE)` 在 loader fd_array 已知时通过 fd-form binding 重新校准；未知时按 `map_ids` 顺序 range-check 后保留
4. ReJIT fd_array 改为 maps-first：`fd_array[0..map_ids.len()]` 直接对应 canonical map IDX。
5. module BTF fd 放在 map fd 后面；写给 bpfopt 的 target `call_offset` 会按 map fd 前缀平移。

## 删除

- 删除 `relocate_map_fds_for_rejit()` 的 per-pass fd rewrite 路径。
- 删除 transformed candidate 上重新扫描 map refs、FD imm rewrite、IDX lowering to FD 的逻辑。
- 删除旧 relocate 单元测试组。

## 新增

- `daemon/src/bpf.rs::canonicalize_map_refs_to_idx()`
- snapshot 后 canonicalize 调用点
- maps-first `build_rejit_fd_array()` 和 target `call_offset` 平移
- bpfopt 对 `PSEUDO_MAP_IDX(_VALUE)` 的最小支持：
  - `kernel-sys`/`insn.rs` 暴露 IDX pseudo 常量
  - `map_inline` metadata 和 direct map value path 识别 IDX forms
  - DCE CLI 测试确认删 LD_IMM64 后剩余 IDX imm 不重绑
- 基于 `corpus/results/failures/129/pass-00-wide_mem.in.bin` 和 `102/pass-00-wide_mem.in.bin` 抽出的真实 LD_IMM64 pattern 的 canonicalize 单元测试。

## Net Diff

实现 diff（不含本报告）：10 files changed, 653 insertions(+), 286 deletions(-)，net +367。

净增主要来自：

- 真实 bytecode pattern fixtures 和新错误路径测试；
- bpfopt 侧补齐 IDX 支持；
- maps-first fd_array + target offset 平移测试。

## Bug D 修复方式

Bug D 的根因是 daemon 在 transformed candidate 上重新推 first-seen old fd 顺序。DCE 删除早期 `LD_IMM64` 后，幸存 old fd 会被绑定到错误的 `map_ids` slot。

新路径中 first-seen 只在原始 snapshot bytecode 上执行一次，结果立即写成稳定 IDX。之后 pass 可以删除、移动、重排 map loads；幸存指令携带的 `imm` 已经是 canonical map index，不再依赖 transformed candidate 的 first-seen 顺序，因此不会发生 old fd -> map slot 错绑。

## 验证

- `cargo build --release --workspace --manifest-path daemon/Cargo.toml`
- `cargo test --release --workspace --manifest-path daemon/Cargo.toml`
- `cargo build --release --workspace --manifest-path bpfopt/Cargo.toml`
- `cargo test --release --workspace --manifest-path bpfopt/Cargo.toml`
- 手测：将 `corpus/results/failures/129/pass-07-dce.in.bin` 管道 canonicalize 成 IDX 后喂 `bpfopt --pass dce`，输出只剩 `src=5/6`，无 `src=1/2` FD/VALUE form。
