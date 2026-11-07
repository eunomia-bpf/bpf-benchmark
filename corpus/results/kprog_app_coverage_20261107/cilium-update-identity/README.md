# Cilium update-call map identity regression

R's stats-off run x86_kvm_corpus_20261107_140240_997545 recorded33 native-link
failures: more than one source update call carried the same truncated kernel
map name. The linker incorrectly treated repeated calls as different identities.
`baseline.json` records the exact cause counts; the full raw shim log is retained.

Source map metadata now retains the actual kernel map address read from its FD.
The link plan carries this address on each update site; the x86 linker matches
it to the already resolved FULL native ELF map symbol's address. Repeated calls
or compiler-created extra calls reuse this same identity, without an ordinal
or first-unused-map guess. Truly dynamic/unmatched map identities keep the
original generic helper. A matching text name cannot override a different map
address. Older link plans without the optional field retain their existing
checks; the ARM selector is unchanged. Update map name/address enter the cache
key so identity changes cannot reuse an older cached specialization.

Validation: all85 existing/new Rust unit tests pass; release native-link and
both static/shared native loader builds pass. The two added regression cases
catch same-prefix different map addresses, repeated/extra calls to the same
map, a mismatching address despite an exact name, and a truly dynamic map.
No old tests were removed. The production change is local to metadata transport,
cache identity and x86 update selection; no app/program filtering or workload
change is included.

```
cargo test --manifest-path kprog/x86/native_lab/native_link/Cargo.toml
cargo build --release --manifest-path kprog/x86/native_lab/native_link/Cargo.toml
make -C kprog/libnativeloader
make -f corpus/results/kprog_app_coverage_20261107/cilium-update-identity/Makefile image
make -f corpus/results/kprog_app_coverage_20261107/cilium-update-identity/Makefile corpus
```

The replay is stats OFF, unbound native, normal JIT-to-native corpus protocol,
Cilium's unchanged endpoint packet workload, one2second functional sample on
CPUs16-19. It is not a reproduction of R's throughput measurement on CPUs0-7.
The overlay changes only loader and linker binaries; an existing post-exit
capture wrapper retains linked cache/JSON plans without changing workload args.
`inputs.json` pins the exact available base image and patched binaries. The
older b371 image inspected in the preceding session was already pruned; this
replay freezes the currently available R image and exports its matching kernel,
without rebuilding a kernel or changing the shared image tag. The base's old
linker is also retained privately for same-input offline comparison.

Runtime replay is pending. Unit/build success alone does not establish that
the33 failures are closed or that the application forwards matching packets.
