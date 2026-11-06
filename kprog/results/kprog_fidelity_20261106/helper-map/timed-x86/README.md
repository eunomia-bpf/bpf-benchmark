# Timed generation-bound helper/map replay

Lane R completed the requested stock Make run at
`micro/results/x86_kvm_micro_20261106_181845_426714`, exit0. All 13 configured
programs run on kernel, generation-bound native (`native_kernel`) and standalone
simulation proof (`native_proof`). Every one of the 117 recorded samples
(13 × 3 runtimes × 3 samples) returns its exact configured64-bit expected result
and retval2. There are zero result/return disagreements. `native_proof` is the
standalone verifier/JIT proof arm, not native execution.

```sh
taskset -c 0-7 make micro PLATFORM=kvm ARCH=x86 SUITE=micro/config/micro_stage2.yaml RUNTIMES="native_kernel kernel native_proof" SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000
cd kprog/results/kprog_fidelity_20261106/helper-map/timed-x86
python3 analyze.py
```

The run used R's timing CPUs0–7. The command was already under Timing requests;
F did not overlap that timing. All numbers below are per-program medians of the
three recorded samples, without filtering. Small execution times are reported
as recorded; integer-nanosecond resolution limits fine comparisons. No geomean
or application performance claim is inferred. `samples.csv` retains every raw
sample/phase and `raw-result.json.gz` is a copy of R's unmodified result.

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

The existing native runner supplies the original companion FD/instructions and
separate compiled simulation proof instructions/object to the generation-bound
loader. The earlier independent F tests record nonzero-generation native
execution explicitly for every configured program on x86 KVM and Arm QEMU;
see the parent README. R's sample format does not include a generation count,
and its guest git identity is `unknown`; those limits remain in the original
metadata. This timed replay is separate from the explicit-generation controls.

The symbol-resolution cost appears in different phase fields depending on its
first caller. For helper_only_uid_gid, median companion_lookup_spec is1287ns
and native_link_cache_lookup is45382576ns; for helper_chain_simple they are
45731306ns and90235ns. The latter phase includes build_native_link_args, not
filesystem-cache work alone. All stage2 cases have helper/map needs, including
packet_5tuple_classify. The separate pure simple,15-sample request is required
to measure elimination of its optional catalogue scan. Neither this13-program
median nor the older29-program median is a matched after-fix measurement for
that single pure program.
