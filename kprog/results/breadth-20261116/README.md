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
stats 1, 3 samples of 180 s, kernel `7.0.0-rc2+`.

### Stats off

| app | run | status | throughput vs eBPF arm | per-call | 05-29 floor (stats off) |
|---|---|---|---|---|---|
| otelcol-ebpf-profiler/profiling | `x86_kvm_corpus_20261116_032555_782265` | ok | **1.866x** | n/a | 1.849x |
| bcc/set | `x86_kvm_corpus_20261116_035145_077678` | ok | **1.002x** | n/a | 0.985x |
| cilium/agent | `x86_kvm_corpus_20261116_041809_047167` | ok | **1.262x** | n/a | 1.319x |
| tetragon/observer | `x86_kvm_corpus_20261116_044420_592995` | error (VM dies) | — | n/a | 1.009x |
| tracee/monitor | `x86_kvm_corpus_20261116_045848_214505` | error (BTF) | — | n/a | 0.948x |
| katran | `x86_kvm_corpus_20261116_051257_960411` | ok | **1.002x** | n/a | 1.113x |

Four of six pass with zero loader failures. The two that do not are new
failures, not the round-one ones: Tetragon's `CONFIG_ITER_NUM` GOT-reloc is
closed and its native arm dies in the guest, and Tracee's 512-chunk ceiling is
closed and replaced by `BPF data map .rodata.str1.1 lacks BTF` on
`sys_enter_submit`.

Tetragon's trigger is the single entry `event_wake_up_n`, not a replacement
count: twelve runs split exactly on whether the manifest contains it, and
`manifest-wake.json` (that one entry) kills the VM on its own
(`corpus/results/tet-tetragon-cap-20261116/README.md`). The earlier "third
replacement" reading was an artifact of set construction — every set with three
or more entries happened to contain it.

### Stats on

Stats on is the only mode with per-call BPF time. The rotate finished all six
here: four rows are complete, one dies before its native arm, one measures only
its baseline.

| app | run | status | throughput | per-call | 05-29 floor |
|---|---|---|---|---|---|
| otelcol-ebpf-profiler/profiling | `x86_kvm_corpus_20261116_053859_493069` | ok | **2.020x** | **14.4x** (3448.6 → 239.6 ns) | 1.849x |
| bcc/set | `x86_kvm_corpus_20261116_060435_731340` | ok | **1.268x** | **1.134x** (122.51 → 107.98 ns) | 0.985x |
| cilium/agent | `x86_kvm_corpus_20261116_063056_107201` | ok | **1.212x** | **2.29x** (845.8 → 369.7 ns) | 1.319x |
| tetragon/observer | — | died, `event_wake_up_n` | — | — | 1.009x |
| tracee/monitor | `x86_kvm_corpus_20261116_071110_996499` | error (BTF), baseline only | — | — | 0.948x |
| katran | `x86_kvm_corpus_20261116_072549_683704` | ok | **1.029x** | **1.041x** (191.3 → 183.8 ns) | 1.113x |

Every measurable per-call number is on the right side of 1.0: OTel 14.4x, Cilium
2.29x, BCC 1.134x, Katran 1.041x. The native arm never costs more per call than
the eBPF arm on any app that completes. Two rows still miss their floor, and
neither is a per-call regression: Cilium's is the eBPF arm having improved
(decomposed above), Katran's is throughput at essentially equal per-call cost.

- **OTel** — workload units eBPF 40 774 750 / 39 759 786 / 40 450 832, native
  75 471 022 / 75 117 432 / 78 452 133; 0 workload errors, 13 replacements.
  `custom__generic` still failed twice, which the `source_bpf_object`
  publication below closes.

  **Warning for the next round: once `custom__generic` links, this row falls to
  1.021x.** In `x86_kvm_corpus_20261116_102445_806916` (stats off) the same app
  with the same manifest measured 324,431,106 against 369,715,211 median ops —
  post_rejit *below* baseline — because `custom__generic`, the per-event kprobe,
  was replaced with a 9257 B body instead of falling back to JIT. Its original
  is 3679 B. Across runs, that program's native size predicts the outcome:
  6452 B → 1.832x/1.885x, 9400 B → 1.060x/1.161x, 9257 B → 1.021x, not
  replaced → 1.85x-2.02x. So the 2.020x above depends on that fallback, and the
  `source_bpf_object` publication closing the failure is what exposes the
  regression. Evidence and the per-program `bytes_jited` diff:
  `kprog/results/native-payload-ir-20261116/README.md`.

  **Confirmed on the stats-on path, with one caveat.** The next round's
  `x86_kvm_corpus_20261116_125155_179400` (`status: ok`) measured **0.946x**
  on interpreter-loop `ops=` (7 445 647 378 → 7 040 298 780, median of
  three) and **0.893x** per-call on `native_tracer_execve` (3189.2 → 3571.9
  ns), where this row records 14.4x. The two runs' replacement sets differ by
  exactly one program — `custom__generic`, absent from the 13 replacements
  here and present among the 14 there — and the extractor reproduces 2.020x
  exactly on this row's run, so the ratio is not an arithmetic artifact.
  Caveat: this row's run predates the 09:04:03Z build of the current image,
  and the new run is on it, so image is not held fixed. That does not touch
  the set difference, which is image-independent: this row's run never linked
  `custom__generic` at all.
- **BCC** — 657 707 / 661 454 / 663 888 against 661 569 / 662 768 / 670 159;
  25 native programs replaced and **zero** `native-loader failed` lines, so the
  `target_family` GOT-reloc link-plan gap is closed on this path.
- **Cilium** — 1 291 758 / 1 294 084 / 1 255 396 against 1 636 270 / 1 613 004
  / 1 629 943; zero `native-loader failed` lines, so `tail_ipv4_policy`'s
  register-indirect helper call is closed too. This is the one app still below
  its 05-29 floor (1.262x against 1.319x), and the gap is the **eBPF arm
  getting faster**, not native code getting slower: against the 11-10 run of
  the same image family, today's baseline arm is 1 291 758 against 1 217 640
  units (+6.1 %) while today's native arm is 1 629 943 against 1 605 561
  (+1.5 %). The native arm is ahead of the 11-10 native arm in absolute terms,
  and the ratio fell because the denominator grew faster. The native objects
  are 4 of 7 code-identical to 05-29 (`compare_code.py`: 275 813 code bytes
  then, 275 868 now; `bpf_xdp` grew 250 B, `bpf_host` shrank 80 B and
  `bpf_lxc` 115 B), so the remaining difference is not the compiled code.
  The stats-on run is what turns this into a per-call statement rather than a
  ratio statement.
- **Katran** — 2 836 395 / 2 834 431 / 2 751 056 against 2 815 437 / 2 840 654
  / 2 916 733, one replacement (`balancer_ingres`), zero loader failures.
  pktgen reports 80-117 M errors per sample in both arms, so the number is pps
  alone. 1.002x against the 05-29 floor 1.113x.
- **Cilium, stats on** — 1 188 402 / 1 090 127 / 1 118 865 against 1 355 682 /
  1 350 554 / 1 408 943, 113 replacements, zero failures. That closes the
  question the stats-off row left open: on `cil_from_container`, the one
  program with real counts in both arms, per-call BPF time is 845.8 to 369.7 ns
  — **the native arm is 2.29x cheaper per call**. So the native code is not
  slow; the 1.212x throughput ratio at stats on (1.262x at stats off) is what
  that per-call gain yields once the program's share of the packet path is
  accounted for. `cil_from_host` and `cil_to_host` show 6.1x and 34x but have
  `run_cnt` 2 in the baseline sample, so they are not per-call evidence and are
  not quoted as such.
- **BCC, stats on** — 410 168 / 401 184 / 467 953 against 525 896 / 520 143 /
  444 167, 25 programs in both arms, zero failures. Per-call BPF time 122.51 to
  107.98 ns, so the native arm does the same work 1.134x cheaper; the
  throughput spread is wider than the per-call gain, so pps is the noisy side
  of that row.
- **OTel, stats on** — 36 558 926 / 36 948 900 / 39 052 673 against 63 427 701
  / 74 649 808 / 75 372 187, 13 replacements, 2.020x against the 1.849x
  floor. Per-call: `native_tracer_e` 3448.6 to 239.6 ns, **14.4x cheaper**.
  `custom__generic` fails twice here with `BPF_PROG_LOAD native_lab stub:
  Invalid argument` because this run used the image's default manifest, which
  predates the `source_bpf_object` publication; with the corpus manifest the
  same program replaces successfully (section below).
- **Tracee, stats on** — the baseline arm measured 317 680 / 325 022 / 316 350,
  then the app exited before the native arm ran: `Tracee exited before BPF
  programs were tracked by shim`. The shim log names the cause twice on
  `sys_enter_submit` (`details/shim-logs/tracee__monitor.post_rejit.log`):
  `native-loader failed prog=sys_enter_submi ... error=BPF data map
  .rodata.str1.1 lacks BTF`. Four replacements went in first, so this is a
  per-program BTF gap, not a load-order effect.
- **Katran, stats on** — pps 2 333 230 / 2 260 241 / 2 287 533 against
  2 354 334 / 2 273 034 / 2 407 530, one replacement (`balancer_ingres`),
  zero loader failures. Per-call 191.3 to 183.8 ns over 1.2 billion
  invocations in each arm: the native arm is 1.041x cheaper per call and the
  throughput difference is inside the pps noise (pktgen reports 80-117 M
  errors per sample in both arms). Katran's 1.113x floor is therefore a
  throughput target the current code does not meet; it is not a per-call
  regression.

## After the helper ABI repair: the wake entry stops killing the guest

Every row above ran on the payload built before `e688689e6`, which is the
`core-compat.h` that gives Tetragon's helpers compiler-visible SysV calls. On a
payload rebuilt from it, the isolated `event_wake_up_n` entry that ended twelve
earlier runs now replaces and runs
(`corpus/results/x86_kvm_corpus_20261116_082133_210399`): fd 71 → 87, native
JIT 5012 B against the original's 7339, zero loader failures, both arms ok,
stress-ng 6/6 with zero failures in each. The death was the helper call shape.

The full 94-entry canonical manifest then survives the load and gets ten
replacements in, including `event_wake_up_n` and `tg_kp_bprm_comm`, before
Tetragon exits on `generic_kprobe_filter_arg`. That is a linker gap, not a
producer one: `native-link` reports `x86 helper tail branch cel_expr_0 has no
helper address`, and `cel_expr_0..7` are policy-load symbols
(`vendor/bpf/tetragon/bpf/process/cel_expr.h:8`), so no plan can carry an
address for them. Both retests used stats off, so Tetragon still has no
timing row; the diagnosis is in
`kprog/results/tet-canonical-retest-20261116/README.md`.

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