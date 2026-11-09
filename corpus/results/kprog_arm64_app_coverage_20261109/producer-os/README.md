# ARM native P compiler comparison

Existing BCC and Katran native recipes compile identical application C at O3 and Os with the existing division pass, fixed-register ABI and architecture flags. The benchmark framework and workload retain their captured definitions.

| Object | O3 text bytes | Os text bytes | Os/O3 | O3 instructions | Os instructions |
| --- | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | 736 | 656 | 0.891 | 184 | 164 |
| bcc/biosnoop | 1268 | 1172 | 0.924 | 317 | 293 |
| bcc/vfsstat | 352 | 352 | 1.000 | 88 | 88 |
| bcc/opensnoop | 848 | 848 | 1.000 | 212 | 212 |
| bcc/syscount | 660 | 608 | 0.921 | 165 | 152 |
| bcc/tcpconnect | 1436 | 1428 | 0.994 | 359 | 357 |
| bcc/tcplife | 1076 | 1048 | 0.974 | 269 | 262 |
| bcc/runqlat | 1516 | 1240 | 0.818 | 379 | 310 |
| katran/balancer | 7812 | 7576 | 0.970 | 1953 | 1894 |

summary.json retains every compiler exit, command, static call site, dependency and source identity. inputs.tar.gz retains captured dependency source, native objects and raw compiler/disassembly/size output. Static counts describe code production; generation-bound application replay and restored-workload ARM hardware throughput provide functional and performance evidence.
