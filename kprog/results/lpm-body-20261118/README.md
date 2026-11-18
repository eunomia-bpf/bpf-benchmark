# Compiled trie body diagnostic

Scope: measure the retained native ARRAY/LPM range against the sole kernel's
compiled trie body on stable host nodes with the captured kernel layout.
The smallest experiment extracts these existing bodies, records host-only
patches, checks expected value pointers and times three query shapes. The
production source, canonical CLI, checked guest, image and corpus entry retain
their current state.

The kernel's external return-thunk jump becomes an ordinary RET in its host
slice. The native range's generic helper relocation targets a local UD2;
the fixture supplies the captured LPM type and twelve-byte data shape. Both
original byte slices and each explicit patch remain in raw output. A normal
SysV call executes both bodies. The fixture checks empty/full/short/over-max
and first/last-bit cases, then a balanced fourteen-level trie with 4,096
queries and a retained ancestor value. Timing alternates arm order across
three samples for full hit, first-bit miss and deep hit.

Run the committed wrapper with setsid nohup. It holds timing SH and image SH,
uses CPU19 and limits address space to4GiB. Raw output stays in
/workspaces/kprog-raw/perf/lpm-body-20261118. This is helper-body diagnostic
evidence. Kernel return mitigations, concurrent update/RCU behavior, actual
application frequency, per-call BPF time and installed app bytes belong to
omp's frozen image/check/affected-app batch with all LTO enabled.

2026-11-18T01:16:29Z — Host2846223 ended0. The eight functional groups pass,
including all4,096 deep queries. Kernel/native median body ratios are1.158
for full hit,1.292 for first-bit miss and0.812 for deep hit. The three raw
kernel deep samples are118.421/104.393/104.664ns; native is128.984/128.919/
128.039ns. See baseline.json for every raw sample, input path and patch.
The first deep kernel sample includes the initial large-tree cache state.
All measurements stay in the report. Function-text sizes are497B kernel and
293B native fused dispatch; each has a different place in installed app code,
so these sizes describe the slices. Production emits an IMUL by8 per trie
level where the kernel uses an indexed address. A local SIB specialization
and the equivalent NOT/AND bit selector are the next measured source step.

2026-11-18T01:21:45Z — Source step: the child-pointer load folds the captured stride8
into SIB scaling. The bit selector computes the same `(~prefix)&7` with
NOT/AND. Other stride encodings retain the existing multiply form. This is
one open production file, three additional lines; existing trie/ABI/shape
checks supply the regression coverage. The compile-time selection emits the
same runtime guard paths. Existing full suite:62 pass,4 opt-in. All295
captured requests emit successfully. Helper targets, relocation-kind counts,
map names, callee masks and recovery-shape counts match in every pair.

The actual retained perf_unwind_native fused range is293→285B. Every one of
157 retained trie ranges shrinks8B. Total neutral payload falls1,256B across
Cilium192, Katran8, OTel8, Tetragon136 and Tracee912B; BCC stays identical.
There are zero growth cases. See comparison.json for each request, including
all captured error statuses. These plans exercise existing generic trie
ranges; the new named-lpm12 map selection has separate source/host evidence
in results/named-lpm-20261118 and awaits actual new-image captures.

| Query | Baseline native ns | Scaled native ns | Candidate kernel ns |
| --- | ---: | ---: | ---: |
| Full hit | 4.118 / 4.090 / 4.086 | 4.096 / 4.084 / 4.084 | 4.758 / 4.693 / 4.600 |
| First-bit miss | 3.412 / 3.407 / 3.410 | 3.409 / 3.406 / 3.408 | 4.409 / 4.399 / 4.397 |
| Deep hit | 128.984 / 128.919 / 128.039 | 109.683 / 110.042 / 109.935 | 104.630 / 104.773 / 104.288 |

The native deep median improves1.173x. Its candidate median remains1.051x
the compiled kernel body cost. Full/miss paths preserve their observed cost;
full-depth hits skip child addressing. Stable-node host timing attributes the
addressing dependency, while actual app throughput, per-call BPF time,
body/helpers/maps and installed native/JIT bytes remain omp batch work.
The host ordinary return also separates this result from the kernel's return
mitigations. The first deep baseline kernel sample retains its initial-cache
cost and remains listed.

Baseline host2846223 ended0. Candidate host2847307 ended0 at01:20:13Z, with
all functional groups passing, the same C driver binary and three alternating
samples per query. Raw: /workspaces/kprog-raw/perf/lpm-body-20261118/candidate-20261118T011911Z-2847307; baseline:
/workspaces/kprog-raw/perf/lpm-body-20261118/host-20261118T011625Z-2846223.
The worker used timing SH/image SH, CPU19 and one Cargo worker/32GiB AS.
The canonical CLI remains2,978,744B with mtime1794948232. The checked Tracee
guest2754970 retains its image/base/CLI lease. Omp owns the next frozen
image/check/affected-app batch with the complete LTO cohort. The phase1
original-FD prototype query and owned context-only program lifetime remain
the frozen-core owner handoff documented in helper-fd-boundary-20261118 and
context-and-globals-20261118.
