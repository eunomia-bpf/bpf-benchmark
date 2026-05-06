# map_inline fix plans: verifier-state extraction, map-in-map, tetragon ENOSPC

## 0. Scope and constraints

本文件是只读调研交付，不修改 `bpfopt`、daemon、kernel 或 runner 代码。

目标结果文件是 `docs/tmp/map_inline_fix_plans_20260506.md`。

本文件基于 `docs/tmp/map_inline_deepdive_20260505.md` 的上一轮结论继续展开。

上一轮结果路径是 `corpus/results/x86_kvm_corpus_20260505_173741_854355/`，该路径在 deep-dive 中列为 run artifact。`docs/tmp/map_inline_deepdive_20260505.md:5-7`

该 run 的 enabled passes 是 `["noop","map_inline"]`。`docs/tmp/map_inline_deepdive_20260505.md:5-7`

本文件不提出 kernel patch，因为 paper plan 明确要求没有用户确认时不做 kernel changes。`docs/kernel-jit-optimization-plan.md:6`

本文件不提出 runner Python v3 refactor，因为 v3 规则把 runner Python 保持在 daemon socket boundary 上。`CLAUDE.md:86-100`

本文件不提出 ReJIT 过滤，因为设计规则禁止过滤、跳过或排除任何 BPF program from ReJIT。`CLAUDE.md:5-10`

本文件不提出 framework 侧聚合指标，因为框架只能写 raw counter measurements。`CLAUDE.md:15-28`

本文件不提出 silent downgrade，因为 fail-fast 规则要求 unsupported capability 或 command failure exit 1。`CLAUDE.md:70-74`

本文件不提出 CLI crate cross-dependency，因为独立 CLI crates 之间禁止 compile-time dependencies。`CLAUDE.md:103-112`

本文件保持 `kernel-sys` 为唯一 syscall boundary，因为 `bpfopt`、`bpfprof`、daemon、`bpfget` 都必须经 `kernel-sys` 调 BPF syscall。`CLAUDE.md:114-123`

本文件的修复方案只使用现有 verifier log、现有 map lookup syscalls、现有 `BPF_PROG_REJIT` syscall path。

`bpfopt` 仍然是纯 bytecode CLI tool。`docs/kernel-jit-optimization-plan.md:128-132`

daemon 仍然负责 per-pass orchestration 和 `BPF_PROG_REJIT`。`docs/kernel-jit-optimization-plan.md:120-132`

daemon 当前通过 CLI side inputs 把 verifier states、map values、map ids 传给 `bpfopt`。`daemon/src/commands.rs:553-565`

`bpfopt` 当前用 `--verifier-states`、`--map-values`、`--map-ids` 读取这些 side inputs。`bpfopt/crates/bpfopt/src/main.rs:92-126`

`map_inline` 当前 pass metadata 需要 verifier states、产生 verifier states、需要 map values。`bpfopt/crates/bpfopt/src/passes/mod.rs:86-89`

`noop` 当前先于 `map_inline` 注册，目的是先产生 verifier states。`bpfopt/crates/bpfopt/src/passes/mod.rs:102-105`

`BpfProgram` 当前保存 `verifier_states`、`map_values`、`map_value_nulls`、`map_metadata` 和 `map_provider`。`bpfopt/crates/bpfopt/src/pass.rs:86-124`

`SnapshotMapProvider` 当前只暴露 `map_info`、`lookup_value_size`、`lookup_elem`。`bpfopt/crates/bpfopt/src/pass.rs:139-160`

`MapInlineRecord` 当前只记录 `map_id`、`key`、`value`。`bpfopt/crates/bpfopt/src/pass.rs:542-548`

本文件的三个修复项按实现顺序建议为：先修 ENOSPC，再修 verifier-state key extraction，最后修 map-in-map。

这个顺序的原因是 ENOSPC 是硬错误，key extraction 是最大 coverage unlock，map-in-map 依赖更稳定的 key extraction。

deep-dive 的 coverage 排序把 verifier-state/key extraction 放在第一，map-in-map 放在第二，tetragon ENOSPC 放在第三。`docs/tmp/map_inline_deepdive_20260505.md:699-709`

本文的实施排序把 ENOSPC 前置，是为了先消除 hard error 并让 Tetragon 后续 coverage 修复可观测。

## 0.1 Shared current result facts

该 run 的成功 applies 总数是 1,604。`docs/tmp/map_inline_deepdive_20260505.md:67-72`

1,604 个 applies 全部是 direct pseudo-map-value constantization。`docs/tmp/map_inline_deepdive_20260505.md:39-45`

helper lookup path 的 successful inlines 是 0。`docs/tmp/map_inline_deepdive_20260505.md:67-72`

helper lookup path matched/skipped 6,277 sites。`docs/tmp/map_inline_deepdive_20260505.md:74-81`

helper lookup path 中 4,588 sites 的 skip reason 是 `lookup key is not available from verifier-guided state`。`docs/tmp/map_inline_deepdive_20260505.md:74-81`

helper lookup path 中 1,143 sites 的 skip reason 是 `map type 13 not inlineable`，也就是 `HASH_OF_MAPS`。`docs/tmp/map_inline_deepdive_20260505.md:74-89`

helper lookup path 中 107 sites 的 skip reason 是 `map type 12 not inlineable`，也就是 `ARRAY_OF_MAPS`。`docs/tmp/map_inline_deepdive_20260505.md:74-89`

map-in-map 两类合计 1,250 unsupported sites。`docs/tmp/map_inline_deepdive_20260505.md:631-634`

Tetragon 有 88 pass errors。`docs/tmp/map_inline_deepdive_20260505.md:427-442`

Tetragon 的 88 pass errors 由 44 个 `noop failed_rejit` 和 44 个 `map_inline skipped_missing_states` 组成。`docs/tmp/map_inline_deepdive_20260505.md:437-442`

`noop failed_rejit` 的 root 是 kernel rejected `BPF_PROG_REJIT` with errno 28 / ENOSPC。`docs/tmp/map_inline_deepdive_20260505.md:437-442`

`map_inline skipped_missing_states` 是 secondary error，因为前置 `noop` 没有产生 verifier states。`docs/tmp/map_inline_deepdive_20260505.md:444-449`

Tetragon 非 error 的 `map_inline` reports 仍然是 0 applies。`docs/tmp/map_inline_deepdive_20260505.md:524-533`

Tetragon 非 error reports 有 3,318 matched/skipped sites。`docs/tmp/map_inline_deepdive_20260505.md:524-533`

Tetragon 非 error reports 有 2,832 key-state skips。`docs/tmp/map_inline_deepdive_20260505.md:524-533`

Tetragon 非 error reports 有 105 `ARRAY_OF_MAPS` skips。`docs/tmp/map_inline_deepdive_20260505.md:524-533`

Tetragon 非 error reports 有 35 `HASH_OF_MAPS` skips。`docs/tmp/map_inline_deepdive_20260505.md:524-533`

Tracee 有 2,522 matched map_inline sites。`docs/tmp/map_inline_deepdive_20260505.md:408-415`

Tracee 有 133 direct pseudo-map-value applies。`docs/tmp/map_inline_deepdive_20260505.md:408-415`

Tracee 有 1,287 key-state skips。`docs/tmp/map_inline_deepdive_20260505.md:408-415`

Tracee 有 1,102 `HASH_OF_MAPS` skips。`docs/tmp/map_inline_deepdive_20260505.md:408-415`

Otelcol 有 1,593 matched sites。`docs/tmp/map_inline_deepdive_20260505.md:167-186`

Otelcol 有 1,192 direct applies。`docs/tmp/map_inline_deepdive_20260505.md:167-186`

Otelcol 仍有 367 key-state skips。`docs/tmp/map_inline_deepdive_20260505.md:167-186`

Otelcol 仍有 4 `HASH_OF_MAPS` skips。`docs/tmp/map_inline_deepdive_20260505.md:167-186`

Katran 有 64 key-state skips。`docs/tmp/map_inline_deepdive_20260505.md:212-215`

Katran 有 2 `ARRAY_OF_MAPS` skips 和 2 `HASH_OF_MAPS` skips。`docs/tmp/map_inline_deepdive_20260505.md:212-215`

Cilium 有 279 direct applies。`docs/tmp/map_inline_deepdive_20260505.md:167-186`

Cilium 只有 2 key-state skips，map-in-map 不是 Cilium 当前主要 blocker。`docs/tmp/map_inline_deepdive_20260505.md:167-186`

## 0.2 Current map_inline execution path facts

`find_map_lookup_sites()` 只匹配 helper call `BPF_FUNC_map_lookup_elem`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:123-135`

`find_map_lookup_sites()` 对每个 matched call 还要求 `find_map_load_for_call()` 能找到 map load。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:127-135`

`find_map_load_for_call()` 只向后找最近的 `r1` def，并要求它是 pseudo map fd load。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1485-1499`

因此当前 helper site model 是 `r1 = ldimm64 pseudo_map_fd; r2 = key; call map_lookup_elem`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:127-135`

当前 direct pseudo-map-value path 另走 `replace_direct_map_value_loads()`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1234-1337`

direct path 的 diagnostic 是 `constantized pseudo-map-value load from map_id=...`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1325-1331`

当前 helper path 在 `run_map_inline_round()` 中先取 `MapInfoAnalysis`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:691-706`

当前 helper path 读取 map id、map type、key_size、value_size、max_entries 后先做 map type gate。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:737-745`

当前 map type gate 调用 `info.supports_direct_value_inline()`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:746-762`

当前 unsupported map type reason 是 `map type {} not inlineable`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:746-762`

当前 key extraction 在 map type gate 之后执行。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`

当前 key extraction failure 的 common skip reason 是 `lookup key is not available from verifier-guided state`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:779-787`

当前 key extraction failure 的 optional diagnostic 会包含 detail。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:779-787`

当前 key extraction 的 concrete snapshot errors 会 hard error。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:769-778`

当前 key extraction 默认不允许 rewrite 后的 non-verifier guided path。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1036-1080`

当前 helper rewrite 需要 `build_site_rewrite()` 从 map snapshot 读 value。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1082-1217`

当前 value preparation 对 `PERCPU_ARRAY` 做 uniform collapse。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1409-1447`

当前 hash-like map 在 missing/null snapshot 时 site-veto，而非直接 hard error。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1092-1113`

当前 `is_hash_like_map_type()` 包括 `HASH`、`PERCPU_HASH`、`LRU_HASH`、`LRU_PERCPU_HASH`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1511-1523`

当前 `is_hash_like_map_type()` 不包括 `HASH_OF_MAPS`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1511-1523`

## 0.3 Current verifier log and side-input facts

kernel verifier log parser说明它处理 `log_level=2` 捕获的 verifier logs。`bpfopt/crates/kernel-sys/src/verifier_log.rs:1-12`

parser 从 log lines 中 `filter_map(parse_state_line)` 得到 state snapshots。`bpfopt/crates/kernel-sys/src/verifier_log.rs:20-22`

parser 的 internal `VerifierInsn` 包含 regs 和 stack。`bpfopt/crates/kernel-sys/src/lib.rs:126-146`

parser 能解析 leading `P` precise marker。`bpfopt/crates/kernel-sys/src/verifier_log.rs:285-320`

parser 能解析 stack token。`bpfopt/crates/kernel-sys/src/verifier_log.rs:330-376`

parser 能从 scalar tnum 或 min/max 推导 exact scalar。`bpfopt/crates/kernel-sys/src/verifier_log.rs:449-475`

`VerifierStatesJson` 当前只序列化 `insns`。`bpfopt/crates/kernel-sys/src/lib.rs:188-192`

`VerifierInsnJson` 当前只序列化 `pc`、`frame`、`regs`。`bpfopt/crates/kernel-sys/src/lib.rs:194-201`

`VerifierRegJson` 当前只序列化 type、offset、const_val、min、max、tnum。`bpfopt/crates/kernel-sys/src/lib.rs:203-217`

`convert_verifier_state()` 当前只把 regs 放进 JSON。`bpfopt/crates/kernel-sys/src/lib.rs:379-389`

`convert_verifier_state()` 当前丢弃 internal stack。`bpfopt/crates/kernel-sys/src/lib.rs:379-389`

`bpfopt` 的 `read_verifier_states()` 当前把 JSON 读回 `VerifierInsn`。`bpfopt/crates/bpfopt/src/main.rs:917-939`

`read_verifier_states()` 当前把 `stack` 初始化为空 map。`bpfopt/crates/bpfopt/src/main.rs:928-935`

`verifier_reg_state()` 当前把 `precise` 设置为 `exact_value.is_some()`。`bpfopt/crates/bpfopt/src/main.rs:955-963`

因此当前 JSON contract 丢弃了 kernel parser 已经拥有的 stack 和 explicit precise flag。`bpfopt/crates/kernel-sys/src/lib.rs:379-389`, `bpfopt/crates/bpfopt/src/main.rs:928-935`

kernel verifier 在 log level 2 下会打印 `mark_precise: frame... regs=... stack=... before ...`。`vendor/linux-framework/kernel/bpf/verifier.c:4718-4725`

kernel verifier 在 log level 2 下会打印 parent state precise trace，然后调用 `print_verifier_state()`。`vendor/linux-framework/kernel/bpf/verifier.c:5365-5374`

kernel verifier 在 normal log level path 会在 scratched state 时调用 `print_insn_state()`。`vendor/linux-framework/kernel/bpf/verifier.c:21630-21637`

因此 Issue 1 不需要 kernel patch；需要的是 userspace parser/JSON/pass 继续携带已有信息。

## 1. Issue 1: verifier-state/key extraction for ~4,588 helper sites

### A. Root cause analysis

#### A.1 Observed blocker

该 run 有 4,588 helper sites 因 `lookup key is not available from verifier-guided state` 被跳过。`docs/tmp/map_inline_deepdive_20260505.md:74-81`

该 reason 是所有 zero-helper-inline blockers 中数量最大的单项。`docs/tmp/map_inline_deepdive_20260505.md:119-126`

deep-dive 判断 unsupported map types 不是 dominant blocker。`docs/tmp/map_inline_deepdive_20260505.md:119-126`

deep-dive 的 app-level table 显示 Tetragon 有 2,832 key-state skips。`docs/tmp/map_inline_deepdive_20260505.md:183-186`

deep-dive 的 app-level table 显示 Tracee 有 1,287 key-state skips。`docs/tmp/map_inline_deepdive_20260505.md:183-186`

deep-dive 的 app-level table 显示 Otelcol 有 367 key-state skips。`docs/tmp/map_inline_deepdive_20260505.md:183-186`

deep-dive 的 app-level table 显示 Katran 有 64 key-state skips。`docs/tmp/map_inline_deepdive_20260505.md:183-186`

deep-dive 的 examples 显示常见 detail 包括 `verifier log has no state snapshot at call pc`。`docs/tmp/map_inline_deepdive_20260505.md:148-158`

deep-dive 的 examples 显示 Tetragon 还有 16-byte 和 256-byte key sizes。`docs/tmp/map_inline_deepdive_20260505.md:148-158`

因此 4,588 中最常见的 top-level reason 是 `lookup key is not available from verifier-guided state`。`docs/tmp/map_inline_deepdive_20260505.md:74-81`

可见的 detail buckets 至少包括 missing call-PC snapshot 和 key-size 超过当前 8-byte extractor。`docs/tmp/map_inline_deepdive_20260505.md:148-158`

当前 result schema 没有把每个 skip detail 做独立聚合。`docs/tmp/map_inline_deepdive_20260505.md:122-126`

所以本计划不假装给出 4,588 的完整 detail distribution。

#### A.2 Current code path

helper site discovery 在 `find_map_lookup_sites()` 中完成。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:123-135`

helper site discovery 要求 call immediate 是 `HELPER_MAP_LOOKUP_ELEM`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:127-135`

helper site discovery 要求 `find_map_load_for_call()` 能找到 map load。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:127-135`

`run_map_inline_round()` 对 helper sites 执行 map info lookup、map type gate、key extraction、rewrite construction。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:714-868`

key extraction 调用点在 `run_map_inline_round()` 的 `extract_site_constant_key()`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`

当前 key extraction failure 被记录成 `lookup key is not available from verifier-guided state`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:779-787`

`extract_site_constant_key()` 在 first round 调用 `try_extract_constant_key_verifier_guided()`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1036-1080`

`extract_site_constant_key()` 在 prior rewrite 之后不再使用 verifier-guided keys，并返回 unavailable error。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1036-1080`

`try_extract_constant_key_verifier_guided()` 是当前生产路径。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:220-237`

该函数要求 verifier states 非空。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:224-228`

该函数拒绝 zero key size。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:229-231`

该函数拒绝 key_size > 8。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:232-237`

该函数筛选 `state.pc == call_pc` 的 occurrences。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:242-252`

没有 call-PC state 时，explicit error 是 `verifier log has no state snapshot at call pc {}`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:247-252`

每个 occurrence 通过 `try_extract_constant_key_for_occurrence()` 处理。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:254-284`

多个 occurrence 得到不同 candidate 时，explicit error 是 verifier-derived key candidates disagree。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:254-284`

`try_extract_constant_key_for_occurrence()` 先用 `find_latest_r2_stack_offset()` 找 R2 stack pointer。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:287-334`

找不到 R2 stack pointer 时，explicit error 是 `verifier log did not expose r2 stack pointer before pc {}`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:287-334`

然后它用 `find_verifier_guided_stack_store()` 找覆盖 key byte range 的 constant stack store。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:287-334`

找不到 covering store 时，explicit error 是 `verifier log did not expose a constant stack store covering fp{} width {} before pc {}`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:287-334`

`find_latest_r2_stack_offset()` 从 occurrence 往前扫描同 frame state。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:336-355`

`find_latest_r2_stack_offset()` 只接受 reg type 是 `fp` 的 R2。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:336-355`

`find_verifier_guided_stack_store()` 再从 occurrence 往前扫描 state。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:522-548`

`verifier_guided_stack_store_value()` 要求当前 insn 是 stack store 且覆盖 target range。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:550-590`

`verifier_guided_stack_store_value()` 对 `BPF_ST` 使用 immediate。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:550-590`

`verifier_guided_stack_store_value()` 对 `BPF_STX` 使用 source reg 的 exact scalar。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:550-590`

`verifier_known_scalar_value()` 只接受 `reg_type == "scalar"` 且有 exact_u64/exact_u32。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:592-598`

当前 key bytes 临时数组是 `[u8; 8]`，这和 8-byte limit 一致。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:550-590`

#### A.3 Why current code fails

当前 extractor 需要 call-PC snapshot，但 deep-dive examples 已经显示多个 apps 出现 `no state snapshot at call pc`。`docs/tmp/map_inline_deepdive_20260505.md:148-158`

当前 extractor 只支持最多 8-byte key，但 deep-dive examples 显示 Tetragon 有 16-byte 和 256-byte key sizes。`docs/tmp/map_inline_deepdive_20260505.md:148-158`

当前 extractor 从 JSON 里读不到 stack，因为 `read_verifier_states()` 把 stack 初始化为空。`bpfopt/crates/bpfopt/src/main.rs:928-935`

当前 JSON writer 也不序列化 stack，因为 `VerifierInsnJson` 没有 stack field。`bpfopt/crates/kernel-sys/src/lib.rs:194-201`

当前 parser internal 已经能解析 stack token。`bpfopt/crates/kernel-sys/src/verifier_log.rs:330-376`

因此 stack 信息是在 parser internal 到 JSON side input 之间丢掉的。`bpfopt/crates/kernel-sys/src/lib.rs:379-389`

当前 JSON writer 不序列化 explicit precise flag。`bpfopt/crates/kernel-sys/src/lib.rs:203-217`

当前 JSON reader 把 `precise` 推成 `exact_value.is_some()`。`bpfopt/crates/bpfopt/src/main.rs:955-963`

kernel log level 2 已经输出 precision-mark context。`vendor/linux-framework/kernel/bpf/verifier.c:4718-4725`

kernel log level 2 已经输出 parent state precise trace。`vendor/linux-framework/kernel/bpf/verifier.c:5365-5374`

因此 missing information 主要是 userspace side-input fidelity，不是 kernel side absence。

当前 extractor 不直接从 call-PC state 的 stack snapshot 还原 key bytes。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:287-334`

当前 extractor 是先找 R2 fp offset，再找历史 store。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:287-334`

如果 key 是经过 verifier state 里已经精确化的 stack bytes，但历史 store trace 不完整，当前 path 会失败。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:522-590`

如果 key bytes 来自跨多次 store、宽度超过 8、或 call-PC state 有完整 stack 但 JSON 丢掉 stack，当前 path 会失败。`bpfopt/crates/bpfopt/src/main.rs:928-935`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:232-237`

当前 code 不报告 `map fd unknown` 为 4,588 的主因，因为 map reference missing 走 `map reference for lookup site is unavailable`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:714-736`

当前 code 不报告 `called from helper` 为 4,588 的主因，因为 helper site discovery 只看 BPF instruction stream 中的 helper call。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:123-135`

当前 code 不报告 `called inside loop` 为 4,588 的主因，因为 loop safety 不是 key extraction branch 的 explicit skip reason。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`

所以 4,588 的 top-level blocker 是 key extraction state fidelity，而不是 map fd unknown、called from helper、或 called inside loop。

#### A.4 Consumed fields vs needed fields

当前 `map_inline` 实际消耗 `VerifierInsn.pc`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:242-252`

当前 `map_inline` 实际消耗 `VerifierInsn.frame`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:336-355`

当前 `map_inline` 实际消耗 `VerifierInsn.regs[r2].reg_type`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:336-355`

当前 `map_inline` 实际消耗 `VerifierInsn.regs[r2].offset`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:336-355`

当前 `map_inline` 实际消耗 store source reg 的 exact scalar。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:550-598`

当前 `map_inline` 不消耗 `VerifierInsn.stack`，因为 CLI reader 永远给空 stack。`bpfopt/crates/bpfopt/src/main.rs:928-935`

当前 `map_inline` 不消耗 explicit precise flag，because CLI reader reconstructs it from exactness。`bpfopt/crates/bpfopt/src/main.rs:955-963`

修复需要新增消耗 call-PC state 的 stack byte/range snapshot。`bpfopt/crates/kernel-sys/src/verifier_log.rs:330-376`

修复需要保留 parser internal 的 precise flag，以便 debug 和 future gating 不把 imprecise exact-looking range误判为 precision-derived constant。`bpfopt/crates/kernel-sys/src/verifier_log.rs:285-320`

修复需要支持 key_size > 8 的 byte vector，而不是 `[u8; 8]`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:232-237`

### B. Fix plan

#### B.1 Files and functions to modify

修改 `bpfopt/crates/kernel-sys/src/lib.rs` 的 JSON structs。`bpfopt/crates/kernel-sys/src/lib.rs:188-217`

修改 `bpfopt/crates/kernel-sys/src/lib.rs` 的 `convert_verifier_state()`。`bpfopt/crates/kernel-sys/src/lib.rs:379-389`

修改 `bpfopt/crates/kernel-sys/src/lib.rs` 的 `convert_reg_state()`。`bpfopt/crates/kernel-sys/src/lib.rs:392-423`

修改 `bpfopt/crates/bpfopt/src/main.rs` 的 `read_verifier_states()`。`bpfopt/crates/bpfopt/src/main.rs:917-939`

修改 `bpfopt/crates/bpfopt/src/main.rs` 的 `verifier_reg_state()`。`bpfopt/crates/bpfopt/src/main.rs:955-973`

修改 `bpfopt/crates/bpfopt/src/passes/map_inline.rs` 的 `try_extract_constant_key_verifier_guided()`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:220-237`

修改 `bpfopt/crates/bpfopt/src/passes/map_inline.rs` 的 `try_extract_constant_key_for_occurrence()`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:287-334`

修改 `bpfopt/crates/bpfopt/src/passes/map_inline.rs` 的 store-tracing helpers，只让它们作为同一 verifier-backed extraction 的 secondary branch。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:522-598`

不修改 daemon `target.json` contract，因为 key extraction 只需要 verifier-states side input。`daemon/src/commands.rs:553-565`

不修改 kernel verifier，因为 log level 2 已经输出 precise/stack context。`vendor/linux-framework/kernel/bpf/verifier.c:4718-4725`, `vendor/linux-framework/kernel/bpf/verifier.c:5365-5374`

#### B.2 Pseudo-diff sketch

```diff
diff --git a/bpfopt/crates/kernel-sys/src/lib.rs b/bpfopt/crates/kernel-sys/src/lib.rs
@@
 pub struct VerifierInsnJson {
     pub pc: usize,
     pub frame: usize,
+    #[serde(default, skip_serializing_if = "BTreeMap::is_empty")]
+    pub stack: BTreeMap<String, VerifierStackJson>,
     pub regs: BTreeMap<String, VerifierRegJson>,
 }
 pub struct VerifierRegJson {
     #[serde(rename = "type")]
     pub reg_type: String,
+    #[serde(default, skip_serializing_if = "Option::is_none")]
+    pub precise: Option<bool>,
 }
@@
-    (!regs.is_empty()).then_some(VerifierInsnJson { pc, frame, regs })
+    let stack = convert_stack_state(&state.stack);
+    (!regs.is_empty() || !stack.is_empty())
+        .then_some(VerifierInsnJson { pc, frame, stack, regs })
diff --git a/bpfopt/crates/bpfopt/src/passes/map_inline.rs b/bpfopt/crates/bpfopt/src/passes/map_inline.rs
@@
-    if key_size > 8 { return Err(...); }
+    let key_width = checked_key_width(key_size)?;
     let occurrences = states_at_call_pc(...)?;
     for occurrence in occurrences {
+        if let Some(key) = constant_key_from_call_stack_state(occurrence, key_width)? {
+            candidates.push(key);
+            continue;
+        }
         candidates.push(try_extract_constant_key_from_store_trace(...)?);
     }
```

#### B.3 New helpers

Add `VerifierStackJson` in `kernel-sys/src/lib.rs` to encode parser internal `StackState` without changing raw parser semantics.`bpfopt/crates/kernel-sys/src/lib.rs:126-146`

Add `convert_stack_state()` next to `convert_reg_state()` so JSON conversion preserves parsed stack。`bpfopt/crates/kernel-sys/src/lib.rs:392-423`

Add `stack_state_from_json()` in `bpfopt/src/main.rs` so `read_verifier_states()` no longer emits empty stack。`bpfopt/crates/bpfopt/src/main.rs:917-939`

Add `constant_key_from_call_stack_state()` in `map_inline.rs`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:287-334`

Add `r2_stack_range_at_call()` in `map_inline.rs` to read R2 as `fp + off` at call PC。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:336-355`

Add `constant_stack_bytes_for_range()` in `map_inline.rs` to reconstruct `[fp+off, fp+off+key_size)` from stack slots。`bpfopt/crates/kernel-sys/src/verifier_log.rs:330-376`

Add `constant_key_from_bytes()` in `map_inline.rs` so key bytes are not limited to a u64。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:232-237`

Keep `find_verifier_guided_stack_store()` as a secondary verifier-backed branch for logs that have source-reg exactness but no stack slot snapshot。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:522-590`

Keep `verifier_known_scalar_value()` but extend callers to accept arbitrary byte vector assembled from exact scalars。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:592-598`

#### B.4 Side-input contract changes

`verifier-states.json` gains optional `stack` per insn。`bpfopt/crates/kernel-sys/src/lib.rs:194-201`

`verifier-states.json` gains optional `precise` per reg。`bpfopt/crates/kernel-sys/src/lib.rs:203-217`

The new fields must be optional for old artifacts and tests.`bpfopt/crates/bpfopt/src/main.rs:917-939`

`target.json` does not change.`daemon/src/commands.rs:489-518`

`map-values.json` does not change for Issue 1.`bpfopt/crates/bpfopt/src/main.rs:234-254`

No new kernel log field is required because parser already sees stack and precise from current log syntax。`bpfopt/crates/kernel-sys/src/verifier_log.rs:285-320`, `bpfopt/crates/kernel-sys/src/verifier_log.rs:330-376`

No daemon fd-array change is required for Issue 1。`daemon/src/commands.rs:934-1050`

#### B.5 LoC estimate

`kernel-sys/src/lib.rs` JSON structs and conversion: gross 55 LoC, net 45 LoC.

`bpfopt/src/main.rs` JSON reader additions: gross 45 LoC, net 35 LoC.

`map_inline.rs` key extraction additions: gross 130 LoC, net 105 LoC.

Tests and fixtures: gross 120 LoC, net 110 LoC.

Issue 1 total estimate: gross 350 LoC, net 295 LoC.

Issue 1 can stay inside existing files.

Issue 1 does not need a new module unless stack-byte reconstruction grows beyond about 150 LoC.

### C. Daemon-side coordination needed

daemon already writes verifier states for next pass after a state-producing ReJIT。`daemon/src/commands.rs:636-641`

daemon already passes `--verifier-states` to bpfopt when a pass needs states。`daemon/src/commands.rs:553-565`

daemon does not need to understand the new `stack` field if `kernel-sys::verifier_states_from_log()` writes it。`bpfopt/crates/kernel-sys/src/lib.rs:361-389`

daemon does not need to parse `verifier-states.json` because it only writes the JSON file。`daemon/src/commands.rs:769-775`

`kernel-sys::verifier_states_from_log()` is the right place to preserve stack and precise。`bpfopt/crates/kernel-sys/src/lib.rs:361-389`

kernel verifier already emits mark-precise register and stack masks under log level 2。`vendor/linux-framework/kernel/bpf/verifier.c:4718-4725`

kernel verifier already emits parent state with `print_verifier_state()` under log level 2。`vendor/linux-framework/kernel/bpf/verifier.c:5365-5374`

Therefore daemon-side coordination is a side-input schema bump, not a kernel patch。

The schema bump must fail-fast on malformed `stack` JSON rather than treating it as empty。`CLAUDE.md:70-74`

The parser must not silently swallow invalid stack slot encodings。`CLAUDE.md:70-74`

The daemon/bpfopt CLI file format remains JSON on disk and raw bytecode on stdin/stdout。`CLAUDE.md:86-100`

No new in-framework summary field is introduced。`CLAUDE.md:15-28`

### D. Risk and verification

#### D.1 Risks

Verifier reject risk exists if reconstructed key bytes are stale relative to actual verifier control path。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:916-956`

The mitigation is to require all call-PC occurrences to agree on key bytes, matching current candidate agreement logic。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:254-284`

The pass must keep hard-error behavior for concrete snapshot mismatches。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:769-778`

Large keys such as 256 bytes can increase memory copied into report diagnostics if not bounded。`docs/tmp/map_inline_deepdive_20260505.md:148-158`

Report output currently stores inlined key/value bytes through `MapInlineRecord`。`bpfopt/crates/bpfopt/src/pass.rs:542-548`

`map_inline` must not emit a markdown rollup or aggregate site summary as part of this fix。`CLAUDE.md:15-28`

Multi-byte stack assembly can get endian bugs because BPF immediate stores and stack bytes are little-endian。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:550-590`

Partially unknown stack ranges must remain a precise skip reason, not default zeros。`CLAUDE.md:70-74`

Per-CPU map semantics are not solved by Issue 1。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:42-46`

`sk_storage` or storage-like map semantics are not solved by Issue 1 because current supported map types do not include storage maps。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:47-55`

#### D.2 Verification targets

Add a kernel-sys parser/JSON test that preserves parsed stack through `verifier_states_from_log()`。`bpfopt/crates/kernel-sys/src/verifier_log.rs:742-773`

Add a kernel-sys parser/JSON test that preserves explicit precise marker。`bpfopt/crates/kernel-sys/src/verifier_log.rs:285-320`

Add a bpfopt CLI reader test that reads `stack` into `VerifierInsn.stack` instead of empty map。`bpfopt/crates/bpfopt/src/main.rs:917-939`

Add a `map_inline` unit test where call-PC state has R2=`fp-16` and stack bytes encode an 8-byte key, but no preceding store trace exists。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:287-334`

Add a `map_inline` unit test where key_size is 16 and stack snapshot encodes all 16 bytes。`docs/tmp/map_inline_deepdive_20260505.md:148-158`

Add a negative unit test where one byte in the stack range is unknown and the site records `lookup key is not available from verifier-guided state`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:779-787`

Add a disagreement test where two call-PC occurrences produce different key bytes and extraction fails。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:254-284`

Good test location is `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs` because existing tests already cover pass behavior。`docs/tmp/map_inline_deepdive_20260505.md:557-562`

Do not add trivial getter/setter tests because unit test rules require bug-detection purpose。`CLAUDE.md:79-84`

Expected cargo test impact is limited to kernel-sys parser tests, bpfopt CLI JSON tests, and map_inline pass tests.

No benchmark is required to verify this code path.

The proof of corpus impact should come from rerunning existing corpus later, not from framework-side aggregation changes。`CLAUDE.md:15-28`

### E. Expected unlock

Issue 1 can unlock classification of up to 4,588 helper sites currently collapsed under key-state skip。`docs/tmp/map_inline_deepdive_20260505.md:564-573`

Unlock does not mean all 4,588 become applies。`docs/tmp/map_inline_deepdive_20260505.md:574-578`

Some sites will become precise unsupported-key-size, non-constant-key, missing-map-value, or verifier-reject diagnostics。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-868`

Tetragon has the largest observed key-state unlock at 2,832 sites。`docs/tmp/map_inline_deepdive_20260505.md:564-573`

Tracee has the second-largest observed key-state unlock at 1,287 sites。`docs/tmp/map_inline_deepdive_20260505.md:564-573`

Otelcol has 367 key-state sites after its 1,192 direct applies。`docs/tmp/map_inline_deepdive_20260505.md:564-573`

Katran has 64 key-state sites。`docs/tmp/map_inline_deepdive_20260505.md:564-573`

BCC and bpftrace tools have smaller combined key-state opportunities。`docs/tmp/map_inline_deepdive_20260505.md:167-186`

Apps that can shift from 0 helper applies to N helper applies include Tetragon, Tracee, Katran, BCC tools, and bpftrace tools。`docs/tmp/map_inline_deepdive_20260505.md:167-186`

Otelcol and Cilium already have direct applies, but Issue 1 targets their remaining helper skips。`docs/tmp/map_inline_deepdive_20260505.md:167-186`

Tracee code-bloat caveat remains because deep-dive did not support direct-apply code-bloat as the hot regression cause。`docs/tmp/map_inline_deepdive_20260505.md:395-425`

Issue 1 might still increase rewritten instruction count if helper lookup removal and value constants are not net smaller。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:916-956`

Tracee hot programs currently had zero applies in the cited run, so later helper applies in hot programs need explicit JIT-size and run-count review after raw results are produced。`docs/tmp/map_inline_deepdive_20260505.md:378-425`

## 2. Issue 2: map-in-map support for ~1,250 unsupported sites

### A. Root cause analysis

#### A.1 Observed blocker

The run has 1,143 `HASH_OF_MAPS` unsupported sites。`docs/tmp/map_inline_deepdive_20260505.md:74-89`

The run has 107 `ARRAY_OF_MAPS` unsupported sites。`docs/tmp/map_inline_deepdive_20260505.md:74-89`

The two map-in-map families sum to 1,250 unsupported sites。`docs/tmp/map_inline_deepdive_20260505.md:631-634`

Tracee accounts for 1,102 `HASH_OF_MAPS` unsupported sites。`docs/tmp/map_inline_deepdive_20260505.md:112-117`

Tetragon accounts for 105 `ARRAY_OF_MAPS` and 35 `HASH_OF_MAPS` unsupported sites。`docs/tmp/map_inline_deepdive_20260505.md:112-117`

Katran accounts for 2 `ARRAY_OF_MAPS` and 2 `HASH_OF_MAPS` unsupported sites。`docs/tmp/map_inline_deepdive_20260505.md:112-117`

Otelcol accounts for 4 `HASH_OF_MAPS` unsupported sites。`docs/tmp/map_inline_deepdive_20260505.md:112-117`

Map-in-map is the largest unsupported map-type expansion opportunity。`docs/tmp/map_inline_deepdive_20260505.md:605-636`

Deep-dive explicitly warns not to simply add these types to `supports_direct_value_access()`。`docs/tmp/map_inline_deepdive_20260505.md:620-629`

#### A.2 Current code path

`MapInfo` currently contains `map_type`、`key_size`、`value_size`、`max_entries`、`map_id`。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:27-33`

`MapInfo` currently has no inner map id, inner map fd, or inner map metadata field。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:27-33`

`supports_direct_value_access()` only allows `HASH`、`ARRAY`、`PERCPU_ARRAY`、`LRU_HASH`。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:47-55`

`supports_direct_value_inline()` simply delegates to `supports_direct_value_access()`。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:57-60`

`HASH_OF_MAPS` and `ARRAY_OF_MAPS` therefore fail the current map type gate。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:746-762`

The explicit skip reason is `map type {} not inlineable`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:746-762`

daemon's `is_map_inlineable_map_type()` uses the same four-type policy。`daemon/src/commands.rs:881-889`

daemon's `write_live_map_values()` skips maps whose type is not inlineable。`daemon/src/commands.rs:802-809`

daemon's `live_bpf_map_keys()` returns empty key list for non-inlineable map types。`daemon/src/commands.rs:347-350`

daemon's current map snapshot therefore does not collect outer map-in-map entries。`daemon/src/commands.rs:802-809`

`MapValuesJson` current schema stores maps metadata and entries as key/value hex。`bpfopt/crates/bpfopt/src/main.rs:234-254`

`read_map_values()` reads map metadata and entries into snapshot provider maps。`bpfopt/crates/bpfopt/src/main.rs:1002-1046`

`parse_map_type()` currently knows names for hash, array, percpu_hash, percpu_array, lru_hash, lru_percpu_hash。`bpfopt/crates/bpfopt/src/main.rs:1048-1068`

`parse_map_type()` currently lacks named parsing for `hash_of_maps` and `array_of_maps`。`bpfopt/crates/bpfopt/src/main.rs:1048-1068`

Numeric map types still work if JSON emits numeric values。`bpfopt/crates/bpfopt/src/main.rs:1048-1068`

#### A.3 Why current code fails

The current gate treats outer map values as ordinary scalar backing values。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:47-60`

A map-in-map outer value is an inner map reference, not the scalar bytes loaded by the BPF program。`docs/tmp/map_inline_deepdive_20260505.md:612-618`

The current helper site scanner requires each helper call's map argument R1 to come from a pseudo-map fd load。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:127-135`

Inner map lookups often use the result of an outer lookup as the map argument, not an `ldimm64` pseudo map fd。`vendor/linux-framework/kernel/bpf/verifier.c:2259-2273`

The verifier converts a non-null outer map lookup result to `CONST_PTR_TO_MAP` when `map->inner_map_meta` exists。`vendor/linux-framework/kernel/bpf/verifier.c:2259-2273`

Therefore current `find_map_load_for_call()` cannot discover an inner lookup whose R1 is copied from the outer lookup result。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1485-1499`

The daemon fd-array currently includes map fds from `prog_info.map_ids` first。`daemon/src/commands.rs:934-939`

The daemon appends a fd for each map id in `snapshot.info.map_ids`。`daemon/src/commands.rs:1017-1022`

`ProgramInfo.map_ids` is populated from `kernel_sys::prog_map_ids(fd, info.nr_map_ids)`。`daemon/src/bpf.rs:130-138`

Inner maps that are only values of an outer map are not represented in the current `MapInfoJson` fields。`daemon/src/bpf.rs:31-38`

So side input currently lacks both outer entry-to-inner id mapping and inner map metadata/value snapshots。`daemon/src/commands.rs:802-838`

#### A.4 Consumed fields vs needed fields

Current pass consumes outer `map_id` and `map_type` from `MapInfo`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:737-745`

Current pass consumes outer `key_size` for key extraction。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`

Current pass consumes map value snapshot through `program.map_provider.lookup_elem()`。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1082-1137`

Map-in-map needs outer map key bytes。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`

Map-in-map needs outer entry value interpreted as inner map id or inner map reference。`docs/tmp/map_inline_deepdive_20260505.md:612-618`

Map-in-map needs inner map metadata。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:27-33`

Map-in-map needs inner map key bytes for the second lookup。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`

Map-in-map needs inner map value snapshot。`bpfopt/crates/bpfopt/src/pass.rs:139-160`

Map-in-map needs verifier path proof that outer lookup result is non-null before it is used as inner map pointer。`vendor/linux-framework/kernel/bpf/verifier.c:2259-2273`

Map-in-map needs alias tracking from outer R0 to inner R1。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:810-833`

### B. Fix plan

#### B.1 Files and functions to modify

Modify `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs` to add `is_map_in_map()` and keep map-in-map out of `supports_direct_value_inline()`。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:47-60`

Modify `bpfopt/crates/bpfopt/src/passes/map_inline.rs` to route map-in-map before generic unsupported map gate。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:746-762`

Modify `find_map_lookup_sites()` or add `find_map_in_map_chains()` for outer-to-inner chain detection。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:123-135`

Modify or extend `classify_r0_uses()` to capture alias copies from outer R0 to inner R1。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:810-833`

Modify `build_site_rewrite()` or add `build_map_in_map_chain_rewrite()` for two-level lookup replacement。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1082-1217`

Modify `bpfopt/crates/bpfopt/src/pass.rs` only if the `MapProvider` trait needs structured inner-map helper。`bpfopt/crates/bpfopt/src/pass.rs:139-160`

Prefer not to modify `MapProvider` if outer entry value can be decoded with existing `lookup_elem()`。`bpfopt/crates/bpfopt/src/pass.rs:139-160`

Modify `bpfopt/crates/bpfopt/src/main.rs` `MapValuesJson` schema to carry optional inner map id for outer entries if value bytes alone are ambiguous。`bpfopt/crates/bpfopt/src/main.rs:234-254`

Modify `daemon/src/commands.rs` `write_live_map_values()` to snapshot map-in-map outer entries and inner maps。`daemon/src/commands.rs:802-838`

Modify `daemon/src/bpf.rs` only if a helper for map id lookup/open/info is missing。`daemon/src/bpf.rs:141-157`

Do not add direct dependency between daemon and bpfopt crates。`CLAUDE.md:103-112`

#### B.2 Pseudo-diff sketch

```diff
diff --git a/bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs b/bpfopt/...
@@
 impl MapInfo {
+    pub fn is_map_in_map(&self) -> bool {
+        matches!(self.map_type, BPF_MAP_TYPE_ARRAY_OF_MAPS | BPF_MAP_TYPE_HASH_OF_MAPS)
+    }
     pub fn supports_direct_value_inline(&self) -> bool {
         self.supports_direct_value_access()
     }
 }
diff --git a/bpfopt/crates/bpfopt/src/passes/map_inline.rs b/bpfopt/...
@@
-        if !info.supports_direct_value_inline() {
+        if info.is_map_in_map() {
+            match build_map_in_map_chain_rewrite(program, &site, &info, ...)? {
+                Some(rewrite) => rewrites.push(rewrite),
+                None => record_skip(..., "map-in-map chain is not inlineable", ...),
+            }
+            continue;
+        }
+        if !info.supports_direct_value_inline() {
             record_skip(..., format!("map type {} not inlineable", info.map_type), ...);
             continue;
         }
diff --git a/daemon/src/commands.rs b/daemon/...
@@
-        if !is_map_inlineable_map_type(map.map_type) { continue; }
+        if is_map_in_map_type(map.map_type) {
+            snapshot_outer_entries_and_inner_maps(map, ...)?;
+            continue;
+        }
+        if !is_map_inlineable_map_type(map.map_type) { continue; }
```

#### B.3 New helpers

Add `is_map_in_map_type(u32)` in daemon next to `is_map_inlineable_map_type()`。`daemon/src/commands.rs:881-889`

Add `MapInfo::is_map_in_map()` in bpfopt map info。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:47-60`

Add `decode_inner_map_id_from_outer_value()` in daemon side snapshot code。

Add `open_inner_map_by_id()` or reuse existing open-map helper used by map snapshot。`daemon/src/commands.rs:810-811`

Add `snapshot_inner_map_values()` to collect inner map metadata and entries。

Add `outer_entry_inner_map_id()` in bpfopt side if JSON keeps outer entry value as inner id。

Add `find_outer_inner_lookup_chain()` in `map_inline.rs`。

Add `resolve_inner_lookup_map_arg()` in `map_inline.rs` to prove inner R1 aliases outer lookup result。

Add `build_map_in_map_chain_rewrite()` in `map_inline.rs`。

Add `removal_plan_for_two_lookup_chain()` to prevent branch-target overlap and unsafe DCE。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:879-885`

Extend `prepare_inline_value()` for inner map value only after inner map type is separately supported。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1409-1447`

Do not use `supports_direct_value_inline()` for outer map-in-map maps because outer values are map references。`docs/tmp/map_inline_deepdive_20260505.md:620-629`

#### B.4 Side-input contract changes

`map-values.json` must include outer map-in-map metadata。`bpfopt/crates/bpfopt/src/main.rs:234-254`

`map-values.json` must include each constant outer key's inner map id。

`map-values.json` must include inner map metadata for each referenced inner map。

`map-values.json` must include inner map entries for supported inner map types。

One minimal schema is to keep `entries[].value` as the raw outer lookup value and add `entries[].inner_map_id` for map-in-map entries。

The schema field must be optional so old map snapshot tests still parse。`bpfopt/crates/bpfopt/src/main.rs:1002-1046`

If `inner_map_id` is absent for a candidate map-in-map entry, candidate handling should hard-error for claimed support rather than silently treating it as not found。`CLAUDE.md:70-74`

`target.json` does not need new fields for map-in-map because the data is map snapshot data。`daemon/src/commands.rs:489-518`

`verifier-states.json` changes from Issue 1 are still useful for outer and inner keys。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`

daemon fd-array does not need inner fds if transformed bytecode removes both outer and inner helper dependencies。

If transformed bytecode keeps any direct inner map reference, fd-array construction must include that fd in verifier order。`daemon/src/commands.rs:934-1050`

The first implementation should avoid introducing new direct inner map references in bytecode。

The first implementation should only replace loads from the inner lookup result and remove lookup patterns when no remaining dependency exists。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1525-1565`

#### B.5 LoC estimate

daemon map-in-map snapshot helpers: gross 190 LoC, net 160 LoC.

`map-values.json` schema and reader changes: gross 85 LoC, net 65 LoC.

`map_info.rs` classifiers and tests: gross 35 LoC, net 25 LoC.

`map_inline.rs` chain detector and rewrite builder: gross 290 LoC, net 240 LoC.

Tests: gross 190 LoC, net 175 LoC.

Issue 2 total estimate: gross 790 LoC, net 665 LoC.

Issue 2 probably deserves a new `bpfopt/crates/bpfopt/src/passes/map_inline/map_in_map.rs` helper module if chain logic exceeds 250 LoC.

If kept inside `map_inline.rs`, isolate the logic in one contiguous section near helper lookup rewrite code。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1082-1217`

### C. Daemon-side coordination needed

Kernel verifier already models non-null outer map lookup result as `CONST_PTR_TO_MAP` for map-in-map。`vendor/linux-framework/kernel/bpf/verifier.c:2259-2273`

Kernel verifier already carries `inner_map_meta` in that transition。`vendor/linux-framework/kernel/bpf/verifier.c:2259-2273`

Kernel log does not currently expose concrete runtime inner map id through the JSON schema。`bpfopt/crates/kernel-sys/src/lib.rs:188-217`

The userspace daemon must derive inner map ids from live outer map entries.

The derivation uses existing map lookup syscalls through daemon BPF helpers。`daemon/src/commands.rs:341-345`

The daemon already opens maps by map id for snapshotting。`daemon/src/commands.rs:810-811`

The daemon already gets map metadata by map id through `get_map_infos()`。`daemon/src/bpf.rs:141-157`

The daemon already scans map keys with `bpf_map_get_next_key` path。`daemon/src/commands.rs:347-375`

The daemon already looks up map element values with correct lookup value size。`daemon/src/commands.rs:341-345`

For map-in-map, daemon must not treat unsupported outer maps as empty。`daemon/src/commands.rs:347-350`

For map-in-map, daemon must scan outer keys subject to the same max_entries guard。`daemon/src/commands.rs:351-375`

For each outer entry, daemon must decode inner map id and then snapshot the inner map.

If outer entry lookup returns no inner map, hash-of-maps candidate should be site-vetoed like hash missing entries。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1092-1113`

If outer entry decode fails for a candidate, daemon or bpfopt should hard-error because that indicates side-input contract mismatch。`CLAUDE.md:70-74`

If inner map type is currently unsupported, bpfopt should record a precise unsupported-inner-map skip, not add a framework summary。`CLAUDE.md:15-28`

The daemon should not add a custom loader or app-level bypass。`CLAUDE.md:12-14`

The daemon should not filter programs that have map-in-map maps。`CLAUDE.md:5-10`

No kernel patch is needed for Issue 2 because userspace can derive the inner map id from live outer map contents.

### D. Risk and verification

#### D.1 Risks

Outer map contents can change between daemon snapshot and ReJIT。

That race already exists for ordinary map values read by `map_inline`。`daemon/src/commands.rs:802-838`

Hash-of-maps may return no entry for a constant outer key。

The existing hash-like missing/null logic site-vetoes missing entries。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1092-1113`

Array-of-maps may have bounds or absent inner map concerns distinct from plain array maps。

The current array-like no-live-value path is a hard error for array-like maps。`daemon/src/commands.rs:874-879`

Inner map may be per-cpu hash, LPM trie, storage map, or another map-in-map。

Current direct inline support only covers hash, array, percpu_array, lru_hash。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:47-55`

The first map-in-map implementation should support only inner maps that existing value inliner can safely read。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:47-60`

Nested map-in-map should be rejected with a precise reason in first implementation。

Per-cpu inner map values must use existing uniform `PERCPU_ARRAY` rule or remain unsupported。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1409-1447`

`sk_storage` and storage-like inner maps are outside current direct value support。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:47-55`

Two-lookup removal can accidentally cross branch targets。

Existing code already keeps lookup pattern when removal crosses branch target。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:879-885`

Tracee code-size risk is real because Tracee owns 1,102 `HASH_OF_MAPS` blocked sites。`docs/tmp/map_inline_deepdive_20260505.md:112-117`

Deep-dive says Tracee's observed app-level regression was not explained by current direct-apply code bloat。`docs/tmp/map_inline_deepdive_20260505.md:395-425`

New helper inlining in hot Tracee programs still needs post-run raw JIT-size inspection。`docs/tmp/map_inline_deepdive_20260505.md:378-425`

#### D.2 Verification targets

Add `map_info` tests proving `HASH_OF_MAPS` and `ARRAY_OF_MAPS` are map-in-map but not direct-value inlineable。`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:456-489`

Add `map_inline` pass test for outer array-of-maps constant outer key and inner array constant inner key。

Add `map_inline` pass test for outer hash-of-maps constant outer key with explicit null check before inner lookup。

Add negative test where outer key is not constant and skip reason remains key-state。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:779-787`

Add negative test where outer entry points to unsupported inner map type and skip reason names inner map type。

Add negative test where inner key is not constant and outer lookup is not removed。

Add negative test where two-lookup removal would cross a branch target and lookup pattern is retained。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:879-885`

Add daemon serialization test for map-in-map snapshot file format.

Do not add trivial tests for `is_map_in_map()` alone unless paired with direct-inline exclusion behavior。`CLAUDE.md:79-84`

Expected cargo test impact is bpfopt pass tests plus daemon snapshot serialization tests.

No corpus benchmark should be run as part of implementing the unit-level patch.

### E. Expected unlock

Issue 2 can unlock up to 1,250 unsupported map-in-map sites。`docs/tmp/map_inline_deepdive_20260505.md:631-634`

`HASH_OF_MAPS` contributes 1,143 of those sites。`docs/tmp/map_inline_deepdive_20260505.md:612-618`

`ARRAY_OF_MAPS` contributes 107 of those sites。`docs/tmp/map_inline_deepdive_20260505.md:612-618`

Tracee is the largest map-in-map beneficiary with 1,102 `HASH_OF_MAPS` sites。`docs/tmp/map_inline_deepdive_20260505.md:112-117`

Tetragon is the second-largest map-in-map beneficiary with 140 combined map-in-map sites。`docs/tmp/map_inline_deepdive_20260505.md:112-117`

Katran could move 4 map-in-map sites from unsupported to candidate。`docs/tmp/map_inline_deepdive_20260505.md:112-117`

Otelcol could move 4 `HASH_OF_MAPS` sites from unsupported to candidate。`docs/tmp/map_inline_deepdive_20260505.md:112-117`

Apps that can shift from 0 helper applies to N helper applies include Tracee, Tetragon, Katran, and possibly Otelcol helper paths。`docs/tmp/map_inline_deepdive_20260505.md:167-186`

Issue 2 depends on Issue 1 for sites where either outer key or inner key is currently not recoverable。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`

Issue 2 alone will not fix per-cpu hash skips。`docs/tmp/map_inline_deepdive_20260505.md:612-618`

Issue 2 alone will not fix LPM trie skips。`docs/tmp/map_inline_deepdive_20260505.md:612-618`

Tracee code-bloat caveat is strongest for Issue 2 because Tracee owns most map-in-map sites。`docs/tmp/map_inline_deepdive_20260505.md:112-117`

The framework must continue writing raw per-program/pass details only; any later win/loss/geomean interpretation remains analysis-side。`CLAUDE.md:15-28`

## 3. Issue 3: tetragon noop ENOSPC root fix for 88 errors

### A. Root cause analysis

#### A.1 Observed blocker

Tetragon has 88 pass errors in the cited run。`docs/tmp/map_inline_deepdive_20260505.md:427-442`

44 errors are `noop failed_rejit`。`docs/tmp/map_inline_deepdive_20260505.md:437-442`

44 errors are `map_inline skipped_missing_states`。`docs/tmp/map_inline_deepdive_20260505.md:437-442`

The `noop failed_rejit` root is errno 28 / ENOSPC。`docs/tmp/map_inline_deepdive_20260505.md:437-442`

The `map_inline skipped_missing_states` errors are secondary because verifier states are missing after failed noop。`docs/tmp/map_inline_deepdive_20260505.md:444-449`

Deep-dive says all 44 first-pass failures are `noop failed_rejit` rather than bpfopt failures。`docs/tmp/map_inline_deepdive_20260505.md:478-482`

Deep-dive says the verifier logs are dominated by `mark_precise` output on large Tetragon programs。`docs/tmp/map_inline_deepdive_20260505.md:478-482`

Fixing ENOSPC alone will turn 88 pass errors into real reports, but it will not create applies without the coverage fixes。`docs/tmp/map_inline_deepdive_20260505.md:541-543`

#### A.2 Current daemon/kernel-sys code path

daemon defines `REJIT_VERBOSE_LOG_BUF_SIZE` as 16 MiB。`daemon/src/commands.rs:31-36`

daemon defines `REJIT_BASIC_LOG_BUF_SIZE` as 1 MiB。`daemon/src/commands.rs:31-36`

`try_apply_one()` sets log level 2 and verbose log buffer size when pass metadata says it produces verifier states。`daemon/src/commands.rs:611-616`

`try_apply_one()` sets log level 1 and basic log buffer size otherwise。`daemon/src/commands.rs:611-616`

`noop` produces verifier states by pass metadata。`bpfopt/crates/bpfopt/src/passes/mod.rs:102-105`

`map_inline` also produces verifier states by pass metadata。`bpfopt/crates/bpfopt/src/passes/mod.rs:86-89`

`rejit_program()` allocates `Vec<u8>` with the selected log buffer size。`daemon/src/commands.rs:200-217`

`rejit_program()` passes that vector to `kernel_sys::prog_rejit()`。`daemon/src/commands.rs:200-217`

`rejit_program()` writes the verifier log after success。`daemon/src/commands.rs:223-225`

`rejit_program()` returns empty states if log_level is not 2。`daemon/src/commands.rs:226-230`

`rejit_program()` bails if log_level 2 returns empty verifier log。`daemon/src/commands.rs:231-232`

`rejit_program()` parses verifier states from log_level 2 log。`daemon/src/commands.rs:234-237`

`kernel_sys::prog_rejit()` accepts optional mutable log buffer。`bpfopt/crates/kernel-sys/src/lib.rs:1298-1341`

`prog_rejit_with_log_buf()` validates buffer and loops on retries。`bpfopt/crates/kernel-sys/src/lib.rs:1344-1364`

On ENOSPC, `prog_rejit_with_log_buf()` calls `next_rejit_log_buf_size()` and retries if a larger buffer is allowed。`bpfopt/crates/kernel-sys/src/lib.rs:1354-1361`

`MAX_REJIT_LOG_BUF_SIZE` is 256 MiB。`bpfopt/crates/kernel-sys/src/lib.rs:39-44`

`next_rejit_log_buf_size()` doubles until the cap。`bpfopt/crates/kernel-sys/src/lib.rs:1380-1394`

There are existing unit tests for doubling until the limit。`bpfopt/crates/kernel-sys/src/lib.rs:1585-1593`

There are existing unit tests for exposing final ENOSPC log to caller。`bpfopt/crates/kernel-sys/src/lib.rs:1596-1618`

#### A.3 Is log_level=2 needed for noop?

`map_inline` needs verifier states according to pass metadata。`bpfopt/crates/bpfopt/src/passes/mod.rs:86-89`

daemon refuses to run a pass that needs verifier states when `verifier_states_ready == false`。`daemon/src/commands.rs:530-552`

The refusal status is `SkippedMissingStates`。`daemon/src/commands.rs:170-177`

The refusal happens before `run_bpfopt_pass()`。`daemon/src/commands.rs:530-565`

Therefore `map_inline` cannot run first and then collect states for itself。

`noop` with log_level=2 is the current state-bootstrap mechanism。`bpfopt/crates/bpfopt/src/passes/mod.rs:102-105`

`noop` with log_level=1 would not produce parsed states because `rejit_program()` returns empty states for log_level != 2。`daemon/src/commands.rs:226-230`

Option (a), `noop` log_level=1 followed by map_inline log_level=2, does not satisfy map_inline's pre-run dependency。`daemon/src/commands.rs:530-552`

A separate bootstrap ReJIT with original bytes and log_level=2 would be equivalent to current `noop` state bootstrap for log volume purposes。

Therefore log_level=2 is strictly needed somewhere before `map_inline` bpfopt invocation。

#### A.4 Why current code fails

The immediate daemon initial buffer for state-producing passes is 16 MiB。`daemon/src/commands.rs:31-36`

kernel-sys can grow that buffer on ENOSPC up to 256 MiB。`bpfopt/crates/kernel-sys/src/lib.rs:1344-1364`, `bpfopt/crates/kernel-sys/src/lib.rs:39-44`

If Tetragon still returns ENOSPC after retries, the likely userspace limit is the 256 MiB cap。`bpfopt/crates/kernel-sys/src/lib.rs:1380-1394`

Deep-dive's mark_precise-heavy log observation is consistent with a log-buffer ENOSPC。`docs/tmp/map_inline_deepdive_20260505.md:478-482`

Kernel log level 2 mark_precise output can be large because verifier prints per-frame precise masks and parent states。`vendor/linux-framework/kernel/bpf/verifier.c:4718-4725`, `vendor/linux-framework/kernel/bpf/verifier.c:5365-5374`

The current failure is not a `map_inline` pass logic skip。`docs/tmp/map_inline_deepdive_20260505.md:484-523`

The current failure is not an unsupported map-type skip。`docs/tmp/map_inline_deepdive_20260505.md:484-523`

The current failure is not a bpfopt CLI failure。`docs/tmp/map_inline_deepdive_20260505.md:478-482`

### B. Fix plan

#### B.1 Picked option

Pick option (b): dynamic log buffer sizing with a larger state-capture cap.

This is the smallest blast-radius fix because kernel-sys already implements ENOSPC retry。`bpfopt/crates/kernel-sys/src/lib.rs:1344-1364`

This preserves the same operation and same log level; it does not downgrade semantics。`daemon/src/commands.rs:611-616`

This keeps fail-fast behavior if the larger cap is still insufficient。`bpfopt/crates/kernel-sys/src/lib.rs:1354-1361`

This avoids kernel patching。`docs/kernel-jit-optimization-plan.md:6`

Do not pick option (a) because map_inline needs states before bpfopt runs。`daemon/src/commands.rs:530-552`

Do not pick option (c) because verifier chunks cannot be split at userspace for a single BPF program.

Do not pick option (d) because dropping precision marks would require changing kernel verifier log behavior。`vendor/linux-framework/kernel/bpf/verifier.c:4718-4725`

#### B.2 Files and functions to modify

Modify `bpfopt/crates/kernel-sys/src/lib.rs` `MAX_REJIT_LOG_BUF_SIZE`。`bpfopt/crates/kernel-sys/src/lib.rs:39-44`

Modify `bpfopt/crates/kernel-sys/src/lib.rs` tests around `next_rejit_log_buf_size()`。`bpfopt/crates/kernel-sys/src/lib.rs:1585-1593`

Optionally modify daemon `REJIT_VERBOSE_LOG_BUF_SIZE` if data shows too many retries are expensive。`daemon/src/commands.rs:31-36`

Do not modify pass metadata to make `noop` non-state-producing。`bpfopt/crates/bpfopt/src/passes/mod.rs:102-105`

Do not modify daemon missing-state behavior。`daemon/src/commands.rs:530-552`

Do not add daemon-side timeout because v3 accepts synchronous `BPF_PROG_REJIT` behavior。`CLAUDE.md:86-100`

#### B.3 Pseudo-diff sketch

```diff
diff --git a/bpfopt/crates/kernel-sys/src/lib.rs b/bpfopt/crates/kernel-sys/src/lib.rs
@@
-const MAX_REJIT_LOG_BUF_SIZE: usize = 256 * 1024 * 1024;
+const MAX_REJIT_LOG_BUF_SIZE: usize = 512 * 1024 * 1024;
@@
 fn next_rejit_log_buf_size(current: usize) -> Option<usize> {
     if current >= MAX_REJIT_LOG_BUF_SIZE {
         return None;
     }
     let doubled = current.checked_mul(2).unwrap_or(MAX_REJIT_LOG_BUF_SIZE);
     let next = doubled.min(MAX_REJIT_LOG_BUF_SIZE);
     (next > current).then_some(next)
 }
diff --git a/daemon/src/commands.rs b/daemon/src/commands.rs
@@
-const REJIT_VERBOSE_LOG_BUF_SIZE: usize = 16 * 1024 * 1024;
+const REJIT_VERBOSE_LOG_BUF_SIZE: usize = 16 * 1024 * 1024; // keep retry-driven growth
```

#### B.4 Side-input contract changes

No `target.json` change is needed for Issue 3。`daemon/src/commands.rs:489-518`

No `map-values.json` change is needed for Issue 3。`bpfopt/crates/bpfopt/src/main.rs:234-254`

No `verifier-states.json` schema change is needed for Issue 3 itself。`bpfopt/crates/kernel-sys/src/lib.rs:188-217`

The only file-format effect is that successful Tetragon noop ReJITs will finally produce verifier-states JSON。`daemon/src/commands.rs:769-775`

The verifier log file may be much larger on disk。`daemon/src/commands.rs:223-225`

The pass result should remain raw status/error/report fields only。`CLAUDE.md:15-28`

#### B.5 LoC estimate

Kernel-sys cap change: gross 2 LoC, net 1 LoC.

Kernel-sys tests update: gross 8 LoC, net 4 LoC.

Optional daemon comment/helper around verbose log policy: gross 10 LoC, net 8 LoC.

Issue 3 total estimate: gross 20 LoC, net 13 LoC.

If memory-gated worker serialization is later needed, that is a separate 80-120 LoC daemon scheduler change.

Do not include worker serialization in the first fix because it broadens scope beyond the observed ENOSPC root。

### C. Daemon-side coordination needed

daemon already chooses log_level per pass metadata。`daemon/src/commands.rs:611-616`

daemon already passes log buffer size into `rejit_program()`。`daemon/src/commands.rs:617-624`

daemon already reports `FailedRejit` when `rejit_program()` returns error。`daemon/src/commands.rs:625-634`

daemon already writes verifier states for the next pass after success。`daemon/src/commands.rs:636-641`

kernel-sys already handles ENOSPC retry for the same syscall。`bpfopt/crates/kernel-sys/src/lib.rs:1344-1364`

kernel-sys already exposes final verifier log summary on failure。`bpfopt/crates/kernel-sys/src/lib.rs:430-440`

The coordination is therefore to adjust the maximum allowed log buffer in kernel-sys and keep daemon's state-producing pass policy unchanged。

If 512 MiB still fails, keep hard failure and surface ENOSPC rather than switching to log_level=1。`CLAUDE.md:70-74`

If memory pressure appears on small AWS instances, reduce concurrency or serialize state-producing ReJIT only as a separate explicit resource-control change。

AWS defaults must remain cost-conscious and not use larger instances to hide the problem。`CLAUDE.md:146-149`

No daemon/bpfopt CLI side-input file format change is required for Issue 3。

### D. Risk and verification

#### D.1 Risks

The main risk is memory pressure from larger verifier log buffers.

The current AWS bench defaults are small instances。`CLAUDE.md:146-149`

Multiple concurrent state-producing ReJITs could allocate large buffers simultaneously if programs all reach the cap。

The existing retry path grows only on ENOSPC。`bpfopt/crates/kernel-sys/src/lib.rs:1344-1364`

Keeping initial daemon buffer at 16 MiB limits memory use for normal programs。`daemon/src/commands.rs:31-36`

The second risk is disk pressure from larger verifier logs written after success。`daemon/src/commands.rs:223-225`

The third risk is still hitting ENOSPC after the larger cap。

That third risk must remain a hard `FailedRejit` error。`daemon/src/commands.rs:625-634`

Do not turn the remaining failure into a skip。`CLAUDE.md:5-10`

Do not turn the remaining failure into a partial result。`CLAUDE.md:70-74`

#### D.2 Verification targets

Update `rejit_log_retry_doubles_until_limit()` expectations for the new cap。`bpfopt/crates/kernel-sys/src/lib.rs:1585-1593`

Keep `rejit_enospc_retry_exposes_final_log_to_caller()` proving hard failure still includes final log。`bpfopt/crates/kernel-sys/src/lib.rs:1596-1618`

Add no trivial daemon unit test unless log policy is refactored into a branchy helper。`CLAUDE.md:79-84`

No corpus benchmark should be run for the unit patch under this task.

Later validation app is Tetragon observer because all 88 observed errors are in Tetragon。`docs/tmp/map_inline_deepdive_20260505.md:427-442`

Success criterion for later corpus run is 44 fewer `noop failed_rejit` and 44 fewer secondary `skipped_missing_states` in Tetragon。`docs/tmp/map_inline_deepdive_20260505.md:437-442`

Expected cargo test impact is one kernel-sys test expectation change, with no broad rebuild-sensitive test additions。

### E. Expected unlock

Issue 3 eliminates the 44 primary Tetragon noop ENOSPC errors if the larger cap is sufficient。`docs/tmp/map_inline_deepdive_20260505.md:437-442`

Issue 3 also eliminates the 44 secondary Tetragon `skipped_missing_states` errors if the primary noop succeeds。`docs/tmp/map_inline_deepdive_20260505.md:437-442`

The total expected error unlock is 88 pass errors。`docs/tmp/map_inline_deepdive_20260505.md:437-442`

Issue 3 exposes real `map_inline` reports for 44 currently opaque Tetragon programs。`docs/tmp/map_inline_deepdive_20260505.md:478-482`

Deep-dive estimates those 44 programs could expose on the order of hundreds more Tetragon sites for classification。`docs/tmp/map_inline_deepdive_20260505.md:597-603`

Issue 3 alone does not make Tetragon helper sites apply。`docs/tmp/map_inline_deepdive_20260505.md:541-543`

Issue 3 is still high priority because later Issue 1 and Issue 2 work needs observable Tetragon pass reports。

Tracee code-bloat caveat is not directly affected by Issue 3 because Issue 3 is Tetragon-specific in this run。`docs/tmp/map_inline_deepdive_20260505.md:427-442`

## 4. Cross-issue dependency plan

Step 1 should be Issue 3 ENOSPC cap increase.

Step 1 is smallest net code change。`bpfopt/crates/kernel-sys/src/lib.rs:39-44`

Step 1 removes hard pass errors before measuring coverage fixes。`docs/tmp/map_inline_deepdive_20260505.md:437-442`

Step 1 does not alter `map_inline` semantics。`daemon/src/commands.rs:611-616`

Step 2 should be Issue 1 verifier-state key extraction.

Step 2 addresses the largest observed helper-site blocker。`docs/tmp/map_inline_deepdive_20260505.md:74-81`

Step 2 also supplies the key extraction needed by map-in-map outer and inner keys。`bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`

Step 2 is userspace-only because kernel log already emits stack and precision context。`vendor/linux-framework/kernel/bpf/verifier.c:4718-4725`, `vendor/linux-framework/kernel/bpf/verifier.c:5365-5374`

Step 3 should be Issue 2 map-in-map chain support.

Step 3 has the largest design surface because it touches daemon snapshots and bpfopt chain rewrite logic。`daemon/src/commands.rs:802-838`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1082-1217`

Step 3 should not be mixed into Step 2 because map-in-map data modeling is separate from key extraction。

Step 3 should not be implemented by adding `HASH_OF_MAPS` and `ARRAY_OF_MAPS` to `supports_direct_value_access()`。`docs/tmp/map_inline_deepdive_20260505.md:620-629`

## 5. Estimated LoC summary

Issue 3 ENOSPC: gross 20 LoC, net 13 LoC.

Issue 1 verifier-state/key extraction: gross 350 LoC, net 295 LoC.

Issue 2 map-in-map support: gross 790 LoC, net 665 LoC.

Total estimate across all three: gross 1,160 LoC, net 973 LoC.

If Issue 2 is split into a new helper module, total gross may rise by about 30 LoC due module declarations and imports.

The total estimate includes unit tests.

The total estimate excludes benchmarks.

The total estimate excludes any kernel patch.

The total estimate excludes any framework-side aggregation output。

## 6. Implementation guardrails

Do not introduce `live_rejit_programs()` filtering。`CLAUDE.md:5-10`

Do not introduce `LifecycleAbort` around ReJIT。`CLAUDE.md:5-10`

Do not add per-prog-type exclusions to benchmark config。`CLAUDE.md:5-10`

Do not add fallback to log_level=1 for state-producing passes。`CLAUDE.md:70-74`

Do not swallow malformed verifier-state JSON with empty stack/default key。`CLAUDE.md:70-74`

Do not turn missing inner-map metadata into success。`CLAUDE.md:70-74`

Do not add derived ratios, geomeans, win/loss counts, or markdown rollups to result payloads。`CLAUDE.md:15-28`

Do not add CLI crate dependencies between `bpfopt`、`bpfprof`、`bpfrejit-daemon`。`CLAUDE.md:103-112`

Do not bypass upstream application loading or add custom loader binaries。`CLAUDE.md:12-14`

Do not use bigger AWS instance types to hide verifier-log memory pressure。`CLAUDE.md:146-149`

Do add tests only where a failure would identify a real bug。`CLAUDE.md:79-84`

Do keep side-input changes explicit and version-tolerant through optional fields。

Do keep hard errors hard when a candidate claims support but required side input is absent。`CLAUDE.md:70-74`

Do keep map-in-map support scoped to outer constant key plus inner constant key。

Do keep unsupported inner maps as precise skip reasons rather than broad unsupported outer map skips。

Do inspect raw result.json after later runs outside framework code for any Tracee code-bloat regression。`CLAUDE.md:15-28`
