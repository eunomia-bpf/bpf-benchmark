# x86 application continuation, November8 UTC

The table records the latest closed complete-application attempts. Baseline resident counts and each observed terminal service request retain distinct domains. The whole upstream application starts unchanged, and failure rows identify the exact point reached. BCC and Katran complete the generation-bound arm and have paired R timing; the four application frontiers continue below.

| Application | Baseline census | Generated | Compiled | Bound | Submission/specialization/loader errors | Verifier rejections | Raw evidence |
| --- | ---: | ---: | ---: | ---: | --- | --- | --- |
| BCC | 25 | 25 | 25 | 25 | 0 | 0 | [complete runtime](../kprog_app_coverage_20261107/native-only-runtime/standard-bcc-8g.json) |
| OTel | 13 resident | 2 | 2 | 1 | 0 | 1: private-stack alignment | [000433](../kprog_app_coverage_20261107/otel-stack-identity/README.md) |
| Cilium | 72 resident | 2 | 2 | 1 | 1: proof kfunc relocation | 0 | [001201](cilium-bmi2/README.md) |
| Tetragon | 287 resident | 5 | 5 | 4 | 0 | 1: 8193-jump complexity | [234541](../kprog_app_coverage_20261107/tetragon-stack-width/README.md) |
| Katran | 1 | 1 | 1 | 1 | 0 | 0 | [complete runtime](../kprog_app_coverage_20261107/katran-tagged-storage/README.md) |
| Tracee | 151 resident | 6 | 6 | 5 | 0 | 1: helper length range | [235054](../kprog_app_coverage_20261107/tracee-narrow-identity/README.md) |

Current serial trials: aligned-stack OTel then Tracee, each12GiB/eightvCPU/20-23. A Cilium successor consumes generic vmlinux kfunc relocation after these trials. Every completed batch retains commands, all native/proof input hashes and raw work/error logs. Generic ISA/token/link laws supply safety; historical individual-program proof material retains its frozen state.
