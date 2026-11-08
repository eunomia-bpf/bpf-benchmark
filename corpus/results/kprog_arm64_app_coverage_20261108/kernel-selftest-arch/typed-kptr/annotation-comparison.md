Original ARM kptr annotations with complete resources

The20-row original annotation component has19native entries. All19submit at source0;11reach stock-verifier rejection,1installs and7retain generation coverage. Resource failures0. Every source and safety case retains its published bytes.

| Historical installed input | Current stage | Same allocated native sections | Actual verifier class |
| --- | --- | --- | --- |
| size_not_bpf_dw | verifier_rejected | True | kptr access size must be BPF_DW |
| misaligned_access_write | verifier_rejected | True | kptr access misaligned expected=8 off=7 |
| misaligned_access_read | installed | True | Native P/B read32 at offset1, inside buf[8]; the original BPF annotation describes read64 at offset1 touching the kptr byte8. |
| reject_bad_type_match | verifier_rejected | True | invalid kptr access, R2 type=untrusted_ptr_prog_test_ref_kfunc expected=ptr_prog_test_ref_kfunc or untrusted_ptr_prog_test_ref_kfunc |
| reject_untrusted_store_to_ref | verifier_rejected | True | store to referenced kptr disallowed |
| reject_indirect_global_func_access | verifier_rejected | True | kptr access misaligned expected=8 off=5 |

The remaining installed misaligned_access_read has a four-byte native/P-model read at offset1, covering buf bytes1..4. The original BPF object carries an eight-byte read at offset1, covering bytes1..8 and overlapping the kptr slot. The annotation/native access-range difference remains an explicit finding. Both native and generated B implement the four-byte operation.

The original d0ec installed epoch, source-isolation/BTF observations4713715b6, missing-module epoch62c3925ee and actual paired-module epoch3b9511df2 retain distinct raw archives. All six inputs have equal allocated native sections across the historical/current requests; complete resource metadata restores five original kptr refusals. Helper/external-call generation outcomes retain their original causes in annotation-comparison.json. Runtime predicate/gate/limit additions:0.
