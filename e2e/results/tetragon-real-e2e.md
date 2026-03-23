# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-23T13:25:24.130059+00:00
- Mode: `tetragon_daemon`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/usr/local/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`

## Baseline

- Application throughput mean: `729037.7374458341` ops/s
- Events/s mean: `0.0`
- Agent CPU mean: `0.19999966369389893`%
- BPF avg ns mean: `None`

- stress_exec: ops/s=806142.2676925146, events/s=0.0, agent_cpu=0.7999986547755957, bpf_avg_ns=None
- file_io: ops/s=1541310.2127981323, events/s=0.0, agent_cpu=0.0, bpf_avg_ns=None
- open_storm: ops/s=531939.9214163105, events/s=0.0, agent_cpu=0.0, bpf_avg_ns=None
- connect_storm: ops/s=36758.54787637907, events/s=0.0, agent_cpu=0.0, bpf_avg_ns=None

## Per-Program

- event_exit_acct (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_wake_up_n (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- event_execve (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_rate (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_send (tracepoint): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- tg_kp_bprm_comm (kprobe): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None
- execve_map_upda (socket_filter): sites=0, stock_avg_ns=None, rejit_avg_ns=None, speedup=None

## Comparison

- Comparable: `False`
- Reason: `Tetragon exited with code 255: level=warn msg="Reading process status error" error="ReadFile /proc/88/loginuid failed: open /proc/88/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/88/ns/user' readlink /proc/88/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/89/loginuid failed: open /proc/89/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/89/ns/user' readlink /proc/89/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/9/loginuid failed: open /proc/9/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/9/ns/user' readlink /proc/9/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/90/loginuid failed: open /proc/90/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/90/ns/user' readlink /proc/90/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/91/loginuid failed: open /proc/91/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/91/ns/user' readlink /proc/91/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/92/loginuid failed: open /proc/92/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/92/ns/user' readlink /proc/92/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/93/loginuid failed: open /proc/93/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/93/ns/user' readlink /proc/93/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/94/loginuid failed: open /proc/94/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/94/ns/user' readlink /proc/94/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/95/loginuid failed: open /proc/95/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/95/ns/user' readlink /proc/95/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/96/loginuid failed: open /proc/96/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/96/ns/user' readlink /proc/96/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/97/loginuid failed: open /proc/97/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/97/ns/user' readlink /proc/97/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/98/loginuid failed: open /proc/98/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/98/ns/user' readlink /proc/98/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/99/loginuid failed: open /proc/99/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/99/ns/user' readlink /proc/99/ns/user: no such file or directory"
level=info msg="Read ProcFS /proc/ appended 245/304 entries"
level=info msg="Cgroup rate disabled (0/0s)"
level=info msg="Added kprobe" return=false function=security_bprm_check override=false
level=info msg="Added kprobe" return=false function=security_file_open override=false
level=info msg="Added kprobe" return=false function=tcp_connect override=false
level=info msg="BTF file: using metadata file" metadata=/sys/kernel/btf/vmlinux
level=info msg="Loading sensor" name=generic_kprobe
level=info msg="Loading kernel version 7.0.0"
level=info msg="Unloading sensor generic_kprobe"
level=warn msg="Unload failed during destroy" sensor=generic_kprobe error="unload of sensor generic_kprobe failed: sensor not loaded"
level=info msg="Unloading sensor __base__"
level=info msg="Sensor unloaded" sensor=__base__ maps-error=[]
level=info msg="BPF events statistics: 0 received, 0% events loss"
level=info msg="Observer events statistics" received=0 lost=0 errors=0 filterPass=0 filterDrop=0`

## Limitations

- Tetragon exited with code 255: level=warn msg="Reading process status error" error="ReadFile /proc/88/loginuid failed: open /proc/88/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/88/ns/user' readlink /proc/88/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/89/loginuid failed: open /proc/89/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/89/ns/user' readlink /proc/89/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/9/loginuid failed: open /proc/9/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/9/ns/user' readlink /proc/9/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/90/loginuid failed: open /proc/90/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/90/ns/user' readlink /proc/90/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/91/loginuid failed: open /proc/91/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/91/ns/user' readlink /proc/91/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/92/loginuid failed: open /proc/92/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/92/ns/user' readlink /proc/92/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/93/loginuid failed: open /proc/93/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/93/ns/user' readlink /proc/93/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/94/loginuid failed: open /proc/94/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/94/ns/user' readlink /proc/94/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/95/loginuid failed: open /proc/95/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/95/ns/user' readlink /proc/95/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/96/loginuid failed: open /proc/96/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/96/ns/user' readlink /proc/96/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/97/loginuid failed: open /proc/97/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/97/ns/user' readlink /proc/97/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/98/loginuid failed: open /proc/98/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/98/ns/user' readlink /proc/98/ns/user: no such file or directory"
level=warn msg="Reading process status error" error="ReadFile /proc/99/loginuid failed: open /proc/99/loginuid: no such file or directory"
level=warn msg="Reading user namespace failed" error="namespace '/proc/99/ns/user' readlink /proc/99/ns/user: no such file or directory"
level=info msg="Read ProcFS /proc/ appended 245/304 entries"
level=info msg="Cgroup rate disabled (0/0s)"
level=info msg="Added kprobe" return=false function=security_bprm_check override=false
level=info msg="Added kprobe" return=false function=security_file_open override=false
level=info msg="Added kprobe" return=false function=tcp_connect override=false
level=info msg="BTF file: using metadata file" metadata=/sys/kernel/btf/vmlinux
level=info msg="Loading sensor" name=generic_kprobe
level=info msg="Loading kernel version 7.0.0"
level=info msg="Unloading sensor generic_kprobe"
level=warn msg="Unload failed during destroy" sensor=generic_kprobe error="unload of sensor generic_kprobe failed: sensor not loaded"
level=info msg="Unloading sensor __base__"
level=info msg="Sensor unloaded" sensor=__base__ maps-error=[]
level=info msg="BPF events statistics: 0 received, 0% events loss"
level=info msg="Observer events statistics" received=0 lost=0 errors=0 filterPass=0 filterDrop=0; skipping scan and ReJIT after the baseline phase.
- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.
