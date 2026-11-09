# Complete BCC native producer from frozen configuration and target BTF

The frozen May29 eight-tool CLI supplies the captured stable read-only settings. The native compiler replaces only their scalar volatile IR reads before the existing O3 backend. Capable my_pid remains a live configuration read because startup getpid supplies its value. Every original tool/program remains in both complete manifests. Each paired compiler uses the same original C/flags/division pass and a vmlinux.h dumped from the retained SMAP kernel BTF, so kernel structure layout is an explicit native compiler input.

| Tool | Control bytes | Candidate bytes | Control instructions | Candidate instructions |
| --- | ---: | ---: | ---: | ---: |
| capable | 646 | 328 | 188 | 96 |
| biosnoop | 1293 | 960 | 363 | 264 |
| vfsstat | 148 | 148 | 60 | 60 |
| opensnoop | 824 | 636 | 252 | 184 |
| syscount | 540 | 233 | 173 | 78 |
| tcpconnect | 1540 | 838 | 418 | 219 |
| tcplife | 1494 | 1010 | 357 | 255 |
| runqlat | 1477 | 943 | 452 | 288 |

Original CLI/C/JIT/workload and same-copy kernel emission retain their definitions. summary.json records all field bindings, replaced loads, exact ELF/section hashes, dynamic reads and target kernel/header identities. raw.tar.gz carries native payloads, manifests, IR, disassembly, commands and source. These are compiler observations; actual generated B, verifier/application work and R frozen05-29 throughput follow separately. Production/runtime admission additions0.
