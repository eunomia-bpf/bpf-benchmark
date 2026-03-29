# Tracee Real End-to-End Benchmark

- Generated: 2026-03-29T08:35:37.603276+00:00
- Mode: `tracee_daemon_same_image_paired_with_control`
- Duration per workload: `20s`
- Warmup per workload: `4.0s`
- Paired cycles: `5`
- Latency probes per phase: `8`
- Smoke: `False`
- Tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `/home/yunwei37/workspace/bpf-benchmark/e2e/cases/tracee/bin/tracee`

## Preflight

- exec_storm: primary_events/s=212.64643640252106, bpf_avg_ns=53.63517274272193, target_runs=5602325
- file_io: primary_events/s=130.70064840997662, bpf_avg_ns=30.84142606638223, target_runs=5602325
- network: primary_events/s=5753.404192001181, bpf_avg_ns=37.483169904735234, target_runs=5602325

## Control

- exec_storm: app_mean=57.41204500784501 execs/s, app_ci95=[51.661641474185075, 60.8783096914933]
- file_io: app_mean=7403.739087163887 opens/s, app_ci95=[6920.484413886347, 7672.973549894501]
- network: app_mean=6505.582404768257 connects/s, app_ci95=[6311.0633205385575, 6694.556574604165]

## Baseline

- exec_storm: app_mean=56.031331159493654 execs/s, primary_events_mean=224.22527257523274/s, latency_p99_mean=5.592651684 ms, overhead_mean=1.6044500421407322%, bpf_avg_ns_mean=57.94191144686499
- file_io: app_mean=7470.269418863806 opens/s, primary_events_mean=36.731767352257414/s, latency_p99_mean=0.929332742 ms, overhead_mean=-1.2421387044071226%, bpf_avg_ns_mean=29.711065044476854
- network: app_mean=5872.109327824892 connects/s, primary_events_mean=5872.656801613281/s, latency_p99_mean=1.1247699 ms, overhead_mean=9.551575884673266%, bpf_avg_ns_mean=36.87613781972084

## Post-ReJIT

- exec_storm: app_mean=57.682827874843355 execs/s, primary_events_mean=230.83128178492882/s, latency_p99_mean=5.018740888 ms, overhead_mean=-1.6529407632903752%, bpf_avg_ns_mean=58.20551837394611
- file_io: app_mean=7595.5544178815 opens/s, primary_events_mean=36.71893371117354/s, latency_p99_mean=1.232327738 ms, overhead_mean=-3.021149083473495%, bpf_avg_ns_mean=29.650529891729853
- network: app_mean=5831.620757220302 connects/s, primary_events_mean=5832.168220829266/s, latency_p99_mean=1.0122821 ms, overhead_mean=10.17049940305019%, bpf_avg_ns_mean=36.9333318686446

## Comparison

- exec_storm: app_delta_mean=3.090452236943185%, event_delta_mean=3.089018362976178%, overhead_delta_mean=7.7175371690640615%, latency_p99_delta_mean=-6.730654366164494%, app_p=0.1875, overhead_p=0.1875
- file_io: app_delta_mean=1.707242497247536%, event_delta_mean=-0.03490149073102635%, overhead_delta_mean=133.90658177458582%, latency_p99_delta_mean=33.121455159245926%, app_p=0.1875, overhead_p=0.1875
- network: app_delta_mean=-0.6549558582783854%, event_delta_mean=-0.6548980201899731%, overhead_delta_mean=33.268883367667534%, latency_p99_delta_mean=-7.175994939492277%, app_p=0.3125, overhead_p=0.3125

