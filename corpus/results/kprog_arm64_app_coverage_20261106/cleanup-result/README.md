# Lane A cleanup

Required source and compact results were committed and pushed before deletion.
Eleven old app-coverage run directories, inactive untracked/ignored result
outputs, duplicate diagnostic builds and lane scratch were removed after live
process/FD checks. Tracked source, summaries and compressed counterexamples
remain. Exact counts, retained builds, live inputs and filesystem free-space
observations are in summary.json; concurrent lanes can also change free space.

The first pass protected both OTel compilers and v18's v15 frozen inputs. The
old v18 job then completed: 10/14 compile, four LLVM aborts. Its compact result
is kept in ../otel-old-input-compiler-result; v18/v15 are retired after that
summary is committed. Only the current v36 job output is ignored until collection.
The retained v35 runtime and canonical native-link/application stage remain.
Shared incremental caches are preserved, and no fresh rebuild ran.

The lane directory retains current prompt/checkpoint state and active OTel
scripts/logs. The current pin_runtime.py still reads T/context-v2-exclusive-choice
when v36 reaches runtime preparation; this dependency is reported to T.

The first deletion pass used the stale shared-index file list and removed 17
just-committed files. All 17 were recovered from the pushed HEAD; all 20 kept
source/result paths were then checked byte-for-byte. Subsequent ownership and
retention checks use HEAD trees, never the shared index.
