# Post-CMOV-Fix Corpus Ablation

- Generated: 2026-03-12T23:09:57.077085+00:00
- Source inventory: `/home/yunwei37/workspace/bpf-benchmark/docs/tmp/corpus-runnability-results.json`
- Eligible runnable CMOV pool: 84 programs across 7 sources
- Full sample size: 12
- Smoke sample size: 6
- Kernel image: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/boot/bzImage`

## Sample Selection

The sample is restricted to loadable `packet_test_run` programs whose existing v3 policy comments report at least one CMOV site. This excludes non-runnable corpus projects such as Tetragon/Cilium from the VM timing run, even if they have CMOV-bearing policies.

| Source | Selected | CMOV Sites |
| --- | --- | --- |
| calico | 2 | 41 |
| katran | 2 | 9 |
| linux-selftests | 2 | 6 |
| suricata | 1 | 2 |
| tracee | 1 | 13 |
| xdp-tools | 2 | 2 |
| xdp-tutorial | 2 | 4 |
