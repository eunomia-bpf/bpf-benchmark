| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.249 | 19 | 24 | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.218 | 16 | 21 | 0.000 | 0.000 |  |
| `bpf_local_call_fanout_dispatch` | run-fail | 2.984 | 503 |  | 0.005 | 0.019 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/bpf_local_call_fanout_dispatch.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/bpf_local_call_fanout_dispatch-20260519-050125.verifier.log; missing direct xlated.bin in micro result |
