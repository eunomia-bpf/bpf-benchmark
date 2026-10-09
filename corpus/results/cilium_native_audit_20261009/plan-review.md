# Fresh experiment plan review (2026-10-09)

Role: independent, read-only PLAN REVIEW under `research-experiment-design`. No code or git changes.

The hypothesis is that Cilium native execution improves measured packet processing beyond ordinary stop/start drift on the paper workload. This is a decisive workload-specific test: consistent benefit across restart pairs with small no-op drift supports the native upper-bound case; disappearance or comparable no-op drift bounds its causal interpretation. It does not independently reject the kinsn thesis. Reanalysis cannot estimate omitted restart drift, so the new controls add necessary evidence. Stock kernel JIT is current practice; JIT/JIT is a null control, not another competitor. Extra workloads/baselines are unnecessary.

Primary paper metric is emitted packet throughput from the existing kernel pktgen workload, with retained BPF ns/run as secondary. Report them separately. The referenced inventory documents the paper's exact computation. Verdict/drop counters test interpretation of the datapath; absent old counters do not erase the old measurement. Keep raw results and caveats.

## Executability findings

- `PLATFORM=aws ARCH=x86 make corpus` is a supported path. `runner/libs/aws_executor.py:_setup_instance` deploys the repository-built x86 kernel, boots it, checks release and BTF, and `corpus/driver.py` loads kinsn modules. AWS itself is not evidence that native execution is unsupported.
- Native post-only is exposed as `BPFREJIT_SHIM_NATIVE_LOADER=post`, translated by `suite_commands.py` to `BPFREJIT_CORPUS_NATIVE_LOADER_POST_ONLY=1`. Baseline disables native environment; post startup enables it. Reuse the matching existing manifest/version rather than enabling bytecode passes simultaneously.
- `SAMPLES=5` gives five baseline samples followed by five native samples, not five restart pairs. Five `SAMPLES=1` invocations give B/N pairs. For JIT/JIT set `SKIP_REJIT=norejit` and omit native post-only; `SKIP_REJIT=all` skips the post phase entirely.
- Current AWS executor terminates after each successful invocation and terminates failed-run instances. Five individual invocations therefore introduce different instances/boots unless an existing reuse route is identified. Record that deviation; it is not a reason to discard data.
- `CPU` passes through the container environment but is only consumed by the micro suite. No corpus `sched_setaffinity`/`taskset` implementation exists. Current Cilium pktgen selects `kpktgend_0` and `kpktgend_1`, inherently associating generator threads with CPUs 0 and 1; this does not pin app userspace or every softirq. CPU= alone must not be called a pinned corpus run. Use actual OS affinity observation/configuration through the authorized AWS path if possible.
- Existing Cilium runner/workload do not persist verdict/drop counters. External read-only map/counter capture during both phases is appropriate and does not require altering a frozen workload. pktgen `errors: 0` is a transmitter status, not a Cilium delivery verdict.
- Presently missing AWS credentials/SSH key are external execution blockers. No native-platform failure has been demonstrated. Pinning and counter capture require an operational method before the requested controlled claim can be made; they are user-requested controls, not added publication gates.
- Minimum traffic time is 20 phases x 180s = one hour, plus warmups/startup, build/deploy, and reboot. `t3.small` in `us-east-1` is within the repository cap. Preserve failed outcomes and verify termination.

## Old-run independent arithmetic and confounds

Stats-on `033517_489159`: 53 programs per phase; only the two `cil_from_contai` instances have at least 100 calls. Baseline IDs 152/173: 421,029,694/421,037,204 calls, 485.940684/491.410903 ns/run. Native IDs 425/465: 944,366,682/951,601,648 calls, 263.516755/261.088667 ns/run. Retained totals: 842,066,898 versus 1,895,968,330 calls (2.251565x); pooled cost 488.675818 versus 262.298078 ns/run (1.863055x). Tiny residual entry calls do not materially change this.

Stats-off `040554_604387`: all BPF call/time deltas are zero. Baseline summed pps samples 1,662,810, 1,589,441, 1,639,482; native 3,865,856, 3,907,168, 3,862,601. Median ratio is 3,865,856 / 1,639,482 = 2.357974x. The 2.358x headline is throughput from this run; 488.7 -> 262.3 ns/run comes from the other run and is 1.86x, not 2.358x.

The two phase workloads share packet size, flow count, UDP ranges and directions, but endpoint IP/MAC addresses and IDs change at restart. Program name/type inventories cannot prove byte/path equality. In stats-on each packet produces approximately one entry call and tail programs have zero recorded calls. Kernel `include/linux/filter.h:__bpf_prog_run` accounts the entry invocation around the dispatch; JIT tail jumps do not separately enter this accounting wrapper. Consequently zero tail counters do **not** establish zero tail execution, and entry ns/run can include a tail chain. Successful forwarding and equal internal paths remain unproven because verdict/receive evidence was not recorded. No verdict/drop map snapshots or receive-side delivery counters were saved. Zero pktgen errors does not resolve this. Native code size changes (entry JIT 1089 -> 1709 bytes; xlated 1720 -> 240) confirm a different generated representation. Both result files say loadtime/skipped, so pass metadata does not identify the separate native loader operation. Separate VM boot IDs, always-baseline-first ordering, no no-op control, no recorded affinity, and stats-on/off separation leave restart, cache/map state, CPU scheduling and path differences as confounds. Keep the measurements and state this uncertainty.

Review conclusion: scientifically useful and appropriately scoped; execute with documented real controls when credentials and their operational route are available. Do not label AWS unsupported before an actual native-path capability/build/load failure.

## Follow-up: stats-off program inventory mismatch

The stats-off throughput run contains **62 baseline versus 56 native program records**, not the stats-on run's 53/53. Every distinct (name,type) family appears on both sides, but these `sched_cls` multiplicities differ:

| name | baseline | native | baseline IDs | native IDs |
|---|---:|---:|---|---|
| `cil_from_host` | 3 | 2 | 117,125,146 | 373,413 |
| `cil_from_netdev` | 3 | 1 | 115,126,139 | 419 |
| `cil_host_policy` | 3 | 2 | 118,134,141 | 375,415 |
| `cil_to_netdev` | 3 | 1 | 121,129,145 | 409 |

The two endpoint `cil_from_contai` records and every tail family retain the same multiplicities. Each duplicated baseline family also repeats identical byte sizes, which is consistent with repeated host/netdev template loads or retained startup/control-plane generations. This is an inference, not attachment proof: the saved inventories contain no interface/link associations. The historical May26 implementation pauses the agent only inside each workload and resumes it afterwards (`CiliumRunner._run_workload` and `run_workload_spec`), leaving opportunities for controller activity between samples. Historical shim `emit_measure_finish` traverses all tracked programs whose kernel information remains queryable; it does not identify the active attachment graph. Thus extra records can be inactive retained instances rather than distinct traffic paths. With stats disabled every recorded call count is zero, so their contribution cannot be determined. The workload can still be compared as measured emitted throughput, but the stronger statement that precisely the same attached programs processed both phases is unsupported. A controlled rerun should preserve link/interface associations alongside the full unfiltered inventory and counts, and report any differences without excluding programs.
