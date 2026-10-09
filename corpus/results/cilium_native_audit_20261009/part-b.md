# Part B: Cilium reconstruction and controlled AWS measurement

The historical native comparison uses Cilium gitlink `1b721c2964e7799cab3e18c38066905ea240fa34` (May 21 UTC), whose VERSION is `1.20.0-dev`. The current repository records the same upstream Cilium gitlink and VERSION. This establishes a source-version match, not equality of previously compiled artifacts, loader, kernel, endpoint configuration, or native compiler options. The history candidate for the original loader is `9f3855f6fa1c43027cfe0788615b6efb247f2a4d`; the late `e31becfa3679` commit retains the runs but is not a recorded measurement pin.

The traffic is bidirectional endpoint-to-endpoint kernel pktgen: 64-byte UDP packets; port range 1–65535; 65535 random flows (`FLOW_RND`), flowlen 1, clone_skb 0; three 180s samples and one warmup. After restart, the stats-on endpoints changed from 10.244.0.190/10.244.0.20 to 10.244.0.173/10.244.0.103. MAC addresses changed too. The distributions match, but exact addresses, random flow sequence, endpoint identities and map state are not fixed.

## Original counts and times

| Stats-on phase / ID | Program | Calls | Time (ns) | ns/run | JIT bytes / BPF bytes |
| --- | --- | ---: | ---: | ---: | ---: |
| JIT / 152 | cil_from_contai | 421029694 | 204595457442 | 485.940684 | 1089 / 1720 |
| JIT / 173 | cil_from_contai | 421037204 | 206902272460 | 491.410903 | 1089 / 1720 |
| native / 425 | cil_from_contai | 944366682 | 248856443360 | 263.516755 | 1709 / 240 |
| native / 465 | cil_from_contai | 951601648 | 248452405736 | 261.088667 | 1709 / 240 |
| all JIT programs | 53 records | 842066910 | 411497744478 | 488.675828 | — |
| all native programs | 53 records | 1895968339 | 497308860864 | 262.298083 | — |

The pooled time ratio is **1.863055×**. Endpoint call ratios are 2.2430× and 2.2601× (pairing directions by workload/ID order is inferred, not attachment-proven); total calls grow 2.251565×. Each phase’s recorded pktgen packets total 842065781 and 1895968326, respectively, approximately one entry call per transmitted packet. Almost all accounted calls/time belong to those two entries; full per-program values, including zero and tiny counts, are in `data/old-programs.csv`.

Zero separate tail-program counts do not show that tails were unused. Historical kernel `include/linux/filter.h::__bpf_prog_run` starts timing before entry dispatch and increments the entry’s counters after it returns; JIT/native tail jumps can execute without separately entering that wrapper. The measured entry duration can include the tail chain. The counters therefore cannot determine internal helper/map/branch paths. Do not apply a filter that loses this distinction.

There is no retained per-sample BPF time/count breakdown, so temporal medians or spread for ns/run cannot be reconstructed from these aggregates. The two programs’ different costs are not temporal repetitions.

## Throughput is a separate measurement

| Run | Phase | PPS samples | Median PPS | min–max PPS |
| --- | --- | --- | ---: | --- |
| stats on, 033517 | JIT | 1555071, 1571949, 1552378 | 1555071 | 1552378–1571949 |
| stats on, 033517 | native | 3502101, 3505649, 3528644 | 3505649 | 3502101–3528644 |
| stats off, 040554 | JIT | 1662810, 1589441, 1639482 | 1639482 | 1589441–1662810 |
| stats off, 040554 | native | 3865856, 3907168, 3862601 | 3865856 | 3862601–3907168 |

**2.357974×** is 3865856 / 1639482 PPS in the stats-off run, not 488.7 / 262.3 ns/run. All BPF counters in the stats-off run are zero because accounting was disabled. Its inventory changes 62→56: `cil_from_host` 3→2, `cil_from_netdev` 3→1, `cil_host_policy` 3→2, `cil_to_netdev` 3→1. Other name/type multiplicities match. Duplicate identical baseline sizes suggest retained startup generations; the missing attachment graph prevents confirming whether they were inactive. Stats-on name/type multiplicities match 53→53.

All recorded pktgen components report zero transmitter errors. Neither run saves verdict/drop maps, receiver-delivery counters, endpoint attachment graphs, per-site/helper counters or packet traces. Transmitter success cannot establish forwarding/delivery or equal internal work. Both app `rejit_result` fields say loadtime/skipped, consistent with skipping optimizer passes during separate native-loader startup, but they do not preserve the native manifest/object identity or the reported 135-replacement log. Changed representation lengths support native replacement without identifying its complete bytes.

Always-JIT-first order, fresh endpoint/map state, separate VM boot IDs for stats-on/off, no restart-only control, and no affinity record leave drift, cache/scheduling, differing traffic decisions and compiler/configuration differences as possible explanations of part of the benefit. These are caveats to the retained measurements, not grounds to delete them. Native source build uses O3, MICRO_NATIVE and architecture flags; historical native Cilium objects use MAX_* feature profiles, whereas the app compiles endpoint BPF from runtime configuration. No saved macro/config equivalence establishes their same-path contract.

## Requested experiment and operational limits

The plan is >=5 JIT/native restart pairs alternating with >=5 JIT/JIT restart controls, SAMPLES=1 per invocation, original 180s traffic, stats enabled on both measured sides. Report per-program pooled cost, per-pair median and min–max/IQR, counts and traffic throughput, plus before/after verdict/drop snapshots and attachment mappings. Preserve every failed or completed outcome. No-op uses `SKIP_REJIT=norejit`, not `all` (which skips post), with native flags absent. Native comparison uses `BPFREJIT_SHIM_NATIVE_LOADER=post`. SAMPLES=5 alone would batch samples within each phase rather than restart five times.

The existing AWS x86 path deploys/boots the repository’s custom kernel and loads modules; AWS itself is not a demonstrated native incompatibility. Current executor terminates each make invocation, so interleaving individual invocations includes between-instance variation. CPU env is forwarded but not consumed by corpus; it must not be described as pinning. Pktgen explicitly uses CPU-associated kpktgend_0 and _1. Actual app/process/softirq affinities need OS verification and, where needed, taskset/IRQ steering before collection. Auxiliary read-only bpftool/cilium metric snapshots during both app-owned phases can collect verdict/drop data without modifying frozen workloads. Missing old telemetry cannot be retrospectively repaired.

A current-source AWS native preflight was launched only through `PLATFORM=aws ARCH=x86 make corpus`; its exact settings and output are in `data/aws-command.json` and `data/aws-preflight.log`. This is a preflight, not a CPU-pinned controlled pair. Final execution/resource status is recorded in summary.md and metadata.json. There are no new controlled numbers unless actual AWS phases finish. Missing credentials/key are an external blocker, not a native-platform capability failure. The nearest valid next measurement is the requested controlled AWS x86 comparison after restoring its credential/key paths; if an actual native load fails, retain that error and compare JIT/JIT drift plus the supported kinsn load-time policy on the same AWS workload, labeling that alternative separately from whole-program native execution.
