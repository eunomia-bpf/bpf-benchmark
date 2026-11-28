# Remaining packet-context field census

Continue the native/eBPF alignment list after common XDP repair6c8fdc70f and selected-feature result7fb0d895f. Read18 actual native Cilium/Katran ELF objects and their retained IR across bothISAs. No source, P, manifest, cache, kernel, app, root or image is changed.

make audit retains canonical BTF fields from both kernel products, native context declarations from actual DWARF, typed first-level context GEP candidates from actual frontend IR, and defined direct-call reachability per manifest symbol candidate. It compares Cilium/Katran physical sk_buff fields with the BTF sk_buff (ingress_ifindex aliases skb_iif, cb requires the qdisc.data pivot). Katran physical xdp_md must be distinguished from Cilium public xdp_md using the data member type, not just the shared type name. Public XDP fields require kernel conversion rules rather than matching physical offsets. The old staged frontend IR precedes common load-time conversion.

The LLVM/DWARF ordinal correspondence requires equal member counts, preserving unresolved/anonymous mappings. Width/bit semantics, actual entry-context pointer provenance, live branch selection, raw and zero-offset accesses, socket/other context types, indirect calls and inline asm remain separate. A declared offset match or call-graph path is not full equality or executable path proof. Four placeholder rows are outside source replay. Ambiguous symbols keep all candidates.

ControllerCPU19; serial LLVM readerCPU16/48GiB AS, BTF metadataCPU19. One detached job is collected later. No performance/PMU work or frozen benchmark changes. Newest coordinator07:17Z OTel2689 activation HOLD and x86 image/timing owner remain active.
