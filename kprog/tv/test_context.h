/* Catch metadata accepted at seal or reinterpreted under another load context. */
static void context_regressions(int original)
{
	const struct native_lab_binding saved = current_context;
	for (unsigned field = 0; field < 8; field++) {
		current_context = saved;
		switch (field) {
		case 0: current_context.prog_flags = BPF_F_TEST_STATE_FREQ; break;
		case 1: current_context.attach_btf_id = 1; break;
		case 2: current_context.attach_btf_obj_id = 1; break;
		case 3: current_context.attach_prog_id = saved.source_prog_id; break;
		case 4: current_context.prog_ifindex = 1; break;
		case 5: current_context.source_prog_id = UINT32_MAX; break;
		case 6: current_context.gpl_compatible = 0; break;
		case 7: current_context.context_reserved = 1; break;
		}
		seal_artifact_expect(native, sizeof(native), &proof, 1, NULL, 0,
			field == 5 ? ENOENT : EINVAL);
		printf("load context field %u mismatch at sealing: PASS (rejected)\n", field);
	}
	current_context = saved;
	int flagged = create_context(BPF_PROG_TYPE_XDP, BPF_F_TEST_STATE_FREQ, "GPL");
	use_context(flagged, BPF_F_TEST_STATE_FREQ);
	seal_single_proof(&proof, 1);
	unsigned id = current_context.source_prog_id;
	if (close(flagged)) fatal("close flagged original");
	int pinned = bpf_prog_get_fd_by_id(id);
	if (pinned < 0) fatal("sealed context did not pin original program");
	if (close(pinned)) fatal("close pinned context lookup");
	load(generation(), 0, 1, "load flags differ before proof lowering");
	stub_load_flags = BPF_F_TEST_STATE_FREQ;
	load(generation(), 0, 0, "exact raw flags and pinned original context");
	stub_load_flags = 0;
	int non_gpl = create_context(BPF_PROG_TYPE_XDP, 0, "BSD");
	use_context(non_gpl, 0);
	seal_single_proof(&proof, 1);
	if (close(non_gpl)) fatal("close non-GPL original");
	load(generation(), 0, 1, "GPL status differs before proof lowering");
	stub_license = "BSD";
	load(generation(), 0, 0, "exact non-GPL original context");
	stub_license = "GPL";
	use_context(original, 0);
}
