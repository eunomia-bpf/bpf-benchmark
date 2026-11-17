# Constant scalar probe sizes

First implementation slice: give the existing register constant worklist
the code-table edges already resolved by helper provenance. Facts join at
every target and retain the existing call-clobber and partial-write rules.
Unknown or non-boundary targets retain the existing empty-fact result;
there is no new load refusal, runtime guard, limit or public schema.
The new test uses a nonzero ELF address and equal/unequal size joins.

This slice also enables the existing memory-routine specialization where
an otherwise resolved indirect branch previously discarded all constants.
It does not yet emit constant-size probe leaves, clone a policy body, or
claim an app time/installed-byte change. Follow with internal branch count
metadata and the single-count scalar copy described in
`../leaf-batch2-20261117/next-lto-step.md`.

`edit-cfg.py` previews by default and applies with `--apply` only in the
single checkout. Host validation takes timing SH/image EX, uses CPU19 and
the canonical release test build, retains raw evidence under /workspaces,
then commits/pushes exact paths under Git EX. All existing LTO stays on.

Validated 2026-11-17T15:23:26Z: foundation58898e6ba passes46 tests/3 existing ignored with26 retained files identical. Sourcefc29c0ac9 passes48 tests/3 existing ignored, all26 generic files identical, seven ELF helper-binding shapes and88 fixed host execution combinations (22 counts, two domains, compact/wide). Dynamic/mixed-count callers retain their prior body. New native/proof tail-consumption bookkeeping also fixes conditional helper PLT32 linking.

| Scalar leaf | Generic compact | Fixed8 compact | Fixed144 compact |
|---|---:|---:|---:|
| Kernel |351|221|242|
| User |355|225|246|

These are host payload bytes including RET. `copy-sizes.json` records every case and its source recovery-site count; actual 144-byte execution has18 qword reads through one static source site. Zero counts have no source load. `copy-host-output.txt` and `copy-payload-comparison.txt` preserve the passing suite and original generic byte comparisons. The first two failed attempts stay in raw: first reused compat-string fixture mode8 and missed consumed PLT32; retry moved new modes to10/11, then exposed that consumption was recorded only for proof, not native emission. Final retry marks the field consumed in both existing ledgers and passes. No new validation gate, per-call check, size cap, flag, public schema, kernel/module or benchmark change was introduced. No image/guest or app per-call/body/helper/map/installed measurement by PERF; Omp owns that batch.
