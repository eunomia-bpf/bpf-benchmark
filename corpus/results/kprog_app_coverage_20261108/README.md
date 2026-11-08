# x86 application continuation, November8 UTC

The table records the latest closed complete-application attempts. Baseline resident counts and each observed terminal service request retain distinct domains. The whole upstream application starts unchanged, and failure rows identify the exact point reached. BCC and Katran complete the generation-bound arm and have paired R timing; the four application frontiers continue below.

| Application | Baseline census | Generated | Compiled | Bound | Submission/specialization/loader errors | Verifier rejections | Raw evidence |
| --- | ---: | ---: | ---: | ---: | --- | --- | --- |
| BCC | 25 | 25 | 25 | 25 | 0 | 0 | [complete runtime](../kprog_app_coverage_20261107/native-only-runtime/standard-bcc-8g.json) |
| OTel | 13 resident | 3 | 3 | 2 | 0 | 1: proof stack depth | [012120](otel-fixed-stack/README.md) |
| Cilium | 72 resident | 2 | 2 | 1 | 0 | 1: native relocation binding for pruned map helper | [021801](cilium-matched-runtime/README.md) |
| Tetragon | 287 resident | 4 | 4 | 3 | 0 | 1: event_execve proof stack depth | [014223](tetragon-fixed-stack-retry/README.md) |
| Katran | 1 | 1 | 1 | 1 | 0 | 0 | [complete runtime](../kprog_app_coverage_20261107/katran-tagged-storage/README.md) |
| Tracee | 151 resident | 6 | 6 | 5 | 0 | 1: helper length range | [013224](tracee-fixed-stack/README.md) |

Current whole-application frontiers are OTel proof-stack depth, Tracee helper length, Tetragon stack/jump complexity and Cilium pruned-helper resource identity. The generic typed private-stack representation completes byte/JIT/host checks and full-source compiles; whole-application successors consume the merged MOV_LOAD fidelity correction. Complete matching kernel modules and the38-case native-only safety suite retain separate receipts.

The [OTel aligned private-stack batch001743](otel-stack-aligned/README.md) freshly binds read_task_struct and perf_unwind_stop and continues from perf_unwind_native instruction exploration,1000001instructions/66042states. The [generic proof kfunc loader](proof-kfunc/README.md) passes20BTF/site/prototype controls and the exact original CiliumELF/matching kernelBTF call. Its whole-application successor follows Tracee serially.

The [Tracee aligned-stack batch002731](tracee-stack-aligned/README.md) retains6fresh generation/compilation and5bound loads, reaching sys_exit_submit helper-size range checking after3458instructions/151states. Allterminal native hashes and source pins reconcile. The whole Cilium kfunc successor is running; generic typed-read OTel/Tetragon/Tracee successors follow it serially.

The [generic narrow register-read representation](typed-read-identity/README.md) passes10width/lane forms and655360BPF-JIT/host/byte observations. Its32-bit read emits a verifier-visible MOV32, and8/16-bit reads emit exact masks. The whole-OTel source compile and serial OTel/Tetragon/Tracee runtime trials retain their separate completion records.

The [Cilium kfunc batch003807](cilium-kfunc/README.md) freshly generates/compiles2requests and binds1, then reaches libbpf-normalized extern linkage at the next TC proof. The common loader successor reads original declarations from the same ELF snapshot and retains the kernel prototype matcher.

The [whole OTel typed-read batch004333](otel-typed-read/README.md) preserves3fresh generation/compilation and2bound loads and reaches1000001verifier instructions/65666states. The complete fixed-input result continues from control/state exploration. Whole Tetragon is now active, followed by Tracee and then the Cilium original-BTF successor.

The [whole Tetragon typed-read batch005356](tetragon-typed-read/README.md) freshly generates/compiles5requests and binds4; execve_send reaches8193jumps/179285instructions/1930states. All5terminal native hashes and source pins reconcile. Tracee follows in the same serial source epoch.

The [whole Tracee typed-read batch005903](tracee-typed-read/README.md) freshly generates/compiles6requests and binds5; sys_exit_submit reaches helper length checking at3502instructions/151states. All6terminal native hashes and source pins reconcile. Whole Cilium now consumes the captured paired kfunc transport build; generic fixed-RSP-offset successors follow it serially.

The [whole Cilium original-BTF batch010928](cilium-original-btf/README.md) freshly generates/compiles2requests and binds1. The TC request now passes loader/BTF/transport checks and reaches kernel native-region call identity before0processedinstructions. Both terminal native hashes/source pins reconcile; canonical-vmlinux guard validation and a private kernel/module build follow.

The [explicit-RSP displacement component](stack-fixed-offsets/README.md) passes45forms/184320BPF-JIT, UBSan host and independent byte observations. Complete original Tetragon and OTel sources compile to1355and10439BPF instructions, respectively; prior typed-read epochs retain4826and40034. These are completed mechanism/compiler measurements. Whole-application verifier, behavior and timing results follow their actual terminal batches.

Recorded verifier frontiers retain their separate native entries and candidate epochs:

| Application / entry | Recorded frontier | Complete batch |
| --- | --- | --- |
| OTel / perf_unwind_native | R10-520 proof-stack write | [012120](otel-fixed-stack/README.md) |
| Tetragon / event_execve | R10-888 proof-stack write | [014223](tetragon-fixed-stack-retry/README.md) |
| Tetragon / execve_send |8193-jump sequence | [005356](tetragon-typed-read/README.md) |
| Tracee / sys_exit_submit | probe_read length range | [013224](tracee-fixed-stack/README.md) |
| Cilium / tail_handle_ipv4_from_host | kernel native-region kfunc identity | [010928](cilium-original-btf/README.md) |

Each row remains verification work until its complete application cohort passes. The new registered-kfunc kernel has separate safety/runtime and environment receipts.

The [Cilium matched-module batch021801](cilium-matched-runtime/README.md) reaches native relocation binding after809symbolic instructions. The [registered-kfunc38-case safety suite](kfunc-native-only-safety/README.md) executes9positive controls and rejects29unsafe submissions. Both retain exact kernel/service/native identities and independent outcome domains.
