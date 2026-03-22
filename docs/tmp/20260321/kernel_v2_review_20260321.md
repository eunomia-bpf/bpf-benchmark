# BpfReJIT v2 内核改动 Review

- Review 范围: `vendor/linux-framework` 仓库 `rejit-v2` 分支相对 `master` 的 `git diff master..HEAD`
- 方法: 静态 review diff，并回看关键上下文代码路径
- 说明: 未实际编译/运行内核或 selftests；以下结论基于代码审阅

## arch/x86/net/bpf_jit_comp.c

- 行 591-595, 2468-2470 | Minor | `emit_inline_kfunc_call()` 在发现 emitter 返回长度不匹配或超过 `max_emit_bytes` 时返回 `-EFAULT`，但调用方把任何非零返回都当成“回退成普通 CALL”。这会把真正的 emitter bug 静默吞掉，最终生成的代码和作者预期不一致。建议修复: 仅对 `-ENOENT` / `-EOPNOTSUPP` 之类的“不可 inline”场景回退到普通 CALL；对 `-EFAULT` 这类 emitter 合约违例直接失败。

## include/linux/bpf.h

- 行 968-973, 3046-3055 | Style | 通用 BPF 头文件直接暴露 `emit_x86` 和 `bpf_register_kfunc_inline_ops()`，把 x86 专有实现细节塞进了 generic core API。这个抽象层次很容易被上游 challenge。建议修复: 要么把接口做成架构无关的 ops，再由各架构实现；要么把该接口限制在 `CONFIG_X86` 范围内，避免 generic header 带着 x86 命名。

## include/linux/btf.h

- 行 82 | Style | `KF_INLINE_EMIT` 是通用 kfunc flag，但实际语义是“允许某个架构 JIT 做 inline codegen”。这会把架构策略固化进通用 BTF flag 空间，上游大概率会追问多架构语义和 capability 暴露方式。建议修复: 在设计上把“可 inline”与“某架构如何 inline”分离，至少先说明多架构语义再冻结 flag。

## include/uapi/linux/bpf.h

- 行 996, 1926-1935 | Major | `BPF_PROG_REJIT` 作为新 UAPI 现在就被冻结，但语义还没有稳定下来。现有 attr 无法完整表达一次等价的 `BPF_PROG_LOAD` 语境，例如缺少 `prog_flags` 等 verifier 相关上下文，导致内核实现已经无法 faithfully replay 原始 load 语义。UAPI 一旦合入就很难再改。建议修复: 在核心设计和语义稳定之前不要引入新命令；如果坚持保留，至少把需要重放 verifier/JIT 语义的字段补齐。

## kernel/bpf/core.c

- 行 141, 291-295 | Minor | 新增了 `aux->rejit_mutex` 的 `mutex_init()`，但 `__bpf_prog_free()` 没有对应 `mutex_destroy()`。这在 lockdep/debug 构建下会让生命周期不完整。建议修复: 在 `__bpf_prog_free()` 中补上 `mutex_destroy(&fp->aux->rejit_mutex)`。

## kernel/bpf/syscall.c

- 行 3252-3254, 3286-3287, 3337-3338 | Critical | `BPF_PROG_REJIT` 构造了一个内核栈上的 `load_attr`，然后把 `KERNEL_BPFPTR(&load_attr)` 传给 `bpf_check()`。但 `load_attr.fd_array` 里装的仍然是用户态地址；`process_fd_array()` 会依据 `uattr.is_kernel` 把它当成内核指针处理，最终走 `copy_from_kernel_nofault()`。结果是正常用户 `fd_array` 会失效，而且特权调用者还能把任意数值伪装成“内核地址”喂给 verifier。建议修复: 不要用假的 kernel `uattr` 重走 verifier；要么扩展 verifier API 显式传 `fd_array` 的 `bpfptr_t`，要么把 REJIT attr 直接按用户指针语义单独处理。

- 行 3159-3174, 3354-3360 | Critical | `bpf_prog_rejit_supported()` 只排除了 `dst_prog` / `dst_trampoline` / `poke_tab` 等少数场景，但没有排除已经挂到 XDP dispatcher 等缓存了 `prog->bpf_func` 地址的 attachment。REJIT 只改 `prog->bpf_func`，却没有走 `bpf_prog_change_xdp()` 这类更新路径，旧 dispatcher image 会继续跳到旧 JIT 地址；`tmp` 销毁后就是稳定 UAF。建议修复: 至少禁止对任何可能被 dispatcher/trampoline/static-call 缓存的程序做 REJIT；更合理的是把“可执行 image”独立成可引用对象，并显式更新所有 attachment backend。

- 行 3354-3360 | Critical | 成功路径在 swap 后只做了 `synchronize_rcu()` / `synchronize_rcu_tasks_trace()`，然后立即释放旧 image。但并不是所有执行路径都在对应的 RCU 读侧临界区里，例如直接持有 `struct bpf_prog *` 并调用 `bpf_prog_run()` / `ops->test_run()` 的路径。这样 REJIT 可以在旧代码仍在 CPU 上执行时把它释放掉。建议修复: 不要原地 hot-swap 并立即 free 旧 image；应把 JIT image 做成单独 refcounted 对象，或者把 REJIT 严格限制为“完全未附着、无人直接执行”的程序。

- 行 3277-3287 | Major | REJIT 只把 `BPF_F_SLEEPABLE` 和 `BPF_F_XDP_HAS_FRAGS` replay 到新的 `load_attr.prog_flags`，其它会影响 verifier/JIT 行为的 flags 都丢了，例如 `BPF_F_STRICT_ALIGNMENT` / `BPF_F_ANY_ALIGNMENT`。这意味着 REJIT 出来的程序并不一定是在与原始 load 相同的约束下验证出来的。建议修复: 把原始 `prog_flags` 保存到 `bpf_prog_aux` 并完整重放，或者把这些字段补进 `rejit` UAPI。

- 行 3177-3235, 5302-5330 | Major | swap 逻辑明显漏字段，最直观的是 `prog->len` 和 `prog->insnsi` 根本没有更新。不同长度的 REJIT 之后，运行时 image 已经变了，但 `BPF_OBJ_GET_INFO_BY_FD` 里的 `xlated_prog_len` / `xlated_prog_insns` 仍然返回旧程序；对象的 metadata 与真实执行内容已经不一致。建议修复: 不要试图维护一份手写的 swap 白名单；改成发布一个新的 immutable prog/image snapshot，或者至少把 xlated insns 与所有相关字段成组替换。

- 行 3177-3200, 5260-5275, 5323-5330 | Major | writer 只拿 `rejit_mutex` 就原地替换 `used_maps`、`orig_insns`、`linfo`、`jited_linfo` 等字段，但 reader 要么根本没同步，要么用的是别的锁（例如 `used_maps_mutex`）。`bpf_prog_get_info_by_fd()` 在并发 REJIT 时可能读到 torn state，甚至拷贝已经释放的 metadata。建议修复: 把这些可变字段收敛到一个 RCU 发布的只读快照里，或者严格使用 reader/writer 共享的同一把锁。

- 行 3235 | Minor | `prog->aux->load_time` 在 REJIT 后被重写，这会把原本表示“对象创建时间”的语义改成“最近一次 REJIT 时间”。这对现有 `bpf_prog_info.load_time` 语义是回归。建议修复: 保持 `load_time` 不变；如果确实需要，新增单独的 `last_rejit_time`。

## kernel/bpf/verifier.c

- 行 3212-3267, 3615-3616 | Major | inline kfunc registry 只用 `func_name` 作为 key，完全忽略模块 / BTF namespace / prog type。kfunc 解析本来是 `(btf, func_id, offset)` 级别的，这里退化成字符串后，同名 kfunc 在不同 BTF 里会冲突，最坏情况下会绑到错误的 inline emitter。建议修复: 用解析后的 `(btf, func_id)` 或直接把 inline emitter 挂到 `bpf_kfunc_desc` 可唯一定位的对象上，不要再做全局字符串注册表。

## tools/include/uapi/linux/bpf.h

- 行 6671-6711 | Major | 这里的 `struct bpf_prog_info` 没有同步内核 UAPI 新增的 `orig_prog_len` / `orig_prog_insns` 字段，tools 头文件已经与内核头失配。任何基于 in-tree tools 头编译的用户态代码都无法正确使用新 ABI。建议修复: 直接同步整份 `include/uapi/linux/bpf.h` 到 tools 副本，不要只挑选部分 diff。

## tools/testing/selftests/bpf/Makefile

- 行 80-83, 128-139 | Minor | 这个 Makefile 没有把新加的 `get_original_poc.c` / `rejit_poc.c` 接入任何 `TEST_GEN_PROGS*`，因此这两个文件现在是 dead code，不会编译、更不会进 CI。建议修复: 要么把它们改造成标准 selftest 并接入构建，要么把它们移出 selftests 目录。

## tools/testing/selftests/bpf/get_original_poc.c

- 行 1-103 | Minor | 这是一个独立 PoC，而不是 selftests 风格的回归测试。当前既不纳入构建也不纳入运行，实际没有持续验证价值。建议修复: 改写成 `prog_tests`/`test_progs` 用例，使用 `ASSERT_*` 风格，并接入 Makefile。

## tools/testing/selftests/bpf/prog_tests/inline_kfunc.c

- 行 87-91 | Minor | 当前只是在 JIT image 里 grep 一段裸字节序列，这个 oracle 很弱，可能误命中，也不能证明普通 CALL 确实被去掉。建议修复: 更精确地验证对应 call site 的 opcode/长度，或者在可行时做反汇编比对。

- 行 71-96 | Minor | 测试覆盖面不够，只覆盖了 happy path 加载和执行，没有覆盖 provider unregister / module reload / REJIT 场景，因此这轮改动里最危险的生命周期问题都测不到。建议修复: 至少补一个“含 inline kfunc 的程序做 REJIT”的回归测试；如果核心设计保留注册/注销接口，还应覆盖注销后的行为。

## tools/testing/selftests/bpf/progs/test_inline_kfunc.c

- 未发现新增阻塞问题。

## tools/testing/selftests/bpf/rejit_poc.c

- 行 133-205 | Major | 这个 PoC 只验证了“不同长度 REJIT 后返回值变化”，却没有检查 `BPF_OBJ_GET_INFO_BY_FD` 里的 `xlated_prog_len` / `xlated_prog_insns` / `orig_prog_len` 是否同步更新，因此完全抓不到当前 swap 漏字段的核心 bug。建议修复: 在 same-length 和 different-length 两个 case 里都检查 info API，确认 xlated/raw/JIT metadata 一致。

- 行 1-221 | Minor | 与 `get_original_poc.c` 同样，这个文件没有接入 selftests 构建和运行，当前只是仓库内的 standalone sample。建议修复: 改造成标准 selftest，或者移到文档/样例目录。

## tools/testing/selftests/bpf/test_kmods/Makefile

- 未发现新增阻塞问题。

## tools/testing/selftests/bpf/test_kmods/bpf_test_inline_kfunc.c

- 未发现该 selftest module 自身的新增阻塞问题；核心风险在 verifier/core 侧的 registry 和生命周期设计，不在这个模块的实现细节里。

## 总结

- 总体结论: 当前版本不建议合入，`kernel/bpf/syscall.c` 里至少有 3 个 blocker 级别问题: 旧 image 生命周期不安全、attachment/dispatcher 不会被同步更新、以及伪造 `KERNEL_BPFPTR` 导致 verifier 把用户 `fd_array` 当成内核指针。
- REJIT swap 方案本身也不稳: 现在是手工维护一个“要 swap 的字段列表”，已经出现了 `prog->len/insnsi` 这类明显遗漏。继续沿这个方向补字段，后续大概率还会漏。
- inline kfunc 方向里，selftest 想法本身可以保留，但 generic API 现在过于 x86-specific，registry 也只按字符串建模，设计上很难直接被上游接受。

## 上游可接受性判断

- 相对容易被上游接受的部分:
- `orig_prog_insns` / `orig_prog_len` 这种“导出原始用户指令”的想法本身是合理的，但需要先把 tools 头同步好，并把语义说清楚到底是“首次 load 的原始指令”还是“当前版本的原始指令”。
- `__bpf_ksym_del()` 里把 `lnode` 重新初始化，用于支持后续重新加入 kallsyms，这个小修补本身问题不大。
- inline kfunc 的 selftest scaffolding 可以保留，但前提是 core 设计先收敛。

- 很容易被 push back 的部分:
- 新增 `BPF_PROG_REJIT` UAPI，但核心语义、并发模型和 attachment 安全性都还没定型。
- 原地修改 `struct bpf_prog`，破坏“BPF program load 后基本 immutable”的现有假设。
- 在 generic BPF/core/verifier 代码里引入 `emit_x86` 这种架构专有接口。
- 用全局字符串注册表来描述 inline kfunc emitter，而不是绑定到唯一的 kfunc 标识。

## 建议的后续改动

1. 先停掉当前“原地 swap `struct bpf_prog`”的方案，把可执行 image 和可读 metadata 抽成独立、可 refcount/RCU 发布的对象。
2. 修掉 REJIT verifier 路径里伪造 `KERNEL_BPFPTR` 的问题，确保 `fd_array` 等仍按用户指针处理。
3. 明确 REJIT 的 load replay 语义: 哪些 `prog_flags`、attach 上下文、token/LSM 语义必须保留，并把缺失字段补进内部状态或 UAPI。
4. 在 attachment 侧建立明确策略: 要么只允许对完全 detached 的 prog REJIT，要么逐类 backend 显式支持 image replacement。
5. 同步 `tools/include/uapi/linux/bpf.h`，并补上真正能卡住本轮 bug 的 selftests，尤其是:
6. attached XDP 程序 REJIT
7. different-length REJIT 后的 `BPF_OBJ_GET_INFO_BY_FD`
8. REJIT 与 `BPF_OBJ_GET_INFO_BY_FD` / test_run 并发
