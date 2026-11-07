# Private x86 numeric stack-pointer repair evidence

The candidate fixes the three remaining numeric SP differences and the
additional stack-alias compositions tested here. Its runtime header remains
a private candidate; production publication follows the combined immutable
formal/micro validation, queued behind V's published ROR FULL check.

| Measurement | Forms / sequences | Cases | CPU/C differences | CPU/reference differences | C/reference differences |
| --- | ---: | ---: | ---: | ---: | ---: |
| Full existing instruction matrix, candidate | 885 | 906,240 | 0 | not replayed here | not replayed here |
| Stack sequences, published f734 baseline | 25 | 25,600 | 19,456 | 0 | 19,456 |
| Stack sequences, candidate | 25 | 25,600 | 0 | 0 | 0 |

The 25 sequences cover copy/restore, chained LEA, scalar arithmetic, partial
8/high8/16/32-bit writes, alias memory accesses, full address spill/restore,
PUSH/POP and four spill widths. All16 GPRs, six defined arithmetic flags,
XMM0,64 stack bytes and256 external-memory bytes are compared. Canonical
X86Path checks every actual byte and successor through its existing finite
path interface; the new --linear-paths option supplies extents only. The
serializer maps the real saved SP base and compares full final memory.
Each run uses newly generated CPU states; before and fixed invocations are
not claimed to have identical ASLR addresses.

The runtime change retains typed private-arena pointers for addressing.
Numeric reads replace the arena origin with the same invocation's native SP
origin. Partial writes materialize old native bits before merging and
scalarizing. RSP pointer writes normalize either private-arena coordinates
or scalar native bits; LEA RSP,[RSP+d] normalizes once. No native bounds check,
fuel condition, runtime trap or verifier-only branch is added. The observer
now reads architectural values for ordinary registers, keeping only its
explicitly normalized RSP slot in relative coordinates.

The source baseline is published f734ec402 plus candidate-header.patch.gz.
producer-source.tar.gz contains the exact tested producer snapshot. It
excludes C's concurrent partial-stack prototype. Six focused Lean lemmas
prove arbitrary-base/wrapping projection, both RSP writeback cases, single
LEA normalization, partial-write composition with the existing generated
write theorem, and native guest bytes. These are supporting arithmetic
refinements, not a whole-program theorem. Initial Word-name shadowing and
Windows Unicode preparation failures remain archived; the corrected focused
build passes on frozen published ecf0a8020 dependencies.

The unchanged25-case KVM suite rejects every case:18 verifier,6 specialization,
1 loader,0 accepted. Exact messages and all inputs are in the sibling negative
results. The first attempt produced19 manifest-match infrastructure errors;
adding explicit source_btf_symbol=neg_source to F's fixture plans supplies
the identity already required by the loader. The same compiled proofs are
reused, and source matching is not weakened. No unsafe body is executed.

Four valid programs execute through the actual generation-bound path and
return2/packet0; captured generations are4/8/12/16 with mask0. They cover
copy/restore SP, alias loads, full spill/restore and partial aliases. Frozen
T699 probe/CLI/module and the matching private TV kernel are used, preserving
all shared binaries. Their exact bodies, proof inputs, checked snapshots,
native/JIT bytes and logs are retained in the sibling positive results.

Commands through bws.sh from /workspaces/repository:

```sh
python3 kprog/fidelity/x86_stack.py --source /absolute/frozen/producer --out /absolute/build
cc -O1 -g -std=gnu11 -static -Ivendor/libbpf/src -Ivendor/libbpf/include/uapi /absolute/frozen/producer/kprog/fidelity/driver.c /absolute/build/generated.c /absolute/build/native.S -o /absolute/build/cpu-differential
/absolute/build/cpu-differential 1024 /absolute/new-output /absolute/new-output/cpu-states.bin
python3 kprog/fidelity/reference_check.py --reuse-trace --linear-paths --binary /absolute/build/cpu-differential --reference kprog/fidelity/build-multiply-xchg/source/kprog/fidelity/build-cpu/reference --arch x86 --cases 1024 --out /absolute/new-output
```

The full885 CPU matrix uses the frozen generator's normal x86 forms. Native
builds/functional checks use host CPUs16-23; guests use2vCPUs/2GiB. Recreate
its frozen source from producer-source.tar.gz; the parent of the build output
must contain the identical driver.h for the existing generator's relative
include. The canonical source/static reference remain in sibling
x86-multiply-xchg. The negative fixtures use the committed negative.py
build/bound commands; positive.py records exact probe commands. All885 CPU,
25-sequence fixed CPU/reference,25 negative and4 positive run stages pass.

Three completed raw traces are retired after publication and no-reader
checks, per coordinator disk instruction. Their hashes/sizes remain in
trace-retention.json. All baseline counterexamples are compressed and
retained. The latest published ROR producer plus this same SP patch is being
validated separately; it is not silently substituted for this tested source.
