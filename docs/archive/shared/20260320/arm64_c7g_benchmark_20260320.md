# ARM64 c7g.large benchmark (2026-03-20)

## Environment

- AWS: `codex-ec2` / `us-east-1` / `c7g.large` / instance `i-0959a4eae87f88090`
- Kernel: `7.0.0-rc2+` from cached `.cache/aws-arm64/` artifacts
- Build/run host: `Linux-7.0.0-rc2+-aarch64-with-glibc2.34`
- Parameters: `iterations=10`, `warmups=2`, `repeat=200`, pinned to `CPU 0`
- Driver warnings: `cpu_governor=unknown`, `turbo_state=unknown`, `perf_event_paranoid=2`

## llvmbpf vs kernel micro

- Completed `62 / 62` benchmarks.
- `llvmbpf / kernel` exec ratio: median `0.509x`, geometric mean `0.522x`.
- llvmbpf was faster on `58` benchmarks; kernel was faster on `4` benchmarks.
- Largest kernel wins:
  - `cmov_select` `0.221x` (`283.0` ns vs `1281.5` ns)
  - `bpf_call_chain` `0.269x` (`336.0` ns vs `1251.0` ns)
  - `binary_search` `0.283x` (`342.0` ns vs `1208.0` ns)
  - `load_byte_recompose` `0.291x` (`117.0` ns vs `402.0` ns)
  - `bounds_ladder` `0.305x` (`102.0` ns vs `334.0` ns)
- Largest llvmbpf wins:
  - `branch_flip_dense` `1.553x` (`501.0` ns vs `322.5` ns)
  - `switch_dispatch` `1.243x` (`493.0` ns vs `396.5` ns)
  - `bounds_check_heavy` `1.123x` (`466.5` ns vs `415.5` ns)
  - `cond_select_dense` `1.037x` (`113.0` ns vs `109.0` ns)
  - `load_byte` `0.958x` (`385.0` ns vs `402.0` ns)

## scanner-based stock vs recompile

- Completed `62 / 62` benchmarks with external `bpftool prog load/run` plus `scanner enumerate --prog-id --recompile`.
- Scanner detected `0` sites across the full micro suite and applied `0` recompile sites.
- Benchmarks with any detected site: `0 / 62`.
- Median absolute stock/recompile exec delta: `1.0` ns.
- Max absolute stock/recompile exec delta: `24.0` ns.
- Result: on `c7g.large`, the scanner-based recompile path was effectively a no-op for this micro suite.

## Katran balancer_ingress smoke

- `bpftool prog loadall ... kernel_btf /sys/kernel/btf/vmlinux` failed with parser error (`rc=255`), so the fallback path without `kernel_btf` was used.
- Fallback `loadall` succeeded (`rc=0`).
- Pinned program: `id=4884`, `name=balancer_ingress`, `bytes_xlated=23840`, `bytes_jited=14472`.
- On this `c7g.large` run, `scanner enumerate` and `scanner enumerate --recompile` both returned empty arrays.
- Inference: this differs from the earlier `t4g.micro` ARM64 smoke (`74` sites, `6` applied on 2026-03-20) and likely reflects Graviton3/c7g ARM64 JIT output diverging from the Graviton2/t4g pattern set currently recognized by the scanner.

## Cleanup

- EC2 instance `i-0959a4eae87f88090` was terminated after result collection.
- Local AWS ARM64 state cache was cleared (`.cache/aws-arm64/state/instance.env` removed).
- Final JSON artifact: `micro/results/dev/arm64_c7g_micro_20260320.json`.
