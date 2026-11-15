# Current helper-output lifetime oracle

2026-11-15. Test replacement0e89749a9, explicit outcome correction
dd9be72a8. Production headers, kernel, base, image and benchmark unchanged.
All native LTO stays enabled together; this validates existing behavior,
not a new optimization or runtime gate.

The old test called retired WRITE_ARG_PTR macros and expected below-SP
faults. Its link failures remain in prior load/store receipts. The replacement
executes the current pointer translation, libc loops and typed comm-helper
wrapper against an independent byte/fact model, with explicit zero and
nonzero environment inputs. It does not restore the removed guards.

Both x86 and ARM64 pass **200 cases each**, covering exact output-pointer
translation, memset/memcpy/helper writes, caller SP fixed at-32, five output
offsets (below, across and above SP), lengths0/1/7/8 and two repeated-byte
input words. Whole arena images and every saved-word tag are compared.
Below-SP reads must draw a new explicit input; live reads retain concrete
bytes. The repeated-byte pattern makes the ISAs' byte/word packing yield
the same observable chosen outcome without assuming every input is zero.

The x86 model checks that typed write helpers invalidate only overlapping
caller facts, while the current generic libc clobber path drops all facts.
ARM64 preserves nonoverlapping tags and full aligned copied-word tags under
its existing transfer contract. Both verify result bits/tag and an exact
helper pointer/length call before caller-register clobbering.

The host callback writes real bytes through the translated pointer and
supplies explicit comm success/error outcomes. It is not an executed kernel
helper. The one kernel's `kernel/bpf/helpers.c:261` uses padded/truncated
comm data with success0, and zeros the buffer/returns-EINVAL in `err_clear`.
The final test separates these outcomes. The first attempt incorrectly
treated zero size as the helper error cause; local source review corrected
that assumption. Size0 remains a wrapper-boundary test only: stock BPF's
verifier requires positive size, so this is not a stock-acceptance claim.
The initial160-case-per-ISA pass/logs remain under `initial`; the corrected
200-case-per-ISA run supplies the final conclusion.

The complete scoped target now exits **0**: load713, stack117,782,
explicit-input pointer/RSP/recovery14, store1,292,621 and both200-case
output-lifetime runs pass. No old failure was filtered. This closes the
obsolete helper-output oracle item, not all formal M4–M6 or whole-model ISA
fidelity. Production host headers still choose zero for UNSPECIFIED outside
BPF/CompCert; this oracle explicitly binds the input interface. General host
input matching and earlier released-stack hardware observer mismatches remain
separate obligations.

Reproduce `make -r -f kprog/test/native-relocations.mk load-oracles
OUTPUT=/workspaces/kprog-raw/perf/<run>`. Canonical host build remains
`/var/tmp/kprog-tmp/perf/load-writeback`; raw initial/corrected runs stay in
`/workspaces/kprog-raw/perf/20261115-helper-output-oracle`. Only logs/results/
hashes are copied here; no source/build copy or raw-data removal.

The next actual OTel stage is running as launcher898093/Clang898194 at this
receipt: `current-otel-frontend` (86142f67f/403d9770a),8–11/16GiBAS/imageSH,
no guest/timing lock. It uses the normal optimized LLVM frontend flags and
canonical `.bounds-input.bc`, after the current production CPP. It stops
before bounds/MIR/packing/B generation to isolate resource growth. Launch
snapshot is explicitly pending in `frontend-launch/launch-state.json`;
final output must be read next turn. No frontend success, full B/stack/app
acceptance or runtime performance is claimed here.
