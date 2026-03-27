# map_inline 真实值调查（2026-03-26）

## 结论摘要

1. 这次我没有观察到“real VM benchmark / E2E 里只内联了 0”这种现象；更强的结论是：**当前真实 VM 跑法里，`map_inline` 基本没有真正触发**。
2. `make vm-static-test TARGET=x86` 产物里 62 个程序全部 verifier accepted，55 个程序有其它 pass 生效，但 **`map_inline` 生效数为 0**。
3. 我在 guest 里额外对 `corpus/build/katran/xdp_pktcntr.bpf.o` 做了两次 live probe：一次默认 map 值（实际 lookup 到 `0`），一次手工把 `ctl_array[0]` 写成 `1`。**两次都没有触发 `map_inline`**；因此这次实际被内联的值列表是空集，不存在“只内联零值”或“已经在内联非零值”的实证。
4. 指定的 latest corpus 结果 `corpus/results/vm_corpus_20260326_201508/metadata.json` 对应的 130 个 applied programs 里，**没有任何一个 program 的 `applied_passes` 包含 `map_inline`**。
5. latest E2E（Tracee/Katran/Tetragon）也都没有出现 `map_inline` 成功应用；我额外扫了仓库里全部 22 个 Tracee、21 个 Tetragon、22 个 Katran checked-in metadata，**`map_inline.changed=true` 的 run 数都是 0**。
6. `const_prop` / `dce` 在真实 corpus 里确实会单独触发（latest corpus 分别有 71 / 19 个 applied programs），但**不是由 `map_inline` 级联驱动**；`map_inline -> const_prop -> dce` 这条链路在这批真实程序里没有观测到。

## Step 1：daemon debug 路径实际是什么

- `daemon/src/main.rs:26-63` 当前 CLI 没有 `--debug` 字段；也就是说用户侧并不存在一个真正的 daemon `--debug` 开关。
- `daemon/src/pass.rs:682-700` `PassManager::run()` 会默认给每个 changed pass 收集 `bytecode_before/bytecode_after`，不需要额外 flag。
- `daemon/src/commands.rs:315-318` 定义了 `emit_debug_result()`；`cmd_apply()` / `cmd_apply_all()` 分别在 `daemon/src/commands.rs:575-612` 调用它，把整个 `OptimizeOneResult` JSON 打到 **stderr**。
- `daemon/src/server.rs:167-178` 的 `serve/optimize` 路径不会重复写 stderr，而是把同一个 `OptimizeOneResult` 直接塞进 socket JSON 响应。
- `daemon/src/passes/map_inline.rs:390-405` 可见 `map_inline` 目前仅输出 `speculative map-inline sites: N` 这类诊断；它**不会**直接把内联值打印出来。
- `daemon/src/passes/map_inline.rs:439-485` 实际被读出的 map 值会进入 `MapInlineRecord.expected_value`。但 `OptimizeOneResult` 的 per-pass 结构 `PassDetail`（`daemon/src/commands.rs:57-68`）没有这个字段，所以当前 debug JSON **不会直接暴露 value bytes**。

**直接含义**：当前代码下，所谓“daemon debug output enabled”并不等于“能直接看到 map inline 的值”。只有当 `map_inline.changed=true` 时，才能通过 pass trace 的 before/after bytecode 间接反推；而这次 benchmark / E2E / probe 都没有跑到那一步。

## Step 2：`vm-static-test` + guest probe

### 2.1 `make vm-static-test TARGET=x86`

- 结果文件：`daemon/tests/results/static_verify.json`
- daemon 日志：`daemon/tests/results/static_verify.daemon.log`
- 汇总：`programs_total=62`，`programs_applied=55`，`verifier_accepted_programs=62`。
- pass 命中频次：`{'wide_mem': 49, 'rotate': 13, 'extract': 4, 'const_prop': 1, 'bounds_check_merge': 2, 'endian_fusion': 1}`。
- `map_inline` 命中程序数：`0`。

**结论**：这条官方 VM 静态验证路径里，`map_inline` 根本没有应用，所以也没有任何实际被内联的值（既没有 0，也没有非 0）。

### 2.2 guest 内手工 probe：`corpus/build/katran/xdp_pktcntr.bpf.o`

probe 方式：在 VM 里用 `bpftool prog loadall ... pinmaps ...` live load object，然后直接跑 `daemon apply <prog_id>`，把 stdout/stderr 写回 `docs/tmp/20260326/probe_outputs/`。

| probe | 实际 map 值 | prog_id | `map_inline.changed` | `map_inline.sites_applied` | `const_prop.changed` | `dce.changed` | 结论 |
| --- | ---: | ---: | --- | ---: | --- | --- | --- |
| `pktcntr_zero` | `0` | `7` | `false` | `0` | `false` | `false` | 未内联任何值 |
| `pktcntr_one` | `1` | `32` | `false` | `0` | `false` | `false` | 未内联任何值 |

两次 probe 的关键事实：
- `pktcntr_zero`：`map_inline` skip reasons = `{'lookup key is not a constant stack materialization': 1, 'map type 6 not inlineable in v1': 1}`。
- `pktcntr_one`：`map_inline` skip reasons = `{'lookup key is not a constant stack materialization': 1, 'map type 6 not inlineable in v1': 1}`。
- 这说明即使我把真实 live map 的值从 `0` 改成 `1`，这条对象上的 `map_inline` 仍然停在 **模式匹配阶段**，还没走到“读取 `expected_value` 并发出常量替换”的阶段。
- 对 `xdp_pktcntr` 这个对象而言，当前 real VM run 里不存在“只内联 0”或“也会内联 1”的现象，因为根本没有内联发生。

### 2.3 另一个候选对象

- 我还尝试了 `corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o`，并手工把 `cpus_count[0]` 写成 `4`。
- 该对象在 guest 中 standalone `bpftool prog loadall` 时失败：`libbpf: map \`cpus_available\`: failed to create: -EINVAL`，因此没有进入 daemon apply 阶段，无法作为本次 value 证据。

## Step 3：指定 latest corpus 结果 `vm_corpus_20260326_201508`

- metadata：`corpus/results/vm_corpus_20260326_201508/metadata.json`
- detail：`corpus/results/vm_corpus_20260326_201508/details/result.json`
- latest corpus summary 显示 `applied_programs=130`，top-level `pass_counts={'cond_select': 19, 'const_prop': 138, 'dangerous_helper_firewall': 86, 'dce': 34, 'endian_fusion': 119, 'extract': 13, 'live_patch': 116, 'skb_load_bytes_spec': 2, 'wide_mem': 67}`。这里 **没有 `map_inline`**。
- detail `programs` 总数：`764`；其中 `applied_passes != []` 的 applied programs：`130`。
- applied programs 的 pass 频次（从 detail 重新统计）：`{'live_patch': 63, 'const_prop': 71, 'dce': 19, 'cond_select': 10, 'endian_fusion': 60, 'wide_mem': 34, 'dangerous_helper_firewall': 44, 'extract': 7, 'skb_load_bytes_spec': 1}`。同样 **没有 `map_inline`**。

### 3.1 这份 latest corpus artifact 能回答什么，不能回答什么

- 它能回答：每个 applied program 用了哪些 pass；`map_inline` 是否出现在 `applied_passes` 中。
- 它不能回答：如果 `map_inline` 应用了，具体应用了几个 site、每个 site 的 value 是多少。原因不是我没解析到，而是 artifact 本身没有保存这个字段。
- 因为这份 artifact 里每个 applied program 的 `applied_passes` 都不含 `map_inline`，所以这次可以把“`map_inline` applied sites”安全地记为 `0`。

### 3.2 latest corpus 的总体结论

- `map_inline` applied programs：`0` / `130`。
- 也就是说 latest corpus 里没有任何程序从 `map_inline` 受益。
- `const_prop` + `dce` 同时出现的程序有 `19` 个，但没有一个同时带 `map_inline`；因此真实 corpus 里**观察到的是 `const_prop/dce` 自己在工作，而不是 `map_inline -> const_prop -> dce` 级联**。

### 3.3 latest corpus 里“收益最大”的程序（按 size_delta_pct 最负排序）

| size_delta_pct | source | object | program | applied_passes | `map_inline`? |
| ---: | --- | --- | --- | --- | --- |
| `-93.92` | `tetragon` | `corpus/build/tetragon/bpf_cgroup_release.bpf.o` | `tg_tp_cgrp_release` | `const_prop, dce, live_patch` | `no` |
| `-93.92` | `tetragon` | `corpus/build/tetragon/bpf_cgroup_rmdir.bpf.o` | `tg_tp_cgrp_rmdir` | `const_prop, dce, live_patch` | `no` |
| `-87.35` | `tetragon` | `corpus/build/tetragon/bpf_cgroup_mkdir.bpf.o` | `tg_tp_cgrp_mkdir` | `const_prop, dce, live_patch` | `no` |
| `-82.16` | `tetragon` | `corpus/build/tetragon/bpf_cgtracker.bpf.o` | `tg_cgtracker_cgroup_mkdir` | `const_prop, dce, live_patch` | `no` |
| `-50.68` | `tetragon` | `corpus/build/tetragon/bpf_execve_bprm_commit_creds.bpf.o` | `tg_kp_bprm_committing_creds` | `live_patch` | `no` |
| `-28.81` | `tracee` | `corpus/build/tracee/tracee.bpf.o` | `tracepoint__raw_syscalls__sys_enter` | `live_patch` | `no` |
| `-23.29` | `tetragon` | `corpus/build/tetragon/bpf_cgroup.bpf.o` | `tg_cgroup_rmdir` | `const_prop, dce, live_patch` | `no` |
| `-17.30` | `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_assign_reuse.bpf.o` | `reuse_accept` | `const_prop, dce, wide_mem` | `no` |
| `-8.23` | `tracee` | `corpus/build/tracee/tracee.bpf.o` | `cgroup_skb_egress` | `const_prop, dce, wide_mem, endian_fusion` | `no` |
| `-8.23` | `tracee` | `corpus/build/tracee/tracee.bpf.o` | `cgroup_skb_ingress` | `const_prop, dce, wide_mem, endian_fusion` | `no` |

**解读**：latest corpus 里收益最大的程序也完全不是 `map_inline` 驱动，主要来自 `const_prop + dce + live_patch` 或 `wide_mem/endian_fusion`。

### 3.4 latest corpus 所有 applied programs 的逐程序表

| source | object | program | applied_passes | `map_inline` in applied_passes? | applied `map_inline` sites |
| --- | --- | --- | --- | --- | ---: |
| `bcc` | `corpus/build/bcc/libbpf-tools/bashreadline.bpf.o` | `printret` | `live_patch` | `no` | `0` |
| `bcc` | `corpus/build/bcc/libbpf-tools/biopattern.bpf.o` | `handle__block_rq_complete` | `const_prop, dce, live_patch` | `no` | `0` |
| `bcc` | `corpus/build/bcc/libbpf-tools/bitesize.bpf.o` | `block_rq_issue` | `const_prop, dce, live_patch` | `no` | `0` |
| `bcc` | `corpus/build/bcc/libbpf-tools/execsnoop.bpf.o` | `tracepoint__syscalls__sys_enter_execve` | `live_patch` | `no` | `0` |
| `bcc` | `corpus/build/bcc/libbpf-tools/filetop.bpf.o` | `vfs_read_entry` | `live_patch` | `no` | `0` |
| `bcc` | `corpus/build/bcc/libbpf-tools/klockstat.bpf.o` | `rtnetlink_rcv_msg` | `live_patch` | `no` | `0` |
| `bcc` | `corpus/build/bcc/libbpf-tools/llcstat.bpf.o` | `on_cache_miss` | `cond_select` | `no` | `0` |
| `bcc` | `corpus/build/bcc/libbpf-tools/mdflush.bpf.o` | `kprobe_md_flush_request` | `const_prop, dce, live_patch` | `no` | `0` |
| `bcc` | `corpus/build/bcc/libbpf-tools/mdflush.bpf.o` | `md_flush_request` | `const_prop, dce, live_patch` | `no` | `0` |
| `bcc` | `corpus/build/bcc/libbpf-tools/oomkill.bpf.o` | `oom_kill_process` | `const_prop, dce, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/from_hep_debug.bpf.o` | `calico_tc_maglev` | `const_prop, endian_fusion, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/from_hep_debug.bpf.o` | `calico_tc_main` | `const_prop, wide_mem, cond_select, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/from_hep_debug.bpf.o` | `calico_tc_skb_accepted_entrypoint` | `const_prop, cond_select, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/from_hep_debug.bpf.o` | `calico_tc_skb_drop` | `const_prop, endian_fusion, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/from_hep_debug.bpf.o` | `calico_tc_skb_icmp_inner_nat` | `const_prop, wide_mem, cond_select, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/from_hep_debug.bpf.o` | `calico_tc_skb_ipv4_frag` | `const_prop, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/from_hep_debug.bpf.o` | `calico_tc_skb_new_flow_entrypoint` | `const_prop` | `no` | `0` |
| `calico` | `corpus/build/calico/from_hep_debug.bpf.o` | `calico_tc_skb_send_icmp_replies` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/from_hep_debug.bpf.o` | `calico_tc_skb_send_tcp_rst` | `const_prop, wide_mem, extract, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/from_nat_debug.bpf.o` | `calico_tc_main` | `const_prop, wide_mem, cond_select, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/from_nat_debug.bpf.o` | `calico_tc_skb_accepted_entrypoint` | `const_prop, cond_select, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/from_nat_debug.bpf.o` | `calico_tc_skb_drop` | `const_prop, endian_fusion, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/from_nat_debug.bpf.o` | `calico_tc_skb_icmp_inner_nat` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/from_nat_debug.bpf.o` | `calico_tc_skb_ipv4_frag` | `const_prop, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/from_nat_debug.bpf.o` | `calico_tc_skb_new_flow_entrypoint` | `const_prop` | `no` | `0` |
| `calico` | `corpus/build/calico/from_nat_debug.bpf.o` | `calico_tc_skb_send_icmp_replies` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/from_nat_debug.bpf.o` | `calico_tc_skb_send_tcp_rst` | `const_prop, wide_mem, extract, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/from_wep_debug.bpf.o` | `calico_tc_main` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/from_wep_debug.bpf.o` | `calico_tc_skb_accepted_entrypoint` | `const_prop, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/from_wep_debug.bpf.o` | `calico_tc_skb_drop` | `const_prop, endian_fusion` | `no` | `0` |
| `calico` | `corpus/build/calico/from_wep_debug.bpf.o` | `calico_tc_skb_icmp_inner_nat` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/from_wep_debug.bpf.o` | `calico_tc_skb_ipv4_frag` | `const_prop, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/from_wep_debug.bpf.o` | `calico_tc_skb_new_flow_entrypoint` | `const_prop` | `no` | `0` |
| `calico` | `corpus/build/calico/from_wep_debug.bpf.o` | `calico_tc_skb_send_icmp_replies` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/from_wep_debug.bpf.o` | `calico_tc_skb_send_tcp_rst` | `const_prop, wide_mem, extract, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/to_hep_debug.bpf.o` | `calico_tc_host_ct_conflict` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/to_hep_debug.bpf.o` | `calico_tc_main` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/to_hep_debug.bpf.o` | `calico_tc_skb_accepted_entrypoint` | `const_prop, cond_select, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/to_hep_debug.bpf.o` | `calico_tc_skb_drop` | `const_prop, endian_fusion, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/to_hep_debug.bpf.o` | `calico_tc_skb_icmp_inner_nat` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/to_hep_debug.bpf.o` | `calico_tc_skb_ipv4_frag` | `const_prop, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/to_hep_debug.bpf.o` | `calico_tc_skb_new_flow_entrypoint` | `const_prop` | `no` | `0` |
| `calico` | `corpus/build/calico/to_hep_debug.bpf.o` | `calico_tc_skb_send_icmp_replies` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/to_hep_debug.bpf.o` | `calico_tc_skb_send_tcp_rst` | `const_prop, wide_mem, extract, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o` | `calico_tc_host_ct_conflict` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o` | `calico_tc_main` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o` | `calico_tc_skb_accepted_entrypoint` | `const_prop, cond_select, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o` | `calico_tc_skb_drop` | `const_prop, endian_fusion, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o` | `calico_tc_skb_icmp_inner_nat` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o` | `calico_tc_skb_ipv4_frag` | `const_prop, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o` | `calico_tc_skb_new_flow_entrypoint` | `const_prop` | `no` | `0` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o` | `calico_tc_skb_send_icmp_replies` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/to_nat_debug.bpf.o` | `calico_tc_skb_send_tcp_rst` | `const_prop, wide_mem, extract, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/to_wep_debug.bpf.o` | `calico_tc_main` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/to_wep_debug.bpf.o` | `calico_tc_skb_accepted_entrypoint` | `const_prop, cond_select, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/to_wep_debug.bpf.o` | `calico_tc_skb_drop` | `const_prop, endian_fusion` | `no` | `0` |
| `calico` | `corpus/build/calico/to_wep_debug.bpf.o` | `calico_tc_skb_icmp_inner_nat` | `const_prop, wide_mem, cond_select, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/to_wep_debug.bpf.o` | `calico_tc_skb_ipv4_frag` | `const_prop, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/to_wep_debug.bpf.o` | `calico_tc_skb_new_flow_entrypoint` | `const_prop` | `no` | `0` |
| `calico` | `corpus/build/calico/to_wep_debug.bpf.o` | `calico_tc_skb_send_icmp_replies` | `const_prop, wide_mem, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/to_wep_debug.bpf.o` | `calico_tc_skb_send_tcp_rst` | `const_prop, wide_mem, extract, endian_fusion, dangerous_helper_firewall` | `no` | `0` |
| `calico` | `corpus/build/calico/xdp_debug.bpf.o` | `calico_xdp_drop` | `endian_fusion` | `no` | `0` |
| `calico` | `corpus/build/calico/xdp_debug.bpf.o` | `calico_xdp_main` | `wide_mem, endian_fusion, dangerous_helper_firewall, live_patch` | `no` | `0` |
| `calico` | `corpus/build/calico/xdp_no_log.bpf.o` | `calico_xdp_main` | `wide_mem, endian_fusion, live_patch` | `no` | `0` |
| `libbpf-bootstrap` | `corpus/build/libbpf-bootstrap/examples/c/kprobe.bpf.o` | `do_unlinkat` | `live_patch` | `no` | `0` |
| `libbpf-bootstrap` | `corpus/build/libbpf-bootstrap/examples/c/ksyscall.bpf.o` | `tgkill_entry` | `live_patch` | `no` | `0` |
| `libbpf-bootstrap` | `corpus/build/libbpf-bootstrap/examples/c/task_iter.bpf.o` | `get_tasks` | `const_prop, dce, live_patch` | `no` | `0` |
| `libbpf-bootstrap` | `corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o` | `tc_ingress` | `endian_fusion` | `no` | `0` |
| `libbpf-bootstrap` | `corpus/build/libbpf-bootstrap/examples/c/usdt.bpf.o` | `usdt_auto_attach` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_map_elem.bpf.o` | `dump_bpf_map_values` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_netlink.bpf.o` | `dump_netlink` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_setsockopt.bpf.o` | `change_tcp_cc` | `endian_fusion` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_iter_unix.bpf.o` | `dump_unix` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_mod_race.bpf.o` | `widen_race` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_syscall_macro.bpf.o` | `handle_sys_prctl` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/decap_sanity.bpf.o` | `decap_sanity` | `skb_load_bytes_spec` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/ip_check_defrag.bpf.o` | `defrag` | `endian_fusion` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/loop6.bpf.o` | `trace_virtqueue_add_sgs` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/mptcp_sock.bpf.o` | `_sockops` | `const_prop, dce` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/netif_receive_skb.bpf.o` | `trace_netif_receive_skb` | `const_prop, dce` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o` | `res_spin_lock_test_held_lock_max` | `dangerous_helper_firewall` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/summarization.bpf.o` | `main_might_sleep_with_subprogs` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_assign_reuse.bpf.o` | `reuse_accept` | `const_prop, dce, wide_mem` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_assign_reuse.bpf.o` | `tc_main` | `endian_fusion` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_attach_probe.bpf.o` | `handle_kprobe_auto` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_btf_skc_cls_ingress.bpf.o` | `cls_ingress` | `endian_fusion` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_core_read_macros.bpf.o` | `handler` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_endian.bpf.o` | `sys_enter` | `endian_fusion` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ptr_untrusted.bpf.o` | `lsm_run` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_send_signal_kern.bpf.o` | `send_signal_tp` | `dangerous_helper_firewall` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skb_helpers.bpf.o` | `test_skb_helpers` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skc_to_unix_sock.bpf.o` | `unix_listen` | `const_prop` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_skmsg_load_helpers.bpf.o` | `prog_msg_verdict` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_subprogs.bpf.o` | `prog1` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_task_pt_regs.bpf.o` | `handle_uprobe` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o` | `__encap_sit_none` | `endian_fusion` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o` | `__encap_udp_eth` | `endian_fusion` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o` | `__encap_udp_mpls` | `endian_fusion` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o` | `__encap_udp_none` | `endian_fusion` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o` | `__encap_vxlan_eth` | `endian_fusion` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tc_tunnel.bpf.o` | `decap_f` | `wide_mem, endian_fusion` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_tcpbpf_kern.bpf.o` | `bpf_testcb` | `extract` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_urandom_usdt.bpf.o` | `urand_read_without_sema` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_usdt.bpf.o` | `usdt0` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_varlen.bpf.o` | `handler64_unsigned` | `live_patch` | `no` | `0` |
| `linux-selftests` | `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/uprobe_multi.bpf.o` | `uprobe` | `live_patch` | `no` | `0` |
| `real_world_code_size` | `corpus/build/real_world_code_size/libbpf-bootstrap/kprobe.bpf.o` | `do_unlinkat` | `live_patch` | `no` | `0` |
| `real_world_code_size` | `corpus/build/real_world_code_size/libbpf-bootstrap/ksyscall.bpf.o` | `tgkill_entry` | `live_patch` | `no` | `0` |
| `real_world_code_size` | `corpus/build/real_world_code_size/libbpf-bootstrap/task_iter.bpf.o` | `get_tasks` | `const_prop, dce, live_patch` | `no` | `0` |
| `real_world_code_size` | `corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o` | `tc_ingress` | `endian_fusion` | `no` | `0` |
| `real_world_code_size` | `corpus/build/real_world_code_size/libbpf-bootstrap/usdt.bpf.o` | `usdt_auto_attach` | `live_patch` | `no` | `0` |
| `scx` | `corpus/build/scx/scx_bpfland_main.bpf.o` | `bpfland_select_cpu` | `const_prop, dce` | `no` | `0` |
| `tetragon` | `corpus/build/tetragon/bpf_cgroup.bpf.o` | `tg_cgroup_rmdir` | `const_prop, dce, live_patch` | `no` | `0` |
| `tetragon` | `corpus/build/tetragon/bpf_cgroup_mkdir.bpf.o` | `tg_tp_cgrp_mkdir` | `const_prop, dce, live_patch` | `no` | `0` |
| `tetragon` | `corpus/build/tetragon/bpf_cgroup_release.bpf.o` | `tg_tp_cgrp_release` | `const_prop, dce, live_patch` | `no` | `0` |
| `tetragon` | `corpus/build/tetragon/bpf_cgroup_rmdir.bpf.o` | `tg_tp_cgrp_rmdir` | `const_prop, dce, live_patch` | `no` | `0` |
| `tetragon` | `corpus/build/tetragon/bpf_cgtracker.bpf.o` | `tg_cgtracker_cgroup_mkdir` | `const_prop, dce, live_patch` | `no` | `0` |
| `tetragon` | `corpus/build/tetragon/bpf_enforcer.bpf.o` | `kprobe_enforcer` | `dangerous_helper_firewall` | `no` | `0` |
| `tetragon` | `corpus/build/tetragon/bpf_execve_bprm_commit_creds.bpf.o` | `tg_kp_bprm_committing_creds` | `live_patch` | `no` | `0` |
| `tetragon` | `corpus/build/tetragon/bpf_fmodret_enforcer.bpf.o` | `fmodret_enforcer` | `dangerous_helper_firewall` | `no` | `0` |
| `tetragon` | `corpus/build/tetragon/bpf_multi_enforcer.bpf.o` | `kprobe_multi_enforcer` | `dangerous_helper_firewall` | `no` | `0` |
| `tracee` | `corpus/build/tracee/tracee.bpf.o` | `cgroup_skb_egress` | `const_prop, dce, wide_mem, endian_fusion` | `no` | `0` |
| `tracee` | `corpus/build/tracee/tracee.bpf.o` | `cgroup_skb_ingress` | `const_prop, dce, wide_mem, endian_fusion` | `no` | `0` |
| `tracee` | `corpus/build/tracee/tracee.bpf.o` | `trace_sys_enter` | `const_prop, dce` | `no` | `0` |
| `tracee` | `corpus/build/tracee/tracee.bpf.o` | `tracepoint__raw_syscalls__sys_enter` | `live_patch` | `no` | `0` |
| `xdp-tools` | `corpus/build/xdp-tools/xdp_forward.bpf.o` | `xdp_fwd_fib_direct` | `endian_fusion` | `no` | `0` |
| `xdp-tools` | `corpus/build/xdp-tools/xdp_forward.bpf.o` | `xdp_fwd_fib_full` | `endian_fusion` | `no` | `0` |
| `xdp-tutorial` | `corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o` | `_fix_port_egress` | `endian_fusion` | `no` | `0` |
| `xdp-tutorial` | `corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o` | `xdp_redirect_func` | `wide_mem` | `no` | `0` |
| `xdp-tutorial` | `corpus/build/xdp-tutorial/packet03-redirecting/xdp_prog_kern.bpf.o` | `xdp_redirect_map_func` | `wide_mem` | `no` | `0` |

## Step 4：latest E2E（Tracee / Katran / Tetragon）

| case | latest artifact | programs / cycles | ReJIT overall applied? | any successful `map_inline`? | observed inlined values |
| --- | --- | ---: | --- | --- | --- |
| `tracee` | `tracee_20260326_210504` | `27` | `false` | `false` | `none observed` |
| `tetragon` | `tetragon_20260326_210838` | `7` | `false` | `false` | `none observed` |
| `katran` | `katran_20260326_211701` | `3` | `false,false,false` | `false` | `none observed` |

补充说明：
- latest Tracee：`e2e/results/tracee_20260326_210504/details/result.json`，`rejit_result.applied=false`，27 个 per-program 结果里没有一个 `passes_applied` 含 `map_inline`。
- latest Tetragon：`e2e/results/tetragon_20260326_210838/details/result.json`，`rejit_result.applied=false`，7 个 per-program 结果里没有一个 `passes_applied` 含 `map_inline`。
- latest Katran：`e2e/results/katran_20260326_211701/details/result.json`，3 个 cycle 的 `rejit_result.applied` 都是 `false`，每个 cycle 的 `balancer_ingres` 也都没有 `map_inline`。
- 我还扫了仓库里全部 checked-in E2E metadata：Tracee `22` 个、Tetragon `21` 个、Katran `22` 个；其中 `map_inline.changed=true` 的 run 数分别是 `0` / `0` / `0`。

## 对“zero vs non-zero”问题的最终回答

如果只看**当前真实 VM benchmark / E2E / guest probe**，答案不是“现在主要在内联 0”，而是：

> **目前几乎没有真实 run 真的触发 `map_inline`，所以实际被内联的值是空集。**

更细一点：

- `vm-static-test`：没有 `map_inline`。
- latest corpus：没有 `map_inline`。
- latest Tracee / Katran / Tetragon E2E：没有 `map_inline`。
- 手工 live probe：即使 map 真实值分别是 `0` 和 `1`，也没有触发 `map_inline`。

所以现阶段最大的事实不是“zero-only”，而是“**real programs 里 `map_inline` 命中率几乎为零**”。

## 为什么现在很难直接看到 value bytes

当前 observability 有一个结构性缺口：

- pass 内部确实保存了 `MapInlineRecord.expected_value`。
- 但 CLI / serve 暴露出去的 `OptimizeOneResult` 只保留 `PassDetail`，没有 `map_inline_records`。
- 因此，只靠现在的 daemon debug JSON，无法直接列出“site -> value bytes”。

如果要把这个问题彻底观测清楚，最直接的工程改法是把 `map_inline_records`（至少 `map_id/key/expected_value`）串进 `OptimizeOneResult`，或者至少在 `map_inline.changed=true` 时把 value bytes 编码进 `diagnostics`。
