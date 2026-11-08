# Canonical vmlinux kfunc identity in native proof regions

The common kernel patch admits canonical resolved-vmlinux kfunc calls in authenticated native proof regions alongside the existing helper route. The kfunc arm requires code0x85, source2, destination0, offset0 and a positive BTF ID. Ordinary verifier BTF/type/effect admission follows region expansion. The existing helper route and other pseudo-call refusals retain their behavior.

The exact source-extracted predicate agrees with an independent field classifier across25600ASan/UBSan controls: both native-proof states, two jump classes, all16source/destination registers, five offset boundaries and five immediate boundaries. Positive canonical kfunc and unauthenticated controls are explicit. Patch format parsing succeeds.

```sh
bash /workspaces/.agent-state/kprog-lanes/C/kernel-kfunc-binding/check.sh
bash /workspaces/.agent-state/kprog-lanes/C/kernel-kfunc-binding/build.sh
```

The classifier archive captures exact before/candidate patch, extracted predicate, controls/binary/output, original/candidate verifier source, input identities and private build scripts. A detached warm source/output copy builds the x86 kernel and module at20-23/j4. Existing shared source/output trees and active guest images retain their captured bytes. Kernel build and whole Cilium runtime outcomes receive their completed receipts.
