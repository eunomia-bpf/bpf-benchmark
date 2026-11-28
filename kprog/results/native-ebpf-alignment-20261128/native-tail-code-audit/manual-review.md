# Captured tail-call review

SAME1357849 completed at2026-11-28T07:32:13Z. All five generated outputs match their controller sizes/SHA. All324 canonical blobs have captured plan matches; no plan key lacks a blob. There are208 matched candidate blocks (197 x86,11 ARM) and30 distinct byte sequences. All reported instruction diagnostics are empty.

| Architecture | App | Canonical blobs | Blobs with tail candidates | Candidate sites |
| --- | --- | ---: | ---: | ---: |
| arm64 | otelcol-ebpf-profiler | 13 | 10 | 11 |
| x86 | bcc | 25 | 0 | 0 |
| x86 | cilium | 64 | 50 | 97 |
| x86 | katran | 1 | 0 | 0 |
| x86 | otelcol-ebpf-profiler | 14 | 11 | 11 |
| x86 | tetragon | 38 | 26 | 42 |
| x86 | tracee | 169 | 43 | 47 |

The x86 variants differ in native stack cleanup, saved-frame-pointer recovery offsets and callee register pops. All29 contain the same target load at offset72, add12 and indirect jump; counter-pointer recovery uses displacement-16 through either live RBP or a saved RBP. The single ARM variant restores five callee pairs from its native frame, uses x26 for the shared count and loads bpf_func at72 plus entry28. Each actual sequence and the per-blob/site mapping are retained, with complete variant disassembly. These observations do not establish correctness of each surrounding frame.

All matched blocks apply index32 bounds, refuse count>=33, and update the shared count only after a non-null slot. Kernel ARM source computes its temporary increment earlier, but its shared store also follows the null test. Three refusal branches in every matched block converge on the block end. Captured layout constants are max_entries68, ptrs304, bpf_func72, entry12(x86)/28(ARM); all324 plans agree within architecture. Actual current ARM config/kernel prologue computation also gives28.

No change is justified by these checked instruction properties. BCC/Katran zero signature matches do not establish absence of executed tail calls; this scanner covers the emitted forms. Two full proof-entry identities remain unresolved because their original captured ELFs were truncated, although their blobs/plans are retained. Complete frame behavior, source-to-captured-build identity, kernel-installed code, dynamic targets/path counts and useful application work remain separate. The frozen ARM OTel loader issue means these static blocks are not proof of useful unwinding.

Newest resume followed: COORDINATOR2026-11-28T07:17Z. Frozen app2689 and ARM build/root2a87 are retained; proposed app689 remains archived. No activation, image/root/pin/flags/kernel/benchmark change or new runtime check occurred.
