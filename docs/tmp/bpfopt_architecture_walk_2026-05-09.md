# bpfopt-suite architecture walk, 2026-05-09

## 1. 总览

权威边界很清楚：`bpfopt` 是 pure bytecode CLI，只做 init canonicalization 和单个 `--pass <name>` 变换；`bpfrejit-daemon` 保留 runner socket + JSON 边界，做 live discovery、side-input 准备、fd_array 构造和每个 pass 后的 `BPF_PROG_REJIT`。设计文档把这两条写在 `docs/tmp/bpfopt_design_v3.md:7`-`docs/tmp/bpfopt_design_v3.md:12`，`CLAUDE.md:86`-`CLAUDE.md:99` 也重复要求 daemon 不维护 PassManager、不在进程内 transform bytecode、不做 BPF_PROG_LOAD dry-run，所有 kernel-facing 调用走 daemon-owned syscall boundary。

当前实现总体符合 v3 进程边界：daemon 通过外部 `bpfopt` CLI 做 canonicalize 和 pass，daemon 自己调用 `BPF_PROG_REJIT`。主要偏差是协议文档仍以旧 `cmd:"optimize"`/`enabled_passes` 为例（`docs/tmp/bpfopt_design_v3.md:21`-`docs/tmp/bpfopt_design_v3.md:27`, `docs/tmp/bpfopt_design_v3.md:156`-`docs/tmp/bpfopt_design_v3.md:164`），而当前 server 只接受 `cmd:"execute_plan"`（`daemon/src/server.rs:271`-`daemon/src/server.rs:289`），runner 用 YAML 生成具体 step command（`runner/libs/rejit_plan.py:1`-`runner/libs/rejit_plan.py:17`, `runner/libs/rejit_plan.py:100`-`runner/libs/rejit_plan.py:136`）。

结论摘要：

- 端到端执行是“app 正常加载 BPF -> runner 发 execute_plan -> daemon snapshot/canonicalize -> 每步 fork 外部 bpfopt -> daemon ReJIT”的模型；不是 daemon 内建 pass pipeline。
- 最大 P0/P1 重复来自 packet ctx/prog_type 判定、`RewritePlan` dead API、同名 libbpf const/wrapper、map_inline 5502 行巨模块、kop 元数据散落、手写 rewrite/branch fixup/annotation remap。
- 是否需要 pass-prologue/epilogue：需要，但应该以“小而显式”的 validator/cleanup/rewrite commit layer 开始；不要把所有 normalize/cleanup 默认套到每个 pass，否则会改变 PC/BTF/verifier-state 对应关系。

## 2. 完整流程时序

```mermaid
sequenceDiagram
    participant App as real benchmark app
    participant Kernel as kernel BPF subsystem
    participant Runner as runner Python
    participant Server as daemon/src/server.rs
    participant Cmd as daemon/src/commands.rs
    participant Bpf as daemon/src/bpf.rs
    participant BpfoptC as bpfopt --canonicalize-map-refs
    participant BpfoptP as bpfopt --pass <name>
    participant Sys as daemon/src/syscall.rs

    App->>Kernel: real app startup loads/attaches BPF programs
    Runner->>Server: newline JSON cmd=execute_plan
    Server->>Cmd: try_execute_plan(programs, kop_probes)
    Cmd->>Bpf: snapshot_program(prog_id)
    Bpf->>Sys: prog_get_fd_by_id + prog_get_original + prog info/map_ids
    Cmd->>Bpf: optional probe_target_json(kop_probes)
    Cmd->>BpfoptC: fork/exec bpfopt --canonicalize-map-refs
    BpfoptC-->>Cmd: canonical bytecode + shifted target.json
    Cmd->>Cmd: optional bpftool map snapshots; build fd_array
    loop per StepSpec
        Cmd->>BpfoptP: fork sh -c "... bpfopt --pass <name> ..."
        BpfoptP-->>Cmd: raw bytecode output + report JSON
        Cmd->>Sys: prog_rejit(new_insns, fd_array, log_level)
        Sys->>Kernel: sys_bpf(BPF_PROG_REJIT)
        Kernel-->>Sys: verify + JIT + swap live image + verifier log
        Sys-->>Cmd: verifier log file path becomes next VERIFIER_STATES
    end
    Cmd-->>Server: per_program result
    Server-->>Runner: JSON response
```

### 2.1 Loader 和 runner

- BPF program 加载来自 real benchmark app startup；框架不直接 loader `.bpf.o`。这是 repo 规则，不在 `bpfopt`/daemon 代码内实现。
- runner 入口 `apply_daemon_rejit()` 要求非空 `prog_ids` 和 `enabled_passes`，然后调用 `rejit_plan.build_execute_plan_payload()`（`runner/libs/rejit.py:338`-`runner/libs/rejit.py:370`）。
- `rejit_plan.py` 明确 YAML 是 command 单一来源，runner 不查询 `bpfopt list-passes`（`runner/libs/rejit_plan.py:1`-`runner/libs/rejit_plan.py:7`）。它还把每个 step 的 outgoing daemon `log_level` 设置成下一步的 input requirement（`runner/libs/rejit_plan.py:14`-`runner/libs/rejit_plan.py:16`, `runner/libs/rejit_plan.py:122`-`runner/libs/rejit_plan.py:127`）。
- 当前 pass YAML 是外部命令模板，例如 `runner/config/passes/wide_mem/default.yaml:6` 是 `timeout 6000 bpfopt --pass wide_mem ...`，`map_inline`/`const_prop` 的 YAML 声明 `log_level: 2`（`runner/config/passes/map_inline/default.yaml:4`, `runner/config/passes/const_prop/default.yaml:4`）。

### 2.2 Socket protocol

- daemon socket server 是 newline-delimited JSON：`cmd_serve()` bind/listen/accept（`daemon/src/server.rs:33`-`daemon/src/server.rs:64`），`handle_client()` 逐行 parse request 并写回一行 JSON（`daemon/src/server.rs:66`-`daemon/src/server.rs:94`）。
- 当前唯一有效 command 是 `execute_plan`（`daemon/src/server.rs:271`-`daemon/src/server.rs:289`）。
- 请求 schema：`programs[]`，每项有 `prog_id` 和 `steps[]`（`daemon/src/server.rs:102`-`daemon/src/server.rs:150`）；每个 step 必须有 `name`、`command`、`log_level`，且 `log_level` 只能为 1 或 2（`daemon/src/server.rs:152`-`daemon/src/server.rs:205`）。
- `kop_probes[]` 是 `{name, aliases[]}`，用于 daemon BTF probing（`daemon/src/server.rs:207`-`daemon/src/server.rs:262`）。
- 响应 schema：top-level 总是 `{status:"ok", per_program:{...}}`，不聚合 error_message；消费者看 `per_program[id].status` 和 `passes[*].error`（`daemon/src/server.rs:292`-`daemon/src/server.rs:310`）。

### 2.3 Daemon per-program orchestration

- `try_execute_plan()` 把 plans 分配给 worker pool，对每个 prog 调 `execute_one()`（`daemon/src/commands.rs:367`-`daemon/src/commands.rs:389`）。
- `execute_one()` 先校验所有 command template，只允许 daemon-known `${VAR}`；校验通过后才碰 kernel（`daemon/src/commands.rs:391`-`daemon/src/commands.rs:410`, `daemon/src/commands.rs:866`-`daemon/src/commands.rs:925`）。
- 核心入口是 `run_program_steps()`（`daemon/src/commands.rs:506`-`daemon/src/commands.rs:834`）。
- live snapshot 由 `bpf::snapshot_program()` 完成：open prog fd、`prog_get_original()`、读 prog info/map_ids/map infos（`daemon/src/bpf.rs:70`-`daemon/src/bpf.rs:85`）。
- `BPF_PROG_GET_ORIGINAL` 和 fork-only `BPF_PROG_REJIT` 只在 `daemon/src/syscall.rs` 包装；标准 get-fd/get-info/map calls 走 libbpf-sys（`daemon/src/syscall.rs:1`-`daemon/src/syscall.rs:6`, `daemon/src/syscall.rs:211`-`daemon/src/syscall.rs:286`, `daemon/src/syscall.rs:481`-`daemon/src/syscall.rs:526`）。

### 2.4 谁 fork/exec 谁

- canonicalize 阶段：daemon 直接 `Command::new("bpfopt")`，参数是 `--canonicalize-map-refs --input --output --map-ids ...`（`daemon/src/commands.rs:448`-`daemon/src/commands.rs:504`）。这是 daemon fork/exec `bpfopt`。
- pass 阶段：daemon 不直接 exec `bpfopt`，而是 `Command::new("sh").arg("-c").arg(&cmd).output()`（`daemon/src/commands.rs:624`-`daemon/src/commands.rs:642`）。实际 `bpfopt --pass ...` 在 shell command 内，通常前面包了 `timeout 6000`。
- `bpfopt` 自己不 fork daemon，也不 call kernel syscall；它只读文件/stdin、写文件/stdout、跑 pass。`bpfopt` CLI dispatch 在 `run_main()`（`bpfopt/crates/bpfopt/src/main.rs:240`-`bpfopt/crates/bpfopt/src/main.rs:274`）。
- `BPF_PROG_REJIT` 不是 subprocess；daemon 在当前进程通过 `syscall::prog_rejit()` 调 kernel（`daemon/src/commands.rs:199`-`daemon/src/commands.rs:224`, `daemon/src/syscall.rs:348`-`daemon/src/syscall.rs:390`, `daemon/src/syscall.rs:445`-`daemon/src/syscall.rs:479`）。

### 2.5 bpfopt CLI 进程模型

- CLI 定义明确写着“Single pass to run. bpfopt intentionally has no built-in pass pipeline.”（`bpfopt/crates/bpfopt/src/main.rs:89`-`bpfopt/crates/bpfopt/src/main.rs:101`）。
- `--canonicalize-map-refs` 不能和 `--pass` 或 subcommand 混用（`bpfopt/crates/bpfopt/src/main.rs:240`-`bpfopt/crates/bpfopt/src/main.rs:254`）。
- optimization path 必须有一个 `--pass <name>`，然后 `run_single_pass()` 读 bytecode、attach side inputs、构建 `PassContext`、构建只含这个 pass 的 `PassManager`、运行、写 bytecode/report（`bpfopt/crates/bpfopt/src/main.rs:322`-`bpfopt/crates/bpfopt/src/main.rs:350`）。
- `PassManager` 本体不是 `#[cfg(test)]` only：生产 `main.rs` 用 `PassManager::new()` 和 `add_pass_boxed()`（`bpfopt/crates/bpfopt/src/main.rs:362`-`bpfopt/crates/bpfopt/src/main.rs:374`）。但是 `add_pass()`、`pass_names()`、`build_custom_pipeline()` 和 test pipeline 构造是 `#[cfg(test)]`（`bpfopt/crates/bpfopt/src/pass.rs:825`-`bpfopt/crates/bpfopt/src/pass.rs:839`, `bpfopt/crates/bpfopt/src/passes/mod.rs:173`-`bpfopt/crates/bpfopt/src/passes/mod.rs:225`）。

### 2.6 canonicalize-map-refs

- 谁负责：daemon 决定何时调用，bpfopt 实现 bytecode rewrite。
- 何时调：`run_program_steps()` 在每个 prog snapshot 后、第一步 pass 前调用 `canonicalize_snapshot_map_refs()`（`daemon/src/commands.rs:513`-`daemon/src/commands.rs:542`）。
- bpfopt 实现：`run_canonicalize_map_refs()` 读 bytecode、调用 `canonicalize_map_refs_to_idx()`、可选平移 target module call offsets、写 bytecode（`bpfopt/crates/bpfopt/src/main.rs:276`-`bpfopt/crates/bpfopt/src/main.rs:295`）。
- map reference 规则：FD-form map pseudo 按原始 bytecode first-seen loader fd 顺序映射到 `prog_info.map_ids` index（`bpfopt/crates/bpfopt/src/main.rs:529`-`bpfopt/crates/bpfopt/src/main.rs:588`, `bpfopt/crates/bpfopt/src/main.rs:590`-`bpfopt/crates/bpfopt/src/main.rs:615`）。

### 2.7 Side-input ownership

- `target.json` / kop registry：daemon 在 command 引用 `${TARGET}` 时 probe BTF（`daemon/src/commands.rs:521`-`daemon/src/commands.rs:532`），BTF probing 枚举 kernel BTF objects，找 aliases，module kop 分配 non-zero `call_offset`（`daemon/src/bpf.rs:87`-`daemon/src/bpf.rs:102`, `daemon/src/bpf.rs:172`-`daemon/src/bpf.rs:280`）。bpfopt 读 `--target`，构建 `PassContext.kop_registry`（`bpfopt/crates/bpfopt/src/main.rs:839`-`bpfopt/crates/bpfopt/src/main.rs:864`, `bpfopt/crates/bpfopt/src/main.rs:965`-`bpfopt/crates/bpfopt/src/main.rs:1037`）。
- map-value side input：daemon 在 command 引用 `${MAP_VALUES}` 时用 bpftool snapshot maps（`daemon/src/commands.rs:567`-`daemon/src/commands.rs:570`, `daemon/src/commands.rs:944`-`daemon/src/commands.rs:993`），map-in-map supplement 通过 daemon syscall wrappers 读 outer map（`daemon/src/commands.rs:1009`-`daemon/src/commands.rs:1146`）。bpfopt `map_inline` pass-local CLI 读该目录并填充 `BpfProgram` map fields（`bpfopt/crates/bpfopt/src/passes/map_inline.rs:62`-`bpfopt/crates/bpfopt/src/passes/map_inline.rs:98`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:355`-`bpfopt/crates/bpfopt/src/passes/map_inline.rs:431`）。
- verifier states：daemon 不解析成结构体，只把 ReJIT verifier log 写到文件，并把路径作为下一步 `${VERIFIER_STATES}`（`daemon/src/commands.rs:582`-`daemon/src/commands.rs:588`, `daemon/src/commands.rs:797`-`daemon/src/commands.rs:799`）。bpfopt 读 `--verifier-states`，支持 JSON 或 raw log，空 states fail-fast（`bpfopt/crates/bpfopt/src/main.rs:787`-`bpfopt/crates/bpfopt/src/main.rs:790`, `bpfopt/crates/bpfopt/src/main.rs:1039`-`bpfopt/crates/bpfopt/src/main.rs:1083`）。parser 在 `bpfopt/crates/bpfopt/src/verifier_log.rs:168`-`bpfopt/crates/bpfopt/src/verifier_log.rs:174`，也符合设计文档 `docs/tmp/bpfopt_design_v3.md:144`-`docs/tmp/bpfopt_design_v3.md:152`。
- fd_array：daemon-only in memory。map fds 在前，module BTF fds 按 target.json `call_offset` 放后面；contiguous check 和 open fd 都在 `build_rejit_fd_array()`（`daemon/src/commands.rs:1225`-`daemon/src/commands.rs:1358`）。

### 2.8 BPF_PROG_REJIT 触发点和 log_level

- 每个 step 成功后，daemon 只有在 `${OUTPUT}` 存在且非空时才读 bytecode、decode，然后 ReJIT（`daemon/src/commands.rs:703`-`daemon/src/commands.rs:761`）。
- `log_level` 来自 `StepSpec`，由 runner 按下一步需求生成；daemon 只校验 1/2（`daemon/src/server.rs:184`-`daemon/src/server.rs:204`）。
- daemon 对 `log_level=2` 使用大 verifier log buffer，否则使用 basic buffer（`daemon/src/commands.rs:763`-`daemon/src/commands.rs:771`），然后调 `rejit_program()`（`daemon/src/commands.rs:772`-`daemon/src/commands.rs:780`）。
- 设计文档说“每个 pass 后 `BPF_PROG_REJIT(log_level=2)`”（`docs/tmp/bpfopt_design_v3.md:9`-`docs/tmp/bpfopt_design_v3.md:10`, `docs/tmp/bpfopt_design_v3.md:54`-`docs/tmp/bpfopt_design_v3.md:58`）。当前实现更细：只有需要给下一步供应 states 的 step 用 2，最后一步或下一步不需要 states 时可用 1。这是文档/实现语义差异，不是进程边界问题。

### 2.9 失败路径

- canonicalize 失败：`canonicalize_snapshot_map_refs()` 捕获 stdout/stderr 前 40 行并 `bail!`，`execute_one()` 把该 program 结果变为 `status:"error"` 并可打包 workdir（`daemon/src/commands.rs:481`-`daemon/src/commands.rs:504`, `daemon/src/commands.rs:412`-`daemon/src/commands.rs:427`）。
- bpfopt step 失败：template substitute、spawn shell、report parse、non-zero exit、output stat/read/decode 都变成 `PassStatus::FailedBpfopt`，当前 program 的 step loop break（`daemon/src/commands.rs:609`-`daemon/src/commands.rs:700`, `daemon/src/commands.rs:733`-`daemon/src/commands.rs:761`）。
- ReJIT 失败：写 verifier log，`PassStatus::FailedRejit`，break；前面已成功的 pass 已经 commit 到 live program，不 rollback（`daemon/src/commands.rs:199`-`daemon/src/commands.rs:224`, `daemon/src/commands.rs:782`-`daemon/src/commands.rs:794`）。
- program 失败不影响其它 program worker，符合设计文档 failure semantics（`docs/tmp/bpfopt_design_v3.md:181`-`docs/tmp/bpfopt_design_v3.md:189`）。

## 3. 重复代码清单（P0/P1/P2）

| 优先级 | file:line | 重复模式 | 建议重构方向 |
|---|---|---|---|
| P0 | `bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:13`-`25`, `:191`-`208`; `prefetch.rs:24`-`27`, `:171`-`174`, `:528`-`545`; `skb_load_bytes.rs:11`-`18`, `:89`-`97`; `wide_mem.rs:427`-`438` | packet ctx offsets、`PacketCtxLayout`、XDP/SKB prog_type 集合重复。review 已点名这类 7 行 `BPF_PROG_TYPE_*` 重复。 | P0 建 `passes/packet_ctx.rs`：`PacketCtxLayout {data_off,data_end_off,family}`、`packet_ctx_layout(prog_type)`、`is_packet_pointer_prog_type()`；删除 pass-local offsets/layout/prog_type match。风险低到中；估计净 -60 到 -140 LOC。 |
| P0 | `bpfopt/crates/bpfopt/src/passes/rewrite.rs:11`-`17`, `:42`-`64` | `insertions` / `internal_branch_patches` 只有 dead API 支撑；当前 production callers 主要用 `replace_range`/`delete_range`/`commit`，`prefetch` 反而手写 insertion path。 | 立即二选一：删除 `insert_before`/`add_internal_branch` 及字段，或立刻迁移 `prefetch` 到它们。按“Fail-Fast: No Dead Code”，建议先删。风险低；估计 -30 到 -70 LOC。 |
| P0 | `bpfopt/crates/bpfopt/src/passes/rewrite.rs:33`-`53` | rewrite plan mutator 用 `assert!` / `expect`，CLI malformed plan 会 panic 而不是 friendly stderr。 | `replace_range()` / `delete_range()` 返回 `Result<()>`，call sites `?`。风险低；LOC 约 +20/-10，质量收益高。 |
| P0 | `bpfopt/crates/bpfopt/src/insn.rs:8`-`90`, `:120`-`180` | 大量同名 libbpf const alias 与 `BpfInsn` wrapper；与“能用 libbpf 就用 libbpf”“同名零增量 const 别名违规”冲突。 | 分阶段删同名 alias，改 call sites 直接用 `libbpf_sys::BPF_*`；只保留 fork-only pseudo tags 或真正增加安全语义的 helper。`BpfInsn` wrapper 若保留，应收缩为 encode/decode + bitfield access shim，而不是新 UAPI surface。风险中高；LOC 可净 -150 到 -400。 |
| P1 | `bpfopt/crates/bpfopt/src/passes/utils.rs:20`-`73`, `:1029`-`1080`; `rewrite.rs:119`-`131`; `prefetch.rs:288`-`320`; `map_inline.rs:2880`-`2943` | branch fixup、addr_map 构造、BTF/annotation remap 在 shared `RewritePlan` 和手写 rewrite loops 之间分裂。 | 扩展一个真实 `RewriteBuilder`/`RewritePlan` 支持 replacement/deletion/insertion/internal branch + optional cleanup；先迁移 `prefetch`，再迁移简单 kop passes。风险中；长期净 -300 到 -600 LOC。 |
| P1 | `bpfopt/crates/bpfopt/src/passes/map_inline.rs:50`-`98`, `:355`-`431`, `:962`-`1661`, `:1749`-`2340`, `:2343`-`2946`, `:3061`-`4197`, `:4204`-`5502`; `wc -l` = 5502 | `map_inline.rs` 同时包含 CLI parsing、bpftool snapshot parsing、key extraction、mutability/hints、fixpoint driver、rewrite builder、map-in-map、direct value rewrite、register/stack analyzers、diagnostics。 | 拆到 `passes/map_inline/{cli,snapshot,hints,sites,key_extract,rewrite,map_value,r0_uses,diagnostics}.rs`。第一步只移动不改逻辑。风险中；LOC 净变化小，但审查成本显著下降。 |
| P1 | `bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:96`-`116`; `bpfopt/crates/bpfopt/src/main.rs:362`-`368`; `bpfopt/crates/bpfopt/src/passes/mod.rs:196`-`203` | `MapInfoAnalysis` 是 map_inline 专用，却作为全局 standard analysis 注册。 | 把 map_info 定义迁到 `analysis/map_info.rs`，或让 map_inline pass 私有加载，不进入全局 standard analyses。风险低中；LOC 近中性。 |
| P1 | `bpfopt/crates/bpfopt/src/main.rs:426`-`497`, `:965`-`1037`; `bpfopt/crates/bpfopt/src/pass.rs:659`-`719`; `bpfopt/crates/bpfopt/src/passes/mod.rs:113`-`119`; `bpfopt/crates/bpfopt/src/passes/utils.rs:289`-`390`; `daemon/src/bpf.rs:172`-`280` | kop metadata 散落：aliases、required kop validation、registry fields、PASS_REGISTRY metadata、proof length、daemon BTF probe target 都各有一份映射。 | 建 `kop::TargetSpec` 表：canonical name、public name、aliases、required-by pass、proof decoder、registry slot。daemon 仍只接 runner probes，不链接 bpfopt crate。风险中高；LOC 可能 -100 到 -250。 |
| P1 | `bpfopt/crates/bpfopt/src/passes/const_prop.rs:34`-`339`; `map_inline.rs:1266`-`1432`; `wide_mem.rs:371`-`414` | verifier-state 查询分别内嵌在 pass：const_prop 有 exact const oracle，map_inline 有 stack/key extraction，wide_mem 有 BTF ptr oracle。 | 抽 `analysis/verifier_state.rs`，提供 typed query：exact scalar、stack bytes、latest reg type、frame consensus。注意 required/optional state semantics。风险中；LOC 初期 +100，长期 -200+。 |
| P2 | `bpfopt/crates/bpfopt/src/main.rs:894`-`939`; `daemon/src/bpf.rs:358`-`395` | prog type string<->u32 映射在 bpfopt 和 daemon 各有一份。跨 CLI crate 不能 path-dep，直接共享不合规。 | 只在 repo 内用小脚本生成两份表，或保持现状但加 drift check。风险低；LOC 影响小。 |
| P2 | `bpfopt/crates/bpfopt/src/main.rs:1193`-`1214`; `bpfopt/crates/bpfopt/src/pass.rs:538`-`555`; `map_inline.rs:4902`-`4993`; `daemon/src/commands.rs:180`-`197` | diagnostics/report/error capture 各自成体系：PassResult diagnostics、map_inline env debug、daemon step stdout/stderr/error。 | 建 pass-local diagnostic sink，输出仍保持 `--report` JSON；daemon 只捕获报告和 subprocess output。风险低；LOC -50 到 -120。 |
| P2 | `daemon/src/commands.rs:1105`-`1113`; `bpfopt/crates/bpfopt/src/pass.rs:206`-`215`; `map_inline.rs:4971`-`4982` | hex formatting helper 重复。 | bpfopt crate 内可共享一个 helper；daemon 因 no compile-time cross-dep 可保留本地版本。风险低；LOC 小。 |

## 4. 职责不清晰清单（按模块）

### `bpfopt/crates/bpfopt/src/main.rs`

- 职责包括 CLI dispatch、canonicalize implementation、prog_type parser、target/kfunc registry parsing、verifier-state parsing、report serialization。入口清晰但文件承担太多 orchestration/detail。
- `run_main()` 的 mode dispatch 本身合理（`bpfopt/crates/bpfopt/src/main.rs:240`-`274`），但 `canonicalize_map_refs_to_idx()`（`bpfopt/crates/bpfopt/src/main.rs:529`-`588`）和 kop registry mapping（`bpfopt/crates/bpfopt/src/main.rs:965`-`1037`）适合移到 `canonicalize.rs` / `kop.rs`。
- 风险：移动不应改变 CLI semantics。优先级 P2；LOC 净影响小，结构收益中。

### `bpfopt/crates/bpfopt/src/pass.rs`

- `BpfProgram` 是核心 IR，但已经装入 map_inline 专用 side-input、PMU branch stats、verifier states、BTF func/line info、map provider（`bpfopt/crates/bpfopt/src/pass.rs:84`-`130`）。
- `PassContext` 同时含 kop registry、platform、policy、prog_type（`bpfopt/crates/bpfopt/src/pass.rs:642`-`657`）。在 production CLI 一次只跑一个 pass 的情况下，`policy.enabled_passes` 属于残留 pipeline 概念。
- 建议：保留 `BpfProgram` 的通用 fields；map_inline-only snapshot/hints 尽量下沉到 `MapInlineCliPass` 或 pass-local context。`PassManager` 可收缩成 one-pass executor，test-only multi-pass builder 继续存在。优先级 P2；风险中。

### `bpfopt/crates/bpfopt/src/passes/map_inline.rs`

- 5502 行单文件是当前最大职责混合点。它在 `MapInlineCliPass` 中读 map snapshots（`bpfopt/crates/bpfopt/src/passes/map_inline.rs:62`-`98`），又在同文件实现 bpftool JSON schema（`:264`-`350`）、snapshot parser（`:355`-`431`）、fixed-point driver（`:2343`-`2435`）、rewrite commit（`:2880`-`2943`）、diagnostics/debug logger（`:4902`-`4993`）。
- 建议先纯移动拆文件，不做行为改动。优先级 P1；风险主要是 merge conflict 和 test import churn。

### `bpfopt/crates/bpfopt/src/passes/utils.rs` 与 `rewrite.rs`

- `utils.rs` 已经 1532 行，包含 branch fixup、BTF remap、kop proof layout、cleanup、emit helpers；`rewrite.rs` 又有部分重写语义。边界是“低层 helper” vs “rewrite transaction”，但现状并不稳定。
- `RewritePlan::commit()` 统一 replacement/deletion 的 branch fixup/BTF/annotation remap（`bpfopt/crates/bpfopt/src/passes/rewrite.rs:66`-`139`），但多个 passes 仍手写 addr_map loops（见第 3 节 P1）。
- 建议：`utils.rs` 留 pure stateless helpers；所有 program mutation 走 `rewrite.rs` transaction。优先级 P1。

### `daemon/src/commands.rs`

- 这个文件现在同时做 plan execution、shell templating、canonicalize subprocess、bpftool map snapshot、map-in-map supplement、fd_array construction、ReJIT call、result shaping，行数 1689。
- 这些职责都属于 daemon 边界，没有违反 v3，但可以内部拆成 `plan.rs`、`map_snapshot.rs`、`fd_array.rs`、`subprocess.rs`，降低错误面。优先级 P2；不要把任何逻辑挪到 bpfopt crate，避免 CLI cross-dependency。

### Daemon / bpfopt borderline

- verifier log parser 的实现属于 bpfopt（`bpfopt/crates/bpfopt/src/verifier_log.rs:168`-`174`），daemon 只传 raw log path。这符合设计文档 `docs/tmp/bpfopt_design_v3.md:144`-`152`。
- map-ref canonicalize 的实现属于 bpfopt，daemon 只在 snapshot 后调用一次 subprocess。这符合 `CLAUDE.md:95`-`CLAUDE.md:99` 和 `CLAUDE.md:117`-`CLAUDE.md:120`。
- 当前不清晰点不是 ownership，而是文档描述“daemon 解析 log_level=2 verifier log，写 verifier-states.json”（`docs/tmp/bpfopt_design_v3.md:54`-`docs/tmp/bpfopt_design_v3.md:58`, `docs/tmp/bpfopt_design_v3.md:123`-`docs/tmp/bpfopt_design_v3.md:129`）与实现“daemon 写 raw log，bpfopt 下步解析”不完全一致。建议更新设计文档措辞，不建议把 parser 挪进 daemon。

## 5. Pass-prologue / pass-epilogue 讨论

| 建议 | 当前实现位置 | 提议位置 | 风险 | LOC 影响 | 优先级 |
|---|---|---|---|---|---|
| Pre-pass canonicalization: map refs 保持 snapshot-only；新增轻量 bytecode normalize 只处理局部无语义格式问题。 | map refs：daemon 调 `canonicalize_snapshot_map_refs()`（`daemon/src/commands.rs:448`-`504`, `:534`-`542`），bpfopt 实现 `run_canonicalize_map_refs()`（`bpfopt/crates/bpfopt/src/main.rs:276`-`295`）。LD_IMM64 boundary/NOP/JA cleanup 分散在 `rewrite.rs:193`-`201`, `utils.rs:885`-`902`, `utils.rs:1011`-`1027`。 | 新 `bpfopt/src/normalize.rs`，由 CLI 在 `run_single_pass()` 读 bytecode 后调用；map-ref canonicalize 仍只在 daemon snapshot 后调用。 | 中：任何 normalize 会改变 PC，影响 report、BTF remap、verifier-state PC。必须 opt-in/very small scope。 | +100 到 +180，后续可删 pass-local小段 -50 到 -120。 | P2 |
| Pre-pass invariant check: instruction boundary、branch target、pseudo-call target、不能跳进 LD_IMM64 second slot。 | `read_bytecode()` 只检查 byte length 是 8 的倍数（`bpfopt/crates/bpfopt/src/main.rs:499`-`527`）；`RewritePlan::validate()` 只保护使用 RewritePlan 的 pass（`bpfopt/crates/bpfopt/src/passes/rewrite.rs:148`-`190`）。 | 新 `bytecode/validate.rs` 或 `passes/rewrite.rs::validate_program_shape()`；CLI pass 前和 pass 后都跑，错误直接 exit 1。 | 中：可能暴露现有 corpus 中“以前靠 verifier 报错”的 case；但符合 fail-fast。 | +180 到 +260；净压缩不大，但防 bug。 | P1 |
| Post-pass cleanup: unreachable/NOP coalescing 不应由每个 pass 自己决定。 | `bounds_check_merge` 手动 cleanup（`bpfopt/crates/bpfopt/src/passes/bounds_check_merge.rs:172`-`181`）；`map_inline` 只在 removed null check 时 cleanup（`bpfopt/crates/bpfopt/src/passes/map_inline.rs:2914`-`2931`）；`dce` 只删除 dead register defs（`bpfopt/crates/bpfopt/src/passes/dce.rs:8`-`12`, `:23`-`50`）。 | `RewritePlan::commit_with_cleanup(CleanupPolicy)`，默认 off，pass 显式选择 `Unreachable | Nop | DeadDefs`。 | 中高：默认全局 cleanup 会改变 verifier-state PC 和 diagnostics；必须 opt-in。 | +80 到 +140，迁移后 -80 到 -180。 | P1 |
| Post-pass verifier-state refresh: 维持 daemon after-ReJIT refresh，不放进 bpfopt。 | daemon 成功 ReJIT 后 `verifier_states_path = verifier_log_path`（`daemon/src/commands.rs:797`）；第一步用不存在 path 强制 runner 排序（`daemon/src/commands.rs:582`-`588`）；PassManager 若 in-process 多 pass transform 会清空 states（`bpfopt/crates/bpfopt/src/pass.rs:930`-`933`）。 | 保持在 daemon；增加 plan validation 或 docs：state-needing pass 必须由前一 step 的 outgoing `log_level=2` 供应。runner 已在 `rejit_plan.py:122`-`127` 做这件事。 | 低：production 一次一进程一 pass，无 stale state；风险只在 test/in-process pipeline。 | +20 到 +60。 | P2 |
| Shared diagnostics/observability: pass 不应各自 env print/字符串计数。 | `PassResult.diagnostics`（`bpfopt/crates/bpfopt/src/pass.rs:538`-`555`）、`pass_report()`（`bpfopt/crates/bpfopt/src/main.rs:1193`-`1214`）、map_inline env debug（`bpfopt/crates/bpfopt/src/passes/map_inline.rs:4906`-`4913`）、daemon subprocess capture（`daemon/src/commands.rs:624`-`700`）。 | `pass::Diagnostics` builder + stable report schema；debug log 走 common trace flag/env。 | 低：注意不要把 framework benchmark summary 混进 pass report。 | +50 初期，后续 -50 到 -120。 | P2 |
| Rewrite epilogue: branch fixup + annotation/BTF remap + internal branch patching 统一事务。 | `RewritePlan::commit()` 已有一半（`bpfopt/crates/bpfopt/src/passes/rewrite.rs:66`-`139`），但 prefetch/map_inline/kop passes 手写 addr_map/branch/remap（第 3 节 P1）。 | 完善 `RewritePlan`，先删 dead API，再按 pass 迁移。 | 中高：BTF func/line remap和 kop proof subprog layout很敏感。 | 长期净 -300 到 -600。 | P1 |

是否需要“通用 pass-prologue/pass-epilogue”的结论：

- 需要 shared invariant check 和 rewrite commit epilogue。
- 不建议立刻增加一个隐式全局 normalize/cleanup pipeline。bpfopt production 是 one-pass CLI，daemon 每 pass 后真实 ReJIT；任何隐式 PC 变化都会影响 verifier-state side input、BTF remap、pass report 和 failure artifact 可解释性。
- `dce` 不能自然胜任所有 post-pass cleanup：当前它只移除 side-effect-free dead register defs（`bpfopt/crates/bpfopt/src/passes/dce.rs:8`-`12`），不是 NOP/unreachable cleanup，也不会替代 branch fixup/annotation remap。

## 6. 推荐 next-step 优先级（按净 LOC 和“压缩代码量”目标）

1. P0：删除或落地 `RewritePlan` dead insertion/internal APIs。先做最小删除，避免 speculative infrastructure 继续扩散。预计 -30 到 -70 LOC，风险低。
2. P0：清理同名 libbpf const alias 和无增量 wrapper surface。先 production code，后 tests。保留 fork-only pseudo 常量；其它直接用 `libbpf_sys::*`。预计净 -150 到 -400 LOC，风险中高，需要小步提交。
3. P0：抽 `passes/packet_ctx.rs`，合并 bounds_check_merge/prefetch/skb_load_bytes/wide_mem 的 packet ctx/prog_type 判定。预计净 -60 到 -140 LOC，风险低中。
4. P1：确定 `RewritePlan` 方向：若保留 insertion/internal patch，就先迁移 `prefetch`；否则不要保留未调用 API。随后逐个迁移 rotate/cond_select/extract/bulk_memory/endian/ccmp 的手写 addr_map loops。预计长期 -300 到 -600 LOC。
5. P1：把 `map_inline.rs` 拆模块。第一轮只移动代码，不重构行为；第二轮再提取 verifier-state oracle、snapshot parser、rewrite builder。净 LOC 初期变化小，但会显著降低 review/bug 成本。
6. P1：合并 kop target metadata 的多份表。注意不能让 daemon compile-time 依赖 bpfopt；可以用生成表或重复生成两端代码。
7. P2：更新 `docs/tmp/bpfopt_design_v3.md` 中 protocol/log parser/log_level 描述：当前实现是 `execute_plan` + runner YAML command + raw verifier log path 传给 bpfopt 解析，不是旧 `optimize/enabled_passes`。

## 7. 报告范围限制

- 本报告只写 `docs/tmp/bpfopt_architecture_walk_2026-05-09.md`；没有修改 `bpfopt/crates/bpfopt/src/` 或 `daemon/src/`。
- 已读取权威文档 `docs/tmp/bpfopt_design_v3.md`、`CLAUDE.md`，以及用户点名的 `main.rs`、`pass.rs`、`passes/mod.rs`、`daemon/src/commands.rs`、`daemon/src/syscall.rs`、`passes/rewrite.rs`；还读取了 server/bpf/runner plan 和 named pass 重复点。
- 已按要求使用 `rg`、`wc -l`、`cargo doc --workspace --no-deps`。repo 根目录没有 `Cargo.toml`，所以该命令在 `bpfopt/` 和 `daemon/` 两个 workspace 分别运行；两者均成功，`bpfopt` 有一个 rustdoc unresolved link 警告在 `pass.rs:381`。
- 未跑 benchmark、未跑 `make test`、未 commit。报告中的 LOC 影响是粗略工程估算，不是 patch 统计。
- 没逐行审计所有 pass 的语义正确性；对 rotate/cond_select/extract/bulk/endian/ccmp 主要用 `rg` 核对 rewrite/addr_map/fixup 模式。后续做实际重构前仍需逐 pass 审查 verifier/BTF 约束和测试覆盖。
