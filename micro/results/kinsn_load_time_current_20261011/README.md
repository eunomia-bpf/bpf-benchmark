# Kernel-side load time of the 62 paper micro programs with and without kinsn (2026-10-11)

Re-measurement of the ATC'26 camera-ready claim (`sections/7-evaluation.tex`): across the 62
x86-64 microbenchmarks, the kernel-side load time with kinsn is 0.99x that of the original kernel.

**Verdict: the 0.99x claim does not hold, and it never measured kinsn verification.**

* The paper's number is the geomean of `median(kernel_rejit) / median(kernel)` for
  `compile_ns` (open+load) or `phases_ns.object_load_ns`. In the `kernel_rejit` runtime,
  `micro_exec` times the libbpf open+load of the **original** object before it waits for the
  ReJIT signal (`runner/src/kernel_runner.cpp`, `run_kernel`: timing ends before
  `wait_for_measure_signal()`). The kinsn-rewritten program is loaded afterwards by the shim's
  ReJIT (`bpfopt/shim/shim_reload.h`, `reload_and_reattach`), outside both fields. The 0.99x
  therefore compares two loads of the same original program. It contains no kinsn proof
  lowering, verification of proof sequences, restore, or kinsn JIT.
* The kinsn-rewritten program's in-kernel `BPF_PROG_LOAD` costs **2.03x** the original's load
  (geomean, current modules, `kinsn` pass, 48 programs that load). With the default full x86
  policy it costs **1.73x**. bpf_check rises 1.97x and verified instructions rise 1.24x.
  **11 of 62** rewritten programs are rejected by the kernel. For 3 more, bpfopt cannot
  produce a rewrite.
* With the June (paper-snapshot) modules, the same measurement gives **1.28x** (52 programs
  load, 7 are rejected). On the 47 programs that load in both arms, the ratio is 1.18x with
  June modules and 1.97x with current modules.
* Reproducing the paper protocol on the current tree gives compile_ns 0.92-0.99 and
  object_load_ns 1.23-1.25. The 1.25 comes from userspace overhead in the `kernel_rejit`
  process (libbpf loading under the ReJIT shim). The kernel-side duration of that same original
  load is 0.985x the `kernel` runtime's.

A defensible replacement sentence is: "Loading the kinsn-rewritten program takes 1.7-2.0x the
kernel time of loading the original (geomean over the 48/62 programs whose rewrite loads; 11
rewrites exceed verifier or patching limits)." Alternatively, report the June-module figure
(1.28x, 52/62) together with the module revision it applies to.

## What the May 14 campaigns did (paper data)

Both campaigns, `x86_kvm_micro_20260514_031744_210343` and `..._181806_133778`, share these
settings:

* suite `micro_staged_codegen`, manifest `micro/config/micro_pure_jit.yaml` (63 benchmarks;
  the population is the 62 benchmarks of the Apr 29 run, which excludes `katran_like`)
* runtimes llvmbpf, kernel_rejit, kernel, in that order
* samples=1, warmups=0, inner_repeat=10
* `micro_exec test-run` with ktime timing, run in virtme-ng on the Core Ultra 9 285K with
  kernel 7.0.0-rc2+

The `kernel_rejit` passes differ:

* Campaign A: `lea` only.
* Campaign B: the 18-step per-family list (noop, map_inline, const_prop, dce, rotate,
  cond_select, extract, endian_fusion, lea, ccmp, bulk_memory, prefetch, wide_mem,
  bounds_check_merge, skb_load_bytes_spec, noop, const_prop, dce). In campaign B, 25 of the 62
  programs ended with a ReJIT error (verifier-log ENOSPC or bpfopt pass failures), but the
  timed fields were unaffected because they time the original load.

Recomputed from the bundle with the `regenerate.py` formula:

| run | compile_ns | object_load_ns |
|---|---:|---:|
| May14 A (lea) | 0.9943 | 0.9952 |
| May14 B (per-family list) | 0.9903 | 0.9978 |

## Method (this run)

* **Host and guest:** lab, Intel Core Ultra 9 285K. The guest is virtme-ng with 8 vCPUs
  pinned to host CPUs 0-7 and 64 GB, using the same `vng` flags as `make micro`
  (`--cpus 8 --pin 0-7 --mem 64G --rwdir <clone> --overlay-rwdir /tmp --append "loglevel=7 panic=30 oops=panic"`).
  Every guest held `~/workspace/codex-runs/followup-20261011/host.lock` for its whole life.
* **Tree and kernel:** clone `bpf-benchmark-rerun-20261009` at HEAD `e3f503e1e`, with
  `kinsn/module` unmodified. The kernel is `vendor/linux-framework` `24cd6e63ce91`, 7.0.0-rc2+,
  built by the coordinator's image build (`build7.log`, bzImage sha256 `b295c01b...` for all
  three arms).
* **Runtime image:** the coordinator's builds (build6 16:08 PDT for kinsn-current, build7
  16:22 PDT for the other arms). The current kinsn modules have identical srcversions in both
  (`runs/*/module-srcversions.txt`).
* **Programs:** the 62 paper programs, built with clang-18 -O2 -g from bpf-benchmark
  `fed5531cd` (2026-05-14) sources. They are byte-identical to that commit's `micro/programs`,
  and every object has exactly the instruction count loaded in the May 14 runs
  (`programs.sha256`; the `.bpf.o` files are git-ignored by the repository and kept on lab).
* **Inputs:** the old input generators no longer exist in the runner, so programs run on a
  zero-filled input of the original `kernel_input_size`. This does not affect load time. The
  pilot run recorded the zero-input return values, and `suite-paper62.yaml` checks them for
  both runtimes. All 62 matched in every arm, after ReJIT included.
* **Command:** the repository's in-guest micro step `make __runtime-vm-micro` with the
  `RUN_MAKE_VARS` that `make micro` passes, launched by `host-run.sh`. Host-side `make micro`
  was not used because its phony `runtime-kernel-image` prerequisite would rebuild and re-save
  the runtime image (`make -o x86-runner-runtime-image-tar micro ...` would also work).
  `MICRO_PROGRAM_DIR` is not in `SUITE_ENV_NAMES`, so it is forwarded through
  `RUNTIME_ENV_BASE_NAMES`. The exact variables are in `runs/<arm>/make-vars`, and the
  invocations in `runs/queue-1.sh`:

  ```
  ./host-run.sh kinsn-current - suite-paper62.yaml RUNTIMES=kernel,kernel_rejit SAMPLES=4 WARMUPS=0 INNER_REPEAT=10 BPFREJIT_BENCH_PASSES=kinsn
  ./host-run.sh kinsn-june <june-premods> suite-paper62.yaml RUNTIMES=kernel,kernel_rejit SAMPLES=4 WARMUPS=0 INNER_REPEAT=10 BPFREJIT_BENCH_PASSES=kinsn
  ./host-run.sh full-current - suite-paper62.yaml RUNTIMES=kernel,kernel_rejit SAMPLES=2 WARMUPS=0 INNER_REPEAT=10
  ```

  As in May, warmups=0 and inner_repeat=10. Samples are 4 (2 for the full policy) instead of
  1, to get medians. llvmbpf was skipped because it does not run in the kernel.
* **Arms:**
  * `kinsn-current`: the current single `kinsn` pass, which covers all x86 kinsn operations
    except prefetch, with the current modules.
  * `full-current`: the default x86 policy `full-x86` (ten bytecode passes, then `kinsn`).
  * `kinsn-june`: the `kinsn` pass with the June paper-snapshot modules (bpf-benchmark
    `e9956b814b38` `module/`). They were built against the current kernel build
    (`nice -n 19 taskset -c 16-23 make -C vendor/build/x86/linux M=... MO=...`) and loaded
    before the suite. An empty placeholder `bpf_x86_bmi2_shift` (`june-modules/`) keeps the
    current SHLX/SHRX/BZHI module out, because June had none. The June modules built and
    loaded without change, and their payload decoders match the current bpfopt encoding for the
    forms used (only a FRAME form was dropped from MOV since June). This arm combines June proof
    sequences with the current bpfopt rewriter.
* **Kernel timing:** `guest-run.sh` arms kprobes on `bpf_prog_load` (program type, insn_cnt,
  log_level, name), `bpf_check`, `bpf_prog_select_runtime` (len,
  `prog->aux->verified_insns`, jited_len), and, for kinsn-june and full-current only,
  `lower_kinsn_proof_regions` and `do_check_common`. The trace clock is x86-tsc. `analyze.py`
  maps each `micro_exec` process to (benchmark, runtime, sample) in driver order and
  separates three loads: the original load, the shim's reload of the kinsn program
  (log_level 0), and the shim's diagnostic reload after a failure (log_level 1). It takes
  per-program medians over samples. No trace events were dropped or overrun. All guest suites
  ended with rc=0 and no benchmark errors.

## Results

### Paper protocol on the current tree (for the record; contains no kinsn verification)

| arm | compile_ns | object_load_ns | kernel-side original load, rejit process / kernel |
|---|---:|---:|---:|
| kinsn-current | 0.917 | 1.254 | 0.985 |
| kinsn-june | 0.986 | 1.236 | 0.985 |
| full-current | 0.986 | 1.234 | 0.985 |

compile_ns is now dominated by `object_open_ns`, with a median of about 10-12 ms against
0.06 ms in May, so its ratio is noise. object_load_ns includes the userspace shim overhead of
the `kernel_rejit` process. The last column shows that the kernel-side load timed by both
fields is the same original program.

### Kernel-side load of the kinsn-rewritten program vs the original

All 62 original programs load in every arm. In the table, "ratio" is the geomean of the
per-program median in-kernel `BPF_PROG_LOAD` of the rewritten program over that of the
original (`kernel` runtime).

| arm | kinsn program loads | load ratio (loading programs) | bpf_check ratio | verified-insns ratio | load ratio, programs with orig >= 1 ms | all 62, failures and non-rewrites = 1.0 | all 62, failed attempt time counted | sum over 62 (ms): orig -> kinsn |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| kinsn-current | 48/62 | **2.03** | 1.97 | 1.24 | 1.74 (24) | 1.73 | 2.07 | 480 -> 1453 |
| full-current | 48/62 | **1.73** | 1.70 | 1.23 | 1.45 (24) | 1.53 | 1.81 | 471 -> 1266 |
| kinsn-june | 52/62 | **1.28** | 1.26 | 0.89 | 1.12 (27) | 1.23 | 1.11 | 472 -> 553 |

Over the programs that load in both arms of a pair:

* current (kinsn) vs June: 47 programs, **1.97x vs 1.18x**. Per program, the current
  rewritten load is 1.68x the June one.
* kinsn-current vs full-current: 48 programs, 2.03x vs 1.73x.

The `simple` program shows a fixed reload-path cost of about 20-60 us with identical verified
insns: kfunc/BTF descriptor setup for the kinsn calls plus lowering and restore.

Where the time goes, from the full-current probes:

* **Most programs:** extra `do_check` path exploration over the proof sequences. The do_check
  geomean is 1.41x; for the June modules it is 0.93x.
* **Programs with many kinsn calls:** the lowering and restore patching, which is
  O(calls x program length). Examples: `rotate64_hash` 17.9 ms lowering of 32.6 ms
  bpf_check, `imm64_storm` 7.3 of 12.1, `branch_flip_dense` 5.3 of 11.5 (with unchanged
  verified insns), `bounds_check_heavy` 7.9 of 107. The median lowering share is 1.75%.

### Dominant increases (kinsn-current; full-current agrees)

Columns: original -> kinsn load (ms), verified insns, kinsn operations.

* `fixed_loop_large`: 2.2 -> 55.5 ms (26x); verified 17.5k -> 196k. One ROL inside the loop
  (`rolq`, bpf_x86_rotate).
* `bounds_check_heavy`: 85 -> 134 ms (1.6x); 375k -> 551k. BEXTR plus LEA/MOVZX/SHLX.
* `code_clone_8`: 1.4 -> 43.6 ms (30x); 15.4k -> 171k. SHLD x6 (bpf_x86_shd), ROL x2.
* `branch_flip_dense`: 1.3 -> 38.1 ms (28x; 11.7 ms in full-current and June); 4.7k -> 4.5k.
  LEA x260 (patching cost only).
* `rotate64_hash`: 0.24 -> 37.0 ms (153x); 990 -> 30.5k. ROL x116.
* `local_call_fanout`: 1.5 -> 29.6 ms (20x); 9.6k -> 30.8k. ROL x10, SHLX/SHRX.
* `log2_fold`: 6.9 -> 19.3 ms (2.8x); 27.9k -> 27.1k. SHRX x8.
* `imm64_storm`: 0.31 -> 12.5 ms (40x); 1.5k -> 7.5k. ROL x64, LEA x193.
* `code_clone_2`: 0.70 -> 9.6 ms (14x); 6.6k -> 42.5k. SHLD, ROL.
* `branch_dense`: 9.5 -> 17.0 ms (1.8x); 50k -> 75k. ROL x2, SHLX.

Three failed attempts also take long before failing: `cmov_dense` runs 510 ms before hitting
the 1M-insn limit, `mega_basic_block_2048` spends 251 ms lowering before ENOMEM, and
`rotate_dense` spends 110 ms lowering before ENOMEM.

Operation history, from `kinsn/docs/scratchfree-20261009-operations.csv` and git:

| operation | proof length, June | proof length now | change |
|---|---|---|---|
| ROL (bpf_x86_rotate) | 4-16 | up to 10,270 | `78e32d5a0`, 2026-10-06 |
| BLSR (bpf_x86_bmi1) | 7-9 | 321 | `c66aa958b`, 2026-10-06 |
| BEXTR (bpf_x86_bmi1) | 22-27 | 25,214 | `38cae04d0`, 2026-10-06 |
| SHLX/SHRX (bpf_x86_bmi2_shift) | absent | 2-254 | new since June |
| SHLD (bpf_x86_shd) | 6 | 5+5r, up to 160 | `d721c529a`, scratch-free range `cf39e96a7..b64889805` |
| LEA/MOV/CMOV/MOVBE | unchanged or shorter | unchanged or shorter | MOV SIB addressing now uses `index *= 1<<scale` (`6aac2bc7f`, 2026-10-06) |

So most of the growth and three of the four failure classes come from the 2026-10-06
"without scratch spills" commits that precede the scratch-free range. In this population the
scratch-free commits change only SHLD (`code_clone_2/8`, `deep_guard_tree_8`). POPCNT
(28,954 insns) is not used by any of the 62 programs: bpfopt emits BLSR for the bit counts.

### Load failures (kernel rejections of the rewritten program; originals load in all arms)

Current modules: 11 rejections, identical in kinsn-current and full-current. The causes come
from the verifier message and the program's kinsn calls. The per-call proof probe run that
would have isolated individual calls hung (see below).

| program | errno | verifier message | cause |
|---|---|---|---|
| bitcount, tc_bitcount | E2BIG | The sequence of 8193 jumps is too complex. | Verifier jump-history limit inside the counting loop. Inferred cause: the BLSR bit-scan proof (bpf_x86_bmi1, 321 insns). June BLSR (7-9 insns) loads. |
| cmov_dense | E2BIG | BPF program is too large. Processed 1000001 insn | 1M processed-insn limit. ROL x26 proofs on CMOV-branchy paths. |
| mixed_alu_mem, packet_rss_hash, bitfield_extract | ENOMEM | insn N cannot be patched due to 16-bit range | Lowering cannot patch jumps across a BEXTR proof (25,214 insns). |
| mega_basic_block_2048, rotate_dense | ENOMEM | insn N cannot be patched due to 16-bit range | Summed ROL proofs (x512, x256) exceed 16-bit jump offsets. |
| addr_calc_stride, large_mixed_500, large_mixed_1000 | EACCES | Rn pointer arithmetic with *= operator prohibited | The MOV SIB-load proof (bpf_x86_mov) multiplies the index register, which here is a packet pointer. |
| cond_select_dense, extract_dense, endian_swap_dense | (not loaded) | bpfopt: LLVM output stack spills exceed the BPF 512-byte frame | The userspace kinsn rewrite fails in every arm, so the program stays original. |

June modules: 7 rejections, a different set. cmov_dense, large_mixed_1000 and rotate_dense
fail with EINVAL (pkt pointer math with unbounded or 64-bit value). mixed_alu_mem,
large_mixed_500, alu32_64_pingpong and bitfield_extract fail with EACCES (invalid mem access
'scalar' / packet offset). In each case a June proof loses pointer type or bounds; the
operation was not isolated. The same 3 bpfopt failures apply. bitcount, tc_bitcount,
packet_rss_hash, mega_basic_block_2048 and addr_calc_stride load with June modules.

The full per-program tables for every arm are in `per-program-tables.md`: original and kinsn
load, bpf_check, verified insns, sites, operations, and status with errno, verifier message
and cause. Every per-program value is in `per-program.csv`.

## Runs and caveats

* `runs/pilot`: one sample, used to obtain the zero-input return values.
* `runs/failed-pilot-*`: two aborted pilots. The `--exec` command line was too long for the
  kernel cmdline (that guest panicked at boot and was killed), and a kprobe sanity check
  misread `r16:` probe definitions.
* `runs/kinsn-current-r2`: a replicate with an extra probe on `validate_kinsn_proof_seq`
  (operation symbol and proof length per call). It **hung** at program 19/62 (`packet_parse`)
  at 00:29 UTC with no kernel message, holding host.lock for about 4 h. The coordinator killed
  it at 04:35 UTC. The `lower_kinsn_proof_regions`/`do_check_common` probes completed
  normally in two arms, so the new symbol-fetching probe is the suspect. Its partial driver
  output is kept in `result-partial/` and is not used.
* kinsn-current (23:21-23:40 UTC) ran while the host was not yet quiet: the coordinator's
  image build was on CPUs 8-15 until 23:22 UTC, and other lab workloads were not yet paused.
  kinsn-june (23:45-00:02) and full-current (00:07-00:20) ran in the coordinator's quiet
  timing window, interleaved with its cells under the lock. Its absolute times
  can be inflated. For example, `branch_flip_dense` took 38 ms against 11.7 ms in both other
  arms with identical operations. Ratios use the baseline from the same run (samples
  interleaved). The quieter full-current arm gives the lower bound of 1.73x.
* The ratios cover the in-kernel `BPF_PROG_LOAD` only. The whole ReJIT path costs more: the
  original load plus every reload plus the diagnostic reload after a failure come to 4.2x
  (kinsn) and 11.7x (full policy, one reload per changed pass) of the original load.

## Files

| file | contents |
|---|---|
| `README.md` | this note |
| `per-program.csv` | one row per arm and program: paper-protocol medians, trace medians, ratios, statuses, operations, error tails |
| `per-program-tables.md` | the per-program tables for every arm (generated) |
| `summary.json` | geomeans, May14 recomputation, pairwise comparisons |
| `analyze.py` | produces the three files above; run from the clone root: `python3 micro/results/kinsn_load_time_current_20261011/analyze.py --here micro/results/kinsn_load_time_current_20261011 kinsn-current kinsn-june full-current` |
| `host-run.sh`, `guest-run.sh` | guest launcher (lock, vng flags, make vars) and in-guest kprobe setup plus `make __runtime-vm-micro` |
| `suite-paper62.yaml`, `suite-pilot.yaml`, `mk-suite.py` | manifests for the 62 programs and their generator |
| `paper-62.txt`, `prog-names.txt`, `programs.sha256` | population, ELF program names, object hashes |
| `june-modules/` | placeholder `bpf_x86_bmi2_shift` source and the June module srcversions and hashes |
| `runs/<arm>/` | make-vars, host and guest logs, dmesg, kprobe definitions, module srcversions, `kprobe-trace.txt.gz`, `result/details/result.json.gz`. The uncompressed raw files, JIT dumps and the r2 partial run are git-ignored by the local `.gitignore` and kept on lab. |
