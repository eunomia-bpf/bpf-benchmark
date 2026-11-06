| Program | Expected result | Retval | Kernel ns | Bound native ns | Proof ns | Bound load ms |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| helper_only_uid_gid | 0 | 2 | 7 | 7 | 7 | 46.094462 |
| helper_chain_simple | 0 | 2 | 73 | 72 | 78 | 46.953958 |
| map_array_lookup | 16045690984503050241 | 2 | 17 | 6 | 20 | 46.468429 |
| map_array_index_packet | 16045690984503098046 | 2 | 17 | 6 | 24 | 46.426556 |
| map_hash_lookup | 1234605616436508552 | 2 | 33 | 34 | 47 | 46.616086 |
| map_hash_str_key | 18369614221520256751 | 2 | 34 | 34 | 35 | 46.676426 |
| map_percpu_array | 18369614221190019774 | 2 | 17 | 6 | 21 | 46.385894 |
| map_lru_hash_counter | 1 | 2 | 85 | 90 | 96 | 49.836777 |
| map_percpu_hash_counter | 1 | 2 | 29 | 28 | 35 | 48.634087 |
| combined_helper_map | 0 | 2 | 19 | 9 | 21 | 46.345019 |
| multi_map_policy | 1311768465173141112 | 2 | 46 | 33 | 54 | 46.590208 |
| packet_5tuple_classify | 3405691582 | 2 | 42 | 41 | 43 | 46.214081 |
| stats_mixed_helpers | 1 | 2 | 62 | 62 | 64 | 47.126904 |
