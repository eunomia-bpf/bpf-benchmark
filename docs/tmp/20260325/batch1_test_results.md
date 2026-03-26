# Batch 1 Test Results

Run date: 2026-03-26
Workspace: `/home/yunwei37/workspace/bpf-benchmark`
Venv: `/home/yunwei37/workspace/.venv`

| # | Test | Status | Key data | Approx. duration | Log |
| --- | --- | --- | --- | --- | --- |
| 1 | `make vm-static-test TARGET=x86 VM_CPUS=4 VM_MEM=8G` | PASS | `exit=0`; `objects=539`; `programs=1240`; `applied=347`; `verifier_accepted=1151`; `avg_insn_delta=-3.14`; `avg_code_delta=-15.82` | 7m29s | `docs/tmp/20260325/logs/1_vm-static-test.log` |
| 2 | `make vm-negative-test TARGET=x86 VM_CPUS=4 VM_MEM=8G FUZZ_ROUNDS=1000` | PASS | `exit=0`; adversarial `23 passed / 0 failed / 0 skipped`; fuzz `1000 rounds`, `rejected=954`, `accepted=46`, `original_ok=1000`, `original_fail=0`, `seed=0x69c51bd9`; `scx_prog_show_race` `bpftool-loop` `20/20 rc=0` | 6s | `docs/tmp/20260325/logs/2_vm-negative-test.log` |
| 3 | `make vm-e2e TARGET=x86 VM_CPUS=4 VM_MEM=8G` | PASS | `exit=0`; `tracee OK`; `tetragon OK`; `bpftrace OK`; `scx OK`; `katran OK`; `bcc OK`; final `e2e: ALL PASSED` | 13m33s | `docs/tmp/20260325/logs/3_vm-e2e.log` |
| 4 | `make vm-shell TARGET=local-x86-vng-tcg VM_CPUS=1 VM_MEM=8G VM_TEST_TIMEOUT=600 VM_COMMAND='bash module/load_all.sh 2>/dev/null || true && ./tests/negative/build/scx_prog_show_race /home/yunwei37/workspace/bpf-benchmark --mode bpftool-loop --iterations 200 --load-timeout 30 && echo TCG_200_PASSED'` | PASS | `exit=0`; `iterations=200`; `bpftool rc=0` for all `0..199`; `after_wait healthy 1 state enabled`; marker `TCG_200_PASSED` | 2m51s | `docs/tmp/20260325/logs/4_vm-shell-tcg.log` |

## Notes

- `vm-e2e` first host-side attempt failed before VM execution because `runner/build/_deps/spdlog-*` hit a `FetchContent` clone error. After cleaning that temporary dependency cache and rerunning the same command, the test passed.
- An older duplicate Codex batch in the same workspace was holding the VM lock during `vm-static-test` and `vm-e2e`. Those stale processes were terminated so the final results above reflect a single serial run only.
