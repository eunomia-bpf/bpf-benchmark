# Step 0042 — KVM micro sanity run (`simple`) at `5b4730556`

Date: 2026-09-30 UTC (run 00:12:40Z → 00:17:13Z, ~4.5 min; image cached from
step 0041)

## Scope

Sanity-verify the `make micro` KVM line with the minimal bench set after the
step 0041 selftest smoke. Command:
`make micro BENCH="simple" SAMPLES=1 WARMUPS=0 INNER_REPEAT=10`, default
`PLATFORM=kvm ARCH=x86`, zero extra env vars. HEAD `5b4730556`
(= `origin/master` after step 0041). make PID 302214.

## Verification

- Suite `status: completed`; `progress.json` `1/1` benchmark; VM powered down
  cleanly (`kvm: exiting hardware virtualization`, `reboot: Power down`); no
  make error markers in the log.
- Run dir `micro/results/x86_kvm_micro_20260930_001655_090124/`:
  `metadata.json` `status: completed`, `run_type: x86_kvm_micro`,
  `suite: micro_staged_codegen`, host `virtme-ng`.
- `simple` confirmed on all three runtimes (raw, `details/result.json`):

  | runtime  | result   | retval | compile_ns | exec_ns | bpf_bytes | native_bytes |
  |----------|----------|--------|------------|---------|-----------|--------------|
  | `native` | 12345678 | 2      | 52456      | 13      | 192       | 61           |
  | `kernel` | 12345678 | 2      | 387392     | 44      | 192       | 111 (`jited_prog_len: 111`) |
  | `llvmbpf`| 12345678 | 2      | 4471088    | 21      | 192       | 59           |

  All match `expected_result: 12345678`, `expected_retval: 2`.
- Anchor vs last tracked run
  `x86_kvm_micro_20260926_105108_035832` (native `exec_cycles: 1471`,
  `compile_ns: 396386`): raw counters only — no ratio or summary computed;
  the sanity check is the exact-result match, not a performance delta.
- Tracked-file pattern identical to the 09-26 run: `metadata.json`,
  `details/result.json`, `details/progress.json` (`.gitignore`
  `!micro/results/**/*.json`); `code_compare/` and `jit_dumps/` stay
  ignored.

## Evidence pointers

- `make-micro.log` (this dir): full 473-line retained host log (cached
  image → short build stage; all suite lines + VM console through
  power-down).
- `run-marker.txt` (this dir).
- `micro/results/x86_kvm_micro_20260930_001655_090124/` run dir.

## Caveats

- Host kernel `7.3.0-070300rc3-generic`; supervisor-owned uncommitted
  `llvm_mapinline.hpp` (+3) in tree; x86 image built from that dirty source
  (inherited from step 0041 build; image was cached, not rebuilt).
- Single sample, `WARMUPS=0`, `INNER_REPEAT=10` — a correctness/pipe
  sanity, not a measurement.

## Open

- `BPFREJIT_CORPUS_APPS=katran make corpus` (default policy).
- `BPFREJIT_CORPUS_APPS=bcc,set make corpus`; further benches; AWS arm64
  within caps if the local KVM line saturates.
