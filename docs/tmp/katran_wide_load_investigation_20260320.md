# Katran Wide Load Investigation (2026-03-20)

## TL;DR

- 当前 `balancer_ingress` 的 `wide` 覆盖之所以只有 `4`，主因不是 scanner 只支持 `2-byte`，也不是 verifier fixup 把 pattern 改坏了。
- 在当前 tree / 当前 bzImage / 当前 Katran object 上，我实际复现到的 live census 是：
  - `branch-flip = 56`
  - `cmov = 8`
  - `wide = 4`
  - `endian = 4`
  - `extract = 2`
  - `rotate = 0`
  - `lea = 0`
  - total `74`
- `micro_exec --compile-only` 导出的 raw xlated、`bpftool prog dump xlated` 的 live 程序、以及 `scanner scan --xlated` 的结果完全一致。说明：
  - 这不是 live-only drift
  - 这不是 verifier fixup 导致 object/live wide 形状分叉
- 当前 `4` 个 `wide-load-2` 全都来自 `handle_icmp.h:46` 的 `memcpy(tmp_mac, eth->h_source, ETH_ALEN)`，也就是 `swap_mac_and_send()` 内部的 MAC 拷贝逻辑，重复出现两次。
- Katran 主路径的大量 header parse 主要是：
  - 直接 `LDXH` / `LDXW`
  - `LDXW + be32` / `LDXH + be16`
  - 单字节 field load
  - byte-to-byte `memcpy`
  而不是 current WIDE_MEM 定义里的 linear byte ladder。
- 我确实找到了额外的 byte-recompose 形状，但它们是 **scanner + kernel validator 的共同 gap**，不是 scanner-only gap：
  - `125` / `271`: 4-byte little-endian tree recompose
  - `1099` / `1881`: 4-byte big-endian tree recompose
  - `1092` / second inlined copy: 3-byte big-endian recompose with shared tail jump
- 在“不改内核代码”的约束下，当前 wide coverage 基本不能通过 scanner-only patch 真正扩展。
- 如果未来同时扩 scanner 和 kernel validator，当前 binary 上比较可信的 wide census 是：
  - `4 -> 6`
  - 新增的是 QUIC CID v3 的两个 `wide-load-4-be`
  - 现有 `125` / `271` 更可能从 `wide-load-2` 升格为 `wide-load-4`，但 start site 数不会增加

## VM Repro

### Environment

- host repo: `/home/yunwei37/workspace/bpf-benchmark`
- guest kernel: `vendor/linux-framework/arch/x86/boot/bzImage`
- venv: `/home/yunwei37/workspace/.venv/bin/activate`

### Commands / flow actually run in guest

1. `bash e2e/cases/katran/setup.sh`
2. compile-only load:

```bash
runner/build/micro_exec run-kernel \
  --program corpus/build/katran/balancer.bpf.o \
  --program-name balancer_ingress \
  --io-mode packet \
  --compile-only \
  --dump-xlated docs/tmp/katran_wide_load_vm_20260320/balancer_ingress.compile_only.xlated.bin
```

3. live topology bring-up and attach via the existing Katran e2e helpers:
   - `KatranDsrTopology("eth0", router_peer_iface="eth1")`
   - `NamespaceHttpServer(...)`
   - `KatranDirectSession(..., attach=True, bpftool=...)`
4. live dump:

```bash
bpftool prog dump xlated id 13 linum
scanner/build/bpf-jit-scanner enumerate --prog-id 13 --all --json
scanner/build/bpf-jit-scanner scan --xlated docs/tmp/katran_wide_load_vm_20260320/balancer_ingress.compile_only.xlated.bin --program-name balancer_ingress --all --json
```

### Artifacts

- raw artifact dir: `docs/tmp/katran_wide_load_vm_20260320/`
- compile-only xlated bin:
  - `docs/tmp/katran_wide_load_vm_20260320/balancer_ingress.compile_only.xlated.bin`
- live bpftool xlated dump:
  - `docs/tmp/katran_wide_load_vm_20260320/bpftool.prog_dump_xlated.txt`
- live enumerate JSON:
  - `docs/tmp/katran_wide_load_vm_20260320/scanner.enumerate.stdout.json`
- offline xlated scan JSON:
  - `docs/tmp/katran_wide_load_vm_20260320/scanner.xlated_scan.stdout.json`
- object scan JSON:
  - `docs/tmp/katran_wide_load_vm_20260320/scanner.object_scan.stdout.json`

### Guest run facts

- live `prog_id = 13`
- `bytes_xlated = 23872` -> `2984` BPF insns
- `bytes_jited = 13412`
- compile-only xlated scan and live enumerate are identical:
  - `live_count = 74`
  - `xlated_count = 74`
  - `identical = True`

## Live Site Census

### Per-family counts

| Family | Sites |
| --- | ---: |
| `branch-flip` | `56` |
| `cmov` | `8` |
| `wide` | `4` |
| `endian` | `4` |
| `extract` | `2` |
| `rotate` | `0` |
| `lea` | `0` |
| total | `74` |

### Per-family offsets

- `wide`
  - `120 wide-load-2`
  - `125 wide-load-2`
  - `266 wide-load-2`
  - `271 wide-load-2`
- `endian`
  - `381 endian-load-swap-32`
  - `734 endian-load-swap-32`
  - `1702 endian-swap-store-16`
  - `2564 endian-swap-store-16`
- `extract`
  - `1554 bitfield-extract-64-mask-shift`
  - `2429 bitfield-extract-64-mask-shift`
- `cmov`
  - `422 cond-select-64`
  - `778 cond-select-64`
  - `989 cond-select-64`
  - `1030 cond-select-64`
  - `1418 cond-select-64`
  - `1464 cond-select-64`
  - `1600 cond-select-64`
  - `2288 cond-select-64`
- `branch-flip`
  - `15, 370, 481, 567, 614, 644, 676, 723, 874, 922, 952, 979, 1019, 1131, 1179, 1200, 1243, 1270, 1284, 1307, 1408, 1440, 1495, 1512, 1528, 1543, 1582, 1618, 1739, 1763, 1779, 1810, 1862, 1909, 1953, 1980, 1996, 2048, 2068, 2110, 2136, 2150, 2172, 2278, 2307, 2362, 2379, 2399, 2414, 2457, 2480, 2606, 2626, 2643, 2691, 2734`

## Byte-load Inventory

## Raw opcode counts

- `LDXB (0x71) = 152`
- `LDXH (0x69) = 59`
- `LDXW (0x61) = 169`
- `LDXDW (0x79) = 231`
- `LSH64K (0x67) = 127`
- `OR64X (0x4f) = 54`
- `BE endian (0xdc) = 9`

### What the byte loads are mostly doing

Top `LDXB` contexts in the actual xlated dump:

- `12x` `handle_icmp.h:46` `memcpy(tmp_mac, eth->h_source, ETH_ALEN);`
- `12x` `handle_icmp.h:47` `memcpy(eth->h_source, eth->h_dest, ETH_ALEN);`
- `12x` `pckt_encap.h:69` `memcpy(new_eth->h_dest, cval->mac, 6);`
- `12x` `pckt_encap.h:70` `memcpy(new_eth->h_source, old_eth->h_dest, 6);`
- `12x` `pckt_encap.h:113` `memcpy(new_eth->h_dest, cval->mac, 6);`
- `12x` `pckt_encap.h:114` `memcpy(new_eth->h_source, old_eth->h_dest, 6);`
- `8x` `pckt_parsing.h:413` QUIC CID v3 server_id recompose
- `6x` `pckt_parsing.h:409` QUIC CID v2 server_id recompose
- `4x` `pckt_parsing.h:406` QUIC CID v1 bit extraction / compose

Top `LDXH` contexts:

- `18x` `csum_helpers.h:56` checksum fold loop over IPv4 header words
- direct port / frag / mtu loads dominate the rest

Top `LDXW` contexts:

- IPv6 addr `memcpy` and `bpf_map_lookup_elem` bookkeeping dominate
- main packet parsing frequently uses direct `u32` loads, not byte recomposition

### Immediate implication

Katran 确实有不少 byte loads，但大部分属于这四类：

1. 单字节 field access
2. byte-to-byte `memcpy`
3. QUIC 自定义 bit packing / server_id 组装
4. 少量真正 linear byte-ladder

只有第 4 类落在 current WIDE_MEM 的 target set 里。

## Why Only 4 Wide Sites

## 1. It is not a width-limit problem

`scanner/src/pattern_v5.cpp` 的 `build_v5_wide_descriptors()` 已经支持：

- width `2..8`
- little-endian low-first ladder
- big-endian high-first ladder

所以问题不是 “scanner 只找 `2-byte`”。

## 2. It is not a verifier-fixup problem

我拿到了三份 source-of-truth：

- compile-only raw xlated
- live `bpftool prog dump xlated`
- `scanner enumerate --prog-id`

在当前 run 上：

- `scan --xlated compile_only.bin` = `74` sites
- live enumerate = `74` sites
- site list 完全一致

所以不是 verifier 把 object 里的 wider byte-ladder 改坏了。

## 3. Main header parsing is already in H/W loads, not byte ladders

这是最关键的真实原因。

从 `bpftool` dump 可以直接看到：

- IPv4 total length:
  - `LDXH` + `be16`
- IPv6 MTU:
  - `LDXW` + `be32`
- IPv4 src/dst:
  - `LDXW`
- IPv6 addr copies:
  - `LDXW` / `LDXDW`

也就是说，Katran 的 “大量 header parse” 并没有在当前 xlated 里落成大量 byte-recompose ladder。clang/LLVM/libbpf/verifier 这条链已经把相当一部分字段读取降成了直接 `16/32-bit` load。

这也是为什么：

- `endian = 4`
- `wide = 4`

而不是“wide 非常多”。

## 4. The 4 matched wide sites are all from one cold-ish helper

当前 `4` 个 matched wide sites 全都来自：

- source: `katran/lib/bpf/handle_icmp.h:46`
- function: `swap_mac_and_send()`
- statement: `memcpy(tmp_mac, eth->h_source, ETH_ALEN);`

实际 xlated 形状：

```text
120: ldxb r1, [r9+11]
121: lsh  r1, 8
122: ldxb r2, [r9+10]
123: or   r1, r2
124: stxh [stack-4], r1

125: ldxb r1, [r9+7]
126: lsh  r1, 8
127: ldxb r2, [r9+6]
128: or   r1, r2
...
```

同样的 helper 在另一条 ICMP reply 路径又内联了一次，所以出现：

- `120`
- `125`
- `266`
- `271`

这解释了两个现象：

- wide 站点数很少
- wide 站点并不在主 LB fast path 的核心 parse / lookup / encap 热路径里

## Scanner vs Katran Shape

## Current scanner / kernel WIDE_MEM contract

userspace scanner 和 kernel validator 对 WIDE_MEM 的假设是同一套：

- 只接受 straight-line site
- site 长度必须是 `3 * width - 2`
- 必须是 linear ladder
- final accumulator 必须就是 site 第一条 `LDXB` 的 `dst_reg`

scanner 证据：

- `scanner/src/pattern_v5.cpp`
  - `build_v5_wide_descriptors()`
  - 只描述 linear low-first / high-first ladder
  - 扫描是 first-match + `idx += pattern.size()`

kernel 证据：

- `vendor/linux-framework/kernel/bpf/jit_validators.c`
  - `bpf_jit_validate_wide_mem_rule()`
  - `shape->dst_reg = first->dst_reg`
  - `rule->site_len == 3 * count - 2`
  - head/body matcher 只支持 linear chunk sequence

结论：

- 如果某个 Katran pattern 不是这套 linear canonical form，scanner 现在看不到
- 就算 scanner 看到了，kernel validator 现在也不一定会 accept

## Matched shape: current 4 sites

### `120` / `266`

这是标准 `wide-load-2` little-endian ladder：

```text
ldxb byte_hi
lsh 8
ldxb byte_lo
or
```

### `125` / `271`

scanner 现在也只把它们识别成 `wide-load-2`，但实际上它们后面接着更大的 4-byte tree：

```text
125: ldxb r1, [base+7]
126: lsh  r1, 8
127: ldxb r2, [base+6]
128: or   r1, r2
129: ldxb r2, [base+8]
130: lsh  r2, 16
131: ldxb r3, [base+9]
132: lsh  r3, 24
133: or   r3, r2
134: or   r3, r1
135: stw  [stack-8], r3
```

这说明：

- scanner 命中了其中的低 16-bit sub-ladder
- 但没有命中完整的 4-byte tree recompose

## Unmatched but semantically valid wide-load candidates

### Candidate A: LE 4-byte tree in MAC memcpy

Sites:

- `125`
- `271`

Source:

- `handle_icmp.h:46`
- `memcpy(tmp_mac, eth->h_source, ETH_ALEN);`

Why current scanner misses it:

- offset 虽然对应连续字节 `6..9`
- 但访问顺序是 `7, 6, 8, 9`
- final accumulator 是 `r3`
- 第一条 load 的 dst 是 `r1`

所以它违反了 current WIDE_MEM 的两个核心假设：

1. linear monotonic accumulator ladder
2. final `dst_reg == first load dst_reg`

Actionability:

- 这是一个真实的 WIDE candidate
- 但 scanner-only patch 不够
- kernel validator 也必须改

Expected coverage impact if scanner+kernel both learn this shape:

- `125` / `271` 会更像 `wide-load-4`
- 但 start site 还是 `125` / `271`
- 所以 **不会把 wide site count 从 `4` 继续加 `2`**
- 它只会把两个现有 start site 的 form 从 `2-byte` 升格到 `4-byte`

### Candidate B: BE 4-byte tree in QUIC CID v3 parse

Sites:

- `1099`
- `1881`

Source:

- `pckt_parsing.h:413`
- `(connId[1] << 24) | (connId[2] << 16) | (connId[3] << 8) | (connId[4])`

Actual xlated:

```text
1099: ldxb r2, [r9+1]
1100: lsh  r2, 24
1101: ldxb r3, [r9+2]
1102: lsh  r3, 16
1103: or   r3, r2
1104: ldxb r2, [r9+3]
1105: lsh  r2, 8
1106: or   r3, r2
1107: ldxb r2, [r9+4]
1108: or   r3, r2
1109: lsh  r3, 32
1110: arsh r3, 32
```

Semantics:

- 这在 `1108` 时已经是一个完整的 `wide-load-4-be`
- 后面的 `<<32` / `s>>32` 只是 32-bit sign/width normalization

Why current scanner misses it:

- 这仍然不是 scanner 现有的 big-endian linear descriptor
- 第一条 byte load 放进了 temp `r2`
- final accumulator 是第二条 load 的 dst `r3`

Why scanner-only still would not be enough:

- current kernel validator 同样要求 `shape->dst_reg = first->dst_reg`
- 所以即便 userspace scanner 加 descriptor，kernel 也会 reject

Coverage impact if scanner+kernel both learn this shape:

- 这是两个新的 non-overlapping start sites
- 因此 wide census 可以从 `4 -> 6`

## Unmatched but not scanner-only WIDE candidates

### Candidate C: QUIC CID v2 3-byte compose with shared tail

Source:

- `pckt_parsing.h:409`
- `result.server_id = (connId[1] << 16) | (connId[2] << 8) | (connId[3]);`

The emitted code shares the final OR/join tail with the v3 path through an unconditional jump:

```text
1092: ldxb r2, [r9+1]
1093: lsh  r2, 16
1094: ldxb r3, [r9+2]
1095: lsh  r3, 8
1096: or   r3, r2
1097: ldxb r2, [r9+3]
1098: ja   shared_tail
...
1108: or   r3, r2
```

This is not a simple descriptor gap. It would require:

- CFG-aware matching
- validator-side shared-tail acceptance

所以它不是 “加一个 scanner linear pattern descriptor” 就能拿到的站点。

### Candidate D: byte-to-byte MAC copies in encap path

Sources:

- `pckt_encap.h:69`
- `pckt_encap.h:70`
- `pckt_encap.h:113`
- `pckt_encap.h:114`

These are lots of `LDXB` + `STXB`, but **not** scalar recompose:

- no shift
- no OR ladder
- semantically this is a block copy, not a wide scalar load

So they are not current WIDE_MEM candidates at all.

## Answering the Original Hypotheses

### Is scanner only matching contiguous offsets?

Partly, but not in the naive sense.

- current WIDE_MEM requires byte offsets to normalize to a contiguous range
- but it also requires a linear accumulator ladder

So:

- `125` / `271` use contiguous bytes, but the order is tree-shaped and non-monotonic
- `1099` / `1881` use contiguous monotonic bytes, but the accumulator register shape is different

### Is scanner only matching byte loads, while Katran uses 16-bit compose?

WIDE_MEM itself is byte-load based, yes.

And in Katran, the main reason wide count is low is exactly that:

- a lot of parsing is already `LDXH` / `LDXW`
- those sites belong to plain scalar load or `ENDIAN_FUSION`, not WIDE_MEM

### Is scanner only matching 2-byte sites?

No.

- scanner descriptors support `2..8`
- kernel emitter also supports `2..8`

Current Katran only lands on `2-byte` matched shapes because the only matched linear ladders happen to be the two 16-bit subpieces in MAC copy logic.

### Did verifier fixup change the pattern?

No.

Current evidence is the opposite:

- compile-only xlated scan == live enumerate

## Why Earlier “object scan only saw 18 sites” Was Not Reproduced

我没有复现旧文档里那个 `18-site` object-only 结果。

在当前 tree 上：

- `scanner scan corpus/build/katran/balancer.bpf.o --program-name balancer_ingress --all --json`
- `scanner scan --xlated ...compile_only.xlated.bin --all --json`
- `scanner enumerate --prog-id 13 --all --json`

三者 wide / endian / cmov / extract / branch-flip census 一致，都是 `74`。

最可能的解释是：

- 旧报告使用的是更早的 scanner/object path 行为
- 或者当时 object path 没成功 load / 没拿到 kernel xlated，只退回了别的输入层级

但在 **2026-03-20 当前树** 上，我的实际结果是 `74`，不是 `18`。

## Practical Recommendation

## Short term, without kernel changes

不要把当前问题理解成 “scanner 漏了大量 Katran wide site，可以只改 scanner 补回来”。

更准确的表述是：

- current wide count low，主要是因为 Katran 当前 xlated 本来就不怎么长成 linear WIDE_MEM
- 剩下那些看起来像 wide 的额外模式，已经超出了当前 kernel validator contract

因此在“不改内核代码”的约束下：

- **wide coverage 维持 `4` 是合理预期**
- 想提升 Katran 覆盖，优先还是看 `branch-flip` / `endian` / `cmov` / `extract`

## If future work allows scanner + kernel changes

建议按这个顺序推进：

1. add a straight-line tree `wide-load-4-be` form for QUIC CID v3
   - sites: `1099`, `1881`
   - expected site-count delta: `+2`
2. add a straight-line tree `wide-load-4` form for the MAC memcpy low-4-byte pack
   - sites: `125`, `271`
   - expected site-count delta: `0`
   - expected pattern-kind upgrade: `wide-load-2 -> wide-load-4`
3. only if worth the complexity, consider CFG-aware shared-tail WIDE for QUIC CID v2
   - heavier validator work
4. if the real target is the many `memcpy(..., 6)` MAC copies in encap/decap, this is probably **not** a WIDE_MEM extension
   - it wants a separate byte-copy / small-memcpy canonical form

## Suggested descriptor shapes if kernel contract is widened

### LE 4-byte tree

```text
ldxb a, [base+1]
lsh  a, 8
ldxb b, [base+0]
or   a, b
ldxb b, [base+2]
lsh  b, 16
ldxb dst, [base+3]
lsh  dst, 24
or   dst, b
or   dst, a
```

Canonical meaning:

- `dst = *(u32 *)(base + 0)` in little-endian byte order

### BE 4-byte tree

```text
ldxb a,   [base+0]
lsh  a,   24
ldxb dst, [base+1]
lsh  dst, 16
or   dst, a
ldxb a,   [base+2]
lsh  a,   8
or   dst, a
ldxb a,   [base+3]
or   dst, a
```

Canonical meaning:

- `dst = be32_load(base + 0)`

## Bottom Line

当前 Katran `balancer_ingress` wide-load 只有 `4` 个，真实原因是：

1. 主 datapath 解析主要已经是 `LDXH/LDXW` / `ENDIAN`
2. current WIDE_MEM contract 只接受 linear ladder
3. Katran 剩下那些像 wide 的 byte-recompose，多数是 tree shape、shared-tail shape、或者根本只是 byte-copy

所以这不是一个简单的 “scanner 少配几个 descriptor” 问题。

在当前“不改内核”的约束下，我不建议直接改 scanner 代码去追这些额外 wide site，因为 userspace detect 到了也过不了现有 kernel validator。
