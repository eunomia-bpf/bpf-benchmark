# AWS ARM64 Benchmark Run - 2026-03-20

## Scope

Requested work:

- fix `scripts/aws_arm64.sh` so AWS CLI calls honor profile `codex-ec2`
- run the ARM64 AWS flow on `t4g.micro` in `us-east-1`
- install the custom ARM64 kernel, verify reboot, run smoke and extra benchmarks
- always terminate instances

Constraints followed:

- no commit
- no push
- all launched instances were terminated

## Script Changes

Updated `scripts/aws_arm64.sh`:

1. Added profile support.
   - `AWS_ARM64_PROFILE="${AWS_ARM64_PROFILE:-codex-ec2}"`
   - new `_aws()` helper now runs `aws --profile "$AWS_ARM64_PROFILE" ...`
   - region detection now uses the configured profile via `aws configure get region`
   - usage text now documents `AWS_ARM64_PROFILE`

2. Fixed stdout contamination in `build_kernel_artifacts()`.
   - `log()` now writes to stderr
   - the internal `make` calls used during artifact build now write to stderr
   - this keeps `kernel_release="$(build_kernel_artifacts)"` clean

3. Fixed reboot control flow in `setup_instance()`.
   - the remote reboot is now detached with `nohup ... systemctl reboot`
   - SSH can return successfully and the script continues into reconnect + verification

Validation:

```bash
AWS_ARM64_PROFILE=codex-ec2 bash -n scripts/aws_arm64.sh
```

Status: passed.

## Attempt History

All attempts used profile `codex-ec2`, region `us-east-1`, and a shell `EXIT` trap for termination.

1. `i-0ba35a4a7e0431370`
   - early trial during bring-up
   - terminated

2. `i-0cf2b16b00c7de749`
   - failed because `build_kernel_artifacts()` polluted stdout and corrupted the kernel artifact path
   - terminated

3. `i-0c2368a26c76e0e59`
   - failed because `sudo reboot` closed SSH before local post-reboot verification ran
   - terminated

4. `i-0b7b21931167e0b28`
   - kernel install + reboot succeeded
   - `scripts/aws_arm64.sh benchmark` failed because uploaded `micro/build-arm64/runner/micro_exec` required newer glibc symbols (`GLIBC_2.38`, `GLIBC_2.36`) than Amazon Linux 2023 provides
   - terminated

5. `i-0b2c3006cc9389a85`
   - final successful run
   - custom kernel boot verified
   - `micro_exec` built natively on the AL2023 ARM64 instance
   - smoke + extra benchmarks collected
   - terminated

## Final Successful Run

Instance:

- instance id: `i-0b2c3006cc9389a85`
- type: `t4g.micro`
- region: `us-east-1`
- profile: `codex-ec2`

Kernel verification after install:

- `uname -r`: `7.0.0-rc2+`
- `ens5`: `UP`
- persistent default kernel remained stock: `/boot/vmlinuz-6.1.163-186.299.amzn2023.aarch64`
- one-shot reboot entry was consumed successfully

Verification artifacts:

- `.cache/aws-arm64/results/setup_verify_7.0.0-rc2+_20260320_165456.log`
- `.cache/aws-arm64/results/smoke_native_20260320_165615/results/`
- `.cache/aws-arm64/results/extra_native_20260320_165615/extra-results/`

## Benchmark Execution Notes

`scripts/aws_arm64.sh benchmark` is still not directly usable on AL2023 with the current local `micro/build-arm64` bundle, because that binary was produced against a newer glibc baseline than the instance has.

For the final successful run, I used this workaround:

1. `scripts/aws_arm64.sh setup <ip>` installed and verified the custom kernel.
2. Uploaded a minimal source bundle:
   - `micro/runner`
   - `scanner`
   - `vendor/libbpf`
   - `micro/programs`
   - `micro/generated-inputs`
   - `micro/policies`
3. Installed build deps on the instance:
   - `cmake make gcc-c++ pkgconfig elfutils-libelf-devel yaml-cpp-devel zlib-devel libzstd-devel`
4. Built `micro_exec` natively on AL2023 ARM64 with `MICRO_EXEC_ENABLE_LLVMBPF=OFF`
5. Ran the same kernel runtime smoke flow plus extra benchmarks

## Results

### Smoke

| Benchmark | Mode | Applied | Exec ns | Stock exec ns | Notes |
| --- | --- | --- | ---: | ---: | --- |
| `simple` | `kernel` | no | 35 | n/a | smoke sanity OK |
| `load_byte_recompose` | `kernel` | no | 605 | n/a | stock OK |
| `load_byte_recompose` | `kernel_recompile` | no | 663 | 655 | policy selected 0 rules |
| `cmov_dense` | `kernel` | no | 147 | n/a | stock OK |
| `cmov_dense` | `kernel_recompile` | yes | 228 | 246 | 26 rotate sites applied |

### Extra

| Benchmark | Mode | Applied | Exec ns | Stock exec ns | Notes |
| --- | --- | --- | ---: | ---: | --- |
| `bpf_call_chain` | `kernel` | no | 1618 | n/a | stock OK |
| `bpf_call_chain` | `kernel_recompile` | yes | 1659 | 1657 | 2 wide sites applied |
| `bounds_ladder` | `kernel` | no | 470 | n/a | stock OK |
| `bounds_ladder` | `kernel_recompile` | yes | 498 | 521 | 2 cmov + 2 wide sites applied |
| `log2_fold` | `kernel` | no | 993 | n/a | stock OK |
| `log2_fold` | `kernel_recompile` | no | 957 | 888 | policy selected 0 rules |
| `mixed_alu_mem` | `kernel` | no | 2627 | n/a | stock OK |
| `mixed_alu_mem` | `kernel_recompile` | no | 2669 | 2683 | policy selected 0 rules |

Functional result:

- all collected benchmark outputs returned the same `result` value between stock and recompile variants
- `cmov_dense`, `bpf_call_chain`, and `bounds_ladder` exercised successful `BPF_PROG_JIT_RECOMPILE`
- `load_byte_recompose`, `log2_fold`, and `mixed_alu_mem` ran successfully but their current policy files selected no applicable rules on this kernel/userspace combination

## Cleanup

Final termination checks:

- `i-0b2c3006cc9389a85` state: `terminated`
- no `bpf-benchmark` EC2 instances remained in `pending`, `running`, `stopping`, `stopped`, or `shutting-down`

## Residual Issues

1. `scripts/aws_arm64.sh benchmark` still assumes the local ARM64 `micro_exec` bundle is ABI-compatible with the target distro.
   - current local bundle requires newer glibc than AL2023 provides
   - native on-instance build worked around this and allowed the benchmark run to complete

2. `make kernel-arm64` still builds the default `vendor/linux-framework/build-arm64` tree.
   - this run used prebuilt AWS-compatible artifacts from `vendor/linux-framework/build-arm64-aws`
   - the AWS setup path succeeded with those artifacts, but the Makefile/build-dir mismatch is still worth cleaning up separately
