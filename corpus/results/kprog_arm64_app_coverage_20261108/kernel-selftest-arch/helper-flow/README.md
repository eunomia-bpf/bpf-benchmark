ARM contextual helper resolution

The original five native-link coverage failures are replayed with the current shared helper-id table, an incremental ARM native-link build and the existing contextual helper alias for check_mtu. BPF_FUNC_check_mtu now participates in that existing contextual set. All builds reuse the retained warm cache.

Five original native inputs generate and compile B. tcx2/tcx3/tcx5/tcx6 install; tc_uninit_mtu reaches the stock verifier and receives an uninitialized-stack R3 fp-4 refusal at helper163. The original client warmup TEST_RUN EINVAL for the four installed programs remains a separate execution stage. summary.json preserves the historical linker errors and actual terminal stages; contextual/trusted-arm64-service-result retains every P/C/B, linker plan and verifier stream.

tc_uninit_mtu source/native/helper model pass the raw fp-4 output address. The native-proof branch in lower_kinsn_proof_regions forces env->allow_uninit_stack=false (verifier.c3744), while stock privileged entry initializes it through bpf_allow_uninit_stack(token). The annotation __success and __failure_unpriv express that privilege policy. C owns the shared patch; the exact policy difference is posted for priority1 removal review.

The full direct-source0 ARM catalog captures these same refreshed helper inputs. Runtime admission additions:0.
