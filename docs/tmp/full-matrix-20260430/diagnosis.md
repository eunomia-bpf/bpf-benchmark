# vm-corpus daemon/verifier hang 诊断

日期：2026-05-01

## 结论

本次 `vm-corpus` 600s socket timeout 的直接原因是 daemon 对 CLI 子进程使用阻塞等待。启用 `const_prop` 时，daemon 会先跑：

```bash
bpfverify --report --verifier-states-out ...
```

它在复杂 Tetragon/Katran 类程序上进入 kernel verifier 的 `mark_precise` 回溯路径。日志里重复出现 frame2 insn 2034-2045 的 backtrack，daemon 没有 stage 级 timeout，因此 runner 只能在 600s socket timeout 后报错，而 daemon 仍然卡在子进程等待上。

cilium/tetragon 的 ReJIT error 是同一条 replay/load-context 路径上的另一类问题：daemon/bpfverify 对原始 live program 做 dry-run replay 时，没有完整保留 live `BPF_PROG_LOAD` 上下文。主要缺口是：

- `prog_flags` 没有从 fork kernel 的 `bpf_prog_info` 导出，也没有传给 `bpfverify`。
- `bpfverify --verifier-states-out` 捕获原始 verifier states 时没有附带非空 `func_info.bin`/`line_info.bin`，导致 BTF/subprog layout 检查在 cilium/tetragon 上自然失败。

Calico baseline 的 interface-bound HTTP readiness 失败是独立 harness 问题：Felix BPF dataplane 默认 host endpoint policy 会挡住 host 到 namespace 内 benchmark HTTP server 的探测，需要显式把 `FELIX_DEFAULTENDPOINTTOHOSTACTION` 设为 `ACCEPT`。

## 历史调查

按用户要求执行了：

```bash
git log --all -i --grep='cilium\|tetragon\|mark_precise\|verifier.*hang\|rejit.*error\|socket.*timeout\|backtrack'
```

与本问题直接相关的历史提交包括：

- `bb354cd3` `fix(daemon): propagate subprocess errors; remove side-input fallback; reconnect map-inline invalidation; clippy`
- `59a5e82b` `fix(daemon, bpfopt): map-inline must use live map values; invalidation must rerun with same pass list`
- `5fbe934b` `fix(bpfopt, daemon): hash null is legitimate skip; scan-map-keys covers LD_IMM64 PSEUDO_MAP_VALUE`
- `3e6439af` `fix(daemon): preserve failure workdirs + capture verifier log + replay load context`
- `925f6571` `daemon: use BPF_PROG_REJIT VERIFY_ONLY+PRESERVE_METADATA; retry on ENOSPC`
- `9874f2b2` `daemon: relocate BPF_PSEUDO_MAP_IDX/IDX_VALUE alongside MAP_FD/MAP_VALUE`
- `e2bb1a92` `fix(bpfget): normalize BTF metadata for original bytecode`

结果 artifact 对照：

- `corpus/results/x86_kvm_corpus_20260429_091709_805618/details/result.json`
  - `status=ok`
  - `samples=1`
  - cilium/tetragon/katran/calico 全部 `status=ok`
- `corpus/results/x86_kvm_corpus_20260429_101106_713274/details/result.json`
  - `status=ok`
  - `samples=1`
  - 无失败 app
- `corpus/results/x86_kvm_corpus_20260429_113603_787483/details/result.json`
  - `status=error`
  - cilium/tetragon/katran/calico/bcc/bpftrace/tracee 等开始报错
  - 失败形态已经是 `bpfverify --verifier-states-out failed`

UTC 时间窗口内的代码提交顺序为：

```text
daa5bd48 2026-04-29T03:02:35-07:00 refactor(daemon): replace internal PassManager with fork+exec CLI (v3 §8 plan B)
bb354cd3 2026-04-29T03:24:22-07:00 fix(daemon): propagate subprocess errors; remove side-input fallback; reconnect map-inline invalidation; clippy
59a5e82b 2026-04-29T04:00:16-07:00 fix(daemon, bpfopt): map-inline must use live map values; invalidation must rerun with same pass list
5fbe934b 2026-04-29T04:20:01-07:00 fix(bpfopt, daemon): hash null is legitimate skip; scan-map-keys covers LD_IMM64 PSEUDO_MAP_VALUE
3e6439af 2026-04-29T06:08:38-07:00 fix(daemon): preserve failure workdirs + capture verifier log + replay load context
```

受“禁止跑 `make vm-corpus`”约束，不能做 benchmark oracle 驱动的真实 `git bisect run`。基于已有 artifact 的最小结论是：`20260429_101106` 仍成功，`20260429_113603` 首次失败；失败从 `bb354cd3` 之后的 fail-fast daemon 路径开始显性化。这里不是应该恢复 fallback 的回归，而是缺失 replay metadata 和缺失子进程 timeout 被 fail-fast 暴露出来。

## host 端复现边界

本机没有足够 BPF 权限：

```text
$ id
uid=1000(yunwei37) gid=1000(yunwei37) groups=... docker,kvm

$ bpftool prog show
Error: can't get next program: Operation not permitted
```

release daemon 可构建，但 host 启动会在 watcher 初始化时遇到相同权限边界：

```text
$ daemon/target/release/bpfrejit-daemon serve --socket /tmp/bpfrejit-codex-debug.sock
Error: initialize BPF program watcher
Caused by:
    0: enumerate BPF programs after id 0
    1: BPF_PROG_GET_NEXT_ID: Operation not permitted (os error 1)
```

因此 host 不能真实执行 `bpftool prog load` / `bpfget` / `bpfverify` live replay。用已有 preserved failure workdir 复现到权限边界：

```bash
timeout 5s bpfopt/target/debug/bpfverify \
  --prog-type kprobe \
  --map-fds corpus/results/x86_kvm_corpus_20260430_180011_539406/details/failures/287/map_fds.json \
  --input corpus/results/x86_kvm_corpus_20260430_180011_539406/details/failures/287/prog.bin \
  --output /tmp/bpfverify-287.verified.bin \
  --report /tmp/bpfverify-287.report.json \
  --verifier-states-out /tmp/bpfverify-287.states.json \
  --prog-btf-id 915 \
  --func-info corpus/results/x86_kvm_corpus_20260430_180011_539406/details/failures/287/func_info.bin \
  --func-info-rec-size 8 \
  --line-info corpus/results/x86_kvm_corpus_20260430_180011_539406/details/failures/287/line_info.bin \
  --line-info-rec-size 16
```

host 输出：

```text
open BPF map id 1088 ... BPF_MAP_GET_FD_BY_ID: Operation not permitted
```

同一个 artifact 的保存 verifier 报告显示旧失败点：

```text
func#0 @0
func#1 @2058
func_info BTF section doesn't match subprog layout in BPF program
```

offline `bpfopt` 复现用于拆 pass：

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

结果正常完成，`wide_mem` 改写 6 个 site，其他 pass 未改写。结合 daemon 代码路径，只有请求 `const_prop` 时才会触发 `bpfverify --verifier-states-out`，因此 hang 被定位到 `const_prop` 的 verifier-state side-input 捕获阶段，而不是某个 bpfopt structural pass 在用户态死循环。

## 修复策略

已采用 fail-fast 修复，不过滤、不跳过任何 BPF program：

- daemon 对所有 CLI stage 使用 5s timeout。
- timeout 后发 kill 并立即返回 stage error，不再调用可能继续阻塞的 `wait_with_output()`。
- 原始 verifier-state 捕获、final verify、failure replay 全部传递完整 load context。
- fork kernel 的 `bpf_prog_info` 导出 `prog_flags`，`kernel-sys`/`bpfget`/`bpfverify`/daemon 全链路传播 `prog_flags`。
- Calico runner 增加 `FELIX_DEFAULTENDPOINTTOHOSTACTION=ACCEPT`，修复 host readiness probe 被 Felix policy 拦截的问题。

这会把原来的 600s socket hang 改成 daemon 单 program ReJIT error，并在 result payload 自然暴露错误；没有实现任何 ReJIT filter、fallback 或 error masking。
