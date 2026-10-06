| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.241 | 19 | 24 | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.212 | 16 | 21 | 0.000 | 0.000 |  |
| `tc_packet_checksum_fold` | run-fail | 0.930 | 151 |  | 0.000 | 0.013 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/tc_packet_checksum_fold.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/tc_packet_checksum_fold-20260519-052404.verifier.log; missing direct xlated.bin in micro result |
| `cgroup_skb_hash_chain` | run-fail | 1.416 | 300 |  | 0.000 | 0.014 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/cgroup_skb_hash_chain.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/cgroup_skb_hash_chain-20260519-052404.verifier.log; missing direct xlated.bin in micro result |
