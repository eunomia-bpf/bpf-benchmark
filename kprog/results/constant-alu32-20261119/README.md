# Constant ALU32 folding in B

Tetragon request 6 retains opaque ALU32 self moves of constant sizes and
helper IDs. The compiler cannot fold their subsequent dispatch branches;
the retained stack-pressure evidence is in `../tetragon-stack-liveness-20261119`.

The smallest fix extends the existing constant-identity pass to exact i32
`$0 = $0` templates with `=w,0` constraints and constant input. Live inputs,
memory clobbers, other widths, throwing and stack-aligned templates keep
their instructions. Shared I, native conversion, B flags, compiler/stock
stack limits and the frozen benchmark are unchanged. No new runtime check.

PERF 2026-11-19T11:31:24Z: The actual old compiler preserves all four constant
templates in the regression. After the fix, the sole checked-sim tools rebuild
through `make -C kprog/libnativeloader checked-sim-stage` under timing SH/image
EX. All four constants (8, 4, -1, INT32_MIN) fold to their exact i32 results;
live input, memory clobber and wide controls retain their asm. Both versions
emit a real BPF object. Raw baseline/candidate and build log are under
`/workspaces/kprog-raw/perf/constant-alu32-20261119/` with suffixes
`baseline-20261119T1130Z`, `candidate-20261119T1131Z`, and
`build-20261119T1131Z.log`. These checks establish the narrow compiler
contract, not new stock acceptance, native installation or runtime speed.

`run.sh` replays only Tetragon's retained O1 frontend through the new bounds
pass and unchanged O1 backend/packer/llc. It does not repeat the frontend or
the previous failed O3 hypothesis. Its input predates the recent shared-I
repairs, so successful emission would still require fresh app confirmation.

PERF 2026-11-19T11:34:23Z: The real BCC fentry_vfs_read and
inet_sock_set_state subset passes fresh B generation/libbpf-open and native
O3/proof compilation with the current shared header. B generation takes
0.996/2.747 s; observed direct R10 depths are 0/256 bytes. This is host
compilation, not stock verification or native installation. Summary is in
`bcc-subset.json`; raw is `bcc-subset-20261119T1134Z` under the directory above.
The preceding `1133Z` attempt omitted CLANG's canonical stock wrapper and
stopped at an unconverted `.8byte` private-input template. Its Make exit 2
and logs remain. Setting CLANG to `kprog/stock-path/bin/clang`, as the
canonical service does, fixes the test setup without a production change.

Detached Tetragon worker 353863 started at 11:32:35Z, raw
`replay-20261119T113235Z-353863`, source 0cb83f15d. Bounds lowering passes in
5.080 s: total folded constant identities rise from 556 to 931, while the
324 live empty identities and other normalization counts stay unchanged.
The 375 additional folds come from this exact constant ALU32 class. The
unchanged backend, packing and emission stages are pending. No new stock,
whole-app or timing result is claimed.

PERF 2026-11-19T11:43:27Z: Canonical BCC functional worker 354948 completed
with host 0/app ok, run `x86_kvm_corpus_20261119_113739_128860`, source
3cb5c5356. Programs/native/B-generated/B-stock are 25/25/25/25, all checked,
zero direct fallback/failures. Installed bytes are 8,628 native versus 7,965
JIT. This confirms the changed B pass against stock for BCC. The existing
1 x 10 s functional run supplies no new speed ratio. Tetragon's retained
backend also passes (396.616 s); packing/emission and fresh Tetragon stock
confirmation remain open. Shared I and current image are unchanged.

PERF 2026-11-19T12:30:54Z: The completed post-fold MIR scan shows this
constant-folding hypothesis worsens Tetragon's register allocation:

| Before packing | Original O1 | Constant ALU32 folded |
| --- | ---: | ---: |
| Machine blocks | 438,579 | 387,404 |
| Referenced spill objects | 719 | 1,804 |
| Four-byte spills | 105 | 1,277 |
| Eight-byte spills | 614 | 527 |
| Declared bytes, including locals | 5,764 | 9,756 |
| Conservative live-byte peak | 3,996 | 8,076 |

The current packer only narrows eight-byte scalars to four and merges two
four-byte objects into one eight-byte object. It does not overlay lifetimes.
Even granting every spill four bytes leaves 7,216 spill bytes, plus 432
non-spill bytes, above the unchanged 4,096-byte compiler limit. All 1,806
objects have references. CFG liveness is still not a feasible-path proof;
the separate object-storage calculation describes this packer's operations.

I ended only owned offline packer356045 with SIGTERM after that analysis.
The stage records return -15 after3,096.892s and the wrapper finishes2 at
12:30:54Z. This is a deliberately cancelled experiment, **not** an llc stack
rejection or stock-verifier result. No B object/emission claim. Completed
frontend/bounds/MIR and all logs remain in the original raw directory;
`cancelled-replay.json` and `post-fold-liveness.json` record the evidence.
The new scan (worker394832) finished0 at12:27:09Z; full observations remain
under perf/tetragon-stack-liveness-20261119/inspect-20261119T122559Z-394832.

Constant ALU32 folding remains implemented and BCC-stock-tested; it is
insufficient for Tetragon's stack problem. No production refusal, limit,
program skip or benchmark setting was added. The cancelled host worker
released timing SH so the already queued combined batch could proceed.
