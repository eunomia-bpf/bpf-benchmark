# Lazy Partial-Register Experiment

This tested a C-only lazy partial-register representation:

- 8/16-bit writes update separate low-lane variables and bool flags.
- Full 32/64-bit writes clear those flags.
- Wider reads materialize the exact x86 value from the full register and the
  pending low-lane value.

The experiment was rejected and the active simulator header was restored. It
keeps x86 semantics, but as a general register abstraction it is not verifier
friendly enough:

- `payload_prefix_memcmp_scan` no longer fails at `mov sil,0x1d`, but fails at
  the later `lea r10d,[rsi-0x1d]` materialization, because exact x86 semantics
  still require combining the low byte with the old pointer bits.
- `tetragon_process_event_arg_filter` grows enough stack state that the proof
  program fails the verifier stack limit.
- Compile cost and proof instruction count are much worse than the old-source
  baseline.

Old-source baseline for the same exact programs:

- `payload_prefix_memcmp_scan`: compile `2.814 s`, proof BPF `228` insns,
  direct BPF `139` insns, verifier fail.
- `tetragon_process_event_arg_filter`: compile `4.507 s`, proof BPF `301`
  insns, direct BPF `287` insns, verifier fail.

| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `payload_prefix_memcmp_scan` | run-fail | 13.814 | 832 | 139 | 0.001 | 0.050 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/payload_prefix_memcmp_scan.bpf.o' \| error: bpf_object__load failed: Invalid argument (os error 22); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/payload_prefix_memcmp_scan-20260519-195153.verifier.log |
| `tetragon_process_event_arg_filter` | run-fail | 23.441 | 3054 | 287 | 0.001 | 0.010 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/tetragon_process_event_arg_filter.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/tetragon_process_event_arg_filter-20260519-195153.verifier.log |
