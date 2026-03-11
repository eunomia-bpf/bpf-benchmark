# Tetragon Real End-to-End Benchmark

- Generated: 2026-03-11T17:01:37.629812+00:00
- Mode: `manual_fallback`
- Smoke: `True`
- Duration per workload: `8s`
- Tetragon binary: `unavailable`

## Setup

- Setup return code: `0`
- Setup tetragon binary: `/usr/local/bin/tetragon`
- Fallback reason: `Tetragon failed to become healthy: level=info msg="Starting tetragon" version=v1.6.0
level=info msg="config settings" config="map[bpf-dir:tetragon bpf-lib:/var/lib/tetragon/ btf: cgroup-rate: cluster-name: config-dir: cpuprofile: cri-endpoint: data-cache-size:1024 debug:false disable-kprobe-multi:false enable-ancestors:[] enable-cgidmap:false enable-cgidmap-debug:false enable-cgtrackerid:true enable-compatibility-syscall64-size-type:false enable-cri:false enable-export-aggregation:false enable-k8s-api:false enable-msg-handling-latency:false enable-pid-set-filter:false enable-pod-annotations:false enable-pod-info:false enable-policy-filter:false enable-policy-filter-cgroup-map:false enable-policy-filter-debug:false enable-process-cred:false enable-process-ns:false enable-tracing-policy-crd:true event-cache-retries:15 event-cache-retry-delay:2 event-queue-size:10000 execve-map-entries:0 execve-map-size: export-aggregation-buffer-size:10000 export-aggregation-window-size:15s export-allowlist: export-denylist: export-file-compress:false export-file-max-backups:5 export-file-max-size-mb:10 export-file-perm:600 export-file-rotation-interval:0s export-filename: export-rate-limit:-1 expose-stack-addresses:false field-filters: force-large-progs:false force-small-progs:false generate-docs:false gops-address: health-server-address::6789 health-server-interval:10 k8s-controlplane-retry:1 k8s-kubeconfig-path: keep-sensors-on-exit:false kernel: log-format:text log-level:info memprofile: metrics-label-filter:namespace,workload,pod,binary metrics-server: netns-dir:/var/run/docker/netns/ pprof-address: process-cache-gc-interval:30s process-cache-size:65536 procfs:/proc/ rb-queue-size:65535 rb-size:0 rb-size-total:0 redaction-filters: release-pinned-bpf:true server-address:localhost:54321 tracing-policy:/tmp/tetragon-policy-z3x4mv4w/tetragon-e2e-policy.yaml tracing-policy-dir:/etc/tetragon/tetragon.tp.d use-perf-ring-buffer:false username-metadata:disabled verbose:0]"
level=info msg="Tetragon pid file creation succeeded" pid=141 pidfile=/var/run/tetragon/tetragon.pid
level=error msg="Failed to execute tetragon" error="struct alignment checks failed: program \"bpf_alignchecker.o\" cannot be found (errors: bpf_alignchecker.o: stat bpf_alignchecker.o: no such file or directory;bpf_alignchecker.o.gz: stat bpf_alignchecker.o.gz: no such file or directory;/var/lib/tetragon/bpf_alignchecker.o: stat /var/lib/tetragon/bpf_alignchecker.o: no such file or directory;/var/lib/tetragon/bpf_alignchecker.o.gz: stat /var/lib/tetragon/bpf_alignchecker.o.gz: no such file or directory)"
level=info msg="Tetragon current security context" SELinux="kernel\x00" AppArmor="" Smack="" Lockdown=""`

## Baseline

- Application throughput mean: `339803.07619894965` ops/s
- Events/s mean: `143095.14282944365`
- Agent CPU mean: `46.311856137224694`%
- BPF avg ns mean: `364.9864301191362`

- stress_exec: ops/s=158.77381481724112, events/s=1445.0790635765893, agent_cpu=1.124989116152172, bpf_avg_ns=506.0445193637621
- file_io: ops/s=1067819.5538658004, events/s=44.547567884893155, agent_cpu=0.12499689660830021, bpf_avg_ns=454.0644329896907
- open_storm: ops/s=279597.5928661529, events/s=559241.5607062429, agent_cpu=99.99810774830681, bpf_avg_ns=218.1223781749176
- connect_storm: ops/s=11636.384249028075, events/s=11649.38398007014, agent_cpu=83.99933078783151, bpf_avg_ns=281.7143899481743

## Recompile

- Applied programs: `3` / `3`
- Applied successfully: `True`

## Per-Program

- event_execve (tracepoint): sites=37, stock_avg_ns=2054.6528213166143, rejit_avg_ns=2344.934300341297, speedup=0.8762091206638782
- generic_kprobe_ (kprobe): sites=2, stock_avg_ns=218.37116879392835, rejit_avg_ns=216.69959615369174, speedup=1.0077137782898822
- generic_kprobe_ (kprobe): sites=2, stock_avg_ns=281.38727106718943, rejit_avg_ns=264.15853728345206, speedup=1.065221188612391

## Post-ReJIT

- Application throughput mean: `352171.57159948914` ops/s
- Events/s mean: `145978.23348623439`
- Agent CPU mean: `42.40556002728332`%
- BPF avg ns mean: `362.8945258799827`

- stress_exec: ops/s=145.7800437449135, events/s=1322.1388029101668, agent_cpu=1.499988954081342, bpf_avg_ns=592.6545729402873
- file_io: ops/s=1105646.698724132, events/s=40.70109120213286, agent_cpu=0.0, bpf_avg_ns=378.29411764705884
- open_storm: ops/s=279603.609701381, events/s=559249.5938889554, agent_cpu=99.99782132246742, bpf_avg_ns=216.34936257990802
- connect_storm: ops/s=23290.19792869867, events/s=23300.500161869844, agent_cpu=68.12442983258453, bpf_avg_ns=264.2800503526768

## Comparison

- connect_storm: baseline_ops/s=11636.384249028075, post_ops/s=23290.19792869867, app_delta=100.14978390425684%, baseline_cpu=83.99933078783151, post_cpu=68.12442983258453, cpu_delta=-18.89884217690302%
- file_io: baseline_ops/s=1067819.5538658004, post_ops/s=1105646.698724132, app_delta=3.542466020722976%, baseline_cpu=0.12499689660830021, post_cpu=0.0, cpu_delta=-100.0%
- open_storm: baseline_ops/s=279597.5928661529, post_ops/s=279603.609701381, app_delta=0.002151962456634199%, baseline_cpu=99.99810774830681, post_cpu=99.99782132246742, cpu_delta=-0.000286431259391669%
- stress_exec: baseline_ops/s=158.77381481724112, post_ops/s=145.7800437449135, app_delta=-8.183824950785663%, baseline_cpu=1.124989116152172, post_cpu=1.499988954081342, cpu_delta=33.333641414397974%

## Limitations

- Daemon mode failed and manual fallback was used instead: Tetragon failed to become healthy: level=info msg="Starting tetragon" version=v1.6.0
level=info msg="config settings" config="map[bpf-dir:tetragon bpf-lib:/var/lib/tetragon/ btf: cgroup-rate: cluster-name: config-dir: cpuprofile: cri-endpoint: data-cache-size:1024 debug:false disable-kprobe-multi:false enable-ancestors:[] enable-cgidmap:false enable-cgidmap-debug:false enable-cgtrackerid:true enable-compatibility-syscall64-size-type:false enable-cri:false enable-export-aggregation:false enable-k8s-api:false enable-msg-handling-latency:false enable-pid-set-filter:false enable-pod-annotations:false enable-pod-info:false enable-policy-filter:false enable-policy-filter-cgroup-map:false enable-policy-filter-debug:false enable-process-cred:false enable-process-ns:false enable-tracing-policy-crd:true event-cache-retries:15 event-cache-retry-delay:2 event-queue-size:10000 execve-map-entries:0 execve-map-size: export-aggregation-buffer-size:10000 export-aggregation-window-size:15s export-allowlist: export-denylist: export-file-compress:false export-file-max-backups:5 export-file-max-size-mb:10 export-file-perm:600 export-file-rotation-interval:0s export-filename: export-rate-limit:-1 expose-stack-addresses:false field-filters: force-large-progs:false force-small-progs:false generate-docs:false gops-address: health-server-address::6789 health-server-interval:10 k8s-controlplane-retry:1 k8s-kubeconfig-path: keep-sensors-on-exit:false kernel: log-format:text log-level:info memprofile: metrics-label-filter:namespace,workload,pod,binary metrics-server: netns-dir:/var/run/docker/netns/ pprof-address: process-cache-gc-interval:30s process-cache-size:65536 procfs:/proc/ rb-queue-size:65535 rb-size:0 rb-size-total:0 redaction-filters: release-pinned-bpf:true server-address:localhost:54321 tracing-policy:/tmp/tetragon-policy-z3x4mv4w/tetragon-e2e-policy.yaml tracing-policy-dir:/etc/tetragon/tetragon.tp.d use-perf-ring-buffer:false username-metadata:disabled verbose:0]"
level=info msg="Tetragon pid file creation succeeded" pid=141 pidfile=/var/run/tetragon/tetragon.pid
level=error msg="Failed to execute tetragon" error="struct alignment checks failed: program \"bpf_alignchecker.o\" cannot be found (errors: bpf_alignchecker.o: stat bpf_alignchecker.o: no such file or directory;bpf_alignchecker.o.gz: stat bpf_alignchecker.o.gz: no such file or directory;/var/lib/tetragon/bpf_alignchecker.o: stat /var/lib/tetragon/bpf_alignchecker.o: no such file or directory;/var/lib/tetragon/bpf_alignchecker.o.gz: stat /var/lib/tetragon/bpf_alignchecker.o.gz: no such file or directory)"
level=info msg="Tetragon current security context" SELinux="kernel\x00" AppArmor="" Smack="" Lockdown=""
- events_total and events_per_sec are derived from aggregate BPF run_cnt deltas, so a single application operation can increment multiple program counters.
- Manual fallback uses directly loaded Tetragon BPF objects; agent CPU therefore reflects the benchmark controller process rather than a real Tetragon daemon.
