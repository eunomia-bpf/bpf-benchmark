# Batch Code-Size Comparison

- Runner: `micro/build/runner/micro_exec`
- Inputs: `corpus/bcf/collected/*.bpf.o`, `corpus/bcf/bcc/*.bpf.o`, `corpus/build/real_world_code_size/libbpf-bootstrap/*.bpf.o`

## Summary

| Metric | Value |
| --- | ---: |
| Input files | 32 |
| Files kept | 21 |
| Files skipped (both runtimes failed) | 11 |
| Program rows kept | 30 |
| Program rows skipped (both runtimes failed) | 20 |
| llvmbpf successes | 21 |
| kernel successes | 24 |
| Paired ratios | 15 |
| Geomean llvmbpf/kernel native ratio | 0.618x |

## Program Results

| File | Program | Section | BPF insns | llvmbpf native B | kernel native B | L/K ratio | Notes |
| --- | --- | --- | ---: | ---: | ---: | ---: | --- |
| `corpus/bcf/collected/ksnoop.bpf.o` | `kprobe_return` | `kretprobe/foo` | 4 | - | 2517 | - | llvmbpf: unsupported llvmbpf map type: 5 |
| `corpus/bcf/collected/shift_constraint.bpf.o` | `shift_constraint` | `tracepoint/syscalls/sys_enter_execve` | 12 | 10 | - | - | kernel: bpf_object__load failed: Invalid argument |
| `corpus/bcf/collected/stack_ptr_varoff.bpf.o` | `shift_constraint` | `tracepoint/syscalls/sys_enter_execve` | 15 | 45 | - | - | kernel: bpf_object__load failed: Invalid argument |
| `corpus/bcf/collected/system_monitor.bpf.o` | `kprobe__security_bprm_check` | `kprobe/security_bprm_check` | 59 | 210 | - | - | kernel: bpf_object__load failed: Permission denied |
| `corpus/bcf/collected/trace_sys_enter_execve.bpf.o` | `tracepoint__syscalls__sys_enter_execve` | `tracepoint/syscalls/sys_enter_execve` | 38 | 167 | - | - | kernel: bpf_object__load failed: Permission denied |
| `corpus/bcf/collected/unreachable_arsh.bpf.o` | `unreachable_arsh` | `tracepoint/syscalls/sys_enter_execve` | 9 | 10 | - | - | kernel: bpf_object__load failed: Permission denied |
| `corpus/build/real_world_code_size/libbpf-bootstrap/bootstrap.bpf.o` | `handle_exec` | `tp/sched/sched_process_exec` | 63 | - | 292 | - | llvmbpf: unsupported llvmbpf map type: 27 |
| `corpus/build/real_world_code_size/libbpf-bootstrap/bootstrap.bpf.o` | `handle_exit` | `tp/sched/sched_process_exit` | 85 | - | 383 | - | llvmbpf: unsupported llvmbpf map type: 27 |
| `corpus/build/real_world_code_size/libbpf-bootstrap/bootstrap_legacy.bpf.o` | `handle_exec` | `tp/sched/sched_process_exec` | 81 | - | 452 | - | llvmbpf: unsupported llvmbpf map type: 4 |
| `corpus/build/real_world_code_size/libbpf-bootstrap/bootstrap_legacy.bpf.o` | `handle_exit` | `tp/sched/sched_process_exit` | 105 | - | 569 | - | llvmbpf: unsupported llvmbpf map type: 4 |
| `corpus/build/real_world_code_size/libbpf-bootstrap/fentry.bpf.o` | `do_unlinkat` | `fentry/do_unlinkat` | 11 | 36 | 91 | 0.396x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/fentry.bpf.o` | `do_unlinkat_exit` | `fexit/do_unlinkat` | 13 | 55 | 102 | 0.539x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/kprobe.bpf.o` | `do_unlinkat` | `kprobe/do_unlinkat` | 19 | 83 | 98 | 0.847x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/kprobe.bpf.o` | `do_unlinkat_exit` | `kretprobe/do_unlinkat` | 11 | 39 | 58 | 0.672x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/ksyscall.bpf.o` | `entry_probe` | `ksyscall/kill` | 57 | 155 | 230 | 0.674x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/ksyscall.bpf.o` | `tgkill_entry` | `ksyscall/tgkill` | 84 | 180 | 315 | 0.571x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/lsm.bpf.o` | `lsm_bpf` | `lsm/bpf` | 12 | 32 | - | - | kernel: bpf_object__load failed: Invalid argument |
| `corpus/build/real_world_code_size/libbpf-bootstrap/minimal.bpf.o` | `handle_tp` | `tp/syscalls/sys_enter_write` | 13 | 30 | 67 | 0.448x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/minimal_legacy.bpf.o` | `handle_tp` | `tp/syscalls/sys_enter_write` | 33 | 185 | 178 | 1.039x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/minimal_ns.bpf.o` | `handle_tp` | `tp/syscalls/sys_enter_write` | 21 | 64 | 110 | 0.582x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/profile.bpf.o` | `profile` | `perf_event` | 45 | - | 227 | - | llvmbpf: unsupported llvmbpf map type: 27 |
| `corpus/build/real_world_code_size/libbpf-bootstrap/sockfilter.bpf.o` | `socket_handler` | `socket` | 72 | - | 363 | - | llvmbpf: unsupported llvmbpf map type: 27 |
| `corpus/build/real_world_code_size/libbpf-bootstrap/task_iter.bpf.o` | `get_tasks` | `iter/task` | 45 | 159 | 239 | 0.665x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/tc.bpf.o` | `tc_ingress` | `tc` | 18 | 73 | 100 | 0.730x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/uprobe.bpf.o` | `uprobe_add` | `uprobe` | 8 | 25 | 45 | 0.556x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/uprobe.bpf.o` | `uprobe_sub` | `uprobe//proc/self/exe:uprobed_sub` | 8 | 28 | 45 | 0.622x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/uprobe.bpf.o` | `uretprobe_add` | `uretprobe` | 7 | 24 | 41 | 0.585x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/uprobe.bpf.o` | `uretprobe_sub` | `uretprobe//proc/self/exe:uprobed_sub` | 7 | 24 | 41 | 0.585x |  |
| `corpus/build/real_world_code_size/libbpf-bootstrap/usdt.bpf.o` | `usdt_auto_attach` | `usdt/libc.so.6:libc:setjmp` | 33 | - | 683 | - | llvmbpf: [2026-03-06 20:31:19.606] [error] [vm.cpp:157] LLVM-JIT: failed to compile: Instruction at pc=4 is going to jump to an illegal position 4 |
| `corpus/build/real_world_code_size/libbpf-bootstrap/usdt.bpf.o` | `usdt_manual_attach` | `usdt` | 26 | - | 653 | - | llvmbpf: [2026-03-06 20:31:19.639] [error] [vm.cpp:157] LLVM-JIT: failed to compile: Instruction at pc=4 is going to jump to an illegal position 4 |
