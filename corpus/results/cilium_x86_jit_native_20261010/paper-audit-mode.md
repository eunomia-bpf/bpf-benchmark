# Paper-era Cilium audit-mode reconstruction

## Conclusion

Yes, the strongest retained source and replay evidence indicates that the
native Cilium object used by the run behind the paper's 2.357974x result was
compiled without `POLICY_AUDIT_MODE`, while its JIT arm was started with
`--policy-audit-mode=true`. Consequently the native arm dropped policy-denied
packets that the JIT arm forwarded. The exact May native object was not
retained, so the compile flag is a source/build reconstruction rather than a
direct inspection of that binary.

## Evidence chain

1. The paper result is `x86_kvm_corpus_20260529_040554_604387`; its stats-off
   PPS medians are 1,639,482 JIT and 3,865,856 native, or 2.357974043x. Its
   metadata records three 180-second samples but not source/kernel/CPU pins.
2. The chronological implementation candidate is commit
   `9f3855f6fa1c43027cfe0788615b6efb247f2a4d`. At that commit,
   `runner/libs/app_runners/cilium.py` passes `--policy-audit-mode=true`, while
   `vendor/bpf/Makefile:CILIUM_MAX_BASE_OPTIONS` has no
   `-DPOLICY_AUDIT_MODE=1`. The current and candidate repositories both pin
   Cilium to `1b721c2964e7799cab3e18c38066905ea240fa34`.
3. The October historical-source replay in
   `../cilium_native_lab_rerun_20261009/` reproduces the behavior. JIT has zero
   reason-133 drops and receives about 30--31 million packets. Native has
   median 67,944,078 reason-133 (`DROP_POLICY`) events with stats on and
   72,140,463 with stats off, while receiver packets are only 1--2. Its
   stats-off generated-rate ratio is 2.300165x, numerically near 2.357974x but
   based on unequal forwarding work.
4. On the current code before the macro fix,
   `x86_kvm_corpus_20261010_045630_427464` sent 14,491,950 native packets,
   received zero, and recorded exactly 14,491,950 reason-133 drops. Disabling
   native map lowering in `x86_kvm_corpus_20261010_050926_485795` still sent
   and reason-133-dropped exactly 9,759,729 packets, ruling out map lowering as
   the cause.
5. Commit `c049e2232` adds `-DPOLICY_AUDIT_MODE=1` to the native build. The
   accepted post-fix gate `x86_kvm_corpus_20261010_052134_234335` sends
   1,979,182 native packets, receives 1,979,202 including control traffic,
   records 1,979,200 allows in each direction, and records zero reason-133
   drops.

The original May result did not retain verdict maps, receiver counters, the
native object identity, or attachment snapshots, so the old run alone cannot
prove delivery. The source mismatch, replay, pre-fix A/B tests, and post-fix
gate together provide convergent evidence. The paper's 2.358x number must not
be presented as equivalent-forwarding native performance.
