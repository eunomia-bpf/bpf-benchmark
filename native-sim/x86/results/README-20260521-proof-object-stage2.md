| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `helper_only_uid_gid` | ok | 0.344 | 10 |  | 0.000 | 0.000 | missing direct xlated.bin in x86 micro result |
| `helper_chain_simple` | ok | 1.134 | 66 |  | 0.001 | 0.000 | missing direct xlated.bin in x86 micro result |
| `map_array_lookup` | ok | 0.710 | 65 |  | 0.001 | 0.000 | missing direct xlated.bin in x86 micro result |
| `map_array_index_packet` | ok | 0.764 | 70 |  | 0.001 | 0.000 | missing direct xlated.bin in x86 micro result |
| `map_hash_lookup` | ok | 0.709 | 67 |  | 0.001 | 0.000 | missing direct xlated.bin in x86 micro result |
| `map_hash_str_key` | ok | 0.662 | 71 |  | 0.001 | 0.000 | missing direct xlated.bin in x86 micro result |
| `map_percpu_array` | ok | 1.126 | 67 |  | 0.001 | 0.000 | missing direct xlated.bin in x86 micro result |
| `map_lru_hash_counter` | ok | 0.799 | 71 |  | 0.001 | 0.000 | missing direct xlated.bin in x86 micro result |
| `map_percpu_hash_counter` | ok | 0.841 | 67 |  | 0.001 | 0.000 | missing direct xlated.bin in x86 micro result |
| `combined_helper_map` | ok | 0.705 | 62 |  | 0.001 | 0.000 | missing direct xlated.bin in x86 micro result |
| `multi_map_policy` | ok | 1.795 | 129 |  | 0.001 | 0.000 | missing direct xlated.bin in x86 micro result |
| `packet_5tuple_classify` | ok | 1.456 | 96 |  | 0.001 | 0.000 | missing direct xlated.bin in x86 micro result |
| `stats_mixed_helpers` | ok | 1.403 | 105 |  | 0.001 | 0.000 | missing direct xlated.bin in x86 micro result |
