# OTel known-hash instruction profile, 2026-11-14

Run `x86_kvm_corpus_20261114_054100_189324`, own job 204811, completed 05:44:21Z: Make 0, corpus/app OK, no workload errors and no tiny-program candidates. Direct-native configuration, pinned 48af2849d known-hash linker, original-source context-corrected OTel manifest, sole kernel/image/base. One 45-second paired diagnostic, stats on, CPUs 16–19, four vCPUs/32 GiB; this is not the official 3×180-second timing or a floor certification. All results remain retained, including the two `custom__generic` EINVAL failures (baseline measured count zero).

Workload native/eBPF throughput is **0.954×** (26,319,584 versus 25,121,520 reported operations). Aggregate BPF cost is **3315.2 → 3745.7 ns per entry**, or 0.885×. The entry counts used for normalization are 17,474,934 and 17,960,529. Inlined tail programs have zero standalone `run_cnt`; their count is never the denominator.

## What the instructions show

The host recorder produced 175,377 samples: 93,789 guest kernel, 78,741 guest user, and 2,847 host kernel. Measurement-window filtering leaves 17,708/19,474 guest-kernel samples, all from QEMU PID 204847. Phase-start symbol tables and each captured program ID/tag/address/length bind the samples to actual machine code, rather than matching shortened symbol labels.

| Measured root observation | eBPF | Native |
| --- | ---: | ---: |
| Samples inside captured program ranges | 2471 | 3257 |
| Main unwinder program ID | 7 | 28 |
| Main unwinder bytes | 21868 | 30557 |
| Main unwinder root samples | 2026 | 2659 |
| Main unwinder sampled period cycles / entry | 2221.88 | 2894.39 |
| All captured program sampled period cycles / entry | 2703.85 | 3544.01 |
| Main unwinder rbp-address operand cycles / entry | 361.90 | 17.01 |
| Main unwinder rsp-address operand cycles / entry | 0 | 653.35 |

The largest native clusters are the repeated stack-delta binary search from unchanged upstream `support/ebpf/native_stack_trace.ebpf.c:bsearch_step`. For example, native offset 0x507–0x5fd repeatedly stores the pivot at `rsp+0x10`, calls the generic map lookup with the actual inner-map pointer, reloads the pivot and the page offset (`rsp+0x68`), then performs `cmp %dx,(%rax)`, `lea pivot+1`, two `cmova` instructions and a bounds branch. Samples at 0x533/0x574/0x5b4 are 36/33/32; these are the instructions immediately following the memory comparison. The corresponding JIT region around 0x420–0x49f loads `addrLow` with `movzwq (%rax),%rsi`, reloads the pivot from `rbp-0x60`, compares registers and uses conditional branches. The sample at JIT offset 0x462, immediately after that `addrLow` load, has 35 hits. Native has 577 samples at instructions immediately following memory comparisons across this unwinder; JIT has 3, because it uses explicit loads and register comparisons instead. This syntactic asymmetry is not a direct latency comparison.

The profile therefore localizes the excess to generated binary-search/stack-access regions and their dependent memory/select chains. It does not establish that conditional moves are inherently slower, or that the entire increase is register spilling. The rsp/rbp categories describe address syntax; rbp can be a general register in native code. Native text also contains LTO-inlined map/tail code, so text-versus-helper bucket movement contributes. A causal compiler-flag or shared-array LTO comparison is still needed. The existing shared-array candidate reduces code duplication but has not yet run; its host success is not a performance result.

## Counters, clocks and scope

Actual measured counter endpoints are baseline-0005→0009/map44 (37.362812 s), native post_rejit-0013→0017/map504 (37.029419 s). Native unwind attempts are 170,720,802/165,535,250, frames per attempt 0.918581/0.916273, interpreter calls per native attempt 0.221304/0.221090. Full family mix and collector output, including appearing/disappearing loss series, are archived; absence of a shared loss delta is not zero loss. Program and map query errors remain in the raw capture.

Host clock offset drift is -482 ns; baseline guest offset changes by +2,072,746 ns, native by -302 ns. Refiltering with each phase's end offset changes **zero guest-kernel sample memberships** in this capture. This sensitivity check observes drift and boundary stability, not perfect absolute clock synchronization. Both sets of windows are archived.

Samples are hardware root IPs with skid, not inclusive caller/helper costs or precise per-instruction latency. Guest kernel work outside captured ranges is reported (15,237/16,217 samples), including helpers, interrupts and uncaptured programs, rather than silently reassigned. No old result is discarded or relabeled. Equal-work resource identity, two runtime configurations, official floors and the 1.20× target remain open.

## Reproduction

The launch recipe/argv, pinned binary and original input hashes, phase clocks/symbols, host.data, decoded periods, actual JIT binaries, complete disassembly, per-instruction TSVs, counter snapshots and raw app run are in the adjacent receipt/archive. Decode using the exact recorded perf binary with `--guestkallsyms run/baseline.start.kallsyms -F time,misc,ip,pid,tid,cpu,period --no-inline --hide-call-graph --ns`; guest samples are hidden without the guest symbol option. `host-costs.py` uses the correct table for each measured phase.

Run `python3 kprog/perf/profile/instruction-costs.py --capture CAPTURE --run RUN --samples guest-samples-period.txt --observation counter-observation.json --profile RAW/run --out NEW_DIRECTORY`. The final output is `instructions-final/`; earlier outputs are preserved. Seven focused attribution/clock/root-window tests pass via `python3 -m unittest discover -s kprog/perf/profile -p 'test_*costs.py'`.
