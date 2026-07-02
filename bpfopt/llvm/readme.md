# bpfopt LLVM Roundtrip Status

`bpfopt/llvm` 是 runner 使用的 C++ `bpfopt` binary。它保持 bytecode CLI
契约：输入和输出都是 raw `struct bpf_insn[]`，loader 通过
`--bpfopt bpfopt/llvm/build/bpfopt` 选择这个实现，不需要改二进制协议。

所有 pass 都必须严格走 LLVM O3 roundtrip：

1. llvmbpf lift kernel BPF bytecode 到 LLVM IR；
2. 跑 LLVM O3 pipeline；
3. 通过 LLVM BPF backend 生成 ELF object；
4. 抽取并修复 `.text` relocation；
5. 输出新的 raw BPF bytecode。

这里没有 raw bytecode fallback。`noop` 也不是 byte-preserving，它只是一个走完整
O3 回环的 pass label。verifier 失败就是 roundtrip 失败，不能悄悄输出原始 bytecode。

当前状态：

- 每个 `--pass <name>` invocation 都走一次 lift -> O3 -> lower。`map_inline`
  在 O3 前做 pass-specific IR rewrite；`branch_flip` 校验真实 per-site profile
  并在 O3 前写入 LLVM branch-weight metadata；其它 pass label 是 plain O3
  roundtrip。
- post-lowering 不是 verifier repair 层。LLVM BPF backend 生成 object 后，
  这里只做 ELF relocation 和 raw instruction stream 恢复；不能插入 bounds check、
  删除指令、改写 memory-address form 或构造新的 verifier proof。
- `map_inline` 读取 `--map-values`、`--map-ids` 和
  `--inline-hint=<map>:<key_hex>`。hint 只有一种：提示某个 map entry 的 key，
  让优化器使用 snapshot 中对应的 value；不再区分 hard/soft。
- llvmbpf 的必要修改已经 push 到
  `origin/codex/bpfopt-llvm-roundtrip-20260515`。

详细契约、改动说明和验证命令见 [README.md](README.md)。
