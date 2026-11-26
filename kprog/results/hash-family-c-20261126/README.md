# Key-size C hash-family calls (P3)

Coordinator assignment 2026-11-26T06:25Z: use header C routines returning the
hash-table element for HASH, LRU_HASH, PERCPU_HASH and HASH_OF_MAPS. Preserve the
LTO value-returning entry and native-link's existing direct-call postprocessing.
The module derives its private layout from the boot kernel BTF at build time;
both loaders select its key-size symbol when present and otherwise retain
`__htab_map_lookup_elem`. The x86 full timing run stays frozen.

The host check reuses the kernel-header oracle and guarded-key/collision/nulls
restart driver, adding an assertion relating the element and value entries.
The offline target reuses the existing whole-stage linker check for both ISAs.
Raw check results and guest logs will be retained here as they complete.

## Offline results

Source 655ae2755: host check passes 1,032 kernel hash oracle cases, 143,388
C/native lookups, one nulls restart, 589 generic calls and 560 same-map alias
cases (`host/report.json`). This reuses the requested LTO driver and its 8- and 16-byte fixture maps;
the guarded driver also covers every key size through 256 bytes. Both element and value returns are checked.

Whole-stage offline links: x86 289/289; arm64 287/289. The two existing arm64
BCC ADR_GOT failures remain (`biosnoop.native.o:block_rq_insert` is the example).
Both architecture loader shared libraries and modules build successfully.
The first module builds report missing prototypes for the exported routines;
the follow-up adds their declarations before the image build.

`run.sh` rebuilds the sole x86 image under the image lock, removes the replaced
image, then runs the unchanged six-app functional target with its default
one 10-second sample. Build concurrency is two; no timing setting changes.

The attempted recursive image dry-run entered the kernel link recipe despite
`make -n` (GNU make executes recursive recipes). Its process group was stopped
before publication; the log stays in `image-dry-run.log`. The normal image
build below replaces any partial build output in the canonical base.

## Corpus key-size census

The staged x86 objects' DWARF map declarations contain hash-family keys of
2, 4, 8, 12, 14, 16, 20, 24, 32, 36, 38, 40, 41, 48, 64, 88, 224, 256 and
260 bytes (`key-sizes.json`, with each map and object). The module now emits
exactly these 19 routines instead of 66; 88 and 260 were absent from the first
set. The first image build was stopped before publication to include these
sizes in the one guest confirmation. Its raw log is `image-first.log`.
The guarded host driver is extended through 260 bytes for this actual corpus
boundary. The first census attempts exposed pointer-width and section-symbol
handling gaps in the census script; both failed logs are retained.

The loader-selection fixture invokes each production loader's selection code
for all four map types, with specialized, zero and absent symbols. Its first
missing-generic test accidentally cleared the initialized cache and caused a
real kallsyms reread; retaining an unrelated sentinel tests the intended missing
symbol case. `loader-selection-first.log` preserves that fixture failure.
