# KVM x86 corpus round 5 follow-up

Date: 2026-05-01

## Round 5 result

Round 5 log source:

`/tmp/vm-corpus.log`

Observed failures:

- Calico baseline failed at `/tmp/vm-corpus.log:135` with `network wrk load failed: unable to connect to 198.18.0.2:18080 Cannot assign requested address`.
- Cilium baseline failed at `/tmp/vm-corpus.log:153` with the same `wrk` error.
- Tetragon reached `rejit_start program_count=287` at `/tmp/vm-corpus.log:162`, then the outer `vng` subprocess hit its 7200s timeout at `/tmp/vm-corpus.log:196`.

The Tetragon timeout is a round 4 regression from making every original verifier-state capture eligible for a full 60s. Worst case is `287 * 60s = 17220s`, far beyond the outer 2h VM cap.

## Bug A: Tetragon verifier-state timeout amplification

Root cause:

- `const_prop` needs original verifier states, so the daemon runs `bpfverify --verifier-states-out` once per program before `bpfopt optimize`.
- Commit `7c768acd` raised `bpfverify original verifier-states` from 5s to 60s to avoid killing genuinely verifier-heavy programs.
- That fixed single heavy programs but made large app sets unsafe. Tetragon exposed 287 programs, so a bounded per-program 60s stage can still exceed the outer `vng` 2h timeout.
- The old command also requested `--report` and `--output` while capturing verifier states. For preserved Tetragon-like failures, verifier logs are 17MB and include high verifier work, for example prog 420 has `processed 172996 insns (limit 1000000)`. Serializing those reports for every program is not needed by `const_prop`.

Fix:

- `daemon/src/commands.rs` now treats original verifier-state capture separately from final verification.
- Original verifier-state capture uses a bounded ramp: `5s -> 30s -> 60s`. A non-timeout verifier error still fails immediately and is recorded for the program.
- The original verifier-state command no longer asks for `--report` or `--output`; it only requires a nonempty `verifier-states.json`.
- Final verification, post-failure report capture, `bpfopt optimize`, and `bpfrejit` keep their 60s bounded timeout.

This does not skip or filter any ReJIT program. If a program still fails all verifier-state attempts, the daemon records the failure normally.

Host reproduction/checks:

- `/tmp/vm-corpus.log` shows Tetragon got as far as `rejit_start program_count=287` before the outer 7200s kill.
- Older preserved Tetragon-like verifier logs under `corpus/results/x86_kvm_p89_kinsn_corpus_20260430_131403_981524/details/failures/` are 17MB each; prog 420 has `insn_cnt=2174`, 13 maps, and verifier output `processed 172996 insns`.
- Direct host replay of prog 420 with `bpfverify --verifier-states-out` is blocked by host capabilities: `BPF_MAP_CREATE: Operation not permitted`. The command path was still useful to confirm the replay boundary.
- Unit coverage now verifies that verifier-state capture does not request full reports and that the first timeout is back to 5s with a 5/30/60 ramp.

## Bug B: Calico/Cilium `wrk` client path

Root cause:

- Round 4 only tested `_network_client_command()` directly.
- The actual corpus path is `CalicoRunner._run_workload()` / `CiliumRunner._run_workload()` -> `run_named_workload(..., network_device=self.device)` -> `run_network_load()`.
- Without a direct test on the runner measurement path, a missing device or alternate call path can silently run a bare `wrk` from the wrong namespace.
- Round 5 error text did not include the executed command, so the VM log could not prove whether `ip netns exec bpfbenchns` was actually used.

Fix:

- Calico and Cilium workload entry points now fail fast if no benchmark device has been determined before measurement.
- Python tests now cover the actual Calico/Cilium runner measurement methods and the `get_app_runner()` corpus adapter path, and assert they pass `network_device=BENCHMARK_IFACE`.
- `run_network_load()` and interface-bound `run_tcp_connect_load()` now include the rendered client command in failure messages. If the VM still fails, the log will show whether the command is `ip netns exec bpfbenchns wrk ...` or a bare `wrk ...`.

Host reproduction/checks:

- Host has `/usr/sbin/ip`, `/usr/bin/wrk`, and `/usr/bin/curl`.
- Host does not have an active `bpfbench0` or `bpfbenchns`, so full network reproduction is VM-only here.
- The mini Python test directly exercises the Calico/Cilium runner measurement path and the namespace-command error message path.

## Tests

Narrow tests run during the fix:

- `PYTHONPATH=. python3 -m unittest discover -s tests/python -p 'test_workload.py'`: passed, 9 tests
- `cd daemon && cargo test verifier_states -- --nocapture`: passed, 4 tests
- `cd daemon && cargo test verifier_and_optimizer_stages_have_heavy_timeouts -- --nocapture`: passed, 1 test

Full requested verification:

- `cd bpfopt && cargo test --workspace`: passed
- `make daemon-tests`: passed, 41 tests
- `PYTHONPATH=. python3 -m unittest discover -s tests/python`: passed, 9 tests

I did not run `make vm-corpus`, `make vm-e2e`, or `make vm-micro`.

## Claude handoff

请 Claude 跑 `make vm-corpus`。重点看：

- Calico/Cilium 如仍失败，错误里应包含实际 client command；确认是否为 `ip netns exec bpfbenchns wrk ...`。
- Tetragon `rejit_start program_count=287` 后不应再被外层 7200s `vng` timeout 杀死。
- Daemon stderr 若出现 verifier-state timeout，应看到 `5s` 后重试 `30s`，再到 `60s`；非 timeout 的 verifier/rejit 错误仍应作为 program failure 自然记录。
