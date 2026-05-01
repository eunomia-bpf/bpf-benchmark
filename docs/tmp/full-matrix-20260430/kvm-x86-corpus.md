# KVM x86 Corpus 修复报告

日期：2026-05-01

## 调研结论

`20260429_091709` 和 `20260429_101106` 两次 SAMPLES=1 corpus artifact 均为 `status=ok`，cilium/tetragon/katran/calico 都成功。`20260429_113603` 首次进入大面积 `status=error`，错误从 daemon fork+exec CLI 路径的 `bpfverify --verifier-states-out` 开始显性化。

在不能跑 `make vm-corpus` 的约束下，无法做真实 benchmark oracle 的 `git bisect run`。基于 artifact 时间线，回归窗口落在 2026-04-29 10:11-11:36 UTC 之间；`bb354cd3` 之后 daemon 开始 fail-fast 传播 subprocess error，随后 `59a5e82b`/`5fbe934b` 引入更严格 side-input 路径。结论是：fail-fast 本身符合项目规则，真实缺陷是 replay metadata 不完整和 daemon 缺少 CLI stage timeout。

## 根因

1. daemon 原先用阻塞式 `Command::output()` 等待 `bpfverify`/`bpfopt`/`bpfrejit`。当 `const_prop` 请求原始 verifier states 时，`bpfverify --verifier-states-out` 会进入 kernel verifier verbose replay；Tetragon/Katran 类程序触发 `mark_precise` 指数级回溯后，runner socket 600s 超时，但 daemon 仍卡住。

2. cilium/tetragon 的 ReJIT error 来自 live program load context replay 不完整：
   - fork kernel 未在 `bpf_prog_info` 导出 live `prog_flags`；
   - `bpfget` JSON 没有记录 `prog_flags`；
   - `bpfverify` CLI 没有 `--prog-flags`；
   - daemon 原始 verifier-state 捕获没有带上非空 BTF func/line metadata。

3. Calico baseline readiness 是 harness policy 问题：Felix BPF dataplane 需要允许 host 到 endpoint 的 readiness probe。

## Host 复现步骤

本机 host 没有 CAP_BPF/CAP_SYS_ADMIN 能力，真实 live BPF replay 会在权限边界失败：

```bash
bpftool prog show
# Error: can't get next program: Operation not permitted

daemon/target/release/bpfrejit-daemon serve --socket /tmp/bpfrejit-codex-debug.sock
# Error: initialize BPF program watcher
# Caused by:
#     0: enumerate BPF programs after id 0
#     1: BPF_PROG_GET_NEXT_ID: Operation not permitted (os error 1)
```

用 preserved failure artifact 可以复现旧 verifier 报告：

```bash
jq '{id,name,type:.type.name,insn_cnt,btf_id,func_info_rec_size,nr_func_info,line_info_rec_size,nr_line_info}' \
  corpus/results/x86_kvm_corpus_20260430_180011_539406/details/failures/287/prog_info.json

jq '{status,errno,log_head:(.verifier_log|split("\n")[:8])}' \
  corpus/results/x86_kvm_corpus_20260430_180011_539406/details/failures/287/original_bpfverify_report.json
```

旧报告关键行：

```text
func#0 @0
func#1 @2058
func_info BTF section doesn't match subprog layout in BPF program
```

offline pass 拆分：

```bash
bpfopt/target/debug/bpfopt optimize \
  --input corpus/results/x86_kvm_corpus_20260430_180011_539406/details/failures/287/prog.bin \
  --output /tmp/bpfopt-287-no-constprop.bin \
  --report /tmp/bpfopt-287-no-constprop.report.json \
  --passes wide_mem,rotate,cond_select,extract,endian_fusion,dce,bounds_check_merge,skb_load_bytes_spec,bulk_memory \
  --prog-type kprobe \
  --target corpus/results/x86_kvm_corpus_20260430_180011_539406/details/failures/287/target.json \
  --func-info corpus/results/x86_kvm_corpus_20260430_180011_539406/details/failures/287/func_info.bin \
  --func-info-rec-size 8 \
  --line-info corpus/results/x86_kvm_corpus_20260430_180011_539406/details/failures/287/line_info.bin \
  --line-info-rec-size 16
```

结果：用户态 bpfopt 正常完成；`wide_mem` 改写 6 个 site，其他 structural pass 未改写。hang 触发点因此定位到 daemon 为 `const_prop` 收集 verifier-state side input 的 `bpfverify --verifier-states-out`，不是 bpfopt transform 本身。

## 修复方式

代码改动摘要：

- `daemon/src/commands.rs`
  - 所有 CLI stage 从阻塞 `output()` 改为 `spawn()` + 5s timeout。
  - timeout 后 kill 子进程并立即返回错误，避免继续阻塞在 `wait_with_output()`。
  - replay/final/original verifier-state load context 全链路传递 `prog_flags`。
  - 原始 verifier-state 捕获现在传递非空 `func_info.bin`/`line_info.bin`。
- `bpfopt/crates/kernel-sys/src/lib.rs`
  - fork `BpfProgInfoFork` 增加 `prog_flags`，并把 dry-run options 写入 `bpf_prog_load_opts.prog_flags`。
- `bpfopt/crates/bpfget/src/main.rs`
  - `prog_info.json` 输出 `prog_flags`。
- `bpfopt/crates/bpfverify/src/main.rs`
  - 增加 `--prog-flags` CLI 参数，并传给 `kernel_sys::ProgLoadDryRunOptions`。
- `vendor/linux-framework`
  - fork kernel `struct bpf_prog_info` 导出 `prog_flags`。
- `runner/libs/app_runners/calico.py`
  - 增加 `FELIX_DEFAULTENDPOINTTOHOSTACTION=ACCEPT`。

修复保持 fail-fast：程序不会被过滤、跳过或排除；如果 verifier/rejit 仍失败，会作为单 program error 返回并被 result payload 记录。

## 单元测试

新增或更新的回归测试：

- `commands::tests::wait_with_timeout_kills_stuck_subprocess`
  - 覆盖 daemon 子进程卡住时必须快速返回，不再等待 runner socket 600s。
- `commands::tests::candidate_load_context_skips_empty_btf_metadata_files`
  - 覆盖 candidate verify 保留 `prog_flags`，同时不传空 BTF 文件。
- `commands::tests::verifier_states_load_context_includes_nonempty_btf_metadata`
  - 覆盖原始 verifier-state 捕获必须带上非空 func/line metadata。
- `tests::prog_flags_cli_defaults_to_zero_and_parses_nonzero_flags`
  - 覆盖 `bpfverify --prog-flags` CLI 解析。
- `tests::prog_info_json_schema_round_trips_requested_fields`
  - 覆盖 `bpfget` JSON schema 输出 `prog_flags`。
- `tests::bpf_prog_info_fork_field_offsets_match_fork_uapi`
  - 覆盖 fork UAPI `prog_flags` 字段 offset/size。

已跑验证：

```bash
cargo test --manifest-path daemon/Cargo.toml
cargo test --workspace --manifest-path bpfopt/Cargo.toml
cargo build --release --manifest-path daemon/Cargo.toml
```

结果均通过。

## 给 Claude

修复完成，请跑 `make vm-corpus` 验证。
