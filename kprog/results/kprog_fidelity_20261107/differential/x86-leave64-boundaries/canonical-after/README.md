# Strict LEAVE64 replay after canonical fault-precision repair

SAME saved CPU inputs and SAME observer binary; no native rerun. Published
canonical213d8d5aa2a7f6440e965d8282e625faaddfeafb, X86 SHA
494c5413e9d8a4f073dac915c7af294a7bf51de8826c69f5b0738d74b81df13b,
was snapshotted into F's isolated incremental reference cache. All eight
source/config blobs match that commit and are archived. No shared formal
cache, ISA, simulator, generator, module or kernel edit was made by F.

The reference build and this replay Make exited0. 33792 cases in 33
input classes (1024 each), one C9 instruction form, have zero mismatches and
zero unavailable classes. Every case compares all16 GPRs, full flags after
removing fault-delivery RF only, PC, captured operand bytes/permissions, and
fault presence plus modeled kind/address/width. Raw hardware flags remain in
the parent trace. SIMD/segments were not observed and are not claimed.
The adapter's fault mapping/comparisons are unchanged; only an explicit
33-class input-count option and computed summary count were added.

```sh
taskset -c16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-leave64-boundaries/canonical-after/Makefile reference
```

`reference-classes.tsv` gives every class count. Empty compressed mismatch
and unavailable streams, complete logs, exact source closure and hashes are
retained. The single new reference executable is archived in the original
8192-case canonical-after directory. Original strict1024 fault-type
counterexamples and the pre-LEAVE decoder refusals remain unchanged.

Only the actual no-LASS KVM33792-case profile is replayed here. Canonical-gap
crossings match non_canonical; every wrapped inaccessible read matches read
fault. The host LASS upper-half #SS behavior is a separate platform profile,
not silently normalized or claimed covered by the flat/no-LASS reference.
There is no active57-bit, successful wrapped load, CPL0 or whole-JIT ABI claim.
