# ARM64 Cross-Build Pipeline Fix Report

日期：2026-03-20（本地时区 America/Vancouver）  
AWS 区域：`us-east-1`  
AWS profile：`codex-ec2`  
约束：未 commit，未 push；ARM64 远端机型只使用 `t4g.micro`

## 1. 结论

本次 ARM64 cross-build pipeline 已修复并完成端到端验证：

- 本地 `Docker` 交叉编译现在基于 `Amazon Linux 2023 ARM64` 运行时兼容环境产出二进制
- `make cross-arm64` 会把 `micro_exec`、`scanner` 和所需运行库输出到 `.cache/aws-arm64/binaries/`
- `runner/scripts/aws_arm64.sh` 已改成上传本地预编译 bundle，远端只安装运行时依赖
- `t4g.micro` 上完成了 custom kernel 安装、重启验证、micro smoke、scanner enumerate、scanner enumerate --recompile
- 验证结束后实例已 terminate，并确认 `us-east-1` 没有残留的 `bpf-benchmark-arm64` 实例

## 2. 实际修改

本次实际生效的改动位于以下路径：

- `runner/docker/arm64-crossbuild.Dockerfile`
- `runner/scripts/aws_arm64.sh`
- `Makefile`
- `docs/remote_machine_aws_skills.md`

说明：

- 仓库当前存在一次目录重组中的工作树状态；原先根目录下的 `docker/arm64-crossbuild.Dockerfile` 和 `scripts/aws_arm64.sh` 在当前工作区表现为 deleted
- 对应的实际可用文件位于 `runner/docker/` 和 `runner/scripts/`
- 因此 `Makefile` 已明确指向 `runner/...` 路径，保证 pipeline 在当前工作区可直接运行

### 2.1 Cross-build 容器

`runner/docker/arm64-crossbuild.Dockerfile` 现在：

- 使用 `amazonlinux:2023` 作为 base image
- 安装 `gcc-c++`、`cmake`、`yaml-cpp-devel`、`elfutils-libelf-devel`、`zlib-devel`、`libzstd-devel`
- 安装 `kernel6.18-libbpf-devel`

效果：

- 产出的 ARM64 `micro_exec.real` 与 `bpf-jit-scanner.real` 使用 AL2023 glibc ABI
- 本地 bundle 额外携带运行库：`libbpf.so.1`、`libelf.so.1`、`libstdc++.so.6`、`libgcc_s.so.1`、`libyaml-cpp.so.0.6`、`libz.so.1`、`libzstd.so.1`

### 2.2 Makefile

新增并接通：

- `make cross-arm64`

行为：

- 先构建 AL2023 ARM64 cross-build image
- 在容器里构建 `runner/micro_exec` 与 `scanner/bpf-jit-scanner`
- 将 wrapper、real binary、运行库统一输出到：
  - `.cache/aws-arm64/binaries/runner/build/`
  - `.cache/aws-arm64/binaries/scanner/build/`
  - `.cache/aws-arm64/binaries/lib/`

同时：

- `AWS_ARM64_INSTANCE_TYPE` 默认值改为 `t4g.micro`
- `aws-arm64-benchmark` 与 `aws-arm64` 依赖 `cross-arm64`

### 2.3 AWS ARM64 脚本

`runner/scripts/aws_arm64.sh` 现在具备以下行为：

- 默认实例类型：`t4g.micro`
- 每个入口点先做实例检查：
  - `describe-instances` 查看 region 中所有非 terminated 实例
  - 额外检查 `Name=bpf-benchmark-arm64` 的 tagged 实例
- `setup` 只安装运行时依赖：
  - `bpftool dracut grubby tar gzip elfutils-libelf zlib zstd`
- `benchmark` 改为：
  - 本地 `cross-arm64`
  - 本地组装 benchmark bundle
  - 上传 bundle 到远端
  - 远端只执行 smoke，不做编译
- scanner smoke 增加了兼容逻辑：
  - 若远端 `bpftool prog loadall ... kernel_btf` 语法不支持，则自动回退到不带 `kernel_btf` 的 loadall
- 修复两个脚本缺陷：
  - `bpffs` pin 路径检查改为 `sudo test -e`，避免 AL2023 上普通用户因权限失败
  - `full` 的 EXIT trap 不再引用失效的局部变量，避免 `set -u` 下 cleanup 异常
- `scp` 改为静默模式，减少交互式 progress meter 对日志/PTY 的干扰

## 3. 本地验证

### 3.1 交叉编译

已成功执行：

```bash
make arm64-crossbuild-image
make cross-arm64
```

产物位于：

- `.cache/aws-arm64/binaries/runner/build/micro_exec`
- `.cache/aws-arm64/binaries/runner/build/micro_exec.real`
- `.cache/aws-arm64/binaries/scanner/build/bpf-jit-scanner`
- `.cache/aws-arm64/binaries/scanner/build/bpf-jit-scanner.real`
- `.cache/aws-arm64/binaries/lib/`

关键确认：

- `file` 显示两个 `.real` 二进制均为 `ARM aarch64`
- wrapper 会自动设置 `LD_LIBRARY_PATH` 指向 bundle 内的 `lib/`

### 3.2 AL2023 兼容性

在干净的 `amazonlinux:2023` ARM64 容器中已直接运行：

- `micro_exec --help`
- `bpf-jit-scanner --help`

这一步证明本地产物可在 AL2023 glibc/runtime 语境下正常启动，不再依赖 Ubuntu/Debian 风格的 host ABI。

## 4. AWS 端到端验证

### 4.1 使用的实例

最终成功验证使用的实例：

- `i-03a53b76f8020b33b`
- 类型：`t4g.micro`
- 区域：`us-east-1`

此前为调试和中间验证启动过：

- `i-03f1d75d1ee73d6f7`
- `i-09d12bde5325b9e65`

这些实例也都已 terminate。

### 4.2 实际执行

成功执行的步骤：

1. `launch`
2. `setup`
3. `benchmark`
4. `terminate`

其中 `setup` 验证日志：

- `.cache/aws-arm64/results/setup_verify_7.0.0-rc2+_20260321_030011.log`

关键结果：

- 远端 `uname -r` 为 `7.0.0-rc2+`
- custom kernel 启动后网络正常
- benchmark 结果已拉回本地：
  - `.cache/aws-arm64/results/benchmark_20260321_030241/results/`

### 4.3 Smoke 结果

本地已回收的结果文件包括：

- `simple.kernel.iter1.json`
- `load_byte_recompose.kernel.iter1.json`
- `load_byte_recompose.kernel_recompile.iter1.json`
- `scanner.prog.json`
- `scanner.prog_id.txt`
- `scanner.enumerate.json`
- `scanner.recompile.json`

关键观察：

- `scanner.prog_id.txt` 为 `107`
- `scanner.enumerate.json` 成功枚举到 Katran `balancer_ingress` 的 JIT site
- `scanner.recompile.json` 显示：
  - `recompile_ok: true`
  - `applied_sites: 6`
- `scanner.loadall.kernel_btf.stderr` 显示当前远端 `bpftool` 不接受 `kernel_btf` 额外参数
- fallback loadall 成功，因此 smoke 未受影响

## 5. 残留实例检查

验证结束后已执行：

```bash
AWS_PAGER='' aws --profile codex-ec2 --region us-east-1 ec2 describe-instances \
  --filters Name=tag:Name,Values=bpf-benchmark-arm64 Name=instance-state-name,Values=pending,running,stopping,stopped \
  --query 'Reservations[].Instances[].[InstanceId,InstanceType,State.Name,PublicIpAddress]' \
  --output table
```

结果为空。

另外单独确认：

- `i-03a53b76f8020b33b` 状态为 `terminated`

结论：

- `us-east-1` 当前没有残留的 `bpf-benchmark-arm64` 实例

## 6. 备注

- 在 Codex 的带 PTY 会话里运行 `aws_arm64.sh benchmark/full` 时，曾出现过 `141`
- 该现象来自交互式传输输出和 PTY 的组合，不代表 benchmark 失败
- 以非 TTY 方式运行时，`benchmark` 已稳定返回 `0` 并成功拉回结果
- 本次已将 `scp` 切为静默模式，以降低这类日志噪声

## 7. 未做的事

- 未 commit
- 未 push

