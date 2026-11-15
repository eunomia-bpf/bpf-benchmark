# BCC: the same-source objects and the two specialized configurations

BCC is the first application timed on both sides of the pipeline. The same-source
objects in this directory are the ones the image itself carries, so they are the
reference: `bcc__set` is the application (`bcc/set`, 25 native programs loaded
per run).

## The three configurations

| configuration | objects | build |
|---|---|---|
| image | the image's own manifest, `/opt/bpf-benchmark/native-bpf/x86_64/bcc/manifest.json` | none; this is the 2026-05-29 path |
| `.rodata` specialized | `corpus/results/bcc-rodata-20261114` | `native_specialize_objects.py --publish` (frozen `.rodata` globals become constants) |
| `.rodata` + maps | `corpus/results/bcc-maps-20261114` | the same plus `--maps` (plain-array lookups become address arithmetic) |

All three cover the same 29 manifest entries over 8 objects. `vfsstat` keeps its
`.bss`-based state and has no `.rodata` map at all, so it ships byte-identical to
the same-source object (`3d713a28…`) in both specialized builds.

## Measurement

`kprog/perf/one-image/scripts/specialized-timing.sh bcc/set <manifest-dir> … 3 180 0-7`,
stats on, CPUs 0-7, under the timing lock. Every run reported `status ok`, 25
`jit-info native` loads in the post arm and 0 in the baseline arm.

| configuration | run | eBPF ns/inv | native ns/inv | pooled | weighted |
|---|---|---|---|---|---|
| image | `x86_kvm_corpus_20261114_135018_043527` | 73.38 | 74.72 | 0.9820x | 0.9826x |
| `.rodata` + maps | `x86_kvm_corpus_20261114_141724_941055` | 71.94 | 71.86 | 1.0011x | 1.0019x |

The two runs above are a pair: both were taken in one clean window with no other
guest on the host, back to back. The `.rodata`-only configuration was measured
earlier (`x86_kvm_corpus_20261114_122855_947378`): 76.26 / 75.71 ns, 1.0072x.

`weighted` re-expresses the native arm at the baseline arm's own invocation mix
(`sum over programs of base_runs × native_ns_per_inv`), because the two arms do
not run the same number of times and a pooled ratio would follow the mix.

## What the numbers say

Specializing the objects does not make BCC faster. The three configurations
land between 0.98x and 1.01x, i.e. within the run-to-run spread, and the
image's own objects are the fastest of the three in the clean window.

Two facts explain it, and both are worth keeping because they bound what any
object-level work can win on this application:

- Only 5 of the 20 distinct programs change bytes between the image objects and
  the `.rodata`+maps objects (`block_rq_insert`, `block_rq_issue`,
  `inet_sock_set_s`, `kprobe__cap_cap`, `sched_switch`). The dominant programs —
  `sys_exit` (561 B jited), `sys_enter` (153 B), `tracepoint__sys` (185/311 B) —
  are byte-identical across all three, so their measured differences are drift,
  not code.
- BCC's BPF share is small (the audit puts it at 18% of the workload's CPU), so
  even a real per-invocation gain moves throughput by a fraction of itself.

## Drift, and why the first readings were wrong

An earlier pass measured the image objects at 1.0312x and the `.rodata`-only
configuration at 1.0072x, which looked like specialization helping. The
baseline arm's own per-invocation cost moved from 72.97 ns to 95.56 ns across
those runs while nothing in the baseline changed, and a lane-PERF guest
(8 vCPUs, 64 G, host CPUs 8-15) was running through both. Ratios taken across
that window are not comparable; the pair above is.

The 20% of the wall clock this exposes: a three-sample, 180 s measurement on a
guest that shares the host with another guest moves the ratio by tens of
percent. Any claim that a configuration is faster needs its two arms taken in
the same clean window.

## The 1.221x claim in `kprog/perf/one-image/README.md`

That README states 1.221x per invocation for the specialized objects and
`sys_exit` 85.1 -> 41.9 ns (2.033x), from commit `92bcc279b`. Neither
reproduces here:

| claim | measured |
|---|---|
| 1.221x per invocation (specialized) | 1.0011x (`.rodata`+maps), 1.0072x (`.rodata` only) |
| `sys_exit` 85.1 -> 41.9 ns (2.033x) | 58.5 -> 57.7 ns (1.013x) |
| 1.006x per invocation (image objects) | 0.9820x |

`sys_exit`'s native object is 561 B of jited code in every configuration, the
same tag and length in the image, `.rodata`-only and `.rodata`+maps runs alike,
so a 2x gain on it cannot come from specialization. The README numbers were
taken in the window above and inherit its drift; the table here is the
replacement, and the README carries a pointer to this file.

## Reproducing

```sh
# the input capture (map contents, needed for --maps)
LOGS=/workspaces/kprog-raw/C/one-image-runs CMD=maps \
  kprog/perf/one-image/scripts/specialized-timing.sh bcc/set image <state> 1 10 0-7

python3 vendor/bpf/native_specialize_objects.py --app bcc \
  --capture corpus/results/<maps-run>/details/map-snapshots/bcc__set \
  --output corpus/results/bcc-maps-20261114 \
  --manifest corpus/results/bcc-samesource-20261114/manifest.json \
  --maps --publish

flock -w 5400 /workspaces/.agent-state/kprog-lanes/locks/timing sh -c \
  'LOGS=/workspaces/kprog-raw/C/one-image-runs \
   kprog/perf/one-image/scripts/specialized-timing.sh bcc/set \
   corpus/results/bcc-maps-20261114 <state> 3 180 0-7'
```

## Tool output: what the two arms make the tools print

Throughput does not test meaning. A replacement that drops, duplicates or
misreads events keeps the same invocation count and the same instruction count
per invocation. This application has a check for that: run the eight tools
against the frozen workload on both arms and keep their full stdout and
stderr. `kprog/perf/one-image/scripts/bcc-tool-output.sh` does exactly that,
and `tool-output-compare.py` diffs the two event streams by event identity
(kind, not timestamp), so per-arm timing noise does not count as a difference.

### The image's objects misread `struct request`

`biosnoop` prints `Unknown` in the DISK column on the native arm and the
device name (`loop0`, `sr0`) on the baseline arm. Every row, every run:

| run | objects | baseline DISK | native DISK |
|---|---|---|---|
| `bcc-tools-20261114` | image manifest | `loop0` (360), `sr0` (11) | `Unknown` (372) |
| `bcc-tools-ab-20261115` | this directory's manifest | `loop0` (139), `sr0` (12) | `loop0` (141), `sr0` (11) |

The same source, two object sets, opposite results. So the defect is in the
image's object, not in the current pipeline.

The mechanism is a compile-time `bpf_core_field_exists` fold. `get_disk()`
(`bcc/libbpf-tools/core_fixes.bpf.h:103-110`) picks a field by existence:
```c
if (bpf_core_field_exists(r->rq_disk))
        return BPF_CORE_READ(r, rq_disk);     /* request + 8  */
return BPF_CORE_READ(r, q, disk);             /* *(request) + 96 */
```

One kernel serves every lane, and that kernel (`7.0.0-rc2+`) has no
`rq_disk` in `struct request` — commit `f3fa33acca9f` removed it — so only the
second branch is right. The image's object takes the first:

| object | `tp_btf/block_rq_issue` | `tp_btf/block_rq_insert` | reads |
|---|---|---|---|
| image (`a07dfa5e…`) | `movq 0x10(%rsp),%rdx; addq $0x8,%rdx` | `addq $0x8,%rdx` | `request+8` = `mq_ctx` |
| this directory (`d8e5ab93…`) | `movq 0x28(%rsp),%rdx; addq $0x60,%rdx` | `addq $0x60,%rdx` | `*(request)+96` = `disk` |

`+8` is `struct request`'s `mq_ctx`, not a `gendisk`. `biosnoop` reads
`major`/`first_minor` from there, `MKDEV` produces a device number no partition
has, `partitions__get_by_dev` returns nothing, and the tool prints `Unknown`.

The image's object also carries both branches — `cmpl $0x50b00` (5.11) and
`setb %cl` on a `LINUX_KERNEL_VERSION` read — where this directory's object
folds the version test away entirely, and it keeps a
`R_X86_64_REX_GOTPCRELX LINUX_KERNEL_VERSION` relocation inside
`tp_btf/block_rq_issue` that the current object does not have. Both facts
point the same way: the image was built with `bpf_core_field_exists(...)`
defined as the constant `1` (`vendor/bpf/native_compat.h`, deleted in
`2f83ebd4b`), which folds the existence test to "the field exists" and
hard-codes the `rq_disk` branch. The current tree compiles against the target
`vmlinux.h`, where the field is
genuinely absent and the test folds to `0`.

Six of the eight objects are instruction-for-instruction identical between the
two sets once branch targets are normalised: `capable`, `opensnoop`, `runqlat`,
`syscount`, `tcpconnect`, `vfsstat`. `tcplife` differs only in stack-frame
addressing (`leaq 0x8(%rsp),%rdi` against `movq %rsp,%rdi`, same address).
`biosnoop` is the one object whose code reads a different field.

### The other seven tools

| tool | result | reading |
|---|---|---|
| `capable` | 15 kinds shared; post adds `21 CAP_SYS_ADMIN`, `6 CAP_SETGID`, `7 CAP_SETUID` | the workload's own stressors differ run to run; the dominant `21 CAP_SYS_ADMIN 1 allow` appears in both |
| `opensnoop` | 405 kinds shared; post-only keys are `stress-ng-sockf` on `/dev/zero` plus the harness's own child tools opening `/sys/kernel/debug/bpf_x86_native_lab/map_ptr` | workload arrival, plus the post arm starting tools that read lab debugfs |
| `syscount` | per-syscall table, both arms | counts follow the same workload drift |
| `runqlat` | 15 rows both arms, **0 kinds exclusive to either arm** | identical |
| `tcpconnect`, `tcplife`, `vfsstat` | header only, both arms | the stress workload opens no TCP connection and no vfs call the tools trace; weak evidence, kept for completeness |

So `biosnoop` is the only tool whose streams differ in **meaning**. It is also
the only tool that reads a struct field through `bpf_core_field_exists`, which
is why it is the only one that catches the stale fold.

### Reproducing

```sh
# the image's own objects (the third argument is the manifest's directory)
flock -w 5400 /workspaces/.agent-state/kprog-lanes/locks/timing \
  kprog/perf/one-image/scripts/bcc-tool-output.sh \
  /workspaces/kprog-raw/C/bcc-tools-<date> 20 0-7

# this directory's objects: pass the manifest itself
flock -w 5400 /workspaces/.agent-state/kprog-lanes/locks/timing \
  kprog/perf/one-image/scripts/bcc-tool-output.sh \
  /workspaces/kprog-raw/C/bcc-tools-ab-<date> 20 0-7 \
  corpus/results/bcc-samesource-20261114/manifest.json

python3 kprog/results/bcc-samesource-20261114/tool-output-compare.py \
  /workspaces/kprog-raw/C/bcc-tools-ab-<date>
```