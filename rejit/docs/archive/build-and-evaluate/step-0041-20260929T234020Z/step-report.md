# Step 0041 — KVM selftest smoke at `5aa795837`

Date: 2026-09-29 UTC (run 22:56:40Z → 23:06:13Z)

## Scope

Smoke-validate the full KVM x86 stack after a host-kernel change. The last
documented runtime status predates the current host kernel
`7.3.0-070300rc3-generic`; selftest is the cheapest full-stack check
(kinsn modules → native-proof micro → verifier negative smokes) before
resuming the `make micro` / `make corpus` line, so it ran first.

- Command: `make selftest` — default `PLATFORM=kvm ARCH=x86`, default
  `TEST_MODE=selftest` policy, zero extra env vars.
- HEAD: `5aa795837` (= `origin/master`).
- Host: kernel `7.3.0-070300rc3-generic`, virtme-ng 1.41
  (`/opt/virtme-ng/bin/vng`), dockerd 29.8.0, `/dev/kvm` writable.
- make PID 230578 (launched via `nohup make selftest > /tmp/selftest.log 2>&1 &`).
- Source state: the tree carries an uncommitted, supervisor-owned
  `bpfopt/llvm/src/llvm_mapinline.hpp` (+3 lines: `create_bpf_target_machine(Aggressive)`
  + `promote_register_allocas` in `run_llvm_roundtrip()`); the rebuilt x86
  runtime image was built from that dirty source. Paper-B speculative
  evidence stays blocked until this change is superseded by a clean-source
  image rebuild; ordinary provenance proceeded.

## Verification

All four selftest sections PASS (host make log, in-VM tail):

1. **kinsn modules** — `bpf_x86_alu: loading out-of-tree module taints kernel.`
2. **native_proof micro smoke** — 29/29 benchmarks completed
   (`[bench] (29/29)` line in log; `details/progress.json`
   `completed_benchmarks: 29 / 29, status: completed`). Anchor:
   `[bench] (1/29) simple` → `result 12345678` (= `expected_result`),
   `compile last 444787 ns | exec last 163 ns`.
3. **native_proof verifier rejection smoke** — `PASS unchecked_packet_read rejected rc=1`
   (verifier diagnostic `invalid access to packet, off=64 size=1`).
4. **BPF verifier negative smoke** — `PASS valid_xdp_pass`,
   `PASS invalid_opcode errno=22`, `PASS stack_oob_write errno=13`,
   `PASS uninitialized_register errno=13` (4/4).

VM powered down cleanly at the end: `kvm: exiting hardware virtualization`,
`reboot: Power down`. No make error markers (`***`, `Error N`, `FAILED`,
`fatal`) anywhere in the log.

Artifact validated: `tests/results/62ce5f12/native_proof_micro_20260929_230257_731320/`
(untracked token dir, `RUN_TOKEN` random hex):

- `metadata.json`: `status: completed`, `run_type: native_proof_micro`,
  `suite: micro_staged_codegen`, host `virtme-ng`.
- `details/progress.json`: `completed_benchmarks: 29 / 29`, `status: completed`.
- `details/result.json`: 29 benchmarks; `simple` → `expected_result: 12345678`,
  `expected_retval: 2`, `compile_ns: 444787`, `exec_ns: 163`,
  `exec_cycles: 5686`, `bpf_bytecode_bytes: 400`, `native_code_bytes: 207`.
- `details/code_compare/*.md`: 29 files.

## Evidence pointers

- `make-selftest.log` (this dir): 504-line copy of the retained host log —
  the in-VM tail containing every suite PASS line and the full VM console
  through power-down.
- `run-marker.txt` (this dir): RUN / STARTED_UTC / GIT_HEAD / HOST_KERNEL /
  VNG path / source-state note.
- `tests/results/62ce5f12/...` artifact tree (kept untracked, as with other
  `RUN_TOKEN` dirs; only pinned historical token dirs are tracked).

## Caveats

- The retained log is the in-VM tail only. The host-build prefix
  (kernel/docker/app builds, ~20.8k lines observed at 23:01Z) is no longer
  in the file; the tail (mtime 23:03Z) contains all suite PASS lines plus
  the full VM console. No host-build-stage evidence is preserved in this run.
- Top-level suite files (`selftest.log`, `native_proof_micro.json`) were not
  present in the host token dir at power-down; suite PASS rests on the host
  make log lines plus the driver run dir (metadata/progress/result).
- Pre-existing host-side `tests/results/aborted/x86-kvm_test/run-contract.json`
  (mtime 08:57) is stale and not from this run (random token used).
- One cosmetic interleaving in the tail: a stray `make: Leaving
  directory '/workspaces/repository'` line inside the `[bench] (10/29)`
  output block (console interleaving, no effect on results).

## Open

- `make micro BENCH="simple" SAMPLES=1 WARMUPS=0 INNER_REPEAT=10` sanity run
  (expect result `12345678`, `expected_retval: 2`).
- `BPFREJIT_CORPUS_APPS=katran make corpus` (default policy), then
  `BPFREJIT_CORPUS_APPS=bcc,set make corpus`; AWS arm64 within caps if the
  local KVM line saturates.
