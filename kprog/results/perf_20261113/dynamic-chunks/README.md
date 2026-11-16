2026-11-16T03:20:11Z

Tracee `lkm_seeker_modt` needs 627 upload chunks. The direct module and loader previously capped every program at 512 chunks, aborting application startup.

The module now allocates chunk descriptors and creates the next `blobN`, `.relocs` and `.sites` endpoints during sequential upload. The existing wire format, 128-byte chunks, relocation boundaries and load-site boundaries stay the same. Open files keep their chunk indices across allocation growth. Chunk zero clears the preceding program's chunks; unload frees the descriptor array. Endpoint allocation failures propagate with partial endpoints removed. The loader's 512-count refusal is deleted. This replaces the fixed array without another cap or switch.

Host planner/wire/relocation regressions pass. Actual sole-kernel runs through `upload_and_load_stub` execute 627, then 1, then 1,025 chunks and return exactly their respective counts; every chunk contributes an ADD, so lost code and stale tails change the result. Existing direct default, cross-chunk fault recovery and reupload cases also pass. Guest CPUs16-19, image SH, hard8GiB address-space limit; module built in the sole canonical `kinsn/module/x86/build` under image EX. Image fc408f64 remains pending combined A-D/B publication. Whole Tracee load and timing remain open. Raw attempts: `/workspaces/kprog-raw/perf/20261116-dynamic-chunks`.
