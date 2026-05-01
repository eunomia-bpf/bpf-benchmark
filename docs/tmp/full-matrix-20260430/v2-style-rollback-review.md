# v2 Style Rollback: Necessity & Trade-off Review

## 9 轮 vm-corpus bug 在 v2 风格下的归因（量化表）

本 review 读了 `CLAUDE.md`、memory、`docs/tmp/bpfopt_design_v3.md`、round2-6 修复报告、v3 pivot/review/fix/line_info 报告和 weekly report；`v2-vs-v3-bug-attribution.md` 当前不存在。结论是：这轮 corpus 中 8 个主要 bug 类别里，2 个是 workload/harness，v2 回归不解决；6 个是 ReJIT replay / dry-run verifier / metadata 协议复杂度，v2 回归会消失或退化成单个 REJIT syscall errno。也就是按类别看 6/8 消失；按 ReJIT 相关类别看 6/6 消失。

| Bug 类别 | 当前架构暴露 | v2 风格是否消失 | 原因 |
| --- | --- | --- | --- |
| HTTP/1.1 keep-alive | workload | 不消失 | round6 证明根因是 namespaced HTTP server 以 HTTP/1.0 产生大量短连接，`wrk` 触发 TIME_WAIT/本地端口压力；和 daemon 架构无关。 |
| timerfd/open stressor timeout | workload | 不消失 | round3 定位为 `timerfd` VM-load-sensitive stressor；删除/替换 workload 才能解决。 |
| multi-map relocation（katran/tracee） | replay protocol | 消失，带 ABI caveat | round4 的 `map_fds.json cannot reconstruct resolved kernel map pointer ... with 16 map bindings` 来自 daemon/bpfget/bpfverify 重建 map 绑定。v2 不做 BPF_PROG_LOAD replay，直接 REJIT，问题面消失。caveat：当前 kernel verifier 仍通过 `fd_array` 解析 `BPF_PSEUDO_MAP_IDX`；若要完全删 daemon map relocation，REJIT ABI 需要从 `prog->aux->used_maps` 构造/复用 map fd array，或 daemon 保留极小 map fd builder。 |
| BTF line_info offset（multi-subprog） | replay protocol | 消失 | round3、v3 line_info fix 都在修 `GET_ORIGINAL` bytecode 与 `BPF_OBJ_GET_INFO_BY_FD` BTF records 重新喂给 BPF_PROG_LOAD 的一致性。v2 REJIT 不重新提交 func_info/line_info metadata，这类 offset normalization 不再存在。 |
| daemon 5s/30s/60s timeout ramp | verifier-states-out | 消失 | round4-6 的 5s 太短、60s 太长、5/30/60 ramp 都是 original verifier-state dry-run 的策略债。v2 不做预 verify，最终只有 REJIT syscall 返回 errno/log。 |
| Tetragon 287 progs vng 7200s | 串行 dry-run | 消失 | round5/6 算术很清楚：`287 * 60s = 17220s`，`287 * (5+30+60)s = 27265s`，超过 vng 7200s。v2 每个 program 只做 bpfopt transform + 一个 REJIT syscall，不再为 const_prop 串行收集 verifier states。 |
| `line_info[35].insn_off Invalid`（post-pivot） | replay protocol | 消失 | v3 pivot 后 raw line_info 重新进入 dry-run/ReJIT replay，bcc execsnoop 251 条 line_info 中 22 条指向 replay bytecode 的非法目标。v2 不喂 line_info。 |
| cilium prog 195 errno 13 EACCES / replay context 不全 | replay protocol | 消失 | 初始诊断把 cilium/tetragon 错误归因到 live load context replay 不完整：`prog_flags`、BTF func/line metadata、attach context 等。REJIT syscall 从原 `prog/aux` 复制这些上下文，不需要 daemon 重建。 |

## 当前 daemon 代码量化（多少行 in 各模块）

统计命令是 `rg --files ... -g '*.rs' | xargs wc -l` 和 `rg '\bfn\s+[A-Za-z0-9_]+' ... | wc -l`，没有运行 test/build。当前 `daemon/src + daemon/crates/{bpfget,bpfverify,bpfrejit}` 合计 6,756 行 Rust、337 个 `fn`。

| 模块 | Rust 行数 | fn 数 | 备注 |
| --- | ---: | ---: | --- |
| `daemon/src` | 3,459 | 182 | daemon socket/watch/orchestration；其中 `commands.rs` 2,148 行、107 fn。 |
| `daemon/src/bpf.rs` | 212 | 15 | BPF helper/reader。 |
| `daemon/src/invalidation.rs` | 346 | 24 | map-inline invalidation。 |
| `daemon/src/server.rs` | 715 | 35 | runner socket JSON。 |
| `daemon/crates/bpfget` | 1,851 | 81 | snapshot、map fd ownership、map relocation、BTF normalization、target probing。 |
| `daemon/crates/bpfverify` | 1,369 | 70 | `lib.rs` 425 行 dry-run；`verifier_log.rs` 944 行 verifier-state parser。 |
| `daemon/crates/bpfrejit` | 77 | 4 | thin wrapper over `kernel_sys::prog_rejit`。 |

删除范围之外的体量：`bpfopt/crates/bpfopt` 25,085 行、1,175 fn（CLI main 1,553 行）；`bpfopt/crates/bpfprof` 1,412 行、56 fn（main 1,290 行）；`kernel-sys` 2,178 行、100 fn。`kernel-sys` 仍应保留，因为它是唯一 syscall boundary，且已有 `prog_rejit` log buffer retry 到 256MB、`prog_get_original`、`prog_info`、BTF/prof helpers。

ABI 证据支持大方向：`vendor/linux-framework/kernel/bpf/syscall.c:3636-3644` 在 REJIT 内部设置 `load_attr.prog_type = prog->type`、`expected_attach_type`、`log_*`、`prog_flags = prog->aux->prog_flags`、`fd_array_cnt`；`3675-3689` 复制 `attach_btf`、`attach_btf_id`、`dst_prog`；`3719-3755` 对 EXT/freplace 预填原 BTF/func_info；`3760` 调 `bpf_check(&tmp, &load_attr, ...)`，所以 kernel 会走完整 verifier path。也就是说 daemon 当前的 dry-run verifier 与 replay context 大部分是在重复 kernel 已经会做的事。

## v2 风格保留的部分（bpfopt + bpfprof + kernel-sys + 简化 daemon）

保留 `bpfopt` CLI 作为 pure bytecode transformer：stdin/stdout 仍是 raw `struct bpf_insn[]`，daemon 不链接 bpfopt lib、不在进程内跑 pass。保留 `bpfprof` CLI，因为 profile/PMU 是独立工具，和 REJIT replay 无关。保留 `kernel-sys`，尤其是 `BPF_PROG_REJIT`、`BPF_PROG_GET_ORIGINAL`/original bytecode 读取、`BPF_OBJ_GET_INFO_BY_FD` 和 map/profile helpers。

简化 daemon 只需要：socket server、program watch、map invalidation、读取原 bytecode、启动 `bpfopt optimize`、把 optimized bytecode 交给 `BPF_PROG_REJIT`。`GET_ORIGINAL` 作为“拿到原 bytecode”的 API 可以保留；要删除的是 `GET_ORIGINAL -> reconstruct map/BTF/load context -> BPF_PROG_LOAD dry-run -> 再 REJIT` 的 replay protocol。

## v2 风格删除的部分（bpfverify lib / verifier-states-out / BTF normalization / 等）

可以删除或大幅压缩的复杂度：

- `bpfverify` library 全部 1,369 行：final dry-run、original verifier-state capture、verifier log parser、watchdog thread 都不再是 daemon 主路径。
- `verifier-states-out` 协议：当前 `commands.rs` 仍会在 const_prop 时写 `verifier-states.json` 并调用 `kernel.verifier_states()`；v2 daemon 不应生成这个 side input。`bpfopt const-prop` 可保留为离线/显式 side-input pass，但 live daemon 默认不能依赖它，否则 dry-run 又回来了。
- BTF func_info/line_info replay normalization：`bpfget` 里 `normalize_func_info_for_insns`、`normalize_line_info_for_insns` 以及真实 bcc fixture 测试，都是为了重新喂 BPF_PROG_LOAD；v2 REJIT 不提交这些字段。
- map_fds / resolved pointer reconstruct：当前 `ProgramSnapshot::relocate_for_load`、snapshot-owned map fds、resolved kernel map pointer rewrite 是 dry-run/replay 需要的。目标 v2 应由 REJIT ABI 使用原 program map context；若当前 ABI未补齐，则只保留最小 map fd array 生成，不保留 JSON/reconstruct 体系。
- `bpfrejit` crate 可内联成 daemon 调 `kernel_sys::prog_rejit` 的几十行；单独 daemon-owned crate 没有足够价值。
- verifier watchdog/timeout 策略：`fca13a39` 加的 in-process watchdog是为 dry-run 兜底。v2 只需 bpfopt subprocess timeout；kernel REJIT 的错误通过 syscall errno/log 自然返回。

## 量化代码净减少估计（前后行数对比）

当前 daemon kernel-facing 面是 6,756 行。合理目标是 1,300-2,000 行 raw Rust（保守含 server、watch、invalidation 和必要测试），或 900-1,500 行生产 orchestrator。估计删除：

| 项 | 当前行数 | 回滚后 | 净减少 |
| --- | ---: | ---: | ---: |
| `bpfverify` | 1,369 | 0 | -1,369 |
| `bpfget` | 1,851 | 250-450 | -1,400 左右 |
| `commands.rs` | 2,148 | 700-1,000 | -1,100 到 -1,400 |
| `bpfrejit` | 77 | 0-40 | -40 左右 |
| BTF/map replay 测试与残留 | 已含在上面 | 少量保留 | -600 到 -900（重叠估算） |

净减少约 4,700 行，误差约 500 行；也就是 daemon 相关 Rust 体量下降 65%-75%。这还没有计算 round4-6 为 timeout/ramp/replay 增加的 churn：`441ad97f`、`7c768acd`、`e9c6bf69`、`dc92a15c` 仅 `daemon/src/commands.rs` 就累计约 +456/-99，`9bbd56f8` pivot 又新增 daemon-owned libs，`b8f4b21b` line_info 修复单文件 +569/-1。v2 回归直接砍掉这条 churn 来源。

## 风险与代价

第一，不能提前知道 candidate 会不会被 verifier 接受；失败点后移到 `BPF_PROG_REJIT`。这符合“不过滤任何 ReJIT program”的项目规则，但 failure artifact 从“pre-verify report”变成“REJIT errno + log”。好消息是 syscall.c 已把 `attr->rejit.log_level/log_size/log_buf` 传入 `load_attr`，`kernel-sys::prog_rejit` 也已经支持 log buffer 和 ENOSPC 扩容，所以并非完全没有 verifier log。

第二，live `const_prop` 是主要功能代价。它需要真实 verifier states；如果 daemon 不做 dry-run，就不能在默认 live path 中启用它。推荐把 `const-prop` 保留在 `bpfopt` CLI，但从 daemon 默认 pass list 中移出，除非调用方显式提供 verifier-states side file。

第三，map fd ABI 需要一次硬核确认。当前 `verifier.c` 对 `BPF_PSEUDO_MAP_IDX` 明确要求 `env->fd_array`，而 `syscall.c` 当前只是复制用户传入 fd_array，并未明显从 `prog->aux->used_maps` 自动构造。若用户目标是“完全不做 map relocation”，需要在 kernel REJIT 内补一个小的 used_maps -> fd_array 兼容层；否则 daemon 仍要保留极小 map fd supplier。

## 推荐方案 + 优先级 + 步骤

推荐做 v2-style rollback，但不是回到旧 daemon pass manager；应保留 v3 已经做对的两件事：`bpfopt`/`bpfprof` 仍是 CLI，`kernel-sys` 仍是唯一 syscall boundary。

优先级：

1. 先定 ABI：确认或补齐 REJIT 对原 program map context 的复用。如果不能补，明确保留最小 map fd array builder，避免再次承诺“零 map replay”。
2. 切 daemon 主路径：`snapshot bytecode -> bpfopt optimize -> BPF_PROG_REJIT`，删除 final dry-run verify 和 original verifier-state capture。
3. 从 daemon 默认 pass 中移出 `const_prop`；`bpfopt const-prop` 作为离线/显式 side-input pass 保留。
4. 删除 `daemon/crates/bpfverify`，压缩 `bpfget` 到 bytecode/prog-info/target probing 必需子集，内联或删除 `bpfrejit` crate。
5. 更新 `docs/tmp/bpfopt_design_v3.md`，把设计文档从“daemon-owned bpfget/bpfverify/bpfrejit libs”改成“daemon-owned REJIT syscall, no pre-verify replay”。
6. 最后跑最小 daemon unit + `make vm-corpus`，重点看 failure payload 是否自然记录所有 REJIT errno，而不是过滤。

## 是否值得做（结合 9 轮调试时间成本）

值得。round2-6 加 pivot 的调试时间主要没有花在 optimizer 本身，而是花在“让 daemon 假装重新 BPF_PROG_LOAD 原 live program”上：map pointer、BTF records、prog_flags、line_info offset、verifier-state timeout、failure artifact。weekly report 的分类也把 cross-process/load-context、relocation、timeout、line_info 合计列为主要 bug 来源。v2-style rollback 把这些 bug source 从 daemon 中删除，让 kernel REJIT 的 verifier path 成为唯一验收点。代价是失去 live const_prop 和 pre-verify reject 预知，但这两个代价都比 4,700 行复杂度和 6/6 类 ReJIT bug 反复修补更可控。
