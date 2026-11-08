# Complete ARM BCC execution inputs

The23 application programs generate C/B and pass the stock verifier on the five-step path. Both complete BCC phases finish successfully with the native LSE input profile.

| Phase | Program counter rows | Positive rows | BPF calls |
| --- | ---: | ---: | ---: |
| JIT | 23 | 20 | 183822 |
| Native | 23 | 20 | 192059 |

Each phase executes8 IPv4 and8 IPv6 TCP connections plus regular-file fsync and16MiB of4KiB libaio direct writes. Native and JIT each record8 executions for each of the4 TCP entry/return probes. The syscall stressor records507 bogo operations per phase; duration-driven stressors retain their individual counts. work-counters.json contains all fixed inputs, fio results and per-program counters.

The earlier LSE run had13 positive counters; these real TCP and block inputs raise that count to20. Three hooks retain zero counters in both phases: blk_account_io_merge_bio, block_rq_insert and fentry_vfs_fsync. The next input targets queue insertion, BIO merging and AIO fsync. The actual native source/program set remains23. QEMU timing supplies functional evidence.

Raw paired guest and compiler/service records are in the adjacent summary/archive from584ae11ac. Source inputs and workload disk setup are retained in ../launch-inputs.tar.gz and ../input.py.
