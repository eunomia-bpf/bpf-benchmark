# Real-World Code-Size Validation

- Generated at: `2026-03-07T23:08:42.939988+00:00`
- Inventory: `/home/yunwei37/workspace/bpf-benchmark/corpus/inventory.json`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Corpora: `libbpf-bootstrap`, `bcf/cilium`, `bcf/inspektor-gadget`, `bcf/collected`
- Runtimes: `llvmbpf`, `kernel`

## Summary

| Metric | Value |
| --- | ---: |
| Input artifacts considered | 77 |
| Artifact prepare/build succeeded | 77 |
| Program inventories succeeded | 77 |
| Programs discovered | 949 |
| Programs with both runtimes ok | 162 |
| Geomean native code-size ratio (llvmbpf/kernel) | 0.618x |

## Runtime Status

| Runtime | ok | error | timeout |
| --- | ---: | ---: | ---: |
| llvmbpf | 948 | 1 | 0 |
| kernel | 162 | 787 | 0 |

## llvmbpf Failures

| Error summary | Count |
| --- | ---: |
| llvmbpf compile failed: Instruction at pc=125 is going to jump to an illegal position 125 | 1 |

## kernel Failures

| Error summary | Count |
| --- | ---: |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-14_-O1_bpf_lxc.o ... | 28 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-15_-O1_bpf_lxc.o ... | 28 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-16_-O1_bpf_lxc.o ... | 28 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-17_-O1_bpf_lxc.o ... | 28 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-18_-O1_bpf_lxc.o ... | 28 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-19_-O1_bpf_lxc.o ... | 28 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-20_-O1_bpf_lxc.o ... | 28 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-21_-O1_bpf_lxc.o ... | 28 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-14_-O1_bpf_host.o ... | 27 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-15_-O1_bpf_host.o ... | 27 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-16_-O1_bpf_host.o ... | 27 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-17_-O1_bpf_host.o ... | 27 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-18_-O1_bpf_host.o ... | 27 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-19_-O1_bpf_host.o ... | 27 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-20_-O1_bpf_host.o ... | 27 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-21_-O1_bpf_host.o ... | 27 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-14_-O1_bpf_overlay.o ... | 18 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-15_-O1_bpf_overlay.o ... | 18 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-16_-O1_bpf_overlay.o ... | 18 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-17_-O1_bpf_overlay.o ... | 18 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-18_-O1_bpf_overlay.o ... | 18 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-19_-O1_bpf_overlay.o ... | 18 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-20_-O1_bpf_overlay.o ... | 18 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-21_-O1_bpf_overlay.o ... | 18 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-14_-O1_bpf_wireguard.o ... | 17 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-15_-O1_bpf_wireguard.o ... | 17 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-16_-O1_bpf_wireguard.o ... | 17 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-17_-O1_bpf_wireguard.o ... | 17 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-18_-O1_bpf_wireguard.o ... | 17 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-19_-O1_bpf_wireguard.o ... | 17 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-20_-O1_bpf_wireguard.o ... | 17 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-21_-O1_bpf_wireguard.o ... | 17 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-20_-O1_bpf_xdp.o ... | 12 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-21_-O1_bpf_xdp.o ... | 12 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-14_-O1_bpf_sock.o ... | 4 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-15_-O1_bpf_sock.o ... | 4 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-16_-O1_bpf_sock.o ... | 4 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-17_-O1_bpf_sock.o ... | 2 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-18_-O1_bpf_sock.o ... | 2 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-19_-O1_bpf_sock.o ... | 2 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-20_-O1_bpf_sock.o ... | 2 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/cilium/clang-21_-O1_bpf_sock.o ... | 2 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/collected/ksnoop.bpf.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/collected/shift_constraint.bpf.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/collected/stack_ptr_varoff.bpf.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/collected/system_monitor.bpf.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/collected/tcp_conn_tuner.bpf.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/collected/test_get_stack_rawtp.bpf.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/collected/trace_sys_enter_execve.bpf.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/collected/unreachable_arsh.bpf.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/collected/xdp_synproxy_kern.bpf.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/inspektor-gadget/clang-19_-O1_seccomp_x86_bpfel.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/inspektor-gadget/clang-19_-O2_seccomp_x86_bpfel.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/inspektor-gadget/clang-19_-O3_seccomp_x86_bpfel.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/inspektor-gadget/clang-19_-Os_seccomp_x86_bpfel.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/inspektor-gadget/clang-20_-O1_seccomp_x86_bpfel.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/inspektor-gadget/clang-20_-O2_seccomp_x86_bpfel.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/inspektor-gadget/clang-20_-O3_seccomp_x86_bpfel.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/inspektor-gadget/clang-20_-Os_seccomp_x86_bpfel.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/inspektor-gadget/clang-21_-O2_seccomp_x86_bpfel.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/inspektor-gadget/clang-21_-O3_seccomp_x86_bpfel.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/bcf/inspektor-gadget/clang-21_-Os_seccomp_x86_bpfel.o ... | 1 |
| libbpf: loading object from /home/yunwei37/workspace/bpf-benchmark/corpus/build/real_world_code_size/libbpf-bootstrap/lsm.bpf.o ... | 1 |

## Program-Level Results

| Repo | Artifact | Program | Section | BPF insns | llvmbpf native B | kernel native B | L/K ratio |
| --- | --- | --- | --- | ---: | ---: | ---: | ---: |
| bcf/cilium | `clang-14_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 101 | 90 | 602 | 0.150x |
| bcf/cilium | `clang-15_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 101 | 90 | 602 | 0.150x |
| bcf/cilium | `clang-16_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 101 | 90 | 602 | 0.150x |
| bcf/cilium | `clang-17_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 101 | 90 | 602 | 0.150x |
| bcf/cilium | `clang-18_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 101 | 90 | 602 | 0.150x |
| bcf/cilium | `clang-19_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 101 | 90 | 602 | 0.150x |
| bcf/cilium | `clang-20_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 101 | 90 | 602 | 0.150x |
| bcf/cilium | `clang-21_-O1_bpf_wireguard.o` | `cil_to_wireguard` | `tc` | 101 | 90 | 602 | 0.150x |
| libbpf-bootstrap | `examples/c/bootstrap.bpf.c` | `handle_exit` | `tp/sched/sched_process_exit` | 85 | 94 | 383 | 0.245x |
| libbpf-bootstrap | `examples/c/bootstrap.bpf.c` | `handle_exec` | `tp/sched/sched_process_exec` | 63 | 103 | 292 | 0.353x |
| libbpf-bootstrap | `examples/c/bootstrap_legacy.bpf.c` | `handle_exit` | `tp/sched/sched_process_exit` | 105 | 215 | 569 | 0.378x |
| libbpf-bootstrap | `examples/c/fentry.bpf.c` | `do_unlinkat` | `fentry/do_unlinkat` | 11 | 36 | 91 | 0.396x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 111 | 287 | 713 | 0.403x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 111 | 287 | 713 | 0.403x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 111 | 287 | 713 | 0.403x |
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 111 | 287 | 713 | 0.403x |
| bcf/cilium | `clang-18_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 110 | 287 | 709 | 0.405x |
| bcf/cilium | `clang-19_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 110 | 287 | 709 | 0.405x |
| bcf/cilium | `clang-20_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 110 | 287 | 709 | 0.405x |
| bcf/cilium | `clang-21_-O1_bpf_lxc.o` | `cil_from_container` | `tc` | 110 | 287 | 709 | 0.405x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 272 | 638 | 1551 | 0.411x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 272 | 638 | 1551 | 0.411x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 270 | 658 | 1547 | 0.425x |
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 270 | 658 | 1547 | 0.425x |
| bcf/cilium | `clang-18_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 264 | 653 | 1533 | 0.426x |
| bcf/cilium | `clang-19_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 264 | 653 | 1533 | 0.426x |
| bcf/cilium | `clang-20_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 264 | 653 | 1533 | 0.426x |
| bcf/cilium | `clang-21_-O1_bpf_lxc.o` | `cil_to_container` | `tc` | 264 | 653 | 1533 | 0.426x |
| libbpf-bootstrap | `examples/c/minimal.bpf.c` | `handle_tp` | `tp/syscalls/sys_enter_write` | 13 | 30 | 67 | 0.448x |
| libbpf-bootstrap | `examples/c/bootstrap_legacy.bpf.c` | `handle_exec` | `tp/sched/sched_process_exec` | 81 | 212 | 452 | 0.469x |
| bcf/cilium | `clang-14_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 211 | 606 | 1226 | 0.494x |
| bcf/cilium | `clang-14_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 206 | 599 | 1207 | 0.496x |
| bcf/cilium | `clang-15_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 206 | 599 | 1207 | 0.496x |
| bcf/cilium | `clang-16_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 206 | 599 | 1207 | 0.496x |
| bcf/cilium | `clang-17_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 206 | 599 | 1207 | 0.496x |
| bcf/cilium | `clang-15_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 209 | 611 | 1218 | 0.502x |
| bcf/cilium | `clang-18_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 206 | 606 | 1207 | 0.502x |
| bcf/cilium | `clang-19_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 206 | 606 | 1207 | 0.502x |
| bcf/cilium | `clang-20_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 206 | 606 | 1207 | 0.502x |
| bcf/cilium | `clang-21_-O1_bpf_overlay.o` | `cil_from_overlay` | `tc` | 206 | 606 | 1207 | 0.502x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 89 | 276 | 548 | 0.504x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 89 | 276 | 548 | 0.504x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 89 | 276 | 548 | 0.504x |
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 89 | 276 | 548 | 0.504x |
| bcf/cilium | `clang-18_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 89 | 276 | 548 | 0.504x |
| bcf/cilium | `clang-19_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 89 | 276 | 548 | 0.504x |
| bcf/cilium | `clang-20_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 89 | 276 | 548 | 0.504x |
| bcf/cilium | `clang-21_-O1_bpf_lxc.o` | `handle_policy_egress` | `tc` | 89 | 276 | 548 | 0.504x |
| bcf/cilium | `clang-16_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 206 | 611 | 1212 | 0.504x |
| bcf/cilium | `clang-17_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 206 | 611 | 1212 | 0.504x |
| bcf/cilium | `clang-18_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 206 | 611 | 1212 | 0.504x |
| bcf/cilium | `clang-19_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 206 | 611 | 1212 | 0.504x |
| bcf/cilium | `clang-20_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 206 | 611 | 1212 | 0.504x |
| bcf/cilium | `clang-21_-O1_bpf_overlay.o` | `cil_to_overlay` | `tc` | 206 | 611 | 1212 | 0.504x |
| bcf/cilium | `clang-14_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 88 | 276 | 545 | 0.506x |
| bcf/cilium | `clang-15_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 88 | 276 | 545 | 0.506x |
| bcf/cilium | `clang-16_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 88 | 276 | 545 | 0.506x |
| bcf/cilium | `clang-17_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 88 | 276 | 545 | 0.506x |
| bcf/cilium | `clang-18_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 88 | 276 | 545 | 0.506x |
| bcf/cilium | `clang-19_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 88 | 276 | 545 | 0.506x |
| bcf/cilium | `clang-20_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 88 | 276 | 545 | 0.506x |
| bcf/cilium | `clang-21_-O1_bpf_lxc.o` | `handle_policy` | `tc` | 88 | 276 | 545 | 0.506x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 1127 | 3090 | 5788 | 0.534x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 1127 | 3090 | 5788 | 0.534x |
| libbpf-bootstrap | `examples/c/fentry.bpf.c` | `do_unlinkat_exit` | `fexit/do_unlinkat` | 13 | 55 | 102 | 0.539x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 1143 | 3189 | 5904 | 0.540x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 1139 | 3246 | 5893 | 0.551x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 1133 | 3245 | 5870 | 0.553x |
| libbpf-bootstrap | `examples/c/uprobe.bpf.c` | `uprobe_add` | `uprobe` | 8 | 25 | 45 | 0.556x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 1133 | 3257 | 5860 | 0.556x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 1131 | 3256 | 5811 | 0.560x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `cil_from_netdev` | `tc` | 1131 | 3256 | 5811 | 0.560x |
| libbpf-bootstrap | `examples/c/ksyscall.bpf.c` | `tgkill_entry` | `ksyscall/tgkill` | 84 | 180 | 315 | 0.571x |
| libbpf-bootstrap | `examples/c/minimal_ns.bpf.c` | `handle_tp` | `tp/syscalls/sys_enter_write` | 21 | 64 | 110 | 0.582x |
| libbpf-bootstrap | `examples/c/uprobe.bpf.c` | `uretprobe_add` | `uretprobe` | 7 | 24 | 41 | 0.585x |
| libbpf-bootstrap | `examples/c/uprobe.bpf.c` | `uretprobe_sub` | `uretprobe//proc/self/exe:uprobed_sub` | 7 | 24 | 41 | 0.585x |
| libbpf-bootstrap | `examples/c/uprobe.bpf.c` | `uprobe_sub` | `uprobe//proc/self/exe:uprobed_sub` | 8 | 28 | 45 | 0.622x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `cil_from_host` | `tc` | 1016 | 3298 | 5067 | 0.651x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `cil_from_host` | `tc` | 1016 | 3298 | 5067 | 0.651x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `cil_from_host` | `tc` | 996 | 3329 | 5096 | 0.653x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `cil_from_host` | `tc` | 996 | 3329 | 5096 | 0.653x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `cil_from_host` | `tc` | 998 | 3296 | 5036 | 0.654x |
| libbpf-bootstrap | `examples/c/task_iter.bpf.c` | `get_tasks` | `iter/task` | 45 | 159 | 239 | 0.665x |
| libbpf-bootstrap | `examples/c/kprobe.bpf.c` | `do_unlinkat_exit` | `kretprobe/do_unlinkat` | 11 | 39 | 58 | 0.672x |
| libbpf-bootstrap | `examples/c/ksyscall.bpf.c` | `entry_probe` | `ksyscall/kill` | 57 | 155 | 230 | 0.674x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `cil_from_host` | `tc` | 995 | 3459 | 5098 | 0.679x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `cil_from_host` | `tc` | 1008 | 3506 | 5055 | 0.694x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `cil_from_host` | `tc` | 1008 | 3506 | 5055 | 0.694x |
| libbpf-bootstrap | `examples/c/tc.bpf.c` | `tc_ingress` | `tc` | 18 | 73 | 100 | 0.730x |
| bcf/cilium | `clang-14_-O1_bpf_sock.o` | `cil_sock6_recvmsg` | `cgroup/recvmsg6` | 576 | 2287 | 2846 | 0.804x |
| bcf/cilium | `clang-14_-O1_bpf_sock.o` | `cil_sock4_recvmsg` | `cgroup/recvmsg4` | 225 | 943 | 1145 | 0.824x |
| bcf/cilium | `clang-15_-O1_bpf_sock.o` | `cil_sock4_recvmsg` | `cgroup/recvmsg4` | 225 | 943 | 1145 | 0.824x |
| bcf/cilium | `clang-17_-O1_bpf_sock.o` | `cil_sock6_recvmsg` | `cgroup/recvmsg6` | 581 | 2352 | 2848 | 0.826x |
| bcf/cilium | `clang-17_-O1_bpf_sock.o` | `cil_sock4_recvmsg` | `cgroup/recvmsg4` | 225 | 943 | 1141 | 0.826x |
| bcf/cilium | `clang-18_-O1_bpf_sock.o` | `cil_sock6_recvmsg` | `cgroup/recvmsg6` | 581 | 2361 | 2853 | 0.828x |
| bcf/cilium | `clang-19_-O1_bpf_sock.o` | `cil_sock6_recvmsg` | `cgroup/recvmsg6` | 581 | 2361 | 2853 | 0.828x |
| bcf/cilium | `clang-20_-O1_bpf_sock.o` | `cil_sock6_recvmsg` | `cgroup/recvmsg6` | 581 | 2361 | 2853 | 0.828x |
| bcf/cilium | `clang-21_-O1_bpf_sock.o` | `cil_sock6_recvmsg` | `cgroup/recvmsg6` | 581 | 2361 | 2853 | 0.828x |
| bcf/cilium | `clang-16_-O1_bpf_sock.o` | `cil_sock4_recvmsg` | `cgroup/recvmsg4` | 221 | 943 | 1133 | 0.832x |
| bcf/cilium | `clang-17_-O1_bpf_sock.o` | `cil_sock6_connect` | `cgroup/connect6` | 1198 | 4788 | 5746 | 0.833x |
| bcf/cilium | `clang-18_-O1_bpf_sock.o` | `cil_sock4_recvmsg` | `cgroup/recvmsg4` | 225 | 951 | 1141 | 0.833x |
| bcf/cilium | `clang-19_-O1_bpf_sock.o` | `cil_sock4_recvmsg` | `cgroup/recvmsg4` | 225 | 951 | 1141 | 0.833x |
| bcf/cilium | `clang-20_-O1_bpf_sock.o` | `cil_sock4_recvmsg` | `cgroup/recvmsg4` | 225 | 951 | 1141 | 0.833x |
| bcf/cilium | `clang-21_-O1_bpf_sock.o` | `cil_sock4_recvmsg` | `cgroup/recvmsg4` | 225 | 951 | 1141 | 0.833x |
| bcf/cilium | `clang-15_-O1_bpf_sock.o` | `cil_sock6_recvmsg` | `cgroup/recvmsg6` | 571 | 2355 | 2825 | 0.834x |
| bcf/cilium | `clang-14_-O1_bpf_sock.o` | `cil_sock6_post_bind` | `cgroup/post_bind6` | 211 | 857 | 1023 | 0.838x |
| bcf/cilium | `clang-16_-O1_bpf_sock.o` | `cil_sock6_recvmsg` | `cgroup/recvmsg6` | 565 | 2355 | 2807 | 0.839x |
| bcf/cilium | `clang-17_-O1_bpf_sock.o` | `cil_sock6_sendmsg` | `cgroup/sendmsg6` | 1178 | 4731 | 5609 | 0.843x |
| libbpf-bootstrap | `examples/c/kprobe.bpf.c` | `do_unlinkat` | `kprobe/do_unlinkat` | 19 | 83 | 98 | 0.847x |
| bcf/cilium | `clang-14_-O1_bpf_sock.o` | `cil_sock4_post_bind` | `cgroup/post_bind4` | 96 | 404 | 475 | 0.851x |
| bcf/cilium | `clang-15_-O1_bpf_sock.o` | `cil_sock4_post_bind` | `cgroup/post_bind4` | 96 | 404 | 475 | 0.851x |
| bcf/cilium | `clang-17_-O1_bpf_sock.o` | `cil_sock4_post_bind` | `cgroup/post_bind4` | 96 | 404 | 475 | 0.851x |
| bcf/cilium | `clang-18_-O1_bpf_sock.o` | `cil_sock4_post_bind` | `cgroup/post_bind4` | 96 | 404 | 475 | 0.851x |
| bcf/cilium | `clang-19_-O1_bpf_sock.o` | `cil_sock4_post_bind` | `cgroup/post_bind4` | 96 | 404 | 475 | 0.851x |
| bcf/cilium | `clang-20_-O1_bpf_sock.o` | `cil_sock4_post_bind` | `cgroup/post_bind4` | 96 | 404 | 475 | 0.851x |
| bcf/cilium | `clang-21_-O1_bpf_sock.o` | `cil_sock4_post_bind` | `cgroup/post_bind4` | 96 | 404 | 475 | 0.851x |
| bcf/cilium | `clang-15_-O1_bpf_sock.o` | `cil_sock6_post_bind` | `cgroup/post_bind6` | 209 | 864 | 1010 | 0.855x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `cil_to_host` | `tc` | 804 | 3368 | 3935 | 0.856x |
| bcf/cilium | `clang-16_-O1_bpf_sock.o` | `cil_sock4_post_bind` | `cgroup/post_bind4` | 94 | 404 | 471 | 0.858x |
| bcf/cilium | `clang-16_-O1_bpf_sock.o` | `cil_sock6_post_bind` | `cgroup/post_bind6` | 205 | 864 | 1001 | 0.863x |
| bcf/cilium | `clang-17_-O1_bpf_sock.o` | `cil_sock6_post_bind` | `cgroup/post_bind6` | 212 | 880 | 1019 | 0.864x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `cil_to_host` | `tc` | 791 | 3368 | 3887 | 0.866x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `cil_to_host` | `tc` | 792 | 3368 | 3886 | 0.867x |
| libbpf-bootstrap | `examples/c/profile.bpf.c` | `profile` | `perf_event` | 45 | 198 | 227 | 0.872x |
| libbpf-bootstrap | `examples/c/usdt.bpf.c` | `usdt_manual_attach` | `usdt` | 26 | 570 | 653 | 0.873x |
| bcf/cilium | `clang-18_-O1_bpf_sock.o` | `cil_sock6_post_bind` | `cgroup/post_bind6` | 210 | 887 | 1016 | 0.873x |
| bcf/cilium | `clang-19_-O1_bpf_sock.o` | `cil_sock6_post_bind` | `cgroup/post_bind6` | 210 | 887 | 1016 | 0.873x |
| bcf/cilium | `clang-20_-O1_bpf_sock.o` | `cil_sock6_post_bind` | `cgroup/post_bind6` | 210 | 887 | 1016 | 0.873x |
| bcf/cilium | `clang-21_-O1_bpf_sock.o` | `cil_sock6_post_bind` | `cgroup/post_bind6` | 210 | 887 | 1016 | 0.873x |
| bcf/cilium | `clang-18_-O1_bpf_sock.o` | `cil_sock6_connect` | `cgroup/connect6` | 1197 | 5173 | 5746 | 0.900x |
| bcf/cilium | `clang-19_-O1_bpf_sock.o` | `cil_sock6_connect` | `cgroup/connect6` | 1197 | 5173 | 5746 | 0.900x |
| bcf/cilium | `clang-20_-O1_bpf_sock.o` | `cil_sock6_connect` | `cgroup/connect6` | 1197 | 5173 | 5746 | 0.900x |
| bcf/cilium | `clang-21_-O1_bpf_sock.o` | `cil_sock6_connect` | `cgroup/connect6` | 1197 | 5173 | 5746 | 0.900x |
| bcf/cilium | `clang-18_-O1_bpf_sock.o` | `cil_sock6_sendmsg` | `cgroup/sendmsg6` | 1182 | 5113 | 5639 | 0.907x |
| bcf/cilium | `clang-19_-O1_bpf_sock.o` | `cil_sock6_sendmsg` | `cgroup/sendmsg6` | 1182 | 5113 | 5639 | 0.907x |
| bcf/cilium | `clang-20_-O1_bpf_sock.o` | `cil_sock6_sendmsg` | `cgroup/sendmsg6` | 1182 | 5113 | 5639 | 0.907x |
| bcf/cilium | `clang-21_-O1_bpf_sock.o` | `cil_sock6_sendmsg` | `cgroup/sendmsg6` | 1182 | 5113 | 5639 | 0.907x |
| libbpf-bootstrap | `examples/c/sockfilter.bpf.c` | `socket_handler` | `socket` | 72 | 336 | 363 | 0.926x |
| bcf/collected | `ksnoop.bpf.o` | `kprobe_return` | `kretprobe/foo` | 4 | 2359 | 2517 | 0.937x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 3680 | 17766 | 18231 | 0.974x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `cil_to_host` | `tc` | 795 | 3771 | 3868 | 0.975x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `cil_to_host` | `tc` | 795 | 3771 | 3868 | 0.975x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `cil_to_host` | `tc` | 795 | 3771 | 3868 | 0.975x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `cil_to_host` | `tc` | 795 | 3771 | 3864 | 0.976x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `cil_to_host` | `tc` | 804 | 3820 | 3911 | 0.977x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 3620 | 17687 | 18005 | 0.982x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 3638 | 17751 | 17990 | 0.987x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 3638 | 17751 | 17990 | 0.987x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 3620 | 17813 | 18015 | 0.989x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 3701 | 18018 | 18182 | 0.991x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 3643 | 17934 | 17964 | 0.998x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `cil_to_netdev` | `tc` | 3704 | 18335 | 18130 | 1.011x |
| bcf/cilium | `clang-15_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 2380 | 11760 | 11621 | 1.012x |
| bcf/cilium | `clang-14_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 2369 | 11807 | 11511 | 1.026x |
| libbpf-bootstrap | `examples/c/minimal_legacy.bpf.c` | `handle_tp` | `tp/syscalls/sys_enter_write` | 33 | 185 | 178 | 1.039x |
| bcf/cilium | `clang-17_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 2373 | 12167 | 11609 | 1.048x |
| bcf/cilium | `clang-16_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 2356 | 12339 | 11527 | 1.070x |
| libbpf-bootstrap | `examples/c/usdt.bpf.c` | `usdt_auto_attach` | `usdt/libc.so.6:libc:setjmp` | 33 | 734 | 683 | 1.075x |
| bcf/cilium | `clang-18_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 2379 | 12568 | 11668 | 1.077x |
| bcf/cilium | `clang-20_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 2384 | 12637 | 11673 | 1.083x |
| bcf/cilium | `clang-21_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 2384 | 12637 | 11673 | 1.083x |
| bcf/cilium | `clang-19_-O1_bpf_host.o` | `handle_lxc_traffic` | `tc` | 2379 | 12613 | 11645 | 1.083x |

## Notes

- Each row is a single program selected from either a source-built or prebuilt real BPF object, not a handcrafted micro benchmark.
- `micro_exec list-programs` enumerates every libbpf-visible program in the object, and both runtimes are invoked with `--program-name` so multi-program objects are measured per program.
- `libbpf-bootstrap` inputs are compiled from source; the integrated BCF inputs are scanned directly from prebuilt objects under `corpus/bcf/`.
- The curated default set keeps the run focused on corpora that are already loadable by the current tooling: `libbpf-bootstrap`, `bcf/cilium`, `bcf/inspektor-gadget`, and `bcf/collected`.
