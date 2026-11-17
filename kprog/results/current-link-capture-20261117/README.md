# Current link-input capture

The historical 239 plans lack required `cpu_tlbstate` facts. Their old
capture wrapper also imports a deleted profile module. This experiment
captures actual paired proof/plan inputs from application startup on the
sole existing image, before another host replay. It emits no new layout
facts and does not restore the removed profiling framework.

`capture.mk` includes the frozen one-image Makefile and reuses its kernel,
image, STATE, guest, module and kvm-host-cpu recipes. Its small diagnostic
boot rule adds the existing `BPFREJIT_NATIVE_LINK_BINARY` override inside
the guest environment. `capture_link.py` delegates the image linker
unchanged and retains kernel inputs before invocation, including failed
links. It preserves the child's return status/stdout/stderr and archives
available output files. Failed earlier proof extraction retains its input
too. One hard link exposes this single committed script through the
existing corpus results mount; no source copy or alternate native body is
made. No benchmark, shared Makefile, app source, loader or image is edited.
The guest still runs the real upstream apps and native loader.

This is the frozen check's functional one-sample/10-second/stats-on
contract, on host CPUs 8–15. It keeps eight vCPUs and 64 GiB and serializes
the existing STATE under batch EX, timing SH and image SH. The controller
has a 96 GiB address-space limit. There is no timing guest on CPUs 0–7.
The native-tool override records load-time artifacts; these runs do not
measure the later unpublished LTO changes or provide official speedups.

`run.sh` visits the six apps in the frozen ORDER, one guest at a time.
Each guest's status, console and paired captures remain under
`/workspaces/kprog-raw/perf/current-link-capture-20261117`; the existing
adapter stores binaries/plans under corpus results. Indexing uses new
folder names and records supplied field names, without hashes or inferred
runtime values. Failed loads remain in logs and the batch moves to the
next app. An empty capture list is reported without a new admission gate.

Each app's index is committed and pushed. Large captures and all
logs stay in place. The only removal follows the frozen entry's successful
run cleanup of the rebuildable STATE Docker disk; raw result/capture
directories are retained. No image or second base is created. Source
changes and timing publication still follow the separate all-LTO batch.

First integration result: OTel guest finished at 18:53:34Z with rc 0
and app status `ok` (run `185119_973034`). Index `c98f65f3d` records 14
successful kernel-link requests and 28 successful proof invocations,
with no archive errors. All 14 supplied probe layouts contain
`cpu_tlbstate`; each has 16 actual supplied field names. These are request
counts, not a substitute for installed-program or B/stock totals.
All six captures subsequently finished successfully at 19:10:00Z.

After capture, `run-replay.sh` queues under batch EX, timing SH and image
EX, builds the sole canonical host linker, and replays every captured
kernel request with its actual flags and paired proof/plan. It records
all failed classes and emitted LTO ranges. Generic zero-tail suffix
counts are static sharing bounds, not installed-byte or per-call gains.
The replay does not add missing facts, infer a helper name, or skip failed
captured requests. The replay finished at 19:10:43Z: **295/295 kernel
requests emitted successfully**, with no index errors. The source build
passed in 29.71 seconds. Neither the capture nor the replay built an image.

| App | Captured kernel requests | Current host replay passed | Generic zero tails | Sharing bound bytes |
| --- | ---: | ---: | ---: | ---: |
| OTel | 14 | 14 | 12 | 0 |
| BCC | 25 | 25 | 8 | 0 |
| Cilium | 47 | 47 | 0 | 0 |
| Tetragon | 39 | 39 | 75 | 1,548 |
| Tracee | 169 | 169 | 462 | 11,268 |
| Katran | 1 | 1 | 0 | 0 |

The current schema limit is resolved by actual captured facts, without
changing the parser or synthesizing addresses. Requests are fewer than
installed programs when the loader reuses a neutral template; this is
not a complete installed-program or B/stock verification census. The
generic-tail bound counts exact emitted suffixes per request: retain
one existing 42-byte tail and charge five bytes for each error jump and
one for its local success RET. Fixed tails and added layout costs remain
outside that bound. No sharing source change is justified as a route to
half-size on these figures alone.

Capture raw: `/workspaces/kprog-raw/perf/current-link-capture-20261117/batch-20261117T184952Z-2708492`.
Replay raw: `/workspaces/kprog-raw/perf/current-link-capture-20261117/replay-20261117T190803Z-2714324`.
Small per-app indexes and raw corpus JSON are committed; binary captures,
console, command and per-request output remain in place. Replay receipt
`7693b6276` retains the actual emitter results. The first summary rendered
Katran's one success as Python `True`: the forward fix makes counters
integers and regenerates the summary from the same completed raw result.
All request return codes and payloads stay unchanged; no emission is
repeated for this presentation correction.
