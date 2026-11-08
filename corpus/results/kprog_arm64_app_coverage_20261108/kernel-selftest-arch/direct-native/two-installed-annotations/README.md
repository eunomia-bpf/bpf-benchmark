Two installed ARM annotations from268171331

The installed stage stays recorded for both original __failure rows. This report compares existing archived native P, specialized P, compiled B and program context. The catalog uses load-only submission.

| Program | eBPF annotation rule | Native P access | Compiled B access | Finding |
| --- | --- | --- | --- | --- |
| global_func14 | A global function parameter requires a known pointee extent; S is FWD | Entry passes zero to foo. Its CBZ selects RET; the other branch retains the conditional32-bit read through s | Initialized entry returns0. Private stack spill/tag cells remain; the source global foo parameter contract has its own BTF scope | Fixed-entry reachability and global-function BTF admissibility explain different acceptance questions |
| no_null_check | mmap_file file carries nullable provenance until a file!=NULL branch narrows it | Read u64 ctx[0], then u64 file+32, and save the inode pointer in a private stack slot | Instructions100/101 preserve both u64 reads;102 saves the pointer,107 returns0 | The active finding is paired-kernel LSM context/nullability qualification |

Global-function case

Native input SHA73acd214, request186 and installed program739 retain foo with its conditional memory read. The actual global_func14 entry setsX0=0, callsfoo, and the zero branch returns0. The compiled B path also returns0. The source annotation applies to the independently checked global BPF function parameter FWD S. Existing x86 complete-resource request121 rejects with invalid-func after26instructions, so its observed stage carries a separate helper/fault-arm resolution frontier.

LSM case

Native input SHA4d55ebe6, request260 and installed program1036 retain both reads in native P and B. Context records type29/expected_attach27/attach_btf_id70008. The retained paired ARM vmlinux identifies70008 as bpf_lsm_mmap_file, FUNC_PROTO16926, first parameter name file. Current paired hook source also names it file. The current btf_ctx_access rule adds PTR_MAYBE_NULL when the parameter name ends in __nullable. These concrete metadata facts locate the alignment question at the kernel LSM context contract, with both P/B loads preserved. The source-resource optional BTF EINVAL is retained separately from the correctly identified hook target. The exact matched x86 LSM request/context is the remaining cross-ISA comparison for C.

The original-source rules remain published. Installed-stage discrepancies keep their existing counts. Runtime admission additions0. evidence.tar.gz contains static disassemblies, original source text, context facts and diagnostic references; the original complete runtime remains at ../full-whole-resources/summary.json. Coordinator/C owns the paired-kernel qualification decision and V owns the ABI/stock-verifier premise interface.
