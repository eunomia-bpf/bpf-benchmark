# Common narrow-value identity

The x86 register reader first performs the canonical width/lane extraction, then carries that value through an empty pure compiler identity for narrow reads. Repeated reads of the same architectural bits retain one optimizer value. Every register bit, provenance tag and flag keeps its existing semantics.

The generic repeated-MOVZX/compare/index fixture compiles under both variants. Canonical C output compares one masked copy while indexing a different expression; the identity variant compares and indexes the same register. The actual captured Tracee source also compiles successfully: its first readonly lookup compares R2 with15 and then shifts that same R2 for indexing. Existing comparison host/UBSan controls pass52686cases with the coherent include pair. The whole Tracee successor uses this pair after the current serial queue; terminal verifier/application results follow.

Commands: C/narrow-value-identity/identity.sh and host.identity.sh, using Clang18/O3/mcpuv4 and the existing host controls. C denotes /workspaces/.agent-state/kprog-lanes/C. raw.tar.gz retains both actual-source compiler variants, generic fixture sources/objects/disassembly, checks and the private header pair; observations.json records source hashes and instruction counts. These are common mechanism checks and actual compilation observations.
