# Sequential Authoritative Rerun 2026-03-18

Environment:
- Activated venv: `source /home/yunwei37/workspace/.venv/bin/activate`
- Before each new benchmark: `ps aux | grep -E 'qemu|vng' | grep -v grep`, kill leftovers if needed, then wait 5s
- All VM benchmarks were run sequentially. No overlapping `qemu`/`vng` processes were left running between steps.

## 1. Micro authoritative rerun

Command:

```bash
make vm-micro ITERATIONS=10 WARMUPS=5 REPEAT=1000
```

Result file:
- `micro/results/dev/vm_micro.json`

Analysis method:
- Per-benchmark speedup ratio = `kernel median exec ns / kernel-recompile median exec ns`
- `applied-only` set = benchmarks whose `micro/policies/<bench>.yaml` has non-empty `sites`

Counts:
- total benchmarks: `62`
- applied benchmarks: `7`
- non-applied benchmarks: `55`

Headline metrics:
- overall geomean: `0.980127x`
- applied-only geomean: `1.015919x`
- non-applied geomean: `0.975663x`

Notable applied winners:
- `rotate_dense`: `1.5596x` (`256` sites)
- `cmov_dense`: `1.1416x` (`26` sites)
- `large_mixed_1000`: `1.0114x` (`7` sites)

Notable applied regressors:
- `rotate64_hash`: `0.8120x` (`116` sites)
- `bounds_ladder`: `0.8500x` (`4` sites)
- `bpf_call_chain`: `0.9368x` (`2` sites)

Largest non-applied drift:
- `packet_rss_hash`: `0.4444x`
- `extract_dense`: `1.2817x`
- `load_native_u64`: `0.8068x`

Run-time measurement warnings emitted by the harness:
- CPU governor was `unknown`
- turbo boost enabled
- `perf_event_paranoid=2`
- no CPU affinity set

Decision:
- **Do not promote this run.**
- It fails the requested gate: `applied-only` is only `1.0159x`, not `> 1.10x`.
- `non-applied` drift (`0.9757x`) is also not close enough to `1.0` for a clean authoritative rerun.
- Existing authoritative file was retained: `micro/results/vm_micro_authoritative_20260318.json`
- Current retained authoritative metrics for that file: overall `1.017449x`, applied-only `1.136279x`, non-applied `1.003245x`

## 2. Corpus authoritative rerun

Command:

```bash
make vm-corpus REPEAT=200
```

Result files:
- `corpus/results/dev/vm_corpus.json`
- `corpus/results/dev/vm_corpus.md`

Analysis method:
- Per-program speedup ratio = `speedup_ratio` from result JSON
- `applied-only` set = programs with `v5_run_applied=true` or non-empty `applied_families_run`
- Grouping key = `source_name`

Counts:
- measured pairs: `152`
- applied programs: `61`

Headline metrics:
- overall exec geomean: `0.807143x`
- old authoritative exec geomean: `1.046336x`
- applied-only geomean: `1.079168x`

By source project geomean:
- `linux-selftests`: `0.5590x` (`59` rows, `4` applied)
- `suricata`: `0.8333x` (`1` row, `0` applied)
- `katran`: `0.8987x` (`5` rows, `2` applied)
- `tracee`: `0.9272x` (`2` rows, `2` applied)
- `real_world_code_size`: `0.9760x` (`1` row, `1` applied)
- `xdp-tools`: `0.9926x` (`4` rows, `1` applied)
- `calico`: `0.9929x` (`59` rows, `46` applied)
- `libbpf-bootstrap`: `1.0317x` (`1` row, `1` applied)
- `xdp-tutorial`: `1.1650x` (`20` rows, `4` applied)

Special watch: `calico`
- Source geomean: `0.9929x` with `46/59` rows applied
- Worst rows:
  - `calico_tc_skb_icmp_inner_nat`: `0.2124x`
  - `calico_tc_skb_ipv4_frag`: `0.3704x`
  - `calico_xdp_drop`: `0.3750x`
- Despite several severe outliers, project-level geomean stayed close to neutral because most other rows clustered near `1.0`

Special watch: `katran`
- Source geomean: `0.8987x` with `2/5` rows applied
- Per-program:
  - `healthcheck_encap`: `0.3333x` (no apply)
  - `xdp_root`: `0.4545x` (no apply)
  - `pktcntr`: `1.0000x`
  - `healthcheck_encap`: `1.2500x` (`endian`)
  - `balancer_ingress`: `3.0952x` (`wide,endian`)
- `balancer_ingress` was strongly positive, but `katran` still regressed overall because the other rows dominated the geomean

Decision:
- **Do not promote this run.**
- It fails the requested gate by a wide margin: overall `0.8071x` is far below the old authoritative `1.0463x`.
- No copy was made to `corpus/results/corpus_recompile_authoritative_20260318.json`.

## 3. Tetragon E2E rerun

Makefile check:
- Root `Makefile` has `vm-e2e` only; there is no standalone `vm-tetragon` target.
- `vm-e2e` would also run tracee/bpftrace/xdp, so it was not suitable for the requested single-case rerun.

Guest command actually used:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage \
  --memory 4G \
  --cpus 2 \
  --rwdir /home/yunwei37/workspace/bpf-benchmark \
  -- \
  bash -lc 'cd /home/yunwei37/workspace/bpf-benchmark && \
    source /home/yunwei37/workspace/.venv/bin/activate && \
    python3 e2e/run.py tetragon \
      --output-json /home/yunwei37/workspace/bpf-benchmark/e2e/results/dev/tetragon_20260318.json \
      --output-md /home/yunwei37/workspace/bpf-benchmark/e2e/results/dev/tetragon_20260318.md'
```

Result files:
- `e2e/results/dev/tetragon_20260318.json`
- `e2e/results/dev/tetragon_20260318.md`

Top-level status:
- mode: `tetragon_daemon`
- comparison comparable: `True`
- policy summary: `configured_programs=3`, `fallback_programs=2`

Per-workload results:
- `connect_storm`: app throughput `-20.42%`, events/s `+0.35%`, BPF avg ns `-51.92%`, ops/s `850.37 -> 676.69`
- `file_io`: app throughput `-0.42%`, events/s `+0.79%`, BPF avg ns `+8.34%`, ops/s `1514908.99 -> 1508535.59`
- `open_storm`: app throughput `+0.56%`, events/s `-0.00%`, BPF avg ns `-4.82%`, ops/s `311401.24 -> 313135.87`
- `stress_exec`: app throughput `+4.60%`, events/s `+4.55%`, BPF avg ns `+1.26%`, ops/s `239.28 -> 250.29`

Aggregate deltas:
- app throughput geomean: `0.955479x`
- events/s geomean: `1.014044x`
- BPF avg ns geomean: `0.841759x`

Interpretation:
- `stress_exec` is clearly positive.
- `open_storm` is effectively neutral-to-slightly-positive.
- `file_io` is roughly flat on app throughput and slightly worse on BPF avg ns.
- `connect_storm` is still the dominant negative outlier on app throughput, consistent with earlier noise concerns around that workload.

## 4. Tracee E2E rerun (optional)

First attempt command:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage \
  --memory 4G \
  --cpus 2 \
  --rwdir /home/yunwei37/workspace/bpf-benchmark \
  -- \
  bash -lc 'cd /home/yunwei37/workspace/bpf-benchmark && \
    source /home/yunwei37/workspace/.venv/bin/activate && \
    python3 e2e/run.py tracee \
      --output-json /home/yunwei37/workspace/bpf-benchmark/e2e/results/dev/tracee_20260318.json \
      --output-md /home/yunwei37/workspace/bpf-benchmark/e2e/results/dev/tracee_20260318.md'
```

Failure:
- Guest run failed immediately inside `tracee` case logic.
- Root cause from traceback: `bpftool -j -p prog show` failed because the guest fell back to Ubuntu's `/usr/sbin/bpftool` wrapper and did not have the matching kernel-version `linux-tools-*` package installed.

Attempted fix:
- Mounted host `/usr/local/sbin` into the guest
- Prepended `/usr/local/sbin` to guest `PATH`
- Retried the same `tracee` command

Second attempt result:
- `vng` exited with code `255`
- no `e2e/results/dev/tracee_20260318.json`
- no `e2e/results/dev/tracee_20260318.md`

Decision:
- **Tracee rerun remains incomplete / environment-blocked.**
- I stopped after one targeted environment fix instead of continuing to churn the optional step.

## Promotion summary

Promoted to new authoritative:
- none

Retained existing authoritative files:
- `micro/results/vm_micro_authoritative_20260318.json`
- `corpus/results/corpus_recompile_authoritative_20260313.json`

New dev artifacts produced:
- `micro/results/dev/vm_micro.json`
- `corpus/results/dev/vm_corpus.json`
- `corpus/results/dev/vm_corpus.md`
- `e2e/results/dev/tetragon_20260318.json`
- `e2e/results/dev/tetragon_20260318.md`
