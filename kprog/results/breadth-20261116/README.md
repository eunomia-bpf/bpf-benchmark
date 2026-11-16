# Breadth round, one image: 2026-11-16

Six applications, one run each, same image and same frozen workload as the
2026-05-29 reference. The coordinator started the round at 2026-11-16T01:07:08Z
(`flock locks/timing make -f kprog/perf/one-image/Makefile rotate`, log
`/workspaces/kprog-raw/one-image-runs/rotate-20261116T0107Z.log`), six apps in
the entry ORDER at stats 0 then stats 1; it stopped the round after Katran
stats 0 (STOP file, 2026-11-16T02:59:45Z: "stop after Katran stats 0; rerun the
round on the image with the native-load fixes"). So round one is the stats-off
half only; the stats-on half, and the per-call BPF time that comes only from
it, are not in it.

## Round one, image `fc408f64`, stats off

Image `fc408f64`, entry defaults, 3 samples per arm of 180 s, kernel
`7.0.0-rc2+`. Each run dir is committed under `corpus/results/`.

## Table

| app | run | status | throughput vs eBPF arm | per-call | 05-29 floor (stats off) |
|---|---|---|---|---|---|
| otelcol-ebpf-profiler/profiling | `x86_kvm_corpus_20261116_010841_344218` | ok | **1.854x** | n/a | 1.849x |
| bcc/set | `x86_kvm_corpus_20261116_013455_495442` | error (link) | — | n/a | 0.985x |
| cilium/agent | `x86_kvm_corpus_20261116_014919_236561` | error (link) | — | n/a | 1.319x |
| tetragon/observer | `x86_kvm_corpus_20261116_020859_257027` | error (link) | — | n/a | 1.009x |
| tracee/monitor | `x86_kvm_corpus_20261116_022318_630666` | error (loader) | — | n/a | 0.948x |
| katran | `x86_kvm_corpus_20261116_023729_285383` | ok | **0.976x** | n/a | 1.113x |

Throughput is the median of the three workload samples in the native arm over
the median of the three in the eBPF arm, computed with the 2026-05-29 parser
(`kprog/docs/archive/native_eval_20260529.py`: `load_app`, `phase_samples`;
`bpf_aggregate` for per-call). Per-call is n/a here because at stats 0 every
`run_cnt_delta` is 0, so the parser retains no record (`run_cnt_delta >= 100`).

## What each row is

- **OTel** — 12 programs replaced in the native arm. Workload units eBPF
  41 262 897 / 40 686 020 / 40 276 491, native 74 612 067 / 75 418 497 /
  79 210 617, 0 workload errors. Committed `45fa996bb`.
- **BCC** — the baseline arm completed (662 224 / 658 155 / 658 977 units, 0
  errors); the native arm never started. `details/shim-logs/bcc__set.post_rejit.log:353`:
  ```
  Error: GOT-relative reloc against unknown symbol target_family; add it to link-plan helpers or maps
  ```
  on `inet_sock_set_state` (1 504 B) from tcplife. The loader fell back to the
  verifier, which then rejected the program (`BPF program load failed: Invalid
  argument`, 374 insns). Committed `aeaa3659c`.
- **Cilium** — baseline 1 054 547 / 1 121 010 / 1 155 316 units, 0 errors;
  native arm never started. `details/shim-logs/cilium__agent.post_rejit.log:855`:
  ```
  Error: x86 unresolved register-indirect call in tail_ipv4_policy at local offset 0x16bd through RAX; helper calls must be rewritten before kernel load
  ```
  cilium-agent then reports `program tail_ipv4_policy: load program: invalid
  argument` and endpoint regeneration times out. Committed `1b299c613`.
- **Tetragon** — baseline 146 199 / 68 025 / 123 045 units, 0 errors; native
  arm never started, the agent exits before any program is tracked.
  `details/shim-logs/tetragon__observer.post_rejit.log:555`:
  ```
  Error: GOT-relative reloc against unknown symbol CONFIG_ITER_NUM; add it to link-plan helpers or maps
  ```
  on `execve_send` (3 609 B); the application then fails its `__base__` sensor
  with `program execve_send: load program: invalid argument`. Committed `558674303`.
- **Tracee** — baseline 337 705 / 332 720 / 365 456 units, 0 errors; native arm
  never started. `details/shim-logs/tracee__monitor.post_rejit.log:670`:
  ```
  native-loader failed prog=lkm_seeker_modt ... error=native blob requires 627 chunks but module only supports 512
  ```
  Tracee dies with `failed to load BPF object: invalid argument`. This one is a
  loader chunk ceiling on a 13 815-insn program, not a link-plan gap.
  Committed `b82eabd88`.
- **Katran** — status ok, 0 workload errors, one program replaced
  (`balancer_ingres`, the only program Katran times). pps baseline 2 825 978 /
  2 900 055 / 2 900 528, native 2 830 499 / 2 808 955 / 2 889 896. pktgen
  reports ~0.28–0.32 G errors per sample in **both** arms, so the ratio is on
  pps alone. 0.976x, the one app measured below its 05-29 floor (1.113x).
  Committed `b82eabd88`.

## The four failures, grouped by owner

Three are link-plan gaps in the linker at `72a2c1d37`: an unknown GOT symbol
(`target_family`, `CONFIG_ITER_NUM`) and one register-indirect helper call the
CFG-identity pass leaves unproven at a join
(`kprog/x86/native_lab/native_link/src/x86_helper_provenance.rs`, the site is
`movl $0x17,%eax; xorl %esi,%esi; callq *%rax` = helper 23 `bpf_redirect`,
reached past `cmpb $0x0,(%rax); jne`). The Cilium site reproduces outside the
guest on the 2026-11-14 stage object and on the 05-29 object, so it is the
linker, not this image's objects or the flags.

The fourth is the loader's 512-chunk module budget against Tracee's 13 815-insn
`lkm_seeker_modt`.

## Round two, image `d9e29630`: the native-load fixes land

PERF published image `d9e29630` at 2026-11-16T03:23:26Z (DATASEC `ed1d7a8f2`,
finite helper joins `f18e94306`, dynamic chunks `5a214d73d`) and restarted the
unchanged rotate entry at 03:24:37Z, six apps in the same ORDER at stats 0 then
stats 1, 3 samples of 180 s, kernel `7.0.0-rc2+`. This section carries the
stats-off rows that finished before this writing; the stats-on half is still
running, so per-call stays n/a here.

| app | run | status | throughput vs eBPF arm | per-call | 05-29 floor (stats off) |
|---|---|---|---|---|---|
| otelcol-ebpf-profiler/profiling | `x86_kvm_corpus_20261116_032555_782265` | ok | **1.866x** | n/a | 1.849x |
| bcc/set | `x86_kvm_corpus_20261116_035145_077678` | ok | **1.002x** | n/a | 0.985x |
| cilium/agent | `x86_kvm_corpus_20261116_041809_047167` | ok | **1.262x** | n/a | 1.319x |
| tetragon/observer | — | running | — | n/a | 1.009x |
| tracee/monitor | — | running | — | n/a | 0.948x |
| katran | — | running | — | n/a | 1.113x |

- **OTel** — workload units eBPF 40 774 750 / 39 759 786 / 40 450 832, native
  75 471 022 / 75 117 432 / 78 452 133; 0 workload errors, 13 replacements.
  `custom__generic` still failed twice, which the `source_bpf_object`
  publication below closes.
- **BCC** — 657 707 / 661 454 / 663 888 against 661 569 / 662 768 / 670 159;
  25 native programs replaced and **zero** `native-loader failed` lines, so the
  `target_family` GOT-reloc link-plan gap is closed on this path.
- **Cilium** — 1 291 758 / 1 294 084 / 1 255 396 against 1 636 270 / 1 613 004
  / 1 629 943; zero `native-loader failed` lines, so `tail_ipv4_policy`'s
  register-indirect helper call is closed too. This is the one app still below
  its 05-29 floor (1.262x against 1.319x); at stats 0 no per-call number
  exists to say whether the gap is BPF time or workload noise.

## The original OTel ELF and `source_bpf_object`

The native loader binds an original program's map symbols to the intercepted
program's map FDs through the ELF the application itself embeds, not through an
object this repository compiles. `native-otel` now stages
`vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/tracer.ebpf.amd64`
(2 419 520 B, md5 `c45c97f31aa375408b14ecae2dae5b5d`, byte-identical to the
blob at offset 29 995 136 of the image's `/usr/local/bin/otelcol-ebpf-profiler`)
into the canonical payload and writes `source_bpf_object` into all 26 manifest
entries.

Measured effect, one 10 s stats-on sample with that payload
(`corpus/results/x86_kvm_corpus_20261116_044522_968846`): 14 replacements and
no failure. `custom__generic` is the 14th;
`details/shim-logs/otelcol-ebpf-profiler__profiling.post_rejit.log:276`:
```
native-loader replaced prog=custom__generic original_fd=10 native_fd=96 manifest=/workspaces/repository/corpus/results/otel-source-bpf-20261116/manifest.json
```
Every earlier run replaced 13 and failed this program twice with
`BPF_PROG_LOAD native_lab stub: Invalid argument`. Committed `8e8ece4fb`
(payload), `2c1bda03d` (proof). The one image does not carry the new payload
yet; `corpus/results/otel-source-bpf-20261116` holds the same three files for
a run that points `NATIVE_MANIFEST` into the repository.

The first round's failures were reported in `COORDINATION.md` for PERF at
`220913e8b` and `5c4f908b1`.