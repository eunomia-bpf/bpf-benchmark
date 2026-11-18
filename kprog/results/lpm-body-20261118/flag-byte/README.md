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

2026-11-18T01:37:50Z — The full62-test suite passes with four existing opt-in tests.
The existing bit/prefix/flag reference now executes104,760 cases over six
flag values in compact and wide layouts. The65,590 trie/guard/generic-ABI
vectors and named-shape execution cases also pass. All295 actual captured
requests emit successfully.

Each of157 shared trie ranges shrinks3B. The actual OTel fused range is
278→275B. Neutral app reductions are Cilium72B, Katran3B, OTel3B,
Tetragon51B and Tracee342B; BCC stays identical. Total471B, zero growth.
Helper targets, relocation kinds, map names and callee masks match.

Recovery-shape counts change in157 requests because their flag instruction
length changes7→4B. Reader28f3e242a attributes every case to exact bytes
`f7 42 14 01 00 00 00` → `f6 42 14 01` at the actual captured node_flags
field20. Its recovery destination remains65535, meaning the existing
memory-test treatment. Every other site retains its length/destination;
following offsets move3B. All295 ordered recovery lists match that mapping,
with zero attribution mismatches. comparison.json retains the raw shape
count differences and recovery.json provides the explicit classification.

| Query | Prior native ns | Byte-flag native ns | Same-run kernel ns |
| --- | ---: | ---: | ---: |
| Full hit |4.085 /4.090 /4.083|4.217 /4.199 /4.242|4.717 /4.591 /4.593|
| First-bit miss |2.743 /2.744 /2.745|2.750 /2.757 /2.746|4.405 /4.392 /4.398|
| Deep hit |101.071 /101.173 /103.949|107.376 /108.111 /107.675|109.878 /107.881 /108.507|

The deep native and kernel medians both rise in this host series, and the
full-hit native series also rises. This records the observed host costs.
The current run supports the static size reduction; isolated per-call
speed effect remains an app measurement. Every sample is retained, and the
same C driver, ordinary kernel return substitution, fixed stable-node
fixtures and code-extraction policy apply as before.

Production is one line changed in the existing emitter. Three existing test
lines change to exercise byte encoding and high flag bits. Branch count,
return values, intermediate-bit semantics, generic fallback, lifetime and
RCU contracts remain. Compiler/tool/kernel/module and benchmark interfaces
retain their current shape. The helper-body slice sizes are separate from
the app's installed code metric and half-size target.

Worker2855681 ended0 at01:35:18Z. Raw:/workspaces/kprog-raw/perf/lpm-body-20261118/candidate-20261118T013414Z-2855681.
It used the existing candidate.sh/candidate.mk under timing SH/image SH,
CPU19, one worker and32GiB AS. The canonical CLI remains2,978,744B with
mtime1794948232. Peer checked Tracee2754970 retains its base/image/CLI lease.
Omp owns the next frozen all-LTO image/check/affected-app batch, including
actual loaded named-lpm12 selection and app installed native/JIT,
per-call, body/helpers/maps and throughput. The original-FD/context-only
phase1 binding handoff stays with the frozen-core owner.
