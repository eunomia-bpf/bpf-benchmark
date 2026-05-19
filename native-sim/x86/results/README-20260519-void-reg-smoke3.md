| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `simple` | ok | 0.264 | 19 | 24 | 0.000 | 0.000 |  |
| `simple_packet` | ok | 0.232 | 16 | 21 | 0.000 | 0.000 |  |
| `bitmap_popcount_scan` | run-fail | 0.443 | 57 | 80 | 0.018 | 0.000 | error: unexpected XDP retval: got 0, expected 2 |
| `packet_checksum_fold` | ok | 0.671 | 99 | 73 | 0.331 | 0.000 |  |
| `bpf_local_call_fanout_dispatch` | ok | 3.122 | 337 | 497 | 0.019 | 0.000 |  |
