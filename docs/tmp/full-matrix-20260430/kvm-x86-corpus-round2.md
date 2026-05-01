# KVM x86 Corpus Round 2 诊断与修复

日期：2026-05-01

## 结论

第二次失败不是 `dockerd` 启动、`docker load`、runtime container entrypoint 或 daemon init 卡死。只读检查失败现场的 Docker root image：

`docs/tmp/run.x86-kvm.corpus.faa08025/vm-tmp/bpf-benchmark-docker.img`

证据显示：

- `dockerd.log` 在 2026-05-01 04:57:46 UTC 已完成初始化并监听 `/run/docker.sock`。
- runtime container `2d14201c...` 在 2026-05-01 05:02:32 UTC 启动，状态仍是 `Running=true`。
- container json log 有完整 corpus stdout：22 个 app 都已 `app_start`，随后进入 baseline。
- 被 kill 时最后完整事件是 2026-05-01 05:34:23 UTC 的 `bpftrace/capable` baseline done，下一条是 `bpftrace/biosnoop` baseline start 的半截 JSON。
- daemon stderr 只有 watcher 的 `observed new BPF program id ...`，没有进入 ReJIT/optimize 阶段错误。

外层 `/tmp/vm-corpus.log` 没有 JSON event 的原因是 KVM executor 用 `script ... capture_output=True` 把 VM stdout 缓存在子进程结束后才写回。手动 kill 发生时，VM 内 Docker json log 已经有进度，但 host log 没被 flush。

真正的 corpus bug 是生命周期调度：driver 先启动全部 22 个 loader，再顺序做 30-sample baseline。SAMPLES=30 下，后面的 loader 会空等二十多分钟才开始 baseline；Calico/Otel/Cilium 在等待后出现状态过期：

- `calico/felix`: interface-bound HTTP readiness 失败。
- `otelcol-ebpf-profiler/profiling`: baseline 时启动时记录的 BPF program IDs 120-132 已经不在 BPF stats 中。
- `cilium/agent`: baseline 时启动时记录的 BPF program IDs 190-236 中多项已消失。

这符合 qemu 5-6 vCPU 满载但磁盘低写入的观察：VM 在跑 corpus workloads，不是在 image load 或 Docker runtime hang。

## 修复

代码改动摘要：

- `corpus/driver.py`
  - 改为每个 loader 独立执行 `start -> baseline -> ReJIT -> post-ReJIT -> stop`。
  - 保留原有 per-app fail-fast 行为：单 app baseline/ReJIT/post 错误进入该 app result，不过滤任何 BPF program。
  - daemon 仍是单个 suite-level session，runner Python 仍走 daemon socket + JSON 边界。
- `runner/libs/vm.py` / `runner/libs/kvm_executor.py`
  - KVM suite run 使用实时 stdout streaming；JSON progress 会直接进入外层 log，不再等 VM 进程正常退出后一次性写回。
- `Makefile`
  - 补 `daemon-tests` 目标，执行 `cargo test --manifest-path daemon/Cargo.toml`，使要求的验证入口存在。

## Host 复现

未运行 `make vm-corpus` / `make vm-e2e` / `make vm-micro`。

已验证 runtime container 和 corpus/daemon 启动边界：

```bash
docker run --rm --entrypoint bash bpf-benchmark/runner-runtime:x86_64 \
  -lc 'python3 -m runner.suites.corpus --help >/dev/null; python3 corpus/driver.py --help >/dev/null'
```

结果：正常退出。

非 privileged container 启动 daemon 会在 host 权限边界 fail-fast：

```text
BPF_PROG_GET_NEXT_ID: Operation not permitted
```

privileged host container 可启动 daemon 并监听 socket；用 `timeout 8s` 停止后看到：

```text
serve: listening on /tmp/bpfrejit-host-priv.sock
serve: shutting down
```

本地源码层也验证了：

```bash
python3 -m runner.suites.corpus --help
python3 corpus/driver.py --help
```

## 验证

已通过：

```bash
python3 -m py_compile corpus/driver.py runner/libs/vm.py runner/libs/kvm_executor.py
make lint
cd bpfopt && cargo test --workspace
cargo test --workspace --manifest-path bpfopt/Cargo.toml
make daemon-tests
```

## 给 Claude

下一步请直接跑 `make vm-corpus`。这次外层 log 应该实时出现 JSON progress；SAMPLES=30 的 full corpus 仍可能超过 36 分钟，不要仅因长时间 CPU 满载判定卡死。若仍失败，优先看实时 stdout 中最后一个 app/phase，再看 preserved artifact 和 Docker json log。
