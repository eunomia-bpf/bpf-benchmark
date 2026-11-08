Generic ARM live skb cb byte accesses

The complete Cilium cohortd81268950 reaches a native eight-byte cb window whose corresponding BPF context offset is60. Stock bpf_skb_is_valid_access requires offset modulo access size zero. The simulator candidate carries the same existing cb window and four widths through byte lanes, preserving exact values and neighboring bytes at every native alignment. Packet pointer fields and other native fields retain their established paths.

The existing142080 host full-state/width/alias observations pass with UBSan. The identical existing TC BPF source, packet/context inputs and O2/BPFv4 compiler flags compile at the existing stack setting. The existing2GiB/two-vCPU QEMU control loads through the stock verifier and executes with retval31; guest and QEMU exits0. This is generic simulator component evidence. Complete Cilium consumption follows the shared five-step migration and live application source epochs.

The BPF form keeps each width's complete byte read/write sequence in a single inline assembly fragment, matching the host byte-lane value model. Initial source-continuation and register-pressure diagnostics accompany the archive. The final source patch changes the cb access representation; the existing window, widths, test cases, inputs and flags retain their values. Added check/gate/limit/validation count0. The source profile includes the established stack byte-arm candidate.

The final fragment retains the existing compile-time constant-displacement form and the existing variable-offset byte-value path. Each address follows its established instruction representation and reaches the stock verifier. The identical142080 host observations, BPF compile and TC/QEMU control pass again, with retval31 and guest/QEMU exits0.
