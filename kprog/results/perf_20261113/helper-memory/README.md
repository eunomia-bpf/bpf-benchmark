# B helper memory contracts

2026-11-16T01:54:11Z

Numeric map-lookup calls now describe their key as readonly and noncapturing. Probe read/str helper calls describe a noncapturing write-only destination and readonly source. Their argument and kernel-internal memory effects remain read/write; the map argument is neither readonly nor noncapturing, and no argument/result gets a noalias promise. Unknown targets and other helper classes retain their behavior. Contracts come from kernel/bpf/helpers.c:44-60 and kernel/trace/bpf_trace.c:171-319 in the sole pinned kernel. Helper calls, guard asm, P, shared I, flags and published compiler stay unchanged.

The real stock-kernel regression passes 1,060 baseline and 1,060 normalized executions, including map key reads, successful kernel copy, failed user read zeroing, an overlapping source/destination kernel read, and unrelated local bytes. Existing host identity/equality/private-alias checks pass. First the test assumed adjacent attribute printing; LLVM inserts noundef/nonnull, so it now inspects each helper line. The second attempt lacked an explicit anonymous-pipeline lowering report path; that harness error and the premature missing-object guest failure remain in raw. The corrected build and kernel2 pass. No framework or benchmark change.

Raw: /workspaces/kprog-raw/perf/20261116-helper-memory. Main OTel frame is the next measurement; full refinement remains M5 and phase 1 acceptance stays open.

2026-11-16T01:58:25Z: actual main annotates134 calls (110lookups/24user probes), but code288400B/frame824B/52spills remain unchanged. Guards remain. No runtime or stock-app gain is claimed. The next diagnostic corrects partial-store liveness: a32-bit store defines its low bytes and does not read unobserved upper bytes.
