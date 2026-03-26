# Corpus Call Statistics (requested 20260326 output)

- Generated at: `2026-03-25T22:14:05-07:00`
- Corpus root: `/home/yunwei37/workspace/bpf-benchmark/corpus/build`
- Runner binary: `/home/yunwei37/workspace/bpf-benchmark/runner/build/micro_exec`
- Counting rule: object programs come from `micro_exec list-programs`; call counts scan all executable ELF sections (including `.text` subprog sections).
- Dangerous helpers counted: `override_return`=58, `send_signal`=109, `send_signal_thread`=117, `probe_write_user`=36, `probe_read`=4, `probe_read_str`=45, `probe_read_user`=112, `probe_read_user_str`=114, `probe_read_kernel`=113, `probe_read_kernel_str`=115, `copy_from_user`=148, `copy_from_user_task`=191, `d_path`=147

## Overall

| Objects | Projects | Programs | Exec Sections | Exec Insns | bpf2bpf Calls | tail_call Helpers | Dangerous Helper Calls | list-programs Failures |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 568 | 23 | 2019 | 1668 | 1495191 | 3427 | 537 | 59939 | 98 |

## Project Summary

| Project | Objects | Programs | Exec Sections | Exec Insns | bpf2bpf Calls | tail_call Helpers | Dangerous Helper Calls | list-programs Failures |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tracee | 2 | 170 | 158 | 436457 | 4 | 49 | 26240 | 0 |
| KubeArmor | 3 | 63 | 64 | 357155 | 15 | 0 | 24908 | 0 |
| tetragon | 23 | 90 | 38 | 172508 | 22 | 118 | 6609 | 0 |
| coroot-node-agent | 1 | 46 | 46 | 37060 | 0 | 0 | 1297 | 0 |
| bcc | 57 | 365 | 366 | 23707 | 99 | 0 | 547 | 0 |
| linux-selftests | 369 | 892 | 679 | 73958 | 1297 | 57 | 191 | 89 |
| xdp-tools | 13 | 99 | 58 | 9094 | 3 | 0 | 48 | 0 |
| real_world_code_size | 15 | 24 | 25 | 1072 | 6 | 0 | 22 | 0 |
| libbpf-bootstrap | 12 | 21 | 22 | 946 | 6 | 0 | 22 | 0 |
| scx | 4 | 85 | 81 | 34541 | 1952 | 0 | 21 | 0 |
| datadog-agent | 2 | 1 | 4 | 544 | 7 | 0 | 14 | 1 |
| opentelemetry-ebpf-profiler | 3 | 0 | 6 | 6058 | 0 | 5 | 14 | 3 |
| systemd | 8 | 16 | 18 | 737 | 8 | 0 | 6 | 0 |
| loxilb | 3 | 18 | 20 | 77619 | 5 | 34 | 0 | 0 |
| katran | 5 | 5 | 6 | 3013 | 3 | 3 | 0 | 0 |
| cilium | 3 | 0 | 9 | 97621 | 0 | 216 | 0 | 3 |
| calico | 8 | 59 | 8 | 158995 | 0 | 55 | 0 | 0 |
| xdp-tutorial | 25 | 51 | 42 | 2345 | 0 | 0 | 0 | 0 |
| tubular | 1 | 1 | 1 | 124 | 0 | 0 | 0 | 0 |
| suricata | 2 | 2 | 2 | 744 | 0 | 0 | 0 | 0 |
| netbird | 2 | 0 | 4 | 528 | 0 | 0 | 0 | 2 |
| manual-test | 2 | 4 | 4 | 48 | 0 | 0 | 0 | 0 |
| bpftrace | 5 | 7 | 7 | 317 | 0 | 0 | 0 | 0 |

Program counts above only include objects where `list-programs` succeeded; `98` objects had enumeration failures.

## list-programs Failure Reasons

| Count | Reason |
| --- | --- |
| 82 | no program found in object |
| 8 | bpf_object__open_file failed: Operation not supported |
| 8 | bpf_object__open_file failed: No such file or directory |

## Dangerous Helper Breakdown By Project

| Project | override_return (58) | send_signal (109) | send_signal_thread (117) | probe_write_user (36) | probe_read (4) | probe_read_str (45) | probe_read_user (112) | probe_read_user_str (114) | probe_read_kernel (113) | probe_read_kernel_str (115) | copy_from_user (148) | copy_from_user_task (191) | d_path (147) |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tracee | 0 | 0 | 0 | 0 | 2103 | 719 | 12 | 0 | 21732 | 1674 | 0 | 0 | 0 |
| KubeArmor | 0 | 0 | 0 | 0 | 18847 | 3372 | 0 | 1 | 2688 | 0 | 0 | 0 | 0 |
| tetragon | 3 | 4 | 0 | 4 | 6253 | 67 | 11 | 0 | 257 | 0 | 10 | 0 | 0 |
| coroot-node-agent | 0 | 0 | 0 | 0 | 1278 | 18 | 0 | 0 | 1 | 0 | 0 | 0 | 0 |
| bcc | 0 | 0 | 0 | 0 | 0 | 0 | 64 | 77 | 387 | 19 | 0 | 0 | 0 |
| linux-selftests | 0 | 3 | 3 | 1 | 0 | 0 | 27 | 0 | 118 | 19 | 13 | 2 | 5 |
| xdp-tools | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 48 | 0 | 0 | 0 | 0 |
| real_world_code_size | 0 | 0 | 0 | 0 | 0 | 2 | 1 | 0 | 18 | 1 | 0 | 0 | 0 |
| libbpf-bootstrap | 0 | 0 | 0 | 0 | 0 | 2 | 1 | 0 | 18 | 1 | 0 | 0 | 0 |
| scx | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 8 | 13 | 0 | 0 | 0 |
| datadog-agent | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 14 | 0 | 0 | 0 | 0 |
| opentelemetry-ebpf-profiler | 0 | 0 | 0 | 0 | 0 | 0 | 10 | 0 | 4 | 0 | 0 | 0 | 0 |
| systemd | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 6 | 0 | 0 | 0 | 0 |
| loxilb | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| katran | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| cilium | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| calico | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| xdp-tutorial | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| tubular | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| suricata | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| netbird | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| manual-test | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| bpftrace | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

## Top Objects By bpf2bpf Calls

| Project | Object | bpf2bpf Calls | Programs | Exec Insns |
| --- | --- | --- | --- | --- |
| scx | corpus/build/scx/scx_lavd_main.bpf.o | 1219 | 46 | 23128 |
| scx | corpus/build/scx/scx_rusty_main.bpf.o | 285 | 13 | 6043 |
| scx | corpus/build/scx/scx_flash_main.bpf.o | 281 | 14 | 3357 |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_ksyms_module.bpf.o | 259 | 2 | 532 |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o | 205 | 23 | 1612 |
| scx | corpus/build/scx/scx_bpfland_main.bpf.o | 167 | 12 | 2013 |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_bpf_nf.bpf.o | 80 | 2 | 952 |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/map_kptr.bpf.o | 65 | 13 | 1543 |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_kfunc_prog_types.bpf.o | 56 | 12 | 180 |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/verifier_bits_iter.bpf.o | 46 | 13 | 345 |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_failure.bpf.o | 45 | 12 | 315 |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/task_kfunc_failure.bpf.o | 36 | 20 | 324 |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_usdt.bpf.o | 29 | 4 | 873 |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_success.bpf.o | 28 | 7 | 383 |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cgrp_kfunc_failure.bpf.o | 27 | 13 | 205 |

## Top Objects By tail_call Helper Calls

| Project | Object | tail_call Helpers | Programs | Exec Insns |
| --- | --- | --- | --- | --- |
| cilium | corpus/build/cilium/bpf_lxc.bpf.o | 129 | 0 | 41881 |
| cilium | corpus/build/cilium/bpf_overlay.bpf.o | 58 | 0 | 29611 |
| linux-selftests | corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/bpf_flow.bpf.o | 53 | 7 | 2860 |
| tracee | corpus/build/tracee/tracee.bpf.o | 49 | 169 | 436443 |
| cilium | corpus/build/cilium/bpf_xdp.bpf.o | 29 | 0 | 26129 |
| tetragon | corpus/build/tetragon/bpf_generic_uprobe.bpf.o | 20 | 13 | 21548 |
| tetragon | corpus/build/tetragon/bpf_generic_kprobe.bpf.o | 20 | 12 | 19321 |
| loxilb | corpus/build/loxilb/llb_ebpf_emain.bpf.o | 17 | 8 | 37938 |
| loxilb | corpus/build/loxilb/llb_ebpf_main.bpf.o | 17 | 8 | 37895 |
| tetragon | corpus/build/tetragon/bpf_generic_rawtp.bpf.o | 16 | 9 | 16287 |
| tetragon | corpus/build/tetragon/bpf_generic_usdt.bpf.o | 15 | 12 | 19633 |
| tetragon | corpus/build/tetragon/bpf_generic_tracepoint.bpf.o | 15 | 8 | 17605 |
| calico | corpus/build/calico/from_hep_debug.bpf.o | 13 | 9 | 28053 |
| tetragon | corpus/build/tetragon/bpf_generic_lsm_core.bpf.o | 12 | 7 | 50785 |
| calico | corpus/build/calico/to_hep_debug.bpf.o | 10 | 9 | 30897 |

## Top Objects By Dangerous Helper Calls

| Project | Object | Dangerous Helper Calls | Programs | Exec Insns |
| --- | --- | --- | --- | --- |
| tracee | corpus/build/tracee/tracee.bpf.o | 26240 | 169 | 436443 |
| KubeArmor | corpus/build/KubeArmor/system_monitor.bpf.o | 22987 | 55 | 323003 |
| tetragon | corpus/build/tetragon/bpf_generic_lsm_core.bpf.o | 2967 | 7 | 50785 |
| KubeArmor | corpus/build/KubeArmor/enforcer.bpf.o | 1557 | 7 | 29013 |
| coroot-node-agent | corpus/build/coroot-node-agent/ebpf.bpf.o | 1297 | 46 | 37060 |
| tetragon | corpus/build/tetragon/bpf_generic_uprobe.bpf.o | 631 | 13 | 21548 |
| tetragon | corpus/build/tetragon/bpf_generic_kprobe.bpf.o | 625 | 12 | 19321 |
| tetragon | corpus/build/tetragon/bpf_generic_usdt.bpf.o | 576 | 12 | 19633 |
| tetragon | corpus/build/tetragon/bpf_generic_rawtp.bpf.o | 516 | 9 | 16287 |
| tetragon | corpus/build/tetragon/bpf_generic_tracepoint.bpf.o | 439 | 8 | 17605 |
| KubeArmor | corpus/build/KubeArmor/protectproc.bpf.o | 364 | 1 | 5139 |
| tetragon | corpus/build/tetragon/bpf_generic_retuprobe.bpf.o | 244 | 5 | 9531 |
| tetragon | corpus/build/tetragon/bpf_generic_retkprobe.bpf.o | 244 | 5 | 9531 |
| tetragon | corpus/build/tetragon/bpf_execve_event.bpf.o | 213 | 3 | 4497 |
| bcc | corpus/build/bcc/libbpf-tools/execsnoop.bpf.o | 122 | 2 | 2300 |
