# Tracee replacement217: captured read-site evidence

The actual native `trace_sys_exit` replacement217 has4304 `memset`-leaf
samples among18216 samples on its probe-read paths. Baseline25 has0 among
27255. Program identities come from the captured census and actual loader
records, not a match on function name. Program216 is the retained original
and is not used as the native arm here. The values are time-weighted sample
counts, not read/failure invocation counts or a failure probability.

Callchains are leaf first. This analysis uses the nearest program frame;
two samples containing217 only as an outer frame are recorded separately.
The native innermost-program denominator is56612, baseline56627. The full
raw perf captures, both analysis attempts and disassemblies remain under
`/workspaces/kprog-raw/perf/20261114-tracee-probe-sites`.

The largest native zero-fill site returns at217+0x143b:575 memset-leaf
samples/976 probe-path samples. Its actual instructions reload rax from rsp,
set source rdx=rax+0x20, destination rdi=rsp and size esi=8, then call
0xffffffff84463980. The baseline's `bpf_probe_read_kernel` calls reach that
same address. This narrows the next comparison to pointer derivation and
CO-RE displacements at the actual sites.

A second native site,217+0x17d0, has212 zero-fill samples/470 probe samples;
it copies65 bytes from the pointer just returned by an eight-byte read.
Baseline25's captured source maps the distinctive eight/eight/65-byte
sequence to task.h153–155 (`get_task_uts_name`): task->nsproxy at+0xd70,
np->uts_ns at+8, then uts_ns->name.nodename at+0x41. The native sequence
uses zero displacements after loading the intermediate pointers. Associating
that native sequence with the same source function is an inference:217 has
no BTF/source lines. C should check the actual input object/CO-RE lowering
before attributing its source or changing code. The prior filtering.h site
attribution is not established for217 by the available source arrays.

`sites.csv` retains every sampled read return offset, helper, direct target
and available baseline source line. `sites.json` retains the peak and every
native zero-fill instruction window plus the captured baseline UTS source
windows. Exact runtime dst/src pointer values were not recorded; the contexts
show their register expressions. No new guest, probes, loader instrumentation,
producer edits or timing run was performed. C has these concrete sites for
its replacement217/source/BTF comparison; full Tracee equality remains open.

Source3a68bc781/8313406d3/ad3101f51, Make `tracee-probe-sites` in
scalar-spill-precision.mk, CPU19/8GiB address-space limit. Existing capture:
`/workspaces/kprog-raw/C/limits/tracee`.
