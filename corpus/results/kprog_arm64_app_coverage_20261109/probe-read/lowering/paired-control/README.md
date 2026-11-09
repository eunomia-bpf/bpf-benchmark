# Paired ARM native producer code size

The actual eleven-object compiler control uses the candidate command lines, Armv8.1LSE target and identical original BCC/paired Tracee C. The captured original plugin source supplies the control; the candidate adds the generic scalar probe-read lowering pass. Both payloads retain complete application translation units. Measurements below describe executable ELF sections and static native instructions/calls. Actual whole application work counters follow the existing queue; R owns restored May29 hardware workload throughput.

| Unit | Compile exit | Control bytes | Candidate bytes | Control calls | Candidate calls | Scalar read sites |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| bcc/capable | 0 | 736 | 736 | 16 | 16 | 0 |
| bcc/biosnoop | 0 | 1268 | 1188 | 30 | 24 | 11 |
| bcc/vfsstat | 0 | 272 | 272 | 0 | 0 | 0 |
| bcc/opensnoop | 0 | 848 | 848 | 26 | 26 | 0 |
| bcc/syscount | 0 | 636 | 636 | 14 | 14 | 0 |
| bcc/tcpconnect | 0 | 1404 | 1416 | 38 | 30 | 8 |
| bcc/tcplife | 0 | 1076 | 900 | 32 | 18 | 15 |
| bcc/runqlat | 0 | 1504 | 1392 | 37 | 27 | 12 |
| tracee/tracee | 0 | 1476028 | 1050608 | 32337 | 14423 | 17935 |
| tracee/lsm_support/kprobe_check | 0 | 64 | 64 | 1 | 1 | 0 |
| tracee/lsm_support/lsm_check | 0 | 64 | 64 | 1 | 1 | 0 |

Plugin Make exit:0. Compile successes:11/11. Runtime admission additions:0.
