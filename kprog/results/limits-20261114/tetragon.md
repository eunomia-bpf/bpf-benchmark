# Tetragon performance limits, 2026-11-15

Both arms of one run, same guest, same workload, `kprog/perf/profile/phase-profile.py
run --app tetragon/observer --seconds 60 --cpus 0-7`. Capture
`/workspaces/kprog-raw/C/20261115T011437Z-phase-profile-tetragon_observer`; corpus run
`x86_kvm_corpus_20261115_011551_351670` (`status: ok`, 288 native loads of 577);
attribution `bpf-attribution.py` → `attribution.txt`.

Method as in `katran.md`: BPF time is samples whose callchain contains a frame inside a
JIT'd program; a sample's bucket is the helper the innermost program frame called.

## Per-program text against helpers

Shares of the BPF denominator (perf samples), which covers only the programs perf sampled:

| bucket | eBPF | native |
|---|---:|---:|
| `bpf_probe_read_compat` | 41.5% | 7.1% |
| **program text** | **25.4%** | **63.8%** |
| `bpf_ringbuf_output` | 18.4% | — |
| `ktime_get_boot_fast_ns` | 4.0% | — |
| map lookup (htab) | 5.0% | 25.9% |
| other helpers | 5.7% | 3.2% |
| **BPF samples** | **36 878** | **4 237** |

Both arms are dominated by one program name, `generic_kprobe_`: 99.8% of the eBPF BPF
denominator and 96.9% of the native one. Tetragon compiles 287 loader instances of the
same generic program family, so a share by name is the only meaningful split.

## The capture disagrees with the kernel's own counters, and the counters win

`perf record` sampled 36 878 BPF samples on the eBPF arm (7.83% of all guest samples) and
4 237 on the native arm (0.88%). The kernel's per-program counters from the same run say
otherwise:

| arm | programs that ran | invocations | BPF time | ns/invocation |
|---|---:|---:|---:|---:|
| eBPF | 32 of 287 | 262 334 776 | 108.4 s | 413.2 |
| native | 35 of 287 | 566 736 541 | 69.7 s | **123.0** |

Two facts make the perf share unusable as an app-level statement here:

1. **Perf missed most of the BPF time.** Of the 108.4 s the kernel charged to BPF on the
   eBPF arm, 89.6 s (83%) belongs to programs whose JIT ranges perf never resolved: 20 of
   the 32 programs that ran were not in that phase's `jit-lines.json`. On the native arm
   66.3 s of 69.7 s (95%) is in the same position. The ranges that *were* resolved cover
   their own programs completely (824 318 of 824 318 bytes, 1 230 846 of 1 230 846), so
   the loss is enumeration, not range matching.
2. **The two arms did different amounts of work.** The native arm ran 2.16x as many
   invocations and moved 1.88x the workload throughput (558 846 against 297 878 bogo
   ops/s summed over stressors). So even a correct BPF share could not be compared
   across arms in this capture.

The counter comparison is the one that survives both problems, because it is per
invocation: **413.2 → 123.0 ns of BPF time per invocation, 3.36x less.** That is the
call-time measure and it is what a timing run would see if the arms ran the same work.

## Conditional code-generation limit

Do not read the perf table's 25.4% → 63.8% program-text shift at face value: the two arms'
denominators cover different program sets. What the capture does show is that on the
programs both arms sampled, the native code spends a larger share of its BPF time in its
own text and less in `bpf_probe_read_compat` (41.5% → 7.1%), which is the direction a
working native body takes.

Under the eBPF-arm program-text share `f = 0.254`:

| program speedup | whole-BPF speedup | 
|---|---:|
| 1.10x | 1.024x |
| 1.30x | 1.067x |
| eliminate program text | 1.341x |

Tetragon's BPF share of guest CPU is small enough that these are upper bounds on the
whole-app effect, not predictions. Tetragon's measured same-source throughput is 1.2754x
(`../tetragon-samesource-20261114/README.md`, 288 native of 0 replacements), so the native
arm already delivers more whole-app movement than the eBPF arm's 25% program text would
suggest; that ratio also carries the workload-volume caveat recorded there.

## Note on the profile's own workload

One sample of the app's normal workload per phase, so its throughput numbers are not
timing results, and here the two phases did not even run the same volume (see above). Use
it for shares and for the per-invocation counters only.

Raw capture:
`/workspaces/kprog-raw/C/20261115T011437Z-phase-profile-tetragon_observer`
(`baseline.data`, `post_rejit.data`, per-phase `kallsyms` and `jit-lines.json`,
`attribution.json`/`attribution.txt`). Regenerate with
`python3 kprog/results/limits-20261114/bpf-attribution.py <capture dir>`.