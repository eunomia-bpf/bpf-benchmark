# Tracee Real End-to-End Benchmark

- Generated: 2026-03-13T19:27:15.921898+00:00
- Mode: `tracee_daemon`
- Duration per workload: `60s`
- Smoke: `False`
- Tracee binary: `/tmp/tracee-bin/tracee`

## Setup

- Setup return code: `0`
- Setup tracee binary: `missing`

## Baseline

- exec_storm: app=160.85900374051403 bogo-ops/s, events/s=1612.2231976636806, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=9.03332205733852, bpf_avg_ns=92.1859991465166
- file_io: app=718511.1675589788 IOPS, events/s=6.152708423958318, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=0.16666557697656903, bpf_avg_ns=32.33818790229565
- network: app=4991.6710607426385 req/s, events/s=4993.949428559457, drops={'event_count': 0, 'lost_event_count': 0, 'lost_write_count': 0}, agent_cpu=21.683124883696422, bpf_avg_ns=43.83859964471756

## Recompile

- Applied programs: `0` / `13`
- Applied successfully: `False`
- Errors: `["enumerate failed ([Errno 13] Permission denied: '/tmp/e2e-enumerate-policy-dir-1u5t9j53'), legacy apply failed: [Errno 13] Permission denied: '/tmp/e2e-live-policy-9vlqgxso.policy.yaml'", "enumerate failed ([Errno 13] Permission denied: '/tmp/e2e-enumerate-policy-dir-83_b_sz0'), legacy apply failed: [Errno 13] Permission denied: '/tmp/e2e-live-policy-dak69lkj.policy.yaml'", "enumerate failed ([Errno 13] Permission denied: '/tmp/e2e-enumerate-policy-dir-_2b6yi71'), legacy apply failed: [Errno 13] Permission denied: '/tmp/e2e-live-policy-q_0e1j12.policy.yaml'", "enumerate failed ([Errno 13] Permission denied: '/tmp/e2e-enumerate-policy-dir-dbotid83'), legacy apply failed: [Errno 13] Permission denied: '/tmp/e2e-live-policy-gego8s3l.policy.yaml'", "enumerate failed ([Errno 13] Permission denied: '/tmp/e2e-enumerate-policy-dir-i878vabo'), legacy apply failed: [Errno 13] Permission denied: '/tmp/e2e-live-policy-kdjqomss.policy.yaml'", "enumerate failed ([Errno 13] Permission denied: '/tmp/e2e-enumerate-policy-dir-j6o3gd0z'), legacy apply failed: [Errno 13] Permission denied: '/tmp/e2e-live-policy-9dmq5m4q.policy.yaml'", "enumerate failed ([Errno 13] Permission denied: '/tmp/e2e-enumerate-policy-dir-jiowcisl'), legacy apply failed: [Errno 13] Permission denied: '/tmp/e2e-live-policy-omgp9635.policy.yaml'", "enumerate failed ([Errno 13] Permission denied: '/tmp/e2e-enumerate-policy-dir-li59h5tr'), legacy apply failed: [Errno 13] Permission denied: '/tmp/e2e-live-policy-zzmhlr8j.policy.yaml'", "enumerate failed ([Errno 13] Permission denied: '/tmp/e2e-enumerate-policy-dir-m_vjl23_'), legacy apply failed: [Errno 13] Permission denied: '/tmp/e2e-live-policy-5osrroge.policy.yaml'", "enumerate failed ([Errno 13] Permission denied: '/tmp/e2e-enumerate-policy-dir-xi5yxoot'), legacy apply failed: [Errno 13] Permission denied: '/tmp/e2e-live-policy-r41ug0vv.policy.yaml'", "enumerate failed ([Errno 13] Permission denied: '/tmp/e2e-enumerate-policy-dir-yg2dcx8x'), legacy apply failed: [Errno 13] Permission denied: '/tmp/e2e-live-policy-rno471c6.policy.yaml'"]`

## Comparison

- Comparable: `False`
- Reason: `recompile did not apply successfully`

## Limitations

- BPF_PROG_JIT_RECOMPILE did not apply on this kernel; post-ReJIT measurement was skipped.
