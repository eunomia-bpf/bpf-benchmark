# OTel checked hotspot stack rejection

2026-11-15T00:50:54Z. The long whole-app run605029 is still active, but its fourth request finished at2026-11-14T23:56:43Z. Source program42, `perf_unwind_hotspot`, reached actual sole-kernel stock verification and failed before native compilation/installation:

```text
1: (7b) *(u64 *)(r10 -576) = r0
invalid write to stack R10 off=-576 size=8
```

The request started21:12:37Z and the service returned status-5 after the verifier subprocess failed (Permission denied). There is no hotspot native program ID or execution claim. Earlier requests21→native27,28→34 and main35→41 completed installation; main success is not whole-app success. The journal and small archive members are retained here; the complete119MiB failure archive remains at `/workspaces/kprog-raw/perf/20261114-otel-whole-word-checked/state/session-d1wppo7h/requests/4.failure.tar.gz`.

The earlier checkpoint incorrectly kept describing request4 as an active frontend based on the live guest/RSS. The terminal request journal supersedes that inference. At this read, a later active directory `request-nzgmeixv` also names `perf_unwind_hotspot`; its completion is not yet journaled. It is preserved, with no duplicate work started or process stopped. The guest logged post_rejit measurement_start, but no phase-completion or whole-app success is recorded.

This run uses the retained prior producer/combined-LTO candidate `ef44985c193e`, whole-word B spills enabled with the former single-pair selection and ALL mode off. It does not test the new unified header/flag producer or establish HARD-native performance. The B-compiler switch collapse and actual576-byte stack class remain open after the leading linker work.
