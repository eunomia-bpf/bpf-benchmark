# Fixed-frequency follow-up

The coordinator's18:38:22Z handoff assigns PERF one A/A and one A/B run on sole
imagefc5336c2, with all LTO including clock linkage enabled. Each run keeps the
existing one-image corpus entry,3x180s/stats1,8vCPU64GiB,host0-7 and the frozen
host-frequency setup/restoration. The batch holds timingEX then imageSH.

The observation wrapper preserves the original guest Make command and records
phase-start JIT/source evidence, actual in-container link plans, cached neutral
blob/relocation lengths and identities, and entry diagnostics. The plan uses a
temporary stem while binary cache files move to the final key; collection
associates these through that exact key. Runtime JIT captures and cache-template
metadata stay distinct. Observation errors remain alongside the original suite
exit status and its raw measurements; both scheduled arms execute.

A real guest smoke through the wrapper completes the original map/value/image
test unchanged,3/3 returns42/304/42, with observation errors empty. Its original
guest command and results are retained here. Compilation and shell syntax also
pass. The official pair completed19:44:34Z, with both Make and app statuses0/OK.

Entry: make -r -f kprog/test/native-relocations.mk katran-fixed-frequency.
Full raw: /workspaces/kprog-raw/perf/20261115-katran-fixed-frequency/.

A/A completed19:18Z, Make0/appOK. Both actual programs are13641B JIT and
23840B translated. Per call173.857457→178.067376ns gives first/second
0.976357718; mean throughput2476317.667→2438470pps gives second/first
0.984716150 (sample rates retained in aa-analysis.json). Host-frequency controls
restore with an empty error list. This is the control factor for the pending
A/B result. The existing per-call-aa/analyze.py reducer retains all counters
and raw pktgen errors; the batch kept its timingEX/imageSH locks during A/B.

The complete pair ran18:52:02–19:44:34Z under timingEX/imageSH. Both preparations
selected performance governors, turbo disabled, and min=max3700000kHz for
policies0–7. All73 controls restored exactly after each run; observer errors
are empty. The quiet window ended with the batch; queued peer work resumed.

| Run | First ns/call | Second ns/call | First/second cost factor | First mean pps | Second mean pps | Second/first rate |
|---|---:|---:|---:|---:|---:|---:|
| A/A, eBPF → eBPF | 173.857457 | 178.067376 | 0.976357718 | 2476317.667 | 2438470.000 | 0.984716150 |
| A/B, eBPF → native | 177.013829 | 175.770415 | 1.007074080 | 2416832.333 | 2453848.000 | 1.015315778 |

Requested per-call normalization is1.007074080/0.976357718=**1.031460153x**.
Mean throughput normalization is1.015315778/0.984716150=**1.031074566x**;
using medians gives1.032409613x. These are point estimates from the requested
single A/A and single A/B, each3x180s. The per-call and throughput targets
remain open. aa-analysis.json, ab-analysis.json and comparison.json retain
all counters and every sample. Successful pktgen packets and BPF invocations
differ by1 in A/A baseline and0 in the other three arms. Raw transmit errors
remain recorded separately from XDP decisions.

The A/B second arm's measured program is nativeID16,12418B JIT/16B translated;
the live originalID15,13641B JIT, also appears in the snapshot. Counters belong
to16. The source native balancer_ingress body is7965B (0.583901x JIT size),
while total installed native code is12418B (0.910344x). The7965/13641 body row
includes the actual application section only; linker/runtime code explains
the larger installed size. Pure-body runtime is unmeasured: whole-program
counters include helper and link-time routines, so the3.15% result establishes
the whole-program per-call observation. The hard body-speed target continues.

Actual timed planbe14e409af5bfa5b.tmp.3017.link-plan.json and cache metadata are
retained as timed-link-plan.json and timed-cache-metadata.json. Replay through
the current analysis CLI677175ed matches the timed proof,12386B neutral blob
and288B relocations exactly; the measured image carried64eb98aa. Thus the
replay's helper-site interpretation is bound to the recorded timing inputs.
There are84 unique static helper sites:66 map lookups,8 clocks,2 CPU queries,
4 adjust-head and4 map updates. Of66 lookups,60 have named map facts:
38percpu-array,14array,4hash,2hash-of-maps and2typed calls;6 retain dynamic map
arguments. Every clock relocation selects the timed plan's fast monotonic
clock symbol. These are static site counts; execution frequencies remain
separate. The six dynamic offsets are3743,3988,5304,5743,5831,6085; classifying
inner-map results versus lost CFG facts is the next map-provenance task.

Reproduction of the offline reductions:

```sh
python3 kprog/results/perf_20261113/per-call-aa/analyze.py --run corpus/results/x86_kvm_corpus_20261115_185356_204200 --output /workspaces/kprog-raw/perf/20261115-katran-fixed-frequency/batch/aa/analysis.json
python3 kprog/results/perf_20261113/per-call-aa/analyze.py --run corpus/results/x86_kvm_corpus_20261115_192007_061187 --output /workspaces/kprog-raw/perf/20261115-katran-fixed-frequency/batch/ab/analysis.json
make -r -f kprog/test/native-relocations.mk katran-helper-audit KATRAN_LINK_PLAN=/workspaces/kprog-raw/perf/20261115-katran-fixed-frequency/batch/ab/post_rejit-429195073aeb/be14e409af5bfa5b.tmp.3017.link-plan.json OUTPUT=/workspaces/kprog-raw/perf/20261115-katran-fixed-frequency/plan-audit
```

Full live JIT/source captures, logs, host controls, plans, diagnostics and
raw corpus outputs stay under the raw root and the two corpus run directories.
The recorded neutral templates and installed JIT captures have distinct roles;
their metadata never substitutes one for the other.

The pure-body question continues in a separate1x60s two-arm profile, using the
existing phase-profile tool under the same fixed-frequency envelope and
timingEX/imageSH. Its perf/module/image inputs are hardlinks to the canonical
artifacts; the completed profile stage records cleanup paths while retaining
raw profiles in persistent storage. It supplies samples for attribution and
keeps the completed A/A–A/B counters above as the official timing observation.
Launcher1180023 started20:00:21Z; raw data and eventual profile results stay
under /workspaces/kprog-raw/perf/20261115-katran-body-profile/.
