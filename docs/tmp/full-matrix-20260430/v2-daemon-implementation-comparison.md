# v2 vs Current Daemon: Implementation-Detail Comparison

对比对象：`daa5bd48^ = 4fc97556` 的最后一个 v2 daemon，以及当前 `d3c3a19d`。另查 `681f5ba8^`，因为最后 v2 已经移除了 daemon 内 verifier-log parser；“v2 const_prop 由 daemon 刷 verifier states”只对更早的 PassManager 时代成立。

核心结论：v2 没暴露当前 round 12 的 thin dry-run `BPF_PROG_LOAD` 失败，不等于 v2 已正确支持这些 replay 场景。v2 final path 是 existing `prog_fd` 上的 `BPF_PROG_REJIT`，per-pass `BPF_PROG_LOAD` 失败只回滚单 pass；部分历史 state 捕获错误曾 warning-and-continue；并且 v2 corpus 没覆盖 calico/cilium/otel，tetragon/katran 规模也小得多。

## v2 daemon 主路径架构（commit + 代码片段）

`4fc97556:daemon/src/pipeline.rs` 文件头说明 v2 daemon 负责 live-kernel concerns：kinsn `fd_array`、per-pass verifier dry-runs、verifier-state refresh、rejected transform rollback。主流程在 `commands.rs`：打开 live prog fd，取 `BPF_PROG_GET_ORIGINAL` 原始 insns，取 `prog_info.map_ids`，构造 `BpfProgram`，daemon 内直接跑 `passes::build_full_pipeline()`。

```rust
let (info, orig_insns) = bpf::bpf_prog_get_info(prog_fd.as_raw_fd(), true)?;
let map_ids = bpf::bpf_prog_get_map_ids(prog_fd.as_raw_fd())?;
let mut program = BpfProgram::new_with_provider(orig_insns, provider);
program.set_map_ids(map_ids);
let pm = passes::build_full_pipeline();
```

per-pass verify 在 daemon 内。`run_single_pass_with_verifier` 先 clone pass 前 program/fd 状态，pass 改完后调用 verifier；若 rejected，就恢复旧 program 并继续。v2 的 `BPF_PROG_LOAD` failure 因此是 pass-local rollback，不是 app-level error。

```rust
let before_program = program.clone();
pass.run(program)?;
match verifier(pass.name(), program)? {
    Rejected { .. } => *program = before_program,
    Accepted => program.verifier_states = verify.verifier_states.clone(),
}
```

verify closure 会 clone 当前 insns，做 map fd relocation，build kinsn `fd_array`，直接 syscall `BPF_PROG_LOAD`。最终提交则再次 relocation 后调用 `BPF_PROG_REJIT`。当前 `d3c3a19d` 相反：daemon snapshot -> 写 `prog.bin/info.json` -> 生成 side inputs -> fork+exec `bpfopt optimize` -> 读 `opt.bin` -> rewrite map refs to fd-array indices -> `kernel.rejit(...)`。daemon 不再有 PassManager，也没有 per-pass rollback。

## v2 const_prop verifier states 获取（代码片段）

const_prop pass 本身 v2/current 基本一致：从 `program.verifier_states` 构建 oracle，按 `(pc, reg)` 查 verifier scalar 常量事实。证据在 `4fc97556:bpfopt/crates/bpfopt/src/passes/const_prop.rs`。

```rust
let oracle = VerifierExactConstOracle::from_states(program.verifier_states.as_ref());
...
if let VerifierInsnKind::InsnDeltaState(delta) = &state.kind {
    // index verifier facts by pc/reg
}
```

关键差异是 states 来源。最后 v2 `4fc97556` 的 daemon per-pass `bpf_prog_load_verify` 只判断 accepted/rejected，closure 返回 `PassVerifyResult::accepted()`，没有 parse load log 更新 states；`set_verifier_states` 主要只剩 CLI/tests 使用。因此最后 v2 corpus 路径并不能证明 const_prop 持续拿到了真实 per-pass states。

更早的 `681f5ba8^:daemon/src/commands.rs` 才是“daemon 内 states”版本：原始 program 先用 `bpf_prog_rejit_capture_verifier_log(prog_fd, &probe_insns, &[])` 捕获 verifier log；每个 pass 的 `BPF_PROG_LOAD` accepted 后再 `parse_verifier_states_from_log`，返回 `accepted_with_verifier_states(states)`。这说明 v2 早期初始 states 不是靠完整 `BPF_PROG_LOAD` replay，而是 existing prog fd 上的 `BPF_PROG_REJIT(log_level=2)`。

当前 `d3c3a19d:daemon/src/dry_run.rs` 则在 `const_prop`/`map_inline` 启用时强制 thin `BPF_PROG_LOAD` side input，且传 `func_info: None`、`line_info: None`；失败直接让 program/app error。

## v2 multi-subprog 处理

v2 per-pass dry-run 比当前 thin dry-run 更接近 live load context。`4fc97556:daemon/src/bpf.rs` 用 `BPF_OBJ_GET_INFO_BY_FD` 读取 live program 的 `func_info`/`line_info` bytes，并在 `populate_prog_load_attr` 填 `prog_btf_fd`、func/line rec size/count、attach metadata 和 `fd_array`。所以 v2 不是“裸 bytecode + no func_info”。

但 v2 final `BPF_PROG_REJIT` 不重新提交 func/line info，只传 existing `prog_fd`、新 insns、log、`fd_array`；kernel 可沿用 live program 已有 aux/metadata。当前 calico `prog 130`、tetragon `prog 322` 的 `func#0/func#1/...` failure，是当前 thin load replay 才需要重新满足的上下文，不是 v2 final path 的必经点。

## v2 map relocation 处理

v2 不直接复用 kernel `used_maps[]` 指针，而是复用 `prog_info.map_ids` 顺序。`BpfProgram::set_map_ids` 扫描 original insns 中 `BPF_PSEUDO_MAP_FD`/`BPF_PSEUDO_MAP_VALUE` 的旧 loader fd，按首次出现顺序绑定 old fd -> map id。verify/final 前，daemon 用 map id reopen live map fd，并把 insn immediate patch 成真实 fd，`OwnedFd` guard 保持生命周期。

```rust
let fd = bpf_map_get_fd_by_id(map_id)?;
insn.imm = fd.as_raw_fd();
guards.push(fd);
```

当前 `d3c3a19d` 改成 fd-array 模型：map fds 放在 fd_array 前缀，`rewrite_pseudo_map_fds_to_indices` 把 `MAP_FD/VALUE` 改成 `MAP_IDX/IDX_VALUE`，imm 是 map index。这修掉 stale fd，但仍要求 original bytecode 的 map reference 可被 old-fd first-seen 识别。katran `prog 733` 的 multi-map/kernel-pointer-immediate 失败说明当前 replay 表达仍有 program shape 没覆盖；v2 katran corpus 只有 1 个小 program，不能证明它覆盖了该形态。

## v2 是 in-memory 改 bytecode 还是 replay？

v2 不是直接改 kernel `prog->aux->insns`。它仍是 userspace replay：`BPF_PROG_GET_ORIGINAL` 取原始 insns，daemon 内 PassManager 修改 `BpfProgram.insns`，最后 `BPF_PROG_REJIT` 提交。

真正差别是：v2 final acceptance 不走 `BPF_PROG_LOAD`，而是在 existing prog fd 上 ReJIT；per-pass load 只是优化防护栏，失败可 rollback。当前 thin dry-run 是 default `const_prop`/`map_inline` 的硬 side-input，失败不能 rollback，只能 fail-fast。所以当前 failure 的根因是“side-input generation 重新构造了极简 load context”，不是简单的“v2 in-memory、v3 replay”。

## v2 corpus 实际跑过哪些 app（按 result 目录验证）

`corpus/results/x86_kvm_corpus_20260413_222825_453420/result.md` 是 v2-era 30 samples、status ok：10 个 bcc case、scx/rusty、tetragon/default、katran、tracee/default、6 个 bpftrace case。对应 `result.json` 聚合：tetragon 7/7 ok，katran 1/1 ok，tracee 10/10 ok。

较早 `vm_corpus_20260403_201849/result.md` 也是 20 apps：tetragon 5 个 program、katran 1 个、tracee 13 个。全目录未看到 calico、cilium、otelcol-ebpf-profiler 的 per-app result。

当前 round 12 failing set 是另一批覆盖面：calico `prog 130` errno 22 multi-subprog，otel `150` errno 28 log buffer，cilium `181` errno 13 replay context，tetragon `322` errno 22 mark_precise/multi-subprog，katran `733` errno 22 multi-map/kernel pointer immediate，tracee `783` errno 28。v2 没有证明覆盖这些具体 shape。

## 借鉴清单：当前能直接抄什么

可借鉴 v2 早期的方向：verifier-state side input 尽量从 existing `prog_fd` 上捕获，比如 `BPF_PROG_REJIT(log_level=2)` 或新的 verify-only/log-only kernel primitive，而不是重新构造 `BPF_PROG_LOAD`。这不需要回滚 v3 CLI 架构，只替换 side-input 生成方式。

可借鉴 v2 的 error evidence：打印 func/line presence、prog_btf_fd、attach fields、map binding、fd_array map/BTF 分段、verifier log 前几行。也可借鉴 log buffer 扩容，但不能抄 v2 的 log_level=0 success fallback；当前 fail-fast 下，ENOSPC 应该扩容后仍失败为清晰错误。

old-fd first-seen -> `prog_info.map_ids` 的绑定机制仍可保留。普通 multi-map 它是合理的；需要补的是 kernel pointer immediate 或无法从 original insns 识别的 map reference 形态。

## 不能借鉴：v2 跟当前架构本质差别

不能搬回 daemon 内 PassManager 或 per-pass rollback；v3 设计要求 bytecode transform 在 `bpfopt` CLI，daemon 只做 live discovery、side-input、fd-array、final ReJIT。

不能照抄 warning-and-continue。早期 v2 verifier-state capture 失败会 warning 后继续，最后 v2 `bpf_prog_load_verify` 还存在 ENOSPC 后 log_level=0 复验成功即 accepted 的行为；这与当前 no fallback/no silenced errors 冲突。

也不能把 v2 corpus ok 当成 correctness proof。v2 没跑 calico/cilium/otel，katran/tetragon program count 明显小；“v2 没问题”很大部分是 coverage mismatch 和 error semantics mismatch。

## 推荐方案（不 revert v2，但学 v2 哪几招）

主线建议：保留当前 v3 CLI 架构，把 verifier-state side-input 从 thin `BPF_PROG_LOAD` 改成 live-prog-context capture。daemon 仍 snapshot 原始 insns，仍 fork `bpfopt`，但 states 由 existing `prog_fd` 的 ReJIT verifier log 或专用 verify-only primitive 产生。失败仍 exit 1，不 fallback。

短期先改 dry-run 诊断和 log buffer：让 errno 28 变成“扩容后仍不够”或真实 verifier error；让 calico/cilium/katran/tetragon 的错误带上 func/line、attach、map binding、fd_array layout。中期固定 corpus attribution：每次比较 v2/current 都列实际 app/prog count，避免把未覆盖误判为已支持。
