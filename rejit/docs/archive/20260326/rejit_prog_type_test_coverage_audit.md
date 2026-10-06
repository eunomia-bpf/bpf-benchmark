# REJIT prog_type test coverage audit

日期: 2026-03-26

## 范围

本审计只统计题目指定的 9 个 unittest 源文件中的 REJIT 测试：

- `tests/unittest/rejit_regression.c`
- `tests/unittest/rejit_safety_tests.c`
- `tests/unittest/rejit_swap_tests.c`
- `tests/unittest/rejit_audit_tests.c`
- `tests/unittest/rejit_tail_call.c`
- `tests/unittest/rejit_prog_types.c`
- `tests/unittest/rejit_kinsn.c`
- `tests/unittest/rejit_verifier_negative_tests.c`
- `tests/unittest/rejit_spectre.c`

不把 upstream selftests、其他 repo 测试、也不把“理论上可测”算成“当前已覆盖”。

## 口径

- “有 REJIT 测试”:
  只要该 prog_type 在上述文件里被 load 后执行过 `BPF_PROG_REJIT`，就算有。
- “真实 attach”:
  只统计真正挂到 live hook/link/对象上的情况，例如 `bpf_program__attach()`、`bpf_link_create()`、`bpf_prog_attach()`、`bpf_map__attach_struct_ops()`、`SO_ATTACH_REUSEPORT_EBPF`、tc/cgroup/xdp/netfilter/lwt attach。
  `BPF_PROG_TEST_RUN` 不算真实 attach。
- “REJIT 后用户态可观测行为”:
  只统计 REJIT 后用户态还能直接断言的语义结果，例如 retval、map 值、包是否送达、包是否被改写、输入事件、socket 被选中与否。
  单纯“没 crash / 没 hang / 能卸载”不算强语义观测。
- “技术上不可测”:
  指该 prog_type 本身不对应可执行 attach 语义，或者 UAPI 上不是一个应被单独补测的 live hook。

## 头文件基线

题目写的是 `include/uapi/linux/bpf.h`，但 repo 根目录没有这一路径。当前 unittest 实际使用的是 vendored 头文件：

- `vendor/linux-framework/include/uapi/linux/bpf.h`

因此 Step 2 以这个文件中的 `enum bpf_prog_type` 为准。

## Step 1: 当前已有覆盖的 prog_type

### 强覆盖: 真实 attach + REJIT + 用户态可观测行为

- `BPF_PROG_TYPE_RAW_TRACEPOINT`
  `rejit_swap_tests.c` 的 `T6_rejit_swap_callchain_buf` 加载 `test_callchain_buf_rawtp.bpf.o`，真实 attach 到 `raw_tracepoint/sys_enter`，REJIT 后继续等待 `state_map.hits` 增长，属于当前唯一的强覆盖。

### 部分覆盖: 有 REJIT + 可观测行为，但不是 live attach

- `BPF_PROG_TYPE_XDP`
  多个文件通过 `BPF_PROG_TEST_RUN` 校验 REJIT 前后 retval、tail-call 行为、map 效果、光谱化插桩后语义一致性，但没有 live XDP attach。
- `BPF_PROG_TYPE_SOCKET_FILTER`
  `rejit_prog_types.c:T03_socket_filter` 通过 `BPF_PROG_TEST_RUN` 比较 REJIT 前后 retval。
- `BPF_PROG_TYPE_SCHED_CLS`
  `rejit_prog_types.c:T02_tc_sched_cls` 和 `T14_tc_functional_rejit` 通过 `BPF_PROG_TEST_RUN` 比较或改变 retval。
- `BPF_PROG_TYPE_SCHED_ACT`
  `rejit_prog_types.c:T09_sched_act` 通过 `BPF_PROG_TEST_RUN` 比较 retval。
- `BPF_PROG_TYPE_CGROUP_SKB`
  `rejit_prog_types.c:T04_cgroup_skb` 通过 `BPF_PROG_TEST_RUN` 比较 retval，但没有真实 cgroup attach。
- `BPF_PROG_TYPE_LWT_IN`
  `rejit_prog_types.c:T12_lwt_in` 尝试 `BPF_PROG_TEST_RUN`，失败时才退化成 REJIT-only。

### 部分覆盖: 有真实 attach + REJIT，但没有语义级 post-REJIT 观测

- `BPF_PROG_TYPE_EXT`
  `rejit_prog_types.c:T17_freplace` 通过 `bpf_program__set_attach_target()` + `bpf_object__load()` 把 EXT 程序挂到 target prog 上，再对 EXT 做 identity REJIT；但测试没有执行 target，因此没有 post-REJIT 行为观测。
- `BPF_PROG_TYPE_STRUCT_OPS`
  `rejit_regression.c:test_rejit_struct_ops_multi_rejit_unregister` 会真实 `attach_struct_ops` 并 REJIT 回调程序；但只验证多次 REJIT、unregister 和无内核告警，没有验证 callback 语义。

### 弱覆盖: 只有 load + REJIT identity，缺少 attach 和/或缺少行为观测

- `BPF_PROG_TYPE_KPROBE`
- `BPF_PROG_TYPE_TRACEPOINT`
- `BPF_PROG_TYPE_PERF_EVENT`
- `BPF_PROG_TYPE_CGROUP_SOCK`
- `BPF_PROG_TYPE_CGROUP_SOCK_ADDR`
- `BPF_PROG_TYPE_FLOW_DISSECTOR`
- `BPF_PROG_TYPE_SK_LOOKUP`
- `BPF_PROG_TYPE_TRACING`
- `BPF_PROG_TYPE_LSM`

其中 `BPF_PROG_TYPE_TRACING` 还有一个重要注记：

- `rejit_prog_types.c:T15_fentry/T16_fexit` 只是 load + REJIT。
- `rejit_regression.c:test_rejit_fentry_reattach_refresh` 本来设计成真实 attach + map 计数观测，但函数开头直接 `TEST_SKIP`，所以当前不能算有效覆盖。

### 完全没有覆盖

- `BPF_PROG_TYPE_UNSPEC`
- `BPF_PROG_TYPE_LWT_OUT`
- `BPF_PROG_TYPE_LWT_XMIT`
- `BPF_PROG_TYPE_SOCK_OPS`
- `BPF_PROG_TYPE_SK_SKB`
- `BPF_PROG_TYPE_CGROUP_DEVICE`
- `BPF_PROG_TYPE_SK_MSG`
- `BPF_PROG_TYPE_LWT_SEG6LOCAL`
- `BPF_PROG_TYPE_LIRC_MODE2`
- `BPF_PROG_TYPE_SK_REUSEPORT`
- `BPF_PROG_TYPE_CGROUP_SYSCTL`
- `BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE`
- `BPF_PROG_TYPE_CGROUP_SOCKOPT`
- `BPF_PROG_TYPE_SYSCALL`
- `BPF_PROG_TYPE_NETFILTER`

### 小结

- `enum bpf_prog_type` 总数: 33
- 当前至少有某种 REJIT 覆盖的 prog_type: 18
- 当前达到“真实 attach + REJIT + 用户态可观测行为”的 prog_type: 1
- 当前完全没有覆盖的 prog_type: 15

## Step 2: 内核支持的全部 prog_type

来源: `vendor/linux-framework/include/uapi/linux/bpf.h` 中 `enum bpf_prog_type`

1. `BPF_PROG_TYPE_UNSPEC`
2. `BPF_PROG_TYPE_SOCKET_FILTER`
3. `BPF_PROG_TYPE_KPROBE`
4. `BPF_PROG_TYPE_SCHED_CLS`
5. `BPF_PROG_TYPE_SCHED_ACT`
6. `BPF_PROG_TYPE_TRACEPOINT`
7. `BPF_PROG_TYPE_XDP`
8. `BPF_PROG_TYPE_PERF_EVENT`
9. `BPF_PROG_TYPE_CGROUP_SKB`
10. `BPF_PROG_TYPE_CGROUP_SOCK`
11. `BPF_PROG_TYPE_LWT_IN`
12. `BPF_PROG_TYPE_LWT_OUT`
13. `BPF_PROG_TYPE_LWT_XMIT`
14. `BPF_PROG_TYPE_SOCK_OPS`
15. `BPF_PROG_TYPE_SK_SKB`
16. `BPF_PROG_TYPE_CGROUP_DEVICE`
17. `BPF_PROG_TYPE_SK_MSG`
18. `BPF_PROG_TYPE_RAW_TRACEPOINT`
19. `BPF_PROG_TYPE_CGROUP_SOCK_ADDR`
20. `BPF_PROG_TYPE_LWT_SEG6LOCAL`
21. `BPF_PROG_TYPE_LIRC_MODE2`
22. `BPF_PROG_TYPE_SK_REUSEPORT`
23. `BPF_PROG_TYPE_FLOW_DISSECTOR`
24. `BPF_PROG_TYPE_CGROUP_SYSCTL`
25. `BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE`
26. `BPF_PROG_TYPE_CGROUP_SOCKOPT`
27. `BPF_PROG_TYPE_TRACING`
28. `BPF_PROG_TYPE_STRUCT_OPS`
29. `BPF_PROG_TYPE_EXT`
30. `BPF_PROG_TYPE_LSM`
31. `BPF_PROG_TYPE_SK_LOOKUP`
32. `BPF_PROG_TYPE_SYSCALL`
33. `BPF_PROG_TYPE_NETFILTER`

## Step 3: 差距表

| prog_type | 当前 REJIT 测试 | 有 REJIT 测试？ | 真实 attach？ | REJIT 后用户态可观测行为？ | 结论 |
| --- | --- | --- | --- | --- | --- |
| `BPF_PROG_TYPE_UNSPEC` | 无 | 否 | N/A | N/A | 技术上不可测；不是应补的 live prog_type |
| `BPF_PROG_TYPE_SOCKET_FILTER` | `rejit_prog_types.c:T03_socket_filter` | 是 | 否 | 是，`BPF_PROG_TEST_RUN` retval | 只覆盖 run-only 路径，应该补真实 socket attach |
| `BPF_PROG_TYPE_KPROBE` | `rejit_prog_types.c:T05_kprobe` | 是 | 否 | 否 | 只有 load + REJIT，应该补 |
| `BPF_PROG_TYPE_SCHED_CLS` | `rejit_prog_types.c:T02_tc_sched_cls/T14_tc_functional_rejit`; freplace target 也属此 type | 是 | 否 | 是，`BPF_PROG_TEST_RUN` retval | 当前不是 tc live attach，应该补 |
| `BPF_PROG_TYPE_SCHED_ACT` | `rejit_prog_types.c:T09_sched_act` | 是 | 否 | 是，`BPF_PROG_TEST_RUN` retval | 当前不是 tc action live attach，应该补 |
| `BPF_PROG_TYPE_TRACEPOINT` | `rejit_prog_types.c:T06_tracepoint` | 是 | 否 | 否 | 只有 load + REJIT，应该补 |
| `BPF_PROG_TYPE_XDP` | `rejit_regression.c`、`rejit_safety_tests.c`、`rejit_swap_tests.c`、`rejit_audit_tests.c`、`rejit_tail_call.c`、`rejit_prog_types.c`、`rejit_kinsn.c`、`rejit_verifier_negative_tests.c`、`rejit_spectre.c` | 是 | 否 | 是，retval/map/tail-call 行为 | correctness 很强，但缺 live attach，应该补 |
| `BPF_PROG_TYPE_PERF_EVENT` | `rejit_prog_types.c:T08_perf_event` | 是 | 否 | 否 | 只有 load + REJIT，应该补 |
| `BPF_PROG_TYPE_CGROUP_SKB` | `rejit_prog_types.c:T04_cgroup_skb` | 是 | 否 | 是，`BPF_PROG_TEST_RUN` retval | 没有真实 cgroup attach，应该补 |
| `BPF_PROG_TYPE_CGROUP_SOCK` | `rejit_prog_types.c:T21_cgroup_sock` | 是 | 否 | 否 | 只有 load + REJIT，应该补 |
| `BPF_PROG_TYPE_LWT_IN` | `rejit_prog_types.c:T12_lwt_in` | 是 | 否 | 部分是，取决于 `BPF_PROG_TEST_RUN` 是否支持 | 没有 route attach，应该补 |
| `BPF_PROG_TYPE_LWT_OUT` | 无 | 否 | 否 | 否 | 应该补 |
| `BPF_PROG_TYPE_LWT_XMIT` | 无 | 否 | 否 | 否 | 应该补 |
| `BPF_PROG_TYPE_SOCK_OPS` | 无 | 否 | 否 | 否 | 应该补 |
| `BPF_PROG_TYPE_SK_SKB` | 无 | 否 | 否 | 否 | 应该补 |
| `BPF_PROG_TYPE_CGROUP_DEVICE` | 无 | 否 | 否 | 否 | 应该补 |
| `BPF_PROG_TYPE_SK_MSG` | 无 | 否 | 否 | 否 | 应该补 |
| `BPF_PROG_TYPE_RAW_TRACEPOINT` | `rejit_prog_types.c:T07_raw_tracepoint`; `rejit_swap_tests.c:T6_rejit_swap_callchain_buf` | 是 | 是 | 是，attach 后 `state_map.hits` 增长 | 当前唯一强覆盖；可视为已补齐 |
| `BPF_PROG_TYPE_CGROUP_SOCK_ADDR` | `rejit_prog_types.c:T20_cgroup_sock_addr` | 是 | 否 | 否 | 只有 load + REJIT，应该补 |
| `BPF_PROG_TYPE_LWT_SEG6LOCAL` | 无 | 否 | 否 | 否 | 应该补，但需要更重的 IPv6/SRv6 VM harness |
| `BPF_PROG_TYPE_LIRC_MODE2` | 无 | 否 | 否 | 否 | 技术上可测，但依赖 rc-loopback 设备；应补到特定 VM 套件 |
| `BPF_PROG_TYPE_SK_REUSEPORT` | 无 | 否 | 否 | 否 | 应该补 |
| `BPF_PROG_TYPE_FLOW_DISSECTOR` | `rejit_prog_types.c:T10_flow_dissector` | 是 | 否 | 否 | 当前连 `BPF_PROG_TEST_RUN` 都没做，应该补真实 attach |
| `BPF_PROG_TYPE_CGROUP_SYSCTL` | 无 | 否 | 否 | 否 | 应该补 |
| `BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE` | 无 | 否 | 否 | 否 | 应该补 |
| `BPF_PROG_TYPE_CGROUP_SOCKOPT` | 无 | 否 | 否 | 否 | 应该补 |
| `BPF_PROG_TYPE_TRACING` | `rejit_prog_types.c:T15_fentry/T16_fexit`; `rejit_regression.c:test_rejit_fentry_reattach_refresh` 被硬跳过 | 是 | 否 | 否 | 当前只有 load + REJIT；真实 attach 方案存在但未启用，应该补 |
| `BPF_PROG_TYPE_STRUCT_OPS` | `rejit_prog_types.c:T19_struct_ops`; `rejit_audit_tests.c:T9_H3_struct_ops_multi_slot`; `rejit_regression.c:test_rejit_struct_ops_multi_rejit_unregister` | 是 | 是 | 弱，仅生命周期/无告警 | attach 有了，但缺 callback 语义观测，应该补强 |
| `BPF_PROG_TYPE_EXT` | `rejit_prog_types.c:T17_freplace` | 是 | 是 | 否，target 从未执行 | attach 有了，但缺 target 行为观测，应该补强 |
| `BPF_PROG_TYPE_LSM` | `rejit_prog_types.c:T18_lsm` | 是 | 否 | 否 | 只有 load + REJIT，应该补 |
| `BPF_PROG_TYPE_SK_LOOKUP` | `rejit_prog_types.c:T11_sk_lookup` | 是 | 否 | 否 | 只有 load + REJIT，应该补 |
| `BPF_PROG_TYPE_SYSCALL` | 无 | 否 | N/A | 否 | 不是 attach-type，但可通过 `BPF_PROG_TEST_RUN` 执行；应该补 run-path REJIT 测试 |
| `BPF_PROG_TYPE_NETFILTER` | 无 | 否 | 否 | 否 | 应该补 |

## 结论

当前 repo 的 REJIT 覆盖重心明显偏向:

- `XDP` correctness / verifier / swap / spectre / kinsn / tail-call
- 少量“跨 prog_type 的 load + identity REJIT”

但离“所有 prog_type 的真实 attach 覆盖”还差得很远。当前只有 `RAW_TRACEPOINT` 真正达到了：

- live attach
- 执行 REJIT
- REJIT 后用用户态可观测信号断言语义仍成立

`EXT` 和 `STRUCT_OPS` 虽然已经触达 attach 路径，但没有 post-REJIT 语义级断言，所以也不能算最终形态的覆盖。

## Step 4: 需要补充的测试设计

以下设计目标是补“强覆盖缺口”，也就是优先把每个 prog_type 拉到“真实 attach + REJIT + 用户态可观测行为”。

### 4.1 应优先补的类型

| prog_type | attach 方式 | 触发方式 | REJIT 前后可观测差异 | 需要的 `.bpf.c` |
| --- | --- | --- | --- | --- |
| `BPF_PROG_TYPE_XDP` | 在 VM 内把程序真实 attach 到 veth/virtio ingress（`bpf_xdp_attach` 或 XDP link） | 从对端 veth 发送 UDP/ICMP 包 | REJIT 前 `XDP_PASS`，报文能到达；REJIT 后 `XDP_DROP` 或改写头部，用户态看到丢包或 payload/TTL 变化 | `tests/unittest/progs/test_xdp_live_rejit.bpf.c` |
| `BPF_PROG_TYPE_SOCKET_FILTER` | `setsockopt(SO_ATTACH_BPF)` 挂到 AF_PACKET/RAW socket | 经 veth/loopback 发送一个可识别 UDP 帧 | REJIT 前 socket 收到完整包；REJIT 后 filter 返回 0 或更短长度，用户态超时或收到截断包 | `tests/unittest/progs/test_socket_filter_rejit.bpf.c` |
| `BPF_PROG_TYPE_SCHED_CLS` | tc `clsact` + `bpf filter` attach 到 ingress/egress | veth 对端发送 UDP | REJIT 前 `TC_ACT_OK`，报文送达；REJIT 后 `TC_ACT_SHOT` 或改写 DSCP/TTL，用户态看到丢包或字段变化 | `tests/unittest/progs/test_sched_cls_rejit.bpf.c` |
| `BPF_PROG_TYPE_SCHED_ACT` | tc action BPF 挂到 filter action 链 | 同上 | REJIT 前 action `OK/PIPE`；REJIT 后 `SHOT` 或 mark/header rewrite，用户态看到丢包或字段变化 | `tests/unittest/progs/test_sched_act_rejit.bpf.c` |
| `BPF_PROG_TYPE_KPROBE` | `SEC("kprobe/__x64_sys_getpid")` 或 `ksyscall/getpid` + `bpf_program__attach()` | 反复调用 `getpid()` | REJIT 前 map counter 每次 `+1`；REJIT 后改成 `+2` 或写入不同 marker | `tests/unittest/progs/test_kprobe_rejit_counter.bpf.c` |
| `BPF_PROG_TYPE_TRACEPOINT` | `SEC("tracepoint/syscalls/sys_enter_getpid")` attach | 调用 `getpid()` 或 `nanosleep()` | REJIT 前 map counter `+1`；REJIT 后 `+2` | `tests/unittest/progs/test_tracepoint_rejit_counter.bpf.c` |
| `BPF_PROG_TYPE_PERF_EVENT` | `perf_event_open(PERF_TYPE_SOFTWARE, PERF_COUNT_SW_CPU_CLOCK)` + perf-event attach | enable event 后 busy loop 一小段时间 | REJIT 前 map counter 或 perf buffer 记录 marker A；REJIT 后 marker B | `tests/unittest/progs/test_perf_event_rejit_counter.bpf.c` |
| `BPF_PROG_TYPE_CGROUP_SKB` | `bpf_program__attach_cgroup()` 到子 cgroup 的 ingress/egress | 把 child 进程放进 cgroup，发送 UDP/TCP | REJIT 前 allow；REJIT 后 deny/drop，用户态看到 send/recv 失败或 map 计数变化 | `tests/unittest/progs/test_cgroup_skb_rejit.bpf.c` |
| `BPF_PROG_TYPE_CGROUP_SOCK` | attach 到 `cgroup/sock_create` | 在子 cgroup 中执行 `socket(AF_INET, SOCK_STREAM, 0)` | REJIT 前 `socket()` 成功；REJIT 后返回 `EPERM`，或 map marker 变化 | `tests/unittest/progs/test_cgroup_sock_rejit.bpf.c` |
| `BPF_PROG_TYPE_CGROUP_SOCK_ADDR` | attach 到 `cgroup/connect4` 或 `cgroup/sendmsg4` | 子 cgroup 中 `connect()` 到 A 端口 | REJIT 前连接被重定向到 server A；REJIT 后改写到 server B，用户态看到连接/响应来自不同端口 | `tests/unittest/progs/test_cgroup_sock_addr_rejit.bpf.c` |
| `BPF_PROG_TYPE_CGROUP_DEVICE` | attach 到 `cgroup/dev` | 子 cgroup 中 `open("/dev/null")` 或 `open("/dev/urandom")` | REJIT 前 allow；REJIT 后 deny `EPERM`，或者从 allow `/dev/null` 切到 only `/dev/urandom` | `tests/unittest/progs/test_cgroup_device_rejit.bpf.c` |
| `BPF_PROG_TYPE_CGROUP_SYSCTL` | attach 到 `cgroup/sysctl` | 子 cgroup 中读/写 `/proc/sys/net/ipv4/...` | REJIT 前 read/write 成功；REJIT 后 deny，或重写新值，用户态读回值不同 | `tests/unittest/progs/test_cgroup_sysctl_rejit.bpf.c` |
| `BPF_PROG_TYPE_CGROUP_SOCKOPT` | attach 到 `cgroup/getsockopt` / `cgroup/setsockopt` | 子 cgroup 中 `setsockopt(IPV6_TCLASS)` 或 `getsockopt(TCP_CONGESTION)` | REJIT 前不改写；REJIT 后改写成不同 congestion control / optval，用户态 `getsockopt()` 读到变化 | `tests/unittest/progs/test_cgroup_sockopt_rejit.bpf.c` |
| `BPF_PROG_TYPE_SOCK_OPS` | attach 到子 cgroup 的 `sockops` hook | 建立一次 loopback TCP 连接 | REJIT 前在 `ACTIVE_ESTABLISHED` 回调把 map counter `+1`；REJIT 后 `+2` 或写新 marker | `tests/unittest/progs/test_sockops_rejit.bpf.c` |
| `BPF_PROG_TYPE_SK_SKB` | 用 sockmap/sockhash 挂 `sk_skb/stream_verdict` 或 `stream_parser` | 两端 TCP socket 互发 1 字节或固定 payload | REJIT 前数据能到达；REJIT 后 drop/redirect 到另一 socket，用户态看到收包对象或是否收包发生变化 | `tests/unittest/progs/test_sk_skb_rejit.bpf.c` |
| `BPF_PROG_TYPE_SK_MSG` | 用 sockmap/sockhash 挂 `sk_msg` verdict | `sendmsg()` 发送固定 payload | REJIT 前 allow 或 redirect 到 socket A；REJIT 后 drop 或 redirect 到 socket B | `tests/unittest/progs/test_sk_msg_rejit.bpf.c` |
| `BPF_PROG_TYPE_SK_REUSEPORT` | `SO_REUSEPORT` listener group + `SO_ATTACH_REUSEPORT_EBPF` | 发起多次 UDP/TCP client 请求 | REJIT 前总是选 server A；REJIT 后改选 server B，用户态看到 accept/recv 落到不同 fd | `tests/unittest/progs/test_sk_reuseport_rejit.bpf.c` |
| `BPF_PROG_TYPE_SK_LOOKUP` | attach 到 netns 的 `BPF_SK_LOOKUP` hook | client 连接/发包到 `127.0.0.1:7007` | REJIT 前 lookup 重定向到 `127.0.0.2:8008` 的 socket A；REJIT 后改到 socket B 或 drop | `tests/unittest/progs/test_sk_lookup_rejit.bpf.c` |
| `BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE` | `bpf_raw_tracepoint_open("bpf_test_finish", prog_fd)` | 触发一次 `BPF_PROG_TEST_RUN` 到一个 socket_filter/XDP 测试程序 | REJIT 前 writable raw tp 把返回状态改成 A；REJIT 后改成 B，用户态直接看到 `bpf_prog_test_run` 返回值变化 | `tests/unittest/progs/test_raw_tp_writable_rejit.bpf.c` |
| `BPF_PROG_TYPE_TRACING` | `fentry` attach 到 repo 自己的 XDP/TC target prog，使用 `bpf_link_create(BPF_TRACE_FENTRY)` | 执行 target prog 的 `BPF_PROG_TEST_RUN` 或 live attach 触发 | REJIT 前 fentry map counter `+1`；REJIT 后 `+2` | 复用 `tests/unittest/progs/test_simple.bpf.c`，新增 `tests/unittest/progs/test_tracing_rejit_counter.bpf.c` |
| `BPF_PROG_TYPE_STRUCT_OPS` | `bpf_map__attach_struct_ops()` attach tcp_congestion_ops | 创建新 TCP socket，并 `setsockopt(TCP_CONGESTION, "bpf_xxx")` 触发 `init` callback | REJIT 前 `init` 往 map 写 marker A；REJIT 后写 marker B，用户态 map lookup 可见变化 | 新增 `tests/unittest/progs/test_struct_ops_rejit_observable.bpf.c`，也可扩展现有 `test_struct_ops.bpf.c` |
| `BPF_PROG_TYPE_EXT` | `bpf_program__set_attach_target()` + load freplace 到 `test_freplace_target` 的 `get_result()` | 对 target `sched_cls` 程序做 `BPF_PROG_TEST_RUN` | 目标程序在 EXT attach 后返回 0；REJIT EXT 后返回 42，用户态直接看到 target retval 变化 | 复用 `tests/unittest/progs/test_freplace_target.bpf.c`，新增 `tests/unittest/progs/test_freplace_ext_alt.bpf.c` |
| `BPF_PROG_TYPE_LSM` | `SEC("lsm/file_open")` + `bpf_program__attach_lsm()` 或 `bpf_program__attach()` | 当前进程 `open()` 一个临时文件 | REJIT 前返回 0 放行；REJIT 后对当前 PID 返回 `-EPERM` 或写不同 map marker | `tests/unittest/progs/test_lsm_rejit_file_open.bpf.c` |

### 4.2 中等复杂度但应该补的类型

| prog_type | attach 方式 | 触发方式 | REJIT 前后可观测差异 | 需要的 `.bpf.c` |
| --- | --- | --- | --- | --- |
| `BPF_PROG_TYPE_LWT_IN` | `ip route add ... encap bpf in obj ... sec lwt_in` | 在 netns/veth 拓扑里发一个经该 route 入站的 UDP 包 | REJIT 前 allow；REJIT 后 drop 或 map marker 变化 | `tests/unittest/progs/test_lwt_rejit.bpf.c` |
| `BPF_PROG_TYPE_LWT_OUT` | `ip route add ... encap bpf out obj ... sec lwt_out` | 从本地 socket 发出经该 route 的 UDP 包 | REJIT 前 allow；REJIT 后 drop 或改写 TTL/TOS，用户态收到差异 | `tests/unittest/progs/test_lwt_rejit.bpf.c` |
| `BPF_PROG_TYPE_LWT_XMIT` | `ip route add ... encap bpf xmit obj ... sec lwt_xmit` | 从本地 socket 发出经该 route 的 UDP 包 | REJIT 前直通；REJIT 后 drop 或改写 MAC/payload，用户态收包差异 | `tests/unittest/progs/test_lwt_rejit.bpf.c` |
| `BPF_PROG_TYPE_FLOW_DISSECTOR` | attach 到当前 netns 的 `BPF_FLOW_DISSECTOR` hook | 在带多个接收 socket 的 netns 拓扑里收包 | REJIT 前 flow 被分到 socket A；REJIT 后分到 socket B，或 flow_keys 决策导致收包端变化 | `tests/unittest/progs/test_flow_dissector_rejit.bpf.c` |
| `BPF_PROG_TYPE_NETFILTER` | `bpf_program__attach_netfilter()`，挂 `NF_INET_PRE_ROUTING`/`POST_ROUTING` | client/server netns 间发送 IPv4/IPv6 UDP | REJIT 前 `NF_ACCEPT` 回显成功；REJIT 后 `NF_DROP` 或仅拒绝分片，用户态看到超时/失败 | `tests/unittest/progs/test_netfilter_rejit.bpf.c` |

### 4.3 环境更重，但技术上可测的类型

| prog_type | attach 方式 | 触发方式 | REJIT 前后可观测差异 | 需要的 `.bpf.c` |
| --- | --- | --- | --- | --- |
| `BPF_PROG_TYPE_LWT_SEG6LOCAL` | 按 upstream `lwt_seg6local` 自测方式，用 `ip -6 route ... encap seg6local action End.BPF endpoint obj ...` | 6 netns 的 SRv6 链路上发送 UDP datagram | REJIT 前 SRv6 链成功到达最终 server；REJIT 后某一步 drop 或 TLV/tag/map marker 改变 | `tests/unittest/progs/test_lwt_seg6local_rejit.bpf.c` |
| `BPF_PROG_TYPE_LIRC_MODE2` | `bpf_prog_attach(progfd, lircfd, BPF_LIRC_MODE2, 0)` 挂到 rc-loopback 的 `/dev/lircN` | 向 loopback LIRC 设备写测试脉冲序列 | REJIT 前解码成 scan code A；REJIT 后解码成 scan code B，用户态从 `/dev/input/eventM` 读到不同事件 | `tests/unittest/progs/test_lirc_mode2_rejit.bpf.c` |

### 4.4 无 attach 语义，但仍应补 REJIT 执行路径的类型

| prog_type | attach 方式 | 触发方式 | REJIT 前后可观测差异 | 需要的 `.bpf.c` |
| --- | --- | --- | --- | --- |
| `BPF_PROG_TYPE_SYSCALL` | N/A，`SYSCALL` 本身不是 attach-type | 通过 `BPF_PROG_TEST_RUN` 执行 `SEC("syscall")` 程序 | REJIT 前程序创建 map/prog 并写 value A；REJIT 后写 value B 或执行另一条 syscall 序列 | `tests/unittest/progs/test_syscall_rejit.bpf.c` |

## 建议的落地顺序

如果按“最小实现成本 / 最高信息增益”排序，我建议顺序是：

1. `TRACING`
2. `EXT`
3. `STRUCT_OPS`
4. `KPROBE`
5. `TRACEPOINT`
6. `PERF_EVENT`
7. `SOCKET_FILTER`
8. `SCHED_CLS`
9. `CGROUP_SKB`
10. `CGROUP_SOCK_ADDR`
11. `SK_LOOKUP`
12. `RAW_TRACEPOINT_WRITABLE`
13. `SOCK_OPS`
14. `SK_MSG`
15. `SK_SKB`
16. `SK_REUSEPORT`
17. `CGROUP_DEVICE`
18. `CGROUP_SOCKOPT`
19. `CGROUP_SYSCTL`
20. `NETFILTER`
21. `FLOW_DISSECTOR`
22. `LWT_IN`
23. `LWT_OUT`
24. `LWT_XMIT`
25. `LSM`
26. `CGROUP_SOCK`
27. `SYSCALL`
28. `LWT_SEG6LOCAL`
29. `LIRC_MODE2`

理由很简单：

- 前半段都可以复用现有 VM unittest harness、现成 `.bpf.c` 或者 upstream selftest 的成熟 attach 路径。
- 后半段更依赖复杂 netns、SRv6、rc-loopback 或特定 kernel config。

## 最终判断

这套 unittest 现在并不是“所有 prog_type 的 REJIT 覆盖”，而是：

- 对 `XDP` 做了非常深的 REJIT correctness 覆盖
- 对 17 个其他 prog_type 只做了浅层或中层覆盖
- 只有 `RAW_TRACEPOINT` 真正做到强语义的 live attach 覆盖

如果后续目标是“审计所有 prog_type 的 REJIT live safety”，那么最缺的不是 verifier 负测，而是：

- 真正跑到 attach path 的测试
- 真正对 REJIT 后 live 语义做用户态断言的测试

这两点目前明显不足。
