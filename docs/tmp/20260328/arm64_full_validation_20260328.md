# ARM64 Full Validation Report

日期：2026-03-28（America/Vancouver）

## Scope

本次验证目标：

- `make vm-arm64-selftest`
- `make cross-arm64`
- 在 ARM64 QEMU 中尝试 micro benchmark：
  - `simple`
  - `load_byte_recompose`
  - `cmov_dense`
- 如可行，补一个 ARM64 corpus smoke

约束：

- 未修改 `docs/paper/`
- 未 commit / push
- 未修改内核 `.c/.h` 源码

## 1. ARM64 Selftest

### 1.1 总结

- `make vm-arm64-selftest` 已跑通到 guest 执行阶段
- 最终 guest 汇总：`11 passed, 16 failed`
- 结论：ARM64 selftest 目前**不是全绿**

这次 selftest 的主要价值在于：

- ARM64 unittest / negative test cross-build 已经打通
- `kinsn` ARM64 模块 `6/6` 成功加载
- `bulk_memset` 相关修复已在 ARM64 `rejit_kinsn` 中被验证通过

### 1.2 构建链路修复

最初的 `make vm-arm64-selftest` 不能运行当前测试集，原因是 ARM64 selftest 目标仍然引用已删除的旧路径 `tests/kernel/test_recompile`。

为适配当前仓库结构，本次修复了 ARM64 selftest userspace/build 入口：

- `runner/scripts/cross-arm64-selftest.sh`
- `runner/scripts/vm-selftest.sh`
- `Makefile`

修复后 ARM64 selftest 改为：

- 构建 `tests/unittest/build-arm64/*`
- 构建 `tests/negative/build-arm64/*`
- 复用 host 已生成的 `tests/unittest/build/progs`
- 在 guest 中通过 `vm-selftest.sh` 执行当前 unittest/negative 套件

### 1.3 通过项

- `module/load_all.sh`：
  - `Loaded bpf_bulk_memory`
  - `Loaded bpf_endian`
  - `Loaded bpf_extract`
  - `Loaded bpf_ldp`
  - `Loaded bpf_rotate`
  - `Loaded bpf_select`
  - `kinsn modules: 6/6 loaded`
- `rejit_audit_tests`：全通过
- `rejit_poc`：全通过
- `rejit_kinsn`：`23 passed, 0 failed, 3 skipped`
- `rejit_regression`：`8 passed, 0 failed, 1 skipped`
- `rejit_spectre`：`7 passed, 0 failed`
- `rejit_swap_tests`：`6 passed, 0 failed`
- `rejit_tail_call`：`2 passed, 0 failed`
- `rejit_verifier_negative_tests`：`4 passed, 0 failed`
- `tests/negative/adversarial_rejit`：`23 passed, 0 failed, 0 skipped`
- `tests/negative/fuzz_rejit 1000`：PASS

### 1.4 bulk_memset / wide-mem 相关验证

`rejit_kinsn` 中以下关键 ARM64 case 已明确 PASS：

- `bulk_memcpy_apply`
- `bulk_memset_reg_apply`
- `bulk_memcpy_offset_lower_boundary`
- `bulk_memset_max_len_zero_fill`
- `bulk_memcpy_zero_length_rejected`
- `bulk_memcpy_invalid_tmp_rejected`
- `bulk_memset_invalid_width_rejected`
- `ldp128_apply`
- `stp128_apply`
- `stp128_offset_lower_boundary`
- `ldp128_invalid_flags_rejected`

结论：

- 用户给出的 `bulk_memset` 三个修复项，在当前 ARM64 selftest 中没有再复现旧失败
- `bulk_memset` / `bulk_memcpy` / `ldp/stp128` 的核心功能在 ARM64 guest 中工作正常

### 1.5 失败项

当前失败主要集中在 hotswap / live attach / guest 环境能力缺失，不是 `bulk_memset` 回归：

- `rejit_daemon_optimize_all_request`: `failed to open UDP sink socket`
- `rejit_hotswap_cgroup_skb`: `failed to read current cgroup`
- `rejit_hotswap_ext`: `kernel does not support live REJIT of attached EXT programs`
- `rejit_hotswap_fentry`: `bpf_program__set_attach_target failed`
- `rejit_hotswap_kprobe`: `failed to attach kprobe program`
  - 日志里还出现了 x86 符号名依赖：`__x64_sys_getpid+0x0`
- `rejit_hotswap_lsm`: `failed to create test file`
- `rejit_hotswap_sched_cls`: `failed to create veth pair`
  - 直接原因：guest rootfs 缺少 `ip`
- `rejit_hotswap_sk_lookup`: `failed to create reuseport listeners`
- `rejit_hotswap_socket_filter`: `failed to open UDP sink socket`
- `rejit_hotswap_struct_ops`: `failed to create loopback listener`
- `rejit_hotswap_tracepoint`: `failed to attach tracepoint program`
  - tracepoint perf event ID `-ENOENT`
- `rejit_hotswap_xdp`: `ip link add ...` 失败
  - 直接原因：guest rootfs 缺少 `ip`
- `rejit_late_rollback`
  - `T1_struct_ops_refresh_late_rollback`: `failed to create loopback listener (errno=99: Cannot assign requested address)`
  - 后续还出现 `Illegal instruction`
- `rejit_pass_correctness`: `Illegal instruction`
- `rejit_prog_types`: `Illegal instruction`
- `rejit_safety_tests`
  - 唯一失败项：`N16_kinsn_max_insn_cnt_exceeds_buf`
  - 原因：`bpf_barrier kinsn module/BTF not available`

### 1.6 Selftest 结论

- ARM64 selftest 已经能完整进入 guest 执行当前 unittest/negative 套件
- `bulk_memset` 相关修复在 ARM64 上已被明确验证
- 但 ARM64 selftest 目前仍有 `16` 个失败项，因此“所有 test 全通过”这一目标**尚未达成**

## 2. ARM64 Cross-Build

### 2.1 当前状态

`make cross-arm64` 过程中已经定位并修复了以下脚本/环境问题：

- 缺少 `ncurses` 相关开发包，导致 `MICRO_TERMINFO_LIBRARY` 找不到
- daemon 仍按 CMake 路径构建，实际应切到 `cargo build`
- 容器内缺少 `cargo/rust`
- daemon 的 `cargo` 在普通用户容器里默认写 `/.cargo`，触发权限错误

当前已修复文件：

- `runner/docker/arm64-crossbuild.Dockerfile`
- `runner/scripts/cross-arm64-build.sh`

修复点：

- cross-build image 补齐 `ncurses-devel`、`cargo`、`rust`、`clang`
- `cross-arm64-build.sh` 把 daemon 构建改为 `cargo build --release`
- `cross-arm64-build.sh` 现在显式设置：
  - `HOME=/tmp/bpf-benchmark-arm64/home`
  - `CARGO_HOME=/tmp/bpf-benchmark-arm64/cargo-home`
- `cross-arm64-build.sh` 现在显式把 `runner` / `cargo` 并行度绑定到 `ARM64_CROSSBUILD_JOBS`

### 2.2 历史失败记录

- 初始失败：缺少 terminfo / ncurses
- 第二次失败：daemon 仍走不存在的 `/workspace/daemon/CMakeLists.txt`
- 第三次失败：`cargo` 写 `/.cargo/registry/...` 权限拒绝

### 2.3 最终结果

待本次重跑完成后补充：

- `micro_exec.real` 是否生成
- `bpfrejit-daemon.real` 是否生成
- `file` 是否确认二者均为 `ARM aarch64`
- 输出目录内容与运行库打包情况

## 3. ARM64 Micro Benchmark

### 3.1 方法

确认了 `runner/scripts/arm64_qemu_smoke.py` 没有专门的 micro benchmark 模式，因此计划采用手工 guest command：

- 在 ARM64 QEMU 中挂载 repo 为只读 `9p`
- 加载 `module/load_all.sh`
- 启动 cross-built `bpfrejit-daemon`
- 用 cross-built `micro_exec` 分别执行：
  - `simple`
  - `load_byte_recompose`
  - `cmov_dense`
- 对每个 benchmark 分别记录 `stock` 与 `rejit` 的 `exec_ns`

### 3.2 Guest 环境限制

额外确认：

- ARM64 QEMU guest 没有 `python3`
- 因此不能直接在 guest 里运行现有 `micro/driver.py` / `corpus/driver.py`
- micro benchmark 需要走手工 `micro_exec run-kernel` 路径

### 3.3 结果

待 `make cross-arm64` 成功后补充。

## 4. ARM64 Corpus Smoke

待定。

当前已知限制：

- guest rootfs 没有 `python3`
- 因此无法直接运行现有 corpus Python pipeline
- 如果补做 corpus smoke，只能走手工对象级验证，而不是完整 `corpus/driver.py` 路径

## 5. Logs

本次相关日志：

- `docs/tmp/20260328/logs/vm-arm64-selftest.log`
- `docs/tmp/20260328/logs/vm-arm64-selftest_retry1.log`
- `docs/tmp/20260328/logs/vm-arm64-selftest_retry2.log`
- `docs/tmp/20260328/logs/vm-arm64-selftest_retry3.log`
- `docs/tmp/20260328/logs/13_make_cross-arm64_final.log`
- `docs/tmp/20260328/logs/14_make_cross-arm64_retry2.log`
