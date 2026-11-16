2026-11-16T11:57:51Z

The retained stats-on run 20261114_174202_766748 records custom__generic
with 0 calls and 0 ns in BOTH measured arms. Its native code is 9400 B,
original JIT 3679 B, and native bytecode 24 B, so this is a run where it was
installed natively. counters.json copies the exact program records and run
settings. The records do not support describing this program as the ordinary
per-event hot path, or attributing that run's throughput to its code size.

Source confirms its role: custom_trace.ebpf.c:19-23 defines an uprobe-section
entry intended for external custom-trace tail calls, without direct attachment.
tracer/tracer.go:447-458 loads and exposes it. native_tracer_entry is the
PERF_EVENT sampling entry. Equal short BPF-stub tags are separate from native
body identity; kernel/bpf/core.c bpf_prog_calc_tag hashes BPF instructions.

Current run 102445_806916 has stats off, so zero program counters there cannot
establish hotness or inactivity. Its upcoming stats-on row and own unwind
counters are the corresponding evidence. The earlier 1.854x OTel result still
has its documented unequal-work context/unwinding defect; these observations
do not rehabilitate it. Every program and the current payload stay selected.
