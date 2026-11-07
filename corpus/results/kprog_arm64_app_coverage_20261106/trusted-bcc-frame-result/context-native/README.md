# Native XDP field reads and exact context identity

This frozen private candidate keeps actual XDP context identity for ordinary stores and buffer helpers. Native data, data_end and data_meta pointer fields are projected to their typed BPF fields through an opaque64-bit result. Partial native pointer-field reads scalarize the exact pointer bits before the source-width shift/mask. Other native reads retain their original base, displacement and width and reach the verifier as real accesses. There is no compile-error callback, new return, trap, fuel or native bounds guard.

The existing compact ghost-payload analysis is unchanged. The exact real Katran native request that previously failed at13 compiler diagnostics now compiles. The earlier precise compiler artifact has maximum fp offset408; that artifact precedes the final signed offsetof displacement correction. Actual compilation of the final frozen header in the guest remains pending. Four final native compiler probes check data/end high32 reads, the data_meta word and a load-only out-of-object read. They retain exact field load offsets0/4/8/4096 and explicit pointer-bit scalarization. LLVM implements high32-nonzero as an unsigned64 comparison with2^32. The earlier overly-specific shift assertion and unsigned-offset pointer-add assertion failures are archived separately; neither reached a guest.

All original34 safety inputs and original8 context inputs are retained (one identical control is shared), plus four native field-access cases:45 total,8 positive and37 negative. Unsafe cases are load-only. The frozen input archive contains the native ELFs/manifests, source pins, exact analysis/header/dependencies, generated C/BPF/compiler metadata and raw compiler logs. inputs.tar.gz SHA256 is recorded in compiler.json.

The common service and kernel-owned request broker are unchanged; the privileged bootstrap selects only this private worker. Applications submit native bytes. The unchanged KatranRunner and safety harness run via:

    make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-context-memory-safety-run
    make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-context-memory-katran-run

A2GiB/two-vCPU safety guest and8GiB/eight-vCPU Katran guest run concurrently within lane A's12GiB budget on host CPUs20-23. They reuse the retained root/kernel/module/loader and caches; QEMU numbers are functional only. Collect each complete archive, actual request outcomes and unchanged-input receipts before a verifier or application claim. The production header remains900422f7c; no candidate promotion or whole semantic-refinement result is claimed here.

The first safety replay (2026-11-07 14:59 UTC) stopped before any of its45 cases: nested bootstrap forwarding passed `service` twice, and argparse refused the command. This is a harness startup failure, not a native-program rejection or a safety pass. The complete raw archive `trusted-arm64-service-result/run-20261107T145906541157Z.tar.gz` has SHA256 `93e9c2df86dc7afebd9b5985b9e10d4919d1de3bb0c44175ec45f1cb3936397a`; `startup-failure-summary.json` preserves the original input hashes and zero-case outcome. The idempotent argument-routing repair is published in6ec355bd3. The frozen Katran bootstrap keeps its original bytes until that active run closes.

The45-case safety replay now runs independently through a temporary bootstrap and the existing Make target with `HERE=kprog/arm64/build/trusted-transport/context-memory-read` (use the absolute path recorded in the archive). It reuses the unchanged native-only safety harness, common service, worker, kernel/module/loader and all45 native ELF identities. The initial temporary bootstrap also stopped before cases because it looked for `subprocess` on a wrapper module; its complete closed failure is preserved, and the corrected bootstrap passed a full recording-launcher check before starting. `parallel-safety-bootstrap.tar.gz` (SHA256 `5b17a8bcc78ac6cfd3b5b4b409432295edf330e4daf4a1aef86024f853b3952a`) retains both bootstrap attempts, exact inputs/commands and the closed failure archive. The safety replay used2GiB alongside the8GiB Katran guest, initially both on20-23. The former queued duplicate safety replay was retired while waiting; the sole source-sync continuation restores the published bootstrap after both jobs close. Neither startup failure counts as a native rejection or accepted program. The completed safety outcome is recorded below; Katran remains in progress.

## Current ARM kernel field layout

`current-arm64-xdp-layout.json` pins the kernel Image/module used by both active guests, its matching vmlinux BuildID `141aad6ee6f5385be65475cc2f99aac9aec12698`, the candidate header and actual compiled type layouts. `data`, `data_end` and `data_meta` occupy BPF context offsets0/4/8 (four bytes) and native `xdp_buff` offsets0/8/16 (eight bytes). The archived converter disassembly emits opcode0x79 (64-bit LDX) at those native offsets, preserving the source register byte and returning one instruction. All388 converter-function bytes from vmlinux match the raw guest Image at offset13087304. This supports the candidate's opaque64-bit field projection.

`current-arm64-xdp-layout.tar.gz` retains pahole output, kernel ELF identity, exact conversion bytes/disassembly, current source access/conversion branches, hashes and commands. It supplies current ARM platform facts to T/V; it does not prove arbitrary compiler semantics, capture live converted proof instructions or establish complete application/safety acceptance. No running input was modified.

## Host CPU affinity during the live run

The Katran launch argv records CPUs20-23. At2026-11-07T15:33:00.710499+00:00 its existing QEMU process2486232 and all14 observed threads moved to CPUs8-11, which were less busy in the recorded one-second host sample. The safety guest remains on20-23. `host-affinity-migration.json` records every thread before/after and is also inside the live Katran output so its final archive preserves the actual placement. Both CPU sets are within lane A's8-23 allocation; the guest,8GiB memory and all213 frozen inputs were preserved. This is resource coordination for functional progress, not a performance measurement.

## Completed native-only safety replay, 2026-11-07

The frozen context/compact worker completed all45 original inputs:8 matching kernel/native executions,23 verifier refusals,13 specialization refusals and1 loader refusal. All8 positives returned2 with nonzero binding generations; all37 negative commands were load-only, with zero accepted unsafe programs and zero unsafe execution. An independent reread of the complete archive checked every input/receipt/kernel native hash, each available generated native copy, all8 result/generation receipts and the exact four-path published commit.

[Complete raw run and outcomes](trusted-arm64-service-result/README.md), [native identity audit](trusted-arm64-service-result/native-identity-audit.json) and [host summary](trusted-arm64-service-result/summary.json) are published in c3da19c4f. This establishes the recorded examples for the private worker. Canonical producer promotion, the still-running actual Katran workload and all-six-application acceptance remain open.

## Canonical integration after the closed Katran run

Katran completed through the native-only kernel service: one proof accepted and
bound, program15 executed19,391 times. The unchanged packet workload sent19,391
packets with0 errors; VIP, TX and real1 counters also increased19,391. Full raw
counters are in `canonical-integration/katran-work-counters.json`; QEMU timing is
functional only. The closed archive and native identity audit remain in
`trusted-arm64-katran-result/` (commit4b3d09c55).

The compact payload analysis and exact native-width XDP reads are now integrated
in the canonical ARM header/ABI analysis/generator. No candidate adapter is used
by the production worker. Re-rendering all46 archived safety/Katran requests gave
33 byte-identical preprocessed C outputs and the same13 specialization refusals.
The real BCC tcplife canonical compile uses352 frame bytes, with executable BPF
sections and executable relocations identical to the accepted private candidate's
host preflight. See `canonical-integration/source-audit.json` and `inputs.tar.gz`
for source pins, comparison code, compiler artifacts and logs. This establishes
these exact artifact comparisons; a new canonical BCC guest run and all-six-app
acceptance remain pending. Existing dated candidate scripts/archives describe the
historical private replay; the supported producer is `kprog/arm64/trusted_specializer.py`.
