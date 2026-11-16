2026-11-16T08:15:00Z

The native payload every guest reads now carries one LLVM module per program
object, plus the runtime context compiler at the payload root. Both come from
PERF's 06:53/06:50 contract: `-Xclang -fembed-bitcode=all` on the one flag set,
one `llvm-link` module in OTel's aggregate, tool at
`/opt/bpf-benchmark/native-bpf/x86_64/kprog-perf-context-lto`.

## What changed

`vendor/bpf/Makefile` (commit `b27e7c253`):

- `NATIVE_CFLAGS` gained `-Xclang -fembed-bitcode=all`. The bare driver flag is
  rejected next to `-mno-red-zone`; the cc1 form is the one that works with the
  unified target flags every app already uses.
- `$(OTEL_NATIVE_OBJECT)` no longer trusts `clang -r` to aggregate IR. `clang -r`
  over two objects that each carry `.llvmbc` produces **one** section whose
  contents are the two unit modules back to back (`llvm-readelf -S` shows a
  single 0x26c0-byte section for a two-object toy build), which is not a module
  `llvm-link` can read as a program. The rule now: `clang -r` for the machine
  object, `llvm-objcopy --dump-section .llvmbc` per unit, `llvm-link` those
  into one module, `--remove-section .llvmbc --remove-section .llvmcmd` on the
  aggregate, then `--add-section .llvmbc=<linked module>`.
- New `LLVM_OBJCOPY ?= llvm-objcopy-18`, plus `OTEL_NATIVE_IR_DIR` and
  `OTEL_NATIVE_IR` beside `OTEL_NATIVE_OBJECT`. `BPF_LINK ?= llvm-link-18` was
  already defined at line 16 and unused; it is the linker now.

## Verified

Embedded IR, per object, on the staged payload (`ir-coverage.txt`):

| app | objects carrying `.llvmbc` |
|---|---|
| katran | 4/4 |
| bcc | 8/8 |
| cilium | 7/7 |
| otelcol-ebpf-profiler | 1/1 (the aggregate; manifests reference only it) |
| tracee | 3/3 |
| tetragon | 88/88 |

OTel's aggregate, specifically:

- exactly one `.llvmbc` (section 94, 0x4071c bytes) and no `.llvmcmd`;
- the section is byte-identical to the llvm-linked module (`cmp` on the dumped
  section against `…/native/otel/ir/otelcol-ebpf-profiler.llvmbc`);
- `llvm-dis-18` reads it as a single module with 130 definitions and the units'
  target attributes intact (`target-cpu="arrowlake-s"`, `noredzone`);
- `native_tracer_entry` present.

The context compiler on the payload P:

- `kprog-perf-context-lto otelcol-ebpf-profiler.native.o --symbol
  native_tracer_entry` → `PERF_EVENT LTO converted loads: 10`, the same count
  PERF reported for the retained IR;
- native-link proves the converted entry: 6434 bytes, 42 relocations;
- the tool has no `libLLVM` in `ldd` — LLVM is statically linked, as the
  contract requires.

Codegen is unchanged by the flag. Every rebuilt object's `.text` is
byte-identical to its pre-flag version: 110 of 110 objects measured (bcc 8,
katran 4, cilium 7, tracee 3, tetragon 88), each compared against a snapshot
taken before the flag was added.

The aggregate was rebuilt from the final `core-compat.h` (`e688689e6`, 07:36),
not the intermediate 5ec form, and its proof marker reran at 08:04, after the
build. Every app's proof markers are complete: katran 4/4, bcc 8/8, cilium 7/7,
otel 1/1 (26 programs), tracee 1/1, tetragon 88/88, status
`native-objects-proof-linked`.

OTel's `source_bpf_object` survived: all 26 manifest objects name
`tracer.ebpf.amd64`.

## Payload state

`vendor/build/native-bpf/x86/stage` is a gitignored build output; `payload-md5.txt`
records what the guests would read (111 native objects + the tool). The tool is
52 757 056 bytes (LLVM linked statically), mode 0755, so it lands executable at
the root of the payload directory the frozen Dockerfile copies whole.

Fifteen stale OTel unit objects from 02:34 sat in the stage next to the
aggregate. No manifest referenced them (`native_object` is
`otelcol-ebpf-profiler.native.o` for all 26 programs) and no current code reads
them, so they were removed rather than left to confuse a later reader. The
aggregate and its build-tree units are untouched.

## What this is not

Own-counter parity and the six-app host replay are still pending, so no timing
claim follows from this. The image is still `d9e29630`, which predates this
payload; a rebuild is what puts the IR and the tool into a guest.
## Reproved on the rebuilt linker

The payload's own proof markers ran at 08:10 against the release linker built at
03:12, before PERF's numeric-helper-tail source (`152ca8054`) was compiled. To
confirm the payload is not resting on a stale binary, every manifest entry that
names a symbol was proved again with a linker built at 08:39 from current source:

| app | entries with a symbol | prove |
|---|---|---|
| katran | 3 | 3/3 |
| bcc | 26 | 26/26 |
| cilium | 75 | 75/75 |
| otelcol-ebpf-profiler | 24 | 24/24 |
| tracee | 96 | 96/96 |
| tetragon | 77 | 77/77 |

301 of 301. The 54 entries across five apps that carry no `symbol` field are a
pre-existing manifest shape — the old `tet-manifest-ab-20261116` manifest has
the same 17 missing in tetragon alone — not a producer change.

## Timing: this payload costs OTel its whole gain

Measured on the rotate's 10:24 stats-off OTel run,
`x86_kvm_corpus_20261116_102445_806916`: **1.021x**, with post_rejit
throughput *below* baseline (324,431,106 against 369,715,211 median ops).
Against `010841_344218`, still 1.854x (632,045,385 against 381,112,434).

The program that differs is `custom__generic`, the per-event kprobe. Diffing
`bytes_jited` program by program against the 2.020x run
(`053859_493069`), it is the only program added — absent there, 9257 B here —
while five others move by 27-2032 B and the remaining seven are byte-identical.
Every full-throughput run, keyed by that program's native size:

| native `custom__generic` | runs | ratio |
|---|---|---|
| 6452 B | `20261110_173026`, `20261110_231509` | 1.832x, 1.885x |
| 9400 B | `20261114_174202`, `20261114_180807` | 1.060x, 1.161x |
| 9257 B | `20261116_102445` | 1.021x |

Its original is 3679 B, so every native version triples the body — and the
6.4 kB version keeps OTel's 1.85x while the ~9.3 kB one loses essentially all
of it.

Two explanations that do **not** hold, checked: the eleven programs sharing tag
`26449268576adffc` share it in the healthy 1.854x run too, so that is
pre-existing; and `custom__generic` was also linked and replaced in
`20261110_173026` (1.832x), so replacement alone costs nothing.

So this payload should not be counted as a win until `custom__generic` comes
out near its previous size. The OTel number to quote stays 1.854x.

## Repairing the stale image line above

`d9e29630` was replaced on 2026-11-16 by `3a1906ab1d4f` (09:04:03Z), which
carries this payload: the guest's
`/opt/bpf-benchmark/native-bpf/x86_64/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o`
is `9c074c02bebc2ccc0ca56f9537002b8d`, the staged object, and the shim is the
one with `probe_lsm_file_` (`7ec409df99c953dfa606dfe541da71ee`).

