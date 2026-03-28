# E2E And Katran Post All Fixes 20260328

## Scope

- Date: `2026-03-28`
- Repo: `/home/yunwei37/workspace/bpf-benchmark`
- Build prep:
  - `rm -f .cache/runner/vm-locks/vm_global.lock .cache/runner/vm-queue/vm_global.json`
  - `make daemon`
  - `make runner`
- E2E command:
  - `make vm-e2e TARGET=x86`
- Katran targeted corpus command:
  - `make vm-corpus TARGET=x86 PROFILE=ablation_map_inline_full FILTERS='katran:balancer.bpf.o:balancer_ingress'`
- E2E/pass config source:
  - `corpus/config/benchmark_config.yaml`

## Build Logs

- `make daemon`: `docs/tmp/20260328/e2e_postfix_make_daemon_20260328.log`
- `make runner`: `docs/tmp/20260328/e2e_postfix_make_runner_20260328.log`
- `make vm-e2e TARGET=x86`: `docs/tmp/20260328/e2e_postfix_vm_e2e_20260328.log`
- `make vm-corpus ...katran...`: `docs/tmp/20260328/e2e_postfix_vm_corpus_katran_20260328.log`

## E2E Overall Status

- `make vm-e2e TARGET=x86` finished with exit code `0`.
- Console summary: `tracee OK`, `tetragon OK`, `bpftrace OK`, `scx OK`, `katran OK`, `bcc OK`, `e2e: ALL PASSED`.

## E2E Artifact Set

- Tracee: `e2e/results/tracee_20260328_204309/details/result.json`
- Tetragon: `e2e/results/tetragon_20260328_205300/details/result.json`
- bpftrace: `e2e/results/bpftrace_20260328_205451/details/result.json`
- scx: `e2e/results/scx_20260328_210228/details/result.json`
- Katran: `e2e/results/katran_20260328_210414/details/result.json`
- BCC: `e2e/results/bcc_20260328_210559/details/result.json`

## Key Checks

### 1. Tetragon

- Case status: `ok`
- Comparison: `comparable = false`
- Comparison reason: `rejit did not apply successfully`
- `rejit_result.applied = false`, `exit_code = 1`
- Result summary no longer fails the whole case, but raw `rejit_result.output` still contains:
  - `BPF_PROG_REJIT: Permission denied (os error 13)`

Conclusion:

- `Permission denied` did **not** fully disappear.
- The case itself completes, but ReJIT still fails on the Tetragon path, so this fix is not sufficient yet.

### 2. Katran E2E

- Case status: `ok`
- BPF speedup ratio: `1.077956368362177x`
- Throughput delta: `+9.9256%`
- Latency p99 delta: `-16.9459%`
- Live scan for `balancer_ingress` shows:
  - `total_sites = 12`
  - `map_inline_sites = 6`
  - `endian_fusion = 2`
  - `wide_mem = 4`
  - site summary: `map_inline=6 endian_fusion=2 wide_mem=4`

Conclusion:

- Katran is no longer at the old `2`-site state, but it is still far from the expected `40+`.
- `wide_mem` and `endian_fusion` are still present in the live E2E path.

### 3. BCC

- Case status: `ok`
- `baseline_successes = 10`
- `rejit_successes = 10`
- `tools_with_sites = 9`
- aggregate sites:
  - `total_sites = 3186`
  - `map_inline = 184`
  - `const_prop = 301`
  - `dce = 2693`
- geomean speedup: `1.0228642682060618x` (`1.023x` in markdown report)

## Per-Case E2E Status

| Case | Status | Notes |
| --- | --- | --- |
| tracee | `ok` | completed successfully |
| tetragon | `ok` | case completes, but ReJIT still fails and raw output still shows `Permission denied` |
| bpftrace | `ok` | completed successfully |
| scx | `ok` | completed successfully |
| katran | `ok` | live scan only `12` sites total, `map_inline=6` |
| bcc | `ok` | geomean `1.023x` |

## Katran Targeted Corpus

- Artifact dir:
  - `runner/corpus/results/vm_corpus_20260328_212026/`
- Result files:
  - `runner/corpus/results/vm_corpus_20260328_212026/metadata.json`
  - `runner/corpus/results/vm_corpus_20260328_212026/details/result.json`
  - `runner/corpus/results/vm_corpus_20260328_212026/details/result.md`

### Summary

- status: `completed`
- profile: `ablation_map_inline_full`
- objects: `1`
- programs: `1`
- compile pairs: `1`
- measured pairs: `1`
- applied programs: `0`
- code-size ratio geomean: `1.0027904244382435x` (`1.003x`)
- exec-time ratio geomean: `1.1x`
- rejit failure reasons:
  - `daemon socket optimize failed: invalid daemon JSON: missing JSON key: verifier_retries` = `2`

### Katran Object / Program Data

- object: `katran:balancer.bpf.o`
- program: `katran:balancer.bpf.o:balancer_ingress`
- object status: `ok`
- stock compile ns: `253814775`
- rejit compile ns: `111516979`
- baseline JIT bytes: `13656`
- rejit JIT bytes: `13618`
- baseline exec ns: `11`
- rejit exec ns: `10`
- exec ratio: `1.100x`

### Sites

- `sites_applied = 0` in both compile/run `rejit` summaries
- `sites_found` is **not available** in this run's persisted corpus result

Why `sites_found` is missing:

- The targeted corpus run hit a new runner/daemon schema mismatch:
  - `daemon socket optimize failed: invalid daemon JSON: missing JSON key: verifier_retries`
- Because the daemon response was rejected during parse, this artifact does not retain usable `pass_details`, so `sites_found` was not recorded for `balancer_ingress` even though execution timing was still captured.

## Bottom Line

- E2E suite itself is green: all six cases completed and `make vm-e2e TARGET=x86` returned `0`.
- Tetragon is **not fixed** at the requested bar: raw ReJIT output still includes `BPF_PROG_REJIT: Permission denied`.
- Katran live E2E coverage improved from the old `2`-site state to `12` total live sites, but only `6` are `map_inline`; `wide_mem` and `endian_fusion` are still active.
- BCC is healthy and currently shows `1.023x` geomean.
- Katran targeted corpus does **not** confirm the desired `40+` `map_inline` state; instead it records `sites_applied = 0` and is blocked by a daemon JSON/schema issue before `sites_found` can be persisted.
