# REJIT V2 Debug Bug Log - 2026-03-24

This file records concrete bugs encountered while migrating REJIT/kinsn to pure v2.
Only repo bugs are listed here. Command-line mistakes or one-off debugging mishaps are excluded.

## Fixed

### 1. `validate_kinsn_proof_seq()` used the wrong jump offset field for `BPF_JMP32 | BPF_JA`

- Location: `vendor/linux-framework/kernel/bpf/verifier.c`
- Symptom: malformed proof sequences using `JMP32|JA` could evade region-boundary validation.
- Root cause: verifier used `insn->off` for all jumps, but `BPF_JMP32 | BPF_JA` stores its offset in `insn->imm`.
- Fix: use `insn->imm` for `BPF_JMP32 | BPF_JA`.

### 2. `bpf_prog_rejit_swap()` did not keep `kinsn_tab` symmetric with `kfunc_tab`

- Location: `vendor/linux-framework/kernel/bpf/syscall.c`
- Symptom: REJIT metadata handling was asymmetric and fragile across swap.
- Root cause: `kfunc_tab` was swapped, `kinsn_tab` was not.
- Fix: swap `kinsn_tab` as part of `bpf_prog_rejit_swap()`.

### 3. Sidecar payload packing did not mask `dst_reg` to 4 bits

- Location: `vendor/linux-framework/include/linux/bpf.h`
- Symptom: sidecar payload fields could overlap if `dst_reg` carried unexpected upper bits.
- Root cause: `bpf_kinsn_sidecar_payload()` packed the full `u8 dst_reg` instead of the low 4 bits.
- Fix: explicitly mask with `0xf`.

### 4. REJIT could silently publish stale xlated bytecode after a successful larger replacement

- Location: `vendor/linux-framework/kernel/bpf/syscall.c`
- Symptom: `bpftool prog dump xlated` could lag behind the live JIT image when the replacement program grew.
- Root cause: `bpf_prog_rejit_swap()` conditionally skipped copying `tmp->insnsi` into `prog->insnsi` if the new insn blob no longer fit the original allocation, but still completed the swap.
- Fix: reject oversize replacements before swap and make xlated-insn copy unconditional once fit is guaranteed.

### 5. `struct_ops` trampoline CALL-site scan used raw byte matching

- Location: `vendor/linux-framework/kernel/bpf/bpf_struct_ops.c`
- Symptom: byte scan for `0xE8` could mis-detect a call site inside unrelated instruction bytes.
- Root cause: `find_call_site()` scanned raw bytes instead of decoding x86 instructions.
- Fix: switch to the x86 instruction decoder (`asm/insn.h`) and walk instruction boundaries.

### 6. x86 kinsn emit bounded the output after the callback had already written into the final JIT image

- Location: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
- Symptom: buggy module emitters could overrun the final JIT image before `max_emit_bytes` was validated.
- Root cause: the callback wrote directly into the destination buffer.
- Fix: emit into a local scratch buffer first, validate length, then copy into the final image.

### 7. ARM64 JIT cast away `const struct bpf_prog *`

- Location: `vendor/linux-framework/arch/arm64/net/bpf_jit_comp.c`
- Symptom: API was weaker than intended and invited accidental mutation through const-cast.
- Root cause: `emit_arm64` callback API and call sites were not const-correct.
- Fix: make `emit_x86` / `emit_arm64` take `const struct bpf_prog *` and update callers/module emitters.

### 8. Fixed-size proof-region and descriptor tables introduced arbitrary cliffs

- Locations:
  - `vendor/linux-framework/include/linux/bpf_verifier.h`
  - `vendor/linux-framework/kernel/bpf/verifier.c`
- Symptom:
  - programs with more than 256 kinsn sites failed with `too many kinsn proof regions`
  - kfunc/kinsn descriptor tables had similar fixed-size cliffs
  - proof lowering still depended on a small fixed `env->insn_buf` shape in places where dynamic sizing was cleaner
- Root cause: verifier used fixed arrays + counters for expedience.
- Fix:
  - allocate proof regions dynamically based on actual site count
  - allocate kfunc/kinsn descriptor tables dynamically
  - allocate per-site proof buffers based on `kinsn->max_insn_cnt`

### 9. `restore_kinsn_proof_regions()` used stale `region->start` values after earlier-site lowering changed program length

- Location: `vendor/linux-framework/kernel/bpf/verifier.c`
- Symptom:
  - `rotate_dense` failed in `BPF_PROG_REJIT` with `Unknown error 524`
  - verifier log itself reached `safe`
  - debug validator reported:
    - `invalid ldimm64 layout after restore_kinsn_proof_regions`
- Root cause:
  - proof lowering walked sites from end to start
  - later regions were recorded before earlier sites were expanded or shrunk
  - when a lower-index site changed length, already-recorded higher-index `region->start` values became stale
  - restore then patched the wrong place and orphaned `ldimm64` second slots
- Fix:
  - after lowering a site, shift all previously recorded later-region starts by the net delta `proof_len - 2`
- Verification:
  - `rotate_dense` now passes again under VM static verification:
    - `applied=1`
    - `verifier_accepted=1`
  - Added repo regression coverage:
    - [`tests/unittest/rejit_kinsn.c`](/home/yunwei37/workspace/bpf-benchmark/tests/unittest/rejit_kinsn.c): `test_rejit_rotate_restore_preserves_ldimm64_layout`
    - [`tests/unittest/rejit_kinsn.c`](/home/yunwei37/workspace/bpf-benchmark/tests/unittest/rejit_kinsn.c): `patch_all_kinsns`

### 10. Static-verify reporting conflated post-verifier REJIT failures with verifier rejection

- Locations:
  - `daemon/src/bpf.rs`
  - `daemon/src/commands.rs`
- Symptom:
  - some `BPF_PROG_REJIT` failures were summarized as `verifier_rejected`
  - this misdirected debugging toward verifier semantics even when the verifier log had already reached `safe`
- Root cause:
  - user-space result classification was too coarse and treated any error carrying a verifier log as verifier rejection
- Fix:
  - distinguish verifier rejection from post-verify REJIT failures
  - treat `E2BIG`/`ENOSPC`-style failures with complete verifier logs as retryable post-verify failures
  - attribute those failures to the last changed pass instead of the verifier
- Verification:
  - added daemon regression coverage:
    - [`daemon/src/commands.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/commands.rs): `test_complete_verifier_log_e2big_is_retryable_post_verify_failure`
    - [`daemon/src/commands.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/commands.rs): `test_attribute_post_verify_rejit_failure_uses_last_changed_pass`

### 11. Endian dense nonzero-offset sites expanded too much and tripped post-verify `E2BIG`

- Locations:
  - `module/include/kinsn_common.h`
  - `module/x86/bpf_endian.c`
  - `module/arm64/bpf_endian.c`
  - `daemon/src/passes/endian.rs`
- Symptom:
  - `endian_swap_dense` initially failed after the `bswap0` fix
  - verifier log reached `safe`
  - `BPF_PROG_REJIT` then failed with `Argument list too long (os error 7)`
- Root cause:
  - endian payload encoded only `(dst_reg, base_reg, size)`
  - nonzero offsets had to be materialized as extra `add/sub` instructions around each site
  - dense programs therefore grew enough to hit the post-verify page-size limit in `bpf_prog_rejit()`
- Fix:
  - make endian payload offset-aware
  - have proof lowering instantiate direct `LDX + BPF_END`
  - have native emit consume the encoded offset directly on x86 and arm64 when encodable
  - keep add/sub materialization only as a target-specific fallback path when required
- Verification:
  - VM static verify now passes directly for [`micro/programs/endian_swap_dense.bpf.o`](/home/yunwei37/workspace/bpf-benchmark/micro/programs/endian_swap_dense.bpf.o):
    - `applied=1`
    - `passes_applied=['endian_fusion']`
    - `insn_delta=0`
    - `daemon_verifier_retries=0`
  - Added repo regression coverage:
    - [`tests/unittest/rejit_kinsn.c`](/home/yunwei37/workspace/bpf-benchmark/tests/unittest/rejit_kinsn.c): `test_rejit_endian32_apply`
    - [`daemon/src/passes/mod.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/mod.rs): `test_full_pipeline_real_bytecode_endian_swap_dense`

### 12. Kinsn descriptor resolution relied on `kallsyms_lookup_name()` instead of explicit registration

- Locations:
  - `vendor/linux-framework/kernel/bpf/verifier.c`
  - `vendor/linux-framework/kernel/bpf/btf.c`
  - `vendor/linux-framework/include/linux/bpf.h`
  - `module/include/kinsn_common.h`
- Symptom:
  - verifier resolved `BPF_PSEUDO_KINSN_CALL` descriptors by taking the BTF var name and calling `kallsyms_lookup_name()`
  - this left kinsn descriptor lookup outside the normal BTF/module registration model and created an upstream acceptance blocker
- Root cause:
  - first-cut pure-v2 transport kept the BTF var identity but still recovered the runtime pointer through the global symbol table
  - module-side `DEFINE_KINSN_V2_MODULE()` also registered no descriptor set, so the explicit registration path existed only partially
- Fix:
  - register kinsn descriptor sets explicitly with `register_bpf_kinsn_set()`
  - resolve descriptor BTF var IDs against the owning module BTF at module init
  - have verifier look up descriptors through the registered `btf->kinsn_tab` using `(module BTF, var_id)` instead of `kallsyms_lookup_name()`
  - add `unregister_bpf_kinsn_set()` and make module exit paths unregister cleanly
- Verification:
  - covered by the VM correctness matrix because every kinsn-bearing module now depends on explicit registration before load/use

### 13. VM e2e `katran` failed because the guest did not receive required net modules from `.virtme_mods`

- Locations:
  - `Makefile`
  - `e2e/cases/katran/case.py`
- Symptom:
  - `vm-e2e` failed in the guest with:
    - `ip link add katran0 type veth peer name rtlb0`
    - `Error: Unknown device type.`
- Root cause:
  - the guest correctly ran `modprobe veth` / `modprobe ipip`
  - but the repo’s hostfs module set only exposed the custom kinsn modules, not the dependent net modules required by the `katran` case
- Fix:
  - add the required guest-visible modules to the hostfs module bundle:
    - `drivers/net/veth.ko`
    - `net/ipv4/ip_tunnel.ko`
    - `net/ipv4/tunnel4.ko`
    - `net/ipv4/ipip.ko`
- Verification:
  - [`e2e/results/katran_20260325_015121/metadata.json`](/home/yunwei37/workspace/bpf-benchmark/e2e/results/katran_20260325_015121/metadata.json): `completed`
  - later full `vm-e2e` rerun completed successfully

### 14. Kinsn descriptor lookup still exposed a too-broad helper and unnecessarily rejected built-in descriptors

- Locations:
  - `vendor/linux-framework/kernel/bpf/btf.c`
  - `vendor/linux-framework/kernel/bpf/verifier.c`
  - `vendor/linux-framework/include/linux/bpf.h`
  - `vendor/linux-framework/include/linux/btf.h`
- Symptom:
  - verifier lookup already used the registered per-BTF kinsn table, but it still called a generic `bpf_find_registered_kinsn()` helper and then open-coded `try_module_get()`
  - `fetch_kinsn_desc_meta()` also rejected `owner == NULL`, which made built-in/vmlinux descriptors impossible even though registration already used `btf_get_module_btf(NULL)`
- Root cause:
  - the first registration-based cleanup stopped at replacing `kallsyms_lookup_name()`, but did not yet tighten the helper boundary around “lookup + lifetime acquisition”
- Fix:
  - replace the generic lookup helper with `btf_try_get_kinsn_desc()`
  - make verifier use that narrower helper directly
  - allow `owner == NULL` for built-in/vmlinux descriptors while still taking a module ref for module-backed descriptors
  - stop exposing the old generic lookup helper through `include/linux/bpf.h`

### 15. Branch diff still carried unrelated upstream churn in kernel runtime/test infrastructure

- Locations:
  - `vendor/linux-framework/net/bpf/test_run.c`
  - `vendor/linux-framework/tools/testing/selftests/bpf/jit_disasm_helpers.c`
  - `vendor/linux-framework/include/linux/btf.h`
- Symptom:
  - branch diff still contained:
    - removal of `bpf_prog_change_xdp()` around repeated XDP `test_run`
    - a selftest-only `normalize_movabs_imm_hex()` helper
    - a cosmetic blank-line deletion in `include/linux/btf.h`
- Root cause:
  - earlier exploratory changes leaked into the branch and were not directly required for pure-v2 REJIT/kinsn semantics
- Fix:
  - restore the repeated-XDP `test_run` behavior
  - restore the unrelated `btf.h` formatting line
  - initially tried dropping the selftest disassembly normalization helper, but latest `vm-test` showed it is still needed to normalize LLVM `movabsq $-0x...` output back to the positive-hex form expected by unmodified upstream regexes
  - keep the diff focused on REJIT/kinsn behavior, but preserve the normalization helper as a test-infra stability fix rather than a testcase semantic change

### 16. Registration-helper cleanup introduced a compile regression in `fetch_kinsn_desc_meta()`

- Location: `vendor/linux-framework/kernel/bpf/verifier.c`
- Symptom:
  - latest `make vm-test` kernel rebuild failed with:
    - `kernel/bpf/verifier.c:3662:9: error: ‘err’ undeclared`
- Root cause:
  - while converting verifier-side kinsn lookup to `btf_try_get_kinsn_desc()`, the function body started using `err` without adding a local declaration
- Fix:
  - add `int err;` to `fetch_kinsn_desc_meta()`

## Open

### 17. `proof lowering` still has a scaling issue beyond constant caps

- Location: `vendor/linux-framework/kernel/bpf/verifier.c`
- Symptom:
  - lowering/restore still patch the whole program per site
  - this is structurally O(number_of_sites * program_length)
  - patching is still bounded by existing program-rewrite machinery and jump-range constraints
- Root cause:
  - current implementation rewrites each site into the live verifier program instead of maintaining a separate proof view
- Status:
  - known design issue
  - not the immediate blocker for current correctness debugging

## Repo Regression Coverage Added In This Round

- [`tests/unittest/rejit_kinsn.c`](/home/yunwei37/workspace/bpf-benchmark/tests/unittest/rejit_kinsn.c)
  - `patch_all_kinsns`
  - `test_rejit_rotate_restore_preserves_ldimm64_layout`
  - `test_rejit_endian32_apply`
- [`daemon/src/commands.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/commands.rs)
  - `test_complete_verifier_log_e2big_is_retryable_post_verify_failure`
  - `test_attribute_post_verify_rejit_failure_uses_last_changed_pass`
- [`daemon/src/passes/mod.rs`](/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/mod.rs)
  - `test_full_pipeline_real_bytecode_endian_swap_dense`

## Boundaries Reaffirmed

- Upstream kernel selftests are not to be patched just to make this repo pass.
- Kernel/BPF runtime actions stay in the VM.
- Repo-owned v2 tests belong under `tests/`.
