# Hand-written helper routines off: Workspace bpf-benchmark-lean (2026-11-18/19)

Operator 2026-11-18: "一边分析, 一边去一个新的 workspace 去把这些擦掉测试一下." Workspace yunwei356/bpf-benchmark-lean
(systems-dev, large-benchmark, node lab) was built from scratch at master 2bdb09335 with one local change (9e5d20b1d):
the linker receives no array, probe_read or LPM layout, so no hand-written helper routine is emitted and every
helper call in native code calls the kernel helper function, as the JIT does. Image 69e2e166, frozen entry
kprog/perf/one-image/Makefile corpus. Raw in that Workspace: /workspaces/kprog-raw/lean.

The comparison image is 3246e818 in bpf-benchmark-dev (all LTO, routines on; kprog/results/lto-all-20261118).
The lab node restarted at about 17:34 UTC on 11-18; the stats-on round ran after that, on a quiet node.
No reruns (operator 2026-11-19: "不要随便重跑").

Function: one-image check six apps rc=0; native replacements OTel 14, BCC 25, Cilium 113, Tetragon 288,
Tracee 169, Katran 1; native-loader failures 0.

| App | Per call (stats on), routines on -> off | Throughput (stats on) | Stats off, routines on -> off | Installed native/JIT |
|---|---|---|---|---|
| OTel | 0.986x -> 0.952x | 1.001x -> 1.062x | 0.950x -> 0.990x | 0.74 -> 0.70 |
| BCC | 1.019x -> 1.011x | 1.013x -> 0.997x | 0.954x -> 1.142x (samples 1.080 / 1.258 / 0.978) | 1.46 -> 0.77 |
| Cilium | 1.118x -> 1.278x | 1.049x -> 1.160x | 1.051x -> 0.945x (node load 15-17) | 0.78 -> 0.76 |
| Tetragon | 1.110x -> 1.027x | 1.062x -> 0.968x | 1.013x -> 1.010x | 0.79 -> 0.71 |
| Tracee | 1.369x -> 1.046x | 1.194x -> 1.035x | 1.332x -> 1.214x (node load 22) | 0.84 -> 0.76 |
| Katran | 1.049x -> 1.030x | 1.023x -> 1.024x | 1.065x -> run cut by the node restart | 0.68 -> 0.64 |

Reading: Cilium is faster without the hand-written map routines and fusion; Tracee and Tetragon lose the gain
that came from inlined probe reads; OTel, BCC and Katran are about the same. Code shrinks on every app.
Decision (coordinator): the routines stay deleted from master (07d9c4c96); probe reads and the other hot helpers
come back the way the design puts them, as C compiled with the specialized sim C in the LTO configuration.

## Test 2: per-app manifest options erased (2026-11-19, local a4d8336e7, image b3b5050f)

Erased in vendor/bpf/Makefile: Cilium source_map_prefix and prog_type, OTel --source-bpf-object, Tetragon
--dedupe-program / --source-object-root / --helper-disambiguate 174. One-image check, all six rc=0:

| App | Native replaced / native-loader failed | Before (test 1) |
|---|---|---|
| OTel | 13 / 1 | 14 / 0 |
| BCC | 25 / 0 | 25 / 0 |
| Cilium | 65 / 70 | 113 / 0 |
| Tetragon | 1 / 287 (manifest lists 648 variant entries) | 288 / 0 |
| Tracee | 169 / 0 | 169 / 0 |
| Katran | 1 / 0 | 1 / 0 |

The options select which native object or kernel-version variant belongs to a loaded program and bind its
tail-call maps. Decision (coordinator): replace them with one mechanism for every app: each native object is
paired with the BPF object it was compiled beside, and the loader picks the entry whose source program matches
the loaded program and binds maps through that source object's relocations (the design already names
source_bpf_object for map binding). BCC, Tracee and Katran need no option today and keep working.

## Tests 3-7: one manifest rule for every app (2026-11-19, local 51bf3ecd2 .. 6f47d2958)

Rule: every native object is listed as `native.o,source=src.o`, paired with the BPF object compiled beside it
(Katran X.bpf.o, BCC .bcc-libbpf X.bpf.o, Tracee tracee.bpf.o and lsm_support, Tetragon X.o, OTel tracer.ebpf,
Cilium siblings built with the same switches and `--target=bpf -mcpu=v3`). The writer records each entry's
section; the loader keeps entries of the loaded program's type (libbpf section mapping) and picks the one whose
source program agrees most with the loaded program: leading agreeing instructions (opcode, dst, src except
ld_imm64/call, ld_imm64 data reference or code), then agreement at aligned positions, then the closer length.
Maps bind through the source object's relocations when the whole function agrees. No per-app option remains.

| Test | Change | OTel | BCC | Cilium | Tetragon | Tracee | Katran |
|---|---|---|---|---|---|---|---|
| target (before test 2) | | 14 / 0 | 25 / 0 | 113 / 0 | 288 / 0 | 169 / 0 | 1 / 0 |
| 6 (a30ddfb33) | ld_imm64 data references agree | 14 / 0 | 25 / 0 | 93 / 6 | 288 / 0 | 169 / 0 | 1 / 0 |
| 7 (6f47d2958) | ties by aligned positions, then length | 14 / 0 | 25 / 0 | 64 / 0 | 288 / 0 | 169 / 0 | 1 / 0 |

Cells are native replaced / native-loader failed, one-image check, all rc=0 (raw in the bpf-benchmark-lean
Workspace, /workspaces/kprog-raw/lean/test7-check.txt and corpus run x86_kvm_corpus_20261119_070637_097806).
In test 7 the Cilium agent rebuilt the host endpoint 3 times in its window (6 times in test 6), so it loaded 64
non-probe programs; all 64 were replaced, tail_drop_notify included (5 of 5; test 6 failed 6 of 8 on a tie).
Decision (coordinator): the rule moves to master; the next image and six-app check run with it.
