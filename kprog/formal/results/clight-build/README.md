# Clight exports as formal build products

The 23 `KProgFormal/Clight/*.lean` files are generated from canonical C by
`clightgen -lean -normalize`. They are ignored build products. Lake runs the
`clightSources` target before reading this package's module inputs, then
delegates parsing/tracing to Lake's own input facet. A small import manifest
ensures every export participates in the first build, when directory globs
cannot yet discover generated files. Default library/executable targets,
package dependencies, toolchain and Lean proof limits stay unchanged.

```
cd kprog/formal
lake build
make clight-sources
```

The pure Make entry builds the existing frontend, then uses normal Make
rules and the frontend's `-MD -MP -MF -MT` dependency output for C and all
included headers. Unchanged exports keep their timestamps. Existing
`make clight` host oracles consume this build step. That entry no longer
rerenders the profile C from assembly/native-link; its sole C snapshots are
checked in and edited directly.

Seven profile C bodies moved from `build/*.bpf.c` to `c/` with their original
basenames and C bodies. Build symlinks retain the frontend input names,
which appear in the AST's `source_file` metadata, and preserve existing
oracle include paths. There is one C body per profile. No source tree or
second build is copied. Other C units continue using their existing paths.

Regeneration is compared byte for byte with Git revision `9c617740f` before
removing tracked copies. `compare.py` streams the original Git blobs and
compares every generated module, including metadata; it writes no baseline
source copies and uses no content digests. Cleanup paths are recorded in
`kprog/docs/cleanup-log.md`. Raw logs and metadata stay at
`/workspaces/kprog-raw/formal/clight-build`.

The first cold default build exposed Lake import discovery occurring before
ordinary extra dependencies. The final input-facet dependency and import
manifest address that ordering. The broader run also found unchanged legacy
proof failures, recorded in the raw default-build log; it is not a green
whole-package result. M5's 2,065 migrations/recount and M6 remain open.
The focused export/current-refinement verification and dependency tests are
recorded separately here. No runtime benchmark, kernel, base or image changes.

Final focused cold build: all 23 exports, the import manifest and fourteen
current refinement modules pass 164 Lake jobs with all generated sources
initially absent. An unchanged build regenerates zero exports. Touching
`c/Arm64Entry.h` regenerates exactly Arm64Entry, Arm64PayloadProfile,
Arm64Program, Arm64ProgramContext and Arm64ProgramFixture; all 23 remain
byte-identical afterward. Six current proof axiom queries and four public
type prints also pass. The bare default run's 25 unchanged legacy proof
files are listed in `legacy-failures.json`; removed local ISA helpers were
not reintroduced to hide those migration failures. Full logs stay in raw.

One empty ARM profile macro had a trailing blank removed when checking in
the C snapshot; regenerated Clight remains byte-identical afterward.
