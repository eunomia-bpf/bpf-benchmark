# Tracee in the main-configuration recipe (2026-11-20 10:01 UTC, source e10ec26c4)

Run x86_kvm_corpus_20261120_100152_964232, recipe kprog/results/lto-apps-20261119/Makefile
(APP=tracee/monitor, 3 x 180 s per arm, stats on), omp's arm under `flock -x` on locks/timing.

- Coverage: 169 requests, **29 native installed** (5 checked-sim-c, 24 direct-native), **140 failed** and kept
  on eBPF. 135 of the 140 failures are `native-link: GOT-relative reloc against unknown symbol current_task`;
  the other 5 are the same error for `cpu_number`. Both symbols went away when 07d9c4c96 (11-18 20:31) deleted
  the hand-written helper reimplementations (x86_task.rs; `cpu_number` "lost its only consumer"). The emitted
  direct-native objects still reference them as GOT-relative relocations, and the kernel link plan no longer
  resolves them.
- Per call: geomean **0.884** over the 41 retained pairs, call parity 0.97. With 140 of 169 programs still on
  the JIT, most pairs compare the JIT against itself; the 0.884 is carried by the replaced hot programs.
- Read with the coverage line: this is **not** a 0.884x whole-app measurement. It is 29 native programs out of
  169. Fixing the `current_task` reloc is what makes the number mean something.

Raw: /workspaces/kprog-raw/omp/lto-tracee-20261120T1001Z (service archive with all 140 failure archives).