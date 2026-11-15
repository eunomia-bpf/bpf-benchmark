# Current perf hotspot frontend expansion

Entry perf_unwind_hotspot, program type7/perf_event, seven captured map
bindings. These are the actual matching entry/type from the retained OTel
request5 metadata (SHAe5c8459b6798aa812ef24253a87a143593ad28148499c3752076f1c4603e6e4a). The earlier scheduled-table
structural test used kprobe_unwind_hotspot; its context must not be swapped
with this one. Current canonical native SHAc50a8df99505eead7881bbd9bebb8eb9357fd53106feb7ff58a8f7781e393150, normal linker
45c33e7e. Map/type metadata is historical, not a fresh app capture or equal-work
certificate. Current native plus those explicit bindings is an offline
pipeline diagnostic, not an application load.

The normal production proof, render and chunk preprocessing complete in
19.67s under8GiB AS on8–11, using the exact existing flags and
piece size. Input: 6945 decoded instructions,
1,032,413 C bytes. Output: **431,680,679 CPP bytes**,
**418.13x** expansion. All commands/resource records retained.
This stops before LLVM B compilation, stack allocation or verification.

Attribution: MOV_LOAD127,980,936 bytes; STORE114,820,691; generic RUN_OP
46,688,668; ALU_REG27,199,843; MOV_IMM22,104,872. The largest nine generic
statements (SHIFTX, SHIFTX_MEM and BZHI_MEM) expand by roughly5.1–5.3MB each.
The generated specialization contract still routes SHIFTX/SHIFTX_MEM/BZHI/
BZHI_MEM through genericRunOp. The BZHI handlers already exist; SHIFTX arms
are inline in the generic chain. Next: express those existing bodies in the
direct specialization contract and prove/check equivalent output, then
measure again. Loads/stores still dominate and need separate reduction.
No claim that the scale problem or OTel backend compilation is fixed.

8fd8c9a7c only extracts preprocess_simulator from compile_simulator; its
flags, chunk boundaries, token joining and validation order are unchanged.
The scheduled fixture's complete B object SHA is identical before/after.
Normal MIR/backend checks, invalid-all-pairs early failure and60 real identity
execution cases pass. This exposes one stage for measurement rather than
creating a second compiler pipeline or runtime switch.

Canonical products replace /var/tmp/kprog-tmp/perf/otel-whole-word-checked.
Stale old spill-replay B/MIR/IR/native-input build copies were removed with
per-file identities after checking holders; the original request archive,
all old results/logs and deterministic spill recipe remain. Current proof/C/
CPP are retained as the sole build. No raw data was deleted. Raw measurement:
/workspaces/kprog-raw/perf/20261115-current-otel-preprocess.
