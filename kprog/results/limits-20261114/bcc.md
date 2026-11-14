# BCC performance limits, 2026-11-14

Both arms of one run, same guest, same workload, `kprog/perf/profile/phase-profile.py
run --app bcc/set --seconds 60 --cpus 0-7`. Capture `/workspaces/kprog-raw/C/limits/bcc`;
corpus run `x86_kvm_corpus_20261114_184517_404427` (`status: ok`); attribution
`bpf-attribution.py` → `attribution.json` / `attribution.txt`.

Method as in `katran.md`: BPF time is samples whose callchain contains a frame inside a
JIT'd program; a sample's bucket is the helper that the innermost program frame called.

## Program body against helpers

Shares of the BPF denominator:

| bucket | eBPF | native |
|---|---:|---:|
| `bpf_ktime_get_ns` | 30.1% | 30.1% |
| `bpf_perf_event_output` (incl. irq_work + APIC IPI) | 27.1% | 26.6% |
| map update (htab/percpu) | 17.8% | 18.1% |
| map lookup (htab + hash + compare) | 12.2% | 12.2% |
| **program text** | **9.2%** | **9.4%** |
| other helpers | 3.2% | 3.2% |
| `bpf_probe_read*` | 0.4% | 0.3% |
| **BPF samples** | **96 925** | **95 733** |

BPF is 19.61% of guest CPU time in the eBPF arm and 20.05% in the native arm. The two
columns are within 0.5 points in every bucket: **the native build changes essentially
nothing about where BCC's time goes**, which matches its measured throughput (1.0011x
pooled, see `../bcc-samesource-20261114/README.md`).

Per program (share of BPF, inclusive of callees), both arms alike:

| program | eBPF | native |
|---|---:|---:|
| `sys_exit` | 34.6% | 34.8% |
| `sys_enter` | 30.9% | 31.5% |
| `tracepoint__syscalls__*` | 25.6% | 25.1% |
| `kprobe__cap_cap` | 8.6% | 8.4% |

## Conditional code-generation limit

`f = 0.092` program-text share of BPF time.

| program speedup | whole-BPF speedup | whole-app effect |
|---|---:|---:|
| 1.10x | 1.008x | 1.002x |
| 1.30x | 1.022x | 1.004x |
| eliminate program text | 1.101x | 1.018x |

**BCC cannot reach 1.20x by code generation at all.** Even a free program body gives about
2% end to end, because BPF is 19.6% of guest time and the body is 9% of that. The only
lever large enough is a helper-level one: `ktime_get_ns` (30%) and
`bpf_perf_event_output` (27%) together are 57% of BPF time. Both are helper calls the
native arm already makes identically, so reaching 1.20x on BCC would need a *helper*
optimisation (e.g. an inlined monotonic clock read), not a better program body.

Note that the eBPF arm here is stock JIT code for the same programs, so any "program text
is only 9%" finding says the native path has little room, not that the JIT is slow.

## On the profile's workload

One 60 s sample per phase; throughput from this capture is `stress-ng` bogo ops and is not
a timing result. The three-configuration timing lives in
`../bcc-samesource-20261114/README.md` (3 x 180 s).
Raw capture: `/workspaces/kprog-raw/C/limits/bcc` (`baseline.data`, `post_rejit.data`, per-phase `kallsyms` and `jit-lines.json`, `attribution.txt`). Regenerate the numbers with
`python3 kprog/results/limits-20261114/bpf-attribution.py /workspaces/kprog-raw/C/limits/bcc`.
