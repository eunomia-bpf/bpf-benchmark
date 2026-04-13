# Tetragon Real End-to-End Benchmark

- Generated: 2026-04-13T08:18:57.481675+00:00
- Mode: `error`
- Smoke: `False`
- Duration per workload: `30s`
- Tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon/bin/tetragon`

## Result

- Status: `ERROR`
- Reason: `Tetragon case could not run: Tetragon failed to become healthy within 20s: level=info msg="Starting tetragon" version=34e9c4a
level=info msg="config settings" config="map[bpf-dir:tetragon bpf-lib:/home/yunwei37/workspace/bpf-benchmark/.cache/repo-artifacts/x86_64/tetragon btf: cgroup-rate:1000,1s cluster-name: config-dir: cpuprofile: cri-endpoint: data-cache-size:1024 debug:false disable-kprobe-multi:false enable-ancestors:[] enable-cgidmap:false enable-cgidmap-debug:false enable-cgtrackerid:true enable-cri:false enable-deprecated-tracingpolicy-grpc:false enable-export-aggregation:false enable-k8s-api:false enable-msg-handling-latency:false enable-pid-set-filter:false enable-pod-annotations:false enable-pod-info:false enable-policy-filter:false enable-policy-filter-cgroup-map:false enable-policy-filter-debug:false enable-process-cred:false enable-process-environment-variables:false enable-process-ns:false enable-tracing-policy-crd:true event-cache-retries:15 event-cache-retry-delay:2 event-queue-size:10000 execve-map-entries:0 execve-map-size: export-aggregation-buffer-size:10000 export-aggregation-window-size:15s export-allowlist: export-denylist: export-file-compress:false export-file-max-backups:5 export-file-max-size-mb:10 export-file-perm:600 export-file-rotation-interval:0s export-filename: export-rate-limit:-1 expose-stack-addresses:false field-filters: filter-environment-variables:[] force-large-progs:false force-small-progs:false generate-docs:false gops-address: health-server-address::6789 health-server-interval:10 k8s-controlplane-retry:1 k8s-kubeconfig-path: keep-sensors-on-exit:false kernel: log-file: log-format:text log-level:info memprofile: metrics-label-filter:namespace,workload,pod,binary metrics-server: netns-dir:/var/run/docker/netns/ parents-map-enabled:false parents-map-entries:0 parents-map-size: pprof-address: process-cache-gc-interval:30s process-cache-size:65536 procfs:/proc/ rb-queue-size:65535 rb-size:0 rb-size-total:0 redaction-filters: release-pinned-bpf:true retprobes-cache-size:4096 server-address:localhost:54321 tracing-policy: tracing-policy-dir:/home/yunwei37/workspace/bpf-benchmark/docs/tmp/20260413/vm-tmp/tetragon-policy-3ftft2wa use-perf-ring-buffer:false username-metadata:disabled verbose:0]"
level=info msg="Tetragon current security context" SELinux="kernel\x00" AppArmor="" Smack="" Lockdown=none
level=info msg="Tetragon pid file creation succeeded" pid=1882 pidfile=/var/run/tetragon/tetragon.pid
level=warn msg="Unable to mount BPF filesystem" error="multiple mount points detected at /sys/fs/bpf"
level=info msg="BPF: successfully released pinned BPF programs and maps" bpf-dir=/sys/fs/bpf/tetragon
level=info msg="BTF discovery: default kernel btf file found" btf-file=/sys/kernel/btf/vmlinux
level=info msg="BPF detected features: override_return: true, buildid: true, kprobe_multi: true, uprobe_multi: true, fmodret: true, fmodret_syscall: true, signal: true, large: true, link_pin: true, lsm: true, missed_stats_kprobe_multi: true, missed_stats_kprobe: true, batch_update: true, uprobe_refctroff: true, audit_loginuid: true, probe_write_user: true, uprobe_regs_change: true, mix_bpf_and_tail_calls: true, fentry: true, get_func_ret: true"
level=info msg="Cgroup mode detection succeeded" cgroup.fs=/sys/fs/cgroup cgroup.mode="Unified mode (Cgroupv2)"
level=info msg="Cgroupv2 supported controllers detected successfully" cgroup.fs=/sys/fs/cgroup cgroup.path=/proc/1/root/sys/fs/cgroup cgroup.controllers="[cpuset cpu io memory hugetlb pids rdma misc dmem]" cgroup.hierarchyID=0
level=info msg="Cgroupv2 supported controllers detected successfully" cgroup.fs=/sys/fs/cgroup cgroup.path=/sys/fs/cgroup cgroup.controllers="[cpuset cpu io memory hugetlb pids rdma misc dmem]" cgroup.hierarchyID=0
level=warn msg="Failed to detect deployment mode from Cgroupv2 path" cgroup.fs=/sys/fs/cgroup error="cgroup path is empty"
level=warn msg="Unable to find Cgroup migration path for pid=1882" cgroup.fs=/sys/fs/cgroup error="could not validate Cgroupv2 hierarchy"
level=warn msg="Detection of deployment mode failed" cgroup.fs=/sys/fs/cgroup error="could not detect Cgroup migration path for pid=1882"
level=warn msg="Deployment mode detection failed" cgroup.fs=/sys/fs/cgroup deployment.mode=unknown
level=warn msg="Deployment mode is unknown, advanced Cgroups tracking will be disabled" confmap-update=tg_conf_map
level=info msg="Updated TetragonConf map successfully" confmap-update=tg_conf_map deployment.mode=unknown log.level=0 cgroup.fs.magic=Cgroupv2 cgroup.hierarchyID=0 NSPID=1882
level=info msg="Disabling Kubernetes API"
level=info msg="Configured redaction filters" redactionFilters=""
level=info msg="Exit probe on acct_process"
level=info msg="Set execve_map entries 32768" size=28M
level=info msg="BPF ring buffer size (bytes)" total=256K
level=info msg="BTF file: using metadata file" metadata=/sys/kernel/btf/vmlinux
level=info msg="Loading sensor" name=__base__
level=info msg="Loading kernel version 7.0.0"
level=info msg="Loaded sensor successfully" sensor=__base__
level=info msg="Available sensors" sensors=__base__
level=info msg="Registered sensors (policy-handlers)" policy-handlers="loader sensor, tracing, enforcer"
level=info msg="Registered probe types" types="generic_tracepoint, generic_uprobe, generic_usdt, loader, execve, enforcer, generic_kprobe, generic_fentry, generic_lsm"
level=info msg="Creating new EventCache" retries=15 delay=2s
level=info msg="Starting process manager" enableK8s=false enableProcessCred=false enableProcessNs=false
level=info msg="Exporter configuration" enabled=false fileName=""
level=info msg="Successfully detected bpftool path" bpftool=/usr/sbin/bpftool
level=warn msg="failed to locate gops binary, on bugtool debugging ensure you have gops installed"
level=info msg="Starting gRPC health server" address=:6789 interval=10
level=info msg="BPF: found active BPF resources" bpf-dir=/sys/fs/bpf/tetragon pinned-bpf="[__base__ cgroup_rate_map cgroup_rate_options_map execve_map execve_map_stats execve_map_update_data tcpmon_map tg_conf_map tg_errmetrics_map tg_execve_joined_info_map tg_execve_joined_info_map_stats tg_mbset_gen tg_mbset_map tg_rb_events tg_stats_map]"
level=error msg="Failed to start gRPC server" protocol=tcp address=localhost:54321 error="listen tcp 127.0.0.1:54321: bind: address already in use"`

