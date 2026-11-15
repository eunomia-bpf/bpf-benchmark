# One invalidation for aliased stores

2026-11-15T10:45UTC. EXEC_STORE's ordinary-address arm invalidated saved
stack-pointer facts, then STORE_ADDR_TAGGED invalidated the same range again.
The first pass is removed in1e66d1be8. Both passes used the same captured
address/width, with no intervening fact reads. Invalidation still precedes
the volatile write; source capture, free-byte choices and post-store fact
saving keep their existing order. No P, flags, LTO or benchmark change.

Before the change,45e2f7ce0 adds4,224 independent alias-store cases. The
same cases pass after it: entire64-byte arena, all saved tags/pointers, all
six flags and exact free-input draw counts. Cases cover11 aligned/unaligned/
SP-crossing offsets, four widths, scalar/stack/map-value sources, shifts,
indexed addresses/displacements, immediate/register forms and zero/nonzero
environment choices. The expected byte/fact model uses interval arithmetic,
not the implementation's invalidation/save macros. The first after-launch
recorded only an empty launcher log; `after-retry` is the completed run.

The complete scoped suite also passes (713load/117782stack/14pointer-RSP/
1292621store/65538width/200helper per ISA). Actual native/shared-C store
comparison passes512 full memory/flag cases, and all16 normal B allocated
section hashes equal the pre-change outputs. Checked-C packet host execution
passes25 complete-context/qdisc-prefix cases. These are host and normal B
compilation results, not new B kernel execution or actual OTel acceptance.

Actual pre-SSA ordinary store probes drop331→309 and298→276 branches;
IR body bytes129366→122392 and116596→109524. Stack probes remain226/192
branches. The diagnostic is not full OTel compile or runtime performance.
The existing queued frontend921682 will capture the latest source after
910213 ends; no extra OTel job or canonical product is created. At10:45UTC
the width-only frontend911032 still runs on its earlier captured input.

One packet-host rebuild replaces45 known build files and preserves21 prior
raw metadata/log files. Exact paths/bytes/SHA/action/completion are in
`rebuild`, identified by `cleanup-summary.json`. Original results/logs stay
under `/workspaces/kprog-raw/perf/20261115-store-erase` and
`/workspaces/kprog-raw/perf/checked-packet-rebuild`. Only result/log/identity
files are archived here. All commands use committed Make targets and reuse
their canonical builds; no guest or timing lock.
