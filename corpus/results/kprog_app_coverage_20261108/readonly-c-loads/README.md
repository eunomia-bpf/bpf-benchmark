# Generic C representation of immutable native reads

The x86 generator emits finite C offset/width cases for each declared immutable native object. Each case copies the original bytes with fixed-size `__builtin_memcpy`; Python supplies the object, offset and width. The compile-time base choice selects the object representation. Every remaining address executes the original raw memory load. Existing instruction expansion, architectural registers, flags and native branches retain their meanings.

The ordinary simulator memory-load route exposes this representation through `X86_SIM_L_NATIVE_DATA_LOAD`. The shared C and generic generator supply the same mechanism to every generated program. The earlier complete Tracee experiment retains6generated/6compiled/5installed and advances the length frontier to the subsequent map destination range; its native-input and raw work records remain in [the original cohort](../readonly-values/whole-tracee/README.md).

| Measurement | Result |
| --- | --- |
| Generic byte-copy host observations, UBSan | 18,650reads;0differences |
| Existing specialization and memory-access source contracts | both check0 |
| Captured whole Tracee C-copy compilation | make0 |
| Existing29positive+1negative-native micro compiler batch | 30rows;make0 |

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/readonly-values/adoption/Makefile host source component micro
```

`observations.json` records source and executable-section identities and the measured comparison with the earlier experimental rendering. `compiler.tar.gz` retains all commands, source snapshots, raw compiler output and objects. The byte observations include all four widths, unaligned starts, shifted aliases, distinct objects, mutable memory and accessible bytes beyond the immutable extent. The new whole original Tracee application runs from its frozen generic generator/header/linker snapshot and retains its terminal records separately. V owns the universal immutable-object read and O2/O4 composition; these compiler and application measurements retain their measured domains.

The initial whole generic-source setup receipt retains its helper API path error under [whole-tracee](whole-tracee/README.md). The copied service now has the exact vendored helper declaration file at its own relative lookup path, and its parser reads211helpers including105/163. `source-inputs.json` and `source-inputs.tar.gz` identify the added file and corrected full-application launch. Native7479850e, the model, generator, kernel and workload keep their captured values; the successor uses a fresh broker directory.
