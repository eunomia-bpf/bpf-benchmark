# Referenced code tables in a shared anonymous section

2026-11-15; linker `a7383af15`, real KPROBE fixture and stock test `f94aa8daf`,
following helper CFG support `399a6bab0`.

An anonymous `.rodata` section can contain code tables for several independent
entry points. Copying its entire section made the selected root's proof try
to resolve another root's table. The linker now copies the actually referenced
table's contiguous complete relocation slots, bounded by the next table start
across all source functions. Proof and kernel linking both rebase PC32 addends
to that copied origin. Actual nested code identities remain relocations; other
program roots are neither included artificially nor skipped from an app run.

The clang fixture has two independent roots and 16 source table slots. Each
root retains its own eight slots in proof and kernel linking. All **128 native
host cases** match their arithmetic reference. The last root's proof also
passes normal B compilation and **64 full shared-simulator host cases**.
The final Rust subset passes **39 tests**, with one existing ignored test.

The same C then supplies a real KPROBE BPF reference. On the sole kernel,
libbpf accepts reference `second_table` as program **5** (288 xlated bytes,
163 JIT bytes) and generated `shared_model_x86_sim_xdp` as program **7**
(400 xlated bytes, 177 JIT bytes). This is acceptance of the second root,
not KPROBE execution or an application measurement. Its two-root native host
coverage is separate. The short functional guest used CPUs 16–17, 2 vCPUs,
2 GiB RAM, an 8 GiB address-space cap and image SH. It used no runtime loader,
unpublished linker binary, changed image/base or native installation. Exact
commands, verifier logs and kernel release are retained.

C's rebuilt Tetragon `event_execve` now completes production proof rewriting
in the source-level test: **12,003 proof blob bytes and 81 nested relocations**.
Input SHA256 is
`d307c102c4a14cfe44995e9d697a2192d05a39ea53a8edf10ae439381305df35`.
That retained product predates the vendor-source split removal in `a01ef4879`;
it tests the linker shape, rather than certifying the new header-only producer.
This is a proof-stage result, not application B compilation, stock acceptance
or checked installation. Its 252 helper facts and 39 R13 call identities are
recorded in `tetragon.json`.

Raw evidence: `/workspaces/kprog-raw/perf/20261115-rodata-spans`.
The canonical build is `/var/tmp/kprog-tmp/perf/helper-cfg`; compiled products
are not copied into results. `build-inputs.json` binds the final stock inputs.
Earlier helper expectations, host integration errors and the original
whole-section proof failure remain in helper-cfg receipts. The normal CLI/base
publisher and registered functional jobs are still queued behind existing
consumers. Other actual objects, application acceptance and formal work remain
open; no throughput, per-call speed or code-size gain is claimed.
