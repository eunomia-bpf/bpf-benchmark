Part A is reconstructed with explicit confidence limits. Part B’s old data is analysed; the new AWS measurement is **blocked by missing credentials and SSH key**, so no controlled numbers are claimed.

[part-a.md](part-a.md) and [data/commit-pins.csv](data/commit-pins.csv) give every run’s chronological source candidate, inferred kernel gitlink, reconstructed replay snapshot, supporting component history and confidence. Exact measured HEADs cannot be recovered from `unknown` metadata. There are 16 selected May/June measurements plus the April 29 population anchor; the inventory does not select a June 8 collection.

Chronological source candidates are: May 14 micro `6273b6497908` / `fed5531cd05c`; May 19 micro `6063cc301444`; May 20 ARM micro `08aba8625570`; May 23 ARM micro `14867b6a71cb`; both May 26 micro runs `16e4d39d76ed`; both May 29 corpus runs `9f3855f6fa1c`; June 4 corpus `9af5cf074873`, `e9956b814b38`, `9e43757a2f4b`; June 5 00:46 corpus `9e43757a2f4b`; both June 5 ARM corpus runs `0b530196cb73`; June 6 ARM micro `cc070f4d6830`. Kernel candidates are `81cb8848bace` for May 14, `6f0caf14e995` for May 19/20, and `8e116c79d104` thereafter. Generic `7.0.0-rc2+` strings do not identify an exact kernel binary; corpus release strings were not retained.

After-run source commits contain relevant policy/selector changes: tuned x86 replay uses `fbbd216a28a4`; ARM corpus `d01056165269`; ARM micro `06f80a8955ab`. These reconstruct likely working-tree changes and are not certified collection HEADs. Exact-source confidence is low; kernel lineage confidence is medium, exact binary low.

The retained 29-case sizes reproduce **0.77180688 / 0.87911616**. [check-code-identity.py](check-code-identity.py) compares per-case JIT/bytecode size signatures from a supplied-commit replay and optionally compares actual binary dumps byte-for-byte. It detects 29 signature differences between the historical May 19/26 datasets. Equal sizes cannot prove byte identity. Original full JIT images are absent; October callback binaries establish only their own comparison, not May/June identity.

The old Cilium version is `1.20.0-dev`, upstream gitlink `1b721c2964e7799cab3e18c38066905ea240fa34`, also recorded by current HEAD. [part-b.md](part-b.md) and the CSV/raw files provide every program and traffic sample.

| Old stats-on entry | Calls | ns/run |
| --- | ---: | ---: |
| JIT ID 152 | 421029694 | 485.941 |
| JIT ID 173 | 421037204 | 491.411 |
| native ID 425 | 944366682 | 263.517 |
| native ID 465 | 951601648 | 261.089 |

Pooled **488.676→262.298 ns/run is 1.863055×**, with total calls **842066910→1895968339**. **2.357974×** is instead stats-off median throughput **1639482→3865856 PPS**. Its baseline/native PPS ranges are **1589441–1662810 / 3862601–3907168**. Stats-on inventories match 53/53; stats-off inventories differ 62/56. Endpoint addresses/MACs changed on restart. Zero tail counters do not imply unused tails: timing wraps entry dispatch and its tail chain. Zero pktgen errors establish transmitter status only. Verdict/drop/receiver counters and per-sample BPF timing were not retained; equivalent internal paths and timing spread cannot be established.

The existing AWS path supports custom x86 kernel deployment; no native-platform incompatibility was demonstrated. `CPU` is ignored by corpus, and `SAMPLES=5` does not restart five times. Five native pairs interleaved with five JIT/JIT restart controls require separate invocations and actual OS affinity/counter capture.

The Makefile AWS native preflight entered only local kernel compilation, then was interrupted after `aws --profile codex-ec2 ... sts get-caller-identity` failed with exit 255: profile absent; default SSH key absent; no AWS credential environment variables. Logs and exact command are retained. No guest ran on the lab host. **Instances started: 0; termination required: 0; AWS cost: 0.** Planned resources were `t3.small`, `us-east-1`; intended kernel `24cd6e63ce91`, `7.0.0-rc2+`. No AWS kernel was observed. Restore existing credential/key paths to perform the requested comparison; its absence is not a measured native failure.

No existing result, framework code, workload, launcher, or paper number was changed.

The subsequent [October 9 lab rerun](../cilium_native_lab_rerun_20261009/summary.md)
completed the historical pinned pairs/controls and one current-master pair,
then was interrupted by the reported host reboot about 16:04–16:05 UTC.
Its native arm policy-dropped traffic that JIT forwarded; retained timing/PPS
ratios therefore do not establish equivalent-forwarding speedups. This later
record does not change the old audit's measurements or confidence limits.
