# Closed diagnostic of the withdrawn relocatable micro variant

The standard KVM micro run completed all29 attempted benchmark records and
exited2. The kernel JIT returned correct results in29 cases;23 cases also
completed native_kernel and native_proof, each with the exact expected64-bit
result and program-specific return value. All75 returned samples match.
The52 service requests comprise46 successful fresh bound loads,4 compiler
SIGKILL failures and2 loader refusals. Every request's kernel native bytes,
service-generation input and captured private-image object hash agree.

| Failed benchmark | Stage | Exact leading message |
| --- | --- | --- |
| trace_event_type_switch_dispatch | loader_refused | trusted-native-loader: BPF_PROG_LOAD native_lab stub: Argument list too long |
| bpf_local_call_fanout_dispatch | compiler_SIGKILL | clang return -9; cause not inferred |
| flow_5tuple_rss_hash | compiler_SIGKILL | clang return -9; cause not inferred |
| katran_lb_consistent_hash_select | compiler_SIGKILL | clang return -9; cause not inferred |
| siphash_rotate64_mixer | compiler_SIGKILL | clang return -9; cause not inferred |
| cilium_socket_lb_service_select | loader_refused | trusted-native-loader: BPF_PROG_LOAD native_lab stub: Permission denied |

All observations and exact errors remain in summary.json and the52 nested
request archives. Signal9 alone does not establish OOM; the captured console
has no OOM line. Loader refusals are preserved separately from the service's
generic EIO message. A failed native_proof attempt prevents that benchmark's
later native_kernel attempt in this run; those six missing samples are not
reported as successes or fabricated additional requests.

This is the explicitly withdrawn ET_REL alternative. It used29 newly compiled
objects from unchanged benchmark sources/flags with only the shared-library
link step removed, in a private cached image. The original userspace .so
hashes stayed unchanged. No equivalence to the existing ET_DYN input bytes,
execution time or failure matrix is claimed. The canonical integration is
C's original-P ET_DYN route with validator fix a974c406f.

The guest had2vCPUs/4GiB on host16-19, one sample and one repeat. It used
the cached TV kernel/module bundle and the standard __runtime-vm-micro
Make target; raw/driver/guest-command.json and run.py in raw.tar.gz preserve
the exact command. This is diagnostic evidence, not a performance result or
a second supported production route. No new run is requested.

F withdrew only its own catalog/build-source hunks after copying the private
image. Those two known host-source changes are explicitly retained, along
with the reconstructed exact source/patch checked against launch hashes.
The copied image inputs remained fixed. The actual captured micro_exec
SHA6af68aec matches the already-published stage2 runtime binary byte for byte;
that existing archive is referenced rather than duplicated. Source identities
for every request, image resolution/build log, object hashes and full micro
results remain available. The host image tag was not substituted with C's
subsequently refreshed tag.

C owns the active original-input integration and failure fixes. F's source
alternative is absent from production; source safety policy, loader
classification, benchmark workloads, kernel/module and simulator are unchanged
by this diagnostic. The failures remain open rather than being bypassed.
