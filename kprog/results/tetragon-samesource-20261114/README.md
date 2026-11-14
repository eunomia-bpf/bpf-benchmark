# Tetragon same-source, both arms, 2026-11-14

## What was built

`vendor/bpf`'s `native-tetragon` target on the one kernel line, with the two
`MICRO_NATIVE` guards restored (`36357fe87`): `bpf/lib/bpf_d_path.h:148`
(`namelen &= 0xff`) and `lib/process.h:729` (`exe->len &= 0xff`) had upstream's BPF
inline asm replaced with plain C, unguarded; both now follow `lib/config.h:31-34`
(plain C under `#ifdef MICRO_NATIVE`, upstream `asm volatile` otherwise).

- `make native-tetragon` rc=0, manifest `native-objects-proof-linked`, 93 entries over
  35 objects.
- All 88 native objects are **byte-identical** to the image's own
  (`/opt/bpf-benchmark/native-bpf/x86_64/tetragon/`): `.text` and `.rodata` compare
  equal object by object. The file-level sha256 differs only in non-code bytes.
- `make tetragon` (the eBPF arm) fails with 36 pre-existing `-Werror` diagnostics from
  `include/vmlinux_generated_x86.h:33936` and `:48425` (anonymous struct members from
  `btf dump ... format c`), producing 0 objects. That failure is independent of the
  guards, and the eBPF arm here is the runtime image's own.

The manifest is entry-for-entry identical to the image's, including both
`generic_kprobe_` variants (`bpf_generic_kprobe_v61.native.o` and
`bpf_multi_kprobe_v61.native.o`).

## Runs

Smoke `x86_kvm_corpus_20261114_193521_704992` (1 x 30 s): `status ok`, 288
`jit-info native`, 288 `replaced prog=`, 0 errors.

Timing `x86_kvm_corpus_20261114_194008_916664` (3 x 180 s, CPUs 0-7, both arms in one
window, `specialized-timing.sh tetragon/observer corpus/results/tetragon-samesource-20261114`):
`status ok`, 0 workload errors, 288 `jit-info native` in the native arm and 0 in the
baseline.

## Result, and the two caveats that matter

Per-sample sums of `stress-ng` real-time `bogo ops/s` (the metric `kprog/docs/evaluation.md`
defines for this app):

| arm | sample 1 | sample 2 | sample 3 | mean |
|---|---:|---:|---:|---:|
| baseline (eBPF) | 455 481 | 438 327 | 441 789 | 445 199 |
| native | 567 611 | 564 231 | 571 531 | 567 791 |

**1.2754x** on the mean; per-sample 1.246 / 1.287 / 1.294.

Caveat 1 — **the two arms did not do equal work.** Native BPF runs were 6.34G against
the baseline's 4.05G (1.57x); every program type scales together (`generic_tracepoint`
2.71G/1.86G, `generic_kprobe_` 2.61G/1.61G, `generic_retkprobe` 1.03G/0.58G). Unlike a
packet generator, `stress-ng` is closed-loop: a faster hook lets it complete more
operations in the 180 s, so the throughput gain is *because* the event path got cheaper,
which is exactly what the metric is meant to show. The per-stressor ratios are 1.08x
(`sockfd`) to 4.08x (`mmap`, a ~40 ops/s stressor where small counts amplify).

Caveat 2 — **the frozen reference for this app is 1.009x stats-off**, and that number
does not reproduce on this workload as it runs today. The reference run
(`x86_kvm_corpus_20261110_092457_736627`, same command line) gives per-sample sums
166 731 / 139 603 / 176 843 against 168 156 / 165 490 / 208 996 — ratios
1.009 / 1.185 / 1.182, a 0.2x spread across three samples of *the same run set*. Its
stressor mix is the same as today's, but its absolute rates are roughly half (e.g. `udp`
57 458 against 156 581 today), so the machine is in a different state. A 1.009x headline
from a metric whose own samples span 1.009–1.185 is not a tight floor; today's
1.2754x is not directly comparable to it.

What is solid: the native objects are the image's own bytes, the manifest is identical,
the load replaces all 288 programs with 0 errors, and the throughput is higher in every
sample and every stressor.

## Per-program cost

Matched by program type over instances with `run_cnt_delta >= 100`:

| type | baseline ns/inv | native ns/inv |
|---|---:|---:|
| `generic_kprobe_` (traffic-carrying instance) | 675.1 | 42.0 |
| `generic_tracepoint` | 552.5 | 519.0 |
| `generic_retkprobe` | 35.1 | 33.8 |

The 16x on `generic_kprobe_` is not a like-for-like comparison: 20 instances share
that name and only one carries traffic, and the baseline's traffic instance ran at
413–4 354 ns depending on which kernel hook it was attached to. The instance-level
numbers are not a ratio to quote; the throughput above is.

Baseline BPF time totalled 2 135 s over the three 180 s samples on 4 vCPUs
(≈ 2 160 CPU-s), so the eBPF arm is essentially saturating the guest — which is why the
native arm's freeing of that time shows up directly in `stress-ng` throughput.

## Where the numbers live

- Capture: `/workspaces/kprog-raw/C/one-image-runs/20261114T193854Z-specialized-tetragon_observer-s3.log`
- Run: `corpus/results/x86_kvm_corpus_20261114_194008_916664`
- Staged manifest: `corpus/results/tetragon-samesource-20261114/`
## Restaging the manifest directory

`*.native.o` is gitignored (`*.o`), so only `manifest.json` is committed. Rebuild
the objects and restage them with the sole kernel's BTF:

```sh
cd vendor/bpf
export KERNEL_RELEASE=$(cat /workspaces/.agent-state/kprog-ck/build-x86/include/config/kernel.release)
make VMLINUX_BTF=/workspaces/.agent-state/kprog-ck/build-x86/vmlinux native-tetragon
R=vendor/build/native-bpf/x86/$KERNEL_RELEASE/native/tetragon   # from the repo root
install -d corpus/results/tetragon-samesource-20261114
cp $R/*.native.o $R/manifest.json corpus/results/tetragon-samesource-20261114/
```

`VMLINUX_BTF` must be the sole kernel's; the default is the host's, and the wrong BTF
silently swaps tracked headers.
