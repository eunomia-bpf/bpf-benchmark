# Offline CO-RE measurement

`make -r -f kprog/test/core-audit.mk mechanism-check OUTPUT=/workspaces/kprog-raw/perf/NAME`
checks actual ELF records and libbpf instruction patches for all thirteen
relocation kinds. It also tests that incorrect native constants remain
different despite correct DWARF, and missing observations remain unobserved.
No BPF program is loaded and no production IR is rewritten.

For rebuilt application objects, supply an explicit inventory:

```json
[
  {
    "app": "tracee",
    "object": "tracee.native.o",
    "source": "/actual/source/tracee.bpf.o",
    "native": "/actual/product/tracee.native.o",
    "observations": "/workspaces/kprog-raw/perf/NAME/tracee-observations.json",
    "native_layout": true
  }
]
```

Run `make -r -f kprog/test/core-audit.mk audit OUTPUT=/workspaces/kprog-raw/perf/NAME AUDIT_ARGS='--inventory /actual/inventory.json'`.
The default target is the sole canonical boot ELF. `TARGET=` can identify a
recorded BTF input; its exact SHA256 is retained. Source/native hashes also
enter every object summary. Omit `observations` when none have been measured;
`native_layout` requests a separate DWARF comparison, with one canonical
detached-BTF build product reused sequentially.

An observation witness contains measured native answers, bound to the exact
source/native bytes. It is not a copy of the reference's expected answers:

```json
{
  "source_sha256": "SOURCE_ELF_SHA256",
  "native_sha256": "NATIVE_ELF_SHA256",
  "answers": [
    {"local_type_id": 123, "kind": 0, "access": "0:1", "value": 16, "poison": false}
  ]
}
```

`value` is the unsigned 64-bit bit pattern; `poison` records whether native
execution rejects the unsupported access. Keep the observation method and
commands beside the witness. A generated header manifest alone describes
intended constants; observe the native output or a compiled witness from its
actual definitions before using it to claim final code agreement. The audit
does not synthesize answers from old compatibility policies, compiler reports,
or DWARF. Source-local type IDs and access strings come from the actual BPF
object's CO-RE records (`reference` target or each object's `kernel.tsv`).

Differences and missing observations are measurement rows, not admission
checks; they do not prevent compilation, loading, timing or queue progress.
Malformed input, command failures and mismatched witness hashes are errors.
Retired IR-compiler targets and their tests are deleted; historical results
remain in `kprog/results/perf_20261113/core-audit` and `core-zero-compare`.
