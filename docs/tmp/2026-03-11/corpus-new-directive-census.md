# Corpus New Directive Census

Date: 2026-03-11

## Summary

- Old live baseline from `docs/tmp/corpus-runnability-report.md`:
  - `532` objects
  - `1836` programs
  - `1214` loadable programs
  - `274` programs with directive sites
  - `381` truly runnable programs
  - `79` packet paired baseline/recompile programs
- Important clarification: the old `274` is a **program** count, not an object count.
  - The same March 11 JSON has `69` discovered objects with sites.
- `python3 corpus/directive_census.py` is stale for this task.
  - It still reports `496` objects and `3073` candidate sites.
  - It does not include `bitfield_extract`, and it does not use the current scanner CLI.
- Latest scanner-backed raw census over the full `corpus/build` snapshot finds `143 / 560` objects with sites and `14593` total sites.
- On the same 532-object runnability set, the new scanner-backed raw census finds `127` objects with sites.
  - `62` objects were `0` before and are now `>0`.
  - `23` of those were already loadable in the old runnability pass.
  - `8` of those were already truly runnable.
- Latest framework-kernel VM smoke passes for:
  - `rotate64_hash`
  - `bitfield_extract`
  - `corpus/build/katran/balancer.bpf.o`
  - `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp`
  - `corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main`

## Methodology

- The current scanner CLI is v5-only and accepts only `--prog-fd` or `--xlated`.
- The task-text shorthand `bpf-jit-scanner scan <object>` does not work on this tree.
- For raw corpus coverage, I scanned executable non-dot ELF sections by feeding their BPF instruction bytes to `bpf-jit-scanner scan --xlated --all --v5`.
- For the old-vs-new comparison, I used two views:
  - full raw corpus census on all `EM_BPF` objects under `corpus/build`
  - a second raw census on the exact 532-object set from `docs/tmp/corpus-runnability-results.json`
- For VM smoke, I booted `vendor/linux-framework/arch/x86/boot/bzImage` with `vng` and used `micro_exec run-kernel` for live load / dump-xlated / recompile checks.

## Full Scanner Census

### Full `corpus/build` raw census

| Metric | Value |
| --- | ---: |
| EM_BPF objects scanned | 560 |
| Objects with sites | 143 |
| Total sites | 14593 |

| Family | Sites | Objects |
| --- | ---: | ---: |
| `cmov` | 9383 | 130 |
| `wide` | 2832 | 32 |
| `rotate` | 1820 | 3 |
| `lea` | 14 | 7 |
| `extract` | 544 | 41 |

Notes:

- `bitfield_extract = 544` matches the earlier implementation report.
- `wide = 2832` is slightly below the previously recorded `2835`.
  - The delta is small enough that the most likely causes are corpus snapshot drift or section-filter differences.
  - I would not treat `2835` as the current authoritative number without rerunning on the exact earlier snapshot.

### Top coverage objects

Top `extract` objects:

| Object | Extract | Total |
| --- | ---: | ---: |
| `corpus/build/cilium/bpf_lxc.bpf.o` | 138 | 474 |
| `corpus/build/tracee/tracee.bpf.o` | 49 | 3469 |
| `corpus/build/cilium/bpf_overlay.bpf.o` | 32 | 202 |
| `corpus/build/loxilb/llb_ebpf_emain.bpf.o` | 32 | 989 |
| `corpus/build/loxilb/llb_ebpf_main.bpf.o` | 32 | 989 |
| `corpus/build/cilium/bpf_xdp.bpf.o` | 28 | 489 |

Top `wide` objects:

| Object | Wide | Total |
| --- | ---: | ---: |
| `corpus/build/loxilb/llb_ebpf_emain.bpf.o` | 863 | 989 |
| `corpus/build/loxilb/llb_ebpf_main.bpf.o` | 863 | 989 |
| `corpus/build/tracee/tracee.bpf.o` | 229 | 3469 |
| `corpus/build/tetragon/bpf_generic_usdt.bpf.o` | 155 | 440 |
| `corpus/build/tetragon/bpf_generic_uprobe.bpf.o` | 98 | 430 |
| `corpus/build/tetragon/bpf_generic_kprobe.bpf.o` | 88 | 420 |

Top `cmov` objects:

| Object | Cmov | Total |
| --- | ---: | ---: |
| `corpus/build/tracee/tracee.bpf.o` | 3191 | 3469 |
| `corpus/build/tetragon/bpf_generic_lsm_core.bpf.o` | 1648 | 1725 |
| `corpus/build/coroot-node-agent/ebpf.bpf.o` | 910 | 942 |
| `corpus/build/cilium/bpf_xdp.bpf.o` | 461 | 489 |
| `corpus/build/cilium/bpf_lxc.bpf.o` | 336 | 474 |

Raw `rotate` coverage is still concentrated:

| Object | Rotate |
| --- | ---: |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o` | 992 |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o` | 818 |
| `corpus/build/calico/from_hep_debug.bpf.o` | 10 |

## Old vs New Coverage

### Same 532-object runnability set

| Metric | Old live runnability | New raw scanner census |
| --- | ---: | ---: |
| Objects considered | 532 attempted / 433 discovered | 532 scanned |
| Objects with sites | 69 discovered objects | 127 objects |
| Programs with sites | 274 | n/a |
| CMOV sites | 840 | 6508 |
| WIDE sites | 389 | 2237 |
| ROTATE sites | 1840 | 1820 |
| LEA sites | 0 | 2 |
| EXTRACT sites | n/a | 439 |

Important caveat:

- This is **not** a pure apples-to-apples family-total comparison.
- The old numbers are from live loaded xlated programs.
- The new numbers above are from raw object-section scanning on the same object set.
- The useful comparison here is object coverage, not exact family totals.

### Newly positive objects

On the 532-object runnability set:

- New scanner raw census finds `127` objects with sites.
- Old runnability JSON had `69` discovered objects with sites.
- Net increase: `+58` objects with sites.
- Exact transitions:
  - `62` objects were old `0` and are now new `>0`
  - `11` objects were old live-positive but are raw-zero now
  - `7` additional site-bearing objects are inventory-failure objects that the old runnability pass could not open/load

The `11` old-live-positive / new-raw-zero cases are concentrated in BCC tracing tools (`fsdist`, `tcpsynbl`, `runqlat`, `biolatency`, `tcprtt`, `funclatency`, `filetop`, `ksnoop`, `filelife`) plus two selftests.

Interpretation:

- I do **not** read these 11 as a scanner regression.
- They are much more likely a raw-ELF vs live-xlated mismatch.
- The Katran smoke below demonstrates that the reverse can also happen: live xlated can expose more sites than the raw object census (`balancer`: raw `14`, live `34`).

### Runnable objects that were previously site-free

These objects were already truly runnable in the March 11 runnability pass but now show nonzero sites in the new scanner-backed census:

| Object | Total | Cmov | Wide | Rotate | Lea | Extract |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/res_spin_lock.bpf.o` | 3 | 3 | 0 | 0 | 0 | 0 |
| `corpus/build/libbpf-bootstrap/examples/c/bootstrap.bpf.o` | 1 | 0 | 0 | 0 | 0 | 1 |
| `corpus/build/libbpf-bootstrap/examples/c/bootstrap_legacy.bpf.o` | 1 | 0 | 0 | 0 | 0 | 1 |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/cpumask_success.bpf.o` | 1 | 1 | 0 | 0 | 0 | 0 |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_metadata.bpf.o` | 1 | 1 | 0 | 0 | 0 | 0 |
| `corpus/build/real_world_code_size/libbpf-bootstrap/bootstrap.bpf.o` | 1 | 0 | 0 | 0 | 0 | 1 |
| `corpus/build/real_world_code_size/libbpf-bootstrap/bootstrap_legacy.bpf.o` | 1 | 0 | 0 | 0 | 0 | 1 |
| `corpus/build/xdp-tutorial/packet-solutions/tc_reply_kern_02.bpf.o` | 1 | 0 | 0 | 0 | 0 | 1 |

High-value blocked objects that still do not have a load/discovery path but now show lots of sites:

| Object | Total | Cmov | Wide | Rotate | Extract | Note |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| `corpus/build/cilium/bpf_xdp.bpf.o` | 489 | 461 | 0 | 0 | 28 | inventory failure in old runnability |
| `corpus/build/cilium/bpf_lxc.bpf.o` | 474 | 336 | 0 | 0 | 138 | inventory failure in old runnability |
| `corpus/build/cilium/bpf_overlay.bpf.o` | 202 | 170 | 0 | 0 | 32 | inventory failure in old runnability |
| `corpus/build/opentelemetry-ebpf-profiler/native_stack_trace.bpf.o` | 16 | 16 | 0 | 0 | 0 | inventory failure |
| `corpus/build/scx/scx_lavd_main.bpf.o` | 9 | 8 | 0 | 0 | 1 | inventory failure |

## VM Smoke Test

### Build status

| Step | Result | Notes |
| --- | --- | --- |
| `make -j$(nproc) bzImage` in `vendor/linux-framework` | pass | `Kernel: arch/x86/boot/bzImage is ready (#18)` |
| `make -C micro micro_exec` | pass after local fix | `micro_exec` had drifted against removed v4 scanner APIs; fixed locally by migrating runner autoscan to v5-only scanner APIs |

The guest reported:

- Kernel release: `7.0.0-rc2-ga99cd78eddd5-dirty`

### Smoke results

| Target | Result | Key output |
| --- | --- | --- |
| `micro/programs/simple.bpf.o` runtime | fail | `required maps input_map/result_map not found` |
| `micro/programs/rotate64_hash.bpf.o` staged runtime | pass | `exec_ns=331`, `result=2666935177028490406`, `native_code_size=3555`, `xlated_prog_len=7984` |
| `rotate64_hash` guest xlated scan | pass | `wide=8`, `rotate=115`, total `123` |
| `rotate64_hash` guest recompile | pass | `applied=true`, `policy_bytes=22660`, `native_code_size 3555 -> 2309` |
| `micro/programs/bitfield_extract.bpf.o` guest xlated scan | pass | `wide=2`, `extract=9`, total `11` |
| `bitfield_extract` guest recompile | pass | `applied=true`, `policy_bytes=1428`, `native_code_size 1087 -> 1073` |
| `corpus/build/katran/balancer.bpf.o` guest xlated scan | pass | `cmov=8`, `wide=4`, `rotate=20`, `extract=2`, total `34` |
| `katran/balancer` guest recompile | pass | `applied=true`, `policy_bytes=6248` |
| `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o:syncookie_xdp` guest xlated scan | pass | `cmov=4`, `wide=3`, `extract=8`, total `15` |
| `xdp_synproxy:syncookie_xdp` guest recompile | pass | `applied=true`, `policy_bytes=2020` |
| `corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main` guest xlated scan | pass | `cmov=20`, `wide=12`, `extract=1`, total `33` |
| `calico_tc_main` guest recompile | pass | `applied=true`, `policy_bytes=4332` |

Notes:

- The original task text asked for `calico_connect4.bpf.o`, but that object does not exist in the current workspace.
- I substituted `corpus/build/calico/from_hep_debug.bpf.o:calico_tc_main`, which is present and recompiled successfully.
- The current scanner CLI still does not accept raw `.bpf.o` paths directly, so guest scan smoke used dumped xlated bytecode rather than `scan <object>`.

## Recommendations

- Yes, rerun corpus recompile / runnability with the latest scanner.
  - `bitfield_extract` alone adds `544` full-corpus raw sites across `41` objects.
  - On the runnability object set, `62` old-zero objects now show sites.
  - VM smoke confirms the latest kernel accepts and applies those policies on representative micro and corpus objects.
- Treat the current raw census as a **coverage expansion signal**, not the final acceptance result.
  - Live xlated counts can differ materially from raw object-section counts.
  - `balancer` is the clearest example: raw census saw `14`, guest live xlated scan saw `34`.
- Prioritize loader / harness work for high-yield blocked objects.
  - Cilium is the biggest upside: `bpf_xdp`, `bpf_lxc`, `bpf_overlay` alone contribute `1165` raw sites.
  - Loxilb and Tetragon also have dense site coverage but still need a robust load path in the corpus harness.
- Replace or rewrite `corpus/directive_census.py`.
  - Right now it materially undercounts coverage and omits `bitfield_extract`.
  - It should be replaced with a scanner-backed v5 census that uses `--xlated` or live `--prog-fd`.
- Update task/docs examples that still say `bpf-jit-scanner scan <object>`.
  - The current scanner CLI is `--prog-fd` / `--xlated` only.
- Fix or replace the `simple.bpf.o` smoke command in docs.
  - On the current runner/kernel combination it fails with `required maps input_map/result_map not found`.
  - `rotate64_hash` or `log2_fold` staged runs are better smoke targets today.

## Bottom Line

- The current corpus is already in a state where a full rerun is justified.
- The latest scanner clearly expands coverage, especially through `bitfield_extract` and additional previously site-free objects.
- The latest framework kernel passes the key smoke tests and successfully applies v5 recompile policies on both micro workloads and representative real corpus objects.
