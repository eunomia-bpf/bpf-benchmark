# Audit of the kprog numbers in the LPC 2026 talk

Read-only analysis, 2026-10-11. No new measurement. The deck is
`yunwei37-blog/presentation/lpc2026-kinsn/slides.md` (talk given 2026-10-05).

## Verdicts

| Number in the deck | Verdict | Corrected number, or what is missing |
| --- | --- | --- |
| Cilium native 1.38x throughput | invalid: mismatched native build configuration, different datapath | 1.194x (IQR 1.185-1.206), `../cilium_x86_config_parity_counterbalanced_20261010/` |
| Cilium 0.61 -> 0.84 of no-eBPF throughput | invalid: same native arm | none; the October rerun has no no-eBPF arm |
| Cilium 443 -> 134 ns/run | invalid: same bug, and one versus three program runs per packet | 659.2 -> 463.9 ns/run (stats on, one root run per packet) |
| OTel 1.83x, 3,225 -> 212 ns/run | invalid as a same-work result (strong indirect evidence) | needs a rerun that counts delivered samples |
| Tetragon 701 -> 304 ns, 0.23 -> 0.29 | cannot tell; suspicious (flat native cost per entry) | event counts |
| Katran 177 -> 145 ns, 0.38 -> 0.43 | cannot tell; plausible | XDP action and receiver counts |
| BCC, Tracee | consistent (runs per workload unit match, flat ns/run) | - |
| "apps up to 1.83x" | invalid | best checked same-work result: Cilium 1.19x |
| micro 1.47x | valid (29 pure-bytecode programs, 0 result mismatches) | - |
| EC2 1.71x / 2.05x | valid; microbenchmarks (JIT vs user-space native), unrelated to kprog apps | - |

## Sources of the deck's numbers

The October audits checked the 2026-05-29 runs (2.358x). The deck used the
earlier 2026-05-26/27 x86 KVM corpus, written up in
`kprog/docs/archive/eval_native_20260527.md`:

- stats on (ns/run): BCC `x86_kvm_corpus_20260526_211758_813406`, OTel
  `20260526_214808_410996`, Cilium `20260526_230251_020975`, Tetragon
  `20260527_002557_893190`, Katran `20260527_005602_704153`, Tracee
  `20260527_012602_194852`;
- stats off (throughput): six apps `20260527_015711_134639`; no eBPF
  `20260527_043130_139245`.

These raw directories exist only in the old lab clone `~/workspace/bpf-benchmark`.
The plotting script of `kprog-corpus-eval.png` was never committed; the same
method is in `docs/tmp/native_eval_20260529.py`. Recomputed from the raw JSON:
Cilium 443.5 -> 133.5 ns, 0.615 -> 0.845 of no-eBPF (1.374x); OTel 3224.9 ->
212.1 ns, 0.395 -> 0.726 (1.84x). Micro 1.47x is
`docs/figures/micro-characterization-runtime-aggregate-20260527.png` from
`micro/results/x86_kvm_micro_20260526_210952_650695` (1.4742x).

## Cilium

The run's commit was not recorded; the last commit before it, dcebb471f, has
the same `vendor/bpf/Makefile` and `native_compat.h` as 9f3855f6fa1c, the
2026-05-29 recipe replayed in October. The JIT arm's daemon runs with
`--policy-audit-mode=true` (since f04689b46); the native build's
`CILIUM_MAX_LXC_OPTIONS` has no `POLICY_AUDIT_MODE` and hardcodes host
firewall, monitor aggregation 3, DSR, NodePort acceleration, host routing and
`ENCAP_IFINDEX=1`. Audit mode reached the native build only in c049e2232
(2026-10-09). No attachment, verdict, drop or receiver counter was kept, but
the BPF counters show different work: under JIT only `cil_from_container` runs
once per packet (864,363,220 runs for 864,362,078 packets), while under native
`cil_from_host` and `cil_to_host` also run once per packet (955,993,859 each).
Per packet, total BPF time is 443.5 -> 400.6 ns, not 443 -> 134.

## OTel

No hardcoded configuration, but the native loader binds the profiler's
load-time `.rodata.var` values by section offset and silently skips the
binding when no map matches; the bound values were not kept. The profiler's
user space creates one `exe_id_to_N_stack_deltas` inner map per process the
BPF side reports. JIT arms: 105 before measurement and 5 per sample; native
arms: 0 before measurement, 19 (stats on) or 7 (stats off) in sample 1, 0
afterwards. The native profiler therefore set up unwinding for almost none of
the workload's processes, so most samples most likely took the unknown-PID
early exit (inferred from this proxy, not observed). On arm64 (2026-06-14),
where both arms create hundreds of these maps, native is 2518.9 vs 2555.6 ns
and 0.989x throughput.
