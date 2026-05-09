# Use libbpf Directly 2026-05-09

## 调研

- `libbpf-sys 1.7.0+v1.7.0` 导出 `libbpf_sys::bpf_insn`、`dst_reg()` / `src_reg()` bitfield accessor、`set_dst_reg()` / `set_src_reg()` mutator，以及 `BPF_*` opcode/class/source/register/pseudo/helper/prog/map 常量，例如 `BPF_ALU64`, `BPF_MOV`, `BPF_CALL`, `BPF_EXIT`, `BPF_PSEUDO_KFUNC_CALL`, `BPF_FUNC_map_lookup_elem`。
- `libbpf-sys` 没有导出 `BPF_MOV64_REG`, `BPF_EMIT_CALL`, `BPF_EXIT_INSN`, `BPF_ALU64_IMM`, `BPF_ST_MEM`, `BPF_LDX_MEM` 这类函数式 C macro。它们存在于 vendored libbpf C headers (`libbpf/include/linux/filter.h`)，但 bindgen 没有把这些 compound-literal/function-like macros 变成 Rust API。
- `libbpf-rs 0.26.x` 没有 instruction builder、`Insn` 类型或 kfunc call builder。它的相关能力是从 loaded/open object 上返回 `&[libbpf_sys::bpf_insn]`。
- 替换策略：能直接使用的 UAPI 类型和常量全部继续来自 `libbpf-sys`；由于没有等价 Rust instruction builder，只保留 `BpfInsn::new(code, regs, off, imm)` / raw-byte ABI 入口和字段分类 helper。语义构造器不再放在 `BpfInsn` 上。

