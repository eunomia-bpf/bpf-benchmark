# scx_rusty End-to-End Benchmark

- Generated: 2026-04-24T00:32:42.631002+00:00
- Mode: `scx_rusty_loader`
- Duration per workload: `30s`
- Smoke: `False`
- Kernel: `7.0.0-rc2`
- Scheduler binary: `/artifacts/scx/bin/scx_rusty`

## Preflight

- sched_ext state before load: `disabled`
- workloads selected: `['hackbench', 'stress-ng-cpu', 'sysbench-cpu']`
- runtime counters available for live scheduler programs: `True`

## Loaded Programs

- Programs: `13`; applied sites total=`2`, breakdown=`extract=2`
- Active ops: `[]`

## Baseline

- hackbench: throughput=3.2360926633704747 runs/s, avg_ns=177.27632517052632, lat_p50_ms=302.0, ctx/s=85037.34955962146, agent_cpu=0.06666641976535868
- stress-ng-cpu: throughput=11609.14 bogo-ops/s, avg_ns=279.47600985221675, lat_p50_ms=None, ctx/s=265.5690080812417, agent_cpu=0.09997667227976201
- sysbench-cpu: throughput=17656.32 events/s, avg_ns=231.57691639144795, lat_p50_ms=0.23, ctx/s=263.36235550285073, agent_cpu=0.06666087809154675

## Post-ReJIT

- hackbench: throughput=3.2589992301498456 runs/s, avg_ns=177.59893302276143, lat_p50_ms=300.0, ctx/s=81525.69477237857, agent_cpu=0.09999851210213906
- stress-ng-cpu: throughput=11609.58 bogo-ops/s, avg_ns=230.9487364981166, lat_p50_ms=None, ctx/s=261.50055046027455, agent_cpu=0.0999942649955883
- sysbench-cpu: throughput=17658.08 events/s, avg_ns=227.56724099899512, lat_p50_ms=0.23, ctx/s=267.55987891455044, agent_cpu=0.033330621132921096

## Comparison

- hackbench: throughput_delta=0.7078464420580923%, bpf_avg_ns_delta=0.1819802232050922%, bpf_speedup=0.9981835034324572, ctx_delta=-4.129544024394597%, lat_p50_delta=-0.6622516556291391%, agent_cpu_delta=49.998323674943244%
- stress-ng-cpu: throughput_delta=0.0037901170973948916%, bpf_avg_ns_delta=-17.363663299673103%, bpf_speedup=1.2101214065507386, ctx_delta=-1.531977564084787%, lat_p50_delta=None%, agent_cpu_delta=0.017596820763416315%
- sysbench-cpu: throughput_delta=0.00996810207337677%, bpf_avg_ns_delta=-1.7314659228275786%, bpf_speedup=1.0176197390048356, ctx_delta=1.5938205760975852%, lat_p50_delta=0.0%, agent_cpu_delta=-49.999726845560794%

