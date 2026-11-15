# Constant-length word hash

The completed compact-loop pair regresses Katran's native program-text profile
52.27→68.16 sampled ns/call. This forward change keeps one generator and emits
straight-line4/8/12/16/20-byte hash and comparison blocks. Live map key_size
selects the block; each block folds the seed-length addition, unrolls Jenkins
chunks/final words, and compares fixed offsets. VIP20 is covered.

The same generator handles other positive word lengths with its general loop.
The original kernel byte-key helper handles non-word and zero keys. No new
key-length limit, map-name guess, metadata, flag, producer or native P changes.
All LTO pieces remain enabled together. Collision word mismatches recheck the
remaining bytes in kernel memcmp order; raw element/nulls/RCU/lifetime semantics
and original caller value/perCPU/LRU adjustment remain.

45 Rust tests pass with one preexisting ignored timing test. The actual2480-byte
fixture passes49178 kernel-reference/table/page-end/unaligned/hash/collision/
null/retry/ABI vectors. A new decoder regression verifies constant hash blocks
execute no chunk loop or tail dispatch. Whole-app counters and body samples
follow on the sole image; host vectors alone establish no speed gain.

Published23:20:14Z in sole image741f8227/CLIf7de4bfc; kernel/modules and1252
native image files unchanged. Actual-plan replay gives12958-byte payload.
Direct one-image corpus1x10s/stats1 completes both armsOK in run232350_572949.
This is a functional subset; C's breadth-first stats-off/on round supplies
full measurements. No removed timing wrapper or observer is used.

Timing-setting correction: the short check starts23:22:11 with1x10s; the
23:21:43 notice freezes3x180 defaults, read23:28. That launch was a lane
mistake. All diagnostic outputs remain; future timings use unchanged corpus
defaults with the permitted app and stats selections. Installed native12990B,
JIT13641B; no full-duration speed claim is made here.
