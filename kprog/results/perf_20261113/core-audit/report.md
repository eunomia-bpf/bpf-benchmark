# Target-kernel CO-RE audit of existing native outputs

Measured 2026-11-14 using the sole kernel build at74d1097af561, current staged
outputs, C's88-object Tetragon image export, and the selected combined OTel
candidate. Sources are untouched. Exact source/native paths for all127 objects
are in objects.csv; the full input list and per-relocation rows are retained at
`/workspaces/kprog-raw/perf/20261114-core-audit/matrix-v3`.

| app | objects | ELF relocations | equal answers | different answers | unobserved |
| --- | ---: | ---: | ---: | ---: | ---: |
| tracee | 3 | 34769 | 9663 | 24947 | 159 |
| bcc | 8 | 90 | 63 | 27 | 0 |
| tetragon | 88 | 65789 | 65239 | 108 | 442 |
| cilium | 7 | 0 | 0 | 0 | 0 |
| katran | 4 | 0 | 0 | 0 | 0 |
| otel | 17 | 0 | 0 | 0 | 0 |

Counts are static source ELF relocation records, including repeated queries and
branches the verifier/compiler may eliminate. They are not execution counts,
failure fractions, or an assertion that every differing source query executes.
The601 unobserved records remain open; their exact native debug root is absent.
No guest or workload ran for this audit. Existing performance numbers acquire
no equal-work certification from it.

The reference reads the original .BTF.ext records, uses libbpf's own candidate
search/cache, relocation calculation and BPF instruction patching against the
sole vmlinux BTF. Native answers use exact, flavor-preserving DWARF layouts from
the actual selected object and the actual native_compat existence policy. The
compiled macro fixture confirms the two Tetragon expression exceptions return0,
ordinary field existence1, and even absent type/enum probes1. This observes
layout/macro answers for the documented direct-native path, rather than tracing
every final machine instruction. Dynamic reachability is a separate question.

When an existing resolved-IR compiler report is available, its answer is joined
by local type ID, relocation kind and access string. Such a report is used as
the native observation only when allocated bytes AND allocated relocations of
its build object exactly match the selected native object. Full debug ELF
identity is not required. This catches a measurement error in matrix-v2:
syscount retained old debug types even though its code uses the correct
0xb30(group_leader)/0xd10(comm) values. Its code+relocations match the resolved
build. Matrix-v3 correctly removes those two false differences. Matrix-v2 and
the initial candidates/cleanup failure remain raw; they are superseded here.

Tracee's34769 source records all match its retained370-query resolver report;
BCC's90 all match their reports. The selected Tracee object differs from the
resolved-IR build in code and relocations. The active direct-native recipe
includes native_compat and bypasses the existing CO-RE compiler. Actual native
DWARF gives task_struct.nsproxy144 versus kernel3440(0xd70), nsproxy.uts_ns0
versus8, and uts_namespace.name.nodename0 versus65. Thus the retained resolver
already has the correct answers; the selected producer path loses them.

BCC's differing objects are biosnoop(9 records), runqlat(16) and tcplife(2).
For example runqlat's task pid/tgid layouts disagree with the kernel, while
biosnoop's request___x.rq_disk existence probe is forced1 against target0.
Syscount, opensnoop and tcpconnect match the resolved build's allocated bytes
and relocations. Merely noting different full ELF bytes would be misleading.

Tetragon has43 objects with108 differing records. Examples include
 task_struct___local.thread_pid96 versus2904 and cgroup___new.ancestors
 existence0 versus1. Generated canonical vmlinux types alone do not resolve
 locally declared flavor types. Its rows do not all match yet. The exact43
 object list and the complete Tracee/BCC list are in rebuild.csv; differences.csv
 groups duplicate source records without dropping their counts. Missing native
 roots can reflect eliminated types; no reachability conclusion is inferred.

Cilium's7 and Katran's4 supplied BPF objects have no CO-RE records. OTel's16
split units plus its selected combined object share the retained original BPF
ELF, also with no CO-RE records. This is an inventory of existing products and
the selected candidate, not a claim that17 OTel objects load together, or that
these apps have no other equal-work differences.

## Existing mechanism and producer handoff

The missing sole compiler product was rebuilt in place at
`/var/tmp/kprog-tmp/perf/core-ir/core-ir-lower` using the existing libbpf build,
without another library build or any source change. Actual ELF fixtures cover
all13 relocation kinds:22 relocation records/22 compiler queries exactly match
libbpf, including existence, offset, size, enum values, type IDs, matches and
bitfield shifts. mechanism.json and macro-policy.json retain the results.
This is compiler conformance, not native application execution.

C owns producer integration. The needed choice is the existing target-BTF
resolved-IR path, selected explicitly with its default unchanged, before native
context/helper/asm lowering. BCC already has BCC_SAME_SOURCE=1; the target BTF,
vmlinux header and release must all name the sole build. Tracee and Tetragon
need their source-compatible IR route and exact original BPF resource metadata.
Writable DATASEC binding is already implemented/tested in both configurations
(fae4cef0d and canonical LEA follow-up; writable-data-result.json); select
kernel_data_layout rather than folding away real branches to avoid the old BSS
write fault. All LTO pieces stay together. Producer rebuild, resolved-output
reaudit, actual app execution and equal-work comparison remain open.

Commands: make -f kprog/test/core-audit.mk audit / mechanism-check / macro-policy;
exact expanded commands and failures are under the raw directory. Source steps
0b17445fc,510b77839,cf8b5c0f8,0b5273a5a,ee44d226f,f1acb15d1,
10cc015f6,9ab6012a8,b244f3cfc. This adds measurement tools only and changes no
load-path checks, native optimization, default bytes, image, base or workload.
