# Actual shared C popcount call and imported CNT byte counts

The complete exported kprog_x86_popcount_value C call takes 11 actual transitions, including the true function entry and return, and preserves the entire arbitrary heap. Its actual arithmetic assignments determine the source intermediate values. Kernel-checked finite byte arithmetic relates the source result to the pinned LNSym simd_count_bytes for every 8-bit argument. All eight original shifted-and-masked CNT operands are proved to be the real zero-extended bytes, and the complete helper calls return their imported counts with the original continuation. This covers the actual byte-domain calls used by CNT; its reduction, vector stores and complete handler composition follow.

Focused build 179 and 3 public type/axiom queries pass at the original 200000/512 proof caps, shared timing lock, CPU 17, one worker and 32 GiB. The public log records the imported axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
