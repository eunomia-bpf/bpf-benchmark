# bpfopt 独立仓库架构设计

## 0. 设计目标

`bpfopt` 的定位是一个独立的 eBPF bytecode 优化器，类似 LLVM `opt`：

1. 输入是 BPF bytecode 和显式 side-input。
2. 输出是优化后的 BPF bytecode、结构化变换报告、以及少量“待外部绑定”的链接需求。
3. 核心库不做任何内核交互，不依赖 live kernel、BTF 扫描、`bpftool`、`perf_event_open`、`/proc/cpuinfo`、`/sys/kernel/btf`。
4. profiling / verifier / map value 一律视为外部采集并标准化后的输入，不在核心库内部采集。
5. `daemon` 退化为 kernel-facing driver：枚举、snapshot、dry-run verify、最终 REJIT、map invalidation watch。

由 `docs/kernel-jit-optimization-plan.md` §3 / §4 / §4.6 推导出的三条硬约束：

1. `bpfopt` 必须同时支持三类 pass：纯 bytecode pass、target-aware kinsn pass、runtime-guided specialization pass。
2. per-pass verify 仍然要保留，但 verify 必须是外部 hook，不得把 kernel 依赖带回 `bpfopt`。
3. kinsn 可用性必须是“声明式 target 描述”，而不是在库内部做 runtime BTF discovery。

非目标：

1. `bpfopt` 不负责 REJIT syscall。
2. `bpfopt` 不负责 map watch / invalidation tick。
3. `bpfopt` 不负责 profile 采集。
4. `bpfopt` 不负责 live kernel map lookup。

## A. `bpfopt` 公共 API 设计

### A.1 `lib.rs` 导出面

建议 `bpfopt/src/lib.rs` 导出四层 API：

```rust
pub use crate::api::{
    analyze, list_passes, optimize, optimize_with_validator,
    AnalysisInput, AnalysisOutput, AnalyzeKind,
    OptimizeInput, OptimizeOutput, OptConfig,
};
pub use crate::ir::{BpfInsn, BytecodeBlob, BytecodeFormat};
pub use crate::target::{TargetDesc, ProgramAbi, KinsnCatalog, KinsnRequirement};
pub use crate::inputs::{PgoProfile, VerifierStateSet, MapValueSet, ProgramMetadata};
pub use crate::report::{PassInfo, PassReport, TransformReport, SpecializationDependency};
pub use crate::validate::{ValidationOracle, ValidationOutcome, ValidationStatus};
```

高层函数：

```rust
pub fn optimize(input: OptimizeInput) -> anyhow::Result<OptimizeOutput>;
pub fn optimize_with_validator<V: ValidationOracle>(
    input: OptimizeInput,
    validator: &mut V,
) -> anyhow::Result<OptimizeOutput>;
pub fn analyze(input: AnalysisInput) -> anyhow::Result<AnalysisOutput>;
pub fn list_passes() -> &'static [PassInfo];
```

设计原则：

1. `optimize()` 是纯库 API，不做 syscall，不做 host feature detect。
2. `optimize_with_validator()` 允许外部 embedding 提供 per-pass validator，保留当前 daemon 的 `BPF_PROG_LOAD` dry-run 架构。
3. `analyze()` 是只读 API，用于离线诊断、pass 候选发现、debug、benchmark explainability。
4. `list_passes()` 返回 machine-readable pass registry，而不是字符串 help。

### A.2 输入结构

表面 API 保持“bytecode + OptConfig”，但 `OptConfig` 里必须补上当前 daemon 里隐式存在、而纯库不能再偷拿的上下文。

```rust
pub struct OptimizeInput {
    pub bytecode: BytecodeBlob,
    pub config: OptConfig,
}

pub struct BytecodeBlob {
    pub format: BytecodeFormat,   // v1 只支持 RawInsnArray
    pub bytes: Vec<u8>,           // raw struct bpf_insn[]
}

pub enum BytecodeFormat {
    RawInsnArray,
}

pub struct OptConfig {
    pub pipeline: PipelineSpec,
    pub target: TargetDesc,
    pub platform: PlatformDesc,
    pub kinsns: KinsnCatalog,
    pub pgo_profile: Option<PgoProfile>,
    pub verifier_states: Option<VerifierStateSet>,
    pub map_values: Option<MapValueSet>,
    pub program: ProgramMetadata,
    pub strictness: Strictness,
}
```

其中 prompt 点名的字段保留：

1. `platform`
2. `kinsns`
3. `pgo_profile`
4. `verifier_states`
5. `map_values`

额外必须补的字段：

1. `program`
   原因：当前 `wide_mem` / `skb_load_bytes_spec` / `bounds_check_merge` 依赖 `prog_type`，`map_inline` 依赖 `map_fd_bindings`；纯库不能再隐式从内核拿。
2. `strictness`
   原因：需要明确“缺 side-input / 缺 kinsn binding / pass 不可用”时是报错还是结构化 skip。

建议的 `ProgramMetadata`：

```rust
pub struct ProgramMetadata {
    pub abi: ProgramAbi,
    pub name: Option<String>,
    pub bytecode_sha256: Option<String>,
    pub map_bindings: Vec<MapBinding>,
}

pub struct MapBinding {
    pub old_fd: i32,
    pub pseudo_kind: MapPseudoKind,   // map_fd | map_value
    pub logical_map_id: String,       // daemon 可填 "kernel-map-id:123"
}

pub enum MapPseudoKind {
    MapFd,
    MapValue,
}
```

`ProgramAbi` 必须是语义化枚举，而不是把 Linux `prog_type` 的裸 `u32` 直接放到核心 API：

```rust
pub enum ProgramAbi {
    Generic,
    TcCls,
    TcAct,
    Xdp,
    SkSkb,
    LwtIn,
    LwtOut,
    LwtXmit,
    Other(String),
}
```

原因：

1. `bpfopt` 需要的是“packet-pointer / ctx layout / verifier safety class”，不是 syscall 数字本身。
2. 未来 libbpf 集成、离线对象优化、测试输入都可以直接构造同一语义枚举。

### A.3 target / kinsn 输入模型

`TargetDesc` 和 `KinsnCatalog` 分离：

```rust
pub struct PlatformDesc {
    pub arch: Arch,
    pub march: String,                 // x86_64-v3 / armv8.6-a / generic
    pub cpu: Option<String>,
    pub features: BTreeSet<TargetFeature>,
}

pub struct TargetDesc {
    pub endianness: Endianness,
    pub pointer_width: u8,
    pub verifier_model: String,        // "linux-ebpf-v1"
}

pub struct KinsnCatalog {
    pub entries: BTreeMap<String, KinsnCapability>,
}

pub struct KinsnCapability {
    pub available: bool,
    pub encodings: BTreeSet<KinsnEncoding>,
    pub binding: Option<KinsnBinding>,
}

pub struct KinsnBinding {
    pub symbol: String,
    pub btf_func_id: Option<i32>,
    pub transport_slot_hint: Option<u16>,
    pub linker_key: Option<String>,
}
```

约束：

1. pass 只看 `available + encodings` 决定“能不能重写”。
2. 真实 `btf_func_id` / `fd_array slot` 不是必须输入；缺 binding 时，`bpfopt` 仍可输出带 relocation 的 bytecode。
3. `daemon` discovery 负责把 runtime BTF 发现结果翻译成这个 manifest。
4. 未来 libbpf 可在 load-time 填同样的 manifest。

### A.4 输出结构

```rust
pub struct OptimizeOutput {
    pub bytecode: BytecodeBlob,
    pub changed: bool,
    pub report: TransformReport,
    pub link_requirements: Vec<KinsnRequirement>,
    pub specialization_dependencies: Vec<SpecializationDependency>,
    pub updated_side_inputs: UpdatedSideInputs,
}
```

`TransformReport`：

```rust
pub struct TransformReport {
    pub input_insn_count: usize,
    pub output_insn_count: usize,
    pub total_sites_applied: usize,
    pub pass_reports: Vec<PassReport>,
    pub diagnostics: Vec<String>,
}

pub struct PassReport {
    pub pass: String,
    pub changed: bool,
    pub action: PassAction,                // kept | skipped | rejected | rolled_back
    pub sites_applied: usize,
    pub insn_delta: i64,
    pub skip_reasons: BTreeMap<String, usize>,
    pub diagnostics: Vec<String>,
    pub validation: Option<ValidationOutcome>,
}
```

这要覆盖 §4.6 的结构化 per-pass 记录要求：

1. `pass`
2. `changed`
3. `sites_applied`
4. `insn_delta`
5. `verify_result`
6. `verify_error`
7. `action`

`link_requirements` 是新引入的关键输出：

```rust
pub struct KinsnRequirement {
    pub pc: usize,                    // output bytecode 中 CALL 的 pc
    pub symbol: String,               // e.g. "bpf_rotate64"
    pub encoding: KinsnEncoding,      // packed_call
}
```

原因：

1. `bpfopt` 不能假定 runtime BTF 一定存在。
2. 但 kinsn pass 仍需要产出“符号化 kinsn 调用”。
3. 因此 output 是“bytecode + relocation-like requirements”，由 daemon / libbpf 在最后一跳绑定。

`specialization_dependencies` 用来承接当前 `map_inline_records`：

```rust
pub enum SpecializationDependency {
    MapValueEquals {
        logical_map_id: String,
        key: Vec<u8>,
        expected_value: Vec<u8>,
    },
}
```

daemon 之后用它驱动 invalidation；libbpf 静态 load-time 模式则可以忽略。

`updated_side_inputs` 的作用是支持“单 pass CLI 链式运行”：

1. pass 改了 PC 之后，`branch_profile` / `verifier_states` 这种按 PC 对齐的 side-input 必须 remap。
2. 如果不把 remap 后的 side-input 一起输出，`run-pass A | run-pass B` 会失真。

### A.5 validator hook

为保留当前 daemon 的 per-pass verify 流程，库层定义抽象 validator：

```rust
pub trait ValidationOracle {
    fn validate_after_pass(
        &mut self,
        pass: &PassInfo,
        program: &[u8],
        link_requirements: &[KinsnRequirement],
    ) -> anyhow::Result<ValidationOutcome>;
}

pub struct ValidationOutcome {
    pub status: ValidationStatus,      // accepted | rejected | skipped
    pub message: Option<String>,
    pub verifier_states: Option<VerifierStateSet>,
}
```

约束：

1. trait 本身不暴露 kernel type。
2. daemon 可用 `BPF_PROG_LOAD(log_level=2)` 实现它。
3. validator 返回的新 `verifier_states` 会覆盖旧输入，继续喂给后续 pass。
4. 默认 `optimize()` 使用 no-op validator。

### A.6 `analyze()` API

```rust
pub struct AnalysisInput {
    pub bytecode: BytecodeBlob,
    pub config: OptConfig,
    pub kinds: Vec<AnalyzeKind>,
}

pub enum AnalyzeKind {
    Summary,
    Cfg,
    Liveness,
    BranchTargets,
    MapReferences,
    PassCandidates,
}
```

`AnalysisOutput` 至少包含：

1. 基础 IR 摘要
2. 请求的 analysis 结果
3. 每个 pass 的候选 site 和 blocker

这样 `bpfopt analyze` 可以承担当前 daemon 里 detection-only / debug 输出的角色。

### A.7 C FFI 草案

初版 C ABI 只做三件事：传 bytecode buffer、传 JSON config、取 JSON report。

```c
typedef struct bpfopt_config bpfopt_config_t;
typedef struct bpfopt_result bpfopt_result_t;

bpfopt_config_t *bpfopt_config_new(void);
void bpfopt_config_free(bpfopt_config_t *);

int bpfopt_config_set_json(
    bpfopt_config_t *cfg,
    const char *json,
    size_t json_len);

int bpfopt_optimize(
    const uint8_t *bytecode,
    size_t bytecode_len,
    const bpfopt_config_t *cfg,
    bpfopt_result_t **out);

int bpfopt_analyze(
    const uint8_t *bytecode,
    size_t bytecode_len,
    const bpfopt_config_t *cfg,
    bpfopt_result_t **out);

const uint8_t *bpfopt_result_bytecode(
    const bpfopt_result_t *result,
    size_t *len);

const char *bpfopt_result_report_json(
    const bpfopt_result_t *result,
    size_t *len);

const char *bpfopt_result_updated_side_inputs_json(
    const bpfopt_result_t *result,
    size_t *len);

void bpfopt_result_free(bpfopt_result_t *);
const char *bpfopt_last_error_message(void);
```

FFI 设计原则：

1. config / report / side-inputs 全走 JSON，避免在 C ABI 暴露大量 version-sensitive Rust struct。
2. raw bytecode 保持 `uint8_t* + len`。
3. v1 不提供 C callback validator；需要 per-pass verify 的 embedding 走 Rust API。
4. 这足够支撑未来 libbpf 集成：libbpf 传字节码和 target/config JSON，拿回 bytecode + report + kinsn requirements。

## B. CLI 设计

### B.1 二进制与子命令

建议仓库提供一个二进制 `bpfopt`，最小三条主子命令：

1. `bpfopt optimize`
2. `bpfopt analyze`
3. `bpfopt list-passes`

另外提供专家模式：

4. `bpfopt pass <pass-name>`

`pass <pass-name>` 是单-pass filter，用于 debug / differential testing / shell pipeline；`optimize` 才是默认入口。

### B.2 `optimize`

建议接口：

```bash
bpfopt optimize \
  --input prog.bin \
  --meta prog.meta.json \
  --target target.json \
  --pgo profile.json \
  --verifier-states verifier.json \
  --map-values maps.json \
  --output prog.opt.bin \
  --meta-out prog.opt.meta.json
```

语义：

1. `prog.bin` 是 raw `struct bpf_insn[]`。
2. `prog.meta.json` 是主 sidecar，包含 pipeline 选择、program ABI、map binding。
3. `target.json` / `profile.json` / `verifier.json` / `maps.json` 是标准化输入，主 sidecar 可选择内联或引用它们。
4. `prog.opt.meta.json` 输出 report、updated side-inputs、kinsn relocations、specialization dependencies。

### B.3 `analyze`

建议接口：

```bash
bpfopt analyze \
  --input prog.bin \
  --meta prog.meta.json \
  --target target.json \
  --kinds summary,cfg,pass-candidates \
  --output analysis.json
```

输出 JSON 包含：

1. CFG / liveness / branch targets 等 analysis
2. 每个 pass 的 candidate sites
3. 每个 candidate 的 blocker，例如：
   `no_kinsn_binding`
   `missing_verifier_states`
   `interior_branch_target`
   `packet_prog_type_not_safe`

### B.4 `list-passes`

文本模式：

```bash
bpfopt list-passes
```

JSON 模式：

```bash
bpfopt list-passes --format json
```

每个 pass 至少输出：

1. `name`
2. `category`
3. `default_enabled`
4. `requires_analyses`
5. `requires_side_inputs`
6. `requires_target_features`
7. `requires_kinsns`
8. `description`

### B.5 管道模式

主结论：

1. 磁盘上和稳定接口上，规范格式仍然是“raw binary bytecode + JSON sidecar”。
2. 真正要做 `stdin/stdout` pass pipeline 时，单靠 split artifacts 不够，因为单条 shell pipe 不能同时安全传 bytecode 和 sidecar。
3. 所以 CLI 提供两种 I/O 模式。

模式 1：split mode，标准落盘格式

```bash
bpfopt pass wide_mem \
  --meta in.meta.json \
  --meta-out out.meta.json \
  < in.bin > out.bin
```

模式 2：pipe mode，专家链式格式

```bash
bpfopt pack --input in.bin --meta in.meta.json \
| bpfopt pass wide_mem --pipe \
| bpfopt pass const_prop --pipe \
| bpfopt pass dce --pipe \
| bpfopt unpack --output out.bin --meta-out out.meta.json
```

这里的 `--pipe` 是一个很小的 framed stream，只是为了把“raw bytecode + JSON sidecar”一起在 stdin/stdout 上传递；逻辑模型不变。

原因：

1. 单 pass 之间必须传递 remap 后的 `verifier_states` / `pgo_profile`。
2. 只传 bytecode、不传 remap 后 sidecar，会让下一 pass 看到错位的 PC。

### B.6 主 sidecar 内容

建议 `prog.meta.json` 最小字段：

```json
{
  "schema": "bpfopt/v1/bundle",
  "pipeline": {
    "passes": ["map_inline", "const_prop", "dce"],
    "strict_side_inputs": false,
    "require_resolved_kinsns": false
  },
  "program": {
    "abi": "xdp",
    "name": "foo",
    "bytecode_sha256": "..."
  },
  "map_bindings": [
    { "old_fd": 17, "pseudo_kind": "map_fd", "logical_map_id": "kernel-map-id:123" }
  ]
}
```

`meta-out` 需要包含：

1. `transform_report`
2. `link_requirements`
3. `specialization_dependencies`
4. `updated_side_inputs`
5. `output_bytecode_sha256`

### B.7 默认 pass pipeline

`list-passes` 和 `optimize` 的默认 pipeline 应沿用当前 OSDI 范围：

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `bulk_memory`
8. `rotate`
9. `cond_select`
10. `extract`
11. `endian_fusion`
12. `branch_flip`

安全 pass 继续不进默认 pipeline。

## C. 代码拆分方案

### C.1 拆分原则

拆分边界按“是否需要 live kernel state / syscall / host probing”划分：

1. 纯 IR / analysis / pass / log parser -> `bpfopt`
2. 内核枚举 / map snapshot / BTF discovery / dry-run verify / REJIT / invalidation -> `daemon`
3. profiling 采集 -> 单独工具，不属于 `bpfopt` 核心，也不再属于瘦身后的 `daemon`

### C.2 文件迁移表

| 当前文件 | 目标位置 | 处理方式 | 备注 |
|---|---|---|---|
| `daemon/src/insn.rs` | `bpfopt/src/ir/insn.rs` | 基本整体移动 | 删除 test-only ELF helper |
| `daemon/src/pass.rs` | `bpfopt/src/pass/{manager.rs,api.rs,program.rs}` | 拆分重构 | 去掉 BTF FD、host detect、kernel-specific context |
| `daemon/src/verifier_log.rs` | `bpfopt/src/inputs/verifier.rs` | 基本整体移动 | parser 留在库里，采集逻辑不留 |
| `daemon/src/analysis/branch_target.rs` | `bpfopt/src/analysis/branch_target.rs` | 直接移动 | 纯 analysis |
| `daemon/src/analysis/cfg.rs` | `bpfopt/src/analysis/cfg.rs` | 直接移动 | 纯 analysis |
| `daemon/src/analysis/liveness.rs` | `bpfopt/src/analysis/liveness.rs` | 直接移动 | 纯 analysis |
| `daemon/src/analysis/map_info.rs` | `bpfopt/src/analysis/map_refs.rs` + daemon glue | 拆分 | 解析/绑定逻辑进 bpfopt，live map resolver 留 daemon |
| `daemon/src/passes/rotate.rs` | `bpfopt/src/passes/rotate.rs` | 重构后移动 | 用 symbolic kinsn requirement 代替 BTF FD slot |
| `daemon/src/passes/cond_select.rs` | `bpfopt/src/passes/cond_select.rs` | 重构后移动 | 同上 |
| `daemon/src/passes/extract.rs` | `bpfopt/src/passes/extract.rs` | 重构后移动 | 同上 |
| `daemon/src/passes/endian.rs` | `bpfopt/src/passes/endian.rs` | 重构后移动 | 同上 |
| `daemon/src/passes/bulk_memory.rs` | `bpfopt/src/passes/bulk_memory.rs` | 重构后移动 | 同上 |
| `daemon/src/passes/wide_mem.rs` | `bpfopt/src/passes/wide_mem.rs` | 直接移动 | 只依赖 ABI/analysis |
| `daemon/src/passes/branch_flip.rs` | `bpfopt/src/passes/branch_flip.rs` | 直接移动 | 只消费 PGO side-input |
| `daemon/src/passes/const_prop.rs` | `bpfopt/src/passes/const_prop.rs` | 直接移动 | 消费 verifier_states |
| `daemon/src/passes/dce.rs` | `bpfopt/src/passes/dce.rs` | 直接移动 | 纯 pass |
| `daemon/src/passes/skb_load_bytes.rs` | `bpfopt/src/passes/skb_load_bytes.rs` | 直接移动 | 只依赖 ProgramAbi |
| `daemon/src/passes/bounds_check_merge.rs` | `bpfopt/src/passes/bounds_check_merge.rs` | 直接移动 | 只依赖 ProgramAbi |
| `daemon/src/passes/map_inline.rs` | `bpfopt/src/passes/map_inline.rs` | 重构后移动 | 改为消费 `MapValueSet`，禁止直接调 `crate::bpf` |
| `daemon/src/passes/utils.rs` | `bpfopt/src/passes/utils.rs` + linker glue | 拆分 | branch fixup 等移走，BTF slot glue 不移 |
| `daemon/src/passes/mod.rs` | `bpfopt/src/passes/mod.rs` | 重构后移动 | 输出 structured pass registry |
| `daemon/src/main.rs` | daemon 保留 | 缩薄 | 只做 CLI / socket / orchestration |
| `daemon/src/server.rs` | daemon 保留 | 缩薄 | 只做 request dispatch / invalidation tick |
| `daemon/src/commands.rs` | daemon 保留 | 大幅缩薄 | 只做 snapshot -> bpfopt -> validate -> bind -> REJIT |
| `daemon/src/bpf.rs` | daemon 保留 | 保留 | raw syscall wrapper |
| `daemon/src/invalidation.rs` | daemon 保留 | 保留 | map watch 不属于 optimizer |
| `daemon/src/kfunc_discovery.rs` | daemon 保留 | 保留 | runtime discovery -> target manifest |
| `daemon/src/profiler.rs` | 从 daemon 移出 | 不进 bpfopt | 改为独立 `bpfopt-profcollect` |
| `daemon/src/elf_parser.rs` | 暂留 daemon/test support | 不进核心 | 与 raw bytecode optimizer 无关 |

### C.3 需要新增的 `bpfopt` 模块

建议新增：

1. `bpfopt/src/inputs/mod.rs`
   放 `PgoProfile` / `VerifierStateSet` / `MapValueSet` / `ProgramMetadata`
2. `bpfopt/src/target.rs`
   放 `PlatformDesc` / `TargetDesc` / `ProgramAbi` / `KinsnCatalog`
3. `bpfopt/src/link.rs`
   放 `KinsnRequirement` 和 symbolic relocation patch points
4. `bpfopt/src/validate.rs`
   放 `ValidationOracle` trait
5. `bpfopt/src/report.rs`
   放 `PassInfo` / `PassReport` / `TransformReport`

### C.4 需要新增的 daemon glue

daemon 侧需要新增四块胶水：

1. `target_manifest.rs`
   把 `kfunc_discovery` + host CPU detect + program ABI 映射成 `TargetDesc + KinsnCatalog`
2. `side_input_collectors.rs`
   负责：
   - 原始 verifier log capture -> `VerifierStateSet`
   - live map metadata/value snapshot -> `MapValueSet`
   - optional external profile load -> `PgoProfile`
3. `validator.rs`
   用 `BPF_PROG_LOAD(log_level=2)` 实现 `ValidationOracle`
4. `linker.rs`
   把 `KinsnRequirement` 解析成真实 `btf_func_id` / `fd_array`，并 patch output bytecode

### C.5 daemon 调 `bpfopt` 的具体 API

推荐调用链：

```rust
let input = bpfopt::OptimizeInput {
    bytecode: snapshot.orig_bytecode,
    config: OptConfig {
        pipeline,
        target,
        platform,
        kinsns,
        pgo_profile,
        verifier_states,
        map_values,
        program,
        strictness,
    },
};

let mut validator = DaemonProgLoadValidator::new(...);
let output = bpfopt::optimize_with_validator(input, &mut validator)?;

let linked = daemon::linker::bind_kinsns(
    output.bytecode,
    &output.link_requirements,
    &runtime_discovery,
)?;

bpf::bpf_prog_rejit(prog_fd, &linked.insns, &linked.fd_array)?;
daemon::invalidation::update(prog_id, &output.specialization_dependencies)?;
```

### C.6 `map_inline` 的改造点

这是唯一必须深改的 pass。

当前问题：

1. `MapInlinePass` 直接调用 `crate::bpf::bpf_map_get_info_by_id()`
2. 直接调用 `bpf_map_lookup_elem_by_id()`
3. 用 `map_ids/map_fd_bindings` 这种 live-kernel 语义

改造后：

1. `map_info` analysis 不再做 I/O，只在 `ProgramMetadata.map_bindings + MapValueSet.maps` 上解析。
2. `MapInlinePass` 只从 `MapValueSet` 读 metadata 和 entry snapshot。
3. 输出 `SpecializationDependency::MapValueEquals`，而不是 daemon 私有的 `MapInlineRecord`。

### C.7 `required_btf_fds` 的替换

当前 `BpfProgram.required_btf_fds` 必须从 core IR 删除。

替换方案：

1. pass 在 rewrite 时只登记 `KinsnRequirement { pc, symbol, encoding }`
2. output sidecar 里记录这些 requirements
3. daemon / libbpf 在最后一步绑定

这样 `bpfopt` 产物是“可链接 bytecode”，而不是“已经绑好某次 runtime BTF 的 bytecode”。

## D. Profile / verifier / map values 格式设计

### D.1 共通原则

三类文档都遵守：

1. 顶层带 `schema` 和 `version`
2. 带 `program.bytecode_sha256`
3. 所有字节串用小写 hex
4. 不绑定采集来源，只记录 `producer` / `notes` / `source`
5. 缺数据和“明确为 null”必须区分

### D.2 PGO profile JSON schema

建议 schema：

```json
{
  "schema": "bpfopt/v1/pgo-profile",
  "version": 1,
  "producer": "perf-lbr|pmu|offline-tool",
  "program": {
    "bytecode_sha256": "...",
    "name": "optional",
    "tag": "optional"
  },
  "window_ms": 250,
  "program_summary": {
    "branch_miss_rate": 0.031,
    "branch_instructions": 123456,
    "branch_misses": 3827
  },
  "branch_sites": [
    {
      "pc": 42,
      "taken_count": 10000,
      "not_taken_count": 2500,
      "confidence": 0.98,
      "source": "lbr"
    }
  ]
}
```

字段语义：

1. `branch_miss_rate`
   程序级 miss rate，供 `branch_flip` gating
2. `branch_sites[*].taken_count/not_taken_count`
   site 级 taken bias，供 `branch_flip` 选择是否 flip
3. `confidence`
   可选；留给采样型 profile
4. `source`
   可选；不参与优化语义，只做 explainability

必须允许：

1. 只有程序级 miss rate，没有 per-site branch counts
2. 只有 per-site counts，没有程序级 miss rate
3. 两者都有

### D.3 Verifier states JSON schema

建议直接承接当前 `VerifierInsn` / `RegState` / `StackState`，但格式化为独立 JSON，而不是 kernel log text。

```json
{
  "schema": "bpfopt/v1/verifier-states",
  "version": 1,
  "producer": "kernel-log-parser|abstract-interpreter",
  "program": {
    "bytecode_sha256": "..."
  },
  "states": [
    {
      "pc": 88,
      "frame": 0,
      "from_pc": 77,
      "kind": "insn_delta",
      "speculative": false,
      "regs": {
        "r2": {
          "reg_type": "fp",
          "value_width": "unknown",
          "precise": true,
          "exact_value": null,
          "tnum": null,
          "range": {},
          "offset": -8,
          "id": null
        }
      },
      "stack": {
        "-8": {
          "slot_types": "mmmmmmmm",
          "value": {
            "reg_type": "scalar",
            "value_width": "bits64",
            "precise": true,
            "exact_value": 42,
            "tnum": { "value": 42, "mask": 0 },
            "range": {
              "umin": 42,
              "umax": 42
            },
            "offset": null,
            "id": null
          }
        }
      }
    }
  ]
}
```

设计点：

1. `kind` 保留 `edge_full` / `pc_full` / `insn_delta`
2. `regs` / `stack` 用字符串 key，避免 JSON 数字键歧义
3. `range` 允许稀疏字段
4. producer 可以不是 kernel verifier；只要语义兼容即可

这让 `const_prop` 和 `map_inline` 既能吃当前 kernel verifier log，也能吃未来离线 abstract interpreter 的输出。

### D.4 Map values JSON schema

`map_values` 不能只放 value snapshot，必须同时放 map metadata，因为当前 `map_inline` 还依赖：

1. `map_type`
2. `key_size`
3. `value_size`
4. `max_entries`
5. `frozen`
6. `supports_direct_value_access`

建议 schema：

```json
{
  "schema": "bpfopt/v1/map-values",
  "version": 1,
  "producer": "daemon-snapshot|object-loader|test-fixture",
  "program": {
    "bytecode_sha256": "..."
  },
  "maps": [
    {
      "logical_map_id": "kernel-map-id:123",
      "map_type": "array",
      "key_size": 4,
      "value_size": 8,
      "max_entries": 1024,
      "frozen": false,
      "supports_direct_value_access": true,
      "entries": [
        { "key_hex": "01000000", "value": { "kind": "bytes", "hex": "2a00000000000000" } },
        { "key_hex": "02000000", "value": null }
      ]
    }
  ]
}
```

解释：

1. `logical_map_id`
   必须和 `ProgramMetadata.map_bindings[*].logical_map_id` 对齐
2. `value: null`
   表示“明确知道 lookup miss”
3. key 不出现
   表示“没有采到这个 key”，对 optimizer 来说是 unknown，不是 miss

为兼容 percpu map，可允许：

```json
{ "kind": "per_cpu_bytes", "slots_hex": ["...", "..."] }
```

但 `bpfopt` 只在 pass 需要时解释；核心 schema 不绑定具体采集方式。

## E. Platform / target description

### E.1 总体思路

`bpfopt` 不做 `PlatformCapabilities::detect()`；host detection 不得出现在核心库里。

改为：

1. target 是显式输入
2. 类似 LLVM `-march` / `-mattr`
3. kinsn availability 也是 target manifest 的一部分

### E.2 CLI 形态

建议：

```bash
bpfopt optimize --march x86_64-v3 --mattr +cmov,+movbe,+bmi2,+rorx ...
bpfopt optimize --target target.json ...
```

规则：

1. `--target target.json` 优先级最高
2. `--march/--mattr` 是 CLI convenience，内部仍转成 `TargetDesc`

### E.3 target JSON

建议 schema：

```json
{
  "schema": "bpfopt/v1/target",
  "version": 1,
  "platform": {
    "arch": "x86_64",
    "march": "x86_64-v3",
    "cpu": "generic",
    "features": ["cmov", "movbe", "bmi1", "bmi2", "rorx"]
  },
  "kinsns": {
    "bpf_rotate64": {
      "available": true,
      "encodings": ["packed_call"],
      "binding": {
        "symbol": "bpf_rotate64",
        "btf_func_id": 12345
      }
    },
    "bpf_select64": {
      "available": true,
      "encodings": ["packed_call"]
    }
  }
}
```

### E.4 kinsn 描述方式

核心要求：不依赖运行时 BTF 发现。

因此 `bpfopt` 只认三层语义：

1. `available`
   这个 kinsn 语义是否可用
2. `encodings`
   支持哪种调用编码，当前就是 `packed_call`
3. `binding`
   可选。若存在，表示 caller 已经知道如何把这个语义绑定到具体 load-time / REJIT-time 目标

这允许三种 embedding：

1. daemon
   启动时做 runtime discovery，然后把结果序列化成 manifest 传给 `bpfopt`
2. libbpf
   在 load-time 通过已有 BTF / BPF object 信息生成 manifest
3. 离线分析
   只关心 candidate / 结构化报告，不提供 binding

### E.5 pass 与 target 的关系

按 §3 分类，可以把当前 pass 分成三类：

1. 纯 bytecode pass
   `map_inline`
   `const_prop`
   `dce`
   `skb_load_bytes_spec`
   `bounds_check_merge`
   `wide_mem`
   `branch_flip`
2. target-aware kinsn pass
   `rotate`
   `cond_select`
   `extract`
   `endian_fusion`
   `bulk_memory`
3. future / disabled
   安全 pass 与非 OSDI pass 继续保留在 registry 里但 `default_enabled=false`

`list_passes()` 应把这种依赖显式列出来，而不是藏在实现里。

## F. daemon 瘦身后的架构

### F.1 daemon 最终只剩什么

瘦身后 daemon 只保留四类职责：

1. kernel program snapshot
   - enumerate live programs
   - 取 original bytecode
   - 取 map IDs / map FDs / attach metadata
2. runtime binding
   - kinsn discovery
   - map FD relocation
   - `BPF_PROG_LOAD` dry-run verify
   - `BPF_PROG_REJIT`
3. specialization lifecycle
   - invalidation tracking
   - reoptimize trigger
4. 服务化封装
   - socket server
   - request parsing
   - structured response

明确不再属于 daemon：

1. runtime profiling 采集
2. hotness ranking
3. profile session thread
4. PMU 读取

这些应改到独立工具，例如 `bpfopt-profcollect`。

### F.2 daemon 内部模块建议

建议 daemon 保留/新增：

1. `main.rs`
2. `server.rs`
3. `commands.rs`
4. `bpf.rs`
5. `kfunc_discovery.rs`
6. `invalidation.rs`
7. `target_manifest.rs`
8. `side_input_collectors.rs`
9. `validator.rs`
10. `linker.rs`

`profiler.rs` 删除出 daemon。

### F.3 optimize 请求流程

瘦身后 `optimize` 的请求路径：

```text
request
  -> snapshot live prog
  -> build ProgramMetadata
  -> load external PGO / verifier / map-value inputs
  -> build TargetDesc + KinsnCatalog
  -> bpfopt::optimize_with_validator()
  -> link unresolved kinsn requirements
  -> final BPF_PROG_REJIT
  -> install specialization dependencies into invalidation tracker
  -> response
```

其中：

1. `validator` 实现 §4.6 的 per-pass `BPF_PROG_LOAD dry-run`
2. 通过 validator 返回的新 `verifier_states` 继续驱动后续 pass
3. 最终只做一次 `BPF_PROG_REJIT` 原子 swap，保持现有约束不变

### F.4 daemon 如何调 `bpfopt`

最重要的边界是：

1. daemon 给 `bpfopt` 的是“快照”，不是“内核句柄”
2. `bpfopt` 返回的是“优化结果 + 绑定需求 + specialization 依赖”，不是“直接可 REJIT 的最终系统调用 attr”

因此 daemon 不再知道 pass 内部细节：

1. 不再构建 `PassManager`
2. 不再直接解析 `PassResult`
3. 不再自己维护 `required_btf_fds`

daemon 只消费：

1. `TransformReport`
2. `KinsnRequirement`
3. `SpecializationDependency`

### F.5 map invalidation 与 re-optimize

`map_inline` 与 invalidation 的接口要改成纯数据：

1. `bpfopt` 输出：
   `MapValueEquals { logical_map_id, key, expected_value }`
2. daemon 把 `logical_map_id` 映射回 live kernel map FD / map ID
3. `MapInvalidationTracker` 继续只做“比较当前值和 expected_value 是否相等”
4. 一旦不相等：
   - 删除旧 tracking entry
   - 重新抓原始 bytecode
   - 重新抓 map snapshot
   - 重新调 `bpfopt`
   - 重新 REJIT

关键点：

1. re-optimize 必须始终从 original bytecode 出发，不从上一版 optimized bytecode 增量修改
2. `bpfopt` 不维护任何 daemon session 状态
3. invalidation watch 完全留在 daemon

### F.6 optimize-all / profile 的新边界

因为 profiling 不再在 daemon 内部：

1. `optimize-all` 不再自行做 hotness ranking
2. runner 要么显式传 program list / 排序
3. 要么传一个标准化 profile snapshot，daemon 只把它转发给 `bpfopt`

也就是说，daemon 的 `optimize-all` 最多是：

1. 枚举
2. 按外部给定顺序调用 `optimize`

而不是：

1. 自己开 profiler session
2. 自己读 PMU
3. 自己决定 hotness

### F.7 与 §4.6 约束的关系

瘦身后仍应保留的 daemon 约束：

1. session 级启动一次
2. crash 即 fail，不自动重启
3. per-pass verify 继续用 `BPF_PROG_LOAD dry-run`
4. 最终只做一次 REJIT
5. 结构化 per-pass 记录继续保留

这些约束属于 embedding driver，而不是 optimizer core。

## 结论

最终架构应是两层：

1. `bpfopt`
   纯 bytecode optimizer，输入显式 side-input，输出 bytecode + report + symbolic requirements
2. `daemon`
   纯 kernel-facing driver，负责 snapshot、validator、binding、REJIT、invalidation

这样可以同时满足三个目标：

1. 把当前 daemon 里最复杂的 pass / analysis / verifier-guided 逻辑独立出来
2. 让 daemon 变薄，严格只保留 kernel 交互和生命周期管理
3. 给未来 libbpf load-time 静态优化留出稳定的库 API 和 C FFI 面
