# KVM x86 corpus round 6 follow-up

Date: 2026-05-01

## Round 6 result

Round 6 log source:

`/tmp/vm-corpus.log`

Observed failures:

- `bcc/*` completed successfully through `bcc/runqlat`.
- `calico/felix` baseline failed with:
  `network wrk load failed via /usr/sbin/ip netns exec bpfbenchns /usr/bin/wrk -t2 -c10 -d1s http://198.18.0.2:18080/: unable to connect to 198.18.0.2:18080 Cannot assign requested address`
- `otelcol-ebpf-profiler/profiling` completed successfully.
- `cilium/agent` baseline failed with the same namespaced `wrk` error.
- `tetragon/observer` reached `rejit_start program_count=287`, then the outer `vng` command hit its 7200s timeout.

## Bug A: Tetragon verifier-state timeout ramp

Root cause:

- Commit `e9c6bf69` changed original verifier-state capture to a per-program ramp of `5s -> 30s -> 60s`.
- The ramp restarts for every program. Worst case for Tetragon is `287 * (5 + 30 + 60) = 27265s`, which exceeds the outer 7200s VM timeout before later apps can run.
- The daemon already records a per-program optimize error when `bpfverify --verifier-states-out` fails or times out. A 5s verifier-state cap therefore does not filter ReJIT; each program is attempted and failures surface in the result payload.

Fix:

- Removed the verifier-state timeout ramp and its retry helper.
- `bpfverify original verifier-states` now uses the normal stage timeout: fixed 5s.
- Final verification, post-rejit failure report capture, `bpfopt optimize`, and `bpfrejit` keep their 60s bounded timeouts.
- Added `verifier_states_timeout_is_not_retried`, which uses a 50ms fake verifier-state timeout and asserts only one `--verifier-states-out` subprocess is attempted.

Host reproduction:

- Round 6 `/tmp/vm-corpus.log` confirms Tetragon was killed after `rejit_start program_count=287`.
- Replay attempts against preserved Tetragon-like prog 420 artifacts were blocked by host/kernel replay boundaries:
  - user dummy-map replay: `BPF_MAP_CREATE: Operation not permitted`
  - sudo dummy-map replay: `BPF_MAP_CREATE: Invalid argument` for a VM-specific map type/layout
  - sudo live-map replay: `BPF_MAP_GET_FD_BY_ID: No such file or directory`
- The actionable host-side check is therefore the daemon timeout contract test above plus the observed round6 timeout amplification math.

## Bug B: Calico/Cilium namespaced network EADDRNOTAVAIL

Root cause:

- `198.18.0.2` comes from `runner/libs/benchmark_net.py` as `BENCHMARK_PEER_IFACE_CIDR`.
- The server is `NamespacedHttpServer(BENCHMARK_NETNS, BENCHMARK_PEER_IFACE_IP)`, so it starts inside `bpfbenchns` and binds `198.18.0.2:18080`.
- The client also correctly runs inside `bpfbenchns`; round 6 proved the command is not a bare host `wrk`.
- Minimal namespace setup with `198.18.0.2/30` works for one `wrk` run.
- The real failure reproduces when running many 1s `wrk` samples against the same namespace endpoint: the old handler responded as HTTP/1.0, so `wrk` opened and closed thousands of short TCP connections per sample. By sample 23, the namespace hit local port/TIME_WAIT pressure and `wrk` failed with the same `Cannot assign requested address`.

Fix:

- Set both workload HTTP handlers to HTTP/1.1:
  - `LocalHttpServer` handler
  - `NamespacedHttpServer` inline Python handler
- The server already sends `Content-Length`, so HTTP/1.1 lets `wrk` reuse its connection pool instead of creating a new TCP connection per request.
- Client remains inside `bpfbenchns`; no host namespace rollback.

Host reproduction:

- One-shot namespace server/client:
  - `ip netns add bpfbenchns`
  - veth `bpfbench0`/`bpfbench1`
  - `198.18.0.1/30` on root side, `198.18.0.2/30` inside namespace
  - `ip netns exec bpfbenchns python3 -m http.server --bind 198.18.0.2 18080`
  - `ip netns exec bpfbenchns wrk -t2 -c10 -d1s http://198.18.0.2:18080/`
  - Result: one run succeeds.
- Failure shape before the fix:
  - repeated `wrk -t2 -c10 -d1s` against the namespace server failed at sample 23 with `Cannot assign requested address`.
- Patched check:
  - repeated `run_network_load(1, network_device=bpfbench0)` for 40 samples completed without `EADDRNOTAVAIL`.

## Tests

Passed:

- `cd daemon && cargo test verifier_states -- --nocapture`
- `PYTHONPATH=. python3 -m unittest discover -s tests/python -p 'test_workload.py'`
- `cd bpfopt && cargo test --workspace`
- `make daemon-tests` (`42 passed`)
- `PYTHONPATH=. python3 -m unittest discover -s tests/python` (`10 passed`)

Did not run:

- `make vm-corpus`
- `make vm-e2e`
- `make vm-micro`

## Claude handoff

请 Claude 跑 `make vm-corpus`。预期变化：

- Calico/Cilium baseline should no longer fail with namespaced `wrk` `EADDRNOTAVAIL`.
- Tetragon should no longer spend up to 95s per program in verifier-state capture. Programs whose verifier-state capture exceeds 5s should return per-program errors and the corpus should continue to later apps.
