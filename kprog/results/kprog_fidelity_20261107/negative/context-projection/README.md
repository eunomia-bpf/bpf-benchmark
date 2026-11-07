# Native-only ordinary context-store projection check

This isolates the existing context-effect finding from memory-intrinsic
admission. One unchanged return2 control and one native context-field store
are submitted through the shared registered specializer service per ISA.
The negative is strictly load-only; only the control may execute. The same
existing harness, companion contexts and producer binaries are reused. The
original34 ARM fixtures, manifests, running guest and production files stay
unchanged. The ARM specializer uses F's corrected private return linker.

Commands use the existing KVM kernel/module or A's unchanged ARM transport:

```sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/negative/context-projection/Makefile build-x86 kvm
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/negative/context-projection/Makefile build-arm64 qemu
```

Builds and receipts are pending. Acceptance is a finding, never a test pass;
all exact messages and native identities remain in the shared harness outputs.
No module admission rule is relaxed and no runtime shadow-write fix is claimed.

The first x86 positive control stopped before proof compilation because the
guest PATH lacked `clang`. This is a setup failure, not a safety rejection;
its full outputs are preserved in `x86-setup-failure.tar.gz`. The runner now
exports the existing `/usr/lib/llvm-18/bin` path, matching the established ARM
transport. Retrying uses the identical native/context/producer bytes and does
not rebuild a kernel, module, image or library.

The corrected x86 KVM run confirms an **accepted ordinary-context-store
finding** on the unchanged production module policy. The return2 control
executed with correct kernel and bound result0/retval2. The negative obtained
a bound program with nonzero generation, but used the producer's argc3
LOAD-ONLY mode and never reached TEST_RUN. `x86-summary.json` records the
native ELF and accepted-request hashes; compressed outcomes retain the exact
messages. `x86-accepted-context-store.tar.gz` includes complete request archives,
proof objects/C/linker outputs, commands, stdout/stderr and native/probe/context
input bytes. This result requires no memory-intrinsic admission exception and
confirms that the context-shadow issue affects an ordinary store. The guest
exit2 is the harness correctly surfacing that finding, not a safety-suite pass.
Production projection repair remains open; no code or admission rule was
weakened. ARM evidence is still pending.

The corresponding ARM full-system QEMU check also confirms an **accepted
ordinary-context-store finding**. Its return2 control executes correctly in
the original kernel and fresh bound native path; the negative obtains a
nonzero-generation bound program in LOAD-ONLY mode and is never executed.
`arm64-summary.json` retains the host/guest exits and unchanged source pins;
compressed outcomes retain exact messages/native identities. The untouched
host archive is `arm64/trusted-arm64-service-result/run-20261107T123409304825Z.tar.gz`;
`arm64-inputs.tar.gz` preserves the native/probe/context input bytes. This uses
F's corrected return-target linker, so it is a separate context-effect defect.

The paired native/proof disassemblies show the concrete representation gap:
the native store targets the entry context, while the proof store targets its
private stack ABI object. The x86 proof retains the store (at instruction13)
rather than optimizing it away; its destination derives from R10-40. No
corresponding store reaches the external context. This narrows the required
repair to context-effect projection, not a blanket relaxation of binding or
helper rules. C/A own the ISA implementations and F retains these regressions.
The original34-case ARM replay remains separate and active; these findings
prevent a simulator-wide safety claim even if those original34 later pass.

## Production ARM XDP repair regression

The independent F replay of production repair `b2b6f28d9` completed on
2026-11-07: the unchanged return2 control executes correctly through kernel
and fresh bound native paths, and the original ordinary context store is
verifier-rejected with `invalid bpf_context access off=0 size=8`. There are
zero accepted negatives and no unsafe execution; guest and QEMU exits are0.
The prior accepted finding above remains retained as pre-repair evidence.

`arm64/arm64-production-summary.json` records both exact native identities,
request IDs, kernel-captured native hashes, source pins and diagnostic.
`arm64/arm64-production-outcomes.json.gz` retains complete messages. The
unchanged original transport archive is
`arm64/trusted-arm64-service-result/run-20261107T134405557846Z.tar.gz`
(SHA256 `4a84ec99d036e4b6da02d14db8f7b714996f878e247eca5aea0b99f22b8f8f13`).
Both requests use the published production header, all request source pins
agree, and host input hashes are unchanged. No kernel, module, image, loader
or native input was rebuilt. The command was
`taskset -c 20-23 make -f kprog/results/kprog_fidelity_20261107/negative/context-projection/Makefile qemu`.
The separate complete34-case production replay is running; this two-case
result does not establish that replay, SKB projection or universal ABI safety.
