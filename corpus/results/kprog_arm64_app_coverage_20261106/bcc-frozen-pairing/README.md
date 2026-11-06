# Immutable native/proof pairing

All 23 captured BCC entries regenerated and compiled successfully. Each proof is
linked from a native ELF copied into the same phase before linking; the manifest
copies that exact native ELF beside the simulator artifact. Later changes to the
shared native stage cannot silently replace one half of the pair. Exact captured
BTF/type/bytecode-length selectors remain unchanged.

`build.log` records the make commands and all generation/compilation outcomes.
`replay.tar.gz` retains native ELFs, native proof ELFs, simulator C/objects,
commands, pairing records and the resulting manifest. This verifies artifact
pairing and compilation; actual application binder failures remain active.
