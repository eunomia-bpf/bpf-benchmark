# Shared tagged-store body

2026-11-15. Native/memory fixtures2647a9aca; implementation b30e228e0.
The former MOV store default-arm condition required the destination tag to
be STACK before calling STORE_ADDR_TAGGED with STACK. Its other arm passed
the destination tag, so both selected the same argument. One call now serves
both. Register-tag reads are pure; address/value computation, alias erasure,
saved-fact handling, unknown-store clearing and released-stack draws remain
in the same order. No P, source, flag, ISA or benchmark change. All native
LTO stays enabled together and all eligible scalar pairs remain the sole B
backend policy8f48bf443.

Before/after checks use the same native fixture object and normal CLI:

- 16 actual CPU/shared-C store fixtures,512 comparisons in each run, all
  pass. Coverage: immediate/register stores,1/2/4/8-byte widths, flat/indexed
  addressing at nonzero displacement, unaligned addresses, eight value
  patterns and four indices. Each invocation compares the entire128-byte
  memory image and CF/ZF/SF/OF; the8-byte immediate covers sign extension.
- All16 fixture programs compile through the normal B pipeline. Their
  allocated section sets are byte-identical before/after. Full ELF debug
  information may change. This is compilation/equivalence subset evidence,
  not kernel verification or actual application acceptance.
- Independent store byte-model oracle passes1,292,621 checks before/after;
  load713, stack117,782 and the explicit-input pointer/RSP/recovery14 also
  pass. The combined target still exits2 because the old helper-output
  lifetime oracle references removed X86_SIM_L_HELPER_WRITE_ARG_PTR and fails
  to link before/after. That failure is retained, not counted as a pass or
  removed from this result.

Same current OTel perf_unwind_hotspot/type7/seven historical map bindings,
native/proof/metadata/CLI identities as the load-writeback measurement:

| CPP attribution | Before | After |
|---|---:|---:|
| Total bytes | 309,459,472 | 289,568,784 |
| STORE | 114,820,691 | 95,133,379 |
| MOV_LOAD | 55,080,144 | 55,080,144 |

This step saves **19,890,688 bytes (6.43%)**, for a cumulative **32.92%**
reduction from431,680,679 bytes before BMI2 specialization. The source
remains1,032,341 bytes/6,945 decoded instructions, now280.50x expansion.
Proof/render/CPP took14.50s in one observation, on8–11/8GiBAS/imageSH,
with the same production flags/chunks. This is a frontend-size measurement,
not a runtime or compiler-speed claim. There was no guest/base/image rebuild.

Native c50a8df99505eead7881bbd9bebb8eb9357fd53106feb7ff58a8f7781e393150;
proof717ece2934366ecfd4b61c0118e460153048cdce657a66d416df29ca5d823452;
metadata e5c8459b6798aa812ef24253a87a143593ad28148499c3752076f1c4603e6e4a;
normal CLI45c33e7ee145c32c80a021182706e5a8c8152900bba68dd6cc78f042f09b7cb6.
Metadata is historical and explicitly bound, not a fresh app capture. Full
OTel B/frontend resource growth, stack/stock acceptance and app equal work
remain open. No10K/100K backend was restarted. STORE still occupies95.1MB.

All raw data stays at `/workspaces/kprog-raw/perf/20261115-store-writeback`
(`native-before`, `native-after`, `oracles-before`, `oracles-after`,
`preprocess`). Canonical native/proof/C/B fixture build is
`/var/tmp/kprog-tmp/perf/store-writeback`, overwritten in place for the
second run; only hashes/logs/results of the earlier build are retained.
Current OTel proof/C/CPP reuses `otel-whole-word-checked`. No compiled copy
or raw-data deletion. Commands/measurements and known failures are committed
in this result directory.

Reproduce using the committed `native-stores`, `load-oracles` and
`current-otel-preprocess` targets in `kprog/test/native-relocations.mk`,
with OUTPUT set to a persistent run directory. The first two baseline logs
identify the pre-change header; the final native result records its input
identities and each allocated section hash.
