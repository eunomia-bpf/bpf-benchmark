Tetragon diagnostic on 6641a7e1, 2026-11-16T22:33:10Z

Run 221727_857801 retains a completed baseline and an app error:
Tetragon exited before BPF programs were tracked by shim
stdout tail:
level=info msg="Starting tetragon" version=v1.8.0-pre.0-79-g8ca052908
level=info msg="config settings" config="map[bpf-dir:tetragon bpf-lib:/opt/bpf-benchmark/repo-artifacts/x86_64/tetragon btf: cgroup-rate: cluster-name: config-dir: cpuprofile: cri-endpoint: data-cache-size:1024 debug:false disable-kprobe-multi:false enable-ancestors:[] enable-cgidmap:false enable-cgidmap-debug:false enable-cgtrackerid:true enable-cri:false enable-deprecated-tracingpolicy-grpc:false enable-event-metrics:true enable-export-aggregation:false enable-k8s-api:false enable-msg-handling-latency:false enable-pid-set-filter:false enable-pod-annotations:false enable-pod-info:false enable-policy-filter:false enable-policy-filter-cgroup-map:false enable-policy-filter-debug:false enable-process-cred:false enable-process-environment-variables:false enable-process-ns:false enable-tracing-policy-crd:true event-cache-retries:15 event-cache-retry-delay:2 event-queue-size:10000 execve-map-entries:0 execve-map-size: export-aggregation-buffer-size:10000 export-aggregation-window-size:15s export-allowlist: export-denylist: export-file-compress:false export-file-max-backups:5 export-file-max-size-mb:10 export-file-perm:600 export-file-rotation-interval:0s export-filename: export-rate-limit:-1 expose-stack-addresses:false field-filters: filter-environment-variables:[] force-large-progs:false force-small-progs:false generate-docs:false gops-address: health-server-address:127.0.0.1:60189 health-server-interval:10 k8s-controlplane-retry:1 k8s-kubeconfig-path: keep-sensors-on-exit:false kernel: log-file: log-format:text log-level:info memprofile: metrics-label-filter:namespace,workload,pod,binary metrics-server: netns-dir:/var/run/docker/netns/ parents-map-enabled:false parents-map-entries:0 parents-map-size: pprof-address: process-cache-gc-interval:30s process-cache-size:65536 procfs:/proc/ rb-queue-size:65535 rb-size:0 rb-size-total:0 redaction-filters: release-pinned-bpf:true retprobes-cache-size:4096 server-address:127.0.0.1:59099 tracing-policy: tracing-policy-dir:/workspaces/repository/runner/assets/tetragon_policies use-perf-ring-buffer:false username-metadata:disabled verbose:0]"
level=info msg="Tetragon current security context" SELinux="kernel\x00" AppArmor="" Smack="" Lockdown=none
level=info msg="Tetragon pid file creation succeeded" pid=2283 pidfile=/var/run/tetragon/tetragon.pid
level=warn msg="BPF filesystem is going to be mounted automatically in /run/cilium/bpffs. However, it probably means that Cilium is running inside container and BPFFS is not mounted on the host. for more information, see: https://cilium.link/err-bpf-mount"
level=info msg="BPF: successfully released pinned BPF programs and maps" bpf-dir=/run/cilium/bpffs/tetragon
level=info msg="BTF discovery: default kernel btf file found" btf-file=/sys/kernel/btf/vmlinux
level=info msg="BPF detected features: override_return: true, buildid: true, kprobe_multi: false, uprobe_multi: true, fmodret: true, fmodret_syscall: true, signal: true, large: true, link_pin: true, lsm: true, missed_stats_kprobe_multi: true, missed_stats_kprobe: true, batch_update: true, uprobe_refctroff: true, audit_loginuid: true, probe_write_user: true, uprobe_regs_change: true, mix_bpf_and_tail_calls: true, fentry: true, get_func_ret: true"
level=info msg="Cgroup mode detection succeeded" cgroup.fs=/sys/fs/cgroup cgroup.mode="Unified mode (Cgroupv2)"
level=info msg="Cgroupv2 supported controllers detected successfully" cgroup.fs=/sys/fs/cgroup cgroup.path=/proc/1/root/sys/fs/cgroup cgroup.controllers="[cpuset cpu io memory hugetlb pids misc]" cgroup.hierarchyID=0
level=info msg="Cgroupv2 supported controllers detected successfully" cgroup.fs=/sys/fs/cgroup cgroup.path=/sys/fs/cgroup/docker/b90851217b508a87161f70c8cfae94e8b8bd548703b9097f50d31f4b2a537f67 cgroup.controllers="[cpuset cpu io memory hugetlb pids misc]" cgroup.hierarchyID=0
level=info msg="Cgroupv2 hierarchy validated successfully" cgroup.fs=/sys/fs/cgroup cgroup.path=/sys/fs/cgroup/docker/b90851217b508a87161f70c8cfae94e8b8bd548703b9097f50d31f4b2a537f67
level=info msg="Deployment mode detection succeeded" cgroup.fs=/sys/fs/cgroup deployment.mode=Container
level=info msg="Updated TetragonConf map successfully" confmap-update=tg_conf_map deployment.mode=Container log.level=0 cgroup.fs.magic=Cgroupv2 cgroup.hierarchyID=0 NSPID=2283
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
level=info msg="Registered sensors (policy-handlers)" policy-handlers="tracing, enforcer, loader sensor"
level=info msg="Registered probe types" types="execve, generic_fentry, generic_kprobe, generic_tracepoint, generic_usdt, enforcer, generic_lsm, generic_uprobe, loader"
level=info msg="Creating new EventCache" retries=15 delay=2s
level=info msg="Starting process manager" enableK8s=false enableProcessCred=false enableProcessNs=false
level=info msg="Exporter configuration" enabled=false fileName=""
level=info msg="Successfully detected bpftool path" bpftool=/usr/local/bin/bpftool
level=warn msg="failed to locate gops binary, on bugtool debugging ensure you have gops installed"
level=info msg="BPF: found active BPF resources" bpf-dir=/run/cilium/bpffs/tetragon pinned-bpf="[__base__ execve_map execve_map_stats execve_map_update_data tcpmon_map tg_conf_map tg_errmetrics_map tg_execve_joined_info_map tg_execve_joined_info_map_stats tg_mbset_gen tg_mbset_map tg_rb_events tg_stats_map]"
level=info msg="Starting gRPC health server" address=127.0.0.1:60189 interval=10
level=info msg="Starting gRPC server" protocol=tcp address=127.0.0.1:59099
level=info msg="Read ProcFS /proc/ appended 182/241 entries"
level=info msg="Cgroup rate disabled (0/0s)"
level=warn msg="Enforcement actions are not configured for this policy, forcing monitor_only mode" policy=bpf
level=info msg="kprobe call ignored because it was not found" policy=bpf sensor=generic_kprobe idx=0 call=security_bpf_map_alloc
level=info msg="Added kprobe" return=false function=bpf_check override=false enforcer=false
level=info msg="Added kprobe" return=false function=security_perf_event_alloc override=false enforcer=false
level=info msg="Added kprobe" return=false function=security_bpf_map_create override=false enforcer=false
level=info msg="Added generic kprobe sensor: /opt/bpf-benchmark/repo-artifacts/x86_64/tetragon/bpf_generic_kprobe_v61.o -> bpf_check" override=false
level=info msg="Added generic kprobe sensor: /opt/bpf-benchmark/repo-artifacts/x86_64/tetragon/bpf_generic_kprobe_v61.o -> security_perf_event_alloc" override=false
level=info msg="Added generic kprobe sensor: /opt/bpf-benchmark/repo-artifacts/x86_64/tetragon/bpf_generic_kprobe_v61.o -> security_bpf_map_create" override=false
level=info msg="BTF file: using metadata file" metadata=/sys/kernel/btf/vmlinux
level=info msg="Loading sensor" name=generic_kprobe
level=info msg="Loading kernel version 7.0.0"
level=info msg="Unloading sensor generic_kprobe"
level=warn msg="Unload failed during destroy" sensor=generic_kprobe error="unload of sensor generic_kprobe failed: sensor not loaded"
level=info msg="Unloading sensor __base__"
level=info msg="Sensor unloaded" sensor=__base__ maps-error=[]
level=info msg="BPF events statistics: 0 received, 0% events loss"
level=info msg="Observer events statistics" received=0 lost=0 errors=0 filterPass=0 filterDrop=0
level=error msg="Failed to execute tetragon" error="sensor generic_kprobe from collection bpf failed to load: failed prog /opt/bpf-benchmark/repo-artifacts/x86_64/tetragon/bpf_generic_kprobe_v61.o kern_version 458752 loadInstance: opening collection '/opt/bpf-benchmark/repo-artifacts/x86_64/tetragon/bpf_generic_kprobe_v61.o' failed: program generic_kprobe_filter_arg: load program: invalid argument"

The post_rejit shim log lines 1094-1102 names generic_kprobe_filter_arg.
Kernel emission rejects its instruction at IP 0x3a4, whose target 0x1133 is
outside included symbols. The entry is 899 bytes, with fifteen symbols in
the selected closure. This runtime context was absent from the two older
Tetragon kernel-emission captures; 154 successful host entry extractions do
not cover this failure. The log retains the real kernel link command and
its generated proof-cache path. The current shared-link adapter archives
only successful kernel output, so this failing input is not preserved by
that adapter. No link failure is hidden or removed.

The verbose guest console also reports a shutdown-time NULL instruction
fetch in netfs_unbuffered_write+0x2a7 on loop0's worker, at guest 249.98s.
Its stack runs through netfs_unbuffered_write_iter, lo_rw_aio and loop work;
it does not identify a native BPF frame. This is separate evidence from the
named linker error and is not proof of a BPF-induced kernel corruption.
The diagnostic controller returned zero while the app result is error.

Raw console and capture controller remain under
/workspaces/kprog-raw/perf/20261116-host-link-replay/tetragon-capture.
The frozen new-image check is next under the coordinator's 22:20 instruction.
Any continuing failure will be diagnosed from that image before timing claims.
