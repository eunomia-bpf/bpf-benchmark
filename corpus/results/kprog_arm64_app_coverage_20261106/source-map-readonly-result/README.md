# Mixed original source maps and private readonly data

The actual OTel read_task_struct simulator failed because its source-site
externs coexist with private readonly string relocations. The raw source-map
loader previously required every relocation to be a strong extern.

The loader now creates/fills/freezes only readonly single-value data maps
whose ELF section and BTF DATASEC match. Source extern identity checks remain.
Existing raw-map binding then checks complete variable identity, native extent
and every readonly byte before native admission; no name/byte-search fallback
or checker bypass is introduced.

The real five-instruction source-map fixture now has an equivalent native
load from private readonly value42. In full-system QEMU source and bound
native write42 at offset16, preserve neighboring bytes and preserve original
map contents during binding, with one nonzero generation. The wrong source
offset proof rejects at load; changing the private readonly bytes rejects
before execution with `readonly proof data does not match native bytes`.
Both ARM static/shared library builds pass. Raw failed fixture generationv1,
positivev2, and positive+both negativesv3 remain. The first fixture used a
public constant not recognized by the generator; the private constant version
exercises the section-relative readonly form present in actual OTel.

Extract replay.tar.gz and run `make -C runtime run`; on Spark use
`make -C runtime run ACCEL=kvm CPU=host`. The archive retains compiled triples,
exact library source, simulator snapshot, kernel and initrd. Rebuild using the
dated Makefile: runtime-loader-build, source-map-arm64-build and
source-map-arm64-check with PHASE=NEW_NAME SOURCE_MAP_ARGS=readonly.

Actual six-application runtimev11 is started separately using the new library.
Its completion is still pending; this regression is not six-app coverage.
