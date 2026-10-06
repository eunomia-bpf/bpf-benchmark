| Micro program | Status | Compile s | Proof BPF insns | Direct BPF insns | Verify s | Test s | Note |
| --- | --- | ---: | ---: | ---: | ---: | ---: | --- |
| `helper_only_uid_gid` | ok | 0.843 | 10 |  | 0.000 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `helper_chain_simple` | ok | 1.167 | 75 |  | 0.001 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `map_array_lookup` | ok | 1.567 | 74 |  | 0.001 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `map_array_index_packet` | ok | 1.776 | 83 |  | 0.001 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `map_hash_lookup` | ok | 1.336 | 76 |  | 0.001 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `map_hash_str_key` | ok | 1.560 | 79 |  | 0.001 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `map_percpu_array` | ok | 1.850 | 76 |  | 0.001 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `map_lru_hash_counter` | ok | 1.367 | 80 |  | 0.001 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `map_percpu_hash_counter` | ok | 1.590 | 75 |  | 0.001 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `combined_helper_map` | ok | 1.153 | 71 |  | 0.001 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `multi_map_policy` | ok | 2.408 | 137 |  | 0.001 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `packet_5tuple_classify` | ok | 1.756 | 107 |  | 0.001 | 0.000 | missing direct xlated.bin in arm64 micro result |
| `stats_mixed_helpers` | ok | 2.029 | 115 |  | 0.001 | 0.000 | missing direct xlated.bin in arm64 micro result |
