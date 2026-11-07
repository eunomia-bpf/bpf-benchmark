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
