# Best x86 numbers on the current system (2026-11-21, coordinator; rewritten 15:3x UTC)

Operator 2026-11-18: "你要用历史上最好的数据作为合理的数据. 你看看能不能复现合理的最好数据, 也要对比比如说程序的功能是不是正常,
功能正常就可以"; "不应该拿调用次数做对比和 gate? 调用次数很可能不同啊"; "莫名其妙的门槛直接清理掉". 2026-11-21 ~15:1x UTC:
"两臂工作量不同，不算??? 怎么还是会有被你不算的? 不是都不看工作量了吗?".

Rule: every functional run counts, whatever its program or call counts. A run is left out only when its native side did
something functionally different, with the receipt that shows it. `best.py` scans the x86 runs of 11-16..11-21 with the
frozen settings (3 samples x 180 s, status ok); ratios are native/eBPF from the 05-29 parser (`raw-maxima.txt`).

## Image 3b5fa4b40 (bpf-benchmark/kprog:current, sha256:ba86ac5d), best of its frozen-entry runs

| App | Per call | Throughput stats off | Throughput stats on | Runs | 05-29 (kinsn-era system) |
|---|---|---|---|---|---|
| Tracee | **2.036x** | **1.884x** | 1.659x | 013353_459359, 225422_198013 | 0.948x |
| Tetragon | **1.248x** | **3.291x** | 1.093x | 010702_796774, 222740_505433 | 1.009x |
| Cilium | **1.348x** | 1.027x | **1.123x** | 133941_317114, 121942_061103 | 1.319x |
| BCC | **1.144x** | 1.009x | **1.251x** | 001342_075406, 115246_054562 | 0.985x |
| Katran | **1.017x** | 0.962x | 1.004x | 020118_444610, 232145_135785 | 1.113x |
| OTel | **0.955x** | 0.979x | 1.006x | 124621_300407, 112615_798808 | 1.849x |

Per-call geomean over the six: **1.250x** (20% target: 1.20x). The same image also read BCC 1.017x and Cilium 1.012x per
call in other runs: the spread between runs of one image is that large.

## Best functional numbers of the week (any image of the current system)

| App | Per call | Throughput stats off | Run |
|---|---|---|---|
| Tetragon | 2.790x (main configuration) | 3.291x | 20261120_143937_810796, 20261120_222740_505433 |
| Tracee | 2.036x | 1.884x | 20261121_013353_459359, 20261120_225422_198013 |
| Cilium | 1.348x | 1.027x | 20261121_133941_317114, 20261121_121942_061103 |
| BCC | 1.144x | 1.023x | 20261121_001342_075406, 20261119_045219_454072 |
| Katran | 1.094x | 1.120x | 20261116_145408_662903, 20261116_092956_863537 |
| OTel | 0.960x | 1.053x | 20261116_195601_628082, 20261117_091405_442941 |

## Left out: the native side did something functionally different

| Run | Receipt |
|---|---|
| OTel per call 14.4x, throughput 1.866x / 1.854x / 2.020x (11-16) | the native path skipped the stack unwinding the eBPF path does: unroll attempts 913,099,438 to 0 (perf-history-review-20261120) |
| Cilium per call 4.1x / 4.0x / 3.8x (11-16), stats off 2.819x (11-17), 3.564x (11-19 202033) | natives built with Cilium's sample config ran in place of programs the agent built with its own constants; on 11-19 the native packets also crossed cil_to_host and the sender pushed about 3x the packets (todo, coordinator 2026-11-19T21:30:54Z) |
| Katran stats off 1.121x (11-16 095730) | the 05-29 image, the May reference of katran-linker-repeat |
