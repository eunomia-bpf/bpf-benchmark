# Shared x86 readonly label identity

Proof and kernel native-link modes now use one resolver for local data objects.
Typed symbols retain their object bytes and identity. A zero-size readonly
label retains the whole section identity and its original offset in the
relocation addend. This represents LCPI/anonymous labels with their native
address relationships across link modes.

The prior implementation reaches its explicit PC32 zero-size refusal in the
constructed-ELF regression. The adopted implementation passes all88 native-link
unit tests with the current production crate. Its243 PC32 combinations cover
three instruction forms, three section extents, three original label offsets
and three relocation addends. Each compares complete readonly bytes, canonical
identity and the decoded final kernel address against proof relocation metadata.
Extent, overflow, writable-section and empty-section rejection controls remain
in the generic resolver test. This catches a mismatch between the proof symbol
address and the final linked native address.

Command from the repository:

```sh
cargo test --offline --manifest-path kprog/x86/native_lab/native_link/Cargo.toml --bin native-link
```

The existing target cache supplies the incremental build. production-check.log
in raw.tar.gz records88passed/0failed; prior-control.log records the original
failure. The archive also carries original/adopted sources, crate inputs,
constructed ELF test code, source fingerprints and initial compiler diagnostics.
observations.json pins the source and archive. The release executable retains
its original recorded hash while active runtime jobs use their captured image;
the next coherent image boundary supplies runtime adoption. Universal readonly
layout/address and native-link preservation laws supply the safety argument.
