# E2E 性能瓶颈调研

日期：2026-03-29

## 范围与输入

本笔记回答 3 个问题：

1. `lkm_seeker_modtree_loop`（14236 insns）在 E2E 里为什么全部 verifier reject。
2. Katran `balancer_ingress` 为什么只改了 19 insns。
3. E2E VM 里 kinsn modules 到底有没有加载。

本次主要读取的输入：

- 最新可用 E2E 结果：
  - `e2e/results/tracee_20260329_081351/details/result.json`
  - `e2e/results/katran_20260329_085002/details/result.json`
  - `e2e/results/tracee_tailcall_fix_20260329_165448/metadata.json`
  - `e2e/results/tracee_tailcall_fix_20260329_165448/details/result.json`
- E2E/VM 路径：
  - `runner/Makefile:78`
  - `runner/Makefile:342`
  - `e2e/case_common.py`
  - `module/load_all.sh:1-34`
- daemon / REJIT 路径：
  - `daemon/src/main.rs:45-73`
  - `daemon/src/kfunc_discovery.rs:312-360`
  - `daemon/src/commands.rs:339-355`
  - `daemon/src/commands.rs:499-544`
  - `daemon/src/commands.rs:626-629`
  - `daemon/src/bpf.rs:1072-1129`
- 内核侧 REJIT 接口：
  - `vendor/linux-framework/kernel/bpf/syscall.c:3605-3606`

## 先给结论

结论排序如下：

1. 当前最实质的 blocker 是 Tracee 的大程序 `lkm_seeker_modtree_loop` 在 per-pass verify-only 阶段全部被 reject，程序没有进入真正的最终 commit 阶段。
2. Katran `balancer_ingress` “只改 19 insns” 不是异常，更像是这份最新 E2E live image 本来就只有 19 个当前 daemon 能合法落地的 site。
3. 现有证据不支持“kinsn modules 没加载”是这轮 E2E 的最大问题。`vm-e2e` 代码路径明确会先执行 `module/load_all.sh`；真正缺的是 E2E 工件没有把 loader / discovery 证据保存下来。

另外一个现实问题是：时间上最新的 Tracee rerun `tracee_tailcall_fix_20260329_165448` 工件本身已损坏，`metadata.json` 为 0 字节，`details/result.json` 被截断在 8 MiB，不能作为强证据源。下面 Tracee 的细节分析以最新“可解析”的 `tracee_20260329_081351` 为主。

## 1. `lkm_seeker_modtree_loop` 14236 insns 全部 verifier reject 的具体原因

### 结果层面的事实

在 `e2e/results/tracee_20260329_081351/details/result.json` 里，这个程序的扫描结果显示：

- 原始指令数是 14236。
- site summary 是 `map_inline=1 const_prop=313 dce=708`。
- 最终 `total_sites_applied` 为 0。
- `verifier_rejections` 为 3。

也就是说，不是“没有可优化点”，而是“有大量候选点，但一到 verifier 校验阶段就过不去”。

更具体地说，这个程序在本轮真正进入 verify 的 3 个 pass 都失败了：

- `map_inline`: 有改动尝试，但 verify reject。
- `const_prop`: 有大量替换尝试，但 verify reject。
- `dce`: 有删除尝试，但 verify reject。

因此 `final_insn_count` 没有下降，程序保持不变。

### reject 的错误签名

同一份结果里能直接抽到下面几类关键字符串：

- `No space left on device (os error 28)`
- `processed 217220 insns (limit 1000000) ...`
- `processed 215461 insns ...`
- `processed 217969 insns ...`
- `initial REJIT failure without verifier log:`
- `BPF_PROG_REJIT: Invalid argument (os error 22)`

这几条要一起看，不能只看 `ENOSPC`：

- `processed 215k~218k insns` 明显还远低于 verifier 的 1,000,000 insn complexity limit。
- 所以这不是普通意义上的 “程序太复杂，直接撞到 complexity 上限”。
- `No space left on device (os error 28)` 更像是“第二次带 verifier log 重试时，16 MiB log buffer 被打满”的症状。
- 真正更靠前的原始失败是 daemon 追加出来的那句：
  - `initial REJIT failure without verifier log: BPF_PROG_REJIT: Invalid argument (os error 22)`

### daemon 代码如何把这个错误包装出来

`daemon/src/bpf.rs:1072-1129` 的逻辑是：

- 先用 `log_level=0` 走一次 `BPF_PROG_REJIT`。
- 失败后再用 16 MiB verifier log buffer、`log_level=2` 重试。
- 如果第二次报的是 `No space left on device`，就把第二次的 `ENOSPC` 和第一次无日志失败一起拼到最终错误串里。

也就是说，这里看到的 `ENOSPC` 是“重试拿日志时的二次症状”，不是最核心的首因。

### 为什么会出现 `EINVAL`

daemon 的 per-pass verify 路径在 `daemon/src/commands.rs:499-544`，它对每个 pass 的候选程序调用的是 `bpf_prog_rejit_verify_only()`。

`daemon/src/bpf.rs:1123-1129` 里，这个 verify-only 路径会带 `BPF_F_REJIT_VERIFY_ONLY` 标志。

而当前源码树里的内核接口 `vendor/linux-framework/kernel/bpf/syscall.c:3605-3606` 写的是：

```c
if (attr->rejit.flags)
    return -EINVAL;
```

这和结果里出现的 `BPF_PROG_REJIT: Invalid argument (os error 22)` 是对得上的。

### 当前最稳的判断

对这个 Tracee 大程序，最稳的说法是：

- “全部 verifier reject” 的具体原因，不是没有 site，也不是直接撞上 1M complexity limit。
- 它卡在 per-pass verify-only REJIT 这一步。
- 首次 verify-only 调用返回了 `EINVAL`。
- 为了拿 log 的第二次重试又把 verifier log buffer 打满，于是表面上又叠加了 `ENOSPC`。
- 最终 3 个会改程序的 pass 全部被标成 verifier reject，程序保持 14236 insns 不变。

### 需要保留的 caveat

这里有一个必须记下来的不一致点：

- 当前源码树里的 `syscall.c` 看起来会把任何 `rejit.flags` 直接打成 `-EINVAL`。
- 但 Katran 的最新 E2E 结果里，若干 pass 的 verify 状态又确实是 `accepted`。

这说明二者至少有一个前提还没完全对齐：

- 可能运行结果用的内核镜像和现在仓库里的 `vendor/linux-framework` 不是完全同一版。
- 也可能某些程序路径和这个大 Tracee 程序的行为不同。

所以我认为：可以把 `EINVAL + ENOSPC` 当作这个 Tracee case 的直接证据；但不要把它过度外推成“所有 verify-only 都必然失效”。

## 2. Katran `balancer_ingress` 为什么只改了 19 insns

这里看的是 `e2e/results/katran_20260329_085002/details/result.json`。

### 结果层面的事实

3 个 paired cycle 的结论完全一致：

- live program 名字都是 `balancer_ingress`。
- kernel info 里的 `bytes_xlated=23840`，约等于 2980 条 BPF insns。
- daemon scan 的 `enumerate_record.insn_count=2542`。
- object listing 里选中的 `balancer_ingress` 程序是 2318 insns。
- site summary 始终是：
  - `map_inline=6`
  - `dce=7`
  - `endian_fusion=2`
  - `wide_mem=4`
  - 合计 `19`
- debug summary 始终是：
  - `total_sites_applied=19`
  - `passes_changed=4`
  - `verifier_rejections=0`
  - `final_insn_count=2523`
  - `insn_delta=-19`

换句话说，这里“19”不是某个奇怪的 cap，而是这份 live image 上实打实扫描出来并成功应用的 site 总数。

### 为什么不是更多

直接原因有 3 个：

1. 最新 E2E 跑到的 live XDP program，并不是大家印象里那个更大的离线/corpus 版本；当前 runtime image 本身就只有这个规模。
2. 当前 daemon 在这份 image 上只命中了 19 个可合法应用的 site。
3. 其他 pass 在这份 image 上要么没有命中，要么命中了但当前实现还不能落地。

结果里能看到两个很具体的“没落地”原因：

- `rotate`:
  - `sites_skipped=1`
  - skip reason 是 `subprog pseudo-calls not yet supported`
- `cond_select`:
  - `sites_skipped=7`
  - skip reason 是 `packed ABI requires register true/false operands`

### 因此怎么解释“只改了 19 insns”

最准确的说法不是“Katran 只优化出 19 条”，而是：

- 这份最新 E2E live `balancer_ingress` 只暴露出 19 个当前实现可安全应用的 site。
- 其中真正减少指令数的是 `dce` 和 `wide_mem`，合计 `-19`。
- `map_inline` 和 `endian_fusion` 虽然改变了程序，但这轮不直接减少总 insn 数。

所以这个 case 的主要问题不是 verifier reject，而是“可优化密度本来就低”。

## 3. kinsn modules 在 E2E VM 里有没有加载

### `case_common.py` 本身不负责加载

`e2e/case_common.py` 主要负责：

- 组织 case 生命周期。
- 调 daemon 做 optimize/apply。
- 收集结果和持久化工件。

它本身没有 `insmod` 或 `load_all.sh` 调用。也就是说，不能指望从 `case_common.py` 里看到 module load 逻辑。

### 真正的加载发生在 `vm-e2e` 外层

`runner/Makefile` 已经把这个路径写死了：

- `runner/Makefile:78`
  - `VM_INIT := $(VENV_ACTIVATE) "$(REPO_ROOT)/module/load_all.sh" &&`
- `runner/Makefile:342`
  - `vm-e2e` 实际在 guest 里执行：
  - `cd "$(REPO_ROOT)" && $(VM_INIT) python3 "$(REPO_ROOT)/e2e/run.py" ...`

所以，如果这轮 E2E 是通过 `make vm-e2e` 跑的，那么 guest 里会先执行 `module/load_all.sh`，然后才进入 `e2e/run.py`。

### `module/load_all.sh` 做了什么

`module/load_all.sh:1-34` 的逻辑很直接：

- 根据架构选 `module/x86` 或 `module/arm64`。
- 对 `.ko` 逐个 `insmod`。
- 跳过 `bpf_barrier`。
- 最后打印：
  - `kinsn modules: ${loaded}/${total} loaded`

因为现在脚本跳过了 `bpf_barrier`，所以当前树上预期更像是 `5/5 loaded`，而不是旧工件里偶尔能看到的 `6/6 loaded`。

### daemon 也会在启动时做 discovery

daemon 并不是“假定模块已在”。它在启动时会主动扫一遍：

- `daemon/src/main.rs:45-73`
  - 先调用 `discover_kinsns()`
  - 再把 discovery registry 放进 `PassContext`
- `daemon/src/kfunc_discovery.rs:312-360`
  - 实际扫描 `/sys/kernel/btf/<module>`
  - 如果模块没加载，会记录：
  - `module '<name>' not loaded (no BTF at /sys/kernel/btf/<module>)`
- `daemon/src/commands.rs:339-355`
  - 真正需要 descriptor BTF fd 的 pass，还会校验 `required_btf_fds` 是否在 registry 里

所以如果 kinsn modules 真的没加载，理论上不应完全“静默”。

### 现有证据支持什么，不支持什么

当前能稳妥说的是：

- 从代码路径看，`vm-e2e` 会先加载 kinsn modules。
- 从 daemon 启动路径看，它也会主动 discovery。
- 但最新 E2E 工件没有保存 `module/load_all.sh` 的 stdout，也没有把 daemon discovery log 作为一等结果字段留出来。

因此，现有证据不足以支持“这轮 E2E 最大问题是 kinsn modules 没加载”。

我更倾向于把它定性为：

- 当前主要问题不是“确认没加载”，而是“没有把加载成功/失败证据固化进 E2E 工件”。

### 如果后面确认真的是 kinsn 没加载，应该怎么修

如果后面发现有人不是通过 `make vm-e2e` 跑，或者存在别的 guest 入口绕过了 `VM_INIT`，最小修法应该是：

1. 所有 E2E guest 入口统一走 `module/load_all.sh && ...`，不要直接裸跑 `python3 e2e/run.py`。
2. 保证 `load_all.sh` 发生在 daemon 启动之前，而不是之后。
3. 把下面几类信息写进 E2E artifact：
   - `module/load_all.sh` stdout/stderr
   - `lsmod` 或 `/sys/module/*` 快照
   - `/sys/kernel/btf/<module>` 是否存在
   - daemon 的 `kinsn discovery` 日志
4. 如果 discovery 结果为空，而当前 case 又依赖 rotate/extract/endian/cond-select/bulk-memory 这类 kinsn pass，直接在 E2E 前置检查里 fail fast，不要等到 benchmark 结果阶段再猜。

## 最后判断：哪个是这轮最大的性能/落地阻塞

如果只按当前证据强弱排序，我会这样排：

1. Tracee 大程序的 per-pass verify-only reject，是最硬的功能性阻塞。
2. Katran live image 只暴露 19 个可优化 site，是收益上限偏低，不是接口故障。
3. kinsn module load 更像“观测缺失”，不是目前最有证据的首因。

因此，本轮最应该优先追的不是“为什么 Katran 只有 19 条”，也不是先假设“VM 没加载 kinsn”，而是：

- 先把 Tracee `lkm_seeker_modtree_loop` 的 verify-only `EINVAL` / log overflow 这条链路彻底钉死。
- 同时把 E2E artifact 的 loader/discovery 证据补齐，避免下轮还要靠代码阅读反推 VM 里到底发生了什么。
