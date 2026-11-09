# ARM native scalar probe-read producer candidate

The existing native compiler plugin lowers helper113 calls with a discarded return and a constant size1/2/4/8 to a single opaque native load and an exact-width destination store. The existing native exception-table destination-zero/resume defines its read-fault result. Named BCC calls and the actual final-input Tracee helper marker share this lowering. Live helper results, wider copies, strings and user-read operations retain their actual helper. Existing native ABI/relocation kinds, kernel/model and benchmark definitions retain their captured bytes.

The pass runs at ScalarOptimizerLate so subsequent standard scalar cleanup can promote local destination slots. Opaque assembly retains the fault-defined native read through optimization. Actual source and outputs are captured in inputs.tar.gz; candidate.patch applies to the existing plugin source.

Plugin Make exit:0. Native compile successes:11/11. IR compile successes:11/11.

| Unit | Compile exit | Executable bytes | Static calls | Lowered scalar sites in IR |
| --- | ---: | ---: | ---: | ---: |
| bcc/capable | 0 | 736 | 16 | 0 |
| bcc/biosnoop | 0 | 1188 | 24 | 11 |
| bcc/vfsstat | 0 | 352 | 0 | 0 |
| bcc/opensnoop | 0 | 848 | 26 | 0 |
| bcc/syscount | 0 | 660 | 14 | 0 |
| bcc/tcpconnect | 0 | 1448 | 30 | 8 |
| bcc/tcplife | 0 | 900 | 18 | 15 |
| bcc/runqlat | 0 | 1400 | 27 | 12 |
| tracee/tracee | 0 | 1050608 | 14423 | 17935 |
| tracee/lsm_support/kprobe_check | 0 | 64 | 1 | 0 |
| tracee/lsm_support/lsm_check | 0 | 64 | 1 | 0 |

Generation-bound application replay follows the current complete catalog and paired Tracee terminal. These counts describe compiler-produced P; runtime acceptance, workload counters and hardware throughput retain their separate measurements.

The source patch uses zero-context unified form, applied with git apply --unidiff-zero candidate.patch. The raw archive retains the equivalent initial context patch and actual compiler commands. Current compilation results remain11native/11IR, with17981actual scalar-load sites. Complete application/model/safety outcomes follow the queued replay phase.
