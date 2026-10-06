# round20 清理报告：死代码 / fallback / 重复 / 无用 API 删除

**日期**: 2026-05-01  
**范围**: `bpfopt/crates/bpfopt/src/` + `daemon/src/`  
**原则**: 不删除任何 pass / crate / 功能；只删重复、死代码、fallback

---

## 一、总行数统计

| 阶段 | 总行数 |
|------|--------|
| 清理前 | 28,299 |
| 清理后 | 28,213 |
| **净减** | **~86 行**（+新建 test_helpers.rs 29 行后净减） |

> 注：由于同步还有 commit `312a5d7f`（map_inline eager bail bug fix），实际统计基于清理专属 commit。

---

## 二、按类别明细

### A. 重复逻辑删除（~115 行重复 → 集中到共享位置）

| 变更 | 删行 | 新增 |
|------|------|------|
| `prefetch.rs` + `map_inline.rs` 本地 `insn_width` → 导入 `utils::insn_width` | -14 | +3（import） |
| `const_prop.rs` + `map_inline.rs` 本地 `emit_ldimm64` → 提升到 `utils::emit_ldimm64` | -24 | +15（utils 新函数） |
| `exit_insn` / `call_helper` / `pseudo_call_to` 7 处副本 → 新建 `passes/test_helpers.rs` | -52 | +29（新文件） |
| `map_inline.rs` 5 个 `BPF_MAP_TYPE_*` 常量 → `kernel_sys::` 直引 | -5 | +0 |
| `pass_tests.rs` 的 `exit_insn` → `test_helpers::exit_insn` | -4 | +1（import） |

### B. 死代码删除（~17 行）

| 变更 | 删行 |
|------|------|
| `BpfInsn::set_code` / `set_off` / `set_imm` — 无任何调用方（grep 验证） | -15 |
| `BpfInsn::new_raw` — 由 `pub` 改为私有（仅内部用） | -1（pub 删） |

### C. Fallback / 静默错误修复（~5 行）

| 变更 | 说明 |
|------|------|
| `const_prop::decode_ldimm64` 的 `.get(pc+1).unwrap_or(0)` → 直接索引 `insns[pc+1]` | 调用点已确认 `is_ldimm64()` 为真，pc+1 必存在；改为 panic-on-violation |
| `map_inline::lookup_pattern_removal_is_safe` 的 `skipped_pcs.iter().min().unwrap_or(0)` → `.expect()` | 有 `is_empty()` 前置保护，`unwrap_or(0)` 为不可达代码 |

---

## 三、Commit 清单

| Hash | 描述 |
|------|------|
| `c6fb7c79` | 重复删除：prefetch.rs / map_inline.rs 的本地 insn_width 副本 |
| `0fbe4a25` | 重复删除：emit_ldimm64 移到 utils.rs，消除 const_prop / map_inline 两份副本 |
| `e2e477dd` | 重复删除：测试辅助函数抽到 passes/test_helpers.rs |
| `37a67a77` | 重复删除：map_inline.rs 的 BPF_MAP_TYPE_* 常量改用 kernel_sys 直引 |
| `64643fb7` | 重复删除：pass_tests.rs 中 exit_insn 移到 passes::test_helpers |
| `573a6bae` | 死代码删除：BpfInsn::set_code / set_off / set_imm 无调用方 |
| `2e512674` | 死代码删除：BpfInsn::new_raw 改为私有 |
| `326e34e5` | fail-fast：const_prop::decode_ldimm64 删除 unwrap_or(0) fallback |
| `43cf9bc4` | fail-fast：map_inline min_removed_pc 的 unwrap_or(0) 为不可达代码 |

---

## 四、保留确认（所有 pass / crate / 功能均完整保留）

以下内容全部保留，构建通过：

| 项目 | 状态 |
|------|------|
| `branch_flip.rs` | ✅ 保留 |
| `bounds_check_merge.rs` | ✅ 保留 |
| `skb_load_bytes.rs` | ✅ 保留 |
| `bpfprof` crate（整个目录） | ✅ 保留 |
| `mock_maps.rs` | ✅ 保留 |
| 全部 12 个 default pass | ✅ 保留（map_inline, const_prop, dce, skb_load_bytes_spec, bounds_check_merge, wide_mem, bulk_memory, rotate, cond_select, ccmp, extract, endian_fusion） |
| `ccmp` pass | ✅ 保留 |
| `branch_flip` pass | ✅ 保留 |
| `vendor/linux-framework` | ✅ 未修改 |
| runner Python 框架 | ✅ 未修改 |

---

## 五、验证结果

```
cargo build --release --workspace --manifest-path bpfopt/Cargo.toml   → 0 error, 0 warning
cargo build --release --workspace --manifest-path daemon/Cargo.toml   → 0 error, 0 warning
cargo test --release --workspace --manifest-path bpfopt/Cargo.toml    → 357+9+10+7+4+21+1+1 tests OK
cargo test --release --workspace --manifest-path daemon/Cargo.toml    → 36 tests OK
```

---

## 六、风险点

- **test_helpers.rs 新模块**：需确保 `#[cfg(test)]` 可见性正确；已在多平台 test 运行中验证。
- **BpfInsn::set_code/set_off/set_imm 删除**：grep 验证无调用方，但若有通过 trait object 或宏的隐式调用则会报编译错误（构建通过证明无此风险）。
- **decode_ldimm64 unwrap 改 index**：若存在截断的畸形 LD_IMM64 bytecode（最后一条是 LD_IMM64 但后无 hi_half），现在会 panic 而非静默返回 0。这是期望的 fail-fast 行为。
- **kinsn rewrite loop 样板（~280 行，7 个 pass）**：此次未抽象为 `apply_site_rewrites`（评估后认为闭包参数会增加代码复杂度，风险大于收益），留待后续 round 决策。
