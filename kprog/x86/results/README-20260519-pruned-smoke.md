| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.475 | 19 | 24 | 0.001 | 0.000 |  |
| `bpf_local_call_fanout_dispatch` | ok | 8.611 | 277 | 295 | 0.016 | 0.000 |  |
| `packed_header_bitfield_decode` | run-fail | 8.466 | 331 | 254 | 0.000 | 0.014 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/packed_header_bitfield_decode.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/packed_header_bitfield_decode-20260519-042356.verifier.log |
