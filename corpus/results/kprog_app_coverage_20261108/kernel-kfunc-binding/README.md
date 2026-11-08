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

The complete matching kernel-module bundle now builds, installs and runs depmod successfully: 842modules for7.0.0-rc2+. Each module hash and the kernel BTF/image hashes reconcile. `matched-modules.tar.gz` preserves all module identities, exact build/install commands and output. The debug-rich runtime payload remains in the private source epoch; compact standard strip/sign module packaging follows as a separate receipt. The corrected Cilium image replaces `/artifacts/lib/modules`; the standard runtime installs and binds that module tree for the original upstream app.

The completed `compact-modules.tar.gz` contains the deployable842-module tree and exact strip/sign/depmod commands. Every SHF_ALLOC section, BTF section, module identity/version field and normalized runtime relocation matches the original signed module. Standard `INSTALL_MOD_STRIP=1` followed by normal kernel module signing reduces the installed module bytes from1562052954 to120223042. Both original and compact SHA lists remain in the archive.

The runtime uses the exact validated image/config/System.map and842compact-module links in `runtime-kernel.tar.gz`, with the matching module payload in `compact-modules.tar.gz`. VNG dry runs complete before and after retiring the duplicate9.51GB logical private guard build. The retirement receipt records `/proc` open-reference checks, image equality and preserved source/build/native-module/BTF archives. The canonical shared x86 warm build and lane A guard cache remain available for incremental builds. Successor commands select `kernel-kfunc-binding/runtime-kernel` as KDIR.
