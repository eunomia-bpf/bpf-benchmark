# 反面例子（拆掉的特殊处理，避免再次出现）

运营者 2026-11-19：“禁止做这样的额外的改动, 以后记住. 也检查还有没有类似的东西, 都要清理掉. 代码要显著减少, 你来做. 不要做这种额外的事情”；“尽可能不要做特殊处理, 尤其是导致性能糟糕的特殊处理. 这些反面例子拆掉之后也都得记下来, 避免再次出现. 之前有一些 anti pattern 也要记住.”；“helper 能用宏或者 function inline 都可以. 但是不要在链接器里面手写太多, 链接器要简单”；“应该尽可能减少链接对吧”。

## 原则

- 运行的代码就是 P：同一份源码按所有应用统一的一组参数 `-O3` 编译。
- helper 写在头文件里，用宏或 inline 函数，所有应用一套写法。
- 链接器只做绑定：map 地址、kernel 符号、重定位，加上读内存出错时的 load site 恢复。
- 验证和运行分开看（运营者 11-19：“吧 verify 和运行分开看”；11-16：“verify 不了的也需要跑 native 先”）。
- 删除任何东西之前，先查运营者原话（kprog/docs/user-instruction.md）。

## 已拆掉的

| 反面例子 | 为什么拆 | 换成什么 | 提交 |
|---|---|---|---|
| 链接器里手写的 x86 helper 例程（ARRAY、LPM、probe_read 内联） | 运营者：“干嘛还需要手写?”；链接器变复杂 | helper 用 C 写在头文件和 LTO 的 C helper 里 | 07d9c4c96 |
| 按二进制大小逐字节压缩（约 30 个链接器提交） | 运营者：“不需要按照 binray size 扣了” | 代码量由编译参数和设计决定，按实际大小报告 | 07d9c4c96 |
| manifest 里按应用的特殊键（source_map_prefix、prog_type、--dedupe-program、--source-object-root、--helper-disambiguate、--source-bpf-object） | 运营者：“不是说禁止写任何按照应用的特殊的吗?” | 一条规则：每个原生对象配旁边编出的 BPF 对象，按源程序吻合度选条目 | 9caea4ed6 |
| 拿调用次数做对比和门槛 | 运营者：“调用次数很可能不同啊” | 只看功能正常和数据完整 | 11-18 todo |
| sim 私有任取值输入在原生一侧留成 volatile 内存读 | 每次调用多读几十到几百次内存，代码大 10 倍 | 原生一侧用 freeze；具体值（NUMERIC）原样取回 | 2eb36bad9、0dfa23814 |
| x86 解析器丢掉 lock 前缀 | 原子计数变成普通读-加-写 | B 和原生两侧都保持原子语义 | 3f80b472e |
| 解析器静默跳过认不出的行、objdump 省掉全零字节段 | B 少了 P 的指令 | 认不出的行让这次生成失败；objdump -z | 10c42d6cf、185091051 |
| 三套 helper 声明（extern 符号、按 helper 编号的宏、Tetragon 的 `call *%rax` 内联汇编） | 链接器要追踪 helper 编号，代码多 | core-compat.h 里一套 extern 加同名宏 | 本次 |
| probe_read 走函数调用（helper，或 C 实现里调 copy_from_kernel_nofault） | Tracee、Tetragon 每次调用 41–46% 的时间 | 内核地址直接 load，出错由 load site 恢复（同 JIT 的 PROBE_MEM）；用户地址照旧调 helper | 本次 |
| 同一配置反复重跑计时 | 运营者：“不要随便重跑” | 代码变了才测；六应用直接原生沿用 lean 第 1 次 | 9fbc4e584 |
| 单样本计时 | 数据不完整 | 每个应用 3 x 180 s，广度优先（运营者 11-11） | 11-19 todo |
| 没查原话就删（c3960d089 删了 direct-native 回落） | 违背运营者 11-16 的原话 | 已恢复，删除前先查原话 | 0a993eb37 |

## 还在清理的（协调者自己做）

- Cilium 源码里的原生 helper 分支（`__native_bpf_helper`，53 个，按编号绑定）：并入 core-compat.h 的同一套写法，Cilium 源码回到上游形态。
- 链接器里追踪 helper 编号的代码（x86_helper_provenance.rs、finite helper call）：所有应用改成符号调用之后删掉。
- native-link 把入口函数的 RET 改写成跳到代码末尾：查清用途后删掉，入口直接 ret。
- sim 原生一侧的地址屏障（compile_sim_ir.cpp memoryAsm 的 stable()）、读内核指针前的地址范围检查、私有栈带来的多余 mov：原生一侧按 P 的正常代码生成。

## 统一 helper 时踩到的坑（2026-11-19 六应用检查发现，已修，3e99eaa1e）

- 应用自己把 helper 声明成同名指针变量（OTel 的 bpfdefs.h）：汇编名相同的 extern 和这个变量被编译器合成一个符号，调用落到数据上（OTel 14 个程序链接失败）。这类声明在原生编译里用 `#ifndef __KPROG_NATIVE_HELPERS` 留在外面。
- 应用把 helper 名字当数值用（Tetragon 的错误统计记录 `(u32)(long)probe_read`，BPF 里是 helper 编号）：把它的声明改成函数会改变语义，链接器也读不了 32 位 GOT 值（Tetragon 81 个失败）。Tetragon 保留自己的指针声明，调用用同名宏转到公共 helper。
- 内联读取的源地址被常量折叠（空指针加偏移）会成为绝对内存操作数，链接器拒绝（Tracee 2 个失败）。读取开头用空 asm 让源地址留在寄存器里。
- 每次改 helper 写法之后，在提交前扫描所有应用的对象：32 位 GOT 读取、绝对操作数（Intel 语法的 `ds:0x`）、间接调用、和 helper 同名的本地数据符号，四项都要为 0。
- 内联读取丢掉了 helper 自己的地址规则（copy_from_kernel_nofault 不读内核半区以下的地址，空指针或用户指针直接清零、返回 -ERANGE，不缺页）：Tracee 里空指针很常见（写管道、socket 时 vfs_write 的 pos 是 NULL），每次都真的缺页、靠 load site 恢复。Tracee 原生每次调用从 425 ns 变成 9273 ns，吞吐 0.047x（17:33 之后的三次运行）；12:46 那次还是按编号调 helper，原生和 eBPF 持平。内联读保留 helper 自己的这条规则：源地址不在内核半区就清零目标、返回 -ERANGE，每次读多两条指令（test、jns）。换 helper 写法之后，除了上面四项扫描，还要看每个应用的每次调用耗时，不能只看有没有失败。
