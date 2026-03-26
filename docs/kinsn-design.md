# kinsn v2 Design and Implementation

Date: 2026-03-26  
Status: current design as implemented in this tree  
Theme: first-class kinsn instruction encoding + proof lowering + shared kfunc/BTF metadata plumbing

## 0. Scope

This document describes what is true in the current repository, not the older aspirational model from temporary design notes.

In particular, the current tree does **not** have:

- a standalone `register_bpf_kinsn_set()` API
- a standalone `btf->kinsn_tab`
- a standalone `prog->aux->kinsn_tab`
- `BPF_PSEUDO_KINSN_CALL` sites whose `imm` names a `BTF_KIND_VAR` descriptor object

What the current tree **does** have is:

- dedicated kinsn instruction encoding in BPF bytecode
- dedicated verifier lowering and restore logic for kinsn proof sequences
- dedicated native JIT dispatch for kinsn sites
- shared registration, BTF lookup, and per-program caching machinery built on top of the existing kfunc infrastructure

Primary source files:

- Kernel ABI and core types:
  - [`vendor/linux-framework/include/uapi/linux/bpf.h`](../vendor/linux-framework/include/uapi/linux/bpf.h)
  - [`vendor/linux-framework/include/linux/bpf.h`](../vendor/linux-framework/include/linux/bpf.h)
  - [`vendor/linux-framework/include/linux/btf.h`](../vendor/linux-framework/include/linux/btf.h)
  - [`vendor/linux-framework/include/linux/bpf_verifier.h`](../vendor/linux-framework/include/linux/bpf_verifier.h)
- Kernel implementation:
  - [`vendor/linux-framework/kernel/bpf/verifier.c`](../vendor/linux-framework/kernel/bpf/verifier.c)
  - [`vendor/linux-framework/kernel/bpf/btf.c`](../vendor/linux-framework/kernel/bpf/btf.c)
  - [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`](../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)
  - [`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`](../vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c)
- Modules, daemon, and tests:
  - [`module/include/kinsn_common.h`](../module/include/kinsn_common.h)
  - [`module/x86/`](../module/x86)
  - [`module/arm64/`](../module/arm64)
  - [`daemon/src/insn.rs`](../daemon/src/insn.rs)
  - [`daemon/src/kfunc_discovery.rs`](../daemon/src/kfunc_discovery.rs)
  - [`daemon/src/passes/utils.rs`](../daemon/src/passes/utils.rs)
  - [`tests/unittest/rejit_kinsn.c`](../tests/unittest/rejit_kinsn.c)

Useful higher-level design references:

- [`docs/tmp/20260323/kinsn_v2_instantiate_design_20260323.md`](./tmp/20260323/kinsn_v2_instantiate_design_20260323.md)
- [`docs/tmp/20260325/kinsn_kfunc_unification_research_20260325.md`](./tmp/20260325/kinsn_kfunc_unification_research_20260325.md)
- [`docs/tmp/20260325/kinsn_func_id_transport_design_20260325.md`](./tmp/20260325/kinsn_func_id_transport_design_20260325.md)

## 1. One-sentence definition

`kinsn` is a first-class BPF instruction form whose canonical semantics come from
`instantiate_insn(payload, insn_buf)`, whose verifier path temporarily lowers it
to ordinary BPF for proof checking, and whose execution path either emits native
machine code or falls back to the same instantiated BPF sequence.

The important qualifier is that "first-class" is true at the instruction,
verifier, and JIT layers. The current tree still reuses kfunc/BTF plumbing for
registration, BTF lookup, and per-program metadata caching.

## 2. Current Architecture Boundary

### 2.1 Dedicated instruction encoding

The current UAPI has dedicated kinsn opcodes:

- `BPF_PSEUDO_KINSN_SIDECAR`
- `BPF_PSEUDO_KINSN_CALL`

The relevant comment in
[`vendor/linux-framework/include/uapi/linux/bpf.h`](../vendor/linux-framework/include/uapi/linux/bpf.h)
explicitly says that `BPF_PSEUDO_KINSN_CALL` carries the BTF ID of a
`BTF_KIND_FUNC` kinsn stub.

This means the bytecode-level representation is not a plain kfunc call.
Verifier and JIT both recognize `BPF_PSEUDO_KINSN_CALL` directly.

### 2.2 Canonical semantics still come from `struct bpf_kinsn`

The current descriptor shape in
[`vendor/linux-framework/include/linux/bpf.h`](../vendor/linux-framework/include/linux/bpf.h)
is:

```c
struct bpf_kinsn {
	struct module *owner; /* NULL for built-in/vmlinux descriptors */
	u16 max_insn_cnt;
	u16 max_emit_bytes;

	int (*instantiate_insn)(u64 payload, struct bpf_insn *insn_buf);

	int (*emit_x86)(u8 *image, u32 *off, bool emit,
			u64 payload, const struct bpf_prog *prog);
	int (*emit_arm64)(u32 *image, int *idx, bool emit,
			  u64 payload, const struct bpf_prog *prog);
};
```

Current meaning:

- `instantiate_insn()` is the canonical BPF-visible semantics source
- native emit callbacks are architecture-specific refinements of that semantics
- generic fallback uses the same instantiated sequence, not a separate kfunc model

There is no active `model_call()` or `bpf_kinsn_effect` path in the current tree.

### 2.3 Current transport identity

The transport for one kinsn site is:

- one sidecar pseudo-insn carrying the packed payload
- one `CALL` whose `src_reg = BPF_PSEUDO_KINSN_CALL`

The sidecar payload format is implemented by
`bpf_kinsn_sidecar_payload()` in
[`vendor/linux-framework/include/linux/bpf.h`](../vendor/linux-framework/include/linux/bpf.h)
and mirrored by `BpfInsn::kinsn_sidecar()` in
[`daemon/src/insn.rs`](../daemon/src/insn.rs):

- bits `[3:0]`: `dst_reg`
- bits `[19:4]`: `off`
- bits `[51:20]`: `imm`

The call-site identity is the part that the previous version of this document
got wrong:

- `CALL.imm` is the BTF ID of a `BTF_KIND_FUNC` kinsn stub
- `CALL.off` is the 1-based `fd_array` slot for the module BTF FD, or `0` for vmlinux

The call site does **not** directly name a `BTF_KIND_VAR` descriptor object.

Descriptor globals such as `bpf_rotate64_desc` still exist in C and may appear
in module BTF as variables, but that is not what `BPF_PSEUDO_KINSN_CALL`
addresses.

### 2.4 Registration and metadata reuse the kfunc path

The current module-side contract is:

1. export a stub kfunc such as `__bpf_kfunc void bpf_rotate64(void) {}`
2. register that stub in a `BTF_KFUNCS_*` ID set
3. provide a parallel `kinsn_descs[]` array holding the actual
   `const struct bpf_kinsn *` descriptors
4. register everything through `register_btf_kfunc_id_set()`

This is visible in:

- [`module/include/kinsn_common.h`](../module/include/kinsn_common.h)
- [`module/x86/bpf_rotate.c`](../module/x86/bpf_rotate.c)
- [`module/arm64/bpf_rotate.c`](../module/arm64/bpf_rotate.c)

The key type is `struct btf_kfunc_id_set` in
[`vendor/linux-framework/include/linux/btf.h`](../vendor/linux-framework/include/linux/btf.h):

```c
struct btf_kfunc_id_set {
	struct module *owner;
	struct btf_id_set8 *set;
	btf_kfunc_filter_t filter;
	const struct bpf_kinsn * const *kinsn_descs;
};
```

So the current implementation is not a fully separate "kinsn registry"
subsystem. It is a dedicated instruction encoding layered on top of shared
kfunc/BTF registration and lookup machinery.

Current lookup path:

- module init calls `register_btf_kfunc_id_set()`
- [`vendor/linux-framework/kernel/bpf/btf.c`](../vendor/linux-framework/kernel/bpf/btf.c)
  stores the kfunc set and the parallel kinsn descriptor mapping in
  `btf->kfunc_set_tab`
- verifier uses `btf_kfunc_kinsn_desc()` to recover the `struct bpf_kinsn *`
- verifier caches per-program metadata in `prog->aux->kfunc_tab` and
  `prog->aux->kfunc_btf_tab`
- JIT later resolves payload and descriptor through `bpf_jit_get_kinsn_payload()`

There is no current `register_bpf_kinsn_set()`, `btf->kinsn_tab`, or
`prog->aux->kinsn_tab`.

## 3. Verifier Pipeline and Proof Lowering

### 3.1 Early descriptor collection

`add_subprog_and_kfunc()` in
[`vendor/linux-framework/kernel/bpf/verifier.c`](../vendor/linux-framework/kernel/bpf/verifier.c)
is where current kinsn sites first enter verifier bookkeeping.

For each `BPF_PSEUDO_KINSN_CALL` site, the verifier:

- counts the site in `env->kinsn_call_cnt`
- routes metadata creation through `add_kfunc_desc(..., true)`
- resolves the backing `struct bpf_kinsn *` through `fetch_kfunc_meta()` and
  `btf_kfunc_kinsn_desc()`
- stores the resulting entry in `prog->aux->kfunc_tab`

So current kinsn calls are "special" in instruction encoding, but not in the
descriptor table implementation.

### 3.2 Lowering happens before main verifier analysis

The current verifier timing is:

1. `add_subprog_and_kfunc()`
2. `lower_kinsn_proof_regions()`
3. CFG, postorder, SCC, liveness, and main verifier analysis
4. `restore_kinsn_proof_regions()`
5. later rewrite/fixup passes such as `remove_fastcall_spills_fills()`

This means the verifier analyzes instantiated proof sequences, not the original
two-insn kinsn encoding, but the program is restored back to the original
`sidecar + kinsn_call` form before later rewrite/JIT stages.

### 3.3 Lowering and restore mechanics

Current lowering is intentionally minimal:

- `lower_kinsn_proof_regions()` walks the program from back to front
- for each kinsn site it requires a preceding sidecar
- it resolves `(kinsn, payload)` via `bpf_jit_get_kinsn_payload()`
- it calls `instantiate_insn(payload, proof_buf)`
- it validates the local structure of the proof sequence
- it removes the sidecar with `verifier_remove_insns()`
- it replaces the call site with the proof sequence via `bpf_patch_insn_data()`
- it records the original two instructions in `env->kinsn_regions[]`

Restore is the inverse:

- `restore_kinsn_proof_regions()` patches back the original two instructions
- it removes the remaining proof instructions
- it cleans affected jump-table aux state

There is no separate `build_kinsn_inst_seq()` helper in the current tree.

### 3.4 What `validate_kinsn_proof_seq()` actually enforces

The current local validation is narrower and more concrete than the older
version of this document claimed.

It rejects:

- nested kinsn sidecar pseudo-insns
- all calls and exits
- pseudo `ldimm64` forms (`BPF_LD | BPF_IMM` with non-zero `src_reg`)
- backward jumps / back-edges
- jumps that go outside the proof sequence boundary

One nuance matters:

- a forward jump may target the one-past-end boundary of the proof sequence
- so the verifier does **not** require every jump target to stay strictly
  inside the proof region

After this local structural validation, normal verifier analysis still runs on
the lowered ordinary-BPF proof sequence.

## 4. Execution and Fallback

### 4.1 Native JIT path

Current x86 and arm64 JITs both have dedicated kinsn dispatch:

- x86:
  [`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`](../vendor/linux-framework/arch/x86/net/bpf_jit_comp.c)
  `emit_kinsn_desc_call()`
- arm64:
  [`vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`](../vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c)
  `emit_kinsn_desc_call_arm64()`

At JIT time, the implementation does not look up symbol names or walk BTF by
name again. Instead it calls `bpf_jit_get_kinsn_payload()` and resolves the
descriptor from the already prepared `prog->aux->kfunc_tab` entry.

So the current statement is:

- kinsn has dedicated JIT dispatch
- but descriptor lookup is still backed by the shared kfunc metadata table

### 4.2 Generic fallback

Current generic fallback lives in `do_misc_fixups()` in
[`vendor/linux-framework/kernel/bpf/verifier.c`](../vendor/linux-framework/kernel/bpf/verifier.c).

For each kinsn site:

- if `prog->jit_requested` is true **and** the descriptor has a native emit
  callback for the running architecture, the original kinsn site stays intact
- otherwise, the sidecar and call are rewritten into the instantiated ordinary
  BPF sequence

So the current fallback behavior is:

- no JIT requested -> lower to ordinary BPF
- JIT requested but no native emit on this architecture -> lower to ordinary BPF
- native emit available -> keep original kinsn representation for JIT

This fallback does **not** route through a kfunc execution model.

## 5. Module, Daemon, and Test Responsibilities

### 5.1 Modules

Current in-tree modules follow the same pattern on both x86 and arm64:

- export a stub kfunc
- provide a `const struct bpf_kinsn ..._desc`
- implement `instantiate_insn()`
- implement native emit for the target architecture
- register through `DEFINE_KINSN_V2_MODULE(...)`

Current in-tree targets include:

- rotate
- select
- extract
- endian load16/load32/load64
- speculation barrier

Representative files:

- [`module/x86/bpf_rotate.c`](../module/x86/bpf_rotate.c)
- [`module/x86/bpf_select.c`](../module/x86/bpf_select.c)
- [`module/x86/bpf_extract.c`](../module/x86/bpf_extract.c)
- [`module/x86/bpf_endian.c`](../module/x86/bpf_endian.c)
- [`module/x86/bpf_barrier.c`](../module/x86/bpf_barrier.c)
- [`module/arm64/bpf_rotate.c`](../module/arm64/bpf_rotate.c)
- [`module/arm64/bpf_select.c`](../module/arm64/bpf_select.c)
- [`module/arm64/bpf_extract.c`](../module/arm64/bpf_extract.c)
- [`module/arm64/bpf_endian.c`](../module/arm64/bpf_endian.c)
- [`module/arm64/bpf_barrier.c`](../module/arm64/bpf_barrier.c)

### 5.2 Daemon

The daemon is already aligned with the current transport, but the transport is
function-ID based, not variable-ID based.

Current daemon responsibilities are:

- discover module BTF-backed kinsn stubs from `/sys/kernel/btf/<module>`
- find `BTF_KIND_FUNC` IDs for known stub names
- bias split-BTF type IDs by the vmlinux type count to recover the absolute
  kernel-visible BTF ID accepted by the verifier
- obtain real BPF BTF FDs for the relevant modules
- emit `sidecar + BPF_PSEUDO_KINSN_CALL` sequences

Relevant files:

- [`daemon/src/kfunc_discovery.rs`](../daemon/src/kfunc_discovery.rs)
- [`daemon/src/insn.rs`](../daemon/src/insn.rs)
- [`daemon/src/passes/utils.rs`](../daemon/src/passes/utils.rs)

### 5.3 Tests

Current repo-owned coverage for this path is centered in
[`tests/unittest/rejit_kinsn.c`](../tests/unittest/rejit_kinsn.c).

That test suite covers current end-to-end behavior such as:

- kinsn discovery through module BTF and BTF FDs
- packed sidecar transport semantics
- REJIT correctness for rotate/select/extract/endian/barrier
- x86 native emit byte-pattern checks for rotate
- rollback behavior when REJIT fails

## 6. Bottom Line

The current repository is best described as:

- first-class kinsn instruction encoding
- `instantiate_insn()` as the canonical semantics source
- verifier proof lowering plus restore
- dedicated native JIT dispatch
- ordinary-BPF fallback when native emit is unavailable
- shared kfunc/BTF registration and metadata caching underneath

So the precise current statement is **not** "kinsn is just a kfunc", but it is
also **not** "kinsn has a completely separate descriptor transport and table
stack".

It is a hybrid:

- dedicated at the bytecode, verifier-lowering, and JIT-dispatch layers
- shared at the registration, BTF lookup, and per-program descriptor-cache layers
