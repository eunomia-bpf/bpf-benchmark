| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.275 | 19 | 24 | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.243 | 16 | 21 | 0.000 | 0.000 |  |
| `bitmap_popcount_scan` | ok | 0.446 | 56 | 80 | 0.018 | 0.000 |  |
| `packet_checksum_fold` | ok | 0.658 | 99 | 73 | 0.335 | 0.000 |  |
| `bpf_local_call_fanout_dispatch` | ok | 3.086 | 337 | 497 | 0.018 | 0.000 |  |
