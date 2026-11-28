# Packet field census completion

SAME1398321/controller1398323 completed09:06:22Z:20commands0,18real Cilium/Katran objects across bothISAs,176programrows (172audited/4placeholder),348typed first-level field GEPs,0unresolved ordinal maps,0missing candidate symbols. Original43 outputs remain byte-identical. All20 Cilium/Katran objects and4manifests still match inventory; canonical kernel products and8source/inventory hashes match.

The original BTF reader missed bpftool `(anon)` members, leaving204 comparisons unresolved. That result-reader gap was fixed in7cbd1eb0c; the short09:11:40Z-09:11:42Z metadata repair re-read only2canonicalBTFs and reused completed IR/DWARF/callgraphs/indices. The addendum now reports336 declaration offsets matching BTF,8anonymous VLAN container sites,4known public XDP ingress sites; all have a defined-call path from a manifest candidate. This is not live branch or context-origin proof.

The8VLAN sites are cil_from_netdev/cil_to_netdev onbothISAs. Targeted actual DWARF/IR review resolves vlan_all156/u32 tested only for nonzero, and vlan_tci158/u16 zero-extended then masked4095. Canonical BTF has those same nested offsets. The kernel public vlan_present rule normalizes raw vlan_all to0/1 and vlan_tci loads a halfword. This compares the native operations with the kernel rule, not the selected eBPF app source or loader feature set.

The4public ingress GEPs occur in ctx_get_ifindex/ctx_redirect (bothISAs); raw staged frontend IR precedes common-source repair6c8fdc70f, so this is not a new unfixed finding. Katran TC cb is declared at40 instead of BPF's qdisc-adjusted48 onbothISAs, but there are0typed Katran cb GEPs here. That unused declaration difference does not establish a selected-use defect and does not justify a frozen app-header change.

No new selected-use offset defect established; no production code changed. Raw/zero-offset accesses, sockets/other context types, indirect/asm effects, widths/bit/probe semantics beyond the targeted VLAN check, pointer provenance, live constants/branches and installed-code parity remain separate.
