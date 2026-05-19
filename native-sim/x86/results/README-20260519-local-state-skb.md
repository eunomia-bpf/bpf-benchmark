| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `tc_packet_checksum_fold` | ok | 1.895 | 167 | 73 | 0.331 | 0.000 |  |
| `cgroup_skb_hash_chain` | run-fail | 2.713 | 829 | 118 | 0.007 | 0.021 | libbpf: failed to load object '/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/micro-prog/build/cgroup_skb_hash_chain.bpf.o' \| error: bpf_object__load failed: Permission denied (os error 13); verifier log: /home/yunwei37/workspace/bpf-benchmark/native-sim/x86/results/cgroup_skb_hash_chain-20260519-024446.verifier.log |
