| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.417 | 19 | 24 | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.353 | 16 | 21 | 0.000 | 0.000 |  |
| `bitmap_popcount_scan` | ok | 0.741 | 56 | 96 | 0.018 | 0.000 |  |
| `packet_checksum_fold` | ok | 1.212 | 163 | 88 | 0.329 | 0.000 |  |
| `bpf_local_call_fanout_dispatch` | run-fail | 6.844 | 3750 | 497 | 0.001 | 0.014 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/bpf_local_call_fanout_dispatch.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/bpf_local_call_fanout_dispatch-20260519-024200.verifier.log |
