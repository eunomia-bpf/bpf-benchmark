# Readonly identity increment

The x86 producer now emits a separate BTF DATASEC/map for each private native
readonly object, with the same version1 identity section used by lane A.
Native-link emits the exact final whole-object offsets for both x86 and AArch64.
Neither repeated instruction references nor identical bytes merge identities.
Relocation addends remain instruction-specific.

Validation completed:

- Both actual ELF→proof→kernel CLI regressions preserve two equal 120-byte
  objects, originally at nonzero section offsets, as distinct final objects.
  The three actual address-forming instructions resolve to object_a+7,
  object_b+48 and object_a+80. The x86 proof contains two separate whole-map
  BTF variables and exact native-symbol metadata.
- All67 Rust tests pass; negative proof compilation and all29 positive micro
  proofs compile. The immutable full formal check passes. Its base is
  `178e6e84e` with the previously checked lane C overlays through `7123cfddd`,
  plus only the current x86 renderer and two native-link files. It includes no
  other lane's uncommitted changes. No ISA transition changed in this increment.
- Fresh BCC phase11 snapshots all native ELF files before entry selection,
  finds actual full entry symbols in those ELF symbol tables, and generates
  each canonical proof from that same copied native object. All25 resident
  entries generate and compile;23 pass an actual verifier load. Two fail
  during upstream stack-trace-map preparation (`max_entries=0`), before the
  verifier. No verifier rejection occurs in this25-entry run. The runtime
  loader must bind those maps to the actual original FD's configured layout;
  this standalone diagnostic does not yet do that.

| Actual application | Successful startup loads | Resident programs | Resident proofs generated / compiled | Verifier accepted | Specialization failures in this run | Preparation failures | Verifier rejected |
| --- | ---: | ---: | --- | ---: | --- | --- | ---: |
| BCC | 77 | 25 | 25 / 25 | 23 | 0 of25 tested | 2: unconfigured stack-map capacity | 0 |
| OTel | 16 | 13 | pending actual-load pairing | pending | pending | pending | pending |
| Cilium | 210 | 92 | pending actual-load pairing | pending | pending | pending | pending |
| Tetragon | 308 | 81 | pending actual-load pairing | pending | pending | pending | pending |
| Katran | 6 | 1 | pending actual-load pairing | pending | pending | pending | pending |
| Tracee | 162 | 151 | pending actual-load pairing | pending | pending | pending | pending |

The successful-load denominator includes transient startup probes. They remain
required work, alongside all resident programs. These verifier diagnostics
are not generation-bound app execution or matching-work timing results.
The1,136-artifact diagnostic census is a separate population, including
internal functions and alternate versions; its readonly rerun is retained
independently. No failing program is excluded from the application goal.

Commands from the repository root:

```sh
make -f corpus/results/kprog_app_coverage_20261106/readonly-layout.mk build test
make -f corpus/results/kprog_app_coverage_20261106/readonly-layout.mk formal micro
make -f corpus/results/kprog_app_coverage_20261106/Makefile bcc-real-generate PHASE=bcc-real-11
make -f corpus/results/kprog_app_coverage_20261106/Makefile bcc-real-compile PHASE=bcc-real-11
make -f corpus/results/kprog_app_coverage_20261106/readonly-layout.mk bcc-verify
make -f corpus/results/kprog_app_coverage_20261106/readonly-layout.mk census
```

`readonly-artifacts.tar.gz` retains fixture sources/ELFs/blobs/layouts, raw
commands, micro compile reports, BCC phase11 snapshots, manifests, full
compiler/verifier logs and the frozen formal/generator sources (without
build caches). Top-level raw invocation logs are stored separately. Lane T
owns the loader consumer and its actual bound-kernel identity checks.
