# Corpus BPF Runtime Performance Results

- Generated: 2026-03-10T20:33:53.710064+00:00
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Dummy packet: `/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/corpus_dummy_packet_64.bin`
- Dummy context: `/home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/corpus_dummy_context_64.bin`
- Corpus source: expanded build report `/home/yunwei37/workspace/bpf-benchmark/corpus/results/expanded_corpus_build.json`
- Corpus BPF objects discovered: 429
- Skipped non-BPF `.bpf.o` artifacts: 0
- Programs found: 4
- Loadable programs: 1
- Baseline-runnable programs: 1
- Recompile-runnable programs: 1
- Paired baseline/recompile measurements: 1
- Directive-bearing loadable programs: 0
- Directive-bearing paired programs: 0
- Correctness mismatches: 0
- Speedup geomean (baseline/recompile): 0.958x
- Speedup median (baseline/recompile): 0.958x

## Summary Statistics

| Metric | Value |
| --- | --- |
| CMOV sites | 0 |
| WIDE sites | 0 |
| ROTATE sites | 0 |
| LEA sites | 0 |
| Speedup min | 0.958x |
| Speedup max | 0.958x |

## Runnable Programs

| Program | Section | Baseline ns | Recompile ns | Speedup | Applied | Correct | CMOV | WIDE | ROTATE | LEA |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/libbpf-bootstrap/examples/c/tc.bpf.o:tc_ingress | tc | 23 | 24 | 0.958x | no | match | 0 | 0 | 0 | 0 |

## Load Failures

| Program | Section | Failure |
| --- | --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/async_stack_depth.bpf.o:async_call_root_check | tc | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/async_stack_depth.bpf.o:pseudo_call_check | tc | bpf_object__load failed: Permission denied (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cb_refs.bpf.o:underflow_prog | tc | bpf_object__load failed: Invalid argument (exit=1) |

## Top Failure Reasons

| Reason | Count |
| --- | --- |
| bpf_object__load failed: Permission denied (exit=1) | 2 |
| bpf_object__load failed: Invalid argument (exit=1) | 1 |

## Inventory Failures

| Object | Failure |
| --- | --- |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_dim.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_dim.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_val_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___diff_arr_val_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___equiv_zero_sz_arr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___equiv_zero_sz_arr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_signed_arr_elem_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_signed_arr_elem_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_zero_sz_arr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_bad_zero_sz_arr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_non_array.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_non_array.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_shallow.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_shallow.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_small.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_too_small.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_wrong_val_type.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___err_wrong_val_type.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___fixed_arr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_arrays___fixed_arr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___bit_sz_change.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___bit_sz_change.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___bitfield_vs_int.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___bitfield_vs_int.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___err_too_big_bitfield.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___err_too_big_bitfield.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___just_big_enough.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_bitfields___just_big_enough.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___diff.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___diff.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___err_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___err_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___val3_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enum64val___val3_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___diff.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___diff.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___err_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___err_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___val3_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_enumval___val3_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence___minimal.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence___minimal.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence___wrong_field_defs.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_existence___wrong_field_defs.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_flavors.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_flavors.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_flavors__err_wrong_name.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_flavors__err_wrong_name.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints___bool.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints___bool.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints___reverse_sign.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ints___reverse_sign.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_misc.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_misc.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods___mod_swap.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods___mod_swap.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods___typedefs.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_mods___typedefs.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___anon_embed.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___anon_embed.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___dup_compat_types.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___dup_compat_types.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_array_container.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_array_container.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_array_field.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_array_field.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_dup_incompat_types.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_dup_incompat_types.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_missing_container.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_missing_container.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_missing_field.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_missing_field.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_nonstruct_container.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_nonstruct_container.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_partial_match_dups.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_partial_match_dups.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_too_deep.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___err_too_deep.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___extra_nesting.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___extra_nesting.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___struct_union_mixup.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_nesting___struct_union_mixup.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_enum_def.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_enum_def.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_func_proto.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_func_proto.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_ptr_type.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___diff_ptr_type.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_enum.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_enum.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_int.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_int.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_ptr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_primitives___err_non_ptr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ptr_as_arr.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ptr_as_arr.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ptr_as_arr___diff_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_ptr_as_arr___diff_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___diff_offs.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___diff_offs.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___diff_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___diff_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___err_ambiguous.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_size___err_ambiguous.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___all_missing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___all_missing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___diff.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___diff.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___diff_sz.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___diff_sz.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___fn_wrong_args.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___fn_wrong_args.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___incompat.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_based___incompat.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_id.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_id.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_id___missing_targets.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf__core_reloc_type_id___missing_targets.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_data.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_data.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_bitfields.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_bitfields.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_multidim.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_multidim.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_namespacing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_namespacing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_ordering.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_ordering.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_packing.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_packing.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_padding.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_padding.bpf.o (exit=1) |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_syntax.bpf.o | no program found in object: /home/yunwei37/workspace/bpf-benchmark/corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/btf_dump_test_case_syntax.bpf.o (exit=1) |

## Notes

- Discovery reuses `micro/directive_census.py` filtering, so only `EM_BPF` corpus objects are executed.
- Execution uses the existing `micro_exec run-kernel` path with `bpf_prog_test_run_opts` and scanner-backed `--recompile-all`.
- Non-runnable programs are expected in this corpus. The harness records load-only success separately from full runtime success.
- Packet programs use the synthetic 64-byte Ethernet/IPv4/TCP packet, while non-packet programs use `context` mode with empty or zero-filled `ctx_in`.

