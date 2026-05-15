# bpfopt LLVM Roundtrip Status

`bpfopt/llvm` 是和 Rust `bpfopt` 平级的 C++ drop-in binary。它保持同一个
bytecode CLI 契约：输入和输出都是 raw `struct bpf_insn[]`，loader 通过
`--bpfopt bpfopt/llvm/build/bpfopt` 选择这个实现，不需要改 daemon/loader 的
二进制协议。

`noop` 必须严格走 LLVM roundtrip：

1. llvmbpf lift kernel BPF bytecode 到 LLVM IR；
2. 跑 O0-oriented LLVM pipeline；
3. 通过 LLVM BPF backend 生成 ELF object；
4. 抽取并修复 `.text` relocation；
5. 输出新的 raw BPF bytecode。

这里没有 raw bytecode fallback。verifier 失败就是 roundtrip 失败，不能悄悄输出
原始 bytecode。

当前状态：

- O0 `noop` 已通过 `bpfopt/testobject` 下 37 个 object，合计 378 个 BPF
  program，命令是 `bpfopt-loader --pass noop --bpfopt bpfopt/llvm/build/bpfopt`。
- O3 还不能全量替代 O0。用现有 `dce` loader config 触发 O3 时，bcc、
  bpftrace、`cilium_bpf_host`、`cilium_bpf_lxc` 能过，但
  `cilium_bpf_overlay.bpf.o` 失败；首个问题是 O3 删除了 verifier 仍需要的
  map-value offset bounds check。
- `map_inline` 已实现最小 hard-hint 路径：先读取 `--map-values`、`--map-ids`、
  `--inline-hint=<map>:!<key_hex>` 的 snapshot，把
  `bpf_map_lookup_elem()` 改写为指向栈上 snapshot value 的非 NULL 指针，然后再
  lift 到 LLVM IR 跑 O3/DCE 并由 LLVM BPF backend 降回 BPF。soft hint 目前
  fail-fast，不做启发式 fallback。Katran `balancer_ingress` 通过
  `docs/tmp/bpfopt_llvm_mapinline_katran_wrapper.sh` 注入同 runner 配置一致的
  hard hints/overlays 后，loader verifier 和 `BPF_PROG_TEST_RUN` 均通过，report
  显示 16 个 lookup site 被 inline，最终指令数 `2542 -> 2500`。
- llvmbpf 的必要修改已经 push 到
  `origin/codex/bpfopt-llvm-roundtrip-20260515`。

详细契约、改动说明和验证命令见 [README.md](README.md)。
