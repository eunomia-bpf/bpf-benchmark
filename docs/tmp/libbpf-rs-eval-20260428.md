# libbpf-rs evaluation for bpfopt-suite

Date: 2026-04-28

Scope: evaluate whether `libbpf-rs` can provide the bytecode-level base types for the bpfopt-suite v3 shared library, or whether this project should keep a lightweight in-repo BPF instruction crate.

Project constraints read before evaluation:

- `docs/tmp/bpfopt_design_v3.md`: `bpfopt` is a zero-kernel-dependency raw bytecode CLI; stdin/stdout are raw `struct bpf_insn[]`; kernel-facing operations belong in `kernel-sys` and the `bpfget`/`bpfverify`/`bpfprof`/`bpfrejit` CLIs.
- `docs/kernel-jit-optimization-plan.md`: §4.6 keeps the same CLI-first split; `kernel-sys` is the raw syscall layer.
- `CLAUDE.md`: v3 design is authoritative; stdin/stdout carry raw `struct bpf_insn[]`; the daemon must not own pass pipeline or bytecode transforms.

Version checked:

- `cargo search libbpf-rs --limit 5`: latest `libbpf-rs = "0.26.2"`.
- `cargo add libbpf-rs --dry-run`: would add `libbpf-rs v0.26.2`; feature list includes `static`, `vendored`, `libbpf-sys`.
- docs.rs crate page: `libbpf-rs 0.26.2`, published 2026-04-08, depends on `libbpf-sys ^1.7.0`.
  Source: <https://docs.rs/crate/libbpf-rs/latest>
- docs.rs crate page: `libbpf-sys 1.7.0+v1.7.0`, published 2026-03-16.
  Source: <https://docs.rs/crate/libbpf-sys/latest>
- Local compile check in `/tmp/test-libbpf-rs-eval`: `cargo check` passed after importing `libbpf_rs::libbpf_sys::{bpf_insn, BPF_ALU64, BPF_MOV, BPF_K, BPF_REG_0, BPF_PROG_TYPE_XDP, bpf_prog_load}` and `libbpf_rs::ProgramType`.

## Question 1: Does libbpf-rs expose `struct bpf_insn`?

Answer: `libbpf-rs` does not define an idiomatic safe Rust instruction type such as `libbpf_rs::BpfInsn`. It re-exports the FFI crate as `libbpf_rs::libbpf_sys`, and the actual instruction type is:

- `libbpf_rs::libbpf_sys::bpf_insn`
- or directly `libbpf_sys::bpf_insn`

`libbpf_sys::bpf_insn` is a bindgen-generated C layout type:

```rust
#[repr(C)]
pub struct bpf_insn {
    pub code: __u8,
    pub _bitfield_align_1: [u8; 0],
    pub _bitfield_1: __BindgenBitfieldUnit<[u8; 1usize]>,
    pub off: __s16,
    pub imm: __s32,
}
```

It derives `Debug`, `Default`, `Copy`, `Clone`; it has public `code`, `off`, `imm` fields and generated `dst_reg()`, `set_dst_reg()`, `src_reg()`, `set_src_reg()` methods. Source: <https://docs.rs/libbpf-sys/1.7.0%2Bv1.7.0/libbpf_sys/struct.bpf_insn.html>

The high-level `libbpf-rs` wrapper exposes object-program instructions as read-only slices:

- `OpenProgram::insns(&self) -> &[libbpf_sys::bpf_insn]`
- `Program::insns(&self) -> &[libbpf_sys::bpf_insn]`

It also documents that libbpf can modify, append, or delete instructions while processing an object file for load, so this is object-loader state, not a stable raw bytecode parser. Source: <https://docs.rs/libbpf-rs/latest/src/libbpf_rs/program.rs.html>

For live program query, `libbpf_rs::query::ProgramInfo` stores translated instructions as `Vec<u8>`, not parsed `bpf_insn` records. Source: <https://docs.rs/libbpf-rs/latest/src/libbpf_rs/query.rs.html>

Conclusion: usable only as a C FFI layout type. It does not provide the safe owned instruction abstraction or raw bytes to instruction parser that `bpfopt-core` needs. For stdin/stdout raw `struct bpf_insn[]`, users still need to implement parsing/serialization or use unsafe casting/transmute.

## Question 2: BPF opcode and register constants

Answer: constants are available from `libbpf-sys`, not directly as top-level `libbpf-rs` re-exports. `libbpf-rs` only re-exports the module:

```rust
pub use libbpf_sys;
```

Source: <https://docs.rs/libbpf-rs/latest/src/libbpf_rs/lib.rs.html>

Concrete import paths:

```rust
use libbpf_rs::libbpf_sys::{
    BPF_LD, BPF_LDX, BPF_ST, BPF_STX, BPF_ALU, BPF_ALU64, BPF_JMP, BPF_JMP32,
    BPF_K, BPF_X,
    BPF_REG_0, BPF_REG_1, BPF_REG_10,
    BPF_DW, BPF_W, BPF_H, BPF_B,
    BPF_MOV, BPF_ADD, BPF_SUB, BPF_XOR,
};
```

or:

```rust
use libbpf_sys::{BPF_ALU64, BPF_MOV, BPF_K, BPF_REG_0};
```

Examples from docs.rs:

- `BPF_ALU64`: <https://docs.rs/libbpf-sys/1.7.0%2Bv1.7.0/libbpf_sys/constant.BPF_ALU64.html>
- `BPF_REG_0`: <https://docs.rs/libbpf-sys/1.7.0%2Bv1.7.0/libbpf_sys/constant.BPF_REG_0.html>

Conclusion: libbpf-rs does not give a bytecode-oriented constants namespace. Depending on it just for constants would drag in libbpf-sys and libbpf build/link behavior.

## Question 3: BPF program type enum

Answer: `libbpf-rs` does provide a Rust enum:

- `libbpf_rs::ProgramType`

It is `#[non_exhaustive]`, `#[repr(u32)]`, and maps to kernel `enum bpf_prog_type`. It includes variants such as `SocketFilter`, `Kprobe`, `Xdp`, `Tracing`, `StructOps`, `Lsm`, `SkLookup`, `Syscall`, `Netfilter`, and `Unknown`. Source: <https://docs.rs/libbpf-rs/latest/libbpf_rs/enum.ProgramType.html>

The low-level FFI type is not a Rust enum:

- `libbpf_sys::bpf_prog_type` is a type alias to `c_uint`.
  Source: <https://docs.rs/libbpf-sys/1.7.0%2Bv1.7.0/libbpf_sys/type.bpf_prog_type.html>

`ProgramType` implements `From<u32>`, but I found no `FromStr` implementation in `libbpf-rs 0.26.2`, and docs.rs lists only `From<u32>` among conversion traits. So there is no built-in mapping from CLI strings like `xdp`, `socket_filter`, or `kprobe` to `ProgramType`.

Conclusion: useful as a reference enum for upstream program types, but not enough for `bpfverify --prog-type xdp`; we still need our own CLI string parser. It also will not know about fork-only program type additions unless libbpf-sys headers are updated.

## Question 4: Instruction decoding and disassembly

Answer: no. `libbpf-rs` exposes:

- read-only slices of `libbpf_sys::bpf_insn` from libbpf-managed object programs;
- `Vec<u8>` for queried live program `xlated_prog_insns`;
- no module like `libbpf_rs::insn`, `libbpf_rs::decode`, or `libbpf_rs::disasm`.

The crate item list has modules only for `btf`, `query`, and `skel`, plus object/map/program wrappers. Source: <https://docs.rs/libbpf-rs/latest/libbpf_rs/>

The local source search for `BpfInsn`, `Instruction`, `disasm`, and `disassemble` in `libbpf-rs 0.26.2/src` found no bytecode parser or disassembler API.

Conclusion: raw byte parsing, instruction validation, LD_IMM64 pairing, pretty-printing, and disassembly must be implemented by us or another dedicated bytecode crate. `libbpf-rs` does not replace `bpfopt-core/src/insn.rs`.

## Question 5: Direct `bpf()` syscall for arbitrary commands

Answer: neither `libbpf-rs` nor `libbpf-sys` exposes a public generic Rust `bpf(cmd, attr, size)` wrapper that accepts arbitrary command IDs.

`libbpf-sys` exposes many libbpf C APIs for known commands, for example:

- `bpf_map_update_elem`
- `bpf_obj_get_info_by_fd`
- `bpf_prog_get_fd_by_id`
- `bpf_prog_load`

Example: <https://docs.rs/libbpf-sys/1.7.0%2Bv1.7.0/libbpf_sys/fn.bpf_map_update_elem.html>

The vendored libbpf C source has an internal `static inline int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)` that calls `syscall(__NR_bpf, cmd, attr, size)`, but because it is `static inline` internal C code it is not exported in bindgen. Local `rg '^\\s*pub fn bpf\\(' libbpf-sys-1.7.0+v1.7.0/src/bindings.rs` found no match.

Upstream `libbpf-sys 1.7.0+v1.7.0` also has no constants for our fork-only `BPF_PROG_REJIT` or `BPF_PROG_GET_ORIGINAL`; local search in generated bindings found no match.

Conclusion: for `BPF_PROG_REJIT` and `BPF_PROG_GET_ORIGINAL`, we need our own `kernel-sys` direct syscall wrapper using `libc::syscall(libc::SYS_bpf, cmd, attr, size)` and fork UAPI definitions.

## Question 6: Build dependencies and cross compile

Answer: default is vendored static libbpf, not dynamic `libbpf.so`, but not a fully static dependency graph.

`cargo info libbpf-rs` reported:

- `libbpf-rs 0.26.2`
- default feature: `libbpf-sys/vendored-libbpf`
- feature `static`: `libbpf-sys/static`
- feature `vendored`: `libbpf-sys/vendored`

`cargo info libbpf-sys` reported:

- `libbpf-sys 1.7.0+v1.7.0`
- default feature: `vendored-libbpf`
- `vendored-libbpf = [static-libbpf]`
- optional `vendored = [vendored-libbpf, vendored-libelf, vendored-zlib]`
- optional `static = [static-libbpf, static-libelf, static-zlib]`
- optional `novendor = []`

docs.rs/libbpf-sys states that cargo build compiles an included copy of libbpf and statically links it into the binary. It still requires a working C compiler toolchain, zlib development headers, libelf development headers, and pkg-config. It also states binaries dynamically link `libz` and `libelf` by default. Sources:

- Build requirements and distribution: <https://docs.rs/crate/libbpf-sys/latest>
- Feature flags: <https://docs.rs/crate/libbpf-sys/latest/features>

ARM64 cross compile impact:

- Cross-compiling with default features needs a target C toolchain that can build vendored libbpf.
- It also needs target `libelf`/`zlib` headers/libs discoverable by pkg-config unless using `vendored`/`static` features for those dependencies.
- `libbpf-sys` documents `LIBBPF_SYS_LIBRARY_PATH_<TARGET_TRIPLE>` for per-target library paths and `LIBBPF_SYS_EXTRA_CFLAGS` for vendored builds. Source: <https://docs.rs/crate/libbpf-sys/latest>

Conclusion: this is a heavy dependency for a bytecode IR crate. It would also violate the v3 preference that `bpfopt` remain pure bytecode and that kernel-facing syscall code stay in `kernel-sys`.

## Question 7: `bpf_program_load_insns` / `bpf_prog_load` for raw insn arrays

Answer: high-level `libbpf-rs` does not provide a safe raw-insn `BPF_PROG_LOAD` helper. Low-level `libbpf-sys` does expose:

```rust
pub unsafe extern "C" fn bpf_prog_load(
    prog_type: bpf_prog_type,
    prog_name: *const c_char,
    license: *const c_char,
    insns: *const bpf_insn,
    insn_cnt: size_t,
    opts: *mut bpf_prog_load_opts,
) -> c_int
```

Source: <https://docs.rs/libbpf-sys/1.7.0%2Bv1.7.0/libbpf_sys/fn.bpf_prog_load.html>

`bpf_prog_load_opts` exposes verifier log fields (`log_level`, `log_size`, `log_buf`, `log_true_size`) and attach/fd-array fields (`expected_attach_type`, `fd_array`, `fd_array_cnt`, etc.). Source: <https://docs.rs/libbpf-sys/1.7.0%2Bv1.7.0/libbpf_sys/struct.bpf_prog_load_opts.html>

So it is technically possible to use `libbpf_sys::bpf_prog_load` for `bpfverify` after converting stdin bytes into `libbpf_sys::bpf_insn[]`. But this is not a libbpf-rs safe API, and success returns a loaded program FD; a verifier-only CLI would still need to close the FD immediately. There is no special high-level dry-run API.

Recommendation for `bpfverify`: use our own `kernel-sys` direct `bpf(BPF_PROG_LOAD, union bpf_attr, sizeof)` wrapper, not `libbpf-rs`. Reasons:

- same syscall layer can support fork-only `BPF_PROG_REJIT` and `BPF_PROG_GET_ORIGINAL`;
- avoids linking libbpf/libelf/zlib into simple CLI tools;
- keeps bpfopt-suite aligned with v3's split between pure bytecode code and kernel syscall code;
- makes stdin raw byte parsing explicit and testable.

## Final conclusion

`libbpf-rs` cannot replace a project-owned lightweight `bpfinsn`/`bpfopt-core::insn` library.

What it provides:

- access to bindgen FFI type `libbpf_sys::bpf_insn`;
- upstream opcode/register/program-type constants through `libbpf_sys`;
- `libbpf_rs::ProgramType` for upstream program type values;
- object-loader and map/program interaction APIs;
- low-level `libbpf_sys::bpf_prog_load` for raw instruction loading if we accept libbpf-sys.

What it does not provide:

- safe, owned, bytecode-level Rust instruction struct tailored to raw `struct bpf_insn[]`;
- raw bytes to instruction parsing/serialization helpers;
- instruction decoder, verifier-friendly structural checks, LD_IMM64 pairing logic, or disassembler;
- CLI string to program type mapping;
- generic arbitrary `bpf()` syscall wrapper;
- fork UAPI support for `BPF_PROG_REJIT` and `BPF_PROG_GET_ORIGINAL`;
- lightweight build profile suitable for a pure bytecode optimizer crate.

## Recommended plan

1. Keep a lightweight in-repo bytecode library for `struct bpf_insn` representation, parse/serialize, opcode/reg constants, LD_IMM64 handling, and display/disassembly helpers.
2. Keep `bpfopt` depending only on that pure bytecode library and non-kernel side-input parsers.
3. Implement `kernel-sys` as our minimal raw syscall crate using `libc::syscall`, with local definitions for upstream BPF commands used by the CLIs plus fork-only `BPF_PROG_REJIT` and `BPF_PROG_GET_ORIGINAL`.
4. For `bpfverify`, use `kernel-sys` direct `BPF_PROG_LOAD`; close the returned FD on success. Do not depend on `libbpf-rs` or `libbpf-sys`.
5. Optionally use `libbpf-sys` only as a reference while writing tests for constant values and layout, not as a runtime dependency.

