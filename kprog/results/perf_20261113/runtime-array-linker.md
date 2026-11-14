# Runtime ARRAY linker candidate, 2026-11-14

Opt-in `--runtime-array-layout layout.json` requires existing `--runtime-map-lookups`. After checking actual RDI map_type, ARRAY uses the live max_entries, index_mask and elem_size with the kernel's u32-key/u64-product semantics. Other types call the original generic helper with original arguments. Proof emission and defaults retain their bytes; no map identity or inner-map type is inferred.

The layout utility reads the sole boot-matched kernel BTF through libbpf, including anonymous aggregate members and field widths. Current offsets: map_type56, max_entries68, elem_size288, index_mask292, value304; ARRAY enum2. The checked-in target vmlinux.h is stale for the last three fields (280/284/296); it is not used. Actual kernel array_map_lookup_elem instructions independently confirm288/292/304. The frozen304 offset was correct. Findings were sent to VERIFIED/C without changing their canonical header/base.

Host execution tests pass27, with1 preexisting ignored. Tests cover key boundaries, mask, wide product, original generic-call arguments, non-ARRAY dispatch before key access, and actual immediate/GOT/PLT encoding including a branch entering the guard.22 six-app real-object cases preserve default/runtime-map proof text and kernel bytes/relocs/maps/ABI against the canonical prechange binary.

The28 runtime CLI cases from the earlier actual audit replay successfully. OFF reproduces every captured output byte;14 proof objects are identical ON/OFF.124 remaining generic sites receive guards, including76 in perf_unwind_native. Programs without remaining generic lookups are unchanged. These are static compiler checks, not dynamic speedup, installation, equal-work, floor or verified-path results.

```sh
make -f kprog/perf/native-context/Makefile runtime-array-link-payload
make -f kprog/perf/native-context/Makefile known-map-link-check
make -f kprog/perf/native-context/Makefile link-audit-replay LINK_AUDIT_REPLAY_LINKER=/var/tmp/kprog-tmp/perf/native-link-known-maps/debug/native-link LINK_AUDIT_REPLAY=/workspaces/kprog-raw/perf/20261114-runtime-array/replay-fresh LINK_AUDIT_REPLAY_ARGS='--runtime-array-layout /var/tmp/kprog-tmp/perf/runtime-array-layout/runtime-array-layout.json'
```

All input capture groups are retained by dab9e2ce8. New tests, plans, replay outputs, pinned binary/wrappers/layout and reports are archived by runtime-array-linker.json/.tar.gz under this directory; full raw remains `/workspaces/kprog-raw/perf/20261114-runtime-array`. Error/preliminary attempts remain recorded. No pointer caching or caller lifetime/RCU change is introduced: the same valid map pointer and caller protection required by the generic helper remain required. Final live map binding and verified execution remain separate evidence work.

A separate Make target runtime-array-otel prepares the1x10s stats-on diagnostic,4vCPU16G/CPUs16–19 and existing original-source OTel manifest. Its result will be collected in a later turn. Canonical linker binary/base/image/kernel and frozen workloads/launchers remain unchanged by this candidate.
