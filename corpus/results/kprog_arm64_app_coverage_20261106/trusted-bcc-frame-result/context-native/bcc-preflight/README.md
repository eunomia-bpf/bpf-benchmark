# BCC tcplife compiler preflight

The existing trusted-bcc-frame-check Make target compiled the real ARM tcplife native entry inet_sock_set_state using the same frozen context/compact worker that passed the45-case native-only suite. Compile status0; maximum BPF fp-minus offset352 bytes. Original native ELF, generator native copy and compiled BPF hashes were independently checked against the complete archive; all frozen worker hashes were unchanged.

This uses source-ELF libbpf pre-load map facts, not kernel-pinned request facts. It is host compiler evidence only; it does not establish verifier acceptance or a BCC application run. The unchanged stock bcc/set two-start workload is the runtime entry for later integration. No application, guest, kernel/module or image was started or rebuilt here.

compiler-inputs.tar.gz contains the original complete compiler-run archive, original summary, wrapper, existing Make invocation/log, input hashes and exact frozen worker/dependencies. Generated C/BPF, disassembly and source/native ELFs are inside compiler-run.tar.gz. Summary.json records the outer archive SHA256 and native/source symbol identity table.
