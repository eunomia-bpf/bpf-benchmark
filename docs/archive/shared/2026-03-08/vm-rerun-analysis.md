# VM Rerun Analysis

## Run metadata

- VM pure-JIT file: `micro/results/vm_pure_jit_with_cmov.json`
- VM runtime file: `micro/results/vm_runtime_with_map_lookup_repeat.json`
- Host pure-JIT file: `micro/results/pure_jit_with_cmov.json`
- Host runtime file: `micro/results/runtime_with_map_lookup_repeat.json`
- Host kernel: `6.15.11-061511-generic`
- VM kernel: `7.0.0-rc2-gc23719abc330`
- Host run parameters: 10 iterations, 2 warmups, repeat 500
- VM run parameters: 5 iterations, 1 warmup, repeat 200
- Comparison basis: kernel `exec_ns` median per benchmark

## Execution notes

- The guest booted successfully with `virtme-ng`, but the direct `micro/run_micro.py` path tried to rebuild `micro_exec` and failed inside the guest because CMake attempted to fetch `spdlog` from GitHub and DNS resolution failed.
- To keep the VM run on kernel `7.0-rc2`, I used `tmp/run_micro_nobuild.py` so the guest reused the already-built host artifacts.
- Result persistence also needed an adjustment: `vng`'s default copy-on-write root did not keep new JSON files on the host, so the final successful runs used `--rwdir` only for `micro/results` and `tmp`.
- Both runtimes (`kernel` and `llvmbpf`) were captured successfully in the VM. The main comparison below focuses on kernel runtime, per request.

## Kernel summary

- Pure-JIT overlap: 50 benchmarks
- Pure-JIT kernel geomean VM/Host: `0.993x`
- Runtime overlap: 11 benchmarks
- Runtime kernel geomean VM/Host: `1.049x`
- Combined overlap: 61 benchmarks
- Combined kernel geomean VM/Host: `1.003x`

Interpretation:

- For the pure-JIT suite, VM kernel `7.0-rc2` is effectively at parity with host kernel `6.15.11`, with a slight `0.7%` advantage on the geomean.
- For the runtime suite, VM kernel `7.0-rc2` is about `4.9%` slower on the geomean.
- Across both suites combined, the VM kernel is essentially flat versus the host baseline (`+0.3%` slower geomean).

## `cmov_select` result

- Host kernel median: `815 ns`
- VM kernel median: `760 ns`
- VM/Host ratio: `0.933x`

This is the clearest answer to the main question: on `cmov_select`, kernel `7.0-rc2` in the VM was about `6.7%` faster than the host `6.15.11` kernel.

## Where `7.0-rc2` improved

Pure-JIT kernel results:

- Faster on `23 / 50` benchmarks, slower on `26 / 50`, unchanged on `1 / 50`.
- Notable wins with both medians above `100 ns`:
- `spill_pressure`: host `411 ns`, VM `248 ns`, ratio `0.603x`
- `stride_load_4`: host `338 ns`, VM `233 ns`, ratio `0.689x`
- `multi_acc_4`: host `361.5 ns`, VM `259 ns`, ratio `0.716x`
- `alu32_64_pingpong`: host `488 ns`, VM `357 ns`, ratio `0.732x`
- `dep_chain_long`: host `546 ns`, VM `424 ns`, ratio `0.777x`
- `const_fold_chain`: host `396.5 ns`, VM `315 ns`, ratio `0.794x`
- `cmov_select`: host `815 ns`, VM `760 ns`, ratio `0.933x`

Runtime kernel results:

- Faster on `5 / 11` benchmarks, slower on `6 / 11`.
- Main wins:
- `probe_read_heavy`: host `441 ns`, VM `242 ns`, ratio `0.549x`
- `atomic_counter_xadd`: host `295.5 ns`, VM `198 ns`, ratio `0.670x`
- `hash_map_lookup`: host `644 ns`, VM `484 ns`, ratio `0.752x`
- `map_lookup_repeat`: host `642 ns`, VM `639 ns`, ratio `0.995x`

## Main regressions

Pure-JIT kernel regressions:

- `local_call_fanout`: host `96.5 ns`, VM `215 ns`, ratio `2.228x`
- `packet_rss_hash`: host `15.5 ns`, VM `31 ns`, ratio `2.000x`
- `packet_redundant_bounds`: host `135 ns`, VM `236 ns`, ratio `1.748x`
- `load_byte_recompose`: host `199.5 ns`, VM `332 ns`, ratio `1.664x`
- `dep_chain_short`: host `107 ns`, VM `178 ns`, ratio `1.664x`

Runtime kernel regressions:

- `helper_call_10`: host `144 ns`, VM `467 ns`, ratio `3.243x`
- `percpu_map_update`: host `332 ns`, VM `534 ns`, ratio `1.608x`
- `get_time_heavy`: host `1690.5 ns`, VM `2408 ns`, ratio `1.424x`
- `helper_call_100`: host `1467.5 ns`, VM `1968 ns`, ratio `1.341x`

## Secondary note on llvmbpf

- Pure-JIT llvmbpf geomean VM/Host: `0.967x`
- Runtime llvmbpf geomean VM/Host: `1.143x`
- Combined llvmbpf geomean VM/Host: `0.996x`

So the VM rerun did exercise both runtimes successfully, but unlike the kernel-only question there is no strong overall llvmbpf shift here.

## Caveats

- The host and VM runs were not parameter-matched: host used `10/2/500`, VM used `5/1/200`.
- The guest emitted environment warnings (`cpu_governor` unknown, turbo enabled, no CPU affinity, `perf_event_paranoid=2`), so this is useful comparative data but not a publication-grade rerun.
- Some of the largest percentage deltas are on very small kernels (< `100 ns`), where timer granularity and environment noise matter more.
- `cmov_select` is less affected by that caveat because both medians are well above the sub-`100 ns` region.
