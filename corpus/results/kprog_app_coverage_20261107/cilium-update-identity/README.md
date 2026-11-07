# Cilium update-call map identity regression

Fixed in `070559db815cc400216f94791693d40c85f29385`. Actual stats-off unbound
Cilium replay `x86_kvm_corpus_20261107_151633_102078` completes: application
status **ok**, all177 application program loads replaced, zero native-load
failures and zero truncation ambiguities. This is a functional result on C's
CPUs16-19, not R's performance comparison or generation-bound coverage.

| Run | Native loads replaced | Native failures | Truncation ambiguities | App |
| --- | ---: | ---: | ---: | --- |
| R original140240_997545 |144|33|33|error|
| Initial address-only150159_654306 |144|33|33|error ENODATA|
| Full identity before neutralization151633_102078 |177|0|0|ok|

The original33 errors name cilium_ipv4_frag_datagrams(18),
cilium_ct_any4_global(5), and cilium_policystats(10). Repeated source calls
with a15-byte kernel map name are not different map identities. Source
metadata now retains the real kernel map pointer read from its FD. Before
native template addresses are deliberately zeroed for later relocation, the
producer binds every complete native ELF map alias to this source pointer.
The link plan carries these canonical names, and the x86 consumer matches
them exactly, reusing the same map identity for repeated/extra compiler calls.
There is no ordinal/first-unused-map guess. Truly dynamic/unmatched maps retain
the generic helper. Legacy metadata checks and the ARM selector are unchanged.
Update name, pointer and bound full aliases enter the cache key. Output map
pointers remain neutral.

The first live address-only attempt revealed template addresses0; its33
failures remain archived, rather than being counted as success. The new
zero-address template regression covers that actual producer/consumer case.
All86 Rust checks pass; release linker and static/shared loader builds pass.
The prior two new checks cover colliding prefixes, repeated/extra calls,
conflicting pointers despite an exact name, and dynamic maps.

## Actual work

Same unchanged bidirectional endpoint packet workload, one2second sample,
JIT then unbound native, BPF stats OFF. Both pktgen commands return0 with
zero errors. Native receiver/tx errors and dropped counters are all0.

| Arm | Forward sent | Opposite endpoint RX | Reverse sent | Opposite endpoint RX |
| --- | ---: | ---: | ---: | ---: |
| JIT |611409|611413|612157|612160|
| Unbound native |686831|686836|687182|687186|

Receiver snapshots include small background traffic; no exact equality of
work counts or throughput conclusion is inferred from this short sample.
Cilium native verdict deltas: reason0 direction1=1374021,
direction2=1374022; reason139 direction2=0 and reason3 direction1=0.
Stats-off BPF run counters are not execution measurements. Complete counters,
per-program native timing receipts and raw stdout are retained.

## Same-input linker comparison

For all16 captured link plans with repeated canonical identities for the
original failing maps, replay EXACTLY the same proof ELF and JSON plan through
the base's old linker and the corrected linker: old16/16 reproduce the
truncation ambiguity; corrected16/16 succeed; all16 corrected blobs are
byte-identical to the actual successful runtime cache. These are16 plans,
not33 loads. SHA256s, entry names and individual stdout/stderr are retained
in same-input-comparison.json and same-input-raw.tar.gz.

## Reproduction and provenance

```
cargo test --manifest-path kprog/x86/native_lab/native_link/Cargo.toml
cargo build --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml
make -C kprog/libnativeloader
make -f corpus/results/kprog_app_coverage_20261107/cilium-update-identity/Makefile image
make -f corpus/results/kprog_app_coverage_20261107/cilium-update-identity/Makefile corpus
python3 corpus/results/kprog_app_coverage_20261107/cilium-update-identity/compare.py
```

The result Makefile keeps R's available base401e818569d1 frozen and exports its
matching cached kernel, with no kernel build or change to the global image
tag. The overlay changes only loader/linker and an existing post-exit cache
capture wrapper, preserving workload arguments. inputs-neutral.json pins the
successful image, binary/source/kernel hashes and verified base layers.
inputs.json pins the INITIAL failed image; baseline.json and its full shim
log pin R's original failure. The old linker for forensic comparison comes
from that frozen base, SHA256 recorded in both inputs files; compare.py expects
it in lane-private state and the corrected packaged binary next to it.

neutral-live.json is the concise successful receipt. neutral-live.tar.gz
contains the COMPLETE raw corpus result and captured link cache; its SHA256 is
in the receipt. initial-neutral-failure.tar.gz and its receipt retain the
failed attempt. Both driver logs, build/check logs and comparison raw outputs
are archived alongside. Healthy guest/cache inputs and the1136-object scan
were preserved. R can now update BOTH loader and linker for its longer
counterbalanced timing runs; no performance acceptance is claimed here.


The corpus recipe removes its guest var-tmp Docker disk and exported image tar
on exit, after checking for open users. A later run re-exports the cached Docker
image when its tar is absent; it does not rebuild the image or kernel. Raw results,
request archives, logs, compiled caches and provenance records are retained.
