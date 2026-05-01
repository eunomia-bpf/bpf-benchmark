# P89-V6Errors Fix Report

Date: 2026-05-01

Input run: `corpus/results/x86_kvm_corpus_20260501_013756_066216/`

## Artifact availability

The result JSON records failure workdirs under `bpfrejit-failures/<prog_id>`, but this checkout only contains:

- `corpus/results/x86_kvm_corpus_20260501_013756_066216/details/result.json`
- `corpus/results/x86_kvm_corpus_20260501_013756_066216/details/result.md`

`details/failures/<prog_id>/` is absent for all five requested program IDs, and `bpfrejit-failures/` is not present in the workspace. Host-side replay with `prog.bin`, `opt.bin`, `map_fds.json`, and BTF side files was therefore not possible in this checkout. The analysis below is based on the embedded `result.json` errors.

## Fixes

1. `bpfverify` now retries `BPF_PROG_LOAD` dry-run when verifier logging returns `ENOSPC`, growing the verifier log buffer from 16 MiB up to 256 MiB.
2. `kernel-sys::prog_rejit` now retries fork `BPF_PROG_REJIT` on `ENOSPC` with larger verifier log buffers, and `bpfrejit` starts with a 16 MiB log buffer.
3. The daemon no longer passes optional `func_info.bin` / `line_info.bin` into the original verifier-state capture command. That replay only needs verifier states, so it now uses stable load context plus maps/attach metadata and avoids fragile live BTF line/function records.
4. `bpfget --full` now drops captured `func_info` unless its offsets exactly match the original bytecode subprogram starts, and drops `line_info` unless it covers every subprogram start required by the kernel verifier ABI.

## Program findings

| Prog | App | Root cause | Status |
|---:|---|---|---|
| 121 | otelcol-ebpf-profiler | `bpfverify --verifier-states-out` failed with `errno 28`; embedded log is a huge verifier trace truncated by the fixed log buffer, not a semantic verifier reject. | Fixed by dynamic `bpfverify` log retry. |
| 278 | tetragon/observer | Original verifier-state replay passed live `func_info` whose offsets did not match original bytecode subprogram layout: `func_info BTF section doesn't match subprog layout in BPF program`. | Fixed by omitting optional BTF records for verifier-state capture and tightening `bpfget` func_info normalization. |
| 571 | katran | Embedded log for `xdp_root` shows verifier execution through `processed 14 insns`, while the app aggregate also shows `missing bpf_line_info for func#1` on a neighboring katran program. This is the optional BTF side-info replay class, not an optimization reject. | Fixed by omitting optional BTF records for verifier-state capture and clearing incomplete line_info in `bpfget`. |
| 102 | calico/felix | `BPF_PROG_REJIT` returned `EINVAL` on a multi-subprogram callback program (`func#1 @34`, `bpf_for_each_map_elem#164`). The candidate reached ReJIT, so userspace final verification had already accepted it; the reject is in the fork ReJIT path. | Not fixed in userspace; keep as known-fail pending kernel-side ReJIT callback/subprogram investigation. No filtering added. |
| 616 | tracee/monitor | `BPF_PROG_REJIT` failed with `No space left on device (os error 28)` while emitting a very large verifier log. | Fixed by dynamic ReJIT log retry. |

The cilium `BPF stats missing` error was intentionally left unchanged as the expected fail-fast behavior.

## Verification

Commands run:

```bash
cd bpfopt && cargo check --workspace
cd bpfopt && cargo test --workspace --release
cd daemon && cargo build --release
cd daemon && cargo test --release
```

All four commands passed.

Not run:

- `vm-corpus` / KVM v7. The next corpus run should be launched separately.
- Host-side per-program replay, because the preserved failure workdirs are not present in this checkout.
