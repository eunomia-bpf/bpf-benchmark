Cilium source-reference diagnostic

The three saved-command configurations cover all 72 resident instances and compile with exit 0. Original source ELF, immutable initial census snapshot and published producer archive hashes agree. Their map definitions agree with the rebuilt references, including CILIUM_PIN_REPLACE=16 on cilium_calls. LIBBPF_PIN_BY_NAME=1 applies to ordinary named maps. The initial macro comparison is corrected by the actual tail-call declaration in vendor/bpf/cilium/bpf/lib/tailcall.h.

The rebuild is a diagnostic confirmation. result.json retains both identities, actual compile commands/exits, exact map definitions and instruction hashes. Xdp and host executable sections match; lxc tc/tail has equal byte length with a distinct hash. All native P and application/workload source bytes retain their captured values. The common temporary resource pinning view supplies the loader compatibility step.
