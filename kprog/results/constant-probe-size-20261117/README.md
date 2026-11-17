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
