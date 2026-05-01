# v2 vs v3 Daemon: 9 轮 vm-corpus bug 归因分析

本文回答一个具体问题：为什么 v2 daemon 时代看起来没有这么多 bug，而 v3 pivot 之后 `vm-corpus` 连续 9 轮调试暴露大量问题。结论先说清楚：这不是单一“v3 锅”。按 round 报告和 git evidence 粗分，v3 daemon/replay 架构相关问题约占一半以上；corpus framework/workload 演进约占四分之一；剩下是新 app 或更大 program set 首次暴露，以及 pass/kinsn 自身 verifier correctness。周报里的频率估算也支持这个判断：cross-process/load-context 约 35%，relocation/metadata 约 17%，daemon hang/timeout 约 17%，line_info/func_info 约 13%，workload setup 约 22%。这些类别有重叠，不能简单相加。

## v2 vs v3 daemon 实现差异（表格 + git commit 链接）

| 维度 | v2 daemon（`daa5bd48^` 之前） | v3 fork+exec（`daa5bd48` 后） | v3 pivot 后（`9bbd56f8` 后） |
| --- | --- | --- | --- |
| pass 运行位置 | daemon 内部 `PassManager`，`daemon/src/pipeline.rs` 对每个 pass 运行后立刻 verifier dry-run；reject 就 rollback。 | daemon 不再持有 pass；fork `bpfopt optimize` 一次跑完整 pass list。 | 仍 fork `bpfopt optimize`；daemon 不链接 bpfopt pass。 |
| verify | daemon 内部直接构造 `BPF_PROG_LOAD` attr，`bpf_prog_load_verify()` dry-run；per-pass verify。 | fork `bpfverify` CLI，stdin/file 传 bytecode，JSON/side files 传 map/BTF/fd_array。 | `bpfverify` 变 daemon-owned lib，进程内 `kernel_sys::prog_load_dryrun_report()`；但仍是 GET_ORIGINAL replay。 |
| ReJIT | daemon 内部直接 `BPF_PROG_REJIT`，fd_array 在同进程构造。 | fork `bpfrejit` CLI，读 `verified.bin`、`map_fds.json`、`fd_array.json`。 | `bpfrejit` 变 daemon-owned lib，fd_array/map fd 在 daemon 进程内传。 |
| map relocation | daemon 从 live `prog_info.map_ids` + in-process map fd 绑定修 pseudo map fd。 | `bpfget`/`bpfverify`/`bpfrejit` 跨进程重建 map fd，产生 `map_fds.json` 和 resolved pointer 反推问题。 | 去掉 JSON fd 协议，但仍要把 `BPF_PROG_GET_ORIGINAL` bytecode 重新 relocate 成可 load/rejit 的 bytecode。 |
| BTF line_info/func_info | daemon 直接从 live prog fd 取 metadata，用于 per-pass dry-run；final REJIT 主要交给 kernel 在 existing prog 上保留 metadata。 | BTF records 写成 side files，`bpfverify` 再喂 `BPF_PROG_LOAD`。`e2bb1a92` 后才补上针对 original bytecode 的 normalization。 | pivot 一度丢失 normalization，`b8f4b21b` 修复；root cause 仍是 original bytecode + live BTF metadata 的 replay invariant。 |
| verifier states | v2 verifier states 在 daemon/pass pipeline 内部流动。 | `bpfverify --verifier-states-out` 文件协议，且起初没有可靠 stage timeout。 | in-process capture，少了 subprocess 文件协议，但 verifier hang watchdog 风险仍需明确。 |

关键 commits：

- [`daa5bd48`](https://github.com/eunomia-bpf/bpf-benchmark/commit/daa5bd48) 删除 daemon 内部 `PassManager`、`pipeline.rs`、`profiler.rs`，改成 fork `bpfget`/`bpfopt`/`bpfverify`/`bpfrejit`。
- [`bb354cd3`](https://github.com/eunomia-bpf/bpf-benchmark/commit/bb354cd3) 删除 side-input fallback，开始 fail-fast 传播 subprocess error。它不是坏事，但暴露 replay metadata 缺口。
- [`9f59ee43`](https://github.com/eunomia-bpf/bpf-benchmark/commit/9f59ee43)、[`dc3abe33`](https://github.com/eunomia-bpf/bpf-benchmark/commit/dc3abe33)、[`681f5ba8`](https://github.com/eunomia-bpf/bpf-benchmark/commit/681f5ba8) 引入 `kernel-sys`、`bpfget`/`bpfrejit`、`bpfverify`/`bpfprof` CLI。
- [`9bbd56f8`](https://github.com/eunomia-bpf/bpf-benchmark/commit/9bbd56f8) pivot：`bpfget`/`bpfverify`/`bpfrejit` 回到 daemon-owned in-process lib，只保留 `bpfopt`/`bpfprof` CLI。
- [`b8f4b21b`](https://github.com/eunomia-bpf/bpf-benchmark/commit/b8f4b21b) 修复 pivot 后丢失的 BTF line_info replay normalization。

这里最重要的区别不是“fork 还是 in-process”，而是 v3 把 live program 变成一套可重复 replay 的协议：`BPF_PROG_GET_ORIGINAL` 取 bytecode，再配 `BPF_OBJ_GET_INFO_BY_FD` 的 map/BTF/attach metadata，重新喂给 `BPF_PROG_LOAD` 和 `BPF_PROG_REJIT`。pivot 后 kernel-facing 调用回到 in-process，但 replay protocol 仍然存在。

## v2 vs v3 corpus framework 差异（workload 演进 + apps list 变化）

v2 build #42 的 authoritative corpus 不是今天的 app-level macro corpus。历史文件 `corpus_recompile_authoritative_20260313.json` 已从当前 tree 删除，但可用 `git show 14f7ed45:corpus/results/corpus_recompile_authoritative_20260313.json` 读到：它是 object/program-level corpus，`targets_attempted=166`、`measured_pairs=152`、`applied_programs=39`、`exec_ratio_geomean=1.0463358483799616`。source list 是 `calico`、`katran`、`libbpf-bootstrap`、`linux-selftests`、`real_world_code_size`、`suricata`、`tracee`、`xdp-tools`、`xdp-tutorial`；没有 cilium/tetragon app-level runner，也没有 otelcol-ebpf-profiler。

当前 macro corpus 是 `corpus/config/macro_apps.yaml`，有 22 个 case，覆盖 8 个 supported app family：10 个 BCC、6 个 bpftrace，加 `calico/felix`、`otelcol-ebpf-profiler/profiling`、`cilium/agent`、`tetragon/observer`、`katran`、`tracee/monitor`。这和 v2 build #42 不可直接同口径比较。

workload 也变了：

- [`986ec3eb`](https://github.com/eunomia-bpf/bpf-benchmark/commit/986ec3eb) 把 corpus workload 切到标准 benchmark：`stress-ng`、`fio`、`wrk` 等，替代自制 synthetic loop。
- [`5edf29e4`](https://github.com/eunomia-bpf/bpf-benchmark/commit/5edf29e4) 扩大 workload 覆盖，目标是触发更多 BPF program。
- [`76d6cd85`](https://github.com/eunomia-bpf/bpf-benchmark/commit/76d6cd85) 加 Calico/Cilium datapath network workload，包含 `bpfbenchns`、`198.18.0.2/30` 和 interface-bound HTTP server/client。
- [`273a0894`](https://github.com/eunomia-bpf/bpf-benchmark/commit/273a0894) 引入 explicit VM-safe stress-ng stressor list，其中 `stress_ng_os` 包含 `timerfd`；[`65d9325e`](https://github.com/eunomia-bpf/bpf-benchmark/commit/65d9325e) 后因 flaky timeout 移除。

所以“v2 没这么多 bug”的第一层原因是：v2 build #42 跑的不是今天这套真实 app startup + 22 macro cases + 标准 workload + no-filter ReJIT 的组合。

## 9 轮 bug 归因表（v3 锅 vs corpus 演进锅 vs 新 app 暴露）

| bug 类别 | v3 重构引入？ | corpus 演进引入？ | 新 app/新覆盖暴露？ | 证据 |
| --- | --- | --- | --- | --- |
| daemon 600s socket hang / 无 stage timeout | 是 | 否 | Tetragon/Katran 放大 | round1 诊断定位 `bpfverify --verifier-states-out` 卡 verifier；[`441ad97f`](https://github.com/eunomia-bpf/bpf-benchmark/commit/441ad97f) 给 CLI stage 加 timeout。v2 in-process per-pass 没有这条 subprocess wait 边界。 |
| `bpfverify --verifier-states-out` 协议复杂 | 是 | 否 | 是 | `681f5ba8` 引入 standalone `bpfverify`，const_prop 需要 verifier states side-input；round4/5/6 反复调 5s/60s/ramp。 |
| 5s/30s/60s timeout ramp | 是 | 否 | Tetragon 287 programs 放大 | [`7c768acd`](https://github.com/eunomia-bpf/bpf-benchmark/commit/7c768acd) 把 heavy stage 到 60s；[`e9c6bf69`](https://github.com/eunomia-bpf/bpf-benchmark/commit/e9c6bf69) 改 5/30/60 ramp；[`dc92a15c`](https://github.com/eunomia-bpf/bpf-benchmark/commit/dc92a15c) 又删 ramp，因为 `287*(5+30+60)` 超过 7200s。 |
| Tetragon `vng` 7200s timeout | 是，timeout amplification 是 v3 | 部分，program set 变大 | 是 | round5/6：`tetragon/observer` `program_count=287` 后超时。v2 `vm_corpus.md` 的 Tetragon 是 8 个 program；4/22 E2E 记录常见 35 个。287 是新 policy/app scope 暴露，但每个 program 串行 verifier-state subprocess 是 v3 架构成本。 |
| multi-map relocation / resolved map pointer | 是 | 否 | Katran/Tracee 暴露 | round3 先修 single-map Katran，round4 Tracee 16 map bindings 证明不能猜；[`7c768acd`](https://github.com/eunomia-bpf/bpf-benchmark/commit/7c768acd) 按 `prog_info.map_ids`/used_maps 顺序重建。pivot `9bbd56f8` 消掉 JSON fd 协议但没消掉 relocation replay。 |
| BTF `line_info` / multi-subprog offset | 是，属于 replay protocol | 否 | BCC/Tracee 类多 subprog 暴露 | [`e2bb1a92`](https://github.com/eunomia-bpf/bpf-benchmark/commit/e2bb1a92) 说明 `bpfget --full` 把 fork-recovered original bytecode 和 live func/line BTF metadata 配对，导致 invalid line_info；`9bbd56f8` pivot 后丢 normalization，`b8f4b21b` 修复 `Invalid insn code at line_info[35].insn_off`。 |
| Calico/Cilium readiness、netns client path | 否 | 是 | Cilium/Calico datapath 首次充分暴露 | [`76d6cd85`](https://github.com/eunomia-bpf/bpf-benchmark/commit/76d6cd85) 加 network infra；round3/4/5 修 `READY`、`ip netns exec bpfbenchns`、failure message。 |
| HTTP/1.1 keep-alive / `wrk` EADDRNOTAVAIL | 否 | 是 | Calico/Cilium 暴露 | `wrk` workload 来自标准 workload 路径；round6 证明 client 已在 netns，真正原因是 HTTP/1.0 短连接导致 TIME_WAIT/ephemeral port pressure；[`dc92a15c`](https://github.com/eunomia-bpf/bpf-benchmark/commit/dc92a15c) 把 handlers 改为 HTTP/1.1。 |
| `timerfd` stressor timeout | 否 | 是 | Tracee/BCC OS workload 暴露 | [`273a0894`](https://github.com/eunomia-bpf/bpf-benchmark/commit/273a0894) explicit `stress_ng_os` 加 `timerfd`；round3 判定 VM-load-sensitive，`65d9325e` 移除。 |
| all loaders 先启动、后面 app 空等导致 program IDs stale | 否 | 是 | Otel/Cilium/Calico 暴露 | round2 诊断：22 apps 全启动后再顺序 30-sample baseline，后面的 loader 空等二十多分钟；[`35e74100`](https://github.com/eunomia-bpf/bpf-benchmark/commit/35e74100) 改为 per-loader `start -> baseline -> ReJIT -> post -> stop`。 |
| verifier reject optimized bytecode | 混合 | 间接 | 是 | misaligned wide load、tail-call-sensitive kinsn、candidate BTF remap 属 pass/kinsn correctness 或 metadata consistency，不全是 daemon v3；但 v3 final verify-only 和 broader corpus 让它们更快暴露。相关 commits 包括 `3f0653bb`、`1d619c17`、`ce956452`、`d6d5acbc`。 |

## v2 build #42 真实测试范围（apps list、workload type）

build #42 的 authoritative data 是 March 13/14 的 `corpus_recompile_authoritative_20260313.json`，不是今天的 `runner/libs/app_runners/*` app startup corpus。它的单位是 `.bpf.o` object/section/program，通过 runner/scanner 做 VM test-run；字段叫 `source_name`，不是 `app`。量化范围：

- `targets_attempted=166`，`compile_pairs=163`，`measured_pairs=152`。
- source：Calico 59 measured、linux-selftests 59、xdp-tutorial 20、Katran 5、xdp-tools 4、Tracee 2、Suricata 1、libbpf-bootstrap 1、real_world_code_size 1。
- 没有 Cilium source measured；没有 Tetragon；没有 otelcol-ebpf-profiler。
- Katran 有 5 个 object-level programs（如 `balancer.bpf.o:balancer_ingress`、`xdp_root.bpf.o:xdp_root`），但不是当前真实 `katran_server_grpc` app lifecycle 下的 corpus run。
- Suricata 只有 1 measured pair，且现在已从 supported apps 删除；它不能作为当前 8-app corpus 的稳定参照。

后来的 v2 macro corpus（例如 2026-04-03 `vm_corpus.md`）已经是 app runner 口径，但 app list 是 20 个：BCC、bpftrace、SCX、Tetragon、Katran、Tracee；没有 Calico/Cilium/Otel。当前 22-case corpus 又删除 SCX、加入 Calico/Cilium/Otel，并扩大 Tetragon policy/program scope。因此，不能说“v2 已经跑通过 Cilium/Tetragon/Katran，v3 才弄坏”：Cilium/Otel 是新覆盖；Tetragon/Katran 的旧覆盖规模和加载路径也不同。

## 关键洞察：v3 GET_ORIGINAL replay protocol 是 root cause

最关键的工程判断是：pivot 后许多 bug 已经不是 fork+exec 本身，而是 v3 replay protocol 本身。

`9bbd56f8` 把 `bpfget`、`bpfverify`、`bpfrejit` 收回 daemon 进程，消掉了 `map_fds.json`、`fd_array.json`、subprocess report file 等一批协议面。这确实修掉或降低了跨进程 fd 生命周期和 JSON reconstruction 的风险。但 daemon 仍要做：

```text
BPF_PROG_GET_ORIGINAL bytecode
+ BPF_OBJ_GET_INFO_BY_FD metadata
+ map_ids / BTF records / attach metadata
=> reconstruct loadable candidate
=> BPF_PROG_LOAD dry-run
=> BPF_PROG_REJIT
```

这里天然有两个视图不一致：original bytecode 是 verifier rewrite 前的指令流；live BTF/map metadata 来自 kernel 已接受并可能调整后的 program。`line_info[35].insn_off` 指到 `ldimm64` second slot，就是这个不一致的典型症状。multi-map resolved pointer 也是同一类：live kernel pointer 不是 userspace 可重放的 relocation，需要重新映射回 pseudo map fd/index。

所以今天的 root cause 不是“Rust 调 CLI 慢”这么简单，而是“透明 post-load optimizer 必须把 live kernel program 还原成一个可再次 `BPF_PROG_LOAD` 的 load context”。v2 的 monolith 少了很多外部协议面，final REJIT 更依赖 kernel-owned existing metadata，因此少暴露；v3 为了纯 bytecode CLI 和 fail-fast，把 replay invariant 变成显式系统边界，bug 自然多。

## 是否值得 revert 部分 v3 设计？（讨论代价）

不建议整体 revert 到 v2 daemon。v2 的好处是少协议、低延迟、per-pass rollback 直观；代价是 daemon 重新链接 pass pipeline、profiler、kernel syscall wrapper，违背当前 v3 设计：`bpfopt` 纯 bytecode CLI，daemon 只做 kernel orchestration。整体 revert 会把刚删掉的 PassManager、in-daemon pass code、profiling residue 带回来，后续 Paper B/Paper A 分层会更难维护。

值得保留的 v3 pivot 方向是：kernel-facing 工作留在 daemon-owned in-process libs，`bpfopt`/`bpfprof` 保持 CLI。这个方向已经消掉最大的一类跨进程 fd/JSON bug，也和 `CLAUDE.md`/`bpfopt_design_v3.md` 对齐。

真正需要收敛的是 replay protocol 的 blast radius：

- `ProgramSnapshot` 应该明确拥有或稳定复用 map fd；如果实现继续按 map id 重开 fd，文档必须改成一致。
- BTF metadata normalization 必须是 snapshot 的强 invariant，而不是某个 CLI/pivot 分支的临时补丁。
- verifier-state capture 要有明确成本策略：固定短 timeout 可让每个 program error 自然浮现；长 ramp 对 Tetragon 这类大 program set 不可接受。
- 文档要承认当前是 final-verify-only，不是 v2 的 per-pass verify/rollback。否则 debug 时会误判“为什么一个 late pass reject 导致整段 candidate 不 apply”。

一句话回答用户疑问：v2 时代 bug 少，主要因为测试面窄、daemon 边界少、错误没有被 v3 fail-fast/replay protocol 全量显性化；v3 确实引入了 replay/metadata/timeout 这一大类 bug，但 Calico/Cilium HTTP、timerfd、loader lifecycle 这些是 corpus framework 真实演进带来的，不应该算 v3 daemon 的锅。
