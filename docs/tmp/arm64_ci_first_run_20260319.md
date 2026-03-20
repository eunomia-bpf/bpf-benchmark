# ARM64 CI First Run Summary (2026-03-19)

## Run Metadata

- Workflow: `ARM64 Baseline Benchmark` (`.github/workflows/arm64-benchmark.yml`)
- Successful run id: `23326256821`
- Successful job id: `67847978164`
- Successful run URL: `https://github.com/eunomia-bpf/bpf-benchmark/actions/runs/23326256821`
- Trigger time: `2026-03-20T02:16:26Z` (`2026-03-19 19:16:26 PDT`)
- Head commit: `69e53e0f454d4830a02d93096b40c30e7b34b3ee`
- Downloaded artifact root: `docs/tmp/arm64_ci_run_23326256821/arm64-baseline-results/`

## CI Iteration History

1. `cc336a2` introduced the ARM64 baseline workflow.
2. Run `23326028042` failed in checkout because `actions/checkout` tried `submodules: recursive` and hit the broken `vendor/linux-baseline` path.
3. `86c9d7b` switched to explicit submodule updates for only `vendor/llvmbpf`, `vendor/libbpf`, and `vendor/bpftool`.
4. Run `23326056549` failed in dependency install because `bpftool` has no install candidate on `ubuntu-24.04-arm`.
5. `93c8518` switched CI to vendored `bpftool` and passed that binary explicitly to the corpus code-size step.
6. Run `23326150435` got through build/preflight/corpus, but micro failed on missing Python dependency `elftools`.
7. `69e53e0` added `python3-pyelftools`.
8. Run `23326256821` succeeded and uploaded valid artifacts.

## Runner Environment

- Kernel: `Linux runnervm95407 6.14.0-1017-azure ... aarch64 GNU/Linux`
- Arch: `aarch64`
- Clang: `Ubuntu clang version 18.1.3 (1ubuntu1)`
- CMake: `3.31.6`
- Python: `3.12.3`
- bpftool: `v7.7.0` (vendored build)
- Kernel BTF: present at `/sys/kernel/btf/vmlinux`
- `bpf_jit_enable=1`

## Produced Artifacts

- `micro/results/arm64_pure_jit.json` (`2,021,484` bytes)
- `corpus/results/arm64/real_world_code_size_libbpf_bootstrap_arm64.json` (`706,155` bytes)
- `corpus/results/arm64/real_world_exec_time_libbpf_bootstrap_arm64.json` (`139,368` bytes)
- Matching Markdown reports plus preflight JSON/stderr/environment files

## Micro Baseline Summary

- Combined micro run succeeded with both runtimes: `llvmbpf` and `kernel`.
- Benchmarks measured: `62`
- llvmbpf had lower median exec time on `54/62` benchmarks.
- kernel had lower median exec time on `8/62` benchmarks.
- Geomean exec ratio (`llvmbpf/kernel`, median exec time): `0.590x`
- llvmbpf had lower median compile time on `8/62` benchmarks.
- kernel had lower median compile time on `54/62` benchmarks.
- Geomean compile ratio (`llvmbpf/kernel`, median compile time): `7.142x`

### Largest Kernel Exec Advantages

- `simple`: `3.083x`
- `simple_packet`: `2.000x`
- `memory_pair_sum`: `1.850x`
- `branch_flip_dense`: `1.291x`
- `switch_dispatch`: `1.164x`

### Largest llvmbpf Exec Advantages

- `binary_search`: `0.191x`
- `cmov_select`: `0.242x`
- `bpf_call_chain`: `0.261x`
- `nested_loop_3`: `0.315x`
- `multi_acc_8`: `0.316x`

### Largest Kernel Compile Advantages

- `mega_basic_block_2048`: `147.571x`
- `endian_swap_dense`: `133.000x`
- `extract_dense`: `130.053x`
- `branch_flip_dense`: `111.158x`
- `cond_select_dense`: `98.179x`

Interpretation: on ARM64, `llvmbpf` usually wins steady-state exec time in this pure-JIT suite, while kernel JIT usually wins compile latency, often by a large margin on dense / large code-shape benchmarks.

## Corpus Code-Size Summary (`libbpf-bootstrap`)

- Source files considered: `15`
- Source builds succeeded: `15/15`
- Program inventories succeeded: `15/15`
- Programs discovered: `24`
- Programs with both runtimes ok: `24/24`
- Geomean native code-size ratio (`llvmbpf/kernel`): `0.310x`
- Median native code-size ratio (`llvmbpf/kernel`): `0.308x`
- Ratio range: `0.000x` to `0.671x`

### Smallest llvmbpf / kernel Code-Size Ratios

- `examples/c/ksyscall.bpf.c` `entry_probe`: `0 / 376 B` (`0.000x`)
- `examples/c/ksyscall.bpf.c` `tgkill_entry`: `0 / 440 B` (`0.000x`)
- `examples/c/minimal_ns.bpf.c` `handle_tp`: `0 / 208 B` (`0.000x`)
- `examples/c/usdt.bpf.c` `usdt_auto_attach`: `0 / 944 B` (`0.000x`)
- `examples/c/usdt.bpf.c` `usdt_manual_attach`: `0 / 888 B` (`0.000x`)

### Largest llvmbpf / kernel Code-Size Ratios

- `examples/c/minimal_legacy.bpf.c` `handle_tp`: `204 / 304 B` (`0.671x`)
- `examples/c/sockfilter.bpf.c` `socket_handler`: `332 / 560 B` (`0.593x`)
- `examples/c/profile.bpf.c` `profile`: `200 / 384 B` (`0.521x`)
- `examples/c/tc.bpf.c` `tc_ingress`: `80 / 160 B` (`0.500x`)
- `examples/c/task_iter.bpf.c` `get_tasks`: `164 / 344 B` (`0.477x`)

Interpretation: on this ARM64 run, llvmbpf generally produced substantially smaller native code than kernel JIT for `libbpf-bootstrap`, with a geomean size ratio near `31%`.

## Corpus Exec-Time Summary (`libbpf-bootstrap`)

- Programs paired from the code-size input: `24`
- Kernel `BPF_PROG_TEST_RUN` ok: `1`
- llvmbpf runs ok: `1`
- Paired exec comparisons completed: `1`
- Geomean exec ratio (`llvmbpf/kernel`): `0.146x`

### Successful Paired Exec Result

- `examples/c/tc.bpf.c` `tc_ingress`: `39 ns` (`llvmbpf`) vs `267 ns` (`kernel`), ratio `0.146x`

### Limitation

- `23/24` corpus exec-time attempts failed on the kernel side with the same reason:
  `io-mode packet requires an XDP or skb packet context`

Interpretation: the workflow now produces valid corpus exec artifacts, but current exec-time coverage is effectively limited to packet-context-compatible programs. This is a harness/input-mode limitation, not a workflow bring-up failure.

## Residual Warnings

- `actions/checkout@v4` and `actions/upload-artifact@v4` emit a Node 20 deprecation warning. This is non-blocking for now.
- `actions/checkout` still emits a non-fatal post-job warning about `vendor/linux-baseline` during cleanup. Main job steps and artifact upload are unaffected.

## Final Status

- ARM64 workflow runs on `ubuntu-24.04-arm`.
- Micro benchmarks run with `--runtime llvmbpf --runtime kernel`.
- Corpus run targets `libbpf-bootstrap`.
- Artifacts are uploaded to GitHub Actions and were downloaded locally for inspection.
- The first successful ARM64 baseline data set is now recorded.
