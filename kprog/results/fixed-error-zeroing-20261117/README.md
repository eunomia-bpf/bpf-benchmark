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

Completed 2026-11-17T17:41:13Z: source `a5bb61c40` is pushed. Host process
2683911 exited 0. The release suite passed 54 tests, with 3 existing ignored
tests. Existing fixed read/policy/fault/zeroing fixtures execute 88 forms;
the added assertions cover 14 count encodings, including u32::MAX's full
word counter and seven-byte remainder without executing a huge copy.
All 98 probe forms retain protected-load bytes, instruction lengths and
R11 recovery destinations after offset mapping. Forty-five generic or
unrelated payload/metadata files and 423 memory bodies remain identical.

Representative routine-local bytes, including the return instruction:

| Compact leaf | Before | After | Saved |
| --- | ---: | ---: | ---: |
| Kernel/user scalar, count 0 | 168 | 127 | 41 |
| Kernel/user scalar, count 1 | 178 | 144 | 34 |
| Kernel/user scalar, count 8 | 179 | 146 | 33 |
| Kernel scalar, count 144 | 196 | 176 | 20 |
| User scalar, count 144 | 200 | 180 | 20 |
| Generic kernel/user scalar | 285/281 | 285/281 | 0 |
| Generic compat scalar/string | 679/647 | 679/647 | 0 |

The handler restores RDI from the saved original destination, preserves
RAX's error and uses the original proven count rather than the remaining
copy count. Reusing the existing displacement encoder avoids a second
encoder. The redundant setup-byte parameter is removed, and only the
generic path needs a zero-length exit patch. The production change adds
22 net lines; the existing count test gains 17 lines, with no new fixture
or framework. These assertions catch count truncation, RAX clobbering,
destination access at zero count and code growth proportional to size.

Evidence: [host output](host-output.txt), [all local sizes](sizes.txt),
[protected-load mapping](sizes-and-loads.json),
[payload comparisons](payload-comparison.txt),
[memory comparisons](memory-comparison.txt) and
[raw location](host-location.txt). The recipe is `274b93fa0`. Raw compiler,
execution, source patch and publication output stays in
`/workspaces/kprog-raw/perf/fixed-error-zeroing-20261117/host-20261117T174028Z-2683911`.

The primary effect is smaller cold error handling. Success-path copy,
policy, helper and map work is preserved; a per-call gain cannot be
inferred from this size change. Whole-app per-call time, body/helper/map
cost, throughput, equal work and installed native/JIT bytes remain for
Omp's image/check/target-app batch with all LTO on. PERF started no guest
or image. The independent helper-prototype wiring finding remains with
its frozen-code owner. Cross-leaf tail sharing remains a separate item.
