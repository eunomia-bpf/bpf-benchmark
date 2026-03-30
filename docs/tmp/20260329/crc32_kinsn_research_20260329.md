# CRC32 硬件指令在 BPF 程序中的优化价值调研

日期：2026-03-29  
范围：只做仓库内源码与既有研究文档调研，不改代码，不跑 VM

## 结论摘要

- **直接命中面很窄，但在 `loxilb` 的 SCTP CRC32C 路径上，局部收益可能很高。**
- 我扫描了 `runner/repos/` 下 22 个 repo 的 BPF 侧源码后，确认**唯一真实的 CRC32C 软件实现命中**在 `loxilb`：
  - `runner/repos/loxilb/kernel/llb_kern_sum.c` 的 `dp_sctp_csum()`
  - 同一函数里有 **2 个 byte-update site**
  - 当前做法不是普通 C 里的本地查表，而是**每个字节都走一次 `bpf_map_lookup_elem(&crc32c_map, ...)`**
- **x86/ARM64 都适合先做 no-FPU 的 scalar CRC32C kinsn。**
  - x86 用 `crc32b/q`，属于 SSE4.2 指令族，但操作 GPR，不需要 FPU/XMM 上下文切换
  - ARM64 用 `crc32cb/cx`，也是标量指令；真正需要 `may_use_simd()` / PMULL 的是长 buffer 的 4-way path
- **如果目标是“整个 corpus 的通用 pass”，优先级不高。**
  - 真实 direct CRC32C 命中只有 1 个 repo
  - corpus 里更广泛的 checksum 机会其实是 `bpf_csum_diff` / `bpf_l3_csum_replace` / `bpf_l4_csum_replace`
  - `jhash` 也有一定使用，但**语义上不能用 CRC32C 替换**
- **建议的最小实现不是 generic `bpf_crc32(buf, len)`，而是 `CRC32C-only`、`loxilb` 定向、register-to-register 的 `step8`/`step64` kinsn。**
  - 这样不需要先把“bounded read + buffer semantics”塞进 current kinsn proof model

## 1. Corpus Site Count

### 1.1 扫描范围与口径

- 扫描目录：`runner/repos/` 下 22 个 repo
- 只统计 BPF 侧源码/头文件：
  - `*.bpf.c` / `*.ebpf.c` / `*_kern.c` / `*_bpf.c`
  - 路径中包含 `/bpf/`、`/ebpf/`、`/bpf-gpl/`
  - `loxilb/kernel/**` 单独纳入，因为其 BPF 程序放在该目录
- 本节所有数字都是**静态源码 site count**，不是 runtime hotness，也不是 perf 权重
- direct CRC32 统计时过滤了明显的非 BPF 侧噪音；例如 `datadog-agent/pkg/ebpf/testdata/kallsyms.unsupported` 这类 testdata 不计入结论
- `jhash` 统计分成两类理解：
  - “实现定义”行：复制的 `jhash.h`
  - “真实调用点”行：BPF 程序中实际调用 `jhash*()`

### 1.2 Direct CRC32/CRC32C 命中

| Repo | 直接命中 | 说明 |
| --- | --- | --- |
| `loxilb` | **2 个 update site，1 个逻辑热点函数** | `dp_sctp_csum()` 里两段 byte-loop 都做 `idx -> crc32c_map lookup -> xor/shift` |
| `cilium` | 0 | 没有 direct CRC32C 实现，但有注释明确说 eBPF 里“没有好办法”算 SCTP CRC32C，需要额外 kernel support |
| 其他 repo | 0 | 没找到确认无误的 direct CRC32/CRC32C BPF 实现 |

`loxilb` 的关键证据：

- `runner/repos/loxilb/kernel/llb_kern_sum.c:55-140`
  - 函数 `dp_sctp_csum()`
  - `PBUF_STACK_SZ = 16`
  - `DP_MAX_LOOPS_PER_TCALL = 152`
  - 单次 tail-call slice 最多处理 `16 * 152 = 2432` 字节
- 两个 direct update site：
  - `runner/repos/loxilb/kernel/llb_kern_sum.c:83-88`
  - `runner/repos/loxilb/kernel/llb_kern_sum.c:99-102`
- 当前 byte update 形态：
  - `pb = pbuf[i]`
  - `idx = (crc ^ pb) & 0xff`
  - `tbval = get_crc32c_map(idx)`
  - `crc = tbval ^ (crc >> 8)`
- 更关键的是，`get_crc32c_map()` 不是本地数组 load，而是：
  - `runner/repos/loxilb/kernel/llb_kern_sum.c:12-23`
  - `val = bpf_map_lookup_elem(&crc32c_map, &off);`
  - 也就是**每个字节一次 helper lookup**

支撑性基础设施：

- `runner/repos/loxilb/kernel/llb_kern_cdefs.h:578-583`
  - `crc32c_map` 定义，256-entry map
- `runner/repos/loxilb/kernel/loxilb_libdp.c:1084-1100`
  - `llb_setup_crc32c_map()` 用多项式 `0x82f63b78` 填表
- `vendor/linux-framework/include/linux/crc32poly.h:11-12`
  - `CRC32C_POLY_LE = 0x82f63b78`

这说明 `loxilb` 的目标不是 generic CRC32，而是**CRC32C / Castagnoli**。这点非常重要，因为：

- x86 `crc32` 指令实际做的是 **CRC32C**
- ARM64 则同时有 `crc32*` 和 `crc32c*`

`cilium` 的间接证据：

- `runner/repos/cilium/bpf/lib/csum.h:41-50`
- 注释明确说：
  - SCTP 用 CRC32C
  - 在 eBPF 里“there is not a good way to calculate a crc32c checksum”
  - 很可能需要额外 kernel support

这说明虽然当前 corpus 没有第二个 direct software CRC32C loop，但**需求背景是存在的**。

### 1.3 Checksum Helper Census

这部分不是 direct CRC32 命中，但它决定了“广义 checksum 优化”的真正覆盖面。

| Repo | Site Count | 备注 |
| --- | ---: | --- |
| `loxilb` | 45 | `bpf_csum_diff` / `bpf_l3_csum_replace` / `bpf_l4_csum_replace` 都很多 |
| `calico` | 35 | NAT / ICMP / QoS / TCP 头重写路径很多 |
| `katran` | 25 | 基本集中在 `csum_helpers.h` |
| `linux-selftests` | 19 | selftest，不是生产 workload，但能说明上游 idiom 常见 |
| `xdp-examples` | 13 | `nat64` / `synproxy` |
| `xdp-tools` | 2 | 少量 `bpf_csum_diff` |
| **合计** | **139** | 其中排除 `linux-selftests` 后是 **120** |

判断：

- 这 139 个 site 的热点是 **IP/TCP/UDP one's-complement checksum**
- **它们不是 CRC32C**
- 所以 `CRC32C kinsn` 不能直接吃到这块覆盖面
- 如果要做“广覆盖 checksum 优化”，应是另一条 pass family，不是本报告这个 `CRC32C` 方向

### 1.4 Software Hash Census

真实 `jhash` 调用点的代表性统计如下：

| Repo | 真实调用点 | 说明 |
| --- | ---: | --- |
| `katran` | 3 | `balancer.bpf.c` 做包 hash |
| `cilium` | 1 个生产调用点 + 2 个测试调用点 | 生产调用点在 `bpf/lib/hash.h` |
| `linux-selftests` | 12 | 主要是上游测试程序 |

代表性位置：

- `runner/repos/katran/katran/lib/bpf/balancer.bpf.c:25-35`
- `runner/repos/cilium/bpf/lib/hash.h:12-17`

判断：

- corpus 里确实存在软件 hash 代码
- 但这是 **jhash**，不是 CRC32C
- 语义上不能把 `jhash` 自动替换成 CRC32C，否则会改负载均衡/哈希分布行为
- 所以这部分**不能算 CRC32 硬件指令的 direct target**

## 2. 实现方式

### 2.1 ISA 侧：为什么这是一个 no-FPU 机会

已有仓库内研究已经把这个问题定得很清楚：

- `docs/tmp/20260324/simd_kinsn_design_20260324.md:305-312`
  - x86 phase 2 先走 **scalar CRC32 instruction chain**
  - ARM64 phase 2 先走 **scalar CRC32/CRC32C instruction chain**
- `docs/tmp/20260326/simd_fpu_kinsn_deep_research_20260326.md:642-667`
  - x86 `crc32b/w/l/q` 是 GPR/整数指令，不需要 FPU
  - ARM64 `crc32{b,h,w,x}` / `crc32c*` 也是标量指令
  - 真正需要 SIMD/FPU 的是 x86 `PCLMULQDQ` / ARM64 `PMULL`

内核自己的 CRC 实现也说明了同样的工程判断：

- x86：
  - `vendor/linux-framework/lib/crc/x86/crc32.h:31-35`
  - `CRC32C_PCLMUL_BREAKEVEN = 512`
  - `vendor/linux-framework/lib/crc/x86/crc32.h:80-86`
  - 短中 buffer 默认直接发 scalar `crc32` 指令流
- ARM64：
  - `vendor/linux-framework/lib/crc/arm64/crc32.h:7-8`
  - `min_len = 1024`
  - `vendor/linux-framework/lib/crc/arm64/crc32.h:38-55`
  - 只有长 buffer 且 `PMULL + may_use_simd()` 成立时才走 4-way path

因此，**BpfReJIT v1 若做 CRC32C，应该只做 scalar/no-FPU backend**：

- x86：`crc32b` 先落地；后续可加 `crc32q`
- ARM64：`crc32cb` 先落地；后续可加 `crc32cx`
- 不要一上来做 `PCLMUL` / `PMULL`

### 2.2 推荐的 kinsn 形态

最小可行路线我建议分两层：

#### 方案 A：`bpf_crc32c_step8`，优先推荐

语义：

- 输入：`crc_reg`, `byte_reg`
- 输出：`crc_reg = crc32c_step8(crc_reg, byte_reg)`

优点：

- 只做 register-to-register transform，不碰内存语义
- daemon pass 可以只替换现有 byte-loop body
- 不必先把“buffer read semantics”塞进 current kinsn model
- 对 `loxilb` 已经很有价值，因为它能直接消掉**每字节一次 map lookup helper**

缺点：

- 每字节仍是一条 kinsn/native instruction
- 不是理论最优吞吐

#### 方案 B：`bpf_crc32c_step64`，作为第二阶段

语义：

- 输入：`crc_reg`, `data64_reg`
- 输出：`crc_reg = crc32c_step64(crc_reg, data64_reg)`

优点：

- 对 `PBUF_STACK_SZ = 16` 的主循环非常友好
- 每 16-byte chunk 可从 16 次 table/helper update 降到 2 次 native CRC 指令

缺点：

- daemon pass 需要把栈上的 8-byte chunk load 成寄存器
- proof sequence 比 `step8` 更大

#### 不推荐作为第一步：generic `bpf_crc32c(ptr, len)`

原因：

- `docs/tmp/20260324/simd_kinsn_design_20260324.md:316-319` 已点出，若想做真正的 `bpf_crc32*` buffer API，要么：
  1. 扩 verifier model，描述 bounded read + scalar transform
  2. 改成普通 kfunc 语义，再做 inline emit
- 而 current tree 的 kinsn proof model 明确要求：
  - `instantiate_insn()` 必须给出 proof sequence
  - proof sequence **不能有 calls/exits/back-edges**
  - 见 `vendor/linux-framework/kernel/bpf/verifier.c:3669-3788`

所以 generic buffer API 不是“加个 module”那么简单。

### 2.3 在当前仓库里落地要动哪些地方

#### Kernel/module 侧

- 新增 `module/x86/bpf_crc32c.c`
- 新增 `module/arm64/bpf_crc32c.c`
- 更新：
  - `module/x86/Makefile:8-12`
  - `module/arm64/Makefile:8-13`
- 好消息：
  - `module/load_all.sh:11-33` 会自动加载目录里所有 `.ko`
  - 所以 loader 脚本不需要再加硬编码模块名

#### Daemon 侧

- 扩 `KinsnRegistry`
  - 当前只有 `rotate/select/extract/bulk/endian`
  - 见 `daemon/src/pass.rs:473-488`
- 扩 discovery 的 `KNOWN_KINSNS`
  - 见 `daemon/src/kfunc_discovery.rs:21-31`
- 扩 test seed
  - `daemon/src/test_utils.rs:159-175`
- 新增 pass
  - 识别 `crc32c_map` idiom
  - 发出 `sidecar + BPF_PSEUDO_KINSN_CALL`

#### Platform gating

当前 daemon 的 platform capability 里还没有 CRC 特征位：

- `daemon/src/pass.rs:563-623`

只有：

- `has_bmi1`
- `has_bmi2`
- `has_cmov`
- `has_movbe`
- `has_rorx`

所以要新增：

- x86 `has_sse42_crc32` 或等价位
- ARM64 `has_crc32`

同时 module emitter 侧也要做最终 feature gate，不能只信 daemon。

## 3. 预期收益

### 3.1 对 `loxilb` 局部路径的收益判断

这是本调研里最重要的一点：

- `loxilb` 当前不是“每字节几条 ALU + 一次普通数组 load”
- 而是“每字节一次 `bpf_map_lookup_elem` helper + 后续 load/xor/shift”

因此：

- **`step8`** 就已经可能带来非常显著的局部收益
  - 每个字节把 “helper lookup + 取值 + xor/shift” 压成 1 条 native CRC32C 指令
- **`step64`** 则可进一步把 8 个 byte update 压成 1 条 native 指令

对 `PBUF_STACK_SZ = 16` 的主循环，一个很粗糙但方向正确的对比是：

- 当前：16 次 `get_crc32c_map()`，也就是 16 次 helper lookup
- 若做 `step8`：16 条 `crc32b` / `crc32cb`
- 若做 `step64`：2 条 `crc32q` / `crc32cx`

这意味着：

- **在 CRC 这一小段 micro-kernel 内，收益很可能是数量级级别**
- 但**整条 BPF 程序的 end-to-end 提升不会等于这个数量级**
  - 因为前面仍有 `dp_pktbuf_read_wrap()`
  - 还有 tail-call/状态更新/写回路径

### 3.2 对整个 corpus 的收益判断

如果视角从 `loxilb` 放大到整个 corpus，结论就反过来了：

- direct CRC32C 命中只有 1 个 repo
- 大多数 checksum 热点其实是 `bpf_csum_diff` / `l3/l4_csum_replace`
- `jhash` 也不是 direct target

所以：

- **局部收益：高**
- **跨 corpus 平均收益：低**

如果 OSDI evaluation set 不包含 `loxilb` 或几乎没有 SCTP 负载，那么：

- 这个 pass 的总体 benchmark 影响大概率非常小

## 4. 风险

### 4.1 覆盖面风险

- 真实 direct target 只有 `loxilb`
- 很难把它包装成“全 corpus 都值得默认开启”的 pass

### 4.2 语义/多项式风险

- x86 `crc32` 指令只对应 **CRC32C**
- 它不是 generic IEEE CRC32
- 因此名字、文档、payload、pass 语义都必须写成 `CRC32C-only`

### 4.3 Pattern 识别风险

- `loxilb` 的 table 是运行时在 userspace 填进去的 `crc32c_map`
- daemon 如果想做 generic 识别，必须能证明：
  - 这是 256-entry table
  - 它真的是 Castagnoli polynomial table
- 若不想做运行时 map-content 验证，最现实的做法就是：
  - **先做 repo-/idiom-specific pass**
  - 例如显式识别 `loxilb` 这条 `crc32c_map` 形态

### 4.4 kinsn proof model 风险

- current kinsn 不是“只写 native emitter”就结束
- 还要有 verifier-proof-friendly 的 `instantiate_insn()`
- 对 `step8` 还能接受
- 对 generic `buf,len` API 风险明显更高

### 4.5 CPU feature gating 风险

- daemon 目前没有 CRC feature bit
- x86 需要 SSE4.2 / CRC32
- ARM64 需要 `ARM64_HAS_CRC32`
- 如果检测、discovery、JIT gate 其中一个没收紧，结果就会不稳定

### 4.6 测量风险

- 本报告没有跑 VM benchmark
- 所以现在只能做**静态价值判断**
- 没有给出 end-to-end speedup 数字

## 5. 实现复杂度评估

### 5.1 若做 narrow `loxilb + step8` 路线

复杂度：**中等**

原因：

- module 层是常规新增 kinsn family
- daemon 层要扩 registry/discovery/platform flags
- pass 识别可以先只盯 `loxilb` 这条 byte-update idiom
- proof sequence 只需要覆盖单字节 CRC32C step

我认为这是唯一“工程上可控且有真实收益”的 first cut。

### 5.2 若做 `step64` 路线

复杂度：**中等偏高**

相比 `step8` 多出来的主要成本：

- payload 设计更复杂
- pass 要做 8-byte 聚合与 load 编排
- proof sequence 更大

但如果目标就是把 `loxilb` 这条热点打深，`step64` 很值得作为第二阶段。

### 5.3 若做 generic `bpf_crc32c(ptr, len)`

复杂度：**高**

这是因为它开始逼近 current kinsn core/model 的边界，而不是单纯的“再加一个 peephole pass”。

## 6. 最终结论

### 6.1 值不值得做

- **如果问题是“这是不是一个 broad corpus、值得默认进入 pipeline 的新 kinsn pass？”**
  - **结论：不值得优先做。**
- **如果问题是“对 `loxilb` 的 SCTP CRC32C 路径，这是不是一个真实且可能很大的优化点？”**
  - **结论：值得。**

### 6.2 推荐落地顺序

1. 只做 **`CRC32C-only`**，不要叫 generic `CRC32`
2. 先做 **no-FPU scalar backend**
   - x86 `crc32b` / 后续 `crc32q`
   - ARM64 `crc32cb` / 后续 `crc32cx`
3. 第一版只做 **`loxilb` 定向 idiom pass**
4. 第一版优先考虑 **`bpf_crc32c_step8`**
5. 第二版再考虑 **`step64`**
6. 不建议第一版就碰 generic `buf,len` API

### 6.3 一句话判断

> **CRC32 硬件指令在本 corpus 里的价值不是“广”，而是“窄但深”：它对 `loxilb`/SCTP 是一个很像样的局部优化点，但还远称不上通用优先级 pass。**
