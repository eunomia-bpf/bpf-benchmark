# Existing ARM ISA48: fixed entry-frame replay

Visited48/48original published cases. Actual stages: {"accepted_finding": 11, "specialization_rejected": 4, "valid_executed": 4, "verifier_rejected": 29}. Existing suite exit:1. Negative native execution requests:0. ARM application replays:0.

All 48 native-input SHA256 values match the published baseline. The four executed positives return the expected value 2. The original harness exits 1 after recording its accepted findings; the guest, QEMU and outer replay each exit 0.

| Classification | Published baseline | Fixed entry frame |
| --- | ---: | ---: |
| valid_executed | 4 | 4 |
| verifier_rejected | 33 | 29 |
| specialization_rejected | 4 | 4 |
| accepted_finding | 7 | 11 |

Four cases move from verifier_rejected to accepted_finding: `exit_frame_pointer_map`, `exit_x19`, `below_sp_helper_output` and `below_sp_memset_output`. The exit-register changes accompany the [stock JIT frame preservation](../../README.md); the helper-output changes accompany the requested helper-check rollback. All four retain their original negative annotation and load-only classification. The other 44 stages match the baseline.

The published raw archive contains 314 members and 1,779,420 uncompressed file bytes. Every regular member was reread successfully, and its archived outcomes equal outcomes.json.gz. The tracked archive is 818,317 bytes.

| Case | Published stage | Fixed-frame stage | Original native bytes |
| --- | --- | --- | --- |
| valid_control | valid_executed | valid_executed | True |
| valid_copy_restore | valid_executed | valid_executed | True |
| valid_alias_load | valid_executed | valid_executed | True |
| valid_spill_restore | valid_executed | valid_executed | True |
| past_data_end_read | verifier_rejected | verifier_rejected | True |
| past_data_end_write | verifier_rejected | verifier_rejected | True |
| missing_data_end_check | verifier_rejected | verifier_rejected | True |
| map_value_oob | verifier_rejected | verifier_rejected | True |
| nullable_map_dereference | verifier_rejected | verifier_rejected | True |
| invalid_helper_argument | verifier_rejected | verifier_rejected | True |
| stack_oob | verifier_rejected | verifier_rejected | True |
| uninitialized_stack | accepted_finding | accepted_finding | True |
| unbounded_loop | verifier_rejected | verifier_rejected | True |
| unbounded_indirect_jump | specialization_rejected | specialization_rejected | True |
| unsupported_instruction | specialization_rejected | specialization_rejected | True |
| misaligned_sp | verifier_rejected | verifier_rejected | True |
| overlapping_load_pair | verifier_rejected | verifier_rejected | True |
| writeback_load_overlap | verifier_rejected | verifier_rejected | True |
| writeback_store_overlap | verifier_rejected | verifier_rejected | True |
| scalar_vector_load_clear_high | specialization_rejected | specialization_rejected | True |
| unpaired_stxr_failure | accepted_finding | accepted_finding | True |
| unpaired_stlxr_failure | accepted_finding | accepted_finding | True |
| paired_stxr_failure | accepted_finding | accepted_finding | True |
| paired_stlxr_failure | accepted_finding | accepted_finding | True |
| stxr_status_data_overlap | verifier_rejected | verifier_rejected | True |
| stlxr_status_data_overlap | verifier_rejected | verifier_rejected | True |
| stxr_status_base_overlap | verifier_rejected | verifier_rejected | True |
| stlxr_status_base_overlap | verifier_rejected | verifier_rejected | True |
| entry_return_address_flags | accepted_finding | accepted_finding | True |
| exit_frame_pointer_map | verifier_rejected | accepted_finding | True |
| exit_stack_pointer | verifier_rejected | verifier_rejected | True |
| below_sp_call | verifier_rejected | verifier_rejected | True |
| below_sp_helper_output | verifier_rejected | accepted_finding | True |
| below_sp_memset_output | verifier_rejected | accepted_finding | True |
| below_sp_memcpy_output | verifier_rejected | verifier_rejected | True |
| exit_x19 | verifier_rejected | accepted_finding | True |
| return_register_overwrite | verifier_rejected | verifier_rejected | True |
| stack_base_flags | accepted_finding | accepted_finding | True |
| undefined_entry_register | verifier_rejected | verifier_rejected | True |
| undefined_entry_flags | verifier_rejected | verifier_rejected | True |
| helper_clobbered_register | verifier_rejected | verifier_rejected | True |
| scalar_vector_load_clear_high_scalar_store | specialization_rejected | specialization_rejected | True |
| unpaired_stxr_failure_scalar_store | verifier_rejected | verifier_rejected | True |
| unpaired_stlxr_failure_scalar_store | verifier_rejected | verifier_rejected | True |
| paired_stxr_failure_scalar_store | verifier_rejected | verifier_rejected | True |
| paired_stlxr_failure_scalar_store | verifier_rejected | verifier_rejected | True |
| entry_return_address_flags_scalar_store | verifier_rejected | verifier_rejected | True |
| stack_base_flags_scalar_store | verifier_rejected | verifier_rejected | True |

Original negative annotations remain intact and use the original load-only harness path. Four published positives retain their original execution policy. Accepted load-only findings and any setup failure retain the existing suite classification and original diagnostics. Kernel/module/model and native-link build identities are in the parent queued.json; setup-continuation.json records the original producer binary-path alias. Raw records include both startup attempts, all compiler/request outcomes, console and dmesg.
