# O3 roundtrip 正确性交叉对比(2026-05-21)—— 结论:**没有 O3 roundtrip bug**

## 背景
上一轮怀疑「LLVM O3 roundtrip 把未折叠的 katran balancer 编译错了(retval=2 vs 期望
3)」。本轮系统交叉对比 **内核里跑的 original vs O3-roundtripped**(同一输入,比 retval +
data_size_out),覆盖 micro + testobject。

## 方法
给 `bpfopt-loader` 加了两个 flag(host 可控,测的就是 bpfopt eBPF→IR→O3→eBPF→内核 这条路):
- `--test-input FILE`:用文件当 `BPF_PROG_TEST_RUN` 的 data_in。
- `--compare`:除了 pass 输出,也把 **canonicalized original(无 LLVM roundtrip)**加载进内核
  TEST_RUN 一遍,写 `test_run_baseline.json`,用于 original-vs-roundtrip 对比。
- 同时给 `verify_workdir` 加了 ENOSPC→log_level=0 重试(复杂程序 verbose verifier log 撑爆
  64MB 时,程序其实能过)。
关键点:对比只要 **baseline 与 O3 喂同一输入**,就能检出 roundtrip 是否改变语义,
**不依赖输入是否"正确"**。

## 结果

### micro(29 个 XDP 程序,`--pass dce` = 纯 O3 roundtrip)
**28/29 baseline == O3**(retval + data_size_out 完全一致),0 mismatch。
1 个 err = `tc_packet_checksum_fold`(TC 类型,TEST_RUN EINVAL,与 O3 无关)。
注意:micro 是 map-staged 输入,我用 packet data_in 喂,多数程序走 early-exit(retval 0),
对 O3 的压力较弱;但有 retval=2 的几个 + 全部 data_size_out 都一致。

### katran balancer(复杂,populate_katran_maps 填了真实 map,katran VIP 报文)
| 变体 | retval | data_size_out |
|---|---|---|
| **baseline(original,无 roundtrip)** | **2** | 64 |
| noop(O0/mem2reg roundtrip) | 2 | 64 |
| **dce(纯 O3 roundtrip)** | **2** | 64 |
| **map_inline(我的 soft fold)** | **2** | 64 |

**baseline == O0 == O3 == soft,全是 retval 2。** → **O3 roundtrip 对 katran 完全保语义,没有 bug。**

## 上一轮"O3 mis-compile"是误判
katran cargo test(`katran_optimization_path`)的 baseline 只在 repeat=10000(live 模式,
retval=0)跑,**从不在 repeat=1 检查 baseline 的 retval**;只对 **优化后**的程序在 repeat=1
断言 `retval==XDP_TX(3)`。所以:
- 我之前看到 soft/0-fold → retval 2,误以为是 O3/soft 把它编译错了。
- 实际上 **original 在 repeat=1 本来就是 retval 2**。retval 3 **只有 hard fold 能给出** ——
  因为 hard fold 把 overlay 意图值(ch_rings→1、reals[1]→real_def 等)**强行**塞进程序,
  改变了行为(2→3)。

## 重大结论
1. **不存在 O3 roundtrip 正确性 bug**:O3(dce)/ O0(noop)/ soft map_inline 在 katran 上都
   等于 original(retval 2);micro 28/29 一致。
2. **我的 soft fold 是正确的** —— 它保留 original 行为(retval 2 == baseline)。之前 cargo
   test "失败" 只是因为它的断言期望 hard-fold-强制 的 retval 3。
3. **需要重新审视的是 hard fold**:它把 katran 行为从 2(PASS)改成 3(TX),即强行让程序
   转发。这究竟是「benchmark 的 map/包没配置成真正转发,hard fold 替它补上意图值」还是
   「hard fold 语义上不正确地强制转发」,取决于 katran 在该 benchmark 下的预期语义 —— 但
   **faithful 的行为(original/O3/soft)是 2**。

## 待办 / 影响
- katran cargo test 的 `assert_katran_forwarding_output`(期望 3)是 **hard-fold 专用断言**,
  对 soft fold 不适用;应改成「对比 optimized vs baseline 一致」而不是硬编码 3。
### testobject 全量 sweep(`--pass dce` = O3,baseline vs O3)
能 TEST_RUN 的全部 baseline == O3:
- `bcc_biosnoop`:OK base=[0 4096] o3=[0 4096]
- `katran_balancer`:OK base=[2 64] o3=[2 64]
其余 no-testrun(非 O3 问题):kprobe/tracepoint/LSM = ENOTSUPP(524);XDP/TC(cilium_*)=
EINVAL(需合法报文);otel_* = 需 link tracer。在 stock 内核 + 无合成包的前提下无法 TEST_RUN。

## 汇总
所有**可 TEST_RUN**的程序(28/29 micro XDP + bcc_biosnoop + katran_balancer)上,
**O3 roundtrip 输出与 original 完全一致(0 mismatch)**。结合 noop(O0)/soft 也都等于
baseline,**确认 LLVM O3 roundtrip 保语义,不存在之前怀疑的正确性 bug**。

## 性能(katran balancer_ingress, live-XDP repeat=10000, ns/run)
| 变体 | baseline | optimized | 结论 |
|---|---|---|---|
| dce(纯 O3 roundtrip) | 130/129/130 | 131/135/127 | 持平(O3 既不快也不慢) |
| map_inline(soft) | 136/119/131 | 136/126/131 | 持平,**无可测收益** |

**soft fold 在 katran 上 ≈ 0% 提速**(全在噪声带内)。原因:
- soft fold **保留真实 lookup**(presence guard),只把值折进 deref;贵的部分(lookup)还在,
  且只折了 ch_rings/server_id 两个 map 共 4 个 site 的小 u32 值 → O3 后基本中性。
- 之前的 ~17% 来自 **hard fold 删掉 16 个 lookup + 删 miss 路径**,而且部分收益其实来自
  hard fold **强制了转发路径(2→3)**,既不安全也改变了语义。

**性能/正确性的取舍(接「没有 daemon」那条线)**:没有 deopt 安全网时,
- 安全的 soft fold → katran ≈ 0%;
- 大收益的 hard fold(删 lookup)→ ~17%,但**无 deopt 则不 sound**(且会强改行为)。
即「大收益」依赖 speculative + deopt 机制,而当前 no-daemon 架构缺这一层。micro 的性能要走
`make micro`(proper benchmark),host 上 katran 这条是中性。
