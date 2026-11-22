# Actual pointer writer retains represented raw values

The exported pointer writer now has one actual 53-transition execution proof
for represented Vlong and Vptr values. Both stores, payload/tag readback and
caller/cache frames follow from the original producer storage and permissions.
The earlier raw-bit API delegates to the same execution and retains its types.

Arm64PointerValueFrame carries that result to all GPRs, SP, all SIMD pairs and
NZCV, using the existing explicit ValueRep address binding and native update.
The linked execution retains the caller continuation and actual composite
layouts. No source payload is coerced to a scalar, and no successful store or
post-memory is a premise. All eight tag bits are preserved.

The focused 185-job build, including old frame/linked clients, and seven public
type/axiom queries pass at original proof limits, CPU17, one worker and32GiB.
The first cast-normalization diagnostic is retained in raw data. Full root
confirmation follows the CSEL composition batch. This is a writer law; generic
handler dispatch, frame free, full handlers, O1/O2/O4 and M5/M6 remain open.

Raw: /workspaces/kprog-raw/formal/m5-pointer-values/20261122T110830Z.
