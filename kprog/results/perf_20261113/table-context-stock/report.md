# Single-context relative code table reaches stock verification

2026-11-15. Source commits 7e4eabb78 and 2d7297ec1. The fixture uses one real
KPROBE context pointer; its index is context word 10 masked by 15, and its eight
cases read constant context offsets. The exact same fixture C is compiled as
original BPF and direct x86. The native flags include O3, target CPU, sibling
calls, omitted frame pointer and kernel GPR/no-red-zone constraints; there is
no PIC or jump-table restriction.

The normal linker retains eight relative code-table relocations in the proof
and binds them again for the kernel layout. All 512 actual native host cases
match independent arithmetic expectations. The complete shared C simulator
also matches all 512, with the index and values carried by the context rather
than the old two-argument host fixture's explicit seed input.

The generated simulator compiles through the current single B pipeline:
piece preprocessing, canonical context loads, strict identities and normal
whole-word backend. No optional all-pairs flag was set. Final B SHA256 is
`83a9115bcab21b519842e63fc5dcafbd85d875af7e15367112001545da050499`;
bounds compiler `5236d0ea94daf23da9e89a98d00bcb8f6c18c389388f1bf76da4d2592e5987b0`;
normal linker `31806730e4d268e89b51806d2e0207812dc5e1b869e974d6f3304e5f90169955`.
All build products stay in the single canonical
`/var/tmp/kprog-tmp/perf/table-context` directory.

The final short functional guest exited zero on the sole 7.0.0-rc2+ boot
kernel, CPUs 16–17, 2 vCPUs, 2 GiB RAM, 8 GiB address-space cap and image SH.
It uses libbpf program loading only, so no old/new loader/linker pairing is
involved and it does not depend on pending base publication.

| Actual stock load | Program ID | Translated bytes | JIT bytes | Accepted |
| --- | ---: | ---: | ---: | --- |
| Original fixture `jump_table` | 5 | 288 | 161 | yes |
| Generated B `trusted_x86_x86_sim_xdp` | 7 | 400 | 175 | yes |

These are BPF program sizes, not native-P size or a speed comparison. Both
verifier logs and exact Make commands are retained. No KPROBE execution,
checked-native installation, application result, code-size target or runtime
gain is claimed. Native execution and shared simulation above are host checks.

Two test integration failures are retained: the first script omitted the
worker's import directory; a later host-model build hit the existing
unresolved-indirect compile-time error declaration. The host diagnostic now
maps that default to an abort function, as the earlier shared-simulator test
does; BPF preprocessing keeps its original unresolved-path behavior. Final
stock verification was repeated after that generated-source/debug-info change.
The first stock result also passed, but the final receipt binds the final B.

Raw root: `/workspaces/kprog-raw/perf/20261115-table-context`, with `final` and
`final-stock` terminal. `collect.py` reduces the complete vector log to counts
and its raw-file hash for the git receipt; all vectors remain persistent.
The earlier two-argument table fixture remains useful
historical evidence; this closes its single-context compilation/stock gap.
Checked-native installation, absolute and immutable map-pointer tables,
cross-function tables and actual application rebuilds remain open.
