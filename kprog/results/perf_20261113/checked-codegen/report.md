# Checked native codegen uses the normal optimization flags

2026-11-15. Source 6e8b11208, host tests a7af36eaf, queued kernel test
99c31dd2e, command retention e3cd8ee93. All pushed to master.

The trusted B-to-native IR compiler no longer forces `no-jump-tables` or
`disable-tail-calls`. Checked native emission removes PIC and uses O3, the one
target CPU, sibling calls and omitted frame pointers. Kernel GPR-only,
no-red-zone and no-stack-protector constraints remain. This is the trusted
checked compiler; the production P frontend is unchanged.

The one standalone compiler was rebuilt at
`/var/tmp/kprog-tmp/perf/checked-compiler/compile-sim-ir`, SHA256
`907b671d1a921c7ccd4bcd4ede69f72d23766511093bbb2069f619045802937e`.
The installed base is still the old pairing while the census holds image SH.
Pending publisher 783752 now includes this compiler with normal loader,
linker and bounds tools, all under the same image EX update. No kernel or
runtime-image rebuild was performed.

Independent subsets ran in one `make -k -j3` batch and exited zero:

| Check | Result |
| --- | --- |
| Already-stock-accepted single-context table → checked native | 512/512 host cases match independent arithmetic |
| Existing XDP, TC and cgroup-SKB physical packet-context fixtures | 25/25 return values and complete context bytes match native P |
| Reachable architectural and unresolved-dispatch faults | 8 safe cases; both fault children terminate with SIGILL |
| Unsupported simulator assembly | explicit compiler failure retained |

The checked table uses the exact source/frontend IR that produced the accepted
B SHA256 `83a9115bcab21b519842e63fc5dcafbd85d875af7e15367112001545da050499`.
Actual checked native SHA256 is
`7855a155d1b57e53ee3ba873f3054134d1088aa758f2c48a842343e614af7eee`,
with 191 executable bytes in its native object. It emits a real relative
code table; the normal linker binds the table and the full-width private input
map pointer before host execution. Private input values vary during the cases.
This size is a fixture observation, not an app size or speed result.

The first host attempt omitted `kprog_unspecified_input`, which the actual
loader already supplies as a direct-value capability. Linking failed clearly;
no stock/kernel failure was inferred. The corrected host test supplies that
same capability through the normal plan/map-patch ABI. Full failed and final
logs remain raw; no production fallback was introduced.

The kernel installation test is queued as PID 800038 behind publisher 783752,
then image SH, CPUs 16–17, 2 vCPUs, 4 GiB RAM and 16 GiB address-space cap.
It reuses the existing registered capability replay: real source-object
context is checked against the fixture declarations, stock verification
precedes checked compilation, then the loader installs checked native code.
No kernel result exists yet. Canonical inputs stay in
`/var/tmp/kprog-tmp/perf/table-context`; the guest writes updated compiler
outputs there, without another build copy. Existing census/scale jobs remain.

One optimization lead remains after phase 1: the native table fixture begins
with 24 volatile reads of the private unspecified-input value whose results
are unused by its context arithmetic. These contribute instructions and bytes,
but no measured runtime cost is claimed. Any elimination needs to preserve the
trusted compiler's input semantics. It is recorded as a candidate, not applied.

Raw root: `/workspaces/kprog-raw/perf/20261115-checked-codegen`.
`collect.py` keeps bounded receipts; full vectors, commands and failed attempts
remain persistent. No checked-native kernel installation, app equal-work
completion, throughput/per-call speedup or hard size target is claimed.
