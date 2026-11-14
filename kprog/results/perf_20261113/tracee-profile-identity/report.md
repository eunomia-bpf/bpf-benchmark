# Tracee profile program identity

The post-phase census contains both the retained original `trace_sys_exit`
and its installed native replacement. Baseline25 and retained original216
share tag `4dc9dfab1040a032`, 8227 bytes and 651 source-line entries. Native217
has tag `59f4a931744dcdc6`, 6359 bytes and no BTF/source-line entries.
`programs.json` records the exact binary paths and address ranges.

The shim log confirms original216/native217 and successful replacement
(`loader.txt`). Comparing baseline25 with216 therefore compares two original
JIT images. That comparison cannot establish native instruction identity or
identify replacement217's source-level call sites. C was notified to redo the
attribution with217 before collecting new helper-argument instrumentation.
The native read-failure cause remains open. A sample fraction under the
helper's EFAULT path is time weighted, not a per-read failure probability.

Raw capture: `/workspaces/kprog-raw/C/limits/tracee`; corpus run
`x86_kvm_corpus_20261114_185936_709485`. This result records identities only;
it makes no new performance or equality claim.
