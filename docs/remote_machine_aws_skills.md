# AWS Remote Machine Skills

> 目的：给 `bpf-benchmark` 提供一套可直接执行的 AWS 远程机器使用手册，覆盖起机、连接、自定义 kernel 安装、一次性切换启动项、结果验证和常见故障排查。
>
> 适用范围：本文以 `Amazon Linux 2023 ARM64` + `EC2` + `SSH` 为主，优先面向 ARM64 kernel 验证和 benchmark 机器管理。

---

## 1. 什么时候用哪种机器

- `t4g.micro`
  用途：本仓库当前唯一允许的 ARM64 远端机型。既用于 custom kernel 启动验证，也用于 ARM64 benchmark smoke。

当前规则非常明确：

- ARM64 benchmark 只用 `t4g.micro`
- 不用 `c7g.large`
- 不用 `c7g.xlarge`
- 不用任何其他更大 ARM64 机器

原因也很明确：

- 当前 pipeline 已经改成“本地 Docker 交叉编译 `micro_exec` + `scanner` -> `scp` 上传 -> `t4g.micro` 直接跑”
- 远端机器不再承担编译负载，只负责装 custom kernel、接收预编译产物、执行 smoke、下载结果
- 既然不再需要远端 native build，就没有理由为了编译速度去起大机器

---

## 2. 前置条件

本机需要：

- 已安装 `aws` CLI
- 已配置 AWS profile
- 能访问 `ec2`, `ssm`, `sts`, `pricing` 等常用 API

账号侧至少需要：

- 起 EC2 的权限
- 查实例状态和 console output 的权限
- 如果要走 Session Manager，需要实例角色 `AmazonSSMManagedInstanceCore`

本次实践里，账户没有配好 SSM 默认实例管理角色，所以最终走的是 `SSH`，不是 `SSM`。

---

## 3. 最小起机路径

### 3.1 选 AMI

ARM64 Amazon Linux 2023 可以直接从 SSM public parameter 取：

```bash
aws --profile <profile> --region <region> ssm get-parameter \
  --name /aws/service/ami-amazon-linux-latest/al2023-ami-kernel-default-arm64 \
  --query 'Parameter.Value' --output text
```

### 3.2 创建或复用 key pair

```bash
aws --profile <profile> --region <region> ec2 create-key-pair \
  --key-name <key-name> \
  --query 'KeyMaterial' --output text > ~/.ssh/<key-name>.pem

chmod 600 ~/.ssh/<key-name>.pem
```

如果已有 key pair，可以直接复用。

### 3.3 准备安全组

最小要求：

- 允许本机公网 IP 访问 `tcp/22`

### 3.4 起实例

```bash
aws --profile <profile> --region <region> ec2 run-instances \
  --image-id <ami-id> \
  --instance-type t4g.micro \
  --key-name <key-name> \
  --security-group-ids <sg-id> \
  --subnet-id <subnet-id> \
  --tag-specifications 'ResourceType=instance,Tags=[{Key=Name,Value=arm64-kernel-test}]' \
  --count 1
```

### 3.5 等实例 ready

```bash
aws --profile <profile> --region <region> ec2 describe-instance-status \
  --instance-ids <instance-id> --include-all-instances
```

关注三件事：

- `InstanceState.Name = running`
- `SystemStatus.Status = ok`
- `InstanceStatus.Status = ok`

---

## 4. 怎么连接

Amazon Linux 2023 默认用户是 `ec2-user`。

```bash
ssh -i ~/.ssh/<key-name>.pem ec2-user@<public-ip>
```

连上后先做基线检查：

```bash
uname -r
df -h /
nproc
free -h
command -v dracut
command -v grubby
sudo grubby --info=ALL
```

本次验证里，`grubby` 和 `dracut` 都在 AL2023 默认镜像里可用。

---

## 5. 推荐使用方式

### 5.1 先保留 stock kernel

不要一上来把默认启动项永久切到 custom kernel。更稳妥的流程是：

1. 安装 custom kernel 到 `/boot` 和 `/lib/modules/<ver>`
2. 生成新的 `initramfs`
3. 新增 grub entry
4. 把持久默认项设回 stock kernel
5. 用 `grub2-reboot` 做一次性切换
6. 重启
7. 用 `uname -r` 和网卡状态确认结果

### 5.2 文件落盘方式

这次实践里更稳的方式不是“跨机直接往 `/` 做 root 级 rsync”，而是：

1. 先把产物传到远端用户目录，例如 `~/codex-kernel-stage/`
2. 再在远端本地执行 `sudo install` / `sudo rsync`

这样可以把“网络传输问题”和“系统文件安装问题”分开。

### 5.3 ARM64 上优先用 `vmlinuz.efi`

在 `Amazon Linux 2023 ARM64` 上，当前 stock kernel 文件类型是：

```bash
file /boot/vmlinuz-$(uname -r)
```

结果是 `PE32+ executable (EFI application) Aarch64`。

因此在自定义 kernel 场景里，建议优先使用：

```bash
arch/arm64/boot/vmlinuz.efi
```

而不是只依赖 `Image.gz`。

### 5.4 安装 custom kernel 的最小命令

假设：

- kernel version 是 `7.0.0-rc2-codexarmtest`
- EFI kernel 在 `~/codex-kernel-stage/boot/vmlinuz-7.0.0-rc2-codexarmtest.efi`
- modules 已准备在 `/lib/modules/7.0.0-rc2-codexarmtest`

可以按下面做：

```bash
ver=7.0.0-rc2-codexarmtest
title="Codex ARM64 ($ver)"
stock=/boot/vmlinuz-$(uname -r)

sudo install -o root -g root -m 0755 \
  "$HOME/codex-kernel-stage/boot/vmlinuz-$ver.efi" \
  "/boot/vmlinuz-$ver"

sudo depmod -a "$ver"
sudo dracut --force "/boot/initramfs-$ver.img" "$ver"

sudo grubby --add-kernel "/boot/vmlinuz-$ver" \
  --initrd "/boot/initramfs-$ver.img" \
  --title "$title" \
  --copy-default

sudo grubby --set-default "$stock"
sudo grub2-reboot "$title"
sudo reboot
```

### 5.5 启动后怎么确认成功

```bash
uname -r
ip -brief addr show ens5
sudo grubby --default-kernel
sudo grub2-editenv list
```

本次成功验证的特征是：

- `uname -r = 7.0.0-rc2-codexarmtest`
- `ens5` 为 `UP`
- 仍然保持 `default-kernel` 指向 stock 6.1
- `next_entry` 被消费后清空

---

## 6. 常见错误与排查

### 6.1 机器能起，但 SSH 失败

先分清是：

- `Connection refused`
- `Connection timed out`
- `Connection closed by remote host`

先看实例级状态：

```bash
aws --profile <profile> --region <region> ec2 describe-instance-status \
  --instance-ids <instance-id> --include-all-instances
```

如果状态正常，再看 console：

```bash
aws --profile <profile> --region <region> ec2 get-console-output \
  --latest --instance-id <instance-id> --query Output --output text
```

### 6.2 custom kernel 启动了，但网络没起来

这是这次最关键的坑。

症状：

- console 里能看到 `Booting 'Codex ARM64 (...)'`
- `uname -r` 最终能变成 custom version
- 但 cloud-init 报 `169.254.169.254` 或 `fd00:ec2::254` `Network is unreachable`
- `Wait for Network to be Configured` 失败
- SSH 连不上

优先看两类 console 证据：

- 有没有 `ena 0000:00:05.0 ...`
- cloud-init 是否持续报 metadata service `Network is unreachable`

如果 `ena` 完全没出现，优先怀疑 ENA 驱动根本没编进去。

### 6.3 `olddefconfig` 后 ENA 驱动丢失

这次实际踩到的问题是：

- 远端 stock config 里有旧符号 `CONFIG_AMAZON_ENA_ETHERNET=m`
- 7.0 内核树里符号名变成了 `CONFIG_ENA_ETHERNET`
- 同时 `CONFIG_NET_VENDOR_AMAZON` 被关掉后，整个 Amazon NIC 菜单被跳过

结果就是：

- `CONFIG_NET_VENDOR_AMAZON=n`
- `CONFIG_ENA_ETHERNET` 没有进入 `.config`
- custom kernel 没有 ENA

正确修法：

```bash
scripts/config --file .config -e NET_VENDOR_AMAZON -e ENA_ETHERNET
make olddefconfig
```

确认：

```bash
rg 'NET_VENDOR_AMAZON|ENA_ETHERNET' .config
```

期望：

```text
CONFIG_NET_VENDOR_AMAZON=y
CONFIG_ENA_ETHERNET=y
```

### 6.4 `grubby --add-kernel` 意外改了默认启动项

这次 AL2023/BLS 环境里，`grubby --add-kernel` 后新 entry 可能直接排到 index 0，看起来像默认项被切过去了。

所以不要假设“add 只是新增，不会影响默认”。

安装后应立即确认：

```bash
sudo grubby --default-kernel
sudo grubby --info=ALL
```

如果默认项变成了 custom，立刻改回 stock：

```bash
sudo grubby --set-default /boot/vmlinuz-<stock-version>
```

然后只用：

```bash
sudo grub2-reboot "Codex ARM64 (<ver>)"
```

做 one-shot 切换。

### 6.5 custom kernel 已经起了，但 userspace 还没稳定

有时会出现：

- 早期 kernel log 正常
- network 还没 fully configured
- 稍后系统又自动关机或因为 metadata 超时被 cloud-init 拖住

这时不要只看一条 `uname -r`，要同时看：

- `ip -brief addr show ens5`
- console output 里 cloud-init 的 metadata 错误
- `grub2-editenv list`

### 6.6 source tree 太脏，ARM64 build 报奇怪错误

这次在本地构建时还碰到过两个非 AWS 问题：

- source tree 不干净，`O=` out-of-tree build 直接拒绝继续
- 清理副本时把 `vmlinux.*` 一起误排除了，导致 `arch/arm64/kernel/vmlinux.lds.S` 缺失

建议：

- 不直接在用户工作树里 `mrproper`
- 先复制一份临时源码副本再编
- 不要粗暴排除所有 `vmlinux.*`

### 6.7 initramfs 里到底有没有你需要的东西

```bash
sudo lsinitrd /boot/initramfs-<ver>.img | grep -E 'ena|nvme|xfs'
```

如果缺的是存储驱动，机器可能根本起不来。

如果缺的是 ENA，常见表现是：

- kernel 启了
- 根文件系统挂上了
- 但拿不到 metadata，SSH 也起不来

---

## 7. 推荐的最小验证流程

如果目标是跑当前仓库的 ARM64 kernel + benchmark smoke，建议按这个顺序：

1. 起一台 `t4g.micro`
2. 先确认 stock kernel + SSH 正常
3. 用远端 `/boot/config-$(uname -r)` 做 baseline config
4. 本地编译并准备 custom kernel 产物（`vmlinuz.efi` + modules）
5. 远端新增 custom kernel entry
6. 把持久默认项设回 stock
7. `grub2-reboot` 一次性启动 custom
8. 用 `uname -r` 和 `ip -brief addr show ens5` 验证 custom kernel 已启动且网络正常
9. 在本机执行 `make cross-arm64`，用 `Amazon Linux 2023 ARM64` Docker 镜像本地构建 `micro_exec` 和 `scanner`
   产物默认输出到 `.cache/aws-arm64/binaries/`
10. 上传预编译 bundle（`micro_exec`、`scanner`、运行库、micro smoke 资产、scanner smoke 资产）
11. 在 `t4g.micro` 上直接跑：
   - micro smoke：`simple` + `load_byte_recompose`
   - scanner smoke：`bpftool prog loadall -> scanner enumerate -> scanner enumerate --recompile`
12. 下载结果
13. 验证完成后立刻 `terminate-instances`

---

## 8. 清理与关机

终止实例：

```bash
aws --profile <profile> --region <region> ec2 terminate-instances \
  --instance-ids <instance-id>
```

建议：

- 验证失败的实例立刻终止
- 验证成功但暂时不用的实例也尽快终止，避免持续计费
- ARM64 benchmark 也不要升级到大机器；仍然只用 `t4g.micro`

---

## 9. 本次实践沉淀出的结论

- `t4g.micro` 足够做 custom kernel 启动验证和当前 ARM64 benchmark smoke
- `Amazon Linux 2023 ARM64` 上优先用 `vmlinuz.efi`
- `grubby --add-kernel` 后必须马上确认默认启动项
- `olddefconfig` 跨内核版本时，云厂商专有驱动选项可能悄悄丢失
- 对 AWS ARM64 而言，最关键的 network driver 是 `ENA`
- ARM64 用户态 benchmark 路径应当是“本地 AL2023 ARM64 Docker 交叉编译 -> 上传 -> `t4g.micro` 运行”，不要在远端安装编译工具链
- ARM64 benchmark 只用 `t4g.micro`，不要起 `c7g.*` 或其他大机器
- 遇到“起了但连不上”的第一反应应该是 `get-console-output --latest`
