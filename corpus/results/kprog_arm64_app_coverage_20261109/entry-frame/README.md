AArch64 fixed entry frame

The two-condition kernel patch selects the existing full-callee save/restore path for native P. X19-X28 occupy five aligned pairs; X29 uses the existing FP/LR frame record. B checks its entry SP at RET. ARM native compilation uses the original branch flags. The existing stock-entry-frame linker feature emits matching five-pair tail cleanup and its native JIT stack extent.

The incremental ARM Image builds successfully against the retained kinsn-free CK source. The existing tail tests pass19/19 under each feature selection; the release linker builds successfully. result.json records the Image and patch identities. The Image is retained at /var/tmp/kprog-tmp/A/entry-frame/Image. kernel-raw.tar.gz retains the compiler input recipe and complete build/test diagnostics. The shared source tree and index retain peer work. Native execution requests:0.
