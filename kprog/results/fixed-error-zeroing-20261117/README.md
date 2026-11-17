# Known scalar error-zeroing

Prepared 2026-11-17. This is item 3 in todo section 0, following the
known-count scalar copy and routine-local branch sizing.

The smallest change is to retain the already proven scalar count in the
existing error handler. A known zero emits no destination access; other
known counts use a bounded word loop and fixed 4/2/1-byte remainder.
The handler restores the original destination and zeros the full original
count after a partial fault. RAX retains the negative error. Unknown scalar
counts and strings keep the generic handler byte-for-byte. No additional
policy body, check, flag, helper identity, relocation schema or module is
needed. This does not implement cross-leaf zero-tail sharing.

`run-host.sh` takes timing SH then image EX before applying `apply.py` or
running the canonical release linker tests on CPU 19, with one worker and
a 32 GiB address-space limit. The existing 88 fixed execution forms cover
zero count, alignment, policy errors, early/mid/late faults and full-buffer
zeroing. The count decoder checks include u32::MAX without allocating or
executing a four-gigabyte copy. Protected load bytes, lengths and R11
recovery destinations are compared after offset mapping. All generic
probe/string/compat and unrelated leaves/memory bodies must compare equal
to the successful UID host run.

Only tested source, actual receipts and the optimization record are
committed and pushed before image EX is released. This applier is one-shot;
after it has applied, a failure requires a forward repair, not another
invocation of the original recipe. All raw output stays under
`/workspaces/kprog-raw/perf/fixed-error-zeroing-20261117`.

Host results and local sizes are pending. Whole-app per-call time,
body/helper/map cost, throughput, equal work and installed native/JIT bytes
remain for Omp's image/check/target-app batch with all LTO on. PERF starts
no guest or image for this host change.
