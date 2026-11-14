# kprog optimizations

Operator, 2026-11-14: "然后你要想办法优化一下, LTO + native 我觉得到 40% 性能进步是完全肯定可以的. 先确保管线正确, 然后开始考虑优化. 每一个优化也得记录在哪里怎么做的."

Every optimization of the native path is recorded here: where it lives, how it works, which pipeline step it belongs to (design.md 编译流水线: step 1 compiler flags when P is produced, step 3 link-time optimization), how its correctness is checked, and its effect in the combined configuration (all pieces on together; the operator: "不需要这样细粒度区分. 只需要都做就好."). The lane that lands an optimization adds or updates its row in the same commit. Effects are per-call native/eBPF on the combined configuration, with the run directory.

| Optimization | Step | Where (code, switch) | How | Commit | Correctness check | Status |
|---|---|---|---|---|---|---|
| Array and per-CPU array lookup inlining | LTO | native_link `select_lookup_site`, `--runtime-known-map-lookups` | a lookup whose map is a proven named Array or PerCPU map becomes the bounds check and address arithmetic the kernel's array_map_gen_lookup emits | 6cf9f5cd9 | 22 real objects byte-identical with the switch off; OTel 325 sites inlined | on |
| Typed hash lookup dispatch | LTO | native_link hash lookup emitter (kprog/build hash-lookup-kernel) | lookups into Hash, LRU, PerCPUHash and HashOfMaps go straight to the map type's lookup routine instead of the generic helper | 48af2849d | 25 host tests, 22 default-off byte comparisons | on |
| Runtime array dispatch | LTO | native_link, `--runtime-array-layout PATH` | array lookups in runtime-map mode use the target kernel's bpf_array layout from the boot BTF (elem_size 288, index_mask 292, value 304) | 9f51cfee7 | 27 host tests, 28 real link commands byte-identical with it off | on |
| Kernel and user memory reads as direct loads | LTO | native_link probe-read emitter, `--runtime-probe-read-layout PATH`, `--abi-load-sites true` | bpf_probe_read_kernel/user calls become direct loads with an EX_TYPE_BPF exception-table entry; a fault clears the destination and returns -EFAULT as the helper does | de0c62bd9, c2bb11c15 | kernel 36/36 executions in both configurations; 121 fault cases each way | on |
| smp_processor_id as a per-CPU load | LTO | native_link `helper_call_name` (`__native_x86_cpu_number`, `__native_x86_this_cpu_off`) | the helper call becomes a GS-relative per-CPU read, as the kernel inlines it | existing | (to be filled by perf) | on |
| LPM trie lookup | LTO | native_link LPM emitter | (to be filled by perf when it lands) | | kernel 3360 executions | in progress |
| Extra LFENCE removed | link output | native_link (to be filled by perf) | a speculation barrier the linker emitted beyond what the kernel JIT emits | 353458a68 | both configurations' kernel checks | on, re-timing |
| Katran map-lookup sinking | step 1 | kprog/build native_specialize_maps.py | map lookups sunk into the C unit before codegen | 529dd6d35 | same-day A/B 102.69 vs 103.11 ns/run | dropped: no gain |
| Branchless select (cmov) removal | step 1 | compiler flag candidate | cmov 140 to 0, jcc 613 to 692 in OTel's unwinder | candidate c17c7eeb | default bytes unchanged | candidate, untimed |
