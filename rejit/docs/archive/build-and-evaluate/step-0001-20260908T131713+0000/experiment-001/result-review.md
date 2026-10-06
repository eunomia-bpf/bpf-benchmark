# Experiment Review: C3 cross-architecture falsifiability

## Decision

The planned AArch64 functional experiment is positive for the implemented
29-program subset. The final public-Make run exited zero, all 29 generated
proof artifacts were accepted and test-run with the configured result and
return value, and the stock target verifier rejected the shared unsafe proof
at its intended one-byte packet access at offset 64. This is cross-ISA
functional evidence, not a performance result, full-ISA proof, or ARM hardware
measurement.

## Runs and retained failures

1. The first full-path preflight reached image construction but the guest
   failed at PID 1 because `qemu-arm64-init` still changed directory to the old
   `/home/yunwei37/workspace/bpf-benchmark` path. No benchmark result was
   produced. The log is retained at
   `/workspaces/.agent-state/bpf-development/kprog-arm64-qemu-preflight-20260908-rerun11.log`.
2. After deriving the guest path from `BPFREJIT_IMAGE_WORKSPACE`, the public
   `PLATFORM=qemu ARCH=arm64 ... make micro` preflight exited zero. Its
   `simple` result was `12345678` with return value 2 and completed metadata at
   `micro/results/arm64_qemu_micro_19700101_000014_909678/metadata.json`.
3. The first full selftest accepted and test-ran all 29 positive artifacts,
   but the negative artifact was first rejected at an unrelated unsafe
   four-byte store at packet offset 1. That made the outcome contradictory to
   the planned exact negative oracle even though the then-broad test reported
   success. The raw metadata remains at
   `tests/results/08063080/native_proof_micro_19700101_000023_397290/metadata.json`.
4. The negative source was reduced to the single unchecked read and the test
   oracle was tightened to the exact diagnostic
   `invalid access to packet, off=64 size=1`. Rebuilding showed a three-native-
   instruction AArch64 function and a three-eBPF-instruction proof with the
   unique dangerous access at offset 64.
5. The final public invocation
   `PLATFORM=qemu ARCH=arm64 JOBS=16 TIMEOUT=1800 make selftest` exited zero.
   Its metadata is
   `tests/results/e4a8b96d/native_proof_micro_19700101_000021_547969/metadata.json`,
   and its complete console log is retained at
   `/workspaces/.agent-state/bpf-development/kprog-arm64-qemu-selftest-final-20260908.log`.

## Independent result checks

- Metadata status is `completed` and contains exactly 29 benchmarks.
- Every benchmark has one `native_proof` run and one sample; every sample's
  `result` and `retval` equal its checked-in expected values.
- The console records
  `invalid access to packet, off=64 size=1`, reports
  `PASS unchecked_packet_read rejected rc=1`, and ends with target power-down
  followed by a zero guest status.

## Interpretation and remaining uncertainty

This result extends the current-revision verifier/load/test-run smoke from
x86-64 to the independently generated AArch64 simulator artifacts. It also
shows that the corrected ABI-load provenance policy handles the XDP, TC, and
cgroup-skb cases exercised by the 29-program set on the target kernel.

The run uses full-system AArch64 QEMU on an x86 host (`cortex-a57` CPU model;
guest KVM HYP mode unavailable), so its timings are not ARM performance data.
It does not establish full ISA coverage, general simulator refinement,
semantic or cryptographic binding between an accepted proof and executed
native text, or the paper's complete O1--O4 safety argument. Those remain
separate implementation and evaluation tasks.

## Raw-provenance reconciliation

The final raw metadata is preserved unchanged, including three inaccurate or
missing fields: it labels the environment `bare-metal`, records guest times in
1970, and reports both repository and kernel commits as `unknown`. These fields
must not be used to identify the execution environment or source revision.

The retained public-Make console log and the raw `host.kernel_cmdline` instead
identify the execution path: the command used `PLATFORM=qemu ARCH=arm64`, the
guest booted with `console=ttyAMA0`, `rootfstype=9p`, and `init=/qemu-init`, and
the log reports unavailable KVM HYP mode on the x86 host. The guest's
`7.0.0-rc2+` kernel version is recorded, but its exact source commit is not.
The 1970 timestamps came from the uninitialized guest clock and establish only
within-guest ordering; the enclosing log filename and operator record date the
run to September 8, 2026. The application source content is contained in root
revision `e0b7d35e0ecb1127105410b2b5b637f65f9d8d1f`, committed after the run,
but the raw artifact itself does not bind that revision. This reconstruction
closes the misleading environment label for interpretation; it does not
manufacture provenance absent from the raw result.
