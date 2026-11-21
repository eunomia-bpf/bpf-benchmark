# The fp-arithmetic class is fixed in the pass (OMP 2026-11-20T23:5xZ, 2141a0e00)

The transform in `PATCH-FOR-PERF.md` is now in `kprog/x86/packet_bounds_ir.cpp`
(`eliminate_stack_pointer_subtractions`, run after `anchor_pointer_differences`). Two things learned while
making it work, each of which had made an earlier version a no-op:

1. **The refused shape is nested.** In the optimized IR OTel emits
   `%inner = sub i64 %s, %p` (both sides pointer-derived, so the existing `pointer_bits()` cannot tell them
   apart) and then `%outer = sub i64 32, %inner` before the compare. The instruction the verifier refuses is the
   *outer* one once the inner becomes the anchor's tied asm: `32 - (s - fp)`. It is integer-identical to
   `(32 - s) + fp`, which is one scalar subtraction plus a pointer add, and that is what the pass emits.
2. **The stack frame must be told apart from a register-valued pointer.** `pointer_bits()` is true for both
   operands, so the distinguishing predicate is `ptrtoint` of an `alloca` (through constant adds) — the
   simulator's own frame — versus a plain register value. That is the same distinction the verifier makes:
   `fp` cannot be subtracted, a register-valued pointer can.

Fires on the captured requests: **52 sites in request 7**, 15 in request 10, 1 in request 11, 0 in the two
small ones (which are the separate `modified ctx ptr` class, `%2` rather than an alloca). The algebra was also
checked directly in 64-bit wrapping arithmetic, and the rewritten IR carries the intended shape
(`%scalar_difference = sub i64 40, %2135`, `%2139 = add i64 %scalar_difference, %2136`).

## Not yet measured

The base's `packet-bounds` (md5 `39560de80b86...`) is still the pre-patch binary, because the coordinator's
six-app rotation was using it when the patch landed; rebuilding the base mid-rotation would change the pass under
a running measurement. Sequenced after the rotation:

1. rebuild the base compiler in place (`make -C kprog/libnativeloader checked-sim-stage`), recording the new
   md5;
2. `checked-corpus` for OTel and read the coverage line — the class should stop appearing in the failure mix,
   while the four `invalid mem access 'scalar'` requests and the one `unbounded memory access` remain (they are
   a separate class), so OTel moves from 4/14 to at most 9/14;
3. then the two timing arms that are already queued (`queue-final.sh`).

A full OTel program exceeds 1M BPF instructions in this harness (errno 7 = E2BIG on the guest verifier), so the
per-object check is done on the captured per-request sources, not on the whole app.

## The change is inert where it does not apply

The strongest check available without a full app run: on the two captured requests where the new transform finds
nothing (r8, r13 — 0 sites each), the pass's output bitcode is **byte-identical** to the pre-change binary's
(`cmp` on both). So any program without the nested `A - (s - fp)` shape comes out exactly as before, and the
change can only affect programs that carry the refused instruction. The old binary was built from
`HEAD~1:kprog/x86/packet_bounds_ir.cpp`.

That also means the coordinator's rotation is unaffected in principle - it is running the pre-patch base binary,
and the apps it measures only change where the class applies (OTel).

## Measured: OTel coverage 4/14 -> 14/14, zero failures

Two runs of the same `checked-corpus` entry, the second with one more fix:

| run | installed | failed | note |
|---|---|---|---|
| `otel-after-pass-20261121T0230Z` | **11/14** | 3 | pass change in, `copy_from_user_nofault` not in the link plan |
| `otel-nofault-20261121T0245Z` | **14/14** | 0 | also binds the two nofault routines (8e0d92c7f) |

The first run is what the fp-arithmetic pass alone buys: the three remaining requests are not the subtraction
class at all, they fail in `native-link` with
`x86 helper call copy_from_user_nofault has no helper address`, because the inline probe-read wrappers in
`kprog/x86/micro-prog/inline_probe.c` call the kernel's own nofault routines and nothing bound their addresses.

Both symbols are global text in the one kernel line (`copy_from_user_nofault` at ffffffff8153f040,
`copy_from_kernel_nofault` at ffffffff8153f1b0 in that build's System.map), so the second change is the two names
added to `native_lto::kernel_symbols`, which the link plan has bound for `ktime_get_mono_fast_ns` and `jiffies_64`
all along. Coverage records: `after-pass/coverage.json` (11/14) and `after-pass/coverage-full.json` (14/14).

This is coverage on the verified path, not a timing result: the app still has to be timed, and the two arms
queued behind the coordinator's rotation are what speak to performance.
