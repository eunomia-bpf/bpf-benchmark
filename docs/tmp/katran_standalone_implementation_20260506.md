# Katran Standalone Attach Implementation

Date: 2026-05-06 local time.

## Diff Summary

Touched file:

```text
runner/libs/app_runners/katran.py | 178 ++++++++++----------------------------
1 file changed, 45 insertions(+), 133 deletions(-)
```

Functional changes:

- Removed the runner-managed shared-root path from `katran.py`: no `_install_root_xdp_program()`, no root-map pinning, no `-map_path=...`, and no `-prog_pos=...`.
- `katran_server_grpc` now starts in upstream standalone mode and still loads the real upstream `balancer.bpf.o`.
- Added `-hc_forwarding=false` so the healthcheck forwarding program is not loaded for the LB-only smoke.
- `reattach_xdpgeneric()` now reattaches the discovered `balancer_ingress` program id and validates both attach mode and program id.
- Cleanup now detaches all XDP attach modes through `_detach_all_xdp_modes()`.

Note: the current file diff also includes pre-existing/concurrent workload-detail changes in the same file (`error_count` and extra workload fields). I preserved those and did not revert them.

## bpftool net show Output

Before fix: no verbatim `bpftool net show dev katran0` output was available. The investigation report notes that saved artifacts did not persist a net-show dump.

After fix: no verbatim `bpftool net show dev katran0` output was available from the completed `make corpus` run. The framework tears down `katran0` before the host can query it after `make corpus` exits, and I did not add attach metadata to `result.json` because the benchmark framework is supposed to keep result payloads to raw counters/status/workload output.

The pre-change runner attached `xdp_root` directly and passed Katran `-map_path`/`-prog_pos`; the raw counter evidence from `corpus/results/x86_kvm_corpus_20260507_025319_683029` confirms top-level attribution on `xdp_root`:

```text
phase        program            id   run_cnt_delta
baseline     xdp_root           531  327649
baseline     balancer_ingress   537  0
post_rejit   xdp_root           531  323215
post_rejit   balancer_ingress   537  0
```

After fix, the final smoke reported `program_count: 1` at ReJIT start, and the app JSON contains only `balancer_ingress` in both phases, with no `xdp_root` or `healthcheck_encap` rows:

```text
phase        program            id   run_cnt_delta
baseline     balancer_ingress   9    112122
post_rejit   balancer_ingress   9    101772
```

## Final Smoke

Command:

```bash
BPFREJIT_CORPUS_APPS=katran SAMPLES=1 make corpus
```

Final run directory:

```text
/home/yunwei37/workspace/bpf-benchmark/corpus/results/x86_kvm_corpus_20260507_034154_267803
```

Result:

```text
app status: ok
baseline requests: 18687/18687 success, error_count=0
post_rejit requests: 16962/16962 success, error_count=0
balancer_ingress baseline run_cnt_delta: 112122
balancer_ingress post_rejit run_cnt_delta: 101772
```

## Followups

- If a verbatim `bpftool net show dev katran0` transcript is required, capture it as debug-only stdout during the live VM run. Do not add it to result payloads.
- ReJIT still records a per-program optimizer error in `const_prop` for `balancer_ingress`; the app-level smoke remains `ok`, and raw baseline/post counters are collected.
- `runner/suites/_common.py` and image build validation still require `xdp_root.bpf.o` as an artifact, but `katran.py` no longer uses it at runtime.
