# Widened-field zero comparisons use the original BPF register width

The shared target-BTF compiler now accepts a direct equality/inequality-to-zero
use of a widened unsigned field behind `--widen-zero-compare` (default false).
The old source type is insufficient: the same source u16 field is relocated to
an eight-byte kernel field, while the original BPF backend can compare either
32 or64 bits. The compiler consults that original ELF's actual CO-RE record,
function symbol range, load destination and first consuming jump. Unrelated
instructions may intervene; branches, register copies/clobbers and unsupported
uses retain the explicit existing unsupported-resize error. It does not guess
width from CPU flags or silently narrow to the original C type.

For BPF CPUs v2/v3/v4, both ==0 and !=0 load the sole kernel's start_boottime
field (source u16, target u64, actual offset3152). Each of six cases executes
1035 values:11 boundaries and1024 seeded inputs, including high32-only values.
The original ELF instructions are patched by libbpf, prefixed with a map-value
input, and loaded/executed on the sole stock kernel. Their return values match
actual userspace x86 code emitted from the resolved native IR in all6210
executions. Native disassembly contains a64-bit compare for v2 and32-bit
comparisons for v3/v4, so both width paths were exercised. This is compiler
semantics evidence, not a native-kernel application/performance result.

Before replacing the single compiler executable, the test retained the old
binary's output in memory. After rebuilding in the same location, the two
all-kind fixtures' complete bitcode and JSON reports are byte-identical with
the feature disabled. The disabled zero-compare rejection/report is unchanged.
Nonzero equality still produces the explicit unsupported-resize error even
with this feature selected; arbitrary widened expressions remain open.

The actual retained Tracee input (370 queries) produces byte-identical bitcode
with the switch off/on:11158928 bytes, zero comparison rewrites. The existing
narrow/wide load/store/helper-copy fixture also produces identical bitcode
(5276 bytes, two queries, zero rewrites). These are compatibility controls;
the latter is synthetic, not an application. The new feature changes neither
the selected Tracee/BCC/Tetragon producer choice nor the running OTel service.
All thirteen relocation kinds remain covered by the byte-identical fixtures.

Source768932a16/bfa7872a5/deb317444/62af4951d. Tests use
`make -f kprog/test/core-audit.mk zero-compare-build`, `zero-compare-run`,
`retained-parity`, and `width-parity`; expanded commands, per-case compiler
reports, patched-reference records, native disassembly and execution results
are under `/workspaces/kprog-raw/perf/20261114-core-zero-compare`.
The sole-kernel guest used host CPUs22–23/onevCPU/2GiB/imageSH/8GiB hostAS,
with no Docker disk/image/base rebuild or timing lock. The first guest failed
before execution because a read-only compiler mount point did not exist;
its complete kernel.log remains raw. Retry1 used an existing build-directory
mount point and passed all six cases. Original BPF/native fixture products
are replaced between cases, never copied per mode. No speedup is claimed.

The core audit can now consume each actual rebuilt set via
`AUDIT_ARGS='--inventory <paths.json> --app bcc'` (4d03f96ae), using the existing
inventory.json row format. C's producer integration/rebuilds and subsequent
object/app equal-work comparisons remain open under P-CORE-all.
