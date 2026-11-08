Original kernel resource type preservation

Same clang18/source/header, isolated function object emits FWD prog_test_ref_kfunc/prog_test_member; original complete map_kptr_fail.c object emits STRUCT sizes32/8 and kptr tags target those complete ids.

Current, upstream-alias flags, standalone-debug and retain-unused-debug variants all keep the isolated forward declarations; the complete original file preserves the structures. Every command, object, raw diagnostic and header is archived.

btf_find_kptr at kernel/bpf/btf.c3523 returns EINVAL for a forward pointee. map_check_btf stores btf_parse_fields result; IS_ERR records pass btf_check_and_fixup_fields4213 with result0, array_map_check_btf551 checks key shape, and btf_record_has_field/btf_record_find treat IS_ERR as absent fields. This source path explains why a map retains BTF id/value id while kptr slot rules disappear for isolated objects. Fresh whole-object QEMU replay will supply its actual map/verifier outcomes.

Keep the original complete BPF translation unit for resource/BTF/program context; native C entries retain isolated compilation. Reuse one resource object for all native entries from that source file. Existing autoloadfalse producer selects its named context and loads maps/BTF only.

The six historical installed annotation outcomes retain their original stage. In misaligned_access_read, native compilation additionally narrows the source u64 read to a four-byte int-result read wholly inside buf; P/B both retain that four-byte operation. Annotation expectation versus the actual native access remains explicit. Runtime admission additions:0.
