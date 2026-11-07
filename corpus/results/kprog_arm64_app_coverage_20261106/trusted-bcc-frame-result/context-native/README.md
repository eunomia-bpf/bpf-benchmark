# Native XDP field reads and exact context identity

This frozen private candidate keeps actual XDP context identity for ordinary stores and buffer helpers. Native data, data_end and data_meta pointer fields are projected to their typed BPF fields through an opaque64-bit result. Partial native pointer-field reads scalarize the exact pointer bits before the source-width shift/mask. Other native reads retain their original base, displacement and width and reach the verifier as real accesses. There is no compile-error callback, new return, trap, fuel or native bounds guard.

The existing compact ghost-payload analysis is unchanged. The exact real Katran native request that previously failed at13 compiler diagnostics now compiles. The earlier precise compiler artifact has maximum fp offset408; that artifact precedes the final signed offsetof displacement correction. Actual compilation of the final frozen header in the guest remains pending. Four final native compiler probes check data/end high32 reads, the data_meta word and a load-only out-of-object read. They retain exact field load offsets0/4/8/4096 and explicit pointer-bit scalarization. LLVM implements high32-nonzero as an unsigned64 comparison with2^32. The earlier overly-specific shift assertion and unsigned-offset pointer-add assertion failures are archived separately; neither reached a guest.

All original34 safety inputs and original8 context inputs are retained (one identical control is shared), plus four native field-access cases:45 total,8 positive and37 negative. Unsafe cases are load-only. The frozen input archive contains the native ELFs/manifests, source pins, exact analysis/header/dependencies, generated C/BPF/compiler metadata and raw compiler logs. inputs.tar.gz SHA256 is recorded in compiler.json.

The common service and kernel-owned request broker are unchanged; the privileged bootstrap selects only this private worker. Applications submit native bytes. The unchanged KatranRunner and safety harness run via:

    make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-context-memory-safety-run
    make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-context-memory-katran-run

A2GiB/two-vCPU safety guest and8GiB/eight-vCPU Katran guest run concurrently within lane A's12GiB budget on host CPUs20-23. They reuse the retained root/kernel/module/loader and caches; QEMU numbers are functional only. Collect each complete archive, actual request outcomes and unchanged-input receipts before a verifier or application claim. The production header remains900422f7c; no candidate promotion or whole semantic-refinement result is claimed here.
