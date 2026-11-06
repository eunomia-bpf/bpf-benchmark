# Permanent Arm bound suite after exclusive and D0 repairs

**30 cases:28 rejected,2 accepted findings.** Rejections are14 in the verifier,
13 in specialization and1 in the loader. All11 original requested negatives
reject. All four exclusive failure-branch programs now reject in the actual
verifier, as does the new D0 upper-half case. The remaining accepted programs
observe numeric SP or the outer entry return address; each has a nonzero
generation1 and is an active safety defect. Unsafe native code is never run.
These are native negative fixtures, not application-program mutation results.

This run uses T's new matching#24 Image (2026-11-06 18:37:58) and module18:39,
choice binding781ce6e93 and A's productiona7e5d6d8f. Source/proof/native inputs,
module/probe/linker/initramfs and exact Image are archived together. It does
not reuse the older#23 kernel that cannot admit the new bound choice.

| Case | Recorded outcome | Exact message |
| --- | --- | --- |
| past_data_end_read | verifier_rejected | [past_data_end_read.log](past_data_end_read.log) |
| past_data_end_write | verifier_rejected | [past_data_end_write.log](past_data_end_write.log) |
| missing_data_end_check | verifier_rejected | [missing_data_end_check.log](missing_data_end_check.log) |
| map_value_oob | verifier_rejected | [map_value_oob.log](map_value_oob.log) |
| nullable_map_dereference | verifier_rejected | [nullable_map_dereference.log](nullable_map_dereference.log) |
| invalid_helper_argument | verifier_rejected | [invalid_helper_argument.log](invalid_helper_argument.log) |
| stack_oob | verifier_rejected | [stack_oob.log](stack_oob.log) |
| uninitialized_stack | verifier_rejected | [uninitialized_stack.log](uninitialized_stack.log) |
| unbounded_loop | loader_rejected | [unbounded_loop.log](unbounded_loop.log) |
| unbounded_indirect_jump | specialization_rejected | [unbounded_indirect_jump.log](unbounded_indirect_jump.log) |
| unsupported_instruction | specialization_rejected | [unsupported_instruction.log](unsupported_instruction.log) |
| misaligned_sp | specialization_rejected | [misaligned_sp.log](misaligned_sp.log) |
| overlapping_load_pair | specialization_rejected | [overlapping_load_pair.log](overlapping_load_pair.log) |
| writeback_load_overlap | specialization_rejected | [writeback_load_overlap.log](writeback_load_overlap.log) |
| writeback_store_overlap | specialization_rejected | [writeback_store_overlap.log](writeback_store_overlap.log) |
| scalar_vector_load_clear_high | verifier_rejected | [scalar_vector_load_clear_high.log](scalar_vector_load_clear_high.log) |
| unpaired_stxr_failure | verifier_rejected | [unpaired_stxr_failure.log](unpaired_stxr_failure.log) |
| unpaired_stlxr_failure | verifier_rejected | [unpaired_stlxr_failure.log](unpaired_stlxr_failure.log) |
| paired_stxr_failure | verifier_rejected | [paired_stxr_failure.log](paired_stxr_failure.log) |
| paired_stlxr_failure | verifier_rejected | [paired_stlxr_failure.log](paired_stlxr_failure.log) |
| stxr_status_data_overlap | specialization_rejected | [stxr_status_data_overlap.log](stxr_status_data_overlap.log) |
| stlxr_status_data_overlap | specialization_rejected | [stlxr_status_data_overlap.log](stlxr_status_data_overlap.log) |
| stxr_status_base_overlap | specialization_rejected | [stxr_status_base_overlap.log](stxr_status_base_overlap.log) |
| stlxr_status_base_overlap | specialization_rejected | [stlxr_status_base_overlap.log](stlxr_status_base_overlap.log) |
| entry_return_address_flags | accepted_finding | [entry_return_address_flags.log](entry_return_address_flags.log) |
| return_register_overwrite | verifier_rejected | [return_register_overwrite.log](return_register_overwrite.log) |
| stack_base_flags | accepted_finding | [stack_base_flags.log](stack_base_flags.log) |
| undefined_entry_register | specialization_rejected | [undefined_entry_register.log](undefined_entry_register.log) |
| undefined_entry_flags | specialization_rejected | [undefined_entry_flags.log](undefined_entry_flags.log) |
| helper_clobbered_register | specialization_rejected | [helper_clobbered_register.log](helper_clobbered_register.log) |

outcomes.json retains the full assembly, every exact message and stage. The
accepted numeric cases are not excluded or relabeled. Generation-side loader
rejection for an unbounded loop is retained as such, not called a verifier
rejection. The command returns1 for the two accepted safety findings.

```sh
taskset -c 16-23 prlimit --as=12884901888 -- make -C kprog/fidelity negative-bound-qemu ARM_NEGATIVE_BOUND_BUILD=build-arm64/negative-current-choice ARM_NEGATIVE_BOUND_OUT=../results/kprog_fidelity_20261106/negative/arm64-current-choice
```

The test changes no app runner/workload and never executes a dangerous candidate.
Application-program negatives and numeric entry-state repair remain active work.
