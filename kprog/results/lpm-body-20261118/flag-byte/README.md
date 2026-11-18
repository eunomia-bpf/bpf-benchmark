# Keep the trie intermediate-flag test to one byte

Scope: the existing bit0 test in x86_lpm_lookup.rs. The sole kernel's
trie_lookup_elem emits `testb $1, node+flags`. On x86, native code can use
the same byte test for the existing live flag and retain the same branch.
The smallest production change is its opcode and immediate width: F7/imm32
becomes F6/imm8. The predicate, load location, helper ABI and trie walk stay.

The existing compact/wide displacement test uses the new byte form. The
existing bit/prefix/flag reference expands its flags from0/1 to0/1/2/0x100/
0x101/0xffffffff and tests `(flags & 1)==0`. This catches treating unrelated
flag bits as intermediate nodes and retains the exact-max-prefix rule.
The full current suite, all295 actual captured links and original compiled
body driver run through the parent candidate.sh recipe under timing SH/
image SH, CPU19, one Cargo worker and32GiB AS. The canonical CLI remains
in use by checked Tracee2754970.

The immediate prior source is90f2dda0a, raw
/workspaces/kprog-raw/perf/lpm-body-20261118/candidate-20261118T012655Z-2851937.
Use parent compare.py --before with that replay.json. Expected size is3B
per retained trie range; actual emission and body cost follow the host run.
App installed native/JIT, per-call, body/helpers/maps and throughput remain
omp's frozen image/check/affected-app batch with all LTO enabled.
