# P89 ReJIT Error Analysis

Date: 2026-05-01

Input run: `corpus/results/x86_kvm_corpus_20260501_010056_295756/details/result.json`

## Failure Distribution

The 14 non-ok apps split as follows:

| Class | Apps | Count |
|---|---:|---:|
| `line_info` points at `code == 0` slots (`Invalid insn code at line_info[...]`) | `bcc/execsnoop`, `bcc/bindsnoop`, `bcc/biosnoop`, `bcc/syscount`, `bcc/tcpconnect`, `bcc/tcplife`, `bcc/runqlat`, `calico/felix`, `otelcol-ebpf-profiler/profiling`, `tetragon/observer`, `katran`, `tracee/monitor` | 12 |
| `line_info` offset/order/out-of-range (`Invalid line_info[...]`) | `bcc/vfsstat` | 1 |
| BPF stats baseline missing requested IDs | `cilium/agent` | 1 |

The ReJIT failures happen before `bpfopt optimize` and before `bpfrejit`: daemon captures verifier states for `const_prop` by running `bpfverify --verifier-states-out` on the original `prog.bin`, and the kernel rejects the replayed BTF `line_info` before processing any instruction.

## Root Cause

`bpfget --full` writes `prog.bin` from the fork-only original bytecode path (`kernel_sys::prog_get_original`) but writes `func_info.bin`/`line_info.bin` from live `BPF_OBJ_GET_INFO_BY_FD` metadata. Those live BTF records are not always valid for the recovered original bytecode:

- `bcc/execsnoop` prog 9 saved in `x86_kvm_corpus_20260430_193236_794969/details/workdirs/9` has 516 original instructions and 251 line records.
- 22 of those line records target either `ldimm64` second slots (`code == 0`) or the end sentinel.
- The reported sample `line_info[35].insn_off` is offset 95; `prog.bin[95].code == 0`, exactly matching the kernel's `Invalid insn code at line_info[35].insn_off`.
- Across the 510 saved debug workdirs from that run, 314 had invalid replay line_info records. 82 also had func_info layouts that were not valid against `prog_get_original()` bytecode.

The culprit is the `bpfget --full` metadata/bytecode contract introduced by the v3 BTF metadata plumbing around `6621d896` and retained through `c61f0559`. `c61f0559..HEAD` did not change `bpfget`; the bad artifacts already exist in pre-PrefetchV2 saved workdirs. `f9429b0c` (PostAuditFix) did remove retry-without-log, but these are malformed BTF metadata rejections, not ENOSPC log-buffer successes; retrying without a log buffer would not make invalid line_info loadable. `9b9bd28e` (PrefetchV2) is also not causal because failure occurs during original verifier-state capture before any pass pipeline runs.

The `failed to preserve failure workdir ... verifier.log is missing` wrapper is a secondary daemon reporting bug: the original verifier-state capture wrote `original_bpfverify_report.json` but did not alias the report's verifier log to `verifier.log`, so workdir preservation could mask the clearer verifier failure.

## Host-Side Reproduction

Representative saved program:

`corpus/results/x86_kvm_corpus_20260430_193236_794969/details/workdirs/9`

Host inspection showed:

- `line_info` records: `251 -> 229` after dropping invalid targets.
- Remaining bad line_info targets: `0`.
- `sudo -n bpfverify` with host BTF id 1 and dummy maps passes the original execsnoop bytecode when guest BTF line_info is not replayed: report status `pass`, 516 instructions, 295 verifier states.

Full guest line_info cannot be faithfully replayed on the host with host BTF because the saved line records contain guest BTF string offsets. The host-side proof used the saved bytecode plus structural validation of the exact bad offsets; KVM v6 is still the authoritative end-to-end validation.
