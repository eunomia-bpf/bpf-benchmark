| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `tc_packet_checksum_fold` | ok | 1.318 | 28 | 55 | 0.000 | 0.000 |  |
| `cgroup_skb_hash_chain` | run-fail | 1.504 | 21 | 102 | 0.000 | 0.000 | error: unexpected XDP retval: got 0, expected 1 |
