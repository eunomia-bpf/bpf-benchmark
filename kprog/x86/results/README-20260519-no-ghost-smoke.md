| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.246 | 19 | 24 | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.221 | 16 | 21 | 0.000 | 0.000 |  |
| `packet_checksum_fold` | run-fail | 0.637 | 170 | 67 | 0.199 | 0.212 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/packet_checksum_fold.bpf.o' \| error: bpf_object__load failed: Bad address (os error 14); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/packet_checksum_fold-20260519-045109.verifier.log |
| `bpf_local_call_fanout_dispatch` | run-fail | 2.970 | 550 | 295 | 0.006 | 0.019 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/bpf_local_call_fanout_dispatch.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/bpf_local_call_fanout_dispatch-20260519-045109.verifier.log |
