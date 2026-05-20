# ReverseSim old-source known failures

This records the chosen baseline after rejecting source-shaping fixes for
`payload_prefix_memcmp_scan` and `tetragon_process_event_arg_filter`.

Command:

```bash
python3 native-sim/x86/micro-prog/generate_micro_sim_proofs.py \
  --only payload_prefix_memcmp_scan tetragon_process_event_arg_filter
python3 native-sim/x86/micro-prog/run_micro_sim_batch.py --jobs 2 \
  --only payload_prefix_memcmp_scan tetragon_process_event_arg_filter \
  --markdown native-sim/x86/results/README-20260519-old-source-known-failures.md
```

Both failures are expected verifier/load failures for the exact old-source
partial-register native code. They are not simulator traps or fallback returns.

| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `payload_prefix_memcmp_scan` | run-fail | 2.814 | 228 | 139 | 0.000 | 0.087 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/payload_prefix_memcmp_scan.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/payload_prefix_memcmp_scan-20260519-165624.verifier.log |
| `tetragon_process_event_arg_filter` | run-fail | 4.507 | 301 | 287 | 0.001 | 0.022 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/tetragon_process_event_arg_filter.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/tetragon_process_event_arg_filter-20260519-165624.verifier.log |
