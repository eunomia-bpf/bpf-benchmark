的 map 上（perf_unwind_native 缺页） | native-link |
| 功能修复 | arm64 TBZ/TBNZ 跳转在展开后重定目标（23844aa67）：6e68d71a7（11-21 07:17）做过，3aa496416 换回 5/29 时丢了，跳转落到 helper 调用序列中间（Tetragon pc 等于 x10、Cilium printk 收到空格式串、OTel 跳到 IRQ 栈）。超出 32 KiB 的改成反条件跳过一条 B，再重新布局 | native-link |
| 优化 | map 的 update、delete 在 map 已知时直接调 map 类型自己的内核函数（d9262890c），和 verifier 的 fixup 调 ops->map_update_elem 一样；加载器按 map 类型给出 hashtab.c、arraymap.c、lpm_trie.c 的函数 | native-link、加载器 |
| 优化 | x86 map 名不可知的查找（内层 map 等）按程序自己用到的 hash 形状逐个比 map_type 和取整后的 key 大小，命中走那个形状的内联形式，其余调 helper（56cf40e8e）。Katran 的 per-CPU LRU 表是内层 map，6 个查找由此回到内联形式 | native-link、加载器 |
| 优化 | arm64 按 helper 编号调用的查找（Cilium、Katran 的 helper 都按编号调用）在 x0 的 map 已知时取这个 map 的形式，运行时编号分派里编号 1 的分支也一样（f26e844a9）；之前只有按名字调用的查找（BCC）取到 | native-link |

5/29 本来就有的链接时优化：ARRAY/PERCPU_ARRAY 查找和更新内联、hash 查找直接绑定 __htab_map_lookup_elem、CPU 号内联、x86 尾调用内联。a04e31ae9 去掉了按调用次序对上的数组更新内联（见上面第一条功能修复），数组更新现在直接调 array_map_update_elem。

**helper 的形式**：

| helper | 形式 |
|---|---|
| map 查找 | map 已知：ARRAY、PERCPU_ARRAY 内联；HASH、LRU_HASH、PERCPU_HASH 直接调 __htab_map_lookup_elem 加后处理；其余直接调 map 类型的查找函数。map 不可知：x86 按 map_type 和 key 大小试程序用到的 hash 形状，其余调 helper；arm64 调 helper |
| map 更新 / 删除 | map 已知：直接调 map 类型自己的函数（HASH、LRU_HASH、PERCPU_HASH、LRU_PERCPU_HASH、ARRAY、PERCPU_ARRAY、LPM_TRIE）；其余调 helper |
| 读内核内存 | 普通 load + load site |
| 读用户内存 | helper 调用 |
| bpf_get_smp_processor_id | 内联 |
| bpf_tail_call | x86 内联（入口函数内）；arm64 内联（任何函数内） |
| 其余 | 按名字绑定内核 helper |

**匹配**：加载器按程序名找 manifest 条目（5/29 的规则）；4abd03352 的“常量对不上就留在 eBPF”随 5/29 恢复一起去掉。

**两种配置**：direct native（冻结入口计时的）在 5/29 基础上完整；checked（主配置）由 formal 线（Codex，verify 侧）接回：dd6559b54 把可信加载放进单独的 native_loader_trusted.cpp，性能代码里只有一处分派；1cb485711 补回 --preserve-entry-abi。

**行数**：tally.sh 在 f26e844a9：路径文件新增 1824、删除 1316，净增 508。新增里约 130 行是 checked 配置（verify 侧）落在共用文件里的接入，native-link 的 main.rs 新增 605 行、删除 352 行，x86.rs 新增 396 行、删除 192 行，其中不少是替换 5/29 代码的行。按新增行算超过 1000。

**构建**：native-link（9 个测试）、加载器、shim、x86 和 arm64 模块、x86 和 arm64 六应用原生对象都已构建通过（/workspaces/kprog-raw/coordinator/restore-529/）。离线链接 x86 289/289、arm64 287/289（biosnoop 两个 ADR_GOT 入口）。x86 镜像 06:04Z 起用 f26e844a9 的内容重建（chain11）；arm64 镜像在 23844aa67 的检查跑完后用 f26e844a9 重建（chain12）。

## 三、和原话的差异

| # | 差异 | 原话 |
|---|---|---|
| 1 | x86 六应用全部原生（OTel 14、BCC 25、Cilium 135、Tetragon 288、Tracee 169、Katran 1）；库的特性探测程序（libbpf、cilium/ebpf 加载后马上卸载）按 5/29 规则留在 eBPF | “任何情况下绝对不允许留在 ebpf 上面跑” |
| 2 | arm64 来宾检查（镜像 23844aa67）：OTel、BCC、Cilium 原生通过（之前崩溃），Tetragon、Tracee、Katran 在跑；最终代码 f26e844a9 的 arm64 镜像接着检查，通过后在 Spark KVM 上计时（暂停 DeepSeek，测完立刻恢复） | 2026-11-20“确保 arm 和 x86 都要弄好, 不然就用 5/27 的数字 … 如果 11/22 之前弄不好就还是 5/27 的”；2026-11-22“arm 的也需要测试.” |
| 5 | x86 a04e31ae9 的 stats 关：BCC 0.988x、Katran 1.018x（8430daa81 是 1.014x、1.106x）。Katran 的原因是内层 map 查找走 helper，56cf40e8e 处理；最终镜像上重测 | 2026-11-22“Cilium 那个也不应该更慢. 任何都不应该更慢对吧?” |
| 6 | 路径行数按新增算超过 1000（见上面“行数”） | 2026-11-21“整个路径 1000 行以内的 fix 和优化” |
| 3 | 装载时常量特化（perf_context_lto）只在 checked 配置里用；它要求 P 带 bitcode、运行时带编译器，和 11-11“不需要 构建时多保留一份 LLVM bitcode?”、11-12“运行时镜像里要带源码和编译器? 不需要吧?”相反，所以 direct native 不接 | “helper map 也可以这样内联之后常量消除” |
| 4 | 读用户内存、current_task 仍是 helper 调用 | “手写的 helper 例程 是不是应替换成 c 实现的直接编译进去的” |

## 四、进度和下一步

1. x86 功能检查（每应用 10 秒、stats 开）全部通过：OTel、BCC、Cilium、Tracee、Katran 在 18:4x–18:59Z（镜像 6004ea7ac），Tetragon 19:29Z 在新镜像上复查（x86_kvm_corpus_20261121_192644_031303：288 个原生，两臂各取样 287 个程序，3 个活跃程序都跟中位数一致）。
2. x86 完整性能测试（冻结入口，六应用 × stats 关、开，3 样本 × 180 秒，不调参数）19:29Z 起在镜像 8430daa81 上跑，进度 /workspaces/kprog-raw/one-image-runs/progress.log。截至 00:25Z（may29_ratio.py）：

   | 应用 | 吞吐 stats 关 | 每次调用 stats 开 | 吞吐 stats 开 | 5/29 |
   |---|---|---|---|---|
   | OTel | 1.847x（作废） | 19.3x（作废） | 1.850x（作废） | 1.849x |
   | BCC | 1.014x | 0.999x | 0.999x | 0.985x |
   | Cilium | 1.026x | 1.108x | 1.048x | 1.319x |
   | Tetragon | 1.335x | 2.439x | 1.982x | 1.009x |
   | Tracee | 1.908x | 1.978x | 1.690x | 0.948x |
   | Katran | 1.106x | 在跑 | 在跑 | 1.113x |

   Cilium 每次调用低于 5/29 的 1.319x。之后 chain5.sh 清掉 x86 原生对象、重建镜像、重跑 OTel 两遍。
3. x86 镜像 a04e31ae9 的 stats 关一列（02:4x–05:52Z）：OTel 1.013x、BCC 0.988x、Cilium 1.026x、Tetragon 1.497x、Tracee 1.736x、Katran 1.018x，几何平均 1.181x；全部 status ok、程序全部原生。stats 开的一列由最终代码的镜像接替。
4. Cilium 每次调用逐次看（cil_from_container）：eBPF 600–1100 ns，原生 416–1171 ns，比值 0.885x–1.348x；1.348x 是 11-21 13:39 那一次（镜像 3b5fa4b40），其它大多 0.9x–1.15x。
5. 最终代码（f26e844a9）：x86 chain11 06:04Z 起重建镜像，六应用各检查一次（verbose、扫 oops），通过后跑完整轮换；arm64 chain12 在 23844aa67 的检查跑完后重建镜像并检查，通过后在 Spark KVM 上计时。
6. Spark 第二次计时 05:2xZ 停掉（镜像缺 TBZ 修复，BCC 7 个入口和 Katran balancer_ingress 和修好的链接结果不同），DeepSeek 05:31Z 恢复（spark-manage 3a3d0da5）。
