# BpfReJIT Evaluation — Methodology and Infrastructure (2026-05-07)

## 1. System Under Test

- **What it does**: re-JIT already-loaded eBPF programs in place: re-generate the BPF bytecode and replace in place transparently and keep all safety model.
- **Kernel**: forked Linux 7.0-rc2.
  - Two added syscall commands: `BPF_PROG_REJIT`, `BPF_PROG_GET_ORIGINAL`.
  - Modify kernel to support kinsn.
  - Modify kernel to support re-JIT and replace the hooks in place.
- *kinsn* modules expose arch-specific code sequences (wide load, byte-swap, `cmov`, prefetch) as JIT inline-emit hooks.

```
   runner ──socket──▶  bpfrejit-daemon  ──fork+exec──▶  bpfopt --pass <name>
   (Python)            (Rust)                          (Rust, pure bytecode)
                          │
                          │ kernel-sys
                          ▼
                       BPF_PROG_REJIT(log_level=2)
```

- **`bpfrejit-daemon`** (Rust) — only userspace component that calls BPF
  syscalls.
  - Live program discovery; side-input preparation (map values, BTF, fd-array
    from `prog_info.used_maps`).
  - Per-pass orchestration: `fork+exec bpfopt` → kernel re-JIT.
  - No in-process bytecode transform; no default pass policy.
- **`bpfopt`** (Rust) — pure-bytecode CLI.
  - `stdin = bpf_insn[]`, `stdout = bpf_insn[]`, `--report = JSON`.
  - One invocation = one named pass.
  - Zero kernel dependency.
- **Per-pass loop** (per program):
  1. daemon writes verifier states + side-inputs to files
  2. `bpfopt --pass <name>` rewrites bytecode
  3. daemon issues `BPF_PROG_REJIT(log_level=2)`; kernel re-verifies + re-emits
  4. on failure → recorded in result JSON, no fallback, no retry

## 2. Optimization Passes

Three classes; every benchmark run selects an explicit subset via
`BPFREJIT_BENCH_PASSES`.

### 2.1 kinsn-class — replace bytecode with a kfunc, lowered by an in-kernel kinsn module via `KFUNC_INLINE_EMIT`

- **`rotate`** — shift+or pair → native rotate (`bpf_rotate{32,64}`)
- **`cond_select`** — branch+select → `cmov` (`bpf_select64`)
- **`extract`** — bit-field extract → BMI `BEXTR` (`bpf_extract64`)
- **`endian_fusion`** — load+`bswap` → `MOVBE` (`bpf_endian_load{16,32}`)
- **`bulk_memory`** — scalarized `memcpy`/`memset` → SIMD or `REP MOVS`
  (`bpf_memcpy` / `bpf_memset`)
- **`prefetch`** — insert `prefetch` ahead of pointer-chasing loads
  (`bpf_prefetch`)

### 2.2 Bytecode-rewriting — pure BPF→BPF, no kfunc; kernel JIT lowers as usual

- **`noop`** — no transform; produces the verifier-state log that
  `map_inline` and `const_prop` consume
- **`wide_mem`** — collapse byte-by-byte ladder into one wide `LDX_MEM`
  (size `H` / `W` / `DW`)
- **`map_inline`** — speculate constant `bpf_map_lookup_elem` results from
  captured map values
- **`const_prop`** — propagate verifier-known constants, fold uses
- **`dce`** — drop instructions dead under verifier liveness
- **`bounds_check_merge`** — merge redundant bounds checks on the same range
- **`skb_load_bytes_spec`** — specialize `bpf_skb_load_bytes` to fixed-width
  loads

### 2.3 Profile-guided

- **`branch_flip`** — re-lay branches by predicted-taken direction;
  consumes per-site `bpfprof` PMU counters. **Not in default policy** until
  Paper B benchmark results decide; included here only because it shares the
  pass infrastructure.

### 2.4 Ordering constraint

`map_inline` and `const_prop` consume the verifier-state log produced by the
preceding pass; the runner therefore prepends `noop` whenever they appear
without another bytecode-rewriting pass in front.
