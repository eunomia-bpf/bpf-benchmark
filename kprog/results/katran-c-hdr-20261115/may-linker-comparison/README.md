# Preserved May-build linker and current Katran code

Read-only replay uses the preserved May-build linker from
`/workspaces/kprog-raw/paper-tree-untracked/native-sim/x86/native_lab/native_link/target/release/native-link`.
All cases use the same current Katran P and recent kernel/map facts; this
reconstructs reference linker output, rather than a May live-code capture.
No old source or build is created.

| Replay | Payload bytes | Decoded instructions | External relocations | All static calls |
|---|---:|---:|---:|---:|
| Reference |10164|2218|27|30|
| Compact word LTO |11016|2487|18|36|
| Constant word LTO72a2c1d37 |12958|2945|18|36|

Both reference and compact output begin with the same entry instructions and
contain zero LFENCE instructions. Reference has8 original clock calls and
11 external lookup calls:6 raw hash,2 other lookup and3 generic. Compact
replaces these with8 fast-clock calls,1 raw hash and1 generic fallback plus
internal calls to shared LTO routines. Map-provenance handling also differs:
the May source tracks register names linearly, while current handling drops
facts at joins. Call counts alone do not establish runtime cost or equal work.

The available profiles explain much of the apparent body increase. External
hash drops20.576→8.252 and table walk14.759→11.716 sampled ns/call while program
text rises52.272→68.160. Total root periods on captured BPF callchains stay
146.778→146.227ns/call, and retained native source stays45.893→45.573. Hash work
moves inside the sampled program-text range. Missing callchain frames and
sampling skid remain caveats; this observation establishes no pure-body1.50x.

The former normalized pair remains recorded at1.015468x per call/0.994092x
throughput. The resumed six-app round uses direct one-image corpus and
stats-off throughput against the May floor1.113x; it will provide the matching
comparison under the operator's simplified timing instructions.
