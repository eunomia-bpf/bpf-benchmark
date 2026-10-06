# P89 Disk Audit

日期：2026-04-30  
范围：只读审计；未删除文件，未修改代码。`runner/build.mk` 在当前仓库不存在，实际 build 入口是 [runner/mk/build.mk](/home/yunwei37/workspace/bpf-benchmark/runner/mk/build.mk:1)，由 [Makefile](/home/yunwei37/workspace/bpf-benchmark/Makefile:26) include。

## 结论

| 严重度 | 发现 | 证据 |
| --- | --- | --- |
| BLOCKER | Docker/BuildKit 是本机满盘主因。`/var/lib/docker` 实占 213G，其中 `overlay2` 197G；`docker system df` 显示 Build Cache 183.4G，全部 reclaimable。 | `docker system df`: Build Cache 1642 entries / 183.4GB；`sudo du -sh /var/lib/docker`: 213G；`sudo du -sh /var/lib/docker/*`: overlay2 197G |
| HIGH | 最近 P89 KVM corpus 结果跨 run 累积 15G；整个 `corpus/results` 18G。 | 13 个 `corpus/results/x86_kvm_p89_kinsn_corpus_*` 目录合计 15G |
| HIGH | `e2e/results` 200 个目录合计 15G，无历史轮数限制。 | `du -sh e2e/results`: 15G |
| MEDIUM | `docs/tmp` 有 KVM docker sparse image 残留：2 个 64G apparent size 文件，当前实际占用 519M；失败/崩溃时可变成大实际占用。 | `docs/tmp/20260424/vm-tmp/bpf-benchmark-docker.img` 517M actual / 64G apparent；`docs/tmp/20260430/...` 2.3M actual / 64G apparent |
| MEDIUM | 全局 `~/.cache` 65G，但主要不是本仓库 P89：HuggingFace 32G、Go build cache 27G。 | `du -sh ~/.cache/*` |

## 顶层占用表

| 路径 | 实占 |
| --- | ---: |
| `/var/lib/docker` | 213G |
| `/var/lib/docker/overlay2` | 197G |
| `/home/yunwei37/.cache` | 65G |
| `/home/yunwei37/.cache/huggingface` | 32G |
| `/home/yunwei37/.cache/go-build` | 27G |
| `corpus` | 20G |
| `corpus/results` | 18G |
| `e2e` | 15G |
| `e2e/results` | 15G |
| `.cache` | 3.7G |
| `.cache/repo-artifacts` | 2.9G |
| `vendor` | 3.0G |
| `docs` | 2.3G |
| `.git` | 1.1G |
| `runner` | 859M |
| `/tmp` | 315M |

当前 root 分区：`/dev/nvme0n1p2` 915G，757G used，112G avail，88%。

## Docker 占用

| 项 | 数量/大小 |
| --- | ---: |
| Images | 14 images / 34.61GB / 34.61GB reclaimable |
| Containers | 1 created container / 0B writable |
| Volumes | 5 volumes / 97.77MB reclaimable |
| Build cache | 1642 entries / 183.4GB reclaimable |
| `docker buildx du` | 207.7GB total, 183.4GB private, 24.27GB shared |

Tagged image size:

| Image | Size |
| --- | ---: |
| `bpf-benchmark/runner-runtime:x86_64` | 8.43GB |
| `bpf-benchmark/runner-runtime:arm64` | 7.47GB |
| `bpf-benchmark/kernel-fork:x86_64-a1b8bade1` | 4.17GB |
| `bpf-benchmark/kernel-fork:arm64-a1b8bade1` | 3.77GB |
| `bpf-benchmark/katran-artifacts:x86_64` | 378MB |
| `bpf-benchmark/katran-artifacts:arm64` | 379MB |

Largest final/runtime history layers observed:

| Layer | Size |
| --- | ---: |
| `runner-runtime-build-base` apt install | 2.76GB |
| kernel modules copied into runtime artifacts | 1.56GB |
| `corpus/bcf` copied into final runtime | 693MB |
| kernel headers copied into runtime artifacts | 472MB |
| tracee/cilium/calico/tetragon app copies | hundreds of MB combined |
| `kernel-fork` full `vendor/linux-framework` COPY | 1.63GB |
| `kernel-fork` build/artifact RUN layer | 2.06GB |

BuildKit duplicate-layer evidence:

| 严重度 | Pattern | Count |
| --- | --- | ---: |
| BLOCKER | `apt-get install` build snapshots, including 2.5G-3.0G variants | 20 |
| HIGH | `COPY bpfopt ./bpfopt` snapshots, many 1.7G-2.45G | 32 |
| HIGH | `COPY corpus/bcf ./corpus/bcf` snapshots, 692.7MB each | 43 |
| HIGH | `COPY e2e/cases ./e2e/cases` snapshots | 43 |
| MEDIUM | `COPY vendor/linux-framework ./vendor/linux-framework` snapshots | 3 |

`/var/lib/docker/buildkit` itself is only 314M metadata; the 183G BuildKit cache is materialized mostly as overlay2 snapshots.

## Dockerfile 反模式

| 严重度 | 位置 | 违反/风险 | 影响 |
| --- | --- | --- | --- |
| HIGH | [runner/containers/runner-runtime.Dockerfile:459](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:459), [runner/containers/runner-runtime.Dockerfile:464](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:464) | Rust CLI build stage inherits `runner-runtime-artifacts`，然后 `COPY bpfopt ./bpfopt`。该 stage 不需要 app/kernel/C++ artifact base。 | BuildKit 中 32 个 `COPY bpfopt` snapshots，多数 1.7G-2.45G；频繁 Rust 改动拖着大 parent snapshot。 |
| HIGH | [.dockerignore:62](/home/yunwei37/workspace/bpf-benchmark/.dockerignore:62), [runner/containers/runner-runtime.Dockerfile:464](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:464) | `.dockerignore` 忽略的是 `bpfopt-suite/target`，没有忽略实际路径 `bpfopt/target`。 | 当前 `bpfopt/target` 127M；历史 build cache 里 `COPY bpfopt` 达 2.45G，说明曾把本地 target/build output 带进 Docker context/stage。 |
| HIGH | [runner/containers/kernel-fork.Dockerfile:49](/home/yunwei37/workspace/bpf-benchmark/runner/containers/kernel-fork.Dockerfile:49), [runner/containers/kernel-fork.Dockerfile:50](/home/yunwei37/workspace/bpf-benchmark/runner/containers/kernel-fork.Dockerfile:50), [runner/containers/kernel-fork.Dockerfile:154](/home/yunwei37/workspace/bpf-benchmark/runner/containers/kernel-fork.Dockerfile:154) | `kernel-fork` final/tagged stage copies完整 `vendor/linux-framework`，再在后续 RUN 中删除。删除不回收前一层。 | `kernel-fork:x86_64-*` 4.17G；history 中 1.63G source layer + 2.06G artifact layer。 |
| MEDIUM | [runner/containers/runner-runtime.Dockerfile:17](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:17), [runner/containers/runner-runtime.Dockerfile:320](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:320), [runner/containers/runner-runtime.Dockerfile:491](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:491) | build deps 在 base layer 安装，后续 stage 再 purge。Purge 改变最终 filesystem，但不减少历史层/缓存体积。 | final runtime history 仍有 2.76G apt base layer；重复 build cache 中保留多个 apt variants。 |
| HIGH | [runner/containers/runner-runtime.Dockerfile:524](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:524), [runner/containers/runner-runtime.Dockerfile:525](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:525), [runner/containers/runner-runtime.Dockerfile:528](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:528), [runner/containers/runner-runtime.Dockerfile:529](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:529) | 高频 Python copy 在大体积 runtime data copy 之前：`corpus/*.py` 在 `corpus/bcf` 之前，`e2e/*.py` 在 `e2e/cases` 之前。 | Python/config 改动会让后续 693M `corpus/bcf`、72.8M `e2e/cases` copy layer 失效；BuildKit 已有 43 份 bcf/cases snapshots。 |
| MEDIUM | [runner/mk/build.mk:123](/home/yunwei37/workspace/bpf-benchmark/runner/mk/build.mk:123), [runner/mk/build.mk:125](/home/yunwei37/workspace/bpf-benchmark/runner/mk/build.mk:125), [runner/mk/build.mk:187](/home/yunwei37/workspace/bpf-benchmark/runner/mk/build.mk:187) | `RUNNER_RUNTIME_IMAGE_INPUT_FILES` 把 runtime Python/YAML/data 作为 image tar target prereq。`RUNNER_RUNTIME_IMAGE_SOURCE_FILES` 本身未包含 runtime Python，但最终 target 仍会因 Python 改动触发 docker build/save。 | 依赖 Docker cache 做细粒度复用；一旦 Dockerfile 顺序或 parent 变动，变成重复大层。 |
| LOW | [runner/mk/build.mk:200](/home/yunwei37/workspace/bpf-benchmark/runner/mk/build.mk:200), [runner/mk/build.mk:215](/home/yunwei37/workspace/bpf-benchmark/runner/mk/build.mk:215) | 每次 image target 重建都会 `docker save` 到 `.cache/container-images/*.image.tar`。 | 当前该目录不存在/无 tar，不是当前占用；但 tar 存在时会额外占 7G-9G/arch。 |

与 CLAUDE.md 对照：

- [CLAUDE.md:88](/home/yunwei37/workspace/bpf-benchmark/CLAUDE.md:88)-[CLAUDE.md:97](/home/yunwei37/workspace/bpf-benchmark/CLAUDE.md:97) 要求按变更频率分层，且 Python 改动不得触发 app/kernel/daemon 重编译。当前 Dockerfile 总体 stage 顺序接近该规则，但 final runtime 内部把大数据层放在 Python 层之后，Rust build stages 又继承大 artifact parent，导致实际 cache 行为不满足“只重 build 顶层”的目标。
- [CLAUDE.md:85](/home/yunwei37/workspace/bpf-benchmark/CLAUDE.md:85)-[CLAUDE.md:86](/home/yunwei37/workspace/bpf-benchmark/CLAUDE.md:86) 禁止 container bind mount host workspace。当前 runtime container command 只 bind result dirs、runtime tmp 和系统路径，未 bind 整个 workspace；见 [runner/libs/suite_commands.py:138](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_commands.py:138)-[runner/libs/suite_commands.py:153](/home/yunwei37/workspace/bpf-benchmark/runner/libs/suite_commands.py:153)。

## Artifact 累积模式

| 严重度 | 路径 | 当前占用 | 跨 run 模式 |
| --- | --- | ---: | --- |
| HIGH | `corpus/results/x86_kvm_p89_kinsn_corpus_*` | 15G | 13 轮 P89 结果目录保留；最大单目录 5.4G、2.7G、2.5G、2.4G、1.3G。 |
| HIGH | `corpus/results` | 18G | 173 个结果目录/文件，无自动 retention。 |
| HIGH | `e2e/results` | 15G | 200 个结果目录，无自动 retention；最大 `tetragon_20260430_001822_658984` 为 7.6G。 |
| MEDIUM | `docs/tmp/runtime-container-tmp` | 975M | 14 个 run token 目录残留；KVM executor 只在成功时清理 scratch dir，失败保留。 |
| MEDIUM | `docs/tmp/*/vm-tmp/*.img` | 519M actual / 128G apparent | KVM guest docker disk 默认 64G sparse file。正常 guest trap 会删；VM 崩溃、host kill 或满盘时会残留。 |
| LOW | `.cache/repo-artifacts` | 2.9G | x86_64 1.5G、arm64 1.4G，属于 app artifact cache，不是每轮 P89 增长主因。 |
| LOW | `.cache/runtime-kernel/*/bzImage` | 15M | 当前只有 x86 bzImage；可忽略。 |
| LOW | `.cache/aws-arm64`, `.cache/aws-x86` | 15M total | 小。用户提到的 `.cache/aws-cache` 当前不存在。 |
| LOW | `.state/runner-contracts` | 1.8M | 290 个 run contract 目录，体积小；`make clean` 才清。 |
| LOW | `.cache/container-images/*.image.tar` | 当前不存在 | build rules 用稳定文件名保存 runtime tar；当前不是根因，但存在时单 arch 会新增约 image-size 的 tar。 |

## 每次 KVM run 的临时占用

| 严重度 | 位置 | 行为 |
| --- | --- | --- |
| MEDIUM | [runner/libs/vm.py:31](/home/yunwei37/workspace/bpf-benchmark/runner/libs/vm.py:31)-[runner/libs/vm.py:42](/home/yunwei37/workspace/bpf-benchmark/runner/libs/vm.py:42) | guest script 把 `TMPDIR` 设置为 `docs/tmp/YYYYMMDD/vm-tmp`，该路径通过 virtme-ng `--rwdir` 映射到 host。 |
| MEDIUM | [runner/libs/kvm_executor.py:30](/home/yunwei37/workspace/bpf-benchmark/runner/libs/kvm_executor.py:30)-[runner/libs/kvm_executor.py:32](/home/yunwei37/workspace/bpf-benchmark/runner/libs/kvm_executor.py:32) | guest Docker disk 默认 `${TMPDIR}/bpf-benchmark-docker.img`，大小 64G。 |
| MEDIUM | [runner/libs/kvm_executor.py:47](/home/yunwei37/workspace/bpf-benchmark/runner/libs/kvm_executor.py:47)-[runner/libs/kvm_executor.py:50](/home/yunwei37/workspace/bpf-benchmark/runner/libs/kvm_executor.py:50) | trap 只在 guest shell 正常退出路径上删除 docker disk；异常中断会留下 sparse image。 |
| LOW | [runner/libs/vm.py:151](/home/yunwei37/workspace/bpf-benchmark/runner/libs/vm.py:151)-[runner/libs/vm.py:165](/home/yunwei37/workspace/bpf-benchmark/runner/libs/vm.py:165) | host 侧 `script` pty log 用 `/tmp/vng-pty-log.*`，finally 删除；满盘时创建/写入该文件会失败。当前 `/tmp/vng-pty-log.*` 和 `/tmp/virtme_ret*` 均不存在。 |

当前 `/tmp` top consumers 是普通日志/临时 build，最大 `/tmp/p86-unittest-build` 59M、`/tmp/codex_p89.log` 47M，不是当前主因。

## 重复路径 / 冗余 cache

| 严重度 | 项 | 当前占用 | 结论 |
| --- | --- | ---: | --- |
| BLOCKER | Docker BuildKit / overlay2 | 183.4G build cache, overlay2 197G | 主因；大量重复 runtime build snapshots。 |
| MEDIUM | Global Go build cache | 27G | 不一定来自本仓库；可回收但会影响其他 Go 项目 rebuild。 |
| MEDIUM | Rustup toolchains | 3.2G | 全局 toolchain，不是 P89 主因。 |
| LOW | Cargo home | 450M | 小。 |
| LOW | `bpfopt/target` | 127M | 当前小，但未被 `.dockerignore` 排除，是 Docker cache 历史膨胀风险。 |
| LOW | Docker volumes | 97.77M | 与 P89 无关；最大两个 postgres volume 48M/47M。 |

## 建议清理项

| 标记 | 严重度 | 项 | 可回收 | 备注 |
| --- | --- | --- | ---: | --- |
| SAFE | BLOCKER | `docker builder prune` / `docker buildx prune` | 183G+ | 不删除源码/结果，只丢 build cache；代价是下次 build 变慢。先确认没有 build 在跑。 |
| SAFE | HIGH | stale `docs/tmp/*/vm-tmp/bpf-benchmark-docker.img` | 当前 519M actual，未来可能几十 G | 生成性 KVM docker disk；确认无 KVM run active 后可删。 |
| SAFE | MEDIUM | `docs/tmp/runtime-container-tmp/run.*` | 975M | 临时 runtime dir；失败 forensics 不需要时可删。 |
| SAFE | LOW | `/tmp/codex_p*.log`, `/tmp/p86-unittest-build`, `/tmp/p88-*` | 约数百 M | 非结果主路径。 |
| RISKY | HIGH | `corpus/results/x86_kvm_p89_kinsn_corpus_*` 旧轮次 | 15G | 结果数据；先保留最好/最新/需要对比的轮次，归档后删。 |
| RISKY | HIGH | `e2e/results/*` 旧轮次 | 15G | 结果数据；需要先确认哪些是 paper/debug 证据。 |
| RISKY | MEDIUM | `~/.cache/go-build`, `~/.cache/huggingface` | 59G | 全局缓存，可能影响其他项目；不是本仓库 P89 主因。 |
| RISKY | MEDIUM | Docker images (`bpf-benchmark/*`, upstream app images) | 34.6G | Docker 认为全部 reclaimable；删除后必须重 pull/rebuild。 |
| RISKY | LOW | `.cache/repo-artifacts` | 2.9G | app artifact cache；删后 Katran/其他 artifacts 需重建。 |

## 建议 Dockerfile 修改

1. [HIGH] 在 `.dockerignore` 增加 `bpfopt/target` 和 `bpfopt/target/**`，并把 [runner/containers/runner-runtime.Dockerfile:464](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:464) 改成只复制 Cargo manifests 和 crate sources，避免把 host build output 带进 BuildKit snapshots。
2. [HIGH] 让 Rust artifact stages 从 `runner-runtime-build-base` 或更小的 Rust build base 起步，不要从 [runner-runtime-artifacts](/home/yunwei37/workspace/bpf-benchmark/runner/containers/runner-runtime.Dockerfile:459) 继承 app/kernel/C++ artifact parent。最终 runtime 再 `COPY --from` 小的 `/artifacts/rust/usr-local-bin`。
3. [HIGH] 在 final runtime 中把大而相对稳定的数据层放到高频 Python 层之前，或使用 `COPY --link`：`corpus/bcf`、`e2e/cases` 不应跟在 `corpus/*.py`、`e2e/*.py` 后面。
4. [HIGH] 把 `kernel-fork` 拆成 builder stage 和 artifact-only final stage。不要 tag 一个含完整 `vendor/linux-framework` source layer 的 final artifact image。
5. [MEDIUM] 将 build deps 和 runtime deps 分开：避免依赖后续 `apt-get purge` 来“瘦身”，因为 purge 不会回收旧层。
6. [MEDIUM] 对大 `COPY --from` artifact（kernel modules/header、app artifacts、corpus/e2e data）评估 `COPY --link`，降低 parent layer 变化导致的大层重复。
7. [MEDIUM] 给 Docker build cache 增加明确 GC 策略；例如文档化 `docker buildx prune --keep-storage <N>` 或单独 make target，而不是让 14 轮 smoke 无限累积。

## 建议 Makefile / Runner 修改

1. [HIGH] 给 `vm-corpus` / `vm-e2e` 增加结果 retention 机制，例如保留最近 N 轮或通过 `KEEP_RESULTS=N` 控制；默认可以只在成功后清理旧的同 target/suite 目录。
2. [HIGH] 给 P89 smoke 增加专用输出目录或 run token prefix，并在 smoke 完成后自动删除失败中间目录，只保留 summary 和选定详情。
3. [MEDIUM] 在 KVM executor host side 的 `finally` 路径清理本 run 生成的 `docs/tmp/YYYYMMDD/vm-tmp/bpf-benchmark-docker.img`，补上 guest trap 失效时的兜底。该修改属于 runner bugfix，不改变 v3 daemon/socket 边界。
4. [MEDIUM] 给 `docs/tmp/runtime-container-tmp/<run-token>` 做失败/成功一致的生命周期管理；需要失败取证时用 env 开关保留。
5. [MEDIUM] 增加显式 `make prune-docker-build-cache` 或 `make vm-prune`，只做 Docker builder cache 和本项目临时 VM 文件清理，避免开发者手动误删结果。
6. [LOW] `make clean` 当前会删 `.state/runner-contracts` 和部分 `.cache`，但不会处理 `corpus/results`、`e2e/results`、`docs/tmp/*/vm-tmp/*.img`、Docker build cache；建议分成 `clean-build`、`clean-results`、`clean-vm-tmp`、`clean-docker-cache`，避免一个 target 既危险又不完整。

## v3 约束检查

[docs/tmp/bpfopt_design_v3.md](/home/yunwei37/workspace/bpf-benchmark/docs/tmp/bpfopt_design_v3.md:648) 仍要求 runner Python 在 daemon socket 边界保持稳定，CLAUDE.md 也强调 runner Python 仅做 bugfix/ stale test data 更新。上述 Makefile/runner 建议都应限定为磁盘生命周期 bugfix，不应重构 corpus/e2e/micro runner 架构，也不应把 v3 pipeline 逻辑放回 daemon。
