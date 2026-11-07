# Independent review of the standard trusted-service helper/map run

F reanalyzed C's existing standard-framework KVM run
x86_kvm_micro_20261107_173730_247516, published in aaf7b9dc4.
All **13 benchmarks / 39 samples** match the suite's exact 64-bit result
and return value 2. All **26 native requests** have distinct source and bound
program IDs, successful fresh compiler commands, a nonempty generated BPF
object and a successful loader receipt. For every request, the kernel's
native ELF copy, service-generation input and receipt native hash agree.
Every benchmark has two such requests with the same native bytes.

| Benchmark | Exact expected result | Return | Correct samples | Fresh requests |
| --- | ---: | ---: | ---: | ---: |
| helper_only_uid_gid | 0 | 2 | 3/3 | 2/2 |
| helper_chain_simple | 0 | 2 | 3/3 | 2/2 |
| map_array_lookup | 16045690984503050241 | 2 | 3/3 | 2/2 |
| map_array_index_packet | 16045690984503098046 | 2 | 3/3 | 2/2 |
| map_hash_lookup | 1234605616436508552 | 2 | 3/3 | 2/2 |
| map_hash_str_key | 18369614221520256751 | 2 | 3/3 | 2/2 |
| map_percpu_array | 18369614221190019774 | 2 | 3/3 | 2/2 |
| map_lru_hash_counter | 1 | 2 | 3/3 | 2/2 |
| map_percpu_hash_counter | 1 | 2 | 3/3 | 2/2 |
| combined_helper_map | 0 | 2 | 3/3 | 2/2 |
| multi_map_policy | 1311768465173141112 | 2 | 3/3 | 2/2 |
| packet_5tuple_classify | 3405691582 | 2 | 3/3 | 2/2 |
| stats_mixed_helpers | 1 | 2 | 3/3 | 2/2 |

The three sample labels are kernel, native_kernel and native_proof.
Both native labels now execute P through the same native-only trusted
service; neither is an unbound baseline. The independent check reads the
original result JSON, current stage2 expectations, service log and every
nested request archive. It does not rely on C's aggregate checks.json.
results.json retains each observed value, request/native/source identities
and both original archive hashes. Numeric generation IDs are not exposed
by these receipts, so no numeric generation-ID claim is made.

The registered service reports ready; application exit is 0. Its -15
service return code is recorded at supervised teardown after the application
closes. The captured runtime runner and supervisor hashes remain distinct
from later publication snapshots where appropriate. Old zero phase fields
and native-size fields are not worker-cost or code-size measurements.

This is a functional correctness result from one sample and one repeat,
not a new run or a timing ratio. The owner ran the unchanged suite on host
CPUs20-23 with four guest CPUs and8GiB through the standard
__runtime-vm-micro Make target. The source/raw command, 26 complete request
archives and exact runtime binary are preserved in
[C's original run](../../../../../corpus/results/kprog_app_coverage_20261107/native-only-micro/README.md);
this report references those pinned archives rather than duplicating them.

Recompute F's independent analysis without starting a VM:

~~~sh
python3 kprog/results/kprog_fidelity_20261107/helper-map/x86-standard-trusted-service/analyze.py
~~~

After refreshing incremental runner/image artifacts to the published
native-only route, R's existing timing request can resume on0-7:

~~~sh
taskset -c 0-7 make micro PLATFORM=kvm ARCH=x86 SUITE=micro/config/micro_stage2.yaml RUNTIMES="native_kernel kernel native_proof" SAMPLES=3 WARMUPS=1 INNER_REPEAT=100000
~~~

The two native labels must not be presented as independent mechanisms.
This report does not broaden the earlier unsafe-suite results, establish an
end-to-end O1-O4 theorem or supply AArch64 hardware evidence.
