# One joined preprocessing product, unchanged compiler bytes

354bfbcbb removes each temporary `.pieceN.c/.pieceN.i` after appending its
expanded tokens to the joined `.i` input. Generated canonical C, joined input,
frontend IR and B retain their existing definitions; raw compiler commands,
stdout/stderr and resource observations remain with the caller. This avoids
keeping successful expanded pieces beside a duplicate joined input.

The focused compiler check loads the prior d9ae8bb90 function from git into
memory, with no source tree or file copy, and compiles the same fixture at the
same paths before replacing each build output with the current version.
Two actual preprocessing pieces are forced in both versions to exercise the
join and source-file lifetime. The joined input and default B object are
byte-identical. Default versus the previous backend command, explicit0, and
the optional whole-word backend's allocated output also match their controls.
Actual commands/results are retained; no hash was generated as evidence.

Test sources0e4593e46/bffd94728; Make `backend-check` in
scalar-spill-precision.mk. Raw observations:
`/workspaces/kprog-raw/perf/20261114-preprocess-cleanup`, including the earlier
single-piece check. This is build-storage cleanup and default-byte evidence,
not a runtime speedup or whole-application acceptance claim. The already
running OTel/1K services imported their earlier functions and stay unchanged.
