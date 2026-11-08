# Canonical vmlinux kfunc identity in native proof regions

The common kernel patch admits canonical resolved-vmlinux kfunc calls in authenticated native proof regions alongside the existing helper route. The kfunc arm requires code0x85, source2, destination0, offset0 and a positive BTF ID. Ordinary verifier BTF/type/effect admission follows region expansion. The existing helper route and other pseudo-call refusals retain their behavior.

The exact source-extracted predicate agrees with an independent field classifier across25600ASan/UBSan controls: both native-proof states, two jump classes, all16source/destination registers, five offset boundaries and five immediate boundaries. Positive canonical kfunc and unauthenticated controls are explicit. Patch format parsing succeeds.

```sh
bash /workspaces/.agent-state/kprog-lanes/C/kernel-kfunc-binding/check.sh
bash /workspaces/.agent-state/kprog-lanes/C/kernel-kfunc-binding/build.sh
```

The classifier archive captures exact before/candidate patch, extracted predicate, controls/binary/output, original/candidate verifier source, input identities and private build scripts. A detached warm source/output copy builds the x86 kernel and module at20-23/j4. Existing shared source/output trees and active guest images retain their captured bytes. Kernel build and whole Cilium runtime outcomes receive their completed receipts.

The completed x86 build consumes lane A's exact registered-kfunc verifier profile: canonical-field admission, ordinary add_kfunc_desc registration, and GPL/BTF/JIT admission on every ordinary kfunc even with an existing kinsn table. Kernel bzImage and the external module build return0. The private mount namespace keeps canonical compiler paths and binds the private output/source file; the shared kernel image matches its original hash.

The initial duplicated-output build records ENOSPC and an empty exit receipt. Its failed private output/source duplicates were retired. The successful retry preserves sparse files/hardlinks and excludes duplicated installer/final-link artifacts. `registered-kernel-build.tar.gz` captures the exact registered verifier/A patch, configuration, compiler command record, kernel image/BTF, module, hashes, build output and prior resource diagnostic. Whole Cilium runs after current OTel/Tracee and the affected Tetragon retry. Lane A retains common registration-source publication ownership.
