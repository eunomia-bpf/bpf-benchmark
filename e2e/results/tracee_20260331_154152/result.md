# Tracee Real End-to-End Benchmark

- Generated: 2026-03-31T15:43:59.988270+00:00
- Mode: `error`
- Duration per workload: `20s`
- Warmup per workload: `Nones`
- Paired cycles: `None`
- Latency probes per phase: `None`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/corpus/build/tracee/bin/tracee`

## Result

- Status: `ERROR`
- Reason: `Tracee case could not run: failed to launch Tracee: /home/yunwei37/workspace/bpf-benchmark/corpus/build/tracee/bin/tracee --events execve,sched_process_exec,security_file_open,security_socket_connect --output destinations.file_json.type=file --output destinations.file_json.format=json --output destinations.file_json.path=/var/tmp/tracee/events.json --server healthz --server http-address=:3366 --signatures-dir /home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/signatures: command exited with code 2: 	/home/yunwei37/go/pkg/mod/golang.org/toolchain@v0.0.1-go1.26.1.linux-amd64/src/internal/sync/mutex.go:149 +0x15d fp=0xc001805c38 sp=0xc001805be8 pc=0xe9ba1d
internal/sync.(*Mutex).Lock(...)
	/home/yunwei37/go/pkg/mod/golang.org/toolchain@v0.0.1-go1.26.1.linux-amd64/src/internal/sync/mutex.go:70
sync.(*Mutex).Lock(...)
	/home/yunwei37/go/pkg/mod/golang.org/toolchain@v0.0.1-go1.26.1.linux-amd64/src/sync/mutex.go:46
github.com/aquasecurity/tracee/common/capabilities.(*Capabilities).Specific(0xc0006961e0, 0xc001805e20, {0xc001805d48, 0x1, 0x1})
	/home/yunwei37/workspace/bpf-benchmark/runner/repos/tracee/common/capabilities/capabilities.go:335 +0x6f fp=0xc001805cb0 sp=0xc001805c38 pc=0x15ddf0f
github.com/aquasecurity/tracee/pkg/datastores/process.dealWithProc(0xc000399360, 0x24)
	/home/yunwei37/workspace/bpf-benchmark/runner/repos/tracee/pkg/datastores/process/proctree_procfs.go:215 +0x4b7 fp=0xc001805e70 sp=0xc001805cb0 pc=0x1c8a7d7
github.com/aquasecurity/tracee/pkg/datastores/process.dealWithProcFsEntry(0xc000399360, 0x24)
	/home/yunwei37/workspace/bpf-benchmark/runner/repos/tracee/pkg/datastores/process/proctree_procfs.go:361 +0x25 fp=0xc001805ee8 sp=0xc001805e70 pc=0x1c8b185
github.com/aquasecurity/tracee/pkg/datastores/process.(*ProcessTree).FeedFromProcFS(0xc000399360, 0x82780?)
	/home/yunwei37/workspace/bpf-benchmark/runner/repos/tracee/pkg/datastores/process/proctree_procfs.go:86 +0xe5 fp=0xc001805f50 sp=0xc001805ee8 pc=0x1c8a1e5
github.com/aquasecurity/tracee/pkg/datastores/process.(*ProcessTree).feedFromProcFSLoop.func1()
	/home/yunwei37/workspace/bpf-benchmark/runner/repos/tracee/pkg/datastores/process/proctree_procfs.go:34 +0xf8 fp=0xc001805fe0 sp=0xc001805f50 pc=0x1c89ff8
runtime.goexit({})
	/home/yunwei37/go/pkg/mod/golang.org/toolchain@v0.0.1-go1.26.1.linux-amd64/src/runtime/asm_amd64.s:1771 +0x1 fp=0xc001805fe8 sp=0xc001805fe0 pc=0xe8b361
created by github.com/aquasecurity/tracee/pkg/datastores/process.(*ProcessTree).feedFromProcFSLoop in goroutine 1
	/home/yunwei37/workspace/bpf-benchmark/runner/repos/tracee/pkg/datastores/process/proctree_procfs.go:26 +0x4f
rax    0x94e1
rbx    0xc000068da8
rcx    0x23941
rdx    0x784154628320
rdi    0x784154628320
rsi    0x94e1
rbp    0x78415bffda30
rsp    0x78415bffda10
r8     0x1
r9     0x78415401f1d0
r10    0x7841540209b0
r11    0x40
r12    0xbf
r13    0xc0019357c0
r14    0xc0000081e0
r15    0xffffffffffffffff
rip    0x211931c
rflags 0x10202
cs     0x33
fs     0x0
gs     0x0`

## Preflight

- tracee_default: primary_events/s=33816.02186832114, bpf_avg_ns=104.35661694222313, target_runs=3400876


