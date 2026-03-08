# New Benchmarks Validation Summary

- Note: `config/micro_pure_jit.yaml` and `config/micro_runtime.yaml` contain duplicate benchmark names for these new entries; this validation used temporary corrected manifests in `tmp/` that keep the first matching definition so `expected_result` stays correct.
- Invocation mode: per benchmark per runtime, so one failure would not stop the rest of the matrix.
- Parameters: iterations=3, warmups=1, repeat=200
- Passed both runtimes: memcmp_prefix_64, local_call_fanout, atomic_counter_xadd

## pure_jit_new_benchmarks

| Benchmark | llvmbpf exec_ns median | kernel exec_ns median | L/K ratio | llvmbpf code_size | kernel code_size | Status |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| memcmp_prefix_64 | 75 | 87 | 0.862x | 483 | 650 | passed both |
| packet_parse_vlans_tcpopts | 17 | n/a | n/a | 1004 | n/a | failed: kernel |
| local_call_fanout | 172 | 99 | 1.737x | 815 | 2222 | passed both |
| packet_rss_hash | 43 | n/a | n/a | 653 | n/a | failed: kernel |
| imm64_storm | n/a | n/a | n/a | n/a | n/a | failed: llvmbpf, kernel |
| alu32_64_pingpong | n/a | n/a | n/a | n/a | n/a | failed: llvmbpf, kernel |
| branch_fanout_32 | n/a | n/a | n/a | n/a | n/a | failed: llvmbpf, kernel |
| deep_guard_tree_8 | n/a | n/a | n/a | n/a | n/a | failed: llvmbpf, kernel |
| mega_basic_block_2048 | n/a | n/a | n/a | n/a | n/a | failed: llvmbpf, kernel |

## runtime_new_benchmarks

| Benchmark | llvmbpf exec_ns median | kernel exec_ns median | L/K ratio | llvmbpf code_size | kernel code_size | Status |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| atomic_counter_xadd | 191 | 190 | 1.005x | 475 | 678 | passed both |

## Failures

- `packet_parse_vlans_tcpopts` / `kernel`: `kernel verifier rejected packet access: invalid access to packet, off=21 size=1, R1(id=0,off=21,r=8)`
- `packet_rss_hash` / `kernel`: `kernel verifier rejected packet access: invalid access to packet, off=21 size=1, R1(id=0,off=21,r=8)`
- `imm64_storm` / `llvmbpf`: `imm64_storm/llvmbpf result mismatch: 3017400743644887605 != 9190566551964362354`
- `imm64_storm` / `kernel`: `imm64_storm/kernel result mismatch: 3017400743644887605 != 9190566551964362354`
- `alu32_64_pingpong` / `llvmbpf`: `alu32_64_pingpong/llvmbpf result mismatch: 9369298489151876707 != 6174013046034006403`
- `alu32_64_pingpong` / `kernel`: `alu32_64_pingpong/kernel result mismatch: 9369298489151876707 != 6174013046034006403`
- `branch_fanout_32` / `llvmbpf`: `branch_fanout_32/llvmbpf result mismatch: 0 != 11447288678069767778`
- `branch_fanout_32` / `kernel`: `branch_fanout_32/kernel result mismatch: 0 != 11447288678069767778`
- `deep_guard_tree_8` / `llvmbpf`: `deep_guard_tree_8/llvmbpf result mismatch: 0 != 14503205652076661908`
- `deep_guard_tree_8` / `kernel`: `deep_guard_tree_8/kernel result mismatch: 0 != 14503205652076661908`
- `mega_basic_block_2048` / `llvmbpf`: `mega_basic_block_2048/llvmbpf result mismatch: 2115305415565152290 != 2041000298484100591`
- `mega_basic_block_2048` / `kernel`: `kernel runner rejected input: input larger than kernel input map size`
